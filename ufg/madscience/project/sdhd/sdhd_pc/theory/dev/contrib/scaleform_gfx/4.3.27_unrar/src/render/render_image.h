// File Line: 500
// RVA: 0x8973E0
void __fastcall Scaleform::Render::ImageData::ImageData(Scaleform::Render::ImageData *this)
{
  *(_QWORD *)&this->Format = 0i64;
  *(_DWORD *)&this->Flags = 0x10000;
  this->pPlanes = &this->Plane0;
  this->pPalette.pObject = 0i64;
  *(_QWORD *)&this->Plane0.Width = 0i64;
  this->Plane0.Pitch = 0i64;
  this->Plane0.DataSize = 0i64;
  this->Plane0.pData = 0i64;
}

// File Line: 518
// RVA: 0x8A4E60
void __fastcall Scaleform::Render::ImageData::~ImageData(Scaleform::Render::ImageData *this)
{
  Scaleform::Render::ImageData *v1; // rbx
  volatile signed __int32 *v2; // rdx

  v1 = this;
  Scaleform::Render::ImageData::freePlanes(this);
  v2 = &v1->pPalette.pObject->RefCount.Value;
  if ( v2 )
  {
    if ( !_InterlockedDecrement(v2) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 549
// RVA: 0x994040
void __fastcall Scaleform::Render::ImageData::Initialize(Scaleform::Render::ImageData *this, Scaleform::Render::ImageFormat format, unsigned int mipLevels, Scaleform::Render::ImagePlane *pplanes, unsigned int planeCount, bool separateMipmaps)
{
  Scaleform::Render::ImagePlane *v6; // r14
  char v7; // di
  Scaleform::Render::ImageFormat v8; // ebx
  Scaleform::Render::ImageData *v9; // rsi

  v6 = pplanes;
  v7 = mipLevels;
  v8 = format;
  v9 = this;
  Scaleform::Render::ImageData::Clear(this);
  v9->Format = v8;
  v9->LevelCount = v7;
  v9->RawPlaneCount = planeCount;
  v9->pPlanes = v6;
  if ( separateMipmaps )
    v9->Flags |= 1u;
  if ( v6 )
  {
    if ( planeCount == 1 )
    {
      v9->Plane0.Width = v6->Width;
      v9->Plane0.Height = v6->Height;
      v9->Plane0.Pitch = v6->Pitch;
      v9->Plane0.DataSize = v6->DataSize;
      v9->Plane0.pData = v6->pData;
    }
  }
}

// File Line: 735
// RVA: 0x9464E0
void __fastcall Scaleform::Render::TextureManagerLocks::TextureManagerLocks(Scaleform::Render::TextureManagerLocks *this, Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManagerLocks *v2; // rbx

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureManagerLocks,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManagerLocks::`vftable;
  this->pManager = pmanager;
  Scaleform::Lock::Lock(&this->ImageLock, 0);
  Scaleform::Mutex::Mutex(&v2->TextureMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v2->TextureInitWC);
}

// File Line: 750
// RVA: 0xA0DB90
void __fastcall Scaleform::Render::MappedTextureBase::MappedTextureBase(Scaleform::Render::MappedTextureBase *this)
{
  Scaleform::Render::MappedTextureBase *v1; // rdx
  Scaleform::Render::ImagePlane *v2; // rcx
  Scaleform::Render::ImageData *v3; // [rsp+28h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  this->pTexture = 0i64;
  *(_QWORD *)&this->StartMipLevel = 0i64;
  v3 = &this->Data;
  *(_QWORD *)&v3->Format = 0i64;
  *(_DWORD *)&v3->Flags = 0x10000;
  v2 = &this->Data.Plane0;
  v3->pPlanes = v2;
  v3->pPalette.pObject = 0i64;
  *(_QWORD *)&v2->Width = 0i64;
  v2->Pitch = 0i64;
  v2->DataSize = 0i64;
  v2->pData = 0i64;
  *(_QWORD *)&v1->Planes[0].Width = 0i64;
  v1->Planes[0].Pitch = 0i64;
  v1->Planes[0].DataSize = 0i64;
  v1->Planes[0].pData = 0i64;
  *(_QWORD *)&v1->Planes[1].Width = 0i64;
  v1->Planes[1].Pitch = 0i64;
  v1->Planes[1].DataSize = 0i64;
  v1->Planes[1].pData = 0i64;
  *(_QWORD *)&v1->Planes[2].Width = 0i64;
  v1->Planes[2].Pitch = 0i64;
  v1->Planes[2].DataSize = 0i64;
  v1->Planes[2].pData = 0i64;
  *(_QWORD *)&v1->Planes[3].Width = 0i64;
  v1->Planes[3].Pitch = 0i64;
  v1->Planes[3].DataSize = 0i64;
  v1->Planes[3].pData = 0i64;
}

// File Line: 753
// RVA: 0xA0E160
void __fastcall Scaleform::Render::MappedTextureBase::~MappedTextureBase(Scaleform::Render::MappedTextureBase *this)
{
  Scaleform::Render::ImageData *v1; // rbx
  volatile signed __int32 *v2; // rdx

  this->vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  v1 = &this->Data;
  Scaleform::Render::ImageData::freePlanes(&this->Data);
  v2 = &v1->pPalette.pObject->RefCount.Value;
  if ( v2 )
  {
    if ( !_InterlockedDecrement(v2) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 814
// RVA: 0xA0DDC0
void __fastcall Scaleform::Render::Texture::Texture(Scaleform::Render::Texture *this, Scaleform::Render::TextureManagerLocks *pmanagerLocks, Scaleform::Render::Size<unsigned long> *size, char mipLevels, unsigned __int16 use, Scaleform::Render::ImageBase *pimage, Scaleform::Render::TextureFormat *pformat)
{
  char v7; // bp
  Scaleform::Render::Size<unsigned long> *v8; // rsi
  Scaleform::Render::TextureManagerLocks *v9; // rdi
  Scaleform::Render::Texture *v10; // rbx
  unsigned int v11; // ecx

  v7 = mipLevels;
  v8 = size;
  v9 = pmanagerLocks;
  v10 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Texture,72>::`vftable;
  this->pPrev = 0i64;
  this->pNext = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  if ( pmanagerLocks )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pmanagerLocks);
  v10->pManagerLocks.pObject = v9;
  v10->pImage = pimage;
  v11 = v8->Height;
  v10->ImgSize.Width = v8->Width;
  v10->ImgSize.Height = v11;
  v10->State = 0;
  v10->MipLevels = v7;
  v10->TextureCount = 1;
  v10->Use = use;
  v10->TextureFlags = 0;
  v10->pMap = 0i64;
  v10->pFormat = pformat;
}

// File Line: 816
// RVA: 0xA0E2A0
void __fastcall Scaleform::Render::Texture::~Texture(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  v2 = (Scaleform::Render::RenderBuffer *)this->pManagerLocks.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 844
// RVA: 0xA0EE60
void __fastcall Scaleform::Render::Texture::GetUVGenMatrix(Scaleform::Render::Texture *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  float v2; // xmm1_4
  float v3; // xmm0_4

  v2 = 1.0 / (float)(signed int)this->ImgSize.Width;
  v3 = (float)(signed int)this->ImgSize.Height;
  *(_OWORD *)&mat->M[0][1] = 0ui64;
  *(_QWORD *)&mat->M[1][2] = 0i64;
  mat->M[0][0] = v2;
  mat->M[1][1] = 1.0 / v3;
}

// File Line: 852
// RVA: 0xA0EEB0
void __fastcall Scaleform::Render::Texture::ImageLost(Scaleform::Render::Texture *this)
{
  Scaleform::Render::Texture *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  v2 = &this->pManagerLocks.pObject->ImageLock.cs;
  EnterCriticalSection(v2);
  v1->pImage = 0i64;
  LeaveCriticalSection(v2);
}

// File Line: 964
// RVA: 0xA0DAF0
void __fastcall Scaleform::Render::DepthStencilSurface::DepthStencilSurface(Scaleform::Render::DepthStencilSurface *this, Scaleform::Render::TextureManagerLocks *pmanagerLocks, Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::Size<unsigned long> *v3; // rsi
  Scaleform::Render::TextureManagerLocks *v4; // rdi
  Scaleform::Render::DepthStencilSurface *v5; // rbx
  unsigned int v6; // ecx

  v3 = size;
  v4 = pmanagerLocks;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DepthStencilSurface,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DepthStencilSurface::`vftable;
  if ( pmanagerLocks )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pmanagerLocks);
  v5->pManagerLocks.pObject = v4;
  v5->State = 0;
  v6 = v3->Height;
  v5->Size.Width = v3->Width;
  v5->Size.Height = v6;
}

// File Line: 966
// RVA: 0xA0ED70
Scaleform::Render::TextureManager *__fastcall Scaleform::Render::DepthStencilSurface::GetTextureManager(Scaleform::Render::DepthStencilSurface *this)
{
  Scaleform::Render::TextureManager *result; // rax

  result = (Scaleform::Render::TextureManager *)this->pManagerLocks.pObject;
  if ( result )
    result = (Scaleform::Render::TextureManager *)result->vfptr;
  return result;
}

// File Line: 989
// RVA: 0x94B170
void __fastcall Scaleform::Render::ImageUpdateSync::~ImageUpdateSync(Scaleform::Render::ImageUpdateSync *this)
{
  this->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&Scaleform::Render::ImageUpdateSync::`vftable;
}

// File Line: 1105
// RVA: 0x95DC20
bool __fastcall Scaleform::Render::TextureManager::CanCreateTextureCurrentThread(Scaleform::Render::TextureManager *this)
{
  return !this->RenderThreadId || UFG::qGetCurrentThreadID() == this->RenderThreadId;
}

// File Line: 1130
// RVA: 0x9976A0
bool __fastcall Scaleform::Render::TextureManager::IsDrawableImageFormat(Scaleform::Render::TextureManager *this, Scaleform::Render::ImageFormat format)
{
  return format == 1;
}

// File Line: 1171
// RVA: 0x9E96C0
Scaleform::Render::MappedTextureBase *__fastcall Scaleform::Render::TextureManager::mapTexture(Scaleform::Render::TextureManager *this, Scaleform::Render::Texture *p)
{
  return (Scaleform::Render::MappedTextureBase *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, _QWORD, _QWORD))this->vfptr[21].__vecDelDtor)(
                                                   this,
                                                   p,
                                                   0i64,
                                                   (unsigned __int8)p->MipLevels);
}

// File Line: 1291
// RVA: 0x6C91A0
void __fastcall Scaleform::Render::Image::Image(Scaleform::Render::Image *this, Scaleform::Render::Texture *ptexture, Scaleform::Render::ImageUpdateSync *psync)
{
  Scaleform::Render::Texture *volatile v3; // rt1
  Scaleform::Render::Texture *volatile v4; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = ptexture;
  v3 = this->pTexture.Value;
  v4 = this->pTexture.Value;
  this->pUpdateSync = psync;
  this->pInverseMatrix = 0i64;
  if ( ptexture )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ptexture);
}

