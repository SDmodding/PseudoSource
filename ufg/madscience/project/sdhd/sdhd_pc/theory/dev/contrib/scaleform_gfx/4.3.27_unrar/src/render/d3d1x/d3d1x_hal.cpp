// File Line: 49
// RVA: 0x9FB5D0
void __fastcall Scaleform::Render::D3D1x::HAL::HAL(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::D3D1x::HAL *v2; // rbx
  Scaleform::Render::MeshCacheParams params; // [rsp+28h] [rbp-50h]

  v2 = this;
  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
    (Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface> *)&this->vfptr,
    commandQueue);
  v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::HAL::`vftable;
  v2->pDevice = 0i64;
  v2->pDeviceContext = 0i64;
  v2->pRenderTargetView.pObject = 0i64;
  v2->pDepthStencilView.pObject = 0i64;
  params.MemReserve = 3145728i64;
  params.MemLimit = 0x1000000i64;
  params.MemGranularity = 3145728i64;
  params.LRUTailSize = 10485760i64;
  params.StagingBufferSize = 0x200000i64;
  params.VBLockEvictSizeLimit = 0x40000i64;
  params.MaxBatchInstances = 24;
  params.InstancingThreshold = 5;
  params.NoBatchVerticesSizeThreshold = 0x2000;
  params.MaxVerticesSizeInBatch = 0x4000;
  params.MaxIndicesInBatch = 6144;
  Scaleform::Render::D3D1x::MeshCache::MeshCache(&v2->Cache, Scaleform::Memory::pGlobalHeap, &params);
  Scaleform::Render::D3D1x::RenderSync::RenderSync(&v2->RSync);
  v2->pTextureManager.pObject = 0i64;
  v2->PrevBatchType = 5;
  v2->CurrentConstantBuffer = 0;
}

// File Line: 53
// RVA: 0x9FBC50
void __fastcall Scaleform::Render::D3D1x::HAL::~HAL(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  ID3D11DepthStencilView *v3; // rcx
  ID3D11RenderTargetView *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::HAL::`vftable;
  Scaleform::Render::D3D1x::HAL::ShutdownHAL(this);
  v2 = (Scaleform::Render::RenderBuffer *)v1->pTextureManager.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  Scaleform::Render::D3D1x::RenderSync::~RenderSync(&v1->RSync);
  Scaleform::Render::D3D1x::MeshCache::~MeshCache(&v1->Cache);
  v3 = v1->pDepthStencilView.pObject;
  if ( v3 )
    ((void (__cdecl *)(ID3D11DepthStencilView *))v3->vfptr->Release)(v3);
  v4 = v1->pRenderTargetView.pObject;
  if ( v4 )
    ((void (__cdecl *)(ID3D11RenderTargetView *))v4->vfptr->Release)(v4);
  Scaleform::Render::D3D1x::ShaderManager::~ShaderManager(&v1->SManager);
  Scaleform::Render::HAL::~HAL((Scaleform::Render::HAL *)&v1->vfptr);
}

// File Line: 60
// RVA: 0x9FF0E0
char __fastcall Scaleform::Render::D3D1x::HAL::InitHAL(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::D3D1x::HALInitParams *params)
{
  Scaleform::Render::D3D1x::HALInitParams *v2; // rdi
  Scaleform::Render::D3D1x::HAL *v3; // rbx
  ID3D11Device *v4; // rcx
  ID3D11DeviceContext *v5; // rdx
  Scaleform::Render::D3D1x::TextureManager *v6; // rsi
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::D3D1x::TextureManager *v8; // rax
  Scaleform::Render::D3D1x::TextureManager *v9; // rax
  Scaleform::Render::D3D1x::TextureManager *v10; // rsi
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::Resource *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v14; // rax
  Scaleform::Render::RenderBufferManager *v15; // rax
  Scaleform::Render::RenderBufferManager *v16; // rdi
  Scaleform::Render::RenderBuffer *v17; // rcx
  int v19; // [rsp+80h] [rbp+18h]
  ID3D11DeviceContext *v20; // [rsp+88h] [rbp+20h]

  v2 = params;
  v3 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[1].__vecDelDtor)() )
    return 0;
  v4 = v2->pD3DDevice;
  if ( !v4 )
    return 0;
  v3->pDevice = v4;
  v5 = v2->pD3DContext;
  v20 = v5;
  if ( !v5 )
  {
    ((void (__fastcall *)(ID3D11Device *, ID3D11DeviceContext **))v4->vfptr->PSGetShaderResources)(v4, &v20);
    v5 = v20;
  }
  v3->pDeviceContext = v5;
  Scaleform::Render::D3D1x::RenderEvent::pContext = v5;
  v5->vfptr->AddRef((IUnknown *)&v5->vfptr);
  ((void (*)(void))v3->pDevice->vfptr->AddRef)();
  ((void (*)(void))v3->pDeviceContext->vfptr->AddRef)();
  if ( Scaleform::Render::D3D1x::RenderSync::SetDevice(&v3->RSync, v3->pDevice, v3->pDeviceContext) )
  {
    if ( Scaleform::Render::D3D1x::HAL::createBlendStates(v3)
      && Scaleform::Render::D3D1x::HAL::createDepthStencilStates(v3)
      && Scaleform::Render::D3D1x::HAL::createRasterStates(v3)
      && Scaleform::Render::D3D1x::HAL::createConstantBuffers(v3)
      && Scaleform::Render::D3D1x::ShaderManager::Initialize(&v3->SManager, v3)
      && Scaleform::Render::D3D1x::MeshCache::Initialize(&v3->Cache, v3->pDevice, v3->pDeviceContext, &v3->SManager) )
    {
      v6 = (Scaleform::Render::D3D1x::TextureManager *)v2->pTextureManager.pObject;
      if ( v6 )
      {
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v2->pTextureManager.pObject);
        v7 = (Scaleform::Render::RenderBuffer *)v3->pTextureManager.pObject;
        if ( v7 )
          Scaleform::RefCountImpl::Release(v7);
        v3->pTextureManager.pObject = v6;
      }
      else
      {
        v19 = 72;
        v8 = (Scaleform::Render::D3D1x::TextureManager *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           v3,
                                                           552ui64,
                                                           (Scaleform::AllocInfo *)&v19);
        if ( v8 )
        {
          Scaleform::Render::D3D1x::TextureManager::TextureManager(
            v8,
            v3->pDevice,
            v3->pDeviceContext,
            v2->RenderThreadId,
            v3->pRTCommandQueue,
            0i64);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        v11 = (Scaleform::Render::RenderBuffer *)v3->pTextureManager.pObject;
        if ( v11 )
          Scaleform::RefCountImpl::Release(v11);
        v3->pTextureManager.pObject = v10;
        if ( !v10 )
        {
          Scaleform::Render::D3D1x::MeshCache::Reset(&v3->Cache);
          Scaleform::Render::D3D1x::ShaderManager::Reset(&v3->SManager);
        }
      }
      v12 = (Scaleform::GFx::Resource *)v2->pRenderBufferManager.pObject;
      if ( v12 )
      {
        Scaleform::Render::RenderBuffer::AddRef(v12);
        v13 = (Scaleform::Render::RenderBuffer *)v3->pRenderBufferManager.pObject;
        if ( v13 )
          Scaleform::RefCountImpl::Release(v13);
        v3->pRenderBufferManager.pObject = v2->pRenderBufferManager.pObject;
      }
      else
      {
        v19 = 72;
        v14 = (Scaleform::Render::RBGenericImpl::RenderBufferManager *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                         Scaleform::Memory::pGlobalHeap,
                                                                         v3,
                                                                         184ui64,
                                                                         (Scaleform::AllocInfo *)&v19);
        if ( v14 )
        {
          Scaleform::Render::RBGenericImpl::RenderBufferManager::RenderBufferManager(
            v14,
            DSSM_Exact,
            0xFFFFFFFFFFFFFFFFui64,
            0i64);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        v17 = (Scaleform::Render::RenderBuffer *)v3->pRenderBufferManager.pObject;
        if ( v17 )
          Scaleform::RefCountImpl::Release(v17);
        v3->pRenderBufferManager.pObject = v16;
        if ( !v16 || !((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v3->vfptr[26].__vecDelDtor)(v3) )
        {
          ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v3->vfptr[99].__vecDelDtor)(v3);
          return 0;
        }
      }
      if ( v3->pTextureManager.pObject && v3->pRenderBufferManager.pObject )
      {
        v3->HALState |= 1u;
        Scaleform::Render::HAL::notifyHandlers((Scaleform::Render::HAL *)&v3->vfptr, 0);
        return 1;
      }
    }
    ((void (*)(void))v3->pDevice->vfptr->Release)();
    ((void (*)(void))v3->pDeviceContext->vfptr->Release)();
    v3->pDevice = 0i64;
    v3->pDeviceContext = 0i64;
    return 0;
  }
  ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v3->vfptr[99].__vecDelDtor)(v3);
  return 0;
}

