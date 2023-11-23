// File Line: 49
// RVA: 0x9FB5D0
void __fastcall Scaleform::Render::D3D1x::HAL::HAL(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::ThreadCommandQueue *commandQueue)
{
  Scaleform::Render::MeshCacheParams params; // [rsp+28h] [rbp-50h] BYREF

  Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>(
    this,
    commandQueue);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::HAL::`vftable;
  this->pDevice = 0i64;
  this->pDeviceContext = 0i64;
  this->pRenderTargetView.pObject = 0i64;
  this->pDepthStencilView.pObject = 0i64;
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
  Scaleform::Render::D3D1x::MeshCache::MeshCache(&this->Cache, Scaleform::Memory::pGlobalHeap, &params);
  Scaleform::Render::D3D1x::RenderSync::RenderSync(&this->RSync);
  this->pTextureManager.pObject = 0i64;
  this->PrevBatchType = DP_None;
  this->CurrentConstantBuffer = 0;
}

// File Line: 53
// RVA: 0x9FBC50
void __fastcall Scaleform::Render::D3D1x::HAL::~HAL(Scaleform::Render::D3D1x::HAL *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  ID3D11DepthStencilView *v3; // rcx
  ID3D11RenderTargetView *v4; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::HAL::`vftable;
  Scaleform::Render::D3D1x::HAL::ShutdownHAL(this);
  pObject = (Scaleform::Render::RenderBuffer *)this->pTextureManager.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::D3D1x::RenderSync::~RenderSync(&this->RSync);
  Scaleform::Render::D3D1x::MeshCache::~MeshCache(&this->Cache);
  v3 = this->pDepthStencilView.pObject;
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = this->pRenderTargetView.pObject;
  if ( v4 )
    v4->vfptr->Release(v4);
  Scaleform::Render::D3D1x::ShaderManager::~ShaderManager(&this->SManager);
  Scaleform::Render::HAL::~HAL(this);
}

// File Line: 60
// RVA: 0x9FF0E0
char __fastcall Scaleform::Render::D3D1x::HAL::InitHAL(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::D3D1x::HALInitParams *params)
{
  ID3D11Device *pD3DDevice; // rcx
  ID3D11DeviceContext *pD3DContext; // rdx
  Scaleform::Render::D3D1x::TextureManager *pObject; // rsi
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::D3D1x::TextureManager *v8; // rax
  Scaleform::Render::D3D1x::TextureManager *v9; // rax
  Scaleform::Render::D3D1x::TextureManager *v10; // rsi
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::RenderBufferManager *v12; // rcx
  Scaleform::Render::RenderBufferManager *v13; // rcx
  Scaleform::Render::RBGenericImpl::RenderBufferManager *v14; // rax
  Scaleform::Render::RenderBufferManager *v15; // rax
  Scaleform::Render::RenderBufferManager *v16; // rdi
  Scaleform::Render::RenderBufferManager *v17; // rcx
  int v19; // [rsp+80h] [rbp+18h] BYREF
  ID3D11DeviceContext *v20; // [rsp+88h] [rbp+20h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[1].__vecDelDtor)(this) )
    return 0;
  pD3DDevice = params->pD3DDevice;
  if ( !pD3DDevice )
    return 0;
  this->pDevice = pD3DDevice;
  pD3DContext = params->pD3DContext;
  v20 = pD3DContext;
  if ( !pD3DContext )
  {
    ((void (__fastcall *)(ID3D11Device *, ID3D11DeviceContext **))pD3DDevice->vfptr->PSGetShaderResources)(
      pD3DDevice,
      &v20);
    pD3DContext = v20;
  }
  this->pDeviceContext = pD3DContext;
  Scaleform::Render::D3D1x::RenderEvent::pContext = pD3DContext;
  pD3DContext->vfptr->AddRef(pD3DContext);
  ((void (__fastcall *)(ID3D11Device *))this->pDevice->vfptr->AddRef)(this->pDevice);
  this->pDeviceContext->vfptr->AddRef(this->pDeviceContext);
  if ( !Scaleform::Render::D3D1x::RenderSync::SetDevice(&this->RSync, this->pDevice, this->pDeviceContext) )
    goto LABEL_6;
  if ( !Scaleform::Render::D3D1x::HAL::createBlendStates(this)
    || !Scaleform::Render::D3D1x::HAL::createDepthStencilStates(this)
    || !Scaleform::Render::D3D1x::HAL::createRasterStates(this)
    || !Scaleform::Render::D3D1x::HAL::createConstantBuffers(this)
    || !Scaleform::Render::D3D1x::ShaderManager::Initialize(&this->SManager, this)
    || !Scaleform::Render::D3D1x::MeshCache::Initialize(
          &this->Cache,
          this->pDevice,
          this->pDeviceContext,
          &this->SManager) )
  {
LABEL_39:
    ((void (__fastcall *)(ID3D11Device *))this->pDevice->vfptr->Release)(this->pDevice);
    this->pDeviceContext->vfptr->Release(this->pDeviceContext);
    this->pDevice = 0i64;
    this->pDeviceContext = 0i64;
    return 0;
  }
  pObject = (Scaleform::Render::D3D1x::TextureManager *)params->pTextureManager.pObject;
  if ( pObject )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)params->pTextureManager.pObject);
    v7 = (Scaleform::Render::RenderBuffer *)this->pTextureManager.pObject;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
    this->pTextureManager.pObject = pObject;
  }
  else
  {
    v19 = 72;
    v8 = (Scaleform::Render::D3D1x::TextureManager *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       552i64,
                                                       &v19);
    if ( v8 )
    {
      Scaleform::Render::D3D1x::TextureManager::TextureManager(
        v8,
        this->pDevice,
        this->pDeviceContext,
        params->RenderThreadId,
        this->pRTCommandQueue,
        0i64);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (Scaleform::Render::RenderBuffer *)this->pTextureManager.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    this->pTextureManager.pObject = v10;
    if ( !v10 )
    {
      Scaleform::Render::D3D1x::MeshCache::Reset(&this->Cache);
      Scaleform::Render::D3D1x::ShaderManager::Reset(&this->SManager);
    }
  }
  v12 = params->pRenderBufferManager.pObject;
  if ( v12 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v12);
    v13 = this->pRenderBufferManager.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
    this->pRenderBufferManager.pObject = params->pRenderBufferManager.pObject;
    goto LABEL_35;
  }
  v19 = 72;
  v14 = (Scaleform::Render::RBGenericImpl::RenderBufferManager *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   184i64,
                                                                   &v19);
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
  v17 = this->pRenderBufferManager.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v17);
  this->pRenderBufferManager.pObject = v16;
  if ( v16 && ((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[26].__vecDelDtor)(this) )
  {
LABEL_35:
    if ( this->pTextureManager.pObject && this->pRenderBufferManager.pObject )
    {
      this->HALState |= 1u;
      Scaleform::Render::HAL::notifyHandlers(this, 0);
      return 1;
    }
    goto LABEL_39;
  }
LABEL_6:
  ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[99].__vecDelDtor)(this);
  return 0;
}