// File Line: 1324
// RVA: 0x6F5100
Scaleform::Render::Rect<unsigned long> *__fastcall Scaleform::Render::ImageBase::GetRect(Scaleform::Render::ImageBase *this, Scaleform::Render::Rect<unsigned long> *result)
{
  Scaleform::Render::Rect<unsigned long> *v2; // rbx
  unsigned int *v3; // rax
  unsigned int v4; // ecx
  char v6; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = (unsigned int *)this->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)this, (unsigned int)&v6);
  *(_QWORD *)&v2->x1 = 0i64;
  v4 = *v3;
  v2->y2 = v3[1];
  v2->x2 = v4;
  return v2;
}

// File Line: 1377
// RVA: 0x722E60
char __fastcall Scaleform::Render::Image::Update(Scaleform::Render::Image *this)
{
  Scaleform::Render::Image *v1; // rdx
  Scaleform::Render::ImageUpdateSync *v2; // rcx

  v1 = this;
  v2 = this->pUpdateSync;
  if ( !v2 )
    return 0;
  v2->vfptr->UpdateImage(v2, v1);
  return 1;
}

// File Line: 1387
// RVA: 0x722E30
char __fastcall Scaleform::Render::Image::Update(Scaleform::Render::Image *this, Scaleform::Render::ImageUpdate *pupdate)
{
  Scaleform::Render::ImageUpdateSync *v2; // rcx

  v2 = this->pUpdateSync;
  if ( !v2 )
    return 0;
  v2->vfptr->UpdateImage(v2, pupdate);
  return 1;
}

