// File Line: 28
// RVA: 0x958410
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::Allocator::AllocateParagraph(
        Scaleform::Render::Text::Allocator *this)
{
  Scaleform::Render::Text::Paragraph *result; // rax
  unsigned int NewParagraphId; // edx

  result = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                   this->pHeap,
                                                   72i64);
  if ( !result )
    return 0i64;
  result->Text.pText = 0i64;
  result->Text.Size = 0i64;
  result->Text.Allocated = 0i64;
  result->pFormat.pObject = 0i64;
  result->FormatInfo.Ranges.Data.Data = 0i64;
  result->FormatInfo.Ranges.Data.Size = 0i64;
  result->FormatInfo.Ranges.Data.Policy.Capacity = 0i64;
  result->StartIndex = 0i64;
  result->ModCounter = 0;
  NewParagraphId = this->NewParagraphId;
  this->NewParagraphId = NewParagraphId + 1;
  result->UniqueId = NewParagraphId;
  return result;
}

// File Line: 111
// RVA: 0x969240
wchar_t *__fastcall Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
        Scaleform::Render::Text::Paragraph::TextBuffer *this,
        Scaleform::Render::Text::Allocator *pallocator,
        unsigned __int64 pos,
        unsigned __int64 length)
{
  unsigned __int64 Size; // r8
  unsigned __int64 v7; // r9
  wchar_t *v9; // rax
  __int64 v10; // r8
  wchar_t *pText; // rax

  Size = this->Size;
  v7 = Size + length;
  if ( this->Allocated < v7 )
  {
    if ( this->pText )
      v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                        Scaleform::Memory::pGlobalHeap,
                        this->pText,
                        2 * v7);
    else
      v9 = (wchar_t *)pallocator->pHeap->vfptr->Alloc(pallocator->pHeap, 2 * v7, 0i64);
    Size = this->Size;
    this->pText = v9;
    this->Allocated = Size + length;
  }
  v10 = Size - pos;
  if ( v10 )
    memmove(&this->pText[pos + length], &this->pText[pos], 2 * v10);
  pText = this->pText;
  this->Size += length;
  return &pText[pos];
}

// File Line: 228
// RVA: 0x9404D0
void __fastcall Scaleform::Render::Text::Paragraph::Paragraph(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Paragraph *o,
        Scaleform::Render::Text::Allocator *ptextAllocator)
{
  wchar_t *v6; // rax
  unsigned __int64 Size; // r8
  signed __int64 v8; // rsi
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // r15
  unsigned int NewParagraphId; // ecx
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // rbx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  __int64 v13; // r14
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *Data; // rbp
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
  Scaleform::Render::Text::TextFormat *v16; // rbx
  Scaleform::Render::Text::TextFormat *v17; // rdi
  bool v18; // zf

  v6 = (wchar_t *)ptextAllocator->pHeap->vfptr->Alloc(ptextAllocator->pHeap, 2 * o->Text.Size, 0i64);
  this->Text.pText = v6;
  Size = o->Text.Size;
  this->Text.Size = Size;
  this->Text.Allocated = Size;
  memmove(v6, o->Text.pText, 2 * o->Text.Size);
  v8 = 0i64;
  this->pFormat.pObject = 0i64;
  p_FormatInfo = &this->FormatInfo;
  Scaleform::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,Scaleform::AllocatorLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2>,Scaleform::ArrayDefaultPolicy>(
    &this->FormatInfo.Ranges.Data,
    &o->FormatInfo.Ranges.Data);
  this->StartIndex = o->StartIndex;
  this->ModCounter = 0;
  NewParagraphId = ptextAllocator->NewParagraphId;
  ptextAllocator->NewParagraphId = NewParagraphId + 1;
  this->UniqueId = NewParagraphId;
  ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(ptextAllocator, o->pFormat.pObject);
  pObject = this->pFormat.pObject;
  if ( pObject )
    Scaleform::Render::Text::ParagraphFormat::Release(pObject);
  this->pFormat.pObject = ParagraphFormat;
  v13 = 0i64;
  while ( v8 >= 0 && v8 < this->FormatInfo.Ranges.Data.Size )
  {
    Data = p_FormatInfo->Ranges.Data.Data;
    TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(
                   ptextAllocator,
                   p_FormatInfo->Ranges.Data.Data[v13].Data.pObject);
    v16 = TextFormat;
    if ( TextFormat )
      ++TextFormat->RefCount;
    v17 = Data[v13].Data.pObject;
    if ( v17 )
    {
      v18 = v17->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v17);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17);
      }
    }
    Data[v13].Data.pObject = v16;
    if ( v16 )
    {
      v18 = v16->RefCount-- == 1;
      if ( v18 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v16);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
    }
    if ( v8 < (signed __int64)this->FormatInfo.Ranges.Data.Size )
    {
      ++v8;
      ++v13;
    }
  }
}

// File Line: 276
// RVA: 0x9B43F0
void __fastcall Scaleform::Render::Text::Paragraph::SetTextFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::TextFormat *fmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::Text::TextFormat *v5; // rsi
  Scaleform::Render::Text::Paragraph *v7; // rbx
  unsigned __int64 v8; // r12
  unsigned __int64 v9; // r11
  __int64 v10; // r12
  unsigned __int64 Size; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *Data; // r10
  wchar_t *pText; // rax
  Scaleform::Render::Text::TextFormat *pObject; // rdi
  unsigned __int64 Length; // rcx
  Scaleform::Render::Text::TextFormat *v16; // rbx
  bool v17; // zf
  Scaleform::Render::Text::TextFormat *v18; // rbx
  __int64 Index; // r14
  unsigned __int64 v20; // r15
  __int64 v21; // rdi
  Scaleform::MemoryHeap *pHeap; // rdx
  Scaleform::MemoryHeap *v23; // rax
  Scaleform::MemoryHeap *v24; // rax
  Scaleform::Render::Text::TextFormat *v25; // rax
  Scaleform::Render::Text::FontHandle *v26; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v27; // rcx
  Scaleform::Render::Text::TextFormat *v28; // rdx
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
  Scaleform::Render::Text::TextFormat *v30; // rbx
  unsigned __int64 v31; // rsi
  __int64 v32; // r9
  Scaleform::Render::Text::TextFormat *v33; // rdi
  unsigned __int64 v34; // rdx
  unsigned __int64 CurTextIndex; // r8
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
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::StringDH *p_FontList; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Text::TextFormat v50; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Text::TextFormat *key; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::Render::Text::TextFormat *v52; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v54; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::Text::TextFormat v55; // [rsp+100h] [rbp+0h] BYREF

  v54 = -2i64;
  v5 = fmt;
  v7 = this;
  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &result, startPos);
  v8 = endPos;
  v9 = startPos;
  if ( endPos < startPos )
    v8 = startPos;
  if ( v8 == -1i64 )
  {
    v10 = 0x7FFFFFFFFFFFFFFFi64;
    goto LABEL_6;
  }
  v10 = v8 - startPos;
  if ( v10 > 0 )
  {
    while ( 1 )
    {
LABEL_6:
      Size = result.pText->Size;
      if ( result.CurTextIndex >= Size )
      {
LABEL_95:
        v7 = this;
        break;
      }
      if ( result.FormatIterator.Index < 0
        || result.FormatIterator.Index >= result.FormatIterator.pArray->Ranges.Data.Size )
      {
        pText = result.pText->pText;
      }
      else
      {
        Data = result.FormatIterator.pArray->Ranges.Data.Data;
        Size = result.FormatIterator.pArray->Ranges.Data.Data[result.FormatIterator.Index].Index;
        pText = result.pText->pText;
        if ( result.CurTextIndex >= Size )
        {
          pObject = Data[result.FormatIterator.Index].Data.pObject;
          Length = Data[result.FormatIterator.Index].Length;
          result.PlaceHolder.pText = &pText[Size];
          result.PlaceHolder.Index = Size;
          result.PlaceHolder.Length = Length;
          if ( pObject )
            ++pObject->RefCount;
          v16 = result.PlaceHolder.pFormat.pObject;
          if ( result.PlaceHolder.pFormat.pObject )
          {
            v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v16);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
              v9 = startPos;
            }
          }
          result.PlaceHolder.pFormat.pObject = pObject;
          goto LABEL_21;
        }
      }
      v18 = result.PlaceHolder.pFormat.pObject;
      result.PlaceHolder.Length = Size - result.CurTextIndex;
      result.PlaceHolder.Index = result.CurTextIndex;
      result.PlaceHolder.pText = &pText[result.CurTextIndex];
      if ( result.PlaceHolder.pFormat.pObject )
      {
        v17 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v18);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
          v9 = startPos;
        }
      }
      result.PlaceHolder.pFormat.pObject = 0i64;
LABEL_21:
      Index = result.PlaceHolder.Index;
      v20 = result.PlaceHolder.Length;
      v21 = result.PlaceHolder.Index;
      if ( v9 > result.PlaceHolder.Index )
        v21 = v9;
      pHeap = pallocator->pHeap;
      v50.pAllocator = 0i64;
      v50.RefCount = 1;
      v23 = Scaleform::Memory::pGlobalHeap;
      if ( pHeap )
        v23 = pHeap;
      p_FontList = &v50.FontList;
      v50.FontList.pHeap = v23;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      v50.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
      v24 = Scaleform::Memory::pGlobalHeap;
      if ( pHeap )
        v24 = pHeap;
      p_FontList = &v50.Url;
      v50.Url.pHeap = v24;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      v50.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
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
            &v55.pAllocator->TextFormatStorage,
            &key);
        }
        v26 = v55.pFontHandle.pObject;
        if ( v55.pFontHandle.pObject && !_InterlockedDecrement(&v55.pFontHandle.pObject->RefCount) && v26 )
          v26->vfptr->__vecDelDtor(v26, 1u);
        v27 = v55.pImageDesc.pObject;
        if ( v55.pImageDesc.pObject )
        {
          --v55.pImageDesc.pObject->RefCount;
          if ( !v27->RefCount )
            v27->vfptr->__vecDelDtor(v27, 1u);
        }
        p_FontList = &v55.Url;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        p_FontList = &v55.FontList;
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v28 = &v50;
      }
      else
      {
        v28 = v5;
      }
      TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, v28);
      v30 = TextFormat;
      v31 = v10;
      if ( Index + v20 - v21 < v10 )
        v31 = Index + v20 - v21;
      range.Index = v21;
      range.Length = v31;
      if ( TextFormat )
        ++TextFormat->RefCount;
      range.Data.pObject = TextFormat;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
        &this->FormatInfo,
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
      CurTextIndex = result.CurTextIndex;
      if ( result.CurTextIndex < v34 )
      {
        v36 = v20 + Index;
        v32 = result.FormatIterator.Index;
        v37 = result.PlaceHolder.pFormat.pObject;
        while ( 1 )
        {
          if ( v32 < 0 || v32 >= result.FormatIterator.pArray->Ranges.Data.Size )
          {
            v40 = result.pText->pText;
            result.PlaceHolder.Length = v34 - CurTextIndex;
          }
          else
          {
            v38 = result.FormatIterator.pArray->Ranges.Data.Data;
            v39 = result.FormatIterator.pArray->Ranges.Data.Data[v32].Index;
            v40 = result.pText->pText;
            if ( CurTextIndex >= v39 )
            {
              v41 = v38[v32].Data.pObject;
              v42 = v38[v32].Length;
              result.PlaceHolder.pText = &v40[v39];
              result.PlaceHolder.Index = v39;
              result.PlaceHolder.Length = v42;
              if ( v41 )
              {
                ++v41->RefCount;
                CurTextIndex = result.CurTextIndex;
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
                CurTextIndex = result.CurTextIndex;
              }
              v37 = v41;
              result.PlaceHolder.pFormat.pObject = v41;
              goto LABEL_69;
            }
            result.PlaceHolder.Length = v39 - CurTextIndex;
          }
          result.PlaceHolder.Index = CurTextIndex;
          result.PlaceHolder.pText = &v40[CurTextIndex];
          if ( v37 )
          {
            v17 = v37->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v37);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v37);
            }
            v32 = result.FormatIterator.Index;
            CurTextIndex = result.CurTextIndex;
          }
          result.PlaceHolder.pFormat.pObject = 0i64;
          v37 = 0i64;
LABEL_69:
          if ( result.PlaceHolder.Index < v36 )
          {
            if ( v32 < 0 || v32 >= result.FormatIterator.pArray->Ranges.Data.Size )
            {
              CurTextIndex = result.pText->Size;
              result.CurTextIndex = CurTextIndex;
            }
            else if ( CurTextIndex >= result.FormatIterator.pArray->Ranges.Data.Data[v32].Index )
            {
              CurTextIndex += result.FormatIterator.pArray->Ranges.Data.Data[v32].Length;
              result.CurTextIndex = CurTextIndex;
              if ( v32 < (signed __int64)result.FormatIterator.pArray->Ranges.Data.Size )
                result.FormatIterator.Index = ++v32;
            }
            else
            {
              CurTextIndex = result.FormatIterator.pArray->Ranges.Data.Data[v32].Index;
              result.CurTextIndex = CurTextIndex;
            }
            v34 = result.pText->Size;
            if ( CurTextIndex < v34 )
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
          &v50.pAllocator->TextFormatStorage,
          &v52);
      }
      v43 = v50.pFontHandle.pObject;
      if ( v50.pFontHandle.pObject && !_InterlockedDecrement(&v50.pFontHandle.pObject->RefCount) && v43 )
        ((void (__fastcall *)(Scaleform::Render::Text::FontHandle *, __int64, unsigned __int64, __int64, const wchar_t *))v43->vfptr->__vecDelDtor)(
          v43,
          1i64,
          CurTextIndex,
          v32,
          result.PlaceHolder.pText);
      v44 = v50.pImageDesc.pObject;
      if ( v50.pImageDesc.pObject )
      {
        --v50.pImageDesc.pObject->RefCount;
        if ( !v44->RefCount )
          ((void (__fastcall *)(Scaleform::Render::Text::HTMLImageTagDesc *, __int64, unsigned __int64, __int64))v44->vfptr->__vecDelDtor)(
            v44,
            1i64,
            CurTextIndex,
            v32);
      }
      p_FontList = &v50.Url;
      v45 = v50.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v50.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v45,
          CurTextIndex,
          v32);
      p_FontList = &v50.FontList;
      v46 = v50.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v50.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, unsigned __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v46,
          CurTextIndex,
          v32);
      v5 = fmt;
      v9 = startPos;
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
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Paragraph::GetTextFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::TextFormat *result,
        __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v5; // rsi
  __int64 v8; // r14
  Scaleform::MemoryHeap *v9; // rax
  Scaleform::MemoryHeap *v10; // rdx
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::MemoryHeap *v12; // rax
  int v13; // r15d
  unsigned __int64 CurTextIndex; // r8
  Scaleform::Render::Text::TextFormat *pObject; // rbx
  unsigned __int64 Size; // rdx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *Data; // r10
  unsigned __int64 Index; // r9
  const wchar_t *v19; // rax
  Scaleform::Render::Text::TextFormat *v20; // rdi
  unsigned __int64 Length; // rdx
  bool v22; // zf
  Scaleform::Render::Text::TextFormat *v24; // rax
  Scaleform::Render::Text::TextFormat *v25; // rbx
  Scaleform::Render::Text::Paragraph::FormatRunIterator resulta; // [rsp+20h] [rbp-E0h] BYREF
  int v28; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+80h] [rbp-80h] BYREF
  __int64 v30; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Text::TextFormat v31; // [rsp+D8h] [rbp-28h] BYREF

  v30 = -2i64;
  v5 = startPos;
  v28 = 0;
  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &resulta, startPos);
  if ( endPos < v5 )
    endPos = v5;
  if ( endPos == -1i64 )
    v8 = 0x7FFFFFFFFFFFFFFFi64;
  else
    v8 = endPos - v5;
  v9 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v10 = v9;
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  v11 = Scaleform::Memory::pGlobalHeap;
  if ( v9 )
    v11 = v9;
  fmt.FontList.pHeap = v11;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  v12 = Scaleform::Memory::pGlobalHeap;
  if ( v10 )
    v12 = v10;
  fmt.Url.pHeap = v12;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
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
    CurTextIndex = resulta.CurTextIndex;
    pObject = resulta.PlaceHolder.pFormat.pObject;
    do
    {
      Size = resulta.pText->Size;
      if ( CurTextIndex >= Size )
        break;
      if ( resulta.FormatIterator.Index < 0
        || resulta.FormatIterator.Index >= resulta.FormatIterator.pArray->Ranges.Data.Size )
      {
        v19 = &resulta.pText->pText[CurTextIndex];
        resulta.PlaceHolder.Length = Size - CurTextIndex;
      }
      else
      {
        Data = resulta.FormatIterator.pArray->Ranges.Data.Data;
        Index = resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index;
        if ( CurTextIndex >= Index )
        {
          v20 = Data[resulta.FormatIterator.Index].Data.pObject;
          Length = Data[resulta.FormatIterator.Index].Length;
          resulta.PlaceHolder.pText = &resulta.pText->pText[Index];
          resulta.PlaceHolder.Index = Index;
          resulta.PlaceHolder.Length = Length;
          if ( v20 )
          {
            ++v20->RefCount;
            CurTextIndex = resulta.CurTextIndex;
            pObject = resulta.PlaceHolder.pFormat.pObject;
          }
          if ( pObject )
          {
            v22 = pObject->RefCount-- == 1;
            if ( v22 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
            }
            CurTextIndex = resulta.CurTextIndex;
          }
          pObject = v20;
          resulta.PlaceHolder.pFormat.pObject = v20;
          if ( v20 )
          {
            if ( v13++ )
            {
              v24 = Scaleform::Render::Text::TextFormat::Intersection(v20, &v31, &fmt);
              Scaleform::Render::Text::TextFormat::operator=(&fmt, v24);
              Scaleform::Render::Text::TextFormat::~TextFormat(&v31);
            }
            else
            {
              Scaleform::Render::Text::TextFormat::operator=(&fmt, v20);
            }
            CurTextIndex = resulta.CurTextIndex;
            pObject = resulta.PlaceHolder.pFormat.pObject;
          }
          goto LABEL_34;
        }
        v19 = &resulta.pText->pText[CurTextIndex];
        resulta.PlaceHolder.Length = Index - CurTextIndex;
      }
      resulta.PlaceHolder.Index = CurTextIndex;
      resulta.PlaceHolder.pText = v19;
      if ( pObject )
      {
        v22 = pObject->RefCount-- == 1;
        if ( v22 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
        }
        CurTextIndex = resulta.CurTextIndex;
      }
      pObject = 0i64;
      resulta.PlaceHolder.pFormat.pObject = 0i64;
LABEL_34:
      v8 += v5 - resulta.PlaceHolder.Length - resulta.PlaceHolder.Index;
      v5 = resulta.PlaceHolder.Length + resulta.PlaceHolder.Index;
      if ( resulta.FormatIterator.Index < 0
        || resulta.FormatIterator.Index >= resulta.FormatIterator.pArray->Ranges.Data.Size )
      {
        CurTextIndex = resulta.pText->Size;
        resulta.CurTextIndex = CurTextIndex;
      }
      else if ( CurTextIndex >= resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index )
      {
        CurTextIndex += resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Length;
        resulta.CurTextIndex = CurTextIndex;
        if ( resulta.FormatIterator.Index < (signed __int64)resulta.FormatIterator.pArray->Ranges.Data.Size )
          ++resulta.FormatIterator.Index;
      }
      else
      {
        CurTextIndex = resulta.FormatIterator.pArray->Ranges.Data.Data[resulta.FormatIterator.Index].Index;
        resulta.CurTextIndex = CurTextIndex;
      }
    }
    while ( v8 > 0 );
  }
  Scaleform::Render::Text::TextFormat::TextFormat(result, &fmt, 0i64);
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
  return result;
}

