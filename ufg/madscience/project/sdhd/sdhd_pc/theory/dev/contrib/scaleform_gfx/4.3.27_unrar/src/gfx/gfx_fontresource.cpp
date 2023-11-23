// File Line: 35
// RVA: 0x89EC90
void __fastcall Scaleform::GFx::TextureGlyphData::TextureGlyphData(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::TextureGlyphData *orig)
{
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *p_TextureGlyphs; // r14
  __int64 v4; // rbx
  Scaleform::HashLH<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>,261,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *p_GlyphsTextures; // r15
  unsigned __int64 Size; // rsi
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  __int64 v9; // rdi
  Scaleform::GFx::ResourceId *v10; // rbp
  __int64 v11; // rcx
  _QWORD *v12; // rax
  Scaleform::GFx::ResourceId *pFirst; // rdi
  __int64 v14; // rax
  __int64 v15; // rdx
  unsigned __int64 v16; // rcx
  _QWORD *v17; // rax
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [rsp+30h] [rbp-88h] BYREF
  Scaleform::Render::TextureGlyph v19; // [rsp+40h] [rbp-78h]

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,261>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::TextureGlyphData,261>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextureGlyphData::`vftable;
  this->PackTextureConfig = orig->PackTextureConfig;
  p_TextureGlyphs = &this->TextureGlyphs;
  v4 = 0i64;
  this->TextureGlyphs.Data.Data = 0i64;
  this->TextureGlyphs.Data.Size = 0i64;
  this->TextureGlyphs.Data.Policy.Capacity = 0i64;
  p_GlyphsTextures = &this->GlyphsTextures;
  this->GlyphsTextures.mHash.pTable = 0i64;
  this->FileCreation = orig->FileCreation;
  Size = orig->TextureGlyphs.Data.Size;
  v7 = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    Size);
  if ( Size > v7 )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      &p_TextureGlyphs->Data.Data[v7],
      Size - v7);
  v8 = orig->TextureGlyphs.Data.Size;
  if ( v8 )
  {
    v9 = 0i64;
    do
    {
      v19 = *Scaleform::Render::TextureGlyph::operator=(
               &p_TextureGlyphs->Data.Data[v9],
               &orig->TextureGlyphs.Data.Data[v9]);
      ++v9;
      --v8;
    }
    while ( v8 );
  }
  v10 = (Scaleform::GFx::ResourceId *)&orig->GlyphsTextures;
  v11 = *(_QWORD *)&v10->Id;
  if ( *(_QWORD *)&v10->Id )
  {
    v12 = (_QWORD *)(v11 + 16);
    do
    {
      if ( *v12 != -2i64 )
        break;
      ++v4;
      v12 += 5;
    }
    while ( (unsigned __int64)v4 <= *(_QWORD *)(v11 + 8) );
    key.pFirst = v10;
  }
  else
  {
    key.pFirst = 0i64;
  }
  key.pSecond = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)v4;
  pFirst = key.pFirst;
  while ( pFirst )
  {
    v14 = *(_QWORD *)&pFirst->Id;
    if ( !*(_QWORD *)&pFirst->Id || v4 > *(_QWORD *)(v14 + 8) )
      break;
    v15 = v14 + 40 * v4;
    key.pFirst = (Scaleform::GFx::ResourceId *)(v15 + 32);
    key.pSecond = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)(v15 + 40);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
      &p_GlyphsTextures->mHash,
      p_GlyphsTextures,
      &key);
    v16 = *(_QWORD *)(*(_QWORD *)&pFirst->Id + 8i64);
    if ( v4 <= (__int64)v16 && ++v4 <= v16 )
    {
      v17 = (_QWORD *)(*(_QWORD *)&pFirst->Id + 8 * (v4 + 4 * v4 + 2));
      do
      {
        if ( *v17 != -2i64 )
          break;
        ++v4;
        v17 += 5;
      }
      while ( v4 <= v16 );
    }
  }
}

// File Line: 52
// RVA: 0x8DF230
Scaleform::Render::TextureGlyph *__fastcall Scaleform::GFx::TextureGlyphData::GetTextureGlyph(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphIndex)
{
  if ( glyphIndex < this->TextureGlyphs.Data.Size )
    return &this->TextureGlyphs.Data.Data[(unsigned __int64)glyphIndex];
  if ( (_S12_14 & 1) == 0 )
  {
    _S12_14 |= 1u;
    dummyTextureGlyph.RefCount = 1;
    dummyTextureGlyph.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable;
    dummyTextureGlyph.pImage.pObject = 0i64;
    dummyTextureGlyph.UvBounds = 0i64;
    dummyTextureGlyph.BindIndex = -1;
    atexit(Scaleform::GFx::TextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__);
  }
  return &dummyTextureGlyph;
}

// File Line: 65
// RVA: 0x8B3160
void __fastcall Scaleform::GFx::TextureGlyphData::AddTextureGlyph(
        Scaleform::GFx::TextureGlyphData *this,
        unsigned int glyphIndex,
        Scaleform::Render::TextureGlyph *glyph)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 Size; // rbx
  unsigned __int64 v7; // rsi

  v3 = glyphIndex;
  if ( this->TextureGlyphs.Data.Size > glyphIndex )
    goto LABEL_5;
  Size = this->TextureGlyphs.Data.Size;
  v7 = glyphIndex + 1;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->TextureGlyphs.Data,
    &this->TextureGlyphs,
    v7);
  if ( v7 > Size )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      &this->TextureGlyphs.Data.Data[Size],
      v7 - Size);
  if ( this->TextureGlyphs.Data.Size > v3 )
LABEL_5:
    Scaleform::Render::TextureGlyph::operator=(&this->TextureGlyphs.Data.Data[v3], glyph);
}

// File Line: 113
// RVA: 0x8B3050
void __fastcall Scaleform::GFx::TextureGlyphData::AddTexture(
        Scaleform::GFx::TextureGlyphData *this,
        Scaleform::GFx::ResourceId *textureId,
        Scaleform::GFx::ResourceHandle *rh)
{
  Scaleform::GFx::Resource *pResource; // rdx
  __int64 v5; // rdi
  __int64 v6; // rcx
  Scaleform::GFx::ResourceHandle::HandleType HType; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::Resource *v8; // [rsp+30h] [rbp-38h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [rsp+38h] [rbp-30h] BYREF

  HType = RH_Pointer;
  v8 = 0i64;
  if ( rh->HType == RH_Pointer )
  {
    pResource = rh->pResource;
    if ( pResource )
      _InterlockedExchangeAdd(&pResource->RefCount.Value, 1u);
  }
  HType = rh->HType;
  v8 = rh->pResource;
  key.pFirst = textureId;
  key.pSecond = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)&HType;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
    &this->GlyphsTextures.mHash,
    &this->GlyphsTextures,
    &key);
  if ( HType == RH_Pointer )
  {
    v5 = (__int64)v8;
    if ( v8 )
    {
      if ( !_InterlockedDecrement(&v8->RefCount.Value) )
      {
        v6 = *(_QWORD *)(v5 + 16);
        if ( v6 )
        {
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v6 + 8i64))(v6, v5);
          *(_QWORD *)(v5 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, __int64))v5)(v5, 1i64);
      }
    }
  }
}

// File Line: 186
// RVA: 0x8DF210
Scaleform::Render::TextureGlyph *__fastcall Scaleform::GFx::FontDataBound::GetTextureGlyph(
        Scaleform::GFx::FontDataBound *this,
        unsigned int glyphIndex)
{
  Scaleform::GFx::TextureGlyphData *pObject; // rcx

  pObject = this->pTGData.pObject;
  if ( pObject && glyphIndex < LODWORD(pObject->TextureGlyphs.Data.Size) )
    return Scaleform::GFx::TextureGlyphData::GetTextureGlyph(pObject, glyphIndex);
  else
    return 0i64;
}

// File Line: 193
// RVA: 0x8DF300
float __fastcall Scaleform::GFx::FontData::GetTextureGlyphHeight(Scaleform::GFx::FontData *this)
{
  Scaleform::GFx::TextureGlyphData *pObject; // rax

  pObject = this->pTGData.pObject;
  if ( pObject )
    return (double)pObject->PackTextureConfig.NominalSize * 1024.0 * 0.0006510416666666666;
  else
    return 0.0;
}

// File Line: 200
// RVA: 0x896480
void __fastcall Scaleform::GFx::FontData::FontData(Scaleform::GFx::FontData *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  *(_QWORD *)&this->Ascent = 0i64;
  *(_QWORD *)&this->Leading = 0i64;
  *(_DWORD *)&this->LowerCaseTop = 0;
  this->hRef.pManager.Value = 0i64;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable;
  this->Name = 0i64;
  this->pTGData.pObject = 0i64;
  this->Glyphs.Data.Data = 0i64;
  this->Glyphs.Data.Size = 0i64;
  this->Glyphs.Data.Policy.Capacity = 0i64;
  this->CodeTable.mHash.pTable = 0i64;
  this->AdvanceTable.Data.Data = 0i64;
  this->AdvanceTable.Data.Size = 0i64;
  this->AdvanceTable.Data.Policy.Capacity = 0i64;
  this->KerningPairs.mHash.pTable = 0i64;
}

// File Line: 205
// RVA: 0x896330
void __fastcall Scaleform::GFx::FontData::FontData(
        Scaleform::GFx::FontData *this,
        const char *name,
        unsigned int fontFlags)
{
  __int64 v5; // rbx
  __int64 v6; // rdx
  char *v7; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  *(_QWORD *)&this->Ascent = 0i64;
  this->Leading = 0.0;
  this->Flags = fontFlags;
  *(_DWORD *)&this->LowerCaseTop = 0;
  this->hRef.pManager.Value = 0i64;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable;
  this->Name = 0i64;
  this->pTGData.pObject = 0i64;
  this->Glyphs.Data.Data = 0i64;
  this->Glyphs.Data.Size = 0i64;
  this->Glyphs.Data.Policy.Capacity = 0i64;
  this->CodeTable.mHash.pTable = 0i64;
  this->AdvanceTable.Data.Data = 0i64;
  this->AdvanceTable.Data.Size = 0i64;
  this->AdvanceTable.Data.Policy.Capacity = 0i64;
  this->KerningPairs.mHash.pTable = 0i64;
  v5 = -1i64;
  v6 = -1i64;
  do
    ++v6;
  while ( name[v6] );
  v7 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v6 + 1, 0i64);
  this->Name = v7;
  if ( v7 )
  {
    do
      ++v5;
    while ( name[v5] );
    strcpy_s(v7, v5 + 1, name);
  }
  this->Flags |= 0x2000u;
}

// File Line: 215
// RVA: 0x8A4640
void __fastcall Scaleform::GFx::FontData::~FontData(Scaleform::GFx::FontData *this)
{
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *p_Glyphs; // rdi
  Scaleform::GFx::TextureGlyphData *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable;
  p_Glyphs = (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Glyphs;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Glyphs.Data,
    &this->Glyphs,
    0i64);
  if ( this->Name )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->Name = 0i64;
  }
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->KerningPairs);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->AdvanceTable.Data.Data);
  Scaleform::HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::~HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>((Scaleform::HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&this->CodeTable);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>(p_Glyphs);
  pObject = this->pTGData.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 228
// RVA: 0x8F6F80
void __fastcall Scaleform::GFx::FontData::Read(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdi
  Scaleform::GFx::TagType TagType; // eax
  __int64 Pos; // r9
  unsigned __int16 v8; // r8
  int v9; // r15d
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  _DWORD *v12; // rcx
  int v13; // r12d
  __int64 v14; // r15
  signed __int64 v15; // r13
  __int64 v16; // r8
  unsigned __int16 v17; // r9
  int v18; // r13d
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // r8
  _DWORD *v21; // rcx
  unsigned __int64 Size; // rbx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v23; // rcx
  unsigned __int64 v24; // rax
  signed __int64 v25; // rsi
  int v26; // r12d
  signed int v27; // ebx
  signed int FilePos; // edx
  unsigned int DataSize; // eax
  int v30; // eax
  unsigned int v31; // r15d
  Scaleform::GFx::Resource *v32; // rbx
  __int64 v33; // r15
  Scaleform::Render::RenderBuffer *v34; // rcx
  int *v35; // rdx
  const char *v36; // rdx
  unsigned int UInt; // eax
  bool v38; // bl
  bool v39; // r14
  bool v40; // al
  bool v41; // r12
  __int64 v42; // r9
  unsigned __int16 v43; // r8
  int v44; // r15d
  int v45; // r13d
  int v46; // eax
  __int64 v47; // r8
  int v48; // r15d
  unsigned int v49; // eax
  __int64 v50; // r9
  unsigned __int64 v51; // rbx
  unsigned __int64 v52; // r8
  int *v53; // rcx
  __int64 i; // r12
  __int64 v55; // r8
  int v56; // r15d
  unsigned __int64 v57; // rbx
  unsigned __int64 v58; // r8
  int *v59; // rcx
  __int64 v60; // r8
  float v61; // r12d
  unsigned int v62; // eax
  __int64 v63; // r15
  __int64 v64; // r9
  unsigned __int16 v65; // r8
  int v66; // r12d
  unsigned __int64 v67; // rbx
  unsigned __int64 v68; // r8
  int *v69; // rcx
  __int64 v70; // r9
  signed __int64 v71; // r13
  unsigned __int64 v72; // rbx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v73; // rcx
  unsigned __int64 v74; // rax
  int v75; // eax
  __int64 v76; // r15
  __int64 v77; // r13
  int *v78; // rdx
  signed int v79; // ebx
  signed int v80; // eax
  unsigned int v81; // r8d
  int v82; // eax
  int v83; // eax
  unsigned int v84; // r12d
  Scaleform::GFx::Resource *v85; // rbx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v86; // r12
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::FontData::AdvanceEntry *v88; // rcx
  float v89; // xmm2_4
  float v90; // xmm3_4
  float v91; // xmm0_4
  float v92; // xmm1_4
  unsigned __int64 Capacity_low; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::FontData::AdvanceEntry,261,Scaleform::ArrayDefaultPolicy> *p_AdvanceTable; // rsi
  unsigned __int64 v95; // r8
  _QWORD *v96; // r15
  unsigned __int64 v97; // rsi
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v98; // rcx
  __int64 k; // rdi
  int v100; // edx
  __int64 v101; // rax
  int v102; // ecx
  float v103; // xmm6_4
  __int64 v104; // r9
  __int16 v105; // r8
  __int64 v106; // r9
  __int16 v107; // r8
  __int64 v108; // r9
  __int16 v109; // r8
  unsigned __int64 v110; // rdx
  unsigned __int64 v111; // r15
  __int64 v112; // rbx
  Scaleform::GFx::FontData::AdvanceEntry *Data; // r12
  __int64 v114; // r9
  unsigned __int16 v115; // r8
  unsigned __int64 j; // rbx
  __int64 v117; // r9
  unsigned __int16 v118; // r8
  int v119; // r13d
  int v120; // r12d
  unsigned int v121; // edx
  unsigned int v122; // r8d
  unsigned int v123; // eax
  int v124; // edx
  __int64 v125; // r8
  __int16 v126; // r15
  __int64 v127; // r8
  __int16 v128; // bx
  unsigned int v129; // eax
  __int64 v130; // rdx
  __int64 v131; // rdx
  __int64 v132; // r9
  __int16 v133; // r8
  __int64 v134; // rdx
  unsigned __int64 v135; // r9
  char *Name; // r9
  unsigned __int64 v137; // rdx
  __int64 v138; // rcx
  int v139; // [rsp+20h] [rbp-A8h]
  unsigned int v140; // [rsp+28h] [rbp-A0h]
  char v141; // [rsp+30h] [rbp-98h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> v142; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v143; // [rsp+50h] [rbp-78h] BYREF
  __m256 pheapAddr; // [rsp+58h] [rbp-70h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+78h] [rbp-50h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v146; // [rsp+80h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeRef key; // [rsp+88h] [rbp-40h] BYREF
  Scaleform::GFx::Resource *v148; // [rsp+98h] [rbp-30h]
  Scaleform::GFx::Resource *v149; // [rsp+A0h] [rbp-28h]
  Scaleform::MemoryHeap *v150; // [rsp+A8h] [rbp-20h]
  __int64 v151; // [rsp+B0h] [rbp-18h]
  Scaleform::Render::Rect<float> pr; // [rsp+B8h] [rbp-10h] BYREF
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v153; // [rsp+120h] [rbp+58h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v154; // [rsp+128h] [rbp+60h]
  __m256 *p_pheapAddr; // [rsp+130h] [rbp+68h]

  v151 = -2i64;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v141 = 1;
  pHeap = p->pLoadData.pObject->pHeap;
  v150 = pHeap;
  TagType = tagInfo->TagType;
  if ( tagInfo->TagType == Tag_DefineFont )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "reading DefineFont\n");
    LODWORD(v143) = pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
    p_pheapAddr = &pheapAddr;
    memset(&pheapAddr, 0, 24);
    pAltStream->Stream.UnusedBits = 0;
    if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v8 = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
    pAltStream->Stream.Pos = Pos + 2;
    v9 = v8;
    v10 = *(_QWORD *)&pheapAddr.m256_f32[2] + 1i64;
    if ( (unsigned __int64)(*(_QWORD *)&pheapAddr.m256_f32[2] + 1i64) >= *(_QWORD *)&pheapAddr.m256_f32[2] )
    {
      if ( v10 > *(_QWORD *)&pheapAddr.m256_f32[4] )
      {
        v11 = v10 + (v10 >> 2);
        goto LABEL_11;
      }
    }
    else if ( v10 < *(_QWORD *)&pheapAddr.m256_f32[4] >> 1 )
    {
      v11 = *(_QWORD *)&pheapAddr.m256_f32[2] + 1i64;
LABEL_11:
      Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
        &pheapAddr,
        v11);
    }
    *(_QWORD *)&pheapAddr.m256_f32[2] = v10;
    v12 = (_DWORD *)(*(_QWORD *)pheapAddr.m256_f32 - 4i64 + 4 * v10);
    if ( v12 )
      *v12 = v9;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "offset[0] = %d\n");
    LODWORD(p_pheapAddr) = (int)**(_DWORD **)pheapAddr.m256_f32 >> 1;
    v13 = 1;
    v14 = 1i64;
    v15 = (int)p_pheapAddr;
    if ( (int)p_pheapAddr > 1i64 )
    {
      while ( 1 )
      {
        pAltStream->Stream.UnusedBits = 0;
        if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v16 = pAltStream->Stream.Pos;
        v17 = (unsigned __int8)pAltStream->Stream.pBuffer[v16] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v16 + 1)] << 8);
        pAltStream->Stream.Pos = v16 + 2;
        if ( !v17 )
        {
          LOBYTE(v13) = 0;
          break;
        }
        v18 = v17;
        v19 = *(_QWORD *)&pheapAddr.m256_f32[2] + 1i64;
        if ( (unsigned __int64)(*(_QWORD *)&pheapAddr.m256_f32[2] + 1i64) >= *(_QWORD *)&pheapAddr.m256_f32[2] )
        {
          if ( v19 > *(_QWORD *)&pheapAddr.m256_f32[4] )
          {
            v20 = v19 + (v19 >> 2);
            goto LABEL_23;
          }
        }
        else if ( v19 < *(_QWORD *)&pheapAddr.m256_f32[4] >> 1 )
        {
          v20 = *(_QWORD *)&pheapAddr.m256_f32[2] + 1i64;
LABEL_23:
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
            &pheapAddr,
            v20);
        }
        *(_QWORD *)&pheapAddr.m256_f32[2] = v19;
        v21 = (_DWORD *)(*(_QWORD *)pheapAddr.m256_f32 - 4i64 + 4 * v19);
        if ( v21 )
          *v21 = v18;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "offset[%d] = %d\n");
        ++v13;
        ++v14;
        v15 = (int)p_pheapAddr;
        if ( v14 >= (int)p_pheapAddr )
        {
          LOBYTE(v13) = 1;
          break;
        }
      }
    }
    *(_QWORD *)&pheapAddr.m256_f32[2] = &this->Glyphs;
    Size = this->Glyphs.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Glyphs.Data,
      &this->Glyphs,
      v15);
    if ( v15 > Size )
    {
      v23 = &this->Glyphs.Data.Data[Size];
      v143 = v23;
      v24 = v15 - Size;
      if ( v15 != Size )
      {
        do
        {
          *(_QWORD *)pheapAddr.m256_f32 = v23;
          if ( v23 )
            v23->pObject = 0i64;
          v143 = ++v23;
          --v24;
        }
        while ( v24 );
      }
    }
    if ( (_BYTE)v13 )
    {
      v25 = 0i64;
      if ( v15 > 0 )
      {
        v26 = 1;
        do
        {
          v27 = *(_DWORD *)(*(_QWORD *)pheapAddr.m256_f32 + 4 * v25) + (_DWORD)v143;
          pAltStream->Stream.UnusedBits = 0;
          FilePos = pAltStream->Stream.FilePos;
          DataSize = pAltStream->Stream.DataSize;
          if ( v27 < (int)(FilePos - DataSize) || v27 >= FilePos )
          {
            if ( (pAltStream->Stream.ResyncFile || pAltStream->Stream.Pos + FilePos - DataSize != v27)
              && ((int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pAltStream->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
                   pAltStream->Stream.pInput.pObject,
                   (unsigned int)v27,
                   0i64) >= 0 )
            {
              pAltStream->Stream.ResyncFile = 0;
              *(_QWORD *)&pAltStream->Stream.Pos = 0i64;
              pAltStream->Stream.FilePos = v27;
            }
          }
          else
          {
            pAltStream->Stream.Pos = v27 + DataSize - FilePos;
          }
          if ( v26 >= (int)p_pheapAddr )
            v30 = LODWORD(v154->Size) + HIDWORD(v154->Size) - v27;
          else
            v30 = *(_DWORD *)(*(_QWORD *)pheapAddr.m256_f32 + 4 * v25 + 4)
                - *(_DWORD *)(*(_QWORD *)pheapAddr.m256_f32 + 4 * v25);
          v31 = v30;
          v32 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                              pHeap,
                                              32i64);
          *(_QWORD *)pheapAddr.m256_f32 = v32;
          if ( v32 )
          {
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImplCore::`vftable;
            v32->RefCount.Value = 1;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImpl::`vftable;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
            v32->pLib = 0i64;
            LOBYTE(v32[1].vfptr) = 0;
            v32->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
          }
          else
          {
            v32 = 0i64;
          }
          v146 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)v32;
          LOBYTE(v139) = 0;
          ((void (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *, __int64, _QWORD, int))v32->vfptr[3].GetResourceReport)(
            v32,
            v153,
            2i64,
            v31,
            v139);
          v33 = **(_QWORD **)&pheapAddr.m256_f32[2];
          Scaleform::Render::RenderBuffer::AddRef(v32);
          v34 = *(Scaleform::Render::RenderBuffer **)(v33 + 8 * v25);
          if ( v34 )
            Scaleform::RefCountImpl::Release(v34);
          *(_QWORD *)(v33 + 8 * v25) = v32;
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v32);
          ++v26;
          ++v25;
        }
        while ( v25 < v15 );
      }
    }
    else
    {
      this->Flags |= 0x1000u;
    }
    v154 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr;
    v35 = *(int **)pheapAddr.m256_f32;
    goto LABEL_248;
  }
  if ( TagType == Tag_DefineFont2 )
  {
    v36 = "reading DefineFont2: ";
  }
  else
  {
    if ( TagType != Tag_DefineFont3 )
      return;
    v36 = "reading DefineFont3: ";
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, v36);
  UInt = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u);
  LOBYTE(p_pheapAddr) = UInt != 0;
  if ( UInt )
    this->Flags |= 0x2000u;
  else
    this->Flags &= ~0x2000u;
  v38 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  v39 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  v40 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  if ( v38 )
  {
    this->Flags &= ~0x100u;
    this->Flags |= 0x200u;
  }
  else if ( v40 )
  {
    this->Flags &= ~0x200u;
    this->Flags |= 0x100u;
  }
  else
  {
    this->Flags &= 0xFFFFFCFF;
  }
  if ( v39 )
    this->Flags |= 0x8000u;
  else
    this->Flags &= ~0x8000u;
  v41 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1u) )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  ++pAltStream->Stream.Pos;
  this->Name = Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, p->pLoadData.pObject->pHeap);
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v42 = pAltStream->Stream.Pos;
  v43 = (unsigned __int8)pAltStream->Stream.pBuffer[v42] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v42 + 1)] << 8);
  pAltStream->Stream.Pos = v42 + 2;
  v44 = v43;
  LODWORD(pHeap) = v43;
  if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  Name = %s, %d glyphs\n");
    v140 = (this->Flags >> 1) & 1;
    v139 = this->Flags & 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &pAltStream->Stream,
      "  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n");
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  LangCode = %d\n");
  }
  LODWORD(v143) = pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
  v146 = &v142;
  memset(&v142, 0, sizeof(v142));
  v45 = v44;
  if ( v44 > 0 )
  {
    pAltStream->Stream.UnusedBits = 0;
    v46 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    if ( v41 )
    {
      if ( v46 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v47 = pAltStream->Stream.Pos;
      v48 = (unsigned __int8)pAltStream->Stream.pBuffer[v47] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v47 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v47 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v47 + 3)] << 8)) << 8)) << 8);
      v49 = v47 + 4;
    }
    else
    {
      if ( v46 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v50 = pAltStream->Stream.Pos;
      v49 = v50 + 2;
      v48 = (unsigned __int16)((unsigned __int8)pAltStream->Stream.pBuffer[v50] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v50 + 1)] << 8));
    }
    pAltStream->Stream.Pos = v49;
    if ( !v48 )
    {
      v141 = 0;
      v45 = 0;
      goto LABEL_104;
    }
    v51 = v142.Size + 1;
    if ( v142.Size + 1 >= v142.Size )
    {
      if ( v51 <= v142.Policy.Capacity )
        goto LABEL_102;
      v52 = v51 + (v51 >> 2);
    }
    else
    {
      if ( v51 >= v142.Policy.Capacity >> 1 )
        goto LABEL_102;
      v52 = v142.Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &v142,
      &v142,
      v52);
LABEL_102:
    v142.Size = v51;
    v53 = &v142.Data[v51 - 1];
    if ( v53 )
      *v53 = v48;
  }
LABEL_104:
  if ( !v41 )
  {
    if ( v45 <= 1 )
    {
LABEL_134:
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v70 = pAltStream->Stream.Pos;
      v62 = v70 + 2;
      LODWORD(v61) = (unsigned __int16)((unsigned __int8)pAltStream->Stream.pBuffer[v70] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v70 + 1)] << 8));
      goto LABEL_137;
    }
    v63 = (unsigned int)(v45 - 1);
    while ( 1 )
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v64 = pAltStream->Stream.Pos;
      v65 = (unsigned __int8)pAltStream->Stream.pBuffer[v64] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v64 + 1)] << 8);
      pAltStream->Stream.Pos = v64 + 2;
      v66 = v65;
      v67 = v142.Size + 1;
      if ( v142.Size + 1 >= v142.Size )
      {
        if ( v67 > v142.Policy.Capacity )
        {
          v68 = v67 + (v67 >> 2);
          goto LABEL_130;
        }
      }
      else if ( v67 < v142.Policy.Capacity >> 1 )
      {
        v68 = v142.Size + 1;
LABEL_130:
        Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v142,
          &v142,
          v68);
      }
      v142.Size = v67;
      v69 = &v142.Data[v67 - 1];
      if ( v69 )
        *v69 = v66;
      if ( !--v63 )
        goto LABEL_134;
    }
  }
  if ( v45 > 1 )
  {
    for ( i = (unsigned int)(v45 - 1); i; --i )
    {
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v55 = pAltStream->Stream.Pos;
      v56 = (unsigned __int8)pAltStream->Stream.pBuffer[v55] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v55 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v55 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v55 + 3)] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v55 + 4;
      v57 = v142.Size + 1;
      if ( v142.Size + 1 >= v142.Size )
      {
        if ( v57 > v142.Policy.Capacity )
        {
          v58 = v57 + (v57 >> 2);
          goto LABEL_114;
        }
      }
      else if ( v57 < v142.Policy.Capacity >> 1 )
      {
        v58 = v142.Size + 1;
LABEL_114:
        Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v142,
          &v142,
          v58);
      }
      v142.Size = v57;
      v59 = &v142.Data[v57 - 1];
      if ( v59 )
        *v59 = v56;
    }
  }
  pAltStream->Stream.UnusedBits = 0;
  if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  v60 = pAltStream->Stream.Pos;
  LODWORD(v61) = (unsigned __int8)pAltStream->Stream.pBuffer[v60] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v60 + 1)] | (((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v60 + 2)] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v60 + 3)] << 8)) << 8)) << 8);
  v62 = v60 + 4;
LABEL_137:
  pheapAddr.m256_f32[6] = v61;
  pAltStream->Stream.Pos = v62;
  v71 = (int)pHeap;
  *(_QWORD *)pheapAddr.m256_f32 = &this->Glyphs;
  v72 = this->Glyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Glyphs.Data,
    &this->Glyphs,
    (int)pHeap);
  if ( v71 > v72 )
  {
    v73 = &this->Glyphs.Data.Data[v72];
    v143 = v73;
    v74 = v71 - v72;
    if ( v71 != v72 )
    {
      do
      {
        v146 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)v73;
        if ( v73 )
          v73->pObject = 0i64;
        v143 = ++v73;
        --v74;
      }
      while ( v74 );
    }
  }
  if ( !v141 )
  {
    v100 = LODWORD(v61) + (_DWORD)v143;
    v101 = pAltStream->Stream.TagStackEntryCount - 1;
    if ( (unsigned int)v101 >= 2 )
      v102 = 0;
    else
      v102 = pAltStream->Stream.TagStack[v101];
    if ( v100 >= v102 )
      goto LABEL_191;
    Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v100);
    this->Flags |= 0x1000u;
LABEL_193:
    Scaleform::GFx::FontData::ReadCodeTable(this, &pAltStream->Stream);
    if ( (_BYTE)p_pheapAddr )
    {
      if ( LODWORD(v154->Data) == 75 )
        v103 = FLOAT_0_050000001;
      else
        v103 = *(float *)&FLOAT_1_0;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v104 = pAltStream->Stream.Pos;
      v105 = (unsigned __int8)pAltStream->Stream.pBuffer[v104] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v104 + 1)] << 8);
      pAltStream->Stream.Pos = v104 + 2;
      this->Ascent = (float)v105 * v103;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v106 = pAltStream->Stream.Pos;
      v107 = (unsigned __int8)pAltStream->Stream.pBuffer[v106] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v106 + 1)] << 8);
      pAltStream->Stream.Pos = v106 + 2;
      this->Descent = (float)v107 * v103;
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v108 = pAltStream->Stream.Pos;
      v109 = (unsigned __int8)pAltStream->Stream.pBuffer[v108] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v108 + 1)] << 8);
      pAltStream->Stream.Pos = v108 + 2;
      this->Leading = (float)v109 * v103;
      if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &pAltStream->Stream,
          "  Ascent = %d, Descent = %d, Leading = %d\n");
      v110 = this->Glyphs.Data.Size;
      if ( this->AdvanceTable.Data.Size != v110 )
        Scaleform::ArrayData<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->AdvanceTable.Data,
          v110);
      v111 = this->AdvanceTable.Data.Size;
      if ( v111 )
      {
        v112 = 0i64;
        do
        {
          Data = this->AdvanceTable.Data.Data;
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v114 = pAltStream->Stream.Pos;
          v115 = (unsigned __int8)pAltStream->Stream.pBuffer[v114] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v114 + 1)] << 8);
          pAltStream->Stream.Pos = v114 + 2;
          Data[v112++].Advance = (float)v115 * v103;
          --v111;
        }
        while ( v111 );
      }
      for ( j = this->Glyphs.Data.Size; j; --j )
        Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
      pAltStream->Stream.UnusedBits = 0;
      if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v117 = pAltStream->Stream.Pos;
      v118 = (unsigned __int8)pAltStream->Stream.pBuffer[v117] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v117 + 1)] << 8);
      pAltStream->Stream.Pos = v117 + 2;
      v119 = v118;
      if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&pAltStream->Stream, "  KerningCount = %d\n");
      v120 = 0;
      if ( v119 > 0 )
      {
        while ( 1 )
        {
          v121 = pAltStream->Stream.DataSize;
          v122 = pAltStream->Stream.Pos;
          if ( (int)(v122 + pAltStream->Stream.FilePos - v121) >= HIDWORD(v154->Size) + LODWORD(v154->Size) )
            break;
          v123 = this->Flags >> 14;
          pAltStream->Stream.UnusedBits = 0;
          v124 = v121 - v122;
          if ( (v123 & 1) != 0 )
          {
            if ( v124 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v125 = pAltStream->Stream.Pos;
            v126 = (unsigned __int8)pAltStream->Stream.pBuffer[v125] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v125 + 1)] << 8);
            pAltStream->Stream.Pos = v125 + 2;
            pAltStream->Stream.UnusedBits = 0;
            if ( (signed int)(pAltStream->Stream.DataSize - (v125 + 2)) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v127 = pAltStream->Stream.Pos;
            v128 = (unsigned __int8)pAltStream->Stream.pBuffer[v127] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v127 + 1)] << 8);
            v129 = v127 + 2;
          }
          else
          {
            if ( v124 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
            v130 = pAltStream->Stream.Pos;
            v126 = (unsigned __int8)pAltStream->Stream.pBuffer[v130];
            pAltStream->Stream.Pos = v130 + 1;
            pAltStream->Stream.UnusedBits = 0;
            if ( (signed int)(pAltStream->Stream.DataSize - (v130 + 1)) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
            v131 = pAltStream->Stream.Pos;
            v128 = (unsigned __int8)pAltStream->Stream.pBuffer[v131];
            v129 = v131 + 1;
          }
          pAltStream->Stream.Pos = v129;
          pAltStream->Stream.UnusedBits = 0;
          if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v132 = pAltStream->Stream.Pos;
          v133 = (unsigned __int8)pAltStream->Stream.pBuffer[v132] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(v132 + 1)] << 8);
          pAltStream->Stream.Pos = v132 + 2;
          *(float *)&v143 = (float)v133 * v103;
          LOWORD(pheapAddr.m256_f32[7]) = v126;
          HIWORD(pheapAddr.m256_f32[7]) = v128;
          if ( (pAltStream->Stream.ParseFlags & 1) != 0 )
            Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
              &pAltStream->Stream,
              "     Pair: %d - %d,\tadj = %d\n");
          key.pFirst = (Scaleform::GFx::FontData::KerningPair *)&pheapAddr.m256_f32[7];
          key.pSecond = (const float *)&v143;
          v134 = 4i64;
          v135 = 5381i64;
          do
          {
            --v134;
            v135 = *((unsigned __int8 *)&pheapAddr.m256_f32[7] + v134) + 65599 * v135;
          }
          while ( v134 );
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeRef>(
            &this->KerningPairs.mHash,
            &this->KerningPairs,
            &key,
            v135);
          if ( ++v120 >= v119 )
            goto LABEL_242;
        }
        Name = "<noname>";
        if ( this->Name )
          Name = this->Name;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          &pAltStream->Stream,
          "Corrupted file %s, kerning table of the font %s is longer than tagLength.",
          (const char *)((pAltStream->Stream.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          Name);
      }
    }
LABEL_242:
    if ( !v141 )
    {
      v137 = this->AdvanceTable.Data.Size;
      if ( v137 )
      {
        v138 = 0i64;
        do
        {
          *(_QWORD *)&this->AdvanceTable.Data.Data[v138++].Left = 0i64;
          --v137;
        }
        while ( v137 );
      }
    }
    v154 = &v142;
    goto LABEL_247;
  }
  v75 = (int)v154->Data;
  if ( LODWORD(v154->Data) == 48 )
    v75 = 22;
  LODWORD(pheapAddr.m256_f32[2]) = v75;
  if ( (_BYTE)p_pheapAddr )
    Scaleform::ArrayData<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->AdvanceTable.Data,
      v71);
  LODWORD(v142.Policy.Capacity) = 0;
  v76 = 0i64;
  if ( v71 > 0 )
  {
    v77 = 0i64;
    HIDWORD(pHeap) = 1;
    while ( 1 )
    {
      v78 = v142.Data;
      v79 = v142.Data[v76] + (_DWORD)v143;
      pAltStream->Stream.UnusedBits = 0;
      v80 = pAltStream->Stream.FilePos;
      v81 = pAltStream->Stream.DataSize;
      if ( v79 < (int)(v80 - v81) || v79 >= v80 )
      {
        if ( pAltStream->Stream.ResyncFile || pAltStream->Stream.Pos + v80 - v81 != v79 )
        {
          v82 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pAltStream->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
                  pAltStream->Stream.pInput.pObject,
                  (unsigned int)v79,
                  0i64);
          v78 = v142.Data;
          if ( v82 >= 0 )
          {
            pAltStream->Stream.ResyncFile = 0;
            *(_QWORD *)&pAltStream->Stream.Pos = 0i64;
            pAltStream->Stream.FilePos = v79;
          }
        }
      }
      else
      {
        pAltStream->Stream.Pos = v81 + v79 - v80;
      }
      v83 = SHIDWORD(pHeap) >= (int)pHeap ? LODWORD(v61) : v78[v76 + 1];
      v84 = v83 - v78[v76];
      v85 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                          pHeap,
                                          32i64);
      v149 = v85;
      if ( v85 )
      {
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImplCore::`vftable;
        v85->RefCount.Value = 1;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImpl::`vftable;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable;
        v85->pLib = 0i64;
        LOBYTE(v85[1].vfptr) = 0;
        v85->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable;
      }
      else
      {
        v85 = 0i64;
      }
      v148 = v85;
      LOBYTE(v139) = 0;
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD, _QWORD, int, unsigned int))v85->vfptr[3].GetResourceReport)(
              v85,
              v153,
              LODWORD(pheapAddr.m256_f32[2]),
              v84,
              v139,
              v140) )
        break;
      v86 = this->Glyphs.Data.Data;
      Scaleform::Render::RenderBuffer::AddRef(v85);
      pObject = (Scaleform::Render::RenderBuffer *)v86[v76].pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      v86[v76].pObject = (Scaleform::GFx::ShapeDataBase *)v85;
      if ( (_BYTE)p_pheapAddr )
      {
        *(_OWORD *)&pheapAddr.m256_f32[4] = 0i64;
        Scaleform::GFx::ShapeDataBase::ComputeBound(
          (Scaleform::GFx::ShapeDataBase *)v85,
          (Scaleform::Render::Rect<float> *)&pheapAddr.m256_f32[4]);
        v88 = this->AdvanceTable.Data.Data;
        v89 = pheapAddr.m256_f32[6];
        v90 = pheapAddr.m256_f32[4];
        if ( pheapAddr.m256_f32[6] < pheapAddr.m256_f32[4]
          || (v91 = pheapAddr.m256_f32[7], v92 = pheapAddr.m256_f32[5], pheapAddr.m256_f32[7] < pheapAddr.m256_f32[5]) )
        {
          *(_QWORD *)&v88[v77].Left = 0i64;
        }
        else
        {
          v88[v77].Left = (int)(float)(pheapAddr.m256_f32[4] * 20.0);
          v88[v77].Top = (int)(float)(v92 * 20.0);
          v88[v77].Width = (int)(float)((float)(v89 - v90) * 20.0);
          v88[v77].Height = (int)(float)((float)(v91 - v92) * 20.0);
        }
      }
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v85);
      ++LODWORD(v142.Policy.Capacity);
      ++HIDWORD(pHeap);
      ++v76;
      ++v77;
      v61 = pheapAddr.m256_f32[6];
      if ( v76 >= (int)pHeap )
        goto LABEL_185;
    }
    Capacity_low = SLODWORD(v142.Policy.Capacity);
    p_AdvanceTable = &this->AdvanceTable;
    if ( SLODWORD(v142.Policy.Capacity) >= p_AdvanceTable->Data.Size )
    {
      if ( SLODWORD(v142.Policy.Capacity) <= p_AdvanceTable->Data.Policy.Capacity )
        goto LABEL_178;
      v95 = SLODWORD(v142.Policy.Capacity) + ((unsigned __int64)SLODWORD(v142.Policy.Capacity) >> 2);
    }
    else
    {
      if ( SLODWORD(v142.Policy.Capacity) >= p_AdvanceTable->Data.Policy.Capacity >> 1 )
        goto LABEL_178;
      v95 = SLODWORD(v142.Policy.Capacity);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_AdvanceTable->Data,
      p_AdvanceTable,
      v95);
LABEL_178:
    p_AdvanceTable->Data.Size = Capacity_low;
    v96 = *(_QWORD **)pheapAddr.m256_f32;
    v97 = *(_QWORD *)(*(_QWORD *)pheapAddr.m256_f32 + 8i64);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      *(Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> **)pheapAddr.m256_f32,
      *(const void **)pheapAddr.m256_f32,
      Capacity_low);
    if ( Capacity_low > v97 )
    {
      v98 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)(*v96 + 8 * v97);
      v154 = v98;
      for ( k = Capacity_low - v97; k; --k )
      {
        v153 = v98;
        if ( v98 )
          v98->Data = 0i64;
        v98 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v98 + 8);
        v154 = v98;
      }
    }
    if ( v85 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v85);
    goto LABEL_191;
  }
LABEL_185:
  if ( (_DWORD)v143 + LODWORD(pheapAddr.m256_f32[6]) == pAltStream->Stream.Pos
                                                      + pAltStream->Stream.FilePos
                                                      - pAltStream->Stream.DataSize )
    goto LABEL_193;
LABEL_191:
  v154 = &v142;
LABEL_247:
  v35 = v142.Data;
LABEL_248:
  if ( v35 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 586
// RVA: 0x8FC040
void __fastcall Scaleform::GFx::FontData::ReadFontInfo(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::Stream *in,
        Scaleform::GFx::TagType tagType)
{
  unsigned int DataSize; // eax
  __int64 Pos; // rcx
  char v8; // si
  unsigned int v9; // eax
  const char *v10; // rdx

  if ( this->Name )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->Name = 0i64;
  }
  this->Name = Scaleform::GFx::Stream::ReadStringWithLength(in, in->FileName.pHeap);
  DataSize = in->DataSize;
  in->UnusedBits = 0;
  if ( (int)(DataSize - in->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(in, 1);
  Pos = in->Pos;
  v8 = in->pBuffer[Pos];
  in->Pos = Pos + 1;
  if ( tagType == Tag_DefineFontInfo2 )
  {
    v9 = in->DataSize;
    in->UnusedBits = 0;
    if ( (int)(v9 - (Pos + 1)) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(in, 1);
    ++in->Pos;
  }
  if ( (v8 & 0x10) != 0 )
  {
    this->Flags &= ~0x100u;
    this->Flags |= 0x200u;
  }
  else if ( (v8 & 8) != 0 )
  {
    this->Flags &= ~0x200u;
    this->Flags |= 0x100u;
  }
  else
  {
    this->Flags &= 0xFFFFFCFF;
  }
  if ( (v8 & 4) != 0 )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( (v8 & 2) != 0 )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
  if ( (v8 & 1) != 0 )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
  if ( (in->ParseFlags & 1) != 0 )
  {
    v10 = "reading DefineFontInfo\n";
    if ( tagType != Tag_DefineFontInfo )
      v10 = "reading DefineFontInfo2\n";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, v10);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, "  Name = %s\n");
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, "  CodePage = %s, Italic = %d, Bold = %d\n");
    if ( tagType == Tag_DefineFontInfo2 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, "  LangCode = %d\n");
  }
  Scaleform::GFx::FontData::ReadCodeTable(this, in);
}

// File Line: 643
// RVA: 0x8FAC90
void __fastcall Scaleform::GFx::FontData::ReadCodeTable(Scaleform::GFx::FontData *this, Scaleform::GFx::Stream *in)
{
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  unsigned __int64 EntryCount; // rax
  unsigned int Flags; // eax
  unsigned __int64 Size; // rbp
  unsigned int DataSize; // eax
  __int64 Pos; // r9
  unsigned __int16 v13; // r8
  unsigned int v14; // eax
  __int64 v15; // rdx
  unsigned int v16; // ecx
  Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeRef key; // [rsp+20h] [rbp-28h] BYREF
  __int16 v18; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int16 v19; // [rsp+58h] [rbp+10h] BYREF

  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(in, "reading code table at offset %d\n");
  p_CodeTable = &this->CodeTable;
  pTable = this->CodeTable.mHash.pTable;
  v6 = 0i64;
  v7 = (5 * this->Glyphs.Data.Size) >> 2;
  if ( pTable )
    EntryCount = pTable->EntryCount;
  else
    EntryCount = 0i64;
  if ( v7 > EntryCount )
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::setRawCapacity(
      &this->CodeTable.mHash,
      &this->CodeTable,
      v7);
  Flags = this->Flags;
  Size = this->Glyphs.Data.Size;
  if ( (Flags & 0x4000) != 0 )
  {
    if ( Size )
    {
      key.pFirst = &v19;
      key.pSecond = (const unsigned __int16 *)&v18;
      do
      {
        DataSize = in->DataSize;
        v18 = v6;
        in->UnusedBits = 0;
        if ( (int)(DataSize - in->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(in, 2);
        Pos = in->Pos;
        v19 = (unsigned __int8)in->pBuffer[Pos] | ((unsigned __int8)in->pBuffer[(unsigned int)(Pos + 1)] << 8);
        v13 = v19;
        in->Pos = Pos + 2;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
          &p_CodeTable->mHash,
          p_CodeTable,
          &key,
          v13);
        ++v6;
      }
      while ( v6 < Size );
    }
  }
  else if ( Size )
  {
    key.pFirst = &v19;
    key.pSecond = (const unsigned __int16 *)&v18;
    do
    {
      v14 = in->DataSize;
      v18 = v6;
      in->UnusedBits = 0;
      if ( (int)(v14 - in->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(in, 1);
      v15 = in->Pos;
      v16 = (unsigned __int8)in->pBuffer[v15];
      v19 = (unsigned __int8)in->pBuffer[v15];
      in->Pos = v15 + 1;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
        &p_CodeTable->mHash,
        p_CodeTable,
        &key,
        v16);
      ++v6;
    }
    while ( v6 < Size );
  }
}

// File Line: 664
// RVA: 0x8D96D0
__int64 __fastcall Scaleform::GFx::FontData::GetGlyphIndex(Scaleform::GFx::FontData *this, unsigned __int16 code)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // r9
  unsigned __int64 SizeMask; // r11
  __int64 v4; // r10
  __int64 EntryCount; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v6; // rax
  __int64 p_SizeMask; // rax

  pTable = this->CodeTable.mHash.pTable;
  if ( !pTable )
    return 0xFFFFFFFFi64;
  SizeMask = pTable->SizeMask;
  v4 = SizeMask & code;
  EntryCount = v4;
  v6 = &pTable[v4 + 1];
  if ( v6->EntryCount == -2i64 || (SizeMask & LOWORD(v6->SizeMask)) != v4 )
    return 0xFFFFFFFFi64;
  while ( (SizeMask & LOWORD(v6->SizeMask)) != v4 || LOWORD(v6->SizeMask) != code )
  {
    EntryCount = v6->EntryCount;
    if ( v6->EntryCount == -1i64 )
      return 0xFFFFFFFFi64;
    v6 = &pTable[EntryCount + 1];
  }
  if ( EntryCount >= 0 && (p_SizeMask = (__int64)&pTable[EntryCount + 1].SizeMask) != 0 )
    return *(unsigned __int16 *)(p_SizeMask + 2);
  else
    return 0xFFFFFFFFi64;
}

// File Line: 674
// RVA: 0x8D5E50
__int64 __fastcall Scaleform::GFx::FontData::GetCharValue(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // r8
  unsigned __int64 v3; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v7; // rcx
  unsigned __int64 v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v9; // r8
  unsigned __int64 v10; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v11; // rax
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v13; // [rsp+0h] [rbp-18h]

  p_CodeTable = &this->CodeTable;
  v3 = 0i64;
  pTable = this->CodeTable.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v3;
      ++v7;
    }
    while ( v3 <= SizeMask );
    v13 = p_CodeTable;
  }
  else
  {
    v13 = 0i64;
  }
  v8 = v3;
  while ( v13 )
  {
    v9 = v13->mHash.pTable;
    if ( !v13->mHash.pTable )
      break;
    v10 = v9->SizeMask;
    if ( (__int64)v8 > (__int64)v10 )
      break;
    if ( WORD1(v9[v8 + 1].SizeMask) == glyphIndex )
      return LOWORD(v9[v8 + 1].SizeMask);
    if ( ++v8 <= v10 )
    {
      v11 = &v9[v8 + 1];
      do
      {
        if ( v11->EntryCount != -2i64 )
          break;
        ++v8;
        ++v11;
      }
      while ( v8 <= v10 );
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 685
// RVA: 0x8DC0E0
Scaleform::GFx::ShapeDataBase *__fastcall Scaleform::GFx::FontData::GetPermanentGlyphShape(
        Scaleform::GFx::FontData *this,
        unsigned int glyphIndex)
{
  if ( glyphIndex >= this->Glyphs.Data.Size )
    return 0i64;
  else
    return this->Glyphs.Data.Data[glyphIndex].pObject;
}

// File Line: 693
// RVA: 0x8D4C50
float __fastcall Scaleform::GFx::FontData::GetAdvance(Scaleform::GFx::FontData *this, __int64 glyphIndex)
{
  unsigned __int64 Size; // rcx
  char v4; // cl
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  float result; // xmm0_4

  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *, __int64, Scaleform::GFx::FontData *))this->vfptr[21].__vecDelDtor)(
      this,
      glyphIndex,
      this);
  }
  else
  {
    Size = this->AdvanceTable.Data.Size;
    if ( Size )
    {
      if ( (unsigned int)glyphIndex >= Size )
        return 0.0;
      else
        return this->AdvanceTable.Data.Data[(unsigned int)glyphIndex].Advance;
    }
    else
    {
      v4 = Logged;
      vfptr = this->vfptr;
      if ( !Logged )
        v4 = 1;
      Logged = v4;
      ((void (__fastcall *)(Scaleform::GFx::FontData *))vfptr[21].__vecDelDtor)(this);
    }
  }
  return result;
}

// File Line: 724
// RVA: 0x8D9790
float __fastcall Scaleform::GFx::FontData::GetGlyphWidth(Scaleform::GFx::FontData *this, __int64 glyphIndex)
{
  float result; // xmm0_4

  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *, __int64, Scaleform::GFx::FontData *))this->vfptr[21].__vecDelDtor)(
      this,
      glyphIndex,
      this);
  }
  else if ( (unsigned int)glyphIndex >= this->AdvanceTable.Data.Size
         || (result = (float)this->AdvanceTable.Data.Data[(unsigned int)glyphIndex].Width * 0.050000001, result == 0.0) )
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *))this->vfptr[3].__vecDelDtor)(this);
  }
  return result;
}

// File Line: 739
// RVA: 0x8D9670
float __fastcall Scaleform::GFx::FontData::GetGlyphHeight(Scaleform::GFx::FontData *this, __int64 glyphIndex)
{
  unsigned __int64 Size; // rax
  float result; // xmm0_4

  if ( (_WORD)glyphIndex == 0xFFFF || (Size = this->AdvanceTable.Data.Size) == 0 )
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *, __int64, Scaleform::GFx::FontData *))this->vfptr[22].__vecDelDtor)(
      this,
      glyphIndex,
      this);
  }
  else if ( (unsigned int)glyphIndex >= Size )
  {
    return 0.0;
  }
  else
  {
    return (float)this->AdvanceTable.Data.Data[(unsigned int)glyphIndex].Height * 0.050000001;
  }
  return result;
}

// File Line: 760
// RVA: 0x8D9380
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::FontData::GetGlyphBounds(
        Scaleform::GFx::FontData *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  Scaleform::Render::Rect<float> *result; // rax
  Scaleform::GFx::FontData::AdvanceEntry *Data; // rcx
  float Advance; // xmm3_4
  float Height; // xmm2_4
  float v10; // xmm1_4
  unsigned int Top; // eax
  __m128i v12; // xmm0
  Scaleform::GFx::ShapeDataBase *pObject; // rcx
  float x2; // xmm1_4
  float x1; // xmm3_4
  float y2; // xmm0_4
  float y1; // xmm2_4
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-18h] BYREF

  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    prect->x2 = ((float (__fastcall *)(Scaleform::GFx::FontData *, _QWORD))this->vfptr[5].__vecDelDtor)(
                  this,
                  glyphIndex)
              + prect->x1;
    prect->y2 = ((float (__fastcall *)(Scaleform::GFx::FontData *, _QWORD))this->vfptr[6].__vecDelDtor)(
                  this,
                  glyphIndex)
              + prect->y1;
    return prect;
  }
  if ( glyphIndex >= this->AdvanceTable.Data.Size )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    if ( glyphIndex >= this->Glyphs.Data.Size )
      return prect;
    pObject = this->Glyphs.Data.Data[glyphIndex].pObject;
    if ( !pObject )
      return prect;
    r = 0i64;
    Scaleform::GFx::ShapeDataBase::ComputeBound(pObject, &r);
    x2 = r.x2;
    x1 = r.x1;
    if ( r.x2 < r.x1 )
      return prect;
    y2 = r.y2;
    y1 = r.y1;
    result = prect;
    if ( r.y2 >= r.y1 )
    {
      prect->x1 = r.x1;
      prect->x2 = (float)(x2 - x1) + x1;
      prect->y2 = (float)(y2 - y1) + y1;
      prect->y1 = y1;
    }
  }
  else
  {
    Data = this->AdvanceTable.Data.Data;
    Advance = (float)Data[glyphIndex].Width * 0.050000001;
    if ( Advance == 0.0 )
      Advance = Data[glyphIndex].Advance;
    Height = (float)Data[glyphIndex].Height;
    v10 = (float)Data[glyphIndex].Left * 0.050000001;
    prect->x1 = v10;
    Top = Data[glyphIndex].Top;
    prect->x2 = Advance + v10;
    v12 = _mm_cvtsi32_si128(Top);
    result = prect;
    *(float *)v12.m128i_i32 = _mm_cvtepi32_ps(v12).m128_f32[0] * 0.050000001;
    LODWORD(prect->y1) = v12.m128i_i32[0];
    prect->y2 = (float)(Height * 0.050000001) + *(float *)v12.m128i_i32;
  }
  return result;
}

// File Line: 822
// RVA: 0x8DA7E0
float __fastcall Scaleform::GFx::FontData::GetKerningAdjustment(
        Scaleform::GFx::FontData *this,
        __int16 LastCode,
        __int16 code)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF> >::TableType *pTable; // r10
  __int64 v6; // rcx
  __int64 v7; // r9
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rcx
  bool v13; // zf
  unsigned __int64 *v14; // rcx
  float *v15; // rcx
  __int64 v17; // [rsp+8h] [rbp+8h]
  __int16 v18; // [rsp+10h] [rbp+10h]
  __int16 v19; // [rsp+12h] [rbp+12h]

  pTable = this->KerningPairs.mHash.pTable;
  v18 = LastCode;
  v19 = code;
  if ( !pTable )
    return 0.0;
  v6 = 5381i64;
  v7 = 4i64;
  do
  {
    v8 = *((unsigned __int8 *)&v17 + v7-- + 7);
    v9 = 65599 * v6 + v8;
    v6 = v9;
  }
  while ( v7 );
  v10 = v9 & pTable->SizeMask;
  v11 = v10;
  v12 = v10 + 2 * (v10 + 1);
  v13 = *(&pTable->EntryCount + v12) == -2i64;
  v14 = &pTable->EntryCount + v12;
  if ( v13 || v14[1] != v10 )
    return 0.0;
  while ( v14[1] != v10 || *((_WORD *)v14 + 8) != LastCode || *((_WORD *)v14 + 9) != code )
  {
    v11 = *v14;
    if ( *v14 == -1i64 )
      return 0.0;
    v14 = &pTable[v11 + 1].EntryCount + v11;
  }
  if ( v11 >= 0 && (v15 = (float *)(&pTable[v11 + 2].EntryCount + v11)) != 0i64 )
    return v15[1];
  else
    return 0.0;
}

// File Line: 840
// RVA: 0x8B8590
Scaleform::String *__fastcall Scaleform::GFx::BuildStringFromRanges(
        Scaleform::String *result,
        Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *ranges)
{
  int v4; // r15d
  char v5; // r8
  unsigned __int16 start; // bx
  unsigned __int64 v7; // rdi
  Scaleform::GFx::Range *Data; // rax
  Scaleform::GFx::Range *v9; // r12
  int end; // edx
  Scaleform::MsgFormat *p_f; // rcx
  Scaleform::GFx::Range *v12; // r12
  char *BuffPtr; // rcx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rdx
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::Formatter *v17; // rax
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-E0h] BYREF
  int v20; // [rsp+38h] [rbp-C8h]
  __int64 v21; // [rsp+40h] [rbp-C0h]
  Scaleform::MsgFormat f; // [rsp+50h] [rbp-B0h] BYREF
  char putf8str[512]; // [rsp+450h] [rbp+350h] BYREF
  Scaleform::MsgFormat v24; // [rsp+650h] [rbp+550h] BYREF
  Scaleform::StackMemPool<512,8,Scaleform::MemPoolImmediateFree> *v; // [rsp+A98h] [rbp+998h] BYREF
  char *v26; // [rsp+AA0h] [rbp+9A0h]

  v21 = -2i64;
  Scaleform::String::String(result);
  v20 = 1;
  v4 = 0;
  v5 = 1;
  start = 0;
  LOWORD(v) = 0;
  v7 = 0i64;
  if ( !ranges->Data.Size )
    return result;
  do
  {
    Data = ranges->Data.Data;
    if ( v7 )
    {
      v9 = &Data[v7];
      end = v9[-1].end;
      if ( v9->start <= end + 1 )
        goto LABEL_13;
      r.Type = tDataPtr;
      r.SinkData.DataPtr.Size = 512i64;
      r.SinkData.pStr = (Scaleform::String *)putf8str;
      if ( start == (_WORD)end )
      {
        Scaleform::MsgFormat::MsgFormat(&v24, &r);
        Scaleform::MsgFormat::Parse(&v24, "0x{0:x}");
        Scaleform::MsgFormat::FormatD1<unsigned short>(&v24, (const unsigned __int16 *)&v);
        Scaleform::MsgFormat::FinishFormatD(&v24);
        p_f = &v24;
      }
      else
      {
        Scaleform::MsgFormat::MsgFormat(&f, &r);
        Scaleform::MsgFormat::Parse(&f, "0x{0:x}-0x{1:x}");
        Scaleform::MsgFormat::FormatD1<unsigned short>(&f, (const unsigned __int16 *)&v);
        Scaleform::MsgFormat::FormatD1<unsigned short>(&f, &v9[-1].end);
        Scaleform::MsgFormat::FinishFormatD(&f);
        p_f = &f;
      }
      Scaleform::MsgFormat::~MsgFormat(p_f);
      if ( v4 )
        Scaleform::String::AppendString(result, ", ", -1i64);
      Scaleform::String::AppendString(result, putf8str, -1i64);
      if ( ++v4 > 4 )
        goto LABEL_32;
      start = ranges->Data.Data[v7].start;
    }
    else
    {
      start = Data->start;
    }
    v5 = 0;
    LOWORD(v) = start;
LABEL_13:
    ++v7;
  }
  while ( v7 < ranges->Data.Size );
  if ( !v5 )
  {
    r.Type = tDataPtr;
    r.SinkData.pStr = (Scaleform::String *)putf8str;
    r.SinkData.DataPtr.Size = 512i64;
    v12 = &ranges->Data.Data[ranges->Data.Size];
    Scaleform::MsgFormat::MsgFormat(&f, &r);
    Scaleform::MsgFormat::Parse(&f, "0x{0:x}-0x{1:x}");
    if ( Scaleform::MsgFormat::NextFormatter(&f) )
    {
      v = &f.MemPool;
      do
      {
        if ( f.MemPool.BuffSize < 0x60 )
        {
          pHeap = f.MemPool.pHeap;
          if ( !f.MemPool.pHeap )
            pHeap = Scaleform::Memory::pGlobalHeap;
          BuffPtr = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))pHeap->vfptr->Alloc)(
                              pHeap,
                              96i64,
                              8i64);
        }
        else
        {
          BuffPtr = f.MemPool.BuffPtr;
          f.MemPool.BuffPtr = (char *)(((unsigned __int64)(f.MemPool.BuffPtr + 95) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
          v14 = f.MemPool.BuffPtr - (char *)&f.MemPool - 8;
          if ( v14 >= 0x200 )
            v15 = 0i64;
          else
            v15 = 512 - v14;
          f.MemPool.BuffSize = v15;
        }
        v26 = BuffPtr;
        if ( BuffPtr )
          Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)BuffPtr, &f, start);
        else
          v17 = 0i64;
        Scaleform::MsgFormat::Bind(&f, v17, 1);
      }
      while ( Scaleform::MsgFormat::NextFormatter(&f) );
    }
    ++f.FirstArgNum;
    Scaleform::MsgFormat::FormatD1<unsigned short>(&f, &v12[-1].end);
    Scaleform::MsgFormat::FinishFormatD(&f);
    Scaleform::MsgFormat::~MsgFormat(&f);
    if ( v4 )
      Scaleform::String::AppendString(result, ", ", -1i64);
    Scaleform::String::AppendString(result, putf8str, -1i64);
  }
LABEL_32:
  if ( v7 < ranges->Data.Size )
    Scaleform::String::AppendString(result, " (truncated)", -1i64);
  return result;
}

// File Line: 886
// RVA: 0x8D5BC0
Scaleform::String *__fastcall Scaleform::GFx::FontData::GetCharRanges(
        Scaleform::GFx::FontData *this,
        Scaleform::String *result)
{
  __int16 v3; // si
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // rdx
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v7; // rcx
  unsigned __int16 v8; // r14
  unsigned __int64 v9; // rbx
  unsigned __int64 Size; // r8
  char v11; // r11
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v12; // r9
  unsigned __int64 SizeMask; // rdx
  int SizeMask_low; // r10d
  unsigned __int64 v15; // rdi
  unsigned __int64 v16; // r8
  int *v17; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v18; // rax
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // r8
  int *v21; // rcx
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v23; // [rsp+30h] [rbp-30h]
  unsigned __int64 v24; // [rsp+38h] [rbp-28h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+40h] [rbp-20h] BYREF
  int v26; // [rsp+90h] [rbp+30h]
  int v27; // [rsp+90h] [rbp+30h]

  v3 = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  p_CodeTable = &this->CodeTable;
  pTable = this->CodeTable.mHash.pTable;
  if ( pTable )
  {
    v6 = 0i64;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 <= pTable->SizeMask );
    v23 = p_CodeTable;
    v24 = v6;
  }
  else
  {
    v23 = 0i64;
    v24 = 0i64;
  }
  v8 = 0;
  v9 = v24;
LABEL_8:
  Size = pheapAddr.Size;
LABEL_9:
  v11 = 0;
  while ( v23 )
  {
    v12 = v23->mHash.pTable;
    if ( !v23->mHash.pTable )
      break;
    SizeMask = v12->SizeMask;
    if ( (__int64)v9 > (__int64)SizeMask )
      break;
    if ( v11 )
    {
      SizeMask_low = LOWORD(v12[v9 + 1].SizeMask);
      if ( v8 != SizeMask_low - 1 )
      {
        LOWORD(v26) = v3;
        HIWORD(v26) = v8;
        v15 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v15 > pheapAddr.Policy.Capacity )
          {
            v16 = v15 + (v15 >> 2);
LABEL_21:
            Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v16);
          }
        }
        else if ( v15 < pheapAddr.Policy.Capacity >> 1 )
        {
          v16 = Size + 1;
          goto LABEL_21;
        }
        Size = v15;
        pheapAddr.Size = v15;
        v17 = &pheapAddr.Data[v15 - 1];
        if ( !v17 )
          goto LABEL_9;
        *v17 = v26;
        goto LABEL_8;
      }
    }
    else
    {
      LOWORD(SizeMask_low) = v12[v9 + 1].SizeMask;
      v3 = SizeMask_low;
      v11 = 1;
    }
    v8 = SizeMask_low;
    if ( ++v9 <= SizeMask )
    {
      v18 = &v12[v9 + 1];
      do
      {
        if ( v18->EntryCount != -2i64 )
          break;
        ++v9;
        ++v18;
      }
      while ( v9 <= SizeMask );
    }
  }
  if ( v11 )
  {
    LOWORD(v27) = v3;
    HIWORD(v27) = v8;
    v19 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v19 <= pheapAddr.Policy.Capacity )
        goto LABEL_36;
      v20 = v19 + (v19 >> 2);
    }
    else
    {
      if ( v19 >= pheapAddr.Policy.Capacity >> 1 )
        goto LABEL_36;
      v20 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace::Range,Scaleform::AllocatorGH<Scaleform::GFx::`anonymous namespace::Range,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v20);
