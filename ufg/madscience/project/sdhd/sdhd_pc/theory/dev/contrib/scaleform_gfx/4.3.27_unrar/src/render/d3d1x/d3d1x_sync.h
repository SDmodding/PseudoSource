// File Line: 31
// RVA: 0x9FB4E0
void __fastcall Scaleform::Render::D3D1x::FenceWrapper::FenceWrapper(Scaleform::Render::D3D1x::FenceWrapper *this, ID3D11Device *pdevice, ID3D11DeviceContext *pdeviceCtx)
{
  ID3D11DeviceContext *v3; // rdi
  ID3D11Device *v4; // r14
  Scaleform::Render::D3D1x::FenceWrapper *v5; // rbx
  ID3D11Query *v6; // rcx
  ID3D11DeviceContext *v7; // rcx
  __int64 v8; // [rsp+58h] [rbp+10h]

  v3 = pdeviceCtx;
  v4 = pdevice;
  v5 = this;
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
  v6 = this->pQuery.pObject;
  if ( v6 )
    ((void (__cdecl *)(ID3D11Query *))v6->vfptr->Release)(v6);
  v5->pQuery.pObject = 0i64;
  v8 = 0i64;
  LODWORD(v8) = 0;
  ((void (__fastcall *)(ID3D11Device *, __int64 *, Scaleform::Ptr<ID3D11Query> *))v4->vfptr->OMSetRenderTargets)(
    v4,
    &v8,
    &v5->pQuery);
  if ( v3 )
    v3->vfptr->AddRef((IUnknown *)&v3->vfptr);
  v7 = v5->pDeviceContext.pObject;
  if ( v7 )
    ((void (__cdecl *)(ID3D11DeviceContext *))v7->vfptr->Release)(v7);
  v5->pDeviceContext.pObject = v3;
}

// File Line: 80
// RVA: 0xA033E0
void __fastcall Scaleform::Render::D3D1x::FenceWrapper::WaitFence(Scaleform::Render::D3D1x::FenceWrapper *this)
{
  Scaleform::Render::D3D1x::FenceWrapper *v1; // rbx
  int v2; // ST20_4
  ID3D11DeviceContext *v3; // rcx
  _QWORD v4[3]; // [rsp+20h] [rbp-18h]
  __int64 v5; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = 0;
  if ( ((unsigned int (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *, _QWORD, _QWORD, int))this->pDeviceContext.pObject->vfptr[9].Release)(
         this->pDeviceContext.pObject,
         this->pQuery.pObject,
         0i64,
         0i64,
         v2) )
  {
    do
    {
      v3 = v1->pDeviceContext.pObject;
      v5 = 0i64;
      ((void (__fastcall *)(ID3D11DeviceContext *, _QWORD, signed __int64, __int64 *))v3->vfptr[7].AddRef)(
        v3,
        0i64,
        1i64,
        &v5);
      LODWORD(v4[0]) = 0;
    }
    while ( ((unsigned int (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *, _QWORD, _QWORD, _QWORD))v1->pDeviceContext.pObject->vfptr[9].Release)(
              v1->pDeviceContext.pObject,
              v1->pQuery.pObject,
              0i64,
              0i64,
              v4[0]) );
  }
}

// File Line: 109
// RVA: 0xA02E50
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::Shutdown(Scaleform::Render::D3D1x::FenceWrapperList *this)
{
  Scaleform::Render::D3D1x::FenceWrapperList *v1; // rbx
  ID3D11Device *v2; // rcx

  v1 = this;
  v2 = this->pDevice.pObject;
  if ( v2 )
    ((void (*)(void))v2->vfptr->Release)();
  v1->pDevice.pObject = 0i64;
  Scaleform::Render::FenceWrapperList::Shutdown((Scaleform::Render::FenceWrapperList *)&v1->vfptr);
}

