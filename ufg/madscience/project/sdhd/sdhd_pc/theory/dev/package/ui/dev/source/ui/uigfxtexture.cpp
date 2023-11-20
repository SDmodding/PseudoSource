// File Line: 73
// RVA: 0xA23210
void __fastcall UFG::UIGfxTexture::UIGfxTexture(UFG::UIGfxTexture *this, Scaleform::Render::TextureManagerLocks *pmanagerLocks, Illusion::Texture *ufgtexture, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::Size<unsigned long> *v5; // rdi
  Illusion::Texture *v6; // rbp
  UFG::UIGfxTexture *v7; // rsi
  unsigned int v8; // ecx
  unsigned int v9; // edi
  UFG::UIGfxTexture::HWTextureDesc *v10; // rbx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax

  v5 = size;
  v6 = ufgtexture;
  v7 = this;
  Scaleform::Render::Texture::Texture(
    (Scaleform::Render::Texture *)&this->vfptr,
    pmanagerLocks,
    size,
    0,
    0,
    pimage,
    0i64);
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTexture::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7->Texture0.mUFGTexture.mPrev);
  v7->NeedsCacheFlush = 0;
  v7->TextureFlags |= 4u;
  v7->pTextures = &v7->Texture0;
  v8 = v5->Height;
  v7->Texture0.Size.Width = v5->Width;
  v7->Texture0.Size.Height = v8;
  v7->pTextures->mIsWarehouseTexture = 1;
  v9 = v6->mNode.mUID;
  v10 = v7->pTextures;
  v11 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v11;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v10->mUFGTexture.mPrev,
    0x8B43FABF,
    v9,
    (UFG::qResourceData *)&v6->mNode,
    v11);
}