LABEL_36:
    Size = v19;
    pheapAddr.Size = v19;
    v21 = &pheapAddr.Data[v19 - 1];
    if ( v21 )
    {
      *v21 = v27;
      Size = pheapAddr.Size;
    }
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace::RangeLess>(
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0i64,
    Size,
    0);
  Scaleform::GFx::BuildStringFromRanges(
    result,
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr);
  if ( pheapAddr.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 1573
// RVA: 0x919760
void __fastcall Scaleform::GFx::TextureGlyphBinder::Visit(
        Scaleform::GFx::TextureGlyphBinder *this,
        unsigned int __formal,
        Scaleform::Render::TextureGlyph *ptextureGlyph)
{
  unsigned int BindIndex; // r8d
  Scaleform::GFx::ResourceBinding *ResBinding; // r9
  Scaleform::GFx::ResourceBindData *v6; // rdx
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::Render::Image *vfptr; // rsi
  Scaleform::Render::Image *v9; // rcx
  Scaleform::GFx::Resource *v10; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-20h] BYREF

  if ( !ptextureGlyph->pImage.pObject && ptextureGlyph->BindIndex != -1 )
  {
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    BindIndex = ptextureGlyph->BindIndex;
    ResBinding = this->ResBinding;
    if ( ResBinding->Frozen && BindIndex < ResBinding->ResourceCount )
    {
      v6 = &ResBinding->pResources[BindIndex];
      if ( v6->pResource.pObject )
        _InterlockedExchangeAdd(&v6->pResource.pObject->RefCount.Value, 1u);
      pObject = v6->pResource.pObject;
      pdata = *v6;
    }
    else
    {
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(this->ResBinding, &pdata, BindIndex);
      pObject = pdata.pResource.pObject;
    }
    if ( pObject
      && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pObject->vfptr->GetResourceTypeCode)(pObject) & 0xFF00) == 256 )
    {
      vfptr = (Scaleform::Render::Image *)pObject[1].vfptr;
      if ( vfptr )
        ((void (__fastcall *)(Scaleform::GFx::ResourceVtbl *))vfptr->vfptr[1].__vecDelDtor)(pObject[1].vfptr);
      v9 = ptextureGlyph->pImage.pObject;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v9->vfptr[2].__vecDelDtor)(v9);
      ptextureGlyph->pImage.pObject = vfptr;
      ptextureGlyph->BindIndex = -1;
    }
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    {
      v10 = pdata.pResource.pObject;
      pLib = pdata.pResource.pObject->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pdata.pResource.pObject);
        v10->pLib = 0i64;
      }
      v10->vfptr->__vecDelDtor(v10, 1u);
    }
  }
}

