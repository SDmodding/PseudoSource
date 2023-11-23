// File Line: 31
// RVA: 0x9FB4E0
void __fastcall Scaleform::Render::D3D1x::FenceWrapper::FenceWrapper(
        Scaleform::Render::D3D1x::FenceWrapper *this,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pdeviceCtx)
{
  ID3D11Query *pObject; // rcx
  ID3D11DeviceContext *v7; // rcx
  __int64 v8; // [rsp+58h] [rbp+10h] BYREF

  this->pPrev = 0i64;
  this->pNext = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FenceWrapper,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FenceWrapper::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::FenceWrapper::`vftable;
  this->pDeviceContext.pObject = 0i64;
  this->pQuery.pObject = 0i64;
  pObject = this->pQuery.pObject;
  if ( pObject )
    pObject->vfptr->Release(pObject);
  this->pQuery.pObject = 0i64;
  v8 = 0i64;
  ((void (__fastcall *)(ID3D11Device *, __int64 *, Scaleform::Ptr<ID3D11Query> *))pdevice->vfptr->OMSetRenderTargets)(
    pdevice,
    &v8,
    &this->pQuery);
  if ( pdeviceCtx )
    pdeviceCtx->vfptr->AddRef(pdeviceCtx);
  v7 = this->pDeviceContext.pObject;
  if ( v7 )
    v7->vfptr->Release(v7);
  this->pDeviceContext.pObject = pdeviceCtx;
}

// File Line: 80
// RVA: 0xA033E0
void __fastcall Scaleform::Render::D3D1x::FenceWrapper::WaitFence(Scaleform::Render::D3D1x::FenceWrapper *this)
{
  ID3D11DeviceContext *pObject; // rcx
  __int64 v3; // [rsp+40h] [rbp+8h] BYREF

  while ( ((unsigned int (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *, _QWORD, _QWORD, _DWORD))this->pDeviceContext.pObject->vfptr[9].Release)(
            this->pDeviceContext.pObject,
            this->pQuery.pObject,
            0i64,
            0i64,
            0) )
  {
    pObject = this->pDeviceContext.pObject;
    v3 = 0i64;
    ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, __int64, __int64 *))pObject->vfptr[7].AddRef)(
      pObject,
      0i64,
      1i64,
      &v3);
  }
}

// File Line: 109
// RVA: 0xA02E50
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::Shutdown(Scaleform::Render::D3D1x::FenceWrapperList *this)
{
  ID3D11Device *pObject; // rcx

  pObject = this->pDevice.pObject;
  if ( pObject )
    ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
  this->pDevice.pObject = 0i64;
  Scaleform::Render::FenceWrapperList::Shutdown(this);
}

// File Line: 115
// RVA: 0xA00C60
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(
        Scaleform::Render::D3D1x::FenceWrapperList *this,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pdeviceCtx)
{
  ID3D11Device *pObject; // rcx
  ID3D11DeviceContext *v7; // rcx

  if ( pdevice )
    ((void (__fastcall *)(ID3D11Device *))pdevice->vfptr->AddRef)(pdevice);
  pObject = this->pDevice.pObject;
  if ( pObject )
    ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
  this->pDevice.pObject = pdevice;
  if ( pdeviceCtx )
    pdeviceCtx->vfptr->AddRef(pdeviceCtx);
  v7 = this->pDeviceCtx.pObject;
  if ( v7 )
    v7->vfptr->Release(v7);
  this->pDeviceCtx.pObject = pdeviceCtx;
  if ( this->pDevice.pObject && pdeviceCtx )
    this->vfptr->Initialize(this);
  else
    this->vfptr->Shutdown(this);
}

// File Line: 125
// RVA: 0xA034B0
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::allocateWrapper(
        Scaleform::Render::D3D1x::FenceWrapperList *this)
{
  Scaleform::Render::D3D1x::FenceWrapper *v2; // rax

  v2 = (Scaleform::Render::D3D1x::FenceWrapper *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   48i64);
  if ( v2 )
    Scaleform::Render::D3D1x::FenceWrapper::FenceWrapper(v2, this->pDevice.pObject, this->pDeviceCtx.pObject);
}

// File Line: 135
// RVA: 0x9FB6D0
void __fastcall Scaleform::Render::D3D1x::RenderSync::RenderSync(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::Ptr<ID3D11DeviceContext> *p_pDeviceContext; // rcx

  Scaleform::Render::RenderSync::RenderSync(this);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::RenderSync::`vftable;
  this->pNextEndFrameFence.pObject = 0i64;
  this->pDevice.pObject = 0i64;
  this->pDeviceContext.pObject = 0i64;
  this->QueryList.vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::FenceWrapperList::`vftable;
  p_pDeviceContext = &this->pDeviceContext;
  if ( this == (Scaleform::Render::D3D1x::RenderSync *)-200i64 )
    p_pDeviceContext = 0i64;
  this->QueryList.WrapperList.Root.pPrev = (Scaleform::Render::FenceWrapper *)p_pDeviceContext;
  this->QueryList.WrapperList.Root.pNext = (Scaleform::Render::FenceWrapper *)p_pDeviceContext;
  this->QueryList.ReservePoolSize = 4;
  this->QueryList.vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::D3D1x::FenceWrapperList::`vftable;
  this->QueryList.pDevice.pObject = 0i64;
  this->QueryList.pDeviceCtx.pObject = 0i64;
}

