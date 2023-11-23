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
  Scaleform::Render::Palette *pObject; // rdx

  Scaleform::Render::ImageData::freePlanes(this);
  pObject = this->pPalette.pObject;
  if ( pObject )
  {
    if ( !_InterlockedDecrement(&pObject->RefCount.Value) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 549
// RVA: 0x994040
void __fastcall Scaleform::Render::ImageData::Initialize(
        Scaleform::Render::ImageData *this,
        Scaleform::Render::ImageFormat format,
        char mipLevels,
        Scaleform::Render::ImagePlane *pplanes,
        unsigned int planeCount,
        bool separateMipmaps)
{
  Scaleform::Render::ImageData::Clear(this);
  this->Format = format;
  this->LevelCount = mipLevels;
  this->RawPlaneCount = planeCount;
  this->pPlanes = pplanes;
  if ( separateMipmaps )
    this->Flags |= 1u;
  if ( pplanes )
  {
    if ( planeCount == 1 )
    {
      this->Plane0.Width = pplanes->Width;
      this->Plane0.Height = pplanes->Height;
      this->Plane0.Pitch = pplanes->Pitch;
      this->Plane0.DataSize = pplanes->DataSize;
      this->Plane0.pData = pplanes->pData;
    }
  }
}

// File Line: 735
// RVA: 0x9464E0
void __fastcall Scaleform::Render::TextureManagerLocks::TextureManagerLocks(
        Scaleform::Render::TextureManagerLocks *this,
        Scaleform::Render::TextureManager *pmanager)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextureManagerLocks,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureManagerLocks::`vftable;
  this->pManager = pmanager;
  Scaleform::Lock::Lock(&this->ImageLock, 0);
  Scaleform::Mutex::Mutex(&this->TextureMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->TextureInitWC);
}

// File Line: 750
// RVA: 0xA0DB90
void __fastcall Scaleform::Render::MappedTextureBase::MappedTextureBase(Scaleform::Render::MappedTextureBase *this)
{
  Scaleform::Render::ImageData *p_Data; // rax
  Scaleform::Render::ImagePlane *p_Plane0; // rcx

  this->vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  this->pTexture = 0i64;
  *(_QWORD *)&this->StartMipLevel = 0i64;
  p_Data = &this->Data;
  *(_QWORD *)&this->Data.Format = 0i64;
  *(_DWORD *)&this->Data.Flags = 0x10000;
  p_Plane0 = &this->Data.Plane0;
  p_Data->pPlanes = p_Plane0;
  p_Data->pPalette.pObject = 0i64;
  *(_QWORD *)&p_Plane0->Width = 0i64;
  p_Plane0->Pitch = 0i64;
  p_Plane0->DataSize = 0i64;
  p_Plane0->pData = 0i64;
  *(_QWORD *)&this->Planes[0].Width = 0i64;
  this->Planes[0].Pitch = 0i64;
  this->Planes[0].DataSize = 0i64;
  this->Planes[0].pData = 0i64;
  *(_QWORD *)&this->Planes[1].Width = 0i64;
  this->Planes[1].Pitch = 0i64;
  this->Planes[1].DataSize = 0i64;
  this->Planes[1].pData = 0i64;
  *(_QWORD *)&this->Planes[2].Width = 0i64;
  this->Planes[2].Pitch = 0i64;
  this->Planes[2].DataSize = 0i64;
  this->Planes[2].pData = 0i64;
  *(_QWORD *)&this->Planes[3].Width = 0i64;
  this->Planes[3].Pitch = 0i64;
  this->Planes[3].DataSize = 0i64;
  this->Planes[3].pData = 0i64;
}

// File Line: 753
// RVA: 0xA0E160
void __fastcall Scaleform::Render::MappedTextureBase::~MappedTextureBase(Scaleform::Render::MappedTextureBase *this)
{
  Scaleform::Render::ImageData *p_Data; // rbx
  volatile signed __int32 *p_Value; // rdx

  this->vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::MappedTextureBase::`vftable;
  p_Data = &this->Data;
  Scaleform::Render::ImageData::freePlanes(&this->Data);
  p_Value = &p_Data->pPalette.pObject->RefCount.Value;
  if ( p_Value )
  {
    if ( !_InterlockedDecrement(p_Value) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 814
// RVA: 0xA0DDC0
void __fastcall Scaleform::Render::Texture::Texture(
        Scaleform::Render::Texture *this,
        Scaleform::GFx::Resource *pmanagerLocks,
        Scaleform::Render::Size<unsigned long> *size,
        char mipLevels,
        unsigned __int16 use,
        Scaleform::Render::ImageBase *pimage,
        Scaleform::Render::TextureFormat *pformat)
{
  unsigned int Height; // ecx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Texture,72>::`vftable;
  this->pPrev = 0i64;
  this->pNext = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  if ( pmanagerLocks )
    Scaleform::Render::RenderBuffer::AddRef(pmanagerLocks);
  this->pManagerLocks.pObject = (Scaleform::Render::TextureManagerLocks *)pmanagerLocks;
  this->pImage = pimage;
  Height = size->Height;
  this->ImgSize.Width = size->Width;
  this->ImgSize.Height = Height;
  this->State = State_PreCapture;
  this->MipLevels = mipLevels;
  this->TextureCount = 1;
  this->Use = use;
  this->TextureFlags = 0;
  this->pMap = 0i64;
  this->pFormat = pformat;
}

// File Line: 816
// RVA: 0xA0E2A0
void __fastcall Scaleform::Render::Texture::~Texture(Scaleform::Render::Texture *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Texture::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pManagerLocks.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 844
// RVA: 0xA0EE60
void __fastcall Scaleform::Render::Texture::GetUVGenMatrix(
        Scaleform::Render::Texture *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  float v2; // xmm1_4
  float Height; // xmm0_4

  v2 = 1.0 / (float)(int)this->ImgSize.Width;
  Height = (float)(int)this->ImgSize.Height;
  *(_OWORD *)&mat->M[0][1] = 0ui64;
  *(_QWORD *)&mat->M[1][2] = 0i64;
  mat->M[0][0] = v2;
  mat->M[1][1] = 1.0 / Height;
}

// File Line: 852
// RVA: 0xA0EEB0
void __fastcall Scaleform::Render::Texture::ImageLost(Scaleform::Render::Texture *this)
{
  Scaleform::Lock *p_ImageLock; // rbx

  p_ImageLock = &this->pManagerLocks.pObject->ImageLock;
  EnterCriticalSection(&p_ImageLock->cs);
  this->pImage = 0i64;
  LeaveCriticalSection(&p_ImageLock->cs);
}

// File Line: 964
// RVA: 0xA0DAF0
void __fastcall Scaleform::Render::DepthStencilSurface::DepthStencilSurface(
        Scaleform::Render::DepthStencilSurface *this,
        Scaleform::GFx::Resource *pmanagerLocks,
        Scaleform::Render::Size<unsigned long> *size)
{
  unsigned int Height; // ecx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DepthStencilSurface,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DepthStencilSurface::`vftable;
  if ( pmanagerLocks )
    Scaleform::Render::RenderBuffer::AddRef(pmanagerLocks);
  this->pManagerLocks.pObject = (Scaleform::Render::TextureManagerLocks *)pmanagerLocks;
  this->State = State_PreCapture;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
}

// File Line: 966
// RVA: 0xA0ED70
Scaleform::Render::ImageUpdateSyncVtbl *__fastcall Scaleform::Render::DepthStencilSurface::GetTextureManager(
        Scaleform::Render::DepthStencilSurface *this)
{
  Scaleform::Render::ImageUpdateSyncVtbl *result; // rax

  result = (Scaleform::Render::ImageUpdateSyncVtbl *)this->pManagerLocks.pObject;
  if ( result )
    return (Scaleform::Render::ImageUpdateSyncVtbl *)result->UpdateImage;
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
bool __fastcall Scaleform::Render::TextureManager::CanCreateTextureCurrentThread(
        Scaleform::Render::TextureManager *this)
{
  return !this->RenderThreadId || UFG::qGetCurrentThreadID() == this->RenderThreadId;
}

// File Line: 1130
// RVA: 0x9976A0
bool __fastcall Scaleform::Render::TextureManager::IsDrawableImageFormat(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageFormat format)
{
  return format == Image_R8G8B8A8;
}

// File Line: 1171
// RVA: 0x9E96C0
Scaleform::Render::MappedTextureBase *__fastcall Scaleform::Render::TextureManager::mapTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Texture *p)
{
  return (Scaleform::Render::MappedTextureBase *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Texture *, _QWORD, _QWORD))this->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[21].__vecDelDtor)(
                                                   this,
                                                   p,
                                                   0i64,
                                                   (unsigned __int8)p->MipLevels);
}

// File Line: 1291
// RVA: 0x6C91A0
void __fastcall Scaleform::Render::Image::Image(
        Scaleform::Render::Image *this,
        Scaleform::Render::Texture *ptexture,
        Scaleform::Render::ImageUpdateSync *psync)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = ptexture;
  this->pUpdateSync = psync;
  this->pInverseMatrix = 0i64;
  if ( ptexture )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ptexture);
}

// File Line: 1324
// RVA: 0x6F5100
Scaleform::Render::Rect<unsigned long> *__fastcall Scaleform::Render::ImageBase::GetRect(
        Scaleform::Render::ImageBase *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  _QWORD *v3; // rax
  char v5; // [rsp+30h] [rbp+8h] BYREF

  v3 = this->vfptr[5].__vecDelDtor(this, &v5);
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = *v3;
  return result;
}

// File Line: 1377
// RVA: 0x722E60
char __fastcall Scaleform::Render::Image::Update(Scaleform::Render::Image *this)
{
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // rcx

  pUpdateSync = this->pUpdateSync;
  if ( !pUpdateSync )
    return 0;
  pUpdateSync->vfptr->UpdateImage(pUpdateSync, this);
  return 1;
}

// File Line: 1387
// RVA: 0x722E30
char __fastcall Scaleform::Render::Image::Update(
        Scaleform::Render::Image *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  Scaleform::Render::ImageUpdateSync *pUpdateSync; // rcx

  pUpdateSync = this->pUpdateSync;
  if ( !pUpdateSync )
    return 0;
  pUpdateSync->vfptr->UpdateImage(pUpdateSync, pupdate);
  return 1;
}

// File Line: 1433
// RVA: 0x721220
void __fastcall Scaleform::Render::Image::TextureLost(
        Scaleform::Render::Image *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  if ( reason == TLR_ManagerDestroyed )
    Scaleform::Render::TextureImage::TextureLost(this);
}

// File Line: 1459
// RVA: 0x6EFC00
__int64 __fastcall Scaleform::Render::ImageDelegate::GetImageType(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[3].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1460
// RVA: 0x6EFB20
__int64 __fastcall Scaleform::Render::ImageDelegate::GetFormat(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[4].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1461
// RVA: 0x6F53C0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::SubImage::GetSize(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  ((void (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[5].__vecDelDtor)(this->pImage.pObject);
  return result;
}

// File Line: 1462
// RVA: 0x6F5130
Scaleform::Render::Rect<unsigned long> *__fastcall Scaleform::Render::ImageDelegate::GetRect(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  ((void (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[6].__vecDelDtor)(this->pImage.pObject);
  return result;
}

// File Line: 1466
// RVA: 0x715180
void __fastcall Scaleform::Render::ImageDelegate::SetMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[13].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    heap);
}

// File Line: 1467
// RVA: 0x6EFE60
void __fastcall Scaleform::Render::ImageDelegate::GetMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  this->pImage.pObject->vfptr[14].__vecDelDtor(this->pImage.pObject, (unsigned int)mat);
}

// File Line: 1469
// RVA: 0x715190
void __fastcall Scaleform::Render::ImageDelegate::SetMatrixInverse(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::MemoryHeap *heap)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[15].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    heap);
}

