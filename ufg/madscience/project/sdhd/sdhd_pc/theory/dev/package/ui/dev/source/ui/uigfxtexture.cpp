// File Line: 73
// RVA: 0xA23210
void __fastcall UFG::UIGfxTexture::UIGfxTexture(
        UFG::UIGfxTexture *this,
        Scaleform::GFx::Resource *pmanagerLocks,
        Illusion::Texture *ufgtexture,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::ImageBase *pimage)
{
  unsigned int Height; // ecx
  unsigned int mUID; // edi
  UFG::UIGfxTexture::HWTextureDesc *pTextures; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax

  Scaleform::Render::Texture::Texture(this, pmanagerLocks, size, 0, 0, pimage, 0i64);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTexture::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->Texture0.mUFGTexture);
  this->NeedsCacheFlush = 0;
  this->TextureFlags |= 4u;
  this->pTextures = &this->Texture0;
  Height = size->Height;
  this->Texture0.Size.Width = size->Width;
  this->Texture0.Size.Height = Height;
  this->pTextures->mIsWarehouseTexture = 1;
  mUID = ufgtexture->mNode.mUID;
  pTextures = this->pTextures;
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&pTextures->mUFGTexture, 0x8B43FABF, mUID, &ufgtexture->UFG::qResourceData, Inventory);
}