// File Line: 145
// RVA: 0xA02EF0
char __fastcall Scaleform::Render::D3D1x::HAL::ShutdownHAL(Scaleform::Render::D3D1x::HAL *this)
{
  char result; // al
  ID3D11RenderTargetView *pObject; // rcx
  ID3D11DepthStencilView *v4; // rcx
  Scaleform::Render::RenderBufferManager *v5; // rcx
  ID3D11Device *v6; // rcx
  ID3D11DeviceContext *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  ID3D11Device *pDevice; // rcx

  if ( (this->HALState & 1) != 0 )
  {
    result = ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[3].__vecDelDtor)(this);
    if ( !result )
      return result;
    ((void (*)(void))Scaleform::Render::D3D1x::RenderEvent::pContext->vfptr->Release)();
    Scaleform::Render::D3D1x::RenderEvent::pContext = 0i64;
    Scaleform::Render::D3D1x::HAL::destroyBlendStates(this);
    Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(this);
    Scaleform::Render::D3D1x::HAL::destroyRasterStates(this);
    Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(this);
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->vfptr->Release(pObject);
    this->pRenderTargetView.pObject = 0i64;
    v4 = this->pDepthStencilView.pObject;
    if ( v4 )
      v4->vfptr->Release(v4);
    this->pDepthStencilView.pObject = 0i64;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[27].__vecDelDtor)(this);
    v5 = this->pRenderBufferManager.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
    this->pRenderBufferManager.pObject = 0i64;
    v6 = this->RSync.pDevice.pObject;
    if ( v6 )
      ((void (__fastcall *)(ID3D11Device *))v6->vfptr->Release)(v6);
    this->RSync.pDevice.pObject = 0i64;
    v7 = this->RSync.pDeviceContext.pObject;
    if ( v7 )
      v7->vfptr->Release(v7);
    this->RSync.pDeviceContext.pObject = 0i64;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames(&this->RSync);
    Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(&this->RSync.QueryList, 0i64, 0i64);
    Scaleform::Render::D3D1x::TextureManager::Reset(this->pTextureManager.pObject);
    v8 = (Scaleform::Render::RenderBuffer *)this->pTextureManager.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    this->pTextureManager.pObject = 0i64;
    Scaleform::Render::D3D1x::ShaderManager::Reset(&this->SManager);
    Scaleform::Render::D3D1x::MeshCache::Reset(&this->Cache);
    this->pDeviceContext->vfptr->Release(this->pDeviceContext);
    pDevice = this->pDevice;
    this->pDeviceContext = 0i64;
    ((void (__fastcall *)(ID3D11Device *))pDevice->vfptr->Release)(pDevice);
    this->pDevice = 0i64;
  }
  return 1;
}

// File Line: 255
// RVA: 0x9FCD00
__int64 __fastcall Scaleform::Render::D3D1x::HAL::BeginScene(Scaleform::Render::D3D1x::HAL *this)
{
  void *v2; // rbx
  unsigned __int8 v3; // di

  v2 = this->vfptr[60].__vecDelDtor(this, 3i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v2 + 16i64))(
    v2,
    "Scaleform::Render::D3D1x::HAL::BeginScene-SetState");
  if ( Scaleform::Render::HAL::BeginScene(this) )
  {
    _((AMD_HD3D *)&this->SManager);
    Scaleform::Render::D3D1x::ShaderInterface::BeginScene(&this->ShaderData);
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64, Scaleform::Ptr<ID3D11RenderTargetView> *, Scaleform::Ptr<ID3D11DepthStencilView> *))this->pDeviceContext->vfptr[29].Release)(
      this->pDeviceContext,
      1i64,
      &this->pRenderTargetView,
      &this->pDepthStencilView);
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64))this->pDeviceContext->vfptr[8].QueryInterface)(
      this->pDeviceContext,
      4i64);
    this->pDeviceContext->vfptr[12].QueryInterface(this->pDeviceContext, (_GUID *)this->DepthStencilStates[1], 0i64);
    this->CurrentConstantBuffer = 0;
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
  void *v2; // rdi
  ID3D11RenderTargetView *pObject; // rcx
  ID3D11DepthStencilView *v4; // rcx
  unsigned __int8 v5; // bl

  v2 = this->vfptr[60].__vecDelDtor(this, 2i64);
  if ( (unsigned __int8)Scaleform::Render::HAL::EndScene(this) )
  {
    _((AMD_HD3D *)&this->SManager);
    pObject = this->pRenderTargetView.pObject;
    if ( pObject )
      pObject->vfptr->Release(pObject);
    this->pRenderTargetView.pObject = 0i64;
    v4 = this->pDepthStencilView.pObject;
    if ( v4 )
      v4->vfptr->Release(v4);
    this->pDepthStencilView.pObject = 0i64;
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
  int Left; // edx
  bool v3; // zf
  int Top; // ecx
  int v5; // r8d
  int v6; // eax
  Scaleform::Render::MatrixState *pObject; // r9
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  ID3D11DeviceContext *pDeviceContext; // rcx
  int v12[2]; // [rsp+30h] [rbp-28h] BYREF
  float v13; // [rsp+38h] [rbp-20h]
  float v14; // [rsp+3Ch] [rbp-1Ch]
  __int64 v15; // [rsp+40h] [rbp-18h]

  Left = 0;
  v3 = (this->HALState & 0x20) == 0;
  Top = 0;
  v5 = 0;
  v6 = 0;
  if ( !v3 )
  {
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _QWORD, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Rect<int> *, int, int))this->vfptr[15].__vecDelDtor)(
      this,
      0i64,
      &this->Matrices.pObject->View2D,
      &this->ViewRect,
      this->ViewRect.x1 - this->VP.Left,
      this->ViewRect.y1 - this->VP.Top);
    this->Matrices.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[3].__vecDelDtor(
      this->Matrices.pObject,
      (unsigned int)&this->Matrices.pObject->User);
    pObject = this->Matrices.pObject;
    y2 = this->ViewRect.y2;
    x2 = this->ViewRect.x2;
    y1 = this->ViewRect.y1;
    pObject->ViewRect.x1 = this->ViewRect.x1;
    pObject->ViewRect.y1 = y1;
    pObject->ViewRect.x2 = x2;
    pObject->ViewRect.y2 = y2;
    this->Matrices.pObject->UVPOChanged = 1;
    if ( (this->HALState & 0x10) != 0 )
    {
      Left = this->VP.Left;
      Top = this->VP.Top;
      v5 = Left + this->VP.Width;
      v6 = Top + this->VP.Height;
    }
    else
    {
      Left = this->ViewRect.x1;
      Top = this->ViewRect.y1;
      v5 = this->ViewRect.x2;
      v6 = this->ViewRect.y2;
    }
  }
  *(float *)v12 = (float)Left;
  *(float *)&v12[1] = (float)Top;
  v13 = (float)(v5 - Left);
  v14 = (float)(v6 - Top);
  if ( v13 <= 1.0 )
    v13 = 1.0;
  if ( (float)(v6 - Top) <= 1.0 )
    v14 = 1.0;
  pDeviceContext = this->pDeviceContext;
  v15 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, int *))pDeviceContext->vfptr[14].Release)(
    pDeviceContext,
    1i64,
    v12);
}

// File Line: 344
// RVA: 0xA060F0
unsigned __int64 __fastcall Scaleform::Render::D3D1x::HAL::setVertexArray(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::PrimitiveBatch *pbatch,
        Scaleform::Render::MeshCacheItem *pmeshBase)
{
  Scaleform::Render::MeshCacheItem *pNext; // rdx
  int pCacheList; // eax
  ID3D11DeviceContext *pDeviceContext; // rcx
  int v10; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int64 AllocSize; // [rsp+48h] [rbp+10h] BYREF

  pNext = pmeshBase[1].pNext;
  pCacheList = (int)pmeshBase[1].pCacheList;
  pDeviceContext = this->pDeviceContext;
  AllocSize = pmeshBase[1].pPrev->AllocSize;
  v10 = pCacheList;
  ((void (__fastcall *)(ID3D11DeviceContext *, unsigned __int64, __int64))pDeviceContext->vfptr[6].AddRef)(
    pDeviceContext,
    pNext->AllocSize,
    57i64);
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, unsigned __int64 *, Scaleform::Render::VertexFormat *, int *))this->pDeviceContext->vfptr[6].QueryInterface)(
    this->pDeviceContext,
    0i64,
    1i64,
    &AllocSize,
    pbatch->pFormat,
    &v10);
  return (unsigned __int64)pmeshBase[1].PrimitiveBatches.Root.pPrev >> 1;
}

