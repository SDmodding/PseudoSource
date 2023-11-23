// File Line: 259
// RVA: 0x89A6B0
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::MemoryContextImpl(Scaleform::GFx::AS3::MemoryContextImpl *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MemoryContext,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MemoryContextImpl::`vftable;
  this->Heap = 0i64;
  this->StringMgr.pObject = 0i64;
  this->ASGC.pObject = 0i64;
  this->TextAllocator.pObject = 0i64;
  this->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  this->LimHandler.AllocCount = 0;
  this->LimHandler.vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::`vftable;
  this->LimHandler.MemContext = 0i64;
  this->LimHandler.UserLevelLimit = 0i64;
  this->LimHandler.LastCollectionFootprint = 0i64;
  this->LimHandler.CurrentLimit = 0i64;
  this->LimHandler.HeapLimitMultiplier = 0.25;
  this->LimHandler.MemContext = this;
}

// File Line: 263
// RVA: 0x8A5F30
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::~MemoryContextImpl(
        Scaleform::GFx::AS3::MemoryContextImpl *this)
{
  Scaleform::Render::Text::Allocator *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MemoryContextImpl::`vftable;
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

// File Line: 324
// RVA: 0x77A790
void __fastcall Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(
        Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *this,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::Resource *data)
{
  Scaleform::GFx::AS3::Abc::File::File(this);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::`vftable;
  if ( pdefImpl )
    Scaleform::Render::RenderBuffer::AddRef(pdefImpl);
  this->pDefImpl.pObject = pdefImpl;
  if ( data )
    Scaleform::Render::RenderBuffer::AddRef(data);
  this->pAbcData.pObject = (Scaleform::GFx::AS3::AbcDataBuffer *)data;
}

// File Line: 426
// RVA: 0x78C6C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::MemContextPtr::~MemContextPtr(
        Scaleform::GFx::AS3::MovieRoot::MemContextPtr *this)
{
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->pObject->ASGC.pObject, 0i64, 1u);
  if ( this->pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->pObject);
}

// File Line: 641
// RVA: 0x7B14D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::StickyVarNode::Assign(
        Scaleform::GFx::AS3::MovieRoot::StickyVarNode *this,
        Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *pNode; // rsi
  Scaleform::GFx::ASStringNode *v5; // rcx

  pNode = node->Name.pNode;
  ++pNode->RefCount;
  v5 = this->Name.pNode;
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->Name.pNode = pNode;
  this->Permanent = node->Permanent;
  Scaleform::GFx::AS3::Value::Assign(&this->mValue, (Scaleform::GFx::AS3::Value *)&node[1]);
}

// File Line: 723
// RVA: 0x7F68A0
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *p_ActionQueue; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *NewEntry; // r8
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // rax

  p_ActionQueue = &this->ActionQueue;
  v3 = lvl;
  NewEntry = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(&this->ActionQueue);
  pInsertEntry = p_ActionQueue->Entries[v3].pInsertEntry;
  if ( pInsertEntry )
  {
    NewEntry->pNextEntry = pInsertEntry->pNextEntry;
    p_ActionQueue->Entries[v3].pInsertEntry->pNextEntry = NewEntry;
  }
  else
  {
    NewEntry->pNextEntry = p_ActionQueue->Entries[v3].pActionRoot;
    p_ActionQueue->Entries[v3].pActionRoot = NewEntry;
  }
  p_ActionQueue->Entries[v3].pInsertEntry = NewEntry;
  if ( !NewEntry->pNextEntry )
    p_ActionQueue->Entries[v3].pLastEntry = NewEntry;
  ++p_ActionQueue->ModId;
  return NewEntry;
}

// File Line: 828
// RVA: 0x7EFFA0
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::AS3::MovieRoot::GetStringManager(
        Scaleform::GFx::AS3::MovieRoot *this)
{
  return this->MemContext.pObject->StringMgr.pObject;
}

// File Line: 1126
// RVA: 0x7EBA30
Scaleform::GFx::LogState *__fastcall Scaleform::GFx::AS3::ASVM::GetLogState(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::GFx::LogState *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+40h] [rbp+8h] BYREF

  pObject = Scaleform::GFx::StateBag::GetLogState(&this->pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return pObject;
}

// File Line: 1130
// RVA: 0x7EB9E0
Scaleform::Log *__fastcall Scaleform::GFx::AS3::ASVM::GetLog(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::Log *pObject; // rbx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h] BYREF

  pObject = Scaleform::GFx::StateBag::GetLog(&this->pMovieRoot->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return pObject;
}

