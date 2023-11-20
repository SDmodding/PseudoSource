// File Line: 44
// RVA: 0x6CAC00
void __fastcall Scaleform::GFx::AS2::MovieRoot::MovieRoot(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::AS2::MemoryContextImpl *memContext, Scaleform::GFx::MovieImpl *pmovie, Scaleform::GFx::ASSupport *pas)
{
  Scaleform::GFx::Resource *v4; // rdi
  Scaleform::GFx::MovieImpl *v5; // rbp
  Scaleform::GFx::AS2::MemoryContextImpl *v6; // rsi
  Scaleform::GFx::AS2::MovieRoot *v7; // rbx
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::RefCountNTSImpl *v9; // rcx
  signed __int64 v10; // [rsp+68h] [rbp+10h]

  v4 = (Scaleform::GFx::Resource *)pas;
  v5 = pmovie;
  v6 = memContext;
  v7 = this;
  Scaleform::GFx::ASMovieRootBase::ASMovieRootBase((Scaleform::GFx::ASMovieRootBase *)&this->vfptr, pas);
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable';
  v7->TopNode.pObject = 0i64;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef(v4);
  v7->pASSupport.pObject = (Scaleform::GFx::ASSupport *)v4;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v7->MemContext.pObject = v6;
  *(_QWORD *)&v7->NumAdvancesSinceCollection = 0i64;
  v7->pGlobalContext.pObject = 0i64;
  v7->ExternalIntfRetVal.T.Type = 0;
  v8 = v6->Heap;
  v7->ActionQueue.Entries[0].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[0].pLastEntry = 0i64;
  v7->ActionQueue.Entries[0].pActionRoot = 0i64;
  v7->ActionQueue.Entries[1].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[1].pLastEntry = 0i64;
  v7->ActionQueue.Entries[1].pActionRoot = 0i64;
  v7->ActionQueue.Entries[2].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[2].pLastEntry = 0i64;
  v7->ActionQueue.Entries[2].pActionRoot = 0i64;
  v7->ActionQueue.Entries[3].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[3].pLastEntry = 0i64;
  v7->ActionQueue.Entries[3].pActionRoot = 0i64;
  v7->ActionQueue.Entries[4].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[4].pLastEntry = 0i64;
  v7->ActionQueue.Entries[4].pActionRoot = 0i64;
  v7->ActionQueue.Entries[5].pInsertEntry = 0i64;
  v7->ActionQueue.Entries[5].pLastEntry = 0i64;
  v7->ActionQueue.Entries[5].pActionRoot = 0i64;
  v7->ActionQueue.pHeap = v8;
  v7->ActionQueue.ModId = 1;
  v7->ActionQueue.pFreeEntry = 0i64;
  v7->ActionQueue.LastSessionId = 1;
  *(_QWORD *)&v7->ActionQueue.CurrentSessionId = 1i64;
  Scaleform::GFx::AS2::StringManager::StringManager(&v7->BuiltinsMgr, v6->StringMgr.pObject);
  v10 = (signed __int64)&v7->SpritesWithHitArea;
  *(_OWORD *)v10 = 0ui64;
  *(_QWORD *)(v10 + 16) = 0i64;
  v7->pMovieImpl = v5;
  v7->pASMouseListener = 0i64;
  v7->pInvokeAliases = 0i64;
  v9 = (Scaleform::RefCountNTSImpl *)&v7->pGlobalContext.pObject->vfptr;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  v7->pGlobalContext.pObject = 0i64;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(v7->pMovieImpl, (Scaleform::GFx::ASMovieRootBase *)&v7->vfptr);
  Scaleform::GFx::AS2::MovieRoot::CreateObjectInterface(v7, v7->pMovieImpl);
}

// File Line: 58
// RVA: 0x6D2130
void __fastcall Scaleform::GFx::AS2::MovieRoot::~MovieRoot(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rbx
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  bool v6; // zf
  Scaleform::Render::RenderBuffer *v7; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable';
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>(&this->SpritesWithHitArea.Data);
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(v1->BuiltinsMgr.pStringManager, v1->BuiltinsMgr.Builtins, 0x9Cu);
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType::~ActionQueueType(&v1->ActionQueue);
  if ( v1->ExternalIntfRetVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v1->ExternalIntfRetVal);
  v2 = (Scaleform::RefCountNTSImpl *)&v1->pGlobalContext.pObject->vfptr;
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->MemContext.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pASSupport.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::ContextImpl::Entry *)&v1->TopNode.pObject->0;
  if ( v5 )
  {
    v6 = v5->RefCount-- == 1;
    if ( v6 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  v7 = (Scaleform::Render::RenderBuffer *)v1->pASSupport.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 62
// RVA: 0x71FC00
void __fastcall Scaleform::GFx::AS2::MovieRoot::Shutdown(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rdi
  Scaleform::Render::ContextImpl::Entry *v2; // rcx
  bool v3; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v4; // rbx
  Scaleform::GFx::AS2::GlobalContext *v5; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v8; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy> *)&this->SpritesWithHitArea.Data.Data,
    &this->SpritesWithHitArea,
    0i64);
  v2 = (Scaleform::Render::ContextImpl::Entry *)&v1->TopNode.pObject->0;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  v1->TopNode.pObject = 0i64;
  v1->pASMouseListener = 0i64;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->pInvokeAliases->mHash.pTable;
  if ( v4 )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(v4);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
  v1->pInvokeAliases = 0i64;
  Scaleform::GFx::AS2::Value::DropRefs(&v1->ExternalIntfRetVal);
  v1->ExternalIntfRetVal.T.Type = 0;
  Scaleform::GFx::AS2::GlobalContext::PreClean(v1->pGlobalContext.pObject, 1);
  v1->pGlobalContext.pObject->pMovieRoot = 0i64;
  v5 = v1->pGlobalContext.pObject;
  v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->pGlobal.pObject->vfptr;
  if ( v6 )
  {
    v7 = v6->RefCount;
    if ( v7 & 0x3FFFFFF )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  v5->pGlobal.pObject = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v5->RegisteredClasses.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v5->BuiltinClassesRegistry.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&v5->Prototypes.mHash.pTable);
  v5->pMovieRoot = 0i64;
  v8.pActionQueue = &v1->ActionQueue;
  v8.ModId = 0;
  v8.CurrentPrio = 0;
  v8.pLastEntry = 0i64;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v8) )
    ;
  if ( v8.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v8.pActionQueue, v8.pLastEntry);
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
    v1->MemContext.pObject->ASGC.pObject,
    v1->pMovieImpl->AdvanceStats.pObject);
}

// File Line: 92
// RVA: 0x71A130
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetMovie(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::MovieImpl *pmovie)
{
  Scaleform::GFx::MovieImpl *v2; // rbx
  Scaleform::GFx::AS2::MovieRoot *v3; // rdi
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::GlobalContext *v5; // rax
  Scaleform::GFx::AS2::GlobalContext *v6; // rbx
  Scaleform::RefCountNTSImpl *v7; // rcx

  v2 = pmovie;
  v3 = this;
  this->pMovieImpl = pmovie;
  v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64))pmovie->pHeap->vfptr->Alloc)(
                                               this,
                                               120i64);
  if ( v4 )
  {
    Scaleform::GFx::AS2::GlobalContext::GlobalContext(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::RefCountNTSImpl *)&v3->pGlobalContext.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v3->pGlobalContext.pObject = v6;
}

// File Line: 98
// RVA: 0x6FCAE0
char __fastcall Scaleform::GFx::AS2::MovieRoot::Init(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  Scaleform::GFx::MovieDefImpl *v2; // rsi
  Scaleform::GFx::AS2::MovieRoot *v3; // rdi
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::GlobalContext *v5; // rax
  Scaleform::GFx::AS2::GlobalContext *v6; // rbx
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::Render::TreeNode *v8; // rbx
  Scaleform::Render::ContextImpl::Entry *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASSupport *v11; // rcx
  Scaleform::GFx::Sprite *v12; // rbx
  Scaleform::GFx::MovieDataDef *v14; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::MovieDefImpl *v15; // [rsp+40h] [rbp-18h]
  __int64 v16; // [rsp+48h] [rbp-10h]
  Scaleform::MemoryHeap *v17; // [rsp+60h] [rbp+8h]
  void *v18; // [rsp+68h] [rbp+10h]

  v2 = pmovieDef;
  v3 = this;
  v17 = this->pMovieImpl->pHeap;
  v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64))v17->vfptr->Alloc)(
                                               this,
                                               120i64);
  v18 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::GlobalContext::GlobalContext(v4, v3->pMovieImpl);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::RefCountNTSImpl *)&v3->pGlobalContext.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v3->pGlobalContext.pObject = v6;
  v8 = (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&v3->pMovieImpl->RenderContext);
  v9 = (Scaleform::Render::ContextImpl::Entry *)&v3->TopNode.pObject->0;
  if ( v9 )
  {
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
  }
  v3->TopNode.pObject = (Scaleform::Render::TreeContainer *)v8;
  Scaleform::Render::TreeContainer::Insert(
    (Scaleform::Render::TreeContainer *)&v3->pMovieImpl->pRenderRoot.pObject->0,
    0i64,
    v8);
  v14 = v2->pBindData.pObject->pDataDef.pObject;
  v15 = v2;
  v16 = 0i64;
  v11 = v3->pASSupport.pObject;
  LODWORD(v17) = 0x40000;
  v12 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, Scaleform::MemoryHeap **, signed int))v11->vfptr[4].__vecDelDtor)(
                                    v11,
                                    v3->pMovieImpl,
                                    &v14,
                                    0i64,
                                    &v17,
                                    3);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v12, 1);
  v18 = v12;
  Scaleform::GFx::AS2::AvmSprite::SetLevel(
    (Scaleform::GFx::AS2::AvmSprite *)((char *)v12 + 4 * (unsigned __int8)v12->AvmObjOffset),
    0);
  Scaleform::GFx::MovieImpl::SetLevelMovie(v3->pMovieImpl, 0, (Scaleform::GFx::DisplayObjContainer *)&v12->vfptr);
  ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))v3->vfptr[38].__vecDelDtor)(v3);
  v3->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v12);
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))v12->vfptr[39].__vecDelDtor)(v12);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
  return 1;
}

// File Line: 132
// RVA: 0x6DA500
void __fastcall Scaleform::GFx::AS2::MovieRoot::AdvanceFrame(Scaleform::GFx::AS2::MovieRoot *this, bool nextFrame)
{
  if ( nextFrame )
    Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(
      this->MemContext.pObject->ASGC.pObject,
      &this->NumAdvancesSinceCollection,
      &this->LastCollectionFrame,
      this->pMovieImpl->AdvanceStats.pObject);
}

// File Line: 142
// RVA: 0x6EC110
void __fastcall Scaleform::GFx::AS2::MovieRoot::ForceCollect(Scaleform::GFx::AS2::MovieRoot *this, unsigned int __formal)
{
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    this->pMovieImpl->AdvanceStats.pObject);
}

// File Line: 151
// RVA: 0x6EC130
void __fastcall Scaleform::GFx::AS2::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MemoryContextImpl *v1; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v2; // rbx

  v1 = this->MemContext.pObject;
  v2 = v1->ASGC.pObject;
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(v1->ASGC.pObject, this->pMovieImpl->AdvanceStats.pObject);
  if ( !(v2->Flags & 1) && !v2->Roots.Size )
    Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)v2->Roots.gap0);
  *(_QWORD *)&v2->MaxRootCount = v2->PresetMaxRootCount;
}

// File Line: 161
// RVA: 0x6EDBE0
void __fastcall Scaleform::GFx::AS2::MovieRoot::GenerateMouseEvents(Scaleform::GFx::AS2::MovieRoot *this, unsigned int mouseIndex)
{
  __int64 v2; // r12
  Scaleform::GFx::AS2::MovieRoot *v3; // rbx
  unsigned int v4; // er8
  Scaleform::GFx::MovieImpl *v5; // r9
  unsigned __int64 v6; // r10
  __int64 v7; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v8; // r9
  Scaleform::GFx::InteractiveObject *v9; // rcx
  signed int v10; // esi
  signed __int64 v11; // rdi
  Scaleform::GFx::InteractiveObject *v12; // rbx
  unsigned int v13; // edx
  char v14; // r10
  char v15; // r14
  unsigned __int8 v16; // r15
  signed __int64 v17; // r9
  Scaleform::GFx::InteractiveObject *v18; // r8
  Scaleform::GFx::InteractiveObject *v19; // rax
  signed int v20; // esi
  signed int v21; // eax
  signed int v22; // eax
  signed int v23; // ecx
  char v24; // cl
  signed int v25; // eax
  char v26; // al
  char v27; // cl
  signed int v28; // eax
  char v29; // cl
  signed int v30; // eax
  char v31; // al
  char v32; // dl
  Scaleform::WeakPtrProxy *v33; // rsi
  _DWORD *v34; // rdx
  bool v35; // zf
  _DWORD *v36; // rdx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::InteractiveObject *v38; // [rsp+28h] [rbp-30h]
  __int64 v39; // [rsp+30h] [rbp-28h]
  __int64 v40; // [rsp+38h] [rbp-20h]
  int v41; // [rsp+40h] [rbp-18h]
  unsigned __int8 v42; // [rsp+44h] [rbp-14h]
  char v43; // [rsp+48h] [rbp-10h]
  char v44; // [rsp+49h] [rbp-Fh]
  __int16 v45; // [rsp+4Ah] [rbp-Eh]
  signed int v46; // [rsp+A0h] [rbp+48h]
  char v47; // [rsp+A8h] [rbp+50h]
  int v48; // [rsp+B0h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v49; // [rsp+B8h] [rbp+60h]

  v39 = -2i64;
  v2 = mouseIndex;
  v3 = this;
  v4 = 0;
  v5 = this->pMovieImpl;
  v6 = v5->MovieLevels.Data.Size;
  if ( v6 )
  {
    v7 = 0i64;
    v8 = v5->MovieLevels.Data.Data;
    while ( v8[v7].Level )
    {
      v7 = ++v4;
      if ( v4 >= v6 )
        goto LABEL_7;
    }
    v9 = v8[v4].pSprite.pObject;
  }
  else
  {
LABEL_7:
    v9 = 0i64;
  }
  v10 = 1;
  if ( *(_BYTE *)(*(_QWORD *)(((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v9->vfptr
                                                                                          + 4
                                                                                          * (unsigned __int8)v9->AvmObjOffset))[30].__vecDelDtor)()
                            + 232)
                + 104i64) == 1 )
    v10 = 16;
  v46 = v10;
  if ( (unsigned int)v2 < 6 )
    v11 = (signed __int64)&v3->pMovieImpl->mMouseState[v2];
  else
    v11 = 0i64;
  Scaleform::GFx::MouseState::GetActiveEntity((Scaleform::GFx::MouseState *)v11, &result);
  Scaleform::GFx::MouseState::GetTopmostEntity((Scaleform::GFx::MouseState *)v11, &v49);
  v12 = result.pObject;
  if ( result.pObject && (LOBYTE(result.pObject->Flags) >> 4) & 1 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
    v12 = 0i64;
    result.pObject = 0i64;
  }
  if ( v49.pObject && (LOBYTE(v49.pObject->Flags) >> 4) & 1 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v49.pObject->vfptr);
    v49.pObject = 0i64;
    v12 = result.pObject;
  }
  if ( v12 )
  {
    ++v12->RefCount;
    v12 = result.pObject;
  }
  v38 = v12;
  v13 = *(_DWORD *)(v11 + 52) ^ *(_DWORD *)(v11 + 48);
  v48 = *(_DWORD *)(v11 + 52) ^ *(_DWORD *)(v11 + 48);
  v14 = 0;
  v47 = 0;
  v15 = (*(_BYTE *)(v11 + 76) >> 2) & 1;
  v16 = 0;
  v17 = 0xFFFFFFFFi64;
  v18 = result.pObject;
  v19 = v49.pObject;
  if ( (_BYTE)v10 )
  {
    while ( 1 )
    {
      v20 = 1 << v16;
      if ( !((v13 >> v16) & 1) )
        break;
      if ( v20 & *(_DWORD *)(v11 + 52) )
      {
        if ( !(v20 & *(_DWORD *)(v11 + 48)) && v18 )
        {
          if ( *(_BYTE *)(v11 + 76) & 4 )
          {
            v21 = 2048;
            if ( v16 )
              v21 = 0x100000;
            LODWORD(v40) = v21;
            *(__int64 *)((char *)&v40 + 4) = 0i64;
            v45 = 0;
            v42 = v16;
            v44 = v2;
            v43 = 0;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject *, signed __int64))v18->vfptr[100].__vecDelDtor)(
              v18,
              &v40,
              v18,
              0xFFFFFFFFi64);
            v18 = result.pObject;
            v19 = v49.pObject;
          }
          else
          {
            if ( !((v18->Flags >> 14) & 1) )
            {
              v22 = 4096;
              if ( v16 )
                v22 = 0x200000;
              LODWORD(v40) = v22;
              *(__int64 *)((char *)&v40 + 4) = 0i64;
              v45 = 0;
              v42 = v16;
              v44 = v2;
              v43 = 0;
              ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject *, signed __int64))v18->vfptr[100].__vecDelDtor)(
                v18,
                &v40,
                v18,
                0xFFFFFFFFi64);
              v18 = result.pObject;
              v19 = v49.pObject;
            }
            v47 = 1;
          }
        }
        if ( v20 & *(_DWORD *)(v11 + 52) )
          goto LABEL_74;
      }
      if ( !(v20 & *(_DWORD *)(v11 + 48)) )
        goto LABEL_74;
      if ( v19 )
      {
        ++v19->RefCount;
        v18 = result.pObject;
        v19 = v49.pObject;
      }
      if ( v12 )
      {
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
        v18 = result.pObject;
        v19 = v49.pObject;
      }
      v12 = v19;
      v38 = v19;
      if ( v19 )
      {
        v23 = 1024;
        if ( v16 )
          v23 = 0x80000;
        LODWORD(v40) = v23;
        *(__int64 *)((char *)&v40 + 4) = 0i64;
        v45 = 0;
        v42 = v16;
        v44 = v2;
        v43 = 0;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::RefCountNTSImplCoreVtbl *, signed __int64))v19->vfptr[100].__vecDelDtor)(
          v19,
          &v40,
          v19->vfptr,
          v17);
LABEL_72:
        v18 = result.pObject;
        v19 = v49.pObject;
      }
      v15 = 1;
LABEL_74:
      ++v16;
      v17 = 0xFFFFFFFFi64;
      v13 = v48;
      if ( v16 >= (unsigned __int8)v46 )
      {
        v17 = 0xFFFFFFFFi64;
        v14 = v47;
        goto LABEL_76;
      }
    }
    if ( !(v20 & *(_DWORD *)(v11 + 48)) )
      goto LABEL_74;
    if ( *(_BYTE *)(v11 + 76) & 4 )
    {
      if ( v19 != v18 )
      {
        if ( v18 )
        {
          v26 = v18->RollOverCnt;
          if ( v26 )
          {
            v27 = v26 - 1;
            v18->RollOverCnt = v26 - 1;
          }
          else
          {
            v27 = -1;
          }
          v28 = 0x10000;
          if ( v16 )
            v28 = 0x800000;
          LODWORD(v40) = v28;
          *(__int64 *)((char *)&v40 + 4) = 0i64;
          v45 = 0;
          v42 = v16;
          v44 = v2;
          v43 = v27;
          ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject *, signed __int64))v18->vfptr[100].__vecDelDtor)(
            v18,
            &v40,
            v18,
            0xFFFFFFFFi64);
          v18 = result.pObject;
          v19 = v49.pObject;
        }
        v15 = 0;
      }
    }
    else if ( v19 == v18 )
    {
      if ( v18 )
      {
        v24 = v18->RollOverCnt;
        v18->RollOverCnt = v24 + 1;
        v25 = 0x8000;
        if ( v16 )
          v25 = 0x400000;
        LODWORD(v40) = v25;
        *(__int64 *)((char *)&v40 + 4) = 0i64;
        v45 = 0;
        v42 = v16;
        v44 = v2;
        v43 = v24;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject *, signed __int64))v18->vfptr[100].__vecDelDtor)(
          v18,
          &v40,
          v18,
          0xFFFFFFFFi64);
        v18 = result.pObject;
        v19 = v49.pObject;
      }
      v15 = 1;
    }
    if ( v18 && !((v18->Flags >> 14) & 1) || !v19 || v19 == v18 || !((v19->Flags >> 14) & 1) )
      goto LABEL_74;
    ++v19->RefCount;
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
    v12 = v49.pObject;
    v38 = v49.pObject;
    v29 = v49.pObject->RollOverCnt;
    v49.pObject->RollOverCnt = v29 + 1;
    v30 = 0x8000;
    if ( v16 )
      v30 = 0x400000;
    LODWORD(v40) = v30;
    *(__int64 *)((char *)&v40 + 4) = 0i64;
    v45 = 0;
    v42 = v16;
    v44 = v2;
    v43 = v29;
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::GFx::InteractiveObject *, signed __int64))v12->vfptr[100].__vecDelDtor)(
      v12,
      &v40,
      v18,
      v17);
    goto LABEL_72;
  }
LABEL_76:
  if ( !(*(_BYTE *)(v11 + 52) & 1) && v19 != v18 )
  {
    if ( !v14 && v18 )
    {
      v31 = v18->RollOverCnt;
      if ( v31 )
      {
        LOBYTE(v17) = v31 - 1;
        v18->RollOverCnt = v31 - 1;
      }
      v40 = 0x4000i64;
      v41 = 0;
      v45 = 0;
      v42 = 0;
      v44 = v2;
      v43 = v17;
      v18->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v18->vfptr, (unsigned int)&v40);
      v19 = v49.pObject;
    }
    if ( v19 )
    {
      ++v19->RefCount;
      v19 = v49.pObject;
    }
    if ( v12 )
    {
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
      v19 = v49.pObject;
    }
    v12 = v19;
    v38 = v19;
    if ( v19 )
    {
      v32 = v19->RollOverCnt;
      v19->RollOverCnt = v32 + 1;
      v40 = 0x2000i64;
      v41 = 0;
      v45 = 0;
      v42 = 0;
      v44 = v2;
      v43 = v32;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64 *, Scaleform::RefCountNTSImplCoreVtbl *, signed __int64))v19->vfptr[100].__vecDelDtor)(
        v19,
        &v40,
        v19->vfptr,
        v17);
    }
    v15 = 1;
  }
  *(_BYTE *)(v11 + 76) &= 0xFBu;
  *(_BYTE *)(v11 + 76) |= 4 * (v15 & 1);
  if ( v12 )
  {
    v33 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v12->vfptr);
    v34 = *(_DWORD **)(v11 + 16);
    if ( v34 )
    {
      v35 = (*v34)-- == 1;
      if ( v35 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    *(_QWORD *)(v11 + 16) = v33;
  }
  else
  {
    v36 = *(_DWORD **)(v11 + 16);
    if ( v36 )
    {
      v35 = (*v36)-- == 1;
      if ( v35 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, _DWORD *, Scaleform::GFx::InteractiveObject *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v36,
          v18,
          v17);
    }
    *(_QWORD *)(v11 + 16) = 0i64;
  }
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
  if ( v49.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v49.pObject->vfptr);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
}

// File Line: 317
// RVA: 0x71A0F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetMemoryParams(Scaleform::GFx::AS2::MovieRoot *this, unsigned int frameBetweenCollections, unsigned int maxRootCount)
{
  Scaleform::GFx::AS2::ASRefCountCollector *v3; // rcx
  unsigned int v4; // eax

  v3 = this->MemContext.pObject->ASGC.pObject;
  v4 = 0;
  if ( frameBetweenCollections != -1 )
    v4 = frameBetweenCollections;
  v3->MaxFramesBetweenCollections = v4;
  if ( maxRootCount == -1 )
  {
    v3->MaxRootCount = 1000;
    v3->PresetMaxRootCount = 1000;
  }
  else
  {
    v3->MaxRootCount = maxRootCount;
    v3->PresetMaxRootCount = maxRootCount;
  }
}

// File Line: 330
// RVA: 0x6E11A0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateSprite(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::TimelineDef *pdef, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::InteractiveObject *parent, Scaleform::GFx::ResourceId id, bool loadedSeparately)
{
  Scaleform::GFx::ASSupport *v6; // r10
  unsigned int v7; // edx
  signed int v8; // ST28_4
  Scaleform::GFx::Sprite *v9; // rbx
  Scaleform::GFx::TimelineDef *v11; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::MovieDefImpl *v12; // [rsp+38h] [rbp-20h]
  __int64 v13; // [rsp+40h] [rbp-18h]

  v6 = this->pASSupport.pObject;
  v11 = pdef;
  v7 = **(_DWORD **)&id.Id;
  v12 = pdefImpl;
  v13 = 0i64;
  id.Id = v7;
  v8 = 3;
  v9 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::TimelineDef **, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::ResourceId *, signed int, Scaleform::GFx::TimelineDef *, Scaleform::GFx::MovieDefImpl *, _QWORD))v6->vfptr[4].__vecDelDtor)(
                                   v6,
                                   this->pMovieImpl,
                                   &v11,
                                   parent,
                                   &id,
                                   v8,
                                   v11,
                                   pdefImpl,
                                   0i64);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v9, loadedSeparately);
  return v9;
}

// File Line: 341
// RVA: 0x6E2650
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoActions(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v3; // [rsp+28h] [rbp-30h]

  v1 = this;
  v3.pActionQueue = &this->ActionQueue;
  v3.ModId = 0;
  v3.CurrentPrio = 0;
  v3.pLastEntry = 0i64;
  for ( i = Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v3);
        i;
        i = Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v3) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, v1);
  }
  if ( v3.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v3.pActionQueue, v3.pLastEntry);
}

// File Line: 355
// RVA: 0x6E26D0
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(Scaleform::GFx::AS2::MovieRoot *this, unsigned int sessionId)
{
  Scaleform::GFx::AS2::MovieRoot *v2; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator v4; // [rsp+28h] [rbp-30h]

  v2 = this;
  v4.pActionQueue = &this->ActionQueue;
  v4.ModId = 0;
  v4.CurrentPrio = 0;
  v4.pLastEntry = 0i64;
  v4.SessionId = sessionId;
  for ( i = Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4);
        i;
        i = Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, v2);
  }
  if ( v4.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
}

// File Line: 367
// RVA: 0x70FC50
void __fastcall Scaleform::GFx::AS2::MovieRoot::RegisterAuxASClasses(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rbx
  Scaleform::GFx::AS2::GlobalContext *v2; // rcx
  Scaleform::GFx::AS2::ASStringContext sc; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->pGlobalContext.pObject;
  sc.SWFVersion = 8;
  sc.pContext = v2;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<23,Scaleform::GFx::AS2::XmlCtorFunction>(
    v2,
    &sc,
    v2->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<24,Scaleform::GFx::AS2::XmlNodeCtorFunction>(
    v1->pGlobalContext.pObject,
    &sc,
    v1->pGlobalContext.pObject->pGlobal.pObject);
}

// File Line: 399
// RVA: 0x6EFCF0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(Scaleform::GFx::AS2::MovieRoot *this, int level)
{
  Scaleform::GFx::MovieImpl *v2; // rcx
  unsigned int v3; // er8
  unsigned __int64 v4; // r9
  Scaleform::GFx::MovieImpl::LevelInfo *v5; // rcx
  __int64 v6; // rax

  v2 = this->pMovieImpl;
  v3 = 0;
  v4 = v2->MovieLevels.Data.Size;
  if ( !v4 )
    return 0i64;
  v5 = v2->MovieLevels.Data.Data;
  v6 = 0i64;
  while ( v5[v6].Level != level )
  {
    v6 = ++v3;
    if ( v3 >= v4 )
      return 0i64;
  }
  return v5[v3].pSprite.pObject;
}

// File Line: 421
// RVA: 0x707BE0
int __fastcall Scaleform::GFx::AS2::MovieRoot::ParseLevelName(const char *pname, const char **ptail, bool caseSensitive)
{
  const char **v3; // rbx
  int result; // eax
  char v5; // al
  const char *v6; // rcx
  char *endptr; // [rsp+30h] [rbp+8h]
  char *v8; // [rsp+48h] [rbp+20h]

  v3 = ptail;
  if ( (unsigned __int8)(*pname - 48) <= 9u )
  {
    endptr = 0i64;
    result = strtol(pname, &endptr, 10);
    *v3 = endptr;
    return result;
  }
  if ( *pname != 95 )
    return -1;
  if ( caseSensitive )
  {
    if ( pname[1] != 108 || pname[2] != 101 || pname[3] != 118 || pname[4] != 101 || pname[5] != 108 )
      return -1;
  }
  else if ( (pname[1] - 76) & 0xDF
         || (pname[2] - 69) & 0xDF
         || (pname[3] - 86) & 0xDF
         || (pname[4] - 69) & 0xDF
         || (pname[5] - 76) & 0xDF )
  {
    return -1;
  }
  v5 = pname[6];
  v6 = pname + 6;
  if ( (unsigned __int8)(v5 - 48) > 9u )
    return -1;
  v8 = 0i64;
  result = strtol(v6, &v8, 10);
  *v3 = v8;
  return result;
}

// File Line: 475
// RVA: 0x6D0C10
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::~ActionQueueType(Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v1; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v2; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v3; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v4; // [rsp+28h] [rbp-30h]

  v1 = this;
  v4.pActionQueue = this;
  v4.ModId = 0;
  v4.CurrentPrio = 0;
  v4.pLastEntry = 0i64;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v4) )
    ;
  if ( v4.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
  v2 = v1->pFreeEntry;
  if ( v2 )
  {
    do
    {
      v3 = v2->pNextEntry;
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
      v2 = v3;
    }
    while ( v3 );
  }
}

