// File Line: 39
// RVA: 0x927C0
void __fastcall Illusion::Texture::HandleUpdated(UFG::qResourceFileHandle *handle, bool bound, AMD_HD3D *callback_data)
{
  if ( handle->mData )
    _(callback_data);
}

// File Line: 100
// RVA: 0x94530
// attributes: thunk
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
void __fastcall Illusion::Texture::SetSamplerFilter(Illusion::Texture *this, char filter)
{
  this->mFilter = filter;
  Illusion::ITexturePlat::OnSetSampler(this);
}

// File Line: 117
// RVA: 0x958C0
void __fastcall Illusion::Texture::SetSamplerAddressFlags(Illusion::Texture *this, unsigned int flags)
{
  this->mFlags &= 0xFFFFFFF0;
  this->mFlags |= flags;
  Illusion::ITexturePlat::OnSetSampler(this);
}

// File Line: 123
// RVA: 0x958E0
void __fastcall Illusion::Texture::SetSamplerState(Illusion::Texture *this, char filter, unsigned int flags)
{
  this->mFlags &= 0xFFFFFFF0;
  this->mFlags |= flags;
  this->mFilter = filter;
  Illusion::ITexturePlat::OnSetSampler(this);
}

// File Line: 130
// RVA: 0x95A90
void __fastcall Illusion::Texture::SwitchAliasTexture(Illusion::Texture *this, Illusion::Texture *new_alias_texture)
{
  this->mImageDataPosition = (unsigned __int64)new_alias_texture;
  Illusion::ITexturePlat::SwitchAliasTexture(this, new_alias_texture);
}

// File Line: 156
// RVA: 0x14582B0
__int64 Illusion::_dynamic_initializer_for__gTextureInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gTextureInventory,
    "iTextureInventory",
    0x8B43FABF,
    0xCDBFA090,
    0x3218EEB7u,
    0x100u);
  Illusion::gTextureInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iTextureInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gTextureInventory__);
}

// File Line: 166
// RVA: 0x8E010
void __fastcall Illusion::iTextureInventory::Add(Illusion::iTextureInventory *this, Illusion::Texture *resource_data)
{
  __int64 mOffset; // rax
  Illusion::TextureUser *v5; // rcx

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(&resource_data->UFG::qResourceData);
    UFG::qResourceHandle::qResourceHandle(&resource_data->mTextureDataHandle);
  }
  Illusion::ITexturePlat::OnLoad(resource_data);
  mOffset = resource_data->mTextureUser.mOffset;
  if ( mOffset )
    v5 = (Illusion::TextureUser *)((char *)&resource_data->mTextureUser + mOffset);
  else
    v5 = 0i64;
  Illusion::TextureUser::OnLoad(v5, resource_data);
  resource_data->mFlags |= 0x2000u;
  UFG::qResourceInventory::Add(this, &resource_data->UFG::qResourceData);
}

// File Line: 181
// RVA: 0x94A40
void __fastcall Illusion::iTextureInventory::Remove(
        Illusion::iTextureInventory *this,
        UFG::qResourceData *resource_data)
{
  __int64 v3; // rax
  Illusion::TextureUser *v4; // rcx

  if ( ((__int64)resource_data[1].mNode.mParent & 0x2000) != 0 )
  {
    UFG::qResourceInventory::Remove(this, resource_data);
    Illusion::ITexturePlat::OnUnload((Illusion::ITexturePlat *)resource_data);
    v3 = *(_QWORD *)&resource_data[1].mNode.mUID;
    if ( v3 )
      v4 = (Illusion::TextureUser *)((char *)&resource_data[1].mNode.mChild[2] + v3);
    else
      v4 = 0i64;
    Illusion::TextureUser::OnUnload(v4);
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&resource_data[1].mDebugName[12]);
    LODWORD(resource_data[1].mNode.mParent) &= ~0x2000u;
  }
}

// File Line: 201
// RVA: 0x941C0
void __fastcall Illusion::iTextureInventory::OnPreMove(
        Illusion::iTextureInventory *this,
        Illusion::ITexturePlat *resourceData)
{
  Illusion::ITexturePlat::OnPreMove(resourceData);
}

// File Line: 208
// RVA: 0x941B0
void __fastcall Illusion::iTextureInventory::OnPostMove(
        Illusion::iTextureInventory *this,
        Illusion::ITexturePlat *resourceData)
{
  Illusion::ITexturePlat::OnPostMove(resourceData);
}

