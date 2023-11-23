// File Line: 44
// RVA: 0x6CAC00
void __fastcall Scaleform::GFx::AS2::MovieRoot::MovieRoot(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Resource *memContext,
        Scaleform::GFx::MovieImpl *pmovie,
        Scaleform::GFx::Resource *pas)
{
  Scaleform::MemoryHeap *pLib; // rax
  Scaleform::GFx::AS2::GlobalContext *pObject; // rcx

  Scaleform::GFx::ASMovieRootBase::ASMovieRootBase(this, pas);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable;
  this->TopNode.pObject = 0i64;
  if ( pas )
    Scaleform::Render::RenderBuffer::AddRef(pas);
  this->pASSupport.pObject = (Scaleform::GFx::ASSupport *)pas;
  if ( memContext )
    Scaleform::Render::RenderBuffer::AddRef(memContext);
  this->MemContext.pObject = (Scaleform::GFx::AS2::MemoryContextImpl *)memContext;
  *(_QWORD *)&this->NumAdvancesSinceCollection = 0i64;
  this->pGlobalContext.pObject = 0i64;
  this->ExternalIntfRetVal.T.Type = 0;
  pLib = (Scaleform::MemoryHeap *)memContext->pLib;
  this->ActionQueue.Entries[0].pInsertEntry = 0i64;
  this->ActionQueue.Entries[0].pLastEntry = 0i64;
  this->ActionQueue.Entries[0].pActionRoot = 0i64;
  this->ActionQueue.Entries[1].pInsertEntry = 0i64;
  this->ActionQueue.Entries[1].pLastEntry = 0i64;
  this->ActionQueue.Entries[1].pActionRoot = 0i64;
  this->ActionQueue.Entries[2].pInsertEntry = 0i64;
  this->ActionQueue.Entries[2].pLastEntry = 0i64;
  this->ActionQueue.Entries[2].pActionRoot = 0i64;
  this->ActionQueue.Entries[3].pInsertEntry = 0i64;
  this->ActionQueue.Entries[3].pLastEntry = 0i64;
  this->ActionQueue.Entries[3].pActionRoot = 0i64;
  this->ActionQueue.Entries[4].pInsertEntry = 0i64;
  this->ActionQueue.Entries[4].pLastEntry = 0i64;
  this->ActionQueue.Entries[4].pActionRoot = 0i64;
  this->ActionQueue.Entries[5].pInsertEntry = 0i64;
  this->ActionQueue.Entries[5].pLastEntry = 0i64;
  this->ActionQueue.Entries[5].pActionRoot = 0i64;
  this->ActionQueue.pHeap = pLib;
  this->ActionQueue.ModId = 1;
  this->ActionQueue.pFreeEntry = 0i64;
  this->ActionQueue.LastSessionId = 1;
  *(_QWORD *)&this->ActionQueue.CurrentSessionId = 1i64;
  Scaleform::GFx::AS2::StringManager::StringManager(
    &this->BuiltinsMgr,
    (Scaleform::GFx::ASStringManager *)memContext[1].vfptr);
  this->SpritesWithHitArea.Data.Data = 0i64;
  this->SpritesWithHitArea.Data.Size = 0i64;
  this->SpritesWithHitArea.Data.Policy.Capacity = 0i64;
  this->pMovieImpl = pmovie;
  this->pASMouseListener = 0i64;
  this->pInvokeAliases = 0i64;
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = 0i64;
  Scaleform::GFx::MovieImpl::SetASMovieRoot(this->pMovieImpl, this);
  Scaleform::GFx::AS2::MovieRoot::CreateObjectInterface(this, this->pMovieImpl);
}

// File Line: 58
// RVA: 0x6D2130
void __fastcall Scaleform::GFx::AS2::MovieRoot::~MovieRoot(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::GlobalContext *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::TreeContainer *v5; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::MovieRoot::`vftable;
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>(&this->SpritesWithHitArea.Data);
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
    this->BuiltinsMgr.pStringManager,
    this->BuiltinsMgr.Builtins,
    0x9Cu);
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType::~ActionQueueType(&this->ActionQueue);
  if ( this->ExternalIntfRetVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->ExternalIntfRetVal);
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->MemContext.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)this->pASSupport.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = this->TopNode.pObject;
  if ( v5 )
  {
    if ( v5->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable;
  v7 = (Scaleform::Render::RenderBuffer *)this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 62
// RVA: 0x71FC00
void __fastcall Scaleform::GFx::AS2::MovieRoot::Shutdown(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::Render::TreeContainer *pObject; // rcx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *pInvokeAliases; // rbx
  Scaleform::GFx::AS2::GlobalContext *v5; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v8; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::Sprite>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::Sprite>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->SpritesWithHitArea.Data,
    &this->SpritesWithHitArea,
    0i64);
  pObject = this->TopNode.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->TopNode.pObject = 0i64;
  this->pASMouseListener = 0i64;
  pInvokeAliases = this->pInvokeAliases;
  if ( pInvokeAliases )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&pInvokeAliases->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pInvokeAliases);
  }
  this->pInvokeAliases = 0i64;
  Scaleform::GFx::AS2::Value::DropRefs(&this->ExternalIntfRetVal);
  this->ExternalIntfRetVal.T.Type = 0;
  Scaleform::GFx::AS2::GlobalContext::PreClean(this->pGlobalContext.pObject, 1);
  this->pGlobalContext.pObject->pMovieRoot = 0i64;
  v5 = this->pGlobalContext.pObject;
  v6 = v5->pGlobal.pObject;
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  v5->pGlobal.pObject = 0i64;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>(&v5->RegisteredClasses.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Clear(&v5->BuiltinClassesRegistry.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>(&v5->Prototypes.mHash);
  v5->pMovieRoot = 0i64;
  v8.pActionQueue = &this->ActionQueue;
  v8.ModId = 0;
  v8.CurrentPrio = 0;
  v8.pLastEntry = 0i64;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v8) )
    ;
  if ( v8.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v8.pActionQueue, v8.pLastEntry);
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
}GFx::Resource *)this->pMovieI

// File Line: 92
// RVA: 0x71A130
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetMovie(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::MovieImpl *pmovie)
{
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::GlobalContext *v5; // rax
  Scaleform::GFx::AS2::GlobalContext *v6; // rbx
  Scaleform::GFx::AS2::GlobalContext *pObject; // rcx

  this->pMovieImpl = pmovie;
  v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64))pmovie->pHeap->vfptr->Alloc)(
                                               this,
                                               120i64);
  if ( v4 )
  {
    Scaleform::GFx::AS2::GlobalContext::GlobalContext(v4, pmovie);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = v6;
}

// File Line: 98
// RVA: 0x6FCAE0
char __fastcall Scaleform::GFx::AS2::MovieRoot::Init(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::GlobalContext *v5; // rax
  Scaleform::GFx::AS2::GlobalContext *v6; // rbx
  Scaleform::GFx::AS2::GlobalContext *pObject; // rcx
  Scaleform::Render::TreeContainer *v8; // rbx
  Scaleform::Render::TreeContainer *v9; // rcx
  Scaleform::GFx::ASSupport *v11; // rcx
  Scaleform::GFx::Sprite *v12; // rbx
  __int64 v14[4]; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+60h] [rbp+8h] BYREF
  void *v16; // [rsp+68h] [rbp+10h]

  pHeap = this->pMovieImpl->pHeap;
  v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64))pHeap->vfptr->Alloc)(
                                               this,
                                               120i64);
  v16 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::GlobalContext::GlobalContext(v4, this->pMovieImpl);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = this->pGlobalContext.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pGlobalContext.pObject = v6;
  v8 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->pMovieImpl->RenderContext);
  v9 = this->TopNode.pObject;
  if ( v9 )
  {
    if ( v9->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
  }
  this->TopNode.pObject = v8;
  Scaleform::Render::TreeContainer::Insert(this->pMovieImpl->pRenderRoot.pObject, 0i64, v8);
  v14[0] = (__int64)pmovieDef->pBindData.pObject->pDataDef.pObject;
  v14[1] = (__int64)pmovieDef;
  v14[2] = 0i64;
  v11 = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  LODWORD(pHeap) = 0x40000;
  v12 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, Scaleform::MemoryHeap **, int))v11->vfptr[4].__vecDelDtor)(
                                    v11,
                                    this->pMovieImpl,
                                    v14,
                                    0i64,
                                    &pHeap,
                                    3);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v12, 1);
  v16 = v12;
  Scaleform::GFx::AS2::AvmSprite::SetLevel(
    (Scaleform::GFx::AS2::AvmSprite *)((char *)v12 + 4 * (unsigned __int8)v12->AvmObjOffset),
    0);
  Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, 0, v12);
  ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))this->vfptr[38].__vecDelDtor)(this);
  this->vfptr[39].__vecDelDtor(this, (unsigned int)v12);
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))v12->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(v12);
  Scaleform::RefCountNTSImpl::Release(v12);
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
      (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
}

// File Line: 142
// RVA: 0x6EC110
void __fastcall Scaleform::GFx::AS2::MovieRoot::ForceCollect(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int __formal)
{
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
    this->MemContext.pObject->ASGC.pObject,
    (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
}

// File Line: 151
// RVA: 0x6EC130
void __fastcall Scaleform::GFx::AS2::MovieRoot::ForceEmergencyCollect(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::ASRefCountCollector *pObject; // rbx

  pObject = this->MemContext.pObject->ASGC.pObject;
  Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
    pObject,
    (Scaleform::GFx::Resource *)this->pMovieImpl->AdvanceStats.pObject);
  if ( (pObject->Flags & 1) == 0 && !pObject->Roots.Size )
    Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease(&pObject->Roots);
  *(_QWORD *)&pObject->MaxRootCount = pObject->PresetMaxRootCount;
}

// File Line: 161
// RVA: 0x6EDBE0
void __fastcall Scaleform::GFx::AS2::MovieRoot::GenerateMouseEvents(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int mouseIndex)
{
  __int64 v2; // r12
  unsigned int v4; // r8d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r10
  __int64 v7; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v10; // rcx
  char v11; // si
  Scaleform::GFx::MouseState *v12; // rdi
  Scaleform::GFx::InteractiveObject *v13; // rbx
  unsigned int v14; // edx
  bool v15; // r14
  unsigned __int8 v16; // r15
  __int64 v17; // r9
  Scaleform::GFx::InteractiveObject *v18; // r8
  Scaleform::GFx::InteractiveObject *v19; // rax
  int v20; // esi
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  char v24; // cl
  int v25; // eax
  char RollOverCnt; // al
  char v27; // cl
  int v28; // eax
  char v29; // cl
  int v30; // eax
  __int64 v31; // r9
  char v32; // al
  char v33; // dl
  Scaleform::WeakPtrProxy *WeakProxy; // rsi
  Scaleform::WeakPtrProxy *v35; // rdx
  bool v36; // zf
  Scaleform::WeakPtrProxy *v37; // rdx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::InteractiveObject *v39; // [rsp+28h] [rbp-30h]
  __int64 v40; // [rsp+30h] [rbp-28h]
  _BYTE v41[12]; // [rsp+38h] [rbp-20h] BYREF
  unsigned __int8 v42; // [rsp+44h] [rbp-14h]
  char v43; // [rsp+48h] [rbp-10h]
  char v44; // [rsp+49h] [rbp-Fh]
  __int16 v45; // [rsp+4Ah] [rbp-Eh]
  unsigned __int8 v46; // [rsp+A0h] [rbp+48h]
  char v47; // [rsp+A8h] [rbp+50h]
  unsigned int v48; // [rsp+B0h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> v49; // [rsp+B8h] [rbp+60h] BYREF

  v40 = -2i64;
  v2 = mouseIndex;
  v4 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v7 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v7].Level )
    {
      v7 = ++v4;
      if ( v4 >= Size )
        goto LABEL_7;
    }
    pObject = Data[v4].pSprite.pObject;
  }
  else
  {
LABEL_7:
    pObject = 0i64;
  }
  v10 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v11 = 1;
  if ( *(_BYTE *)(*(_QWORD *)((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 240i64))(v10) + 232) + 104i64) == 1 )
    v11 = 16;
  v46 = v11;
  if ( (unsigned int)v2 < 6 )
    v12 = &this->pMovieImpl->mMouseState[v2];
  else
    v12 = 0i64;
  Scaleform::GFx::MouseState::GetActiveEntity(v12, &result);
  Scaleform::GFx::MouseState::GetTopmostEntity(v12, &v49);
  v13 = result.pObject;
  if ( result.pObject && (result.pObject->Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(result.pObject);
    v13 = 0i64;
    result.pObject = 0i64;
  }
  if ( v49.pObject && (v49.pObject->Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(v49.pObject);
    v49.pObject = 0i64;
    v13 = result.pObject;
  }
  if ( v13 )
  {
    ++v13->RefCount;
    v13 = result.pObject;
  }
  v39 = v13;
  v14 = v12->PrevButtonsState ^ v12->CurButtonsState;
  v48 = v14;
  v47 = 0;
  v15 = (*((_BYTE *)v12 + 76) & 4) != 0;
  v16 = 0;
  v17 = 0xFFFFFFFFi64;
  v18 = result.pObject;
  v19 = v49.pObject;
  do
  {
    v20 = 1 << v16;
    if ( ((v14 >> v16) & 1) != 0 )
    {
      if ( (v20 & v12->PrevButtonsState) == 0 )
        goto LABEL_36;
      if ( (v20 & v12->CurButtonsState) == 0 && v18 )
      {
        if ( (*((_BYTE *)v12 + 76) & 4) != 0 )
        {
          v21 = 2048;
          if ( v16 )
            v21 = 0x100000;
          *(_DWORD *)v41 = v21;
          *(_QWORD *)&v41[4] = 0i64;
          v45 = 0;
          v42 = v16;
          v44 = v2;
          v43 = 0;
          v18->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            v18,
            (unsigned int)v41);
          v18 = result.pObject;
          v19 = v49.pObject;
        }
        else
        {
          if ( (v18->Flags & 0x4000) == 0 )
          {
            v22 = 4096;
            if ( v16 )
              v22 = 0x200000;
            *(_DWORD *)v41 = v22;
            *(_QWORD *)&v41[4] = 0i64;
            v45 = 0;
            v42 = v16;
            v44 = v2;
            v43 = 0;
            v18->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
              v18,
              (unsigned int)v41);
            v18 = result.pObject;
            v19 = v49.pObject;
          }
          v47 = 1;
        }
      }
      if ( (v20 & v12->PrevButtonsState) == 0 )
      {
LABEL_36:
        if ( (v20 & v12->CurButtonsState) != 0 )
        {
          if ( v19 )
          {
            ++v19->RefCount;
            v18 = result.pObject;
            v19 = v49.pObject;
          }
          if ( v13 )
          {
            Scaleform::RefCountNTSImpl::Release(v13);
            v18 = result.pObject;
            v19 = v49.pObject;
          }
          v13 = v19;
          v39 = v19;
          if ( v19 )
          {
            v23 = 1024;
            if ( v16 )
              v23 = 0x80000;
            *(_DWORD *)v41 = v23;
            *(_QWORD *)&v41[4] = 0i64;
            v45 = 0;
            v42 = v16;
            v44 = v2;
            v43 = 0;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _BYTE *, Scaleform::RefCountNTSImplCoreVtbl *, __int64))v19->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor)(
              v19,
              v41,
              v19->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr,
              v17);
            goto LABEL_72;
          }
          goto LABEL_73;
        }
      }
    }
    else if ( (v20 & v12->CurButtonsState) != 0 )
    {
      if ( (*((_BYTE *)v12 + 76) & 4) != 0 )
      {
        if ( v19 != v18 )
        {
          if ( v18 )
          {
            RollOverCnt = v18->RollOverCnt;
            if ( RollOverCnt )
            {
              v27 = RollOverCnt - 1;
              v18->RollOverCnt = RollOverCnt - 1;
            }
            else
            {
              v27 = -1;
            }
            v28 = 0x10000;
            if ( v16 )
              v28 = 0x800000;
            *(_DWORD *)v41 = v28;
            *(_QWORD *)&v41[4] = 0i64;
            v45 = 0;
            v42 = v16;
            v44 = v2;
            v43 = v27;
            v18->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
              v18,
              (unsigned int)v41);
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
          *(_DWORD *)v41 = v25;
          *(_QWORD *)&v41[4] = 0i64;
          v45 = 0;
          v42 = v16;
          v44 = v2;
          v43 = v24;
          v18->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            v18,
            (unsigned int)v41);
          v18 = result.pObject;
          v19 = v49.pObject;
        }
        v15 = 1;
      }
      if ( (!v18 || (v18->Flags & 0x4000) != 0) && v19 && v19 != v18 && (v19->Flags & 0x4000) != 0 )
      {
        ++v19->RefCount;
        if ( v13 )
          Scaleform::RefCountNTSImpl::Release(v13);
        v13 = v49.pObject;
        v39 = v49.pObject;
        v29 = v49.pObject->RollOverCnt;
        v49.pObject->RollOverCnt = v29 + 1;
        v30 = 0x8000;
        if ( v16 )
          v30 = 0x400000;
        *(_DWORD *)v41 = v30;
        *(_QWORD *)&v41[4] = 0i64;
        v45 = 0;
        v42 = v16;
        v44 = v2;
        v43 = v29;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _BYTE *, Scaleform::GFx::InteractiveObject *, __int64))v13->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor)(
          v13,
          v41,
          v18,
          v17);
LABEL_72:
        v18 = result.pObject;
        v19 = v49.pObject;
LABEL_73:
        v15 = 1;
      }
    }
    ++v16;
    v17 = 0xFFFFFFFFi64;
    v14 = v48;
  }
  while ( v16 < v46 );
  v31 = 0xFFFFFFFFi64;
  if ( (v12->PrevButtonsState & 1) == 0 && v19 != v18 )
  {
    if ( !v47 && v18 )
    {
      v32 = v18->RollOverCnt;
      if ( v32 )
      {
        LOBYTE(v31) = v32 - 1;
        v18->RollOverCnt = v32 - 1;
      }
      *(_QWORD *)v41 = 0x4000i64;
      *(_DWORD *)&v41[8] = 0;
      v45 = 0;
      v42 = 0;
      v44 = v2;
      v43 = v31;
      v18->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
        v18,
        (unsigned int)v41);
      v19 = v49.pObject;
    }
    if ( v19 )
    {
      ++v19->RefCount;
      v19 = v49.pObject;
    }
    if ( v13 )
    {
      Scaleform::RefCountNTSImpl::Release(v13);
      v19 = v49.pObject;
    }
    v13 = v19;
    v39 = v19;
    if ( v19 )
    {
      v33 = v19->RollOverCnt;
      v19->RollOverCnt = v33 + 1;
      *(_QWORD *)v41 = 0x2000i64;
      *(_DWORD *)&v41[8] = 0;
      v45 = 0;
      v42 = 0;
      v44 = v2;
      v43 = v33;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, _BYTE *, Scaleform::RefCountNTSImplCoreVtbl *, __int64))v19->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor)(
        v19,
        v41,
        v19->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr,
        v31);
    }
    v15 = 1;
  }
  *((_BYTE *)v12 + 76) &= ~4u;
  *((_BYTE *)v12 + 76) |= 4 * v15;
  if ( v13 )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(v13);
    v35 = v12->ActiveEntity.pProxy.pObject;
    if ( v35 )
    {
      v36 = v35->RefCount-- == 1;
      if ( v36 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v12->ActiveEntity.pProxy.pObject = WeakProxy;
  }
  else
  {
    v37 = v12->ActiveEntity.pProxy.pObject;
    if ( v37 )
    {
      v36 = v37->RefCount-- == 1;
      if ( v36 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::WeakPtrProxy *, Scaleform::GFx::InteractiveObject *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v37,
          v18,
          v31);
    }
    v12->ActiveEntity.pProxy.pObject = 0i64;
  }
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
  if ( v49.pObject )
    Scaleform::RefCountNTSImpl::Release(v49.pObject);
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
}

// File Line: 317
// RVA: 0x71A0F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetMemoryParams(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount)
{
  Scaleform::GFx::AS2::ASRefCountCollector *pObject; // rcx
  unsigned int v4; // eax

  pObject = this->MemContext.pObject->ASGC.pObject;
  v4 = 0;
  if ( frameBetweenCollections != -1 )
    v4 = frameBetweenCollections;
  pObject->MaxFramesBetweenCollections = v4;
  if ( maxRootCount == -1 )
  {
    pObject->MaxRootCount = 1000;
    pObject->PresetMaxRootCount = 1000;
  }
  else
  {
    pObject->MaxRootCount = maxRootCount;
    pObject->PresetMaxRootCount = maxRootCount;
  }
}

// File Line: 330
// RVA: 0x6E11A0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateSprite(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::TimelineDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::InteractiveObject *parent,
        int *id,
        bool loadedSeparately)
{
  Scaleform::GFx::ASSupport *pObject; // r10
  int v7; // edx
  Scaleform::GFx::Sprite *v8; // rbx
  _QWORD v10[5]; // [rsp+30h] [rbp-28h] BYREF

  pObject = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  v10[0] = pdef;
  v7 = *id;
  v10[1] = pdefImpl;
  v10[2] = 0i64;
  LODWORD(id) = v7;
  v8 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, _QWORD *, Scaleform::GFx::InteractiveObject *, int **, int))pObject->vfptr[4].__vecDelDtor)(
                                   pObject,
                                   this->pMovieImpl,
                                   v10,
                                   parent,
                                   &id,
                                   3);
  Scaleform::GFx::Sprite::SetLoadedSeparately(v8, loadedSeparately);
  return v8;
}

// File Line: 341
// RVA: 0x6E2650
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoActions(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v3; // [rsp+28h] [rbp-30h] BYREF

  v3.pActionQueue = &this->ActionQueue;
  v3.ModId = 0;
  v3.CurrentPrio = 0;
  v3.pLastEntry = 0i64;
  for ( i = Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v3);
        i;
        i = Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v3) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( v3.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v3.pActionQueue, v3.pLastEntry);
}

// File Line: 355
// RVA: 0x6E26D0
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int sessionId)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator v4; // [rsp+28h] [rbp-30h] BYREF

  v4.pActionQueue = &this->ActionQueue;
  v4.ModId = 0;
  v4.CurrentPrio = 0;
  v4.pLastEntry = 0i64;
  v4.SessionId = sessionId;
  for ( i = Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4);
        i;
        i = Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( v4.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
}

// File Line: 367
// RVA: 0x70FC50
void __fastcall Scaleform::GFx::AS2::MovieRoot::RegisterAuxASClasses(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::GlobalContext *pObject; // rcx
  Scaleform::GFx::AS2::ASStringContext sc; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pGlobalContext.pObject;
  sc.SWFVersion = 8;
  sc.pContext = pObject;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<23,Scaleform::GFx::AS2::XmlCtorFunction>(
    pObject,
    &sc,
    pObject->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<24,Scaleform::GFx::AS2::XmlNodeCtorFunction>(
    this->pGlobalContext.pObject,
    &sc,
    this->pGlobalContext.pObject->pGlobal.pObject);
}

// File Line: 399
// RVA: 0x6EFCF0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
        Scaleform::GFx::AS2::MovieRoot *this,
        int level)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  unsigned int v3; // r8d
  unsigned __int64 Size; // r9
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  __int64 v6; // rax

  pMovieImpl = this->pMovieImpl;
  v3 = 0;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  v6 = 0i64;
  while ( Data[v6].Level != level )
  {
    v6 = ++v3;
    if ( v3 >= Size )
      return 0i64;
  }
  return (Scaleform::GFx::Sprite *)Data[v3].pSprite.pObject;
}

// File Line: 421
// RVA: 0x707BE0
int __fastcall Scaleform::GFx::AS2::MovieRoot::ParseLevelName(const char *pname, char **ptail, bool caseSensitive)
{
  int result; // eax
  char v5; // al
  const char *v6; // rcx
  char *endptr; // [rsp+30h] [rbp+8h] BYREF
  char *v8; // [rsp+48h] [rbp+20h] BYREF

  if ( (unsigned __int8)(*pname - 48) <= 9u )
  {
    endptr = 0i64;
    result = strtol(pname, &endptr, 10);
    *ptail = endptr;
    return result;
  }
  if ( *pname != 95 )
    return -1;
  if ( caseSensitive )
  {
    if ( pname[1] != 108 || pname[2] != 101 || pname[3] != 118 || pname[4] != 101 || pname[5] != 108 )
      return -1;
  }
  else if ( ((pname[1] - 76) & 0xDF) != 0
         || ((pname[2] - 69) & 0xDF) != 0
         || ((pname[3] - 86) & 0xDF) != 0
         || ((pname[4] - 69) & 0xDF) != 0
         || ((pname[5] - 76) & 0xDF) != 0 )
  {
    return -1;
  }
  v5 = pname[6];
  v6 = pname + 6;
  if ( (unsigned __int8)(v5 - 48) > 9u )
    return -1;
  v8 = 0i64;
  result = strtol(v6, &v8, 10);
  *ptail = v8;
  return result;
}

// File Line: 475
// RVA: 0x6D0C10
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::~ActionQueueType(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pFreeEntry; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pNextEntry; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v4; // [rsp+28h] [rbp-30h] BYREF

  v4.pActionQueue = this;
  v4.ModId = 0;
  v4.CurrentPrio = 0;
  v4.pLastEntry = 0i64;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v4) )
    ;
  if ( v4.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
  pFreeEntry = this->pFreeEntry;
  if ( pFreeEntry )
  {
    do
    {
      pNextEntry = pFreeEntry->pNextEntry;
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(pFreeEntry);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pFreeEntry);
      pFreeEntry = pNextEntry;
    }
    while ( pNextEntry );
  }
}

// File Line: 488
// RVA: 0x6FD8A0
Scaleform::GFx::AS2::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  __int64 v2; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pFreeEntry; // rbx
  __int64 v5; // rax
  Scaleform::RefCountNTSImpl *v6; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueEntry *v8; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry **p_pNextEntry; // rax

  v2 = prio;
  pFreeEntry = this->pFreeEntry;
  if ( pFreeEntry )
  {
    this->pFreeEntry = pFreeEntry->pNextEntry;
    pFreeEntry->pNextEntry = 0i64;
    --this->FreeEntriesCount;
  }
  else
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot::ActionQueueType *, __int64))this->pHeap->vfptr->Alloc)(
           this,
           120i64);
    pFreeEntry = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)v5;
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
      *(_QWORD *)(v5 + 88) = 0i64;
      *(_QWORD *)(v5 + 96) = 0i64;
      *(_QWORD *)(v5 + 104) = 0i64;
      *(_QWORD *)v5 = 0i64;
      *(_DWORD *)(v5 + 8) = 0;
      v6 = *(Scaleform::RefCountNTSImpl **)(v5 + 24);
      if ( v6 )
        Scaleform::RefCountNTSImpl::Release(v6);
      pFreeEntry->pActionBuffer.pObject = 0i64;
      pFreeEntry->SessionId = 0;
    }
    else
    {
      pFreeEntry = 0i64;
    }
    if ( !pFreeEntry )
      return 0i64;
  }
  v8 = &this->Entries[v2];
  p_pNextEntry = &v8->pInsertEntry->pNextEntry;
  if ( p_pNextEntry )
  {
    pFreeEntry->pNextEntry = *p_pNextEntry;
    v8->pInsertEntry->pNextEntry = pFreeEntry;
  }
  else
  {
    pFreeEntry->pNextEntry = v8->pActionRoot;
    v8->pActionRoot = pFreeEntry;
  }
  v8->pInsertEntry = pFreeEntry;
  if ( !pFreeEntry->pNextEntry )
    v8->pLastEntry = pFreeEntry;
  pFreeEntry->SessionId = this->CurrentSessionId;
  ++this->ModId;
  return pFreeEntry;
}

// File Line: 540
// RVA: 0x6D9880
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::AS2::MovieRoot::ActionEntry *pentry)
{
  Scaleform::GFx::AS2::ActionBuffer *pObject; // rcx
  Scaleform::GFx::InteractiveObject *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  bool v8; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v10; // eax

  pentry->Type = Entry_None;
  pObject = pentry->pActionBuffer.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  pentry->pActionBuffer.pObject = 0i64;
  v5 = pentry->pCharacter.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  pentry->pCharacter.pObject = 0i64;
  if ( (pentry->Function.Flags & 2) == 0 )
  {
    Function = pentry->Function.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v8 = (pentry->Function.Flags & 1) == 0;
  pentry->Function.Function = 0i64;
  if ( v8 )
  {
    pLocalFrame = pentry->Function.pLocalFrame;
    if ( pLocalFrame )
    {
      v10 = pLocalFrame->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  pentry->Function.pLocalFrame = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &pentry->FunctionParams.Data,
    0i64);
  if ( this->FreeEntriesCount >= 0x32 )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(pentry);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pentry);
  }
  else
  {
    pentry->pNextEntry = this->pFreeEntry;
    ++this->FreeEntriesCount;
    this->pFreeEntry = pentry;
  }
}

// File Line: 576
// RVA: 0x6D0BC0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::~ActionQueueIterator(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pLastEntry; // rdx

  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, pLastEntry);
}

// File Line: 582
// RVA: 0x725080
Scaleform::GFx::AS2::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *pActionQueue; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pActionRoot; // rdi
  __int64 v4; // rax
  __int64 CurrentPrio; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v6; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pLastEntry; // rdx

  pActionQueue = this->pActionQueue;
  if ( pActionQueue->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = pActionQueue->ModId;
  }
  pActionRoot = pActionQueue->Entries[this->CurrentPrio].pActionRoot;
  if ( pActionRoot )
  {
LABEL_8:
    CurrentPrio = this->CurrentPrio;
    if ( pActionRoot == pActionQueue->Entries[CurrentPrio].pInsertEntry )
      pActionQueue->Entries[CurrentPrio].pInsertEntry = pActionRoot->pNextEntry;
    this->pActionQueue->Entries[this->CurrentPrio].pActionRoot = pActionRoot->pNextEntry;
    pActionRoot->pNextEntry = 0i64;
  }
  else
  {
    while ( 1 )
    {
      v4 = ++this->CurrentPrio;
      if ( (int)v4 >= 6 )
        break;
      pActionRoot = pActionQueue->Entries[v4].pActionRoot;
      if ( pActionRoot )
        goto LABEL_8;
    }
  }
  v6 = this->pActionQueue;
  if ( !v6->Entries[this->CurrentPrio].pActionRoot )
  {
    v6->Entries[this->CurrentPrio].pInsertEntry = 0i64;
    this->pActionQueue->Entries[this->CurrentPrio].pLastEntry = 0i64;
  }
  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, pLastEntry);
  this->pLastEntry = pActionRoot;
  return pActionRoot;
}

// File Line: 621
// RVA: 0x725160
Scaleform::GFx::AS2::MovieRoot::ActionEntry *__fastcall Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *pActionQueue; // r8
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pActionRoot; // rbx
  __int64 CurrentPrio; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v5; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueEntry *v6; // r8
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pNextEntry; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pLastEntry; // rdx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *result; // rax

  pActionQueue = this->pActionQueue;
  if ( pActionQueue->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = pActionQueue->ModId;
  }
  pActionRoot = 0i64;
  if ( this->CurrentPrio < 6 )
  {
    while ( 1 )
    {
      CurrentPrio = this->CurrentPrio;
      v5 = 0i64;
      pActionRoot = pActionQueue->Entries[CurrentPrio].pActionRoot;
      if ( pActionRoot )
        break;
LABEL_7:
      this->CurrentPrio = CurrentPrio + 1;
      if ( (int)CurrentPrio + 1 >= 6 )
        goto LABEL_19;
    }
    while ( pActionRoot->SessionId != this->SessionId )
    {
      v5 = pActionRoot;
      pActionRoot = pActionRoot->pNextEntry;
      if ( !pActionRoot )
        goto LABEL_7;
    }
    if ( v5 )
      v5->pNextEntry = pActionRoot->pNextEntry;
    else
      pActionQueue->Entries[this->CurrentPrio].pActionRoot = pActionRoot->pNextEntry;
    if ( !pActionRoot->pNextEntry )
      this->pActionQueue->Entries[this->CurrentPrio].pLastEntry = v5;
    v6 = &this->pActionQueue->Entries[this->CurrentPrio];
    if ( pActionRoot == v6->pInsertEntry )
    {
      pNextEntry = pActionRoot->pNextEntry;
      if ( !pActionRoot->pNextEntry )
        pNextEntry = v5;
      v6->pInsertEntry = pNextEntry;
    }
    pActionRoot->pNextEntry = 0i64;
  }
LABEL_19:
  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, pLastEntry);
  result = pActionRoot;
  this->pLastEntry = pActionRoot;
  return result;
}

// File Line: 673
// RVA: 0x6E7B10
void __fastcall Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
        Scaleform::GFx::AS2::MovieRoot::ActionEntry *this,
        Scaleform::GFx::AS2::MovieRoot *proot)
{
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  char *v4; // rcx
  __int64 v5; // rax
  char *v6; // rcx
  __int64 v7; // rax
  char *v8; // rcx
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax

  pObject = this->pCharacter.pObject;
  if ( pObject && (pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    switch ( this->Type )
    {
      case Entry_Buffer:
        v10 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
        v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 8i64))(v10);
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ActionBuffer *))(*(_QWORD *)v11 + 288i64))(
          v11,
          this->pActionBuffer.pObject);
        break;
      case Entry_Event:
        v8 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
        v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 8i64))(v8);
        (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v9 + 296i64))(v9, &this->mEventId);
        break;
      case Entry_Function:
        v6 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
        v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 8i64))(v6);
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::FunctionRef *, Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v7 + 304i64))(
          v7,
          &this->Function,
          &this->FunctionParams);
        break;
      case Entry_CFunction:
        v4 = (char *)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
        v5 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v4 + 8i64))(v4);
        (*(void (__fastcall **)(__int64, void (__fastcall *)(Scaleform::GFx::AS2::FnCall *), Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v5 + 312i64))(
          v5,
          this->CFunction,
          &this->FunctionParams);
        break;
    }
  }
}

// File Line: 705
// RVA: 0x6E0060
Scaleform::GFx::MovieDefRootNode *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateMovieDefRootNode(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::MemoryHeap *pheap,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        bool importFlag)
{
  Scaleform::GFx::MovieDefRootNode *result; // rax

  result = (Scaleform::GFx::MovieDefRootNode *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pheap->vfptr->Alloc)(
                                                 pheap,
                                                 64i64);
  if ( !result )
    return 0i64;
  result->vfptr = (Scaleform::GFx::MovieDefRootNodeVtbl *)&Scaleform::GFx::MovieDefRootNode::`vftable;
  result->SpriteRefCount = 1;
  result->pDefImpl = pdefImpl;
  result->ImportFlag = importFlag;
  result->pFontManager.pObject = 0i64;
  return result;
}

