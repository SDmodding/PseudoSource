// File Line: 66
// RVA: 0x6D94E0
void __fastcall Scaleform::GFx::ImageResource::ImageDelegate::AddRef(Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&this[-1].pTexture);
}

// File Line: 70
// RVA: 0x70FCA0
void __fastcall Scaleform::GFx::ImageResource::ImageDelegate::Release(Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&this[-1].pTexture);
}

// File Line: 83
// RVA: 0x77ED30
void __fastcall Scaleform::GFx::ImageResource::ImageResource(Scaleform::GFx::ImageResource *this, Scaleform::Render::ImageBase *pimageBase, Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::Resource::ResourceUse v3; // ebx
  Scaleform::Render::ImageSource *v4; // rsi
  Scaleform::GFx::ImageResource *v5; // rdi
  volatile int v6; // et1
  __int64 v7; // rax
  Scaleform::Render::Texture *volatile v8; // rt1
  Scaleform::Render::Texture *volatile v9; // rax
  Scaleform::GFx::ImageResource::ImageDelegate *v10; // [rsp+48h] [rbp+10h]

  v3 = use;
  v4 = (Scaleform::Render::ImageSource *)pimageBase;
  v5 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v6 = this->RefCount.Value;
  v7 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  v10 = &this->Delegate;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v10->RefCount = 1;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  v10->pTexture.Value = 0i64;
  v8 = this->Delegate.pTexture.Value;
  v9 = this->Delegate.pTexture.Value;
  v10->pUpdateSync = 0i64;
  v10->pInverseMatrix = 0i64;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  v10->pImage.pObject = 0i64;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories((AK::DSP::MultiChannelBiquadFilter<8>::Memories *)&this->Key);
  v5->UseType = v3;
  if ( v4 )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageSource *))v4->vfptr[3].__vecDelDtor)(v4) )
      Scaleform::GFx::ImageResource::SetImageSource(v5, v4);
    else
      Scaleform::GFx::ImageResource::SetImage(v5, (Scaleform::Render::Image *)v4);
  }
}

// File Line: 96
// RVA: 0x897740
void __fastcall Scaleform::GFx::ImageResource::ImageResource(Scaleform::GFx::ImageResource *this, Scaleform::Render::ImageSource *pimageSrc, Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::Resource::ResourceUse v3; // edi
  Scaleform::Render::ImageSource *v4; // rsi
  Scaleform::GFx::ImageResource *v5; // rbx
  volatile int v6; // et1
  __int64 v7; // rax
  Scaleform::GFx::ImageResource::ImageDelegate *v8; // rdx
  Scaleform::Render::Texture *volatile v9; // rt1
  Scaleform::Render::Texture *volatile v10; // rax
  Scaleform::Render::ImageBase *v11; // rcx
  Scaleform::Render::Image *v12; // rcx
  Scaleform::Render::ImageBase *v13; // rcx

  v3 = use;
  v4 = pimageSrc;
  v5 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v6 = this->RefCount.Value;
  v7 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  v8 = &this->Delegate;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v8->RefCount = 1;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  v9 = this->Delegate.pTexture.Value;
  v10 = this->Delegate.pTexture.Value;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  this->Key.pKeyInterface = 0i64;
  this->Key.hKeyData = 0i64;
  v11 = this->pImage;
  if ( v11 && v11 != (Scaleform::Render::ImageBase *)v8 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v11->vfptr[2].__vecDelDtor)(v11);
  v5->pImage = (Scaleform::Render::ImageBase *)&v4->vfptr;
  v12 = v5->Delegate.pImage.pObject;
  if ( v12 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v12->vfptr[2].__vecDelDtor)(v12);
  v5->Delegate.pImage.pObject = 0i64;
  v13 = v5->pImage;
  if ( v13 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v13->vfptr[1].__vecDelDtor)(v13);
  v5->UseType = v3;
}

// File Line: 103
// RVA: 0x6C92B0
void __fastcall Scaleform::GFx::ImageResource::ImageResource(Scaleform::GFx::ImageResource *this, Scaleform::Render::Image *pimage, Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::Resource::ResourceUse v3; // ebp
  Scaleform::Render::Image *v4; // rsi
  Scaleform::GFx::ImageResource *v5; // rbx
  volatile int v6; // et1
  __int64 v7; // rax
  Scaleform::GFx::ImageResource::ImageDelegate *v8; // rdi
  Scaleform::Render::Texture *volatile v9; // rt1
  Scaleform::Render::Texture *volatile v10; // rax
  char *v11; // rcx
  Scaleform::Render::Image *v12; // rcx

  v3 = use;
  v4 = pimage;
  v5 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v6 = this->RefCount.Value;
  v7 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  v8 = &this->Delegate;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v8->RefCount = 1;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  v9 = this->Delegate.pTexture.Value;
  v10 = this->Delegate.pTexture.Value;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories((AK::DSP::MultiChannelBiquadFilter<8>::Memories *)&this->Key);
  v11 = (char *)v5->pImage;
  if ( v11 && v11 != (char *)v8 )
    (*(void (__cdecl **)(char *))(*(_QWORD *)v11 + 16i64))(v11);
  if ( v4 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v4->vfptr[1].__vecDelDtor)(v4);
  v12 = v5->Delegate.pImage.pObject;
  if ( v12 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v12->vfptr[2].__vecDelDtor)(v12);
  v5->Delegate.pImage.pObject = v4;
  v5->pImage = (Scaleform::Render::ImageBase *)&v8->vfptr;
  v5->UseType = v3;
}

