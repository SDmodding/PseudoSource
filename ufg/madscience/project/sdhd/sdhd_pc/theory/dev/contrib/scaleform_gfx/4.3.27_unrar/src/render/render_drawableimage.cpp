// File Line: 37
// RVA: 0x93B710
void __fastcall Scaleform::Render::DrawableImageContext::DrawableImageContext(Scaleform::Render::DrawableImageContext *this, Scaleform::Render::ContextImpl::Context *controlContext, Scaleform::Render::ThreadCommandQueue *commandQueue, Scaleform::Render::Interfaces *i)
{
  Scaleform::Render::Interfaces *v4; // rbx
  Scaleform::Render::DrawableImageContext *v5; // rdi
  Scaleform::Render::DICommandQueue *v6; // rsi
  Scaleform::ArrayLH<Scaleform::Render::TreeRoot *,2,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::Render::ContextImpl::Context *v9; // rax
  Scaleform::Render::DICommandQueue *v10; // rax
  Scaleform::Render::DICommandQueue *v11; // rax
  Scaleform::Render::DICommandQueue *v12; // rcx
  Scaleform::Render::ContextImpl::Context *v13; // rcx
  char *v14; // [rsp+58h] [rbp+10h]
  void *v15; // [rsp+60h] [rbp+18h]

  v4 = i;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  v6 = 0i64;
  this->pOwnedContext = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>};
  this->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::Render::ContextImpl::ContextCaptureNotify};
  this->RContext = 0i64;
  this->pControlContext = controlContext;
  this->pRTCommandQueue = commandQueue;
  Scaleform::Lock::Lock(&this->TreeRootKillListLock, 0);
  v7 = &v5->TreeRootKillList;
  v14 = (char *)v7;
  v15 = &v5->TreeRootKillList;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  v5->Queue.pObject = 0i64;
  v5->IDefaults.pTextureManager = v4->pTextureManager;
  v5->IDefaults.pHAL = v4->pHAL;
  v5->IDefaults.pRenderer2D = v4->pRenderer2D;
  v5->IDefaults.RenderThreadID = v4->RenderThreadID;
  v14 = v5->RContextBacking;
  if ( v5 == (Scaleform::Render::DrawableImageContext *)-56i64 )
  {
    v9 = 0i64;
  }
  else
  {
    v8 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v5);
    Scaleform::Render::ContextImpl::Context::Context((Scaleform::Render::ContextImpl::Context *)v5->RContextBacking, v8);
  }
  v5->RContext = v9;
  LODWORD(v14) = 2;
  v10 = (Scaleform::Render::DICommandQueue *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::DrawableImageContext *, signed __int64, char **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                               Scaleform::Memory::pGlobalHeap,
                                               v5,
                                               240i64,
                                               &v14,
                                               -2i64);
  v15 = v10;
  if ( v10 )
  {
    Scaleform::Render::DICommandQueue::DICommandQueue(v10, v5);
    v6 = v11;
  }
  v12 = v5->Queue.pObject;
  if ( v12 && !_InterlockedDecrement(&v12->RefCount) && v12 )
    v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
  v5->Queue.pObject = v6;
  v13 = v5->pControlContext;
  if ( v13 )
    Scaleform::Render::ContextImpl::Context::AddCaptureNotify(
      v13,
      (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&v5->vfptr);
}

// File Line: 45
// RVA: 0x949E70
void __fastcall Scaleform::Render::DrawableImageContext::~DrawableImageContext(Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::DrawableImageContext *v1; // rbx
  Scaleform::Render::ContextImpl::Context *v2; // rcx
  Scaleform::Render::DICommandQueue *v3; // rcx
  Scaleform::Render::ContextImpl::Context *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>};
  this->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::Render::ContextImpl::ContextCaptureNotify};
  if ( this->RContext )
  {
    Scaleform::Render::DrawableImageContext::processTreeRootKillList(this);
    Scaleform::Render::ContextImpl::Context::~Context(v1->RContext);
    v1->RContext = 0i64;
  }
  v2 = v1->pControlContext;
  if ( v2 )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
      v2,
      (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&v1->vfptr);
  v3 = v1->Queue.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->TreeRootKillList.Data.Data);
  DeleteCriticalSection(&v1->TreeRootKillListLock.cs);
  v1->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  v4 = v1->pOwnedContext;
  if ( v4 )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
      v4,
      (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&v1->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 74
// RVA: 0x99C9C0
void __fastcall Scaleform::Render::DrawableImageContext::OnCapture(Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::DrawableImageContext *v1; // rbx
  Scaleform::Render::ContextImpl::Context *v2; // rcx
  Scaleform::Render::DICommandQueue *v3; // rcx

  v1 = this;
  v2 = (Scaleform::Render::ContextImpl::Context *)this->pNext;
  if ( v2 )
    Scaleform::Render::ContextImpl::Context::Capture(v2);
  v3 = (Scaleform::Render::DICommandQueue *)v1->TreeRootKillList.Data.Size;
  if ( v3 )
    Scaleform::Render::DICommandQueue::OnCapture(v3);
  Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)v1 - 16));
}

// File Line: 83
// RVA: 0x99CB70
void __fastcall Scaleform::Render::DrawableImageContext::OnNextCapture(Scaleform::Render::DrawableImageContext *this, Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::ContextImpl::Context *v2; // rbx
  Scaleform::Render::ContextImpl::RenderNotify *v3; // rsi
  Scaleform::Render::DrawableImageContext *v4; // rdi
  Scaleform::Render::ContextImpl::Context *v5; // rcx
  Scaleform::Render::DICommandQueue *v6; // rbx
  Scaleform::Render::ContextImpl::Snapshot *updateSnapshot; // [rsp+30h] [rbp+8h]

  v2 = (Scaleform::Render::ContextImpl::Context *)this->pNext;
  v3 = notify;
  v4 = this;
  if ( v2 )
  {
    v5 = (Scaleform::Render::ContextImpl::Context *)this->pNext;
    updateSnapshot = 0i64;
    Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(v5, &updateSnapshot, notify, 0);
    if ( updateSnapshot )
      Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(v2, updateSnapshot, v3);
  }
  v6 = (Scaleform::Render::DICommandQueue *)v4->TreeRootKillList.Data.Size;
  if ( v6 )
  {
    _InterlockedExchangeAdd(&v6->RefCount, 1u);
    Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v6);
    Scaleform::Render::DICommandQueue::ExecuteNextCapture(v6, v3);
    if ( !_InterlockedDecrement(&v6->RefCount) )
    {
      if ( v6 )
        v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    }
  }
}

// File Line: 91
// RVA: 0x99CC20
void __fastcall Scaleform::Render::DrawableImageContext::OnShutdown(Scaleform::Render::DrawableImageContext *this, bool waitFlag)
{
  unsigned __int64 v2; // rdi
  bool v3; // si
  Scaleform::Render::DrawableImageContext *v4; // rbx
  unsigned __int64 v5; // rcx
  bool v6; // zf
  Scaleform::Render::ContextImpl::Context *v7; // rcx

  v2 = this->TreeRootKillList.Data.Size;
  v3 = waitFlag;
  v4 = this;
  if ( v2 )
  {
    if ( waitFlag )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 8), 1u);
      _InterlockedExchangeAdd((volatile signed __int32 *)(*(_QWORD *)(v2 + 152) + 8i64), 1u);
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)(v2 + 104) + 8i64))(
        *(_QWORD *)(v2 + 104),
        *(_QWORD *)(v2 + 152));
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(*(Scaleform::Render::DICommandQueue::ExecuteCommand **)(v2 + 152));
    }
    else
    {
      Scaleform::Render::DICommandQueue::DiscardCommands((Scaleform::Render::DICommandQueue *)v2);
    }
    v5 = v4->TreeRootKillList.Data.Size;
    if ( v5 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) && v5 )
      (**(void (__fastcall ***)(unsigned __int64, signed __int64))v5)(v5, 1i64);
    v4->TreeRootKillList.Data.Size = 0i64;
  }
  v6 = v4->pNext == 0i64;
  *(_QWORD *)&v4->RContextBacking[256] = 0i64;
  if ( !v6 )
  {
    Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)v4 - 16));
    v7 = (Scaleform::Render::ContextImpl::Context *)v4->pNext;
    if ( v3 )
    {
      Scaleform::Render::ContextImpl::Context::~Context(v7);
      v4->pNext = 0i64;
    }
    else
    {
      Scaleform::Render::ContextImpl::Context::Shutdown(v7, 0);
    }
  }
}

// File Line: 125
// RVA: 0x974360
void __fastcall Scaleform::Render::DrawableImageContext::ExecuteNextCapture(Scaleform::Render::DrawableImageContext *this, Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::ContextImpl::Context *v2; // rbx
  Scaleform::Render::ContextImpl::RenderNotify *v3; // rdi
  Scaleform::Render::ContextImpl::Context *v4; // rcx
  Scaleform::Render::ContextImpl::Snapshot *updateSnapshot; // [rsp+30h] [rbp+8h]

  v2 = this->RContext;
  v3 = notify;
  if ( v2 )
  {
    v4 = this->RContext;
    updateSnapshot = 0i64;
    Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(v4, &updateSnapshot, notify, 0);
    if ( updateSnapshot )
      Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(v2, updateSnapshot, v3);
  }
}

// File Line: 131
// RVA: 0x9EDCB0
void __fastcall Scaleform::Render::DrawableImageContext::processTreeRootKillList(Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::DrawableImageContext *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rsi
  Scaleform::Render::ContextImpl::Entry *v4; // rcx
  bool v5; // zf

  v1 = this;
  if ( this->RContext )
  {
    v2 = &this->TreeRootKillListLock.cs;
    EnterCriticalSection(&this->TreeRootKillListLock.cs);
    v3 = 0i64;
    if ( v1->TreeRootKillList.Data.Size )
    {
      do
      {
        v4 = (Scaleform::Render::ContextImpl::Entry *)&v1->TreeRootKillList.Data.Data[v3]->0;
        v5 = v4->RefCount-- == 1;
        if ( v5 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
        ++v3;
      }
      while ( v3 < v1->TreeRootKillList.Data.Size );
    }
    if ( v1->TreeRootKillList.Data.Size && v1->TreeRootKillList.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v1->TreeRootKillList.Data.Data )
      {
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v1->TreeRootKillList.Data.Data = 0i64;
      }
      v1->TreeRootKillList.Data.Policy.Capacity = 0i64;
    }
    v1->TreeRootKillList.Data.Size = 0i64;
    LeaveCriticalSection(v2);
  }
}

// File Line: 144
// RVA: 0x954C90
void __fastcall Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(Scaleform::Render::DrawableImageContext *this, Scaleform::Render::TreeRoot *proot)
{
  Scaleform::Render::TreeRoot *v2; // rbp
  Scaleform::Render::DrawableImageContext *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // r8
  _QWORD *v9; // rcx

  v2 = proot;
  v3 = this;
  v4 = &this->TreeRootKillListLock.cs;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  v5 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->TreeRootKillList;
  v6 = v5->Size;
  v7 = v6 + 1;
  if ( v6 + 1 >= v6 )
  {
    if ( v7 <= v5->Policy.Capacity )
      goto LABEL_7;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= v5->Policy.Capacity >> 1 )
      goto LABEL_7;
    v8 = v6 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v5,
    v5,
    v8);
LABEL_7:
  v5->Size = v7;
  v9 = &v5->Data[v7 - 1].pObject;
  if ( v9 )
    *v9 = v2;
  LeaveCriticalSection(v4);
}

// File Line: 169
// RVA: 0x93B5D0
void __fastcall Scaleform::Render::DrawableImage::DrawableImage(Scaleform::Render::DrawableImage *this, bool transparent, Scaleform::Render::ImageBase *originalData, Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DrawableImageContext *v4; // rbp
  Scaleform::Render::ImageBase *v5; // rsi
  Scaleform::Render::DrawableImage *v6; // rdi
  Scaleform::Render::Texture *volatile v7; // rt1
  Scaleform::Render::Texture *volatile v8; // rax
  Scaleform::Render::ImagePlane *v9; // rcx
  Scaleform::Render::Size<unsigned long> *v10; // rbx
  Scaleform::Render::ImageFormat v11; // eax
  Scaleform::Render::ImageData *v12; // [rsp+70h] [rbp+18h]
  char v13; // [rsp+78h] [rbp+20h]

  v4 = dicontext;
  v5 = originalData;
  v6 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  v7 = this->pTexture.Value;
  v8 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  this->DrawableImageState = 0;
  this->Transparent = transparent;
  this->pQueue.pObject = 0i64;
  v12 = &this->MappedData;
  *(_QWORD *)&v12->Format = 0i64;
  *(_DWORD *)&v12->Flags = 0x10000;
  v9 = &this->MappedData.Plane0;
  v12->pPlanes = v9;
  v12->pPalette.pObject = 0i64;
  *(_QWORD *)&v9->Width = 0i64;
  v9->Pitch = 0i64;
  v9->DataSize = 0i64;
  v9->pData = 0i64;
  v6->pCPUModifiedNext.pObject = 0i64;
  v6->pGPUModifiedNext.pObject = 0i64;
  if ( originalData )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))originalData->vfptr[1].__vecDelDtor)(originalData);
  v6->pDelegateImage.pObject = v5;
  if ( v4 )
    _InterlockedExchangeAdd(&v4->RefCount, 1u);
  v6->pContext.pObject = v4;
  v6->pRT.pObject = 0i64;
  v6->pFence.pObject = 0i64;
  v10 = (Scaleform::Render::Size<unsigned long> *)v5->vfptr[5].__vecDelDtor(
                                                    (Scaleform::RefCountImplCore *)&v5->vfptr,
                                                    (unsigned int)&v13);
  v11 = ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))v5->vfptr[4].__vecDelDtor)(v5);
  Scaleform::Render::DrawableImage::initialize(v6, v11, v10, v4);
}