// File Line: 488
// RVA: 0x6FD8A0
Scaleform::GFx::AS2::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this, Scaleform::GFx::ActionPriority::Priority prio)
{
  __int64 v2; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v3; // rsi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v4; // rbx
  __int64 v5; // rax
  signed __int64 v6; // ST28_8
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueEntry *v9; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry **v10; // rax

  v2 = prio;
  v3 = this;
  v4 = this->pFreeEntry;
  if ( v4 )
  {
    this->pFreeEntry = v4->pNextEntry;
    v4->pNextEntry = 0i64;
    --this->FreeEntriesCount;
  }
  else
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot::ActionQueueType *, signed __int64))this->pHeap->vfptr->Alloc)(
           this,
           120i64);
    v4 = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)v5;
    if ( v5 )
    {
      *(_QWORD *)(v5 + 16) = 0i64;
      *(_QWORD *)(v5 + 24) = 0i64;
      *(_QWORD *)(v5 + 32) = 0i64;
      *(_DWORD *)(v5 + 40) = 0;
      *(_BYTE *)(v5 + 44) = 0;
      *(_DWORD *)(v5 + 48) = 65280;
      *(_BYTE *)(v5 + 72) = 0;
      *(_QWORD *)(v5 + 56) = 0i64;
      *(_QWORD *)(v5 + 64) = 0i64;
      v6 = v5 + 88;
      *(_OWORD *)v6 = 0ui64;
      *(_QWORD *)(v6 + 16) = 0i64;
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 8) = 0;
      v7 = *(Scaleform::RefCountNTSImpl **)(v5 + 24);
      if ( v7 )
        Scaleform::RefCountNTSImpl::Release(v7);
      v4->pActionBuffer.pObject = 0i64;
      v4->SessionId = 0;
    }
    else
    {
      v4 = 0i64;
    }
    if ( !v4 )
      return 0i64;
  }
  v9 = &v3->Entries[v2];
  v10 = &v9->pInsertEntry->pNextEntry;
  if ( v10 )
  {
    v4->pNextEntry = *v10;
    v9->pInsertEntry->pNextEntry = v4;
  }
  else
  {
    v4->pNextEntry = v9->pActionRoot;
    v9->pActionRoot = v4;
  }
  v9->pInsertEntry = v4;
  if ( !v4->pNextEntry )
    v9->pLastEntry = v4;
  v4->SessionId = v3->CurrentSessionId;
  ++v3->ModId;
  return v4;
}

// File Line: 540
// RVA: 0x6D9880
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this, Scaleform::GFx::AS2::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v2; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v3; // rbx
  Scaleform::GFx::AS2::ActionBuffer *v4; // rcx
  Scaleform::RefCountNTSImpl *v5; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  bool v8; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax

  v2 = this;
  v3 = pentry;
  pentry->Type = 0;
  v4 = pentry->pActionBuffer.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  v3->pActionBuffer.pObject = 0i64;
  v5 = (Scaleform::RefCountNTSImpl *)&v3->pCharacter.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  v3->pCharacter.pObject = 0i64;
  if ( !(v3->Function.Flags & 2) )
  {
    v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->Function.Function->vfptr;
    if ( v6 )
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
  }
  v8 = (v3->Function.Flags & 1) == 0;
  v3->Function.Function = 0i64;
  if ( v8 )
  {
    v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->Function.pLocalFrame->vfptr;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  v3->Function.pLocalFrame = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v3->FunctionParams.Data,
    0i64);
  if ( v2->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  else
  {
    v3->pNextEntry = v2->pFreeEntry;
    ++v2->FreeEntriesCount;
    v2->pFreeEntry = v3;
  }
}

// File Line: 576
// RVA: 0x6D0BC0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::~ActionQueueIterator(Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v1; // rdx

  v1 = this->pLastEntry;
  if ( v1 )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, v1);
}

// File Line: 582
// RVA: 0x725080
Scaleform::GFx::AS2::MovieRoot::ActionEntry **__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v1; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *v2; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry **v3; // rdi
  __int64 v4; // rax
  __int64 v5; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v6; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v7; // rdx

  v1 = this->pActionQueue;
  v2 = this;
  if ( v1->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = v1->ModId;
  }
  v3 = &v1->Entries[this->CurrentPrio].pActionRoot->pNextEntry;
  if ( v3 )
    goto LABEL_8;
  while ( 1 )
  {
    v4 = ++this->CurrentPrio;
    if ( (signed int)v4 >= 6 )
      break;
    v3 = &v1->Entries[v4].pActionRoot->pNextEntry;
    if ( v3 )
      goto LABEL_8;
  }
  if ( v3 )
  {
LABEL_8:
    v5 = this->CurrentPrio;
    if ( v3 == (Scaleform::GFx::AS2::MovieRoot::ActionEntry **)v1->Entries[v5].pInsertEntry )
      v1->Entries[v5].pInsertEntry = *v3;
    this->pActionQueue->Entries[this->CurrentPrio].pActionRoot = *v3;
    *v3 = 0i64;
  }
  v6 = this->pActionQueue;
  if ( !v6->Entries[this->CurrentPrio].pActionRoot )
  {
    v6->Entries[this->CurrentPrio].pInsertEntry = 0i64;
    this->pActionQueue->Entries[this->CurrentPrio].pLastEntry = 0i64;
  }
  v7 = this->pLastEntry;
  if ( v7 )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, v7);
  v2->pLastEntry = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)v3;
  return v3;
}

// File Line: 621
// RVA: 0x725160
Scaleform::GFx::AS2::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v1; // r8
  Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator *v2; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v3; // rbx
  __int64 v4; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v5; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v6; // rax
  signed __int64 v7; // r8
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v8; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v9; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *result; // rax

  v1 = this->pActionQueue;
  v2 = this;
  if ( v1->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = v1->ModId;
  }
  v3 = 0i64;
  if ( this->CurrentPrio < 6 )
  {
    while ( 1 )
    {
      v4 = v2->CurrentPrio;
      v5 = 0i64;
      v3 = v1->Entries[v4].pActionRoot;
      if ( v3 )
        break;
LABEL_7:
      v2->CurrentPrio = v4 + 1;
      if ( (signed int)v4 + 1 >= 6 )
        goto LABEL_19;
    }
    while ( v3->SessionId != v2->SessionId )
    {
      v5 = v3;
      v3 = v3->pNextEntry;
      if ( !v3 )
        goto LABEL_7;
    }
    if ( v5 )
      v5->pNextEntry = v3->pNextEntry;
    else
      v1->Entries[v2->CurrentPrio].pActionRoot = v3->pNextEntry;
    if ( !v3->pNextEntry )
      v2->pActionQueue->Entries[v2->CurrentPrio].pLastEntry = v5;
    v6 = v2->pActionQueue;
    v7 = (signed __int64)&v6->Entries[v2->CurrentPrio];
    if ( v3 == v6->Entries[v2->CurrentPrio].pInsertEntry )
    {
      v8 = v3->pNextEntry;
      if ( !v3->pNextEntry )
        v8 = v5;
      *(_QWORD *)(v7 + 8) = v8;
    }
    v3->pNextEntry = 0i64;
  }
LABEL_19:
  v9 = v2->pLastEntry;
  if ( v9 )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v2->pActionQueue, v9);
  result = v3;
  v2->pLastEntry = v3;
  return result;
}

// File Line: 673
// RVA: 0x6E7B10
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(Scaleform::GFx::AS2::MovieRoot::ActionEntry *this, Scaleform::GFx::AS2::MovieRoot *proot)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax

  v2 = this;
  v3 = this->pCharacter.pObject;
  if ( v3 && !((LOBYTE(v3->Flags) >> 4) & 1) )
  {
    switch ( v2->Type )
    {
      case 1:
        v7 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                         + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)();
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ActionBuffer *))(*(_QWORD *)v7 + 288i64))(
          v7,
          v2->pActionBuffer.pObject);
        break;
      case 2:
        v6 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                         + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)();
        (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v6 + 296i64))(v6, &v2->mEventId);
        break;
      case 3:
        v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                         + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)();
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::FunctionRef *, Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v5 + 304i64))(
          v5,
          &v2->Function,
          &v2->FunctionParams);
        break;
      case 4:
        v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                         + 4 * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)();
        (*(void (__fastcall **)(__int64, void (__fastcall *)(Scaleform::GFx::AS2::FnCall *), Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v4 + 312i64))(
          v4,
          v2->CFunction,
          &v2->FunctionParams);
        break;
    }
  }
}

// File Line: 705
// RVA: 0x6E0060
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateMovieDefRootNode(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::MemoryHeap *pheap, Scaleform::GFx::MovieDefImpl *pdefImpl, bool importFlag)
{
  bool v4; // bl
  Scaleform::GFx::MovieDefImpl *v5; // rdi
  Scaleform::GFx::MovieDefRootNode *result; // rax

  v4 = importFlag;
  v5 = pdefImpl;
  result = (Scaleform::GFx::MovieDefRootNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pheap->vfptr->Alloc)(
                                                 pheap,
                                                 64i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable';
  result->SpriteRefCount = 1;
  result->pDefImpl = v5;
  result->ImportFlag = v4;
  result->pFontManager.pObject = 0i64;
  return result;
}

// File Line: 710
// RVA: 0x6DDB30
void __fastcall Scaleform::GFx::AS2::MovieRoot::ClearDisplayList(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rbp
  unsigned __int64 v2; // rsi
  signed __int64 v3; // rdi
  __int64 v4; // rbx
  signed __int64 v5; // rbx
  signed __int64 v6; // rdi

  v1 = this;
  v2 = this->pMovieImpl->MovieLevels.Data.Size;
  if ( v2 )
  {
    v3 = v2;
    do
    {
      v4 = *((_QWORD *)&v1->pMovieImpl->MovieLevels.Data.Data[v3] - 1);
      Scaleform::GFx::DisplayList::Clear(
        (Scaleform::GFx::DisplayList *)(v4 + 216),
        (Scaleform::GFx::DisplayObjectBase *)v4);
      _((AMD_HD3D *)v4);
      --v3;
      --v2;
    }
    while ( v2 );
  }
  v5 = v1->pMovieImpl->MovieLevels.Data.Size;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      (*(void (**)(void))(**((_QWORD **)&v1->pMovieImpl->MovieLevels.Data.Data[v6] - 1) + 480i64))();
      --v6;
      --v5;
    }
    while ( v5 );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy> *)&v1->pMovieImpl->MovieLevels.Data.Data,
    &v1->pMovieImpl->MovieLevels,
    0i64);
}

// File Line: 727
// RVA: 0x6D8E60
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *v2; // r15
  Scaleform::GFx::AS2::MovieRoot *v3; // r14
  Scaleform::GFx::LoadQueueEntry::LoadType v4; // eax
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v5; // rax
  Scaleform::GFx::LoadQueueEntryMT *v6; // rax
  Scaleform::GFx::LoadQueueEntryMT *v7; // rdi
  __int64 v8; // rcx
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *v9; // rax
  Scaleform::GFx::LoadQueueEntryMT *v10; // rax
  Scaleform::GFx::LoadQueueEntry *v11; // rbx
  Scaleform::GFx::AS2::Object *v12; // rbp
  Scaleform::GFx::LoadQueueEntryMT *i; // rbx
  Scaleform::GFx::LoadQueueEntry *v14; // rsi
  char v15; // dl
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *v16; // rax
  Scaleform::GFx::LoadQueueEntryMT *v17; // rax
  Scaleform::GFx::LoadQueueEntry *v18; // r9
  Scaleform::GFx::LoadQueueEntryMT *v19; // rdx
  Scaleform::GFx::LoadQueueEntry *v20; // rcx
  Scaleform::GFx::LoadQueueEntry *v21; // rax
  Scaleform::GFx::LoadQueueEntry *v22; // r8
  bool v23; // zf
  int v24; // eax

  v2 = pentry;
  v3 = this;
  v4 = pentry->Type;
  if ( v4 & 4 )
  {
    v5 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                        this,
                                                        56i64);
    if ( v5 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(v5, v2, v3->pMovieImpl);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    goto LABEL_33;
  }
  if ( !(v4 & 8) )
  {
    if ( v4 & 0x10 )
      goto LABEL_35;
    v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                                     this,
                                                                     88i64);
    if ( v16 )
    {
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(v16, v2, v3->pMovieImpl);
      v7 = v17;
    }
    else
    {
      v7 = 0i64;
    }
    if ( !v7 )
      goto LABEL_35;
    v18 = v7->pQueueEntry;
    v19 = v3->pMovieImpl->pLoadQueueMTHead;
    if ( !v19 )
      goto LABEL_33;
    while ( 1 )
    {
      v20 = v19->pQueueEntry;
      v21 = v18[1].pNext;
      if ( v21 )
      {
        v22 = v20[1].pNext;
        if ( v22 )
        {
          v23 = v22->URL.HeapTypeBits == v21->URL.HeapTypeBits;
          goto LABEL_30;
        }
      }
      else
      {
        v24 = (int)v20[1].vfptr;
        if ( v24 != -1 )
        {
          v23 = v24 == LODWORD(v18[1].vfptr);
LABEL_30:
          if ( v23 )
            v20->Canceled = 1;
          goto LABEL_32;
        }
      }
LABEL_32:
      v19 = v19->pNext;
      if ( !v19 )
        goto LABEL_33;
    }
  }
  if ( !Scaleform::String::GetLength(&pentry->URL) )
    goto LABEL_35;
  v9 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *)((__int64 (__fastcall *)(__int64, signed __int64))v3->pMovieImpl->pHeap->vfptr->Alloc)(
                                                                v8,
                                                                64i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(v9, v2, v3);
    v7 = v10;
  }
  else
  {
    v7 = 0i64;
  }
  v11 = v7->pQueueEntry;
  if ( Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v11[3], 0i64) )
  {
    v12 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v11[3], 0i64);
    for ( i = v3->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
    {
      v14 = i->pQueueEntry;
      v15 = (char)v14[3].vfptr;
      if ( v15 && v15 != 10 && v12 == Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v14[3], 0i64) )
        v14->Canceled = 1;
    }
  }
LABEL_33:
  if ( v7 )
  {
    Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(v3->pMovieImpl, v7);
    return;
  }
LABEL_35:
  v2->vfptr->__vecDelDtor(v2, 1u);
}

// File Line: 811
// RVA: 0x6D8BB0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, const char *ptarget, const char *purl, Scaleform::GFx::AS2::Environment *env, Scaleform::GFx::LoadQueueEntry::LoadMethod method, Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  Scaleform::GFx::AS2::Environment *v6; // rsi
  const char *v7; // r12
  const char *v8; // r14
  Scaleform::GFx::AS2::MovieRoot *v9; // r15
  __int64 v10; // rdi
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  char v13; // bl
  Scaleform::GFx::InteractiveObject *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::DisplayObject *v16; // rsi
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::DisplayObject *v20; // rcx
  int v21; // er14
  char *v22; // r14
  Scaleform::GFx::CharacterHandle *v23; // rax
  __int64 v24; // rax
  Scaleform::String::DataDesc *v25; // rdx
  unsigned int v26; // ecx
  Scaleform::GFx::MovieImpl *v27; // r8
  unsigned __int64 v28; // rdx
  __int64 v29; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v30; // r8
  Scaleform::GFx::DisplayObjectBase *v31; // rcx
  unsigned int v32; // eax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v33; // rsi
  __int64 v34; // rax
  char *ptail; // [rsp+38h] [rbp-38h]
  Scaleform::String v36; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::ASString v37; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-20h]
  __int64 v39; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v40; // [rsp+60h] [rbp-10h]
  Scaleform::String url; // [rsp+B8h] [rbp+48h]

  v39 = -2i64;
  v6 = env;
  v7 = purl;
  v8 = ptarget;
  v9 = this;
  v10 = 0i64;
  v11 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)this->BuiltinsMgr.Builtins;
  if ( env )
  {
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
            v11,
            &result,
            ptarget);
    v13 = 1;
    v14 = Scaleform::GFx::AS2::Environment::FindTarget(v6, v12, 0);
  }
  else
  {
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
            v11,
            &v37,
            ptarget);
    v13 = 2;
    v14 = (Scaleform::GFx::InteractiveObject *)v9->vfptr[8].__vecDelDtor(
                                                 (Scaleform::RefCountImplCore *)&v9->vfptr,
                                                 (unsigned int)v15);
  }
  v16 = (Scaleform::GFx::DisplayObject *)&v14->vfptr;
  if ( v13 & 2 )
  {
    v13 &= 0xFDu;
    v17 = v37.pNode;
    v18 = v37.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  if ( v13 & 1 )
  {
    v13 &= 0xFEu;
    v19 = result.pNode;
    v18 = result.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( v16 )
  {
    v20 = 0i64;
    if ( (v16->Flags >> 10) & 1 )
      v20 = v16;
    if ( !v20
      || (v21 = (*(__int64 (**)(void))(*(_QWORD *)(&v20->Id.Id + (unsigned __int8)v20->AvmObjOffset) + 240i64))(),
          v21 == -1) )
    {
      v36.pData = (Scaleform::String::DataDesc *)v9->pMovieImpl->pHeap;
      v22 = (char *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, signed __int64, _QWORD))(v36.pData->Size + 80))(
                      v20,
                      160i64,
                      0i64);
      ptail = v22;
      if ( v22 )
      {
        Scaleform::String::String(&url, v7);
        v13 |= 4u;
        v23 = v16->pNameHandle.pObject;
        if ( !v23 )
          v23 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v22,
          v23,
          &url,
          method,
          0,
          0);
        v10 = v24;
      }
      if ( !(v13 & 4) )
        goto LABEL_36;
      v25 = url.pData;
LABEL_34:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v25 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_36:
      if ( v10 )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(
          (Scaleform::GFx::AS2::Value *)(v10 + 56),
          (Scaleform::GFx::AS2::Object *)&pmovieClipLoader->vfptr);
        Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(v9, (Scaleform::GFx::LoadQueueEntry *)v10);
      }
      return;
    }
LABEL_30:
    url.pData = (Scaleform::String::DataDesc *)v9->pMovieImpl->pHeap;
    v33 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, signed __int64, _QWORD))(url.pData->Size + 80))(
                                                         v20,
                                                         160i64,
                                                         0i64);
    v40 = v33;
    if ( v33 )
    {
      Scaleform::String::String(&v36, v7);
      v13 |= 8u;
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v33, v21, &v36, method, 0, 0);
      v10 = v34;
    }
    if ( !(v13 & 8) )
      goto LABEL_36;
    v25 = v36.pData;
    goto LABEL_34;
  }
  ptail = &customWorldMapCaption;
  v26 = 0;
  v27 = v9->pMovieImpl;
  v28 = v27->MovieLevels.Data.Size;
  if ( v28 )
  {
    v29 = 0i64;
    v30 = v27->MovieLevels.Data.Data;
    while ( v30[v29].Level )
    {
      v29 = ++v26;
      if ( v26 >= v28 )
        goto LABEL_27;
    }
    v31 = (Scaleform::GFx::DisplayObjectBase *)&v30[v26].pSprite.pObject->vfptr;
  }
  else
  {
LABEL_27:
    v31 = 0i64;
  }
  v32 = Scaleform::GFx::DisplayObjectBase::GetVersion(v31);
  v21 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v8, (const char **)&ptail, v32 > 6);
  if ( !*ptail && v21 != -1 )
    goto LABEL_30;
}

// File Line: 866
// RVA: 0x6D9D20
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, const char *ptarget, const char *purl, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // er13
  const char *v5; // r12
  const char *v6; // rbp
  Scaleform::GFx::AS2::MovieRoot *v7; // r15
  Scaleform::GFx::LoadQueueEntry *v8; // rdi
  char v9; // si
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::DisplayObject *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::DisplayObject *v14; // rcx
  int v15; // ebp
  Scaleform::String::DataDesc *v16; // rbp
  Scaleform::GFx::CharacterHandle *v17; // rax
  Scaleform::GFx::LoadQueueEntry *v18; // rax
  Scaleform::String::DataDesc *v19; // rdx
  unsigned int v20; // ecx
  Scaleform::GFx::MovieImpl *v21; // r8
  unsigned __int64 v22; // rdx
  __int64 v23; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // r8
  Scaleform::GFx::DisplayObjectBase *v25; // rcx
  unsigned int v26; // eax
  __int64 v27; // r14
  Scaleform::GFx::CharacterHandle *v28; // rbx
  Scaleform::GFx::TaskManager *v29; // rbx
  char *ptail; // [rsp+38h] [rbp-60h]
  Scaleform::String src; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::ASStringNode *v32; // [rsp+48h] [rbp-50h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+50h] [rbp-48h]
  __int64 v34; // [rsp+58h] [rbp-40h]
  __int64 v35; // [rsp+60h] [rbp-38h]
  Scaleform::String url; // [rsp+A0h] [rbp+8h]

  v34 = -2i64;
  v4 = method;
  v5 = purl;
  v6 = ptarget;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)this->BuiltinsMgr.Builtins,
          (Scaleform::GFx::ASString *)&v32,
          ptarget);
  v11 = (Scaleform::GFx::DisplayObject *)v7->vfptr[8].__vecDelDtor(
                                           (Scaleform::RefCountImplCore *)&v7->vfptr,
                                           (unsigned int)v10);
  v12 = v32;
  v13 = v32->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v11 )
  {
    v14 = 0i64;
    if ( (v11->Flags >> 10) & 1 )
      v14 = v11;
    if ( !v14
      || (v15 = (*(__int64 (**)(void))(*(_QWORD *)(&v14->Id.Id + (unsigned __int8)v14->AvmObjOffset) + 240i64))(),
          v15 == -1) )
    {
      result.pObject = (Scaleform::GFx::TaskManager *)v7->pMovieImpl->pHeap;
      v16 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                             v14,
                                             160i64,
                                             0i64);
      src.pData = v16;
      if ( v16 )
      {
        Scaleform::String::String(&url, v5);
        v9 = 1;
        v17 = v11->pNameHandle.pObject;
        if ( !v17 )
          v17 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v11);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v16,
          v17,
          &url,
          v4,
          1,
          0);
        v8 = v18;
      }
      if ( !(v9 & 1) )
        goto LABEL_32;
      v19 = url.pData;
LABEL_30:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v19 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_32:
      if ( v8 )
      {
        v29 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject;
        if ( result.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
        if ( v29 )
          Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(v7, v8);
        else
          Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, v8);
      }
      return;
    }
LABEL_23:
    url.pData = (Scaleform::String::DataDesc *)v7->pMovieImpl->pHeap;
    v27 = (*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, signed __int64, _QWORD))(url.pData->Size + 80))(
            v14,
            160i64,
            0i64);
    result.pObject = (Scaleform::GFx::TaskManager *)v27;
    if ( v27 )
    {
      Scaleform::String::String(&src, v5);
      v9 = 2;
      *(_QWORD *)v27 = &Scaleform::GFx::LoadQueueEntry::`vftable';
      Scaleform::String::String((Scaleform::String *)(v27 + 24));
      *(_DWORD *)(v27 + 16) = 4;
      *(_DWORD *)(v27 + 20) = v4;
      *(_QWORD *)(v27 + 8) = 0i64;
      Scaleform::String::operator=((Scaleform::String *)(v27 + 24), &src);
      *(_DWORD *)(v27 + 32) = -1;
      *(_WORD *)(v27 + 36) = 0;
      *(_QWORD *)v27 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
      *(_QWORD *)(v27 + 48) = 0i64;
      *(_BYTE *)(v27 + 56) = 0;
      *(_BYTE *)(v27 + 88) = 0;
      v35 = v27 + 120;
      *(_BYTE *)(v27 + 120) = 0;
      *(_QWORD *)(v27 + 152) = 0i64;
      v28 = *(Scaleform::GFx::CharacterHandle **)(v27 + 48);
      if ( v28 )
      {
        if ( --v28->RefCount <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle(v28);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v28);
        }
      }
      *(_QWORD *)(v27 + 48) = 0i64;
      *(_DWORD *)(v27 + 40) = v15;
      *(_DWORD *)(v27 + 16) = 6;
      v8 = (Scaleform::GFx::LoadQueueEntry *)v27;
    }
    if ( !(v9 & 2) )
      goto LABEL_32;
    v19 = src.pData;
    goto LABEL_30;
  }
  ptail = &customWorldMapCaption;
  v20 = 0;
  v21 = v7->pMovieImpl;
  v22 = v21->MovieLevels.Data.Size;
  if ( v22 )
  {
    v23 = 0i64;
    v24 = v21->MovieLevels.Data.Data;
    while ( v24[v23].Level )
    {
      v23 = ++v20;
      if ( v20 >= v22 )
        goto LABEL_20;
    }
    v25 = (Scaleform::GFx::DisplayObjectBase *)&v24[v20].pSprite.pObject->vfptr;
  }
  else
  {
LABEL_20:
    v25 = 0i64;
  }
  v26 = Scaleform::GFx::DisplayObjectBase::GetVersion(v25);
  v15 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v6, (const char **)&ptail, v26 > 6);
  if ( !*ptail && v15 != -1 )
    goto LABEL_23;
}

// File Line: 924
// RVA: 0x6D89E0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *ptargetChar, const char *purl, Scaleform::GFx::LoadQueueEntry::LoadMethod method, Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v5; // er15
  const char *v6; // rbp
  Scaleform::GFx::InteractiveObject *v7; // rdi
  Scaleform::GFx::AS2::MovieRoot *v8; // r14
  char v9; // bl
  __int16 v10; // ax
  Scaleform::GFx::InteractiveObject *v11; // rdx
  int v12; // esi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rdi
  Scaleform::String::DataDesc *v16; // rdx
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v17; // rsi
  Scaleform::GFx::CharacterHandle *v18; // rax
  __int64 v19; // rax
  Scaleform::String v20; // [rsp+38h] [rbp-30h]
  __int64 v21; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v22; // [rsp+48h] [rbp-20h]
  Scaleform::String url; // [rsp+78h] [rbp+10h]

  if ( ptargetChar )
  {
    v21 = -2i64;
    v5 = method;
    v6 = purl;
    v7 = ptargetChar;
    v8 = this;
    v9 = 0;
    v10 = ptargetChar->Flags >> 10;
    v11 = 0i64;
    if ( v10 & 1 )
      v11 = v7;
    if ( v11
      && (v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                            + 4
                                                                            * ((unsigned __int8)v11->AvmObjOffset + 10i64)))[30].__vecDelDtor)(),
          v12 != -1) )
    {
      v20.pData = (Scaleform::String::DataDesc *)v8->pMovieImpl->pHeap;
      v13 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))(v20.pData->Size + 80))(
                                                           this,
                                                           160i64,
                                                           0i64);
      v22 = v13;
      if ( v13 )
      {
        Scaleform::String::String(&url, v6);
        v9 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v13, v12, &url, v5, 0, 0);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      if ( !(v9 & 2) )
        goto LABEL_20;
      v16 = url.pData;
    }
    else
    {
      url.pData = (Scaleform::String::DataDesc *)v8->pMovieImpl->pHeap;
      v17 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))(url.pData->Size + 80))(
                                                           this,
                                                           160i64,
                                                           0i64);
      v22 = v17;
      if ( v17 )
      {
        Scaleform::String::String(&v20, v6);
        v9 = 1;
        v18 = v7->pNameHandle.pObject;
        if ( !v18 )
          v18 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v7->vfptr);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v17, v18, &v20, v5, 0, 0);
        v15 = v19;
      }
      else
      {
        v15 = 0i64;
      }
      if ( !(v9 & 1) )
        goto LABEL_20;
      v16 = v20.pData;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v16 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_20:
    if ( v15 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(
        (Scaleform::GFx::AS2::Value *)(v15 + 56),
        (Scaleform::GFx::AS2::Object *)&pmovieClipLoader->vfptr);
      Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(v8, (Scaleform::GFx::LoadQueueEntry *)v15);
    }
  }
}

// File Line: 961
// RVA: 0x6D90F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *v2; // rdi
  Scaleform::GFx::AS2::MovieRoot *v3; // rsi
  Scaleform::GFx::TaskManager *v4; // rbx
  bool v5; // bp
  Scaleform::GFx::TaskManager *v6; // rbp
  Scaleform::GFx::MovieImpl *v7; // rdx
  Scaleform::GFx::StateBag *v8; // rcx
  Scaleform::GFx::MovieDefImpl *v9; // rdx
  Scaleform::GFx::LoaderImpl *v10; // rbx
  Scaleform::GFx::StateBag *v11; // rax
  Scaleform::GFx::TaskManager *v12; // rax
  bool v13; // bp
  bool sync; // [rsp+58h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+60h] [rbp+18h]

  if ( pentry )
  {
    v2 = pentry;
    v3 = this;
    v4 = 0i64;
    v5 = Scaleform::GFx::LoaderImpl::IsProtocolImage(&pentry->URL, 0i64, &sync);
    if ( v5 && sync )
    {
      v6 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            144ui64,
                                            0i64);
      result.pObject = v6;
      if ( v6 )
      {
        v7 = v3->pMovieImpl;
        v8 = (Scaleform::GFx::StateBag *)&v7->vfptr;
        v9 = v7->pMainMovieDef.pObject;
        v10 = v9->pLoaderImpl.pObject;
        v11 = (Scaleform::GFx::StateBag *)((__int64 (__cdecl *)(Scaleform::GFx::StateBag *, Scaleform::GFx::MovieDefImpl *))v8->vfptr->GetStateBagImpl)(
                                            v8,
                                            v9);
        Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, v10, v11, 0i64);
        v4 = v12;
      }
      result.pObject = v4;
      ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::TaskManager *))v3->vfptr[35].__vecDelDtor)(
        v3,
        v2,
        v4);
      v2->vfptr->__vecDelDtor(v2, 1u);
      if ( v4 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
    }
    else
    {
      v13 = 0;
      if ( Scaleform::String::GetLength(&v2->URL) )
      {
        if ( !v5 )
        {
          LOBYTE(v4) = 1;
          if ( Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v3->pMovieImpl->vfptr, &result)->pObject )
            v13 = 1;
        }
      }
      if ( (unsigned __int8)v4 & 1 && result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( v13 )
        Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(v3, v2);
      else
        Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v3->pMovieImpl, v2);
    }
  }
}

// File Line: 991
// RVA: 0x6D9970
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *ptargetChar, const char *purl, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // er15
  const char *v5; // rbp
  Scaleform::GFx::InteractiveObject *v6; // rdi
  Scaleform::GFx::AS2::MovieRoot *v7; // rsi
  char v8; // bl
  __int16 v9; // ax
  Scaleform::GFx::InteractiveObject *v10; // rdx
  int v11; // er14
  Scaleform::String::DataDesc *v12; // rdi
  Scaleform::GFx::LoadQueueEntry *v13; // rax
  Scaleform::GFx::LoadQueueEntry *v14; // rdi
  Scaleform::String::DataDesc *v15; // rdx
  Scaleform::GFx::TaskManager *v16; // r14
  Scaleform::GFx::CharacterHandle *v17; // rax
  Scaleform::GFx::LoadQueueEntry *v18; // rax
  Scaleform::GFx::TaskManager *v19; // rbx
  Scaleform::String v20; // [rsp+38h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+40h] [rbp-28h]
  __int64 v22; // [rsp+48h] [rbp-20h]
  Scaleform::String url; // [rsp+78h] [rbp+10h]

  if ( !ptargetChar )
    return;
  v22 = -2i64;
  v4 = method;
  v5 = purl;
  v6 = ptargetChar;
  v7 = this;
  v8 = 0;
  v9 = ptargetChar->Flags >> 10;
  v10 = 0i64;
  if ( v9 & 1 )
    v10 = v6;
  if ( !v10
    || (v11 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v10->vfptr
                                                                          + 4
                                                                          * ((unsigned __int8)v10->AvmObjOffset + 10i64)))[30].__vecDelDtor)(),
        v11 == -1) )
  {
    url.pData = (Scaleform::String::DataDesc *)v7->pMovieImpl->pHeap;
    v16 = (Scaleform::GFx::TaskManager *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))(url.pData->Size + 80))(
                                           this,
                                           160i64,
                                           0i64);
    result.pObject = v16;
    if ( v16 )
    {
      Scaleform::String::String(&v20, v5);
      v8 = 1;
      v17 = v6->pNameHandle.pObject;
      if ( !v17 )
        v17 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v6->vfptr);
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v16,
        v17,
        &v20,
        v4,
        1,
        0);
      v14 = v18;
    }
    else
    {
      v14 = 0i64;
    }
    if ( !(v8 & 1) )
      goto LABEL_20;
    v15 = v20.pData;
    goto LABEL_18;
  }
  result.pObject = (Scaleform::GFx::TaskManager *)v7->pMovieImpl->pHeap;
  v12 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                         this,
                                         160i64,
                                         0i64);
  v20.pData = v12;
  if ( v12 )
  {
    Scaleform::String::String(&url, v5);
    v8 = 2;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
      (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v12,
      v11,
      &url,
      v4,
      1,
      0);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  if ( v8 & 2 )
  {
    v15 = url.pData;
LABEL_18:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v15 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
LABEL_20:
  if ( v14 )
  {
    v19 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v19 )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(v7, v14);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, v14);
  }
}ueueEntryMT(v7, v14);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, v14);
  }


// File Line: 1036
// RVA: 0x6D9B60
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::AS2::LoadVarsObject *ploadVars, const char *purl, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry::LoadMethod v4; // er15
  const char *v5; // rdi
  Scaleform::GFx::AS2::LoadVarsObject *v6; // r12
  Scaleform::GFx::AS2::MovieRoot *v7; // r14
  char v8; // bp
  __int64 v9; // rsi
  Scaleform::GFx::CharacterHandle *v10; // rdi
  Scaleform::GFx::TaskManager *v11; // rbx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+28h] [rbp-50h]
  __int64 v13; // [rsp+30h] [rbp-48h]
  __int64 v14; // [rsp+38h] [rbp-40h]
  __int64 v15; // [rsp+40h] [rbp-38h]
  Scaleform::String src; // [rsp+80h] [rbp+8h]

  v13 = -2i64;
  v4 = method;
  v5 = purl;
  v6 = ploadVars;
  v7 = this;
  v8 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
         this,
         160i64,
         0i64);
  v14 = v9;
  if ( v9 )
  {
    Scaleform::String::String(&src, v5);
    v8 = 1;
    *(_QWORD *)v9 = &Scaleform::GFx::LoadQueueEntry::`vftable';
    Scaleform::String::String((Scaleform::String *)(v9 + 24));
    *(_DWORD *)(v9 + 16) = 4;
    *(_DWORD *)(v9 + 20) = v4;
    *(_QWORD *)(v9 + 8) = 0i64;
    Scaleform::String::operator=((Scaleform::String *)(v9 + 24), &src);
    *(_DWORD *)(v9 + 32) = -1;
    *(_WORD *)(v9 + 36) = 0;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_BYTE *)(v9 + 56) = 0;
    *(_BYTE *)(v9 + 88) = 0;
    v15 = v9 + 120;
    *(_BYTE *)(v9 + 120) = 0;
    *(_QWORD *)(v9 + 152) = 0i64;
    v10 = *(Scaleform::GFx::CharacterHandle **)(v9 + 48);
    if ( v10 )
    {
      if ( --v10->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v10);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
      }
    }
    *(_QWORD *)(v9 + 48) = 0i64;
    *(_DWORD *)(v9 + 40) = -1;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v8 & 1 && !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v9 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(
      (Scaleform::GFx::AS2::Value *)(v9 + 88),
      (Scaleform::GFx::AS2::Object *)&v6->vfptr);
    v11 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v11 )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(v7, (Scaleform::GFx::LoadQueueEntry *)v9);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v7->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v9);
  }
}

