// File Line: 28
// RVA: 0xA0DD00
void __fastcall Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::TextureManagerLocks *pmanagerLocks,
        Scaleform::Render::D3D1x::TextureFormat *pformat,
        char mipLevels,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned __int16 use,
        Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::ImageFormat v9; // eax
  unsigned __int8 FormatPlaneCount; // al
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *p_Texture0; // rax

  Scaleform::Render::Texture::Texture(this, pmanagerLocks, size, mipLevels, use, pimage, pformat);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  v9 = pformat->vfptr->GetImageFormat(pformat);
  FormatPlaneCount = Scaleform::Render::ImageData::GetFormatPlaneCount(v9);
  this->TextureCount = FormatPlaneCount;
  if ( FormatPlaneCount <= 1u )
    p_Texture0 = &this->Texture0;
  else
    p_Texture0 = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       32i64 * FormatPlaneCount,
                                                                       0i64);
  this->pTextures = p_Texture0;
  memset(p_Texture0, 0, 32i64 * (unsigned __int8)this->TextureCount);
}

// File Line: 44
// RVA: 0xA0DC50
void __fastcall Scaleform::Render::D3D1x::Texture::Texture(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::TextureManagerLocks *pmanagerLocks,
        ID3D11Texture2D *ptexture,
        Scaleform::Render::Size<unsigned long> size,
        Scaleform::Render::ImageBase *image)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // rdx
  unsigned int v9; // ecx

  Scaleform::Render::Texture::Texture(
    this,
    pmanagerLocks,
    *(Scaleform::Render::Size<unsigned long> **)&size,
    0,
    0,
    image,
    0i64);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  this->TextureFlags |= 4u;
  ptexture->vfptr->AddRef(ptexture);
  this->pTextures = &this->Texture0;
  this->Texture0.pTexture = ptexture;
  this->pTextures->pView = 0i64;
  pTextures = this->pTextures;
  v9 = *(_DWORD *)(*(_QWORD *)&size + 4i64);
  pTextures->Size.Width = *(_DWORD *)size.Width;
  pTextures->Size.Height = v9;
  this->pTextures->pStagingTexture = 0i64;
}

// File Line: 55
// RVA: 0xA0E1C0
void __fastcall Scaleform::Render::D3D1x::Texture::~Texture(Scaleform::Render::D3D1x::Texture *this)
{
  Scaleform::Mutex *p_TextureMutex; // rbx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // rdx
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  p_TextureMutex = &this->pManagerLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  if ( (unsigned int)(this->State - 2) <= 1 )
  {
    this->pPrev->Scaleform::Render::Texture::pNext = this->pNext;
    this->pNext->Scaleform::Render::Texture::pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::Texture *)-1i64;
    this->pNext = (Scaleform::Render::Texture *)-1i64;
    this->pPrev = 0i64;
    this->pNext = 0i64;
    Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(this, 1);
  }
  pTextures = this->pTextures;
  if ( pTextures != &this->Texture0 && pTextures )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Mutex::Unlock(p_TextureMutex);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 76
// RVA: 0xA0EE10
void __fastcall Scaleform::Render::D3D1x::Texture::GetUVGenMatrix(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *p_ImgSize; // rcx
  float v3; // xmm1_4
  float Height; // xmm0_4

  if ( (this->TextureFlags & 1) != 0 )
    p_ImgSize = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)&this->ImgSize;
  else
    p_ImgSize = this->pTextures;
  v3 = 1.0 / (float)(int)p_ImgSize->Size.Width;
  Height = (float)(int)p_ImgSize->Size.Height;
  *(_OWORD *)&mat->M[0][1] = 0ui64;
  *(_QWORD *)&mat->M[1][2] = 0i64;
  mat->M[0][0] = v3;
  mat->M[1][1] = 1.0 / Height;
}

// File Line: 110
// RVA: 0xA0F3C0
bool __fastcall Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible(DXGI_FORMAT format)
{
  bool result; // al

  switch ( (int)format )
  {
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R16G16B16A16_SNORM:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R16G16_SNORM:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R8G8_SNORM:
    case DXGI_FORMAT_R16_FLOAT:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R16_SNORM:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_R8_SNORM:
    case DXGI_FORMAT_A8_UNORM:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 143
// RVA: 0xA0F140
char __fastcall Scaleform::Render::D3D1x::Texture::Initialize(Scaleform::Render::D3D1x::Texture *this)
{
  Scaleform::Render::ImageFormat v3; // eax
  int v4; // esi
  Scaleform::Render::TextureManager *pManager; // r13
  Scaleform::Render::ImageFormat v6; // r15d
  unsigned int i; // ebp
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v8; // rdi
  Scaleform::Render::Size<unsigned long> *FormatPlaneSize; // rax
  unsigned int Height; // ecx
  unsigned int v11; // ebp
  unsigned int j; // edi
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v13; // rax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned __int16 Use; // ax
  bool v17; // cl
  int v18; // r15d
  int v19; // r12d
  bool v20; // al
  int v21; // ebp
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v22; // rdi
  int v23; // eax
  int vecDelDtor_high; // eax
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  __int64 v26; // rdx
  int Dst[12]; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::Render::Size<unsigned long> result; // [rsp+80h] [rbp+8h] BYREF

  if ( (this->TextureFlags & 4) != 0 )
    return Scaleform::Render::D3D1x::Texture::Initialize(this, this->pTextures->pTexture);
  v3 = ((unsigned int (__fastcall *)(Scaleform::Render::D3D1x::Texture *))this->vfptr[5].__vecDelDtor)(this);
  v4 = 0;
  pManager = this->pManagerLocks.pObject->pManager;
  v6 = v3;
  if ( this->State != (State_Dead|State_Valid) )
  {
    for ( i = 0; i < (unsigned __int8)this->TextureCount; v8->Size.Height = Height )
    {
      v8 = &this->pTextures[i];
      FormatPlaneSize = Scaleform::Render::ImageData::GetFormatPlaneSize(&result, v6, &this->ImgSize, i++);
      Height = FormatPlaneSize->Height;
      v8->Size.Width = FormatPlaneSize->Width;
    }
  }
  if ( (this->Use & 2) != 0
    && Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)HIDWORD(this->pFormat[1].vfptr->__vecDelDtor)) )
  {
    this->TextureFlags |= 2u;
    v11 = 31;
    for ( j = 0; j < (unsigned __int8)this->TextureCount; v11 = v15 )
    {
      v13 = &this->pTextures[j];
      v14 = v13->Size.Height;
      LODWORD(v13) = v13->Size.Width;
      result.Height = v14;
      result.Width = (unsigned int)v13;
      v15 = Scaleform::Render::ImageSize_MipLevelCount((Scaleform::Render::Size<unsigned long>)&result);
      if ( v11 < v15 )
        v15 = v11;
      ++j;
    }
    this->MipLevels = v11;
  }
  Use = this->Use;
  v17 = (Use & 0x100) != 0 && (Use & 0xE0) != 0;
  v18 = 0;
  v19 = 0;
  v20 = (Use & 0x400) != 0;
  v21 = 8;
  if ( v17 )
  {
    v18 = 2;
    v19 = 0x10000;
  }
  if ( v20 )
    v21 = 40;
  if ( this->TextureCount )
  {
    while ( 1 )
    {
      v22 = &this->pTextures[v4];
      memset(Dst, 0, 0x2Cui64);
      Dst[0] = v22->Size.Width;
      v23 = v22->Size.Height;
      Dst[3] = 1;
      Dst[1] = v23;
      Dst[2] = (unsigned __int8)this->MipLevels;
      vecDelDtor_high = HIDWORD(this->pFormat[1].vfptr->__vecDelDtor);
      vfptr = pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
      Dst[7] = v18;
      Dst[4] = vecDelDtor_high;
      Dst[8] = v21;
      Dst[9] = v19;
      Dst[5] = 1;
      if ( (*((int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, int *, _QWORD, ID3D11Texture2D **))vfptr->__vecDelDtor
            + 5))(
             vfptr,
             Dst,
             0i64,
             &v22->pTexture) < 0
        || (*((int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, ID3D11Texture2D *, _QWORD, ID3D11ShaderResourceView **))pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor
            + 7))(
             pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr,
             v22->pTexture,
             0i64,
             &v22->pView) < 0 )
      {
        break;
      }
      if ( ++v4 >= (unsigned int)(unsigned __int8)this->TextureCount )
        goto LABEL_25;
    }
  }
  else
  {
LABEL_25:
    if ( !this->pImage || (unsigned __int8)Scaleform::Render::Texture::Update(this) )
    {
      this->State = State_Dead;
      return Scaleform::Render::Texture::Initialize(this);
    }
  }
  LOBYTE(v26) = 1;
  this->vfptr[11].__vecDelDtor(this, v26);
  if ( this->State != (State_Dead|State_Valid) )
    this->State = State_Valid;
  return 0;
}