// File Line: 82
// RVA: 0xA23AB0
void __fastcall UFG::UIGfxTexture::~UIGfxTexture(UFG::UIGfxTexture *this)
{
  UFG::UIGfxTexture *v1; // rdi
  Scaleform::Mutex *v2; // rbx
  signed int v3; // esi
  __int64 v4; // rbp
  UFG::UIGfxTexture::HWTextureDesc *v5; // rax
  UFG::UIGfxTexture::HWTextureDesc *v6; // rdx
  UFG::qResourceHandle *v7; // rsi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTexture::`vftable;
  v2 = &this->pManagerLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v2);
  if ( (unsigned int)(v1->State - 2) <= 1 )
  {
    v1->pPrev->pNext = v1->pNext;
    v1->pNext->pPrev = v1->pPrev;
    v1->pPrev = (Scaleform::Render::Texture *)-1i64;
    v1->pNext = (Scaleform::Render::Texture *)-1i64;
    v3 = 0;
    v1->pPrev = 0i64;
    v1->pNext = 0i64;
    Scaleform::Render::Texture::ReleaseHWTextures((Scaleform::Render::Texture *)&v1->vfptr, 1);
    if ( v1->TextureCount > 0u )
    {
      v4 = 0i64;
      do
      {
        v5 = v1->pTextures;
        if ( !v5[v4].mIsWarehouseTexture )
          Illusion::Factory::QueueDelete((Illusion::Texture *)v5[v4].mUFGTexture.mData);
        ++v3;
        ++v4;
      }
      while ( v3 < (unsigned __int8)v1->TextureCount );
    }
  }
  v6 = v1->pTextures;
  if ( v6 != &v1->Texture0 && v6 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Mutex::Unlock(v2);
  v7 = (UFG::qResourceHandle *)&v1->Texture0.mUFGTexture.mPrev;
  v8 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(v7, v8);
  UFG::qResourceHandle::~qResourceHandle(v7);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  v10 = (Scaleform::Render::RenderBuffer *)v1->pManagerLocks.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 103
// RVA: 0xA26EE0
char __fastcall UFG::UIGfxTexture::Initialize(UFG::UIGfxTexture *this)
{
  UFG::UIGfxTexture *v1; // rbx
  Scaleform::Render::ImageFormat v3; // ebp
  unsigned int v4; // esi
  UFG::UIGfxTexture::HWTextureDesc *v5; // rdi
  Scaleform::Render::Size<unsigned long> *v6; // rax
  unsigned int v7; // ecx
  unsigned __int16 v8; // cx
  unsigned int v9; // esi
  unsigned int v10; // edi
  unsigned int *v11; // rdx
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // ebp
  signed __int64 v15; // r14
  Illusion::Texture::Format v16; // er15
  unsigned int i; // esi
  unsigned int v18; // edi
  unsigned int v19; // eax
  UFG::qResourceData *v20; // rax
  __int64 v21; // rdx
  UFG::qResourceData *v22; // rdi
  unsigned int v23; // esi
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  __int64 v26; // rdx
  UFG::qString v27; // [rsp+48h] [rbp-50h]
  Scaleform::Render::Size<unsigned long> result; // [rsp+A0h] [rbp+8h]

  v1 = this;
  if ( this->TextureFlags & 4 )
    return UFG::UIGfxTexture::Initialize(
             this,
             (Illusion::Texture *)this->pTextures->mUFGTexture.mData,
             this->pTextures->Size.Width,
             this->pTextures->Size.Height);
  v3 = ((unsigned int (*)(void))this->vfptr[5].__vecDelDtor)();
  v4 = 0;
  if ( v1->TextureCount )
  {
    do
    {
      v5 = &v1->pTextures[v4];
      v6 = Scaleform::Render::ImageData::GetFormatPlaneSize(&result, v3, &v1->ImgSize, v4);
      v7 = v6->Height;
      v5->Size.Width = v6->Width;
      v5->Size.Height = v7;
      ++v4;
    }
    while ( v4 < (unsigned __int8)v1->TextureCount );
  }
  v8 = v1->Use;
  if ( v8 & 1 )
  {
    if ( (v3 & 0xFFFu) - 50 <= 0xF )
      goto LABEL_30;
    v1->TextureFlags |= 1u;
  }
  if ( v8 & 2 )
  {
    v1->TextureFlags |= 2u;
    v9 = 31;
    v10 = 0;
    if ( v1->TextureCount > 0u )
    {
      do
      {
        v11 = (unsigned int *)&v1->pTextures[v10].Size;
        v12 = v11[1];
        result.Width = *v11;
        result.Height = v12;
        v13 = Scaleform::Render::ImageSize_MipLevelCount((Scaleform::Render::Size<unsigned long>)&result);
        if ( v9 < v13 )
          v13 = v9;
        v9 = v13;
        ++v10;
      }
      while ( v10 < (unsigned __int8)v1->TextureCount );
    }
    v1->MipLevels = v9;
  }
  v14 = 0;
  if ( v1->TextureCount <= 0u )
  {
LABEL_27:
    if ( !v1->pImage || (unsigned __int8)Scaleform::Render::Texture::Update((Scaleform::Render::Texture *)&v1->vfptr) )
    {
      v1->State = 2;
      return Scaleform::Render::Texture::Initialize((Scaleform::Render::Texture *)&v1->vfptr);
    }
    LOBYTE(v26) = 1;
    v1->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v26);
LABEL_30:
    v1->State = 1;
    return 0;
  }
  while ( 1 )
  {
    v15 = (signed __int64)&v1->pTextures[v14];
    v16 = HIDWORD(v1->pFormat[1].vfptr->__vecDelDtor);
    for ( i = 1; i < *(_DWORD *)v15; i *= 2 )
      ;
    v18 = 1;
    v19 = *(_DWORD *)(v15 + 4);
    if ( v19 > 1 )
    {
      do
        v18 *= 2;
      while ( v18 < v19 );
    }
    UFG::qString::qString(&v27);
    UFG::qString::Format(&v27, "gfxtex%d", UFG::gTexInd);
    ++UFG::gTexInd;
    v20 = Illusion::CreateTexture(v27.mData, i, v18, v16, 0x500u, (unsigned __int8)v1->MipLevels, 0, 0);
    v22 = v20;
    if ( !v20 )
      break;
    v23 = v20->mNode.mUID;
    v24 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v25 = UFG::qResourceWarehouse::Instance();
      v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v24;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v15 + 8), 0x8B43FABF, v23, v22, v24);
    UFG::qString::~qString(&v27);
    if ( ++v14 >= (unsigned int)(unsigned __int8)v1->TextureCount )
      goto LABEL_27;
  }
  LOBYTE(v21) = 1;
  v1->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v21);
  if ( v1->State != 3 )
    v1->State = 1;
  UFG::qString::~qString(&v27);
  return 0;
}