// File Line: 342
// RVA: 0x98D750
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Paragraph::GetTextFormatPtr(
        Scaleform::Render::Text::Paragraph *this,
        __int64 startPos)
{
  Scaleform::Render::Text::TextFormat *v2; // rbx
  unsigned __int64 Size; // rcx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v4; // r10
  __int64 Index; // r8
  wchar_t *pText; // rax
  Scaleform::Render::Text::Paragraph::FormatRunIterator *p_result; // rax
  Scaleform::Render::Text::TextFormat *pObject; // rdi
  bool v9; // zf
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+40h] [rbp-58h] BYREF

  Scaleform::Render::Text::Paragraph::GetIteratorAt(this, &result, startPos);
  v2 = 0i64;
  Size = result.pText->Size;
  if ( result.CurTextIndex >= Size )
    goto LABEL_14;
  if ( result.FormatIterator.Index < 0 || result.FormatIterator.Index >= result.FormatIterator.pArray->Ranges.Data.Size )
  {
    pText = result.pText->pText;
    result.PlaceHolder.Length = Size - result.CurTextIndex;
LABEL_8:
    pObject = result.PlaceHolder.pFormat.pObject;
    result.PlaceHolder.Index = result.CurTextIndex;
    result.PlaceHolder.pText = &pText[result.CurTextIndex];
    if ( result.PlaceHolder.pFormat.pObject )
    {
      v9 = result.PlaceHolder.pFormat.pObject->RefCount-- == 1;
      if ( v9 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
    }
    p_result = &result;
    result.PlaceHolder.pFormat.pObject = 0i64;
    goto LABEL_12;
  }
  v4 = &result.FormatIterator.pArray->Ranges.Data.Data[result.FormatIterator.Index];
  Index = v4->Index;
  pText = result.pText->pText;
  if ( result.CurTextIndex < v4->Index )
  {
    result.PlaceHolder.Length = Index - result.CurTextIndex;
    goto LABEL_8;
  }
  p_result = (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                        &result.PlaceHolder,
                                                                        &pText[Index],
                                                                        Index,
                                                                        v4->Length,
                                                                        v4->Data.pObject);
LABEL_12:
  v10 = p_result->PlaceHolder.pFormat.pObject;
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
void __fastcall Scaleform::Render::Text::Paragraph::SetFormat(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::ParagraphFormat *fmt)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::ParagraphFormat *v6; // rax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // rbx
  Scaleform::Render::Text::ParagraphFormat *v8; // rcx
  Scaleform::Render::Text::ParagraphFormat result; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+78h] [rbp+20h] BYREF

  pObject = this->pFormat.pObject;
  if ( pObject )
  {
    v6 = Scaleform::Render::Text::ParagraphFormat::Merge(pObject, &result, fmt);
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, v6);
    if ( result.pAllocator )
    {
      key = &result;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        &result.pAllocator->ParagraphFormatStorage,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, result.pTabStops);
    result.pTabStops = 0i64;
  }
  else
  {
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, fmt);
  }
  if ( ParagraphFormat )
    ++ParagraphFormat->RefCount;
  v8 = this->pFormat.pObject;
  if ( v8 )
    Scaleform::Render::Text::ParagraphFormat::Release(v8);
  this->pFormat.pObject = ParagraphFormat;
  ++this->ModCounter;
  if ( ParagraphFormat )
    Scaleform::Render::Text::ParagraphFormat::Release(ParagraphFormat);
}

// File Line: 403
// RVA: 0x987D10
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::GetIterator(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Paragraph::FormatRunIterator *result)
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
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::GetIteratorAt(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Paragraph::FormatRunIterator *result,
        __int64 index)
{
  Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
    result,
    &this->FormatInfo,
    &this->Text,
    index);
  return result;
}

// File Line: 424
// RVA: 0x9B40D0
void __fastcall Scaleform::Render::Text::Paragraph::SetTermNullFormat(Scaleform::Render::Text::Paragraph *this)
{
  unsigned __int64 Size; // rdi
  wchar_t *pText; // rax
  wchar_t *v4; // rdx
  unsigned __int64 v5; // r8
  wchar_t *v6; // rcx
  unsigned __int64 v7; // rcx

  Size = this->Text.Size;
  if ( Size )
  {
    pText = this->Text.pText;
    v4 = 0i64;
    v5 = Size - 1;
    if ( !this->Text.pText || (v6 = &pText[v5], v5 >= Size) )
      v6 = 0i64;
    if ( !*v6 )
    {
      v7 = Size - 1;
      if ( pText && v7 < Size )
        v4 = &pText[v7];
      if ( !*v4 )
        --Size;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        Size,
        1ui64);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &this->FormatInfo,
        Size + 1,
        1i64);
    }
  }
}

// File Line: 438
// RVA: 0x995870
void __fastcall Scaleform::Render::Text::Paragraph::InsertString(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const wchar_t *pstr,
        unsigned __int64 pos,
        unsigned __int64 length,
        Scaleform::Render::Text::TextFormat *pnewFmt)
{
  unsigned __int64 v9; // rbx
  wchar_t *Position; // r14
  Scaleform::Render::Text::TextFormat *pObject; // rbx
  bool v12; // zf
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+28h] [rbp-30h] BYREF

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
      Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, pos, v9);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        pos,
        v9);
      ++this->ModCounter;
      if ( Position )
      {
        memmove(Position, pstr, 2 * v9);
        if ( pnewFmt )
        {
          ++pnewFmt->RefCount;
          range.Index = pos;
          range.Length = v9;
          ++pnewFmt->RefCount;
          range.Data.pObject = pnewFmt;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &this->FormatInfo,
            &range);
          pObject = range.Data.pObject;
          if ( range.Data.pObject )
          {
            v12 = range.Data.pObject->RefCount-- == 1;
            if ( v12 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
            }
          }
          v12 = pnewFmt->RefCount-- == 1;
          if ( v12 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(pnewFmt);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pnewFmt);
          }
        }
        Scaleform::Render::Text::Paragraph::SetTermNullFormat(this);
        ++this->ModCounter;
      }
    }
  }
}