// File Line: 145
// RVA: 0xA02EF0
char __fastcall Scaleform::Render::D3D1x::HAL::ShutdownHAL(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rbx
  char result; // al
  ID3D11RenderTargetView *v3; // rcx
  ID3D11DepthStencilView *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  ID3D11Device *v6; // rcx
  ID3D11DeviceContext *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  ID3D11Device *v9; // rcx

  v1 = this;
  if ( this->HALState & 1 )
  {
    result = ((__int64 (*)(void))this->vfptr[3].__vecDelDtor)();
    if ( !result )
      return result;
    ((void (*)(void))Scaleform::Render::D3D1x::RenderEvent::pContext->vfptr->Release)();
    Scaleform::Render::D3D1x::RenderEvent::pContext = 0i64;
    Scaleform::Render::D3D1x::HAL::destroyBlendStates(v1);
    Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(v1);
    Scaleform::Render::D3D1x::HAL::destroyRasterStates(v1);
    Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(v1);
    v3 = v1->pRenderTargetView.pObject;
    if ( v3 )
      ((void (*)(void))v3->vfptr->Release)();
    v1->pRenderTargetView.pObject = 0i64;
    v4 = v1->pDepthStencilView.pObject;
    if ( v4 )
      ((void (*)(void))v4->vfptr->Release)();
    v1->pDepthStencilView.pObject = 0i64;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v1->vfptr[27].__vecDelDtor)(v1);
    v5 = (Scaleform::Render::RenderBuffer *)v1->pRenderBufferManager.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    v1->pRenderBufferManager.pObject = 0i64;
    v6 = v1->RSync.pDevice.pObject;
    if ( v6 )
      ((void (*)(void))v6->vfptr->Release)();
    v1->RSync.pDevice.pObject = 0i64;
    v7 = v1->RSync.pDeviceContext.pObject;
    if ( v7 )
      ((void (*)(void))v7->vfptr->Release)();
    v1->RSync.pDeviceContext.pObject = 0i64;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames((Scaleform::Render::RenderSync *)&v1->RSync.vfptr);
    Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(&v1->RSync.QueryList, 0i64, 0i64);
    Scaleform::Render::D3D1x::TextureManager::Reset(v1->pTextureManager.pObject);
    v8 = (Scaleform::Render::RenderBuffer *)v1->pTextureManager.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    v1->pTextureManager.pObject = 0i64;
    Scaleform::Render::D3D1x::ShaderManager::Reset(&v1->SManager);
    Scaleform::Render::D3D1x::MeshCache::Reset(&v1->Cache);
    ((void (*)(void))v1->pDeviceContext->vfptr->Release)();
    v9 = v1->pDevice;
    v1->pDeviceContext = 0i64;
    ((void (*)(void))v9->vfptr->Release)();
    v1->pDevice = 0i64;
  }
  return 1;
}

// File Line: 255
// RVA: 0x9FCD00
__int64 __fastcall Scaleform::Render::D3D1x::HAL::BeginScene(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rdi
  void *v2; // rbx
  unsigned __int8 v3; // di

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 3u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(
    v2,
    "Scaleform::Render::D3D1x::HAL::BeginScene-SetState");
  if ( Scaleform::Render::HAL::BeginScene((Scaleform::Render::HAL *)&v1->vfptr) )
  {
    _((AMD_HD3D *)&v1->SManager);
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(&v1->ShaderData);
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, Scaleform::Ptr<ID3D11RenderTargetView> *, Scaleform::Ptr<ID3D11DepthStencilView> *))v1->pDeviceContext->vfptr[29].Release)(
      v1->pDeviceContext,
      1i64,
      &v1->pRenderTargetView,
      &v1->pDepthStencilView);
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64))v1->pDeviceContext->vfptr[8].QueryInterface)(
      v1->pDeviceContext,
      4i64);
    v1->pDeviceContext->vfptr[12].QueryInterface(
      (IUnknown *)v1->pDeviceContext,
      (_GUID *)v1->DepthStencilStates[1],
      0i64);
    v1->CurrentConstantBuffer = 0;
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
  return v3;
}

// File Line: 273
// RVA: 0x9FEC70
__int64 __fastcall Scaleform::Render::D3D1x::HAL::EndScene(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rbx
  void *v2; // rdi
  ID3D11RenderTargetView *v3; // rcx
  ID3D11DepthStencilView *v4; // rcx
  unsigned __int8 v5; // bl

  v1 = this;
  v2 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 2u);
  if ( (unsigned __int8)Scaleform::Render::HAL::EndScene((Scaleform::Render::HAL *)&v1->vfptr) )
  {
    _((AMD_HD3D *)&v1->SManager);
    v3 = v1->pRenderTargetView.pObject;
    if ( v3 )
      ((void (*)(void))v3->vfptr->Release)();
    v1->pRenderTargetView.pObject = 0i64;
    v4 = v1->pDepthStencilView.pObject;
    if ( v4 )
      ((void (*)(void))v4->vfptr->Release)();
    v1->pDepthStencilView.pObject = 0i64;
    v5 = 1;
  }
  else
  {
    v5 = 0;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v2 + 24i64))(v2);
  return v5;
}

// File Line: 289
// RVA: 0xA062B0
void __fastcall Scaleform::Render::D3D1x::HAL::updateViewport(Scaleform::Render::D3D1x::HAL *this)
{
  signed int v1; // edx
  Scaleform::Render::D3D1x::HAL *v2; // rbx
  bool v3; // zf
  signed int v4; // ecx
  int v5; // er8
  int v6; // eax
  int v7; // ST28_4
  int v8; // ST20_4
  Scaleform::Render::MatrixState *v9; // r9
  int v10; // er8
  int v11; // edx
  int v12; // ecx
  ID3D11DeviceContext *v13; // rcx
  float v14; // [rsp+30h] [rbp-28h]
  float v15; // [rsp+34h] [rbp-24h]
  float v16; // [rsp+38h] [rbp-20h]
  float v17; // [rsp+3Ch] [rbp-1Ch]
  __int64 v18; // [rsp+40h] [rbp-18h]

  v1 = 0;
  v2 = this;
  v3 = (this->HALState & 0x20) == 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  if ( !v3 )
  {
    v7 = v2->ViewRect.y1 - v2->VP.Top;
    v8 = v2->ViewRect.x1 - v2->VP.Left;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _QWORD, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Rect<int> *, int, int))v2->vfptr[15].__vecDelDtor)(
      v2,
      0i64,
      &v2->Matrices.pObject->View2D,
      &v2->ViewRect,
      v8,
      v7);
    v2->Matrices.pObject->vfptr[3].__vecDelDtor(
      (Scaleform::RefCountImplCore *)&v2->Matrices.pObject->vfptr,
      (unsigned int)&v2->Matrices.pObject->User);
    v9 = v2->Matrices.pObject;
    v10 = v2->ViewRect.y2;
    v11 = v2->ViewRect.x2;
    v12 = v2->ViewRect.y1;
    v9->ViewRect.x1 = v2->ViewRect.x1;
    v9->ViewRect.y1 = v12;
    v9->ViewRect.x2 = v11;
    v9->ViewRect.y2 = v10;
    v2->Matrices.pObject->UVPOChanged = 1;
    if ( v2->HALState & 0x10 )
    {
      v1 = v2->VP.Left;
      v4 = v2->VP.Top;
      v5 = v1 + v2->VP.Width;
      v6 = v4 + v2->VP.Height;
    }
    else
    {
      v1 = v2->ViewRect.x1;
      v4 = v2->ViewRect.y1;
      v5 = v2->ViewRect.x2;
      v6 = v2->ViewRect.y2;
    }
  }
  v14 = (float)v1;
  v15 = (float)v4;
  v16 = (float)(v5 - v1);
  v17 = (float)(v6 - v4);
  if ( v16 <= 1.0 )
    v16 = 1.0;
  if ( (float)(v6 - v4) <= 1.0 )
    v17 = 1.0;
  v13 = v2->pDeviceContext;
  v18 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, float *))v13->vfptr[14].Release)(v13, 1i64, &v14);
}

// File Line: 344
// RVA: 0xA060F0
unsigned __int64 __fastcall Scaleform::Render::D3D1x::HAL::setVertexArray(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::PrimitiveBatch *pbatch, Scaleform::Render::MeshCacheItem *pmeshBase)
{
  Scaleform::Render::PrimitiveBatch *v3; // rdi
  Scaleform::Render::MeshCacheItem *v4; // rdx
  int v5; // eax
  Scaleform::Render::D3D1x::HAL *v6; // rbx
  ID3D11DeviceContext *v7; // rcx
  Scaleform::Render::MeshCacheItem *v8; // rsi
  int v10; // [rsp+40h] [rbp+8h]
  unsigned __int64 v11; // [rsp+48h] [rbp+10h]

  v3 = pbatch;
  v4 = pmeshBase[1].pNext;
  v5 = (int)pmeshBase[1].pCacheList;
  v6 = this;
  v7 = this->pDeviceContext;
  v11 = pmeshBase[1].pPrev->AllocSize;
  v10 = v5;
  v8 = pmeshBase;
  ((void (__fastcall *)(ID3D11DeviceContext *, unsigned __int64, signed __int64))v7->vfptr[6].AddRef)(
    v7,
    v4->AllocSize,
    57i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, unsigned __int64 *, Scaleform::Render::VertexFormat *, int *))v6->pDeviceContext->vfptr[6].QueryInterface)(
    v6->pDeviceContext,
    0i64,
    1i64,
    &v11,
    v3->pFormat,
    &v10);
  return (_QWORD)v8[1].PrimitiveBatches.Root.pPrev >> 1;
}