// File Line: 138
// RVA: 0xA00D00
char __fastcall Scaleform::Render::D3D1x::RenderSync::SetDevice(
        Scaleform::Render::D3D1x::RenderSync *this,
        ID3D11Device *pdevice,
        ID3D11DeviceContext *pdeviceCtx)
{
  ID3D10DeviceVtbl *vfptr; // rax
  int v7; // ebp
  ID3D11Device *pObject; // rcx
  ID3D11DeviceContext *v9; // rcx
  ID3D11Device *v11; // rcx
  ID3D11DeviceContext *v12; // rcx
  __int64 v13; // [rsp+48h] [rbp+10h] BYREF
  __int64 v14; // [rsp+58h] [rbp+20h] BYREF

  if ( pdevice && pdeviceCtx )
  {
    v13 = 0i64;
    vfptr = pdevice->vfptr;
    v14 = 0i64;
    v7 = ((__int64 (__fastcall *)(ID3D11Device *, __int64 *, __int64 *))vfptr->OMSetRenderTargets)(pdevice, &v13, &v14);
    if ( v14 )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
      ((void (__fastcall *)(ID3D11Device *))pdevice->vfptr->AddRef)(pdevice);
      pObject = this->pDevice.pObject;
      if ( pObject )
        ((void (__fastcall *)(ID3D11Device *))pObject->vfptr->Release)(pObject);
      this->pDevice.pObject = pdevice;
      pdeviceCtx->vfptr->AddRef(pdeviceCtx);
      v9 = this->pDeviceContext.pObject;
      if ( v9 )
        v9->vfptr->Release(v9);
      this->pDeviceContext.pObject = pdeviceCtx;
    }
    if ( v7 < 0 )
      return 0;
  }
  else
  {
    v11 = this->pDevice.pObject;
    if ( v11 )
      ((void (__fastcall *)(ID3D11Device *))v11->vfptr->Release)(v11);
    this->pDevice.pObject = 0i64;
    v12 = this->pDeviceContext.pObject;
    if ( v12 )
      v12->vfptr->Release(v12);
    this->pDeviceContext.pObject = 0i64;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames(this);
  }
  Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(&this->QueryList, pdevice, pdeviceCtx);
  return 1;
}

// File Line: 171
// RVA: 0x9FCC60
void __fastcall Scaleform::Render::D3D1x::RenderSync::BeginFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::GFx::Resource *v2; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::D3D1x::FenceWrapper *v4; // rdi

  if ( this->pDevice.pObject )
  {
    v2 = Scaleform::Render::FenceWrapperList::Alloc(&this->QueryList);
    pObject = (Scaleform::Render::RenderBuffer *)this->pNextEndFrameFence.pObject;
    v4 = (Scaleform::Render::D3D1x::FenceWrapper *)v2;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->pNextEndFrameFence.pObject = v4;
    Scaleform::Render::RenderSync::BeginFrame(this);
  }
}