// File Line: 110
// RVA: 0x8975E0
void __fastcall Scaleform::GFx::ImageResource::ImageResource(Scaleform::GFx::ImageResource *this, Scaleform::Render::Image *pimage, Scaleform::GFx::ResourceKey *key, Scaleform::GFx::Resource::ResourceUse use)
{
  Scaleform::GFx::Resource::ResourceUse v4; // ebp
  Scaleform::GFx::ResourceKey *v5; // rsi
  Scaleform::Render::Image *v6; // r14
  Scaleform::GFx::ImageResource *v7; // rbx
  volatile int v8; // et1
  __int64 v9; // rax
  Scaleform::GFx::ImageResource::ImageDelegate *v10; // rdi
  Scaleform::Render::Texture *volatile v11; // rt1
  Scaleform::Render::Texture *volatile v12; // rax
  Scaleform::Render::ImageBase *v13; // rcx
  Scaleform::Render::Image *v14; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v15; // rcx

  v4 = use;
  v5 = key;
  v6 = pimage;
  v7 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
  v8 = this->RefCount.Value;
  v9 = (unsigned int)this->RefCount.Value;
  this->RefCount.Value = 1;
  this->pLib = 0i64;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  this->pImage = 0i64;
  v10 = &this->Delegate;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v10->RefCount = 1;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->Delegate.pTexture.Value = 0i64;
  v11 = this->Delegate.pTexture.Value;
  v12 = this->Delegate.pTexture.Value;
  this->Delegate.pUpdateSync = 0i64;
  this->Delegate.pInverseMatrix = 0i64;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageDelegate::`vftable;
  this->Delegate.pImage.pObject = 0i64;
  v10->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageResource::ImageDelegate::`vftable;
  this->Key.pKeyInterface = 0i64;
  this->Key.hKeyData = 0i64;
  v13 = this->pImage;
  if ( v13 && v13 != (Scaleform::Render::ImageBase *)v10 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v13->vfptr[2].__vecDelDtor)(v13);
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v6->vfptr[1].__vecDelDtor)(v6);
  v14 = v7->Delegate.pImage.pObject;
  if ( v14 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v14->vfptr[2].__vecDelDtor)(v14);
  v7->Delegate.pImage.pObject = v6;
  v7->pImage = (Scaleform::Render::ImageBase *)&v10->vfptr;
  if ( v5->pKeyInterface )
    v5->pKeyInterface->vfptr->AddRef(v5->pKeyInterface, v5->hKeyData);
  v15 = v7->Key.pKeyInterface;
  if ( v15 )
    v15->vfptr->Release(v15, v7->Key.hKeyData);
  v7->Key.pKeyInterface = v5->pKeyInterface;
  v7->Key.hKeyData = v5->hKeyData;
  v7->UseType = v4;
}