// File Line: 231
// RVA: 0x92AF0
UFG::qResourceData *__fastcall Illusion::InternalCreateTexture(
        const char *name,
        __int16 width,
        __int16 height,
        __int16 depth,
        Illusion::Texture::Format format,
        unsigned int flags,
        char num_mips,
        char type,
        unsigned int esram_offset,
        unsigned int esram_usage_bytes)
{
  unsigned int v14; // eax
  UFG::qResourceData *v15; // rax
  UFG::qResourceData *v16; // rbx
  UFG::qResourceWarehouse *v17; // rax

  v14 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v15 = Illusion::Factory::NewTexture(name, v14, 0i64, 0i64, 0i64);
  BYTE4(v15[1].mNode.mParent) = format;
  v16 = v15;
  BYTE1(v15[1].mNode.mChild[1]) = 1;
  WORD2(v15[1].mNode.mChild[0]) = width;
  LODWORD(v15[1].mNode.mParent) = flags | 0x4003;
  HIWORD(v15[1].mNode.mChild[0]) = height;
  BYTE5(v15[1].mNode.mParent) = type;
  WORD1(v15[1].mNode.mChild[1]) = depth;
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
UFG::qResourceData *__fastcall Illusion::CreateTexture(
        const char *name,
        int width,
        int height,
        Illusion::Texture::Format format,
        unsigned int flags,
        int num_mips,
        unsigned int esram_offset,
        unsigned int esram_usage_bytes)
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
Illusion::Texture *__fastcall Illusion::CreateTexture3D(
        const char *name,
        int width,
        int height,
        int depth,
        Illusion::Texture::Format format,
        unsigned int flags,
        int num_mips,
        unsigned int esram_offset,
        unsigned int esram_usage_bytes)
{
  return (Illusion::Texture *)Illusion::InternalCreateTexture(
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
Illusion::Texture *__fastcall Illusion::CreateTextureCube(
        const char *name,
        int width,
        int height,
        Illusion::Texture::Format format,
        unsigned int flags,
        int num_mips,
        unsigned int esram_offset,
        unsigned int esram_usage_bytes)
{
  return (Illusion::Texture *)Illusion::InternalCreateTexture(
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
UFG::qResourceData *__fastcall Illusion::CreateTexture2DArray(
        const char *name,
        int width,
        int height,
        int array_size,
        Illusion::Texture::Format format,
        unsigned int flags,
        int num_mips,
        unsigned int esram_offset,
        unsigned int esram_usage_bytes)
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
void __fastcall Illusion::DeleteTexture(AMD_HD3D *texture, bool wait)
{
  UFG::qResourceWarehouse *v4; // rax

  _(texture);
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Remove(v4, (UFG::qResourceData *)texture);
  Illusion::Factory::Delete((Illusion::Texture *)texture, wait);
}

// File Line: 318
// RVA: 0x8EC70
Illusion::Texture *__fastcall Illusion::CreateTextureAlias(
        const char *name,
        UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *org_texture,
        Illusion::Texture::Format format)
{
  char v4; // di
  unsigned int v6; // eax
  UFG::qResourceData *v7; // rax
  unsigned int mNext; // ecx
  UFG::qResourceData *v9; // rbx
  UFG::qResourceData *v10; // rcx
  UFG::qResourceWarehouse *v11; // rax

  v4 = format;
  v6 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v7 = Illusion::Factory::NewTexture(name, v6, 0i64, 0i64, 0i64);
  mNext = (unsigned int)org_texture[5].mNext;
  v9 = v7;
  BYTE4(v7[1].mNode.mParent) = v4;
  LODWORD(v7[1].mNode.mParent) = mNext & 0xFEDF1FFF | 0x204000;
  BYTE5(v7[1].mNode.mParent) = BYTE5(org_texture[5].mNext);
  BYTE6(v7[1].mNode.mParent) = BYTE6(org_texture[5].mNext);
  HIBYTE(v7[1].mNode.mParent) = HIBYTE(org_texture[5].mNext);
  LODWORD(v7[1].mNode.mChild[0]) = org_texture[6].mPrev;
  v10 = v7;
  WORD2(v7[1].mNode.mChild[0]) = WORD2(org_texture[6].mPrev);
  HIWORD(v7[1].mNode.mChild[0]) = HIWORD(org_texture[6].mPrev);
  LOBYTE(v7[1].mNode.mChild[1]) = org_texture[6].mNext;
  BYTE1(v7[1].mNode.mChild[1]) = BYTE1(org_texture[6].mNext);
  WORD1(v7[1].mNode.mChild[1]) = WORD1(org_texture[6].mNext);
  LODWORD(v7) = HIDWORD(org_texture[6].mNext);
  v10[1].mResourceHandles.mNode.mNext = org_texture;
  LODWORD(v10[1].mResourceHandles.mNode.mPrev) = 0;
  LODWORD(v10[2].mNode.mParent) = 0;
  HIDWORD(v10[1].mNode.mChild[1]) = (_DWORD)v7;
  Illusion::ITexturePlat::CreateTextureData((Illusion::ITexturePlat *)v10);
  v11 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v11, v9);
  return (Illusion::Texture *)v9;
}