// File Line: 1433
// RVA: 0x721220
void __fastcall Scaleform::Render::Image::TextureLost(Scaleform::Render::Image *this, Scaleform::Render::Image::TextureLossReason reason)
{
  JUMPOUT(reason, 0, Scaleform::Render::TextureImage::TextureLost);
}

// File Line: 1459
// RVA: 0x6EFC00
__int64 __fastcall Scaleform::Render::ImageDelegate::GetImageType(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[3].__vecDelDtor)();
}

// File Line: 1460
// RVA: 0x6EFB20
__int64 __fastcall Scaleform::Render::ImageDelegate::GetFormat(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[4].__vecDelDtor)();
}

// File Line: 1461
// RVA: 0x6F53C0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::SubImage::GetSize(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Size<unsigned long> *result)
{
  Scaleform::Render::Size<unsigned long> *v2; // rbx

  v2 = result;
  ((void (*)(void))this->pImage.pObject->vfptr[5].__vecDelDtor)();
  return v2;
}

// File Line: 1462
// RVA: 0x6F5130
Scaleform::Render::Rect<unsigned long> *__fastcall Scaleform::Render::ImageDelegate::GetRect(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Rect<unsigned long> *result)
{
  Scaleform::Render::Rect<unsigned long> *v2; // rbx

  v2 = result;
  ((void (*)(void))this->pImage.pObject->vfptr[6].__vecDelDtor)();
  return v2;
}