// File Line: 1594
// RVA: 0x896560
void __fastcall Scaleform::GFx::FontDataBound::FontDataBound(
        Scaleform::GFx::FontDataBound *this,
        Scaleform::GFx::Resource *pfont,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  unsigned __int64 v6; // rdi
  Scaleform::GFx::TextureGlyphData *v7; // rbx
  Scaleform::GFx::TextureGlyphData *v8; // rax
  Scaleform::GFx::TextureGlyphData *v9; // rax
  Scaleform::GFx::TextureGlyphData *v10; // rbx
  Scaleform::GFx::TextureGlyphData *pObject; // rcx
  Scaleform::GFx::TextureGlyphData *v12; // rbp
  unsigned __int64 Size; // r14
  __int64 v14; // rbx
  __int64 v15[8]; // [rsp+28h] [rbp-40h] BYREF
  int v16; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::GFx::TextureGlyphData *v17; // [rsp+80h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  this->Ascent = *(float *)&pfont->pLib;
  this->Descent = *((float *)&pfont->pLib + 1);
  this->Leading = *(float *)&pfont[1].vfptr;
  this->Flags = HIDWORD(pfont[1].vfptr);
  this->LowerCaseTop = pfont[1].RefCount.Value;
  this->UpperCaseTop = HIWORD(pfont[1].RefCount.Value);
  v6 = 0i64;
  this->hRef.pManager.Value = 0i64;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontDataBound::`vftable;
  Scaleform::Render::RenderBuffer::AddRef(pfont);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  this->pTGData.pObject = 0i64;
  v7 = (Scaleform::GFx::TextureGlyphData *)pfont->vfptr[2].GetResourceReport(pfont);
  v16 = 261;
  v8 = (Scaleform::GFx::TextureGlyphData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::FontDataBound *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                             Scaleform::Memory::pGlobalHeap,
                                             this,
                                             72i64,
                                             &v16,
                                             -2i64);
  v17 = v8;
  if ( v8 )
  {
    Scaleform::GFx::TextureGlyphData::TextureGlyphData(v8, v7);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  pObject = this->pTGData.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pTGData.pObject = v10;
  v15[0] = (__int64)&Scaleform::GFx::TextureGlyphBinder::`vftable;
  v15[1] = (__int64)pbinding;
  v12 = this->pTGData.pObject;
  Size = v12->TextureGlyphs.Data.Size;
  if ( Size )
  {
    v14 = 0i64;
    do
      (*(void (__fastcall **)(__int64 *, _QWORD, Scaleform::Render::TextureGlyph *))(v15[0] + 8))(
        v15,
        (unsigned int)v6++,
        &v12->TextureGlyphs.Data.Data[v14++]);
    while ( v6 < Size );
  }
}