// File Line: 117
// RVA: 0x6D1A90
void __fastcall Scaleform::GFx::ImageResource::~ImageResource(Scaleform::GFx::ImageResource *this)
{
  Scaleform::GFx::ImageResource *v1; // rbx
  Scaleform::Render::ImageBase *v2; // rcx
  Scaleform::GFx::ResourceKey::KeyInterface *v3; // rcx
  Scaleform::Render::Image *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ImageResource::`vftable;
  v2 = this->pImage;
  if ( v2 && v2 != (Scaleform::Render::ImageBase *)&v1->Delegate )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *))v2->vfptr[2].__vecDelDtor)(v2);
  v3 = v1->Key.pKeyInterface;
  if ( v3 )
    v3->vfptr->Release(v3, v1->Key.hKeyData);
  v4 = v1->Delegate.pImage.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::Image *))v4->vfptr[2].__vecDelDtor)(v4);
  Scaleform::Render::Image::~Image((Scaleform::Render::Image *)&v1->Delegate.vfptr);
  v1->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 136
// RVA: 0x819AB0
void __fastcall Scaleform::GFx::ImageResource::SetImageSource(Scaleform::GFx::ImageResource *this, Scaleform::Render::ImageSource *pimageSrc)
{
  Scaleform::GFx::ImageResource *v2; // rbx
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::Render::ImageSource *v4; // rdi
  Scaleform::Render::Image *v5; // rcx
  Scaleform::Render::ImageBase *v6; // rcx

  v2 = this;
  v3 = this->pImage;
  v4 = pimageSrc;
  if ( v3 && v3 != (Scaleform::Render::ImageBase *)&v2->Delegate )
    ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
  v2->pImage = (Scaleform::Render::ImageBase *)&v4->vfptr;
  v5 = v2->Delegate.pImage.pObject;
  if ( v5 )
    ((void (*)(void))v5->vfptr[2].__vecDelDtor)();
  v2->Delegate.pImage.pObject = 0i64;
  v6 = v2->pImage;
  if ( v6 )
    ((void (*)(void))v6->vfptr[1].__vecDelDtor)();
}

// File Line: 143
// RVA: 0x714B50
void __fastcall Scaleform::GFx::ImageResource::SetImage(Scaleform::GFx::ImageResource *this, Scaleform::Render::Image *pimage)
{
  Scaleform::GFx::ImageResource *v2; // rbx
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::Render::Image *v4; // rdi
  Scaleform::Render::Image *v5; // rcx

  v2 = this;
  v3 = this->pImage;
  v4 = pimage;
  if ( v3 && v3 != (Scaleform::Render::ImageBase *)&v2->Delegate )
    ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
  if ( v4 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v4->vfptr[1].__vecDelDtor)(v4);
  v5 = v2->Delegate.pImage.pObject;
  if ( v5 )
    ((void (*)(void))v5->vfptr[2].__vecDelDtor)();
  v2->Delegate.pImage.pObject = v4;
  v2->pImage = (Scaleform::Render::ImageBase *)&v2->Delegate.vfptr;
}

// File Line: 184
// RVA: 0x6EFC20
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::ImageResource::GetKey(Scaleform::GFx::ImageResource *this, Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey *v2; // rbx

  v2 = result;
  Scaleform::GFx::ResourceKey::ResourceKey(result, &this->Key);
  return v2;
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
void __fastcall Scaleform::GFx::SubImageResource::SubImageResource(Scaleform::GFx::SubImageResource *this, Scaleform::GFx::ImageResource *pbase, __int64 baseid, Scaleform::Render::Rect<unsigned long> *rect)
{
  Scaleform::Render::Rect<unsigned long> *v4; // rsi
  unsigned int *v5; // r14
  Scaleform::GFx::ImageResource *v6; // rbx
  Scaleform::GFx::SubImageResource *v7; // rdi
  Scaleform::Render::SubImage *v8; // rax
  Scaleform::Render::Image *v9; // rax
  Scaleform::Render::Image *v10; // rbx
  unsigned int v11; // er8
  unsigned int v12; // edx
  unsigned int v13; // ecx
  Scaleform::Render::Image *v14; // [rsp+68h] [rbp+10h]
  Scaleform::Render::ImageBase *v15; // [rsp+70h] [rbp+18h]
  Scaleform::Render::SubImage *v16; // [rsp+78h] [rbp+20h]

  v4 = rect;
  v5 = (unsigned int *)baseid;
  v6 = pbase;
  v7 = this;
  v15 = pbase->pImage;
  LODWORD(v14) = 3;
  v8 = (Scaleform::Render::SubImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::ImageBase *, signed __int64, Scaleform::Render::Image **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                        Scaleform::Memory::pGlobalHeap,
                                        v15,
                                        64i64,
                                        &v14,
                                        -2i64);
  v16 = v8;
  if ( v8 )
  {
    Scaleform::Render::SubImage::SubImage(v8, (Scaleform::Render::Image *)v6->pImage, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v14 = v10;
  Scaleform::GFx::ImageResource::ImageResource((Scaleform::GFx::ImageResource *)&v7->vfptr, v10, Use_Bitmap);
  if ( v10 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v10->vfptr[2].__vecDelDtor)(v10);
  v7->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::SubImageResource::`vftable;
  v11 = v4->y2;
  v12 = v4->x2;
  v13 = v4->y1;
  v7->Rect.x1 = v4->x1;
  v7->Rect.y1 = v13;
  v7->Rect.x2 = v12;
  v7->Rect.y2 = v11;
  v7->BaseImageId.Id = *v5;
}

// File Line: 223
// RVA: 0x8D4D80
Scaleform::GFx::ResourceId *__fastcall Scaleform::GFx::SubImageResource::GetBaseImageId(Scaleform::GFx::SubImageResource *this, Scaleform::GFx::ResourceId *result)
{
  result->Id = (unsigned int)this->BaseImageId;
  return result;
}

