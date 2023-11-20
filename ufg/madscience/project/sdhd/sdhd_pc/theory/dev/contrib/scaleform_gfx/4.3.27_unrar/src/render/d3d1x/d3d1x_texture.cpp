// File Line: 28
// RVA: 0xA0DD00
void __fastcall Scaleform::Render::D3D1x::Texture::Texture(Scaleform::Render::D3D1x::Texture *this, Scaleform::Render::TextureManagerLocks *pmanagerLocks, Scaleform::Render::D3D1x::TextureFormat *pformat, unsigned int mipLevels, Scaleform::Render::Size<unsigned long> *size, unsigned int use, Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::D3D1x::TextureFormat *v7; // rbx
  Scaleform::Render::D3D1x::Texture *v8; // rdi
  Scaleform::Render::ImageFormat v9; // eax
  unsigned __int8 v10; // al
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v11; // rax

  v7 = pformat;
  v8 = this;
  Scaleform::Render::Texture::Texture(
    (Scaleform::Render::Texture *)&this->vfptr,
    pmanagerLocks,
    size,
    mipLevels,
    use,
    pimage,
    (Scaleform::Render::TextureFormat *)&pformat->vfptr);
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  v9 = (unsigned int)v7->vfptr->GetImageFormat((Scaleform::Render::TextureFormat *)&v7->vfptr);
  v10 = Scaleform::Render::ImageData::GetFormatPlaneCount(v9);
  v8->TextureCount = v10;
  if ( v10 <= 1u )
    v11 = &v8->Texture0;
  else
    v11 = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                v8,
                                                                32i64 * v10,
                                                                0i64);
  v8->pTextures = v11;
  memset(v11, 0, 32i64 * (unsigned __int8)v8->TextureCount);
}

// File Line: 44
// RVA: 0xA0DC50
void __fastcall Scaleform::Render::D3D1x::Texture::Texture(Scaleform::Render::D3D1x::Texture *this, Scaleform::Render::TextureManagerLocks *pmanagerLocks, ID3D11Texture2D *ptexture, Scaleform::Render::Size<unsigned long> size, Scaleform::Render::ImageBase *image)
{
  unsigned int *v5; // rdi
  ID3D11Texture2D *v6; // rbx
  Scaleform::Render::D3D1x::Texture *v7; // rsi
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v8; // rdx
  unsigned int v9; // ecx

  v5 = (unsigned int *)size;
  v6 = ptexture;
  v7 = this;
  Scaleform::Render::Texture::Texture(
    (Scaleform::Render::Texture *)&this->vfptr,
    pmanagerLocks,
    *(Scaleform::Render::Size<unsigned long> **)&size,
    0,
    0,
    image,
    0i64);
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  v7->TextureFlags |= 4u;
  v6->vfptr->AddRef((IUnknown *)&v6->vfptr);
  v7->pTextures = &v7->Texture0;
  v7->Texture0.pTexture = v6;
  v7->pTextures->pView = 0i64;
  v8 = v7->pTextures;
  v9 = v5[1];
  v8->Size.Width = *v5;
  v8->Size.Height = v9;
  v7->pTextures->pStagingTexture = 0i64;
}

// File Line: 55
// RVA: 0xA0E1C0
void __fastcall Scaleform::Render::D3D1x::Texture::~Texture(Scaleform::Render::D3D1x::Texture *this)
{
  Scaleform::Render::D3D1x::Texture *v1; // rdi
  Scaleform::Mutex *v2; // rbx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v3; // rdx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::Texture::`vftable;
  v2 = &this->pManagerLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v2);
  if ( (unsigned int)(v1->State - 2) <= 1 )
  {
    v1->pPrev->pNext = v1->pNext;
    v1->pNext->pPrev = v1->pPrev;
    v1->pPrev = (Scaleform::Render::Texture *)-1i64;
    v1->pNext = (Scaleform::Render::Texture *)-1i64;
    v1->pPrev = 0i64;
    v1->pNext = 0i64;
    Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(v1, 1);
  }
  v3 = v1->pTextures;
  if ( v3 != &v1->Texture0 && v3 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Mutex::Unlock(v2);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  v4 = (Scaleform::Render::RenderBuffer *)v1->pManagerLocks.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 76
// RVA: 0xA0EE10
void __fastcall Scaleform::Render::D3D1x::Texture::GetUVGenMatrix(Scaleform::Render::D3D1x::Texture *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v2; // rcx
  float v3; // xmm1_4
  float v4; // xmm0_4

  if ( this->TextureFlags & 1 )
    v2 = (Scaleform::Render::D3D1x::Texture::HWTextureDesc *)&this->ImgSize;
  else
    v2 = this->pTextures;
  v3 = 1.0 / (float)(signed int)v2->Size.Width;
  v4 = (float)(signed int)v2->Size.Height;
  *(_OWORD *)&mat->M[0][1] = 0ui64;
  *(_QWORD *)&mat->M[1][2] = 0i64;
  mat->M[0][0] = v3;
  mat->M[1][1] = 1.0 / v4;
}

// File Line: 110
// RVA: 0xA0F3C0
char __fastcall Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible(DXGI_FORMAT format)
{
  char result; // al

  switch ( (_DWORD)format )
  {
    case 2:
    case 0xA:
    case 0xB:
    case 0xD:
    case 0x10:
    case 0x18:
    case 0x1A:
    case 0x1C:
    case 0x1D:
    case 0x1F:
    case 0x22:
    case 0x23:
    case 0x25:
    case 0x29:
    case 0x31:
    case 0x33:
    case 0x36:
    case 0x38:
    case 0x3A:
    case 0x3D:
    case 0x3F:
    case 0x41:
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
  Scaleform::Render::D3D1x::Texture *v1; // rbx
  Scaleform::Render::ImageFormat v3; // eax
  int v4; // esi
  Scaleform::Render::TextureManager *v5; // r13
  Scaleform::Render::ImageFormat v6; // er15
  unsigned int v7; // ebp
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v8; // rdi
  Scaleform::Render::Size<unsigned long> *v9; // rax
  unsigned int v10; // ecx
  unsigned int v11; // ebp
  unsigned int v12; // edi
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v13; // rax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned __int16 v16; // ax
  bool v17; // cl
  signed int v18; // er15
  signed int v19; // er12
  char v20; // al
  signed int v21; // ebp
  signed __int64 v22; // rdi
  int v23; // eax
  unsigned int v24; // eax
  Scaleform::RefCountImplCoreVtbl *v25; // rcx
  __int64 v26; // rdx
  int Dst; // [rsp+20h] [rbp-58h]
  int v28; // [rsp+24h] [rbp-54h]
  int v29; // [rsp+28h] [rbp-50h]
  int v30; // [rsp+2Ch] [rbp-4Ch]
  unsigned __int64 v31; // [rsp+30h] [rbp-48h]
  int v32; // [rsp+3Ch] [rbp-3Ch]
  int v33; // [rsp+40h] [rbp-38h]
  int v34; // [rsp+44h] [rbp-34h]
  Scaleform::Render::Size<unsigned long> result; // [rsp+80h] [rbp+8h]

  v1 = this;
  if ( this->TextureFlags & 4 )
    return Scaleform::Render::D3D1x::Texture::Initialize(this, this->pTextures->pTexture);
  v3 = ((unsigned int (*)(void))this->vfptr[5].__vecDelDtor)();
  v4 = 0;
  v5 = v1->pManagerLocks.pObject->pManager;
  v6 = v3;
  if ( v1->State != 3 )
  {
    v7 = 0;
    if ( v1->TextureCount > 0u )
    {
      do
      {
        v8 = &v1->pTextures[v7];
        v9 = Scaleform::Render::ImageData::GetFormatPlaneSize(&result, v6, &v1->ImgSize, v7++);
        v10 = v9->Height;
        v8->Size.Width = v9->Width;
        v8->Size.Height = v10;
      }
      while ( v7 < (unsigned __int8)v1->TextureCount );
    }
  }
  if ( v1->Use & 2
    && Scaleform::Render::D3D1x::IsD3DFormatMipGenCompatible((DXGI_FORMAT)HIDWORD(v1->pFormat[1].vfptr->__vecDelDtor)) )
  {
    v1->TextureFlags |= 2u;
    v11 = 31;
    v12 = 0;
    if ( v1->TextureCount > 0u )
    {
      do
      {
        v13 = &v1->pTextures[v12];
        v14 = v13->Size.Height;
        LODWORD(v13) = v13->Size.Width;
        result.Height = v14;
        result.Width = (unsigned int)v13;
        v15 = Scaleform::Render::ImageSize_MipLevelCount((Scaleform::Render::Size<unsigned long>)&result);
        if ( v11 < v15 )
          v15 = v11;
        ++v12;
        v11 = v15;
      }
      while ( v12 < (unsigned __int8)v1->TextureCount );
    }
    v1->MipLevels = v11;
  }
  v16 = v1->Use;
  v17 = v16 & 0x100 && v16 & 0xE0;
  v18 = 0;
  v19 = 0;
  v20 = (v16 >> 10) & 1;
  v21 = 8;
  if ( v17 )
  {
    v18 = 2;
    v19 = 0x10000;
  }
  if ( v20 )
    v21 = 40;
  if ( v1->TextureCount <= 0u )
  {
LABEL_25:
    if ( !v1->pImage || (unsigned __int8)Scaleform::Render::Texture::Update((Scaleform::Render::Texture *)&v1->vfptr) )
    {
      v1->State = 2;
      return Scaleform::Render::Texture::Initialize((Scaleform::Render::Texture *)&v1->vfptr);
    }
  }
  else
  {
    while ( 1 )
    {
      v22 = (signed __int64)&v1->pTextures[v4];
      memset(&Dst, 0, 0x2Cui64);
      Dst = *(_DWORD *)v22;
      v23 = *(_DWORD *)(v22 + 4);
      v30 = 1;
      v28 = v23;
      v29 = (unsigned __int8)v1->MipLevels;
      v24 = HIDWORD(v1->pFormat[1].vfptr->__vecDelDtor);
      v25 = v5[1].vfptr;
      v32 = v18;
      v31 = __PAIR__(1, v24);
      v33 = v21;
      v34 = v19;
      if ( (*((signed int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, int *, _QWORD, signed __int64, _QWORD, _QWORD, unsigned __int64))v25->__vecDelDtor
            + 5))(
             v25,
             &Dst,
             0i64,
             v22 + 8,
             *(_QWORD *)&Dst,
             *(_QWORD *)&v29,
             __PAIR__(1, v24)) < 0
        || (*((signed int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, _QWORD, _QWORD, signed __int64))v5[1].vfptr->__vecDelDtor
            + 7))(
             v5[1].vfptr,
             *(_QWORD *)(v22 + 8),
             0i64,
             v22 + 16) < 0 )
      {
        break;
      }
      if ( ++v4 >= (unsigned int)(unsigned __int8)v1->TextureCount )
        goto LABEL_25;
    }
  }
  LOBYTE(v26) = 1;
  v1->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, v26);
  if ( v1->State != 3 )
    v1->State = 1;
  return 0;
}

