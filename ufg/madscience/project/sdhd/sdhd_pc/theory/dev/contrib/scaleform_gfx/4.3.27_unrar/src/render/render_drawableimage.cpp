// File Line: 37
// RVA: 0x93B710
void __fastcall Scaleform::Render::DrawableImageContext::DrawableImageContext(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::Context *controlContext,
        Scaleform::Render::ThreadCommandQueue *commandQueue,
        Scaleform::Render::Interfaces *i)
{
  Scaleform::Render::DICommandQueue *v6; // rsi
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::Render::ContextImpl::Context *v8; // rax
  Scaleform::Render::DICommandQueue *v9; // rax
  Scaleform::Render::DICommandQueue *v10; // rax
  Scaleform::Render::DICommandQueue *pObject; // rcx
  Scaleform::Render::ContextImpl::Context *pControlContext; // rcx
  void *p_TreeRootKillList; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::ArrayLH<Scaleform::Render::TreeRoot *,2,Scaleform::ArrayDefaultPolicy> *v14; // [rsp+60h] [rbp+18h]

  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::`vftable;
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  v6 = 0i64;
  this->pOwnedContext = 0i64;
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>};
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::Render::ContextImpl::ContextCaptureNotify};
  this->RContext = 0i64;
  this->pControlContext = controlContext;
  this->pRTCommandQueue = commandQueue;
  Scaleform::Lock::Lock(&this->TreeRootKillListLock, 0);
  p_TreeRootKillList = &this->TreeRootKillList;
  v14 = &this->TreeRootKillList;
  this->TreeRootKillList.Data.Data = 0i64;
  this->TreeRootKillList.Data.Size = 0i64;
  this->TreeRootKillList.Data.Policy.Capacity = 0i64;
  this->Queue.pObject = 0i64;
  this->IDefaults = *i;
  p_TreeRootKillList = this->RContextBacking;
  if ( this == (Scaleform::Render::DrawableImageContext *)-56i64 )
  {
    v8 = 0i64;
  }
  else
  {
    v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::ContextImpl::Context::Context(
      (Scaleform::Render::ContextImpl::Context *)this->RContextBacking,
      v7);
  }
  this->RContext = v8;
  LODWORD(p_TreeRootKillList) = 2;
  v9 = (Scaleform::Render::DICommandQueue *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::DrawableImageContext *, __int64, void **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              240i64,
                                              &p_TreeRootKillList,
                                              -2i64);
  v14 = (Scaleform::ArrayLH<Scaleform::Render::TreeRoot *,2,Scaleform::ArrayDefaultPolicy> *)v9;
  if ( v9 )
  {
    Scaleform::Render::DICommandQueue::DICommandQueue(v9, this);
    v6 = v10;
  }
  pObject = this->Queue.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->Queue.pObject = v6;
  pControlContext = this->pControlContext;
  if ( pControlContext )
    Scaleform::Render::ContextImpl::Context::AddCaptureNotify(
      pControlContext,
      &this->Scaleform::Render::ContextImpl::ContextCaptureNotify);
}

// File Line: 45
// RVA: 0x949E70
void __fastcall Scaleform::Render::DrawableImageContext::~DrawableImageContext(
        Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::ContextImpl::Context *pControlContext; // rcx
  Scaleform::Render::DICommandQueue *pObject; // rcx
  Scaleform::Render::ContextImpl::Context *pOwnedContext; // rcx

  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>};
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::DrawableImageContext::`vftable{for `Scaleform::Render::ContextImpl::ContextCaptureNotify};
  if ( this->RContext )
  {
    Scaleform::Render::DrawableImageContext::processTreeRootKillList(this);
    Scaleform::Render::ContextImpl::Context::~Context(this->RContext);
    this->RContext = 0i64;
  }
  pControlContext = this->pControlContext;
  if ( pControlContext )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
      pControlContext,
      &this->Scaleform::Render::ContextImpl::ContextCaptureNotify);
  pObject = this->Queue.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->TreeRootKillList.Data.Data);
  DeleteCriticalSection(&this->TreeRootKillListLock.cs);
  this->Scaleform::Render::ContextImpl::ContextCaptureNotify::vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  pOwnedContext = this->pOwnedContext;
  if ( pOwnedContext )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
      pOwnedContext,
      &this->Scaleform::Render::ContextImpl::ContextCaptureNotify);
  this->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 74
// RVA: 0x99C9C0
void __fastcall Scaleform::Render::DrawableImageContext::OnCapture(Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Render::ContextImpl::Context *pNext; // rcx
  Scaleform::Render::DICommandQueue *Size; // rcx

  pNext = (Scaleform::Render::ContextImpl::Context *)this->pNext;
  if ( pNext )
    Scaleform::Render::ContextImpl::Context::Capture(pNext);
  Size = (Scaleform::Render::DICommandQueue *)this->TreeRootKillList.Data.Size;
  if ( Size )
    Scaleform::Render::DICommandQueue::OnCapture(Size);
  Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)this - 16));
}

// File Line: 83
// RVA: 0x99CB70
void __fastcall Scaleform::Render::DrawableImageContext::OnNextCapture(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::ContextImpl::Context *pNext; // rbx
  Scaleform::Render::ContextImpl::Context *v5; // rcx
  Scaleform::Render::DICommandQueue *Size; // rbx
  Scaleform::Render::ContextImpl::Snapshot *updateSnapshot; // [rsp+30h] [rbp+8h] BYREF

  pNext = (Scaleform::Render::ContextImpl::Context *)this->pNext;
  if ( pNext )
  {
    v5 = (Scaleform::Render::ContextImpl::Context *)this->pNext;
    updateSnapshot = 0i64;
    Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(v5, &updateSnapshot, notify, Capture_Immediate);
    if ( updateSnapshot )
      Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(pNext, updateSnapshot, notify);
  }
  Size = (Scaleform::Render::DICommandQueue *)this->TreeRootKillList.Data.Size;
  if ( Size )
  {
    _InterlockedExchangeAdd(&Size->RefCount, 1u);
    Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(Size);
    Scaleform::Render::DICommandQueue::ExecuteNextCapture(Size, notify);
    if ( !_InterlockedDecrement(&Size->RefCount) )
      Size->vfptr->__vecDelDtor(Size, 1u);
  }
}

// File Line: 91
// RVA: 0x99CC20
void __fastcall Scaleform::Render::DrawableImageContext::OnShutdown(
        Scaleform::Render::DrawableImageContext *this,
        bool waitFlag)
{
  Scaleform::Render::DICommandQueue *Size; // rdi
  unsigned __int64 v5; // rcx
  bool v6; // zf
  Scaleform::Render::ContextImpl::Context *pNext; // rcx

  Size = (Scaleform::Render::DICommandQueue *)this->TreeRootKillList.Data.Size;
  if ( Size )
  {
    if ( waitFlag )
    {
      _InterlockedExchangeAdd(&Size->RefCount, 1u);
      _InterlockedExchangeAdd(&Size->ExecuteCmd.pObject->RefCount, 1u);
      Size->pRTCommandQueue->vfptr->PushThreadCommand(Size->pRTCommandQueue, Size->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(Size->ExecuteCmd.pObject);
    }
    else
    {
      Scaleform::Render::DICommandQueue::DiscardCommands(Size);
    }
    v5 = this->TreeRootKillList.Data.Size;
    if ( v5 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) )
      (**(void (__fastcall ***)(unsigned __int64, __int64))v5)(v5, 1i64);
    this->TreeRootKillList.Data.Size = 0i64;
  }
  v6 = this->pNext == 0i64;
  *(_QWORD *)&this->RContextBacking[256] = 0i64;
  if ( !v6 )
  {
    Scaleform::Render::DrawableImageContext::processTreeRootKillList((Scaleform::Render::DrawableImageContext *)((char *)this - 16));
    pNext = (Scaleform::Render::ContextImpl::Context *)this->pNext;
    if ( waitFlag )
    {
      Scaleform::Render::ContextImpl::Context::~Context(pNext);
      this->pNext = 0i64;
    }
    else
    {
      Scaleform::Render::ContextImpl::Context::Shutdown(pNext, 0);
    }
  }
}

// File Line: 125
// RVA: 0x974360
void __fastcall Scaleform::Render::DrawableImageContext::ExecuteNextCapture(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::ContextImpl::Context *RContext; // rbx
  Scaleform::Render::ContextImpl::Context *v4; // rcx
  Scaleform::Render::ContextImpl::Snapshot *updateSnapshot; // [rsp+30h] [rbp+8h] BYREF

  RContext = this->RContext;
  if ( RContext )
  {
    v4 = this->RContext;
    updateSnapshot = 0i64;
    Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(v4, &updateSnapshot, notify, Capture_Immediate);
    if ( updateSnapshot )
      Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(RContext, updateSnapshot, notify);
  }
}

// File Line: 131
// RVA: 0x9EDCB0
void __fastcall Scaleform::Render::DrawableImageContext::processTreeRootKillList(
        Scaleform::Render::DrawableImageContext *this)
{
  Scaleform::Lock *p_TreeRootKillListLock; // rbx
  unsigned __int64 i; // rsi
  Scaleform::Render::TreeRoot *v4; // rcx

  if ( this->RContext )
  {
    p_TreeRootKillListLock = &this->TreeRootKillListLock;
    EnterCriticalSection(&this->TreeRootKillListLock.cs);
    for ( i = 0i64; i < this->TreeRootKillList.Data.Size; ++i )
    {
      v4 = this->TreeRootKillList.Data.Data[i];
      if ( v4->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
    }
    if ( this->TreeRootKillList.Data.Size && (this->TreeRootKillList.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( this->TreeRootKillList.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        this->TreeRootKillList.Data.Data = 0i64;
      }
      this->TreeRootKillList.Data.Policy.Capacity = 0i64;
    }
    this->TreeRootKillList.Data.Size = 0i64;
    LeaveCriticalSection(&p_TreeRootKillListLock->cs);
  }
}

// File Line: 144
// RVA: 0x954C90
void __fastcall Scaleform::Render::DrawableImageContext::AddTreeRootToKillList(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::GFx::AS2::Object *proot)
{
  Scaleform::Lock *p_TreeRootKillListLock; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_TreeRootKillList; // rdi
  unsigned __int64 Size; // rax
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // r8
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v9; // rcx

  p_TreeRootKillListLock = &this->TreeRootKillListLock;
  EnterCriticalSection(&this->TreeRootKillListLock.cs);
  p_TreeRootKillList = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->TreeRootKillList;
  Size = p_TreeRootKillList->Size;
  v7 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v7 <= p_TreeRootKillList->Policy.Capacity )
      goto LABEL_7;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= p_TreeRootKillList->Policy.Capacity >> 1 )
      goto LABEL_7;
    v8 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_TreeRootKillList,
    p_TreeRootKillList,
    v8);
LABEL_7:
  p_TreeRootKillList->Size = v7;
  v9 = &p_TreeRootKillList->Data[v7 - 1];
  if ( v9 )
    v9->pObject = proot;
  LeaveCriticalSection(&p_TreeRootKillListLock->cs);
}

// File Line: 169
// RVA: 0x93B5D0
void __fastcall Scaleform::Render::DrawableImage::DrawableImage(
        Scaleform::Render::DrawableImage *this,
        bool transparent,
        Scaleform::Render::ImageBase *originalData,
        Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::ImageData *p_MappedData; // rax
  Scaleform::Render::ImagePlane *p_Plane0; // rcx
  Scaleform::Render::Size<unsigned long> *v9; // rbx
  Scaleform::Render::ImageFormat v10; // eax
  char v11; // [rsp+78h] [rbp+20h] BYREF

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
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  this->DrawableImageState = 0;
  this->Transparent = transparent;
  this->pQueue.pObject = 0i64;
  p_MappedData = &this->MappedData;
  *(_QWORD *)&this->MappedData.Format = 0i64;
  *(_DWORD *)&this->MappedData.Flags = 0x10000;
  p_Plane0 = &this->MappedData.Plane0;
  p_MappedData->pPlanes = p_Plane0;
  p_MappedData->pPalette.pObject = 0i64;
  *(_QWORD *)&p_Plane0->Width = 0i64;
  p_Plane0->Pitch = 0i64;
  p_Plane0->DataSize = 0i64;
  p_Plane0->pData = 0i64;
  this->pCPUModifiedNext.pObject = 0i64;
  this->pGPUModifiedNext.pObject = 0i64;
  if ( originalData )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))originalData->vfptr[1].__vecDelDtor)(originalData);
  this->pDelegateImage.pObject = originalData;
  if ( dicontext )
    _InterlockedExchangeAdd(&dicontext->RefCount, 1u);
  this->pContext.pObject = dicontext;
  this->pRT.pObject = 0i64;
  this->pFence.pObject = 0i64;
  v9 = (Scaleform::Render::Size<unsigned long> *)originalData->vfptr[5].__vecDelDtor(originalData, &v11);
  v10 = ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))originalData->vfptr[4].__vecDelDtor)(originalData);
  Scaleform::Render::DrawableImage::initialize(this, v10, v9, dicontext);
}

// File Line: 181
// RVA: 0x93B450
void __fastcall Scaleform::Render::DrawableImage::DrawableImage(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> size,
        bool transparent,
        __int64 fillColor,
        Scaleform::Render::DrawableImageContext *dicontext)
{
  unsigned int v7; // ebx
  Scaleform::Render::DICommand_Clear cmd; // [rsp+30h] [rbp-28h] BYREF

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
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  this->DrawableImageState = 0;
  this->Transparent = transparent;
  this->pQueue.pObject = 0i64;
  *(_QWORD *)&this->MappedData.Format = 0i64;
  *(_DWORD *)&this->MappedData.Flags = 0x10000;
  this->MappedData.pPlanes = &this->MappedData.Plane0;
  this->MappedData.pPalette.pObject = 0i64;
  *(_QWORD *)&this->MappedData.Plane0.Width = 0i64;
  this->MappedData.Plane0.Pitch = 0i64;
  this->MappedData.Plane0.DataSize = 0i64;
  this->MappedData.Plane0.pData = 0i64;
  this->pCPUModifiedNext.pObject = 0i64;
  this->pGPUModifiedNext.pObject = 0i64;
  this->pDelegateImage.pObject = 0i64;
  this->pContext.pObject = 0i64;
  this->pRT.pObject = 0i64;
  this->pFence.pObject = 0i64;
  Scaleform::Render::DrawableImage::initialize(
    this,
    format,
    *(Scaleform::Render::Size<unsigned long> **)&size,
    dicontext);
  if ( !this->Transparent )
    *(_BYTE *)(fillColor + 3) = -1;
  v7 = *(_DWORD *)fillColor;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Clear::`vftable;
  cmd.FillColor.Raw = v7;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Clear>(this, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Clear,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 200
// RVA: 0x971E10
void __fastcall Scaleform::Render::DestroyDrawableImageThreadCommand::Execute(
        Scaleform::Render::DestroyDrawableImageThreadCommand *this)
{
  Scaleform::Render::DrawableImage *pDrawableImage; // rcx

  pDrawableImage = this->pDrawableImage;
  if ( pDrawableImage )
    pDrawableImage->vfptr->__vecDelDtor(pDrawableImage, 1u);
}

// File Line: 208
// RVA: 0x9A76B0
void __fastcall Scaleform::Render::DrawableImage::Release(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::ImageBase *pObject; // rcx
  Scaleform::Render::DrawableImageContext *v3; // rdi
  __int64 pTextureManager; // rax
  __int64 pHAL; // rax
  __int64 pRenderer2D; // rax
  void *RenderThreadID; // rax
  Scaleform::Render::ThreadCommand *v8; // rdi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  Scaleform::Render::DrawableImage *v10; // rcx
  __int64 v11; // [rsp+28h] [rbp-40h] BYREF
  __int64 v12; // [rsp+30h] [rbp-38h]
  __int64 v13; // [rsp+38h] [rbp-30h]
  void *v14; // [rsp+40h] [rbp-28h]

  if ( !_InterlockedDecrement(&this->RefCount) )
  {
    pObject = this->pDelegateImage.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))pObject->vfptr[2].__vecDelDtor)(pObject);
    this->pDelegateImage.pObject = 0i64;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0i64;
    v14 = 0i64;
    v3 = this->pContext.pObject;
    v3->pRTCommandQueue->vfptr->GetRenderInterfaces(v3->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v11);
    pTextureManager = v11;
    if ( v3->IDefaults.pTextureManager )
      pTextureManager = (__int64)v3->IDefaults.pTextureManager;
    v11 = pTextureManager;
    pHAL = v12;
    if ( v3->IDefaults.pHAL )
      pHAL = (__int64)v3->IDefaults.pHAL;
    v12 = pHAL;
    pRenderer2D = v13;
    if ( v3->IDefaults.pRenderer2D )
      pRenderer2D = (__int64)v3->IDefaults.pRenderer2D;
    v13 = pRenderer2D;
    RenderThreadID = v14;
    if ( v3->IDefaults.RenderThreadID )
      RenderThreadID = v3->IDefaults.RenderThreadID;
    v14 = RenderThreadID;
    if ( RenderThreadID == UFG::qGetCurrentThreadID() || !v14 )
    {
      vfptr = this->vfptr;
      v10 = this;
      goto LABEL_21;
    }
    v8 = (Scaleform::Render::ThreadCommand *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               24i64,
                                               0i64);
    if ( v8 )
    {
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v8->RefCount = 1;
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable;
      v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DestroyDrawableImageThreadCommand::`vftable;
      v8[1].vfptr = (Scaleform::RefCountImplCoreVtbl *)this;
    }
    else
    {
      v8 = 0i64;
    }
    this->pContext.pObject->pRTCommandQueue->vfptr->PushThreadCommand(this->pContext.pObject->pRTCommandQueue, v8);
    if ( v8 && !_InterlockedDecrement(&v8->RefCount) )
    {
      vfptr = v8->vfptr;
      v10 = (Scaleform::Render::DrawableImage *)v8;
LABEL_21:
      vfptr->__vecDelDtor(v10, 1u);
    }
  }
}

// File Line: 237
// RVA: 0x949C10
void __fastcall Scaleform::Render::DrawableImage::~DrawableImage(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rbx
  __int64 pTextureManager; // rax
  __int64 pHAL; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  Scaleform::Render::Fence *v7; // r8
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *v9; // r8
  Scaleform::Render::FenceImpl *v10; // r8
  Scaleform::Render::Fence *v11; // rcx
  Scaleform::Render::RenderTarget *v12; // rcx
  Scaleform::Render::DrawableImageContext *v13; // rcx
  Scaleform::Render::ImageBase *v14; // rcx
  Scaleform::Render::DrawableImage *v15; // rcx
  Scaleform::Render::DrawableImage *v16; // rcx
  char Flags; // al
  Scaleform::Render::Palette *v18; // rdx
  Scaleform::Render::DICommandQueue *v19; // rcx
  __int64 v20; // [rsp+28h] [rbp-40h] BYREF
  __int64 v21; // [rsp+30h] [rbp-38h]
  __int64 v22; // [rsp+38h] [rbp-30h]
  __int64 v23; // [rsp+40h] [rbp-28h]
  Scaleform::Lock *lpCriticalSection; // [rsp+78h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DrawableImage::`vftable;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0i64;
  pObject = this->pContext.pObject;
  pObject->pRTCommandQueue->vfptr->GetRenderInterfaces(pObject->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v20);
  pTextureManager = v20;
  if ( pObject->IDefaults.pTextureManager )
    pTextureManager = (__int64)pObject->IDefaults.pTextureManager;
  v20 = pTextureManager;
  pHAL = v21;
  if ( pObject->IDefaults.pHAL )
    pHAL = (__int64)pObject->IDefaults.pHAL;
  v21 = pHAL;
  pRenderer2D = v22;
  if ( pObject->IDefaults.pRenderer2D )
    pRenderer2D = (__int64)pObject->IDefaults.pRenderer2D;
  v22 = pRenderer2D;
  RenderThreadID = v23;
  if ( pObject->IDefaults.RenderThreadID )
    RenderThreadID = (__int64)pObject->IDefaults.RenderThreadID;
  v23 = RenderThreadID;
  if ( (this->DrawableImageState & 3) != 0 )
  {
    lpCriticalSection = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&lpCriticalSection->cs);
    if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
    {
      ((void (__fastcall *)(Scaleform::Render::Texture *volatile))this->pTexture.Value->Scaleform::Render::Image::vfptr[14].__vecDelDtor)(this->pTexture.Value);
      this->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(&lpCriticalSection->cs);
  }
  v7 = this->pFence.pObject;
  if ( v7 )
  {
    if ( v7->HasData )
    {
      Data = v7->Data;
      if ( Data )
      {
        if ( Data->Parent )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[4].__vecDelDtor)(
                 Data->RSContext,
                 1i64,
                 Data->APIHandle) )
          {
            v9 = this->pFence.pObject;
            if ( v9->HasData )
            {
              v10 = v9->Data;
              if ( v10 )
              {
                if ( v10->Parent )
                  ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))v10->RSContext->vfptr[5].__vecDelDtor)(
                    v10->RSContext,
                    1i64,
                    v10->APIHandle);
              }
            }
          }
        }
      }
    }
  }
  v11 = this->pFence.pObject;
  if ( v11 )
    Scaleform::Render::Fence::Release(v11);
  v12 = this->pRT.pObject;
  if ( v12 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v12->vfptr[2].__vecDelDtor)(v12);
  v13 = this->pContext.pObject;
  if ( v13 && !_InterlockedDecrement(&v13->RefCount) )
    v13->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      v13,
      1u);
  v14 = this->pDelegateImage.pObject;
  if ( v14 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v14->vfptr[2].__vecDelDtor)(v14);
  v15 = this->pGPUModifiedNext.pObject;
  if ( v15 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v15->vfptr[2].__vecDelDtor)(v15);
  v16 = this->pCPUModifiedNext.pObject;
  if ( v16 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v16->vfptr[2].__vecDelDtor)(v16);
  Flags = this->MappedData.Flags;
  if ( (Flags & 2) != 0 )
  {
    this->MappedData.Flags = Flags & 0xFD;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->MappedData.pPlanes);
  }
  this->MappedData.pPlanes = &this->MappedData.Plane0;
  v18 = this->MappedData.pPalette.pObject;
  if ( v18 && !_InterlockedDecrement(&v18->RefCount.Value) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v19 = this->pQueue.pObject;
  if ( v19 && !_InterlockedDecrement(&v19->RefCount) )
    v19->vfptr->__vecDelDtor(v19, 1u);
  Scaleform::Render::Image::~Image(this);
}

