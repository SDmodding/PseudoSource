// File Line: 150
// RVA: 0x9ADF80
Scaleform::Render::Text::Paragraph::StyledTextRun *__fastcall Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
        Scaleform::Render::Text::Paragraph::StyledTextRun *this,
        const wchar_t *ptext,
        __int64 index,
        unsigned __int64 len,
        Scaleform::Render::Text::TextFormat *pfmt)
{
  Scaleform::Render::Text::TextFormat *pObject; // rsi
  bool v7; // zf
  Scaleform::Render::Text::Paragraph::StyledTextRun *result; // rax

  this->pText = ptext;
  this->Index = index;
  this->Length = len;
  if ( pfmt )
    ++pfmt->RefCount;
  pObject = this->pFormat.pObject;
  if ( pObject && (v7 = pObject->RefCount == 1, --pObject->RefCount, v7) )
  {
    Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    this->pFormat.pObject = pfmt;
    return this;
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
Scaleform::Render::Text::Paragraph::CharactersIterator *__fastcall Scaleform::Render::Text::Paragraph::GetCharactersIterator(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Paragraph::CharactersIterator *result,
        __int64 index)
{
  Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(result, this, index);
  return result;
}

// File Line: 253
// RVA: 0x9957B0
void __fastcall Scaleform::Render::Text::Paragraph::InsertString(
        Scaleform::Render::Text::Paragraph *this,
        Scaleform::Render::Text::Allocator *pallocator,
        const wchar_t *pstr,
        unsigned __int64 pos,
        unsigned __int64 length)
{
  unsigned __int64 v5; // rbx
  wchar_t *Position; // rbp

  v5 = length;
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
      Position = Scaleform::Render::Text::Paragraph::TextBuffer::CreatePosition(&this->Text, pallocator, pos, v5);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        pos,
        v5);
      ++this->ModCounter;
      if ( Position )
      {
        memmove(Position, pstr, 2 * v5);
        Scaleform::Render::Text::Paragraph::SetTermNullFormat(this);
        ++this->ModCounter;
      }
    }
  }
}

// File Line: 319
// RVA: 0x94BD70
void __fastcall Scaleform::Render::Text::StyledText::ParagraphPtrWrapper::~ParagraphPtrWrapper(
        Scaleform::Render::Text::StyledText::ParagraphPtrWrapper *this)
{
  Scaleform::Render::Text::Paragraph *pPara; // rdi
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx

  pPara = this->pPara;
  if ( this->pPara )
  {
    Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>>::DestructArray(
      pPara->FormatInfo.Ranges.Data.Data,
      pPara->FormatInfo.Ranges.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPara->FormatInfo.Ranges.Data.Data);
    pObject = pPara->pFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pPara);
  }
}

// File Line: 434
// RVA: 0x94CE80
void __fastcall Scaleform::Render::Text::StyledText::~StyledText(Scaleform::Render::Text::StyledText *this)
{
  Scaleform::Render::Text::TextFormat *pObject; // rbx
  bool v3; // zf
  Scaleform::Render::Text::ParagraphFormat *v4; // rcx
  Scaleform::Render::Text::Allocator *v5; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::StyledText::`vftable;
  Scaleform::Render::Text::StyledText::Clear(this);
  pObject = this->pDefaultTextFormat.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v4 = this->pDefaultParagraphFormat.pObject;
  if ( v4 )
    Scaleform::Render::Text::ParagraphFormat::Release(v4);
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper>::DestructArray(
    this->Paragraphs.Data.Data,
    this->Paragraphs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Paragraphs.Data.Data);
  v5 = this->pTextAllocator.pObject;
  if ( v5 )
  {
    v3 = v5->RefCount-- == 1;
    if ( v3 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 573
// RVA: 0x97FF70
Scaleform::Render::Text::Allocator *__fastcall Scaleform::Render::Text::StyledText::GetAllocator(
        Scaleform::Render::Text::StyledText *this)
{
  Scaleform::MemoryHeap *v2; // rdi
  Scaleform::Render::Text::Allocator *v3; // rax
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rdi
  Scaleform::Render::Text::Allocator *pObject; // rcx

  if ( this->pTextAllocator.pObject )
    return this->pTextAllocator.pObject;
  v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v3 = (Scaleform::Render::Text::Allocator *)v2->vfptr->Alloc(v2, 144ui64, 0i64);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, v2, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  pObject = this->pTextAllocator.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  this->pTextAllocator.pObject = v5;
  return v5;
}