// File Line: 1616
// RVA: 0x896DD0
void __fastcall Scaleform::GFx::FontResource::FontResource(
        Scaleform::GFx::FontResource *this,
        Scaleform::GFx::Resource *pfont,
        Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::FontResource::`vftable;
  this->pFont.pObject = 0i64;
  this->pBinding = pbinding;
  this->FontKey.pKeyInterface = 0i64;
  this->FontKey.hKeyData = 0i64;
  if ( pfont )
    Scaleform::Render::RenderBuffer::AddRef(pfont);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  *(_DWORD *)&this->LowerCaseTop = 0;
}

// File Line: 1624
// RVA: 0x896D00
void __fastcall Scaleform::GFx::FontResource::FontResource(
        Scaleform::GFx::FontResource *this,
        Scaleform::GFx::Resource *pfont,
        Scaleform::GFx::ResourceKey *key)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::FontResource::`vftable;
  this->pFont.pObject = 0i64;
  this->pBinding = 0i64;
  this->FontKey.pKeyInterface = 0i64;
  this->FontKey.hKeyData = 0i64;
  if ( pfont )
    Scaleform::Render::RenderBuffer::AddRef(pfont);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  if ( key->pKeyInterface )
    key->pKeyInterface->vfptr->AddRef(key->pKeyInterface, key->hKeyData);
  pKeyInterface = this->FontKey.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->FontKey.hKeyData);
  this->FontKey.pKeyInterface = key->pKeyInterface;
  this->FontKey.hKeyData = key->hKeyData;
  *(_DWORD *)&this->LowerCaseTop = 0;
}