// File Line: 262
// RVA: 0xA0EFE0
char __fastcall Scaleform::Render::D3D1x::Texture::Initialize(Scaleform::Render::D3D1x::Texture *this, ID3D11Texture2D *ptexture)
{
  ID3D11Texture2D *v2; // rdi
  Scaleform::Render::D3D1x::Texture *v3; // rbx
  Scaleform::Render::ImageBase *v4; // rcx
  Scaleform::Render::TextureManagerLocks *v5; // rax
  Scaleform::Render::TextureManager *v6; // rdi
  unsigned int v7; // eax
  __int64 v8; // rdx
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v9; // rcx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v11; // rcx
  int v12; // edx
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v13; // rax
  unsigned int v14; // ecx
  Scaleform::RefCountImplCoreVtbl *v15; // rcx
  unsigned int v16; // [rsp+20h] [rbp-38h]
  int v17; // [rsp+24h] [rbp-34h]
  char v18; // [rsp+28h] [rbp-30h]
  int v19; // [rsp+30h] [rbp-28h]

  v2 = ptexture;
  v3 = this;
  if ( !ptexture )
    return 0;
  if ( this->pTextures->pTexture != ptexture )
  {
    LOBYTE(ptexture) = 1;
    this->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)ptexture);
    v3->pTextures->pTexture = v2;
    ((void (*)(void))v3->pTextures->pTexture->vfptr->AddRef)();
  }
  ((void (__fastcall *)(ID3D11Texture2D *, unsigned int *))v2->vfptr[3].AddRef)(v2, &v16);
  v4 = v3->pImage;
  v3->MipLevels = v18;
  v5 = v3->pManagerLocks.pObject;
  v3->pFormat = 0i64;
  v6 = v5->pManager;
  if ( v4 )
  {
    v7 = ((__int64 (*)(void))v4->vfptr[4].__vecDelDtor)();
    v8 = v7;
    LODWORD(v8) = v7 & 0xFFEFFFFF;
    v3->pFormat = (Scaleform::Render::TextureFormat *)v6->vfptr[18].__vecDelDtor(
                                                        (Scaleform::RefCountImplCore *)&v6->vfptr,
                                                        v8);
  }
  if ( !v3->pFormat )
  {
    v9 = Scaleform::Render::D3D1x::TextureFormatMapping;
    if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
    {
      while ( *(_DWORD *)v9->D3DFormat != v19 )
      {
        ++v9;
        if ( v9->Format == Image_None )
          goto LABEL_12;
      }
      v3->pFormat = (Scaleform::Render::TextureFormat *)v6->vfptr[18].__vecDelDtor(
                                                          (Scaleform::RefCountImplCore *)&v6->vfptr,
                                                          v9->Format);
    }
LABEL_12:
    if ( !v3->pFormat )
      goto LABEL_22;
  }
  v11 = v3->pTextures;
  v12 = v17;
  v11->Size.Width = v16;
  v11->Size.Height = v12;
  if ( !v3->ImgSize.Width && !v3->ImgSize.Height )
  {
    v13 = v3->pTextures;
    v14 = v13->Size.Height;
    v3->ImgSize.Width = v13->Size.Width;
    v3->ImgSize.Height = v14;
  }
  v15 = v3->pManagerLocks.pObject->pManager[1].vfptr;
  if ( (*((signed int (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, ID3D11Texture2D *, _QWORD, ID3D11ShaderResourceView **))v15->__vecDelDtor
        + 7))(
         v15,
         v3->pTextures->pTexture,
         0i64,
         &v3->pTextures->pView) < 0 )
  {
LABEL_22:
    v3->State = 1;
    return 0;
  }
  v3->State = 2;
  return Scaleform::Render::Texture::Initialize((Scaleform::Render::Texture *)&v3->vfptr);
}