// File Line: 710
// RVA: 0x6DDB30
void __fastcall Scaleform::GFx::AS2::MovieRoot::ClearDisplayList(Scaleform::GFx::AS2::MovieRoot *this)
{
  unsigned __int64 Size; // rsi
  unsigned __int64 v3; // rdi
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  Scaleform::GFx::InteractiveObject *v7; // rcx

  Size = this->pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v3 = Size;
    do
    {
      pObject = this->pMovieImpl->MovieLevels.Data.Data[v3 - 1].pSprite.pObject;
      Scaleform::GFx::DisplayList::Clear((Scaleform::GFx::DisplayList *)&pObject[1], pObject);
      _((AMD_HD3D *)pObject);
      --v3;
      --Size;
    }
    while ( Size );
  }
  v5 = this->pMovieImpl->MovieLevels.Data.Size;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      v7 = this->pMovieImpl->MovieLevels.Data.Data[v6 - 1].pSprite.pObject;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[60].__vecDelDtor)(v7);
      --v6;
      --v5;
    }
    while ( v5 );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::MovieImpl::LevelInfo,Scaleform::AllocatorLH<Scaleform::GFx::MovieImpl::LevelInfo,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->pMovieImpl->MovieLevels.Data,
    &this->pMovieImpl->MovieLevels,
    0i64);
}

// File Line: 727
// RVA: 0x6D8E60
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry::LoadType Type; // eax
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
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // r9
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // rdx
  Scaleform::GFx::LoadQueueEntry *v20; // rcx
  Scaleform::GFx::LoadQueueEntry *pNext; // rax
  Scaleform::GFx::LoadQueueEntry *v22; // r8
  bool v23; // zf
  int vfptr; // eax

  Type = pentry->Type;
  if ( (Type & 4) != 0 )
  {
    v5 = (Scaleform::GFx::LoadQueueEntryMT_LoadVars *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                        this,
                                                        56i64);
    if ( v5 )
    {
      Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(v5, pentry, this->pMovieImpl);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    goto LABEL_32;
  }
  if ( (Type & 8) == 0 )
  {
    if ( (Type & 0x10) != 0 )
      goto LABEL_34;
    v16 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                                     this,
                                                                     88i64);
    if ( v16 )
    {
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(
        v16,
        pentry,
        this->pMovieImpl);
      v7 = v17;
    }
    else
    {
      v7 = 0i64;
    }
    if ( !v7 )
      goto LABEL_34;
    pQueueEntry = v7->pQueueEntry;
    pLoadQueueMTHead = this->pMovieImpl->pLoadQueueMTHead;
    if ( !pLoadQueueMTHead )
      goto LABEL_32;
    while ( 1 )
    {
      v20 = pLoadQueueMTHead->pQueueEntry;
      pNext = pQueueEntry[1].pNext;
      if ( pNext )
      {
        v22 = v20[1].pNext;
        if ( v22 )
        {
          v23 = v22->URL.HeapTypeBits == pNext->URL.HeapTypeBits;
          goto LABEL_29;
        }
      }
      else
      {
        vfptr = (int)v20[1].vfptr;
        if ( vfptr != -1 )
        {
          v23 = vfptr == LODWORD(pQueueEntry[1].vfptr);
LABEL_29:
          if ( v23 )
            v20->Canceled = 1;
        }
      }
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      if ( !pLoadQueueMTHead )
        goto LABEL_32;
    }
  }
  if ( !Scaleform::String::GetLength(&pentry->URL) )
    goto LABEL_34;
  v9 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *)((__int64 (__fastcall *)(__int64, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                                v8,
                                                                64i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(v9, pentry, this);
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
    for ( i = this->pMovieImpl->pLoadQueueMTHead; i; i = i->pNext )
    {
      v14 = i->pQueueEntry;
      v15 = (char)v14[3].vfptr;
      if ( v15 && v15 != 10 && v12 == Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&v14[3], 0i64) )
        v14->Canceled = 1;
    }
  }
LABEL_32:
  if ( v7 )
  {
    Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(this->pMovieImpl, v7);
    return;
  }
LABEL_34:
  pentry->vfptr->__vecDelDtor(pentry, 1i64);
}

// File Line: 811
// RVA: 0x6D8BB0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *ptarget,
        const char *purl,
        Scaleform::GFx::AS2::Environment *env,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  __int64 v10; // rdi
  Scaleform::GFx::AS2::StringManager *p_BuiltinsMgr; // rcx
  Scaleform::GFx::ASString *v12; // rax
  char v13; // bl
  Scaleform::GFx::InteractiveObject *Target; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::DisplayObject *v16; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::DisplayObject *v20; // rcx
  __int64 v21; // rcx
  int v22; // r14d
  char *v23; // r14
  Scaleform::GFx::CharacterHandle *pObject; // rax
  __int64 v25; // rax
  Scaleform::String::DataDesc *pData; // rdx
  unsigned int v27; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // rdx
  __int64 v30; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::DisplayObjectBase *v32; // rcx
  unsigned int Version; // eax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v34; // rsi
  __int64 v35; // rax
  char *ptail; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::String v37; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v38; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp-20h] BYREF
  __int64 v40; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v41; // [rsp+60h] [rbp-10h]
  Scaleform::String url; // [rsp+B8h] [rbp+48h] BYREF

  v40 = -2i64;
  v10 = 0i64;
  p_BuiltinsMgr = &this->BuiltinsMgr;
  if ( env )
  {
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
            p_BuiltinsMgr,
            &result,
            ptarget);
    v13 = 1;
    Target = Scaleform::GFx::AS2::Environment::FindTarget(env, v12, 0);
  }
  else
  {
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
            p_BuiltinsMgr,
            &v38,
            ptarget);
    v13 = 2;
    Target = (Scaleform::GFx::InteractiveObject *)this->vfptr[8].__vecDelDtor(this, v15);
  }
  v16 = Target;
  if ( (v13 & 2) != 0 )
  {
    v13 &= ~2u;
    pNode = v38.pNode;
    v18 = v38.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( (v13 & 1) != 0 )
  {
    v13 &= ~1u;
    v19 = result.pNode;
    v18 = result.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( v16 )
  {
    v20 = 0i64;
    if ( (v16->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      v20 = v16;
    if ( !v20
      || (v21 = (__int64)(&v20->Id + (unsigned __int8)v20->AvmObjOffset),
          v22 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 240i64))(v21),
          v22 == -1) )
    {
      v37.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
      v23 = (char *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, __int64, _QWORD))(*(_QWORD *)v37.HeapTypeBits
                                                                                                + 80i64))(
                      v20,
                      160i64,
                      0i64);
      ptail = v23;
      if ( v23 )
      {
        Scaleform::String::String(&url, purl);
        v13 |= 4u;
        pObject = v16->pNameHandle.pObject;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v16);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v23,
          pObject,
          &url,
          method,
          0,
          0);
        v10 = v25;
      }
      if ( (v13 & 4) == 0 )
        goto LABEL_36;
      pData = url.pData;
LABEL_34:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_36:
      if ( v10 )
      {
        Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v10 + 56), pmovieClipLoader);
        Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(this, (Scaleform::GFx::LoadQueueEntry *)v10);
      }
      return;
    }
LABEL_30:
    url.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
    v34 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, __int64, _QWORD))(*(_QWORD *)url.HeapTypeBits + 80i64))(
                                                         v20,
                                                         160i64,
                                                         0i64);
    v41 = v34;
    if ( v34 )
    {
      Scaleform::String::String(&v37, purl);
      v13 |= 8u;
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v34, v22, &v37, method, 0, 0);
      v10 = v35;
    }
    if ( (v13 & 8) == 0 )
      goto LABEL_36;
    pData = v37.pData;
    goto LABEL_34;
  }
  ptail = &customCaption;
  v27 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v30 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v30].Level )
    {
      v30 = ++v27;
      if ( v27 >= Size )
        goto LABEL_27;
    }
    v32 = Data[v27].pSprite.pObject;
  }
  else
  {
LABEL_27:
    v32 = 0i64;
  }
  Version = Scaleform::GFx::DisplayObjectBase::GetVersion(v32);
  v22 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(ptarget, (const char **)&ptail, Version > 6);
  if ( !*ptail && v22 != -1 )
    goto LABEL_30;
}

// File Line: 866
// RVA: 0x6D9D20
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *ptarget,
        const char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::LoadQueueEntry *v8; // rdi
  char v9; // si
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::DisplayObject *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::DisplayObject *v14; // rcx
  __int64 v15; // rcx
  int v16; // ebp
  Scaleform::String::DataDesc *v17; // rbp
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::LoadQueueEntry *v19; // rax
  Scaleform::String::DataDesc *pData; // rdx
  unsigned int v21; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // rdx
  __int64 v24; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::DisplayObjectBase *v26; // rcx
  unsigned int Version; // eax
  __int64 v28; // r14
  Scaleform::GFx::CharacterHandle *v29; // rbx
  Scaleform::GFx::TaskManager *v30; // rbx
  char *ptail; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::String src; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::ASStringNode *v33; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+50h] [rbp-48h] BYREF
  __int64 v35; // [rsp+58h] [rbp-40h]
  __int64 v36; // [rsp+60h] [rbp-38h]
  Scaleform::String url; // [rsp+A0h] [rbp+8h] BYREF

  v35 = -2i64;
  v8 = 0i64;
  v9 = 0;
  String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
             &this->BuiltinsMgr,
             (Scaleform::GFx::ASString *)&v33,
             ptarget);
  v11 = (Scaleform::GFx::DisplayObject *)this->vfptr[8].__vecDelDtor(this, String);
  v12 = v33;
  if ( v33->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v11 )
  {
    v14 = 0i64;
    if ( (v11->Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
      v14 = v11;
    if ( !v14
      || (v15 = (__int64)(&v14->Id + (unsigned __int8)v14->AvmObjOffset),
          v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 240i64))(v15),
          v16 == -1) )
    {
      result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
      v17 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                             v14,
                                             160i64,
                                             0i64);
      src.pData = v17;
      if ( v17 )
      {
        Scaleform::String::String(&url, purl);
        v9 = 1;
        pObject = v11->pNameHandle.pObject;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v11);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
          (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v17,
          pObject,
          &url,
          method,
          1,
          0);
        v8 = v19;
      }
      if ( (v9 & 1) == 0 )
        goto LABEL_32;
      pData = url.pData;
LABEL_30:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_32:
      if ( v8 )
      {
        v30 = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
        if ( result.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
        if ( v30 )
          Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, v8);
        else
          Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v8);
      }
      return;
    }
LABEL_23:
    url.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
    v28 = (*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, __int64, _QWORD))(*(_QWORD *)url.HeapTypeBits
                                                                                      + 80i64))(
            v14,
            160i64,
            0i64);
    result.pObject = (Scaleform::GFx::TaskManager *)v28;
    if ( v28 )
    {
      Scaleform::String::String(&src, purl);
      v9 = 2;
      *(_QWORD *)v28 = &Scaleform::GFx::LoadQueueEntry::`vftable;
      Scaleform::String::String((Scaleform::String *)(v28 + 24));
      *(_DWORD *)(v28 + 16) = 4;
      *(_DWORD *)(v28 + 20) = method;
      *(_QWORD *)(v28 + 8) = 0i64;
      Scaleform::String::operator=((Scaleform::String *)(v28 + 24), &src);
      *(_DWORD *)(v28 + 32) = -1;
      *(_WORD *)(v28 + 36) = 0;
      *(_QWORD *)v28 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable;
      *(_QWORD *)(v28 + 48) = 0i64;
      *(_BYTE *)(v28 + 56) = 0;
      *(_BYTE *)(v28 + 88) = 0;
      v36 = v28 + 120;
      *(_BYTE *)(v28 + 120) = 0;
      *(_QWORD *)(v28 + 152) = 0i64;
      v29 = *(Scaleform::GFx::CharacterHandle **)(v28 + 48);
      if ( v29 )
      {
        if ( --v29->RefCount <= 0 )
        {
          Scaleform::GFx::CharacterHandle::~CharacterHandle(v29);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v29);
        }
      }
      *(_QWORD *)(v28 + 48) = 0i64;
      *(_DWORD *)(v28 + 40) = v16;
      *(_DWORD *)(v28 + 16) = 6;
      v8 = (Scaleform::GFx::LoadQueueEntry *)v28;
    }
    if ( (v9 & 2) == 0 )
      goto LABEL_32;
    pData = src.pData;
    goto LABEL_30;
  }
  ptail = &customCaption;
  v21 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v24 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v24].Level )
    {
      v24 = ++v21;
      if ( v21 >= Size )
        goto LABEL_20;
    }
    v26 = Data[v21].pSprite.pObject;
  }
  else
  {
LABEL_20:
    v26 = 0i64;
  }
  Version = Scaleform::GFx::DisplayObjectBase::GetVersion(v26);
  v16 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(ptarget, (const char **)&ptail, Version > 6);
  if ( !*ptail && v16 != -1 )
    goto LABEL_23;
}

// File Line: 924
// RVA: 0x6D89E0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ptargetChar,
        const char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader)
{
  char v9; // bl
  __int16 v10; // ax
  Scaleform::GFx::InteractiveObject *v11; // rdx
  Scaleform::GFx::ResourceId *v12; // rcx
  int v13; // esi
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v14; // rdi
  __int64 v15; // rax
  __int64 v16; // rdi
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v18; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  __int64 v20; // rax
  Scaleform::String v21; // [rsp+38h] [rbp-30h] BYREF
  __int64 v22; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *v23; // [rsp+48h] [rbp-20h]
  Scaleform::String url; // [rsp+78h] [rbp+10h] BYREF

  if ( ptargetChar )
  {
    v22 = -2i64;
    v9 = 0;
    v10 = ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags >> 10;
    v11 = 0i64;
    if ( (v10 & 1) != 0 )
      v11 = ptargetChar;
    if ( !v11
      || (v12 = &v11->Id + (unsigned __int8)v11->AvmObjOffset,
          v13 = (*(__int64 (__fastcall **)(Scaleform::GFx::ResourceId *))(*(_QWORD *)&v12->Id + 240i64))(v12),
          v13 == -1) )
    {
      url.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
      v18 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))(*(_QWORD *)url.HeapTypeBits + 80i64))(
                                                           this,
                                                           160i64,
                                                           0i64);
      v23 = v18;
      if ( v18 )
      {
        Scaleform::String::String(&v21, purl);
        v9 = 1;
        pObject = ptargetChar->pNameHandle.pObject;
        if ( !pObject )
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptargetChar);
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v18, pObject, &v21, method, 0, 0);
        v16 = v20;
      }
      else
      {
        v16 = 0i64;
      }
      if ( (v9 & 1) == 0 )
        goto LABEL_20;
      pData = v21.pData;
    }
    else
    {
      v21.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
      v14 = (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))(*(_QWORD *)v21.HeapTypeBits + 80i64))(
                                                           this,
                                                           160i64,
                                                           0i64);
      v23 = v14;
      if ( v14 )
      {
        Scaleform::String::String(&url, purl);
        v9 = 2;
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(v14, v13, &url, method, 0, 0);
        v16 = v15;
      }
      else
      {
        v16 = 0i64;
      }
      if ( (v9 & 2) == 0 )
        goto LABEL_20;
      pData = url.pData;
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_20:
    if ( v16 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v16 + 56), pmovieClipLoader);
      Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(this, (Scaleform::GFx::LoadQueueEntry *)v16);
    }
  }
}

// File Line: 961
// RVA: 0x6D90F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::TaskManager *v4; // rbx
  bool IsProtocolImage; // bp
  Scaleform::GFx::TaskManager *v6; // rbp
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::LoaderImpl *pObject; // rbx
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::TaskManager *v10; // rax
  bool v11; // bp
  bool sync; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+60h] [rbp+18h] BYREF

  if ( pentry )
  {
    v4 = 0i64;
    IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&pentry->URL, 0i64, &sync);
    if ( IsProtocolImage && sync )
    {
      v6 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            144i64,
                                            0i64);
      result.pObject = v6;
      if ( v6 )
      {
        pMovieImpl = this->pMovieImpl;
        pObject = pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
        v9 = (Scaleform::GFx::StateBag *)pMovieImpl->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
        Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, pObject, v9, 0i64);
        v4 = v10;
      }
      result.pObject = v4;
      ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::TaskManager *))this->vfptr[35].__vecDelDtor)(
        this,
        pentry,
        v4);
      pentry->vfptr->__vecDelDtor(pentry, 1i64);
      if ( v4 )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
    }
    else
    {
      v11 = 0;
      if ( Scaleform::String::GetLength(&pentry->URL) )
      {
        if ( !IsProtocolImage )
        {
          LOBYTE(v4) = 1;
          if ( Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject )
            v11 = 1;
        }
      }
      if ( ((unsigned __int8)v4 & 1) != 0 && result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      if ( v11 )
        Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, pentry);
      else
        Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, pentry);
    }
  }
}

// File Line: 991
// RVA: 0x6D9970
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ptargetChar,
        const char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v8; // bl
  __int16 v9; // ax
  Scaleform::GFx::InteractiveObject *v10; // rdx
  Scaleform::GFx::ResourceId *v11; // rcx
  int v12; // r14d
  Scaleform::String::DataDesc *v13; // rdi
  Scaleform::GFx::LoadQueueEntry *v14; // rax
  Scaleform::GFx::LoadQueueEntry *v15; // rdi
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::GFx::TaskManager *v17; // r14
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::LoadQueueEntry *v19; // rax
  Scaleform::GFx::TaskManager *v20; // rbx
  Scaleform::String v21; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+40h] [rbp-28h] BYREF
  __int64 v23; // [rsp+48h] [rbp-20h]
  Scaleform::String url; // [rsp+78h] [rbp+10h] BYREF

  if ( !ptargetChar )
    return;
  v23 = -2i64;
  v8 = 0;
  v9 = ptargetChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags >> 10;
  v10 = 0i64;
  if ( (v9 & 1) != 0 )
    v10 = ptargetChar;
  if ( !v10
    || (v11 = &v10->Id + (unsigned __int8)v10->AvmObjOffset,
        v12 = (*(__int64 (__fastcall **)(Scaleform::GFx::ResourceId *))(*(_QWORD *)&v11->Id + 240i64))(v11),
        v12 == -1) )
  {
    url.pData = (Scaleform::String::DataDesc *)this->pMovieImpl->pHeap;
    v17 = (Scaleform::GFx::TaskManager *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))(*(_QWORD *)url.HeapTypeBits + 80i64))(
                                           this,
                                           160i64,
                                           0i64);
    result.pObject = v17;
    if ( v17 )
    {
      Scaleform::String::String(&v21, purl);
      v8 = 1;
      pObject = ptargetChar->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptargetChar);
      Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
        (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v17,
        pObject,
        &v21,
        method,
        1,
        0);
      v15 = v19;
    }
    else
    {
      v15 = 0i64;
    }
    if ( (v8 & 1) == 0 )
      goto LABEL_20;
    pData = v21.pData;
    goto LABEL_18;
  }
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v13 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
                                         this,
                                         160i64,
                                         0i64);
  v21.pData = v13;
  if ( v13 )
  {
    Scaleform::String::String(&url, purl);
    v8 = 2;
    Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(
      (Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *)v13,
      v12,
      &url,
      method,
      1,
      0);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  if ( (v8 & 2) != 0 )
  {
    pData = url.pData;
LABEL_18:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
LABEL_20:
  if ( v15 )
  {
    v20 = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v20 )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, v15);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v15);
  }
}

// File Line: 1036
// RVA: 0x6D9B60
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::LoadVarsObject *ploadVars,
        const char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v8; // bp
  __int64 v9; // rsi
  Scaleform::GFx::CharacterHandle *v10; // rdi
  Scaleform::GFx::TaskManager *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+28h] [rbp-50h] BYREF
  __int64 v13; // [rsp+30h] [rbp-48h]
  __int64 v14; // [rsp+38h] [rbp-40h]
  __int64 v15; // [rsp+40h] [rbp-38h]
  Scaleform::String src; // [rsp+80h] [rbp+8h] BYREF

  v13 = -2i64;
  v8 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
         this,
         160i64,
         0i64);
  v14 = v9;
  if ( v9 )
  {
    Scaleform::String::String(&src, purl);
    v8 = 1;
    *(_QWORD *)v9 = &Scaleform::GFx::LoadQueueEntry::`vftable;
    Scaleform::String::String((Scaleform::String *)(v9 + 24));
    *(_DWORD *)(v9 + 16) = 4;
    *(_DWORD *)(v9 + 20) = method;
    *(_QWORD *)(v9 + 8) = 0i64;
    Scaleform::String::operator=((Scaleform::String *)(v9 + 24), &src);
    *(_DWORD *)(v9 + 32) = -1;
    *(_WORD *)(v9 + 36) = 0;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable;
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
  if ( (v8 & 1) != 0
    && !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( v9 )
  {
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v9 + 88), ploadVars);
    pObject = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( pObject )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::LoadQueueEntry *)v9);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v9);
  }
}

