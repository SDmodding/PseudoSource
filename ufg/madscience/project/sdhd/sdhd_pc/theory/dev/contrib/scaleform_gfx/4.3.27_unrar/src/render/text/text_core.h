// File Line: 94
// RVA: 0x6C9230
void __fastcall Scaleform::Render::Text::ImageDesc::ImageDesc(Scaleform::Render::Text::ImageDesc *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::ImageDesc,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::ImageDesc::`vftable';
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
void __fastcall Scaleform::Render::Text::HTMLImageTagDesc::HTMLImageTagDesc(Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::ImageDesc,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::ImageDesc::`vftable';
  this->pImage.pObject = 0i64;
  *(_QWORD *)&this->BaseLineX = 0i64;
  *(_QWORD *)&this->ScreenWidth = 0i64;
  *(_OWORD *)&this->Matrix.M[0][0] = 0x3F800000ui64;
  this->Matrix.M[1][0] = 0.0;
  *(_QWORD *)&this->Matrix.M[1][1] = 1065353216i64;
  this->Matrix.M[1][3] = 0.0;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::HTMLImageTagDesc::`vftable';
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 1;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->Id.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 1;
  *(_QWORD *)&this->VSpace = 0i64;
  this->ParaId = -1;
  this->Alignment = 0;
}

// File Line: 129
// RVA: 0x94E830
char __fastcall Scaleform::Render::Text::HTMLImageTagDesc::operator==(Scaleform::Render::Text::HTMLImageTagDesc *this, Scaleform::Render::Text::HTMLImageTagDesc *f)
{
  Scaleform::Render::Text::HTMLImageTagDesc *v2; // r9
  Scaleform::Render::Text::HTMLImageTagDesc *v3; // r10
  unsigned __int8 *v4; // rax
  unsigned __int64 v5; // r8
  int v6; // ecx
  int v7; // edx
  unsigned __int8 *v8; // rax
  int v9; // ecx
  int v10; // edx
  char result; // al

  v2 = f;
  v3 = this;
  v4 = (unsigned __int8 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v5 = (f->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v6 = v4[v5];
    v7 = *v4 - v6;
    if ( *v4 != v6 )
      break;
    ++v4;
  }
  while ( v6 );
  if ( v7 )
    goto LABEL_17;
  v8 = (unsigned __int8 *)((v3->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  do
  {
    v9 = v8[(v2->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v3->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)];
    v10 = *v8 - v9;
    if ( *v8 != v9 )
      break;
    ++v8;
  }
  while ( v9 );
  if ( v10
    || v3->VSpace != v2->VSpace
    || v3->HSpace != v2->HSpace
    || v3->ParaId != v2->ParaId
    || v3->Alignment != v2->Alignment )
  {
LABEL_17:
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

// File Line: 256
// RVA: 0x714620
void __fastcall Scaleform::Render::Text::TextFormat::SetFontSize(Scaleform::Render::Text::TextFormat *this, float fontSize)
{
  if ( fontSize >= 3276.8 )
  {
    this->PresentMask |= 8u;
    this->FontSize = -1;
  }
  else
  {
    this->PresentMask |= 8u;
    this->FontSize = (signed int)(float)(fontSize * 20.0);
  }
}

// File Line: 274
// RVA: 0x7E9880
Scaleform::Render::RenderBuffer *__fastcall Scaleform::Render::Text::TextFormat::GetFontHandle(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::TextFormat *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rbx
  char v5; // di
  Scaleform::Render::RenderBuffer *v7; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = 0i64;
  if ( (v1->PresentMask >> 11) & 1 )
  {
    v3 = (Scaleform::GFx::Resource *)v1->pFontHandle.pObject;
    if ( v3 )
      Scaleform::Render::RenderBuffer::AddRef(v3);
    v4 = (Scaleform::Render::RenderBuffer *)v1->pFontHandle.pObject;
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
  if ( v5 & 2 )
  {
    v5 &= 0xFDu;
    if ( v2 )
      Scaleform::RefCountImpl::Release(v2);
  }
  if ( v5 & 1 && v4 )
    Scaleform::RefCountImpl::Release(v4);
  return v7;
}

// File Line: 278
// RVA: 0x9873E0
Scaleform::Render::Text::HTMLImageTagDesc *__fastcall Scaleform::Render::Text::TextFormat::GetImageDesc(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::TextFormat *v1; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v2; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v3; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v4; // rbx
  char v5; // di
  bool v6; // zf
  Scaleform::Render::Text::HTMLImageTagDesc *v8; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = 0i64;
  if ( (v1->PresentMask >> 9) & 1 )
  {
    v3 = v1->pImageDesc.pObject;
    if ( v3 )
      ++v3->RefCount;
    v4 = v1->pImageDesc.pObject;
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
  if ( v5 & 2 )
  {
    v5 &= 0xFDu;
    if ( v2 )
    {
      v6 = v2->RefCount-- == 1;
      if ( v6 )
        v2->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
    }
  }
  if ( v5 & 1 )
  {
    if ( v4 )
    {
      v6 = v4->RefCount-- == 1;
      if ( v6 )
        v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
    }
  }
  return v8;
}

// File Line: 300
// RVA: 0x700EF0
bool __fastcall Scaleform::Render::Text::TextFormat::IsUrlSet(Scaleform::Render::Text::TextFormat *this)
{
  return this->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&this->Url.0);
}

// File Line: 307
// RVA: 0x94E930
bool __fastcall Scaleform::Render::Text::TextFormat::operator==(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *f)
{
  Scaleform::Render::Text::TextFormat *v2; // rdi
  unsigned __int16 v3; // dx
  Scaleform::Render::Text::TextFormat *v4; // rsi
  unsigned __int16 v5; // cx
  char v6; // cl
  char v7; // cl
  Scaleform::Render::Text::FontHandle *v8; // rcx
  Scaleform::Render::Text::FontHandle *v9; // rdx
  bool v10; // bl
  Scaleform::Render::Text::HTMLImageTagDesc *v11; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v12; // rdx
  bool result; // al

  v2 = f;
  v3 = f->PresentMask;
  v4 = this;
  v5 = this->PresentMask;
  result = 0;
  if ( v5 == v3 && v4->FormatFlags == v2->FormatFlags && v4->ColorV == v2->ColorV && v4->FontSize == v2->FontSize )
  {
    v6 = ((unsigned __int8)v5 >> 2) & 1;
    if ( v6 == (((unsigned __int8)v3 >> 2) & 1)
      && (!v6
       || !stricmp(
             (const char *)((v4->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             (const char *)((v2->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)))
      && v2->LetterSpacing == v4->LetterSpacing )
    {
      v7 = (v4->PresentMask >> 11) & 1;
      if ( v7 == ((v2->PresentMask >> 11) & 1) )
      {
        if ( !v7
          || (v8 = v4->pFontHandle.pObject, v9 = v2->pFontHandle.pObject, v8 == v9)
          || v8 && v9 && Scaleform::Render::Text::FontHandle::operator==(v8, v9) )
        {
          v10 = Scaleform::Render::Text::TextFormat::IsUrlSet(v2);
          if ( Scaleform::Render::Text::TextFormat::IsUrlSet(v4) == v10
            && (!Scaleform::Render::Text::TextFormat::IsUrlSet(v4)
             || !stricmp(
                   (const char *)((v4->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                   (const char *)((v2->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))) )
          {
            if ( (v11 = v4->pImageDesc.pObject) != 0i64
              && (v12 = v2->pImageDesc.pObject) != 0i64
              && Scaleform::Render::Text::HTMLImageTagDesc::operator==(v4->pImageDesc.pObject, v12)
              || v11 == v2->pImageDesc.pObject )
            {
              result = 1;
            }
          }
        }
      }
    }
  }
  return result;
}

// File Line: 396
// RVA: 0x940660
void __fastcall Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(Scaleform::Render::Text::ParagraphFormat *this, Scaleform::Render::Text::ParagraphFormat *src, Scaleform::Render::Text::Allocator *allocator)
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
  bool v1; // zf
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx

  v1 = this->RefCount-- == 1;
  v2 = this;
  if ( v1 )
  {
    Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(this);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
}

// File Line: 461
// RVA: 0x71C410
void __fastcall Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(Scaleform::Render::Text::ParagraphFormat *this, unsigned int num)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx

  v2 = this;
  Scaleform::Render::Text::ParagraphFormat::AllocTabStops(this, num);
  v2->PresentMask |= 0x40u;
}

// File Line: 481
// RVA: 0x94E8D0
bool __fastcall Scaleform::Render::Text::ParagraphFormat::operator==(Scaleform::Render::Text::ParagraphFormat *this, Scaleform::Render::Text::ParagraphFormat *f)
{
  return this->PresentMask == f->PresentMask
      && *(_QWORD *)&this->BlockIndent == *(_QWORD *)&f->BlockIndent
      && this->RightMargin == f->RightMargin
      && Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(this, f->pTabStops);
}

// File Line: 566
// RVA: 0x6C6E10
void __fastcall Scaleform::Render::Text::Allocator::Allocator(Scaleform::Render::Text::Allocator *this, Scaleform::MemoryHeap *pheap, char flags)
{
  char v3; // bl
  Scaleform::Render::Text::Allocator *v4; // rdi

  v3 = flags;
  v4 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::Allocator,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::Allocator::`vftable';
  this->TextFormatStorage.pTable = 0i64;
  this->ParagraphFormatStorage.pTable = 0i64;
  this->TextFormatStorageCap = 100;
  this->ParagraphFormatStorageCap = 100;
  this->NewParagraphId = 1;
  this->pHeap = pheap;
  Scaleform::Render::Text::TextFormat::TextFormat(&this->EntryTextFormat, pheap);
  v4->Flags = v3;
}

// File Line: 616
// RVA: 0x78E630
void __fastcall Scaleform::Render::Text::Allocator::TextFormatVisitor::~TextFormatVisitor(Scaleform::Render::Text::Allocator::TextFormatVisitor *this)
{
  this->vfptr = (Scaleform::Render::Text::Allocator::TextFormatVisitorVtbl *)&Scaleform::Render::Text::Allocator::TextFormatVisitor::`vftable';
}