// File Line: 1079
// RVA: 0x6DA050
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::AS2::Object *pxmlobj, Scaleform::GFx::AS2::XMLFileLoader *pxmlLoader, const char *purl, Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  const char *v5; // rdi
  Scaleform::GFx::Resource *v6; // r15
  Scaleform::GFx::AS2::Object *v7; // r12
  Scaleform::GFx::AS2::MovieRoot *v8; // r14
  char v9; // bp
  __int64 v10; // rsi
  Scaleform::GFx::CharacterHandle *v11; // rdi
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::TaskManager *v13; // rbx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+28h] [rbp-50h]
  __int64 v15; // [rsp+30h] [rbp-48h]
  __int64 v16; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+40h] [rbp-38h]
  Scaleform::String src; // [rsp+80h] [rbp+8h]

  v15 = -2i64;
  v5 = purl;
  v6 = (Scaleform::GFx::Resource *)pxmlLoader;
  v7 = pxmlobj;
  v8 = this;
  v9 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v10 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, signed __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
          this,
          160i64,
          0i64);
  v16 = v10;
  if ( v10 )
  {
    Scaleform::String::String(&src, v5);
    v9 = 1;
    *(_QWORD *)v10 = &Scaleform::GFx::LoadQueueEntry::`vftable';
    Scaleform::String::String((Scaleform::String *)(v10 + 24));
    *(_DWORD *)(v10 + 16) = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
    *(_DWORD *)(v10 + 20) = method;
    *(_QWORD *)(v10 + 8) = 0i64;
    Scaleform::String::operator=((Scaleform::String *)(v10 + 24), &src);
    *(_DWORD *)(v10 + 32) = -1;
    *(_WORD *)(v10 + 36) = 0;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable';
    *(_QWORD *)(v10 + 48) = 0i64;
    *(_BYTE *)(v10 + 56) = 0;
    *(_BYTE *)(v10 + 88) = 0;
    v17 = v10 + 120;
    *(_BYTE *)(v10 + 120) = 0;
    *(_QWORD *)(v10 + 152) = 0i64;
    v11 = *(Scaleform::GFx::CharacterHandle **)(v10 + 48);
    if ( v11 )
    {
      if ( --v11->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v11);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
    }
    *(_QWORD *)(v10 + 48) = 0i64;
    *(_DWORD *)(v10 + 40) = -1;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v9 & 1 && !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v10 )
  {
    *(_DWORD *)(v10 + 16) = 8;
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v10 + 120), v7);
    if ( v6 )
      Scaleform::Render::RenderBuffer::AddRef(v6);
    v12 = *(Scaleform::Render::RenderBuffer **)(v10 + 152);
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    *(_QWORD *)(v10 + 152) = v6;
    v13 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v8->pMovieImpl->vfptr, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v13 )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(v8, (Scaleform::GFx::LoadQueueEntry *)v10);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(v8->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v10);
  }
}

// File Line: 1096
// RVA: 0x70A330
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadQueueEntry(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadQueueEntry::LoadType v3; // eax

  v3 = pentry->Type;
  JUMPOUT(v3 & 4, 0, Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars);
  JUMPOUT(v3 & 8, 0, Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML);
  Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(this, pentry, pls);
}

// File Line: 1118
// RVA: 0x709750
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *p_entry, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v3; // rdi
  Scaleform::GFx::LoadQueueEntry *v4; // r13
  Scaleform::GFx::AS2::MovieRoot *v5; // r14
  unsigned int v6; // er9
  Scaleform::GFx::MovieImpl *v7; // r11
  unsigned __int64 v8; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // rcx
  const char *v11; // rax
  Scaleform::GFx::DisplayObject *v12; // rbx
  Scaleform::GFx::MovieDefImpl *v13; // rsi
  Scaleform::GFx::Sprite *v14; // rdi
  __int64 v15; // r12
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  __int64 v18; // rax
  signed int v19; // er14
  int v20; // er9
  unsigned int v21; // edx
  Scaleform::GFx::MovieImpl *v22; // r10
  unsigned __int64 v23; // rcx
  __int64 v24; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v25; // r8
  unsigned int v26; // edx
  __int64 v27; // rax
  unsigned int v28; // edx
  __int64 v29; // rax
  __int64 v30; // rax
  Scaleform::GFx::InteractiveObject *v31; // rcx
  __int64 v32; // rax
  Scaleform::String *v33; // rax
  Scaleform::GFx::ImageCreator *v34; // r12
  __int64 v35; // rdx
  Scaleform::GFx::ImageFileHandlerRegistry *v36; // rbx
  Scaleform::GFx::FileOpener *v37; // rdi
  Scaleform::GFx::LogState *v38; // rax
  Scaleform::Log *v39; // rax
  __int64 v40; // rcx
  Scaleform::Render::Image *v41; // rdi
  Scaleform::GFx::ImageResource *v42; // rax
  Scaleform::GFx::ImageResource *v43; // rax
  Scaleform::GFx::ImageResource *v44; // rbx
  unsigned int v45; // edi
  Scaleform::GFx::LoadStates *v46; // r12
  Scaleform::GFx::MovieDefImpl *v47; // rbx
  Scaleform::GFx::MovieDefImpl *v48; // rbx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v49; // rbx
  char *v50; // rcx
  __int64 v51; // rax
  Scaleform::GFx::AS2::Environment *v52; // rax
  Scaleform::GFx::AS2::Environment *v53; // rdi
  Scaleform::GFx::AS2::Object *v54; // rax
  Scaleform::GFx::AS2::MovieRoot *v55; // r12
  Scaleform::GFx::ASSupport *v56; // rcx
  Scaleform::GFx::LoadQueueEntryMT *v57; // rdx
  Scaleform::GFx::LoadQueueEntry *v58; // rcx
  int v59; // er8
  int v60; // eax
  bool v61; // zf
  Scaleform::GFx::LoadQueueEntry *v62; // r8
  Scaleform::GFx::LoadQueueEntry *v63; // rax
  int v64; // edx
  Scaleform::GFx::MovieDefImpl *v65; // rax
  Scaleform::GFx::ASSupport *v66; // rcx
  __int64 v67; // r14
  Scaleform::GFx::ASString *v68; // rax
  Scaleform::GFx::ASStringNode *v69; // rcx
  __int64 v70; // rax
  signed __int64 v71; // rcx
  unsigned int v72; // ecx
  Scaleform::GFx::MovieImpl *v73; // r8
  unsigned __int64 v74; // rdx
  __int64 v75; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v76; // r8
  unsigned int v77; // ecx
  Scaleform::GFx::MovieImpl *v78; // r8
  unsigned __int64 v79; // rdx
  __int64 v80; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v81; // r8
  Scaleform::GFx::InteractiveObject *v82; // rcx
  signed __int64 v83; // rcx
  Scaleform::GFx::AS2::Environment *v84; // rax
  Scaleform::GFx::AS2::RefCountCollector<323> *v85; // r12
  Scaleform::GFx::AS2::Object *v86; // rax
  Scaleform::GFx::AS2::Object *v87; // r14
  Scaleform::GFx::AS2::MovieRoot *v88; // r13
  unsigned __int64 v89; // rax
  const char *v90; // r9
  Scaleform::GFx::LoadStates *plsa; // [rsp+20h] [rbp-E0h]
  __int64 v92; // [rsp+28h] [rbp-D8h]
  Scaleform::String url; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::MovieDefImpl *v94; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::Sprite *v95; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v96; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::DisplayObject *v97; // [rsp+50h] [rbp-B0h]
  Scaleform::String ppath; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::InteractiveObject *v99; // [rsp+60h] [rbp-A0h]
  Scaleform::String src; // [rsp+68h] [rbp-98h]
  int v101; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ResourceId rid; // [rsp+74h] [rbp-8Ch]
  int v103; // [rsp+78h] [rbp-88h]
  Scaleform::MemoryHeap *v104; // [rsp+80h] [rbp-80h]
  Scaleform::String v105; // [rsp+88h] [rbp-78h]
  Scaleform::String result; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::ASString v108; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::URLBuilder::LocationInfo v109; // [rsp+B8h] [rbp-48h]
  int v110; // [rsp+D0h] [rbp-30h]
  __int64 v111; // [rsp+D8h] [rbp-28h]
  int v112; // [rsp+E0h] [rbp-20h]
  int v113; // [rsp+E4h] [rbp-1Ch]
  Scaleform::Log *v114; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::FileOpener *v115; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ImageFileHandlerRegistry *v116; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::MovieImpl *v117; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::MovieDataDef *v118; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::MovieDefImpl *v119; // [rsp+110h] [rbp+10h]
  __int64 v120; // [rsp+118h] [rbp+18h]
  __int64 v121; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ImageResource *v122; // [rsp+128h] [rbp+28h]
  Scaleform::Render::Image *v123; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::ImageResource *v124; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::CharacterCreateInfo v125; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::AS2::MovieRoot *v126; // [rsp+1B0h] [rbp+B0h]
  bool bilinear; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::LoadStates *v128; // [rsp+1C0h] [rbp+C0h]
  unsigned int v129; // [rsp+1C8h] [rbp+C8h]

  v128 = pls;
  v126 = this;
  v121 = -2i64;
  v3 = pls;
  v4 = p_entry;
  v5 = this;
  Scaleform::String::String(&ppath);
  v6 = 0;
  v7 = v5->pMovieImpl;
  v8 = v7->MovieLevels.Data.Size;
  if ( !v8 )
    goto LABEL_8;
  v9 = 0i64;
  v10 = v7->MovieLevels.Data.Data;
  while ( v10[v9].Level )
  {
    v9 = ++v6;
    if ( v6 >= v8 )
      goto LABEL_8;
  }
  if ( !v10[v6].pSprite.pObject
    || (v11 = (const char *)((__int64 (*)(void))v7->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(),
        Scaleform::String::operator=(&ppath, v11),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  Scaleform::String::String(&url, &v4->URL);
  Scaleform::String::String(&src);
  v12 = 0i64;
  v97 = 0i64;
  v99 = 0i64;
  v96 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v3->pLog.pObject;
  LODWORD(v104) = v5->pMovieImpl->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
  v13 = 0i64;
  v94 = 0i64;
  v14 = 0i64;
  v95 = 0i64;
  LOBYTE(v15) = 0;
  v16 = (Scaleform::GFx::CharacterHandle *)v4[1].pNext;
  if ( !v16 )
  {
    v20 = (int)v4[1].vfptr;
    if ( v20 == -1 )
      goto LABEL_161;
    v21 = 0;
    v22 = v5->pMovieImpl;
    v23 = v22->MovieLevels.Data.Size;
    if ( !v23 )
      goto LABEL_27;
    v24 = 0i64;
    v25 = v22->MovieLevels.Data.Data;
    while ( v25[v24].Level != v20 )
    {
      v24 = ++v21;
      if ( v21 >= v23 )
        goto LABEL_27;
    }
    if ( v25[v21].pSprite.pObject )
    {
      v26 = 0;
      if ( v23 )
      {
        v27 = 0i64;
        while ( v25[v27].Level != v20 )
        {
          v27 = ++v26;
          if ( v26 >= v23 )
            goto LABEL_39;
        }
        goto LABEL_38;
      }
    }
    else
    {
LABEL_27:
      v28 = 0;
      if ( !v23 )
        goto LABEL_41;
      v29 = 0i64;
      v25 = v22->MovieLevels.Data.Data;
      while ( v25[v29].Level )
      {
        v29 = ++v28;
        if ( v28 >= v23 )
          goto LABEL_41;
      }
      if ( !v25[v28].pSprite.pObject )
        goto LABEL_41;
      v26 = 0;
      if ( v23 )
      {
        v30 = 0i64;
        while ( v25[v30].Level )
        {
          v30 = ++v26;
          if ( v26 >= v23 )
            goto LABEL_39;
        }
LABEL_38:
        v31 = v25[v26].pSprite.pObject;
LABEL_40:
        v32 = ((__int64 (*)(void))v31->vfptr[66].__vecDelDtor)();
        v15 = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v32 + 88i64))(v32) >> 4) & 1;
LABEL_41:
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(v5->pMovieImpl, (int)v4[1].vfptr);
        v19 = 0x40000;
        goto LABEL_42;
      }
    }
LABEL_39:
    v31 = 0i64;
    goto LABEL_40;
  }
  v17 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter(v16, v5->pMovieImpl);
  v12 = v17;
  if ( v17 )
    ++v17->RefCount;
  v97 = v17;
  if ( !v17 )
    goto LABEL_161;
  v99 = v17->pParent;
  if ( !v99 )
    goto LABEL_161;
  v18 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v17->vfptr[66].__vecDelDtor)(v17);
  LOBYTE(v15) = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v18 + 88i64))(v18) >> 4) & 1;
  v19 = v12->Id.Id;
LABEL_42:
  v129 = 0;
  if ( (_BYTE)v15 )
  {
    v33 = Scaleform::GFx::GetUrlStrGfx(&result, &url);
    Scaleform::String::operator=(&src, v33);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v14 = v95;
    v13 = v94;
    v12 = v97;
  }
  if ( !Scaleform::String::GetLength(&url) )
  {
    v55 = v126;
    v57 = v126->pMovieImpl->pLoadQueueMTHead;
    if ( !v57 )
      goto LABEL_118;
    while ( 1 )
    {
      v58 = v57->pQueueEntry;
      if ( v58->EntryTime < v4->EntryTime )
      {
        v59 = (int)v4[1].vfptr;
        if ( v59 != -1 )
        {
          v60 = (int)v58[1].vfptr;
          if ( v60 != -1 )
          {
            v61 = v59 == v60;
            goto LABEL_113;
          }
        }
        v62 = v4[1].pNext;
        if ( v62 )
        {
          v63 = v58[1].pNext;
          if ( v63 )
          {
            v61 = v62 == v63;
LABEL_113:
            if ( v61 )
              v58->Canceled = 1;
            goto LABEL_115;
          }
        }
      }
LABEL_115:
      v57 = v57->pNext;
      if ( !v57 )
        goto LABEL_118;
    }
  }
  bilinear = 0;
  if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, &bilinear, 0i64) )
  {
    v34 = Scaleform::GFx::LoadStates::GetImageCreator(v128);
    if ( !v34 )
    {
      if ( v96 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          v96 + 3,
          "ImageCreator is not installed,failed to load image \"%s\"",
          (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      goto LABEL_117;
    }
    v35 = (__int64)v126->pMovieImpl->pHeap;
    v110 = 0;
    v111 = v35;
    v112 = 1;
    v113 = 1;
    v114 = 0i64;
    v115 = 0i64;
    v116 = 0i64;
    v117 = 0i64;
    v36 = v128->pImageFileHandlerRegistry.pObject;
    v37 = v128->pBindStates.pObject->pFileOpener.pObject;
    v38 = v128->pLog.pObject;
    if ( v38 )
    {
      v39 = v38->pLog.pObject;
      if ( !v39 )
        v39 = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      v39 = 0i64;
    }
    v115 = v37;
    v114 = v39;
    v116 = v36;
    v117 = v126->pMovieImpl;
    Scaleform::String::String(&v105, (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v41 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::String *))v34->vfptr[1].__vecDelDtor)(
                                        v34,
                                        &v110,
                                        &v105);
    v123 = v41;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v105.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v41 )
    {
      v104 = v126->pMovieImpl->pHeap;
      v42 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(__int64, signed __int64))v104->vfptr->Alloc)(
                                               v40,
                                               104i64);
      v124 = v42;
      if ( v42 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v42, v41, Use_Bitmap);
        v44 = v43;
      }
      else
      {
        v44 = 0i64;
      }
      v122 = v44;
      if ( v44 )
      {
        v13 = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                v126->pMovieImpl,
                v44,
                bilinear,
                (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                v128);
        v94 = v13;
      }
      else
      {
        v13 = v94;
      }
      if ( v44 )
        Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v44->vfptr);
    }
    else
    {
      if ( v96 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          v96 + 3,
          "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
          (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      v13 = v94;
    }
    if ( v41 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v41->vfptr[2].__vecDelDtor)(v41);
    goto LABEL_91;
  }
  v45 = (unsigned int)v104 | 0x10001;
  if ( v4->QuietOpen )
    v45 = (unsigned int)v104 | 0x210001;
  if ( Scaleform::String::GetLength(&src) )
  {
    loc.Use = 3;
    Scaleform::String::String(&loc.FileName, &src);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    HIDWORD(plsa) = 0;
    v46 = v128;
    v47 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v128, &loc, v45, 0i64);
    v94 = v47;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v47 )
      goto LABEL_86;
  }
  else
  {
    v46 = v128;
  }
  v109.Use = 3;
  Scaleform::String::String(&v109.FileName, &url);
  Scaleform::String::String(&v109.ParentPath, &ppath);
  HIDWORD(plsa) = 0;
  v48 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v46, &v109, v45, 0i64);
  v94 = v48;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v109.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v109.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v48 )
  {
LABEL_86:
    v13 = v94;
    v129 = v94->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength;
LABEL_91:
    v49 = v96;
    goto LABEL_92;
  }
  v49 = v96;
  if ( v96 && !v4->QuietOpen )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
      v96 + 3,
      "Failed loading URL \"%s\"",
      (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v13 = v94;
LABEL_92:
  if ( !v13 )
  {
    v12 = v97;
    v14 = v95;
LABEL_117:
    v55 = v126;
    goto LABEL_118;
  }
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v13->vfptr[1].__vecDelDtor)(v13) != -1
    && ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v13->vfptr[1].__vecDelDtor)(v13) >= 9
    && (char)((v13->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) > 2 )
  {
    if ( v49 && !v4->QuietOpen )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        v49 + 3,
        "Failed loading SWF \"%s\": ActionScript version mismatch",
        (url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v12 = v97;
    if ( v97 )
    {
      v50 = (char *)v97 + 4 * (unsigned __int8)v97->AvmObjOffset;
      v51 = (*(__int64 (__cdecl **)(char *))(*(_QWORD *)v50 + 8i64))(v50);
      v52 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v51 + 240i64))(v51);
      v53 = v52;
      v54 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v4[1].Type, v52);
      if ( v54 )
      {
        LODWORD(plsa) = 0;
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::DisplayObject *, const char *, Scaleform::GFx::LoadStates *))v54->vfptr[4].ExecuteForEachChild_GC)(
          v54,
          v53,
          v12,
          "ActionScriptMismatch",
          plsa);
      }
    }
    v14 = v95;
    goto LABEL_161;
  }
  v118 = v13->pBindData.pObject->pDataDef.pObject;
  v119 = v13;
  v120 = 0i64;
  v55 = v126;
  v56 = v126->pASSupport.pObject;
  v101 = v19;
  v14 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, Scaleform::GFx::InteractiveObject *, int *, signed int))v56->vfptr[4].__vecDelDtor)(
                                    v56,
                                    v126->pMovieImpl,
                                    &v118,
                                    v99,
                                    &v101,
                                    3);
  v95 = v14;
  Scaleform::GFx::Sprite::SetLoadedSeparately(v14, 1);
  v12 = v97;
LABEL_118:
  LOBYTE(v128) = v14 != 0i64;
  v64 = (int)v4[1].vfptr;
  if ( v64 != -1 )
  {
    if ( v14 )
    {
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v14 + 4 * (unsigned __int8)v14->AvmObjOffset),
        v64);
      Scaleform::GFx::MovieImpl::SetLevelMovie(
        v55->pMovieImpl,
        (int)v4[1].vfptr,
        (Scaleform::GFx::DisplayObjContainer *)&v14->vfptr);
      v55->pMovieImpl->Flags &= 0xFFFFFEFF;
      v55->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, (unsigned int)v14);
    }
    v72 = 0;
    v73 = v55->pMovieImpl;
    v74 = v73->MovieLevels.Data.Size;
    if ( !v74 )
      goto LABEL_138;
    v75 = 0i64;
    v76 = v73->MovieLevels.Data.Data;
    while ( v76[v75].Level )
    {
      v75 = ++v72;
      if ( v72 >= v74 )
        goto LABEL_138;
    }
    if ( !v76[v72].pSprite.pObject )
    {
LABEL_138:
      if ( v96 )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          v96 + 3,
          "_level0 unloaded - no further playback possible");
        goto LABEL_161;
      }
    }
    goto LABEL_140;
  }
  if ( v14 )
  {
    v67 = (__int64)v99;
    goto LABEL_123;
  }
  rid.Id = 65537;
  v65 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v99->vfptr[66].__vecDelDtor)(v99);
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v65, &v125, (Scaleform::GFx::ResourceId)&rid);
  v66 = v55->pASSupport.pObject;
  v103 = v19;
  LODWORD(v92) = 3;
  v67 = (__int64)v99;
  v14 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, int *, __int64))v66->vfptr[4].__vecDelDtor)(
                                    v66,
                                    v55->pMovieImpl,
                                    &v125,
                                    v99,
                                    &v103,
                                    v92);
  v95 = v14;
  if ( v14 )
  {
LABEL_123:
    Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v14->vfptr);
    v14->CreateFrame = v12->CreateFrame;
    v14->Depth = v12->Depth;
    if ( !((LOBYTE(v12->Flags) >> 1) & 1) )
    {
      v68 = Scaleform::GFx::DisplayObject::GetName(v12, &v108);
      v14->vfptr[124].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v14->vfptr, (unsigned int)v68);
      v69 = v108.pNode;
      v61 = v108.pNode->RefCount == 1;
      --v69->RefCount;
      if ( v61 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v69);
    }
    if ( v67 )
    {
      v71 = v67 + 4i64 * *(unsigned __int8 *)(v67 + 109);
      v70 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v71 + 8i64))(v71);
    }
    else
    {
      v70 = 0i64;
    }
    (*(void (__fastcall **)(__int64, Scaleform::GFx::DisplayObject *, Scaleform::GFx::Sprite *))(*(_QWORD *)v70 + 224i64))(
      v70,
      v12,
      v14);
    v12->pParent = 0i64;
    v55->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, (unsigned int)v14);
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>((Scaleform::GFx::InteractiveObject *)&v14->vfptr);
  }
LABEL_140:
  v77 = 0;
  v78 = v55->pMovieImpl;
  v79 = v78->MovieLevels.Data.Size;
  if ( v79 )
  {
    v80 = 0i64;
    v81 = v78->MovieLevels.Data.Data;
    while ( v81[v80].Level )
    {
      v80 = ++v77;
      if ( v77 >= v79 )
        goto LABEL_146;
    }
    v82 = v81[v77].pSprite.pObject;
  }
  else
  {
LABEL_146:
    v82 = 0i64;
  }
  v83 = (signed __int64)v82 + 4 * (unsigned __int8)v82->AvmObjOffset;
  v84 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v83 + 240i64))(v83);
  v85 = (Scaleform::GFx::AS2::RefCountCollector<323> *)v84;
  v86 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v4[1].Type, v84);
  v87 = v86;
  if ( (_BYTE)v128 )
  {
    if ( v86 )
    {
      v86->vfptr[3].ExecuteForEachChild_GC(
        (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v86->vfptr,
        v85,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v14);
      LODWORD(plsa) = v129;
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::Sprite *, _QWORD, Scaleform::GFx::LoadStates *))v87->vfptr[4].Finalize_GC)(
        v87,
        v85,
        v14,
        v129,
        plsa);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::Sprite *, _QWORD))v87->vfptr[3].Finalize_GC)(
        v87,
        v85,
        v14,
        0i64);
    }
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))v14->vfptr[112].__vecDelDtor)(v14);
    v88 = v126;
    ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))v126->vfptr[7].__vecDelDtor)(v126);
    if ( v87 )
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::Sprite *))v87->vfptr[3].~RefCountBaseGC<323>)(
        v87,
        v85,
        v14);
  }
  else
  {
    if ( v86 )
    {
      v89 = Scaleform::String::GetLength(&url);
      LODWORD(plsa) = 0;
      v90 = "URLNotFound";
      if ( !v89 )
        v90 = "Unknown error";
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::Sprite *, const char *, Scaleform::GFx::LoadStates *))v87->vfptr[4].ExecuteForEachChild_GC)(
        v87,
        v85,
        v14,
        v90,
        plsa);
    }
    v88 = v126;
  }
  if ( !Scaleform::String::GetLength(&url) )
  {
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
    v12 = 0i64;
    v97 = 0i64;
    Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
      &v88->MemContext.pObject->LimHandler,
      v88->pMovieImpl->pHeap);
  }
LABEL_161:
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v14->vfptr);
  if ( v13 )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v13->vfptr);
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}lockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_Inter

// File Line: 1460
// RVA: 0x70A670
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *pentry, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v3; // r15
  Scaleform::GFx::LoadQueueEntry *v4; // r14
  Scaleform::GFx::AS2::MovieRoot *v5; // rbp
  Scaleform::GFx::InteractiveObject *v6; // rdi
  unsigned int v7; // er9
  Scaleform::GFx::MovieImpl *v8; // r11
  unsigned __int64 v9; // r10
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rcx
  const char *v12; // rax
  unsigned __int64 v13; // rdx
  unsigned int v14; // ecx
  Scaleform::GFx::MovieImpl *v15; // r8
  unsigned __int64 v16; // rdx
  __int64 v17; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // r8
  signed __int64 v19; // rcx
  Scaleform::GFx::AS2::Environment *v20; // rax
  Scaleform::GFx::AS2::Environment *v21; // rdi
  __int64 *v22; // rsi
  __int64 v23; // rbp
  Scaleform::GFx::AS2::Object *v24; // rax
  unsigned __int64 v25; // rdx
  unsigned __int64 v26; // rdx
  unsigned __int64 v27; // rdx
  unsigned __int64 v28; // rdx
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+28h] [rbp-40h]
  Scaleform::String ppath; // [rsp+70h] [rbp+8h]
  Scaleform::String pdest; // [rsp+78h] [rbp+10h]
  Scaleform::String v32; // [rsp+88h] [rbp+20h]

  v3 = pls;
  v4 = pentry;
  v5 = this;
  Scaleform::String::String(&ppath);
  v6 = 0i64;
  v7 = 0;
  v8 = v5->pMovieImpl;
  v9 = v8->MovieLevels.Data.Size;
  if ( !v9 )
    goto LABEL_8;
  v10 = 0i64;
  v11 = v8->MovieLevels.Data.Data;
  while ( v11[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= v9 )
      goto LABEL_8;
  }
  if ( !v11[v7].pSprite.pObject
    || (v12 = (const char *)((__int64 (__cdecl *)(Scaleform::GFx::MovieDefImpl *))v8->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v8->pMainMovieDef.pObject),
        Scaleform::String::operator=(&ppath, v12),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  if ( Scaleform::String::GetLength(&v4->URL) )
  {
    loc.Use = 5;
    Scaleform::String::String(&loc.FileName, &v4->URL);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    Scaleform::String::String(&pdest);
    Scaleform::GFx::LoadStates::BuildURL(v3, &pdest, &loc);
    Scaleform::String::String(&v32, (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    (*(void (__fastcall **)(_QWORD, Scaleform::String *, Scaleform::GFx::FileOpener *))(**(_QWORD **)&v4[3].EntryTime
                                                                                      + 8i64))(
      *(_QWORD *)&v4[3].EntryTime,
      &v32,
      v3->pBindStates.pObject->pFileOpener.pObject);
    v13 = v32.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v32.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v13);
    v14 = 0;
    v15 = v5->pMovieImpl;
    v16 = v15->MovieLevels.Data.Size;
    if ( v16 )
    {
      v17 = 0i64;
      v18 = v15->MovieLevels.Data.Data;
      while ( v18[v17].Level )
      {
        v17 = ++v14;
        if ( v14 >= v16 )
          goto LABEL_18;
      }
      v6 = v18[v14].pSprite.pObject;
    }
LABEL_18:
    v19 = (signed __int64)v6 + 4 * (unsigned __int8)v6->AvmObjOffset;
    v20 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, unsigned __int64))(*(_QWORD *)v19 + 240i64))(
                                                v19,
                                                v16);
    v21 = v20;
    v22 = *(__int64 **)&v4[3].EntryTime;
    v23 = *v22;
    v24 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v4[3], v20);
    (*(void (__fastcall **)(__int64 *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(v23 + 16))(
      v22,
      v21,
      v24);
    v25 = pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v25);
    v26 = loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v26);
    v27 = loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v27);
  }
  v28 = ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v28);
}

// File Line: 1507
// RVA: 0x70A5B0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVarsMT(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *p_entry, Scaleform::GFx::LoadStates *pls, Scaleform::String *data, unsigned __int64 fileLen)
{
  Scaleform::String *v5; // rbx
  Scaleform::GFx::LoadStates *v6; // rdi
  Scaleform::GFx::LoadQueueEntry *v7; // rsi
  Scaleform::GFx::AS2::MovieRoot *v8; // rbp
  Scaleform::String punescapedStr; // [rsp+68h] [rbp+20h]

  v5 = data;
  v6 = pls;
  v7 = p_entry;
  v8 = this;
  Scaleform::String::String(&punescapedStr);
  Scaleform::GFx::ASUtils::Unescape(
    (const char *)((v5->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(v5->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
    &punescapedStr);
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(v8, v7, v6, &punescapedStr, fileLen);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1522
// RVA: 0x6E2750
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *p_entry, Scaleform::GFx::LoadStates *pls, Scaleform::String *data, unsigned __int64 fileLen)
{
  Scaleform::String *v5; // r15
  Scaleform::GFx::LoadStates *v6; // r14
  Scaleform::GFx::LoadQueueEntry *v7; // rbp
  Scaleform::GFx::AS2::MovieRoot *v8; // rsi
  Scaleform::GFx::AS2::Object *v9; // rbx
  unsigned int v10; // edx
  Scaleform::GFx::MovieImpl *v11; // r8
  unsigned __int64 v12; // r9
  __int64 v13; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v14; // r8
  Scaleform::GFx::InteractiveObject *v15; // rcx
  signed __int64 v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rsi
  double v18; // xmm1_8
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::InteractiveObject *v21; // rdi
  int v22; // edx
  Scaleform::GFx::DisplayObject *v23; // rax
  Scaleform::GFx::Sprite *v24; // rbx
  unsigned int v25; // ecx
  Scaleform::GFx::MovieImpl *v26; // r9
  unsigned __int64 v27; // r8
  __int64 v28; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // r9
  signed __int64 v30; // rcx
  __int64 v31; // rax
  Scaleform::GFx::AS2::ObjectInterface *v32; // rbp
  unsigned int v33; // ecx
  Scaleform::GFx::MovieImpl *v34; // r8
  unsigned __int64 v35; // rdx
  __int64 v36; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v37; // r8
  signed __int64 v38; // rcx
  Scaleform::GFx::AS2::Environment *v39; // rax
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v5 = data;
  v6 = pls;
  v7 = p_entry;
  v8 = this;
  if ( Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[2].pNext, 0i64) )
  {
    v9 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v7[2].pNext, 0i64);
    v10 = 0;
    v11 = v8->pMovieImpl;
    v12 = v11->MovieLevels.Data.Size;
    if ( v12 )
    {
      v13 = 0i64;
      v14 = v11->MovieLevels.Data.Data;
      while ( v14[v13].Level )
      {
        v13 = ++v10;
        if ( v10 >= v12 )
          goto LABEL_8;
      }
      v15 = v14[v10].pSprite.pObject;
    }
    else
    {
LABEL_8:
      v15 = 0i64;
    }
    v16 = (signed __int64)v15 + 4 * (unsigned __int8)v15->AvmObjOffset;
    v17 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v16 + 240i64))(v16);
    Scaleform::GFx::AS2::Environment::CreateString(v17, &result, v5);
    v18 = (double)(signed int)fileLen;
    if ( (fileLen & 0x8000000000000000ui64) != 0i64 )
      v18 = v18 + 1.844674407370955e19;
    if ( *(double *)&v9[1].pRCC < 0.0 )
      v9[1].pRCC = 0i64;
    *(double *)&v9[1].vfptr = v18;
    *(double *)&v9[1].pRCC = v18 + *(double *)&v9[1].pRCC;
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData((Scaleform::GFx::AS2::LoadVarsObject *)v9, v17, &result);
    v19 = result.pNode;
    v20 = result.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    return;
  }
  v21 = 0i64;
  result.pNode = 0i64;
  v22 = (int)v7[1].vfptr;
  if ( v22 == -1 )
  {
    v23 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
            (Scaleform::GFx::CharacterHandle *)v7[1].pNext,
            v8->pMovieImpl);
    v24 = (Scaleform::GFx::Sprite *)v23;
    if ( v23 )
      ++v23->RefCount;
    result.pNode = (Scaleform::GFx::ASStringNode *)v23;
    if ( !v23 )
      goto LABEL_31;
    goto LABEL_30;
  }
  v25 = 0;
  v26 = v8->pMovieImpl;
  v27 = v26->MovieLevels.Data.Size;
  if ( v27 )
  {
    v28 = 0i64;
    v29 = v26->MovieLevels.Data.Data;
    while ( v29[v28].Level != v22 )
    {
      v28 = ++v25;
      if ( v25 >= v27 )
        goto LABEL_27;
    }
    v24 = (Scaleform::GFx::Sprite *)v29[v25].pSprite.pObject;
    if ( v24 )
      ++v24->RefCount;
  }
  else
  {
LABEL_27:
    v24 = 0i64;
  }
  result.pNode = (Scaleform::GFx::ASStringNode *)v24;
  if ( v24
    || (v24 = Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(v8, v6, (int)v7[1].vfptr),
        (result.pNode = (Scaleform::GFx::ASStringNode *)v24) != 0i64) )
  {
LABEL_30:
    v30 = (signed __int64)v24 + 4 * (unsigned __int8)v24->AvmObjOffset;
    v31 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v30 + 8i64))(v30);
    v32 = (Scaleform::GFx::AS2::ObjectInterface *)(v31 + 8);
    if ( v31 )
    {
LABEL_32:
      v33 = 0;
      v34 = v8->pMovieImpl;
      v35 = v34->MovieLevels.Data.Size;
      if ( v35 )
      {
        v36 = 0i64;
        v37 = v34->MovieLevels.Data.Data;
        while ( v37[v36].Level )
        {
          v36 = ++v33;
          if ( v33 >= v35 )
            goto LABEL_38;
        }
        v21 = v37[v33].pSprite.pObject;
      }
LABEL_38:
      v38 = (signed __int64)v21 + 4 * (unsigned __int8)v21->AvmObjOffset;
      v39 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v38 + 240i64))(v38);
      Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v39, v32, v5);
      if ( v24 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v24->vfptr);
      return;
    }
LABEL_31:
    v32 = 0i64;
    goto LABEL_32;
  }
}

// File Line: 1572
// RVA: 0x70A350
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadQueueEntry *p_entry, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v3; // r15
  Scaleform::GFx::LoadQueueEntry *v4; // r14
  Scaleform::GFx::AS2::MovieRoot *v5; // r13
  Scaleform::Render::RenderBuffer *v6; // rbx
  unsigned int v7; // er9
  Scaleform::GFx::MovieImpl *v8; // r11
  unsigned __int64 v9; // r10
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rcx
  const char *v12; // rax
  Scaleform::File *v13; // rax
  Scaleform::String pdata; // [rsp+30h] [rbp-50h]
  Scaleform::File *v15; // [rsp+38h] [rbp-48h]
  __int64 v16; // [rsp+40h] [rbp-40h]
  __int64 *v17; // [rsp+48h] [rbp-38h]
  __int64 v18; // [rsp+50h] [rbp-30h]
  __int64 v19; // [rsp+58h] [rbp-28h]
  __int64 v20; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+68h] [rbp-18h]
  int pfileLen; // [rsp+C0h] [rbp+40h]
  Scaleform::String ppath; // [rsp+C8h] [rbp+48h]
  Scaleform::String pdest; // [rsp+D8h] [rbp+58h]

  v16 = -2i64;
  v3 = pls;
  v4 = p_entry;
  v5 = this;
  Scaleform::String::String(&ppath);
  v6 = 0i64;
  v7 = 0;
  v8 = v5->pMovieImpl;
  v9 = v8->MovieLevels.Data.Size;
  if ( !v9 )
    goto LABEL_8;
  v10 = 0i64;
  v11 = v8->MovieLevels.Data.Data;
  while ( v11[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= v9 )
      goto LABEL_8;
  }
  if ( !v11[v7].pSprite.pObject
    || (v12 = (const char *)((__int64 (*)(void))v8->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(),
        Scaleform::String::operator=(&ppath, v12),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  Scaleform::String::String(&pdata);
  pfileLen = 0;
  if ( Scaleform::String::GetLength(&v4->URL) )
  {
    loc.Use = 4;
    Scaleform::String::String(&loc.FileName, &v4->URL);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    Scaleform::String::String(&pdest);
    Scaleform::GFx::LoadStates::BuildURL(v3, &pdest, &loc);
    v15 = 0i64;
    v17 = &v18;
    v18 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    if ( !Scaleform::GFx::URLBuilder::IsProtocol(&pdest) )
    {
      v13 = Scaleform::GFx::LoadStates::OpenFile(
              v3,
              (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
              0);
      v6 = (Scaleform::Render::RenderBuffer *)v13;
      v15 = v13;
      if ( v13 )
      {
        if ( LOBYTE(v4[2].pNext) == 6 )
        {
          if ( !Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v13, &pfileLen, 1) )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v4[2].pNext);
        }
        else
        {
          Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v13, &pfileLen, 1);
        }
      }
    }
    v17 = &v18;
    if ( v18 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(v5, v4, v3, &pdata, pfileLen);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap

// File Line: 1659
// RVA: 0x6DFBE0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::LoadStates *pls, int level)
{
  int v3; // er15
  Scaleform::GFx::LoadStates *v4; // r14
  Scaleform::GFx::AS2::MovieRoot *v5; // rbp
  Scaleform::GFx::Sprite *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::MemoryHeap *v8; // rbx
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::GFx::MovieDataDef *v10; // rax
  Scaleform::GFx::MovieDataDef *v11; // rax
  Scaleform::GFx::MovieDataDef *v12; // rsi
  Scaleform::GFx::Resource *v13; // rbx
  __int64 v14; // rcx
  Scaleform::GFx::MovieDefImpl *v15; // rax
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::GFx::ASSupport *v17; // rcx
  __int64 debugHeap; // [rsp+28h] [rbp-90h]
  Scaleform::GFx::ResourceKey result; // [rsp+68h] [rbp-50h]
  Scaleform::GFx::MovieDataDef *v21; // [rsp+78h] [rbp-40h]
  Scaleform::GFx::Resource *v22; // [rsp+80h] [rbp-38h]
  __int64 v23; // [rsp+88h] [rbp-30h]
  Scaleform::MemoryHeap *v24; // [rsp+C0h] [rbp+8h]
  Scaleform::GFx::MovieDataDef *v25; // [rsp+D8h] [rbp+20h]

  v3 = level;
  v4 = pls;
  v5 = this;
  v6 = 0i64;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, &customWorldMapCaption, 0i64, 0i64, 0i64);
  v7 = v5->pMovieImpl;
  v8 = v7->pHeap;
  v9 = Scaleform::Memory::pGlobalHeap;
  if ( v8 )
    v9 = v7->pHeap;
  v24 = v9;
  v10 = (Scaleform::GFx::MovieDataDef *)v9->vfptr->Alloc(v9, 72ui64, 0i64);
  v25 = v10;
  if ( v10 )
  {
    Scaleform::GFx::MovieDataDef::MovieDataDef(v10, &result, 0, &customWorldMapCaption, v8, 0, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 0i64;
  v25 = 0i64;
  if ( v12 )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(v12->pData.pObject);
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef(v4, v12);
    v24 = v5->pMovieImpl->pHeap;
    v15 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(__int64, signed __int64))v24->vfptr->Alloc)(
                                            v14,
                                            112i64);
    if ( v15 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v15,
        v12,
        v4->pBindStates.pObject,
        v4->pLoaderImpl.pObject,
        0,
        v5->pMovieImpl->pStateBag.pObject->pDelegate.pObject,
        v5->pMovieImpl->pHeap,
        1,
        0i64);
      v13 = v16;
    }
    else
    {
      v13 = 0i64;
    }
    v25 = (Scaleform::GFx::MovieDataDef *)v13;
    if ( v13 )
    {
      v21 = v12;
      v22 = v13;
      v23 = 0i64;
      v17 = v5->pASSupport.pObject;
      LODWORD(v24) = 0x40000;
      LODWORD(debugHeap) = 3;
      v6 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::MovieDataDef **, _QWORD, Scaleform::MemoryHeap **, __int64))v17->vfptr[4].__vecDelDtor)(
                                       v17,
                                       v5->pMovieImpl,
                                       &v21,
                                       0i64,
                                       &v24,
                                       debugHeap);
      Scaleform::GFx::Sprite::SetLoadedSeparately(v6, 1);
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
        v3);
      Scaleform::GFx::MovieImpl::SetLevelMovie(v5->pMovieImpl, v3, (Scaleform::GFx::DisplayObjContainer *)&v6->vfptr);
    }
  }
  if ( v13 )
    Scaleform::GFx::Resource::Release(v13);
  if ( v12 )
    Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v12->vfptr);
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  return v6;
}

// File Line: 1693
// RVA: 0x6FF070
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeAlias(Scaleform::GFx::AS2::MovieRoot *this, const char *pmethodName, Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *alias, Scaleform::GFx::AS2::Value *presult, unsigned int numArgs)
{
  Scaleform::GFx::AS2::Value *v5; // r15
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v6; // rsi
  const char *v7; // r12
  Scaleform::GFx::AS2::MovieRoot *v8; // r14
  unsigned int v9; // er10
  Scaleform::GFx::MovieImpl *v10; // r9
  unsigned __int64 v11; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // r9
  Scaleform::GFx::AS2::Object *v14; // rdi
  Scaleform::GFx::DisplayObject *v15; // rbx
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  Scaleform::GFx::AS2::ObjectInterface *v18; // rbp
  __int64 v19; // rax
  unsigned int v20; // ecx
  Scaleform::GFx::MovieImpl *v21; // r8
  unsigned __int64 v22; // rdx
  __int64 v23; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // r8
  Scaleform::GFx::InteractiveObject *v25; // rcx
  Scaleform::GFx::AS2::Environment *v26; // r14
  Scaleform::GFx::ASStringNode *v27; // rdx
  Scaleform::GFx::AS2::LocalFrame *v28; // rdx
  char v29; // si
  unsigned int v30; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+50h] [rbp-48h]

  v5 = presult;
  v6 = alias;
  v7 = pmethodName;
  v8 = this;
  v9 = 0;
  v10 = this->pMovieImpl;
  v11 = v10->MovieLevels.Data.Size;
  if ( !v11 )
    return 0;
  v12 = 0i64;
  v13 = v10->MovieLevels.Data.Data;
  while ( v13[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= v11 )
      return 0;
  }
  if ( !v13[v9].pSprite.pObject )
    return 0;
  if ( alias->ThisObject.pObject )
    alias->ThisObject.pObject->RefCount = (alias->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  v14 = alias->ThisObject.pObject;
  v15 = 0i64;
  v16 = alias->ThisChar.pObject;
  if ( v16 )
  {
    v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v16, v8->pMovieImpl);
    v15 = v17;
    if ( v17 )
      ++v17->RefCount;
  }
  if ( v14 )
  {
    v18 = (Scaleform::GFx::AS2::ObjectInterface *)&v14->vfptr;
  }
  else if ( v15
         && (v19 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v15->vfptr
                                                                               + 4 * (unsigned __int8)v15->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    v18 = (Scaleform::GFx::AS2::ObjectInterface *)(v19 + 8);
  }
  else
  {
    v18 = 0i64;
  }
  v20 = 0;
  v21 = v8->pMovieImpl;
  v22 = v21->MovieLevels.Data.Size;
  if ( v22 )
  {
    v23 = 0i64;
    v24 = v21->MovieLevels.Data.Data;
    while ( v24[v23].Level )
    {
      v23 = ++v20;
      if ( v20 >= v22 )
        goto LABEL_24;
    }
    v25 = v24[v20].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v25 = 0i64;
  }
  v26 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v25->vfptr + 4 * (unsigned __int8)v25->AvmObjOffset))[30].__vecDelDtor)();
  method.T.Type = 8;
  method.V.FunctionValue.Flags = 0;
  v27 = (Scaleform::GFx::ASStringNode *)v6->Function.Function;
  method.V.pStringNode = v27;
  if ( v27 )
    v27->RefCount = (v27->RefCount + 1) & 0x8FFFFFFF;
  method.V.FunctionValue.pLocalFrame = 0i64;
  v28 = v6->Function.pLocalFrame;
  if ( v28 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&method.NV.8,
      v28,
      v6->Function.Flags & 1);
  v29 = Scaleform::GFx::AS2::GAS_Invoke(
          &method,
          v5,
          v18,
          v26,
          numArgs,
          32 * v26->Stack.Pages.Data.Size
        - 32
        + ((_QWORD)((char *)v26->Stack.pCurrent - (char *)v26->Stack.pPageStart) >> 5),
          v7);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v15 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v15->vfptr);
  if ( v14 )
  {
    v30 = v14->RefCount;
    if ( v30 & 0x3FFFFFF )
    {
      v14->RefCount = v30 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
    }
  }
  return v29;
}

// File Line: 1716
// RVA: 0x6FF2A0
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(Scaleform::GFx::AS2::MovieRoot *this, const char *pmethodName, Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *alias, Scaleform::GFx::AS2::Value *presult)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v5; // rsi
  Scaleform::GFx::AS2::MovieRoot *v6; // r14
  unsigned int v7; // er10
  Scaleform::GFx::MovieImpl *v8; // r9
  unsigned __int64 v9; // r11
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // r9
  Scaleform::GFx::AS2::Object *v12; // rdi
  Scaleform::GFx::DisplayObject *v13; // rbx
  Scaleform::GFx::CharacterHandle *v14; // rcx
  Scaleform::GFx::DisplayObject *v15; // rax
  Scaleform::GFx::AS2::ObjectInterface *v16; // rbp
  __int64 v17; // rax
  unsigned int v18; // ecx
  Scaleform::GFx::MovieImpl *v19; // r8
  unsigned __int64 v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v22; // r8
  Scaleform::GFx::InteractiveObject *v23; // rcx
  Scaleform::GFx::AS2::Environment *v24; // r14
  Scaleform::GFx::ASStringNode *v25; // rdx
  Scaleform::GFx::AS2::LocalFrame *v26; // rdx
  char v27; // si
  unsigned int v28; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+50h] [rbp-48h]

  v4 = presult;
  v5 = alias;
  v6 = this;
  v7 = 0;
  v8 = this->pMovieImpl;
  v9 = v8->MovieLevels.Data.Size;
  if ( !v9 )
    return 0;
  v10 = 0i64;
  v11 = v8->MovieLevels.Data.Data;
  while ( v11[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= v9 )
      return 0;
  }
  if ( !v11[v7].pSprite.pObject )
    return 0;
  if ( alias->ThisObject.pObject )
    alias->ThisObject.pObject->RefCount = (alias->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  v12 = alias->ThisObject.pObject;
  v13 = 0i64;
  v14 = alias->ThisChar.pObject;
  if ( v14 )
  {
    v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, v6->pMovieImpl);
    v13 = v15;
    if ( v15 )
      ++v15->RefCount;
  }
  if ( v12 )
  {
    v16 = (Scaleform::GFx::AS2::ObjectInterface *)&v12->vfptr;
  }
  else if ( v13
         && (v17 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v13->vfptr
                                                                               + 4 * (unsigned __int8)v13->AvmObjOffset))[1].__vecDelDtor)()) != 0 )
  {
    v16 = (Scaleform::GFx::AS2::ObjectInterface *)(v17 + 8);
  }
  else
  {
    v16 = 0i64;
  }
  v18 = 0;
  v19 = v6->pMovieImpl;
  v20 = v19->MovieLevels.Data.Size;
  if ( v20 )
  {
    v21 = 0i64;
    v22 = v19->MovieLevels.Data.Data;
    while ( v22[v21].Level )
    {
      v21 = ++v18;
      if ( v18 >= v20 )
        goto LABEL_24;
    }
    v23 = v22[v18].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v23 = 0i64;
  }
  v24 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v23->vfptr + 4 * (unsigned __int8)v23->AvmObjOffset))[30].__vecDelDtor)();
  method.T.Type = 8;
  method.V.FunctionValue.Flags = 0;
  v25 = (Scaleform::GFx::ASStringNode *)v5->Function.Function;
  method.V.pStringNode = v25;
  if ( v25 )
    v25->RefCount = (v25->RefCount + 1) & 0x8FFFFFFF;
  method.V.FunctionValue.pLocalFrame = 0i64;
  v26 = v5->Function.pLocalFrame;
  if ( v26 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&method.NV.8,
      v26,
      v5->Function.Flags & 1);
  v27 = Scaleform::GFx::AS2::GAS_InvokeParsed(&method, v4, v16, v24);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v13->vfptr);
  if ( v12 )
  {
    v28 = v12->RefCount;
    if ( v28 & 0x3FFFFFF )
    {
      v12->RefCount = v28 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
    }
  }
  return v27;
}

// File Line: 1739
// RVA: 0x6D8720
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::ASString *alias, Scaleform::GFx::CharacterHandle *pthisChar, Scaleform::GFx::AS2::Object *pthisObj, Scaleform::GFx::AS2::FunctionRef *func)
{
  Scaleform::GFx::AS2::Object *v5; // rbx
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::ASString *v7; // rbp
  Scaleform::GFx::AS2::MovieRoot *v8; // rsi
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::CharacterHandle *v12; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v13; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo v15; // [rsp+38h] [rbp-40h]

  v5 = pthisObj;
  v6 = pthisChar;
  v7 = alias;
  v8 = this;
  if ( !this->pInvokeAliases )
  {
    v9 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                                                            Scaleform::Memory::pGlobalHeap,
                                                                                            8ui64,
                                                                                            0i64);
    if ( v9 )
      v9->mHash.pTable = 0i64;
    else
      v9 = 0i64;
    v8->pInvokeAliases = v9;
  }
  v15.ThisObject.pObject = 0i64;
  v15.ThisChar.pObject = 0i64;
  v15.Function.Flags = 0;
  v15.Function.Function = 0i64;
  v15.Function.pLocalFrame = 0i64;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
  v10 = v15.ThisObject.pObject;
  if ( v15.ThisObject.pObject )
  {
    v11 = v15.ThisObject.pObject->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v15.ThisObject.pObject->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr);
    }
  }
  v15.ThisObject.pObject = v5;
  if ( v6 )
    ++v6->RefCount;
  v12 = v15.ThisChar.pObject;
  if ( v15.ThisChar.pObject )
  {
    --v15.ThisChar.pObject->RefCount;
    if ( v12->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v12);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
    }
  }
  v15.ThisChar.pObject = v6;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(
    (Scaleform::GFx::AS2::FunctionRefBase *)&v15.Function.Function,
    (Scaleform::GFx::AS2::FunctionRefBase *)&func->Function);
  v13 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v8->pInvokeAliases->mHash.pTable;
  key.pFirst = v7;
  key.pSecond = &v15;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
    v13,
    v13,
    &key);
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::~InvokeAliasInfo(&v15);
}

// File Line: 1750
// RVA: 0x6F67A0
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::AS2::MovieRoot::GetTextAllocator(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot *v1; // rbx
  Scaleform::GFx::AS2::MemoryContextImpl *v2; // rcx
  Scaleform::Render::Text::Allocator *v3; // rax
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rsi
  Scaleform::GFx::AS2::MemoryContextImpl *v6; // rdi
  Scaleform::RefCountNTSImpl *v7; // rcx

  v1 = this;
  v2 = this->MemContext.pObject;
  if ( v2->TextAllocator.pObject )
    return v2->TextAllocator.pObject;
  v3 = (Scaleform::Render::Text::Allocator *)v2->Heap->vfptr->Alloc((Scaleform::MemoryHeap *)v2, 144ui64, 0i64);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, v1->MemContext.pObject->Heap, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->MemContext.pObject;
  v7 = (Scaleform::RefCountNTSImpl *)&v6->TextAllocator.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v6->TextAllocator.pObject = v5;
  return v1->MemContext.pObject->TextAllocator.pObject;
}

// File Line: 1760
// RVA: 0x712250
Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__fastcall Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(Scaleform::GFx::AS2::MovieRoot *this, const char *pstr)
{
  const char *v2; // rsi
  Scaleform::GFx::AS2::MovieRoot *v3; // rdi
  signed __int64 v4; // rbx
  unsigned int v5; // er8
  Scaleform::GFx::MovieImpl *v6; // rdx
  unsigned __int64 v7; // r9
  __int64 v8; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v9; // rdx
  unsigned int v10; // ecx
  __int64 v11; // rax
  Scaleform::GFx::InteractiveObject *v12; // rcx
  signed __int64 v13; // rcx
  Scaleform::GFx::AS2::Environment *v14; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v15; // r11
  unsigned __int64 v16; // rdi
  __int64 v17; // r10
  signed __int64 v18; // r8
  unsigned __int64 *v19; // r9
  Scaleform::GFx::ASStringNode *v20; // rdx
  signed __int64 v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  bool v23; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = pstr;
  v3 = this;
  if ( !this->pInvokeAliases )
    return 0i64;
  v4 = 0i64;
  v5 = 0;
  v6 = this->pMovieImpl;
  v7 = v6->MovieLevels.Data.Size;
  if ( !v7 )
    return 0i64;
  v8 = 0i64;
  v9 = v6->MovieLevels.Data.Data;
  while ( v9[v8].Level )
  {
    v8 = ++v5;
    if ( v5 >= v7 )
      return 0i64;
  }
  if ( !v9[v5].pSprite.pObject )
    return 0i64;
  v10 = 0;
  if ( v7 )
  {
    v11 = 0i64;
    while ( v9[v11].Level )
    {
      v11 = ++v10;
      if ( v10 >= v7 )
        goto LABEL_14;
    }
    v12 = v9[v10].pSprite.pObject;
  }
  else
  {
LABEL_14:
    v12 = 0i64;
  }
  v13 = (signed __int64)v12 + 4 * (unsigned __int8)v12->AvmObjOffset;
  v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::Environment::CreateString(v14, &result, v2);
  v15 = v3->pInvokeAliases->mHash.pTable;
  if ( v15 )
  {
    v16 = v15->SizeMask;
    v17 = (unsigned int)v16 & result.pNode->HashFlags;
    v18 = (unsigned int)v16 & result.pNode->HashFlags;
    v19 = &v15[1].EntryCount + 7 * v17;
    if ( *v19 != -2i64 && ((unsigned int)v16 & *(_DWORD *)(v19[1] + 28)) == v17 )
    {
      while ( 1 )
      {
        v20 = (Scaleform::GFx::ASStringNode *)v19[1];
        if ( ((unsigned int)v16 & v20->HashFlags) == v17 && v20 == result.pNode )
          break;
        v18 = *v19;
        if ( *v19 == -1i64 )
          goto LABEL_25;
        v19 = &v15[1].EntryCount + 7 * v18;
      }
      if ( v18 >= 0 )
      {
        v21 = (signed __int64)(&v15[1].SizeMask + 7 * v18);
        if ( v21 )
          v4 = v21 + 8;
      }
    }
  }
LABEL_25:
  v22 = result.pNode;
  v23 = result.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v23 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  return (Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *)v4;
}

// File Line: 1772
// RVA: 0x6F7790
char __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariable(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *pval, const char *ppathToVar)
{
  const char *v3; // rbp
  Scaleform::GFx::Value *v4; // rdi
  Scaleform::GFx::AS2::MovieRoot *v5; // rsi
  unsigned int v6; // er9
  Scaleform::GFx::MovieImpl *v7; // r11
  unsigned __int64 v8; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // r11
  unsigned int v11; // ecx
  __int64 v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rcx
  Scaleform::GFx::AS2::Environment *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v3 = ppathToVar;
  v4 = pval;
  v5 = this;
  v6 = 0;
  v7 = this->pMovieImpl;
  v8 = v7->MovieLevels.Data.Size;
  if ( !v8 )
    return 0;
  v9 = 0i64;
  v10 = v7->MovieLevels.Data.Data;
  while ( v10[v9].Level )
  {
    v9 = ++v6;
    if ( v6 >= v8 )
      return 0;
  }
  if ( !v10[v6].pSprite.pObject || !pval )
    return 0;
  v11 = 0;
  if ( v8 )
  {
    v12 = 0i64;
    while ( v10[v12].Level )
    {
      v12 = ++v11;
      if ( v11 >= v8 )
        goto LABEL_14;
    }
    v13 = v10[v11].pSprite.pObject;
  }
  else
  {
LABEL_14:
    v13 = 0i64;
  }
  v14 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v13->vfptr + 4 * (unsigned __int8)v13->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v14, &result, v3);
  presult.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v14, &result, &presult, 0i64) )
  {
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    v18 = result.pNode;
    v16 = result.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    return 0;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v5, v14, &presult, v4);
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v15 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  return 1;
}

// File Line: 1795
// RVA: 0x71D450
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariable(Scaleform::GFx::AS2::MovieRoot *this, const char *ppathToVar, Scaleform::GFx::Value *value, Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::Movie::SetVarType v4; // edi
  Scaleform::GFx::Value *v5; // r14
  const char *v6; // rbp
  Scaleform::GFx::AS2::MovieRoot *v7; // rsi
  Scaleform::GFx::InteractiveObject *v8; // rbx
  unsigned int v9; // er10
  Scaleform::GFx::MovieImpl *v10; // rcx
  unsigned __int64 v11; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // r9
  Scaleform::Log *v14; // rbx
  Scaleform::Log *v15; // rbx
  unsigned int v16; // ecx
  __int64 v17; // rax
  Scaleform::GFx::InteractiveObject *v18; // rcx
  Scaleform::GFx::AS2::Environment *v19; // rax
  unsigned int v20; // ecx
  Scaleform::GFx::MovieImpl *v21; // rdx
  unsigned __int64 v22; // r8
  __int64 v23; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v24; // rdx
  Scaleform::GFx::AS2::Environment *v25; // rax
  char v26; // bl
  Scaleform::GFx::ASStringNode *v27; // rcx
  bool v28; // zf
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+30h] [rbp-48h]
  __int64 v31; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::ASString varname; // [rsp+80h] [rbp+8h]

  v31 = -2i64;
  v4 = setType;
  v5 = value;
  v6 = ppathToVar;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = this->pMovieImpl;
  v11 = v10->MovieLevels.Data.Size;
  if ( !v11 )
    return 0;
  v12 = 0i64;
  v13 = v10->MovieLevels.Data.Data;
  while ( v13[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= v11 )
      return 0;
  }
  if ( !v13[v9].pSprite.pObject )
    return 0;
  if ( !ppathToVar )
  {
    v14 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v10->vfptr, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v14 )
    {
      v15 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v7->pMovieImpl->vfptr, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      Scaleform::Log::LogError(v15, "NULL pathToVar passed to SetVariable/SetDouble()");
    }
    return 0;
  }
  v16 = 0;
  if ( v11 )
  {
    v17 = 0i64;
    while ( v13[v17].Level )
    {
      v17 = ++v16;
      if ( v16 >= v11 )
        goto LABEL_20;
    }
    v18 = v13[v16].pSprite.pObject;
  }
  else
  {
LABEL_20:
    v18 = 0i64;
  }
  v19 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v18->vfptr + 4 * (unsigned __int8)v18->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v19, &varname, v6);
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v7, v5, &pdestVal);
  v20 = 0;
  v21 = v7->pMovieImpl;
  v22 = v21->MovieLevels.Data.Size;
  if ( v22 )
  {
    v23 = 0i64;
    v24 = v21->MovieLevels.Data.Data;
    while ( v24[v23].Level )
    {
      v23 = ++v20;
      if ( v20 >= v22 )
        goto LABEL_27;
    }
    v8 = v24[v20].pSprite.pObject;
  }
LABEL_27:
  v25 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->vfptr + 4 * (unsigned __int8)v8->AvmObjOffset))[30].__vecDelDtor)();
  v26 = Scaleform::GFx::AS2::Environment::SetVariable(v25, &varname, &pdestVal, 0i64, v4 == 0);
  if ( !v26 && v4 || v4 == 2 )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v7, &varname, &pdestVal, v4);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  v27 = varname.pNode;
  v28 = varname.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v28 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  return v26;
}

// File Line: 1830
// RVA: 0x71D660
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariableArray(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Movie::SetArrayType type, const char *ppathToVar, unsigned int index)
{
  unsigned int v4; // er12
  const char *v5; // rdi
  Scaleform::GFx::Movie::SetArrayType v6; // esi
  Scaleform::GFx::AS2::MovieRoot *v7; // r13
  Scaleform::GFx::InteractiveObject *v8; // r15
  unsigned int v9; // er10
  Scaleform::GFx::MovieImpl *v10; // r8
  unsigned __int64 v11; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // r8
  unsigned int v14; // ecx
  __int64 v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  __int64 v18; // rcx
  Scaleform::GFx::AS2::Object *v19; // rax
  __int64 v20; // rdx
  __int64 v21; // r8
  __int64 v22; // rbx
  Scaleform::GFx::ASStringNode *v23; // rbx
  __int64 v24; // rdx
  Scaleform::GFx::MovieImpl *v25; // r9
  unsigned __int64 v26; // r8
  __int64 v27; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // r9
  Scaleform::GFx::InteractiveObject *v29; // rcx
  signed __int64 v30; // rcx
  Scaleform::GFx::AS2::Environment *v31; // rax
  __int64 v32; // rax
  unsigned int v33; // esi
  int *v34; // r14
  unsigned int v35; // esi
  float *v36; // r14
  unsigned int v37; // esi
  Scaleform::GFx::ASStringNode **v38; // r14
  unsigned int v39; // esi
  unsigned int v40; // esi
  const char **v41; // r14
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  bool v44; // zf
  unsigned int v45; // esi
  const wchar_t **v46; // r14
  Scaleform::GFx::ASString *v47; // rax
  Scaleform::GFx::ASStringNode *v48; // rcx
  unsigned int v49; // ecx
  Scaleform::GFx::MovieImpl *v50; // rdx
  unsigned __int64 v51; // r8
  __int64 v52; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v53; // rdx
  Scaleform::GFx::AS2::Environment *v54; // rax
  char v55; // di
  int v56; // eax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+18h] [rbp-71h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::ASString v61; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::ASString v62; // [rsp+48h] [rbp-41h]
  __int64 v63; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Value v64; // [rsp+58h] [rbp-31h]
  Scaleform::GFx::AS2::Value presult; // [rsp+78h] [rbp-11h]
  __int64 v66; // [rsp+98h] [rbp+Fh]
  Scaleform::GFx::AS2::MovieRoot *v67; // [rsp+D8h] [rbp+4Fh]
  Scaleform::GFx::Value *retaddr; // [rsp+F8h] [rbp+6Fh]
  Scaleform::GFx::AS2::MovieRoot *v69; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::Movie::SetVarType v70; // [rsp+108h] [rbp+7Fh]

  v69 = this;
  v66 = -2i64;
  v4 = index;
  v5 = ppathToVar;
  v6 = type;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = this->pMovieImpl;
  v11 = v10->MovieLevels.Data.Size;
  if ( !v11 )
    return 0;
  v12 = 0i64;
  v13 = v10->MovieLevels.Data.Data;
  while ( v13[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= v11 )
      return 0;
  }
  if ( !v13[v9].pSprite.pObject )
    return 0;
  v14 = 0;
  if ( v11 )
  {
    v15 = 0i64;
    while ( v13[v15].Level )
    {
      v15 = ++v14;
      if ( v14 >= v11 )
        goto LABEL_13;
    }
    v16 = v13[v14].pSprite.pObject;
  }
  else
  {
LABEL_13:
    v16 = 0i64;
  }
  v17 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v16->vfptr + 4 * (unsigned __int8)v16->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v17, &result, v5);
  v63 = 0i64;
  presult.T.Type = 0;
  *((_DWORD *)&val.NV + 6) = 0;
  *(_OWORD *)&val.NV.Int32Value = 0ui64;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v17, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v19 = Scaleform::GFx::AS2::Value::ToObject(&presult, v17), (v22 = (__int64)v19) != 0)
    && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, __int64, __int64))&v19->vfptr->gap8[8])(
         &v19->vfptr,
         v20,
         v21) == 7 )
  {
    *(_DWORD *)(v22 + 24) = (*(_DWORD *)(v22 + 24) + 1) & 0x8FFFFFFF;
  }
  else
  {
    v61.pNode = (Scaleform::GFx::ASStringNode *)v7->pMovieImpl->pHeap;
    v23 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(__int64, signed __int64, _QWORD))v61.pNode->pData
                                           + 10))(
                                            v18,
                                            144i64,
                                            0i64);
    v62.pNode = v23;
    if ( v23 )
    {
      v24 = 0i64;
      v25 = v7->pMovieImpl;
      v26 = v25->MovieLevels.Data.Size;
      if ( v26 )
      {
        v27 = 0i64;
        v28 = v25->MovieLevels.Data.Data;
        while ( v28[v27].Level )
        {
          v24 = (unsigned int)(v24 + 1);
          v27 = (unsigned int)v24;
          if ( (unsigned int)v24 >= v26 )
            goto LABEL_26;
        }
        v29 = v28[(unsigned int)v24].pSprite.pObject;
      }
      else
      {
LABEL_26:
        v29 = 0i64;
      }
      v30 = (signed __int64)v29 + 4 * (unsigned __int8)v29->AvmObjOffset;
      v31 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, __int64, unsigned __int64))(*(_QWORD *)v30 + 240i64))(
                                                  v30,
                                                  v24,
                                                  v26);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v23, v31);
      v22 = v32;
    }
    else
    {
      v22 = 0i64;
    }
  }
  v63 = v22;
  if ( v4 + (unsigned int)v69 > *(_DWORD *)(v22 + 112) )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v22, v4 + (_DWORD)v69);
  switch ( v6 )
  {
    case 0:
      v33 = 0;
      if ( (_DWORD)v69 )
      {
        v34 = (int *)retaddr;
        do
        {
          val.NV.Int32Value = *v34;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v33 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v33;
          ++v34;
        }
        while ( v33 < (unsigned int)v69 );
      }
      break;
    case 1:
      v37 = 0;
      if ( (_DWORD)v69 )
      {
        v38 = (Scaleform::GFx::ASStringNode **)retaddr;
        do
        {
          val.V.pStringNode = *v38;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v37 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v37;
          ++v38;
        }
        while ( v37 < (unsigned int)v69 );
      }
      break;
    case 2:
      v35 = 0;
      if ( (_DWORD)v69 )
      {
        v36 = (float *)retaddr;
        do
        {
          val.NV.NumberValue = *v36;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v35 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v35;
          ++v36;
        }
        while ( v35 < (unsigned int)v69 );
      }
      break;
    case 3:
      v40 = 0;
      if ( (_DWORD)v69 )
      {
        v41 = (const char **)retaddr;
        do
        {
          v42 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)v7->BuiltinsMgr.Builtins,
                  &v62,
                  *v41);
          val.T.Type = 5;
          val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v42->pNode;
          ++val.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v40 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          v43 = v62.pNode;
          v44 = v62.pNode->RefCount == 1;
          --v43->RefCount;
          if ( v44 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v43);
          ++v40;
          ++v41;
        }
        while ( v40 < (unsigned int)v69 );
        goto LABEL_70;
      }
      break;
    case 4:
      v45 = 0;
      if ( (_DWORD)v69 )
      {
        v46 = (const wchar_t **)retaddr;
        do
        {
          v47 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)v7->BuiltinsMgr.Builtins,
                  &v61,
                  *v46,
                  -1i64);
          val.T.Type = 5;
          val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v47->pNode;
          ++val.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v45 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          v48 = v61.pNode;
          v44 = v61.pNode->RefCount == 1;
          --v48->RefCount;
          if ( v44 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v48);
          ++v45;
          ++v46;
        }
        while ( v45 < (unsigned int)v69 );
LABEL_70:
        v7 = v67;
      }
      break;
    case 5:
      v39 = 0;
      if ( (_DWORD)v69 )
      {
        do
        {
          Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v7, &retaddr[v39], &val);
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v22, v39 + v4, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v39;
        }
        while ( v39 < (unsigned int)v69 );
      }
      break;
    default:
      break;
  }
  v64.T.Type = 0;
  Scaleform::GFx::AS2::Value::SetAsObject(&v64, (Scaleform::GFx::AS2::Object *)v22);
  v49 = 0;
  v50 = v7->pMovieImpl;
  v51 = v50->MovieLevels.Data.Size;
  if ( v51 )
  {
    v52 = 0i64;
    v53 = v50->MovieLevels.Data.Data;
    while ( v53[v52].Level )
    {
      v52 = ++v49;
      if ( v49 >= v51 )
        goto LABEL_77;
    }
    v8 = v53[v49].pSprite.pObject;
  }
LABEL_77:
  v54 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v8->vfptr + 4 * (unsigned __int8)v8->AvmObjOffset))[30].__vecDelDtor)();
  v55 = Scaleform::GFx::AS2::Environment::SetVariable(v54, &result, &v64, 0i64, v70 == 0);
  if ( !v55 && v70 || v70 == 2 )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v7, &result, &v64, v70);
  if ( v64.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v64);
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v56 = *(_DWORD *)(v22 + 24);
  if ( v56 & 0x3FFFFFF )
  {
    *(_DWORD *)(v22 + 24) = v56 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v22);
  }
  v57 = result.pNode;
  v44 = result.pNode->RefCount == 1;
  --v57->RefCount;
  if ( v44 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  return v55;
}

// File Line: 1935
// RVA: 0x71DBC0
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariableArraySize(Scaleform::GFx::AS2::MovieRoot *this, const char *ppathToVar, unsigned int count, Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::Movie::SetVarType v4; // esi
  int v5; // er14
  const char *v6; // r15
  Scaleform::GFx::AS2::MovieRoot *v7; // rbp
  __int64 v8; // rdi
  unsigned int v9; // er10
  Scaleform::GFx::MovieImpl *v10; // r9
  unsigned __int64 v11; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v13; // r9
  unsigned int v14; // ecx
  __int64 v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rbx
  Scaleform::MemoryHeap *v18; // rcx
  Scaleform::GFx::AS2::Object *v19; // rax
  __int64 v20; // rdx
  __int64 v21; // r8
  Scaleform::GFx::AS2::Object *v22; // rbx
  char v23; // di
  Scaleform::GFx::AS2::ArrayObject *v24; // rbx
  __int64 v25; // rdx
  Scaleform::GFx::MovieImpl *v26; // r9
  unsigned __int64 v27; // r8
  __int64 v28; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // r9
  Scaleform::GFx::InteractiveObject *v30; // rcx
  signed __int64 v31; // rcx
  Scaleform::GFx::AS2::Environment *v32; // rax
  Scaleform::GFx::AS2::Object *v33; // rax
  unsigned int v34; // ecx
  Scaleform::GFx::MovieImpl *v35; // rdx
  unsigned __int64 v36; // r8
  __int64 v37; // rax
  signed __int64 v38; // rcx
  Scaleform::GFx::AS2::Environment *v39; // rax
  unsigned int v40; // eax
  Scaleform::GFx::ASStringNode *v41; // rcx
  bool v42; // zf
  Scaleform::GFx::AS2::Value val; // [rsp+60h] [rbp-58h]
  Scaleform::GFx::AS2::Value presult; // [rsp+80h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+8h]

  v4 = setType;
  v5 = count;
  v6 = ppathToVar;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = this->pMovieImpl;
  v11 = v10->MovieLevels.Data.Size;
  if ( !v11 )
    return 0;
  v12 = 0i64;
  v13 = v10->MovieLevels.Data.Data;
  while ( v13[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= v11 )
      return 0;
  }
  if ( !v13[v9].pSprite.pObject )
    return 0;
  v14 = 0;
  if ( v11 )
  {
    v15 = 0i64;
    while ( v13[v15].Level )
    {
      v15 = ++v14;
      if ( v14 >= v11 )
        goto LABEL_13;
    }
    v16 = v13[v14].pSprite.pObject;
  }
  else
  {
LABEL_13:
    v16 = 0i64;
  }
  v17 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v16->vfptr + 4 * (unsigned __int8)v16->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v17, &result, v6);
  presult.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v17, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v19 = Scaleform::GFx::AS2::Value::ToObject(&presult, v17), (v22 = v19) != 0i64)
    && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, __int64, __int64))&v19->vfptr->gap8[8])(
         &v19->vfptr,
         v20,
         v21) == 7 )
  {
    v22->RefCount = (v22->RefCount + 1) & 0x8FFFFFFF;
    if ( v5 != v22[1].RootIndex )
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v22, v5);
    v23 = 1;
  }
  else
  {
    v24 = (Scaleform::GFx::AS2::ArrayObject *)v7->pMovieImpl->pHeap->vfptr->Alloc(v18, 144ui64, 0i64);
    if ( v24 )
    {
      v25 = 0i64;
      v26 = v7->pMovieImpl;
      v27 = v26->MovieLevels.Data.Size;
      if ( v27 )
      {
        v28 = 0i64;
        v29 = v26->MovieLevels.Data.Data;
        while ( v29[v28].Level )
        {
          v25 = (unsigned int)(v25 + 1);
          v28 = (unsigned int)v25;
          if ( (unsigned int)v25 >= v27 )
            goto LABEL_28;
        }
        v30 = v29[(unsigned int)v25].pSprite.pObject;
      }
      else
      {
LABEL_28:
        v30 = 0i64;
      }
      v31 = (signed __int64)v30 + 4 * (unsigned __int8)v30->AvmObjOffset;
      v32 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, __int64, unsigned __int64))(*(_QWORD *)v31 + 240i64))(
                                                  v31,
                                                  v25,
                                                  v27);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v24, v32);
      v22 = v33;
    }
    else
    {
      v22 = 0i64;
    }
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v22, v5);
    val.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObject(&val, v22);
    v34 = 0;
    v35 = v7->pMovieImpl;
    v36 = v35->MovieLevels.Data.Size;
    if ( v36 )
    {
      v37 = 0i64;
      v35 = (Scaleform::GFx::MovieImpl *)v35->MovieLevels.Data.Data;
      while ( LODWORD((&v35->vfptr)[2 * v37]) )
      {
        v37 = ++v34;
        if ( v34 >= v36 )
          goto LABEL_37;
      }
      v8 = *((_QWORD *)&v35->RefCount + 2 * v34);
    }
LABEL_37:
    v38 = v8 + 4i64 * *(unsigned __int8 *)(v8 + 109);
    v39 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, Scaleform::GFx::MovieImpl *, unsigned __int64))(*(_QWORD *)v38 + 240i64))(
                                                v38,
                                                v35,
                                                v36);
    v23 = Scaleform::GFx::AS2::Environment::SetVariable(v39, &result, &val, 0i64, v4 == 0);
    if ( !v23 && v4 || v4 == 2 )
      Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v7, &result, &val, v4);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  if ( v22 )
  {
    v40 = v22->RefCount;
    if ( v40 & 0x3FFFFFF )
    {
      v22->RefCount = v40 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v22->vfptr);
    }
  }
  v41 = result.pNode;
  v42 = result.pNode->RefCount == 1;
  --v41->RefCount;
  if ( v42 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  return v23;
}

// File Line: 1976
// RVA: 0x6F7F00
__int64 __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariableArraySize(Scaleform::GFx::AS2::MovieRoot *this, const char *ppathToVar)
{
  const char *v2; // rdi
  unsigned int v3; // er8
  Scaleform::GFx::MovieImpl *v4; // r10
  unsigned __int64 v5; // r9
  __int64 v6; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v7; // r10
  unsigned int v8; // ecx
  __int64 v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rbx
  Scaleform::GFx::AS2::Object *v12; // rax
  __int64 v13; // r8
  Scaleform::GFx::AS2::Object *v14; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v2 = ppathToVar;
  v3 = 0;
  v4 = this->pMovieImpl;
  v5 = v4->MovieLevels.Data.Size;
  if ( !v5 )
    return 0i64;
  v6 = 0i64;
  v7 = v4->MovieLevels.Data.Data;
  while ( v7[v6].Level )
  {
    v6 = ++v3;
    if ( v3 >= v5 )
      return 0i64;
  }
  if ( !v7[v3].pSprite.pObject )
    return 0i64;
  v8 = 0;
  if ( v5 )
  {
    v9 = 0i64;
    while ( v7[v9].Level )
    {
      v9 = ++v8;
      if ( v8 >= v5 )
        goto LABEL_13;
    }
    v10 = v7[v8].pSprite.pObject;
  }
  else
  {
LABEL_13:
    v10 = 0i64;
  }
  v11 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v10->vfptr + 4 * (unsigned __int8)v10->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v11, &result, v2);
  presult.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v11, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v12 = Scaleform::GFx::AS2::Value::ToObject(&presult, v11), (v14 = v12) != 0i64)
    && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ObjectInterfaceVtbl *, __int64))&v12->vfptr->gap8[8])(
         &v12->vfptr,
         v12->vfptr,
         v13) == 7 )
  {
    v15 = v14[1].pPrev;
  }
  else
  {
    LODWORD(v15) = 0;
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v16 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return (unsigned int)v15;
}

// File Line: 1998
// RVA: 0x6F7910
char __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariableArray(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Movie::SetArrayType type, const char *ppathToVar, unsigned int index)
{
  signed __int64 v4; // r14
  const char *v5; // rdi
  Scaleform::GFx::Movie::SetArrayType v6; // esi
  Scaleform::GFx::AS2::MovieRoot *v7; // rbx
  unsigned int v8; // er10
  Scaleform::GFx::MovieImpl *v9; // r8
  unsigned __int64 v10; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // r8
  unsigned int v13; // ecx
  __int64 v14; // rax
  Scaleform::GFx::InteractiveObject *v15; // rcx
  Scaleform::GFx::AS2::Environment *v16; // r15
  Scaleform::GFx::AS2::Object *v17; // rax
  Scaleform::GFx::AS2::Object *v18; // rdi
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v19; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // rbx
  unsigned int v21; // eax
  _DWORD *v22; // rbx
  signed __int64 v23; // rsi
  __int64 v24; // r14
  Scaleform::GFx::AS2::Value *v25; // rcx
  unsigned int v26; // eax
  float *v27; // rbx
  signed __int64 v28; // rsi
  __int64 v29; // r14
  Scaleform::GFx::AS2::Value *v30; // rcx
  float v31; // xmm1_4
  unsigned int v32; // eax
  long double *v33; // rbx
  signed __int64 v34; // r14
  __int64 v35; // rsi
  Scaleform::GFx::AS2::Value *v36; // rcx
  unsigned int v37; // ecx
  signed __int64 v38; // rsi
  _QWORD *v39; // rbx
  __int64 v40; // r12
  Scaleform::GFx::ASStringNode *v41; // r13
  Scaleform::GFx::AS2::Value *v42; // r14
  __int64 v43; // rsi
  unsigned int v44; // eax
  const char **v45; // rbx
  signed __int64 v46; // rax
  Scaleform::GFx::AS2::Value *v47; // rcx
  Scaleform::GFx::ASStringNode *v48; // r14
  __int64 v49; // r12
  Scaleform::GFx::ASString *v50; // r13
  Scaleform::GFx::ASStringNode *v51; // rcx
  bool v52; // zf
  Scaleform::GFx::ASStringNode *v53; // rcx
  int v54; // er12
  __int64 v55; // rsi
  unsigned __int64 v56; // rdx
  __int64 v57; // rsi
  __int64 *v58; // r13
  Scaleform::GFx::AS2::Value *v59; // rcx
  __int64 v60; // rax
  Scaleform::GFx::AS2::Value *v61; // r12
  Scaleform::GFx::ASStringNode *v62; // rcx
  unsigned int v63; // eax
  Scaleform::GFx::ASStringNode *v64; // rcx
  unsigned int v65; // ebx
  unsigned int v66; // eax
  Scaleform::MemoryHeapVtbl *v67; // rax
  __int64 v68; // rax
  char *v69; // rbx
  __int64 v70; // rdi
  char *v71; // r14
  unsigned int v72; // eax
  Scaleform::GFx::ASStringNode *v73; // rcx
  Scaleform::GFx::ASStringNode *v75; // rcx
  signed __int64 v76; // [rsp+18h] [rbp-39h]
  __int64 *v77; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-31h]
  Scaleform::GFx::AS2::Value *powner; // [rsp+28h] [rbp-29h]
  unsigned int excludeFlags; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v81; // [rsp+38h] [rbp-19h]
  __int64 v82; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-9h]
  __int64 v84; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::ASString v85; // [rsp+A8h] [rbp+57h]
  char *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::GFx::AS2::MovieRoot *v87; // [rsp+D0h] [rbp+7Fh]

  v87 = this;
  v84 = -2i64;
  v4 = index;
  v5 = ppathToVar;
  v6 = type;
  v7 = this;
  v8 = 0;
  v9 = this->pMovieImpl;
  v10 = v9->MovieLevels.Data.Size;
  if ( !v10 )
    return 0;
  v11 = 0i64;
  v12 = v9->MovieLevels.Data.Data;
  while ( v12[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= v10 )
      return 0;
  }
  if ( !v12[v8].pSprite.pObject )
    return 0;
  v13 = 0;
  if ( v10 )
  {
    v14 = 0i64;
    while ( v12[v14].Level )
    {
      v14 = ++v13;
      if ( v13 >= v10 )
        goto LABEL_13;
    }
    v15 = v12[v13].pSprite.pObject;
  }
  else
  {
LABEL_13:
    v15 = 0i64;
  }
  v16 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v15->vfptr + 4 * (unsigned __int8)v15->AvmObjOffset))[30].__vecDelDtor)();
  Scaleform::GFx::AS2::Environment::CreateString(v16, &result, v5);
  presult.T.Type = 0;
  excludeFlags = 0;
  powner = 0i64;
  result.pNode = 0i64;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v16, &result, &presult, 0i64)
    || presult.T.Type != 6
    || (v17 = Scaleform::GFx::AS2::Value::ToObject(&presult, v16), (v18 = v17) == 0i64)
    || (*(unsigned int (**)(void))&v17->vfptr->gap8[8])() != 7 )
  {
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    v75 = result.pNode;
    v52 = result.pNode->RefCount == 1;
    --v75->RefCount;
    if ( v52 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v75);
    return 0;
  }
  v19 = Scaleform::GFx::MovieImpl::GetRetValHolder(v7->pMovieImpl);
  v81 = v19;
  v19->StringArrayPos = 0;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v19->StringArray.Data,
    1ui64);
  v20 = v18[1].pPrev;
  switch ( v6 )
  {
    case 0:
      v21 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v21 = (unsigned int)v18[1].pPrev;
      if ( v21 )
      {
        v22 = retaddr;
        v23 = v4;
        v24 = v21;
        do
        {
          v25 = (Scaleform::GFx::AS2::Value *)(&v18[1].pRCC->vfptr)[v23];
          if ( v25 )
            *v22 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v25, v16);
          else
            *v22 = 0;
          ++v23;
          ++v22;
          --v24;
        }
        while ( v24 );
      }
      break;
    case 1:
      v32 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v32 = (unsigned int)v18[1].pPrev;
      if ( v32 )
      {
        v33 = (long double *)retaddr;
        v34 = 8 * v4 - (_QWORD)retaddr;
        v35 = v32;
        do
        {
          v36 = *(Scaleform::GFx::AS2::Value **)((char *)&v18[1].pRCC->vfptr + v34 + (unsigned __int64)v33);
          if ( v36 )
            *v33 = Scaleform::GFx::AS2::Value::ToNumber(v36, v16);
          else
            *v33 = 0.0;
          ++v33;
          --v35;
        }
        while ( v35 );
      }
      break;
    case 2:
      v26 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v26 = (unsigned int)v18[1].pPrev;
      if ( v26 )
      {
        v27 = (float *)retaddr;
        v28 = v4;
        v29 = v26;
        do
        {
          v30 = (Scaleform::GFx::AS2::Value *)(&v18[1].pRCC->vfptr)[v28];
          if ( v30 )
          {
            v31 = Scaleform::GFx::AS2::Value::ToNumber(v30, v16);
            *v27 = v31;
          }
          else
          {
            *v27 = 0.0;
          }
          ++v28;
          ++v27;
          --v29;
        }
        while ( v29 );
      }
      break;
    case 3:
      v43 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v43 = (unsigned int)v20;
      v44 = v43;
      if ( (unsigned int)v43 < 1 )
        v44 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v19->StringArray.Data,
        v44);
      if ( (_DWORD)v43 )
      {
        v45 = (const char **)retaddr;
        v46 = 8 * v4 - (_QWORD)retaddr;
        v76 = 8 * v4 - (_QWORD)retaddr;
        do
        {
          v47 = *(Scaleform::GFx::AS2::Value **)((char *)v45 + v46 + (unsigned __int64)v18[1].pRCC);
          if ( v47 )
          {
            Scaleform::GFx::AS2::Value::ToString(v47, &v85, v16, -1);
            v48 = v85.pNode;
            *v45 = v85.pNode->pData;
            v49 = v19->StringArrayPos;
            v19->StringArrayPos = v49 + 1;
            v50 = v19->StringArray.Data.Data;
            ++v48->RefCount;
            v51 = v50[v49].pNode;
            v52 = v51->RefCount-- == 1;
            if ( v52 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v51);
            v50[v49].pNode = v48;
            v53 = v85.pNode;
            v52 = v85.pNode->RefCount == 1;
            --v53->RefCount;
            if ( v52 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v53);
            v19 = v81;
          }
          else
          {
            *v45 = 0i64;
          }
          ++v45;
          --v43;
          v46 = v76;
        }
        while ( v43 );
      }
      break;
    case 4:
      v54 = 0;
      LODWORD(v85.pNode) = 0;
      v55 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v55 = (unsigned int)v20;
      excludeFlags = v55;
      v56 = (unsigned int)v55;
      if ( (unsigned int)v55 < 1 )
        v56 = 1i64;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v19->StringArray.Data,
        v56);
      if ( (_DWORD)v20 )
      {
        v57 = 0i64;
        v20 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(unsigned int)v20;
        v58 = v77;
        do
        {
          v59 = (Scaleform::GFx::AS2::Value *)(&(&v18[1].pRCC->vfptr)[v4])[v57];
          if ( v59 )
          {
            Scaleform::GFx::AS2::Value::ToString(v59, (Scaleform::GFx::ASString *)&powner, v16, -1);
            v82 = *v58;
            v60 = v82;
            v61 = powner;
            ++*((_DWORD *)&v61->NV + 6);
            v62 = *(Scaleform::GFx::ASStringNode **)(v57 * 8 + v60);
            v52 = v62->RefCount-- == 1;
            if ( v52 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v62);
              v60 = v82;
            }
            *(_QWORD *)(v57 * 8 + v60) = v61;
            v63 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&powner);
            v54 = v63 + LODWORD(v85.pNode) + 1;
            LODWORD(v85.pNode) += v63 + 1;
            v64 = (Scaleform::GFx::ASStringNode *)powner;
            v52 = *((_DWORD *)&powner->NV + 6) == 1;
            --v64->RefCount;
            if ( v52 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v64);
          }
          ++v57;
          v20 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v20 - 1);
        }
        while ( v20 );
        v19 = v81;
        v55 = excludeFlags;
      }
      v65 = (2 * v54 + 4095) & 0xFFFFF000;
      v66 = v19->CharBufferSize;
      if ( v66 < v65 || v66 > v65 && v66 - v65 > 0x1000 )
      {
        v67 = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( v19->CharBuffer )
          v68 = (__int64)v67->Realloc(Scaleform::Memory::pGlobalHeap, v19->CharBuffer, v65);
        else
          v68 = (__int64)v67->Alloc(Scaleform::Memory::pGlobalHeap, v65, 0i64);
        v19->CharBuffer = (char *)v68;
        v19->CharBufferSize = v65;
      }
      v69 = v19->CharBuffer;
      if ( (_DWORD)v55 )
      {
        v70 = 0i64;
        do
        {
          v85.pNode = **(Scaleform::GFx::ASStringNode ***)(v70 + *v77);
          v71 = v69;
          while ( 1 )
          {
            v72 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v85);
            if ( !v72 )
              break;
            *(_WORD *)v69 = v72;
            v69 += 2;
          }
          --v85.pNode;
          *(_WORD *)v69 = 0;
          v69 += 2;
          *(_QWORD *)&retaddr[v70] = v71;
          v70 += 8i64;
          --v55;
        }
        while ( v55 );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v19->StringArray.Data,
        1ui64);
      break;
    case 5:
      v37 = (unsigned int)v87;
      if ( (unsigned int)v20 < (unsigned int)v87 )
        v37 = (unsigned int)v18[1].pPrev;
      if ( v37 )
      {
        v38 = v4;
        v39 = retaddr + 16;
        v40 = v37;
        v41 = v85.pNode;
        do
        {
          v42 = (Scaleform::GFx::AS2::Value *)(&v18[1].pRCC->vfptr)[v38];
          if ( (*((_DWORD *)v39 + 2) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v39 + 16i64))(*v39, v39 - 2, v39[2]);
            *v39 = 0i64;
          }
          *((_DWORD *)v39 + 2) = 0;
          if ( v42 )
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
              (Scaleform::GFx::AS2::MovieRoot *)v41,
              v16,
              v42,
              (Scaleform::GFx::Value *)(v39 - 2));
          else
            *((_DWORD *)v39 + 2) = 0;
          ++v38;
          v39 += 6;
          --v40;
        }
        while ( v40 );
      }
      break;
    default:
      break;
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v73 = result.pNode;
  v52 = result.pNode->RefCount == 1;
  --v73->RefCount;
  if ( v52 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v73);
  return 1;
}

// File Line: 2141
// RVA: 0x6D9620
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::ASString *fullPath, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::Movie::SetVarType v4; // er15
  Scaleform::GFx::AS2::Value *v5; // r12
  Scaleform::GFx::AS2::MovieRoot *v6; // r14
  Scaleform::GFx::AS2::GlobalContext *v7; // rdi
  bool v8; // al
  Scaleform::GFx::ASStringNode *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rdi
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rax
  int v14; // eax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rsi
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rdi
  Scaleform::GFx::ASStringNode *v21; // rcx
  void *v22; // rdi
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString pvar; // [rsp+20h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+30h] [rbp-20h]
  __int64 v27; // [rsp+40h] [rbp-10h]
  Scaleform::GFx::ASString ppath; // [rsp+80h] [rbp+30h]

  v27 = -2i64;
  v4 = setType;
  v5 = val;
  v6 = this;
  v7 = this->pGlobalContext.pObject;
  psc.pContext = v7;
  psc.SWFVersion = 8;
  ppath.pNode = *(Scaleform::GFx::ASStringNode **)&v7->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++ppath.pNode->RefCount;
  pvar.pNode = *(Scaleform::GFx::ASStringNode **)&v7->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++pvar.pNode->RefCount;
  v8 = Scaleform::GFx::AS2::Environment::ParsePath(&psc, fullPath, &ppath, &pvar);
  v9 = pvar.pNode;
  if ( v8 )
  {
    v13 = ppath.pNode;
    if ( ppath.pNode->Size < 5 )
      goto LABEL_33;
    if ( *(_DWORD *)ppath.pNode->pData == *(_DWORD *)aRoo && *((_BYTE *)ppath.pNode->pData + 4) == 116 )
    {
      v14 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&ppath.pNode);
      v15 = Scaleform::GFx::ASString::Substring(&ppath, (Scaleform::GFx::ASString *)&psc, 5, v14);
      v16 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&v7->pMovieRoot->pASMovieRoot.pObject[21],
              &result,
              v15)->pNode;
      ++v16->RefCount;
      v17 = ppath.pNode;
      v12 = ppath.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      ppath.pNode = v16;
      v18 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v19 = (Scaleform::GFx::ASStringNode *)psc.pContext;
      v12 = LODWORD(psc.pContext->RegisteredClasses.mHash.pTable) == 1;
      --v19->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      v13 = ppath.pNode;
    }
    v11 = (Scaleform::GFx::ASStringNode *)v13->pData;
    if ( *(_DWORD *)v13->pData != *(_DWORD *)aLev || WORD2(v11->pData) != 27749 )
    {
LABEL_33:
      v20 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&v7->pMovieRoot->pASMovieRoot.pObject[21].RefCount,
              (Scaleform::GFx::ASString *)&psc,
              &ppath)->pNode;
      ++v20->RefCount;
      v21 = ppath.pNode;
      v12 = ppath.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      ppath.pNode = v20;
      v11 = (Scaleform::GFx::ASStringNode *)psc.pContext;
      v12 = LODWORD(psc.pContext->RegisteredClasses.mHash.pTable) == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
  }
  else
  {
    if ( !pvar.pNode->Size )
      goto LABEL_27;
    v10 = (Scaleform::GFx::ASStringNode *)v7->pMovieRoot->pASMovieRoot.pObject[21].vfptr;
    ++v10->RefCount;
    v11 = ppath.pNode;
    v12 = ppath.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    ppath.pNode = v10;
  }
  psc.pContext = (Scaleform::GFx::AS2::GlobalContext *)v6->pMovieImpl->pHeap;
  v22 = psc.pContext->vfptr[10].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v11, 64u);
  result.pNode = (Scaleform::GFx::ASStringNode *)v22;
  if ( v22 )
  {
    *(_QWORD *)v22 = &Scaleform::GFx::MovieImpl::StickyVarNode::`vftable';
    *((_QWORD *)v22 + 1) = v9;
    ++v9->RefCount;
    *((_QWORD *)v22 + 2) = 0i64;
    *((_BYTE *)v22 + 24) = v4 == 2;
    *(_QWORD *)v22 = &Scaleform::GFx::AS2::MovieRoot::StickyVarNode::`vftable';
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v22 + 1, v5, (__int64)v22);
  }
  else
  {
    v22 = 0i64;
  }
  if ( v22 )
    Scaleform::GFx::MovieImpl::AddStickyVariableNode(
      v6->pMovieImpl,
      &ppath,
      (Scaleform::GFx::MovieImpl::StickyVarNode *)v22);
LABEL_27:
  v12 = v9->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v23 = ppath.pNode;
  v12 = ppath.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}

// File Line: 2207
// RVA: 0x7125F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ResolveStickyVariables(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::CharacterHandle *v2; // rax
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::MovieRoot *v4; // rdi
  Scaleform::GFx::ASString *v5; // r12
  signed __int64 v6; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  signed __int64 v10; // rax
  signed __int64 v11; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v12; // r14
  __int64 v13; // r15
  __int64 v14; // rbx
  Scaleform::GFx::MovieImpl::StickyVarNode *v15; // r12
  Scaleform::GFx::MovieImpl::StickyVarNodeVtbl *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rbp
  __int64 v18; // rax
  __int64 v19; // rdi
  Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *v20; // rcx
  Scaleform::GFx::AS2::MovieRoot *v21; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ASString *key; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::MovieImpl::StickyVarNode *v24; // [rsp+98h] [rbp+20h]

  v21 = this;
  v2 = pch->pNameHandle.pObject;
  v3 = pch;
  v4 = this;
  if ( !v2 )
    v2 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&pch->vfptr);
  v5 = &v2->NamePath;
  v6 = (signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset;
  key = &v2->NamePath;
  v7 = (Scaleform::GFx::MovieImpl::StickyVarNode *)(*(__int64 (**)(void))(*(_QWORD *)v6 + 8i64))();
  v8 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v4->pMovieImpl->StickyVariables.mHash.pTable;
  value = v7;
  v9.pTable = v8->pTable;
  if ( v8->pTable )
  {
    v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            v8,
            v5,
            v9.pTable->SizeMask & v5->pNode->HashFlags);
    if ( v10 >= 0 )
    {
      v11 = (signed __int64)v9.pTable + 8 * (3 * v10 + 3);
      if ( v11 )
      {
        v12 = 0i64;
        v13 = 0i64;
        v24 = *(Scaleform::GFx::MovieImpl::StickyVarNode **)(v11 + 8);
        v14 = (__int64)v24;
        if ( v24 )
        {
          v15 = value;
          do
          {
            v16 = v15->vfptr;
            v17 = v15->Name.pNode;
            LOBYTE(value) = 0;
            v18 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl::StickyVarNode *))v16[15].__vecDelDtor)(v15);
            (*(void (__fastcall **)(Scaleform::GFx::ASString *, __int64, __int64, __int64, Scaleform::GFx::MovieImpl::StickyVarNode **))&v17->RefCount)(
              &v15->Name,
              v18,
              v14 + 8,
              v14 + 32,
              &value);
            v19 = *(_QWORD *)(v14 + 16);
            if ( *(_BYTE *)(v14 + 24) )
            {
              if ( v12 )
                *(_QWORD *)(v13 + 16) = v14;
              else
                v12 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v14;
              v13 = v14;
              *(_QWORD *)(v14 + 16) = 0i64;
            }
            else
            {
              (**(void (__fastcall ***)(__int64, signed __int64))v14)(v14, 1i64);
            }
            v14 = v19;
          }
          while ( v19 );
          v5 = key;
          if ( v12 )
          {
            if ( v12 != v24 )
            {
              v20 = (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::All)v21->pMovieImpl;
              value = v12;
              Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
                v20 + 2441,
                key,
                &value);
            }
            return;
          }
          v4 = v21;
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v4->pMovieImpl->StickyVariables.mHash.pTable,
          v5);
        return;
      }
    }
  }
}

// File Line: 2270
// RVA: 0x6EB5A0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::MovieRoot::FindTarget(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::ASString *path)
{
  Scaleform::GFx::MovieImpl *v2; // r10
  Scaleform::GFx::InteractiveObject *v3; // r11
  Scaleform::GFx::ASString *v4; // rbx
  unsigned __int64 v5; // r9
  unsigned int v6; // er8
  Scaleform::GFx::MovieImpl::LevelInfo *v7; // r10
  __int64 v8; // rax
  unsigned int v10; // ecx
  __int64 v11; // rax
  Scaleform::GFx::AS2::Environment *v12; // rax

  v2 = this->pMovieImpl;
  v3 = 0i64;
  v4 = path;
  v5 = v2->MovieLevels.Data.Size;
  v6 = 0;
  if ( !v5 )
    return 0i64;
  v7 = v2->MovieLevels.Data.Data;
  v8 = 0i64;
  while ( v7[v8].Level )
  {
    v8 = ++v6;
    if ( v6 >= v5 )
      return 0i64;
  }
  if ( !v7[v6].pSprite.pObject || !path->pNode->Size )
    return 0i64;
  v10 = 0;
  if ( v5 )
  {
    v11 = 0i64;
    while ( v7[v11].Level )
    {
      v11 = ++v10;
      if ( v10 >= v5 )
        goto LABEL_14;
    }
    v3 = v7[v10].pSprite.pObject;
  }
LABEL_14:
  v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * (unsigned __int8)v3->AvmObjOffset))[30].__vecDelDtor)((signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset);
  return Scaleform::GFx::AS2::Environment::FindTarget(v12, v4, 0);
}

// File Line: 2301
// RVA: 0x704860
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyOnResize(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::MovieImpl *v1; // r9
  unsigned int v2; // edx
  Scaleform::GFx::AS2::MovieRoot *v3; // rbx
  unsigned __int64 v4; // r8
  Scaleform::GFx::MovieImpl::LevelInfo *v5; // r9
  __int64 v6; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v7; // rdi
  Scaleform::GFx::MovieImpl *v8; // rbx
  unsigned int v9; // edx
  unsigned __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rbx
  __int64 v12; // rcx
  Scaleform::GFx::InteractiveObject *v13; // rbx
  Scaleform::RefCountNTSImpl *v14; // rcx
  Scaleform::RefCountNTSImpl *v15; // rcx

  v1 = this->pMovieImpl;
  v2 = 0;
  v3 = this;
  v4 = v1->MovieLevels.Data.Size;
  if ( v4 )
  {
    v5 = v1->MovieLevels.Data.Data;
    v6 = 0i64;
    while ( v5[v6].Level )
    {
      v6 = ++v2;
      if ( v2 >= v4 )
        return;
    }
    if ( v5[v2].pSprite.pObject )
    {
      v7 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(&this->ActionQueue, AP_Frame);
      if ( v7 )
      {
        v8 = v3->pMovieImpl;
        v9 = 0;
        v10 = v8->MovieLevels.Data.Size;
        if ( v10 )
        {
          v11 = v8->MovieLevels.Data.Data;
          v12 = 0i64;
          while ( v11[v12].Level )
          {
            v12 = ++v9;
            if ( v9 >= v10 )
              goto LABEL_12;
          }
          v13 = v11[v9].pSprite.pObject;
        }
        else
        {
LABEL_12:
          v13 = 0i64;
        }
        v7->Type = 4;
        if ( v13 )
          ++v13->RefCount;
        v14 = (Scaleform::RefCountNTSImpl *)&v7->pCharacter.pObject->vfptr;
        if ( v14 )
          Scaleform::RefCountNTSImpl::Release(v14);
        v7->pCharacter.pObject = v13;
        v15 = (Scaleform::RefCountNTSImpl *)&v7->pActionBuffer.pObject->vfptr;
        if ( v15 )
          Scaleform::RefCountNTSImpl::Release(v15);
        v7->pActionBuffer.pObject = 0i64;
        v7->CFunction = Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize;
      }
    }
  }
}

// File Line: 2313
// RVA: 0x7002B0
char __fastcall Scaleform::GFx::AS2::MovieRoot::IsAvailable(Scaleform::GFx::AS2::MovieRoot *this, const char *pathToVar)
{
  const char *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // r11
  unsigned int v4; // er8
  Scaleform::GFx::MovieImpl *v5; // r10
  unsigned __int64 v6; // r9
  __int64 v7; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v8; // r10
  unsigned int v9; // ecx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  Scaleform::GFx::AS2::Environment *v12; // rbx
  char v13; // bl
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = pathToVar;
  v3 = 0i64;
  v4 = 0;
  v5 = this->pMovieImpl;
  v6 = v5->MovieLevels.Data.Size;
  if ( !v6 )
    return 0;
  v7 = 0i64;
  v8 = v5->MovieLevels.Data.Data;
  while ( v8[v7].Level )
  {
    v7 = ++v4;
    if ( v4 >= v6 )
      return 0;
  }
  if ( !v8[v4].pSprite.pObject )
    return 0;
  v9 = 0;
  if ( v6 )
  {
    v10 = 0i64;
    while ( v8[v10].Level )
    {
      v10 = ++v9;
      if ( v9 >= v6 )
        goto LABEL_13;
    }
    v3 = v8[v9].pSprite.pObject;
  }
LABEL_13:
  v11 = (signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset;
  v12 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v11 + 240i64))(v11);
  Scaleform::GFx::AS2::Environment::CreateString(v12, &result, v2);
  v13 = Scaleform::GFx::AS2::Environment::IsAvailable(v12, &result, 0i64);
  v14 = result.pNode;
  v15 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  return v13;
}

// File Line: 2325
// RVA: 0x6FEF20
__int64 __fastcall Scaleform::GFx::AS2::MovieRoot::Invoke(Scaleform::GFx::AS2::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, Scaleform::GFx::Value *pargs, unsigned int numArgs)
{
  Scaleform::GFx::MovieImpl *v5; // r11
  const char *v6; // rdi
  Scaleform::GFx::InteractiveObject *v7; // rdx
  unsigned __int64 v8; // rbx
  unsigned int v9; // er10
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // r11
  __int64 v11; // rax
  unsigned int v12; // ST28_4

  v5 = this->pMovieImpl;
  v6 = pmethodName;
  v7 = 0i64;
  v8 = v5->MovieLevels.Data.Size;
  v9 = 0;
  if ( v8 )
  {
    v10 = v5->MovieLevels.Data.Data;
    v11 = 0i64;
    while ( v10[v11].Level )
    {
      v11 = ++v9;
      if ( v9 >= v8 )
        goto LABEL_7;
    }
    v7 = v10[v9].pSprite.pObject;
  }
LABEL_7:
  v12 = numArgs;
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::InteractiveObject *, const char *, Scaleform::GFx::Value *, Scaleform::GFx::Value *, unsigned int))this->vfptr[61].__vecDelDtor)(
           this,
           v7,
           v6,
           presult,
           pargs,
           v12);
}

// File Line: 2332
// RVA: 0x6FEB30
char __fastcall Scaleform::GFx::AS2::MovieRoot::Invoke(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *thisCont, const char *pmethodName, Scaleform::GFx::Value *presult, Scaleform::GFx::Value *pargs, unsigned int numArgs)
{
  const char *v6; // r12
  Scaleform::GFx::InteractiveObject *v7; // rbx
  Scaleform::GFx::AS2::MovieRoot *v8; // r14
  signed __int64 v9; // r15
  Scaleform::GFx::AS2::Environment *v10; // r13
  unsigned int v11; // ebp
  signed int v12; // esi
  Scaleform::GFx::Value *v13; // rdi
  Scaleform::GFx::AS2::Value *v14; // rcx
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v15; // rax
  char v16; // di
  Scaleform::RefCountNTSImpl *v17; // rbx
  int firstArgBottomIndex; // ST28_4
  Scaleform::GFx::AS2::Value *v19; // rcx
  Scaleform::GFx::AS2::Value presulta; // [rsp+40h] [rbp-78h]
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+60h] [rbp-58h]
  Scaleform::GFx::Value *v23; // [rsp+D8h] [rbp+20h]

  v23 = presult;
  v6 = pmethodName;
  v7 = thisCont;
  v8 = this;
  if ( !thisCont
    || ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))thisCont->vfptr[81].__vecDelDtor)(thisCont) != 3 )
  {
    return 0;
  }
  presulta.T.Type = 0;
  v9 = (signed __int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v9 + 240i64))((signed __int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset);
  v11 = numArgs;
  v12 = numArgs - 1;
  if ( (signed int)(numArgs - 1) >= 0 )
  {
    v13 = &pargs[v12];
    do
    {
      pdestVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v8, v13, &pdestVal);
      ++v10->Stack.pCurrent;
      if ( v10->Stack.pCurrent >= v10->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
      v14 = v10->Stack.pCurrent;
      if ( v14 )
        Scaleform::GFx::AS2::Value::Value(v14, &pdestVal, (__int64)v13);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  if ( v8->pInvokeAliases && (v15 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(v8, v6)) != 0i64 )
  {
    v16 = Scaleform::GFx::AS2::MovieRoot::InvokeAlias(v8, v6, v15, &presulta, numArgs);
  }
  else
  {
    v17 = *(Scaleform::RefCountNTSImpl **)(v9 + 24);
    if ( v17 )
      ++v17->RefCount;
    firstArgBottomIndex = 32 * *(unsigned __int64 *)(v9 + 96)
                        - 32
                        + ((*(_QWORD *)(v9 + 56) - *(_QWORD *)(v9 + 64)) >> 5);
    v16 = Scaleform::GFx::AS2::GAS_Invoke(
            v6,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)(v9 + 8),
            (Scaleform::GFx::AS2::Environment *)(v9 + 48));
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
  }
  if ( numArgs )
  {
    do
    {
      v19 = v10->Stack.pCurrent;
      if ( v19->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v19);
      --v10->Stack.pCurrent;
      if ( v10->Stack.pCurrent < v10->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v10->Stack);
      --v11;
    }
    while ( v11 );
  }
  if ( v16 && v23 )
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v8, v10, &presulta, v23);
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v16;
}

// File Line: 2374
// RVA: 0x6FED40
char Scaleform::GFx::AS2::MovieRoot::Invoke(Scaleform::GFx::AS2::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt, ...)
{
  Scaleform::GFx::Value *v4; // r14
  const char *v5; // rsi
  Scaleform::GFx::AS2::MovieRoot *v6; // rbp
  __int64 v7; // rdi
  unsigned int v8; // er9
  Scaleform::GFx::MovieImpl *v9; // r10
  unsigned __int64 v10; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // r10
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v13; // rax
  char v14; // si
  __int64 v15; // r9
  unsigned int v16; // ecx
  Scaleform::GFx::MovieImpl *v17; // r8
  unsigned __int64 v18; // rdx
  __int64 v19; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v20; // r8
  Scaleform::GFx::InteractiveObject *v21; // rcx
  __int64 v22; // rax
  Scaleform::RefCountNTSImpl *v23; // rbx
  unsigned int v24; // ecx
  Scaleform::GFx::MovieImpl *v25; // r8
  unsigned __int64 v26; // rdx
  __int64 v27; // rax
  signed __int64 v28; // rcx
  Scaleform::GFx::AS2::Environment *v29; // rax
  Scaleform::GFx::AS2::Value presulta; // [rsp+40h] [rbp-58h]
  char *pmethodArgFmt; // [rsp+B8h] [rbp+20h]
  va_list va; // [rsp+C0h] [rbp+28h]

  va_start(va, pargFmt);
  pmethodArgFmt = (char *)pargFmt;
  v4 = presult;
  v5 = pmethodName;
  v6 = this;
  v7 = 0i64;
  v8 = 0;
  v9 = this->pMovieImpl;
  v10 = v9->MovieLevels.Data.Size;
  if ( !v10 )
    return 0;
  v11 = 0i64;
  v12 = v9->MovieLevels.Data.Data;
  while ( v12[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= v10 )
      return 0;
  }
  if ( !v12[v8].pSprite.pObject )
    return 0;
  presulta.T.Type = 0;
  if ( this->pInvokeAliases && (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) != 0i64 )
  {
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(v6, v5, v13, &presulta, pmethodArgFmt, va);
  }
  else
  {
    v16 = 0;
    v17 = v6->pMovieImpl;
    v18 = v17->MovieLevels.Data.Size;
    if ( v18 )
    {
      v19 = 0i64;
      v20 = v17->MovieLevels.Data.Data;
      while ( v20[v19].Level )
      {
        v19 = ++v16;
        if ( v16 >= v18 )
          goto LABEL_16;
      }
      v21 = v20[v16].pSprite.pObject;
    }
    else
    {
LABEL_16:
      v21 = 0i64;
    }
    v22 = (unsigned __int8)v21->AvmObjOffset;
    v23 = *(Scaleform::RefCountNTSImpl **)((char *)&v21->vfptr + 4 * v22);
    if ( v23 )
      ++v23->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            v5,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)((char *)v21 + 4 * (v22 + 2)),
            (Scaleform::GFx::AS2::Environment *)((char *)v21 + 4 * (v22 + 12)));
    if ( v23 )
      Scaleform::RefCountNTSImpl::Release(v23);
  }
  if ( v14 && v4 )
  {
    v24 = 0;
    v25 = v6->pMovieImpl;
    v26 = v25->MovieLevels.Data.Size;
    if ( v26 )
    {
      v27 = 0i64;
      v25 = (Scaleform::GFx::MovieImpl *)v25->MovieLevels.Data.Data;
      while ( LODWORD((&v25->vfptr)[2 * v27]) )
      {
        v27 = ++v24;
        if ( v24 >= v26 )
          goto LABEL_29;
      }
      v7 = *((_QWORD *)&v25->RefCount + 2 * v24);
    }
LABEL_29:
    v28 = v7 + 4i64 * *(unsigned __int8 *)(v7 + 109);
    v29 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, unsigned __int64, Scaleform::GFx::MovieImpl *, __int64))(*(_QWORD *)v28 + 240i64))(
                                                v28,
                                                v26,
                                                v25,
                                                v15);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v6, v29, &presulta, v4);
  }
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v14;
}

// File Line: 2405
// RVA: 0x6FF4C0
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeArgs(Scaleform::GFx::AS2::MovieRoot *this, const char *pmethodName, Scaleform::GFx::Value *presult, const char *pargFmt)
{
  Scaleform::GFx::Value *v4; // r15
  const char *v5; // rsi
  Scaleform::GFx::AS2::MovieRoot *v6; // rbp
  __int64 v7; // rdi
  unsigned int v8; // er10
  Scaleform::GFx::MovieImpl *v9; // r9
  unsigned __int64 v10; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // r9
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v13; // rax
  char v14; // si
  unsigned int v15; // ecx
  Scaleform::GFx::MovieImpl *v16; // r8
  unsigned __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // r8
  Scaleform::GFx::InteractiveObject *v20; // rcx
  __int64 v21; // rax
  Scaleform::RefCountNTSImpl *v22; // rbx
  unsigned int v23; // ecx
  Scaleform::GFx::MovieImpl *v24; // r8
  unsigned __int64 v25; // rdx
  __int64 v26; // rax
  signed __int64 v27; // rcx
  Scaleform::GFx::AS2::Environment *v28; // rax
  Scaleform::GFx::AS2::Value presulta; // [rsp+38h] [rbp-40h]

  v4 = presult;
  v5 = pmethodName;
  v6 = this;
  v7 = 0i64;
  v8 = 0;
  v9 = this->pMovieImpl;
  v10 = v9->MovieLevels.Data.Size;
  if ( !v10 )
    return 0;
  v11 = 0i64;
  v12 = v9->MovieLevels.Data.Data;
  while ( v12[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= v10 )
      return 0;
  }
  if ( !v12[v8].pSprite.pObject )
    return 0;
  presulta.T.Type = 0;
  if ( this->pInvokeAliases && (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) != 0i64 )
  {
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(v6, v5, v13, &presulta);
  }
  else
  {
    v15 = 0;
    v16 = v6->pMovieImpl;
    v17 = v16->MovieLevels.Data.Size;
    if ( v17 )
    {
      v18 = 0i64;
      v19 = v16->MovieLevels.Data.Data;
      while ( v19[v18].Level )
      {
        v18 = ++v15;
        if ( v15 >= v17 )
          goto LABEL_16;
      }
      v20 = v19[v15].pSprite.pObject;
    }
    else
    {
LABEL_16:
      v20 = 0i64;
    }
    v21 = (unsigned __int8)v20->AvmObjOffset;
    v22 = *(Scaleform::RefCountNTSImpl **)((char *)&v20->vfptr + 4 * v21);
    if ( v22 )
      ++v22->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            v5,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)((char *)v20 + 4 * (v21 + 2)),
            (Scaleform::GFx::AS2::Environment *)((char *)v20 + 4 * (v21 + 12)));
    if ( v22 )
      Scaleform::RefCountNTSImpl::Release(v22);
  }
  if ( v14 && v4 )
  {
    v23 = 0;
    v24 = v6->pMovieImpl;
    v25 = v24->MovieLevels.Data.Size;
    if ( v25 )
    {
      v26 = 0i64;
      v24 = (Scaleform::GFx::MovieImpl *)v24->MovieLevels.Data.Data;
      while ( LODWORD((&v24->vfptr)[2 * v26]) )
      {
        v26 = ++v23;
        if ( v23 >= v25 )
          goto LABEL_29;
      }
      v7 = *((_QWORD *)&v24->RefCount + 2 * v23);
    }
LABEL_29:
    v27 = v7 + 4i64 * *(unsigned __int8 *)(v7 + 109);
    v28 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64, unsigned __int64, Scaleform::GFx::MovieImpl *))(*(_QWORD *)v27 + 240i64))(
                                                v27,
                                                v25,
                                                v24);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v6, v28, &presulta, v4);
  }
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v14;
}

// File Line: 2433
// RVA: 0x714610
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetExternalInterfaceRetVal(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::Value *retVal)
{
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, retVal, &this->ExternalIntfRetVal);
}

// File Line: 2438
// RVA: 0x703800
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyMouseEvent(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InputEventsQueueEntry *qe, Scaleform::GFx::MouseState *ms, int mi)
{
  unsigned int v4; // er12
  Scaleform::GFx::MouseState *v5; // rdi
  Scaleform::GFx::InputEventsQueueEntry *v6; // rbx
  Scaleform::GFx::AS2::MovieRoot *v7; // r15
  unsigned int v8; // edx
  Scaleform::GFx::MovieImpl *v9; // r9
  unsigned __int64 v10; // r10
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // r9
  Scaleform::GFx::InteractiveObject *v13; // rcx
  __int64 v14; // r14
  Scaleform::GFx::AS2::MouseListener *v15; // rcx
  char v16; // cl
  bool v17; // r13
  float v18; // xmm1_4
  Scaleform::GFx::InteractiveObject *v19; // rax
  Scaleform::GFx::InteractiveObject *v20; // rsi
  Scaleform::RefCountNTSImpl *v21; // rcx
  signed __int16 v22; // di
  unsigned int v23; // ebp
  Scaleform::Render::Point<float> mousePos; // [rsp+70h] [rbp+8h]

  v4 = mi;
  v5 = ms;
  v6 = qe;
  v7 = this;
  v8 = 0;
  v9 = this->pMovieImpl;
  v10 = v9->MovieLevels.Data.Size;
  if ( v10 )
  {
    v11 = 0i64;
    v12 = v9->MovieLevels.Data.Data;
    while ( v12[v11].Level )
    {
      v11 = ++v8;
      if ( v8 >= v10 )
        goto LABEL_7;
    }
    v13 = v12[v8].pSprite.pObject;
  }
  else
  {
LABEL_7:
    v13 = 0i64;
  }
  v14 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v13->vfptr
                                                                    + 4 * (unsigned __int8)v13->AvmObjOffset))[30].__vecDelDtor)();
  v15 = v7->pASMouseListener;
  if ( v15 )
  {
    if ( !((unsigned __int8 (*)(void))v15->vfptr->IsEmpty)() )
    {
      v16 = (*((_BYTE *)v5 + 76) >> 3) & 1;
      if ( v16 || v6->u.mouseEntry.ButtonsState || v6->u.mouseEntry.Flags & 0x20 )
      {
        v17 = *(_BYTE *)(*(_QWORD *)(v14 + 232) + 104i64) == 1;
        if ( v16 )
          v7->pASMouseListener->vfptr->OnMouseMove(v7->pASMouseListener, (Scaleform::GFx::AS2::Environment *)v14, v4);
        if ( v6->u.mouseEntry.Flags & 0x20 || v6->u.mouseEntry.ButtonsState )
        {
          v18 = v6->u.mouseEntry.PosY;
          mousePos.x = v6->u.mouseEntry.PosX;
          mousePos.y = v18;
          v19 = Scaleform::GFx::MovieImpl::GetTopMostEntity(v7->pMovieImpl, &mousePos, v4, 1, 0i64);
          v20 = v19;
          if ( v19 )
            ++v19->RefCount;
          if ( v19 && v19->pASRoot->AVMVersion != 1 )
          {
            v21 = (Scaleform::RefCountNTSImpl *)&v19->vfptr;
LABEL_35:
            Scaleform::RefCountNTSImpl::Release(v21);
            return;
          }
          if ( v6->u.mouseEntry.Flags & 0x20 )
            v7->pASMouseListener->vfptr->OnMouseWheel(
              v7->pASMouseListener,
              (Scaleform::GFx::AS2::Environment *)v14,
              v4,
              v6->u.mouseEntry.WheelScrollDelta,
              v19);
          if ( v6->u.mouseEntry.ButtonsState )
          {
            v22 = 1;
            v23 = 1;
            do
            {
              if ( v6->u.mouseEntry.ButtonsState & (unsigned __int16)v22 )
              {
                if ( v6->u.mouseEntry.Flags & 0xC0 || !v6->u.mouseEntry.ButtonsState )
                  v7->pASMouseListener->vfptr->OnMouseUp(
                    v7->pASMouseListener,
                    (Scaleform::GFx::AS2::Environment *)v14,
                    v4,
                    v23,
                    v20);
                else
                  v7->pASMouseListener->vfptr->OnMouseDown(
                    v7->pASMouseListener,
                    (Scaleform::GFx::AS2::Environment *)v14,
                    v4,
                    v23,
                    v20);
              }
              if ( !v17 )
                break;
              v22 *= 2;
              ++v23;
            }
            while ( v22 );
          }
          if ( v20 )
          {
            v21 = (Scaleform::RefCountNTSImpl *)&v20->vfptr;
            goto LABEL_35;
          }
        }
      }
    }
  }
}21 = (Scaleform::RefCountNTSImpl *)&v20->vfptr;
            goto LABEL_35;
      

// File Line: 2477
// RVA: 0x703C40
bool __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyOnFocusChange(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *curFocused, Scaleform::GFx::InteractiveObject *newFocus, __int64 __formal, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::InteractiveObject *v5; // rbx
  Scaleform::GFx::InteractiveObject *v6; // r8

  v5 = newFocus;
  v6 = curFocused;
  return fmt != 1
      || curFocused
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64, Scaleform::GFx::InteractiveObject *, __int64))curFocused->vfptr[89].__vecDelDtor)(
           curFocused,
           1i64,
           curFocused,
           __formal)
      || v5
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, signed __int64, Scaleform::GFx::InteractiveObject *, __int64))v5->vfptr[89].__vecDelDtor)(
           v5,
           1i64,
           v6,
           __formal);
}

// File Line: 2490
// RVA: 0x6DC550
void __fastcall Scaleform::GFx::AS2::MovieRoot::ChangeMouseCursorType(Scaleform::GFx::AS2::MovieRoot *this, unsigned int mouseIdx, unsigned int newCursorType)
{
  int v3; // er14
  __int64 v4; // rdi
  Scaleform::GFx::AS2::MovieRoot *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::MovieImpl *v7; // r8
  unsigned __int64 v8; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v10; // r8
  Scaleform::GFx::InteractiveObject *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS2::Environment *v13; // rsi
  Scaleform::GFx::MovieImpl *v14; // rdx
  Scaleform::GFx::AS2::Object *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  signed int v18; // edi
  __int64 v19; // rax
  Scaleform::GFx::AS2::Value *v20; // rcx
  Scaleform::GFx::AS2::Value *v21; // rcx
  Scaleform::GFx::AS2::Value *v22; // rcx
  char v23; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // rcx
  int v25; // edx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::UserEventHandler *v28; // rcx
  char FirstIn; // [rsp+28h] [rbp-79h]
  Scaleform::GFx::AS2::Value ThisIn; // [rsp+30h] [rbp-71h]
  Scaleform::GFx::AS2::Value v31; // [rsp+50h] [rbp-51h]
  Scaleform::GFx::AS2::Value ResIn; // [rsp+70h] [rbp-31h]
  __int64 v33; // [rsp+90h] [rbp-11h]
  Scaleform::GFx::AS2::FnCall v34; // [rsp+98h] [rbp-9h]
  __int64 v35; // [rsp+108h] [rbp+67h]

  v33 = -2i64;
  v3 = newCursorType;
  v4 = mouseIdx;
  v5 = this;
  v6 = 0;
  v7 = this->pMovieImpl;
  v8 = v7->MovieLevels.Data.Size;
  if ( v8 )
  {
    v9 = 0i64;
    v10 = v7->MovieLevels.Data.Data;
    while ( v10[v9].Level )
    {
      v9 = ++v6;
      if ( v6 >= v8 )
        goto LABEL_7;
    }
    v11 = v10[v6].pSprite.pObject;
  }
  else
  {
LABEL_7:
    v11 = 0i64;
  }
  v12 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v11->vfptr
                                                                    + 4 * (unsigned __int8)v11->AvmObjOffset))[30].__vecDelDtor)();
  v13 = (Scaleform::GFx::AS2::Environment *)v12;
  v14 = v5->pMovieImpl;
  if ( (v14->Flags >> 12) & 1 && *(_BYTE *)(*(_QWORD *)(v12 + 232) + 104i64) == 1 )
  {
    ThisIn.T.Type = 0;
    if ( (*(unsigned __int8 (__fastcall **)(signed __int64, __int64, signed __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 232) + 96i64) + 32i64) + 88i64))(
           *(_QWORD *)(*(_QWORD *)(v12 + 232) + 96i64) + 32i64,
           v12 + 232,
           *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 232) + 40i64) + 24i64) + 528i64,
           &ThisIn) )
    {
      v15 = Scaleform::GFx::AS2::Value::ToObject(&ThisIn, v13);
      if ( v15 )
      {
        v31.T.Type = 0;
        if ( v15->vfptr->GetMember(
               (Scaleform::GFx::AS2::ObjectInterface *)&v15->vfptr,
               v13,
               (Scaleform::GFx::ASString *)&v13->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[35],
               &v31) )
        {
          Scaleform::GFx::AS2::Value::ToFunction(&v31, (Scaleform::GFx::AS2::FunctionRef *)&ThisIn, v13);
          if ( *(_QWORD *)&ThisIn.T.Type )
          {
            ResIn.T.Type = 0;
            ++v13->Stack.pCurrent;
            if ( v13->Stack.pCurrent >= v13->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v13->Stack);
            v16 = (__int64)v13->Stack.pCurrent;
            v35 = v16;
            if ( v16 )
            {
              *(_BYTE *)v16 = 3;
              *(double *)(v16 + 8) = (double)(signed int)v4;
            }
            ++v13->Stack.pCurrent;
            if ( v13->Stack.pCurrent >= v13->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v13->Stack);
            v17 = (__int64)v13->Stack.pCurrent;
            v35 = v17;
            if ( v17 )
            {
              *(_BYTE *)v17 = 3;
              *(double *)(v17 + 8) = (double)v3;
            }
            v18 = 2;
            Scaleform::GFx::AS2::FnCall::FnCall(
              &v34,
              &ResIn,
              &ThisIn,
              v13,
              2,
              32 * v13->Stack.Pages.Data.Size
            - 32
            + ((_QWORD)((char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart) >> 5));
            (*(void (__fastcall **)(_QWORD, __int64, Scaleform::GFx::ASStringNode *, _QWORD))(**(_QWORD **)&ThisIn.T.Type
                                                                                            + 80i64))(
              *(_QWORD *)&ThisIn.T.Type,
              v19,
              ThisIn.V.pStringNode,
              0i64);
            Scaleform::GFx::AS2::FnCall::~FnCall(&v34);
            v20 = v13->Stack.pCurrent;
            if ( &v20[-2] >= v13->Stack.pPageStart )
            {
              if ( v20->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v20);
              --v13->Stack.pCurrent;
              v22 = v13->Stack.pCurrent;
              if ( v22->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v22);
              --v13->Stack.pCurrent;
            }
            else
            {
              do
              {
                v21 = v13->Stack.pCurrent;
                if ( v21->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v21);
                --v13->Stack.pCurrent;
                if ( v13->Stack.pCurrent < v13->Stack.pPageStart )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v13->Stack);
                --v18;
              }
              while ( v18 );
            }
            if ( ResIn.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
          }
          v23 = FirstIn;
          if ( !(FirstIn & 2) )
          {
            v24 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&ThisIn.T.Type;
            if ( *(_QWORD *)&ThisIn.T.Type )
            {
              v25 = *(_DWORD *)(*(_QWORD *)&ThisIn.T.Type + 24i64);
              if ( v25 & 0x3FFFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&ThisIn.T.Type + 24i64) = v25 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
                v23 = FirstIn;
              }
            }
          }
          *(_QWORD *)&ThisIn.T.Type = 0i64;
          if ( !(v23 & 1) )
          {
            v26 = ThisIn.V.pStringNode;
            if ( ThisIn.V.pStringNode )
            {
              v27 = ThisIn.V.pStringNode->RefCount;
              if ( v27 & 0x3FFFFFF )
              {
                ThisIn.V.pStringNode->RefCount = v27 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v26);
              }
            }
          }
          ThisIn.V.pStringNode = 0i64;
        }
        if ( v31.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v31);
      }
    }
    if ( ThisIn.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ThisIn);
  }
  else if ( v3 != v14->mMouseState[v4].CursorType )
  {
    v28 = v14->pUserEventHandler.pObject;
    if ( v28 )
    {
      *((_BYTE *)&ThisIn.NV.0 + 4) = 0;
      *(_DWORD *)&ThisIn.T.Type = 23;
      ThisIn.NV.Int32Value = v3;
      ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::AS2::Value *))v28->vfptr[1].__vecDelDtor)(
        v28,
        v14,
        &ThisIn);
    }
  }
}

// File Line: 2535
// RVA: 0x704BC0
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyQueueSetFocus(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *ch, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl *v4; // rcx
  Scaleform::GFx::InteractiveObject *v5; // rbx
  Scaleform::GFx::FocusMovedType v6; // edi
  unsigned __int64 v7; // r11
  unsigned int v8; // esi
  Scaleform::GFx::InteractiveObject *v9; // rbp
  unsigned int v10; // er10
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS2::Environment *v13; // rax

  v4 = this->pMovieImpl;
  v5 = 0i64;
  v6 = fmt;
  v7 = v4->MovieLevels.Data.Size;
  v8 = controllerIdx;
  v9 = ch;
  v10 = 0;
  if ( v7 )
  {
    v11 = v4->MovieLevels.Data.Data;
    v12 = 0i64;
    while ( v11[v12].Level )
    {
      v12 = ++v10;
      if ( v10 >= v7 )
        goto LABEL_7;
    }
    v5 = v11[v10].pSprite.pObject;
  }
LABEL_7:
  v13 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * (unsigned __int8)v5->AvmObjOffset))[30].__vecDelDtor)((signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset);
  Scaleform::GFx::AS2::Selection::QueueSetFocus(v13, v9, v8, v6);
}

// File Line: 2541
// RVA: 0x704C50
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyTransferFocus(Scaleform::GFx::AS2::MovieRoot *this, Scaleform::GFx::InteractiveObject *curFocused, Scaleform::GFx::InteractiveObject *pNewFocus, unsigned int controllerIdx)
{
  Scaleform::GFx::MovieImpl *v4; // rcx
  Scaleform::GFx::InteractiveObject *v5; // rbx
  unsigned int v6; // edi
  unsigned __int64 v7; // r11
  Scaleform::GFx::InteractiveObject *v8; // rsi
  Scaleform::GFx::InteractiveObject *v9; // rbp
  unsigned int v10; // er10
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS2::Environment *v13; // rax

  v4 = this->pMovieImpl;
  v5 = 0i64;
  v6 = controllerIdx;
  v7 = v4->MovieLevels.Data.Size;
  v8 = pNewFocus;
  v9 = curFocused;
  v10 = 0;
  if ( v7 )
  {
    v11 = v4->MovieLevels.Data.Data;
    v12 = 0i64;
    while ( v11[v12].Level )
    {
      v12 = ++v10;
      if ( v10 >= v7 )
        goto LABEL_7;
    }
    v5 = v11[v10].pSprite.pObject;
  }
LABEL_7:
  v13 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * (unsigned __int8)v5->AvmObjOffset))[30].__vecDelDtor)((signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset);
  Scaleform::GFx::AS2::Selection::BroadcastOnSetFocus(v13, v9, v8, v6);
}

// File Line: 2551
// RVA: 0x6C8B10
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this, Scaleform::GFx::LoadQueueEntry *pqueueEntry, Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadQueueEntry *v3; // r15
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *v4; // rsi
  Scaleform::GFx::MoviePreloadTask *v5; // rdi
  _BOOL8 v6; // rbp
  Scaleform::GFx::LoadQueueEntry *v7; // r14
  Scaleform::GFx::CharacterHandle *v8; // rcx
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::RefCountNTSImpl *v10; // rbx
  __int64 v11; // rax
  int v12; // er9
  unsigned int v13; // edx
  Scaleform::GFx::MovieImpl *v14; // r10
  unsigned __int64 v15; // rcx
  __int64 v16; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v17; // r8
  unsigned int v18; // edx
  __int64 v19; // rax
  unsigned int v20; // edx
  __int64 v21; // rax
  __int64 v22; // rax
  Scaleform::GFx::InteractiveObject *v23; // rcx
  __int64 v24; // rax
  Scaleform::GFx::TaskManager *v25; // rax
  Scaleform::GFx::MoviePreloadTask *v26; // rax
  Scaleform::Render::RenderBuffer *v27; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v28; // rax
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+88h] [rbp+20h]

  v3 = pqueueEntry;
  v4 = this;
  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
    (Scaleform::GFx::LoadQueueEntryMT *)&this->vfptr,
    pqueueEntry,
    pmovieRoot);
  v4->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::`vftable';
  v5 = 0i64;
  v4->pPreloadTask.pObject = 0i64;
  v4->pNewChar.pObject = 0i64;
  v4->pOldChar.pObject = 0i64;
  v4->NewCharId.Id = 65537;
  v4->CharSwitched = 0;
  v4->BytesLoaded = 0;
  v4->FirstFrameLoaded = 0;
  LOBYTE(v6) = 0;
  v7 = v4->pQueueEntry;
  v8 = (Scaleform::GFx::CharacterHandle *)v7[1].pNext;
  if ( v8 )
  {
    v9 = (Scaleform::GFx::TaskManager *)Scaleform::GFx::CharacterHandle::ResolveCharacter(v8, v4->pMovieImpl);
    v10 = (Scaleform::RefCountNTSImpl *)v9;
    if ( v9 )
      ++v9->RefCount;
    result.pObject = v9;
    if ( v9 )
    {
      v11 = ((__int64 (__fastcall *)(Scaleform::GFx::TaskManager *))v9->vfptr[66].__vecDelDtor)(v9);
      LOBYTE(v6) = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v11 + 88i64))(v11) >> 4) & 1;
    }
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    goto LABEL_34;
  }
  v12 = (int)v7[1].vfptr;
  if ( v12 == -1 )
    goto LABEL_34;
  v13 = 0;
  v14 = v4->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  v15 = v14->MovieLevels.Data.Size;
  if ( v15 )
  {
    v16 = 0i64;
    v17 = v14->MovieLevels.Data.Data;
    while ( v17[v16].Level != v12 )
    {
      v16 = ++v13;
      if ( v13 >= v15 )
        goto LABEL_20;
    }
    if ( v17[v13].pSprite.pObject )
    {
      v18 = 0;
      if ( v15 )
      {
        v19 = 0i64;
        while ( v17[v19].Level != v12 )
        {
          v19 = ++v18;
          if ( v18 >= v15 )
            goto LABEL_32;
        }
        goto LABEL_31;
      }
      goto LABEL_32;
    }
  }