// File Line: 1079
// RVA: 0x6DA050
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddXmlLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::AS2::Object *pxmlobj,
        Scaleform::GFx::Resource *pxmlLoader,
        const char *purl,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  char v9; // bp
  __int64 v10; // rsi
  Scaleform::GFx::CharacterHandle *v11; // rdi
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::TaskManager *pObject; // rbx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+28h] [rbp-50h] BYREF
  __int64 v15; // [rsp+30h] [rbp-48h]
  __int64 v16; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+40h] [rbp-38h]
  Scaleform::String src; // [rsp+80h] [rbp+8h] BYREF

  v15 = -2i64;
  v9 = 0;
  result.pObject = (Scaleform::GFx::TaskManager *)this->pMovieImpl->pHeap;
  v10 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, __int64, _QWORD))result.pObject->vfptr[10].__vecDelDtor)(
          this,
          160i64,
          0i64);
  v16 = v10;
  if ( v10 )
  {
    Scaleform::String::String(&src, purl);
    v9 = 1;
    *(_QWORD *)v10 = &Scaleform::GFx::LoadQueueEntry::`vftable;
    Scaleform::String::String((Scaleform::String *)(v10 + 24));
    *(_DWORD *)(v10 + 16) = (src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
    *(_DWORD *)(v10 + 20) = method;
    *(_QWORD *)(v10 + 8) = 0i64;
    Scaleform::String::operator=((Scaleform::String *)(v10 + 24), &src);
    *(_DWORD *)(v10 + 32) = -1;
    *(_WORD *)(v10 + 36) = 0;
    *(_QWORD *)v10 = &Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vftable;
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
  if ( (v9 & 1) != 0
    && !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( v10 )
  {
    *(_DWORD *)(v10 + 16) = 8;
    Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)(v10 + 120), pxmlobj);
    if ( pxmlLoader )
      Scaleform::Render::RenderBuffer::AddRef(pxmlLoader);
    v12 = *(Scaleform::Render::RenderBuffer **)(v10 + 152);
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    *(_QWORD *)(v10 + 152) = pxmlLoader;
    pObject = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( pObject )
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, (Scaleform::GFx::LoadQueueEntry *)v10);
    else
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, (Scaleform::GFx::LoadQueueEntry *)v10);
  }
}

// File Line: 1096
// RVA: 0x70A330
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadQueueEntry::LoadType Type; // eax

  Type = pentry->Type;
  if ( (Type & 4) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars(this, pentry, pls);
  }
  else if ( (Type & 8) != 0 )
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML(this, pentry, pls);
  }
  else
  {
    Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(this, pentry, pls);
  }
}

// File Line: 1118
// RVA: 0x709750
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadMovieClip(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls)
{
  unsigned int v6; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r11
  unsigned __int64 Size; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  const char *v11; // rax
  Scaleform::GFx::DisplayObject *v12; // rbx
  Scaleform::GFx::MovieDefImpl *ImageMovieDef; // rsi
  Scaleform::GFx::Sprite *v14; // rdi
  bool v15; // r12
  Scaleform::GFx::LoadQueueEntry *pNext; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  __int64 v18; // rax
  int Id; // r14d
  int vfptr; // r9d
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
  Scaleform::String *UrlStrGfx; // rax
  Scaleform::GFx::ImageCreator *ImageCreator; // r12
  Scaleform::MemoryHeap *pHeap; // rdx
  Scaleform::GFx::ImageFileHandlerRegistry *v36; // rbx
  Scaleform::GFx::FileOpener *v37; // rdi
  Scaleform::GFx::LogState *v38; // rax
  Scaleform::Log *GlobalLog; // rax
  __int64 v40; // rcx
  Scaleform::Render::Image *v41; // rdi
  Scaleform::GFx::ImageResource *v42; // rax
  Scaleform::GFx::ImageResource *v43; // rax
  Scaleform::GFx::ImageResource *v44; // rbx
  unsigned int v45; // edi
  Scaleform::GFx::LoadStates *v46; // r12
  Scaleform::GFx::MovieDefImpl *v47; // rbx
  Scaleform::GFx::MovieDefImpl *v48; // rbx
  Scaleform::GFx::LogState *v49; // rbx
  char *v50; // rcx
  __int64 v51; // rax
  Scaleform::GFx::AS2::Environment *v52; // rdi
  Scaleform::GFx::AS2::Object *v53; // rax
  Scaleform::GFx::AS2::MovieRoot *v54; // r12
  Scaleform::GFx::ASSupport *v55; // rcx
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // rdx
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rcx
  int v58; // r8d
  int v59; // eax
  bool v60; // zf
  Scaleform::GFx::LoadQueueEntry *v61; // r8
  Scaleform::GFx::LoadQueueEntry *v62; // rax
  int v63; // edx
  Scaleform::GFx::MovieDefImpl *v64; // rax
  Scaleform::GFx::ASSupport *v65; // rcx
  __int64 v66; // r14
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 v69; // rax
  __int64 v70; // rcx
  unsigned int v71; // ecx
  Scaleform::GFx::MovieImpl *v72; // r8
  unsigned __int64 v73; // rdx
  __int64 v74; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v75; // r8
  unsigned int v76; // ecx
  Scaleform::GFx::MovieImpl *v77; // r8
  unsigned __int64 v78; // rdx
  __int64 v79; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v80; // r8
  Scaleform::GFx::InteractiveObject *v81; // rcx
  __int64 v82; // rcx
  Scaleform::GFx::AS2::Environment *v83; // r12
  Scaleform::GFx::AS2::Object *v84; // rax
  Scaleform::GFx::AS2::Object *v85; // r14
  Scaleform::GFx::AS2::MovieRoot *v86; // r13
  unsigned __int64 Length; // rax
  const char *v88; // r9
  Scaleform::GFx::LoadStates *plsa; // [rsp+20h] [rbp-E0h]
  Scaleform::String url; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::MovieDefImpl *v91; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::Sprite *v92; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::LogState *pObject; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::DisplayObject *v94; // [rsp+50h] [rbp-B0h]
  Scaleform::String ppath; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::InteractiveObject *pParent; // [rsp+60h] [rbp-A0h]
  Scaleform::String src; // [rsp+68h] [rbp-98h] BYREF
  int v98; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+74h] [rbp-8Ch] BYREF
  int v100; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::MemoryHeap *v101; // [rsp+80h] [rbp-80h]
  Scaleform::String v102; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::String result; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::ASString v105; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v106; // [rsp+B8h] [rbp-48h] BYREF
  int v107; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *v108; // [rsp+D8h] [rbp-28h]
  int v109; // [rsp+E0h] [rbp-20h]
  int v110; // [rsp+E4h] [rbp-1Ch]
  Scaleform::Log *v111; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::FileOpener *v112; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ImageFileHandlerRegistry *v113; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::MovieImpl *v114; // [rsp+100h] [rbp+0h]
  __int64 v115[7]; // [rsp+108h] [rbp+8h] BYREF
  Scaleform::GFx::CharacterCreateInfo v116; // [rsp+140h] [rbp+40h] BYREF
  bool bilinear; // [rsp+1B8h] [rbp+B8h] BYREF
  Scaleform::GFx::LoadStates *v119; // [rsp+1C0h] [rbp+C0h]
  unsigned int FileLength; // [rsp+1C8h] [rbp+C8h]

  v119 = pls;
  v115[3] = -2i64;
  Scaleform::String::String(&ppath);
  v6 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    goto LABEL_8;
  v9 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v9].Level )
  {
    v9 = ++v6;
    if ( v6 >= Size )
      goto LABEL_8;
  }
  if ( !Data[v6].pSprite.pObject
    || (v11 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pMovieImpl->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(pMovieImpl->pMainMovieDef.pObject),
        Scaleform::String::operator=(&ppath, v11),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  Scaleform::String::String(&url, &p_entry->URL);
  Scaleform::String::String(&src);
  v12 = 0i64;
  v94 = 0i64;
  pParent = 0i64;
  pObject = pls->pLog.pObject;
  LODWORD(v101) = this->pMovieImpl->pMainMovieDef.pObject->pBindData.pObject->LoadFlags;
  ImageMovieDef = 0i64;
  v91 = 0i64;
  v14 = 0i64;
  v92 = 0i64;
  v15 = 0;
  pNext = p_entry[1].pNext;
  if ( !pNext )
  {
    vfptr = (int)p_entry[1].vfptr;
    if ( vfptr == -1 )
      goto LABEL_159;
    v21 = 0;
    v22 = this->pMovieImpl;
    v23 = v22->MovieLevels.Data.Size;
    if ( !v23 )
      goto LABEL_26;
    v24 = 0i64;
    v25 = v22->MovieLevels.Data.Data;
    while ( v25[v24].Level != vfptr )
    {
      v24 = ++v21;
      if ( v21 >= v23 )
        goto LABEL_26;
    }
    if ( v25[v21].pSprite.pObject )
    {
      v26 = 0;
      v27 = 0i64;
      while ( v25[v27].Level != vfptr )
      {
        v27 = ++v26;
        if ( v26 >= v23 )
        {
LABEL_37:
          v31 = 0i64;
          goto LABEL_38;
        }
      }
    }
    else
    {
LABEL_26:
      v28 = 0;
      if ( !v23 )
        goto LABEL_39;
      v29 = 0i64;
      v25 = v22->MovieLevels.Data.Data;
      while ( v25[v29].Level )
      {
        v29 = ++v28;
        if ( v28 >= v23 )
          goto LABEL_39;
      }
      if ( !v25[v28].pSprite.pObject )
      {
LABEL_39:
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, (int)p_entry[1].vfptr);
        Id = 0x40000;
        goto LABEL_40;
      }
      v26 = 0;
      v30 = 0i64;
      while ( v25[v30].Level )
      {
        v30 = ++v26;
        if ( v26 >= v23 )
          goto LABEL_37;
      }
    }
    v31 = v25[v26].pSprite.pObject;
LABEL_38:
    v32 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v31->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(v31);
    v15 = ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v32 + 88i64))(v32) & 0x10) != 0;
    goto LABEL_39;
  }
  v17 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter(
          (Scaleform::GFx::CharacterHandle *)pNext,
          this->pMovieImpl);
  v12 = v17;
  if ( v17 )
    ++v17->RefCount;
  v94 = v17;
  if ( !v17 )
    goto LABEL_159;
  pParent = v17->pParent;
  if ( !pParent )
    goto LABEL_159;
  v18 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v17->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(v17);
  v15 = ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 88i64))(v18) & 0x10) != 0;
  Id = v12->Id.Id;
LABEL_40:
  FileLength = 0;
  if ( v15 )
  {
    UrlStrGfx = Scaleform::GFx::GetUrlStrGfx(&result, &url);
    Scaleform::String::operator=(&src, UrlStrGfx);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v14 = v92;
    ImageMovieDef = v91;
    v12 = v94;
  }
  if ( !Scaleform::String::GetLength(&url) )
  {
    v54 = this;
    pLoadQueueMTHead = this->pMovieImpl->pLoadQueueMTHead;
    if ( !pLoadQueueMTHead )
      goto LABEL_116;
    while ( 1 )
    {
      pQueueEntry = pLoadQueueMTHead->pQueueEntry;
      if ( pQueueEntry->EntryTime < p_entry->EntryTime )
      {
        v58 = (int)p_entry[1].vfptr;
        if ( v58 != -1 )
        {
          v59 = (int)pQueueEntry[1].vfptr;
          if ( v59 != -1 )
          {
            v60 = v58 == v59;
            goto LABEL_111;
          }
        }
        v61 = p_entry[1].pNext;
        if ( v61 )
        {
          v62 = pQueueEntry[1].pNext;
          if ( v62 )
          {
            v60 = v61 == v62;
LABEL_111:
            if ( v60 )
              pQueueEntry->Canceled = 1;
          }
        }
      }
      pLoadQueueMTHead = pLoadQueueMTHead->pNext;
      if ( !pLoadQueueMTHead )
        goto LABEL_116;
    }
  }
  bilinear = 0;
  if ( Scaleform::GFx::LoaderImpl::IsProtocolImage(&url, &bilinear, 0i64) )
  {
    ImageCreator = Scaleform::GFx::LoadStates::GetImageCreator(v119);
    if ( !ImageCreator )
    {
      if ( pObject )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "ImageCreator is not installed,failed to load image \"%s\"",
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      goto LABEL_115;
    }
    pHeap = this->pMovieImpl->pHeap;
    v107 = 0;
    v108 = pHeap;
    v109 = 1;
    v110 = 1;
    v111 = 0i64;
    v112 = 0i64;
    v113 = 0i64;
    v114 = 0i64;
    v36 = v119->pImageFileHandlerRegistry.pObject;
    v37 = v119->pBindStates.pObject->pFileOpener.pObject;
    v38 = v119->pLog.pObject;
    if ( v38 )
    {
      GlobalLog = v38->pLog.pObject;
      if ( !GlobalLog )
        GlobalLog = Scaleform::Log::GetGlobalLog();
    }
    else
    {
      GlobalLog = 0i64;
    }
    v112 = v37;
    v111 = GlobalLog;
    v113 = v36;
    v114 = this->pMovieImpl;
    Scaleform::String::String(&v102, (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v41 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::String *))ImageCreator->vfptr[1].__vecDelDtor)(
                                        ImageCreator,
                                        &v107,
                                        &v102);
    v115[5] = (__int64)v41;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v102.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v41 )
    {
      v101 = this->pMovieImpl->pHeap;
      v42 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(__int64, __int64))v101->vfptr->Alloc)(v40, 104i64);
      v115[6] = (__int64)v42;
      if ( v42 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v42, v41, Use_Bitmap);
        v44 = v43;
      }
      else
      {
        v44 = 0i64;
      }
      v115[4] = (__int64)v44;
      if ( v44 )
      {
        ImageMovieDef = Scaleform::GFx::MovieImpl::CreateImageMovieDef(
                          this->pMovieImpl,
                          v44,
                          bilinear,
                          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                          v119);
        v91 = ImageMovieDef;
      }
      else
      {
        ImageMovieDef = v91;
      }
      if ( v44 )
        Scaleform::GFx::Resource::Release(v44);
    }
    else
    {
      if ( pObject )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "ImageCreator::LoadProtocolImage failed to load image \"%s\"",
          (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      ImageMovieDef = v91;
    }
    if ( v41 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v41->vfptr[2].__vecDelDtor)(v41);
    goto LABEL_89;
  }
  v45 = (unsigned int)v101 | 0x10001;
  if ( p_entry->QuietOpen )
    v45 = (unsigned int)v101 | 0x210001;
  if ( Scaleform::String::GetLength(&src) )
  {
    loc.Use = File_LoadMovie;
    Scaleform::String::String(&loc.FileName, &src);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    HIDWORD(plsa) = 0;
    v46 = v119;
    v47 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v119, &loc, v45, 0i64);
    v91 = v47;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v47 )
      goto LABEL_84;
  }
  else
  {
    v46 = v119;
  }
  v106.Use = File_LoadMovie;
  Scaleform::String::String(&v106.FileName, &url);
  Scaleform::String::String(&v106.ParentPath, &ppath);
  HIDWORD(plsa) = 0;
  v48 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v46, &v106, v45, 0i64);
  v91 = v48;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v106.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v106.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v48 )
  {
LABEL_84:
    ImageMovieDef = v91;
    FileLength = v91->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FileLength;
LABEL_89:
    v49 = pObject;
    goto LABEL_90;
  }
  v49 = pObject;
  if ( pObject && !p_entry->QuietOpen )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
      &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "Failed loading URL \"%s\"",
      (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  ImageMovieDef = v91;
LABEL_90:
  if ( !ImageMovieDef )
  {
    v12 = v94;
    v14 = v92;
LABEL_115:
    v54 = this;
    goto LABEL_116;
  }
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))ImageMovieDef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[1].__vecDelDtor)(ImageMovieDef) != -1
    && ((unsigned int (__fastcall *)(Scaleform::GFx::MovieDefImpl *))ImageMovieDef->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[1].__vecDelDtor)(ImageMovieDef) >= 9
    && (char)((ImageMovieDef->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) > 2 )
  {
    if ( v49 && !p_entry->QuietOpen )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v49->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Failed loading SWF \"%s\": ActionScript version mismatch",
        (const char *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v12 = v94;
    if ( v94 )
    {
      v50 = (char *)v94 + 4 * (unsigned __int8)v94->AvmObjOffset;
      v51 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v50 + 8i64))(v50);
      v52 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v51 + 240i64))(v51);
      v53 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].Type, v52);
      if ( v53 )
      {
        LODWORD(plsa) = 0;
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::DisplayObject *, const char *, Scaleform::GFx::LoadStates *))v53->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
          v53,
          v52,
          v12,
          "ActionScriptMismatch",
          plsa);
      }
    }
    v14 = v92;
    goto LABEL_159;
  }
  v115[0] = (__int64)ImageMovieDef->pBindData.pObject->pDataDef.pObject;
  v115[1] = (__int64)ImageMovieDef;
  v115[2] = 0i64;
  v54 = this;
  v55 = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
  v98 = Id;
  v14 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, Scaleform::GFx::InteractiveObject *, int *, int))v55->vfptr[4].__vecDelDtor)(
                                    v55,
                                    this->pMovieImpl,
                                    v115,
                                    pParent,
                                    &v98,
                                    3);
  v92 = v14;
  Scaleform::GFx::Sprite::SetLoadedSeparately(v14, 1);
  v12 = v94;
LABEL_116:
  LOBYTE(v119) = v14 != 0i64;
  v63 = (int)p_entry[1].vfptr;
  if ( v63 != -1 )
  {
    if ( v14 )
    {
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v14 + 4 * (unsigned __int8)v14->AvmObjOffset),
        v63);
      Scaleform::GFx::MovieImpl::SetLevelMovie(v54->pMovieImpl, (int)p_entry[1].vfptr, v14);
      v54->pMovieImpl->Flags &= ~0x100u;
      v54->vfptr[39].__vecDelDtor(v54, (unsigned int)v14);
    }
    v71 = 0;
    v72 = v54->pMovieImpl;
    v73 = v72->MovieLevels.Data.Size;
    if ( !v73 )
      goto LABEL_136;
    v74 = 0i64;
    v75 = v72->MovieLevels.Data.Data;
    while ( v75[v74].Level )
    {
      v74 = ++v71;
      if ( v71 >= v73 )
        goto LABEL_136;
    }
    if ( !v75[v71].pSprite.pObject )
    {
LABEL_136:
      if ( pObject )
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
          &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "_level0 unloaded - no further playback possible");
        goto LABEL_159;
      }
    }
    goto LABEL_138;
  }
  if ( v14 )
  {
    v66 = (__int64)pParent;
    goto LABEL_121;
  }
  rid.Id = 65537;
  v64 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pParent);
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v64, &v116, (Scaleform::GFx::ResourceId)&rid);
  v65 = v54->pASSupport.pObject;
  v100 = Id;
  v66 = (__int64)pParent;
  v14 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, int *, int))v65->vfptr[4].__vecDelDtor)(
                                    v65,
                                    v54->pMovieImpl,
                                    &v116,
                                    pParent,
                                    &v100,
                                    3);
  v92 = v14;
  if ( v14 )
  {
LABEL_121:
    Scaleform::GFx::InteractiveObject::AddToPlayList(v14);
    v14->CreateFrame = v12->CreateFrame;
    v14->Depth = v12->Depth;
    if ( (v12->Flags & 2) == 0 )
    {
      Name = Scaleform::GFx::DisplayObject::GetName(v12, &v105);
      v14->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[124].__vecDelDtor(
        v14,
        (unsigned int)Name);
      pNode = v105.pNode;
      v60 = v105.pNode->RefCount-- == 1;
      if ( v60 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( v66 )
    {
      v70 = v66 + 4i64 * *(unsigned __int8 *)(v66 + 109);
      v69 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v70 + 8i64))(v70);
    }
    else
    {
      v69 = 0i64;
    }
    (*(void (__fastcall **)(__int64, Scaleform::GFx::DisplayObject *, Scaleform::GFx::Sprite *))(*(_QWORD *)v69 + 224i64))(
      v69,
      v12,
      v14);
    v12->pParent = 0i64;
    v54->vfptr[39].__vecDelDtor(v54, (unsigned int)v14);
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(v14);
  }
LABEL_138:
  v76 = 0;
  v77 = v54->pMovieImpl;
  v78 = v77->MovieLevels.Data.Size;
  if ( v78 )
  {
    v79 = 0i64;
    v80 = v77->MovieLevels.Data.Data;
    while ( v80[v79].Level )
    {
      v79 = ++v76;
      if ( v76 >= v78 )
        goto LABEL_144;
    }
    v81 = v80[v76].pSprite.pObject;
  }
  else
  {
LABEL_144:
    v81 = 0i64;
  }
  v82 = (__int64)v81 + 4 * (unsigned __int8)v81->AvmObjOffset;
  v83 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v82 + 240i64))(v82);
  v84 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[1].Type, v83);
  v85 = v84;
  if ( (_BYTE)v119 )
  {
    if ( v84 )
    {
      v84->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].ExecuteForEachChild_GC(
        v84,
        (Scaleform::GFx::AS2::RefCountCollector<323> *)v83,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)v14);
      LODWORD(plsa) = FileLength;
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, _QWORD, Scaleform::GFx::LoadStates *))v85->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].Finalize_GC)(
        v85,
        v83,
        v14,
        FileLength,
        plsa);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, _QWORD))v85->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].Finalize_GC)(
        v85,
        v83,
        v14,
        0i64);
    }
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))v14->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[112].__vecDelDtor)(v14);
    v86 = this;
    ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))this->vfptr[7].__vecDelDtor)(this);
    if ( v85 )
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *))v85->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
        v85,
        v83,
        v14);
  }
  else
  {
    if ( v84 )
    {
      Length = Scaleform::String::GetLength(&url);
      LODWORD(plsa) = 0;
      v88 = "URLNotFound";
      if ( !Length )
        v88 = "Unknown error";
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::Sprite *, const char *, Scaleform::GFx::LoadStates *))v85->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
        v85,
        v83,
        v14,
        v88,
        plsa);
    }
    v86 = this;
  }
  if ( !Scaleform::String::GetLength(&url) )
  {
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    v12 = 0i64;
    v94 = 0i64;
    Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
      &v86->MemContext.pObject->LimHandler,
      v86->pMovieImpl->pHeap);
  }
LABEL_159:
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
  if ( ImageMovieDef )
    Scaleform::GFx::Resource::Release(ImageMovieDef);
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1460
// RVA: 0x70A670
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadXML(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *pentry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::InteractiveObject *pObject; // rdi
  unsigned int v7; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r11
  unsigned __int64 Size; // r10
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  const char *v12; // rax
  unsigned int v13; // ecx
  Scaleform::GFx::MovieImpl *v14; // r8
  unsigned __int64 v15; // rdx
  __int64 v16; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v17; // r8
  __int64 v18; // rcx
  Scaleform::GFx::AS2::Environment *v19; // rdi
  __int64 *v20; // rsi
  __int64 v21; // rbp
  Scaleform::GFx::AS2::Object *v22; // rax
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::String ppath; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::String pdest; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::String v26; // [rsp+88h] [rbp+20h] BYREF

  Scaleform::String::String(&ppath);
  pObject = 0i64;
  v7 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    goto LABEL_8;
  v10 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= Size )
      goto LABEL_8;
  }
  if ( !Data[v7].pSprite.pObject
    || (v12 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pMovieImpl->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(pMovieImpl->pMainMovieDef.pObject),
        Scaleform::String::operator=(&ppath, v12),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  if ( Scaleform::String::GetLength(&pentry->URL) )
  {
    loc.Use = File_LoadXML;
    Scaleform::String::String(&loc.FileName, &pentry->URL);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    Scaleform::String::String(&pdest);
    Scaleform::GFx::LoadStates::BuildURL(pls, &pdest, &loc);
    Scaleform::String::String(&v26, (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    (*(void (__fastcall **)(_QWORD, Scaleform::String *, Scaleform::GFx::FileOpener *))(**(_QWORD **)&pentry[3].EntryTime
                                                                                      + 8i64))(
      *(_QWORD *)&pentry[3].EntryTime,
      &v26,
      pls->pBindStates.pObject->pFileOpener.pObject);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = 0;
    v14 = this->pMovieImpl;
    v15 = v14->MovieLevels.Data.Size;
    if ( v15 )
    {
      v16 = 0i64;
      v17 = v14->MovieLevels.Data.Data;
      while ( v17[v16].Level )
      {
        v16 = ++v13;
        if ( v13 >= v15 )
          goto LABEL_18;
      }
      pObject = v17[v13].pSprite.pObject;
    }
LABEL_18:
    v18 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
    v19 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 240i64))(v18);
    v20 = *(__int64 **)&pentry[3].EntryTime;
    v21 = *v20;
    v22 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pentry[3], v19);
    (*(void (__fastcall **)(__int64 *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(v21 + 16))(
      v20,
      v19,
      v22);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1507
// RVA: 0x70A5B0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVarsMT(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::String *data,
        signed __int64 fileLen)
{
  Scaleform::String punescapedStr; // [rsp+68h] [rbp+20h] BYREF

  Scaleform::String::String(&punescapedStr);
  Scaleform::GFx::ASUtils::Unescape(
    (const char *)((data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(data->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
    &punescapedStr);
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(this, p_entry, pls, &punescapedStr, fileLen);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((punescapedStr.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1522
// RVA: 0x6E2750
void __fastcall Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::String *data,
        signed __int64 fileLen)
{
  Scaleform::GFx::AS2::Object *v9; // rbx
  unsigned int v10; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // r9
  __int64 v13; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v14; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // rsi
  double v18; // xmm1_8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::InteractiveObject *v21; // rdi
  int vfptr; // edx
  Scaleform::GFx::DisplayObject *v23; // rax
  Scaleform::GFx::Sprite *EmptySprite; // rbx
  unsigned int v25; // ecx
  Scaleform::GFx::MovieImpl *v26; // r9
  unsigned __int64 v27; // r8
  __int64 v28; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v29; // r9
  char *v30; // rcx
  __int64 v31; // rax
  Scaleform::GFx::AS2::ObjectInterface *v32; // rbp
  unsigned int v33; // ecx
  Scaleform::GFx::MovieImpl *v34; // r8
  unsigned __int64 v35; // rdx
  __int64 v36; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v37; // r8
  __int64 v38; // rcx
  Scaleform::GFx::AS2::Environment *v39; // rax
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  if ( Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[2].pNext, 0i64) )
  {
    v9 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&p_entry[2].pNext, 0i64);
    v10 = 0;
    pMovieImpl = this->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    if ( Size )
    {
      v13 = 0i64;
      v14 = pMovieImpl->MovieLevels.Data.Data;
      while ( v14[v13].Level )
      {
        v13 = ++v10;
        if ( v10 >= Size )
          goto LABEL_8;
      }
      pObject = v14[v10].pSprite.pObject;
    }
    else
    {
LABEL_8:
      pObject = 0i64;
    }
    v16 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
    v17 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 240i64))(v16);
    Scaleform::GFx::AS2::Environment::CreateString(v17, &result, data);
    v18 = (double)(int)fileLen;
    if ( fileLen < 0 )
      v18 = v18 + 1.844674407370955e19;
    if ( *(double *)&v9[1].pRCC < 0.0 )
      v9[1].pRCC = 0i64;
    *(double *)&v9[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = v18;
    *(double *)&v9[1].pRCC = v18 + *(double *)&v9[1].pRCC;
    Scaleform::GFx::AS2::LoadVarsObject::NotifyOnData((Scaleform::GFx::AS2::LoadVarsObject *)v9, v17, &result);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  v21 = 0i64;
  result.pNode = 0i64;
  vfptr = (int)p_entry[1].vfptr;
  if ( vfptr == -1 )
  {
    v23 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
            (Scaleform::GFx::CharacterHandle *)p_entry[1].pNext,
            this->pMovieImpl);
    EmptySprite = (Scaleform::GFx::Sprite *)v23;
    if ( v23 )
      ++v23->RefCount;
    result.pNode = (Scaleform::GFx::ASStringNode *)v23;
    if ( !v23 )
      goto LABEL_31;
    goto LABEL_30;
  }
  v25 = 0;
  v26 = this->pMovieImpl;
  v27 = v26->MovieLevels.Data.Size;
  if ( v27 )
  {
    v28 = 0i64;
    v29 = v26->MovieLevels.Data.Data;
    while ( v29[v28].Level != vfptr )
    {
      v28 = ++v25;
      if ( v25 >= v27 )
        goto LABEL_27;
    }
    EmptySprite = (Scaleform::GFx::Sprite *)v29[v25].pSprite.pObject;
    if ( EmptySprite )
      ++EmptySprite->RefCount;
  }
  else
  {
LABEL_27:
    EmptySprite = 0i64;
  }
  result.pNode = (Scaleform::GFx::ASStringNode *)EmptySprite;
  if ( EmptySprite
    || (EmptySprite = Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(this, pls, (int)p_entry[1].vfptr),
        (result.pNode = (Scaleform::GFx::ASStringNode *)EmptySprite) != 0i64) )
  {
LABEL_30:
    v30 = (char *)EmptySprite + 4 * (unsigned __int8)EmptySprite->AvmObjOffset;
    v31 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v30 + 8i64))(v30);
    v32 = (Scaleform::GFx::AS2::ObjectInterface *)(v31 + 8);
    if ( v31 )
    {
LABEL_32:
      v33 = 0;
      v34 = this->pMovieImpl;
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
      v38 = (__int64)v21 + 4 * (unsigned __int8)v21->AvmObjOffset;
      v39 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v38 + 240i64))(v38);
      Scaleform::GFx::AS2::LoadVarsProto::LoadVariables(v39, v32, data);
      if ( EmptySprite )
        Scaleform::RefCountNTSImpl::Release(EmptySprite);
      return;
    }
LABEL_31:
    v32 = 0i64;
    goto LABEL_32;
  }
}

// File Line: 1572
// RVA: 0x70A350
void __fastcall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::Render::RenderBuffer *v6; // rbx
  unsigned int v7; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r11
  unsigned __int64 Size; // r10
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  const char *v12; // rax
  Scaleform::File *v13; // rax
  Scaleform::String pdata; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::File *v15; // [rsp+38h] [rbp-48h]
  __int64 v16; // [rsp+40h] [rbp-40h]
  __int64 *v17; // [rsp+48h] [rbp-38h]
  __int64 v18[3]; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+68h] [rbp-18h] BYREF
  int pfileLen; // [rsp+C0h] [rbp+40h] BYREF
  Scaleform::String ppath; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::String pdest; // [rsp+D8h] [rbp+58h] BYREF

  v16 = -2i64;
  Scaleform::String::String(&ppath);
  v6 = 0i64;
  v7 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    goto LABEL_8;
  v10 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= Size )
      goto LABEL_8;
  }
  if ( !Data[v7].pSprite.pObject
    || (v12 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pMovieImpl->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(pMovieImpl->pMainMovieDef.pObject),
        Scaleform::String::operator=(&ppath, v12),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_8:
    Scaleform::String::Clear(&ppath);
  }
  Scaleform::String::String(&pdata);
  pfileLen = 0;
  if ( Scaleform::String::GetLength(&p_entry->URL) )
  {
    loc.Use = File_LoadVars;
    Scaleform::String::String(&loc.FileName, &p_entry->URL);
    Scaleform::String::String(&loc.ParentPath, &ppath);
    Scaleform::String::String(&pdest);
    Scaleform::GFx::LoadStates::BuildURL(pls, &pdest, &loc);
    v15 = 0i64;
    v17 = v18;
    memset(v18, 0, sizeof(v18));
    if ( !Scaleform::GFx::URLBuilder::IsProtocol(&pdest) )
    {
      v13 = Scaleform::GFx::LoadStates::OpenFile(
              pls,
              (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
              0);
      v6 = (Scaleform::Render::RenderBuffer *)v13;
      v15 = v13;
      if ( v13 )
      {
        if ( LOBYTE(p_entry[2].pNext) == 6 )
        {
          if ( !Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v13, &pfileLen, 1) )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&p_entry[2].pNext);
        }
        else
        {
          Scaleform::GFx::MovieImpl::ReadTextData(&pdata, v13, &pfileLen, 1);
        }
      }
    }
    v17 = v18;
    if ( v18[0] )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v6 )
      Scaleform::RefCountImpl::Release(v6);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(this, p_entry, pls, &pdata, pfileLen);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pdata.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1659
// RVA: 0x6DFBE0
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::AS2::MovieRoot::CreateEmptySprite(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadStates *pls,
        int level)
{
  Scaleform::GFx::Sprite *v6; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rax
  Scaleform::MemoryHeap *pHeap; // rbx
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::GFx::MovieDataDef *v10; // rax
  Scaleform::GFx::MovieDataDef *v11; // rax
  Scaleform::GFx::MovieDataDef *v12; // rsi
  Scaleform::GFx::Resource *v13; // rbx
  __int64 v14; // rcx
  Scaleform::GFx::MovieDefImpl *v15; // rax
  Scaleform::GFx::Resource *v16; // rax
  Scaleform::GFx::ASSupport *pObject; // rcx
  Scaleform::GFx::ResourceKey result; // [rsp+68h] [rbp-50h] BYREF
  __int64 v20[8]; // [rsp+78h] [rbp-40h] BYREF
  Scaleform::MemoryHeap *v21; // [rsp+C0h] [rbp+8h] BYREF
  Scaleform::GFx::MovieDataDef *v22; // [rsp+D8h] [rbp+20h]

  v6 = 0i64;
  Scaleform::GFx::MovieDataDef::CreateMovieFileKey(&result, &customCaption, 0i64, 0i64, 0i64);
  pMovieImpl = this->pMovieImpl;
  pHeap = pMovieImpl->pHeap;
  v9 = Scaleform::Memory::pGlobalHeap;
  if ( pHeap )
    v9 = pMovieImpl->pHeap;
  v21 = v9;
  v10 = (Scaleform::GFx::MovieDataDef *)v9->vfptr->Alloc(v9, 72ui64, 0i64);
  v22 = v10;
  if ( v10 )
  {
    Scaleform::GFx::MovieDataDef::MovieDataDef(v10, &result, MT_Empty, &customCaption, pHeap, 0, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = 0i64;
  v22 = 0i64;
  if ( v12 )
  {
    Scaleform::GFx::MovieDataDef::LoadTaskData::InitEmptyMovieDef(v12->pData.pObject);
    Scaleform::GFx::LoadStates::SetRelativePathForDataDef(pls, v12);
    v21 = this->pMovieImpl->pHeap;
    v15 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(__int64, __int64))v21->vfptr->Alloc)(v14, 112i64);
    if ( v15 )
    {
      Scaleform::GFx::MovieDefImpl::MovieDefImpl(
        v15,
        v12,
        pls->pBindStates.pObject,
        pls->pLoaderImpl.pObject,
        0,
        this->pMovieImpl->pStateBag.pObject->pDelegate.pObject,
        this->pMovieImpl->pHeap,
        1,
        0i64);
      v13 = v16;
    }
    else
    {
      v13 = 0i64;
    }
    v22 = (Scaleform::GFx::MovieDataDef *)v13;
    if ( v13 )
    {
      v20[0] = (__int64)v12;
      v20[1] = (__int64)v13;
      v20[2] = 0i64;
      pObject = this->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
      LODWORD(v21) = 0x40000;
      v6 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, _QWORD, Scaleform::MemoryHeap **, int))pObject->vfptr[4].__vecDelDtor)(
                                       pObject,
                                       this->pMovieImpl,
                                       v20,
                                       0i64,
                                       &v21,
                                       3);
      Scaleform::GFx::Sprite::SetLoadedSeparately(v6, 1);
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
        level);
      Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, level, v6);
    }
  }
  if ( v13 )
    Scaleform::GFx::Resource::Release(v13);
  if ( v12 )
    Scaleform::GFx::Resource::Release(v12);
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  return v6;
}

// File Line: 1693
// RVA: 0x6FF070
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *alias,
        Scaleform::GFx::AS2::Value *presult,
        int numArgs)
{
  unsigned int v9; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::DisplayObject *v15; // rbx
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax
  Scaleform::GFx::AS2::ObjectInterface *v18; // rbp
  char *v19; // rcx
  __int64 v20; // rax
  unsigned int v21; // ecx
  Scaleform::GFx::MovieImpl *v22; // r8
  unsigned __int64 v23; // rdx
  __int64 v24; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v25; // r8
  Scaleform::GFx::InteractiveObject *v26; // rcx
  __int64 v27; // rcx
  Scaleform::GFx::AS2::Environment *v28; // r14
  Scaleform::GFx::ASStringNode *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  char v31; // si
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+50h] [rbp-48h] BYREF

  v9 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v12 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  if ( alias->ThisObject.pObject )
    alias->ThisObject.pObject->RefCount = (alias->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = alias->ThisObject.pObject;
  v15 = 0i64;
  v16 = alias->ThisChar.pObject;
  if ( v16 )
  {
    v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v16, this->pMovieImpl);
    v15 = v17;
    if ( v17 )
      ++v17->RefCount;
  }
  if ( pObject )
  {
    v18 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
  }
  else if ( v15
         && (v19 = (char *)v15 + 4 * (unsigned __int8)v15->AvmObjOffset,
             (v20 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v19 + 8i64))(v19)) != 0) )
  {
    v18 = (Scaleform::GFx::AS2::ObjectInterface *)(v20 + 8);
  }
  else
  {
    v18 = 0i64;
  }
  v21 = 0;
  v22 = this->pMovieImpl;
  v23 = v22->MovieLevels.Data.Size;
  if ( v23 )
  {
    v24 = 0i64;
    v25 = v22->MovieLevels.Data.Data;
    while ( v25[v24].Level )
    {
      v24 = ++v21;
      if ( v21 >= v23 )
        goto LABEL_24;
    }
    v26 = v25[v21].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v26 = 0i64;
  }
  v27 = (__int64)v26 + 4 * (unsigned __int8)v26->AvmObjOffset;
  v28 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v27 + 240i64))(v27);
  method.T.Type = 8;
  method.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)alias->Function.Function;
  method.V.pStringNode = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  method.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = alias->Function.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&method.V.FunctionValue, pLocalFrame, alias->Function.Flags & 1);
  v31 = Scaleform::GFx::AS2::GAS_Invoke(
          &method,
          presult,
          v18,
          v28,
          numArgs,
          32 * v28->Stack.Pages.Data.Size - 32 + v28->Stack.pCurrent - v28->Stack.pPageStart,
          pmethodName);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v15 )
    Scaleform::RefCountNTSImpl::Release(v15);
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  return v31;
}

// File Line: 1716
// RVA: 0x6FF2A0
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *alias,
        Scaleform::GFx::AS2::Value *presult)
{
  unsigned int v7; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r11
  __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::DisplayObject *v13; // rbx
  Scaleform::GFx::CharacterHandle *v14; // rcx
  Scaleform::GFx::DisplayObject *v15; // rax
  Scaleform::GFx::AS2::ObjectInterface *v16; // rbp
  char *v17; // rcx
  __int64 v18; // rax
  unsigned int v19; // ecx
  Scaleform::GFx::MovieImpl *v20; // r8
  unsigned __int64 v21; // rdx
  __int64 v22; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v23; // r8
  Scaleform::GFx::InteractiveObject *v24; // rcx
  __int64 v25; // rcx
  Scaleform::GFx::AS2::Environment *v26; // r14
  Scaleform::GFx::ASStringNode *Function; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  char v29; // si
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+50h] [rbp-48h] BYREF

  v7 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v10 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v10].Level )
  {
    v10 = ++v7;
    if ( v7 >= Size )
      return 0;
  }
  if ( !Data[v7].pSprite.pObject )
    return 0;
  if ( alias->ThisObject.pObject )
    alias->ThisObject.pObject->RefCount = (alias->ThisObject.pObject->RefCount + 1) & 0x8FFFFFFF;
  pObject = alias->ThisObject.pObject;
  v13 = 0i64;
  v14 = alias->ThisChar.pObject;
  if ( v14 )
  {
    v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, this->pMovieImpl);
    v13 = v15;
    if ( v15 )
      ++v15->RefCount;
  }
  if ( pObject )
  {
    v16 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
  }
  else if ( v13
         && (v17 = (char *)v13 + 4 * (unsigned __int8)v13->AvmObjOffset,
             (v18 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v17 + 8i64))(v17)) != 0) )
  {
    v16 = (Scaleform::GFx::AS2::ObjectInterface *)(v18 + 8);
  }
  else
  {
    v16 = 0i64;
  }
  v19 = 0;
  v20 = this->pMovieImpl;
  v21 = v20->MovieLevels.Data.Size;
  if ( v21 )
  {
    v22 = 0i64;
    v23 = v20->MovieLevels.Data.Data;
    while ( v23[v22].Level )
    {
      v22 = ++v19;
      if ( v19 >= v21 )
        goto LABEL_24;
    }
    v24 = v23[v19].pSprite.pObject;
  }
  else
  {
LABEL_24:
    v24 = 0i64;
  }
  v25 = (__int64)v24 + 4 * (unsigned __int8)v24->AvmObjOffset;
  v26 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 240i64))(v25);
  method.T.Type = 8;
  method.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)alias->Function.Function;
  method.V.pStringNode = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  method.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = alias->Function.pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&method.V.FunctionValue, pLocalFrame, alias->Function.Flags & 1);
  v29 = Scaleform::GFx::AS2::GAS_InvokeParsed(&method, presult, v16, v26);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v13 )
    Scaleform::RefCountNTSImpl::Release(v13);
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  return v29;
}

// File Line: 1739
// RVA: 0x6D8720
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddInvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::ASString *alias,
        Scaleform::GFx::CharacterHandle *pthisChar,
        Scaleform::GFx::AS2::Object *pthisObj,
        Scaleform::GFx::AS2::FunctionRef *func)
{
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *v9; // rax
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::CharacterHandle *v12; // rbx
  Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *pInvokeAliases; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo v15; // [rsp+38h] [rbp-40h] BYREF

  if ( !this->pInvokeAliases )
  {
    v9 = (Scaleform::GFx::ASStringHash<Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo> *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                                                            Scaleform::Memory::pGlobalHeap,
                                                                                            8i64,
                                                                                            0i64);
    if ( v9 )
      v9->mHash.pTable = 0i64;
    else
      v9 = 0i64;
    this->pInvokeAliases = v9;
  }
  memset(&v15, 0, 33);
  if ( pthisObj )
    pthisObj->RefCount = (pthisObj->RefCount + 1) & 0x8FFFFFFF;
  pObject = v15.ThisObject.pObject;
  if ( v15.ThisObject.pObject )
  {
    RefCount = v15.ThisObject.pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v15.ThisObject.pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v15.ThisObject.pObject = pthisObj;
  if ( pthisChar )
    ++pthisChar->RefCount;
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
  v15.ThisChar.pObject = pthisChar;
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&v15.Function, func);
  pInvokeAliases = this->pInvokeAliases;
  key.pFirst = alias;
  key.pSecond = &v15;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
    &pInvokeAliases->mHash,
    pInvokeAliases,
    &key);
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::~InvokeAliasInfo(&v15);
}

// File Line: 1750
// RVA: 0x6F67A0
Scaleform::Render::Text::Allocator *__fastcall Scaleform::GFx::AS2::MovieRoot::GetTextAllocator(
        Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::AS2::MemoryContextImpl *pObject; // rcx
  Scaleform::Render::Text::Allocator *v3; // rax
  Scaleform::Render::Text::Allocator *v4; // rax
  Scaleform::Render::Text::Allocator *v5; // rsi
  Scaleform::GFx::AS2::MemoryContextImpl *v6; // rdi
  Scaleform::RefCountNTSImpl *v7; // rcx

  pObject = this->MemContext.pObject;
  if ( pObject->TextAllocator.pObject )
    return pObject->TextAllocator.pObject;
  v3 = (Scaleform::Render::Text::Allocator *)pObject->Heap->vfptr->Alloc(
                                               (Scaleform::MemoryHeap *)pObject,
                                               144ui64,
                                               0i64);
  if ( v3 )
  {
    Scaleform::Render::Text::Allocator::Allocator(v3, this->MemContext.pObject->Heap, 0);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = this->MemContext.pObject;
  v7 = v6->TextAllocator.pObject;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v6->TextAllocator.pObject = v5;
  return this->MemContext.pObject->TextAllocator.pObject;
}

// File Line: 1760
// RVA: 0x712250
Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *__fastcall Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pstr)
{
  __int64 v4; // rbx
  unsigned int v5; // r8d
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  unsigned __int64 Size; // r9
  __int64 v8; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rdx
  unsigned int v10; // ecx
  __int64 v11; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v13; // rcx
  Scaleform::GFx::AS2::Environment *v14; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r11
  unsigned __int64 SizeMask; // rdi
  __int64 v17; // r10
  __int64 v18; // r8
  unsigned __int64 *v19; // r9
  Scaleform::GFx::ASStringNode *v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  if ( !this->pInvokeAliases )
    return 0i64;
  v4 = 0i64;
  v5 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0i64;
  v8 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v8].Level )
  {
    v8 = ++v5;
    if ( v5 >= Size )
      return 0i64;
  }
  if ( !Data[v5].pSprite.pObject )
    return 0i64;
  v10 = 0;
  v11 = 0i64;
  do
  {
    if ( !Data[v11].Level )
    {
      pObject = Data[v10].pSprite.pObject;
      goto LABEL_15;
    }
    v11 = ++v10;
  }
  while ( v10 < Size );
  pObject = 0i64;
LABEL_15:
  v13 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::Environment::CreateString(v14, &result, pstr);
  pTable = this->pInvokeAliases->mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v17 = (unsigned int)SizeMask & result.pNode->HashFlags;
    v18 = v17;
    v19 = &pTable[1].EntryCount + 7 * v17;
    if ( *v19 != -2i64 && ((unsigned int)SizeMask & *(_DWORD *)(v19[1] + 28)) == v17 )
    {
      while ( 1 )
      {
        v20 = (Scaleform::GFx::ASStringNode *)v19[1];
        if ( ((unsigned int)SizeMask & v20->HashFlags) == v17 && v20 == result.pNode )
          break;
        v18 = *v19;
        if ( *v19 == -1i64 )
          goto LABEL_25;
        v19 = &pTable[1].EntryCount + 7 * v18;
      }
      if ( v18 >= 0 )
      {
        v21 = (__int64)(&pTable[1].SizeMask + 7 * v18);
        if ( v21 )
          v4 = v21 + 8;
      }
    }
  }
LABEL_25:
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *)v4;
}

// File Line: 1772
// RVA: 0x6F7790
char __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariable(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  unsigned int v6; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r11
  unsigned __int64 Size; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r11
  unsigned int v11; // ecx
  __int64 v12; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v14; // rcx
  Scaleform::GFx::AS2::Environment *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  v6 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v9 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v9].Level )
  {
    v9 = ++v6;
    if ( v6 >= Size )
      return 0;
  }
  if ( !Data[v6].pSprite.pObject || !pval )
    return 0;
  v11 = 0;
  v12 = 0i64;
  do
  {
    if ( !Data[v12].Level )
    {
      pObject = Data[v11].pSprite.pObject;
      goto LABEL_15;
    }
    v12 = ++v11;
  }
  while ( v11 < Size );
  pObject = 0i64;
LABEL_15:
  v14 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v15 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 240i64))(v14);
  Scaleform::GFx::AS2::Environment::CreateString(v15, &result, ppathToVar);
  presult.T.Type = 0;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v15, &result, &presult, 0i64) )
  {
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    pNode = result.pNode;
    v17 = result.pNode->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 0;
  }
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v15, &presult, pval);
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v16 = result.pNode;
  v17 = result.pNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return 1;
}

// File Line: 1795
// RVA: 0x71D450
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariable(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *ppathToVar,
        Scaleform::GFx::Value *value,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::InteractiveObject *v8; // rbx
  unsigned int v9; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  unsigned __int64 Size; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::Log *pObject; // rbx
  Scaleform::Log *v15; // rbx
  unsigned int v16; // ecx
  __int64 v17; // rax
  Scaleform::GFx::InteractiveObject *v18; // rcx
  __int64 v19; // rcx
  Scaleform::GFx::AS2::Environment *v20; // rax
  unsigned int v21; // ecx
  Scaleform::GFx::MovieImpl *v22; // rdx
  unsigned __int64 v23; // r8
  __int64 v24; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v25; // rdx
  __int64 v26; // rcx
  Scaleform::GFx::AS2::Environment *v27; // rax
  char v28; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+30h] [rbp-48h] BYREF
  __int64 v33; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::ASString varname; // [rsp+80h] [rbp+8h] BYREF

  v33 = -2i64;
  v8 = 0i64;
  v9 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v12 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  if ( !ppathToVar )
  {
    pObject = Scaleform::GFx::StateBag::GetLog(&pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( pObject )
    {
      v15 = Scaleform::GFx::StateBag::GetLog(&this->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
      if ( result.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
      Scaleform::Log::LogError(v15, "NULL pathToVar passed to SetVariable/SetDouble()");
    }
    return 0;
  }
  v16 = 0;
  v17 = 0i64;
  do
  {
    if ( !Data[v17].Level )
    {
      v18 = Data[v16].pSprite.pObject;
      goto LABEL_21;
    }
    v17 = ++v16;
  }
  while ( v16 < Size );
  v18 = 0i64;
LABEL_21:
  v19 = (__int64)v18 + 4 * (unsigned __int8)v18->AvmObjOffset;
  v20 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 240i64))(v19);
  Scaleform::GFx::AS2::Environment::CreateString(v20, &varname, ppathToVar);
  pdestVal.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, value, &pdestVal);
  v21 = 0;
  v22 = this->pMovieImpl;
  v23 = v22->MovieLevels.Data.Size;
  if ( v23 )
  {
    v24 = 0i64;
    v25 = v22->MovieLevels.Data.Data;
    while ( v25[v24].Level )
    {
      v24 = ++v21;
      if ( v21 >= v23 )
        goto LABEL_27;
    }
    v8 = v25[v21].pSprite.pObject;
  }
LABEL_27:
  v26 = (__int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
  v27 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 240i64))(v26);
  v28 = Scaleform::GFx::AS2::Environment::SetVariable(v27, &varname, &pdestVal, 0i64, setType == SV_Normal);
  if ( !v28 && setType || setType == SV_Permanent )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(this, &varname, &pdestVal, setType);
  if ( pdestVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
  pNode = varname.pNode;
  if ( varname.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v28;
}

// File Line: 1830
// RVA: 0x71D660
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariableArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index)
{
  Scaleform::GFx::AS2::MovieRoot *v7; // r13
  Scaleform::GFx::InteractiveObject *v8; // r15
  unsigned int v9; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  unsigned int v14; // ecx
  __int64 v15; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v17; // rcx
  Scaleform::GFx::AS2::Environment *v18; // rbx
  __int64 v19; // rcx
  Scaleform::GFx::AS2::Object *v20; // rax
  __int64 v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rbx
  unsigned int v23; // edx
  Scaleform::GFx::MovieImpl *v24; // r9
  unsigned __int64 v25; // r8
  __int64 v26; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v27; // r9
  Scaleform::GFx::InteractiveObject *v28; // rcx
  __int64 v29; // rcx
  Scaleform::GFx::AS2::Environment *v30; // rax
  __int64 v31; // rax
  unsigned int v32; // esi
  int *v33; // r14
  unsigned int v34; // esi
  float *v35; // r14
  unsigned int v36; // esi
  Scaleform::GFx::ASStringNode **v37; // r14
  unsigned int i; // esi
  unsigned int v39; // esi
  const char **v40; // r14
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v43; // zf
  unsigned int v44; // esi
  const wchar_t **v45; // r14
  Scaleform::GFx::ASString *v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  unsigned int v48; // ecx
  Scaleform::GFx::MovieImpl *v49; // rdx
  unsigned __int64 v50; // r8
  __int64 v51; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v52; // rdx
  __int64 v53; // rcx
  Scaleform::GFx::AS2::Environment *v54; // rax
  char v55; // di
  int v56; // eax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+18h] [rbp-71h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-51h] BYREF
  Scaleform::GFx::ASString v61; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+48h] [rbp-41h] BYREF
  __int64 v63; // [rsp+50h] [rbp-39h]
  Scaleform::GFx::AS2::Value v64; // [rsp+58h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value presult; // [rsp+78h] [rbp-11h] BYREF
  __int64 v66; // [rsp+98h] [rbp+Fh]
  Scaleform::GFx::AS2::MovieRoot *v67; // [rsp+D8h] [rbp+4Fh]
  Scaleform::GFx::Value *retaddr; // [rsp+F8h] [rbp+6Fh]
  unsigned int v69; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::Movie::SetVarType v70; // [rsp+108h] [rbp+7Fh]

  v69 = (unsigned int)this;
  v66 = -2i64;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v12 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  v14 = 0;
  v15 = 0i64;
  while ( Data[v15].Level )
  {
    v15 = ++v14;
    if ( v14 >= Size )
    {
      pObject = 0i64;
      goto LABEL_12;
    }
  }
  pObject = Data[v14].pSprite.pObject;
LABEL_12:
  v17 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v18 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 240i64))(v17);
  Scaleform::GFx::AS2::Environment::CreateString(v18, &result, ppathToVar);
  v63 = 0i64;
  presult.T.Type = 0;
  memset(&val.NV.8, 0, 20);
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v18, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v20 = Scaleform::GFx::AS2::Value::ToObject(&presult, v18), (v21 = (__int64)v20) != 0)
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v20->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v20->Scaleform::GFx::AS2::ObjectInterface) == 7 )
  {
    *(_DWORD *)(v21 + 24) = (*(_DWORD *)(v21 + 24) + 1) & 0x8FFFFFFF;
  }
  else
  {
    v61.pNode = (Scaleform::GFx::ASStringNode *)v7->pMovieImpl->pHeap;
    v22 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(__int64, __int64, _QWORD))v61.pNode->pData + 10))(
                                            v19,
                                            144i64,
                                            0i64);
    v62.pNode = v22;
    if ( v22 )
    {
      v23 = 0;
      v24 = v7->pMovieImpl;
      v25 = v24->MovieLevels.Data.Size;
      if ( v25 )
      {
        v26 = 0i64;
        v27 = v24->MovieLevels.Data.Data;
        while ( v27[v26].Level )
        {
          v26 = ++v23;
          if ( v23 >= v25 )
            goto LABEL_24;
        }
        v28 = v27[v23].pSprite.pObject;
      }
      else
      {
LABEL_24:
        v28 = 0i64;
      }
      v29 = (__int64)v28 + 4 * (unsigned __int8)v28->AvmObjOffset;
      v30 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 240i64))(v29);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v22, v30);
      v21 = v31;
    }
    else
    {
      v21 = 0i64;
    }
  }
  v63 = v21;
  if ( index + v69 > *(_DWORD *)(v21 + 112) )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v21, index + v69);
  switch ( type )
  {
    case SA_Int:
      v32 = 0;
      if ( v69 )
      {
        v33 = (int *)retaddr;
        do
        {
          val.NV.Int32Value = *v33;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, v32 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v32;
          ++v33;
        }
        while ( v32 < v69 );
      }
      break;
    case SA_Double:
      v36 = 0;
      if ( v69 )
      {
        v37 = (Scaleform::GFx::ASStringNode **)retaddr;
        do
        {
          val.V.pStringNode = *v37;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, v36 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v36;
          ++v37;
        }
        while ( v36 < v69 );
      }
      break;
    case SA_Float:
      v34 = 0;
      if ( v69 )
      {
        v35 = (float *)retaddr;
        do
        {
          val.NV.NumberValue = *v35;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, v34 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          ++v34;
          ++v35;
        }
        while ( v34 < v69 );
      }
      break;
    case SA_String:
      v39 = 0;
      if ( v69 )
      {
        v40 = (const char **)retaddr;
        do
        {
          v41 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                  &v7->BuiltinsMgr,
                  &v62,
                  *v40);
          val.T.Type = 5;
          val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v41->pNode;
          ++val.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, v39 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          pNode = v62.pNode;
          v43 = v62.pNode->RefCount-- == 1;
          if ( v43 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          ++v39;
          ++v40;
        }
        while ( v39 < v69 );
        goto LABEL_68;
      }
      break;
    case SA_StringW:
      v44 = 0;
      if ( v69 )
      {
        v45 = (const wchar_t **)retaddr;
        do
        {
          v46 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
                  &v7->BuiltinsMgr,
                  &v61,
                  *v45,
                  -1i64);
          val.T.Type = 5;
          val.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v46->pNode;
          ++val.V.pStringNode->RefCount;
          Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, v44 + index, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          v47 = v61.pNode;
          v43 = v61.pNode->RefCount-- == 1;
          if ( v43 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v47);
          ++v44;
          ++v45;
        }
        while ( v44 < v69 );
LABEL_68:
        v7 = v67;
      }
      break;
    case SA_Value:
      for ( i = 0; i < v69; ++i )
      {
        Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v7, &retaddr[i], &val);
        Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)v21, i + index, &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      break;
    default:
      break;
  }
  v64.T.Type = 0;
  Scaleform::GFx::AS2::Value::SetAsObject(&v64, (Scaleform::GFx::ASStringNode *)v21);
  v48 = 0;
  v49 = v7->pMovieImpl;
  v50 = v49->MovieLevels.Data.Size;
  if ( v50 )
  {
    v51 = 0i64;
    v52 = v49->MovieLevels.Data.Data;
    while ( v52[v51].Level )
    {
      v51 = ++v48;
      if ( v48 >= v50 )
        goto LABEL_75;
    }
    v8 = v52[v48].pSprite.pObject;
  }
LABEL_75:
  v53 = (__int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
  v54 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v53 + 240i64))(v53);
  v55 = Scaleform::GFx::AS2::Environment::SetVariable(v54, &result, &v64, 0i64, v70 == SV_Normal);
  if ( !v55 && v70 || v70 == SV_Permanent )
    Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(v7, &result, &v64, v70);
  if ( v64.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v64);
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v56 = *(_DWORD *)(v21 + 24);
  if ( (v56 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v21 + 24) = v56 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v21);
  }
  v57 = result.pNode;
  v43 = result.pNode->RefCount-- == 1;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  return v55;
}

// File Line: 1935
// RVA: 0x71DBC0
char __fastcall Scaleform::GFx::AS2::MovieRoot::SetVariableArraySize(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *ppathToVar,
        int count,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::InteractiveObject *v8; // rdi
  unsigned int v9; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r11
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  unsigned int v14; // ecx
  __int64 v15; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v17; // rcx
  Scaleform::GFx::AS2::Environment *v18; // rbx
  Scaleform::MemoryHeap *v19; // rcx
  Scaleform::GFx::AS2::Object *v20; // rax
  Scaleform::GFx::AS2::Object *v21; // rbx
  char v22; // di
  Scaleform::GFx::AS2::ArrayObject *v23; // rbx
  unsigned int v24; // edx
  Scaleform::GFx::MovieImpl *v25; // r9
  unsigned __int64 v26; // r8
  __int64 v27; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v28; // r9
  Scaleform::GFx::InteractiveObject *v29; // rcx
  __int64 v30; // rcx
  Scaleform::GFx::AS2::Environment *v31; // rax
  Scaleform::GFx::AS2::Object *v32; // rax
  unsigned int v33; // ecx
  Scaleform::GFx::MovieImpl *v34; // rdx
  unsigned __int64 v35; // r8
  __int64 v36; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v37; // rdx
  __int64 v38; // rcx
  Scaleform::GFx::AS2::Environment *v39; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value val; // [rsp+60h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value presult; // [rsp+80h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+C0h] [rbp+8h] BYREF

  v8 = 0i64;
  v9 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v12 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v12].Level )
  {
    v12 = ++v9;
    if ( v9 >= Size )
      return 0;
  }
  if ( !Data[v9].pSprite.pObject )
    return 0;
  v14 = 0;
  v15 = 0i64;
  do
  {
    if ( !Data[v15].Level )
    {
      pObject = Data[v14].pSprite.pObject;
      goto LABEL_14;
    }
    v15 = ++v14;
  }
  while ( v14 < Size );
  pObject = 0i64;
LABEL_14:
  v17 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v18 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 240i64))(v17);
  Scaleform::GFx::AS2::Environment::CreateString(v18, &result, ppathToVar);
  presult.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v18, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v20 = Scaleform::GFx::AS2::Value::ToObject(&presult, v18), (v21 = v20) != 0i64)
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v20->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v20->Scaleform::GFx::AS2::ObjectInterface) == 7 )
  {
    v21->RefCount = (v21->RefCount + 1) & 0x8FFFFFFF;
    if ( count != v21[1].RootIndex )
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v21, count);
    v22 = 1;
  }
  else
  {
    v23 = (Scaleform::GFx::AS2::ArrayObject *)this->pMovieImpl->pHeap->vfptr->Alloc(v19, 144i64, 0i64);
    if ( v23 )
    {
      v24 = 0;
      v25 = this->pMovieImpl;
      v26 = v25->MovieLevels.Data.Size;
      if ( v26 )
      {
        v27 = 0i64;
        v28 = v25->MovieLevels.Data.Data;
        while ( v28[v27].Level )
        {
          v27 = ++v24;
          if ( v24 >= v26 )
            goto LABEL_28;
        }
        v29 = v28[v24].pSprite.pObject;
      }
      else
      {
LABEL_28:
        v29 = 0i64;
      }
      v30 = (__int64)v29 + 4 * (unsigned __int8)v29->AvmObjOffset;
      v31 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v30 + 240i64))(v30);
      Scaleform::GFx::AS2::ArrayObject::ArrayObject(v23, v31);
      v21 = v32;
    }
    else
    {
      v21 = 0i64;
    }
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v21, count);
    val.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObject(&val, (Scaleform::GFx::ASStringNode *)v21);
    v33 = 0;
    v34 = this->pMovieImpl;
    v35 = v34->MovieLevels.Data.Size;
    if ( v35 )
    {
      v36 = 0i64;
      v37 = v34->MovieLevels.Data.Data;
      while ( v37[v36].Level )
      {
        v36 = ++v33;
        if ( v33 >= v35 )
          goto LABEL_37;
      }
      v8 = v37[v33].pSprite.pObject;
    }
LABEL_37:
    v38 = (__int64)v8 + 4 * (unsigned __int8)v8->AvmObjOffset;
    v39 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v38 + 240i64))(v38);
    v22 = Scaleform::GFx::AS2::Environment::SetVariable(v39, &result, &val, 0i64, setType == SV_Normal);
    if ( !v22 && setType || setType == SV_Permanent )
      Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(this, &result, &val, setType);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  if ( v21 )
  {
    RefCount = v21->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v21->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
    }
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v22;
}

// File Line: 1976
// RVA: 0x6F7F00
__int64 __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariableArraySize(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *ppathToVar)
{
  unsigned int v3; // r8d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r10
  unsigned __int64 Size; // r9
  __int64 v6; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r10
  unsigned int v8; // ecx
  __int64 v9; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v11; // rcx
  Scaleform::GFx::AS2::Environment *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // rax
  Scaleform::GFx::AS2::Object *v14; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  v3 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0i64;
  v6 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v6].Level )
  {
    v6 = ++v3;
    if ( v3 >= Size )
      return 0i64;
  }
  if ( !Data[v3].pSprite.pObject )
    return 0i64;
  v8 = 0;
  v9 = 0i64;
  do
  {
    if ( !Data[v9].Level )
    {
      pObject = Data[v8].pSprite.pObject;
      goto LABEL_14;
    }
    v9 = ++v8;
  }
  while ( v8 < Size );
  pObject = 0i64;
LABEL_14:
  v11 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v12 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 240i64))(v11);
  Scaleform::GFx::AS2::Environment::CreateString(v12, &result, ppathToVar);
  presult.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(v12, &result, &presult, 0i64)
    && presult.T.Type == 6
    && (v13 = Scaleform::GFx::AS2::Value::ToObject(&presult, v12), (v14 = v13) != 0i64)
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v13->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v13->Scaleform::GFx::AS2::ObjectInterface) == 7 )
  {
    pPrev = v14[1].pPrev;
  }
  else
  {
    LODWORD(pPrev) = 0;
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (unsigned int)pPrev;
}

// File Line: 1998
// RVA: 0x6F7910
char __fastcall Scaleform::GFx::AS2::MovieRoot::GetVariableArray(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Movie::SetArrayType type,
        const char *ppathToVar,
        unsigned int index)
{
  __int64 v4; // r14
  unsigned int v8; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  unsigned int v13; // ecx
  __int64 v14; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v16; // rcx
  Scaleform::GFx::AS2::Environment *v17; // r15
  Scaleform::GFx::AS2::Object *v18; // rax
  Scaleform::GFx::AS2::Object *v19; // rdi
  Scaleform::GFx::MovieImpl::ReturnValueHolder *RetValHolder; // r13
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pPrev; // rbx
  unsigned int v22; // eax
  _DWORD *v23; // rbx
  __int64 v24; // rsi
  __int64 v25; // r14
  Scaleform::GFx::AS2::Value *v26; // rcx
  unsigned int v27; // eax
  float *v28; // rbx
  __int64 v29; // rsi
  __int64 v30; // r14
  Scaleform::GFx::AS2::Value *v31; // rcx
  float v32; // xmm1_4
  unsigned int v33; // eax
  long double *v34; // rbx
  __int64 v35; // r14
  __int64 v36; // rsi
  Scaleform::GFx::AS2::Value *v37; // rcx
  unsigned int v38; // ecx
  __int64 v39; // rsi
  _QWORD *v40; // rbx
  __int64 v41; // r12
  Scaleform::GFx::ASStringNode *v42; // r13
  Scaleform::GFx::AS2::Value *v43; // r14
  __int64 v44; // rsi
  unsigned int v45; // eax
  const char **v46; // rbx
  __int64 v47; // rax
  Scaleform::GFx::AS2::Value *v48; // rcx
  Scaleform::GFx::ASStringNode *v49; // r14
  __int64 StringArrayPos; // r12
  Scaleform::GFx::ASString *v51; // r13
  Scaleform::GFx::ASStringNode *v52; // rcx
  bool v53; // zf
  Scaleform::GFx::ASStringNode *v54; // rcx
  unsigned int v55; // r12d
  __int64 v56; // rsi
  unsigned __int64 v57; // rdx
  __int64 v58; // rsi
  __int64 *v59; // r13
  Scaleform::GFx::AS2::Value *v60; // rcx
  __int64 v61; // rax
  Scaleform::GFx::AS2::Value *v62; // r12
  Scaleform::GFx::ASStringNode *v63; // rcx
  unsigned int Length; // eax
  Scaleform::GFx::ASStringNode *v65; // rcx
  unsigned int v66; // ebx
  unsigned int CharBufferSize; // eax
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  __int64 v69; // rax
  char *CharBuffer; // rbx
  __int64 v71; // rdi
  char *v72; // r14
  unsigned int Char_Advance0; // eax
  Scaleform::GFx::ASStringNode *v74; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 v77; // [rsp+18h] [rbp-39h]
  __int64 *v78; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value *powner; // [rsp+28h] [rbp-29h] BYREF
  unsigned int excludeFlags; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v82; // [rsp+38h] [rbp-19h]
  __int64 v83; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-9h] BYREF
  __int64 v85; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::ASString v86; // [rsp+A8h] [rbp+57h] BYREF
  char *retaddr; // [rsp+C8h] [rbp+77h]
  unsigned int v88; // [rsp+D0h] [rbp+7Fh]

  v88 = (unsigned int)this;
  v85 = -2i64;
  v4 = index;
  v8 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v11 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= Size )
      return 0;
  }
  if ( !Data[v8].pSprite.pObject )
    return 0;
  v13 = 0;
  v14 = 0i64;
  while ( Data[v14].Level )
  {
    v14 = ++v13;
    if ( v13 >= Size )
    {
      pObject = 0i64;
      goto LABEL_12;
    }
  }
  pObject = Data[v13].pSprite.pObject;
LABEL_12:
  v16 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v17 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 240i64))(v16);
  Scaleform::GFx::AS2::Environment::CreateString(v17, &result, ppathToVar);
  presult.T.Type = 0;
  excludeFlags = 0;
  powner = 0i64;
  result.pNode = 0i64;
  if ( !Scaleform::GFx::AS2::Environment::GetVariable(v17, &result, &presult, 0i64)
    || presult.T.Type != 6
    || (v18 = Scaleform::GFx::AS2::Value::ToObject(&presult, v17), (v19 = v18) == 0i64)
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v18->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v18->Scaleform::GFx::AS2::ObjectInterface) != 7 )
  {
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    pNode = result.pNode;
    v53 = result.pNode->RefCount-- == 1;
    if ( v53 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 0;
  }
  RetValHolder = Scaleform::GFx::MovieImpl::GetRetValHolder(this->pMovieImpl);
  v82 = RetValHolder;
  RetValHolder->StringArrayPos = 0;
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
    &RetValHolder->StringArray.Data,
    1ui64);
  pPrev = v19[1].pPrev;
  switch ( type )
  {
    case SA_Int:
      v22 = v88;
      if ( (unsigned int)pPrev < v88 )
        v22 = (unsigned int)v19[1].pPrev;
      if ( v22 )
      {
        v23 = retaddr;
        v24 = v4;
        v25 = v22;
        do
        {
          v26 = (Scaleform::GFx::AS2::Value *)(&v19[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v24];
          if ( v26 )
            *v23 = (int)Scaleform::GFx::AS2::Value::ToNumber(v26, v17);
          else
            *v23 = 0;
          ++v24;
          ++v23;
          --v25;
        }
        while ( v25 );
      }
      break;
    case SA_Double:
      v33 = v88;
      if ( (unsigned int)pPrev < v88 )
        v33 = (unsigned int)v19[1].pPrev;
      if ( v33 )
      {
        v34 = (long double *)retaddr;
        v35 = 8 * v4 - (_QWORD)retaddr;
        v36 = v33;
        do
        {
          v37 = *(Scaleform::GFx::AS2::Value **)((char *)&v19[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr
                                               + v35
                                               + (unsigned __int64)v34);
          if ( v37 )
            *v34 = Scaleform::GFx::AS2::Value::ToNumber(v37, v17);
          else
            *v34 = 0.0;
          ++v34;
          --v36;
        }
        while ( v36 );
      }
      break;
    case SA_Float:
      v27 = v88;
      if ( (unsigned int)pPrev < v88 )
        v27 = (unsigned int)v19[1].pPrev;
      if ( v27 )
      {
        v28 = (float *)retaddr;
        v29 = v4;
        v30 = v27;
        do
        {
          v31 = (Scaleform::GFx::AS2::Value *)(&v19[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v29];
          if ( v31 )
          {
            v32 = Scaleform::GFx::AS2::Value::ToNumber(v31, v17);
            *v28 = v32;
          }
          else
          {
            *v28 = 0.0;
          }
          ++v29;
          ++v28;
          --v30;
        }
        while ( v30 );
      }
      break;
    case SA_String:
      v44 = v88;
      if ( (unsigned int)pPrev < v88 )
        v44 = (unsigned int)pPrev;
      v45 = v44;
      if ( !(_DWORD)v44 )
        v45 = 1;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &RetValHolder->StringArray.Data,
        v45);
      if ( (_DWORD)v44 )
      {
        v46 = (const char **)retaddr;
        v47 = 8 * v4 - (_QWORD)retaddr;
        v77 = v47;
        do
        {
          v48 = *(Scaleform::GFx::AS2::Value **)((char *)v46 + v47 + (unsigned __int64)v19[1].pRCC);
          if ( v48 )
          {
            Scaleform::GFx::AS2::Value::ToString(v48, &v86, v17, -1);
            v49 = v86.pNode;
            *v46 = v86.pNode->pData;
            StringArrayPos = RetValHolder->StringArrayPos;
            RetValHolder->StringArrayPos = StringArrayPos + 1;
            v51 = RetValHolder->StringArray.Data.Data;
            ++v49->RefCount;
            v52 = v51[StringArrayPos].pNode;
            v53 = v52->RefCount-- == 1;
            if ( v53 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v52);
            v51[StringArrayPos].pNode = v49;
            v54 = v86.pNode;
            v53 = v86.pNode->RefCount-- == 1;
            if ( v53 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
            RetValHolder = v82;
          }
          else
          {
            *v46 = 0i64;
          }
          ++v46;
          --v44;
          v47 = v77;
        }
        while ( v44 );
      }
      break;
    case SA_StringW:
      v55 = 0;
      LODWORD(v86.pNode) = 0;
      v56 = v88;
      if ( (unsigned int)pPrev < v88 )
        v56 = (unsigned int)pPrev;
      excludeFlags = v56;
      v57 = (unsigned int)v56;
      if ( !(_DWORD)v56 )
        v57 = 1i64;
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &RetValHolder->StringArray.Data,
        v57);
      if ( (_DWORD)pPrev )
      {
        v58 = 0i64;
        pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(unsigned int)pPrev;
        v59 = v78;
        do
        {
          v60 = (Scaleform::GFx::AS2::Value *)(&(&v19[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v4])[v58];
          if ( v60 )
          {
            Scaleform::GFx::AS2::Value::ToString(v60, (Scaleform::GFx::ASString *)&powner, v17, -1);
            v83 = *v59;
            v61 = v83;
            v62 = powner;
            ++*((_DWORD *)&powner->NV + 6);
            v63 = *(Scaleform::GFx::ASStringNode **)(v58 * 8 + v61);
            v53 = v63->RefCount-- == 1;
            if ( v53 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v63);
              v61 = v83;
            }
            *(_QWORD *)(v58 * 8 + v61) = v62;
            Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&powner);
            v55 = Length + LODWORD(v86.pNode) + 1;
            LODWORD(v86.pNode) = v55;
            v65 = (Scaleform::GFx::ASStringNode *)powner;
            v53 = (*((_DWORD *)&powner->NV + 6))-- == 1;
            if ( v53 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v65);
          }
          ++v58;
          pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)pPrev - 1);
        }
        while ( pPrev );
        RetValHolder = v82;
        v56 = excludeFlags;
      }
      v66 = (2 * v55 + 4095) & 0xFFFFF000;
      CharBufferSize = RetValHolder->CharBufferSize;
      if ( CharBufferSize < v66 || CharBufferSize > v66 && CharBufferSize - v66 > 0x1000 )
      {
        vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
        if ( RetValHolder->CharBuffer )
          v69 = (__int64)vfptr->Realloc(Scaleform::Memory::pGlobalHeap, RetValHolder->CharBuffer, v66);
        else
          v69 = (__int64)vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v66, 0i64);
        RetValHolder->CharBuffer = (char *)v69;
        RetValHolder->CharBufferSize = v66;
      }
      CharBuffer = RetValHolder->CharBuffer;
      if ( (_DWORD)v56 )
      {
        v71 = 0i64;
        do
        {
          v86.pNode = **(Scaleform::GFx::ASStringNode ***)(v71 + *v78);
          v72 = CharBuffer;
          while ( 1 )
          {
            Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v86);
            if ( !Char_Advance0 )
              break;
            *(_WORD *)CharBuffer = Char_Advance0;
            CharBuffer += 2;
          }
          --v86.pNode;
          *(_WORD *)CharBuffer = 0;
          CharBuffer += 2;
          *(_QWORD *)&retaddr[v71] = v72;
          v71 += 8i64;
          --v56;
        }
        while ( v56 );
      }
      Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        &RetValHolder->StringArray.Data,
        1ui64);
      break;
    case SA_Value:
      v38 = v88;
      if ( (unsigned int)pPrev < v88 )
        v38 = (unsigned int)v19[1].pPrev;
      if ( v38 )
      {
        v39 = v4;
        v40 = retaddr + 16;
        v41 = v38;
        v42 = v86.pNode;
        do
        {
          v43 = (Scaleform::GFx::AS2::Value *)(&v19[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v39];
          if ( (v40[1] & 0x40) != 0 )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v40 + 16i64))(*v40, v40 - 2, v40[2]);
            *v40 = 0i64;
          }
          *((_DWORD *)v40 + 2) = 0;
          if ( v43 )
            Scaleform::GFx::AS2::MovieRoot::ASValue2Value(
              (Scaleform::GFx::AS2::MovieRoot *)v42,
              v17,
              v43,
              (Scaleform::GFx::Value *)(v40 - 2));
          else
            *((_DWORD *)v40 + 2) = 0;
          ++v39;
          v40 += 6;
          --v41;
        }
        while ( v41 );
      }
      break;
    default:
      break;
  }
  if ( presult.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presult);
  v74 = result.pNode;
  v53 = result.pNode->RefCount-- == 1;
  if ( v53 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v74);
  return 1;
}

// File Line: 2141
// RVA: 0x6D9620
void __fastcall Scaleform::GFx::AS2::MovieRoot::AddStickyVariable(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::ASString *fullPath,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::Movie::SetVarType setType)
{
  Scaleform::GFx::AS2::GlobalContext *pObject; // rdi
  bool v8; // al
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *vfptr; // rdi
  Scaleform::GFx::ASStringNode *pData; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rax
  int Length; // eax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rsi
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *pContext; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rdi
  Scaleform::GFx::ASStringNode *v23; // rcx
  void *v24; // rdi
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString pvar; // [rsp+20h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-28h] BYREF
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+30h] [rbp-20h] BYREF
  __int64 v29; // [rsp+40h] [rbp-10h]
  Scaleform::GFx::ASString ppath; // [rsp+80h] [rbp+30h] BYREF

  v29 = -2i64;
  pObject = this->pGlobalContext.pObject;
  psc.pContext = pObject;
  psc.SWFVersion = 8;
  ppath.pNode = *(Scaleform::GFx::ASStringNode **)&pObject->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++ppath.pNode->RefCount;
  pvar.pNode = *(Scaleform::GFx::ASStringNode **)&pObject->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  ++pvar.pNode->RefCount;
  v8 = Scaleform::GFx::AS2::Environment::ParsePath(&psc, fullPath, &ppath, &pvar);
  pNode = pvar.pNode;
  if ( v8 )
  {
    v13 = ppath.pNode;
    if ( ppath.pNode->Size < 5 )
      goto LABEL_18;
    if ( *(_DWORD *)ppath.pNode->pData == *(_DWORD *)aRoo && *((_BYTE *)ppath.pNode->pData + 4) == 116 )
    {
      Length = Scaleform::GFx::ASConstString::GetLength(&ppath);
      v15 = Scaleform::GFx::ASString::Substring(&ppath, (Scaleform::GFx::ASString *)&psc, 5, Length);
      v16 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&pObject->pMovieRoot->pASMovieRoot.pObject[21],
              &result,
              v15);
      v17 = v16->pNode;
      ++v16->pNode->RefCount;
      v18 = ppath.pNode;
      v12 = ppath.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      ppath.pNode = v17;
      v19 = result.pNode;
      v12 = result.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      pContext = (Scaleform::GFx::ASStringNode *)psc.pContext;
      v12 = LODWORD(psc.pContext->RegisteredClasses.mHash.pTable)-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pContext);
      v13 = ppath.pNode;
    }
    pData = (Scaleform::GFx::ASStringNode *)v13->pData;
    if ( *(_DWORD *)v13->pData != *(_DWORD *)aLev || WORD2(pData->pData) != 27749 )
    {
LABEL_18:
      v21 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)&pObject->pMovieRoot->pASMovieRoot.pObject[21].RefCount,
              (Scaleform::GFx::ASString *)&psc,
              &ppath);
      v22 = v21->pNode;
      ++v21->pNode->RefCount;
      v23 = ppath.pNode;
      v12 = ppath.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      ppath.pNode = v22;
      pData = (Scaleform::GFx::ASStringNode *)psc.pContext;
      v12 = LODWORD(psc.pContext->RegisteredClasses.mHash.pTable)-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pData);
    }
  }
  else
  {
    if ( !pvar.pNode->Size )
      goto LABEL_27;
    vfptr = (Scaleform::GFx::ASStringNode *)pObject->pMovieRoot->pASMovieRoot.pObject[21].vfptr;
    ++vfptr->RefCount;
    pData = ppath.pNode;
    v12 = ppath.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pData);
    ppath.pNode = vfptr;
  }
  psc.pContext = (Scaleform::GFx::AS2::GlobalContext *)this->pMovieImpl->pHeap;
  v24 = psc.pContext->vfptr[10].__vecDelDtor(pData, 64i64);
  result.pNode = (Scaleform::GFx::ASStringNode *)v24;
  if ( v24 )
  {
    *(_QWORD *)v24 = &Scaleform::GFx::MovieImpl::StickyVarNode::`vftable;
    *((_QWORD *)v24 + 1) = pNode;
    ++pNode->RefCount;
    *((_QWORD *)v24 + 2) = 0i64;
    *((_BYTE *)v24 + 24) = setType == SV_Permanent;
    *(_QWORD *)v24 = &Scaleform::GFx::AS2::MovieRoot::StickyVarNode::`vftable;
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v24 + 1, val);
  }
  else
  {
    v24 = 0i64;
  }
  if ( v24 )
    Scaleform::GFx::MovieImpl::AddStickyVariableNode(
      this->pMovieImpl,
      &ppath,
      (Scaleform::GFx::MovieImpl::StickyVarNode *)v24);
LABEL_27:
  v12 = pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v25 = ppath.pNode;
  v12 = ppath.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
}

// File Line: 2207
// RVA: 0x7125F0
void __fastcall Scaleform::GFx::AS2::MovieRoot::ResolveStickyVariables(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::AS2::MovieRoot *v4; // rdi
  Scaleform::GFx::ASString *p_NamePath; // r12
  char *v6; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_mHash; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v9; // rbx
  __int64 v10; // rax
  unsigned __int64 *v11; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *v12; // r14
  __int64 v13; // r15
  __int64 v14; // rbx
  Scaleform::GFx::MovieImpl::StickyVarNode *v15; // r12
  Scaleform::GFx::MovieImpl::StickyVarNodeVtbl *vfptr; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbp
  __int64 v18; // rax
  __int64 v19; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::MovieImpl::StickyVarNode *value; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ASString *key; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::MovieImpl::StickyVarNode *v24; // [rsp+98h] [rbp+20h]

  pObject = pch->pNameHandle.pObject;
  v4 = this;
  if ( !pObject )
    pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pch);
  p_NamePath = &pObject->NamePath;
  v6 = (char *)pch + 4 * (unsigned __int8)pch->AvmObjOffset;
  key = &pObject->NamePath;
  v7 = (Scaleform::GFx::MovieImpl::StickyVarNode *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 8i64))(v6);
  p_mHash = &v4->pMovieImpl->StickyVariables.mHash;
  value = v7;
  v9.pTable = p_mHash->pTable;
  if ( p_mHash->pTable )
  {
    v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            p_mHash,
            p_NamePath,
            v9.pTable->SizeMask & p_NamePath->pNode->HashFlags);
    if ( v10 >= 0 )
    {
      v11 = &v9.pTable[1].SizeMask + 3 * v10;
      if ( v11 )
      {
        v12 = 0i64;
        v13 = 0i64;
        v24 = (Scaleform::GFx::MovieImpl::StickyVarNode *)v11[1];
        v14 = (__int64)v24;
        if ( v24 )
        {
          v15 = value;
          do
          {
            vfptr = v15->vfptr;
            pNode = v15->Name.pNode;
            LOBYTE(value) = 0;
            v18 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl::StickyVarNode *))vfptr[15].__vecDelDtor)(v15);
            (*(void (__fastcall **)(Scaleform::GFx::ASString *, __int64, __int64, __int64, Scaleform::GFx::MovieImpl::StickyVarNode **))&pNode->RefCount)(
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
              (**(void (__fastcall ***)(__int64, __int64))v14)(v14, 1i64);
            }
            v14 = v19;
          }
          while ( v19 );
          p_NamePath = key;
          if ( v12 )
          {
            if ( v12 != v24 )
            {
              pMovieImpl = this->pMovieImpl;
              value = v12;
              Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Set(
                &pMovieImpl->StickyVariables,
                key,
                &value);
            }
            return;
          }
          v4 = this;
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
          &v4->pMovieImpl->StickyVariables.mHash,
          p_NamePath);
      }
    }
  }
}

// File Line: 2270
// RVA: 0x6EB5A0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::MovieRoot::FindTarget(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::ASString *path)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r10
  Scaleform::GFx::InteractiveObject *pObject; // r11
  unsigned __int64 Size; // r9
  unsigned int v6; // r8d
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r10
  __int64 v8; // rax
  unsigned int v10; // ecx
  __int64 v11; // rax
  __int64 v12; // rcx
  Scaleform::GFx::AS2::Environment *v13; // rax

  pMovieImpl = this->pMovieImpl;
  pObject = 0i64;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( !Size )
    return 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  v8 = 0i64;
  while ( Data[v8].Level )
  {
    v8 = ++v6;
    if ( v6 >= Size )
      return 0i64;
  }
  if ( !Data[v6].pSprite.pObject || !path->pNode->Size )
    return 0i64;
  v10 = 0;
  v11 = 0i64;
  while ( Data[v11].Level )
  {
    v11 = ++v10;
    if ( v10 >= Size )
      goto LABEL_14;
  }
  pObject = Data[v10].pSprite.pObject;
LABEL_14:
  v12 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v13 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 240i64))(v12);
  return Scaleform::GFx::AS2::Environment::FindTarget(v13, path, 0);
}

// File Line: 2301
// RVA: 0x704860
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyOnResize(Scaleform::GFx::AS2::MovieRoot *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned int v2; // edx
  unsigned __int64 Size; // r8
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  __int64 v6; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rdi
  Scaleform::GFx::MovieImpl *v8; // rbx
  unsigned int v9; // edx
  unsigned __int64 v10; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v11; // rbx
  __int64 v12; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  Scaleform::RefCountNTSImpl *v14; // rcx
  Scaleform::RefCountNTSImpl *v15; // rcx

  pMovieImpl = this->pMovieImpl;
  v2 = 0;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v6 = 0i64;
    while ( Data[v6].Level )
    {
      v6 = ++v2;
      if ( v2 >= Size )
        return;
    }
    if ( Data[v2].pSprite.pObject )
    {
      inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(&this->ActionQueue, AP_Frame);
      if ( inserted )
      {
        v8 = this->pMovieImpl;
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
          pObject = v11[v9].pSprite.pObject;
        }
        else
        {
LABEL_12:
          pObject = 0i64;
        }
        inserted->Type = Entry_CFunction;
        if ( pObject )
          ++pObject->RefCount;
        v14 = inserted->pCharacter.pObject;
        if ( v14 )
          Scaleform::RefCountNTSImpl::Release(v14);
        inserted->pCharacter.pObject = pObject;
        v15 = inserted->pActionBuffer.pObject;
        if ( v15 )
          Scaleform::RefCountNTSImpl::Release(v15);
        inserted->pActionBuffer.pObject = 0i64;
        inserted->CFunction = Scaleform::GFx::AS2::StageCtorFunction::NotifyOnResize;
      }
    }
  }
}

// File Line: 2313
// RVA: 0x7002B0
char __fastcall Scaleform::GFx::AS2::MovieRoot::IsAvailable(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pathToVar)
{
  Scaleform::GFx::InteractiveObject *pObject; // r11
  unsigned int v4; // r8d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r10
  unsigned __int64 Size; // r9
  __int64 v7; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r10
  unsigned int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rcx
  Scaleform::GFx::AS2::Environment *v12; // rbx
  char IsAvailable; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  pObject = 0i64;
  v4 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v7 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v7].Level )
  {
    v7 = ++v4;
    if ( v4 >= Size )
      return 0;
  }
  if ( !Data[v4].pSprite.pObject )
    return 0;
  v9 = 0;
  v10 = 0i64;
  while ( Data[v10].Level )
  {
    v10 = ++v9;
    if ( v9 >= Size )
      goto LABEL_13;
  }
  pObject = Data[v9].pSprite.pObject;
LABEL_13:
  v11 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v12 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 240i64))(v11);
  Scaleform::GFx::AS2::Environment::CreateString(v12, &result, pathToVar);
  IsAvailable = Scaleform::GFx::AS2::Environment::IsAvailable(v12, &result, 0i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return IsAvailable;
}

// File Line: 2325
// RVA: 0x6FEF20
__int64 __fastcall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r11
  Scaleform::GFx::InteractiveObject *pObject; // rdx
  unsigned __int64 Size; // rbx
  unsigned int v9; // r10d
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r11
  __int64 v11; // rax

  pMovieImpl = this->pMovieImpl;
  pObject = 0i64;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v9 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v11 = 0i64;
    while ( Data[v11].Level )
    {
      v11 = ++v9;
      if ( v9 >= Size )
        return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::InteractiveObject *, const char *, Scaleform::GFx::Value *, Scaleform::GFx::Value *, unsigned int))this->vfptr[61].__vecDelDtor)(
                 this,
                 pObject,
                 pmethodName,
                 presult,
                 pargs,
                 numArgs);
    }
    pObject = Data[v9].pSprite.pObject;
  }
  return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *, Scaleform::GFx::InteractiveObject *, const char *, Scaleform::GFx::Value *, Scaleform::GFx::Value *, unsigned int))this->vfptr[61].__vecDelDtor)(
           this,
           pObject,
           pmethodName,
           presult,
           pargs,
           numArgs);
}

// File Line: 2332
// RVA: 0x6FEB30
char __fastcall Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *thisCont,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        Scaleform::GFx::Value *pargs,
        unsigned int numArgs)
{
  Scaleform::RefCountNTSImpl **v9; // r15
  Scaleform::GFx::AS2::Environment *v10; // r13
  unsigned int v11; // ebp
  int v12; // esi
  Scaleform::GFx::Value *v13; // rdi
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v15; // rax
  char v16; // di
  Scaleform::RefCountNTSImpl *v17; // rbx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value presulta; // [rsp+40h] [rbp-78h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [rsp+60h] [rbp-58h] BYREF

  if ( !thisCont
    || ((unsigned int (__fastcall *)(Scaleform::GFx::InteractiveObject *))thisCont->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(thisCont) != 3 )
  {
    return 0;
  }
  presulta.T.Type = 0;
  v9 = (Scaleform::RefCountNTSImpl **)((char *)thisCont + 4 * (unsigned __int8)thisCont->AvmObjOffset);
  v10 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::RefCountNTSImpl **))(*v9)[15].vfptr)(v9);
  v11 = numArgs;
  v12 = numArgs - 1;
  if ( (int)(numArgs - 1) >= 0 )
  {
    v13 = &pargs[v12];
    do
    {
      pdestVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, v13, &pdestVal);
      if ( ++v10->Stack.pCurrent >= v10->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v10->Stack);
      pCurrent = v10->Stack.pCurrent;
      if ( pCurrent )
        Scaleform::GFx::AS2::Value::Value(pCurrent, &pdestVal);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      --v13;
      --v12;
    }
    while ( v12 >= 0 );
  }
  if ( this->pInvokeAliases && (v15 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) != 0i64 )
  {
    v16 = Scaleform::GFx::AS2::MovieRoot::InvokeAlias(this, pmethodName, v15, &presulta, numArgs);
  }
  else
  {
    v17 = v9[3];
    if ( v17 )
      ++v17->RefCount;
    v16 = Scaleform::GFx::AS2::GAS_Invoke(
            pmethodName,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)(v9 + 1),
            (Scaleform::GFx::AS2::Environment *)(v9 + 6));
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
  }
  if ( numArgs )
  {
    do
    {
      v18 = v10->Stack.pCurrent;
      if ( v18->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v18);
      if ( --v10->Stack.pCurrent < v10->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v10->Stack);
      --v11;
    }
    while ( v11 );
  }
  if ( v16 && presult )
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v10, &presulta, presult);
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v16;
}

// File Line: 2374
// RVA: 0x6FED40
char Scaleform::GFx::AS2::MovieRoot::Invoke(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt,
        ...)
{
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned int v8; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r10
  unsigned __int64 Size; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r10
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v13; // rax
  char v14; // si
  unsigned int v15; // ecx
  Scaleform::GFx::MovieImpl *v16; // r8
  unsigned __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 AvmObjOffset; // rax
  Scaleform::RefCountNTSImpl *v22; // rbx
  unsigned int v23; // ecx
  Scaleform::GFx::MovieImpl *v24; // r8
  unsigned __int64 v25; // rdx
  __int64 v26; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v27; // r8
  __int64 v28; // rcx
  Scaleform::GFx::AS2::Environment *v29; // rax
  Scaleform::GFx::AS2::Value presulta; // [rsp+40h] [rbp-58h] BYREF
  va_list va; // [rsp+C0h] [rbp+28h] BYREF

  va_start(va, pargFmt);
  v7 = 0i64;
  v8 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v11 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= Size )
      return 0;
  }
  if ( !Data[v8].pSprite.pObject )
    return 0;
  presulta.T.Type = 0;
  if ( this->pInvokeAliases && (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) != 0i64 )
  {
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(this, pmethodName, v13, &presulta, pargFmt, va);
  }
  else
  {
    v15 = 0;
    v16 = this->pMovieImpl;
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
      pObject = v19[v15].pSprite.pObject;
    }
    else
    {
LABEL_16:
      pObject = 0i64;
    }
    AvmObjOffset = (unsigned __int8)pObject->AvmObjOffset;
    v22 = *(Scaleform::RefCountNTSImpl **)((char *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr
                                         + 4 * AvmObjOffset);
    if ( v22 )
      ++v22->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            pmethodName,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)(&pObject->RefCount + AvmObjOffset),
            (Scaleform::GFx::AS2::Environment *)(&pObject->CreateFrame + AvmObjOffset));
    if ( v22 )
      Scaleform::RefCountNTSImpl::Release(v22);
  }
  if ( v14 && presult )
  {
    v23 = 0;
    v24 = this->pMovieImpl;
    v25 = v24->MovieLevels.Data.Size;
    if ( v25 )
    {
      v26 = 0i64;
      v27 = v24->MovieLevels.Data.Data;
      while ( v27[v26].Level )
      {
        v26 = ++v23;
        if ( v23 >= v25 )
          goto LABEL_29;
      }
      v7 = v27[v23].pSprite.pObject;
    }
LABEL_29:
    v28 = (__int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset;
    v29 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v28 + 240i64))(v28);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v29, &presulta, presult);
  }
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v14;
}

// File Line: 2405
// RVA: 0x6FF4C0
char __fastcall Scaleform::GFx::AS2::MovieRoot::InvokeArgs(
        Scaleform::GFx::AS2::MovieRoot *this,
        const char *pmethodName,
        Scaleform::GFx::Value *presult,
        const char *pargFmt)
{
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned int v8; // r10d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r11
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *v13; // rax
  char v14; // si
  unsigned int v15; // ecx
  Scaleform::GFx::MovieImpl *v16; // r8
  unsigned __int64 v17; // rdx
  __int64 v18; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v19; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 AvmObjOffset; // rax
  Scaleform::RefCountNTSImpl *v22; // rbx
  unsigned int v23; // ecx
  Scaleform::GFx::MovieImpl *v24; // r8
  unsigned __int64 v25; // rdx
  __int64 v26; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v27; // r8
  __int64 v28; // rcx
  Scaleform::GFx::AS2::Environment *v29; // rax
  Scaleform::GFx::AS2::Value presulta; // [rsp+38h] [rbp-40h] BYREF

  v7 = 0i64;
  v8 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    return 0;
  v11 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v11].Level )
  {
    v11 = ++v8;
    if ( v8 >= Size )
      return 0;
  }
  if ( !Data[v8].pSprite.pObject )
    return 0;
  presulta.T.Type = 0;
  if ( this->pInvokeAliases && (v13 = Scaleform::GFx::AS2::MovieRoot::ResolveInvokeAlias(this, pmethodName)) != 0i64 )
  {
    v14 = Scaleform::GFx::AS2::MovieRoot::InvokeAliasArgs(this, pmethodName, v13, &presulta);
  }
  else
  {
    v15 = 0;
    v16 = this->pMovieImpl;
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
      pObject = v19[v15].pSprite.pObject;
    }
    else
    {
LABEL_16:
      pObject = 0i64;
    }
    AvmObjOffset = (unsigned __int8)pObject->AvmObjOffset;
    v22 = *(Scaleform::RefCountNTSImpl **)((char *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr
                                         + 4 * AvmObjOffset);
    if ( v22 )
      ++v22->RefCount;
    v14 = Scaleform::GFx::AS2::GAS_InvokeParsed(
            pmethodName,
            &presulta,
            (Scaleform::GFx::AS2::ObjectInterface *)(&pObject->RefCount + AvmObjOffset),
            (Scaleform::GFx::AS2::Environment *)(&pObject->CreateFrame + AvmObjOffset));
    if ( v22 )
      Scaleform::RefCountNTSImpl::Release(v22);
  }
  if ( v14 && presult )
  {
    v23 = 0;
    v24 = this->pMovieImpl;
    v25 = v24->MovieLevels.Data.Size;
    if ( v25 )
    {
      v26 = 0i64;
      v27 = v24->MovieLevels.Data.Data;
      while ( v27[v26].Level )
      {
        v26 = ++v23;
        if ( v23 >= v25 )
          goto LABEL_29;
      }
      v7 = v27[v23].pSprite.pObject;
    }
LABEL_29:
    v28 = (__int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset;
    v29 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v28 + 240i64))(v28);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v29, &presulta, presult);
  }
  if ( presulta.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&presulta);
  return v14;
}

// File Line: 2433
// RVA: 0x714610
void __fastcall Scaleform::GFx::AS2::MovieRoot::SetExternalInterfaceRetVal(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *retVal)
{
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(this, retVal, &this->ExternalIntfRetVal);
}

// File Line: 2438
// RVA: 0x703800
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyMouseEvent(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InputEventsQueueEntry *qe,
        Scaleform::GFx::MouseState *ms,
        unsigned int mi)
{
  unsigned int v8; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  unsigned __int64 Size; // r10
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r9
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v14; // rcx
  Scaleform::GFx::AS2::Environment *v15; // r14
  Scaleform::GFx::AS2::MouseListener *pASMouseListener; // rcx
  bool v17; // r13
  float PosY; // xmm1_4
  Scaleform::GFx::InteractiveObject *TopMostEntity; // rax
  Scaleform::GFx::InteractiveObject *v20; // rsi
  Scaleform::RefCountNTSImpl *v21; // rcx
  __int16 v22; // di
  unsigned int v23; // ebp
  Scaleform::Render::Point<float> mousePos; // [rsp+70h] [rbp+8h] BYREF

  v8 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v11 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v11].Level )
    {
      v11 = ++v8;
      if ( v8 >= Size )
        goto LABEL_7;
    }
    pObject = Data[v8].pSprite.pObject;
  }
  else
  {
LABEL_7:
    pObject = 0i64;
  }
  v14 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v15 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 240i64))(v14);
  pASMouseListener = this->pASMouseListener;
  if ( pASMouseListener
    && !pASMouseListener->vfptr->IsEmpty(pASMouseListener)
    && ((*((_BYTE *)ms + 76) & 8) != 0 || qe->u.mouseEntry.ButtonsState || (qe->u.mouseEntry.Flags & 0x20) != 0) )
  {
    v17 = v15->StringContext.pContext->GFxExtensions.Value == 1;
    if ( (*((_BYTE *)ms + 76) & 8) != 0 )
      this->pASMouseListener->vfptr->OnMouseMove(this->pASMouseListener, v15, mi);
    if ( (qe->u.mouseEntry.Flags & 0x20) != 0 || qe->u.mouseEntry.ButtonsState )
    {
      PosY = qe->u.mouseEntry.PosY;
      LODWORD(mousePos.x) = qe->u.keyEntry.WcharCode;
      mousePos.y = PosY;
      TopMostEntity = Scaleform::GFx::MovieImpl::GetTopMostEntity(this->pMovieImpl, &mousePos, mi, 1, 0i64);
      v20 = TopMostEntity;
      if ( TopMostEntity )
        ++TopMostEntity->RefCount;
      if ( TopMostEntity && TopMostEntity->pASRoot->AVMVersion != 1 )
      {
        v21 = TopMostEntity;
LABEL_35:
        Scaleform::RefCountNTSImpl::Release(v21);
        return;
      }
      if ( (qe->u.mouseEntry.Flags & 0x20) != 0 )
        this->pASMouseListener->vfptr->OnMouseWheel(
          this->pASMouseListener,
          v15,
          mi,
          qe->u.mouseEntry.WheelScrollDelta,
          TopMostEntity);
      if ( qe->u.mouseEntry.ButtonsState )
      {
        v22 = 1;
        v23 = 1;
        do
        {
          if ( (qe->u.mouseEntry.ButtonsState & (unsigned __int16)v22) != 0 )
          {
            if ( (qe->u.mouseEntry.Flags & 0xC0) != 0 || !qe->u.mouseEntry.ButtonsState )
              this->pASMouseListener->vfptr->OnMouseUp(this->pASMouseListener, v15, mi, v23, v20);
            else
              this->pASMouseListener->vfptr->OnMouseDown(this->pASMouseListener, v15, mi, v23, v20);
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
        v21 = v20;
        goto LABEL_35;
      }
    }
  }
}

// File Line: 2477
// RVA: 0x703C40
bool __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyOnFocusChange(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *curFocused,
        Scaleform::GFx::InteractiveObject *newFocus,
        __int64 __formal,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::InteractiveObject *v6; // r8

  v6 = curFocused;
  return fmt != GFx_FocusMovedByMouse
      || curFocused
      && curFocused->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor(
           curFocused,
           1i64)
      || newFocus
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int64, Scaleform::GFx::InteractiveObject *, __int64))newFocus->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor)(
           newFocus,
           1i64,
           v6,
           __formal);
}

// File Line: 2490
// RVA: 0x6DC550
void __fastcall Scaleform::GFx::AS2::MovieRoot::ChangeMouseCursorType(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int mouseIdx,
        int newCursorType)
{
  __int64 v4; // rdi
  unsigned int v6; // r9d
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // r10
  __int64 v9; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::AS2::Environment *v14; // rsi
  Scaleform::GFx::MovieImpl *v15; // rdx
  Scaleform::GFx::AS2::Object *v16; // rax
  __int64 pCurrent; // rax
  __int64 v18; // rax
  int v19; // edi
  __int64 v20; // rax
  Scaleform::GFx::AS2::Value *v21; // rcx
  Scaleform::GFx::AS2::Value *v22; // rcx
  Scaleform::GFx::AS2::Value *v23; // rcx
  char v24; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v25; // rcx
  int v26; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::UserEventHandler *v29; // rcx
  char FirstIn; // [rsp+28h] [rbp-79h]
  Scaleform::GFx::AS2::Value ThisIn; // [rsp+30h] [rbp-71h] BYREF
  Scaleform::GFx::AS2::Value v32; // [rsp+50h] [rbp-51h] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [rsp+70h] [rbp-31h] BYREF
  __int64 v34; // [rsp+90h] [rbp-11h]
  Scaleform::GFx::AS2::FnCall v35; // [rsp+98h] [rbp-9h] BYREF
  __int64 v36; // [rsp+108h] [rbp+67h]

  v34 = -2i64;
  v4 = mouseIdx;
  v6 = 0;
  pMovieImpl = this->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( Size )
  {
    v9 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v9].Level )
    {
      v9 = ++v6;
      if ( v6 >= Size )
        goto LABEL_7;
    }
    pObject = Data[v6].pSprite.pObject;
  }
  else
  {
LABEL_7:
    pObject = 0i64;
  }
  v12 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 240i64))(v12);
  v14 = (Scaleform::GFx::AS2::Environment *)v13;
  v15 = this->pMovieImpl;
  if ( (v15->Flags & 0x1000) != 0 && *(_BYTE *)(*(_QWORD *)(v13 + 232) + 104i64) == 1 )
  {
    ThisIn.T.Type = 0;
    if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64, __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 232) + 96i64) + 32i64) + 88i64))(
           *(_QWORD *)(*(_QWORD *)(v13 + 232) + 96i64) + 32i64,
           v13 + 232,
           *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 232) + 40i64) + 24i64) + 528i64,
           &ThisIn) )
    {
      v16 = Scaleform::GFx::AS2::Value::ToObject(&ThisIn, v14);
      if ( v16 )
      {
        v32.T.Type = 0;
        if ( v16->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember(
               &v16->Scaleform::GFx::AS2::ObjectInterface,
               v14,
               (Scaleform::GFx::ASString *)&v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[35],
               &v32) )
        {
          Scaleform::GFx::AS2::Value::ToFunction(&v32, (Scaleform::GFx::AS2::FunctionRef *)&ThisIn, v14);
          if ( *(_QWORD *)&ThisIn.T.Type )
          {
            ResIn.T.Type = 0;
            if ( ++v14->Stack.pCurrent >= v14->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v14->Stack);
            pCurrent = (__int64)v14->Stack.pCurrent;
            v36 = pCurrent;
            if ( pCurrent )
            {
              *(_BYTE *)pCurrent = 3;
              *(double *)(pCurrent + 8) = (double)(int)v4;
            }
            if ( ++v14->Stack.pCurrent >= v14->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v14->Stack);
            v18 = (__int64)v14->Stack.pCurrent;
            v36 = v18;
            if ( v18 )
            {
              *(_BYTE *)v18 = 3;
              *(double *)(v18 + 8) = (double)newCursorType;
            }
            v19 = 2;
            Scaleform::GFx::AS2::FnCall::FnCall(
              &v35,
              &ResIn,
              &ThisIn,
              v14,
              2,
              32 * v14->Stack.Pages.Data.Size - 32 + v14->Stack.pCurrent - v14->Stack.pPageStart);
            (*(void (__fastcall **)(_QWORD, __int64, Scaleform::GFx::ASStringNode *, _QWORD))(**(_QWORD **)&ThisIn.T.Type
                                                                                            + 80i64))(
              *(_QWORD *)&ThisIn.T.Type,
              v20,
              ThisIn.V.pStringNode,
              0i64);
            Scaleform::GFx::AS2::FnCall::~FnCall(&v35);
            v21 = v14->Stack.pCurrent;
            if ( &v21[-2] >= v14->Stack.pPageStart )
            {
              if ( v21->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v21);
              v23 = --v14->Stack.pCurrent;
              if ( v23->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v23);
              --v14->Stack.pCurrent;
            }
            else
            {
              do
              {
                v22 = v14->Stack.pCurrent;
                if ( v22->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v22);
                if ( --v14->Stack.pCurrent < v14->Stack.pPageStart )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v14->Stack);
                --v19;
              }
              while ( v19 );
            }
            if ( ResIn.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
          }
          v24 = FirstIn;
          if ( (FirstIn & 2) == 0 )
          {
            v25 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&ThisIn.T.Type;
            if ( *(_QWORD *)&ThisIn.T.Type )
            {
              v26 = *(_DWORD *)(*(_QWORD *)&ThisIn.T.Type + 24i64);
              if ( (v26 & 0x3FFFFFF) != 0 )
              {
                *(_DWORD *)(*(_QWORD *)&ThisIn.T.Type + 24i64) = v26 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
                v24 = FirstIn;
              }
            }
          }
          *(_QWORD *)&ThisIn.T.Type = 0i64;
          if ( (v24 & 1) == 0 )
          {
            pStringNode = ThisIn.V.pStringNode;
            if ( ThisIn.V.pStringNode )
            {
              RefCount = ThisIn.V.pStringNode->RefCount;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                ThisIn.V.pStringNode->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
              }
            }
          }
          ThisIn.V.pStringNode = 0i64;
        }
        if ( v32.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v32);
      }
    }
    if ( ThisIn.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ThisIn);
  }
  else if ( newCursorType != v15->mMouseState[v4].CursorType )
  {
    v29 = v15->pUserEventHandler.pObject;
    if ( v29 )
    {
      *((_BYTE *)&ThisIn.NV.Scaleform::GFx::AS2::Value::TypeDesc + 4) = 0;
      *(_DWORD *)&ThisIn.T.Type = 23;
      ThisIn.NV.Int32Value = newCursorType;
      ((void (__fastcall *)(Scaleform::GFx::UserEventHandler *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::AS2::Value *))v29->vfptr[1].__vecDelDtor)(
        v29,
        v15,
        &ThisIn);
    }
  }
}

// File Line: 2535
// RVA: 0x704BC0
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyQueueSetFocus(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *ch,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  unsigned __int64 Size; // r11
  unsigned int v10; // r10d
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  Scaleform::GFx::AS2::Environment *v14; // rax

  pMovieImpl = this->pMovieImpl;
  pObject = 0i64;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v10 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v12 = 0i64;
    while ( Data[v12].Level )
    {
      v12 = ++v10;
      if ( v10 >= Size )
        goto LABEL_7;
    }
    pObject = Data[v10].pSprite.pObject;
  }
LABEL_7:
  v13 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::Selection::QueueSetFocus(v14, ch, controllerIdx, fmt);
}

// File Line: 2541
// RVA: 0x704C50
void __fastcall Scaleform::GFx::AS2::MovieRoot::NotifyTransferFocus(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *curFocused,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        int controllerIdx)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::InteractiveObject *pObject; // rbx
  unsigned __int64 Size; // r11
  unsigned int v10; // r10d
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  Scaleform::GFx::AS2::Environment *v14; // rax

  pMovieImpl = this->pMovieImpl;
  pObject = 0i64;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v10 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v12 = 0i64;
    while ( Data[v12].Level )
    {
      v12 = ++v10;
      if ( v10 >= Size )
        goto LABEL_7;
    }
    pObject = Data[v10].pSprite.pObject;
  }
LABEL_7:
  v13 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v14 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::Selection::BroadcastOnSetFocus(v14, curFocused, pNewFocus, controllerIdx);
}

// File Line: 2551
// RVA: 0x6C8B10
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::GFxAS2LoadQueueEntryMT_LoadMovie(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::MoviePreloadTask *v5; // rdi
  bool v6; // bp
  Scaleform::GFx::LoadQueueEntry *v7; // r14
  Scaleform::GFx::CharacterHandle *pNext; // rcx
  Scaleform::GFx::TaskManager *v9; // rax
  Scaleform::RefCountNTSImpl *v10; // rbx
  __int64 v11; // rax
  int vfptr; // r9d
  unsigned int v13; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r10
  unsigned __int64 Size; // rcx
  __int64 v16; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  unsigned int v18; // edx
  __int64 v19; // rax
  unsigned int v20; // edx
  __int64 v21; // rax
  __int64 v22; // rax
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v24; // rax
  Scaleform::GFx::TaskManager *v25; // rax
  Scaleform::GFx::MoviePreloadTask *v26; // rax
  Scaleform::Render::RenderBuffer *v27; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *TaskManager; // rax
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+88h] [rbp+20h] BYREF

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(this, pqueueEntry, pmovieRoot);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::`vftable;
  v5 = 0i64;
  this->pPreloadTask.pObject = 0i64;
  this->pNewChar.pObject = 0i64;
  this->pOldChar.pObject = 0i64;
  this->NewCharId.Id = 65537;
  this->CharSwitched = 0;
  this->BytesLoaded = 0;
  this->FirstFrameLoaded = 0;
  v6 = 0;
  v7 = this->pQueueEntry;
  pNext = (Scaleform::GFx::CharacterHandle *)v7[1].pNext;
  if ( pNext )
  {
    v9 = (Scaleform::GFx::TaskManager *)Scaleform::GFx::CharacterHandle::ResolveCharacter(pNext, this->pMovieImpl);
    v10 = (Scaleform::RefCountNTSImpl *)v9;
    if ( v9 )
      ++v9->RefCount;
    result.pObject = v9;
    if ( v9 )
    {
      v11 = ((__int64 (__fastcall *)(Scaleform::GFx::TaskManager *))v9->vfptr[66].__vecDelDtor)(v9);
      v6 = ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 88i64))(v11) & 0x10) != 0;
    }
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
    goto LABEL_32;
  }
  vfptr = (int)v7[1].vfptr;
  if ( vfptr == -1 )
    goto LABEL_32;
  v13 = 0;
  pMovieImpl = this->pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  if ( !Size )
    goto LABEL_19;
  v16 = 0i64;
  Data = pMovieImpl->MovieLevels.Data.Data;
  while ( Data[v16].Level != vfptr )
  {
    v16 = ++v13;
    if ( v13 >= Size )
      goto LABEL_19;
  }
  if ( Data[v13].pSprite.pObject )
  {
    v18 = 0;
    v19 = 0i64;
    while ( Data[v19].Level != vfptr )
    {
      v19 = ++v18;
      if ( v18 >= Size )
      {
LABEL_30:
        pObject = 0i64;
        goto LABEL_31;
      }
    }
  }
  else
  {
LABEL_19:
    v20 = 0;
    if ( !Size )
      goto LABEL_32;
    v21 = 0i64;
    Data = pMovieImpl->MovieLevels.Data.Data;
    while ( Data[v21].Level )
    {
      v21 = ++v20;
      if ( v20 >= Size )
        goto LABEL_32;
    }
    if ( !Data[v20].pSprite.pObject )
      goto LABEL_32;
    v18 = 0;
    v22 = 0i64;
    while ( Data[v22].Level )
    {
      v22 = ++v18;
      if ( v18 >= Size )
        goto LABEL_30;
    }
  }
  pObject = Data[v18].pSprite.pObject;