// File Line: 192
// RVA: 0xA26D70
char __fastcall UFG::UIGfxTexture::Initialize(UFG::UIGfxTexture *this, Illusion::Texture *ufgtexture, unsigned int w, unsigned int h)
{
  Scaleform::Render::TextureManagerLocks *v4; // rax
  UFG::UIGfxTexture *v5; // rbx
  Scaleform::Render::ImageBase *v6; // rcx
  Scaleform::Render::TextureManager *v7; // rdi
  unsigned int v8; // ebp
  unsigned int v9; // er14
  Illusion::Texture *v10; // rsi
  unsigned int v11; // eax
  __int64 v12; // rdx
  UFG::UIGfxTextureFormat::Mapping *v13; // rax
  char result; // al
  UFG::qResourceInventory *v15; // rax
  UFG::UIGfxTexture::HWTextureDesc *v16; // rdi
  UFG::qResourceWarehouse *v17; // rax
  UFG::qResourceInventory *v18; // rax
  unsigned int v19; // esi
  UFG::UIGfxTexture::HWTextureDesc *v20; // rdi
  UFG::qResourceWarehouse *v21; // rax

  this->TextureFlags |= 4u;
  v4 = this->pManagerLocks.pObject;
  v5 = this;
  v6 = this->pImage;
  v7 = v4->pManager;
  v8 = h;
  v9 = w;
  v10 = ufgtexture;
  if ( v6 )
  {
    v11 = ((__int64 (*)(void))v6->vfptr[4].__vecDelDtor)();
    v12 = v11;
    LODWORD(v12) = v11 & 0xFFEFFFFF;
    v5->pFormat = (Scaleform::Render::TextureFormat *)v7->vfptr[18].__vecDelDtor(
                                                        (Scaleform::RefCountImplCore *)&v7->vfptr,
                                                        v12);
  }
  if ( v5->pFormat )
    goto LABEL_18;
  v13 = UFG::TextureFormatMapping;
  if ( UFG::TextureFormatMapping[0].Format )
  {
    while ( v13->IllusionFormat != (unsigned __int8)v10->mFormat )
    {
      ++v13;
      if ( v13->Format == Image_None )
        goto LABEL_9;
    }
    v5->pFormat = (Scaleform::Render::TextureFormat *)v7->vfptr[18].__vecDelDtor(
                                                        (Scaleform::RefCountImplCore *)&v7->vfptr,
                                                        v13->Format);
  }
LABEL_9:
  if ( v5->pFormat )
  {
LABEL_18:
    v15 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    v16 = v5->pTextures;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v17 = UFG::qResourceWarehouse::Instance();
      v15 = UFG::qResourceWarehouse::GetInventory(v17, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v15;
    }
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v16->mUFGTexture.mPrev, v15);
    v18 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    v19 = v10->mNode.mUID;
    v20 = v5->pTextures;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v21 = UFG::qResourceWarehouse::Instance();
      v18 = UFG::qResourceWarehouse::GetInventory(v21, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v18;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v20->mUFGTexture.mPrev, 0x8B43FABF, v19, v18);
    v5->pTextures->Size.Width = v9;
    v5->pTextures->Size.Height = v8;
    v5->pTextures->mIsWarehouseTexture = 1;
    v5->State = 2;
    result = Scaleform::Render::Texture::Initialize((Scaleform::Render::Texture *)&v5->vfptr);
  }
  else
  {
    v5->State = 1;
    result = 0;
  }
  return result;
}