// File Line: 355
// RVA: 0xA06050
unsigned __int64 __fastcall Scaleform::Render::D3D1x::HAL::setVertexArray(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::ComplexMesh::FillRecord *fr,
        unsigned int formatIndex,
        Scaleform::Render::MeshCacheItem *pmeshBase)
{
  ID3D11DeviceContext *pDeviceContext; // rcx
  int v7; // eax
  unsigned int Size; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int64 AllocSize; // [rsp+48h] [rbp+10h] BYREF
  int v11; // [rsp+50h] [rbp+18h] BYREF

  pDeviceContext = this->pDeviceContext;
  v7 = LODWORD(fr->VertexByteOffset) + LODWORD(pmeshBase[1].pCacheList);
  AllocSize = pmeshBase[1].pPrev->AllocSize;
  v11 = v7;
  Size = fr->pFormats[formatIndex]->Size;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, unsigned __int64 *, unsigned int *, int *))pDeviceContext->vfptr[6].QueryInterface)(
    pDeviceContext,
    0i64,
    1i64,
    &AllocSize,
    &Size,
    &v11);
  ((void (__fastcall *)(ID3D11DeviceContext *, unsigned __int64, __int64))this->pDeviceContext->vfptr[6].AddRef)(
    this->pDeviceContext,
    pmeshBase[1].pNext->AllocSize,
    57i64);
  return (unsigned int)((unsigned __int64)pmeshBase[1].PrimitiveBatches.Root.pPrev >> 1);
}

// File Line: 371
// RVA: 0xA03560
void __fastcall Scaleform::Render::D3D1x::HAL::applyDepthStencilMode(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::HAL::DepthStencilMode mode,
        unsigned int stencilRef)
{
  __int64 v4; // rbp
  void *v6; // rsi

  v4 = mode;
  v6 = this->vfptr[60].__vecDelDtor(this, 14i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v6 + 16i64))(
    v6,
    "Scaleform::Render::D3D1x::HAL::applyDepthStencilMode");
  if ( *(_QWORD *)&this->CurrentDepthStencilState != __PAIR64__(stencilRef, v4) )
  {
    this->pDeviceContext->vfptr[12].QueryInterface(
      this->pDeviceContext,
      (_GUID *)this->DepthStencilStates[v4],
      (void **)stencilRef);
    this->CurrentStencilRef = stencilRef;
    if ( Scaleform::Render::HAL::DepthStencilModeTable[v4].ColorWriteEnable != Scaleform::Render::HAL::DepthStencilModeTable[this->CurrentDepthStencilState].ColorWriteEnable )
    {
      this->CurrentDepthStencilState = v4;
      ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _QWORD, bool, bool))this->vfptr[42].__vecDelDtor)(
        this,
        (unsigned int)this->CurrentBlendState.Mode,
        this->CurrentBlendState.SourceAc,
        this->CurrentBlendState.ForceAc);
    }
    this->CurrentDepthStencilState = v4;
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v6 + 24i64))(v6);
}

// File Line: 390
// RVA: 0xA03680
char __fastcall Scaleform::Render::D3D1x::HAL::checkDepthStencilBufferCaps(Scaleform::Render::D3D1x::HAL *this)
{
  char v2; // cl
  int v4[8]; // [rsp+28h] [rbp-20h] BYREF
  __int64 v5; // [rsp+50h] [rbp+8h] BYREF
  __int64 v6; // [rsp+58h] [rbp+10h] BYREF

  if ( this->StencilChecked )
    goto LABEL_14;
  this->StencilAvailable = 0;
  this->DepthBufferAvailable = 0;
  v5 = 0i64;
  v6 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, __int64 *, __int64 *, __int64))this->pDeviceContext->vfptr[29].Release)(
    this->pDeviceContext,
    1i64,
    &v6,
    &v5,
    -2i64);
  if ( !v5 )
    goto LABEL_10;
  (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v5 + 64i64))(v5, v4);
  switch ( v4[0] )
  {
    case 20:
      goto LABEL_8;
    case 40:
LABEL_9:
      this->DepthBufferAvailable = 1;
      break;
    case 45:
LABEL_8:
      *(_WORD *)&this->StencilAvailable = 257;
      goto LABEL_9;
    case 55:
      goto LABEL_9;
  }
LABEL_10:
  this->StencilChecked = 1;
  if ( v6 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
  if ( v5 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5);
LABEL_14:
  if ( this->StencilAvailable || this->DepthBufferAvailable )
    return 1;
  v2 = warned_2;
  if ( !warned_2 )
    v2 = 1;
  warned_2 = v2;
  return 0;
}

// File Line: 435
// RVA: 0x9FF4D0
bool __fastcall Scaleform::Render::D3D1x::HAL::IsRasterModeSupported(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::HAL::RasterModeType mode)
{
  return mode != RasterMode_Point;
}

// File Line: 441
// RVA: 0xA03660
void __fastcall Scaleform::Render::D3D1x::HAL::applyRasterModeImpl(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::HAL::RasterModeType mode)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11RasterizerState *))this->pDeviceContext->vfptr[14].AddRef)(
    this->pDeviceContext,
    this->RasterStates[mode]);
}