// File Line: 1466
// RVA: 0x715180
void __fastcall Scaleform::Render::ImageDelegate::SetMatrix(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::MemoryHeap *heap)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[13].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    heap);
}

// File Line: 1467
// RVA: 0x6EFE60
void __fastcall Scaleform::Render::ImageDelegate::GetMatrix(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  this->pImage.pObject->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)this->pImage.pObject, (unsigned int)mat);
}

// File Line: 1469
// RVA: 0x715190
void __fastcall Scaleform::Render::ImageDelegate::SetMatrixInverse(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::MemoryHeap *heap)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[15].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    heap);
}

// File Line: 1470
// RVA: 0x6EFE70
__int64 __fastcall Scaleform::Render::ImageDelegate::GetMatrixInverse(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat)
{
  return this->pImage.pObject->vfptr[16].__vecDelDtor(
           (Scaleform::RefCountImplCore *)this->pImage.pObject,
           (unsigned int)mat);
}

// File Line: 1472
// RVA: 0x6F7280
void __fastcall Scaleform::Render::ImageDelegate::GetUVGenMatrix(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::Render::TextureManager *manager)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::TextureManager *))this->pImage.pObject->vfptr[22].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    manager);
}

// File Line: 1474
// RVA: 0x6F7290
void __fastcall Scaleform::Render::ImageDelegate::GetUVNormMatrix(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Matrix2x4<float> *mat, Scaleform::Render::TextureManager *manager)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::TextureManager *))this->pImage.pObject->vfptr[23].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    manager);
}

// File Line: 1487
// RVA: 0x6F72A0
__int64 __fastcall Scaleform::Render::SubImage::GetUse(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[12].__vecDelDtor)();
}

// File Line: 1489
// RVA: 0x6E1930
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageDelegate::CreateSubImage(Scaleform::Render::ImageDelegate *this, Scaleform::Render::Rect<unsigned long> *rect, Scaleform::MemoryHeap *pheap)
{
  return (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Rect<unsigned long> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[11].__vecDelDtor)(
                                       this->pImage.pObject,
                                       rect,
                                       pheap);
}

