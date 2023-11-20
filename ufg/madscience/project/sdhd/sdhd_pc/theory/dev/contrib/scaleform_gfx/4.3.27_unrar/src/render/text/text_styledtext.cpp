// File Line: 28
// RVA: 0x958410
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::Allocator::AllocateParagraph(Scaleform::Render::Text::Allocator *this)
{
  Scaleform::Render::Text::Allocator *v1; // rbx
  Scaleform::Render::Text::Paragraph *result; // rax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v3; // ST28_8
  unsigned int v4; // edx

  v1 = this;
  result = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                                   this->pHeap,
                                                   72i64);
  if ( !result )
    return 0i64;
  result->Text.pText = 0i64;
  result->Text.Size = 0i64;
  result->Text.Allocated = 0i64;
  result->pFormat.pObject = 0i64;
  v3 = &result->FormatInfo;
  v3->Ranges.Data.Data = 0i64;
  v3->Ranges.Data.Size = 0i64;
  v3->Ranges.Data.Policy.Capacity = 0i64;
  result->StartIndex = 0i64;
  result->ModCounter = 0;
  v4 = v1->NewParagraphId;
  v1->NewParagraphId = v4 + 1;
  result->UniqueId = v4;
  return result;
}

// File Line: 111
// RVA: 0x969240
wchar_t *__fastcall Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(Scaleform::Render::Text::Paragraph::TextBuffer *this, Scaleform::Render::Text::Allocator *pallocator, unsigned __int64 pos, unsigned __int64 length)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r9
  Scaleform::Render::Text::Paragraph::TextBuffer *v8; // rbx
  wchar_t *v9; // rax
  unsigned __int64 v10; // r8
  wchar_t *v11; // rax

  v4 = pos;
  v5 = this->Size;
  v6 = length;
  v7 = v5 + length;
  v8 = this;
  if ( this->Allocated < v7 )
  {
    if ( this->pText )
      v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                        Scaleform::Memory::pGlobalHeap,
                        this->pText,
                        2 * v7);
    else
      v9 = (wchar_t *)pallocator->pHeap->vfptr->Alloc(pallocator->pHeap, 2 * v7, 0i64);
    v5 = v8->Size;
    v8->pText = v9;
    v8->Allocated = v5 + v6;
  }
  v10 = v5 - v4;
  if ( v10 )
    memmove(&v8->pText[v4 + v6], &v8->pText[v4], 2 * v10);
  v11 = v8->pText;
  v8->Size += v6;
  return &v11[v4];
}

// File Line: 228
// RVA: 0x9404D0
void __fastcall Scaleform::Render::Text::Paragraph::Paragraph(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Paragraph *o, Scaleform::Render::Text::Allocator *ptextAllocator)
{
  Scaleform::Render::Text::Allocator *v3; // r13
  Scaleform::Render::Text::Paragraph *v4; // rbx
  Scaleform::Render::Text::Paragraph *v5; // r12
  wchar_t *v6; // rax
  unsigned __int64 v7; // r8
  signed __int64 v8; // rsi
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v9; // r15
  unsigned int v10; // ecx
  Scaleform::Render::Text::ParagraphFormat *v11; // rbx
  Scaleform::Render::Text::ParagraphFormat *v12; // rcx
  __int64 v13; // r14
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v14; // rbp
  Scaleform::Render::Text::TextFormat *v15; // rax
  Scaleform::Render::Text::TextFormat *v16; // rbx
  Scaleform::Render::Text::TextFormat *v17; // rdi
  bool v18; // zf

  v3 = ptextAllocator;
  v4 = o;
  v5 = this;
  v6 = (wchar_t *)ptextAllocator->pHeap->vfptr->Alloc(ptextAllocator->pHeap, 2 * o->Text.Size, 0i64);
  v5->Text.pText = v6;
  v7 = v4->Text.Size;
  v5->Text.Size = v7;
  v5->Text.Allocated = v7;
  memmove(v6, v4->Text.pText, 2 * v4->Text.Size);
  v8 = 0i64;
  v5->pFormat.pObject = 0i64;
  v9 = &v5->FormatInfo;
  Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>(
    &v5->FormatInfo.Ranges.Data,
    &v4->FormatInfo.Ranges.Data);
  v5->StartIndex = v4->StartIndex;
  v5->ModCounter = 0;
  v10 = v3->NewParagraphId;
  v3->NewParagraphId = v10 + 1;
  v5->UniqueId = v10;
  v11 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v3, v4->pFormat.pObject);
  v12 = v5->pFormat.pObject;
  if ( v12 )
    Scaleform::Render::Text::ParagraphFormat::Release(v12);
  v5->pFormat.pObject = v11;
  v13 = 0i64;
  while ( v8 >= 0 && v8 < v5->FormatInfo.Ranges.Data.Size )
  {
    v14 = v9->Ranges.Data.Data;
    v15 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v3, v9->Ranges.Data.Data[v13].Data.pObject);
    v16 = v15;
    if ( v15 )
      ++v15->RefCount;
    v17 = v14[v13].Data.pObject;
    if ( v17 )
    {
      v18 = v17->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v17);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17);
      }
    }
    v14[v13].Data.pObject = v16;
    if ( v16 )
    {
      v18 = v16->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    if ( v8 < (signed __int64)v5->FormatInfo.Ranges.Data.Size )
    {
      ++v8;
      ++v13;
    }
  }
}

// File Line: 276
// RVA: 0x9B43F0
void __fastcall Scaleform::Render::Text::Paragraph::SetTextFormat(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::TextFormat *fmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::Text::TextFormat *v5; // rsi
  Scaleform::Render::Text::Allocator *v6; // r13
  Scaleform::Render::Text::Paragraph *v7; // rbx
  unsigned __int64 v8; // r12
  unsigned __int64 v9; // r11
  signed __int64 v10; // r12
  unsigned __int64 v11; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v12; // r10
  wchar_t *v13; // rax
  Scaleform::Render::Text::TextFormat *v14; // rdi
  unsigned __int64 v15; // rcx
  Scaleform::Render::Text::TextFormat *v16; // rbx
  bool v17; // zf
  Scaleform::Render::Text::TextFormat *v18; // rbx
  __int64 v19; // r14
  unsigned __int64 v20; // r15
  __int64 v21; // rdi
  Scaleform::MemoryHeap *v22; // rdx
  Scaleform::MemoryHeap *v23; // rax
  Scaleform::MemoryHeap *v24; // rax
  Scaleform::Render::Text::TextFormat *v25; // rax
  Scaleform::Render::Text::FontHandle *v26; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v27; // rcx
  Scaleform::Render::Text::TextFormat *v28; // rdx
  Scaleform::Render::Text::TextFormat *v29; // rax
  Scaleform::Render::Text::TextFormat *v30; // rbx
  unsigned __int64 v31; // rsi
  __int64 v32; // r9
  Scaleform::Render::Text::TextFormat *v33; // rdi
  unsigned __int64 v34; // rdx
  unsigned __int64 v35; // r8
  __int64 v36; // r14
  Scaleform::Render::Text::TextFormat *v37; // rdi
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v38; // r11
  unsigned __int64 v39; // r10
  wchar_t *v40; // rcx
  Scaleform::Render::Text::TextFormat *v41; // rsi
  unsigned __int64 v42; // rdx
  Scaleform::Render::Text::FontHandle *v43; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v44; // rcx
  unsigned __int64 v45; // rdx
  unsigned __int64 v46; // rdx
  Scaleform::Render::Text::TextFormat *v47; // rbx
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+20h] [rbp-E0h]
  Scaleform::StringDH *v49; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Text::TextFormat v50; // [rsp+80h] [rbp-80h]
  Scaleform::Render::Text::TextFormat *key; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Text::TextFormat *v52; // [rsp+D8h] [rbp-28h]
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+E0h] [rbp-20h]
  __int64 v54; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::Text::TextFormat v55; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Text::Paragraph *v56; // [rsp+190h] [rbp+90h]
  Scaleform::Render::Text::TextFormat *v57; // [rsp+1A0h] [rbp+A0h]
  unsigned __int64 v58; // [rsp+1A8h] [rbp+A8h]

  v58 = startPos;
  v57 = fmt;
  v56 = this;
  v54 = -2i64;
  v5 = fmt;
  v6 = pallocator;
  v7 = this;
  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &result, startPos);
  v8 = endPos;
  v9 = v58;
  if ( endPos < v58 )
    v8 = v58;
  if ( v8 == -1i64 )
  {
    v10 = 0x7FFFFFFFFFFFFFFFi64;
    goto LABEL_6;
  }
  v10 = v8 - v58;
  if ( v10 > 0 )
  {
    while ( 1 )
    {
LABEL_6:
      v11 = result.pText->Size;
      if ( result.CurTextIndex >= v11 )
      {
LABEL_95:
        v7 = v56;
        break;
      }
      if ( result.FormatIterator.Index < 0
        || result.FormatIterator.Index >= result.FormatIterator.pArray->Ranges.Data.Size )
      {
        v13 = result.pText->pText;
      }
      else
      {
        v12 = result.FormatIterator.pArray->Ranges.Data.Data;
        v11 = result.FormatIterator.pArray->Ranges.Data.Data[result.FormatIterator.Index].Index;
        v13 = result.pText->pText;
        if ( result.CurTextIndex >= v11 )
        {
          v14 = v12[result.FormatIterator.Index].Data.pObject;
          v15 = v12[result.FormatIterator.Index].Length;
          result.PlaceHolder.pText = &v13[v11];
          result.PlaceHolder.Index = v11;
          result.PlaceHolder.Length = v15;
          if ( v14 )
            ++v14->RefCount;
          v16 = result.PlaceHolder.pFormat.pObject;
          if ( result.PlaceHolder.pFormat.pObject )
          {
            v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v16);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
              v9 = v58;
            }
          }
          result.PlaceHolder.pFormat.pObject = v14;
          goto LABEL_21;
        }
      }
      v18 = result.PlaceHolder.pFormat.pObject;
      result.PlaceHolder.Length = v11 - result.CurTextIndex;
      result.PlaceHolder.Index = result.CurTextIndex;
      result.PlaceHolder.pText = &v13[result.CurTextIndex];
      if ( result.PlaceHolder.pFormat.pObject )
      {
        v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v18);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
          v9 = v58;
        }
      }
      result.PlaceHolder.pFormat.pObject = 0i64;
LABEL_21:
      v19 = result.PlaceHolder.Index;
      v20 = result.PlaceHolder.Length;
      v21 = result.PlaceHolder.Index;
      if ( v9 > result.PlaceHolder.Index )
        v21 = v9;
      v22 = v6->pHeap;
      v50.pAllocator = 0i64;
      v50.RefCount = 1;
      v23 = Scaleform::Memory::pGlobalHeap;
      if ( v22 )
        v23 = v22;
      v49 = &v50.FontList;
      v50.FontList.pHeap = v23;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      v50.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
      v24 = Scaleform::Memory::pGlobalHeap;
      if ( v22 )
        v24 = v22;
      v49 = &v50.Url;
      v50.Url.pHeap = v24;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      v50.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
      v50.pImageDesc.pObject = 0i64;
      v50.pFontHandle.pObject = 0i64;
      v50.ColorV = -16777216;
      v50.LetterSpacing = 0.0;
      v50.FontSize = 0;
      v50.FormatFlags = 0;
      v50.PresentMask = 0;
      if ( result.PlaceHolder.pFormat.pObject )
      {
        v25 = Scaleform::Render::Text::TextFormat::Merge(result.PlaceHolder.pFormat.pObject, &v55, v5);
        Scaleform::Render::Text::TextFormat::operator=(&v50, v25);
        if ( v55.pAllocator )
        {
          key = &v55;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v55.pAllocator->TextFormatStorage.pTable,
            &key);
        }
        v26 = v55.pFontHandle.pObject;
        if ( v55.pFontHandle.pObject && !_InterlockedDecrement(&v55.pFontHandle.pObject->RefCount) && v26 )
          v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
        v27 = v55.pImageDesc.pObject;
        if ( v55.pImageDesc.pObject )
        {
          --v55.pImageDesc.pObject->RefCount;
          if ( !v27->RefCount )
            v27->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v27->vfptr, 1u);
        }
        v49 = &v55.Url;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v49 = &v55.FontList;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v28 = &v50;
      }
      else
      {
        v28 = v5;
      }
      v29 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v6, v28);
      v30 = v29;
      v31 = v10;
      if ( v19 + v20 - v21 < v10 )
        v31 = v19 + v20 - v21;
      range.Index = v21;
      range.Length = v31;
      if ( v29 )
        ++v29->RefCount;
      range.Data.pObject = v29;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
        &v56->FormatInfo,
        &range);
      v33 = range.Data.pObject;
      if ( range.Data.pObject )
      {
        v17 = range.Data.pObject->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v33);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
        }
      }
      v10 -= v31;
      v34 = result.pText->Size;
      v35 = result.CurTextIndex;
      if ( result.CurTextIndex < v34 )
      {
        v36 = v20 + v19;
        v32 = result.FormatIterator.Index;
        v37 = result.PlaceHolder.pFormat.pObject;
        while ( 1 )
        {
          if ( v32 < 0 || v32 >= result.FormatIterator.pArray->Ranges.Data.Size )
          {
            v40 = result.pText->pText;
            result.PlaceHolder.Length = v34 - v35;
          }
          else
          {
            v38 = result.FormatIterator.pArray->Ranges.Data.Data;
            v39 = result.FormatIterator.pArray->Ranges.Data.Data[v32].Index;
            v40 = result.pText->pText;
            if ( v35 >= v39 )
            {
              v41 = v38[v32].Data.pObject;
              v42 = v38[v32].Length;
              result.PlaceHolder.pText = &v40[v39];
              result.PlaceHolder.Index = v39;
              result.PlaceHolder.Length = v42;
              if ( v41 )
              {
                ++v41->RefCount;
                v35 = result.CurTextIndex;
                v32 = result.FormatIterator.Index;
                v37 = result.PlaceHolder.pFormat.pObject;
              }
              if ( v37 )
              {
                v17 = v37->RefCount-- == 1;
                if ( v17 )
                {
                  Scaleform::Render::Text::TextFormat::~TextFormat(v37);
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v37);
                }
                v32 = result.FormatIterator.Index;
                v35 = result.CurTextIndex;
              }
              v37 = v41;
              result.PlaceHolder.pFormat.pObject = v41;
              goto LABEL_69;
            }
            result.PlaceHolder.Length = v39 - v35;
          }
          result.PlaceHolder.Index = v35;
          result.PlaceHolder.pText = &v40[v35];
          if ( v37 )
          {
            v17 = v37->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v37);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v37);
            }
            v32 = result.FormatIterator.Index;
            v35 = result.CurTextIndex;
          }
          result.PlaceHolder.pFormat.pObject = 0i64;
          v37 = 0i64;
LABEL_69:
          if ( result.PlaceHolder.Index < v36 )
          {
            if ( v32 < 0 || v32 >= result.FormatIterator.pArray->Ranges.Data.Size )
            {
              v35 = result.pText->Size;
              result.CurTextIndex = result.pText->Size;
            }
            else if ( v35 >= result.FormatIterator.pArray->Ranges.Data.Data[v32].Index )
            {
              v35 += result.FormatIterator.pArray->Ranges.Data.Data[v32].Length;
              result.CurTextIndex = v35;
              if ( v32 < (signed __int64)result.FormatIterator.pArray->Ranges.Data.Size )
                result.FormatIterator.Index = ++v32;
            }
            else
            {
              v35 = result.FormatIterator.pArray->Ranges.Data.Data[v32].Index;
              result.CurTextIndex = result.FormatIterator.pArray->Ranges.Data.Data[v32].Index;
            }
            v34 = result.pText->Size;
            if ( v35 < v34 )
              continue;
          }
          break;
        }
      }
      if ( v30 )
      {
        v17 = v30->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v30);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v30);
        }
      }
      if ( v50.pAllocator )
      {
        v52 = &v50;
        Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
          (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v50.pAllocator->TextFormatStorage.pTable,
          &v52);
      }
      v43 = v50.pFontHandle.pObject;
      if ( v50.pFontHandle.pObject && !_InterlockedDecrement(&v50.pFontHandle.pObject->RefCount) && v43 )
        ((void (__fastcall *)(Scaleform::Render::Text::FontHandle *, signed __int64, unsigned __int64, __int64, const wchar_t *))v43->vfptr->__vecDelDtor)(
          v43,
          1i64,
          v35,
          v32,
          result.PlaceHolder.pText);
      v44 = v50.pImageDesc.pObject;
      if ( v50.pImageDesc.pObject )
      {
        --v50.pImageDesc.pObject->RefCount;
        if ( !v44->RefCount )
          ((void (__fastcall *)(Scaleform::Render::Text::HTMLImageTagDesc *, signed __int64, unsigned __int64, __int64, const wchar_t *))v44->vfptr->__vecDelDtor)(
            v44,
            1i64,
            v35,
            v32,
            result.PlaceHolder.pText);
      }
      v49 = &v50.Url;
      v45 = v50.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v50.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, unsigned __int64, __int64, const wchar_t *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v45,
          v35,
          v32,
          result.PlaceHolder.pText);
      v49 = &v50.FontList;
      v46 = v50.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v50.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, unsigned __int64, __int64, const wchar_t *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v46,
          v35,
          v32,
          result.PlaceHolder.pText);
      v5 = v57;
      v9 = v58;
      if ( v10 <= 0 )
        goto LABEL_95;
    }
  }
  ++v7->ModCounter;
  v47 = result.PlaceHolder.pFormat.pObject;
  if ( result.PlaceHolder.pFormat.pObject )
  {
    v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
    if ( v17 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v47);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v47);
    }
  }
}

// File Line: 314
// RVA: 0x98D3C0
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Paragraph::GetTextFormat(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::TextFormat *result, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // rsi
  Scaleform::Render::Text::TextFormat *v6; // r12
  Scaleform::Render::Text::Paragraph *v7; // rbx
  signed __int64 v8; // r14
  Scaleform::MemoryHeap *v9; // rax
  Scaleform::MemoryHeap *v10; // rdx
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::MemoryHeap *v12; // rax
  int v13; // er15
  unsigned __int64 v14; // r8
  Scaleform::Render::Text::TextFormat *v15; // rbx
  unsigned __int64 v16; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v17; // r10
  unsigned __int64 v18; // r9
  const wchar_t *v19; // rax
  Scaleform::Render::Text::TextFormat *v20; // rdi
  unsigned __int64 v21; // rdx
  bool v22; // zf
  int v23; // eax
  Scaleform::Render::Text::TextFormat *v24; // rax
  Scaleform::Render::Text::TextFormat *v25; // rbx
  Scaleform::Render::Text::Paragraph::FormatRunIterator resulta; // [rsp+20h] [rbp-E0h]
  int v28; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+80h] [rbp-80h]
  __int64 v30; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Text::TextFormat v31; // [rsp+D8h] [rbp-28h]

  v30 = -2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = result;
  v7 = this;
  v28 = 0;
  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &resulta, startPos);
  if ( v4 < v5 )
    v4 = v5;
  if ( v4 == -1i64 )
    v8 = 0x7FFFFFFFFFFFFFFFi64;
  else
    v8 = v4 - v5;
  v9 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v7);
  v10 = v9;
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  v11 = Scaleform::Memory::pGlobalHeap;
  if ( v9 )
    v11 = v9;
  fmt.FontList.pHeap = v11;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v12 = Scaleform::Memory::pGlobalHeap;
  if ( v10 )
    v12 = v10;
  fmt.Url.pHeap = v12;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  fmt.pImageDesc.pObject = 0i64;
  fmt.pFontHandle.pObject = 0i64;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0.0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  v13 = 0;
  if ( v8 > 0 )
  {
    v14 = resulta.CurTextIndex;
    v15 = resulta.PlaceHolder.pFormat.pObject;
    do
    {
      v16 = resulta.pText->Size;
      if ( v14 >= v16 )
        break;
      if ( resulta.FormatIterator.Index < 0
        || resulta.FormatIterator.Index >= resulta.FormatIterator.pArray->Ranges.Data.Size )
      {
        v19 = &resulta.pText->pText[v14];
        resulta.PlaceHolder.Length = v16 - v14;
      }
      else
      {
        v17 = resulta.FormatIterator.pArray->Ranges.Data.Data;
        v18 = resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index;
        if ( v14 >= v18 )
        {
          v20 = v17[resulta.FormatIterator.Index].Data.pObject;
          v21 = v17[resulta.FormatIterator.Index].Length;
          resulta.PlaceHolder.pText = &resulta.pText->pText[v18];
          resulta.PlaceHolder.Index = v18;
          resulta.PlaceHolder.Length = v21;
          if ( v20 )
          {
            ++v20->RefCount;
            v14 = resulta.CurTextIndex;
            v15 = resulta.PlaceHolder.pFormat.pObject;
          }
          if ( v15 )
          {
            v22 = v15->RefCount-- == 1;
            if ( v22 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v15);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
            }
            v14 = resulta.CurTextIndex;
          }
          v15 = v20;
          resulta.PlaceHolder.pFormat.pObject = v20;
          if ( v20 )
          {
            v23 = v13++;
            if ( v23 )
            {
              v24 = Scaleform::Render::Text::TextFormat::Intersection(v20, &v31, &fmt);
              Scaleform::Render::Text::TextFormat::operator=(&fmt, v24);
              Scaleform::Render::Text::TextFormat::~TextFormat(&v31);
            }
            else
            {
              Scaleform::Render::Text::TextFormat::operator=(&fmt, v20);
            }
            v14 = resulta.CurTextIndex;
            v15 = resulta.PlaceHolder.pFormat.pObject;
          }
          goto LABEL_34;
        }
        v19 = &resulta.pText->pText[v14];
        resulta.PlaceHolder.Length = v18 - v14;
      }
      resulta.PlaceHolder.Index = v14;
      resulta.PlaceHolder.pText = v19;
      if ( v15 )
      {
        v22 = v15->RefCount-- == 1;
        if ( v22 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v15);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
        }
        v14 = resulta.CurTextIndex;
      }
      v15 = 0i64;
      resulta.PlaceHolder.pFormat.pObject = 0i64;