// File Line: 458
// RVA: 0xA03AC0
char __fastcall Scaleform::Render::D3D1x::HAL::createBlendStates(Scaleform::Render::D3D1x::HAL *this)
{
  unsigned int v2; // ebx
  char v3; // r8
  unsigned int v4; // ecx
  unsigned __int64 v5; // rcx
  int v6; // edx
  int v7; // eax
  int Dst[68]; // [rsp+20h] [rbp-118h] BYREF

  memset(this->BlendStates, 0, sizeof(this->BlendStates));
  v2 = 0;
  while ( 1 )
  {
    memset(Dst, 0, 0x108ui64);
    v3 = 0;
    v4 = v2;
    if ( v2 < 0x28 )
    {
      Dst[2] = 1;
      LOBYTE(Dst[9]) = 15;
      if ( v2 >= 0x14 )
      {
        v4 = v2 - 20;
        v3 = 1;
      }
    }
    else
    {
      Dst[2] = 0;
      LOBYTE(Dst[9]) = 0;
    }
    v5 = 3i64 * (v4 % 0x14);
    Dst[5] = BlendOps[Scaleform::Render::HAL::BlendModeTable[v5 / 3].Operator];
    v6 = BlendFactors[dword_1420BB1C4[2 * v5]];
    v7 = BlendFactors[dword_1420BB1C8[2 * v5]];
    Dst[3] = v6;
    Dst[4] = v7;
    Dst[8] = BlendOps[dword_1420BB1CC[2 * v5]];
    Dst[6] = BlendFactors[dword_1420BB1D0[2 * v5]];
    Dst[7] = BlendFactors[dword_1420BB1D4[2 * v5]];
    if ( v3 )
    {
      if ( v6 == 5 )
        v6 = 2;
      Dst[3] = v6;
    }
    if ( ((int (__fastcall *)(ID3D11Device *, int *, ID3D11BlendState **))this->pDevice->vfptr->VSSetSamplers)(
           this->pDevice,
           Dst,
           &this->BlendStates[v2]) < 0 )
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
  ID3D11BlendState **BlendStates; // rsi
  __int64 v2; // rdi
  ID3D11BlendState **v3; // rbx

  BlendStates = this->BlendStates;
  v2 = 41i64;
  v3 = this->BlendStates;
  do
  {
    if ( *v3 )
      (*v3)->vfptr->Release(*v3);
    ++v3;
    --v2;
  }
  while ( v2 );
  memset(BlendStates, 0, 0x148ui64);
}

// File Line: 549
// RVA: 0xA04010
char __fastcall Scaleform::Render::D3D1x::HAL::createDepthStencilStates(Scaleform::Render::D3D1x::HAL *this)
{
  unsigned int v2; // edi
  Scaleform::Render::HAL::EnableIgnoreValue *p_DepthWriteEnable; // rbx
  int v4; // r8d
  __int64 v5; // rax
  int v6; // edx
  __int64 v7; // rax
  int v8; // ecx
  ID3D11Device *pDevice; // rcx
  int Dst[16]; // [rsp+20h] [rbp-48h] BYREF

  this->DepthStencilStates[0] = 0i64;
  this->DepthStencilStates[1] = 0i64;
  this->DepthStencilStates[2] = 0i64;
  this->DepthStencilStates[3] = 0i64;
  this->DepthStencilStates[4] = 0i64;
  this->DepthStencilStates[5] = 0i64;
  this->DepthStencilStates[6] = 0i64;
  v2 = 0;
  p_DepthWriteEnable = &Scaleform::Render::HAL::DepthStencilModeTable[0].DepthWriteEnable;
  this->DepthStencilStates[7] = 0i64;
  while ( 1 )
  {
    memset(Dst, 0, 0x34ui64);
    Dst[3] = *((_DWORD *)p_DepthWriteEnable + 1) != 0;
    if ( *((_DWORD *)p_DepthWriteEnable - 1) || (Dst[0] = 0, *p_DepthWriteEnable) )
      Dst[0] = 1;
    LOWORD(Dst[4]) = -1;
    Dst[1] = *p_DepthWriteEnable != EnableIgnore_Off;
    Dst[2] = ComparisonFunctions[*((int *)p_DepthWriteEnable + 3)];
    v4 = StencilOperations[*((int *)p_DepthWriteEnable + 5)];
    v5 = *((int *)p_DepthWriteEnable + 6);
    Dst[8] = ComparisonFunctions[*((int *)p_DepthWriteEnable + 4)];
    v6 = StencilOperations[v5];
    v7 = *((int *)p_DepthWriteEnable + 7);
    Dst[7] = v4;
    v8 = StencilOperations[v7];
    Dst[5] = v6;
    Dst[9] = v6;
    Dst[6] = v8;
    Dst[10] = v8;
    pDevice = this->pDevice;
    Dst[11] = v4;
    Dst[12] = Dst[8];
    if ( ((int (__fastcall *)(ID3D11Device *, int *, ID3D11DepthStencilState **))pDevice->vfptr->SetPredication)(
           pDevice,
           Dst,
           &this->DepthStencilStates[v2]) < 0 )
      break;
    ++v2;
    p_DepthWriteEnable += 9;
    if ( v2 >= 8 )
      return 1;
  }
  return 0;
}

// File Line: 603
// RVA: 0xA04300
void __fastcall Scaleform::Render::D3D1x::HAL::destroyDepthStencilStates(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11DepthStencilState **DepthStencilStates; // rdi
  __int64 v2; // rsi
  ID3D11DepthStencilState **v3; // rbx

  DepthStencilStates = this->DepthStencilStates;
  v2 = 8i64;
  v3 = this->DepthStencilStates;
  do
  {
    if ( *v3 )
      (*v3)->vfptr->Release(*v3);
    ++v3;
    --v2;
  }
  while ( v2 );
  *DepthStencilStates = 0i64;
  DepthStencilStates[1] = 0i64;
  DepthStencilStates[2] = 0i64;
  DepthStencilStates[3] = 0i64;
  DepthStencilStates[4] = 0i64;
  DepthStencilStates[5] = 0i64;
  DepthStencilStates[6] = 0i64;
  DepthStencilStates[7] = 0i64;
}

// File Line: 613
// RVA: 0xA04180
char __fastcall Scaleform::Render::D3D1x::HAL::createRasterStates(Scaleform::Render::D3D1x::HAL *this)
{
  int v2; // ebx
  int Dst[14]; // [rsp+20h] [rbp-38h] BYREF

  v2 = 0;
  this->RasterStates[0] = 0i64;
  this->RasterStates[1] = 0i64;
  this->RasterStates[2] = 0i64;
  while ( 1 )
  {
    memset(Dst, 0, 0x28ui64);
    Dst[1] = 1;
    Dst[6] = 1;
    Dst[0] = 3;
    if ( v2 == 1 )
      Dst[0] = 2;
    if ( ((int (__fastcall *)(ID3D11Device *, int *, ID3D11RasterizerState **))this->pDevice->vfptr->GSSetShaderResources)(
           this->pDevice,
           Dst,
           &this->RasterStates[v2]) < 0 )
      break;
    if ( (unsigned int)++v2 >= 3 )
      return 1;
  }
  return 0;
}

// File Line: 633
// RVA: 0xA04370
void __fastcall Scaleform::Render::D3D1x::HAL::destroyRasterStates(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11RasterizerState **RasterStates; // rsi
  __int64 v2; // rdi
  ID3D11RasterizerState **v3; // rbx

  RasterStates = this->RasterStates;
  v2 = 3i64;
  v3 = this->RasterStates;
  do
  {
    if ( *v3 )
      (*v3)->vfptr->Release(*v3);
    ++v3;
    --v2;
  }
  while ( v2 );
  *RasterStates = 0i64;
  RasterStates[1] = 0i64;
  RasterStates[2] = 0i64;
}

// File Line: 643
// RVA: 0xA03C30
char __fastcall Scaleform::Render::D3D1x::HAL::createConstantBuffers(Scaleform::Render::D3D1x::HAL *this)
{
  int v2; // ebx
  ID3D11Device *pDevice; // rcx
  __int64 v5; // [rsp+20h] [rbp-28h] BYREF
  __int64 v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]

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
    pDevice = this->pDevice;
    v5 = 0x2000040C0i64;
    v6 = 0x1000000000004i64;
    if ( ((int (__fastcall *)(ID3D11Device *, __int64 *, _QWORD, ID3D11Buffer **))pDevice->vfptr->VSSetConstantBuffers)(
           pDevice,
           &v5,
           0i64,
           &this->ConstantBuffers[v2]) < 0 )
      break;
    if ( (unsigned int)++v2 >= 8 )
      return 1;
  }
  return 0;
}

// File Line: 660
// RVA: 0xA04290
void __fastcall Scaleform::Render::D3D1x::HAL::destroyConstantBuffers(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer **ConstantBuffers; // rdi
  __int64 v2; // rsi
  ID3D11Buffer **v3; // rbx

  ConstantBuffers = this->ConstantBuffers;
  v2 = 8i64;
  v3 = this->ConstantBuffers;
  do
  {
    if ( *v3 )
      (*v3)->vfptr->Release(*v3);
    ++v3;
    --v2;
  }
  while ( v2 );
  *ConstantBuffers = 0i64;
  ConstantBuffers[1] = 0i64;
  ConstantBuffers[2] = 0i64;
  ConstantBuffers[3] = 0i64;
  ConstantBuffers[4] = 0i64;
  ConstantBuffers[5] = 0i64;
  ConstantBuffers[6] = 0i64;
  ConstantBuffers[7] = 0i64;
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
void __fastcall Scaleform::Render::D3D1x::HAL::applyBlendModeImpl(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::BlendMode mode,
        bool sourceAc,
        bool forceAc)
{
  ID3D11DeviceContext *pDeviceContext; // r11
  int v5; // eax

  pDeviceContext = this->pDeviceContext;
  if ( pDeviceContext )
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
      mode = Blend_None;
    }
    ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11BlendState *, _QWORD, __int64))pDeviceContext->vfptr[11].Release)(
      this->pDeviceContext,
      this->BlendStates[mode + v5],
      0i64,
      0xFFFFFFFFi64);
  }
}