// File Line: 355
// RVA: 0xA06050
unsigned __int64 __fastcall Scaleform::Render::D3D1x::HAL::setVertexArray(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::ComplexMesh::FillRecord *fr, unsigned int formatIndex, Scaleform::Render::MeshCacheItem *pmeshBase)
{
  Scaleform::Render::D3D1x::HAL *v4; // rbx
  ID3D11DeviceContext *v5; // rcx
  Scaleform::Render::MeshCacheItem *v6; // rdi
  int v7; // eax
  unsigned int v9; // [rsp+40h] [rbp+8h]
  unsigned __int64 v10; // [rsp+48h] [rbp+10h]
  int v11; // [rsp+50h] [rbp+18h]

  v4 = this;
  v5 = this->pDeviceContext;
  v6 = pmeshBase;
  v7 = LODWORD(fr->VertexByteOffset) + LODWORD(pmeshBase[1].pCacheList);
  v10 = pmeshBase[1].pPrev->AllocSize;
  v11 = v7;
  v9 = fr->pFormats[formatIndex]->Size;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, unsigned __int64 *, unsigned int *, int *))v5->vfptr[6].QueryInterface)(
    v5,
    0i64,
    1i64,
    &v10,
    &v9,
    &v11);
  ((void (__fastcall *)(ID3D11DeviceContext *, unsigned __int64, signed __int64))v4->pDeviceContext->vfptr[6].AddRef)(
    v4->pDeviceContext,
    v6[1].pNext->AllocSize,
    57i64);
  return (unsigned int)((_QWORD)v6[1].PrimitiveBatches.Root.pPrev >> 1);
}

// File Line: 371
// RVA: 0xA03560
void __fastcall Scaleform::Render::D3D1x::HAL::applyDepthStencilMode(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::HAL::DepthStencilMode mode, unsigned int stencilRef)
{
  unsigned int v3; // er14
  __int64 v4; // rbp
  Scaleform::Render::D3D1x::HAL *v5; // rdi
  void *v6; // rsi

  v3 = stencilRef;
  v4 = mode;
  v5 = this;
  v6 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 14u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(
    v6,
    "Scaleform::Render::D3D1x::HAL::applyDepthStencilMode");
  if ( *(_QWORD *)&v5->CurrentDepthStencilState != __PAIR__(v3, (unsigned int)v4) )
  {
    v5->pDeviceContext->vfptr[12].QueryInterface(
      (IUnknown *)v5->pDeviceContext,
      (_GUID *)v5->DepthStencilStates[v4],
      (void **)v3);
    v5->CurrentStencilRef = v3;
    if ( Scaleform::Render::HAL::DepthStencilModeTable[v4].ColorWriteEnable != Scaleform::Render::HAL::DepthStencilModeTable[v5->CurrentDepthStencilState].ColorWriteEnable )
    {
      v5->CurrentDepthStencilState = v4;
      ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _QWORD, bool, bool))v5->vfptr[42].__vecDelDtor)(
        v5,
        (unsigned int)v5->CurrentBlendState.Mode,
        v5->CurrentBlendState.SourceAc,
        v5->CurrentBlendState.ForceAc);
    }
    v5->CurrentDepthStencilState = v4;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 390
// RVA: 0xA03680
char __fastcall Scaleform::Render::D3D1x::HAL::checkDepthStencilBufferCaps(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rbx
  char v2; // cl
  int v4; // [rsp+28h] [rbp-20h]
  __int128 v5; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( this->StencilChecked )
    goto LABEL_14;
  this->StencilAvailable = 0;
  this->DepthBufferAvailable = 0;
  v5 = 0ui64;
  ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, char *, __int128 *, signed __int64))this->pDeviceContext->vfptr[29].Release)(
    this->pDeviceContext,
    1i64,
    (char *)&v5 + 8,
    &v5,
    -2i64);
  if ( !(_QWORD)v5 )
    goto LABEL_10;
  (*(void (__fastcall **)(_QWORD, int *))(*(_QWORD *)v5 + 64i64))(v5, &v4);
  switch ( v4 )
  {
    case 20:
      goto LABEL_22;
    case 40:
LABEL_9:
      v1->DepthBufferAvailable = 1;
      break;
    case 45:
LABEL_22:
      *(_WORD *)&v1->StencilAvailable = 257;
      goto LABEL_9;
    case 55:
      goto LABEL_9;
  }
LABEL_10:
  v1->StencilChecked = 1;
  if ( *((_QWORD *)&v5 + 1) )
    (*(void (**)(void))(**((_QWORD **)&v5 + 1) + 16i64))();
  if ( (_QWORD)v5 )
    (*(void (**)(void))(*(_QWORD *)v5 + 16i64))();
LABEL_14:
  if ( v1->StencilAvailable || v1->DepthBufferAvailable )
    return 1;
  v2 = warned_2;
  if ( !warned_2 )
    v2 = 1;
  warned_2 = v2;
  return 0;
}

// File Line: 435
// RVA: 0x9FF4D0
bool __fastcall Scaleform::Render::D3D1x::HAL::IsRasterModeSupported(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::HAL::RasterModeType mode)
{
  return mode != 2;
}

// File Line: 441
// RVA: 0xA03660
void __fastcall Scaleform::Render::D3D1x::HAL::applyRasterModeImpl(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::HAL::RasterModeType mode)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RasterizerState *))this->pDeviceContext->vfptr[14].AddRef)(
    this->pDeviceContext,
    this->RasterStates[mode]);
}

// File Line: 458
// RVA: 0xA03AC0
char __fastcall Scaleform::Render::D3D1x::HAL::createBlendStates(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rdi
  unsigned int v2; // ebx
  char v3; // r8
  unsigned int v4; // ecx
  unsigned __int64 v5; // rcx
  D3D11_BLEND v6; // edx
  D3D11_BLEND v7; // eax
  char Dst; // [rsp+20h] [rbp-118h]
  int v10; // [rsp+28h] [rbp-110h]
  D3D11_BLEND v11; // [rsp+2Ch] [rbp-10Ch]
  D3D11_BLEND v12; // [rsp+30h] [rbp-108h]
  D3D11_BLEND_OP v13; // [rsp+34h] [rbp-104h]
  D3D11_BLEND v14; // [rsp+38h] [rbp-100h]
  D3D11_BLEND v15; // [rsp+3Ch] [rbp-FCh]
  D3D11_BLEND_OP v16; // [rsp+40h] [rbp-F8h]
  char v17; // [rsp+44h] [rbp-F4h]

  v1 = this;
  memset(this->BlendStates, 0, 0x148ui64);
  v2 = 0;
  while ( 1 )
  {
    memset(&Dst, 0, 0x108ui64);
    v3 = 0;
    v4 = v2;
    if ( v2 < 0x28 )
    {
      v10 = 1;
      v17 = 15;
      if ( v2 >= 0x14 )
      {
        v4 = v2 - 20;
        v3 = 1;
      }
    }
    else
    {
      v10 = 0;
      v17 = 0;
    }
    v5 = 3i64 * (v4 % 0x14);
    v13 = BlendOps[Scaleform::Render::HAL::BlendModeTable[v5 / 3].Operator];
    v6 = BlendFactors[dword_1420BB1C4[2 * v5]];
    v7 = BlendFactors[dword_1420BB1C8[2 * v5]];
    v11 = BlendFactors[dword_1420BB1C4[2 * v5]];
    v12 = v7;
    v16 = BlendOps[dword_1420BB1CC[2 * v5]];
    v14 = BlendFactors[dword_1420BB1D0[2 * v5]];
    v15 = BlendFactors[dword_1420BB1D4[2 * v5]];
    if ( v3 )
    {
      if ( v6 == 5 )
        v6 = 2;
      v11 = v6;
    }
    if ( ((signed int (__fastcall *)(ID3D11Device *, char *, signed __int64))v1->pDevice->vfptr->VSSetSamplers)(
           v1->pDevice,
           &Dst,
           (signed __int64)v1 + 8 * (v2 + 31991i64)) < 0 )
      break;
    if ( ++v2 >= 0x29 )
      return 1;
  }
  return 0;
}

// File Line: 539
// RVA: 0xA04230
void __fastcall Scaleform::Render::D3D1x::HAL::destroyBlendStates(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11BlendState **v1; // rsi
  signed __int64 v2; // rdi
  ID3D11BlendState **v3; // rbx

  v1 = this->BlendStates;
  v2 = 41i64;
  v3 = this->BlendStates;
  do
  {
    if ( *v3 )
      ((void (*)(void))(*v3)->vfptr->Release)();
    ++v3;
    --v2;
  }
  while ( v2 );
  memset(v1, 0, 0x148ui64);
}