// File Line: 262
// RVA: 0xA0EFE0
char __fastcall Scaleform::Render::D3D1x::Texture::Initialize(
        Scaleform::Render::D3D1x::Texture *this,
        ID3D11Texture2D *ptexture)
{
  ID3D11Texture2D *v2; // rdi
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *pManager; // rdi
  unsigned int v7; // eax
  __int64 v8; // rdx
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v9; // rcx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // rcx
  int v12; // edx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v13; // rax
  unsigned int Height; // ecx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  int v16[2]; // [rsp+20h] [rbp-38h] BYREF
  char v17; // [rsp+28h] [rbp-30h]
  int v18; // [rsp+30h] [rbp-28h]

  v2 = ptexture;
  if ( !ptexture )
    return 0;
  if ( this->pTextures->pTexture != ptexture )
  {
    LOBYTE(ptexture) = 1;
    this->vfptr[11].__vecDelDtor(this, (unsigned int)ptexture);
    this->pTextures->pTexture = v2;
    this->pTextures->pTexture->vfptr->AddRef(this->pTextures->pTexture);
  }
  ((void (__fastcall *)(ID3D11Texture2D *, int *))v2->vfptr[3].AddRef)(v2, v16);
  pImage = this->pImage;
  this->MipLevels = v17;
  pObject = this->pManagerLocks.pObject;
  this->pFormat = 0i64;
  pManager = pObject->pManager;
  if ( pImage )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[4].__vecDelDtor)(pImage);
    v8 = v7;
    LODWORD(v8) = v7 & 0xFFEFFFFF;
    this->pFormat = (Scaleform::Render::TextureFormat *)pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
                                                          pManager,
                                                          v8);
  }
  if ( !this->pFormat )
  {
    v9 = Scaleform::Render::D3D1x::TextureFormatMapping;
    if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
    {
      while ( *(_DWORD *)v9->D3DFormat != v18 )
      {
        ++v9;
        if ( v9->Format == Image_None )
          goto LABEL_12;
      }
      this->pFormat = (Scaleform::Render::TextureFormat *)pManager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor(
                                                            pManager,
                                                            v9->Format);
    }
LABEL_12:
    if ( !this->pFormat )
      goto LABEL_13;
  }
  pTextures = this->pTextures;
  v12 = v16[1];
  pTextures->Size.Width = v16[0];
  pTextures->Size.Height = v12;
  if ( !this->ImgSize.Width && !this->ImgSize.Height )
  {
    v13 = this->pTextures;
    Height = v13->Size.Height;
    this->ImgSize.Width = v13->Size.Width;
    this->ImgSize.Height = Height;
  }
  vfptr = this->pManagerLocks.pObject->pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  if ( (*((int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, ID3D11Texture2D *, _QWORD, ID3D11ShaderResourceView **))vfptr->__vecDelDtor
        + 7))(
         vfptr,
         this->pTextures->pTexture,
         0i64,
         &this->pTextures->pView) < 0 )
  {
LABEL_13:
    this->State = State_Valid;
    return 0;
  }
  this->State = State_Dead;
  return Scaleform::Render::Texture::Initialize(this);
}

// File Line: 328
// RVA: 0xA10070
void __fastcall Scaleform::Render::D3D1x::Texture::computeUpdateConvertRescaleFlags(
        Scaleform::Render::D3D1x::Texture *this,
        bool rescale,
        bool swMipGen,
        Scaleform::Render::ImageFormat inputFormat,
        Scaleform::Render::ResizeImageType *rescaleType,
        Scaleform::Render::ImageFormat *rescaleBuffFromat,
        bool *convert)
{
  int vecDelDtor_high; // eax

  if ( rescale )
  {
    vecDelDtor_high = HIDWORD(this->pFormat[1].vfptr->__vecDelDtor);
    if ( vecDelDtor_high != 28 )
    {
      if ( vecDelDtor_high == 65 )
      {
        *rescaleBuffFromat = Image_A8;
        *rescaleType = ResizeGray;
        goto LABEL_8;
      }
      if ( vecDelDtor_high != 87 )
      {
        *convert = 1;
        goto LABEL_8;
      }
    }
    *rescaleBuffFromat = Image_R8G8B8A8;
    *rescaleType = ResizeRgbaToRgba;
  }
LABEL_8:
  if ( swMipGen
    && !Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)HIDWORD(this->pFormat[1].vfptr->__vecDelDtor)) )
  {
    *convert = 1;
  }
}