// File Line: 502
// RVA: 0x959BB0
void __fastcall Scaleform::Render::Text::Paragraph::AppendTermNull(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::TextFormat *pdefTextFmt)
{
  unsigned __int64 Size; // rdi
  unsigned __int64 v7; // rax
  wchar_t *pText; // rcx
  bool v9; // cf
  wchar_t *v10; // rax
  unsigned __int64 v11; // rax
  wchar_t *v12; // rax
  wchar_t *Position; // r14
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // rbp
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
  Scaleform::Render::Text::TextFormat *v16; // rbx
  Scaleform::Render::Text::TextFormat *pObject; // rdi
  bool v18; // zf
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+28h] [rbp-40h] BYREF

  Size = this->Text.Size;
  if ( !Size )
  {
LABEL_11:
    Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, Size, 1ui64);
    p_FormatInfo = &this->FormatInfo;
    Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
      &this->FormatInfo,
      Size,
      1ui64);
    ++this->ModCounter;
    if ( Position )
    {
      *Position = 0;
      if ( !this->FormatInfo.Ranges.Data.Size )
      {
        if ( pdefTextFmt )
        {
          TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, pdefTextFmt);
          v16 = TextFormat;
          range.Index = Size;
          range.Length = 1i64;
          if ( TextFormat )
            ++TextFormat->RefCount;
          range.Data.pObject = TextFormat;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            p_FormatInfo,
            &range);
          pObject = range.Data.pObject;
          if ( range.Data.pObject )
          {
            v18 = range.Data.pObject->RefCount-- == 1;
            if ( v18 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
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
  v7 = Size - 1;
  pText = this->Text.pText;
  if ( !pText || (v9 = v7 < Size, v10 = &pText[v7], !v9) )
    v10 = 0i64;
  if ( *v10 )
  {
    v11 = Size - 1;
    if ( !this->Text.pText || (v9 = v11 < Size, v12 = &this->Text.pText[v11], !v9) )
      v12 = 0i64;
    if ( !*v12 )
      --Size;
    goto LABEL_11;
  }
}

// File Line: 522
// RVA: 0x9AA680
void __fastcall Scaleform::Render::Text::Paragraph::RemoveTermNull(Scaleform::Render::Text::Paragraph *this)
{
  unsigned __int64 Size; // rdx
  wchar_t *pText; // rax
  wchar_t *v4; // rcx
  unsigned __int64 v5; // r8
  bool v6; // cf
  wchar_t *v7; // r8
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // rcx

  Size = this->Text.Size;
  if ( Size )
  {
    pText = this->Text.pText;
    v4 = 0i64;
    v5 = Size - 1;
    if ( !pText || (v6 = v5 < Size, v7 = &pText[v5], !v6) )
      v7 = 0i64;
    if ( !*v7 )
    {
      v8 = Size - 1;
      if ( pText && v8 < Size )
        v4 = &pText[v8];
      if ( !*v4 )
        --Size;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &this->FormatInfo,
        Size,
        1i64);
      v9 = this->Text.Size;
      if ( v9 )
      {
        if ( !this->Text.pText[v9 - 1] )
          this->Text.Size = v9 - 1;
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
void __fastcall Scaleform::Render::Text::Paragraph::Remove(
        Scaleform::Render::Text::Paragraph *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 Size; // r8

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
  Size = this->Text.Size;
  if ( startPos < Size )
  {
    if ( v5 + startPos < Size )
    {
      memmove(&this->Text.pText[startPos], &this->Text.pText[v5 + startPos], 2 * (Size - v5 - startPos));
      this->Text.Size -= v5;
    }
    else
    {
      this->Text.Size = startPos;
    }
  }
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
    &this->FormatInfo,
    startPos,
    v5);
  Scaleform::Render::Text::Paragraph::SetTermNullFormat(this);
  ++this->ModCounter;
}

// File Line: 581
// RVA: 0x9642F0
void __fastcall Scaleform::Render::Text::Paragraph::Copy(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::Paragraph *psrcPara,
        signed __int64 startSrcIndex)
{
  unsigned __int64 v7; // r14
  unsigned __int64 Size; // r10
  wchar_t *v9; // r15
  unsigned __int64 CurTextIndex; // rdx
  __int64 Index; // r8
  Scaleform::Render::Text::TextFormat *pObject; // rbx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v13; // r9
  __int64 v14; // r11
  wchar_t *pText; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *p_result; // rax
  bool v17; // zf
  signed __int64 v18; // r9
  unsigned __int64 v19; // rcx
  signed __int64 v20; // rdi
  unsigned __int64 v21; // rsi
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
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
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > range; // [rsp+10h] [rbp-41h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator result; // [rsp+28h] [rbp-29h] BYREF
  Scaleform::Render::Text::Allocator *v35; // [rsp+B0h] [rbp+5Fh]
  signed __int64 retaddr; // [rsp+C8h] [rbp+77h]
  unsigned __int64 v37; // [rsp+D0h] [rbp+7Fh]

  v7 = v37;
  if ( v37 )
  {
    Scaleform::Render::Text::Paragraph::InsertString(
      this,
      pallocator,
      &psrcPara->Text.pText[startSrcIndex],
      retaddr,
      v37);
    Scaleform::Render::Text::Paragraph::GetIteratorAt(psrcPara, &result, startSrcIndex);
    Size = result.pText->Size;
    v9 = 0i64;
    CurTextIndex = result.CurTextIndex;
    if ( result.CurTextIndex < Size )
    {
      Index = result.FormatIterator.Index;
      pObject = result.PlaceHolder.pFormat.pObject;
      while ( 1 )
      {
        if ( !v7 )
          goto LABEL_39;
        if ( Index < 0 || Index >= result.FormatIterator.pArray->Ranges.Data.Size )
          break;
        v13 = &result.FormatIterator.pArray->Ranges.Data.Data[Index];
        v14 = v13->Index;
        pText = result.pText->pText;
        if ( CurTextIndex < v13->Index )
        {
          result.PlaceHolder.Length = v14 - CurTextIndex;
LABEL_11:
          result.PlaceHolder.Index = CurTextIndex;
          result.PlaceHolder.pText = &pText[CurTextIndex];
          if ( pObject )
          {
            v17 = pObject->RefCount-- == 1;
            if ( v17 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
            }
            Index = result.FormatIterator.Index;
            CurTextIndex = result.CurTextIndex;
          }
          pObject = 0i64;
          p_result = &result;
          result.PlaceHolder.pFormat.pObject = 0i64;
          goto LABEL_16;
        }
        p_result = (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                              &result.PlaceHolder,
                                                                              &pText[v14],
                                                                              v14,
                                                                              v13->Length,
                                                                              v13->Data.pObject);
        CurTextIndex = result.CurTextIndex;
        Index = result.FormatIterator.Index;
        pObject = result.PlaceHolder.pFormat.pObject;
LABEL_16:
        v18 = p_result->PlaceHolder.Index;
        v19 = p_result->PlaceHolder.Length;
        if ( v18 >= startSrcIndex )
        {
          v20 = v18 - startSrcIndex;
        }
        else
        {
          v20 = 0i64;
          v19 = v18 + v19 - startSrcIndex;
        }
        v21 = v7;
        if ( v19 < v7 )
          v21 = v19;
        if ( p_result->PlaceHolder.pFormat.pObject )
        {
          TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(
                         v35,
                         p_result->PlaceHolder.pFormat.pObject);
          v23 = TextFormat;
          range.Index = v20 + retaddr;
          range.Length = v21;
          if ( TextFormat )
            ++TextFormat->RefCount;
          range.Data.pObject = TextFormat;
          Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::SetRange(
            &this->FormatInfo,
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
          pObject = result.PlaceHolder.pFormat.pObject;
          Index = result.FormatIterator.Index;
          CurTextIndex = result.CurTextIndex;
        }
        v7 -= v21;
        if ( Index < 0 || Index >= result.FormatIterator.pArray->Ranges.Data.Size )
        {
          CurTextIndex = result.pText->Size;
          result.CurTextIndex = CurTextIndex;
        }
        else
        {
          v25 = &result.FormatIterator.pArray->Ranges.Data.Data[Index];
          if ( CurTextIndex >= v25->Index )
          {
            CurTextIndex += v25->Length;
            result.CurTextIndex = CurTextIndex;
            if ( Index < (signed __int64)result.FormatIterator.pArray->Ranges.Data.Size )
              result.FormatIterator.Index = ++Index;
          }
          else
          {
            CurTextIndex = v25->Index;
            result.CurTextIndex = v25->Index;
          }
        }
        Size = result.pText->Size;
        if ( CurTextIndex >= Size )
          goto LABEL_39;
      }
      pText = result.pText->pText;
      result.PlaceHolder.Length = Size - CurTextIndex;
      goto LABEL_11;
    }
LABEL_39:
    v26 = this->Text.Size;
    if ( v26 )
    {
      v27 = v26 - 1;
      v28 = this->Text.pText;
      if ( !this->Text.pText || (v29 = v27 < v26, v30 = &v28[v27], !v29) )
        v30 = 0i64;
      if ( !*v30 )
      {
        v31 = v26 - 1;
        if ( v28 && v31 < v26 )
          v9 = &v28[v31];
        if ( !*v9 )
          --v26;
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
          &this->FormatInfo,
          v26,
          1ui64);
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
          &this->FormatInfo,
          v26 + 1,
          1ui64);
      }
    }
    ++this->ModCounter;
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
}-- == 1;
      if ( v17 )
      {
     

// File Line: 687
// RVA: 0x93C030
void __fastcall Scaleform::Render::Text::Paragraph::FormatRunIterator::FormatRunIterator(
        Scaleform::Render::Text::Paragraph::FormatRunIterator *this,
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *fmts,
        Scaleform::Render::Text::Paragraph::TextBuffer *textHandle,
        __int64 index)
{
  __int64 NearestRangeIndex; // rax
  unsigned __int64 Size; // rcx
  __int64 v10; // rcx
  __int64 v11; // r8
  __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rcx

  this->PlaceHolder.pText = 0i64;
  this->PlaceHolder.Index = 0i64;
  this->PlaceHolder.Length = 0i64;
  this->PlaceHolder.pFormat.pObject = 0i64;
  this->pFormatInfo = fmts;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)fmts,
                        index);
  this->FormatIterator.pArray = fmts;
  this->FormatIterator.Index = 0i64;
  if ( NearestRangeIndex >= 0 )
  {
    Size = fmts->Ranges.Data.Size;
    if ( NearestRangeIndex >= Size )
      NearestRangeIndex = Size - 1;
    this->FormatIterator.Index = NearestRangeIndex;
  }
  else
  {
    this->FormatIterator.Index = 0i64;
  }
  this->pText = textHandle;
  this->CurTextIndex = 0i64;
  v10 = this->FormatIterator.Index;
  if ( v10 >= 0 && v10 < fmts->Ranges.Data.Size )
  {
    v11 = fmts->Ranges.Data.Data[v10].Index;
    if ( index < v11 || index > (signed __int64)(fmts->Ranges.Data.Data[v10].Length + v11 - 1) )
    {
      v12 = this->FormatIterator.Index;
      if ( index > fmts->Ranges.Data.Data[v12].Index )
      {
        v13 = fmts->Ranges.Data.Data[v12].Index;
        this->CurTextIndex = v13;
        this->CurTextIndex = v13 + fmts->Ranges.Data.Data[this->FormatIterator.Index].Length;
        v14 = this->FormatIterator.Index;
        if ( v14 < (signed __int64)fmts->Ranges.Data.Size )
          this->FormatIterator.Index = v14 + 1;
      }
    }
    else
    {
      this->CurTextIndex = fmts->Ranges.Data.Data[this->FormatIterator.Index].Index;
    }
  }
}

// File Line: 722
// RVA: 0x94ECC0
Scaleform::Render::Text::Paragraph::FormatRunIterator *__fastcall Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(
        Scaleform::Render::Text::Paragraph::FormatRunIterator *this)
{
  __int64 Index; // rax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // rcx
  unsigned __int64 v4; // r8
  __int64 v5; // r9
  unsigned __int64 v6; // rdx
  wchar_t *v7; // rcx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *result; // rax
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  __int64 CurTextIndex; // r8
  unsigned __int64 Size; // rdx
  wchar_t *v12; // rax
  Scaleform::Render::Text::TextFormat *pObject; // rdi

  Index = this->FormatIterator.Index;
  if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
  {
    pText = this->pText;
    CurTextIndex = this->CurTextIndex;
    Size = pText->Size;
    v12 = pText->pText;
    this->PlaceHolder.Index = CurTextIndex;
    this->PlaceHolder.pText = &v12[CurTextIndex];
    this->PlaceHolder.Length = Size - CurTextIndex;
  }
  else
  {
    v4 = pArray->Ranges.Data.Data[Index].Index;
    v5 = (__int64)&pArray->Ranges.Data.Data[Index];
    v6 = this->CurTextIndex;
    v7 = this->pText->pText;
    if ( v6 >= v4 )
      return (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                        &this->PlaceHolder,
                                                                        &v7[v4],
                                                                        v4,
                                                                        *(_QWORD *)(v5 + 8),
                                                                        *(Scaleform::Render::Text::TextFormat **)(v5 + 16));
    this->PlaceHolder.Index = v6;
    this->PlaceHolder.pText = &v7[v6];
    this->PlaceHolder.Length = v4 - v6;
  }
  pObject = this->PlaceHolder.pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  result = this;
  this->PlaceHolder.pFormat.pObject = 0i64;
  return result;
}

// File Line: 791
// RVA: 0x9395F0
void __fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        Scaleform::Render::Text::Paragraph *pparagraph,
        __int64 index)
{
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // rsi
  __int64 NearestRangeIndex; // rcx
  unsigned __int64 Size; // rax
  __int64 v9; // rcx
  signed __int64 v10; // r8
  __int64 v11; // rcx

  this->PlaceHolder.pFormat.pObject = 0i64;
  this->PlaceHolder.Index = 0i64;
  this->PlaceHolder.Character = 0;
  p_FormatInfo = &pparagraph->FormatInfo;
  this->pFormatInfo = &pparagraph->FormatInfo;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        (Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *)&pparagraph->FormatInfo,
                        index);
  this->FormatIterator.pArray = p_FormatInfo;
  this->FormatIterator.Index = 0i64;
  if ( NearestRangeIndex >= 0 )
  {
    Size = p_FormatInfo->Ranges.Data.Size;
    if ( NearestRangeIndex < Size )
      this->FormatIterator.Index = NearestRangeIndex;
    else
      this->FormatIterator.Index = Size - 1;
  }
  else
  {
    this->FormatIterator.Index = 0i64;
  }
  this->pText = (Scaleform::Render::Text::Paragraph::TextBuffer *)pparagraph;
  this->CurTextIndex = index;
  v9 = this->FormatIterator.Index;
  if ( v9 >= 0 && v9 < p_FormatInfo->Ranges.Data.Size )
  {
    v10 = p_FormatInfo->Ranges.Data.Data[v9].Index;
    if ( (index < v10 || index > (signed __int64)(p_FormatInfo->Ranges.Data.Data[v9].Length + v10 - 1))
      && (int)index > p_FormatInfo->Ranges.Data.Data[this->FormatIterator.Index].Index )
    {
      v11 = this->FormatIterator.Index;
      if ( v11 < (signed __int64)p_FormatInfo->Ranges.Data.Size )
        this->FormatIterator.Index = v11 + 1;
    }
  }
}

// File Line: 802
// RVA: 0x94EB90
Scaleform::Render::Text::Paragraph::CharactersIterator *__fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this)
{
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  unsigned __int64 CurTextIndex; // r8
  wchar_t v4; // dx
  __int64 Index; // rax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // rdx
  __int64 v7; // rsi
  Scaleform::Render::Text::TextFormat *v8; // rdi
  bool v9; // zf
  __int64 v10; // rax
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::TextFormat *pObject; // rsi

  pText = this->pText;
  if ( !pText || (CurTextIndex = this->CurTextIndex, CurTextIndex >= pText->Size) )
  {
    this->PlaceHolder.Index = this->CurTextIndex;
    this->PlaceHolder.Character = 0;
    pObject = this->PlaceHolder.pFormat.pObject;
    if ( this->PlaceHolder.pFormat.pObject )
    {
      v9 = pObject->RefCount-- == 1;
      if ( v9 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
    }
    goto LABEL_21;
  }
  v4 = pText->pText[CurTextIndex];
  this->PlaceHolder.Index = CurTextIndex;
  this->PlaceHolder.Character = v4;
  Index = this->FormatIterator.Index;
  if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
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
    this->PlaceHolder.pFormat.pObject = 0i64;
    return this;
  }
  v7 = (__int64)&pArray->Ranges.Data.Data[Index];
  if ( CurTextIndex < *(_QWORD *)v7 )
  {
    v8 = this->PlaceHolder.pFormat.pObject;
    goto LABEL_7;
  }
  v10 = *(_QWORD *)(v7 + 16);
  if ( v10 )
    ++*(_DWORD *)(v10 + 8);
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
  this->PlaceHolder.pFormat.pObject = *(Scaleform::Render::Text::TextFormat **)(v7 + 16);
  return this;
}

// File Line: 855
// RVA: 0x94F1E0
void __fastcall Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        unsigned __int64 n)
{
  unsigned __int64 i; // r10
  Scaleform::Render::Text::Paragraph::TextBuffer *pText; // rax
  unsigned __int64 CurTextIndex; // rdx
  __int64 Index; // r9
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // rax
  __int64 Size; // r11

  for ( i = n; i; --i )
  {
    pText = this->pText;
    if ( pText && (CurTextIndex = this->CurTextIndex, CurTextIndex < pText->Size) )
    {
      this->CurTextIndex = CurTextIndex + 1;
      Index = this->FormatIterator.Index;
      if ( Index >= 0 )
      {
        pArray = this->FormatIterator.pArray;
        Size = pArray->Ranges.Data.Size;
        if ( Index < (unsigned __int64)Size
          && CurTextIndex + 1 >= pArray->Ranges.Data.Data[Index].Index + pArray->Ranges.Data.Data[Index].Length
          && Index < Size )
        {
          this->FormatIterator.Index = Index + 1;
        }
      }
    }
    else
    {
      this->CurTextIndex = pText->Size;
    }
  }
}

// File Line: 885
// RVA: 0x9452D0
void __fastcall Scaleform::Render::Text::StyledText::StyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::Allocator *pallocator)
{
  Scaleform::Render::Text::ParagraphFormat *v4; // rsi
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::TextFormat *TextFormat; // rsi
  Scaleform::Render::Text::TextFormat *v7; // rdi
  Scaleform::Render::Text::ParagraphFormat srcfmt; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // [rsp+80h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::StyledText,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::StyledText::`vftable;
  if ( pallocator )
    ++pallocator->RefCount;
  this->pTextAllocator.pObject = pallocator;
  key = (Scaleform::Render::Text::ParagraphFormat *)&this->Paragraphs;
  p_Paragraphs = &this->Paragraphs;
  this->Paragraphs.Data.Data = 0i64;
  this->Paragraphs.Data.Size = 0i64;
  this->Paragraphs.Data.Policy.Capacity = 0i64;
  this->pDefaultParagraphFormat.pObject = 0i64;
  this->pDefaultTextFormat.pObject = 0i64;
  this->RTFlags = 0;
  srcfmt.pAllocator = 0i64;
  srcfmt.RefCount = 1;
  memset(&srcfmt.pTabStops, 0, 20);
  v4 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(pallocator, &srcfmt);
  pObject = this->pDefaultParagraphFormat.pObject;
  if ( pObject )
    Scaleform::Render::Text::ParagraphFormat::Release(pObject);
  this->pDefaultParagraphFormat.pObject = v4;
  if ( srcfmt.pAllocator )
  {
    key = &srcfmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &srcfmt.pAllocator->ParagraphFormatStorage,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, srcfmt.pTabStops);
  srcfmt.pTabStops = 0i64;
  TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(pallocator, &pallocator->EntryTextFormat);
  v7 = this->pDefaultTextFormat.pObject;
  if ( v7 )
  {
    if ( v7->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v7);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
    }
  }
  this->pDefaultTextFormat.pObject = TextFormat;
}

// File Line: 892
// RVA: 0x959000
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::AppendNewParagraph(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned __int64 Size; // rcx
  unsigned __int64 v5; // r14
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 StartIndex; // r9
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdx
  wchar_t *v10; // rcx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::Paragraph *Paragraph; // rbx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v13; // rdx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  unsigned __int64 v15; // rcx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *Data; // rax
  Scaleform::Render::Text::Paragraph *v17; // rbx

  Size = this->Paragraphs.Data.Size;
  v5 = 0i64;
  if ( Size )
  {
    pPara = this->Paragraphs.Data.Data[Size - 1].pPara;
    StartIndex = pPara->StartIndex;
    v8 = pPara->Text.Size;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( pPara->Text.pText && v9 < v8 )
        v10 = &pPara->Text.pText[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --v8;
    }
    v5 = v8 + StartIndex;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  Paragraph = Scaleform::Render::Text::Allocator::AllocateParagraph(Allocator);
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Paragraphs.Data,
    &this->Paragraphs,
    this->Paragraphs.Data.Size + 1);
  v13 = &this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1];
  if ( v13 )
  {
    v13->pPara = Paragraph;
    Paragraph = 0i64;
  }
  if ( Paragraph )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      Paragraph->FormatInfo.Ranges.Data.Data,
      Paragraph->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Paragraph->FormatInfo.Ranges.Data.Data);
    pObject = Paragraph->pFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Paragraph);
  }
  v15 = this->Paragraphs.Data.Size;
  Data = this->Paragraphs.Data.Data;
  v17 = Data[v15 - 1].pPara;
  if ( !pdefParaFmt )
    pdefParaFmt = this->pDefaultParagraphFormat.pObject;
  Scaleform::Render::Text::Paragraph::SetFormat(Data[v15 - 1].pPara, this->pTextAllocator.pObject, pdefParaFmt);
  v17->StartIndex = v5;
  return v17;
}

// File Line: 913
// RVA: 0x958E30
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::Paragraph *srcPara)
{
  unsigned __int64 Size; // rcx
  unsigned __int64 v5; // rbp
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 StartIndex; // r9
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rdx
  wchar_t *v10; // rcx
  Scaleform::Render::Text::Allocator *Allocator; // rbx
  Scaleform::Render::Text::Paragraph *v12; // rax
  Scaleform::Render::Text::Paragraph *v13; // rax
  Scaleform::Render::Text::Paragraph *v14; // rbx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v15; // rdx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::Paragraph *result; // rax

  Size = this->Paragraphs.Data.Size;
  v5 = 0i64;
  if ( Size )
  {
    pPara = this->Paragraphs.Data.Data[Size - 1].pPara;
    StartIndex = pPara->StartIndex;
    v8 = pPara->Text.Size;
    if ( v8 )
    {
      v9 = v8 - 1;
      if ( pPara->Text.pText && v9 < v8 )
        v10 = &pPara->Text.pText[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --v8;
    }
    v5 = v8 + StartIndex;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v12 = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Allocator->pHeap->vfptr->Alloc)(
                                                Allocator->pHeap,
                                                72i64);
  if ( v12 )
  {
    Scaleform::Render::Text::Paragraph::Paragraph(v12, srcPara, Allocator);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Paragraphs.Data,
    &this->Paragraphs,
    this->Paragraphs.Data.Size + 1);
  v15 = &this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1];
  if ( v15 )
  {
    v15->pPara = v14;
    v14 = 0i64;
  }
  if ( v14 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v14->FormatInfo.Ranges.Data.Data,
      v14->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14->FormatInfo.Ranges.Data.Data);
    pObject = v14->pFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14);
  }
  result = this->Paragraphs.Data.Data[this->Paragraphs.Data.Size - 1].pPara;
  result->StartIndex = v5;
  return result;
}

