// File Line: 35
// RVA: 0x89EC90
void __fastcall Scaleform::GFx::TextureGlyphData::TextureGlyphData(Scaleform::GFx::TextureGlyphData *this, Scaleform::GFx::TextureGlyphData *orig)
{
  Scaleform::GFx::TextureGlyphData *v2; // rbp
  Scaleform::ArrayLH<Scaleform::Render::TextureGlyph,261,Scaleform::ArrayDefaultPolicy> *v3; // r14
  Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *v4; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *v5; // r15
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rsi
  __int64 v9; // rdi
  __int128 *v10; // rax
  Scaleform::GFx::ResourceId *v11; // rbp
  __int64 v12; // rcx
  _QWORD *v13; // rax
  Scaleform::GFx::ResourceId *v14; // rdi
  signed __int64 v15; // rbx
  __int64 v16; // rax
  signed __int64 v17; // rdx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [rsp+30h] [rbp-88h]
  __int128 v21; // [rsp+40h] [rbp-78h]
  __int128 v22; // [rsp+50h] [rbp-68h]
  __int128 v23; // [rsp+60h] [rbp-58h]
  __int128 v24; // [rsp+70h] [rbp-48h]

  v2 = orig;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,261>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::TextureGlyphData,261>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextureGlyphData::`vftable';
  this->PackTextureConfig.NominalSize = orig->PackTextureConfig.NominalSize;
  this->PackTextureConfig.PadPixels = orig->PackTextureConfig.PadPixels;
  this->PackTextureConfig.TextureWidth = orig->PackTextureConfig.TextureWidth;
  this->PackTextureConfig.TextureHeight = orig->PackTextureConfig.TextureHeight;
  v3 = &this->TextureGlyphs;
  v4 = 0i64;
  v3->Data.Data = 0i64;
  v3->Data.Size = 0i64;
  v3->Data.Policy.Capacity = 0i64;
  v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *)&this->GlyphsTextures.mHash.pTable;
  this->GlyphsTextures.mHash.pTable = 0i64;
  this->FileCreation = orig->FileCreation;
  v6 = orig->TextureGlyphs.Data.Size;
  v7 = this->TextureGlyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy> *)&this->TextureGlyphs.Data.Data,
    &this->TextureGlyphs,
    orig->TextureGlyphs.Data.Size);
  if ( v6 > v7 )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(&v3->Data.Data[v7], v6 - v7);
  v8 = v2->TextureGlyphs.Data.Size;
  if ( v8 )
  {
    v9 = 0i64;
    do
    {
      v10 = (__int128 *)Scaleform::Render::TextureGlyph::operator=(&v3->Data.Data[v9], &v2->TextureGlyphs.Data.Data[v9]);
      v21 = *v10;
      v22 = v10[1];
      v23 = v10[2];
      v24 = v10[3];
      ++v9;
      --v8;
    }
    while ( v8 );
  }
  v11 = (Scaleform::GFx::ResourceId *)&v2->GlyphsTextures;
  v12 = *(_QWORD *)&v11->Id;
  if ( *(_QWORD *)&v11->Id )
  {
    v13 = (_QWORD *)(v12 + 16);
    do
    {
      if ( *v13 != -2i64 )
        break;
      v4 = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)((char *)v4 + 1);
      v13 += 5;
    }
    while ( (unsigned __int64)v4 <= *(_QWORD *)(v12 + 8) );
    key.pFirst = v11;
  }
  else
  {
    key.pFirst = 0i64;
  }
  key.pSecond = v4;
  _mm_store_si128((__m128i *)&key, (__m128i)key);
  v14 = key.pFirst;
  v15 = (signed __int64)key.pSecond;
  while ( v14 )
  {
    v16 = *(_QWORD *)&v14->Id;
    if ( !*(_QWORD *)&v14->Id || v15 > *(_QWORD *)(v16 + 8) )
      break;
    v17 = v16 + 40 * v15;
    key.pFirst = (Scaleform::GFx::ResourceId *)(v17 + 32);
    key.pSecond = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)(v17 + 40);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
      v5,
      v5,
      &key);
    v18 = *(_QWORD *)(*(_QWORD *)&v14->Id + 8i64);
    if ( v15 <= (signed __int64)v18 && ++v15 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)&v14->Id + 8 * (v15 + 4 * v15 + 2));
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v15;
        v19 += 5;
      }
      while ( v15 <= v18 );
    }
  }
}

// File Line: 52
// RVA: 0x8DF230
Scaleform::Render::TextureGlyph *__fastcall Scaleform::GFx::TextureGlyphData::GetTextureGlyph(Scaleform::GFx::TextureGlyphData *this, unsigned int glyphIndex)
{
  if ( glyphIndex < this->TextureGlyphs.Data.Size )
    return &this->TextureGlyphs.Data.Data[(unsigned __int64)glyphIndex];
  if ( !(_S12_14 & 1) )
  {
    _S12_14 |= 1u;
    dummyTextureGlyph.RefCount = 1;
    dummyTextureGlyph.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureGlyph::`vftable';
    dummyTextureGlyph.pImage.pObject = 0i64;
    dummyTextureGlyph.UvBounds = 0i64;
    dummyTextureGlyph.BindIndex = -1;
    atexit(Scaleform::GFx::TextureGlyphData::GetTextureGlyph_::_5_::_dynamic_atexit_destructor_for__dummyTextureGlyph__);
  }
  return &dummyTextureGlyph;
}

// File Line: 65
// RVA: 0x8B3160
void __fastcall Scaleform::GFx::TextureGlyphData::AddTextureGlyph(Scaleform::GFx::TextureGlyphData *this, unsigned int glyphIndex, Scaleform::Render::TextureGlyph *glyph)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::TextureGlyph *v4; // r15
  Scaleform::GFx::TextureGlyphData *v5; // rbp
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rsi
  Scaleform::Render::TextureGlyph *v8; // rax
  Scaleform::RefCountBase<Scaleform::Render::TextureGlyph,2> v9; // ST20_16
  Scaleform::Render::Rect<float> v10; // xmm0
  __int128 v11; // ST30_16
  __int128 v12; // ST50_16

  v3 = glyphIndex;
  v4 = glyph;
  v5 = this;
  if ( this->TextureGlyphs.Data.Size > glyphIndex )
    goto LABEL_8;
  v6 = this->TextureGlyphs.Data.Size;
  v7 = glyphIndex + 1;
  Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::TextureGlyph,Scaleform::AllocatorLH<Scaleform::Render::TextureGlyph,261>,Scaleform::ArrayDefaultPolicy> *)&this->TextureGlyphs.Data.Data,
    &this->TextureGlyphs,
    v7);
  if ( v7 > v6 )
    Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(
      &v5->TextureGlyphs.Data.Data[v6],
      v7 - v6);
  if ( v5->TextureGlyphs.Data.Size > v3 )
  {
LABEL_8:
    v8 = Scaleform::Render::TextureGlyph::operator=(&v5->TextureGlyphs.Data.Data[v3], v4);
    v9 = v8->0;
    v10 = v8->UvBounds;
    v11 = *(_OWORD *)&v8->pImage.pObject;
    v12 = *(_OWORD *)&v8->UvOrigin.x;
  }
}

// File Line: 113
// RVA: 0x8B3050
void __fastcall Scaleform::GFx::TextureGlyphData::AddTexture(Scaleform::GFx::TextureGlyphData *this, __int64 textureId, Scaleform::GFx::ResourceHandle *rh)
{
  Scaleform::GFx::ResourceHandle *v3; // rsi
  Scaleform::GFx::ResourceId *v4; // rbp
  Scaleform::GFx::TextureGlyphData *v5; // r14
  Scaleform::GFx::Resource *v6; // rdx
  Scaleform::GFx::Resource *v7; // rdi
  Scaleform::GFx::ResourceLibBase *v8; // rcx
  __int64 v9; // rdi
  __int64 v10; // rcx
  Scaleform::GFx::ResourceHandle::HandleType v11; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::Resource *v12; // [rsp+30h] [rbp-38h]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeRef key; // [rsp+38h] [rbp-30h]

  v3 = rh;
  v4 = (Scaleform::GFx::ResourceId *)textureId;
  v5 = this;
  v11 = 0;
  v12 = 0i64;
  if ( rh->HType == RH_Pointer )
  {
    v6 = rh->pResource;
    if ( v6 )
      _InterlockedExchangeAdd(&v6->RefCount.Value, 1u);
  }
  if ( v11 == RH_Pointer )
  {
    v7 = v12;
    if ( v12 )
    {
      if ( !_InterlockedDecrement(&v12->RefCount.Value) )
      {
        v8 = v12->pLib;
        if ( v8 )
        {
          v8->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, (unsigned int)v12);
          v12->pLib = 0i64;
        }
        v7->vfptr->__vecDelDtor(v7, 1u);
      }
    }
  }
  v11 = v3->HType;
  v12 = v3->pResource;
  key.pFirst = v4;
  key.pSecond = (Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource> *)&v11;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourcePtr<Scaleform::GFx::ImageResource>,Scaleform::FixedSizeHash<Scaleform::GFx::ResourceId> >::NodeHashF> > *)&v5->GlyphsTextures.mHash.pTable,
    &v5->GlyphsTextures,
    &key);
  if ( v11 == RH_Pointer )
  {
    v9 = (__int64)v12;
    if ( v12 )
    {
      if ( !_InterlockedDecrement(&v12->RefCount.Value) )
      {
        v10 = *(_QWORD *)(v9 + 16);
        if ( v10 )
        {
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v10 + 8i64))(v10, v9);
          *(_QWORD *)(v9 + 16) = 0i64;
        }
        (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
      }
    }
  }
}

// File Line: 186
// RVA: 0x8DF210
Scaleform::Render::TextureGlyph *__fastcall Scaleform::GFx::FontDataBound::GetTextureGlyph(Scaleform::GFx::FontDataBound *this, unsigned int glyphIndex)
{
  Scaleform::GFx::TextureGlyphData *v2; // rcx

  v2 = this->pTGData.pObject;
  if ( v2 )
    JUMPOUT(glyphIndex, v2->TextureGlyphs.Data.Size, Scaleform::GFx::TextureGlyphData::GetTextureGlyph);
  return 0i64;
}

// File Line: 193
// RVA: 0x8DF300
float __fastcall Scaleform::GFx::FontData::GetTextureGlyphHeight(Scaleform::GFx::FontData *this)
{
  Scaleform::GFx::TextureGlyphData *v1; // rax
  float result; // xmm0_4

  v1 = this->pTGData.pObject;
  if ( v1 )
    result = (double)v1->PackTextureConfig.NominalSize * 1024.0 * 0.0006510416666666666;
  else
    result = 0.0;
  return result;
}

