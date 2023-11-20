// File Line: 89
// RVA: 0x941140
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::DSSizeMode depthStencilSizeMode, unsigned __int64 memReuseLimit, unsigned __int64 memAbsoluteLimit)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v4; // rcx

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
  this->DefImageFormat = 0;
  this->RequirePow2 = 0;
  this->DepthStencilSizeMode = depthStencilSizeMode;
  v4 = this->BufferCache;
  v4->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
  v4->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
  v4[1].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[1];
  v4[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[1];
  v4[2].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[2];
  v4[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[2];
  v4[3].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[3];
  v4[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[3];
  v4[4].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[4];
  v4[4].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[4];
  v4[5].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[5];
  v4[5].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[5];
  v4[6].Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[6];
  v4[6].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v4[6];
}

// File Line: 93
// RVA: 0x94C360
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::~RenderBufferManager(Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v1; // rdi
  Scaleform::Render::TextureManager *v2; // rcx
  Scaleform::Render::TextureManager *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RBGenericImpl::RenderBufferManager::`vftable;
  ((void (__cdecl *)(Scaleform::Render::RBGenericImpl::RenderBufferManager *))this->vfptr[4].__vecDelDtor)(this);
  v1->DefImageFormat = 0;
  v2 = v1->pTextureManager.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v1->pTextureManager.pObject = 0i64;
  v3 = v1->pTextureManager.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBufferManager::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 99
// RVA: 0x994270
char __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Initialize(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::TextureManager *manager, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *screenSize)
{
  Scaleform::Render::Size<unsigned long> *v4; // rsi
  Scaleform::Render::ImageFormat v5; // ebp
  Scaleform::Render::TextureManager *v6; // rdi
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v7; // rbx
  Scaleform::Render::TextureManager *v8; // rcx
  unsigned __int64 v9; // rax

  v4 = screenSize;
  v5 = format;
  v6 = manager;
  v7 = this;
  if ( manager )
    _InterlockedExchangeAdd(&manager->RefCount, 1u);
  v8 = this->pTextureManager.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) && v8 )
    v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
  v7->pTextureManager.pObject = v6;
  v7->DefImageFormat = v5;
  v7->RequirePow2 = ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64))v6->vfptr[4].__vecDelDtor)(
                      v6,
                      (unsigned int)v5,
                      1024i64) == 0;
  v9 = v7->CtorReuseLimit;
  if ( v9 == -1i64 )
  {
    if ( v4->Width || v4->Height )
      v9 = 16 * v4->Width * v4->Height;
    else
      v9 = 0i64;
  }
  v7->ReuseLimit = v9;
  return 1;
}

// File Line: 115
// RVA: 0x96D3D0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Destroy(Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v1; // rbx
  Scaleform::Render::TextureManager *v2; // rcx

  v1 = this;
  ((void (*)(void))this->vfptr[4].__vecDelDtor)();
  v1->DefImageFormat = 0;
  v2 = v1->pTextureManager.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v1->pTextureManager.pObject = 0i64;
}

// File Line: 122
// RVA: 0x970770
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::EndFrame(Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v1; // rbx
  Scaleform::Render::RBGenericImpl::CacheData *v2; // r8
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // rax
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v4; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v5; // rcx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // r8
  Scaleform::Render::RBGenericImpl::CacheData *v7; // r9
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v9; // r9
  Scaleform::Render::RBGenericImpl::CacheData *v10; // rcx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v11; // rax
  signed __int64 v12; // rbx
  signed __int64 *v13; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v14; // rcx

  v1 = this;
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(this, RBCL_Reuse_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(v1, RBCL_LRU);
  if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v1->BufferCache[0].Root.pNext != v1->BufferCache
    || (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v1->BufferCache[1].Root.pNext != &v1->BufferCache[1] )
  {
    ((void (__fastcall *)(Scaleform::Render::RBGenericImpl::RenderBufferManager *))v1->vfptr[8].__vecDelDtor)(v1);
  }
  v2 = v1->BufferCache[1].Root.pNext;
  v3 = &v1->BufferCache[1];
  v4 = &v1->BufferCache[2];
  if ( v2 != (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[1] )
  {
    v5 = v3->Root.pPrev;
    v1->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[1];
    v3->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v3;
    v5->pNext = v1->BufferCache[2].Root.pNext;
    v2->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
    v1->BufferCache[2].Root.pNext->pPrev = v5;
    v1->BufferCache[2].Root.pNext = v2;
  }
  v6 = &v1->BufferCache[3];
  v7 = v1->BufferCache[3].Root.pNext;
  if ( v7 != (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[3] )
  {
    v8 = v6->Root.pPrev;
    v1->BufferCache[3].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[3];
    v6->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v6;
    v8->pNext = v1->BufferCache[4].Root.pNext;
    v7->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[4];
    v1->BufferCache[4].Root.pNext->pPrev = v8;
    v1->BufferCache[4].Root.pNext = v7;
  }
  v9 = v1->BufferCache[2].Root.pNext;
  if ( v9 != (Scaleform::Render::RBGenericImpl::CacheData *)v4 )
  {
    v10 = v4->Root.pPrev;
    v1->BufferCache[2].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v1->BufferCache[2];
    v4->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v4;
    v10->pNext = v1->BufferCache[3].Root.pNext;
    v9->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v6;
    v1->BufferCache[3].Root.pNext->pPrev = v10;
    v1->BufferCache[3].Root.pNext = v9;
  }
  v11 = &v1->BufferCache[5];
  v12 = (signed __int64)&v1->BufferCache[6];
  v13 = (signed __int64 *)v11->Root.pNext;
  if ( v13 != (signed __int64 *)v11 )
  {
    v14 = v11->Root.pPrev;
    v11->Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v11;
    v11->Root.pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v11;
    v14->pNext = *(Scaleform::Render::RBGenericImpl::CacheData **)(v12 + 8);
    *v13 = v12;
    **(_QWORD **)(v12 + 8) = v14;
    *(_QWORD *)(v12 + 8) = v13;
  }
}

// File Line: 137
// RVA: 0x9AB9F0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::Reset(Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v1; // rbx

  v1 = this;
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(this, RBCL_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(v1, RBCL_PrevFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(v1, RBCL_LRU);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(v1, RBCL_Reuse_ThisFrame);
  Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(v1, RBCL_Reuse_LRU);
}

// File Line: 149
// RVA: 0x96F4D0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::DumpUsage(Scaleform::Render::RBGenericImpl::RenderBufferManager *this)
{
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v1; // rcx
  signed __int64 v2; // rdx
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *i; // rax

  v1 = this->BufferCache;
  v2 = 7i64;
  do
  {
    for ( i = (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v1->Root.pNext;
          i != v1;
          i = (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)i->Root.pNext )
    {
      ;
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 164
// RVA: 0x969330
Scaleform::Render::RBGenericImpl::RenderTarget *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateRenderTarget(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::RenderBufferType type, Scaleform::Render::ImageFormat format, Scaleform::Render::Texture *texture)
{
  Scaleform::Render::RBGenericImpl::RenderTarget *result; // rax

  if ( this->pTextureManager.pObject )
    result = Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
               this,
               size,
               type,
               format,
               texture);
  else
    result = 0i64;
  return result;
}

// File Line: 174
// RVA: 0x9DE430
Scaleform::Render::RBGenericImpl::RenderTarget *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::RenderBufferType type, Scaleform::Render::ImageFormat format, Scaleform::Render::Texture *texture)
{
  Scaleform::Render::ImageFormat v5; // esi
  Scaleform::Render::RenderBufferType v6; // ebp
  Scaleform::Render::Size<unsigned long> *v7; // r14
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v8; // rdi
  __int64 v9; // rbx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  __int64 v13; // rcx
  unsigned int v14; // ecx
  unsigned int v15; // edx
  int v17; // [rsp+20h] [rbp-38h]
  __int64 v18; // [rsp+28h] [rbp-30h]
  __int64 v19; // [rsp+30h] [rbp-28h]

  v18 = -2i64;
  v5 = format;
  v6 = type;
  v7 = size;
  v8 = this;
  v17 = 72;
  v9 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::RBGenericImpl::RenderBufferManager *, signed __int64, int *, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         this,
         120i64,
         &v17,
         *(_QWORD *)&v17,
         -2i64);
  v19 = v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v9 + 8) = 1;
    *(_QWORD *)v9 = &Scaleform::RefCountVImpl::`vftable;
    *(_QWORD *)v9 = &Scaleform::Render::RenderBuffer::`vftable;
    *(_DWORD *)(v9 + 16) = v6;
    *(_QWORD *)(v9 + 24) = v8;
    *(_QWORD *)(v9 + 32) = 0i64;
    v10 = v7->Height;
    *(_DWORD *)(v9 + 40) = v7->Width;
    *(_DWORD *)(v9 + 44) = v10;
    *(_QWORD *)v9 = &Scaleform::Render::RenderTarget::`vftable;
    v11 = v7->Height;
    v12 = v7->Width;
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_DWORD *)(v9 + 56) = v12;
    *(_DWORD *)(v9 + 60) = v11;
    *(_QWORD *)(v9 + 64) = 0i64;
    *(_QWORD *)(v9 + 72) = 0i64;
    *(_QWORD *)(v9 + 80) = v9;
    *(_QWORD *)(v9 + 88) = 0i64;
    *(_QWORD *)(v9 + 96) = 0i64;
    *(_QWORD *)v9 = &Scaleform::Render::RBGenericImpl::RenderTarget::`vftable;
    *(_QWORD *)(v9 + 104) = 0i64;
    *(_DWORD *)(v9 + 112) = 0;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v9 )
  {
    *(_DWORD *)(v9 + 92) = v5;
    if ( texture )
      _InterlockedExchangeAdd(&texture->RefCount, 1u);
    v13 = *(_QWORD *)(v9 + 104);
    if ( v13 && !_InterlockedDecrement((volatile signed __int32 *)(v13 + 8)) && v13 )
      (**(void (__fastcall ***)(__int64, signed __int64))v13)(v13, 1i64);
    *(_QWORD *)(v9 + 104) = texture;
    v14 = v7->Width;
    v15 = v7->Height;
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_DWORD *)(v9 + 56) = v14;
    *(_DWORD *)(v9 + 60) = v15;
  }
  return (Scaleform::Render::RBGenericImpl::RenderTarget *)v9;
}

// File Line: 198
// RVA: 0x969700
Scaleform::Render::RenderBuffer *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateTempRenderTarget(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::Size<unsigned long> *size)
{
  Scaleform::Render::Size<unsigned long> *v2; // r14
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v3; // rbp
  Scaleform::Render::RenderBuffer *v5; // rsi
  unsigned int v6; // ebx
  unsigned int i; // edi
  unsigned int v8; // eax
  Scaleform::Render::ImageFormat v9; // er15
  unsigned __int64 requestSize; // rdi
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v11; // ecx
  Scaleform::Render::Texture *v12; // rax
  Scaleform::Render::Texture *v13; // rbx
  Scaleform::Render::RBGenericImpl::RenderTarget *v14; // rax
  signed __int64 v15; // r8
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ecx
  Scaleform::Render::RenderBuffer::RenderTargetData *v20; // rax
  __int64 format; // [rsp+20h] [rbp-68h]
  Scaleform::Render::Size<unsigned long> sizea; // [rsp+90h] [rbp+8h]
  Scaleform::Render::RBGenericImpl::CacheData *pdata; // [rsp+A0h] [rbp+18h]
  Scaleform::Render::Texture *v24; // [rsp+A8h] [rbp+20h]

  v2 = size;
  v3 = this;
  if ( !this->pTextureManager.pObject )
    return 0i64;
  pdata = 0i64;
  v5 = 0i64;
  if ( this->RequirePow2 )
  {
    v6 = 1;
    for ( i = 1; v6 < size->Width; v6 *= 2 )
      ;
    v8 = size->Height;
    if ( v8 > 1 )
    {
      do
        i *= 2;
      while ( i < v8 );
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
  v9 = this->DefImageFormat;
  requestSize = (unsigned __int64)(v6 * Scaleform::Render::ImageData::GetFormatBitsPerPixel(this->DefImageFormat, 0) * i) >> 3;
  v11 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
          v3,
          &pdata,
          &sizea,
          RBuffer_Temporary,
          v9,
          requestSize);
  if ( v11 )
  {
    if ( v11 == 1 )
    {
      LODWORD(format) = 1024;
      v12 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64, Scaleform::Render::Size<unsigned long> *, __int64, _QWORD, _QWORD))v3->pTextureManager.pObject->vfptr[1].__vecDelDtor)(
                                            v3->pTextureManager.pObject,
                                            (unsigned int)v9,
                                            1i64,
                                            &sizea,
                                            format,
                                            0i64,
                                            0i64);
      v13 = v12;
      v24 = v12;
      if ( v12 )
      {
        v14 = Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
                v3,
                &sizea,
                RBuffer_Temporary,
                v9,
                v12);
        v5 = (Scaleform::Render::RenderBuffer *)&v14->vfptr;
        if ( v14 )
        {
          v15 = (signed __int64)&v14->0;
          *(_DWORD *)(v15 + 24) = 1;
          *(_QWORD *)(v15 + 8) = v3->BufferCache[1].Root.pNext;
          *(_QWORD *)v15 = (char *)v3 + 88;
          v3->BufferCache[1].Root.pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v14->0;
          v3->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v14->0;
          v16 = v2->Height;
          v17 = v2->Width;
          v5[1].vfptr = 0i64;
          v5[1].RefCount = v17;
          *((_DWORD *)&v5[1].RefCount + 1) = v16;
          v5[2].vfptr = (Scaleform::RefCountImplCoreVtbl *)requestSize;
          v3->AllocSize += requestSize;
        }
      }
      if ( v13 )
      {
        if ( !_InterlockedDecrement(&v13->RefCount) )
          v13->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, 1u);
      }
    }
  }
  else
  {
    v5 = pdata->pBuffer;
    v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&pdata->pBuffer->vfptr, 1u);
    v18 = v2->Width;
    v19 = v2->Height;
    v5[1].vfptr = 0i64;
    v5[1].RefCount = v18;
    *((_DWORD *)&v5[1].RefCount + 1) = v19;
    ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v5->vfptr[1].__vecDelDtor)(v5);
    v20 = v5->pRenderTargetData;
    if ( v20 )
      v20->CacheID = 0i64;
  }
  return v5;
}

// File Line: 259
// RVA: 0x966350
Scaleform::Render::RBGenericImpl::DepthStencilBuffer *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateDepthStencilBuffer(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::Size<unsigned long> *size, bool temporary)
{
  bool v3; // r14
  Scaleform::Render::Size<unsigned long> *v4; // r9
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v5; // rdi
  Scaleform::Render::RBGenericImpl::DepthStencilBuffer *v7; // rbx
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rdx
  int v9; // ecx
  int *v10; // rcx
  unsigned int v11; // ecx
  unsigned int i; // eax
  unsigned int v13; // er8
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ecx
  unsigned __int64 v19; // rbp
  Scaleform::Render::RBGenericImpl::RenderBufferManager::ReserveSpaceResult v20; // ecx
  Scaleform::Render::DepthStencilSurface *v21; // rsi
  _DWORD *v22; // rdx
  unsigned int v23; // ecx
  signed __int64 v24; // rdx
  unsigned int v25; // [rsp+30h] [rbp-58h]
  unsigned int v26; // [rsp+34h] [rbp-54h]
  Scaleform::Render::Size<unsigned long> sizea; // [rsp+38h] [rbp-50h]
  unsigned int v28; // [rsp+40h] [rbp-48h]
  int v29; // [rsp+44h] [rbp-44h]
  Scaleform::Render::RBGenericImpl::CacheData *pdata; // [rsp+48h] [rbp-40h]
  __int64 v31; // [rsp+50h] [rbp-38h]
  Scaleform::Render::DepthStencilSurface *v32; // [rsp+58h] [rbp-30h]
  _DWORD *v33; // [rsp+60h] [rbp-28h]
  int v34; // [rsp+A8h] [rbp+20h]

  v31 = -2i64;
  v3 = temporary;
  v4 = size;
  v5 = this;
  if ( !this->pTextureManager.pObject )
    return 0i64;
  v7 = 0i64;
  v8 = 0i64;
  pdata = 0i64;
  if ( this->DepthStencilSizeMode == 1 )
  {
    v9 = v4->Height;
    v28 = v4->Width;
    v29 = v9;
    v10 = (int *)&v28;
  }
  else
  {
    if ( this->RequirePow2 )
    {
      v11 = 1;
      for ( i = 1; v11 < v4->Width; v11 *= 2 )
        ;
      v13 = v4->Height;
      if ( v13 > 1 )
      {
        do
          i *= 2;
        while ( i < v13 );
      }
      v25 = v11;
      v26 = i;
    }
    else
    {
      v14 = (v4->Height + 31) & 0xFFFFFFE0;
      v15 = (v4->Width + 31) & 0xFFFFFFE0;
      if ( v15 < 0x20 )
        v15 = 32;
      v25 = v15;
      if ( v14 < 0x20 )
        v14 = 32;
      v26 = v14;
    }
    v10 = (int *)&v25;
  }
  v16 = v10[1];
  v17 = *v10;
  sizea.Width = v17;
  sizea.Height = v16;
  v18 = 4 * v16 * v17;
  v19 = v18;
  if ( v3 )
  {
    v20 = Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(
            v5,
            &pdata,
            &sizea,
            RBuffer_DepthStencil,
            0,
            v18);
    v8 = pdata;
  }
  else
  {
    v20 = 1;
  }
  if ( v20 )
  {
    if ( v20 == 1 )
    {
      v21 = (Scaleform::Render::DepthStencilSurface *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, Scaleform::Render::Size<unsigned long> *, _QWORD))v5->pTextureManager.pObject->vfptr[5].__vecDelDtor)(
                                                        v5->pTextureManager.pObject,
                                                        &sizea,
                                                        0i64);
      v32 = v21;
      if ( v21 )
      {
        v34 = 72;
        v22 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                          Scaleform::Memory::pGlobalHeap,
                          v5,
                          96ui64,
                          (Scaleform::AllocInfo *)&v34);
        v33 = v22;
        if ( v22 )
        {
          *(_QWORD *)v22 = &Scaleform::RefCountImplCore::`vftable;
          v22[2] = 1;
          *(_QWORD *)v22 = &Scaleform::RefCountVImpl::`vftable;
          *(_QWORD *)v22 = &Scaleform::Render::RenderBuffer::`vftable;
          v22[4] = 6 - (v3 != 0);
          *((_QWORD *)v22 + 3) = v5;
          *((_QWORD *)v22 + 4) = 0i64;
          v23 = sizea.Height;
          v22[10] = sizea.Width;
          v22[11] = v23;
          *(_QWORD *)v22 = &Scaleform::Render::DepthStencilBuffer::`vftable;
          *((_QWORD *)v22 + 6) = 0i64;
          *((_QWORD *)v22 + 7) = 0i64;
          *((_QWORD *)v22 + 8) = v22;
          *((_QWORD *)v22 + 9) = 0i64;
          *((_QWORD *)v22 + 10) = 0i64;
          *(_QWORD *)v22 = &Scaleform::Render::RBGenericImpl::DepthStencilBuffer::`vftable;
          *((_QWORD *)v22 + 11) = 0i64;
          v7 = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer *)v22;
        }
        if ( v7 )
        {
          Scaleform::Render::RBGenericImpl::DepthStencilBuffer::initSurface(v7, v21);
          if ( v3 )
          {
            v24 = (signed __int64)&v7->0;
            *(_DWORD *)(v24 + 24) = 1;
            *(_QWORD *)(v24 + 8) = v5->BufferCache[1].Root.pNext;
            *(_QWORD *)v24 = (char *)v5 + 88;
            v5->BufferCache[1].Root.pNext->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v7->0;
            v5->BufferCache[1].Root.pNext = (Scaleform::Render::RBGenericImpl::CacheData *)&v7->0;
            v5->AllocSize += v19;
          }
          v7->DataSize = v19;
        }
      }
      if ( v21 )
      {
        if ( !_InterlockedDecrement(&v21->RefCount) )
          v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
      }
    }
  }
  else
  {
    v8->pPrev->pNext = v8->pNext;
    v8->pNext->pPrev = v8->pPrev;
    v8->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
    v8->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
    v8->ListType = 1;
    v8->pNext = v5->BufferCache[1].Root.pNext;
    v8->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v5->BufferCache[1];
    v5->BufferCache[1].Root.pNext->pPrev = v8;
    v5->BufferCache[1].Root.pNext = v8;
    v7 = (Scaleform::Render::RBGenericImpl::DepthStencilBuffer *)v8->pBuffer;
    ((void (__fastcall *)(Scaleform::Render::RBGenericImpl::DepthStencilBuffer *))v7->vfptr[1].__vecDelDtor)(v7);
  }
  return v7;
}