// File Line: 328
// RVA: 0xA10070
void __fastcall Scaleform::Render::D3D1x::Texture::computeUpdateConvertRescaleFlags(Scaleform::Render::D3D1x::Texture *this, bool rescale, bool swMipGen, Scaleform::Render::ImageFormat inputFormat, Scaleform::Render::ResizeImageType *rescaleType, Scaleform::Render::ImageFormat *rescaleBuffFromat, bool *convert)
{
  int v7; // eax

  if ( rescale )
  {
    v7 = HIDWORD(this->pFormat[1].vfptr->__vecDelDtor);
    if ( v7 != 28 )
    {
      if ( v7 == 65 )
      {
        *rescaleBuffFromat = 9;
        *rescaleType = 4;
        goto LABEL_8;
      }
      if ( v7 != 87 )
      {
        *convert = 1;
        goto LABEL_8;
      }
    }
    *rescaleBuffFromat = 1;
    *rescaleType = 2;
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
void __fastcall Scaleform::Render::D3D1x::Texture::ReleaseHWTextures(Scaleform::Render::D3D1x::Texture *this, bool staging)
{
  bool v2; // r14
  Scaleform::Render::D3D1x::Texture *v3; // r15
  Scaleform::Render::TextureManager *v4; // rdx
  void *v5; // rax
  bool v6; // cl
  unsigned int v7; // er12
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v8; // rax
  signed __int64 v9; // rbp
  ID3D11Texture2D *v10; // rsi
  ID3D11ShaderResourceView *v11; // r13
  ID3D11Texture2D *v12; // r14
  Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *v13; // rbx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rdi
  unsigned __int64 v16; // r8
  ID3D11View **v17; // rax
  ID3D11View **v18; // rcx
  Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *v19; // rdi
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  ID3D11View **v23; // rax
  ID3D11View **v24; // rcx
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // r8
  ID3D11View **v28; // rax
  ID3D11View **v29; // rcx
  bool v30; // [rsp+60h] [rbp+8h]
  bool v31; // [rsp+68h] [rbp+10h]
  Scaleform::Render::TextureManager *v32; // [rsp+70h] [rbp+18h]

  v31 = staging;
  v2 = staging;
  v3 = this;
  Scaleform::Render::Texture::ReleaseHWTextures((Scaleform::Render::Texture *)&this->vfptr, staging);
  v4 = v3->pManagerLocks.pObject->pManager;
  v32 = v4;
  v6 = 1;
  if ( v4->RenderThreadId )
  {
    v5 = UFG::qGetCurrentThreadID();
    v4 = v32;
    if ( v5 == v32->RenderThreadId )
      v6 = 0;
  }
  v7 = 0;
  v30 = v6;
  if ( v3->TextureCount )
  {
    while ( 1 )
    {
      v8 = v3->pTextures;
      v9 = v7;
      v10 = v8[v9].pTexture;
      v11 = v8[v9].pView;
      v12 = v2 ? v8[v9].pStagingTexture : 0i64;
      if ( v10 )
        break;
LABEL_38:
      v2 = v31;
      v3->pTextures[v9].pTexture = 0i64;
      v3->pTextures[v9].pView = 0i64;
      if ( v31 )
        v3->pTextures[v9].pStagingTexture = 0i64;
      v4 = v32;
      v6 = v30;
      if ( ++v7 >= (unsigned __int8)v3->TextureCount )
        return;
    }
    if ( !v6 )
    {
      v10->vfptr->Release((IUnknown *)&v10->vfptr);
      v11->vfptr->Release((IUnknown *)&v11->vfptr);
      if ( v12 )
        v12->vfptr->Release((IUnknown *)&v12->vfptr);
      goto LABEL_38;
    }
    v13 = (Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *)&v4[2].pRTCommandQueue;
    v14 = (unsigned __int64)v4[2].pTextureCache.pObject;
    v15 = v14 + 1;
    if ( v14 + 1 >= v14 )
    {
      if ( (Scaleform::Render::TextureManagerLocks *)v15 <= v4[2].pLocks.pObject )
        goto LABEL_17;
      v16 = v15 + (v15 >> 2);
    }
    else
    {
      if ( v15 >= (_QWORD)v4[2].pLocks.pObject >> 1 )
        goto LABEL_17;
      v16 = v14 + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      v13,
      &v4[2].pRTCommandQueue,
      v16);
    v4 = v32;
LABEL_17:
    v17 = v13->Data;
    v13->Size = v15;
    v18 = &v17[v15 - 1];
    if ( v18 )
      *v18 = (ID3D11View *)v10;
    v19 = (Scaleform::ArrayDataBase<ID3D11View *,Scaleform::AllocatorLH<ID3D11View *,72>,Scaleform::ArrayConstPolicy<8,8,0> > *)&v4[2].ImageUpdates;
    v20 = v4[2].ImageUpdates.Queue.Data.Size;
    v21 = v20 + 1;
    if ( v20 + 1 >= v20 )
    {
      if ( v21 <= v4[2].ImageUpdates.Queue.Data.Policy.Capacity )
        goto LABEL_25;
      v22 = v21 + (v21 >> 2);
    }
    else
    {
      if ( v21 >= v4[2].ImageUpdates.Queue.Data.Policy.Capacity >> 1 )
        goto LABEL_25;
      v22 = v20 + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      v19,
      v19,
      v22);
LABEL_25:
    v23 = v19->Data;
    v19->Size = v21;
    v24 = &v23[v21 - 1];
    if ( v24 )
      *v24 = (ID3D11View *)&v11->vfptr;
    if ( !v12 )
      goto LABEL_38;
    v25 = v13->Size;
    v26 = v25 + 1;
    if ( v25 + 1 >= v25 )
    {
      if ( v26 <= v13->Policy.Capacity )
        goto LABEL_34;
      v27 = v26 + (v26 >> 2);
    }
    else
    {
      if ( v26 >= v13->Policy.Capacity >> 1 )
        goto LABEL_34;
      v27 = v25 + 1;
    }
    Scaleform::ArrayDataBase<ID3D11Resource *,Scaleform::AllocatorLH<ID3D11Resource *,72>,Scaleform::ArrayConstPolicy<8,8,0>>::Reserve(
      v13,
      v13,
      v27);
LABEL_34:
    v28 = v13->Data;
    v13->Size = v26;
    v29 = &v28[v26 - 1];
    if ( v29 )
      *v29 = (ID3D11View *)v12;
    goto LABEL_38;
  }
}

// File Line: 377
// RVA: 0xA0E7D0
void __fastcall Scaleform::Render::D3D1x::Texture::ApplyTexture(Scaleform::Render::D3D1x::Texture *this, __int64 stageIndex, Scaleform::Render::ImageFillMode *fm)
{
  Scaleform::Render::ImageFillMode *v3; // rdi
  __int64 v4; // r14
  Scaleform::Render::D3D1x::Texture *v5; // rbx
  unsigned __int64 v6; // rbp
  Scaleform::Render::TextureManager *v7; // rsi
  unsigned __int64 v8; // r10
  __int64 *v9; // rdx
  __int64 v10; // rdi
  ID3D11ShaderResourceView **v11; // rcx
  __int64 v12; // rax
  char v13; // dl
  char v14; // bl
  unsigned int v15; // er8
  __int64 v16; // rdi
  unsigned __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19[4]; // [rsp+20h] [rbp-B8h]
  char Src; // [rsp+40h] [rbp-98h]

  v3 = fm;
  v4 = (unsigned int)stageIndex;
  v5 = this;
  Scaleform::Render::Texture::ApplyTexture((Scaleform::Render::Texture *)&this->vfptr, stageIndex, fm);
  v6 = (unsigned __int8)v5->TextureCount;
  v7 = v5->pManagerLocks.pObject->pManager;
  v8 = *((_QWORD *)&v7[2].TextureFormats.Data.Data + (unsigned __int8)v3->Fill);
  if ( v5->TextureCount )
  {
    v9 = v19;
    v10 = (unsigned __int8)v5->TextureCount;
    v11 = &v5->pTextures->pView;
    do
    {
      v12 = (__int64)*v11;
      ++v9;
      v11 += 4;
      *(v9 - 1) = v12;
      --v10;
    }
    while ( v10 );
  }
  v13 = 0;
  v14 = 0;
  if ( (_DWORD)v6 )
  {
    memset64(&Src, v8, v6);
    v15 = v4;
    v16 = 0i64;
    v17 = v6;
    do
    {
      v18 = v19[v16];
      ++v16;
      if ( *((_QWORD *)&v7[2].Textures.Root.pNext + v15) != v8 )
        v13 = 1;
      if ( *((_QWORD *)&v7[2].DepthStencilInitQueue.Root.pNext + v15) != v18 )
        v14 = 1;
      ++v15;
      --v17;
    }
    while ( v17 );
    if ( v13 )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, char *))(**(_QWORD **)&v7[1].RefCount + 80i64))(
        *(_QWORD *)&v7[1].RefCount,
        (unsigned int)v4,
        (unsigned int)v6,
        &Src);
      memmove(&(&v7->vfptr)[v4 + 61], &Src, 8 * v6);
    }
    if ( v14 )
    {
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64 *))(**(_QWORD **)&v7[1].RefCount + 64i64))(
        *(_QWORD *)&v7[1].RefCount,
        (unsigned int)v4,
        (unsigned int)v6,
        v19);
      memmove(&(&v7->vfptr)[v4 + 65], v19, 8 * v6);
    }
  }
}