// File Line: 200
// RVA: 0x896480
void __fastcall Scaleform::GFx::FontData::FontData(Scaleform::GFx::FontData *this)
{
  Scaleform::Render::FontCacheHandleManager *volatile v1; // rt1
  Scaleform::Render::FontCacheHandleManager *volatile v2; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *v3; // rax
  Scaleform::ArrayLH<Scaleform::GFx::FontData::AdvanceEntry,261,Scaleform::ArrayDefaultPolicy> *v4; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  *(_QWORD *)&this->Ascent = 0i64;
  *(_QWORD *)&this->Leading = 0i64;
  *(_DWORD *)&this->LowerCaseTop = 0;
  v1 = this->hRef.pManager.Value;
  this->hRef.pManager.Value = 0i64;
  v2 = this->hRef.pManager.Value;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable';
  this->Name = 0i64;
  this->pTGData.pObject = 0i64;
  v3 = &this->Glyphs;
  v3->Data.Data = 0i64;
  v3->Data.Size = 0i64;
  v3->Data.Policy.Capacity = 0i64;
  this->CodeTable.mHash.pTable = 0i64;
  v4 = &this->AdvanceTable;
  v4->Data.Data = 0i64;
  v4->Data.Size = 0i64;
  v4->Data.Policy.Capacity = 0i64;
  this->KerningPairs.mHash.pTable = 0i64;
}

// File Line: 205
// RVA: 0x896330
void __fastcall Scaleform::GFx::FontData::FontData(Scaleform::GFx::FontData *this, const char *name, unsigned int fontFlags)
{
  const char *v3; // rdi
  Scaleform::GFx::FontData *v4; // rsi
  Scaleform::Render::FontCacheHandleManager *volatile v5; // rt1
  Scaleform::Render::FontCacheHandleManager *volatile v6; // rax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::ArrayLH<Scaleform::GFx::FontData::AdvanceEntry,261,Scaleform::ArrayDefaultPolicy> *v8; // rax
  signed __int64 v9; // rbx
  signed __int64 v10; // rdx
  char *v11; // rax

  v3 = name;
  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  *(_QWORD *)&this->Ascent = 0i64;
  this->Leading = 0.0;
  this->Flags = fontFlags;
  *(_DWORD *)&this->LowerCaseTop = 0;
  v5 = this->hRef.pManager.Value;
  this->hRef.pManager.Value = 0i64;
  v6 = this->hRef.pManager.Value;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable';
  this->Name = 0i64;
  this->pTGData.pObject = 0i64;
  v7 = &this->Glyphs;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  this->CodeTable.mHash.pTable = 0i64;
  v8 = &this->AdvanceTable;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  this->KerningPairs.mHash.pTable = 0i64;
  v9 = -1i64;
  v10 = -1i64;
  do
    ++v10;
  while ( v3[v10] );
  v11 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v10 + 1, 0i64);
  v4->Name = v11;
  if ( v11 )
  {
    do
      ++v9;
    while ( v3[v9] );
    strcpy_s(v11, v9 + 1, v3);
  }
  v4->Flags |= 0x2000u;
}