// File Line: 934
// RVA: 0x995600
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::InsertNewParagraph(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *iter,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rbp
  __int64 CurIndex; // rdi
  unsigned __int64 v6; // r15
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 StartIndex; // r9
  unsigned __int64 Size; // rax
  unsigned __int64 v10; // rdx
  wchar_t *v11; // rcx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::Paragraph *Paragraph; // rbx
  unsigned __int64 v14; // r8
  __int64 v15; // r12
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v16; // rcx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *Data; // rax
  Scaleform::Render::Text::Paragraph *v19; // rbx

  v3 = pdefParaFmt;
  if ( !iter->pArray )
    return Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  CurIndex = iter->CurIndex;
  if ( CurIndex < 0 || CurIndex >= SLODWORD(iter->pArray->Data.Size) )
    return Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v6 = 0i64;
  if ( CurIndex )
  {
    pPara = this->Paragraphs.Data.Data[CurIndex - 1].pPara;
    StartIndex = pPara->StartIndex;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v10 = Size - 1;
      if ( pPara->Text.pText && v10 < Size )
        v11 = &pPara->Text.pText[v10];
      else
        v11 = 0i64;
      if ( !*v11 )
        --Size;
    }
    v6 = Size + StartIndex;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  Paragraph = Scaleform::Render::Text::Allocator::AllocateParagraph(Allocator);
  Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Paragraphs.Data,
    this->Paragraphs.Data.Size + 1);
  v14 = this->Paragraphs.Data.Size;
  if ( CurIndex < v14 - 1 )
    memmove(&this->Paragraphs.Data.Data[CurIndex + 1], &this->Paragraphs.Data.Data[CurIndex], 8 * (v14 - CurIndex) - 8);
  v15 = CurIndex;
  v16 = &this->Paragraphs.Data.Data[CurIndex];
  if ( v16 )
  {
    v16->pPara = Paragraph;
    Paragraph = 0i64;
  }
  if ( Paragraph )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      Paragraph->FormatInfo.Ranges.Data.Data,
      Paragraph->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Paragraph->FormatInfo.Ranges.Data.Data);
    pObject = Paragraph->pFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Paragraph);
  }
  Data = this->Paragraphs.Data.Data;
  v19 = Data[v15].pPara;
  if ( !v3 )
    v3 = this->pDefaultParagraphFormat.pObject;
  Scaleform::Render::Text::Paragraph::SetFormat(Data[v15].pPara, this->pTextAllocator.pObject, v3);
  v19->StartIndex = v6;
  return v19;
}

// File Line: 960
// RVA: 0x994E40
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *iter,
        Scaleform::Render::Text::Paragraph *srcPara)
{
  __int64 CurIndex; // rdi
  unsigned __int64 v6; // rbp
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 StartIndex; // r9
  unsigned __int64 Size; // rax
  unsigned __int64 v10; // rdx
  wchar_t *v11; // rcx
  Scaleform::Render::Text::Allocator *Allocator; // rbx
  Scaleform::Render::Text::Paragraph *v13; // rax
  Scaleform::Render::Text::Paragraph *v14; // rax
  Scaleform::Render::Text::Paragraph *v15; // rbx
  unsigned __int64 v16; // r8
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v17; // rcx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::Paragraph *result; // rax

  if ( !iter->pArray )
    return Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(this, srcPara);
  CurIndex = iter->CurIndex;
  if ( CurIndex < 0 || CurIndex >= SLODWORD(iter->pArray->Data.Size) )
    return Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(this, srcPara);
  v6 = 0i64;
  if ( CurIndex )
  {
    pPara = this->Paragraphs.Data.Data[CurIndex - 1].pPara;
    StartIndex = pPara->StartIndex;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v10 = Size - 1;
      if ( pPara->Text.pText && v10 < Size )
        v11 = &pPara->Text.pText[v10];
      else
        v11 = 0i64;
      if ( !*v11 )
        --Size;
    }
    v6 = Size + StartIndex;
  }
  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v13 = (Scaleform::Render::Text::Paragraph *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Allocator->pHeap->vfptr->Alloc)(
                                                Allocator->pHeap,
                                                72i64);
  if ( v13 )
  {
    Scaleform::Render::Text::Paragraph::Paragraph(v13, srcPara, Allocator);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Paragraphs.Data,
    this->Paragraphs.Data.Size + 1);
  v16 = this->Paragraphs.Data.Size;
  if ( CurIndex < v16 - 1 )
    memmove(&this->Paragraphs.Data.Data[CurIndex + 1], &this->Paragraphs.Data.Data[CurIndex], 8 * (v16 - CurIndex) - 8);
  v17 = &this->Paragraphs.Data.Data[CurIndex];
  if ( v17 )
  {
    v17->pPara = v15;
    v15 = 0i64;
  }
  if ( v15 )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v15->FormatInfo.Ranges.Data.Data,
      v15->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15->FormatInfo.Ranges.Data.Data);
    pObject = v15->pFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
  }
  result = this->Paragraphs.Data.Data[CurIndex].pPara;
  result->StartIndex = v6;
  return result;
}

// File Line: 984
// RVA: 0x987DC0
Scaleform::Render::Text::Paragraph *__fastcall Scaleform::Render::Text::StyledText::GetLastParagraph(
        Scaleform::Render::Text::StyledText *this)
{
  signed __int64 v1; // rdx

  v1 = this->Paragraphs.Data.Size - 1;
  if ( this == (Scaleform::Render::Text::StyledText *)-24i64 || v1 < 0 || v1 >= SLODWORD(this->Paragraphs.Data.Size) )
    return 0i64;
  else
    return this->Paragraphs.Data.Data[v1].pPara;
}

// File Line: 1015
// RVA: 0x959480
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        char *putf8String,
        unsigned __int64 stringSize,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  char *v6; // rdi
  const char *v8; // r12
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdx
  unsigned __int64 Size; // rcx
  int v11; // ebx
  __int64 v12; // rcx
  Scaleform::Render::Text::Paragraph *pPara; // r13
  unsigned __int64 StartIndex; // rbp
  Scaleform::Render::Text::ParagraphFormat *v15; // rsi
  int v16; // ecx
  unsigned __int64 v17; // rbp
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  int v20; // esi
  unsigned __int64 v21; // r14
  unsigned int Char_Advance0; // eax
  char *v23; // rcx
  wchar_t *Position; // rsi
  unsigned int v25; // eax
  int v26; // eax
  int v27; // eax
  Scaleform::Render::Text::TextFormat *v28; // rbx
  bool v29; // zf
  unsigned __int64 result; // rax
  unsigned __int64 v31; // [rsp+30h] [rbp-68h]
  unsigned __int64 v32; // [rsp+38h] [rbp-60h]
  Scaleform::Render::Text::Paragraph *v33; // [rsp+40h] [rbp-58h]
  int v34; // [rsp+A0h] [rbp+8h]
  char *putf8Buffer; // [rsp+A8h] [rbp+10h] BYREF
  unsigned __int64 v36; // [rsp+B0h] [rbp+18h]
  Scaleform::Render::Text::StyledText::NewLinePolicy v37; // [rsp+B8h] [rbp+20h]

  v37 = newLinePolicy;
  v6 = putf8String;
  if ( stringSize == -1i64 )
  {
    do
      ++stringSize;
    while ( putf8String[stringSize] );
  }
  v8 = &putf8String[stringSize];
  p_Paragraphs = &this->Paragraphs;
  Size = this->Paragraphs.Data.Size;
  v11 = 0;
  v36 = 0i64;
  v12 = Size - 1;
  if ( !p_Paragraphs || v12 < 0 || v12 >= SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = 0i64;
    v33 = 0i64;
    goto LABEL_9;
  }
  pPara = p_Paragraphs->Data.Data[v12].pPara;
  v33 = pPara;
  if ( !pPara )
  {
LABEL_9:
    StartIndex = 0i64;
    goto LABEL_10;
  }
  StartIndex = pPara->StartIndex;
LABEL_10:
  v31 = StartIndex;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))this->vfptr[1].__vecDelDtor)(
    this,
    StartIndex,
    stringSize,
    v6);
  v15 = pdefParaFmt;
  v16 = 0;
  do
  {
    v34 = v16 + 1;
    if ( v16 || !pPara )
    {
      v17 = 0i64;
      pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, v15);
      v33 = pPara;
      pPara->StartIndex = v31;
      v32 = 0i64;
    }
    else
    {
      Scaleform::Render::Text::Paragraph::RemoveTermNull(pPara);
      v17 = pPara->Text.Size;
      v32 = v17;
      if ( !v17 )
        goto LABEL_21;
      v18 = v17 - 1;
      if ( pPara->Text.pText && v18 < v17 )
        v19 = &pPara->Text.pText[v18];
      else
        v19 = 0i64;
      if ( !*v19 )
        v32 = --v17;
      if ( !v17 )
      {
LABEL_21:
        if ( v15 )
          Scaleform::Render::Text::Paragraph::SetFormat(pPara, this->pTextAllocator.pObject, v15);
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
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v23 = putf8Buffer;
      if ( !Char_Advance0 )
        v23 = --putf8Buffer;
      if ( v37 || v20 != 13 || v21 || (v20 = -1, Char_Advance0 != 10) )
      {
        v11 = Char_Advance0;
        if ( Char_Advance0 == 10 )
          goto LABEL_39;
        if ( Char_Advance0 == 13 )
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
      Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(
                   &pPara->Text,
                   this->pTextAllocator.pObject,
                   v17,
                   v21);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        v17,
        v21);
      ++pPara->ModCounter;
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
            v6 = --putf8Buffer;
          if ( v25 == 13 || v25 == 10 )
          {
            v11 = 10;
            if ( (this->RTFlags & 2) != 0 )
              v11 = 13;
          }
          *Position++ = v11;
          v26 = 10;
          if ( (this->RTFlags & 2) != 0 )
            v26 = 13;
        }
        while ( v11 != v26 && v6 < v8 );
        v17 = v32;
        pPara = v33;
      }
      Scaleform::Render::Text::Paragraph::SetTextFormat(
        pPara,
        this->pTextAllocator.pObject,
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
  if ( (this->RTFlags & 2) != 0 )
    v27 = 13;
  if ( v11 == v27 )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, pdefParaFmt);
  v28 = pdefTextFmt;
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, this->pTextAllocator.pObject, pdefTextFmt);
  if ( (v28->PresentMask & 0x100) == 0 )
    return v36;
  v29 = Scaleform::String::GetLength(&v28->Url) == 0;
  result = v36;
  if ( !v29 )
    this->RTFlags |= 1u;
  return result;
}

// File Line: 1127
// RVA: 0x9597C0
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::AppendString(
        Scaleform::Render::Text::StyledText *this,
        const wchar_t *pstr,
        unsigned __int64 length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  int v6; // esi
  const wchar_t *v7; // r12
  unsigned __int64 v8; // rbp
  Scaleform::Render::Text::StyledText *v9; // r13
  unsigned __int64 Size; // r14
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rcx
  __int64 v12; // r14
  Scaleform::Render::Text::Paragraph *pPara; // r14
  unsigned __int64 StartIndex; // rbx
  Scaleform::Render::Text::ParagraphFormat *v15; // rdi
  int v16; // ecx
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // rax
  wchar_t *v19; // rax
  Scaleform::Render::Text::Paragraph *appended; // rax
  unsigned __int64 v21; // rbx
  wchar_t *v22; // r13
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rdx
  wchar_t *v25; // rax
  unsigned __int64 v26; // r8
  wchar_t *pText; // rax
  int v28; // eax
  unsigned __int64 v29; // rdx
  unsigned __int64 v30; // rax
  wchar_t *v31; // rax
  unsigned __int8 v32; // al
  unsigned __int64 v33; // r15
  int v34; // eax
  unsigned __int64 v35; // rdi
  __int64 v36; // rbx
  __int64 v37; // rax
  unsigned __int64 result; // rax
  __int64 v39; // [rsp+30h] [rbp-58h]
  const wchar_t *v40; // [rsp+38h] [rbp-50h]
  int v42; // [rsp+98h] [rbp+10h]
  unsigned __int64 v43; // [rsp+A0h] [rbp+18h]

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
  Size = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v12 = Size - 1;
  v40 = &pstr[v8];
  if ( !p_Paragraphs || v12 < 0 || v12 >= SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = 0i64;
    goto LABEL_10;
  }
  pPara = p_Paragraphs->Data.Data[v12].pPara;
  if ( !pPara )
  {
LABEL_10:
    StartIndex = 0i64;
    goto LABEL_11;
  }
  StartIndex = pPara->StartIndex;
LABEL_11:
  v43 = StartIndex;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, const wchar_t *))v9->vfptr[2].__vecDelDtor)(
    v9,
    StartIndex,
    v8,
    pstr);
  v15 = pdefParaFmt;
  v39 = 0i64;
  v16 = 0;
  while ( 1 )
  {
    v42 = v16 + 1;
    if ( v16 || !pPara )
    {
      appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(v9, v15);
      v17 = 0i64;
      appended->StartIndex = StartIndex;
      pPara = appended;
    }
    else
    {
      Scaleform::Render::Text::Paragraph::RemoveTermNull(pPara);
      v17 = pPara->Text.Size;
      if ( !v17 )
        goto LABEL_22;
      v18 = v17 - 1;
      if ( pPara->Text.pText && v18 < v17 )
        v19 = &pPara->Text.pText[v18];
      else
        v19 = 0i64;
      if ( !*v19 )
        --v17;
      if ( !v17 )
      {
LABEL_22:
        if ( v15 )
          Scaleform::Render::Text::Paragraph::SetFormat(pPara, v9->pTextAllocator.pObject, v15);
      }
    }
    v21 = 0i64;
    if ( newLinePolicy == NLP_CompressCRLF && v6 == 13 && *v7 == 10 )
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
      v23 = pPara->Text.Size;
      v24 = v23 + v21;
      if ( pPara->Text.Allocated < v23 + v21 )
      {
        if ( pPara->Text.pText )
          v25 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                             Scaleform::Memory::pGlobalHeap,
                             pPara->Text.pText,
                             2 * v24);
        else
          v25 = (wchar_t *)v9->pTextAllocator.pObject->pHeap->vfptr->Alloc(
                             v9->pTextAllocator.pObject->pHeap,
                             2 * v24,
                             0i64);
        v23 = pPara->Text.Size;
        pPara->Text.pText = v25;
        pPara->Text.Allocated = v23 + v21;
      }
      v26 = v23 - v17;
      if ( v26 )
        memmove(&pPara->Text.pText[v21 + v17], &pPara->Text.pText[v17], 2 * v26);
      pText = pPara->Text.pText;
      pPara->Text.Size += v21;
      v22 = &pText[v17];
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &pPara->FormatInfo,
        v17,
        v21);
      ++pPara->ModCounter;
    }
    else
    {
      v22 = 0i64;
    }
    memmove(v22, v7, 2 * v21);
    v7 += v21;
    v8 -= v21;
    if ( v6 == 10 || v6 == 13 )
    {
      v9 = this;
      v28 = 10;
      if ( (this->RTFlags & 2) != 0 )
        v28 = 13;
      if ( v6 != v28 )
      {
        v29 = pPara->Text.Size;
        if ( v29 )
        {
          v30 = v29 - 1;
          if ( pPara->Text.pText && v30 < v29 )
            v31 = &pPara->Text.pText[v30];
          else
            v31 = 0i64;
          if ( !*v31 )
            --v29;
          if ( v29 )
          {
            v32 = 10;
            if ( (this->RTFlags & 2) != 0 )
              v32 = 13;
            pPara->Text.pText[v29 - 1] = v32;
          }
        }
        v6 = 10;
        if ( (this->RTFlags & 2) != 0 )
          v6 = 13;
      }
    }
    else
    {
      v9 = this;
    }
    Scaleform::Render::Text::Paragraph::SetTextFormat(
      pPara,
      v9->pTextAllocator.pObject,
      pdefTextFmt,
      v17,
      0xFFFFFFFFFFFFFFFFui64);
    v43 += v21 + v17;
    v33 = v21 + v39;
    v39 += v21;
    if ( v7 < v40 )
    {
      v15 = pdefParaFmt;
      v16 = v42;
      StartIndex = v43;
      if ( v6 )
        continue;
    }
    v15 = pdefParaFmt;
    goto LABEL_71;
  }
  v33 = v39;
LABEL_71:
  v34 = 10;
  if ( (v9->RTFlags & 2) != 0 )
    v34 = 13;
  if ( v6 == v34 )
    pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(v9, v15);
  Scaleform::Render::Text::Paragraph::AppendTermNull(pPara, v9->pTextAllocator.pObject, pdefTextFmt);
  if ( (pdefTextFmt->PresentMask & 0x100) == 0 )
    return v33;
  v35 = pdefTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v36 = *(_QWORD *)v35 & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(__int64 *)v35 >= 0 )
  {
    v37 = Scaleform::UTF8Util::GetLength((const char *)(v35 + 12), *(_QWORD *)v35 & 0x7FFFFFFFFFFFFFFFi64);
    if ( v37 == v36 )
      *(_QWORD *)v35 |= 0x8000000000000000ui64;
    v36 = v37;
  }
  result = v33;
  if ( v36 )
    v9->RTFlags |= 1u;
  return result;
}

