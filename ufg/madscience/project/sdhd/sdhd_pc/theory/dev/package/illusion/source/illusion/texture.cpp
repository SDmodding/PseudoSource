// File Line: 39
// RVA: 0x927C0
void __fastcall Illusion::Texture::HandleUpdated(UFG::qResourceFileHandle *handle, bool bound, void *callback_data)
{
  if ( handle->mData )
  {
    JUMPOUT(bound, 1, _);
    _((AMD_HD3D *)callback_data);
  }
}

// File Line: 100
// RVA: 0x94530
void __fastcall HandleDamageTrack::ResolveReferences(Illusion::Texture *this)
{
  _((AMD_HD3D *)this);
}

// File Line: 106
// RVA: 0x92680
__int64 __fastcall Illusion::Texture::GetSamplerAddressFlags(Illusion::Texture *this)
{
  return this->mFlags & 0xF;
}

// File Line: 111
// RVA: 0x958D0
void __fastcall Illusion::Texture::SetSamplerFilter(Illusion::Texture *this, unsigned int filter)
{
  this->mFilter = filter;
  Illusion::ITexturePlat::OnSetSampler((Illusion::ITexturePlat *)this);
}

// File Line: 117
// RVA: 0x958C0
void __fastcall Illusion::Texture::SetSamplerAddressFlags(Illusion::Texture *this, unsigned int flags)
{
  this->mFlags &= 0xFFFFFFF0;
  this->mFlags |= flags;
  Illusion::ITexturePlat::OnSetSampler((Illusion::ITexturePlat *)this);
}

// File Line: 123
// RVA: 0x958E0
void __fastcall Illusion::Texture::SetSamplerState(Illusion::Texture *this, unsigned int filter, unsigned int flags)
{
  this->mFlags &= 0xFFFFFFF0;
  this->mFlags |= flags;
  this->mFilter = filter;
  Illusion::ITexturePlat::OnSetSampler((Illusion::ITexturePlat *)this);
}

// File Line: 130
// RVA: 0x95A90
void __fastcall Illusion::Texture::SwitchAliasTexture(Illusion::Texture *this, Illusion::Texture *new_alias_texture)
{
  this->mImageDataPosition = (unsigned __int64)new_alias_texture;
  Illusion::ITexturePlat::SwitchAliasTexture((Illusion::ITexturePlat *)this, new_alias_texture);
}