// File Line: 354
// RVA: 0x9F0860
signed __int64 __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::reserveSpace(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::CacheData **pdata, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::RenderBufferType type, Scaleform::Render::ImageFormat format, unsigned __int64 requestSize)
{
  unsigned __int64 v6; // rax
  Scaleform::Render::RenderBufferType v7; // esi
  Scaleform::Render::Size<unsigned long> *v8; // rbp
  Scaleform::Render::RBGenericImpl::CacheData **v9; // r14
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v10; // rbx
  Scaleform::Render::RBGenericImpl::CacheData *v12; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v13; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v14; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v15; // rax
  Scaleform::Render::RBGenericImpl::CacheData *v16; // rax
  unsigned __int64 v17; // rdx

  v6 = this->AbsoluteLimit;
  v7 = type;
  v8 = size;
  v9 = pdata;
  v10 = this;
  if ( v6 && requestSize > v6 )
    return 2i64;
  v12 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(this, RBCL_Reuse_LRU, size, type, format);
  *v9 = v12;
  if ( v12 )
    return 0i64;
  v13 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(v10, RBCL_Reuse_ThisFrame, v8, v7, format);
  *v9 = v13;
  if ( v13 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(v10, RBCL_Reuse_LRU, requestSize) )
    return 1i64;
  v14 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(v10, RBCL_LRU, v8, v7, format);
  *v9 = v14;
  if ( v14 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(v10, RBCL_LRU, requestSize)
    || Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(
         v10,
         RBCL_Reuse_ThisFrame,
         requestSize) )
  {
    return 1i64;
  }
  v15 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(v10, RBCL_PrevFrame, v8, v7, format);
  *v9 = v15;
  if ( v15 )
    return 0i64;
  if ( Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(v10, RBCL_PrevFrame, requestSize) )
    return 1i64;
  v16 = Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(v10, RBCL_ThisFrame, v8, v7, format);
  *v9 = v16;
  if ( !v16 )
  {
    if ( !Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(v10, RBCL_ThisFrame, requestSize) )
    {
      v17 = v10->AbsoluteLimit;
      if ( v17 )
      {
        if ( requestSize + v10->AllocSize > v17 )
          return 2i64;
      }
    }
    return 1i64;
  }
  return 0i64;
}