// File Line: 1236
// RVA: 0x98A2A0
Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *__fastcall Scaleform::Render::Text::StyledText::GetParagraphByIndex(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *result,
        unsigned __int64 index,
        unsigned __int64 *pindexInParagraph)
{
  __int64 Size; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rsi
  unsigned __int64 v6; // rbx
  unsigned __int64 v10; // r9
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // rdx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator *v15; // rax

  Size = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v6 = 0i64;
  while ( Size > 0 )
  {
    v10 = (Size >> 1) + v6;
    pPara = p_Paragraphs->Data.Data[v10].pPara;
    StartIndex = pPara->StartIndex;
    if ( index >= StartIndex && index < StartIndex + pPara->Text.Size || (int)StartIndex - (int)index >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v6 = v10 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v6 < this->Paragraphs.Data.Size
    && ((v13 = p_Paragraphs->Data.Data[v6].pPara, v14 = v13->StartIndex, index >= v14) && index < v14 + v13->Text.Size
     || (_DWORD)v14 == (_DWORD)index) )
  {
    if ( pindexInParagraph )
      *pindexInParagraph = index - p_Paragraphs->Data.Data[(int)v6].pPara->StartIndex;
    result->pArray = p_Paragraphs;
    v15 = result;
    result->CurIndex = (int)v6;
  }
  else
  {
    result->pArray = 0i64;
    result->CurIndex = -1i64;
    return result;
  }
  return v15;
}

// File Line: 1266
// RVA: 0x970DA0
void __fastcall Scaleform::Render::Text::StyledText::EnsureTermNull(Scaleform::Render::Text::StyledText *this)
{
  signed __int64 v2; // rdx
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 Size; // rcx
  unsigned __int64 v5; // rdx
  wchar_t *v6; // rcx
  wchar_t v7; // cx

  v2 = this->Paragraphs.Data.Size - 1;
  if ( this != (Scaleform::Render::Text::StyledText *)-24i64
    && v2 >= 0
    && v2 < SLODWORD(this->Paragraphs.Data.Size)
    && (pPara = this->Paragraphs.Data.Data[v2].pPara) != 0i64
    || (pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0i64)) != 0i64 )
  {
    Size = pPara->Text.Size;
    if ( !Size
      || ((v5 = Size - 1, !pPara->Text.pText) || v5 >= Size ? (v6 = 0i64) : (v6 = &pPara->Text.pText[v5]),
          (v7 = *v6, v7 != 10) && v7 != 13) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        pPara,
        this->pTextAllocator.pObject,
        this->pDefaultTextFormat.pObject);
    }
  }
}

// File Line: 1277
// RVA: 0x9B4A30
void __fastcall Scaleform::Render::Text::StyledText::SetTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *fmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  __int64 Size; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r15
  unsigned __int64 v6; // rbx
  __int64 v7; // rdi
  unsigned __int64 v12; // r9
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v15; // rax
  unsigned __int64 v16; // rdx
  unsigned __int64 v17; // rbp
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v18; // r14
  __int64 v19; // rsi
  Scaleform::Render::Text::Paragraph *v20; // r10
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rdx
  wchar_t *v24; // rdx
  unsigned __int64 v25; // rbx
  unsigned __int64 v26; // rax
  wchar_t *v27; // rax
  unsigned __int64 v28; // [rsp+70h] [rbp+8h]

  Size = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v6 = 0i64;
  v7 = -1i64;
  while ( Size > 0 )
  {
    v12 = (Size >> 1) + v6;
    pPara = p_Paragraphs->Data.Data[v12].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v6 = v12 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v6 < this->Paragraphs.Data.Size
    && ((v15 = p_Paragraphs->Data.Data[v6].pPara, v16 = v15->StartIndex, startPos >= v16)
     && startPos < v16 + v15->Text.Size
     || (_DWORD)v16 == (_DWORD)startPos) )
  {
    v17 = startPos - p_Paragraphs->Data.Data[(int)v6].pPara->StartIndex;
    v7 = (int)v6;
    v18 = &this->Paragraphs;
  }
  else
  {
    v17 = v28;
    v18 = 0i64;
  }
  v19 = endPos - startPos;
  while ( v18 && v7 >= 0 && v7 < SLODWORD(v18->Data.Size) )
  {
    v20 = v18->Data.Data[v7].pPara;
    v21 = v20->Text.Size;
    v22 = v21;
    if ( v21 )
    {
      v23 = v21 - 1;
      if ( v20->Text.pText && v23 < v21 )
        v24 = &v20->Text.pText[v23];
      else
        v24 = 0i64;
      if ( !*v24 )
        v22 = v21 - 1;
    }
    v25 = v19 + v17;
    if ( v19 + v17 <= v22 )
    {
      if ( v19 + v17 != v22 )
        goto LABEL_36;
    }
    else
    {
      v25 = v22;
    }
    if ( v21 )
    {
      v26 = v21 - 1;
      if ( v20->Text.pText && v26 < v21 )
        v27 = &v20->Text.pText[v26];
      else
        v27 = 0i64;
      if ( !*v27 )
      {
        ++v25;
        if ( v19 != -1 )
          ++v19;
      }
    }
LABEL_36:
    Scaleform::Render::Text::Paragraph::SetTextFormat(
      v18->Data.Data[v7].pPara,
      this->pTextAllocator.pObject,
      fmt,
      v17,
      v25);
    v19 += v17 - v25;
    v17 = 0i64;
    if ( v7 < (signed __int64)v18->Data.Size )
      ++v7;
  }
  if ( (fmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&fmt->Url) )
    this->RTFlags |= 1u;
}

// File Line: 1312
// RVA: 0x9B2570
void __fastcall Scaleform::Render::Text::StyledText::SetParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *fmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  __int64 Size; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r14
  unsigned __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned __int64 v12; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v15; // rax
  unsigned __int64 v16; // rdx
  __int64 v17; // rdi
  unsigned __int64 v18; // r15
  Scaleform::Render::Text::Paragraph *v19; // rsi
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rcx
  wchar_t *v22; // rcx
  __int64 v23; // [rsp+28h] [rbp-30h]
  __int64 v24; // [rsp+60h] [rbp+8h]

  Size = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v6 = 0i64;
  v7 = -1i64;
  while ( Size > 0 )
  {
    v12 = (Size >> 1) + v6;
    pPara = p_Paragraphs->Data.Data[v12].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v6 = v12 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v6 < this->Paragraphs.Data.Size
    && ((v15 = p_Paragraphs->Data.Data[v6].pPara, v16 = v15->StartIndex, startPos >= v16)
     && startPos < v16 + v15->Text.Size
     || (_DWORD)v16 == (_DWORD)startPos) )
  {
    v23 = (int)v6;
    v17 = startPos - p_Paragraphs->Data.Data[(int)v6].pPara->StartIndex;
    v7 = v23;
  }
  else
  {
    v17 = v24;
    p_Paragraphs = 0i64;
  }
  v18 = endPos - startPos;
  while ( p_Paragraphs && v7 >= 0 && v7 < SLODWORD(p_Paragraphs->Data.Size) )
  {
    v19 = p_Paragraphs->Data.Data[v7].pPara;
    if ( !v17 )
      Scaleform::Render::Text::Paragraph::SetFormat(
        p_Paragraphs->Data.Data[v7].pPara,
        this->pTextAllocator.pObject,
        fmt);
    if ( !v18 )
      break;
    v20 = v19->Text.Size;
    if ( v20 )
    {
      v21 = v20 - 1;
      if ( v19->Text.pText && v21 < v20 )
        v22 = &v19->Text.pText[v21];
      else
        v22 = 0i64;
      if ( !*v22 )
        --v20;
    }
    if ( v18 <= v20 )
      v20 = v18 + v17;
    v18 += v17 - v20;
    v17 = 0i64;
    if ( v7 < (signed __int64)p_Paragraphs->Data.Size )
      ++v7;
  }
}

// File Line: 1375
// RVA: 0x98CAA0
void __fastcall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *pdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdestParaFmt,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v5; // r12
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdi
  __int64 Size; // r10
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v12; // rax
  unsigned __int64 v13; // rdx
  __int64 v14; // r15
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v15; // r13
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
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::Render::Text::TextFormat *TextFormat; // rax
  Scaleform::Render::Text::TextFormat *v33; // rax
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v35; // rcx
  Scaleform::Render::Text::FontHandle *v36; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v37; // rcx
  Scaleform::Render::Text::ParagraphFormat *v38; // rcx
  unsigned int *v39; // rsi
  __int64 v40; // rdi
  unsigned int *v41; // r9
  Scaleform::Render::Text::ParagraphFormat *v42; // rax
  unsigned int *pTabStops; // rsi
  __int64 v44; // rdi
  unsigned int *v45; // r9
  Scaleform::Render::Text::ParagraphFormat v46; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v47[2]; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v49; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::Render::Text::TextFormat *key; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::Render::Text::TextFormat *v51; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::Render::Text::TextFormat *v52[2]; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::Render::Text::ParagraphFormat v53; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::Render::Text::TextFormat result; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::Render::Text::TextFormat v55; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::Render::Text::TextFormat v56; // [rsp+1A0h] [rbp+A0h] BYREF
  int v57; // [rsp+240h] [rbp+140h]
  unsigned __int64 startPosa; // [rsp+258h] [rbp+158h]
  int endPosa; // [rsp+260h] [rbp+160h]

  v52[1] = (Scaleform::Render::Text::TextFormat *)-2i64;
  v5 = endPos - startPos;
  p_Paragraphs = &this->Paragraphs;
  Size = this->Paragraphs.Data.Size;
  v8 = 0i64;
  while ( Size > 0 )
  {
    v9 = (Size >> 1) + v8;
    pPara = p_Paragraphs->Data.Data[v9].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v8 = v9 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v8 < this->Paragraphs.Data.Size
    && ((v12 = p_Paragraphs->Data.Data[v8].pPara, v13 = v12->StartIndex, startPos >= v13)
     && startPos < v13 + v12->Text.Size
     || (_DWORD)v13 == (_DWORD)startPos) )
  {
    v47[0] = (Scaleform::Render::Text::ParagraphFormat *)&this->Paragraphs;
    v47[1] = (Scaleform::Render::Text::ParagraphFormat *)(int)v8;
    startPosa = startPos - p_Paragraphs->Data.Data[(int)v8].pPara->StartIndex;
    v14 = (int)v8;
    v15 = &this->Paragraphs;
  }
  else
  {
    v15 = 0i64;
    v14 = -1i64;
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
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  v19 = Scaleform::Memory::pGlobalHeap;
  if ( v17 )
    v19 = v17;
  fmt.Url.pHeap = v19;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  fmt.pImageDesc.pObject = 0i64;
  fmt.pFontHandle.pObject = 0i64;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0.0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  v46.pAllocator = 0i64;
  v46.RefCount = 1;
  memset(&v46.pTabStops, 0, 20);
  v20 = 0;
  endPosa = 0;
  v21 = 0;
  if ( v5 )
  {
    v22 = startPosa;
    do
    {
      if ( !v15 || v14 < 0 || v14 >= SLODWORD(v15->Data.Size) )
        break;
      v23 = v15->Data.Data[v14].pPara;
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
        TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(v23, &v56, v22, v27);
        v33 = Scaleform::Render::Text::TextFormat::Intersection(TextFormat, &v55, &fmt);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v33);
        if ( v55.pAllocator )
        {
          v52[0] = &v55;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            &v55.pAllocator->TextFormatStorage,
            v52);
        }
        pObject = v55.pFontHandle.pObject;
        if ( v55.pFontHandle.pObject && !_InterlockedDecrement(&v55.pFontHandle.pObject->RefCount) && pObject )
          pObject->vfptr->__vecDelDtor(pObject, 1u);
        v35 = v55.pImageDesc.pObject;
        if ( v55.pImageDesc.pObject )
        {
          --v55.pImageDesc.pObject->RefCount;
          if ( !v35->RefCount )
            v35->vfptr->__vecDelDtor(v35, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v55.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( v56.pAllocator )
        {
          v51 = &v56;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            &v56.pAllocator->TextFormatStorage,
            &v51);
        }
        v36 = v56.pFontHandle.pObject;
        if ( v56.pFontHandle.pObject && !_InterlockedDecrement(&v56.pFontHandle.pObject->RefCount) && v36 )
          v36->vfptr->__vecDelDtor(v36, 1u);
        v37 = v56.pImageDesc.pObject;
        if ( v56.pImageDesc.pObject )
        {
          --v56.pImageDesc.pObject->RefCount;
          if ( !v37->RefCount )
            v37->vfptr->__vecDelDtor(v37, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v56.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pData = v56.FontList.pData;
      }
      else
      {
        v28 = Scaleform::Render::Text::Paragraph::GetTextFormat(v23, &result, v22, v27);
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v28);
        if ( result.pAllocator )
        {
          key = &result;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
            &result.pAllocator->TextFormatStorage,
            &key);
        }
        v29 = result.pFontHandle.pObject;
        if ( result.pFontHandle.pObject && !_InterlockedDecrement(&result.pFontHandle.pObject->RefCount) && v29 )
          v29->vfptr->__vecDelDtor(v29, 1u);
        v30 = result.pImageDesc.pObject;
        if ( result.pImageDesc.pObject )
        {
          --result.pImageDesc.pObject->RefCount;
          if ( !v30->RefCount )
            v30->vfptr->__vecDelDtor(v30, 1u);
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((result.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pData = result.FontList.pData;
      }
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v22 = startPosa;
      if ( !startPosa )
      {
        v38 = v23->pFormat.pObject;
        if ( v38 )
        {
          v57 = v21 + 1;
          if ( v21 )
          {
            v42 = Scaleform::Render::Text::ParagraphFormat::Intersection(v38, &v53, &v46);
            v46.BlockIndent = v42->BlockIndent;
            v46.Indent = v42->Indent;
            v46.Leading = v42->Leading;
            v46.LeftMargin = v42->LeftMargin;
            v46.RightMargin = v42->RightMargin;
            v46.PresentMask = v42->PresentMask;
            pTabStops = v42->pTabStops;
            if ( pTabStops )
            {
              v44 = *pTabStops;
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
              memmove(v45 + 1, pTabStops + 1, 4 * v44);
            }
            else
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
              v46.pTabStops = 0i64;
            }
            if ( v53.pAllocator )
            {
              v49 = &v53;
              Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
                &v53.pAllocator->ParagraphFormatStorage,
                &v49);
            }
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v53.pTabStops);
            v53.pTabStops = 0i64;
            v21 = v57;
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
              v21 = v57;
            }
            else
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
              v46.pTabStops = 0i64;
              v21 = v57;
            }
          }
        }
      }
      v5 -= v24;
      if ( v14 < (signed __int64)v15->Data.Size )
        ++v14;
      v20 = endPosa;
    }
    while ( v5 );
  }
  if ( pdestTextFmt )
    Scaleform::Render::Text::TextFormat::operator=(pdestTextFmt, &fmt);
  if ( pdestParaFmt )
  {
    pdestParaFmt->BlockIndent = v46.BlockIndent;
    pdestParaFmt->Indent = v46.Indent;
    pdestParaFmt->Leading = v46.Leading;
    pdestParaFmt->LeftMargin = v46.LeftMargin;
    pdestParaFmt->RightMargin = v46.RightMargin;
    pdestParaFmt->PresentMask = v46.PresentMask;
    Scaleform::Render::Text::ParagraphFormat::CopyTabStops(pdestParaFmt, v46.pTabStops);
  }
  if ( v46.pAllocator )
  {
    v47[0] = &v46;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &v46.pAllocator->ParagraphFormatStorage,
      v47);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v46.pTabStops);
  v46.pTabStops = 0i64;
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}v46.pTabStops = 0i64;
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 1421
// RVA: 0x98D250
__int64 __fastcall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat **ppdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat **ppdestParaFmt,
        unsigned __int64 pos)
{
  Scaleform::Render::Text::ParagraphFormat *v4; // rsi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r15
  __int64 v7; // rdi
  __int64 Size; // r9
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v16; // rax
  unsigned __int64 v17; // rdx
  unsigned __int64 v18; // r10
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *v19; // rdx
  unsigned __int8 v20; // cl
  Scaleform::Render::Text::Paragraph *v21; // rbx
  Scaleform::Render::Text::TextFormat *pObject; // rax
  __int64 result; // rax
  unsigned __int64 v24; // [rsp+60h] [rbp+8h]

  v4 = 0i64;
  p_Paragraphs = &this->Paragraphs;
  v7 = -1i64;
  Size = this->Paragraphs.Data.Size;
  v12 = 0i64;
  while ( Size > 0 )
  {
    v13 = (Size >> 1) + v12;
    pPara = p_Paragraphs->Data.Data[v13].pPara;
    StartIndex = pPara->StartIndex;
    if ( pos >= StartIndex && pos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)pos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v12 = v13 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v12 < this->Paragraphs.Data.Size
    && ((v16 = p_Paragraphs->Data.Data[v12].pPara, v17 = v16->StartIndex, pos >= v17) && pos < v17 + v16->Text.Size
     || (_DWORD)v17 == (_DWORD)pos) )
  {
    v18 = pos - p_Paragraphs->Data.Data[(int)v12].pPara->StartIndex;
    v7 = (int)v12;
    v19 = &this->Paragraphs;
  }
  else
  {
    v18 = v24;
    v19 = 0i64;
  }
  v20 = 0;
  if ( !v19
    || v7 < 0
    || v7 >= SLODWORD(v19->Data.Size)
    || (v21 = v19->Data.Data[v7].pPara,
        pObject = Scaleform::Render::Text::Paragraph::GetTextFormatPtr(v21, v18),
        v4 = v21->pFormat.pObject,
        v20 = 1,
        !pObject) )
  {
    pObject = this->pDefaultTextFormat.pObject;
  }
  if ( !v4 )
    v4 = this->pDefaultParagraphFormat.pObject;
  if ( ppdestTextFmt )
    *ppdestTextFmt = pObject;
  result = v20;
  if ( ppdestParaFmt )
    *ppdestParaFmt = v4;
  return result;
}