LABEL_20:
  v20 = 0;
  if ( v15 )
  {
    v21 = 0i64;
    v17 = v14->MovieLevels.Data.Data;
    while ( v17[v21].Level )
    {
      v21 = ++v20;
      if ( v20 >= v15 )
        goto LABEL_34;
    }
    if ( v17[v20].pSprite.pObject )
    {
      v18 = 0;
      if ( v15 )
      {
        v22 = 0i64;
        while ( v17[v22].Level )
        {
          v22 = ++v18;
          if ( v18 >= v15 )
            goto LABEL_32;
        }
LABEL_31:
        v23 = v17[v18].pSprite.pObject;
LABEL_33:
        v24 = ((__int64 (*)(void))v23->vfptr[66].__vecDelDtor)();
        v6 = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v24 + 88i64))(v24) >> 4) & 1;
        goto LABEL_34;
      }
LABEL_32:
      v23 = 0i64;
      goto LABEL_33;
    }
  }
LABEL_34:
  v25 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         80i64);
  result.pObject = v25;
  if ( v25 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      (Scaleform::GFx::MoviePreloadTask *)v25,
      v4->pMovieImpl,
      &v7->URL,
      v6,
      v3->QuietOpen);
    v5 = v26;
  }
  v27 = (Scaleform::Render::RenderBuffer *)v4->pPreloadTask.pObject;
  if ( v27 )
    Scaleform::RefCountImpl::Release(v27);
  v4->pPreloadTask.pObject = v5;
  v28 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &result);
  v28->pObject->vfptr[1].__vecDelDtor(
    (Scaleform::RefCountImplCore *)v28->pObject,
    (unsigned int)v4->pPreloadTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2589
// RVA: 0x701470
char __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::LoadFinished(Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this)
{
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *v1; // rsi
  char v2; // al
  Scaleform::GFx::LoadQueueEntry *v3; // r13
  Scaleform::GFx::MovieImpl *v4; // rdx
  Scaleform::GFx::AS2::MovieRoot *v5; // r15
  Scaleform::RefCountNTSImpl *v6; // rbx
  Scaleform::GFx::CharacterHandle *v7; // rcx
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::InteractiveObject *v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // rax
  Scaleform::GFx::AS2::Environment *v11; // rdi
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rdi
  Scaleform::RefCountNTSImpl *v14; // rcx
  unsigned int v15; // ecx
  Scaleform::GFx::MovieImpl *v16; // r8
  unsigned __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // r8
  Scaleform::GFx::InteractiveObject *v20; // rcx
  Scaleform::GFx::AS2::Environment *v21; // rdi
  Scaleform::GFx::AS2::Object *v22; // r14
  Scaleform::GFx::AS2::GlobalContext *v23; // rcx
  bool v24; // di
  SSExpressionBase *v25; // r12
  unsigned __int8 *v26; // r12
  Scaleform::GFx::MovieDefImpl *v27; // rax
  Scaleform::GFx::ASSupport *v28; // rcx
  Scaleform::GFx::InteractiveObject *v29; // rdi
  Scaleform::GFx::InteractiveObject *v30; // rcx
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  bool v33; // zf
  __int64 v34; // rax
  Scaleform::RefCountNTSImpl *v35; // rcx
  int v36; // edx
  Scaleform::GFx::InteractiveObject *v37; // rax
  Scaleform::GFx::InteractiveObject *v38; // rdi
  Scaleform::RefCountNTSImpl *v39; // rcx
  Scaleform::GFx::InteractiveObject *v40; // rcx
  __int64 v41; // rax
  __int64 v42; // rax
  int v43; // edx
  Scaleform::GFx::InteractiveObject *v44; // rcx
  Scaleform::GFx::LogState *v45; // rdi
  unsigned __int64 v46; // rdi
  Scaleform::GFx::LogState *v47; // r15
  Scaleform::GFx::InteractiveObject *v48; // rcx
  __int64 v49; // rax
  __int64 v50; // rax
  Scaleform::GFx::InteractiveObject *v51; // rdi
  int v52; // edx
  Scaleform::GFx::ASSupport *v53; // rcx
  Scaleform::GFx::Sprite *v54; // r15
  Scaleform::GFx::InteractiveObject *v55; // rcx
  Scaleform::GFx::ASString *v56; // rax
  Scaleform::GFx::ASStringNode *v57; // rcx
  __int64 v58; // rax
  Scaleform::RefCountNTSImpl *v59; // rcx
  __int64 v60; // rax
  __int64 v61; // rdi
  int v62; // ST20_4
  Scaleform::GFx::InteractiveObject *v63; // rcx
  __int64 v64; // rax
  __int64 v65; // rax
  int v66; // ST20_4
  int v67; // ecx
  int v68; // edx
  Scaleform::RefCountNTSImpl *v69; // rdi
  Scaleform::GFx::InteractiveObject *v70; // rax
  unsigned int v71; // edi
  unsigned int v72; // eax
  unsigned int v73; // edx
  __int64 v74; // rax
  char v75; // di
  int v76; // eax
  Scaleform::GFx::InteractiveObject *v77; // rcx
  __int64 v78; // rax
  __int64 v79; // rax
  Scaleform::GFx::InteractiveObject *v80; // r8
  int v81; // edx
  Scaleform::GFx::InteractiveObject *v82; // rax
  __int64 v83; // rax
  unsigned int v84; // ebx
  unsigned int v85; // eax
  unsigned int v86; // edx
  __int64 v87; // rax
  __int64 v88; // [rsp+20h] [rbp-79h]
  Scaleform::GFx::Sprite *v89; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::Sprite *v90; // [rsp+38h] [rbp-61h]
  Scaleform::GFx::ASString v91; // [rsp+40h] [rbp-59h]
  Scaleform::GFx::ASString v92; // [rsp+48h] [rbp-51h]
  Scaleform::Ptr<Scaleform::GFx::LogState> v93; // [rsp+50h] [rbp-49h]
  Scaleform::Ptr<Scaleform::GFx::LogState> v94; // [rsp+58h] [rbp-41h]
  Scaleform::GFx::AS2::MovieRoot *v95; // [rsp+60h] [rbp-39h]
  eSSSideEffect (__fastcall *v96)(SSExpressionBase *); // [rsp+68h] [rbp-31h]
  SSExpressionBase *v97; // [rsp+70h] [rbp-29h]
  __int64 v98; // [rsp+78h] [rbp-21h]
  __int64 v99; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::InteractiveObject *v100; // [rsp+88h] [rbp-11h]
  Scaleform::GFx::Sprite *v101; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+98h] [rbp-1h]
  bool v103; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ResourceId rid; // [rsp+108h] [rbp+6Fh]
  unsigned int v105; // [rsp+110h] [rbp+77h]
  unsigned int v106; // [rsp+118h] [rbp+7Fh]

  v99 = -2i64;
  v1 = this;
  v2 = Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
  v3 = v1->pQueueEntry;
  if ( v3->Canceled && v2 )
    return 1;
  v4 = v1->pMovieImpl;
  v5 = (Scaleform::GFx::AS2::MovieRoot *)v4->pASMovieRoot.pObject;
  v95 = (Scaleform::GFx::AS2::MovieRoot *)v4->pASMovieRoot.pObject;
  if ( !v2 )
    return v2;
  v6 = 0i64;
  if ( !v1->pOldChar.pObject )
  {
    v7 = (Scaleform::GFx::CharacterHandle *)v3[1].pNext;
    if ( v7 )
    {
      v8 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter(v7, v4);
      if ( !v8 )
      {
        v9 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v5, 0);
        if ( v9 )
        {
          v10 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v9->vfptr + 4 * (unsigned __int8)v9->AvmObjOffset))[30].__vecDelDtor)();
          v11 = v10;
          v12 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v3[1].Type, v10);
          if ( v12 )
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, _QWORD, const char *, _DWORD))v12->vfptr[4].ExecuteForEachChild_GC)(
              v12,
              v11,
              0i64,
              "Error",
              0);
        }
        return 1;
      }
      v13 = 0i64;
      if ( SLOBYTE(v8->Flags) < 0 )
        v13 = (Scaleform::GFx::InteractiveObject *)v8;
      if ( v13 )
        ++v13->RefCount;
      v14 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
      if ( v14 )
        Scaleform::RefCountNTSImpl::Release(v14);
      v1->pOldChar.pObject = v13;
      v1->NewCharId.Id = v13->Id.Id;
    }
  }
  v15 = 0;
  v16 = v5->pMovieImpl;
  v17 = v16->MovieLevels.Data.Size;
  if ( !v17 )
    return 1;
  v18 = 0i64;
  v19 = v16->MovieLevels.Data.Data;
  while ( v19[v18].Level )
  {
    v18 = ++v15;
    if ( v15 >= v17 )
      return 1;
  }
  v20 = v19[v15].pSprite.pObject;
  if ( !v20 )
    return 1;
  v21 = (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v20->vfptr + 4 * (unsigned __int8)v20->AvmObjOffset))[30].__vecDelDtor)();
  v22 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v3[1].Type, v21);
  v23 = v21->StringContext.pContext;
  v24 = v23->GFxExtensions.Value == 1;
  v103 = v23->GFxExtensions.Value == 1;
  v25 = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)v1->pPreloadTask.pObject);
  if ( v25 )
  {
    v44 = v1->pOldChar.pObject;
    if ( v44 && ((LOBYTE(v44->Flags) >> 4) & 1 || v44->Flags & 0x1000 || v44->Depth < -1) )
      return 1;
    if ( ((unsigned int (__fastcall *)(SSExpressionBase *))v25->vfptr->invoke)(v25) != -1
      && ((unsigned int (__fastcall *)(SSExpressionBase *))v25->vfptr->invoke)(v25) >= 9
      && (char)((*(_DWORD *)(*((_QWORD *)v25[13].vfptr->get_side_effect + 8) + 208i64) & 8 | 0x10u) >> 3) > 2 )
    {
      v1->pQueueEntry->Canceled = 1;
      v45 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v5->pMovieImpl->vfptr, &v94)->pObject;
      if ( v94.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v94.pObject);
      if ( v45 && !v3->QuietOpen )
      {
        v46 = v3->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
        v47 = Scaleform::GFx::StateBag::GetLogState((Scaleform::GFx::StateBag *)&v5->pMovieImpl->vfptr, &v93)->pObject;
        if ( v93.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v93.pObject);
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v47->vfptr,
          "Failed loading SWF \"%s\": ActionScript version mismatch",
          v46 + 12);
      }
      v48 = v1->pOldChar.pObject;
      if ( v48 && v22 )
      {
        v49 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v48->vfptr
                                                                          + 4 * (unsigned __int8)v48->AvmObjOffset))[1].__vecDelDtor)();
        v50 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v49 + 240i64))(v49);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v22->vfptr[4].ExecuteForEachChild_GC)(
          v22,
          v50,
          v1->pOldChar.pObject,
          "ActionScriptMismatch",
          0);
      }
      return 1;
    }
    if ( !v1->CharSwitched )
    {
      v51 = 0i64;
      v52 = (int)v3[1].vfptr;
      if ( v52 == -1 )
      {
        if ( v3[1].pNext )
        {
          v51 = v1->pOldChar.pObject->pParent;
          if ( !v51 )
            return 1;
        }
      }
      else
      {
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(v1->pMovieImpl, v52);
        v1->NewCharId.Id = 0x40000;
      }
      v96 = v25[13].vfptr->get_side_effect;
      v97 = v25;
      v98 = 0i64;
      v53 = v5->pASSupport.pObject;
      v106 = v1->NewCharId.Id;
      v54 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, eSSSideEffect (__fastcall **)(SSExpressionBase *), Scaleform::GFx::InteractiveObject *, unsigned int *))v53->vfptr[4].__vecDelDtor)(
                                        v53,
                                        v5->pMovieImpl,
                                        &v96,
                                        v51,
                                        &v106);
      v101 = v54;
      Scaleform::GFx::Sprite::SetLoadedSeparately(v54, 1);
      if ( !v103 )
        v54->Flags |= 4u;
      if ( v3[1].pNext )
      {
        Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v54->vfptr);
        v54->CreateFrame = v1->pOldChar.pObject->CreateFrame;
        v54->Depth = v1->pOldChar.pObject->Depth;
        v55 = v1->pOldChar.pObject;
        if ( !((LOBYTE(v55->Flags) >> 1) & 1) )
        {
          v56 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v55->vfptr, &v91);
          v54->vfptr[124].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v54->vfptr, (unsigned int)v56);
          v57 = v91.pNode;
          v33 = v91.pNode->RefCount == 1;
          --v57->RefCount;
          if ( v33 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v57);
        }
        if ( v51 )
          v58 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v51->vfptr
                                                                            + 4 * (unsigned __int8)v51->AvmObjOffset))[1].__vecDelDtor)();
        else
          v58 = 0i64;
        (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::Sprite *))(*(_QWORD *)v58 + 224i64))(
          v58,
          v1->pOldChar.pObject,
          v54);
        v1->pOldChar.pObject->pParent = 0i64;
      }
      else
      {
        Scaleform::GFx::AS2::AvmSprite::SetLevel(
          (Scaleform::GFx::AS2::AvmSprite *)((char *)v54 + 4 * (unsigned __int8)v54->AvmObjOffset),
          (int)v3[1].vfptr);
        Scaleform::GFx::MovieImpl::SetLevelMovie(
          v1->pMovieImpl,
          (int)v3[1].vfptr,
          (Scaleform::GFx::DisplayObjContainer *)&v54->vfptr);
        v1->pMovieImpl->Flags &= 0xFFFFFEFF;
      }
      v54->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v54->vfptr, 1u);
      ++v54->RefCount;
      v59 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
      if ( v59 )
        Scaleform::RefCountNTSImpl::Release(v59);
      v1->pOldChar.pObject = (Scaleform::GFx::InteractiveObject *)&v54->vfptr;
      if ( v22 )
      {
        if ( v54 )
          v60 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v54->vfptr
                                                                            + 4 * (unsigned __int8)v54->AvmObjOffset))[1].__vecDelDtor)();
        else
          v60 = 0i64;
        v61 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v60 + 240i64))(v60);
        v22->vfptr[3].ExecuteForEachChild_GC(
          (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v22->vfptr,
          (Scaleform::GFx::AS2::RefCountCollector<323> *)v61,
          (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v1->pOldChar.pObject);
        v1->BytesLoaded = HIDWORD(v25[13].vfptr[2].find_expr_last_no_side_effect);
        v62 = *(_DWORD *)(*((_QWORD *)v25[13].vfptr->get_side_effect + 8) + 80i64);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *))v22->vfptr[4].Finalize_GC)(
          v22,
          v61,
          v1->pOldChar.pObject);
      }
      v1->CharSwitched = 1;
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v54->vfptr);
      v5 = v95;
      v24 = v103;
    }
    if ( v1->BytesLoaded != HIDWORD(v25[13].vfptr[2].find_expr_last_no_side_effect) && v22 )
    {
      v63 = v1->pOldChar.pObject;
      if ( v63 )
        v64 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v63->vfptr
                                                                          + 4 * (unsigned __int8)v63->AvmObjOffset))[1].__vecDelDtor)();
      else
        v64 = 0i64;
      v65 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v64 + 240i64))(v64);
      v1->BytesLoaded = HIDWORD(v25[13].vfptr[2].find_expr_last_no_side_effect);
      v66 = *(_DWORD *)(*((_QWORD *)v25[13].vfptr->get_side_effect + 8) + 80i64);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *))v22->vfptr[4].Finalize_GC)(
        v22,
        v65,
        v1->pOldChar.pObject);
    }
    if ( v24 && !v1->FirstFrameLoaded )
    {
      v67 = (int)v25[13].vfptr[2].__vecDelDtor;
      if ( _bittest(&v67, 8u) )
      {
        v68 = (int)v3[1].vfptr;
        if ( v68 == -1 )
        {
          v69 = 0i64;
          if ( (v1->pOldChar.pObject->Flags >> 10) & 1 )
            v69 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
          if ( v69 )
            ++v69->RefCount;
          v89 = (Scaleform::GFx::Sprite *)v69;
        }
        else
        {
          v70 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v5, v68);
          v69 = (Scaleform::RefCountNTSImpl *)&v70->vfptr;
          if ( v70 )
            ++v70->RefCount;
          v89 = (Scaleform::GFx::Sprite *)v70;
        }
        if ( v69 )
        {
          v69->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v69->vfptr, 0);
          v71 = HIDWORD(v25[13].vfptr[2].find_expr_last_no_side_effect);
          v72 = ((__int64 (__fastcall *)(SSExpressionBase *))v25->vfptr->null_receiver)(v25);
          v73 = v71;
          v69 = (Scaleform::RefCountNTSImpl *)&v89->vfptr;
          Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v89, v73, v72);
          ((void (__fastcall *)(Scaleform::RefCountNTSImpl *))v69->vfptr[112].__vecDelDtor)(v69);
          ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))v5->vfptr[7].__vecDelDtor)(v5);
          if ( v22 )
          {
            v74 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v89->vfptr
                                                                              + 4 * (unsigned __int8)v89->AvmObjOffset))[30].__vecDelDtor)();
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::Sprite *))v22->vfptr[3].~RefCountBaseGC<323>)(
              v22,
              v74,
              v89);
          }
        }
        v1->FirstFrameLoaded = 1;
        if ( v69 )
          Scaleform::RefCountNTSImpl::Release(v69);
      }
    }
    v75 = 0;
    v76 = (_QWORD)v25[13].vfptr[2].__vecDelDtor & 0xF;
    if ( v76 >= 0 )
    {
      if ( v76 <= 1 )
        return v75;
      if ( v76 == 2 )
      {
        v81 = (int)v3[1].vfptr;
        if ( v81 == -1 )
        {
          if ( (v1->pOldChar.pObject->Flags >> 10) & 1 )
            v6 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
          if ( v6 )
            ++v6->RefCount;
          v90 = (Scaleform::GFx::Sprite *)v6;
          v5->vfptr[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v1->pOldChar.pObject);
        }
        else
        {
          v82 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v5, v81);
          v6 = (Scaleform::RefCountNTSImpl *)&v82->vfptr;
          if ( v82 )
            ++v82->RefCount;
          v90 = (Scaleform::GFx::Sprite *)v82;
        }
        if ( v6 )
        {
          if ( !v103 )
            v6[11].RefCount &= 0xFFFFFFFB;
          if ( v22 )
          {
            v83 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr
                                                                              + 4
                                                                              * *((unsigned __int8 *)&v6[6].RefCount + 5)))[30].__vecDelDtor)();
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::RefCountNTSImpl *, _QWORD))v22->vfptr[3].Finalize_GC)(
              v22,
              v83,
              v6,
              0i64);
          }
          if ( !v1->FirstFrameLoaded )
          {
            v6->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6->vfptr, 0);
            v84 = HIDWORD(v25[13].vfptr[2].find_expr_last_no_side_effect);
            v85 = ((__int64 (__fastcall *)(SSExpressionBase *))v25->vfptr->null_receiver)(v25);
            v86 = v84;
            v6 = (Scaleform::RefCountNTSImpl *)&v90->vfptr;
            Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v90, v86, v85);
            ((void (__fastcall *)(Scaleform::RefCountNTSImpl *))v6->vfptr[112].__vecDelDtor)(v6);
            ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))v5->vfptr[7].__vecDelDtor)(v5);
            if ( v22 )
            {
              v87 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v90->vfptr
                                                                                + 4 * (unsigned __int8)v90->AvmObjOffset))[30].__vecDelDtor)();
              ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::Sprite *))v22->vfptr[3].~RefCountBaseGC<323>)(
                v22,
                v87,
                v90);
            }
          }
          v1->FirstFrameLoaded = 1;
        }
        v75 = 1;
        if ( v6 )
          Scaleform::RefCountNTSImpl::Release(v6);
        return v75;
      }
      if ( (unsigned int)(v76 - 3) <= 1 && v22 )
      {
        v77 = v1->pOldChar.pObject;
        if ( v77 )
          v78 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v77->vfptr
                                                                            + 4 * (unsigned __int8)v77->AvmObjOffset))[1].__vecDelDtor)();
        else
          v78 = 0i64;
        v79 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v78 + 240i64))(v78);
        LODWORD(v88) = 0;
        v80 = v1->pOldChar.pObject;
        if ( *(_DWORD *)(*((_QWORD *)v25[13].vfptr->get_side_effect + 8) + 228i64) == 4 )
          ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, __int64))v22->vfptr[4].ExecuteForEachChild_GC)(
            v22,
            v79,
            v80,
            "Error",
            v88);
        else
          ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, __int64))v22->vfptr[4].ExecuteForEachChild_GC)(
            v22,
            v79,
            v80,
            "Canceled",
            v88);
      }
    }
    return 1;
  }
  if ( !v3[1].pNext )
  {
    v36 = (int)v3[1].vfptr;
    if ( v36 != -1 )
    {
      v37 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v5, v36);
      v38 = v37;
      if ( v37 )
        ++v37->RefCount;
      v39 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
      if ( v39 )
        Scaleform::RefCountNTSImpl::Release(v39);
      v1->pOldChar.pObject = v38;
    }
    goto LABEL_38;
  }
  v26 = (unsigned __int8 *)v1->pOldChar.pObject->pParent;
  if ( v26 )
  {
    rid.Id = 65537;
    v27 = (Scaleform::GFx::MovieDefImpl *)(*(__int64 (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v26 + 528i64))(v26);
    Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v27, &result, (Scaleform::GFx::ResourceId)&rid);
    v28 = v5->pASSupport.pObject;
    v105 = v1->NewCharId.Id;
    v29 = (Scaleform::GFx::InteractiveObject *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, unsigned __int8 *, unsigned int *, signed int))v28->vfptr[4].__vecDelDtor)(
                                                 v28,
                                                 v1->pMovieImpl,
                                                 &result,
                                                 v26,
                                                 &v105,
                                                 3);
    v100 = v29;
    v29->CreateFrame = v1->pOldChar.pObject->CreateFrame;
    v29->Depth = v1->pOldChar.pObject->Depth;
    v30 = v1->pOldChar.pObject;
    if ( !((LOBYTE(v30->Flags) >> 1) & 1) )
    {
      v31 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v30->vfptr, &v92);
      v29->vfptr[124].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v29->vfptr, (unsigned int)v31);
      v32 = v92.pNode;
      v33 = v92.pNode->RefCount == 1;
      --v32->RefCount;
      if ( v33 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
    }
    Scaleform::GFx::InteractiveObject::AddToPlayList(v29);
    v34 = (*(__int64 (**)(void))(*(_QWORD *)&v26[4 * v26[109]] + 8i64))();
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v34 + 216i64))(
      v34,
      v1->pOldChar.pObject,
      v29);
    v1->pOldChar.pObject->pParent = 0i64;
    ++v29->RefCount;
    v35 = (Scaleform::RefCountNTSImpl *)&v1->pOldChar.pObject->vfptr;
    if ( v35 )
      Scaleform::RefCountNTSImpl::Release(v35);
    v1->pOldChar.pObject = v29;
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v29->vfptr);
LABEL_38:
    v40 = v1->pOldChar.pObject;
    if ( v40 && v22 )
    {
      v41 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v40->vfptr
                                                                        + 4 * (unsigned __int8)v40->AvmObjOffset))[1].__vecDelDtor)();
      v42 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v41 + 240i64))(v41);
      LODWORD(v88) = 0;
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, __int64))v22->vfptr[4].ExecuteForEachChild_GC)(
        v22,
        v42,
        v1->pOldChar.pObject,
        "URLNotFound",
        v88);
    }
    v43 = (int)v3[1].vfptr;
    if ( v43 != -1 )
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(v1->pMovieImpl, v43);
  }
  return 1;
}