LABEL_31:
  v24 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pObject);
  v6 = ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 88i64))(v24) & 0x10) != 0;
LABEL_32:
  v25 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         80i64);
  result.pObject = v25;
  if ( v25 )
  {
    Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
      (Scaleform::GFx::MoviePreloadTask *)v25,
      this->pMovieImpl,
      &v7->URL,
      v6,
      pqueueEntry->QuietOpen);
    v5 = v26;
  }
  v27 = (Scaleform::Render::RenderBuffer *)this->pPreloadTask.pObject;
  if ( v27 )
    Scaleform::RefCountImpl::Release(v27);
  this->pPreloadTask.pObject = v5;
  TaskManager = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result);
  TaskManager->pObject->vfptr[1].__vecDelDtor(TaskManager->pObject, (unsigned int)this->pPreloadTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2589
// RVA: 0x701470
char __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::LoadFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this)
{
  char IsDone; // al
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // r13
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::AS2::MovieRoot *pObject; // r15
  Scaleform::GFx::InteractiveObject *v6; // rbx
  Scaleform::GFx::CharacterHandle *pNext; // rcx
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::Sprite *LevelMovie; // rax
  char *v10; // rcx
  Scaleform::GFx::AS2::Environment *v11; // rdi
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::InteractiveObject *v13; // rdi
  Scaleform::GFx::InteractiveObject *v14; // rcx
  unsigned int v15; // ecx
  Scaleform::GFx::MovieImpl *v16; // r8
  unsigned __int64 Size; // rdx
  __int64 v18; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::InteractiveObject *v20; // rcx
  __int64 v21; // rcx
  Scaleform::GFx::AS2::Environment *v22; // rdi
  Scaleform::GFx::AS2::Object *v23; // r14
  bool v24; // di
  SSExpressionBase *Heap; // r12
  Scaleform::GFx::InteractiveObject *pParent; // r12
  Scaleform::GFx::MovieDefImpl *v27; // rax
  Scaleform::GFx::ASSupport *v28; // rcx
  Scaleform::GFx::InteractiveObject *v29; // rdi
  Scaleform::GFx::InteractiveObject *v30; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v33; // zf
  char *v34; // rcx
  __int64 v35; // rax
  Scaleform::GFx::InteractiveObject *v36; // rcx
  int vfptr; // edx
  Scaleform::GFx::Sprite *v38; // rax
  Scaleform::GFx::InteractiveObject *v39; // rdi
  Scaleform::GFx::InteractiveObject *v40; // rcx
  Scaleform::GFx::InteractiveObject *v41; // rcx
  char *v42; // rcx
  __int64 v43; // rax
  __int64 v44; // rax
  int v45; // edx
  Scaleform::GFx::InteractiveObject *v46; // rcx
  Scaleform::GFx::LogState *v47; // rdi
  unsigned __int64 v48; // rdi
  Scaleform::GFx::LogState *v49; // r15
  Scaleform::GFx::InteractiveObject *v50; // rcx
  char *v51; // rcx
  __int64 v52; // rax
  __int64 v53; // rax
  Scaleform::GFx::InteractiveObject *v54; // rdi
  int v55; // edx
  Scaleform::GFx::ASSupport *v56; // rcx
  Scaleform::GFx::Sprite *v57; // r15
  Scaleform::GFx::InteractiveObject *v58; // rcx
  Scaleform::GFx::ASString *v59; // rax
  Scaleform::GFx::ASStringNode *v60; // rcx
  __int64 v61; // rax
  char *v62; // rcx
  Scaleform::GFx::InteractiveObject *v63; // rcx
  __int64 v64; // rax
  char *v65; // rcx
  __int64 v66; // rdi
  Scaleform::GFx::InteractiveObject *v67; // rcx
  __int64 v68; // rax
  char *v69; // rcx
  __int64 v70; // rax
  int v71; // edx
  Scaleform::GFx::InteractiveObject *v72; // rdi
  Scaleform::GFx::Sprite *v73; // rax
  unsigned int find_expr_last_no_side_effect_high; // edi
  unsigned int v75; // eax
  unsigned int v76; // edx
  char *v77; // rcx
  __int64 v78; // rax
  char v79; // di
  unsigned int v80; // eax
  Scaleform::GFx::InteractiveObject *v81; // rcx
  __int64 v82; // rax
  char *v83; // rcx
  __int64 v84; // rax
  Scaleform::GFx::InteractiveObject *v85; // r8
  int v86; // edx
  Scaleform::GFx::Sprite *v87; // rax
  char *v88; // rcx
  __int64 v89; // rax
  unsigned int v90; // ebx
  unsigned int v91; // eax
  unsigned int v92; // edx
  char *v93; // rcx
  __int64 v94; // rax
  Scaleform::GFx::Sprite *v95; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::Sprite *v96; // [rsp+38h] [rbp-61h]
  Scaleform::GFx::ASString v97; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::GFx::ASString v98; // [rsp+48h] [rbp-51h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v99; // [rsp+50h] [rbp-49h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> v100; // [rsp+58h] [rbp-41h] BYREF
  Scaleform::GFx::AS2::MovieRoot *v101; // [rsp+60h] [rbp-39h]
  __int64 v102[6]; // [rsp+68h] [rbp-31h] BYREF
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+98h] [rbp-1h] BYREF
  bool v104; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::ResourceId rid; // [rsp+108h] [rbp+6Fh] BYREF
  unsigned int Id; // [rsp+110h] [rbp+77h] BYREF
  unsigned int v107; // [rsp+118h] [rbp+7Fh] BYREF

  v102[3] = -2i64;
  IsDone = Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled && IsDone )
    return 1;
  pMovieImpl = this->pMovieImpl;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)pMovieImpl->pASMovieRoot.pObject;
  v101 = pObject;
  if ( !IsDone )
    return IsDone;
  v6 = 0i64;
  if ( !this->pOldChar.pObject )
  {
    pNext = (Scaleform::GFx::CharacterHandle *)pQueueEntry[1].pNext;
    if ( pNext )
    {
      v8 = Scaleform::GFx::CharacterHandle::ForceResolveCharacter(pNext, pMovieImpl);
      if ( !v8 )
      {
        LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
        if ( LevelMovie )
        {
          v10 = (char *)LevelMovie + 4 * (unsigned __int8)LevelMovie->AvmObjOffset;
          v11 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 240i64))(v10);
          v12 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[1].Type, v11);
          if ( v12 )
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::Environment *, _QWORD, const char *, _DWORD))v12->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
              v12,
              v11,
              0i64,
              "Error",
              0);
        }
        return 1;
      }
      v13 = 0i64;
      if ( SLOBYTE(v8->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
        v13 = (Scaleform::GFx::InteractiveObject *)v8;
      if ( v13 )
        ++v13->RefCount;
      v14 = this->pOldChar.pObject;
      if ( v14 )
        Scaleform::RefCountNTSImpl::Release(v14);
      this->pOldChar.pObject = v13;
      this->NewCharId.Id = v13->Id.Id;
    }
  }
  v15 = 0;
  v16 = pObject->pMovieImpl;
  Size = v16->MovieLevels.Data.Size;
  if ( !Size )
    return 1;
  v18 = 0i64;
  Data = v16->MovieLevels.Data.Data;
  while ( Data[v18].Level )
  {
    v18 = ++v15;
    if ( v15 >= Size )
      return 1;
  }
  v20 = Data[v15].pSprite.pObject;
  if ( !v20 )
    return 1;
  v21 = (__int64)v20 + 4 * (unsigned __int8)v20->AvmObjOffset;
  v22 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 240i64))(v21);
  v23 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[1].Type, v22);
  v24 = v22->StringContext.pContext->GFxExtensions.Value == 1;
  v104 = v24;
  Heap = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)this->pPreloadTask.pObject);
  if ( !Heap )
  {
    if ( !pQueueEntry[1].pNext )
    {
      vfptr = (int)pQueueEntry[1].vfptr;
      if ( vfptr != -1 )
      {
        v38 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, vfptr);
        v39 = v38;
        if ( v38 )
          ++v38->RefCount;
        v40 = this->pOldChar.pObject;
        if ( v40 )
          Scaleform::RefCountNTSImpl::Release(v40);
        this->pOldChar.pObject = v39;
      }
      goto LABEL_38;
    }
    pParent = this->pOldChar.pObject->pParent;
    if ( pParent )
    {
      rid.Id = 65537;
      v27 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pParent);
      Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(v27, &result, (Scaleform::GFx::ResourceId)&rid);
      v28 = pObject->pASSupport.pObject;
      Id = this->NewCharId.Id;
      v29 = (Scaleform::GFx::InteractiveObject *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *, Scaleform::GFx::InteractiveObject *, unsigned int *, int))v28->vfptr[4].__vecDelDtor)(
                                                   v28,
                                                   this->pMovieImpl,
                                                   &result,
                                                   pParent,
                                                   &Id,
                                                   3);
      v102[4] = (__int64)v29;
      v29->CreateFrame = this->pOldChar.pObject->CreateFrame;
      v29->Depth = this->pOldChar.pObject->Depth;
      v30 = this->pOldChar.pObject;
      if ( (v30->Scaleform::GFx::DisplayObject::Flags & 2) == 0 )
      {
        Name = Scaleform::GFx::DisplayObject::GetName(v30, &v98);
        v29->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[124].__vecDelDtor(
          v29,
          (unsigned int)Name);
        pNode = v98.pNode;
        v33 = v98.pNode->RefCount-- == 1;
        if ( v33 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      Scaleform::GFx::InteractiveObject::AddToPlayList(v29);
      v34 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
      v35 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v34 + 8i64))(v34);
      (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v35 + 216i64))(
        v35,
        this->pOldChar.pObject,
        v29);
      this->pOldChar.pObject->pParent = 0i64;
      ++v29->RefCount;
      v36 = this->pOldChar.pObject;
      if ( v36 )
        Scaleform::RefCountNTSImpl::Release(v36);
      this->pOldChar.pObject = v29;
      Scaleform::RefCountNTSImpl::Release(v29);