// File Line: 256
// RVA: 0x999390
char __fastcall Scaleform::Render::DrawableImage::MapImageSource(
        Scaleform::Render::ImageData *data,
        Scaleform::Render::DrawableImage *i)
{
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  int v5; // eax
  bool v6; // bl
  Scaleform::Render::ImageData *MappedData; // rax
  __int64 v9; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  if ( data && i )
  {
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::DrawableImage *))i->vfptr[3].__vecDelDtor)(i) == 6 )
    {
      if ( (i->DrawableImageState & 3) != 0 )
      {
LABEL_15:
        MappedData = Scaleform::Render::DrawableImage::getMappedData(i);
        Scaleform::Render::ImageData::operator=(data, MappedData);
        return 1;
      }
      p_cs = &i->pQueue.pObject->QueueLock.cs;
      lpCriticalSection = p_cs;
      EnterCriticalSection(p_cs);
      if ( Scaleform::Render::DrawableImage::MapImageSource(&i->MappedData, i->pDelegateImage.pObject) )
      {
        v5 = i->DrawableImageState | 2;
        goto LABEL_13;
      }
      if ( !i->pDelegateImage.pObject || Scaleform::Render::DrawableImage::ensureRenderableRT(i) )
      {
        if ( !i->pTexture.Value
          || !((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::ImageData *, _QWORD, _QWORD, __int64))i->pTexture.Value->Scaleform::Render::Image::vfptr[13].__vecDelDtor)(
                i->pTexture.Value,
                &i->MappedData,
                0i64,
                0i64,
                -2i64) )
        {
LABEL_14:
          v6 = (i->DrawableImageState & 3) != 0;
          LeaveCriticalSection(lpCriticalSection);
          if ( v6 )
            goto LABEL_15;
          return 0;
        }
        v5 = i->DrawableImageState | 3;
LABEL_13:
        i->DrawableImageState = v5;
        goto LABEL_14;
      }
      LeaveCriticalSection(p_cs);
    }
    else if ( ((unsigned int (__fastcall *)(Scaleform::Render::DrawableImage *))i->vfptr[3].__vecDelDtor)(i) == 2 )
    {
      v9 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))i->vfptr[9].__vecDelDtor)(i);
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 32i64))(v9) == 2
        || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 32i64))(v9) == 1 )
      {
        Scaleform::Render::ImageData::operator=(data, (Scaleform::Render::ImageData *)(v9 + 40));
        return 1;
      }
    }
  }
  return 0;
}

