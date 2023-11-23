// File Line: 89
// RVA: 0x941140
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::DSSizeMode depthStencilSizeMode,
        unsigned __int64 memReuseLimit,
        unsigned __int64 memAbsoluteLimit)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *BufferCache; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::RenderBufferManager,72>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBufferManager::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RBGenericImpl::RenderBufferManager::`vftable;
  this->pTextureManager.pObject = 0i64;
  this->CtorReuseLimit = memReuseLimit;
  this->ReuseLimit = 0i64;
  this->AbsoluteLimit = memAbsoluteLimit;
  this->AllocSize = 0i64;
  this->DefImageFormat = Image_None;
  this->RequirePow2 = 0;
  this->DepthStencilSizeMode = depthStencilSizeMode;
  BufferCache = this->BufferCache;
  BufferCache->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)BufferCache;
  BufferCache->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)BufferCache;
  BufferCache[1].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[1];
  BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[1];
  BufferCache[2].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[2];
  BufferCache[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[2];
  BufferCache[3].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[3];
  BufferCache[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[3];
  BufferCache[4].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[4];
  BufferCache[4].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[4];
  BufferCache[5].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[5];
  BufferCache[5].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[5];
  BufferCache[6].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[6];
  BufferCache[6].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&BufferCache[6];
}

// File Line: 93
// RVA: 0x94C360
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::~RenderBufferManager(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::TextureManager *pObject; // rcx
  Scaleform::Render::TextureManager *v3; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RBGenericImpl::RenderBufferManager::`vftable;
  ((void (__fastcall *)(Scaleform::Render::RBGenericImpl::RenderBufferManager *))this->vfptr[4].__vecDelDtor)(this);
  this->DefImageFormat = Image_None;
  pObject = this->pTextureManager.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  this->pTextureManager.pObject = 0i64;
  v3 = this->pTextureManager.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
    v3->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      v3,
      1u);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBufferManager::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 99
// RVA: 0x994270
char __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Initialize(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::TextureManager *manager,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *screenSize)
{
  Scaleform::Render::TextureManager *pObject; // rcx
  unsigned __int64 CtorReuseLimit; // rax

  if ( manager )
    _InterlockedExchangeAdd(&manager->RefCount, 1u);
  pObject = this->pTextureManager.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  this->pTextureManager.pObject = manager;
  this->DefImageFormat = format;
  this->RequirePow2 = ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64))manager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[4].__vecDelDtor)(
                        manager,
                        (unsigned int)format,
                        1024i64) == 0;
  CtorReuseLimit = this->CtorReuseLimit;
  if ( CtorReuseLimit == -1i64 )
  {
    if ( screenSize->Width || screenSize->Height )
      CtorReuseLimit = 16 * screenSize->Width * screenSize->Height;
    else
      CtorReuseLimit = 0i64;
  }
  this->ReuseLimit = CtorReuseLimit;
  return 1;
}

// File Line: 115
// RVA: 0x96D3D0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Destroy(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::TextureManager *pObject; // rcx

  ((void (__fastcall *)(Scaleform::Render::RBGenericImpl::RenderBufferManager *))this->vfptr[4].__vecDelDtor)(this);
  this->DefImageFormat = Image_None;
  pObject = this->pTextureManager.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  this->pTextureManager.pObject = 0i64;
}