LABEL_38:
      v41 = this->pOldChar.pObject;
      if ( v41 && v23 )
      {
        v42 = (char *)v41 + 4 * (unsigned __int8)v41->AvmObjOffset;
        v43 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v42 + 8i64))(v42);
        v44 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v43 + 240i64))(v43);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
          v23,
          v44,
          this->pOldChar.pObject,
          "URLNotFound",
          0);
      }
      v45 = (int)pQueueEntry[1].vfptr;
      if ( v45 != -1 )
        Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, v45);
    }
    return 1;
  }
  v46 = this->pOldChar.pObject;
  if ( v46
    && ((v46->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0
     || (v46->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0
     || v46->Depth < -1) )
  {
    return 1;
  }
  if ( ((unsigned int (__fastcall *)(SSExpressionBase *))Heap->vfptr->invoke)(Heap) != -1
    && ((unsigned int (__fastcall *)(SSExpressionBase *))Heap->vfptr->invoke)(Heap) >= 9
    && (char)((*(_DWORD *)(*((_QWORD *)Heap[13].vfptr->get_side_effect + 8) + 208i64) & 8 | 0x10u) >> 3) > 2 )
  {
    this->pQueueEntry->Canceled = 1;
    v47 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &v100)->pObject;
    if ( v100.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v100.pObject);
    if ( v47 && !pQueueEntry->QuietOpen )
    {
      v48 = pQueueEntry->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v49 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &v99)->pObject;
      if ( v99.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v99.pObject);
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v49->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Failed loading SWF \"%s\": ActionScript version mismatch",
        (const char *)(v48 + 12));
    }
    v50 = this->pOldChar.pObject;
    if ( v50 && v23 )
    {
      v51 = (char *)v50 + 4 * (unsigned __int8)v50->AvmObjOffset;
      v52 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v51 + 8i64))(v51);
      v53 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v52 + 240i64))(v52);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
        v23,
        v53,
        this->pOldChar.pObject,
        "ActionScriptMismatch",
        0);
    }
    return 1;
  }
  if ( !this->CharSwitched )
  {
    v54 = 0i64;
    v55 = (int)pQueueEntry[1].vfptr;
    if ( v55 == -1 )
    {
      if ( pQueueEntry[1].pNext )
      {
        v54 = this->pOldChar.pObject->pParent;
        if ( !v54 )
          return 1;
      }
    }
    else
    {
      Scaleform::GFx::MovieImpl::ReleaseLevelMovie(this->pMovieImpl, v55);
      this->NewCharId.Id = 0x40000;
    }
    v102[0] = (__int64)Heap[13].vfptr->get_side_effect;
    v102[1] = (__int64)Heap;
    v102[2] = 0i64;
    v56 = pObject->Scaleform::GFx::ASMovieRootBase::pASSupport.pObject;
    v107 = this->NewCharId.Id;
    v57 = (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, __int64 *, Scaleform::GFx::InteractiveObject *, unsigned int *, int))v56->vfptr[4].__vecDelDtor)(
                                      v56,
                                      pObject->pMovieImpl,
                                      v102,
                                      v54,
                                      &v107,
                                      3);
    v102[5] = (__int64)v57;
    Scaleform::GFx::Sprite::SetLoadedSeparately(v57, 1);
    if ( !v104 )
      v57->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 4u;
    if ( pQueueEntry[1].pNext )
    {
      Scaleform::GFx::InteractiveObject::AddToPlayList(v57);
      v57->CreateFrame = this->pOldChar.pObject->CreateFrame;
      v57->Depth = this->pOldChar.pObject->Depth;
      v58 = this->pOldChar.pObject;
      if ( (v58->Scaleform::GFx::DisplayObject::Flags & 2) == 0 )
      {
        v59 = Scaleform::GFx::DisplayObject::GetName(v58, &v97);
        v57->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[124].__vecDelDtor(
          v57,
          (unsigned int)v59);
        v60 = v97.pNode;
        v33 = v97.pNode->RefCount-- == 1;
        if ( v33 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v60);
      }
      if ( v54 )
      {
        v62 = (char *)v54 + 4 * (unsigned __int8)v54->AvmObjOffset;
        v61 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v62 + 8i64))(v62);
      }
      else
      {
        v61 = 0i64;
      }
      (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *, Scaleform::GFx::Sprite *))(*(_QWORD *)v61 + 224i64))(
        v61,
        this->pOldChar.pObject,
        v57);
      this->pOldChar.pObject->pParent = 0i64;
    }
    else
    {
      Scaleform::GFx::AS2::AvmSprite::SetLevel(
        (Scaleform::GFx::AS2::AvmSprite *)((char *)v57 + 4 * (unsigned __int8)v57->AvmObjOffset),
        (int)pQueueEntry[1].vfptr);
      Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, (int)pQueueEntry[1].vfptr, v57);
      this->pMovieImpl->Flags &= ~0x100u;
    }
    v57->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
      v57,
      1u);
    ++v57->RefCount;
    v63 = this->pOldChar.pObject;
    if ( v63 )
      Scaleform::RefCountNTSImpl::Release(v63);
    this->pOldChar.pObject = v57;
    if ( v23 )
    {
      if ( v57 )
      {
        v65 = (char *)v57 + 4 * (unsigned __int8)v57->AvmObjOffset;
        v64 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v65 + 8i64))(v65);
      }
      else
      {
        v64 = 0i64;
      }
      v66 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v64 + 240i64))(v64);
      v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].ExecuteForEachChild_GC(
        v23,
        (Scaleform::GFx::AS2::RefCountCollector<323> *)v66,
        (Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)this->pOldChar.pObject);
      this->BytesLoaded = HIDWORD(Heap[13].vfptr[2].find_expr_last_no_side_effect);
      ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].Finalize_GC)(
        v23,
        v66,
        this->pOldChar.pObject);
    }
    this->CharSwitched = 1;
    Scaleform::RefCountNTSImpl::Release(v57);
    pObject = v101;
    v24 = v104;
  }
  if ( this->BytesLoaded != HIDWORD(Heap[13].vfptr[2].find_expr_last_no_side_effect) && v23 )
  {
    v67 = this->pOldChar.pObject;
    if ( v67 )
    {
      v69 = (char *)v67 + 4 * (unsigned __int8)v67->AvmObjOffset;
      v68 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v69 + 8i64))(v69);
    }
    else
    {
      v68 = 0i64;
    }
    v70 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v68 + 240i64))(v68);
    this->BytesLoaded = HIDWORD(Heap[13].vfptr[2].find_expr_last_no_side_effect);
    ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].Finalize_GC)(
      v23,
      v70,
      this->pOldChar.pObject);
  }
  if ( v24 && !this->FirstFrameLoaded && ((__int64)Heap[13].vfptr[2].__vecDelDtor & 0x100) != 0 )
  {
    v71 = (int)pQueueEntry[1].vfptr;
    if ( v71 == -1 )
    {
      v72 = 0i64;
      if ( (this->pOldChar.pObject->Flags & 0x400) != 0 )
        v72 = this->pOldChar.pObject;
      if ( v72 )
        ++v72->RefCount;
      v95 = (Scaleform::GFx::Sprite *)v72;
    }
    else
    {
      v73 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, v71);
      v72 = v73;
      if ( v73 )
        ++v73->RefCount;
      v95 = v73;
    }
    if ( v72 )
    {
      v72->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
        v72,
        0);
      find_expr_last_no_side_effect_high = HIDWORD(Heap[13].vfptr[2].find_expr_last_no_side_effect);
      v75 = ((__int64 (__fastcall *)(SSExpressionBase *))Heap->vfptr->null_receiver)(Heap);
      v76 = find_expr_last_no_side_effect_high;
      v72 = v95;
      Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v95, v76, v75);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v72->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[112].__vecDelDtor)(v72);
      ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))pObject->vfptr[7].__vecDelDtor)(pObject);
      if ( v23 )
      {
        v77 = (char *)v95 + 4 * (unsigned __int8)v95->AvmObjOffset;
        v78 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v77 + 240i64))(v77);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::Sprite *))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
          v23,
          v78,
          v95);
      }
    }
    this->FirstFrameLoaded = 1;
    if ( v72 )
      Scaleform::RefCountNTSImpl::Release(v72);
  }
  v79 = 0;
  v80 = (__int64)Heap[13].vfptr[2].__vecDelDtor & 0xF;
  if ( v80 > 1 )
  {
    if ( v80 == 2 )
    {
      v86 = (int)pQueueEntry[1].vfptr;
      if ( v86 == -1 )
      {
        if ( (this->pOldChar.pObject->Flags & 0x400) != 0 )
          v6 = this->pOldChar.pObject;
        if ( v6 )
          ++v6->RefCount;
        v96 = (Scaleform::GFx::Sprite *)v6;
        pObject->vfptr[39].__vecDelDtor(pObject, (unsigned int)this->pOldChar.pObject);
      }
      else
      {
        v87 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, v86);
        v6 = v87;
        if ( v87 )
          ++v87->RefCount;
        v96 = v87;
      }
      if ( v6 )
      {
        if ( !v104 )
          v6->Flags &= ~4u;
        if ( v23 )
        {
          v88 = (char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset;
          v89 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v88 + 240i64))(v88);
          ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, _QWORD))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].Finalize_GC)(
            v23,
            v89,
            v6,
            0i64);
        }
        if ( !this->FirstFrameLoaded )
        {
          v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
            v6,
            0);
          v90 = HIDWORD(Heap[13].vfptr[2].find_expr_last_no_side_effect);
          v91 = ((__int64 (__fastcall *)(SSExpressionBase *))Heap->vfptr->null_receiver)(Heap);
          v92 = v90;
          v6 = v96;
          Scaleform::GFx::Sprite::SetRootNodeLoadingStat(v96, v92, v91);
          ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[112].__vecDelDtor)(v6);
          ((void (__fastcall *)(Scaleform::GFx::AS2::MovieRoot *))pObject->vfptr[7].__vecDelDtor)(pObject);
          if ( v23 )
          {
            v93 = (char *)v96 + 4 * (unsigned __int8)v96->AvmObjOffset;
            v94 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v93 + 240i64))(v93);
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::Sprite *))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
              v23,
              v94,
              v96);
          }
        }
        this->FirstFrameLoaded = 1;
      }
      v79 = 1;
      if ( v6 )
        Scaleform::RefCountNTSImpl::Release(v6);
    }
    else
    {
      if ( v80 - 3 <= 1 && v23 )
      {
        v81 = this->pOldChar.pObject;
        if ( v81 )
        {
          v83 = (char *)v81 + 4 * (unsigned __int8)v81->AvmObjOffset;
          v82 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v83 + 8i64))(v83);
        }
        else
        {
          v82 = 0i64;
        }
        v84 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v82 + 240i64))(v82);
        v85 = this->pOldChar.pObject;
        if ( *(_DWORD *)(*((_QWORD *)Heap[13].vfptr->get_side_effect + 8) + 228i64) == 4 )
          ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
            v23,
            v84,
            v85,
            "Error",
            0);
        else
          ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int64, Scaleform::GFx::InteractiveObject *, const char *, _DWORD))v23->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[4].ExecuteForEachChild_GC)(
            v23,
            v84,
            v85,
            "Canceled",
            0);
      }
      return 1;
    }
  }
  return v79;
}