// File Line: 2940
// RVA: 0x700BE0
bool __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::IsPreloadingFinished(Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this)
{
  return Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
}

// File Line: 2951
// RVA: 0x6C8F70
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(Scaleform::GFx::AS2::GFxAS2LoadXMLTask *this, Scaleform::GFx::LoadStates *pls, Scaleform::String *level0Path, Scaleform::String *url, Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType *xmlholder)
{
  Scaleform::String *v5; // rsi
  Scaleform::String *v6; // rbp
  Scaleform::GFx::LoadStates *v7; // rdi
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v8; // rbx
  Scaleform::GFx::Resource *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx

  v5 = url;
  v6 = level0Path;
  v7 = pls;
  v8 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable';
  this->ThisTaskId = 131073;
  this->CurrentState = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadXMLTask::`vftable';
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pls);
  v8->pLoadStates.pObject = v7;
  Scaleform::String::String(&v8->Level0Path, v6);
  Scaleform::String::String(&v8->Url, v5);
  v9 = (Scaleform::GFx::Resource *)xmlholder->Loader.pObject;
  if ( v9 )
    Scaleform::Render::RenderBuffer::AddRef(v9);
  v8->pXMLLoader.pObject = xmlholder->Loader.pObject;
  v8->Done = 0;
  v10 = (Scaleform::Render::RenderBuffer *)xmlholder->Loader.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  if ( xmlholder->ASObj.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&xmlholder->ASObj);
}

// File Line: 2955
// RVA: 0x6E7BF0
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::Execute(Scaleform::GFx::AS2::GFxAS2LoadXMLTask *this)
{
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v1; // rdi
  unsigned __int64 v2; // rdx
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rdx
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+28h] [rbp-20h]
  Scaleform::String pdest; // [rsp+50h] [rbp+8h]
  Scaleform::String v8; // [rsp+58h] [rbp+10h]

  v1 = this;
  loc.Use = 5;
  Scaleform::String::String(&loc.FileName, &this->Url);
  Scaleform::String::String(&loc.ParentPath, &v1->Level0Path);
  Scaleform::String::String(&pdest);
  Scaleform::GFx::LoadStates::BuildURL(v1->pLoadStates.pObject, &pdest, &loc);
  Scaleform::String::String(&v8, (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  ((void (__fastcall *)(Scaleform::GFx::AS2::XMLFileLoader *, Scaleform::String *, Scaleform::GFx::FileOpener *))v1->pXMLLoader.pObject->vfptr[1].__vecDelDtor)(
    v1->pXMLLoader.pObject,
    &v8,
    v1->pLoadStates.pObject->pBindStates.pObject->pFileOpener.pObject);
  v2 = v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v2);
  v1->Done = 1;
  v3 = pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v3);
  v4 = loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v4);
  v5 = loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v5);
}

// File Line: 2974
// RVA: 0x6C8D50
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this, Scaleform::GFx::LoadQueueEntry *pqueueEntry, Scaleform::GFx::AS2::MovieRoot *pmovieRoot)
{
  Scaleform::GFx::AS2::MovieRoot *v3; // rbx
  Scaleform::GFx::LoadQueueEntry *v4; // r14
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *v5; // rdi
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v6; // rsi
  Scaleform::GFx::TaskManager *v7; // rbp
  Scaleform::GFx::MovieImpl *v8; // r8
  Scaleform::GFx::LoaderImpl *v9; // rbx
  Scaleform::GFx::StateBag *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rax
  Scaleform::GFx::LoadStates *v12; // rbx
  Scaleform::Render::RenderBuffer *v13; // rcx
  unsigned int v14; // ecx
  Scaleform::GFx::MovieImpl *v15; // r9
  unsigned __int64 v16; // r8
  __int64 v17; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // rdx
  const char *v19; // rax
  Scaleform::GFx::TaskManager *v20; // rbp
  Scaleform::GFx::Resource *v21; // rcx
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v22; // rax
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v24; // rax
  Scaleform::GFx::AS2::Value v25; // [rsp+40h] [rbp-58h]
  __int64 v26; // [rsp+60h] [rbp-38h]
  Scaleform::String ppath; // [rsp+B0h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+B8h] [rbp+20h]

  v3 = pmovieRoot;
  v4 = pqueueEntry;
  v5 = this;
  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
    (Scaleform::GFx::LoadQueueEntryMT *)&this->vfptr,
    pqueueEntry,
    pmovieRoot->pMovieImpl);
  v5->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::`vftable';
  v6 = 0i64;
  v5->pTask.pObject = 0i64;
  v5->pLoadStates.pObject = 0i64;
  v5->pASMovieRoot = v3;
  v7 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144ui64,
                                        0i64);
  result.pObject = v7;
  if ( v7 )
  {
    v8 = v5->pMovieImpl;
    v9 = v8->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v10 = (Scaleform::GFx::StateBag *)((__int64 (*)(void))v8->vfptr->GetStateBagImpl)();
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v7, v9, v10, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (Scaleform::Render::RenderBuffer *)v5->pLoadStates.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v5->pLoadStates.pObject = v12;
  Scaleform::String::String(&ppath);
  v14 = 0;
  v15 = v5->pASMovieRoot->pMovieImpl;
  v16 = v15->MovieLevels.Data.Size;
  if ( !v16 )
    goto LABEL_13;
  v17 = 0i64;
  v18 = v15->MovieLevels.Data.Data;
  while ( v18[v17].Level )
  {
    v17 = ++v14;
    if ( v14 >= v16 )
      goto LABEL_13;
  }
  if ( !v18[v14].pSprite.pObject
    || (v19 = (const char *)((__int64 (*)(void))v15->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(),
        Scaleform::String::operator=(&ppath, v19),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_13:
    Scaleform::String::Clear(&ppath);
  }
  v20 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         64i64);
  result.pObject = v20;
  if ( v20 )
  {
    Scaleform::GFx::AS2::Value::Value(&v25, (Scaleform::GFx::AS2::Value *)&v4[3]);
    v21 = *(Scaleform::GFx::Resource **)&v4[3].EntryTime;
    if ( v21 )
      Scaleform::Render::RenderBuffer::AddRef(v21);
    v26 = *(_QWORD *)&v4[3].EntryTime;
    Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(
      (Scaleform::GFx::AS2::GFxAS2LoadXMLTask *)v20,
      v5->pLoadStates.pObject,
      &ppath,
      &v4->URL,
      (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType *)&v25);
    v6 = v22;
  }
  v23 = (Scaleform::Render::RenderBuffer *)v5->pTask.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  v5->pTask.pObject = v6;
  v24 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v5->pMovieImpl->vfptr, &result);
  v24->pObject->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)v24->pObject, (unsigned int)v5->pTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 2990