// File Line: 549
// RVA: 0xA04010
char __fastcall Scaleform::Render::D3D1x::HAL::createDepthStencilStates(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rsi
  unsigned int v2; // edi
  Scaleform::Render::HAL::EnableIgnoreValue *v3; // rbx
  D3D11_STENCIL_OP v4; // er8
  __int64 v5; // rax
  D3D11_STENCIL_OP v6; // edx
  __int64 v7; // rax
  D3D11_STENCIL_OP v8; // ecx
  ID3D11Device *v9; // rcx
  int Dst; // [rsp+20h] [rbp-48h]
  BOOL v12; // [rsp+24h] [rbp-44h]
  D3D11_COMPARISON_FUNC v13; // [rsp+28h] [rbp-40h]
  BOOL v14; // [rsp+2Ch] [rbp-3Ch]
  __int16 v15; // [rsp+30h] [rbp-38h]
  D3D11_STENCIL_OP v16; // [rsp+34h] [rbp-34h]
  D3D11_STENCIL_OP v17; // [rsp+38h] [rbp-30h]
  D3D11_STENCIL_OP v18; // [rsp+3Ch] [rbp-2Ch]
  D3D11_COMPARISON_FUNC v19; // [rsp+40h] [rbp-28h]
  D3D11_STENCIL_OP v20; // [rsp+44h] [rbp-24h]
  D3D11_STENCIL_OP v21; // [rsp+48h] [rbp-20h]
  D3D11_STENCIL_OP v22; // [rsp+4Ch] [rbp-1Ch]
  D3D11_COMPARISON_FUNC v23; // [rsp+50h] [rbp-18h]

  v1 = this;
  this->DepthStencilStates[0] = 0i64;
  this->DepthStencilStates[1] = 0i64;
  this->DepthStencilStates[2] = 0i64;
  this->DepthStencilStates[3] = 0i64;
  this->DepthStencilStates[4] = 0i64;
  this->DepthStencilStates[5] = 0i64;
  this->DepthStencilStates[6] = 0i64;
  v2 = 0;
  v3 = &Scaleform::Render::HAL::DepthStencilModeTable[0].DepthWriteEnable;
  this->DepthStencilStates[7] = 0i64;
  while ( 1 )
  {
    memset(&Dst, 0, 0x34ui64);
    v14 = *((_DWORD *)v3 + 1) != 0;
    if ( *((_DWORD *)v3 - 1) || (Dst = 0, *v3) )
      Dst = 1;
    v15 = -1;
    v12 = *v3 != 0;
    v13 = ComparisonFunctions[*((signed int *)v3 + 3)];
    v4 = StencilOperations[*((signed int *)v3 + 5)];
    v5 = *((signed int *)v3 + 6);
    v19 = ComparisonFunctions[*((signed int *)v3 + 4)];
    v6 = StencilOperations[v5];
    v7 = *((signed int *)v3 + 7);
    v18 = v4;
    v8 = StencilOperations[v7];
    v16 = v6;
    v20 = v6;
    v17 = v8;
    v21 = v8;
    v9 = v1->pDevice;
    v22 = v4;
    v23 = v19;
    if ( ((signed int (__fastcall *)(ID3D11Device *, int *, signed __int64))v9->vfptr->SetPredication)(
           v9,
           &Dst,
           (signed __int64)v1 + 8 * (v2 + 32032i64)) < 0 )
      break;
    ++v2;
    v3 += 9;
    if ( v2 >= 8 )
      return 1;
  }
  return 0;
}

// File Line: 603
// RVA: 0xA04300
void __fastcall Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11DepthStencilState **v1; // rdi
  signed __int64 v2; // rsi
  ID3D11DepthStencilState **v3; // rbx

  v1 = this->DepthStencilStates;
  v2 = 8i64;
  v3 = this->DepthStencilStates;
  do
  {
    if ( *v3 )
      ((void (*)(void))(*v3)->vfptr->Release)();
    ++v3;
    --v2;
  }
  while ( v2 );
  *v1 = 0i64;
  v1[1] = 0i64;
  v1[2] = 0i64;
  v1[3] = 0i64;
  v1[4] = 0i64;
  v1[5] = 0i64;
  v1[6] = 0i64;
  v1[7] = 0i64;
}

// File Line: 613
// RVA: 0xA04180
char __fastcall Scaleform::Render::D3D1x::HAL::createRasterStates(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rdi
  unsigned int v2; // ebx
  int Dst; // [rsp+20h] [rbp-38h]
  int v5; // [rsp+24h] [rbp-34h]
  int v6; // [rsp+38h] [rbp-20h]

  v1 = this;
  v2 = 0;
  this->RasterStates[0] = 0i64;
  this->RasterStates[1] = 0i64;
  this->RasterStates[2] = 0i64;
  while ( 1 )
  {
    memset(&Dst, 0, 0x28ui64);
    v5 = 1;
    v6 = 1;
    Dst = 3;
    if ( v2 == 1 )
      Dst = 2;
    if ( ((signed int (__fastcall *)(ID3D11Device *, int *, signed __int64))v1->pDevice->vfptr->GSSetShaderResources)(
           v1->pDevice,
           &Dst,
           (signed __int64)v1 + 8 * (v2 + 32040i64)) < 0 )
      break;
    if ( ++v2 >= 3 )
      return 1;
  }
  return 0;
}

// File Line: 633
// RVA: 0xA04370
void __fastcall Scaleform::Render::D3D1x::HAL::destroyRasterStates(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11RasterizerState **v1; // rsi
  signed __int64 v2; // rdi
  ID3D11RasterizerState **v3; // rbx

  v1 = this->RasterStates;
  v2 = 3i64;
  v3 = this->RasterStates;
  do
  {
    if ( *v3 )
      ((void (*)(void))(*v3)->vfptr->Release)();
    ++v3;
    --v2;
  }
  while ( v2 );
  *v1 = 0i64;
  v1[1] = 0i64;
  v1[2] = 0i64;
}

// File Line: 643
// RVA: 0xA03C30
char __fastcall Scaleform::Render::D3D1x::HAL::createConstantBuffers(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rdi
  unsigned int v2; // ebx
  ID3D11Device *v3; // rcx
  __int64 v5; // [rsp+20h] [rbp-28h]
  __int64 v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = 0;
  this->ConstantBuffers[0] = 0i64;
  this->ConstantBuffers[1] = 0i64;
  this->ConstantBuffers[2] = 0i64;
  this->ConstantBuffers[3] = 0i64;
  this->ConstantBuffers[4] = 0i64;
  this->ConstantBuffers[5] = 0i64;
  this->ConstantBuffers[6] = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  this->ConstantBuffers[7] = 0i64;
  v7 = 0i64;
  while ( 1 )
  {
    v3 = v1->pDevice;
    v5 = 8589951168i64;
    v6 = 281474976710660i64;
    if ( ((signed int (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, signed __int64, signed __int64, signed __int64, __int64))v3->vfptr->VSSetConstantBuffers)(
           v3,
           &v5,
           0i64,
           (signed __int64)v1 + 8 * (v2 + 32043i64),
           8589951168i64,
           281474976710660i64,
           v7) < 0 )
      break;
    if ( ++v2 >= 8 )
      return 1;
  }
  return 0;
}

// File Line: 660
// RVA: 0xA04290
void __fastcall Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer **v1; // rdi
  signed __int64 v2; // rsi
  ID3D11Buffer **v3; // rbx

  v1 = this->ConstantBuffers;
  v2 = 8i64;
  v3 = this->ConstantBuffers;
  do
  {
    if ( *v3 )
      ((void (*)(void))(*v3)->vfptr->Release)();
    ++v3;
    --v2;
  }
  while ( v2 );
  *v1 = 0i64;
  v1[1] = 0i64;
  v1[2] = 0i64;
  v1[3] = 0i64;
  v1[4] = 0i64;
  v1[5] = 0i64;
  v1[6] = 0i64;
  v1[7] = 0i64;
}

// File Line: 670
// RVA: 0xA05C10
ID3D11Buffer *__fastcall Scaleform::Render::D3D1x::HAL::getNextConstantBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  __int64 v1; // rax

  v1 = ((unsigned __int8)this->CurrentConstantBuffer + 1) & 7;
  this->CurrentConstantBuffer = v1;
  return this->ConstantBuffers[v1];
}

// File Line: 677
// RVA: 0xA03500
void __fastcall Scaleform::Render::D3D1x::HAL::applyBlendModeImpl(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::BlendMode mode, bool sourceAc, bool forceAc)
{
  ID3D11DeviceContext *v4; // r11
  signed int v5; // eax

  v4 = this->pDeviceContext;
  if ( v4 )
  {
    if ( Scaleform::Render::HAL::DepthStencilModeTable[this->CurrentDepthStencilState].ColorWriteEnable )
    {
      v5 = 0;
      if ( sourceAc )
        v5 = 20;
    }
    else
    {
      v5 = 40;
      mode = 0;
    }
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11BlendState *, _QWORD, signed __int64))v4->vfptr[11].Release)(
      this->pDeviceContext,
      this->BlendStates[mode + v5],
      0i64,
      0xFFFFFFFFi64);
  }
}

