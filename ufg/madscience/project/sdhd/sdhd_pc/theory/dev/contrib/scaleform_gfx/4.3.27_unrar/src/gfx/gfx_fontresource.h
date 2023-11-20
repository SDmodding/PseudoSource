// File Line: 123
// RVA: 0x89EE90
void __fastcall Scaleform::GFx::TextureGlyphData::TextureGlyphData(Scaleform::GFx::TextureGlyphData *this, unsigned int glyphCount, bool isLoadedFromFile)
{
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy> *v3; // r14
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,261>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::TextureGlyphData,261>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextureGlyphData::`vftable';
  this->PackTextureConfig.NominalSize = 48;
  this->PackTextureConfig.PadPixels = 3;
  this->PackTextureConfig.TextureWidth = 1024;
  this->PackTextureConfig.TextureHeight = 1024;
  v3 = (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy> *)&this->TextureGlyphs.Data.Data;
  v3->Data = 0i64;
  v3->Size = 0i64;
  v3->Policy.Capacity = 0i64;
  this->GlyphsTextures.mHash.pTable = 0i64;
  this->FileCreation = isLoadedFromFile;
  v4 = glyphCount;
  v5 = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v3,
    v3,
    glyphCount);
  if ( v4 > v5 )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(&v3->Data[v5], v4 - v5);
}

// File Line: 156
// RVA: 0x8A85F0
void __fastcall Scaleform::GFx::TextureGlyphData::TextureGlyphVisitor::~TextureGlyphVisitor(Scaleform::GFx::TextureGlyphData::TextureGlyphVisitor *this)
{
  this->vfptr = (Scaleform::GFx::TextureGlyphData::TextureGlyphVisitorVtbl *)&Scaleform::GFx::TextureGlyphData::TextureGlyphVisitor::`vftable';
}

// File Line: 260
// RVA: 0x90E6B0
void __fastcall Scaleform::GFx::FontData::SetTextureGlyphData(Scaleform::GFx::FontData *this, void *pvdata)
{
  Scaleform::GFx::TextureGlyphData *v2; // rbx
  Scaleform::GFx::FontData *v3; // rdi
  Scaleform::GFx::TextureGlyphData *v4; // rcx

  v2 = (Scaleform::GFx::TextureGlyphData *)pvdata;
  v3 = this;
  if ( pvdata )
    ++*((_DWORD *)pvdata + 2);
  v4 = this->pTGData.pObject;
  if ( v4 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
    v3->pTGData.pObject = v2;
  }
  else
  {
    v3->pTGData.pObject = (Scaleform::GFx::TextureGlyphData *)pvdata;
  }
}

// File Line: 269
// RVA: 0x8E32B0
bool __fastcall Scaleform::GFx::FontData::HasVectorOrRasterGlyphs(Scaleform::GFx::FontData *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v1; // rcx
  bool result; // al

  v1 = this->CodeTable.mHash.pTable;
  if ( v1 )
    result = v1->EntryCount != 0;
  else
    result = 0;
  return result;
}

// File Line: 441
// RVA: 0x8DB610
const char *__fastcall Scaleform::GFx::FontDataBound::GetName(Scaleform::GFx::FontDataBound *this)
{
  return (const char *)((__int64 (*)(void))this->pFont.pObject->vfptr[1].__vecDelDtor)();
}

// File Line: 447
// RVA: 0x8D9760
__int64 __fastcall Scaleform::GFx::FontDataBound::GetGlyphIndex(Scaleform::GFx::FontDataBound *this, __int64 code)
{
  return this->pFont.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)this->pFont.pObject, code);
}

// File Line: 449
// RVA: 0x8D4CB0
void __fastcall Scaleform::GFx::FontDataBound::GetAdvance(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex)
{
  this->pFont.pObject->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)this->pFont.pObject, glyphIndex);
}

// File Line: 451
// RVA: 0x8DA8B0
void __fastcall Scaleform::GFx::FontDataBound::GetKerningAdjustment(Scaleform::GFx::FontDataBound *this, __int64 lastCode, __int64 thisCode)
{
  ((void (__fastcall *)(Scaleform::Render::Font *, __int64, __int64))this->pFont.pObject->vfptr[4].__vecDelDtor)(
    this->pFont.pObject,
    lastCode,
    thisCode);
}

// File Line: 454
// RVA: 0x8D97E0
void __fastcall Scaleform::GFx::FontDataBound::GetGlyphWidth(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex)
{
  this->pFont.pObject->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)this->pFont.pObject, glyphIndex);
}

// File Line: 455
// RVA: 0x8D96C0
void __fastcall Scaleform::GFx::FontDataBound::GetGlyphHeight(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex)
{
  this->pFont.pObject->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)this->pFont.pObject, glyphIndex);
}

// File Line: 457
// RVA: 0x8D9510
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::FontDataBound::GetGlyphBounds(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex, Scaleform::Render::Rect<float> *prect)
{
  return (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::Render::Font *, __int64, Scaleform::Render::Rect<float> *))this->pFont.pObject->vfptr[7].__vecDelDtor)(
                                             this->pFont.pObject,
                                             glyphIndex,
                                             prect);
}