// File Line: 1449
// RVA: 0x9AF040
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *defaultTextFmt)
{
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // rcx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::TextFormat *v6; // rsi
  Scaleform::Render::Text::TextFormat *v7; // rdi
  bool v8; // zf
  Scaleform::Render::Text::Allocator *v9; // rax
  Scaleform::Render::Text::TextFormat *TextFormat; // rsi
  Scaleform::Render::Text::TextFormat *v11; // rdi
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-58h] BYREF

  if ( Scaleform::Render::Text::TextFormat::GetImageDesc(defaultTextFmt) )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(&srcfmt, defaultTextFmt, 0i64);
    pObject = srcfmt.pImageDesc.pObject;
    if ( srcfmt.pImageDesc.pObject )
    {
      --srcfmt.pImageDesc.pObject->RefCount;
      if ( !pObject->RefCount )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    srcfmt.pImageDesc.pObject = 0i64;
    srcfmt.PresentMask |= 0x200u;
    Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
    v6 = Scaleform::Render::Text::Allocator::AllocateTextFormat(Allocator, &srcfmt);
    v7 = this->pDefaultTextFormat.pObject;
    if ( v7 )
    {
      v8 = v7->RefCount-- == 1;
      if ( v8 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v7);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
    }
    this->pDefaultTextFormat.pObject = v6;
    Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  }
  else
  {
    v9 = Scaleform::Render::Text::StyledText::GetAllocator(this);
    TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(v9, defaultTextFmt);
    v11 = this->pDefaultTextFormat.pObject;
    if ( v11 )
    {
      v8 = v11->RefCount-- == 1;
      if ( v8 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v11);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
    }
    this->pDefaultTextFormat.pObject = TextFormat;
  }
}

// File Line: 1462
// RVA: 0x9AEDD0
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *defaultParagraphFmt)
{
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // rax
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::ParagraphFormat *v7; // rbx

  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(Allocator, defaultParagraphFmt);
  pObject = this->pDefaultParagraphFormat.pObject;
  v7 = ParagraphFormat;
  if ( pObject )
  {
    Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    this->pDefaultParagraphFormat.pObject = v7;
  }
  else
  {
    this->pDefaultParagraphFormat.pObject = ParagraphFormat;
  }
}

// File Line: 1468
// RVA: 0x9AF160
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat *pdefaultTextFmt)
{
  Scaleform::Render::Text::TextFormat *pObject; // rdi

  if ( Scaleform::Render::Text::TextFormat::GetImageDesc(pdefaultTextFmt) )
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this, pdefaultTextFmt);
  }
  else
  {
    if ( pdefaultTextFmt )
      ++pdefaultTextFmt->RefCount;
    pObject = this->pDefaultTextFormat.pObject;
    if ( pObject )
    {
      if ( pObject->RefCount-- == 1 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
    }
    this->pDefaultTextFormat.pObject = pdefaultTextFmt;
  }
}

// File Line: 1481
// RVA: 0x9AEE20
void __fastcall Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::ParagraphFormat *pdefaultParagraphFmt)
{
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx

  if ( pdefaultParagraphFmt )
    ++pdefaultParagraphFmt->RefCount;
  pObject = this->pDefaultParagraphFormat.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    this->pDefaultParagraphFormat.pObject = pdefaultParagraphFmt;
  }
  else
  {
    this->pDefaultParagraphFormat.pObject = pdefaultParagraphFmt;
  }
}

// File Line: 1487
// RVA: 0x985480
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetHtml(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *result)
{
  Scaleform::StringBuffer *Html; // rax
  Scaleform::StringBuffer v5; // [rsp+30h] [rbp-38h] BYREF

  memset(&v5, 0, 24);
  v5.GrowSize = 512i64;
  v5.LengthIsSize = 0;
  v5.pHeap = Scaleform::Memory::pGlobalHeap;
  Html = Scaleform::Render::Text::StyledText::GetHtml(this, &v5);
  Scaleform::String::String(result, Html);
  if ( v5.pData )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 1501
// RVA: 0x985500
Scaleform::Render::Text::StyledText::GetHtml

// File Line: 1692
// RVA: 0x988430
__int64 __fastcall Scaleform::Render::Text::StyledText::GetLength(Scaleform::Render::Text::StyledText *this)
{
  __int64 v1; // r9
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdx
  __int64 v3; // rcx
  Scaleform::Render::Text::Paragraph *pPara; // r10
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // r8
  wchar_t *v7; // r8

  v1 = 0i64;
  p_Paragraphs = &this->Paragraphs;
  v3 = 0i64;
  while ( p_Paragraphs && v3 >= 0 && v3 < SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = p_Paragraphs->Data.Data[v3].pPara;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v6 = Size - 1;
      if ( pPara->Text.pText && v6 < Size )
        v7 = &pPara->Text.pText[v6];
      else
        v7 = 0i64;
      if ( !*v7 )
        --Size;
    }
    v1 += Size;
    if ( v3 < (signed __int64)p_Paragraphs->Data.Size )
      ++v3;
  }
  return v1;
}

// File Line: 1705
// RVA: 0x98C6A0
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *result)
{
  result->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  Scaleform::Render::Text::StyledText::GetText(this, result);
  return result;
}

// File Line: 1712
// RVA: 0x98C6F0
Scaleform::String *__fastcall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *retStr)
{
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdi
  __int64 v5; // rbx
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 Size; // r8
  const wchar_t *pText; // rdx
  unsigned __int64 v9; // rax
  const wchar_t *v10; // rax

  Scaleform::String::AssignString(retStr, &customCaption, 0i64);
  p_Paragraphs = &this->Paragraphs;
  v5 = 0i64;
  while ( p_Paragraphs && v5 >= 0 && v5 < SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = p_Paragraphs->Data.Data[v5].pPara;
    Size = pPara->Text.Size;
    pText = pPara->Text.pText;
    if ( Size )
    {
      v9 = Size - 1;
      if ( pText && v9 < Size )
        v10 = &pText[v9];
      else
        v10 = 0i64;
      if ( !*v10 )
        --Size;
    }
    Scaleform::String::AppendString(retStr, pText, Size);
    if ( v5 < (signed __int64)p_Paragraphs->Data.Size )
      ++v5;
  }
  return retStr;
}

// File Line: 1727
// RVA: 0x98C790
void __fastcall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer)
{
  __int64 Length; // rax
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rsi
  __int64 v6; // rdi
  __int64 v7; // rbp
  Scaleform::Render::Text::Paragraph *pPara; // rbx
  wchar_t *pText; // rdx
  unsigned __int64 Size; // rbx
  unsigned __int64 v11; // rax
  bool v12; // cf
  char *v13; // rax

  Length = Scaleform::Render::Text::StyledText::GetLength(this);
  Scaleform::WStringBuffer::Resize(pBuffer, Length + 1);
  p_Paragraphs = &this->Paragraphs;
  v6 = 0i64;
  v7 = 0i64;
  while ( p_Paragraphs && v6 >= 0 && v6 < SLODWORD(p_Paragraphs->Data.Size) )
  {
    pPara = p_Paragraphs->Data.Data[v6].pPara;
    pText = pPara->Text.pText;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v11 = Size - 1;
      if ( !pText || (v12 = v11 < Size, v13 = (char *)&pText[v11], !v12) )
        v13 = 0i64;
      if ( !*(_WORD *)v13 )
        --Size;
    }
    memmove(&pBuffer->pText[v7], pText, 2 * Size);
    v7 += Size;
    if ( v6 < (signed __int64)p_Paragraphs->Data.Size )
      ++v6;
  }
  pBuffer->pText[v7] = 0;
}

// File Line: 1747
// RVA: 0x98C860
void __fastcall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer,
        unsigned __int64 startPos,
        __int64 endPos)
{
  __int64 Length; // rbp
  unsigned __int64 v8; // rbp
  __int64 Size; // rdx
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rsi
  __int64 v11; // rdi
  __int64 v12; // r12
  unsigned __int64 v13; // r11
  unsigned __int64 v14; // r10
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r9
  Scaleform::Render::Text::Paragraph *v17; // rax
  unsigned __int64 v18; // rdx
  __int64 v19; // r14
  Scaleform::Render::Text::Paragraph *v20; // rdx
  unsigned __int64 v21; // rbx
  unsigned __int64 v22; // rax
  bool v23; // cf
  wchar_t *v24; // rax
  unsigned __int64 v25; // rbx
  wchar_t *v26; // rdx

  Length = endPos;
  if ( endPos == -1 )
    Length = Scaleform::Render::Text::StyledText::GetLength(this);
  v8 = Length - startPos;
  Scaleform::WStringBuffer::Resize(pBuffer, v8 + 1);
  Size = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v11 = -1i64;
  v12 = 0i64;
  v13 = 0i64;
  while ( Size > 0 )
  {
    v14 = (Size >> 1) + v13;
    pPara = p_Paragraphs->Data.Data[v14].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v13 = v14 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v13 < this->Paragraphs.Data.Size
    && ((v17 = p_Paragraphs->Data.Data[v13].pPara, v18 = v17->StartIndex, startPos >= v18)
     && startPos < v18 + v17->Text.Size
     || (_DWORD)v18 == (_DWORD)startPos) )
  {
    v12 = startPos - p_Paragraphs->Data.Data[(int)v13].pPara->StartIndex;
    v11 = (int)v13;
  }
  else
  {
    p_Paragraphs = 0i64;
  }
  v19 = 0i64;
  while ( p_Paragraphs && v11 >= 0 && v11 < SLODWORD(p_Paragraphs->Data.Size) && v8 )
  {
    v20 = p_Paragraphs->Data.Data[v11].pPara;
    v21 = v20->Text.Size;
    if ( v21 )
    {
      v22 = v21 - 1;
      if ( !v20->Text.pText || (v23 = v22 < v21, v24 = &v20->Text.pText[v22], !v23) )
        v24 = 0i64;
      if ( !*v24 )
        --v21;
    }
    v25 = v21 - v12;
    v26 = &v20->Text.pText[v12];
    if ( v25 > v8 )
      v25 = v8;
    memmove(&pBuffer->pText[v19], v26, 2 * v25);
    v19 += v25;
    v8 -= v25;
    v12 = 0i64;
    if ( v11 < (signed __int64)p_Paragraphs->Data.Size )
      ++v11;
  }
  pBuffer->pText[v19] = 0;
}

// File Line: 1779
// RVA: 0x964DE0
Scaleform::Render::Text::StyledText *__fastcall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::Text::Allocator *Allocator; // rbx
  __int64 v7; // rcx
  Scaleform::Render::Text::StyledText *v8; // rax
  Scaleform::Render::Text::StyledText *v9; // rax
  Scaleform::Render::Text::StyledText *v10; // rbx

  Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this);
  v8 = (Scaleform::Render::Text::StyledText *)((__int64 (__fastcall *)(__int64, __int64))Allocator->pHeap->vfptr->Alloc)(
                                                v7,
                                                72i64);
  if ( v8 )
  {
    Scaleform::Render::Text::StyledText::StyledText(v8, Allocator);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  Scaleform::Render::Text::StyledText::CopyStyledText(this, v10, startPos, endPos);
  return v10;
}

// File Line: 1787
// RVA: 0x964E70
void __fastcall Scaleform::Render::Text::StyledText::CopyStyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::StyledText *pdest,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 Length; // rsi
  Scaleform::Render::Text::StyledText *v7; // rbp
  unsigned __int64 v8; // rsi
  __int64 Size; // rdx
  wchar_t *v10; // r13
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r12
  unsigned __int64 v12; // r11
  unsigned __int64 v13; // r10
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r9
  Scaleform::Render::Text::Paragraph *v16; // rax
  unsigned __int64 v17; // rdx
  signed __int64 v18; // rbp
  Scaleform::Render::Text::Paragraph *v19; // r14
  signed __int64 v20; // rdi
  Scaleform::Render::Text::Paragraph *appended; // rax
  unsigned __int64 v22; // rcx
  unsigned __int64 v23; // rdx
  wchar_t *v24; // rax
  unsigned __int64 v25; // rcx
  unsigned __int64 v26; // rbx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  __int64 v28; // rdi
  Scaleform::Render::Text::Paragraph *v29; // rdx
  unsigned __int64 v30; // rbx
  unsigned __int64 v31; // rax
  bool v32; // cf
  wchar_t *v33; // rax
  Scaleform::Render::Text::Paragraph *v34; // rdi
  Scaleform::Render::Text::Paragraph *v35; // rbx
  Scaleform::Render::Text::Allocator *v36; // rax
  signed __int64 v37; // rcx
  Scaleform::Render::Text::Paragraph *v38; // rdx
  unsigned __int64 v39; // rax
  unsigned __int64 v40; // rcx
  __int64 v41; // [rsp+38h] [rbp-40h]
  Scaleform::Render::Text::Paragraph *v43; // [rsp+88h] [rbp+10h]

  Length = endPos;
  v7 = this;
  if ( endPos == -1i64 )
    Length = Scaleform::Render::Text::StyledText::GetLength(this);
  v8 = Length - startPos;
  Scaleform::Render::Text::StyledText::Clear(pdest);
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))pdest->vfptr[1].__vecDelDtor)(
    pdest,
    startPos,
    v8,
    &customCaption);
  Size = v7->Paragraphs.Data.Size;
  v10 = 0i64;
  p_Paragraphs = &v7->Paragraphs;
  v12 = 0i64;
  while ( Size > 0 )
  {
    v13 = (Size >> 1) + v12;
    pPara = p_Paragraphs->Data.Data[v13].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v12 = v13 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v12 < v7->Paragraphs.Data.Size )
  {
    if ( (v16 = p_Paragraphs->Data.Data[v12].pPara, v17 = v16->StartIndex, startPos >= v17)
      && startPos < v17 + v16->Text.Size
      || (_DWORD)v17 == (_DWORD)startPos )
    {
      v18 = (int)v12;
      v41 = (int)v12;
      v19 = p_Paragraphs->Data.Data[(int)v12].pPara;
      v20 = startPos - v19->StartIndex;
      if ( (v12 & 0x80000000) == 0i64 && (int)v12 < (__int64)SLODWORD(p_Paragraphs->Data.Size) )
      {
        if ( !v20 )
          goto LABEL_26;
        appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, v19->pFormat.pObject);
        v22 = v19->Text.Size;
        v43 = appended;
        if ( v22 )
        {
          v23 = v22 - 1;
          if ( !v19->Text.pText || (v24 = &v19->Text.pText[v23], v23 >= v22) )
            v24 = 0i64;
          if ( !*v24 )
            --v22;
        }
        v25 = v22 - v20;
        v26 = v8;
        if ( v25 < v8 )
          v26 = v25;
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(pdest);
        Scaleform::Render::Text::Paragraph::Copy(v43, Allocator, v19, v20);
        v8 -= v26;
        v28 = v18 + 1;
        if ( v18 >= (signed __int64)p_Paragraphs->Data.Size )
LABEL_26:
          v28 = v41;
        while ( v28 >= 0 && v28 < SLODWORD(p_Paragraphs->Data.Size) && v8 )
        {
          v29 = p_Paragraphs->Data.Data[v28].pPara;
          v30 = v29->Text.Size;
          if ( v30 )
          {
            v31 = v30 - 1;
            if ( !v29->Text.pText || (v32 = v31 < v30, v33 = &v29->Text.pText[v31], !v32) )
              v33 = 0i64;
            if ( !*v33 )
              --v30;
          }
          if ( v30 > v8 )
          {
            v34 = p_Paragraphs->Data.Data[v28].pPara;
            v35 = Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, v34->pFormat.pObject);
            v36 = Scaleform::Render::Text::StyledText::GetAllocator(pdest);
            Scaleform::Render::Text::Paragraph::Copy(v35, v36, v34, 0i64);
            break;
          }
          Scaleform::Render::Text::StyledText::AppendCopyOfParagraph(pdest, v29);
          v8 -= v30;
          if ( v28 < (signed __int64)p_Paragraphs->Data.Size )
            ++v28;
        }
      }
      v7 = this;
    }
  }
  v37 = pdest->Paragraphs.Data.Size - 1;
  if ( pdest != (Scaleform::Render::Text::StyledText *)-24i64 && v37 >= 0 && v37 < SLODWORD(pdest->Paragraphs.Data.Size) )
  {
    v38 = pdest->Paragraphs.Data.Data[v37].pPara;
    if ( v38 )
    {
      v39 = v38->Text.Size;
      if ( v39 )
      {
        v40 = v39 - 1;
        if ( v38->Text.pText && v40 < v39 )
          v10 = &v38->Text.pText[v40];
        if ( *v10 == 10 || *v10 == 13 )
          Scaleform::Render::Text::StyledText::AppendNewParagraph(pdest, v38->pFormat.pObject);
      }
    }
  }
  Scaleform::Render::Text::StyledText::EnsureTermNull(pdest);
  if ( (v7->RTFlags & 1) != 0 )
    pdest->RTFlags |= 1u;
}