// File Line: 82
// RVA: 0xA23AB0
void __fastcall UFG::UIGfxTexture::~UIGfxTexture(UFG::UIGfxTexture *this)
{
  Scaleform::Mutex *p_TextureMutex; // rbx
  int v3; // esi
  __int64 v4; // rbp
  UFG::UIGfxTexture::HWTextureDesc *pTextures; // rax
  UFG::UIGfxTexture::HWTextureDesc *v6; // rdx
  Illusion::TextureHandle *p_mUFGTexture; // rsi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTexture::`vftable;
  p_TextureMutex = &this->pManagerLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( (unsigned int)(this->State - 2) <= 1 )
  {
    this->pPrev->Scaleform::Render::Texture::pNext = this->pNext;
    this->pNext->Scaleform::Render::Texture::pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::Texture *)-1i64;
    this->pNext = (Scaleform::Render::Texture *)-1i64;
    v3 = 0;
    this->pPrev = 0i64;
    this->pNext = 0i64;
    Scaleform::Render::Texture::ReleaseHWTextures(this, 1);
    if ( this->TextureCount )
    {
      v4 = 0i64;
      do
      {
        pTextures = this->pTextures;
        if ( !pTextures[v4].mIsWarehouseTexture )
          Illusion::Factory::QueueDelete((Illusion::Texture *)pTextures[v4].mUFGTexture.mData);
        ++v3;
        ++v4;
      }
      while ( v3 < (unsigned __int8)this->TextureCount );
    }
  }
  v6 = this->pTextures;
  if ( v6 != &this->Texture0 && v6 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Mutex::Unlock(p_TextureMutex);
  p_mUFGTexture = &this->Texture0.mUFGTexture;
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mUFGTexture, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mUFGTexture);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 103
// RVA: 0xA26EE0
char __fastcall UFG::UIGfxTexture::Initialize(UFG::UIGfxTexture *this)
{
  Scaleform::Render::ImageFormat v3; // ebp
  unsigned int i; // esi
  UFG::UIGfxTexture::HWTextureDesc *v5; // rdi
  Scaleform::Render::Size<unsigned long> *FormatPlaneSize; // rax
  unsigned int Height; // ecx
  unsigned __int16 Use; // cx
  unsigned int v9; // esi
  unsigned int j; // edi
  UFG::UIGfxTexture::HWTextureDesc *v11; // rdx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // ebp
  UFG::UIGfxTexture::HWTextureDesc *v15; // r14
  Illusion::Texture::Format vecDelDtor_high; // r15d
  unsigned int k; // esi
  unsigned int v18; // edi
  unsigned int v19; // eax
  UFG::qResourceData *Texture; // rax
  __int64 v21; // rdx
  UFG::qResourceData *v22; // rdi
  unsigned int mUID; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v25; // rax
  __int64 v26; // rdx
  UFG::qString v27; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::Render::Size<unsigned long> result; // [rsp+A0h] [rbp+8h] BYREF

  if ( (this->TextureFlags & 4) != 0 )
    return UFG::UIGfxTexture::Initialize(
             this,
             (Illusion::Texture *)this->pTextures->mUFGTexture.mData,
             this->pTextures->Size.Width,
             this->pTextures->Size.Height);
  v3 = ((unsigned int (__fastcall *)(UFG::UIGfxTexture *))this->vfptr[5].__vecDelDtor)(this);
  for ( i = 0; i < (unsigned __int8)this->TextureCount; ++i )
  {
    v5 = &this->pTextures[i];
    FormatPlaneSize = Scaleform::Render::ImageData::GetFormatPlaneSize(&result, v3, &this->ImgSize, i);
    Height = FormatPlaneSize->Height;
    v5->Size.Width = FormatPlaneSize->Width;
    v5->Size.Height = Height;
  }
  Use = this->Use;
  if ( (Use & 1) != 0 )
  {
    if ( (v3 & 0xFFFu) - 50 <= 0xF )
      goto LABEL_30;
    this->TextureFlags |= 1u;
  }
  if ( (Use & 2) != 0 )
  {
    this->TextureFlags |= 2u;
    v9 = 31;
    for ( j = 0; j < (unsigned __int8)this->TextureCount; ++j )
    {
      v11 = &this->pTextures[j];
      v12 = v11->Size.Height;
      result.Width = v11->Size.Width;
      result.Height = v12;
      v13 = Scaleform::Render::ImageSize_MipLevelCount((Scaleform::Render::Size<unsigned long>)&result);
      if ( v9 < v13 )
        v13 = v9;
      v9 = v13;
    }
    this->MipLevels = v9;
  }
  v14 = 0;
  if ( !this->TextureCount )
  {
LABEL_27:
    if ( !this->pImage || (unsigned __int8)Scaleform::Render::Texture::Update(this) )
    {
      this->State = State_Dead;
      return Scaleform::Render::Texture::Initialize(this);
    }
    LOBYTE(v26) = 1;
    this->vfptr[11].__vecDelDtor(this, v26);
LABEL_30:
    this->State = State_Valid;
    return 0;
  }
  while ( 1 )
  {
    v15 = &this->pTextures[v14];
    vecDelDtor_high = HIDWORD(this->pFormat[1].vfptr->__vecDelDtor);
    for ( k = 1; k < v15->Size.Width; k *= 2 )
      ;
    v18 = 1;
    v19 = v15->Size.Height;
    if ( v19 > 1 )
    {
      do
        v18 *= 2;
      while ( v18 < v19 );
    }
    UFG::qString::qString(&v27);
    UFG::qString::Format(&v27, "gfxtex%d", UFG::gTexInd);
    ++UFG::gTexInd;
    Texture = Illusion::CreateTexture(
                v27.mData,
                k,
                v18,
                vecDelDtor_high,
                0x500u,
                (unsigned __int8)this->MipLevels,
                0,
                0);
    v22 = Texture;
    if ( !Texture )
      break;
    mUID = Texture->mNode.mUID;
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v25 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v25, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v15->mUFGTexture, 0x8B43FABF, mUID, v22, Inventory);
    UFG::qString::~qString(&v27);
    if ( ++v14 >= (unsigned int)(unsigned __int8)this->TextureCount )
      goto LABEL_27;
  }
  LOBYTE(v21) = 1;
  this->vfptr[11].__vecDelDtor(this, v21);
  if ( this->State != (State_Dead|State_Valid) )
    this->State = State_Valid;
  UFG::qString::~qString(&v27);
  return 0;
}

// File Line: 192
// RVA: 0xA26D70
char __fastcall UFG::UIGfxTexture::Initialize(
        UFG::UIGfxTexture *this,
        Illusion::Texture *ufgtexture,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::Render::TextureManager *pManager; // rdi
  unsigned int v11; // eax
  __int64 v12; // rdx
  UFG::UIGfxTextureFormat::Mapping *v13; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::UIGfxTexture::HWTextureDesc *pTextures; // rdi
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  unsigned int mUID; // esi
  UFG::UIGfxTexture::HWTextureDesc *v20; // rdi
  UFG::qResourceWarehouse *v21; // rax

  this->TextureFlags |= 4u;
  pObject = this->pManagerLocks.pObject;
  pImage = this->pImage;
  pManager = pObject->pManager;
  if ( pImage )
  {
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[4].__vecDelDtor)(pImage);
    v12 = v11;
    LODWORD(v12) = v11 & 0xFFEFFFFF;
    this->pFormat = (Scaleform::Render::TextureFormat *)pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
                                                          pManager,
                                                          v12);
  }
  if ( this->pFormat )
    goto LABEL_11;
  v13 = UFG::TextureFormatMapping;
  if ( UFG::TextureFormatMapping[0].Format )
  {
    while ( v13->IllusionFormat != (unsigned __int8)ufgtexture->mFormat )
    {
      ++v13;
      if ( v13->Format == Image_None )
        goto LABEL_9;
    }
    this->pFormat = (Scaleform::Render::TextureFormat *)pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
                                                          pManager,
                                                          v13->Format);
  }