// File Line: 463
// RVA: 0x8E7350
__int64 __fastcall Scaleform::GFx::FontDataBound::IsHintedVectorGlyph(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex, __int64 hintedSize)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Font *, __int64, __int64))this->pFont.pObject->vfptr[8].__vecDelDtor)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize);
}

// File Line: 469
// RVA: 0x8E7340
__int64 __fastcall Scaleform::GFx::FontDataBound::IsHintedRasterGlyph(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex, __int64 hintedSize)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Font *, __int64, __int64))this->pFont.pObject->vfptr[9].__vecDelDtor)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize);
}

// File Line: 481
// RVA: 0x8DF330
void __fastcall Scaleform::GFx::FontDataBound::GetTextureGlyphHeight(Scaleform::GFx::FontDataBound *this)
{
  ((void (*)(void))this->pFont.pObject->vfptr[13].__vecDelDtor)();
}

// File Line: 487
// RVA: 0x8DC100
Scaleform::Render::ShapeDataInterface *__fastcall Scaleform::GFx::FontDataBound::GetPermanentGlyphShape(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex)
{
  return (Scaleform::Render::ShapeDataInterface *)this->pFont.pObject->vfptr[14].__vecDelDtor(
                                                    (Scaleform::RefCountImplCore *)this->pFont.pObject,
                                                    glyphIndex);
}

// File Line: 496
// RVA: 0x8DE800
__int64 __fastcall Scaleform::GFx::FontDataBound::GetTemporaryGlyphShape(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex, __int64 hintedSize, Scaleform::Render::GlyphShape *shape)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Font *, __int64, __int64, Scaleform::Render::GlyphShape *))this->pFont.pObject->vfptr[15].__vecDelDtor)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize,
           shape);
}

// File Line: 504
// RVA: 0x8D9770
__int64 __fastcall Scaleform::GFx::FontDataBound::GetGlyphRaster(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex, __int64 hintedSize, Scaleform::Render::GlyphRaster *raster)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Font *, __int64, __int64, Scaleform::Render::GlyphRaster *))this->pFont.pObject->vfptr[16].__vecDelDtor)(
           this->pFont.pObject,
           glyphIndex,
           hintedSize,
           raster);
}

// File Line: 516
// RVA: 0x8D5F10
__int64 __fastcall Scaleform::GFx::FontDataBound::GetCharValue(Scaleform::GFx::FontDataBound *this, __int64 glyphIndex)
{
  return this->pFont.pObject->vfptr[17].__vecDelDtor((Scaleform::RefCountImplCore *)this->pFont.pObject, glyphIndex);
}

// File Line: 522
// RVA: 0x8D9780
__int64 __fastcall Scaleform::GFx::FontDataBound::GetGlyphShapeCount(Scaleform::GFx::FontDataBound *this)
{
  return ((__int64 (*)(void))this->pFont.pObject->vfptr[18].__vecDelDtor)();
}

// File Line: 524
// RVA: 0x8E32D0
__int64 __fastcall Scaleform::GFx::FontDataBound::HasVectorOrRasterGlyphs(Scaleform::GFx::FontDataBound *this)
{
  return ((__int64 (*)(void))this->pFont.pObject->vfptr[19].__vecDelDtor)();
}

// File Line: 527
// RVA: 0x8D5E10
Scaleform::String *__fastcall Scaleform::GFx::FontDataBound::GetCharRanges(Scaleform::GFx::FontDataBound *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  ((void (__cdecl *)(Scaleform::Render::Font *, Scaleform::String *))this->pFont.pObject->vfptr[20].__vecDelDtor)(
    this->pFont.pObject,
    result);
  return v2;
}

// File Line: 530
// RVA: 0x8DC020
void __fastcall Scaleform::GFx::FontDataBound::GetNominalGlyphWidth(Scaleform::GFx::FontDataBound *this)
{
  ((void (*)(void))this->pFont.pObject->vfptr[21].__vecDelDtor)();
}

// File Line: 531
// RVA: 0x8DC000
void __fastcall Scaleform::GFx::FontDataBound::GetNominalGlyphHeight(Scaleform::GFx::FontDataBound *this)
{
  ((void (*)(void))this->pFont.pObject->vfptr[22].__vecDelDtor)();
}

// File Line: 653
// RVA: 0x8DA8C0
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::FontResource::GetKey(Scaleform::GFx::MovieDataDef *this, Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey *v2; // rbx
  Scaleform::GFx::MovieDataDef *v3; // rdi
  Scaleform::GFx::ResourceKey::KeyInterface *v4; // rcx

  v2 = result;
  v3 = this;
  v4 = this->mResourceKey.pKeyInterface;
  if ( v4 )
    v4->vfptr->AddRef(v4, v3->mResourceKey.hKeyData);
  v2->pKeyInterface = v3->mResourceKey.pKeyInterface;
  v2->hKeyData = v3->mResourceKey.hKeyData;
  return v2;
}

