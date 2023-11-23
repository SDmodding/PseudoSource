// File Line: 66
// RVA: 0x6D94E0
void __fastcall Scaleform::GFx::ImageResource::ImageDelegate::AddRef(
        Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&this[-1].pTexture);
}

// File Line: 70
// RVA: 0x70FCA0
void __fastcall Scaleform::GFx::ImageResource::ImageDelegate::Release(
        Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&this[-1].pTexture);
}

// File Line: 83
// RVA: 0x77ED30
void __fastcall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageBase,
        Scaleform::GFx::Resource::ResourceUse use)
{
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Delegate.RefCount = 1;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories((AK::DSP::MultiChannelBiquadFilter<8>::Memories *)&this->Key);
  this->UseType = use;
  if ( pimageBase )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageSource *))pimageBase->vfptr[3].__vecDelDtor)(pimageBase) )
      Scaleform::GFx::ImageResource::SetImageSource(this, pimageBase);
    else
      Scaleform::GFx::ImageResource::SetImage(this, (Scaleform::Render::Image *)pimageBase);
  }
}

// File Line: 96
// RVA: 0x897740
void __fastcall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageSrc,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // rdx
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::Render::ImageBase *v9; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  p_Delegate = &this->Delegate;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Delegate.RefCount = 1;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  this->Key.pKeyInterface = 0i64;
  this->Key.hKeyData = 0i64;
  pImage = this->pImage;
  if ( pImage && pImage != p_Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[2].__vecDelDtor)(pImage);
  this->pImage = pimageSrc;
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->Delegate.pImage.pObject = 0i64;
  v9 = this->pImage;
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v9->vfptr[1].__vecDelDtor)(v9);
  this->UseType = use;
}

// File Line: 103
// RVA: 0x6C92B0
void __fastcall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // rdi
  Scaleform::Render::ImageBase *v7; // rcx
  Scaleform::Render::Image *pObject; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  p_Delegate = &this->Delegate;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Delegate.RefCount = 1;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories((AK::DSP::MultiChannelBiquadFilter<8>::Memories *)&this->Key);
  v7 = this->pImage;
  if ( v7 && v7 != p_Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v7->vfptr[2].__vecDelDtor)(v7);
  if ( pimage )
    ((void (__fastcall *)(Scaleform::Render::Image *))pimage->vfptr[1].__vecDelDtor)(pimage);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->Delegate.pImage.pObject = pimage;
  this->pImage = p_Delegate;
  this->UseType = use;
}

// File Line: 110
// RVA: 0x8975E0
void __fastcall Scaleform::GFx::ImageResource::ImageResource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage,
        Scaleform::GFx::ResourceKey *key,
        Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::ImageResource::ImageDelegate *p_Delegate; // rdi
  Scaleform::Render::ImageBase *v9; // rcx
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  p_Delegate = &this->Delegate;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->Delegate.RefCount = 1;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  this->Delegate.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  this->Key.pKeyInterface = 0i64;
  this->Key.hKeyData = 0i64;
  v9 = this->pImage;
  if ( v9 && v9 != p_Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v9->vfptr[2].__vecDelDtor)(v9);
  if ( pimage )
    ((void (__fastcall *)(Scaleform::Render::Image *))pimage->vfptr[1].__vecDelDtor)(pimage);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->Delegate.pImage.pObject = pimage;
  this->pImage = p_Delegate;
  if ( key->pKeyInterface )
    key->pKeyInterface->vfptr->AddRef(key->pKeyInterface, key->hKeyData);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->Key.hKeyData);
  this->Key.pKeyInterface = key->pKeyInterface;
  this->Key.hKeyData = key->hKeyData;
  this->UseType = use;
}