// File Line: 407
// RVA: 0x9E2DE0
Scaleform::Render::RBGenericImpl::CacheData *__fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::findMatch(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::RBCacheListType ltype, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::RenderBufferType bufferType, Scaleform::Render::ImageFormat format)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v5; // rsi
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v6; // rdi
  Scaleform::Render::RBGenericImpl::CacheData *i; // r10
  Scaleform::Render::RBGenericImpl::DSSizeMode v8; // edx
  Scaleform::Render::RenderBuffer *v9; // rax
  int v10; // edx
  unsigned int v11; // er11
  unsigned int v12; // edx
  unsigned int v13; // ecx

  v5 = this;
  v6 = &this->BufferCache[ltype];
  for ( i = v6->Root.pPrev; i != (Scaleform::Render::RBGenericImpl::CacheData *)v6; i = i->pPrev )
  {
    if ( bufferType == 5 )
      v8 = v5->DepthStencilSizeMode;
    else
      v8 = 0;
    v9 = i->pBuffer;
    if ( v9->Type == bufferType && i->Format == format )
    {
      v10 = v8 - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
        {
          if ( v9->BufferSize.Width >= size->Width && v9->BufferSize.Height >= size->Height )
            return i;
        }
        else
        {
          v11 = v9->BufferSize.Width;
          if ( size->Width <= v11 )
          {
            v12 = size->Height;
            v13 = v9->BufferSize.Height;
            if ( v12 <= v13 && 27 * v11 * v13 >> 5 <= size->Width * v12 )
              return i;
          }
        }
      }
      else if ( *size == *(_QWORD *)&v9->BufferSize )
      {
        return i;
      }
    }
  }
  return 0i64;
}