// File Line: 1470
// RVA: 0x6EFE70
void *__fastcall Scaleform::Render::ImageDelegate::GetMatrixInverse(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  return this->pImage.pObject->vfptr[16].__vecDelDtor(this->pImage.pObject, mat);
}

// File Line: 1472
// RVA: 0x6F7280
void __fastcall Scaleform::Render::ImageDelegate::GetUVGenMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
{
  ((void (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::TextureManager *))this->pImage.pObject->vfptr[22].__vecDelDtor)(
    this->pImage.pObject,
    mat,
    manager);
}

// File Line: 1474
// RVA: 0x6F7290
void __fastcall Scaleform::Render::ImageDelegate::GetUVNormMatrix(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Matrix2x4<float> *mat,
        Scaleform::Render::TextureManager *manager)
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
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[12].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1489
// RVA: 0x6E1930
Scaleform::Render::Image *__fastcall Scaleform::Render::ImageDelegate::CreateSubImage(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::Rect<unsigned long> *rect,
        Scaleform::MemoryHeap *pheap)
{
  return (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::Rect<unsigned long> *, Scaleform::MemoryHeap *))this->pImage.pObject->vfptr[11].__vecDelDtor)(
                                       this->pImage.pObject,
                                       rect,
                                       pheap);
}

// File Line: 1492
// RVA: 0x703060
__int64 __fastcall Scaleform::Render::ImageDelegate::Map(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::ImageData *pdata,
        __int64 levelIndex,
        __int64 levelCount)
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
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[18].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1497
// RVA: 0x721230
void __fastcall Scaleform::Render::ImageDelegate::TextureLost(Scaleform::Render::ImageDelegate *this, __int64 reason)
{
  this->pImage.pObject->vfptr[24].__vecDelDtor(this->pImage.pObject, reason);
}