// File Line: 391
// RVA: 0xA0FEF0
bool __fastcall Scaleform::Render::D3D1x::Texture::Update(Scaleform::Render::D3D1x::Texture *this, Scaleform::Render::Texture::UpdateDesc *updates, unsigned int count, unsigned int mipLevel)
{
  Scaleform::Render::D3D1x::Texture *v4; // rbx
  __int64 v5; // rsi
  Scaleform::Render::Texture::UpdateDesc *v6; // rdi
  __int64 v7; // rax
  Scaleform::Render::ImageFormat v8; // eax
  __int64 v9; // r8
  Scaleform::Render::ImageFormat v10; // ebp
  unsigned int *v11; // rdi
  Scaleform::Render::MappedTextureBase *v12; // rcx
  unsigned int v13; // edx
  Scaleform::Render::TextureFormat *v14; // r10
  int v15; // er9
  Scaleform::Render::TextureFormat *v16; // rcx
  unsigned int v17; // edx
  unsigned int v18; // eax
  void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  Scaleform::Render::ImagePlane pplane; // [rsp+40h] [rbp-48h]
  Scaleform::Render::ImagePlane splane; // [rsp+60h] [rbp-28h]

  v4 = this;
  v5 = count;
  v6 = updates;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::D3D1x::Texture *, _QWORD, signed __int64))this->pManagerLocks.pObject->pManager->vfptr[21].__vecDelDtor)(
         this->pManagerLocks.pObject->pManager,
         this,
         mipLevel,
         1i64);
  if ( v7 )
  {
    v8 = ((unsigned int (__fastcall *)(Scaleform::Render::D3D1x::Texture *))v4->vfptr[5].__vecDelDtor)(v4);
    *(_QWORD *)&pplane.Width = 0i64;
    pplane.Pitch = 0i64;
    pplane.DataSize = 0i64;
    v10 = v8;
    pplane.pData = 0i64;
    if ( (_DWORD)v5 )
    {
      v11 = &v6->DestRect.y2;
      do
      {
        v12 = v4->pMap;
        v13 = v11[1];
        splane.Width = *(v11 - 11);
        splane.Height = *(v11 - 10);
        splane.Pitch = *(_QWORD *)(v11 - 9);
        splane.DataSize = *(_QWORD *)(v11 - 7);
        splane.pData = *(char **)(v11 - 5);
        Scaleform::Render::ImageData::GetPlane(&v12->Data, v13, &pplane);
        v14 = v4->pFormat;
        v15 = *(v11 - 2);
        v16 = v4->pFormat;
        v17 = *(v11 - 1) - *(v11 - 3);
        pplane.pData += *(v11 - 3) * LOBYTE(v14[1].vfptr->GetImageFormat) + pplane.Pitch * *(v11 - 2);
        v18 = *v11 - v15;
        splane.Width = v17;
        pplane.Width = v17;
        splane.Height = v18;
        pplane.Height = v18;
        copyScanline = v14->vfptr->GetScanlineCopyFn(v16);
        Scaleform::Render::ConvertImagePlane(&pplane, &splane, v10, v11[1], copyScanline, 0i64, 0i64);
        v11 += 14;
        --v5;
      }
      while ( v5 );
    }
    LOBYTE(v9) = 1;
    ((void (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::D3D1x::Texture *, __int64))v4->pManagerLocks.pObject->pManager->vfptr[22].__vecDelDtor)(
      v4->pManagerLocks.pObject->pManager,
      v4,
      v9);
    LOBYTE(v7) = 1;
  }
  return v7;
}

// File Line: 437
// RVA: 0xA0EF00
bool __fastcall Scaleform::Render::D3D1x::DepthStencilSurface::Initialize(Scaleform::Render::D3D1x::DepthStencilSurface *this)
{
  Scaleform::Render::D3D1x::DepthStencilSurface *v1; // rbx
  __int64 v2; // rsi
  int v3; // edx
  int Dst; // [rsp+20h] [rbp-38h]
  unsigned int v6; // [rsp+24h] [rbp-34h]
  __int64 v7; // [rsp+28h] [rbp-30h]
  __int64 v8; // [rsp+30h] [rbp-28h]
  int v9; // [rsp+3Ch] [rbp-1Ch]
  __int64 v10; // [rsp+40h] [rbp-18h]

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  memset(&Dst, 0, 0x2Cui64);
  v3 = v1->Size.Width;
  v7 = 4294967297i64;
  Dst = v3;
  v6 = v1->Size.Height;
  v8 = 4294967341i64;
  v10 = 64i64;
  v9 = 0;
  if ( (*(signed int (__fastcall **)(_QWORD, int *, _QWORD, ID3D11Texture2D **, _QWORD, signed __int64, signed __int64))(**(_QWORD **)(v2 + 176) + 40i64))(
         *(_QWORD *)(v2 + 176),
         &Dst,
         0i64,
         &v1->pDepthStencilSurface,
         *(_QWORD *)&Dst,
         4294967297i64,
         4294967341i64) < 0
    || (*(signed int (__fastcall **)(_QWORD, ID3D11Texture2D *, _QWORD, ID3D11DepthStencilView **))(**(_QWORD **)(v2 + 176)
                                                                                                  + 80i64))(
         *(_QWORD *)(v2 + 176),
         v1->pDepthStencilSurface,
         0i64,
         &v1->pDepthStencilSurfaceView) < 0 )
  {
    v1->State = 1;
  }
  else
  {
    v1->State = 2;
  }
  return v1->State == 2;
}

// File Line: 463
// RVA: 0xA0F450
char __fastcall Scaleform::Render::D3D1x::MappedTexture::Map(Scaleform::Render::D3D1x::MappedTexture *this, Scaleform::Render::Texture *ptexture, unsigned int mipLevel, unsigned int levelCount)
{
  unsigned int v4; // er15
  unsigned int v5; // er14
  Scaleform::Render::Texture *v6; // r12
  Scaleform::Render::D3D1x::MappedTexture *v7; // r13
  signed int v8; // ebx
  Scaleform::Render::ImageFormat v9; // eax
  int v10; // esi
  Scaleform::Render::ImageFormat v11; // ebx
  Scaleform::Render::ImageFormat v12; // ebx
  char result; // al
  Scaleform::Render::TextureManager *v14; // r15
  __int64 v15; // rsi
  __int64 v16; // r15
  signed __int64 v17; // rdx
  char *v18; // rdi
  unsigned int v19; // er14
  unsigned int v20; // ebx
  __int64 v21; // rax
  _QWORD *v22; // r13
  bool v23; // al
  unsigned int v24; // er12
  __int64 v25; // rdi
  __int64 v26; // rsi
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  unsigned int v29; // eax
  char v30; // bl
  __int64 v31; // [rsp+20h] [rbp-A9h]
  unsigned int plane; // [rsp+30h] [rbp-99h]
  unsigned int v33; // [rsp+34h] [rbp-95h]
  unsigned int v34; // [rsp+38h] [rbp-91h]
  __int64 v35; // [rsp+40h] [rbp-89h]
  __int64 v36; // [rsp+48h] [rbp-81h]
  Scaleform::Render::Size<unsigned long> sz; // [rsp+50h] [rbp-79h]
  __int64 v38; // [rsp+58h] [rbp-71h]
  __int64 v39; // [rsp+60h] [rbp-69h]
  __int64 v40; // [rsp+68h] [rbp-61h]
  __int64 v41; // [rsp+70h] [rbp-59h]
  __int64 v42; // [rsp+78h] [rbp-51h]
  int v43; // [rsp+80h] [rbp-49h]
  __int64 v44; // [rsp+88h] [rbp-41h]
  unsigned int v45; // [rsp+90h] [rbp-39h]
  __int64 v46; // [rsp+98h] [rbp-31h]
  __int64 v47; // [rsp+A0h] [rbp-29h]
  __int64 v48; // [rsp+A8h] [rbp-21h]
  __int64 v49; // [rsp+B0h] [rbp-19h]
  int v50; // [rsp+C0h] [rbp-9h]
  __int64 v51; // [rsp+C8h] [rbp-1h]
  __int64 v52; // [rsp+D0h] [rbp+7h]
  __int64 v53; // [rsp+D8h] [rbp+Fh]
  Scaleform::Render::D3D1x::MappedTexture *v54; // [rsp+130h] [rbp+67h]
  Scaleform::Render::Texture *v55; // [rsp+138h] [rbp+6Fh]
  unsigned int v56; // [rsp+140h] [rbp+77h]
  unsigned int v57; // [rsp+148h] [rbp+7Fh]

  v57 = levelCount;
  v56 = mipLevel;
  v55 = ptexture;
  v54 = this;
  v53 = -2i64;
  v4 = levelCount;
  v5 = mipLevel;
  v6 = ptexture;
  v7 = this;
  if ( levelCount > 4 )
  {
    v12 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[5].__vecDelDtor)(ptexture);
    Scaleform::Render::ImageData::Clear(&v7->Data);
    result = Scaleform::Render::ImageData::allocPlanes(&v7->Data, v12, v4, 1);
    if ( !result )
      return result;
  }
  else
  {
    v8 = 1;
    if ( !(ptexture->Use & 2) )
      v8 = (unsigned __int8)ptexture->MipLevels;
    v9 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))ptexture->vfptr[4].__vecDelDtor)(ptexture);
    v10 = v8 * (unsigned __int64)Scaleform::Render::ImageData::GetFormatPlaneCount(v9);
    v11 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))v6->vfptr[5].__vecDelDtor)(v6);
    Scaleform::Render::ImageData::Clear(&v7->Data);
    v7->Data.Format = v11;
    v7->Data.LevelCount = v4;
    v7->Data.pPlanes = v7->Planes;
    v7->Data.RawPlaneCount = v10;
    v7->Data.Flags |= 1u;
    v5 = v56;
    if ( v7 != (Scaleform::Render::D3D1x::MappedTexture *)-88i64 && v10 == 1 )
    {
      v7->Data.Plane0.Width = v7->Planes[0].Width;
      v7->Data.Plane0.Height = v7->Planes[0].Height;
      v7->Data.Plane0.Pitch = v7->Planes[0].Pitch;
      v7->Data.Plane0.DataSize = v7->Planes[0].DataSize;
      v7->Data.Plane0.pData = v7->Planes[0].pData;
    }
  }
  v14 = v6->pManagerLocks.pObject->pManager;
  v15 = (__int64)v14[1].vfptr;
  v35 = v15;
  if ( v15 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 8i64))(v15);
  v51 = v15;
  v16 = *(_QWORD *)&v14[1].RefCount;
  if ( v16 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 8i64))(v16);
  v52 = v16;
  v7->pTexture = v6;
  v7->StartMipLevel = v5;
  v7->LevelCount = v57;
  v34 = (unsigned __int8)v6->TextureCount;
  plane = 0;
  if ( v6->TextureCount )
  {
    v17 = 0i64;
    v36 = 0i64;
    while ( 1 )
    {
      v18 = (char *)v6[1].vfptr + v17;
      v19 = *(_DWORD *)v18;
      v20 = *((_DWORD *)v18 + 1);
      v21 = v7->StartMipLevel;
      if ( (_DWORD)v21 )
      {
        do
        {
          v19 >>= 1;
          if ( v19 < 1 )
            v19 = 1;
          v20 >>= 1;
          if ( v20 < 1 )
            v20 = 1;
          --v21;
        }
        while ( v21 );
      }
      (*(void (__fastcall **)(_QWORD, __int64 *))(**((_QWORD **)v18 + 1) + 80i64))(*((_QWORD *)v18 + 1), &v46);
      v38 = v46;
      v39 = v47;
      v40 = v48;
      v41 = v49;
      v43 = v50;
      HIDWORD(v42) = 0x10000;
      *(__int64 *)((char *)&v41 + 4) = 3i64;
      v22 = v18 + 24;
      if ( !*((_QWORD *)v18 + 3)
        && (*(signed int (__fastcall **)(__int64, __int64 *, _QWORD, char *))(*(_QWORD *)v15 + 40i64))(
             v15,
             &v38,
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
          v23 = (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v15 + 296i64))(v15) >= 40960;
          canHandleCopyResource = v23;
          checkHandleCopyResource = 1;
        }
        if ( !warned_3 )
          warned_3 = v23 == 0;
        if ( v23 )
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v16 + 376i64))(v16, *v22, *((_QWORD *)v18 + 1));
      }
      v24 = 0;
      if ( v57 )
      {
        v33 = plane;
        while ( 1 )
        {
          LODWORD(v31) = 0;
          if ( (*(signed int (__fastcall **)(__int64, _QWORD, _QWORD, signed __int64, __int64, __int64 *))(*(_QWORD *)v16 + 112i64))(
                 v16,
                 *v22,
                 v24,
                 2i64,
                 v31,
                 &v44) < 0 )
            break;
          v25 = v45;
          v26 = v44;
          sz.Width = v19;
          sz.Height = v20;
          v27 = Scaleform::Render::ImageData::GetMipLevelSize(v54->Data.Format, &sz, plane);
          v28 = (signed __int64)&v54->Data.pPlanes[v33];
          *(_DWORD *)v28 = v19;
          *(_DWORD *)(v28 + 4) = v20;
          *(_QWORD *)(v28 + 8) = v25;
          *(_QWORD *)(v28 + 16) = v27;
          *(_QWORD *)(v28 + 24) = v26;
          v19 >>= 1;
          if ( v19 < 1 )
            v19 = 1;
          v20 >>= 1;
          if ( v20 < 1 )
            v20 = 1;
          ++v24;
          v29 = v34;
          v33 += v34;
          if ( v24 >= v57 )
          {
            v15 = v35;
            goto LABEL_40;
          }
        }
        v15 = v35;
        break;
      }
      v29 = v34;