// File Line: 215
// RVA: 0x8A4640
void __fastcall Scaleform::GFx::FontData::~FontData(Scaleform::GFx::FontData *this)
{
  Scaleform::GFx::FontData *v1; // rbx
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  Scaleform::RefCountNTSImpl *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontData::`vftable';
  v2 = (Scaleform::ArrayData<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::AmpMovieObjectDesc>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Glyphs;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *)&this->Glyphs.Data.Data,
    &this->Glyphs,
    0i64);
  if ( v1->Name )
  {
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v1->Name = 0i64;
  }
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v1->KerningPairs);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->AdvanceTable.Data.Data);
  Scaleform::HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::~HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>((Scaleform::HashSet<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&v1->CodeTable);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>(v2);
  v3 = (Scaleform::RefCountNTSImpl *)&v1->pTGData.pObject->vfptr;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&v1->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 228
// RVA: 0x8F6F80
void __fastcall Scaleform::GFx::FontData::Read(Scaleform::GFx::FontData *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v3; // r15
  Scaleform::GFx::FontData *v4; // rsi
  Scaleform::GFx::Stream *v5; // rdi
  Scaleform::GFx::TagType v6; // eax
  __int64 v7; // r9
  unsigned __int16 v8; // r8
  int v9; // er15
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  int *v12; // rax
  int *v13; // rcx
  __int64 v14; // r8
  signed int v15; // er12
  signed __int64 v16; // r15
  signed __int64 v17; // r13
  __int64 v18; // r8
  unsigned __int16 v19; // r9
  int v20; // er13
  unsigned __int64 v21; // rbx
  unsigned __int64 v22; // r8
  int *v23; // rcx
  __int64 v24; // r9
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *v25; // r15
  unsigned __int64 v26; // rbx
  int *v27; // rcx
  signed __int64 v28; // rax
  signed __int64 v29; // rsi
  signed int v30; // er12
  int v31; // ebx
  signed int v32; // edx
  unsigned int v33; // eax
  int v34; // ecx
  int v35; // eax
  unsigned int v36; // er15
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v37; // rbx
  __int64 v38; // r15
  Scaleform::Render::RenderBuffer *v39; // rcx
  int *v40; // rdx
  const char *v41; // rdx
  unsigned int v42; // eax
  bool v43; // bl
  bool v44; // r14
  bool v45; // al
  bool v46; // r12
  __int64 v47; // rcx
  __int64 v48; // rbx
  __int64 v49; // r9
  unsigned __int16 v50; // r8
  signed int v51; // er15
  signed int v52; // er13
  int v53; // eax
  __int64 v54; // r8
  int v55; // er15
  unsigned int v56; // eax
  __int64 v57; // r9
  unsigned __int64 v58; // rbx
  unsigned __int64 v59; // r8
  int *v60; // rcx
  __int64 v61; // r12
  __int64 v62; // r8
  int v63; // er15
  unsigned __int64 v64; // rbx
  unsigned __int64 v65; // r8
  int *v66; // rcx
  __int64 v67; // r8
  float v68; // er12
  unsigned int v69; // eax
  __int64 v70; // r15
  __int64 v71; // r9
  unsigned __int16 v72; // r8
  int v73; // er12
  unsigned __int64 v74; // rbx
  unsigned __int64 v75; // r8
  int *v76; // rcx
  __int64 v77; // r9
  unsigned __int64 v78; // r13
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *v79; // r15
  unsigned __int64 v80; // rbx
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v81; // rcx
  unsigned __int64 v82; // rax
  signed int v83; // eax
  signed __int64 v84; // r15
  __int64 v85; // r13
  int *v86; // rdx
  int v87; // ebx
  signed int v88; // eax
  unsigned int v89; // er8
  int v90; // ecx
  int v91; // eax
  int v92; // eax
  unsigned int v93; // er12
  Scaleform::GFx::Resource *v94; // rbx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v95; // r12
  Scaleform::Render::RenderBuffer *v96; // rcx
  Scaleform::GFx::FontData::AdvanceEntry *v97; // rcx
  float v98; // xmm2_4
  float v99; // xmm3_4
  float v100; // xmm0_4
  float v101; // xmm1_4
  unsigned __int64 v102; // rdi
  Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy> *v103; // rsi
  unsigned __int64 v104; // r8
  int *v105; // r15
  unsigned __int64 v106; // rsi
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v107; // rcx
  unsigned __int64 j; // rdi
  int v109; // edx
  __int64 v110; // rax
  int v111; // ecx
  float v112; // xmm6_4
  __int64 v113; // r9
  __int16 v114; // r8
  __int64 v115; // r9
  __int16 v116; // r8
  __int64 v117; // r9
  __int16 v118; // r8
  float v119; // xmm0_4
  __int64 v120; // r9
  __int64 v121; // r8
  unsigned __int64 v122; // rdx
  unsigned __int64 v123; // r15
  __int64 v124; // rbx
  Scaleform::GFx::FontData::AdvanceEntry *v125; // r12
  __int64 v126; // r9
  unsigned __int16 v127; // r8
  unsigned __int64 i; // rbx
  __int64 v129; // r9
  unsigned __int16 v130; // r8
  int v131; // er13
  int v132; // er12
  unsigned int v133; // edx
  unsigned int v134; // er8
  unsigned int v135; // eax
  int v136; // edx
  __int64 v137; // r8
  __int16 v138; // r15
  __int64 v139; // r8
  __int16 v140; // bx
  unsigned int v141; // eax
  __int64 v142; // rdx
  __int64 v143; // rdx
  __int64 v144; // r9
  __int16 v145; // r8
  signed __int64 v146; // rdx
  unsigned __int64 v147; // r9
  const char *v148; // r9
  unsigned __int64 v149; // rdx
  __int64 v150; // rcx
  __int64 v151; // [rsp+20h] [rbp-A8h]
  __int64 v152; // [rsp+28h] [rbp-A0h]
  char v153; // [rsp+30h] [rbp-98h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> v154; // [rsp+38h] [rbp-90h]
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v155; // [rsp+50h] [rbp-78h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+58h] [rbp-70h]
  float v157; // [rsp+70h] [rbp-58h]
  float v158; // [rsp+74h] [rbp-54h]
  Scaleform::MemoryHeap *v159; // [rsp+78h] [rbp-50h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v160; // [rsp+80h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeRef key; // [rsp+88h] [rbp-40h]
  Scaleform::GFx::Resource *v162; // [rsp+98h] [rbp-30h]
  Scaleform::GFx::Resource *v163; // [rsp+A0h] [rbp-28h]
  Scaleform::MemoryHeap *v164; // [rsp+A8h] [rbp-20h]
  __int64 v165; // [rsp+B0h] [rbp-18h]
  Scaleform::Render::Rect<float> pr; // [rsp+B8h] [rbp-10h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v167; // [rsp+120h] [rbp+58h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v168; // [rsp+128h] [rbp+60h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *v169; // [rsp+130h] [rbp+68h]

  v165 = -2i64;
  v3 = p;
  v4 = this;
  v5 = p->pAltStream;
  if ( !v5 )
    v5 = &p->ProcessInfo.Stream;
  v153 = 1;
  v159 = p->pLoadData.pObject->pHeap;
  v164 = v159;
  v6 = tagInfo->TagType;
  if ( tagInfo->TagType == 10 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "reading DefineFont\n");
    LODWORD(v155) = v5->Pos + v5->FilePos - v5->DataSize;
    v169 = &pheapAddr;
    pheapAddr.Data = 0i64;
    pheapAddr.Size = 0i64;
    pheapAddr.Policy.Capacity = 0i64;
    v5->UnusedBits = 0;
    if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
    v7 = v5->Pos;
    v8 = (unsigned __int8)v5->pBuffer[v7] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v7 + 1)] << 8);
    v5->Pos = v7 + 2;
    v9 = v8;
    v10 = pheapAddr.Size + 1;
    if ( pheapAddr.Size + 1 >= pheapAddr.Size )
    {
      if ( v10 > pheapAddr.Policy.Capacity )
      {
        v11 = v10 + (v10 >> 2);
        goto LABEL_11;
      }
    }
    else if ( v10 < pheapAddr.Policy.Capacity >> 1 )
    {
      v11 = pheapAddr.Size + 1;
LABEL_11:
      Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v11);
      goto LABEL_12;
    }
LABEL_12:
    pheapAddr.Size = v10;
    v12 = pheapAddr.Data;
    v13 = &pheapAddr.Data[v10 - 1];
    if ( v13 )
    {
      *v13 = v9;
      v12 = pheapAddr.Data;
    }
    v14 = (unsigned int)*v12;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "offset[0] = %d\n");
    LODWORD(v169) = *pheapAddr.Data >> 1;
    v15 = 1;
    v16 = 1i64;
    v17 = (signed int)v169;
    if ( (signed int)v169 > 1i64 )
    {
      while ( 1 )
      {
        v5->UnusedBits = 0;
        if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
        v18 = v5->Pos;
        v19 = (unsigned __int8)v5->pBuffer[v18] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v18 + 1)] << 8);
        v5->Pos = v18 + 2;
        if ( !v19 )
        {
          LOBYTE(v15) = 0;
          break;
        }
        v20 = v19;
        v21 = pheapAddr.Size + 1;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v21 > pheapAddr.Policy.Capacity )
          {
            v22 = v21 + (v21 >> 2);
            goto LABEL_23;
          }
        }
        else if ( v21 < pheapAddr.Policy.Capacity >> 1 )
        {
          v22 = pheapAddr.Size + 1;
LABEL_23:
          Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            v22);
          goto LABEL_24;
        }
LABEL_24:
        pheapAddr.Size = v21;
        v23 = &pheapAddr.Data[v21 - 1];
        if ( v23 )
          *v23 = v20;
        v24 = (unsigned int)pheapAddr.Data[v16];
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
          "offset[%d] = %d\n");
        ++v15;
        ++v16;
        v17 = (signed int)v169;
        if ( v16 >= (signed int)v169 )
        {
          LOBYTE(v15) = 1;
          break;
        }
      }
    }
    v25 = &v4->Glyphs;
    pheapAddr.Size = (unsigned __int64)&v4->Glyphs;
    v26 = v4->Glyphs.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *)&v4->Glyphs.Data.Data,
      &v4->Glyphs,
      v17);
    if ( v17 > v26 )
    {
      v27 = (int *)&v25->Data.Data[v26];
      v155 = &v25->Data.Data[v26];
      v28 = v17 - v26;
      if ( v17 != v26 )
      {
        do
        {
          pheapAddr.Data = v27;
          if ( v27 )
            *(_QWORD *)v27 = 0i64;
          v27 += 2;
          v155 = (Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *)v27;
          --v28;
        }
        while ( v28 );
      }
    }
    if ( (_BYTE)v15 )
    {
      v29 = 0i64;
      if ( v17 > 0 )
      {
        v30 = 1;
        do
        {
          v31 = pheapAddr.Data[v29] + (_DWORD)v155;
          v5->UnusedBits = 0;
          v32 = v5->FilePos;
          v33 = v5->DataSize;
          v34 = v5->FilePos - v33;
          if ( v31 < v34 || v31 >= v32 )
          {
            if ( (v5->ResyncFile || v5->Pos + v34 != v31)
              && ((signed int (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v5->pInput.pObject->vfptr[14].__vecDelDtor)(
                   v5->pInput.pObject,
                   (unsigned int)v31,
                   0i64) >= 0 )
            {
              v5->ResyncFile = 0;
              *(_QWORD *)&v5->Pos = 0i64;
              v5->FilePos = v31;
            }
          }
          else
          {
            v5->Pos = v31 + v33 - v32;
          }
          if ( v30 >= (signed int)v169 )
            v35 = LODWORD(v168->Size) + HIDWORD(v168->Size) - v31;
          else
            v35 = pheapAddr.Data[v29 + 1] - pheapAddr.Data[v29];
          v36 = v35;
          v37 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v159->vfptr->Alloc)(v159, 32i64);
          pheapAddr.Data = (int *)v37;
          if ( v37 )
          {
            v37->Data = (int *)&Scaleform::RefCountImplCore::`vftable';
            LODWORD(v37->Size) = 1;
            v37->Data = (int *)&Scaleform::RefCountImpl::`vftable';
            v37->Data = (int *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
            v37->Data = (int *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
            v37->Data = (int *)&Scaleform::Render::ShapeDataInterface::`vftable';
            v37->Data = (int *)&Scaleform::GFx::ShapeDataBase::`vftable';
            v37->Policy.Capacity = 0i64;
            LOBYTE(v37[1].Data) = 0;
            v37->Data = (int *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
          }
          else
          {
            v37 = 0i64;
          }
          v160 = v37;
          LOBYTE(v151) = 0;
          (*((void (__fastcall **)(Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *, Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *, signed __int64, _QWORD, __int64))v37->Data
           + 15))(
            v37,
            v167,
            2i64,
            v36,
            v151);
          v38 = *(_QWORD *)pheapAddr.Size;
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v37);
          v39 = *(Scaleform::Render::RenderBuffer **)(v38 + 8 * v29);
          if ( v39 )
            Scaleform::RefCountImpl::Release(v39);
          *(_QWORD *)(v38 + 8 * v29) = v37;
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v37);
          ++v30;
          ++v29;
        }
        while ( v29 < v17 );
      }
    }
    else
    {
      v4->Flags |= 0x1000u;
    }
    v168 = &pheapAddr;
    v40 = pheapAddr.Data;
    goto LABEL_248;
  }
  if ( v6 == 48 )
  {
    v41 = "reading DefineFont2: ";
  }
  else
  {
    if ( v6 != 75 )
      return;
    v41 = "reading DefineFont3: ";
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    v41);
  v42 = Scaleform::GFx::Stream::ReadUInt(v5, 1u);
  LOBYTE(v169) = v42 != 0;
  if ( v42 )
    v4->Flags |= 0x2000u;
  else
    v4->Flags &= 0xFFFFDFFF;
  v43 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  v44 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  v45 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  if ( v43 )
  {
    v4->Flags &= 0xFFFFFEFF;
    v4->Flags |= 0x200u;
  }
  else if ( v45 )
  {
    v4->Flags &= 0xFFFFFDFF;
    v4->Flags |= 0x100u;
  }
  else
  {
    v4->Flags &= 0xFFFFFCFF;
  }
  if ( v44 )
    v4->Flags |= 0x8000u;
  else
    v4->Flags &= 0xFFFF7FFF;
  v46 = Scaleform::GFx::Stream::ReadUInt(v5, 1u) != 0;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 0x4000u;
  else
    v4->Flags &= 0xFFFFBFFF;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 1u;
  else
    v4->Flags &= 0xFFFFFFFE;
  if ( Scaleform::GFx::Stream::ReadUInt(v5, 1u) )
    v4->Flags |= 2u;
  else
    v4->Flags &= 0xFFFFFFFD;
  v5->UnusedBits = 0;
  if ( (signed int)(v5->DataSize - v5->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v5, 1);
  v47 = v5->Pos;
  v48 = (unsigned __int8)v5->pBuffer[v47];
  v5->Pos = v47 + 1;
  v4->Name = Scaleform::GFx::Stream::ReadStringWithLength(v5, v3->pLoadData.pObject->pHeap);
  v5->UnusedBits = 0;
  if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
  v49 = v5->Pos;
  v50 = (unsigned __int8)v5->pBuffer[v49] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v49 + 1)] << 8);
  v5->Pos = v49 + 2;
  v51 = v50;
  LODWORD(v159) = v50;
  if ( v5->ParseFlags & 1 )
  {
    v4->Name;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  Name = %s, %d glyphs\n");
    LODWORD(v152) = (v4->Flags >> 1) & 1;
    LODWORD(v151) = v4->Flags & 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n");
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "  LangCode = %d\n");
  }
  LODWORD(v155) = v5->Pos + v5->FilePos - v5->DataSize;
  v160 = &v154;
  v154.Data = 0i64;
  v154.Size = 0i64;
  v154.Policy.Capacity = 0i64;
  v52 = v51;
  if ( v51 > 0 )
  {
    v5->UnusedBits = 0;
    v53 = v5->DataSize - v5->Pos;
    if ( v46 )
    {
      if ( v53 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 4);
      v54 = v5->Pos;
      v55 = (unsigned __int8)v5->pBuffer[v54] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v54 + 1)] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v54 + 2)] | ((unsigned __int8)v5->pBuffer[(unsigned int)(v54 + 3)] << 8)) << 8)) << 8);
      v56 = v54 + 4;
    }
    else
    {
      if ( v53 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v57 = v5->Pos;
      v56 = v57 + 2;
      v55 = (unsigned __int16)((unsigned __int8)v5->pBuffer[v57] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v57 + 1)] << 8));
    }
    v5->Pos = v56;
    if ( !v55 )
    {
      v153 = 0;
      v52 = 0;
      goto LABEL_104;
    }
    v58 = v154.Size + 1;
    if ( v154.Size + 1 >= v154.Size )
    {
      if ( v58 <= v154.Policy.Capacity )
        goto LABEL_102;
      v59 = v58 + (v58 >> 2);
    }
    else
    {
      if ( v58 >= v154.Policy.Capacity >> 1 )
        goto LABEL_102;
      v59 = v154.Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
      &v154,
      &v154,
      v59);
LABEL_102:
    v154.Size = v58;
    v60 = &v154.Data[v58 - 1];
    if ( v60 )
      *v60 = v55;
  }
LABEL_104:
  if ( !v46 )
  {
    if ( v52 <= 1 )
    {
LABEL_134:
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v77 = v5->Pos;
      v69 = v77 + 2;
      LODWORD(v68) = (unsigned __int16)((unsigned __int8)v5->pBuffer[v77] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v77 + 1)] << 8));
      goto LABEL_137;
    }
    v70 = (unsigned int)(v52 - 1);
    while ( 1 )
    {
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v71 = v5->Pos;
      v72 = (unsigned __int8)v5->pBuffer[v71] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v71 + 1)] << 8);
      v5->Pos = v71 + 2;
      v73 = v72;
      v74 = v154.Size + 1;
      if ( v154.Size + 1 >= v154.Size )
      {
        if ( v74 > v154.Policy.Capacity )
        {
          v75 = v74 + (v74 >> 2);
          goto LABEL_130;
        }
      }
      else if ( v74 < v154.Policy.Capacity >> 1 )
      {
        v75 = v154.Size + 1;
LABEL_130:
        Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
          &v154,
          &v154,
          v75);
        goto LABEL_131;
      }
LABEL_131:
      v154.Size = v74;
      v76 = &v154.Data[v74 - 1];
      if ( v76 )
        *v76 = v73;
      if ( !--v70 )
        goto LABEL_134;
    }
  }
  if ( v52 > 1 )
  {
    v61 = (unsigned int)(v52 - 1);
    do
    {
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 4);
      v62 = v5->Pos;
      v63 = (unsigned __int8)v5->pBuffer[v62] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v62 + 1)] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v62 + 2)] | ((unsigned __int8)v5->pBuffer[(unsigned int)(v62 + 3)] << 8)) << 8)) << 8);
      v5->Pos = v62 + 4;
      v64 = v154.Size + 1;
      if ( v154.Size + 1 >= v154.Size )
      {
        if ( v64 > v154.Policy.Capacity )
        {
          v65 = v64 + (v64 >> 2);
          goto LABEL_114;
        }
      }
      else if ( v64 < v154.Policy.Capacity >> 1 )
      {
        v65 = v154.Size + 1;
LABEL_114:
        Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
          &v154,
          &v154,
          v65);
        goto LABEL_115;
      }
LABEL_115:
      v154.Size = v64;
      v66 = &v154.Data[v64 - 1];
      if ( v66 )
        *v66 = v63;
      --v61;
    }
    while ( v61 );
  }
  v5->UnusedBits = 0;
  if ( (signed int)(v5->DataSize - v5->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v5, 4);
  v67 = v5->Pos;
  LODWORD(v68) = (unsigned __int8)v5->pBuffer[v67] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v67 + 1)] | (((unsigned __int8)v5->pBuffer[(unsigned int)(v67 + 2)] | ((unsigned __int8)v5->pBuffer[(unsigned int)(v67 + 3)] << 8)) << 8)) << 8);
  v69 = v67 + 4;
LABEL_137:
  v157 = v68;
  v5->Pos = v69;
  v78 = (signed int)v159;
  v79 = &v4->Glyphs;
  pheapAddr.Data = (int *)&v4->Glyphs;
  v80 = v4->Glyphs.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *)&v4->Glyphs.Data.Data,
    &v4->Glyphs,
    (signed int)v159);
  if ( v78 > v80 )
  {
    v81 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v79->Data.Data[v80];
    v155 = &v79->Data.Data[v80];
    v82 = v78 - v80;
    if ( v78 != v80 )
    {
      do
      {
        v160 = v81;
        if ( v81 )
          v81->Data = 0i64;
        v81 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v81 + 8);
        v155 = (Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *)v81;
        --v82;
      }
      while ( v82 );
    }
  }
  if ( !v153 )
  {
    v109 = LODWORD(v68) + (_DWORD)v155;
    v110 = v5->TagStackEntryCount - 1;
    if ( (unsigned int)v110 >= 2 )
      v111 = 0;
    else
      v111 = v5->TagStack[v110];
    if ( v109 >= v111 )
      goto LABEL_191;
    Scaleform::GFx::Stream::SetPosition(v5, v109);
    v4->Flags |= 0x1000u;
LABEL_193:
    Scaleform::GFx::FontData::ReadCodeTable(v4, v5);
    if ( (_BYTE)v169 )
    {
      if ( LODWORD(v168->Data) == 75 )
        v112 = FLOAT_0_050000001;
      else
        v112 = *(float *)&FLOAT_1_0;
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v113 = v5->Pos;
      v114 = (unsigned __int8)v5->pBuffer[v113] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v113 + 1)] << 8);
      v5->Pos = v113 + 2;
      v4->Ascent = (float)v114 * v112;
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v115 = v5->Pos;
      v116 = (unsigned __int8)v5->pBuffer[v115] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v115 + 1)] << 8);
      v5->Pos = v115 + 2;
      v4->Descent = (float)v116 * v112;
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v117 = v5->Pos;
      v118 = (unsigned __int8)v5->pBuffer[v117] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v117 + 1)] << 8);
      v5->Pos = v117 + 2;
      v119 = (float)v118 * v112;
      v4->Leading = v119;
      if ( v5->ParseFlags & 1 )
      {
        v120 = (unsigned int)(signed int)v4->Descent;
        v121 = (unsigned int)(signed int)v4->Ascent;
        LODWORD(v151) = (signed int)v119;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
          "  Ascent = %d, Descent = %d, Leading = %d\n");
      }
      v122 = v4->Glyphs.Data.Size;
      if ( v4->AdvanceTable.Data.Size != v122 )
        Scaleform::ArrayData<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Resize(
          &v4->AdvanceTable.Data,
          v122);
      v123 = v4->AdvanceTable.Data.Size;
      if ( v123 )
      {
        v124 = 0i64;
        do
        {
          v125 = v4->AdvanceTable.Data.Data;
          v5->UnusedBits = 0;
          if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
          v126 = v5->Pos;
          v127 = (unsigned __int8)v5->pBuffer[v126] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v126 + 1)] << 8);
          v5->Pos = v126 + 2;
          v125[v124].Advance = (float)v127 * v112;
          ++v124;
          --v123;
        }
        while ( v123 );
      }
      for ( i = v4->Glyphs.Data.Size; i; --i )
        Scaleform::GFx::Stream::ReadRect(v5, &pr);
      v5->UnusedBits = 0;
      if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
      v129 = v5->Pos;
      v130 = (unsigned __int8)v5->pBuffer[v129] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v129 + 1)] << 8);
      v5->Pos = v129 + 2;
      v131 = v130;
      if ( v5->ParseFlags & 1 )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
          "  KerningCount = %d\n");
      v132 = 0;
      if ( v131 > 0 )
      {
        while ( 1 )
        {
          v133 = v5->DataSize;
          v134 = v5->Pos;
          if ( (signed int)(v134 + v5->FilePos - v133) >= HIDWORD(v168->Size) + LODWORD(v168->Size) )
            break;
          v135 = v4->Flags >> 14;
          v5->UnusedBits = 0;
          v136 = v133 - v134;
          if ( v135 & 1 )
          {
            if ( v136 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
            v137 = v5->Pos;
            v138 = (unsigned __int8)v5->pBuffer[v137] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v137 + 1)] << 8);
            v5->Pos = v137 + 2;
            v5->UnusedBits = 0;
            if ( (signed int)(v5->DataSize - (v137 + 2)) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
            v139 = v5->Pos;
            v140 = (unsigned __int8)v5->pBuffer[v139] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v139 + 1)] << 8);
            v141 = v139 + 2;
          }
          else
          {
            if ( v136 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(v5, 1);
            v142 = v5->Pos;
            v138 = (unsigned __int8)v5->pBuffer[v142];
            v5->Pos = v142 + 1;
            v5->UnusedBits = 0;
            if ( (signed int)(v5->DataSize - (v142 + 1)) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer(v5, 1);
            v143 = v5->Pos;
            v140 = (unsigned __int8)v5->pBuffer[v143];
            v141 = v143 + 1;
          }
          v5->Pos = v141;
          v5->UnusedBits = 0;
          if ( (signed int)(v5->DataSize - v5->Pos) < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(v5, 2);
          v144 = v5->Pos;
          v145 = (unsigned __int8)v5->pBuffer[v144] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v144 + 1)] << 8);
          v5->Pos = v144 + 2;
          *(float *)&v155 = (float)v145 * v112;
          LOWORD(v158) = v138;
          HIWORD(v158) = v140;
          if ( v5->ParseFlags & 1 )
          {
            LODWORD(v151) = (signed int)(float)((float)v145 * v112);
            Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
              (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
              "     Pair: %d - %d,\tadj = %d\n");
          }
          key.pFirst = (Scaleform::GFx::FontData::KerningPair *)&v158;
          key.pSecond = (const float *)&v155;
          v146 = 4i64;
          v147 = 5381i64;
          do
            v147 = *((unsigned __int8 *)&v158 + --v146) + 65599 * v147;
          while ( v146 );
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF> > *)&v4->KerningPairs.mHash.pTable,
            &v4->KerningPairs,
            &key,
            v147);
          if ( ++v132 >= v131 )
            goto LABEL_242;
        }
        v148 = "<noname>";
        if ( v4->Name )
          v148 = v4->Name;
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
          "Corrupted file %s, kerning table of the font '%s' is longer than tagLength.",
          (v5->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
          v148,
          v151,
          v152);
      }
    }
LABEL_242:
    if ( !v153 )
    {
      v149 = v4->AdvanceTable.Data.Size;
      if ( v149 )
      {
        v150 = 0i64;
        do
        {
          *(_QWORD *)&v4->AdvanceTable.Data.Data[v150].Left = 0i64;
          ++v150;
          --v149;
        }
        while ( v149 );
      }
    }
    v168 = &v154;
    goto LABEL_247;
  }
  v83 = (signed int)v168->Data;
  if ( LODWORD(v168->Data) == 48 )
    v83 = 22;
  LODWORD(pheapAddr.Size) = v83;
  if ( (_BYTE)v169 )
    Scaleform::ArrayData<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v4->AdvanceTable.Data,
      v78);
  LODWORD(v154.Policy.Capacity) = 0;
  v84 = 0i64;
  if ( (signed __int64)v78 > 0 )
  {
    v85 = 0i64;
    HIDWORD(v159) = 1;
    while ( 1 )
    {
      v86 = v154.Data;
      v87 = v154.Data[v84] + (_DWORD)v155;
      v5->UnusedBits = 0;
      v88 = v5->FilePos;
      v89 = v5->DataSize;
      v90 = v5->FilePos - v89;
      if ( v87 < v90 || v87 >= v88 )
      {
        if ( v5->ResyncFile || v5->Pos + v90 != v87 )
        {
          v91 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v5->pInput.pObject->vfptr[14].__vecDelDtor)(
                  v5->pInput.pObject,
                  (unsigned int)v87,
                  0i64);
          v86 = v154.Data;
          if ( v91 >= 0 )
          {
            v5->ResyncFile = 0;
            *(_QWORD *)&v5->Pos = 0i64;
            v5->FilePos = v87;
          }
        }
      }
      else
      {
        v5->Pos = v89 + v87 - v88;
      }
      v92 = SHIDWORD(v159) >= (signed int)v159 ? LODWORD(v68) : v86[v84 + 1];
      v93 = v92 - v86[v84];
      v94 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v159->vfptr->Alloc)(
                                          v159,
                                          32i64);
      v163 = v94;
      if ( v94 )
      {
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImplCore::`vftable';
        v94->RefCount.Value = 1;
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImpl::`vftable';
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ShapeDataInterface,71>::`vftable';
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::Render::ShapeDataInterface::`vftable';
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ShapeDataBase::`vftable';
        v94->pLib = 0i64;
        LOBYTE(v94[1].vfptr) = 0;
        v94->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
      }
      else
      {
        v94 = 0i64;
      }
      v162 = v94;
      LOBYTE(v151) = 0;
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD, _QWORD, __int64, __int64))v94->vfptr[3].GetResourceReport)(
              v94,
              v167,
              LODWORD(pheapAddr.Size),
              v93,
              v151,
              v152) )
        break;
      v95 = v4->Glyphs.Data.Data;
      Scaleform::Render::RenderBuffer::AddRef(v94);
      v96 = (Scaleform::Render::RenderBuffer *)v95[v84].pObject;
      if ( v96 )
        Scaleform::RefCountImpl::Release(v96);
      v95[v84].pObject = (Scaleform::GFx::ShapeDataBase *)v94;
      if ( (_BYTE)v169 )
      {
        *(_OWORD *)&pheapAddr.Policy.Capacity = 0i64;
        Scaleform::GFx::ShapeDataBase::ComputeBound(
          (Scaleform::GFx::ShapeDataBase *)v94,
          (Scaleform::Render::Rect<float> *)&pheapAddr.Policy);
        v97 = v4->AdvanceTable.Data.Data;
        v98 = v157;
        v99 = *(float *)&pheapAddr.Policy.Capacity;
        if ( v157 < *(float *)&pheapAddr.Policy.Capacity
          || (v100 = v158,
              v101 = *((float *)&pheapAddr.Policy.Capacity + 1),
              v158 < *((float *)&pheapAddr.Policy.Capacity + 1)) )
        {
          *(_QWORD *)&v97[v85].Left = 0i64;
        }
        else
        {
          v97[v85].Left = (signed int)(float)(*(float *)&pheapAddr.Policy.Capacity * 20.0);
          v97[v85].Top = (signed int)(float)(v101 * 20.0);
          v97[v85].Width = (signed int)(float)((float)(v98 - v99) * 20.0);
          v97[v85].Height = (signed int)(float)((float)(v100 - v101) * 20.0);
        }
      }
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v94);
      ++LODWORD(v154.Policy.Capacity);
      ++HIDWORD(v159);
      ++v84;
      ++v85;
      v68 = v157;
      if ( v84 >= (signed int)v159 )
        goto LABEL_185;
    }
    v102 = SLODWORD(v154.Policy.Capacity);
    v103 = (Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy> *)&v4->AdvanceTable.Data.Data;
    if ( SLODWORD(v154.Policy.Capacity) >= v103->Size )
    {
      if ( SLODWORD(v154.Policy.Capacity) <= v103->Policy.Capacity )
        goto LABEL_178;
      v104 = SLODWORD(v154.Policy.Capacity) + ((unsigned __int64)SLODWORD(v154.Policy.Capacity) >> 2);
    }
    else
    {
      if ( SLODWORD(v154.Policy.Capacity) >= v103->Policy.Capacity >> 1 )
        goto LABEL_178;
      v104 = SLODWORD(v154.Policy.Capacity);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v103,
      v103,
      v104);