// File Line: 458
// RVA: 0x9E22F0
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictAll(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::RBCacheListType ltype)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v2; // rsi
  char **v3; // rdi
  signed __int64 v4; // r14
  Scaleform::RefCountImplCoreVtbl *v5; // rbx
  void *(__fastcall *v6)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v7)(Scaleform::RefCountImplCore *, unsigned int); // rbx
  int v8; // eax
  __int64 v9; // rcx
  void (__fastcall ***v10)(_QWORD, signed __int64); // rcx
  int v11; // eax

  v2 = this;
  v3 = (char **)&this->BufferCache[ltype];
  if ( v3[1] != (char *)v3 )
  {
    v4 = 2 * ((signed int)ltype + 5i64);
    do
    {
      v5 = (&v2->vfptr)[v4];
      *((Scaleform::RefCountImplCoreVtbl *)v5->__vecDelDtor + 1) = v5[1];
      *(Scaleform::RefCountImplCoreVtbl *)v5[1].__vecDelDtor = (Scaleform::RefCountImplCoreVtbl)v5->__vecDelDtor;
      v6 = v5[4].__vecDelDtor;
      v5->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))-1i64;
      v5[1].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))-1i64;
      LODWORD(v5[3].__vecDelDtor) = 0;
      v2->AllocSize -= (unsigned __int64)v6;
      v5[4].__vecDelDtor = 0i64;
      v7 = v5[2].__vecDelDtor;
      v8 = *((_DWORD *)v7 + 4);
      if ( v8 == 3 )
      {
        v9 = *((_QWORD *)v7 + 13);
        if ( v9 && !_InterlockedDecrement((volatile signed __int32 *)(v9 + 8)) && v9 )
          (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
        *((_QWORD *)v7 + 13) = 0i64;
        v10 = (void (__fastcall ***)(_QWORD, signed __int64))*((_QWORD *)v7 + 4);
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
      (**(void (__fastcall ***)(void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int), signed __int64))v7)(
        v7,
        1i64);
    }
    while ( v3[1] != (char *)v3 );
  }
}