// File Line: 122
// RVA: 0x970770
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::EndFrame(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::CacheData *pNext; // r8
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // rax
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v4; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // rcx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // r8
  Scaleform::Render::RBGenericImpl::CacheData *v7; // r9
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v9; // r9
  Scaleform::Render::RBGenericImpl::CacheData *v10; // rcx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v11; // rax
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v12; // rbx
  Scaleform::Render::RBGenericImpl::CacheData *v13; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v14; // rcx

  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(this, RBCL_Reuse_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(this, RBCL_LRU);
  if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)this->BufferCache[0].Root.pNext != this->BufferCache
    || (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)this->BufferCache[1].Root.pNext != &this->BufferCache[1] )
  {
    ((void (__fastcall *)(Scaleform::Render::RBGenericImpl::RenderBufferManager *))this->vfptr[8].__vecDelDtor)(this);
  }
  pNext = this->BufferCache[1].Root.pNext;
  v3 = &this->BufferCache[1];
  v4 = &this->BufferCache[2];
  if ( pNext != (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1] )
  {
    pPrev = v3->Root.pPrev;
    this->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
    v3->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v3;
    pPrev->pNext = this->BufferCache[2].Root.pNext;
    pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
    this->BufferCache[2].Root.pNext->pPrev = pPrev;
    this->BufferCache[2].Root.pNext = pNext;
  }
  v6 = &this->BufferCache[3];
  v7 = this->BufferCache[3].Root.pNext;
  if ( v7 != (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3] )
  {
    v8 = v6->Root.pPrev;
    this->BufferCache[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[3];
    v6->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v6;
    v8->pNext = this->BufferCache[4].Root.pNext;
    v7->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[4];
    this->BufferCache[4].Root.pNext->pPrev = v8;
    this->BufferCache[4].Root.pNext = v7;
  }
  v9 = this->BufferCache[2].Root.pNext;
  if ( v9 != (Scaleform::Render::RBGenericImpl::CacheData *)v4 )
  {
    v10 = v4->Root.pPrev;
    this->BufferCache[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[2];
    v4->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
    v10->pNext = this->BufferCache[3].Root.pNext;
    v9->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v6;
    this->BufferCache[3].Root.pNext->pPrev = v10;
    this->BufferCache[3].Root.pNext = v9;
  }
  v11 = &this->BufferCache[5];
  v12 = &this->BufferCache[6];
  v13 = v11->Root.pNext;
  if ( v13 != (Scaleform::Render::RBGenericImpl::CacheData *)v11 )
  {
    v14 = v11->Root.pPrev;
    v11->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v11;
    v11->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v11;
    v14->pNext = v12->Root.pNext;
    v13->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v12;
    v12->Root.pNext->pPrev = v14;
    v12->Root.pNext = v13;
  }
}

// File Line: 137
// RVA: 0x9AB9F0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Reset(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_PrevFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_Reuse_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_Reuse_LRU);
}

// File Line: 149
// RVA: 0x96F4D0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::DumpUsage(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *BufferCache; // rcx
  __int64 v2; // rdx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *i; // rax

  BufferCache = this->BufferCache;
  v2 = 7i64;
  do
  {
    for ( i = (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)BufferCache->Root.pNext;
          i != BufferCache;
          i = (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)i->Root.pNext )
    {
      ;
    }
    ++BufferCache;
    --v2;
  }
  while ( v2 );
}

// File Line: 164
// RVA: 0x969330
Scaleform::Render::RBGenericImpl::RenderTarget *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Texture *texture)
{
  if ( this->pTextureManager.pObject )
    return Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(this, size, type, format, texture);
  else
    return 0i64;
}