// File Line: 292
// RVA: 0x9E8660
void __fastcall Scaleform::Render::DrawableImage::initialize(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DrawableImageContext *pObject; // rcx
  Scaleform::Render::RenderTarget *v9; // rcx
  Scaleform::Render::DrawableImageContext *v10; // rdi
  Scaleform::Render::TextureManager *pTextureManager; // rax
  Scaleform::Render::HAL *v12; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  unsigned int Height; // ecx
  Scaleform::Render::DrawableImage *v16; // rcx
  Scaleform::Render::DrawableImage *v17; // rcx
  Scaleform::Render::DICommandQueue *v18; // rcx
  Scaleform::Render::DICommandQueue *v19; // rcx
  Scaleform::Render::DICommand_CreateTexture cmd; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::Render::TextureManager *tmanager; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Render::HAL *phal; // [rsp+40h] [rbp-38h]
  __int64 v23; // [rsp+48h] [rbp-30h]
  __int64 v24; // [rsp+50h] [rbp-28h]

  if ( dicontext )
    _InterlockedExchangeAdd(&dicontext->RefCount, 1u);
  pObject = this->pContext.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::DrawableImageContext,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  this->pContext.pObject = dicontext;
  v9 = this->pRT.pObject;
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v9->vfptr[2].__vecDelDtor)(v9);
  this->pRT.pObject = 0i64;
  tmanager = 0i64;
  phal = 0i64;
  v23 = 0i64;
  v24 = 0i64;
  v10 = this->pContext.pObject;
  v10->pRTCommandQueue->vfptr->GetRenderInterfaces(v10->pRTCommandQueue, (Scaleform::Render::Interfaces *)&tmanager);
  pTextureManager = tmanager;
  if ( v10->IDefaults.pTextureManager )
    pTextureManager = v10->IDefaults.pTextureManager;
  tmanager = pTextureManager;
  v12 = phal;
  if ( v10->IDefaults.pHAL )
    v12 = v10->IDefaults.pHAL;
  phal = v12;
  pRenderer2D = v23;
  if ( v10->IDefaults.pRenderer2D )
    pRenderer2D = (__int64)v10->IDefaults.pRenderer2D;
  v23 = pRenderer2D;
  RenderThreadID = v24;
  if ( v10->IDefaults.RenderThreadID )
    RenderThreadID = (__int64)v10->IDefaults.RenderThreadID;
  v24 = RenderThreadID;
  this->Format = format;
  Height = size->Height;
  this->ISize.Width = size->Width;
  this->ISize.Height = Height;
  v16 = this->pCPUModifiedNext.pObject;
  if ( v16 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v16->vfptr[2].__vecDelDtor)(v16);
  this->pCPUModifiedNext.pObject = 0i64;
  v17 = this->pGPUModifiedNext.pObject;
  if ( v17 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v17->vfptr[2].__vecDelDtor)(v17);
  this->pGPUModifiedNext.pObject = 0i64;
  v18 = dicontext->Queue.pObject;
  if ( v18 )
    _InterlockedExchangeAdd(&v18->RefCount, 1u);
  v19 = this->pQueue.pObject;
  if ( v19 && !_InterlockedDecrement(&v19->RefCount) )
    v19->vfptr->__vecDelDtor(v19, 1u);
  this->pQueue.pObject = dicontext->Queue.pObject;
  if ( !this->pDelegateImage.pObject )
  {
    if ( tmanager
      && ((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *))tmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[7].__vecDelDtor)(tmanager) )
    {
      Scaleform::Render::DrawableImage::createTextureFromManager(this, phal, tmanager);
    }
    else
    {
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
      cmd.pImage.pObject = this;
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CreateTexture::`vftable;
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CreateTexture>(this, &cmd);
      cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( cmd.pImage.pObject )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_CreateTexture,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
    }
  }
}

// File Line: 338
// RVA: 0x9CA7B0
void __fastcall Scaleform::Render::DrawableImage::addToCPUModifiedList(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rax
  Scaleform::Render::DICommandQueue *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DICommandQueue *v6; // rdi
  Scaleform::Render::DrawableImage *v7; // rcx
  Scaleform::Lock *p_QueueLock; // [rsp+40h] [rbp+8h]

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  pObject = this->pContext.pObject;
  if ( pObject && pObject->pControlContext )
    pObject->pControlContext->DIChangesRequired = 1;
  if ( (this->DrawableImageState & 8) == 0 )
  {
    this->DrawableImageState |= 8u;
    v3 = this->pQueue.pObject;
    v4 = v3->pCPUModifiedImageList.pObject;
    if ( v4 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
    v5 = this->pCPUModifiedNext.pObject;
    if ( v5 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
    this->pCPUModifiedNext.pObject = v3->pCPUModifiedImageList.pObject;
    v6 = this->pQueue.pObject;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
    v7 = v6->pCPUModifiedImageList.pObject;
    if ( v7 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v7);
    v6->pCPUModifiedImageList.pObject = this;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}

// File Line: 355
// RVA: 0x9CA870
void __fastcall Scaleform::Render::DrawableImage::addToGPUModifiedListRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rax
  Scaleform::Render::DICommandQueue *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DICommandQueue *v6; // rdi
  Scaleform::Render::DrawableImage *v7; // rcx
  Scaleform::Lock *p_QueueLock; // [rsp+40h] [rbp+8h]

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  pObject = this->pContext.pObject;
  if ( pObject && pObject->pControlContext )
    pObject->pControlContext->DIChangesRequired = 1;
  if ( (this->DrawableImageState & 0x10) == 0 )
  {
    this->DrawableImageState |= 0x10u;
    v3 = this->pQueue.pObject;
    v4 = v3->pGPUModifiedImageList.pObject;
    if ( v4 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
    v5 = this->pGPUModifiedNext.pObject;
    if ( v5 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
    this->pGPUModifiedNext.pObject = v3->pGPUModifiedImageList.pObject;
    v6 = this->pQueue.pObject;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
    v7 = v6->pGPUModifiedImageList.pObject;
    if ( v7 )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v7);
    v6->pGPUModifiedImageList.pObject = this;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}

// File Line: 372
// RVA: 0x9DEBE0
bool __fastcall Scaleform::Render::DrawableImage::createTextureFromManager(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::HAL *phal,
        Scaleform::Render::TextureManager *tmanager)
{
  unsigned int Width; // eax
  unsigned int Height; // r9d
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  unsigned int v9; // eax
  Scaleform::Render::DrawableImage *pObject; // rcx
  Scaleform::Render::Texture *v11; // rax
  __int64 v12; // rax
  Scaleform::Render::RenderTarget *v13; // rcx
  Scaleform::Render::RenderTarget *v14; // rbx
  unsigned int v16; // [rsp+60h] [rbp+8h] BYREF
  unsigned int v17; // [rsp+64h] [rbp+Ch]

  Width = this->ISize.Width;
  Height = this->ISize.Height;
  vfptr = tmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
  if ( !Width )
    Width = 1;
  if ( !Height )
    Height = 1;
  v16 = Width;
  v17 = Height;
  v9 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))vfptr[13].__vecDelDtor)(tmanager);
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64))vfptr[4].__vecDelDtor)(
          tmanager,
          v9,
          1152i64) )
  {
    v16 = (((((((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 4) | ((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 8) | ((((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 4) | ((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1) | ((((((((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 4) | ((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 8) | ((((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 4) | ((((v16 - 1) >> 1) | (v16 - 1)) >> 2) | ((v16 - 1) >> 1) | (v16 - 1)) >> 16))
        + 1;
    v17 = (((((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 8) | ((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1) | ((((((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 8) | ((((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 4) | ((((v17 - 1) >> 1) | (v17 - 1)) >> 2) | ((v17 - 1) >> 1) | (v17 - 1)) >> 16))
        + 1;
  }
  pObject = this;
  if ( this->pDelegateImage.pObject )
    pObject = (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject;
  v11 = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64, unsigned int *, int, Scaleform::Render::DrawableImage *, _QWORD))tmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(
                                        tmanager,
                                        (unsigned int)this->Format,
                                        1i64,
                                        &v16,
                                        1152,
                                        pObject,
                                        0i64);
  if ( v11 )
  {
    this->pTexture.Value = v11;
    v12 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture *, __int64))phal->vfptr[21].__vecDelDtor)(
            phal,
            v11,
            1i64);
    v13 = this->pRT.pObject;
    v14 = (Scaleform::Render::RenderTarget *)v12;
    if ( v13 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v13->vfptr[2].__vecDelDtor)(v13);
    this->pRT.pObject = v14;
    LOBYTE(v11) = v14 != 0i64;
  }
  return (char)v11;
}

// File Line: 411
// RVA: 0x98D910
Scaleform::Render::Texture *__fastcall Scaleform::Render::DrawableImage::GetTexture(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::ImageBase *pObject; // rcx
  Scaleform::Render::ImageBase *v5; // rsi
  Scaleform::Render::DrawableImageContext *v6; // rbx
  __int64 pHAL; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  Scaleform::Render::TextureManager *v11; // [rsp+20h] [rbp-28h] BYREF
  __int64 v12; // [rsp+28h] [rbp-20h]
  __int64 v13; // [rsp+30h] [rbp-18h]
  __int64 v14; // [rsp+38h] [rbp-10h]

  pObject = this->pDelegateImage.pObject;
  if ( !pObject
    || !((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pObject->vfptr[3].__vecDelDtor)(pObject)
    || ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))this->pDelegateImage.pObject->vfptr[3].__vecDelDtor)(this->pDelegateImage.pObject) == 7 )
  {
    return this->pTexture.Value;
  }
  v5 = this->pDelegateImage.pObject;
  if ( !pmanager )
  {
    v6 = this->pContext.pObject;
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0i64;
    v14 = 0i64;
    v6->pRTCommandQueue->vfptr->GetRenderInterfaces(v6->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v11);
    pmanager = v11;
    if ( v6->IDefaults.pTextureManager )
      pmanager = v6->IDefaults.pTextureManager;
    pHAL = v12;
    v11 = pmanager;
    if ( v6->IDefaults.pHAL )
      pHAL = (__int64)v6->IDefaults.pHAL;
    v12 = pHAL;
    pRenderer2D = v13;
    if ( v6->IDefaults.pRenderer2D )
      pRenderer2D = (__int64)v6->IDefaults.pRenderer2D;
    v13 = pRenderer2D;
    RenderThreadID = v14;
    if ( v6->IDefaults.RenderThreadID )
      RenderThreadID = (__int64)v6->IDefaults.RenderThreadID;
    v14 = RenderThreadID;
  }
  return (Scaleform::Render::Texture *)v5->vfptr[21].__vecDelDtor(v5, (unsigned int)pmanager);
}

// File Line: 443
// RVA: 0x9B9C00
void __fastcall Scaleform::Render::DrawableImage::TextureLost(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image::TextureLossReason reason)
{
  Scaleform::Render::RenderTarget *pObject; // rcx

  if ( reason == TLR_DeviceLost )
  {
    pObject = this->pRT.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))pObject->vfptr[2].__vecDelDtor)(pObject);
    this->pRT.pObject = 0i64;
  }
}

// File Line: 452
// RVA: 0x9E9790
_BOOL8 __fastcall Scaleform::Render::DrawableImage::mapTextureRT(Scaleform::Render::DrawableImage *this, bool readOnly)
{
  Scaleform::Lock *p_QueueLock; // rbx
  bool v5; // di

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  if ( readOnly
    && Scaleform::Render::DrawableImage::MapImageSource(
         &this->MappedData,
         (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject) )
  {
    this->DrawableImageState |= 2u;
LABEL_10:
    v5 = (this->DrawableImageState & 3) != 0;
    goto LABEL_11;
  }
  if ( !this->pDelegateImage.pObject || Scaleform::Render::DrawableImage::ensureRenderableRT(this) )
  {
    if ( this->pTexture.Value
      && ((unsigned __int8 (__fastcall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::ImageData *, _QWORD, _QWORD, __int64))this->pTexture.Value->Scaleform::Render::Image::vfptr[13].__vecDelDtor)(
           this->pTexture.Value,
           &this->MappedData,
           0i64,
           0i64,
           -2i64) )
    {
      this->DrawableImageState |= 3u;
    }
    goto LABEL_10;
  }
  v5 = 0;
LABEL_11:
  LeaveCriticalSection(&p_QueueLock->cs);
  return v5;
}

// File Line: 487
// RVA: 0x9E1EA0
char __fastcall Scaleform::Render::DrawableImage::ensureRenderableRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rbx
  __int64 pTextureManager; // rax
  Scaleform::Render::HAL *pHAL; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  unsigned int Height; // ecx
  Scaleform::Render::ImageBase *v9; // rcx
  Scaleform::Render::ImageBase *v10; // r14
  __int64 v11; // r15
  Scaleform::Render::RenderTarget *v12; // rbx
  Scaleform::Render::RenderTarget *v13; // rcx
  Scaleform::Render::ImageBase *v14; // rcx
  unsigned int *v15; // rax
  unsigned int v16; // ecx
  __int64 v17; // rax
  Scaleform::Render::ImageBase *v18; // rcx
  Scaleform::Render::DrawableImageContext *v19; // rbx
  Scaleform::Render::ImageFormat v20; // eax
  char v21; // bl
  Scaleform::Render::HAL *v22; // rcx
  bool v23; // bl
  bool v24; // si
  Scaleform::Render::RenderTarget *v25; // r8
  float v26; // xmm1_4
  float v27; // xmm0_4
  Scaleform::Render::RenderTarget *v28; // rcx
  int v29; // edx
  int *v30; // rax
  Scaleform::Render::RenderTarget *v31; // rdx
  float v32; // xmm3_4
  Scaleform::RefCountImplCoreVtbl *v33; // rbx
  Scaleform::Render::ImageData *MappedData; // rax
  __int64 v35; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::Render::HAL *v36; // [rsp+38h] [rbp-61h]
  __int64 v37; // [rsp+40h] [rbp-59h]
  __int64 v38; // [rsp+48h] [rbp-51h]
  __int128 v39; // [rsp+50h] [rbp-49h] BYREF
  __m128 v40; // [rsp+60h] [rbp-39h]
  __int64 v41; // [rsp+70h] [rbp-29h] BYREF
  float v42; // [rsp+78h] [rbp-21h]
  float v43; // [rsp+7Ch] [rbp-1Dh]
  int v44[8]; // [rsp+80h] [rbp-19h] BYREF
  __int64 v45; // [rsp+A0h] [rbp+7h]
  char v46[8]; // [rsp+A8h] [rbp+Fh] BYREF
  int v47; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [rsp+108h] [rbp+6Fh] BYREF
  int v49; // [rsp+110h] [rbp+77h] BYREF
  int v50; // [rsp+114h] [rbp+7Bh]
  Scaleform::Render::ImageBase *v51; // [rsp+118h] [rbp+7Fh]

  v45 = -2i64;
  if ( this->pRT.pObject )
    return 1;
  v35 = 0i64;
  v36 = 0i64;
  v37 = 0i64;
  v38 = 0i64;
  pObject = this->pContext.pObject;
  pObject->pRTCommandQueue->vfptr->GetRenderInterfaces(pObject->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v35);
  pTextureManager = v35;
  if ( pObject->IDefaults.pTextureManager )
    pTextureManager = (__int64)pObject->IDefaults.pTextureManager;
  v35 = pTextureManager;
  pHAL = v36;
  if ( pObject->IDefaults.pHAL )
    pHAL = pObject->IDefaults.pHAL;
  v36 = pHAL;
  pRenderer2D = v37;
  if ( pObject->IDefaults.pRenderer2D )
    pRenderer2D = (__int64)pObject->IDefaults.pRenderer2D;
  v37 = pRenderer2D;
  RenderThreadID = v38;
  if ( pObject->IDefaults.RenderThreadID )
    RenderThreadID = (__int64)pObject->IDefaults.RenderThreadID;
  v38 = RenderThreadID;
  Height = this->ISize.Height;
  size.Width = this->ISize.Width;
  size.Height = Height;
  v9 = this->pDelegateImage.pObject;
  if ( v9 )
    ((void (__fastcall *)(Scaleform::Render::ImageBase *))v9->vfptr[1].__vecDelDtor)(v9);
  v10 = this->pDelegateImage.pObject;
  v51 = v10;
  v11 = 0i64;
  if ( this->pTexture.Value )
  {
    v12 = (Scaleform::Render::RenderTarget *)((__int64 (__fastcall *)(Scaleform::Render::HAL *, Scaleform::Render::Texture *volatile, _QWORD))v36->vfptr[21].__vecDelDtor)(
                                               v36,
                                               this->pTexture.Value,
                                               0i64);
    v13 = this->pRT.pObject;
    if ( v13 )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))v13->vfptr[2].__vecDelDtor)(v13);
    this->pRT.pObject = v12;
    if ( !v12 )
      goto LABEL_23;
  }
  else
  {
    v14 = this->pDelegateImage.pObject;
    if ( v14 )
    {
      v15 = (unsigned int *)v14->vfptr[5].__vecDelDtor(v14, (unsigned int)v46);
      v16 = v15[1];
      size.Width = *v15;
      size.Height = v16;
      v17 = ((__int64 (__fastcall *)(Scaleform::Render::ImageBase *))this->pDelegateImage.pObject->vfptr[9].__vecDelDtor)(this->pDelegateImage.pObject);
      v11 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v17 + 168i64))(v17, v35);
      v18 = this->pDelegateImage.pObject;
      if ( v18 )
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))v18->vfptr[2].__vecDelDtor)(v18);
      this->pDelegateImage.pObject = 0i64;
      v19 = this->pContext.pObject;
      v20 = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v35 + 104i64))(v35);
      Scaleform::Render::DrawableImage::initialize(this, v20, &size, v19);
    }
  }
  if ( this->pRT.pObject )
  {
    if ( v11 )
    {
      v22 = v36;
      v23 = (v36->HALState & 4) == 0;
      v24 = (v36->HALState & 2) == 0;
      if ( (v36->HALState & 2) == 0 )
      {
        ((void (__fastcall *)(Scaleform::Render::HAL *))v36->vfptr[5].__vecDelDtor)(v36);
        v22 = v36;
      }
      if ( !v23 )
      {
        ((void (__fastcall *)(Scaleform::Render::HAL *))v22->vfptr[10].__vecDelDtor)(v22);
        v22 = v36;
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *))v22->vfptr[9].__vecDelDtor)(v22);
      v25 = this->pRT.pObject;
      v26 = (float)(v25->ViewRect.y2 - v25->ViewRect.y1);
      v27 = (float)(v25->ViewRect.x2 - v25->ViewRect.x1);
      v47 = 0;
      v41 = 0i64;
      v42 = v27;
      v43 = v26;
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, Scaleform::Render::RenderTarget *, __int64, int *))v36->vfptr[24].__vecDelDtor)(
        v36,
        &v41,
        v25,
        2i64,
        &v47);
      v28 = this->pRT.pObject;
      v29 = v28->ViewRect.y2 - v28->ViewRect.y1;
      v49 = v28->ViewRect.x2 - v28->ViewRect.x1;
      v50 = v29;
      v30 = (int *)v36->Matrices.pObject->vfptr[1].__vecDelDtor(v36->Matrices.pObject, &v49);
      v44[0] = *v30;
      v44[1] = v30[1];
      v44[2] = v30[2];
      v44[3] = v30[3];
      v44[4] = v30[4];
      v44[5] = v30[5];
      v44[6] = v30[6];
      v44[7] = v30[7];
      v39 = _xmm;
      v40 = _xmm;
      v31 = this->pRT.pObject;
      v32 = (float)(v31->ViewRect.y2 - v31->ViewRect.y1) / (float)(int)v31->BufferSize.Height;
      *(float *)&v39 = (float)(v31->ViewRect.x2 - v31->ViewRect.x1) / (float)(int)v31->BufferSize.Width;
      *((float *)&v39 + 1) = *(float *)&v39 * 0.0;
      *((float *)&v39 + 2) = *(float *)&v39 * 0.0;
      *((float *)&v39 + 3) = *(float *)&v39 * 0.0;
      v40.m128_f32[0] = v32 * 0.0;
      v40.m128_f32[1] = v32;
      v40.m128_f32[2] = v32 * 0.0;
      v40.m128_f32[3] = v32 * 0.0;
      Scaleform::Render::HAL::applyBlendMode(v36, 16i64, 1, 1);
      ((void (__fastcall *)(Scaleform::Render::HAL *, __int64, int *, __int128 *, int))v36->vfptr[58].__vecDelDtor)(
        v36,
        v11,
        v44,
        &v39,
        -1);
      v36->vfptr[25].__vecDelDtor(v36, 2u);
      Scaleform::Render::DrawableImage::updateStagingTargetRT(this);
      ((void (__fastcall *)(Scaleform::Render::HAL *))v36->vfptr[10].__vecDelDtor)(v36);
      if ( !v23 )
        ((void (__fastcall *)(Scaleform::Render::HAL *))v36->vfptr[9].__vecDelDtor)(v36);
      if ( v24 )
        ((void (__fastcall *)(Scaleform::Render::HAL *))v36->vfptr[6].__vecDelDtor)(v36);
    }
    else if ( v10 && Scaleform::Render::DrawableImage::mapTextureRT(this, 0) )
    {
      v33 = v10->vfptr + 8;
      MappedData = Scaleform::Render::DrawableImage::getMappedData(this);
      ((void (__fastcall *)(Scaleform::Render::ImageBase *, Scaleform::Render::ImageData *, _QWORD, _QWORD))v33->__vecDelDtor)(
        v10,
        MappedData,
        Scaleform::Render::ImageBase::CopyScanlineDefault,
        0i64);
      Scaleform::Render::DrawableImage::unmapTextureRT(this);
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
}

// File Line: 567
// RVA: 0x9F88D0
void __fastcall Scaleform::Render::DrawableImage::unmapTextureRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Lock *p_QueueLock; // [rsp+40h] [rbp+8h]

  p_QueueLock = &this->pQueue.pObject->QueueLock;
  EnterCriticalSection(&p_QueueLock->cs);
  if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
  {
    ((void (__fastcall *)(Scaleform::Render::Texture *volatile))this->pTexture.Value->Scaleform::Render::Image::vfptr[14].__vecDelDtor)(this->pTexture.Value);
    this->DrawableImageState &= 0xFFFFFFFC;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
}

// File Line: 579
// RVA: 0x9FA5E0
void __fastcall Scaleform::Render::DrawableImage::updateRenderTargetRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rbx
  __int64 pTextureManager; // rax
  __int64 pHAL; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  __int64 v7; // [rsp+28h] [rbp-30h] BYREF
  __int64 v8; // [rsp+30h] [rbp-28h]
  __int64 v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]
  Scaleform::Lock *lpCriticalSection; // [rsp+60h] [rbp+8h]

  if ( this->pTexture.Value )
  {
    lpCriticalSection = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&lpCriticalSection->cs);
    if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
    {
      ((void (__fastcall *)(Scaleform::Render::Texture *volatile))this->pTexture.Value->Scaleform::Render::Image::vfptr[14].__vecDelDtor)(this->pTexture.Value);
      this->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(&lpCriticalSection->cs);
    v7 = 0i64;
    v8 = 0i64;
    v9 = 0i64;
    v10 = 0i64;
    pObject = this->pContext.pObject;
    pObject->pRTCommandQueue->vfptr->GetRenderInterfaces(pObject->pRTCommandQueue, (Scaleform::Render::Interfaces *)&v7);
    pTextureManager = v7;
    if ( pObject->IDefaults.pTextureManager )
      pTextureManager = (__int64)pObject->IDefaults.pTextureManager;
    v7 = pTextureManager;
    pHAL = v8;
    if ( pObject->IDefaults.pHAL )
      pHAL = (__int64)pObject->IDefaults.pHAL;
    v8 = pHAL;
    pRenderer2D = v9;
    if ( pObject->IDefaults.pRenderer2D )
      pRenderer2D = (__int64)pObject->IDefaults.pRenderer2D;
    v9 = pRenderer2D;
    RenderThreadID = v10;
    if ( pObject->IDefaults.RenderThreadID )
      RenderThreadID = (__int64)pObject->IDefaults.RenderThreadID;
    v10 = RenderThreadID;
    ((void (__fastcall *)(Scaleform::Render::Texture *volatile, Scaleform::Render::RenderBuffer::RenderTargetData *, __int64))this->pTexture.Value->Scaleform::Render::Image::vfptr[15].__vecDelDtor)(
      this->pTexture.Value,
      this->pRT.pObject->pRenderTargetData,
      v8);
  }
}

// File Line: 591
// RVA: 0x9FA940
void __fastcall Scaleform::Render::DrawableImage::updateStagingTargetRT(Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::DrawableImageContext *pObject; // rbx
  __int64 pTextureManager; // rax
  __int64 pHAL; // rax
  __int64 pRenderer2D; // rax
  __int64 RenderThreadID; // rax
  Scaleform::Render::RenderSync *v7; // rax
  Scaleform::Render::Fence *inserted; // rax
  Scaleform::Render::Fence *v9; // rbx
  Scaleform::Render::Fence *v10; // rcx
  __int64 v11; // [rsp+28h] [rbp-30h] BYREF
  __int64 v12; // [rsp+30h] [rbp-28h]
  __int64 v13; // [rsp+38h] [rbp-20h]
  __int64 v14; // [rsp+40h] [rbp-18h]
  Scaleform::Lock *lpCriticalSection; // [rsp+60h] [rbp+8h]

  if ( this->pTexture.Value )
  {
    v11 = 0i64;
    v12 = 0i64;
    v13 = 0i64;
    v14 = 0i64;
    pObject = this->pContext.pObject;
    pObject->pRTCommandQueue->vfptr->GetRenderInterfaces(
      pObject->pRTCommandQueue,
      (Scaleform::Render::Interfaces *)&v11);
    pTextureManager = v11;
    if ( pObject->IDefaults.pTextureManager )
      pTextureManager = (__int64)pObject->IDefaults.pTextureManager;
    v11 = pTextureManager;
    pHAL = v12;
    if ( pObject->IDefaults.pHAL )
      pHAL = (__int64)pObject->IDefaults.pHAL;
    v12 = pHAL;
    pRenderer2D = v13;
    if ( pObject->IDefaults.pRenderer2D )
      pRenderer2D = (__int64)pObject->IDefaults.pRenderer2D;
    v13 = pRenderer2D;
    RenderThreadID = v14;
    if ( pObject->IDefaults.RenderThreadID )
      RenderThreadID = (__int64)pObject->IDefaults.RenderThreadID;
    v14 = RenderThreadID;
    lpCriticalSection = &this->pQueue.pObject->QueueLock;
    EnterCriticalSection(&lpCriticalSection->cs);
    if ( (this->DrawableImageState & 3) != 0 && this->pTexture.Value )
    {
      ((void (__fastcall *)(Scaleform::Render::Texture *volatile))this->pTexture.Value->Scaleform::Render::Image::vfptr[14].__vecDelDtor)(this->pTexture.Value);
      this->DrawableImageState &= 0xFFFFFFFC;
    }
    LeaveCriticalSection(&lpCriticalSection->cs);
    this->pTexture.Value->Scaleform::Render::Image::vfptr[16].__vecDelDtor(
      this->pTexture.Value,
      (unsigned int)this->pRT.pObject->pRenderTargetData);
    if ( (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 520i64))(v12) )
    {
      v7 = (Scaleform::Render::RenderSync *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 520i64))(v12);
      inserted = Scaleform::Render::RenderSync::InsertFence(v7);
      v9 = inserted;
      if ( inserted )
        ++inserted->RefCount;
      v10 = this->pFence.pObject;
      if ( v10 )
        Scaleform::Render::Fence::Release(v10);
      this->pFence.pObject = v9;
    }
  }
}

// File Line: 608
// RVA: 0x937EA0
void __fastcall Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DICommand_SetPixels *cmd)
{
  Scaleform::Render::DrawableImageContext *pObject; // rax
  Scaleform::Render::DICommand_SetPixels *v5; // rax
  Scaleform::Render::DICommandQueue *v6; // rbx

  pObject = this->pContext.pObject;
  if ( pObject && pObject->pControlContext )
    pObject->pControlContext->DIChangesRequired = 1;
  if ( !Scaleform::Render::DICommand::ExecuteSWOnAddCommand(cmd, this) )
  {
    v5 = (Scaleform::Render::DICommand_SetPixels *)Scaleform::Render::DICommandQueue::allocCommandFromPage(
                                                     this->pQueue.pObject,
                                                     0x30u,
                                                     &this->pQueue.pObject->QueueLock);
    if ( v5 )
      Scaleform::Render::DICommand_SetPixels::DICommand_SetPixels(v5, cmd);
    if ( (((__int64 (__fastcall *)(Scaleform::Render::DICommand_SetPixels *))cmd->vfptr->GetRenderCaps)(cmd) & 0x10) != 0 )
    {
      v6 = this->pQueue.pObject;
      _InterlockedExchangeAdd(&v6->RefCount, 1u);
      _InterlockedExchangeAdd(&v6->ExecuteCmd.pObject->RefCount, 1u);
      v6->pRTCommandQueue->vfptr->PushThreadCommand(v6->pRTCommandQueue, v6->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(v6->ExecuteCmd.pObject);
    }
  }
}

// File Line: 626
// RVA: 0x9E7230
Scaleform::Render::ImageData *__fastcall Scaleform::Render::DrawableImage::getMappedData(
        Scaleform::Render::DrawableImage *this)
{
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *v4; // r8
  Scaleform::Render::FenceImpl *v5; // r8
  Scaleform::Render::Fence *v6; // rcx

  pObject = this->pFence.pObject;
  if ( pObject )
  {
    if ( pObject->HasData )
    {
      Data = pObject->Data;
      if ( pObject->Data )
      {
        if ( Data->Parent )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[4].__vecDelDtor)(
                 Data->RSContext,
                 1i64,
                 Data->APIHandle) )
          {
            v4 = this->pFence.pObject;
            if ( v4->HasData )
            {
              v5 = v4->Data;
              if ( v5 )
              {
                if ( v5->Parent )
                  ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))v5->RSContext->vfptr[5].__vecDelDtor)(
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
  v6 = this->pFence.pObject;
  if ( v6 )
    Scaleform::Render::Fence::Release(v6);
  this->pFence.pObject = 0i64;
  return &this->MappedData;
}

// File Line: 640
// RVA: 0x9F2090
void __fastcall Scaleform::Render::DrawableImage::setViewProj3DHelper(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::TreeNode *subtree,
        Scaleform::Render::TreeRoot *root)
{
  Scaleform::Render::TreeNode *i; // rbx
  __int64 v5; // r8
  Scaleform::Render::Matrix3x4<float> mat; // [rsp+20h] [rbp-19h] BYREF
  Scaleform::Render::Matrix4x4<float> mat3D; // [rsp+50h] [rbp+17h] BYREF

  for ( i = subtree; i; i = (Scaleform::Render::TreeNode *)i->pParent )
  {
    v5 = *(_QWORD *)(((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    if ( (*(_WORD *)(*(_QWORD *)(v5
                               + 8i64 * (unsigned int)((int)((_DWORD)i - ((unsigned int)i & 0xFFFFF000) - 56) / 56)
                               + 40)
                   + 10i64) & 0x1000) != 0 )
      break;
    if ( (*(_WORD *)(*(_QWORD *)(v5
                               + 8i64
                               * (unsigned int)((__int64)((__int64)&i[-1]
                                                        - ((unsigned __int64)i & 0xFFFFFFFFFFFFF000ui64))
                                              / 56)
                               + 40)
                   + 10i64) & 0x800) != 0 )
      break;
  }
  mat = Scaleform::Render::Matrix3x4<float>::Identity;
  mat3D = Scaleform::Render::Matrix4x4<float>::Identity;
  if ( i )
  {
    Scaleform::Render::TreeNode::GetViewMatrix3D(i, &mat);
    Scaleform::Render::TreeNode::GetProjectionMatrix3D(i, &mat3D);
  }
  Scaleform::Render::TreeNode::SetViewMatrix3D(root, &mat);
  Scaleform::Render::TreeNode::SetProjectionMatrix3D(root, &mat3D);
}

// File Line: 662
// RVA: 0x959E60
void __fastcall Scaleform::Render::DrawableImage::ApplyFilter(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::Filter *filter)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  Scaleform::Render::Filter *pObject; // rcx
  Scaleform::Render::DICommand_ApplyFilter cmd; // [rsp+28h] [rbp-40h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_ApplyFilter::`vftable;
  if ( filter )
    _InterlockedExchangeAdd(&filter->RefCount, 1u);
  cmd.pFilter.pObject = filter;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ApplyFilter>(this, &cmd);
  pObject = cmd.pFilter.pObject;
  if ( cmd.pFilter.pObject && !_InterlockedDecrement(&cmd.pFilter.pObject->RefCount) && pObject )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ApplyFilter>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ApplyFilter>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 669
// RVA: 0x95BC70
void __fastcall Scaleform::Render::DrawableImage::CalcFilterRect(
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Filter *filter)
{
  float y1; // xmm1_4
  float x2; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float y2; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+20h] [rbp-18h] BYREF

  y1 = (float)sourceRect->y1;
  x2 = (float)sourceRect->x2;
  bounds.x1 = (float)sourceRect->x1;
  bounds.y1 = y1;
  bounds.x2 = x2;
  bounds.y2 = (float)sourceRect->y2;
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(filter, &bounds);
  if ( result )
  {
    v6 = bounds.y1;
    result->x1 = bounds.x1;
    v7 = bounds.x2;
    result->y1 = v6;
    y2 = bounds.y2;
    result->x2 = v7;
    result->y2 = y2;
  }
}