// File Line: 243
// RVA: 0xA2A370
void __fastcall UFG::UIGfxTexture::computeUpdateConvertRescaleFlags(UFG::UIGfxTexture *this, bool rescale, bool swMipGen, Scaleform::Render::ImageFormat format, Scaleform::Render::ResizeImageType *rescaleType, Scaleform::Render::ImageFormat *rescaleBuffFromat, bool *convert)
{
  if ( swMipGen && ((format - 1) & 0xFFFFFFF6 || format == 10) )
    *convert = 1;
}

// File Line: 265
// RVA: 0xA28110
void __fastcall UFG::UIGfxTexture::ReleaseHWTextures(UFG::UIGfxTexture *this, bool __formal)
{
  UFG::UIGfxTexture *v2; // rsi
  signed int v3; // ebx
  __int64 v4; // rdi
  UFG::UIGfxTexture::HWTextureDesc *v5; // rax

  v2 = this;
  Scaleform::Render::Texture::ReleaseHWTextures((Scaleform::Render::Texture *)&this->vfptr, 1);
  v3 = 0;
  if ( v2->TextureCount )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->pTextures;
      if ( !v5[v4].mIsWarehouseTexture )
        Illusion::Factory::QueueDelete((Illusion::Texture *)v5[v4].mUFGTexture.mData);
      ++v3;
      ++v4;
    }
    while ( v3 < (unsigned __int8)v2->TextureCount );
  }
}

// File Line: 283
// RVA: 0xA247D0
void __fastcall UFG::UIGfxTexture::ApplyTexture(UFG::UIGfxTexture *this, __int64 stageIndex, Scaleform::Render::ImageFillMode *fm)
{
  Scaleform::Render::ImageFillMode *v3; // rbx
  unsigned int v4; // esi
  UFG::UIGfxTexture *v5; // rdi
  Scaleform::Render::D3D1x::TextureManager *v6; // rbp
  ID3D11SamplerState *state; // r14
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rbx
  unsigned int v9; // ebx
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  unsigned int v14; // er8
  ID3D11ShaderResourceView **v15; // rdx
  __int64 v16; // r9
  UFG::qResourceHandle v17; // [rsp+38h] [rbp-50h]
  ID3D11ShaderResourceView *views; // [rsp+58h] [rbp-30h]

  v3 = fm;
  v4 = stageIndex;
  v5 = this;
  Scaleform::Render::Texture::ApplyTexture((Scaleform::Render::Texture *)&this->vfptr, stageIndex, fm);
  v6 = (Scaleform::Render::D3D1x::TextureManager *)v5->pManagerLocks.pObject->pManager;
  state = v6->SamplerStates[(unsigned __int8)v3->Fill];
  v8 = v5->pTextures->mUFGTexture.mData[3].mResourceHandles.mNode.mPrev;
  if ( !v8 )
  {
    UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
    UFG::qResourceHandle::qResourceHandle(&v17);
    v9 = DEFAULT_TEXTURE;
    v10 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v10;
    }
    UFG::qResourceHandle::Init(&v17, 0x8B43FABF, v9, v10);
    v8 = v17.mData[3].mResourceHandles.mNode.mPrev;
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
  v14 = (unsigned __int8)v5->TextureCount;
  if ( v5->TextureCount )
  {
    v15 = &views;
    v16 = (unsigned __int8)v5->TextureCount;
    do
    {
      *v15 = (ID3D11ShaderResourceView *)v8[10].mNext;
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(v6, v4, v14, &views, state);
}

// File Line: 394
// RVA: 0xA286D0
bool __fastcall UFG::UIGfxTexture::Update(UFG::UIGfxTexture *this, Scaleform::Render::Texture::UpdateDesc *updates, unsigned int count, unsigned int mipLevel)
{
  UFG::UIGfxTexture *v4; // rbx
  __int64 v5; // rdi
  Scaleform::Render::Texture::UpdateDesc *v6; // r14
  __int64 v7; // rax
  Scaleform::Render::ImageFormat v8; // eax
  __int64 v9; // r8
  Scaleform::Render::ImageFormat v10; // er15
  unsigned int *v11; // r14
  __int64 v12; // rbp
  Scaleform::Render::MappedTextureBase *v13; // rcx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  Scaleform::Render::TextureFormat *v17; // rcx
  void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  Scaleform::Render::ImagePlane pplane; // [rsp+40h] [rbp-58h]
  Scaleform::Render::ImagePlane splane; // [rsp+60h] [rbp-38h]

  v4 = this;
  v5 = count;
  v6 = updates;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, UFG::UIGfxTexture *, _QWORD, signed __int64))this->pManagerLocks.pObject->pManager->vfptr[21].__vecDelDtor)(
         this->pManagerLocks.pObject->pManager,
         this,
         mipLevel,
         1i64);
  if ( v7 )
  {
    v8 = ((unsigned int (__fastcall *)(UFG::UIGfxTexture *))v4->vfptr[5].__vecDelDtor)(v4);
    *(_QWORD *)&pplane.Width = 0i64;
    pplane.Pitch = 0i64;
    pplane.DataSize = 0i64;
    v10 = v8;
    pplane.pData = 0i64;
    if ( (_DWORD)v5 )
    {
      v11 = &v6->DestRect.y2;
      v12 = v5;
      do
      {
        v13 = v4->pMap;
        v14 = v11[1];
        splane.Width = *(v11 - 11);
        splane.Height = *(v11 - 10);
        splane.Pitch = *(_QWORD *)(v11 - 9);
        splane.DataSize = *(_QWORD *)(v11 - 7);
        splane.pData = *(char **)(v11 - 5);
        Scaleform::Render::ImageData::GetPlane(&v13->Data, v14, &pplane);
        v15 = *(v11 - 2);
        v16 = LOBYTE(UFG::UIGfxTexture::GetTextureFormatMapping(v4)[1].vfptr);
        splane.Width = *(v11 - 1) - *(v11 - 3);
        pplane.Width = splane.Width;
        v17 = v4->pFormat;
        pplane.pData += *(v11 - 3) * v16 + pplane.Pitch * v15;
        splane.Height = *v11 - v15;
        pplane.Height = splane.Height;
        copyScanline = (void (__fastcall *)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *))((__int64 (*)(void))v17->vfptr->GetScanlineCopyFn)();
        Scaleform::Render::ConvertImagePlane(&pplane, &splane, v10, v11[1], copyScanline, 0i64, 0i64);
        v11 += 14;
        --v12;
      }
      while ( v12 );
    }
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(Scaleform::Render::TextureManager *, UFG::UIGfxTexture *, __int64))v4->pManagerLocks.pObject->pManager->vfptr[22].__vecDelDtor)(
      v4->pManagerLocks.pObject->pManager,
      v4,
      v9);
    LOBYTE(v7) = 1;
  }
  return v7;
}