LABEL_40:
      ++plane;
      v17 = v36 + 32;
      v36 += 32i64;
      v7 = v54;
      if ( plane >= v29 )
        goto LABEL_44;
      v6 = v55;
    }
    v30 = 0;
  }
  else
  {
LABEL_44:
    v7->pTexture->pMap = (Scaleform::Render::MappedTextureBase *)&v7->vfptr;
    v30 = 1;
  }
  if ( v16 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
  if ( v15 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16i64))(v15);
  return v30;
}

// File Line: 565
// RVA: 0xA0FD20
void __fastcall Scaleform::Render::D3D1x::MappedTexture::Unmap(Scaleform::Render::D3D1x::MappedTexture *this, bool applyUpdate)
{
  bool v2; // si
  Scaleform::Render::D3D1x::MappedTexture *v3; // rdi
  Scaleform::Render::Texture *v4; // rdx
  Scaleform::Render::TextureManager *v5; // r8
  __int64 v6; // r14
  Scaleform::Render::Texture *v7; // rax
  unsigned int v8; // er15
  unsigned int v9; // er13
  __int64 v10; // rcx
  char *v11; // rbp
  int v12; // ebx
  int v13; // ebx
  unsigned int v14; // esi
  __int64 v15; // [rsp+20h] [rbp-A8h]
  __int64 v16; // [rsp+28h] [rbp-A0h]
  __int64 v17; // [rsp+38h] [rbp-90h]
  Scaleform::Render::ImagePlane pplane; // [rsp+58h] [rbp-70h]
  __int64 v19; // [rsp+D0h] [rbp+8h]
  bool v20; // [rsp+D8h] [rbp+10h]
  Scaleform::Render::Texture *v21; // [rsp+E0h] [rbp+18h]

  v20 = applyUpdate;
  v2 = applyUpdate;
  v3 = this;
  v4 = this->pTexture;
  v21 = v4;
  v5 = v4->pManagerLocks.pObject->pManager;
  v6 = *(_QWORD *)&v5[1].RefCount;
  if ( v6 )
  {
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 8i64))(*(_QWORD *)&v5[1].RefCount);
    v4 = v21;
  }
  v7 = v3->pTexture;
  v8 = (unsigned __int8)v7->TextureCount;
  v9 = 0;
  if ( v7->TextureCount )
  {
    v10 = 0i64;
    v19 = 0i64;
    do
    {
      v11 = (char *)v4[1].vfptr + v10;
      *(_QWORD *)&pplane.Width = 0i64;
      pplane.Pitch = 0i64;
      pplane.DataSize = 0i64;
      pplane.pData = 0i64;
      v12 = 0;
      if ( v3->LevelCount > 0 )
      {
        do
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v6 + 120i64))(
            v6,
            *((_QWORD *)v11 + 3),
            (unsigned int)v12++);
        while ( v12 < v3->LevelCount );
        v10 = v19;
      }
      if ( v2 )
      {
        v13 = 0;
        if ( v3->LevelCount > 0 )
        {
          v14 = v9;
          do
          {
            Scaleform::Render::ImageData::GetPlane(&v3->Data, v14, &pplane);
            if ( pplane.pData )
            {
              LODWORD(v17) = v13;
              LODWORD(v16) = 0;
              LODWORD(v15) = 0;
              (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, __int64, __int64, _QWORD, __int64, _QWORD))(*(_QWORD *)v6 + 368i64))(
                v6,
                *((_QWORD *)v11 + 1),
                v13 + v3->StartMipLevel,
                0i64,
                v15,
                v16,
                *((_QWORD *)v11 + 3),
                v17,
                0i64);
              pplane.pData = 0i64;
            }
            ++v13;
            v14 += v8;
          }
          while ( v13 < v3->LevelCount );
          v10 = v19;
          v2 = v20;
        }
      }
      ++v9;
      v10 += 32i64;
      v19 = v10;
      v4 = v21;
    }
    while ( v9 < v8 );
  }
  v3->pTexture->pMap = 0i64;
  v3->pTexture = 0i64;
  *(_QWORD *)&v3->StartMipLevel = 0i64;
  if ( v6 )
    (*(void (__fastcall **)(__int64, Scaleform::Render::Texture *))(*(_QWORD *)v6 + 16i64))(v6, v4);
}