LABEL_178:
    v103->Size = v102;
    v105 = pheapAddr.Data;
    v106 = *((_QWORD *)pheapAddr.Data + 1);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *)pheapAddr.Data,
      pheapAddr.Data,
      v102);
    if ( v102 > v106 )
    {
      v107 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)(*(_QWORD *)v105 + 8 * v106);
      v168 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)(*(_QWORD *)v105 + 8 * v106);
      for ( j = v102 - v106; j; --j )
      {
        v167 = v107;
        if ( v107 )
          v107->Data = 0i64;
        v107 = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v107 + 8);
        v168 = v107;
      }
    }
    if ( v94 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v94);
    goto LABEL_191;
  }
LABEL_185:
  if ( (_DWORD)v155 + LODWORD(v157) == v5->Pos + v5->FilePos - v5->DataSize )
    goto LABEL_193;
LABEL_191:
  v168 = &v154;
LABEL_247:
  v40 = v154.Data;
LABEL_248:
  if ( v40 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, int *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v40);
}

// File Line: 586
// RVA: 0x8FC040
void __fastcall Scaleform::GFx::FontData::ReadFontInfo(Scaleform::GFx::FontData *this, Scaleform::GFx::Stream *in, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Stream *v3; // rdi
  Scaleform::GFx::TagType v4; // ebp
  Scaleform::GFx::FontData *v5; // rbx
  unsigned int v6; // eax
  __int64 v7; // rcx
  char v8; // si
  unsigned int v9; // eax
  __int64 v10; // rcx
  __int64 v11; // r14
  const char *v12; // rdx
  bool v13; // zf

  v3 = in;
  v4 = tagType;
  v5 = this;
  if ( this->Name )
  {
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v5->Name = 0i64;
  }
  v5->Name = Scaleform::GFx::Stream::ReadStringWithLength(v3, v3->FileName.pHeap);
  v6 = v3->DataSize;
  v3->UnusedBits = 0;
  if ( (signed int)(v6 - v3->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
  v7 = v3->Pos;
  v8 = v3->pBuffer[v7];
  v3->Pos = v7 + 1;
  if ( v4 == 62 )
  {
    v9 = v3->DataSize;
    v3->UnusedBits = 0;
    if ( (signed int)(v9 - (v7 + 1)) < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(v3, 1);
    v10 = v3->Pos;
    v11 = (unsigned __int8)v3->pBuffer[v10];
    v3->Pos = v10 + 1;
  }
  if ( v8 & 0x10 )
  {
    v5->Flags &= 0xFFFFFEFF;
    v5->Flags |= 0x200u;
  }
  else if ( v8 & 8 )
  {
    v5->Flags &= 0xFFFFFDFF;
    v5->Flags |= 0x100u;
  }
  else
  {
    v5->Flags &= 0xFFFFFCFF;
  }
  if ( v8 & 4 )
    v5->Flags |= 1u;
  else
    v5->Flags &= 0xFFFFFFFE;
  if ( v8 & 2 )
    v5->Flags |= 2u;
  else
    v5->Flags &= 0xFFFFFFFD;
  if ( v8 & 1 )
    v5->Flags |= 0x4000u;
  else
    v5->Flags &= 0xFFFFBFFF;
  if ( v3->ParseFlags & 1 )
  {
    v12 = "reading DefineFontInfo\n";
    if ( v4 != 13 )
      v12 = "reading DefineFontInfo2\n";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
      v12);
    v5->Name;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
      "  Name = %s\n");
    v5->Flags;
    v13 = (v5->Flags & 1) == 0;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
      "  CodePage = %s, Italic = %d, Bold = %d\n");
    if ( v4 == 62 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
        "  LangCode = %d\n");
  }
  Scaleform::GFx::FontData::ReadCodeTable(v5, v3);
}