// File Line: 679
// RVA: 0x961840
void __fastcall Scaleform::Render::DrawableImage::ColorTransform(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *rect,
        Scaleform::Render::Cxform *cxform)
{
  Scaleform::Render::DICommand_ColorTransform *v4; // rax
  Scaleform::Render::DICommand_ColorTransform v5; // [rsp+30h] [rbp-58h] BYREF

  Scaleform::Render::DICommand_ColorTransform::DICommand_ColorTransform(&v5, this, rect, cxform);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_ColorTransform>(this, v4);
  if ( v5.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ColorTransform>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(v5.pSource.pObject);
  v5.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v5.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_ColorTransform>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v5.pImage.pObject);
}

// File Line: 685
// RVA: 0x9618B0
void __fastcall Scaleform::Render::DrawableImage::Compare(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *image0,
        Scaleform::Render::DrawableImage *image1)
{
  Scaleform::Render::DICommand_Compare *v4; // rax
  Scaleform::Render::DICommand_Compare v5; // [rsp+28h] [rbp-40h] BYREF

  Scaleform::Render::DICommand_Compare::DICommand_Compare(&v5, this, image0, image1);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Compare>(this, v4);
  if ( v5.pImageCompare1.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pImageCompare1.pObject->vfptr[2].__vecDelDtor)(v5.pImageCompare1.pObject);
  if ( v5.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Compare>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(v5.pSource.pObject);
  v5.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v5.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Compare>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v5.pImage.pObject);
}