// File Line: 1492
// RVA: 0x703060
__int64 __fastcall Scaleform::Render::ImageDelegate::Map(Scaleform::Render::ImageDelegate *this, Scaleform::Render::ImageData *pdata, __int64 levelIndex, __int64 levelCount)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, __int64, __int64))this->pImage.pObject->vfptr[17].__vecDelDtor)(
           this->pImage.pObject,
           pdata,
           levelIndex,
           levelCount);
}

// File Line: 1493
// RVA: 0x722B90
__int64 __fastcall Scaleform::Render::ImageDelegate::Unmap(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[18].__vecDelDtor)();
}

// File Line: 1497
// RVA: 0x721230
void __fastcall Scaleform::Render::ImageDelegate::TextureLost(Scaleform::Render::ImageDelegate *this, __int64 reason)
{
  this->pImage.pObject->vfptr[24].__vecDelDtor((Scaleform::RefCountImplCore *)this->pImage.pObject, reason);
}

// File Line: 1499
// RVA: 0x722EA0
__int64 __fastcall Scaleform::Render::ImageDelegate::Update(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[20].__vecDelDtor)();
}

// File Line: 1500
// RVA: 0x722E90
__int64 __fastcall Scaleform::Render::ImageDelegate::Update(Scaleform::Render::ImageDelegate *this, Scaleform::Render::ImageUpdate *pupdate)
{
  return this->pImage.pObject->vfptr[19].__vecDelDtor(
           (Scaleform::RefCountImplCore *)this->pImage.pObject,
           (unsigned int)pupdate);
}

// File Line: 1502
// RVA: 0x6EE6A0
const char *__fastcall Scaleform::GFx::FontManagerStates::GetStateBagImpl(LOCALNAMESPACE::hkNativeResource *this)
{
  return this->m_contentsTypeName;
}

// File Line: 1503
// RVA: 0x6EE6B0
Scaleform::Render::MemoryBufferImage *__fastcall Scaleform::Render::ImageDelegate::GetAsMemoryImage(Scaleform::Render::ImageDelegate *this)
{
  return (Scaleform::Render::MemoryBufferImage *)((__int64 (*)(void))this->pImage.pObject->vfptr[25].__vecDelDtor)();
}

// File Line: 1563
// RVA: 0x89F8A0
void __fastcall Scaleform::Render::WrapperImageSource::WrapperImageSource(Scaleform::Render::WrapperImageSource *this, Scaleform::Render::Image *pdelegate)
{
  Scaleform::Render::Image *v2; // rdi
  Scaleform::Render::WrapperImageSource *v3; // rbx

  v2 = pdelegate;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageSource::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::WrapperImageSource::`vftable;
  if ( pdelegate )
    ((void (__fastcall *)(Scaleform::Render::Image *))pdelegate->vfptr[1].__vecDelDtor)(pdelegate);
  v3->pDelegate.pObject = v2;
}

// File Line: 1566
// RVA: 0x8D8D20
__int64 __fastcall Scaleform::Render::WrapperImageSource::GetFormat(hkSubStreamWriter *this, const void *buf, __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamWriter *, const void *, __int64))this->m_childStream->vfptr[2].__vecDelDtor)(
           this->m_childStream,
           buf,
           nbytes);
}

// File Line: 1567
// RVA: 0x8DE220
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::WrapperImageSource::GetSize(Scaleform::Render::WrapperImageSource *this, Scaleform::Render::Size<unsigned long> *result)
{
  Scaleform::Render::Size<unsigned long> *v2; // rbx

  v2 = result;
  ((void (*)(void))this->pDelegate.pObject->vfptr[5].__vecDelDtor)();
  return v2;
}

// File Line: 1576
// RVA: 0x8BF0F0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::WrapperImageSource::CreateCompatibleImage(Scaleform::Render::WrapperImageSource *this, Scaleform::Render::ImageCreateArgs *args)
{
  Scaleform::Render::ImageCreateArgs *v2; // rdi
  Scaleform::Render::WrapperImageSource *v3; // rbx

  v2 = args;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[11].__vecDelDtor)() )
    return Scaleform::Render::ImageSource::CreateCompatibleImage((Scaleform::Render::ImageSource *)&v3->vfptr, v2);
  ((void (*)(void))v3->pDelegate.pObject->vfptr[1].__vecDelDtor)();
  return (Scaleform::Render::RawImage *)v3->pDelegate.pObject;
}

// File Line: 1605
// RVA: 0x941090
void __fastcall Scaleform::Render::RawImage::RawImage(Scaleform::Render::RawImage *this)
{
  Scaleform::Render::RawImage *v1; // rdx
  Scaleform::Render::Texture *volatile v2; // rt1
  Scaleform::Render::Texture *volatile v3; // rax
  Scaleform::Render::ImagePlane *v4; // rcx
  Scaleform::Render::ImageData *v5; // [rsp+28h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  v2 = this->pTexture.Value;
  v3 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RawImage::`vftable;
  v5 = &this->Data;
  *(_QWORD *)&v5->Format = 0i64;
  *(_DWORD *)&v5->Flags = 0x10000;
  v4 = &this->Data.Plane0;
  v5->pPlanes = v4;
  v5->pPalette.pObject = 0i64;
  *(_QWORD *)&v4->Width = 0i64;
  v1->Data.Plane0.Pitch = 0i64;
  v1->Data.Plane0.DataSize = 0i64;
  v1->Data.Plane0.pData = 0i64;
}