// File Line: 2940
// RVA: 0x700BE0
bool __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie::IsPreloadingFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadMovie *this)
{
  return Scaleform::GFx::MoviePreloadTask::IsDone(this->pPreloadTask.pObject);
}

// File Line: 2951
// RVA: 0x6C8F70
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(
        Scaleform::GFx::AS2::GFxAS2LoadXMLTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::String *level0Path,
        Scaleform::String *url,
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType *xmlholder)
{
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Stopped;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadXMLTask::`vftable;
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  pObject = (Scaleform::GFx::Resource *)xmlholder->Loader.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef(pObject);
  this->pXMLLoader.pObject = xmlholder->Loader.pObject;
  this->Done = 0;
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
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::String pdest; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::String v4; // [rsp+58h] [rbp+10h] BYREF

  loc.Use = File_LoadXML;
  Scaleform::String::String(&loc.FileName, &this->Url);
  Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
  Scaleform::String::String(&pdest);
  Scaleform::GFx::LoadStates::BuildURL(this->pLoadStates.pObject, &pdest, &loc);
  Scaleform::String::String(&v4, (const char *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  ((void (__fastcall *)(Scaleform::GFx::AS2::XMLFileLoader *, Scaleform::String *, Scaleform::GFx::FileOpener *))this->pXMLLoader.pObject->vfptr[1].__vecDelDtor)(
    this->pXMLLoader.pObject,
    &v4,
    this->pLoadStates.pObject->pBindStates.pObject->pFileOpener.pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v4.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Done = 1;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((pdest.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 2974
// RVA: 0x6C8D50
void __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::GFxAS2LoadQueueEntryMT_LoadXML(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::AS2::MovieRoot *pmovieRoot)
{
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v6; // rsi
  Scaleform::GFx::TaskManager *v7; // rbp
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::LoaderImpl *pObject; // rbx
  Scaleform::GFx::StateBag *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rax
  Scaleform::GFx::LoadStates *v12; // rbx
  Scaleform::Render::RenderBuffer *v13; // rcx
  unsigned int v14; // ecx
  Scaleform::GFx::MovieImpl *v15; // r9
  unsigned __int64 Size; // r8
  __int64 v17; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rdx
  const char *v19; // rax
  Scaleform::GFx::TaskManager *v20; // rbp
  Scaleform::GFx::Resource *v21; // rcx
  Scaleform::GFx::AS2::GFxAS2LoadXMLTask *v22; // rax
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *TaskManager; // rax
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::XMLHolderType v25[2]; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::String ppath; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> result; // [rsp+B8h] [rbp+20h] BYREF

  Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(this, pqueueEntry, pmovieRoot->pMovieImpl);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::`vftable;
  v6 = 0i64;
  this->pTask.pObject = 0i64;
  this->pLoadStates.pObject = 0i64;
  this->pASMovieRoot = pmovieRoot;
  v7 = (Scaleform::GFx::TaskManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144i64,
                                        0i64);
  result.pObject = v7;
  if ( v7 )
  {
    pMovieImpl = this->pMovieImpl;
    pObject = pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v10 = (Scaleform::GFx::StateBag *)pMovieImpl->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v7, pObject, v10, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->pLoadStates.pObject = v12;
  Scaleform::String::String(&ppath);
  v14 = 0;
  v15 = this->pASMovieRoot->pMovieImpl;
  Size = v15->MovieLevels.Data.Size;
  if ( !Size )
    goto LABEL_13;
  v17 = 0i64;
  Data = v15->MovieLevels.Data.Data;
  while ( Data[v17].Level )
  {
    v17 = ++v14;
    if ( v14 >= Size )
      goto LABEL_13;
  }
  if ( !Data[v14].pSprite.pObject
    || (v19 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v15->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v15->pMainMovieDef.pObject),
        Scaleform::String::operator=(&ppath, v19),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&ppath)) )
  {
LABEL_13:
    Scaleform::String::Clear(&ppath);
  }
  v20 = (Scaleform::GFx::TaskManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         64i64);
  result.pObject = v20;
  if ( v20 )
  {
    Scaleform::GFx::AS2::Value::Value(&v25[0].ASObj, (Scaleform::GFx::AS2::Value *)&pqueueEntry[3]);
    v21 = *(Scaleform::GFx::Resource **)&pqueueEntry[3].EntryTime;
    if ( v21 )
      Scaleform::Render::RenderBuffer::AddRef(v21);
    v25[0].Loader.pObject = *(Scaleform::GFx::AS2::XMLFileLoader **)&pqueueEntry[3].EntryTime;
    Scaleform::GFx::AS2::GFxAS2LoadXMLTask::GFxAS2LoadXMLTask(
      (Scaleform::GFx::AS2::GFxAS2LoadXMLTask *)v20,
      this->pLoadStates.pObject,
      &ppath,
      &pqueueEntry->URL,
      v25);
    v6 = v22;
  }
  v23 = (Scaleform::Render::RenderBuffer *)this->pTask.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  this->pTask.pObject = v6;
  TaskManager = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &result);
  TaskManager->pObject->vfptr[1].__vecDelDtor(TaskManager->pObject, (unsigned int)this->pTask.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 2990
// RVA: 0x701E60
bool __fastcall Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML::LoadFinished(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntryMT_LoadXML *this)
{
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rbp
  Scaleform::GFx::InteractiveObject *pObject; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // rdx
  unsigned int v6; // ecx
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  __int64 v8; // rax
  __int64 v9; // rcx
  Scaleform::GFx::AS2::Environment *v10; // rax
  __int64 *v11; // rdi
  __int64 v12; // rsi
  Scaleform::GFx::AS2::Environment *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rax

  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
    return this->pTask.pObject->Done == 1;
  if ( this->pTask.pObject->Done != 1 )
    return 0;
  pObject = 0i64;
  pMovieImpl = this->pASMovieRoot->pMovieImpl;
  Size = pMovieImpl->MovieLevels.Data.Size;
  v6 = 0;
  if ( Size )
  {
    Data = pMovieImpl->MovieLevels.Data.Data;
    v8 = 0i64;
    while ( Data[v8].Level )
    {
      v8 = ++v6;
      if ( v6 >= Size )
        goto LABEL_12;
    }
    pObject = Data[v6].pSprite.pObject;
  }
LABEL_12:
  v9 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
  v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 240i64))(v9);
  v11 = *(__int64 **)&pQueueEntry[3].EntryTime;
  v12 = *v11;
  v13 = v10;
  v14 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&pQueueEntry[3], v10);
  (*(void (__fastcall **)(__int64 *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *))(v12 + 16))(
    v11,
    v13,
    v14);
  return 1;
}