// File Line: 456
// RVA: 0xA26090
Scaleform::Render::Texture *__fastcall UFG::UIGfxTextureManager::CreateTexture(UFG::UIGfxTextureManager *this, Illusion::Texture *ufgtexture, Scaleform::Render::Size<unsigned long> size, Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::ImageBase *v4; // rdi
  Scaleform::Render::Size<unsigned long> *v5; // rsi
  Illusion::Texture *v6; // rbp
  UFG::UIGfxTextureManager *v7; // rbx
  UFG::UIGfxTexture *v8; // rax
  int v10; // [rsp+30h] [rbp-28h]
  __int64 v11; // [rsp+38h] [rbp-20h]
  UFG::UIGfxTexture *v12; // [rsp+40h] [rbp-18h]

  v11 = -2i64;
  v4 = pimage;
  v5 = (Scaleform::Render::Size<unsigned long> *)size;
  v6 = ufgtexture;
  v7 = this;
  v10 = 72;
  v8 = (UFG::UIGfxTexture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              152ui64,
                              (Scaleform::AllocInfo *)&v10);
  v12 = v8;
  if ( v8 )
    UFG::UIGfxTexture::UIGfxTexture(v8, v7->pLocks.pObject, v6, v5, v4);
  return Scaleform::Render::TextureManager::postCreateTexture(
           (Scaleform::Render::TextureManager *)&v7->vfptr,
           (Scaleform::Render::Texture *)&v8->vfptr,
           0);
}