// File Line: 1630
// RVA: 0x9849A0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(hkMemoryResourceContainer *this)
{
  return (unsigned int)this->m_resourceHandles.m_size;
}

// File Line: 1632
// RVA: 0x98B700
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::RawImage::GetSize(Scaleform::Render::RawImage *this, Scaleform::Render::Size<unsigned long> *result)
{
  Scaleform::Render::ImagePlane *v2; // r8

  v2 = this->Data.pPlanes;
  result->Width = v2->Width;
  result->Height = v2->Height;
  return result;
}

// File Line: 1633
// RVA: 0x989A30
__int64 __fastcall Scaleform::Render::RawImage::GetMipmapCount(Scaleform::Render::RawImage *this)
{
  return (unsigned __int8)this->Data.LevelCount;
}

// File Line: 1667
// RVA: 0x9462B0
void __fastcall Scaleform::Render::TextureImage::TextureImage(Scaleform::Render::TextureImage *this, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *size, unsigned int use, Scaleform::Render::Texture *ptexture, Scaleform::Render::ImageUpdateSync *psync)
{
  unsigned int v6; // ebp
  Scaleform::Render::Size<unsigned long> *v7; // rdi
  Scaleform::Render::ImageFormat v8; // ebx
  Scaleform::Render::TextureImage *v9; // rsi
  unsigned int v10; // edx

  v6 = use;
  v7 = size;
  v8 = format;
  v9 = this;
  Scaleform::Render::Image::Image((Scaleform::Render::Image *)&this->vfptr, ptexture, psync);
  v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable;
  v9->Format = v8;
  v10 = v7->Height;
  v9->Size.Width = v7->Width;
  v9->Size.Height = v10;
  v9->Use = v6;
}

// File Line: 1683
// RVA: 0x98B7B0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::TextureImage::GetSize(Scaleform::Render::MemoryBufferImage *this, Scaleform::Render::Size<unsigned long> *result)
{
  result->Width = this->Size.Width;
  result->Height = this->Size.Height;
  return result;
}

// File Line: 1684
// RVA: 0x989A60
signed __int64 __fastcall Scaleform::Render::TextureImage::GetMipmapCount(Scaleform::Render::TextureImage *this)
{
  Scaleform::Render::Texture *volatile v1; // rax
  signed __int64 result; // rax

  if ( !this->pTexture.Value || (v1 = this->pTexture.Value, v1->Use & 2) )
    result = 1i64;
  else
    result = (unsigned __int8)v1->MipLevels;
  return result;
}