// File Line: 1857
// RVA: 0x9959B0
__int64 __fastcall Scaleform::Render::Text::StyledText::InsertString(
        Scaleform::Render::Text::StyledText *this,
        const wchar_t *pstr,
        unsigned __int64 pos,
        unsigned __int64 length,
        Scaleform::Render::Text::StyledText::NewLinePolicy newLinePolicy,
        Scaleform::Render::Text::TextFormat *pdefTextFmt,
        Scaleform::Render::Text::ParagraphFormat *pdefParaFmt)
{
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbx
  wchar_t *v12; // r13
  Scaleform::Render::Text::StyledText *v13; // r11
  unsigned __int64 v14; // r8
  unsigned __int64 Size; // rbp
  __int64 v16; // r9
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r14
  __int64 v18; // r10
  __int64 v19; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *Data; // rax
  Scaleform::Render::Text::Paragraph *v23; // rcx
  __int64 CurIndex; // r14
  Scaleform::Render::Text::ParagraphFormat *v25; // r9
  wchar_t v26; // bp
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *pArray; // r15
  Scaleform::Render::Text::Paragraph *v28; // r12
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // rcx
  bool v31; // cf
  wchar_t *v32; // rcx
  __int64 v33; // rax
  unsigned __int64 v34; // rbx
  Scaleform::Render::Text::Paragraph *inserted; // rax
  Scaleform::Render::Text::ParagraphFormat *pObject; // r13
  Scaleform::Render::Text::Paragraph *v37; // rcx
  Scaleform::Render::Text::ParagraphFormat *v38; // r15
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *pAllocator; // rcx
  unsigned __int64 v41; // r15
  unsigned __int64 v42; // r15
  unsigned __int64 v43; // r8
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // r15
  unsigned __int64 v46; // r13
  unsigned __int64 v47; // r15
  wchar_t *pText; // rax
  unsigned __int64 v49; // rcx
  wchar_t *v50; // rcx
  unsigned __int64 v51; // rcx
  wchar_t *v52; // rcx
  unsigned __int64 v53; // r8
  unsigned __int8 v54; // al
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v55; // rdx
  Scaleform::Render::Text::Paragraph *v56; // rcx
  __int64 v57; // rcx
  Scaleform::Render::Text::Paragraph *appended; // rax
  unsigned __int64 v59; // rcx
  unsigned __int64 v60; // rdx
  unsigned __int64 v61; // rdi
  __int64 v62; // rbx
  __int64 v63; // rax
  unsigned __int64 v64; // [rsp+30h] [rbp-88h]
  __int64 v65; // [rsp+38h] [rbp-80h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+40h] [rbp-78h] BYREF
  Scaleform::Render::Text::Paragraph *v67; // [rsp+48h] [rbp-70h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v68; // [rsp+50h] [rbp-68h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v69; // [rsp+60h] [rbp-58h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator iter; // [rsp+70h] [rbp-48h] BYREF
  unsigned __int64 startSrcIndex; // [rsp+D8h] [rbp+20h]

  v7 = length;
  v8 = pos;
  if ( !length )
    return 0i64;
  if ( pos > Scaleform::Render::Text::StyledText::GetLength(this) )
    v8 = Scaleform::Render::Text::StyledText::GetLength(this);
  v12 = 0i64;
  if ( v7 == -1i64 )
  {
    v7 = 0i64;
    if ( *pstr )
    {
      do
        ++v7;
      while ( pstr[v7] );
    }
  }
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, const wchar_t *))this->vfptr[2].__vecDelDtor)(
    this,
    v8,
    v7,
    pstr);
  v13 = this;
  v14 = 0i64;
  Size = this->Paragraphs.Data.Size;
  startSrcIndex = 0i64;
  if ( !Size )
  {
    CurIndex = -1i64;
    v68.pArray = 0i64;
    v68.CurIndex = -1i64;
    goto LABEL_24;
  }
  v16 = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v18 = 0i64;
  if ( v16 > 0 )
  {
    do
    {
      v19 = (v16 >> 1) + v18;
      pPara = p_Paragraphs->Data.Data[v19].pPara;
      StartIndex = pPara->StartIndex;
      if ( v8 >= StartIndex && v8 < StartIndex + pPara->Text.Size || (int)StartIndex - (int)v8 >= 0 )
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
    v13 = this;
  }
  if ( v18 == Size )
    LODWORD(v18) = v18 - 1;
  Data = p_Paragraphs->Data.Data;
  v68.pArray = &this->Paragraphs;
  v23 = Data[(int)v18].pPara;
  v68.CurIndex = (int)v18;
  v14 = v8 - v23->StartIndex;
  v64 = v23->StartIndex;
  startSrcIndex = v14;
  if ( (int)v18 < 0 || (int)v18 >= (__int64)SLODWORD(this->Paragraphs.Data.Size) )
  {
    CurIndex = v68.CurIndex;
LABEL_24:
    v64 = 0i64;
    goto LABEL_25;
  }
  CurIndex = v68.CurIndex;
LABEL_25:
  v25 = pdefParaFmt;
  v26 = 0;
  v65 = 0i64;
  while ( 1 )
  {
    if ( newLinePolicy == NLP_IgnoreCRLF )
    {
      if ( !v7 )
        break;
      do
      {
        if ( *pstr != 13 && *pstr != 10 )
          break;
        ++pstr;
        --v7;
      }
      while ( v7 );
      if ( !v7 )
        break;
    }
    pArray = (Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *)v68.pArray;
    if ( !v68.pArray || CurIndex < 0 || CurIndex >= SLODWORD(v68.pArray->Data.Size) )
    {
      Scaleform::Render::Text::StyledText::AppendNewParagraph(v13, v25);
      v13 = this;
      v25 = pdefParaFmt;
      v14 = 0i64;
      v69 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator)(unsigned __int64)&this->Paragraphs;
      startSrcIndex = 0i64;
      v68 = v69;
      CurIndex = 0i64;
      pArray = &this->Paragraphs;
    }
    v28 = pArray->Data.Data[CurIndex].pPara;
    v29 = v28->Text.Size;
    if ( !v29 )
      goto LABEL_43;
    v30 = v29 - 1;
    if ( !v28->Text.pText || (v31 = v30 < v29, v32 = &v28->Text.pText[v30], !v31) )
      v32 = 0i64;
    if ( !*v32 )
      --v29;
    if ( !v29 )
    {
LABEL_43:
      Scaleform::Render::Text::Paragraph::SetFormat(pArray->Data.Data[CurIndex].pPara, v13->pTextAllocator.pObject, v25);
      v13 = this;
      v14 = startSrcIndex;
    }
    v33 = -1i64;
    v34 = 0i64;
    if ( newLinePolicy == NLP_CompressCRLF && v26 == 13 && *pstr == 10 )
    {
      ++pstr;
      if ( !--v7 )
        break;
    }
    if ( v7 )
    {
      while ( 1 )
      {
        v26 = pstr[v34];
        if ( v26 == 10 || v26 == 13 )
          break;
        if ( !v26 )
          goto LABEL_74;
        if ( ++v34 >= v7 )
          goto LABEL_53;
      }
      if ( newLinePolicy == NLP_IgnoreCRLF )
      {
        v26 = 1;
LABEL_74:
        Scaleform::Render::Text::Paragraph::InsertString(v28, v13->pTextAllocator.pObject, pstr, v14, v34, pdefTextFmt);
        goto LABEL_96;
      }
      v33 = v34;
    }
LABEL_53:
    if ( v26 == 10 || v26 == 13 )
      ++v34;
    if ( v33 == -1 )
      goto LABEL_74;
    iter = v68;
    if ( CurIndex < (signed __int64)pArray->Data.Size )
      iter.CurIndex = CurIndex + 1;
    inserted = Scaleform::Render::Text::StyledText::InsertNewParagraph(v13, &iter, pdefParaFmt);
    pObject = v28->pFormat.pObject;
    v37 = inserted;
    v67 = inserted;
    if ( pObject )
      ++pObject->RefCount;
    v38 = inserted->pFormat.pObject;
    if ( v38 )
    {
      if ( v38->RefCount-- == 1 )
      {
        pAllocator = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v38->pAllocator;
        if ( v38->pAllocator )
        {
          key = v38;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            pAllocator + 3,
            &key);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38->pTabStops);
        v38->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v38);
        v37 = v67;
      }
    }
    v37->pFormat.pObject = pObject;
    ++v37->ModCounter;
    v12 = 0i64;
    Scaleform::Render::Text::Paragraph::Copy(v37, this->pTextAllocator.pObject, v28, startSrcIndex);
    v41 = v28->Text.Size;
    Scaleform::Render::Text::Paragraph::InsertString(
      v28,
      this->pTextAllocator.pObject,
      pstr,
      startSrcIndex,
      v34,
      pdefTextFmt);
    v42 = v41 - startSrcIndex;
    if ( v42 )
    {
      v43 = v28->Text.Size;
      v44 = v43;
      if ( v42 < v43 )
        v44 = v42;
      v45 = v43 - v44;
      if ( v43 == -1i64 )
      {
        v46 = -1i64;
        goto LABEL_76;
      }
      v46 = v44;
      if ( v43 != v45 )
      {
LABEL_76:
        if ( v45 < v43 )
        {
          if ( v45 + v46 < v43 )
          {
            memmove(&v28->Text.pText[v43 - v44], &v28->Text.pText[v43 - v44 + v46], 2 * (v44 - v46));
            v28->Text.Size -= v46;
          }
          else
          {
            v28->Text.Size = v45;
          }
        }
        Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
          &v28->FormatInfo,
          v45,
          v46);
        v47 = v28->Text.Size;
        if ( v47 )
        {
          pText = v28->Text.pText;
          v49 = v47 - 1;
          if ( v28->Text.pText && v49 < v47 )
            v50 = &pText[v49];
          else
            v50 = 0i64;
          if ( !*v50 )
          {
            v51 = v47 - 1;
            if ( pText && v51 < v47 )
              v52 = &pText[v51];
            else
              v52 = 0i64;
            if ( !*v52 )
              --v47;
            Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
              &v28->FormatInfo,
              v47,
              1ui64);
            Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
              &v28->FormatInfo,
              v47 + 1,
              1ui64);
          }
        }
        ++v28->ModCounter;
      }
      v12 = 0i64;
    }
    pArray = (Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *)v68.pArray;
LABEL_96:
    if ( v26 == 13 || v26 == 10 )
    {
      v13 = this;
      v53 = startSrcIndex;
      v54 = 10;
      if ( (this->RTFlags & 2) != 0 )
        v54 = 13;
      if ( v26 != v54 )
        v28->Text.pText[v34 - 1 + startSrcIndex] = v54;
    }
    else
    {
      v13 = this;
      v53 = startSrcIndex;
    }
    v65 += v34;
    v7 -= v34;
    pstr += v34;
    v28->StartIndex = v64;
    if ( newLinePolicy == NLP_IgnoreCRLF )
    {
      v14 = v34 + v53;
      startSrcIndex = v14;
    }
    else
    {
      v14 = 0i64;
      startSrcIndex = 0i64;
      v64 += v28->Text.Size;
      if ( CurIndex < (signed __int64)pArray->Data.Size )
        v68.CurIndex = ++CurIndex;
    }
    if ( v7 )
    {
      v25 = pdefParaFmt;
      if ( v26 )
        continue;
    }
    break;
  }
  v55 = v68.pArray;
  while ( v55 && CurIndex >= 0 && CurIndex < SLODWORD(v55->Data.Size) )
  {
    v56 = v55->Data.Data[CurIndex].pPara;
    v56->StartIndex = v64;
    v64 += v56->Text.Size;
    if ( CurIndex < (signed __int64)v55->Data.Size )
      ++CurIndex;
  }
  v57 = v13->Paragraphs.Data.Size - 1;
  if ( v13 != (Scaleform::Render::Text::StyledText *)-24i64
    && v57 >= 0
    && v57 < SLODWORD(v13->Paragraphs.Data.Size)
    && (appended = v13->Paragraphs.Data.Data[v57].pPara) != 0i64 )
  {
LABEL_121:
    v59 = appended->Text.Size;
    if ( !v59 )
      goto LABEL_127;
    v60 = v59 - 1;
    if ( appended->Text.pText && v60 < v59 )
      v12 = &appended->Text.pText[v60];
    if ( *v12 != 10 && *v12 != 13 )
LABEL_127:
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        appended,
        v13->pTextAllocator.pObject,
        v13->pDefaultTextFormat.pObject);
  }
  else
  {
    appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(v13, 0i64);
    if ( appended )
    {
      v13 = this;
      goto LABEL_121;
    }
  }
  if ( (pdefTextFmt->PresentMask & 0x100) != 0 )
  {
    v61 = pdefTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    v62 = *(_QWORD *)v61 & 0x7FFFFFFFFFFFFFFFi64;
    if ( *(__int64 *)v61 >= 0 )
    {
      v63 = Scaleform::UTF8Util::GetLength((char *)(v61 + 12), *(_QWORD *)v61 & 0x7FFFFFFFFFFFFFFFi64);
      if ( v63 == v62 )
        *(_QWORD *)v61 |= 0x8000000000000000ui64;
      v62 = v63;
    }
    if ( v62 )
      this->RTFlags |= 1u;
  }
  return v65;
}