// File Line: 174
// RVA: 0x9DE430
Scaleform::Render::RBGenericImpl::RenderTarget *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Texture *texture)
{
  _DWORD *v9; // rbx
  unsigned int Height; // ecx
  unsigned int v11; // ecx
  unsigned int Width; // eax
  __int64 v13; // rcx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  int v17; // [rsp+20h] [rbp-38h] BYREF
  __int64 v18; // [rsp+28h] [rbp-30h]
  _DWORD *v19; // [rsp+30h] [rbp-28h]

  v18 = -2i64;
  v17 = 72;
  v9 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 120i64, &v17);
  v19 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = &Scaleform::RefCountImplCore::`vftable;
    v9[2] = 1;
    *(_QWORD *)v9 = &Scaleform::RefCountVImpl::`vftable;
    *(_QWORD *)v9 = &Scaleform::Render::RenderBuffer::`vftable;
    v9[4] = type;
    *((_QWORD *)v9 + 3) = this;
    *((_QWORD *)v9 + 4) = 0i64;
    Height = size->Height;
    v9[10] = size->Width;
    v9[11] = Height;
    *(_QWORD *)v9 = &Scaleform::Render::RenderTarget::`vftable;
    v11 = size->Height;
    Width = size->Width;
    *((_QWORD *)v9 + 6) = 0i64;
    v9[14] = Width;
    v9[15] = v11;
    *((_QWORD *)v9 + 8) = 0i64;
    *((_QWORD *)v9 + 9) = 0i64;
    *((_QWORD *)v9 + 10) = v9;
    *((_QWORD *)v9 + 11) = 0i64;
    *((_QWORD *)v9 + 12) = 0i64;
    *(_QWORD *)v9 = &Scaleform::Render::RBGenericImpl::RenderTarget::`vftable;
    *((_QWORD *)v9 + 13) = 0i64;
    v9[28] = 0;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v9 )
  {
    v9[23] = format;
    if ( texture )
      _InterlockedExchangeAdd(&texture->RefCount, 1u);
    v13 = *((_QWORD *)v9 + 13);
    if ( v13 && !_InterlockedDecrement((volatile signed __int32 *)(v13 + 8)) )
      (**(void (__fastcall ***)(__int64, __int64))v13)(v13, 1i64);
    *((_QWORD *)v9 + 13) = texture;
    v14 = size->Width;
    v15 = size->Height;
    *((_QWORD *)v9 + 6) = 0i64;
    v9[14] = v14;
    v9[15] = v15;
  }
  return (Scaleform::Render::RBGenericImpl::RenderTarget *)v9;
}

// File Line: 198
// RVA: 0x969700
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateTempRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::RenderBuffer *pBuffer; // rsi
  unsigned int v6; // ebx
  unsigned int i; // edi
  unsigned int Height; // eax
  Scaleform::Render::ImageFormat format; // r15d
  unsigned __int64 requestSize; // rdi
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v11; // ecx
  Scaleform::Render::Texture *v12; // rax
  Scaleform::Render::Texture *v13; // rbx
  Scaleform::Render::RBGenericImpl::RenderTarget *v14; // rax
  unsigned int v15; // ecx
  unsigned int Width; // eax
  unsigned int v17; // eax
  unsigned int v18; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rax
  Scaleform::Render::Size<unsigned long> sizea; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::Render::RBGenericImpl::CacheData *pdata; // [rsp+A0h] [rbp+18h] BYREF
  Scaleform::Render::Texture *v22; // [rsp+A8h] [rbp+20h]

  if ( !this->pTextureManager.pObject )
    return 0i64;
  pdata = 0i64;
  pBuffer = 0i64;
  if ( this->RequirePow2 )
  {
    v6 = 1;
    for ( i = 1; v6 < size->Width; v6 *= 2 )
      ;
    Height = size->Height;
    if ( Height > 1 )
    {
      do
        i *= 2;
      while ( i < Height );
    }
  }
  else
  {
    i = (size->Height + 31) & 0xFFFFFFE0;
    v6 = (size->Width + 31) & 0xFFFFFFE0;
    if ( v6 < 0x20 )
      v6 = 32;
    if ( i < 0x20 )
      i = 32;
  }
  sizea.Height = i;
  sizea.Width = v6;
  format = this->DefImageFormat;
  requestSize = (unsigned __int64)(v6 * Scaleform::Render::ImageData::GetFormatBitsPerPixel(format, 0) * i) >> 3;
  v11 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
          this,
          &pdata,
          &sizea,
          RBuffer_Temporary,
          format,
          requestSize);
  if ( v11 )
  {
    if ( v11 == RS_Alloc )
    {
      v12 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64, Scaleform::Render::Size<unsigned long> *, int, _QWORD, _QWORD))this->pTextureManager.pObject->vfptr[1].__vecDelDtor)(
                                            this->pTextureManager.pObject,
                                            (unsigned int)format,
                                            1i64,
                                            &sizea,
                                            1024,
                                            0i64,
                                            0i64);
      v13 = v12;
      v22 = v12;
      if ( v12 )
      {
        v14 = Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
                this,
                &sizea,
                RBuffer_Temporary,
                format,
                v12);
        pBuffer = v14;
        if ( v14 )
        {
          v14->ListType = RBCL_InUse;
          v14->pNext = this->BufferCache[1].Root.pNext;
          v14->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
          this->BufferCache[1].Root.pNext->pPrev = &v14->Scaleform::Render::RBGenericImpl::CacheData;
          this->BufferCache[1].Root.pNext = &v14->Scaleform::Render::RBGenericImpl::CacheData;
          v15 = size->Height;
          Width = size->Width;
          pBuffer[1].vfptr = 0i64;
          pBuffer[1].RefCount = Width;
          *((_DWORD *)&pBuffer[1].RefCount + 1) = v15;
          pBuffer[2].vfptr = (Scaleform::RefCountImplCoreVtbl *)requestSize;
          this->AllocSize += requestSize;
        }
      }
      if ( v13 )
      {
        if ( !_InterlockedDecrement(&v13->RefCount) )
          v13->vfptr->__vecDelDtor(v13, 1u);
      }
    }
  }
  else
  {
    pBuffer = pdata->pBuffer;
    pBuffer->vfptr[5].__vecDelDtor(pBuffer, 1u);
    v17 = size->Width;
    v18 = size->Height;
    pBuffer[1].vfptr = 0i64;
    pBuffer[1].RefCount = v17;
    *((_DWORD *)&pBuffer[1].RefCount + 1) = v18;
    ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pBuffer->vfptr[1].__vecDelDtor)(pBuffer);
    pRenderTargetData = pBuffer->pRenderTargetData;
    if ( pRenderTargetData )
      pRenderTargetData->CacheID = 0i64;
  }
  return (Scaleform::Render::RenderTarget *)pBuffer;
}

// File Line: 259
// RVA: 0x966350
Scaleform::Render::DepthStencilBuffer *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateDepthStencilBuffer(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *size,
        bool temporary)
{
  Scaleform::Render::RenderBuffer *pBuffer; // rbx
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rdx
  unsigned int Height; // ecx
  int *v10; // rcx
  unsigned int v11; // ecx
  unsigned int i; // eax
  unsigned int v13; // r8d
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  Scaleform::Render::RenderBuffer::RenderTargetData *v17; // rbp
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v18; // ecx
  __int64 v19; // rsi
  Scaleform::Render::RBGenericImpl::CacheData *v20; // rdx
  unsigned int v21; // ecx
  unsigned int v22; // [rsp+30h] [rbp-58h] BYREF
  unsigned int v23; // [rsp+34h] [rbp-54h]
  Scaleform::Render::Size<unsigned long> sizea; // [rsp+38h] [rbp-50h] BYREF
  int v25[2]; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Render::RBGenericImpl::CacheData *pdata[5]; // [rsp+48h] [rbp-40h] BYREF
  int v27; // [rsp+A8h] [rbp+20h] BYREF

  pdata[1] = (Scaleform::Render::RBGenericImpl::CacheData *)-2i64;
  if ( !this->pTextureManager.pObject )
    return 0i64;
  pBuffer = 0i64;
  v8 = 0i64;
  pdata[0] = 0i64;
  if ( this->DepthStencilSizeMode == DSSM_Exact )
  {
    Height = size->Height;
    v25[0] = size->Width;
    v25[1] = Height;
    v10 = v25;
  }
  else
  {
    if ( this->RequirePow2 )
    {
      v11 = 1;
      for ( i = 1; v11 < size->Width; v11 *= 2 )
        ;
      v13 = size->Height;
      if ( v13 > 1 )
      {
        do
          i *= 2;
        while ( i < v13 );
      }
      v22 = v11;
      v23 = i;
    }
    else
    {
      v14 = (size->Height + 31) & 0xFFFFFFE0;
      v15 = (size->Width + 31) & 0xFFFFFFE0;
      if ( v15 < 0x20 )
        v15 = 32;
      v22 = v15;
      if ( v14 < 0x20 )
        v14 = 32;
      v23 = v14;
    }
    v10 = (int *)&v22;
  }
  v16 = v10[1];
  sizea.Width = *v10;
  sizea.Height = v16;
  v17 = (Scaleform::Render::RenderBuffer::RenderTargetData *)(4 * v16 * sizea.Width);
  if ( temporary )
  {
    v18 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
            this,
            pdata,
            &sizea,
            RBuffer_DepthStencil,
            Image_None,
            4 * v16 * sizea.Width);
    v8 = pdata[0];
  }
  else
  {
    v18 = RS_Alloc;
  }
  if ( v18 )
  {
    if ( v18 == RS_Alloc )
    {
      v19 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Size<unsigned long> *, _QWORD))this->pTextureManager.pObject->vfptr[5].__vecDelDtor)(
              this->pTextureManager.pObject,
              &sizea,
              0i64);
      pdata[2] = (Scaleform::Render::RBGenericImpl::CacheData *)v19;
      if ( v19 )
      {
        v27 = 72;
        v20 = (Scaleform::Render::RBGenericImpl::CacheData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               this,
                                                               96i64,
                                                               &v27);
        pdata[3] = v20;
        if ( v20 )
        {
          v20->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&Scaleform::RefCountImplCore::`vftable;
          LODWORD(v20->pNext) = 1;
          v20->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&Scaleform::RefCountVImpl::`vftable;
          v20->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&Scaleform::Render::RenderBuffer::`vftable;
          LODWORD(v20->pBuffer) = 6 - temporary;
          *(_QWORD *)&v20->ListType = this;
          v20->DataSize = 0i64;
          v21 = sizea.Height;
          LODWORD(v20[1].pPrev) = sizea.Width;
          HIDWORD(v20[1].pVoidPrev) = v21;
          v20->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&Scaleform::Render::DepthStencilBuffer::`vftable;
          v20[1].pNext = 0i64;
          v20[1].pBuffer = 0i64;
          *(_QWORD *)&v20[1].ListType = v20;
          v20[1].DataSize = 0i64;
          v20[2].pPrev = 0i64;
          v20->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&Scaleform::Render::RBGenericImpl::DepthStencilBuffer::`vftable;
          v20[2].pNext = 0i64;
          pBuffer = (Scaleform::Render::RenderBuffer *)v20;
        }
        if ( pBuffer )
        {
          Scaleform::Render::RBGenericImpl::DepthStencilBuffer::initSurface(
            (Scaleform::Render::RBGenericImpl::DepthStencilBuffer *)pBuffer,
            (Scaleform::Render::DepthStencilSurface *)v19);
          if ( temporary )
          {
            LODWORD(pBuffer[1].pManager) = 1;
            *(_QWORD *)&pBuffer[1].RefCount = this->BufferCache[1].Root.pNext;
            pBuffer[1].vfptr = (Scaleform::RefCountImplCoreVtbl *)&this->BufferCache[1];
            this->BufferCache[1].Root.pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&pBuffer[1];
            this->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&pBuffer[1];
            this->AllocSize += (unsigned __int64)v17;
          }
          pBuffer[1].pRenderTargetData = v17;
        }
      }
      if ( v19 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)(v19 + 8)) )
          (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1i64);
      }
    }
  }
  else
  {
    v8->pPrev->pNext = v8->pNext;
    v8->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = v8->pPrev;
    v8->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
    v8->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
    v8->ListType = RBCL_InUse;
    v8->pNext = this->BufferCache[1].Root.pNext;
    v8->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&this->BufferCache[1];
    this->BufferCache[1].Root.pNext->pPrev = v8;
    this->BufferCache[1].Root.pNext = v8;
    pBuffer = v8->pBuffer;
    ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pBuffer->vfptr[1].__vecDelDtor)(pBuffer);
  }
  return (Scaleform::Render::DepthStencilBuffer *)pBuffer;
}