// File Line: 181
// RVA: 0x93B450
void __fastcall Scaleform::Render::DrawableImage::DrawableImage(Scaleform::Render::DrawableImage *this, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> size, bool transparent, __int64 fillColor, Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DrawableImage *v6; // rdi
  Scaleform::Render::Texture *volatile v7; // rt1
  Scaleform::Render::Texture *volatile v8; // rax
  Scaleform::Render::ImageData *v9; // ST28_8
  Scaleform::Render::ImagePlane *v10; // rcx
  unsigned int v11; // ebx
  __int64 v12; // rdx
  __int64 v13; // r8
  Scaleform::Render::DICommand_Clear cmd; // [rsp+30h] [rbp-28h]

  v6 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  v7 = this->pTexture.Value;
  v8 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  this->DrawableImageState = 0;
  this->Transparent = transparent;
  this->pQueue.pObject = 0i64;
  v9 = &this->MappedData;
  *(_QWORD *)&v9->Format = 0i64;
  *(_DWORD *)&v9->Flags = 0x10000;
  v10 = &this->MappedData.Plane0;
  v9->pPlanes = v10;
  v9->pPalette.pObject = 0i64;
  *(_QWORD *)&v10->Width = 0i64;
  v6->MappedData.Plane0.Pitch = 0i64;
  v6->MappedData.Plane0.DataSize = 0i64;
  v6->MappedData.Plane0.pData = 0i64;
  v6->pCPUModifiedNext.pObject = 0i64;
  v6->pGPUModifiedNext.pObject = 0i64;
  v6->pDelegateImage.pObject = 0i64;
  v6->pContext.pObject = 0i64;
  v6->pRT.pObject = 0i64;
  v6->pFence.pObject = 0i64;
  Scaleform::Render::DrawableImage::initialize(v6, format, *(Scaleform::Render::Size<unsigned long> **)&size, dicontext);
  if ( !v6->Transparent )
    *(_BYTE *)(fillColor + 3) = -1;
  v11 = *(_DWORD *)fillColor;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
  cmd.pImage.pObject = v6;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Clear::`vftable;
  cmd.FillColor.Raw = v11;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Clear>(v6, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v12,
      v13);
}

// File Line: 200
// RVA: 0x971E10
void __fastcall Scaleform::Render::DestroyDrawableImageThreadCommand::Execute(Scaleform::Render::DestroyDrawableImageThreadCommand *this)
{
  Scaleform::Render::DrawableImage *v1; // rcx

  v1 = this->pDrawableImage;
  if ( v1 )
    v1->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 1u);
}

// File Line: 208
// RVA: 0x9A76B0
void __fastcall Scaleform::Render::DrawableImage::Release(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rsi
  Scaleform::Render::ImageBase *v2; // rcx
  Scaleform::Render::DrawableImageContext *v3; // rdi
  Scaleform::Render::TextureManager *v4; // rax
  Scaleform::Render::HAL *v5; // rax
  __int64 v6; // rax
  void *v7; // rax
  void *v8; // rdi
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  Scaleform::Render::DrawableImage *v10; // rcx
  __int128 v11; // [rsp+28h] [rbp-40h]
  __int64 v12; // [rsp+38h] [rbp-30h]
  void *v13; // [rsp+40h] [rbp-28h]

  v1 = this;
  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    v2 = this->pDelegateImage.pObject;
    if ( v2 )
      ((void (__cdecl *)(Scaleform::Render::ImageBase *))v2->vfptr[2].__vecDelDtor)(v2);
    v1->pDelegateImage.pObject = 0i64;
    v11 = 0ui64;
    v12 = 0i64;
    v13 = 0i64;
    v3 = v1->pContext.pObject;
    v3->pRTCommandQueue->vfptr->GetRenderInterfaces(v3->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v11);
    v4 = (Scaleform::Render::TextureManager *)v11;
    if ( v3->IDefaults.pTextureManager )
      v4 = v3->IDefaults.pTextureManager;
    *(_QWORD *)&v11 = v4;
    v5 = (Scaleform::Render::HAL *)*((_QWORD *)&v11 + 1);
    if ( v3->IDefaults.pHAL )
      v5 = v3->IDefaults.pHAL;
    *((_QWORD *)&v11 + 1) = v5;
    v6 = v12;
    if ( v3->IDefaults.pRenderer2D )
      v6 = (__int64)v3->IDefaults.pRenderer2D;
    v12 = v6;
    v7 = v13;
    if ( v3->IDefaults.RenderThreadID )
      v7 = v3->IDefaults.RenderThreadID;
    v13 = v7;
    if ( v7 == UFG::qGetCurrentThreadID() || !v13 )
    {
      v9 = v1->vfptr;
      v10 = v1;
      goto LABEL_21;
    }
    v8 = Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 24ui64, 0i64);
    if ( v8 )
    {
      *(_QWORD *)v8 = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)v8 + 2) = 1;
      *(_QWORD *)v8 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v8 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v8 = &Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
      *(_QWORD *)v8 = &Scaleform::Render::ThreadCommand::`vftable;
      *(_QWORD *)v8 = &Scaleform::Render::DestroyDrawableImageThreadCommand::`vftable;
      *((_QWORD *)v8 + 2) = v1;
    }
    else
    {
      v8 = 0i64;
    }
    v1->pContext.pObject->pRTCommandQueue->vfptr->PushThreadCommand(
      v1->pContext.pObject->pRTCommandQueue,
      (Scaleform::Render::ThreadCommand *)v8);
    if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)v8 + 2) )
    {
      v9 = *(Scaleform::RefCountImplCoreVtbl **)v8;
      v10 = (Scaleform::Render::DrawableImage *)v8;
LABEL_21:
      v9->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
      return;
    }
  }
}

// File Line: 237
// RVA: 0x949C10
void __fastcall Scaleform::Render::DrawableImage::~DrawableImage(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rdi
  Scaleform::Render::DrawableImageContext *v2; // rbx
  __int64 v3; // rdx
  __int64 v4; // r9
  Scaleform::Render::TextureManager *v5; // rax
  Scaleform::Render::HAL *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // r9
  Scaleform::Render::Fence *v12; // r8
  Scaleform::Render::Fence *v13; // rcx
  Scaleform::Render::RenderTarget *v14; // rcx
  Scaleform::Render::DrawableImageContext *v15; // rcx
  Scaleform::Render::ImageBase *v16; // rcx
  Scaleform::Render::DrawableImage *v17; // rcx
  Scaleform::Render::DrawableImage *v18; // rcx
  char v19; // al
  volatile signed __int32 *v20; // rdx
  Scaleform::Render::DICommandQueue *v21; // rcx
  signed __int64 v22; // [rsp+20h] [rbp-48h]
  __int128 v23; // [rsp+28h] [rbp-40h]
  __int64 v24; // [rsp+38h] [rbp-30h]
  __int64 v25; // [rsp+40h] [rbp-28h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+78h] [rbp+10h]

  v22 = -2i64;
  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  v23 = 0ui64;
  v24 = 0i64;
  v25 = 0i64;
  v2 = this->pContext.pObject;
  v2->pRTCommandQueue->vfptr->GetRenderInterfaces(v2->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v23);
  v5 = (Scaleform::Render::TextureManager *)v23;
  if ( v2->IDefaults.pTextureManager )
    v5 = v2->IDefaults.pTextureManager;
  *(_QWORD *)&v23 = v5;
  v6 = (Scaleform::Render::HAL *)*((_QWORD *)&v23 + 1);
  if ( v2->IDefaults.pHAL )
    v6 = v2->IDefaults.pHAL;
  *((_QWORD *)&v23 + 1) = v6;
  v7 = v24;
  if ( v2->IDefaults.pRenderer2D )
    v7 = (__int64)v2->IDefaults.pRenderer2D;
  v24 = v7;
  v8 = v25;
  if ( v2->IDefaults.RenderThreadID )
    v8 = (__int64)v2->IDefaults.RenderThreadID;
  v25 = v8;
  if ( v1->DrawableImageState & 3 )
  {
    lpCriticalSection = &v1->pQueue.pObject->QueueLock.cs;
    EnterCriticalSection(lpCriticalSection);
    if ( v1->DrawableImageState & 3 && v1->pTexture.Value )
    {
      ((void (__cdecl *)(Scaleform::Render::Texture *volatile , __int64, __int64, __int64, signed __int64))v1->pTexture.Value->vfptr[14].__vecDelDtor)(
        v1->pTexture.Value,
        v9,
        v10,
        v11,
        -2i64);
      v1->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  v12 = v1->pFence.pObject;
  if ( v12 )
  {
    if ( v12->HasData )
    {
      v12 = (Scaleform::Render::Fence *)v12->Data;
      if ( v12 )
      {
        v4 = *(_QWORD *)&v12->RefCount;
        if ( v4 )
        {
          if ( ((unsigned __int64 (__fastcall *)(Scaleform::Render::FenceImpl *, signed __int64, Scaleform::Render::FenceImpl *))v12->Data->RSContext->FenceFrameAlloc.FirstPage)(
                 v12->Data,
                 1i64,
                 v12[1].Data) )
          {
            v12 = v1->pFence.pObject;
            if ( v12->HasData )
            {
              v12 = (Scaleform::Render::Fence *)v12->Data;
              if ( v12 )
              {
                v4 = *(_QWORD *)&v12->RefCount;
                if ( v4 )
                  ((void (__fastcall *)(Scaleform::Render::FenceImpl *, signed __int64, Scaleform::Render::FenceImpl *))v12->Data->RSContext->FenceFrameAlloc.LastPage)(
                    v12->Data,
                    1i64,
                    v12[1].Data);
              }
            }
          }
        }
      }
    }
  }
  v13 = v1->pFence.pObject;
  if ( v13 )
    Scaleform::Render::Fence::Release(v13);
  v14 = v1->pRT.pObject;
  if ( v14 )
    ((void (__cdecl *)(Scaleform::Render::RenderTarget *, __int64, Scaleform::Render::Fence *, __int64, signed __int64))v14->vfptr[2].__vecDelDtor)(
      v14,
      v3,
      v12,
      v4,
      v22);
  v15 = v1->pContext.pObject;
  if ( v15 && !_InterlockedDecrement(&v15->RefCount) && v15 )
    v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
  v16 = v1->pDelegateImage.pObject;
  if ( v16 )
    ((void (__cdecl *)(Scaleform::Render::ImageBase *, __int64, Scaleform::Render::Fence *, __int64, signed __int64))v16->vfptr[2].__vecDelDtor)(
      v16,
      v3,
      v12,
      v4,
      v22);
  v17 = v1->pGPUModifiedNext.pObject;
  if ( v17 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, Scaleform::Render::Fence *, __int64, signed __int64))v17->vfptr[2].__vecDelDtor)(
      v17,
      v3,
      v12,
      v4,
      v22);
  v18 = v1->pCPUModifiedNext.pObject;
  if ( v18 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, Scaleform::Render::Fence *, __int64, signed __int64))v18->vfptr[2].__vecDelDtor)(
      v18,
      v3,
      v12,
      v4,
      v22);
  v19 = v1->MappedData.Flags;
  if ( v19 & 2 )
  {
    v1->MappedData.Flags = v19 & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->MappedData.pPlanes);
  }
  v1->MappedData.pPlanes = &v1->MappedData.Plane0;
  v20 = &v1->MappedData.pPalette.pObject->RefCount.Value;
  if ( v20 && !_InterlockedDecrement(v20) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, volatile signed __int32 *, Scaleform::Render::Fence *, __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v20,
      v12,
      v4,
      v22);
  v21 = v1->pQueue.pObject;
  if ( v21 && !_InterlockedDecrement(&v21->RefCount) && v21 )
    v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
  Scaleform::Render::Image::~Image((Scaleform::Render::Image *)&v1->vfptr);
}

// File Line: 256
// RVA: 0x999390
char __fastcall Scaleform::Render::DrawableImage::MapImageSource(Scaleform::Render::ImageData *data, Scaleform::Render::ImageBase *i)
{
  Scaleform::Render::DrawableImage *v2; // rdi
  Scaleform::Render::ImageData *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  int v5; // eax
  bool v6; // bl
  Scaleform::Render::ImageData *v7; // rax
  __int64 v9; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  v2 = (Scaleform::Render::DrawableImage *)i;
  v3 = data;
  if ( data && i )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))i->vfptr[3].__vecDelDtor)(i) == 6 )
    {
      if ( v2->DrawableImageState & 3 )
      {
LABEL_15:
        v7 = Scaleform::Render::DrawableImage::getMappedData(v2);
        Scaleform::Render::ImageData::operator=(v3, v7);
        return 1;
      }
      v4 = &v2->pQueue.pObject->QueueLock.cs;
      lpCriticalSection = &v2->pQueue.pObject->QueueLock.cs;
      EnterCriticalSection(v4);
      if ( Scaleform::Render::DrawableImage::MapImageSource(&v2->MappedData, v2->pDelegateImage.pObject) )
      {
        v5 = v2->DrawableImageState | 2;
        goto LABEL_13;
      }
      if ( !v2->pDelegateImage.pObject || Scaleform::Render::DrawableImage::ensureRenderableRT(v2) )
      {
        if ( !v2->pTexture.Value
          || !((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *volatile , Scaleform::Render::ImageData *, _QWORD, _QWORD, signed __int64))v2->pTexture.Value->vfptr[13].__vecDelDtor)(
                v2->pTexture.Value,
                &v2->MappedData,
                0i64,
                0i64,
                -2i64) )
        {
LABEL_14:
          v6 = (v2->DrawableImageState & 3) != 0;
          LeaveCriticalSection(lpCriticalSection);
          if ( v6 )
            goto LABEL_15;
          return 0;
        }
        v5 = v2->DrawableImageState | 3;
LABEL_13:
        v2->DrawableImageState = v5;
        goto LABEL_14;
      }
      LeaveCriticalSection(v4);
    }
    else if ( ((unsigned int (__fastcall *)(Scaleform::Render::DrawableImage *))v2->vfptr[3].__vecDelDtor)(v2) == 2 )
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))v2->vfptr[9].__vecDelDtor)(v2);
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 32i64))(v9) == 2
        || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 32i64))(v9) == 1 )
      {
        Scaleform::Render::ImageData::operator=(v3, (Scaleform::Render::ImageData *)(v9 + 40));
        return 1;
      }
    }
  }
  return 0;
}

// File Line: 292
// RVA: 0x9E8660
void __fastcall Scaleform::Render::DrawableImage::initialize(Scaleform::Render::DrawableImage *this, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *size, Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DrawableImageContext *v4; // rbp
  Scaleform::Render::Size<unsigned long> *v5; // r14
  Scaleform::Render::ImageFormat v6; // er15
  Scaleform::Render::DrawableImage *v7; // rsi
  Scaleform::Render::DrawableImageContext *v8; // rcx
  Scaleform::Render::RenderTarget *v9; // rcx
  Scaleform::Render::DrawableImageContext *v10; // rdi
  Scaleform::Render::TextureManager *v11; // rax
  Scaleform::Render::HAL *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned int v15; // ecx
  Scaleform::Render::DrawableImage *v16; // rcx
  Scaleform::Render::DrawableImage *v17; // rcx
  Scaleform::Render::DICommandQueue *v18; // rcx
  Scaleform::Render::DICommandQueue *v19; // rcx
  __int64 v20; // rdx
  Scaleform::Render::DICommand_CreateTexture cmd; // [rsp+28h] [rbp-50h]
  __int128 tmanager; // [rsp+38h] [rbp-40h]
  __int64 v23; // [rsp+48h] [rbp-30h]
  __int64 v24; // [rsp+50h] [rbp-28h]

  v4 = dicontext;
  v5 = size;
  v6 = format;
  v7 = this;
  if ( dicontext )
    _InterlockedExchangeAdd(&dicontext->RefCount, 1u);
  v8 = this->pContext.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount) && v8 )
    v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
  v7->pContext.pObject = v4;
  v9 = v7->pRT.pObject;
  if ( v9 )
    ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v9->vfptr[2].__vecDelDtor)(v9);
  v7->pRT.pObject = 0i64;
  tmanager = 0ui64;
  v23 = 0i64;
  v24 = 0i64;
  v10 = v7->pContext.pObject;
  v10->pRTCommandQueue->vfptr->GetRenderInterfaces(v10->pRTCommandQueue, (Scaleform::Render::Interfaces *)&tmanager);
  v11 = (Scaleform::Render::TextureManager *)tmanager;
  if ( v10->IDefaults.pTextureManager )
    v11 = v10->IDefaults.pTextureManager;
  *(_QWORD *)&tmanager = v11;
  v12 = (Scaleform::Render::HAL *)*((_QWORD *)&tmanager + 1);
  if ( v10->IDefaults.pHAL )
    v12 = v10->IDefaults.pHAL;
  *((_QWORD *)&tmanager + 1) = v12;
  v13 = v23;
  if ( v10->IDefaults.pRenderer2D )
    v13 = (__int64)v10->IDefaults.pRenderer2D;
  v23 = v13;
  v14 = v24;
  if ( v10->IDefaults.RenderThreadID )
    v14 = (__int64)v10->IDefaults.RenderThreadID;
  v24 = v14;
  v7->Format = v6;
  v15 = v5->Height;
  v7->ISize.Width = v5->Width;
  v7->ISize.Height = v15;
  v16 = v7->pCPUModifiedNext.pObject;
  if ( v16 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v16->vfptr[2].__vecDelDtor)(v16);
  v7->pCPUModifiedNext.pObject = 0i64;
  v17 = v7->pGPUModifiedNext.pObject;
  if ( v17 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v17->vfptr[2].__vecDelDtor)(v17);
  v7->pGPUModifiedNext.pObject = 0i64;
  v18 = v4->Queue.pObject;
  if ( v18 )
    _InterlockedExchangeAdd(&v18->RefCount, 1u);
  v19 = v7->pQueue.pObject;
  if ( v19 && !_InterlockedDecrement(&v19->RefCount) && v19 )
    v19->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v19->vfptr, 1u);
  v7->pQueue.pObject = v4->Queue.pObject;
  if ( !v7->pDelegateImage.pObject )
  {
    if ( (_QWORD)tmanager && (*(unsigned __int8 (__cdecl **)(_QWORD))(*(_QWORD *)tmanager + 56i64))(tmanager) )
    {
      Scaleform::Render::DrawableImage::createTextureFromManager(
        v7,
        *((Scaleform::Render::HAL **)&tmanager + 1),
        (Scaleform::Render::TextureManager *)tmanager);
    }
    else
    {
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[1].__vecDelDtor)(v7);
      cmd.pImage.pObject = v7;
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CreateTexture::`vftable;
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CreateTexture>(v7, &cmd);
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( cmd.pImage.pObject )
        ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
          cmd.pImage.pObject,
          v20);
    }
  }
}