// File Line: 643
// RVA: 0x8FAC90
void __fastcall Scaleform::GFx::FontData::ReadCodeTable(Scaleform::GFx::FontData *this, Scaleform::GFx::Stream *in)
{
  Scaleform::GFx::Stream *v2; // rbx
  Scaleform::GFx::FontData *v3; // rbp
  unsigned __int8 v4; // cf
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *v5; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v6; // rax
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // rax
  unsigned int v10; // eax
  unsigned __int64 v11; // rbp
  unsigned int v12; // eax
  __int64 v13; // r9
  unsigned __int16 v14; // r8
  unsigned int v15; // eax
  __int64 v16; // rdx
  unsigned int v17; // ecx
  Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeRef key; // [rsp+20h] [rbp-28h]
  __int16 v19; // [rsp+50h] [rbp+8h]
  unsigned __int16 v20; // [rsp+58h] [rbp+10h]

  v2 = in;
  v3 = this;
  v4 = __CFADD__(in->Pos, in->FilePos - in->DataSize);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&in->vfptr,
    "reading code table at offset %d\n");
  v5 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&v3->CodeTable.mHash.pTable;
  v6 = v3->CodeTable.mHash.pTable;
  v7 = 0i64;
  v8 = 5 * v3->Glyphs.Data.Size >> 2;
  if ( v6 )
    v9 = v6->EntryCount;
  else
    v9 = 0i64;
  if ( v8 > v9 )
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::setRawCapacity(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&v3->CodeTable.mHash.pTable,
      &v3->CodeTable,
      v8);
  v10 = v3->Flags;
  v11 = v3->Glyphs.Data.Size;
  if ( (v10 >> 14) & 1 )
  {
    if ( v11 )
    {
      key.pFirst = &v20;
      key.pSecond = (const unsigned __int16 *)&v19;
      do
      {
        v12 = v2->DataSize;
        v19 = v7;
        v2->UnusedBits = 0;
        if ( (signed int)(v12 - v2->Pos) < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(v2, 2);
        v13 = v2->Pos;
        v20 = (unsigned __int8)v2->pBuffer[v13] | (unsigned __int16)((unsigned __int8)v2->pBuffer[(unsigned int)(v13 + 1)] << 8);
        v14 = v20;
        v2->Pos = v13 + 2;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
          v5,
          v5,
          &key,
          v14);
        ++v7;
      }
      while ( v7 < v11 );
    }
  }
  else if ( v11 )
  {
    key.pFirst = &v20;
    key.pSecond = (const unsigned __int16 *)&v19;
    do
    {
      v15 = v2->DataSize;
      v19 = v7;
      v2->UnusedBits = 0;
      if ( (signed int)(v15 - v2->Pos) < 1 )
        Scaleform::GFx::Stream::PopulateBuffer(v2, 1);
      v16 = v2->Pos;
      v17 = (unsigned __int8)v2->pBuffer[v16];
      v20 = (unsigned __int8)v2->pBuffer[v16];
      v2->Pos = v16 + 1;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
        v5,
        v5,
        &key,
        v17);
      ++v7;
    }
    while ( v7 < v11 );
  }
}

// File Line: 664
// RVA: 0x8D96D0
signed __int64 __fastcall Scaleform::GFx::FontData::GetGlyphIndex(Scaleform::GFx::FontData *this, unsigned __int16 code)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v2; // r9
  unsigned __int64 v3; // r11
  unsigned __int64 v4; // r10
  signed __int64 v5; // r8
  signed __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 result; // rax

  v2 = this->CodeTable.mHash.pTable;
  if ( !v2 )
    goto LABEL_11;
  v3 = v2->SizeMask;
  v4 = v3 & code;
  v5 = v4;
  v6 = (signed __int64)&v2[v4 + 1];
  if ( *(_QWORD *)v6 == -2i64 || (v3 & *(_WORD *)(v6 + 8)) != v4 )
    goto LABEL_11;
  while ( (v3 & *(_WORD *)(v6 + 8)) != v4 || *(_WORD *)(v6 + 8) != code )
  {
    v5 = *(_QWORD *)v6;
    if ( *(_QWORD *)v6 == -1i64 )
      goto LABEL_11;
    v6 = (signed __int64)&v2[v5 + 1];
  }
  if ( v5 >= 0 && (v7 = (signed __int64)&v2[v5 + 1].SizeMask) != 0 )
    result = *(unsigned __int16 *)(v7 + 2);
  else
LABEL_11:
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 674
// RVA: 0x8D5E50
signed __int64 __fastcall Scaleform::GFx::FontData::GetCharValue(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v2; // r8
  unsigned __int64 v3; // rax
  unsigned int v4; // er10
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v5; // rcx
  unsigned __int64 v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // r8
  unsigned __int64 v10; // rdx
  _QWORD *v11; // rax
  __m128i v13; // [rsp+0h] [rbp-18h]

  v2 = &this->CodeTable;
  v3 = 0i64;
  v4 = glyphIndex;
  v5 = this->CodeTable.mHash.pTable;
  if ( v5 )
  {
    v6 = v5->SizeMask;
    v7 = v5 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v3;
      ++v7;
    }
    while ( v3 <= v6 );
    v13.m128i_i64[0] = (__int64)v2;
  }
  else
  {
    v13.m128i_i64[0] = 0i64;
  }
  v13.m128i_i64[1] = v3;
  _mm_store_si128(&v13, v13);
  v8 = v13.m128i_i64[1];
  while ( v13.m128i_i64[0] )
  {
    v9 = *(_QWORD *)v13.m128i_i64[0];
    if ( !*(_QWORD *)v13.m128i_i64[0] )
      break;
    v10 = *(_QWORD *)(v9 + 8);
    if ( v8 > (signed __int64)v10 )
      break;
    if ( *(unsigned __int16 *)(v9 + 16 * v8 + 26) == v4 )
      return *(unsigned __int16 *)(v9 + 16 * v8 + 24);
    if ( ++v8 <= v10 )
    {
      v11 = (_QWORD *)(v9 + 16 * (v8 + 1));
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v8;
        v11 += 2;
      }
      while ( v8 <= v10 );
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 685
// RVA: 0x8DC0E0
Scaleform::GFx::ShapeDataBase *__fastcall Scaleform::GFx::FontData::GetPermanentGlyphShape(Scaleform::GFx::FontData *this, unsigned int glyphIndex)
{
  Scaleform::GFx::ShapeDataBase *result; // rax

  if ( glyphIndex >= this->Glyphs.Data.Size )
    result = 0i64;
  else
    result = this->Glyphs.Data.Data[glyphIndex].pObject;
  return result;
}

// File Line: 693
// RVA: 0x8D4C50
float __fastcall Scaleform::GFx::FontData::GetAdvance(Scaleform::GFx::FontData *this, __int64 glyphIndex)
{
  Scaleform::GFx::FontData *v2; // r8
  unsigned __int64 v3; // rcx
  char v4; // cl
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  float result; // xmm0_4

  v2 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *, __int64, Scaleform::GFx::FontData *))this->vfptr[21].__vecDelDtor)(
      this,
      glyphIndex,
      this);
  }
  else
  {
    v3 = this->AdvanceTable.Data.Size;
    if ( v3 )
    {
      if ( (unsigned int)glyphIndex >= v3 )
        result = 0.0;
      else
        result = v2->AdvanceTable.Data.Data[(unsigned int)glyphIndex].Advance;
    }
    else
    {
      v4 = Logged;
      v5 = v2->vfptr;
      if ( !Logged )
        v4 = 1;
      Logged = v4;
      ((void (__fastcall *)(Scaleform::GFx::FontData *))v5[21].__vecDelDtor)(v2);
    }
  }
  return result;
}