// File Line: 183
// RVA: 0x9FEBD0
char __fastcall Scaleform::Render::D3D1x::RenderSync::EndFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  char result; // al
  Scaleform::Render::D3D1x::FenceWrapper *pObject; // rdx
  Scaleform::Render::RenderBuffer *v4; // rcx

  if ( this->pDevice.pObject && this->pDeviceContext.pObject )
  {
    result = Scaleform::Render::RenderSync::EndFrame(this);
    if ( !result )
      return result;
    pObject = this->pNextEndFrameFence.pObject;
    if ( pObject )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *))pObject->pDeviceContext.pObject->vfptr[9].AddRef)(
        pObject->pDeviceContext.pObject,
        pObject->pQuery.pObject);
    v4 = (Scaleform::Render::RenderBuffer *)this->pNextEndFrameFence.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->pNextEndFrameFence.pObject = 0i64;
  }
  return 1;
}

// File Line: 208
// RVA: 0xA01470
Scaleform::Render::D3D1x::FenceWrapper *__fastcall Scaleform::Render::D3D1x::RenderSync::SetFence(
        Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::GFx::Resource *pObject; // rcx

  pObject = (Scaleform::GFx::Resource *)this->pNextEndFrameFence.pObject;
  if ( !pObject )
    return 0i64;
  Scaleform::Render::RenderBuffer::AddRef(pObject);
  return this->pNextEndFrameFence.pObject;
}

// File Line: 215
// RVA: 0x9FF470
bool __fastcall Scaleform::Render::D3D1x::RenderSync::IsPending(
        Scaleform::Render::D3D1x::RenderSync *this,
        Scaleform::Render::FenceType waitType,
        Scaleform::Render::D3D1x::FenceWrapper *handle,
        Scaleform::Render::FenceFrame *parent)
{
  if ( !handle
    || (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
  {
    return 0;
  }
  if ( handle == this->pNextEndFrameFence.pObject )
    return 1;
  return ((unsigned int (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *, _QWORD, _QWORD, int))handle->pDeviceContext.pObject->vfptr[9].Release)(
           handle->pDeviceContext.pObject,
           handle->pQuery.pObject,
           0i64,
           0i64,
           1) != 0;
}

// File Line: 234
// RVA: 0xA03460
void __fastcall Scaleform::Render::D3D1x::RenderSync::WaitFence(
        Scaleform::Render::D3D1x::RenderSync *this,
        __int64 waitType,
        Scaleform::Render::D3D1x::FenceWrapper *handle,
        Scaleform::Render::FenceFrame *parent)
{
  if ( handle )
  {
    if ( handle == this->pNextEndFrameFence.pObject )
    {
      ((void (__fastcall *)(Scaleform::Render::D3D1x::RenderSync *, __int64, Scaleform::Render::D3D1x::FenceWrapper *, Scaleform::Render::FenceFrame *))this->vfptr[2].__vecDelDtor)(
        this,
        waitType,
        handle,
        parent);
      ((void (__fastcall *)(Scaleform::Render::D3D1x::RenderSync *))this->vfptr[1].__vecDelDtor)(this);
    }
    Scaleform::Render::D3D1x::FenceWrapper::WaitFence(handle);
  }
}

// File Line: 253
// RVA: 0xA00670
void __fastcall Scaleform::Render::D3D1x::RenderSync::ReleaseFence(
        Scaleform::Render::D3D1x::RenderSync *this,
        unsigned __int64 handle)
{
  if ( handle )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)handle);
    if ( *(_DWORD *)(handle + 8) == 1 )
    {
      *(_QWORD *)(handle + 16) = this->QueryList.WrapperList.Root.pPrev;
      *(_QWORD *)(handle + 24) = &this->pDeviceContext;
      this->QueryList.WrapperList.Root.pPrev->pNext = (Scaleform::Render::FenceWrapper *)handle;
      this->QueryList.WrapperList.Root.pPrev = (Scaleform::Render::FenceWrapper *)handle;
    }
  }
}