// File Line: 338
// RVA: 0x9CA7B0
void __fastcall Scaleform::Render::DrawableImage::addToCPUModifiedList(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rbx
  Scaleform::Render::DrawableImageContext *v2; // rax
  Scaleform::Render::DICommandQueue *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DICommandQueue *v6; // rdi
  Scaleform::Render::DrawableImage *v7; // rcx
  _RTL_CRITICAL_SECTION *v8; // [rsp+40h] [rbp+8h]

  v1 = this;
  v8 = &this->pQueue.pObject->QueueLock.cs;
  EnterCriticalSection(v8);
  v2 = v1->pContext.pObject;
  if ( v2 && v2->pControlContext )
    v2->pControlContext->DIChangesRequired = 1;
  if ( !(v1->DrawableImageState & 8) )
  {
    v1->DrawableImageState |= 8u;
    v3 = v1->pQueue.pObject;
    v4 = v3->pCPUModifiedImageList.pObject;
    if ( v4 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
    v5 = v1->pCPUModifiedNext.pObject;
    if ( v5 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
    v1->pCPUModifiedNext.pObject = v3->pCPUModifiedImageList.pObject;
    v6 = v1->pQueue.pObject;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v1->vfptr[1].__vecDelDtor)(v1);
    v7 = v6->pCPUModifiedImageList.pObject;
    if ( v7 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v7);
    v6->pCPUModifiedImageList.pObject = v1;
  }
  LeaveCriticalSection(v8);
}

// File Line: 355
// RVA: 0x9CA870
void __fastcall Scaleform::Render::DrawableImage::addToGPUModifiedListRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rbx
  Scaleform::Render::DrawableImageContext *v2; // rax
  Scaleform::Render::DICommandQueue *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DICommandQueue *v6; // rdi
  Scaleform::Render::DrawableImage *v7; // rcx
  _RTL_CRITICAL_SECTION *v8; // [rsp+40h] [rbp+8h]

  v1 = this;
  v8 = &this->pQueue.pObject->QueueLock.cs;
  EnterCriticalSection(v8);
  v2 = v1->pContext.pObject;
  if ( v2 && v2->pControlContext )
    v2->pControlContext->DIChangesRequired = 1;
  if ( !(v1->DrawableImageState & 0x10) )
  {
    v1->DrawableImageState |= 0x10u;
    v3 = v1->pQueue.pObject;
    v4 = v3->pGPUModifiedImageList.pObject;
    if ( v4 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
    v5 = v1->pGPUModifiedNext.pObject;
    if ( v5 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
    v1->pGPUModifiedNext.pObject = v3->pGPUModifiedImageList.pObject;
    v6 = v1->pQueue.pObject;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v1->vfptr[1].__vecDelDtor)(v1);
    v7 = v6->pGPUModifiedImageList.pObject;
    if ( v7 )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v7);
    v6->pGPUModifiedImageList.pObject = v1;
  }
  LeaveCriticalSection(v8);
}