LABEL_34:
      v8 += v5 - resulta.PlaceHolder.Length - resulta.PlaceHolder.Index;
      v5 = resulta.PlaceHolder.Length + resulta.PlaceHolder.Index;
      if ( resulta.FormatIterator.Index < 0
        || resulta.FormatIterator.Index >= resulta.FormatIterator.pArray->Ranges.Data.Size )
      {
        v14 = resulta.pText->Size;
        resulta.CurTextIndex = resulta.pText->Size;
      }
      else if ( v14 >= resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index )
      {
        v14 += resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Length;
        resulta.CurTextIndex = v14;
        if ( resulta.FormatIterator.Index < (signed __int64)resulta.FormatIterator.pArray->Ranges.Data.Size )
          ++resulta.FormatIterator.Index;
      }
      else
      {
        v14 = resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index;
        resulta.CurTextIndex = resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index;
      }
    }
    while ( v8 > 0 );
  }
  Scaleform::Render::Text::TextFormat::TextFormat(v6, &fmt, 0i64);
  v28 = 1;
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  v25 = resulta.PlaceHolder.pFormat.pObject;
  if ( resulta.PlaceHolder.pFormat.pObject )
  {
    v22 = resulta.PlaceHolder.pFormat.pObject->RefCount-- == 1;
    if ( v22 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v25);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
    }
  }
  return v6;
}

// File Line: 342
// RVA: 0x98D750
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Paragraph::GetTextFormatPtr(Scaleform::Render::Text::Paragraph *this, unsigned __int64 startPos)
{
  Scaleform::Render::Text::TextFormat *v2; // rbx
  unsigned __int64 v3; // rcx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v4; // r10
  __int64 v5; // r8
  wchar_t *v6; // rax
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v7; // rax
  Scaleform::Render::Text::TextFormat *v8; // rdi
  bool v9; // zf
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+40h] [rbp-58h]

  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &result, startPos);
  v2 = 0i64;
  v3 = result.pText->Size;
  if ( result.CurTextIndex >= v3 )
    goto LABEL_14;
  if ( result.FormatIterator.Index < 0 || result.FormatIterator.Index >= result.FormatIterator.pArray->Ranges.Data.Size )
  {
    v6 = result.pText->pText;
    result.PlaceHolder.Length = v3 - result.CurTextIndex;
LABEL_8:
    v8 = result.PlaceHolder.pFormat.pObject;
    result.PlaceHolder.Index = result.CurTextIndex;
    result.PlaceHolder.pText = &v6[result.CurTextIndex];
    if ( result.PlaceHolder.pFormat.pObject )
    {
      v9 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
      if ( v9 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
    v7 = &result;
    result.PlaceHolder.pFormat.pObject = 0i64;
    goto LABEL_12;
  }
  v4 = &result.FormatIterator.pArray->Ranges.Data.Data[result.FormatIterator.Index];
  v5 = v4->Index;
  v6 = result.pText->pText;
  if ( result.CurTextIndex < v4->Index )
  {
    result.PlaceHolder.Length = v5 - result.CurTextIndex;
    goto LABEL_8;
  }
  v7 = (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                  &result.PlaceHolder,
                                                                  &v6[v5],
                                                                  v5,
                                                                  v4->Length,
                                                                  v4->Data.pObject);
LABEL_12:
  v10 = v7->PlaceHolder.pFormat.pObject;
  if ( v10 )
    v2 = v10;
LABEL_14:
  v11 = result.PlaceHolder.pFormat.pObject;
  if ( result.PlaceHolder.pFormat.pObject )
  {
    v9 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
    if ( v9 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v11);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
    }
  }
  return v2;
}

// File Line: 386
// RVA: 0x9B0520
void __fastcall Scaleform::Render::Text::Paragraph::SetFormat(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::ParagraphFormat *fmt)
{
  Scaleform::Render::Text::Allocator *v3; // rbx
  Scaleform::Render::Text::Paragraph *v4; // rdi
  Scaleform::Render::Text::ParagraphFormat *v5; // rcx
  Scaleform::Render::Text::ParagraphFormat *v6; // rax
  Scaleform::Render::Text::ParagraphFormat *v7; // rbx
  Scaleform::Render::Text::ParagraphFormat *v8; // rcx
  Scaleform::Render::Text::ParagraphFormat result; // [rsp+28h] [rbp-30h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+78h] [rbp+20h]

  v3 = pallocator;
  v4 = this;
  v5 = this->pFormat.pObject;
  if ( v5 )
  {
    v6 = Scaleform::Render::Text::ParagraphFormat::Merge(v5, &result, fmt);
    v7 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v3, v6);
    if ( result.pAllocator )
    {
      key = &result;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&result.pAllocator->ParagraphFormatStorage.pTable,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, result.pTabStops);
    result.pTabStops = 0i64;
  }
  else
  {
    v7 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, fmt);
  }
  if ( v7 )
    ++v7->RefCount;
  v8 = v4->pFormat.pObject;
  if ( v8 )
    Scaleform::Render::Text::ParagraphFormat::Release(v8);
  v4->pFormat.pObject = v7;
  ++v4->ModCounter;
  if ( v7 )
    Scaleform::Render::Text::ParagraphFormat::Release(v7);
}

// File Line: 403
// RVA: 0x987D10
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::GetIterator(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Paragraph::FormatRunIterator *result)
{
  result->PlaceHolder.pText = 0i64;
  result->PlaceHolder.Index = 0i64;
  result->PlaceHolder.Length = 0i64;
  result->PlaceHolder.pFormat.pObject = 0i64;
  result->pFormatInfo = &this->FormatInfo;
  result->FormatIterator.pArray = &this->FormatInfo;
  result->FormatIterator.Index = 0i64;
  result->pText = (Scaleform::Render::Text::Paragraph::TextBuffer *)this;
  result->CurTextIndex = 0i64;
  return result;
}

// File Line: 408
// RVA: 0x987D70
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::GetIteratorAt(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Paragraph::FormatRunIterator *result, unsigned __int64 index)
{
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v3; // rbx

  v3 = result;
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    result,
    &this->FormatInfo,
    &this->Text,
    index);
  return v3;
}

// File Line: 424
// RVA: 0x9B40D0
void __fastcall Scaleform::Render::Text::Paragraph::SetTermNullFormat(Scaleform::Render::Text::Paragraph *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::Text::Paragraph *v2; // rbx
  wchar_t *v3; // rax
  wchar_t *v4; // rdx
  unsigned __int64 v5; // r8
  wchar_t *v6; // rcx
  unsigned __int64 v7; // rcx

  v1 = this->Text.Size;
  v2 = this;
  if ( v1 )
  {
    v3 = this->Text.pText;
    v4 = 0i64;
    v5 = v1 - 1;
    if ( !this->Text.pText || (v6 = &v3[v5], v5 >= v1) )
      v6 = 0i64;
    if ( !*v6 )
    {
      if ( v1 )
      {
        v7 = v1 - 1;
        if ( v3 && v7 < v1 )
          v4 = &v3[v7];
        if ( !*v4 )
          --v1;
      }
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &v2->FormatInfo,
        v1,
        1ui64);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &v2->FormatInfo,
        v1 + 1,
        1ui64);
    }
  }
}

// File Line: 438
// RVA: 0x995870
void __fastcall Scaleform::Render::Text::Paragraph::InsertString(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, const wchar_t *pstr, unsigned __int64 pos, unsigned __int64 length, Scaleform::Render::Text::TextFormat *pnewFmt)
{
  __int64 v6; // rbp
  const wchar_t *v7; // rdi
  Scaleform::Render::Text::Paragraph *v8; // rsi
  unsigned __int64 v9; // rbx
  wchar_t *v10; // r14
  Scaleform::Render::Text::TextFormat *v11; // rbx
  bool v12; // zf
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+28h] [rbp-30h]

  v6 = pos;
  v7 = pstr;
  v8 = this;
  v9 = length;
  if ( length )
  {
    if ( length == -1i64 )
    {
      v9 = 0i64;
      if ( *pstr )
      {
        do
          ++v9;
        while ( pstr[v9] );
      }
    }
    if ( v9 )
    {
      v10 = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, pos, v9);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &v8->FormatInfo,
        v6,
        v9);
      ++v8->ModCounter;
      if ( v10 )
      {
        memmove(v10, v7, 2 * v9);
        if ( pnewFmt )
        {
          ++pnewFmt->RefCount;
          range.Index = v6;
          range.Length = v9;
          ++pnewFmt->RefCount;
          range.Data.pObject = pnewFmt;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &v8->FormatInfo,
            &range);
          v11 = range.Data.pObject;
          if ( range.Data.pObject )
          {
            v12 = range.Data.pObject->RefCount-- == 1;
            if ( v12 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v11);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
            }
          }
          v12 = pnewFmt->RefCount-- == 1;
          if ( v12 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(pnewFmt);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pnewFmt);
          }
        }
        Scaleform::Render::Text::Paragraph::SetTermNullFormat(v8);
        ++v8->ModCounter;
      }
    }
  }
}

// File Line: 502
// RVA: 0x959BB0
void __fastcall Scaleform::Render::Text::Paragraph::AppendTermNull(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::TextFormat *pdefTextFmt)
{
  Scaleform::Render::Text::TextFormat *v3; // rsi
  Scaleform::Render::Text::Allocator *v4; // r15
  Scaleform::Render::Text::Paragraph *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rax
  wchar_t *v8; // rcx
  bool v9; // cf
  wchar_t *v10; // rax
  unsigned __int64 v11; // rax
  wchar_t *v12; // rax
  wchar_t *v13; // r14
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v14; // rbp
  Scaleform::Render::Text::TextFormat *v15; // rax
  Scaleform::Render::Text::TextFormat *v16; // rbx
  Scaleform::Render::Text::TextFormat *v17; // rdi
  bool v18; // zf
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+28h] [rbp-40h]

  v3 = pdefTextFmt;
  v4 = pallocator;
  v5 = this;
  v6 = this->Text.Size;
  if ( !v6 )
  {
LABEL_12:
    v13 = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&v5->Text, pallocator, v6, 1ui64);
    v14 = &v5->FormatInfo;
    Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
      &v5->FormatInfo,
      v6,
      1ui64);
    ++v5->ModCounter;
    if ( v13 )
    {
      *v13 = 0;
      if ( !v5->FormatInfo.Ranges.Data.Size )
      {
        if ( v3 )
        {
          v15 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v4, v3);
          v16 = v15;
          range.Index = v6;
          range.Length = 1i64;
          if ( v15 )
            ++v15->RefCount;
          range.Data.pObject = v15;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            v14,
            &range);
          v17 = range.Data.pObject;
          if ( range.Data.pObject )
          {
            v18 = range.Data.pObject->RefCount-- == 1;
            if ( v18 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v17);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17);
            }
          }
          if ( v16 )
          {
            v18 = v16->RefCount-- == 1;
            if ( v18 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v16);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
            }
          }
        }
      }
    }
    return;
  }
  v7 = v6 - 1;
  v8 = this->Text.pText;
  if ( !v8 || (v9 = v7 < v6, v10 = &v8[v7], !v9) )
    v10 = 0i64;
  if ( *v10 )
  {
    if ( v6 )
    {
      v11 = v6 - 1;
      if ( !v5->Text.pText || (v9 = v11 < v6, v12 = &v5->Text.pText[v11], !v9) )
        v12 = 0i64;
      if ( !*v12 )
        --v6;
    }
    goto LABEL_12;
  }
}

// File Line: 522
// RVA: 0x9AA680
void __fastcall Scaleform::Render::Text::Paragraph::RemoveTermNull(Scaleform::Render::Text::Paragraph *this)
{
  unsigned __int64 v1; // rdx
  Scaleform::Render::Text::Paragraph *v2; // rbx
  wchar_t *v3; // rax
  wchar_t *v4; // rcx
  unsigned __int64 v5; // r8
  bool v6; // cf
  wchar_t *v7; // r8
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // rcx

  v1 = this->Text.Size;
  v2 = this;
  if ( v1 )
  {
    v3 = this->Text.pText;
    v4 = 0i64;
    v5 = v1 - 1;
    if ( !v3 || (v6 = v5 < v1, v7 = &v3[v5], !v6) )
      v7 = 0i64;
    if ( !*v7 )
    {
      if ( v1 )
      {
        v8 = v1 - 1;
        if ( v3 && v8 < v1 )
          v4 = &v3[v8];
        if ( !*v4 )
          --v1;
      }
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &v2->FormatInfo,
        v1,
        1ui64);
      v9 = v2->Text.Size;
      if ( v9 )
      {
        if ( !v2->Text.pText[v9 - 1] )
          v2->Text.Size = v9 - 1;
      }
    }
  }
}

// File Line: 549
// RVA: 0x988350
unsigned __int64 __fastcall Scaleform::Render::Text::Paragraph::GetLength(Scaleform::Render::Text::Paragraph *this)
{
  unsigned __int64 result; // rax
  unsigned __int64 v2; // rdx
  wchar_t *v3; // rcx

  result = this->Text.Size;
  if ( result )
  {
    v2 = result - 1;
    if ( this->Text.pText && v2 < result )
      v3 = &this->Text.pText[v2];
    else
      v3 = 0i64;
    if ( !*v3 )
      --result;
  }
  return result;
}

// File Line: 557
// RVA: 0x9A8930
void __fastcall Scaleform::Render::Text::Paragraph::Remove(Scaleform::Render::Text::Paragraph *this, unsigned __int64 startPos, unsigned __int64 endPos)
{
  __int64 v3; // rsi
  Scaleform::Render::Text::Paragraph *v4; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8

  v3 = startPos;
  v4 = this;
  if ( endPos == -1i64 )
  {
    v5 = -1i64;
  }
  else
  {
    v5 = endPos - startPos;
    if ( endPos == startPos )
      return;
  }
  v6 = this->Text.Size;
  if ( startPos < v6 )
  {
    if ( v5 + startPos < v6 )
    {
      memmove(&this->Text.pText[startPos], &this->Text.pText[v5 + startPos], 2 * (v6 - v5 - startPos));
      v4->Text.Size -= v5;
    }
    else
    {
      this->Text.Size = startPos;
    }
  }
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
    &v4->FormatInfo,
    v3,
    v5);
  Scaleform::Render::Text::Paragraph::SetTermNullFormat(v4);
  ++v4->ModCounter;
}

// File Line: 581
// RVA: 0x9642F0
void __fastcall Scaleform::Render::Text::Paragraph::Copy(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::Paragraph *psrcPara, unsigned __int64 startSrcIndex)
{
  signed __int64 v4; // r12
  Scaleform::Render::Text::Paragraph *v5; // rbx
  Scaleform::Render::Text::Paragraph *v6; // r13
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r10
  wchar_t *v9; // r15
  unsigned __int64 v10; // rdx
  __int64 v11; // r8
  Scaleform::Render::Text::TextFormat *v12; // rbx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v13; // r9
  __int64 v14; // r11
  wchar_t *v15; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v16; // rax
  bool v17; // zf
  __int64 v18; // r9
  unsigned __int64 v19; // rcx
  signed __int64 v20; // rdi
  unsigned __int64 v21; // rsi
  Scaleform::Render::Text::TextFormat *v22; // rax
  Scaleform::Render::Text::TextFormat *v23; // rbx
  Scaleform::Render::Text::TextFormat *v24; // rdi
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v25; // r10
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // rcx
  wchar_t *v28; // rax
  bool v29; // cf
  wchar_t *v30; // rcx
  unsigned __int64 v31; // rcx
  Scaleform::Render::Text::TextFormat *v32; // rbx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+10h] [rbp-41h]
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+28h] [rbp-29h]
  Scaleform::Render::Text::Allocator *v35; // [rsp+B0h] [rbp+5Fh]
  char *retaddr; // [rsp+C8h] [rbp+77h]
  unsigned __int64 v37; // [rsp+D0h] [rbp+7Fh]

  v4 = startSrcIndex;
  v5 = psrcPara;
  v6 = this;
  v7 = v37;
  if ( v37 )
  {
    Scaleform::Render::Text::Paragraph::InsertString(
      this,
      pallocator,
      &psrcPara->Text.pText[startSrcIndex],
      (unsigned __int64)retaddr,
      v37);
    Scaleform::Render::Text::Paragraph::GetIteratorAt(v5, &result, v4);
    v8 = result.pText->Size;
    v9 = 0i64;
    v10 = result.CurTextIndex;
    if ( result.CurTextIndex < v8 )
    {
      v11 = result.FormatIterator.Index;
      v12 = result.PlaceHolder.pFormat.pObject;
      while ( 1 )
      {
        if ( !v7 )
          goto LABEL_39;
        if ( v11 < 0 || v11 >= result.FormatIterator.pArray->Ranges.Data.Size )
          break;
        v13 = &result.FormatIterator.pArray->Ranges.Data.Data[v11];
        v14 = v13->Index;
        v15 = result.pText->pText;
        if ( v10 < v13->Index )
        {
          result.PlaceHolder.Length = v14 - v10;
LABEL_11:
          result.PlaceHolder.Index = v10;
          result.PlaceHolder.pText = &v15[v10];
          if ( v12 )
          {
            v17 = v12->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v12);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
            }
            v11 = result.FormatIterator.Index;
            v10 = result.CurTextIndex;
          }
          v12 = 0i64;
          v16 = &result;
          result.PlaceHolder.pFormat.pObject = 0i64;
          goto LABEL_16;
        }
        range.Data.pObject = v13->Data.pObject;
        v16 = (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                         &result.PlaceHolder,
                                                                         &v15[v14],
                                                                         v14,
                                                                         v13->Length,
                                                                         range.Data.pObject);
        v10 = result.CurTextIndex;
        v11 = result.FormatIterator.Index;
        v12 = result.PlaceHolder.pFormat.pObject;
LABEL_16:
        v18 = v16->PlaceHolder.Index;
        v19 = v16->PlaceHolder.Length;
        if ( v18 >= v4 )
        {
          v20 = v18 - v4;
        }
        else
        {
          v20 = 0i64;
          v19 = v18 + v19 - v4;
        }
        v21 = v7;
        if ( v19 < v7 )
          v21 = v19;
        if ( v16->PlaceHolder.pFormat.pObject )
        {
          v22 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v35, v16->PlaceHolder.pFormat.pObject);
          v23 = v22;
          range.Index = (__int64)&retaddr[v20];
          range.Length = v21;
          if ( v22 )
            ++v22->RefCount;
          range.Data.pObject = v22;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &v6->FormatInfo,
            &range);
          v24 = range.Data.pObject;
          if ( range.Data.pObject )
          {
            v17 = range.Data.pObject->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v24);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v24);
            }
          }
          if ( v23 )
          {
            v17 = v23->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v23);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v23);
            }
          }
          v12 = result.PlaceHolder.pFormat.pObject;
          v11 = result.FormatIterator.Index;
          v10 = result.CurTextIndex;
        }
        v7 -= v21;
        if ( v11 < 0 || v11 >= result.FormatIterator.pArray->Ranges.Data.Size )
        {
          v10 = result.pText->Size;
          result.CurTextIndex = result.pText->Size;
        }
        else
        {
          v25 = &result.FormatIterator.pArray->Ranges.Data.Data[v11];
          if ( v10 >= v25->Index )
          {
            v10 += v25->Length;
            result.CurTextIndex = v10;
            if ( v11 < (signed __int64)result.FormatIterator.pArray->Ranges.Data.Size )
              result.FormatIterator.Index = ++v11;
          }
          else
          {
            v10 = v25->Index;
            result.CurTextIndex = v25->Index;
          }
        }
        v8 = result.pText->Size;
        if ( v10 >= v8 )
          goto LABEL_39;
      }
      v15 = result.pText->pText;
      result.PlaceHolder.Length = v8 - v10;
      goto LABEL_11;
    }