// File Line: 724
// RVA: 0x8D9790
float __fastcall Scaleform::GFx::FontData::GetGlyphWidth(Scaleform::GFx::FontData *this, __int64 glyphIndex)
{
  float result; // xmm0_4

  if ( (_WORD)glyphIndex == -1 )
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
  unsigned __int64 v2; // rax
  float result; // xmm0_4

  if ( (_WORD)glyphIndex != -1 && (v2 = this->AdvanceTable.Data.Size) != 0 )
  {
    if ( (unsigned int)glyphIndex >= v2 )
      result = 0.0;
    else
      result = (float)this->AdvanceTable.Data.Data[(unsigned int)glyphIndex].Height * 0.050000001;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::FontData *, __int64, Scaleform::GFx::FontData *))this->vfptr[22].__vecDelDtor)(
      this,
      glyphIndex,
      this);
  }
  return result;
}

// File Line: 760
// RVA: 0x8D9380
Scaleform::Render::Rect<float> *__usercall Scaleform::GFx::FontData::GetGlyphBounds@<rax>(Scaleform::GFx::FontData *this@<rcx>, unsigned int glyphIndex@<edx>, Scaleform::Render::Rect<float> *prect@<r8>, float a4@<xmm0>)
{
  Scaleform::Render::Rect<float> *v4; // rbx
  unsigned int v5; // esi
  Scaleform::GFx::FontData *v6; // rdi
  float v7; // xmm0_4
  Scaleform::Render::Rect<float> *result; // rax
  Scaleform::GFx::FontData::AdvanceEntry *v9; // rcx
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  unsigned int v13; // eax
  __m128i v14; // xmm0
  Scaleform::GFx::ShapeDataBase *v15; // rcx
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-18h]

  v4 = prect;
  v5 = glyphIndex;
  v6 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    this->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)this, glyphIndex);
    v7 = a4 + v4->x1;
    v4->x2 = v7;
    v6->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v5);
    v4->y2 = v7 + v4->y1;
    return v4;
  }
  if ( glyphIndex >= this->AdvanceTable.Data.Size )
  {
    *(_QWORD *)&prect->x1 = 0i64;
    *(_QWORD *)&prect->x2 = 0i64;
    if ( glyphIndex >= this->Glyphs.Data.Size )
      return v4;
    v15 = this->Glyphs.Data.Data[glyphIndex].pObject;
    if ( !v15 )
      return v4;
    r = 0i64;
    Scaleform::GFx::ShapeDataBase::ComputeBound(v15, &r);
    v16 = r.x2;
    v17 = r.x1;
    if ( r.x2 < r.x1 )
      return v4;
    v18 = r.y2;
    v19 = r.y1;
    result = v4;
    if ( r.y2 >= r.y1 )
    {
      v4->x1 = r.x1;
      v4->x2 = (float)(v16 - v17) + v17;
      v4->y2 = (float)(v18 - v19) + v19;
      v4->y1 = v19;
    }
  }
  else
  {
    v9 = this->AdvanceTable.Data.Data;
    v10 = (float)v9[glyphIndex].Width * 0.050000001;
    if ( v10 == 0.0 )
      v10 = v9[glyphIndex].Advance;
    v11 = (float)v9[glyphIndex].Height;
    v12 = (float)v9[glyphIndex].Left * 0.050000001;
    prect->x1 = v12;
    v13 = v9[glyphIndex].Top;
    prect->x2 = v10 + v12;
    v14 = _mm_cvtsi32_si128(v13);
    result = prect;
    *(float *)v14.m128i_i32 = COERCE_FLOAT(_mm_cvtepi32_ps(v14)) * 0.050000001;
    LODWORD(prect->y1) = v14.m128i_i32[0];
    prect->y2 = (float)(v11 * 0.050000001) + *(float *)v14.m128i_i32;
  }
  return result;
}

// File Line: 822
// RVA: 0x8DA7E0
float __fastcall Scaleform::GFx::FontData::GetKerningAdjustment(Scaleform::GFx::FontData *this, unsigned int LastCode, unsigned int code)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeHashF> >::TableType *v3; // r10
  __int16 v4; // r11
  __int16 v5; // bx
  signed __int64 v6; // rcx
  signed __int64 v7; // r9
  __int64 v8; // rax
  signed __int64 v9; // rax
  unsigned __int64 v10; // r8
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  bool v13; // zf
  signed __int64 v14; // rcx
  signed __int64 v15; // rcx
  float result; // xmm0_4
  __int64 v17; // [rsp+8h] [rbp+8h]
  __int16 v18; // [rsp+10h] [rbp+10h]
  __int16 v19; // [rsp+12h] [rbp+12h]

  v3 = this->KerningPairs.mHash.pTable;
  v4 = code;
  v5 = LastCode;
  v18 = LastCode;
  v19 = code;
  if ( !v3 )
    goto LABEL_14;
  v6 = 5381i64;
  v7 = 4i64;
  do
  {
    v8 = *((unsigned __int8 *)&v17 + v7-- + 7);
    v9 = 65599 * v6 + v8;
    v6 = v9;
  }
  while ( v7 );
  v10 = v9 & v3->SizeMask;
  v11 = v10;
  v12 = v10 + 2 * (v10 + 1);
  v13 = *(&v3->EntryCount + v12) == -2i64;
  v14 = (signed __int64)v3 + 8 * v12;
  if ( v13 || *(_QWORD *)(v14 + 8) != v10 )
    goto LABEL_14;
  while ( *(_QWORD *)(v14 + 8) != v10 || *(_WORD *)(v14 + 16) != v5 || *(_WORD *)(v14 + 18) != v4 )
  {
    v11 = *(_QWORD *)v14;
    if ( *(_QWORD *)v14 == -1i64 )
      goto LABEL_14;
    v14 = (signed __int64)v3 + 8 * (v11 + 2 * (v11 + 1));
  }
  if ( v11 >= 0 && (v15 = (signed __int64)v3 + 8 * (v11 + 2 * (v11 + 2))) != 0 )
    result = *(float *)(v15 + 4);
  else
LABEL_14:
    result = 0.0;
  return result;
}

// File Line: 840
// RVA: 0x8B8590
Scaleform::String *__fastcall Scaleform::GFx::BuildStringFromRanges(Scaleform::String *result, Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *ranges)
{
  Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  Scaleform::String *v3; // r14
  int v4; // er15
  char v5; // r8
  unsigned __int16 v6; // bx
  unsigned __int64 v7; // rdi
  unsigned __int16 *v8; // rax
  signed __int64 v9; // r12
  int v10; // edx
  Scaleform::MsgFormat *v11; // rcx
  signed __int64 v12; // r12
  char *v13; // rcx
  char *v14; // rax
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rdx
  Scaleform::MemoryHeap *v17; // rcx
  Scaleform::Formatter *v18; // rax
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-E0h]
  int v21; // [rsp+38h] [rbp-C8h]
  __int64 v22; // [rsp+40h] [rbp-C0h]
  Scaleform::MsgFormat f; // [rsp+50h] [rbp-B0h]
  char putf8str; // [rsp+450h] [rbp+350h]
  Scaleform::MsgFormat v25; // [rsp+650h] [rbp+550h]
  unsigned __int16 v; // [rsp+A98h] [rbp+998h]
  char *v27; // [rsp+AA0h] [rbp+9A0h]

  v22 = -2i64;
  v2 = ranges;
  v3 = result;
  Scaleform::String::String(result);
  v21 = 1;
  v4 = 0;
  v5 = 1;
  v6 = 0;
  v = 0;
  v7 = 0i64;
  if ( v2->Data.Size <= 0 )
    return v3;
  do
  {
    v8 = &v2->Data.Data->start;
    if ( v7 )
    {
      v9 = (signed __int64)&v8[2 * v7];
      v10 = *(unsigned __int16 *)(v9 - 2);
      if ( v8[2 * v7] <= v10 + 1 )
        goto LABEL_13;
      r.Type = 2;
      r.SinkData.DataPtr.Size = 512i64;
      r.SinkData.pStr = (Scaleform::String *)&putf8str;
      if ( v6 == (_WORD)v10 )
      {
        Scaleform::MsgFormat::MsgFormat(&v25, &r);
        Scaleform::MsgFormat::Parse(&v25, "0x{0:x}");
        Scaleform::MsgFormat::FormatD1<unsigned short>(&v25, &v);
        Scaleform::MsgFormat::FinishFormatD(&v25);
        v11 = &v25;
      }
      else
      {
        Scaleform::MsgFormat::MsgFormat(&f, &r);
        Scaleform::MsgFormat::Parse(&f, "0x{0:x}-0x{1:x}");
        Scaleform::MsgFormat::FormatD1<unsigned short>(&f, &v);
        Scaleform::MsgFormat::FormatD1<unsigned short>(&f, (const unsigned __int16 *)(v9 - 2));
        Scaleform::MsgFormat::FinishFormatD(&f);
        v11 = &f;
      }
      Scaleform::MsgFormat::~MsgFormat(v11);
      if ( v4 )
        Scaleform::String::AppendString(v3, ", ", -1i64);
      Scaleform::String::AppendString(v3, &putf8str, -1i64);
      if ( ++v4 > 4 )
        goto LABEL_32;
      v6 = v2->Data.Data[v7].start;
    }
    else
    {
      v6 = *v8;
    }
    v5 = 0;
    v = v6;
LABEL_13:
    ++v7;
  }
  while ( v7 < v2->Data.Size );
  if ( !v5 )
  {
    r.Type = 2;
    r.SinkData.pStr = (Scaleform::String *)&putf8str;
    r.SinkData.DataPtr.Size = 512i64;
    v12 = (signed __int64)&v2->Data.Data[v2->Data.Size];
    Scaleform::MsgFormat::MsgFormat(&f, &r);
    Scaleform::MsgFormat::Parse(&f, "0x{0:x}-0x{1:x}");
    if ( Scaleform::MsgFormat::NextFormatter(&f) )
    {
      *(_QWORD *)&v = (char *)&f + 480;
      do
      {
        if ( f.MemPool.BuffSize < 0x60 )
        {
          v17 = f.MemPool.pHeap;
          if ( !f.MemPool.pHeap )
            v17 = Scaleform::Memory::pGlobalHeap;
          v13 = (char *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v17->vfptr->Alloc)(
                          v17,
                          96i64,
                          8i64);
        }
        else
        {
          v13 = f.MemPool.BuffPtr;
          v14 = (char *)(((_QWORD)(f.MemPool.BuffPtr + 95) & 0xFFFFFFFFFFFFFFF8ui64) + 8);
          f.MemPool.BuffPtr = v14;
          v15 = v14 - (char *)&f.MemPool - 8;
          if ( v15 >= 0x200 )
            v16 = 0i64;
          else
            v16 = 512 - v15;
          f.MemPool.BuffSize = v16;
        }
        v27 = v13;
        if ( v13 )
          Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)v13, &f, v6);
        else
          v18 = 0i64;
        Scaleform::MsgFormat::Bind(&f, v18, 1);
      }
      while ( Scaleform::MsgFormat::NextFormatter(&f) );
    }
    ++f.FirstArgNum;
    Scaleform::MsgFormat::FormatD1<unsigned short>(&f, (const unsigned __int16 *)(v12 - 2));
    Scaleform::MsgFormat::FinishFormatD(&f);
    Scaleform::MsgFormat::~MsgFormat(&f);
    if ( v4 )
      Scaleform::String::AppendString(v3, ", ", -1i64);
    Scaleform::String::AppendString(v3, &putf8str, -1i64);
  }