// File Line: 3079
// RVA: 0x6C6BD0
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::ASRefCountCollector(
        Scaleform::GFx::AS2::ASRefCountCollector *this)
{
  Scaleform::GFx::AS2::RefCountCollector<323>::RefCountCollector<323>(this);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::ASRefCountCollector::`vftable;
  this->FrameCnt = 0;
  *(_QWORD *)&this->PeakRootCount = 0i64;
  *(_QWORD *)&this->LastCollectedRoots = 0i64;
  *(_QWORD *)&this->TotalFramesCount = 0i64;
  *(_QWORD *)&this->PresetMaxRootCount = 1000i64;
  this->MaxRootCount = 1000;
}

// File Line: 3092
// RVA: 0x71AA20
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::SetParams(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount)
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
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::AdvanceFrame(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        unsigned int *movieFrameCnt,
        unsigned int *movieLastCollectFrame,
        Scaleform::GFx::Resource *ampStats)
{
  unsigned int LastCollectionFrameNum; // eax
  unsigned int FrameCnt; // ecx
  unsigned __int64 Size; // rdi
  unsigned int v11; // edx
  unsigned int PeakRootCount; // ecx
  unsigned int PresetMaxRootCount; // ecx
  unsigned int MaxFramesBetweenCollections; // eax
  unsigned int v15; // eax
  unsigned int RootsFreedTotal; // edx
  unsigned int MaxRootCount; // ecx
  unsigned int v18; // eax
  unsigned int v19; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h] BYREF

  LastCollectionFrameNum = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == LastCollectionFrameNum )
  {
    FrameCnt = this->FrameCnt;
    if ( *movieFrameCnt >= FrameCnt )
    {
      Size = this->Roots.Size;
      ++this->TotalFramesCount;
      v11 = FrameCnt + 1;
      this->FrameCnt = FrameCnt + 1;
      PeakRootCount = Size;
      if ( (unsigned int)Size < this->PeakRootCount )
        PeakRootCount = this->PeakRootCount;
      this->PeakRootCount = PeakRootCount;
      PresetMaxRootCount = this->PresetMaxRootCount;
      if ( PresetMaxRootCount && (unsigned int)Size > this->MaxRootCount
        || (MaxFramesBetweenCollections = this->MaxFramesBetweenCollections) != 0
        && v11 >= MaxFramesBetweenCollections
        && (unsigned int)Size > PresetMaxRootCount )
      {
        if ( ampStats )
          Scaleform::Render::RenderBuffer::AddRef(ampStats);
        pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)ampStats;
        *(_QWORD *)&pstat.RootsNumber = 0i64;
        Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, &pstat);
        v15 = this->PresetMaxRootCount;
        RootsFreedTotal = pstat.RootsFreedTotal;
        if ( pstat.RootsFreedTotal > v15 )
        {
          this->PeakRootCount = Size;
          this->MaxRootCount = v15;
        }
        if ( (unsigned int)Size > RootsFreedTotal )
        {
          MaxRootCount = Size - RootsFreedTotal;
          if ( (unsigned int)Size - RootsFreedTotal < this->MaxRootCount )
            MaxRootCount = this->MaxRootCount;
          this->MaxRootCount = MaxRootCount;
        }
        v18 = (int)((double)(int)this->MaxRootCount * 0.7);
        v19 = this->PeakRootCount;
        if ( v19 < v18 )
          this->MaxRootCount = v18;
        this->LastCollectionFrameNum = this->TotalFramesCount;
        this->FrameCnt = 0;
        this->LastPeakRootCount = v19;
        this->LastCollectedRoots = RootsFreedTotal;
        if ( pstat.AdvanceStats.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
      }
      this->LastRootCount = Size;
      *movieFrameCnt = this->FrameCnt;
      *movieLastCollectFrame = this->LastCollectionFrameNum;
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = LastCollectionFrameNum;
    *movieFrameCnt = 1;
  }
}

// File Line: 3186
// RVA: 0x6EC090
void __fastcall Scaleform::GFx::AS2::ASRefCountCollector::ForceCollect(
        Scaleform::GFx::AS2::ASRefCountCollector *this,
        Scaleform::GFx::Resource *ampStats)
{
  unsigned __int64 Size; // rsi
  unsigned int PeakRootCount; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h] BYREF

  Size = this->Roots.Size;
  if ( ampStats )
    Scaleform::Render::RenderBuffer::AddRef(ampStats);
  pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)ampStats;
  *(_QWORD *)&pstat.RootsNumber = 0i64;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, &pstat);
  this->FrameCnt = 0;
  PeakRootCount = Size;
  if ( (unsigned int)Size < this->PeakRootCount )
    PeakRootCount = this->PeakRootCount;
  this->PeakRootCount = PeakRootCount;
  this->LastRootCount = Size;
  if ( pstat.AdvanceStats.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
}

// File Line: 3222
// RVA: 0x70B700
void __fastcall Scaleform::GFx::AS2::AvmSwfEvent::Read(
        Scaleform::GFx::AS2::AvmSwfEvent *this,
        Scaleform::GFx::StreamContext *psc,
        unsigned int flags)
{
  unsigned __int64 CurByteIndex; // rcx
  const char *pData; // rdx
  unsigned int v7; // esi
  unsigned __int64 v8; // rax
  unsigned int v9; // ecx
  Scaleform::GFx::AS2::ActionBufferData *New; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::AS2::ActionBufferData *v12; // rbp
  unsigned int BufferLen; // ecx
  unsigned int v14; // esi
  unsigned int CurBitIndex; // ecx
  unsigned __int64 v16; // rax
  __int64 v17; // rdx

  this->Event.Id = flags;
  *(_DWORD *)&this->Event.RollOverCnt = 65280;
  *(_QWORD *)&this->Event.WcharCode = 0i64;
  this->Event.AsciiCode = 0;
  if ( psc->CurBitIndex )
    ++psc->CurByteIndex;
  CurByteIndex = psc->CurByteIndex;
  psc->CurBitIndex = 0;
  pData = psc->pData;
  v7 = (unsigned __int8)pData[CurByteIndex] | (((unsigned __int8)pData[CurByteIndex + 1] | (*(unsigned __int16 *)&pData[CurByteIndex + 2] << 8)) << 8);
  v8 = CurByteIndex + 4;
  psc->CurByteIndex = CurByteIndex + 4;
  if ( (this->Event.Id & 0x20000) != 0 )
  {
    psc->CurBitIndex = 0;
    v9 = (unsigned __int8)pData[v8];
    psc->CurByteIndex = v8 + 1;
    --v7;
    this->Event.KeyCode = v9;
  }
  New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  pObject = (Scaleform::Render::RenderBuffer *)this->pActionOpData.pObject;
  v12 = New;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pActionOpData.pObject = v12;
  Scaleform::GFx::AS2::ActionBufferData::Read(v12, psc, v7);
  BufferLen = this->pActionOpData.pObject->BufferLen;
  if ( BufferLen != v7 )
  {
    if ( v7 <= BufferLen )
    {
      psc->CurByteIndex -= BufferLen - v7;
    }
    else
    {
      v14 = v7 - BufferLen;
      if ( v14 )
      {
        CurBitIndex = psc->CurBitIndex;
        v16 = psc->CurByteIndex;
        v17 = v14;
        do
        {
          if ( CurBitIndex )
            ++v16;
          ++v16;
          CurBitIndex = 0;
          --v17;
        }
        while ( v17 );
        psc->CurBitIndex = 0;
        psc->CurByteIndex = v16;
      }
    }
  }
}

// File Line: 3273
// RVA: 0x6DB2F0
void __fastcall Scaleform::GFx::AS2::AvmSwfEvent::AttachTo(
        Scaleform::GFx::AS2::AvmSwfEvent *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::AS2::ActionBufferData *pObject; // rax
  Scaleform::GFx::AS2::AvmCharacter *v4; // rsi
  char *v5; // rcx
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::MemoryHeap *pHeap; // r14
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rbx
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType; // ebp
  Scaleform::GFx::AS2::AsFunctionObject *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value method; // [rsp+60h] [rbp-58h] BYREF

  pObject = this->pActionOpData.pObject;
  if ( pObject && pObject->BufferLen && *pObject->pBuffer )
  {
    if ( ch )
    {
      v5 = (char *)ch + 4 * (unsigned __int8)ch->AvmObjOffset;
      v4 = (Scaleform::GFx::AS2::AvmCharacter *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 8i64))(v5);
    }
    else
    {
      v4 = 0i64;
    }
    v6 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))v4->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(v4);
    pHeap = v6->StringContext.pContext->pHeap;
    v8 = (Scaleform::GFx::AS2::ActionBuffer *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pHeap->vfptr->Alloc)(
                                                pHeap,
                                                64i64);
    if ( v8 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
        v8,
        &v6->StringContext,
        (Scaleform::GFx::Resource *)this->pActionOpData.pObject);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( this->Event.Id == 1
      || this->Event.Id == 4
      || this->Event.Id == 512
      || (execType = Exec_Event, this->Event.Id == 0x40000) )
    {
      execType = Exec_SpecialEvent;
    }
    v12 = (Scaleform::GFx::AS2::AsFunctionObject *)pHeap->vfptr->Alloc(pHeap, 200ui64, 0i64);
    if ( v12 )
    {
      Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
        v12,
        v6,
        v10,
        0,
        this->pActionOpData.pObject->BufferLen,
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
      RefCount = v14->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v14->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14);
      }
    }
    Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(v4, &this->Event, &method);
    if ( method.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&method);
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release(v10);
  }
}

// File Line: 3341
// RVA: 0x705EF0
char __fastcall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::OnExceedLimit(
        Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned __int64 overLimit)
{
  __int64 v6; // rax
  unsigned __int64 Limit; // r15
  __int64 v8; // rbp
  float v9; // xmm0_4
  float v10; // xmm0_4
  unsigned __int64 v11; // rax
  float v12; // xmm1_4
  unsigned __int64 v13; // rsi
  unsigned __int64 UserLevelLimit; // rax
  unsigned __int64 CurrentLimit; // rdx
  unsigned __int64 v16; // rax
  unsigned __int64 LastCollectionFootprint; // rcx

  v6 = heap->vfptr->GetFootprint(heap);
  Limit = heap->Info.Desc.Limit;
  v8 = v6;
  v9 = (float)(int)v6;
  if ( v6 < 0 )
    v9 = v9 + 1.8446744e19;
  v10 = v9 * this->HeapLimitMultiplier;
  v11 = 0i64;
  v12 = v10;
  if ( v10 >= 9.223372e18 )
  {
    v12 = v10 - 9.223372e18;
    if ( (float)(v10 - 9.223372e18) < 9.223372e18 )
      v11 = 0x8000000000000000ui64;
  }
  v13 = overLimit + Limit + v11 + (unsigned int)(int)v12;
  if ( (signed __int64)(v8 - this->LastCollectionFootprint) < (unsigned int)(int)v10 )
  {
    UserLevelLimit = this->UserLevelLimit;
    if ( !UserLevelLimit || v13 <= UserLevelLimit )
    {
      CurrentLimit = v13;
LABEL_16:
      heap->vfptr->SetLimit(heap, CurrentLimit);
      this->CurrentLimit = heap->Info.Desc.Limit;
      return 1;
    }
  }
  if ( !this->AllocCount )
  {
    Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(this, heap);
    v16 = this->UserLevelLimit;
    if ( v16 )
    {
      if ( v13 > v16 )
      {
        LastCollectionFootprint = this->LastCollectionFootprint;
        if ( overLimit <= v8 - LastCollectionFootprint )
        {
          CurrentLimit = this->CurrentLimit;
        }
        else
        {
          CurrentLimit = overLimit + Limit + LastCollectionFootprint - v8;
          this->CurrentLimit = CurrentLimit;
        }
        goto LABEL_16;
      }
    }
  }
  return 1;
}

// File Line: 3408
// RVA: 0x706360
void __fastcall Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::OnFreeSegment(
        Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap,
        unsigned __int64 freeingSize)
{
  unsigned __int64 CurrentLimit; // rdx

  CurrentLimit = this->CurrentLimit;
  if ( CurrentLimit > this->UserLevelLimit && CurrentLimit > freeingSize )
  {
    this->CurrentLimit = CurrentLimit - freeingSize;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))heap->vfptr->SetLimit)(heap);
  }
}

// File Line: 3423
// RVA: 0x6DE250
void __fastcall Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit::Collect(
        Scaleform::GFx::AS2::MemoryContextImpl::HeapLimit *this,
        Scaleform::MemoryHeap *heap)
{
  Scaleform::Render::Text::Allocator *pObject; // rcx
  Scaleform::GFx::AS2::ASRefCountCollector *v5; // rdi
  unsigned __int64 Size; // rbx
  unsigned int PeakRootCount; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats pstat; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->MemContext->TextAllocator.pObject;
  if ( pObject )
  {
    Scaleform::Render::Text::Allocator::FlushTextFormatCache(pObject, 1);
    Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(this->MemContext->TextAllocator.pObject, 1);
  }
  v5 = this->MemContext->ASGC.pObject;
  Size = v5->Roots.Size;
  pstat.AdvanceStats.pObject = 0i64;
  *(_QWORD *)&pstat.RootsNumber = 0i64;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(v5, &pstat);
  v5->FrameCnt = 0;
  PeakRootCount = Size;
  if ( (unsigned int)Size < v5->PeakRootCount )
    PeakRootCount = v5->PeakRootCount;
  v5->PeakRootCount = PeakRootCount;
  v5->LastRootCount = Size;
  if ( pstat.AdvanceStats.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
  if ( (v5->Flags & 1) == 0 && !v5->Roots.Size )
    Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease(&v5->Roots);
  v5->PeakRootCount = 0;
  v5->MaxRootCount = v5->PresetMaxRootCount;
  this->LastCollectionFootprint = heap->vfptr->GetFootprint(heap);
}

// File Line: 3529
// RVA: 0x6E3150
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::EventId_GetFunctionName(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::StringManager *psm,
        Scaleform::GFx::EventId *evt)
{
  unsigned int Id; // r8d
  __int64 v6; // r8
  int v7; // ecx
  Scaleform::GFx::ASStringNode *pNode; // rcx

  Id = evt->Id;
  if ( Id > 0x800000 )
    v6 = Id - 16777191;
  else
    v6 = (unsigned __int8)Scaleform::Alg::BitCount32(Id);
  if ( (unsigned int)(v6 - 1) > 0x21 )
    v7 = 46;
  else
    v7 = *(_DWORD *)&aZ_26[4 * v6];
  pNode = psm->Builtins[v7].pNode;
  result->pNode = pNode;
  ++pNode->RefCount;
  return result;
}