// File Line: 354
// RVA: 0x9F0860
__int64 __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::CacheData **pdata,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        unsigned __int64 requestSize)
{
  unsigned __int64 AbsoluteLimit; // rax
  Scaleform::Render::RBGenericImpl::CacheData *Match; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v13; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v14; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v15; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v16; // rax
  unsigned __int64 v17; // rdx

  AbsoluteLimit = this->AbsoluteLimit;
  if ( AbsoluteLimit && requestSize > AbsoluteLimit )
    return 2i64;
  Match = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_Reuse_LRU, size, type, format);
  *pdata = Match;
  if ( Match )
    return 0i64;
  v13 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_Reuse_ThisFrame, size, type, format);
  *pdata = v13;
  if ( v13 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_Reuse_LRU, requestSize) )
    return 1i64;
  v14 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_LRU, size, type, format);
  *pdata = v14;
  if ( v14 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_LRU, requestSize)
    || Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(
         this,
         RBCL_Reuse_ThisFrame,
         requestSize) )
  {
    return 1i64;
  }
  v15 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_PrevFrame, size, type, format);
  *pdata = v15;
  if ( v15 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_PrevFrame, requestSize) )
    return 1i64;
  v16 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_ThisFrame, size, type, format);
  *pdata = v16;
  if ( !v16 )
  {
    if ( !Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(this, RBCL_ThisFrame, requestSize) )
    {
      v17 = this->AbsoluteLimit;
      if ( v17 )
      {
        if ( requestSize + this->AllocSize > v17 )
          return 2i64;
      }
    }
    return 1i64;
  }
  return 0i64;
}