// File Line: 687
// RVA: 0x9FCDE0
Scaleform::Render::RenderBuffer *__fastcall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(Scaleform::Render::D3D1x::HAL *this, ID3D11View *pcolor, ID3D11View *pdepth)
{
  ID3D11View *v3; // rsi
  ID3D11View *v4; // r14
  Scaleform::Render::D3D1x::HAL *v5; // r13
  Scaleform::Render::DepthStencilBuffer *v6; // rbx
  __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rdi
  int v9; // er15
  int v10; // er12
  _DWORD *v11; // rax
  __int64 v13; // [rsp+30h] [rbp-79h]
  Scaleform::Render::DepthStencilBuffer *v14; // [rsp+38h] [rbp-71h]
  Scaleform::Render::RenderBuffer *v15; // [rsp+40h] [rbp-69h]
  _DWORD *v16; // [rsp+48h] [rbp-61h]
  __int64 v17; // [rsp+50h] [rbp-59h]
  __int64 v18; // [rsp+58h] [rbp-51h]
  int v19; // [rsp+88h] [rbp-21h]
  int v20; // [rsp+8Ch] [rbp-1Dh]
  int v21; // [rsp+118h] [rbp+6Fh]
  __int64 v22; // [rsp+120h] [rbp+77h]
  __int64 v23; // [rsp+128h] [rbp+7Fh]

  v17 = -2i64;
  v3 = pdepth;
  v4 = pcolor;
  v5 = this;
  v6 = 0i64;
  v13 = 0i64;
  v23 = 0i64;
  v22 = 0i64;
  ((void (__fastcall *)(ID3D11View *, __int64 *))pcolor->vfptr[2].AddRef)(pcolor, &v13);
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v13 + 80i64))(v13, &v18);
  v22 = v18;
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, __int64 *, signed __int64, signed __int64, _QWORD))v5->pRenderBufferManager.pObject->vfptr[5].__vecDelDtor)(
         v5->pRenderBufferManager.pObject,
         &v22,
         2i64,
         1i64,
         0i64);
  v8 = (Scaleform::Render::RenderBuffer *)v7;
  if ( v7 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
  v15 = v8;
  v14 = 0i64;
  if ( v3 )
  {
    ((void (__fastcall *)(ID3D11View *, __int64 *))v3->vfptr[2].AddRef)(v3, &v23);
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v23 + 80i64))(v23, &v19);
    v9 = v19;
    v10 = v20;
    v21 = 72;
    v11 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      v5,
                      48ui64,
                      (Scaleform::AllocInfo *)&v21);
    v16 = v11;
    if ( v11 )
    {
      *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable;
      v11[2] = 1;
      *(_QWORD *)v11 = &Scaleform::RefCountVImpl::`vftable;
      *(_QWORD *)v11 = &Scaleform::Render::RenderBuffer::`vftable;
      v11[4] = 5;
      *((_QWORD *)v11 + 3) = 0i64;
      *((_QWORD *)v11 + 4) = 0i64;
      v11[10] = v9;
      v11[11] = v10;
      *(_QWORD *)v11 = &Scaleform::Render::DepthStencilBuffer::`vftable;
      v6 = (Scaleform::Render::DepthStencilBuffer *)v11;
    }
    v14 = v6;
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v8, v4, v6, v3);
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v6->vfptr[2].__vecDelDtor)(v6);
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v8->vfptr[2].__vecDelDtor)(v8);
  if ( v23 )
    (*(void (**)(void))(*(_QWORD *)v23 + 16i64))();
  if ( v13 )
    (*(void (**)(void))(*(_QWORD *)v13 + 16i64))();
  return v8;
}

// File Line: 714
// RVA: 0x9FCF90
Scaleform::Render::RenderBuffer *__fastcall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::Texture *texture, bool needsStencil)
{
  bool v3; // r15
  Scaleform::Render::Texture *v4; // rsi
  Scaleform::Render::D3D1x::HAL *v5; // r14
  Scaleform::Render::RenderBufferManager *v6; // rdi
  unsigned int v7; // er9
  Scaleform::RefCountImplCoreVtbl *v8; // rbx
  unsigned int v9; // eax
  Scaleform::Render::RenderBuffer *v10; // rbp
  ID3D11View *v11; // rdi
  Scaleform::Render::DepthStencilBuffer *v12; // rbx
  Scaleform::Render::RenderBufferManager *v13; // rcx
  int v14; // edx
  __int64 v15; // rax
  __int64 v16; // rax
  unsigned int v18; // [rsp+30h] [rbp-48h]
  int v19; // [rsp+34h] [rbp-44h]
  __int64 v20; // [rsp+38h] [rbp-40h]
  __int64 v21; // [rsp+40h] [rbp-38h]
  ID3D11View *prt; // [rsp+88h] [rbp+10h]
  unsigned int v23; // [rsp+98h] [rbp+20h]
  unsigned int v24; // [rsp+9Ch] [rbp+24h]

  v21 = -2i64;
  v3 = needsStencil;
  v4 = texture;
  v5 = this;
  if ( !texture )
    return 0i64;
  if ( texture->TextureCount != 1 )
    return 0i64;
  v6 = this->pRenderBufferManager.pObject;
  v7 = texture->ImgSize.Height;
  v23 = texture->ImgSize.Width;
  v24 = v7;
  v8 = v6->vfptr;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::Texture *))texture->vfptr[4].__vecDelDtor)(texture);
  v10 = (Scaleform::Render::RenderBuffer *)((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, unsigned int *, signed __int64, _QWORD, Scaleform::Render::Texture *))v8[5].__vecDelDtor)(
                                             v6,
                                             &v23,
                                             4i64,
                                             v9,
                                             v4);
  if ( !v10 )
    return 0i64;
  v11 = 0i64;
  prt = 0i64;
  if ( ((signed int (__fastcall *)(ID3D11Device *, void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int), _QWORD, ID3D11View **))v5->pDevice->vfptr->Draw)(
         v5->pDevice,
         v4[1].vfptr[1].__vecDelDtor,
         0i64,
         &prt) < 0 )
  {
    v10 = 0i64;
  }
  else
  {
    v12 = 0i64;
    v20 = 0i64;
    if ( v3 )
    {
      v13 = v5->pRenderBufferManager.pObject;
      v14 = v4->ImgSize.Height;
      v18 = v4->ImgSize.Width;
      v19 = v14;
      v15 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, unsigned int *, _QWORD))v13->vfptr[7].__vecDelDtor)(
              v13,
              &v18,
              0i64);
      v12 = (Scaleform::Render::DepthStencilBuffer *)v15;
      v20 = v15;
      if ( v15 )
      {
        v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 24i64))(v15);
        if ( v16 )
          v11 = *(ID3D11View **)(v16 + 64);
      }
    }
    Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v10, prt, v12, v11);
    if ( v12 )
      ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v12->vfptr[2].__vecDelDtor)(v12);
  }
  if ( prt )
    ((void (*)(void))prt->vfptr->Release)();
  return v10;
}

// File Line: 745
// RVA: 0x9FD0F0
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::D3D1x::HAL::CreateTempRenderTarget(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::Size<unsigned long> *size, bool needsStencil)
{
  bool v3; // bp
  Scaleform::Render::D3D1x::HAL *v4; // r14
  Scaleform::Render::RenderTarget *result; // rax
  Scaleform::Render::RenderTarget *v6; // rdi
  Scaleform::Render::RenderBuffer::RenderTargetData *v7; // rax
  __int64 v8; // r15
  ID3D11View *v9; // rsi
  __int64 v10; // r8
  Scaleform::Render::DepthStencilBuffer *v11; // rbx
  Scaleform::Render::RenderBufferManager *v12; // rcx
  int v13; // edx
  __int64 v14; // rax
  __int64 v15; // rax
  ID3D11View *prt; // [rsp+60h] [rbp+8h]
  int v17; // [rsp+78h] [rbp+20h]
  int v18; // [rsp+7Ch] [rbp+24h]

  v3 = needsStencil;
  v4 = this;
  result = (Scaleform::Render::RenderTarget *)this->pRenderBufferManager.pObject->vfptr[6].__vecDelDtor(
                                                (Scaleform::RefCountImplCore *)this->pRenderBufferManager.pObject,
                                                (unsigned int)size);
  v6 = result;
  if ( result )
  {
    v7 = result->pRenderTargetData;
    if ( v7 && (!v3 || v7->pDepthStencilBuffer.pObject) )
    {
      result = v6;
    }
    else
    {
      v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))v6->vfptr[3].__vecDelDtor)(v6);
      v9 = 0i64;
      prt = 0i64;
      if ( ((signed int (__fastcall *)(ID3D11Device *, _QWORD, _QWORD, ID3D11View **))v4->pDevice->vfptr->Draw)(
             v4->pDevice,
             *(_QWORD *)(*(_QWORD *)(v8 + 88) + 8i64),
             0i64,
             &prt) >= 0 )
      {
        v11 = 0i64;
        if ( v3 )
        {
          v12 = v4->pRenderBufferManager.pObject;
          v13 = *(_DWORD *)(v8 + 52);
          v17 = *(_DWORD *)(v8 + 48);
          v18 = v13;
          LOBYTE(v10) = 1;
          v14 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, int *, __int64))v12->vfptr[7].__vecDelDtor)(
                  v12,
                  &v17,
                  v10);
          v11 = (Scaleform::Render::DepthStencilBuffer *)v14;
          if ( v14 )
          {
            v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 24i64))(v14);
            if ( v15 )
              v9 = *(ID3D11View **)(v15 + 64);
          }
        }
        Scaleform::Render::D3D1x::RenderTargetData::UpdateData(
          (Scaleform::Render::RenderBuffer *)&v6->vfptr,
          prt,
          v11,
          v9);
        v9 = (ID3D11View *)v6;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v11->vfptr[2].__vecDelDtor)(v11);
      }
      if ( prt )
        ((void (__cdecl *)(ID3D11View *))prt->vfptr->Release)(prt);
      result = (Scaleform::Render::RenderTarget *)v9;
    }
  }
  return result;
}

// File Line: 780
// RVA: 0xA02980
char __fastcall Scaleform::Render::D3D1x::HAL::SetRenderTarget(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::RenderTarget *ptarget, bool setState)
{
  bool v3; // si
  Scaleform::Render::RenderTarget *v4; // rdi
  Scaleform::Render::D3D1x::HAL *v5; // rbx
  __int64 v7; // rdx
  __int64 v8; // r8
  Scaleform::Render::RenderBuffer::RenderTargetData *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // r9
  Scaleform::Render::HAL::RenderTargetEntry *v11; // rcx
  __int64 v12; // rdx
  Scaleform::Render::HAL::RenderTargetEntry __that; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *v14; // [rsp+348h] [rbp+260h]

  v3 = setState;
  v4 = ptarget;
  v5 = this;
  if ( this->HALState & 4 )
    ((void (*)(void))this->vfptr[8].__vecDelDtor)();
  if ( v5->HALState & 8 )
    return 0;
  __that.pRenderTarget.pObject = 0i64;
  Scaleform::Render::MatrixState::MatrixState(&__that.OldMatrixState);
  _mm_store_si128((__m128i *)&__that.OldMatrixState.FullViewportMVP.M[0][2], (__m128i)0i64);
  *(_QWORD *)&__that.OldMatrixState.FullViewportMVP.M[1][2] = 0i64;
  *(_QWORD *)&__that.OldViewRect.x1 = 0i64;
  __that.OldViewRect.y2 = 1;
  __that.OldViewRect.x2 = 1;
  *(_QWORD *)&__that.OldViewport.Left = 0i64;
  *(_QWORD *)&__that.OldViewport.BufferWidth = 0i64;
  __that.OldViewport.Width = 0;
  v9 = v4->pRenderTargetData;
  v14 = v9[1].vfptr;
  v10 = v9[1].pBuffer;
  if ( v3 )
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, Scaleform::Render::RenderBuffer::RenderTargetDataVtbl **, Scaleform::Render::RenderBuffer *))v5->pDeviceContext->vfptr[11].QueryInterface)(
      v5->pDeviceContext,
      1i64,
      &v14,
      v10);
  ((void (__fastcall *)(Scaleform::Render::RenderTarget *, __int64, __int64, Scaleform::Render::RenderBuffer *))v4->vfptr[1].__vecDelDtor)(
    v4,
    v7,
    v8,
    v10);
  if ( __that.pRenderTarget.pObject )
    ((void (*)(void))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
  __that.pRenderTarget.pObject = v4;
  if ( v5->RenderTargetStack.Data.Size )
  {
    Scaleform::Render::HAL::RenderTargetEntry::operator=(v5->RenderTargetStack.Data.Data, &__that);
  }
  else
  {
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v5->RenderTargetStack.Data.Data,
      &v5->RenderTargetStack,
      v5->RenderTargetStack.Data.Size + 1);
    v11 = &v5->RenderTargetStack.Data.Data[v5->RenderTargetStack.Data.Size - 1];
    if ( v11 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v11, &__that);
  }
  if ( *(_QWORD *)&__that.OldMatrixState.ViewRectCompensated3D.M[3][0] )
    Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&__that.OldMatrixState.ViewRectCompensated3D.M[3][0]);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&__that.OldMatrixState.vfptr);
  if ( __that.pRenderTarget.pObject )
    ((void (__cdecl *)(Scaleform::Render::RenderTarget *, __int64))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(
      __that.pRenderTarget.pObject,
      v12);
  return 1;
}

// File Line: 810
// RVA: 0xA00230
void __fastcall Scaleform::Render::D3D1x::HAL::PushRenderTarget(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::Rect<float> *frameRect, Scaleform::Render::RenderTarget *prt, unsigned int flags, __int64 clearColor)
{
  char v5; // r15
  Scaleform::Render::RenderTarget *v6; // rsi
  Scaleform::Render::Rect<float> *v7; // r12
  Scaleform::Render::D3D1x::HAL *v8; // rdi
  void *v9; // rax
  int v10; // er8
  int v11; // edx
  int v12; // ecx
  Scaleform::Render::MatrixState *v13; // rax
  Scaleform::Render::MatrixState *v14; // rbx
  Scaleform::Render::HAL::RenderTargetEntry *v15; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *v16; // rbx
  int v17; // er8
  int v18; // edx
  int v19; // er10
  int v20; // er9
  int v21; // ecx
  Scaleform::Render::MatrixState *v22; // rdx
  int v23; // ecx
  int v24; // eax
  Scaleform::Render::HAL::RenderTargetEntry *v25; // rcx
  float pr; // [rsp+30h] [rbp-D0h]
  float pg; // [rsp+34h] [rbp-CCh]
  float pb; // [rsp+38h] [rbp-C8h]
  float pa; // [rsp+3Ch] [rbp-C4h]
  ID3D11ShaderResourceView *views; // [rsp+40h] [rbp-C0h]
  __int64 v31; // [rsp+48h] [rbp-B8h]
  __int64 v32; // [rsp+50h] [rbp-B0h]
  Scaleform::Render::HAL::RenderTargetEntry __that; // [rsp+60h] [rbp-A0h]

  v32 = -2i64;
  v5 = flags;
  v6 = prt;
  v7 = frameRect;
  v8 = this;
  v9 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 11u);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v9 + 16i64))(
    v9,
    "Scaleform::Render::D3D1x::HAL::PushRenderTarget");
  v8->HALState |= 0x10u;
  __that.pRenderTarget.pObject = 0i64;
  Scaleform::Render::MatrixState::MatrixState(&__that.OldMatrixState);
  _mm_store_si128((__m128i *)&__that.OldViewRect, (__m128i)0i64);
  *(_QWORD *)&__that.OldViewport.BufferWidth = 0i64;
  *(_QWORD *)&__that.OldViewport.Left = 0i64;
  __that.OldViewport.Height = 1;
  __that.OldViewport.Width = 1;
  *(_QWORD *)&__that.OldViewport.ScissorWidth = 0i64;
  *(_QWORD *)&__that.OldViewport.ScissorLeft = 0i64;
  __that.OldViewport.Flags = 0;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v6->vfptr[1].__vecDelDtor)(v6);
  if ( __that.pRenderTarget.pObject )
    ((void (*)(void))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
  __that.pRenderTarget.pObject = v6;
  *(_OWORD *)&__that.OldViewport.BufferWidth = *(_OWORD *)&v8->VP.BufferWidth;
  *(_OWORD *)&__that.OldViewport.Width = *(_OWORD *)&v8->VP.Width;
  *(_QWORD *)&__that.OldViewport.ScissorWidth = *(_QWORD *)&v8->VP.ScissorWidth;
  __that.OldViewport.Flags = v8->VP.Flags;
  v10 = v8->ViewRect.y2;
  v11 = v8->ViewRect.x2;
  v12 = v8->ViewRect.y1;
  __that.OldViewRect.x1 = v8->ViewRect.x1;
  __that.OldViewRect.y1 = v12;
  __that.OldViewRect.x2 = v11;
  __that.OldViewRect.y2 = v10;
  Scaleform::Render::MatrixState::CopyFrom(&__that.OldMatrixState, v8->Matrices.pObject);
  v13 = v8->Matrices.pObject;
  *(_QWORD *)&v13->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&v13->Orient2D.M[0][2] = 0i64;
  v13->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&v13->Orient2D.M[1][1] = 1065353216i64;
  v13->Orient2D.M[1][3] = 0.0;
  v14 = v8->Matrices.pObject;
  memset(&v14->Orient3D, 0, 0x40ui64);
  v14->Orient3D.M[0][0] = 1.0;
  v14->Orient3D.M[1][1] = 1.0;
  v14->Orient3D.M[2][2] = 1.0;
  v14->Orient3D.M[3][3] = 1.0;
  v8->Matrices.pObject->vfptr[3].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v8->Matrices.pObject->vfptr,
    (unsigned int)&Scaleform::Render::Matrix2x4<float>::Identity);
  if ( v6 )
  {
    v16 = v6->pRenderTargetData;
    views = 0i64;
    v31 = 0i64;
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(v8->pTextureManager.pObject, 0, 2u, &views, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, Scaleform::Render::RenderBuffer::RenderTargetData *, Scaleform::Render::RenderBuffer *))v8->pDeviceContext->vfptr[11].QueryInterface)(
      v8->pDeviceContext,
      1i64,
      &v16[1],
      v16[1].pBuffer);
    v8->StencilChecked = 0;
    ++v8->AccumulatedStats.RTChanges;
    if ( !(v5 & 1) )
    {
      Scaleform::Render::Color::GetRGBAFloat((Scaleform::Render::Color *)clearColor, &pr, &pg, &pb, &pa);
      ((void (__fastcall *)(ID3D11DeviceContext *, Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *, float *))v8->pDeviceContext->vfptr[16].Release)(
        v8->pDeviceContext,
        v16[1].vfptr,
        &pr);
    }
    v17 = v6->ViewRect.y1;
    v18 = v6->ViewRect.x1;
    v19 = v6->ViewRect.y2 - v17;
    v20 = v6->ViewRect.x2 - v18;
    v21 = v6->BufferSize.Height;
    v8->VP.BufferWidth = v6->BufferSize.Width;
    v8->VP.BufferHeight = v21;
    v8->VP.Left = v18;
    v8->VP.Top = v17;
    v8->VP.Width = v20;
    v8->VP.Height = v19;
    *(_QWORD *)&v8->VP.ScissorLeft = 0i64;
    *(_QWORD *)&v8->VP.ScissorWidth = 0i64;
    v8->VP.Flags = 0;
    v8->ViewRect.x1 = (signed int)v7->x1;
    v8->ViewRect.y1 = (signed int)v7->y1;
    v8->ViewRect.x2 = (signed int)v7->x2;
    v8->ViewRect.y2 = (signed int)v7->y2;
    v22 = v8->Matrices.pObject;
    v23 = -__that.OldViewport.Top;
    v24 = -__that.OldViewport.Left;
    v22->ViewRectOriginal.x1 -= __that.OldViewport.Left;
    v22->ViewRectOriginal.x2 += v24;
    v22->ViewRectOriginal.y1 += v23;
    v22->ViewRectOriginal.y2 += v23;
    v8->Matrices.pObject->UVPOChanged = 1;
    v8->HALState |= 0x20u;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v8->vfptr[17].__vecDelDtor)(v8);
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v8->RenderTargetStack.Data.Data,
      &v8->RenderTargetStack,
      v8->RenderTargetStack.Data.Size + 1);
    v25 = &v8->RenderTargetStack.Data.Data[v8->RenderTargetStack.Data.Size - 1];
    if ( v25 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v25, &__that);
  }
  else
  {
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v8->RenderTargetStack.Data.Data,
      &v8->RenderTargetStack,
      v8->RenderTargetStack.Data.Size + 1);
    v15 = &v8->RenderTargetStack.Data.Data[v8->RenderTargetStack.Data.Size - 1];
    if ( v15 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v15, &__that);
  }
  if ( __that.OldMatrixState.S3DImpl.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)__that.OldMatrixState.S3DImpl.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&__that.OldMatrixState.vfptr);
  if ( __that.pRenderTarget.pObject )
    ((void (*)(void))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)();
}

// File Line: 869
// RVA: 0x9FFC40
void __fastcall Scaleform::Render::D3D1x::HAL::PopRenderTarget(Scaleform::Render::D3D1x::HAL *this, unsigned int flags)
{
  char v2; // r12
  Scaleform::Render::D3D1x::HAL *v3; // rbx
  void *v4; // r15
  Scaleform::Render::HAL::RenderTargetEntry *v5; // r14
  Scaleform::Render::RenderBuffer::RenderTargetData *v6; // rdi
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::DepthStencilBuffer *v8; // rcx
  int v9; // er8
  int v10; // edx
  int v11; // ecx
  unsigned __int64 v12; // rdi
  Scaleform::Render::RenderBuffer *v13; // rbp
  Scaleform::Render::RenderBuffer::RenderTargetData *v14; // rdi
  unsigned __int64 v15; // rdx
  ID3D11ShaderResourceView *views; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+40h] [rbp-38h]

  v2 = flags;
  v3 = this;
  v4 = this->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)this, 11u);
  v5 = &v3->RenderTargetStack.Data.Data[v3->RenderTargetStack.Data.Size - 1];
  if ( v5->pRenderTarget.pObject->Type == 3 )
  {
    v6 = v5->pRenderTarget.pObject->pRenderTargetData;
    v7 = v6[1].pBuffer;
    if ( v7 )
    {
      ((void (*)(void))v7->vfptr[2].__vecDelDtor)();
      v6[1].pBuffer = 0i64;
    }
    v8 = v6->pDepthStencilBuffer.pObject;
    if ( v8 )
      ((void (*)(void))v8->vfptr[2].__vecDelDtor)();
    v6->pDepthStencilBuffer.pObject = 0i64;
  }
  v3->Matrices.pObject->vfptr[6].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v3->Matrices.pObject->vfptr,
    (unsigned int)&v5->OldMatrixState);
  v9 = v5->OldViewRect.y2;
  v10 = v5->OldViewRect.x2;
  v11 = v5->OldViewRect.y1;
  v3->ViewRect.x1 = v5->OldViewRect.x1;
  v3->ViewRect.y1 = v11;
  v3->ViewRect.x2 = v10;
  v3->ViewRect.y2 = v9;
  v3->VP.BufferWidth = v5->OldViewport.BufferWidth;
  v3->VP.BufferHeight = v5->OldViewport.BufferHeight;
  v3->VP.Left = v5->OldViewport.Left;
  v3->VP.Top = v5->OldViewport.Top;
  v3->VP.Width = v5->OldViewport.Width;
  v3->VP.Height = v5->OldViewport.Height;
  v3->VP.ScissorLeft = v5->OldViewport.ScissorLeft;
  v3->VP.ScissorTop = v5->OldViewport.ScissorTop;
  v3->VP.ScissorWidth = v5->OldViewport.ScissorWidth;
  v3->VP.ScissorHeight = v5->OldViewport.ScissorHeight;
  v3->VP.Flags = v5->OldViewport.Flags;
  v12 = v3->RenderTargetStack.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&v3->RenderTargetStack.Data.Data,
    &v3->RenderTargetStack,
    v12 - 1);
  if ( v12 - 1 > v12 )
    Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
      &v3->RenderTargetStack.Data.Data[v12],
      0xFFFFFFFFFFFFFFFFui64);
  v13 = 0i64;
  v14 = 0i64;
  v15 = v3->RenderTargetStack.Data.Size;
  if ( v15 )
  {
    v14 = v3->RenderTargetStack.Data.Data[v3->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject->pRenderTargetData;
    v13 = v14[1].pBuffer;
  }
  if ( v15 == 1 )
    v3->HALState &= 0xFFFFFFEF;
  views = 0i64;
  v17 = 0i64;
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(v3->pTextureManager.pObject, 0, 2u, &views, 0i64);
  if ( !(v2 & 4) )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, Scaleform::Render::RenderBuffer::RenderTargetData *, Scaleform::Render::RenderBuffer *))v3->pDeviceContext->vfptr[11].QueryInterface)(
      v3->pDeviceContext,
      1i64,
      &v14[1],
      v13);
    ++v3->AccumulatedStats.RTChanges;
    v3->HALState |= 0x20u;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v3->vfptr[17].__vecDelDtor)(v3);
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v4 + 24i64))(v4);
}

// File Line: 920
// RVA: 0xA03D00
bool __fastcall Scaleform::Render::D3D1x::HAL::createDefaultRenderBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::D3D1x::HAL *v1; // rsi
  _DWORD *v2; // rax
  int v3; // edx
  Scaleform::Render::DepthStencilBuffer *v4; // rbx
  _DWORD *v5; // rdi
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  ID3D11View *v9; // r9
  int v10; // er14
  int v11; // er15
  _DWORD *v12; // rax
  __int64 v13; // r8
  __int128 prt; // [rsp+20h] [rbp-89h]
  __int64 v16; // [rsp+30h] [rbp-79h]
  __int64 v17; // [rsp+38h] [rbp-71h]
  Scaleform::Render::DepthStencilBuffer *v18; // [rsp+40h] [rbp-69h]
  _DWORD *v19; // [rsp+48h] [rbp-61h]
  _DWORD *v20; // [rsp+50h] [rbp-59h]
  __int64 v21; // [rsp+58h] [rbp-51h]
  int v22; // [rsp+60h] [rbp-49h]
  int v23; // [rsp+64h] [rbp-45h]
  int v24; // [rsp+90h] [rbp-19h]
  int v25; // [rsp+94h] [rbp-15h]
  int v26; // [rsp+118h] [rbp+6Fh]
  int v27; // [rsp+120h] [rbp+77h]
  int v28; // [rsp+128h] [rbp+7Fh]
  int v29; // [rsp+12Ch] [rbp+83h]

  v21 = -2i64;
  v1 = this;
  if ( ((__int64 (*)(void))this->vfptr[20].__vecDelDtor)() )
  {
    v2 = (_DWORD *)((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))v1->vfptr[20].__vecDelDtor)(v1);
    v3 = v2[15] - v2[13];
    v28 = v2[14] - v2[12];
    v29 = v3;
    return ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, Scaleform::Render::D3D1x::TextureManager *, signed __int64, int *))v1->pRenderBufferManager.pObject->vfptr[1].__vecDelDtor)(
             v1->pRenderBufferManager.pObject,
             v1->pTextureManager.pObject,
             1i64,
             &v28);
  }
  v4 = 0i64;
  prt = 0ui64;
  v17 = 0i64;
  v16 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, signed __int64, __int128 *, char *))v1->pDeviceContext->vfptr[29].Release)(
    v1->pDeviceContext,
    1i64,
    &prt,
    (char *)&prt + 8);
  (*(void (__fastcall **)(_QWORD, __int64 *))(*(_QWORD *)prt + 56i64))(prt, &v17);
  (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v17 + 80i64))(v17, &v22);
  v28 = v22;
  v29 = v23;
  v26 = 72;
  v5 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                   Scaleform::Memory::pGlobalHeap,
                   v1,
                   64ui64,
                   (Scaleform::AllocInfo *)&v26);
  v19 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
    v5[2] = 1;
    *(_QWORD *)v5 = &Scaleform::RefCountVImpl::`vftable;
    *(_QWORD *)v5 = &Scaleform::Render::RenderBuffer::`vftable;
    v5[4] = 1;
    *((_QWORD *)v5 + 3) = 0i64;
    *((_QWORD *)v5 + 4) = 0i64;
    v6 = v29;
    v5[10] = v28;
    v5[11] = v6;
    *(_QWORD *)v5 = &Scaleform::Render::RenderTarget::`vftable;
    v7 = v29;
    v8 = v28;
    *((_QWORD *)v5 + 6) = 0i64;
    v5[14] = v8;
    v5[15] = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v20 = v5;
  v18 = 0i64;
  v9 = (ID3D11View *)*((_QWORD *)&prt + 1);
  if ( *((_QWORD *)&prt + 1) )
  {
    (*(void (__fastcall **)(_QWORD, __int64 *))(*(_QWORD *)prt + 56i64))(prt, &v16);
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v16 + 80i64))(v16, &v24);
    v10 = v24;
    v11 = v25;
    v27 = 72;
    v12 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      v1,
                      48ui64,
                      (Scaleform::AllocInfo *)&v27);
    v19 = v12;
    if ( v12 )
    {
      *(_QWORD *)v12 = &Scaleform::RefCountImplCore::`vftable;
      v12[2] = 1;
      *(_QWORD *)v12 = &Scaleform::RefCountVImpl::`vftable;
      *(_QWORD *)v12 = &Scaleform::Render::RenderBuffer::`vftable;
      v12[4] = 5;
      *((_QWORD *)v12 + 3) = 0i64;
      *((_QWORD *)v12 + 4) = 0i64;
      v12[10] = v10;
      v12[11] = v11;
      *(_QWORD *)v12 = &Scaleform::Render::DepthStencilBuffer::`vftable;
      v4 = (Scaleform::Render::DepthStencilBuffer *)v12;
    }
    v18 = v4;
    v9 = (ID3D11View *)*((_QWORD *)&prt + 1);
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(
    (Scaleform::Render::RenderBuffer *)v5,
    (ID3D11View *)prt,
    v4,
    v9);
  LOBYTE(v13) = 1;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _DWORD *, __int64))v1->vfptr[23].__vecDelDtor)(
         v1,
         v5,
         v13) )
  {
    if ( v4 )
      ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v4->vfptr[2].__vecDelDtor)(v4);
    if ( v5 )
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
    if ( v16 )
      (*(void (**)(void))(*(_QWORD *)v16 + 16i64))();
    if ( v17 )
      (*(void (**)(void))(*(_QWORD *)v17 + 16i64))();
    if ( *((_QWORD *)&prt + 1) )
      (*(void (**)(void))(**((_QWORD **)&prt + 1) + 16i64))();
    if ( (_QWORD)prt )
      (*(void (**)(void))(*(_QWORD *)prt + 16i64))();
    return ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, Scaleform::Render::D3D1x::TextureManager *, signed __int64, int *))v1->pRenderBufferManager.pObject->vfptr[1].__vecDelDtor)(
             v1->pRenderBufferManager.pObject,
             v1->pTextureManager.pObject,
             1i64,
             &v28);
  }
  if ( v4 )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v4->vfptr[2].__vecDelDtor)(v4);
  if ( v5 )
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
  if ( v16 )
    (*(void (**)(void))(*(_QWORD *)v16 + 16i64))();
  if ( v17 )
    (*(void (**)(void))(*(_QWORD *)v17 + 16i64))();
  if ( *((_QWORD *)&prt + 1) )
    (*(void (**)(void))(**((_QWORD **)&prt + 1) + 16i64))();
  if ( (_QWORD)prt )
    (*(void (**)(void))(*(_QWORD *)prt + 16i64))();
  return 0;
}

