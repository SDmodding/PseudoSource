// File Line: 460
// RVA: 0x89A600
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::MemoryContextImpl(Scaleform::GFx::AS2::MemoryContextImpl *this)
{
  Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *v1; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MemoryContext,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::`vftable;
  this->Heap = 0i64;
  this->StringMgr.pObject = 0i64;
  this->ASGC.pObject = 0i64;
  this->TextAllocator.pObject = 0i64;
  v1 = &this->LimHandler;
  v1->vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  v1->AllocCount = 0;
  v1->vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::`vftable;
  this->LimHandler.MemContext = 0i64;
  this->LimHandler.UserLevelLimit = 0i64;
  this->LimHandler.LastCollectionFootprint = 0i64;
  this->LimHandler.CurrentLimit = 0i64;
  this->LimHandler.HeapLimitMultiplier = 0.25;
  this->LimHandler.MemContext = this;
}

// File Line: 464
// RVA: 0x8A5EA0
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::~MemoryContextImpl(Scaleform::GFx::AS2::MemoryContextImpl *this)
{
  Scaleform::GFx::AS2::MemoryContextImpl *v1; // rbx
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::`vftable;
  this->Heap->vfptr->SetLimitHandler(this->Heap, 0i64);
  v1->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  v2 = (Scaleform::RefCountNTSImpl *)&v1->TextAllocator.pObject->vfptr;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->ASGC.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->StringMgr.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