LABEL_32:
  if ( v7 < v2->Data.Size )
    Scaleform::String::AppendString(v3, " (truncated)", -1i64);
  return v3;
}

// File Line: 886
// RVA: 0x8D5BC0
Scaleform::String *__fastcall Scaleform::GFx::FontData::GetCharRanges(Scaleform::GFx::FontData *this, Scaleform::String *result)
{
  Scaleform::String *v2; // r12
  __int16 v3; // si
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v4; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v5; // rdx
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v7; // rcx
  unsigned __int16 v8; // r14
  __int64 v9; // rbx
  __int64 *v10; // r15
  unsigned __int64 v11; // r8
  char v12; // r11
  __int64 v13; // r9
  unsigned __int64 v14; // rdx
  int v15; // er10
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  int *v18; // rcx
  _QWORD *v19; // rax
  unsigned __int64 v20; // rbx
  unsigned __int64 v21; // r8
  int *v22; // rcx
  __m128i v24; // [rsp+30h] [rbp-30h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+40h] [rbp-20h]
  int v26; // [rsp+90h] [rbp+30h]
  int v27; // [rsp+90h] [rbp+30h]

  v2 = result;
  v3 = 0;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  v4 = &this->CodeTable;
  v5 = this->CodeTable.mHash.pTable;
  if ( v5 )
  {
    v6 = 0i64;
    v7 = v5 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v6;
      ++v7;
    }
    while ( v6 <= v5->SizeMask );
    v24.m128i_i64[0] = (__int64)v4;
    v24.m128i_i64[1] = v6;
  }
  else
  {
    v24 = 0ui64;
  }
  _mm_store_si128(&v24, v24);
  v8 = 0;
  v9 = v24.m128i_i64[1];
  v10 = (__int64 *)v24.m128i_i64[0];
LABEL_8:
  v11 = pheapAddr.Size;
LABEL_9:
  v12 = 0;
  while ( v10 )
  {
    v13 = *v10;
    if ( !*v10 )
      break;
    v14 = *(_QWORD *)(v13 + 8);
    if ( v9 > (signed __int64)v14 )
      break;
    if ( v12 )
    {
      v15 = *(unsigned __int16 *)(v13 + 16 * v9 + 24);
      if ( v8 != v15 - 1 )
      {
        LOWORD(v26) = v3;
        HIWORD(v26) = v8;
        v16 = v11 + 1;
        if ( v11 + 1 >= v11 )
        {
          if ( v16 > pheapAddr.Policy.Capacity )
          {
            v17 = v16 + (v16 >> 2);
LABEL_21:
            Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v17);
          }
        }
        else if ( v16 < pheapAddr.Policy.Capacity >> 1 )
        {
          v17 = v11 + 1;
          goto LABEL_21;
        }
        v11 = v16;
        pheapAddr.Size = v16;
        v18 = &pheapAddr.Data[v16 - 1];
        if ( !v18 )
          goto LABEL_9;
        *v18 = v26;
        goto LABEL_8;
      }
    }
    else
    {
      LOWORD(v15) = *(_WORD *)(v13 + 16 * v9 + 24);
      v3 = *(_WORD *)(v13 + 16 * v9 + 24);
      v12 = 1;
    }
    v8 = v15;
    if ( ++v9 <= v14 )
    {
      v19 = (_QWORD *)(v13 + 16 * (v9 + 1));
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v9;
        v19 += 2;
      }
      while ( v9 <= v14 );
    }
  }
  if ( v12 )
  {
    LOWORD(v27) = v3;
    HIWORD(v27) = v8;
    v20 = v11 + 1;
    if ( v11 + 1 >= v11 )
    {
      if ( v20 <= pheapAddr.Policy.Capacity )
        goto LABEL_36;
      v21 = v20 + (v20 >> 2);
    }
    else
    {
      if ( v20 >= pheapAddr.Policy.Capacity >> 1 )
        goto LABEL_36;
      v21 = v11 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::`anonymous namespace'::Range,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>,AllocatorGH<Scaleform::GFx::`anonymous namespace'::Range,2>::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v21);
LABEL_36:
    v11 = v20;
    pheapAddr.Size = v20;
    v22 = &pheapAddr.Data[v20 - 1];
    if ( v22 )
    {
      *v22 = v27;
      v11 = pheapAddr.Size;
    }
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,ArrayDefaultPolicy::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0i64,
    v11,
    0);
  Scaleform::GFx::BuildStringFromRanges(
    v2,
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr);
  if ( pheapAddr.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, int *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      pheapAddr.Data);
  return v2;
}

// File Line: 1573
// RVA: 0x919760
void __fastcall Scaleform::GFx::TextureGlyphBinder::Visit(Scaleform::GFx::TextureGlyphBinder *this, unsigned int __formal, Scaleform::Render::TextureGlyph *ptextureGlyph)
{
  Scaleform::Render::TextureGlyph *v3; // rdi
  unsigned int v4; // er8
  Scaleform::GFx::ResourceBinding *v5; // r9
  signed __int64 v6; // rdx
  Scaleform::GFx::Resource *v7; // rbx
  Scaleform::Render::Image *v8; // rsi
  Scaleform::Render::Image *v9; // rcx
  Scaleform::GFx::Resource *v10; // rbx
  Scaleform::GFx::ResourceLibBase *v11; // rcx
  Scaleform::GFx::ResourceBindData pdata; // [rsp+28h] [rbp-20h]

  v3 = ptextureGlyph;
  if ( !ptextureGlyph->pImage.pObject && ptextureGlyph->BindIndex != -1 )
  {
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    v4 = ptextureGlyph->BindIndex;
    v5 = this->ResBinding;
    if ( v5->Frozen && v4 < v5->ResourceCount )
    {
      v6 = (signed __int64)&v5->pResources[v4];
      if ( *(_QWORD *)v6 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)v6 + 8i64), 1u);
      v7 = *(Scaleform::GFx::Resource **)v6;
      pdata.pResource.pObject = *(Scaleform::GFx::Resource **)v6;
      pdata.pBinding = *(Scaleform::GFx::ResourceBinding **)(v6 + 8);
    }
    else
    {
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(this->ResBinding, &pdata, v4);
      v7 = pdata.pResource.pObject;
    }
    if ( v7 && (v7->vfptr->GetResourceTypeCode(v7) & 0xFF00) == 256 )
    {
      v8 = (Scaleform::Render::Image *)v7[1].vfptr;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::GFx::ResourceVtbl *))v8->vfptr[1].__vecDelDtor)(v7[1].vfptr);
      v9 = v3->pImage.pObject;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::Render::Image *))v9->vfptr[2].__vecDelDtor)(v9);
      v3->pImage.pObject = v8;
      v3->BindIndex = -1;
    }
    if ( v7 && !_InterlockedDecrement(&v7->RefCount.Value) )
    {
      v10 = pdata.pResource.pObject;
      v11 = pdata.pResource.pObject->pLib;
      if ( v11 )
      {
        v11->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, (unsigned int)pdata.pResource.pObject);
        v10->pLib = 0i64;
      }
      v10->vfptr->__vecDelDtor(v10, 1u);
    }
  }
}

// File Line: 1594
// RVA: 0x896560
void __fastcall Scaleform::GFx::FontDataBound::FontDataBound(Scaleform::GFx::FontDataBound *this, Scaleform::Render::Font *pfont, Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::GFx::ResourceBinding *v3; // rbp
  Scaleform::Render::Font *v4; // rbx
  Scaleform::GFx::FontDataBound *v5; // rsi
  Scaleform::Render::FontCacheHandleManager *volatile v6; // rt1
  unsigned __int64 v7; // rdi
  Scaleform::Render::FontCacheHandleManager *volatile v8; // rax
  Scaleform::GFx::TextureGlyphData *v9; // rbx
  Scaleform::GFx::TextureGlyphData *v10; // rax
  Scaleform::GFx::TextureGlyphData *v11; // rax
  Scaleform::GFx::TextureGlyphData *v12; // rbx
  Scaleform::RefCountNTSImpl *v13; // rcx
  Scaleform::GFx::TextureGlyphData *v14; // rbp
  unsigned __int64 v15; // r14
  __int64 v16; // rbx
  void **v17; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ResourceBinding *v18; // [rsp+30h] [rbp-38h]
  int v19; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::TextureGlyphData *v20; // [rsp+80h] [rbp+18h]

  v3 = pbinding;
  v4 = pfont;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  this->Ascent = pfont->Ascent;
  this->Descent = pfont->Descent;
  this->Leading = pfont->Leading;
  this->Flags = pfont->Flags;
  this->LowerCaseTop = pfont->LowerCaseTop;
  this->UpperCaseTop = pfont->UpperCaseTop;
  v6 = this->hRef.pManager.Value;
  v7 = 0i64;
  this->hRef.pManager.Value = 0i64;
  v8 = this->hRef.pManager.Value;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontDataBound::`vftable';
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfont);
  v5->pFont.pObject = v4;
  v5->pTGData.pObject = 0i64;
  v9 = (Scaleform::GFx::TextureGlyphData *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v4->vfptr[11].__vecDelDtor)(v4);
  v19 = 261;
  v10 = (Scaleform::GFx::TextureGlyphData *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::FontDataBound *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              v5,
                                              72i64,
                                              &v19,
                                              -2i64);
  v20 = v10;
  if ( v10 )
  {
    Scaleform::GFx::TextureGlyphData::TextureGlyphData(v10, v9);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (Scaleform::RefCountNTSImpl *)&v5->pTGData.pObject->vfptr;
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
  v5->pTGData.pObject = v12;
  v17 = &Scaleform::GFx::TextureGlyphBinder::`vftable';
  v18 = v3;
  v14 = v5->pTGData.pObject;
  v15 = v14->TextureGlyphs.Data.Size;
  if ( v15 )
  {
    v16 = 0i64;
    do
    {
      ((void (__fastcall *)(void ***, _QWORD, Scaleform::Render::TextureGlyph *))v17[1])(
        &v17,
        (unsigned int)v7++,
        &v14->TextureGlyphs.Data.Data[v16]);
      ++v16;
    }
    while ( v7 < v15 );
  }
}