// File Line: 695
// RVA: 0x964620
void __fastcall Scaleform::Render::DrawableImage::CopyChannel(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage::ChannelBits sourceChannel,
        Scaleform::Render::DrawableImage::ChannelBits destChannel)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  Scaleform::Render::DICommand_CopyChannel cmd; // [rsp+28h] [rbp-40h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CopyChannel::`vftable;
  cmd.SourceChannel = sourceChannel;
  cmd.DestChannel = destChannel;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyChannel>(this, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyChannel>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyChannel>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 704
// RVA: 0x964C80
void __fastcall Scaleform::Render::DrawableImage::CopyPixels(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage *alphaSource,
        Scaleform::Render::DrawableImage **alphaPoint,
        bool mergeAlpha)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  Scaleform::Render::DICommand_CopyPixels cmd; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::Render::DrawableImage *alphaSourcea; // [rsp+B0h] [rbp+40h]

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_CopyPixels::`vftable;
  if ( alphaSource )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))alphaSource->vfptr[1].__vecDelDtor)(alphaSource);
  cmd.pAlphaSource.pObject = alphaSource;
  if ( alphaPoint )
    alphaSourcea = *alphaPoint;
  else
    alphaSourcea = 0i64;
  cmd.AlphaPoint = (Scaleform::Render::Point<long>)alphaSourcea;
  cmd.MergeAlpha = mergeAlpha;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_CopyPixels>(this, &cmd);
  if ( cmd.pAlphaSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pAlphaSource.pObject->vfptr[2].__vecDelDtor)(cmd.pAlphaSource.pObject);
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyPixels>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_CopyPixels>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 722
// RVA: 0x96E8F0
void __fastcall Scaleform::Render::DrawableImage::Draw(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::TreeNode *subtree,
        Scaleform::Render::Matrix2x4<float> *matrix,
        Scaleform::Render::Cxform *cform,
        Scaleform::Render::BlendMode blendMode,
        Scaleform::Render::Rect<long> *clipRect)
{
  Scaleform::Render::DrawableImageContext *pObject; // rcx
  Scaleform::Render::TreeRoot *v9; // r15
  Scaleform::Render::TreeNode *v10; // r12
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int *v14; // rax
  int *v15; // rax
  int v16; // edx
  int v17; // ecx
  int v18; // r14d
  int v19; // edi
  int v20; // esi
  int v21; // ebx
  int *v22; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::DrawableImageContext *v24; // rax
  Scaleform::Render::DICommand_Draw *v25; // rax
  bool v26; // zf
  int v27[4]; // [rsp+20h] [rbp-B9h] BYREF
  __int64 v28; // [rsp+30h] [rbp-A9h] BYREF
  int v29; // [rsp+38h] [rbp-A1h]
  int v30; // [rsp+3Ch] [rbp-9Dh]
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-99h] BYREF
  int v32; // [rsp+70h] [rbp-69h]
  int v33; // [rsp+74h] [rbp-65h]
  int v34; // [rsp+78h] [rbp-61h]
  int v35; // [rsp+7Ch] [rbp-5Dh]
  char v36[8]; // [rsp+80h] [rbp-59h] BYREF
  char v37[8]; // [rsp+88h] [rbp-51h] BYREF
  Scaleform::Render::TreeRoot *v38; // [rsp+90h] [rbp-49h]
  __int64 v39; // [rsp+98h] [rbp-41h]
  Scaleform::Render::TreeNode *v40; // [rsp+A0h] [rbp-39h]
  Scaleform::Render::DICommand_Draw v41; // [rsp+A8h] [rbp-31h] BYREF
  int v42; // [rsp+134h] [rbp+5Bh]

  v39 = -2i64;
  pObject = this->pContext.pObject;
  if ( pObject && pObject->RContext )
  {
    v9 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeRoot>(pObject->RContext);
    v38 = v9;
    if ( v9 )
    {
      v10 = Scaleform::Render::TreeNode::Clone(subtree, this->pContext.pObject->RContext);
      v40 = v10;
      Scaleform::Render::TreeContainer::Add(v9, v10);
      if ( clipRect )
      {
        y2 = clipRect->y2;
        x2 = clipRect->x2;
        y1 = clipRect->y1;
        v27[0] = clipRect->x1;
        v27[1] = y1;
        v27[2] = x2;
        v27[3] = y2;
        v14 = v27;
      }
      else
      {
        v15 = (int *)this->vfptr[5].__vecDelDtor(this, v37);
        v16 = v15[1];
        v17 = *v15;
        v28 = 0i64;
        v29 = v17;
        v30 = v16;
        v14 = (int *)&v28;
      }
      v18 = v14[3];
      v19 = v14[2];
      v20 = v14[1];
      v32 = *v14;
      v21 = v32;
      v33 = v20;
      v34 = v19;
      v35 = v18;
      v22 = (int *)this->vfptr[5].__vecDelDtor(this, v36);
      v42 = v22[1];
      vp.BufferWidth = *v22;
      vp.BufferHeight = v42;
      vp.Left = v21;
      vp.Top = v20;
      vp.Width = v19 - v21;
      vp.Height = v18 - v20;
      vp.Flags = 1;
      *(_QWORD *)&vp.ScissorWidth = 0i64;
      *(_QWORD *)&vp.ScissorLeft = 0i64;
      Scaleform::Render::TreeRoot::SetViewport(v9, &vp);
      Scaleform::Render::TreeNode::SetMatrix(v9, matrix);
      Scaleform::Render::DrawableImage::setViewProj3DHelper(this, subtree, v9);
      Scaleform::Render::TreeNode::SetMatrix(v10, &Scaleform::Render::Matrix2x4<float>::Identity);
      Scaleform::Render::TreeNode::SetVisible(v10, 1);
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(v10, 2u);
      WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&cform->M[0][0];
      WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&cform->M[1][0];
      Scaleform::Render::TreeNode::SetBlendMode(v10, blendMode);
      ++v9->RefCount;
      v24 = this->pContext.pObject;
      if ( v24->pControlContext )
        v24->pControlContext->DIChangesRequired = 1;
      this->pContext.pObject->vfptr->OnCapture(&this->pContext.pObject->Scaleform::Render::ContextImpl::ContextCaptureNotify);
      Scaleform::Render::DICommand_Draw::DICommand_Draw(&v41, this, v9, clipRect);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(this, v25);
      v41.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( v41.pImage.pObject )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v41.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Draw,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v41.pImage.pObject);
      if ( v10 )
      {
        v26 = v10->RefCount-- == 1;
        if ( v26 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v10);
      }
    }
    if ( v9 )
    {
      v26 = v9->RefCount-- == 1;
      if ( v26 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
    }
  }
}

// File Line: 764
// RVA: 0x96E510
void __fastcall Scaleform::Render::DrawableImage::Draw(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image *source,
        Scaleform::Render::Matrix2x4<float> *matrix,
        Scaleform::Render::Cxform *cform)
{
  Scaleform::Render::DrawableImageContext *pObject; // rcx
  Scaleform::Render::TreeRoot *v7; // r12
  Scaleform::Render::TreeShape *v8; // r13
  Scaleform::Render::ComplexFill *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r15
  __int64 v12; // rcx
  Scaleform::Render::ShapeDataFloatMP *v13; // rax
  Scaleform::Render::ShapeDataFloatMP *v14; // rax
  Scaleform::Render::ShapeDataFloatMP *v15; // r14
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *v16; // rbx
  __int64 v17; // rcx
  __int64 v18; // rdx
  bool v19; // zf
  __int64 v20; // rdx
  int *v21; // rbx
  int *v22; // rax
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int *v26; // rax
  int *v27; // rax
  int v28; // edx
  int v29; // ecx
  int v30; // r14d
  int v31; // edi
  int v32; // esi
  int v33; // ebx
  _DWORD *v34; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::EntryData *v36; // rcx
  Scaleform::Render::DrawableImage *v37; // rbx
  Scaleform::Render::DrawableImageContext *v38; // rax
  Scaleform::Render::DICommand_Draw *v39; // rax
  int v40; // [rsp+34h] [rbp-94h]
  Scaleform::Render::ShapeDataFloatMP *v41; // [rsp+38h] [rbp-90h]
  int v42[3]; // [rsp+40h] [rbp-88h] BYREF
  char v43[12]; // [rsp+4Ch] [rbp-7Ch] BYREF
  int v44; // [rsp+58h] [rbp-70h]
  int v45; // [rsp+5Ch] [rbp-6Ch]
  char vp[48]; // [rsp+60h] [rbp-68h] BYREF
  char v47[8]; // [rsp+90h] [rbp-38h] BYREF
  Scaleform::Render::ShapeDataFloatMP *v48; // [rsp+98h] [rbp-30h]
  char v49[8]; // [rsp+A0h] [rbp-28h] BYREF
  __int64 v50; // [rsp+A8h] [rbp-20h]
  char v51[8]; // [rsp+B0h] [rbp-18h] BYREF
  __int64 v52; // [rsp+B8h] [rbp-10h]
  __int64 v53; // [rsp+C0h] [rbp-8h]
  Scaleform::Render::DICommand_Draw v54; // [rsp+C8h] [rbp+0h] BYREF
  Scaleform::Render::DrawableImage *image; // [rsp+138h] [rbp+70h]
  Scaleform::Render::Matrix2x4<float> *m; // [rsp+148h] [rbp+80h]
  Scaleform::Render::ContextImpl::EntryData *v57; // [rsp+150h] [rbp+88h]
  Scaleform::Render::BlendMode mode; // [rsp+158h] [rbp+90h]
  Scaleform::Render::Rect<long> *vars0; // [rsp+160h] [rbp+98h]

  v53 = -2i64;
  pObject = this->pContext.pObject;
  if ( pObject && pObject->RContext )
  {
    v7 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeRoot>(pObject->RContext);
    *(_QWORD *)&vp[32] = v7;
    if ( v7 )
    {
      v8 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(this->pContext.pObject->RContext);
      *(_QWORD *)&vp[40] = v8;
      Scaleform::Render::TreeContainer::Add(v7, v8);
      *(_QWORD *)&vp[16] = 0i64;
      *(_DWORD *)&vp[8] = 0;
      v9 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               80i64,
                                               0i64);
      if ( v9 )
      {
        Scaleform::Render::ComplexFill::ComplexFill(v9);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      *(_QWORD *)&vp[16] = v11;
      if ( source )
        ((void (__fastcall *)(Scaleform::Render::Image *))source->vfptr[1].__vecDelDtor)(source);
      v12 = *(_QWORD *)(v11 + 16);
      if ( v12 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
      *(_QWORD *)(v11 + 16) = source;
      v13 = (Scaleform::Render::ShapeDataFloatMP *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     160i64,
                                                     0i64);
      if ( v13 )
      {
        Scaleform::Render::ShapeDataFloatMP::ShapeDataFloatMP(v13);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      v41 = v15;
      v48 = v15;
      v16 = (Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> *)v15->pData.pObject;
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v16 + 1,
        &v16[1],
        v16[1].Size + 1);
      v17 = 16 * v16[1].Size;
      v18 = (__int64)&v16[1].Data[-1];
      v19 = v17 + v18 == 0;
      v20 = v17 + v18;
      v50 = v20;
      v52 = v20;
      if ( !v19 )
      {
        *(_DWORD *)v20 = 0;
        _InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 8), 1u);
        *(_QWORD *)(v20 + 8) = v11;
      }
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(v15->pData.pObject);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        v15->pData.pObject,
        1u,
        0,
        0);
      v21 = (int *)source->vfptr[5].__vecDelDtor(source, &vp[24]);
      v22 = (int *)source->vfptr[5].__vecDelDtor(source, v47);
      Scaleform::Render::ShapeDataFloatMP::RectanglePath(v15, 0.0, 0.0, (float)*v21, (float)v22[1]);
      Scaleform::Render::ShapeDataFloatMP::CountLayers(v15);
      Scaleform::Render::TreeShape::SetShape(v8, (Scaleform::Render::ContextImpl::EntryDataVtbl *)v15);
      if ( vars0 )
      {
        y2 = vars0->y2;
        x2 = vars0->x2;
        y1 = vars0->y1;
        v42[0] = vars0->x1;
        v42[1] = y1;
        v42[2] = x2;
        *(_DWORD *)v43 = y2;
        v26 = v42;
      }
      else
      {
        v27 = (int *)this->vfptr[5].__vecDelDtor(this, v51);
        v28 = v27[1];
        v29 = *v27;
        *(_QWORD *)&v43[4] = 0i64;
        v44 = v29;
        v45 = v28;
        v26 = (int *)&v43[4];
      }
      v30 = v26[3];
      v31 = v26[2];
      v32 = v26[1];
      v44 = *v26;
      v33 = v44;
      v45 = v32;
      *(_DWORD *)vp = v31;
      *(_DWORD *)&vp[4] = v30;
      v34 = image->vfptr[5].__vecDelDtor(image, v49);
      v40 = v34[1];
      *(_DWORD *)vp = *v34;
      *(_DWORD *)&vp[4] = v40;
      *(_DWORD *)&vp[8] = v33;
      *(_DWORD *)&vp[12] = v32;
      *(_DWORD *)&vp[16] = v31 - v33;
      *(_DWORD *)&vp[20] = v30 - v32;
      *(_QWORD *)v43 = 0i64;
      *(_QWORD *)&vp[28] = 0i64;
      *(_DWORD *)&vp[24] = 0;
      Scaleform::Render::TreeRoot::SetViewport(v7, (Scaleform::Render::Viewport *)vp);
      Scaleform::Render::TreeNode::SetMatrix(v7, m);
      Scaleform::Render::TreeNode::SetMatrix(v8, &Scaleform::Render::Matrix2x4<float>::Identity);
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(v8, 2u);
      v36 = v57;
      WritableData[5] = *v57;
      WritableData[6] = v36[1];
      Scaleform::Render::TreeNode::SetBlendMode(v8, mode);
      ++v7->RefCount;
      v37 = image;
      v38 = image->pContext.pObject;
      if ( v38->pControlContext )
        v38->pControlContext->DIChangesRequired = 1;
      v37->pContext.pObject->vfptr->OnCapture(&v37->pContext.pObject->Scaleform::Render::ContextImpl::ContextCaptureNotify);
      Scaleform::Render::DICommand_Draw::DICommand_Draw(&v54, v37, v7, vars0);
      Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Draw>(v37, v39);
      v54.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
      if ( v54.pImage.pObject )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v54.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Draw,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v54.pImage.pObject);
      v41->Scaleform::Render::ShapeMeshProvider::Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->Release(&v41->Scaleform::Render::MeshProvider);
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v11 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v11)(v11, 1i64);
      if ( v8 )
      {
        v19 = v8->RefCount-- == 1;
        if ( v19 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
      }
    }
    if ( v7 )
    {
      v19 = v7->RefCount-- == 1;
      if ( v19 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
    }
  }
}

// File Line: 813
// RVA: 0x977FB0
void __fastcall Scaleform::Render::DrawableImage::FillRect(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *rect,
        unsigned int *color)
{
  unsigned int v5; // ebx
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  Scaleform::Render::DICommand_FillRect cmd; // [rsp+28h] [rbp-30h] BYREF

  v5 = *color;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_FillRect::`vftable;
  y2 = rect->y2;
  x2 = rect->x2;
  y1 = rect->y1;
  cmd.ApplyRect.x1 = rect->x1;
  cmd.ApplyRect.y1 = y1;
  cmd.ApplyRect.x2 = x2;
  cmd.ApplyRect.y2 = y2;
  cmd.FillColor.Raw = v5;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FillRect>(this, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_FillRect,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 819
// RVA: 0x97AB50
void __fastcall Scaleform::Render::DrawableImage::FloodFill(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Point<long> *pt,
        unsigned int *color)
{
  unsigned int v5; // ebx
  int y; // ecx
  Scaleform::Render::DICommand_FloodFill cmd; // [rsp+28h] [rbp-30h] BYREF

  v5 = *color;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_FloodFill::`vftable;
  y = pt->y;
  cmd.Pt.x = pt->x;
  cmd.Pt.y = y;
  cmd.FillColor.Raw = v5;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_FloodFill>(this, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_FloodFill,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 824
// RVA: 0x981620
Scaleform::Render::Rect<long> *__fastcall Scaleform::Render::DrawableImage::GetColorBoundsRect(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *result,
        unsigned int mask,
        unsigned int color,
        bool findColor)
{
  Scaleform::Render::DICommand_GetColorBoundsRect cmd; // [rsp+28h] [rbp-30h] BYREF

  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetColorBoundsRect::`vftable;
  cmd.Mask = mask;
  cmd.SearchColor = color;
  cmd.FindColor = findColor;
  cmd.Result = result;
  if ( !this->Transparent )
    cmd.Mask = mask & 0xFFFFFF;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetColorBoundsRect>(this, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetColorBoundsRect,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return result;
}

// File Line: 835
// RVA: 0x98A890
Scaleform::Render::Color *__fastcall Scaleform::Render::DrawableImage::GetPixel(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Color *result,
        unsigned int x,
        unsigned int y)
{
  Scaleform::Render::DrawableImage::GetPixel32(this, result, x, y);
  result->Channels.Alpha = 0;
  return result;
}

// File Line: 844
// RVA: 0x98A7C0
Scaleform::Render::Color *__fastcall Scaleform::Render::DrawableImage::GetPixel32(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Color *result,
        unsigned int x,
        unsigned int y)
{
  Scaleform::Render::DICommand_GetPixel32 cmd; // [rsp+28h] [rbp-40h] BYREF
  unsigned int v10; // [rsp+80h] [rbp+18h] BYREF

  if ( x >= this->ISize.Width || y >= this->ISize.Height || (x & 0x80000000) != 0 || (y & 0x80000000) != 0 )
  {
    result->Raw = 0;
  }
  else
  {
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
    cmd.pImage.pObject = this;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetPixel32::`vftable;
    cmd.X = x;
    cmd.Y = y;
    cmd.Result = (Scaleform::Render::Color *)&v10;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixel32>(this, &cmd);
    result->Raw = v10;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetPixel32,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  }
  return result;
}

// File Line: 856
// RVA: 0x98AA10
char __fastcall Scaleform::Render::DrawableImage::GetPixels(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DIPixelProvider *provider,
        Scaleform::Render::Rect<long> *sourceRect)
{
  signed int x2; // r14d
  signed int y2; // esi
  int x1; // edi
  int y1; // ebp
  char v9; // bl
  Scaleform::Render::DICommand_GetPixels cmd; // [rsp+28h] [rbp-60h] BYREF
  char v12; // [rsp+90h] [rbp+8h] BYREF

  x2 = sourceRect->x2;
  if ( (signed int)this->ISize.Width < x2 )
    return 0;
  y2 = sourceRect->y2;
  if ( (signed int)this->ISize.Height < y2 )
    return 0;
  x1 = sourceRect->x1;
  if ( sourceRect->x1 < 0 )
    return 0;
  y1 = sourceRect->y1;
  if ( y1 < 0 )
    return 0;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_GetPixels::`vftable;
  cmd.SourceRect.x1 = x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  cmd.Provider = provider;
  cmd.Result = (bool *)&v12;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_GetPixels>(this, &cmd);
  v9 = v12;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_GetPixels,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v9;
}

// File Line: 873
// RVA: 0x9913E0
void __fastcall Scaleform::Render::DrawableImage::Histogram(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *rect,
        unsigned int (*colors)[256])
{
  int y2; // r15d
  int x2; // r14d
  int y1; // esi
  int x1; // edi
  int *v10; // rax
  Scaleform::Render::DrawableImageContext *pObject; // rax
  _QWORD *v12; // rax
  _QWORD *v13; // rdi
  Scaleform::Render::DrawableImage *v14; // rcx
  int v15; // r8d
  int v16; // edx
  int v17; // ecx
  Scaleform::Render::DICommandQueue *v18; // rbx
  Scaleform::Render::DICommand v19; // [rsp+38h] [rbp-28h] BYREF
  int v20; // [rsp+48h] [rbp-18h]
  int v21; // [rsp+4Ch] [rbp-14h]
  int v22; // [rsp+50h] [rbp-10h]
  int v23; // [rsp+54h] [rbp-Ch]
  unsigned int (*v24)[256]; // [rsp+58h] [rbp-8h]
  char v25; // [rsp+A0h] [rbp+40h] BYREF
  _QWORD *v26; // [rsp+A8h] [rbp+48h]
  _QWORD *v27; // [rsp+B0h] [rbp+50h]

  memset(colors, 0, 0x1000ui64);
  if ( rect )
  {
    y2 = rect->y2;
    x2 = rect->x2;
    y1 = rect->y1;
    x1 = rect->x1;
  }
  else
  {
    v10 = (int *)this->vfptr[5].__vecDelDtor(this, &v25);
    y2 = v10[1];
    x2 = *v10;
    x1 = 0;
    y1 = 0;
  }
  v19.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  v19.pImage.pObject = this;
  v19.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Histogram::`vftable;
  v20 = x1;
  v21 = y1;
  v22 = x2;
  v23 = y2;
  v24 = colors;
  pObject = this->pContext.pObject;
  if ( pObject && pObject->pControlContext )
    pObject->pControlContext->DIChangesRequired = 1;
  if ( !Scaleform::Render::DICommand::ExecuteSWOnAddCommand(&v19, this) )
  {
    v12 = Scaleform::Render::DICommandQueue::allocCommandFromPage(
            this->pQueue.pObject,
            0x28u,
            &this->pQueue.pObject->QueueLock);
    v13 = v12;
    v26 = v12;
    if ( v12 )
    {
      v27 = v12;
      *v12 = &Scaleform::Render::DICommand::`vftable;
      v14 = v19.pImage.pObject;
      if ( v19.pImage.pObject )
      {
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v19.pImage.pObject->vfptr[1].__vecDelDtor)(v19.pImage.pObject);
        v14 = v19.pImage.pObject;
      }
      v13[1] = v14;
      *v13 = &Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Histogram,Scaleform::Render::DICommand>::`vftable;
      *v13 = &Scaleform::Render::DICommand_Histogram::`vftable;
      v15 = v23;
      v16 = v22;
      v17 = v21;
      *((_DWORD *)v13 + 4) = v20;
      *((_DWORD *)v13 + 5) = v17;
      *((_DWORD *)v13 + 6) = v16;
      *((_DWORD *)v13 + 7) = v15;
      v13[4] = v24;
    }
    if ( (((__int64 (__fastcall *)(Scaleform::Render::DICommand *))v19.vfptr->GetRenderCaps)(&v19) & 0x10) != 0 )
    {
      v18 = this->pQueue.pObject;
      _InterlockedExchangeAdd(&v18->RefCount, 1u);
      _InterlockedExchangeAdd(&v18->ExecuteCmd.pObject->RefCount, 1u);
      v18->pRTCommandQueue->vfptr->PushThreadCommand(v18->pRTCommandQueue, v18->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(v18->ExecuteCmd.pObject);
    }
  }
  v19.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v19.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v19.pImage.pObject->vfptr[2].__vecDelDtor)(v19.pImage.pObject);
}

// File Line: 893
// RVA: 0x9915C0
__int64 __fastcall Scaleform::Render::DrawableImage::HitTest(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Point<long> *firstPoint,
        Scaleform::Render::Rect<long> *secondImage,
        unsigned int alphaThreshold)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  unsigned __int8 v12; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [rsp+30h] [rbp-68h] BYREF
  unsigned __int8 v15; // [rsp+B8h] [rbp+20h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_HitTest::`vftable;
  cmd.SecondImage.pObject = 0i64;
  y2 = secondImage->y2;
  x2 = secondImage->x2;
  y1 = secondImage->y1;
  cmd.SecondArea.x1 = secondImage->x1;
  cmd.SecondArea.y1 = y1;
  cmd.SecondArea.x2 = x2;
  cmd.SecondArea.y2 = y2;
  y = firstPoint->y;
  cmd.FirstPoint.x = firstPoint->x;
  cmd.FirstPoint.y = y;
  cmd.FirstThreshold = alphaThreshold;
  cmd.SecondThreshold = 0;
  cmd.Result = (bool *)&v15;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(this, &cmd);
  v12 = v15;
  if ( cmd.SecondImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))cmd.SecondImage.pObject->vfptr[2].__vecDelDtor)(cmd.SecondImage.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_HitTest,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v12;
}