// File Line: 1499
// RVA: 0x722EA0
__int64 __fastcall Scaleform::Render::ImageDelegate::Update(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[20].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1500
// RVA: 0x722E90
void *__fastcall Scaleform::Render::ImageDelegate::Update(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::ImageUpdate *pupdate)
{
  return this->pImage.pObject->vfptr[19].__vecDelDtor(this->pImage.pObject, pupdate);
}

// File Line: 1502
// RVA: 0x6EE6A0
const char *__fastcall Scaleform::GFx::FontManagerStates::GetStateBagImpl(LOCALNAMESPACE::hkNativeResource *this)
{
  return this->m_contentsTypeName;
}

// File Line: 1503
// RVA: 0x6EE6B0
Scaleform::Render::MemoryBufferImage *__fastcall Scaleform::Render::ImageDelegate::GetAsMemoryImage(
        Scaleform::Render::ImageDelegate *this)
{
  return (Scaleform::Render::MemoryBufferImage *)((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[25].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1563
// RVA: 0x89F8A0
void __fastcall Scaleform::Render::WrapperImageSource::WrapperImageSource(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::Image *pdelegate)
{
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
  this->pDelegate.pObject = pdelegate;
}

// File Line: 1566
// RVA: 0x8D8D20
__int64 __fastcall Scaleform::Render::WrapperImageSource::GetFormat(
        hkSubStreamWriter *this,
        const void *buf,
        __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamWriter *, const void *, __int64))this->m_childStream->vfptr[2].__vecDelDtor)(
           this->m_childStream,
           buf,
           nbytes);
}

// File Line: 1567
// RVA: 0x8DE220
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::WrapperImageSource::GetSize(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  ((void (__fastcall *)(Scaleform::Render::Image *))this->pDelegate.pObject->vfptr[5].__vecDelDtor)(this->pDelegate.pObject);
  return result;
}

// File Line: 1576
// RVA: 0x8BF0F0
Scaleform::Render::RawImage *__fastcall Scaleform::Render::WrapperImageSource::CreateCompatibleImage(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::ImageCreateArgs *args)
{
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::WrapperImageSource *))this->vfptr[11].__vecDelDtor)(this) )
    return Scaleform::Render::ImageSource::CreateCompatibleImage(this, args);
  ((void (__fastcall *)(Scaleform::Render::Image *))this->pDelegate.pObject->vfptr[1].__vecDelDtor)(this->pDelegate.pObject);
  return (Scaleform::Render::RawImage *)this->pDelegate.pObject;
}