// File Line: 464
// RVA: 0x9E2670
void __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictOverReuseLimit(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::RBCacheListType ltype)
{
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v2; // rdi
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v3; // rsi
  Scaleform::Render::RBGenericImpl::CacheData *v4; // rbx
  unsigned __int64 v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rbx
  Scaleform::Render::RenderBufferType v7; // eax
  __int64 v8; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *v9; // rcx
  volatile int v10; // eax

  v2 = this;
  if ( this->AllocSize > this->ReuseLimit )
  {
    v3 = &this->BufferCache[ltype];
    do
    {
      v4 = v3->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v3->Root.pPrev == v3 )
        return;
      v4->pPrev->pNext = v4->pNext;
      v4->pNext->pPrev = v4->pPrev;
      v5 = v4->DataSize;
      v4->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v4->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v4->ListType = 0;
      v2->AllocSize -= v5;
      v4->DataSize = 0i64;
      v6 = v4->pBuffer;
      v7 = v6->Type;
      if ( v7 == 3 )
      {
        v8 = *(_QWORD *)&v6[2].RefCount;
        if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) && v8 )
          (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
        *(_QWORD *)&v6[2].RefCount = 0i64;
        v9 = v6->pRenderTargetData;
        if ( v9 )
        {
          v9->vfptr->__vecDelDtor(v9, 1u);
          v6->pRenderTargetData = 0i64;
        }
        v10 = v6->RefCount;
        v6[2].Type = 3;
        if ( v10 )
          continue;
      }
      else if ( v7 != 5 || !v6 )
      {
        continue;
      }
      v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    }
    while ( v2->AllocSize > v2->ReuseLimit );
  }
}