// File Line: 687
// RVA: 0x9FCDE0
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        ID3D11View *pcolor,
        ID3D11View *pdepth)
{
  Scaleform::Render::DepthStencilBuffer *v6; // rbx
  __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rdi
  int v9; // r15d
  int v10; // r12d
  _DWORD *v11; // rax
  __int64 v13; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::Render::DepthStencilBuffer *v14; // [rsp+38h] [rbp-71h]
  Scaleform::Render::RenderBuffer *v15; // [rsp+40h] [rbp-69h]
  _DWORD *v16; // [rsp+48h] [rbp-61h]
  __int64 v17; // [rsp+50h] [rbp-59h]
  __int64 v18[6]; // [rsp+58h] [rbp-51h] BYREF
  int v19[26]; // [rsp+88h] [rbp-21h] BYREF
  int v20; // [rsp+118h] [rbp+6Fh] BYREF
  __int64 v21; // [rsp+120h] [rbp+77h] BYREF
  __int64 v22; // [rsp+128h] [rbp+7Fh] BYREF

  v17 = -2i64;
  v6 = 0i64;
  v13 = 0i64;
  v22 = 0i64;
  v21 = 0i64;
  ((void (__fastcall *)(ID3D11View *, __int64 *))pcolor->vfptr[2].AddRef)(pcolor, &v13);
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v13 + 80i64))(v13, v18);
  v21 = v18[0];
  v7 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, __int64 *, __int64, __int64, _QWORD))this->pRenderBufferManager.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[5].__vecDelDtor)(
         this->pRenderBufferManager.pObject,
         &v21,
         2i64,
         1i64,
         0i64);
  v8 = (Scaleform::Render::RenderBuffer *)v7;
  if ( v7 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
  v15 = v8;
  v14 = 0i64;
  if ( pdepth )
  {
    ((void (__fastcall *)(ID3D11View *, __int64 *))pdepth->vfptr[2].AddRef)(pdepth, &v22);
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v22 + 80i64))(v22, v19);
    v9 = v19[0];
    v10 = v19[1];
    v20 = 72;
    v11 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 48i64, &v20);
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
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v8, pcolor, v6, pdepth);
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v6->vfptr[2].__vecDelDtor)(v6);
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v8->vfptr[2].__vecDelDtor)(v8);
  if ( v22 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
  if ( v13 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
  return (Scaleform::Render::RenderTarget *)v8;
}

// File Line: 714
// RVA: 0x9FCF90
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::D3D1x::HAL::CreateRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Texture *texture,
        bool needsStencil)
{
  Scaleform::Render::RenderBufferManager *pObject; // rdi
  unsigned int Height; // r9d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  unsigned int v9; // eax
  Scaleform::Render::RenderBuffer *v10; // rbp
  ID3D11View *v11; // rdi
  Scaleform::Render::DepthStencilBuffer *v12; // rbx
  Scaleform::Render::RenderBufferManager *v13; // rcx
  unsigned int v14; // edx
  __int64 v15; // rax
  __int64 v16; // rax
  int v18[2]; // [rsp+30h] [rbp-48h] BYREF
  __int64 v19; // [rsp+38h] [rbp-40h]
  __int64 v20; // [rsp+40h] [rbp-38h]
  ID3D11View *prt; // [rsp+88h] [rbp+10h] BYREF
  unsigned int Width; // [rsp+98h] [rbp+20h] BYREF
  unsigned int v23; // [rsp+9Ch] [rbp+24h]

  v20 = -2i64;
  if ( !texture )
    return 0i64;
  if ( texture->TextureCount != 1 )
    return 0i64;
  pObject = this->pRenderBufferManager.pObject;
  Height = texture->ImgSize.Height;
  Width = texture->ImgSize.Width;
  v23 = Height;
  vfptr = pObject->vfptr;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::Texture *))texture->vfptr[4].__vecDelDtor)(texture);
  v10 = (Scaleform::Render::RenderBuffer *)((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, unsigned int *, __int64, _QWORD, Scaleform::Render::Texture *))vfptr[5].__vecDelDtor)(
                                             pObject,
                                             &Width,
                                             4i64,
                                             v9,
                                             texture);
  if ( !v10 )
    return 0i64;
  v11 = 0i64;
  prt = 0i64;
  if ( ((int (__fastcall *)(ID3D11Device *, void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int), _QWORD, ID3D11View **))this->pDevice->vfptr->Draw)(
         this->pDevice,
         texture[1].vfptr[1].__vecDelDtor,
         0i64,
         &prt) < 0 )
  {
    v10 = 0i64;
  }
  else
  {
    v12 = 0i64;
    v19 = 0i64;
    if ( needsStencil )
    {
      v13 = this->pRenderBufferManager.pObject;
      v14 = texture->ImgSize.Height;
      v18[0] = texture->ImgSize.Width;
      v18[1] = v14;
      v15 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, int *, _QWORD))v13->vfptr[7].__vecDelDtor)(
              v13,
              v18,
              0i64);
      v12 = (Scaleform::Render::DepthStencilBuffer *)v15;
      v19 = v15;
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
    prt->vfptr->Release(prt);
  return (Scaleform::Render::RenderTarget *)v10;
}

// File Line: 745
// RVA: 0x9FD0F0
Scaleform::Render::RenderTarget *__fastcall Scaleform::Render::D3D1x::HAL::CreateTempRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Size<unsigned long> *size,
        bool needsStencil)
{
  Scaleform::Render::RenderTarget *result; // rax
  Scaleform::Render::RenderTarget *v6; // rdi
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rax
  __int64 v8; // r15
  ID3D11View *v9; // rsi
  __int64 v10; // r8
  Scaleform::Render::DepthStencilBuffer *v11; // rbx
  Scaleform::Render::RenderBufferManager *pObject; // rcx
  int v13; // edx
  __int64 v14; // rax
  __int64 v15; // rax
  ID3D11View *prt; // [rsp+60h] [rbp+8h] BYREF
  int v17; // [rsp+78h] [rbp+20h] BYREF
  int v18; // [rsp+7Ch] [rbp+24h]

  result = (Scaleform::Render::RenderTarget *)this->pRenderBufferManager.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[6].__vecDelDtor(
                                                this->pRenderBufferManager.pObject,
                                                size);
  v6 = result;
  if ( result )
  {
    pRenderTargetData = result->pRenderTargetData;
    if ( pRenderTargetData && (!needsStencil || pRenderTargetData->pDepthStencilBuffer.pObject) )
    {
      return v6;
    }
    else
    {
      v8 = ((__int64 (__fastcall *)(Scaleform::Render::RenderTarget *))v6->vfptr[3].__vecDelDtor)(v6);
      v9 = 0i64;
      prt = 0i64;
      if ( ((int (__fastcall *)(ID3D11Device *, _QWORD, _QWORD, ID3D11View **))this->pDevice->vfptr->Draw)(
             this->pDevice,
             *(_QWORD *)(*(_QWORD *)(v8 + 88) + 8i64),
             0i64,
             &prt) >= 0 )
      {
        v11 = 0i64;
        if ( needsStencil )
        {
          pObject = this->pRenderBufferManager.pObject;
          v13 = *(_DWORD *)(v8 + 52);
          v17 = *(_DWORD *)(v8 + 48);
          v18 = v13;
          LOBYTE(v10) = 1;
          v14 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, int *, __int64))pObject->vfptr[7].__vecDelDtor)(
                  pObject,
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
        Scaleform::Render::D3D1x::RenderTargetData::UpdateData(v6, prt, v11, v9);
        v9 = (ID3D11View *)v6;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v11->vfptr[2].__vecDelDtor)(v11);
      }
      if ( prt )
        prt->vfptr->Release(prt);
      return (Scaleform::Render::RenderTarget *)v9;
    }
  }
  return result;
}