// File Line: 1605
// RVA: 0x941090
void __fastcall Scaleform::Render::RawImage::RawImage(Scaleform::Render::RawImage *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RawImage::`vftable;
  *(_QWORD *)&this->Data.Format = 0i64;
  *(_DWORD *)&this->Data.Flags = 0x10000;
  this->Data.pPlanes = &this->Data.Plane0;
  this->Data.pPalette.pObject = 0i64;
  *(_QWORD *)&this->Data.Plane0.Width = 0i64;
  this->Data.Plane0.Pitch = 0i64;
  this->Data.Plane0.DataSize = 0i64;
  this->Data.Plane0.pData = 0i64;
}

// File Line: 1630
// RVA: 0x9849A0
__int64 __fastcall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(
        hkMemoryResourceContainer *this)
{
  return (unsigned int)this->m_resourceHandles.m_size;
}

// File Line: 1632
// RVA: 0x98B700
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::RawImage::GetSize(
        Scaleform::Render::RawImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  Scaleform::Render::ImagePlane *pPlanes; // r8

  pPlanes = this->Data.pPlanes;
  result->Width = pPlanes->Width;
  result->Height = pPlanes->Height;
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
void __fastcall Scaleform::Render::TextureImage::TextureImage(
        Scaleform::Render::TextureImage *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::Texture *ptexture,
        Scaleform::Render::ImageUpdateSync *psync)
{
  unsigned int Height; // edx

  Scaleform::Render::Image::Image(this, ptexture, psync);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable;
  this->Format = format;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
  this->Use = use;
}

// File Line: 1683
// RVA: 0x98B7B0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::TextureImage::GetSize(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::Size<unsigned long> *result)
{
  *result = this->Size;
  return result;
}

// File Line: 1684
// RVA: 0x989A60
__int64 __fastcall Scaleform::Render::TextureImage::GetMipmapCount(Scaleform::Render::TextureImage *this)
{
  Scaleform::Render::Texture *volatile Value; // rax

  if ( !this->pTexture.Value )
    return 1i64;
  Value = this->pTexture.Value;
  if ( (Value->Use & 2) != 0 )
    return 1i64;
  else
    return (unsigned __int8)Value->MipLevels;
}

// File Line: 1691
// RVA: 0x9B9D90
void __fastcall Scaleform::Render::TextureImage::TextureLost(Scaleform::Render::Image *this)
{
  volatile signed __int32 *v1; // rbx

  v1 = (volatile signed __int32 *)_InterlockedExchange64((volatile __int64 *)&this->pTexture, 0i64);
  if ( v1 )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v1 + 64i64))(v1);
    if ( !_InterlockedDecrement(v1 + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v1)(v1, 1i64);
  }
}

// File Line: 1717
// RVA: 0x89DB10
void __fastcall Scaleform::Render::SubImage::SubImage(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Image *pimage,
        Scaleform::Render::Rect<unsigned long> *rect)
{
  unsigned int y2; // r8d
  unsigned int x2; // edx
  unsigned int y1; // ecx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::SubImage::`vftable;
  if ( pimage )
    ((void (__fastcall *)(Scaleform::Render::Image *))pimage->vfptr[1].__vecDelDtor)(pimage);
  this->pImage.pObject = pimage;
  y2 = rect->y2;
  x2 = rect->x2;
  y1 = rect->y1;
  this->SubRect.x1 = rect->x1;
  this->SubRect.y1 = y1;
  this->SubRect.x2 = x2;
  this->SubRect.y2 = y2;
}