// File Line: 2016
// RVA: 0x996110
unsigned __int64 __fastcall Scaleform::Render::Text::StyledText::InsertStyledText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::StyledText *text,
        unsigned __int64 pos,
        unsigned __int64 length)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 v8; // rax
  unsigned __int64 Size; // rsi
  wchar_t *v10; // r12
  __int64 v11; // r9
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // r8
  __int64 v13; // r10
  __int64 v14; // r11
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // rdx
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *Data; // rax
  Scaleform::Render::Text::Paragraph *v18; // rcx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v19; // xmm0
  signed __int64 v20; // rdi
  __int64 CurIndex; // rbx
  unsigned __int64 v22; // rsi
  Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *v23; // rax
  Scaleform::Render::Text::Paragraph *v24; // rbp
  Scaleform::Render::Text::Paragraph *v25; // r15
  unsigned __int64 v26; // rsi
  Scaleform::Render::Text::Paragraph *v27; // r15
  Scaleform::Render::Text::Paragraph *v28; // rbp
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // rcx
  unsigned __int64 v31; // r12
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *v32; // r8
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // rax
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // rcx
  wchar_t *v36; // rcx
  unsigned __int64 v37; // rsi
  Scaleform::Render::Text::StyledText *v38; // rcx
  __int64 v39; // rbp
  Scaleform::Render::Text::Paragraph *v40; // r15
  unsigned __int64 v41; // rax
  unsigned __int64 v42; // rdi
  unsigned __int64 v43; // rcx
  wchar_t *v44; // rcx
  unsigned __int64 v45; // rcx
  wchar_t *v46; // rax
  wchar_t v47; // ax
  Scaleform::Render::Text::Paragraph *v48; // rdi
  unsigned __int64 v49; // rax
  unsigned __int64 v50; // rcx
  bool v51; // cf
  wchar_t *v52; // rcx
  Scaleform::Render::Text::Paragraph *v53; // rcx
  signed __int64 v54; // rcx
  Scaleform::Render::Text::Paragraph *appended; // rax
  unsigned __int64 v56; // rcx
  unsigned __int64 v57; // rdx
  Scaleform::Render::Text::Paragraph *inserted; // [rsp+30h] [rbp-68h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator iter; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v61; // [rsp+50h] [rbp-48h] BYREF
  unsigned __int64 v63; // [rsp+B8h] [rbp+20h]

  v63 = length;
  v5 = length;
  v8 = Scaleform::Render::Text::StyledText::GetLength(text);
  if ( v5 == -1i64 || v5 > v8 )
  {
    v5 = v8;
    v63 = v8;
  }
  if ( !v5 || !text->Paragraphs.Data.Size )
    return 0i64;
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64, char *))this->vfptr[1].__vecDelDtor)(
    this,
    pos,
    v5,
    &customCaption);
  Size = this->Paragraphs.Data.Size;
  v10 = 0i64;
  if ( !Size )
    goto LABEL_19;
  v11 = this->Paragraphs.Data.Size;
  p_Paragraphs = &this->Paragraphs;
  v13 = 0i64;
  if ( v11 > 0 )
  {
    do
    {
      v14 = (v11 >> 1) + v13;
      pPara = p_Paragraphs->Data.Data[v14].pPara;
      StartIndex = pPara->StartIndex;
      if ( pos >= StartIndex && pos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)pos >= 0 )
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
    p_Paragraphs = &this->Paragraphs;
  }
  if ( v13 == Size )
    LODWORD(v13) = v13 - 1;
  Data = p_Paragraphs->Data.Data;
  v61.pArray = p_Paragraphs;
  v18 = Data[(int)v13].pPara;
  v61.CurIndex = (int)v13;
  v19 = v61;
  v20 = pos - v18->StartIndex;
  if ( (int)v13 < 0 || (int)v13 >= (__int64)SLODWORD(p_Paragraphs->Data.Size) )
  {
LABEL_19:
    Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0i64);
    iter.CurIndex = 0i64;
    iter.pArray = &this->Paragraphs;
    v20 = 0i64;
    v19 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator)(unsigned __int64)&this->Paragraphs;
    v61 = v19;
  }
  CurIndex = v61.CurIndex;
  if ( v19.pArray && v61.CurIndex >= 0 && v61.CurIndex < SLODWORD(v19.pArray->Data.Size) )
    v22 = v19.pArray->Data.Data[v61.CurIndex].pPara->StartIndex;
  else
    v22 = 0i64;
  v23 = v19.pArray->Data.Data;
  if ( text->Paragraphs.Data.Size == 1 )
  {
    v24 = v23[v61.CurIndex].pPara;
    v25 = text->Paragraphs.Data.Data->pPara;
    Scaleform::Render::Text::Paragraph::Copy(v24, this->pTextAllocator.pObject, v25, 0i64);
    if ( !v20 )
      Scaleform::Render::Text::Paragraph::SetFormat(v24, this->pTextAllocator.pObject, v25->pFormat.pObject);
    v26 = v24->Text.Size + v22;
  }
  else
  {
    v27 = v23[v61.CurIndex].pPara;
    iter = v19;
    if ( v61.CurIndex < (signed __int64)v19.pArray->Data.Size )
      iter.CurIndex = v61.CurIndex + 1;
    inserted = Scaleform::Render::Text::StyledText::InsertNewParagraph(this, &iter, v27->pFormat.pObject);
    Scaleform::Render::Text::Paragraph::Copy(inserted, this->pTextAllocator.pObject, v27, v20);
    iter.pArray = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)(v27->Text.Size - v20);
    v28 = text->Paragraphs.Data.Data->pPara;
    Scaleform::Render::Text::Paragraph::Copy(v27, this->pTextAllocator.pObject, v28, 0i64);
    v29 = v28->Text.Size;
    if ( v29 )
    {
      v30 = v29 - 1;
      if ( v28->Text.pText && v30 < v29 )
        v10 = &v28->Text.pText[v30];
      if ( !*v10 )
        --v29;
    }
    v31 = v63 - v29;
    if ( !v20 )
      Scaleform::Render::Text::Paragraph::SetFormat(v27, this->pTextAllocator.pObject, v28->pFormat.pObject);
    if ( iter.pArray )
    {
      v32 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *)v27->Text.Size;
      pArray = v32;
      if ( iter.pArray < v32 )
        pArray = iter.pArray;
      Scaleform::Render::Text::Paragraph::Remove(v27, v27->Text.Size - (_QWORD)pArray, (unsigned __int64)v32);
    }
    v34 = v27->Text.Size;
    if ( v34 )
    {
      v35 = v34 - 1;
      if ( v27->Text.pText && v35 < v34 )
        v36 = &v27->Text.pText[v35];
      else
        v36 = 0i64;
      if ( !*v36 )
        --v34;
    }
    v37 = v34 + v22;
    if ( CurIndex < (signed __int64)v19.pArray->Data.Size )
      v61.CurIndex = ++CurIndex;
    v38 = text;
    v39 = (signed __int64)text->Paragraphs.Data.Size > 0;
    while ( v39 >= 0 && v39 < SLODWORD(v38->Paragraphs.Data.Size) && v31 )
    {
      v40 = v38->Paragraphs.Data.Data[v39].pPara;
      v41 = v40->Text.Size;
      v42 = v41;
      if ( v41 )
      {
        v43 = v41 - 1;
        if ( v40->Text.pText && v43 < v41 )
          v44 = &v40->Text.pText[v43];
        else
          v44 = 0i64;
        if ( !*v44 )
          v42 = v41 - 1;
      }
      if ( v42 > v31
        || v42 == v31
        && (!v41
         || ((v45 = v41 - 1, !v40->Text.pText) || v45 >= v41 ? (v46 = 0i64) : (v46 = &v40->Text.pText[v45]),
             (v47 = *v46, v47 != 13) && v47 != 10)) )
      {
        v48 = inserted;
        v10 = 0i64;
        Scaleform::Render::Text::Paragraph::Copy(inserted, this->pTextAllocator.pObject, v40, 0i64);
        Scaleform::Render::Text::Paragraph::SetFormat(inserted, this->pTextAllocator.pObject, v40->pFormat.pObject);
        goto LABEL_78;
      }
      Scaleform::Render::Text::StyledText::InsertCopyOfParagraph(this, &v61, v40);
      v38 = text;
      v31 -= v42;
      v37 += v42;
      if ( v39 < (signed __int64)text->Paragraphs.Data.Size )
        ++v39;
      if ( CurIndex < (signed __int64)v19.pArray->Data.Size )
        v61.CurIndex = ++CurIndex;
    }
    v48 = inserted;
    v10 = 0i64;
LABEL_78:
    v49 = v48->Text.Size;
    v48->StartIndex = v37;
    if ( v49 )
    {
      v50 = v49 - 1;
      if ( !v48->Text.pText || (v51 = v50 < v49, v52 = &v48->Text.pText[v50], !v51) )
        v52 = 0i64;
      if ( !*v52 )
        --v49;
    }
    v26 = v49 + v37;
  }
  if ( CurIndex < (signed __int64)v19.pArray->Data.Size )
    ++CurIndex;
  while ( CurIndex >= 0 )
  {
    if ( CurIndex >= SLODWORD(v19.pArray->Data.Size) )
      break;
    v53 = v19.pArray->Data.Data[CurIndex].pPara;
    if ( v53->StartIndex == v26 )
      break;
    v53->StartIndex = v26;
    v26 += v53->Text.Size;
    if ( CurIndex < (signed __int64)v19.pArray->Data.Size )
      ++CurIndex;
  }
  v54 = this->Paragraphs.Data.Size - 1;
  if ( this != (Scaleform::Render::Text::StyledText *)-24i64
    && v54 >= 0
    && v54 < SLODWORD(this->Paragraphs.Data.Size)
    && (appended = this->Paragraphs.Data.Data[v54].pPara) != 0i64
    || (appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0i64)) != 0i64 )
  {
    v56 = appended->Text.Size;
    if ( !v56 )
      goto LABEL_103;
    v57 = v56 - 1;
    if ( appended->Text.pText && v57 < v56 )
      v10 = &appended->Text.pText[v57];
    if ( *v10 != 10 && *v10 != 13 )
LABEL_103:
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        appended,
        this->pTextAllocator.pObject,
        this->pDefaultTextFormat.pObject);
  }
  if ( (text->RTFlags & 1) != 0 )
    this->RTFlags |= 1u;
  return v63;
}

// File Line: 2144
// RVA: 0x9A8CE0
void __fastcall Scaleform::Render::Text::StyledText::Remove(
        Scaleform::Render::Text::StyledText *this,
        unsigned __int64 startPos,
        unsigned __int64 length)
{
  unsigned __int64 v3; // r13
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // rdi
  __int64 Size; // r9
  unsigned __int64 v8; // r11
  signed __int64 v9; // rsi
  unsigned __int64 v10; // r10
  Scaleform::Render::Text::Paragraph *pPara; // rax
  unsigned __int64 StartIndex; // r8
  Scaleform::Render::Text::Paragraph *v13; // rax
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // r14
  Scaleform::Render::Text::Paragraph *v17; // rcx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // r15
  Scaleform::Render::Text::Paragraph *v20; // rbx
  unsigned __int64 v21; // r15
  unsigned __int64 v22; // rcx
  Scaleform::Render::Text::Paragraph *v23; // rbp
  Scaleform::Render::Text::ParagraphFormat *pObject; // rbx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *pAllocator; // rcx
  bool v27; // dl
  Scaleform::Render::Text::Paragraph *v28; // rbx
  unsigned __int64 v29; // [rsp+A0h] [rbp+8h]
  bool v30; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::Text::Paragraph *v31; // [rsp+A8h] [rbp+10h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // [rsp+B8h] [rbp+20h]

  v3 = length;
  if ( length == -1i64 )
    v3 = Scaleform::Render::Text::StyledText::GetLength(this);
  ((void (__fastcall *)(Scaleform::Render::Text::StyledText *, unsigned __int64, unsigned __int64))this->vfptr[3].__vecDelDtor)(
    this,
    startPos,
    v3);
  p_Paragraphs = &this->Paragraphs;
  Size = this->Paragraphs.Data.Size;
  v8 = 0i64;
  v9 = -1i64;
  while ( Size > 0 )
  {
    v10 = (Size >> 1) + v8;
    pPara = p_Paragraphs->Data.Data[v10].pPara;
    StartIndex = pPara->StartIndex;
    if ( startPos >= StartIndex && startPos < StartIndex + pPara->Text.Size || (int)StartIndex - (int)startPos >= 0 )
    {
      Size >>= 1;
    }
    else
    {
      v8 = v10 + 1;
      Size += -1 - (Size >> 1);
    }
  }
  if ( v8 < this->Paragraphs.Data.Size
    && ((v13 = p_Paragraphs->Data.Data[v8].pPara, v14 = v13->StartIndex, startPos >= v14)
     && startPos < v14 + v13->Text.Size
     || (_DWORD)v14 == (_DWORD)startPos) )
  {
    v15 = startPos - p_Paragraphs->Data.Data[(int)v8].pPara->StartIndex;
    v9 = (int)v8;
  }
  else
  {
    p_Paragraphs = 0i64;
    v15 = v29;
  }
  v31 = 0i64;
  v16 = v3;
  v30 = 0;
  if ( p_Paragraphs )
  {
    if ( v9 >= 0 && v9 < SLODWORD(p_Paragraphs->Data.Size) )
    {
      v17 = p_Paragraphs->Data.Data[v9].pPara;
      v18 = v17->Text.Size;
      v19 = v18 - v15;
      if ( v3 < v18 - v15 )
        v19 = v3;
      if ( v19 <= v18 )
      {
        v30 = v19 + v15 >= v18;
        v31 = p_Paragraphs->Data.Data[v9].pPara;
        Scaleform::Render::Text::Paragraph::Remove(v17, v15, v19 + v15);
        v16 = v3 - v19;
        if ( v9 < (signed __int64)p_Paragraphs->Data.Size )
          ++v9;
      }
    }
    while ( 1 )
    {
      if ( v9 < 0 || v9 >= SLODWORD(p_Paragraphs->Data.Size) )
      {
LABEL_45:
        v27 = v30;
        goto LABEL_46;
      }
      v20 = p_Paragraphs->Data.Data[v9].pPara;
      v21 = v20->Text.Size;
      if ( v16 < v21 )
        break;
      this->vfptr[5].__vecDelDtor(this, (unsigned int)p_Paragraphs->Data.Data[v9].pPara);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20->Text.pText);
      v20->Text.pText = 0i64;
      v20->Text.Allocated = 0i64;
      v20->Text.Size = 0i64;
      v22 = p_Paragraphs->Data.Size;
      if ( v9 < (int)v22 )
      {
        if ( v22 == 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &p_Paragraphs->Data,
            p_Paragraphs,
            0i64);
        }
        else
        {
          v23 = p_Paragraphs->Data.Data[v9].pPara;
          key = (Scaleform::Render::Text::ParagraphFormat *)v23;
          if ( v23 )
          {
            p_FormatInfo = &v23->FormatInfo;
            Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
              v23->FormatInfo.Ranges.Data.Data,
              v23->FormatInfo.Ranges.Data.Size);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(
              Scaleform::Memory::pGlobalHeap,
              v23->FormatInfo.Ranges.Data.Data);
            pObject = v23->pFormat.pObject;
            if ( pObject )
            {
              if ( pObject->RefCount-- == 1 )
              {
                pAllocator = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)pObject->pAllocator;
                if ( pObject->pAllocator )
                {
                  key = pObject;
                  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
                    pAllocator + 3,
                    &key);
                }
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject->pTabStops);
                pObject->pTabStops = 0i64;
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
              }
            }
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v23);
          }
          memmove(
            &p_Paragraphs->Data.Data[v9],
            &p_Paragraphs->Data.Data[v9 + 1],
            8 * (p_Paragraphs->Data.Size - v9) - 8);
          --p_Paragraphs->Data.Size;
        }
      }
      v16 -= v21;
      if ( !v16 )
        goto LABEL_45;
    }
    v27 = v30;
    if ( v31 && v30 )
    {
      Scaleform::Render::Text::Paragraph::Copy(v31, this->pTextAllocator.pObject, v20, v16);
      this->vfptr[5].__vecDelDtor(this, (unsigned int)v20);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20->Text.pText);
      v20->Text.pText = 0i64;
      v20->Text.Allocated = 0i64;
      v20->Text.Size = 0i64;
      if ( v9 < SLODWORD(p_Paragraphs->Data.Size) )
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          p_Paragraphs,
          v9);
      v27 = 0;
    }
LABEL_46:
    if ( v9 < 0 || v9 >= SLODWORD(p_Paragraphs->Data.Size) )
      goto LABEL_54;
    v28 = p_Paragraphs->Data.Data[v9].pPara;
    if ( v28->Text.Size )
    {
      if ( !v31 || !v27 )
      {
LABEL_54:
        while ( v9 >= 0 && v9 < SLODWORD(p_Paragraphs->Data.Size) )
        {
          p_Paragraphs->Data.Data[v9].pPara->StartIndex -= v3;
          if ( v9 < (signed __int64)p_Paragraphs->Data.Size )
            ++v9;
        }
        goto LABEL_58;
      }
      Scaleform::Render::Text::Paragraph::Copy(v31, this->pTextAllocator.pObject, v28, 0i64);
    }
    this->vfptr[5].__vecDelDtor(this, (unsigned int)v28);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v28->Text.pText);
    v28->Text.pText = 0i64;
    v28->Text.Allocated = 0i64;
    v28->Text.Size = 0i64;
    if ( v9 < SLODWORD(p_Paragraphs->Data.Size) )
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        p_Paragraphs,
        v9);
    goto LABEL_54;
  }
LABEL_58:
  Scaleform::Render::Text::StyledText::EnsureTermNull(this);
}

// File Line: 2369
// RVA: 0x95FAC0
void __fastcall Scaleform::Render::Text::StyledText::Clear(Scaleform::Render::Text::StyledText *this)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rsi
  Scaleform::Render::Text::Paragraph *pPara; // rdi

  Size = this->Paragraphs.Data.Size;
  for ( i = 0i64; i < Size; pPara->Text.Size = 0i64 )
  {
    pPara = this->Paragraphs.Data.Data[i].pPara;
    Scaleform::Render::Text::StyledText::GetAllocator(this);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPara->Text.pText);
    ++i;
    pPara->Text.pText = 0i64;
    pPara->Text.Allocated = 0i64;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Paragraphs.Data,
    &this->Paragraphs,
    0i64);
  this->RTFlags &= ~1u;
}