// File Line: 962
// RVA: 0xA06000
void __fastcall Scaleform::Render::D3D1x::HAL::setBatchUnitSquareVertexStream(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *v1; // rax
  ID3D11DeviceContext *v2; // rcx
  ID3D11Buffer *v3; // [rsp+40h] [rbp+8h]

  v1 = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  v2 = this->pDeviceContext;
  v3 = v1;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **, const unsigned int *, const unsigned int *))v2->vfptr[6].QueryInterface)(
    v2,
    0i64,
    1i64,
    &v3,
    &stride,
    &FLOAT_0_0);
}

// File Line: 970
// RVA: 0xA05360
void __fastcall Scaleform::Render::D3D1x::HAL::drawPrimitive(Scaleform::Render::D3D1x::HAL *this, __int64 indexCount, unsigned int meshCount)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, _QWORD))this->pDeviceContext->vfptr[4].AddRef)(
    this->pDeviceContext,
    indexCount,
    0i64);
}

// File Line: 982
// RVA: 0xA04F80
void __fastcall Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(Scaleform::Render::D3D1x::HAL *this, __int64 indexCount, unsigned int vertexCount, unsigned int meshCount, unsigned __int64 indexPtr, unsigned __int64 vertexOffset)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, _QWORD, _QWORD))this->pDeviceContext->vfptr[4].QueryInterface)(
    this->pDeviceContext,
    indexCount,
    (unsigned int)indexPtr,
    (unsigned int)vertexOffset);
}