// File Line: 780
// RVA: 0xA02980
char __fastcall Scaleform::Render::D3D1x::HAL::SetRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::RenderTarget *ptarget,
        bool setState)
{
  __int64 v7; // rdx
  __int64 v8; // r8
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rcx
  Scaleform::Render::RenderBuffer *pBuffer; // r9
  Scaleform::Render::HAL::RenderTargetEntry *v11; // rcx
  Scaleform::Render::HAL::RenderTargetEntry __that; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *vfptr; // [rsp+348h] [rbp+260h] BYREF

  if ( (this->HALState & 4) != 0 )
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[8].__vecDelDtor)(this);
  if ( (this->HALState & 8) != 0 )
    return 0;
  __that.pRenderTarget.pObject = 0i64;
  Scaleform::Render::MatrixState::MatrixState(&__that.OldMatrixState);
  memset(&__that.OldMatrixState.FullViewportMVP.M[0][2], 0, 32);
  __that.OldViewRect.y2 = 1;
  __that.OldViewRect.x2 = 1;
  memset(&__that.OldViewport, 0, 20);
  pRenderTargetData = ptarget->pRenderTargetData;
  vfptr = pRenderTargetData[1].vfptr;
  pBuffer = pRenderTargetData[1].pBuffer;
  if ( setState )
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64, Scaleform::Render::RenderBuffer::RenderTargetDataVtbl **, Scaleform::Render::RenderBuffer *))this->pDeviceContext->vfptr[11].QueryInterface)(
      this->pDeviceContext,
      1i64,
      &vfptr,
      pBuffer);
  ((void (__fastcall *)(Scaleform::Render::RenderTarget *, __int64, __int64, Scaleform::Render::RenderBuffer *))ptarget->vfptr[1].__vecDelDtor)(
    ptarget,
    v7,
    v8,
    pBuffer);
  __that.pRenderTarget.pObject = ptarget;
  if ( this->RenderTargetStack.Data.Size )
  {
    Scaleform::Render::HAL::RenderTargetEntry::operator=(this->RenderTargetStack.Data.Data, &__that);
  }
  else
  {
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->RenderTargetStack.Data,
      &this->RenderTargetStack,
      this->RenderTargetStack.Data.Size + 1);
    v11 = &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1];
    if ( v11 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v11, &__that);
  }
  if ( *(_QWORD *)&__that.OldMatrixState.ViewRectCompensated3D.M[3][0] )
    Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&__that.OldMatrixState.ViewRectCompensated3D.M[3][0]);
  Scaleform::RefCountImplCore::~RefCountImplCore(&__that.OldMatrixState);
  if ( __that.pRenderTarget.pObject )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(__that.pRenderTarget.pObject);
  return 1;
}

// File Line: 810
// RVA: 0xA00230
void __fastcall Scaleform::Render::D3D1x::HAL::PushRenderTarget(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::Rect<float> *frameRect,
        Scaleform::Render::RenderTarget *prt,
        char flags,
        Scaleform::Render::Color *clearColor)
{
  void *v9; // rax
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  Scaleform::Render::MatrixState *pObject; // rax
  Scaleform::Render::MatrixState *v14; // rbx
  Scaleform::Render::HAL::RenderTargetEntry *v15; // rcx
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rbx
  int v17; // r8d
  int x1; // edx
  int v19; // r10d
  int v20; // r9d
  int Height; // ecx
  Scaleform::Render::MatrixState *v22; // rdx
  int v23; // ecx
  int v24; // eax
  Scaleform::Render::HAL::RenderTargetEntry *v25; // rcx
  float pr; // [rsp+30h] [rbp-D0h] BYREF
  float pg; // [rsp+34h] [rbp-CCh] BYREF
  float pb; // [rsp+38h] [rbp-C8h] BYREF
  float pa; // [rsp+3Ch] [rbp-C4h] BYREF
  ID3D11ShaderResourceView *views[4]; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::Render::HAL::RenderTargetEntry __that; // [rsp+60h] [rbp-A0h] BYREF

  views[2] = (ID3D11ShaderResourceView *)-2i64;
  v9 = this->vfptr[60].__vecDelDtor(this, 11i64);
  (*(void (__fastcall **)(void *, const char *))(*(_QWORD *)v9 + 16i64))(
    v9,
    "Scaleform::Render::D3D1x::HAL::PushRenderTarget");
  this->HALState |= 0x10u;
  __that.pRenderTarget.pObject = 0i64;
  Scaleform::Render::MatrixState::MatrixState(&__that.OldMatrixState);
  memset(&__that.OldViewRect, 0, 32);
  __that.OldViewport.Height = 1;
  __that.OldViewport.Width = 1;
  memset(&__that.OldViewport.ScissorLeft, 0, 20);
  if ( prt )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))prt->vfptr[1].__vecDelDtor)(prt);
  __that.pRenderTarget.pObject = prt;
  __that.OldViewport = this->VP;
  y2 = this->ViewRect.y2;
  x2 = this->ViewRect.x2;
  y1 = this->ViewRect.y1;
  __that.OldViewRect.x1 = this->ViewRect.x1;
  __that.OldViewRect.y1 = y1;
  __that.OldViewRect.x2 = x2;
  __that.OldViewRect.y2 = y2;
  Scaleform::Render::MatrixState::CopyFrom(&__that.OldMatrixState, this->Matrices.pObject);
  pObject = this->Matrices.pObject;
  *(_QWORD *)&pObject->Orient2D.M[0][0] = 1065353216i64;
  *(_QWORD *)&pObject->Orient2D.M[0][2] = 0i64;
  pObject->Orient2D.M[1][0] = 0.0;
  *(_QWORD *)&pObject->Orient2D.M[1][1] = 1065353216i64;
  pObject->Orient2D.M[1][3] = 0.0;
  v14 = this->Matrices.pObject;
  memset(&v14->Orient3D, 0, sizeof(v14->Orient3D));
  v14->Orient3D.M[0][0] = 1.0;
  v14->Orient3D.M[1][1] = 1.0;
  v14->Orient3D.M[2][2] = 1.0;
  v14->Orient3D.M[3][3] = 1.0;
  this->Matrices.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[3].__vecDelDtor(
    this->Matrices.pObject,
    (unsigned int)&Scaleform::Render::Matrix2x4<float>::Identity);
  if ( prt )
  {
    pRenderTargetData = prt->pRenderTargetData;
    views[0] = 0i64;
    views[1] = 0i64;
    Scaleform::Render::D3D1x::TextureManager::SetSamplerState(this->pTextureManager.pObject, 0, 2u, views, 0i64);
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64, Scaleform::Render::RenderBuffer::RenderTargetData *, Scaleform::Render::RenderBuffer *))this->pDeviceContext->vfptr[11].QueryInterface)(
      this->pDeviceContext,
      1i64,
      &pRenderTargetData[1],
      pRenderTargetData[1].pBuffer);
    this->StencilChecked = 0;
    ++this->AccumulatedStats.RTChanges;
    if ( (flags & 1) == 0 )
    {
      Scaleform::Render::Color::GetRGBAFloat(clearColor, &pr, &pg, &pb, &pa);
      ((void (__fastcall *)(ID3D11DeviceContext *, Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *, float *))this->pDeviceContext->vfptr[16].Release)(
        this->pDeviceContext,
        pRenderTargetData[1].vfptr,
        &pr);
    }
    v17 = prt->ViewRect.y1;
    x1 = prt->ViewRect.x1;
    v19 = prt->ViewRect.y2 - v17;
    v20 = prt->ViewRect.x2 - x1;
    Height = prt->BufferSize.Height;
    this->VP.BufferWidth = prt->BufferSize.Width;
    this->VP.BufferHeight = Height;
    this->VP.Left = x1;
    this->VP.Top = v17;
    this->VP.Width = v20;
    this->VP.Height = v19;
    *(_QWORD *)&this->VP.ScissorLeft = 0i64;
    *(_QWORD *)&this->VP.ScissorWidth = 0i64;
    this->VP.Flags = 0;
    this->ViewRect.x1 = (int)frameRect->x1;
    this->ViewRect.y1 = (int)frameRect->y1;
    this->ViewRect.x2 = (int)frameRect->x2;
    this->ViewRect.y2 = (int)frameRect->y2;
    v22 = this->Matrices.pObject;
    v23 = -__that.OldViewport.Top;
    v24 = -__that.OldViewport.Left;
    v22->ViewRectOriginal.x1 -= __that.OldViewport.Left;
    v22->ViewRectOriginal.x2 += v24;
    v22->ViewRectOriginal.y1 += v23;
    v22->ViewRectOriginal.y2 += v23;
    this->Matrices.pObject->UVPOChanged = 1;
    this->HALState |= 0x20u;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[17].__vecDelDtor)(this);
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->RenderTargetStack.Data,
      &this->RenderTargetStack,
      this->RenderTargetStack.Data.Size + 1);
    v25 = &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1];
    if ( v25 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v25, &__that);
  }
  else
  {
    Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
      &this->RenderTargetStack.Data,
      &this->RenderTargetStack,
      this->RenderTargetStack.Data.Size + 1);
    v15 = &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1];
    if ( v15 )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(v15, &__that);
  }
  if ( __that.OldMatrixState.S3DImpl.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)__that.OldMatrixState.S3DImpl.pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(&__that.OldMatrixState);
  if ( __that.pRenderTarget.pObject )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))__that.pRenderTarget.pObject->vfptr[2].__vecDelDtor)(__that.pRenderTarget.pObject);
}