// File Line: 115
// RVA: 0xA00C60
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(Scaleform::Render::D3D1x::FenceWrapperList *this, ID3D11Device *pdevice, ID3D11DeviceContext *pdeviceCtx)
{
  ID3D11DeviceContext *v3; // rdi
  ID3D11Device *v4; // rsi
  Scaleform::Render::D3D1x::FenceWrapperList *v5; // rbx
  ID3D11Device *v6; // rcx
  ID3D11DeviceContext *v7; // rcx

  v3 = pdeviceCtx;
  v4 = pdevice;
  v5 = this;
  if ( pdevice )
    ((void (__fastcall *)(ID3D11Device *))pdevice->vfptr->AddRef)(pdevice);
  v6 = v5->pDevice.pObject;
  if ( v6 )
    ((void (*)(void))v6->vfptr->Release)();
  v5->pDevice.pObject = v4;
  if ( v3 )
    v3->vfptr->AddRef((IUnknown *)&v3->vfptr);
  v7 = v5->pDeviceCtx.pObject;
  if ( v7 )
    ((void (*)(void))v7->vfptr->Release)();
  v5->pDeviceCtx.pObject = v3;
  if ( v5->pDevice.pObject && v3 )
    v5->vfptr->Initialize((Scaleform::Render::FenceWrapperList *)&v5->vfptr);
  else
    v5->vfptr->Shutdown((Scaleform::Render::FenceWrapperList *)&v5->vfptr);
}

// File Line: 125
// RVA: 0xA034B0
void __fastcall Scaleform::Render::D3D1x::FenceWrapperList::allocateWrapper(Scaleform::Render::D3D1x::FenceWrapperList *this)
{
  Scaleform::Render::D3D1x::FenceWrapperList *v1; // rbx
  Scaleform::Render::D3D1x::FenceWrapper *v2; // rax

  v1 = this;
  v2 = (Scaleform::Render::D3D1x::FenceWrapper *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   48i64);
  if ( v2 )
    Scaleform::Render::D3D1x::FenceWrapper::FenceWrapper(v2, v1->pDevice.pObject, v1->pDeviceCtx.pObject);
}