LABEL_9:
  if ( this->pFormat )
  {
LABEL_11:
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    pTextures = this->pTextures;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v17 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v17, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&pTextures->mUFGTexture, Inventory);
    v18 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    mUID = ufgtexture->mNode.mUID;
    v20 = this->pTextures;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v21 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v21, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v18;
    }
    UFG::qResourceHandle::Init(&v20->mUFGTexture, 0x8B43FABF, mUID, v18);
    this->pTextures->Size.Width = w;
    this->pTextures->Size.Height = h;
    this->pTextures->mIsWarehouseTexture = 1;
    this->State = State_Dead;
    return Scaleform::Render::Texture::Initialize(this);
  }
  else
  {
    this->State = State_Valid;
    return 0;
  }
}

// File Line: 243
// RVA: 0xA2A370
void __fastcall UFG::UIGfxTexture::computeUpdateConvertRescaleFlags(
        UFG::UIGfxTexture *this,
        bool rescale,
        bool swMipGen,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::ResizeImageType *rescaleType,
        Scaleform::Render::ImageFormat *rescaleBuffFromat,
        bool *convert)
{
  if ( swMipGen && (((format - 1) & 0xFFFFFFF6) != 0 || format == 10) )
    *convert = 1;
}

// File Line: 265
// RVA: 0xA28110
void __fastcall UFG::UIGfxTexture::ReleaseHWTextures(UFG::UIGfxTexture *this, bool __formal)
{
  int v3; // ebx
  __int64 v4; // rdi
  UFG::UIGfxTexture::HWTextureDesc *pTextures; // rax

  Scaleform::Render::Texture::ReleaseHWTextures(this, 1);
  v3 = 0;
  if ( this->TextureCount )
  {
    v4 = 0i64;
    do
    {
      pTextures = this->pTextures;
      if ( !pTextures[v4].mIsWarehouseTexture )
        Illusion::Factory::QueueDelete((Illusion::Texture *)pTextures[v4].mUFGTexture.mData);
      ++v3;
      ++v4;
    }
    while ( v3 < (unsigned __int8)this->TextureCount );
  }
}

// File Line: 283
// RVA: 0xA247D0
void __fastcall UFG::UIGfxTexture::ApplyTexture(
        UFG::UIGfxTexture *this,
        __int64 stageIndex,
        Scaleform::Render::ImageFillMode *fm)
{
  unsigned int v4; // esi
  Scaleform::Render::D3D1x::TextureManager *pManager; // rbp
  ID3D11SamplerState *state; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rbx
  unsigned int v9; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  unsigned int TextureCount; // r8d
  ID3D11ShaderResourceView **v15; // rdx
  __int64 v16; // r9
  UFG::qResourceHandle v17; // [rsp+38h] [rbp-50h] BYREF
  ID3D11ShaderResourceView *views[5]; // [rsp+58h] [rbp-30h] BYREF

  v4 = stageIndex;
  Scaleform::Render::Texture::ApplyTexture(this, stageIndex, fm);
  pManager = (Scaleform::Render::D3D1x::TextureManager *)this->pManagerLocks.pObject->pManager;
  state = pManager->SamplerStates[(unsigned __int8)fm->Fill];
  mPrev = this->pTextures->mUFGTexture.mData[3].mResourceHandles.mNode.mPrev;
  if ( !mPrev )
  {
    UFG::qStringHashUpper32("DEFAULT", -1);
    UFG::qResourceHandle::qResourceHandle(&v17);
    v9 = DEFAULT_TEXTURE;
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v17, 0x8B43FABF, v9, Inventory);
    mPrev = v17.mData[3].mResourceHandles.mNode.mPrev;
    v12 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v12;
    }
    UFG::qResourceHandle::Close(&v17, v12);
    UFG::qResourceHandle::~qResourceHandle(&v17);
  }
  TextureCount = (unsigned __int8)this->TextureCount;
  if ( this->TextureCount )
  {
    v15 = views;
    v16 = (unsigned __int8)this->TextureCount;
    do
    {
      *v15++ = (ID3D11ShaderResourceView *)mPrev[10].mNext;
      --v16;
    }
    while ( v16 );
  }
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(pManager, v4, TextureCount, views, state);
}