// File Line: 476
// RVA: 0x9E2780
bool __fastcall Scaleform::Render::RBGenericImpl::RenderBufferManager::evictUntilAvailable(Scaleform::Render::RBGenericImpl::RenderBufferManager *this, Scaleform::Render::RBGenericImpl::RBCacheListType ltype, unsigned __int64 requestSize)
{
  unsigned __int64 v3; // r15
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v4; // rdi
  Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *v5; // r14
  Scaleform::Render::RBGenericImpl::CacheData *v6; // rbx
  unsigned __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::Render::RenderBufferType v9; // eax
  __int64 v10; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *v11; // rcx
  volatile int v12; // eax

  v3 = requestSize;
  v4 = this;
  if ( requestSize + this->AllocSize > this->ReuseLimit )
  {
    v5 = &this->BufferCache[ltype];
    do
    {
      v6 = v5->Root.pPrev;
      if ( (Scaleform::List<Scaleform::Render::RBGenericImpl::CacheData,Scaleform::Render::RBGenericImpl::CacheData> *)v5->Root.pPrev == v5 )
        return v3 + v4->AllocSize <= v4->ReuseLimit;
      v6->pPrev->pNext = v6->pNext;
      v6->pNext->pPrev = v6->pPrev;
      v7 = v6->DataSize;
      v6->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v6->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v6->ListType = 0;
      v4->AllocSize -= v7;
      v6->DataSize = 0i64;
      v8 = v6->pBuffer;
      v9 = v8->Type;
      if ( v9 == 3 )
      {
        v10 = *(_QWORD *)&v8[2].RefCount;
        if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) && v10 )
          (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
        *(_QWORD *)&v8[2].RefCount = 0i64;
        v11 = v8->pRenderTargetData;
        if ( v11 )
        {
          v11->vfptr->__vecDelDtor(v11, 1u);
          v8->pRenderTargetData = 0i64;
        }
        v12 = v8->RefCount;
        v8[2].Type = 3;
        if ( v12 )
          continue;
      }
      else if ( v9 != 5 || !v8 )
      {
        continue;
      }
      v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
    }
    while ( v3 + v4->AllocSize > v4->ReuseLimit );
  }
  return v3 + v4->AllocSize <= v4->ReuseLimit;
}