// RVA: 0x701E60
char __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::LoadFinished(Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this)
{
  Scaleform::GFx::LoadQueueEntry *v1; // rbp
  bool v2; // al
  Scaleform::GFx::InteractiveObject *v4; // r9
  Scaleform::GFx::MovieImpl *v5; // r8
  unsigned __int64 v6; // rdx
  unsigned int v7; // ecx
  Scaleform::GFx::MovieImpl::LevelInfo *v8; // r8
  __int64 v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // rax
  __int64 *v11; // rdi
  __int64 v12; // rsi
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax

  v1 = this->pQueueEntry;
  v2 = this->pTask.pObject->Done == 1;
  if ( v1->Canceled )
  {
    if ( v2 )
      return 1;
    return 0;
  }
  if ( !v2 )
    return 0;
  v4 = 0i64;
  v5 = this->pASMovieRoot->pMovieImpl;
  v6 = v5->MovieLevels.Data.Size;
  v7 = 0;
  if ( v6 )
  {
    v8 = v5->MovieLevels.Data.Data;
    v9 = 0i64;
    while ( v8[v9].Level )
    {
      v9 = ++v7;
      if ( v7 >= v6 )
        goto LABEL_12;
    }
    v4 = v8[v7].pSprite.pObject;
  }
LABEL_12:
  v10 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * (unsigned __int8)v4->AvmObjOffset))[30].__vecDelDtor)((signed __int64)v4 + 4 * (unsigned __int8)v4->AvmObjOffset);
  v11 = *(__int64 **)&v1[3].EntryTime;
  v12 = *v11;
  v13 = v10;
  v14 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v1[3], v10);
  (*(void (__fastcall **)(__int64 *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(v12 + 16))(
    v11,
    v13,
    v14);
  return 1;
}

// File Line: 3079
// RVA: 0x6C6BD0
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::ASRefCountCollector(Scaleform::GFx::AS2::ASRefCountCollector *this)
{
  Scaleform::GFx::AS2::ASRefCountCollector *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS2::RefCountCollector<323>::RefCountCollector<323>((Scaleform::GFx::AS2::RefCountCollector<323> *)&this->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::ASRefCountCollector::`vftable';
  v1->FrameCnt = 0;
  *(_QWORD *)&v1->PeakRootCount = 0i64;
  *(_QWORD *)&v1->LastCollectedRoots = 0i64;
  *(_QWORD *)&v1->TotalFramesCount = 0i64;
  *(_QWORD *)&v1->PresetMaxRootCount = 1000i64;
  v1->MaxRootCount = 1000;
}

// File Line: 3092
// RVA: 0x71AA20
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::SetParams(Scaleform::GFx::AS2::ASRefCountCollector *this, unsigned int frameBetweenCollections, unsigned int maxRootCount)
{
  unsigned int v3; // eax

  v3 = 0;
  if ( frameBetweenCollections != -1 )
    v3 = frameBetweenCollections;
  this->MaxFramesBetweenCollections = v3;
  if ( maxRootCount == -1 )
  {
    this->MaxRootCount = 1000;
    this->PresetMaxRootCount = 1000;
  }
  else
  {
    this->MaxRootCount = maxRootCount;
    this->PresetMaxRootCount = maxRootCount;
  }
}

// File Line: 3107
// RVA: 0x6DA250
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(Scaleform::GFx::AS2::ASRefCountCollector *this, unsigned int *movieFrameCnt, unsigned int *movieLastCollectFrame, Scaleform::AmpStats *ampStats)
{
  Scaleform::AmpStats *v4; // rbp
  unsigned int *v5; // r14
  unsigned int *v6; // rsi
  Scaleform::GFx::AS2::ASRefCountCollector *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  unsigned __int64 v10; // rdi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h]

  v4 = ampStats;
  v5 = movieLastCollectFrame;
  v6 = movieFrameCnt;
  v7 = this;
  v8 = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == v8 )
  {
    v9 = this->FrameCnt;
    if ( *movieFrameCnt >= v9 )
    {
      v10 = v7->Roots.Size;
      ++v7->TotalFramesCount;
      v11 = v9 + 1;
      v7->FrameCnt = v9 + 1;
      v12 = v10;
      if ( (unsigned int)v10 < v7->PeakRootCount )
        v12 = v7->PeakRootCount;
      v7->PeakRootCount = v12;
      v13 = v7->PresetMaxRootCount;
      if ( v13 && (unsigned int)v10 > v7->MaxRootCount
        || (v14 = v7->MaxFramesBetweenCollections) != 0 && v11 >= v14 && (unsigned int)v10 > v13 )
      {
        if ( ampStats )
          Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ampStats);
        pstat.AdvanceStats.pObject = v4;
        *(_QWORD *)&pstat.RootsNumber = 0i64;
        Scaleform::GFx::AS2::RefCountCollector<323>::Collect(
          (Scaleform::GFx::AS2::RefCountCollector<323> *)&v7->vfptr,
          &pstat);
        v15 = v7->PresetMaxRootCount;
        v16 = pstat.RootsFreedTotal;
        if ( pstat.RootsFreedTotal > v15 )
        {
          v7->PeakRootCount = v10;
          v7->MaxRootCount = v15;
        }
        if ( (unsigned int)v10 > v16 )
        {
          v17 = v10 - v16;
          if ( (unsigned int)v10 - v16 < v7->MaxRootCount )
            v17 = v7->MaxRootCount;
          v7->MaxRootCount = v17;
        }
        v18 = (signed int)((double)(signed int)v7->MaxRootCount * 0.7);
        v19 = v7->PeakRootCount;
        if ( v19 < v18 )
          v7->MaxRootCount = v18;
        v7->LastCollectionFrameNum = v7->TotalFramesCount;
        v7->FrameCnt = 0;
        v7->LastPeakRootCount = v19;
        v7->LastCollectedRoots = v16;
        if ( pstat.AdvanceStats.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
      }
      v7->LastRootCount = v10;
      *v6 = v7->FrameCnt;
      *v5 = v7->LastCollectionFrameNum;
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = v8;
    *movieFrameCnt = 1;
  }
}

// File Line: 3186
// RVA: 0x6EC090
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(Scaleform::GFx::AS2::ASRefCountCollector *this, Scaleform::AmpStats *ampStats)
{
  Scaleform::AmpStats *v2; // rdi
  Scaleform::GFx::AS2::ASRefCountCollector *v3; // rbx
  unsigned __int64 v4; // rsi
  unsigned int v5; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h]

  v2 = ampStats;
  v3 = this;
  v4 = this->Roots.Size;
  if ( ampStats )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ampStats);
  pstat.AdvanceStats.pObject = v2;
  *(_QWORD *)&pstat.RootsNumber = 0i64;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(
    (Scaleform::GFx::AS2::RefCountCollector<323> *)&v3->vfptr,
    &pstat);
  v3->FrameCnt = 0;
  v5 = v4;
  if ( (unsigned int)v4 < v3->PeakRootCount )
    v5 = v3->PeakRootCount;
  v3->PeakRootCount = v5;
  v3->LastRootCount = v4;
  if ( pstat.AdvanceStats.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
}

// File Line: 3222
// RVA: 0x70B700
void __fastcall Scaleform::GFx::AS2::AvmSwfEvent::Read(Scaleform::GFx::AS2::AvmSwfEvent *this, Scaleform::GFx::StreamContext *psc, unsigned int flags)
{
  Scaleform::GFx::StreamContext *v3; // rbx
  Scaleform::GFx::AS2::AvmSwfEvent *v4; // rdi
  unsigned __int64 v5; // rcx
  const char *v6; // rdx
  unsigned int v7; // esi
  signed __int64 v8; // rax
  unsigned int v9; // ecx
  Scaleform::GFx::AS2::ActionBufferData *v10; // rax
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::AS2::ActionBufferData *v12; // rbp
  unsigned int v13; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ecx
  unsigned __int64 v16; // rax
  __int64 v17; // rdx

  this->Event.Id = flags;
  *(_DWORD *)&this->Event.RollOverCnt = 65280;
  *(_QWORD *)&this->Event.WcharCode = 0i64;
  this->Event.AsciiCode = 0;
  v3 = psc;
  v4 = this;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  v5 = psc->CurByteIndex;
  psc->CurBitIndex = 0;
  v6 = psc->pData;
  v7 = (unsigned __int8)v6[v5] | (((unsigned __int8)v6[v5 + 1] | (*(unsigned __int16 *)&v6[v5 + 2] << 8)) << 8);
  v8 = v5 + 4;
  v3->CurByteIndex = v5 + 4;
  if ( v4->Event.Id & 0x20000 )
  {
    v3->CurBitIndex = 0;
    v9 = (unsigned __int8)v6[v8];
    v3->CurByteIndex = v8 + 1;
    --v7;
    v4->Event.KeyCode = v9;
  }
  v10 = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  v11 = (Scaleform::Render::RenderBuffer *)v4->pActionOpData.pObject;
  v12 = v10;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v4->pActionOpData.pObject = v12;
  Scaleform::GFx::AS2::ActionBufferData::Read(v12, v3, v7);
  v13 = v4->pActionOpData.pObject->BufferLen;
  if ( v13 != v7 )
  {
    if ( v7 <= v13 )
    {
      v3->CurByteIndex -= v13 - v7;
    }
    else
    {
      v14 = v7 - v13;
      if ( v14 )
      {
        v15 = v3->CurBitIndex;
        v16 = v3->CurByteIndex;
        v17 = v14;
        do
        {
          if ( v15 )
            ++v16;
          ++v16;
          v15 = 0;
          --v17;
        }
        while ( v17 );
        v3->CurBitIndex = 0;
        v3->CurByteIndex = v16;
      }
    }
  }
}

// File Line: 3273
// RVA: 0x6DB2F0
void __fastcall Scaleform::GFx::AS2::AvmSwfEvent::AttachTo(Scaleform::GFx::AS2::AvmSwfEvent *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::AS2::AvmSwfEvent *v2; // rdi
  Scaleform::GFx::AS2::ActionBufferData *v3; // rax
  Scaleform::GFx::AS2::AvmCharacter *v4; // rsi
  __int64 v5; // rax
  Scaleform::GFx::AS2::Environment *v6; // r15
  __int64 v7; // r14
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rbx
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType; // ebp
  Scaleform::GFx::AS2::AsFunctionObject *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+60h] [rbp-58h]

  v2 = this;
  v3 = this->pActionOpData.pObject;
  if ( v3 && v3->BufferLen >= 1 && *v3->pBuffer )
  {
    if ( ch )
      v4 = (Scaleform::GFx::AS2::AvmCharacter *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&ch->vfptr + 4 * (unsigned __int8)ch->AvmObjOffset))[1].__vecDelDtor)();
    else
      v4 = 0i64;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))v4->vfptr[2].GetAbsolutePath)(v4);
    v6 = (Scaleform::GFx::AS2::Environment *)v5;
    v7 = *(_QWORD *)(*(_QWORD *)(v5 + 232) + 48i64);
    v8 = (Scaleform::GFx::AS2::ActionBuffer *)(*(__int64 (__fastcall **)(_QWORD, signed __int64))(*(_QWORD *)v7 + 80i64))(
                                                *(_QWORD *)(*(_QWORD *)(v5 + 232) + 48i64),
                                                64i64);
    if ( v8 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v8, &v6->StringContext, v2->pActionOpData.pObject);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v2->Event.Id == 1 || v2->Event.Id == 4 || v2->Event.Id == 512 || (execType = 3, v2->Event.Id == 262144) )
      execType = 4;
    v12 = (Scaleform::GFx::AS2::AsFunctionObject *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v7 + 80i64))(
                                                     v7,
                                                     200i64,
                                                     0i64);
    if ( v12 )
    {
      Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
        v12,
        v6,
        v10,
        0,
        v2->pActionOpData.pObject->BufferLen,
        0i64,
        execType);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    method.T.Type = 8;
    method.V.FunctionValue.Flags = 0;
    method.V.pStringNode = v14;
    if ( v14 )
      v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
    method.V.FunctionValue.pLocalFrame = 0i64;
    if ( v14 )
    {
      v15 = v14->RefCount;
      if ( v15 & 0x3FFFFFF )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
      }
    }
    Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(v4, &v2->Event, &method);
    if ( method.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&method);
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
  }
}

// File Line: 3341
// RVA: 0x705EF0
char __fastcall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::OnExceedLimit(Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this, Scaleform::MemoryHeap *heap, unsigned __int64 overLimit)
{
  Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *v3; // rbx
  unsigned __int64 v4; // r14
  Scaleform::MemoryHeap *v5; // rdi
  signed __int64 v6; // rax
  unsigned __int64 v7; // r15
  signed __int64 v8; // rbp
  float v9; // xmm0_4
  float v10; // xmm0_4
  signed __int64 v11; // rax
  float v12; // xmm1_4
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rcx

  v3 = this;
  v4 = overLimit;
  v5 = heap;
  v6 = heap->vfptr->GetFootprint(heap);
  v7 = v5->Info.Desc.Limit;
  v8 = v6;
  v9 = (float)(signed int)v6;
  if ( v6 < 0 )
    v9 = v9 + 1.8446744e19;
  v10 = v9 * v3->HeapLimitMultiplier;
  v11 = 0i64;
  v12 = v10;
  if ( v10 >= 9.223372e18 )
  {
    v12 = v10 - 9.223372e18;
    if ( (float)(v10 - 9.223372e18) < 9.223372e18 )
      v11 = 0x8000000000000000i64;
  }
  v13 = v4 + v7 + v11 + (unsigned int)(signed int)v12;
  if ( (signed __int64)(v8 - v3->LastCollectionFootprint) < (unsigned int)(signed int)v10 )
  {
    v14 = v3->UserLevelLimit;
    if ( !v14 || v13 <= v14 )
    {
      v15 = v13;
LABEL_16:
      v5->vfptr->SetLimit(v5, v15);
      v3->CurrentLimit = v5->Info.Desc.Limit;
      return 1;
    }
  }
  if ( !v3->AllocCount )
  {
    Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(v3, v5);
    v16 = v3->UserLevelLimit;
    if ( v16 )
    {
      if ( v13 > v16 )
      {
        v17 = v3->LastCollectionFootprint;
        if ( v4 <= v8 - v17 )
        {
          v15 = v3->CurrentLimit;
        }
        else
        {
          v15 = v4 + v7 + v17 - v8;
          v3->CurrentLimit = v15;
        }
        goto LABEL_16;
      }
    }
  }
  return 1;
}

// File Line: 3408
// RVA: 0x706360
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnFreeSegment(Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this, Scaleform::MemoryHeap *heap, unsigned __int64 freeingSize)
{
  Scaleform::MemoryHeap *v3; // r9
  unsigned __int64 v4; // rdx

  v3 = heap;
  v4 = this->CurrentLimit;
  if ( v4 > this->UserLevelLimit && v4 > freeingSize )
  {
    this->CurrentLimit = v4 - freeingSize;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))v3->vfptr->SetLimit)(v3);
  }
}

// File Line: 3423
// RVA: 0x6DE250
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // r14
  Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *v3; // rsi
  Scaleform::Render::Text::Allocator *v4; // rcx
  Scaleform::GFx::AS2::ASRefCountCollector *v5; // rdi
  unsigned __int64 v6; // rbx
  unsigned int v7; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h]

  v2 = heap;
  v3 = this;
  v4 = this->MemContext->TextAllocator.pObject;
  if ( v4 )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(v4, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(v3->MemContext->TextAllocator.pObject, 1);
  }
  v5 = v3->MemContext->ASGC.pObject;
  v6 = v5->Roots.Size;
  pstat.AdvanceStats.pObject = 0i64;
  *(_QWORD *)&pstat.RootsNumber = 0i64;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(
    (Scaleform::GFx::AS2::RefCountCollector<323> *)&v5->vfptr,
    &pstat);
  v5->FrameCnt = 0;
  v7 = v6;
  if ( (unsigned int)v6 < v5->PeakRootCount )
    v7 = v5->PeakRootCount;
  v5->PeakRootCount = v7;
  v5->LastRootCount = v6;
  if ( pstat.AdvanceStats.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
  if ( !(v5->Flags & 1) && !v5->Roots.Size )
    Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)v5->Roots.gap0);
  v5->PeakRootCount = 0;
  v5->MaxRootCount = v5->PresetMaxRootCount;
  v3->LastCollectionFootprint = v2->vfptr->GetFootprint(v2);
}

// File Line: 3529
// RVA: 0x6E3150
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::EventId_GetFunctionName(Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::StringManager *psm, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::AS2::StringManager *v3; // rdi
  Scaleform::GFx::ASString *v4; // rbx
  unsigned int v5; // er8
  __int64 v6; // r8
  signed int v7; // ecx
  Scaleform::GFx::ASStringNode *v8; // rcx

  v3 = psm;
  v4 = result;
  v5 = evt->Id;
  if ( v5 > 0x800000 )
    v6 = v5 - 16777191;
  else
    v6 = (unsigned __int8)Scaleform::Alg::BitCount32(v5);
  if ( (unsigned int)(v6 - 1) > 0x21 )
    v7 = 46;
  else
    v7 = *(_DWORD *)&aZ_26[4 * v6];
  v8 = v3->Builtins[v7].pNode;
  v4->pNode = v8;
  ++v8->RefCount;
  return v4;
}