// File Line: 338
// RVA: 0xA0F810
void __fastcall Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(
        Scaleform::Render::D3D1x::Texture *this,
        bool staging)
{
  bool v2; // r14
  Scaleform::Render::TextureManager *pManager; // rdx
  void *CurrentThreadID; // rax
  bool v6; // cl
  unsigned int v7; // r12d
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *pTextures; // rax
  __int64 v9; // rbp
  ID3D11Texture2D *pTexture; // rsi
  ID3D11ShaderResourceView *pView; // r13
  ID3D11Texture2D *v12; // r14
  Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *p_pRTCommandQueue; // rbx
  unsigned __int64 pObject; // rax
  unsigned __int64 v15; // rdi
  unsigned __int64 v16; // r8
  ID3D11View **Data; // rax
  ID3D11Texture2D **v18; // rcx
  Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *p_ImageUpdates; // rdi
  unsigned __int64 Size; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  ID3D11View **v23; // rax
  ID3D11ShaderResourceView **v24; // rcx
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // r8
  ID3D11View **v28; // rax
  ID3D11Texture2D **v29; // rcx
  bool v30; // [rsp+60h] [rbp+8h]
  Scaleform::Render::TextureManager *v32; // [rsp+70h] [rbp+18h]

  v2 = staging;
  Scaleform::Render::Texture::ReleaseHWTextures(this, staging);
  pManager = this->pManagerLocks.pObject->pManager;
  v32 = pManager;
  v6 = 1;
  if ( pManager->RenderThreadId )
  {
    CurrentThreadID = UFG::qGetCurrentThreadID();
    pManager = v32;
    if ( CurrentThreadID == v32->RenderThreadId )
      v6 = 0;
  }
  v7 = 0;
  v30 = v6;
  if ( this->TextureCount )
  {
    while ( 1 )
    {
      pTextures = this->pTextures;
      v9 = v7;
      pTexture = pTextures[v9].pTexture;
      pView = pTextures[v9].pView;
      v12 = v2 ? pTextures[v9].pStagingTexture : 0i64;
      if ( pTexture )
        break;
LABEL_38:
      v2 = staging;
      this->pTextures[v9].pTexture = 0i64;
      this->pTextures[v9].pView = 0i64;
      if ( staging )
        this->pTextures[v9].pStagingTexture = 0i64;
      pManager = v32;
      v6 = v30;
      if ( ++v7 >= (unsigned __int8)this->TextureCount )
        return;
    }
    if ( !v6 )
    {
      pTexture->vfptr->Release(pTexture);
      pView->vfptr->Release(pView);
      if ( v12 )
        v12->vfptr->Release(v12);
      goto LABEL_38;
    }
    p_pRTCommandQueue = (Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *)&pManager[2].pRTCommandQueue;
    pObject = (unsigned __int64)pManager[2].pTextureCache.pObject;
    v15 = pObject + 1;
    if ( pObject + 1 >= pObject )
    {
      if ( (Scaleform::Render::TextureManagerLocks *)v15 <= pManager[2].pLocks.pObject )
        goto LABEL_17;
      v16 = v15 + (v15 >> 2);
    }
    else
    {
      if ( v15 >= (unsigned __int64)pManager[2].pLocks.pObject >> 1 )
        goto LABEL_17;
      v16 = pObject + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      p_pRTCommandQueue,
      &pManager[2].pRTCommandQueue,
      v16);
    pManager = v32;
LABEL_17:
    Data = p_pRTCommandQueue->Data;
    p_pRTCommandQueue->Size = v15;
    v18 = (ID3D11Texture2D **)&Data[v15 - 1];
    if ( v18 )
      *v18 = pTexture;
    p_ImageUpdates = (Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *)&pManager[2].ImageUpdates;
    Size = pManager[2].ImageUpdates.Queue.Data.Size;
    v21 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v21 <= pManager[2].ImageUpdates.Queue.Data.Policy.Capacity )
        goto LABEL_25;
      v22 = v21 + (v21 >> 2);
    }
    else
    {
      if ( v21 >= pManager[2].ImageUpdates.Queue.Data.Policy.Capacity >> 1 )
        goto LABEL_25;
      v22 = Size + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      p_ImageUpdates,
      p_ImageUpdates,
      v22);
LABEL_25:
    v23 = p_ImageUpdates->Data;
    p_ImageUpdates->Size = v21;
    v24 = (ID3D11ShaderResourceView **)&v23[v21 - 1];
    if ( v24 )
      *v24 = pView;
    if ( !v12 )
      goto LABEL_38;
    v25 = p_pRTCommandQueue->Size;
    v26 = v25 + 1;
    if ( v25 + 1 >= v25 )
    {
      if ( v26 <= p_pRTCommandQueue->Policy.Capacity )
        goto LABEL_34;
      v27 = v26 + (v26 >> 2);
    }
    else
    {
      if ( v26 >= p_pRTCommandQueue->Policy.Capacity >> 1 )
        goto LABEL_34;
      v27 = v25 + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      p_pRTCommandQueue,
      p_pRTCommandQueue,
      v27);
LABEL_34:
    v28 = p_pRTCommandQueue->Data;
    p_pRTCommandQueue->Size = v26;
    v29 = (ID3D11Texture2D **)&v28[v26 - 1];
    if ( v29 )
      *v29 = v12;
    goto LABEL_38;
  }
}

// File Line: 377
// RVA: 0xA0E7D0
void __fastcall Scaleform::Render::D3D1x::Texture::ApplyTexture(
        Scaleform::Render::D3D1x::Texture *this,
        __int64 stageIndex,
        Scaleform::Render::ImageFillMode *fm)
{
  __int64 v4; // r14
  unsigned __int64 TextureCount; // rbp
  Scaleform::Render::TextureManager *pManager; // rsi
  unsigned __int64 v8; // r10
  __int64 *v9; // rdx
  __int64 v10; // rdi
  ID3D11ShaderResourceView **p_pView; // rcx
  ID3D11ShaderResourceView *v12; // rax
  char v13; // dl
  char v14; // bl
  unsigned int v15; // r8d
  __int64 v16; // rdi
  unsigned __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19[4]; // [rsp+20h] [rbp-B8h] BYREF
  char Src[128]; // [rsp+40h] [rbp-98h] BYREF

  v4 = (unsigned int)stageIndex;
  Scaleform::Render::Texture::ApplyTexture(this, stageIndex, fm);
  TextureCount = (unsigned __int8)this->TextureCount;
  pManager = this->pManagerLocks.pObject->pManager;
  v8 = *((_QWORD *)&pManager[2].TextureFormats.Data.Data + (unsigned __int8)fm->Fill);
  if ( this->TextureCount )
  {
    v9 = v19;
    v10 = (unsigned __int8)this->TextureCount;
    p_pView = &this->pTextures->pView;
    do
    {
      v12 = *p_pView;
      ++v9;
      p_pView += 4;
      *(v9 - 1) = (__int64)v12;
      --v10;
    }
    while ( v10 );
  }
  v13 = 0;
  v14 = 0;
  if ( (_DWORD)TextureCount )
  {
    memset64(Src, v8, TextureCount);
    v15 = v4;
    v16 = 0i64;
    v17 = TextureCount;
    do
    {
      v18 = v19[v16++];
      if ( *((_QWORD *)&pManager[2].Textures.Root.pNext + v15) != v8 )
        v13 = 1;
      if ( *((_QWORD *)&pManager[2].DepthStencilInitQueue.Root.pNext + v15) != v18 )
        v14 = 1;
      ++v15;
      --v17;
    }
    while ( v17 );
    if ( v13 )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, char *))(**(_QWORD **)&pManager[1].RefCount + 80i64))(
        *(_QWORD *)&pManager[1].RefCount,
        (unsigned int)v4,
        (unsigned int)TextureCount,
        Src);
      memmove(&pManager[2].Textures.Root.pNext + v4, Src, 8 * TextureCount);
    }
    if ( v14 )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64 *))(**(_QWORD **)&pManager[1].RefCount + 64i64))(
        *(_QWORD *)&pManager[1].RefCount,
        (unsigned int)v4,
        (unsigned int)TextureCount,
        v19);
      memmove(&pManager[2].DepthStencilInitQueue.Root.pNext + v4, v19, 8 * TextureCount);
    }
  }
}