// File Line: 608
// RVA: 0xA0DEA0
void __fastcall Scaleform::Render::D3D1x::TextureManager::TextureManager(Scaleform::Render::D3D1x::TextureManager *this, ID3D11Device *pdevice, ID3D11DeviceContext *pcontext, void *renderThreadId, Scaleform::Render::ThreadCommandQueue *commandQueue, Scaleform::Render::TextureCache *texCache)
{
  ID3D11DeviceContext *v6; // rdi
  ID3D11Device *v7; // rbx
  Scaleform::Render::D3D1x::TextureManager *v8; // rsi
  unsigned int v9; // edi
  unsigned int v10; // ebx
  signed int v11; // eax
  int Dst; // [rsp+28h] [rbp-50h]
  int v13; // [rsp+2Ch] [rbp-4Ch]
  int v14; // [rsp+30h] [rbp-48h]
  int v15; // [rsp+34h] [rbp-44h]
  int v16; // [rsp+38h] [rbp-40h]
  int v17; // [rsp+3Ch] [rbp-3Ch]
  int v18; // [rsp+40h] [rbp-38h]
  int v19; // [rsp+58h] [rbp-20h]
  signed __int64 v20; // [rsp+88h] [rbp+10h]
  signed __int64 v21; // [rsp+88h] [rbp+10h]

  v6 = pcontext;
  v7 = pdevice;
  v8 = this;
  Scaleform::Render::TextureManager::TextureManager(
    (Scaleform::Render::TextureManager *)&this->vfptr,
    renderThreadId,
    commandQueue,
    texCache);
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  v8->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  v8->pDevice = v7;
  v8->pDeviceContext = v6;
  Scaleform::Render::MappedTextureBase::MappedTextureBase((Scaleform::Render::MappedTextureBase *)&v8->MappedTexture0.vfptr);
  v8->MappedTexture0.vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::D3D1x::MappedTexture::`vftable;
  v20 = (signed __int64)&v8->D3DTextureKillList;
  *(_OWORD *)v20 = 0ui64;
  *(_QWORD *)(v20 + 16) = 0i64;
  v21 = (signed __int64)&v8->D3DTexViewKillList;
  *(_OWORD *)v21 = 0ui64;
  *(_QWORD *)(v21 + 16) = 0i64;
  Scaleform::Render::D3D1x::TextureManager::initTextureFormats(v8);
  v8->SamplerStates[0] = 0i64;
  v8->SamplerStates[1] = 0i64;
  v8->SamplerStates[2] = 0i64;
  v8->SamplerStates[3] = 0i64;
  v9 = 0;
  do
  {
    v10 = 0;
    do
    {
      memset(&Dst, 0, 0x34ui64);
      v11 = 21;
      if ( 2 * v10 != 2 )
        v11 = 0;
      Dst = v11;
      if ( v9 )
      {
        v14 = 3;
        v13 = 3;
      }
      else
      {
        v14 = 1;
        v13 = 1;
      }
      v15 = 3;
      v18 = 8;
      v19 = 2139095039;
      v16 = -1086324736;
      v17 = 1;
      ((void (__fastcall *)(ID3D11Device *, int *, signed __int64))v8->pDevice->vfptr->GSSetSamplers)(
        v8->pDevice,
        &Dst,
        (signed __int64)v8 + 8 * ((unsigned __int8)(v9 | 2 * v10++) + 57i64));
    }
    while ( v10 < 2 );
    ++v9;
  }
  while ( v9 < 2 );
}

// File Line: 647
// RVA: 0xA0E2F0
void __fastcall Scaleform::Render::D3D1x::TextureManager::~TextureManager(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::D3D1x::TextureManager *v1; // rdi
  Scaleform::Mutex *v2; // rbx
  volatile signed __int32 *v3; // rdx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
  this->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::D3D1x::TextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  v2 = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v2);
  Scaleform::Render::D3D1x::TextureManager::Reset(v1);
  v1->pLocks.pObject->pManager = 0i64;
  Scaleform::Mutex::Unlock(v2);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->D3DTexViewKillList.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->D3DTextureKillList.Data.Data);
  v1->MappedTexture0.vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  Scaleform::Render::ImageData::freePlanes(&v1->MappedTexture0.Data);
  v3 = &v1->MappedTexture0.Data.pPalette.pObject->RefCount.Value;
  if ( v3 && !_InterlockedDecrement(v3) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Render::TextureManager::~TextureManager((Scaleform::Render::TextureManager *)&v1->vfptr);
}

// File Line: 654
// RVA: 0xA0FB00
void __fastcall Scaleform::Render::D3D1x::TextureManager::Reset(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::D3D1x::TextureManager *v1; // r14
  Scaleform::Mutex *v2; // rbx
  signed __int64 v3; // rax
  unsigned int v4; // esi
  unsigned int v5; // edi
  ID3D11SamplerState *v6; // rcx

  v1 = this;
  v2 = &this->pLocks.pObject->TextureMutex;
  Scaleform::Mutex::DoLock(v2);
  while ( 1 )
  {
    v3 = (signed __int64)(v1 == (Scaleform::Render::D3D1x::TextureManager *)-128i64 ? 0i64 : &v1->TextureFormats.Data.Size);
    if ( v1->Textures.Root.pNext == (Scaleform::Render::Texture *)v3 )
      break;
    ((void (__cdecl *)(Scaleform::Render::Texture *))v1->Textures.Root.pNext->vfptr[9].__vecDelDtor)(v1->Textures.Root.pNext);
  }
  ((void (__fastcall *)(Scaleform::Render::D3D1x::TextureManager *))v1->vfptr[16].__vecDelDtor)(v1);
  v4 = 0;
  do
  {
    v5 = 0;
    do
    {
      v6 = v1->SamplerStates[(unsigned __int8)(v4 | 2 * v5)];
      if ( v6 )
        ((void (__cdecl *)(ID3D11SamplerState *))v6->vfptr->Release)(v6);
      ++v5;
    }
    while ( v5 < 2 );
    ++v4;
  }
  while ( v4 < 2 );
  v1->SamplerStates[0] = 0i64;
  v1->SamplerStates[1] = 0i64;
  v1->SamplerStates[2] = 0i64;
  v1->SamplerStates[3] = 0i64;
  v1->pDevice = 0i64;
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 684
// RVA: 0xA0FBF0
void __fastcall Scaleform::Render::D3D1x::TextureManager::SetSamplerState(Scaleform::Render::D3D1x::TextureManager *this, unsigned int stage, unsigned int viewCount, ID3D11ShaderResourceView **views, ID3D11SamplerState *state)
{
  __int64 v5; // r15
  __int64 v6; // r12
  Scaleform::Render::D3D1x::TextureManager *v7; // rsi
  char v8; // r10
  ID3D11ShaderResourceView **v9; // r13
  unsigned int v10; // er11
  ID3D11ShaderResourceView **v11; // r14
  char v12; // bl
  __int64 v13; // rbp
  ID3D11View *v14; // rax
  __int64 v15; // rdi
  char Src; // [rsp+20h] [rbp-A8h]

  if ( viewCount )
  {
    v5 = stage;
    v6 = viewCount;
    v7 = this;
    v8 = 0;
    v9 = views;
    memset64(&Src, (unsigned __int64)state, viewCount);
    v10 = stage;
    v11 = views;
    v12 = 0;
    v13 = viewCount;
    do
    {
      v14 = (ID3D11View *)*v11;
      ++v11;
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
        &Src);
      v15 = v6;
      memmove(&(&v7->vfptr)[v5 + 61], &Src, 8 * v6);
    }
    else
    {
      v15 = viewCount;
    }
    if ( v12 )
    {
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, _QWORD, ID3D11ShaderResourceView **))v7->pDeviceContext->vfptr[2].Release)(
        v7->pDeviceContext,
        (unsigned int)v5,
        (unsigned int)v6,
        v9);
      memmove(&(&v7->vfptr)[v5 + 65], v9, 8 * v15);
    }
  }
}

// File Line: 714
// RVA: 0xA0E930
void __fastcall Scaleform::Render::D3D1x::TextureManager::BeginScene(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::D3D1x::TextureManager *v1; // rbx
  ID3D11DeviceContext *v2; // rcx
  __int64 v3; // [rsp+20h] [rbp-48h]
  __int64 v4; // [rsp+28h] [rbp-40h]
  __int64 v5; // [rsp+30h] [rbp-38h]
  __int64 v6; // [rsp+38h] [rbp-30h]
  __int64 v7; // [rsp+40h] [rbp-28h]
  __int64 v8; // [rsp+48h] [rbp-20h]
  __int64 v9; // [rsp+50h] [rbp-18h]
  __int64 v10; // [rsp+58h] [rbp-10h]

  v1 = this;
  this->CurrentSamplers[0] = 0i64;
  this->CurrentSamplers[1] = 0i64;
  this->CurrentSamplers[2] = 0i64;
  this->CurrentSamplers[3] = 0i64;
  this->CurrentTextures[0] = 0i64;
  this->CurrentTextures[1] = 0i64;
  this->CurrentTextures[2] = 0i64;
  this->CurrentTextures[3] = 0i64;
  v2 = this->pDeviceContext;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int64 *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v2->vfptr[3].AddRef)(
    v2,
    0i64,
    4i64,
    &v3,
    0i64,
    0i64,
    0i64,
    0i64,
    0i64,
    0i64,
    0i64,
    0i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int64 *))v1->pDeviceContext->vfptr[2].Release)(
    v1->pDeviceContext,
    0i64,
    4i64,
    &v7);
}

// File Line: 801
// RVA: 0xA10170
void __fastcall Scaleform::Render::D3D1x::TextureManager::initTextureFormats(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::D3D1x::TextureManager *v1; // rbp
  D3D_FEATURE_LEVEL v2; // er15
  Scaleform::Render::D3D1x::TextureFormat::Mapping *v3; // rbx
  Scaleform::Render::TextureFormat *v4; // rax
  Scaleform::Render::TextureFormat *v5; // r14
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::Render::TextureFormat **v8; // rcx
  Scaleform::Render::D3D1x::TextureFormat::Mapping *i; // rcx
  char v10; // [rsp+88h] [rbp+10h]
  int v11; // [rsp+90h] [rbp+18h]
  Scaleform::Render::TextureFormat *v12; // [rsp+98h] [rbp+20h]

  v1 = this;
  v2 = ((unsigned int (__cdecl *)(ID3D11Device *))this->pDevice->vfptr->GenerateMips)(this->pDevice);
  v3 = Scaleform::Render::D3D1x::TextureFormatMapping;
  if ( Scaleform::Render::D3D1x::TextureFormatMapping[0].Format )
  {
    while ( v2 < v3->MinFeatureLevel
         || ((signed int (__fastcall *)(ID3D11Device *, _QWORD, char *))v1->pDevice->vfptr->RSSetState)(
              v1->pDevice,
              *(unsigned int *)v3->D3DFormat,
              &v10) < 0
         || !(v10 & 0x20) )
    {
LABEL_18:
      ++v3;
      if ( v3->Format == Image_None )
        return;
    }
    v11 = 72;
    v4 = (Scaleform::Render::TextureFormat *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               v1,
                                               24ui64,
                                               (Scaleform::AllocInfo *)&v11);
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
    v6 = v1->TextureFormats.Data.Size + 1;
    if ( v6 >= v1->TextureFormats.Data.Size )
    {
      if ( v6 > v1->TextureFormats.Data.Policy.Capacity )
      {
        v7 = v6 + (v6 >> 2);
        goto LABEL_13;
      }
    }
    else if ( v6 < v1->TextureFormats.Data.Policy.Capacity >> 1 )
    {
      v7 = v1->TextureFormats.Data.Size + 1;
LABEL_13:
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->TextureFormats,
        &v1->TextureFormats,
        v7);
      goto LABEL_14;
    }
LABEL_14:
    v1->TextureFormats.Data.Size = v6;
    v8 = &v1->TextureFormats.Data.Data[v6 - 1];
    if ( v8 )
      *v8 = v5;
    for ( i = v3 + 1; i->Format == v3->Format; ++i )
      v3 = i;
    goto LABEL_18;
  }
}

// File Line: 844
// RVA: 0xA10450
void __fastcall Scaleform::Render::D3D1x::TextureManager::processTextureKillList(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::D3D1x::TextureManager *v1; // rbx
  unsigned int v2; // edi
  __int64 v3; // rcx
  unsigned int v4; // edi
  __int64 v5; // rcx
  signed __int64 v6; // rdi
  void *v7; // rax
  signed __int64 v8; // rbx
  void *v9; // rax
  int v10; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = 0;
  if ( this->D3DTexViewKillList.Data.Size )
  {
    v3 = 0i64;
    do
    {
      ((void (*)(void))v1->D3DTexViewKillList.Data.Data[v3]->vfptr->Release)();
      v3 = ++v2;
    }
    while ( v2 < v1->D3DTexViewKillList.Data.Size );
  }
  v4 = 0;
  if ( v1->D3DTextureKillList.Data.Size > 0 )
  {
    v5 = 0i64;
    do
    {
      ((void (*)(void))v1->D3DTextureKillList.Data.Data[v5]->vfptr->Release)();
      v5 = ++v4;
    }
    while ( v4 < v1->D3DTextureKillList.Data.Size );
  }
  v6 = (signed __int64)&v1->D3DTexViewKillList;
  if ( v1->D3DTexViewKillList.Data.Size > 0 && v1->D3DTexViewKillList.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( *(_QWORD *)v6 )
    {
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, *(void **)v6, 64ui64);
    }
    else
    {
      v10 = 72;
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
             Scaleform::Memory::pGlobalHeap,
             &v1->D3DTexViewKillList,
             64ui64,
             (Scaleform::AllocInfo *)&v10);
    }
    *(_QWORD *)v6 = v7;
    v1->D3DTexViewKillList.Data.Policy.Capacity = 8i64;
  }
  v8 = (signed __int64)&v1->D3DTextureKillList;
  *(_QWORD *)(v6 + 8) = 0i64;
  if ( *(_QWORD *)(v8 + 8) > 0ui64 && *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( *(_QWORD *)v8 )
    {
      v9 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, *(void **)v8, 64ui64);
    }
    else
    {
      v10 = 72;
      v9 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
             Scaleform::Memory::pGlobalHeap,
             (const void *)v8,
             64ui64,
             (Scaleform::AllocInfo *)&v10);
    }
    *(_QWORD *)v8 = v9;
    *(_QWORD *)(v8 + 16) = 8i64;
  }
  *(_QWORD *)(v8 + 8) = 0i64;
}

// File Line: 854
// RVA: 0xA10300
void __fastcall Scaleform::Render::D3D1x::TextureManager::processInitTextures(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *v1; // rsi
  Scaleform::Render::D3D1x::TextureManager *v2; // rdi
  Scaleform::Render::Texture *v3; // rax
  char **v4; // rax
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *v5; // rcx
  signed __int64 v6; // rax
  Scaleform::Render::Texture *v7; // rbx
  Scaleform::RefCountImplCoreVtbl *v8; // rax
  signed __int64 v9; // rax
  Scaleform::Render::DepthStencilSurface *v10; // rcx
  Scaleform::RefCountImplCoreVtbl *v11; // rax

  v1 = &this->TextureInitQueue;
  v2 = this;
  v3 = (Scaleform::Render::Texture *)&this->Textures;
  if ( this == (Scaleform::Render::D3D1x::TextureManager *)-144i64 )
    v3 = 0i64;
  if ( this->TextureInitQueue.Root.pNext != v3 )
    goto LABEL_19;
  v4 = (char **)&this->DepthStencilInitQueue;
  v5 = &this->TextureInitQueue;
  if ( !v4 )
    v5 = 0i64;
  if ( v4[1] != (char *)v5 )
  {
LABEL_19:
    while ( 1 )
    {
      v6 = (signed __int64)&v1[-1];
      if ( !v1 )
        v6 = 0i64;
      if ( v1->Root.pNext == (Scaleform::Render::Texture *)v6 )
        break;
      v7 = v2->TextureInitQueue.Root.pNext;
      v7->pPrev->pNext = v7->pNext;
      v7->pNext->pPrev = v7->pPrev;
      v7->pPrev = (Scaleform::Render::Texture *)-1i64;
      v7->pNext = (Scaleform::Render::Texture *)-1i64;
      v8 = v7->vfptr;
      v7->pNext = 0i64;
      v7->pPrev = 0i64;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *))v8[1].__vecDelDtor)(v7) )
      {
        v7->pPrev = v2->Textures.Root.pPrev;
        v7->pNext = (Scaleform::Render::Texture *)&v2->TextureFormats.Data.Size;
        v2->Textures.Root.pPrev->pNext = v7;
        v2->Textures.Root.pPrev = v7;
      }
    }
    while ( 1 )
    {
      v9 = (signed __int64)&v2->TextureInitQueue;
      if ( v2 == (Scaleform::Render::D3D1x::TextureManager *)-160i64 )
        v9 = 0i64;
      if ( v2->DepthStencilInitQueue.Root.pNext == (Scaleform::Render::DepthStencilSurface *)v9 )
        break;
      v10 = v2->DepthStencilInitQueue.Root.pNext;
      v10->pPrev->pNext = v10->pNext;
      v10->pNext->pPrev = v10->pPrev;
      v10->pPrev = (Scaleform::Render::DepthStencilSurface *)-1i64;
      v10->pNext = (Scaleform::Render::DepthStencilSurface *)-1i64;
      v11 = v10->vfptr;
      v10->pNext = 0i64;
      v10->pPrev = 0i64;
      ((void (*)(void))v11[3].__vecDelDtor)();
    }
    Scaleform::WaitCondition::NotifyAll(&v2->pLocks.pObject->TextureInitWC);
  }
}

// File Line: 883
// RVA: 0xA0EC40
Scaleform::Render::Texture *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateTexture(Scaleform::Render::D3D1x::TextureManager *this, Scaleform::Render::ImageFormat format, unsigned int mipLevels, Scaleform::Render::Size<unsigned long> *size, unsigned int use, Scaleform::Render::ImageBase *pimage)
{
  Scaleform::Render::Size<unsigned long> *v6; // r14
  unsigned int v7; // er15
  Scaleform::Render::D3D1x::TextureManager *v8; // rbx
  Scaleform::Render::D3D1x::TextureFormat *v10; // rbp
  Scaleform::Render::D3D1x::Texture *v11; // rax
  int v12; // [rsp+40h] [rbp-38h]
  __int64 v13; // [rsp+48h] [rbp-30h]
  Scaleform::Render::D3D1x::Texture *v14; // [rsp+50h] [rbp-28h]

  v13 = -2i64;
  v6 = size;
  v7 = mipLevels;
  v8 = this;
  if ( !this->pDevice )
    return 0i64;
  v10 = (Scaleform::Render::D3D1x::TextureFormat *)Scaleform::Render::TextureManager::precreateTexture(
                                                     (Scaleform::Render::TextureManager *)&this->vfptr,
                                                     format,
                                                     use,
                                                     pimage);
  if ( !v10 )
    return 0i64;
  v12 = 72;
  v11 = (Scaleform::Render::D3D1x::Texture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               v8,
                                               128ui64,
                                               (Scaleform::AllocInfo *)&v12);
  v14 = v11;
  if ( v11 )
    Scaleform::Render::D3D1x::Texture::Texture(v11, v8->pLocks.pObject, v10, v7, v6, use, pimage);
  return Scaleform::Render::TextureManager::postCreateTexture(
           (Scaleform::Render::TextureManager *)&v8->vfptr,
           (Scaleform::Render::Texture *)&v11->vfptr,
           use);
}

// File Line: 903
// RVA: 0xA0EB90
Scaleform::Render::Texture *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateTexture(Scaleform::Render::D3D1x::TextureManager *this, ID3D11Texture2D *pd3dtexture, Scaleform::Render::Size<unsigned long> imgSize, Scaleform::Render::ImageBase *image)
{
  Scaleform::Render::ImageBase *v4; // rbp
  unsigned int *v5; // rsi
  ID3D11Texture2D *v6; // rdi
  Scaleform::Render::D3D1x::TextureManager *v7; // rbx
  Scaleform::Render::D3D1x::Texture *v9; // rax
  unsigned int v10; // edx
  Scaleform::Render::Size<unsigned long> size; // [rsp+30h] [rbp-38h]
  __int64 v12; // [rsp+38h] [rbp-30h]
  Scaleform::Render::D3D1x::Texture *v13; // [rsp+40h] [rbp-28h]
  int v14; // [rsp+78h] [rbp+10h]

  v12 = -2i64;
  v4 = image;
  v5 = (unsigned int *)imgSize;
  v6 = pd3dtexture;
  v7 = this;
  if ( !pd3dtexture )
    return 0i64;
  v14 = 72;
  v9 = (Scaleform::Render::D3D1x::Texture *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              128ui64,
                                              (Scaleform::AllocInfo *)&v14);
  v13 = v9;
  if ( v9 )
  {
    v10 = v5[1];
    size.Width = *v5;
    size.Height = v10;
    Scaleform::Render::D3D1x::Texture::Texture(
      v9,
      v7->pLocks.pObject,
      v6,
      (Scaleform::Render::Size<unsigned long>)&size,
      v4);
  }
  return Scaleform::Render::TextureManager::postCreateTexture(
           (Scaleform::Render::TextureManager *)&v7->vfptr,
           (Scaleform::Render::Texture *)&v9->vfptr,
           0);
}

// File Line: 913
// RVA: 0xA0EDA0
__int64 __fastcall Scaleform::Render::D3D1x::TextureManager::GetTextureUseCaps(Scaleform::Render::D3D1x::TextureManager *this, Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::D3D1x::TextureManager *v2; // rdi
  unsigned int v3; // ebx
  __int64 result; // rax

  v2 = this;
  v3 = 272;
  if ( (format & 0xFFFu) - 50 > 0xF )
    v3 = 306;
  result = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::TextureManager *))this->vfptr[18].__vecDelDtor)(this);
  if ( result )
  {
    if ( v2->vfptr[19].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, result) )
      v3 |= 0x80u;
    result = v3;
  }
  return result;
}

// File Line: 928
// RVA: 0xA0E9D0
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(Scaleform::Render::D3D1x::TextureManager *this, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::MemoryManager *manager)
{
  Scaleform::Render::Size<unsigned long> *v3; // rsi
  Scaleform::Render::D3D1x::TextureManager *v4; // rdi
  Scaleform::Render::DepthStencilSurface *v6; // rax
  Scaleform::Render::DepthStencilSurface *v7; // rbx
  int v8; // [rsp+58h] [rbp+20h]

  v3 = size;
  v4 = this;
  if ( !this->pDevice )
    return 0i64;
  v8 = 72;
  v6 = (Scaleform::Render::DepthStencilSurface *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::D3D1x::TextureManager *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   72i64,
                                                   &v8,
                                                   -2i64);
  v7 = v6;
  if ( v6 )
  {
    Scaleform::Render::DepthStencilSurface::DepthStencilSurface(v6, v4->pLocks.pObject, v3);
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::DepthStencilSurface::`vftable;
    v7[1].vfptr = 0i64;
    *(_QWORD *)&v7[1].RefCount = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  return Scaleform::Render::TextureManager::postCreateDepthStencilSurface(
           (Scaleform::Render::TextureManager *)&v4->vfptr,
           v7);
}