// File Line: 1721
// RVA: 0x8DA120
__int64 __fastcall Scaleform::Render::DICommand_Draw::GetType(CAkLayerCntr *this)
{
  return 5i64;
}

// File Line: 1725
// RVA: 0x8DB0E0
__int64 __fastcall Scaleform::Render::SubImage::GetMipmapCount(Scaleform::Render::ImageDelegate *this)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *))this->pImage.pObject->vfptr[7].__vecDelDtor)(this->pImage.pObject);
}

// File Line: 1735
// RVA: 0x8C47E0
__int64 __fastcall Scaleform::Render::ImageDelegate::Decode(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::ImageData *pdest,
        void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *),
        void *arg)
{
  return ((__int64 (__fastcall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, void (__fastcall *)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *))this->pImage.pObject->vfptr[8].__vecDelDtor)(
           this->pImage.pObject,
           pdest,
           copyScanline,
           arg);
}

// File Line: 1736
// RVA: 0x8DF200
Scaleform::Render::Texture *__fastcall Scaleform::Render::ImageDelegate::GetTexture(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::TextureManager *pmanager)
{
  return (Scaleform::Render::Texture *)this->pImage.pObject->vfptr[21].__vecDelDtor(this->pImage.pObject, pmanager);
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
  int MipLevels; // ebx
  Scaleform::Render::ImageFormat v2; // eax

  MipLevels = 1;
  if ( (this->Use & 2) == 0 )
    MipLevels = (unsigned __int8)this->MipLevels;
  v2 = ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))this->vfptr[4].__vecDelDtor)(this);
  return MipLevels * (unsigned int)Scaleform::Render::ImageData::GetFormatPlaneCount(v2);
}

// File Line: 1816
// RVA: 0xA0ED20
__int64 __fastcall Scaleform::Render::Texture::GetImageFormat(Scaleform::Render::Texture *this)
{
  Scaleform::Render::TextureFormat *pFormat; // rcx

  pFormat = this->pFormat;
  if ( pFormat )
    return ((__int64 (__fastcall *)(Scaleform::Render::TextureFormat *))pFormat->vfptr->GetImageFormat)(pFormat);
  else
    return 0i64;
}