// File Line: 391
// RVA: 0xA0FEF0
bool __fastcall Scaleform::Render::D3D1x::Texture::Update(
        Scaleform::Render::D3D1x::Texture *this,
        Scaleform::Render::Texture::UpdateDesc *updates,
        unsigned int count,
        unsigned int mipLevel)
{
  __int64 v5; // rsi
  __int64 v7; // rax
  Scaleform::Render::ImageFormat v8; // eax
  __int64 v9; // r8
  Scaleform::Render::ImageFormat v10; // ebp
  unsigned int *p_y2; // rdi
  Scaleform::Render::MappedTextureBase *pMap; // rcx
  unsigned int v13; // edx
  Scaleform::Render::TextureFormat *pFormat; // r10
  unsigned int v15; // r9d
  unsigned int v16; // edx
  unsigned int v17; // eax
  void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  Scaleform::Render::ImagePlane pplane; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Render::ImagePlane splane; // [rsp+60h] [rbp-28h] BYREF

  v5 = count;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::D3D1x::Texture *, _QWORD, __int64))this->pManagerLocks.pObject->pManager->Scaleform::Render::Texture::vfptr[21].__vecDelDtor)(
         this->pManagerLocks.pObject->pManager,
         this,
         mipLevel,
         1i64);
  if ( v7 )
  {
    v8 = ((unsigned int (__fastcall *)(Scaleform::Render::D3D1x::Texture *))this->vfptr[5].__vecDelDtor)(this);
    memset(&pplane, 0, sizeof(pplane));
    v10 = v8;
    if ( (_DWORD)v5 )
    {
      p_y2 = &updates->DestRect.y2;
      do
      {
        pMap = this->pMap;
        v13 = p_y2[1];
        splane = *(Scaleform::Render::ImagePlane *)(p_y2 - 11);
        Scaleform::Render::ImageData::GetPlane(&pMap->Data, v13, &pplane);
        pFormat = this->pFormat;
        v15 = *(p_y2 - 2);
        v16 = *(p_y2 - 1) - *(p_y2 - 3);
        pplane.pData += *(p_y2 - 3) * LOBYTE(pFormat[1].vfptr->GetImageFormat) + pplane.Pitch * v15;
        v17 = *p_y2 - v15;
        splane.Width = v16;
        pplane.Width = v16;
        splane.Height = v17;
        pplane.Height = v17;
        copyScanline = pFormat->vfptr->GetScanlineCopyFn(pFormat);
        Scaleform::Render::ConvertImagePlane(&pplane, &splane, v10, p_y2[1], copyScanline, 0i64, 0i64);
        p_y2 += 14;
        --v5;
      }
      while ( v5 );
    }
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::D3D1x::Texture *, __int64))this->pManagerLocks.pObject->pManager->Scaleform::Render::Texture::vfptr[22].__vecDelDtor)(
      this->pManagerLocks.pObject->pManager,
      this,
      v9);
    LOBYTE(v7) = 1;
  }
  return v7;
}

// File Line: 437
// RVA: 0xA0EF00
bool __fastcall Scaleform::Render::D3D1x::DepthStencilSurface::Initialize(
        Scaleform::Render::D3D1x::DepthStencilSurface *this)
{
  __int64 v2; // rsi
  unsigned int Width; // edx
  _QWORD Dst[7]; // [rsp+20h] [rbp-38h] BYREF

  v2 = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::DepthStencilSurface *))this->vfptr[1].__vecDelDtor)(this);
  memset(Dst, 0, 0x2Cui64);
  Width = this->Size.Width;
  Dst[1] = 0x100000001i64;
  LODWORD(Dst[0]) = Width;
  HIDWORD(Dst[0]) = this->Size.Height;
  Dst[2] = 0x10000002Di64;
  Dst[4] = 64i64;
  HIDWORD(Dst[3]) = 0;
  if ( (*(int (__fastcall **)(_QWORD, _QWORD *, _QWORD, ID3D11Texture2D **))(**(_QWORD **)(v2 + 176) + 40i64))(
         *(_QWORD *)(v2 + 176),
         Dst,
         0i64,
         &this->pDepthStencilSurface) < 0
    || (*(int (__fastcall **)(_QWORD, ID3D11Texture2D *, _QWORD, ID3D11DepthStencilView **))(**(_QWORD **)(v2 + 176)
                                                                                           + 80i64))(
         *(_QWORD *)(v2 + 176),
         this->pDepthStencilSurface,
         0i64,
         &this->pDepthStencilSurfaceView) < 0 )
  {
    this->State = State_Valid;
  }
  else
  {
    this->State = State_Dead;
  }
  return this->State == State_Dead;
}

// File Line: 463
// RVA: 0xA0F450
char __fastcall Scaleform::Render::D3D1x::MappedTexture::Map(
        Scaleform::Render::D3D1x::MappedTexture *this,
        Scaleform::Render::Texture *ptexture,
        unsigned int mipLevel,
        unsigned int levelCount)
{
  unsigned int v5; // r14d
  Scaleform::Render::Texture *v6; // r12
  Scaleform::Render::D3D1x::MappedTexture *v7; // r13
  int MipLevels; // ebx
  Scaleform::Render::ImageFormat v9; // eax
  int v10; // esi
  Scaleform::Render::ImageFormat v11; // ebx
  Scaleform::Render::ImageFormat v12; // ebx
  char result; // al
  Scaleform::Render::TextureManager *pManager; // r15
  __int64 vfptr; // rsi
  __int64 v16; // r15
  __int64 v17; // rdx
  char *v18; // rdi
  unsigned int v19; // r14d
  unsigned int v20; // ebx
  __int64 StartMipLevel; // rax
  _QWORD *v22; // r13
  bool v23; // al
  unsigned int v24; // r12d
  unsigned __int64 v25; // rdi
  __int64 v26; // rsi
  unsigned __int64 MipLevelSize; // rax
  Scaleform::Render::ImagePlane *v28; // rcx
  unsigned int v29; // eax
  char v30; // bl
  unsigned int plane; // [rsp+30h] [rbp-99h]
  unsigned int v32; // [rsp+34h] [rbp-95h]
  unsigned int TextureCount; // [rsp+38h] [rbp-91h]
  __int64 v34; // [rsp+40h] [rbp-89h]
  __int64 v35; // [rsp+48h] [rbp-81h]
  Scaleform::Render::Size<unsigned long> sz; // [rsp+50h] [rbp-79h] BYREF
  __int64 v37[3]; // [rsp+58h] [rbp-71h] BYREF
  int v38; // [rsp+70h] [rbp-59h]
  __int64 v39; // [rsp+74h] [rbp-55h]
  int v40; // [rsp+7Ch] [rbp-4Dh]
  int v41; // [rsp+80h] [rbp-49h]
  __int64 v42; // [rsp+88h] [rbp-41h] BYREF
  unsigned int v43; // [rsp+90h] [rbp-39h]
  __int64 v44[3]; // [rsp+98h] [rbp-31h] BYREF
  __int64 v45; // [rsp+B0h] [rbp-19h]
  int v46; // [rsp+C0h] [rbp-9h]
  __int64 v47; // [rsp+C8h] [rbp-1h]
  __int64 v48; // [rsp+D0h] [rbp+7h]
  __int64 v49; // [rsp+D8h] [rbp+Fh]

  v49 = -2i64;
  v5 = mipLevel;
  v6 = ptexture;
  v7 = this;
  if ( levelCount > 4 )
  {
    v12 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[5].__vecDelDtor)(ptexture);
    Scaleform::Render::ImageData::Clear(&v7->Data);
    result = Scaleform::Render::ImageData::allocPlanes(&v7->Data, v12, levelCount, 1);
    if ( !result )
      return result;
  }
  else
  {
    MipLevels = 1;
    if ( (ptexture->Use & 2) == 0 )
      MipLevels = (unsigned __int8)ptexture->MipLevels;
    v9 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[4].__vecDelDtor)(ptexture);
    v10 = MipLevels * Scaleform::Render::ImageData::GetFormatPlaneCount(v9);
    v11 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))v6->vfptr[5].__vecDelDtor)(v6);
    Scaleform::Render::ImageData::Clear(&v7->Data);
    v7->Data.Format = v11;
    v7->Data.LevelCount = levelCount;
    v7->Data.pPlanes = v7->Planes;
    v7->Data.RawPlaneCount = v10;
    v7->Data.Flags |= 1u;
    v5 = mipLevel;
    if ( v7 != (Scaleform::Render::D3D1x::MappedTexture *)-88i64 && v10 == 1 )
    {
      v7->Data.Plane0.Width = v7->Planes[0].Width;
      v7->Data.Plane0.Height = v7->Planes[0].Height;
      v7->Data.Plane0.Pitch = v7->Planes[0].Pitch;
      v7->Data.Plane0.DataSize = v7->Planes[0].DataSize;
      v7->Data.Plane0.pData = v7->Planes[0].pData;
    }
  }
  pManager = v6->pManagerLocks.pObject->pManager;
  vfptr = (__int64)pManager[1].Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  v34 = vfptr;
  if ( vfptr )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)vfptr + 8i64))(vfptr);
  v47 = vfptr;
  v16 = *(_QWORD *)&pManager[1].RefCount;
  if ( v16 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 8i64))(v16);
  v48 = v16;
  v7->pTexture = v6;
  v7->StartMipLevel = v5;
  v7->LevelCount = levelCount;
  TextureCount = (unsigned __int8)v6->TextureCount;
  plane = 0;
  if ( v6->TextureCount )
  {
    v17 = 0i64;
    v35 = 0i64;
    while ( 1 )
    {
      v18 = (char *)v6[1].vfptr + v17;
      v19 = *(_DWORD *)v18;
      v20 = *((_DWORD *)v18 + 1);
      StartMipLevel = v7->StartMipLevel;
      if ( (_DWORD)StartMipLevel )
      {
        do
        {
          v19 >>= 1;
          if ( !v19 )
            v19 = 1;
          v20 >>= 1;
          if ( !v20 )
            v20 = 1;
          --StartMipLevel;
        }
        while ( StartMipLevel );
      }
      (*(void (__fastcall **)(_QWORD, __int64 *))(**((_QWORD **)v18 + 1) + 80i64))(*((_QWORD *)v18 + 1), v44);
      v37[0] = v44[0];
      v37[1] = v44[1];
      v37[2] = v44[2];
      v38 = v45;
      v41 = v46;
      v40 = 0x10000;
      v39 = 3i64;
      v22 = v18 + 24;
      if ( !*((_QWORD *)v18 + 3)
        && (*(int (__fastcall **)(__int64, __int64 *, _QWORD, char *))(*(_QWORD *)vfptr + 40i64))(
             vfptr,
             v37,
             0i64,
             v18 + 24) < 0 )
      {
        break;
      }
      if ( (v6->Use & 0x480) == 1152 )
      {
        if ( checkHandleCopyResource )
        {
          v23 = canHandleCopyResource;
        }
        else
        {
          v23 = (*(int (__fastcall **)(__int64))(*(_QWORD *)vfptr + 296i64))(vfptr) >= 40960;
          canHandleCopyResource = v23;
          checkHandleCopyResource = 1;
        }
        if ( !warned_3 )
          warned_3 = !v23;
        if ( v23 )
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v16 + 376i64))(v16, *v22, *((_QWORD *)v18 + 1));
      }
      v24 = 0;
      if ( levelCount )
      {
        v32 = plane;
        while ( (*(int (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD, __int64 *))(*(_QWORD *)v16 + 112i64))(
                  v16,
                  *v22,
                  v24,
                  2i64,
                  0,
                  &v42) >= 0 )
        {
          v25 = v43;
          v26 = v42;
          sz.Width = v19;
          sz.Height = v20;
          MipLevelSize = Scaleform::Render::ImageData::GetMipLevelSize(this->Data.Format, &sz, plane);
          v28 = &this->Data.pPlanes[v32];
          v28->Width = v19;
          v28->Height = v20;
          v28->Pitch = v25;
          v28->DataSize = MipLevelSize;
          v28->pData = (char *)v26;
          v19 >>= 1;
          if ( !v19 )
            v19 = 1;
          v20 >>= 1;
          if ( !v20 )
            v20 = 1;
          ++v24;
          v29 = TextureCount;
          v32 += TextureCount;
          if ( v24 >= levelCount )
          {
            vfptr = v34;
            goto LABEL_40;
          }
        }
        vfptr = v34;
        break;
      }
      v29 = TextureCount;
