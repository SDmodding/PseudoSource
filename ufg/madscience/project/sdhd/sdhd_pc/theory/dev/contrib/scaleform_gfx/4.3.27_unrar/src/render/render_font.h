// File Line: 55
// RVA: 0x93CCA0
void __fastcall Scaleform::Render::GlyphShape::GlyphShape(Scaleform::Render::GlyphShape *this)
{
  Scaleform::ArrayLH<Scaleform::Render::FillStyleType,2,Scaleform::ArrayDefaultPolicy> *v1; // rax
  Scaleform::ArrayLH<Scaleform::Render::StrokeStyleType,2,Scaleform::ArrayDefaultPolicy> *v2; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::`vftable;
  this->pContainer = &this->Data;
  this->Decoder.Decoder.Data = &this->Data;
  this->Decoder.OneOverMultiplier = 1.0;
  this->StartingPos = 0;
  this->Multiplier = 1.0;
  v1 = &this->FillStyles;
  v1->Data.Data = 0i64;
  v1->Data.Size = 0i64;
  v1->Data.Policy.Capacity = 0i64;
  v2 = &this->StrokeStyles;
  v2->Data.Data = 0i64;
  v2->Data.Size = 0i64;
  v2->Data.Policy.Capacity = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphShape::`vftable;
  this->Data.Data.Data = 0i64;
  this->Data.Data.Size = 0i64;
  this->Data.Data.Policy.Capacity = 0i64;
  this->HintedSize = 0;
  *(_QWORD *)&this->Bounds.x1 = 0i64;
  *(_QWORD *)&this->Bounds.x2 = 0i64;
}

// File Line: 57
// RVA: 0x95F570
void __fastcall Scaleform::Render::GlyphShape::Clear(Scaleform::Render::GlyphShape *this)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx

  v1 = &this->Data;
  if ( this->Data.Data.Size && this->Data.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      &this->Data,
      0i64);
  v1->Data.Size = 0i64;
}

// File Line: 58
// RVA: 0x9976F0
_BOOL8 __fastcall Scaleform::Render::GlyphShape::IsEmpty(Scaleform::Render::GlyphShape *this)
{
  return this->Data.Data.Size == 0;
}

// File Line: 99
// RVA: 0x8A4630
void __fastcall Scaleform::Render::FontCacheHandleRef::~FontCacheHandleRef(Scaleform::Render::FontCacheHandleRef *this)
{
  Scaleform::Render::FontCacheHandleRef::releaseFont(this);
}

// File Line: 119
// RVA: 0x8A45F0
void __fastcall Scaleform::Render::Font::~Font(Scaleform::Render::Font *this)
{
  Scaleform::Render::Font *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 274
// RVA: 0x8D5B80
Scaleform::String *__fastcall Scaleform::Render::Font::GetCharRanges(Scaleform::Render::Font *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  Scaleform::String::String(result, &customWorldMapCaption);
  return v2;
}

// File Line: 277
// RVA: 0x8DC010
float __fastcall Scaleform::Render::Font::GetNominalGlyphWidth(Scaleform::Render::Font *this)
{
  return FLOAT_512_0;
}

// File Line: 278
// RVA: 0x8DBFF0
float __fastcall Scaleform::Render::Font::GetNominalGlyphHeight(Scaleform::Render::Font *this)
{
  return FLOAT_1024_0;
}

// File Line: 384
// RVA: 0x94A4F0
void __fastcall Scaleform::Render::FontProvider::~FontProvider(Scaleform::Render::FontProvider *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProvider::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