// File Line: 372
// RVA: 0x9DEBE0
bool __fastcall Scaleform::Render::DrawableImage::createTextureFromManager(Scaleform::Render::DrawableImage *this, Scaleform::Render::HAL *phal, Scaleform::Render::TextureManager *tmanager)
{
  unsigned int v3; // eax
  unsigned int v4; // er9
  Scaleform::RefCountImplCoreVtbl *v5; // rbx
  Scaleform::Render::DrawableImage *v6; // rdi
  Scaleform::Render::TextureManager *v7; // rsi
  Scaleform::Render::HAL *v8; // r14
  unsigned int v9; // eax
  Scaleform::Render::DrawableImage *v10; // rcx
  signed int v11; // ST20_4
  __int64 v12; // rax
  __int64 v13; // rax
  Scaleform::Render::RenderTarget *v14; // rcx
  Scaleform::Render::RenderTarget *v15; // rbx
  unsigned int v17; // [rsp+60h] [rbp+8h]
  unsigned int v18; // [rsp+64h] [rbp+Ch]

  v3 = this->ISize.Width;
  v4 = this->ISize.Height;
  v5 = tmanager->vfptr;
  v6 = this;
  v7 = tmanager;
  v8 = phal;
  if ( v3 < 1 )
    v3 = 1;
  if ( v4 < 1 )
    v4 = 1;
  v17 = v3;
  v18 = v4;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))v5[13].__vecDelDtor)(tmanager);
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64))v5[4].__vecDelDtor)(
          v7,
          v9,
          1152i64) )
  {
    v17 = (((((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 8) | ((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1) | ((((((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 8) | ((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 16))
        + 1;
    v18 = (((((((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 4) | ((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 8) | ((((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 4) | ((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1) | ((((((((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 4) | ((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 8) | ((((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 4) | ((((v18 - 1) >> 1) | (v18 - 1)) >> 2) | ((v18 - 1) >> 1) | (v18 - 1)) >> 16))
        + 1;
  }
  v10 = v6;
  if ( v6->pDelegateImage.pObject )
    v10 = (Scaleform::Render::DrawableImage *)v6->pDelegateImage.pObject;
  v11 = 1152;
  v12 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64, unsigned int *, signed int, Scaleform::Render::DrawableImage *, _QWORD))v7->vfptr[1].__vecDelDtor)(
          v7,
          (unsigned int)v6->Format,
          1i64,
          &v17,
          v11,
          v10,
          0i64);
  if ( v12 )
  {
    v6->pTexture.Value = (Scaleform::Render::Texture *volatile )v12;
    v13 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, __int64, signed __int64))v8->vfptr[21].__vecDelDtor)(
            v8,
            v12,
            1i64);
    v14 = v6->pRT.pObject;
    v15 = (Scaleform::Render::RenderTarget *)v13;
    if ( v14 )
      ((void (*)(void))v14->vfptr[2].__vecDelDtor)();
    v6->pRT.pObject = v15;
    LOBYTE(v12) = v15 != 0i64;
  }
  return v12;
}

// File Line: 411
// RVA: 0x98D910
Scaleform::Render::Texture *__fastcall Scaleform::Render::DrawableImage::GetTexture(Scaleform::Render::DrawableImage *this, Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::DrawableImage *v2; // rbx
  Scaleform::Render::ImageBase *v3; // rcx
  Scaleform::Render::TextureManager *v4; // rdi
  Scaleform::Render::ImageBase *v5; // rsi
  Scaleform::Render::DrawableImageContext *v6; // rbx
  Scaleform::Render::HAL *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int128 v11; // [rsp+20h] [rbp-28h]
  __int64 v12; // [rsp+30h] [rbp-18h]
  __int64 v13; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = this->pDelegateImage.pObject;
  v4 = pmanager;
  if ( !v3
    || !((unsigned int (*)(void))v3->vfptr[3].__vecDelDtor)()
    || ((unsigned int (*)(void))v2->pDelegateImage.pObject->vfptr[3].__vecDelDtor)() == 7 )
  {
    return v2->pTexture.Value;
  }
  v5 = v2->pDelegateImage.pObject;
  if ( !v4 )
  {
    v6 = v2->pContext.pObject;
    v11 = 0ui64;
    v12 = 0i64;
    v13 = 0i64;
    v6->pRTCommandQueue->vfptr->GetRenderInterfaces(v6->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v11);
    v4 = (Scaleform::Render::TextureManager *)v11;
    if ( v6->IDefaults.pTextureManager )
      v4 = v6->IDefaults.pTextureManager;
    v7 = (Scaleform::Render::HAL *)*((_QWORD *)&v11 + 1);
    *(_QWORD *)&v11 = v4;
    if ( v6->IDefaults.pHAL )
      v7 = v6->IDefaults.pHAL;
    *((_QWORD *)&v11 + 1) = v7;
    v8 = v12;
    if ( v6->IDefaults.pRenderer2D )
      v8 = (__int64)v6->IDefaults.pRenderer2D;
    v12 = v8;
    v9 = v13;
    if ( v6->IDefaults.RenderThreadID )
      v9 = (__int64)v6->IDefaults.RenderThreadID;
    v13 = v9;
  }
  return (Scaleform::Render::Texture *)v5->vfptr[21].__vecDelDtor(
                                         (Scaleform::RefCountImplCore *)&v5->vfptr,
                                         (unsigned int)v4);
}

// File Line: 443
// RVA: 0x9B9C00
void __fastcall Scaleform::Render::DrawableImage::TextureLost(Scaleform::Render::DrawableImage *this, Scaleform::Render::Image::TextureLossReason reason)
{
  Scaleform::Render::DrawableImage *v2; // rbx
  Scaleform::Render::RenderTarget *v3; // rcx

  if ( reason == 1 )
  {
    v2 = this;
    v3 = this->pRT.pObject;
    if ( v3 )
      ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
    v2->pRT.pObject = 0i64;
  }
}

// File Line: 452
// RVA: 0x9E9790
_BOOL8 __fastcall Scaleform::Render::DrawableImage::mapTextureRT(Scaleform::Render::DrawableImage *this, bool readOnly)
{
  bool v2; // di
  Scaleform::Render::DrawableImage *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  bool v5; // di
  Scaleform::Lock *v7; // [rsp+40h] [rbp+8h]

  v2 = readOnly;
  v3 = this;
  v4 = &this->pQueue.pObject->QueueLock.cs;
  v7 = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(v4);
  if ( v2 && Scaleform::Render::DrawableImage::MapImageSource(&v3->MappedData, v3->pDelegateImage.pObject) )
  {
    v3->DrawableImageState |= 2u;
LABEL_10:
    v4 = &v7->cs;
    v5 = (v3->DrawableImageState & 3) != 0;
    goto LABEL_11;
  }
  if ( !v3->pDelegateImage.pObject || Scaleform::Render::DrawableImage::ensureRenderableRT(v3) )
  {
    if ( v3->pTexture.Value
      && ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *volatile , Scaleform::Render::ImageData *, _QWORD, _QWORD, signed __int64))v3->pTexture.Value->vfptr[13].__vecDelDtor)(
           v3->pTexture.Value,
           &v3->MappedData,
           0i64,
           0i64,
           -2i64) )
    {
      v3->DrawableImageState |= 3u;
    }
    goto LABEL_10;
  }
  v5 = 0;
LABEL_11:
  LeaveCriticalSection(v4);
  return v5;
}

// File Line: 487
// RVA: 0x9E1EA0
char __fastcall Scaleform::Render::DrawableImage::ensureRenderableRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rdi
  Scaleform::Render::DrawableImageContext *v3; // rbx
  Scaleform::Render::TextureManager *v4; // rax
  Scaleform::Render::HAL *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  unsigned int v8; // ecx
  Scaleform::Render::ImageBase *v9; // rcx
  Scaleform::Render::ImageBase *v10; // r14
  __int64 v11; // r15
  __int64 v12; // rbx
  Scaleform::Render::RenderTarget *v13; // rcx
  Scaleform::Render::ImageBase *v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // ecx
  __int64 v17; // rax
  Scaleform::Render::ImageBase *v18; // rcx
  Scaleform::Render::DrawableImageContext *v19; // rbx
  Scaleform::Render::ImageFormat v20; // eax
  char v21; // bl
  __int64 v22; // rcx
  char v23; // bl
  char v24; // si
  Scaleform::Render::RenderTarget *v25; // r8
  int v26; // ecx
  float v27; // xmm1_4
  Scaleform::Render::RenderTarget *v28; // rcx
  int v29; // edx
  int *v30; // rax
  signed int *v31; // rdx
  float v32; // xmm3_4
  __int64 v33; // ST20_8
  Scaleform::RefCountImplCoreVtbl *v34; // rbx
  Scaleform::Render::ImageData *v35; // rax
  __int128 v36; // [rsp+30h] [rbp-69h]
  __int64 v37; // [rsp+40h] [rbp-59h]
  __int64 v38; // [rsp+48h] [rbp-51h]
  __int128 v39; // [rsp+50h] [rbp-49h]
  __m128 v40; // [rsp+60h] [rbp-39h]
  __int64 v41; // [rsp+70h] [rbp-29h]
  float v42; // [rsp+78h] [rbp-21h]
  float v43; // [rsp+7Ch] [rbp-1Dh]
  int v44; // [rsp+80h] [rbp-19h]
  int v45; // [rsp+84h] [rbp-15h]
  int v46; // [rsp+88h] [rbp-11h]
  int v47; // [rsp+8Ch] [rbp-Dh]
  int v48; // [rsp+90h] [rbp-9h]
  int v49; // [rsp+94h] [rbp-5h]
  int v50; // [rsp+98h] [rbp-1h]
  int v51; // [rsp+9Ch] [rbp+3h]
  __int64 v52; // [rsp+A0h] [rbp+7h]
  char v53; // [rsp+A8h] [rbp+Fh]
  int v54; // [rsp+100h] [rbp+67h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+108h] [rbp+6Fh]
  int v56; // [rsp+110h] [rbp+77h]
  int v57; // [rsp+114h] [rbp+7Bh]
  Scaleform::Render::ImageBase *v58; // [rsp+118h] [rbp+7Fh]

  v52 = -2i64;
  v1 = this;
  if ( this->pRT.pObject )
    return 1;
  v36 = 0ui64;
  v37 = 0i64;
  v38 = 0i64;
  v3 = this->pContext.pObject;
  v3->pRTCommandQueue->vfptr->GetRenderInterfaces(v3->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v36);
  v4 = (Scaleform::Render::TextureManager *)v36;
  if ( v3->IDefaults.pTextureManager )
    v4 = v3->IDefaults.pTextureManager;
  *(_QWORD *)&v36 = v4;
  v5 = (Scaleform::Render::HAL *)*((_QWORD *)&v36 + 1);
  if ( v3->IDefaults.pHAL )
    v5 = v3->IDefaults.pHAL;
  *((_QWORD *)&v36 + 1) = v5;
  v6 = v37;
  if ( v3->IDefaults.pRenderer2D )
    v6 = (__int64)v3->IDefaults.pRenderer2D;
  v37 = v6;
  v7 = v38;
  if ( v3->IDefaults.RenderThreadID )
    v7 = (__int64)v3->IDefaults.RenderThreadID;
  v38 = v7;
  v8 = v1->ISize.Height;
  size.Width = v1->ISize.Width;
  size.Height = v8;
  v9 = v1->pDelegateImage.pObject;
  if ( v9 )
    ((void (*)(void))v9->vfptr[1].__vecDelDtor)();
  v10 = v1->pDelegateImage.pObject;
  v58 = v1->pDelegateImage.pObject;
  v11 = 0i64;
  if ( v1->pTexture.Value )
  {
    v12 = (*(__int64 (__fastcall **)(_QWORD, Scaleform::Render::Texture *volatile , _QWORD))(**((_QWORD **)&v36 + 1)
                                                                                           + 168i64))(
            *((_QWORD *)&v36 + 1),
            v1->pTexture.Value,
            0i64);
    v13 = v1->pRT.pObject;
    if ( v13 )
      ((void (*)(void))v13->vfptr[2].__vecDelDtor)();
    v1->pRT.pObject = (Scaleform::Render::RenderTarget *)v12;
    if ( !v12 )
      goto LABEL_23;
  }
  else
  {
    v14 = v1->pDelegateImage.pObject;
    if ( v14 )
    {
      v15 = (unsigned int *)v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)&v53);
      v16 = v15[1];
      size.Width = *v15;
      size.Height = v16;
      v17 = ((__int64 (*)(void))v1->pDelegateImage.pObject->vfptr[9].__vecDelDtor)();
      v11 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v17 + 168i64))(v17, v36);
      v18 = v1->pDelegateImage.pObject;
      if ( v18 )
        ((void (*)(void))v18->vfptr[2].__vecDelDtor)();
      v1->pDelegateImage.pObject = 0i64;
      v19 = v1->pContext.pObject;
      v20 = (*(unsigned int (**)(void))(*(_QWORD *)v36 + 104i64))();
      Scaleform::Render::DrawableImage::initialize(v1, v20, &size, v19);
    }
  }
  if ( v1->pRT.pObject )
  {
    if ( v11 )
    {
      v22 = *((_QWORD *)&v36 + 1);
      v23 = ~(unsigned __int8)(*(_DWORD *)(*((_QWORD *)&v36 + 1) + 24i64) >> 2) & 1;
      v24 = ~(unsigned __int8)(*(_DWORD *)(*((_QWORD *)&v36 + 1) + 24i64) >> 1) & 1;
      if ( v24 )
      {
        (*(void (**)(void))(**((_QWORD **)&v36 + 1) + 40i64))();
        v22 = *((_QWORD *)&v36 + 1);
      }
      if ( !v23 )
      {
        (*(void (**)(void))(*(_QWORD *)v22 + 80i64))();
        v22 = *((_QWORD *)&v36 + 1);
      }
      (*(void (**)(void))(*(_QWORD *)v22 + 72i64))();
      v25 = v1->pRT.pObject;
      v26 = v25->ViewRect.x2 - v25->ViewRect.x1;
      v27 = (float)(v25->ViewRect.y2 - v25->ViewRect.y1);
      v54 = 0;
      v41 = 0i64;
      v42 = (float)v26;
      v43 = v27;
      (*(void (__fastcall **)(_QWORD, __int64 *, Scaleform::Render::RenderTarget *, signed __int64, int *))(**((_QWORD **)&v36 + 1) + 192i64))(
        *((_QWORD *)&v36 + 1),
        &v41,
        v25,
        2i64,
        &v54);
      v28 = v1->pRT.pObject;
      v29 = v28->ViewRect.y2 - v28->ViewRect.y1;
      v56 = v28->ViewRect.x2 - v28->ViewRect.x1;
      v57 = v29;
      v30 = (int *)(*(__int64 (__fastcall **)(_QWORD, int *))(**(_QWORD **)(*((_QWORD *)&v36 + 1) + 48i64) + 8i64))(
                     *(_QWORD *)(*((_QWORD *)&v36 + 1) + 48i64),
                     &v56);
      v44 = *v30;
      v45 = v30[1];
      v46 = v30[2];
      v47 = v30[3];
      v48 = v30[4];
      v49 = v30[5];
      v50 = v30[6];
      v51 = v30[7];
      v39 = _xmm;
      v40 = _xmm;
      v31 = (signed int *)v1->pRT.pObject;
      v32 = (float)(v31[15] - v31[13]) / (float)v31[11];
      *(float *)&v39 = (float)(v31[14] - v31[12]) / (float)v31[10];
      *((float *)&v39 + 1) = *(float *)&v39 * 0.0;
      *((float *)&v39 + 2) = *(float *)&v39 * 0.0;
      *((float *)&v39 + 3) = *(float *)&v39 * 0.0;
      v40.m128_f32[0] = v32 * 0.0;
      v40.m128_f32[1] = v32;
      v40.m128_f32[2] = v32 * 0.0;
      v40.m128_f32[3] = v32 * 0.0;
      Scaleform::Render::HAL::applyBlendMode(*((Scaleform::Render::HAL **)&v36 + 1), 16i64, 1, 1);
      LODWORD(v33) = -1;
      (*(void (__fastcall **)(_QWORD, __int64, int *, __int128 *, __int64))(**((_QWORD **)&v36 + 1) + 464i64))(
        *((_QWORD *)&v36 + 1),
        v11,
        &v44,
        &v39,
        v33);
      (*(void (__fastcall **)(_QWORD, signed __int64))(**((_QWORD **)&v36 + 1) + 200i64))(*((_QWORD *)&v36 + 1), 2i64);
      Scaleform::Render::DrawableImage::updateStagingTargetRT(v1);
      (*(void (**)(void))(**((_QWORD **)&v36 + 1) + 80i64))();
      if ( !v23 )
        (*(void (**)(void))(**((_QWORD **)&v36 + 1) + 72i64))();
      if ( v24 )
        (*(void (**)(void))(**((_QWORD **)&v36 + 1) + 48i64))();
    }
    else if ( v10 && Scaleform::Render::DrawableImage::mapTextureRT(v1, 0) )
    {
      v34 = v10->vfptr + 8;
      v35 = Scaleform::Render::DrawableImage::getMappedData(v1);
      ((void (__fastcall *)(Scaleform::Render::ImageBase *, Scaleform::Render::ImageData *, _QWORD, _QWORD))v34->__vecDelDtor)(
        v10,
        v35,
        Scaleform::Render::ImageBase::CopyScanlineDefault,
        0i64);
      Scaleform::Render::DrawableImage::unmapTextureRT(v1);
    }
    v21 = 1;
    goto LABEL_37;
  }
LABEL_23:
  v21 = 0;
LABEL_37:
  if ( v10 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v10->vfptr[2].__vecDelDtor)(v10);
  return v21;
}((void (__fastcall *)(Scaleform::Render::ImageBase *))v10->vfptr[2].__vecDelDtor)(v10);
  return v21;
}

// File Line: 567
// RVA: 0x9F88D0
void __fastcall Scaleform::Render::DrawableImage::unmapTextureRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = &this->pQueue.pObject->QueueLock.cs;
  EnterCriticalSection(v2);
  if ( v1->DrawableImageState & 3 && v1->pTexture.Value )
  {
    ((void (__cdecl *)(Scaleform::Render::Texture *volatile ))v1->pTexture.Value->vfptr[14].__vecDelDtor)(v1->pTexture.Value);
    v1->DrawableImageState &= 0xFFFFFFFC;
  }
  LeaveCriticalSection(v2);
}

// File Line: 579
// RVA: 0x9FA5E0
void __fastcall Scaleform::Render::DrawableImage::updateRenderTargetRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rdi
  Scaleform::Render::DrawableImageContext *v2; // rbx
  Scaleform::Render::TextureManager *v3; // rax
  Scaleform::Render::HAL *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int128 v7; // [rsp+28h] [rbp-30h]
  __int64 v8; // [rsp+38h] [rbp-20h]
  __int64 v9; // [rsp+40h] [rbp-18h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+60h] [rbp+8h]

  v1 = this;
  if ( this->pTexture.Value )
  {
    lpCriticalSection = &this->pQueue.pObject->QueueLock.cs;
    EnterCriticalSection(lpCriticalSection);
    if ( v1->DrawableImageState & 3 && v1->pTexture.Value )
    {
      ((void (__cdecl *)(Scaleform::Render::Texture *volatile ))v1->pTexture.Value->vfptr[14].__vecDelDtor)(v1->pTexture.Value);
      v1->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(lpCriticalSection);
    v7 = 0ui64;
    v8 = 0i64;
    v9 = 0i64;
    v2 = v1->pContext.pObject;
    v2->pRTCommandQueue->vfptr->GetRenderInterfaces(v2->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v7);
    v3 = (Scaleform::Render::TextureManager *)v7;
    if ( v2->IDefaults.pTextureManager )
      v3 = v2->IDefaults.pTextureManager;
    *(_QWORD *)&v7 = v3;
    v4 = (Scaleform::Render::HAL *)*((_QWORD *)&v7 + 1);
    if ( v2->IDefaults.pHAL )
      v4 = v2->IDefaults.pHAL;
    *((_QWORD *)&v7 + 1) = v4;
    v5 = v8;
    if ( v2->IDefaults.pRenderer2D )
      v5 = (__int64)v2->IDefaults.pRenderer2D;
    v8 = v5;
    v6 = v9;
    if ( v2->IDefaults.RenderThreadID )
      v6 = (__int64)v2->IDefaults.RenderThreadID;
    v9 = v6;
    ((void (__fastcall *)(Scaleform::Render::Texture *volatile , Scaleform::Render::RenderBuffer::RenderTargetData *, _QWORD))v1->pTexture.Value->vfptr[15].__vecDelDtor)(
      v1->pTexture.Value,
      v1->pRT.pObject->pRenderTargetData,
      *((_QWORD *)&v7 + 1));
  }
}

// File Line: 591
// RVA: 0x9FA940
void __fastcall Scaleform::Render::DrawableImage::updateStagingTargetRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImage *v1; // rdi
  Scaleform::Render::DrawableImageContext *v2; // rbx
  Scaleform::Render::TextureManager *v3; // rax
  Scaleform::Render::HAL *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rdx
  __int64 v9; // rdx
  Scaleform::Render::RenderSync *v10; // rax
  Scaleform::Render::Fence *v11; // rax
  Scaleform::Render::Fence *v12; // rbx
  Scaleform::Render::Fence *v13; // rcx
  __int128 v14; // [rsp+28h] [rbp-30h]
  __int64 v15; // [rsp+38h] [rbp-20h]
  __int64 v16; // [rsp+40h] [rbp-18h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+60h] [rbp+8h]

  v1 = this;
  if ( this->pTexture.Value )
  {
    v14 = 0ui64;
    v15 = 0i64;
    v16 = 0i64;
    v2 = this->pContext.pObject;
    v2->pRTCommandQueue->vfptr->GetRenderInterfaces(v2->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v14);
    v3 = (Scaleform::Render::TextureManager *)v14;
    if ( v2->IDefaults.pTextureManager )
      v3 = v2->IDefaults.pTextureManager;
    *(_QWORD *)&v14 = v3;
    v4 = (Scaleform::Render::HAL *)*((_QWORD *)&v14 + 1);
    if ( v2->IDefaults.pHAL )
      v4 = v2->IDefaults.pHAL;
    *((_QWORD *)&v14 + 1) = v4;
    v5 = v15;
    if ( v2->IDefaults.pRenderer2D )
      v5 = (__int64)v2->IDefaults.pRenderer2D;
    v15 = v5;
    v6 = v16;
    if ( v2->IDefaults.RenderThreadID )
      v6 = (__int64)v2->IDefaults.RenderThreadID;
    v16 = v6;
    lpCriticalSection = &v1->pQueue.pObject->QueueLock.cs;
    EnterCriticalSection(lpCriticalSection);
    if ( v1->DrawableImageState & 3 && v1->pTexture.Value )
    {
      ((void (__cdecl *)(Scaleform::Render::Texture *volatile , __int64))v1->pTexture.Value->vfptr[14].__vecDelDtor)(
        v1->pTexture.Value,
        v7);
      v1->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(lpCriticalSection);
    v1->pTexture.Value->vfptr[16].__vecDelDtor(
      (Scaleform::RefCountImplCore *)v1->pTexture.Value,
      (unsigned int)v1->pRT.pObject->pRenderTargetData);
    if ( (*(__int64 (__cdecl **)(_QWORD, __int64))(**((_QWORD **)&v14 + 1) + 520i64))(*((_QWORD *)&v14 + 1), v8) )
    {
      v10 = (Scaleform::Render::RenderSync *)(*(__int64 (__cdecl **)(_QWORD, __int64))(**((_QWORD **)&v14 + 1) + 520i64))(
                                               *((_QWORD *)&v14 + 1),
                                               v9);
      v11 = Scaleform::Render::RenderSync::InsertFence(v10);
      v12 = v11;
      if ( v11 )
        ++v11->RefCount;
      v13 = v1->pFence.pObject;
      if ( v13 )
        Scaleform::Render::Fence::Release(v13);
      v1->pFence.pObject = v12;
    }
  }
}

// File Line: 608
// RVA: 0x937EA0
void __fastcall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(Scaleform::Render::DrawableImage *this, Scaleform::Render::DICommand_SetPixels *cmd)
{
  Scaleform::Render::DICommand_SetPixels *v2; // rbx
  Scaleform::Render::DrawableImage *v3; // rdi
  Scaleform::Render::DrawableImageContext *v4; // rax
  Scaleform::Render::DICommand_SetPixels *v5; // rax
  Scaleform::Render::DICommandQueue *v6; // rbx

  v2 = cmd;
  v3 = this;
  v4 = this->pContext.pObject;
  if ( v4 && v4->pControlContext )
    v4->pControlContext->DIChangesRequired = 1;
  if ( !Scaleform::Render::DICommand::ExecuteSWOnAddCommand((Scaleform::Render::DICommand *)&cmd->vfptr, this) )
  {
    v5 = (Scaleform::Render::DICommand_SetPixels *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                     v3->pQueue.pObject,
                                                     0x30u,
                                                     &v3->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(v5, v2);
    if ( v2->vfptr->GetRenderCaps((Scaleform::Render::DICommand *)&v2->vfptr) & 0x10 )
    {
      v6 = v3->pQueue.pObject;
      _InterlockedExchangeAdd(&v6->RefCount, 1u);
      _InterlockedExchangeAdd(&v6->ExecuteCmd.pObject->RefCount, 1u);
      v6->pRTCommandQueue->vfptr->PushThreadCommand(
        v6->pRTCommandQueue,
        (Scaleform::Render::ThreadCommand *)v6->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(v6->ExecuteCmd.pObject);
    }
  }
}

// File Line: 626
// RVA: 0x9E7230
Scaleform::Render::ImageData *__fastcall Scaleform::Render::DrawableImage::getMappedData(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::Fence *v1; // rax
  Scaleform::Render::DrawableImage *v2; // rbx
  Scaleform::Render::FenceImpl *v3; // r8
  Scaleform::Render::Fence *v4; // r8
  Scaleform::Render::FenceImpl *v5; // r8
  Scaleform::Render::Fence *v6; // rcx

  v1 = this->pFence.pObject;
  v2 = this;
  if ( v1 )
  {
    if ( v1->HasData )
    {
      v3 = v1->Data;
      if ( v1->Data )
      {
        if ( v3->Parent )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v3->RSContext->vfptr[4].__vecDelDtor)(
                 v3->RSContext,
                 1i64,
                 v3->APIHandle) )
          {
            v4 = v2->pFence.pObject;
            if ( v4->HasData )
            {
              v5 = v4->Data;
              if ( v5 )
              {
                if ( v5->Parent )
                  ((void (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v5->RSContext->vfptr[5].__vecDelDtor)(
                    v5->RSContext,
                    1i64,
                    v5->APIHandle);
              }
            }
          }
        }
      }
    }
  }
  v6 = v2->pFence.pObject;
  if ( v6 )
    Scaleform::Render::Fence::Release(v6);
  v2->pFence.pObject = 0i64;
  return &v2->MappedData;
}

// File Line: 640
// RVA: 0x9F2090
void __fastcall Scaleform::Render::DrawableImage::setViewProj3DHelper(Scaleform::Render::DrawableImage *this, Scaleform::Render::TreeNode *subtree, Scaleform::Render::TreeRoot *root)
{
  Scaleform::Render::TreeRoot *v3; // rdi
  Scaleform::Render::TreeNode *i; // rbx
  __int64 v5; // r8
  Scaleform::Render::Matrix3x4<float> mat; // [rsp+20h] [rbp-19h]
  Scaleform::Render::Matrix4x4<float> mat3D; // [rsp+50h] [rbp+17h]

  v3 = root;
  for ( i = subtree; i; i = (Scaleform::Render::TreeNode *)i->pParent )
  {
    v5 = *(_QWORD *)(((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    if ( (*(_WORD *)(*(_QWORD *)(v5
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&i[-1]
                                                                                         - ((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&i[-1] - ((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40)
                   + 10i64) >> 12) & 1 )
      break;
    if ( (*(_WORD *)(*(_QWORD *)(v5
                               + 8
                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&i[-1]
                                                                                         - ((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&i[-1] - ((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                               + 40)
                   + 10i64) >> 11) & 1 )
      break;
  }
  mat = Scaleform::Render::Matrix3x4<float>::Identity;
  mat3D = Scaleform::Render::Matrix4x4<float>::Identity;
  if ( i )
  {
    Scaleform::Render::TreeNode::GetViewMatrix3D(i, &mat);
    Scaleform::Render::TreeNode::GetProjectionMatrix3D(i, &mat3D);
  }
  Scaleform::Render::TreeNode::SetViewMatrix3D((Scaleform::Render::TreeNode *)&v3->0, &mat);
  Scaleform::Render::TreeNode::SetProjectionMatrix3D((Scaleform::Render::TreeNode *)&v3->0, &mat3D);
}

// File Line: 662
// RVA: 0x959E60
void __fastcall Scaleform::Render::DrawableImage::ApplyFilter(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, Scaleform::Render::Filter *filter)
{
  Scaleform::Render::Point<long> *v5; // r14
  Scaleform::Render::Rect<long> *v6; // rsi
  Scaleform::Render::DrawableImage *v7; // rdi
  Scaleform::Render::DrawableImage *v8; // rbx
  int v9; // er8
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  __int64 v13; // rdx
  Scaleform::Render::Filter *v14; // rcx
  Scaleform::Render::DICommand_ApplyFilter cmd; // [rsp+28h] [rbp-40h]

  v5 = destPoint;
  v6 = sourceRect;
  v7 = source;
  v8 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(
      this,
      source);
  cmd.pImage.pObject = v8;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v7 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[1].__vecDelDtor)(v7);
  cmd.pSource.pObject = v7;
  v9 = v6->y2;
  v10 = v6->x2;
  v11 = v6->y1;
  cmd.SourceRect.x1 = v6->x1;
  cmd.SourceRect.y1 = v11;
  cmd.SourceRect.x2 = v10;
  cmd.SourceRect.y2 = v9;
  v12 = v5->y;
  cmd.DestPoint.x = v5->x;
  cmd.DestPoint.y = v12;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ApplyFilter::`vftable;
  if ( filter )
    _InterlockedExchangeAdd(&filter->RefCount, 1u);
  cmd.pFilter.pObject = filter;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ApplyFilter>(v8, &cmd);
  v14 = cmd.pFilter.pObject;
  if ( cmd.pFilter.pObject && !_InterlockedDecrement(&cmd.pFilter.pObject->RefCount) && v14 )
    v14->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, 1u);
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pSource.pObject,
      v13);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v13);
}

// File Line: 669
// RVA: 0x95BC70
void __fastcall Scaleform::Render::DrawableImage::CalcFilterRect(Scaleform::Render::Rect<float> *result, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Filter *filter)
{
  Scaleform::Render::Rect<float> *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = (float)sourceRect->y1;
  v5 = (float)sourceRect->x2;
  bounds.x1 = (float)sourceRect->x1;
  bounds.y1 = v4;
  bounds.x2 = v5;
  bounds.y2 = (float)sourceRect->y2;
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(filter, &bounds);
  if ( v3 )
  {
    v6 = bounds.y1;
    v3->x1 = bounds.x1;
    v7 = bounds.x2;
    v3->y1 = v6;
    v8 = bounds.y2;
    v3->x2 = v7;
    v3->y2 = v8;
  }
}

// File Line: 679
// RVA: 0x961840
void __fastcall Scaleform::Render::DrawableImage::ColorTransform(Scaleform::Render::DrawableImage *this, Scaleform::Render::Rect<long> *rect, Scaleform::Render::Cxform *cxform)
{
  Scaleform::Render::DrawableImage *v3; // rbx
  Scaleform::Render::DICommand_ColorTransform *v4; // rax
  Scaleform::Render::DICommand_ColorTransform v5; // [rsp+30h] [rbp-58h]

  v3 = this;
  Scaleform::Render::DICommand_ColorTransform::DICommand_ColorTransform(&v5, this, rect, cxform);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ColorTransform>(v3, v4);
  if ( v5.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v5.pSource.pObject->vfptr[2].__vecDelDtor)(v5.pSource.pObject);
  v5.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v5.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v5.pImage.pObject->vfptr[2].__vecDelDtor)(v5.pImage.pObject);
}

// File Line: 685
// RVA: 0x9618B0
void __fastcall Scaleform::Render::DrawableImage::Compare(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *image0, Scaleform::Render::DrawableImage *image1)
{
  Scaleform::Render::DrawableImage *v3; // rbx
  Scaleform::Render::DICommand_Compare *v4; // rax
  __int64 v5; // rdx
  Scaleform::Render::DICommand_Compare v6; // [rsp+28h] [rbp-40h]

  v3 = this;
  Scaleform::Render::DICommand_Compare::DICommand_Compare(&v6, this, image0, image1);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Compare>(v3, v4);
  if ( v6.pImageCompare1.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6.pImageCompare1.pObject->vfptr[2].__vecDelDtor)(v6.pImageCompare1.pObject);
  if ( v6.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6.pSource.pObject->vfptr[2].__vecDelDtor)(v6.pSource.pObject);
  v6.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v6.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))v6.pImage.pObject->vfptr[2].__vecDelDtor)(
      v6.pImage.pObject,
      v5);
}

// File Line: 695
// RVA: 0x964620
void __fastcall Scaleform::Render::DrawableImage::CopyChannel(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, Scaleform::Render::DrawableImage::ChannelBits sourceChannel, Scaleform::Render::DrawableImage::ChannelBits destChannel)
{
  Scaleform::Render::Point<long> *v6; // r14
  Scaleform::Render::Rect<long> *v7; // rsi
  Scaleform::Render::DrawableImage *v8; // rdi
  Scaleform::Render::DrawableImage *v9; // rbx
  int v10; // er8
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  __int64 v14; // rdx
  Scaleform::Render::DICommand_CopyChannel cmd; // [rsp+28h] [rbp-40h]

  v6 = destPoint;
  v7 = sourceRect;
  v8 = source;
  v9 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(
      this,
      source);
  cmd.pImage.pObject = v9;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v8->vfptr[1].__vecDelDtor)(v8);
  cmd.pSource.pObject = v8;
  v10 = v7->y2;
  v11 = v7->x2;
  v12 = v7->y1;
  cmd.SourceRect.x1 = v7->x1;
  cmd.SourceRect.y1 = v12;
  cmd.SourceRect.x2 = v11;
  cmd.SourceRect.y2 = v10;
  v13 = v6->y;
  cmd.DestPoint.x = v6->x;
  cmd.DestPoint.y = v13;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CopyChannel::`vftable;
  cmd.SourceChannel = sourceChannel;
  cmd.DestChannel = destChannel;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyChannel>(v9, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pSource.pObject,
      v14);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v14);
}

// File Line: 704
// RVA: 0x964C80
void __fastcall Scaleform::Render::DrawableImage::CopyPixels(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, Scaleform::Render::DrawableImage *alphaSource, Scaleform::Render::Point<long> *alphaPoint, bool mergeAlpha)
{
  Scaleform::Render::Point<long> *v7; // r14
  Scaleform::Render::Rect<long> *v8; // rsi
  Scaleform::Render::DrawableImage *v9; // rdi
  Scaleform::Render::DrawableImage *v10; // rbx
  int v11; // er8
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  __int64 v15; // rdx
  Scaleform::Render::DICommand_CopyPixels cmd; // [rsp+28h] [rbp-48h]
  Scaleform::Render::DrawableImage *alphaSourcea; // [rsp+B0h] [rbp+40h]

  v7 = destPoint;
  v8 = sourceRect;
  v9 = source;
  v10 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(
      this,
      source);
  cmd.pImage.pObject = v10;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v9->vfptr[1].__vecDelDtor)(v9);
  cmd.pSource.pObject = v9;
  v11 = v8->y2;
  v12 = v8->x2;
  v13 = v8->y1;
  cmd.SourceRect.x1 = v8->x1;
  cmd.SourceRect.y1 = v13;
  cmd.SourceRect.x2 = v12;
  cmd.SourceRect.y2 = v11;
  v14 = v7->y;
  cmd.DestPoint.x = v7->x;
  cmd.DestPoint.y = v14;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CopyPixels::`vftable;
  if ( alphaSource )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))alphaSource->vfptr[1].__vecDelDtor)(alphaSource);
  cmd.pAlphaSource.pObject = alphaSource;
  if ( alphaPoint )
    alphaSourcea = (Scaleform::Render::DrawableImage *)*alphaPoint;
  else
    alphaSourcea = 0i64;
  cmd.AlphaPoint = (Scaleform::Render::Point<long>)alphaSourcea;
  cmd.MergeAlpha = mergeAlpha;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyPixels>(v10, &cmd);
  if ( cmd.pAlphaSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pAlphaSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pAlphaSource.pObject,
      v15);
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pSource.pObject,
      v15);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v15);
}

// File Line: 722
// RVA: 0x96E8F0
void __fastcall Scaleform::Render::DrawableImage::Draw(Scaleform::Render::DrawableImage *this, Scaleform::Render::TreeNode *subtree, Scaleform::Render::Matrix2x4<float> *matrix, Scaleform::Render::Cxform *cform, Scaleform::Render::BlendMode blendMode, Scaleform::Render::Rect<long> *clipRect)
{
  Scaleform::Render::TreeNode *v6; // rbx
  Scaleform::Render::DrawableImage *v7; // r13
  Scaleform::Render::DrawableImageContext *v8; // rcx
  Scaleform::Render::TreeRoot *v9; // r15
  Scaleform::Render::TreeNode *v10; // r12
  int v11; // er8
  int v12; // edx
  int v13; // ecx
  int *v14; // rax
  int *v15; // rax
  int v16; // edx
  int v17; // ecx
  int v18; // er14
  int v19; // edi
  int v20; // esi
  int v21; // ebx
  int *v22; // rax
  Scaleform::Render::ContextImpl::EntryData *v23; // rax
  __int64 v24; // rdx
  __int64 v25; // r8
  __int64 v26; // r9
  Scaleform::Render::DrawableImageContext *v27; // rax
  Scaleform::Render::DICommand_Draw *v28; // rax
  __int64 v29; // rdx
  __int64 v30; // r8
  __int64 v31; // r9
  bool v32; // zf
  int v33; // [rsp+20h] [rbp-B9h]
  int v34; // [rsp+24h] [rbp-B5h]
  int v35; // [rsp+28h] [rbp-B1h]
  int v36; // [rsp+2Ch] [rbp-ADh]
  __int64 v37; // [rsp+30h] [rbp-A9h]
  int v38; // [rsp+38h] [rbp-A1h]
  int v39; // [rsp+3Ch] [rbp-9Dh]
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-99h]
  int v41; // [rsp+70h] [rbp-69h]
  int v42; // [rsp+74h] [rbp-65h]
  int v43; // [rsp+78h] [rbp-61h]
  int v44; // [rsp+7Ch] [rbp-5Dh]
  char v45; // [rsp+80h] [rbp-59h]
  char v46; // [rsp+88h] [rbp-51h]
  Scaleform::Render::TreeRoot *v47; // [rsp+90h] [rbp-49h]
  __int64 v48; // [rsp+98h] [rbp-41h]
  Scaleform::Render::TreeNode *v49; // [rsp+A0h] [rbp-39h]
  Scaleform::Render::DICommand_Draw v50; // [rsp+A8h] [rbp-31h]
  int v51; // [rsp+134h] [rbp+5Bh]
  Scaleform::Render::TreeNode *subtreea; // [rsp+138h] [rbp+5Fh]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+140h] [rbp+67h]
  Scaleform::Render::Cxform *v54; // [rsp+148h] [rbp+6Fh]

  v54 = cform;
  m = matrix;
  subtreea = subtree;
  v48 = -2i64;
  v6 = subtree;
  v7 = this;
  v8 = this->pContext.pObject;
  if ( v8 && v8->RContext )
  {
    v9 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeRoot>(v8->RContext);
    v47 = v9;
    if ( v9 )
    {
      v10 = Scaleform::Render::TreeNode::Clone(v6, v7->pContext.pObject->RContext);
      v49 = v10;
      Scaleform::Render::TreeContainer::Add((Scaleform::Render::TreeContainer *)&v9->0, v10);
      if ( clipRect )
      {
        v11 = clipRect->y2;
        v12 = clipRect->x2;
        v13 = clipRect->y1;
        v33 = clipRect->x1;
        v34 = v13;
        v35 = v12;
        v36 = v11;
        v14 = &v33;
      }
      else
      {
        v15 = (int *)v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&v46);
        v16 = v15[1];
        v17 = *v15;
        v37 = 0i64;
        v38 = v17;
        v39 = v16;
        v14 = (int *)&v37;
      }
      v18 = v14[3];
      v19 = v14[2];
      v20 = v14[1];
      v41 = *v14;
      v21 = v41;
      v42 = v20;
      v43 = v19;
      v44 = v18;
      v22 = (int *)v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&v45);
      v51 = v22[1];
      vp.BufferWidth = *v22;
      vp.BufferHeight = v51;
      vp.Left = v21;
      vp.Top = v20;
      vp.Width = v19 - v21;
      vp.Height = v18 - v20;
      vp.Flags = 1;
      *(_QWORD *)&vp.ScissorWidth = 0i64;
      *(_QWORD *)&vp.ScissorLeft = 0i64;
      Scaleform::Render::TreeRoot::SetViewport(v9, &vp);
      Scaleform::Render::TreeNode::SetMatrix((Scaleform::Render::TreeNode *)&v9->0, m);
      Scaleform::Render::DrawableImage::setViewProj3DHelper(v7, subtreea, v9);
      Scaleform::Render::TreeNode::SetMatrix(v10, &Scaleform::Render::Matrix2x4<float>::Identity);
      Scaleform::Render::TreeNode::SetVisible(v10, 1);
      v23 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v10->0, 2u);
      v23[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v54->M[0][0];
      v23[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v54->M[1][0];
      Scaleform::Render::TreeNode::SetBlendMode(v10, blendMode);
      ++v9->RefCount;
      v27 = v7->pContext.pObject;
      if ( v27->pControlContext )
        v27->pControlContext->DIChangesRequired = 1;
      ((void (__cdecl *)(Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl **, __int64, __int64, __int64))v7->pContext.pObject->vfptr->OnCapture)(
        &v7->pContext.pObject->vfptr,
        v24,
        v25,
        v26);
      Scaleform::Render::DICommand_Draw::DICommand_Draw(&v50, v7, v9, clipRect);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(v7, v28);
      v50.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( v50.pImage.pObject )
        ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, __int64, __int64))v50.pImage.pObject->vfptr[2].__vecDelDtor)(
          v50.pImage.pObject,
          v29,
          v30,
          v31);
      if ( v10 )
      {
        v32 = v10->RefCount-- == 1;
        if ( v32 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v10->0);
      }
    }
    if ( v9 )
    {
      v32 = v9->RefCount-- == 1;
      if ( v32 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v9->0);
    }
  }
}

// File Line: 764
// RVA: 0x96E510
void __fastcall Scaleform::Render::DrawableImage::Draw(Scaleform::Render::DrawableImage *this, Scaleform::Render::Image *source, Scaleform::Render::Matrix2x4<float> *matrix, Scaleform::Render::Cxform *cform)
{
  Scaleform::Render::Image *v4; // rsi
  Scaleform::Render::DrawableImage *v5; // rdi
  Scaleform::Render::DrawableImageContext *v6; // rcx
  Scaleform::Render::TreeRoot *v7; // r12
  Scaleform::Render::TreeNode *v8; // rax
  Scaleform::Render::TreeShape *v9; // r13
  Scaleform::Render::ComplexFill *v10; // rax
  __int64 v11; // rax
  __int64 v12; // r15
  __int64 v13; // rcx
  Scaleform::Render::ShapeDataFloatMP *v14; // rax
  __int64 v15; // rax
  __int64 v16; // r14
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *v17; // rbx
  signed __int64 v18; // rcx
  signed __int64 v19; // rdx
  bool v20; // zf
  __int64 v21; // rdx
  signed int *v22; // rbx
  __int64 v23; // rax
  int v24; // er8
  int v25; // edx
  int v26; // ecx
  int *v27; // rax
  int *v28; // rax
  int v29; // edx
  int v30; // ecx
  int v31; // er14
  int v32; // edi
  int v33; // esi
  int v34; // ebx
  int *v35; // rax
  int v36; // ST34_4
  Scaleform::Render::ContextImpl::EntryData *v37; // rax
  Scaleform::Render::ContextImpl::EntryData *v38; // rcx
  Scaleform::Render::DrawableImage *v39; // rbx
  Scaleform::Render::DrawableImageContext *v40; // rax
  Scaleform::Render::DICommand_Draw *v41; // rax
  __int64 v42; // [rsp+38h] [rbp-90h]
  int v43; // [rsp+40h] [rbp-88h]
  int v44; // [rsp+44h] [rbp-84h]
  int v45; // [rsp+48h] [rbp-80h]
  __int64 v46; // [rsp+4Ch] [rbp-7Ch]
  int v47; // [rsp+58h] [rbp-70h]
  int v48; // [rsp+5Ch] [rbp-6Ch]
  Scaleform::Render::Viewport vp; // [rsp+60h] [rbp-68h]
  char v50; // [rsp+90h] [rbp-38h]
  __int64 v51; // [rsp+98h] [rbp-30h]
  char v52; // [rsp+A0h] [rbp-28h]
  __int64 v53; // [rsp+A8h] [rbp-20h]
  char v54; // [rsp+B0h] [rbp-18h]
  __int64 v55; // [rsp+B8h] [rbp-10h]
  __int64 v56; // [rsp+C0h] [rbp-8h]
  Scaleform::Render::DICommand_Draw v57; // [rsp+C8h] [rbp+0h]
  Scaleform::Render::DrawableImage *image; // [rsp+138h] [rbp+70h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+148h] [rbp+80h]
  Scaleform::Render::ContextImpl::EntryData *v60; // [rsp+150h] [rbp+88h]
  Scaleform::Render::BlendMode mode; // [rsp+158h] [rbp+90h]
  Scaleform::Render::Rect<long> *vars0; // [rsp+160h] [rbp+98h]

  v56 = -2i64;
  v4 = source;
  v5 = this;
  v6 = this->pContext.pObject;
  if ( v6 && v6->RContext )
  {
    v7 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeRoot>(v6->RContext);
    *(_QWORD *)&vp.ScissorWidth = v7;
    if ( v7 )
    {
      v8 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(v5->pContext.pObject->RContext);
      v9 = (Scaleform::Render::TreeShape *)v8;
      *(_QWORD *)&vp.Flags = v8;
      Scaleform::Render::TreeContainer::Add((Scaleform::Render::TreeContainer *)&v7->0, v8);
      *(_QWORD *)&vp.Width = 0i64;
      vp.Left = 0;
      v10 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                80ui64,
                                                0i64);
      if ( v10 )
      {
        Scaleform::Render::ComplexFill::ComplexFill(v10);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      *(_QWORD *)&vp.Width = v12;
      if ( v4 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v4->vfptr[1].__vecDelDtor)(v4);
      v13 = *(_QWORD *)(v12 + 16);
      if ( v13 )
        (*(void (**)(void))(*(_QWORD *)v13 + 16i64))();
      *(_QWORD *)(v12 + 16) = v4;
      v14 = (Scaleform::Render::ShapeDataFloatMP *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     160ui64,
                                                     0i64);
      if ( v14 )
      {
        Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(v14);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      v42 = v16;
      v51 = v16;
      v17 = *(Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> **)(v16 + 144);
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v17 + 1,
        &v17[1],
        v17[1].Size + 1);
      v18 = 16 * v17[1].Size;
      v19 = (signed __int64)&v17[1].Data[-1];
      v20 = v18 + v19 == 0;
      v21 = v18 + v19;
      v53 = v21;
      v55 = v21;
      if ( !v20 )
      {
        *(_DWORD *)v21 = 0;
        _InterlockedExchangeAdd((volatile signed __int32 *)(v12 + 8), 1u);
        *(_QWORD *)(v21 + 8) = v12;
      }
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(*(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > **)(v16 + 144));
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        *(Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > **)(v16 + 144),
        1u,
        0,
        0);
      v22 = (signed int *)v4->vfptr[5].__vecDelDtor(
                            (Scaleform::RefCountImplCore *)&v4->vfptr,
                            (unsigned int)&vp.ScissorLeft);
      v23 = (__int64)v4->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v50);
      Scaleform::Render::ShapeDataFloatMP::RectanglePath(
        (Scaleform::Render::ShapeDataFloatMP *)v16,
        0.0,
        0.0,
        (float)*v22,
        (float)*(signed int *)(v23 + 4));
      Scaleform::Render::ShapeDataFloatMP::CountLayers((Scaleform::Render::ShapeDataFloatMP *)v16);
      Scaleform::Render::TreeShape::SetShape(v9, (Scaleform::Render::ShapeMeshProvider *)v16);
      if ( vars0 )
      {
        v24 = vars0->y2;
        v25 = vars0->x2;
        v26 = vars0->y1;
        v43 = vars0->x1;
        v44 = v26;
        v45 = v25;
        LODWORD(v46) = v24;
        v27 = &v43;
      }
      else
      {
        v28 = (int *)v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v54);
        v29 = v28[1];
        v30 = *v28;
        *(__int64 *)((char *)&v46 + 4) = 0i64;
        v47 = v30;
        v48 = v29;
        v27 = (int *)((char *)&v46 + 4);
      }
      v31 = v27[3];
      v32 = v27[2];
      v33 = v27[1];
      v47 = *v27;
      v34 = v47;
      v48 = v33;
      vp.BufferWidth = v32;
      vp.BufferHeight = v31;
      v35 = (int *)image->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)image, (unsigned int)&v52);
      v36 = v35[1];
      vp.BufferWidth = *v35;
      vp.BufferHeight = v36;
      vp.Left = v34;
      vp.Top = v33;
      vp.Width = v32 - v34;
      vp.Height = v31 - v33;
      v46 = 0i64;
      *(_QWORD *)&vp.ScissorTop = 0i64;
      vp.ScissorLeft = 0;
      Scaleform::Render::TreeRoot::SetViewport(v7, &vp);
      Scaleform::Render::TreeNode::SetMatrix((Scaleform::Render::TreeNode *)&v7->0, m);
      Scaleform::Render::TreeNode::SetMatrix(
        (Scaleform::Render::TreeNode *)&v9->0,
        &Scaleform::Render::Matrix2x4<float>::Identity);
      v37 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v9->0, 2u);
      v38 = v60;
      v37[5] = *v60;
      v37[6] = v38[1];
      Scaleform::Render::TreeNode::SetBlendMode((Scaleform::Render::TreeNode *)&v9->0, mode);
      ++v7->RefCount;
      v39 = image;
      v40 = image->pContext.pObject;
      if ( v40->pControlContext )
        v40->pControlContext->DIChangesRequired = 1;
      ((void (*)(void))v39->pContext.pObject->vfptr->OnCapture)();
      Scaleform::Render::DICommand_Draw::DICommand_Draw(&v57, v39, v7, vars0);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(v39, v41);
      v57.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( v57.pImage.pObject )
        ((void (*)(void))v57.pImage.pObject->vfptr[2].__vecDelDtor)();
      (*(void (**)(void))(*(_QWORD *)(v42 + 16) + 16i64))();
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v12 + 8)) )
        (**(void (__fastcall ***)(__int64, signed __int64))v12)(v12, 1i64);
      if ( v9 )
      {
        v20 = v9->RefCount-- == 1;
        if ( v20 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v9->0);
      }
    }
    if ( v7 )
    {
      v20 = v7->RefCount-- == 1;
      if ( v20 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v7->0);
    }
  }
}

// File Line: 813
// RVA: 0x977FB0
void __fastcall Scaleform::Render::DrawableImage::FillRect(Scaleform::Render::DrawableImage *this, Scaleform::Render::Rect<long> *rect, __int64 color)
{
  Scaleform::Render::Rect<long> *v3; // rsi
  Scaleform::Render::DrawableImage *v4; // rdi
  unsigned int v5; // ebx
  int v6; // er8
  int v7; // edx
  int v8; // ecx
  __int64 v9; // rdx
  Scaleform::Render::DICommand_FillRect cmd; // [rsp+28h] [rbp-30h]

  v3 = rect;
  v4 = this;
  v5 = *(_DWORD *)color;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::Rect<long> *))this->vfptr[1].__vecDelDtor)(
      this,
      rect);
  cmd.pImage.pObject = v4;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_FillRect::`vftable;
  v6 = v3->y2;
  v7 = v3->x2;
  v8 = v3->y1;
  cmd.ApplyRect.x1 = v3->x1;
  cmd.ApplyRect.y1 = v8;
  cmd.ApplyRect.x2 = v7;
  cmd.ApplyRect.y2 = v6;
  cmd.FillColor.Raw = v5;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FillRect>(v4, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v9);
}

// File Line: 819
// RVA: 0x97AB50
void __fastcall Scaleform::Render::DrawableImage::FloodFill(Scaleform::Render::DrawableImage *this, Scaleform::Render::Point<long> *pt, __int64 color)
{
  Scaleform::Render::Point<long> *v3; // rsi
  Scaleform::Render::DrawableImage *v4; // rdi
  unsigned int v5; // ebx
  int v6; // ecx
  __int64 v7; // rdx
  Scaleform::Render::DICommand_FloodFill cmd; // [rsp+28h] [rbp-30h]

  v3 = pt;
  v4 = this;
  v5 = *(_DWORD *)color;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::Point<long> *))this->vfptr[1].__vecDelDtor)(
      this,
      pt);
  cmd.pImage.pObject = v4;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_FloodFill::`vftable;
  v6 = v3->y;
  cmd.Pt.x = v3->x;
  cmd.Pt.y = v6;
  cmd.FillColor.Raw = v5;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FloodFill>(v4, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v7);
}

// File Line: 824
// RVA: 0x981620
Scaleform::Render::Rect<long> *__fastcall Scaleform::Render::DrawableImage::GetColorBoundsRect(Scaleform::Render::DrawableImage *this, Scaleform::Render::Rect<long> *result, unsigned int mask, unsigned int color, bool findColor)
{
  unsigned int v5; // ebp
  unsigned int v6; // esi
  Scaleform::Render::Rect<long> *v7; // rbx
  Scaleform::Render::DrawableImage *v8; // rdi
  __int64 v9; // rdx
  Scaleform::Render::DICommand_GetColorBoundsRect cmd; // [rsp+28h] [rbp-30h]

  v5 = color;
  v6 = mask;
  v7 = result;
  v8 = this;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::Rect<long> *))this->vfptr[1].__vecDelDtor)(
      this,
      result);
  cmd.pImage.pObject = v8;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetColorBoundsRect::`vftable;
  cmd.Mask = v6;
  cmd.SearchColor = v5;
  cmd.FindColor = findColor;
  cmd.Result = v7;
  if ( !v8->Transparent )
    cmd.Mask = v6 & 0xFFFFFF;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetColorBoundsRect>(v8, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v9);
  return v7;
}

// File Line: 835
// RVA: 0x98A890
Scaleform::Render::Color *__fastcall Scaleform::Render::DrawableImage::GetPixel(Scaleform::Render::DrawableImage *this, Scaleform::Render::Color *result, int x, int y)
{
  Scaleform::Render::Color *v4; // rbx

  v4 = result;
  Scaleform::Render::DrawableImage::GetPixel32(this, result, x, y);
  v4->Channels.Alpha = 0;
  return v4;
}

// File Line: 844
// RVA: 0x98A7C0
Scaleform::Render::Color *__fastcall Scaleform::Render::DrawableImage::GetPixel32(Scaleform::Render::DrawableImage *this, Scaleform::Render::Color *result, int x, int y)
{
  int v4; // esi
  int v5; // ebp
  Scaleform::Render::Color *v6; // rbx
  Scaleform::Render::DrawableImage *v7; // rdi
  __int64 v8; // rdx
  Scaleform::Render::DICommand_GetPixel32 cmd; // [rsp+28h] [rbp-40h]
  unsigned int v11; // [rsp+80h] [rbp+18h]

  v4 = y;
  v5 = x;
  v6 = result;
  v7 = this;
  if ( x >= this->ISize.Width || y >= this->ISize.Height || x < 0 || y < 0 )
  {
    result->Raw = 0;
  }
  else
  {
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::Color *))this->vfptr[1].__vecDelDtor)(
      this,
      result);
    cmd.pImage.pObject = v7;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetPixel32::`vftable;
    cmd.X = v5;
    cmd.Y = v4;
    cmd.Result = (Scaleform::Render::Color *)&v11;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixel32>(v7, &cmd);
    v6->Raw = v11;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
        cmd.pImage.pObject,
        v8);
  }
  return v6;
}

// File Line: 856
// RVA: 0x98AA10
char __fastcall Scaleform::Render::DrawableImage::GetPixels(Scaleform::Render::DrawableImage *this, Scaleform::Render::DIPixelProvider *provider, Scaleform::Render::Rect<long> *sourceRect)
{
  Scaleform::Render::DIPixelProvider *v3; // r15
  Scaleform::Render::DrawableImage *v4; // rbx
  signed int v5; // er14
  signed int v6; // esi
  int v7; // edi
  int v8; // ebp
  char v9; // bl
  Scaleform::Render::DICommand_GetPixels cmd; // [rsp+28h] [rbp-60h]
  char v12; // [rsp+90h] [rbp+8h]

  v3 = provider;
  v4 = this;
  v5 = sourceRect->x2;
  if ( (signed int)this->ISize.Width < v5 )
    return 0;
  v6 = sourceRect->y2;
  if ( (signed int)this->ISize.Height < v6 )
    return 0;
  v7 = sourceRect->x1;
  if ( sourceRect->x1 < 0 )
    return 0;
  v8 = sourceRect->y1;
  if ( v8 < 0 )
    return 0;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DIPixelProvider *))this->vfptr[1].__vecDelDtor)(
    this,
    provider);
  cmd.pImage.pObject = v4;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetPixels::`vftable;
  cmd.SourceRect.x1 = v7;
  cmd.SourceRect.y1 = v8;
  cmd.SourceRect.x2 = v5;
  cmd.SourceRect.y2 = v6;
  cmd.Provider = v3;
  cmd.Result = (bool *)&v12;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixels>(v4, &cmd);
  v9 = v12;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::RefCountImplCoreVtbl *))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      cmd.pImage.pObject->vfptr);
  return v9;
}

// File Line: 873
// RVA: 0x9913E0
void __fastcall Scaleform::Render::DrawableImage::Histogram(Scaleform::Render::DrawableImage *this, Scaleform::Render::Rect<long> *rect, unsigned int (*colors)[256])
{
  unsigned int (*v3)[256]; // r12
  Scaleform::Render::Rect<long> *v4; // rdi
  Scaleform::Render::DrawableImage *v5; // rbx
  int v6; // er15
  int v7; // er14
  int v8; // esi
  int v9; // edi
  int *v10; // rax
  Scaleform::Render::DrawableImageContext *v11; // rax
  __int64 v12; // rdx
  __int64 v13; // r8
  __int64 v14; // r9
  _QWORD *v15; // rax
  __int64 v16; // rdx
  __int64 v17; // r8
  _QWORD *v18; // rdi
  Scaleform::Render::DrawableImage *v19; // rcx
  int v20; // er8
  int v21; // edx
  int v22; // ecx
  Scaleform::Render::DICommandQueue *v23; // rbx
  Scaleform::Render::DICommand v24; // [rsp+38h] [rbp-28h]
  int v25; // [rsp+48h] [rbp-18h]
  int v26; // [rsp+4Ch] [rbp-14h]
  int v27; // [rsp+50h] [rbp-10h]
  int v28; // [rsp+54h] [rbp-Ch]
  unsigned int (*v29)[256]; // [rsp+58h] [rbp-8h]
  char v30; // [rsp+A0h] [rbp+40h]
  _QWORD *v31; // [rsp+A8h] [rbp+48h]
  _QWORD *v32; // [rsp+B0h] [rbp+50h]

  v3 = colors;
  v4 = rect;
  v5 = this;
  memset(colors, 0, 0x1000ui64);
  if ( v4 )
  {
    v6 = v4->y2;
    v7 = v4->x2;
    v8 = v4->y1;
    v9 = v4->x1;
  }
  else
  {
    v10 = (int *)v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v30);
    v6 = v10[1];
    v7 = *v10;
    v9 = 0;
    v8 = 0;
  }
  v24.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
  v24.pImage.pObject = v5;
  v24.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Histogram::`vftable;
  v25 = v9;
  v26 = v8;
  v27 = v7;
  v28 = v6;
  v29 = v3;
  v11 = v5->pContext.pObject;
  if ( v11 && v11->pControlContext )
    v11->pControlContext->DIChangesRequired = 1;
  if ( !Scaleform::Render::DICommand::ExecuteSWOnAddCommand(&v24, v5) )
  {
    v15 = Scaleform::Render::DICommandQueue::allocCommandFromPage(
            v5->pQueue.pObject,
            0x28u,
            &v5->pQueue.pObject->QueueLock);
    v18 = v15;
    v31 = v15;
    if ( v15 )
    {
      v32 = v15;
      *v15 = &Scaleform::Render::DICommand::`vftable;
      v19 = v24.pImage.pObject;
      if ( v24.pImage.pObject )
      {
        ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, __int64))v24.pImage.pObject->vfptr[1].__vecDelDtor)(
          v24.pImage.pObject,
          v16,
          v17);
        v19 = v24.pImage.pObject;
      }
      v18[1] = v19;
      *v18 = &Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Histogram,Scaleform::Render::DICommand>::`vftable;
      *v18 = &Scaleform::Render::DICommand_Histogram::`vftable;
      v20 = v28;
      v21 = v27;
      v22 = v26;
      *((_DWORD *)v18 + 4) = v25;
      *((_DWORD *)v18 + 5) = v22;
      *((_DWORD *)v18 + 6) = v21;
      *((_DWORD *)v18 + 7) = v20;
      v18[4] = v29;
    }
    if ( v24.vfptr->GetRenderCaps(&v24) & 0x10 )
    {
      v23 = v5->pQueue.pObject;
      _InterlockedExchangeAdd(&v23->RefCount, 1u);
      _InterlockedExchangeAdd(&v23->ExecuteCmd.pObject->RefCount, 1u);
      v23->pRTCommandQueue->vfptr->PushThreadCommand(
        v23->pRTCommandQueue,
        (Scaleform::Render::ThreadCommand *)v23->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(v23->ExecuteCmd.pObject);
    }
  }
  v24.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v24.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64, __int64, __int64))v24.pImage.pObject->vfptr[2].__vecDelDtor)(
      v24.pImage.pObject,
      v12,
      v13,
      v14);
}

// File Line: 893
// RVA: 0x9915C0
__int64 __fastcall Scaleform::Render::DrawableImage::HitTest(Scaleform::Render::DrawableImage *this, Scaleform::Render::Point<long> *firstPoint, Scaleform::Render::Rect<long> *secondImage, unsigned int alphaThreshold)
{
  unsigned int v4; // ebp
  Scaleform::Render::Rect<long> *v5; // rdi
  Scaleform::Render::Point<long> *v6; // rsi
  Scaleform::Render::DrawableImage *v7; // rbx
  int v8; // er8
  int v9; // edx
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 v12; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [rsp+30h] [rbp-68h]
  unsigned __int8 v15; // [rsp+B8h] [rbp+20h]

  v4 = alphaThreshold;
  v5 = secondImage;
  v6 = firstPoint;
  v7 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = v7;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_HitTest::`vftable;
  cmd.SecondImage.pObject = 0i64;
  v8 = v5->y2;
  v9 = v5->x2;
  v10 = v5->y1;
  cmd.SecondArea.x1 = v5->x1;
  cmd.SecondArea.y1 = v10;
  cmd.SecondArea.x2 = v9;
  cmd.SecondArea.y2 = v8;
  v11 = v6->y;
  cmd.FirstPoint.x = v6->x;
  cmd.FirstPoint.y = v11;
  cmd.FirstThreshold = v4;
  cmd.SecondThreshold = 0;
  cmd.Result = (bool *)&v15;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(v7, &cmd);
  v12 = v15;
  if ( cmd.SecondImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::Image *))cmd.SecondImage.pObject->vfptr[2].__vecDelDtor)(cmd.SecondImage.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v12;
}

// File Line: 906
// RVA: 0x9916C0
__int64 __fastcall Scaleform::Render::DrawableImage::HitTest(Scaleform::Render::DrawableImage *this, Scaleform::Render::ImageBase *secondImage, Scaleform::Render::Point<long> *firstPoint, Scaleform::Render::Point<long> *secondPoint, unsigned int firstThreshold, unsigned int secondThreshold)
{
  Scaleform::Render::Point<long> *v6; // rsi
  Scaleform::Render::Point<long> *v7; // r14
  Scaleform::Render::ImageBase *v8; // rdi
  Scaleform::Render::DrawableImage *v9; // rbx
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 v12; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [rsp+30h] [rbp-68h]
  unsigned __int8 v15; // [rsp+A0h] [rbp+8h]

  v6 = secondPoint;
  v7 = firstPoint;
  v8 = secondImage;
  v9 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = v9;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_HitTest::`vftable;
  if ( v8 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v8->vfptr[1].__vecDelDtor)(v8);
  *(_OWORD *)&cmd.SecondImage.pObject = (unsigned __int64)v8;
  *(_QWORD *)&cmd.SecondArea.x2 = 0i64;
  v10 = v7->y;
  cmd.FirstPoint.x = v7->x;
  cmd.FirstPoint.y = v10;
  v11 = v6->y;
  cmd.SecondPoint.x = v6->x;
  cmd.SecondPoint.y = v11;
  cmd.FirstThreshold = firstThreshold;
  cmd.SecondThreshold = secondThreshold;
  cmd.Result = (bool *)&v15;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(v9, &cmd);
  v12 = v15;
  if ( cmd.SecondImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::Image *))cmd.SecondImage.pObject->vfptr[2].__vecDelDtor)(cmd.SecondImage.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v12;
}

// File Line: 920
// RVA: 0x99A780
void __fastcall Scaleform::Render::DrawableImage::Merge(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, unsigned int redMult, unsigned int greenMult, unsigned int blueMult, unsigned int alphaMult)
{
  Scaleform::Render::Point<long> *v8; // r14
  Scaleform::Render::Rect<long> *v9; // rsi
  Scaleform::Render::DrawableImage *v10; // rdi
  Scaleform::Render::DrawableImage *v11; // rbx
  int v12; // er8
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  __int64 v16; // rdx
  Scaleform::Render::DICommand_Merge cmd; // [rsp+28h] [rbp-50h]

  v8 = destPoint;
  v9 = sourceRect;
  v10 = source;
  v11 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(
      this,
      source);
  cmd.pImage.pObject = v11;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v10 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v10->vfptr[1].__vecDelDtor)(v10);
  cmd.pSource.pObject = v10;
  v12 = v9->y2;
  v13 = v9->x2;
  v14 = v9->y1;
  cmd.SourceRect.x1 = v9->x1;
  cmd.SourceRect.y1 = v14;
  cmd.SourceRect.x2 = v13;
  cmd.SourceRect.y2 = v12;
  v15 = v8->y;
  cmd.DestPoint.x = v8->x;
  cmd.DestPoint.y = v15;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Merge::`vftable;
  cmd.RedMultiplier = redMult;
  cmd.GreenMultiplier = greenMult;
  cmd.BlueMultiplier = blueMult;
  cmd.AlphaMultiplier = alphaMult;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Merge>(v11, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pSource.pObject,
      v16);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v16);
}

// File Line: 928
// RVA: 0x99C6A0
void __fastcall Scaleform::Render::DrawableImage::Noise(Scaleform::Render::DrawableImage *this, __int64 randomSeed, unsigned int low, unsigned int high, unsigned int channelMask, bool grayscale)
{
  unsigned int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // ebp
  Scaleform::Render::DrawableImage *v9; // rbx
  __int64 v10; // rdx
  Scaleform::Render::DICommand_Noise cmd; // [rsp+28h] [rbp-30h]

  v6 = high;
  v7 = low;
  v8 = randomSeed;
  v9 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))this->vfptr[1].__vecDelDtor)(this, randomSeed);
  cmd.pImage.pObject = v9;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Noise::`vftable;
  cmd.RandomSeed = v8;
  cmd.Low = v7;
  cmd.High = v6;
  cmd.ChannelMask = channelMask;
  cmd.GrayScale = grayscale;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Noise>(v9, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v10);
}

// File Line: 936
// RVA: 0x99CF00
void __fastcall Scaleform::Render::DrawableImage::PaletteMap(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, unsigned int **channels)
{
  Scaleform::Render::DrawableImage *v5; // rbx
  Scaleform::Render::DICommand_PaletteMap *v6; // rax
  Scaleform::Render::DICommand_PaletteMap v7; // [rsp+38h] [rbp-50h]

  v5 = this;
  Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(&v7, this, source, sourceRect, destPoint, channels);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PaletteMap>(v5, v6);
  v7.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  if ( v7.Channels )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v7.Channels = 0i64;
  if ( v7.pSource.pObject )
    ((void (*)(void))v7.pSource.pObject->vfptr[2].__vecDelDtor)();
  v7.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v7.pImage.pObject )
    ((void (*)(void))v7.pImage.pObject->vfptr[2].__vecDelDtor)();
}

// File Line: 944
// RVA: 0x99EA70
void __fastcall Scaleform::Render::DrawableImage::PerlinNoise(Scaleform::Render::DrawableImage *this, float frequencyX, float frequencyY, unsigned int numOctaves, unsigned int randomSeed, bool stitch, bool fractal, unsigned int channelMask, bool grayScale, float *offsets, unsigned int offsetCount)
{
  Scaleform::Render::DrawableImage *v11; // rbx
  Scaleform::Render::DICommand_PerlinNoise *v12; // rax
  Scaleform::Render::DICommand_PerlinNoise v13; // [rsp+68h] [rbp-C0h]

  v11 = this;
  Scaleform::Render::DICommand_PerlinNoise::DICommand_PerlinNoise(
    &v13,
    this,
    frequencyX,
    frequencyY,
    numOctaves,
    randomSeed,
    stitch,
    fractal,
    channelMask,
    grayScale,
    offsets,
    offsetCount);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PerlinNoise>(v11, v12);
  v13.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v13.pImage.pObject )
    ((void (*)(void))v13.pImage.pObject->vfptr[2].__vecDelDtor)();
}

// File Line: 952
// RVA: 0x99EB30
__int64 __fastcall Scaleform::Render::DrawableImage::PixelDissolve(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, unsigned int randomSeed, unsigned int numPixels, Scaleform::Render::Color fill)
{
  Scaleform::Render::Point<long> *v7; // r15
  Scaleform::Render::Rect<long> *v8; // r14
  Scaleform::Render::DrawableImage *v9; // rsi
  Scaleform::Render::DrawableImage *v10; // rdi
  unsigned int v11; // ebx
  int v12; // er8
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // ebx
  Scaleform::Render::DICommand_PixelDissolve cmd; // [rsp+30h] [rbp-68h]

  v7 = destPoint;
  v8 = sourceRect;
  v9 = source;
  v10 = this;
  v11 = **(_DWORD **)&fill.Channels.Blue;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = v10;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PixelDissolve::`vftable;
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v9->vfptr[1].__vecDelDtor)(v9);
  cmd.pSource.pObject = v9;
  v12 = v8->y2;
  v13 = v8->x2;
  v14 = v8->y1;
  cmd.SourceRect.x1 = v8->x1;
  cmd.SourceRect.y1 = v14;
  cmd.SourceRect.x2 = v13;
  cmd.SourceRect.y2 = v12;
  v15 = v7->y;
  cmd.DestPoint.x = v7->x;
  cmd.DestPoint.y = v15;
  cmd.RandomSeed = randomSeed;
  cmd.NumPixels = numPixels;
  cmd.Fill.Raw = v11;
  cmd.Result = (unsigned int *)&fill;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PixelDissolve>(v10, &cmd);
  v16 = fill.Raw;
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v16;
}

// File Line: 963
// RVA: 0x9ADC10
void __fastcall Scaleform::Render::DrawableImage::Scroll(Scaleform::Render::DrawableImage *this, int x, int y)
{
  Scaleform::Render::DrawableImage *v3; // rbx
  Scaleform::Render::DICommand_Scroll *v4; // rax
  __int64 v5; // rdx
  Scaleform::Render::DICommand_Scroll v6; // [rsp+28h] [rbp-40h]

  v3 = this;
  Scaleform::Render::DICommand_Scroll::DICommand_Scroll(&v6, this, x, y);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Scroll>(v3, v4);
  if ( v6.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6.pSource.pObject->vfptr[2].__vecDelDtor)(v6.pSource.pObject);
  v6.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v6.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))v6.pImage.pObject->vfptr[2].__vecDelDtor)(
      v6.pImage.pObject,
      v5);
}

// File Line: 968
// RVA: 0x9B29A0
void __fastcall Scaleform::Render::DrawableImage::SetPixel(Scaleform::Render::DrawableImage *this, int x, int y, __int64 c)
{
  int v4; // edi
  int v5; // ebp
  Scaleform::Render::DrawableImage *v6; // rsi
  int v7; // ecx
  unsigned int v8; // ebx
  __int64 v9; // rdx
  Scaleform::Render::DICommand_SetPixel32 cmd; // [rsp+28h] [rbp-30h]

  v4 = y;
  v5 = x;
  v6 = this;
  v7 = this->ISize.Height - 1;
  if ( x <= (signed int)(v6->ISize.Width - 1) && x >= 0 && y <= v7 && y >= 0 )
  {
    v8 = *(_DWORD *)c;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
    cmd.pImage.pObject = v6;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable;
    cmd.X = v5;
    cmd.Y = v4;
    cmd.Fill.Raw = v8;
    cmd.OverwriteAlpha = 0;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(v6, &cmd);
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
        cmd.pImage.pObject,
        v9);
  }
}

// File Line: 975
// RVA: 0x9B28D0
void __fastcall Scaleform::Render::DrawableImage::SetPixel32(Scaleform::Render::DrawableImage *this, int x, int y, __int64 c)
{
  int v4; // edi
  int v5; // ebp
  Scaleform::Render::DrawableImage *v6; // rsi
  int v7; // ecx
  unsigned int v8; // ebx
  __int64 v9; // rdx
  Scaleform::Render::DICommand_SetPixel32 cmd; // [rsp+28h] [rbp-30h]

  v4 = y;
  v5 = x;
  v6 = this;
  v7 = this->ISize.Height - 1;
  if ( x <= (signed int)(v6->ISize.Width - 1) && x >= 0 && y <= v7 && y >= 0 )
  {
    v8 = *(_DWORD *)c;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
    cmd.pImage.pObject = v6;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable;
    cmd.X = v5;
    cmd.Y = v4;
    cmd.Fill.Raw = v8;
    cmd.OverwriteAlpha = 1;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(v6, &cmd);
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
        cmd.pImage.pObject,
        v9);
  }
}

// File Line: 983
// RVA: 0x9B2BA0
char __fastcall Scaleform::Render::DrawableImage::SetPixels(Scaleform::Render::DrawableImage *this, Scaleform::Render::Rect<long> *inputRect, Scaleform::Render::DIPixelProvider *provider)
{
  Scaleform::Render::DIPixelProvider *v3; // r15
  Scaleform::Render::DrawableImage *v4; // rbx
  int v5; // er14
  signed int v6; // esi
  int v7; // ebp
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  char v11; // bl
  Scaleform::Render::DICommand_SetPixels cmd; // [rsp+28h] [rbp-60h]
  char v14; // [rsp+90h] [rbp+8h]

  v3 = provider;
  v4 = this;
  v5 = this->ISize.Height;
  v6 = this->ISize.Width;
  v7 = inputRect->y1;
  if ( v5 < v7 )
    return 0;
  v8 = inputRect->y2;
  if ( v8 < 0 )
    return 0;
  v9 = inputRect->x2;
  if ( v9 < 0 )
    return 0;
  v10 = inputRect->x1;
  if ( v6 < inputRect->x1 )
    return 0;
  if ( v10 < 0 )
    v10 = 0;
  if ( v6 > v9 )
    v6 = inputRect->x2;
  if ( v7 < 0 )
    v7 = 0;
  if ( v5 > v8 )
    v5 = inputRect->y2;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
  cmd.pImage.pObject = v4;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixels::`vftable;
  cmd.DestRect.x1 = v10;
  cmd.DestRect.y1 = v7;
  cmd.DestRect.x2 = v6;
  cmd.DestRect.y2 = v5;
  cmd.Provider = v3;
  cmd.Result = (bool *)&v14;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(v4, &cmd);
  v11 = v14;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::RefCountImplCoreVtbl *))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      cmd.pImage.pObject->vfptr);
  return v11;
}