// File Line: 906
// RVA: 0x9916C0
__int64 __fastcall Scaleform::Render::DrawableImage::HitTest(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Image *secondImage,
        Scaleform::Render::Point<long> *firstPoint,
        Scaleform::Render::Point<long> *secondPoint,
        unsigned int firstThreshold,
        unsigned int secondThreshold)
{
  int y; // ecx
  int v11; // ecx
  unsigned __int8 v12; // bl
  Scaleform::Render::DICommand_HitTest cmd; // [rsp+30h] [rbp-68h] BYREF
  unsigned __int8 v15; // [rsp+A0h] [rbp+8h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_HitTest::`vftable;
  if ( secondImage )
    ((void (__fastcall *)(Scaleform::Render::Image *))secondImage->vfptr[1].__vecDelDtor)(secondImage);
  cmd.SecondImage.pObject = secondImage;
  *(_QWORD *)&cmd.SecondArea.x1 = 0i64;
  *(_QWORD *)&cmd.SecondArea.x2 = 0i64;
  y = firstPoint->y;
  cmd.FirstPoint.x = firstPoint->x;
  cmd.FirstPoint.y = y;
  v11 = secondPoint->y;
  cmd.SecondPoint.x = secondPoint->x;
  cmd.SecondPoint.y = v11;
  cmd.FirstThreshold = firstThreshold;
  cmd.SecondThreshold = secondThreshold;
  cmd.Result = (bool *)&v15;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_HitTest>(this, &cmd);
  v12 = v15;
  if ( cmd.SecondImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::Image *))cmd.SecondImage.pObject->vfptr[2].__vecDelDtor)(cmd.SecondImage.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_HitTest,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v12;
}