// File Line: 941
// RVA: 0xA0EA80
Scaleform::Render::DepthStencilSurface *__fastcall Scaleform::Render::D3D1x::TextureManager::CreateDepthStencilSurface(Scaleform::Render::D3D1x::TextureManager *this, ID3D11Texture2D *psurface)
{
  ID3D11Texture2D *v2; // rdi
  Scaleform::Render::D3D1x::TextureManager *v3; // rsi
  __int64 v5; // rbx
  int v6; // ebp
  int v7; // er14
  Scaleform::GFx::Resource *v8; // rsi
  int v9; // [rsp+28h] [rbp-60h]
  int v10; // [rsp+2Ch] [rbp-5Ch]
  int v11; // [rsp+98h] [rbp+10h]
  __int64 v12; // [rsp+A0h] [rbp+18h]

  v2 = psurface;
  v3 = this;
  if ( !psurface )
    return 0i64;
  psurface->vfptr->AddRef((IUnknown *)psurface);
  ((void (__fastcall *)(ID3D11Texture2D *, int *))v2->vfptr[3].AddRef)(v2, &v9);
  v11 = 72;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::D3D1x::TextureManager *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         v3,
         72i64,
         &v11,
         -2i64);
  v12 = v5;
  if ( v5 )
  {
    v6 = v9;
    v7 = v10;
    v8 = (Scaleform::GFx::Resource *)v3->pLocks.pObject;
    *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v5 + 8) = 1;
    *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::Render::DepthStencilSurface,72>::`vftable;
    *(_QWORD *)v5 = &Scaleform::Render::DepthStencilSurface::`vftable;
    if ( v8 )
      Scaleform::Render::RenderBuffer::AddRef(v8);
    *(_QWORD *)(v5 + 32) = v8;
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
  *(_QWORD *)(v5 + 56) = v2;
  *(_DWORD *)(v5 + 40) = 2;
  return (Scaleform::Render::DepthStencilSurface *)v5;
}