// File Line: 135
// RVA: 0x9FB6D0
void __fastcall Scaleform::Render::D3D1x::RenderSync::RenderSync(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::Render::D3D1x::RenderSync *v1; // rbx
  signed __int64 v2; // rcx

  v1 = this;
  Scaleform::Render::RenderSync::RenderSync((Scaleform::Render::RenderSync *)&this->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::D3D1x::RenderSync::`vftable;
  v1->pNextEndFrameFence.pObject = 0i64;
  v1->pDevice.pObject = 0i64;
  v1->pDeviceContext.pObject = 0i64;
  v1->QueryList.vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::FenceWrapperList::`vftable;
  v2 = (signed __int64)&v1->pDeviceContext;
  if ( v1 == (Scaleform::Render::D3D1x::RenderSync *)-200i64 )
    v2 = 0i64;
  v1->QueryList.WrapperList.Root.pPrev = (Scaleform::Render::FenceWrapper *)v2;
  v1->QueryList.WrapperList.Root.pNext = (Scaleform::Render::FenceWrapper *)v2;
  v1->QueryList.ReservePoolSize = 4;
  v1->QueryList.vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::D3D1x::FenceWrapperList::`vftable;
  v1->QueryList.pDevice.pObject = 0i64;
  v1->QueryList.pDeviceCtx.pObject = 0i64;
}

// File Line: 138
// RVA: 0xA00D00
char __fastcall Scaleform::Render::D3D1x::RenderSync::SetDevice(Scaleform::Render::D3D1x::RenderSync *this, ID3D11Device *pdevice, ID3D11DeviceContext *pdeviceCtx)
{
  ID3D11DeviceContext *v3; // rdi
  ID3D11Device *v4; // rsi
  Scaleform::Render::D3D1x::RenderSync *v5; // rbx
  ID3D10DeviceVtbl *v6; // rax
  int v7; // ebp
  ID3D11Device *v8; // rcx
  ID3D11DeviceContext *v9; // rcx
  ID3D11Device *v11; // rcx
  ID3D11DeviceContext *v12; // rcx
  __int64 v13; // [rsp+48h] [rbp+10h]
  __int64 v14; // [rsp+58h] [rbp+20h]

  v3 = pdeviceCtx;
  v4 = pdevice;
  v5 = this;
  if ( pdevice && pdeviceCtx )
  {
    v13 = 0i64;
    v6 = pdevice->vfptr;
    LODWORD(v13) = 0;
    v14 = 0i64;
    v7 = ((__int64 (__fastcall *)(ID3D11Device *, __int64 *, __int64 *))v6->OMSetRenderTargets)(pdevice, &v13, &v14);
    if ( v14 )
    {
      (*(void (**)(void))(*(_QWORD *)v14 + 16i64))();
      ((void (__fastcall *)(ID3D11Device *))v4->vfptr->AddRef)(v4);
      v8 = v5->pDevice.pObject;
      if ( v8 )
        ((void (*)(void))v8->vfptr->Release)();
      v5->pDevice.pObject = v4;
      v3->vfptr->AddRef((IUnknown *)&v3->vfptr);
      v9 = v5->pDeviceContext.pObject;
      if ( v9 )
        ((void (*)(void))v9->vfptr->Release)();
      v5->pDeviceContext.pObject = v3;
    }
    if ( v7 < 0 )
      return 0;
  }
  else
  {
    v11 = this->pDevice.pObject;
    if ( v11 )
      ((void (*)(void))v11->vfptr->Release)();
    v5->pDevice.pObject = 0i64;
    v12 = v5->pDeviceContext.pObject;
    if ( v12 )
      ((void (*)(void))v12->vfptr->Release)();
    v5->pDeviceContext.pObject = 0i64;
    Scaleform::Render::RenderSync::ReleaseOutstandingFrames((Scaleform::Render::RenderSync *)&v5->vfptr);
  }
  Scaleform::Render::D3D1x::FenceWrapperList::SetDevice(&v5->QueryList, v4, v3);
  return 1;
}

// File Line: 171
// RVA: 0x9FCC60
void __fastcall Scaleform::Render::D3D1x::RenderSync::BeginFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::Render::D3D1x::RenderSync *v1; // rbx
  Scaleform::GFx::Resource *v2; // rax
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::Resource *v4; // rdi

  v1 = this;
  if ( this->pDevice.pObject )
  {
    v2 = Scaleform::Render::FenceWrapperList::Alloc((Scaleform::Render::FenceWrapperList *)&this->QueryList.vfptr);
    v3 = (Scaleform::Render::RenderBuffer *)v1->pNextEndFrameFence.pObject;
    v4 = v2;
    if ( v3 )
      Scaleform::RefCountImpl::Release(v3);
    v1->pNextEndFrameFence.pObject = (Scaleform::Render::D3D1x::FenceWrapper *)v4;
    Scaleform::Render::RenderSync::BeginFrame((Scaleform::Render::RenderSync *)&v1->vfptr);
  }
}

// File Line: 183
// RVA: 0x9FEBD0
char __fastcall Scaleform::Render::D3D1x::RenderSync::EndFrame(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::Render::D3D1x::RenderSync *v1; // rbx
  char result; // al
  Scaleform::Render::D3D1x::FenceWrapper *v3; // rdx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v1 = this;
  if ( this->pDevice.pObject && this->pDeviceContext.pObject )
  {
    result = Scaleform::Render::RenderSync::EndFrame((Scaleform::Render::RenderSync *)&this->vfptr);
    if ( !result )
      return result;
    v3 = v1->pNextEndFrameFence.pObject;
    if ( v3 )
      ((void (__fastcall *)(ID3D11DeviceContext *, ID3D11Query *))v3->pDeviceContext.pObject->vfptr[9].AddRef)(
        v3->pDeviceContext.pObject,
        v3->pQuery.pObject);
    v4 = (Scaleform::Render::RenderBuffer *)v1->pNextEndFrameFence.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    v1->pNextEndFrameFence.pObject = 0i64;
  }
  return 1;
}

// File Line: 208
// RVA: 0xA01470
Scaleform::Render::D3D1x::FenceWrapper *__fastcall Scaleform::Render::D3D1x::RenderSync::SetFence(Scaleform::Render::D3D1x::RenderSync *this)
{
  Scaleform::Render::D3D1x::RenderSync *v1; // rbx
  Scaleform::GFx::Resource *v2; // rcx

  v1 = this;
  v2 = (Scaleform::GFx::Resource *)this->pNextEndFrameFence.pObject;
  if ( !v2 )
    return 0i64;
  Scaleform::Render::RenderBuffer::AddRef(v2);
  return v1->pNextEndFrameFence.pObject;
}

// File Line: 215
// RVA: 0x9FF470
bool __fastcall Scaleform::Render::D3D1x::RenderSync::IsPending(Scaleform::Render::D3D1x::RenderSync *this, Scaleform::Render::FenceType waitType, unsigned __int64 handle, Scaleform::Render::FenceFrame *parent)
{
  signed int v5; // ST20_4

  if ( !handle
    || (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
  {
    return 0;
  }
  if ( (Scaleform::Render::D3D1x::FenceWrapper *)handle == this->pNextEndFrameFence.pObject )
    return 1;
  v5 = 1;
  return (*(unsigned int (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, signed int))(**(_QWORD **)(handle + 32) + 232i64))(
           *(_QWORD *)(handle + 32),
           *(_QWORD *)(handle + 40),
           0i64,
           0i64,
           v5) != 0;
}

// File Line: 234
// RVA: 0xA03460
void __fastcall Scaleform::Render::D3D1x::RenderSync::WaitFence(Scaleform::Render::D3D1x::RenderSync *this, __int64 waitType, unsigned __int64 handle, Scaleform::Render::FenceFrame *parent)
{
  Scaleform::Render::D3D1x::FenceWrapper *v4; // rdi
  Scaleform::Render::D3D1x::RenderSync *v5; // rbx

  if ( handle )
  {
    v4 = (Scaleform::Render::D3D1x::FenceWrapper *)handle;
    v5 = this;
    if ( (Scaleform::Render::D3D1x::FenceWrapper *)handle == this->pNextEndFrameFence.pObject )
    {
      ((void (__fastcall *)(Scaleform::Render::D3D1x::RenderSync *, __int64, unsigned __int64, Scaleform::Render::FenceFrame *))this->vfptr[2].__vecDelDtor)(
        this,
        waitType,
        handle,
        parent);
      ((void (__fastcall *)(Scaleform::Render::D3D1x::RenderSync *))v5->vfptr[1].__vecDelDtor)(v5);
    }
    Scaleform::Render::D3D1x::FenceWrapper::WaitFence(v4);
  }
}

// File Line: 253
// RVA: 0xA00670
void __fastcall Scaleform::Render::D3D1x::RenderSync::ReleaseFence(Scaleform::Render::D3D1x::RenderSync *this, unsigned __int64 handle)
{
  Scaleform::Render::D3D1x::RenderSync *v2; // rdi
  unsigned __int64 v3; // rbx

  if ( handle )
  {
    v2 = this;
    v3 = handle;
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)handle);
    if ( *(_DWORD *)(v3 + 8) == 1 )
    {
      *(_QWORD *)(v3 + 16) = v2->QueryList.WrapperList.Root.pPrev;
      *(_QWORD *)(v3 + 24) = (char *)v2 + 184;
      v2->QueryList.WrapperList.Root.pPrev->pNext = (Scaleform::Render::FenceWrapper *)v3;
      v2->QueryList.WrapperList.Root.pPrev = (Scaleform::Render::FenceWrapper *)v3;
    }
  }
}