// File Line: 920
// RVA: 0x99A780
void __fastcall Scaleform::Render::DrawableImage::Merge(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        unsigned int redMult,
        unsigned int greenMult,
        unsigned int blueMult,
        unsigned int alphaMult)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  Scaleform::Render::DICommand_Merge cmd; // [rsp+28h] [rbp-50h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Merge::`vftable;
  cmd.RedMultiplier = redMult;
  cmd.GreenMultiplier = greenMult;
  cmd.BlueMultiplier = blueMult;
  cmd.AlphaMultiplier = alphaMult;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Merge>(this, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Merge>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Merge>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 928
// RVA: 0x99C6A0
void __fastcall Scaleform::Render::DrawableImage::Noise(
        Scaleform::Render::DrawableImage *this,
        unsigned int randomSeed,
        unsigned int low,
        unsigned int high,
        unsigned int channelMask,
        bool grayscale)
{
  Scaleform::Render::DICommand_Noise cmd; // [rsp+28h] [rbp-30h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Noise::`vftable;
  cmd.RandomSeed = randomSeed;
  cmd.Low = low;
  cmd.High = high;
  cmd.ChannelMask = channelMask;
  cmd.GrayScale = grayscale;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Noise>(this, &cmd);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_Noise,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

// File Line: 936
// RVA: 0x99CF00
void __fastcall Scaleform::Render::DrawableImage::PaletteMap(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        unsigned int **channels)
{
  Scaleform::Render::DICommand_PaletteMap *v6; // rax
  Scaleform::Render::DICommand_PaletteMap v7; // [rsp+38h] [rbp-50h] BYREF

  Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(&v7, this, source, sourceRect, destPoint, channels);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PaletteMap>(this, v6);
  v7.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable;
  if ( v7.Channels )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v7.Channels = 0i64;
  if ( v7.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(v7.pSource.pObject);
  v7.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v7.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_PaletteMap>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v7.pImage.pObject);
}

// File Line: 944
// RVA: 0x99EA70
void __fastcall Scaleform::Render::DrawableImage::PerlinNoise(
        Scaleform::Render::DrawableImage *this,
        float frequencyX,
        float frequencyY,
        unsigned int numOctaves,
        unsigned int randomSeed,
        bool stitch,
        bool fractal,
        unsigned int channelMask,
        bool grayScale,
        float *offsets,
        unsigned int offsetCount)
{
  Scaleform::Render::DICommand_PerlinNoise *v12; // rax
  Scaleform::Render::DICommand_PerlinNoise v13; // [rsp+68h] [rbp-C0h] BYREF

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
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PerlinNoise>(this, v12);
  v13.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v13.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v13.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PerlinNoise,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v13.pImage.pObject);
}

// File Line: 952
// RVA: 0x99EB30
__int64 __fastcall Scaleform::Render::DrawableImage::PixelDissolve(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        unsigned int randomSeed,
        unsigned int numPixels,
        unsigned int *fill)
{
  unsigned int v11; // ebx
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  unsigned int v16; // ebx
  Scaleform::Render::DICommand_PixelDissolve cmd; // [rsp+30h] [rbp-68h] BYREF

  v11 = *fill;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_PixelDissolve::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.RandomSeed = randomSeed;
  cmd.NumPixels = numPixels;
  cmd.Fill.Raw = v11;
  cmd.Result = (unsigned int *)&fill;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PixelDissolve>(this, &cmd);
  v16 = (unsigned int)fill;
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_PixelDissolve,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v16;
}

// File Line: 963
// RVA: 0x9ADC10
void __fastcall Scaleform::Render::DrawableImage::Scroll(Scaleform::Render::DrawableImage *this, int x, int y)
{
  Scaleform::Render::DICommand_Scroll *v4; // rax
  Scaleform::Render::DICommand_Scroll v5; // [rsp+28h] [rbp-40h] BYREF

  Scaleform::Render::DICommand_Scroll::DICommand_Scroll(&v5, this, x, y);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Scroll>(this, v4);
  if ( v5.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(v5.pSource.pObject);
  v5.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( v5.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Scroll>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(v5.pImage.pObject);
}

// File Line: 968
// RVA: 0x9B29A0
void __fastcall Scaleform::Render::DrawableImage::SetPixel(
        Scaleform::Render::DrawableImage *this,
        int x,
        int y,
        unsigned int *c)
{
  signed int v7; // ecx
  unsigned int v8; // ebx
  Scaleform::Render::DICommand_SetPixel32 cmd; // [rsp+28h] [rbp-30h] BYREF

  v7 = this->ISize.Height - 1;
  if ( x <= (signed int)(this->ISize.Width - 1) && x >= 0 && y <= v7 && y >= 0 )
  {
    v8 = *c;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
    cmd.pImage.pObject = this;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable;
    cmd.X = x;
    cmd.Y = y;
    cmd.Fill.Raw = v8;
    cmd.OverwriteAlpha = 0;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(this, &cmd);
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_SetPixel32,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  }
}

// File Line: 975
// RVA: 0x9B28D0
void __fastcall Scaleform::Render::DrawableImage::SetPixel32(
        Scaleform::Render::DrawableImage *this,
        int x,
        int y,
        unsigned int *c)
{
  signed int v7; // ecx
  unsigned int v8; // ebx
  Scaleform::Render::DICommand_SetPixel32 cmd; // [rsp+28h] [rbp-30h] BYREF

  v7 = this->ISize.Height - 1;
  if ( x <= (signed int)(this->ISize.Width - 1) && x >= 0 && y <= v7 && y >= 0 )
  {
    v8 = *c;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
    cmd.pImage.pObject = this;
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixel32::`vftable;
    cmd.X = x;
    cmd.Y = y;
    cmd.Fill.Raw = v8;
    cmd.OverwriteAlpha = 1;
    Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixel32>(this, &cmd);
    cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
    if ( cmd.pImage.pObject )
      ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_SetPixel32,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  }
}

// File Line: 983
// RVA: 0x9B2BA0
char __fastcall Scaleform::Render::DrawableImage::SetPixels(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::Rect<long> *inputRect,
        Scaleform::Render::DIPixelProvider *provider)
{
  int Height; // r14d
  signed int Width; // esi
  int y1; // ebp
  int y2; // eax
  int x2; // ecx
  int x1; // edi
  char v11; // bl
  Scaleform::Render::DICommand_SetPixels cmd; // [rsp+28h] [rbp-60h] BYREF
  char v14; // [rsp+90h] [rbp+8h] BYREF

  Height = this->ISize.Height;
  Width = this->ISize.Width;
  y1 = inputRect->y1;
  if ( Height < y1 )
    return 0;
  y2 = inputRect->y2;
  if ( y2 < 0 )
    return 0;
  x2 = inputRect->x2;
  if ( x2 < 0 )
    return 0;
  x1 = inputRect->x1;
  if ( Width < inputRect->x1 )
    return 0;
  if ( x1 < 0 )
    x1 = 0;
  if ( Width > x2 )
    Width = inputRect->x2;
  if ( y1 < 0 )
    y1 = 0;
  if ( Height > y2 )
    Height = inputRect->y2;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SetPixels::`vftable;
  cmd.DestRect.x1 = x1;
  cmd.DestRect.y1 = y1;
  cmd.DestRect.x2 = Width;
  cmd.DestRect.y2 = Height;
  cmd.Provider = provider;
  cmd.Result = (bool *)&v14;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_SetPixels>(this, &cmd);
  v11 = v14;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommandImpl<Scaleform::Render::DICommand_SetPixels,Scaleform::Render::DICommand>::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
  return v11;
}

// File Line: 1002
// RVA: 0x9B9DD0
void __fastcall Scaleform::Render::DrawableImage::Threshold(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        Scaleform::Render::Rect<long> *sourceRect,
        Scaleform::Render::Point<long> *destPoint,
        Scaleform::Render::DrawableImage::OperationType op,
        unsigned int threshold,
        unsigned int color,
        unsigned int mask,
        bool copySource)
{
  int y2; // r8d
  int x2; // edx
  int y1; // ecx
  int y; // ecx
  Scaleform::Render::DICommand_Threshold cmd; // [rsp+28h] [rbp-50h] BYREF

  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( this )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))this->vfptr[1].__vecDelDtor)(this);
  cmd.pImage.pObject = this;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_SourceRect::`vftable;
  if ( source )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))source->vfptr[1].__vecDelDtor)(source);
  cmd.pSource.pObject = source;
  y2 = sourceRect->y2;
  x2 = sourceRect->x2;
  y1 = sourceRect->y1;
  cmd.SourceRect.x1 = sourceRect->x1;
  cmd.SourceRect.y1 = y1;
  cmd.SourceRect.x2 = x2;
  cmd.SourceRect.y2 = y2;
  y = destPoint->y;
  cmd.DestPoint.x = destPoint->x;
  cmd.DestPoint.y = y;
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand_Threshold::`vftable;
  cmd.Operation = op;
  cmd.Threshold = threshold;
  cmd.ThresholdColor = color;
  cmd.Mask = mask;
  cmd.CopySource = copySource;
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_Threshold>(this, &cmd);
  if ( cmd.pSource.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pSource.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold>::Scaleform::Render::DICommand_SourceRect::vfptr[2].__vecDelDtor)(cmd.pSource.pObject);
  cmd.vfptr = (Scaleform::Render::DICommandVtbl *)&Scaleform::Render::DICommand::`vftable;
  if ( cmd.pImage.pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))cmd.pImage.pObject->Scaleform::Render::DICommand_SourceRectImpl<Scaleform::Render::DICommand_Threshold>::Scaleform::Render::DICommand_SourceRect::Scaleform::Render::DICommand::vfptr[2].__vecDelDtor)(cmd.pImage.pObject);
}