// File Line: 407
// RVA: 0x9E2DE0
Scaleform::Render::RBGenericImpl::CacheData *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType bufferType,
        Scaleform::Render::ImageFormat format)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // rdi
  Scaleform::Render::RBGenericImpl::CacheData *i; // r10
  Scaleform::Render::RBGenericImpl::DSSizeMode DepthStencilSizeMode; // edx
  Scaleform::Render::RenderBuffer *pBuffer; // rax
  __int32 v10; // edx
  unsigned int Width; // r11d
  unsigned int Height; // edx
  unsigned int v13; // ecx

  v6 = &this->BufferCache[ltype];
  for ( i = v6->Root.pPrev; i != (Scaleform::Render::RBGenericImpl::CacheData *)v6; i = i->pPrev )
  {
    if ( bufferType == RBuffer_DepthStencil )
      DepthStencilSizeMode = this->DepthStencilSizeMode;
    else
      DepthStencilSizeMode = DSSM_None;
    pBuffer = i->pBuffer;
    if ( pBuffer->Type == bufferType && i->Format == format )
    {
      v10 = DepthStencilSizeMode - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          if ( pBuffer->BufferSize.Width >= size->Width && pBuffer->BufferSize.Height >= size->Height )
            return i;
        }
        else
        {
          Width = pBuffer->BufferSize.Width;
          if ( size->Width <= Width )
          {
            Height = size->Height;
            v13 = pBuffer->BufferSize.Height;
            if ( Height <= v13 && (27 * Width * v13) >> 5 <= size->Width * Height )
              return i;
          }
        }
      }
      else if ( size->Width == pBuffer->BufferSize.Width && size->Height == pBuffer->BufferSize.Height )
      {
        return i;
      }
    }
  }
  return 0i64;
}

