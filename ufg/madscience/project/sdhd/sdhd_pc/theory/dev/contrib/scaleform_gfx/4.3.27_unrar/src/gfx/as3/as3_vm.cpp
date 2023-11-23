// File Line: 444
// RVA: 0x784BD0
void __fastcall Scaleform::GFx::AS3::VMFile::VMFile(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340,Scaleform::ArrayDefaultPolicy> *p_IntStrings; // rsi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v7; // rdx

  GC = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMFile::`vftable;
  this->VMRef = vm;
  this->AppDomain.pObject = appDomain;
  if ( appDomain )
    appDomain->RefCount = (appDomain->RefCount + 1) & 0x8FBFFFFF;
  this->IntNamespaces.Entries.mHash.pTable = 0i64;
  this->IntNamespaceSets.Data.Data = 0i64;
  this->IntNamespaceSets.Data.Size = 0i64;
  this->IntNamespaceSets.Data.Policy.Capacity = 0i64;
  p_IntStrings = &this->IntStrings;
  this->IntStrings.Data.Data = 0i64;
  this->IntStrings.Data.Size = 0i64;
  this->IntStrings.Data.Policy.Capacity = 0i64;
  this->ActivationTraitsCache.mHash.pTable = 0i64;
  this->LoadedClasses.Data.Data = 0i64;
  this->LoadedClasses.Data.Size = 0i64;
  this->LoadedClasses.Data.Policy.Capacity = 0i64;
  this->ASStringNodeSet.pTable = 0i64;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  if ( vm->StringManagerRef->pStringManager != (Scaleform::GFx::ASStringManager *)-64i64 )
    ++p_EmptyStringNode->RefCount;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntStrings.Data,
    &this->IntStrings,
    this->IntStrings.Data.Size + 1);
  v7 = &p_IntStrings->Data.Data[this->IntStrings.Data.Size - 1];
  if ( v7 )
  {
    v7->pObject = p_EmptyStringNode;
    if ( p_EmptyStringNode )
      ++p_EmptyStringNode->RefCount;
  }
  if ( p_EmptyStringNode && ((unsigned __int8)p_EmptyStringNode & 1) == 0 && p_EmptyStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}

// File Line: 450
// RVA: 0x78F9D0
void __fastcall Scaleform::GFx::AS3::VMFile::~VMFile(Scaleform::GFx::AS3::VMFile *this)
{
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMFile::`vftable;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::~HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>(&this->ASStringNodeSet);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LoadedClasses);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>(&this->ActivationTraitsCache.mHash);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>(&this->IntStrings.Data);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->IntNamespaceSets);
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ(&this->IntNamespaces.Entries.mHash);
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ(&this->IntNamespaces.Entries.mHash);
  pObject = this->AppDomain.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->AppDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 454
// RVA: 0x7D6B50
void __fastcall Scaleform::GFx::AS3::VMFile::ForEachChild_GC(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, __int64, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *))
{
  unsigned __int64 Size; // rsi
  unsigned __int64 v7; // rdi
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *p_ActivationTraitsCache; // r8
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v13; // rcx
  unsigned __int64 v14; // rax
  signed __int64 v15; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v16; // rcx
  unsigned __int64 *p_SizeMask; // rdx
  unsigned __int64 v18; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v19; // rax
  unsigned __int64 v20; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v21; // rdx
  Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *v22; // [rsp+20h] [rbp-28h]
  signed __int64 v23; // [rsp+28h] [rbp-20h]

  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::ForEachChild_GC(
    &this->IntNamespaces,
    prcc,
    op);
  Size = this->IntNamespaceSets.Data.Size;
  v7 = 0i64;
  for ( i = 0i64; i < Size; ++i )
  {
    v9 = &this->IntNamespaceSets.Data.Data[i];
    if ( v9->pObject )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *))op)(
        prcc,
        v9);
  }
  pTable = this->ActivationTraitsCache.mHash.pTable;
  p_ActivationTraitsCache = &this->ActivationTraitsCache;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v13 = pTable + 1;
    v14 = 0i64;
    do
    {
      if ( v13->EntryCount != -2i64 )
        break;
      ++v14;
      v13 += 2;
    }
    while ( v14 <= SizeMask );
    v22 = &this->ActivationTraitsCache;
    v23 = v14;
  }
  else
  {
    v22 = 0i64;
    v23 = 0i64;
  }
  v15 = v23;
  while ( v22 )
  {
    v16 = v22->mHash.pTable;
    if ( !v22->mHash.pTable || v15 > (signed __int64)v16->SizeMask )
      break;
    p_SizeMask = &v16[2 * v15 + 2].SizeMask;
    if ( *p_SizeMask )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, unsigned __int64 *, Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *))op)(
        prcc,
        p_SizeMask,
        p_ActivationTraitsCache);
    v18 = v22->mHash.pTable->SizeMask;
    if ( v15 <= (__int64)v18 && ++v15 <= v18 )
    {
      v19 = &v22->mHash.pTable[2 * v15 + 1];
      do
      {
        if ( v19->EntryCount != -2i64 )
          break;
        ++v15;
        v19 += 2;
      }
      while ( v15 <= v18 );
    }
  }
  v20 = this->LoadedClasses.Data.Size;
  if ( v20 )
  {
    do
    {
      v21 = &this->LoadedClasses.Data.Data[v7];
      if ( v21->pObject )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *, Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *))op)(
          prcc,
          v21,
          p_ActivationTraitsCache);
      ++v7;
    }
    while ( v7 < v20 );
  }
  if ( this->AppDomain.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *, Scaleform::HashLH<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>,340,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *))op)(
      prcc,
      &this->AppDomain,
      p_ActivationTraitsCache);
}

// File Line: 481
// RVA: 0x7EA6B0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rax
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *p_IntNamespaces; // rdi
  __int64 v6; // rcx
  unsigned __int64 v7; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rcx
  unsigned int RefCount; // eax
  __int64 v11[2]; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeRef key; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // [rsp+68h] [rbp+10h] BYREF
  char v14; // [rsp+70h] [rbp+18h] BYREF

  if ( (mn->Kind & 3u) > 1
    || (v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
               &this->IntNamespaces,
               mn->Ind,
               mn->NextIndex)) == 0i64 )
  {
    v13 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, Scaleform::GFx::AS3::Abc::Multiname *))this->vfptr[1].Finalize_GC)(
                                                          this,
                                                          &v14,
                                                          mn);
    v11[0] = mn->Ind;
    v11[1] = mn->NextIndex;
    key.pFirst = (Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key *)v11;
    key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&v13;
    p_IntNamespaces = &this->IntNamespaces;
    v6 = 16i64;
    v7 = 5381i64;
    do
    {
      --v6;
      v7 = *((unsigned __int8 *)v11 + v6) + 65599 * v7;
    }
    while ( v6 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeRef>(
      &p_IntNamespaces->Entries.mHash,
      p_IntNamespaces,
      &key,
      v7);
    v8 = v13;
    if ( v13 )
    {
      if ( ((unsigned __int8)v13 & 1) != 0 )
      {
        v13 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
      }
      else
      {
        RefCount = v13->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v13->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
    }
    if ( (mn->Kind & 3u) > 1 )
      v4 = 0i64;
    else
      v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
             p_IntNamespaces,
             mn->Ind,
             mn->NextIndex);
  }
  return v4->pObject;
}

// File Line: 495
// RVA: 0x7EA7D0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
        Scaleform::GFx::AS3::VMFile *this,
        __int64 nsIndex)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rax
  __int64 v5; // rcx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int RefCount; // eax
  __int64 v10[2]; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeRef key; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // [rsp+60h] [rbp+8h] BYREF
  char v13; // [rsp+70h] [rbp+18h] BYREF

  v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
         &this->IntNamespaces,
         nsIndex,
         -1);
  if ( !v4 )
  {
    v12 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, __int64))this->vfptr[1].~RefCountBaseGC<328>)(
                                                          this,
                                                          &v13,
                                                          nsIndex);
    v10[0] = nsIndex;
    v10[1] = -1i64;
    key.pFirst = (Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key *)v10;
    key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&v12;
    v5 = 16i64;
    v6 = 5381i64;
    do
    {
      --v5;
      v6 = *((unsigned __int8 *)v10 + v5) + 65599 * v6;
    }
    while ( v5 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeRef>(
      &this->IntNamespaces.Entries.mHash,
      &this->IntNamespaces,
      &key,
      v6);
    v7 = v12;
    if ( v12 )
    {
      if ( ((unsigned __int8)v12 & 1) != 0 )
      {
        v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v12 - 1);
      }
      else
      {
        RefCount = v12->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v12->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
           &this->IntNamespaces,
           nsIndex,
           -1);
  }
  return v4->pObject;
}

// File Line: 509
// RVA: 0x7EA8D0
Scaleform::GFx::AS3::NamespaceSet *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
        Scaleform::GFx::AS3::VMFile *this,
        unsigned __int64 nsSetIndex)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *Data; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *v5; // r14
  Scaleform::GFx::AS3::NamespaceSet **v6; // rax
  Scaleform::GFx::AS3::NamespaceSet *pObject; // rcx
  Scaleform::GFx::AS3::NamespaceSet *v8; // rbx
  unsigned int RefCount; // edx
  char v11; // [rsp+30h] [rbp+8h] BYREF

  if ( nsSetIndex >= this->IntNamespaceSets.Data.Size )
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->IntNamespaceSets.Data,
      nsSetIndex + 1);
  Data = this->IntNamespaceSets.Data.Data;
  v5 = &Data[nsSetIndex];
  if ( v5->pObject )
    return Data[nsSetIndex].pObject;
  v6 = (Scaleform::GFx::AS3::NamespaceSet **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, unsigned __int64))this->vfptr[2].ForEachChild_GC)(
                                               this,
                                               &v11,
                                               nsSetIndex);
  pObject = v5->pObject;
  v8 = *v6;
  if ( *v6 != v5->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v5->pObject = (Scaleform::GFx::AS3::NamespaceSet *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    v5->pObject = v8;
  }
  return this->IntNamespaceSets.Data.Data[nsSetIndex].pObject;
}

// File Line: 521
// RVA: 0x7EA990
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedString(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::ASString *result,
        unsigned __int64 strIndex)
{
  unsigned __int64 v6; // r15
  Scaleform::GFx::ASStringNode **v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v9; // rsi
  Scaleform::GFx::ASStringNode *pObject; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v15; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v16; // [rsp+58h] [rbp+10h]

  v16 = result;
  if ( strIndex >= this->IntStrings.Data.Size )
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->IntStrings.Data,
      strIndex + 1);
  v6 = strIndex;
  if ( !this->IntStrings.Data.Data[strIndex].pObject )
  {
    v7 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, Scaleform::GFx::ASStringNode **, unsigned __int64))this->vfptr[2].Finalize_GC)(
                                            this,
                                            &v15,
                                            strIndex);
    v8 = *v7;
    v9 = &this->IntStrings.Data.Data[v6];
    if ( *v7 != v9->pObject )
    {
      if ( v8 )
        ++v8->RefCount;
      pObject = v9->pObject;
      if ( v9->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v9->pObject = (Scaleform::GFx::ASStringNode *)((char *)pObject - 1);
        }
        else
        {
          v11 = pObject->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
        }
      }
      v9->pObject = v8;
    }
    v12 = v15;
    v11 = v15->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  v13 = this->IntStrings.Data.Data[v6].pObject;
  result->pNode = v13;
  ++v13->RefCount;
  return result;
}

// File Line: 532
// RVA: 0x7E5B80
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::Abc::MbiInd mbi_ind)
{
  __int64 Index; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v5; // rax
  unsigned __int64 *p_SizeMask; // rax
  __int64 v8; // rdx
  unsigned __int64 v9; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  unsigned int RefCount; // eax
  Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeRef v12; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Abc::MbiInd key; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // [rsp+70h] [rbp+18h] BYREF

  key.Ind = mbi_ind.Ind;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            &this->ActivationTraitsCache.mHash,
            &key);
  if ( Index >= 0 )
  {
    v5 = &this->ActivationTraitsCache.mHash.pTable[2 * Index + 2];
    if ( v5 )
    {
      p_SizeMask = &v5->SizeMask;
      if ( p_SizeMask )
        return (Scaleform::GFx::AS3::InstanceTraits::Traits *)*p_SizeMask;
    }
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::VMFile *, Scaleform::GFx::AS3::RefCountBaseGC<328> **, _QWORD))this->vfptr[2].~RefCountBaseGC<328>)(
    this,
    &v15,
    (unsigned int)mbi_ind.Ind);
  v13 = v15;
  v12.pFirst = &key;
  v12.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *)&v13;
  v8 = 4i64;
  v9 = 5381i64;
  do
  {
    --v8;
    v9 = *((unsigned __int8 *)&key.Ind + v8) + 65599 * v9;
  }
  while ( v8 );
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::add<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeRef>(
    &this->ActivationTraitsCache.mHash,
    &this->ActivationTraitsCache,
    &v12,
    v9);
  v10 = v13;
  if ( v13 )
  {
    if ( ((unsigned __int8)v13 & 1) != 0 )
    {
      v13 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
    }
    else
    {
      RefCount = v13->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v13->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
  }
  return (Scaleform::GFx::AS3::InstanceTraits::Traits *)v15;
}

// File Line: 570
// RVA: 0x784A00
void __fastcall Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned __int64 Size; // rsi
  unsigned __int64 v8; // rdi

  Scaleform::GFx::AS3::VMFile::VMFile(this, vm, appDomain);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAbcFile::`vftable;
  if ( file->pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)file->pObject);
  this->File = (Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File>)file->pObject;
  this->AbsObjects.pTable = 0i64;
  this->GlobalObjects.pTable = 0i64;
  this->Children.Data.Data = 0i64;
  this->Children.Data.Size = 0i64;
  this->Children.Data.Policy.Capacity = 0i64;
  this->FunctionTraitsCache.mHash.pTable = 0i64;
  this->MethodInfoArray.Data.Data = 0i64;
  this->MethodInfoArray.Data.Size = 0i64;
  this->MethodInfoArray.Data.Policy.Capacity = 0i64;
  this->AliasClass.pTable = 0i64;
  this->RefCount |= 0x2000000u;
  Size = file->pObject->MethodBodies.Info.Data.Size;
  v8 = this->MethodInfoArray.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->MethodInfoArray.Data,
    &this->MethodInfoArray,
    Size);
  if ( Size > v8 )
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::MethodInfo>::ConstructArray(
      &this->MethodInfoArray.Data.Data[v8],
      Size - v8);
  Scaleform::GFx::AS3::VM::AddVMAbcFileWeak(vm, this);
}

// File Line: 583
// RVA: 0x78F610
void __fastcall Scaleform::GFx::AS3::VMAbcFile::~VMAbcFile(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VM *VMRef; // r13
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,340> *p_AliasClass; // rbp
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *pTable; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v6; // rcx
  signed __int64 v7; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v8; // rcx
  Scaleform::GFx::ASString *v9; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::TableType *v10; // r8
  Scaleform::GFx::ASStringNode *pNode; // r11
  __int64 SizeMask; // r10
  __int64 v13; // r9
  __int64 v14; // rdi
  __int64 *v15; // rdx
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned __int64 v17; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v18; // rax
  __int64 v19; // rdi
  __int64 v20; // rsi
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rcx
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *i; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Render::RenderBuffer *v28; // rcx
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,340> *v29; // [rsp+30h] [rbp-48h]
  unsigned __int64 v30; // [rsp+38h] [rbp-40h]

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAbcFile::`vftable;
  VMRef = this->VMRef;
  p_AliasClass = &this->AliasClass;
  pTable = this->AliasClass.pTable;
  if ( pTable )
  {
    v5 = 0i64;
    v6 = pTable + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v5;
      ++v6;
    }
    while ( v5 <= pTable->SizeMask );
    v29 = p_AliasClass;
    v30 = v5;
  }
  else
  {
    v29 = 0i64;
    v30 = 0i64;
  }
  v7 = v30;
  while ( v29 )
  {
    v8 = v29->pTable;
    if ( !v29->pTable || v7 > (signed __int64)v8->SizeMask )
      break;
    v9 = (Scaleform::GFx::ASString *)&v8[v7];
    v10 = VMRef->AliasClass.mHash.pTable;
    if ( v10 )
    {
      pNode = v9[3].pNode;
      SizeMask = v10->SizeMask;
      v13 = (unsigned int)SizeMask & pNode->HashFlags;
      v14 = v13;
      v15 = (__int64 *)(&v10[v13 + 1].EntryCount + v13);
      if ( *v15 != -2 && ((unsigned int)SizeMask & *(_DWORD *)(v15[1] + 28)) == v13 )
      {
        while ( 1 )
        {
          v16 = (Scaleform::GFx::ASStringNode *)v15[1];
          if ( ((unsigned int)SizeMask & v16->HashFlags) == v13 && v16 == pNode )
            break;
          v14 = *v15;
          if ( *v15 == -1 )
            goto LABEL_22;
          v15 = (__int64 *)(&v10[v14 + 1].EntryCount + v14);
        }
        if ( v14 >= 0 && VMRef != (Scaleform::GFx::AS3::VM *)-704i64 && v14 <= SizeMask )
        {
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&VMRef->AliasClass,
            v9 + 3);
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Class *>(
            &VMRef->ClassAlias.mHash,
            (Scaleform::GFx::AS3::Class **)&VMRef->AliasClass.mHash.pTable[v14 + 2].EntryCount + v14);
        }
      }
    }
LABEL_22:
    v17 = v29->pTable->SizeMask;
    if ( v7 <= (__int64)v17 && ++v7 <= v17 )
    {
      v18 = &v29->pTable[v7 + 1];
      do
      {
        if ( v18->EntryCount != -2i64 )
          break;
        ++v7;
        ++v18;
      }
      while ( v7 <= v17 );
    }
  }
  Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(VMRef, this);
  if ( p_AliasClass->pTable )
  {
    v19 = 0i64;
    v20 = p_AliasClass->pTable->SizeMask + 1;
    do
    {
      v21 = p_AliasClass->pTable;
      if ( p_AliasClass->pTable[v19 + 1].EntryCount != -2i64 )
      {
        v22 = (Scaleform::GFx::ASStringNode *)v21[v19 + 1].SizeMask;
        if ( v22->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        v21[v19 + 1].EntryCount = -2i64;
      }
      ++v19;
      --v20;
    }
    while ( v20 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_AliasClass->pTable);
    p_AliasClass->pTable = 0i64;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::MethodInfo>::DestructArray(
    this->MethodInfoArray.Data.Data,
    this->MethodInfoArray.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->MethodInfoArray.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *)&this->FunctionTraitsCache);
  Size = this->Children.Data.Size;
  for ( i = &this->Children.Data.Data[Size - 1]; Size; --Size )
  {
    pObject = i->pObject;
    if ( i->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        i->pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    --i;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Children.Data.Data);
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear(&this->GlobalObjects);
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&this->AbsObjects);
  v28 = (Scaleform::Render::RenderBuffer *)this->File.pObject;
  if ( v28 )
    Scaleform::RefCountImpl::Release(v28);
  Scaleform::GFx::AS3::VMFile::~VMFile(this);
}

// File Line: 604
// RVA: 0x7D1880
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::VMAbcFile::Finalize_GC(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile::UnRegister(this);
}

// File Line: 610
// RVA: 0x7FEB30
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // rbx
  __int64 p_any_namespace; // rsi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  __int64 NextIndex; // rax
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rax
  __int64 v11; // rbx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v18; // [rsp+68h] [rbp+10h] BYREF

  pObject = this->File.pObject;
  if ( mn->Ind )
    p_any_namespace = (__int64)&pObject->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    p_any_namespace = (__int64)&pObject->Const_Pool.any_namespace;
  StringManagerRef = this->VMRef->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    StringManagerRef,
    &resulta,
    *(const char **)(p_any_namespace + 8),
    *(_QWORD *)(p_any_namespace + 16));
  NextIndex = mn->NextIndex;
  if ( (int)NextIndex >= 0 )
  {
    v10 = &pObject->Const_Pool.const_multiname.Data.Data[NextIndex];
    v11 = (__int64)(v10->Ind
                  ? &pObject->Const_Pool.ConstNamespace.Data.Data[v10->Ind]
                  : &pObject->Const_Pool.any_namespace);
    Scaleform::GFx::ASString::Append(&resulta, "$", 1ui64);
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            StringManagerRef,
            &v18,
            *(const char **)(v11 + 8),
            *(_QWORD *)(v11 + 16));
    Scaleform::GFx::ASString::Append(&resulta, v12);
    pNode = v18.pNode;
    v14 = v18.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(
    this->VMRef,
    result,
    *(Scaleform::GFx::AS3::Abc::NamespaceKind *)p_any_namespace,
    &resulta);
  v15 = resulta.pNode;
  v14 = resulta.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  return result;
}

// File Line: 631
// RVA: 0x7FEC50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        unsigned __int64 nsIndex)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // rax
  unsigned __int64 p_any_namespace; // rax

  pObject = this->File.pObject;
  if ( nsIndex )
    p_any_namespace = (unsigned __int64)&pObject->Const_Pool.ConstNamespace.Data.Data[nsIndex];
  else
    p_any_namespace = (unsigned __int64)&pObject->Const_Pool.any_namespace;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(
    this->VMRef,
    result,
    *(Scaleform::GFx::AS3::Abc::NamespaceKind *)p_any_namespace,
    (Scaleform::StringDataPtr *)(p_any_namespace + 8));
  return result;
}

// File Line: 637
// RVA: 0x7FECA0
Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespaceSet(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *result,
        unsigned __int64 nsSetIndex)
{
  Scaleform::GFx::AS3::NamespaceSet *v6; // rdi
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rdx
  const char *Data; // rbx
  char v9; // al
  char *v10; // rbx
  unsigned int v11; // r8d
  unsigned int v12; // ecx
  char v13; // dl
  __int64 v14; // rsi
  char v15; // al
  unsigned int v16; // r8d
  unsigned int v17; // ecx
  char v18; // dl
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *v20; // rax

  v6 = (Scaleform::GFx::AS3::NamespaceSet *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMAbcFile *, __int64))this->VMRef->MHeap->Scaleform::GFx::AS3::VMFile::vfptr->Alloc)(
                                              this,
                                              64i64);
  if ( v6 )
  {
    GC = this->VMRef->GC.GC;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    v6->RefCount = 1;
    v6->pRCCRaw = (unsigned __int64)GC;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::NamespaceSet::`vftable;
    v6->Namespaces.Data.Data = 0i64;
    v6->Namespaces.Data.Size = 0i64;
    v6->Namespaces.Data.Policy.Capacity = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  Data = this->File.pObject->Const_Pool.const_ns_set.Data.Data[nsSetIndex].Data;
  v9 = *Data;
  v10 = (char *)(Data + 1);
  v11 = v9 & 0x7F;
  v12 = 7;
  if ( v9 < 0 )
  {
    do
    {
      if ( v12 >= 0x20 )
        break;
      v13 = *v10++;
      v11 |= (v13 & 0x7F) << v12;
      v12 += 7;
    }
    while ( v13 < 0 );
  }
  if ( v11 )
  {
    v14 = v11;
    do
    {
      v15 = *v10++;
      v16 = v15 & 0x7F;
      v17 = 7;
      if ( v15 < 0 )
      {
        do
        {
          if ( v17 >= 0x20 )
            break;
          v18 = *v10++;
          v16 |= (v18 & 0x7F) << v17;
          v17 += 7;
        }
        while ( v18 < 0 );
      }
      InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this, v16);
      Scaleform::GFx::AS3::NamespaceSet::Add(v6, InternedNamespace);
      --v14;
    }
    while ( v14 );
  }
  v20 = result;
  result->pV = v6;
  return v20;
}

// File Line: 657
// RVA: 0x7FA450
Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeActivationInstanceTraits(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *result,
        Scaleform::GFx::AS3::Abc::MbiInd mbi_ind)
{
  Scaleform::GFx::AS3::VM *VMRef; // rsi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v6; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Activation *v7; // rax

  VMRef = this->VMRef;
  v6 = this->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind];
  v7 = (Scaleform::GFx::AS3::InstanceTraits::Activation *)VMRef->MHeap->vfptr->Alloc(
                                                            (Scaleform::MemoryHeap *)this,
                                                            216ui64,
                                                            0i64);
  if ( v7 )
    Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(v7, this, VMRef, v6);
  result->pV = v7;
  return result;
}

// File Line: 665
// RVA: 0x7FEDF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedString(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::ASString *result,
        unsigned __int64 strIndex)
{
  unsigned __int64 v5; // r9
  const char *Data; // r8
  const char *v7; // r8
  char v8; // al
  unsigned int v9; // ecx
  char v10; // dl

  v5 = 0i64;
  Data = this->File.pObject->Const_Pool.ConstStr.Data.Data[(unsigned int)strIndex].Data;
  if ( Data )
  {
    v8 = *Data;
    v7 = Data + 1;
    LODWORD(v5) = v8 & 0x7F;
    v9 = 7;
    if ( v8 < 0 )
    {
      do
      {
        if ( v9 >= 0x20 )
          break;
        v10 = *v7++;
        LODWORD(v5) = ((v10 & 0x7F) << v9) | v5;
        v9 += 7;
      }
      while ( v10 < 0 );
    }
    v5 = (int)v5;
  }
  else
  {
    v7 = &customCaption;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->VMRef->StringManagerRef,
    result,
    v7,
    v5);
  return result;
}

// File Line: 672
// RVA: 0x7D6830
void __fastcall Scaleform::GFx::AS3::VMAbcFile::ForEachChild_GC(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v6; // rsi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *v12; // rcx
  signed __int64 v13; // rdx
  bool v14; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v15; // rdx
  unsigned __int64 v16; // rdx
  unsigned __int64 *v17; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v18; // rcx
  unsigned __int64 v19; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v23; // rcx
  signed __int64 v24; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v25; // rdx
  unsigned __int64 v26; // rdx
  unsigned __int64 *v27; // rcx
  unsigned __int64 Size; // rdi
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v30; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v31; // rax
  unsigned __int64 v32; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v33; // rax
  signed __int64 v34; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v35; // rcx
  unsigned __int64 v36; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v37; // rcx
  Scaleform::HashSetLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > > *p_AbsObjects; // [rsp+20h] [rbp-10h]
  Scaleform::HashSetLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *p_GlobalObjects; // [rsp+20h] [rbp-10h]
  Scaleform::HashLH<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>,340,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> > *p_FunctionTraitsCache; // [rsp+20h] [rbp-10h]
  signed __int64 v41; // [rsp+28h] [rbp-8h]
  signed __int64 v42; // [rsp+28h] [rbp-8h]

  Scaleform::GFx::AS3::VMFile::ForEachChild_GC(this, prcc, op);
  v6 = 0i64;
  pTable = this->AbsObjects.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = pTable + 1;
    v10 = 0i64;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v10;
      v9 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *)((char *)v9 + 24);
    }
    while ( v10 <= SizeMask );
    p_AbsObjects = &this->AbsObjects;
    v41 = v10;
  }
  else
  {
    p_AbsObjects = 0i64;
    v41 = 0i64;
  }
  v11 = v41;
  while ( p_AbsObjects )
  {
    v12 = p_AbsObjects->pTable;
    if ( !p_AbsObjects->pTable || v11 > (signed __int64)v12->SizeMask )
      break;
    v13 = v11 + 2 * (v11 + 2);
    v14 = *(&v12->EntryCount + v13) == 0;
    v15 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(&v12->EntryCount + v13);
    if ( !v14 )
      op(prcc, v15);
    v16 = p_AbsObjects->pTable->SizeMask;
    if ( v11 <= (__int64)v16 && ++v11 <= v16 )
    {
      v17 = &p_AbsObjects->pTable[1].EntryCount + 3 * v11;
      do
      {
        if ( *v17 != -2i64 )
          break;
        ++v11;
        v17 += 3;
      }
      while ( v11 <= v16 );
    }
  }
  v18 = this->GlobalObjects.pTable;
  if ( v18 )
  {
    v19 = v18->SizeMask;
    v20 = v18 + 1;
    v21 = 0i64;
    do
    {
      if ( v20->EntryCount != -2i64 )
        break;
      ++v21;
      v20 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *)((char *)v20 + 24);
    }
    while ( v21 <= v19 );
    p_GlobalObjects = &this->GlobalObjects;
    v42 = v21;
  }
  else
  {
    p_GlobalObjects = 0i64;
    v42 = 0i64;
  }
  v22 = v42;
  while ( p_GlobalObjects )
  {
    v23 = p_GlobalObjects->pTable;
    if ( !p_GlobalObjects->pTable || v22 > (signed __int64)v23->SizeMask )
      break;
    v24 = v22 + 2 * (v22 + 2);
    v14 = *(&v23->EntryCount + v24) == 0;
    v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(&v23->EntryCount + v24);
    if ( !v14 )
      op(prcc, v25);
    v26 = p_GlobalObjects->pTable->SizeMask;
    if ( v22 <= (__int64)v26 && ++v22 <= v26 )
    {
      v27 = &p_GlobalObjects->pTable[1].EntryCount + 3 * v22;
      do
      {
        if ( *v27 != -2i64 )
          break;
        ++v22;
        v27 += 3;
      }
      while ( v22 <= v26 );
    }
  }
  Size = this->Children.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v30 = &this->Children.Data.Data[i];
    if ( v30->pObject )
      op(prcc, &v30->pObject);
  }
  v31 = this->FunctionTraitsCache.mHash.pTable;
  if ( v31 )
  {
    v32 = v31->SizeMask;
    v33 = v31 + 1;
    do
    {
      if ( v33->EntryCount != -2i64 )
        break;
      ++v6;
      v33 += 2;
    }
    while ( v6 <= v32 );
    p_FunctionTraitsCache = &this->FunctionTraitsCache;
  }
  else
  {
    p_FunctionTraitsCache = 0i64;
  }
  v34 = v6;
  while ( p_FunctionTraitsCache )
  {
    v35 = p_FunctionTraitsCache->mHash.pTable;
    if ( !p_FunctionTraitsCache->mHash.pTable || v34 > (signed __int64)v35->SizeMask )
      break;
    if ( v35[2 * v34 + 2].SizeMask )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
    v36 = p_FunctionTraitsCache->mHash.pTable->SizeMask;
    if ( v34 <= (__int64)v36 && ++v34 <= v36 )
    {
      v37 = &p_FunctionTraitsCache->mHash.pTable[2 * v34 + 1];
      do
      {
        if ( v37->EntryCount != -2i64 )
          break;
        ++v34;
        v37 += 2;
      }
      while ( v34 <= v36 );
    }
  }
}

// File Line: 710
// RVA: 0x8104C0
char __fastcall Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // rax
  __int64 v3; // r15
  Scaleform::GFx::AS3::VM *VMRef; // r13
  unsigned __int64 Size; // r12
  unsigned __int64 v6; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v7; // r12
  Scaleform::GFx::AS3::Abc::Multiname *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *v13; // r15
  Scaleform::GFx::AS3::VMAppDomain *pTable; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // r14
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *v17; // r14
  signed __int64 v18; // rax
  __int64 v19; // r14
  unsigned int v20; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  __int64 v23; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v24; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::ASStringNode *v27; // rcx
  __int64 v28; // rdi
  unsigned __int64 v29; // rdx
  unsigned __int64 v30; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *Data; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v32; // rdx
  int v33; // eax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v34; // rax
  __int64 v35; // rax
  __int64 v36; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v37; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v41; // rdx
  int v42; // eax
  unsigned __int64 v43; // rdi
  Scaleform::GFx::AS3::Abc::ClassInfo *v44; // r14
  Scaleform::GFx::AS3::Abc::Multiname *v45; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *UserDefinedTraits; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  char v50; // r14
  Scaleform::GFx::AS3::VMAppDomain *v51; // rcx
  Scaleform::GFx::ASStringNode *v52; // rdi
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v54; // rcx
  __int64 v56; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::GFx::ASStringNode *v57; // [rsp+28h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v58; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+38h] [rbp-51h] BYREF
  Scaleform::GFx::ASStringNode *v60; // [rsp+48h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v61; // [rsp+50h] [rbp-39h]
  void *MHeap; // [rsp+58h] [rbp-31h]
  unsigned __int64 v63; // [rsp+60h] [rbp-29h]
  __int64 v64; // [rsp+68h] [rbp-21h]
  __int64 v65; // [rsp+70h] [rbp-19h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v66; // [rsp+78h] [rbp-11h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v67; // [rsp+88h] [rbp-1h] BYREF
  __int64 v68; // [rsp+98h] [rbp+Fh]
  __int64 v69; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+6Fh] BYREF
  unsigned __int64 v71; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::AS3::Abc::File *v72; // [rsp+108h] [rbp+7Fh]

  v68 = -2i64;
  pObject = this->File.pObject;
  v72 = pObject;
  v3 = 0i64;
  v69 = 0i64;
  VMRef = this->VMRef;
  Size = pObject->AS3_Classes.Info.Data.Size;
  v63 = Size;
  v6 = 0i64;
  v71 = 0i64;
  if ( !Size )
  {
LABEL_73:
    v43 = 0i64;
    if ( Size )
    {
      do
      {
        v44 = v72->AS3_Classes.Info.Data.Data[v43];
        v45 = &this->File.pObject->Const_Pool.const_multiname.Data.Data[v44->inst_info.name_ind];
        Scaleform::GFx::AS3::VMFile::GetInternedString(this, &result, v45->NameIndex);
        InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this, v45->Ind);
        if ( (_S13_9 & 1) == 0 )
        {
          _S13_9 |= 1u;
          scaleform_gfx.pStr = "scaleform.gfx";
          scaleform_gfx.Size = 13i64;
        }
        pNode = InternedNamespace->Uri.pNode;
        if ( pNode->Size < scaleform_gfx.Size || strncmp(pNode->pData, scaleform_gfx.pStr, scaleform_gfx.Size) )
        {
          UserDefinedTraits = Scaleform::GFx::AS3::VM::GetUserDefinedTraits(VMRef, this, v44);
          if ( UserDefinedTraits->File.pObject == this
            && !Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(
                  UserDefinedTraits,
                  (Scaleform::GFx::AS3::CheckResult *)&v69)->Result )
          {
            if ( VMRef->HandleException )
              Scaleform::GFx::AS3::VM::OutputAndIgnoreException(VMRef);
            v51 = this->AppDomain.pObject;
            v52 = result.pNode;
            key.Name = result;
            ++result.pNode->RefCount;
            key.pNs.pObject = InternedNamespace;
            if ( InternedNamespace )
              InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
              &v51->ClassTraitsSet.Entries.mHash,
              (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&key);
            if ( InternedNamespace )
            {
              if ( ((unsigned __int8)InternedNamespace & 1) != 0 )
              {
                key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)InternedNamespace - 1);
              }
              else
              {
                RefCount = InternedNamespace->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  InternedNamespace->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(InternedNamespace);
                }
              }
            }
            v12 = v52->RefCount-- == 1;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v52);
            v54 = result.pNode;
            v12 = result.pNode->RefCount-- == 1;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
            Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(this);
            return 0;
          }
        }
        v49 = result.pNode;
        v12 = result.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v49);
        ++v43;
      }
      while ( v43 < Size );
      v50 = 0;
      if ( !v3 )
        return v50;
    }
    return 1;
  }
  do
  {
    v7 = pObject->AS3_Classes.Info.Data.Data[v6];
    v8 = &this->File.pObject->Const_Pool.const_multiname.Data.Data[v7->inst_info.name_ind];
    Scaleform::GFx::AS3::VMFile::GetInternedString(this, &result, v8->NameIndex);
    v9 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this, v8->Ind);
    if ( (_S13_9 & 1) == 0 )
    {
      _S13_9 |= 1u;
      scaleform_gfx.pStr = "scaleform.gfx";
      scaleform_gfx.Size = 13i64;
    }
    v10 = v9->Uri.pNode;
    if ( v10->Size < scaleform_gfx.Size || strncmp(v10->pData, scaleform_gfx.pStr, scaleform_gfx.Size) )
    {
      v13 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)this->AppDomain.pObject;
      pTable = (Scaleform::GFx::AS3::VMAppDomain *)v13[5].pTable;
      if ( !pTable || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(pTable, &result, v9)) == 0i64 )
      {
        v16 = result.pNode;
        key.Name = result;
        ++result.pNode->RefCount;
        key.pNs.pObject = v9;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
        v17 = v13[6].pTable;
        if ( v17
          && (v18 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                      v13 + 6,
                      &key,
                      v17->SizeMask & (v16->HashFlags & 0xFFFFFF ^ (4 * (v9->Uri.pNode->HashFlags & 0xFFFFFF)) ^ (unsigned __int64)(unsigned int)((int)(*((_DWORD *)v9 + 10) << 28) >> 28))),
              v18 >= 0)
          && (v19 = (__int64)&v17[2] + 40 * v18) != 0 )
        {
          ClassTrait = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v19 + 16);
        }
        else
        {
          ClassTrait = 0i64;
        }
        if ( v9 )
        {
          if ( ((unsigned __int8)v9 & 1) != 0 )
          {
            key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v9 - 1);
          }
          else
          {
            v20 = v9->RefCount;
            if ( (v20 & 0x3FFFFF) != 0 )
            {
              v9->RefCount = v20 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
            }
          }
        }
        v12 = v16->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        if ( !ClassTrait )
          goto LABEL_26;
      }
      v21 = *ClassTrait;
      if ( !*ClassTrait )
      {
LABEL_26:
        ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                        VMRef->GlobalObject.pObject,
                        &result,
                        v9);
        v21 = ClassTraits;
        if ( !ClassTraits )
        {
          MHeap = VMRef->MHeap;
          v34 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)MHeap + 80i64))(
                                                                   v23,
                                                                   224i64,
                                                                   0i64);
          v56 = (__int64)v34;
          if ( v34 )
          {
            Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(v34, this, VMRef, v7);
            v36 = v35;
          }
          else
          {
            v36 = 0i64;
          }
          v37 = this->AppDomain.pObject;
          v56 = v36;
          v60 = result.pNode;
          ++result.pNode->RefCount;
          v61 = v9;
          if ( v9 )
            v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
          v66.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v60;
          v66.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v56;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
            &v37->ClassTraitsSet.Entries.mHash,
            v37->ClassTraitsSet.Entries.mHash.pHeap,
            &v66,
            v60->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v61[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v61[1].vfptr) << 28) >> 28));
          v38 = v61;
          if ( v61 )
          {
            if ( ((unsigned __int8)v61 & 1) != 0 )
            {
              v61 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v61 - 1);
            }
            else
            {
              v39 = v61->RefCount;
              if ( (v39 & 0x3FFFFF) != 0 )
              {
                v61->RefCount = v39 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
              }
            }
          }
          v40 = v60;
          v12 = v60->RefCount-- == 1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v40);
          v3 = ++v69;
          v65 = v36;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&this->LoadedClasses,
            &this->LoadedClasses,
            this->LoadedClasses.Data.Size + 1);
          v41 = &this->LoadedClasses.Data.Data[this->LoadedClasses.Data.Size - 1];
          MHeap = v41;
          v56 = (__int64)v41;
          if ( v41 )
          {
            v41->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v36;
            if ( v36 )
              *(_DWORD *)(v36 + 32) = (*(_DWORD *)(v36 + 32) + 1) & 0x8FBFFFFF;
          }
          if ( v36 )
          {
            if ( (v36 & 1) != 0 )
            {
              v65 = v36 - 1;
            }
            else
            {
              v42 = *(_DWORD *)(v36 + 32);
              if ( (v42 & 0x3FFFFF) != 0 )
              {
                *(_DWORD *)(v36 + 32) = v42 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v36);
              }
            }
          }
          goto LABEL_68;
        }
        v24 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *)VMRef->SystemDomain.pObject;
        v56 = (__int64)ClassTraits;
        v57 = result.pNode;
        ++result.pNode->RefCount;
        v58 = v9;
        if ( v9 )
          v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
        v67.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v57;
        v67.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v56;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
          v24 + 6,
          v24[7].pTable,
          &v67,
          v57->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v58[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v58[1].vfptr) << 28) >> 28));
        v25 = v58;
        if ( v58 )
        {
          if ( ((unsigned __int8)v58 & 1) != 0 )
          {
            v58 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v58 - 1);
          }
          else
          {
            v26 = v58->RefCount;
            if ( (v26 & 0x3FFFFF) != 0 )
            {
              v58->RefCount = v26 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
            }
          }
        }
        v27 = v57;
        v12 = v57->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      v28 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))v21->vfptr[2].~RefCountBaseGC<328>)(v21);
      if ( v28 )
      {
        v29 = this->Children.Data.Size;
        v30 = 0i64;
        if ( v29 )
        {
          Data = this->Children.Data.Data;
          while ( Data->pObject != (Scaleform::GFx::AS3::VMAbcFile *)v28 )
          {
            ++v30;
            ++Data;
            if ( v30 >= v29 )
              goto LABEL_41;
          }
        }
        else
        {
LABEL_41:
          v64 = v28;
          *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->Children.Data,
            &this->Children,
            this->Children.Data.Size + 1);
          v32 = &this->Children.Data.Data[this->Children.Data.Size - 1];
          v56 = (__int64)v32;
          MHeap = v32;
          if ( v32 )
          {
            v32->pObject = (Scaleform::GFx::AS3::VMAbcFile *)v28;
            *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
          }
          if ( (v28 & 1) != 0 )
          {
            v64 = v28 - 1;
          }
          else
          {
            v33 = *(_DWORD *)(v28 + 32);
            if ( (v33 & 0x3FFFFF) != 0 )
            {
              *(_DWORD *)(v28 + 32) = v33 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28);
            }
          }
        }
      }
      v3 = v69;
LABEL_68:
      v11 = result.pNode;
      v12 = result.pNode->RefCount-- == 1;
      if ( !v12 )
        goto LABEL_70;
      goto LABEL_69;
    }
    v11 = result.pNode;
    v12 = result.pNode->RefCount-- == 1;
    if ( !v12 )
      goto LABEL_70;
LABEL_69:
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
LABEL_70:
    v6 = v71 + 1;
    v71 = v6;
    Size = v63;
    pObject = v72;
  }
  while ( v6 < v63 );
  if ( v3 || !v63 )
    goto LABEL_73;
  return 0;
}

// File Line: 872
// RVA: 0x8292D0
void __fastcall Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  unsigned __int64 Size; // r14
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rdi
  unsigned int RefCount; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rcx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key key; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASStringNode *v14; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::ClassTraits::Traits *v; // [rsp+68h] [rbp+10h] BYREF

  Size = this->LoadedClasses.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    Data = this->LoadedClasses.Data.Data;
    pObject = Data[i].pObject->ITraits.pObject;
    if ( pObject )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **))pObject->vfptr[1].~RefCountBaseGC<328>)(
        pObject,
        &v14);
      v6 = pObject->Ns.pObject;
      v7 = this->AppDomain.pObject;
      v8 = v14;
      key.Name.pNode = v14;
      ++v14->RefCount;
      key.pNs.pObject = v6;
      if ( v6 )
        v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
        &v7->ClassTraitsSet.Entries.mHash,
        &key);
      if ( v6 )
      {
        if ( ((unsigned __int8)v6 & 1) != 0 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v6 - 1);
        }
        else
        {
          RefCount = v6->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v6->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
          }
        }
      }
      v10 = v8->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      v11 = v14;
      v10 = v14->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    else
    {
      v12 = this->AppDomain.pObject;
      v = Data[i].pObject;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::RemoveValue(
        &v12->ClassTraitsSet,
        &v);
    }
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&this->LoadedClasses,
    &this->LoadedClasses,
    0i64);
}

// File Line: 917
// RVA: 0x80FC90
bool __fastcall Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(Scaleform::GFx::AS3::VMAbcFile *this, bool to_execute)
{
  char v2; // al
  Scaleform::GFx::AS3::VM *VMRef; // rbp
  Scaleform::GFx::AS3::Abc::File *pObject; // r13
  unsigned __int64 Size; // r12
  __int64 v7; // r14
  Scaleform::GFx::AS3::Abc::HasTraits *v8; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v9; // rax
  Scaleform::GFx::AS3::Traits *v10; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v11; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *pV; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v13; // rdi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int RefCount; // eax
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObject *v19; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> v20; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+A0h] [rbp+8h] BYREF
  bool v22; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> key; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v24; // [rsp+B8h] [rbp+20h]

  v22 = to_execute;
  v2 = to_execute;
  VMRef = this->VMRef;
  pObject = this->File.pObject;
  Size = pObject->Scripts.Info.Data.Size;
  v7 = 0i64;
  if ( Size )
  {
    while ( 1 )
    {
      v8 = pObject->Scripts.Info.Data.Data[v7];
      v24 = 0i64;
      v9 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)VMRef->MHeap->vfptr->Alloc(
                                                                      (Scaleform::MemoryHeap *)this,
                                                                      256ui64,
                                                                      0i64);
      v10 = v9;
      if ( v9 )
      {
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v9, VMRef);
        v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::`vftable;
        v10[1].FirstOwnSlotNum = (unsigned __int64)this;
        this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
        v10[1].Parent = (Scaleform::GFx::AS3::Slots *)v8;
        Scaleform::GFx::AS3::Traits::AddSlots(v10, &result, v8, this, 0x40u);
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 0i64;
      if ( v10 )
        v11 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)v10;
      v24 = v11;
      if ( VMRef->HandleException )
        break;
      pV = Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::MakeInstance(v11, &v20)->pV;
      key.pObject = pV;
      if ( VMRef->HandleException )
      {
        if ( pV )
        {
          if ( ((unsigned __int8)pV & 1) != 0 )
          {
            key.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)pV - 1);
          }
          else
          {
            RefCount = pV->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              pV->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
            }
          }
        }
        break;
      }
      Scaleform::GFx::AS3::VM::RegisterGlobalObject(VMRef, pV);
      Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>>>::Set<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>(
        &this->GlobalObjects,
        &this->GlobalObjects,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&key);
      v13 = key.pObject;
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::InitUserDefinedClassTraits(key.pObject);
      if ( v13 )
      {
        if ( ((unsigned __int8)v13 & 1) != 0 )
        {
          key.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)v13 - 1);
        }
        else
        {
          v14 = v13->RefCount;
          if ( (v14 & 0x3FFFFF) != 0 )
          {
            v13->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
      if ( v11 )
      {
        if ( ((unsigned __int8)v11 & 1) != 0 )
        {
          v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)((char *)v11 - 1);
        }
        else
        {
          v15 = v11->RefCount;
          if ( (v15 & 0x3FFFFF) != 0 )
          {
            v11->RefCount = v15 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
      if ( ++v7 >= Size )
      {
        v2 = v22;
        goto LABEL_32;
      }
    }
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)((char *)v11 - 1);
      }
      else
      {
        v17 = v11->RefCount;
        if ( (v17 & 0x3FFFFF) != 0 )
        {
          v11->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
    }
    return 0;
  }
  else
  {
LABEL_32:
    if ( v2 )
    {
      if ( Size )
      {
        v19 = VMRef->GlobalObjects.Data.Data[VMRef->GlobalObjects.Data.Size - 1];
        v19->vfptr[6].Finalize_GC(v19);
      }
    }
    return !VMRef->HandleException;
  }
}

// File Line: 964
// RVA: 0x7F9B50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VMAbcFile::Load(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool to_execute)
{
  if ( Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(this)
    && Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(this, to_execute) )
  {
    result->Result = 1;
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 978
// RVA: 0x8288F0
void __fastcall Scaleform::GFx::AS3::VMAbcFile::UnRegister(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *pTable; // rcx
  Scaleform::HashSetLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,2,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *p_GlobalObjects; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v5; // rax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v6; // rax
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 *v8; // rcx
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v10; // rax
  Scaleform::GFx::AS3::VM *VMRef; // rcx

  if ( Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(this->VMRef, this) )
  {
    Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(this);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->MethodInfoArray.Data,
      &this->MethodInfoArray,
      0i64);
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&this->AbsObjects);
    pTable = this->GlobalObjects.pTable;
    p_GlobalObjects = 0i64;
    v4 = 0i64;
    if ( pTable )
    {
      v5 = pTable + 1;
      do
      {
        if ( v5->EntryCount != -2i64 )
          break;
        ++v4;
        v5 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *)((char *)v5 + 24);
      }
      while ( v4 <= pTable->SizeMask );
      p_GlobalObjects = &this->GlobalObjects;
    }
    while ( p_GlobalObjects )
    {
      v6 = p_GlobalObjects->pTable;
      if ( !p_GlobalObjects->pTable || (signed __int64)v4 > (signed __int64)v6->SizeMask )
        break;
      Scaleform::GFx::AS3::VM::UnregisterGlobalObject(
        this->VMRef,
        *((Scaleform::GFx::AS3::Instances::fl::GlobalObject **)&v6[2].EntryCount + 3 * v4));
      SizeMask = p_GlobalObjects->pTable->SizeMask;
      if ( (__int64)v4 <= (__int64)SizeMask && ++v4 <= SizeMask )
      {
        v8 = &p_GlobalObjects->pTable[1].EntryCount + 3 * v4;
        do
        {
          if ( *v8 != -2i64 )
            break;
          ++v4;
          v8 += 3;
        }
        while ( v4 <= SizeMask );
      }
    }
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear(&this->GlobalObjects);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Children.Data,
      &this->Children,
      0i64);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *)&this->FunctionTraitsCache);
    __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ(&this->IntNamespaces.Entries.mHash);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&this->IntNamespaceSets,
      &this->IntNamespaceSets,
      0i64);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->IntStrings.Data,
      &this->IntStrings,
      0i64);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>(&this->ActivationTraitsCache.mHash);
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::~HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>(&this->ASStringNodeSet);
    pObject = this->AppDomain.pObject;
    v10 = pObject->ClassTraitsSet.Entries.mHash.pTable;
    if ( (!v10 || !v10->EntryCount) && !pObject->ChildDomains.Data.Size )
    {
      VMRef = this->VMRef;
      if ( !VMRef->LoadingAbcFile )
        Scaleform::GFx::AS3::VMAppDomain::RemoveChild(VMRef->SystemDomain.pObject, pObject);
    }
  }
}

// File Line: 1019
// RVA: 0x7ED750
Scaleform::ArrayLH_POD<unsigned __int64,338,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetOpCode(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::VM *VMRef; // rdi
  Scaleform::GFx::AS3::MethodInfo *v3; // rbx
  Scaleform::GFx::AS3::Tracer v5; // [rsp+30h] [rbp-148h] BYREF

  VMRef = this->VMRef;
  v3 = &this->MethodInfoArray.Data.Data[cf->MBIIndex.Ind];
  if ( !v3->OpCode.Data.Size )
  {
    Scaleform::GFx::AS3::Tracer::Tracer(&v5, VMRef->MHeap, cf, &this->MethodInfoArray.Data.Data[cf->MBIIndex.Ind]);
    if ( !VMRef->HandleException )
      Scaleform::GFx::AS3::Tracer::EmitCode(&v5);
    Scaleform::GFx::AS3::Tracer::~Tracer(&v5);
  }
  return &v3->OpCode;
}

// File Line: 1056
// RVA: 0x7E86F0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Abc::ValueDetail *d)
{
  unsigned __int64 ValueIndex; // rdx
  int v5; // edx
  int v6; // edx
  long double Double; // xmm0_8
  Scaleform::GFx::ASString *InternedString; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value::V1U v12; // rcx
  Scaleform::GFx::AS3::Value::V1U v13; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+18h] BYREF

  ValueIndex = d->ValueIndex;
  if ( (int)ValueIndex <= 0 )
  {
LABEL_26:
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    result->Flags = v.Flags;
    result->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    result->value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( (v.Flags & 0x1F) == 10 )
      {
        v13 = v.value.VS._1;
LABEL_40:
        ++v13.VStr->RefCount;
      }
      else if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            return result;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    switch ( d->Kind )
    {
      case 0:
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        goto LABEL_11;
      case 1:
        InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(this, &resulta, ValueIndex);
        Scaleform::GFx::AS3::Value::Value(result, InternedString);
        pNode = resulta.pNode;
        if ( resulta.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return result;
      case 3:
        v5 = this->File.pObject->Const_Pool.ConstInt.Data.Data[ValueIndex];
        result->Flags = 2;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VInt = v5;
        return result;
      case 4:
        v6 = this->File.pObject->Const_Pool.ConstUInt.Data.Data[ValueIndex];
        result->Flags = 3;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VInt = v6;
        return result;
      case 5:
      case 8:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1A:
        InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this, ValueIndex);
        result->Flags = 11;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)InternedNamespace;
        if ( InternedNamespace )
          InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
        return result;
      case 6:
        Double = Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(&this->File.pObject->Const_Pool, ValueIndex);
        result->Flags = 4;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VNumber = Double;
        return result;
      case 0xA:
        result->Flags = 1;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VBool = 0;
        return result;
      case 0xB:
        result->Flags = 1;
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VBool = 1;
        return result;
      case 0xC:
        Undefined = Scaleform::GFx::AS3::Value::GetNull();
LABEL_11:
        result->Flags = Undefined->Flags;
        result->Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
        result->value.VS._1.VStr = Undefined->value.VS._1.VStr;
        result->value.VS._2.VObj = Undefined->value.VS._2.VObj;
        if ( (Undefined->Flags & 0x1F) <= 9 )
          return result;
        if ( (Undefined->Flags & 0x200) != 0 )
        {
          ++Undefined->Bonus.pWeakProxy->RefCount;
          return result;
        }
        if ( (Undefined->Flags & 0x1F) == 10 )
        {
          v13 = Undefined->value.VS._1;
          goto LABEL_40;
        }
        if ( (Undefined->Flags & 0x1F) <= 0xA )
          return result;
        if ( (Undefined->Flags & 0x1F) <= 0xF )
        {
          v12 = Undefined->value.VS._1;
        }
        else
        {
          if ( (Undefined->Flags & 0x1F) > 0x11 )
            return result;
          v12 = (Scaleform::GFx::AS3::Value::V1U)Undefined->value.VS._2.VObj;
        }
        if ( v12.VStr )
          v12.VStr->Size = (v12.VStr->Size + 1) & 0x8FBFFFFF;
        break;
      default:
        goto LABEL_26;
    }
  }
  return result;
}

// File Line: 1105
// RVA: 0x7E9E50
Scaleform::GFx::AS3::InstanceTraits::Function *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetFunctionInstanceTraits(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos,
        unsigned int method_ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *p_FunctionTraitsCache; // rsi
  __int64 Index; // rax
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Function *v12; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rdi
  __int64 v15; // rdx
  unsigned __int64 v16; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  unsigned int RefCount; // eax
  Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeRef key; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *MHeap; // [rsp+70h] [rbp+8h] BYREF
  unsigned int mi; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::InstanceTraits::Function *v22; // [rsp+88h] [rbp+20h]

  mi = method_ind;
  p_FunctionTraitsCache = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *)&this->FunctionTraitsCache;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *)&this->FunctionTraitsCache,
            (Scaleform::GFx::AS3::Abc::MbiInd *)&mi);
  if ( Index >= 0 )
  {
    v8 = (__int64)&p_FunctionTraitsCache->pTable[2 * Index + 2];
    if ( v8 )
    {
      v9 = v8 + 8;
      if ( v9 )
        return *(Scaleform::GFx::AS3::InstanceTraits::Function **)v9;
    }
  }
  VMRef = this->VMRef;
  MHeap = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)VMRef->MHeap;
  v12 = (Scaleform::GFx::AS3::InstanceTraits::Function *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))MHeap->vfptr[3].~RefCountBaseGC<328>)(
                                                           v7,
                                                           264i64,
                                                           0i64);
  v22 = v12;
  if ( v12 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Function::Function(v12, this, &Scaleform::GFx::AS3::fl::FunctionCI, mi, gos);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  if ( VMRef->HandleException )
    return VMRef->NoFunctionTraits.pObject;
  MHeap = v14;
  key.pFirst = (Scaleform::GFx::AS3::Abc::MbiInd *)&mi;
  key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *)&MHeap;
  v15 = 4i64;
  v16 = 5381i64;
  do
  {
    --v15;
    v16 = *((unsigned __int8 *)&mi + v15) + 65599 * v16;
  }
  while ( v15 );
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::add<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeRef>(
    p_FunctionTraitsCache,
    p_FunctionTraitsCache,
    &key,
    v16);
  v17 = MHeap;
  if ( MHeap )
  {
    if ( ((unsigned __int8)MHeap & 1) != 0 )
    {
      MHeap = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)MHeap - 1);
    }
    else
    {
      RefCount = MHeap->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        MHeap->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
  return (Scaleform::GFx::AS3::InstanceTraits::Function *)v14;
}

// File Line: 1151
// RVA: 0x7EC600
Scaleform::GFx::AS3::Abc::Multiname *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetMultiname(
        Scaleform::GFx::AS3::VMAbcFile *this,
        unsigned __int64 ind)
{
  return &this->File.pObject->Const_Pool.const_multiname.Data.Data[ind];
}

// File Line: 1157
// RVA: 0x7900E0
void __fastcall Scaleform::GFx::AS3::XMLSupport::~XMLSupport(Scaleform::GFx::AS3::XMLSupport *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable;
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 1172
// RVA: 0x7C9900
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupport::EqualsXML(
        Scaleform::GFx::AS3::XMLSupport *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *stop,
        bool *a4)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rax

  *stop = 1;
  result->Result = 0;
  v4 = result;
  *a4 = 0;
  return v4;
}

// File Line: 1185
// RVA: 0x7C9890
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupport::EqualsXMLList(
        Scaleform::GFx::AS3::XMLSupport *this,
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a3,
        Scaleform::GFx::AS3::Instances::fl::XMLList *__formal)
{
  *a3 = 0;
  result->Result = 0;
  return result;
}

// File Line: 1238
// RVA: 0x7E5EB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetArrayInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        unsigned int *ind)
{
  unsigned int Size; // r9d
  const char *pData; // r10
  char v7; // al
  unsigned int v9; // ecx
  _BYTE *v10; // rdx
  double v11; // xmm0_8
  char *endptr; // [rsp+38h] [rbp+10h] BYREF

  Size = sn->Size;
  if ( Size )
  {
    pData = sn->pData;
    v7 = *sn->pData;
    if ( v7 == 48 )
    {
      *ind = 0;
      result->Result = Size == 1;
      return result;
    }
    if ( (unsigned __int8)(v7 - 48) <= 9u )
    {
      v9 = 1;
      if ( Size <= 1 )
      {
LABEL_9:
        v11 = strtod(pData, &endptr);
        if ( v11 <= 4294967295.0 )
        {
          result->Result = 1;
          *ind = (int)v11;
          return result;
        }
      }
      else
      {
        v10 = pData + 1;
        while ( (unsigned __int8)(*v10 - 48) <= 9u )
        {
          ++v9;
          ++v10;
          if ( v9 >= Size )
            goto LABEL_9;
        }
      }
    }
  }
  result->Result = 0;
  return result;
}

// File Line: 1276
// RVA: 0x7E5E50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetArrayInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        unsigned int *ind)
{
  unsigned int v4; // eax
  bool v5; // cl
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  bool v7; // cl
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF

  v4 = prop_name->Name.Flags & 0x1F;
  if ( v4 == 10 )
  {
    v5 = Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name->Name.value.VS._1.VStr, ind)->Result;
    v6 = result;
    result->Result = v5;
  }
  else if ( v4 - 2 > 2 )
  {
    result->Result = 0;
    return result;
  }
  else
  {
    v7 = Scaleform::GFx::AS3::Value::Convert2UInt32(&prop_name->Name, &resulta, ind)->Result;
    v6 = result;
    result->Result = v7;
  }
  return v6;
}

// File Line: 1290
// RVA: 0x7F1AD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetVectorInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        unsigned int *ind)
{
  double v5; // xmm0_8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF
  long double v8; // [rsp+48h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::GetStrNumber(&resulta, sn, &v8)->Result && (v5 = v8, v8 <= 4294967295.0) )
  {
    result->Result = 1;
    *ind = (int)v5;
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 1308
// RVA: 0x7F1A10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetVectorInd(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        unsigned int *ind)
{
  bool v3; // bl
  long double VNumber; // xmm6_8
  int VInt; // eax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+8h] BYREF
  long double iptr; // [rsp+58h] [rbp+10h] BYREF

  v3 = 0;
  switch ( prop_name->Name.Flags & 0x1F )
  {
    case 2u:
      VInt = prop_name->Name.value.VS._1.VInt;
      if ( VInt < 0 )
        break;
      goto LABEL_12;
    case 3u:
      VInt = prop_name->Name.value.VS._1.VInt;
LABEL_12:
      *ind = VInt;
      goto LABEL_13;
    case 4u:
      VNumber = prop_name->Name.value.VNumber;
      if ( VNumber < 0.0 || modf(VNumber, &iptr) != 0.0 || VNumber > 4294967295.0 )
        break;
      *ind = (int)VNumber;
LABEL_13:
      v3 = 1;
      break;
    case 10u:
      v3 = Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name->Name.value.VS._1.VStr, ind)->Result;
      break;
  }
  result->Result = v3;
  return result;
}

// File Line: 1356
// RVA: 0x7EFEC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetStrNumber(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *sn,
        long double *a3)
{
  unsigned int Size; // r8d
  const char *pData; // r10
  unsigned int v7; // ecx
  _BYTE *v8; // rdx
  long double v9; // xmm0_8
  Scaleform::GFx::AS3::CheckResult *v10; // rax
  unsigned int v11; // eax
  const char *v12; // rcx
  char *endptr; // [rsp+38h] [rbp+10h] BYREF

  if ( sn )
  {
    Size = sn->Size;
    if ( Size )
    {
      pData = sn->pData;
      if ( (unsigned __int8)(*sn->pData - 48) <= 9u )
      {
        v7 = 1;
        if ( Size > 1 )
        {
          v8 = pData + 1;
          while ( (unsigned __int8)(*v8 - 48) <= 9u )
          {
            ++v7;
            ++v8;
            if ( v7 >= Size )
              goto LABEL_8;
          }
          if ( *v8 != 46 )
            goto LABEL_15;
          v11 = v7 + 1;
          if ( v7 + 1 < Size )
          {
            v12 = &pData[v11];
            while ( *v12 == 48 )
            {
              ++v11;
              ++v12;
              if ( v11 >= Size )
                goto LABEL_8;
            }
LABEL_15:
            result->Result = 0;
            return result;
          }
        }
LABEL_8:
        v9 = strtod(pData, &endptr);
        result->Result = 1;
        v10 = result;
        *a3 = v9;
        return v10;
      }
    }
  }
  v10 = result;
  result->Result = 0;
  return v10;
}

// File Line: 1480
// RVA: 0x77BBE0
void __fastcall Scaleform::GFx::AS3::CallFrame::CallFrame(
        Scaleform::GFx::AS3::CallFrame *this,
        Scaleform::GFx::AS3::CallFrame *other)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r8
  unsigned int Flags; // r8d
  Scaleform::GFx::AS3::Value::V2U v4; // r8
  Scaleform::GFx::AS3::Value::V1U v5; // r8

  this->DiscardResult = other->DiscardResult;
  this->ACopy = 1;
  this->ScopeStackBaseInd = other->ScopeStackBaseInd;
  this->CP = other->CP;
  this->pRegisterFile = other->pRegisterFile;
  this->pHeap = other->pHeap;
  this->pFile = other->pFile;
  this->MBIIndex.Ind = other->MBIIndex.Ind;
  this->pSavedScope = other->pSavedScope;
  this->OriginationTraits = other->OriginationTraits;
  this->pScopeStack = other->pScopeStack;
  this->PrevInitialStackPos = other->PrevInitialStackPos;
  pObject = other->DefXMLNamespace.pObject;
  this->DefXMLNamespace.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->PrevFirstStackPos = other->PrevFirstStackPos;
  this->Invoker.Flags = other->Invoker.Flags;
  this->Invoker.Bonus.pWeakProxy = other->Invoker.Bonus.pWeakProxy;
  this->Invoker.value = other->Invoker.value;
  Flags = other->Invoker.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++other->Invoker.Bonus.pWeakProxy->RefCount;
    }
    else if ( (other->Invoker.Flags & 0x1F) == 10 )
    {
      ++other->Invoker.value.VS._1.VStr->RefCount;
    }
    else if ( (other->Invoker.Flags & 0x1F) > 0xA )
    {
      if ( (other->Invoker.Flags & 0x1F) <= 0xF )
      {
        v5 = other->Invoker.value.VS._1;
        if ( v5.VStr )
          v5.VStr->Size = (v5.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (other->Invoker.Flags & 0x1F) <= 0x11 )
      {
        v4.VObj = (Scaleform::GFx::AS3::Object *)other->Invoker.value.VS._2;
        if ( v4.VObj )
          v4.VObj->RefCount = (v4.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 1486
// RVA: 0x789CD0
void __fastcall Scaleform::GFx::AS3::CallFrame::~CallFrame(Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rbx
  __int64 *p_DefXMLNamespace; // rsi
  __int64 v4; // rcx
  int v5; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // [rsp+48h] [rbp+10h] BYREF

  if ( this->pRegisterFile && this->pScopeStack && this->ACopy )
  {
    Scaleform::GFx::AS3::ValueStack::ReleaseReserved(&this->pFile->VMRef->OpStack, this->PrevFirstStackPos);
    Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(
      this->pRegisterFile,
      this->pFile->File.pObject->MethodBodies.Info.Data.Data[this->MBIIndex.Ind]->local_reg_count);
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->pScopeStack->Data,
      this->ScopeStackBaseInd);
    pObject = this->DefXMLNamespace.pObject;
    v11 = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    p_DefXMLNamespace = (__int64 *)&this->pFile->VMRef->DefXMLNamespace;
    if ( &v11 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)p_DefXMLNamespace )
    {
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      v4 = *p_DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        if ( (v4 & 1) != 0 )
        {
          *p_DefXMLNamespace = v4 - 1;
        }
        else
        {
          v5 = *(_DWORD *)(v4 + 32);
          if ( (v5 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)(v4 + 32) = v5 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v4);
          }
        }
      }
      *p_DefXMLNamespace = (__int64)pObject;
    }
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v11 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  if ( (this->Invoker.Flags & 0x1F) > 9 )
  {
    if ( (this->Invoker.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Invoker.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Invoker.Bonus.pWeakProxy = 0i64;
      this->Invoker.value.VS._1.VStr = 0i64;
      this->Invoker.value.VS._2.VObj = 0i64;
      this->Invoker.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->Invoker);
    }
  }
  v9 = this->DefXMLNamespace.pObject;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      this->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v9 - 1);
    }
    else
    {
      v10 = v9->RefCount;
      if ( (v10 & 0x3FFFFF) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
}

// File Line: 1559
// RVA: 0x8203C0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        Scaleform::GFx::AS3::CallFrame *this,
        Scaleform::GFx::AS3::Abc::MethodInfo *mi,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc)
{
  unsigned __int64 v4; // r12
  unsigned int v6; // esi
  unsigned int Flags; // r11d
  char v8; // r10
  int v9; // edi
  int v10; // r10d
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rcx
  Scaleform::GFx::AS3::Value::V2U v12; // rax
  Scaleform::GFx::AS3::Value::V1U v13; // rcx
  Scaleform::GFx::AS3::Value *p_result; // rdx
  unsigned int v15; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Value::V1U v17; // rcx
  Scaleform::GFx::AS3::Value *pRF; // rcx
  unsigned int v19; // edi
  bool v20; // zf
  unsigned int v21; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // r14
  Scaleform::GFx::AS3::VM *VMRef; // r13
  unsigned __int64 v25; // rbx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v26; // rdi
  Scaleform::GFx::AS3::Value::V1U v27; // rcx
  Scaleform::GFx::AS3::Value::V2U v28; // r8
  Scaleform::GFx::AS3::Value *DetailValue; // rax
  bool v30; // bl
  int v31; // edi
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::VM::Error *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::AS3::VM::Error *v36; // rax
  Scaleform::GFx::AS3::VM::Error *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v39; // rsi
  unsigned int v40; // ebx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v44; // r14
  unsigned int v45; // ebx
  unsigned int i; // ebx
  Scaleform::GFx::AS3::Value *v47; // rdx
  int VInt; // eax
  Scaleform::GFx::AS3::Value::V2U v49; // rcx
  unsigned int v50; // ebx
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v52; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v57; // rcx
  unsigned int v58; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+0h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+20h] [rbp-31h] BYREF
  unsigned int v61; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS3::VM::Error v62; // [rsp+48h] [rbp-9h] BYREF
  unsigned __int64 v63; // [rsp+58h] [rbp+7h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+60h] [rbp+Fh]
  __int64 v65; // [rsp+68h] [rbp+17h]
  int v66; // [rsp+B0h] [rbp+5Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v67; // [rsp+B8h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::Value::V2U *v68; // [rsp+C0h] [rbp+6Fh]
  __int64 v69; // [rsp+D0h] [rbp+7Fh]

  v65 = -2i64;
  v4 = argc;
  v6 = 0;
  v61 = 0;
  Flags = _this->Flags;
  v8 = _this->Flags;
  v9 = 1;
  v66 = 1;
  v10 = v8 & 0x1F;
  if ( v10 && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || _this->value.VS._1.VStr) )
  {
    result.Flags = Flags;
    pWeakProxy = _this->Bonus.pWeakProxy;
    result.Bonus.pWeakProxy = pWeakProxy;
    result.value.VS._1.VStr = _this->value.VS._1.VStr;
    v12.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2;
    result.value.VS._2 = v12;
    if ( v10 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        ++pWeakProxy->RefCount;
      }
      else if ( v10 == 10 )
      {
        ++_this->value.VS._1.VStr->RefCount;
      }
      else if ( v10 <= 15 )
      {
        v13 = _this->value.VS._1;
        if ( v13.VStr )
          v13.VStr->Size = (v13.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( v10 <= 17 && v12.VObj )
      {
        v12.VObj->RefCount = (v12.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    p_result = &result;
    v15 = 2;
  }
  else
  {
    pSavedScope = this->pSavedScope;
    if ( pSavedScope->Data.Size )
    {
      v17 = pSavedScope->Data.Data->value.VS._1;
    }
    else
    {
      pRF = this->pRegisterFile->pRF;
      if ( (pRF->Flags & 0x1F) - 12 > 3 )
        v17.VStr = 0i64;
      else
        v17 = pRF->value.VS._1;
    }
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._1 = v17;
    if ( v17.VStr )
      v17.VStr->Size = (v17.VStr->Size + 1) & 0x8FBFFFFF;
    p_result = &other;
    v15 = 1;
  }
  v61 = v15;
  Scaleform::GFx::AS3::Value::Assign(this->pRegisterFile->pRF, p_result);
  if ( (v15 & 2) != 0 )
  {
    v15 &= ~2u;
    v61 = v15;
    v19 = result.Flags;
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.Bonus, 0, 24);
        result.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
    v9 = 1;
  }
  if ( (v15 & 1) != 0 )
  {
    v61 = v15 & 0xFFFFFFFE;
    v21 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags = v21 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  pV = v67.pV;
  pPrev = v67.pV->pPrev;
  v63 = (char *)pPrev - (char *)v67.pV->DynAttrs.mHash.pTable;
  VMRef = this->pFile->VMRef;
  if ( !pPrev )
  {
LABEL_98:
    if ( ((__int64)pV->vfptr & 4) != 0 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v67,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)VMRef->TraitsArray.pObject->ITraits.pObject);
      other.Bonus.pWeakProxy = 0i64;
      other.Flags = 12;
      v39 = v67.pV;
      *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&other.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array>)v67.pV;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v62.Message.pNode;
      Scaleform::GFx::AS3::Value::Assign(&this->pRegisterFile->pRF[v9], &other);
      v40 = other.Flags;
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
        {
          v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&other.Bonus, 0, 24);
          other.Flags = v40 & 0xFFFFFDE0;
        }
        else
        {
          switch ( other.Flags & 0x1F )
          {
            case 0xA:
              VStr = other.value.VS._1.VStr;
              v20 = other.value.VS._1.VStr->RefCount-- == 1;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              if ( !other.value.VS._1.VBool )
              {
                VObj = other.value.VS._1.VObj;
                goto LABEL_113;
              }
              --other.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
              {
                --other.value.VS._2.VObj;
              }
              else
              {
                VObj = other.value.VS._2.VObj;
LABEL_113:
                if ( VObj )
                {
                  RefCount = VObj->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    VObj->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( v4 > (unsigned __int64)pPrev )
        Scaleform::GFx::AS3::Impl::SparseArray::Append(
          &v39->SA,
          v4 - (_DWORD)pPrev,
          (Scaleform::GFx::AS3::Value *)(v69 + 32i64 * (_QWORD)pPrev));
    }
    else if ( ((__int64)pV->vfptr & 1) != 0 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v67,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)VMRef->TraitsArray.pObject->ITraits.pObject);
      result.Bonus.pWeakProxy = 0i64;
      result.Flags = 12;
      v44 = v67.pV;
      *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&result.value.VNumber = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array>)v67.pV;
      result.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v62.Message.pNode;
      Scaleform::GFx::AS3::Value::Assign(&this->pRegisterFile->pRF[v9], &result);
      v45 = result.Flags;
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.Bonus, 0, 24);
          result.Flags = v45 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      for ( i = 0; i < (unsigned int)v4; ++i )
      {
        if ( i >= v9 - 1 )
          v47 = (Scaleform::GFx::AS3::Value *)(v69 + 32i64 * i);
        else
          v47 = &this->pRegisterFile->pRF[i + 1];
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v44->SA, v47);
      }
      result.Flags = 0;
      result.Bonus.pWeakProxy = 0i64;
      if ( (this->Invoker.Flags & 0x1F) == 7 )
      {
        VInt = this->Invoker.value.VS._1.VInt;
        v49.VObj = v68[2].VObj;
        other.Flags = 17;
        other.Bonus.pWeakProxy = 0i64;
        other.value.VS._2 = v49;
        other.value.VS._1.VInt = VInt;
        if ( v49.VObj )
          v49.VObj->RefCount = (v49.VObj->RefCount + 1) & 0x8FBFFFFF;
        other.Flags = 17;
        Scaleform::GFx::AS3::Value::Assign(&result, &other);
        v50 = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v20 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags = v50 & 0xFFFFFDE0;
          }
          else
          {
            switch ( other.Flags & 0x1F )
            {
              case 0xA:
                v51 = other.value.VS._1.VStr;
                v20 = other.value.VS._1.VStr->RefCount-- == 1;
                if ( v20 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v51);
                break;
              case 0xB:
              case 0xC:
              case 0xD:
              case 0xE:
              case 0xF:
                if ( !other.value.VS._1.VBool )
                {
                  v52 = other.value.VS._1.VObj;
                  goto LABEL_148;
                }
                --other.value.VS._1.VStr;
                break;
              case 0x10:
              case 0x11:
                if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
                {
                  --other.value.VS._2.VObj;
                }
                else
                {
                  v52 = other.value.VS._2.VObj;
LABEL_148:
                  if ( v52 )
                  {
                    v53 = v52->RefCount;
                    if ( (v53 & 0x3FFFFF) != 0 )
                    {
                      v52->RefCount = v53 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v52);
                    }
                  }
                }
                break;
              default:
                break;
            }
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::Value::Assign(&result, &this->Invoker);
      }
      ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                      VMRef->StringManagerRef,
                      (Scaleform::GFx::ASString *)&v67,
                      "callee");
      LODWORD(v63) = 0;
      pNode = ConstString->pNode;
      ++pNode->RefCount;
      *(_QWORD *)&v62.ID = &v63;
      v62.Message.pNode = (Scaleform::GFx::ASStringNode *)&result;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        &v44->DynAttrs.mHash,
        &v44->DynAttrs,
        (Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *)&v62);
      v55 = pNode;
      v20 = pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v55);
      v56 = (Scaleform::GFx::ASStringNode *)v67.pV;
      v20 = LODWORD(v67.pV->pPrev)-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v56);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.Bonus, 0, 24);
          result.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( result.Flags & 0x1F )
          {
            case 0xA:
              v38 = result.value.VS._1.VStr;
              v20 = result.value.VS._1.VStr->RefCount-- == 1;
              if ( v20 )
                goto LABEL_97;
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              v57 = result.value.VS._1.VObj;
              if ( !result.value.VS._1.VBool )
                goto LABEL_167;
              --result.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              v57 = result.value.VS._2.VObj;
              if ( ((__int64)result.value.VS._2.VObj & 1) != 0 )
              {
                --result.value.VS._2.VObj;
              }
              else
              {
LABEL_167:
                if ( v57 )
                {
                  v58 = v57->RefCount;
                  if ( (v58 & 0x3FFFFF) != 0 )
                  {
                    v57->RefCount = v58 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v57);
                  }
                }
              }
              break;
            default:
              return;
          }
        }
      }
    }
    return;
  }
  v25 = 0i64;
  while ( 1 )
  {
    v26 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
            VMRef,
            this->pFile,
            &this->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*((unsigned int *)&pV->pNext->Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::Scaleform::GFx::AS3::GASRefCountBase::Scaleform::GFx::AS3::RefCountBaseGC<328>::$CBB44125B27995AEB5908B7872D4CF4F::vfptr
                                                                             + v25)]);
    if ( !v26 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v62, 1014, VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v37, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v38 = v62.Message.pNode;
      v20 = v62.Message.pNode->RefCount-- == 1;
      if ( v20 )
LABEL_97:
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      return;
    }
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    other.Flags = v.Flags;
    other.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v28.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
    v27 = v.value.VS._1;
    other.value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
      }
      else if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          if ( v.value.VS._1.VStr )
          {
            ++v.value.VS._1.VStr->Size;
            v27.VStr->Size &= 0x8FBFFFFF;
          }
        }
        else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
        {
          ++v.value.VS._2.VObj->RefCount;
          v28.VObj->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    if ( v6 < (unsigned int)v4 )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, unsigned __int64, Scaleform::GFx::AS3::Value *))v26->vfptr[3].Finalize_GC)(
             v26,
             v69 + 32 * v25,
             &other) )
      {
        goto LABEL_71;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v62, 1034, VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v32, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_80:
      v33 = v62.Message.pNode;
      v20 = v62.Message.pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
        {
          v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_86:
          memset(&other.Bonus, 0, 24);
          other.Flags &= 0xFFFFFDE0;
          return;
        }
LABEL_95:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        return;
      }
      return;
    }
    if ( ((__int64)v67.pV->vfptr & 8) != 0 && v25 >= v63 )
      break;
    if ( v26 != VMRef->TraitsClassClass.pObject )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v62, 1063, VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v36, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      goto LABEL_80;
    }
LABEL_71:
    v31 = v66;
    Scaleform::GFx::AS3::Value::Assign(&this->pRegisterFile->pRF[v66], &other);
    v9 = v31 + 1;
    v66 = v9;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    v25 = ++v6;
    pV = v67.pV;
    if ( v6 >= (unsigned __int64)pPrev )
      goto LABEL_98;
  }
  DetailValue = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
                  this->pFile,
                  &result,
                  (Scaleform::GFx::AS3::Abc::ValueDetail *)&v67.pV->pTraits.pObject->vfptr + v25 - v63);
  v30 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v26->vfptr[3].Finalize_GC)(
          v26,
          DetailValue,
          &other) == 0;
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  if ( !v30 )
    goto LABEL_71;
  Scaleform::GFx::AS3::VM::Error::Error(&v62, 1034, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v34, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v35 = v62.Message.pNode;
  v20 = v62.Message.pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_86;
    }
    goto LABEL_95;
  }
}

// File Line: 1702
// RVA: 0x7B4CB0
void __fastcall Scaleform::GFx::AS3::CallFrame::ClearOpStack(Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::GFx::AS3::VM *VMRef; // rdx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rax

  VMRef = this->pFile->VMRef;
  p_OpStack = &VMRef->OpStack;
  if ( this->DiscardResult || VMRef->HandleException )
    Scaleform::GFx::AS3::ValueStack::PopReserved(p_OpStack, this->PrevInitialStackPos, 0);
  else
    Scaleform::GFx::AS3::ValueStack::PopReserved(p_OpStack, this->PrevInitialStackPos, 1);
}

// File Line: 1764
// RVA: 0x7EA070
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::CallFrame::GetGlobalObject(
        Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Value *Data; // rax

  pSavedScope = this->pSavedScope;
  if ( pSavedScope->Data.Size )
  {
    Data = pSavedScope->Data.Data;
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)Data->value.VS._1.VStr;
  }
  Data = this->pRegisterFile->pRF;
  if ( (Data->Flags & 0x1F) - 12 <= 3 )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)Data->value.VS._1.VStr;
  return 0i64;
}

// File Line: 1792
// RVA: 0x784B30
void __fastcall Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::VMAppDomain *parentDomain)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::MemoryHeap *MHeap; // rcx

  GC = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable;
  this->ParentDomain = 0i64;
  MHeap = vm->MHeap;
  this->ClassTraitsSet.Entries.mHash.pTable = 0i64;
  this->ClassTraitsSet.Entries.mHash.pHeap = MHeap;
  this->ChildDomains.Data.Data = 0i64;
  this->ChildDomains.Data.Size = 0i64;
  this->ChildDomains.Data.Policy.Capacity = 0i64;
  if ( parentDomain )
    Scaleform::GFx::AS3::VMAppDomain::AddChild(parentDomain, this);
}

// File Line: 1798
// RVA: 0x78F960
void __fastcall Scaleform::GFx::AS3::VMAppDomain::~VMAppDomain(Scaleform::GFx::AS3::VMAppDomain *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ChildDomains);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&this->ClassTraitsSet);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&this->ClassTraitsSet);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 1802
// RVA: 0x7AB6C0
void __fastcall Scaleform::GFx::AS3::VMAppDomain::AddChild(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::VMAppDomain *childDomain)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v4; // rdx
  unsigned int RefCount; // eax

  if ( childDomain )
    childDomain->RefCount = (childDomain->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ChildDomains.Data,
    &this->ChildDomains,
    this->ChildDomains.Data.Size + 1);
  v4 = &this->ChildDomains.Data.Data[this->ChildDomains.Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = childDomain;
    if ( childDomain )
      childDomain->RefCount = (childDomain->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( childDomain )
  {
    if ( ((unsigned __int8)childDomain & 1) == 0 )
    {
      RefCount = childDomain->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        childDomain->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(childDomain);
      }
    }
  }
  childDomain->ParentDomain = this;
}

// File Line: 1808
// RVA: 0x7AE040
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *__fastcall Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VMAppDomain *v6; // rsi
  Scaleform::GFx::AS3::VMAppDomain *v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *v8; // rax

  v6 = 0i64;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    v7 = (Scaleform::GFx::AS3::VMAppDomain *)vm->MHeap->vfptr->Alloc(this, 88i64, 0i64);
    if ( v7 )
    {
      Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(v7, vm, this);
      v6 = v8;
    }
    result->pObject = v6;
    return result;
  }
  else
  {
    result->pObject = this;
    if ( this )
      this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    return result;
  }
}

// File Line: 1821
// RVA: 0x811630
char __fastcall Scaleform::GFx::AS3::VMAppDomain::RemoveChild(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::VMAppDomain *childDomain)
{
  __int64 v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *Data; // rax
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  unsigned int RefCount; // eax

  v2 = 0i64;
  if ( !this->ChildDomains.Data.Size )
    return 0;
  while ( 1 )
  {
    Data = this->ChildDomains.Data.Data;
    pObject = Data[v2].pObject;
    if ( pObject == childDomain )
      break;
    if ( Scaleform::GFx::AS3::VMAppDomain::RemoveChild(pObject, childDomain) )
      return 1;
    if ( ++v2 >= this->ChildDomains.Data.Size )
      return 0;
  }
  if ( this->ChildDomains.Data.Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ChildDomains.Data,
      &this->ChildDomains,
      0i64);
    return 1;
  }
  v8 = Data[v2].pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      Data[v2].pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v8 - 1);
    }
    else
    {
      RefCount = v8->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v8->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  memmove(
    &this->ChildDomains.Data.Data[v2],
    &this->ChildDomains.Data.Data[v2 + 1],
    8 * (this->ChildDomains.Data.Size - v2) - 8);
  --this->ChildDomains.Data.Size;
  return 1;
}

// File Line: 1838
// RVA: 0x7E6E90
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  ParentDomain = this->ParentDomain;
  if ( !ParentDomain )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             name,
             ns);
  result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns);
  if ( !result )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             name,
             ns);
  return result;
}

// File Line: 1857
// RVA: 0x7E6EE0
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  ParentDomain = this->ParentDomain;
  if ( !ParentDomain )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             mn);
  result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, mn);
  if ( !result )
    return Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &this->ClassTraitsSet,
             mn);
  return result;
}

// File Line: 1871
// RVA: 0x7AB900
void __fastcall Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::ClassTraits::Traits *val)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *vala; // [rsp+48h] [rbp+20h] BYREF

  vala = val;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &this->ClassTraitsSet,
    name,
    ns,
    &vala);
}

// File Line: 1909
// RVA: 0x7D6AE0
void __fastcall Scaleform::GFx::AS3::VMAppDomain::ForEachChild_GC(
        Scaleform::GFx::AS3::VMAppDomain *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rcx

  for ( i = 0i64; i < this->ChildDomains.Data.Size; ++i )
  {
    pObject = this->ChildDomains.Data.Data[i].pObject;
    pObject->vfptr->ForEachChild_GC(pObject, prcc, op);
  }
}

// File Line: 1976
// RVA: 0x783E90
void __fastcall Scaleform::GFx::AS3::VM::VM(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::FlashUI *_ui,
        Scaleform::GFx::AS3::StringManager *sm,
        Scaleform::GFx::AS3::ASRefCountCollector *gc)
{
  Scaleform::MemoryHeap *v5; // rax
  Scaleform::GFx::AS3::XMLSupport *v6; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // rcx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v8; // rax
  Scaleform::MemoryHeap *MHeap; // rcx
  Scaleform::MemoryHeap *v10; // rax
  __int64 v11; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rax
  Scaleform::MemoryHeap *v13; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v14; // rdx
  Scaleform::GFx::AS3::ASRefCountCollector *v15; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v16; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v17; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *pV; // rbx
  char v19; // r14
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // rdx
  unsigned int RefCount; // eax
  unsigned int v23; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // rax
  __int64 v25; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v27; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v28; // rax
  __int64 v29; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v30; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v31; // rax
  __int64 v32; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v33; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v34; // rax
  __int64 v35; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v36; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v37; // rax
  __int64 v38; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v39; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v40; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v41; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v42; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v44; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v45; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v46; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v47; // rax
  Scaleform::GFx::AS3::ClassTraits::Function *v48; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v49; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v50; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v51; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v52; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v53; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v54; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v55; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v56; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v57; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::String *v58; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v59; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Array *v60; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v61; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::QName *v62; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v63; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Catch *v64; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v65; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v66; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v67; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *v68; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v69; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *v70; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v71; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *v72; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v73; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *v74; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v75; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *v76; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v77; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Domain *v78; // rbx
  __int64 v79; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Anonimous *v80; // rax
  __int64 v81; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v82; // rax
  Scaleform::GFx::AS3::InstanceTraits::Void *v83; // rax
  __int64 v84; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v85; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v86; // rax
  __int64 v87; // rcx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v88; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v89; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v90; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v91; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v92; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v93; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v94; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *v95; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v96; // rbx
  Scaleform::GFx::AS3::Class *v97; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Function *v98; // r14
  Scaleform::GFx::AS3::Class *v99; // rcx
  unsigned int v100; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v101; // r14
  unsigned __int64 v102; // rbx
  unsigned __int64 v103; // r8
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v104; // rcx
  Scaleform::GFx::AS3::Classes::ClassClass **v105; // rbx
  Scaleform::GFx::AS3::Value::V2U v106; // [rsp+30h] [rbp-89h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // [rsp+C0h] [rbp+7h]
  __int64 v109; // [rsp+C8h] [rbp+Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> result; // [rsp+128h] [rbp+6Fh] BYREF
  void *p_GlobalObjects; // [rsp+130h] [rbp+77h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329,Scaleform::ArrayDefaultPolicy> *p_ChildDomains; // [rsp+138h] [rbp+7Fh]

  v109 = -2i64;
  this->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::VM::`vftable;
  *(_WORD *)&this->Initialized = 0;
  this->LoadingAbcFile = 0;
  this->StringManagerRef = sm;
  this->GC.GC = gc;
  this->UI = _ui;
  this->InInitializer = 0;
  v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->MHeap = v5;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v5;
  v6 = (Scaleform::GFx::AS3::XMLSupport *)v5->vfptr->Alloc(v5, 48ui64, 0i64);
  p_GlobalObjects = v6;
  if ( v6 )
  {
    v7 = this->GC.GC;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    v6->RefCount = 1;
    v6->pRCCRaw = (unsigned __int64)v7;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable;
    v6->Enabled = 0;
  }
  else
  {
    v6 = 0i64;
  }
  this->XMLSupport_.pObject = v6;
  Scaleform::GFx::AS3::ValueStack::ValueStack(&this->OpStack);
  this->RegisterFile.ReservedNum = 0;
  this->RegisterFile.pRF = 0i64;
  *(_DWORD *)&this->RegisterFile.MaxReservedPageSize = 0;
  this->RegisterFile.pCurrentPage = 0i64;
  this->RegisterFile.pReserved = 0i64;
  v8 = Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(&this->RegisterFile, 0);
  this->RegisterFile.pCurrentPage = v8;
  v8->pNext = 0i64;
  this->RegisterFile.pCurrentPage->pPrev = 0i64;
  this->RegisterFile.pRF = this->RegisterFile.pCurrentPage->Values;
  MHeap = this->MHeap;
  this->ScopeStack.Data.Data = 0i64;
  this->ScopeStack.Data.Size = 0i64;
  this->ScopeStack.Data.Policy.Capacity = 0i64;
  this->ScopeStack.Data.pHeap = MHeap;
  this->HandleException = 0;
  this->ExceptionObj.Flags = 0;
  this->ExceptionObj.Bonus.pWeakProxy = 0i64;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->GlobalObjects;
  p_GlobalObjects = &this->GlobalObjects;
  this->GlobalObjects.Data.Data = 0i64;
  this->GlobalObjects.Data.Size = 0i64;
  this->GlobalObjects.Data.Policy.Capacity = 0i64;
  v10 = this->MHeap;
  *(_WORD *)&other.DiscardResult = 0;
  memset(&other.ScopeStackBaseInd, 0, 24);
  other.pHeap = v10;
  other.pFile = 0i64;
  other.MBIIndex.Ind = 0;
  memset(&other.pSavedScope, 0, 52);
  other.Invoker.Bonus.pWeakProxy = 0i64;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->CallStack;
  this->CallStack.Size = 0i64;
  this->CallStack.NumPages = 0i64;
  this->CallStack.MaxPages = 0i64;
  this->CallStack.Pages = 0i64;
  Scaleform::GFx::AS3::CallFrame::CallFrame(&this->CallStack.DefaultValue, &other);
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v12 = (Scaleform::GFx::AS3::VMAppDomain *)((__int64 (__fastcall *)(__int64, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                              v11,
                                              88i64);
  v14 = v12;
  p_GlobalObjects = v12;
  if ( v12 )
  {
    v15 = this->GC.GC;
    v12->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    v12->RefCount = 1;
    v12->pRCCRaw = (unsigned __int64)v15;
    v12->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    v12->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable;
    v12->ParentDomain = 0i64;
    v13 = this->MHeap;
    p_ClassTraitsSet = &v12->ClassTraitsSet;
    v12->ClassTraitsSet.Entries.mHash.pTable = 0i64;
    v12->ClassTraitsSet.Entries.mHash.pHeap = v13;
    p_ChildDomains = &v12->ChildDomains;
    v12->ChildDomains.Data.Data = 0i64;
    v12->ChildDomains.Data.Size = 0i64;
    v12->ChildDomains.Data.Policy.Capacity = 0i64;
  }
  else
  {
    v14 = 0i64;
  }
  this->SystemDomain.pObject = v14;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
    v16 = (Scaleform::GFx::AS3::VMAppDomain *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                v13,
                                                88i64);
    p_GlobalObjects = v16;
    if ( v16 )
    {
      Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(v16, this, this->SystemDomain.pObject);
      pV = v17;
    }
    else
    {
      pV = 0i64;
    }
    result.pV = pV;
    v19 = 1;
    pObject = (Scaleform::GFx::AS3::VMAppDomain *)pV;
  }
  else
  {
    pObject = this->SystemDomain.pObject;
    result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    v19 = 2;
    pV = result.pV;
  }
  v21 = result.pV;
  this->CurrentDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)result.pV;
  if ( v21 )
    v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
  if ( (v19 & 2) != 0 )
  {
    v19 &= ~2u;
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)pObject - 1);
        result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject;
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  if ( (v19 & 1) != 0 && pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)pV - 1);
    }
    else
    {
      v23 = pV->RefCount;
      if ( (v23 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v24 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMAppDomain *, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           pObject,
                                                           104i64);
  v26 = v24;
  p_GlobalObjects = v24;
  if ( v24 )
  {
    v27 = this->GC.GC;
    v24->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    v24->RefCount = 1;
    v24->pRCCRaw = (unsigned __int64)v27;
    v24->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    v24->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
    *((_QWORD *)v24 + 5) &= 0xFFFFFFFFFFFFFFE0ui64;
    v24->VMRef = this;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      this->StringManagerRef,
      &v24->Uri,
      &customCaption);
    v26->pFactory.pObject = 0i64;
    v26->Prefix.Flags = 0;
    v26->Prefix.Bonus.pWeakProxy = 0i64;
  }
  else
  {
    v26 = 0i64;
  }
  this->PublicNamespace.pObject = v26;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v28 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v25,
                                                           104i64);
  p_GlobalObjects = v28;
  if ( v28 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v28, this, NS_Public, Scaleform::GFx::AS3::NS_AS3);
  else
    v30 = 0i64;
  this->AS3Namespace.pObject = v30;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v31 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v29,
                                                           104i64);
  p_GlobalObjects = v31;
  if ( v31 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v31, this, NS_Public, Scaleform::GFx::AS3::NS_Vector);
  else
    v33 = 0i64;
  this->VectorNamespace.pObject = v33;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v34 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v32,
                                                           104i64);
  p_GlobalObjects = v34;
  if ( v34 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v34, this, NS_Public, Scaleform::GFx::AS3::NS_flash_proxy);
  else
    v36 = 0i64;
  this->ProxyNamespace.pObject = v36;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v37 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v35,
                                                           104i64);
  p_GlobalObjects = v37;
  if ( v37 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v37, this, NS_Public, Scaleform::GFx::AS3::NS_XML);
  else
    v39 = 0i64;
  this->XMLNamespace.pObject = v39;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v40 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                          v38,
                                                          208i64,
                                                          0i64);
  p_GlobalObjects = v40;
  if ( v40 )
  {
    Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(v40, this);
    v42 = v41;
  }
  else
  {
    v42 = 0i64;
  }
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v42, this->SystemDomain.pObject);
  this->TraitsClassClass.pObject = v42;
  ClassTraits = Scaleform::GFx::AS3::ClassTraits::fl::Object::MakeClassTraits(&result, this);
  v44 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)ClassTraits->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, ClassTraits->pV, this->SystemDomain.pObject);
  this->TraitsObject.pObject = v44;
  v45 = Scaleform::GFx::AS3::ClassTraits::fl::Namespace::MakeClassTraits(&result, this);
  v46 = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)v45->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v45->pV, this->SystemDomain.pObject);
  this->TraitsNamespace.pObject = v46;
  v47 = Scaleform::GFx::AS3::ClassTraits::Function::MakeClassTraits(&result, this);
  v48 = (Scaleform::GFx::AS3::ClassTraits::Function *)v47->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v47->pV, this->SystemDomain.pObject);
  this->TraitsFunction.pObject = v48;
  v49 = Scaleform::GFx::AS3::ClassTraits::fl::Boolean::MakeClassTraits(&result, this);
  v50 = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)v49->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v49->pV, this->SystemDomain.pObject);
  this->TraitsBoolean.pObject = v50;
  v51 = Scaleform::GFx::AS3::ClassTraits::fl::Number::MakeClassTraits(&result, this);
  v52 = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)v51->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v51->pV, this->SystemDomain.pObject);
  this->TraitsNumber.pObject = v52;
  v53 = Scaleform::GFx::AS3::ClassTraits::fl::int_::MakeClassTraits(&result, this);
  v54 = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)v53->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v53->pV, this->SystemDomain.pObject);
  this->TraitsInt.pObject = v54;
  v55 = Scaleform::GFx::AS3::ClassTraits::fl::uint::MakeClassTraits(&result, this);
  v56 = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)v55->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v55->pV, this->SystemDomain.pObject);
  this->TraitsUint.pObject = v56;
  v57 = Scaleform::GFx::AS3::ClassTraits::fl::String::MakeClassTraits(&result, this);
  v58 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)v57->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v57->pV, this->SystemDomain.pObject);
  this->TraitsString.pObject = v58;
  v59 = Scaleform::GFx::AS3::ClassTraits::fl::Array::MakeClassTraits(&result, this);
  v60 = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)v59->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v59->pV, this->SystemDomain.pObject);
  this->TraitsArray.pObject = v60;
  v61 = Scaleform::GFx::AS3::ClassTraits::fl::QName::MakeClassTraits(&result, this);
  v62 = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)v61->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v61->pV, this->SystemDomain.pObject);
  this->TraitsQName.pObject = v62;
  v63 = Scaleform::GFx::AS3::ClassTraits::fl::Catch::MakeClassTraits(&result, this);
  v64 = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)v63->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v63->pV, this->SystemDomain.pObject);
  this->TraitsCatch.pObject = v64;
  v65 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::MakeClassTraits(&result, this);
  v66 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)v65->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v65->pV, this->SystemDomain.pObject);
  this->TraitsVector.pObject = v66;
  v67 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int::MakeClassTraits(&result, this);
  v68 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v67->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v67->pV, this->SystemDomain.pObject);
  this->TraitsVector_int.pObject = v68;
  v69 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint::MakeClassTraits(&result, this);
  v70 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)v69->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v69->pV, this->SystemDomain.pObject);
  this->TraitsVector_uint.pObject = v70;
  v71 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::MakeClassTraits(&result, this);
  v72 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)v71->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v71->pV, this->SystemDomain.pObject);
  this->TraitsVector_Number.pObject = v72;
  v73 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::MakeClassTraits(&result, this);
  v74 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)v73->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v73->pV, this->SystemDomain.pObject);
  this->TraitsVector_String.pObject = v74;
  v75 = Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::MakeClassTraits(&result, this);
  v76 = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)v75->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v75->pV, this->SystemDomain.pObject);
  this->TraitsApplicationDomain.pObject = v76;
  v77 = Scaleform::GFx::AS3::ClassTraits::fl::Domain::MakeClassTraits(&result, this);
  v78 = (Scaleform::GFx::AS3::ClassTraits::fl::Domain *)v77->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v77->pV, this->SystemDomain.pObject);
  this->TraitsDomain.pObject = v78;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v80 = (Scaleform::GFx::AS3::InstanceTraits::Anonimous *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                            v79,
                                                            240i64,
                                                            0i64);
  p_GlobalObjects = v80;
  if ( v80 )
    Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(v80, this);
  else
    v82 = 0i64;
  this->TraitsNull.pObject = v82;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v83 = (Scaleform::GFx::AS3::InstanceTraits::Void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                       v81,
                                                       240i64,
                                                       0i64);
  p_GlobalObjects = v83;
  if ( v83 )
    Scaleform::GFx::AS3::InstanceTraits::Void::Void(v83, this);
  else
    v85 = 0i64;
  this->TraitsVoid.pObject = v85;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v86 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                          v84,
                                                          264i64,
                                                          0i64);
  v88 = v86;
  p_GlobalObjects = v86;
  if ( v86 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v86, this, &Scaleform::GFx::AS3::fl::FunctionCICpp);
    v88->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable;
    LODWORD(v88[1].vfptr) = 0;
    v88[1].pRCCRaw = 0i64;
    v88[1].pNext = 0i64;
    v88->TraitsType = Traits_Function;
    Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots((Scaleform::GFx::AS3::InstanceTraits::Function *)v88);
  }
  else
  {
    v88 = 0i64;
  }
  this->NoFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Function *)v88;
  this->DefXMLNamespace.pObject = 0i64;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap;
  v89 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                                   v87,
                                                                   240i64,
                                                                   0i64);
  p_GlobalObjects = v89;
  if ( v89 )
    Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v89, this);
  else
    v90 = 0i64;
  this->TraitaGlobalObject.pObject = v90;
  v91 = (Scaleform::GFx::AS3::ClassTraits::Traits *)this->MHeap->vfptr->Alloc(this->MHeap, 216i64, 0i64);
  result.pV = v91;
  p_GlobalObjects = v91;
  if ( v91 )
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GlobalObjectCPP(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v91,
      this,
      this->TraitaGlobalObject.pObject);
  else
    v92 = 0i64;
  this->GlobalObject.pObject = v92;
  this->GlobalObjectValue.Flags = 0;
  this->GlobalObjectValue.Bonus.pWeakProxy = 0i64;
  v93 = this->GlobalObject.pObject;
  this->GlobalObjectValue.Flags = this->GlobalObjectValue.Flags & 0xFFFFFFE0 | 0xC;
  this->GlobalObjectValue.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v93;
  this->GlobalObjectValue.value.VS._2 = v106;
  if ( v93 )
    v93->RefCount = (v93->RefCount + 1) & 0x8FBFFFFF;
  v94 = Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray::MakeClassTraits(&result, this);
  v95 = (Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *)v94->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(this, v94->pV, this->SystemDomain.pObject);
  this->TraitsByteArray.pObject = v95;
  this->AliasClass.mHash.pTable = 0i64;
  this->ClassAlias.mHash.pTable = 0i64;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->VMAbcFilesWeak;
  p_GlobalObjects = &this->VMAbcFilesWeak;
  this->VMAbcFilesWeak.Data.Data = 0i64;
  this->VMAbcFilesWeak.Data.Size = 0i64;
  this->VMAbcFilesWeak.Data.Policy.Capacity = 0i64;
  Scaleform::GFx::AS3::VM::EnableXMLSupport(this);
  v96 = this->TraitsFunction.pObject->ITraits.pObject;
  if ( !v96->pConstructor.pObject )
    v96->vfptr[3].~RefCountBaseGC<328>(v96);
  v97 = v96->pConstructor.pObject;
  if ( v97 )
    v97->RefCount = (v97->RefCount + 1) & 0x8FBFFFFF;
  v98 = this->NoFunctionTraits.pObject;
  v99 = v98->pConstructor.pObject;
  if ( v97 != v99 )
  {
    if ( v99 )
    {
      if ( ((unsigned __int8)v99 & 1) != 0 )
      {
        v98->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v99 - 1);
      }
      else
      {
        v100 = v99->RefCount;
        if ( (v100 & 0x3FFFFF) != 0 )
        {
          v99->RefCount = v100 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v99);
        }
      }
    }
    v98->pConstructor.pObject = v97;
  }
  this->Initialized = 1;
  v101 = this->GlobalObject.pObject;
  v102 = this->GlobalObjects.Data.Size + 1;
  if ( v102 >= this->GlobalObjects.Data.Size )
  {
    if ( v102 <= this->GlobalObjects.Data.Policy.Capacity )
      goto LABEL_81;
    v103 = v102 + (v102 >> 2);
  }
  else
  {
    if ( v102 >= this->GlobalObjects.Data.Policy.Capacity >> 1 )
      goto LABEL_81;
    v103 = this->GlobalObjects.Data.Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
    &this->GlobalObjects,
    v103);
LABEL_81:
  this->GlobalObjects.Data.Size = v102;
  v104 = &this->GlobalObjects.Data.Data[v102 - 1];
  if ( v104 )
    *v104 = v101;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->TraitsClassClass.pObject->pParent,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->TraitsObject.pObject);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsClassClass.pObject);
  v105 = (Scaleform::GFx::AS3::Classes::ClassClass **)this->TraitsClassClass.pObject->ITraits.pObject;
  if ( !v105[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::ClassClass **))(*v105)[1]._pRCC)(v105);
  Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(v105[17]);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsObject.pObject);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsNamespace.pObject);
}

// File Line: 2061
// RVA: 0x78ED90
void __fastcall Scaleform::GFx::AS3::VM::~VM(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v5; // zf
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Domain *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Catch *v32; // rcx
  unsigned int v33; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::QName *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Array *v36; // rcx
  unsigned int v37; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::String *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v40; // rcx
  unsigned int v41; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v42; // rcx
  unsigned int v43; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v44; // rcx
  unsigned int v45; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v46; // rcx
  unsigned int v47; // eax
  Scaleform::GFx::AS3::ClassTraits::Function *v48; // rcx
  unsigned int v49; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v50; // rcx
  unsigned int v51; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v52; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v54; // rcx
  unsigned int v55; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v56; // rcx
  unsigned int v57; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v58; // rcx
  unsigned int v59; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v60; // rcx
  unsigned int v61; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v62; // rcx
  unsigned int v63; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v64; // rcx
  unsigned int v65; // eax
  Scaleform::GFx::AS3::VMAppDomain *v66; // rcx
  unsigned int v67; // eax
  Scaleform::GFx::AS3::VMAppDomain *v68; // rcx
  unsigned int v69; // eax
  Scaleform::GFx::AS3::WeakProxy *v70; // rdx
  Scaleform::GFx::AS3::XMLSupport *v71; // rcx
  unsigned int v72; // eax

  this->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::VM::`vftable;
  this->InDestructor = 1;
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(this);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->VMAbcFilesWeak.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::Clear(&this->ClassAlias.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->AliasClass);
  pObject = this->TraitsByteArray.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->TraitsByteArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (this->GlobalObjectValue.Flags & 0x1F) > 9 )
  {
    if ( (this->GlobalObjectValue.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->GlobalObjectValue.Bonus.pWeakProxy;
      v5 = pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->GlobalObjectValue.Bonus.pWeakProxy = 0i64;
      this->GlobalObjectValue.value.VS._1.VStr = 0i64;
      this->GlobalObjectValue.value.VS._2.VObj = 0i64;
      this->GlobalObjectValue.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->GlobalObjectValue);
    }
  }
  v6 = this->GlobalObject.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->GlobalObject.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  v8 = this->TraitaGlobalObject.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->TraitaGlobalObject.pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  v10 = this->DefXMLNamespace.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      this->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
  }
  v12 = this->NoFunctionTraits.pObject;
  if ( v12 )
  {
    if ( ((unsigned __int8)v12 & 1) != 0 )
    {
      this->NoFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Function *)((char *)v12 - 1);
    }
    else
    {
      v13 = v12->RefCount;
      if ( (v13 & 0x3FFFFF) != 0 )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
  v14 = this->TraitsVoid.pObject;
  if ( v14 )
  {
    if ( ((unsigned __int8)v14 & 1) != 0 )
    {
      this->TraitsVoid.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v14 - 1);
    }
    else
    {
      v15 = v14->RefCount;
      if ( (v15 & 0x3FFFFF) != 0 )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
  }
  v16 = this->TraitsNull.pObject;
  if ( v16 )
  {
    if ( ((unsigned __int8)v16 & 1) != 0 )
    {
      this->TraitsNull.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v16 - 1);
    }
    else
    {
      v17 = v16->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        v16->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
  v18 = this->TraitsDomain.pObject;
  if ( v18 )
  {
    if ( ((unsigned __int8)v18 & 1) != 0 )
    {
      this->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Domain *)((char *)v18 - 1);
    }
    else
    {
      v19 = v18->RefCount;
      if ( (v19 & 0x3FFFFF) != 0 )
      {
        v18->RefCount = v19 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
      }
    }
  }
  v20 = this->TraitsApplicationDomain.pObject;
  if ( v20 )
  {
    if ( ((unsigned __int8)v20 & 1) != 0 )
    {
      this->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)((char *)v20 - 1);
    }
    else
    {
      v21 = v20->RefCount;
      if ( (v21 & 0x3FFFFF) != 0 )
      {
        v20->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
  v22 = this->TraitsVector_String.pObject;
  if ( v22 )
  {
    if ( ((unsigned __int8)v22 & 1) != 0 )
    {
      this->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)((char *)v22 - 1);
    }
    else
    {
      v23 = v22->RefCount;
      if ( (v23 & 0x3FFFFF) != 0 )
      {
        v22->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
      }
    }
  }
  v24 = this->TraitsVector_Number.pObject;
  if ( v24 )
  {
    if ( ((unsigned __int8)v24 & 1) != 0 )
    {
      this->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)((char *)v24 - 1);
    }
    else
    {
      v25 = v24->RefCount;
      if ( (v25 & 0x3FFFFF) != 0 )
      {
        v24->RefCount = v25 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
      }
    }
  }
  v26 = this->TraitsVector_uint.pObject;
  if ( v26 )
  {
    if ( ((unsigned __int8)v26 & 1) != 0 )
    {
      this->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)((char *)v26 - 1);
    }
    else
    {
      v27 = v26->RefCount;
      if ( (v27 & 0x3FFFFF) != 0 )
      {
        v26->RefCount = v27 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
      }
    }
  }
  v28 = this->TraitsVector_int.pObject;
  if ( v28 )
  {
    if ( ((unsigned __int8)v28 & 1) != 0 )
    {
      this->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)((char *)v28 - 1);
    }
    else
    {
      v29 = v28->RefCount;
      if ( (v29 & 0x3FFFFF) != 0 )
      {
        v28->RefCount = v29 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
      }
    }
  }
  v30 = this->TraitsVector.pObject;
  if ( v30 )
  {
    if ( ((unsigned __int8)v30 & 1) != 0 )
    {
      this->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)((char *)v30 - 1);
    }
    else
    {
      v31 = v30->RefCount;
      if ( (v31 & 0x3FFFFF) != 0 )
      {
        v30->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
  v32 = this->TraitsCatch.pObject;
  if ( v32 )
  {
    if ( ((unsigned __int8)v32 & 1) != 0 )
    {
      this->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)((char *)v32 - 1);
    }
    else
    {
      v33 = v32->RefCount;
      if ( (v33 & 0x3FFFFF) != 0 )
      {
        v32->RefCount = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v32);
      }
    }
  }
  v34 = this->TraitsQName.pObject;
  if ( v34 )
  {
    if ( ((unsigned __int8)v34 & 1) != 0 )
    {
      this->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)((char *)v34 - 1);
    }
    else
    {
      v35 = v34->RefCount;
      if ( (v35 & 0x3FFFFF) != 0 )
      {
        v34->RefCount = v35 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
      }
    }
  }
  v36 = this->TraitsArray.pObject;
  if ( v36 )
  {
    if ( ((unsigned __int8)v36 & 1) != 0 )
    {
      this->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)((char *)v36 - 1);
    }
    else
    {
      v37 = v36->RefCount;
      if ( (v37 & 0x3FFFFF) != 0 )
      {
        v36->RefCount = v37 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v36);
      }
    }
  }
  v38 = this->TraitsString.pObject;
  if ( v38 )
  {
    if ( ((unsigned __int8)v38 & 1) != 0 )
    {
      this->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)((char *)v38 - 1);
    }
    else
    {
      v39 = v38->RefCount;
      if ( (v39 & 0x3FFFFF) != 0 )
      {
        v38->RefCount = v39 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
      }
    }
  }
  v40 = this->TraitsUint.pObject;
  if ( v40 )
  {
    if ( ((unsigned __int8)v40 & 1) != 0 )
    {
      this->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)((char *)v40 - 1);
    }
    else
    {
      v41 = v40->RefCount;
      if ( (v41 & 0x3FFFFF) != 0 )
      {
        v40->RefCount = v41 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v40);
      }
    }
  }
  v42 = this->TraitsInt.pObject;
  if ( v42 )
  {
    if ( ((unsigned __int8)v42 & 1) != 0 )
    {
      this->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)((char *)v42 - 1);
    }
    else
    {
      v43 = v42->RefCount;
      if ( (v43 & 0x3FFFFF) != 0 )
      {
        v42->RefCount = v43 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v42);
      }
    }
  }
  v44 = this->TraitsNumber.pObject;
  if ( v44 )
  {
    if ( ((unsigned __int8)v44 & 1) != 0 )
    {
      this->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)((char *)v44 - 1);
    }
    else
    {
      v45 = v44->RefCount;
      if ( (v45 & 0x3FFFFF) != 0 )
      {
        v44->RefCount = v45 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v44);
      }
    }
  }
  v46 = this->TraitsBoolean.pObject;
  if ( v46 )
  {
    if ( ((unsigned __int8)v46 & 1) != 0 )
    {
      this->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)((char *)v46 - 1);
    }
    else
    {
      v47 = v46->RefCount;
      if ( (v47 & 0x3FFFFF) != 0 )
      {
        v46->RefCount = v47 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v46);
      }
    }
  }
  v48 = this->TraitsFunction.pObject;
  if ( v48 )
  {
    if ( ((unsigned __int8)v48 & 1) != 0 )
    {
      this->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)((char *)v48 - 1);
    }
    else
    {
      v49 = v48->RefCount;
      if ( (v49 & 0x3FFFFF) != 0 )
      {
        v48->RefCount = v49 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v48);
      }
    }
  }
  v50 = this->TraitsNamespace.pObject;
  if ( v50 )
  {
    if ( ((unsigned __int8)v50 & 1) != 0 )
    {
      this->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)((char *)v50 - 1);
    }
    else
    {
      v51 = v50->RefCount;
      if ( (v51 & 0x3FFFFF) != 0 )
      {
        v50->RefCount = v51 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v50);
      }
    }
  }
  v52 = this->TraitsObject.pObject;
  if ( v52 )
  {
    if ( ((unsigned __int8)v52 & 1) != 0 )
    {
      this->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)((char *)v52 - 1);
    }
    else
    {
      v53 = v52->RefCount;
      if ( (v53 & 0x3FFFFF) != 0 )
      {
        v52->RefCount = v53 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v52);
      }
    }
  }
  v54 = this->TraitsClassClass.pObject;
  if ( v54 )
  {
    if ( ((unsigned __int8)v54 & 1) != 0 )
    {
      this->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)((char *)v54 - 1);
    }
    else
    {
      v55 = v54->RefCount;
      if ( (v55 & 0x3FFFFF) != 0 )
      {
        v54->RefCount = v55 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v54);
      }
    }
  }
  v56 = this->XMLNamespace.pObject;
  if ( v56 )
  {
    if ( ((unsigned __int8)v56 & 1) != 0 )
    {
      this->XMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v56 - 1);
    }
    else
    {
      v57 = v56->RefCount;
      if ( (v57 & 0x3FFFFF) != 0 )
      {
        v56->RefCount = v57 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v56);
      }
    }
  }
  v58 = this->ProxyNamespace.pObject;
  if ( v58 )
  {
    if ( ((unsigned __int8)v58 & 1) != 0 )
    {
      this->ProxyNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v58 - 1);
    }
    else
    {
      v59 = v58->RefCount;
      if ( (v59 & 0x3FFFFF) != 0 )
      {
        v58->RefCount = v59 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v58);
      }
    }
  }
  v60 = this->VectorNamespace.pObject;
  if ( v60 )
  {
    if ( ((unsigned __int8)v60 & 1) != 0 )
    {
      this->VectorNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v60 - 1);
    }
    else
    {
      v61 = v60->RefCount;
      if ( (v61 & 0x3FFFFF) != 0 )
      {
        v60->RefCount = v61 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v60);
      }
    }
  }
  v62 = this->AS3Namespace.pObject;
  if ( v62 )
  {
    if ( ((unsigned __int8)v62 & 1) != 0 )
    {
      this->AS3Namespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v62 - 1);
    }
    else
    {
      v63 = v62->RefCount;
      if ( (v63 & 0x3FFFFF) != 0 )
      {
        v62->RefCount = v63 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v62);
      }
    }
  }
  v64 = this->PublicNamespace.pObject;
  if ( v64 )
  {
    if ( ((unsigned __int8)v64 & 1) != 0 )
    {
      this->PublicNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v64 - 1);
    }
    else
    {
      v65 = v64->RefCount;
      if ( (v65 & 0x3FFFFF) != 0 )
      {
        v64->RefCount = v65 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v64);
      }
    }
  }
  v66 = this->CurrentDomain.pObject;
  if ( v66 )
  {
    if ( ((unsigned __int8)v66 & 1) != 0 )
    {
      this->CurrentDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v66 - 1);
    }
    else
    {
      v67 = v66->RefCount;
      if ( (v67 & 0x3FFFFF) != 0 )
      {
        v66->RefCount = v67 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v66);
      }
    }
  }
  v68 = this->SystemDomain.pObject;
  if ( v68 )
  {
    if ( ((unsigned __int8)v68 & 1) != 0 )
    {
      this->SystemDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v68 - 1);
    }
    else
    {
      v69 = v68->RefCount;
      if ( (v69 & 0x3FFFFF) != 0 )
      {
        v68->RefCount = v69 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v68);
      }
    }
  }
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&this->CallStack.DefaultValue);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease(&this->CallStack);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->GlobalObjects.Data.Data);
  if ( (this->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (this->ExceptionObj.Flags & 0x200) != 0 )
    {
      v70 = this->ExceptionObj.Bonus.pWeakProxy;
      v5 = v70->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->ExceptionObj.Bonus.pWeakProxy = 0i64;
      this->ExceptionObj.value.VS._1.VStr = 0i64;
      this->ExceptionObj.value.VS._2.VObj = 0i64;
      this->ExceptionObj.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExceptionObj);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->ScopeStack.Data.Data,
    this->ScopeStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->ScopeStack.Data.Data);
  Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(&this->RegisterFile);
  Scaleform::GFx::AS3::ValueStack::~ValueStack(&this->OpStack);
  v71 = this->XMLSupport_.pObject;
  if ( v71 )
  {
    if ( ((unsigned __int8)v71 & 1) != 0 )
    {
      this->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)v71 - 1);
    }
    else
    {
      v72 = v71->RefCount;
      if ( (v72 & 0x3FFFFF) != 0 )
      {
        v71->RefCount = v72 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v71);
      }
    }
  }
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->GC.GC, 0i64, 1u);
}

// File Line: 2071
// RVA: 0x7E9940
Scaleform::GFx::AS3::VMAppDomain *__fastcall Scaleform::GFx::AS3::VM::GetFrameAppDomain(Scaleform::GFx::AS3::VM *this)
{
  if ( this->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    return this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    return this->CurrentDomain.pObject;
}

// File Line: 2087
// RVA: 0x829150
void __fastcall Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(Scaleform::GFx::AS3::VM *this)
{
  unsigned __int64 Size; // rsi
  bool InDestructor; // bp
  unsigned __int64 i; // rdi

  Size = this->VMAbcFilesWeak.Data.Size;
  InDestructor = this->InDestructor;
  this->InDestructor = 1;
  for ( i = 0i64; i < Size; ++i )
    Scaleform::GFx::AS3::VMAbcFile::UnRegister(this->VMAbcFilesWeak.Data.Data[i]);
  if ( this->VMAbcFilesWeak.Data.Size && (this->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->VMAbcFilesWeak.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->VMAbcFilesWeak.Data.Data = 0i64;
    }
    this->VMAbcFilesWeak.Data.Policy.Capacity = 0i64;
  }
  this->VMAbcFilesWeak.Data.Size = 0i64;
  this->InDestructor = InDestructor;
}

// File Line: 2099
// RVA: 0x7D4240
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__fastcall Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result,
        const char *name,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned __int64 v6; // r10
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::VMAbcFile **Data; // r14
  Scaleform::GFx::AS3::VMAbcFile **v9; // r11
  unsigned __int64 v10; // rax
  const char *v11; // r8
  int v12; // ecx
  int v13; // edx
  Scaleform::GFx::AS3::VMAbcFile *v14; // rcx

  v6 = 0i64;
  Size = this->VMAbcFilesWeak.Data.Size;
  if ( Size )
  {
    Data = this->VMAbcFilesWeak.Data.Data;
    v9 = Data;
    while ( 1 )
    {
      v10 = ((*v9)->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
      v11 = &name[-v10];
      do
      {
        v12 = (unsigned __int8)v11[v10];
        v13 = *(unsigned __int8 *)v10 - v12;
        if ( v13 )
          break;
        ++v10;
      }
      while ( v12 );
      if ( !v13 && (*v9)->AppDomain.pObject == appDomain )
        break;
      ++v6;
      ++v9;
      if ( v6 >= Size )
        goto LABEL_13;
    }
    v14 = Data[v6];
    result->pObject = v14;
    if ( v14 )
      v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
LABEL_13:
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 2113
// RVA: 0x7AFC40
void __fastcall Scaleform::GFx::AS3::VM::AddVMAbcFileWeak(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *f)
{
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329,Scaleform::ArrayDefaultPolicy> *p_VMAbcFilesWeak; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::VMAbcFile **Data; // rax

  if ( !this->InDestructor )
  {
    p_VMAbcFilesWeak = &this->VMAbcFilesWeak;
    Size = this->VMAbcFilesWeak.Data.Size;
    v5 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v5 > this->VMAbcFilesWeak.Data.Policy.Capacity )
      {
        v6 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < this->VMAbcFilesWeak.Data.Policy.Capacity >> 1 )
    {
      v6 = Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy> *)&this->VMAbcFilesWeak,
        &this->VMAbcFilesWeak,
        v6);
    }
    Data = p_VMAbcFilesWeak->Data.Data;
    p_VMAbcFilesWeak->Data.Size = v5;
    Data[v5 - 1] = f;
  }
}

// File Line: 2121
// RVA: 0x812390
char __fastcall Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *f)
{
  unsigned __int64 Size; // r8
  __int64 v4; // rax
  Scaleform::GFx::AS3::VMAbcFile **Data; // r9
  Scaleform::GFx::AS3::VMAbcFile **i; // rcx

  if ( this->InDestructor )
    return 0;
  Size = this->VMAbcFilesWeak.Data.Size;
  v4 = 0i64;
  if ( !Size )
    return 0;
  Data = this->VMAbcFilesWeak.Data.Data;
  for ( i = Data; *i != f; ++i )
  {
    if ( ++v4 >= Size )
      return 0;
  }
  if ( Size == 1 )
  {
    if ( (this->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( Data )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Data);
        this->VMAbcFilesWeak.Data.Data = 0i64;
      }
      this->VMAbcFilesWeak.Data.Policy.Capacity = 0i64;
    }
    this->VMAbcFilesWeak.Data.Size = 0i64;
    return 1;
  }
  else
  {
    memmove(&Data[v4], &Data[v4 + 1], 8 * (Size - v4) - 8);
    --this->VMAbcFilesWeak.Data.Size;
    return 1;
  }
}

// File Line: 2137
// RVA: 0x7E5D20
unsigned __int64 __fastcall Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *destArray)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 Size; // r14
  Scaleform::GFx::AS3::VMAbcFile *v6; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v7; // rdx
  unsigned int RefCount; // ecx

  v4 = 0i64;
  if ( !this->InDestructor )
  {
    Size = this->VMAbcFilesWeak.Data.Size;
    if ( Size )
    {
      do
      {
        v6 = this->VMAbcFilesWeak.Data.Data[v4];
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &destArray->Data,
          destArray,
          destArray->Data.Size + 1);
        v7 = &destArray->Data.Data[destArray->Data.Size - 1];
        if ( v7 )
        {
          v7->pObject = v6;
          if ( v6 )
            v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v6 )
        {
          if ( ((unsigned __int8)v6 & 1) == 0 )
          {
            RefCount = v6->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v6->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
            }
          }
        }
        ++v4;
      }
      while ( v4 < Size );
    }
  }
  return v4;
}

// File Line: 2150
// RVA: 0x80FAF0
void __fastcall Scaleform::GFx::AS3::VM::RegisterClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::ASStringNode *v10; // [rsp+50h] [rbp+18h] BYREF

  pObject = tr->ITraits.pObject;
  v6 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **))pObject->vfptr[1].~RefCountBaseGC<328>)(
                                     pObject,
                                     &v10);
  val = tr;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &appDomain->ClassTraitsSet,
    v6,
    pObject->Ns.pObject,
    &val);
  v7 = v10;
  if ( v10->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 2157
// RVA: 0x7F9130
bool __fastcall Scaleform::GFx::AS3::IsScaleformGFx(Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx

  if ( (_S13_9 & 1) == 0 )
  {
    _S13_9 |= 1u;
    scaleform_gfx.pStr = "scaleform.gfx";
    scaleform_gfx.Size = 13i64;
  }
  pNode = ns->Uri.pNode;
  return pNode->Size >= scaleform_gfx.Size && !strncmp(pNode->pData, scaleform_gfx.pStr, scaleform_gfx.Size);
}

// File Line: 2179
// RVA: 0x7FA4D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *__fastcall Scaleform::GFx::AS3::VM::MakeArray(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->TraitsArray.pObject->ITraits.pObject);
  return result;
}

// File Line: 2185
// RVA: 0x7FA500
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *__fastcall Scaleform::GFx::AS3::VM::MakeByteArray(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
    result,
    (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)this->TraitsByteArray.pObject->ITraits.pObject);
  return result;
}

// File Line: 2191
// RVA: 0x7B1110
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::AsString(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->StringManagerRef,
    result);
  Scaleform::GFx::AS3::Value::Convert2String(value, &resulta, result);
  return result;
}

// File Line: 2206
// RVA: 0x7EECA0
Scaleform::GFx::AS3::ClassTraits::ClassClass *__fastcall Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::ClassTraits::ClassClass *result; // rax
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx

  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(mn) )
    return this->TraitsClassClass.pObject;
  ParentDomain = appDomain->ParentDomain;
  if ( ParentDomain )
  {
    result = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
                                                               ParentDomain,
                                                               mn);
    if ( result )
      return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)result->vfptr;
  }
  result = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                                                             &appDomain->ClassTraitsSet,
                                                             mn);
  if ( result )
    return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)result->vfptr;
  return result;
}

// File Line: 2231
// RVA: 0x7EEC30
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  ParentDomain = appDomain->ParentDomain;
  if ( ParentDomain )
  {
    result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns);
    if ( result )
      return (Scaleform::GFx::AS3::ClassTraits::Traits **)*result;
  }
  result = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
             &appDomain->ClassTraitsSet,
             name,
             ns);
  if ( result )
    return (Scaleform::GFx::AS3::ClassTraits::Traits **)*result;
  return result;
}

// File Line: 2237
// RVA: 0x815790
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [rsp+48h] [rbp+20h] BYREF

  ParentDomain = appDomain->ParentDomain;
  if ( (!ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, name, ns)) == 0i64)
    && (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &appDomain->ClassTraitsSet,
                       name,
                       ns)) == 0i64
    || (result = *ClassTrait) == 0i64 )
  {
    result = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(this->GlobalObject.pObject, name, ns);
    v11 = result;
    if ( result )
    {
      p_ClassTraitsSet = &this->SystemDomain.pObject->ClassTraitsSet;
      val = result;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
        p_ClassTraitsSet,
        name,
        ns,
        &val);
      return v11;
    }
  }
  return result;
}

// File Line: 2253
// RVA: 0x815840
Scaleform::GFx::AS3::ClassTraits::ClassClass *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::ClassTraits::ClassClass *RegisteredClassTraits; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v11; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h] BYREF
  __int64 v17; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // [rsp+38h] [rbp-20h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // [rsp+78h] [rbp+20h] BYREF

  v17 = -2i64;
  RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(this, mn, appDomain);
  if ( RegisteredClassTraits )
    return RegisteredClassTraits;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->StringManagerRef,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&v21, &result)->Result )
  {
    ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                    this->GlobalObject.pObject,
                    &result,
                    (Scaleform::GFx::AS3::Instances::fl::Namespace *)mn->Obj.pObject);
    RegisteredClassTraits = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)ClassTraits;
    if ( ClassTraits )
    {
      pObject = mn->Obj.pObject;
      v11 = this->SystemDomain.pObject;
      v21 = ClassTraits;
      pNode = result.pNode;
      ++result.pNode->RefCount;
      v19 = pObject;
      if ( pObject )
        pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&pNode;
      key.pSecond = &v21;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        &v11->ClassTraitsSet.Entries.mHash,
        v11->ClassTraitsSet.Entries.mHash.pHeap,
        &key,
        pNode->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v19[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v19[1].vfptr) << 28) >> 28));
      v12 = v19;
      if ( v19 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v19 - 1);
        }
        else
        {
          RefCount = v19->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v19->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
      v14 = pNode;
      v7 = pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v15 = result.pNode;
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    return RegisteredClassTraits;
  }
  v6 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 0i64;
}

// File Line: 2276
// RVA: 0x8153E0
Scaleform::GFx::AS3::ClassTraits::ClassClass *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v9; // rsi
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *Constructor; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+18h] BYREF

  if ( !*(_QWORD *)&mn->NameIndex && !mn->Ind )
    return this->TraitsClassClass.pObject;
  Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, mn->NameIndex);
  if ( result.pNode == this->StringManagerRef->Builtins[3].pNode )
  {
    pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsObject.pObject;
  }
  else
  {
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, mn->Ind);
    pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                                    this,
                                                                    &result,
                                                                    InternedNamespace,
                                                                    file->AppDomain.pObject);
    if ( pObject == this->TraitsVector.pObject )
    {
      if ( mn->NextIndex > 0 )
      {
        v10 = (Scaleform::GFx::AS3::Abc::Multiname *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, _QWORD))file->vfptr[1].ForEachChild_GC)(
                                                       file,
                                                       mn->NextIndex);
        v9 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                               this,
                                                               file,
                                                               v10);
      }
      else
      {
        v9 = this->TraitsObject.pObject;
      }
      if ( v9 )
      {
        switch ( v9->TraitsType )
        {
          case Traits_SInt:
            pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_int.pObject;
            break;
          case Traits_UInt:
            pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_uint.pObject;
            break;
          case Traits_Number:
            pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_Number.pObject;
            break;
          case Traits_String:
            pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->TraitsVector_String.pObject;
            break;
          default:
            if ( v9->ITraits.pObject )
            {
              Constructor = (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::Traits::GetConstructor(pObject->ITraits.pObject);
              pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
                                                                              Constructor,
                                                                              v9);
            }
            break;
        }
      }
    }
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pObject;
}

// File Line: 2349
// RVA: 0x815540
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v7; // rdi
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  void *v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *ClassTraits; // rax
  Scaleform::GFx::AS3::VMAppDomain *v12; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *pNode; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // [rsp+40h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+48h] [rbp-20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+28h] BYREF
  Scaleform::GFx::ASString uri; // [rsp+98h] [rbp+30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v26; // [rsp+A0h] [rbp+38h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // [rsp+A8h] [rbp+40h]

  StringManagerRef = this->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &result,
    ti->Name);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &uri,
    ti->PkgName);
  if ( uri.pNode->Size )
  {
    pObject = this->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&pObject[1].RefCount,
      &v26,
      NS_Public,
      &uri,
      &v);
    pV = v26.pV;
  }
  else
  {
    pV = this->PublicNamespace.pObject;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  v27 = pV;
  v7 = this->SystemDomain.pObject;
  ParentDomain = v7->ParentDomain;
  if ( (!ParentDomain
     || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &result, pV)) == 0i64)
    && (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &v7->ClassTraitsSet,
                       &result,
                       pV)) == 0i64
    || (v10 = *ClassTrait) == 0i64 )
  {
    ClassTraits = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                                     this->GlobalObject.pObject,
                                                                     &result,
                                                                     pV);
    v10 = ClassTraits;
    if ( ClassTraits )
    {
      v12 = this->SystemDomain.pObject;
      v26.pV = ClassTraits;
      pNode = result.pNode;
      ++result.pNode->RefCount;
      v22 = pV;
      if ( pV )
        pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&pNode;
      key.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v26;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        &v12->ClassTraitsSet.Entries.mHash,
        v12->ClassTraitsSet.Entries.mHash.pHeap,
        &key,
        pNode->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v22[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v22[1].vfptr) << 28) >> 28));
      v13 = v22;
      if ( v22 )
      {
        if ( ((unsigned __int8)v22 & 1) != 0 )
        {
          v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
        }
        else
        {
          RefCount = v22->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v22->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
      v15 = pNode;
      v16 = pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v27 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV - 1);
    }
    else
    {
      v17 = pV->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  v18 = uri.pNode;
  v16 = uri.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return (Scaleform::GFx::AS3::ClassTraits::Traits *)v10;
}

// File Line: 2359
// RVA: 0x829210
void __fastcall Scaleform::GFx::AS3::VM::UnregisterGlobalObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *go)
{
  unsigned __int64 Size; // rcx
  __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **Data; // r9
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **i; // r8

  Size = this->GlobalObjects.Data.Size;
  v4 = 0i64;
  if ( Size )
  {
    Data = this->GlobalObjects.Data.Data;
    for ( i = Data; *i != go; ++i )
    {
      if ( ++v4 >= Size )
        return;
    }
    if ( Size == 1 )
    {
      if ( (this->GlobalObjects.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      {
        if ( Data )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Instances::fl::GlobalObject **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            this->GlobalObjects.Data.Data,
            1i64);
          this->GlobalObjects.Data.Data = 0i64;
        }
        this->GlobalObjects.Data.Policy.Capacity = 0i64;
      }
      this->GlobalObjects.Data.Size = 0i64;
    }
    else
    {
      memmove(&Data[v4], &Data[v4 + 1], 8 * (Size - v4) - 8);
      --this->GlobalObjects.Data.Size;
    }
  }
}

// File Line: 2374
// RVA: 0x818AC0
void __fastcall Scaleform::GFx::AS3::VM::SetClassAlias(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *alias,
        Scaleform::GFx::AS3::Class *cl)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::TableType *pTable; // rsi
  __int64 v7; // rax
  unsigned __int64 *v8; // rcx
  Scaleform::GFx::AS3::Class *v9; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v10; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v11; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>,329,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *p_ClassAlias; // rdx
  Scaleform::HashLH<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>,329,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *v13; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v14; // rax
  unsigned __int64 HashFlags; // r9
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeRef v16; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::Class *key; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Class *value; // [rsp+60h] [rbp+18h] BYREF

  value = cl;
  pTable = this->AliasClass.mHash.pTable;
  if ( pTable
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->AliasClass,
               alias,
               pTable->SizeMask & alias->pNode->HashFlags),
        v7 >= 0)
    && (v8 = &pTable[1].SizeMask + 3 * v7) != 0i64 )
  {
    v9 = (Scaleform::GFx::AS3::Class *)v8[1];
    key = v9;
    if ( v9 == cl )
      return;
    v10 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v9->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(v9->pTraits.pObject);
    if ( v10 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::RemoveAlt<Scaleform::GFx::ASString>(
        v10 + 29,
        alias);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Class *>(
      &this->ClassAlias.mHash,
      &key);
    v11 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))value->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(value->pTraits.pObject);
    if ( v11 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::add<Scaleform::GFx::ASString>(
        v11 + 29,
        &v11[29],
        alias,
        alias->pNode->HashFlags);
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>>>::Set(
      &this->AliasClass,
      alias,
      &value);
    p_ClassAlias = &this->ClassAlias;
    v13 = &this->ClassAlias;
  }
  else
  {
    v14 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))cl->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[2].~RefCountBaseGC<328>)(cl->pTraits.pObject);
    if ( v14 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::add<Scaleform::GFx::ASString>(
        v14 + 29,
        &v14[29],
        alias,
        alias->pNode->HashFlags);
    v16.pSecond = &value;
    HashFlags = alias->pNode->HashFlags;
    v16.pFirst = alias;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeRef>(
      &this->AliasClass.mHash,
      &this->AliasClass,
      &v16,
      HashFlags);
    v13 = &this->ClassAlias;
    p_ClassAlias = &this->ClassAlias;
  }
  v16.pSecond = (Scaleform::GFx::AS3::Class *const *)alias;
  v16.pFirst = (Scaleform::GFx::ASString *)&value;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeRef>(
    &v13->mHash,
    p_ClassAlias,
    (Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeRef *)&v16);
}

// File Line: 2420
// RVA: 0x7E6E40
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::VM::GetClassByAlias(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *alias)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_AliasClass; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v3; // rbx
  __int64 v4; // rax
  unsigned __int64 *v5; // rax

  p_AliasClass = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->AliasClass;
  v3.pTable = p_AliasClass->pTable;
  if ( p_AliasClass->pTable
    && (v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               p_AliasClass,
               alias,
               v3.pTable->SizeMask & alias->pNode->HashFlags),
        v4 >= 0)
    && (v5 = &v3.pTable[1].SizeMask + 3 * v4) != 0i64 )
  {
    return (Scaleform::GFx::AS3::Class *)v5[1];
  }
  else
  {
    return 0i64;
  }
}

// File Line: 2427
// RVA: 0x7E5C90
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::GetAliasByClass(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Class *cl)
{
  signed __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> >::TableType *v6; // rax
  Scaleform::GFx::ASStringNode *SizeMask; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Class *key; // [rsp+50h] [rbp+18h] BYREF

  key = cl;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->StringManagerRef,
    result);
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::ASString>(
         &this->ClassAlias.mHash,
         &key);
  if ( v5 >= 0 )
  {
    v6 = &this->ClassAlias.mHash.pTable[2 * v5 + 2];
    if ( v6 )
    {
      if ( result )
      {
        SizeMask = (Scaleform::GFx::ASStringNode *)v6->SizeMask;
        ++SizeMask->RefCount;
        pNode = result->pNode;
        if ( result->pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        result->pNode = SizeMask;
      }
    }
  }
  return result;
}

// File Line: 2435
// RVA: 0x7F8BA0
_BOOL8 __fastcall Scaleform::GFx::AS3::VM::IsOfType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *v,
        const char *type_name,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned __int64 v7; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  bool v9; // bl
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  qname.pStr = type_name;
  if ( type_name )
  {
    v7 = -1i64;
    do
      ++v7;
    while ( type_name[v7] );
    qname.Size = v7;
  }
  else
  {
    qname.Size = 0i64;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this, &qname);
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, &mn, appDomain);
  v9 = v8 && Scaleform::GFx::AS3::VM::IsOfType(this, v, v8);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return v9;
}

// File Line: 2451
// RVA: 0x7F8CD0
char __fastcall Scaleform::GFx::AS3::VM::IsOfType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::fl::Object *ctr)
{
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // ebx
  bool v7; // zf
  bool v8; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::Value::V1U v10; // rcx
  Scaleform::GFx::AS3::Class *Constructor; // rax
  long double iptr; // [rsp+38h] [rbp+10h] BYREF

  TraitsType = ctr->TraitsType;
  switch ( v->Flags & 0x1F )
  {
    case 1u:
      return TraitsType == Traits_Boolean || ctr == this->TraitsObject.pObject;
    case 2u:
      if ( TraitsType == Traits_UInt )
        return v->value.VS._1.VInt >= 0;
      if ( TraitsType == Traits_Number )
        return 1;
      v7 = TraitsType == Traits_SInt;
      goto LABEL_10;
    case 3u:
      if ( TraitsType == Traits_SInt )
        return v->value.VS._1.VInt <= 0x7FFFFFFFu;
      if ( TraitsType == Traits_Number )
        return 1;
      v7 = TraitsType == Traits_UInt;
LABEL_10:
      if ( !v7 )
      {
        v8 = ctr == this->TraitsObject.pObject;
        goto LABEL_12;
      }
      return 1;
    case 4u:
      if ( modf(v->value.VNumber, &iptr) != 0.0 )
        goto LABEL_27;
      if ( TraitsType == Traits_UInt )
      {
        if ( iptr >= 0.0 && iptr <= 4294967295.0 )
          return 1;
      }
      else if ( TraitsType == Traits_SInt )
      {
        if ( iptr >= -2147483648.0 && iptr <= 2147483647.0 )
          return 1;
      }
      else
      {
LABEL_27:
        if ( TraitsType == Traits_Number )
          return 1;
        v8 = ctr == this->TraitsObject.pObject;
LABEL_12:
        if ( v8 )
          return 1;
      }
      return 0;
    case 0xAu:
      if ( !v->value.VS._1.VStr )
        return 0;
      v7 = TraitsType == Traits_String;
      goto LABEL_10;
    case 0xBu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      goto $LN5_84;
    case 0xCu:
      if ( !v->value.VS._1.VStr )
        return 0;
$LN5_84:
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, v);
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(ClassTraits, ctr);
    case 0xDu:
      v10 = v->value.VS._1;
      if ( !v10.VStr )
        return 0;
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)v10.VStr[1].pData);
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
               (Scaleform::GFx::AS3::ClassTraits::Traits *)Constructor->pTraits.pObject,
               ctr);
    default:
      return 0;
  }
}

// File Line: 2522
// RVA: 0x8042E0
__int64 __fastcall Scaleform::GFx::AS3::VM::OnException(
        Scaleform::GFx::AS3::VM *this,
        unsigned __int64 offset,
        Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::MethodInfo *v6; // r12
  unsigned __int64 i; // rdi
  unsigned __int64 Size; // rdx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *Data; // r8
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v10; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v11; // r15
  __int64 exc_type_ind; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v14; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // rsi
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  bool v17; // r8
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  bool v19; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  int target; // r10d
  Scaleform::GFx::AS3::VM *v24; // rcx
  bool v25; // r8
  Scaleform::GFx::AS3::Value *v26; // rcx
  Scaleform::GFx::AS3::Value::V1U v27; // rcx

  v6 = &cf->pFile->MethodInfoArray.Data.Data[cf->MBIIndex.Ind];
  for ( i = 0i64; ; ++i )
  {
    Size = v6->Exception.info.Data.Size;
    if ( i >= Size )
    {
LABEL_59:
      target = -1;
      goto LABEL_60;
    }
    Data = v6->Exception.info.Data.Data;
    v10 = &Data[i];
    while ( offset < v10->from || offset > v10->to )
    {
      ++i;
      ++v10;
      if ( i >= Size )
        goto LABEL_59;
    }
    v11 = &Data[i];
    exc_type_ind = (int)v11->exc_type_ind;
    if ( !(_DWORD)exc_type_ind )
      break;
    if ( (this->ExceptionObj.Flags & 0x1F) != 0 )
    {
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, &this->ExceptionObj);
      this->HandleException = 0;
      v14 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              this,
              cf->pFile,
              &cf->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[exc_type_ind]);
      v15 = v14;
      this->HandleException = 1;
      if ( v14 )
      {
        if ( v14 == ClassTraits )
          goto LABEL_17;
        if ( ClassTraits )
        {
          while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))ClassTraits->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
                     ClassTraits->ITraits.pObject,
                     v15->ITraits.pObject) )
          {
            ClassTraits = (Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits->pParent.pObject;
            if ( ClassTraits == v15 )
              break;
            if ( !ClassTraits )
              goto LABEL_16;
          }
LABEL_17:
          VMRef = cf->pFile->VMRef;
          v17 = !cf->DiscardResult && !VMRef->HandleException;
          Scaleform::GFx::AS3::ValueStack::PopReserved(&VMRef->OpStack, cf->PrevInitialStackPos, v17);
          p_ExceptionObj = &this->ExceptionObj;
          v19 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
          pCurrent = this->OpStack.pCurrent;
          if ( !v19 )
          {
            pCurrent->Flags = p_ExceptionObj->Flags;
            pCurrent->Bonus.pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
            pCurrent->value.VS._1.VStr = this->ExceptionObj.value.VS._1.VStr;
            pCurrent->value.VS._2.VObj = this->ExceptionObj.value.VS._2.VObj;
            if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
            {
              if ( (p_ExceptionObj->Flags & 0x200) != 0 )
              {
                ++this->ExceptionObj.Bonus.pWeakProxy->RefCount;
                goto LABEL_34;
              }
              if ( (p_ExceptionObj->Flags & 0x1F) == 10 )
              {
                ++this->ExceptionObj.value.VS._1.VStr->RefCount;
              }
              else
              {
                if ( (p_ExceptionObj->Flags & 0x1F) <= 0xA )
                  goto LABEL_34;
                if ( (p_ExceptionObj->Flags & 0x1F) <= 0xF )
                {
                  VObj = this->ExceptionObj.value.VS._1;
                }
                else
                {
                  if ( (p_ExceptionObj->Flags & 0x1F) > 0x11 )
                    goto LABEL_34;
                  VObj = (Scaleform::GFx::AS3::Value::V1U)this->ExceptionObj.value.VS._2.VObj;
                }
                if ( VObj.VStr )
                  VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
              }
            }
          }
          goto LABEL_34;
        }
      }
    }
LABEL_16:
    ;
  }
  v24 = cf->pFile->VMRef;
  v25 = !cf->DiscardResult && !v24->HandleException;
  Scaleform::GFx::AS3::ValueStack::PopReserved(&v24->OpStack, cf->PrevInitialStackPos, v25);
  p_ExceptionObj = &this->ExceptionObj;
  v19 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  v26 = this->OpStack.pCurrent;
  if ( !v19 )
  {
    v26->Flags = p_ExceptionObj->Flags;
    v26->Bonus.pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
    v26->value.VS._1.VStr = this->ExceptionObj.value.VS._1.VStr;
    v26->value.VS._2.VObj = this->ExceptionObj.value.VS._2.VObj;
    if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
    {
      if ( (p_ExceptionObj->Flags & 0x200) != 0 )
      {
        ++this->ExceptionObj.Bonus.pWeakProxy->RefCount;
        goto LABEL_34;
      }
      if ( (p_ExceptionObj->Flags & 0x1F) == 10 )
      {
        ++this->ExceptionObj.value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_ExceptionObj->Flags & 0x1F) <= 0xA )
          goto LABEL_34;
        if ( (p_ExceptionObj->Flags & 0x1F) <= 0xF )
        {
          v27 = this->ExceptionObj.value.VS._1;
        }
        else
        {
          if ( (p_ExceptionObj->Flags & 0x1F) > 0x11 )
            goto LABEL_34;
          v27 = (Scaleform::GFx::AS3::Value::V1U)this->ExceptionObj.value.VS._2.VObj;
        }
        if ( v27.VStr )
          v27.VStr->Size = (v27.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
LABEL_34:
  if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
  {
    if ( (p_ExceptionObj->Flags & 0x200) != 0 )
    {
      pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
      v19 = pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      p_ExceptionObj->Bonus.pWeakProxy = 0i64;
      p_ExceptionObj->value.VS._1.VStr = 0i64;
      p_ExceptionObj->value.VS._2.VObj = 0i64;
      p_ExceptionObj->Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
    }
  }
  p_ExceptionObj->Flags = 0;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &cf->pScopeStack->Data,
    cf->ScopeStackBaseInd);
  target = v11->target;
LABEL_60:
  this->HandleException = target < 0;
  return (unsigned int)target;
}

// File Line: 2589
// RVA: 0x8413D0
void __fastcall Scaleform::GFx::AS3::VM::exec_getsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  int v7; // ecx
  char v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+58h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::StackReader v16; // [rsp+68h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+78h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::Value *result; // [rsp+A8h] [rbp+37h]
  __int64 v19; // [rsp+B8h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+67h] BYREF

  v19 = -2i64;
  v16.VMRef = file->VMRef;
  v16.OpStack = &v16.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v16, &obj);
  pCurrent = v16.OpStack->pCurrent;
  result = pCurrent;
  v7 = pCurrent->Flags & 0x1F;
  if ( !v7 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !pCurrent->value.VS._1.VStr )
  {
    if ( (unsigned int)(v7 - 12) > 3 && v7 != 10 || (v8 = 1, pCurrent->value.VS._1.VStr) )
      v8 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1010 - (v8 != 0), v16.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v16.VMRef, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v15.Message.pNode;
    v11 = v15.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    _this.Flags = result->Flags;
    _this.Bonus.pWeakProxy = result->Bonus.pWeakProxy;
    _this.value = result->value;
    result->Flags = 0;
    if ( Scaleform::GFx::AS3::GetSuperProperty(
           (Scaleform::GFx::AS3::CheckResult *)&retaddr,
           this,
           ot,
           result,
           &_this,
           &obj)->Result )
    {
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          goto LABEL_28;
        }
        v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_26;
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, 1035, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v13 = v15.Message.pNode;
      v11 = v15.Message.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          goto LABEL_28;
        }
        v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_26:
        memset(&_this.Bonus, 0, 24);
        _this.Flags &= 0xFFFFFDE0;
      }
    }
  }
LABEL_28:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 2605
// RVA: 0x846E50
void __fastcall Scaleform::GFx::AS3::VM::exec_setsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  int v6; // ecx
  char v7; // al
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::StackReader v13; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+88h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+A8h] [rbp+37h] BYREF
  __int64 v18; // [rsp+B8h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+67h] BYREF

  v18 = -2i64;
  v13.VMRef = file->VMRef;
  v13.OpStack = &v13.VMRef->OpStack;
  value.Flags = v13.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v13.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v13.VMRef->OpStack.pCurrent->value;
  --v13.VMRef->OpStack.pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v13, &obj);
  _this.Flags = v13.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v13.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v13.OpStack->pCurrent->value;
  --v13.OpStack->pCurrent;
  v6 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !_this.value.VS._1.VStr )
  {
    if ( (unsigned int)(v6 - 12) > 3 && v6 != 10 || (v7 = 1, _this.value.VS._1.VStr) )
      v7 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, 1010 - (v7 != 0), v13.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v13.VMRef, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->HandleException )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_26:
        memset(&_this.Bonus, 0, 24);
        _this.Flags &= 0xFFFFFDE0;
        goto LABEL_35;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  else if ( Scaleform::GFx::AS3::SetSuperProperty(
              (Scaleform::GFx::AS3::CheckResult *)&retaddr,
              this,
              ot,
              &_this,
              &obj,
              &value)->Result )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_26;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, 1035, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v12 = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_26;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
LABEL_35:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      value.Flags &= 0xFFFFFDE0;
      memset(&value.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

// File Line: 2621
// RVA: 0x846960
void __fastcall Scaleform::GFx::AS3::VM::exec_setproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  int v4; // ecx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::StackReader v9; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+90h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+B0h] [rbp+37h] BYREF
  __int64 v14; // [rsp+C0h] [rbp+47h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+E0h] [rbp+67h] BYREF

  v14 = -2i64;
  v9.VMRef = file->VMRef;
  v9.OpStack = &v9.VMRef->OpStack;
  value.Flags = v9.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v9.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v9.VMRef->OpStack.pCurrent->value;
  --v9.VMRef->OpStack.pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v9, &obj);
  _this.Flags = v9.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v9.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v9.OpStack->pCurrent->value;
  --v9.OpStack->pCurrent;
  v4 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !_this.value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !_this.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v5, v9.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
    Scaleform::GFx::AS3::SetProperty(&result, this, &_this, &obj, &value);
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

// File Line: 2634
// RVA: 0x83A250
void __fastcall Scaleform::GFx::AS3::VM::exec_callproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  bool v12; // zf
  int v13; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::VU v15; // kr00_16
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::Value::V2U v24; // [rsp+90h] [rbp-58h]
  __int64 v25; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgsMnObject ptr; // [rsp+A8h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult v27[8]; // [rsp+258h] [rbp+170h] BYREF

  v25 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr.FixedArr, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&ptr.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&ptr, &ptr.ArgMN);
  ptr.ArgObject.Flags = ptr.OpStack->pCurrent->Flags;
  ptr.ArgObject.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  ptr.ArgObject.value = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v8 = ptr.ArgObject.Flags & 0x1F;
  if ( (ptr.ArgObject.Flags & 0x1F) == 0
    || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !ptr.ArgObject.value.VS._1.VStr )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, ptr.ArgObject.value.VS._1.VStr) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      1010 - (v9 != 0),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    VStr = result.This.value.VS._1.VStr;
    v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
  if ( this->HandleException )
    goto LABEL_92;
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&result, this, &ptr.ArgObject, &ptr.ArgMN, FindCall);
  if ( (result.This.Flags & 0x1F) == 0
    || ((__int64)result.pSI & 1) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)result.pSI & 2) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    if ( (Scaleform::GFx::AS3::VM::GetValueTraits(this, &ptr.ArgObject)->Flags & 2) != 0
      || (ptr.ArgObject.Flags & 0x1F) <= 4
      || (ptr.ArgObject.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1006, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v21 = result.This.value.VS._1.VStr;
      v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      goto LABEL_86;
    }
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1069, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v18, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v19 = result.This.value.VS._1.VStr;
    v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    if ( (result.This.Flags & 0x1F) <= 9 )
    {
LABEL_74:
      Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject(&ptr);
      return;
    }
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.SlotIndex, 0, 24);
        goto LABEL_74;
      }
      goto LABEL_72;
    }
    goto LABEL_73;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v27, this, &value, valExecute)->Result )
  {
    v13 = value.Flags & 0x1F;
    if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v13 - 12) > 3 && v13 != 10 || value.value.VS._1.VStr) )
    {
      argv = ptr.FixedArr;
      if ( ptr.ArgNum > 8 )
        argv = ptr.CallArgs.Data.Data;
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      LODWORD(result.This.Bonus.pWeakProxy) = v.Flags;
      result.This.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
      v15 = v.value;
      v24.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            if ( v.value.VS._1.VStr )
            {
              ++v.value.VS._1.VStr->Size;
              v15.VS._1.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            v15.VS._2.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        this,
        &value,
        &ptr.ArgObject,
        (Scaleform::GFx::AS3::Value *)&result.This.Bonus,
        arg_count,
        argv,
        1);
      if ( (unsigned __int64)((__int64)result.This.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( ((__int64)result.This.Bonus.pWeakProxy & 0x200) != 0 )
        {
          v12 = LODWORD(result.This.value.VS._1.VStr->pData)-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          result.This.value = 0ui64;
          v24.VObj = 0i64;
          LODWORD(result.This.Bonus.pWeakProxy) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&result.This.Bonus);
        }
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_74;
      if ( (result.This.Flags & 0x200) != 0 )
      {
        v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.SlotIndex, 0, 24);
          goto LABEL_74;
        }
LABEL_72:
        memset(&result.SlotIndex, 0, 24);
        goto LABEL_74;
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1006, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v16, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v17 = result.This.value.VS._1.VStr;
      v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_74;
      if ( (result.This.Flags & 0x200) != 0 )
      {
        v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_72;
      }
    }
LABEL_73:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    goto LABEL_74;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
LABEL_86:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.SlotIndex, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_92:
  if ( (ptr.ArgObject.Flags & 0x1F) > 9 )
  {
    if ( (ptr.ArgObject.Flags & 0x200) != 0 )
    {
      v12 = ptr.ArgObject.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&ptr.ArgObject.Bonus, 0, 24);
      ptr.ArgObject.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr.ArgObject);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&ptr.ArgMN);
  *(_QWORD *)&v27[0].Result = &ptr.CallArgs;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2692
// RVA: 0x8462F0
void __fastcall Scaleform::GFx::AS3::VM::exec_returnvoid(Scaleform::GFx::AS3::VM *this)
{
  bool v2; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].DiscardResult )
  {
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v2 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    pCurrent = this->OpStack.pCurrent;
    if ( !v2 )
    {
      pCurrent->Flags = v.Flags;
      pCurrent->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
      pCurrent->value = v.value;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
          return;
        }
        if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else
        {
          if ( (v.Flags & 0x1F) <= 0xA )
            return;
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            VObj = v.value.VS._1;
          }
          else
          {
            if ( (v.Flags & 0x1F) > 0x11 )
              return;
            VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
          }
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
        }
      }
    }
  }
}

// File Line: 2714
// RVA: 0x846230
void __fastcall Scaleform::GFx::AS3::VM::exec_returnvalue(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].DiscardResult )
  {
    Scaleform::GFx::AS3::VM::Coerce2ReturnType(this, this->OpStack.pCurrent, this->OpStack.pCurrent);
    return;
  }
  pCurrent = this->OpStack.pCurrent;
  if ( (pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_8:
    --this->OpStack.pCurrent;
    return;
  }
  if ( (pCurrent->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(pCurrent);
    goto LABEL_8;
  }
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pCurrent->Flags &= 0xFFFFFDE0;
  pCurrent->Bonus.pWeakProxy = 0i64;
  pCurrent->value.VS._1.VStr = 0i64;
  pCurrent->value.VS._2.VObj = 0i64;
  --this->OpStack.pCurrent;
}

// File Line: 2783
// RVA: 0x83A9D0
void __fastcall Scaleform::GFx::AS3::VM::exec_callproplex(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  bool v12; // zf
  int v13; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value *Undefined; // rdi
  Scaleform::GFx::AS3::Value::VU v16; // kr00_16
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+90h] [rbp-58h]
  __int64 v26; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgsMnObject ptr; // [rsp+A8h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult v28[8]; // [rsp+258h] [rbp+170h] BYREF

  v26 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr.FixedArr, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&ptr.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&ptr, &ptr.ArgMN);
  ptr.ArgObject.Flags = ptr.OpStack->pCurrent->Flags;
  ptr.ArgObject.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  ptr.ArgObject.value = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v8 = ptr.ArgObject.Flags & 0x1F;
  if ( (ptr.ArgObject.Flags & 0x1F) == 0
    || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !ptr.ArgObject.value.VS._1.VStr )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, ptr.ArgObject.value.VS._1.VStr) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      1010 - (v9 != 0),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    VStr = result.This.value.VS._1.VStr;
    v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
  if ( !this->HandleException )
  {
    memset(&result, 0, 20);
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&result, this, &ptr.ArgObject, &ptr.ArgMN, FindCall);
    if ( (result.This.Flags & 0x1F) != 0
      && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v28, this, &value, valExecute)->Result )
      {
        v13 = value.Flags & 0x1F;
        if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v13 - 12) > 3 && v13 != 10 || value.value.VS._1.VStr) )
        {
          argv = ptr.FixedArr;
          if ( ptr.ArgNum > 8 )
            argv = ptr.CallArgs.Data.Data;
          Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
          if ( (_S11_12 & 1) == 0 )
          {
            _S11_12 |= 1u;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0i64;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          LODWORD(result.This.Bonus.pWeakProxy) = v.Flags;
          result.This.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
          v16 = v.value;
          v25.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags & 0x200) != 0 )
            {
              ++v.Bonus.pWeakProxy->RefCount;
            }
            else if ( (v.Flags & 0x1F) == 10 )
            {
              ++v.value.VS._1.VStr->RefCount;
            }
            else if ( (v.Flags & 0x1F) > 0xA )
            {
              if ( (v.Flags & 0x1F) <= 0xF )
              {
                if ( v.value.VS._1.VStr )
                {
                  ++v.value.VS._1.VStr->Size;
                  v16.VS._1.VStr->Size &= 0x8FBFFFFF;
                }
              }
              else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
              {
                ++v.value.VS._2.VObj->RefCount;
                v16.VS._2.VObj->RefCount &= 0x8FBFFFFF;
              }
            }
          }
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
            this,
            &value,
            Undefined,
            (Scaleform::GFx::AS3::Value *)&result.This.Bonus,
            arg_count,
            argv,
            1);
          if ( (unsigned __int64)((__int64)result.This.Bonus.pWeakProxy & 0x1F) > 9 )
          {
            if ( ((__int64)result.This.Bonus.pWeakProxy & 0x200) != 0 )
            {
              v12 = LODWORD(result.This.value.VS._1.VStr->pData)-- == 1;
              if ( v12 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              result.This.value = 0ui64;
              v25.VObj = 0i64;
              LODWORD(result.This.Bonus.pWeakProxy) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&result.This.Bonus);
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags & 0x200) != 0 )
            {
              v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v12 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&value.Bonus, 0, 24);
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (result.This.Flags & 0x1F) <= 9 )
            goto LABEL_56;
          if ( (result.This.Flags & 0x200) != 0 )
          {
            v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_54:
            memset(&result.SlotIndex, 0, 24);
LABEL_56:
            Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject(&ptr);
            return;
          }
          goto LABEL_55;
        }
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1006, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v18 = result.This.value.VS._1.VStr;
        v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
    }
    else
    {
      if ( (Scaleform::GFx::AS3::VM::GetValueTraits(this, &ptr.ArgObject)->Flags & 2) == 0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1069, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v21, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v22 = result.This.value.VS._1.VStr;
        v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        if ( (result.This.Flags & 0x1F) <= 9 )
          goto LABEL_56;
        if ( (result.This.Flags & 0x200) != 0 )
        {
          v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&result.SlotIndex, 0, 24);
            goto LABEL_56;
          }
          goto LABEL_54;
        }
LABEL_55:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_56;
      }
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1006, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v19, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v20 = result.This.value.VS._1.VStr;
      v12 = result.This.value.VS._1.VStr->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags & 0x200) != 0 )
      {
        v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.SlotIndex, 0, 24);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
  }
  if ( (ptr.ArgObject.Flags & 0x1F) > 9 )
  {
    if ( (ptr.ArgObject.Flags & 0x200) != 0 )
    {
      v12 = ptr.ArgObject.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&ptr.ArgObject.Bonus, 0, 24);
      ptr.ArgObject.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr.ArgObject);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&ptr.ArgMN);
  *(_QWORD *)&v28[0].Result = &ptr.CallArgs;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2850
// RVA: 0x83B090
void __fastcall Scaleform::GFx::AS3::VM::exec_callpropvoid(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  int v13; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::V1U v15; // rcx
  Scaleform::GFx::AS3::Value::V2U v16; // r8
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Value::VU v26; // [rsp+A0h] [rbp-60h]
  __int64 ptr_8; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgsMnObject ptr_24; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_CallArgs; // [rsp+270h] [rbp+170h] BYREF

  ptr_8 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr_24, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&ptr_24.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&ptr_24, &ptr_24.ArgMN);
  ptr_24.ArgObject.Flags = ptr_24.OpStack->pCurrent->Flags;
  ptr_24.ArgObject.Bonus.pWeakProxy = ptr_24.OpStack->pCurrent->Bonus.pWeakProxy;
  ptr_24.ArgObject.value = ptr_24.OpStack->pCurrent->value;
  --ptr_24.OpStack->pCurrent;
  v8 = ptr_24.ArgObject.Flags & 0x1F;
  if ( (ptr_24.ArgObject.Flags & 0x1F) == 0
    || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !ptr_24.ArgObject.value.VS._1.VStr )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, ptr_24.ArgObject.value.VS._1.VStr) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 1010 - (v9 != 0), ptr_24.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr_24.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v25.Message.pNode;
    v12 = v25.Message.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    memset(&result, 0, 20);
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&result, this, &ptr_24.ArgObject, &ptr_24.ArgMN, FindCall);
    if ( (result.This.Flags & 0x1F) != 0
      && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
             &result,
             (Scaleform::GFx::AS3::CheckResult *)&p_CallArgs,
             this,
             &value,
             valExecute)->Result )
      {
        v13 = value.Flags & 0x1F;
        if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v13 - 12) > 3 && v13 != 10 || value.value.VS._1.VStr) )
        {
          argv = ptr_24.FixedArr;
          if ( ptr_24.ArgNum > 8 )
            argv = ptr_24.CallArgs.Data.Data;
          if ( (_S11_12 & 1) == 0 )
          {
            _S11_12 |= 1u;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0i64;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          v25.ID = v.Flags;
          v25.Message.pNode = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
          v16.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
          v15 = v.value.VS._1;
          v26 = v.value;
          if ( (v.Flags & 0x1F) > 9 )
          {
            if ( (v.Flags & 0x200) != 0 )
            {
              ++v.Bonus.pWeakProxy->RefCount;
            }
            else if ( (v.Flags & 0x1F) == 10 )
            {
              ++v.value.VS._1.VStr->RefCount;
            }
            else if ( (v.Flags & 0x1F) > 0xA )
            {
              if ( (v.Flags & 0x1F) <= 0xF )
              {
                if ( v.value.VS._1.VStr )
                {
                  ++v.value.VS._1.VStr->Size;
                  v15.VStr->Size &= 0x8FBFFFFF;
                }
              }
              else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
              {
                ++v.value.VS._2.VObj->RefCount;
                v16.VObj->RefCount &= 0x8FBFFFFF;
              }
            }
          }
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
            this,
            &value,
            &ptr_24.ArgObject,
            (Scaleform::GFx::AS3::Value *)&v25,
            arg_count,
            argv,
            0);
          if ( (v25.ID & 0x1Fu) > 9 )
          {
            if ( (v25.ID & 0x200) != 0 )
            {
              v12 = LODWORD(v25.Message.pNode->pData)-- == 1;
              if ( v12 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              v25.Message.pNode = 0i64;
              v26 = 0ui64;
              v25.ID &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v25);
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags & 0x200) != 0 )
            {
              v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v12 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&value.Bonus, 0, 24);
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (result.This.Flags & 0x1F) <= 9 )
            goto LABEL_56;
          if ( (result.This.Flags & 0x200) != 0 )
          {
            v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_54:
            memset(&result.This.Bonus, 0, 24);
            result.This.Flags &= 0xFFFFFDE0;
LABEL_56:
            Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject(&ptr_24);
            return;
          }
          goto LABEL_55;
        }
        Scaleform::GFx::AS3::VM::Error::Error(&v25, 1006, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v18 = v25.Message.pNode;
        v12 = v25.Message.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
    }
    else
    {
      if ( (Scaleform::GFx::AS3::VM::GetValueTraits(this, &ptr_24.ArgObject)->Flags & 2) == 0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v25, 1069, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v21, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v22 = v25.Message.pNode;
        v12 = v25.Message.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        if ( (result.This.Flags & 0x1F) <= 9 )
          goto LABEL_56;
        if ( (result.This.Flags & 0x200) != 0 )
        {
          v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&result.This.Bonus, 0, 24);
            result.This.Flags &= 0xFFFFFDE0;
            goto LABEL_56;
          }
          goto LABEL_54;
        }
LABEL_55:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_56;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v25, 1006, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v19, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v20 = v25.Message.pNode;
      v12 = v25.Message.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags & 0x200) != 0 )
      {
        v12 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.This.Bonus, 0, 24);
        result.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
  }
  if ( (ptr_24.ArgObject.Flags & 0x1F) > 9 )
  {
    if ( (ptr_24.ArgObject.Flags & 0x200) != 0 )
    {
      v12 = ptr_24.ArgObject.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&ptr_24.ArgObject.Bonus, 0, 24);
      ptr_24.ArgObject.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr_24.ArgObject);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&ptr_24.ArgMN);
  p_CallArgs = &ptr_24.CallArgs;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    ptr_24.CallArgs.Data.Data,
    ptr_24.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr_24.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr_24.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2912
// RVA: 0x839E80
void __fastcall Scaleform::GFx::AS3::VM::exec_callmethod(
        Scaleform::GFx::AS3::VM *this,
        int method_index,
        unsigned int arg_count)
{
  int v5; // ecx
  bool v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v12; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-A8h] BYREF
  __int128 v14[2]; // [rsp+188h] [rbp+90h] BYREF
  Scaleform::GFx::AS3::Value::V2U *retaddr; // [rsp+1B8h] [rbp+C0h]

  v12 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  LODWORD(ptr.CallArgs.Data.pHeap) = ptr.OpStack->pCurrent->Flags;
  *(_QWORD *)&v14[0] = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  *(Scaleform::GFx::AS3::Value::VU *)((char *)v14 + 8) = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v5 = (__int64)ptr.CallArgs.Data.pHeap & 0x1F;
  if ( ((__int64)ptr.CallArgs.Data.pHeap & 0x1F) == 0
    || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*((_QWORD *)&v14[0] + 1) )
  {
    v6 = ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*((_QWORD *)&v14[0] + 1);
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1010 - v6, ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v11.Message.pNode;
    v9 = v11.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.pHeap);
    Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
      this,
      method_index,
      ValueTraits,
      (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.pHeap);
  }
  if ( (unsigned __int64)((__int64)ptr.CallArgs.Data.pHeap & 0x1F) > 9 )
  {
    if ( ((__int64)ptr.CallArgs.Data.pHeap & 0x200) != 0 )
    {
      v9 = (**(_DWORD **)&v14[0])-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(v14, 0, 24);
      LODWORD(ptr.CallArgs.Data.pHeap) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.pHeap);
    }
  }
  retaddr = &ptr.FixedArr[7].value.VS._2;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
    (unsigned __int64)ptr.CallArgs.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2940
// RVA: 0x83C8D0
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupermethod(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Traits *ot,
        int method_index,
        unsigned int arg_count)
{
  int v7; // ecx
  bool v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Traits *pObject; // r8
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::AS3::VM *ptr; // [rsp+40h] [rbp-A8h] BYREF
  unsigned int **ptr_8; // [rsp+48h] [rbp-A0h]
  Scaleform::GFx::AS3::ReadArgs ptr_24; // [rsp+58h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::Value *ptr_256[4]; // [rsp+140h] [rbp+58h] BYREF
  Scaleform::GFx::AS3::Value ptr_288; // [rsp+160h] [rbp+78h] BYREF
  __int64 v21; // [rsp+188h] [rbp+A0h]
  Scaleform::GFx::AS3::Value **v22; // [rsp+1B8h] [rbp+D0h]

  v21 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, this, arg_count);
  ptr_288.Flags = **ptr_8;
  ptr_288.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*ptr_8 + 1);
  ptr_288.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*ptr_8 + 1);
  *ptr_8 -= 8;
  v7 = ptr_288.Flags & 0x1F;
  if ( (ptr_288.Flags & 0x1F) == 0 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !ptr_288.value.VS._1.VStr )
  {
    v8 = ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !ptr_288.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1010 - v8, ptr);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v15.Message.pNode;
    v11 = v15.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->HandleException )
  {
    if ( (ptr_288.Flags & 0x1F) <= 9 )
      goto LABEL_36;
    if ( (ptr_288.Flags & 0x200) == 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr_288);
      goto LABEL_36;
    }
    v11 = ptr_288.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v11 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    goto LABEL_27;
  }
  pObject = ot->pParent.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(this, method_index, pObject, &ptr_288);
    if ( (ptr_288.Flags & 0x1F) <= 9 )
      goto LABEL_36;
    if ( (ptr_288.Flags & 0x200) == 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr_288);
      goto LABEL_36;
    }
    v11 = ptr_288.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v11 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    goto LABEL_27;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v15, 1035, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  v14 = v15.Message.pNode;
  v11 = v15.Message.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (ptr_288.Flags & 0x1F) > 9 )
  {
    if ( (ptr_288.Flags & 0x200) == 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr_288);
      goto LABEL_36;
    }
    v11 = ptr_288.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v11 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_27:
    memset(&ptr_288.Bonus, 0, 24);
    ptr_288.Flags &= 0xFFFFFDE0;
  }
LABEL_36:
  v22 = ptr_256;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr_256[0], (unsigned __int64)ptr_256[1]);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr_256[0]);
  `eh vector destructor iterator(&ptr_24, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2972
// RVA: 0x839AA0
void __fastcall Scaleform::GFx::AS3::VM::exec_callgetter(
        Scaleform::GFx::AS3::VM *this,
        unsigned int method_index,
        unsigned int arg_count)
{
  __int64 v4; // rbx
  int v6; // ecx
  char v7; // al
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Value *v12; // rdx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::V1U v14; // rcx
  Scaleform::GFx::AS3::Value::V2U v15; // r8
  Scaleform::GFx::AS3::Value v16; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-88h] BYREF
  unsigned int **v18; // [rsp+80h] [rbp-68h]
  unsigned int v19; // [rsp+88h] [rbp-60h]
  char ptr[256]; // [rsp+90h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value *v21[4]; // [rsp+190h] [rbp+A8h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+1B0h] [rbp+C8h] BYREF
  Scaleform::GFx::AS3::Value **v23; // [rsp+1F8h] [rbp+110h]

  result.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)-2i64;
  v4 = method_index;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr, this, arg_count);
  v.Flags = **v18;
  v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*v18 + 1);
  v.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*v18 + 1);
  *v18 -= 8;
  v6 = v.Flags & 0x1F;
  if ( (v.Flags & 0x1F) == 0 || ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !v.value.VS._1.VStr )
  {
    if ( (unsigned int)(v6 - 12) > 3 && v6 != 10 || (v7 = 1, v.value.VS._1.VStr) )
      v7 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v16,
      1010 - (v7 != 0),
      (Scaleform::GFx::AS3::VM *)result.value.VS._2.VObj);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)result.value.VS._2.VObj,
      v8,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v16.Bonus.pWeakProxy;
    v10 = LODWORD(v16.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  if ( !this->HandleException )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &v);
    v12 = &Scaleform::GFx::AS3::Traits::GetVT(ValueTraits)->VTMethods.Data.Data[v4];
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, v12, &v, &result, 0, 0i64, 0);
    if ( !this->HandleException )
    {
      argv = (Scaleform::GFx::AS3::Value *)ptr;
      if ( v19 > 8 )
        argv = v21[0];
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        ::v.Flags = 0;
        ::v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v16.Flags = ::v.Flags;
      v16.Bonus.pWeakProxy = ::v.Bonus.pWeakProxy;
      v15.VObj = (Scaleform::GFx::AS3::Object *)::v.value.VS._2;
      v14 = ::v.value.VS._1;
      v16.value = ::v.value;
      if ( (::v.Flags & 0x1F) > 9 )
      {
        if ( (::v.Flags & 0x200) != 0 )
        {
          ++::v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (::v.Flags & 0x1F) == 10 )
        {
          ++::v.value.VS._1.VStr->RefCount;
        }
        else if ( (::v.Flags & 0x1F) > 0xA )
        {
          if ( (::v.Flags & 0x1F) <= 0xF )
          {
            if ( ::v.value.VS._1.VStr )
            {
              ++::v.value.VS._1.VStr->Size;
              v14.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (::v.Flags & 0x1F) <= 0x11 && ::v.value.VS._2.VObj )
          {
            ++::v.value.VS._2.VObj->RefCount;
            v15.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &result, &v, &v16, arg_count, argv, 1);
      if ( (v16.Flags & 0x1F) > 9 )
      {
        if ( (v16.Flags & 0x200) != 0 )
        {
          v10 = v16.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v16.Bonus, 0, 24);
          v16.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
        }
      }
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        v10 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.Bonus, 0, 24);
        result.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      v10 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  v23 = v21;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v21[0], (unsigned __int64)v21[1]);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21[0]);
  `eh vector destructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3008
// RVA: 0x83C230
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupergetter(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Traits *ot,
        int method_index,
        unsigned int arg_count)
{
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *argv; // rdi
  Scaleform::GFx::AS3::Value::VU value; // kr00_16
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::Value::V2U v20; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+88h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+1C0h] [rbp+D8h] BYREF
  __int64 v23; // [rsp+1E8h] [rbp+100h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_CallArgs; // [rsp+218h] [rbp+130h]

  v23 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr.FixedArr, this, arg_count);
  _this.Flags = ptr.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v8 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !_this.value.VS._1.VStr )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, _this.value.VS._1.VStr) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.Bonus, 1010 - (v9 != 0), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    VStr = result.value.VS._1.VStr;
    v12 = result.value.VS._1.VStr->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
  if ( this->HandleException )
    goto LABEL_76;
  pObject = ot->pParent.pObject;
  if ( pObject )
  {
    func.Flags = 7;
    func.Bonus.pWeakProxy = 0i64;
    func.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pObject;
    func.value.VS._1.VInt = method_index;
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &func, &_this, &result, 0, 0i64, 0);
    if ( !this->HandleException )
    {
      argv = ptr.FixedArr;
      if ( ptr.ArgNum > 8 )
        argv = ptr.CallArgs.Data.Data;
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      LODWORD(result.Bonus.pWeakProxy) = v.Flags;
      result.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
      value = v.value;
      v20.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            if ( v.value.VS._1.VStr )
            {
              ++v.value.VS._1.VStr->Size;
              value.VS._1.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            value.VS._2.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        this,
        &result,
        &_this,
        (Scaleform::GFx::AS3::Value *)&result.Bonus,
        arg_count,
        argv,
        1);
      if ( (unsigned __int64)((__int64)result.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( ((__int64)result.Bonus.pWeakProxy & 0x200) != 0 )
        {
          v12 = LODWORD(result.value.VS._1.VStr->pData)-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          result.value = 0ui64;
          v20.VObj = 0i64;
          LODWORD(result.Bonus.pWeakProxy) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&result.Bonus);
        }
      }
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          v12 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.Bonus, 0, 24);
          result.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags & 0x200) != 0 )
        {
          v12 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&func.Bonus, 0, 24);
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) <= 9 )
        goto LABEL_82;
      if ( (_this.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        goto LABEL_82;
      }
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_80;
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        v12 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.Bonus, 0, 24);
        result.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags & 0x200) != 0 )
      {
        v12 = func.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&func.Bonus, 0, 24);
        func.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
LABEL_76:
    if ( (_this.Flags & 0x1F) <= 9 )
    {
LABEL_82:
      p_CallArgs = &ptr.CallArgs;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        ptr.CallArgs.Data.Data,
        ptr.CallArgs.Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
      goto LABEL_83;
    }
    if ( (_this.Flags & 0x200) == 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      goto LABEL_82;
    }
    v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v12 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_80:
    memset(&_this.Bonus, 0, 24);
    _this.Flags &= 0xFFFFFDE0;
    goto LABEL_82;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.Bonus, 1035, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v14, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  v15 = result.value.VS._1.VStr;
  v12 = result.value.VS._1.VStr->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  p_CallArgs = &ptr.CallArgs;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
LABEL_83:
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3043
// RVA: 0x83B740
void __fastcall Scaleform::GFx::AS3::VM::exec_callstatic(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MiInd ind,
        unsigned int arg_count)
{
  int v7; // ecx
  char v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  __int64 MethodBodyInfoInd; // rbx
  Scaleform::GFx::AS3::Traits *pData; // rdi
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::Value::V2U v17; // rdx
  Scaleform::GFx::AS3::Value::V1U v18; // rcx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v24; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v30; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+218h] [rbp+118h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_CallArgs; // [rsp+280h] [rbp+180h] BYREF
  int v34; // [rsp+290h] [rbp+190h]

  v34 = ind.Ind;
  v30 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  _this.Flags = ptr.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v7 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !_this.value.VS._1.VStr )
  {
    if ( (unsigned int)(v7 - 12) > 3 && v7 != 10 || (v8 = 1, _this.value.VS._1.VStr) )
      v8 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v28, 1010 - (v8 != 0), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v28.Message.pNode;
    v11 = v28.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    MethodBodyInfoInd = file->File.pObject->Methods.Info.Data.Data[v34]->MethodBodyInfoInd;
    pData = (Scaleform::GFx::AS3::Traits *)_this.value.VS._1.VStr[1].pData;
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    if ( this->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v28, 1023, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v14, &Scaleform::GFx::AS3::fl::ErrorTI);
      v15 = v28.Message.pNode;
      v11 = v28.Message.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      *(_WORD *)&other.DiscardResult = 0;
      VMRef = file->VMRef;
      other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
      other.CP = 0i64;
      other.pRegisterFile = &VMRef->RegisterFile;
      other.pHeap = VMRef->MHeap;
      other.pFile = file;
      other.MBIIndex.Ind = MethodBodyInfoInd;
      other.pSavedScope = &pData->InitScope;
      other.OriginationTraits = pData;
      other.pScopeStack = &VMRef->ScopeStack;
      other.DefXMLNamespace.pObject = 0i64;
      other.Invoker.Flags = v.Flags;
      other.Invoker.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
      v17.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      v18 = v.value.VS._1;
      other.Invoker.value = v.value;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            if ( v.value.VS._1.VStr )
            {
              ++v.value.VS._1.VStr->Size;
              v18.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            v17.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      p_OpStack = &file->VMRef->OpStack;
      other.PrevInitialStackPos = p_OpStack->pCurrent;
      other.PrevFirstStackPos = p_OpStack->pStack;
      v20 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
      Scaleform::GFx::AS3::ValueStack::Reserve(p_OpStack, v20->max_stack + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v20->local_reg_count);
      p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
      if ( *p_DefXMLNamespace )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
          *p_DefXMLNamespace);
        p_CallArgs = 0i64;
        if ( &p_CallArgs != (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> **)p_DefXMLNamespace )
        {
          v22 = *p_DefXMLNamespace;
          if ( *p_DefXMLNamespace )
          {
            if ( ((unsigned __int8)v22 & 1) != 0 )
            {
              *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v22 - 1);
            }
            else
            {
              RefCount = v22->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v22->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
              }
            }
          }
          *p_DefXMLNamespace = 0i64;
        }
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &other,
        file->File.pObject->Methods.Info.Data.Data[file->File.pObject->MethodBodies.Info.Data.Data[MethodBodyInfoInd]->method_info_ind],
        &_this,
        arg_count);
      if ( this->HandleException )
      {
        other.ACopy = 1;
      }
      else
      {
        v24 = this->CallStack.Size >> 6;
        if ( v24 >= this->CallStack.NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
            &this->CallStack,
            this->CallStack.Size >> 6);
        Pages = this->CallStack.Pages;
        v26 = this->CallStack.Size & 0x3F;
        v11 = &Pages[v24][v26] == 0i64;
        v27 = &Pages[v24][v26];
        p_CallArgs = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v27;
        *(_QWORD *)&v28.ID = v27;
        if ( !v11 )
          Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
        ++this->CallStack.Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  p_CallArgs = &ptr.CallArgs;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3101
// RVA: 0x8438D0
void __fastcall Scaleform::GFx::AS3::VM::exec_newfunction(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf,
        unsigned int method_ind)
{
  Scaleform::GFx::AS3::CallFrame *v5; // r10
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos; // rsi
  Scaleform::GFx::AS3::Value *pRF; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v9; // rbp
  Scaleform::GFx::AS3::VMAbcFile *pFile; // r15
  Scaleform::GFx::AS3::Classes::Function **pObject; // r14
  Scaleform::GFx::AS3::Instances::Function *pV; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::Instances::Function *pCurrent; // rax
  Scaleform::GFx::AS3::Value v15; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> result; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::Function *v17; // [rsp+98h] [rbp+10h]

  if ( !this->CallStack.Size )
    goto LABEL_6;
  v5 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  pSavedScope = v5->pSavedScope;
  if ( pSavedScope->Data.Size )
  {
    gos = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pSavedScope->Data.Data->value.VS._1.VStr;
    goto LABEL_7;
  }
  pRF = v5->pRegisterFile->pRF;
  if ( (pRF->Flags & 0x1F) - 12 <= 3 )
    gos = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pRF->value.VS._1.VStr;
  else
LABEL_6:
    gos = 0i64;
LABEL_7:
  v9 = cf->pSavedScope;
  pFile = cf->pFile;
  pObject = (Scaleform::GFx::AS3::Classes::Function **)this->TraitsFunction.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::Function **))(*pObject)[1]._pRCC)(pObject);
  Scaleform::GFx::AS3::Classes::Function::MakeInstance(pObject[17], &result, pFile, method_ind, v9, gos);
  v15.Bonus.pWeakProxy = 0i64;
  v15.Flags = 14;
  pV = result.pV;
  v15.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)result.pV;
  v13 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = (Scaleform::GFx::AS3::Instances::Function *)this->OpStack.pCurrent;
  result.pV = pCurrent;
  v17 = pCurrent;
  if ( !v13 )
  {
    LODWORD(pCurrent->vfptr) = 14;
    pCurrent->pRCCRaw = 0i64;
    pCurrent->pNext = pV;
    pCurrent->pPrev = 0i64;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
}

// File Line: 3123
// RVA: 0x8396D0
void __fastcall Scaleform::GFx::AS3::VM::exec_call(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::V1U v10; // rcx
  Scaleform::GFx::AS3::Value::V2U v11; // r8
  Scaleform::GFx::AS3::Value v12; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v13; // [rsp+60h] [rbp-88h]
  unsigned int v14; // [rsp+68h] [rbp-80h]
  Scaleform::GFx::AS3::VM *ptr; // [rsp+70h] [rbp-78h] BYREF
  unsigned int **ptr_8; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::AS3::Value *ptr_256[4]; // [rsp+170h] [rbp+88h] BYREF
  Scaleform::GFx::AS3::Value ptr_288; // [rsp+190h] [rbp+A8h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+1B0h] [rbp+C8h] BYREF
  Scaleform::GFx::AS3::Value **v20; // [rsp+1F8h] [rbp+110h]

  v13 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, this, arg_count);
  ptr_288.Flags = **ptr_8;
  ptr_288.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*ptr_8 + 1);
  ptr_288.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*ptr_8 + 1);
  *ptr_8 -= 8;
  v4 = ptr_288.Flags & 0x1F;
  if ( (ptr_288.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !ptr_288.value.VS._1.VStr )
  {
    if ( (unsigned int)(v4 - 12) > 3 && v4 != 10 || (v5 = 1, ptr_288.value.VS._1.VStr) )
      v5 = 0;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v12, 1010 - (v5 != 0), ptr);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v12.Bonus.pWeakProxy;
    v8 = LODWORD(v12.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  func.Flags = **ptr_8;
  func.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*ptr_8 + 1);
  func.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*ptr_8 + 1);
  *ptr_8 -= 8;
  if ( !this->HandleException )
  {
    argv = (Scaleform::GFx::AS3::Value *)&ptr;
    if ( v14 > 8 )
      argv = ptr_256[0];
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v12.Flags = v.Flags;
    v12.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v11.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
    v10 = v.value.VS._1;
    v12.value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
      }
      else if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          if ( v.value.VS._1.VStr )
          {
            ++v.value.VS._1.VStr->Size;
            v10.VStr->Size &= 0x8FBFFFFF;
          }
        }
        else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
        {
          ++v.value.VS._2.VObj->RefCount;
          v11.VObj->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &func, &ptr_288, &v12, arg_count, argv, 1);
    if ( (v12.Flags & 0x1F) > 9 )
    {
      if ( (v12.Flags & 0x200) != 0 )
      {
        v8 = v12.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v12.Bonus, 0, 24);
        v12.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
      }
    }
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
    {
      v8 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&func.Bonus, 0, 24);
      func.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
    }
  }
  if ( (ptr_288.Flags & 0x1F) > 9 )
  {
    if ( (ptr_288.Flags & 0x200) != 0 )
    {
      v8 = ptr_288.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&ptr_288.Bonus, 0, 24);
      ptr_288.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ptr_288);
    }
  }
  v20 = ptr_256;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr_256[0], (unsigned __int64)ptr_256[1]);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr_256[0]);
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3140
// RVA: 0x83A090
void __fastcall Scaleform::GFx::AS3::VM::exec_callobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value *pCurrent; // r9
  int v5; // r8d
  bool v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 v10; // r8
  Scaleform::GFx::AS3::Value::V1U v11; // rdi
  Scaleform::GFx::AS3::Value *FixedArr; // rbx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-168h] BYREF
  __int64 v14; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-148h] BYREF
  Scaleform::GFx::AS3::Value *v16; // [rsp+188h] [rbp-10h]

  v14 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  pCurrent = ptr.OpStack->pCurrent;
  v16 = pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    v6 = ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v6, ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    if ( v13.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    v10 = (__int64)v16;
    v11 = v16->value.VS._1;
    FixedArr = ptr.FixedArr;
    if ( ptr.ArgNum > 8 )
      FixedArr = ptr.CallArgs.Data.Data;
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      v10 = (__int64)v16;
    }
    (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, __int64, _QWORD, Scaleform::GFx::AS3::Value *))v11.VStr->pData
     + 9))(
      v11,
      &v,
      v10,
      arg_count,
      FixedArr);
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3156
// RVA: 0x83BC10
void __fastcall Scaleform::GFx::AS3::VM::exec_callsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value *v15; // rbx
  Scaleform::GFx::AS3::Value::V1U v16; // rcx
  Scaleform::GFx::AS3::Value::V2U v17; // r8
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value v19; // [rsp+60h] [rbp-88h] BYREF
  char ptr[256]; // [rsp+80h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::Value *v21; // [rsp+180h] [rbp+98h] BYREF
  unsigned __int64 v22; // [rsp+188h] [rbp+A0h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1A0h] [rbp+B8h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+1D0h] [rbp+E8h] BYREF
  __int64 v25; // [rsp+1F8h] [rbp+110h]
  Scaleform::GFx::AS3::CheckResult result[8]; // [rsp+228h] [rbp+140h] BYREF
  unsigned int argc; // [rsp+248h] [rbp+160h]

  v25 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr, file->VMRef, argc);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&v19.Bonus, &obj);
  _this.Flags = *(_DWORD *)v19.value.VS._1.VStr->pData;
  _this.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)v19.value.VS._1.VStr->pData + 1);
  _this.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)v19.value.VS._1.VStr->pData + 1);
  v19.value.VS._1.VStr->pData -= 32;
  v8 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !_this.value.VS._1.VStr )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, _this.value.VS._1.VStr) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&v19,
      1010 - (v9 != 0),
      (Scaleform::GFx::AS3::VM *)v19.Bonus.pWeakProxy);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v19.Bonus.pWeakProxy,
      v10,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v19.Bonus.pWeakProxy;
    v12 = LODWORD(v19.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  if ( !this->HandleException )
  {
    func.Flags = 0;
    func.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::GetSuperProperty(result, this, ot, &func, &_this, &obj)->Result )
    {
      v15 = (Scaleform::GFx::AS3::Value *)ptr;
      if ( LODWORD(v19.value.VS._2.VObj) > 8 )
        v15 = v21;
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v19.Flags = v.Flags;
      v19.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
      v17.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      v16 = v.value.VS._1;
      v19.value = v.value;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            if ( v.value.VS._1.VStr )
            {
              ++v.value.VS._1.VStr->Size;
              v16.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            v17.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this, &func, &_this, &v19, argc, v15, 1);
      if ( (v19.Flags & 0x1F) > 9 )
      {
        if ( (v19.Flags & 0x200) != 0 )
        {
          v12 = v19.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v19.Bonus, 0, 24);
          v19.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
        }
      }
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags & 0x200) != 0 )
        {
          v12 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&func.Bonus, 0, 24);
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) <= 9 )
        goto LABEL_69;
      if ( (_this.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        goto LABEL_69;
      }
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v19, 1070, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v14 = (Scaleform::GFx::ASStringNode *)v19.Bonus.pWeakProxy;
      v12 = LODWORD(v19.Bonus.pWeakProxy[1].pObject)-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags & 0x200) != 0 )
        {
          v12 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&func.Bonus, 0, 24);
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) <= 9 )
        goto LABEL_69;
      if ( (_this.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        goto LABEL_69;
      }
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    memset(&_this.Bonus, 0, 24);
    _this.Flags &= 0xFFFFFDE0;
LABEL_69:
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
    *(_QWORD *)&result[0].Result = &v21;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v21, v22);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
    goto LABEL_70;
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  *(_QWORD *)&result[0].Result = &v21;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v21, v22);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
LABEL_70:
  `eh vector destructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}rm::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
LABEL_70:
  `eh vector destructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);

// File Line: 3184
// RVA: 0x83CC40
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupervoid(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  unsigned int v9; // r15d
  int v10; // ecx
  char v11; // al
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::Value *v17; // rbx
  Scaleform::GFx::AS3::Value::V1U v18; // rcx
  Scaleform::GFx::AS3::Value::V2U v19; // r8
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value v21; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::StackReader ptr; // [rsp+80h] [rbp-80h] BYREF
  unsigned int v23; // [rsp+90h] [rbp-70h]
  char v24[232]; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::Value *p; // [rsp+198h] [rbp+98h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+1D0h] [rbp+D0h] BYREF
  __int128 v28[2]; // [rsp+1F0h] [rbp+F0h] BYREF
  __int64 v29; // [rsp+210h] [rbp+110h]
  Scaleform::GFx::AS3::Value **p_p; // [rsp+240h] [rbp+140h] BYREF

  v29 = -2i64;
  v9 = arg_count;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&obj.Name.Bonus, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&ptr, (Scaleform::GFx::AS3::Multiname *)&obj.Name.Bonus);
  LODWORD(_this.value.VS._2.VObj) = ptr.OpStack->pCurrent->Flags;
  *(_QWORD *)&v28[0] = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  *(Scaleform::GFx::AS3::Value::VU *)((char *)v28 + 8) = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v10 = (__int64)_this.value.VS._2.VObj & 0x1F;
  if ( ((__int64)_this.value.VS._2.VObj & 0x1F) == 0
    || ((unsigned int)(v10 - 12) <= 3 || v10 == 10) && !*((_QWORD *)&v28[0] + 1) )
  {
    if ( (unsigned int)(v10 - 12) > 3 && v10 != 10 || (v11 = 1, *((_QWORD *)&v28[0] + 1)) )
      v11 = 0;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v21, 1010 - (v11 != 0), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v21.Bonus.pWeakProxy;
    v14 = LODWORD(v21.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  if ( !this->HandleException )
  {
    func.Flags = 0;
    func.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::GetSuperProperty(
           (Scaleform::GFx::AS3::CheckResult *)&p_p,
           this,
           ot,
           &func,
           (Scaleform::GFx::AS3::Value *)&_this.value.VS._2,
           (Scaleform::GFx::AS3::Multiname *)&obj.Name.Bonus)->Result )
    {
      v17 = (Scaleform::GFx::AS3::Value *)v24;
      if ( v23 > 8 )
        v17 = p;
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v21.Flags = v.Flags;
      v21.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
      v19.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      v18 = v.value.VS._1;
      v21.value = v.value;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
        }
        else if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            if ( v.value.VS._1.VStr )
            {
              ++v.value.VS._1.VStr->Size;
              v18.VStr->Size &= 0x8FBFFFFF;
            }
          }
          else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            v19.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        this,
        &func,
        (Scaleform::GFx::AS3::Value *)&_this.value.VS._2,
        &v21,
        v9,
        v17,
        0);
      if ( (v21.Flags & 0x1F) > 9 )
      {
        if ( (v21.Flags & 0x200) != 0 )
        {
          v14 = v21.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v21.Bonus, 0, 24);
          v21.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
        }
      }
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags & 0x200) != 0 )
        {
          v14 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&func.Bonus, 0, 24);
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (unsigned __int64)((__int64)_this.value.VS._2.VObj & 0x1F) <= 9 )
        goto LABEL_69;
      if ( ((__int64)_this.value.VS._2.VObj & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.value.VS._2);
        goto LABEL_69;
      }
      v14 = (**(_DWORD **)&v28[0])-- == 1;
      if ( v14 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v21, 1070, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v15, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v16 = (Scaleform::GFx::ASStringNode *)v21.Bonus.pWeakProxy;
      v14 = LODWORD(v21.Bonus.pWeakProxy[1].pObject)-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags & 0x200) != 0 )
        {
          v14 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&func.Bonus, 0, 24);
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (unsigned __int64)((__int64)_this.value.VS._2.VObj & 0x1F) <= 9 )
        goto LABEL_69;
      if ( ((__int64)_this.value.VS._2.VObj & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.value.VS._2);
        goto LABEL_69;
      }
      v14 = (**(_DWORD **)&v28[0])-- == 1;
      if ( v14 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    memset(v28, 0, 24);
    LODWORD(_this.value.VS._2.VObj) &= 0xFFFFFDE0;
LABEL_69:
    Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&obj.Name.Bonus);
    p_p = &p;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(p, *(unsigned __int64 *)&obj.Kind);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p);
    goto LABEL_70;
  }
  if ( (unsigned __int64)((__int64)_this.value.VS._2.VObj & 0x1F) > 9 )
  {
    if ( ((__int64)_this.value.VS._2.VObj & 0x200) != 0 )
    {
      v14 = (**(_DWORD **)&v28[0])-- == 1;
      if ( v14 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(v28, 0, 24);
      LODWORD(_this.value.VS._2.VObj) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.value.VS._2);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&obj.Name.Bonus);
  p_p = &p;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(p, *(unsigned __int64 *)&obj.Kind);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p);
LABEL_70:
  `eh vector destructor iterator(v24, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3213
// RVA: 0x83D7E0
void __fastcall Scaleform::GFx::AS3::VM::exec_construct(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::MemoryHeap *pCurrent; // rcx
  int v5; // r8d
  bool v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  int v10; // ecx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::Value *FixedArr; // r9
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM::Error *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v19; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value::V2U *retaddr; // [rsp+198h] [rbp+A0h]

  v19 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  pCurrent = (Scaleform::MemoryHeap *)ptr.OpStack->pCurrent;
  ptr.CallArgs.Data.pHeap = pCurrent;
  v5 = (__int64)pCurrent->vfptr & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->pNext )
  {
    v6 = ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->pNext;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1010 - v6, ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v18.Message.pNode;
    v9 = v18.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->HandleException )
    goto LABEL_31;
  v10 = (__int64)ptr.CallArgs.Data.pHeap->vfptr & 0x1F;
  if ( !v10 || ((unsigned int)(v10 - 12) <= 3 || v10 == 10) && !ptr.CallArgs.Data.pHeap->pNext )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1009, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v16, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v17 = v18.Message.pNode;
    v9 = v18.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_31;
  }
  if ( v10 == 7 || v10 == 17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1064, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v15 = v18.Message.pNode;
    v9 = v18.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    goto LABEL_31;
  }
  if ( (unsigned int)(v10 - 12) > 3 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1115, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v18.Message.pNode;
    v9 = v18.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_31:
    retaddr = &ptr.FixedArr[7].value.VS._2;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
      (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
      (unsigned __int64)ptr.CallArgs.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
    goto LABEL_32;
  }
  FixedArr = ptr.FixedArr;
  if ( ptr.ArgNum > 8 )
    FixedArr = (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj;
  ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::MemoryHeap *, _QWORD, Scaleform::GFx::AS3::Value *, _BYTE))ptr.CallArgs.Data.pHeap->pNext->vfptr->Free)(
    ptr.CallArgs.Data.pHeap->pNext,
    ptr.CallArgs.Data.pHeap,
    arg_count,
    FixedArr,
    0);
  retaddr = &ptr.FixedArr[7].value.VS._2;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
    (unsigned __int64)ptr.CallArgs.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
LABEL_32:
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}    0x20ui

// File Line: 3251
// RVA: 0x83E3A0
void __fastcall Scaleform::GFx::AS3::VM::exec_constructsuper(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Traits *ot,
        unsigned int arg_count)
{
  int v6; // ecx
  bool v7; // al
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value *FixedArr; // rax
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v14; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::Value v16; // [rsp+188h] [rbp+88h] BYREF

  v14 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  v16.Flags = ptr.OpStack->pCurrent->Flags;
  v16.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v16.value = ptr.OpStack->pCurrent->value;
  --ptr.OpStack->pCurrent;
  v6 = v16.Flags & 0x1F;
  if ( (v16.Flags & 0x1F) == 0 || ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !v16.value.VS._1.VStr )
  {
    v7 = ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !v16.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v7, ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    v10 = v13.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    pObject = ot->pParent.pObject;
    if ( pObject )
    {
      FixedArr = ptr.FixedArr;
      if ( ptr.ArgNum > 8 )
        FixedArr = ptr.CallArgs.Data.Data;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))pObject->vfptr[4].ForEachChild_GC)(
        pObject,
        ot,
        &v16,
        arg_count,
        FixedArr);
    }
  }
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags & 0x200) != 0 )
    {
      v10 = v16.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v16.Bonus, 0, 24);
      v16.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3288
// RVA: 0x83DB00
void __fastcall Scaleform::GFx::AS3::VM::exec_constructprop(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value *v8; // rdx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v14; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  char *v16; // r9
  int v17; // ecx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  char *v20; // r9
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::FindPropAttr attr; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value value; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::AS3::PropRef result; // [rsp+50h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value **v30; // [rsp+80h] [rbp-68h]
  unsigned int v31; // [rsp+88h] [rbp-60h]
  char ptr[256]; // [rsp+90h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value *v33; // [rsp+190h] [rbp+A8h] BYREF
  unsigned __int64 v34; // [rsp+198h] [rbp+B0h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1B0h] [rbp+C8h] BYREF
  Scaleform::GFx::AS3::Value *scope; // [rsp+1E0h] [rbp+F8h]
  __int64 v37; // [rsp+1E8h] [rbp+100h]
  Scaleform::GFx::AS3::CheckResult v38[8]; // [rsp+218h] [rbp+130h] BYREF

  v37 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)ptr, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&result.This.value.VS._2, &obj);
  v8 = *v30;
  scope = v8;
  v9 = v8->Flags & 0x1F;
  if ( !v9 || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !v8->value.VS._1.VStr )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, v8->value.VS._1.VStr) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      1010 - (v10 != 0),
      (Scaleform::GFx::AS3::VM *)result.This.value.VS._2.VObj);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)result.This.value.VS._2.VObj,
      v11,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    VStr = result.This.value.VS._1.VStr;
    v13 = result.This.value.VS._1.VStr->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
  if ( this->HandleException )
    goto LABEL_89;
  if ( (obj.Kind & 3u) <= 1 )
  {
    v14 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, &obj, file->AppDomain.pObject);
    if ( v14 )
    {
      pObject = v14->ITraits.pObject;
      if ( !pObject->pConstructor.pObject )
        pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
      v16 = ptr;
      if ( v31 > 8 )
        v16 = (char *)v33;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, char *, _BYTE))pObject->pConstructor.pObject->Scaleform::GFx::AS3::Traits::vfptr[4].ForEachChild_GC)(
        pObject->pConstructor.pObject,
        scope,
        arg_count,
        v16,
        0);
LABEL_89:
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&v38[0].Result = &v33;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
      goto LABEL_90;
    }
  }
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&result, this, scope, &obj, FindGet);
  if ( (result.This.Flags & 0x1F) != 0
    && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v38, this, &value, valGet)->Result )
    {
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) > 9 )
      {
        if ( (result.This.Flags & 0x200) != 0 )
        {
          v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&result.This.Bonus, 0, 24);
          result.This.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        }
      }
      goto LABEL_89;
    }
    v17 = value.Flags & 0x1F;
    if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v17 - 12) > 3 && v17 != 10 || value.value.VS._1.VStr) )
    {
      if ( v17 == 7 || v17 == 17 )
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1064, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v21, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v22 = result.This.value.VS._1.VStr;
        v13 = result.This.value.VS._1.VStr->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        if ( (value.Flags & 0x1F) <= 9 )
          goto LABEL_79;
        if ( (value.Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          goto LABEL_79;
        }
        v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else if ( (unsigned int)(v17 - 12) <= 3 )
      {
        v20 = ptr;
        if ( v31 > 8 )
          v20 = (char *)v33;
        LOBYTE(attr) = 0;
        (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, _QWORD, char *, Scaleform::GFx::AS3::FindPropAttr))value.value.VS._1.VStr->pData
         + 12))(
          value.value.VS._1,
          scope,
          arg_count,
          v20,
          attr);
        if ( (value.Flags & 0x1F) <= 9 )
          goto LABEL_79;
        if ( (value.Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          goto LABEL_79;
        }
        v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1065, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v18, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v19 = result.This.value.VS._1.VStr;
        v13 = result.This.value.VS._1.VStr->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        if ( (value.Flags & 0x1F) <= 9 )
          goto LABEL_79;
        if ( (value.Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          goto LABEL_79;
        }
        v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1009, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v23, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v24 = result.This.value.VS._1.VStr;
      v13 = result.This.value.VS._1.VStr->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( (value.Flags & 0x1F) <= 9 )
        goto LABEL_79;
      if ( (value.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        goto LABEL_79;
      }
      v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    memset(&value.Bonus, 0, 24);
    value.Flags &= 0xFFFFFDE0;
LABEL_79:
    Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&result);
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
    *(_QWORD *)&v38[0].Result = &v33;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
    goto LABEL_90;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, 1069, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v25, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  v26 = result.This.value.VS._1.VStr;
  v13 = result.This.value.VS._1.VStr->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  *(_QWORD *)&v38[0].Result = &v33;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
LABEL_90:
  `eh vector destructor iterator(ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3360
// RVA: 0x83FF80
void __fastcall Scaleform::GFx::AS3::VM::exec_getdescendants(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  int v5; // ecx
  bool v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::Value::V1U v13; // rsi
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v14; // rax
  Scaleform::GFx::AS3::Value *v15; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::StackReader v20; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value *v22; // [rsp+80h] [rbp-18h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> result; // [rsp+A0h] [rbp+8h] BYREF

  v20.VMRef = file->VMRef;
  v20.OpStack = &v20.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v20, &obj);
  pCurrent = v20.OpStack->pCurrent;
  v22 = pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    v6 = ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 1010 - v6, v20.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v20.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    pObject = this->XMLSupport_.pObject;
    if ( pObject->Enabled )
    {
      if ( (v22->Flags & 0x1F) - 12 <= 3 && (v13 = v22->value.VS._1, v13.VStr) )
      {
        v14 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].~RefCountBaseGC<328>)(pObject);
        Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(&result, v14);
        Scaleform::GFx::AS3::Value::Pick(v22, result.pV);
        (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Multiname *))v13.VStr->pData
         + 7))(
          v13,
          result.pV,
          &obj);
      }
      else
      {
        v15 = this->OpStack.pCurrent;
        if ( (v15->Flags & 0x1F) > 9 )
        {
          if ( (v15->Flags & 0x200) != 0 )
          {
            pWeakProxy = v15->Bonus.pWeakProxy;
            v9 = pWeakProxy->RefCount-- == 1;
            if ( v9 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v15->Bonus.pWeakProxy = 0i64;
            v15->value.VS._1.VStr = 0i64;
            v15->value.VS._2.VObj = 0i64;
            v15->Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
          }
        }
        --this->OpStack.pCurrent;
        Scaleform::GFx::AS3::VM::Error::Error(&v19, 1016, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v18 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, 1001, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v12 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3401
// RVA: 0x843180
void __fastcall Scaleform::GFx::AS3::VM::exec_newcatch(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::Classes::fl::Catch **pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl::Catch *pV; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rax
  Scaleform::GFx::AS3::Value::V2U v10; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> result; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Value *v13; // [rsp+98h] [rbp+20h]

  pObject = (Scaleform::GFx::AS3::Classes::fl::Catch **)this->TraitsCatch.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::Catch **))(*pObject)[1]._pRCC)(pObject);
  pV = Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstance(pObject[17], &result, file, e)->pV;
  v11.Bonus.pWeakProxy = 0i64;
  v11.Flags = 12;
  v11.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pV;
  v11.value.VS._2 = v10;
  v8 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = this->OpStack.pCurrent;
  v13 = pCurrent;
  if ( !v8 )
  {
    pCurrent->Flags = 12;
    pCurrent->Bonus.pWeakProxy = 0i64;
    pCurrent->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pV;
    pCurrent->value.VS._2 = v10;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
}

// File Line: 3412
// RVA: 0x7D3980
void __fastcall Scaleform::GFx::AS3::VM::FindProperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned __int64 ScopeStackBaseInd; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *RegisteredClassTraits; // rax

  if ( this->CallStack.Size )
    ScopeStackBaseInd = this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0i64;
  Scaleform::GFx::AS3::FindScopeProperty(result, this, ScopeStackBaseInd, &this->ScopeStack, mn);
  if ( ((result->This.Flags & 0x1F) == 0
     || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
     || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0)
    && ss->Data.Size )
  {
    Scaleform::GFx::AS3::FindScopeProperty(result, this, 0i64, ss, mn);
  }
  if ( (result->This.Flags & 0x1F) == 0
    || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(this, mn, appDomain);
    Scaleform::GFx::AS3::FindGOProperty(result, this, &this->GlobalObjects, mn, RegisteredClassTraits);
  }
}

// File Line: 3437
// RVA: 0x83F9F0
void __fastcall Scaleform::GFx::AS3::VM::exec_findpropstrict(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  bool v7; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::StackReader v13; // [rsp+48h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+88h] [rbp+27h] BYREF
  __int64 v16; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::AS3::Value *v17; // [rsp+C8h] [rbp+67h]
  Scaleform::GFx::AS3::Value *vars0; // [rsp+D0h] [rbp+6Fh]

  v16 = -2i64;
  v13.VMRef = file->VMRef;
  v13.OpStack = &v13.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v13, &obj);
  if ( !this->HandleException )
  {
    memset(&result, 0, 20);
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::FindProperty(this, &result, &obj, ss, file->AppDomain.pObject);
    if ( (result.This.Flags & 0x1F) != 0
      && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      v7 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
      pCurrent = this->OpStack.pCurrent;
      v17 = pCurrent;
      vars0 = pCurrent;
      if ( v7 )
        goto LABEL_20;
      pCurrent->Flags = result.This.Flags;
      pCurrent->Bonus.pWeakProxy = result.This.Bonus.pWeakProxy;
      pCurrent->value = result.This.value;
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_20;
      if ( (result.This.Flags & 0x200) != 0 )
      {
        ++result.This.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (result.This.Flags & 0x1F) == 10 )
        {
          ++result.This.value.VS._1.VStr->RefCount;
          goto LABEL_20;
        }
        if ( (result.This.Flags & 0x1F) > 0xA )
        {
          if ( (result.This.Flags & 0x1F) <= 0xF )
          {
            VObj = result.This.value.VS._1;
          }
          else
          {
            if ( (result.This.Flags & 0x1F) > 0x11 )
              goto LABEL_20;
            VObj = (Scaleform::GFx::AS3::Value::V1U)result.This.value.VS._2.VObj;
          }
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
        }
      }
LABEL_20:
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_35;
      if ( (result.This.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_35;
      }
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_33:
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
      goto LABEL_35;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1065, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v10, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v15.Message.pNode;
    v7 = v15.Message.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags & 0x200) == 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_35;
      }
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_33;
    }
  }
LABEL_35:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3466
// RVA: 0x83F5D0
void __fastcall Scaleform::GFx::AS3::VM::exec_findproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  bool v7; // zf
  Scaleform::GFx::AS3::Value *v8; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value v12; // [rsp+48h] [rbp-31h] BYREF
  __int64 v13; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::AS3::StackReader v14; // [rsp+78h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+88h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Value *v16; // [rsp+D8h] [rbp+5Fh]
  Scaleform::GFx::AS3::Value *vars0; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS3::Value::V1U v18; // [rsp+F8h] [rbp+7Fh]

  v13 = -2i64;
  v14.VMRef = file->VMRef;
  v14.OpStack = &v14.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v14, &obj);
  if ( this->HandleException )
    goto LABEL_33;
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::FindProperty(this, &result, &obj, ss, file->AppDomain.pObject);
  if ( (result.This.Flags & 0x1F) == 0
    || ((__int64)result.pSI & 1) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)result.pSI & 2) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    v12.Flags = 12;
    v12.Bonus.pWeakProxy = 0i64;
    v12.value.VS._1 = v18;
    if ( v18.VStr )
      v18.VStr->Size = (v18.VStr->Size + 1) & 0x8FBFFFFF;
    v7 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    pCurrent = this->OpStack.pCurrent;
    v16 = pCurrent;
    vars0 = pCurrent;
    if ( !v7 )
    {
      pCurrent->Flags = 12;
      pCurrent->Bonus.pWeakProxy = 0i64;
      pCurrent->value.VS._1 = v18;
      pCurrent->value.VS._2.VObj = v12.value.VS._2.VObj;
      if ( v18.VStr )
        v18.VStr->Size = (v18.VStr->Size + 1) & 0x8FBFFFFF;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v12);
    goto LABEL_27;
  }
  v7 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  v8 = this->OpStack.pCurrent;
  v16 = v8;
  vars0 = v8;
  if ( !v7 )
  {
    v8->Flags = result.This.Flags;
    v8->Bonus.pWeakProxy = result.This.Bonus.pWeakProxy;
    v8->value = result.This.value;
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags & 0x200) != 0 )
      {
        ++result.This.Bonus.pWeakProxy->RefCount;
        goto LABEL_27;
      }
      if ( (result.This.Flags & 0x1F) == 10 )
      {
        ++result.This.value.VS._1.VStr->RefCount;
      }
      else if ( (result.This.Flags & 0x1F) > 0xA )
      {
        if ( (result.This.Flags & 0x1F) <= 0xF )
        {
          VObj = result.This.value.VS._1;
LABEL_17:
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
          goto LABEL_27;
        }
        if ( (result.This.Flags & 0x1F) <= 0x11 )
        {
          VObj = (Scaleform::GFx::AS3::Value::V1U)result.This.value.VS._2.VObj;
          goto LABEL_17;
        }
      }
    }
  }
LABEL_27:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_33:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3504
// RVA: 0x840510
void __fastcall Scaleform::GFx::AS3::VM::exec_getlex(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // ecx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Multiname *v11; // rax
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Multiname v16; // [rsp+48h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+78h] [rbp+27h] BYREF
  __int64 v18; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // [rsp+C8h] [rbp+77h] BYREF

  v18 = -2i64;
  Kind = mn->Kind;
  if ( (Kind & 3) == 1 && (Kind & 4) == 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, 1078, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&v16, file, mn);
  Scaleform::GFx::AS3::VM::FindProperty(this, &result, v11, ss, file->AppDomain.pObject);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v16);
  if ( (result.This.Flags & 0x1F) == 0
    || ((__int64)result.pSI & 1) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)result.pSI & 2) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, 1069, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v14 = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    goto LABEL_29;
  }
  v16.Kind = MN_QName;
  v16.Obj.pObject = 0i64;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
         &result,
         (Scaleform::GFx::AS3::CheckResult *)&p_OpStack,
         this,
         (Scaleform::GFx::AS3::Value *)&v16,
         valGet)->Result )
  {
    p_OpStack = &this->OpStack;
    v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    pCurrent = this->OpStack.pCurrent;
    *(_QWORD *)&v17.ID = pCurrent;
    if ( !v10 )
    {
      pCurrent->Flags = v16.Kind;
      pCurrent->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v16.Obj.pObject;
      pCurrent->value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)&v16.Name.Flags;
      pCurrent->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v16.Name.Bonus.pWeakProxy;
      v16.Kind = MN_QName;
    }
    if ( (v16.Kind & 0x1Fu) <= 9 )
      goto LABEL_29;
    if ( (v16.Kind & 0x200) != 0 )
    {
      v10 = LODWORD(v16.Obj.pObject->vfptr)-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_15;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v16);
  }
  else if ( (v16.Kind & 0x1Fu) > 9 )
  {
    if ( (v16.Kind & 0x200) != 0 )
    {
      v10 = LODWORD(v16.Obj.pObject->vfptr)-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_15:
      memset(&v16.Obj, 0, 24);
      v16.Kind &= 0xFFFFFDE0;
      goto LABEL_29;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v16);
  }
LABEL_29:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v10 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.This.Flags &= 0xFFFFFDE0;
      memset(&result.This.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
}

// File Line: 3575
// RVA: 0x840A80
void __fastcall Scaleform::GFx::AS3::VM::exec_getproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  int v5; // ecx
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Value _this; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+38h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::StackReader v16; // [rsp+48h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value *value; // [rsp+88h] [rbp+27h]
  __int64 v19; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+67h] BYREF

  v19 = -2i64;
  v16.VMRef = file->VMRef;
  v16.OpStack = &v16.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v16, &obj);
  pCurrent = v16.OpStack->pCurrent;
  value = pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, pCurrent->value.VS._1.VStr) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1010 - (v6 != 0), v16.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v16.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v15.Message.pNode;
    v9 = v15.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->HandleException )
    goto LABEL_37;
  Flags = value->Flags;
  _this.Flags = value->Flags;
  pWeakProxy = value->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = pWeakProxy;
  _this.value = value->value;
  value->Flags = 0;
  if ( !Scaleform::GFx::AS3::GetPropertyUnsafe(&result, this, &_this, &obj, value)->Result )
  {
    if ( this->HandleException )
    {
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          v9 = pWeakProxy->RefCount-- == 1;
          if ( v9 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
LABEL_35:
          memset(&_this.Bonus, 0, 24);
          _this.Flags = Flags & 0xFFFFFDE0;
          goto LABEL_37;
        }
        goto LABEL_36;
      }
      goto LABEL_37;
    }
    if ( (Flags & 0x1F) <= 4 || (Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, 1069, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v13 = v15.Message.pNode;
      v9 = v15.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) == 0 )
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          goto LABEL_37;
        }
        v9 = pWeakProxy->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        goto LABEL_35;
      }
      goto LABEL_37;
    }
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v9 = pWeakProxy->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      goto LABEL_35;
    }
LABEL_36:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
LABEL_37:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3606
// RVA: 0x842700
void __fastcall Scaleform::GFx::AS3::VM::exec_initproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  int v4; // ecx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::StackReader v9; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+90h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+B0h] [rbp+37h] BYREF
  __int64 v14; // [rsp+C0h] [rbp+47h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::VM *v16; // [rsp+E8h] [rbp+6Fh]

  v14 = -2i64;
  v9.VMRef = file->VMRef;
  v9.OpStack = &v9.VMRef->OpStack;
  value.Flags = v9.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v9.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v9.VMRef->OpStack.pCurrent->value;
  --v9.VMRef->OpStack.pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v9, &obj);
  _this.Flags = v9.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v9.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v9.OpStack->pCurrent->value;
  --v9.OpStack->pCurrent;
  v4 = _this.Flags & 0x1F;
  if ( (_this.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !_this.value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !_this.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v5, v9.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    v16 = this;
    ++this->InInitializer;
    Scaleform::GFx::AS3::SetProperty(&result, this, &_this, &obj, &value);
    --this->InInitializer;
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

// File Line: 3621
// RVA: 0x83E940
void __fastcall Scaleform::GFx::AS3::VM::exec_deleteproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  int v5; // ecx
  bool v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  char v10; // r10
  const char *pData; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Value *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::ASStringNode *VStr; // r9
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+28h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::StackReader v20; // [rsp+40h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::Multiname obj; // [rsp+50h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value *v22; // [rsp+80h] [rbp+47h]
  char v23; // [rsp+A0h] [rbp+67h] BYREF

  v20.VMRef = file->VMRef;
  v20.OpStack = &v20.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v20, &obj);
  pCurrent = v20.OpStack->pCurrent;
  v22 = pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    v6 = ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, 1010 - v6, v20.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v20.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    v10 = 0;
    if ( this->XMLSupport_.pObject->Enabled
      && (obj.Name.Flags & 0x1F) - 12 <= 3
      && obj.Name.value.VS._1.VStr
      && (pData = obj.Name.value.VS._1.VStr[1].pData, *((_DWORD *)pData + 30) == 19)
      && (pData[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, 1119, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v13 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    else
    {
      v14 = v22;
      v15 = v22->Flags & 0x1F;
      if ( v15 <= 4 || v15 == 10 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v19, 1120, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v17, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v18 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      else
      {
        if ( v15 - 12 > 3 )
          goto LABEL_27;
        VStr = v22->value.VS._1.VStr;
        if ( (VStr[1].pData[112] & 2) != 0 )
        {
          v10 = *(_BYTE *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, char *, Scaleform::GFx::AS3::Multiname *))VStr->pData
                           + 8))(
                            v22->value.VS._1,
                            &v23,
                            &obj);
          v14 = v22;
        }
        if ( !this->HandleException )
LABEL_27:
          Scaleform::GFx::AS3::Value::SetBool(v14, v10);
      }
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3674
// RVA: 0x841280
void __fastcall Scaleform::GFx::AS3::VM::exec_getslot(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SlotIndex slot_index)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rsi
  int v5; // r8d
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v9; // zf
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *v11; // rbx
  Scaleform::GFx::AS3::Object *VObj; // rcx
  Scaleform::GFx::AS3::Value v13[2]; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+70h] [rbp+8h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, pCurrent->value.VS._1.VStr) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)v13, 1010 - (v6 != 0), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v13[0].Bonus.pWeakProxy;
    v9 = LODWORD(v13[0].Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  if ( !this->HandleException )
  {
    v13[0].Flags = pCurrent->Flags;
    Flags = v13[0].Flags;
    v11 = pCurrent->Bonus.pWeakProxy;
    v13[0].Bonus.pWeakProxy = v11;
    v13[0].value = pCurrent->value;
    VObj = v13[0].value.VS._1.VObj;
    pCurrent->Flags = 0;
    Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(VObj, &result, slot_index, pCurrent);
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v9 = v11->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        v13[0].Bonus.pWeakProxy = 0i64;
        v13[0].value = 0ui64;
        v13[0].Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
      }
    }
  }
}

// File Line: 3689
// RVA: 0x846410
void __fastcall Scaleform::GFx::AS3::VM::exec_setabsslot(Scaleform::GFx::AS3::VM *this, unsigned __int64 slot_ind)
{
  int v4; // ecx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+30h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+48h] [rbp+7h]
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // [rsp+50h] [rbp+Fh]
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value v13; // [rsp+78h] [rbp+37h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+67h] BYREF

  vm = this;
  p_OpStack = &this->OpStack;
  v.Flags = this->OpStack.pCurrent->Flags;
  v.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  v.value = this->OpStack.pCurrent->value;
  --this->OpStack.pCurrent;
  v13.Flags = p_OpStack->pCurrent->Flags;
  v13.Bonus.pWeakProxy = p_OpStack->pCurrent->Bonus.pWeakProxy;
  v13.value = p_OpStack->pCurrent->value;
  --p_OpStack->pCurrent;
  v4 = v13.Flags & 0x1F;
  if ( (v13.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v13.value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v13.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1010 - v5, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v9.Message.pNode;
    v8 = v9.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      (Scaleform::GFx::AS3::Traits *)v13.value.VS._1.VStr[1].pData,
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      (Scaleform::GFx::AS3::AbsoluteIndex)(slot_ind - 1),
      &v);
  if ( (v13.Flags & 0x1F) > 9 )
  {
    if ( (v13.Flags & 0x200) != 0 )
    {
      v8 = v13.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v13.Bonus, 0, 24);
      v13.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 3707
// RVA: 0x842520
void __fastcall Scaleform::GFx::AS3::VM::exec_initabsslot(Scaleform::GFx::AS3::VM *this, unsigned __int64 slot_ind)
{
  int v4; // ecx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+30h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+48h] [rbp+7h]
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // [rsp+50h] [rbp+Fh]
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value v14; // [rsp+78h] [rbp+37h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+67h] BYREF

  vm = this;
  p_OpStack = &this->OpStack;
  v.Flags = this->OpStack.pCurrent->Flags;
  v.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  v.value = this->OpStack.pCurrent->value;
  --this->OpStack.pCurrent;
  v14.Flags = p_OpStack->pCurrent->Flags;
  v14.Bonus.pWeakProxy = p_OpStack->pCurrent->Bonus.pWeakProxy;
  v14.value = p_OpStack->pCurrent->value;
  --p_OpStack->pCurrent;
  v4 = v14.Flags & 0x1F;
  if ( (v14.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v14.value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v14.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1010 - v5, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v10.Message.pNode;
    v8 = v10.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
  {
    v9 = v14.value.VS._1;
    ++this->InInitializer;
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      (Scaleform::GFx::AS3::Traits *)v9.VStr[1].pData,
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      (Scaleform::GFx::AS3::AbsoluteIndex)(slot_ind - 1),
      &v);
    --this->InInitializer;
  }
  if ( (v14.Flags & 0x1F) > 9 )
  {
    if ( (v14.Flags & 0x200) != 0 )
    {
      v8 = v14.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v14.Bonus, 0, 24);
      v14.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      v8 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 3727
// RVA: 0x846C80
void __fastcall Scaleform::GFx::AS3::VM::exec_setslot(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SlotIndex slot_index)
{
  int v4; // ecx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+38h] [rbp+7h]
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::Value v13; // [rsp+68h] [rbp+37h] BYREF
  void *retaddr; // [rsp+98h] [rbp+67h] BYREF

  vm = this;
  p_OpStack = &this->OpStack;
  value.Flags = this->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = this->OpStack.pCurrent->value;
  --this->OpStack.pCurrent;
  v13.Flags = p_OpStack->pCurrent->Flags;
  v13.Bonus.pWeakProxy = p_OpStack->pCurrent->Bonus.pWeakProxy;
  v13.value = p_OpStack->pCurrent->value;
  --p_OpStack->pCurrent;
  v4 = v13.Flags & 0x1F;
  if ( (v13.Flags & 0x1F) == 0 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v13.value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !v13.value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1010 - v5, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v9.Message.pNode;
    v8 = v9.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( !this->HandleException )
    Scaleform::GFx::AS3::Object::SetSlotValue(
      v13.value.VS._1.VObj,
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      slot_index,
      &value);
  if ( (v13.Flags & 0x1F) > 9 )
  {
    if ( (v13.Flags & 0x200) != 0 )
    {
      v8 = v13.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v13.Bonus, 0, 24);
      v13.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    }
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

// File Line: 3740
// RVA: 0x83D310
void __fastcall Scaleform::GFx::AS3::VM::exec_coerce(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // r9d
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) != 1 || (Kind & 4) != 0 )
  {
    pCurrent = this->OpStack.pCurrent;
    v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v7 )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v7->vfptr[3].Finalize_GC)(
             v7,
             pCurrent,
             pCurrent) )
      {
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v12, 1034, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, 1069, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v9, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, 1078, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  pNode = v12.Message.pNode;
  if ( v12.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 3793
// RVA: 0x843B70
void __fastcall Scaleform::GFx::AS3::VM::exec_newobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value::V1U pV; // r14
  __int64 v5; // r12
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r14
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::Value *v8; // rax
  unsigned int v9; // edi
  Scaleform::GFx::AS3::WeakProxy *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rsi
  Scaleform::GFx::AS3::Value::V2U v12; // r15
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Value *pSecond; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v24; // rax
  unsigned int v25; // eax
  int v26; // [rsp+28h] [rbp-41h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-39h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-31h] BYREF
  unsigned int Flags; // [rsp+48h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // [rsp+50h] [rbp-19h]
  Scaleform::GFx::ASStringNode *VStr; // [rsp+58h] [rbp-11h]
  Scaleform::GFx::AS3::Value::V2U v32; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::AS3::Value v33; // [rsp+68h] [rbp-1h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v35; // [rsp+E0h] [rbp+77h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->TraitsObject.pObject->ITraits.pObject);
  pV = (Scaleform::GFx::AS3::Value::V1U)result.pV;
  if ( arg_count )
  {
    key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v26;
    key.pSecond = (Scaleform::GFx::AS3::Value *)&Flags;
    v5 = arg_count;
    p_DynAttrs = &result.pV->DynAttrs;
    do
    {
      pCurrent = this->OpStack.pCurrent;
      Flags = pCurrent->Flags;
      pWeakProxy = pCurrent->Bonus.pWeakProxy;
      VStr = pCurrent->value.VS._1.VStr;
      v32.VObj = (Scaleform::GFx::AS3::Object *)pCurrent->value.VS._2;
      this->OpStack.pCurrent = pCurrent - 1;
      v8 = this->OpStack.pCurrent;
      v9 = v8->Flags;
      v33.Flags = v8->Flags;
      v10 = v8->Bonus.pWeakProxy;
      v33.Bonus.pWeakProxy = v10;
      v11 = v8->value.VS._1.VStr;
      v33.value.VS._1.VStr = v11;
      v12.VObj = (Scaleform::GFx::AS3::Object *)v8->value.VS._2;
      v33.value.VS._2 = v12;
      this->OpStack.pCurrent = v8 - 1;
      v13 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v33, &v35);
      v26 = 0;
      pNode = v13->pNode;
      ++pNode->RefCount;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        &p_DynAttrs->mHash,
        p_DynAttrs,
        &key);
      v14 = pNode;
      v15 = pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v16 = v35.pNode;
      v15 = v35.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( (v9 & 0x1F) > 9 )
      {
        if ( (v9 & 0x200) != 0 )
        {
          v15 = v10->RefCount-- == 1;
          if ( v15 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
          memset(&v33.Bonus, 0, 24);
          v33.Flags = v9 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v9 & 0x1F )
          {
            case 0xAu:
              v15 = v11->RefCount-- == 1;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v11);
              break;
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
            case 0xFu:
              if ( v33.value.VS._1.VBool )
              {
                v33.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)v11 - 1);
              }
              else if ( v11 )
              {
                Size = v11->Size;
                if ( (Size & 0x3FFFFF) != 0 )
                {
                  v11->Size = Size - 1;
                  VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11;
                  goto LABEL_25;
                }
              }
              break;
            case 0x10u:
            case 0x11u:
              if ( ((__int64)v33.value.VS._2.VObj & 1) != 0 )
              {
                v33.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v12.VObj - 1);
              }
              else if ( v12.VObj )
              {
                RefCount = v12.VObj->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v12.VObj->RefCount = RefCount - 1;
                  VObj = v12.VObj;
LABEL_25:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          v15 = pWeakProxy->RefCount-- == 1;
          if ( v15 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          pWeakProxy = 0i64;
          VStr = 0i64;
          v32.VObj = 0i64;
          Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( Flags & 0x1F )
          {
            case 0xAu:
              v20 = VStr;
              v15 = VStr->RefCount-- == 1;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              break;
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
            case 0xFu:
              v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)VStr;
              if ( ((unsigned __int8)VStr & 1) == 0 )
                goto LABEL_38;
              VStr = (Scaleform::GFx::ASStringNode *)((char *)VStr - 1);
              break;
            case 0x10u:
            case 0x11u:
              v21 = v32.VObj;
              if ( ((__int64)v32.VObj & 1) != 0 )
              {
                --v32.VObj;
              }
              else
              {
LABEL_38:
                if ( v21 )
                {
                  v22 = v21->RefCount;
                  if ( (v22 & 0x3FFFFF) != 0 )
                  {
                    v21->RefCount = v22 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      --v5;
    }
    while ( v5 );
    pV = (Scaleform::GFx::AS3::Value::V1U)result.pV;
  }
  v33.Bonus.pWeakProxy = 0i64;
  v33.Flags = 12;
  v33.value.VS._1 = pV;
  pSecond = key.pSecond;
  v33.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
  v15 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  v24 = (Scaleform::GFx::AS3::Instances::fl::Object *)this->OpStack.pCurrent;
  result.pV = v24;
  v35.pNode = (Scaleform::GFx::ASStringNode *)v24;
  if ( !v15 )
  {
    LODWORD(v24->vfptr) = 12;
    v24->pRCCRaw = 0i64;
    v24->pNext = pV.VObj;
    v24->pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pSecond;
    if ( pV.VStr )
      pV.VStr->Size = (pV.VStr->Size + 1) & 0x8FBFFFFF;
  }
  if ( pV.VBool )
  {
    v33.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)pV.VStr - 1);
  }
  else if ( pV.VStr )
  {
    v25 = pV.VStr->Size;
    if ( (v25 & 0x3FFFFF) != 0 )
    {
      pV.VStr->Size = v25 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV.VObj);
    }
  }
}

// File Line: 3812
// RVA: 0x843460
void __fastcall Scaleform::GFx::AS3::VM::exec_newclass(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        unsigned int v)
{
  Scaleform::GFx::AS3::Abc::File *pObject; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v6; // rbx
  Scaleform::GFx::AS3::Value *pCurrent; // r12
  int v8; // r8d
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Abc::Multiname *v12; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v15; // di
  Scaleform::GFx::ASStringNode *v16; // rbx
  Scaleform::GFx::AS3::Value::V2U v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v18; // r15
  int v19; // esi
  const char *pData; // rax
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // bl
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::ClassTraits::UserDefined *UserDefinedTraits; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v28; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *Class; // rax
  Scaleform::GFx::AS3::Value v30; // [rsp+28h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Multiname v31; // [rsp+48h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v32; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+6Fh] BYREF
  char v34; // [rsp+E0h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v35; // [rsp+E8h] [rbp+7Fh] BYREF

  pObject = file->File.pObject;
  v6 = pObject->AS3_Classes.Info.Data.Data[v];
  pCurrent = this->OpStack.pCurrent;
  v8 = pCurrent->Flags & 0x1F;
  if ( v8 && ((unsigned int)(v8 - 12) > 3 && v8 != 10 || pCurrent->value.VS._1.VStr) )
  {
    if ( v8 != 13 )
      goto LABEL_8;
  }
  else if ( v6->inst_info.super_name_ind )
  {
LABEL_8:
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v30, 1009, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v30.Bonus.pWeakProxy;
LABEL_9:
    v11 = pWeakProxy->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    return;
  }
  v12 = &pObject->Const_Pool.const_multiname.Data.Data[v6->inst_info.name_ind];
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v12->Ind);
  pNode = InternedNamespace->Uri.pNode;
  if ( pNode->Size >= 0xD && !strncmp(pNode->pData, "scaleform.gfx", 0xDui64) )
  {
    Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, v12->NameIndex);
    v15 = 10;
    v30.Flags = 10;
    v30.Bonus.pWeakProxy = 0i64;
    v16 = result.pNode;
    *(Scaleform::GFx::ASString *)&v30.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
    if ( result.pNode == &result.pNode->pManager->NullStringNode )
    {
      v16 = 0i64;
      v30.value.VS._1.VStr = 0i64;
      v17.VObj = (Scaleform::GFx::AS3::Object *)v30.Bonus.pWeakProxy;
      v30.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v30.Bonus.pWeakProxy;
      v15 = 12;
      v30.Flags = 12;
    }
    else
    {
      ++result.pNode->RefCount;
      v17.VObj = (Scaleform::GFx::AS3::Object *)v30.value.VS._2;
    }
    v18 = this->GlobalObject.pObject;
    v31.Kind = MN_QName;
    v31.Obj.pObject = InternedNamespace;
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    v31.Name.Flags = 0;
    v31.Name.Bonus.pWeakProxy = 0i64;
    v19 = v15 & 0x1F;
    if ( (unsigned int)(v19 - 12) <= 3
      && v16
      && (pData = v16[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v31.Name, (Scaleform::GFx::ASString *)&v16[1].16);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v31.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v16[1].RefCount);
      v31.Kind &= 0xFFFFFFF9;
    }
    else
    {
      _mm_prefetch((const char *)&v30, 2);
      *(_QWORD *)&v31.Name.Flags = *(_QWORD *)&v30.Flags;
      v31.Name.Bonus.pWeakProxy = 0i64;
      v31.Name.value.VS._1.VStr = v16;
      v31.Name.value.VS._2 = v17;
      if ( (v15 & 0x1Fu) > 9 )
      {
        if ( v19 == 10 )
        {
          ++v16->RefCount;
        }
        else if ( (v15 & 0x1Fu) <= 0xF )
        {
          if ( v16 )
            v16->Size = (v16->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (v15 & 0x1Fu) <= 0x11 && v17.VObj )
        {
          v17.VObj->RefCount = (v17.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
      if ( (v31.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v31.Name, &v32);
        if ( v32.pNode->Size )
        {
          if ( *v32.pNode->pData == 64 )
          {
            v31.Kind |= 8u;
            v21 = Scaleform::GFx::ASString::Substring(&v32, &v35, 1, v32.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v31.Name, v21);
            v22 = v35.pNode;
            v11 = v35.pNode->RefCount-- == 1;
            if ( v11 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          }
        }
        v23 = v32.pNode;
        v11 = v32.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      }
    }
    v24 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, __int64))v18->vfptr[1].~RefCountBaseGC<328>)(
                      v18,
                      &v34,
                      &v31,
                      pCurrent,
                      -2i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v31);
    if ( (v15 & 0x1Fu) > 9 )
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v30);
    if ( v24 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v30, 1069, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v25, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v26 = (Scaleform::GFx::ASStringNode *)v30.Bonus.pWeakProxy;
      v11 = LODWORD(v30.Bonus.pWeakProxy[1].pObject)-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    }
    pWeakProxy = result.pNode;
    goto LABEL_9;
  }
  UserDefinedTraits = Scaleform::GFx::AS3::VM::GetUserDefinedTraits(this, file, v6);
  v28 = UserDefinedTraits->ITraits.pObject;
  if ( v28->pConstructor.pObject )
  {
    Scaleform::GFx::AS3::Value::Assign(pCurrent, v28->pConstructor.pObject);
  }
  else
  {
    Class = Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(
              UserDefinedTraits,
              (Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *)&v32);
    Scaleform::GFx::AS3::Value::Pick(pCurrent, Class->pV);
  }
}

// File Line: 3874
// RVA: 0x8391F0
void __fastcall Scaleform::GFx::AS3::VM::exec_astype(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // r9d
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v7; // rsi
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) != 1 || (Kind & 4) != 0 )
  {
    pCurrent = this->OpStack.pCurrent;
    v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v7 && v7 != Scaleform::GFx::AS3::VM::GetClassTraits(this, pCurrent) )
    {
      Scaleform::GFx::AS3::Value::SetNull(pCurrent);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1014, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 1078, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  pNode = v11.Message.pNode;
  if ( v11.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 3910
// RVA: 0x842900
void __fastcall Scaleform::GFx::AS3::VM::exec_instanceof(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  unsigned int Flags; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rbx
  int v5; // r13d
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // r15
  int v10; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rdi
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Traits *v13; // r14
  bool v14; // dl
  Scaleform::GFx::AS3::Object *i; // rbp
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-40h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v.Flags = pCurrent->Flags;
  Flags = v.Flags;
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  v.Bonus.pWeakProxy = pWeakProxy;
  v.value = pCurrent->value;
  this->OpStack.pCurrent = pCurrent - 1;
  v5 = Flags & 0x1F;
  if ( (unsigned int)(v5 - 13) <= 1 )
  {
    v9 = this->OpStack.pCurrent;
    v10 = v9->Flags & 0x1F;
    if ( v10 && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || v9->value.VS._1.VStr) )
    {
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this, v9);
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, &v);
      v13 = ValueTraits;
      if ( v5 == 13 )
      {
        if ( ClassTraits )
        {
          while ( ClassTraits != ValueTraits )
          {
            ClassTraits = (Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits->pParent.pObject;
            if ( !ClassTraits )
              goto LABEL_21;
          }
LABEL_13:
          v14 = 1;
LABEL_22:
          Scaleform::GFx::AS3::Value::SetBool(v9, v14);
          goto LABEL_23;
        }
      }
      else
      {
        if ( !ValueTraits->pConstructor.pObject )
          ValueTraits->vfptr[3].~RefCountBaseGC<328>(ValueTraits);
        for ( i = v13->pConstructor.pObject;
              ClassTraits;
              ClassTraits = (Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits->pParent.pObject )
        {
          if ( !ClassTraits->pConstructor.pObject )
            ClassTraits->vfptr[3].~RefCountBaseGC<328>(ClassTraits);
          if ( Scaleform::GFx::AS3::Class::GetPrototype(ClassTraits->pConstructor.pObject) == i )
            goto LABEL_13;
        }
      }
    }
LABEL_21:
    v14 = 0;
    goto LABEL_22;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v16, 1040, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v16.Message.pNode;
  v8 = v16.Message.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_23:
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v8 = pWeakProxy->RefCount-- == 1;
      if ( v8 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      v.Flags = Flags & 0xFFFFFDE0;
      memset(&v.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 3962
// RVA: 0x842B30
void __fastcall Scaleform::GFx::AS3::VM::exec_istype(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // r9d
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v9; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  char v11; // al
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) != 1 || (Kind & 4) != 0 )
  {
    pCurrent = this->OpStack.pCurrent;
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v9 )
    {
      v11 = Scaleform::GFx::AS3::VM::IsOfType(this, pCurrent, (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v9);
      Scaleform::GFx::AS3::Value::SetBool(pCurrent, v11);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v12, 1014, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, 1078, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  pNode = v12.Message.pNode;
  if ( v12.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 4039
// RVA: 0x8392C0
void __fastcall Scaleform::GFx::AS3::VM::exec_astypelate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rbx
  Scaleform::GFx::AS3::Value::V1U v5; // r8
  int v6; // r14d
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // rsi
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v15; // [rsp+38h] [rbp-28h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v15.Flags = pCurrent->Flags;
  Flags = v15.Flags;
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  v15.Bonus.pWeakProxy = pWeakProxy;
  v5 = pCurrent->value.VS._1;
  v15.value = pCurrent->value;
  this->OpStack.pCurrent = pCurrent - 1;
  v6 = Flags & 0x1F;
  if ( v6 == 13 )
  {
    v13 = this->OpStack.pCurrent;
    if ( !Scaleform::GFx::AS3::VM::IsOfType(this, v13, (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v5.VStr[1].pData) )
      Scaleform::GFx::AS3::Value::SetNull(v13);
LABEL_22:
    if ( (Flags & 0x200) != 0 )
    {
      v9 = pWeakProxy->RefCount-- == 1;
      if ( v9 )
LABEL_24:
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
LABEL_25:
      v15.Flags = Flags & 0xFFFFFDE0;
      memset(&v15.Bonus, 0, 24);
      return;
    }
LABEL_26:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    return;
  }
  if ( (Flags & 0x1F) != 0 && ((unsigned int)(v6 - 12) > 3 && v6 != 10 || v5.VStr) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 1041, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    v9 = v14.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (Flags & 0x1F) > 9 )
      goto LABEL_22;
  }
  else
  {
    if ( (unsigned int)(v6 - 12) > 3 && v6 != 10 || (v10 = 1, v5.VStr) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 1010 - (v10 != 0), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v14.Message.pNode;
    v9 = v14.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v9 = pWeakProxy->RefCount-- == 1;
        if ( v9 )
          goto LABEL_24;
        goto LABEL_25;
      }
      goto LABEL_26;
    }
  }
}

// File Line: 4071
// RVA: 0x843020
void __fastcall Scaleform::GFx::AS3::VM::exec_newarray(Scaleform::GFx::AS3::VM *this, unsigned int arr_size)
{
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rdi
  bool v6; // zf
  Scaleform::GFx::AS3::Instances::fl::Array *pCurrent; // rax
  Scaleform::GFx::AS3::Value v8; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Array *v10; // [rsp+70h] [rbp+18h]

  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->TraitsArray.pObject->ITraits.pObject);
  v4 = arr_size;
  pV = result.pV;
  Scaleform::GFx::AS3::Impl::SparseArray::Pick(&result.pV->SA, &this->OpStack, v4);
  v8.Bonus.pWeakProxy = 0i64;
  v8.Flags = 12;
  v8.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)pV;
  v6 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = (Scaleform::GFx::AS3::Instances::fl::Array *)this->OpStack.pCurrent;
  result.pV = pCurrent;
  v10 = pCurrent;
  if ( !v6 )
  {
    LODWORD(pCurrent->vfptr) = 12;
    pCurrent->pRCCRaw = 0i64;
    pCurrent->pNext = pV;
    pCurrent->pPrev = 0i64;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
}

// File Line: 4083
// RVA: 0x8416B0
void __fastcall Scaleform::GFx::AS3::VM::exec_hasnext2(
        Scaleform::GFx::AS3::VM *this,
        unsigned int object_reg,
        unsigned int index_reg)
{
  __int64 v5; // r12
  Scaleform::GFx::AS3::Value *pRF; // rdx
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v10; // zf
  int v11; // ecx
  __int64 v12; // r13
  int v13; // ecx
  Scaleform::GFx::ASStringNode *VStr; // r15
  Scaleform::GFx::AS3::Object *Prototype; // r14
  const char *pData; // rbx
  unsigned int v17; // ebx
  Scaleform::GFx::AS3::Value *Null; // rax
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  int v21; // ebx
  unsigned int v22; // r14d
  Scaleform::GFx::AS3::Value *v23; // rcx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Traits *pObject; // r14
  unsigned int v26; // ebx
  Scaleform::GFx::AS3::Value *v27; // rcx
  Scaleform::GFx::AS3::Object *v28; // r15
  int v29; // ebx
  unsigned int v30; // r14d
  Scaleform::GFx::AS3::Value *v31; // rax
  unsigned int v32; // r14d
  Scaleform::GFx::AS3::Value *v33; // rcx
  Scaleform::GFx::AS3::Value *v34; // rcx
  Scaleform::GFx::AS3::Value v35; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value *v36; // [rsp+A0h] [rbp+48h] BYREF
  int result; // [rsp+A8h] [rbp+50h] BYREF
  unsigned int v38; // [rsp+B0h] [rbp+58h] BYREF
  Scaleform::GFx::AS3::Value *v39; // [rsp+B8h] [rbp+60h]

  v5 = object_reg;
  pRF = this->RegisterFile.pRF;
  v7 = &pRF[v5];
  if ( index_reg == object_reg )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v35, 1124, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v35.Bonus.pWeakProxy;
    v10 = LODWORD(v35.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    return;
  }
  v11 = v7->Flags & 0x1F;
  if ( v11 && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || v7->value.VS._1.VStr) )
  {
    v38 = 0;
    v12 = index_reg;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(&pRF[v12], (Scaleform::GFx::AS3::CheckResult *)&result, &v38)->Result )
      return;
    v13 = v7->Flags & 0x1F;
    if ( (unsigned int)(v13 - 12) <= 3 )
    {
      VStr = v7->value.VS._1.VStr;
      (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, int *, _QWORD))VStr->pData + 16))(VStr, &result, v38);
      Prototype = (Scaleform::GFx::AS3::Object *)VStr;
      pData = VStr[1].pData;
      if ( pData )
      {
        while ( !result )
        {
          if ( !*((_QWORD *)pData + 17) )
            (*(void (__fastcall **)(const char *))(*(_QWORD *)pData + 80i64))(pData);
          Prototype = Scaleform::GFx::AS3::Class::GetPrototype(*((Scaleform::GFx::AS3::Class **)pData + 17));
          result = *(_DWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value **, _QWORD))Prototype->vfptr[5].~RefCountBaseGC<328>)(
                                Prototype,
                                &v36,
                                0i64);
          pData = (const char *)*((_QWORD *)pData + 18);
          if ( !pData )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        if ( !result )
        {
          Null = Scaleform::GFx::AS3::Value::GetNull();
          Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v5], Null);
LABEL_26:
          v35.Flags = 3;
          v35.Bonus.pWeakProxy = 0i64;
          v35.value.VS._1.VInt = result;
          Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v12], &v35);
          Flags = v35.Flags;
          if ( (v35.Flags & 0x1F) > 9 )
          {
            if ( (v35.Flags & 0x200) != 0 )
            {
              v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v10 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v35.Bonus, 0, 24);
              v35.Flags = Flags & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
            }
          }
          v35.Flags = 1;
          v35.Bonus.pWeakProxy = 0i64;
          v35.value.VS._1.VBool = result != 0;
          v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
          pCurrent = this->OpStack.pCurrent;
          v36 = pCurrent;
          v39 = pCurrent;
          if ( !v10 )
          {
            pCurrent->Flags = 1;
            pCurrent->Bonus.pWeakProxy = 0i64;
            pCurrent->value = v35.value;
          }
          return;
        }
      }
      if ( Prototype != (Scaleform::GFx::AS3::Object *)VStr )
      {
        v35.Flags = 12;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)Prototype;
        if ( Prototype )
          Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v5], &v35);
        v17 = v35.Flags;
        if ( (v35.Flags & 0x1F) > 9 )
        {
          if ( (v35.Flags & 0x200) != 0 )
          {
            v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v35.Bonus, 0, 24);
            v35.Flags = v17 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
          }
        }
      }
      goto LABEL_26;
    }
    if ( v13 == 11 )
    {
      if ( v38 > 1 )
        v21 = 0;
      else
        v21 = v38 + 1;
      v35.Flags = 3;
      v35.Bonus.pWeakProxy = 0i64;
      v35.value.VS._1.VInt = v21;
      Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v12], &v35);
      v22 = v35.Flags;
      if ( (v35.Flags & 0x1F) > 9 )
      {
        if ( (v35.Flags & 0x200) != 0 )
        {
          v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v35.Bonus, 0, 24);
          v35.Flags = v22 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
        }
      }
      v35.Flags = 1;
      v35.Bonus.pWeakProxy = 0i64;
      v35.value.VS._1.VBool = v21 != 0;
      v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
      v23 = this->OpStack.pCurrent;
      v36 = v23;
      v39 = v23;
      if ( !v10 )
      {
        v23->Flags = 1;
        v23->Bonus.pWeakProxy = 0i64;
        v23->value = v35.value;
      }
    }
    else
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, v7);
      pObject = ValueTraits;
      if ( ValueTraits->TraitsType != Traits_Namespace || (ValueTraits->Flags & 0x20) != 0 || v38 > 1 )
      {
        while ( 1 )
        {
          if ( !pObject->pConstructor.pObject )
            pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
          v28 = Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject);
          v29 = *(_DWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, int *, _QWORD))v28->vfptr[5].~RefCountBaseGC<328>)(
                             v28,
                             &result,
                             0i64);
          pObject = pObject->pParent.pObject;
          if ( !pObject )
            break;
          if ( v29 )
            goto LABEL_66;
        }
        if ( !v29 )
        {
          v31 = Scaleform::GFx::AS3::Value::GetNull();
          Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v5], v31);
          goto LABEL_73;
        }
LABEL_66:
        v35.Flags = 12;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v28;
        v28->RefCount = (v28->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v5], &v35);
        v30 = v35.Flags;
        if ( (v35.Flags & 0x1F) > 9 )
        {
          if ( (v35.Flags & 0x200) != 0 )
          {
            v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v35.Bonus, 0, 24);
            v35.Flags = v30 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
          }
        }
LABEL_73:
        v35.Flags = 3;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VInt = v29;
        Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v12], &v35);
        v32 = v35.Flags;
        if ( (v35.Flags & 0x1F) > 9 )
        {
          if ( (v35.Flags & 0x200) != 0 )
          {
            v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v35.Bonus, 0, 24);
            v35.Flags = v32 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
          }
        }
        v35.Flags = 1;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VBool = v29 != 0;
        v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v33 = this->OpStack.pCurrent;
        v36 = v33;
        v39 = v33;
        if ( !v10 )
        {
          v33->Flags = 1;
          v33->Bonus.pWeakProxy = 0i64;
          v33->value = v35.value;
        }
      }
      else
      {
        v35.Flags = 3;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VInt = v38 + 1;
        Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[v12], &v35);
        v26 = v35.Flags;
        if ( (v35.Flags & 0x1F) > 9 )
        {
          if ( (v35.Flags & 0x200) != 0 )
          {
            v10 = v35.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v35.Bonus, 0, 24);
            v35.Flags = v26 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
          }
        }
        v35.Flags = 1;
        v35.Bonus.pWeakProxy = 0i64;
        v35.value.VS._1.VBool = 1;
        v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v27 = this->OpStack.pCurrent;
        v36 = v27;
        v39 = v27;
        if ( !v10 )
        {
          v27->Flags = 1;
          v27->Bonus.pWeakProxy = 0i64;
          v27->value = v35.value;
        }
      }
    }
  }
  else
  {
    v35.Flags = 1;
    v35.Bonus.pWeakProxy = 0i64;
    v35.value.VS._1.VBool = 0;
    v10 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    v34 = this->OpStack.pCurrent;
    v36 = v34;
    v39 = v34;
    if ( !v10 )
    {
      v34->Flags = 1;
      v34->Bonus.pWeakProxy = 0i64;
      v34->value = v35.value;
    }
  }
}

// File Line: 4241
// RVA: 0x838EE0
void __fastcall Scaleform::GFx::AS3::VM::exec_applytype(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::Value *pCurrent; // r8
  int v4; // edx
  bool v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::Value *FixedArr; // r8
  Scaleform::GFx::AS3::Class **v12; // rbx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+20h] [rbp-E0h] BYREF
  __int64 v14; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value *v16; // [rsp+178h] [rbp+78h]

  v14 = -2i64;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  pCurrent = ptr.OpStack->pCurrent;
  v16 = pCurrent;
  v4 = pCurrent->Flags & 0x1F;
  if ( !v4 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !pCurrent->value.VS._1.VStr )
  {
    v5 = ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !pCurrent->value.VS._1.VStr;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v5, ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->HandleException )
    goto LABEL_13;
  if ( (v16->Flags & 0x1F) != 13 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1127, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
LABEL_13:
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
    goto LABEL_23;
  }
  FixedArr = ptr.FixedArr;
  if ( ptr.ArgNum > 8 )
    FixedArr = ptr.CallArgs.Data.Data;
  v12 = *(Scaleform::GFx::AS3::Class ***)((*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, _QWORD, Scaleform::GFx::AS3::Value *))v16->value.VS._1.VStr->pData
                                           + 22))(
                                            v16->value.VS._1,
                                            ptr.ArgNum,
                                            FixedArr)
                                        + 200);
  if ( !v12[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class **))(*v12)[1]._pRCC)(v12);
  Scaleform::GFx::AS3::Value::Assign(v16, v12[17]);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
LABEL_23:
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 4255
// RVA: 0x7CF440
void __fastcall Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *func,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool result_on_stack)
{
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V1U v12; // rcx
  Scaleform::GFx::AS3::Value::V1U v13; // rcx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *v17; // rcx
  const char *VStr; // r10
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::AS3::Value *v21; // rcx
  const char *v22; // r10
  Scaleform::GFx::AS3::Value::V1U v23; // rcx
  Scaleform::GFx::AS3::Value *v24; // rcx
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Value *v27; // rdx
  __int64 VInt; // rbx
  Scaleform::GFx::AS3::Traits *pTraits; // r13
  Scaleform::GFx::AS3::VMAbcFile *v30; // rax
  __int64 MethodBodyInfoInd; // rbx
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  unsigned int v35; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::ValueStack *v38; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v39; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v41; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v43; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v45; // rcx
  Scaleform::GFx::AS3::CallFrame *v46; // rcx
  const char *v47; // r10
  Scaleform::GFx::AS3::Value *v48; // rcx
  Scaleform::GFx::AS3::VM::Error *v49; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value *v51; // rcx
  Scaleform::GFx::AS3::Value::V1U v52; // rdx
  __int64 v53; // rbx
  Scaleform::GFx::AS3::Traits *v54; // r12
  Scaleform::GFx::AS3::VMAbcFile *v55; // rax
  Scaleform::GFx::AS3::VMAbcFile *v56; // r13
  __int64 v57; // rbx
  Scaleform::GFx::AS3::VM::Error *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::AS3::VM *v60; // rcx
  unsigned int v61; // ecx
  Scaleform::GFx::AS3::WeakProxy *v62; // rdx
  Scaleform::GFx::AS3::Value::V1U v63; // rcx
  Scaleform::GFx::AS3::ValueStack *v64; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v65; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v66; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v67; // rcx
  unsigned int v68; // eax
  unsigned __int64 v69; // rdi
  Scaleform::GFx::AS3::CallFrame **v70; // rax
  __int64 v71; // rcx
  Scaleform::GFx::AS3::CallFrame *v72; // rcx
  const char *v73; // r10
  Scaleform::GFx::AS3::Value *v74; // rcx
  Scaleform::GFx::AS3::VM::Error *v75; // rax
  Scaleform::GFx::ASStringNode *v76; // rcx
  Scaleform::GFx::AS3::VM::Error *v77; // rax
  Scaleform::GFx::AS3::Value _thisa; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS3::VM::Error v79; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::CallFrame other; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::VM::Error v81; // [rsp+F0h] [rbp-10h] BYREF
  Scaleform::GFx::AS3::VM::Error v82; // [rsp+100h] [rbp+0h] BYREF
  __int64 v83; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // [rsp+168h] [rbp+68h] BYREF
  _QWORD *p_Flags; // [rsp+170h] [rbp+70h]

  v83 = -2i64;
  _mm_prefetch((const char *)func, 2);
  _mm_prefetch((const char *)_this, 2);
  Flags = func->Flags;
  switch ( Flags & 0x1F )
  {
    case 5u:
      VStr = (const char *)func->value.VS._1.VStr;
      _mm_prefetch(VStr + 32, 2);
      _mm_prefetch(VStr, 2);
      if ( argc < ((unsigned int)(*((_QWORD *)VStr + 4) >> 6) & 7)
        || (*((_QWORD *)VStr + 4) & 0x200000i64) == 0 && argc > ((unsigned int)(*((_QWORD *)VStr + 4) >> 9) & 0xFFF) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v79, 1063, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v20, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        pNode = v79.Message.pNode;
        goto LABEL_137;
      }
      (*(void (__fastcall **)(const char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *))VStr)(
        VStr,
        this,
        _this);
      if ( result_on_stack && !this->HandleException )
      {
        p_OpStack = &this->OpStack;
        v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        pCurrent = this->OpStack.pCurrent;
        p_Flags = &pCurrent->Flags;
        if ( !v16 )
        {
          pCurrent->Flags = result->Flags;
          pCurrent->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
          pCurrent->value.VS._1.VStr = result->value.VS._1.VStr;
          pCurrent->value.VS._2.VObj = result->value.VS._2.VObj;
          result->Flags = 0;
        }
      }
      return;
    case 7u:
      v27 = &Scaleform::GFx::AS3::Traits::GetVT(func->value.VS._2.pTraits)->VTMethods.Data.Data[func->value.VS._1.VUInt];
      _mm_prefetch((const char *)v27, 2);
      if ( (v27->Flags & 0x1F) == 6 )
      {
        VInt = v27->value.VS._1.VInt;
        pTraits = v27->value.VS._2.pTraits;
        v30 = (Scaleform::GFx::AS3::VMAbcFile *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pTraits->vfptr[2].~RefCountBaseGC<328>)(pTraits);
        p_Flags = &v30->vfptr;
        MethodBodyInfoInd = v30->File.pObject->Methods.Info.Data.Data[VInt]->MethodBodyInfoInd;
        if ( this->CallStack.Size == 128 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v79, 1023, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v32, &Scaleform::GFx::AS3::fl::ErrorTI);
          v33 = v79.Message.pNode;
          v16 = v79.Message.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
LABEL_76:
          if ( !result_on_stack )
            Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
          return;
        }
        *(_WORD *)&other.DiscardResult = 0;
        VMRef = v30->VMRef;
        other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
        other.CP = 0i64;
        other.pRegisterFile = &VMRef->RegisterFile;
        other.pHeap = VMRef->MHeap;
        other.pFile = v30;
        other.MBIIndex.Ind = MethodBodyInfoInd;
        other.pSavedScope = &pTraits->InitScope;
        other.OriginationTraits = pTraits;
        other.pScopeStack = &VMRef->ScopeStack;
        other.DefXMLNamespace.pObject = 0i64;
        v35 = func->Flags;
        other.Invoker.Flags = v35;
        pWeakProxy = func->Bonus.pWeakProxy;
        other.Invoker.Bonus.pWeakProxy = pWeakProxy;
        other.Invoker.value = func->value;
        if ( (v35 & 0x1F) > 9 )
        {
          if ( (v35 & 0x200) != 0 )
          {
            ++pWeakProxy->RefCount;
            goto LABEL_60;
          }
          if ( (v35 & 0x1F) == 10 )
          {
            ++func->value.VS._1.VStr->RefCount;
          }
          else if ( (v35 & 0x1F) > 0xA )
          {
            if ( (v35 & 0x1F) <= 0xF )
            {
              VObj = func->value.VS._1;
LABEL_57:
              if ( VObj.VStr )
                VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
              goto LABEL_60;
            }
            if ( (v35 & 0x1F) <= 0x11 )
            {
              VObj = (Scaleform::GFx::AS3::Value::V1U)func->value.VS._2.VObj;
              goto LABEL_57;
            }
          }
        }
LABEL_60:
        v38 = &v30->VMRef->OpStack;
        other.PrevInitialStackPos = v38->pCurrent;
        other.PrevFirstStackPos = v38->pStack;
        v39 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
        Scaleform::GFx::AS3::ValueStack::Reserve(v38, v39->max_stack + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v39->local_reg_count);
        p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
        if ( *p_DefXMLNamespace )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
            *p_DefXMLNamespace);
          p_OpStack = 0i64;
          if ( &p_OpStack != (Scaleform::GFx::AS3::ValueStack **)p_DefXMLNamespace )
          {
            v41 = *p_DefXMLNamespace;
            if ( *p_DefXMLNamespace )
            {
              if ( ((unsigned __int8)v41 & 1) != 0 )
              {
                *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v41 - 1);
              }
              else
              {
                RefCount = v41->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v41->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
                }
              }
            }
            *p_DefXMLNamespace = 0i64;
          }
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &other,
          *(Scaleform::GFx::AS3::Abc::MethodInfo **)(*(_QWORD *)(p_Flags[19] + 224i64)
                                                   + 8i64
                                                   * *(int *)(*(_QWORD *)(*(_QWORD *)(p_Flags[19] + 344i64)
                                                                        + 8 * MethodBodyInfoInd)
                                                            + 24i64)),
          _this,
          argc,
          argv);
        if ( this->HandleException )
        {
          other.ACopy = 1;
        }
        else
        {
          v43 = this->CallStack.Size >> 6;
          if ( v43 >= this->CallStack.NumPages )
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
              &this->CallStack,
              this->CallStack.Size >> 6);
          Pages = this->CallStack.Pages;
          v45 = this->CallStack.Size & 0x3F;
          v16 = &Pages[v43][v45] == 0i64;
          v46 = &Pages[v43][v45];
          p_OpStack = (Scaleform::GFx::AS3::ValueStack *)v46;
          p_Flags = v46;
          if ( !v16 )
            Scaleform::GFx::AS3::CallFrame::CallFrame(v46, &other);
          ++this->CallStack.Size;
        }
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        goto LABEL_76;
      }
      v47 = (const char *)v27->value.VS._1.VStr;
      _mm_prefetch(v47 + 32, 2);
      _mm_prefetch(v47, 2);
      if ( argc < ((unsigned int)(*((_QWORD *)v47 + 4) >> 6) & 7)
        || (*((_QWORD *)v47 + 4) & 0x200000i64) == 0 && argc > ((unsigned int)(*((_QWORD *)v47 + 4) >> 9) & 0xFFF) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v79, 1063, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v49, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        pNode = v79.Message.pNode;
        goto LABEL_137;
      }
      (*(void (__fastcall **)(const char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v47)(
        v47,
        this,
        _this,
        result,
        argc,
        argv);
      if ( result_on_stack && !this->HandleException )
      {
        p_OpStack = &this->OpStack;
        v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v48 = this->OpStack.pCurrent;
        p_Flags = &v48->Flags;
        if ( !v16 )
        {
          v48->Flags = result->Flags;
          v48->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
          v48->value.VS._1.VStr = result->value.VS._1.VStr;
          v48->value.VS._2.VObj = result->value.VS._2.VObj;
          result->Flags = 0;
        }
      }
      return;
    case 0xCu:
    case 0xDu:
      v13 = func->value.VS._1;
      if ( !v13.VStr )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v82, 1006, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        pNode = v82.Message.pNode;
        goto LABEL_137;
      }
      (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))v13.VStr->pData
       + 9))(
        v13,
        _this,
        result,
        argc,
        argv);
      if ( !this->HandleException && result_on_stack )
      {
        p_OpStack = &this->OpStack;
        v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v17 = this->OpStack.pCurrent;
        p_Flags = &v17->Flags;
        if ( !v16 )
        {
          v17->Flags = result->Flags;
          v17->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
          v17->value.VS._1.VStr = result->value.VS._1.VStr;
          v17->value.VS._2.VObj = result->value.VS._2.VObj;
          result->Flags = 0;
        }
      }
      return;
    case 0xEu:
      v12 = func->value.VS._1;
      if ( result_on_stack )
        (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, _BYTE))v12.VStr->pData
         + 21))(
          v12,
          _this,
          argc,
          argv,
          0);
      else
        (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))v12.VStr->pData
         + 20))(
          v12,
          _this,
          result,
          argc,
          argv);
      return;
    case 0xFu:
      (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))func->value.VS._1.VStr->pData
       + 20))(
        func->value.VS._1,
        _this,
        result,
        argc,
        argv);
      if ( !this->HandleException && result_on_stack )
      {
        p_OpStack = &this->OpStack;
        v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v21 = this->OpStack.pCurrent;
        p_Flags = &v21->Flags;
        if ( !v16 )
        {
          v21->Flags = result->Flags;
          v21->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
          v21->value.VS._1.VStr = result->value.VS._1.VStr;
          v21->value.VS._2.VObj = result->value.VS._2.VObj;
          result->Flags = 0;
        }
      }
      return;
    case 0x10u:
      v22 = (const char *)func->value.VS._1.VStr;
      _mm_prefetch(v22 + 32, 2);
      _mm_prefetch(v22, 2);
      v23 = (Scaleform::GFx::AS3::Value::V1U)func->value.VS._2.VObj;
      _thisa.Flags = 12;
      _thisa.Bonus.pWeakProxy = 0i64;
      _thisa.value.VS._1 = v23;
      if ( v23.VStr )
        v23.VStr->Size = (v23.VStr->Size + 1) & 0x8FBFFFFF;
      if ( argc >= ((unsigned int)(*((_QWORD *)v22 + 4) >> 6) & 7)
        && ((*((_QWORD *)v22 + 4) & 0x200000i64) != 0 || argc <= ((unsigned int)(*((_QWORD *)v22 + 4) >> 9) & 0xFFF)) )
      {
        (*(void (__fastcall **)(const char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *))v22)(
          v22,
          this,
          &_thisa);
        if ( result_on_stack && !this->HandleException )
        {
          p_OpStack = &this->OpStack;
          v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
          v24 = this->OpStack.pCurrent;
          p_Flags = &v24->Flags;
          if ( !v16 )
          {
            v24->Flags = result->Flags;
            v24->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
            v24->value.VS._1.VStr = result->value.VS._1.VStr;
            v24->value.VS._2.VObj = result->value.VS._2.VObj;
            result->Flags = 0;
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v79, 1063, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v25, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v26 = v79.Message.pNode;
        v16 = v79.Message.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
      }
      goto LABEL_38;
    case 0x11u:
      pObject = func->value.VS._2.VObj->pTraits.pObject;
      if ( (Flags & 0x800) != 0 )
        pObject = pObject->pParent.pObject;
      v51 = &Scaleform::GFx::AS3::Traits::GetVT(pObject)->VTMethods.Data.Data[func->value.VS._1.VUInt];
      _mm_prefetch((const char *)v51, 2);
      v52 = (Scaleform::GFx::AS3::Value::V1U)func->value.VS._2.VObj;
      _thisa.Flags = 12;
      _thisa.Bonus.pWeakProxy = 0i64;
      _thisa.value.VS._1 = v52;
      if ( v52.VStr )
        v52.VStr->Size = (v52.VStr->Size + 1) & 0x8FBFFFFF;
      if ( (v51->Flags & 0x1F) == 6 )
      {
        v53 = v51->value.VS._1.VInt;
        v54 = v51->value.VS._2.pTraits;
        v55 = (Scaleform::GFx::AS3::VMAbcFile *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v54->vfptr[2].~RefCountBaseGC<328>)(v54);
        v56 = v55;
        v57 = v55->File.pObject->Methods.Info.Data.Data[v53]->MethodBodyInfoInd;
        if ( this->CallStack.Size == 128 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v79, 1023, this);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v58, &Scaleform::GFx::AS3::fl::ErrorTI);
          v59 = v79.Message.pNode;
          v16 = v79.Message.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
LABEL_123:
          if ( !result_on_stack )
            Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(this, result);
          goto LABEL_38;
        }
        *(_WORD *)&other.DiscardResult = 0;
        v60 = v55->VMRef;
        other.ScopeStackBaseInd = v60->ScopeStack.Data.Size;
        other.CP = 0i64;
        other.pRegisterFile = &v60->RegisterFile;
        other.pHeap = v60->MHeap;
        other.pFile = v55;
        other.MBIIndex.Ind = v57;
        other.pSavedScope = &v54->InitScope;
        other.OriginationTraits = v54;
        other.pScopeStack = &v60->ScopeStack;
        other.DefXMLNamespace.pObject = 0i64;
        v61 = func->Flags;
        other.Invoker.Flags = v61;
        v62 = func->Bonus.pWeakProxy;
        other.Invoker.Bonus.pWeakProxy = v62;
        other.Invoker.value = func->value;
        if ( (v61 & 0x1F) > 9 )
        {
          if ( (v61 & 0x200) != 0 )
          {
            ++v62->RefCount;
            goto LABEL_107;
          }
          if ( (v61 & 0x1F) == 10 )
          {
            ++func->value.VS._1.VStr->RefCount;
          }
          else if ( (v61 & 0x1F) > 0xA )
          {
            if ( (v61 & 0x1F) <= 0xF )
            {
              v63 = func->value.VS._1;
LABEL_104:
              if ( v63.VStr )
                v63.VStr->Size = (v63.VStr->Size + 1) & 0x8FBFFFFF;
              goto LABEL_107;
            }
            if ( (v61 & 0x1F) <= 0x11 )
            {
              v63 = (Scaleform::GFx::AS3::Value::V1U)func->value.VS._2.VObj;
              goto LABEL_104;
            }
          }
        }
LABEL_107:
        v64 = &v55->VMRef->OpStack;
        other.PrevInitialStackPos = v64->pCurrent;
        other.PrevFirstStackPos = v64->pStack;
        v65 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
        Scaleform::GFx::AS3::ValueStack::Reserve(v64, v65->max_stack + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v65->local_reg_count);
        v66 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
        if ( *v66 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
            *v66);
          p_OpStack = 0i64;
          if ( &p_OpStack != (Scaleform::GFx::AS3::ValueStack **)v66 )
          {
            v67 = *v66;
            if ( *v66 )
            {
              if ( ((unsigned __int8)v67 & 1) != 0 )
              {
                *v66 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v67 - 1);
              }
              else
              {
                v68 = v67->RefCount;
                if ( (v68 & 0x3FFFFF) != 0 )
                {
                  v67->RefCount = v68 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v67);
                }
              }
            }
            *v66 = 0i64;
          }
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &other,
          v56->File.pObject->Methods.Info.Data.Data[v56->File.pObject->MethodBodies.Info.Data.Data[v57]->method_info_ind],
          &_thisa,
          argc,
          argv);
        if ( this->HandleException )
        {
          other.ACopy = 1;
        }
        else
        {
          v69 = this->CallStack.Size >> 6;
          if ( v69 >= this->CallStack.NumPages )
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
              &this->CallStack,
              this->CallStack.Size >> 6);
          v70 = this->CallStack.Pages;
          v71 = this->CallStack.Size & 0x3F;
          v16 = &v70[v69][v71] == 0i64;
          v72 = &v70[v69][v71];
          p_OpStack = (Scaleform::GFx::AS3::ValueStack *)v72;
          p_Flags = v72;
          if ( !v16 )
            Scaleform::GFx::AS3::CallFrame::CallFrame(v72, &other);
          ++this->CallStack.Size;
        }
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        goto LABEL_123;
      }
      v73 = (const char *)v51->value.VS._1.VStr;
      _mm_prefetch(v73 + 32, 2);
      _mm_prefetch(v73, 2);
      if ( argc >= ((unsigned int)(*((_QWORD *)v73 + 4) >> 6) & 7)
        && ((*((_QWORD *)v73 + 4) & 0x200000i64) != 0 || argc <= ((unsigned int)(*((_QWORD *)v73 + 4) >> 9) & 0xFFF)) )
      {
        (*(void (__fastcall **)(const char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v73)(
          v73,
          this,
          &_thisa,
          result,
          argc,
          argv);
        if ( result_on_stack && !this->HandleException )
        {
          p_OpStack = &this->OpStack;
          v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
          v74 = this->OpStack.pCurrent;
          p_Flags = &v74->Flags;
          if ( !v16 )
          {
            v74->Flags = result->Flags;
            v74->Bonus.pWeakProxy = result->Bonus.pWeakProxy;
            v74->value.VS._1.VStr = result->value.VS._1.VStr;
            v74->value.VS._2.VObj = result->value.VS._2.VObj;
            result->Flags = 0;
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v79, 1063, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v75, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v76 = v79.Message.pNode;
        v16 = v79.Message.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v76);
      }
LABEL_38:
      if ( (_thisa.Flags & 0x1F) > 9 )
      {
        if ( (_thisa.Flags & 0x200) != 0 )
        {
          v16 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v16 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&_thisa.Bonus, 0, 24);
          _thisa.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_thisa);
        }
      }
      return;
    default:
      Scaleform::GFx::AS3::VM::Error::Error(&v81, 1006, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v77, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v81.Message.pNode;
LABEL_137:
      v16 = pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
  }
}ptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&_thisa.Bonus, 0, 24);
          _thisa.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_thisa);
        }
      }
      return;
  

// File Line: 4392
// RVA: 0x7D0F00
void __fastcall Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
        Scaleform::GFx::AS3::VM *this,
        int ind,
        Scaleform::GFx::AS3::Traits *tr,
        Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::Value *v8; // rcx
  __int64 VInt; // rbx
  unsigned __int64 *VObj; // r15
  __int64 v11; // rax
  __int64 v12; // r13
  __int64 v13; // rbx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  __int64 v17; // rcx
  __int64 v18; // rcx
  __int64 v19; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // rcx
  unsigned int RefCount; // eax
  Scaleform::ArrayPagedCC<Scaleform::GFx::AS3::CallFrame,6,64,329> *p_CallStack; // r14
  unsigned __int64 v24; // rbx
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  const char *VStr; // r10
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::AS3::Value v32; // [rsp+30h] [rbp-A8h] BYREF
  void *v33; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+58h] [rbp-80h] BYREF
  __int64 v35; // [rsp+68h] [rbp-70h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+70h] [rbp-68h] BYREF
  void *retaddr; // [rsp+138h] [rbp+60h]
  Scaleform::GFx::AS3::Value *v38; // [rsp+140h] [rbp+68h]

  *(_QWORD *)&other.Invoker.Flags = -2i64;
  v8 = &Scaleform::GFx::AS3::Traits::GetVT(tr)->VTMethods.Data.Data[ind];
  _mm_prefetch((const char *)v8, 2);
  if ( (v8->Flags & 0x1F) == 6 )
  {
    v32.Flags = 7;
    v32.Bonus.pWeakProxy = 0i64;
    v32.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)tr;
    v32.value.VS._1.VInt = ind;
    VInt = v8->value.VS._1.VInt;
    VObj = (unsigned __int64 *)v8->value.VS._2.VObj;
    v11 = (*(__int64 (__fastcall **)(unsigned __int64 *))(*VObj + 56))(VObj);
    v12 = v11;
    v13 = *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 152) + 224i64) + 8 * VInt) + 8i64);
    if ( this->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v34, 1023, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v14, &Scaleform::GFx::AS3::fl::ErrorTI);
      pNode = v34.Message.pNode;
      v16 = v34.Message.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      *(_WORD *)&other.DiscardResult = 0;
      v17 = *(_QWORD *)(v11 + 40);
      other.ScopeStackBaseInd = *(_QWORD *)(v17 + 144);
      *(_QWORD *)&v34.ID = 0i64;
      v34.Message.pNode = (Scaleform::GFx::ASStringNode *)(v17 + 96);
      v35 = *(_QWORD *)(v17 + 48);
      *(_QWORD *)&other.DiscardResult = v11;
      LODWORD(other.ScopeStackBaseInd) = v13;
      other.CP = VObj + 21;
      other.pRegisterFile = (Scaleform::GFx::AS3::ValueRegisterFile *)VObj;
      other.pHeap = (Scaleform::MemoryHeap *)(v17 + 136);
      *(_QWORD *)&other.MBIIndex.Ind = 0i64;
      LODWORD(other.OriginationTraits) = 7;
      other.pScopeStack = 0i64;
      other.PrevInitialStackPos = (Scaleform::GFx::AS3::Value *)v32.value.VS._1.VStr;
      other.DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)tr;
      v18 = *(_QWORD *)(v11 + 40) + 64i64;
      other.pFile = *(Scaleform::GFx::AS3::VMAbcFile **)v18;
      other.pSavedScope = *(Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> **)(v18 + 8);
      v19 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 152) + 344i64) + 8i64 * (int)v13);
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v18, *(_DWORD *)(v19 + 28) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(
        (Scaleform::GFx::AS3::ValueRegisterFile *)v34.Message.pNode,
        *(_WORD *)(v19 + 32));
      v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)(*(_QWORD *)&other.DiscardResult + 40i64)
                                                           + 640i64);
      if ( *v20 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.MBIIndex,
          *v20);
        v33 = 0i64;
        if ( &v33 != (void **)v20 )
        {
          v21 = *v20;
          if ( *v20 )
          {
            if ( ((unsigned __int8)v21 & 1) != 0 )
            {
              *v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v21 - 1);
            }
            else
            {
              RefCount = v21->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v21->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
              }
            }
          }
          *v20 = 0i64;
        }
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &other,
        *(Scaleform::GFx::AS3::Abc::MethodInfo **)(*(_QWORD *)(*(_QWORD *)(v12 + 152) + 224i64)
                                                 + 8i64
                                                 * *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 152) + 344i64)
                                                                      + 8 * v13)
                                                          + 24i64)),
        _this,
        (unsigned int)retaddr,
        v38);
      if ( this->HandleException )
      {
        other.ACopy = 1;
      }
      else
      {
        p_CallStack = &this->CallStack;
        v24 = p_CallStack->Size >> 6;
        if ( v24 >= p_CallStack->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
            p_CallStack,
            p_CallStack->Size >> 6);
        Pages = p_CallStack->Pages;
        v26 = p_CallStack->Size & 0x3F;
        v16 = &Pages[v24][v26] == 0i64;
        v27 = &Pages[v24][v26];
        v33 = v27;
        *(_QWORD *)&v34.ID = v27;
        if ( !v16 )
          Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
        ++p_CallStack->Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
  }
  else
  {
    VStr = (const char *)v8->value.VS._1.VStr;
    _mm_prefetch(VStr + 32, 2);
    _mm_prefetch(VStr, 2);
    v32.Flags = 0;
    v32.Bonus.pWeakProxy = 0i64;
    if ( (unsigned int)retaddr >= ((unsigned int)(*((_QWORD *)VStr + 4) >> 6) & 7)
      && ((*((_QWORD *)VStr + 4) & 0x200000i64) != 0
       || (unsigned int)retaddr <= ((unsigned int)(*((_QWORD *)VStr + 4) >> 9) & 0xFFF)) )
    {
      (*(void (__fastcall **)(const char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _DWORD, Scaleform::GFx::AS3::Value *))VStr)(
        VStr,
        this,
        _this,
        &v32,
        (_DWORD)retaddr,
        v38);
      if ( !this->HandleException )
      {
        *(_QWORD *)&v34.ID = &this->OpStack;
        v16 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        pCurrent = this->OpStack.pCurrent;
        v33 = pCurrent;
        if ( !v16 )
        {
          pCurrent->Flags = v32.Flags;
          pCurrent->Bonus.pWeakProxy = v32.Bonus.pWeakProxy;
          pCurrent->value = v32.value;
          v32.Flags = 0;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v34, 1063, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v30, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v31 = v34.Message.pNode;
      v16 = v34.Message.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    }
    if ( (v32.Flags & 0x1F) > 9 )
    {
      if ( (v32.Flags & 0x200) != 0 )
      {
        v16 = v32.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v32.Bonus, 0, 24);
        v32.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
      }
    }
  }
}

// File Line: 4627
// RVA: 0x7B6770
void __fastcall Scaleform::GFx::AS3::VM::Coerce2ReturnType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::CallFrame *v6; // r10
  Scaleform::GFx::AS3::VMFile *pFile; // rdx
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h] BYREF

  v6 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  pFile = v6->pFile;
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         this,
         pFile,
         (Scaleform::GFx::AS3::Abc::Multiname *)pFile[1].vfptr[7].~RefCountBaseGC<328>
       + *(int *)(*((_QWORD *)pFile[1].vfptr[9].~RefCountBaseGC<328>
                  + *(int *)(*((_QWORD *)pFile[1].vfptr[14].~RefCountBaseGC<328> + v6->MBIIndex.Ind) + 24i64))
                + 4i64));
  if ( v8 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v8->vfptr[3].Finalize_GC)(
           v8,
           value,
           result) )
    {
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1034, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, 1014, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  pNode = v13.Message.pNode;
  if ( v13.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 4664
// RVA: 0x7F0C10
Scaleform::GFx::AS3::ClassTraits::UserDefined *__fastcall Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::ClassInfo *ci)
{
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbp
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r14
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v5 = (Scaleform::GFx::AS3::Abc::Multiname *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, _QWORD))file->vfptr[1].ForEachChild_GC)(
                                                file,
                                                ci->inst_info.name_ind);
  Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, v5->NameIndex);
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v5->Ind);
  v7 = InternedNamespace;
  pObject = file->AppDomain.pObject;
  ParentDomain = pObject->ParentDomain;
  if ( ParentDomain
    && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &result, InternedNamespace)) != 0i64
    || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &pObject->ClassTraitsSet,
                       &result,
                       v7)) != 0i64
    || (pNode = v7->Uri.pNode, pNode->Size < 0xD)
    || strncmp(pNode->pData, "scaleform.gfx", 0xDui64) )
  {
    v12 = *ClassTrait;
  }
  else
  {
    v12 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, v5);
  }
  v13 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  return (Scaleform::GFx::AS3::ClassTraits::UserDefined *)v12;
}

// File Line: 4695
// RVA: 0x805CB0
void __fastcall Scaleform::GFx::AS3::VM::OutputError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *e)
{
  Scaleform::GFx::AS3::Value::V1U *v4; // rax
  char v5; // di
  Scaleform::GFx::AS3::Value::V1U v6; // rbx
  Scaleform::GFx::AS3::Value::V2U v7; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx
  int v9; // esi
  const char *pData; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  unsigned int v16; // ecx
  bool v17; // al
  unsigned int v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+48h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value v24; // [rsp+78h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value v25; // [rsp+98h] [rbp-11h] BYREF
  __int64 v26; // [rsp+B8h] [rbp+Fh]
  Scaleform::GFx::ASString v27; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+118h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString v29; // [rsp+120h] [rbp+77h] BYREF
  Scaleform::GFx::ASString v30; // [rsp+128h] [rbp+7Fh] BYREF

  v26 = -2i64;
  v25.Flags = 0;
  v25.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->StringManagerRef,
    &result);
  v4 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            this->StringManagerRef,
                                            &v30,
                                            "getStackTrace");
  v5 = 10;
  v24.Flags = 10;
  v24.Bonus.pWeakProxy = 0i64;
  v6 = *v4;
  v24.value.VS._1 = v6;
  if ( v6.VStr == &v6.VStr->pManager->NullStringNode )
  {
    v6.VStr = 0i64;
    v24.value.VS._1.VStr = 0i64;
    v7.VObj = (Scaleform::GFx::AS3::Object *)v24.Bonus.pWeakProxy;
    v24.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v24.Bonus.pWeakProxy;
    v5 = 12;
    v24.Flags = 12;
  }
  else
  {
    ++v6.VStr->RefCount;
    v7.VObj = (Scaleform::GFx::AS3::Object *)v24.value.VS._2;
  }
  pObject = this->PublicNamespace.pObject;
  prop_name.Kind = MN_QName;
  prop_name.Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  prop_name.Name.Flags = 0;
  prop_name.Name.Bonus.pWeakProxy = 0i64;
  v9 = v5 & 0x1F;
  if ( (unsigned int)(v9 - 12) <= 3
    && v6.VStr
    && (pData = v6.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)&v6.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v6.VStr[1].RefCount);
    prop_name.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v24, 2);
    *(_QWORD *)&prop_name.Name.Flags = *(_QWORD *)&v24.Flags;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    prop_name.Name.value.VS._1 = v6;
    prop_name.Name.value.VS._2 = v7;
    if ( (v5 & 0x1Fu) > 9 )
    {
      if ( v9 == 10 )
      {
        ++v6.VStr->RefCount;
      }
      else if ( (v5 & 0x1Fu) <= 0xF )
      {
        if ( v6.VStr )
          v6.VStr->Size = (v6.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v5 & 0x1Fu) <= 0x11 && v7.VObj )
      {
        v7.VObj->RefCount = (v7.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (prop_name.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &v27);
      if ( v27.pNode->Size )
      {
        if ( *v27.pNode->pData == 64 )
        {
          prop_name.Kind |= 8u;
          v11 = Scaleform::GFx::ASString::Substring(&v27, &v29, 1, v27.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v11);
          pNode = v29.pNode;
          v13 = v29.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v14 = v27.pNode;
      v13 = v27.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
  }
  if ( (v5 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
  v15 = v30.pNode;
  v13 = v30.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = e->Flags & 0x1F;
  v17 = v16
     && (v16 - 12 > 3 && v16 != 10 || e->value.VS._1.VStr)
     && Scaleform::GFx::AS3::ExecutePropertyUnsafe((Scaleform::GFx::AS3::CheckResult *)&v27, this, &prop_name, e)->Result;
  if ( !v17
    || Scaleform::GFx::AS3::Value::Convert2String(&v25, (Scaleform::GFx::AS3::CheckResult *)&v27, &result)->Result )
  {
    v18 = e->Flags & 0x1F;
    if ( !v18 || (v18 - 12 <= 3 || v18 == 10) && !e->value.VS._1.VStr || (v19 = result.pNode, !result.pNode->Size) )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2String(e, (Scaleform::GFx::AS3::CheckResult *)&v27, &result)->Result )
        goto LABEL_48;
      v19 = result.pNode;
    }
    this->UI->vfptr->Output(this->UI, Output_Error, v19->pData);
  }
LABEL_48:
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags & 0x200) != 0 )
    {
      v13 = prop_name.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&prop_name.Name.Bonus, 0, 24);
      prop_name.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
    }
  }
  v20 = prop_name.Obj.pObject;
  if ( prop_name.Obj.pObject )
  {
    if ( ((__int64)prop_name.Obj.pObject & 1) != 0 )
    {
      --prop_name.Obj.pObject;
    }
    else
    {
      RefCount = prop_name.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        prop_name.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
  v22 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( (v25.Flags & 0x1F) > 9 )
  {
    if ( (v25.Flags & 0x200) != 0 )
    {
      v13 = v25.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v25.Bonus, 0, 24);
      v25.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
    }
  }
}

// File Line: 4728
// RVA: 0x7FE970
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbp

  if ( uri->pNode->Size || kind )
  {
    pObject = this->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&pObject[1].RefCount,
      result,
      kind,
      uri,
      &v);
  }
  else
  {
    v7 = this->PublicNamespace.pObject;
    result->pV = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  return result;
}

// File Line: 4738
// RVA: 0x7FEAB0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const char *name)
{
  const char *v7; // r8
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v7 = &customCaption;
  if ( name )
    v7 = name;
  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         this->StringManagerRef,
         &resulta,
         v7);
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, v8);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 4744
// RVA: 0x7FEA40
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::StringDataPtr *uri)
{
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF

  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         this->StringManagerRef,
         &resulta,
         uri->pStr,
         uri->Size);
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, result, kind, v7);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 4750
// RVA: 0x7EA590
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VM::GetInternedNamespace(
        Scaleform::GFx::AS3::VM *this,
        unsigned int kind,
        Scaleform::GFx::ASString *uri)
{
  __int64 v4; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // r14
  unsigned __int64 SizeMask; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *v8; // r14
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *pTable; // rbp
  signed __int64 v11; // rax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v12; // rax
  Scaleform::GFx::AS3::NamespaceKey key; // [rsp+28h] [rbp-20h] BYREF

  v4 = kind;
  if ( !uri->pNode->Size && !kind )
    return this->PublicNamespace.pObject;
  pObject = this->TraitsNamespace.pObject->ITraits.pObject;
  SizeMask = 0i64;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v8 = *(Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > **)&pObject[1].RefCount;
  key.Kind = v4;
  pNode = uri->pNode;
  key.URI.pNode = pNode;
  ++pNode->RefCount;
  pTable = v8[2].pTable;
  if ( pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                v8 + 2,
                &key,
                pTable->SizeMask & (v4 ^ (4 * (pNode->HashFlags & 0xFFFFFF)))),
        v11 >= 0) )
  {
    SizeMask = pTable[v11 + 1].SizeMask;
  }
  else
  {
    v12 = v8[3].pTable;
    if ( v12 )
      SizeMask = *(_QWORD *)(v12[8].EntryCount + 424);
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS3::Instances::fl::Namespace *)SizeMask;
}

// File Line: 4771
// RVA: 0x7F9BB0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__fastcall Scaleform::GFx::AS3::VM::LoadFile(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result,
        Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file,
        Scaleform::GFx::AS3::VMAppDomain *appDomain,
        bool to_execute)
{
  Scaleform::GFx::AS3::VMAbcFile *v9; // rax
  Scaleform::GFx::AS3::VMAbcFile *v10; // rax
  Scaleform::GFx::AS3::VMAbcFile *v11; // rbx
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  Scaleform::MemoryHeap *resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v16; // [rsp+68h] [rbp+10h]

  v16 = result;
  this->LoadingAbcFile = 1;
  resulta = this->MHeap;
  v9 = (Scaleform::GFx::AS3::VMAbcFile *)resulta->vfptr->Alloc((Scaleform::MemoryHeap *)this, 240ui64, 0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(v9, this, file, appDomain);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( Scaleform::GFx::AS3::VMAbcFile::Load(v11, (Scaleform::GFx::AS3::CheckResult *)&resulta, to_execute)->Result )
  {
    this->LoadingAbcFile = 0;
    result->pObject = v11;
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) == 0 )
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
    }
  }
  else
  {
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) == 0 )
      {
        v13 = v11->RefCount;
        if ( (v13 & 0x3FFFFF) != 0 )
        {
          v11->RefCount = v13 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
    }
    this->LoadingAbcFile = 0;
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 4790
// RVA: 0x7E6BE0
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::VM::GetClass(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::StringDataPtr *gname,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::Class *v6; // rbx
  unsigned __int64 Size; // r8
  unsigned __int64 v8; // rax
  const char *pStr; // rcx
  size_t v10; // r8
  __int64 LastChar; // r9
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r8
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *ClassVector; // rax
  __int64 v18; // rax
  Scaleform::GFx::AS3::Class *result; // rax
  Scaleform::GFx::AS3::Class *v20; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v22; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v23; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::StringDataPtr gnamea; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname v26; // [rsp+38h] [rbp-40h] BYREF

  v6 = 0i64;
  if ( !gname->Size )
    return v6;
  if ( (_S14_6 & 1) == 0 )
  {
    _S14_6 |= 1u;
    vecPref.pStr = "Vector.<";
    vecPref.Size = 8i64;
  }
  Size = gname->Size;
  if ( Size <= vecPref.Size )
    goto LABEL_24;
  v8 = Size - vecPref.Size;
  if ( Size < Size - vecPref.Size )
    v8 = gname->Size;
  pStr = gname->pStr;
  v10 = Size - v8;
  if ( vecPref.Size != v10 || vecPref.pStr != pStr && (!pStr || !vecPref.pStr || strncmp(pStr, vecPref.pStr, v10)) )
  {
LABEL_24:
    Scaleform::GFx::AS3::Multiname::Multiname(&v26, this, gname);
    v22 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, &v26, appDomain);
    v23 = v22;
    if ( v22 )
    {
      v22->vfptr[3].~RefCountBaseGC<328>(v22);
      if ( !this->HandleException )
      {
        pObject = v23->ITraits.pObject;
        if ( !pObject->pConstructor.pObject )
          pObject->vfptr[3].~RefCountBaseGC<328>(v23->ITraits.pObject);
        v6 = pObject->pConstructor.pObject;
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&v26);
    return v6;
  }
  LastChar = Scaleform::StringDataPtr::FindLastChar(gname, 62, 0xFFFFFFFFFFFFFFFFui64);
  if ( LastChar <= 0 )
    return v6;
  v12 = gname->Size;
  v13 = vecPref.Size;
  if ( v12 < vecPref.Size )
    v13 = gname->Size;
  v14 = v12 - v13;
  v15 = v12 - LastChar;
  if ( v14 < v15 )
    v15 = v14;
  gnamea.pStr = &gname->pStr[v13];
  gnamea.Size = v14 - v15;
  Class = Scaleform::GFx::AS3::VM::GetClass(this, &gnamea, appDomain);
  if ( !Class )
    return v6;
  v26.Kind = MN_RTQNameLA;
  v26.Obj.pObject = 0i64;
  *(_QWORD *)&v26.Name.Flags = Class;
  Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  ClassVector = Scaleform::GFx::AS3::VM::GetClassVector(this);
  v18 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Classes::fl_vec::Vector *, __int64, Scaleform::GFx::AS3::Multiname *))ClassVector->vfptr[7].~RefCountBaseGC<328>)(
          ClassVector,
          1i64,
          &v26);
  result = Scaleform::GFx::AS3::Traits::GetConstructor(*(Scaleform::GFx::AS3::Traits **)(v18 + 200));
  v20 = result;
  if ( (v26.Kind & 0x1Fu) > 9 )
  {
    if ( (v26.Kind & 0x200) != 0 )
    {
      if ( LODWORD(v26.Obj.pObject->vfptr)-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v26.Obj, 0, 24);
      v26.Kind &= 0xFFFFFDE0;
      return v20;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v26);
      return v20;
    }
  }
  return result;
}

// File Line: 4855
// RVA: 0x7B8F60
bool __fastcall Scaleform::GFx::AS3::VM::Construct(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Class *cl,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  unsigned __int64 Size; // rbp

  Size = this->CallStack.Size;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, bool))cl->vfptr[4].ForEachChild_GC)(
    cl,
    result,
    argc,
    argv,
    extCall);
  return !this->HandleException && this->CallStack.Size > Size;
}

// File Line: 4868
// RVA: 0x7B8FE0
_BOOL8 __fastcall Scaleform::GFx::AS3::VM::Construct(
        Scaleform::GFx::AS3::VM *this,
        const char *gname,
        Scaleform::GFx::AS3::VMAppDomain *appDomain,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  char v9; // bl
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS3::Class *Class; // rax
  bool v12; // di
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::StringDataPtr gnamea; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+48h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value v19; // [rsp+58h] [rbp-30h] BYREF

  v9 = 0;
  v19.Flags = 0;
  v19.Bonus.pWeakProxy = 0i64;
  gnamea.pStr = gname;
  if ( gname )
  {
    v10 = -1i64;
    do
      ++v10;
    while ( gname[v10] );
    gnamea.Size = v10;
  }
  else
  {
    gnamea.Size = 0i64;
  }
  Class = Scaleform::GFx::AS3::VM::GetClass(this, &gnamea, appDomain);
  if ( Class )
  {
    v9 = 13;
    v19.Flags = 13;
    v19.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)Class;
    v19.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.Message.pNode;
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
    v12 = Scaleform::GFx::AS3::VM::Construct(this, Class, result, argc, argv, extCall);
  }
  else
  {
    if ( !this->HandleException )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, 1065, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v18.Message.pNode;
      if ( v18.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    v12 = 0;
  }
  if ( (v9 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  return v12;
}

// File Line: 4890
// RVA: 0x831D60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VM::constructBuiltinObject(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *pobj,
        const char *gname,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v9; // bp
  int v10; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v15; // [rsp+48h] [rbp-30h] BYREF

  v9 = 0;
  v15.Flags = 0;
  v15.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::Construct(this, gname, this->CurrentDomain.pObject, &v15, argc, argv, 1);
  if ( this->HandleException
    || (v10 = v15.Flags & 0x1F, (v15.Flags & 0x1F) == 0)
    || ((unsigned int)(v10 - 12) <= 3 || v10 == 10) && !v15.value.VS._1.VStr )
  {
    pObject = pobj->pObject;
    if ( pobj->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        pobj->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      pobj->pObject = 0i64;
    }
    if ( this->HandleException )
      this->HandleException = 0;
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      pobj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v15.value.VS._1.VStr);
    v9 = 1;
  }
  result->Result = v9;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
    {
      if ( v15.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v15.Bonus, 0, 24);
      v15.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    }
  }
  return result;
}

// File Line: 4914
// RVA: 0x7F1030
Scaleform::GFx::AS3::Traits *__fastcall Scaleform::GFx::AS3::VM::GetValueTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // r9d
  Scaleform::GFx::AS3::Traits *result; // rax

  v2 = v->Flags & 0x1F;
  switch ( v2 )
  {
    case 1u:
      result = this->TraitsBoolean.pObject->ITraits.pObject;
      break;
    case 2u:
      result = this->TraitsInt.pObject->ITraits.pObject;
      break;
    case 3u:
      result = this->TraitsUint.pObject->ITraits.pObject;
      break;
    case 4u:
      result = this->TraitsNumber.pObject->ITraits.pObject;
      break;
    case 5u:
    case 0x10u:
      result = this->TraitsFunction.pObject->ThunkTraits.pObject;
      break;
    case 7u:
    case 0x11u:
      result = this->TraitsFunction.pObject->VTableTraits.pObject;
      break;
    case 8u:
    case 9u:
      result = v->value.VS._1.ITr;
      break;
    case 0xAu:
      if ( !v->value.VS._1.VStr )
        goto LABEL_8;
      result = this->TraitsString.pObject->ITraits.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject->ITraits.pObject;
      break;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v2 - 12 <= 3 || v2 == 10) && !v->value.VS._1.VStr )
LABEL_8:
        result = this->TraitsObject.pObject->ITraits.pObject;
      else
        result = (Scaleform::GFx::AS3::Traits *)v->value.VS._1.VStr[1].pData;
      break;
    default:
      result = this->TraitsVoid.pObject;
      break;
  }
  return result;
}

// File Line: 5019
// RVA: 0x7E7100
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetClassTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  Scaleform::GFx::AS3::Value::V1U v3; // rbx
  char *pData; // rbx

  switch ( v->Flags & 0x1F )
  {
    case 1u:
      result = this->TraitsBoolean.pObject;
      break;
    case 2u:
      result = this->TraitsInt.pObject;
      break;
    case 3u:
      result = this->TraitsUint.pObject;
      break;
    case 4u:
      result = this->TraitsNumber.pObject;
      break;
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      result = this->TraitsFunction.pObject;
      break;
    case 9u:
      result = v->value.VS._1.CTr;
      break;
    case 0xAu:
      if ( v->value.VS._1.VStr )
        result = this->TraitsString.pObject;
      else
        result = this->TraitsObject.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject;
      break;
    case 0xDu:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)v->value.VS._1.VStr[1].pData;
      break;
    default:
      v3 = v->value.VS._1;
      if ( v3.VStr )
      {
        pData = (char *)v3.VStr[1].pData;
        if ( !*((_QWORD *)pData + 17) )
          (*(void (__fastcall **)(char *))(*(_QWORD *)pData + 80i64))(pData);
        result = *(Scaleform::GFx::AS3::ClassTraits::Traits **)(*((_QWORD *)pData + 17) + 40i64);
      }
      else
      {
        result = this->TraitsObject.pObject;
      }
      break;
  }
  return result;
}

// File Line: 5067
// RVA: 0x7EA430
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetInstanceTraits(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // r9d
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // rax

  v2 = v->Flags & 0x1F;
  switch ( v2 )
  {
    case 1u:
      result = this->TraitsBoolean.pObject->ITraits.pObject;
      break;
    case 2u:
      result = this->TraitsInt.pObject->ITraits.pObject;
      break;
    case 3u:
      result = this->TraitsUint.pObject->ITraits.pObject;
      break;
    case 4u:
      result = this->TraitsNumber.pObject->ITraits.pObject;
      break;
    case 5u:
    case 0x10u:
      result = this->TraitsFunction.pObject->ThunkTraits.pObject;
      break;
    case 7u:
    case 0x11u:
      result = this->TraitsFunction.pObject->VTableTraits.pObject;
      break;
    case 8u:
      result = v->value.VS._1.ITr;
      break;
    case 9u:
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->value.VS._1.VStr[5].pData;
      if ( !result )
        goto LABEL_22;
      break;
    case 0xAu:
      if ( !v->value.VS._1.VStr )
        goto LABEL_8;
      result = this->TraitsString.pObject->ITraits.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject->ITraits.pObject;
      break;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      if ( (v2 - 12 <= 3 || v2 == 10) && !v->value.VS._1.VStr )
        goto LABEL_8;
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->value.VS._1.VStr[1].pData;
      break;
    case 0xDu:
      if ( (v2 - 12 <= 3 || v2 == 10) && !v->value.VS._1.VStr )
LABEL_8:
        result = this->TraitsObject.pObject->ITraits.pObject;
      else
        result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)*((_QWORD *)v->value.VS._1.VStr[1].pData + 25);
      break;
    default:
LABEL_22:
      result = this->TraitsVoid.pObject;
      break;
  }
  return result;
}

// File Line: 5131
// RVA: 0x7EA200
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::VM::GetGlobalObject(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::CallFrame *v1; // r8
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Value *pRF; // rcx

  if ( !this->CallStack.Size )
    return 0i64;
  v1 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  pSavedScope = v1->pSavedScope;
  if ( pSavedScope->Data.Size )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pSavedScope->Data.Data->value.VS._1.VStr;
  pRF = v1->pRegisterFile->pRF;
  if ( (pRF->Flags & 0x1F) - 12 <= 3 )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)pRF->value.VS._1.VStr;
  else
    return 0i64;
}

// File Line: 5240
// RVA: 0x7E7960
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VM::GetDefaultValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::ClassTraits::ClassClass *ctr)
{
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  long double v6; // xmm0_8

  switch ( ctr->TraitsType )
  {
    case Traits_Boolean:
      result->Flags = 1;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VBool = 0;
      return result;
    case Traits_SInt:
      result->Flags = 2;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VInt = 0;
      return result;
    case Traits_UInt:
      result->Flags = 3;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VInt = 0;
      return result;
    case Traits_Number:
      v6 = Scaleform::GFx::NumberUtil::NaN();
      result->Flags = 4;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VNumber = v6;
      return result;
  }
  if ( ctr == this->TraitsClassClass.pObject )
    Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  else
    Undefined = Scaleform::GFx::AS3::Value::GetNull();
  result->Flags = Undefined->Flags;
  result->Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
  result->value.VS._1.VStr = Undefined->value.VS._1.VStr;
  result->value.VS._2.VObj = Undefined->value.VS._2.VObj;
  if ( (Undefined->Flags & 0x1F) > 9 )
  {
    if ( (Undefined->Flags & 0x200) != 0 )
    {
      ++Undefined->Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (Undefined->Flags & 0x1F) == 10 )
      {
        ++Undefined->value.VS._1.VStr->RefCount;
        return result;
      }
      if ( (Undefined->Flags & 0x1F) > 0xA )
      {
        if ( (Undefined->Flags & 0x1F) <= 0xF )
        {
          VObj = Undefined->value.VS._1;
        }
        else
        {
          if ( (Undefined->Flags & 0x1F) > 0x11 )
            return result;
          VObj = (Scaleform::GFx::AS3::Value::V1U)Undefined->value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
  return result;
}

// File Line: 5267
// RVA: 0x7E7820
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VM::GetDefaultValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  if ( (*(_QWORD *)&mn->NameIndex || mn->Ind)
    && (v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn)) != 0i64 )
  {
    Scaleform::GFx::AS3::VM::GetDefaultValue(this, result, v6);
  }
  else
  {
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    result->Flags = v.Flags;
    result->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    result->value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
          return result;
        }
        if ( (v.Flags & 0x1F) > 0xA )
        {
          if ( (v.Flags & 0x1F) <= 0xF )
          {
            VObj = v.value.VS._1;
          }
          else
          {
            if ( (v.Flags & 0x1F) > 0x11 )
              return result;
            VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
          }
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 5281
// RVA: 0x7E9A10
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetFunctReturnType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::ThunkInfo *thunk,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::TypeInfo *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rax
  _QWORD *p_vfptr; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *ClassTraits; // rax
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  __int64 v16; // rdi
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v22; // [rsp+20h] [rbp-30h] BYREF
  __int64 v23; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // [rsp+38h] [rbp-18h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+28h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Namespace *v28; // [rsp+88h] [rbp+38h]

  v23 = -2i64;
  v5 = *thunk->ArgType;
  if ( !v5 )
    return this->TraitsObject.pObject->ITraits.pObject;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->StringManagerRef,
    &result,
    v5->Name);
  pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(this, &v22, NS_Public, v5->PkgName)->pV;
  v28 = pV;
  ParentDomain = appDomain->ParentDomain;
  if ( (!ParentDomain
     || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &result, pV)) == 0i64)
    && (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                       &appDomain->ClassTraitsSet,
                       &result,
                       pV)) == 0i64
    || (p_vfptr = *ClassTrait) == 0i64 )
  {
    ClassTraits = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                                     this->GlobalObject.pObject,
                                                                     &result,
                                                                     pV);
    p_vfptr = &ClassTraits->vfptr;
    if ( ClassTraits )
    {
      pObject = this->SystemDomain.pObject;
      v22.pV = ClassTraits;
      pNode = result.pNode;
      ++result.pNode->RefCount;
      v25 = pV;
      if ( pV )
        pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&pNode;
      key.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v22;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        &pObject->ClassTraitsSet.Entries.mHash,
        pObject->ClassTraitsSet.Entries.mHash.pHeap,
        &key,
        pNode->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v25[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v25[1].vfptr) << 28) >> 28));
      v12 = v25;
      if ( v25 )
      {
        if ( ((unsigned __int8)v25 & 1) != 0 )
        {
          v25 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v25 - 1);
        }
        else
        {
          RefCount = v25->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v25->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
      v14 = pNode;
      v15 = pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      goto LABEL_16;
    }
    if ( pV )
    {
      if ( ((unsigned __int8)pV & 1) != 0 )
      {
        v28 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV - 1);
      }
      else
      {
        v20 = pV->RefCount;
        if ( (v20 & 0x3FFFFF) != 0 )
        {
          pV->RefCount = v20 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
    }
    v21 = result.pNode;
    v15 = result.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    return this->TraitsObject.pObject->ITraits.pObject;
  }
LABEL_16:
  v16 = p_vfptr[25];
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v28 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV - 1);
    }
    else
    {
      v17 = pV->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  v18 = result.pNode;
  v15 = result.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  return (Scaleform::GFx::AS3::InstanceTraits::Traits *)v16;
}

// File Line: 5300
// RVA: 0x7E9C20
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetFunctReturnType(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbp
  unsigned int v4; // ebx
  const char *pData; // r10
  _QWORD *v7; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *v8; // r8
  Scaleform::GFx::AS3::VMFile *v9; // rdx
  Scaleform::GFx::AS3::ClassTraits::fl::Object *pObject; // rax
  __int64 VInt; // rbx

  v3 = appDomain;
  v4 = value->Flags & 0x1F;
  switch ( v4 )
  {
    case 5u:
    case 0x10u:
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(this, value->value.VS._1.VThunk, appDomain);
    case 6u:
      goto $LN6_92;
    case 7u:
    case 0x11u:
      value = &Scaleform::GFx::AS3::Traits::GetVT(value->value.VS._2.pTraits)->VTMethods.Data.Data[value->value.VS._1.VUInt];
      if ( (value->Flags & 0x1F) == 6 )
      {
$LN6_92:
        VInt = value->value.VS._1.VInt;
        v9 = (Scaleform::GFx::AS3::VMFile *)((__int64 (__fastcall *)(_QWORD))value->value.VS._2.VObj->vfptr[2].~RefCountBaseGC<328>)((Scaleform::GFx::AS3::Value::V2U)value->value.VS._2.VObj);
        v8 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)v9[1].vfptr[7].~RefCountBaseGC<328>
                                                   + 16
                                                   * *(int *)(*((_QWORD *)v9[1].vfptr[9].~RefCountBaseGC<328> + VInt)
                                                            + 4i64));
LABEL_3:
        pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                                    this,
                                                                    v9,
                                                                    v8);
        if ( pObject )
          return pObject->ITraits.pObject;
        goto LABEL_4;
      }
      if ( v4 != 7 && v4 != 17 )
      {
LABEL_4:
        pObject = this->TraitsObject.pObject;
        return pObject->ITraits.pObject;
      }
      appDomain = v3;
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(this, value->value.VS._1.VThunk, appDomain);
    case 0xEu:
      pData = value->value.VS._1.VStr[1].pData;
      v7 = *(_QWORD **)(*((_QWORD *)pData + 31) + 152i64);
      v8 = (Scaleform::GFx::AS3::Abc::Multiname *)(v7[22]
                                                 + 16i64
                                                 * *(int *)(*(_QWORD *)(v7[28]
                                                                      + 8i64
                                                                      * *(int *)(*(_QWORD *)(v7[43]
                                                                                           + 8i64
                                                                                           * *(int *)(*(_QWORD *)(v7[28] + 8i64 * *((int *)pData + 60)) + 8i64))
                                                                               + 24i64))
                                                          + 4i64));
      v9 = (Scaleform::GFx::AS3::VMFile *)*((_QWORD *)pData + 31);
      goto LABEL_3;
    case 0xFu:
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(
               this,
               *(Scaleform::GFx::AS3::ThunkInfo **)&value->value.VS._1.VStr[1].RefCount,
               appDomain);
    default:
      goto LABEL_4;
  }
}

// File Line: 5461
// RVA: 0x7E72C0
void __fastcall Scaleform::GFx::AS3::VM::GetCodeFileName(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result)
{
  unsigned __int64 v3; // r8
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  v3 = this->CallStack.Size - 1;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 result->pNode->pManager,
                 (const char *)((this->CallStack.Pages[v3 >> 6][v3 & 0x3F].pFile->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                              + 12),
                 *(_QWORD *)(this->CallStack.Pages[v3 >> 6][v3 & 0x3F].pFile->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v5 = StringNode;
  ++StringNode->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = v5;
  }
  else
  {
    result->pNode = StringNode;
  }
}

// File Line: 5546
// RVA: 0x8347E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::describeTypeEx(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringManagerRef = this->StringManagerRef;
  pNode = StringManagerRef->Builtins[0].pNode;
  result->pNode = StringManagerRef->Builtins[0].pNode;
  ++pNode->RefCount;
  return result;
}

// File Line: 5756
// RVA: 0x7E7240
Scaleform::GFx::AS3::Classes::fl_vec::Vector *__fastcall Scaleform::GFx::AS3::VM::GetClassVector(
        Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx

  pObject = this->TraitsVector.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  return (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)pObject->pConstructor.pObject;
}

// File Line: 5766
// RVA: 0x7EA290
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorSInt(
        Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_int.pObject->ITraits.pObject;
}

// File Line: 5776
// RVA: 0x7EA2B0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorUInt(
        Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_uint.pObject->ITraits.pObject;
}

// File Line: 5786
// RVA: 0x7EA280
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorNumber(
        Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_Number.pObject->ITraits.pObject;
}

// File Line: 5796
// RVA: 0x7EA2A0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorString(
        Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_String.pObject->ITraits.pObject;
}

// File Line: 5811
// RVA: 0x8257C0
void __fastcall Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e,
        Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::ASString *v6; // r13
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r14
  char *PkgName; // r8
  Scaleform::GFx::ASString *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *SizeMask; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v11; // r15
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *v12; // r15
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *pTable; // r14
  signed __int64 v15; // rax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v16; // rax
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::VM::ErrorID ID; // eax
  Scaleform::GFx::AS3::NamespaceKey key; // [rsp+28h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+38h] [rbp-41h] BYREF
  int ptr; // [rsp+60h] [rbp-19h] BYREF
  __int64 v26; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::AS3::NamespaceKey v27; // [rsp+70h] [rbp-9h]
  int v28; // [rsp+80h] [rbp+7h]
  __int64 v29; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS3::VM::ErrorID v30; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::VMAppDomain *v31; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::ASString v32; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+77h] BYREF

  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->StringManagerRef,
         &result,
         ti->Name);
  pObject = this->CurrentDomain.pObject;
  v31 = pObject;
  PkgName = &customCaption;
  if ( ti->PkgName )
    PkgName = (char *)ti->PkgName;
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         this->StringManagerRef,
         &v32,
         PkgName);
  if ( v9->pNode->Size )
  {
    v11 = this->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S11_12 & 1) != 0 )
    {
      SizeMask = 0i64;
    }
    else
    {
      _S11_12 |= 1u;
      SizeMask = 0i64;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v12 = *(Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > **)&v11[1].RefCount;
    key.Kind = NS_Public;
    pNode = v9->pNode;
    key.URI.pNode = pNode;
    ++pNode->RefCount;
    pTable = v12[2].pTable;
    if ( pTable
      && (v15 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                  v12 + 2,
                  &key,
                  pTable->SizeMask & (4 * (pNode->HashFlags & 0xFFFFFF))),
          v15 >= 0) )
    {
      SizeMask = (Scaleform::GFx::AS3::Instances::fl::Namespace *)pTable[v15 + 1].SizeMask;
    }
    else
    {
      v16 = v12[3].pTable;
      if ( v16 )
        SizeMask = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(v16[8].EntryCount + 424);
    }
    v17 = pNode->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pObject = v31;
  }
  else
  {
    SizeMask = this->PublicNamespace.pObject;
  }
  v18 = v32.pNode;
  v17 = v32.pNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, v6, SizeMask, pObject);
  v20 = result.pNode;
  v17 = result.pNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  other.Flags = 0;
  other.Bonus.pWeakProxy = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v19->ITraits.pObject->vfptr[3].Finalize_GC)(
    v19->ITraits.pObject,
    &other,
    v19->ITraits.pObject);
  ptr = 10;
  v26 = 0i64;
  v21 = e->Message.pNode;
  *(_QWORD *)&v27.Kind = v21;
  if ( v21 == &v21->pManager->NullStringNode )
  {
    *(_QWORD *)&key.Kind = 0i64;
    v27 = key;
    ptr = 12;
  }
  else
  {
    ++v21->RefCount;
  }
  ID = e->ID;
  v28 = 2;
  v29 = 0i64;
  v30 = ID;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, __int64, int *))other.value.VS._1.VStr->pData + 11))(
    other.value.VS._1,
    2i64,
    &ptr);
  this->HandleException = 1;
  Scaleform::GFx::AS3::Value::Assign(&this->ExceptionObj, &other);
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v17 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 5830
// RVA: 0x8257B0
void __fastcall Scaleform::GFx::AS3::VM::ThrowError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::ErrorTI);
}

// File Line: 5840
// RVA: 0x825A50
void __fastcall Scaleform::GFx::AS3::VM::ThrowRangeError(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::RangeErrorTI);
}

// File Line: 5845
// RVA: 0x825A60
void __fastcall Scaleform::GFx::AS3::VM::ThrowReferenceError(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
}

// File Line: 5860
// RVA: 0x825A70
void __fastcall Scaleform::GFx::AS3::VM::ThrowTypeError(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::TypeErrorTI);
}

// File Line: 5870
// RVA: 0x825A80
void __fastcall Scaleform::GFx::AS3::VM::ThrowVerifyError(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
}

// File Line: 5880
// RVA: 0x8257A0
void __fastcall Scaleform::GFx::AS3::VM::ThrowArgumentError(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
}

// File Line: 6062
// RVA: 0x77C950
void __fastcall Scaleform::GFx::AS3::VM::Error::Error(
        Scaleform::GFx::AS3::VM::Error *this,
        __int32 id,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-448h] BYREF
  __int64 v12; // [rsp+38h] [rbp-430h]
  Scaleform::MsgFormat v13; // [rsp+40h] [rbp-428h] BYREF
  int v; // [rsp+478h] [rbp+10h] BYREF
  Scaleform::String str; // [rsp+480h] [rbp+18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+488h] [rbp+20h] BYREF

  v12 = -2i64;
  this->ID = id;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &this->Message);
  Scaleform::String::String(&str);
  v = id;
  r.Type = tStr;
  r.SinkData.pStr = &str;
  Scaleform::MsgFormat::MsgFormat(&v13, &r);
  Scaleform::MsgFormat::Parse(&v13, "Error #{0}");
  Scaleform::MsgFormat::FormatD1<long>(&v13, &v);
  Scaleform::MsgFormat::FinishFormatD(&v13);
  Scaleform::MsgFormat::~MsgFormat(&v13);
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         vm->StringManagerRef,
         &result,
         &str);
  pNode = v6->pNode;
  ++v6->pNode->RefCount;
  v8 = this->Message.pNode;
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  this->Message.pNode = pNode;
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 6112
// RVA: 0x72E060
void __fastcall Scaleform::GFx::AS3::ThunkInfo::EmptyFunc(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  const char *NamespaceName; // rdx
  const char *Name; // rdx
  Scaleform::String v8; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::String::String(&v8, "The method ");
  NamespaceName = ti->NamespaceName;
  if ( NamespaceName )
  {
    Scaleform::String::AppendString(&v8, NamespaceName, -1i64);
    Scaleform::String::AppendString(&v8, "::", -1i64);
  }
  Name = ti->Name;
  if ( Name )
  {
    Scaleform::String::AppendString(&v8, Name, -1i64);
    Scaleform::String::AppendString(&v8, "()", -1i64);
  }
  Scaleform::String::AppendString(&v8, " is not implemented\n", -1i64);
  vm->UI->vfptr->Output(vm->UI, Output_Warning, (const char *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 6138
// RVA: 0x81AC30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SetProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v7; // rcx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+48h] [rbp-38h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3 && (v7 = _this->value.VS._1, v7.VStr) )
  {
    (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v7.VStr->pData
     + 3))(
      v7,
      result,
      prop_name,
      value);
  }
  else
  {
    memset(&resulta, 0, 20);
    resulta.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&resulta, vm, _this, prop_name, FindSet);
    if ( (resulta.This.Flags & 0x1F) != 0
      && (((__int64)resulta.pSI & 1) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)resulta.pSI & 2) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      Scaleform::GFx::AS3::PropRef::SetSlotValue(&resulta, result, vm, value);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, 1056, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v12.Message.pNode;
      v10 = v12.Message.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      result->Result = 0;
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags & 0x200) != 0 )
      {
        v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&resulta.This.Bonus, 0, 24);
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
  }
  return result;
}

// File Line: 6169
// RVA: 0x7EE5E0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetPropertyUnsafe(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v7; // rcx
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+38h] [rbp-38h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3 && (v7 = _this->value.VS._1, v7.VStr) )
  {
    (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v7.VStr->pData
     + 4))(
      v7,
      result,
      prop_name,
      value);
  }
  else
  {
    memset(&resulta, 0, 20);
    resulta.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&resulta, vm, _this, prop_name, FindGet);
    if ( (resulta.This.Flags & 0x1F) != 0
      && (((__int64)resulta.pSI & 1) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)resulta.pSI & 2) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, result, vm, value, valGet);
    }
    else
    {
      result->Result = 0;
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags & 0x200) != 0 )
      {
        if ( resulta.This.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&resulta.This.Bonus, 0, 24);
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
  }
  return result;
}

// File Line: 6196
// RVA: 0x81AE10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::SetProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Value scope; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+40h] [rbp+Fh] BYREF

  pVM = this->pTraits.pObject->pVM;
  memset(&resulta, 0, 20);
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  scope.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, this->pTraits.pObject->pVM, &scope, prop_name, FindSet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  if ( (resulta.This.Flags & 0x1F) != 0
    && (((__int64)resulta.pSI & 1) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)resulta.pSI & 2) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    Scaleform::GFx::AS3::PropRef::SetSlotValue(&resulta, result, pVM, value);
  }
  else if ( (this->pTraits.pObject->Flags & 2) != 0
         && Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, pVM->PublicNamespace.pObject) )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD))this->vfptr[4].Finalize_GC)(
      this,
      &prop_name->Name,
      value,
      0i64);
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&scope, 1056, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v9, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)scope.Bonus.pWeakProxy;
    v11 = LODWORD(scope.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    result->Result = 0;
  }
  if ( (resulta.This.Flags & 0x1F) > 9 )
  {
    if ( (resulta.This.Flags & 0x200) != 0 )
    {
      v11 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&resulta.This.Bonus, 0, 24);
      resulta.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
    }
  }
  return result;
}

// File Line: 6232
// RVA: 0x7EDC60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::Extra v8; // rax
  Scaleform::GFx::AS3::Value::VU v9; // kr00_16
  bool v10; // zf
  Scaleform::GFx::AS3::Value scope; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+40h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v14; // [rsp+98h] [rbp+67h] BYREF

  pVM = this->pTraits.pObject->pVM;
  memset(&resulta, 0, 20);
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  scope.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, pVM, &scope, prop_name, FindGet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  if ( (resulta.This.Flags & 0x1F) == 0
    || ((__int64)resulta.pSI & 1) != 0 && ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)resulta.pSI & 2) != 0 && ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
LABEL_20:
    result->Result = 0;
    goto LABEL_21;
  }
  scope.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, &v14, pVM, &scope, valGet)->Result )
  {
    if ( (scope.Flags & 0x1F) > 9 )
    {
      if ( (scope.Flags & 0x200) != 0 )
      {
        v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&scope.Bonus, 0, 24);
        scope.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
      }
    }
    goto LABEL_20;
  }
  Flags = scope.Flags;
  v8.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)scope.Bonus;
  v9 = scope.value;
  scope.Flags = value->Flags;
  scope.Bonus.pWeakProxy = value->Bonus.pWeakProxy;
  scope.value = value->value;
  value->Flags = Flags;
  value->Bonus = v8;
  value->value = v9;
  result->Result = 1;
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags & 0x200) != 0 )
    {
      v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&scope.Bonus, 0, 24);
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
LABEL_21:
  if ( (resulta.This.Flags & 0x1F) > 9 )
  {
    if ( (resulta.This.Flags & 0x200) != 0 )
    {
      v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&resulta.This.Bonus, 0, 24);
      resulta.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
    }
  }
  return result;
}

// File Line: 6255
// RVA: 0x7E9370
void __fastcall Scaleform::GFx::AS3::Object::GetDynamicProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  p_DynAttrs = &this->DynAttrs;
  v4 = 0i64;
  pTable = this->DynAttrs.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 4;
    }
    while ( (unsigned __int64)v4 <= SizeMask );
    v4 = p_DynAttrs;
  }
  Scaleform::GFx::AS3::Value::Assign(
    value,
    (Scaleform::GFx::AS3::Value *)&v4->mHash.pTable[4 * (unsigned __int64)LODWORD(ind.Index) + 3]);
}

// File Line: 6263
// RVA: 0x7C0E20
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::DeleteProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  if ( (this->pTraits.pObject->Flags & 2) != 0 )
  {
    Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(this, result, prop_name);
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 6326
// RVA: 0x7B6BA0
void __fastcall Scaleform::GFx::AS3::Impl::CoerceInternal(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::TypeInfo *ti,
        Scaleform::GFx::AS3::Value *to,
        Scaleform::GFx::AS3::Value *from)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rax

  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, ti);
  if ( !v6
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v6->vfptr[3].Finalize_GC)(
          v6,
          from,
          to) )
  {
    Scaleform::GFx::AS3::Value::Assign(to, from);
  }
}