LABEL_39:
    v26 = v6->Text.Size;
    if ( v26 )
    {
      v27 = v26 - 1;
      v28 = v6->Text.pText;
      if ( !v6->Text.pText || (v29 = v27 < v26, v30 = &v28[v27], !v29) )
        v30 = 0i64;
      if ( !*v30 )
      {
        if ( v26 )
        {
          v31 = v26 - 1;
          if ( v28 && v31 < v26 )
            v9 = &v28[v31];
          if ( !*v9 )
            --v26;
        }
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
          &v6->FormatInfo,
          v26,
          1ui64);
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
          &v6->FormatInfo,
          v26 + 1,
          1ui64);
      }
    }
    ++v6->ModCounter;
    v32 = result.PlaceHolder.pFormat.pObject;
    if ( result.PlaceHolder.pFormat.pObject )
    {
      v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
      if ( v17 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v32);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v32);
      }
    }
  }
}32);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v32);
      }
    }
  }
}

// File Line: 687
// RVA: 0x93C030
void __fastcall Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(Scaleform::Render::Text::Paragraph::FormatRunIterator *this, Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *fmts, Scaleform::Render::Text::Paragraph::TextBuffer *textHandle, unsigned __int64 index)
{
  signed __int64 v4; // rdi
  Scaleform::Render::Text::Paragraph::TextBuffer *v5; // rbp
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v6; // rsi
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v7; // rbx
  signed __int64 v8; // rax
  unsigned __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // r8
  __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rcx

  v4 = index;
  v5 = textHandle;
  v6 = fmts;
  v7 = this;
  this->PlaceHolder.pText = 0i64;
  this->PlaceHolder.Index = 0i64;
  this->PlaceHolder.Length = 0i64;
  this->PlaceHolder.pFormat.pObject = 0i64;
  this->pFormatInfo = fmts;
  v8 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)fmts,
         index);
  v7->FormatIterator.pArray = v6;
  v7->FormatIterator.Index = 0i64;
  if ( v8 >= 0 )
  {
    v9 = v6->Ranges.Data.Size;
    if ( v8 >= v9 )
      v8 = v9 - 1;
    v7->FormatIterator.Index = v8;
  }
  else
  {
    v7->FormatIterator.Index = 0i64;
  }
  v7->pText = v5;
  v7->CurTextIndex = 0i64;
  v10 = v7->FormatIterator.Index;
  if ( v10 >= 0 && v10 < v6->Ranges.Data.Size )
  {
    v11 = v6->Ranges.Data.Data[v10].Index;
    if ( v4 < v11 || v4 > (signed __int64)(v6->Ranges.Data.Data[v10].Length + v11 - 1) )
    {
      v12 = v7->FormatIterator.Index;
      if ( v4 > v6->Ranges.Data.Data[v12].Index )
      {
        v13 = v6->Ranges.Data.Data[v12].Index;
        v7->CurTextIndex = v13;
        v7->CurTextIndex = v13 + v6->Ranges.Data.Data[v7->FormatIterator.Index].Length;
        v14 = v7->FormatIterator.Index;
        if ( v14 < (signed __int64)v6->Ranges.Data.Size )
          v7->FormatIterator.Index = v14 + 1;
      }
    }
    else
    {
      v7->CurTextIndex = v6->Ranges.Data.Data[v7->FormatIterator.Index].Index;
    }
  }
}

// File Line: 722
// RVA: 0x94ECC0
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(Scaleform::Render::Text::Paragraph::FormatRunIterator *this)
{
  __int64 v1; // rax
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v2; // rbx
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v3; // rcx
  unsigned __int64 v4; // r8
  signed __int64 v5; // r9
  unsigned __int64 v6; // rdx
  wchar_t *v7; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *result; // rax
  Scaleform::Render::Text::Paragraph::TextBuffer *v9; // rax
  __int64 v10; // r8
  unsigned __int64 v11; // rdx
  wchar_t *v12; // rax
  Scaleform::Render::Text::TextFormat *v13; // rdi
  bool v14; // zf

  v1 = this->FormatIterator.Index;
  v2 = this;
  if ( v1 < 0 || (v3 = this->FormatIterator.pArray, v1 >= v3->Ranges.Data.Size) )
  {
    v9 = v2->pText;
    v10 = v2->CurTextIndex;
    v11 = v9->Size;
    v12 = v9->pText;
    v2->PlaceHolder.Index = v10;
    v2->PlaceHolder.pText = &v12[v10];
    v2->PlaceHolder.Length = v11 - v10;
  }
  else
  {
    v4 = v3->Ranges.Data.Data[v1].Index;
    v5 = (signed __int64)&v3->Ranges.Data.Data[v1];
    v6 = v2->CurTextIndex;
    v7 = v2->pText->pText;
    if ( v6 >= v4 )
      return (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                        &v2->PlaceHolder,
                                                                        &v7[v4],
                                                                        v4,
                                                                        *(_QWORD *)(v5 + 8),
                                                                        *(Scaleform::Render::Text::TextFormat **)(v5 + 16));
    v2->PlaceHolder.Index = v6;
    v2->PlaceHolder.pText = &v7[v6];
    v2->PlaceHolder.Length = v4 - v6;
  }
  v13 = v2->PlaceHolder.pFormat.pObject;
  if ( v13 )
  {
    v14 = v13->RefCount-- == 1;
    if ( v14 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v13);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
    }
  }
  result = v2;
  v2->PlaceHolder.pFormat.pObject = 0i64;
  return result;
}

// File Line: 791
// RVA: 0x9395F0
void __fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(Scaleform::Render::Text::Paragraph::CharactersIterator *this, Scaleform::Render::Text::Paragraph *pparagraph, unsigned __int64 index)
{
  signed __int64 v3; // rdi
  Scaleform::Render::Text::Paragraph *v4; // rbp
  Scaleform::Render::Text::Paragraph::CharactersIterator *v5; // rbx
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v6; // rsi
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // rax
  __int64 v9; // rcx
  signed __int64 v10; // r8
  __int64 v11; // rcx

  v3 = index;
  v4 = pparagraph;
  v5 = this;
  this->PlaceHolder.pFormat.pObject = 0i64;
  this->PlaceHolder.Index = 0i64;
  this->PlaceHolder.Character = 0;
  v6 = &pparagraph->FormatInfo;
  this->pFormatInfo = &pparagraph->FormatInfo;
  v7 = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
         (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)&pparagraph->FormatInfo,
         index);
  v5->FormatIterator.pArray = v6;
  v5->FormatIterator.Index = 0i64;
  if ( (v7 & 0x8000000000000000ui64) == 0i64 )
  {
    v8 = v6->Ranges.Data.Size;
    if ( v7 < v8 )
      v5->FormatIterator.Index = v7;
    else
      v5->FormatIterator.Index = v8 - 1;
  }
  else
  {
    v5->FormatIterator.Index = 0i64;
  }
  v5->pText = (Scaleform::Render::Text::Paragraph::TextBuffer *)v4;
  v5->CurTextIndex = v3;
  v9 = v5->FormatIterator.Index;
  if ( v9 >= 0 && v9 < v6->Ranges.Data.Size )
  {
    v10 = v6->Ranges.Data.Data[v9].Index;
    if ( (v3 < v10 || v3 > (signed __int64)(v6->Ranges.Data.Data[v9].Length + v10 - 1))
      && (signed int)v3 > v6->Ranges.Data.Data[v5->FormatIterator.Index].Index )
    {
      v11 = v5->FormatIterator.Index;
      if ( v11 < (signed __int64)v6->Ranges.Data.Size )
        v5->FormatIterator.Index = v11 + 1;
    }
  }
}

// File Line: 802
// RVA: 0x94EB90
Scaleform::Render::Text::Paragraph::CharactersIterator *__fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(Scaleform::Render::Text::Paragraph::CharactersIterator *this)
{
  Scaleform::Render::Text::Paragraph::TextBuffer *v1; // rax
  Scaleform::Render::Text::Paragraph::CharactersIterator *v2; // rbx
  unsigned __int64 v3; // r8
  wchar_t v4; // dx
  __int64 v5; // rax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v6; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v7; // rsi
  Scaleform::Render::Text::TextFormat *v8; // rdi
  bool v9; // zf
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::TextFormat *v13; // rsi

  v1 = this->pText;
  v2 = this;
  if ( !v1 || (v3 = this->CurTextIndex, v3 >= v1->Size) )
  {
    this->PlaceHolder.Index = this->CurTextIndex;
    this->PlaceHolder.Character = 0;
    v13 = this->PlaceHolder.pFormat.pObject;
    if ( this->PlaceHolder.pFormat.pObject )
    {
      v9 = v13->RefCount-- == 1;
      if ( v9 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v13);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
      }
    }
    goto LABEL_21;
  }
  v4 = v1->pText[v3];
  this->PlaceHolder.Index = v3;
  this->PlaceHolder.Character = v4;
  v5 = this->FormatIterator.Index;
  if ( v5 < 0 || (v6 = this->FormatIterator.pArray, v5 >= v6->Ranges.Data.Size) )
  {
    v8 = this->PlaceHolder.pFormat.pObject;
LABEL_7:
    if ( v8 )
    {
      v9 = v8->RefCount-- == 1;
      if ( v9 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
LABEL_21:
    v2->PlaceHolder.pFormat.pObject = 0i64;
    return v2;
  }
  v7 = &v6->Ranges.Data.Data[v5];
  if ( v3 < v7->Index )
  {
    v8 = this->PlaceHolder.pFormat.pObject;
    goto LABEL_7;
  }
  v10 = v7->Data.pObject;
  if ( v10 )
    ++v10->RefCount;
  v11 = this->PlaceHolder.pFormat.pObject;
  if ( this->PlaceHolder.pFormat.pObject )
  {
    v9 = v11->RefCount-- == 1;
    if ( v9 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v11);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
    }
  }
  v2->PlaceHolder.pFormat.pObject = v7->Data.pObject;
  return v2;
}

// File Line: 855
// RVA: 0x94F1E0
void __fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(Scaleform::Render::Text::Paragraph::CharactersIterator *this, unsigned __int64 n)
{
  unsigned __int64 i; // r10
  Scaleform::Render::Text::Paragraph::TextBuffer *v3; // rax
  unsigned __int64 v4; // rdx
  __int64 v5; // r9
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v6; // rax
  __int64 v7; // r11

  for ( i = n; i; --i )
  {
    v3 = this->pText;
    if ( v3 && (v4 = this->CurTextIndex, v4 < v3->Size) )
    {
      this->CurTextIndex = v4 + 1;
      v5 = this->FormatIterator.Index;
      if ( v5 >= 0 )
      {
        v6 = this->FormatIterator.pArray;
        v7 = v6->Ranges.Data.Size;
        if ( v5 < (unsigned __int64)v7
          && v4 + 1 >= v6->Ranges.Data.Data[v5].Index + v6->Ranges.Data.Data[v5].Length
          && v5 < v7 )
        {
          this->FormatIterator.Index = v5 + 1;
        }
      }
    }
    else
    {
      this->CurTextIndex = v3->Size;
    }
  }
}