// File Line: 869
// RVA: 0x9FFC40
void __fastcall Scaleform::Render::D3D1x::HAL::PopRenderTarget(Scaleform::Render::D3D1x::HAL *this, char flags)
{
  void *v4; // r15
  Scaleform::Render::HAL::RenderTargetEntry *v5; // r14
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rdi
  Scaleform::Render::RenderBuffer *pBuffer; // rcx
  Scaleform::Render::DepthStencilBuffer *pObject; // rcx
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  unsigned __int64 Size; // rdi
  Scaleform::Render::RenderBuffer *v13; // rbp
  Scaleform::Render::RenderBuffer::RenderTargetData *v14; // rdi
  unsigned __int64 v15; // rdx
  ID3D11ShaderResourceView *views[3]; // [rsp+38h] [rbp-40h] BYREF

  v4 = this->vfptr[60].__vecDelDtor(this, 11i64);
  v5 = &this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1];
  if ( v5->pRenderTarget.pObject->Type == RBuffer_Temporary )
  {
    pRenderTargetData = v5->pRenderTarget.pObject->pRenderTargetData;
    pBuffer = pRenderTargetData[1].pBuffer;
    if ( pBuffer )
    {
      ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pBuffer->vfptr[2].__vecDelDtor)(pBuffer);
      pRenderTargetData[1].pBuffer = 0i64;
    }
    pObject = pRenderTargetData->pDepthStencilBuffer.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pObject->vfptr[2].__vecDelDtor)(pObject);
    pRenderTargetData->pDepthStencilBuffer.pObject = 0i64;
  }
  this->Matrices.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[6].__vecDelDtor(
    this->Matrices.pObject,
    (unsigned int)&v5->OldMatrixState);
  y2 = v5->OldViewRect.y2;
  x2 = v5->OldViewRect.x2;
  y1 = v5->OldViewRect.y1;
  this->ViewRect.x1 = v5->OldViewRect.x1;
  this->ViewRect.y1 = y1;
  this->ViewRect.x2 = x2;
  this->ViewRect.y2 = y2;
  this->VP.BufferWidth = v5->OldViewport.BufferWidth;
  this->VP.BufferHeight = v5->OldViewport.BufferHeight;
  this->VP.Left = v5->OldViewport.Left;
  this->VP.Top = v5->OldViewport.Top;
  this->VP.Width = v5->OldViewport.Width;
  this->VP.Height = v5->OldViewport.Height;
  this->VP.ScissorLeft = v5->OldViewport.ScissorLeft;
  this->VP.ScissorTop = v5->OldViewport.ScissorTop;
  this->VP.ScissorWidth = v5->OldViewport.ScissorWidth;
  this->VP.ScissorHeight = v5->OldViewport.ScissorHeight;
  this->VP.Flags = v5->OldViewport.Flags;
  Size = this->RenderTargetStack.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::Render::HAL::RenderTargetEntry,Scaleform::AllocatorLH<Scaleform::Render::HAL::RenderTargetEntry,2>,Scaleform::ArrayConstPolicy<0,8,1>>::ResizeNoConstruct(
    &this->RenderTargetStack.Data,
    &this->RenderTargetStack,
    Size - 1);
  if ( Size - 1 > Size )
    Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
      (char *)&this->RenderTargetStack.Data.Data[Size],
      0xFFFFFFFFFFFFFFFFui64);
  v13 = 0i64;
  v14 = 0i64;
  v15 = this->RenderTargetStack.Data.Size;
  if ( v15 )
  {
    v14 = this->RenderTargetStack.Data.Data[this->RenderTargetStack.Data.Size - 1].pRenderTarget.pObject->pRenderTargetData;
    v13 = v14[1].pBuffer;
  }
  if ( v15 == 1 )
    this->HALState &= ~0x10u;
  views[0] = 0i64;
  views[1] = 0i64;
  Scaleform::Render::D3D1x::TextureManager::SetSamplerState(this->pTextureManager.pObject, 0, 2u, views, 0i64);
  if ( (flags & 4) == 0 )
  {
    ((void (__fastcall *)(ID3D11DeviceContext *, __int64, Scaleform::Render::RenderBuffer::RenderTargetData *, Scaleform::Render::RenderBuffer *))this->pDeviceContext->vfptr[11].QueryInterface)(
      this->pDeviceContext,
      1i64,
      &v14[1],
      v13);
    ++this->AccumulatedStats.RTChanges;
    this->HALState |= 0x20u;
    ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[17].__vecDelDtor)(this);
  }
  (*(void (__fastcall **)(void *))(*(_QWORD *)v4 + 24i64))(v4);
}