// File Line: 493
// RVA: 0x9B0C00
void __fastcall Scaleform::Render::RBGenericImpl::RenderTarget::SetInUse(Scaleform::Render::RBGenericImpl::RenderTarget *this, Scaleform::Render::RenderTargetUse inUse)
{
  __int32 v2; // edx
  Scaleform::Render::RenderBufferManager *v3; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v4; // r8
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  Scaleform::Render::RenderBufferManager *v6; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v7; // r8

  if ( this->Type == 3 )
  {
    if ( inUse == RTUse_Unused )
      goto LABEL_12;
    v2 = inUse - 1;
    if ( !v2 )
    {
      v6 = this->pManager;
      v7 = (Scaleform::Render::RBGenericImpl::CacheData *)&this->0;
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
      v7->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v7->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v7->ListType = 1;
      v7->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v6[6].vfptr;
      v7->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v6[5].RefCount;
      v6[6].vfptr->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))&this->0;
      v6[6].vfptr = (Scaleform::RefCountImplCoreVtbl *)&this->0;
      this->RTStatus = 0;
      return;
    }
    if ( v2 == 1 )
    {
LABEL_12:
      if ( this->ListType < 2 )
      {
        v3 = this->pManager;
        v4 = (Scaleform::Render::RBGenericImpl::CacheData *)&this->0;
        this->pPrev->pNext = this->pNext;
        this->pNext->pPrev = this->pPrev;
        v4->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
        v4->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
        v4->ListType = 2;
        v5 = v3[7].vfptr;
        v4->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)&v3[6].RefCount;
        v4->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)v5;
        v3[7].vfptr->__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))&this->0;
        v3[7].vfptr = (Scaleform::RefCountImplCoreVtbl *)&this->0;
      }
      this->RTStatus = 1;
    }
  }
}

