// File Line: 460
// RVA: 0x89A600
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::MemoryContextImpl(Scaleform::GFx::AS2::MemoryContextImpl *this)
{
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
  this->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  this->LimHandler.AllocCount = 0;
  this->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::`vftable;
  this->LimHandler.MemContext = 0i64;
  this->LimHandler.UserLevelLimit = 0i64;
  this->LimHandler.LastCollectionFootprint = 0i64;
  this->LimHandler.CurrentLimit = 0i64;
  this->LimHandler.HeapLimitMultiplier = 0.25;
  this->LimHandler.MemContext = this;
}

// File Line: 464
// RVA: 0x8A5EA0
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::~MemoryContextImpl(
        Scaleform::GFx::AS2::MemoryContextImpl *this)
{
  Scaleform::Render::Text::Allocator *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MemoryContextImpl::`vftable;
  this->Heap->vfptr->SetLimitHandler(this->Heap, 0i64);
  this->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  pObject = this->TextAllocator.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->ASGC.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)this->StringMgr.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