// File Line: 1726
// RVA: 0x897070
void __fastcall Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(
        Scaleform::GFx::GFxSystemFontResourceKey *this,
        const char *pname,
        char fontFlags,
        Scaleform::GFx::Resource *pfontProvider)
{
  Scaleform::String *v8; // rax
  Scaleform::String *v9; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::String v11; // [rsp+20h] [rbp-28h] BYREF
  __int64 v12; // [rsp+28h] [rbp-20h]
  Scaleform::String result; // [rsp+68h] [rbp+20h] BYREF

  v12 = -2i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,261>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::GFxSystemFontResourceKey,261>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::GFxSystemFontResourceKey::`vftable;
  this->pFontProvider.pObject = 0i64;
  Scaleform::String::String(&this->FontName);
  Scaleform::String::String(&v11, pname);
  v9 = Scaleform::String::ToLower(v8, &result);
  Scaleform::String::operator=(&this->FontName, v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->CreateFontFlags = fontFlags & 3;
  if ( pfontProvider )
    Scaleform::Render::RenderBuffer::AddRef(pfontProvider);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)pfontProvider;
}

// File Line: 1765
// RVA: 0x8D98C0
unsigned __int64 __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::GetHashCode(
        Scaleform::GFx::GFxSystemFontResourceKeyInterface *this,
        _QWORD *hdata)
{
  return Scaleform::String::BernsteinHashFunctionCIS(
           (const void *)((hdata[3] & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(hdata[3] & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ hdata[2] ^ (hdata[2] >> 7) ^ *((unsigned int *)hdata + 8);
}

// File Line: 1772
// RVA: 0x159C2A0
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxSystemFontResourceKeyInterface_Instance__()
{
  GFxSystemFontResourceKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxSystemFontResourceKeyInterface::`vftable;
  return atexit((int (__fastcall *)())Scaleform::GFx::_dynamic_atexit_destructor_for__GFxSystemFontResourceKeyInterface_Instance__);
}