// File Line: 1691
// RVA: 0x9B9D90
void __fastcall Scaleform::Render::TextureImage::TextureLost(Scaleform::Render::Image *this)
{
  _RBX = 0i64;
  __asm { xchg    rbx, [rcx+10h]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)_RBX + 64i64))(_RBX);
    if ( !_InterlockedDecrement(_RBX + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))_RBX)(_RBX, 1i64);
  }
}

// File Line: 1717
// RVA: 0x89DB10
void __fastcall Scaleform::Render::SubImage::SubImage(Scaleform::Render::SubImage *this, Scaleform::Render::Image *pimage, Scaleform::Render::Rect<unsigned long> *rect)
{
  Scaleform::Render::Rect<unsigned long> *v3; // rdi
  Scaleform::Render::Image *v4; // rsi
  Scaleform::Render::SubImage *v5; // rbx
  Scaleform::Render::Texture *volatile v6; // rt1
  Scaleform::Render::Texture *volatile v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // edx
  unsigned int v10; // ecx

  v3 = rect;
  v4 = pimage;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  v6 = this->pTexture.Value;
  v7 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SubImage::`vftable;
  if ( pimage )
    ((void (__fastcall *)(Scaleform::Render::Image *))pimage->vfptr[1].__vecDelDtor)(pimage);
  v5->pImage.pObject = v4;
  v8 = v3->y2;
  v9 = v3->x2;
  v10 = v3->y1;
  v5->SubRect.x1 = v3->x1;
  v5->SubRect.y1 = v10;
  v5->SubRect.x2 = v9;
  v5->SubRect.y2 = v8;
}

// File Line: 1721
// RVA: 0x8DA120
signed __int64 __fastcall Scaleform::Render::DICommand_Draw::GetType(CAkLayerCntr *this)
{
  return 5i64;
}

// File Line: 1725
// RVA: 0x8DB0E0
__int64 __fastcall Scaleform::Render::SubImage::GetMipmapCount(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (*)(void))this->pImage.pObject->vfptr[7].__vecDelDtor)();
}

// File Line: 1735
// RVA: 0x8C47E0
__int64 __fastcall Scaleform::Render::ImageDelegate::Decode(Scaleform::Render::ImageDelegate *this, Scaleform::Render::ImageData *pdest, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *arg)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, void (__fastcall *)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *))this->pImage.pObject->vfptr[8].__vecDelDtor)(
           this->pImage.pObject,
           pdest,
           copyScanline,
           arg);
}

// File Line: 1736
// RVA: 0x8DF200
Scaleform::Render::Texture *__fastcall Scaleform::Render::ImageDelegate::GetTexture(Scaleform::Render::ImageDelegate *this, Scaleform::Render::TextureManager *pmanager)
{
  return (Scaleform::Render::Texture *)this->pImage.pObject->vfptr[21].__vecDelDtor(
                                         (Scaleform::RefCountImplCore *)this->pImage.pObject,
                                         (unsigned int)pmanager);
}

// File Line: 1800
// RVA: 0xA0E2E0
void __fastcall Scaleform::Render::TextureFormat::~TextureFormat(Scaleform::Render::TextureFormat *this)
{
  this->vfptr = (Scaleform::Render::TextureFormatVtbl *)&Scaleform::Render::TextureFormat::`vftable;
}

// File Line: 1811
// RVA: 0x9FF000
__int64 __fastcall Scaleform::Render::Texture::GetPlaneCount(Scaleform::Render::Texture *this)
{
  signed int v1; // ebx
  Scaleform::Render::ImageFormat v2; // eax

  v1 = 1;
  if ( !(this->Use & 2) )
    v1 = (unsigned __int8)this->MipLevels;
  v2 = ((unsigned int (*)(void))this->vfptr[4].__vecDelDtor)();
  return v1 * (unsigned int)Scaleform::Render::ImageData::GetFormatPlaneCount(v2);
}

// File Line: 1816
// RVA: 0xA0ED20
__int64 __fastcall Scaleform::Render::Texture::GetImageFormat(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureFormat *v1; // rcx
  __int64 result; // rax

  v1 = this->pFormat;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr->GetImageFormat)();
  else
    result = 0i64;
  return result;
}