// File Line: 458
// RVA: 0x9E22F0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        int ltype)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // rdi
  __int64 v4; // r14
  Scaleform::RefCountImplCoreVtbl *v5; // rbx
  void *(__fastcall *vecDelDtor)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v7)(Scaleform::RefCountImplCore *, unsigned int); // rbx
  int v8; // eax
  __int64 v9; // rcx
  void (__fastcall ***v10)(_QWORD, __int64); // rcx
  int v11; // eax

  v3 = &this->BufferCache[ltype];
  if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v3->Root.pNext != v3 )
  {
    v4 = 2 * (ltype + 5i64);
    do
    {
      v5 = (&this->vfptr)[v4];
      *((Scaleform::RefCountImplCoreVtbl *)v5->__vecDelDtor + 1) = v5[1];
      *(Scaleform::RefCountImplCoreVtbl *)v5[1].__vecDelDtor = (Scaleform::RefCountImplCoreVtbl)v5->__vecDelDtor;
      vecDelDtor = v5[4].__vecDelDtor;
      v5->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))-1i64;
      v5[1].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))-1i64;
      LODWORD(v5[3].__vecDelDtor) = 0;
      this->AllocSize -= (unsigned __int64)vecDelDtor;
      v5[4].__vecDelDtor = 0i64;
      v7 = v5[2].__vecDelDtor;
      v8 = *((_DWORD *)v7 + 4);
      if ( v8 == 3 )
      {
        v9 = *((_QWORD *)v7 + 13);
        if ( v9 && !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) )
          (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
        *((_QWORD *)v7 + 13) = 0i64;
        v10 = (void (__fastcall ***)(_QWORD, __int64))*((_QWORD *)v7 + 4);
        if ( v10 )
        {
          (**v10)(v10, 1i64);
          *((_QWORD *)v7 + 4) = 0i64;
        }
        v11 = *((_DWORD *)v7 + 2);
        *((_DWORD *)v7 + 28) = 3;
        if ( v11 )
          continue;
      }
      else if ( v8 != 5 || !v7 )
      {
        continue;
      }
      (**(void (__fastcall ***)(void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int), __int64))v7)(
        v7,
        1i64);
    }
    while ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v3->Root.pNext != v3 );
  }
}

