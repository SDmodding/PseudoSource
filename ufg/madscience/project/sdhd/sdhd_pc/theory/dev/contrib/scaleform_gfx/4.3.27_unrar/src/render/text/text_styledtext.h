// File Line: 150
// RVA: 0x9ADF80
Scaleform::Render::Text::Paragraph::StyledTextRun *__fastcall Scaleform::Render::Text::Paragraph::StyledTextRun::Set(Scaleform::Render::Text::Paragraph::StyledTextRun *this, const wchar_t *ptext, __int64 index, unsigned __int64 len, Scaleform::Render::Text::TextFormat *pfmt)
{
  Scaleform::Render::Text::Paragraph::StyledTextRun *v5; // rbx
  Scaleform::Render::Text::TextFormat *v6; // rsi
  bool v7; // zf
  Scaleform::Render::Text::Paragraph::StyledTextRun *result; // rax

  v5 = this;
  this->pText = ptext;
  this->Index = index;
  this->Length = len;
  if ( pfmt )
    ++pfmt->RefCount;
  v6 = this->pFormat.pObject;
  if ( v6 && (v7 = v6->RefCount == 1, --v6->RefCount, v7) )
  {
    Scaleform::Render::Text::TextFormat::~TextFormat(v6);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
    v5->pFormat.pObject = pfmt;
    result = v5;
  }
  else
  {
    result = this;
    this->pFormat.pObject = pfmt;
  }
  return result;
}

// File Line: 227
// RVA: 0x9815C0
Scaleform::Render::Text::Paragraph::CharactersIterator *__fastcall Scaleform::Render::Text::Paragraph::GetCharactersIterator(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Paragraph::CharactersIterator *result, unsigned __int64 index)
{
  Scaleform::Render::Text::Paragraph::CharactersIterator *v3; // rbx

  v3 = result;
  Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(result, this, index);
  return v3;
}

// File Line: 253
// RVA: 0x9957B0
void __fastcall Scaleform::Render::Text::Paragraph::InsertString(Scaleform::Render::Text::Paragraph *this, Scaleform::Render::Text::Allocator *pallocator, const wchar_t *pstr, unsigned __int64 pos, unsigned __int64 length)
{
  unsigned __int64 v5; // rbx
  __int64 v6; // r14
  const wchar_t *v7; // rdi
  Scaleform::Render::Text::Paragraph *v8; // rsi
  wchar_t *v9; // rbp

  v5 = length;
  v6 = pos;
  v7 = pstr;
  v8 = this;
  if ( length )
  {
    if ( length == -1i64 )
    {
      v5 = 0i64;
      if ( *pstr )
      {
        do
          ++v5;
        while ( pstr[v5] );
      }
    }
    if ( v5 )
    {
      v9 = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, pos, v5);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &v8->FormatInfo,
        v6,
        v5);
      ++v8->ModCounter;
      if ( v9 )
      {
        memmove(v9, v7, 2 * v5);
        Scaleform::Render::Text::Paragraph::SetTermNullFormat(v8);
        ++v8->ModCounter;
      }
    }
  }
}

// File Line: 319
// RVA: 0x94BD70
void __fastcall Scaleform::Render::Text::StyledText::ParagraphPtrWrapper::~ParagraphPtrWrapper(Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *this)
{
  Scaleform::Render::Text::Paragraph *v1; // rdi
  Scaleform::Render::Text::ParagraphFormat *v2; // rcx

  v1 = this->pPara;
  if ( this->pPara )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      v1->FormatInfo.Ranges.Data.Data,
      v1->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->FormatInfo.Ranges.Data.Data);
    v2 = v1->pFormat.pObject;
    if ( v2 )
      Scaleform::Render::Text::ParagraphFormat::Release(v2);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

// File Line: 434
// RVA: 0x94CE80
void __fastcall Scaleform::Render::Text::StyledText::~StyledText(Scaleform::Render::Text::StyledText *this)
{
  Scaleform::Render::Text::StyledText *v1; // rdi
  Scaleform::Render::Text::TextFormat *v2; // rbx
  bool v3; // zf
  Scaleform::Render::Text::ParagraphFormat *v4; // rcx
  Scaleform::Render::Text::Allocator *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::StyledText::`vftable';
  Scaleform::Render::Text::StyledText::Clear(this);
  v2 = v1->pDefaultTextFormat.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
    }
  }
  v4 = v1->pDefaultParagraphFormat.pObject;
  if ( v4 )
    Scaleform::Render::Text::ParagraphFormat::Release(v4);
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
    v1->Paragraphs.Data.Data,
    v1->Paragraphs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Paragraphs.Data.Data);
  v5 = v1->pTextAllocator.pObject;
  if ( v5 )
  {
    v3 = v5->RefCount-- == 1;
    if ( v3 )
      v5->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, 1u);
  }
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
}

// File Line: 573
// RVA: 0x97FF70
Scaleform::Render::Text::Allocator *__fastcall Scaleform::Render::Text::StyledText::GetAllocator(Scaleform::Render::Text::StyledText *this)
{
  Scaleform::Render::Text::StyledText *v1; // rbx
  Scaleform::MemoryHeap *v2; // rax
  Scaleform::MemoryHeap *v3; // rdi
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rax
  Scaleform::Render::Text::Allocator *v6; // rdi
  Scaleform::Render::Text::Allocator *v7; // rcx
  bool v8; // zf

  v1 = this;
  if ( this->pTextAllocator.pObject )
    return this->pTextAllocator.pObject;
  v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v3 = v2;
  v4 = (Scaleform::Render::Text::Allocator *)v2->vfptr->Alloc(v2, 144ui64, 0i64);
  if ( v4 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v4, v3, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->pTextAllocator.pObject;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      v7->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 1u);
  }
  v1->pTextAllocator.pObject = v6;
  return v6;
}