LABEL_40:
      ++plane;
      v17 = v35 + 32;
      v35 += 32i64;
      v7 = this;
      if ( plane >= v29 )
        goto LABEL_44;
      v6 = ptexture;
    }
    v30 = 0;
  }
  else
  {
LABEL_44:
    v7->pTexture->pMap = v7;
    v30 = 1;
  }
  if ( v16 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
  if ( vfptr )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)vfptr + 16i64))(vfptr);
  return v30;
}

// File Line: 565
// RVA: 0xA0FD20
void __fastcall Scaleform::Render::D3D1x::MappedTexture::Unmap(
        Scaleform::Render::D3D1x::MappedTexture *this,
        bool applyUpdate)
{
  bool v2; // si
  Scaleform::Render::Texture *pTexture; // rdx
  Scaleform::Render::TextureManager *pManager; // r8
  __int64 v6; // r14
  Scaleform::Render::Texture *v7; // rax
  unsigned int TextureCount; // r15d
  unsigned int v9; // r13d
  __int64 v10; // rcx
  char *v11; // rbp
  int v12; // ebx
  int v13; // ebx
  unsigned int v14; // esi
  Scaleform::Render::ImagePlane pplane; // [rsp+58h] [rbp-70h] BYREF
  __int64 v16; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Texture *v18; // [rsp+E0h] [rbp+18h]

  v2 = applyUpdate;
  pTexture = this->pTexture;
  v18 = pTexture;
  pManager = pTexture->pManagerLocks.pObject->pManager;
  v6 = *(_QWORD *)&pManager[1].RefCount;
  if ( v6 )
  {
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 8i64))(*(_QWORD *)&pManager[1].RefCount);
    pTexture = v18;
  }
  v7 = this->pTexture;
  TextureCount = (unsigned __int8)v7->TextureCount;
  v9 = 0;
  if ( v7->TextureCount )
  {
    v10 = 0i64;
    v16 = 0i64;
    do
    {
      v11 = (char *)pTexture[1].vfptr + v10;
      memset(&pplane, 0, sizeof(pplane));
      v12 = 0;
      if ( this->LevelCount > 0 )
      {
        do
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v6 + 120i64))(
            v6,
            *((_QWORD *)v11 + 3),
            (unsigned int)v12++);
        while ( v12 < this->LevelCount );
        v10 = v16;
      }
      if ( v2 )
      {
        v13 = 0;
        if ( this->LevelCount > 0 )
        {
          v14 = v9;
          do
          {
            Scaleform::Render::ImageData::GetPlane(&this->Data, v14, &pplane);
            if ( pplane.pData )
            {
              (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD, int, _QWORD))(*(_QWORD *)v6 + 368i64))(
                v6,
                *((_QWORD *)v11 + 1),
                v13 + this->StartMipLevel,
                0i64,
                0,
                0,
                *((_QWORD *)v11 + 3),
                v13,
                0i64);
              pplane.pData = 0i64;
            }
            ++v13;
            v14 += TextureCount;
          }
          while ( v13 < this->LevelCount );
          v10 = v16;
          v2 = applyUpdate;
        }
      }
      ++v9;
      v10 += 32i64;
      v16 = v10;
      pTexture = v18;
    }
    while ( v9 < TextureCount );
  }
  this->pTexture->pMap = 0i64;
  this->pTexture = 0i64;
  *(_QWORD *)&this->StartMipLevel = 0i64;
  if ( v6 )
    (*(void (__fastcall **)(__int64, Scaleform::Render::Texture *))(*(_QWORD *)v6 + 16i64))(v6, pTexture);
}