// File Line: 885
// RVA: 0x9452D0
void __fastcall Scaleform::Render::Text::StyledText::StyledText(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::Allocator *pallocator)
{
  Scaleform::Render::Text::Allocator *v2; // rdi
  Scaleform::Render::Text::StyledText *v3; // rbx
  Scaleform::Render::Text::ParagraphFormat *v4; // rax
  Scaleform::Render::Text::ParagraphFormat *v5; // rsi
  Scaleform::Render::Text::ParagraphFormat *v6; // rcx
  Scaleform::Render::Text::TextFormat *v7; // rsi
  Scaleform::Render::Text::TextFormat *v8; // rdi
  bool v9; // zf
  Scaleform::Render::Text::ParagraphFormat srcfmt; // [rsp+28h] [rbp-40h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+78h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v12; // [rsp+80h] [rbp+18h]

  v2 = pallocator;
  v3 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::StyledText,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::StyledText::`vftable;
  if ( pallocator )
    ++pallocator->RefCount;
  this->pTextAllocator.pObject = pallocator;
  v4 = (Scaleform::Render::Text::ParagraphFormat *)&this->Paragraphs;
  key = v4;
  v12 = &this->Paragraphs;
  v4->pAllocator = 0i64;
  *(_QWORD *)&v4->RefCount = 0i64;
  v4->pTabStops = 0i64;
  this->pDefaultParagraphFormat.pObject = 0i64;
  this->pDefaultTextFormat.pObject = 0i64;
  this->RTFlags = 0;
  srcfmt.pAllocator = 0i64;
  srcfmt.RefCount = 1;
  srcfmt.pTabStops = 0i64;
  *(_QWORD *)&srcfmt.BlockIndent = 0i64;
  *(_DWORD *)&srcfmt.RightMargin = 0;
  v5 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, &srcfmt);
  v6 = v3->pDefaultParagraphFormat.pObject;
  if ( v6 )
    Scaleform::Render::Text::ParagraphFormat::Release(v6);
  v3->pDefaultParagraphFormat.pObject = v5;
  if ( srcfmt.pAllocator )
  {
    key = &srcfmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&srcfmt.pAllocator->ParagraphFormatStorage.pTable,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, srcfmt.pTabStops);
  srcfmt.pTabStops = 0i64;
  v7 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v2, &v2->EntryTextFormat);
  v8 = v3->pDefaultTextFormat.pObject;
  if ( v8 )
  {
    v9 = v8->RefCount-- == 1;
    if ( v9 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v8);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  v3->pDefaultTextFormat.pObject = v7;
}

// File Line: 892
// RVA: 0x959000
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::AppendNewParagraph(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbp
  Scaleform::Render::Text::StyledText *v3; // rsi
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // r14
  Scaleform::Render::Text::Paragraph *v6; // rcx
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdx
  wchar_t *v10; // rcx
  Scaleform::Render::Text::Allocator *v11; // rax
  Scaleform::Render::Text::Paragraph *v12; // rbx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v13; // rdx
  Scaleform::Render::Text::ParagraphFormat *v14; // rcx
  unsigned __int64 v15; // rcx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v16; // rax
  Scaleform::Render::Text::Paragraph *v17; // rbx

  v2 = pdefParaFmt;
  v3 = this;
  v4 = this->Paragraphs.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    v6 = v3->Paragraphs.Data.Data[v4 - 1].pPara;
    v7 = v6->StartIndex;
    v8 = v6->Text.Size;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v6->Text.pText && v9 < v8 )
        v10 = &v6->Text.pText[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --v8;
    }
    v5 = v8 + v7;
  }
  v11 = Scaleform::Render::Text::StyledText::GetAllocator(v3);
  v12 = Scaleform::Render::Text::Allocator::AllocateParagraph(v11);
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Paragraphs.Data.Data,
    &v3->Paragraphs,
    v3->Paragraphs.Data.Size + 1);
  v13 = &v3->Paragraphs.Data.Data[v3->Paragraphs.Data.Size - 1];
  if ( v13 )
  {
    v13->pPara = v12;
    v12 = 0i64;
  }
  if ( v12 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v12->FormatInfo.Ranges.Data.Data,
      v12->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12->FormatInfo.Ranges.Data.Data);
    v14 = v12->pFormat.pObject;
    if ( v14 )
      Scaleform::Render::Text::ParagraphFormat::Release(v14);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
  v15 = v3->Paragraphs.Data.Size;
  v16 = v3->Paragraphs.Data.Data;
  v17 = v16[v15 - 1].pPara;
  if ( !v2 )
    v2 = v3->pDefaultParagraphFormat.pObject;
  Scaleform::Render::Text::Paragraph::SetFormat(v16[v15 - 1].pPara, v3->pTextAllocator.pObject, v2);
  v17->StartIndex = v5;
  return v17;
}

// File Line: 913
// RVA: 0x958E30
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::Paragraph *srcPara)
{
  Scaleform::Render::Text::Paragraph *v2; // rdi
  Scaleform::Render::Text::StyledText *v3; // rsi
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rbp
  Scaleform::Render::Text::Paragraph *v6; // rcx
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdx
  wchar_t *v10; // rcx
  Scaleform::Render::Text::Allocator *v11; // rax
  Scaleform::Render::Text::Allocator *v12; // rbx
  Scaleform::Render::Text::Paragraph *v13; // rax
  Scaleform::Render::Text::Paragraph *v14; // rax
  Scaleform::Render::Text::Paragraph *v15; // rbx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v16; // rdx
  Scaleform::Render::Text::ParagraphFormat *v17; // rcx
  Scaleform::Render::Text::Paragraph *result; // rax

  v2 = srcPara;
  v3 = this;
  v4 = this->Paragraphs.Data.Size;
  v5 = 0i64;
  if ( v4 )
  {
    v6 = v3->Paragraphs.Data.Data[v4 - 1].pPara;
    v7 = v6->StartIndex;
    v8 = v6->Text.Size;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( v6->Text.pText && v9 < v8 )
        v10 = &v6->Text.pText[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --v8;
    }
    v5 = v8 + v7;
  }
  v11 = Scaleform::Render::Text::StyledText::GetAllocator(v3);
  v12 = v11;
  v13 = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v11->pHeap->vfptr->Alloc)(
                                                v11->pHeap,
                                                72i64);
  if ( v13 )
  {
    Scaleform::Render::Text::Paragraph::Paragraph(v13, v2, v12);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Paragraphs.Data.Data,
    &v3->Paragraphs,
    v3->Paragraphs.Data.Size + 1);
  v16 = &v3->Paragraphs.Data.Data[v3->Paragraphs.Data.Size - 1];
  if ( v16 )
  {
    v16->pPara = v15;
    v15 = 0i64;
  }
  if ( v15 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v15->FormatInfo.Ranges.Data.Data,
      v15->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15->FormatInfo.Ranges.Data.Data);
    v17 = v15->pFormat.pObject;
    if ( v17 )
      Scaleform::Render::Text::ParagraphFormat::Release(v17);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
  }
  result = v3->Paragraphs.Data.Data[v3->Paragraphs.Data.Size - 1].pPara;
  result->StartIndex = v5;
  return result;
}

// File Line: 934
// RVA: 0x995600
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::InsertNewParagraph(Scaleform::Render::Text::StyledText *this, Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *iter, Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rbp
  Scaleform::Render::Text::StyledText *v4; // rsi
  __int64 v5; // rdi
  unsigned __int64 v6; // r15
  Scaleform::Render::Text::Paragraph *v7; // rcx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rdx
  wchar_t *v11; // rcx
  Scaleform::Render::Text::Allocator *v12; // rax
  Scaleform::Render::Text::Paragraph *v13; // rbx
  unsigned __int64 v14; // r8
  signed __int64 v15; // r12
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v16; // rcx
  Scaleform::Render::Text::ParagraphFormat *v17; // rcx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v18; // rax
  Scaleform::Render::Text::Paragraph *v19; // rbx

  v3 = pdefParaFmt;
  v4 = this;
  if ( !iter->pArray )
    return Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v5 = iter->CurIndex;
  if ( v5 < 0 || v5 >= SLODWORD(iter->pArray->Data.Size) )
    return Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = this->Paragraphs.Data.Data[v5 - 1].pPara;
    v8 = v7->StartIndex;
    v9 = v7->Text.Size;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v7->Text.pText && v10 < v9 )
        v11 = &v7->Text.pText[v10];
      else
        v11 = 0i64;
      if ( !*v11 )
        --v9;
    }
    v6 = v9 + v8;
  }
  v12 = Scaleform::Render::Text::StyledText::GetAllocator(v4);
  v13 = Scaleform::Render::Text::Allocator::AllocateParagraph(v12);
  Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v4->Paragraphs.Data,
    v4->Paragraphs.Data.Size + 1);
  v14 = v4->Paragraphs.Data.Size;
  if ( v5 < v14 - 1 )
    memmove(&v4->Paragraphs.Data.Data[v5 + 1], &v4->Paragraphs.Data.Data[v5], 8 * (v14 - v5) - 8);
  v15 = v5;
  v16 = &v4->Paragraphs.Data.Data[v5];
  if ( v16 )
  {
    v16->pPara = v13;
    v13 = 0i64;
  }
  if ( v13 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v13->FormatInfo.Ranges.Data.Data,
      v13->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13->FormatInfo.Ranges.Data.Data);
    v17 = v13->pFormat.pObject;
    if ( v17 )
      Scaleform::Render::Text::ParagraphFormat::Release(v17);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
  v18 = v4->Paragraphs.Data.Data;
  v19 = v18[v15].pPara;
  if ( !v3 )
    v3 = v4->pDefaultParagraphFormat.pObject;
  Scaleform::Render::Text::Paragraph::SetFormat(v18[v15].pPara, v4->pTextAllocator.pObject, v3);
  v19->StartIndex = v6;
  return v19;
}

// File Line: 960
// RVA: 0x994E40
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(Scaleform::Render::Text::StyledText *this, Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *iter, Scaleform::Render::Text::Paragraph *srcPara)
{
  Scaleform::Render::Text::Paragraph *v3; // r14
  Scaleform::Render::Text::StyledText *v4; // rsi
  __int64 v5; // rdi
  unsigned __int64 v6; // rbp
  Scaleform::Render::Text::Paragraph *v7; // rcx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rdx
  wchar_t *v11; // rcx
  Scaleform::Render::Text::Allocator *v12; // rax
  Scaleform::Render::Text::Allocator *v13; // rbx
  Scaleform::Render::Text::Paragraph *v14; // rax
  Scaleform::Render::Text::Paragraph *v15; // rax
  Scaleform::Render::Text::Paragraph *v16; // rbx
  unsigned __int64 v17; // r8
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v18; // rcx
  Scaleform::Render::Text::ParagraphFormat *v19; // rcx
  Scaleform::Render::Text::Paragraph *result; // rax

  v3 = srcPara;
  v4 = this;
  if ( !iter->pArray )
    return Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(this, srcPara);
  v5 = iter->CurIndex;
  if ( v5 < 0 || v5 >= SLODWORD(iter->pArray->Data.Size) )
    return Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(this, srcPara);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = this->Paragraphs.Data.Data[v5 - 1].pPara;
    v8 = v7->StartIndex;
    v9 = v7->Text.Size;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v7->Text.pText && v10 < v9 )
        v11 = &v7->Text.pText[v10];
      else
        v11 = 0i64;
      if ( !*v11 )
        --v9;
    }
    v6 = v9 + v8;
  }
  v12 = Scaleform::Render::Text::StyledText::GetAllocator(v4);
  v13 = v12;
  v14 = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v12->pHeap->vfptr->Alloc)(
                                                v12->pHeap,
                                                72i64);
  if ( v14 )
  {
    Scaleform::Render::Text::Paragraph::Paragraph(v14, v3, v13);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v4->Paragraphs.Data,
    v4->Paragraphs.Data.Size + 1);
  v17 = v4->Paragraphs.Data.Size;
  if ( v5 < v17 - 1 )
    memmove(&v4->Paragraphs.Data.Data[v5 + 1], &v4->Paragraphs.Data.Data[v5], 8 * (v17 - v5) - 8);
  v18 = &v4->Paragraphs.Data.Data[v5];
  if ( v18 )
  {
    v18->pPara = v16;
    v16 = 0i64;
  }
  if ( v16 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v16->FormatInfo.Ranges.Data.Data,
      v16->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16->FormatInfo.Ranges.Data.Data);
    v19 = v16->pFormat.pObject;
    if ( v19 )
      Scaleform::Render::Text::ParagraphFormat::Release(v19);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
  }
  result = v4->Paragraphs.Data.Data[v5].pPara;
  result->StartIndex = v6;
  return result;
}

// File Line: 984
// RVA: 0x987DC0
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::GetLastParagraph(Scaleform::Render::Text::StyledText *this)
{
  signed __int64 v1; // rdx
  Scaleform::Render::Text::Paragraph *result; // rax

  v1 = this->Paragraphs.Data.Size - 1;
  if ( this == (Scaleform::Render::Text::StyledText *)-24i64 || v1 < 0 || v1 >= SLODWORD(this->Paragraphs.Data.Size) )
    result = 0i64;
  else
    result = this->Paragraphs.Data.Data[v1].pPara;
  return result;
}

// File Line: 1015
// RVA: 0x959480
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::AppendString(Scaleform::Render::Text::StyledText *this, const char *putf8String, unsigned __int64 stringSize, Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy, Scaleform::Render::Text::TextFormat *pdefTextFmt, Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  char *v6; // rdi
  Scaleform::Render::Text::StyledText *v7; // r15
  const char *v8; // r12
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v9; // rdx
  unsigned __int64 v10; // rcx
  signed int v11; // ebx
  signed __int64 v12; // rcx
  Scaleform::Render::Text::Paragraph *v13; // r13
  unsigned __int64 v14; // rbp
  Scaleform::Render::Text::ParagraphFormat *v15; // rsi
  int v16; // ecx
  unsigned __int64 v17; // rbp
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  signed int v20; // esi
  unsigned __int64 v21; // r14
  unsigned int v22; // eax
  char *v23; // rcx
  wchar_t *v24; // rsi
  unsigned int v25; // eax
  signed int v26; // eax
  signed int v27; // eax
  Scaleform::Render::Text::TextFormat *v28; // rbx
  bool v29; // zf
  unsigned __int64 result; // rax
  unsigned __int64 v31; // [rsp+30h] [rbp-68h]
  unsigned __int64 v32; // [rsp+38h] [rbp-60h]
  Scaleform::Render::Text::Paragraph *v33; // [rsp+40h] [rbp-58h]
  int v34; // [rsp+A0h] [rbp+8h]
  char *putf8Buffer; // [rsp+A8h] [rbp+10h]
  unsigned __int64 v36; // [rsp+B0h] [rbp+18h]
  Scaleform::Render::Text::StyledText::NewLinePolicy v37; // [rsp+B8h] [rbp+20h]

  v37 = newLinePolicy;
  v6 = (char *)putf8String;
  v7 = this;
  if ( stringSize == -1i64 )
  {
    do
      ++stringSize;
    while ( putf8String[stringSize] );
  }
  v8 = &putf8String[stringSize];
  v9 = &this->Paragraphs;
  v10 = this->Paragraphs.Data.Size;
  v11 = 0;
  v36 = 0i64;
  v12 = v10 - 1;
  if ( !v9 || v12 < 0 || v12 >= SLODWORD(v9->Data.Size) )
  {
    v13 = 0i64;
    v33 = 0i64;
    goto LABEL_9;
  }
  v13 = v9->Data.Data[v12].pPara;
  v33 = v13;
  if ( !v13 )
  {
LABEL_9:
    v14 = 0i64;
    goto LABEL_10;
  }
  v14 = v13->StartIndex;
LABEL_10:
  v31 = v14;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))v7->vfptr[1].__vecDelDtor)(
    v7,
    v14,
    stringSize,
    v6);
  v15 = pdefParaFmt;
  v16 = 0;
  do
  {
    v34 = v16 + 1;
    if ( v16 || !v13 )
    {
      v17 = 0i64;
      v13 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, v15);
      v33 = v13;
      v13->StartIndex = v31;
      v32 = 0i64;
    }
    else
    {
      Scaleform::Render::Text::Paragraph::RemoveTermNull(v13);
      v17 = v13->Text.Size;
      v32 = v17;
      if ( !v17 )
        goto LABEL_67;
      v18 = v17 - 1;
      if ( v13->Text.pText && v18 < v17 )
        v19 = &v13->Text.pText[v18];
      else
        v19 = 0i64;
      if ( !*v19 )
        v32 = --v17;
      if ( !v17 )
      {
LABEL_67:
        if ( v15 )
          Scaleform::Render::Text::Paragraph::SetFormat(v13, v7->pTextAllocator.pObject, v15);
      }
    }
    v20 = v11;
    v21 = 0i64;
    v11 = -1;
    putf8Buffer = v6;
    if ( v6 >= v8 )
      break;
    while ( v11 )
    {
      v22 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v23 = putf8Buffer;
      if ( !v22 )
        v23 = putf8Buffer-- - 1;
      if ( v37 || v20 != 13 || v21 || (v20 = -1, v22 != 10) )
      {
        v11 = v22;
        if ( v22 == 10 )
          goto LABEL_39;
        if ( v22 == 13 )
          break;
        ++v21;
      }
      else
      {
        ++v6;
      }
      if ( v23 >= v8 )
        break;
    }
    if ( v11 == 10 || v11 == 13 )
LABEL_39:
      ++v21;
    if ( v21 )
    {
      v24 = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
              &v13->Text,
              v7->pTextAllocator.pObject,
              v17,
              v21);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &v13->FormatInfo,
        v17,
        v21);
      ++v13->ModCounter;
      v11 = -1;
      putf8Buffer = v6;
      if ( v6 < v8 )
      {
        do
        {
          if ( !v11 )
            break;
          v25 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          v6 = putf8Buffer;
          v11 = v25;
          if ( !v25 )
            v6 = putf8Buffer-- - 1;
          if ( v25 == 13 || v25 == 10 )
          {
            v11 = 10;
            if ( v7->RTFlags & 2 )
              v11 = 13;
          }
          *v24 = v11;
          ++v24;
          v26 = 10;
          if ( v7->RTFlags & 2 )
            v26 = 13;
        }
        while ( v11 != v26 && v6 < v8 );
        v17 = v32;
        v13 = v33;
      }
      Scaleform::Render::Text::Paragraph::SetTextFormat(
        v13,
        v7->pTextAllocator.pObject,
        pdefTextFmt,
        v17,
        0xFFFFFFFFFFFFFFFFui64);
      v31 += v21 + v17;
      v36 += v21;
    }
    if ( v6 >= v8 )
      break;
    v15 = pdefParaFmt;
    v16 = v34;
  }
  while ( v11 );
  v27 = 10;
  if ( v7->RTFlags & 2 )
    v27 = 13;
  if ( v11 == v27 )
    v13 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, pdefParaFmt);
  v28 = pdefTextFmt;
  Scaleform::Render::Text::Paragraph::AppendTermNull(v13, v7->pTextAllocator.pObject, pdefTextFmt);
  if ( !(v28->PresentMask & 0x100) )
    return v36;
  v29 = Scaleform::String::GetLength((Scaleform::String *)&v28->Url.0) == 0;
  result = v36;
  if ( !v29 )
    v7->RTFlags |= 1u;
  return result;
}

// File Line: 1127
// RVA: 0x9597C0
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::AppendString(Scaleform::Render::Text::StyledText *this, const wchar_t *pstr, unsigned __int64 length, Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy, Scaleform::Render::Text::TextFormat *pdefTextFmt, Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  signed int v6; // esi
  const wchar_t *v7; // r12
  unsigned __int64 v8; // rbp
  Scaleform::Render::Text::StyledText *v9; // r13
  unsigned __int64 v10; // r14
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v11; // rcx
  signed __int64 v12; // r14
  Scaleform::Render::Text::Paragraph *v13; // r14
  unsigned __int64 v14; // rbx
  Scaleform::Render::Text::ParagraphFormat *v15; // rdi
  int v16; // ecx
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  Scaleform::Render::Text::Paragraph *v20; // rax
  unsigned __int64 v21; // rbx
  wchar_t *v22; // r13
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rdx
  wchar_t *v25; // rax
  unsigned __int64 v26; // r8
  wchar_t *v27; // rax
  signed int v28; // eax
  char v29; // cl
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // rax
  wchar_t *v32; // rax
  unsigned __int8 v33; // al
  unsigned __int64 v34; // r15
  signed int v35; // eax
  unsigned __int64 v36; // rdi
  signed __int64 v37; // rbx
  __int64 v38; // rax
  unsigned __int64 result; // rax
  __int64 v40; // [rsp+30h] [rbp-58h]
  const wchar_t *v41; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Text::StyledText *v42; // [rsp+90h] [rbp+8h]
  int v43; // [rsp+98h] [rbp+10h]
  unsigned __int64 v44; // [rsp+A0h] [rbp+18h]
  Scaleform::Render::Text::StyledText::NewLinePolicy v45; // [rsp+A8h] [rbp+20h]

  v45 = newLinePolicy;
  v42 = this;
  v6 = 0;
  v7 = pstr;
  v8 = length;
  v9 = this;
  if ( length == -1i64 )
  {
    v8 = -1i64;
    do
      ++v8;
    while ( pstr[v8] );
  }
  v10 = this->Paragraphs.Data.Size;
  v11 = &this->Paragraphs;
  v12 = v10 - 1;
  v41 = &pstr[v8];
  if ( !v11 || v12 < 0 || v12 >= SLODWORD(v11->Data.Size) )
  {
    v13 = 0i64;
    goto LABEL_10;
  }
  v13 = v11->Data.Data[v12].pPara;
  if ( !v13 )
  {
LABEL_10:
    v14 = 0i64;
    goto LABEL_11;
  }
  v14 = v13->StartIndex;
LABEL_11:
  v44 = v14;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, const wchar_t *))v9->vfptr[2].__vecDelDtor)(
    v9,
    v14,
    v8,
    pstr);
  v15 = pdefParaFmt;
  v40 = 0i64;
  v16 = 0;
  while ( 1 )
  {
    v43 = v16 + 1;
    if ( v16 || !v13 )
    {
      v20 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v9, v15);
      v17 = 0i64;
      v20->StartIndex = v14;
      v13 = v20;
    }
    else
    {
      Scaleform::Render::Text::Paragraph::RemoveTermNull(v13);
      v17 = v13->Text.Size;
      if ( !v17 )
        goto LABEL_85;
      v18 = v17 - 1;
      if ( v13->Text.pText && v18 < v17 )
        v19 = &v13->Text.pText[v18];
      else
        v19 = 0i64;
      if ( !*v19 )
        --v17;
      if ( !v17 )
      {
LABEL_85:
        if ( v15 )
          Scaleform::Render::Text::Paragraph::SetFormat(v13, v9->pTextAllocator.pObject, v15);
      }
    }
    v21 = 0i64;
    if ( v45 == NLP_CompressCRLF && v6 == 13 && *v7 == 10 )
    {
      ++v7;
      if ( !--v8 )
        break;
    }
    if ( v8 )
    {
      while ( 1 )
      {
        v6 = v7[v21];
        if ( v6 == 10 )
          break;
        if ( v6 != 13 )
        {
          if ( v7[v21] )
          {
            if ( ++v21 < v8 )
              continue;
          }
        }
        goto LABEL_34;
      }
    }
    else
    {
LABEL_34:
      if ( v6 != 10 && v6 != 13 )
        goto LABEL_37;
    }
    ++v21;
LABEL_37:
    if ( v21 )
    {
      v23 = v13->Text.Size;
      v24 = v23 + v21;
      if ( v13->Text.Allocated < v23 + v21 )
      {
        if ( v13->Text.pText )
          v25 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                             Scaleform::Memory::pGlobalHeap,
                             v13->Text.pText,
                             2 * v24);
        else
          v25 = (wchar_t *)v9->pTextAllocator.pObject->pHeap->vfptr->Alloc(
                             v9->pTextAllocator.pObject->pHeap,
                             2 * v24,
                             0i64);
        v23 = v13->Text.Size;
        v13->Text.pText = v25;
        v13->Text.Allocated = v23 + v21;
      }
      v26 = v23 - v17;
      if ( v26 )
        memmove(&v13->Text.pText[v21 + v17], &v13->Text.pText[v17], 2 * v26);
      v27 = v13->Text.pText;
      v13->Text.Size += v21;
      v22 = &v27[v17];
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &v13->FormatInfo,
        v17,
        v21);
      ++v13->ModCounter;
    }
    else
    {
      v22 = 0i64;
    }
    memmove(v22, v7, 2 * v21);
    v7 += v21;
    v8 -= v21;
    if ( v6 != 10 && v6 != 13 )
    {
      v9 = v42;
    }
    else
    {
      v9 = v42;
      v28 = 10;
      v29 = ((unsigned __int8)v42->RTFlags >> 1) & 1;
      if ( v29 )
        v28 = 13;
      if ( v6 != v28 )
      {
        v30 = v13->Text.Size;
        if ( v30 )
        {
          v31 = v30 - 1;
          if ( v13->Text.pText && v31 < v30 )
            v32 = &v13->Text.pText[v31];
          else
            v32 = 0i64;
          if ( !*v32 )
            --v30;
          if ( v30 )
          {
            v33 = 10;
            if ( v29 )
              v33 = 13;
            v13->Text.pText[v30 - 1] = v33;
          }
        }
        v6 = 10;
        if ( v42->RTFlags & 2 )
          v6 = 13;
      }
    }
    Scaleform::Render::Text::Paragraph::SetTextFormat(
      v13,
      v9->pTextAllocator.pObject,
      pdefTextFmt,
      v17,
      0xFFFFFFFFFFFFFFFFui64);
    v44 += v21 + v17;
    v34 = v21 + v40;
    v40 += v21;
    if ( v7 < v41 )
    {
      v15 = pdefParaFmt;
      v16 = v43;
      v14 = v44;
      if ( v6 )
        continue;
    }
    v15 = pdefParaFmt;
    goto LABEL_71;
  }
  v34 = v40;
LABEL_71:
  v35 = 10;
  if ( v9->RTFlags & 2 )
    v35 = 13;
  if ( v6 == v35 )
    v13 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v9, v15);
  Scaleform::Render::Text::Paragraph::AppendTermNull(v13, v9->pTextAllocator.pObject, pdefTextFmt);
  if ( !(pdefTextFmt->PresentMask & 0x100) )
    return v34;
  v36 = pdefTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v37 = *(_QWORD *)v36 & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(_QWORD *)v36 >= 0i64 )
  {
    v38 = Scaleform::UTF8Util::GetLength((const char *)(v36 + 12), *(_QWORD *)v36 & 0x7FFFFFFFFFFFFFFFi64);
    if ( v38 == v37 )
      *(_QWORD *)v36 |= 0x8000000000000000ui64;
    v37 = v38;
  }
  result = v34;
  if ( v37 )
    v9->RTFlags |= 1u;
  return result;
}

// File Line: 1236
// RVA: 0x98A2A0
Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *__fastcall Scaleform::Render::Text::StyledText::GetParagraphByIndex(Scaleform::Render::Text::StyledText *this, Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *result, unsigned __int64 index, unsigned __int64 *pindexInParagraph)
{
  signed __int64 v4; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  unsigned __int64 v6; // rbx
  unsigned __int64 *v7; // r15
  unsigned __int64 v8; // r11
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *v9; // rdi
  unsigned __int64 v10; // r9
  Scaleform::Render::Text::Paragraph *v11; // rax
  unsigned __int64 v12; // r8
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // rdx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *v15; // rax

  v4 = this->Paragraphs.Data.Size;
  v5 = &this->Paragraphs;
  v6 = 0i64;
  v7 = pindexInParagraph;
  v8 = index;
  v9 = result;
  while ( v4 > 0 )
  {
    v10 = (v4 >> 1) + v6;
    v11 = v5->Data.Data[v10].pPara;
    v12 = v11->StartIndex;
    if ( v8 >= v12 && v8 < v12 + v11->Text.Size || (signed int)v12 - (signed int)v8 >= 0 )
    {
      v4 >>= 1;
    }
    else
    {
      v6 = v10 + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  if ( v6 >= this->Paragraphs.Data.Size
    || ((v13 = v5->Data.Data[v6].pPara, v14 = v13->StartIndex, v8 < v14) || v8 >= v14 + v13->Text.Size)
    && (_DWORD)v14 != (_DWORD)v8 )
  {
    v9->pArray = 0i64;
    v9->CurIndex = -1i64;
    v15 = v9;
  }
  else
  {
    if ( v7 )
      *v7 = v8 - v5->Data.Data[(signed int)v6].pPara->StartIndex;
    v9->pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)&v5->Data;
    v15 = v9;
    v9->CurIndex = (signed int)v6;
  }
  return v15;
}

// File Line: 1266
// RVA: 0x970DA0
void __fastcall Scaleform::Render::Text::StyledText::EnsureTermNull(Scaleform::Render::Text::StyledText *this)
{
  Scaleform::Render::Text::StyledText *v1; // rbx
  signed __int64 v2; // rdx
  Scaleform::Render::Text::Paragraph *v3; // rax
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rdx
  wchar_t *v6; // rcx
  wchar_t v7; // cx

  v1 = this;
  v2 = this->Paragraphs.Data.Size - 1;
  if ( this != (Scaleform::Render::Text::StyledText *)-24i64
    && v2 >= 0
    && v2 < SLODWORD(this->Paragraphs.Data.Size)
    && (v3 = this->Paragraphs.Data.Data[v2].pPara) != 0i64
    || (v3 = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0i64)) != 0i64 )
  {
    v4 = v3->Text.Size;
    if ( !v4
      || ((v5 = v4 - 1, !v3->Text.pText) || v5 >= v4 ? (v6 = 0i64) : (v6 = &v3->Text.pText[v5]),
          (v7 = *v6, v7 != 10) && v7 != 13) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(v3, v1->pTextAllocator.pObject, v1->pDefaultTextFormat.pObject);
    }
  }
}

// File Line: 1277
// RVA: 0x9B4A30
void __fastcall Scaleform::Render::Text::StyledText::SetTextFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::TextFormat *fmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  signed __int64 v4; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v5; // r15
  unsigned __int64 v6; // rbx
  signed __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r11
  Scaleform::Render::Text::TextFormat *v10; // r12
  Scaleform::Render::Text::StyledText *v11; // r13
  unsigned __int64 v12; // r9
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // r8
  Scaleform::Render::Text::Paragraph *v15; // rax
  unsigned __int64 v16; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v17; // rax
  Scaleform::Render::Text::Paragraph *v18; // rcx
  unsigned __int64 v19; // rbp
  _QWORD *v20; // r14
  unsigned __int64 v21; // rsi
  _QWORD *v22; // r10
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rdx
  _WORD *v26; // rdx
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // rax
  _WORD *v29; // rax
  __m128i v30; // [rsp+30h] [rbp-38h]
  unsigned __int64 v31; // [rsp+70h] [rbp+8h]

  v4 = this->Paragraphs.Data.Size;
  v5 = &this->Paragraphs;
  v6 = 0i64;
  v7 = -1i64;
  v8 = endPos;
  v9 = startPos;
  v10 = fmt;
  v11 = this;
  while ( v4 > 0 )
  {
    v12 = (v4 >> 1) + v6;
    v13 = v5->Data.Data[v12].pPara;
    v14 = v13->StartIndex;
    if ( v9 >= v14 && v9 < v14 + v13->Text.Size || (signed int)v14 - (signed int)v9 >= 0 )
    {
      v4 >>= 1;
    }
    else
    {
      v6 = v12 + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  if ( v6 >= this->Paragraphs.Data.Size
    || ((v15 = v5->Data.Data[v6].pPara, v16 = v15->StartIndex, v9 < v16) || v9 >= v16 + v15->Text.Size)
    && (_DWORD)v16 != (_DWORD)v9 )
  {
    v19 = v31;
    v20 = 0i64;
  }
  else
  {
    v17 = v5->Data.Data;
    v30.m128i_i64[0] = (__int64)&this->Paragraphs;
    v30.m128i_i64[1] = (signed int)v6;
    v18 = v17[(signed int)v6].pPara;
    _mm_store_si128(&v30, v30);
    v19 = v9 - v18->StartIndex;
    v7 = v30.m128i_i64[1];
    v20 = (_QWORD *)v30.m128i_i64[0];
  }
  v21 = v8 - v9;
  while ( v20 && v7 >= 0 && v7 < *((signed int *)v20 + 2) )
  {
    v22 = *(_QWORD **)(*v20 + 8 * v7);
    v23 = v22[1];
    v24 = v23;
    if ( v23 )
    {
      v25 = v23 - 1;
      if ( *v22 && v25 < v23 )
        v26 = (_WORD *)(*v22 + 2 * v25);
      else
        v26 = 0i64;
      if ( !*v26 )
        v24 = v23 - 1;
    }
    v27 = v21 + v19;
    if ( v21 + v19 <= v24 )
    {
      if ( v21 + v19 != v24 )
        goto LABEL_36;
    }
    else
    {
      v27 = v24;
    }
    if ( v23 )
    {
      v28 = v23 - 1;
      if ( *v22 && v28 < v23 )
        v29 = (_WORD *)(*v22 + 2 * v28);
      else
        v29 = 0i64;
      if ( !*v29 )
      {
        ++v27;
        if ( v21 != -1i64 )
          ++v21;
      }
    }
LABEL_36:
    Scaleform::Render::Text::Paragraph::SetTextFormat(
      *(Scaleform::Render::Text::Paragraph **)(*v20 + 8 * v7),
      v11->pTextAllocator.pObject,
      v10,
      v19,
      v27);
    v21 += v19 - v27;
    v19 = 0i64;
    if ( v7 < v20[1] )
      ++v7;
  }
  if ( v10->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v10->Url.0) )
    v11->RTFlags |= 1u;
}

// File Line: 1312
// RVA: 0x9B2570
void __fastcall Scaleform::Render::Text::StyledText::SetParagraphFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::ParagraphFormat *fmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  signed __int64 v4; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v5; // r14
  unsigned __int64 v6; // rdi
  signed __int64 v7; // rbx
  unsigned __int64 v8; // r15
  Scaleform::Render::Text::ParagraphFormat *v9; // r12
  unsigned __int64 v10; // r9
  Scaleform::Render::Text::StyledText *v11; // rbp
  unsigned __int64 v12; // r11
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // r8
  Scaleform::Render::Text::Paragraph *v15; // rax
  unsigned __int64 v16; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v17; // rax
  Scaleform::Render::Text::Paragraph *v18; // rcx
  unsigned __int64 v19; // rdi
  _QWORD *v20; // r14
  unsigned __int64 v21; // r15
  _QWORD *v22; // rsi
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rcx
  _WORD *v25; // rcx
  __m128i v26; // [rsp+20h] [rbp-38h]
  unsigned __int64 v27; // [rsp+60h] [rbp+8h]

  v4 = this->Paragraphs.Data.Size;
  v5 = &this->Paragraphs;
  v6 = 0i64;
  v7 = -1i64;
  v8 = endPos;
  v9 = fmt;
  v10 = startPos;
  v11 = this;
  while ( v4 > 0 )
  {
    v12 = (v4 >> 1) + v6;
    v13 = v5->Data.Data[v12].pPara;
    v14 = v13->StartIndex;
    if ( v10 >= v14 && v10 < v14 + v13->Text.Size || (signed int)v14 - (signed int)v10 >= 0 )
    {
      v4 >>= 1;
    }
    else
    {
      v6 = v12 + 1;
      v4 += -1 - (v4 >> 1);
    }
  }
  if ( v6 >= this->Paragraphs.Data.Size
    || ((v15 = v5->Data.Data[v6].pPara, v16 = v15->StartIndex, v10 < v16) || v10 >= v16 + v15->Text.Size)
    && (_DWORD)v16 != (_DWORD)v10 )
  {
    v19 = v27;
    v20 = 0i64;
  }
  else
  {
    v17 = v5->Data.Data;
    v26.m128i_i64[0] = (__int64)&this->Paragraphs;
    v26.m128i_i64[1] = (signed int)v6;
    v18 = v17[(signed int)v6].pPara;
    _mm_store_si128(&v26, v26);
    v19 = v10 - v18->StartIndex;
    v7 = v26.m128i_i64[1];
    v20 = (_QWORD *)v26.m128i_i64[0];
  }
  v21 = v8 - v10;
  while ( v20 && v7 >= 0 && v7 < *((signed int *)v20 + 2) )
  {
    v22 = *(_QWORD **)(*v20 + 8 * v7);
    if ( !v19 )
      Scaleform::Render::Text::Paragraph::SetFormat(
        *(Scaleform::Render::Text::Paragraph **)(*v20 + 8 * v7),
        v11->pTextAllocator.pObject,
        v9);
    if ( !v21 )
      break;
    v23 = v22[1];
    if ( v23 )
    {
      v24 = v23 - 1;
      if ( *v22 && v24 < v23 )
        v25 = (_WORD *)(*v22 + 2 * v24);
      else
        v25 = 0i64;
      if ( !*v25 )
        --v23;
    }
    if ( v21 <= v23 )
      v23 = v21 + v19;
    v21 += v19 - v23;
    v19 = 0i64;
    if ( v7 < v20[1] )
      ++v7;
  }
}

// File Line: 1375
// RVA: 0x98CAA0
void __fastcall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::TextFormat *pdestTextFmt, Scaleform::Render::Text::ParagraphFormat *pdestParaFmt, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v5; // r12
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  signed __int64 v7; // r10
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r11
  Scaleform::Render::Text::Paragraph *v10; // rax
  unsigned __int64 v11; // r8
  Scaleform::Render::Text::Paragraph *v12; // rax
  unsigned __int64 v13; // rdx
  signed __int64 v14; // r15
  Scaleform::Render::Text::ParagraphFormat *v15; // r13
  Scaleform::MemoryHeap *v16; // rax
  Scaleform::MemoryHeap *v17; // rdx
  Scaleform::MemoryHeap *v18; // rcx
  Scaleform::MemoryHeap *v19; // rax
  int v20; // ecx
  int v21; // esi
  unsigned __int64 v22; // r14
  Scaleform::Render::Text::Paragraph *v23; // rdi
  unsigned __int64 v24; // rbx
  unsigned __int64 v25; // rax
  wchar_t *v26; // rax
  unsigned __int64 v27; // r9
  Scaleform::Render::Text::TextFormat *v28; // rax
  Scaleform::Render::Text::FontHandle *v29; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v30; // rcx
  Scaleform::String::DataDesc *v31; // rdx
  Scaleform::Render::Text::TextFormat *v32; // rax
  Scaleform::Render::Text::TextFormat *v33; // rax
  Scaleform::Render::Text::FontHandle *v34; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v35; // rcx
  Scaleform::Render::Text::FontHandle *v36; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v37; // rcx
  Scaleform::Render::Text::ParagraphFormat *v38; // rcx
  unsigned int *v39; // rsi
  __int64 v40; // rdi
  unsigned int *v41; // r9
  Scaleform::Render::Text::ParagraphFormat *v42; // rax
  unsigned int *v43; // rsi
  __int64 v44; // rdi
  unsigned int *v45; // r9
  Scaleform::Render::Text::ParagraphFormat v46; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::Text::ParagraphFormat *v47[2]; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::Text::ParagraphFormat *v49; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::Text::TextFormat *key; // [rsp+B8h] [rbp-48h]
  Scaleform::Render::Text::TextFormat *v51; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Text::TextFormat *v52; // [rsp+C8h] [rbp-38h]
  __int64 v53; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Text::ParagraphFormat v54; // [rsp+D8h] [rbp-28h]
  Scaleform::Render::Text::TextFormat result; // [rsp+100h] [rbp+0h]
  Scaleform::Render::Text::TextFormat v56; // [rsp+150h] [rbp+50h]
  Scaleform::Render::Text::TextFormat v57; // [rsp+1A0h] [rbp+A0h]
  int v58; // [rsp+240h] [rbp+140h]
  Scaleform::Render::Text::TextFormat *v59; // [rsp+248h] [rbp+148h]
  Scaleform::Render::Text::ParagraphFormat *v60; // [rsp+250h] [rbp+150h]
  unsigned __int64 startPosa; // [rsp+258h] [rbp+158h]
  int endPosa; // [rsp+260h] [rbp+160h]

  v60 = pdestParaFmt;
  v59 = pdestTextFmt;
  v53 = -2i64;
  v5 = endPos - startPos;
  v6 = &this->Paragraphs;
  v7 = this->Paragraphs.Data.Size;
  v8 = 0i64;
  while ( v7 > 0 )
  {
    v9 = (v7 >> 1) + v8;
    v10 = v6->Data.Data[v9].pPara;
    v11 = v10->StartIndex;
    if ( startPos >= v11 && startPos < v11 + v10->Text.Size || (signed int)v11 - (signed int)startPos >= 0 )
    {
      v7 >>= 1;
    }
    else
    {
      v8 = v9 + 1;
      v7 += -1 - (v7 >> 1);
    }
  }
  if ( v8 >= this->Paragraphs.Data.Size
    || ((v12 = v6->Data.Data[v8].pPara, v13 = v12->StartIndex, startPos < v13) || startPos >= v13 + v12->Text.Size)
    && (_DWORD)v13 != (_DWORD)startPos )
  {
    v15 = 0i64;
    v14 = -1i64;
  }
  else
  {
    v47[0] = (Scaleform::Render::Text::ParagraphFormat *)&this->Paragraphs;
    v47[1] = (Scaleform::Render::Text::ParagraphFormat *)(signed int)v8;
    startPosa = startPos - v6->Data.Data[(signed int)v8].pPara->StartIndex;
    _mm_store_si128((__m128i *)v47, *(__m128i *)v47);
    v14 = (signed __int64)v47[1];
    v15 = v47[0];
  }
  v16 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v17 = v16;
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  v18 = Scaleform::Memory::pGlobalHeap;
  if ( v16 )
    v18 = v16;
  fmt.FontList.pHeap = v18;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v19 = Scaleform::Memory::pGlobalHeap;
  if ( v17 )
    v19 = v17;
  fmt.Url.pHeap = v19;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  fmt.pImageDesc.pObject = 0i64;
  fmt.pFontHandle.pObject = 0i64;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0.0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  v46.pAllocator = 0i64;
  v46.RefCount = 1;
  v46.pTabStops = 0i64;
  *(_QWORD *)&v46.BlockIndent = 0i64;
  *(_DWORD *)&v46.RightMargin = 0;
  v20 = 0;
  endPosa = 0;
  v21 = 0;
  if ( v5 )
  {
    v22 = startPosa;
    do
    {
      if ( !v15 || v14 < 0 || v14 >= (signed int)v15->RefCount )
        break;
      v23 = (Scaleform::Render::Text::Paragraph *)(&v15->pAllocator->vfptr)[v14];
      v24 = v23->Text.Size;
      if ( v24 )
      {
        v25 = v24 - 1;
        if ( v23->Text.pText && v25 < v24 )
          v26 = &v23->Text.pText[v25];
        else
          v26 = 0i64;
        v20 = endPosa;
        if ( !*v26 )
          --v24;
      }
      if ( v5 < v24 )
        v24 = v5;
      if ( !v24 )
        break;
      endPosa = v20 + 1;
      v27 = v24 + v22;
      if ( v20 )
      {
        v32 = Scaleform::Render::Text::Paragraph::GetTextFormat(v23, &v57, v22, v27);
        v33 = Scaleform::Render::Text::TextFormat::Intersection(v32, &v56, &fmt);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v33);
        if ( v56.pAllocator )
        {
          v52 = &v56;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v56.pAllocator->TextFormatStorage.pTable,
            &v52);
        }
        v34 = v56.pFontHandle.pObject;
        if ( v56.pFontHandle.pObject && !_InterlockedDecrement(&v56.pFontHandle.pObject->RefCount) && v34 )
          v34->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v34->vfptr, 1u);
        v35 = v56.pImageDesc.pObject;
        if ( v56.pImageDesc.pObject )
        {
          --v56.pImageDesc.pObject->RefCount;
          if ( !v35->RefCount )
            v35->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v35->vfptr, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v56.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v56.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( v57.pAllocator )
        {
          v51 = &v57;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v57.pAllocator->TextFormatStorage.pTable,
            &v51);
        }
        v36 = v57.pFontHandle.pObject;
        if ( v57.pFontHandle.pObject && !_InterlockedDecrement(&v57.pFontHandle.pObject->RefCount) && v36 )
          v36->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v36->vfptr, 1u);
        v37 = v57.pImageDesc.pObject;
        if ( v57.pImageDesc.pObject )
        {
          --v57.pImageDesc.pObject->RefCount;
          if ( !v37->RefCount )
            v37->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v37->vfptr, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v57.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v31 = v57.FontList.pData;
      }
      else
      {
        v28 = Scaleform::Render::Text::Paragraph::GetTextFormat(v23, &result, v22, v27);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v28);
        if ( result.pAllocator )
        {
          key = &result;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&result.pAllocator->TextFormatStorage.pTable,
            &key);
        }
        v29 = result.pFontHandle.pObject;
        if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v29 )
          v29->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v29->vfptr, 1u);
        v30 = result.pImageDesc.pObject;
        if ( result.pImageDesc.pObject )
        {
          --result.pImageDesc.pObject->RefCount;
          if ( !v30->RefCount )
            v30->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v30->vfptr, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((result.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v31 = result.FontList.pData;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v31 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v22 = startPosa;
      if ( !startPosa )
      {
        v38 = v23->pFormat.pObject;
        if ( v38 )
        {
          v58 = v21 + 1;
          if ( v21 )
          {
            v42 = Scaleform::Render::Text::ParagraphFormat::Intersection(v38, &v54, &v46);
            v46.BlockIndent = v42->BlockIndent;
            v46.Indent = v42->Indent;
            v46.Leading = v42->Leading;
            v46.LeftMargin = v42->LeftMargin;
            v46.RightMargin = v42->RightMargin;
            v46.PresentMask = v42->PresentMask;
            v43 = v42->pTabStops;
            if ( v43 )
            {
              v44 = *v43;
              v45 = v46.pTabStops;
              if ( !v46.pTabStops || *v46.pTabStops != (_DWORD)v44 )
              {
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
                v46.pTabStops = 0i64;
                v46.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  4i64 * (unsigned int)(v44 + 1),
                                                  0i64);
                *v46.pTabStops = v44;
                v45 = v46.pTabStops;
              }
              memmove(v45 + 1, v43 + 1, 4 * v44);
            }
            else
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
              v46.pTabStops = 0i64;
            }
            if ( v54.pAllocator )
            {
              v49 = &v54;
              Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
                (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v54.pAllocator->ParagraphFormatStorage.pTable,
                &v49);
            }
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v54.pTabStops);
            v54.pTabStops = 0i64;
            v21 = v58;
          }
          else
          {
            v46.BlockIndent = v38->BlockIndent;
            v46.Indent = v38->Indent;
            v46.Leading = v38->Leading;
            v46.LeftMargin = v38->LeftMargin;
            v46.RightMargin = v38->RightMargin;
            v46.PresentMask = v38->PresentMask;
            v39 = v38->pTabStops;
            if ( v39 )
            {
              v40 = *v39;
              v41 = v46.pTabStops;
              if ( !v46.pTabStops || *v46.pTabStops != (_DWORD)v40 )
              {
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
                v46.pTabStops = 0i64;
                v46.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  4i64 * (unsigned int)(v40 + 1),
                                                  0i64);
                *v46.pTabStops = v40;
                v41 = v46.pTabStops;
              }
              memmove(v41 + 1, v39 + 1, 4 * v40);
              v21 = v58;
            }
            else
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
              v46.pTabStops = 0i64;
              v21 = v58;
            }
          }
        }
      }
      v5 -= v24;
      if ( v14 < *(_QWORD *)&v15->RefCount )
        ++v14;
      v20 = endPosa;
    }
    while ( v5 );
  }
  if ( v59 )
    Scaleform::Render::Text::TextFormat::operator=(v59, &fmt);
  if ( v60 )
  {
    v60->BlockIndent = v46.BlockIndent;
    v60->Indent = v46.Indent;
    v60->Leading = v46.Leading;
    v60->LeftMargin = v46.LeftMargin;
    v60->RightMargin = v46.RightMargin;
    v60->PresentMask = v46.PresentMask;
    Scaleform::Render::Text::ParagraphFormat::CopyTabStops(v60, v46.pTabStops);
  }
  if ( v46.pAllocator )
  {
    v47[0] = &v46;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v46.pAllocator->ParagraphFormatStorage.pTable,
      v47);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
  v46.pTabStops = 0i64;
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 1421
// RVA: 0x98D250
__int64 __fastcall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::TextFormat **ppdestTextFmt, Scaleform::Render::Text::ParagraphFormat **ppdestParaFmt, unsigned __int64 pos)
{
  Scaleform::Render::Text::ParagraphFormat *v4; // rsi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v5; // r15
  unsigned __int64 v6; // r10
  signed __int64 v7; // rdi
  signed __int64 v8; // r9
  Scaleform::Render::Text::ParagraphFormat **v9; // r12
  Scaleform::Render::Text::TextFormat **v10; // r13
  Scaleform::Render::Text::StyledText *v11; // rbp
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r11
  Scaleform::Render::Text::Paragraph *v14; // rax
  unsigned __int64 v15; // r8
  Scaleform::Render::Text::Paragraph *v16; // rax
  unsigned __int64 v17; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v18; // rax
  unsigned __int64 v19; // r10
  __int64 v20; // rdx
  unsigned __int8 v21; // cl
  __int64 v22; // rbx
  Scaleform::Render::Text::TextFormat *v23; // rax
  __int64 result; // rax
  __m128i v25; // [rsp+20h] [rbp-38h]
  unsigned __int64 v26; // [rsp+60h] [rbp+8h]

  v4 = 0i64;
  v5 = &this->Paragraphs;
  v6 = pos;
  v7 = -1i64;
  v8 = this->Paragraphs.Data.Size;
  v9 = ppdestParaFmt;
  v10 = ppdestTextFmt;
  v11 = this;
  v12 = 0i64;
  while ( v8 > 0 )
  {
    v13 = (v8 >> 1) + v12;
    v14 = v5->Data.Data[v13].pPara;
    v15 = v14->StartIndex;
    if ( v6 >= v15 && v6 < v15 + v14->Text.Size || (signed int)v15 - (signed int)v6 >= 0 )
    {
      v8 >>= 1;
    }
    else
    {
      v12 = v13 + 1;
      v8 += -1 - (v8 >> 1);
    }
  }
  if ( v12 >= this->Paragraphs.Data.Size
    || ((v16 = v5->Data.Data[v12].pPara, v17 = v16->StartIndex, v6 < v17) || v6 >= v17 + v16->Text.Size)
    && (_DWORD)v17 != (_DWORD)v6 )
  {
    v19 = v26;
    v20 = 0i64;
  }
  else
  {
    v18 = v5->Data.Data;
    v25.m128i_i64[0] = (__int64)&this->Paragraphs;
    v25.m128i_i64[1] = (signed int)v12;
    v19 = v6 - v18[(signed int)v12].pPara->StartIndex;
    _mm_store_si128(&v25, v25);
    v7 = v25.m128i_i64[1];
    v20 = v25.m128i_i64[0];
  }
  v21 = 0;
  if ( !v20
    || v7 < 0
    || v7 >= *(signed int *)(v20 + 8)
    || (v22 = *(_QWORD *)(*(_QWORD *)v20 + 8 * v7),
        v23 = Scaleform::Render::Text::Paragraph::GetTextFormatPtr(
                *(Scaleform::Render::Text::Paragraph **)(*(_QWORD *)v20 + 8 * v7),
                v19),
        v4 = *(Scaleform::Render::Text::ParagraphFormat **)(v22 + 24),
        v21 = 1,
        !v23) )
  {
    v23 = v11->pDefaultTextFormat.pObject;
  }
  if ( !v4 )
    v4 = v11->pDefaultParagraphFormat.pObject;
  if ( v10 )
    *v10 = v23;
  result = v21;
  if ( v9 )
    *v9 = v4;
  return result;
}

// File Line: 1449
// RVA: 0x9AF040
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::TextFormat *defaultTextFmt)
{
  Scaleform::Render::Text::TextFormat *v2; // rdi
  Scaleform::Render::Text::StyledText *v3; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v4; // rcx
  Scaleform::Render::Text::Allocator *v5; // rax
  Scaleform::Render::Text::TextFormat *v6; // rsi
  Scaleform::Render::Text::TextFormat *v7; // rdi
  bool v8; // zf
  Scaleform::Render::Text::Allocator *v9; // rax
  Scaleform::Render::Text::TextFormat *v10; // rsi
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-58h]

  v2 = defaultTextFmt;
  v3 = this;
  if ( Scaleform::Render::Text::TextFormat::GetImageDesc(defaultTextFmt) )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(&srcfmt, v2, 0i64);
    v4 = srcfmt.pImageDesc.pObject;
    if ( srcfmt.pImageDesc.pObject )
    {
      --srcfmt.pImageDesc.pObject->RefCount;
      if ( !v4->RefCount )
        v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
    }
    srcfmt.pImageDesc.pObject = 0i64;
    srcfmt.PresentMask |= 0x200u;
    v5 = Scaleform::Render::Text::StyledText::GetAllocator(v3);
    v6 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v5, &srcfmt);
    v7 = v3->pDefaultTextFormat.pObject;
    if ( v7 )
    {
      v8 = v7->RefCount-- == 1;
      if ( v8 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v7);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
    }
    v3->pDefaultTextFormat.pObject = v6;
    Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  }
  else
  {
    v9 = Scaleform::Render::Text::StyledText::GetAllocator(v3);
    v10 = Scaleform::Render::Text::Allocator::AllocateTextFormat(v9, v2);
    v11 = v3->pDefaultTextFormat.pObject;
    if ( v11 )
    {
      v8 = v11->RefCount-- == 1;
      if ( v8 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v11);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
    }
    v3->pDefaultTextFormat.pObject = v10;
  }
}

// File Line: 1462
// RVA: 0x9AEDD0
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::ParagraphFormat *defaultParagraphFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx
  Scaleform::Render::Text::StyledText *v3; // rdi
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::ParagraphFormat *v5; // rax
  Scaleform::Render::Text::ParagraphFormat *v6; // rcx
  Scaleform::Render::Text::ParagraphFormat *v7; // rbx

  v2 = defaultParagraphFmt;
  v3 = this;
  v4 = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v5 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v4, v2);
  v6 = v3->pDefaultParagraphFormat.pObject;
  v7 = v5;
  if ( v6 )
  {
    Scaleform::Render::Text::ParagraphFormat::Release(v6);
    v3->pDefaultParagraphFormat.pObject = v7;
  }
  else
  {
    v3->pDefaultParagraphFormat.pObject = v5;
  }
}

// File Line: 1468
// RVA: 0x9AF160
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::TextFormat *pdefaultTextFmt)
{
  Scaleform::Render::Text::StyledText *v2; // rsi
  Scaleform::Render::Text::TextFormat *v3; // rbx
  Scaleform::Render::Text::TextFormat *v4; // rdi
  bool v5; // zf

  v2 = this;
  v3 = pdefaultTextFmt;
  if ( Scaleform::Render::Text::TextFormat::GetImageDesc(pdefaultTextFmt) )
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v2, v3);
  }
  else
  {
    if ( v3 )
      ++v3->RefCount;
    v4 = v2->pDefaultTextFormat.pObject;
    if ( v4 )
    {
      v5 = v4->RefCount-- == 1;
      if ( v5 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v4);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
    }
    v2->pDefaultTextFormat.pObject = v3;
  }
}

// File Line: 1481
// RVA: 0x9AEE20
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::ParagraphFormat *pdefaultParagraphFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx
  Scaleform::Render::Text::StyledText *v3; // rdi
  Scaleform::Render::Text::ParagraphFormat *v4; // rcx

  v2 = pdefaultParagraphFmt;
  v3 = this;
  if ( pdefaultParagraphFmt )
    ++pdefaultParagraphFmt->RefCount;
  v4 = this->pDefaultParagraphFormat.pObject;
  if ( v4 )
  {
    Scaleform::Render::Text::ParagraphFormat::Release(v4);
    v3->pDefaultParagraphFormat.pObject = v2;
  }
  else
  {
    v3->pDefaultParagraphFormat.pObject = pdefaultParagraphFmt;
  }
}

// File Line: 1487
// RVA: 0x985480
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetHtml(Scaleform::Render::Text::StyledText *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx
  Scaleform::StringBuffer *v3; // rax
  __int128 v5; // [rsp+30h] [rbp-38h]
  __int64 v6; // [rsp+40h] [rbp-28h]
  __int64 v7; // [rsp+48h] [rbp-20h]
  char v8; // [rsp+50h] [rbp-18h]
  Scaleform::MemoryHeap *v9; // [rsp+58h] [rbp-10h]

  v2 = result;
  v5 = 0ui64;
  v6 = 0i64;
  v7 = 512i64;
  v8 = 0;
  v9 = Scaleform::Memory::pGlobalHeap;
  v3 = Scaleform::Render::Text::StyledText::GetHtml(this, (Scaleform::StringBuffer *)&v5);
  Scaleform::String::String(v2, v3);
  if ( (_QWORD)v5 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v5);
  return v2;
}

// File Line: 1501
// RVA: 0x985500
Scaleform::Render::Text::StyledText::GetHtml

// File Line: 1692
// RVA: 0x988430
__int64 __fastcall Scaleform::Render::Text::StyledText::GetLength(Scaleform::Render::Text::StyledText *this)
{
  __int64 v1; // r9
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v2; // rdx
  signed __int64 v3; // rcx
  Scaleform::Render::Text::Paragraph *v4; // r10
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8
  wchar_t *v7; // r8

  v1 = 0i64;
  v2 = &this->Paragraphs;
  v3 = 0i64;
  while ( v2 && v3 >= 0 && v3 < SLODWORD(v2->Data.Size) )
  {
    v4 = v2->Data.Data[v3].pPara;
    v5 = v4->Text.Size;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v4->Text.pText && v6 < v5 )
        v7 = &v4->Text.pText[v6];
      else
        v7 = 0i64;
      if ( !*v7 )
        --v5;
    }
    v1 += v5;
    if ( v3 < (signed __int64)v2->Data.Size )
      ++v3;
  }
  return v1;
}

// File Line: 1705
// RVA: 0x98C6A0
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetText(Scaleform::Render::Text::StyledText *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  result->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  Scaleform::Render::Text::StyledText::GetText(this, result);
  return v2;
}

// File Line: 1712
// RVA: 0x98C6F0
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetText(Scaleform::Render::Text::StyledText *this, Scaleform::String *retStr)
{
  Scaleform::String *v2; // rsi
  Scaleform::Render::Text::StyledText *v3; // rdi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v4; // rdi
  signed __int64 v5; // rbx
  Scaleform::Render::Text::Paragraph *v6; // rcx
  unsigned __int64 v7; // r8
  const wchar_t *v8; // rdx
  unsigned __int64 v9; // rax
  const wchar_t *v10; // rax

  v2 = retStr;
  v3 = this;
  Scaleform::String::AssignString(retStr, &customWorldMapCaption, 0i64);
  v4 = &v3->Paragraphs;
  v5 = 0i64;
  while ( v4 && v5 >= 0 && v5 < SLODWORD(v4->Data.Size) )
  {
    v6 = v4->Data.Data[v5].pPara;
    v7 = v6->Text.Size;
    v8 = v6->Text.pText;
    if ( v7 )
    {
      v9 = v7 - 1;
      if ( v8 && v9 < v7 )
        v10 = &v8[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --v7;
    }
    Scaleform::String::AppendString(v2, v8, v7);
    if ( v5 < (signed __int64)v4->Data.Size )
      ++v5;
  }
  return v2;
}

// File Line: 1727
// RVA: 0x98C790
void __fastcall Scaleform::Render::Text::StyledText::GetText(Scaleform::Render::Text::StyledText *this, Scaleform::WStringBuffer *pBuffer)
{
  Scaleform::WStringBuffer *v2; // r14
  Scaleform::Render::Text::StyledText *v3; // rsi
  __int64 v4; // rax
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  signed __int64 v6; // rdi
  __int64 v7; // rbp
  Scaleform::Render::Text::Paragraph *v8; // rbx
  wchar_t *v9; // rdx
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rax
  bool v12; // cf
  char *v13; // rax

  v2 = pBuffer;
  v3 = this;
  v4 = Scaleform::Render::Text::StyledText::GetLength(this);
  Scaleform::WStringBuffer::Resize(v2, v4 + 1);
  v5 = &v3->Paragraphs;
  v6 = 0i64;
  v7 = 0i64;
  while ( v5 && v6 >= 0 && v6 < SLODWORD(v5->Data.Size) )
  {
    v8 = v5->Data.Data[v6].pPara;
    v9 = v8->Text.pText;
    v10 = v8->Text.Size;
    if ( v10 )
    {
      v11 = v10 - 1;
      if ( !v9 || (v12 = v11 < v10, v13 = (char *)&v9[v11], !v12) )
        v13 = 0i64;
      if ( !*(_WORD *)v13 )
        --v10;
    }
    memmove(&v2->pText[v7], v9, 2 * v10);
    v7 += v10;
    if ( v6 < (signed __int64)v5->Data.Size )
      ++v6;
  }
  v2->pText[v7] = 0;
}

// File Line: 1747
// RVA: 0x98C860
void __fastcall Scaleform::Render::Text::StyledText::GetText(Scaleform::Render::Text::StyledText *this, Scaleform::WStringBuffer *pBuffer, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  Scaleform::WStringBuffer *v6; // r13
  Scaleform::Render::Text::StyledText *v7; // r14
  unsigned __int64 v8; // rbp
  signed __int64 v9; // rdx
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v10; // rsi
  signed __int64 v11; // rdi
  unsigned __int64 v12; // r12
  unsigned __int64 v13; // r11
  unsigned __int64 v14; // r10
  Scaleform::Render::Text::Paragraph *v15; // rax
  unsigned __int64 v16; // r9
  Scaleform::Render::Text::Paragraph *v17; // rax
  unsigned __int64 v18; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v19; // rax
  Scaleform::Render::Text::Paragraph *v20; // rcx
  _QWORD *v21; // rsi
  __int64 v22; // r14
  _QWORD *v23; // rdx
  unsigned __int64 v24; // rbx
  unsigned __int64 v25; // rax
  bool v26; // cf
  _WORD *v27; // rax
  unsigned __int64 v28; // rbx
  const void *v29; // rdx
  __m128i v30; // [rsp+20h] [rbp-38h]

  v4 = endPos;
  v5 = startPos;
  v6 = pBuffer;
  v7 = this;
  if ( endPos == -1i64 )
    v4 = Scaleform::Render::Text::StyledText::GetLength(this);
  v8 = v4 - v5;
  Scaleform::WStringBuffer::Resize(v6, v8 + 1);
  v9 = v7->Paragraphs.Data.Size;
  v10 = &v7->Paragraphs;
  v11 = -1i64;
  v12 = 0i64;
  v13 = 0i64;
  while ( v9 > 0 )
  {
    v14 = (v9 >> 1) + v13;
    v15 = v10->Data.Data[v14].pPara;
    v16 = v15->StartIndex;
    if ( v5 >= v16 && v5 < v16 + v15->Text.Size || (signed int)v16 - (signed int)v5 >= 0 )
    {
      v9 >>= 1;
    }
    else
    {
      v13 = v14 + 1;
      v9 += -1 - (v9 >> 1);
    }
  }
  if ( v13 >= v7->Paragraphs.Data.Size
    || ((v17 = v10->Data.Data[v13].pPara, v18 = v17->StartIndex, v5 < v18) || v5 >= v18 + v17->Text.Size)
    && (_DWORD)v18 != (_DWORD)v5 )
  {
    v21 = 0i64;
  }
  else
  {
    v19 = v10->Data.Data;
    v30.m128i_i64[0] = (__int64)&v7->Paragraphs;
    v30.m128i_i64[1] = (signed int)v13;
    v20 = v19[(signed int)v13].pPara;
    _mm_store_si128(&v30, v30);
    v12 = v5 - v20->StartIndex;
    v11 = v30.m128i_i64[1];
    v21 = (_QWORD *)v30.m128i_i64[0];
  }
  v22 = 0i64;
  while ( v21 && v11 >= 0 && v11 < *((signed int *)v21 + 2) && v8 )
  {
    v23 = *(_QWORD **)(*v21 + 8 * v11);
    v24 = v23[1];
    if ( v24 )
    {
      v25 = v24 - 1;
      if ( !*v23 || (v26 = v25 < v24, v27 = (_WORD *)(*v23 + 2 * v25), !v26) )
        v27 = 0i64;
      if ( !*v27 )
        --v24;
    }
    v28 = v24 - v12;
    v29 = (const void *)(*v23 + 2 * v12);
    if ( v28 > v8 )
      v28 = v8;
    memmove(&v6->pText[v22], v29, 2 * v28);
    v22 += v28;
    v8 -= v28;
    v12 = 0i64;
    if ( v11 < v21[1] )
      ++v11;
  }
  v6->pText[v22] = 0;
}

// File Line: 1779
// RVA: 0x964DE0
Scaleform::Render::Text::StyledText *__fastcall Scaleform::Render::Text::StyledText::CopyStyledText(Scaleform::Render::Text::StyledText *this, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rbp
  Scaleform::Render::Text::StyledText *v5; // rdi
  Scaleform::Render::Text::Allocator *v6; // rax
  Scaleform::Render::Text::Allocator *v7; // rbx
  __int64 v8; // rcx
  Scaleform::Render::Text::StyledText *v9; // rax
  Scaleform::Render::Text::StyledText *v10; // rax
  Scaleform::Render::Text::StyledText *v11; // rbx

  v3 = endPos;
  v4 = startPos;
  v5 = this;
  v6 = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v7 = v6;
  v9 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(__int64, signed __int64))v6->pHeap->vfptr->Alloc)(
                                                v8,
                                                72i64);
  if ( v9 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v9, v7);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  Scaleform::Render::Text::StyledText::CopyStyledText(v5, v11, v4, v3);
  return v11;
}

// File Line: 1787
// RVA: 0x964E70
void __fastcall Scaleform::Render::Text::StyledText::CopyStyledText(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::StyledText *pdest, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::StyledText *v6; // r15
  Scaleform::Render::Text::StyledText *v7; // rbp
  unsigned __int64 v8; // rsi
  signed __int64 v9; // rdx
  wchar_t *v10; // r13
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v11; // r12
  unsigned __int64 v12; // r11
  unsigned __int64 v13; // r10
  Scaleform::Render::Text::Paragraph *v14; // rax
  unsigned __int64 v15; // r9
  Scaleform::Render::Text::Paragraph *v16; // rax
  unsigned __int64 v17; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v18; // rax
  signed __int64 v19; // rbp
  Scaleform::Render::Text::Paragraph *v20; // r14
  unsigned __int64 v21; // rdi
  Scaleform::Render::Text::Paragraph *v22; // rax
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rdx
  wchar_t *v25; // rax
  unsigned __int64 v26; // rcx
  unsigned __int64 v27; // rbx
  Scaleform::Render::Text::Allocator *v28; // rax
  signed __int64 v29; // rdi
  _QWORD *v30; // r14
  Scaleform::Render::Text::Paragraph *v31; // rdx
  unsigned __int64 v32; // rbx
  unsigned __int64 v33; // rax
  bool v34; // cf
  wchar_t *v35; // rax
  Scaleform::Render::Text::Paragraph *v36; // rdi
  Scaleform::Render::Text::Paragraph *v37; // rbx
  Scaleform::Render::Text::Allocator *v38; // rax
  signed __int64 v39; // rcx
  Scaleform::Render::Text::Paragraph *v40; // rdx
  unsigned __int64 v41; // rax
  unsigned __int64 v42; // rcx
  __m128i v43; // [rsp+30h] [rbp-48h]
  Scaleform::Render::Text::StyledText *v44; // [rsp+80h] [rbp+8h]
  Scaleform::Render::Text::Paragraph *v45; // [rsp+88h] [rbp+10h]

  v44 = this;
  v4 = endPos;
  v5 = startPos;
  v6 = pdest;
  v7 = this;
  if ( endPos == -1i64 )
    v4 = Scaleform::Render::Text::StyledText::GetLength(this);
  v8 = v4 - v5;
  Scaleform::Render::Text::StyledText::Clear(v6);
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))v6->vfptr[1].__vecDelDtor)(
    v6,
    v5,
    v8,
    &customWorldMapCaption);
  v9 = v7->Paragraphs.Data.Size;
  v10 = 0i64;
  v11 = &v7->Paragraphs;
  v12 = 0i64;
  while ( v9 > 0 )
  {
    v13 = (v9 >> 1) + v12;
    v14 = v11->Data.Data[v13].pPara;
    v15 = v14->StartIndex;
    if ( v5 >= v15 && v5 < v15 + v14->Text.Size || (signed int)v15 - (signed int)v5 >= 0 )
    {
      v9 >>= 1;
    }
    else
    {
      v12 = v13 + 1;
      v9 += -1 - (v9 >> 1);
    }
  }
  if ( v12 < v7->Paragraphs.Data.Size )
  {
    if ( (v16 = v11->Data.Data[v12].pPara, v17 = v16->StartIndex, v5 >= v17) && v5 < v17 + v16->Text.Size
      || (_DWORD)v17 == (_DWORD)v5 )
    {
      v18 = v11->Data.Data;
      v19 = (signed int)v12;
      v43.m128i_i64[0] = (__int64)v11;
      v43.m128i_i64[1] = (signed int)v12;
      v20 = v18[(signed int)v12].pPara;
      _mm_store_si128(&v43, v43);
      v21 = v5 - v20->StartIndex;
      if ( (v12 & 0x80000000) == 0i64 && (signed int)v12 < (signed __int64)SLODWORD(v11->Data.Size) )
      {
        if ( !v21 )
          goto LABEL_57;
        v22 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v6, v20->pFormat.pObject);
        v23 = v20->Text.Size;
        v45 = v22;
        if ( v23 )
        {
          v24 = v23 - 1;
          if ( !v20->Text.pText || (v25 = &v20->Text.pText[v24], v24 >= v23) )
            v25 = 0i64;
          if ( !*v25 )
            --v23;
        }
        v26 = v23 - v21;
        v27 = v8;
        if ( v26 < v8 )
          v27 = v26;
        v28 = Scaleform::Render::Text::StyledText::GetAllocator(v6);
        Scaleform::Render::Text::Paragraph::Copy(v45, v28, v20, v21);
        v8 -= v27;
        v29 = v19 + 1;
        if ( v19 >= (signed __int64)v11->Data.Size )
LABEL_57:
          v29 = v43.m128i_i64[1];
        v30 = (_QWORD *)v43.m128i_i64[0];
        while ( v29 >= 0 && v29 < *((signed int *)v30 + 2) && v8 )
        {
          v31 = *(Scaleform::Render::Text::Paragraph **)(*v30 + 8 * v29);
          v32 = v31->Text.Size;
          if ( v32 )
          {
            v33 = v32 - 1;
            if ( !v31->Text.pText || (v34 = v33 < v32, v35 = &v31->Text.pText[v33], !v34) )
              v35 = 0i64;
            if ( !*v35 )
              --v32;
          }
          if ( v32 > v8 )
          {
            v36 = *(Scaleform::Render::Text::Paragraph **)(*v30 + 8 * v29);
            v37 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v6, v36->pFormat.pObject);
            v38 = Scaleform::Render::Text::StyledText::GetAllocator(v6);
            Scaleform::Render::Text::Paragraph::Copy(v37, v38, v36, 0i64);
            break;
          }
          Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(v6, v31);
          v8 -= v32;
          if ( v29 < v30[1] )
            ++v29;
        }
      }
      v7 = v44;
    }
  }
  v39 = v6->Paragraphs.Data.Size - 1;
  if ( v6 != (Scaleform::Render::Text::StyledText *)-24i64 && v39 >= 0 && v39 < SLODWORD(v6->Paragraphs.Data.Size) )
  {
    v40 = v6->Paragraphs.Data.Data[v39].pPara;
    if ( v40 )
    {
      v41 = v40->Text.Size;
      if ( v41 )
      {
        v42 = v41 - 1;
        if ( v40->Text.pText && v42 < v41 )
          v10 = &v40->Text.pText[v42];
        if ( *v10 == 10 || *v10 == 13 )
          Scaleform::Render::Text::StyledText::AppendNewParagraph(v6, v40->pFormat.pObject);
      }
    }
  }
  Scaleform::Render::Text::StyledText::EnsureTermNull(v6);
  if ( v7->RTFlags & 1 )
    v6->RTFlags |= 1u;
}

// File Line: 1857
// RVA: 0x9959B0
__int64 __fastcall Scaleform::Render::Text::StyledText::InsertString(Scaleform::Render::Text::StyledText *this, const wchar_t *pstr, unsigned __int64 pos, unsigned __int64 length, Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy, Scaleform::Render::Text::TextFormat *pdefTextFmt, Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbx
  const wchar_t *v9; // rsi
  Scaleform::Render::Text::StyledText *v10; // r14
  wchar_t *v12; // r13
  Scaleform::Render::Text::StyledText *v13; // r11
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rbp
  signed __int64 v16; // r9
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v17; // r14
  signed __int64 v18; // r10
  signed __int64 v19; // r11
  Scaleform::Render::Text::Paragraph *v20; // rax
  unsigned __int64 v21; // r8
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v22; // rax
  Scaleform::Render::Text::Paragraph *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // r14
  Scaleform::Render::Text::ParagraphFormat *v26; // r9
  signed __int16 v27; // bp
  _QWORD *v28; // r15
  Scaleform::Render::Text::Paragraph *v29; // r12
  unsigned __int64 v30; // rax
  unsigned __int64 v31; // rcx
  bool v32; // cf
  wchar_t *v33; // rcx
  signed __int64 v34; // rax
  unsigned __int64 v35; // rbx
  Scaleform::Render::Text::Paragraph *v36; // rax
  Scaleform::Render::Text::ParagraphFormat *v37; // r13
  Scaleform::Render::Text::Paragraph *v38; // rcx
  Scaleform::Render::Text::ParagraphFormat *v39; // r15
  bool v40; // zf
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v41; // rcx
  unsigned __int64 v42; // ST28_8
  unsigned __int64 v43; // r15
  unsigned __int64 v44; // r15
  unsigned __int64 v45; // r8
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // r15
  unsigned __int64 v48; // r13
  unsigned __int64 v49; // r15
  wchar_t *v50; // rax
  unsigned __int64 v51; // rcx
  wchar_t *v52; // rcx
  unsigned __int64 v53; // rcx
  wchar_t *v54; // rcx
  unsigned __int64 v55; // r8
  unsigned __int8 v56; // al
  _QWORD *v57; // rdx
  __int64 v58; // rcx
  signed __int64 v59; // rcx
  Scaleform::Render::Text::Paragraph *v60; // rax
  unsigned __int64 v61; // rcx
  unsigned __int64 v62; // rdx
  unsigned __int64 v63; // rdi
  signed __int64 v64; // rbx
  __int64 v65; // rax
  unsigned __int64 v66; // [rsp+30h] [rbp-88h]
  __int64 v67; // [rsp+38h] [rbp-80h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+40h] [rbp-78h]
  Scaleform::Render::Text::Paragraph *v69; // [rsp+48h] [rbp-70h]
  __m128i v70; // [rsp+50h] [rbp-68h]
  __m128i v71; // [rsp+60h] [rbp-58h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator iter; // [rsp+70h] [rbp-48h]
  Scaleform::Render::Text::StyledText *v73; // [rsp+C0h] [rbp+8h]
  unsigned __int64 startSrcIndex; // [rsp+D8h] [rbp+20h]

  v73 = this;
  v7 = length;
  v8 = pos;
  v9 = pstr;
  v10 = this;
  if ( !length )
    return 0i64;
  if ( pos > Scaleform::Render::Text::StyledText::GetLength(this) )
    v8 = Scaleform::Render::Text::StyledText::GetLength(v10);
  v12 = 0i64;
  if ( v7 == -1i64 )
  {
    v7 = 0i64;
    if ( *v9 )
    {
      do
        ++v7;
      while ( v9[v7] );
    }
  }
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, const wchar_t *))v10->vfptr[2].__vecDelDtor)(
    v10,
    v8,
    v7,
    v9);
  v13 = v73;
  v14 = 0i64;
  v15 = v73->Paragraphs.Data.Size;
  startSrcIndex = 0i64;
  if ( !v15 )
  {
    v25 = -1i64;
    v70.m128i_i64[0] = 0i64;
    v70.m128i_i64[1] = -1i64;
    goto LABEL_24;
  }
  v16 = v73->Paragraphs.Data.Size;
  v17 = &v73->Paragraphs;
  v18 = 0i64;
  if ( v16 > 0 )
  {
    do
    {
      v19 = (v16 >> 1) + v18;
      v20 = v17->Data.Data[v19].pPara;
      v21 = v20->StartIndex;
      if ( v8 >= v21 && v8 < v21 + v20->Text.Size || (signed int)v21 - (signed int)v8 >= 0 )
      {
        v16 >>= 1;
      }
      else
      {
        v18 = v19 + 1;
        v16 += -1 - (v16 >> 1);
      }
    }
    while ( v16 > 0 );
    v13 = v73;
  }
  if ( v18 == v15 )
    LODWORD(v18) = v18 - 1;
  v22 = v17->Data.Data;
  v70.m128i_i64[0] = (__int64)&v73->Paragraphs;
  v23 = v22[(signed int)v18].pPara;
  v70.m128i_i64[1] = (signed int)v18;
  _mm_store_si128(&v70, v70);
  v24 = v23->StartIndex;
  v14 = v8 - v24;
  v66 = v23->StartIndex;
  startSrcIndex = v8 - v24;
  if ( (signed int)v18 < 0 || (signed int)v18 >= (signed __int64)SLODWORD(v73->Paragraphs.Data.Size) )
  {
    v25 = v70.m128i_i64[1];
LABEL_24:
    v66 = 0i64;
    goto LABEL_25;
  }
  v25 = v70.m128i_i64[1];
LABEL_25:
  v26 = pdefParaFmt;
  v27 = 0;
  v67 = 0i64;
  while ( 1 )
  {
    if ( newLinePolicy == 2 )
    {
      if ( !v7 )
        break;
      do
      {
        if ( *v9 != 13 && *v9 != 10 )
          break;
        ++v9;
        --v7;
      }
      while ( v7 );
      if ( !v7 )
        break;
    }
    v28 = (_QWORD *)v70.m128i_i64[0];
    if ( !v70.m128i_i64[0] || v25 < 0 || v25 >= *(signed int *)(v70.m128i_i64[0] + 8) )
    {
      Scaleform::Render::Text::StyledText::AppendNewParagraph(v13, v26);
      v13 = v73;
      v26 = pdefParaFmt;
      v14 = 0i64;
      v71 = (__m128i)(unsigned __int64)&v73->Paragraphs;
      startSrcIndex = 0i64;
      _mm_store_si128(&v70, v71);
      v25 = v70.m128i_i64[1];
      v28 = (_QWORD *)v70.m128i_i64[0];
    }
    v29 = *(Scaleform::Render::Text::Paragraph **)(*v28 + 8 * v25);
    v30 = v29->Text.Size;
    if ( !v30 )
      goto LABEL_139;
    v31 = v30 - 1;
    if ( !v29->Text.pText || (v32 = v31 < v30, v33 = &v29->Text.pText[v31], !v32) )
      v33 = 0i64;
    if ( !*v33 )
      --v30;
    if ( !v30 )
    {
LABEL_139:
      Scaleform::Render::Text::Paragraph::SetFormat(
        *(Scaleform::Render::Text::Paragraph **)(*v28 + 8 * v25),
        v13->pTextAllocator.pObject,
        v26);
      v13 = v73;
      v14 = startSrcIndex;
    }
    v34 = -1i64;
    v35 = 0i64;
    if ( newLinePolicy == NLP_CompressCRLF && v27 == 13 && *v9 == 10 )
    {
      ++v9;
      if ( !--v7 )
        break;
    }
    if ( v7 )
    {
      while ( 1 )
      {
        v27 = v9[v35];
        if ( v27 == 10 || v27 == 13 )
          break;
        if ( !v27 )
          goto LABEL_74;
        if ( ++v35 >= v7 )
          goto LABEL_53;
      }
      if ( newLinePolicy == 2 )
      {
        v27 = 1;
LABEL_74:
        Scaleform::Render::Text::Paragraph::InsertString(v29, v13->pTextAllocator.pObject, v9, v14, v35, pdefTextFmt);
        goto LABEL_97;
      }
      v34 = v35;
    }
LABEL_53:
    if ( v27 == 10 || v27 == 13 )
      ++v35;
    if ( v34 == -1 )
      goto LABEL_74;
    _mm_store_si128((__m128i *)&iter, v70);
    if ( v25 < v28[1] )
      iter.CurIndex = v25 + 1;
    v36 = Scaleform::Render::Text::StyledText::InsertNewParagraph(v13, &iter, pdefParaFmt);
    v37 = v29->pFormat.pObject;
    v38 = v36;
    v69 = v36;
    if ( v37 )
      ++v37->RefCount;
    v39 = v36->pFormat.pObject;
    if ( v39 )
    {
      v40 = v39->RefCount-- == 1;
      if ( v40 )
      {
        v41 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v39->pAllocator;
        if ( v39->pAllocator )
        {
          key = v39;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            v41 + 3,
            &key);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v39->pTabStops);
        v39->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v39);
        v38 = v69;
      }
    }
    v38->pFormat.pObject = v37;
    ++v38->ModCounter;
    v12 = 0i64;
    v42 = v29->Text.Size - startSrcIndex;
    Scaleform::Render::Text::Paragraph::Copy(v38, v73->pTextAllocator.pObject, v29, startSrcIndex);
    v43 = v29->Text.Size;
    Scaleform::Render::Text::Paragraph::InsertString(
      v29,
      v73->pTextAllocator.pObject,
      v9,
      startSrcIndex,
      v35,
      pdefTextFmt);
    v44 = v43 - startSrcIndex;
    if ( v44 )
    {
      v45 = v29->Text.Size;
      v46 = v29->Text.Size;
      if ( v44 < v45 )
        v46 = v44;
      v47 = v45 - v46;
      if ( v45 == -1i64 )
      {
        v48 = -1i64;
        goto LABEL_76;
      }
      v48 = v46;
      if ( v45 != v47 )
      {
LABEL_76:
        if ( v47 < v45 )
        {
          if ( v47 + v48 < v45 )
          {
            memmove(&v29->Text.pText[v45 - v46], &v29->Text.pText[v45 - v46 + v48], 2 * (v46 - v48));
            v29->Text.Size -= v48;
          }
          else
          {
            v29->Text.Size = v47;
          }
        }
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
          &v29->FormatInfo,
          v47,
          v48);
        v49 = v29->Text.Size;
        if ( v49 )
        {
          v50 = v29->Text.pText;
          v51 = v49 - 1;
          if ( v29->Text.pText && v51 < v49 )
            v52 = &v50[v51];
          else
            v52 = 0i64;
          if ( !*v52 )
          {
            if ( v49 )
            {
              v53 = v49 - 1;
              if ( v50 && v53 < v49 )
                v54 = &v50[v53];
              else
                v54 = 0i64;
              if ( !*v54 )
                --v49;
            }
            Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
              &v29->FormatInfo,
              v49,
              1ui64);
            Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
              &v29->FormatInfo,
              v49 + 1,
              1ui64);
          }
        }
        ++v29->ModCounter;
      }
      v12 = 0i64;
    }
    v28 = (_QWORD *)v70.m128i_i64[0];
LABEL_97:
    if ( v27 != 13 && v27 != 10 )
    {
      v13 = v73;
      v55 = startSrcIndex;
    }
    else
    {
      v13 = v73;
      v55 = startSrcIndex;
      v56 = 10;
      if ( v73->RTFlags & 2 )
        v56 = 13;
      if ( v27 != v56 )
        v29->Text.pText[v35 - 1 + startSrcIndex] = v56;
    }
    v67 += v35;
    v7 -= v35;
    v9 += v35;
    v29->StartIndex = v66;
    if ( newLinePolicy == 2 )
    {
      v14 = v35 + v55;
      startSrcIndex = v14;
    }
    else
    {
      v14 = 0i64;
      startSrcIndex = 0i64;
      v66 += v29->Text.Size;
      if ( v25 < v28[1] )
        v70.m128i_i64[1] = ++v25;
    }
    if ( v7 )
    {
      v26 = pdefParaFmt;
      if ( v27 )
        continue;
    }
    break;
  }
  v57 = (_QWORD *)v70.m128i_i64[0];
  while ( v57 && v25 >= 0 && v25 < *((signed int *)v57 + 2) )
  {
    v58 = *(_QWORD *)(*v57 + 8 * v25);
    *(_QWORD *)(v58 + 56) = v66;
    v66 += *(_QWORD *)(v58 + 8);
    if ( v25 < v57[1] )
      ++v25;
  }
  v59 = v13->Paragraphs.Data.Size - 1;
  if ( v13 != (Scaleform::Render::Text::StyledText *)-24i64
    && v59 >= 0
    && v59 < SLODWORD(v13->Paragraphs.Data.Size)
    && (v60 = v13->Paragraphs.Data.Data[v59].pPara) != 0i64 )
  {
LABEL_122:
    v61 = v60->Text.Size;
    if ( !v61 )
      goto LABEL_140;
    v62 = v61 - 1;
    if ( v60->Text.pText && v62 < v61 )
      v12 = &v60->Text.pText[v62];
    if ( *v12 != 10 && *v12 != 13 )
LABEL_140:
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        v60,
        v13->pTextAllocator.pObject,
        v13->pDefaultTextFormat.pObject);
  }
  else
  {
    v60 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v13, 0i64);
    if ( v60 )
    {
      v13 = v73;
      goto LABEL_122;
    }
  }
  if ( pdefTextFmt->PresentMask & 0x100 )
  {
    v63 = pdefTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    v64 = *(_QWORD *)v63 & 0x7FFFFFFFFFFFFFFFi64;
    if ( *(_QWORD *)v63 >= 0i64 )
    {
      v65 = Scaleform::UTF8Util::GetLength((const char *)(v63 + 12), *(_QWORD *)v63 & 0x7FFFFFFFFFFFFFFFi64);
      if ( v65 == v64 )
        *(_QWORD *)v63 |= 0x8000000000000000ui64;
      v64 = v65;
    }
    if ( v64 )
      v73->RTFlags |= 1u;
  }
  return v67;
}

// File Line: 2016
// RVA: 0x996110
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::InsertStyledText(Scaleform::Render::Text::StyledText *this, Scaleform::Render::Text::StyledText *text, unsigned __int64 pos, unsigned __int64 length)
{
  Scaleform::Render::Text::StyledText *v4; // r13
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  Scaleform::Render::Text::StyledText *v7; // rbp
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rsi
  wchar_t *v10; // r12
  signed __int64 v11; // r9
  signed __int64 v12; // r8
  signed __int64 v13; // r10
  signed __int64 v14; // r11
  __int64 v15; // rax
  unsigned __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rcx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v19; // xmm0
  unsigned __int64 v20; // rdi
  __int64 v21; // rbx
  unsigned __int64 v22; // rsi
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v23; // rax
  Scaleform::Render::Text::Paragraph *v24; // rbp
  Scaleform::Render::Text::Paragraph *v25; // r15
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rcx
  bool v28; // cf
  wchar_t *v29; // rcx
  unsigned __int64 v30; // rsi
  Scaleform::Render::Text::Paragraph *v31; // r15
  Scaleform::Render::Text::Paragraph *v32; // rax
  unsigned __int64 v33; // ST28_8
  Scaleform::Render::Text::Paragraph *v34; // rbp
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // rcx
  wchar_t *v37; // rcx
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // r12
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v41; // r8
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v42; // rax
  unsigned __int64 v43; // rax
  unsigned __int64 v44; // rcx
  wchar_t *v45; // rcx
  unsigned __int64 v46; // rsi
  Scaleform::Render::Text::StyledText *v47; // rcx
  signed __int64 v48; // rbp
  Scaleform::Render::Text::Paragraph *v49; // r15
  unsigned __int64 v50; // rax
  unsigned __int64 v51; // rdi
  unsigned __int64 v52; // rcx
  wchar_t *v53; // rcx
  unsigned __int64 v54; // rcx
  wchar_t *v55; // rax
  wchar_t v56; // ax
  Scaleform::Render::Text::Paragraph *v57; // rdi
  unsigned __int64 v58; // rax
  unsigned __int64 v59; // rcx
  wchar_t *v60; // rcx
  Scaleform::Render::Text::Paragraph *v61; // rcx
  signed __int64 v62; // rcx
  Scaleform::Render::Text::Paragraph *v63; // rax
  unsigned __int64 v64; // rcx
  unsigned __int64 v65; // rdx
  Scaleform::Render::Text::Paragraph *v67; // [rsp+30h] [rbp-68h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator iter; // [rsp+40h] [rbp-58h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v69; // [rsp+50h] [rbp-48h]
  Scaleform::Render::Text::StyledText *v70; // [rsp+A8h] [rbp+10h]
  unsigned __int64 v71; // [rsp+B8h] [rbp+20h]

  v71 = length;
  v70 = text;
  v4 = this;
  v5 = length;
  v6 = pos;
  v7 = text;
  v8 = Scaleform::Render::Text::StyledText::GetLength(text);
  if ( v5 == -1i64 || v5 > v8 )
  {
    v5 = v8;
    v71 = v8;
  }
  if ( !v5 || !v7->Paragraphs.Data.Size )
    return 0i64;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))v4->vfptr[1].__vecDelDtor)(
    v4,
    v6,
    v5,
    &customWorldMapCaption);
  v9 = v4->Paragraphs.Data.Size;
  v10 = 0i64;
  if ( !v9 )
    goto LABEL_121;
  v11 = v4->Paragraphs.Data.Size;
  v12 = (signed __int64)&v4->Paragraphs;
  v13 = 0i64;
  if ( v11 > 0 )
  {
    do
    {
      v14 = (v11 >> 1) + v13;
      v15 = *(_QWORD *)(*(_QWORD *)v12 + 8 * v14);
      v16 = *(_QWORD *)(v15 + 56);
      if ( v6 >= v16 && v6 < v16 + *(_QWORD *)(v15 + 8) || (signed int)v16 - (signed int)v6 >= 0 )
      {
        v11 >>= 1;
      }
      else
      {
        v13 = v14 + 1;
        v11 += -1 - (v11 >> 1);
      }
    }
    while ( v11 > 0 );
    v12 = (signed __int64)&v4->Paragraphs;
  }
  if ( v13 == v9 )
    LODWORD(v13) = v13 - 1;
  v17 = *(_QWORD *)v12;
  v69.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)v12;
  v18 = *(_QWORD *)(v17 + 8i64 * (signed int)v13);
  v69.CurIndex = (signed int)v13;
  v19 = v69;
  v20 = v6 - *(_QWORD *)(v18 + 56);
  if ( (signed int)v13 < 0 || (signed int)v13 >= (signed __int64)*(signed int *)(v12 + 8) )
  {
LABEL_121:
    Scaleform::Render::Text::StyledText::AppendNewParagraph(v4, 0i64);
    iter.CurIndex = 0i64;
    iter.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->Paragraphs.Data;
    v20 = 0i64;
    v19 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator)(unsigned __int64)&v4->Paragraphs;
    v69 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator)(unsigned __int64)&v4->Paragraphs;
  }
  v21 = v69.CurIndex;
  if ( v19.pArray && v69.CurIndex >= 0 && v69.CurIndex < SLODWORD(v19.pArray->Data.Size) )
    v22 = v19.pArray->Data.Data[v69.CurIndex].pPara->StartIndex;
  else
    v22 = 0i64;
  v23 = v19.pArray->Data.Data;
  if ( v7->Paragraphs.Data.Size == 1 )
  {
    v24 = v23[v69.CurIndex].pPara;
    v25 = v70->Paragraphs.Data.Data->pPara;
    v26 = v25->Text.Size;
    if ( v26 )
    {
      v27 = v26 - 1;
      if ( !v25->Text.pText || (v28 = v27 < v26, v29 = &v25->Text.pText[v27], !v28) )
        v29 = 0i64;
      *v29;
    }
    Scaleform::Render::Text::Paragraph::Copy(v24, v4->pTextAllocator.pObject, v25, 0i64);
    if ( !v20 )
      Scaleform::Render::Text::Paragraph::SetFormat(v24, v4->pTextAllocator.pObject, v25->pFormat.pObject);
    v30 = v24->Text.Size + v22;
  }
  else
  {
    v31 = v23[v69.CurIndex].pPara;
    _mm_store_si128((__m128i *)&iter, (__m128i)v19);
    if ( v21 < (signed __int64)v19.pArray->Data.Size )
      iter.CurIndex = v21 + 1;
    v32 = Scaleform::Render::Text::StyledText::InsertNewParagraph(v4, &iter, v31->pFormat.pObject);
    v33 = v31->Text.Size - v20;
    v67 = v32;
    Scaleform::Render::Text::Paragraph::Copy(v32, v4->pTextAllocator.pObject, v31, v20);
    iter.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)(v31->Text.Size - v20);
    v34 = v7->Paragraphs.Data.Data->pPara;
    v35 = v34->Text.Size;
    if ( v35 )
    {
      v36 = v35 - 1;
      if ( !v34->Text.pText || (v28 = v36 < v35, v37 = &v34->Text.pText[v36], !v28) )
        v37 = 0i64;
      *v37;
    }
    Scaleform::Render::Text::Paragraph::Copy(v31, v4->pTextAllocator.pObject, v34, 0i64);
    v38 = v34->Text.Size;
    if ( v38 )
    {
      v39 = v38 - 1;
      if ( v34->Text.pText && v39 < v38 )
        v10 = &v34->Text.pText[v39];
      if ( !*v10 )
        --v38;
    }
    v40 = v71 - v38;
    if ( !v20 )
      Scaleform::Render::Text::Paragraph::SetFormat(v31, v4->pTextAllocator.pObject, v34->pFormat.pObject);
    if ( iter.pArray )
    {
      v41 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)v31->Text.Size;
      v42 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)v31->Text.Size;
      if ( iter.pArray < v41 )
        v42 = iter.pArray;
      Scaleform::Render::Text::Paragraph::Remove(v31, v31->Text.Size - (_QWORD)v42, (unsigned __int64)v41);
    }
    v43 = v31->Text.Size;
    if ( v43 )
    {
      v44 = v43 - 1;
      if ( v31->Text.pText && v44 < v43 )
        v45 = &v31->Text.pText[v44];
      else
        v45 = 0i64;
      if ( !*v45 )
        --v43;
    }
    v46 = v43 + v22;
    if ( v21 < (signed __int64)v19.pArray->Data.Size )
      v69.CurIndex = ++v21;
    v47 = v70;
    v48 = 0i64;
    if ( (signed __int64)v70->Paragraphs.Data.Size > 0 )
      v48 = 1i64;
    while ( v48 >= 0 && v48 < SLODWORD(v47->Paragraphs.Data.Size) && v40 )
    {
      v49 = v47->Paragraphs.Data.Data[v48].pPara;
      v50 = v49->Text.Size;
      v51 = v50;
      if ( v50 )
      {
        v52 = v50 - 1;
        if ( v49->Text.pText && v52 < v50 )
          v53 = &v49->Text.pText[v52];
        else
          v53 = 0i64;
        if ( !*v53 )
          v51 = v50 - 1;
      }
      if ( v51 > v40
        || v51 == v40
        && (!v50
         || ((v54 = v50 - 1, !v49->Text.pText) || v54 >= v50 ? (v55 = 0i64) : (v55 = &v49->Text.pText[v54]),
             (v56 = *v55, v56 != 13) && v56 != 10)) )
      {
        v57 = v67;
        v10 = 0i64;
        Scaleform::Render::Text::Paragraph::Copy(v67, v4->pTextAllocator.pObject, v49, 0i64);
        Scaleform::Render::Text::Paragraph::SetFormat(v67, v4->pTextAllocator.pObject, v49->pFormat.pObject);
        goto LABEL_89;
      }
      Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(v4, &v69, v49);
      v47 = v70;
      v40 -= v51;
      v46 += v51;
      if ( v48 < (signed __int64)v70->Paragraphs.Data.Size )
        ++v48;
      if ( v21 < (signed __int64)v19.pArray->Data.Size )
        v69.CurIndex = ++v21;
    }
    v57 = v67;
    v10 = 0i64;
LABEL_89:
    v58 = v57->Text.Size;
    v57->StartIndex = v46;
    if ( v58 )
    {
      v59 = v58 - 1;
      if ( !v57->Text.pText || (v28 = v59 < v58, v60 = &v57->Text.pText[v59], !v28) )
        v60 = 0i64;
      if ( !*v60 )
        --v58;
    }
    v30 = v58 + v46;
  }
  if ( v21 < (signed __int64)v19.pArray->Data.Size )
    ++v21;
  while ( v21 >= 0 )
  {
    if ( v21 >= SLODWORD(v19.pArray->Data.Size) )
      break;
    v61 = v19.pArray->Data.Data[v21].pPara;
    if ( v61->StartIndex == v30 )
      break;
    v61->StartIndex = v30;
    v30 += v61->Text.Size;
    if ( v21 < (signed __int64)v19.pArray->Data.Size )
      ++v21;
  }
  v62 = v4->Paragraphs.Data.Size - 1;
  if ( v4 != (Scaleform::Render::Text::StyledText *)-24i64
    && v62 >= 0
    && v62 < SLODWORD(v4->Paragraphs.Data.Size)
    && (v63 = v4->Paragraphs.Data.Data[v62].pPara) != 0i64
    || (v63 = Scaleform::Render::Text::StyledText::AppendNewParagraph(v4, 0i64)) != 0i64 )
  {
    v64 = v63->Text.Size;
    if ( !v64 )
      goto LABEL_122;
    v65 = v64 - 1;
    if ( v63->Text.pText && v65 < v64 )
      v10 = &v63->Text.pText[v65];
    if ( *v10 != 10 && *v10 != 13 )
LABEL_122:
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        v63,
        v4->pTextAllocator.pObject,
        v4->pDefaultTextFormat.pObject);
  }
  if ( v70->RTFlags & 1 )
    v4->RTFlags |= 1u;
  return v71;
} v10 = &v63->Text.pText[v65];
    if ( *v10 != 10 && *v10 != 13 )
LABEL_122:
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        v63,
        v4->pTextAllocator.pObject,
        v4->pDefaultTextFormat.pObject);
  }
  if ( v70->RTFlags & 1 )
    v4->RTFlags |= 1u;
  return v71;
}

// File Line: 2144
// RVA: 0x9A8CE0
void __fastcall Scaleform::Render::Text::StyledText::Remove(Scaleform::Render::Text::StyledText *this, unsigned __int64 startPos, unsigned __int64 length)
{
  unsigned __int64 v3; // r13
  unsigned __int64 v4; // rbx
  Scaleform::Render::Text::StyledText *v5; // r12
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  signed __int64 v7; // r9
  unsigned __int64 v8; // r11
  signed __int64 v9; // rsi
  unsigned __int64 v10; // r10
  Scaleform::Render::Text::Paragraph *v11; // rax
  unsigned __int64 v12; // r8
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rbx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v16; // rdi
  unsigned __int64 v17; // r14
  Scaleform::Render::Text::Paragraph *v18; // rcx
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // r15
  Scaleform::Render::Text::Paragraph *v21; // rbx
  unsigned __int64 v22; // r15
  unsigned __int64 v23; // rcx
  Scaleform::Render::Text::Paragraph *v24; // rbp
  Scaleform::Render::Text::ParagraphFormat *v25; // rbx
  bool v26; // zf
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v27; // rcx
  bool v28; // dl
  unsigned __int64 startDestIndex; // ST20_8
  Scaleform::Render::Text::Paragraph *v30; // rbx
  unsigned __int64 v31; // ST20_8
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *v32[2]; // [rsp+40h] [rbp-58h]
  unsigned __int64 v33; // [rsp+A0h] [rbp+8h]
  bool v34; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::Text::Paragraph *v35; // [rsp+A8h] [rbp+10h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+B0h] [rbp+18h]
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v37; // [rsp+B8h] [rbp+20h]

  v3 = length;
  v4 = startPos;
  v5 = this;
  if ( length == -1i64 )
    v3 = Scaleform::Render::Text::StyledText::GetLength(this);
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64))v5->vfptr[3].__vecDelDtor)(
    v5,
    v4,
    v3);
  v6 = &v5->Paragraphs;
  v7 = v5->Paragraphs.Data.Size;
  v8 = 0i64;
  v9 = -1i64;
  while ( v7 > 0 )
  {
    v10 = (v7 >> 1) + v8;
    v11 = v6->Data.Data[v10].pPara;
    v12 = v11->StartIndex;
    if ( v4 >= v12 && v4 < v12 + v11->Text.Size || (signed int)v12 - (signed int)v4 >= 0 )
    {
      v7 >>= 1;
    }
    else
    {
      v8 = v10 + 1;
      v7 += -1 - (v7 >> 1);
    }
  }
  if ( v8 >= v5->Paragraphs.Data.Size
    || ((v13 = v6->Data.Data[v8].pPara, v14 = v13->StartIndex, v4 < v14) || v4 >= v14 + v13->Text.Size)
    && (_DWORD)v14 != (_DWORD)v4 )
  {
    v16 = 0i64;
    v15 = v33;
  }
  else
  {
    v32[0] = (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Paragraphs.Data.Data;
    v32[1] = (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)(signed int)v8;
    v15 = v4 - v6->Data.Data[(signed int)v8].pPara->StartIndex;
    _mm_store_si128((__m128i *)v32, *(__m128i *)v32);
    v9 = (signed __int64)v32[1];
    v16 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)v32[0];
  }
  v35 = 0i64;
  v17 = v3;
  v34 = 0;
  if ( v16 )
  {
    if ( v9 >= 0 && v9 < SLODWORD(v16->Data.Size) )
    {
      v18 = v16->Data.Data[v9].pPara;
      v19 = v18->Text.Size;
      v20 = v18->Text.Size - v15;
      if ( v3 < v20 )
        v20 = v3;
      if ( v20 <= v19 )
      {
        v34 = v20 + v15 >= v19;
        v35 = v16->Data.Data[v9].pPara;
        Scaleform::Render::Text::Paragraph::Remove(v18, v15, v20 + v15);
        v17 = v3 - v20;
        if ( v9 < (signed __int64)v16->Data.Size )
          ++v9;
      }
    }
    while ( 1 )
    {
      if ( !v16 )
        goto LABEL_61;
      if ( v9 < 0 || v9 >= SLODWORD(v16->Data.Size) )
        goto LABEL_46;
      v21 = v16->Data.Data[v9].pPara;
      v22 = v21->Text.Size;
      if ( v17 < v22 )
        break;
      v5->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)v16->Data.Data[v9].pPara);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21->Text.pText);
      v21->Text.pText = 0i64;
      v21->Text.Allocated = 0i64;
      v21->Text.Size = 0i64;
      v23 = v16->Data.Size;
      if ( v9 < (signed int)v23 )
      {
        if ( v23 == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)&v16->Data.Data,
            v16,
            0i64);
        }
        else
        {
          v24 = v16->Data.Data[v9].pPara;
          key = (Scaleform::Render::Text::ParagraphFormat *)v24;
          if ( v24 )
          {
            v37 = &v24->FormatInfo;
            Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
              v24->FormatInfo.Ranges.Data.Data,
              v24->FormatInfo.Ranges.Data.Size);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(
              Scaleform::Memory::pGlobalHeap,
              v24->FormatInfo.Ranges.Data.Data);
            v25 = v24->pFormat.pObject;
            if ( v25 )
            {
              v26 = v25->RefCount-- == 1;
              if ( v26 )
              {
                v27 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v25->pAllocator;
                if ( v25->pAllocator )
                {
                  key = v25;
                  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
                    v27 + 3,
                    &key);
                }
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25->pTabStops);
                v25->pTabStops = 0i64;
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
              }
            }
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v24);
          }
          memmove(&v16->Data.Data[v9], &v16->Data.Data[v9 + 1], 8 * (v16->Data.Size - v9) - 8);
          --v16->Data.Size;
        }
      }
      v17 -= v22;
      if ( !v17 )
      {
LABEL_46:
        v28 = v34;
        goto LABEL_47;
      }
    }
    v28 = v34;
    if ( v35 && v34 )
    {
      startDestIndex = v35->Text.Size;
      Scaleform::Render::Text::Paragraph::Copy(v35, v5->pTextAllocator.pObject, v21, v17);
      v5->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)v21);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21->Text.pText);
      v21->Text.pText = 0i64;
      v21->Text.Allocated = 0i64;
      v21->Text.Size = 0i64;
      if ( v9 < SLODWORD(v16->Data.Size) )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          v16,
          v9);
      v28 = 0;
    }
LABEL_47:
    if ( !v16 )
      goto LABEL_61;
    if ( v9 >= 0 && v9 < SLODWORD(v16->Data.Size) )
    {
      v30 = v16->Data.Data[v9].pPara;
      if ( !v30->Text.Size )
        goto LABEL_54;
      if ( v35 && v28 )
      {
        v31 = v35->Text.Size;
        Scaleform::Render::Text::Paragraph::Copy(v35, v5->pTextAllocator.pObject, v30, 0i64);
LABEL_54:
        v5->vfptr[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)v30);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v30->Text.pText);
        v30->Text.pText = 0i64;
        v30->Text.Allocated = 0i64;
        v30->Text.Size = 0i64;
        if ( v9 < SLODWORD(v16->Data.Size) )
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            v16,
            v9);
        goto LABEL_56;
      }
    }
LABEL_56:
    while ( v16 && v9 >= 0 && v9 < SLODWORD(v16->Data.Size) )
    {
      v16->Data.Data[v9].pPara->StartIndex -= v3;
      if ( v9 < (signed __int64)v16->Data.Size )
        ++v9;
    }
  }
LABEL_61:
  Scaleform::Render::Text::StyledText::EnsureTermNull(v5);
}

// File Line: 2369
// RVA: 0x95FAC0
void __fastcall Scaleform::Render::Text::StyledText::Clear(Scaleform::Render::Text::StyledText *this)
{
  unsigned __int64 v1; // rbp
  Scaleform::Render::Text::StyledText *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::Text::Paragraph *v4; // rdi

  v1 = this->Paragraphs.Data.Size;
  v2 = this;
  v3 = 0i64;
  if ( v1 )
  {
    do
    {
      v4 = v2->Paragraphs.Data.Data[v3].pPara;
      Scaleform::Render::Text::StyledText::GetAllocator(v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->Text.pText);
      ++v3;
      v4->Text.pText = 0i64;
      v4->Text.Allocated = 0i64;
      v4->Text.Size = 0i64;
    }
    while ( v3 < v1 );
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Paragraphs.Data.Data,
    &v2->Paragraphs,
    0i64);
  v2->RTFlags &= 0xFEu;
}