// File Line: 528
// RVA: 0x9A7CA0
void __fastcall Scaleform::Render::RBGenericImpl::RenderTarget::Release(Scaleform::Render::RBGenericImpl::RenderTarget *this)
{
  Scaleform::Render::RBGenericImpl::RenderTarget *v1; // r10
  Scaleform::Render::RenderBufferManager *v2; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v3; // r9
  bool v4; // zf
  bool v5; // sf
  unsigned __int8 v6; // of
  int v7; // er8
  signed __int64 v8; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v9; // rax

  --this->RefCount;
  v1 = this;
  if ( this->RefCount <= 0 )
  {
    if ( this->pBuffer->Type != 3 || this->RTStatus == 3 )
    {
      this->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)this, 1u);
    }
    else
    {
      v2 = this->pManager;
      v3 = (Scaleform::Render::RBGenericImpl::CacheData *)&this->0;
      v6 = __OFSUB__(this->ListType, 2);
      v4 = this->ListType == 2;
      v5 = this->ListType - 2 < 0;
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
      v3->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v3->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v7 = !((unsigned __int8)(v5 ^ v6) | v4) + 5;
      v3->ListType = v7;
      v8 = (signed __int64)(&v2[4].RefCount + 4 * v7);
      v9 = *(Scaleform::Render::RBGenericImpl::CacheData **)(v8 + 8);
      v3->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v8;
      v3->pNext = v9;
      **(_QWORD **)(v8 + 8) = v3;
      *(_QWORD *)(v8 + 8) = v3;
      v1->RTStatus = 1;
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
void __fastcall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::Release(Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this)
{
  Scaleform::Render::RenderBufferManager *v1; // rdx
  Scaleform::Render::RBGenericImpl::CacheData *v2; // r9
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of
  int v6; // er8
  signed __int64 v7; // rcx
  Scaleform::Render::RBGenericImpl::CacheData *v8; // rax

  if ( --this->RefCount <= 0 )
  {
    if ( this->Type == 5 )
    {
      v1 = this->pManager;
      v2 = (Scaleform::Render::RBGenericImpl::CacheData *)&this->0;
      v5 = __OFSUB__(this->ListType, 2);
      v3 = this->ListType == 2;
      v4 = this->ListType - 2 < 0;
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
      v2->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v2->pNext = (Scaleform::Render::RBGenericImpl::CacheData *)-1i64;
      v6 = !((unsigned __int8)(v4 ^ v5) | v3) + 5;
      v2->ListType = v6;
      v7 = (signed __int64)(&v1[4].RefCount + 4 * v6);
      v8 = *(Scaleform::Render::RBGenericImpl::CacheData **)(v7 + 8);
      v2->pPrev = (Scaleform::Render::RBGenericImpl::CacheData *)v7;
      v2->pNext = v8;
      **(_QWORD **)(v7 + 8) = v2;
      *(_QWORD *)(v7 + 8) = v2;
    }
    else
    {
      this->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)this, 1u);
    }
  }
}