// File Line: 920
// RVA: 0xA03D00
bool __fastcall Scaleform::Render::D3D1x::HAL::createDefaultRenderBuffer(Scaleform::Render::D3D1x::HAL *this)
{
  _DWORD *v2; // rax
  int v3; // edx
  Scaleform::Render::DepthStencilBuffer *v4; // rbx
  _DWORD *v5; // rdi
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  ID3D11View *v9; // r9
  int v10; // r14d
  int v11; // r15d
  _DWORD *v12; // rax
  __int64 v13; // r8
  ID3D11View *prt; // [rsp+20h] [rbp-89h] BYREF
  ID3D11View *pdss; // [rsp+28h] [rbp-81h] BYREF
  __int64 v17; // [rsp+30h] [rbp-79h] BYREF
  __int64 v18; // [rsp+38h] [rbp-71h] BYREF
  Scaleform::Render::DepthStencilBuffer *v19; // [rsp+40h] [rbp-69h]
  _DWORD *v20; // [rsp+48h] [rbp-61h]
  _DWORD *v21; // [rsp+50h] [rbp-59h]
  __int64 v22; // [rsp+58h] [rbp-51h]
  int v23[12]; // [rsp+60h] [rbp-49h] BYREF
  int v24[24]; // [rsp+90h] [rbp-19h] BYREF
  int v25; // [rsp+118h] [rbp+6Fh] BYREF
  int v26; // [rsp+120h] [rbp+77h] BYREF
  int v27; // [rsp+128h] [rbp+7Fh] BYREF
  int v28; // [rsp+12Ch] [rbp+83h]

  v22 = -2i64;
  if ( ((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[20].__vecDelDtor)(this) )
  {
    v2 = (_DWORD *)((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->vfptr[20].__vecDelDtor)(this);
    v3 = v2[15] - v2[13];
    v27 = v2[14] - v2[12];
    v28 = v3;
    return ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, Scaleform::Render::D3D1x::TextureManager *, __int64, int *))this->pRenderBufferManager.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[1].__vecDelDtor)(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             1i64,
             &v27);
  }
  v4 = 0i64;
  prt = 0i64;
  pdss = 0i64;
  v18 = 0i64;
  v17 = 0i64;
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, ID3D11View **, ID3D11View **))this->pDeviceContext->vfptr[29].Release)(
    this->pDeviceContext,
    1i64,
    &prt,
    &pdss);
  ((void (__fastcall *)(ID3D11View *, __int64 *))prt->vfptr[2].AddRef)(prt, &v18);
  (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v18 + 80i64))(v18, v23);
  v27 = v23[0];
  v28 = v23[1];
  v25 = 72;
  v5 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 64i64, &v25);
  v20 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
    v5[2] = 1;
    *(_QWORD *)v5 = &Scaleform::RefCountVImpl::`vftable;
    *(_QWORD *)v5 = &Scaleform::Render::RenderBuffer::`vftable;
    v5[4] = 1;
    *((_QWORD *)v5 + 3) = 0i64;
    *((_QWORD *)v5 + 4) = 0i64;
    v6 = v28;
    v5[10] = v27;
    v5[11] = v6;
    *(_QWORD *)v5 = &Scaleform::Render::RenderTarget::`vftable;
    v7 = v28;
    v8 = v27;
    *((_QWORD *)v5 + 6) = 0i64;
    v5[14] = v8;
    v5[15] = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v21 = v5;
  v19 = 0i64;
  v9 = pdss;
  if ( pdss )
  {
    ((void (__fastcall *)(ID3D11View *, __int64 *))prt->vfptr[2].AddRef)(prt, &v17);
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v17 + 80i64))(v17, v24);
    v10 = v24[0];
    v11 = v24[1];
    v26 = 72;
    v12 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 48i64, &v26);
    v20 = v12;
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
    v19 = v4;
    v9 = pdss;
  }
  Scaleform::Render::D3D1x::RenderTargetData::UpdateData((Scaleform::Render::RenderBuffer *)v5, prt, v4, v9);
  LOBYTE(v13) = 1;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::D3D1x::HAL *, _DWORD *, __int64))this->vfptr[23].__vecDelDtor)(
         this,
         v5,
         v13) )
  {
    if ( v4 )
      ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v4->vfptr[2].__vecDelDtor)(v4);
    if ( v5 )
      (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
    if ( v17 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
    if ( v18 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16i64))(v18);
    if ( pdss )
      pdss->vfptr->Release(pdss);
    if ( prt )
      prt->vfptr->Release(prt);
    return ((__int64 (__fastcall *)(Scaleform::Render::RenderBufferManager *, Scaleform::Render::D3D1x::TextureManager *, __int64, int *))this->pRenderBufferManager.pObject->Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::Scaleform::Render::HAL::vfptr[1].__vecDelDtor)(
             this->pRenderBufferManager.pObject,
             this->pTextureManager.pObject,
             1i64,
             &v27);
  }
  if ( v4 )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))v4->vfptr[2].__vecDelDtor)(v4);
  if ( v5 )
    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 16i64))(v5);
  if ( v17 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
  if ( v18 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16i64))(v18);
  if ( pdss )
    pdss->vfptr->Release(pdss);
  if ( prt )
    prt->vfptr->Release(prt);
  return 0;
}

// File Line: 962
// RVA: 0xA06000
void __fastcall Scaleform::Render::D3D1x::HAL::setBatchUnitSquareVertexStream(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pObject; // rax
  ID3D11DeviceContext *pDeviceContext; // rcx
  ID3D11Buffer *v3; // [rsp+40h] [rbp+8h] BYREF

  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  pDeviceContext = this->pDeviceContext;
  v3 = pObject;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **, const unsigned int *, const unsigned int *))pDeviceContext->vfptr[6].QueryInterface)(
    pDeviceContext,
    0i64,
    1i64,
    &v3,
    &stride,
    &FLOAT_0_0);
}

// File Line: 970
// RVA: 0xA05360
void __fastcall Scaleform::Render::D3D1x::HAL::drawPrimitive(
        Scaleform::Render::D3D1x::HAL *this,
        __int64 indexCount,
        unsigned int meshCount)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, _QWORD))this->pDeviceContext->vfptr[4].AddRef)(
    this->pDeviceContext,
    indexCount,
    0i64);
}

// File Line: 982
// RVA: 0xA04F80
void __fastcall Scaleform::Render::D3D1x::HAL::drawIndexedPrimitive(
        Scaleform::Render::D3D1x::HAL *this,
        __int64 indexCount,
        unsigned int vertexCount,
        unsigned int meshCount,
        unsigned __int64 indexPtr,
        unsigned __int64 vertexOffset)
{
  ((void (__fastcall *)(ID3D11DeviceContext *, __int64, _QWORD, _QWORD))this->pDeviceContext->vfptr[4].QueryInterface)(
    this->pDeviceContext,
    indexCount,
    (unsigned int)indexPtr,
    (unsigned int)vertexOffset);
}

// File Line: 994
// RVA: 0xA04F50
void __fastcall Scaleform::Render::D3D1x::HAL::drawIndexedInstanced(
        Scaleform::Render::D3D1x::HAL *this,
        __int64 indexCount,
        unsigned int vertexCount,
        unsigned int meshCount,
        unsigned __int64 indexPtr,
        unsigned __int64 vertexOffset)
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
char __fastcall Scaleform::Render::D3D1x::HAL::shouldRenderFilters(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::FilterPrimitive *prim)
{
  Scaleform::Render::FilterSet *pObject; // rsi
  unsigned int v5; // ebx
  unsigned int Size; // edi

  if ( this->SManager.Scaleform::Render::ShaderHAL<Scaleform::Render::D3D1x::ShaderManager,Scaleform::Render::D3D1x::ShaderInterface>::vfptr->GetShaderVersion(&this->SManager) >= ShaderVersion_Count )
    return 1;
  pObject = prim->pFilters.pObject;
  v5 = 0;
  Size = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)pObject);
  if ( !Size )
    return 0;
  while ( Scaleform::Render::FilterSet::GetFilter(pObject, v5)->Type != Filter_ColorMatrix )
  {
    if ( ++v5 >= Size )
      return 0;
  }
  return 1;
}

// File Line: 1030
// RVA: 0x9FED10
// attributes: thunk
Scaleform::Render::RenderEvent *__fastcall Scaleform::Render::D3D1x::HAL::GetEvent(
        Scaleform::Render::D3D1x::HAL *this,
        Scaleform::Render::EventType eventType)
{
  return Scaleform::Render::HAL::GetEvent(this, eventType);
}

// File Line: 1041
// RVA: 0xA05380
void __fastcall Scaleform::Render::D3D1x::HAL::drawScreenQuad(Scaleform::Render::D3D1x::HAL *this)
{
  ID3D11Buffer *pObject; // rax
  ID3D11DeviceContext *pDeviceContext; // rcx
  ID3D11Buffer *v4; // [rsp+40h] [rbp+8h] BYREF

  pObject = this->Cache.pMaskEraseBatchVertexBuffer.pObject;
  pDeviceContext = this->pDeviceContext;
  v4 = pObject;
  ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, ID3D11Buffer **, const unsigned int *, const unsigned int *))pDeviceContext->vfptr[6].QueryInterface)(
    pDeviceContext,
    0i64,
    1i64,
    &v4,
    &stride,
    &FLOAT_0_0);
  ((void (__fastcall *)(Scaleform::Render::D3D1x::HAL *, __int64, __int64))this->vfptr[95].__vecDelDtor)(
    this,
    6i64,
    1i64);
}