// File Line: 994
// RVA: 0xA04F50
void __fastcall Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(Scaleform::Render::D3D1x::HAL *this, __int64 indexCount, unsigned int vertexCount, unsigned int meshCount, unsigned __int64 indexPtr, unsigned __int64 vertexOffset)
{
  __int64 v6; // r8
  __int64 v7; // r9

  v6 = meshCount;
  v7 = (unsigned int)indexPtr;
  LODWORD(indexPtr) = vertexOffset;
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, __int64, __int64, unsigned __int64))this->pDeviceContext->vfptr[6].Release)(
    this->pDeviceContext,
    indexCount,
    v6,
    v7,
    indexPtr);
}

// File Line: 1006
// RVA: 0xA06190
char __fastcall Scaleform::Render::D3D1x::HAL::shouldRenderFilters(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::FilterPrimitive *prim)
{
  Scaleform::Render::FilterPrimitive *v2; // rsi
  BasicArrayImplementation<hkDataObjectImpl *> *v4; // rsi
  unsigned int v5; // ebx
  unsigned int v6; // edi

  v2 = prim;
  if ( ((signed int (*)(void))this->SManager.vfptr->GetShaderVersion)() >= 2 )
    return 1;
  v4 = (BasicArrayImplementation<hkDataObjectImpl *> *)v2->pFilters.pObject;
  v5 = 0;
  v6 = BasicArrayImplementation<hkDataArrayImpl *>::getSize(v4);
  if ( !v6 )
    return 0;
  while ( Scaleform::Render::FilterSet::GetFilter((Scaleform::Render::FilterSet *)v4, v5)->Type != 8 )
  {
    if ( ++v5 >= v6 )
      return 0;
  }
  return 1;
}

// File Line: 1030
// RVA: 0x9FED10
Scaleform::Render::RenderEvent *__fastcall Scaleform::Render::D3D1x::HAL::GetEvent(Scaleform::Render::D3D1x::HAL *this, Scaleform::Render::EventType eventType)
{
  return Scaleform::Render::HAL::GetEvent((Scaleform::Render::HAL *)&this->vfptr, eventType);
}

// File Line: 1041
// RVA: 0xA05380
void __fastcall Scaleform::Render::D3D1x::HAL::drawScreenQuad(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *v1; // rax
  Scaleform::Render::D3D1x::HAL *v2; // rbx
  ID3D11DeviceContext *v3; // rcx
  ID3D11Buffer *v4; // [rsp+40h] [rbp+8h]

  v1 = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  v2 = this;
  v3 = this->pDeviceContext;
  v4 = v1;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, ID3D11Buffer **, const unsigned int *, const unsigned int *))v3->vfptr[6].QueryInterface)(
    v3,
    0i64,
    1i64,
    &v4,
    &stride,
    &FLOAT_0_0);
  ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, signed __int64, signed __int64))v2->vfptr[95].__vecDelDtor)(
    v2,
    6i64,
    1i64);
}