// File Line: 156
// RVA: 0x14582B0
__int64 Illusion::_dynamic_initializer_for__gTextureInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gTextureInventory.vfptr,
    "iTextureInventory",
    0x8B43FABF,
    0xCDBFA090,
    0x3218EEB7u,
    0x100u);
  Illusion::gTextureInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iTextureInventory::`vftable;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gTextureInventory__);
}

// File Line: 166
// RVA: 0x8E010
void __fastcall Illusion::iTextureInventory::Add(Illusion::iTextureInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::TexturePlat *v2; // rbx
  Illusion::iTextureInventory *v3; // rdi
  __int64 v4; // rax
  Illusion::TextureUser *v5; // rcx

  v2 = (Illusion::TexturePlat *)resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v2->mPadding[48]);
  }
  Illusion::ITexturePlat::OnLoad((Illusion::ITexturePlat *)v2);
  v4 = *(_QWORD *)&v2->mPadding[8];
  if ( v4 )
    v5 = (Illusion::TextureUser *)&v2->mPadding[v4 + 8];
  else
    v5 = 0i64;
  Illusion::TextureUser::OnLoad(v5, (Illusion::Texture *)v2);
  LODWORD(v2->mTextureD3DResourceHandle.mData) |= 0x2000u;
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)v2);
}

// File Line: 181
// RVA: 0x94A40
void __fastcall Illusion::iTextureInventory::Remove(Illusion::iTextureInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  __int64 v3; // rax
  Illusion::TextureUser *v4; // rcx

  v2 = resource_data;
  if ( (_QWORD)resource_data[1].mNode.mParent & 0x2000 )
  {
    UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
    Illusion::ITexturePlat::OnUnload((Illusion::ITexturePlat *)v2);
    v3 = *(_QWORD *)&v2[1].mNode.mUID;
    if ( v3 )
      v4 = (Illusion::TextureUser *)((char *)&v2[1].mNode.mUID + v3);
    else
      v4 = 0i64;
    Illusion::TextureUser::OnUnload(v4);
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2[1].mDebugName[12]);
    LODWORD(v2[1].mNode.mParent) &= 0xFFFFDFFF;
  }
}

// File Line: 201
// RVA: 0x941C0
void __fastcall Illusion::iTextureInventory::OnPreMove(Illusion::iTextureInventory *this, UFG::qResourceData *resourceData)
{
  Illusion::ITexturePlat::OnPreMove((Illusion::ITexturePlat *)resourceData);
}

// File Line: 208
// RVA: 0x941B0
void __fastcall Illusion::iTextureInventory::OnPostMove(Illusion::iTextureInventory *this, UFG::qResourceData *resourceData)
{
  Illusion::ITexturePlat::OnPostMove((Illusion::ITexturePlat *)resourceData);
}

// File Line: 231
// RVA: 0x92AF0
UFG::qResourceData *__fastcall Illusion::InternalCreateTexture(const char *name, int width, int height, int depth, Illusion::Texture::Format format, unsigned int flags, int num_mips, unsigned int type, unsigned int esram_offset, unsigned int esram_usage_bytes)
{
  __int16 v10; // di
  __int16 v11; // bp
  __int16 v12; // si
  const char *v13; // rbx
  unsigned int v14; // eax
  UFG::qResourceData *v15; // rax
  UFG::qResourceData *v16; // rbx
  UFG::qResourceWarehouse *v17; // rax

  v10 = width;
  v11 = depth;
  v12 = height;
  v13 = name;
  v14 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v15 = Illusion::Factory::NewTexture(v13, v14, 0i64, 0i64, 0i64);
  BYTE4(v15[1].mNode.mParent) = format;
  v16 = v15;
  BYTE1(v15[1].mNode.mChild[1]) = 1;
  WORD2(v15[1].mNode.mChild[0]) = v10;
  LODWORD(v15[1].mNode.mParent) = flags | 0x4003;
  HIWORD(v15[1].mNode.mChild[0]) = v12;
  BYTE5(v15[1].mNode.mParent) = type;
  WORD1(v15[1].mNode.mChild[1]) = v11;
  LOBYTE(v15[1].mNode.mChild[1]) = num_mips;
  HIDWORD(v15[1].mNode.mChild[1]) = 662883558;
  v15[1].mResourceHandles.mNode.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)esram_offset;
  LODWORD(v15[1].mResourceHandles.mNode.mPrev) = esram_usage_bytes;
  LODWORD(v15[2].mNode.mParent) = 0;
  Illusion::ITexturePlat::CreateTextureData((Illusion::ITexturePlat *)v15);
  v17 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v17, v16);
  return v16;
}

// File Line: 267
// RVA: 0x8EC20
UFG::qResourceData *__fastcall Illusion::CreateTexture(const char *name, int width, int height, Illusion::Texture::Format format, unsigned int flags, int num_mips, unsigned int esram_offset, unsigned int esram_usage_bytes)
{
  return Illusion::InternalCreateTexture(
           name,
           width,
           height,
           1,
           format,
           flags,
           num_mips,
           0,
           esram_offset,
           esram_usage_bytes);
}

// File Line: 280
// RVA: 0x8EBD0
UFG::qResourceData *__fastcall Illusion::CreateTexture3D(const char *name, int width, int height, int depth, Illusion::Texture::Format format, unsigned int flags, int num_mips, unsigned int esram_offset, unsigned int esram_usage_bytes)
{
  return Illusion::InternalCreateTexture(
           name,
           width,
           height,
           depth,
           format,
           flags,
           num_mips,
           1u,
           esram_offset,
           esram_usage_bytes);
}

// File Line: 292
// RVA: 0x8ED50
UFG::qResourceData *__fastcall Illusion::CreateTextureCube(const char *name, int width, int height, Illusion::Texture::Format format, unsigned int flags, int num_mips, unsigned int esram_offset, unsigned int esram_usage_bytes)
{
  return Illusion::InternalCreateTexture(
           name,
           width,
           height,
           1,
           format,
           flags,
           num_mips,
           2u,
           esram_offset,
           esram_usage_bytes);
}

// File Line: 305
// RVA: 0x8EB80
UFG::qResourceData *__fastcall Illusion::CreateTexture2DArray(const char *name, int width, int height, int array_size, Illusion::Texture::Format format, unsigned int flags, int num_mips, unsigned int esram_offset, unsigned int esram_usage_bytes)
{
  return Illusion::InternalCreateTexture(
           name,
           width,
           height,
           array_size,
           format,
           flags,
           num_mips,
           3u,
           esram_offset,
           esram_usage_bytes);
}

// File Line: 310
// RVA: 0x8F190
void __fastcall Illusion::DeleteTexture(Illusion::Texture *texture, bool wait)
{
  bool v2; // bl
  Illusion::Texture *v3; // rdi
  UFG::qResourceWarehouse *v4; // rax

  v2 = wait;
  v3 = texture;
  _((AMD_HD3D *)texture);
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Remove(v4, (UFG::qResourceData *)&v3->mNode);
  Illusion::Factory::Delete(v3, v2);
}

// File Line: 318
// RVA: 0x8EC70
UFG::qResourceData *__fastcall Illusion::CreateTextureAlias(const char *name, Illusion::Texture *org_texture, Illusion::Texture::Format format)
{
  Illusion::Texture *v3; // rsi
  char v4; // di
  const char *v5; // rbx
  unsigned int v6; // eax
  UFG::qResourceData *v7; // rax
  unsigned int v8; // ecx
  UFG::qResourceData *v9; // rbx
  UFG::qResourceData *v10; // rcx
  UFG::qResourceWarehouse *v11; // rax

  v3 = org_texture;
  v4 = format;
  v5 = name;
  v6 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v7 = Illusion::Factory::NewTexture(v5, v6, 0i64, 0i64, 0i64);
  v8 = v3->mFlags;
  v9 = v7;
  BYTE4(v7[1].mNode.mParent) = v4;
  LODWORD(v7[1].mNode.mParent) = v8 & 0xFEFF5FFF | 0x204000;
  BYTE5(v7[1].mNode.mParent) = v3->mType;
  BYTE6(v7[1].mNode.mParent) = v3->mAniso;
  HIBYTE(v7[1].mNode.mParent) = v3->mMipMapBiasPreset;
  LODWORD(v7[1].mNode.mChild[0]) = v3->mMipMapBias;
  v10 = v7;
  WORD2(v7[1].mNode.mChild[0]) = v3->mWidth;
  HIWORD(v7[1].mNode.mChild[0]) = v3->mHeight;
  LOBYTE(v7[1].mNode.mChild[1]) = v3->mNumMipMaps;
  BYTE1(v7[1].mNode.mChild[1]) = v3->mFilter;
  WORD1(v7[1].mNode.mChild[1]) = v3->mDepth;
  LODWORD(v7) = v3->mAlphaStateUID;
  v10[1].mResourceHandles.mNode.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v3;
  LODWORD(v10[1].mResourceHandles.mNode.mPrev) = 0;
  LODWORD(v10[2].mNode.mParent) = 0;
  HIDWORD(v10[1].mNode.mChild[1]) = (_DWORD)v7;
  Illusion::ITexturePlat::CreateTextureData((Illusion::ITexturePlat *)v10);
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, v9);
  return v9;
}