// File Line: 464
// RVA: 0x9E2670
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // rsi
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // rbx
  unsigned __int64 DataSize; // rax
  Scaleform::Render::RenderBuffer *pBuffer; // rbx
  Scaleform::Render::RenderBufferType Type; // eax
  __int64 v8; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rcx
  volatile int RefCount; // eax

  if ( this->AllocSize > this->ReuseLimit )
  {
    v3 = &this->BufferCache[ltype];
    do
    {
      pPrev = v3->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v3->Root.pPrev == v3 )
        return;
      pPrev->pPrev->pNext = pPrev->pNext;
      pPrev->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = pPrev->pPrev;
      DataSize = pPrev->DataSize;
      pPrev->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      pPrev->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      pPrev->ListType = RBCL_Uncached;
      this->AllocSize -= DataSize;
      pPrev->DataSize = 0i64;
      pBuffer = pPrev->pBuffer;
      Type = pBuffer->Type;
      if ( Type == RBuffer_Temporary )
      {
        v8 = *(_QWORD *)&pBuffer[2].RefCount;
        if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
          (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
        *(_QWORD *)&pBuffer[2].RefCount = 0i64;
        pRenderTargetData = pBuffer->pRenderTargetData;
        if ( pRenderTargetData )
        {
          pRenderTargetData->vfptr->__vecDelDtor(pRenderTargetData, 1u);
          pBuffer->pRenderTargetData = 0i64;
        }
        RefCount = pBuffer->RefCount;
        pBuffer[2].Type = RBuffer_Temporary;
        if ( RefCount )
          continue;
      }
      else if ( Type != RBuffer_DepthStencil || !pBuffer )
      {
        continue;
      }
      pBuffer->vfptr->__vecDelDtor(pBuffer, 1u);
    }
    while ( this->AllocSize > this->ReuseLimit );
  }
}

// File Line: 476
// RVA: 0x9E2780
bool __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::RBGenericImpl::RBCacheListType ltype,
        unsigned __int64 requestSize)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v5; // r14
  Scaleform::Render::RBGenericImpl::CacheData *pPrev; // rbx
  unsigned __int64 DataSize; // rax
  Scaleform::Render::RenderBuffer *pBuffer; // rbx
  Scaleform::Render::RenderBufferType Type; // eax
  __int64 v10; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rcx
  volatile int RefCount; // eax

  if ( requestSize + this->AllocSize > this->ReuseLimit )
  {
    v5 = &this->BufferCache[ltype];
    do
    {
      pPrev = v5->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v5->Root.pPrev == v5 )
        return requestSize + this->AllocSize <= this->ReuseLimit;
      pPrev->pPrev->pNext = pPrev->pNext;
      pPrev->pNext->Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = pPrev->pPrev;
      DataSize = pPrev->DataSize;
      pPrev->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      pPrev->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      pPrev->ListType = RBCL_Uncached;
      this->AllocSize -= DataSize;
      pPrev->DataSize = 0i64;
      pBuffer = pPrev->pBuffer;
      Type = pBuffer->Type;
      if ( Type == RBuffer_Temporary )
      {
        v10 = *(_QWORD *)&pBuffer[2].RefCount;
        if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) )
          (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
        *(_QWORD *)&pBuffer[2].RefCount = 0i64;
        pRenderTargetData = pBuffer->pRenderTargetData;
        if ( pRenderTargetData )
        {
          pRenderTargetData->vfptr->__vecDelDtor(pRenderTargetData, 1u);
          pBuffer->pRenderTargetData = 0i64;
        }
        RefCount = pBuffer->RefCount;
        pBuffer[2].Type = RBuffer_Temporary;
        if ( RefCount )
          continue;
      }
      else if ( Type != RBuffer_DepthStencil || !pBuffer )
      {
        continue;
      }
      pBuffer->vfptr->__vecDelDtor(pBuffer, 1u);
    }
    while ( requestSize + this->AllocSize > this->ReuseLimit );
  }
  return requestSize + this->AllocSize <= this->ReuseLimit;
}

// File Line: 493
// RVA: 0x9B0C00
void __fastcall Scaleform::Render::RBGenericImpl::RenderTarget::SetInUse(
        Scaleform::Render::RBGenericImpl::RenderTarget *this,
        Scaleform::Render::RenderTargetUse inUse)
{
  int v2; // edx
  Scaleform::Render::RenderBufferManager *v3; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *vfptr; // rax
  Scaleform::Render::RenderBufferManager *pManager; // rdx

  if ( this->Type == RBuffer_Temporary )
  {
    if ( inUse == RTUse_Unused )
      goto LABEL_5;
    v2 = inUse - 1;
    if ( !v2 )
    {
      pManager = this->pManager;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = this->pPrev;
      this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      this->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      this->ListType = RBCL_InUse;
      this->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)pManager[6].vfptr;
      this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&pManager[5].RefCount;
      pManager[6].vfptr->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))&this->Scaleform::Render::RBGenericImpl::CacheData;
      pManager[6].vfptr = (Scaleform::RefCountImplCoreVtbl *)&this->Scaleform::Render::RBGenericImpl::CacheData;
      this->RTStatus = RTS_InUse;
      return;
    }
    if ( v2 == 1 )
    {
LABEL_5:
      if ( this->ListType < RBCL_ThisFrame )
      {
        v3 = this->pManager;
        this->pPrev->pNext = this->pNext;
        this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = this->pPrev;
        this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
        this->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
        this->ListType = RBCL_ThisFrame;
        vfptr = (Scaleform::Render::RBGenericImpl::CacheData *)v3[7].vfptr;
        this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v3[6].RefCount;
        this->pNext = vfptr;
        v3[7].vfptr->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))&this->Scaleform::Render::RBGenericImpl::CacheData;
        v3[7].vfptr = (Scaleform::RefCountImplCoreVtbl *)&this->Scaleform::Render::RBGenericImpl::CacheData;
      }
      this->RTStatus = RTS_Available;
    }
  }
}