// File Line: 1616
// RVA: 0x896DD0
void __fastcall Scaleform::GFx::FontResource::FontResource(Scaleform::GFx::FontResource *this, Scaleform::Render::Font *pfont, Scaleform::GFx::ResourceBinding *pbinding)
{
  Scaleform::Render::Font *v3; // rdi
  Scaleform::GFx::FontResource *v4; // rbx
  volatile int v5; // et1
  __int64 v6; // rax
  Scaleform::Render::RenderBuffer *v7; // rcx

  v3 = pfont;
  v4 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable';
  v5 = this->RefCount.Value;
  v6 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::FontResource::`vftable';
  this->pFont.pObject = 0i64;
  this->pBinding = pbinding;
  this->FontKey.pKeyInterface = 0i64;
  this->FontKey.hKeyData = 0i64;
  if ( pfont )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfont);
  v7 = (Scaleform::Render::RenderBuffer *)v4->pFont.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v4->pFont.pObject = v3;
  *(_DWORD *)&v4->LowerCaseTop = 0;
}

// File Line: 1624
// RVA: 0x896D00
void __fastcall Scaleform::GFx::FontResource::FontResource(Scaleform::GFx::FontResource *this, Scaleform::Render::Font *pfont, Scaleform::GFx::ResourceKey *key)
{
  Scaleform::GFx::ResourceKey *v3; // rdi
  Scaleform::Render::Font *v4; // rsi
  Scaleform::GFx::FontResource *v5; // rbx
  volatile int v6; // et1
  __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v9; // rcx

  v3 = key;
  v4 = pfont;
  v5 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable';
  v6 = this->RefCount.Value;
  v7 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::FontResource::`vftable';
  this->pFont.pObject = 0i64;
  this->pBinding = 0i64;
  this->FontKey.pKeyInterface = 0i64;
  this->FontKey.hKeyData = 0i64;
  if ( pfont )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfont);
  v8 = (Scaleform::Render::RenderBuffer *)v5->pFont.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v5->pFont.pObject = v4;
  if ( v3->pKeyInterface )
    v3->pKeyInterface->vfptr->AddRef(v3->pKeyInterface, v3->hKeyData);
  v9 = v5->FontKey.pKeyInterface;
  if ( v9 )
    v9->vfptr->Release(v9, v5->FontKey.hKeyData);
  v5->FontKey.pKeyInterface = v3->pKeyInterface;
  v5->FontKey.hKeyData = v3->hKeyData;
  *(_DWORD *)&v5->LowerCaseTop = 0;
}

// File Line: 1726
// RVA: 0x897070
void __fastcall Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(Scaleform::GFx::GFxSystemFontResourceKey *this, const char *pname, unsigned int fontFlags, Scaleform::GFx::FontProvider *pfontProvider)
{
  Scaleform::GFx::Resource *v4; // rbp
  char v5; // r14
  const char *v6; // rdi
  Scaleform::GFx::GFxSystemFontResourceKey *v7; // rsi
  Scaleform::String *v8; // rax
  Scaleform::String *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::String v11; // [rsp+20h] [rbp-28h]
  __int64 v12; // [rsp+28h] [rbp-20h]
  Scaleform::String result; // [rsp+68h] [rbp+20h]

  v12 = -2i64;
  v4 = (Scaleform::GFx::Resource *)pfontProvider;
  v5 = fontFlags;
  v6 = pname;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,261>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::GFxSystemFontResourceKey,261>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::GFxSystemFontResourceKey::`vftable';
  this->pFontProvider.pObject = 0i64;
  Scaleform::String::String(&this->FontName);
  Scaleform::String::String(&v11, v6);
  v9 = Scaleform::String::ToLower(v8, &result);
  Scaleform::String::operator=(&v7->FontName, v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v7->CreateFontFlags = v5 & 3;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef(v4);
  v10 = (Scaleform::Render::RenderBuffer *)v7->pFontProvider.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v7->pFontProvider.pObject = (Scaleform::GFx::FontProvider *)v4;
}

// File Line: 1765
// RVA: 0x8D98C0
unsigned __int64 __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::GetHashCode(Scaleform::GFx::GFxSystemFontResourceKeyInterface *this, void *hdata)
{
  return Scaleform::String::BernsteinHashFunctionCIS(
           (const void *)((*((_QWORD *)hdata + 3) & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(*((_QWORD *)hdata + 3) & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ *((_QWORD *)hdata + 2) ^ (*((_QWORD *)hdata + 2) >> 7) ^ *((unsigned int *)hdata + 8);
}

// File Line: 1772
// RVA: 0x159C2A0
__int64 Scaleform::GFx::_dynamic_initializer_for__GFxSystemFontResourceKeyInterface_Instance__()
{
  GFxSystemFontResourceKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::GFxSystemFontResourceKeyInterface::`vftable';
  return atexit(Scaleform::GFx::_dynamic_atexit_destructor_for__GFxSystemFontResourceKeyInterface_Instance__);
}

// File Line: 1775
// RVA: 0x8E7FB0
bool __fastcall Scaleform::GFx::GFxSystemFontResourceKeyInterface::KeyEquals(Scaleform::GFx::GFxSystemFontResourceKeyInterface *this, void *hdata, Scaleform::GFx::ResourceKey *other)
{
  _QWORD *v3; // r9
  _QWORD *v5; // r10
  unsigned __int8 *v6; // rax
  unsigned __int64 v7; // r8
  int v8; // ecx
  int v9; // edx

  v3 = hdata;
  if ( this != (Scaleform::GFx::GFxSystemFontResourceKeyInterface *)other->pKeyInterface )
    return 0;
  v5 = other->hKeyData;
  v6 = (unsigned __int8 *)((*((_QWORD *)hdata + 3) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v7 = (v5[3] & 0xFFFFFFFFFFFFFFFCui64) - (*((_QWORD *)hdata + 3) & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v8 = v6[v7];
    v9 = *v6 - v8;
    if ( *v6 != v8 )
      break;
    ++v6;
  }
  while ( v8 );
  return !v9 && v3[2] == v5[2] && *((_DWORD *)v3 + 8) == *((_DWORD *)v5 + 8);
}

// File Line: 1788
// RVA: 0x8BFC90
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::FontResource::CreateFontResourceKey(Scaleform::GFx::ResourceKey *result, const char *pname, unsigned int fontFlags, Scaleform::GFx::FontProvider *pfontProvider)
{
  Scaleform::GFx::FontProvider *v4; // rsi
  unsigned int v5; // ebp
  const char *v6; // r14
  Scaleform::GFx::ResourceKey *v7; // rdi
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::GFx::GFxSystemFontResourceKey *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  v4 = pfontProvider;
  v5 = fontFlags;
  v6 = pname;
  v7 = result;
  v8 = 0i64;
  v9 = (Scaleform::GFx::GFxSystemFontResourceKey *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     40ui64,
                                                     0i64);
  if ( v9 )
  {
    Scaleform::GFx::GFxSystemFontResourceKey::GFxSystemFontResourceKey(v9, v6, v5, v4);
    v8 = v10;
  }
  GFxSystemFontResourceKeyInterface_Instance.vfptr->AddRef(
    (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxSystemFontResourceKeyInterface_Instance,
    v8);
  v7->pKeyInterface = (Scaleform::GFx::ResourceKey::KeyInterface *)&GFxSystemFontResourceKeyInterface_Instance;
  v7->hKeyData = v8;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return v7;
}

// File Line: 1802
// RVA: 0x8BFAC0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::FontResource::CreateFontResource(const char *pname, unsigned int fontFlags, Scaleform::GFx::FontProvider *pprovider, Scaleform::GFx::ResourceWeakLib *plib)
{
  Scaleform::GFx::ResourceWeakLib *v4; // rbx
  Scaleform::GFx::FontProvider *v5; // rdi
  unsigned int v6; // ebp
  const char *v7; // r14
  Scaleform::GFx::Resource *v8; // rsi
  Scaleform::Render::Font *v9; // rbp
  Scaleform::GFx::FontResource *v10; // rax
  Scaleform::GFx::Resource *v11; // rax
  Scaleform::GFx::Resource *v12; // rdi
  _RTL_CRITICAL_SECTION *v13; // rbx
  Scaleform::GFx::Resource *v14; // rbx
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ResourceKey k; // [rsp+48h] [rbp-20h]

  v4 = plib;
  v5 = pprovider;
  v6 = fontFlags;
  v7 = pname;
  Scaleform::GFx::FontResource::CreateFontResourceKey(&k, pname, fontFlags, pprovider);
  phandle.State = 0;
  phandle.pResource = 0i64;
  v8 = 0i64;
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(v4, &phandle, &k) == 3 )
  {
    v9 = (Scaleform::Render::Font *)((__int64 (__fastcall *)(Scaleform::GFx::FontProvider *, const char *, _QWORD))v5->vfptr[1].__vecDelDtor)(
                                      v5,
                                      v7,
                                      v6);
    if ( v9
      && ((v10 = (Scaleform::GFx::FontResource *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   64ui64,
                                                   0i64)) == 0i64 ? (v8 = 0i64) : (Scaleform::GFx::FontResource::FontResource(
                                                                                     v10,
                                                                                     v9,
                                                                                     &k),
                                                                                   v8 = v11),
          v8) )
    {
      v12 = phandle.pResource;
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v8);
    }
    else
    {
      v12 = phandle.pResource;
      v13 = (_RTL_CRITICAL_SECTION *)&phandle.pResource->pLib[1].RefCount;
      EnterCriticalSection(v13);
      LODWORD(v12[1].vfptr) = 2;
      Scaleform::String::operator=((Scaleform::String *)&v12[2].RefCount, &customWorldMapCaption);
      Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
        (Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp> > *)&v12->pLib[4],
        (Scaleform::GFx::ResourceKey *)&v12[1].pLib);
      Scaleform::Event::SetEvent((Scaleform::Event *)&v12[2].pLib);
      LeaveCriticalSection(v13);
    }
    if ( v9 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v9);
  }
  else
  {
    v8 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    v12 = phandle.pResource;
  }
  if ( phandle.State == 1 )
  {
    if ( !_InterlockedDecrement(&v12->RefCount.Value) )
    {
      v14 = phandle.pResource;
      v15 = phandle.pResource->pLib;
      if ( v15 )
      {
        v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)phandle.pResource);
        v14->pLib = 0i64;
      }
      v14->vfptr->__vecDelDtor(v14, 1u);
    }
  }
  else if ( phandle.State >= 2 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v12);
  }
  if ( k.pKeyInterface )
    k.pKeyInterface->vfptr->Release(k.pKeyInterface, k.hKeyData);
  return v8;
}

// File Line: 1838
// RVA: 0x9041C0
void __fastcall Scaleform::GFx::FontResource::ResolveTextureGlyphs(Scaleform::GFx::FontResource *this)
{
  Scaleform::GFx::FontResource *v1; // rbx
  Scaleform::GFx::FontDataBound *v2; // rax
  Scaleform::Render::Font *v3; // rax
  Scaleform::Render::Font *v4; // rdi
  Scaleform::Render::RenderBuffer *v5; // rcx
  int v6; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::FontDataBound *v7; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( ((__int64 (__cdecl *)(Scaleform::Render::Font *))this->pFont.pObject->vfptr[11].__vecDelDtor)(this->pFont.pObject) )
  {
    v6 = 75;
    v2 = (Scaleform::GFx::FontDataBound *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            v1,
                                            72ui64,
                                            (Scaleform::AllocInfo *)&v6);
    v7 = v2;
    if ( v2 )
    {
      Scaleform::GFx::FontDataBound::FontDataBound(v2, v1->pFont.pObject, v1->pBinding);
      v4 = v3;
    }
    else
    {
      v4 = 0i64;
    }
    v5 = (Scaleform::Render::RenderBuffer *)v1->pFont.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    v1->pFont.pObject = v4;
  }
}

