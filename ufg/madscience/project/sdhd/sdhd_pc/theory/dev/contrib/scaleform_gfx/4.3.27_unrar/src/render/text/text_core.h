// File Line: 94
// RVA: 0x6C9230
void __fastcall Scaleform::Render::Text::ImageDesc::ImageDesc(Scaleform::Render::Text::ImageDesc *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::ImageDesc,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::ImageDesc::`vftable;
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->BaseLineX = 0i64;
  *(_QWORD *)&this->ScreenWidth = 0i64;
  *(_OWORD *)&this->Matrix.M[0][0] = 0x3F800000ui64;
  this->Matrix.M[1][0] = 0.0;
  *(_QWORD *)&this->Matrix.M[1][1] = 1065353216i64;
  this->Matrix.M[1][3] = 0.0;
}

// File Line: 124
// RVA: 0x93D960
void __fastcall Scaleform::Render::Text::HTMLImageTagDesc::HTMLImageTagDesc(
        Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::ImageDesc,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::ImageDesc::`vftable;
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->BaseLineX = 0i64;
  *(_QWORD *)&this->ScreenWidth = 0i64;
  *(_OWORD *)&this->Matrix.M[0][0] = 0x3F800000ui64;
  this->Matrix.M[1][0] = 0.0;
  *(_QWORD *)&this->Matrix.M[1][1] = 1065353216i64;
  this->Matrix.M[1][3] = 0.0;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::HTMLImageTagDesc::`vftable;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 1;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->Id.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 1;
  *(_QWORD *)&this->VSpace = 0i64;
  this->ParaId = -1;
  this->Alignment = 0;
}

// File Line: 129
// RVA: 0x94E830
bool __fastcall Scaleform::Render::Text::HTMLImageTagDesc::operator==(
        Scaleform::Render::Text::HTMLImageTagDesc *this,
        Scaleform::Render::Text::HTMLImageTagDesc *f)
{
  unsigned __int8 *v4; // rax
  unsigned __int64 v5; // r8
  int v6; // ecx
  int v7; // edx
  unsigned __int8 *v8; // rax
  int v9; // ecx
  int v10; // edx

  v4 = (unsigned __int8 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v5 = (f->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v6 = v4[v5];
    v7 = *v4 - v6;
    if ( v7 )
      break;
    ++v4;
  }
  while ( v6 );
  if ( v7 )
    return 0;
  v8 = (unsigned __int8 *)((this->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  do
  {
    v9 = v8[(f->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (this->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)];
    v10 = *v8 - v9;
    if ( v10 )
      break;
    ++v8;
  }
  while ( v9 );
  return !v10
      && this->VSpace == f->VSpace
      && this->HSpace == f->HSpace
      && this->ParaId == f->ParaId
      && this->Alignment == f->Alignment;
}

// File Line: 256
// RVA: 0x714620
void __fastcall Scaleform::Render::Text::TextFormat::SetFontSize(
        Scaleform::Render::Text::TextFormat *this,
        float fontSize)
{
  this->PresentMask |= 8u;
  if ( fontSize >= 3276.8 )
    this->FontSize = -1;
  else
    this->FontSize = (int)(float)(fontSize * 20.0);
}

// File Line: 274
// RVA: 0x7E9880
Scaleform::Render::RenderBuffer *__fastcall Scaleform::Render::Text::TextFormat::GetFontHandle(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v4; // rbx
  char v5; // di
  Scaleform::Render::RenderBuffer *v7; // [rsp+40h] [rbp+8h]

  v2 = 0i64;
  if ( (this->PresentMask & 0x800) != 0 )
  {
    pObject = (Scaleform::GFx::Resource *)this->pFontHandle.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef(pObject);
    v4 = (Scaleform::Render::RenderBuffer *)this->pFontHandle.pObject;
    v7 = v4;
    v5 = 1;
    v2 = v4;
  }
  else
  {
    v7 = 0i64;
    v5 = 2;
    v4 = 0i64;
  }
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v2 )
      Scaleform::RefCountImpl::Release(v2);
  }
  if ( (v5 & 1) != 0 && v4 )
    Scaleform::RefCountImpl::Release(v4);
  return v7;
}

// File Line: 278
// RVA: 0x9873E0
Scaleform::Render::Text::HTMLImageTagDesc *__fastcall Scaleform::Render::Text::TextFormat::GetImageDesc(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::HTMLImageTagDesc *v2; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v4; // rbx
  char v5; // di
  bool v6; // zf
  Scaleform::Render::Text::HTMLImageTagDesc *v8; // [rsp+40h] [rbp+8h]

  v2 = 0i64;
  if ( (this->PresentMask & 0x200) != 0 )
  {
    pObject = this->pImageDesc.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v4 = this->pImageDesc.pObject;
    v8 = v4;
    v5 = 1;
    v2 = v4;
  }
  else
  {
    v8 = 0i64;
    v5 = 2;
    v4 = 0i64;
  }
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v2 )
    {
      v6 = v2->RefCount-- == 1;
      if ( v6 )
        v2->vfptr->__vecDelDtor(v2, 1u);
    }
  }
  if ( (v5 & 1) != 0 )
  {
    if ( v4 )
    {
      v6 = v4->RefCount-- == 1;
      if ( v6 )
        v4->vfptr->__vecDelDtor(v4, 1u);
    }
  }
  return v8;
}

// File Line: 300
// RVA: 0x700EF0
bool __fastcall Scaleform::Render::Text::TextFormat::IsUrlSet(Scaleform::Render::Text::TextFormat *this)
{
  return (this->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&this->Url);
}

// File Line: 307
// RVA: 0x94E930
bool __fastcall Scaleform::Render::Text::TextFormat::operator==(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *f)
{
  unsigned __int16 PresentMask; // dx
  unsigned __int16 v5; // cx
  bool v6; // cl
  Scaleform::Render::Text::FontHandle *v7; // rcx
  Scaleform::Render::Text::FontHandle *v8; // rdx
  bool IsUrlSet; // bl
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v11; // rdx
  bool result; // al

  PresentMask = f->PresentMask;
  v5 = this->PresentMask;
  result = 0;
  if ( v5 == PresentMask
    && this->FormatFlags == f->FormatFlags
    && this->ColorV == f->ColorV
    && this->FontSize == f->FontSize )
  {
    v6 = (v5 & 4) != 0;
    if ( v6 == ((PresentMask & 4) != 0)
      && (!v6
       || !stricmp(
             (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             (const char *)((f->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)))
      && f->LetterSpacing == this->LetterSpacing
      && ((this->PresentMask & 0x800) != 0) == ((f->PresentMask & 0x800) != 0) )
    {
      if ( (this->PresentMask & 0x800) == 0
        || (v7 = this->pFontHandle.pObject, v8 = f->pFontHandle.pObject, v7 == v8)
        || v7 && v8 && Scaleform::Render::Text::FontHandle::operator==(v7, v8) )
      {
        IsUrlSet = Scaleform::Render::Text::TextFormat::IsUrlSet(f);
        if ( Scaleform::Render::Text::TextFormat::IsUrlSet(this) == IsUrlSet
          && (!Scaleform::Render::Text::TextFormat::IsUrlSet(this)
           || !stricmp(
                 (const char *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                 (const char *)((f->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))) )
        {
          pObject = this->pImageDesc.pObject;
          if ( pObject )
          {
            v11 = f->pImageDesc.pObject;
            if ( v11 )
            {
              if ( Scaleform::Render::Text::HTMLImageTagDesc::operator==(this->pImageDesc.pObject, v11) )
                return 1;
            }
          }
          if ( pObject == f->pImageDesc.pObject )
            return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 396
// RVA: 0x940660
void __fastcall Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *src,
        Scaleform::Render::Text::Allocator *allocator)
{
  this->pAllocator = allocator;
  this->RefCount = 1;
  this->pTabStops = 0i64;
  this->BlockIndent = src->BlockIndent;
  this->Indent = src->Indent;
  this->Leading = src->Leading;
  this->LeftMargin = src->LeftMargin;
  this->RightMargin = src->RightMargin;
  this->PresentMask = src->PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, src->pTabStops);
}

// File Line: 402
// RVA: 0x70FCB0
void __fastcall Scaleform::Render::Text::ParagraphFormat::Release(Scaleform::Render::Text::ParagraphFormat *this)
{
  if ( this->RefCount-- == 1 )
  {
    Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(this);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
  }
}

// File Line: 461
// RVA: 0x71C410
void __fastcall Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int num)
{
  Scaleform::Render::Text::ParagraphFormat::AllocTabStops(this, num);
  this->PresentMask |= 0x40u;
}

// File Line: 481
// RVA: 0x94E8D0
bool __fastcall Scaleform::Render::Text::ParagraphFormat::operator==(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *f)
{
  return this->PresentMask == f->PresentMask
      && this->BlockIndent == f->BlockIndent
      && this->Indent == f->Indent
      && this->Leading == f->Leading
      && this->LeftMargin == f->LeftMargin
      && this->RightMargin == f->RightMargin
      && Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(this, f->pTabStops);
}

// File Line: 566
// RVA: 0x6C6E10
void __fastcall Scaleform::Render::Text::Allocator::Allocator(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::MemoryHeap *pheap,
        char flags)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::Allocator,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::Allocator::`vftable;
  this->TextFormatStorage.pTable = 0i64;
  this->ParagraphFormatStorage.pTable = 0i64;
  this->TextFormatStorageCap = 100;
  this->ParagraphFormatStorageCap = 100;
  this->NewParagraphId = 1;
  this->pHeap = pheap;
  Scaleform::Render::Text::TextFormat::TextFormat(&this->EntryTextFormat, pheap);
  this->Flags = flags;
}

// File Line: 616
// RVA: 0x78E630
void __fastcall Scaleform::Render::Text::Allocator::TextFormatVisitor::~TextFormatVisitor(
        Scaleform::Render::Text::Allocator::TextFormatVisitor *this)
{
  this->vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&Scaleform::Render::Text::Allocator::TextFormatVisitor::`vftable;
}