// File Line: 528
// RVA: 0x9A7CA0
void __fastcall Scaleform::Render::RBGenericImpl::RenderTarget::Release(
        Scaleform::Render::RBGenericImpl::RenderTarget *this)
{
  Scaleform::Render::RenderBufferManager *pManager; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v3; // r9
  bool v4; // zf
  bool v5; // sf
  bool v6; // of
  Scaleform::Render::RBGenericImpl::RBCacheListType v7; // r8d
  __int64 v8; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v9; // rax

  if ( --this->RefCount <= 0 )
  {
    if ( this->pBuffer->Scaleform::Render::RBGenericImpl::CacheData::Type != RBuffer_Temporary
      || this->RTStatus == RTS_Lost )
    {
      this->vfptr->__vecDelDtor(this, 1i64);
    }
    else
    {
      pManager = this->pManager;
      v3 = &this->Scaleform::Render::RBGenericImpl::CacheData;
      v6 = __OFSUB__(this->ListType, 2);
      v4 = this->ListType == RBCL_ThisFrame;
      v5 = this->ListType - 2 < 0;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = this->pPrev;
      this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      this->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v7 = !(v5 ^ v6 | v4) + 5;
      this->ListType = v7;
      v8 = (__int64)(&pManager[4].RefCount + 4 * v7);
      v9 = *(Scaleform::Render::RBGenericImpl::CacheData **)(v8 + 8);
      v3->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v8;
      v3->pNext = v9;
      **(_QWORD **)(v8 + 8) = v3;
      *(_QWORD *)(v8 + 8) = v3;
      this->RTStatus = RTS_Available;
    }
  }
}

// File Line: 566
// RVA: 0x9548A0
void __fastcall SSClassUnion::reference(SSContextClassBase *this)
{
  ++this->i_ref_count;
}

// File Line: 571
// RVA: 0x9A7620
void __fastcall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::Release(
        Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this)
{
  Scaleform::Render::RenderBufferManager *pManager; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v2; // r9
  bool v3; // zf
  bool v4; // sf
  bool v5; // of
  Scaleform::Render::RBGenericImpl::RBCacheListType v6; // r8d
  __int64 v7; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rax

  if ( --this->RefCount <= 0 )
  {
    if ( this->Type == RBuffer_DepthStencil )
    {
      pManager = this->pManager;
      v2 = &this->Scaleform::Render::RBGenericImpl::CacheData;
      v5 = __OFSUB__(this->ListType, 2);
      v3 = this->ListType == RBCL_ThisFrame;
      v4 = this->ListType - 2 < 0;
      this->pPrev->pNext = this->pNext;
      this->pNext->Scaleform::Render::RBGenericImpl::CacheData::Scaleform::ListNode<Scaleform::Render::RBGenericImpl::CacheData>::$F22CD053336D31DA893D15F8BA025614::pPrev = this->pPrev;
      this->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      this->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v6 = !(v4 ^ v5 | v3) + 5;
      this->ListType = v6;
      v7 = (__int64)(&pManager[4].RefCount + 4 * v6);
      v8 = *(Scaleform::Render::RBGenericImpl::CacheData **)(v7 + 8);
      v2->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v7;
      v2->pNext = v8;
      **(_QWORD **)(v7 + 8) = v2;
      *(_QWORD *)(v7 + 8) = v2;
    }
    else
    {
      this->vfptr->__vecDelDtor(this, 1i64);
    }
  }
}