// File Line: 1775
// RVA: 0x8E7FB0
bool __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::KeyEquals(
        Scaleform::GFx::GFxSystemFontResourceKeyInterface *this,
        _QWORD *hdata,
        Scaleform::GFx::ResourceKey *other)
{
  _QWORD *hKeyData; // r10
  unsigned __int8 *v6; // rax
  unsigned __int64 v7; // r8
  int v8; // ecx
  int v9; // edx

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  v6 = (unsigned __int8 *)((hdata[3] & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v7 = (hKeyData[3] & 0xFFFFFFFFFFFFFFFCui64) - (hdata[3] & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v8 = v6[v7];
    v9 = *v6 - v8;
    if ( v9 )
      break;
    ++v6;
  }
  while ( v8 );
  return !v9 && hdata[2] == hKeyData[2] && *((_DWORD *)hdata + 8) == *((_DWORD *)hKeyData + 8);
}

// File Line: 1788
// RVA: 0x8BFC90
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::FontResource::CreateFontResourceKey(
        Scaleform::GFx::ResourceKey *result,
        const char *pname,
        char fontFlags,
        Scaleform::GFx::Resource *pfontProvider)
{
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::GFx::GFxSystemFontResourceKey *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  v8 = 0i64;
  v9 = (Scaleform::GFx::GFxSystemFontResourceKey *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     40i64,
                                                     0i64);
  if ( v9 )
  {
    Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(v9, pname, fontFlags, pfontProvider);
    v8 = v10;
  }
  GFxSystemFontResourceKeyInterface_Instance.vfptr->AddRef(&GFxSystemFontResourceKeyInterface_Instance, v8);
  result->pKeyInterface = &GFxSystemFontResourceKeyInterface_Instance;
  result->hKeyData = v8;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return result;
}

// File Line: 1802
// RVA: 0x8BFAC0
Scaleform::GFx::FontResource *__fastcall Scaleform::GFx::FontResource::CreateFontResource(
        const char *pname,
        unsigned int fontFlags,
        Scaleform::GFx::FontProvider *pprovider,
        Scaleform::GFx::ResourceWeakLib *plib)
{
  Scaleform::GFx::Resource *v8; // rsi
  Scaleform::GFx::Resource *v9; // rbp
  Scaleform::GFx::FontResource *v10; // rax
  Scaleform::GFx::Resource *v11; // rax
  Scaleform::GFx::Resource *pResource; // rdi
  _RTL_CRITICAL_SECTION *p_RefCount; // rbx
  Scaleform::GFx::Resource *v14; // rbx
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::ResourceKey k; // [rsp+48h] [rbp-20h] BYREF

  Scaleform::GFx::FontResource::CreateFontResourceKey(&k, pname, fontFlags, pprovider);
  phandle.State = RS_Unbound;
  phandle.pResource = 0i64;
  v8 = 0i64;
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(plib, &phandle, &k) == 3 )
  {
    v9 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::FontProvider *, const char *, _QWORD))pprovider->vfptr[1].__vecDelDtor)(
                                       pprovider,
                                       pname,
                                       fontFlags);
    if ( v9
      && ((v10 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64i64,
                                                   0i64)) == 0i64
        ? (v8 = 0i64)
        : (Scaleform::GFx::FontResource::FontResource(v10, v9, &k), v8 = v11),
          v8) )
    {
      pResource = phandle.pResource;
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v8);
    }
    else
    {
      pResource = phandle.pResource;
      p_RefCount = (_RTL_CRITICAL_SECTION *)&phandle.pResource->pLib[1].RefCount;
      EnterCriticalSection(p_RefCount);
      LODWORD(pResource[1].vfptr) = 2;
      Scaleform::String::operator=((Scaleform::String *)&pResource[2].RefCount, &customCaption);
      Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
        (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&pResource->pLib[4],
        (Scaleform::GFx::ResourceKey *)&pResource[1].pLib);
      Scaleform::Event::SetEvent((Scaleform::Event *)&pResource[2].pLib);
      LeaveCriticalSection(p_RefCount);
    }
    if ( v9 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  }
  else
  {
    v8 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    pResource = phandle.pResource;
  }
  if ( phandle.State == RS_Available )
  {
    if ( !_InterlockedDecrement(&pResource->RefCount.Value) )
    {
      v14 = phandle.pResource;
      v15 = phandle.pResource->pLib;
      if ( v15 )
      {
        v15->vfptr[1].__vecDelDtor(v15, (unsigned int)phandle.pResource);
        v14->pLib = 0i64;
      }
      v14->vfptr->__vecDelDtor(v14, 1u);
    }
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pResource);
  }
  if ( k.pKeyInterface )
    k.pKeyInterface->vfptr->Release(k.pKeyInterface, k.hKeyData);
  return (Scaleform::GFx::FontResource *)v8;
}se(k.pKeyInterface, k.hKeyData);
  return (Scaleform::

// File Line: 1838
// RVA: 0x9041C0
void __fastcall Scaleform::GFx::FontResource::ResolveTextureGlyphs(Scaleform::GFx::FontResource *this)
{
  Scaleform::GFx::FontDataBound *v2; // rax
  Scaleform::Render::Font *v3; // rax
  Scaleform::Render::Font *v4; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  int v6; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::FontDataBound *v7; // [rsp+50h] [rbp+18h]

  if ( ((__int64 (__fastcall *)(Scaleform::Render::Font *))this->pFont.pObject->vfptr[11].__vecDelDtor)(this->pFont.pObject) )
  {
    v6 = 75;
    v2 = (Scaleform::GFx::FontDataBound *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            72i64,
                                            &v6);
    v7 = v2;
    if ( v2 )
    {
      Scaleform::GFx::FontDataBound::FontDataBound(v2, (Scaleform::GFx::Resource *)this->pFont.pObject, this->pBinding);
      v4 = v3;
    }
    else
    {
      v4 = 0i64;
    }
    pObject = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pFont.pObject = v4;
  }
}