// File Line: 117
// RVA: 0x6D1A90
void __fastcall Scaleform::GFx::ImageResource::~ImageResource(Scaleform::GFx::ImageResource *this)
{
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx
  Scaleform::Render::Image *pObject; // rcx

  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  pImage = this->pImage;
  if ( pImage && pImage != &this->Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[2].__vecDelDtor)(pImage);
  pKeyInterface = this->Key.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->Key.hKeyData);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  Scaleform::Render::Image::~Image(&this->Delegate);
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 136
// RVA: 0x819AB0
void __fastcall Scaleform::GFx::ImageResource::SetImageSource(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::ImageSource *pimageSrc)
{
  Scaleform::Render::ImageBase *pImage; // rcx
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::Render::ImageBase *v6; // rcx

  pImage = this->pImage;
  if ( pImage && pImage != &this->Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[2].__vecDelDtor)(pImage);
  this->pImage = pimageSrc;
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->Delegate.pImage.pObject = 0i64;
  v6 = this->pImage;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v6->vfptr[1].__vecDelDtor)(v6);
}

// File Line: 143
// RVA: 0x714B50
void __fastcall Scaleform::GFx::ImageResource::SetImage(
        Scaleform::GFx::ImageResource *this,
        Scaleform::Render::Image *pimage)
{
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::Render::Image *pObject; // rcx

  v3 = this->pImage;
  if ( v3 && v3 != &this->Delegate )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v3->vfptr[2].__vecDelDtor)(v3);
  if ( pimage )
    ((void (__fastcall *)(Scaleform::Render::Image *))pimage->vfptr[1].__vecDelDtor)(pimage);
  pObject = this->Delegate.pImage.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
  this->Delegate.pImage.pObject = pimage;
  this->pImage = &this->Delegate;
}

// File Line: 184
// RVA: 0x6EFC20
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::ImageResource::GetKey(
        Scaleform::GFx::ImageResource *this,
        Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey::ResourceKey(result, &this->Key);
  return result;
}

// File Line: 185
// RVA: 0x6EFC10
__int64 __fastcall Scaleform::GFx::ImageResource::GetImageUse(hkpConvexVerticesShape *this)
{
  return (unsigned int)this->m_numVertices;
}

// File Line: 186
// RVA: 0x6F5380
__int32 __fastcall Scaleform::GFx::ImageResource::GetResourceTypeCode(Scaleform::GFx::ImageResource *this)
{
  return this->UseType | 0x100;
}

// File Line: 219
// RVA: 0x89DBE0
void __fastcall Scaleform::GFx::SubImageResource::SubImageResource(
        Scaleform::GFx::SubImageResource *this,
        Scaleform::GFx::ImageResource *pbase,
        unsigned int *baseid,
        Scaleform::Render::Rect<unsigned long> *rect)
{
  Scaleform::Render::SubImage *v8; // rax
  Scaleform::Render::Image *v9; // rax
  Scaleform::Render::Image *v10; // rbx
  unsigned int y2; // r8d
  unsigned int x2; // edx
  unsigned int y1; // ecx
  Scaleform::Render::Image *v14; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::Render::ImageBase *pImage; // [rsp+70h] [rbp+18h]
  Scaleform::Render::SubImage *v16; // [rsp+78h] [rbp+20h]

  pImage = pbase->pImage;
  LODWORD(v14) = 3;
  v8 = (Scaleform::Render::SubImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ImageBase *, __int64, Scaleform::Render::Image **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        pImage,
                                        64i64,
                                        &v14,
                                        -2i64);
  v16 = v8;
  if ( v8 )
  {
    Scaleform::Render::SubImage::SubImage(v8, (Scaleform::Render::Image *)pbase->pImage, rect);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v14 = v10;
  Scaleform::GFx::ImageResource::ImageResource(this, v10, Use_Bitmap);
  if ( v10 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v10->vfptr[2].__vecDelDtor)(v10);
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SubImageResource::`vftable;
  y2 = rect->y2;
  x2 = rect->x2;
  y1 = rect->y1;
  this->Rect.x1 = rect->x1;
  this->Rect.y1 = y1;
  this->Rect.x2 = x2;
  this->Rect.y2 = y2;
  this->BaseImageId.Id = *baseid;
}

// File Line: 223
// RVA: 0x8D4D80
Scaleform::GFx::ResourceId *__fastcall Scaleform::GFx::SubImageResource::GetBaseImageId(
        Scaleform::GFx::SubImageResource *this,
        Scaleform::GFx::ResourceId *result)
{
  result->Id = (unsigned int)this->BaseImageId;
  return result;
}