// File Line: 1002
// RVA: 0x9B9DD0
void __fastcall Scaleform::Render::DrawableImage::Threshold(Scaleform::Render::DrawableImage *this, Scaleform::Render::DrawableImage *source, Scaleform::Render::Rect<long> *sourceRect, Scaleform::Render::Point<long> *destPoint, Scaleform::Render::DrawableImage::OperationType op, unsigned int threshold, unsigned int color, unsigned int mask, bool copySource)
{
  Scaleform::Render::Point<long> *v9; // r14
  Scaleform::Render::Rect<long> *v10; // rsi
  Scaleform::Render::DrawableImage *v11; // rdi
  Scaleform::Render::DrawableImage *v12; // rbx
  int v13; // er8
  int v14; // edx
  int v15; // ecx
  int v16; // ecx
  __int64 v17; // rdx
  Scaleform::Render::DICommand_Threshold cmd; // [rsp+28h] [rbp-50h]

  v9 = destPoint;
  v10 = sourceRect;
  v11 = source;
  v12 = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(
      this,
      source);
  cmd.pImage.pObject = v12;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( v11 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v11->vfptr[1].__vecDelDtor)(v11);
  cmd.pSource.pObject = v11;
  v13 = v10->y2;
  v14 = v10->x2;
  v15 = v10->y1;
  cmd.SourceRect.x1 = v10->x1;
  cmd.SourceRect.y1 = v15;
  cmd.SourceRect.x2 = v14;
  cmd.SourceRect.y2 = v13;
  v16 = v9->y;
  cmd.DestPoint.x = v9->x;
  cmd.DestPoint.y = v16;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Threshold::`vftable;
  cmd.Operation = op;
  cmd.Threshold = threshold;
  cmd.ThresholdColor = color;
  cmd.Mask = mask;
  cmd.CopySource = copySource;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Threshold>(v12, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(
      cmd.pSource.pObject,
      v17);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *, __int64))cmd.pImage.pObject->vfptr[2].__vecDelDtor)(
      cmd.pImage.pObject,
      v17);
}