// File Line: 608
// RVA: 0xA0DEA0
void __fastcall Scaleform::Render::D3D1x::TextureManager::TextureManager(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pcontext,
        void *renderThreadId,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        Scaleform::Render::TextureCache *texCache)
{
  unsigned int i; // edi
  unsigned int j; // ebx
  int v11; // eax
  int Dst[20]; // [rsp+28h] [rbp-50h] BYREF

  Scaleform::Render::TextureManager::TextureManager(this, renderThreadId, commandQueue, texCache);
  this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  this->Scaleform::Render::TextureManager::Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  this->pDevice = pdevice;
  this->pDeviceContext = pcontext;
  Scaleform::Render::MappedTextureBase::MappedTextureBase(&this->MappedTexture0);
  this->MappedTexture0.vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::D3D1x::MappedTexture::`vftable;
  this->D3DTextureKillList.Data.Data = 0i64;
  this->D3DTextureKillList.Data.Size = 0i64;
  this->D3DTextureKillList.Data.Policy.Capacity = 0i64;
  this->D3DTexViewKillList.Data.Data = 0i64;
  this->D3DTexViewKillList.Data.Size = 0i64;
  this->D3DTexViewKillList.Data.Policy.Capacity = 0i64;
  Scaleform::Render::D3D1x::TextureManager::initTextureFormats(this);
  this->SamplerStates[0] = 0i64;
  this->SamplerStates[1] = 0i64;
  this->SamplerStates[2] = 0i64;
  this->SamplerStates[3] = 0i64;
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < 2; ++j )
    {
      memset(Dst, 0, 0x34ui64);
      v11 = 21;
      if ( 2 * j != 2 )
        v11 = 0;
      Dst[0] = v11;
      if ( i )
      {
        Dst[2] = 3;
        Dst[1] = 3;
      }
      else
      {
        Dst[2] = 1;
        Dst[1] = 1;
      }
      Dst[3] = 3;
      Dst[6] = 8;
      Dst[12] = 2139095039;
      Dst[4] = -1086324736;
      Dst[5] = 1;
      ((void (__fastcall *)(ID3D11Device *, int *, ID3D11SamplerState **))this->pDevice->vfptr->GSSetSamplers)(
        this->pDevice,
        Dst,
        &this->SamplerStates[(unsigned __int8)(i | (2 * j))]);
    }
  }
}

// File Line: 647
// RVA: 0xA0E2F0
void __fastcall Scaleform::Render::D3D1x::TextureManager::~TextureManager(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Mutex *p_TextureMutex; // rbx
  Scaleform::Render::Palette *pObject; // rdx

  this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  this->Scaleform::Render::TextureManager::Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  Scaleform::Render::D3D1x::TextureManager::Reset(this);
  this->pLocks.pObject->pManager = 0i64;
  Scaleform::Mutex::Unlock(p_TextureMutex);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->D3DTexViewKillList.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->D3DTextureKillList.Data.Data);
  this->MappedTexture0.vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  Scaleform::Render::ImageData::freePlanes(&this->MappedTexture0.Data);
  pObject = this->MappedTexture0.Data.pPalette.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::TextureManager::~TextureManager(this);
}

// File Line: 654
// RVA: 0xA0FB00
void __fastcall Scaleform::Render::D3D1x::TextureManager::Reset(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Mutex *p_TextureMutex; // rbx
  Scaleform::Render::Texture *v3; // rax
  unsigned int i; // esi
  unsigned int j; // edi
  ID3D11SamplerState *v6; // rcx

  p_TextureMutex = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(p_TextureMutex);
  while ( 1 )
  {
    v3 = this == (Scaleform::Render::D3D1x::TextureManager *)-128i64
       ? 0i64
       : (Scaleform::Render::Texture *)&this->TextureFormats.Data.Size;
    if ( this->Textures.Root.pNext == v3 )
      break;
    ((void (__fastcall *)(Scaleform::Render::Texture *))this->Textures.Root.pNext->vfptr[9].__vecDelDtor)(this->Textures.Root.pNext);
  }
  ((void (__fastcall *)(Scaleform::Render::D3D1x::TextureManager *))this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[16].__vecDelDtor)(this);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; j < 2; ++j )
    {
      v6 = this->SamplerStates[(unsigned __int8)(i | (2 * j))];
      if ( v6 )
        v6->vfptr->Release(v6);
    }
  }
  this->SamplerStates[0] = 0i64;
  this->SamplerStates[1] = 0i64;
  this->SamplerStates[2] = 0i64;
  this->SamplerStates[3] = 0i64;
  this->pDevice = 0i64;
  Scaleform::Mutex::Unlock(p_TextureMutex);
}

// File Line: 684
// RVA: 0xA0FBF0
void __fastcall Scaleform::Render::D3D1x::TextureManager::SetSamplerState(
        Scaleform::Render::D3D1x::TextureManager *this,
        unsigned int stage,
        unsigned int viewCount,
        ID3D11View **views,
        ID3D11SamplerState *state)
{
  __int64 v5; // r15
  __int64 v6; // r12
  char v8; // r10
  unsigned int v10; // r11d
  ID3D11View **v11; // r14
  char v12; // bl
  __int64 v13; // rbp
  ID3D11View *v14; // rax
  __int64 v15; // rdi
  char Src[168]; // [rsp+20h] [rbp-A8h] BYREF

  if ( viewCount )
  {
    v5 = stage;
    v6 = viewCount;
    v8 = 0;
    memset64(Src, (unsigned __int64)state, viewCount);
    v10 = stage;
    v11 = views;
    v12 = 0;
    v13 = viewCount;
    do
    {
      v14 = *v11++;
      if ( this->CurrentSamplers[v10] != state )
        v8 = 1;
      if ( this->CurrentTextures[v10] != v14 )
        v12 = 1;
      ++v10;
      --v13;
    }
    while ( v13 );
    if ( v8 )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, char *))this->pDeviceContext->vfptr[3].AddRef)(
        this->pDeviceContext,
        stage,
        viewCount,
        Src);
      v15 = v6;
      memmove(&this->CurrentSamplers[v5], Src, 8 * v6);
    }
    else
    {
      v15 = viewCount;
    }
    if ( v12 )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, ID3D11View **))this->pDeviceContext->vfptr[2].Release)(
        this->pDeviceContext,
        (unsigned int)v5,
        (unsigned int)v6,
        views);
      memmove(&this->CurrentTextures[v5], views, 8 * v15);
    }
  }
}

// File Line: 714
// RVA: 0xA0E930
void __fastcall Scaleform::Render::D3D1x::TextureManager::BeginScene(Scaleform::Render::D3D1x::TextureManager *this)
{
  ID3D11DeviceContext *pDeviceContext; // rcx
  _BYTE v3[32]; // [rsp+20h] [rbp-48h] BYREF
  char v4[40]; // [rsp+40h] [rbp-28h] BYREF

  this->CurrentSamplers[0] = 0i64;
  this->CurrentSamplers[1] = 0i64;
  this->CurrentSamplers[2] = 0i64;
  this->CurrentSamplers[3] = 0i64;
  this->CurrentTextures[0] = 0i64;
  this->CurrentTextures[1] = 0i64;
  this->CurrentTextures[2] = 0i64;
  this->CurrentTextures[3] = 0i64;
  pDeviceContext = this->pDeviceContext;
  memset(v4, 0, 32);
  memset(v3, 0, sizeof(v3));
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, _BYTE *))pDeviceContext->vfptr[3].AddRef)(
    pDeviceContext,
    0i64,
    4i64,
    v3);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, char *))this->pDeviceContext->vfptr[2].Release)(
    this->pDeviceContext,
    0i64,
    4i64,
    v4);
}

// File Line: 801
// RVA: 0xA10170
void __fastcall Scaleform::Render::D3D1x::TextureManager::initTextureFormats(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  D3D_FEATURE_LEVEL v2; // r15d
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v3; // rbx
  Scaleform::Render::TextureFormat *v4; // rax
  Scaleform::Render::TextureFormat *v5; // r14
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::Render::TextureFormat **v8; // rcx
  Scaleform::Render::D3D1x::TextureFormat::Mapping *i; // rcx
  char v10; // [rsp+88h] [rbp+10h] BYREF
  int v11; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::Render::TextureFormat *v12; // [rsp+98h] [rbp+20h]

  v2 = ((unsigned int (__fastcall *)(ID3D11Device *))this->pDevice->vfptr->GenerateMips)(this->pDevice);
  v3 = Scaleform::Render::D3D1x::TextureFormatMapping;
  if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
  {
    while ( v2 < v3->MinFeatureLevel
         || ((int (__fastcall *)(ID3D11Device *, _QWORD, char *))this->pDevice->vfptr->RSSetState)(
              this->pDevice,
              *(unsigned int *)v3->D3DFormat,
              &v10) < 0
         || (v10 & 0x20) == 0 )
    {
LABEL_18:
      ++v3;
      if ( v3->Format == Image_None )
        return;
    }
    v11 = 72;
    v4 = (Scaleform::Render::TextureFormat *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               24i64,
                                               &v11);
    v5 = v4;
    v12 = v4;
    if ( v4 )
    {
      v4->vfptr = (Scaleform::Render::TextureFormatVtbl *)&Scaleform::Render::TextureFormat::`vftable;
      v4->vfptr = (Scaleform::Render::TextureFormatVtbl *)&Scaleform::Render::D3D1x::TextureFormat::`vftable;
      v4[1].vfptr = (Scaleform::Render::TextureFormatVtbl *)v3;
      LODWORD(v4[2].vfptr) = 0;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = this->TextureFormats.Data.Size + 1;
    if ( v6 >= this->TextureFormats.Data.Size )
    {
      if ( v6 > this->TextureFormats.Data.Policy.Capacity )
      {
        v7 = v6 + (v6 >> 2);
        goto LABEL_13;
      }
    }
    else if ( v6 < this->TextureFormats.Data.Policy.Capacity >> 1 )
    {
      v7 = this->TextureFormats.Data.Size + 1;
LABEL_13:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TextureFormats,
        &this->TextureFormats,
        v7);
    }
    this->TextureFormats.Data.Size = v6;
    v8 = &this->TextureFormats.Data.Data[v6 - 1];
    if ( v8 )
      *v8 = v5;
    for ( i = v3 + 1; i->Format == v3->Format; ++i )
      v3 = i;
    goto LABEL_18;
  }
}

// File Line: 844
// RVA: 0xA10450
void __fastcall Scaleform::Render::D3D1x::TextureManager::processTextureKillList(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  unsigned int v2; // edi
  __int64 v3; // rcx
  ID3D11View *v4; // rcx
  unsigned int v5; // edi
  __int64 v6; // rcx
  ID3D11Resource *v7; // rcx
  Scaleform::ArrayLH<ID3D11View *,72,Scaleform::ArrayConstPolicy<8,8,0> > *p_D3DTexViewKillList; // rdi
  ID3D11View **v9; // rax
  Scaleform::ArrayLH<ID3D11Resource *,72,Scaleform::ArrayConstPolicy<8,8,0> > *p_D3DTextureKillList; // rbx
  ID3D11Resource **v11; // rax
  int v12; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0;
  if ( this->D3DTexViewKillList.Data.Size )
  {
    v3 = 0i64;
    do
    {
      v4 = this->D3DTexViewKillList.Data.Data[v3];
      v4->vfptr->Release(v4);
      v3 = ++v2;
    }
    while ( v2 < this->D3DTexViewKillList.Data.Size );
  }
  v5 = 0;
  if ( this->D3DTextureKillList.Data.Size )
  {
    v6 = 0i64;
    do
    {
      v7 = this->D3DTextureKillList.Data.Data[v6];
      v7->vfptr->Release(v7);
      v6 = ++v5;
    }
    while ( v5 < this->D3DTextureKillList.Data.Size );
  }
  p_D3DTexViewKillList = &this->D3DTexViewKillList;
  if ( this->D3DTexViewKillList.Data.Size
    && (this->D3DTexViewKillList.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( p_D3DTexViewKillList->Data.Data )
    {
      v9 = (ID3D11View **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            p_D3DTexViewKillList->Data.Data,
                            64i64);
    }
    else
    {
      v12 = 72;
      v9 = (ID3D11View **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                            Scaleform::Memory::pGlobalHeap,
                            &this->D3DTexViewKillList,
                            64i64,
                            &v12);
    }
    p_D3DTexViewKillList->Data.Data = v9;
    this->D3DTexViewKillList.Data.Policy.Capacity = 8i64;
  }
  p_D3DTextureKillList = &this->D3DTextureKillList;
  p_D3DTexViewKillList->Data.Size = 0i64;
  if ( p_D3DTextureKillList->Data.Size && (p_D3DTextureKillList->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( p_D3DTextureKillList->Data.Data )
    {
      v11 = (ID3D11Resource **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 p_D3DTextureKillList->Data.Data,
                                 64i64);
    }
    else
    {
      v12 = 72;
      v11 = (ID3D11Resource **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 p_D3DTextureKillList,
                                 64i64,
                                 &v12);
    }
    p_D3DTextureKillList->Data.Data = v11;
    p_D3DTextureKillList->Data.Policy.Capacity = 8i64;
  }
  p_D3DTextureKillList->Data.Size = 0i64;
}

// File Line: 854
// RVA: 0xA10300
void __fastcall Scaleform::Render::D3D1x::TextureManager::processInitTextures(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *p_TextureInitQueue; // rsi
  Scaleform::Render::Texture *p_Textures; // rax
  Scaleform::List<Scaleform::Render::DepthStencilSurface,Scaleform::Render::DepthStencilSurface> *p_DepthStencilInitQueue; // rax
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *v5; // rcx
  Scaleform::Render::Texture *v6; // rax
  Scaleform::Render::Texture *pNext; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *v9; // rax
  Scaleform::Render::DepthStencilSurface *v10; // rcx
  Scaleform::RefCountImplCoreVtbl *v11; // rax

  p_TextureInitQueue = &this->TextureInitQueue;
  p_Textures = (Scaleform::Render::Texture *)&this->Textures;
  if ( this == (Scaleform::Render::D3D1x::TextureManager *)-144i64 )
    p_Textures = 0i64;
  if ( this->TextureInitQueue.Root.pNext != p_Textures )
    goto LABEL_9;
  p_DepthStencilInitQueue = &this->DepthStencilInitQueue;
  v5 = &this->TextureInitQueue;
  if ( !p_DepthStencilInitQueue )
    v5 = 0i64;
  if ( (Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *)p_DepthStencilInitQueue->Root.pNext != v5 )
  {
LABEL_9:
    while ( 1 )
    {
      v6 = (Scaleform::Render::Texture *)&p_TextureInitQueue[-1];
      if ( !p_TextureInitQueue )
        v6 = 0i64;
      if ( p_TextureInitQueue->Root.pNext == v6 )
        break;
      pNext = this->TextureInitQueue.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::Texture *)-1i64;
      pNext->pNext = (Scaleform::Render::Texture *)-1i64;
      vfptr = pNext->vfptr;
      pNext->pNext = 0i64;
      pNext->pPrev = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))vfptr[1].__vecDelDtor)(pNext) )
      {
        pNext->pPrev = this->Textures.Root.pPrev;
        pNext->pNext = (Scaleform::Render::Texture *)&this->TextureFormats.Data.Size;
        this->Textures.Root.pPrev->pNext = pNext;
        this->Textures.Root.pPrev = pNext;
      }
    }
    while ( 1 )
    {
      v9 = &this->TextureInitQueue;
      if ( this == (Scaleform::Render::D3D1x::TextureManager *)-160i64 )
        v9 = 0i64;
      if ( (Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *)this->DepthStencilInitQueue.Root.pNext == v9 )
        break;
      v10 = this->DepthStencilInitQueue.Root.pNext;
      v10->pPrev->pNext = v10->pNext;
      v10->pNext->pPrev = v10->pPrev;
      v10->pPrev = (Scaleform::Render::DepthStencilSurface *)-1i64;
      v10->pNext = (Scaleform::Render::DepthStencilSurface *)-1i64;
      v11 = v10->vfptr;
      v10->pNext = 0i64;
      v10->pPrev = 0i64;
      ((void (*)(void))v11[3].__vecDelDtor)();
    }
    Scaleform::WaitCondition::NotifyAll(&this->pLocks.pObject->TextureInitWC);
  }
}

// File Line: 883
// RVA: 0xA0EC40
Scaleform::Render::Texture *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        unsigned int format,
        char mipLevels,
        Scaleform::Render::Size<unsigned long> *size,
        __int16 use,
        Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::D3D1x::TextureFormat *v10; // rbp
  Scaleform::Render::D3D1x::Texture *v11; // rax
  int v12; // [rsp+40h] [rbp-38h] BYREF
  __int64 v13; // [rsp+48h] [rbp-30h]
  Scaleform::Render::D3D1x::Texture *v14; // [rsp+50h] [rbp-28h]

  v13 = -2i64;
  if ( !this->pDevice )
    return 0i64;
  v10 = (Scaleform::Render::D3D1x::TextureFormat *)Scaleform::Render::TextureManager::precreateTexture(
                                                     this,
                                                     format,
                                                     use,
                                                     pimage);
  if ( !v10 )
    return 0i64;
  v12 = 72;
  v11 = (Scaleform::Render::D3D1x::Texture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               128i64,
                                               &v12);
  v14 = v11;
  if ( v11 )
    Scaleform::Render::D3D1x::Texture::Texture(v11, this->pLocks.pObject, v10, mipLevels, size, use, pimage);
  return Scaleform::Render::TextureManager::postCreateTexture(this, v11, use);
}

// File Line: 903
// RVA: 0xA0EB90
Scaleform::Render::Texture *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateTexture(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Texture2D *pd3dtexture,
        Scaleform::Render::Size<unsigned long> imgSize,
        Scaleform::Render::ImageBase *image)
{
  Scaleform::Render::D3D1x::Texture *v9; // rax
  unsigned int v10; // edx
  Scaleform::Render::Size<unsigned long> size; // [rsp+30h] [rbp-38h] BYREF
  __int64 v12; // [rsp+38h] [rbp-30h]
  Scaleform::Render::D3D1x::Texture *v13; // [rsp+40h] [rbp-28h]
  int v14; // [rsp+78h] [rbp+10h] BYREF

  v12 = -2i64;
  if ( !pd3dtexture )
    return 0i64;
  v14 = 72;
  v9 = (Scaleform::Render::D3D1x::Texture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              128i64,
                                              &v14);
  v13 = v9;
  if ( v9 )
  {
    v10 = *(_DWORD *)(*(_QWORD *)&imgSize + 4i64);
    size.Width = *(_DWORD *)imgSize.Width;
    size.Height = v10;
    Scaleform::Render::D3D1x::Texture::Texture(
      v9,
      this->pLocks.pObject,
      pd3dtexture,
      (Scaleform::Render::Size<unsigned long>)&size,
      image);
  }
  return Scaleform::Render::TextureManager::postCreateTexture(this, v9, 0);
}

// File Line: 913
// RVA: 0xA0EDA0
__int64 __fastcall Scaleform::Render::D3D1x::TextureManager::GetTextureUseCaps(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  unsigned int v3; // ebx
  __int64 result; // rax

  v3 = 272;
  if ( (format & 0xFFFu) - 50 > 0xF )
    v3 = 306;
  result = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::TextureManager *))this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[18].__vecDelDtor)(this);
  if ( result )
  {
    if ( this->Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[19].__vecDelDtor(
           this,
           result) )
    {
      v3 |= 0x80u;
    }
    return v3;
  }
  return result;
}

// File Line: 928
// RVA: 0xA0E9D0
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::MemoryManager *manager)
{
  Scaleform::Render::DepthStencilSurface *v6; // rax
  Scaleform::Render::DepthStencilSurface *v7; // rbx
  int v8; // [rsp+58h] [rbp+20h] BYREF

  if ( !this->pDevice )
    return 0i64;
  v8 = 72;
  v6 = (Scaleform::Render::DepthStencilSurface *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::D3D1x::TextureManager *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   72i64,
                                                   &v8,
                                                   -2i64);
  v7 = v6;
  if ( v6 )
  {
    Scaleform::Render::DepthStencilSurface::DepthStencilSurface(
      v6,
      (Scaleform::GFx::Resource *)this->pLocks.pObject,
      size);
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::DepthStencilSurface::`vftable;
    v7[1].vfptr = 0i64;
    *(_QWORD *)&v7[1].RefCount = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  return Scaleform::Render::TextureManager::postCreateDepthStencilSurface(this, v7);
}

