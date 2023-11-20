// File Line: 259
// RVA: 0x89A6B0
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::MemoryContextImpl(Scaleform::GFx::AS3::MemoryContextImpl *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit *v1; // [rsp+28h] [rbp+10h]

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
  v1 = &this->LimHandler;
  v1->vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable;
  v1->AllocCount = 0;
  v1->vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::`vftable;
  this->LimHandler.MemContext = 0i64;
  this->LimHandler.UserLevelLimit = 0i64;
  this->LimHandler.LastCollectionFootprint = 0i64;
  this->LimHandler.CurrentLimit = 0i64;
  this->LimHandler.HeapLimitMultiplier = 0.25;
  this->LimHandler.MemContext = this;
}

// File Line: 263
// RVA: 0x8A5F30
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::~MemoryContextImpl(Scaleform::GFx::AS3::MemoryContextImpl *this)
{
  Scaleform::GFx::AS3::MemoryContextImpl *v1; // rbx
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::MemoryContextImpl::`vftable;
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

// File Line: 324
// RVA: 0x77A790
void __fastcall Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::AbcFileWithMovieDef(Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *this, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::AS3::AbcDataBuffer *data)
{
  Scaleform::GFx::Resource *v3; // rdi
  Scaleform::GFx::MovieDefImpl *v4; // rsi
  Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef *v5; // rbx

  v3 = (Scaleform::GFx::Resource *)data;
  v4 = pdefImpl;
  v5 = this;
  Scaleform::GFx::AS3::Abc::File::File((Scaleform::GFx::AS3::Abc::File *)&this->vfptr);
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::ASVM::AbcFileWithMovieDef::`vftable;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v4->vfptr);
  v5->pDefImpl.pObject = v4;
  if ( v3 )
    Scaleform::Render::RenderBuffer::AddRef(v3);
  v5->pAbcData.pObject = (Scaleform::GFx::AS3::AbcDataBuffer *)v3;
}

// File Line: 426
// RVA: 0x78C6C0
void __fastcall Scaleform::GFx::AS3::MovieRoot::MemContextPtr::~MemContextPtr(Scaleform::GFx::AS3::MovieRoot::MemContextPtr *this)
{
  Scaleform::Render::RenderBuffer **v1; // rbx

  v1 = (Scaleform::Render::RenderBuffer **)this;
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->pObject->ASGC.pObject, 0i64, 1u);
  if ( *v1 )
    Scaleform::RefCountImpl::Release(*v1);
}

// File Line: 641
// RVA: 0x7B14D0
void __fastcall Scaleform::GFx::AS3::MovieRoot::StickyVarNode::Assign(Scaleform::GFx::AS3::MovieRoot::StickyVarNode *this, Scaleform::GFx::MovieImpl::StickyVarNode *node)
{
  Scaleform::GFx::ASStringNode *v2; // rsi
  Scaleform::GFx::AS3::MovieRoot::StickyVarNode *v3; // rbx
  Scaleform::GFx::MovieImpl::StickyVarNode *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = node->Name.pNode;
  v3 = this;
  v4 = node;
  ++v2->RefCount;
  v5 = this->Name.pNode;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->Name.pNode = v2;
  v3->Permanent = v4->Permanent;
  Scaleform::GFx::AS3::Value::Assign(&v3->mValue, (Scaleform::GFx::AS3::Value *)&v4[1]);
}

// File Line: 723
// RVA: 0x7F68A0
Scaleform::GFx::AS3::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(Scaleform::GFx::AS3::MovieRoot *this, Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v4; // r8
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **v5; // rax

  v2 = &this->ActionQueue;
  v3 = lvl;
  v4 = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(&this->ActionQueue);
  v5 = &v2->Entries[v3].pInsertEntry->pNextEntry;
  if ( v5 )
  {
    v4->pNextEntry = *v5;
    v2->Entries[v3].pInsertEntry->pNextEntry = v4;
  }
  else
  {
    v4->pNextEntry = v2->Entries[v3].pActionRoot;
    v2->Entries[v3].pActionRoot = v4;
  }
  v2->Entries[v3].pInsertEntry = v4;
  if ( !v4->pNextEntry )
    v2->Entries[v3].pLastEntry = v4;
  ++v2->ModId;
  return v4;
}

// File Line: 828
// RVA: 0x7EFFA0
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::AS3::MovieRoot::GetStringManager(Scaleform::GFx::AS3::MovieRoot *this)
{
  return this->MemContext.pObject->StringMgr.pObject;
}

// File Line: 1126
// RVA: 0x7EBA30
Scaleform::GFx::LogState *__fastcall Scaleform::GFx::AS3::ASVM::GetLogState(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::GFx::LogState *v1; // rbx
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+40h] [rbp+8h]

  v1 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&this->pMovieRoot->pMovieImpl->vfptr, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v1;
}

// File Line: 1130
// RVA: 0x7EB9E0
Scaleform::Log *__fastcall Scaleform::GFx::AS3::ASVM::GetLog(Scaleform::GFx::AS3::ASVM *this)
{
  Scaleform::Log *v1; // rbx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+40h] [rbp+8h]

  v1 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&this->pMovieRoot->pMovieImpl->vfptr, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v1;
}