// File Line: 394
// RVA: 0xA286D0
bool __fastcall UFG::UIGfxTexture::Update(
        UFG::UIGfxTexture *this,
        Scaleform::Render::Texture::UpdateDesc *updates,
        unsigned int count,
        unsigned int mipLevel)
{
  __int64 v5; // rdi
  __int64 v7; // rax
  Scaleform::Render::ImageFormat v8; // eax
  __int64 v9; // r8
  Scaleform::Render::ImageFormat v10; // r15d
  unsigned int *p_y2; // r14
  __int64 v12; // rbp
  Scaleform::Render::MappedTextureBase *pMap; // rcx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int vfptr_low; // edx
  Scaleform::Render::TextureFormat *pFormat; // rcx
  void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  Scaleform::Render::ImagePlane pplane; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::Render::ImagePlane splane; // [rsp+60h] [rbp-38h] BYREF

  v5 = count;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, UFG::UIGfxTexture *, _QWORD, __int64))this->pManagerLocks.pObject->pManager->Scaleform::Render::Texture::vfptr[21].__vecDelDtor)(
         this->pManagerLocks.pObject->pManager,
         this,
         mipLevel,
         1i64);
  if ( v7 )
  {
    v8 = ((unsigned int (__fastcall *)(UFG::UIGfxTexture *))this->vfptr[5].__vecDelDtor)(this);
    memset(&pplane, 0, sizeof(pplane));
    v10 = v8;
    if ( (_DWORD)v5 )
    {
      p_y2 = &updates->DestRect.y2;
      v12 = v5;
      do
      {
        pMap = this->pMap;
        v14 = p_y2[1];
        splane = *(Scaleform::Render::ImagePlane *)(p_y2 - 11);
        Scaleform::Render::ImageData::GetPlane(&pMap->Data, v14, &pplane);
        v15 = *(p_y2 - 2);
        vfptr_low = LOBYTE(UFG::UIGfxTexture::GetTextureFormatMapping(this)[1].vfptr);
        splane.Width = *(p_y2 - 1) - *(p_y2 - 3);
        pplane.Width = splane.Width;
        pFormat = this->pFormat;
        pplane.pData += *(p_y2 - 3) * vfptr_low + pplane.Pitch * v15;
        splane.Height = *p_y2 - v15;
        pplane.Height = splane.Height;
        copyScanline = pFormat->vfptr->GetScanlineCopyFn(pFormat);
        Scaleform::Render::ConvertImagePlane(&pplane, &splane, v10, p_y2[1], copyScanline, 0i64, 0i64);
        p_y2 += 14;
        --v12;
      }
      while ( v12 );
    }
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(Scaleform::Render::TextureManager *, UFG::UIGfxTexture *, __int64))this->pManagerLocks.pObject->pManager->Scaleform::Render::Texture::vfptr[22].__vecDelDtor)(
      this->pManagerLocks.pObject->pManager,
      this,
      v9);
    LOBYTE(v7) = 1;
  }
  return v7;
}

// File Line: 456
// RVA: 0xA26090
Scaleform::Render::Texture *__fastcall UFG::UIGfxTextureManager::CreateTexture(
        UFG::UIGfxTextureManager *this,
        Illusion::Texture *ufgtexture,
        Scaleform::Render::Size<unsigned long> size,
        Scaleform::Render::ImageBase *pimage)
{
  UFG::UIGfxTexture *v8; // rax
  int v10; // [rsp+30h] [rbp-28h] BYREF
  __int64 v11; // [rsp+38h] [rbp-20h]
  UFG::UIGfxTexture *v12; // [rsp+40h] [rbp-18h]

  v11 = -2i64;
  v10 = 72;
  v8 = (UFG::UIGfxTexture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              152i64,
                              &v10);
  v12 = v8;
  if ( v8 )
    UFG::UIGfxTexture::UIGfxTexture(
      v8,
      (Scaleform::GFx::Resource *)this->pLocks.pObject,
      ufgtexture,
      *(Scaleform::Render::Size<unsigned long> **)&size,
      pimage);
  return Scaleform::Render::TextureManager::postCreateTexture(this, v8, 0);
}