// File Line: 941
// RVA: 0xA0EA80
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(
        Scaleform::Render::D3D1x::TextureManager *this,
        ID3D11Texture2D *psurface)
{
  __int64 v5; // rbx
  int v6; // ebp
  int v7; // r14d
  Scaleform::Render::TextureManagerLocks *pObject; // rsi
  int v9[24]; // [rsp+28h] [rbp-60h] BYREF
  int v10; // [rsp+98h] [rbp+10h] BYREF
  __int64 v11; // [rsp+A0h] [rbp+18h]

  if ( !psurface )
    return 0i64;
  psurface->vfptr->AddRef(psurface);
  ((void (__fastcall *)(ID3D11Texture2D *, int *))psurface->vfptr[3].AddRef)(psurface, v9);
  v10 = 72;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::D3D1x::TextureManager *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         this,
         72i64,
         &v10,
         -2i64);
  v11 = v5;
  if ( v5 )
  {
    v6 = v9[0];
    v7 = v9[1];
    pObject = this->pLocks.pObject;
    *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v5 + 8) = 1;
    *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::Render::DepthStencilSurface,72>::`vftable;
    *(_QWORD *)v5 = &Scaleform::Render::DepthStencilSurface::`vftable;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
    *(_QWORD *)(v5 + 32) = pObject;
    *(_DWORD *)(v5 + 40) = 0;
    *(_DWORD *)(v5 + 44) = v6;
    *(_DWORD *)(v5 + 48) = v7;
    *(_QWORD *)v5 = &Scaleform::Render::D3D1x::DepthStencilSurface::`vftable;
    *(_QWORD *)(v5 + 56) = 0i64;
    *(_QWORD *)(v5 + 64) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  *(_QWORD *)(v5 + 56) = psurface;
  *(_DWORD *)(v5 + 40) = 2;
  return (Scaleform::Render::DepthStencilSurface *)v5;
}

