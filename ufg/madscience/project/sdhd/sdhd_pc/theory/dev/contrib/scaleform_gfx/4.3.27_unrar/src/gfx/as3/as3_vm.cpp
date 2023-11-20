// File Line: 444
// RVA: 0x784BD0
void __fastcall Scaleform::GFx::AS3::VMFile::VMFile(Scaleform::GFx::AS3::VMFile *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMFile *v3; // rdi
  Scaleform::GFx::AS3::ASRefCountCollector *v4; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v7; // rdx
  bool v8; // zf
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340,Scaleform::ArrayDefaultPolicy> *v9; // [rsp+60h] [rbp+18h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340,Scaleform::ArrayDefaultPolicy> *v10; // [rsp+60h] [rbp+18h]

  v3 = this;
  v4 = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v4;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMFile::`vftable;
  this->VMRef = vm;
  this->AppDomain.pObject = appDomain;
  if ( appDomain )
    appDomain->RefCount = (appDomain->RefCount + 1) & 0x8FBFFFFF;
  this->IntNamespaces.Entries.mHash.pTable = 0i64;
  v9 = &this->IntNamespaceSets;
  *(_OWORD *)&v9->Data.Data = 0ui64;
  v9->Data.Policy.Capacity = 0i64;
  v5 = &this->IntStrings;
  v5->Data.Data = 0i64;
  v5->Data.Size = 0i64;
  v5->Data.Policy.Capacity = 0i64;
  this->ActivationTraitsCache.mHash.pTable = 0i64;
  v10 = &this->LoadedClasses;
  *(_OWORD *)&v10->Data.Data = 0ui64;
  v10->Data.Policy.Capacity = 0i64;
  this->ASStringNodeSet.pTable = 0i64;
  v6 = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  if ( vm->StringManagerRef->pStringManager != (Scaleform::GFx::ASStringManager *)-64i64 )
    ++vm->StringManagerRef->pStringManager->EmptyStringNode.RefCount;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy> *)&this->IntStrings.Data.Data,
    &this->IntStrings,
    this->IntStrings.Data.Size + 1);
  v7 = &v5->Data.Data[v3->IntStrings.Data.Size - 1];
  if ( v7 )
  {
    v7->pObject = v6;
    if ( v6 )
      ++v6->RefCount;
  }
  if ( v6 && !((unsigned __int8)v6 & 1) )
  {
    v8 = v6->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 450
// RVA: 0x78F9D0
void __fastcall Scaleform::GFx::AS3::VMFile::~VMFile(Scaleform::GFx::AS3::VMFile *this)
{
  Scaleform::GFx::AS3::VMFile *v1; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMFile::`vftable;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::~HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc> > *)&this->ASStringNodeSet.pTable);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->LoadedClasses);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&v1->ActivationTraitsCache.mHash.pTable);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->IntStrings.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&v1->IntNamespaceSets);
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::A)&v1->IntNamespaces.Entries.mHash.pTable);
  __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::A)&v1->IntNamespaces.Entries.mHash.pTable);
  v2 = v1->AppDomain.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->AppDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 454
// RVA: 0x7D6B50
void __fastcall Scaleform::GFx::AS3::VMFile::ForEachChild_GC(Scaleform::GFx::AS3::VMFile *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::VMFile *v3; // rbp
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // r14
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // r15
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rdi
  unsigned __int64 v8; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v10; // rcx
  signed __int64 v11; // r8
  unsigned __int64 v12; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> >::TableType *v13; // rcx
  unsigned __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rsi
  __int64 v17; // rcx
  _QWORD *v18; // rdx
  unsigned __int64 v19; // rcx
  _QWORD *v20; // rax
  unsigned __int64 v21; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v22; // rdx
  __m128i v23; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = op;
  v5 = prcc;
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::ForEachChild_GC(
    &this->IntNamespaces,
    prcc,
    op);
  v6 = v3->IntNamespaceSets.Data.Size;
  v7 = 0i64;
  v8 = 0i64;
  if ( v6 )
  {
    do
    {
      v9 = &v3->IntNamespaceSets.Data.Data[v8];
      if ( v9->pObject )
        v4(v5, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v9);
      ++v8;
    }
    while ( v8 < v6 );
  }
  v10 = v3->ActivationTraitsCache.mHash.pTable;
  v11 = (signed __int64)&v3->ActivationTraitsCache;
  if ( v10 )
  {
    v12 = v10->SizeMask;
    v13 = v10 + 1;
    v14 = 0i64;
    do
    {
      if ( v13->EntryCount != -2i64 )
        break;
      ++v14;
      v13 += 2;
    }
    while ( v14 <= v12 );
    v23.m128i_i64[0] = (__int64)&v3->ActivationTraitsCache;
    v23.m128i_i64[1] = v14;
  }
  else
  {
    v23 = 0ui64;
  }
  _mm_store_si128(&v23, v23);
  v15 = v23.m128i_i64[1];
  v16 = v23.m128i_i64[0];
  while ( v16 )
  {
    v17 = *(_QWORD *)v16;
    if ( !*(_QWORD *)v16 || v15 > *(_QWORD *)(v17 + 8) )
      break;
    v18 = (_QWORD *)(32 * v15 + v17 + 40);
    if ( *v18 )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, _QWORD *, signed __int64))v4)(v5, v18, v11);
    v19 = *(_QWORD *)(*(_QWORD *)v16 + 8i64);
    if ( v15 <= (signed __int64)v19 && ++v15 <= v19 )
    {
      v20 = (_QWORD *)(*(_QWORD *)v16 + 32 * v15 + 16);
      do
      {
        if ( *v20 != -2i64 )
          break;
        ++v15;
        v20 += 4;
      }
      while ( v15 <= v19 );
    }
  }
  v21 = v3->LoadedClasses.Data.Size;
  if ( v21 )
  {
    do
    {
      v22 = &v3->LoadedClasses.Data.Data[v7];
      if ( v22->pObject )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *, signed __int64))v4)(
          v5,
          v22,
          v11);
      ++v7;
    }
    while ( v7 < v21 );
  }
  if ( v3->AppDomain.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *, signed __int64))v4)(
      v5,
      &v3->AppDomain,
      v11);
}

// File Line: 481
// RVA: 0x7EA6B0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(Scaleform::GFx::AS3::VMFile *this, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v2; // rbx
  Scaleform::GFx::AS3::VMFile *v3; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rax
  Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340> *v5; // rdi
  signed __int64 v6; // rcx
  unsigned __int64 v7; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rcx
  unsigned int v9; // eax
  __int64 v11; // [rsp+28h] [rbp-30h]
  __int64 v12; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeRef key; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // [rsp+68h] [rbp+10h]
  char v15; // [rsp+70h] [rbp+18h]

  v2 = mn;
  v3 = this;
  if ( (mn->Kind & 3u) > 1
    || (v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
               &this->IntNamespaces,
               mn->Ind,
               mn->NextIndex)) == 0i64 )
  {
    v14 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, Scaleform::GFx::AS3::Abc::Multiname *))v3->vfptr[1].Finalize_GC)(
                                                          v3,
                                                          &v15,
                                                          v2);
    v11 = v2->Ind;
    v12 = v2->NextIndex;
    key.pFirst = (Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key *)&v11;
    key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&v14;
    v5 = &v3->IntNamespaces;
    v6 = 16i64;
    v7 = 5381i64;
    do
      v7 = *((unsigned __int8 *)&v11 + --v6) + 65599 * v7;
    while ( v6 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::A)&v5->Entries.mHash.pTable,
      v5,
      &key,
      v7);
    v8 = v14;
    if ( v14 )
    {
      if ( (unsigned __int8)v14 & 1 )
      {
        v14 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v14 - 1);
      }
      else
      {
        v9 = v14->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          v14->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
        }
      }
    }
    if ( (v2->Kind & 3u) > 1 )
      v4 = 0i64;
    else
      v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
             v5,
             v2->Ind,
             v2->NextIndex);
  }
  return v4->pObject;
}

// File Line: 495
// RVA: 0x7EA7D0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespace(Scaleform::GFx::AS3::VMFile *this, unsigned __int64 nsIndex)
{
  __int64 v2; // rdi
  Scaleform::GFx::AS3::VMFile *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rax
  signed __int64 v5; // rcx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  unsigned int v8; // eax
  __int64 v10; // [rsp+28h] [rbp-30h]
  __int64 v11; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeRef key; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // [rsp+60h] [rbp+8h]
  char v14; // [rsp+70h] [rbp+18h]

  v2 = nsIndex;
  v3 = this;
  v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
         &this->IntNamespaces,
         nsIndex,
         -1);
  if ( !v4 )
  {
    v13 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, __int64))v3->vfptr[1].~RefCountBaseGC<328>)(
                                                          v3,
                                                          &v14,
                                                          v2);
    v10 = v2;
    v11 = -1i64;
    key.pFirst = (Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key *)&v10;
    key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&v13;
    v5 = 16i64;
    v6 = 5381i64;
    do
      v6 = *((unsigned __int8 *)&v10 + --v5) + 65599 * v6;
    while ( v5 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::A)&v3->IntNamespaces.Entries.mHash.pTable,
      &v3->IntNamespaces,
      &key,
      v6);
    v7 = v13;
    if ( v13 )
    {
      if ( (unsigned __int8)v13 & 1 )
      {
        v13 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
      }
      else
      {
        v8 = v13->RefCount;
        if ( v8 & 0x3FFFFF )
        {
          v13->RefCount = v8 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    v4 = Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Get(
           &v3->IntNamespaces,
           v2,
           -1);
  }
  return v4->pObject;
}

// File Line: 509
// RVA: 0x7EA8D0
Scaleform::GFx::AS3::NamespaceSet *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(Scaleform::GFx::AS3::VMFile *this, unsigned __int64 nsSetIndex)
{
  unsigned __int64 v2; // rsi
  Scaleform::GFx::AS3::VMFile *v3; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet> *v4; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v5; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rbx
  unsigned int v9; // edx
  char v11; // [rsp+30h] [rbp+8h]

  v2 = nsSetIndex;
  v3 = this;
  if ( nsSetIndex >= this->IntNamespaceSets.Data.Size )
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->IntNamespaceSets.Data,
      nsSetIndex + 1);
  v4 = v3->IntNamespaceSets.Data.Data;
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v4[v2];
  if ( v4[v2].pObject )
    return v4[v2].pObject;
  v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, char *, unsigned __int64))v3->vfptr[2].ForEachChild_GC)(
                                                      v3,
                                                      &v11,
                                                      v2);
  v7 = *v5;
  v8 = *v6;
  if ( *v6 != *v5 )
  {
    if ( v7 )
    {
      if ( (unsigned __int8)v7 & 1 )
      {
        *v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v7 - 1);
      }
      else
      {
        v9 = v7->RefCount;
        if ( v9 & 0x3FFFFF )
        {
          v7->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    *v5 = v8;
  }
  return v3->IntNamespaceSets.Data.Data[v2].pObject;
}

// File Line: 521
// RVA: 0x7EA990
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VMFile::GetInternedString(Scaleform::GFx::AS3::VMFile *this, Scaleform::GFx::ASString *result, unsigned __int64 strIndex)
{
  unsigned __int64 v3; // rdi
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::AS3::VMFile *v5; // rbx
  signed __int64 v6; // r15
  Scaleform::GFx::ASStringNode **v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode **v9; // rsi
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v15; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString *v16; // [rsp+58h] [rbp+10h]

  v16 = result;
  v3 = strIndex;
  v4 = result;
  v5 = this;
  if ( strIndex >= this->IntStrings.Data.Size )
    Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->IntStrings.Data,
      strIndex + 1);
  v6 = v3;
  if ( !v5->IntStrings.Data.Data[v3].pObject )
  {
    v7 = (Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, Scaleform::GFx::ASStringNode **, unsigned __int64))v5->vfptr[2].Finalize_GC)(
                                            v5,
                                            &v15,
                                            v3);
    v8 = *v7;
    v9 = &v5->IntStrings.Data.Data[v6].pObject;
    if ( *v7 != *v9 )
    {
      if ( v8 )
        ++v8->RefCount;
      v10 = *v9;
      if ( *v9 )
      {
        if ( (unsigned __int8)v10 & 1 )
        {
          *v9 = (Scaleform::GFx::ASStringNode *)((char *)v10 - 1);
        }
        else
        {
          v11 = v10->RefCount-- == 1;
          if ( v11 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        }
      }
      *v9 = v8;
    }
    v12 = v15;
    v11 = v15->RefCount == 1;
    --v12->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  v13 = v5->IntStrings.Data.Data[v6].pObject;
  v4->pNode = v13;
  ++v13->RefCount;
  return v4;
}

// File Line: 532
// RVA: 0x7E5B80
Scaleform::GFx::AS3::RefCountBaseGC<328> *__fastcall Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(Scaleform::GFx::AS3::VMFile *this, Scaleform::GFx::AS3::Abc::MbiInd mbi_ind)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::VMFile *v3; // rsi
  __int64 v4; // rax
  signed __int64 v5; // rax
  signed __int64 v6; // rax
  signed __int64 v8; // rdx
  unsigned __int64 v9; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  unsigned int v11; // eax
  Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeRef v12; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::Abc::MbiInd key; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // [rsp+70h] [rbp+18h]

  key.Ind = mbi_ind.Ind;
  v2 = mbi_ind.Ind;
  v3 = this;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&this->ActivationTraitsCache.mHash.pTable,
         &key);
  if ( v4 >= 0 )
  {
    v5 = (signed __int64)&v3->ActivationTraitsCache.mHash.pTable[2 * (v4 + 1)];
    if ( v5 )
    {
      v6 = v5 + 8;
      if ( v6 )
        return *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v6;
    }
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::VMFile *, Scaleform::GFx::AS3::RefCountBaseGC<328> **, _QWORD))v3->vfptr[2].~RefCountBaseGC<328>)(
    v3,
    &v15,
    v2);
  v13 = v15;
  v12.pFirst = &key;
  v12.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *)&v13;
  v8 = 4i64;
  v9 = 5381i64;
  do
    v9 = *((unsigned __int8 *)&key.Ind + --v8) + 65599 * v9;
  while ( v8 );
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::add<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&v3->ActivationTraitsCache.mHash.pTable,
    &v3->ActivationTraitsCache,
    &v12,
    v9);
  v10 = v13;
  if ( v13 )
  {
    if ( (unsigned __int8)v13 & 1 )
    {
      v13 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
    }
    else
    {
      v11 = v13->RefCount;
      if ( v11 & 0x3FFFFF )
      {
        v13->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
  }
  return v15;
}

// File Line: 570
// RVA: 0x784A00
void __fastcall Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::VM *vm, Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::Resource **v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbp
  Scaleform::GFx::AS3::VMAbcFile *v6; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::MethodInfo,340,Scaleform::ArrayDefaultPolicy> *v7; // r14
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rdi
  signed __int64 v10; // [rsp+60h] [rbp+18h]

  v4 = (Scaleform::GFx::Resource **)file;
  v5 = vm;
  v6 = this;
  Scaleform::GFx::AS3::VMFile::VMFile((Scaleform::GFx::AS3::VMFile *)&this->vfptr, vm, appDomain);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAbcFile::`vftable;
  if ( *v4 )
    Scaleform::Render::RenderBuffer::AddRef(*v4);
  v6->File.pObject = (Scaleform::GFx::AS3::Abc::File *)*v4;
  v6->AbsObjects.pTable = 0i64;
  v6->GlobalObjects.pTable = 0i64;
  v10 = (signed __int64)&v6->Children;
  *(_OWORD *)v10 = 0ui64;
  *(_QWORD *)(v10 + 16) = 0i64;
  v6->FunctionTraitsCache.mHash.pTable = 0i64;
  v7 = &v6->MethodInfoArray;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  v6->AliasClass.pTable = 0i64;
  v6->RefCount |= 0x2000000u;
  v8 = (unsigned __int64)(*v4)[14].pLib;
  v9 = v6->MethodInfoArray.Data.Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy> *)&v6->MethodInfoArray.Data.Data,
    &v6->MethodInfoArray,
    v8);
  if ( v8 > v9 )
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::MethodInfo>::ConstructArray(&v7->Data.Data[v9], v8 - v9);
  Scaleform::GFx::AS3::VM::AddVMAbcFileWeak(v5, v6);
}

// File Line: 583
// RVA: 0x78F610
void __fastcall Scaleform::GFx::AS3::VMAbcFile::~VMAbcFile(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile *v1; // r12
  Scaleform::GFx::AS3::VM *v2; // r13
  void **v3; // rbp
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v4; // rdx
  unsigned __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> >::TableType *v6; // rcx
  __int64 v7; // rbx
  __int64 v8; // r14
  __int64 v9; // rcx
  Scaleform::GFx::ASString *v10; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::TableType *v11; // r8
  Scaleform::GFx::ASStringNode *v12; // r11
  signed __int64 v13; // r10
  __int64 v14; // r9
  signed __int64 v15; // rdi
  unsigned __int64 *v16; // rdx
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  __int64 v20; // rdi
  signed __int64 v21; // rsi
  char *v22; // rbx
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  unsigned __int64 v25; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **i; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v27; // rcx
  unsigned int v28; // eax
  Scaleform::Render::RenderBuffer *v29; // rcx
  __m128i v30; // [rsp+30h] [rbp-48h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAbcFile::`vftable;
  v2 = this->VMRef;
  v3 = (void **)&this->AliasClass.pTable;
  v4 = this->AliasClass.pTable;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4 + 1;
    do
    {
      if ( v6->EntryCount != -2i64 )
        break;
      ++v5;
      ++v6;
    }
    while ( v5 <= v4->SizeMask );
    v30.m128i_i64[0] = (__int64)v3;
    v30.m128i_i64[1] = v5;
  }
  else
  {
    v30 = 0ui64;
  }
  _mm_store_si128(&v30, v30);
  v7 = v30.m128i_i64[1];
  v8 = v30.m128i_i64[0];
  while ( v8 )
  {
    v9 = *(_QWORD *)v8;
    if ( !*(_QWORD *)v8 || v7 > *(_QWORD *)(v9 + 8) )
      break;
    v10 = (Scaleform::GFx::ASString *)(v9 + 16 * v7);
    v11 = v2->AliasClass.mHash.pTable;
    if ( v11 )
    {
      v12 = v10[3].pNode;
      v13 = v11->SizeMask;
      v14 = (unsigned int)v13 & v12->HashFlags;
      v15 = v14;
      v16 = &v11->EntryCount + v14 + 2 * (v14 + 1);
      if ( *v16 != -2i64 && ((unsigned int)v13 & *(_DWORD *)(v16[1] + 28)) == v14 )
      {
        while ( 1 )
        {
          v17 = (Scaleform::GFx::ASStringNode *)v16[1];
          if ( ((unsigned int)v13 & v17->HashFlags) == v14 && v17 == v12 )
            break;
          v15 = *v16;
          if ( *v16 == -1i64 )
            goto LABEL_22;
          v16 = &v11->EntryCount + v15 + 2 * (v15 + 1);
        }
        if ( v15 >= 0 && v2 != (Scaleform::GFx::AS3::VM *)-704i64 && v15 <= v13 )
        {
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::ASString>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->AliasClass,
            v10 + 3);
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Class *>(
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v2->ClassAlias.mHash.pTable,
            (Scaleform::GFx::AS3::Class *const *)&v2->AliasClass.mHash.pTable->EntryCount + v15 + 2 * (v15 + 2));
        }
      }
    }
LABEL_22:
    v18 = *(_QWORD *)(*(_QWORD *)v8 + 8i64);
    if ( v7 <= (signed __int64)v18 && ++v7 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)v8 + 16 * (v7 + 1));
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v7;
        v19 += 2;
      }
      while ( v7 <= v18 );
    }
  }
  Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(v2, v1);
  if ( *v3 )
  {
    v20 = 0i64;
    v21 = *((_QWORD *)*v3 + 1) + 1i64;
    do
    {
      v22 = (char *)*v3;
      if ( *(_QWORD *)((char *)*v3 + v20 + 16) != -2i64 )
      {
        v23 = *(Scaleform::GFx::ASStringNode **)&v22[v20 + 24];
        v24 = v23->RefCount-- == 1;
        if ( v24 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        *(_QWORD *)&v22[v20 + 16] = -2i64;
      }
      v20 += 16i64;
      --v21;
    }
    while ( v21 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
    *v3 = 0i64;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::MethodInfo>::DestructArray(
    v1->MethodInfoArray.Data.Data,
    v1->MethodInfoArray.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->MethodInfoArray.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&v1->FunctionTraitsCache);
  v25 = v1->Children.Data.Size;
  for ( i = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v1->Children.Data.Data[v25 - 1]; v25; --v25 )
  {
    v27 = *i;
    if ( *i )
    {
      if ( (unsigned __int8)v27 & 1 )
      {
        *i = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v27 - 1);
      }
      else
      {
        v28 = v27->RefCount;
        if ( v28 & 0x3FFFFF )
        {
          v27->RefCount = v28 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
        }
      }
    }
    --i;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Children.Data.Data);
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v1->GlobalObjects.pTable);
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v1->AbsObjects);
  v29 = (Scaleform::Render::RenderBuffer *)v1->File.pObject;
  if ( v29 )
    Scaleform::RefCountImpl::Release(v29);
  Scaleform::GFx::AS3::VMFile::~VMFile((Scaleform::GFx::AS3::VMFile *)&v1->vfptr);
}

// File Line: 604
// RVA: 0x7D1880
void __fastcall Scaleform::GFx::AS3::VMAbcFile::Finalize_GC(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile::UnRegister(this);
}

// File Line: 610
// RVA: 0x7FEB30
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rdi
  Scaleform::GFx::AS3::VMAbcFile *v5; // rbp
  Scaleform::GFx::AS3::Abc::File *v6; // rbx
  signed __int64 v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rax
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v9; // r15
  __int64 v10; // rax
  Scaleform::GFx::AS3::Abc::Multiname *v11; // rax
  signed __int64 v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString v19; // [rsp+68h] [rbp+10h]

  v3 = mn;
  v4 = result;
  v5 = this;
  v6 = this->File.pObject;
  if ( mn->Ind )
    v7 = (signed __int64)&v6->Const_Pool.ConstNamespace.Data.Data[mn->Ind];
  else
    v7 = (signed __int64)&v6->Const_Pool.any_namespace;
  v8 = this->VMRef;
  v9 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins,
    &resulta,
    *(const char **)(v7 + 8),
    *(_QWORD *)(v7 + 16));
  v10 = v3->NextIndex;
  if ( (signed int)v10 >= 0 )
  {
    v11 = &v6->Const_Pool.const_multiname.Data.Data[v10];
    v12 = (signed __int64)(v11->Ind ? &v6->Const_Pool.ConstNamespace.Data.Data[v11->Ind] : &v6->Const_Pool.any_namespace);
    Scaleform::GFx::ASString::Append(&resulta, "$", 1ui64);
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v9,
            &v19,
            *(const char **)(v12 + 8),
            *(_QWORD *)(v12 + 16));
    Scaleform::GFx::ASString::Append(&resulta, v13);
    v14 = v19.pNode;
    v15 = v19.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(
    v5->VMRef,
    v4,
    *(Scaleform::GFx::AS3::Abc::NamespaceKind *)v7,
    &resulta);
  v16 = resulta.pNode;
  v15 = resulta.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return v4;
}

// File Line: 631
// RVA: 0x7FEC50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespace(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, unsigned __int64 nsIndex)
{
  Scaleform::GFx::AS3::Abc::File *v3; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rbx
  signed __int64 v5; // rax

  v3 = this->File.pObject;
  v4 = result;
  if ( nsIndex )
    v5 = (signed __int64)&v3->Const_Pool.ConstNamespace.Data.Data[nsIndex];
  else
    v5 = (signed __int64)&v3->Const_Pool.any_namespace;
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(
    this->VMRef,
    result,
    *(Scaleform::GFx::AS3::Abc::NamespaceKind *)v5,
    (Scaleform::StringDataPtr *)(v5 + 8));
  return v4;
}

// File Line: 637
// RVA: 0x7FECA0
Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedNamespaceSet(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *result, unsigned __int64 nsSetIndex)
{
  unsigned __int64 v3; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *v4; // r14
  Scaleform::GFx::AS3::VMAbcFile *v5; // rbp
  Scaleform::GFx::AS3::NamespaceSet *v6; // rdi
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // rdx
  const char *v8; // rbx
  char v9; // al
  char *v10; // rbx
  unsigned int v11; // er8
  unsigned int v12; // ecx
  char v13; // dl
  __int64 v14; // rsi
  char v15; // al
  unsigned int v16; // er8
  unsigned int v17; // ecx
  char v18; // dl
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::NamespaceSet> *v20; // rax
  signed __int64 v21; // [rsp+70h] [rbp+18h]

  v3 = nsSetIndex;
  v4 = result;
  v5 = this;
  v6 = (Scaleform::GFx::AS3::NamespaceSet *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMAbcFile *, signed __int64))this->VMRef->MHeap->vfptr->Alloc)(
                                              this,
                                              64i64);
  if ( v6 )
  {
    v7 = v5->VMRef->GC.GC;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    v6->RefCount = 1;
    v6->pRCCRaw = (unsigned __int64)v7;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::NamespaceSet::`vftable;
    v21 = (signed __int64)&v6->Namespaces;
    *(_OWORD *)v21 = 0ui64;
    *(_QWORD *)(v21 + 16) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v8 = v5->File.pObject->Const_Pool.const_ns_set.Data.Data[v3].Data;
  v9 = *v8;
  v10 = (char *)(v8 + 1);
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
      v19 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&v5->vfptr, v16);
      Scaleform::GFx::AS3::NamespaceSet::Add(v6, v19);
      --v14;
    }
    while ( v14 );
  }
  v20 = v4;
  v4->pV = v6;
  return v20;
}

// File Line: 657
// RVA: 0x7FA450
Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeActivationInstanceTraits(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *result, Scaleform::GFx::AS3::Abc::MbiInd mbi_ind)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> *v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v6; // rbp
  Scaleform::GFx::AS3::InstanceTraits::Activation *v7; // rax

  v3 = result;
  v4 = this;
  v5 = this->VMRef;
  v6 = this->File.pObject->MethodBodies.Info.Data.Data[mbi_ind.Ind];
  v7 = (Scaleform::GFx::AS3::InstanceTraits::Activation *)v5->MHeap->vfptr->Alloc(
                                                            (Scaleform::MemoryHeap *)this,
                                                            216ui64,
                                                            0i64);
  if ( v7 )
    Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(v7, v4, v5, v6);
  v3->pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  return v3;
}

// File Line: 665
// RVA: 0x7FEDF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VMAbcFile::MakeInternedString(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::ASString *result, unsigned __int64 strIndex)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v4; // r10
  unsigned __int64 v5; // r9
  const char *v6; // r8
  const char *v7; // r8
  char v8; // al
  unsigned int v9; // ecx
  char v10; // dl

  v3 = result;
  v4 = this;
  v5 = 0i64;
  v6 = this->File.pObject->Const_Pool.ConstStr.Data.Data[(unsigned int)strIndex].Data;
  if ( v6 )
  {
    v8 = *v6;
    v7 = v6 + 1;
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
    v5 = (signed int)v5;
  }
  else
  {
    v7 = &customWorldMapCaption;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->VMRef->StringManagerRef->Builtins,
    v3,
    v7,
    v5);
  return v3;
}

// File Line: 672
// RVA: 0x7D6830
void __fastcall Scaleform::GFx::AS3::VMAbcFile::ForEachChild_GC(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // r15
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // r12
  Scaleform::GFx::AS3::VMAbcFile *v5; // r14
  unsigned __int64 v6; // rsi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *v7; // rcx
  unsigned __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *v9; // rcx
  unsigned __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rcx
  signed __int64 v14; // rdx
  bool v15; // zf
  signed __int64 v16; // rdx
  unsigned __int64 v17; // rdx
  _QWORD *v18; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v19; // rcx
  unsigned __int64 v20; // rdx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v21; // rcx
  unsigned __int64 v22; // rax
  __int64 v23; // rbx
  __int64 v24; // rdi
  __int64 v25; // rcx
  signed __int64 v26; // rdx
  signed __int64 v27; // rdx
  unsigned __int64 v28; // rdx
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rdi
  unsigned __int64 v31; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v32; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v33; // rax
  unsigned __int64 v34; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v35; // rax
  __int64 v36; // rbx
  __int64 v37; // rdi
  __int64 v38; // rcx
  unsigned __int64 v39; // rdx
  _QWORD *v40; // rcx
  __m128i v41; // [rsp+20h] [rbp-10h]

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::VMFile::ForEachChild_GC((Scaleform::GFx::AS3::VMFile *)&this->vfptr, prcc, op);
  v6 = 0i64;
  v7 = v5->AbsObjects.pTable;
  if ( v7 )
  {
    v8 = v7->SizeMask;
    v9 = v7 + 1;
    v10 = 0i64;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v10;
      v9 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::TableType *)((char *)v9 + 24);
    }
    while ( v10 <= v8 );
    v41.m128i_i64[0] = (__int64)&v5->AbsObjects;
    v41.m128i_i64[1] = v10;
  }
  else
  {
    v41 = 0ui64;
  }
  _mm_store_si128(&v41, v41);
  v11 = v41.m128i_i64[1];
  v12 = v41.m128i_i64[0];
  while ( v12 )
  {
    v13 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 || v11 > *(_QWORD *)(v13 + 8) )
      break;
    v14 = v11 + 2 * (v11 + 2);
    v15 = *(_QWORD *)(v13 + 8 * v14) == 0i64;
    v16 = v13 + 8 * v14;
    if ( !v15 )
      v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v16);
    v17 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
    if ( v11 <= (signed __int64)v17 && ++v11 <= v17 )
    {
      v18 = (_QWORD *)(*(_QWORD *)v12 + 24 * v11 + 16);
      do
      {
        if ( *v18 != -2i64 )
          break;
        ++v11;
        v18 += 3;
      }
      while ( v11 <= v17 );
    }
  }
  v19 = v5->GlobalObjects.pTable;
  if ( v19 )
  {
    v20 = v19->SizeMask;
    v21 = v19 + 1;
    v22 = 0i64;
    do
    {
      if ( v21->EntryCount != -2i64 )
        break;
      ++v22;
      v21 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *)((char *)v21 + 24);
    }
    while ( v22 <= v20 );
    v41.m128i_i64[0] = (__int64)&v5->GlobalObjects;
    v41.m128i_i64[1] = v22;
  }
  else
  {
    v41 = 0ui64;
  }
  _mm_store_si128(&v41, v41);
  v23 = v41.m128i_i64[1];
  v24 = v41.m128i_i64[0];
  while ( v24 )
  {
    v25 = *(_QWORD *)v24;
    if ( !*(_QWORD *)v24 || v23 > *(_QWORD *)(v25 + 8) )
      break;
    v26 = v23 + 2 * (v23 + 2);
    v15 = *(_QWORD *)(v25 + 8 * v26) == 0i64;
    v27 = v25 + 8 * v26;
    if ( !v15 )
      v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v27);
    v28 = *(_QWORD *)(*(_QWORD *)v24 + 8i64);
    if ( v23 <= (signed __int64)v28 && ++v23 <= v28 )
    {
      v29 = (_QWORD *)(*(_QWORD *)v24 + 24 * v23 + 16);
      do
      {
        if ( *v29 != -2i64 )
          break;
        ++v23;
        v29 += 3;
      }
      while ( v23 <= v28 );
    }
  }
  v30 = v5->Children.Data.Size;
  v31 = 0i64;
  if ( v30 )
  {
    do
    {
      v32 = &v5->Children.Data.Data[v31];
      if ( v32->pObject )
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v32);
      ++v31;
    }
    while ( v31 < v30 );
  }
  v33 = v5->FunctionTraitsCache.mHash.pTable;
  if ( v33 )
  {
    v34 = v33->SizeMask;
    v35 = v33 + 1;
    do
    {
      if ( v35->EntryCount != -2i64 )
        break;
      ++v6;
      v35 += 2;
    }
    while ( v6 <= v34 );
    v41.m128i_i64[0] = (__int64)&v5->FunctionTraitsCache;
  }
  else
  {
    v41.m128i_i64[0] = 0i64;
  }
  v41.m128i_i64[1] = v6;
  _mm_store_si128(&v41, v41);
  v36 = v41.m128i_i64[1];
  v37 = v41.m128i_i64[0];
  while ( v37 )
  {
    v38 = *(_QWORD *)v37;
    if ( !*(_QWORD *)v37 || v36 > *(_QWORD *)(v38 + 8) )
      break;
    if ( *(_QWORD *)(32 * v36 + v38 + 40) )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
    v39 = *(_QWORD *)(*(_QWORD *)v37 + 8i64);
    if ( v36 <= (signed __int64)v39 && ++v36 <= v39 )
    {
      v40 = (_QWORD *)(32 * v36 + *(_QWORD *)v37 + 16i64);
      do
      {
        if ( *v40 != -2i64 )
          break;
        ++v36;
        v40 += 4;
      }
      while ( v36 <= v39 );
    }
  }
}

// File Line: 710
// RVA: 0x8104C0
char __fastcall Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile *v1; // rsi
  Scaleform::GFx::AS3::Abc::File *v2; // rax
  __int64 v3; // r15
  Scaleform::GFx::AS3::VM *v4; // r13
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v7; // r12
  Scaleform::GFx::AS3::Abc::Multiname *v8; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *v13; // r15
  Scaleform::GFx::AS3::VMAppDomain *v14; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v15; // r14
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *v17; // r14
  signed __int64 v18; // rax
  signed __int64 v19; // r14
  unsigned int v20; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // rax
  Scaleform::MemoryHeap *v23; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v24; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::ASStringNode *v27; // rcx
  __int64 v28; // rdi
  unsigned __int64 v29; // rdx
  unsigned __int64 v30; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v31; // rax
  Scaleform::MemoryHeap *v32; // rdx
  int v33; // eax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v34; // rax
  __int64 v35; // rax
  __int64 v36; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v37; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::MemoryHeap *v41; // rdx
  int v42; // eax
  Scaleform::GFx::ASStringNode *v43; // rcx
  unsigned __int64 v44; // rdi
  Scaleform::GFx::AS3::Abc::ClassInfo *v45; // r14
  Scaleform::GFx::AS3::Abc::Multiname *v46; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v47; // rbx
  Scaleform::GFx::ASStringNode *v48; // rax
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v49; // rax
  Scaleform::GFx::ASStringNode *v50; // rcx
  char v51; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rdi
  unsigned int v54; // eax
  Scaleform::GFx::ASStringNode *v55; // rcx
  _QWORD *v57; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::ASStringNode *v58; // [rsp+28h] [rbp-61h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v59; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::ASStringNode *v61; // [rsp+48h] [rbp-41h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v62; // [rsp+50h] [rbp-39h]
  Scaleform::MemoryHeap *v63; // [rsp+58h] [rbp-31h]
  unsigned __int64 v64; // [rsp+60h] [rbp-29h]
  __int64 v65; // [rsp+68h] [rbp-21h]
  __int64 v66; // [rsp+70h] [rbp-19h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v67; // [rsp+78h] [rbp-11h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v68; // [rsp+88h] [rbp-1h]
  __int64 v69; // [rsp+98h] [rbp+Fh]
  __int64 v70; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+6Fh]
  unsigned __int64 v72; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::AS3::Abc::File *v73; // [rsp+108h] [rbp+7Fh]

  v69 = -2i64;
  v1 = this;
  v2 = this->File.pObject;
  v73 = v2;
  v3 = 0i64;
  v70 = 0i64;
  v4 = this->VMRef;
  v5 = v2->AS3_Classes.Info.Data.Size;
  v64 = v5;
  v6 = 0i64;
  v72 = 0i64;
  if ( !v5 )
  {
LABEL_73:
    v44 = 0i64;
    if ( v5 )
    {
      do
      {
        v45 = v73->AS3_Classes.Info.Data.Data[v44];
        v46 = &v1->File.pObject->Const_Pool.const_multiname.Data.Data[v45->inst_info.name_ind];
        Scaleform::GFx::AS3::VMFile::GetInternedString(
          (Scaleform::GFx::AS3::VMFile *)&v1->vfptr,
          &result,
          v46->NameIndex);
        v47 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&v1->vfptr, v46->Ind);
        if ( !(_S13_9 & 1) )
        {
          _S13_9 |= 1u;
          scaleform_gfx.pStr = "scaleform.gfx";
          scaleform_gfx.Size = 13i64;
        }
        v48 = v47->Uri.pNode;
        if ( v48->Size < scaleform_gfx.Size || strncmp(v48->pData, scaleform_gfx.pStr, scaleform_gfx.Size) )
        {
          v49 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
                                                                   v4,
                                                                   (Scaleform::GFx::AS3::VMFile *)&v1->vfptr,
                                                                   v45);
          if ( v49->File.pObject == v1
            && !Scaleform::GFx::AS3::ClassTraits::UserDefined::Initialize(v49, (Scaleform::GFx::AS3::CheckResult *)&v70)->Result )
          {
            if ( v4->HandleException )
              Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v4);
            v52 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v1->AppDomain.pObject;
            v53 = result.pNode;
            key.Name = result;
            ++key.Name.pNode->RefCount;
            key.pNs.pObject = v47;
            if ( v47 )
              v47->RefCount = (v47->RefCount + 1) & 0x8FBFFFFF;
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
              v52 + 6,
              (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&key);
            if ( v47 )
            {
              if ( (unsigned __int8)v47 & 1 )
              {
                key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v47 - 1);
              }
              else
              {
                v54 = v47->RefCount;
                if ( v54 & 0x3FFFFF )
                {
                  v47->RefCount = v54 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v47->vfptr);
                }
              }
            }
            v12 = v53->RefCount-- == 1;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v53);
            v55 = result.pNode;
            v12 = result.pNode->RefCount == 1;
            --v55->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v55);
            Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(v1);
            return 0;
          }
        }
        v50 = result.pNode;
        v12 = result.pNode->RefCount == 1;
        --v50->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v50);
        ++v44;
      }
      while ( v44 < v5 );
      v51 = 0;
      if ( v5 && !v3 )
        return v51;
    }
    return 1;
  }
  do
  {
    v7 = v2->AS3_Classes.Info.Data.Data[v6];
    v8 = &v1->File.pObject->Const_Pool.const_multiname.Data.Data[v7->inst_info.name_ind];
    Scaleform::GFx::AS3::VMFile::GetInternedString((Scaleform::GFx::AS3::VMFile *)&v1->vfptr, &result, v8->NameIndex);
    v9 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&v1->vfptr, v8->Ind);
    if ( !(_S13_9 & 1) )
    {
      _S13_9 |= 1u;
      scaleform_gfx.pStr = "scaleform.gfx";
      scaleform_gfx.Size = 13i64;
    }
    v10 = v9->Uri.pNode;
    if ( v10->Size >= scaleform_gfx.Size && !strncmp(v10->pData, scaleform_gfx.pStr, scaleform_gfx.Size) )
    {
      v11 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      goto LABEL_70;
    }
    v13 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)v1->AppDomain.pObject;
    v14 = (Scaleform::GFx::AS3::VMAppDomain *)v13[5].pTable;
    if ( v14 )
    {
      v15 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v14, &result, v9);
      if ( v15 )
        goto LABEL_105;
    }
    v16 = result.pNode;
    key.Name = result;
    ++key.Name.pNode->RefCount;
    key.pNs.pObject = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v17 = v13[6].pTable;
    if ( v17
      && (v18 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                  v13 + 6,
                  &key,
                  v17->SizeMask & (v16->HashFlags & 0xFFFFFF ^ 4 * (v9->Uri.pNode->HashFlags & 0xFFFFFF) ^ (unsigned __int64)(unsigned int)(*((_QWORD *)v9 + 5) << 60 >> 60))),
          v18 >= 0)
      && (v19 = (signed __int64)&v17[2] + 40 * v18) != 0 )
    {
      v15 = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v19 + 16);
    }
    else
    {
      v15 = 0i64;
    }
    if ( v9 )
    {
      if ( (unsigned __int8)v9 & 1 )
      {
        key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v9 - 1);
      }
      else
      {
        v20 = v9->RefCount;
        if ( v20 & 0x3FFFFF )
        {
          v9->RefCount = v20 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
        }
      }
    }
    v12 = v16->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( v15 )
    {
LABEL_105:
      v21 = *v15;
      if ( *v15 )
        goto LABEL_36;
    }
    v22 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(v4->GlobalObject.pObject, &result, v9);
    v21 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v22;
    if ( v22 )
    {
      v24 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v4->SystemDomain.pObject;
      v57 = &v22->vfptr;
      v58 = result.pNode;
      ++v58->RefCount;
      v59 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr;
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
      v68.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v58;
      v68.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v57;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        v24 + 6,
        v24[7].pTable,
        &v68,
        v58->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v59[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v59[1].vfptr << 60 >> 60));
      v25 = v59;
      if ( v59 )
      {
        if ( (unsigned __int8)v59 & 1 )
        {
          v59 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v59 - 1);
        }
        else
        {
          v26 = v59->RefCount;
          if ( v26 & 0x3FFFFF )
          {
            v59->RefCount = v26 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
          }
        }
      }
      v27 = v58;
      v12 = v58->RefCount == 1;
      --v27->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
LABEL_36:
      v28 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))v21->vfptr[2].~RefCountBaseGC<328>)(v21);
      if ( v28 )
      {
        v29 = v1->Children.Data.Size;
        v30 = 0i64;
        if ( v29 )
        {
          v31 = v1->Children.Data.Data;
          while ( v31->pObject != (Scaleform::GFx::AS3::VMAbcFile *)v28 )
          {
            ++v30;
            ++v31;
            if ( v30 >= v29 )
              goto LABEL_41;
          }
        }
        else
        {
LABEL_41:
          v65 = v28;
          *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->Children.Data.Data,
            &v1->Children,
            v1->Children.Data.Size + 1);
          v32 = (Scaleform::MemoryHeap *)&v1->Children.Data.Data[v1->Children.Data.Size - 1];
          v57 = &v32->vfptr;
          v63 = v32;
          if ( v32 )
          {
            v32->vfptr = (Scaleform::MemoryHeapVtbl *)v28;
            *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
          }
          if ( v28 & 1 )
          {
            v65 = v28 - 1;
          }
          else
          {
            v33 = *(_DWORD *)(v28 + 32);
            if ( v33 & 0x3FFFFF )
            {
              *(_DWORD *)(v28 + 32) = v33 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v28);
            }
          }
        }
      }
      v3 = v70;
      goto LABEL_68;
    }
    v63 = v4->MHeap;
    v34 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)v63->vfptr->Alloc(v23, 224ui64, 0i64);
    v57 = &v34->vfptr;
    if ( v34 )
    {
      Scaleform::GFx::AS3::ClassTraits::UserDefined::UserDefined(v34, v1, v4, v7);
      v36 = v35;
    }
    else
    {
      v36 = 0i64;
    }
    v37 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v1->AppDomain.pObject;
    v57 = (_QWORD *)v36;
    v61 = result.pNode;
    ++v61->RefCount;
    v62 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v67.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v61;
    v67.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v57;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
      v37 + 6,
      v37[7].pTable,
      &v67,
      v61->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v62[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v62[1].vfptr << 60 >> 60));
    v38 = v62;
    if ( v62 )
    {
      if ( (unsigned __int8)v62 & 1 )
      {
        v62 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v62 - 1);
      }
      else
      {
        v39 = v62->RefCount;
        if ( v39 & 0x3FFFFF )
        {
          v62->RefCount = v39 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
        }
      }
    }
    v40 = v61;
    v12 = v61->RefCount == 1;
    --v40->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    v3 = v70++ + 1;
    v66 = v36;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->LoadedClasses,
      &v1->LoadedClasses,
      v1->LoadedClasses.Data.Size + 1);
    v41 = (Scaleform::MemoryHeap *)&v1->LoadedClasses.Data.Data[v1->LoadedClasses.Data.Size - 1];
    v63 = v41;
    v57 = &v41->vfptr;
    if ( v41 )
    {
      v41->vfptr = (Scaleform::MemoryHeapVtbl *)v36;
      if ( v36 )
        *(_DWORD *)(v36 + 32) = (*(_DWORD *)(v36 + 32) + 1) & 0x8FBFFFFF;
    }
    if ( v36 )
    {
      if ( v36 & 1 )
      {
        v66 = v36 - 1;
      }
      else
      {
        v42 = *(_DWORD *)(v36 + 32);
        if ( v42 & 0x3FFFFF )
        {
          *(_DWORD *)(v36 + 32) = v42 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v36);
        }
      }
    }
LABEL_68:
    v43 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v43->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
LABEL_70:
    v6 = v72 + 1;
    v72 = v6;
    v5 = v64;
    v2 = v73;
  }
  while ( v6 < v64 );
  if ( v3 || !v64 )
    goto LABEL_73;
  return 0;
}

// File Line: 872
// RVA: 0x8292D0
void __fastcall Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *v1; // rbp
  unsigned __int64 v2; // r14
  unsigned __int64 v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rdi
  unsigned int v9; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v12; // rcx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key key; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v14; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::ClassTraits::Traits *v; // [rsp+68h] [rbp+10h]

  v1 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)this;
  v2 = this->LoadedClasses.Data.Size;
  v3 = 0i64;
  if ( v2 )
  {
    do
    {
      v4 = v1[5].Data;
      v5 = v4[v3].pObject->FunctionTraitsCache.mHash.pTable;
      if ( v5 )
      {
        (*(void (__fastcall **)(Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::TableType *, Scaleform::GFx::ASStringNode **))(v5->EntryCount + 32))(
          v5,
          &v14);
        v6 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v5[12].SizeMask;
        v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v1[2].Data;
        v8 = v14;
        key.Name.pNode = v14;
        ++key.Name.pNode->RefCount;
        key.pNs.pObject = v6;
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
          v7 + 6,
          &key);
        if ( v6 )
        {
          if ( (unsigned __int8)v6 & 1 )
          {
            key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v6 - 1);
          }
          else
          {
            v9 = v6->RefCount;
            if ( v9 & 0x3FFFFF )
            {
              v6->RefCount = v9 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
            }
          }
        }
        v10 = v8->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        v11 = v14;
        v10 = v14->RefCount == 1;
        --v11->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      }
      else
      {
        v12 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v1[2].Data;
        v = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4[v3].pObject;
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::RemoveValue(v12 + 3, &v);
      }
      ++v3;
    }
    while ( v3 < v2 );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v1 + 5,
    &v1[5],
    0i64);
}

// File Line: 917
// RVA: 0x80FC90
bool __fastcall Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(Scaleform::GFx::AS3::VMAbcFile *this, bool to_execute)
{
  char v2; // al
  Scaleform::GFx::AS3::VMAbcFile *v3; // r15
  Scaleform::GFx::AS3::VM *v4; // rbp
  Scaleform::GFx::AS3::Abc::File *v5; // r13
  unsigned __int64 v6; // r12
  __int64 v7; // r14
  Scaleform::GFx::AS3::Abc::HasTraits *v8; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v9; // rax
  Scaleform::GFx::AS3::Traits *v10; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v11; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> *v12; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v14; // rdi
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  bool v19; // al
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> v20; // [rsp+48h] [rbp-50h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+A0h] [rbp+8h]
  bool v22; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> key; // [rsp+B0h] [rbp+18h]
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *v24; // [rsp+B8h] [rbp+20h]

  v22 = to_execute;
  v2 = to_execute;
  v3 = this;
  v4 = this->VMRef;
  v5 = this->File.pObject;
  v6 = v5->Scripts.Info.Data.Size;
  v7 = 0i64;
  if ( v6 )
  {
    while ( 1 )
    {
      v8 = (Scaleform::GFx::AS3::Abc::HasTraits *)&v5->Scripts.Info.Data.Data[v7]->obj_traits;
      v24 = 0i64;
      v9 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)v4->MHeap->vfptr->Alloc(
                                                                      (Scaleform::MemoryHeap *)this,
                                                                      256ui64,
                                                                      0i64);
      v10 = (Scaleform::GFx::AS3::Traits *)&v9->vfptr;
      if ( v9 )
      {
        Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v9, v4);
        v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::`vftable;
        v10[1].FirstOwnSlotNum = (unsigned __int64)v3;
        v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
        v10[1].Parent = (Scaleform::GFx::AS3::Slots *)v8;
        Scaleform::GFx::AS3::Traits::AddSlots(v10, &result, v8, v3, 0x40u);
      }
      else
      {
        v10 = 0i64;
      }
      v11 = 0i64;
      if ( v10 )
        v11 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)v10;
      v24 = v11;
      if ( v4->HandleException )
        break;
      v12 = Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript::MakeInstance(v11, &v20);
      v13 = v12->pV;
      key.pObject = v12->pV;
      if ( v4->HandleException )
      {
        if ( v13 )
        {
          if ( (unsigned __int8)v13 & 1 )
          {
            key.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)v13 - 1);
          }
          else
          {
            v17 = v13->RefCount;
            if ( v17 & 0x3FFFFF )
            {
              v13->RefCount = v17 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
            }
          }
        }
        break;
      }
      Scaleform::GFx::AS3::VM::RegisterGlobalObject(v4, (Scaleform::GFx::AS3::Instances::fl::GlobalObject *)&v13->vfptr);
      Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>>>::Set<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>>(
        (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v3->GlobalObjects.pTable,
        &v3->GlobalObjects,
        &key);
      v14 = key.pObject;
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript::InitUserDefinedClassTraits(key.pObject);
      if ( v14 )
      {
        if ( (unsigned __int8)v14 & 1 )
        {
          key.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)((char *)v14 - 1);
        }
        else
        {
          v15 = v14->RefCount;
          if ( v15 & 0x3FFFFF )
          {
            v14->RefCount = v15 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->vfptr);
          }
        }
      }
      if ( v11 )
      {
        if ( (unsigned __int8)v11 & 1 )
        {
          v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)((char *)v11 - 1);
        }
        else
        {
          v16 = v11->RefCount;
          if ( v16 & 0x3FFFFF )
          {
            v11->RefCount = v16 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
          }
        }
      }
      if ( ++v7 >= v6 )
      {
        v2 = v22;
        goto LABEL_32;
      }
    }
    if ( v11 )
    {
      if ( (unsigned __int8)v11 & 1 )
      {
        v24 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObjectScript *)((char *)v11 - 1);
      }
      else
      {
        v18 = v11->RefCount;
        if ( v18 & 0x3FFFFF )
        {
          v11->RefCount = v18 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
        }
      }
    }
    v19 = 0;
  }
  else
  {
LABEL_32:
    if ( v2 )
    {
      if ( v6 )
        ((void (*)(void))v4->GlobalObjects.Data.Data[v4->GlobalObjects.Data.Size - 1]->vfptr[6].Finalize_GC)();
    }
    v19 = v4->HandleException == 0;
  }
  return v19;
}

// File Line: 964
// RVA: 0x7F9B50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VMAbcFile::Load(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::CheckResult *result, bool to_execute)
{
  bool v3; // si
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rax

  v3 = to_execute;
  v4 = result;
  v5 = this;
  if ( Scaleform::GFx::AS3::VMAbcFile::RegisterUserDefinedClassTraits(this)
    && Scaleform::GFx::AS3::VMAbcFile::RegisterScrips(v5, v3) )
  {
    v4->Result = 1;
    v6 = v4;
  }
  else
  {
    v4->Result = 0;
    v6 = v4;
  }
  return v6;
}

// File Line: 978
// RVA: 0x8288F0
void __fastcall Scaleform::GFx::AS3::VMAbcFile::UnRegister(Scaleform::GFx::AS3::VMAbcFile *this)
{
  Scaleform::GFx::AS3::VMAbcFile *v1; // rsi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v2; // rcx
  signed __int64 v3; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *v5; // rax
  __int64 v6; // rax
  unsigned __int64 v7; // rdx
  _QWORD *v8; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *v10; // rax
  Scaleform::GFx::AS3::VM *v11; // rcx

  v1 = this;
  if ( Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(this->VMRef, this) )
  {
    Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(v1);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::MethodInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::MethodInfo,340>,Scaleform::ArrayDefaultPolicy> *)&v1->MethodInfoArray.Data.Data,
      &v1->MethodInfoArray,
      0i64);
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v1->AbsObjects);
    v2 = v1->GlobalObjects.pTable;
    v3 = 0i64;
    v4 = 0i64;
    if ( v2 )
    {
      v5 = v2 + 1;
      do
      {
        if ( v5->EntryCount != -2i64 )
          break;
        ++v4;
        v5 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > >::TableType *)((char *)v5 + 24);
      }
      while ( v4 <= v2->SizeMask );
      v3 = (signed __int64)&v1->GlobalObjects;
    }
    while ( v3 )
    {
      v6 = *(_QWORD *)v3;
      if ( !*(_QWORD *)v3 || (signed __int64)v4 > *(_QWORD *)(v6 + 8) )
        break;
      Scaleform::GFx::AS3::VM::UnregisterGlobalObject(
        v1->VMRef,
        *(Scaleform::GFx::AS3::Instances::fl::GlobalObject **)(v6 + 24 * v4 + 32));
      v7 = *(_QWORD *)(*(_QWORD *)v3 + 8i64);
      if ( (signed __int64)v4 <= (signed __int64)v7 && ++v4 <= v7 )
      {
        v8 = (_QWORD *)(*(_QWORD *)v3 + 24 * v4 + 16);
        do
        {
          if ( *v8 != -2i64 )
            break;
          ++v4;
          v8 += 3;
        }
        while ( v4 <= v7 );
      }
    }
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Clear((Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript> > > > *)&v1->GlobalObjects.pTable);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->Children.Data.Data,
      &v1->Children,
      0i64);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&v1->FunctionTraitsCache);
    __1__HashSetBase_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12_UNodeAltHashF_12_U__AllocatorLH_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___0BFE__2_V__HashsetCachedNodeEntry_U__HashNode_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform__V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___345_V__FixedSizeHash_UKey___AbcMultinameHash_V__SPtr_VNamespace_fl_Instances_AS3_GFx_Scaleform___AS3_GFx_Scaleform___0BFE__AS3_GFx_Scaleform___5__Scaleform__UNodeHashF_12__2__Scaleform__QEAA_XZ((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::AbcMultinameHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,340>::Key,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::A)&v1->IntNamespaces.Entries.mHash.pTable);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->IntNamespaceSets,
      &v1->IntNamespaceSets,
      0i64);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy> *)&v1->IntStrings.Data.Data,
      &v1->IntStrings,
      0i64);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd>>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&v1->ActivationTraitsCache.mHash.pTable);
    Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::~HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc> > *)&v1->ASStringNodeSet.pTable);
    v9 = v1->AppDomain.pObject;
    v10 = v9->ClassTraitsSet.Entries.mHash.pTable;
    if ( (!v10 || !v10->EntryCount) && !v9->ChildDomains.Data.Size )
    {
      v11 = v1->VMRef;
      if ( !v11->LoadingAbcFile )
        Scaleform::GFx::AS3::VMAppDomain::RemoveChild(v11->SystemDomain.pObject, v9);
    }
  }
}

// File Line: 1019
// RVA: 0x7ED750
Scaleform::ArrayLH_POD<unsigned __int64,338,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetOpCode(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::GFx::AS3::MethodInfo *v3; // rbx
  Scaleform::GFx::AS3::Tracer v5; // [rsp+30h] [rbp-148h]

  v2 = this->VMRef;
  v3 = &this->MethodInfoArray.Data.Data[cf->MBIIndex.Ind];
  if ( !v3->OpCode.Data.Size )
  {
    Scaleform::GFx::AS3::Tracer::Tracer(&v5, v2->MHeap, cf, &this->MethodInfoArray.Data.Data[cf->MBIIndex.Ind]);
    if ( !v2->HandleException )
      Scaleform::GFx::AS3::Tracer::EmitCode(&v5);
    Scaleform::GFx::AS3::Tracer::~Tracer(&v5);
  }
  return &v3->OpCode;
}

// File Line: 1056
// RVA: 0x7E86F0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Abc::ValueDetail *d)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  unsigned __int64 v4; // rdx
  int v5; // edx
  unsigned int v6; // edx
  long double v7; // xmm0_8
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // rax
  int v12; // ecx
  long double v13; // rcx
  long double v14; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rax
  int v16; // eax
  long double v17; // rax
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+18h]

  v3 = result;
  v4 = d->ValueIndex;
  if ( (signed int)v4 <= 0 )
  {
LABEL_26:
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v3->Flags = v.Flags;
    v3->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v3->value = v.value;
    v16 = v.Flags & 0x1F;
    if ( v16 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( v16 == 10 )
      {
        v14 = v.value.VNumber;
LABEL_40:
        ++*(_DWORD *)(*(_QWORD *)&v14 + 24i64);
      }
      else if ( v16 > 10 )
      {
        if ( v16 <= 15 )
        {
          v17 = v.value.VNumber;
        }
        else
        {
          if ( v16 > 17 )
            return v3;
          v17 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v17 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v17 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v17 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    switch ( d->Kind )
    {
      case 0:
        v11 = Scaleform::GFx::AS3::Value::GetUndefined();
        goto LABEL_11;
      case 1:
        v8 = Scaleform::GFx::AS3::VMFile::GetInternedString((Scaleform::GFx::AS3::VMFile *)&this->vfptr, &resulta, v4);
        Scaleform::GFx::AS3::Value::Value(v3, v8);
        v9 = resulta.pNode;
        v10 = resulta.pNode->RefCount == 1;
        --v9->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        return v3;
      case 3:
        v5 = this->File.pObject->Const_Pool.ConstInt.Data.Data[v4];
        v3->Flags = 2;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VS._1.VInt = v5;
        return v3;
      case 4:
        v6 = this->File.pObject->Const_Pool.ConstUInt.Data.Data[v4];
        v3->Flags = 3;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VS._1.VInt = v6;
        return v3;
      case 5:
      case 8:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1A:
        v15 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&this->vfptr, v4);
        v3->Flags = 11;
        v3->Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v3->value.VNumber = v15;
        if ( v15 )
          v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
        return v3;
      case 6:
        v7 = Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(&this->File.pObject->Const_Pool, v4);
        v3->Flags = 4;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VNumber = v7;
        return v3;
      case 0xA:
        v3->Flags = 1;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VS._1.VBool = 0;
        return v3;
      case 0xB:
        v3->Flags = 1;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VS._1.VBool = 1;
        return v3;
      case 0xC:
        v11 = Scaleform::GFx::AS3::Value::GetNull();
LABEL_11:
        v3->Flags = v11->Flags;
        v3->Bonus.pWeakProxy = v11->Bonus.pWeakProxy;
        v3->value.VNumber = v11->value.VNumber;
        v3->value.VS._2.VObj = v11->value.VS._2.VObj;
        v12 = v11->Flags & 0x1F;
        if ( v12 <= 9 )
          return v3;
        if ( (v11->Flags >> 9) & 1 )
        {
          ++v11->Bonus.pWeakProxy->RefCount;
          return v3;
        }
        if ( v12 == 10 )
        {
          v14 = v11->value.VNumber;
          goto LABEL_40;
        }
        if ( v12 <= 10 )
          return v3;
        if ( v12 <= 15 )
        {
          v13 = v11->value.VNumber;
        }
        else
        {
          if ( v12 > 17 )
            return v3;
          v13 = *(double *)&v11->value.VS._2.VObj;
        }
        if ( v13 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
        break;
      default:
        goto LABEL_26;
    }
  }
  return v3;
}

// File Line: 1105
// RVA: 0x7E9E50
Scaleform::GFx::AS3::RefCountBaseGC<328> *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetFunctionInstanceTraits(Scaleform::GFx::AS3::VMAbcFile *this, Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos, unsigned int method_ind)
{
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v3; // rbp
  Scaleform::GFx::AS3::VMAbcFile *v4; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF> > *v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  Scaleform::GFx::AS3::VM *v11; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Function *v12; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rdi
  signed __int64 v15; // rdx
  unsigned __int64 v16; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  unsigned int v18; // eax
  Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeRef key; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::Abc::MbiInd mi; // [rsp+80h] [rbp+18h]
  Scaleform::GFx::AS3::InstanceTraits::Function *v22; // [rsp+88h] [rbp+20h]

  mi.Ind = method_ind;
  v3 = gos;
  v4 = this;
  v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&this->FunctionTraitsCache;
  v6 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::findIndexAlt<unsigned long>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MbiInd,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Abc::MbiInd> >,Scaleform::HashNode<Scaleform::GFx::AS3::Abc::MbiInd,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,Scaleform::Fix)&this->FunctionTraitsCache,
         &mi);
  if ( v6 >= 0 )
  {
    v8 = (signed __int64)&v5->pTable[2 * (v6 + 1)];
    if ( v8 )
    {
      v9 = v8 + 8;
      if ( v9 )
        return *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v9;
    }
  }
  v11 = v4->VMRef;
  v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11->MHeap;
  v12 = (Scaleform::GFx::AS3::InstanceTraits::Function *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))v20->vfptr[3].~RefCountBaseGC<328>)(
                                                           v7,
                                                           264i64,
                                                           0i64);
  v22 = v12;
  if ( v12 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Function::Function(v12, v4, &Scaleform::GFx::AS3::fl::FunctionCI, mi.Ind, v3);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  if ( v11->HandleException )
    return (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11->NoFunctionTraits.pObject;
  v20 = v14;
  key.pFirst = &mi;
  key.pSecond = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *)&v20;
  v15 = 4i64;
  v16 = 5381i64;
  do
    v16 = *((unsigned __int8 *)&mi.Ind + --v15) + 65599 * v16;
  while ( v15 );
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned long,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>,Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeHashF>>::add<Scaleform::HashNode<unsigned long,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<unsigned long>>::NodeRef>(
    v5,
    v5,
    &key,
    v16);
  v17 = v20;
  if ( v20 )
  {
    if ( (unsigned __int8)v20 & 1 )
    {
      v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
    }
    else
    {
      v18 = v20->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v20->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
  return v14;
}

// File Line: 1151
// RVA: 0x7EC600
Scaleform::GFx::AS3::Abc::Multiname *__fastcall Scaleform::GFx::AS3::VMAbcFile::GetMultiname(Scaleform::GFx::AS3::VMAbcFile *this, unsigned __int64 ind)
{
  return &this->File.pObject->Const_Pool.const_multiname.Data.Data[ind];
}

// File Line: 1157
// RVA: 0x7900E0
void __fastcall Scaleform::GFx::AS3::XMLSupport::~XMLSupport(Scaleform::GFx::AS3::XMLSupport *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable;
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&this->vfptr);
}

// File Line: 1172
// RVA: 0x7C9900
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupport::EqualsXML(Scaleform::GFx::AS3::XMLSupport *this, Scaleform::GFx::AS3::CheckResult *result, bool *stop, bool *a4)
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
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::XMLSupport::EqualsXMLList(Scaleform::GFx::AS3::XMLSupport *this, Scaleform::GFx::AS3::CheckResult *result, bool *a3, Scaleform::GFx::AS3::Instances::fl::XMLList *__formal)
{
  *a3 = 0;
  result->Result = 0;
  return result;
}

// File Line: 1238
// RVA: 0x7E5EB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetArrayInd(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASStringNode *sn, unsigned int *ind)
{
  unsigned int v3; // er9
  unsigned int *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  const char *v6; // r10
  char v7; // al
  unsigned int v9; // ecx
  _BYTE *v10; // rdx
  double v11; // xmm0_8
  char *endptr; // [rsp+38h] [rbp+10h]

  v3 = sn->Size;
  v4 = ind;
  v5 = result;
  if ( v3 )
  {
    v6 = sn->pData;
    v7 = *sn->pData;
    if ( v7 == 48 )
    {
      *ind = 0;
      result->Result = v3 == 1;
      return result;
    }
    if ( (unsigned __int8)(v7 - 48) <= 9u )
    {
      v9 = 1;
      if ( v3 <= 1 )
      {
LABEL_9:
        v11 = strtod(v6, &endptr);
        if ( v11 <= 4294967295.0 )
        {
          v5->Result = 1;
          *v4 = (signed int)v11;
          return v5;
        }
      }
      else
      {
        v10 = v6 + 1;
        while ( (unsigned __int8)(*v10 - 48) <= 9u )
        {
          ++v9;
          ++v10;
          if ( v9 >= v3 )
            goto LABEL_9;
        }
      }
    }
  }
  v5->Result = 0;
  return v5;
}

// File Line: 1276
// RVA: 0x7E5E50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetArrayInd(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, unsigned int *ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  unsigned int v4; // eax
  bool v5; // cl
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  bool v7; // cl
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]

  v3 = result;
  v4 = prop_name->Name.Flags & 0x1F;
  if ( v4 == 10 )
  {
    v5 = Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name->Name.value.VS._1.VStr, ind)->Result;
    v6 = v3;
    v3->Result = v5;
  }
  else if ( v4 - 2 > 2 )
  {
    result->Result = 0;
    v6 = result;
  }
  else
  {
    v7 = Scaleform::GFx::AS3::Value::Convert2UInt32(&prop_name->Name, &resulta, ind)->Result;
    v6 = v3;
    v3->Result = v7;
  }
  return v6;
}

// File Line: 1290
// RVA: 0x7F1AD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetVectorInd(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASStringNode *sn, unsigned int *ind)
{
  unsigned int *v3; // rdi
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  double v5; // xmm0_8
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]
  long double v8; // [rsp+48h] [rbp+20h]

  v3 = ind;
  v4 = result;
  if ( Scaleform::GFx::AS3::GetStrNumber(&resulta, sn, &v8)->Result && (v5 = v8, v8 <= 4294967295.0) )
  {
    v4->Result = 1;
    *v3 = (signed int)v5;
    v6 = v4;
  }
  else
  {
    v4->Result = 0;
    v6 = v4;
  }
  return v6;
}

// File Line: 1308
// RVA: 0x7F1A10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetVectorInd(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, unsigned int *ind)
{
  bool v3; // bl
  unsigned int *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rsi
  long double v6; // xmm6_8
  int v7; // eax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+8h]
  long double iptr; // [rsp+58h] [rbp+10h]

  v3 = 0;
  v4 = ind;
  v5 = result;
  switch ( prop_name->Name.Flags & 0x1F )
  {
    case 2u:
      v7 = prop_name->Name.value.VS._1.VInt;
      if ( v7 < 0 )
        break;
      goto LABEL_12;
    case 3u:
      v7 = prop_name->Name.value.VS._1.VInt;
LABEL_12:
      *ind = v7;
      goto LABEL_13;
    case 4u:
      v6 = prop_name->Name.value.VNumber;
      if ( v6 < 0.0 || modf(v6, &iptr) != 0.0 || v6 > 4294967295.0 )
        break;
      *v4 = (signed int)v6;
LABEL_13:
      v3 = 1;
      break;
    case 10u:
      v3 = Scaleform::GFx::AS3::GetVectorInd(&resulta, prop_name->Name.value.VS._1.VStr, ind)->Result;
      break;
  }
  v5->Result = v3;
  return v5;
}

// File Line: 1356
// RVA: 0x7EFEC0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetStrNumber(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASStringNode *sn, long double *a3)
{
  long double *v3; // rdi
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  unsigned int v5; // er8
  const char *v6; // r10
  unsigned int v7; // ecx
  _BYTE *v8; // rdx
  long double v9; // xmm0_8
  Scaleform::GFx::AS3::CheckResult *v10; // rax
  unsigned int v11; // eax
  const char *v12; // rcx
  char *endptr; // [rsp+38h] [rbp+10h]

  v3 = a3;
  v4 = result;
  if ( sn )
  {
    v5 = sn->Size;
    if ( v5 )
    {
      v6 = sn->pData;
      if ( (unsigned __int8)(*sn->pData - 48) <= 9u )
      {
        v7 = 1;
        if ( v5 > 1 )
        {
          v8 = v6 + 1;
          while ( (unsigned __int8)(*v8 - 48) <= 9u )
          {
            ++v7;
            ++v8;
            if ( v7 >= v5 )
              goto LABEL_8;
          }
          if ( *v8 != 46 )
            goto LABEL_15;
          v11 = v7 + 1;
          if ( v7 + 1 < v5 )
          {
            v12 = &v6[v11];
            while ( *v12 == 48 )
            {
              ++v11;
              ++v12;
              if ( v11 >= v5 )
                goto LABEL_8;
            }
LABEL_15:
            v4->Result = 0;
            return v4;
          }
        }
LABEL_8:
        v9 = strtod(v6, &endptr);
        v4->Result = 1;
        v10 = v4;
        *v3 = v9;
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
void __fastcall Scaleform::GFx::AS3::CallFrame::CallFrame(Scaleform::GFx::AS3::CallFrame *this, Scaleform::GFx::AS3::CallFrame *other)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // r8
  signed int v3; // eax
  Scaleform::GFx::AS3::Value::V2U v4; // r8
  long double v5; // r8

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
  v2 = other->DefXMLNamespace.pObject;
  this->DefXMLNamespace.pObject = v2;
  if ( v2 )
    v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  this->PrevFirstStackPos = other->PrevFirstStackPos;
  this->Invoker.Flags = other->Invoker.Flags;
  this->Invoker.Bonus.pWeakProxy = other->Invoker.Bonus.pWeakProxy;
  this->Invoker.value = other->Invoker.value;
  v3 = other->Invoker.Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (other->Invoker.Flags >> 9) & 1 )
    {
      ++other->Invoker.Bonus.pWeakProxy->RefCount;
    }
    else if ( v3 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&other->Invoker.value.VNumber + 24i64);
    }
    else if ( v3 > 10 )
    {
      if ( v3 <= 15 )
      {
        v5 = other->Invoker.value.VNumber;
        if ( v5 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v5 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v5 + 32i64) + 1) & 0x8FBFFFFF;
      }
      else if ( v3 <= 17 )
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
  Scaleform::GFx::AS3::CallFrame *v1; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rbx
  __int64 *v3; // rsi
  __int64 v4; // rcx
  int v5; // eax
  unsigned int v6; // eax
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  bool v8; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // [rsp+48h] [rbp+10h]

  v1 = this;
  if ( this->pRegisterFile && this->pScopeStack && this->ACopy )
  {
    Scaleform::GFx::AS3::ValueStack::ReleaseReserved(&this->pFile->VMRef->OpStack, this->PrevFirstStackPos);
    Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(
      v1->pRegisterFile,
      v1->pFile->File.pObject->MethodBodies.Info.Data.Data[v1->MBIIndex.Ind]->local_reg_count);
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v1->pScopeStack->Data,
      v1->ScopeStackBaseInd);
    v2 = v1->DefXMLNamespace.pObject;
    v11 = v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
    v3 = (__int64 *)&v1->pFile->VMRef->DefXMLNamespace;
    if ( &v11 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)v3 )
    {
      if ( v2 )
        v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
      v4 = *v3;
      if ( *v3 )
      {
        if ( v4 & 1 )
        {
          *v3 = v4 - 1;
        }
        else
        {
          v5 = *(_DWORD *)(v4 + 32);
          if ( v5 & 0x3FFFFF )
          {
            *(_DWORD *)(v4 + 32) = v5 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v4);
          }
        }
      }
      *v3 = (__int64)v2;
    }
    if ( v2 )
    {
      if ( (unsigned __int8)v2 & 1 )
      {
        v11 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v2 - 1);
      }
      else
      {
        v6 = v2->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v2->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
        }
      }
    }
  }
  if ( (v1->Invoker.Flags & 0x1F) > 9 )
  {
    if ( (v1->Invoker.Flags >> 9) & 1 )
    {
      v7 = v1->Invoker.Bonus.pWeakProxy;
      v8 = v7->RefCount-- == 1;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->Invoker.Bonus.pWeakProxy = 0i64;
      v1->Invoker.value.VNumber = 0.0;
      v1->Invoker.value.VS._2.VObj = 0i64;
      v1->Invoker.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->Invoker);
    }
  }
  v9 = v1->DefXMLNamespace.pObject;
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      v1->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v9 - 1);
    }
    else
    {
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
}

// File Line: 1559
// RVA: 0x8203C0
void __fastcall Scaleform::GFx::AS3::CallFrame::SetupRegisters(Scaleform::GFx::AS3::CallFrame *this, Scaleform::GFx::AS3::Abc::MethodInfo *mi, Scaleform::GFx::AS3::Value *_this, unsigned int argc)
{
  unsigned __int64 v4; // r12
  Scaleform::GFx::AS3::CallFrame *v5; // r15
  unsigned int v6; // esi
  unsigned int v7; // er11
  char v8; // r10
  int v9; // edi
  int v10; // er10
  Scaleform::GFx::AS3::WeakProxy *v11; // rcx
  Scaleform::GFx::AS3::Value::V2U v12; // rax
  long double v13; // rcx
  Scaleform::GFx::AS3::Value *v14; // rdx
  signed int v15; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v16; // rax
  long double v17; // rcx
  Scaleform::GFx::AS3::Value *v18; // rcx
  unsigned int v19; // edi
  bool v20; // zf
  unsigned int v21; // ebx
  Scaleform::GFx::AS3::Instances::fl::Array *v22; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // r14
  Scaleform::GFx::AS3::VM *v24; // r13
  unsigned __int64 v25; // rbx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v26; // rdi
  long double v27; // rcx
  Scaleform::GFx::AS3::Value::V2U v28; // r8
  int v29; // edx
  Scaleform::GFx::AS3::Value *v30; // rax
  bool v31; // bl
  int v32; // edi
  Scaleform::GFx::AS3::VM::Error *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::AS3::VM::Error *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::VM::Error *v37; // rax
  Scaleform::GFx::AS3::VM::Error *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v40; // rsi
  unsigned int v41; // ebx
  int v42; // ecx
  Scaleform::GFx::ASStringNode *v43; // rcx
  long double v44; // rcx
  int v45; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *v46; // r14
  unsigned int v47; // ebx
  unsigned int v48; // ebx
  Scaleform::GFx::AS3::Value *v49; // rdx
  int v50; // eax
  Scaleform::GFx::AS3::Value::V2U v51; // rcx
  unsigned int v52; // ebx
  int v53; // ecx
  Scaleform::GFx::ASStringNode *v54; // rcx
  long double v55; // rcx
  int v56; // eax
  Scaleform::GFx::ASString *v57; // rax
  Scaleform::GFx::ASStringNode *v58; // rcx
  Scaleform::GFx::ASStringNode *v59; // rcx
  int v60; // eax
  Scaleform::GFx::ASStringNode *v61; // rcx
  long double v62; // rcx
  int v63; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+0h] [rbp-51h]
  Scaleform::GFx::AS3::Value result; // [rsp+20h] [rbp-31h]
  unsigned int v66; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS3::VM::Error v67; // [rsp+48h] [rbp-9h]
  unsigned __int64 v68; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::ASStringNode *v69; // [rsp+60h] [rbp+Fh]
  __int64 v70; // [rsp+68h] [rbp+17h]
  char v71[35]; // [rsp+91h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v72; // [rsp+B8h] [rbp+67h]
  Scaleform::GFx::AS3::Value::V2U *v73; // [rsp+C0h] [rbp+6Fh]
  __int64 v74; // [rsp+D0h] [rbp+7Fh]

  v70 = -2i64;
  v4 = argc;
  v5 = this;
  v6 = 0;
  v66 = 0;
  v7 = _this->Flags;
  v8 = _this->Flags;
  v9 = 1;
  *(_DWORD *)&v71[31] = 1;
  v10 = v8 & 0x1F;
  if ( v10 && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || *(_QWORD *)&_this->value.VNumber) )
  {
    result.Flags = v7;
    v11 = _this->Bonus.pWeakProxy;
    result.Bonus.pWeakProxy = _this->Bonus.pWeakProxy;
    result.value.VNumber = _this->value.VNumber;
    v12.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2;
    result.value.VS._2.VObj = _this->value.VS._2.VObj;
    if ( v10 > 9 )
    {
      if ( (v7 >> 9) & 1 )
      {
        ++v11->RefCount;
      }
      else if ( v10 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&_this->value.VNumber + 24i64);
      }
      else if ( v10 > 10 )
      {
        if ( v10 <= 15 )
        {
          v13 = _this->value.VNumber;
          if ( v13 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v10 <= 17 && v12.VObj )
        {
          v12.VObj->RefCount = (v12.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    v14 = &result;
    v15 = 2;
  }
  else
  {
    v16 = this->pSavedScope;
    if ( v16->Data.Size )
    {
      v17 = v16->Data.Data->value.VNumber;
    }
    else
    {
      v18 = this->pRegisterFile->pRF;
      if ( (v18->Flags & 0x1F) - 12 > 3 )
        v17 = 0.0;
      else
        v17 = v18->value.VNumber;
    }
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VNumber = v17;
    if ( v17 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v17 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v17 + 32i64) + 1) & 0x8FBFFFFF;
    v14 = &other;
    v15 = 1;
  }
  v66 = v15;
  Scaleform::GFx::AS3::Value::Assign(v5->pRegisterFile->pRF, v14);
  if ( v15 & 2 )
  {
    v15 &= 0xFFFFFFFD;
    v66 = v15;
    v19 = result.Flags;
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags >> 9) & 1 )
      {
        v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.Bonus.pWeakProxy = 0i64;
        result.value = 0ui64;
        result.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
    v9 = 1;
  }
  if ( v15 & 1 )
  {
    v66 = v15 & 0xFFFFFFFE;
    v21 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v21 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  v22 = v72.pV;
  v23 = v72.pV->pPrev;
  v68 = (char *)v72.pV->pPrev - (char *)v72.pV->DynAttrs.mHash.pTable;
  v24 = v5->pFile->VMRef;
  if ( !v23 )
  {
LABEL_100:
    if ( (_QWORD)v22->vfptr & 4 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v72,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v24->TraitsArray.pObject->ITraits.pObject);
      other.Bonus.pWeakProxy = 0i64;
      other.Flags = 12;
      v40 = v72.pV;
      *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&other.value.VNumber = v72;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v67.Message.pNode;
      Scaleform::GFx::AS3::Value::Assign(&v5->pRegisterFile->pRF[v9], &other);
      v41 = other.Flags;
      v42 = other.Flags & 0x1F;
      if ( v42 > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags = v41 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v42 )
          {
            case 10:
              v43 = other.value.VS._1.VStr;
              v20 = *(_DWORD *)(*(_QWORD *)&other.value.VNumber + 24i64) == 1;
              --v43->RefCount;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v43);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              if ( !other.value.VS._1.VBool )
              {
                v44 = other.value.VNumber;
                goto LABEL_115;
              }
              --*(_QWORD *)&other.value.VNumber;
              break;
            case 16:
            case 17:
              if ( (_QWORD)other.value.VS._2.VObj & 1 )
              {
                --other.value.VS._2.VObj;
              }
              else
              {
                v44 = *(double *)&other.value.VS._2.VObj;
LABEL_115:
                if ( v44 != 0.0 )
                {
                  v45 = *(_DWORD *)(*(_QWORD *)&v44 + 32i64);
                  if ( v45 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v44 + 32i64) = v45 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v44);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      if ( v4 > (unsigned __int64)v23 )
        Scaleform::GFx::AS3::Impl::SparseArray::Append(
          &v40->SA,
          v4 - (_DWORD)v23,
          (Scaleform::GFx::AS3::Value *)(v74 + 32i64 * (_QWORD)v23));
    }
    else if ( (_QWORD)v22->vfptr & 1 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v72,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v24->TraitsArray.pObject->ITraits.pObject);
      result.Bonus.pWeakProxy = 0i64;
      result.Flags = 12;
      v46 = v72.pV;
      *(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&result.value.VNumber = v72;
      result.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v67.Message.pNode;
      Scaleform::GFx::AS3::Value::Assign(&v5->pRegisterFile->pRF[v9], &result);
      v47 = result.Flags;
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags >> 9) & 1 )
        {
          v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.Bonus.pWeakProxy = 0i64;
          result.value = 0ui64;
          result.Flags = v47 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      v48 = 0;
      if ( (_DWORD)v4 )
      {
        do
        {
          if ( v48 >= v9 - 1 )
            v49 = (Scaleform::GFx::AS3::Value *)(v74 + 32i64 * v48);
          else
            v49 = &v5->pRegisterFile->pRF[v48 + 1];
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v46->SA, v49);
          ++v48;
        }
        while ( v48 < (unsigned int)v4 );
      }
      result.Flags = 0;
      result.Bonus.pWeakProxy = 0i64;
      if ( (v5->Invoker.Flags & 0x1F) == 7 )
      {
        v50 = v5->Invoker.value.VS._1.VInt;
        v51.VObj = v73[2].VObj;
        other.Flags = 17;
        other.Bonus.pWeakProxy = 0i64;
        other.value.VS._2 = v51;
        other.value.VS._1.VInt = v50;
        if ( v51.VObj )
          v51.VObj->RefCount = (v51.VObj->RefCount + 1) & 0x8FBFFFFF;
        other.Flags = 17;
        Scaleform::GFx::AS3::Value::Assign(&result, &other);
        v52 = other.Flags;
        v53 = other.Flags & 0x1F;
        if ( v53 > 9 )
        {
          if ( (other.Flags >> 9) & 1 )
          {
            v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v20 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.Bonus.pWeakProxy = 0i64;
            other.value = 0ui64;
            other.Flags = v52 & 0xFFFFFDE0;
          }
          else
          {
            switch ( v53 )
            {
              case 10:
                v54 = other.value.VS._1.VStr;
                v20 = *(_DWORD *)(*(_QWORD *)&other.value.VNumber + 24i64) == 1;
                --v54->RefCount;
                if ( v20 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v54);
                break;
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
                if ( !other.value.VS._1.VBool )
                {
                  v55 = other.value.VNumber;
                  goto LABEL_150;
                }
                --*(_QWORD *)&other.value.VNumber;
                break;
              case 16:
              case 17:
                if ( (_QWORD)other.value.VS._2.VObj & 1 )
                {
                  --other.value.VS._2.VObj;
                }
                else
                {
                  v55 = *(double *)&other.value.VS._2.VObj;
LABEL_150:
                  if ( v55 != 0.0 )
                  {
                    v56 = *(_DWORD *)(*(_QWORD *)&v55 + 32i64);
                    if ( v56 & 0x3FFFFF )
                    {
                      *(_DWORD *)(*(_QWORD *)&v55 + 32i64) = v56 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v55);
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
        Scaleform::GFx::AS3::Value::Assign(&result, &v5->Invoker);
      }
      v57 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v24->StringManagerRef->Builtins,
              (Scaleform::GFx::ASString *)&v72,
              "callee");
      LODWORD(v68) = 0;
      v69 = v57->pNode;
      ++v69->RefCount;
      *(_QWORD *)&v67.ID = &v68;
      v67.Message.pNode = (Scaleform::GFx::ASStringNode *)&result;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v46->DynAttrs.mHash.pTable,
        &v46->DynAttrs,
        (Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *)&v67);
      v58 = v69;
      v20 = v69->RefCount == 1;
      --v58->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v58);
      v59 = (Scaleform::GFx::ASStringNode *)v72.pV;
      v20 = LODWORD(v72.pV->pPrev) == 1;
      --v59->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v59);
      v60 = result.Flags & 0x1F;
      if ( v60 > 9 )
      {
        if ( (result.Flags >> 9) & 1 )
        {
          v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.Bonus.pWeakProxy = 0i64;
          result.value = 0ui64;
          result.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v60 )
          {
            case 10:
              v61 = result.value.VS._1.VStr;
              v20 = *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 24i64) == 1;
              --v61->RefCount;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v61);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v62 = result.value.VNumber;
              if ( !result.value.VS._1.VBool )
                goto LABEL_169;
              --*(_QWORD *)&result.value.VNumber;
              break;
            case 16:
            case 17:
              v62 = *(double *)&result.value.VS._2.VObj;
              if ( (_QWORD)result.value.VS._2.VObj & 1 )
              {
                --result.value.VS._2.VObj;
              }
              else
              {
LABEL_169:
                if ( v62 != 0.0 )
                {
                  v63 = *(_DWORD *)(*(_QWORD *)&v62 + 32i64);
                  if ( v63 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v62 + 32i64) = v63 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v62);
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
            v24,
            (Scaleform::GFx::AS3::VMFile *)&v5->pFile->vfptr,
            &v5->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[*((unsigned int *)&v22->pNext->vfptr + v25)]);
    if ( !v26 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v67, eClassNotFoundError, v24);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v24, v38, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v39 = v67.Message.pNode;
      v20 = v67.Message.pNode->RefCount == 1;
      --v39->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v39);
      return;
    }
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    other.Flags = v.Flags;
    other.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v28.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
    v27 = v.value.VNumber;
    other.value = v.value;
    v29 = v.Flags & 0x1F;
    if ( v29 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( v29 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else if ( v29 > 10 )
      {
        if ( v29 <= 15 )
        {
          if ( *(_QWORD *)&v.value.VNumber )
          {
            ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
            *(_DWORD *)(*(_QWORD *)&v27 + 32i64) &= 0x8FBFFFFF;
          }
        }
        else if ( v29 <= 17 && v.value.VS._2.VObj )
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
             v74 + 32 * v25,
             &other) )
      {
        goto LABEL_72;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v67, eCheckTypeFailedError, v24);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v24, v33, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_81:
      v34 = v67.Message.pNode;
      v20 = v67.Message.pNode->RefCount == 1;
      --v34->RefCount;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
LABEL_88:
          other.Flags &= 0xFFFFFDE0;
          return;
        }
LABEL_97:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        return;
      }
      return;
    }
    if ( (_QWORD)v72.pV->vfptr & 8 && v25 >= v68 )
      break;
    if ( v26 != v24->TraitsClassClass.pObject )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v67, eWrongArgumentCountError, v24);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v24, v37, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      goto LABEL_81;
    }
LABEL_72:
    v32 = *(_DWORD *)&v71[31];
    Scaleform::GFx::AS3::Value::Assign(&v5->pRegisterFile->pRF[*(signed int *)&v71[31]], &other);
    v9 = v32 + 1;
    *(_DWORD *)&v71[31] = v9;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    v25 = ++v6;
    v22 = v72.pV;
    if ( v6 >= (unsigned __int64)v23 )
      goto LABEL_100;
  }
  v30 = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
          v5->pFile,
          &result,
          (Scaleform::GFx::AS3::Abc::ValueDetail *)&v72.pV->pTraits.pObject->vfptr + v25 - v68);
  v31 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v26->vfptr[3].Finalize_GC)(
          v26,
          v30,
          &other) == 0;
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v20 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  if ( !v31 )
    goto LABEL_72;
  Scaleform::GFx::AS3::VM::Error::Error(&v67, eCheckTypeFailedError, v24);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v24, v35, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v36 = v67.Message.pNode;
  v20 = v67.Message.pNode->RefCount == 1;
  --v36->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v20 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      goto LABEL_88;
    }
    goto LABEL_97;
  }
}

// File Line: 1702
// RVA: 0x7B4CB0
void __fastcall Scaleform::GFx::AS3::CallFrame::ClearOpStack(Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::GFx::AS3::VM *v1; // rdx
  Scaleform::GFx::AS3::ValueStack *v2; // rax

  v1 = this->pFile->VMRef;
  v2 = &v1->OpStack;
  if ( this->DiscardResult || v1->HandleException )
    Scaleform::GFx::AS3::ValueStack::PopReserved(v2, this->PrevInitialStackPos, 0);
  else
    Scaleform::GFx::AS3::ValueStack::PopReserved(v2, this->PrevInitialStackPos, 1);
}

// File Line: 1764
// RVA: 0x7EA070
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::CallFrame::GetGlobalObject(Scaleform::GFx::AS3::CallFrame *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v1; // rax
  Scaleform::GFx::AS3::Value *v2; // rax

  v1 = this->pSavedScope;
  if ( v1->Data.Size )
  {
    v2 = v1->Data.Data;
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v2->value.VS._1.VStr;
  }
  v2 = this->pRegisterFile->pRF;
  if ( (v2->Flags & 0x1F) - 12 <= 3 )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v2->value.VS._1.VStr;
  return 0i64;
}

// File Line: 1792
// RVA: 0x784B30
void __fastcall Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::VMAppDomain *parentDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v4; // rax
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329,Scaleform::ArrayDefaultPolicy> *v6; // rax

  v3 = this;
  v4 = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v4;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable;
  this->ParentDomain = 0i64;
  v5 = vm->MHeap;
  v3->ClassTraitsSet.Entries.mHash.pTable = 0i64;
  v3->ClassTraitsSet.Entries.mHash.pHeap = v5;
  v6 = &v3->ChildDomains;
  v6->Data.Data = 0i64;
  v6->Data.Size = 0i64;
  v6->Data.Policy.Capacity = 0i64;
  if ( parentDomain )
    Scaleform::GFx::AS3::VMAppDomain::AddChild(parentDomain, v3);
}

// File Line: 1798
// RVA: 0x78F960
void __fastcall Scaleform::GFx::AS3::VMAppDomain::~VMAppDomain(Scaleform::GFx::AS3::VMAppDomain *this)
{
  Scaleform::GFx::AS3::VMAppDomain *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ChildDomains);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v1->ClassTraitsSet);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&v1->ClassTraitsSet);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 1802
// RVA: 0x7AB6C0
void __fastcall Scaleform::GFx::AS3::VMAppDomain::AddChild(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::VMAppDomain *childDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v2; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v3; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v4; // rdx
  unsigned int v5; // eax

  v2 = childDomain;
  v3 = this;
  if ( childDomain )
    childDomain->RefCount = (childDomain->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy> *)&this->ChildDomains.Data.Data,
    &this->ChildDomains,
    this->ChildDomains.Data.Size + 1);
  v4 = &v3->ChildDomains.Data.Data[v3->ChildDomains.Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v2 )
  {
    if ( !((unsigned __int8)v2 & 1) )
    {
      v5 = v2->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v2->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v2->ParentDomain = v3;
}

// File Line: 1808
// RVA: 0x7AE040
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *__fastcall Scaleform::GFx::AS3::VMAppDomain::AddNewChild(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v3; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v4; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v5; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v6; // rsi
  Scaleform::GFx::AS3::VMAppDomain *v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *v8; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v9; // rax

  v3 = vm;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    v7 = (Scaleform::GFx::AS3::VMAppDomain *)vm->MHeap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 88ui64, 0i64);
    if ( v7 )
    {
      Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(v7, v3, v5);
      v6 = v8;
    }
    v4->pObject = v6;
    v9 = v4;
  }
  else
  {
    result->pObject = this;
    if ( this )
      this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    v9 = result;
  }
  return v9;
}

// File Line: 1821
// RVA: 0x811630
char __fastcall Scaleform::GFx::AS3::VMAppDomain::RemoveChild(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::VMAppDomain *childDomain)
{
  __int64 v2; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbp
  Scaleform::GFx::AS3::VMAppDomain *v4; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v5; // rax
  Scaleform::GFx::AS3::VMAppDomain *v6; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  unsigned int v9; // eax

  v2 = 0i64;
  v3 = childDomain;
  v4 = this;
  if ( !this->ChildDomains.Data.Size )
    return 0;
  while ( 1 )
  {
    v5 = v4->ChildDomains.Data.Data;
    v6 = v5[v2].pObject;
    if ( v6 == v3 )
      break;
    if ( Scaleform::GFx::AS3::VMAppDomain::RemoveChild(v6, v3) )
      return 1;
    if ( ++v2 >= v4->ChildDomains.Data.Size )
      return 0;
  }
  if ( v4->ChildDomains.Data.Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy> *)&v4->ChildDomains.Data.Data,
      &v4->ChildDomains,
      0i64);
    return 1;
  }
  v8 = v5[v2].pObject;
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      v5[v2].pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  memmove(
    &v4->ChildDomains.Data.Data[v2],
    &v4->ChildDomains.Data.Data[v2 + 1],
    8 * (v4->ChildDomains.Data.Size - v2) - 8);
  --v4->ChildDomains.Data.Size;
  return 1;
}

// File Line: 1838
// RVA: 0x7E6E90
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v4; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rdi
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  v3 = this;
  v4 = this->ParentDomain;
  v5 = ns;
  v6 = name;
  if ( !v4 || (result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v4, name, ns)) == 0i64 )
    result = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
               &v3->ClassTraitsSet,
               v6,
               v5);
  return result;
}

// File Line: 1857
// RVA: 0x7E6EE0
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::VMAppDomain *v2; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v3; // rcx
  Scaleform::GFx::AS3::Multiname *v4; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  v2 = this;
  v3 = this->ParentDomain;
  v4 = mn;
  if ( !v3 || (result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v3, mn)) == 0i64 )
    result = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
               &v2->ClassTraitsSet,
               v4);
  return result;
}

// File Line: 1871
// RVA: 0x7AB900
void __fastcall Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::AS3::ClassTraits::Traits *val)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *vala; // [rsp+48h] [rbp+20h]

  vala = val;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &this->ClassTraitsSet,
    name,
    ns,
    &vala);
}

// File Line: 1909
// RVA: 0x7D6AE0
void __fastcall Scaleform::GFx::AS3::VMAppDomain::ForEachChild_GC(Scaleform::GFx::AS3::VMAppDomain *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rbx
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rsi
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // rbp
  Scaleform::GFx::AS3::VMAppDomain *v6; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v7; // rcx

  v3 = 0i64;
  v4 = op;
  v5 = prcc;
  v6 = this;
  if ( this->ChildDomains.Data.Size )
  {
    do
    {
      v7 = v6->ChildDomains.Data.Data[v3].pObject;
      v7->vfptr->ForEachChild_GC((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr, v5, v4);
      ++v3;
    }
    while ( v3 < v6->ChildDomains.Data.Size );
  }
}

// File Line: 1976
// RVA: 0x783E90
void __fastcall Scaleform::GFx::AS3::VM::VM(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::FlashUI *_ui, Scaleform::GFx::AS3::StringManager *sm, Scaleform::GFx::AS3::ASRefCountCollector *gc)
{
  Scaleform::GFx::AS3::VM *v4; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  __int64 v6; // rax
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // rcx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v8; // rax
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v10; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rsi
  Scaleform::MemoryHeap *v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rax
  Scaleform::MemoryHeap *v16; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v17; // rdx
  Scaleform::GFx::AS3::ASRefCountCollector *v18; // rcx
  _QWORD *v19; // rax
  Scaleform::GFx::AS3::VMAppDomain *v20; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v22; // rbx
  char v23; // r14
  Scaleform::GFx::AS3::VMAppDomain *v24; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v25; // rdx
  unsigned int v26; // eax
  unsigned int v27; // eax
  __int64 v28; // rax
  __int64 v29; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v30; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v31; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v32; // rax
  __int64 v33; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v34; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v35; // rax
  __int64 v36; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v37; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v38; // rax
  __int64 v39; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v40; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v41; // rax
  __int64 v42; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v43; // rax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v44; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v45; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v46; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v47; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v48; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v49; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v50; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v51; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v52; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v53; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v54; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v55; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v56; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v57; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v58; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v59; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v60; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v61; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v62; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v63; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v64; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v65; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v66; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v67; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v68; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v69; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v70; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v71; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v72; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v73; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v74; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v75; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v76; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v77; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v78; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v79; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v80; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v81; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v82; // rbx
  __int64 v83; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Anonimous *v84; // rax
  __int64 v85; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v86; // rax
  Scaleform::GFx::AS3::InstanceTraits::Void *v87; // rax
  __int64 v88; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v89; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v90; // rax
  __int64 v91; // rcx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v92; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v93; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v94; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v95; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v96; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v97; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v98; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v99; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v100; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v101; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v102; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Function *v103; // r14
  Scaleform::GFx::AS3::Class *v104; // rcx
  unsigned int v105; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v106; // r14
  unsigned __int64 v107; // rbx
  unsigned __int64 v108; // r8
  void (__fastcall **v109)(Scaleform::GFx::AS3::RefCountBaseGC<328> *); // rcx
  Scaleform::GFx::AS3::Classes::ClassClass **v110; // rbx
  Scaleform::GFx::AS3::Value::V2U v111; // [rsp+30h] [rbp-89h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+38h] [rbp-81h]
  __int64 v113; // [rsp+C0h] [rbp+7h]
  __int64 v114; // [rsp+C8h] [rbp+Fh]
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> result; // [rsp+128h] [rbp+6Fh]
  __int64 v116; // [rsp+130h] [rbp+77h]
  _QWORD *v117; // [rsp+138h] [rbp+7Fh]

  v114 = -2i64;
  v4 = this;
  this->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::VM::`vftable;
  *(_WORD *)&this->Initialized = 0;
  this->LoadingAbcFile = 0;
  this->StringManagerRef = sm;
  this->GC.GC = gc;
  this->UI = _ui;
  this->InInitializer = 0;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this);
  v4->MHeap = (Scaleform::MemoryHeap *const )v5;
  result.pV = v5;
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, signed __int64, _QWORD))v5->vfptr[3].~RefCountBaseGC<328>)(
         v5,
         48i64,
         0i64);
  v116 = v6;
  if ( v6 )
  {
    v7 = v4->GC.GC;
    *(_QWORD *)v6 = &Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    *(_DWORD *)(v6 + 32) = 1;
    *(_QWORD *)(v6 + 8) = v7;
    *(_QWORD *)v6 = &Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    *(_QWORD *)v6 = &Scaleform::GFx::AS3::XMLSupport::`vftable;
    *(_BYTE *)(v6 + 40) = 0;
  }
  else
  {
    v6 = 0i64;
  }
  v4->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)v6;
  Scaleform::GFx::AS3::ValueStack::ValueStack(&v4->OpStack);
  v4->RegisterFile.ReservedNum = 0;
  v4->RegisterFile.pRF = 0i64;
  *(_DWORD *)&v4->RegisterFile.MaxReservedPageSize = 0;
  v4->RegisterFile.pCurrentPage = 0i64;
  v4->RegisterFile.pReserved = 0i64;
  v8 = Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(&v4->RegisterFile, 0);
  v4->RegisterFile.pCurrentPage = v8;
  v8->pNext = 0i64;
  v4->RegisterFile.pCurrentPage->pPrev = 0i64;
  v4->RegisterFile.pRF = v4->RegisterFile.pCurrentPage->Values;
  v9 = v4->MHeap;
  v10 = &v4->ScopeStack;
  v10->Data.Data = 0i64;
  v10->Data.Size = 0i64;
  v10->Data.Policy.Capacity = 0i64;
  v4->ScopeStack.Data.pHeap = v9;
  v4->HandleException = 0;
  v4->ExceptionObj.Flags = 0;
  v4->ExceptionObj.Bonus.pWeakProxy = 0i64;
  v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->GlobalObjects;
  result.pV = v11;
  v116 = (__int64)&v4->GlobalObjects;
  v11->vfptr = 0i64;
  v11->pRCCRaw = 0i64;
  v11->pNext = 0i64;
  v12 = v4->MHeap;
  *(_WORD *)&other.DiscardResult = 0;
  other.ScopeStackBaseInd = 0i64;
  other.CP = 0i64;
  other.pRegisterFile = 0i64;
  other.pHeap = v12;
  other.pFile = 0i64;
  other.MBIIndex.Ind = 0;
  other.pSavedScope = 0i64;
  other.OriginationTraits = 0i64;
  other.pScopeStack = 0i64;
  other.PrevInitialStackPos = 0i64;
  other.DefXMLNamespace.pObject = 0i64;
  other.PrevFirstStackPos = 0i64;
  other.Invoker.Flags = 0;
  other.Invoker.Bonus.pWeakProxy = 0i64;
  v13 = (signed __int64)&v4->CallStack;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v13;
  *(_QWORD *)(v13 + 8) = 0i64;
  *(_QWORD *)(v13 + 16) = 0i64;
  *(_QWORD *)(v13 + 24) = 0i64;
  *(_QWORD *)(v13 + 32) = 0i64;
  Scaleform::GFx::AS3::CallFrame::CallFrame(&v4->CallStack.DefaultValue, &other);
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v15 = ((__int64 (__fastcall *)(__int64, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(v14, 88i64);
  v17 = (Scaleform::GFx::AS3::VMAppDomain *)v15;
  v116 = v15;
  if ( v15 )
  {
    v18 = v4->GC.GC;
    *(_QWORD *)v15 = &Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    *(_DWORD *)(v15 + 32) = 1;
    *(_QWORD *)(v15 + 8) = v18;
    *(_QWORD *)v15 = &Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    *(_QWORD *)v15 = &Scaleform::GFx::AS3::VMAppDomain::`vftable;
    *(_QWORD *)(v15 + 40) = 0i64;
    v16 = v4->MHeap;
    v113 = v15 + 48;
    *(_QWORD *)(v15 + 48) = 0i64;
    *(_QWORD *)(v15 + 56) = v16;
    v19 = (_QWORD *)(v15 + 64);
    v117 = v19;
    *v19 = 0i64;
    v19[1] = 0i64;
    v19[2] = 0i64;
  }
  else
  {
    v17 = 0i64;
  }
  v4->SystemDomain.pObject = v17;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
    v20 = (Scaleform::GFx::AS3::VMAppDomain *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                v16,
                                                88i64);
    v116 = (__int64)v20;
    if ( v20 )
    {
      Scaleform::GFx::AS3::VMAppDomain::VMAppDomain(v20, v4, v4->SystemDomain.pObject);
      v22 = v21;
    }
    else
    {
      v22 = 0i64;
    }
    result.pV = v22;
    v23 = 1;
    v24 = (Scaleform::GFx::AS3::VMAppDomain *)v22;
  }
  else
  {
    v24 = v4->SystemDomain.pObject;
    result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v24;
    if ( v24 )
      v24->RefCount = (v24->RefCount + 1) & 0x8FBFFFFF;
    v23 = 2;
    v22 = result.pV;
  }
  v25 = result.pV;
  v4->CurrentDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)result.pV;
  if ( v25 )
    v25->RefCount = (v25->RefCount + 1) & 0x8FBFFFFF;
  if ( v23 & 2 )
  {
    v23 &= 0xFDu;
    if ( v24 )
    {
      if ( (unsigned __int8)v24 & 1 )
      {
        v24 = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v24 - 1);
        result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v24;
      }
      else
      {
        v26 = v24->RefCount;
        if ( v26 & 0x3FFFFF )
        {
          v24->RefCount = v26 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24->vfptr);
        }
      }
    }
  }
  if ( v23 & 1 && v22 )
  {
    if ( (unsigned __int8)v22 & 1 )
    {
      result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)v22 - 1);
    }
    else
    {
      v27 = v22->RefCount;
      if ( v27 & 0x3FFFFF )
      {
        v22->RefCount = v27 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
      }
    }
  }
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v28 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMAppDomain *, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
          v24,
          104i64);
  v30 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v28;
  v116 = v28;
  if ( v28 )
  {
    v31 = v4->GC.GC;
    *(_QWORD *)v28 = &Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
    *(_DWORD *)(v28 + 32) = 1;
    *(_QWORD *)(v28 + 8) = v31;
    *(_QWORD *)v28 = &Scaleform::GFx::AS3::GASRefCountBase::`vftable;
    *(_QWORD *)v28 = &Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
    *(_QWORD *)(v28 + 40) &= 0xFFFFFFFFFFFFFFE0ui64;
    *(_QWORD *)(v28 + 48) = v4;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
      (Scaleform::GFx::ASString *)(v28 + 56),
      &customWorldMapCaption);
    v30->pFactory.pObject = 0i64;
    v30->Prefix.Flags = 0;
    v30->Prefix.Bonus.pWeakProxy = 0i64;
  }
  else
  {
    v30 = 0i64;
  }
  v4->PublicNamespace.pObject = v30;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v32 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v29,
                                                           104i64);
  v116 = (__int64)v32;
  if ( v32 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v32, v4, 0, Scaleform::GFx::AS3::NS_AS3);
  else
    v34 = 0i64;
  v4->AS3Namespace.pObject = v34;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v35 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v33,
                                                           104i64);
  v116 = (__int64)v35;
  if ( v35 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v35, v4, 0, Scaleform::GFx::AS3::NS_Vector);
  else
    v37 = 0i64;
  v4->VectorNamespace.pObject = v37;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v38 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v36,
                                                           104i64);
  v116 = (__int64)v38;
  if ( v38 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v38, v4, 0, Scaleform::GFx::AS3::NS_flash_proxy);
  else
    v40 = 0i64;
  v4->ProxyNamespace.pObject = v40;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v41 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((__int64 (__fastcall *)(__int64, signed __int64))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                           v39,
                                                           104i64);
  v116 = (__int64)v41;
  if ( v41 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v41, v4, 0, Scaleform::GFx::AS3::NS_XML);
  else
    v43 = 0i64;
  v4->XMLNamespace.pObject = v43;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v44 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                          v42,
                                                          208i64,
                                                          0i64);
  v116 = (__int64)v44;
  if ( v44 )
  {
    Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(v44, v4);
    v46 = v45;
  }
  else
  {
    v46 = 0i64;
  }
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v46, v4->SystemDomain.pObject);
  v4->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v46;
  v47 = Scaleform::GFx::AS3::ClassTraits::fl::Object::MakeClassTraits(&result, v4);
  v48 = v47->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v47->pV, v4->SystemDomain.pObject);
  v4->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v48;
  v49 = Scaleform::GFx::AS3::ClassTraits::fl::Namespace::MakeClassTraits(&result, v4);
  v50 = v49->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v49->pV, v4->SystemDomain.pObject);
  v4->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)v50;
  v51 = Scaleform::GFx::AS3::ClassTraits::Function::MakeClassTraits(&result, v4);
  v52 = v51->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v51->pV, v4->SystemDomain.pObject);
  v4->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)v52;
  v53 = Scaleform::GFx::AS3::ClassTraits::fl::Boolean::MakeClassTraits(&result, v4);
  v54 = v53->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v53->pV, v4->SystemDomain.pObject);
  v4->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)v54;
  v55 = Scaleform::GFx::AS3::ClassTraits::fl::Number::MakeClassTraits(&result, v4);
  v56 = v55->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v55->pV, v4->SystemDomain.pObject);
  v4->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)v56;
  v57 = Scaleform::GFx::AS3::ClassTraits::fl::int_::MakeClassTraits(&result, v4);
  v58 = v57->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v57->pV, v4->SystemDomain.pObject);
  v4->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)v58;
  v59 = Scaleform::GFx::AS3::ClassTraits::fl::uint::MakeClassTraits(&result, v4);
  v60 = v59->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v59->pV, v4->SystemDomain.pObject);
  v4->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)v60;
  v61 = Scaleform::GFx::AS3::ClassTraits::fl::String::MakeClassTraits(&result, v4);
  v62 = v61->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v61->pV, v4->SystemDomain.pObject);
  v4->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)v62;
  v63 = Scaleform::GFx::AS3::ClassTraits::fl::Array::MakeClassTraits(&result, v4);
  v64 = v63->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v63->pV, v4->SystemDomain.pObject);
  v4->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)v64;
  v65 = Scaleform::GFx::AS3::ClassTraits::fl::QName::MakeClassTraits(&result, v4);
  v66 = v65->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v65->pV, v4->SystemDomain.pObject);
  v4->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)v66;
  v67 = Scaleform::GFx::AS3::ClassTraits::fl::Catch::MakeClassTraits(&result, v4);
  v68 = v67->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v67->pV, v4->SystemDomain.pObject);
  v4->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)v68;
  v69 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::MakeClassTraits(&result, v4);
  v70 = v69->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v69->pV, v4->SystemDomain.pObject);
  v4->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)v70;
  v71 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int::MakeClassTraits(&result, v4);
  v72 = v71->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v71->pV, v4->SystemDomain.pObject);
  v4->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v72;
  v73 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint::MakeClassTraits(&result, v4);
  v74 = v73->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v73->pV, v4->SystemDomain.pObject);
  v4->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)v74;
  v75 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::MakeClassTraits(&result, v4);
  v76 = v75->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v75->pV, v4->SystemDomain.pObject);
  v4->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)v76;
  v77 = Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::MakeClassTraits(&result, v4);
  v78 = v77->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v77->pV, v4->SystemDomain.pObject);
  v4->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)v78;
  v79 = Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::MakeClassTraits(&result, v4);
  v80 = v79->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v79->pV, v4->SystemDomain.pObject);
  v4->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)v80;
  v81 = Scaleform::GFx::AS3::ClassTraits::fl::Domain::MakeClassTraits(&result, v4);
  v82 = v81->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v81->pV, v4->SystemDomain.pObject);
  v4->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Domain *)v82;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v84 = (Scaleform::GFx::AS3::InstanceTraits::Anonimous *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                            v83,
                                                            240i64,
                                                            0i64);
  v116 = (__int64)v84;
  if ( v84 )
    Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(v84, v4);
  else
    v86 = 0i64;
  v4->TraitsNull.pObject = v86;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v87 = (Scaleform::GFx::AS3::InstanceTraits::Void *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                       v85,
                                                       240i64,
                                                       0i64);
  v116 = (__int64)v87;
  if ( v87 )
    Scaleform::GFx::AS3::InstanceTraits::Void::Void(v87, v4);
  else
    v89 = 0i64;
  v4->TraitsVoid.pObject = v89;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v90 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                          v88,
                                                          264i64,
                                                          0i64);
  v92 = v90;
  v116 = (__int64)v90;
  if ( v90 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v90, v4, &Scaleform::GFx::AS3::fl::FunctionCICpp);
    v92->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable;
    LODWORD(v92[1].vfptr) = 0;
    v92[1].pRCCRaw = 0i64;
    v92[1].pNext = 0i64;
    v92->TraitsType = 10;
    Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots((Scaleform::GFx::AS3::InstanceTraits::Function *)v92);
  }
  else
  {
    v92 = 0i64;
  }
  v4->NoFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Function *)v92;
  v4->DefXMLNamespace.pObject = 0i64;
  result.pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap;
  v93 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))result.pV->vfptr[3].~RefCountBaseGC<328>)(
                                                                   v91,
                                                                   240i64,
                                                                   0i64);
  v116 = (__int64)v93;
  if ( v93 )
    Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v93, v4);
  else
    v94 = 0i64;
  v4->TraitaGlobalObject.pObject = v94;
  v95 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->MHeap->vfptr->Alloc(v4->MHeap, 216ui64, 0i64);
  result.pV = v95;
  v116 = (__int64)v95;
  if ( v95 )
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GlobalObjectCPP(
      (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)v95,
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v4->TraitaGlobalObject.pObject->vfptr);
  else
    v96 = 0i64;
  v4->GlobalObject.pObject = v96;
  v4->GlobalObjectValue.Flags = 0;
  v4->GlobalObjectValue.Bonus.pWeakProxy = 0i64;
  v97 = v4->GlobalObject.pObject;
  v4->GlobalObjectValue.Flags = v4->GlobalObjectValue.Flags & 0xFFFFFFEC | 0xC;
  *(_QWORD *)&v4->GlobalObjectValue.value.VNumber = v97;
  v4->GlobalObjectValue.value.VS._2 = v111;
  if ( v97 )
    v97->RefCount = (v97->RefCount + 1) & 0x8FBFFFFF;
  v98 = Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray::MakeClassTraits(&result, v4);
  v99 = v98->pV;
  Scaleform::GFx::AS3::VM::RegisterClassTraits(v4, v98->pV, v4->SystemDomain.pObject);
  v4->TraitsByteArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *)v99;
  v4->AliasClass.mHash.pTable = 0i64;
  v4->ClassAlias.mHash.pTable = 0i64;
  v100 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->VMAbcFilesWeak;
  result.pV = v100;
  v116 = (__int64)&v4->VMAbcFilesWeak;
  v100->vfptr = 0i64;
  v100->pRCCRaw = 0i64;
  v100->pNext = 0i64;
  Scaleform::GFx::AS3::VM::EnableXMLSupport(v4);
  v101 = v4->TraitsFunction.pObject->ITraits.pObject;
  if ( !v101->pConstructor.pObject )
    v101->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v101->vfptr);
  v102 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v101->pConstructor.pObject->vfptr;
  if ( v102 )
    v102->RefCount = (v102->RefCount + 1) & 0x8FBFFFFF;
  v103 = v4->NoFunctionTraits.pObject;
  v104 = v103->pConstructor.pObject;
  if ( v102 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v104 )
  {
    if ( v104 )
    {
      if ( (unsigned __int8)v104 & 1 )
      {
        v103->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v104 - 1);
      }
      else
      {
        v105 = v104->RefCount;
        if ( v105 & 0x3FFFFF )
        {
          v104->RefCount = v105 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v104->vfptr);
        }
      }
    }
    v103->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)v102;
  }
  v4->Initialized = 1;
  v106 = v4->GlobalObject.pObject;
  v107 = v4->GlobalObjects.Data.Size + 1;
  if ( v107 >= v4->GlobalObjects.Data.Size )
  {
    if ( v107 <= v4->GlobalObjects.Data.Policy.Capacity )
      goto LABEL_81;
    v108 = v107 + (v107 >> 2);
  }
  else
  {
    if ( v107 >= v4->GlobalObjects.Data.Policy.Capacity >> 1 )
      goto LABEL_81;
    v108 = v4->GlobalObjects.Data.Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v4->GlobalObjects,
    &v4->GlobalObjects,
    v108);
LABEL_81:
  v4->GlobalObjects.Data.Size = v107;
  v109 = &v11->vfptr[-1].Finalize_GC + v107;
  if ( v109 )
    *v109 = (void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *))v106;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->TraitsClassClass.pObject->pParent,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->TraitsObject.pObject);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots((Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsClassClass.pObject->vfptr);
  v110 = (Scaleform::GFx::AS3::Classes::ClassClass **)v4->TraitsClassClass.pObject->ITraits.pObject;
  if ( !v110[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::ClassClass **))(*v110)[1]._pRCC)(v110);
  Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(v110[17]);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots((Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsObject.pObject->vfptr);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots((Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsNamespace.pObject->vfptr);
}

// File Line: 2061
// RVA: 0x78ED90
void __fastcall Scaleform::GFx::AS3::VM::~VM(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
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

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::VMVtbl *)&Scaleform::GFx::AS3::VM::`vftable;
  this->InDestructor = 1;
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(this);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->VMAbcFilesWeak.Data.Data);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v1->ClassAlias.mHash.pTable);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v1->AliasClass);
  v2 = v1->TraitsByteArray.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->TraitsByteArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_utils::ByteArray *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  if ( (v1->GlobalObjectValue.Flags & 0x1F) > 9 )
  {
    if ( (v1->GlobalObjectValue.Flags >> 9) & 1 )
    {
      v4 = v1->GlobalObjectValue.Bonus.pWeakProxy;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->GlobalObjectValue.Bonus.pWeakProxy = 0i64;
      v1->GlobalObjectValue.value.VNumber = 0.0;
      v1->GlobalObjectValue.value.VS._2.VObj = 0i64;
      v1->GlobalObjectValue.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->GlobalObjectValue);
    }
  }
  v6 = v1->GlobalObject.pObject;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v1->GlobalObject.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
  }
  v8 = v1->TraitaGlobalObject.pObject;
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      v1->TraitaGlobalObject.pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  v10 = v1->DefXMLNamespace.pObject;
  if ( v10 )
  {
    if ( (unsigned __int8)v10 & 1 )
    {
      v1->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( v11 & 0x3FFFFF )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
      }
    }
  }
  v12 = v1->NoFunctionTraits.pObject;
  if ( v12 )
  {
    if ( (unsigned __int8)v12 & 1 )
    {
      v1->NoFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Function *)((char *)v12 - 1);
    }
    else
    {
      v13 = v12->RefCount;
      if ( v13 & 0x3FFFFF )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
  v14 = v1->TraitsVoid.pObject;
  if ( v14 )
  {
    if ( (unsigned __int8)v14 & 1 )
    {
      v1->TraitsVoid.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v14 - 1);
    }
    else
    {
      v15 = v14->RefCount;
      if ( v15 & 0x3FFFFF )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->vfptr);
      }
    }
  }
  v16 = v1->TraitsNull.pObject;
  if ( v16 )
  {
    if ( (unsigned __int8)v16 & 1 )
    {
      v1->TraitsNull.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v16 - 1);
    }
    else
    {
      v17 = v16->RefCount;
      if ( v17 & 0x3FFFFF )
      {
        v16->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
      }
    }
  }
  v18 = v1->TraitsDomain.pObject;
  if ( v18 )
  {
    if ( (unsigned __int8)v18 & 1 )
    {
      v1->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Domain *)((char *)v18 - 1);
    }
    else
    {
      v19 = v18->RefCount;
      if ( v19 & 0x3FFFFF )
      {
        v18->RefCount = v19 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v18->vfptr);
      }
    }
  }
  v20 = v1->TraitsApplicationDomain.pObject;
  if ( v20 )
  {
    if ( (unsigned __int8)v20 & 1 )
    {
      v1->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)((char *)v20 - 1);
    }
    else
    {
      v21 = v20->RefCount;
      if ( v21 & 0x3FFFFF )
      {
        v20->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v20->vfptr);
      }
    }
  }
  v22 = v1->TraitsVector_String.pObject;
  if ( v22 )
  {
    if ( (unsigned __int8)v22 & 1 )
    {
      v1->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)((char *)v22 - 1);
    }
    else
    {
      v23 = v22->RefCount;
      if ( v23 & 0x3FFFFF )
      {
        v22->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
      }
    }
  }
  v24 = v1->TraitsVector_Number.pObject;
  if ( v24 )
  {
    if ( (unsigned __int8)v24 & 1 )
    {
      v1->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)((char *)v24 - 1);
    }
    else
    {
      v25 = v24->RefCount;
      if ( v25 & 0x3FFFFF )
      {
        v24->RefCount = v25 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24->vfptr);
      }
    }
  }
  v26 = v1->TraitsVector_uint.pObject;
  if ( v26 )
  {
    if ( (unsigned __int8)v26 & 1 )
    {
      v1->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)((char *)v26 - 1);
    }
    else
    {
      v27 = v26->RefCount;
      if ( v27 & 0x3FFFFF )
      {
        v26->RefCount = v27 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26->vfptr);
      }
    }
  }
  v28 = v1->TraitsVector_int.pObject;
  if ( v28 )
  {
    if ( (unsigned __int8)v28 & 1 )
    {
      v1->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)((char *)v28 - 1);
    }
    else
    {
      v29 = v28->RefCount;
      if ( v29 & 0x3FFFFF )
      {
        v28->RefCount = v29 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v28->vfptr);
      }
    }
  }
  v30 = v1->TraitsVector.pObject;
  if ( v30 )
  {
    if ( (unsigned __int8)v30 & 1 )
    {
      v1->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)((char *)v30 - 1);
    }
    else
    {
      v31 = v30->RefCount;
      if ( v31 & 0x3FFFFF )
      {
        v30->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v30->vfptr);
      }
    }
  }
  v32 = v1->TraitsCatch.pObject;
  if ( v32 )
  {
    if ( (unsigned __int8)v32 & 1 )
    {
      v1->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)((char *)v32 - 1);
    }
    else
    {
      v33 = v32->RefCount;
      if ( v33 & 0x3FFFFF )
      {
        v32->RefCount = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v32->vfptr);
      }
    }
  }
  v34 = v1->TraitsQName.pObject;
  if ( v34 )
  {
    if ( (unsigned __int8)v34 & 1 )
    {
      v1->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)((char *)v34 - 1);
    }
    else
    {
      v35 = v34->RefCount;
      if ( v35 & 0x3FFFFF )
      {
        v34->RefCount = v35 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v34->vfptr);
      }
    }
  }
  v36 = v1->TraitsArray.pObject;
  if ( v36 )
  {
    if ( (unsigned __int8)v36 & 1 )
    {
      v1->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)((char *)v36 - 1);
    }
    else
    {
      v37 = v36->RefCount;
      if ( v37 & 0x3FFFFF )
      {
        v36->RefCount = v37 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v36->vfptr);
      }
    }
  }
  v38 = v1->TraitsString.pObject;
  if ( v38 )
  {
    if ( (unsigned __int8)v38 & 1 )
    {
      v1->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)((char *)v38 - 1);
    }
    else
    {
      v39 = v38->RefCount;
      if ( v39 & 0x3FFFFF )
      {
        v38->RefCount = v39 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v38->vfptr);
      }
    }
  }
  v40 = v1->TraitsUint.pObject;
  if ( v40 )
  {
    if ( (unsigned __int8)v40 & 1 )
    {
      v1->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)((char *)v40 - 1);
    }
    else
    {
      v41 = v40->RefCount;
      if ( v41 & 0x3FFFFF )
      {
        v40->RefCount = v41 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v40->vfptr);
      }
    }
  }
  v42 = v1->TraitsInt.pObject;
  if ( v42 )
  {
    if ( (unsigned __int8)v42 & 1 )
    {
      v1->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)((char *)v42 - 1);
    }
    else
    {
      v43 = v42->RefCount;
      if ( v43 & 0x3FFFFF )
      {
        v42->RefCount = v43 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v42->vfptr);
      }
    }
  }
  v44 = v1->TraitsNumber.pObject;
  if ( v44 )
  {
    if ( (unsigned __int8)v44 & 1 )
    {
      v1->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)((char *)v44 - 1);
    }
    else
    {
      v45 = v44->RefCount;
      if ( v45 & 0x3FFFFF )
      {
        v44->RefCount = v45 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v44->vfptr);
      }
    }
  }
  v46 = v1->TraitsBoolean.pObject;
  if ( v46 )
  {
    if ( (unsigned __int8)v46 & 1 )
    {
      v1->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)((char *)v46 - 1);
    }
    else
    {
      v47 = v46->RefCount;
      if ( v47 & 0x3FFFFF )
      {
        v46->RefCount = v47 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v46->vfptr);
      }
    }
  }
  v48 = v1->TraitsFunction.pObject;
  if ( v48 )
  {
    if ( (unsigned __int8)v48 & 1 )
    {
      v1->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)((char *)v48 - 1);
    }
    else
    {
      v49 = v48->RefCount;
      if ( v49 & 0x3FFFFF )
      {
        v48->RefCount = v49 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v48->vfptr);
      }
    }
  }
  v50 = v1->TraitsNamespace.pObject;
  if ( v50 )
  {
    if ( (unsigned __int8)v50 & 1 )
    {
      v1->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)((char *)v50 - 1);
    }
    else
    {
      v51 = v50->RefCount;
      if ( v51 & 0x3FFFFF )
      {
        v50->RefCount = v51 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v50->vfptr);
      }
    }
  }
  v52 = v1->TraitsObject.pObject;
  if ( v52 )
  {
    if ( (unsigned __int8)v52 & 1 )
    {
      v1->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)((char *)v52 - 1);
    }
    else
    {
      v53 = v52->RefCount;
      if ( v53 & 0x3FFFFF )
      {
        v52->RefCount = v53 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v52->vfptr);
      }
    }
  }
  v54 = v1->TraitsClassClass.pObject;
  if ( v54 )
  {
    if ( (unsigned __int8)v54 & 1 )
    {
      v1->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)((char *)v54 - 1);
    }
    else
    {
      v55 = v54->RefCount;
      if ( v55 & 0x3FFFFF )
      {
        v54->RefCount = v55 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v54->vfptr);
      }
    }
  }
  v56 = v1->XMLNamespace.pObject;
  if ( v56 )
  {
    if ( (unsigned __int8)v56 & 1 )
    {
      v1->XMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v56 - 1);
    }
    else
    {
      v57 = v56->RefCount;
      if ( v57 & 0x3FFFFF )
      {
        v56->RefCount = v57 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v56->vfptr);
      }
    }
  }
  v58 = v1->ProxyNamespace.pObject;
  if ( v58 )
  {
    if ( (unsigned __int8)v58 & 1 )
    {
      v1->ProxyNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v58 - 1);
    }
    else
    {
      v59 = v58->RefCount;
      if ( v59 & 0x3FFFFF )
      {
        v58->RefCount = v59 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v58->vfptr);
      }
    }
  }
  v60 = v1->VectorNamespace.pObject;
  if ( v60 )
  {
    if ( (unsigned __int8)v60 & 1 )
    {
      v1->VectorNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v60 - 1);
    }
    else
    {
      v61 = v60->RefCount;
      if ( v61 & 0x3FFFFF )
      {
        v60->RefCount = v61 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v60->vfptr);
      }
    }
  }
  v62 = v1->AS3Namespace.pObject;
  if ( v62 )
  {
    if ( (unsigned __int8)v62 & 1 )
    {
      v1->AS3Namespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v62 - 1);
    }
    else
    {
      v63 = v62->RefCount;
      if ( v63 & 0x3FFFFF )
      {
        v62->RefCount = v63 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v62->vfptr);
      }
    }
  }
  v64 = v1->PublicNamespace.pObject;
  if ( v64 )
  {
    if ( (unsigned __int8)v64 & 1 )
    {
      v1->PublicNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v64 - 1);
    }
    else
    {
      v65 = v64->RefCount;
      if ( v65 & 0x3FFFFF )
      {
        v64->RefCount = v65 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v64->vfptr);
      }
    }
  }
  v66 = v1->CurrentDomain.pObject;
  if ( v66 )
  {
    if ( (unsigned __int8)v66 & 1 )
    {
      v1->CurrentDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v66 - 1);
    }
    else
    {
      v67 = v66->RefCount;
      if ( v67 & 0x3FFFFF )
      {
        v66->RefCount = v67 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v66->vfptr);
      }
    }
  }
  v68 = v1->SystemDomain.pObject;
  if ( v68 )
  {
    if ( (unsigned __int8)v68 & 1 )
    {
      v1->SystemDomain.pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v68 - 1);
    }
    else
    {
      v69 = v68->RefCount;
      if ( v69 & 0x3FFFFF )
      {
        v68->RefCount = v69 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v68->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&v1->CallStack.DefaultValue);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v1->CallStack.gap0);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->GlobalObjects.Data.Data);
  if ( (v1->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (v1->ExceptionObj.Flags >> 9) & 1 )
    {
      v70 = v1->ExceptionObj.Bonus.pWeakProxy;
      v5 = v70->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->ExceptionObj.Bonus.pWeakProxy = 0i64;
      v1->ExceptionObj.value.VNumber = 0.0;
      v1->ExceptionObj.value.VS._2.VObj = 0i64;
      v1->ExceptionObj.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->ExceptionObj);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    v1->ScopeStack.Data.Data,
    v1->ScopeStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->ScopeStack.Data.Data);
  Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(&v1->RegisterFile);
  Scaleform::GFx::AS3::ValueStack::~ValueStack(&v1->OpStack);
  v71 = v1->XMLSupport_.pObject;
  if ( v71 )
  {
    if ( (unsigned __int8)v71 & 1 )
    {
      v1->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)v71 - 1);
    }
    else
    {
      v72 = v71->RefCount;
      if ( v72 & 0x3FFFFF )
      {
        v71->RefCount = v72 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v71->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(v1->GC.GC, 0i64, 1u);
}

// File Line: 2071
// RVA: 0x7E9940
Scaleform::GFx::AS3::VMAppDomain *__fastcall Scaleform::GFx::AS3::VM::GetFrameAppDomain(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VMAppDomain *result; // rax

  if ( this->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    result = this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    result = this->CurrentDomain.pObject;
  return result;
}

// File Line: 2087
// RVA: 0x829150
void __fastcall Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(Scaleform::GFx::AS3::VM *this)
{
  unsigned __int64 v1; // rsi
  bool v2; // bp
  Scaleform::GFx::AS3::VM *v3; // rbx
  unsigned __int64 v4; // rdi

  v1 = this->VMAbcFilesWeak.Data.Size;
  v2 = this->InDestructor;
  v3 = this;
  this->InDestructor = 1;
  v4 = 0i64;
  if ( v1 )
  {
    do
      Scaleform::GFx::AS3::VMAbcFile::UnRegister(v3->VMAbcFilesWeak.Data.Data[v4++]);
    while ( v4 < v1 );
  }
  if ( v3->VMAbcFilesWeak.Data.Size > 0 && v3->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v3->VMAbcFilesWeak.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3->VMAbcFilesWeak.Data.Data = 0i64;
    }
    v3->VMAbcFilesWeak.Data.Policy.Capacity = 0i64;
  }
  v3->VMAbcFilesWeak.Data.Size = 0i64;
  v3->InDestructor = v2;
}

// File Line: 2099
// RVA: 0x7D4240
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__fastcall Scaleform::GFx::AS3::VM::FindVMAbcFileWeak(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result, const char *name, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  const char *v4; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v5; // rbx
  unsigned __int64 v6; // r10
  unsigned __int64 v7; // rdi
  Scaleform::GFx::AS3::VMAbcFile **v8; // r14
  Scaleform::GFx::AS3::VMAbcFile **v9; // r11
  const char *v10; // rax
  signed __int64 v11; // r8
  int v12; // ecx
  int v13; // edx
  Scaleform::GFx::AS3::VMAbcFile *v14; // rcx

  v4 = name;
  v5 = result;
  v6 = 0i64;
  v7 = this->VMAbcFilesWeak.Data.Size;
  if ( v7 )
  {
    v8 = this->VMAbcFilesWeak.Data.Data;
    v9 = this->VMAbcFilesWeak.Data.Data;
    while ( 1 )
    {
      v10 = (const char *)(((*v9)->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      v11 = v4 - v10;
      do
      {
        v12 = (unsigned __int8)v10[v11];
        v13 = *(unsigned __int8 *)v10 - v12;
        if ( *(unsigned __int8 *)v10 != v12 )
          break;
        ++v10;
      }
      while ( v12 );
      if ( !v13 && (*v9)->AppDomain.pObject == appDomain )
        break;
      ++v6;
      ++v9;
      if ( v6 >= v7 )
        goto LABEL_13;
    }
    v14 = v8[v6];
    v5->pObject = v14;
    if ( v14 )
      v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
LABEL_13:
    v5->pObject = 0i64;
  }
  return v5;
}

// File Line: 2113
// RVA: 0x7AFC40
void __fastcall Scaleform::GFx::AS3::VM::AddVMAbcFileWeak(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMAbcFile *f)
{
  Scaleform::GFx::AS3::VMAbcFile *v2; // rsi
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::VMAbcFile *,329,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::VMAbcFile **v7; // rax

  v2 = f;
  if ( !this->InDestructor )
  {
    v3 = &this->VMAbcFilesWeak;
    v4 = this->VMAbcFilesWeak.Data.Size;
    v5 = v4 + 1;
    if ( v4 + 1 >= v4 )
    {
      if ( v5 > this->VMAbcFilesWeak.Data.Policy.Capacity )
      {
        v6 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < this->VMAbcFilesWeak.Data.Policy.Capacity >> 1 )
    {
      v6 = v4 + 1;
LABEL_7:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain>,329>,Scaleform::ArrayDefaultPolicy> *)&this->VMAbcFilesWeak,
        &this->VMAbcFilesWeak,
        v6);
      goto LABEL_8;
    }
LABEL_8:
    v7 = v3->Data.Data;
    v3->Data.Size = v5;
    v7[v5 - 1] = v2;
  }
}

// File Line: 2121
// RVA: 0x812390
char __fastcall Scaleform::GFx::AS3::VM::RemoveVMAbcFileWeak(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMAbcFile *f)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS3::VMAbcFile **v5; // r9
  Scaleform::GFx::AS3::VMAbcFile **v6; // rcx
  char result; // al

  v2 = this;
  if ( this->InDestructor )
    return 0;
  v3 = this->VMAbcFilesWeak.Data.Size;
  v4 = 0i64;
  if ( !v3 )
    return 0;
  v5 = this->VMAbcFilesWeak.Data.Data;
  v6 = this->VMAbcFilesWeak.Data.Data;
  while ( *v6 != f )
  {
    ++v4;
    ++v6;
    if ( v4 >= v3 )
      return 0;
  }
  if ( v3 == 1 )
  {
    if ( v2->VMAbcFilesWeak.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v5 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
        v2->VMAbcFilesWeak.Data.Data = 0i64;
      }
      v2->VMAbcFilesWeak.Data.Policy.Capacity = 0i64;
    }
    v2->VMAbcFilesWeak.Data.Size = 0i64;
    result = 1;
  }
  else
  {
    memmove(&v5[v4], &v5[v4 + 1], 8 * (v3 - v4) - 8);
    --v2->VMAbcFilesWeak.Data.Size;
    result = 1;
  }
  return result;
}

// File Line: 2137
// RVA: 0x7E5D20
unsigned __int64 __fastcall Scaleform::GFx::AS3::VM::GetAllLoadedAbcFiles(Scaleform::GFx::AS3::VM *this, Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *destArray)
{
  Scaleform::Array<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  Scaleform::GFx::AS3::VM *v3; // rbp
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r14
  Scaleform::GFx::AS3::VMAbcFile *v6; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v7; // rdx
  unsigned int v8; // ecx

  v2 = destArray;
  v3 = this;
  v4 = 0i64;
  if ( !this->InDestructor )
  {
    v5 = this->VMAbcFilesWeak.Data.Size;
    if ( v5 )
    {
      do
      {
        v6 = v3->VMAbcFilesWeak.Data.Data[v4];
        if ( v6 )
          v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Data.Data,
          v2,
          v2->Data.Size + 1);
        v7 = &v2->Data.Data[v2->Data.Size - 1];
        if ( v7 )
        {
          v7->pObject = v6;
          if ( v6 )
            v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
        }
        if ( v6 )
        {
          if ( !((unsigned __int8)v6 & 1) )
          {
            v8 = v6->RefCount;
            if ( v8 & 0x3FFFFF )
            {
              v6->RefCount = v8 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
            }
          }
        }
        ++v4;
      }
      while ( v4 < v5 );
    }
  }
  return v4;
}

// File Line: 2150
// RVA: 0x80FAF0
void __fastcall Scaleform::GFx::AS3::VM::RegisterClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::ClassTraits::Traits *tr, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ASStringNode *v10; // [rsp+50h] [rbp+18h]

  v3 = appDomain;
  v4 = tr;
  v5 = tr->ITraits.pObject;
  v6 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **))v5->vfptr[1].~RefCountBaseGC<328>)(
                                     v5,
                                     &v10);
  val = v4;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v3->ClassTraitsSet,
    v6,
    v5->Ns.pObject,
    &val);
  v7 = v10;
  v8 = v10->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 2157
// RVA: 0x7F9130
bool __fastcall Scaleform::GFx::AS3::IsScaleformGFx(Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *v1; // rcx

  if ( !(_S13_9 & 1) )
  {
    _S13_9 |= 1u;
    scaleform_gfx.pStr = "scaleform.gfx";
    scaleform_gfx.Size = 13i64;
  }
  v1 = ns->Uri.pNode;
  return v1->Size >= scaleform_gfx.Size && !strncmp(v1->pData, scaleform_gfx.pStr, scaleform_gfx.Size);
}

// File Line: 2179
// RVA: 0x7FA4D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *__fastcall Scaleform::GFx::AS3::VM::MakeArray(Scaleform::GFx::AS3::VM *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v2; // rbx

  v2 = result;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->TraitsArray.pObject->ITraits.pObject);
  return v2;
}

// File Line: 2185
// RVA: 0x7FA500
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *__fastcall Scaleform::GFx::AS3::VM::MakeByteArray(Scaleform::GFx::AS3::VM *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *v2; // rbx

  v2 = result;
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
    result,
    (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)this->TraitsByteArray.pObject->ITraits.pObject);
  return v2;
}

// File Line: 2191
// RVA: 0x7B1110
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::AsString(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  v3 = value;
  v4 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
    result);
  Scaleform::GFx::AS3::Value::Convert2String(v3, &resulta, v4);
  return v4;
}

// File Line: 2206
// RVA: 0x7EECA0
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VM *v3; // rsi
  Scaleform::GFx::AS3::VMAppDomain *v4; // rdi
  Scaleform::GFx::AS3::Multiname *v5; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax
  Scaleform::GFx::AS3::VMAppDomain *v7; // rcx

  v3 = this;
  v4 = appDomain;
  v5 = mn;
  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(mn) )
    return (Scaleform::GFx::AS3::ClassTraits::Traits **)v3->TraitsClassClass.pObject;
  v7 = v4->ParentDomain;
  if ( v7 && (result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v7, v5)) != 0i64
    || (result = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                   &v4->ClassTraitsSet,
                   v5)) != 0i64 )
  {
    result = (Scaleform::GFx::AS3::ClassTraits::Traits **)*result;
  }
  return result;
}

// File Line: 2231
// RVA: 0x7EEC30
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v4; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbx
  Scaleform::GFx::ASString *v7; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits **result; // rax

  v4 = appDomain->ParentDomain;
  v5 = appDomain;
  v6 = ns;
  v7 = name;
  if ( v4 && (result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v4, name, ns)) != 0i64
    || (result = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                   &v5->ClassTraitsSet,
                   v7,
                   v6)) != 0i64 )
  {
    result = (Scaleform::GFx::AS3::ClassTraits::Traits **)*result;
  }
  return result;
}

// File Line: 2237
// RVA: 0x815790
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VM *v4; // rbp
  Scaleform::GFx::AS3::VMAppDomain *v5; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  Scaleform::GFx::ASString *v8; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits **v9; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v12; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [rsp+48h] [rbp+20h]

  v4 = this;
  v5 = appDomain->ParentDomain;
  v6 = appDomain;
  v7 = ns;
  v8 = name;
  if ( (!v5 || (v9 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v5, name, ns)) == 0i64)
    && (v9 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
               &v6->ClassTraitsSet,
               v8,
               v7)) == 0i64
    || (result = *v9) == 0i64 )
  {
    result = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                           v4->GlobalObject.pObject,
                                                           v8,
                                                           v7);
    v11 = result;
    if ( result )
    {
      v12 = &v4->SystemDomain.pObject->ClassTraitsSet;
      val = result;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(v12, v8, v7, &val);
      result = v11;
    }
  }
  return result;
}

// File Line: 2253
// RVA: 0x815840
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::Multiname *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits **v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v11; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h]
  __int64 v17; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v18; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // [rsp+38h] [rbp-20h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+78h] [rbp+20h]

  v17 = -2i64;
  v3 = mn;
  v4 = this;
  v5 = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(this, mn, appDomain);
  if ( v5 )
    return v5;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(&v3->Name, &v21, &result)->Result )
  {
    v9 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
           v4->GlobalObject.pObject,
           &result,
           (Scaleform::GFx::AS3::Instances::fl::Namespace *)v3->Obj.pObject);
    v5 = (Scaleform::GFx::AS3::ClassTraits::Traits **)v9;
    if ( v9 )
    {
      v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->Obj.pObject->vfptr;
      v11 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v4->SystemDomain.pObject;
      *(_QWORD *)&v21.Result = v9;
      v18 = result.pNode;
      ++v18->RefCount;
      v19 = v10;
      if ( v10 )
        v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v18;
      key.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v21;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        v11 + 6,
        v11[7].pTable,
        &key,
        v18->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v19[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v19[1].vfptr << 60 >> 60));
      v12 = v19;
      if ( v19 )
      {
        if ( (unsigned __int8)v19 & 1 )
        {
          v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v19 - 1);
        }
        else
        {
          v13 = v19->RefCount;
          if ( v13 & 0x3FFFFF )
          {
            v19->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
          }
        }
      }
      v14 = v18;
      v7 = v18->RefCount == 1;
      --v14->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v15 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v15->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    return v5;
  }
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 0i64;
}

// File Line: 2276
// RVA: 0x8153E0
Scaleform::GFx::AS3::ClassTraits::ClassClass *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // rsi
  Scaleform::GFx::AS3::VMFile *v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rsi
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+18h]

  v3 = mn;
  v4 = file;
  v5 = this;
  if ( !*(_QWORD *)&mn->NameIndex && !mn->Ind )
    return this->TraitsClassClass.pObject;
  Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, mn->NameIndex);
  if ( result.pNode == v5->StringManagerRef->Builtins[3].pNode )
  {
    v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsObject.pObject->vfptr;
  }
  else
  {
    v8 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v4, v3->Ind);
    v7 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, &result, v8, v4->AppDomain.pObject);
    if ( v7 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v5->TraitsVector.pObject )
    {
      if ( v3->NextIndex > 0 )
      {
        v10 = (Scaleform::GFx::AS3::Abc::Multiname *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, _QWORD))v4->vfptr[1].ForEachChild_GC)(
                                                       v4,
                                                       v3->NextIndex);
        v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, v4, v10);
      }
      else
      {
        v9 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsObject.pObject->vfptr;
      }
      if ( v9 )
      {
        switch ( v9->TraitsType )
        {
          case 2:
            v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsVector_int.pObject->vfptr;
            break;
          case 3:
            v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsVector_uint.pObject->vfptr;
            break;
          case 4:
            v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsVector_Number.pObject->vfptr;
            break;
          case 5:
            v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsVector_String.pObject->vfptr;
            break;
          default:
            if ( v9->ITraits.pObject )
            {
              v11 = (Scaleform::GFx::AS3::Classes::fl_vec::Vector *)Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)&v7->ITraits.pObject->vfptr);
              v7 = Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(v11, v9);
            }
            break;
        }
      }
    }
  }
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v7;
}

// File Line: 2349
// RVA: 0x815540
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::Resolve2ClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::AS3::TypeInfo *v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rsi
  Scaleform::GFx::AS3::StringManager *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v7; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v9; // rax
  void *v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v12; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v21; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // [rsp+40h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+28h]
  Scaleform::GFx::ASString uri; // [rsp+98h] [rbp+30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v26; // [rsp+A0h] [rbp+38h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // [rsp+A8h] [rbp+40h]

  v2 = ti;
  v3 = this;
  v4 = this->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
    &result,
    ti->Name);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
    &uri,
    v2->PkgName);
  if ( uri.pNode->Size )
  {
    v6 = v3->TraitsNamespace.pObject->ITraits.pObject;
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v6[1].RefCount,
      &v26,
      0,
      &uri,
      &v);
    v5 = v26.pV;
  }
  else
  {
    v5 = v3->PublicNamespace.pObject;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  }
  v27 = v5;
  v7 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v3->SystemDomain.pObject;
  v8 = (Scaleform::GFx::AS3::VMAppDomain *)v7[2].Entries.mHash.pHeap;
  if ( (!v8 || (v9 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v8, &result, v5)) == 0i64)
    && (v9 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
               v7 + 3,
               &result,
               v5)) == 0i64
    || (v10 = *v9) == 0i64 )
  {
    v11 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                             v3->GlobalObject.pObject,
                                                             &result,
                                                             v5);
    v10 = v11;
    if ( v11 )
    {
      v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v3->SystemDomain.pObject;
      v26.pV = v11;
      v21 = result.pNode;
      ++v21->RefCount;
      v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr;
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v21;
      key.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v26;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        v12 + 6,
        v12[7].pTable,
        &key,
        v21->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v22[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v22[1].vfptr << 60 >> 60));
      v13 = v22;
      if ( v22 )
      {
        if ( (unsigned __int8)v22 & 1 )
        {
          v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
        }
        else
        {
          v14 = v22->RefCount;
          if ( v14 & 0x3FFFFF )
          {
            v22->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
      v15 = v21;
      v16 = v21->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
  }
  if ( v5 )
  {
    if ( (unsigned __int8)v5 & 1 )
    {
      v27 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v5 - 1);
    }
    else
    {
      v17 = v5->RefCount;
      if ( v17 & 0x3FFFFF )
      {
        v5->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
      }
    }
  }
  v18 = uri.pNode;
  v16 = uri.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return (Scaleform::GFx::AS3::ClassTraits::Traits *)v10;
}

// File Line: 2359
// RVA: 0x829210
void __fastcall Scaleform::GFx::AS3::VM::UnregisterGlobalObject(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Instances::fl::GlobalObject *go)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v5; // r9
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v6; // r8

  v2 = this;
  v3 = this->GlobalObjects.Data.Size;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = v2->GlobalObjects.Data.Data;
    v6 = v2->GlobalObjects.Data.Data;
    while ( *v6 != go )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        return;
    }
    if ( v3 == 1 )
    {
      if ( v2->GlobalObjects.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
      {
        if ( v5 )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Instances::fl::GlobalObject **, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v2->GlobalObjects.Data.Data,
            v3);
          v2->GlobalObjects.Data.Data = 0i64;
        }
        v2->GlobalObjects.Data.Policy.Capacity = 0i64;
      }
      v2->GlobalObjects.Data.Size = 0i64;
    }
    else
    {
      memmove(&v5[v4], &v5[v4 + 1], 8 * (v3 - v4) - 8);
      --v2->GlobalObjects.Data.Size;
    }
  }
}

// File Line: 2374
// RVA: 0x818AC0
void __fastcall Scaleform::GFx::AS3::VM::SetClassAlias(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *alias, Scaleform::GFx::AS3::Class *cl)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::TableType *v3; // rsi
  Scaleform::GFx::AS3::Class *v4; // rdi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rbp
  signed __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v10; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v11; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>,329,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *v12; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *v13; // rcx
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *v14; // rax
  unsigned __int64 v15; // r9
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeRef v16; // [rsp+20h] [rbp-28h]
  Scaleform::GFx::AS3::Class *key; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Class *value; // [rsp+60h] [rbp+18h]

  value = cl;
  v3 = this->AliasClass.mHash.pTable;
  v4 = cl;
  v5 = alias;
  v6 = this;
  if ( v3
    && (v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->AliasClass,
               alias,
               v3->SizeMask & alias->pNode->HashFlags),
        v7 >= 0)
    && (v8 = (signed __int64)v3 + 8 * (3 * v7 + 3)) != 0 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    key = (Scaleform::GFx::AS3::Class *)v9;
    if ( (Scaleform::GFx::AS3::Class *)v9 == v4 )
      return;
    v10 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)(*(__int64 (**)(void))(**(_QWORD **)(v9 + 40) + 56i64))();
    if ( v10 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::RemoveAlt<Scaleform::GFx::ASString>(
        v10 + 29,
        v5);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Class *>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v6->ClassAlias.mHash.pTable,
      &key);
    v11 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)((__int64 (*)(void))value->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)();
    if ( v11 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::add<Scaleform::GFx::ASString>(
        v11 + 29,
        &v11[29],
        v5,
        v5->pNode->HashFlags);
    Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>>>::Set(
      (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::Hashse)&v6->AliasClass.mHash,
      v5,
      &value);
    v12 = &v6->ClassAlias;
    v13 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v6->ClassAlias.mHash.pTable;
  }
  else
  {
    v14 = (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc> > *)((__int64 (*)(void))v4->pTraits.pObject->vfptr[2].~RefCountBaseGC<328>)();
    if ( v14 )
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::GFx::AS3::ASStringNodeHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::ASString,340>,Scaleform::HashsetEntry<Scaleform::GFx::ASString,Scaleform::GFx::AS3::ASStringNodeHashFunc>>::add<Scaleform::GFx::ASString>(
        v14 + 29,
        &v14[29],
        v5,
        v5->pNode->HashFlags);
    v16.pSecond = &value;
    v15 = v5->pNode->HashFlags;
    v16.pFirst = v5;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,329>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Class *,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> > *)&v6->AliasClass.mHash.pTable,
      &v6->AliasClass,
      &v16,
      v15);
    v13 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v6->ClassAlias.mHash.pTable;
    v12 = &v6->ClassAlias;
  }
  v16.pSecond = (Scaleform::GFx::AS3::Class *const *)v5;
  v16.pFirst = (Scaleform::GFx::ASString *)&value;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *>>::NodeRef>(
    v13,
    v12,
    (Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeRef *)&v16);
}

// File Line: 2420
// RVA: 0x7E6E40
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::VM::GetClassByAlias(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *alias)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v2; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v3; // rbx
  signed __int64 v4; // rax
  signed __int64 v5; // rax
  Scaleform::GFx::AS3::Class *result; // rax

  v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->AliasClass;
  v3.pTable = v2->pTable;
  if ( v2->pTable
    && (v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               v2,
               alias,
               v3.pTable->SizeMask & alias->pNode->HashFlags),
        v4 >= 0)
    && (v5 = (signed __int64)v3.pTable + 8 * (3 * v4 + 3)) != 0 )
  {
    result = *(Scaleform::GFx::AS3::Class **)(v5 + 8);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 2427
// RVA: 0x7E5C90
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::GetAliasByClass(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Class *cl)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rbx
  signed __int64 v5; // rax
  signed __int64 v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Class *key; // [rsp+50h] [rbp+18h]

  key = cl;
  v3 = result;
  v4 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
    result);
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::findIndexAlt<Scaleform::GFx::ASString>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Class *,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >,Scaleform::HashNode<Scaleform::GFx::AS3::Class *,Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::Class *> >::NodeHashF> > *)&v4->ClassAlias.mHash.pTable,
         &key);
  if ( v5 >= 0 )
  {
    v6 = (signed __int64)&v4->ClassAlias.mHash.pTable[2 * (v5 + 1)];
    if ( v6 )
    {
      if ( v3 )
      {
        v7 = *(Scaleform::GFx::ASStringNode **)(v6 + 8);
        ++v7->RefCount;
        v8 = v3->pNode;
        v9 = v3->pNode->RefCount == 1;
        --v8->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        v3->pNode = v7;
      }
    }
  }
  return v3;
}

// File Line: 2435
// RVA: 0x7F8BA0
_BOOL8 __fastcall Scaleform::GFx::AS3::VM::IsOfType(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *v, const char *type_name, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  unsigned __int64 v7; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  __int64 v9; // r8
  bool v10; // bl
  Scaleform::GFx::AS3::WeakProxy *v11; // rdx
  bool v12; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v13; // rcx
  unsigned int v14; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h]

  v4 = appDomain;
  v5 = v;
  v6 = this;
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
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v6, &mn, v4);
  v10 = v8 && Scaleform::GFx::AS3::VM::IsOfType(v6, v5, v8);
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v11 = mn.Name.Bonus.pWeakProxy;
      v12 = mn.Name.Bonus.pWeakProxy->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v11,
          v9);
      mn.Name.Bonus.pWeakProxy = 0i64;
      mn.Name.value = 0ui64;
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v13 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v14 = mn.Obj.pObject->RefCount;
      if ( v14 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
      }
    }
  }
  return v10;
}

// File Line: 2451
// RVA: 0x7F8CD0
char __fastcall Scaleform::GFx::AS3::VM::IsOfType(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *ctr)
{
  Scaleform::GFx::AS3::BuiltinTraitsType v3; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rsi
  bool v7; // zf
  bool v8; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rax
  long double v10; // rcx
  Scaleform::GFx::AS3::Class *v11; // rax
  long double iptr; // [rsp+38h] [rbp+10h]

  v3 = ctr->TraitsType;
  v4 = ctr;
  v5 = this;
  switch ( v->Flags & 0x1F )
  {
    case 1u:
      if ( v3 != 1 && ctr != (Scaleform::GFx::AS3::ClassTraits::Traits *)this->TraitsObject.pObject )
        return 0;
      return 1;
    case 2u:
      if ( v3 == 3 )
        return v->value.VS._1.VInt >= 0;
      if ( v3 == 4 )
        return 1;
      v7 = v3 == 2;
      goto LABEL_10;
    case 3u:
      if ( v3 == 2 )
        return v->value.VS._1.VInt <= 0x7FFFFFFFu;
      if ( v3 == 4 )
        return 1;
      v7 = v3 == 3;
LABEL_10:
      if ( !v7 )
      {
        v8 = ctr == (Scaleform::GFx::AS3::ClassTraits::Traits *)this->TraitsObject.pObject;
        goto LABEL_12;
      }
      return 1;
    case 4u:
      if ( modf(v->value.VNumber, &iptr) != 0.0 )
        goto LABEL_27;
      if ( v3 == 3 )
      {
        if ( iptr >= 0.0 && iptr <= 4294967295.0 )
          return 1;
      }
      else if ( v3 == 2 )
      {
        if ( iptr >= -2147483648.0 && iptr <= 2147483647.0 )
          return 1;
      }
      else
      {
LABEL_27:
        if ( v3 == 4 )
          return 1;
        v8 = v4 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v5->TraitsObject.pObject;
LABEL_12:
        if ( v8 )
          return 1;
      }
      return 0;
    case 0xAu:
      if ( !*(_QWORD *)&v->value.VNumber )
        return 0;
      v7 = v3 == 5;
      goto LABEL_10;
    case 0xBu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      goto $LN5_84;
    case 0xCu:
      if ( !*(_QWORD *)&v->value.VNumber )
        return 0;
$LN5_84:
      v9 = Scaleform::GFx::AS3::VM::GetClassTraits(this, v);
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(v9, v4);
    case 0xDu:
      v10 = v->value.VNumber;
      if ( v10 == 0.0 )
        return 0;
      v11 = Scaleform::GFx::AS3::Traits::GetConstructor(*(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v10 + 40i64));
      return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
               (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pTraits.pObject,
               v4);
    default:
      return 0;
  }
}

// File Line: 2522
// RVA: 0x8042E0
__int64 __fastcall Scaleform::GFx::AS3::VM::OnException(Scaleform::GFx::AS3::VM *this, unsigned __int64 offset, Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::CallFrame *v3; // r13
  unsigned __int64 v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // r14
  Scaleform::GFx::AS3::MethodInfo *v6; // r12
  unsigned __int64 i; // rdi
  unsigned __int64 v8; // rdx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v9; // r8
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v10; // rcx
  signed __int64 v11; // r15
  __int64 v12; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v13; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v14; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // rsi
  Scaleform::GFx::AS3::VM *v16; // rcx
  bool v17; // r8
  Scaleform::GFx::AS3::Value *v18; // rbx
  bool v19; // zf
  Scaleform::GFx::AS3::Value *v20; // rcx
  int v21; // eax
  long double v22; // rcx
  Scaleform::GFx::AS3::WeakProxy *v23; // rdx
  signed int v24; // er10
  Scaleform::GFx::AS3::VM *v25; // rcx
  bool v26; // r8
  Scaleform::GFx::AS3::Value *v27; // rcx
  int v28; // eax
  long double v29; // rcx

  v3 = cf;
  v4 = offset;
  v5 = this;
  v6 = &cf->pFile->MethodInfoArray.Data.Data[cf->MBIIndex.Ind];
  for ( i = 0i64; ; ++i )
  {
    v8 = v6->Exception.info.Data.Size;
    if ( i >= v8 )
    {
LABEL_59:
      v24 = -1;
      goto LABEL_60;
    }
    v9 = v6->Exception.info.Data.Data;
    v10 = &v9[i];
    while ( v4 < v10->from || v4 > v10->to )
    {
      ++i;
      ++v10;
      if ( i >= v8 )
        goto LABEL_59;
    }
    v11 = (signed __int64)&v9[i];
    v12 = *(signed int *)(v11 + 12);
    if ( !(_DWORD)v12 )
      break;
    if ( v5->ExceptionObj.Flags & 0x1F )
    {
      v13 = Scaleform::GFx::AS3::VM::GetClassTraits(v5, &v5->ExceptionObj);
      v5->HandleException = 0;
      v14 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
              v5,
              (Scaleform::GFx::AS3::VMFile *)&v3->pFile->vfptr,
              &v3->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v12]);
      v15 = v14;
      v5->HandleException = 1;
      if ( v14 )
      {
        if ( v14 == v13 )
          goto LABEL_17;
        if ( v13 )
        {
          while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v13->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
                     v13->ITraits.pObject,
                     v15->ITraits.pObject) )
          {
            v13 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v13->pParent.pObject;
            if ( v13 == v15 )
              break;
            if ( !v13 )
              goto LABEL_16;
          }
LABEL_17:
          v16 = v3->pFile->VMRef;
          v17 = !v3->DiscardResult && !v16->HandleException;
          Scaleform::GFx::AS3::ValueStack::PopReserved(&v16->OpStack, v3->PrevInitialStackPos, v17);
          v18 = &v5->ExceptionObj;
          v19 = v5->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
          ++v5->OpStack.pCurrent;
          v20 = v5->OpStack.pCurrent;
          if ( !v19 )
          {
            v20->Flags = v18->Flags;
            v20->Bonus.pWeakProxy = v5->ExceptionObj.Bonus.pWeakProxy;
            v20->value.VNumber = v5->ExceptionObj.value.VNumber;
            v20->value.VS._2.VObj = v5->ExceptionObj.value.VS._2.VObj;
            v21 = v18->Flags & 0x1F;
            if ( v21 > 9 )
            {
              if ( (v18->Flags >> 9) & 1 )
              {
                ++v5->ExceptionObj.Bonus.pWeakProxy->RefCount;
                goto LABEL_34;
              }
              if ( v21 == 10 )
              {
                ++*(_DWORD *)(*(_QWORD *)&v5->ExceptionObj.value.VNumber + 24i64);
              }
              else
              {
                if ( v21 <= 10 )
                  goto LABEL_34;
                if ( v21 <= 15 )
                {
                  v22 = v5->ExceptionObj.value.VNumber;
                }
                else
                {
                  if ( v21 > 17 )
                    goto LABEL_34;
                  v22 = *(double *)&v5->ExceptionObj.value.VS._2.VObj;
                }
                if ( v22 != 0.0 )
                  *(_DWORD *)(*(_QWORD *)&v22 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v22 + 32i64) + 1) & 0x8FBFFFFF;
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
  v25 = v3->pFile->VMRef;
  v26 = !v3->DiscardResult && !v25->HandleException;
  Scaleform::GFx::AS3::ValueStack::PopReserved(&v25->OpStack, v3->PrevInitialStackPos, v26);
  v18 = &v5->ExceptionObj;
  v19 = v5->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v5->OpStack.pCurrent;
  v27 = v5->OpStack.pCurrent;
  if ( !v19 )
  {
    v27->Flags = v18->Flags;
    v27->Bonus.pWeakProxy = v5->ExceptionObj.Bonus.pWeakProxy;
    v27->value.VNumber = v5->ExceptionObj.value.VNumber;
    v27->value.VS._2.VObj = v5->ExceptionObj.value.VS._2.VObj;
    v28 = v18->Flags & 0x1F;
    if ( v28 > 9 )
    {
      if ( (v18->Flags >> 9) & 1 )
      {
        ++v5->ExceptionObj.Bonus.pWeakProxy->RefCount;
        goto LABEL_34;
      }
      if ( v28 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v5->ExceptionObj.value.VNumber + 24i64);
      }
      else
      {
        if ( v28 <= 10 )
          goto LABEL_34;
        if ( v28 <= 15 )
        {
          v29 = v5->ExceptionObj.value.VNumber;
        }
        else
        {
          if ( v28 > 17 )
            goto LABEL_34;
          v29 = *(double *)&v5->ExceptionObj.value.VS._2.VObj;
        }
        if ( v29 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v29 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
LABEL_34:
  if ( (v18->Flags & 0x1F) > 9 )
  {
    if ( (v18->Flags >> 9) & 1 )
    {
      v23 = v18->Bonus.pWeakProxy;
      v19 = v23->RefCount-- == 1;
      if ( v19 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v18->Bonus.pWeakProxy = 0i64;
      v18->value.VNumber = 0.0;
      v18->value.VS._2.VObj = 0i64;
      v18->Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v18);
    }
  }
  v18->Flags = 0;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v3->pScopeStack->Data,
    v3->ScopeStackBaseInd);
  v24 = *(_DWORD *)(v11 + 8);
LABEL_60:
  v5->HandleException = v24 < 0;
  return (unsigned int)v24;
}

// File Line: 2589
// RVA: 0x8413D0
void __fastcall Scaleform::GFx::AS3::VM::exec_getsuper(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Traits *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::Value *v6; // rdx
  int v7; // ecx
  char v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-39h]
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+58h] [rbp-19h]
  Scaleform::GFx::AS3::StackReader v16; // [rsp+68h] [rbp-9h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::AS3::Value *result; // [rsp+A8h] [rbp+37h]
  __int64 v19; // [rsp+B8h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+67h]

  v19 = -2i64;
  v4 = ot;
  v5 = this;
  v16.VMRef = file->VMRef;
  v16.OpStack = &v16.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v16, &obj);
  v6 = v16.OpStack->pCurrent;
  result = v6;
  v7 = v6->Flags & 0x1F;
  if ( !v7 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*(_QWORD *)&v6->value.VNumber )
  {
    if ( (unsigned int)(v7 - 12) > 3 && v7 != 10 || (v8 = 1, *(_QWORD *)&v6->value.VNumber) )
      v8 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v8 != 0)), v16.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v16.VMRef, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v15.Message.pNode;
    v11 = v15.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( !v5->HandleException )
  {
    _this.Flags = result->Flags;
    _this.Bonus.pWeakProxy = result->Bonus.pWeakProxy;
    _this.value = result->value;
    result->Flags = 0;
    if ( Scaleform::GFx::AS3::GetSuperProperty(
           (Scaleform::GFx::AS3::CheckResult *)&retaddr,
           v5,
           v4,
           result,
           &_this,
           &obj)->Result )
    {
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, eIllegalSuperCallError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v13 = v15.Message.pNode;
      v11 = v15.Message.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v11 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 2605
// RVA: 0x846E50
void __fastcall Scaleform::GFx::AS3::VM::exec_setsuper(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Traits *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  int v6; // ecx
  char v7; // al
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::StackReader v13; // [rsp+28h] [rbp-49h]
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-39h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-19h]
  Scaleform::GFx::AS3::Value _this; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+A8h] [rbp+37h]
  __int64 v18; // [rsp+B8h] [rbp+47h]
  void *retaddr; // [rsp+D8h] [rbp+67h]

  v18 = -2i64;
  v4 = ot;
  v5 = this;
  v13.VMRef = file->VMRef;
  v13.OpStack = &v13.VMRef->OpStack;
  value.Flags = v13.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v13.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v13.VMRef->OpStack.pCurrent->value;
  --v13.OpStack->pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v13, &obj);
  _this.Flags = v13.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v13.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v13.OpStack->pCurrent->value;
  --v13.OpStack->pCurrent;
  v6 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    if ( (unsigned int)(v6 - 12) > 3 && v6 != 10 || (v7 = 1, *(_QWORD *)&_this.value.VNumber) )
      v7 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v7 != 0)), v13.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v13.VMRef, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v9 = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( v5->HandleException )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _this.Bonus.pWeakProxy = 0i64;
        _mm_store_si128((__m128i *)&_this.value, (__m128i)0i64);
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  }
  else if ( Scaleform::GFx::AS3::SetSuperProperty(
              (Scaleform::GFx::AS3::CheckResult *)&retaddr,
              v5,
              v4,
              &_this,
              &obj,
              &value)->Result )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _this.Bonus.pWeakProxy = 0i64;
        _mm_store_si128((__m128i *)&_this.value, (__m128i)0i64);
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eIllegalSuperCallError, v5);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v11, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v12 = v17.Message.pNode;
    v10 = v17.Message.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _this.Bonus.pWeakProxy = 0i64;
        _mm_store_si128((__m128i *)&_this.value, (__m128i)0i64);
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Flags &= 0xFFFFFDE0;
      value.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&value.value, (__m128i)0i64);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

// File Line: 2621
// RVA: 0x846960
void __fastcall Scaleform::GFx::AS3::VM::exec_setproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::StackReader v9; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS3::Value _this; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+B0h] [rbp+37h]
  __int64 v14; // [rsp+C0h] [rbp+47h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+E0h] [rbp+67h]

  v14 = -2i64;
  v3 = this;
  v9.VMRef = file->VMRef;
  v9.OpStack = &v9.VMRef->OpStack;
  value.Flags = v9.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v9.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v9.VMRef->OpStack.pCurrent->value;
  --v9.OpStack->pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v9, &obj);
  _this.Flags = v9.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v9.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v9.OpStack->pCurrent->value;
  --v9.OpStack->pCurrent;
  v4 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&_this.value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), v9.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( !v3->HandleException )
    Scaleform::GFx::AS3::SetProperty(&result, v3, &_this, &obj, &value);
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&_this.value, (__m128i)0i64);
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
    if ( (value.Flags >> 9) & 1 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&value.value, (__m128i)0i64);
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
void __fastcall Scaleform::GFx::AS3::VM::exec_callproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, unsigned int arg_count)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbx
  Scaleform::GFx::AS3::VMFile *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::Value *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  int v14; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::VU v16; // kr00_16
  int v17; // edx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  int v20; // eax
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::V2U v27; // [rsp+90h] [rbp-58h]
  __int64 v28; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+A8h] [rbp-40h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1E0h] [rbp+F8h]
  Scaleform::GFx::AS3::Value scope; // [rsp+210h] [rbp+128h]
  Scaleform::GFx::AS3::CheckResult v32[8]; // [rsp+258h] [rbp+170h]

  v28 = -2i64;
  v4 = arg_count;
  v5 = mn;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)((char *)&ptr + 24), file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v5);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&ptr.VMRef, &obj);
  scope.Flags = ptr.OpStack->pCurrent->Flags;
  scope.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v8 = ptr.OpStack->pCurrent;
  scope.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  scope.value.VS._2.VObj = v8->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  v9 = scope.Flags & 0x1F;
  if ( !(scope.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&scope.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&scope.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( v7->HandleException )
    goto LABEL_92;
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&result, v7, &scope, &obj, FindCall);
  if ( !(result.This.Flags & 0x1F)
    || (_QWORD)result.pSI & 1 && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    || (LOBYTE(result.pSI) >> 1) & 1 && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    if ( (LOBYTE(Scaleform::GFx::AS3::VM::GetValueTraits(v7, &scope)->Flags) >> 1) & 1
      || (v20 = scope.Flags & 0x1F, v20 <= 4)
      || v20 == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
        eCallOfNonFunctionError,
        v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v23, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v24 = result.This.value.VS._1.VStr;
      v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
      --v24->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      goto LABEL_86;
    }
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, eReadSealedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v21, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v22 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v22->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    if ( (result.This.Flags & 0x1F) <= 9 )
    {
LABEL_74:
      Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject((Scaleform::GFx::AS3::ReadArgsMnObject *)&ptr);
      return;
    }
    if ( (result.This.Flags >> 9) & 1 )
    {
      v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.This.Bonus.pWeakProxy = 0i64;
        result.SlotIndex = 0i64;
        *(_QWORD *)&result.This.Flags = 0i64;
        goto LABEL_74;
      }
      goto LABEL_72;
    }
    goto LABEL_73;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v32, v7, &value, valExecute)->Result )
  {
    v14 = value.Flags & 0x1F;
    if ( value.Flags & 0x1F && ((unsigned int)(v14 - 12) > 3 && v14 != 10 || *(_QWORD *)&value.value.VNumber) )
    {
      argv = ptr.FixedArr;
      if ( ptr.ArgNum > 8 )
        argv = ptr.CallArgs.Data.Data;
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      LODWORD(result.This.Bonus.pWeakProxy) = v.Flags;
      result.This.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
      v16 = v.value;
      v27.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
      v17 = v.Flags & 0x1F;
      if ( v17 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( v17 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        }
        else if ( v17 > 10 )
        {
          if ( v17 <= 15 )
          {
            if ( *(_QWORD *)&v.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
              *(_DWORD *)(*(_QWORD *)&v16.VNumber + 32i64) &= 0x8FBFFFFF;
            }
          }
          else if ( v17 <= 17 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            v16.VS._2.VObj->RefCount &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        v7,
        &value,
        &scope,
        (Scaleform::GFx::AS3::Value *)((char *)&result.This + 8),
        v4,
        argv,
        1);
      if ( ((_QWORD)result.This.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( (LODWORD(result.This.Bonus.pWeakProxy) >> 9) & 1 )
        {
          v13 = result.This.value.VS._1.VStr->pData-- == (const char *)1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.This.value = 0ui64;
          v27.VObj = 0i64;
          LODWORD(result.This.Bonus.pWeakProxy) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&result.This + 8));
        }
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_74;
      if ( (result.This.Flags >> 9) & 1 )
      {
        v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
        {
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.This.Bonus.pWeakProxy = 0i64;
          result.SlotIndex = 0i64;
          *(_QWORD *)&result.This.Flags = 0i64;
          goto LABEL_74;
        }
LABEL_72:
        result.This.Bonus.pWeakProxy = 0i64;
        result.SlotIndex = 0i64;
        *(_QWORD *)&result.This.Flags = 0i64;
        goto LABEL_74;
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
        eCallOfNonFunctionError,
        v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v19 = result.This.value.VS._1.VStr;
      v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
      --v19->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) <= 9 )
        goto LABEL_74;
      if ( (result.This.Flags >> 9) & 1 )
      {
        v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        goto LABEL_72;
      }
    }
LABEL_73:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    goto LABEL_74;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
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
    if ( (result.This.Flags >> 9) & 1 )
    {
      v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.SlotIndex = 0i64;
      *(_QWORD *)&result.This.Flags = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_92:
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags >> 9) & 1 )
    {
      v13 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&scope.Bonus, (__m128i)0i64);
      scope.value.VS._2.VObj = 0i64;
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  *(_QWORD *)&v32[0].Result = (char *)&ptr + 280;
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
  Scaleform::GFx::AS3::VM *v1; // rbx
  bool v2; // zf
  Scaleform::GFx::AS3::Value::VU *v3; // rcx
  int v4; // eax
  long double v5; // rax

  v1 = this;
  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].DiscardResult )
  {
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v2 = v1->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++v1->OpStack.pCurrent;
    v3 = (Scaleform::GFx::AS3::Value::VU *)v1->OpStack.pCurrent;
    if ( !v2 )
    {
      LODWORD(v3->VS._1.VStr) = v.Flags;
      v3->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
      v3[1] = v.value;
      v4 = v.Flags & 0x1F;
      if ( v4 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
          return;
        }
        if ( v4 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        }
        else
        {
          if ( v4 <= 10 )
            return;
          if ( v4 <= 15 )
          {
            v5 = v.value.VNumber;
          }
          else
          {
            if ( v4 > 17 )
              return;
            v5 = *(double *)&v.value.VS._2.VObj;
          }
          if ( v5 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v5 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v5 + 32i64) &= 0x8FBFFFFF;
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
  Scaleform::GFx::AS3::VM *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf

  v1 = this;
  if ( !this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].DiscardResult )
  {
    Scaleform::GFx::AS3::VM::Coerce2ReturnType(this, this->OpStack.pCurrent, this->OpStack.pCurrent);
    return;
  }
  v2 = this->OpStack.pCurrent;
  if ( (v2->Flags & 0x1F) <= 9 )
  {
LABEL_8:
    --v1->OpStack.pCurrent;
    return;
  }
  if ( !((v2->Flags >> 9) & 1) )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    goto LABEL_8;
  }
  v3 = v2->Bonus.pWeakProxy;
  v4 = v3->RefCount-- == 1;
  if ( v4 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v2->Flags &= 0xFFFFFDE0;
  v2->Bonus.pWeakProxy = 0i64;
  v2->value.VNumber = 0.0;
  v2->value.VS._2.VObj = 0i64;
  --v1->OpStack.pCurrent;
}

// File Line: 2783
// RVA: 0x83A9D0
void __fastcall Scaleform::GFx::AS3::VM::exec_callproplex(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, unsigned int arg_count)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbx
  Scaleform::GFx::AS3::VMFile *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::Value *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  int v14; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value *v16; // rdi
  Scaleform::GFx::AS3::Value::VU v17; // kr00_16
  int v18; // edx
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::V2U v27; // [rsp+90h] [rbp-58h]
  __int64 v28; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+A8h] [rbp-40h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1E0h] [rbp+F8h]
  Scaleform::GFx::AS3::Value scope; // [rsp+210h] [rbp+128h]
  Scaleform::GFx::AS3::CheckResult v32[8]; // [rsp+258h] [rbp+170h]

  v28 = -2i64;
  v4 = arg_count;
  v5 = mn;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)((char *)&ptr + 24), file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v5);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&ptr.VMRef, &obj);
  scope.Flags = ptr.OpStack->pCurrent->Flags;
  scope.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v8 = ptr.OpStack->pCurrent;
  scope.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  scope.value.VS._2.VObj = v8->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  v9 = scope.Flags & 0x1F;
  if ( !(scope.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&scope.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&scope.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( !v7->HandleException )
  {
    result.pSI = 0i64;
    result.SlotIndex = 0i64;
    result.This.Flags = 0;
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&result, v7, &scope, &obj, FindCall);
    if ( result.This.Flags & 0x1F
      && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v32, v7, &value, valExecute)->Result )
      {
        v14 = value.Flags & 0x1F;
        if ( value.Flags & 0x1F && ((unsigned int)(v14 - 12) > 3 && v14 != 10 || *(_QWORD *)&value.value.VNumber) )
        {
          argv = ptr.FixedArr;
          if ( ptr.ArgNum > 8 )
            argv = ptr.CallArgs.Data.Data;
          v16 = Scaleform::GFx::AS3::Value::GetUndefined();
          if ( !(_S11_12 & 1) )
          {
            _S11_12 |= 1u;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0i64;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          LODWORD(result.This.Bonus.pWeakProxy) = v.Flags;
          result.This.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
          v17 = v.value;
          v27.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
          v18 = v.Flags & 0x1F;
          if ( v18 > 9 )
          {
            if ( (v.Flags >> 9) & 1 )
            {
              ++v.Bonus.pWeakProxy->RefCount;
            }
            else if ( v18 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
            }
            else if ( v18 > 10 )
            {
              if ( v18 <= 15 )
              {
                if ( *(_QWORD *)&v.value.VNumber )
                {
                  ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
                  *(_DWORD *)(*(_QWORD *)&v17.VNumber + 32i64) &= 0x8FBFFFFF;
                }
              }
              else if ( v18 <= 17 && v.value.VS._2.VObj )
              {
                ++v.value.VS._2.VObj->RefCount;
                v17.VS._2.VObj->RefCount &= 0x8FBFFFFF;
              }
            }
          }
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
            v7,
            &value,
            v16,
            (Scaleform::GFx::AS3::Value *)((char *)&result.This + 8),
            v4,
            argv,
            1);
          if ( ((_QWORD)result.This.Bonus.pWeakProxy & 0x1F) > 9 )
          {
            if ( (LODWORD(result.This.Bonus.pWeakProxy) >> 9) & 1 )
            {
              v13 = result.This.value.VS._1.VStr->pData-- == (const char *)1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              result.This.value = 0ui64;
              v27.VObj = 0i64;
              LODWORD(result.This.Bonus.pWeakProxy) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&result.This + 8));
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags >> 9) & 1 )
            {
              v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              value.Bonus.pWeakProxy = 0i64;
              value.value = 0ui64;
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (result.This.Flags & 0x1F) <= 9 )
            goto LABEL_56;
          if ( (result.This.Flags >> 9) & 1 )
          {
            v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_54:
            result.This.Bonus.pWeakProxy = 0i64;
            result.SlotIndex = 0i64;
            *(_QWORD *)&result.This.Flags = 0i64;
LABEL_56:
            Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject((Scaleform::GFx::AS3::ReadArgsMnObject *)&ptr);
            return;
          }
          goto LABEL_55;
        }
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eCallOfNonFunctionError,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v19, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v20 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v20->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
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
      if ( !((LOBYTE(Scaleform::GFx::AS3::VM::GetValueTraits(v7, &scope)->Flags) >> 1) & 1) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eReadSealedError,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v23, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v24 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v24->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        if ( (result.This.Flags & 0x1F) <= 9 )
          goto LABEL_56;
        if ( (result.This.Flags >> 9) & 1 )
        {
          v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
          {
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            result.This.Bonus.pWeakProxy = 0i64;
            result.SlotIndex = 0i64;
            *(_QWORD *)&result.This.Flags = 0i64;
            goto LABEL_56;
          }
          goto LABEL_54;
        }
LABEL_55:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_56;
      }
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
        eCallOfNonFunctionError,
        v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v21, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v22 = result.This.value.VS._1.VStr;
      v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
      --v22->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    }
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.This.Bonus.pWeakProxy = 0i64;
        result.SlotIndex = 0i64;
        *(_QWORD *)&result.This.Flags = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
  }
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags >> 9) & 1 )
    {
      v13 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&scope.Bonus, (__m128i)0i64);
      scope.value.VS._2.VObj = 0i64;
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  *(_QWORD *)&v32[0].Result = (char *)&ptr + 280;
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
void __fastcall Scaleform::GFx::AS3::VM::exec_callpropvoid(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, unsigned int arg_count)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbx
  Scaleform::GFx::AS3::VMFile *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::Value *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  int v14; // ecx
  Scaleform::GFx::AS3::Value *argv; // rbx
  Scaleform::GFx::AS3::Value::VU v16; // kr00_16
  int v17; // edx
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::V2U v26; // [rsp+90h] [rbp-58h]
  __int64 v27; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+A8h] [rbp-40h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1E0h] [rbp+F8h]
  Scaleform::GFx::AS3::Value scope; // [rsp+210h] [rbp+128h]
  Scaleform::GFx::AS3::CheckResult v31[8]; // [rsp+258h] [rbp+170h]

  v27 = -2i64;
  v4 = arg_count;
  v5 = mn;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)((char *)&ptr + 24), file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v5);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&ptr.VMRef, &obj);
  scope.Flags = ptr.OpStack->pCurrent->Flags;
  scope.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v8 = ptr.OpStack->pCurrent;
  scope.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  scope.value.VS._2.VObj = v8->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  v9 = scope.Flags & 0x1F;
  if ( !(scope.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&scope.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&scope.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( !v7->HandleException )
  {
    result.pSI = 0i64;
    result.SlotIndex = 0i64;
    result.This.Flags = 0;
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&result, v7, &scope, &obj, FindCall);
    if ( result.This.Flags & 0x1F
      && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v31, v7, &value, valExecute)->Result )
      {
        v14 = value.Flags & 0x1F;
        if ( value.Flags & 0x1F && ((unsigned int)(v14 - 12) > 3 && v14 != 10 || *(_QWORD *)&value.value.VNumber) )
        {
          argv = ptr.FixedArr;
          if ( ptr.ArgNum > 8 )
            argv = ptr.CallArgs.Data.Data;
          if ( !(_S11_12 & 1) )
          {
            _S11_12 |= 1u;
            v.Flags = 0;
            v.Bonus.pWeakProxy = 0i64;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          LODWORD(result.This.Bonus.pWeakProxy) = v.Flags;
          result.This.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
          v16 = v.value;
          v26.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
          v17 = v.Flags & 0x1F;
          if ( v17 > 9 )
          {
            if ( (v.Flags >> 9) & 1 )
            {
              ++v.Bonus.pWeakProxy->RefCount;
            }
            else if ( v17 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
            }
            else if ( v17 > 10 )
            {
              if ( v17 <= 15 )
              {
                if ( *(_QWORD *)&v.value.VNumber )
                {
                  ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
                  *(_DWORD *)(*(_QWORD *)&v16.VNumber + 32i64) &= 0x8FBFFFFF;
                }
              }
              else if ( v17 <= 17 && v.value.VS._2.VObj )
              {
                ++v.value.VS._2.VObj->RefCount;
                v16.VS._2.VObj->RefCount &= 0x8FBFFFFF;
              }
            }
          }
          Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
            v7,
            &value,
            &scope,
            (Scaleform::GFx::AS3::Value *)((char *)&result.This + 8),
            v4,
            argv,
            0);
          if ( ((_QWORD)result.This.Bonus.pWeakProxy & 0x1F) > 9 )
          {
            if ( (LODWORD(result.This.Bonus.pWeakProxy) >> 9) & 1 )
            {
              v13 = result.This.value.VS._1.VStr->pData-- == (const char *)1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              result.This.value = 0ui64;
              v26.VObj = 0i64;
              LODWORD(result.This.Bonus.pWeakProxy) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&result.This + 8));
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags >> 9) & 1 )
            {
              v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              value.Bonus.pWeakProxy = 0i64;
              value.value = 0ui64;
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (result.This.Flags & 0x1F) <= 9 )
            goto LABEL_56;
          if ( (result.This.Flags >> 9) & 1 )
          {
            v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_54:
            result.This.Bonus.pWeakProxy = 0i64;
            result.SlotIndex = 0i64;
            *(_QWORD *)&result.This.Flags = 0i64;
LABEL_56:
            Scaleform::GFx::AS3::ReadArgsMnObject::~ReadArgsMnObject((Scaleform::GFx::AS3::ReadArgsMnObject *)&ptr);
            return;
          }
          goto LABEL_55;
        }
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eCallOfNonFunctionError,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v19 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v19->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
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
      if ( !((LOBYTE(Scaleform::GFx::AS3::VM::GetValueTraits(v7, &scope)->Flags) >> 1) & 1) )
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eReadSealedError,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v22, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v23 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v23->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        if ( (result.This.Flags & 0x1F) <= 9 )
          goto LABEL_56;
        if ( (result.This.Flags >> 9) & 1 )
        {
          v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
          {
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            result.This.Bonus.pWeakProxy = 0i64;
            result.SlotIndex = 0i64;
            *(_QWORD *)&result.This.Flags = 0i64;
            goto LABEL_56;
          }
          goto LABEL_54;
        }
LABEL_55:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
        goto LABEL_56;
      }
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
        eCallOfNonFunctionError,
        v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v21 = result.This.value.VS._1.VStr;
      v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
      --v21->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.This.Bonus.pWeakProxy = 0i64;
        result.SlotIndex = 0i64;
        *(_QWORD *)&result.This.Flags = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
  }
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags >> 9) & 1 )
    {
      v13 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&scope.Bonus, (__m128i)0i64);
      scope.value.VS._2.VObj = 0i64;
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  *(_QWORD *)&v31[0].Result = (char *)&ptr + 280;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2912
// RVA: 0x839E80
void __fastcall Scaleform::GFx::AS3::VM::exec_callmethod(Scaleform::GFx::AS3::VM *this, unsigned int method_index, unsigned int arg_count)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rcx
  int v6; // ecx
  char v7; // al
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Traits *v11; // rax
  _DWORD *v12; // rdx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-C8h]
  __int64 v14; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-A8h]
  __int128 v16; // [rsp+188h] [rbp+90h]
  Scaleform::GFx::AS3::Value::V2U v17; // [rsp+198h] [rbp+A0h]
  Scaleform::GFx::AS3::Value::V2U *retaddr; // [rsp+1B8h] [rbp+C0h]

  v14 = -2i64;
  v3 = method_index;
  v4 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  LODWORD(ptr.CallArgs.Data.pHeap) = ptr.OpStack->pCurrent->Flags;
  *(_QWORD *)&v16 = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v5 = ptr.OpStack->pCurrent;
  *((_QWORD *)&v16 + 1) = *(_QWORD *)&ptr.OpStack->pCurrent->value.VNumber;
  v17.VObj = (Scaleform::GFx::AS3::Object *)v5->value.VS._2;
  --ptr.OpStack->pCurrent;
  v6 = (_QWORD)ptr.CallArgs.Data.pHeap & 0x1F;
  if ( !((_QWORD)ptr.CallArgs.Data.pHeap & 0x1F) || ((unsigned int)(v6 - 12) <= 3 || v6 == 10) && !*((_QWORD *)&v16 + 1) )
  {
    v7 = (unsigned int)(v6 - 12) > 3 && v6 != 10 || *((_QWORD *)&v16 + 1) ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v7 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v9 = v13.Message.pNode;
    v10 = v13.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( !v4->HandleException )
  {
    v11 = Scaleform::GFx::AS3::VM::GetValueTraits(v4, (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.pHeap);
    Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(v4, v3, v11, (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.pHeap);
  }
  if ( ((_QWORD)ptr.CallArgs.Data.pHeap & 0x1F) > 9 )
  {
    if ( (LODWORD(ptr.CallArgs.Data.pHeap) >> 9) & 1 )
    {
      v12 = (_DWORD *)v16;
      v10 = *(_DWORD *)v16 == 1;
      --*v12;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v12);
      _mm_store_si128((__m128i *)&v16, (__m128i)0i64);
      v17.VObj = 0i64;
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
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupermethod(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Traits *ot, unsigned int method_index, unsigned int arg_count)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::Traits *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // rcx
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Traits *v13; // r8
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  _DWORD *v16; // rdx
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::Value::V2U v19; // [rsp+178h] [rbp+90h]
  __int64 v20; // [rsp+188h] [rbp+A0h]
  Scaleform::GFx::AS3::Value::Extra *v21; // [rsp+1B8h] [rbp+D0h]

  v20 = -2i64;
  v4 = method_index;
  v5 = ot;
  v6 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  LODWORD(ptr.CallArgs.Data.Size) = ptr.OpStack->pCurrent->Flags;
  ptr.CallArgs.Data.Policy.Capacity = (unsigned __int64)ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v7 = ptr.OpStack->pCurrent;
  ptr.CallArgs.Data.pHeap = (Scaleform::MemoryHeap *)ptr.OpStack->pCurrent->value.VS._1.VStr;
  v19.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
  --ptr.OpStack->pCurrent;
  v8 = ptr.CallArgs.Data.Size & 0x1F;
  if ( !(ptr.CallArgs.Data.Size & 0x1F) || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !ptr.CallArgs.Data.pHeap )
  {
    v9 = (unsigned int)(v8 - 12) > 3 && v8 != 10 || ptr.CallArgs.Data.pHeap ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v9 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v11 = v17.Message.pNode;
    v12 = v17.Message.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( v6->HandleException )
  {
    if ( (ptr.CallArgs.Data.Size & 0x1F) > 9 )
    {
      if ( (LODWORD(ptr.CallArgs.Data.Size) >> 9) & 1 )
      {
        v12 = (*(_DWORD *)ptr.CallArgs.Data.Policy.Capacity)-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _mm_store_si128((__m128i *)&ptr.CallArgs.Data.Policy, (__m128i)0i64);
        v19.VObj = 0i64;
        LODWORD(ptr.CallArgs.Data.Size) &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size);
      }
    }
    v21 = &ptr.FixedArr[7].Bonus;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
      (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].Bonus.pWeakProxy,
      (unsigned __int64)ptr.FixedArr[7].value.VS._1.VStr);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].Bonus.pWeakProxy);
  }
  else
  {
    v13 = v5->pParent.pObject;
    if ( v13 )
    {
      Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(
        v6,
        v4,
        v13,
        (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size);
      if ( (ptr.CallArgs.Data.Size & 0x1F) > 9 )
      {
        if ( (LODWORD(ptr.CallArgs.Data.Size) >> 9) & 1 )
        {
          v16 = (_DWORD *)ptr.CallArgs.Data.Policy.Capacity;
          v12 = *(_DWORD *)ptr.CallArgs.Data.Policy.Capacity == 1;
          --*v16;
          if ( v12 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v16);
          _mm_store_si128((__m128i *)&ptr.CallArgs.Data.Policy, (__m128i)0i64);
          v19.VObj = 0i64;
          LODWORD(ptr.CallArgs.Data.Size) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size);
        }
      }
      v21 = &ptr.FixedArr[7].Bonus;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].Bonus.pWeakProxy,
        (unsigned __int64)ptr.FixedArr[7].value.VS._1.VStr);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].Bonus.pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v17, eIllegalSuperCallError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v14, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v15 = v17.Message.pNode;
      v12 = v17.Message.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( (ptr.CallArgs.Data.Size & 0x1F) > 9 )
      {
        if ( (LODWORD(ptr.CallArgs.Data.Size) >> 9) & 1 )
        {
          v12 = (*(_DWORD *)ptr.CallArgs.Data.Policy.Capacity)-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _mm_store_si128((__m128i *)&ptr.CallArgs.Data.Policy, (__m128i)0i64);
          v19.VObj = 0i64;
          LODWORD(ptr.CallArgs.Data.Size) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size);
        }
      }
      v21 = &ptr.FixedArr[7].Bonus;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].Bonus.pWeakProxy,
        (unsigned __int64)ptr.FixedArr[7].value.VS._1.VStr);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].Bonus.pWeakProxy);
    }
  }
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 2972
// RVA: 0x839AA0
void __fastcall Scaleform::GFx::AS3::VM::exec_callgetter(Scaleform::GFx::AS3::VM *this, unsigned int method_index, unsigned int arg_count)
{
  unsigned int argc; // esi
  __int64 v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rdi
  unsigned int *v6; // rcx
  int v7; // ecx
  char v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Traits *v12; // rax
  Scaleform::GFx::AS3::Value *v13; // rdx
  Scaleform::GFx::AS3::Value *argv; // rbx
  __int64 v15; // rcx
  __int64 v16; // r8
  Scaleform::GFx::AS3::Value::VU v17; // kr00_16
  int v18; // edx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::Value::VU v20; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-88h]
  unsigned int **v22; // [rsp+80h] [rbp-68h]
  unsigned int v23; // [rsp+88h] [rbp-60h]
  char ptr; // [rsp+90h] [rbp-58h]
  Scaleform::GFx::AS3::Value *v25; // [rsp+190h] [rbp+A8h]
  unsigned __int64 v26; // [rsp+198h] [rbp+B0h]
  Scaleform::GFx::AS3::Value v; // [rsp+1B0h] [rbp+C8h]
  Scaleform::GFx::AS3::Value **v28; // [rsp+1F8h] [rbp+110h]

  result.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)-2i64;
  argc = arg_count;
  v4 = method_index;
  v5 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, this, arg_count);
  v.Flags = **v22;
  v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*v22 + 1);
  v6 = *v22;
  v.value.VNumber = *((long double *)*v22 + 2);
  v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)*((_QWORD *)v6 + 3);
  *v22 -= 8;
  v7 = v.Flags & 0x1F;
  if ( !(v.Flags & 0x1F) || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*(_QWORD *)&v.value.VNumber )
  {
    if ( (unsigned int)(v7 - 12) > 3 && v7 != 10 || (v8 = 1, *(_QWORD *)&v.value.VNumber) )
      v8 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v19,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v8 != 0)),
      (Scaleform::GFx::AS3::VM *)result.value.VS._2.VObj);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)result.value.VS._2.VObj,
      v9,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v19.Message.pNode;
    v11 = v19.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( !v5->HandleException )
  {
    v12 = Scaleform::GFx::AS3::VM::GetValueTraits(v5, &v);
    v13 = &Scaleform::GFx::AS3::Traits::GetVT(v12)->VTMethods.Data.Data[v4];
    result.Flags = 0;
    result.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, v13, &v, &result, 0, 0i64, 0);
    if ( !v5->HandleException )
    {
      argv = (Scaleform::GFx::AS3::Value *)&ptr;
      if ( v23 > 8 )
        argv = v25;
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        ::v.Flags = 0;
        ::v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v19.ID = ::v.Flags;
      v19.Message.pNode = (Scaleform::GFx::ASStringNode *)::v.Bonus.pWeakProxy;
      v17 = ::v.value;
      v16 = *(_OWORD *)&v17 >> 64;
      v15 = (unsigned __int128)v17;
      v20 = ::v.value;
      v18 = ::v.Flags & 0x1F;
      if ( v18 > 9 )
      {
        if ( (::v.Flags >> 9) & 1 )
        {
          ++::v.Bonus.pWeakProxy->RefCount;
        }
        else if ( v18 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&::v.value.VNumber + 24i64);
        }
        else if ( v18 > 10 )
        {
          if ( v18 <= 15 )
          {
            if ( *(_QWORD *)&::v.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&::v.value.VNumber + 32i64);
              *(_DWORD *)(v15 + 32) &= 0x8FBFFFFF;
            }
          }
          else if ( v18 <= 17 && ::v.value.VS._2.VObj )
          {
            ++::v.value.VS._2.VObj->RefCount;
            *(_DWORD *)(v16 + 32) &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, &result, &v, (Scaleform::GFx::AS3::Value *)&v19, argc, argv, 1);
      if ( (v19.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v19.ID >> 9) & 1 )
        {
          v11 = v19.Message.pNode->pData-- == (const char *)1;
          if ( v11 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v19.Message.pNode = 0i64;
          v20 = 0ui64;
          v19.ID &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v19);
        }
      }
    }
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags >> 9) & 1 )
      {
        v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.Bonus.pWeakProxy = 0i64;
        result.value = 0ui64;
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
    if ( (v.Flags >> 9) & 1 )
    {
      v11 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&v.Bonus, (__m128i)0i64);
      v.value.VS._2.VObj = 0i64;
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  v28 = &v25;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3008
// RVA: 0x83C230
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupergetter(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Traits *ot, unsigned int method_index, unsigned int arg_count)
{
  unsigned int argc; // er14
  int v5; // esi
  Scaleform::GFx::AS3::Traits *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::Value::V2U v14; // rax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::Value *argv; // rdi
  Scaleform::GFx::AS3::Value::VU v18; // kr00_16
  int v19; // edx
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::V2U v22; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+88h] [rbp-60h]
  Scaleform::GFx::AS3::Value _this; // [rsp+1C0h] [rbp+D8h]
  __int64 v25; // [rsp+1E8h] [rbp+100h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v26; // [rsp+218h] [rbp+130h]

  v25 = -2i64;
  argc = arg_count;
  v5 = method_index;
  v6 = ot;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)((char *)&ptr + 24), this, arg_count);
  _this.Flags = ptr.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v8 = ptr.OpStack->pCurrent;
  _this.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  _this.value.VS._2.VObj = v8->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  v9 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&_this.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.Bonus,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = result.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 24i64) == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( v7->HandleException )
    goto LABEL_76;
  v14.VObj = (Scaleform::GFx::AS3::Object *)v6->pParent.pObject;
  if ( !v14.VObj )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.Bonus, eIllegalSuperCallError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v15, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v16 = result.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.value.VNumber + 24i64) == 1;
    --v16->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
        _this.value.VS._2.VObj = 0i64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    v26 = &ptr.CallArgs;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
    goto LABEL_83;
  }
  func.Flags = 7;
  func.Bonus.pWeakProxy = 0i64;
  func.value.VS._2 = v14;
  func.value.VS._1.VInt = v5;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7, &func, &_this, &result, 0, 0i64, 0);
  if ( v7->HandleException )
  {
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags >> 9) & 1 )
      {
        v13 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.Bonus.pWeakProxy = 0i64;
        result.value = 0ui64;
        result.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags >> 9) & 1 )
      {
        v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        func.Bonus.pWeakProxy = 0i64;
        func.value = 0ui64;
        func.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
LABEL_76:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
        _this.value.VS._2.VObj = 0i64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    v26 = &ptr.CallArgs;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
    goto LABEL_83;
  }
  argv = ptr.FixedArr;
  if ( ptr.ArgNum > 8 )
    argv = ptr.CallArgs.Data.Data;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  LODWORD(result.Bonus.pWeakProxy) = v.Flags;
  result.value = *(Scaleform::GFx::AS3::Value::VU *)&v.Bonus.pWeakProxy;
  v18 = v.value;
  v22.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v19 = v.Flags & 0x1F;
  if ( v19 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v19 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v19 > 10 )
    {
      if ( v19 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(*(_QWORD *)&v18.VNumber + 32i64) &= 0x8FBFFFFF;
        }
      }
      else if ( v19 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v18.VS._2.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
    v7,
    &result,
    &_this,
    (Scaleform::GFx::AS3::Value *)((char *)&result + 8),
    argc,
    argv,
    1);
  if ( ((_QWORD)result.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( (LODWORD(result.Bonus.pWeakProxy) >> 9) & 1 )
    {
      v13 = result.value.VS._1.VStr->pData-- == (const char *)1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.value = 0ui64;
      v22.VObj = 0i64;
      LODWORD(result.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&result + 8));
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v13 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags >> 9) & 1 )
    {
      v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      func.Bonus.pWeakProxy = 0i64;
      func.value = 0ui64;
      func.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
    }
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
      _this.value.VS._2.VObj = 0i64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  v26 = &ptr.CallArgs;
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
void __fastcall Scaleform::GFx::AS3::VM::exec_callstatic(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::MiInd ind, unsigned int arg_count)
{
  unsigned int v4; // er12
  Scaleform::GFx::AS3::VMAbcFile *v5; // r15
  Scaleform::GFx::AS3::VM *v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // rcx
  int v8; // ecx
  char v9; // al
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  __int64 v13; // rbx
  Scaleform::GFx::AS3::Traits *v14; // rdi
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM *v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // rcx
  Scaleform::GFx::AS3::Value::VU v20; // kr00_16
  int v21; // er8
  Scaleform::GFx::AS3::ValueStack *v22; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v23; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v24; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v25; // rcx
  unsigned int v26; // eax
  unsigned __int64 v27; // rdi
  Scaleform::GFx::AS3::CallFrame **v28; // rax
  signed __int64 v29; // rcx
  Scaleform::GFx::AS3::CallFrame *v30; // rcx
  Scaleform::GFx::AS3::VM::Error v31; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+40h] [rbp-C0h]
  __int64 v33; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS3::Value _this; // [rsp+218h] [rbp+118h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v36; // [rsp+280h] [rbp+180h]
  int v37; // [rsp+290h] [rbp+190h]

  v37 = ind.Ind;
  v33 = -2i64;
  v4 = arg_count;
  v5 = file;
  v6 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  _this.Flags = ptr.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v7 = ptr.OpStack->pCurrent;
  _this.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  _this.value.VS._2.VObj = v7->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  v8 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    if ( (unsigned int)(v8 - 12) > 3 && v8 != 10 || (v9 = 1, *(_QWORD *)&_this.value.VNumber) )
      v9 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v31, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v9 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v11 = v31.Message.pNode;
    v12 = v31.Message.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( !v6->HandleException )
  {
    v13 = v5->File.pObject->Methods.Info.Data.Data[v37]->MethodBodyInfoInd;
    v14 = *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&_this.value.VNumber + 40i64);
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    if ( v6->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eStackOverflowError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v15, &Scaleform::GFx::AS3::fl::ErrorTI);
      v16 = v31.Message.pNode;
      v12 = v31.Message.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    else
    {
      *(_WORD *)&other.DiscardResult = 0;
      v17 = v5->VMRef;
      other.ScopeStackBaseInd = v17->ScopeStack.Data.Size;
      other.CP = 0i64;
      other.pRegisterFile = &v17->RegisterFile;
      other.pHeap = v17->MHeap;
      other.pFile = v5;
      other.MBIIndex.Ind = v13;
      other.pSavedScope = &v14->InitScope;
      other.OriginationTraits = v14;
      other.pScopeStack = &v17->ScopeStack;
      other.DefXMLNamespace.pObject = 0i64;
      other.Invoker.Flags = v.Flags;
      other.Invoker.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
      v20 = v.value;
      v18 = *(_OWORD *)&v20 >> 64;
      v19 = (unsigned __int128)v20;
      other.Invoker.value = v.value;
      v21 = v.Flags & 0x1F;
      if ( v21 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( v21 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        }
        else if ( v21 > 10 )
        {
          if ( v21 <= 15 )
          {
            if ( *(_QWORD *)&v.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
              *(_DWORD *)(v19 + 32) &= 0x8FBFFFFF;
            }
          }
          else if ( v21 <= 17 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            *(_DWORD *)(v18 + 32) &= 0x8FBFFFFF;
          }
        }
      }
      v22 = &v5->VMRef->OpStack;
      other.PrevInitialStackPos = v22->pCurrent;
      other.PrevFirstStackPos = v22->pStack;
      v23 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
      Scaleform::GFx::AS3::ValueStack::Reserve(v22, v23->max_stack + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v23->local_reg_count);
      v24 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
      if ( *v24 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
          *v24);
        v36 = 0i64;
        if ( &v36 != (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> **)v24 )
        {
          v25 = *v24;
          if ( *v24 )
          {
            if ( (unsigned __int8)v25 & 1 )
            {
              *v24 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v25 - 1);
            }
            else
            {
              v26 = v25->RefCount;
              if ( v26 & 0x3FFFFF )
              {
                v25->RefCount = v26 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v25->vfptr);
              }
            }
          }
          *v24 = 0i64;
        }
      }
      Scaleform::GFx::AS3::CallFrame::SetupRegisters(
        &other,
        v5->File.pObject->Methods.Info.Data.Data[v5->File.pObject->MethodBodies.Info.Data.Data[v13]->method_info_ind],
        &_this,
        v4);
      if ( v6->HandleException )
      {
        other.ACopy = 1;
      }
      else
      {
        v27 = v6->CallStack.Size >> 6;
        if ( v27 >= v6->CallStack.NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
            (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v6->CallStack.gap0,
            v6->CallStack.Size >> 6);
        v28 = v6->CallStack.Pages;
        v29 = v6->CallStack.Size & 0x3F;
        v12 = &v28[v27][v29] == 0i64;
        v30 = &v28[v27][v29];
        v36 = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v30;
        *(_QWORD *)&v31.ID = v30;
        if ( !v12 )
          Scaleform::GFx::AS3::CallFrame::CallFrame(v30, &other);
        ++v6->CallStack.Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v12 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
      _this.value.VS._2.VObj = 0i64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
  v36 = &ptr.CallArgs;
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
void __fastcall Scaleform::GFx::AS3::VM::exec_newfunction(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::CallFrame *cf, unsigned int method_ind)
{
  unsigned int v3; // er12
  Scaleform::GFx::AS3::VM *v4; // rdi
  Scaleform::GFx::AS3::CallFrame *v5; // r10
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v6; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos; // rsi
  Scaleform::GFx::AS3::Value *v8; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v9; // rbp
  Scaleform::GFx::AS3::VMAbcFile *v10; // r15
  Scaleform::GFx::AS3::Classes::Function **v11; // r14
  Scaleform::GFx::AS3::Instances::Function *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::Instances::Function *v14; // rax
  Scaleform::GFx::AS3::Value v15; // [rsp+38h] [rbp-50h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> result; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::Function *v17; // [rsp+98h] [rbp+10h]

  v3 = method_ind;
  v4 = this;
  if ( !this->CallStack.Size )
    goto LABEL_15;
  v5 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  v6 = v5->pSavedScope;
  if ( v6->Data.Size )
  {
    gos = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v6->Data.Data->value.VS._1.VStr;
    goto LABEL_7;
  }
  v8 = v5->pRegisterFile->pRF;
  if ( (v8->Flags & 0x1F) - 12 <= 3 )
    gos = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v8->value.VS._1.VStr;
  else
LABEL_15:
    gos = 0i64;
LABEL_7:
  v9 = cf->pSavedScope;
  v10 = cf->pFile;
  v11 = (Scaleform::GFx::AS3::Classes::Function **)this->TraitsFunction.pObject->ITraits.pObject;
  if ( !v11[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::Function **))(*v11)[1]._pRCC)(v11);
  Scaleform::GFx::AS3::Classes::Function::MakeInstance(v11[17], &result, v10, v3, v9, gos);
  v15.Bonus.pWeakProxy = 0i64;
  v15.Flags = 14;
  v12 = result.pV;
  v15.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)result.pV;
  v13 = v4->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v4->OpStack.pCurrent;
  v14 = (Scaleform::GFx::AS3::Instances::Function *)v4->OpStack.pCurrent;
  result.pV = v14;
  v17 = v14;
  if ( !v13 )
  {
    LODWORD(v14->vfptr) = 14;
    v14->pRCCRaw = 0i64;
    v14->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr;
    v14->pPrev = 0i64;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
}

// File Line: 3123
// RVA: 0x8396D0
void __fastcall Scaleform::GFx::AS3::VM::exec_call(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int argc; // esi
  Scaleform::GFx::AS3::VM *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rcx
  int v5; // ecx
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Value *v10; // rcx
  Scaleform::GFx::AS3::ReadArgs *argv; // rbx
  __int64 v12; // rcx
  __int64 v13; // r8
  Scaleform::GFx::AS3::Value::VU v14; // kr00_16
  int v15; // edx
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::Value::VU v17; // [rsp+50h] [rbp-98h]
  __int64 v18; // [rsp+60h] [rbp-88h]
  unsigned int v19; // [rsp+68h] [rbp-80h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS3::Value::V2U v21; // [rsp+1A8h] [rbp+C0h]
  Scaleform::GFx::AS3::Value func; // [rsp+1B0h] [rbp+C8h]
  Scaleform::GFx::AS3::Value::Extra *v23; // [rsp+1F8h] [rbp+110h]

  v18 = -2i64;
  argc = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  LODWORD(ptr.CallArgs.Data.Size) = ptr.OpStack->pCurrent->Flags;
  ptr.CallArgs.Data.Policy.Capacity = (unsigned __int64)ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v4 = ptr.OpStack->pCurrent;
  ptr.CallArgs.Data.pHeap = (Scaleform::MemoryHeap *)ptr.OpStack->pCurrent->value.VS._1.VStr;
  v21.VObj = (Scaleform::GFx::AS3::Object *)v4->value.VS._2;
  --ptr.OpStack->pCurrent;
  v5 = ptr.CallArgs.Data.Size & 0x1F;
  if ( !(ptr.CallArgs.Data.Size & 0x1F) || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !ptr.CallArgs.Data.pHeap )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, ptr.CallArgs.Data.pHeap) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v16.Message.pNode;
    v9 = v16.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  func.Flags = ptr.OpStack->pCurrent->Flags;
  func.Bonus.pWeakProxy = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v10 = ptr.OpStack->pCurrent;
  func.value.VNumber = ptr.OpStack->pCurrent->value.VNumber;
  func.value.VS._2.VObj = v10->value.VS._2.VObj;
  --ptr.OpStack->pCurrent;
  if ( !v3->HandleException )
  {
    argv = &ptr;
    if ( v19 > 8 )
      argv = (Scaleform::GFx::AS3::ReadArgs *)ptr.FixedArr[7].Bonus.pWeakProxy;
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v16.ID = v.Flags;
    v16.Message.pNode = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
    v14 = v.value;
    v13 = *(_OWORD *)&v14 >> 64;
    v12 = (unsigned __int128)v14;
    v17 = v.value;
    v15 = v.Flags & 0x1F;
    if ( v15 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( v15 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else if ( v15 > 10 )
      {
        if ( v15 <= 15 )
        {
          if ( *(_QWORD *)&v.value.VNumber )
          {
            ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
            *(_DWORD *)(v12 + 32) &= 0x8FBFFFFF;
          }
        }
        else if ( v15 <= 17 && v.value.VS._2.VObj )
        {
          ++v.value.VS._2.VObj->RefCount;
          *(_DWORD *)(v13 + 32) &= 0x8FBFFFFF;
        }
      }
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      v3,
      &func,
      (Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size,
      (Scaleform::GFx::AS3::Value *)&v16,
      argc,
      (Scaleform::GFx::AS3::Value *)argv,
      1);
    if ( (v16.ID & 0x1F) > 9 )
    {
      if ( ((unsigned int)v16.ID >> 9) & 1 )
      {
        v9 = v16.Message.pNode->pData-- == (const char *)1;
        if ( v9 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v16.Message.pNode = 0i64;
        v17 = 0ui64;
        v16.ID &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v16);
      }
    }
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags >> 9) & 1 )
    {
      v9 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&func.Bonus, (__m128i)0i64);
      func.value.VS._2.VObj = 0i64;
      func.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
    }
  }
  if ( (ptr.CallArgs.Data.Size & 0x1F) > 9 )
  {
    if ( (LODWORD(ptr.CallArgs.Data.Size) >> 9) & 1 )
    {
      v9 = (*(_DWORD *)ptr.CallArgs.Data.Policy.Capacity)-- == 1;
      if ( v9 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&ptr.CallArgs.Data.Policy, (__m128i)0i64);
      v21.VObj = 0i64;
      LODWORD(ptr.CallArgs.Data.Size) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&ptr.CallArgs.Data.Size);
    }
  }
  v23 = &ptr.FixedArr[7].Bonus;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].Bonus.pWeakProxy,
    (unsigned __int64)ptr.FixedArr[7].value.VS._1.VStr);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].Bonus.pWeakProxy);
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3140
// RVA: 0x83A090
void __fastcall Scaleform::GFx::AS3::VM::exec_callobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int v2; // esi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // r9
  int v5; // er8
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  __int64 v10; // r8
  long double v11; // rdi
  Scaleform::GFx::AS3::Value *v12; // rbx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+30h] [rbp-168h]
  __int64 v14; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-148h]
  Scaleform::GFx::AS3::Value *v16; // [rsp+188h] [rbp-10h]

  v14 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  v4 = ptr.OpStack->pCurrent;
  v16 = v4;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    v6 = (unsigned int)(v5 - 12) > 3 && v5 != 10 || *(_QWORD *)&v4->value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v13.Message.pNode;
    v9 = v13.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v10 = (__int64)v16;
    v11 = v16->value.VNumber;
    v12 = ptr.FixedArr;
    if ( ptr.ArgNum > 8 )
      v12 = ptr.CallArgs.Data.Data;
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      v10 = (__int64)v16;
    }
    (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Value *, __int64, _QWORD, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v11 + 72i64))(
      COERCE_LONG_DOUBLE(*(_QWORD *)&v11),
      &v,
      v10,
      v2,
      v12);
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
void __fastcall Scaleform::GFx::AS3::VM::exec_callsuper(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v4; // rdi
  Scaleform::GFx::AS3::Traits *v5; // r14
  Scaleform::GFx::AS3::VMFile *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::Value::V2U *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *v16; // rbx
  __int64 v17; // rcx
  __int64 v18; // r8
  Scaleform::GFx::AS3::Value::VU v19; // kr00_16
  int v20; // edx
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::VM::Error v22; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::VU v23; // [rsp+70h] [rbp-78h]
  char ptr; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::Value *v25; // [rsp+180h] [rbp+98h]
  unsigned __int64 v26; // [rsp+188h] [rbp+A0h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1A0h] [rbp+B8h]
  Scaleform::GFx::AS3::Value _this; // [rsp+1D0h] [rbp+E8h]
  __int64 v29; // [rsp+1F8h] [rbp+110h]
  Scaleform::GFx::AS3::CheckResult result[8]; // [rsp+228h] [rbp+140h]
  unsigned int argc; // [rsp+248h] [rbp+160h]

  v29 = -2i64;
  v4 = mn;
  v5 = ot;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, file->VMRef, argc);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v4);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&v22.Message, &obj);
  _this.Flags = *(_DWORD *)v23.VS._1.VStr->pData;
  _this.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)v23.VS._1.VStr->pData + 1);
  v8 = (Scaleform::GFx::AS3::Value::V2U *)v23.VS._1.VStr->pData;
  _this.value.VNumber = *((long double *)v23.VS._1.VStr->pData + 2);
  _this.value.VS._2 = v8[3];
  v23.VS._1.VStr->pData -= 32;
  v9 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&_this.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v22,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      (Scaleform::GFx::AS3::VM *)v22.Message.pNode);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v22.Message.pNode,
      v11,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v22.Message.pNode;
    v13 = v22.Message.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( v7->HandleException )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
        _this.value.VS._2.VObj = 0i64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
    *(_QWORD *)&result[0].Result = &v25;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
  }
  else
  {
    func.Flags = 0;
    func.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::GetSuperProperty(result, v7, v5, &func, &_this, &obj)->Result )
    {
      v16 = (Scaleform::GFx::AS3::Value *)&ptr;
      if ( LODWORD(v23.VS._2.VObj) > 8 )
        v16 = v25;
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v22.ID = v.Flags;
      v22.Message.pNode = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
      v19 = v.value;
      v18 = *(_OWORD *)&v19 >> 64;
      v17 = (unsigned __int128)v19;
      v23 = v.value;
      v20 = v.Flags & 0x1F;
      if ( v20 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( v20 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        }
        else if ( v20 > 10 )
        {
          if ( v20 <= 15 )
          {
            if ( *(_QWORD *)&v.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
              *(_DWORD *)(v17 + 32) &= 0x8FBFFFFF;
            }
          }
          else if ( v20 <= 17 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            *(_DWORD *)(v18 + 32) &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        v7,
        &func,
        &_this,
        (Scaleform::GFx::AS3::Value *)&v22,
        argc,
        v16,
        1);
      if ( (v22.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v22.ID >> 9) & 1 )
        {
          v13 = v22.Message.pNode->pData-- == (const char *)1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v22.Message.pNode = 0i64;
          v23 = 0ui64;
          v22.ID &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v22);
        }
      }
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags >> 9) & 1 )
        {
          v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          func.Bonus.pWeakProxy = 0i64;
          func.value = 0ui64;
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
          _this.value.VS._2.VObj = 0i64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&result[0].Result = &v25;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v22, eCallNotFoundError, v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v14, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v15 = v22.Message.pNode;
      v13 = v22.Message.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags >> 9) & 1 )
        {
          v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          func.Bonus.pWeakProxy = 0i64;
          func.value = 0ui64;
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
          _this.value.VS._2.VObj = 0i64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&result[0].Result = &v25;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3184
// RVA: 0x83CC40
void __fastcall Scaleform::GFx::AS3::VM::exec_callsupervoid(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v4; // rdi
  Scaleform::GFx::AS3::Traits *v5; // r14
  Scaleform::GFx::AS3::VMFile *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rsi
  Scaleform::GFx::AS3::Value::V2U *v8; // rcx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Value *v16; // rbx
  __int64 v17; // rcx
  __int64 v18; // r8
  Scaleform::GFx::AS3::Value::VU v19; // kr00_16
  int v20; // edx
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::VM::Error v22; // [rsp+60h] [rbp-88h]
  Scaleform::GFx::AS3::Value::VU v23; // [rsp+70h] [rbp-78h]
  char ptr; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::Value *v25; // [rsp+180h] [rbp+98h]
  unsigned __int64 v26; // [rsp+188h] [rbp+A0h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1A0h] [rbp+B8h]
  Scaleform::GFx::AS3::Value _this; // [rsp+1D0h] [rbp+E8h]
  __int64 v29; // [rsp+1F8h] [rbp+110h]
  Scaleform::GFx::AS3::CheckResult result[8]; // [rsp+228h] [rbp+140h]
  unsigned int argc; // [rsp+248h] [rbp+160h]

  v29 = -2i64;
  v4 = mn;
  v5 = ot;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, file->VMRef, argc);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v4);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&v22.Message, &obj);
  _this.Flags = *(_DWORD *)v23.VS._1.VStr->pData;
  _this.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)v23.VS._1.VStr->pData + 1);
  v8 = (Scaleform::GFx::AS3::Value::V2U *)v23.VS._1.VStr->pData;
  _this.value.VNumber = *((long double *)v23.VS._1.VStr->pData + 2);
  _this.value.VS._2 = v8[3];
  v23.VS._1.VStr->pData -= 32;
  v9 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&_this.value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v22,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      (Scaleform::GFx::AS3::VM *)v22.Message.pNode);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)v22.Message.pNode,
      v11,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v22.Message.pNode;
    v13 = v22.Message.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( v7->HandleException )
  {
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
        _this.value.VS._2.VObj = 0i64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
    *(_QWORD *)&result[0].Result = &v25;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
  }
  else
  {
    func.Flags = 0;
    func.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::GetSuperProperty(result, v7, v5, &func, &_this, &obj)->Result )
    {
      v16 = (Scaleform::GFx::AS3::Value *)&ptr;
      if ( LODWORD(v23.VS._2.VObj) > 8 )
        v16 = v25;
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      v22.ID = v.Flags;
      v22.Message.pNode = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
      v19 = v.value;
      v18 = *(_OWORD *)&v19 >> 64;
      v17 = (unsigned __int128)v19;
      v23 = v.value;
      v20 = v.Flags & 0x1F;
      if ( v20 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          ++v.Bonus.pWeakProxy->RefCount;
        }
        else if ( v20 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        }
        else if ( v20 > 10 )
        {
          if ( v20 <= 15 )
          {
            if ( *(_QWORD *)&v.value.VNumber )
            {
              ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
              *(_DWORD *)(v17 + 32) &= 0x8FBFFFFF;
            }
          }
          else if ( v20 <= 17 && v.value.VS._2.VObj )
          {
            ++v.value.VS._2.VObj->RefCount;
            *(_DWORD *)(v18 + 32) &= 0x8FBFFFFF;
          }
        }
      }
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        v7,
        &func,
        &_this,
        (Scaleform::GFx::AS3::Value *)&v22,
        argc,
        v16,
        0);
      if ( (v22.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v22.ID >> 9) & 1 )
        {
          v13 = v22.Message.pNode->pData-- == (const char *)1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v22.Message.pNode = 0i64;
          v23 = 0ui64;
          v22.ID &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v22);
        }
      }
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags >> 9) & 1 )
        {
          v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          func.Bonus.pWeakProxy = 0i64;
          func.value = 0ui64;
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
          _this.value.VS._2.VObj = 0i64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&result[0].Result = &v25;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v22, eCallNotFoundError, v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v14, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v15 = v22.Message.pNode;
      v13 = v22.Message.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( (func.Flags & 0x1F) > 9 )
      {
        if ( (func.Flags >> 9) & 1 )
        {
          v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          func.Bonus.pWeakProxy = 0i64;
          func.value = 0ui64;
          func.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
        }
      }
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v13 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _mm_store_si128((__m128i *)&_this.Bonus, (__m128i)0i64);
          _this.value.VS._2.VObj = 0i64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&result[0].Result = &v25;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v25, v26);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3213
// RVA: 0x83D7E0
void __fastcall Scaleform::GFx::AS3::VM::exec_construct(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::MemoryHeap *v4; // rcx
  int v5; // er8
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  int v10; // ecx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // r9
  char v14; // ST20_1
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+30h] [rbp-C8h]
  __int64 v20; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-A8h]
  Scaleform::GFx::AS3::Value::V2U *retaddr; // [rsp+198h] [rbp+A0h]

  v20 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  v4 = (Scaleform::MemoryHeap *)ptr.OpStack->pCurrent;
  ptr.CallArgs.Data.pHeap = v4;
  v5 = (_QWORD)v4->vfptr & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !v4->pNext )
  {
    v6 = (unsigned int)(v5 - 12) > 3 && v5 != 10 || v4->pNext ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( v3->HandleException )
  {
    retaddr = &ptr.FixedArr[7].value.VS._2;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
      (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
      (unsigned __int64)ptr.CallArgs.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
  }
  else
  {
    v10 = (_QWORD)ptr.CallArgs.Data.pHeap->vfptr & 0x1F;
    if ( v10 && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || ptr.CallArgs.Data.pHeap->pNext) )
    {
      if ( v10 == 7 || v10 == 17 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v19, eCannotCallMethodAsConstructor, v3);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v15, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v16 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount == 1;
        --v16->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        retaddr = &ptr.FixedArr[7].value.VS._2;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
          (unsigned __int64)ptr.CallArgs.Data.Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
      }
      else if ( (unsigned int)(v10 - 12) <= 3 )
      {
        v13 = ptr.FixedArr;
        if ( ptr.ArgNum > 8 )
          v13 = (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj;
        v14 = 0;
        ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::MemoryHeap *, _QWORD, Scaleform::GFx::AS3::Value *, char))ptr.CallArgs.Data.pHeap->pNext->vfptr->Free)(
          ptr.CallArgs.Data.pHeap->pNext,
          ptr.CallArgs.Data.pHeap,
          v2,
          v13,
          v14);
        retaddr = &ptr.FixedArr[7].value.VS._2;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
          (unsigned __int64)ptr.CallArgs.Data.Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v19, eNotConstructorError, v3);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v12 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount == 1;
        --v12->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        retaddr = &ptr.FixedArr[7].value.VS._2;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
          (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
          (unsigned __int64)ptr.CallArgs.Data.Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eConvertNullToObjectError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v18 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      retaddr = &ptr.FixedArr[7].value.VS._2;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
        (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj,
        (unsigned __int64)ptr.CallArgs.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.FixedArr[7].value.VS._2.VObj);
    }
  }
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3251
// RVA: 0x83E3A0
void __fastcall Scaleform::GFx::AS3::VM::exec_constructsuper(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Traits *ot, unsigned int arg_count)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS3::Traits *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::Value *v6; // rcx
  int v7; // ecx
  char v8; // al
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Traits *v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // rax
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+30h] [rbp-C8h]
  __int64 v15; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+50h] [rbp-A8h]
  __int128 v17; // [rsp+188h] [rbp+90h]
  Scaleform::GFx::AS3::Value::V2U v18; // [rsp+198h] [rbp+A0h]
  Scaleform::GFx::AS3::Value::V2U *retaddr; // [rsp+1B8h] [rbp+C0h]

  v15 = -2i64;
  v3 = arg_count;
  v4 = ot;
  v5 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  LODWORD(ptr.CallArgs.Data.pHeap) = ptr.OpStack->pCurrent->Flags;
  *(_QWORD *)&v17 = ptr.OpStack->pCurrent->Bonus.pWeakProxy;
  v6 = ptr.OpStack->pCurrent;
  *((_QWORD *)&v17 + 1) = *(_QWORD *)&ptr.OpStack->pCurrent->value.VNumber;
  v18.VObj = (Scaleform::GFx::AS3::Object *)v6->value.VS._2;
  --ptr.OpStack->pCurrent;
  v7 = (_QWORD)ptr.CallArgs.Data.pHeap & 0x1F;
  if ( !((_QWORD)ptr.CallArgs.Data.pHeap & 0x1F) || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*((_QWORD *)&v17 + 1) )
  {
    v8 = (unsigned int)(v7 - 12) > 3 && v7 != 10 || *((_QWORD *)&v17 + 1) ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v8 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v14.Message.pNode;
    v11 = v14.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  if ( !v5->HandleException )
  {
    v12 = v4->pParent.pObject;
    if ( v12 )
    {
      v13 = ptr.FixedArr;
      if ( ptr.ArgNum > 8 )
        v13 = (Scaleform::GFx::AS3::Value *)ptr.FixedArr[7].value.VS._2.VObj;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Traits *, Scaleform::MemoryHeap **, _QWORD, Scaleform::GFx::AS3::Value *))v12->vfptr[4].ForEachChild_GC)(
        v12,
        v4,
        &ptr.CallArgs.Data.pHeap,
        v3,
        v13);
    }
  }
  if ( ((_QWORD)ptr.CallArgs.Data.pHeap & 0x1F) > 9 )
  {
    if ( (LODWORD(ptr.CallArgs.Data.pHeap) >> 9) & 1 )
    {
      v11 = (*(_DWORD *)v17)-- == 1;
      if ( v11 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&v17, (__m128i)0i64);
      v18.VObj = 0i64;
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

// File Line: 3288
// RVA: 0x83DB00
void __fastcall Scaleform::GFx::AS3::VM::exec_constructprop(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, unsigned int arg_count)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbx
  Scaleform::GFx::AS3::VMFile *v6; // rsi
  Scaleform::GFx::AS3::VM *v7; // rdi
  Scaleform::GFx::AS3::Value *v8; // rdx
  int v9; // ecx
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits **v14; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // rbx
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
  __int64 attr[2]; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value value; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AS3::Value **v30; // [rsp+80h] [rbp-68h]
  unsigned int v31; // [rsp+88h] [rbp-60h]
  char ptr; // [rsp+90h] [rbp-58h]
  Scaleform::GFx::AS3::Value *v33; // [rsp+190h] [rbp+A8h]
  unsigned __int64 v34; // [rsp+198h] [rbp+B0h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+1B0h] [rbp+C8h]
  Scaleform::GFx::AS3::Value *scope; // [rsp+1E0h] [rbp+F8h]
  __int64 v37; // [rsp+1E8h] [rbp+100h]
  Scaleform::GFx::AS3::CheckResult v38[8]; // [rsp+218h] [rbp+130h]

  v37 = -2i64;
  v4 = arg_count;
  v5 = mn;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs((Scaleform::GFx::AS3::ReadArgs *)&ptr, file->VMRef, arg_count);
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, v6, v5);
  Scaleform::GFx::AS3::StackReader::Read((Scaleform::GFx::AS3::StackReader *)&result.This.value.VS._2, &obj);
  v8 = *v30;
  scope = v8;
  v9 = v8->Flags & 0x1F;
  if ( !v9 || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&v8->value.VNumber )
  {
    if ( (unsigned int)(v9 - 12) > 3 && v9 != 10 || (v10 = 1, *(_QWORD *)&v8->value.VNumber) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
      (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)),
      (Scaleform::GFx::AS3::VM *)result.This.value.VS._2.VObj);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      (Scaleform::GFx::AS3::VM *)result.This.value.VS._2.VObj,
      v11,
      &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( v7->HandleException )
    goto LABEL_89;
  if ( (obj.Kind & 3u) <= 1 )
  {
    v14 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v7, &obj, v6->AppDomain.pObject);
    if ( v14 )
    {
      v15 = v14[25];
      if ( !v15->pConstructor.pObject )
        v15->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15->vfptr);
      v16 = &ptr;
      if ( v31 > 8 )
        v16 = (char *)v33;
      ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, char *, _BYTE))v15->pConstructor.pObject->vfptr[4].ForEachChild_GC)(
        v15->pConstructor.pObject,
        scope,
        v4,
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
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&result, v7, scope, &obj, 0);
  if ( result.This.Flags & 0x1F
    && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&result, v38, v7, &value, 0)->Result )
    {
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      if ( (result.This.Flags & 0x1F) > 9 )
      {
        if ( (result.This.Flags >> 9) & 1 )
        {
          v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          result.This.Bonus.pWeakProxy = 0i64;
          result.This.value = 0ui64;
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
    if ( value.Flags & 0x1F && ((unsigned int)(v17 - 12) > 3 && v17 != 10 || *(_QWORD *)&value.value.VNumber) )
    {
      if ( v17 == 7 || v17 == 17 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eCannotCallMethodAsConstructor,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v21, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v22 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v22->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        if ( (value.Flags & 0x1F) > 9 )
        {
          if ( (value.Flags >> 9) & 1 )
          {
            v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            value.Bonus.pWeakProxy = 0i64;
            value.value = 0ui64;
            value.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          }
        }
        Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&result);
        Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
        *(_QWORD *)&v38[0].Result = &v33;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
      }
      else if ( (unsigned int)(v17 - 12) <= 3 )
      {
        v20 = &ptr;
        if ( v31 > 8 )
          v20 = (char *)v33;
        LOBYTE(attr[0]) = 0;
        (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Value *, _QWORD, char *, __int64))value.value.VS._1.VStr->pData
         + 12))(
          *(_QWORD *)&value.value.VNumber,
          scope,
          v4,
          v20,
          attr[0]);
        if ( (value.Flags & 0x1F) > 9 )
        {
          if ( (value.Flags >> 9) & 1 )
          {
            v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            value.Bonus.pWeakProxy = 0i64;
            value.value = 0ui64;
            value.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          }
        }
        Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&result);
        Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
        *(_QWORD *)&v38[0].Result = &v33;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(
          (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
          eUndefinedVarError,
          v7);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v18, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v19 = result.This.value.VS._1.VStr;
        v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
        --v19->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        if ( (value.Flags & 0x1F) > 9 )
        {
          if ( (value.Flags >> 9) & 1 )
          {
            v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v13 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            value.Bonus.pWeakProxy = 0i64;
            value.value = 0ui64;
            value.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          }
        }
        Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&result);
        Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
        *(_QWORD *)&v38[0].Result = &v33;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus,
        eConvertNullToObjectError,
        v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v23, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v24 = result.This.value.VS._1.VStr;
      v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
      --v24->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v13 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&result);
      Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
      *(_QWORD *)&v38[0].Result = &v33;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v33, v34);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v33);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result.This.Bonus, eReadSealedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v25, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v26 = result.This.value.VS._1.VStr;
    v13 = *(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64) == 1;
    --v26->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        v13 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.This.Bonus.pWeakProxy = 0i64;
        result.This.value = 0ui64;
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
  }
LABEL_90:
  `eh vector destructor iterator(&ptr, 0x20ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 3360
// RVA: 0x83FF80
void __fastcall Scaleform::GFx::AS3::VM::exec_getdescendants(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rdx
  int v5; // ecx
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::XMLSupport *v10; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  long double v13; // rsi
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v14; // rax
  Scaleform::GFx::AS3::Value *v15; // rbx
  Scaleform::GFx::AS3::WeakProxy *v16; // rdx
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+28h] [rbp-70h]
  Scaleform::GFx::AS3::StackReader v20; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::AS3::Value *v22; // [rsp+80h] [rbp-18h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> result; // [rsp+A0h] [rbp+8h]

  v3 = this;
  v20.VMRef = file->VMRef;
  v20.OpStack = &v20.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v20, &obj);
  v4 = v20.OpStack->pCurrent;
  v22 = v4;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    v6 = (unsigned int)(v5 - 12) > 3 && v5 != 10 || *(_QWORD *)&v4->value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), v20.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v20.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v10 = v3->XMLSupport_.pObject;
    if ( v10->Enabled )
    {
      if ( (v22->Flags & 0x1F) - 12 > 3 || (v13 = v22->value.VNumber, v13 == 0.0) )
      {
        v15 = v3->OpStack.pCurrent;
        if ( (v15->Flags & 0x1F) > 9 )
        {
          if ( (v15->Flags >> 9) & 1 )
          {
            v16 = v15->Bonus.pWeakProxy;
            v9 = v16->RefCount-- == 1;
            if ( v9 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v15->Bonus.pWeakProxy = 0i64;
            v15->value.VNumber = 0.0;
            v15->value.VS._2.VObj = 0i64;
            v15->Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(v3->OpStack.pCurrent);
          }
        }
        --v3->OpStack.pCurrent;
        Scaleform::GFx::AS3::VM::Error::Error(&v19, eDescendentsError, v3);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v17, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v18 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      else
      {
        v14 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)((__int64 (__cdecl *)(Scaleform::GFx::AS3::XMLSupport *))v10->vfptr[4].~RefCountBaseGC<328>)(v10);
        Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(&result, v14);
        Scaleform::GFx::AS3::Value::Pick(v22, (Scaleform::GFx::AS3::Object *)&result.pV->vfptr);
        (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Instances::fl::XMLList *, Scaleform::GFx::AS3::Multiname *))(**(_QWORD **)&v13 + 56i64))(
          COERCE_LONG_DOUBLE(*(_QWORD *)&v13),
          result.pV,
          &obj);
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eNotImplementedError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v11, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v12 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3401
// RVA: 0x843180
void __fastcall Scaleform::GFx::AS3::VM::exec_newcatch(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v3; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::Classes::fl::Catch **v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::Catch *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::Value::V2U v10; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> result; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS3::Value *v13; // [rsp+98h] [rbp+20h]

  v3 = e;
  v4 = file;
  v5 = this;
  v6 = (Scaleform::GFx::AS3::Classes::fl::Catch **)this->TraitsCatch.pObject->ITraits.pObject;
  if ( !v6[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::Catch **))(*v6)[1]._pRCC)(v6);
  v7 = Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstance(v6[17], &result, v4, v3)->pV;
  v11.Bonus.pWeakProxy = 0i64;
  v11.Flags = 12;
  *(_QWORD *)&v11.value.VNumber = v7;
  v11.value.VS._2 = v10;
  v8 = v5->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v5->OpStack.pCurrent;
  v9 = v5->OpStack.pCurrent;
  v13 = v5->OpStack.pCurrent;
  if ( !v8 )
  {
    v9->Flags = 12;
    v9->Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v9->value.VNumber = v7;
    v9->value.VS._2 = v10;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
}

// File Line: 3412
// RVA: 0x7D3980
void __fastcall Scaleform::GFx::AS3::VM::FindProperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *mn, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // rbp
  Scaleform::GFx::AS3::Multiname *v6; // rsi
  Scaleform::GFx::AS3::PropRef *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  unsigned __int64 v9; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rax

  v5 = ss;
  v6 = mn;
  v7 = result;
  v8 = this;
  if ( this->CallStack.Size )
    v9 = this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    v9 = 0i64;
  Scaleform::GFx::AS3::FindScopeProperty(result, this, v9, &this->ScopeStack, v6);
  if ( (!(v7->This.Flags & 0x1F)
     || (_QWORD)v7->pSI & 1 && !((_QWORD)v7->pSI & 0xFFFFFFFFFFFFFFFEui64)
     || ((unsigned __int8)v7->pSI >> 1) & 1 && !((_QWORD)v7->pSI & 0xFFFFFFFFFFFFFFFDui64))
    && v5->Data.Size )
  {
    Scaleform::GFx::AS3::FindScopeProperty(v7, v8, 0i64, v5, v6);
  }
  if ( !(v7->This.Flags & 0x1F)
    || (_QWORD)v7->pSI & 1 && !((_QWORD)v7->pSI & 0xFFFFFFFFFFFFFFFEui64)
    || ((unsigned __int8)v7->pSI >> 1) & 1 && !((_QWORD)v7->pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    v10 = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(v8, v6, appDomain);
    Scaleform::GFx::AS3::FindGOProperty(v7, v8, &v8->GlobalObjects, v6, v10);
  }
}

// File Line: 3437
// RVA: 0x83F9F0
void __fastcall Scaleform::GFx::AS3::VM::exec_findpropstrict(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  Scaleform::GFx::AS3::VMFile *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::Value::VU *v8; // rcx
  int v9; // eax
  long double v10; // rax
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-49h]
  Scaleform::GFx::AS3::StackReader v14; // [rsp+48h] [rbp-19h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h]
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+88h] [rbp+27h]
  __int64 v17; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::AS3::Value::VU *v18; // [rsp+C8h] [rbp+67h]
  Scaleform::GFx::AS3::Value::VU *vars0; // [rsp+D0h] [rbp+6Fh]

  v17 = -2i64;
  v4 = ss;
  v5 = file;
  v6 = this;
  v14.VMRef = file->VMRef;
  v14.OpStack = &v14.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v14, &obj);
  if ( v6->HandleException )
    goto LABEL_35;
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::FindProperty(v6, &result, &obj, v4, v5->AppDomain.pObject);
  if ( result.This.Flags & 0x1F
    && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    v7 = v6->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++v6->OpStack.pCurrent;
    v8 = (Scaleform::GFx::AS3::Value::VU *)v6->OpStack.pCurrent;
    v18 = v8;
    vars0 = v8;
    if ( !v7 )
    {
      LODWORD(v8->VS._1.VStr) = result.This.Flags;
      v8->VS._2.VObj = (Scaleform::GFx::AS3::Object *)result.This.Bonus.pWeakProxy;
      v8[1] = result.This.value;
      v9 = result.This.Flags & 0x1F;
      if ( v9 > 9 )
      {
        if ( (result.This.Flags >> 9) & 1 )
        {
          ++result.This.Bonus.pWeakProxy->RefCount;
          goto LABEL_20;
        }
        if ( v9 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64);
        }
        else if ( v9 > 10 )
        {
          if ( v9 <= 15 )
          {
            v10 = result.This.value.VNumber;
LABEL_17:
            if ( v10 != 0.0 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v10 + 32i64);
              *(_DWORD *)(*(_QWORD *)&v10 + 32i64) &= 0x8FBFFFFF;
            }
            goto LABEL_20;
          }
          if ( v9 <= 17 )
          {
            v10 = *(double *)&result.This.value.VS._2.VObj;
            goto LABEL_17;
          }
        }
      }
    }
LABEL_20:
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v7 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        result.This.Bonus.pWeakProxy = 0i64;
        result.This.value = 0ui64;
        result.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
    goto LABEL_35;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v16, eUndefinedVarError, v6);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v11, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
  v12 = v16.Message.pNode;
  v7 = v16.Message.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags >> 9) & 1 )
    {
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.This.value = 0ui64;
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_35:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3466
// RVA: 0x83F5D0
void __fastcall Scaleform::GFx::AS3::VM::exec_findproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  Scaleform::GFx::AS3::VMFile *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  bool v7; // zf
  Scaleform::GFx::AS3::Value::VU *v8; // rcx
  int v9; // eax
  long double v10; // rax
  __int64 v11; // rdx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-61h]
  Scaleform::GFx::AS3::Value v13; // [rsp+48h] [rbp-31h]
  __int64 v14; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::AS3::StackReader v15; // [rsp+78h] [rbp-1h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+88h] [rbp+Fh]
  __int64 v17; // [rsp+D8h] [rbp+5Fh]
  __int64 vars0; // [rsp+E0h] [rbp+67h]
  long double v19; // [rsp+F8h] [rbp+7Fh]

  v14 = -2i64;
  v4 = ss;
  v5 = file;
  v6 = this;
  v15.VMRef = file->VMRef;
  v15.OpStack = &v15.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v15, &obj);
  if ( v6->HandleException )
    goto LABEL_33;
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::FindProperty(v6, &result, &obj, v4, v5->AppDomain.pObject);
  if ( !(result.This.Flags & 0x1F)
    || (_QWORD)result.pSI & 1 && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    || (LOBYTE(result.pSI) >> 1) & 1 && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    v13.Flags = 12;
    v13.Bonus.pWeakProxy = 0i64;
    v13.value.VNumber = v19;
    if ( v19 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v19 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v19 + 32i64) + 1) & 0x8FBFFFFF;
    v7 = v6->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++v6->OpStack.pCurrent;
    v11 = (__int64)v6->OpStack.pCurrent;
    v17 = v11;
    vars0 = v11;
    if ( !v7 )
    {
      *(_DWORD *)v11 = 12;
      *(_QWORD *)(v11 + 8) = 0i64;
      *(long double *)(v11 + 16) = v19;
      *(_QWORD *)(v11 + 24) = v13.value.VS._2.VObj;
      if ( v19 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v19 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v19 + 32i64) + 1) & 0x8FBFFFFF;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    goto LABEL_27;
  }
  v7 = v6->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v6->OpStack.pCurrent;
  v8 = (Scaleform::GFx::AS3::Value::VU *)v6->OpStack.pCurrent;
  v17 = (__int64)v8;
  vars0 = (__int64)v8;
  if ( !v7 )
  {
    LODWORD(v8->VS._1.VStr) = result.This.Flags;
    v8->VS._2.VObj = (Scaleform::GFx::AS3::Object *)result.This.Bonus.pWeakProxy;
    v8[1] = result.This.value;
    v9 = result.This.Flags & 0x1F;
    if ( v9 > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        ++result.This.Bonus.pWeakProxy->RefCount;
        goto LABEL_27;
      }
      if ( v9 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&result.This.value.VNumber + 24i64);
      }
      else if ( v9 > 10 )
      {
        if ( v9 <= 15 )
        {
          v10 = result.This.value.VNumber;
LABEL_17:
          if ( v10 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v10 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v10 + 32i64) &= 0x8FBFFFFF;
          }
          goto LABEL_27;
        }
        if ( v9 <= 17 )
        {
          v10 = *(double *)&result.This.value.VS._2.VObj;
          goto LABEL_17;
        }
      }
    }
  }
LABEL_27:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags >> 9) & 1 )
    {
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.This.value = 0ui64;
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_33:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}:AS3::Value::ReleaseInte

// File Line: 3504
// RVA: 0x840510
void __fastcall Scaleform::GFx::AS3::VM::exec_getlex(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  Scaleform::GFx::AS3::VMFile *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Multiname *v10; // rax
  Scaleform::GFx::AS3::Value *v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::AS3::Multiname v15; // [rsp+48h] [rbp-9h]
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+78h] [rbp+27h]
  __int64 v17; // [rsp+88h] [rbp+37h]
  void *retaddr; // [rsp+C8h] [rbp+77h]

  v17 = -2i64;
  v4 = ss;
  v5 = file;
  v6 = this;
  if ( (mn->Kind & 3) != 1 || ((unsigned int)mn->Kind >> 2) & 1 )
  {
    result.SlotIndex = 0i64;
    result.This.Flags = 0;
    result.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::Multiname::Multiname(&v15, file, mn);
    Scaleform::GFx::AS3::VM::FindProperty(v6, &result, v10, v4, v5->AppDomain.pObject);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v15);
    if ( result.This.Flags & 0x1F
      && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
    {
      v15.Kind = 0;
      v15.Obj.pObject = 0i64;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
             &result,
             (Scaleform::GFx::AS3::CheckResult *)&retaddr,
             v6,
             (Scaleform::GFx::AS3::Value *)&v15,
             0)->Result )
      {
        v9 = v6->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        ++v6->OpStack.pCurrent;
        v11 = v6->OpStack.pCurrent;
        *(_QWORD *)&v16.ID = v6->OpStack.pCurrent;
        if ( !v9 )
        {
          v11->Flags = v15.Kind;
          v11->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v15.Obj.pObject;
          v11->value.VNumber = *(long double *)&v15.Name.Flags;
          v11->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15.Name.Bonus.pWeakProxy;
          v15.Kind = 0;
        }
        if ( (v15.Kind & 0x1F) > 9 )
        {
          if ( ((unsigned int)v15.Kind >> 9) & 1 )
          {
            v9 = v15.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
            if ( v9 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v15.Obj.pObject = 0i64;
            *(_QWORD *)&v15.Name.Flags = 0i64;
            v15.Name.Bonus.pWeakProxy = 0i64;
            v15.Kind &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v15);
          }
        }
      }
      else if ( (v15.Kind & 0x1F) > 9 )
      {
        if ( ((unsigned int)v15.Kind >> 9) & 1 )
        {
          v9 = v15.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
          if ( v9 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v15.Obj.pObject = 0i64;
          *(_QWORD *)&v15.Name.Flags = 0i64;
          v15.Name.Bonus.pWeakProxy = 0i64;
          v15.Kind &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v15);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eReadSealedError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v13 = v16.Message.pNode;
      v9 = v16.Message.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    if ( (result.This.Flags & 0x1F) > 9 )
    {
      if ( (result.This.Flags >> 9) & 1 )
      {
        v9 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        result.This.Flags &= 0xFFFFFDE0;
        result.This.Bonus.pWeakProxy = 0i64;
        result.This.value = 0ui64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v16.Message.pNode;
    v9 = v16.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}

// File Line: 3575
// RVA: 0x840A80
void __fastcall Scaleform::GFx::AS3::VM::exec_getproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // r14
  Scaleform::GFx::AS3::Value *v4; // rdx
  int v5; // ecx
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  unsigned int v10; // edi
  Scaleform::GFx::AS3::WeakProxy *v11; // rbx
  int v12; // esi
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value _this; // [rsp+18h] [rbp-49h]
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+38h] [rbp-29h]
  Scaleform::GFx::AS3::StackReader v17; // [rsp+48h] [rbp-19h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h]
  Scaleform::GFx::AS3::Value *value; // [rsp+88h] [rbp+27h]
  __int64 v20; // [rsp+98h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+67h]

  v20 = -2i64;
  v3 = this;
  v17.VMRef = file->VMRef;
  v17.OpStack = &v17.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v17, &obj);
  v4 = v17.OpStack->pCurrent;
  value = v4;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, *(_QWORD *)&v4->value.VNumber) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), v17.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v17.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v16.Message.pNode;
    v9 = v16.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v10 = value->Flags;
    _this.Flags = value->Flags;
    v11 = value->Bonus.pWeakProxy;
    _this.Bonus.pWeakProxy = value->Bonus.pWeakProxy;
    _this.value = value->value;
    value->Flags = 0;
    if ( Scaleform::GFx::AS3::GetPropertyUnsafe(&result, v3, &_this, &obj, value)->Result )
      goto LABEL_40;
    if ( v3->HandleException )
    {
      if ( (char)(v10 & 0x1F) > 9 )
      {
        if ( (v10 >> 9) & 1 )
        {
          v9 = v11->RefCount-- == 1;
          if ( v9 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags = v10 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      goto LABEL_37;
    }
    v12 = v10 & 0x1F;
    if ( v12 > 4 && v12 != 10 )
    {
LABEL_40:
      if ( (char)(v10 & 0x1F) > 9 )
      {
        if ( (v10 >> 9) & 1 )
        {
          v9 = v11->RefCount-- == 1;
          if ( v9 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags = v10 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eReadSealedError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v14 = v16.Message.pNode;
      v9 = v16.Message.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v12 > 9 )
      {
        if ( (v10 >> 9) & 1 )
        {
          v9 = v11->RefCount-- == 1;
          if ( v9 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags = v10 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
  }
LABEL_37:
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3606
// RVA: 0x842700
void __fastcall Scaleform::GFx::AS3::VM::exec_initproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::StackReader v9; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-39h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS3::Value _this; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+B0h] [rbp+37h]
  __int64 v14; // [rsp+C0h] [rbp+47h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS3::VM *v16; // [rsp+E8h] [rbp+6Fh]

  v14 = -2i64;
  v3 = this;
  v9.VMRef = file->VMRef;
  v9.OpStack = &v9.VMRef->OpStack;
  value.Flags = v9.VMRef->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = v9.VMRef->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = v9.VMRef->OpStack.pCurrent->value;
  --v9.OpStack->pCurrent;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v9, &obj);
  _this.Flags = v9.OpStack->pCurrent->Flags;
  _this.Bonus.pWeakProxy = v9.OpStack->pCurrent->Bonus.pWeakProxy;
  _this.value = v9.OpStack->pCurrent->value;
  --v9.OpStack->pCurrent;
  v4 = _this.Flags & 0x1F;
  if ( !(_this.Flags & 0x1F) || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&_this.value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&_this.value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), v9.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( !v3->HandleException )
  {
    v16 = v3;
    ++v3->InInitializer;
    Scaleform::GFx::AS3::SetProperty(&result, v3, &_this, &obj, &value);
    --v3->InInitializer;
  }
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v8 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&_this.value, (__m128i)0i64);
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
    if ( (value.Flags >> 9) & 1 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&value.value, (__m128i)0i64);
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
void __fastcall Scaleform::GFx::AS3::VM::exec_deleteproperty(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rdx
  int v5; // ecx
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char v10; // r10
  __int64 v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Value *v14; // rcx
  signed int v15; // eax
  long double v16; // r9
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+28h] [rbp-11h]
  Scaleform::GFx::AS3::StackReader v20; // [rsp+40h] [rbp+7h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+50h] [rbp+17h]
  Scaleform::GFx::AS3::Value *v22; // [rsp+80h] [rbp+47h]
  char v23; // [rsp+A0h] [rbp+67h]

  v3 = this;
  v20.VMRef = file->VMRef;
  v20.OpStack = &v20.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&v20, &obj);
  v4 = v20.OpStack->pCurrent;
  v22 = v4;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    v6 = (unsigned int)(v5 - 12) > 3 && v5 != 10 || *(_QWORD *)&v4->value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v19, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), v20.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v20.VMRef, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v19.Message.pNode;
    v9 = v19.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v10 = 0;
    if ( v3->XMLSupport_.pObject->Enabled
      && (obj.Name.Flags & 0x1F) - 12 <= 3
      && *(_QWORD *)&obj.Name.value.VNumber
      && (v11 = *(_QWORD *)(*(_QWORD *)&obj.Name.value.VNumber + 40i64), *(_DWORD *)(v11 + 120) == 19)
      && ~(*(_BYTE *)(v11 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eDeleteTypeError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v13 = v19.Message.pNode;
      v9 = v19.Message.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    else
    {
      v14 = v22;
      v15 = v22->Flags & 0x1F;
      if ( v15 <= 4 || v15 == 10 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v19, eDeleteSealedError, v3);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v17, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v18 = v19.Message.pNode;
        v9 = v19.Message.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      else
      {
        if ( (unsigned int)(v15 - 12) > 3 )
          goto LABEL_33;
        v16 = v22->value.VNumber;
        if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)&v16 + 40i64) + 112i64) >> 1) & 1 )
        {
          v10 = *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD, char *, Scaleform::GFx::AS3::Multiname *))(**(_QWORD **)&v16 + 64i64))(
                            *(_QWORD *)&v22->value.VNumber,
                            &v23,
                            &obj);
          v14 = v22;
        }
        if ( !v3->HandleException )
LABEL_33:
          Scaleform::GFx::AS3::Value::SetBool(v14, v10);
      }
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 3674
// RVA: 0x841280
void __fastcall Scaleform::GFx::AS3::VM::exec_getslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  unsigned int v2; // ebp
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rsi
  int v5; // er8
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::ErrorID v10; // edi
  Scaleform::GFx::AS3::WeakProxy *v11; // rbx
  Scaleform::GFx::AS3::Object *v12; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::Object *v14; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS3::Value::V2U v15; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+70h] [rbp+8h]

  v2 = slot_index;
  v3 = this;
  v4 = this->OpStack.pCurrent;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, *(_QWORD *)&v4->value.VNumber) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v13.Message.pNode;
    v9 = v13.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v13.ID = v4->Flags;
    v10 = v13.ID;
    v11 = v4->Bonus.pWeakProxy;
    v13.Message.pNode = (Scaleform::GFx::ASStringNode *)v4->Bonus.pWeakProxy;
    v14 = v4->value.VS._1.VObj;
    v12 = v14;
    v15.VObj = (Scaleform::GFx::AS3::Object *)v4->value.VS._2;
    v4->Flags = 0;
    Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(v12, &result, (Scaleform::GFx::AS3::SlotIndex)v2, v4);
    if ( (v10 & 0x1F) > 9 )
    {
      if ( ((unsigned int)v10 >> 9) & 1 )
      {
        v9 = v11->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        v13.Message.pNode = 0i64;
        v14 = 0i64;
        v15.VObj = 0i64;
        v13.ID = v10 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v13);
      }
    }
  }
}

// File Line: 3689
// RVA: 0x846410
void __fastcall Scaleform::GFx::AS3::VM::exec_setabsslot(Scaleform::GFx::AS3::VM *this, unsigned __int64 slot_ind)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+30h] [rbp-11h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+48h] [rbp+7h]
  unsigned int **v13; // [rsp+50h] [rbp+Fh]
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp+17h]
  Scaleform::GFx::AS3::Value v15; // [rsp+78h] [rbp+37h]
  void *retaddr; // [rsp+A8h] [rbp+67h]

  v2 = slot_ind;
  v3 = this;
  vm = this;
  v13 = (unsigned int **)&this->OpStack;
  v.Flags = this->OpStack.pCurrent->Flags;
  v.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  v.value = this->OpStack.pCurrent->value;
  *v13 -= 8;
  v15.Flags = **v13;
  v15.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*v13 + 1);
  v15.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*v13 + 1);
  *v13 -= 8;
  v4 = v15.Flags & 0x1F;
  if ( !(v15.Flags & 0x1F) || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&v15.value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&v15.value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v11, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v11.Message.pNode;
    v8 = v11.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( !v3->HandleException )
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v15.value.VNumber + 40i64),
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      (Scaleform::GFx::AS3::AbsoluteIndex)(v2 - 1),
      &v);
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags >> 9) & 1 )
    {
      v9 = v15.Bonus.pWeakProxy;
      v8 = v15.Bonus.pWeakProxy->RefCount == 1;
      --v9->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v9);
      v15.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&v15.value, (__m128i)0i64);
      v15.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v10 = v.Bonus.pWeakProxy;
      v8 = v.Bonus.pWeakProxy->RefCount == 1;
      --v10->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v10);
      v.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&v.value, (__m128i)0i64);
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
  unsigned __int64 v2; // rdi
  Scaleform::GFx::AS3::VM *v3; // rbx
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  long double v9; // rcx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  Scaleform::GFx::AS3::WeakProxy *v11; // rdx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-11h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+48h] [rbp+7h]
  unsigned int **v14; // [rsp+50h] [rbp+Fh]
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp+17h]
  Scaleform::GFx::AS3::Value v16; // [rsp+78h] [rbp+37h]
  void *retaddr; // [rsp+A8h] [rbp+67h]

  v2 = slot_ind;
  v3 = this;
  vm = this;
  v14 = (unsigned int **)&this->OpStack;
  v.Flags = this->OpStack.pCurrent->Flags;
  v.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  v.value = this->OpStack.pCurrent->value;
  *v14 -= 8;
  v16.Flags = **v14;
  v16.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*v14 + 1);
  v16.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*v14 + 1);
  *v14 -= 8;
  v4 = v16.Flags & 0x1F;
  if ( !(v16.Flags & 0x1F) || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&v16.value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&v16.value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v12.Message.pNode;
    v8 = v12.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( !v3->HandleException )
  {
    v9 = v16.value.VNumber;
    ++v3->InInitializer;
    Scaleform::GFx::AS3::Traits::SetSlotValue(
      *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v9 + 40i64),
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      (Scaleform::GFx::AS3::AbsoluteIndex)(v2 - 1),
      &v);
    --v3->InInitializer;
  }
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags >> 9) & 1 )
    {
      v10 = v16.Bonus.pWeakProxy;
      v8 = v16.Bonus.pWeakProxy->RefCount == 1;
      --v10->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v10);
      v16.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&v16.value, (__m128i)0i64);
      v16.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
    }
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v11 = v.Bonus.pWeakProxy;
      v8 = v.Bonus.pWeakProxy->RefCount == 1;
      --v11->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v11);
      v.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&v.value, (__m128i)0i64);
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
void __fastcall Scaleform::GFx::AS3::VM::exec_setslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::VM *v3; // rbx
  int v4; // ecx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+38h] [rbp+7h]
  unsigned int **v11; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp+17h]
  Scaleform::GFx::AS3::Value v13; // [rsp+68h] [rbp+37h]
  void *retaddr; // [rsp+98h] [rbp+67h]

  v2 = slot_index;
  v3 = this;
  vm = this;
  v11 = (unsigned int **)&this->OpStack;
  value.Flags = this->OpStack.pCurrent->Flags;
  value.Bonus.pWeakProxy = this->OpStack.pCurrent->Bonus.pWeakProxy;
  value.value = this->OpStack.pCurrent->value;
  *v11 -= 8;
  v13.Flags = **v11;
  v13.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)*((_QWORD *)*v11 + 1);
  v13.value = (Scaleform::GFx::AS3::Value::VU)*((_OWORD *)*v11 + 1);
  *v11 -= 8;
  v4 = v13.Flags & 0x1F;
  if ( !(v13.Flags & 0x1F) || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&v13.value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&v13.value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v9.Message.pNode;
    v8 = v9.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( !v3->HandleException )
    Scaleform::GFx::AS3::Object::SetSlotValue(
      v13.value.VS._1.VObj,
      (Scaleform::GFx::AS3::CheckResult *)&retaddr,
      (Scaleform::GFx::AS3::SlotIndex)v2,
      &value);
  if ( (v13.Flags & 0x1F) > 9 )
  {
    if ( (v13.Flags >> 9) & 1 )
    {
      v8 = v13.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v13.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&v13.value, (__m128i)0i64);
      v13.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    }
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v8 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&value.value, (__m128i)0i64);
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
void __fastcall Scaleform::GFx::AS3::VM::exec_coerce(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v6; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h]

  v3 = this;
  if ( (mn->Kind & 3) != 1 || ((unsigned int)mn->Kind >> 2) & 1 )
  {
    v5 = this->OpStack.pCurrent;
    v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v6 )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::ClassClass *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v6->vfptr[3].Finalize_GC)(
             v6,
             v5,
             v5) )
      {
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eReadSealedError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v4, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  v9 = v11.Message.pNode;
  v10 = v11.Message.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 3793
// RVA: 0x843B70
void __fastcall Scaleform::GFx::AS3::VM::exec_newobject(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::VM *v3; // r13
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // r14
  __int64 v5; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rcx
  Scaleform::GFx::AS3::Value *v8; // rax
  unsigned int v9; // edi
  Scaleform::GFx::AS3::WeakProxy *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // r15
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  int v17; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v19; // rcx
  unsigned int v20; // eax
  int v21; // eax
  Scaleform::GFx::AS3::WeakProxy *v22; // rdx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // rcx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::Value *v26; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v27; // rax
  unsigned int v28; // eax
  int v29; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::ASStringNode *v30; // [rsp+30h] [rbp-39h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-31h]
  unsigned int v32; // [rsp+48h] [rbp-21h]
  Scaleform::GFx::AS3::WeakProxy *v33; // [rsp+50h] [rbp-19h]
  Scaleform::GFx::ASStringNode *v34; // [rsp+58h] [rbp-11h]
  Scaleform::GFx::AS3::Object *v35; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::AS3::Value v36; // [rsp+68h] [rbp-1h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::ASString v38; // [rsp+E0h] [rbp+77h]

  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->TraitsObject.pObject->ITraits.pObject);
  v4 = result.pV;
  if ( v2 )
  {
    key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v29;
    key.pSecond = (Scaleform::GFx::AS3::Value *)&v32;
    v5 = v2;
    v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&result.pV->DynAttrs.mHash.pTable;
    do
    {
      v7 = v3->OpStack.pCurrent;
      v32 = v7->Flags;
      v33 = v7->Bonus.pWeakProxy;
      v34 = v7->value.VS._1.VStr;
      v35 = v7->value.VS._2.VObj;
      v3->OpStack.pCurrent = v7 - 1;
      v8 = v3->OpStack.pCurrent;
      v9 = v8->Flags;
      v36.Flags = v8->Flags;
      v10 = v8->Bonus.pWeakProxy;
      v36.Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
      v11 = v8->value.VS._1.VStr;
      v36.value.VNumber = v8->value.VNumber;
      v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->value.VS._2.VObj->vfptr;
      v36.value.VS._2.VObj = v8->value.VS._2.VObj;
      v3->OpStack.pCurrent = v8 - 1;
      v13 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v36, &v38);
      v29 = 0;
      v30 = v13->pNode;
      ++v30->RefCount;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
        v6,
        v6,
        &key);
      v14 = v30;
      v15 = v30->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v16 = v38.pNode;
      v15 = v38.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v17 = v9 & 0x1F;
      if ( v17 > 9 )
      {
        if ( (v9 >> 9) & 1 )
        {
          v15 = v10->RefCount-- == 1;
          if ( v15 )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
          v36.Bonus.pWeakProxy = 0i64;
          v36.value = 0ui64;
          v36.Flags = v9 & 0xFFFFFDE0;
        }
        else
        {
          switch ( v17 )
          {
            case 10:
              v15 = v11->RefCount-- == 1;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v11);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              if ( v36.value.VS._1.VBool )
              {
                *(_QWORD *)&v36.value.VNumber = (char *)v11 - 1;
              }
              else if ( v11 )
              {
                v18 = v11->Size;
                if ( v18 & 0x3FFFFF )
                {
                  v11->Size = v18 - 1;
                  v19 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11;
                  goto LABEL_25;
                }
              }
              break;
            case 16:
            case 17:
              if ( (_QWORD)v36.value.VS._2.VObj & 1 )
              {
                v36.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v12[-1].RefCount + 7);
              }
              else if ( v12 )
              {
                v20 = v12->RefCount;
                if ( v20 & 0x3FFFFF )
                {
                  v12->RefCount = v20 - 1;
                  v19 = v12;
LABEL_25:
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
                }
              }
              break;
            default:
              break;
          }
        }
      }
      v21 = v32 & 0x1F;
      if ( v21 > 9 )
      {
        if ( (v32 >> 9) & 1 )
        {
          v22 = v33;
          v15 = v33->RefCount == 1;
          --v22->RefCount;
          if ( v15 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
              Scaleform::Memory::pGlobalHeap,
              v22,
              5368709120i64);
          v33 = 0i64;
          v34 = 0i64;
          v35 = 0i64;
          v32 &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v21 )
          {
            case 10:
              v23 = v34;
              v15 = v34->RefCount == 1;
              --v23->RefCount;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v23);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v34;
              if ( !((unsigned __int8)v34 & 1) )
                goto LABEL_38;
              v34 = (Scaleform::GFx::ASStringNode *)((char *)v34 - 1);
              break;
            case 16:
            case 17:
              v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v35->vfptr;
              if ( (unsigned __int8)v35 & 1 )
              {
                v35 = (Scaleform::GFx::AS3::Object *)((char *)v35 - 1);
              }
              else
              {
LABEL_38:
                if ( v24 )
                {
                  v25 = v24->RefCount;
                  if ( v25 & 0x3FFFFF )
                  {
                    v24->RefCount = v25 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
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
    v4 = result.pV;
  }
  v36.Bonus.pWeakProxy = 0i64;
  v36.Flags = 12;
  *(_QWORD *)&v36.value.VNumber = v4;
  v26 = key.pSecond;
  v36.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
  v15 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v3->OpStack.pCurrent;
  v27 = (Scaleform::GFx::AS3::Instances::fl::Object *)v3->OpStack.pCurrent;
  result.pV = v27;
  v38.pNode = (Scaleform::GFx::ASStringNode *)v27;
  if ( !v15 )
  {
    LODWORD(v27->vfptr) = 12;
    v27->pRCCRaw = 0i64;
    v27->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr;
    v27->pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v26;
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( (unsigned __int8)v4 & 1 )
  {
    *(_QWORD *)&v36.value.VNumber = (char *)v4 - 1;
  }
  else if ( v4 )
  {
    v28 = v4->RefCount;
    if ( v28 & 0x3FFFFF )
    {
      v4->RefCount = v28 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
    }
  }
}

// File Line: 3812
// RVA: 0x843460
void __fastcall Scaleform::GFx::AS3::VM::exec_newclass(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMAbcFile *file, unsigned int v)
{
  Scaleform::GFx::AS3::VMAbcFile *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // r14
  Scaleform::GFx::AS3::Abc::File *v5; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // r12
  int v8; // er8
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Abc::Multiname *v13; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // rsi
  Scaleform::GFx::ASStringNode *v15; // rcx
  unsigned int v16; // edi
  Scaleform::GFx::ASStringNode *v17; // rbx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v19; // r15
  int v20; // esi
  const char *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  bool v25; // bl
  Scaleform::GFx::AS3::VM::Error *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::ClassTraits::UserDefined *v28; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v29; // rbx
  Scaleform::GFx::AS3::Class **v30; // rax
  Scaleform::GFx::AS3::VM::Error v31; // [rsp+28h] [rbp-41h]
  Scaleform::GFx::ASStringNode *v32; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::ASStringNode *v33; // [rsp+40h] [rbp-29h]
  Scaleform::GFx::AS3::Multiname v34; // [rsp+48h] [rbp-21h]
  Scaleform::GFx::ASString v35; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+6Fh]
  char v37; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::ASString v38; // [rsp+E8h] [rbp+7Fh]

  v3 = file;
  v4 = this;
  v5 = file->File.pObject;
  v6 = v5->AS3_Classes.Info.Data.Data[v];
  v7 = v4->OpStack.pCurrent;
  v8 = v7->Flags & 0x1F;
  if ( v8 && ((unsigned int)(v8 - 12) > 3 && v8 != 10 || *(_QWORD *)&v7->value.VNumber) )
  {
    if ( v8 != 13 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eConvertNullToObjectError, v4);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_9:
      v11 = v31.Message.pNode;
LABEL_10:
      v12 = v11->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      return;
    }
  }
  else if ( v6->inst_info.super_name_ind )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v31, eConvertNullToObjectError, v4);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    goto LABEL_9;
  }
  v13 = &v5->Const_Pool.const_multiname.Data.Data[v6->inst_info.name_ind];
  v14 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&file->vfptr, v13->Ind);
  v15 = v14->Uri.pNode;
  if ( v15->Size >= 0xD && !strncmp(v15->pData, "scaleform.gfx", 0xDui64) )
  {
    Scaleform::GFx::AS3::VMFile::GetInternedString((Scaleform::GFx::AS3::VMFile *)&v3->vfptr, &result, v13->NameIndex);
    v16 = 10;
    v31.ID = 10;
    v31.Message.pNode = 0i64;
    v17 = result.pNode;
    v32 = result.pNode;
    if ( result.pNode == &result.pNode->pManager->NullStringNode )
    {
      v17 = 0i64;
      v32 = 0i64;
      v18 = v31.Message.pNode;
      v33 = v31.Message.pNode;
      v16 = 12;
      v31.ID = 12;
    }
    else
    {
      ++result.pNode->RefCount;
      v18 = v33;
    }
    v19 = v4->GlobalObject.pObject;
    v34.Kind = 0;
    v34.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v14->vfptr;
    if ( v14 )
      v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
    v34.Name.Flags = 0;
    v34.Name.Bonus.pWeakProxy = 0i64;
    v20 = v16 & 0x1F;
    if ( (unsigned int)(v20 - 12) <= 3
      && v17
      && (v21 = v17[1].pData, *((_DWORD *)v21 + 30) == 17)
      && ~((const unsigned __int8)v21[112] >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v34.Name, (Scaleform::GFx::ASString *)&v17[1].16);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v34.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v17[1].RefCount);
      v34.Kind &= 0xFFFFFFF9;
    }
    else
    {
      __asm { prefetcht1 byte ptr [rbp+57h+var_98.ID]; Prefetch to all cache levels }
      *(_QWORD *)&v34.Name.Flags = *(_QWORD *)&v31.ID;
      v34.Name.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v34.Name.value.VNumber = v17;
      v34.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18;
      if ( v20 > 9 )
      {
        if ( (v16 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] + 1;
        }
        else if ( v20 == 10 )
        {
          ++v17->RefCount;
        }
        else if ( v20 > 10 )
        {
          if ( v20 <= 15 )
          {
            if ( v17 )
              v17->Size = (v17->Size + 1) & 0x8FBFFFFF;
          }
          else if ( v20 <= 17 && v18 )
          {
            v18->Size = (v18->Size + 1) & 0x8FBFFFFF;
          }
        }
      }
      if ( (v34.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v34.Name, &v35);
        if ( v35.pNode->Size )
        {
          if ( *v35.pNode->pData == 64 )
          {
            v34.Kind |= 8u;
            v22 = Scaleform::GFx::ASString::Substring(&v35, &v38, 1, v35.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v34.Name, v22);
            v23 = v38.pNode;
            v12 = v38.pNode->RefCount == 1;
            --v23->RefCount;
            if ( v12 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          }
        }
        v24 = v35.pNode;
        v12 = v35.pNode->RefCount == 1;
        --v24->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      }
    }
    v25 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, signed __int64))v19->vfptr[1].~RefCountBaseGC<328>)(
                      v19,
                      &v37,
                      &v34,
                      v7,
                      -2i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v34);
    if ( v20 > 9 )
    {
      if ( (v16 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        v31.Message.pNode = 0i64;
        v32 = 0i64;
        v33 = 0i64;
        v31.ID = v16 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v31);
      }
    }
    if ( v25 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eReadSealedError, v4);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v26, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v27 = v31.Message.pNode;
      v12 = v31.Message.pNode->RefCount == 1;
      --v27->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    }
    v11 = result.pNode;
    goto LABEL_10;
  }
  v28 = (Scaleform::GFx::AS3::ClassTraits::UserDefined *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
                                                           v4,
                                                           (Scaleform::GFx::AS3::VMFile *)&v3->vfptr,
                                                           v6);
  v29 = v28->ITraits.pObject;
  if ( v29->pConstructor.pObject )
  {
    Scaleform::GFx::AS3::Value::Assign(v7, v29->pConstructor.pObject);
  }
  else
  {
    v30 = (Scaleform::GFx::AS3::Class **)Scaleform::GFx::AS3::ClassTraits::UserDefined::MakeClass(
                                           v28,
                                           (Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *)&v35);
    Scaleform::GFx::AS3::Value::Pick(v7, *v30);
  }
}                                       v28,
                                           (Scaleform::Pickable<Scaleform::GFx::AS3::Classes::UserDefined> *)&v35);
   

// File Line: 3874
// RVA: 0x8391F0
void __fastcall Scaleform::GFx::AS3::VM::exec_astype(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v6; // rsi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h]

  v3 = this;
  if ( (mn->Kind & 3) != 1 || ((unsigned int)mn->Kind >> 2) & 1 )
  {
    v5 = this->OpStack.pCurrent;
    v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v6 && v6 != (Scaleform::GFx::AS3::ClassTraits::ClassClass *)Scaleform::GFx::AS3::VM::GetClassTraits(v3, v5) )
    {
      Scaleform::GFx::AS3::Value::SetNull(v5);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eClassNotFoundError, v3);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v4, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  v8 = v10.Message.pNode;
  v9 = v10.Message.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 3910
// RVA: 0x842900
void __fastcall Scaleform::GFx::AS3::VM::exec_instanceof(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rbp
  Scaleform::GFx::AS3::Value *v2; // rdx
  unsigned int v3; // esi
  Scaleform::GFx::AS3::WeakProxy *v4; // rbx
  int v5; // er13
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // r15
  int v10; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rdi
  Scaleform::GFx::AS3::Traits *v12; // rax
  Scaleform::GFx::AS3::Traits *v13; // r14
  bool v14; // dl
  Scaleform::GFx::AS3::Object *i; // rbp
  __int64 v16; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-40h]

  v1 = this;
  v2 = this->OpStack.pCurrent;
  v.Flags = v2->Flags;
  v3 = v.Flags;
  v4 = v2->Bonus.pWeakProxy;
  v.Bonus.pWeakProxy = v2->Bonus.pWeakProxy;
  v.value = v2->value;
  this->OpStack.pCurrent = v2 - 1;
  v5 = v3 & 0x1F;
  if ( (unsigned int)(v5 - 13) <= 1 )
  {
    v9 = this->OpStack.pCurrent;
    v10 = v9->Flags & 0x1F;
    if ( v10 && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || *(_QWORD *)&v9->value.VNumber) )
    {
      v11 = Scaleform::GFx::AS3::VM::GetClassTraits(v1, v9);
      v12 = Scaleform::GFx::AS3::VM::GetValueTraits(v1, &v);
      v13 = v12;
      if ( v5 == 13 )
      {
        if ( v11 )
        {
          while ( v11 != (Scaleform::GFx::AS3::ClassTraits::Traits *)v12 )
          {
            v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject;
            if ( !v11 )
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
        if ( !v12->pConstructor.pObject )
          v12->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
        for ( i = (Scaleform::GFx::AS3::Object *)&v13->pConstructor.pObject->vfptr;
              v11;
              v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject )
        {
          if ( !v11->pConstructor.pObject )
            v11->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
          if ( Scaleform::GFx::AS3::Class::GetPrototype(v11->pConstructor.pObject) == i )
            goto LABEL_13;
        }
      }
    }
LABEL_21:
    v14 = 0;
    goto LABEL_22;
  }
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&v16,
    eCantUseInstanceofOnNonObjectError,
    this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v7 = v17;
  v8 = v17->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
LABEL_23:
  if ( v5 > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v8 = v4->RefCount-- == 1;
      if ( v8 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      v.Flags = v3 & 0xFFFFFDE0;
      v.value = 0ui64;
      v.Bonus.pWeakProxy = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 3962
// RVA: 0x842B30
void __fastcall Scaleform::GFx::AS3::VM::exec_istype(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  char v10; // al
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h]

  v3 = this;
  if ( (mn->Kind & 3) != 1 || ((unsigned int)mn->Kind >> 2) & 1 )
  {
    v7 = this->OpStack.pCurrent;
    v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, file, mn);
    if ( v8 )
    {
      v10 = Scaleform::GFx::AS3::VM::IsOfType(v3, v7, (Scaleform::GFx::AS3::ClassTraits::Traits *)&v8->vfptr);
      Scaleform::GFx::AS3::Value::SetBool(v7, v10);
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eClassNotFoundError, v3);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v4, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  v5 = v11.Message.pNode;
  v6 = v11.Message.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 4039
// RVA: 0x8392C0
void __fastcall Scaleform::GFx::AS3::VM::exec_astypelate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // r15
  Scaleform::GFx::AS3::Value *v2; // rdx
  unsigned int v3; // edi
  Scaleform::GFx::AS3::WeakProxy *v4; // rbx
  long double v5; // r8
  int v6; // er14
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  char v10; // al
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::Value *v13; // rsi
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::Value v15; // [rsp+38h] [rbp-28h]

  v1 = this;
  v2 = this->OpStack.pCurrent;
  v15.Flags = v2->Flags;
  v3 = v15.Flags;
  v4 = v2->Bonus.pWeakProxy;
  v15.Bonus.pWeakProxy = v2->Bonus.pWeakProxy;
  v5 = v2->value.VNumber;
  v15.value = v2->value;
  this->OpStack.pCurrent = v2 - 1;
  v6 = v3 & 0x1F;
  if ( v6 == 13 )
  {
    v13 = this->OpStack.pCurrent;
    if ( !Scaleform::GFx::AS3::VM::IsOfType(
            this,
            this->OpStack.pCurrent,
            *(Scaleform::GFx::AS3::ClassTraits::Traits **)(*(_QWORD *)&v5 + 40i64)) )
      Scaleform::GFx::AS3::Value::SetNull(v13);
LABEL_22:
    if ( (v3 >> 9) & 1 )
    {
      v9 = v4->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
LABEL_25:
      v15.Flags = v3 & 0xFFFFFDE0;
      v15.Bonus.pWeakProxy = 0i64;
      v15.value = 0ui64;
      return;
    }
LABEL_26:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    return;
  }
  if ( v3 & 0x1F && ((unsigned int)(v6 - 12) > 3 && v6 != 10 || v5 != 0.0) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eIsTypeMustBeClassError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v14.Message.pNode;
    v9 = v14.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v6 > 9 )
      goto LABEL_22;
  }
  else
  {
    if ( (unsigned int)(v6 - 12) > 3 && v6 != 10 || (v10 = 1, v5 != 0.0) )
      v10 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v10 != 0)), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v12 = v14.Message.pNode;
    v9 = v14.Message.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( v6 > 9 )
    {
      if ( (v3 >> 9) & 1 )
      {
        v9 = v4->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
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
  unsigned int v2; // edi
  Scaleform::GFx::AS3::VM *v3; // rbx
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rdi
  bool v6; // zf
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // rax
  Scaleform::GFx::AS3::Value v8; // [rsp+28h] [rbp-30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl::Array *v10; // [rsp+70h] [rbp+18h]

  v2 = arr_size;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->TraitsArray.pObject->ITraits.pObject);
  v4 = v2;
  v5 = result.pV;
  Scaleform::GFx::AS3::Impl::SparseArray::Pick(&result.pV->SA, &v3->OpStack, v4);
  v8.Bonus.pWeakProxy = 0i64;
  v8.Flags = 12;
  v8.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)v5;
  v6 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v3->OpStack.pCurrent;
  v7 = (Scaleform::GFx::AS3::Instances::fl::Array *)v3->OpStack.pCurrent;
  result.pV = v7;
  v10 = v7;
  if ( !v6 )
  {
    LODWORD(v7->vfptr) = 12;
    v7->pRCCRaw = 0i64;
    v7->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr;
    v7->pPrev = 0i64;
    if ( v5 )
      v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
}

// File Line: 4083
// RVA: 0x8416B0
void __fastcall Scaleform::GFx::AS3::VM::exec_hasnext2(Scaleform::GFx::AS3::VM *this, unsigned int object_reg, __int64 index_reg)
{
  Scaleform::GFx::AS3::VM *v3; // rsi
  unsigned int v4; // eax
  signed __int64 v5; // r12
  Scaleform::GFx::AS3::Value *v6; // rdx
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  int v11; // ecx
  signed __int64 v12; // r13
  int v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // r15
  Scaleform::GFx::AS3::Object *v15; // r14
  const char *v16; // rbx
  Scaleform::GFx::AS3::VM::ErrorID v17; // ebx
  Scaleform::GFx::AS3::Value *v18; // rax
  Scaleform::GFx::AS3::VM::ErrorID v19; // ebx
  __int64 v20; // rcx
  unsigned int v21; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v22; // er14
  __int64 v23; // rcx
  Scaleform::GFx::AS3::Traits *v24; // rax
  Scaleform::GFx::AS3::Traits *v25; // r14
  Scaleform::GFx::AS3::VM::ErrorID v26; // ebx
  __int64 v27; // rcx
  Scaleform::GFx::AS3::Object *v28; // r15
  int v29; // ebx
  Scaleform::GFx::AS3::VM::ErrorID v30; // er14
  Scaleform::GFx::AS3::Value *v31; // rax
  Scaleform::GFx::AS3::VM::ErrorID v32; // er14
  __int64 v33; // rcx
  __int64 v34; // rcx
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::Object *v36; // [rsp+38h] [rbp-20h]
  __int64 v37; // [rsp+40h] [rbp-18h]
  __int64 v38; // [rsp+A0h] [rbp+48h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+A8h] [rbp+50h]
  unsigned int v40; // [rsp+B0h] [rbp+58h]
  __int64 v41; // [rsp+B8h] [rbp+60h]

  v3 = this;
  index_reg = (unsigned int)index_reg;
  v4 = object_reg;
  v5 = object_reg;
  v6 = this->RegisterFile.pRF;
  v7 = &v6[v5];
  if ( (_DWORD)index_reg == v4 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v35, eInvalidHasNextError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v9 = v35.Message.pNode;
    v10 = v35.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    return;
  }
  v11 = v7->Flags & 0x1F;
  if ( v11 && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || *(_QWORD *)&v7->value.VNumber) )
  {
    v40 = 0;
    v12 = index_reg;
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(&v6[index_reg], &result, &v40)->Result )
      return;
    v13 = v7->Flags & 0x1F;
    if ( (unsigned int)(v13 - 12) <= 3 )
    {
      v14 = v7->value.VS._1.VStr;
      (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::CheckResult *, _QWORD))v14->pData + 16))(
        *(_QWORD *)&v7->value.VNumber,
        &result,
        v40);
      v15 = (Scaleform::GFx::AS3::Object *)v14;
      v16 = v14[1].pData;
      if ( v16 )
      {
        while ( *(_DWORD *)&result.Result <= 0u )
        {
          if ( !*((_QWORD *)v16 + 17) )
            (*(void (__fastcall **)(const char *))(*(_QWORD *)v16 + 80i64))(v16);
          v15 = Scaleform::GFx::AS3::Class::GetPrototype(*((Scaleform::GFx::AS3::Class **)v16 + 17));
          *(_DWORD *)&result.Result = *(_DWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, __int64 *, _QWORD))v15->vfptr[5].~RefCountBaseGC<328>)(
                                                   v15,
                                                   &v38,
                                                   0i64);
          v16 = (const char *)*((_QWORD *)v16 + 18);
          if ( !v16 )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        if ( *(_DWORD *)&result.Result <= 0u )
        {
          v18 = Scaleform::GFx::AS3::Value::GetNull();
          Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v5], v18);
LABEL_26:
          v35.ID = 3;
          v35.Message.pNode = 0i64;
          LODWORD(v36) = *(_DWORD *)&result.Result;
          Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v12], (Scaleform::GFx::AS3::Value *)&v35);
          v19 = v35.ID;
          if ( (v35.ID & 0x1F) > 9 )
          {
            if ( ((unsigned int)v35.ID >> 9) & 1 )
            {
              v10 = v35.Message.pNode->pData-- == (const char *)1;
              if ( v10 )
                ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              v35.Message.pNode = 0i64;
              v36 = 0i64;
              v37 = 0i64;
              v35.ID = v19 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
            }
          }
          v35.ID = 1;
          v35.Message.pNode = 0i64;
          LOBYTE(v36) = *(_DWORD *)&result.Result != 0;
          v10 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
          ++v3->OpStack.pCurrent;
          v20 = (__int64)v3->OpStack.pCurrent;
          v38 = v20;
          v41 = v20;
          if ( !v10 )
          {
            *(_DWORD *)v20 = 1;
            *(_QWORD *)(v20 + 8) = 0i64;
            *(_QWORD *)(v20 + 16) = v36;
            *(_QWORD *)(v20 + 24) = v37;
          }
          return;
        }
      }
      if ( v15 != (Scaleform::GFx::AS3::Object *)v14 )
      {
        v35.ID = 12;
        v35.Message.pNode = 0i64;
        v36 = v15;
        if ( v15 )
          v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v5], (Scaleform::GFx::AS3::Value *)&v35);
        v17 = v35.ID;
        if ( (v35.ID & 0x1F) > 9 )
        {
          if ( ((unsigned int)v35.ID >> 9) & 1 )
          {
            v10 = v35.Message.pNode->pData-- == (const char *)1;
            if ( v10 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v35.Message.pNode = 0i64;
            v36 = 0i64;
            v37 = 0i64;
            v35.ID = v17 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
          }
        }
      }
      goto LABEL_26;
    }
    if ( v13 == 11 )
    {
      if ( v40 > 1 )
        v21 = 0;
      else
        v21 = v40 + 1;
      v35.ID = 3;
      v35.Message.pNode = 0i64;
      LODWORD(v36) = v21;
      Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v12], (Scaleform::GFx::AS3::Value *)&v35);
      v22 = v35.ID;
      if ( (v35.ID & 0x1F) > 9 )
      {
        if ( ((unsigned int)v35.ID >> 9) & 1 )
        {
          v10 = v35.Message.pNode->pData-- == (const char *)1;
          if ( v10 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v35.Message.pNode = 0i64;
          v36 = 0i64;
          v37 = 0i64;
          v35.ID = v22 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
        }
      }
      v35.ID = 1;
      v35.Message.pNode = 0i64;
      LOBYTE(v36) = v21 != 0;
      v10 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
      ++v3->OpStack.pCurrent;
      v23 = (__int64)v3->OpStack.pCurrent;
      v38 = v23;
      v41 = v23;
      if ( !v10 )
      {
        *(_DWORD *)v23 = 1;
        *(_QWORD *)(v23 + 8) = 0i64;
        *(_QWORD *)(v23 + 16) = v36;
        *(_QWORD *)(v23 + 24) = v37;
      }
    }
    else
    {
      v24 = Scaleform::GFx::AS3::VM::GetValueTraits(v3, v7);
      v25 = v24;
      if ( v24->TraitsType == 6 && ~(LOBYTE(v24->Flags) >> 5) & 1 && v40 <= 1 )
      {
        v35.ID = 3;
        v35.Message.pNode = 0i64;
        LODWORD(v36) = v40 + 1;
        Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v12], (Scaleform::GFx::AS3::Value *)&v35);
        v26 = v35.ID;
        if ( (v35.ID & 0x1F) > 9 )
        {
          if ( ((unsigned int)v35.ID >> 9) & 1 )
          {
            v10 = v35.Message.pNode->pData-- == (const char *)1;
            if ( v10 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v35.Message.pNode = 0i64;
            v36 = 0i64;
            v37 = 0i64;
            v35.ID = v26 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
          }
        }
        v35.ID = 1;
        v35.Message.pNode = 0i64;
        LOBYTE(v36) = 1;
        v10 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        ++v3->OpStack.pCurrent;
        v27 = (__int64)v3->OpStack.pCurrent;
        v38 = v27;
        v41 = v27;
        if ( !v10 )
        {
          *(_DWORD *)v27 = 1;
          *(_QWORD *)(v27 + 8) = 0i64;
          *(_QWORD *)(v27 + 16) = v36;
          *(_QWORD *)(v27 + 24) = v37;
        }
      }
      else
      {
        while ( 1 )
        {
          if ( !v25->pConstructor.pObject )
            v25->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v25->vfptr);
          v28 = Scaleform::GFx::AS3::Class::GetPrototype(v25->pConstructor.pObject);
          v29 = *(_DWORD *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::CheckResult *, _QWORD))v28->vfptr[5].~RefCountBaseGC<328>)(
                             v28,
                             &result,
                             0i64);
          v25 = v25->pParent.pObject;
          if ( !v25 )
            break;
          if ( v29 )
            goto LABEL_66;
        }
        if ( !v29 )
        {
          v31 = Scaleform::GFx::AS3::Value::GetNull();
          Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v5], v31);
          goto LABEL_73;
        }
LABEL_66:
        v35.ID = 12;
        v35.Message.pNode = 0i64;
        v36 = v28;
        v28->RefCount = (v28->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v5], (Scaleform::GFx::AS3::Value *)&v35);
        v30 = v35.ID;
        if ( (v35.ID & 0x1F) > 9 )
        {
          if ( ((unsigned int)v35.ID >> 9) & 1 )
          {
            v10 = v35.Message.pNode->pData-- == (const char *)1;
            if ( v10 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v35.Message.pNode = 0i64;
            v36 = 0i64;
            v37 = 0i64;
            v35.ID = v30 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
          }
        }
LABEL_73:
        v35.ID = 3;
        v35.Message.pNode = 0i64;
        LODWORD(v36) = v29;
        Scaleform::GFx::AS3::Value::Assign(&v3->RegisterFile.pRF[v12], (Scaleform::GFx::AS3::Value *)&v35);
        v32 = v35.ID;
        if ( (v35.ID & 0x1F) > 9 )
        {
          if ( ((unsigned int)v35.ID >> 9) & 1 )
          {
            v10 = v35.Message.pNode->pData-- == (const char *)1;
            if ( v10 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v35.Message.pNode = 0i64;
            v36 = 0i64;
            v37 = 0i64;
            v35.ID = v32 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v35);
          }
        }
        v35.ID = 1;
        v35.Message.pNode = 0i64;
        LOBYTE(v36) = v29 != 0;
        v10 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        ++v3->OpStack.pCurrent;
        v33 = (__int64)v3->OpStack.pCurrent;
        v38 = v33;
        v41 = v33;
        if ( !v10 )
        {
          *(_DWORD *)v33 = 1;
          *(_QWORD *)(v33 + 8) = 0i64;
          *(_QWORD *)(v33 + 16) = v36;
          *(_QWORD *)(v33 + 24) = v37;
        }
      }
    }
  }
  else
  {
    v35.ID = 1;
    v35.Message.pNode = 0i64;
    LOBYTE(v36) = 0;
    v10 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++v3->OpStack.pCurrent;
    v34 = (__int64)v3->OpStack.pCurrent;
    v38 = v34;
    v41 = v34;
    if ( !v10 )
    {
      *(_DWORD *)v34 = 1;
      *(_QWORD *)(v34 + 8) = 0i64;
      *(_QWORD *)(v34 + 16) = v36;
      *(_QWORD *)(v34 + 24) = v37;
    }
  }
}

// File Line: 4241
// RVA: 0x838EE0
void __fastcall Scaleform::GFx::AS3::VM::exec_applytype(Scaleform::GFx::AS3::VM *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // r8
  int v4; // edx
  char v5; // al
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::Value *v11; // r8
  Scaleform::GFx::AS3::Class **v12; // rbx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+20h] [rbp-E0h]
  __int64 v14; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::ReadArgs ptr; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value *v16; // [rsp+178h] [rbp+78h]

  v14 = -2i64;
  v2 = this;
  Scaleform::GFx::AS3::ReadArgs::ReadArgs(&ptr, this, arg_count);
  v3 = ptr.OpStack->pCurrent;
  v16 = v3;
  v4 = v3->Flags & 0x1F;
  if ( !v4 || ((unsigned int)(v4 - 12) <= 3 || v4 == 10) && !*(_QWORD *)&v3->value.VNumber )
  {
    v5 = (unsigned int)(v4 - 12) > 3 && v4 != 10 || *(_QWORD *)&v3->value.VNumber ? 0 : 1;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v5 != 0)), ptr.VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(ptr.VMRef, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v7 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  if ( v2->HandleException )
  {
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  }
  else if ( (v16->Flags & 0x1F) == 13 )
  {
    v11 = ptr.FixedArr;
    if ( ptr.ArgNum > 8 )
      v11 = ptr.CallArgs.Data.Data;
    v12 = *(Scaleform::GFx::AS3::Class ***)((*((__int64 (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::AS3::Value *))v16->value.VS._1.VStr->pData
                                             + 22))(
                                              *(_QWORD *)&v16->value.VNumber,
                                              ptr.ArgNum,
                                              v11)
                                          + 200);
    if ( !v12[17] )
      ((void (__fastcall *)(Scaleform::GFx::AS3::Class **))(*v12)[1]._pRCC)(v12);
    Scaleform::GFx::AS3::Value::Assign(v16, v12[17]);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eTypeAppOfNonParamType, v2);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v2, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v13.Message.pNode;
    v8 = v13.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
  }
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 4255
// RVA: 0x7CF440
void __fastcall Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *func, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool result_on_stack)
{
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::Value *v8; // r12
  Scaleform::GFx::AS3::Value *v9; // rdi
  Scaleform::GFx::AS3::VM *v10; // r14
  unsigned int v11; // edx
  long double v12; // rcx
  long double v13; // rcx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *v17; // rcx
  signed __int64 v19; // rdx
  Scaleform::GFx::AS3::Value *v20; // rcx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::AS3::Value *v22; // rcx
  long double v24; // rcx
  signed __int64 v25; // rdx
  Scaleform::GFx::AS3::Value *v26; // rcx
  Scaleform::GFx::AS3::VM::Error *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  __int64 v30; // rbx
  Scaleform::GFx::AS3::Traits *v31; // r13
  Scaleform::GFx::AS3::VMAbcFile *v32; // rax
  Scaleform::GFx::AS3::VMAbcFile *v33; // r8
  __int64 v34; // rbx
  Scaleform::GFx::AS3::VM::Error *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::VM *v37; // rcx
  unsigned int v38; // ecx
  Scaleform::GFx::AS3::WeakProxy *v39; // rdx
  int v40; // eax
  long double v41; // rcx
  Scaleform::GFx::AS3::ValueStack *v42; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v43; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v44; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v45; // rcx
  unsigned int v46; // eax
  unsigned __int64 v47; // rdi
  Scaleform::GFx::AS3::CallFrame **v48; // rax
  signed __int64 v49; // rcx
  Scaleform::GFx::AS3::CallFrame *v50; // rcx
  signed __int64 v52; // rdx
  Scaleform::GFx::AS3::Value *v53; // rcx
  Scaleform::GFx::AS3::VM::Error *v54; // rax
  Scaleform::GFx::AS3::Traits *v55; // rcx
  long double v57; // rdx
  __int64 v58; // rbx
  Scaleform::GFx::AS3::Traits *v59; // r12
  Scaleform::GFx::AS3::VMAbcFile *v60; // rax
  Scaleform::GFx::AS3::VMAbcFile *v61; // r13
  __int64 v62; // rbx
  Scaleform::GFx::AS3::VM::Error *v63; // rax
  Scaleform::GFx::ASStringNode *v64; // rcx
  Scaleform::GFx::AS3::VM *v65; // rcx
  unsigned int v66; // ecx
  Scaleform::GFx::AS3::WeakProxy *v67; // rdx
  int v68; // eax
  long double v69; // rcx
  Scaleform::GFx::AS3::ValueStack *v70; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v71; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v72; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v73; // rcx
  unsigned int v74; // eax
  unsigned __int64 v75; // rdi
  Scaleform::GFx::AS3::CallFrame **v76; // rax
  signed __int64 v77; // rcx
  Scaleform::GFx::AS3::CallFrame *v78; // rcx
  signed __int64 v80; // rdx
  Scaleform::GFx::AS3::Value *v81; // rcx
  Scaleform::GFx::AS3::VM::Error *v82; // rax
  Scaleform::GFx::ASStringNode *v83; // rcx
  Scaleform::GFx::AS3::VM::Error *v84; // rax
  Scaleform::GFx::AS3::Value _thisa; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS3::VM::Error v86; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::VM::Error v88; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::AS3::VM::Error v89; // [rsp+100h] [rbp+0h]
  __int64 v90; // [rsp+110h] [rbp+10h]
  _QWORD *v91; // [rsp+168h] [rbp+68h]
  _QWORD *v92; // [rsp+170h] [rbp+70h]

  v90 = -2i64;
  v7 = result;
  v8 = _this;
  v9 = func;
  v10 = this;
  __asm
  {
    prefetcht1 byte ptr [rdx]; Prefetch to all cache levels
    prefetcht1 byte ptr [r8]; Prefetch to all cache levels
  }
  v11 = func->Flags;
  switch ( v11 & 0x1F )
  {
    case 5u:
      _R10 = v9->value.VNumber;
      __asm
      {
        prefetcht1 byte ptr [r10+20h]; Prefetch to all cache levels
        prefetcht1 byte ptr [r10]; Prefetch to all cache levels
      }
      v19 = (*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 9) & 0xFFFi64;
      if ( argc < ((unsigned __int64)(*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 6) & 7)
        || !((*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 21) & 1) && argc > (unsigned int)v19 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v86, eWrongArgumentCountError, this);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v21, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v15 = v86.Message.pNode;
        goto LABEL_137;
      }
      (**(void (__fastcall ***)(long double, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *))&_R10)(
        COERCE_LONG_DOUBLE(*(_QWORD *)&_R10),
        this,
        _this);
      if ( result_on_stack && !v10->HandleException )
      {
        v91 = &v10->OpStack.pCurrent;
        v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        *v91 += 32i64;
        v20 = v10->OpStack.pCurrent;
        v92 = &v10->OpStack.pCurrent->Flags;
        if ( !v16 )
        {
          v20->Flags = v7->Flags;
          v20->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
          v20->value.VNumber = v7->value.VNumber;
          v20->value.VS._2.VObj = v7->value.VS._2.VObj;
          v7->Flags = 0;
        }
      }
      return;
    case 7u:
      _RDX = &Scaleform::GFx::AS3::Traits::GetVT(v9->value.VS._2.pTraits)->VTMethods.Data.Data[v9->value.VS._1.VUInt];
      __asm { prefetcht1 byte ptr [rdx]; Prefetch to all cache levels }
      if ( (_RDX->Flags & 0x1F) == 6 )
      {
        v30 = _RDX->value.VS._1.VInt;
        v31 = _RDX->value.VS._2.pTraits;
        v32 = (Scaleform::GFx::AS3::VMAbcFile *)((__int64 (__fastcall *)(_QWORD))v31->vfptr[2].~RefCountBaseGC<328>)((Scaleform::GFx::AS3::Value::V2U)_RDX->value.VS._2.VObj);
        v33 = v32;
        v92 = &v32->vfptr;
        v34 = v32->File.pObject->Methods.Info.Data.Data[v30]->MethodBodyInfoInd;
        if ( v10->CallStack.Size == 128 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v86, eStackOverflowError, v10);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v35, &Scaleform::GFx::AS3::fl::ErrorTI);
          v36 = v86.Message.pNode;
          v16 = v86.Message.pNode->RefCount == 1;
          --v36->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
LABEL_76:
          if ( !result_on_stack )
            Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(v10, v7);
          return;
        }
        *(_WORD *)&other.DiscardResult = 0;
        v37 = v32->VMRef;
        other.ScopeStackBaseInd = v37->ScopeStack.Data.Size;
        other.CP = 0i64;
        other.pRegisterFile = &v37->RegisterFile;
        other.pHeap = v37->MHeap;
        other.pFile = v32;
        other.MBIIndex.Ind = v34;
        other.pSavedScope = &v31->InitScope;
        other.OriginationTraits = v31;
        other.pScopeStack = &v37->ScopeStack;
        other.DefXMLNamespace.pObject = 0i64;
        v38 = v9->Flags;
        other.Invoker.Flags = v38;
        v39 = v9->Bonus.pWeakProxy;
        other.Invoker.Bonus.pWeakProxy = v9->Bonus.pWeakProxy;
        other.Invoker.value = v9->value;
        v40 = v38 & 0x1F;
        if ( v40 > 9 )
        {
          if ( (v38 >> 9) & 1 )
          {
            ++v39->RefCount;
            goto LABEL_60;
          }
          if ( v40 == 10 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v9->value.VNumber + 24i64);
          }
          else if ( v40 > 10 )
          {
            if ( v40 <= 15 )
            {
              v41 = v9->value.VNumber;
LABEL_57:
              if ( v41 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v41 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v41 + 32i64) + 1) & 0x8FBFFFFF;
              goto LABEL_60;
            }
            if ( v40 <= 17 )
            {
              v41 = *(double *)&v9->value.VS._2.VObj;
              goto LABEL_57;
            }
          }
        }
LABEL_60:
        v42 = &v33->VMRef->OpStack;
        other.PrevInitialStackPos = v42->pCurrent;
        other.PrevFirstStackPos = v42->pStack;
        v43 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
        Scaleform::GFx::AS3::ValueStack::Reserve(v42, v43->max_stack + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v43->local_reg_count);
        v44 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
        if ( *v44 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
            *v44);
          v91 = 0i64;
          if ( &v91 != (_QWORD **)v44 )
          {
            v45 = *v44;
            if ( *v44 )
            {
              if ( (unsigned __int8)v45 & 1 )
              {
                *v44 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v45 - 1);
              }
              else
              {
                v46 = v45->RefCount;
                if ( v46 & 0x3FFFFF )
                {
                  v45->RefCount = v46 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v45->vfptr);
                }
              }
            }
            *v44 = 0i64;
          }
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &other,
          *(Scaleform::GFx::AS3::Abc::MethodInfo **)(*(_QWORD *)(v92[19] + 224i64)
                                                   + 8i64
                                                   * *(signed int *)(*(_QWORD *)(*(_QWORD *)(v92[19] + 344i64) + 8 * v34)
                                                                   + 24i64)),
          v8,
          argc,
          argv);
        if ( v10->HandleException )
        {
          other.ACopy = 1;
        }
        else
        {
          v47 = v10->CallStack.Size >> 6;
          if ( v47 >= v10->CallStack.NumPages )
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
              (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v10->CallStack.gap0,
              v10->CallStack.Size >> 6);
          v48 = v10->CallStack.Pages;
          v49 = v10->CallStack.Size & 0x3F;
          v16 = &v48[v47][v49] == 0i64;
          v50 = &v48[v47][v49];
          v91 = v50;
          v92 = v50;
          if ( !v16 )
            Scaleform::GFx::AS3::CallFrame::CallFrame(v50, &other);
          ++v10->CallStack.Size;
        }
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        goto LABEL_76;
      }
      _R10 = _RDX->value.VNumber;
      __asm
      {
        prefetcht1 byte ptr [r10+20h]; Prefetch to all cache levels
        prefetcht1 byte ptr [r10]; Prefetch to all cache levels
      }
      v52 = (*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 9) & 0xFFFi64;
      if ( argc < ((unsigned __int64)(*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 6) & 7)
        || !((*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 21) & 1) && argc > (unsigned int)v52 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v86, eWrongArgumentCountError, v10);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v54, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v15 = v86.Message.pNode;
        goto LABEL_137;
      }
      (**(void (__fastcall ***)(long double, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))&_R10)(
        COERCE_LONG_DOUBLE(*(_QWORD *)&_R10),
        v10,
        v8,
        v7,
        argc,
        argv);
      if ( result_on_stack && !v10->HandleException )
      {
        v91 = &v10->OpStack.pCurrent;
        v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        *v91 += 32i64;
        v53 = v10->OpStack.pCurrent;
        v92 = &v10->OpStack.pCurrent->Flags;
        if ( !v16 )
        {
          v53->Flags = v7->Flags;
          v53->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
          v53->value.VNumber = v7->value.VNumber;
          v53->value.VS._2.VObj = v7->value.VS._2.VObj;
          v7->Flags = 0;
        }
      }
      return;
    case 0xCu:
    case 0xDu:
      v13 = v9->value.VNumber;
      if ( v13 == 0.0 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v89, eCallOfNonFunctionError, v10);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v15 = v89.Message.pNode;
        goto LABEL_137;
      }
      (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v13 + 72i64))(
        COERCE_LONG_DOUBLE(*(_QWORD *)&v13),
        _this,
        result,
        argc,
        argv);
      if ( !v10->HandleException && result_on_stack )
      {
        v91 = &v10->OpStack.pCurrent;
        v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        *v91 += 32i64;
        v17 = v10->OpStack.pCurrent;
        v92 = &v10->OpStack.pCurrent->Flags;
        if ( !v16 )
        {
          v17->Flags = v7->Flags;
          v17->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
          v17->value.VNumber = v7->value.VNumber;
          v17->value.VS._2.VObj = v7->value.VS._2.VObj;
          v7->Flags = 0;
        }
      }
      return;
    case 0xEu:
      v12 = v9->value.VNumber;
      if ( result_on_stack )
        (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, _BYTE))(**(_QWORD **)&v12 + 168i64))(
          COERCE_LONG_DOUBLE(*(_QWORD *)&v12),
          _this,
          argc,
          argv,
          0);
      else
        (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v12 + 160i64))(
          COERCE_LONG_DOUBLE(*(_QWORD *)&v12),
          _this,
          result,
          argc,
          argv);
      return;
    case 0xFu:
      (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))v9->value.VS._1.VStr->pData
       + 20))(
        *(_QWORD *)&v9->value.VNumber,
        _this,
        result,
        argc,
        argv);
      if ( !v10->HandleException && result_on_stack )
      {
        v91 = &v10->OpStack.pCurrent;
        v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        *v91 += 32i64;
        v22 = v10->OpStack.pCurrent;
        v92 = &v10->OpStack.pCurrent->Flags;
        if ( !v16 )
        {
          v22->Flags = v7->Flags;
          v22->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
          v22->value.VNumber = v7->value.VNumber;
          v22->value.VS._2.VObj = v7->value.VS._2.VObj;
          v7->Flags = 0;
        }
      }
      return;
    case 0x10u:
      _R10 = v9->value.VNumber;
      __asm
      {
        prefetcht1 byte ptr [r10+20h]; Prefetch to all cache levels
        prefetcht1 byte ptr [r10]; Prefetch to all cache levels
      }
      v24 = *(double *)&v9->value.VS._2.VObj;
      _thisa.Flags = 12;
      _thisa.Bonus.pWeakProxy = 0i64;
      _thisa.value.VNumber = v24;
      if ( v24 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v24 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v24 + 32i64) + 1) & 0x8FBFFFFF;
      v25 = (*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 9) & 0xFFFi64;
      if ( argc >= ((unsigned __int64)(*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 6) & 7)
        && ((*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 21) & 1 || argc <= (unsigned int)v25) )
      {
        (**(void (__fastcall ***)(long double, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *))&_R10)(
          COERCE_LONG_DOUBLE(*(_QWORD *)&_R10),
          v10,
          &_thisa);
        if ( result_on_stack && !v10->HandleException )
        {
          v91 = &v10->OpStack.pCurrent;
          v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
          *v91 += 32i64;
          v26 = v10->OpStack.pCurrent;
          v92 = &v10->OpStack.pCurrent->Flags;
          if ( !v16 )
          {
            v26->Flags = v7->Flags;
            v26->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
            v26->value.VNumber = v7->value.VNumber;
            v26->value.VS._2.VObj = v7->value.VS._2.VObj;
            v7->Flags = 0;
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v86, eWrongArgumentCountError, v10);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v27, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v28 = v86.Message.pNode;
        v16 = v86.Message.pNode->RefCount == 1;
        --v28->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      }
      goto LABEL_38;
    case 0x11u:
      v55 = v9->value.VS._2.VObj->pTraits.pObject;
      if ( (v11 >> 11) & 1 )
        v55 = v55->pParent.pObject;
      _RCX = &Scaleform::GFx::AS3::Traits::GetVT(v55)->VTMethods.Data.Data[v9->value.VS._1.VUInt];
      __asm { prefetcht1 byte ptr [rcx]; Prefetch to all cache levels }
      v57 = *(double *)&v9->value.VS._2.VObj;
      _thisa.Flags = 12;
      _thisa.Bonus.pWeakProxy = 0i64;
      _thisa.value.VNumber = v57;
      if ( v57 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v57 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v57 + 32i64) + 1) & 0x8FBFFFFF;
      if ( (_RCX->Flags & 0x1F) == 6 )
      {
        v58 = _RCX->value.VS._1.VInt;
        v59 = _RCX->value.VS._2.pTraits;
        v60 = (Scaleform::GFx::AS3::VMAbcFile *)((__int64 (__fastcall *)(_QWORD))v59->vfptr[2].~RefCountBaseGC<328>)((Scaleform::GFx::AS3::Value::V2U)_RCX->value.VS._2.VObj);
        v61 = v60;
        v62 = v60->File.pObject->Methods.Info.Data.Data[v58]->MethodBodyInfoInd;
        if ( v10->CallStack.Size == 128 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v86, eStackOverflowError, v10);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v63, &Scaleform::GFx::AS3::fl::ErrorTI);
          v64 = v86.Message.pNode;
          v16 = v86.Message.pNode->RefCount == 1;
          --v64->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v64);
LABEL_123:
          if ( !result_on_stack )
            Scaleform::GFx::AS3::VM::ExecuteAndRetrieveResult(v10, v7);
          goto LABEL_38;
        }
        *(_WORD *)&other.DiscardResult = 0;
        v65 = v60->VMRef;
        other.ScopeStackBaseInd = v65->ScopeStack.Data.Size;
        other.CP = 0i64;
        other.pRegisterFile = &v65->RegisterFile;
        other.pHeap = v65->MHeap;
        other.pFile = v60;
        other.MBIIndex.Ind = v62;
        other.pSavedScope = &v59->InitScope;
        other.OriginationTraits = v59;
        other.pScopeStack = &v65->ScopeStack;
        other.DefXMLNamespace.pObject = 0i64;
        v66 = v9->Flags;
        other.Invoker.Flags = v66;
        v67 = v9->Bonus.pWeakProxy;
        other.Invoker.Bonus.pWeakProxy = v9->Bonus.pWeakProxy;
        other.Invoker.value = v9->value;
        v68 = v66 & 0x1F;
        if ( v68 > 9 )
        {
          if ( (v66 >> 9) & 1 )
          {
            ++v67->RefCount;
            goto LABEL_107;
          }
          if ( v68 == 10 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v9->value.VNumber + 24i64);
          }
          else if ( v68 > 10 )
          {
            if ( v68 <= 15 )
            {
              v69 = v9->value.VNumber;
LABEL_104:
              if ( v69 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v69 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v69 + 32i64) + 1) & 0x8FBFFFFF;
              goto LABEL_107;
            }
            if ( v68 <= 17 )
            {
              v69 = *(double *)&v9->value.VS._2.VObj;
              goto LABEL_104;
            }
          }
        }
LABEL_107:
        v70 = &v61->VMRef->OpStack;
        other.PrevInitialStackPos = v70->pCurrent;
        other.PrevFirstStackPos = v70->pStack;
        v71 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
        Scaleform::GFx::AS3::ValueStack::Reserve(v70, v71->max_stack + 1);
        Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v71->local_reg_count);
        v72 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
        if ( *v72 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
            *v72);
          v91 = 0i64;
          if ( &v91 != (_QWORD **)v72 )
          {
            v73 = *v72;
            if ( *v72 )
            {
              if ( (unsigned __int8)v73 & 1 )
              {
                *v72 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v73 - 1);
              }
              else
              {
                v74 = v73->RefCount;
                if ( v74 & 0x3FFFFF )
                {
                  v73->RefCount = v74 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v73->vfptr);
                }
              }
            }
            *v72 = 0i64;
          }
        }
        Scaleform::GFx::AS3::CallFrame::SetupRegisters(
          &other,
          v61->File.pObject->Methods.Info.Data.Data[v61->File.pObject->MethodBodies.Info.Data.Data[v62]->method_info_ind],
          &_thisa,
          argc,
          argv);
        if ( v10->HandleException )
        {
          other.ACopy = 1;
        }
        else
        {
          v75 = v10->CallStack.Size >> 6;
          if ( v75 >= v10->CallStack.NumPages )
            Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
              (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v10->CallStack.gap0,
              v10->CallStack.Size >> 6);
          v76 = v10->CallStack.Pages;
          v77 = v10->CallStack.Size & 0x3F;
          v16 = &v76[v75][v77] == 0i64;
          v78 = &v76[v75][v77];
          v91 = v78;
          v92 = v78;
          if ( !v16 )
            Scaleform::GFx::AS3::CallFrame::CallFrame(v78, &other);
          ++v10->CallStack.Size;
        }
        Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
        goto LABEL_123;
      }
      _R10 = _RCX->value.VNumber;
      __asm
      {
        prefetcht1 byte ptr [r10+20h]; Prefetch to all cache levels
        prefetcht1 byte ptr [r10]; Prefetch to all cache levels
      }
      v80 = (*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 9) & 0xFFFi64;
      if ( argc >= ((unsigned __int64)(*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 6) & 7)
        && ((*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 21) & 1 || argc <= (unsigned int)v80) )
      {
        (**(void (__fastcall ***)(long double, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))&_R10)(
          COERCE_LONG_DOUBLE(*(_QWORD *)&_R10),
          v10,
          &_thisa,
          v7,
          argc,
          argv);
        if ( result_on_stack && !v10->HandleException )
        {
          v91 = &v10->OpStack.pCurrent;
          v16 = v10->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
          *v91 += 32i64;
          v81 = v10->OpStack.pCurrent;
          v92 = &v10->OpStack.pCurrent->Flags;
          if ( !v16 )
          {
            v81->Flags = v7->Flags;
            v81->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
            v81->value.VNumber = v7->value.VNumber;
            v81->value.VS._2.VObj = v7->value.VS._2.VObj;
            v7->Flags = 0;
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v86, eWrongArgumentCountError, v10);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v82, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v83 = v86.Message.pNode;
        v16 = v86.Message.pNode->RefCount == 1;
        --v83->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v83);
      }
LABEL_38:
      if ( (_thisa.Flags & 0x1F) > 9 )
      {
        if ( (_thisa.Flags >> 9) & 1 )
        {
          v16 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v16 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _thisa.Bonus.pWeakProxy = 0i64;
          _thisa.value = 0ui64;
          _thisa.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_thisa);
        }
      }
      return;
    default:
      Scaleform::GFx::AS3::VM::Error::Error(&v88, eCallOfNonFunctionError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v84, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v15 = v88.Message.pNode;
LABEL_137:
      v16 = v15->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      return;
  }
}

// File Line: 4392
// RVA: 0x7D0F00
void __fastcall Scaleform::GFx::AS3::VM::ExecuteVTableIndUnsafe(Scaleform::GFx::AS3::VM *this, unsigned int ind, Scaleform::GFx::AS3::Traits *tr, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rdi
  int v6; // er15
  Scaleform::GFx::AS3::VM *v7; // r14
  __int64 v9; // rbx
  unsigned __int64 *v10; // r15
  __int64 v11; // rax
  __int64 v12; // r13
  __int64 v13; // rbx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  __int64 v17; // rcx
  signed __int64 v18; // rcx
  __int64 v19; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // rcx
  unsigned int v22; // eax
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *v23; // r14
  unsigned __int64 v24; // rbx
  Scaleform::GFx::AS3::CallFrame **v25; // rax
  signed __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  signed __int64 v29; // rdx
  int v30; // ST20_4
  Scaleform::GFx::AS3::Value::VU *v31; // rcx
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::Value v34; // [rsp+30h] [rbp-A8h]
  void *v35; // [rsp+50h] [rbp-88h]
  Scaleform::GFx::AS3::VM::Error v36; // [rsp+58h] [rbp-80h]
  __int64 v37; // [rsp+68h] [rbp-70h]
  Scaleform::GFx::AS3::CallFrame other; // [rsp+70h] [rbp-68h]
  void *retaddr; // [rsp+138h] [rbp+60h]
  Scaleform::GFx::AS3::Value *v40; // [rsp+140h] [rbp+68h]

  *(_QWORD *)&other.Invoker.Flags = -2i64;
  v4 = _this;
  v5 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)tr;
  v6 = ind;
  v7 = this;
  _RCX = &Scaleform::GFx::AS3::Traits::GetVT(tr)->VTMethods.Data.Data[ind];
  __asm { prefetcht1 byte ptr [rcx]; Prefetch to all cache levels }
  if ( (_RCX->Flags & 0x1F) == 6 )
  {
    v34.Flags = 7;
    v34.Bonus.pWeakProxy = 0i64;
    v34.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v5;
    v34.value.VS._1.VInt = v6;
    v9 = _RCX->value.VS._1.VInt;
    v10 = (unsigned __int64 *)_RCX->value.VS._2.VObj;
    v11 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V2U))(*v10 + 56))(_RCX->value.VS._2);
    v12 = v11;
    v13 = *(signed int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 152) + 224i64) + 8 * v9) + 8i64);
    if ( v7->CallStack.Size == 128 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v36, eStackOverflowError, v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v14, &Scaleform::GFx::AS3::fl::ErrorTI);
      v15 = v36.Message.pNode;
      v16 = v36.Message.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      *(_WORD *)&other.DiscardResult = 0;
      v17 = *(_QWORD *)(v11 + 40);
      other.ScopeStackBaseInd = *(_QWORD *)(v17 + 144);
      *(_QWORD *)&v36.ID = 0i64;
      v36.Message.pNode = (Scaleform::GFx::ASStringNode *)(v17 + 96);
      v37 = *(_QWORD *)(v17 + 48);
      *(_QWORD *)&other.DiscardResult = v11;
      LODWORD(other.ScopeStackBaseInd) = v13;
      other.CP = v10 + 21;
      other.pRegisterFile = (Scaleform::GFx::AS3::ValueRegisterFile *)v10;
      other.pHeap = (Scaleform::MemoryHeap *)(v17 + 136);
      *(_QWORD *)&other.MBIIndex.Ind = 0i64;
      LODWORD(other.OriginationTraits) = 7;
      other.pScopeStack = 0i64;
      other.PrevInitialStackPos = (Scaleform::GFx::AS3::Value *)v34.value.VS._1.VStr;
      other.DefXMLNamespace.pObject = v5;
      v18 = *(_QWORD *)(v11 + 40) + 64i64;
      other.pFile = *(Scaleform::GFx::AS3::VMAbcFile **)v18;
      other.pSavedScope = *(Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> **)(v18 + 8);
      v19 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v11 + 152) + 344i64) + 8i64 * (signed int)v13);
      Scaleform::GFx::AS3::ValueStack::Reserve((Scaleform::GFx::AS3::ValueStack *)v18, *(unsigned int *)(v19 + 28) + 1);
      Scaleform::GFx::AS3::ValueRegisterFile::Reserve(
        (Scaleform::GFx::AS3::ValueRegisterFile *)v36.Message.pNode,
        *(_WORD *)(v19 + 32));
      v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)(*(_QWORD *)&other.DiscardResult + 40i64)
                                                           + 640i64);
      if ( *v20 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.MBIIndex,
          *v20);
        v35 = 0i64;
        if ( &v35 != (void **)v20 )
        {
          v21 = *v20;
          if ( *v20 )
          {
            if ( (unsigned __int8)v21 & 1 )
            {
              *v20 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v21 - 1);
            }
            else
            {
              v22 = v21->RefCount;
              if ( v22 & 0x3FFFFF )
              {
                v21->RefCount = v22 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
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
                                                 * *(signed int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 152)
                                                                                         + 344i64)
                                                                             + 8 * v13)
                                                                 + 24i64)),
        v4,
        (unsigned int)retaddr,
        v40);
      if ( v7->HandleException )
      {
        other.ACopy = 1;
      }
      else
      {
        v23 = (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v7->CallStack.gap0;
        v24 = v23->Size >> 6;
        if ( v24 >= v23->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
            v23,
            v23->Size >> 6);
        v25 = v23->Pages;
        v26 = v23->Size & 0x3F;
        v16 = &v25[v24][v26] == 0i64;
        v27 = &v25[v24][v26];
        v35 = v27;
        *(_QWORD *)&v36.ID = v27;
        if ( !v16 )
          Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
        ++v23->Size;
      }
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
    }
  }
  else
  {
    _R10 = _RCX->value.VNumber;
    __asm
    {
      prefetcht1 byte ptr [r10+20h]; Prefetch to all cache levels
      prefetcht1 byte ptr [r10]; Prefetch to all cache levels
    }
    v34.Flags = 0;
    v34.Bonus.pWeakProxy = 0i64;
    v29 = (*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 9) & 0xFFFi64;
    if ( (unsigned int)retaddr >= ((unsigned __int64)(*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 6) & 7)
      && ((*(_QWORD *)(*(_QWORD *)&_R10 + 32i64) >> 21) & 1 || (unsigned int)retaddr <= (unsigned int)v29) )
    {
      v30 = (signed int)retaddr;
      (**(void (__fastcall ***)(long double, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, int, Scaleform::GFx::AS3::Value *))&_R10)(
        COERCE_LONG_DOUBLE(*(_QWORD *)&_R10),
        v7,
        v4,
        &v34,
        v30,
        v40);
      if ( !v7->HandleException )
      {
        *(_QWORD *)&v36.ID = (char *)v7 + 64;
        v16 = v7->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        **(_QWORD **)&v36.ID += 32i64;
        v31 = (Scaleform::GFx::AS3::Value::VU *)v7->OpStack.pCurrent;
        v35 = v7->OpStack.pCurrent;
        if ( !v16 )
        {
          LODWORD(v31->VS._1.VStr) = v34.Flags;
          v31->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v34.Bonus.pWeakProxy;
          v31[1] = v34.value;
          v34.Flags = 0;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v36, eWrongArgumentCountError, v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v32, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v33 = v36.Message.pNode;
      v16 = v36.Message.pNode->RefCount == 1;
      --v33->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    }
    if ( (v34.Flags & 0x1F) > 9 )
    {
      if ( (v34.Flags >> 9) & 1 )
      {
        v16 = v34.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v16 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v34.Bonus.pWeakProxy = 0i64;
        v34.value = 0ui64;
        v34.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
      }
    }
  }
}

// File Line: 4627
// RVA: 0x7B6770
void __fastcall Scaleform::GFx::AS3::VM::Coerce2ReturnType(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::CallFrame *v6; // r10
  Scaleform::GFx::AS3::VMFile *v7; // rdx
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rax
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h]

  v3 = result;
  v4 = value;
  v5 = this;
  v6 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  v7 = (Scaleform::GFx::AS3::VMFile *)&v6->pFile->vfptr;
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
         this,
         v7,
         (Scaleform::GFx::AS3::Abc::Multiname *)v7[1].vfptr[7].~RefCountBaseGC<328>
       + *(signed int *)(*((_QWORD *)v7[1].vfptr[9].~RefCountBaseGC<328>
                         + *(signed int *)(*((_QWORD *)v7[1].vfptr[14].~RefCountBaseGC<328> + v6->MBIIndex.Ind) + 24i64))
                       + 4i64));
  if ( v8 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v8->vfptr[3].Finalize_GC)(
           v8,
           v4,
           v3) )
    {
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eCheckTypeFailedError, v5);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eClassNotFoundError, v5);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  v11 = v13.Message.pNode;
  v12 = v13.Message.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}

// File Line: 4664
// RVA: 0x7F0C10
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetUserDefinedTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::ClassInfo *ci)
{
  Scaleform::GFx::AS3::VMFile *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // r15
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rbp
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rdi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v8; // r14
  Scaleform::GFx::AS3::VMAppDomain *v9; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v3 = file;
  v4 = this;
  v5 = (Scaleform::GFx::AS3::Abc::Multiname *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMFile *, _QWORD))file->vfptr[1].ForEachChild_GC)(
                                                file,
                                                ci->inst_info.name_ind);
  Scaleform::GFx::AS3::VMFile::GetInternedString(v3, &result, v5->NameIndex);
  v6 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v3, v5->Ind);
  v7 = v6;
  v8 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v3->AppDomain.pObject;
  v9 = (Scaleform::GFx::AS3::VMAppDomain *)v8[2].Entries.mHash.pHeap;
  if ( v9 && (v10 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v9, &result, v6)) != 0i64
    || (v10 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                v8 + 3,
                &result,
                v7)) != 0i64
    || (v11 = v7->Uri.pNode, v11->Size < 0xD)
    || strncmp(v11->pData, "scaleform.gfx", 0xDui64) )
  {
    v12 = *v10;
  }
  else
  {
    v12 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v4, v3, v5);
  }
  v13 = result.pNode;
  v14 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  return v12;
}

// File Line: 4695
// RVA: 0x805CB0
void __fastcall Scaleform::GFx::AS3::VM::OutputError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *e)
{
  Scaleform::GFx::AS3::Value *v2; // r15
  Scaleform::GFx::AS3::VM *v3; // r13
  long double *v4; // rax
  unsigned int v5; // edi
  long double v6; // rbx
  Scaleform::GFx::AS3::Value::V2U v7; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rdx
  int v9; // esi
  __int64 v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  int v16; // ecx
  bool v17; // al
  __int64 v18; // r8
  int v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::AS3::WeakProxy *v21; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::WeakProxy *v25; // rdx
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+48h] [rbp-61h]
  Scaleform::GFx::AS3::Value v27; // [rsp+78h] [rbp-31h]
  Scaleform::GFx::AS3::Value v28; // [rsp+98h] [rbp-11h]
  __int64 v29; // [rsp+B8h] [rbp+Fh]
  Scaleform::GFx::ASString v30; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+118h] [rbp+6Fh]
  Scaleform::GFx::ASString v32; // [rsp+120h] [rbp+77h]
  Scaleform::GFx::ASString v33; // [rsp+128h] [rbp+7Fh]

  v29 = -2i64;
  v2 = e;
  v3 = this;
  v28.Flags = 0;
  v28.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
    &result);
  v4 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
                        &v33,
                        "getStackTrace");
  v5 = 10;
  v27.Flags = 10;
  v27.Bonus.pWeakProxy = 0i64;
  v6 = *v4;
  v27.value.VNumber = v6;
  if ( *(_QWORD *)&v6 == *(_QWORD *)(*(_QWORD *)&v6 + 8i64) + 104i64 )
  {
    v6 = 0.0;
    v27.value.VNumber = 0.0;
    v7.VObj = (Scaleform::GFx::AS3::Object *)v27.Bonus.pWeakProxy;
    v27.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v27.Bonus.pWeakProxy;
    v5 = 12;
    v27.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
    v7.VObj = (Scaleform::GFx::AS3::Object *)v27.value.VS._2;
  }
  v8 = (Scaleform::GFx::AS3::GASRefCountBase *)&v3->PublicNamespace.pObject->vfptr;
  prop_name.Kind = 0;
  prop_name.Obj.pObject = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  prop_name.Name.Flags = 0;
  prop_name.Name.Bonus.pWeakProxy = 0i64;
  v9 = v5 & 0x1F;
  if ( (unsigned int)(v9 - 12) <= 3
    && v6 != 0.0
    && (v10 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64), *(_DWORD *)(v10 + 120) == 17)
    && ~(*(_BYTE *)(v10 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v6 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v6 + 64i64));
    prop_name.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rbp+57h+var_88.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&prop_name.Name.Flags = *(_QWORD *)&v27.Flags;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    prop_name.Name.value.VNumber = v6;
    prop_name.Name.value.VS._2 = v7;
    if ( v9 > 9 )
    {
      if ( (v5 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v9 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
      }
      else if ( v9 > 10 )
      {
        if ( v9 <= 15 )
        {
          if ( v6 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v6 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v6 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v9 <= 17 && v7.VObj )
        {
          v7.VObj->RefCount = (v7.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (prop_name.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &v30);
      if ( v30.pNode->Size )
      {
        if ( *v30.pNode->pData == 64 )
        {
          prop_name.Kind |= 8u;
          v11 = Scaleform::GFx::ASString::Substring(&v30, &v32, 1, v30.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v11);
          v12 = v32.pNode;
          v13 = v32.pNode->RefCount == 1;
          --v12->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        }
      }
      v14 = v30.pNode;
      v13 = v30.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
  }
  if ( v9 > 9 )
  {
    if ( (v5 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v27.Bonus.pWeakProxy = 0i64;
      v27.value = 0ui64;
      v27.Flags = v5 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  v15 = v33.pNode;
  v13 = v33.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = v2->Flags & 0x1F;
  v17 = v16
     && ((unsigned int)(v16 - 12) > 3 && v16 != 10 || *(_QWORD *)&v2->value.VNumber)
     && Scaleform::GFx::AS3::ExecutePropertyUnsafe((Scaleform::GFx::AS3::CheckResult *)&v30, v3, &prop_name, v2)->Result;
  if ( !v17
    || Scaleform::GFx::AS3::Value::Convert2String(&v28, (Scaleform::GFx::AS3::CheckResult *)&v30, &result)->Result )
  {
    v19 = v2->Flags & 0x1F;
    if ( !v19
      || ((unsigned int)(v19 - 12) <= 3 || v19 == 10) && !*(_QWORD *)&v2->value.VNumber
      || (v20 = result.pNode, !result.pNode->Size) )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v2, (Scaleform::GFx::AS3::CheckResult *)&v30, &result)->Result )
        goto LABEL_55;
      v20 = result.pNode;
    }
    v3->UI->vfptr->Output(v3->UI, Output_Error, v20->pData);
  }
LABEL_55:
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags >> 9) & 1 )
    {
      v21 = prop_name.Name.Bonus.pWeakProxy;
      v13 = prop_name.Name.Bonus.pWeakProxy->RefCount == 1;
      --v21->RefCount;
      if ( v13 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v21,
          v18);
      prop_name.Name.Bonus.pWeakProxy = 0i64;
      prop_name.Name.value = 0ui64;
      prop_name.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
    }
  }
  v22 = prop_name.Obj.pObject;
  if ( prop_name.Obj.pObject )
  {
    if ( (_QWORD)prop_name.Obj.pObject & 1 )
    {
      --prop_name.Obj.pObject;
    }
    else
    {
      v23 = prop_name.Obj.pObject->RefCount;
      if ( v23 & 0x3FFFFF )
      {
        prop_name.Obj.pObject->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
      }
    }
  }
  v24 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v24->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( (v28.Flags & 0x1F) > 9 )
  {
    if ( (v28.Flags >> 9) & 1 )
    {
      v25 = v28.Bonus.pWeakProxy;
      v13 = v28.Bonus.pWeakProxy->RefCount == 1;
      --v25->RefCount;
      if ( v13 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v25,
          v18);
      v28.Bonus.pWeakProxy = 0i64;
      v28.value = 0ui64;
      v28.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v28);
    }
  }
}

// File Line: 4728
// RVA: 0x7FE970
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(Scaleform::GFx::AS3::VM *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::ASString *v4; // rsi
  Scaleform::GFx::AS3::Abc::NamespaceKind v5; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rbp

  v4 = uri;
  v5 = kind;
  v6 = result;
  if ( uri->pNode->Size || kind )
  {
    v8 = this->TraitsNamespace.pObject->ITraits.pObject;
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v8[1].RefCount,
      v6,
      v5,
      v4,
      &v);
  }
  else
  {
    v7 = this->PublicNamespace.pObject;
    result->pV = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  return v6;
}

// File Line: 4738
// RVA: 0x7FEAB0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(Scaleform::GFx::AS3::VM *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::NamespaceKind kind, const char *name)
{
  Scaleform::GFx::AS3::Abc::NamespaceKind v4; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v5; // rsi
  Scaleform::GFx::AS3::VM *v6; // rdi
  char *v7; // r8
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v4 = kind;
  v5 = result;
  v6 = this;
  v7 = &customWorldMapCaption;
  if ( name )
    v7 = (char *)name;
  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
         &resulta,
         v7);
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(v6, v5, v4, v8);
  v9 = resulta.pNode;
  v10 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v5;
}

// File Line: 4744
// RVA: 0x7FEA40
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::VM::MakeInternedNamespace(Scaleform::GFx::AS3::VM *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::StringDataPtr *uri)
{
  Scaleform::GFx::AS3::Abc::NamespaceKind v4; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v5; // rsi
  Scaleform::GFx::AS3::VM *v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]

  v4 = kind;
  v5 = result;
  v6 = this;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
         &resulta,
         uri->pStr,
         uri->Size);
  Scaleform::GFx::AS3::VM::MakeInternedNamespace(v6, v5, v4, v7);
  v8 = resulta.pNode;
  v9 = resulta.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  return v5;
}

// File Line: 4750
// RVA: 0x7EA590
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::VM::GetInternedNamespace(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::GFx::ASString *uri)
{
  Scaleform::GFx::ASString *v3; // rbx
  __int64 v4; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // r14
  unsigned __int64 v7; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v10; // rbp
  signed __int64 v11; // rax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v12; // rax
  bool v13; // zf
  Scaleform::GFx::AS3::NamespaceKey key; // [rsp+28h] [rbp-20h]

  v3 = uri;
  v4 = kind;
  if ( !uri->pNode->Size && kind == NS_Public )
    return this->PublicNamespace.pObject;
  v6 = this->TraitsNamespace.pObject->ITraits.pObject;
  v7 = 0i64;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v8 = *(Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > **)&v6[1].RefCount;
  key.Kind = v4;
  v9 = v3->pNode;
  key.URI.pNode = v9;
  ++v9->RefCount;
  v10 = v8[2].pTable;
  if ( v10
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                v8 + 2,
                &key,
                v10->SizeMask & (v4 ^ 4 * (v9->HashFlags & 0xFFFFFF))),
        v11 >= 0) )
  {
    v7 = v10[v11 + 1].SizeMask;
  }
  else
  {
    v12 = v8[3].pTable;
    if ( v12 )
      v7 = *(_QWORD *)(v12[8].EntryCount + 424);
  }
  v13 = v9->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return (Scaleform::GFx::AS3::Instances::fl::Namespace *)v7;
}

// File Line: 4771
// RVA: 0x7F9BB0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *__fastcall Scaleform::GFx::AS3::VM::LoadFile(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *result, Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *file, Scaleform::GFx::AS3::VMAppDomain *appDomain, bool to_execute)
{
  Scaleform::GFx::AS3::VMAppDomain *v5; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *v6; // rbp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v7; // rdi
  Scaleform::GFx::AS3::VM *v8; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v9; // rax
  Scaleform::GFx::AS3::VMAbcFile *v10; // rax
  Scaleform::GFx::AS3::VMAbcFile *v11; // rbx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::MemoryHeap *resulta; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *v16; // [rsp+68h] [rbp+10h]

  v16 = result;
  v5 = appDomain;
  v6 = file;
  v7 = result;
  v8 = this;
  this->LoadingAbcFile = 1;
  resulta = this->MHeap;
  v9 = (Scaleform::GFx::AS3::VMAbcFile *)resulta->vfptr->Alloc((Scaleform::MemoryHeap *)this, 240ui64, 0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS3::VMAbcFile::VMAbcFile(v9, v8, v6, v5);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  if ( Scaleform::GFx::AS3::VMAbcFile::Load(v11, (Scaleform::GFx::AS3::CheckResult *)&resulta, to_execute)->Result )
  {
    v8->LoadingAbcFile = 0;
    v7->pObject = v11;
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
    if ( v11 )
    {
      if ( !((unsigned __int8)v11 & 1) )
      {
        v12 = v11->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          v11->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
        }
      }
    }
  }
  else
  {
    if ( v11 )
    {
      if ( !((unsigned __int8)v11 & 1) )
      {
        v13 = v11->RefCount;
        if ( v13 & 0x3FFFFF )
        {
          v11->RefCount = v13 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
        }
      }
    }
    v8->LoadingAbcFile = 0;
    v7->pObject = 0i64;
  }
  return v7;
}

// File Line: 4790
// RVA: 0x7E6BE0
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::VM::GetClass(Scaleform::GFx::AS3::VM *this, Scaleform::StringDataPtr *gname, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbp
  Scaleform::StringDataPtr *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::Class *v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // rax
  const char *v9; // rcx
  size_t v10; // r8
  __int64 v11; // r9
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // r8
  Scaleform::GFx::AS3::Class *v16; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *v17; // rax
  __int64 v18; // rax
  Scaleform::GFx::AS3::Class *result; // rax
  Scaleform::GFx::AS3::Class *v20; // rdi
  bool v21; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v22; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v23; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v24; // rbx
  Scaleform::StringDataPtr gnamea; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Value v26; // [rsp+38h] [rbp-40h]

  v3 = appDomain;
  v4 = gname;
  v5 = this;
  v6 = 0i64;
  if ( !gname->Size )
    return v6;
  if ( !(_S14_6 & 1) )
  {
    _S14_6 |= 1u;
    vecPref.pStr = "Vector.<";
    vecPref.Size = 8i64;
  }
  v7 = gname->Size;
  if ( v7 <= vecPref.Size )
    goto LABEL_33;
  v8 = v7 - vecPref.Size;
  if ( v7 < v7 - vecPref.Size )
    v8 = gname->Size;
  v9 = gname->pStr;
  v10 = v7 - v8;
  if ( vecPref.Size != v10 || vecPref.pStr != v9 && (!v9 || !vecPref.pStr || strncmp(v9, vecPref.pStr, v10)) )
  {
LABEL_33:
    Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&v26, v5, v4);
    v22 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, (Scaleform::GFx::AS3::Multiname *)&v26, v3);
    v23 = v22;
    if ( v22 )
    {
      v22->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
      if ( !v5->HandleException )
      {
        v24 = v23->ITraits.pObject;
        if ( !v24->pConstructor.pObject )
          v24->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v23->ITraits.pObject->vfptr);
        v6 = v24->pConstructor.pObject;
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&v26);
    return v6;
  }
  v11 = Scaleform::StringDataPtr::FindLastChar(v4, 62, 0xFFFFFFFFFFFFFFFFui64);
  if ( v11 <= 0 )
    return v6;
  v12 = v4->Size;
  v13 = vecPref.Size;
  if ( v12 < vecPref.Size )
    v13 = v4->Size;
  v14 = v12 - v13;
  v15 = v12 - v11;
  if ( v14 < v15 )
    v15 = v14;
  gnamea.pStr = &v4->pStr[v13];
  gnamea.Size = v14 - v15;
  v16 = Scaleform::GFx::AS3::VM::GetClass(v5, &gnamea, v3);
  if ( !v16 )
    return v6;
  v26.Flags = 13;
  v26.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v26.value.VNumber = v16;
  v16->RefCount = (v16->RefCount + 1) & 0x8FBFFFFF;
  v17 = Scaleform::GFx::AS3::VM::GetClassVector(v5);
  v18 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Classes::fl_vec::Vector *, signed __int64, Scaleform::GFx::AS3::Value *))v17->vfptr[7].~RefCountBaseGC<328>)(
          v17,
          1i64,
          &v26);
  result = Scaleform::GFx::AS3::Traits::GetConstructor(*(Scaleform::GFx::AS3::Traits **)(v18 + 200));
  v20 = result;
  if ( (v26.Flags & 0x1F) > 9 )
  {
    if ( (v26.Flags >> 9) & 1 )
    {
      v21 = v26.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v26.Bonus.pWeakProxy = 0i64;
      v26.value = 0ui64;
      v26.Flags &= 0xFFFFFDE0;
      result = v20;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
      result = v20;
    }
  }
  return result;
}

// File Line: 4855
// RVA: 0x7B8F60
bool __fastcall Scaleform::GFx::AS3::VM::Construct(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Class *cl, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool extCall)
{
  unsigned __int64 v6; // rbp
  Scaleform::GFx::AS3::VM *v7; // rsi
  bool v8; // ST20_1
  bool v9; // al

  v6 = this->CallStack.Size;
  v7 = this;
  v8 = extCall;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, bool))cl->vfptr[4].ForEachChild_GC)(
    cl,
    result,
    argc,
    argv,
    v8);
  if ( v7->HandleException )
    v9 = 0;
  else
    v9 = v7->CallStack.Size > v6;
  return v9;
}

// File Line: 4868
// RVA: 0x7B8FE0
_BOOL8 __fastcall Scaleform::GFx::AS3::VM::Construct(Scaleform::GFx::AS3::VM *this, const char *gname, Scaleform::GFx::AS3::VMAppDomain *appDomain, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool extCall)
{
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rdi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rax
  bool v12; // di
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::StringDataPtr gnamea; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::AS3::Value v19; // [rsp+58h] [rbp-30h]

  v7 = result;
  v8 = this;
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
  v11 = Scaleform::GFx::AS3::VM::GetClass(this, &gnamea, appDomain);
  if ( v11 )
  {
    v9 = 13;
    v19.Flags = 13;
    *(_QWORD *)&v19.value.VNumber = v11;
    v19.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v18.Message.pNode;
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
    v12 = Scaleform::GFx::AS3::VM::Construct(v8, v11, v7, argc, argv, extCall);
  }
  else
  {
    if ( !v8->HandleException )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, eUndefinedVarError, v8);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v13, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v14 = v18.Message.pNode;
      v15 = v18.Message.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v12 = 0;
  }
  if ( (char)(v9 & 0x1F) > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v19.Bonus.pWeakProxy = 0i64;
      v19.value = 0ui64;
      v19.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
    }
  }
  return v12;
}

// File Line: 4890
// RVA: 0x831D60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VM::constructBuiltinObject(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *pobj, const char *gname, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v6; // rdi
  Scaleform::GFx::AS3::CheckResult *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rsi
  char v9; // bp
  int v10; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v11; // rcx
  unsigned int v12; // eax
  bool v13; // zf
  Scaleform::GFx::AS3::Value v15; // [rsp+48h] [rbp-30h]

  v6 = pobj;
  v7 = result;
  v8 = this;
  v9 = 0;
  v15.Flags = 0;
  v15.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::VM::Construct(this, gname, this->CurrentDomain.pObject, &v15, argc, argv, 1);
  if ( !v8->HandleException
    && (v10 = v15.Flags & 0x1F) != 0
    && ((unsigned int)(v10 - 12) > 3 && v10 != 10 || *(_QWORD *)&v15.value.VNumber) )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v15.value.VS._1.VStr);
    v9 = 1;
  }
  else
  {
    v11.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6->pObject;
    if ( v6->pObject )
    {
      if ( (_QWORD)v11.pObject & 1 )
      {
        v6->pObject = (Scaleform::GFx::AS3::Object *)((char *)&v11.pObject[-1].List.Data.Policy.Capacity + 7);
      }
      else
      {
        v12 = v11.pObject->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          v11.pObject->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11.pObject->vfptr);
        }
      }
      v6->pObject = 0i64;
    }
    if ( v8->HandleException )
      v8->HandleException = 0;
  }
  v7->Result = v9;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags >> 9) & 1 )
    {
      v13 = v15.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v15.Bonus.pWeakProxy = 0i64;
      v15.value = 0ui64;
      v15.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
    }
  }
  return v7;
}

// File Line: 4914
// RVA: 0x7F1030
Scaleform::GFx::AS3::Traits *__fastcall Scaleform::GFx::AS3::VM::GetValueTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // er9
  Scaleform::GFx::AS3::Traits *result; // rax

  v2 = v->Flags & 0x1F;
  switch ( v2 )
  {
    case 1u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsBoolean.pObject->ITraits.pObject->vfptr;
      break;
    case 2u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsInt.pObject->ITraits.pObject->vfptr;
      break;
    case 3u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsUint.pObject->ITraits.pObject->vfptr;
      break;
    case 4u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsNumber.pObject->ITraits.pObject->vfptr;
      break;
    case 5u:
    case 0x10u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsFunction.pObject->ThunkTraits.pObject->vfptr;
      break;
    case 7u:
    case 0x11u:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsFunction.pObject->VTableTraits.pObject->vfptr;
      break;
    case 8u:
    case 9u:
      result = (Scaleform::GFx::AS3::Traits *)v->value.VS._1.VStr;
      break;
    case 0xAu:
      if ( !*(_QWORD *)&v->value.VNumber )
        goto LABEL_8;
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsString.pObject->ITraits.pObject->vfptr;
      break;
    case 0xBu:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsNamespace.pObject->ITraits.pObject->vfptr;
      break;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v2 - 12 > 3 && v2 != 10 || *(_QWORD *)&v->value.VNumber )
        result = *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v->value.VNumber + 40i64);
      else
LABEL_8:
        result = (Scaleform::GFx::AS3::Traits *)&this->TraitsObject.pObject->ITraits.pObject->vfptr;
      break;
    default:
      result = (Scaleform::GFx::AS3::Traits *)&this->TraitsVoid.pObject->vfptr;
      break;
  }
  return result;
}

// File Line: 5019
// RVA: 0x7E7100
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetClassTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *result; // rax
  long double v3; // rbx
  _QWORD *v4; // rbx

  switch ( v->Flags & 0x1F )
  {
    case 1u:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsBoolean.pObject->vfptr;
      break;
    case 2u:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsInt.pObject->vfptr;
      break;
    case 3u:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsUint.pObject->vfptr;
      break;
    case 4u:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsNumber.pObject->vfptr;
      break;
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsFunction.pObject->vfptr;
      break;
    case 9u:
      result = v->value.VS._1.CTr;
      break;
    case 0xAu:
      if ( *(_QWORD *)&v->value.VNumber )
        result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsString.pObject->vfptr;
      else
        result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsObject.pObject->vfptr;
      break;
    case 0xBu:
      result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsNamespace.pObject->vfptr;
      break;
    case 0xDu:
      result = *(Scaleform::GFx::AS3::ClassTraits::Traits **)(*(_QWORD *)&v->value.VNumber + 40i64);
      break;
    default:
      v3 = v->value.VNumber;
      if ( v3 == 0.0 )
      {
        result = (Scaleform::GFx::AS3::ClassTraits::Traits *)&this->TraitsObject.pObject->vfptr;
      }
      else
      {
        v4 = *(_QWORD **)(*(_QWORD *)&v3 + 40i64);
        if ( !v4[17] )
          (*(void (__fastcall **)(_QWORD *))(*v4 + 80i64))(v4);
        result = *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v4[17] + 40i64);
      }
      break;
  }
  return result;
}

// File Line: 5067
// RVA: 0x7EA430
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetInstanceTraits(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // er9
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
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&this->TraitsFunction.pObject->ThunkTraits.pObject->vfptr;
      break;
    case 7u:
    case 0x11u:
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&this->TraitsFunction.pObject->VTableTraits.pObject->vfptr;
      break;
    case 8u:
      result = v->value.VS._1.ITr;
      break;
    case 9u:
      result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_QWORD *)&v->value.VNumber + 200i64);
      if ( !result )
        goto LABEL_22;
      break;
    case 0xAu:
      if ( !*(_QWORD *)&v->value.VNumber )
        goto LABEL_8;
      result = this->TraitsString.pObject->ITraits.pObject;
      break;
    case 0xBu:
      result = this->TraitsNamespace.pObject->ITraits.pObject;
      break;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      if ( (v2 - 12 <= 3 || v2 == 10) && !*(_QWORD *)&v->value.VNumber )
        goto LABEL_8;
      result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_QWORD *)&v->value.VNumber + 40i64);
      break;
    case 0xDu:
      if ( v2 - 12 > 3 && v2 != 10 || *(_QWORD *)&v->value.VNumber )
        result = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_QWORD *)(*(_QWORD *)&v->value.VNumber + 40i64)
                                                                 + 200i64);
      else
LABEL_8:
        result = this->TraitsObject.pObject->ITraits.pObject;
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
Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *__fastcall Scaleform::GFx::AS3::VM::GetGlobalObject(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::CallFrame *v1; // r8
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v2; // rax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *result; // rax
  Scaleform::GFx::AS3::Value *v4; // rcx

  if ( !this->CallStack.Size )
    goto LABEL_9;
  v1 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  v2 = v1->pSavedScope;
  if ( v2->Data.Size )
    return (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v2->Data.Data->value.VS._1.VStr;
  v4 = v1->pRegisterFile->pRF;
  if ( (v4->Flags & 0x1F) - 12 <= 3 )
    result = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v4->value.VS._1.VStr;
  else
LABEL_9:
    result = 0i64;
  return result;
}

// File Line: 5240
// RVA: 0x7E7960
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VM::GetDefaultValue(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::ClassTraits::Traits *ctr)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rax
  int v5; // ecx
  long double v6; // rcx
  long double v7; // xmm0_8

  v3 = result;
  switch ( ctr->TraitsType )
  {
    case 1:
      result->Flags = 1;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VBool = 0;
      return v3;
    case 2:
      result->Flags = 2;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VInt = 0;
      return v3;
    case 3:
      result->Flags = 3;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VInt = 0;
      return v3;
    case 4:
      v7 = Scaleform::GFx::NumberUtil::NaN();
      v3->Flags = 4;
      v3->Bonus.pWeakProxy = 0i64;
      v3->value.VNumber = v7;
      return v3;
  }
  if ( ctr == (Scaleform::GFx::AS3::ClassTraits::Traits *)this->TraitsClassClass.pObject )
    v4 = Scaleform::GFx::AS3::Value::GetUndefined();
  else
    v4 = Scaleform::GFx::AS3::Value::GetNull();
  v3->Flags = v4->Flags;
  v3->Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  v3->value.VNumber = v4->value.VNumber;
  v3->value.VS._2.VObj = v4->value.VS._2.VObj;
  v5 = v4->Flags & 0x1F;
  if ( v5 > 9 )
  {
    if ( (v4->Flags >> 9) & 1 )
    {
      ++v4->Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v5 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
        return v3;
      }
      if ( v5 > 10 )
      {
        if ( v5 <= 15 )
        {
          v6 = v4->value.VNumber;
        }
        else
        {
          if ( v5 > 17 )
            return v3;
          v6 = *(double *)&v4->value.VS._2.VObj;
        }
        if ( v6 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v6 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v6 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
  return v3;
}

// File Line: 5267
// RVA: 0x7E7820
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VM::GetDefaultValue(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rax
  int v7; // eax
  long double v8; // rax

  v4 = result;
  v5 = this;
  if ( (*(_QWORD *)&mn->NameIndex || mn->Ind)
    && (v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this, (Scaleform::GFx::AS3::VMFile *)&file->vfptr, mn)) != 0i64 )
  {
    Scaleform::GFx::AS3::VM::GetDefaultValue(v5, v4, v6);
  }
  else
  {
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v4->Flags = v.Flags;
    v4->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v4->value = v.value;
    v7 = v.Flags & 0x1F;
    if ( v7 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( v7 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
          return v4;
        }
        if ( v7 > 10 )
        {
          if ( v7 <= 15 )
          {
            v8 = v.value.VNumber;
          }
          else
          {
            if ( v7 > 17 )
              return v4;
            v8 = *(double *)&v.value.VS._2.VObj;
          }
          if ( v8 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v8 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v8 + 32i64) &= 0x8FBFFFFF;
          }
        }
      }
    }
  }
  return v4;
}

// File Line: 5281
// RVA: 0x7E9A10
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetFunctReturnType(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::ThunkInfo *thunk, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::TypeInfo *v5; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v6; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v9; // rax
  _QWORD *v10; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v12; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  __int64 v17; // rdi
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v23; // [rsp+20h] [rbp-30h]
  __int64 v24; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::ASStringNode *v25; // [rsp+30h] [rbp-20h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // [rsp+38h] [rbp-18h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+28h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v29; // [rsp+88h] [rbp+38h]

  v24 = -2i64;
  v3 = appDomain;
  v4 = this;
  v5 = *thunk->ArgType;
  if ( !v5 )
    return v4->TraitsObject.pObject->ITraits.pObject;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
    &result,
    v5->Name);
  v6 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(v4, &v23, 0, v5->PkgName);
  v7 = v6->pV;
  v29 = v6->pV;
  v8 = v3->ParentDomain;
  if ( (!v8 || (v9 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v8, &result, v7)) == 0i64)
    && (v9 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
               &v3->ClassTraitsSet,
               &result,
               v7)) == 0i64
    || (v10 = *v9) == 0i64 )
  {
    v11 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                                                             v4->GlobalObject.pObject,
                                                             &result,
                                                             v7);
    v10 = &v11->vfptr;
    if ( v11 )
    {
      v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v4->SystemDomain.pObject;
      v23.pV = v11;
      v25 = result.pNode;
      ++v25->RefCount;
      v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr;
      if ( v7 )
        v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
      key.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v25;
      key.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v23;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
        v12 + 6,
        v12[7].pTable,
        &key,
        v25->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v26[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v26[1].vfptr << 60 >> 60));
      v13 = v26;
      if ( v26 )
      {
        if ( (unsigned __int8)v26 & 1 )
        {
          v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v26 - 1);
        }
        else
        {
          v14 = v26->RefCount;
          if ( v14 & 0x3FFFFF )
          {
            v26->RefCount = v14 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
      v15 = v25;
      v16 = v25->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_16;
    }
    if ( v7 )
    {
      if ( (unsigned __int8)v7 & 1 )
      {
        v29 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v7 - 1);
      }
      else
      {
        v21 = v7->RefCount;
        if ( v21 & 0x3FFFFF )
        {
          v7->RefCount = v21 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
        }
      }
    }
    v22 = result.pNode;
    v16 = result.pNode->RefCount == 1;
    --v22->RefCount;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    return v4->TraitsObject.pObject->ITraits.pObject;
  }
LABEL_16:
  v17 = v10[25];
  if ( v7 )
  {
    if ( (unsigned __int8)v7 & 1 )
    {
      v29 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v7 - 1);
    }
    else
    {
      v18 = v7->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v7->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
      }
    }
  }
  v19 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  return (Scaleform::GFx::AS3::InstanceTraits::Traits *)v17;
}

// File Line: 5300
// RVA: 0x7E9C20
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetFunctReturnType(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbp
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::VM *v5; // rdi
  __int64 v6; // r10
  _QWORD *v7; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *v8; // r8
  Scaleform::GFx::AS3::VMFile *v9; // rdx
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rax
  __int64 v12; // rbx

  v3 = appDomain;
  v4 = value->Flags & 0x1F;
  v5 = this;
  switch ( v4 )
  {
    case 5u:
    case 0x10u:
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(v5, value->value.VS._1.VThunk, appDomain);
    case 6u:
      goto $LN6_92;
    case 7u:
    case 0x11u:
      value = &Scaleform::GFx::AS3::Traits::GetVT(value->value.VS._2.pTraits)->VTMethods.Data.Data[value->value.VS._1.VUInt];
      if ( (value->Flags & 0x1F) == 6 )
      {
$LN6_92:
        v12 = value->value.VS._1.VInt;
        v9 = (Scaleform::GFx::AS3::VMFile *)((__int64 (*)(void))value->value.VS._2.VObj->vfptr[2].~RefCountBaseGC<328>)();
        v8 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)v9[1].vfptr[7].~RefCountBaseGC<328>
                                                   + 16
                                                   * *(signed int *)(*((_QWORD *)v9[1].vfptr[9].~RefCountBaseGC<328>
                                                                     + v12)
                                                                   + 4i64));
LABEL_3:
        v10 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, v9, v8);
        if ( v10 )
          return v10->ITraits.pObject;
        goto LABEL_4;
      }
      if ( v4 != 7 && v4 != 17 )
      {
LABEL_4:
        v10 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->TraitsObject.pObject->vfptr;
        return v10->ITraits.pObject;
      }
      appDomain = v3;
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(v5, value->value.VS._1.VThunk, appDomain);
    case 0xEu:
      v6 = *(_QWORD *)(*(_QWORD *)&value->value.VNumber + 40i64);
      v7 = *(_QWORD **)(*(_QWORD *)(v6 + 248) + 152i64);
      v8 = (Scaleform::GFx::AS3::Abc::Multiname *)(v7[22]
                                                 + 16i64
                                                 * *(signed int *)(*(_QWORD *)(v7[28]
                                                                             + 8i64
                                                                             * *(signed int *)(*(_QWORD *)(v7[43] + 8i64 * *(signed int *)(*(_QWORD *)(v7[28] + 8i64 * *(signed int *)(v6 + 240)) + 8i64))
                                                                                             + 24i64))
                                                                 + 4i64));
      v9 = *(Scaleform::GFx::AS3::VMFile **)(v6 + 248);
      goto LABEL_3;
    case 0xFu:
      return Scaleform::GFx::AS3::VM::GetFunctReturnType(
               this,
               *(Scaleform::GFx::AS3::ThunkInfo **)(*(_QWORD *)&value->value.VNumber + 64i64),
               appDomain);
    default:
      goto LABEL_4;
  }
}

// File Line: 5461
// RVA: 0x7E72C0
void __fastcall Scaleform::GFx::AS3::VM::GetCodeFileName(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  unsigned __int64 v3; // r9
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v2 = result;
  v3 = this->CallStack.Size - 1;
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(
         result->pNode->pManager,
         (const char *)((this->CallStack.Pages[v3 >> 6][v3 & 0x3F].pFile->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                      + 12),
         *(_QWORD *)(this->CallStack.Pages[v3 >> 6][v3 & 0x3F].pFile->File.pObject->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v5 = v4;
  ++v4->RefCount;
  v6 = v2->pNode;
  v7 = v2->pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v2->pNode = v5;
  }
  else
  {
    v2->pNode = v4;
  }
}

// File Line: 5546
// RVA: 0x8347E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::VM::describeTypeEx(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::StringManager *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx

  v3 = this->StringManagerRef;
  v4 = v3->Builtins[0].pNode;
  result->pNode = v3->Builtins[0].pNode;
  ++v4->RefCount;
  return result;
}

// File Line: 5756
// RVA: 0x7E7240
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::VM::GetClassVector(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v1; // rbx

  v1 = this->TraitsVector.pObject->ITraits.pObject;
  if ( !v1->pConstructor.pObject )
    v1->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v1->vfptr);
  return v1->pConstructor.pObject;
}

// File Line: 5766
// RVA: 0x7EA290
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorSInt(Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_int.pObject->ITraits.pObject;
}

// File Line: 5776
// RVA: 0x7EA2B0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorUInt(Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_uint.pObject->ITraits.pObject;
}

// File Line: 5786
// RVA: 0x7EA280
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorNumber(Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_Number.pObject->ITraits.pObject;
}

// File Line: 5796
// RVA: 0x7EA2A0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::VM::GetITraitsVectorString(Scaleform::GFx::AS3::VM *this)
{
  return this->TraitsVector_String.pObject->ITraits.pObject;
}

// File Line: 5811
// RVA: 0x8257C0
void __fastcall Scaleform::GFx::AS3::VM::ThrowErrorInternal(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e, Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::AS3::TypeInfo *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // r12
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::ASString *v6; // r13
  Scaleform::GFx::AS3::VMAppDomain *v7; // r14
  const char *v8; // r8
  Scaleform::GFx::ASString *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v11; // r15
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *v12; // r15
  Scaleform::GFx::ASStringNode *v13; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v14; // r14
  signed __int64 v15; // rax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v16; // rax
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v19; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  int v22; // eax
  Scaleform::GFx::AS3::WeakProxy *v23; // rdx
  Scaleform::GFx::AS3::NamespaceKey key; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS3::Value other; // [rsp+38h] [rbp-41h]
  int ptr; // [rsp+60h] [rbp-19h]
  __int64 v27; // [rsp+68h] [rbp-11h]
  Scaleform::GFx::AS3::NamespaceKey v28; // [rsp+70h] [rbp-9h]
  int v29; // [rsp+80h] [rbp+7h]
  __int64 v30; // [rsp+88h] [rbp+Fh]
  int v31; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS3::VMAppDomain *v32; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::ASString v33; // [rsp+E8h] [rbp+6Fh]
  Scaleform::GFx::ASString result; // [rsp+F0h] [rbp+77h]

  v3 = ti;
  v4 = e;
  v5 = this;
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
         &result,
         ti->Name);
  v7 = v5->CurrentDomain.pObject;
  v32 = v5->CurrentDomain.pObject;
  v8 = &customWorldMapCaption;
  if ( v3->PkgName )
    v8 = v3->PkgName;
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
         &v33,
         v8);
  if ( v9->pNode->Size )
  {
    v11 = v5->TraitsNamespace.pObject->ITraits.pObject;
    if ( _S11_12 & 1 )
    {
      v10 = 0i64;
    }
    else
    {
      _S11_12 |= 1u;
      v10 = 0i64;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v12 = *(Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > **)&v11[1].RefCount;
    key.Kind = (unsigned int)v10;
    v13 = v9->pNode;
    key.URI.pNode = v13;
    ++v13->RefCount;
    v14 = v12[2].pTable;
    if ( v14
      && (v15 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                  v12 + 2,
                  &key,
                  v14->SizeMask & 4 * (v13->HashFlags & 0xFFFFFF)),
          v15 >= 0) )
    {
      v10 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v14[v15 + 1].SizeMask;
    }
    else
    {
      v16 = v12[3].pTable;
      if ( v16 )
        v10 = *(Scaleform::GFx::AS3::Instances::fl::Namespace **)(v16[8].EntryCount + 424);
    }
    v17 = v13->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v7 = v32;
  }
  else
  {
    v10 = v5->PublicNamespace.pObject;
  }
  v18 = v33.pNode;
  v17 = v33.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, v6, v10, v7);
  v20 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  other.Flags = 0;
  other.Bonus.pWeakProxy = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v19->ITraits.pObject->vfptr[3].Finalize_GC)(
    v19->ITraits.pObject,
    &other,
    v19->ITraits.pObject);
  ptr = 10;
  v27 = 0i64;
  v21 = v4->Message.pNode;
  *(_QWORD *)&v28.Kind = v21;
  if ( v21 == &v21->pManager->NullStringNode )
  {
    *(_QWORD *)&key.Kind = 0i64;
    v28 = key;
    ptr = 12;
  }
  else
  {
    ++v21->RefCount;
  }
  v22 = v4->ID;
  v29 = 2;
  v30 = 0i64;
  v31 = v22;
  (*((void (__fastcall **)(_QWORD, signed __int64, int *))other.value.VS._1.VStr->pData + 11))(
    *(_QWORD *)&other.value.VNumber,
    2i64,
    &ptr);
  v5->HandleException = 1;
  Scaleform::GFx::AS3::Value::Assign(&v5->ExceptionObj, &other);
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v23 = other.Bonus.pWeakProxy;
      v17 = other.Bonus.pWeakProxy->RefCount == 1;
      --v23->RefCount;
      if ( v17 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v23);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::VM::ThrowRangeError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::RangeErrorTI);
}

// File Line: 5845
// RVA: 0x825A60
void __fastcall Scaleform::GFx::AS3::VM::ThrowReferenceError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
}

// File Line: 5860
// RVA: 0x825A70
void __fastcall Scaleform::GFx::AS3::VM::ThrowTypeError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::TypeErrorTI);
}

// File Line: 5870
// RVA: 0x825A80
void __fastcall Scaleform::GFx::AS3::VM::ThrowVerifyError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
}

// File Line: 5880
// RVA: 0x8257A0
void __fastcall Scaleform::GFx::AS3::VM::ThrowArgumentError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::VM::Error *e)
{
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, e, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
}

// File Line: 6062
// RVA: 0x77C950
void __fastcall Scaleform::GFx::AS3::VM::Error::Error(Scaleform::GFx::AS3::VM::Error *this, Scaleform::GFx::AS3::VM::ErrorID id, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v3; // rdi
  int v4; // ebx
  Scaleform::GFx::AS3::VM::Error *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-448h]
  __int64 v11; // [rsp+38h] [rbp-430h]
  Scaleform::MsgFormat v12; // [rsp+40h] [rbp-428h]
  int v; // [rsp+478h] [rbp+10h]
  Scaleform::String str; // [rsp+480h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+488h] [rbp+20h]

  v11 = -2i64;
  v3 = vm;
  v4 = id;
  v5 = this;
  this->ID = id;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &this->Message);
  Scaleform::String::String(&str);
  v = v4;
  r.Type = 0;
  r.SinkData.pStr = &str;
  Scaleform::MsgFormat::MsgFormat(&v12, &r);
  Scaleform::MsgFormat::Parse(&v12, "Error #{0}");
  Scaleform::MsgFormat::FormatD1<long>(&v12, &v);
  Scaleform::MsgFormat::FinishFormatD(&v12);
  Scaleform::MsgFormat::~MsgFormat(&v12);
  v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->StringManagerRef->Builtins,
         &result,
         &str)->pNode;
  ++v6->RefCount;
  v7 = v5->Message.pNode;
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v5->Message.pNode = v6;
  v9 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 6112
// RVA: 0x72E060
void __fastcall Scaleform::GFx::AS3::ThunkInfo::EmptyFunc(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v5; // rdi
  const char *v6; // rdx
  const char *v7; // rdx
  Scaleform::String v8; // [rsp+40h] [rbp+8h]

  v4 = vm;
  v5 = ti;
  Scaleform::String::String(&v8, "The method ");
  v6 = v5->NamespaceName;
  if ( v6 )
  {
    Scaleform::String::AppendString(&v8, v6, -1i64);
    Scaleform::String::AppendString(&v8, "::", -1i64);
  }
  v7 = v5->Name;
  if ( v7 )
  {
    Scaleform::String::AppendString(&v8, v7, -1i64);
    Scaleform::String::AppendString(&v8, "()", -1i64);
  }
  Scaleform::String::AppendString(&v8, " is not implemented\n", -1i64);
  v4->UI->vfptr->Output(v4->UI, Output_Warning, (const char *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 6138
// RVA: 0x81AC30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SetProperty(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  long double v7; // rcx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+48h] [rbp-38h]

  v5 = vm;
  v6 = result;
  if ( (_this->Flags & 0x1F) - 12 > 3 || (v7 = _this->value.VNumber, v7 == 0.0) )
  {
    resulta.pSI = 0i64;
    resulta.SlotIndex = 0i64;
    resulta.This.Flags = 0;
    resulta.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&resulta, vm, _this, prop_name, FindSet);
    if ( resulta.This.Flags & 0x1F
      && (!((_QWORD)resulta.pSI & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!((LOBYTE(resulta.pSI) >> 1) & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
    {
      Scaleform::GFx::AS3::PropRef::SetSlotValue(&resulta, v6, v5, value);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eWriteSealedError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v9 = v12.Message.pNode;
      v10 = v12.Message.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v6->Result = 0;
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags >> 9) & 1 )
      {
        v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.This.Bonus.pWeakProxy = 0i64;
        resulta.This.value = 0ui64;
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
  }
  else
  {
    (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v7 + 24i64))(
      COERCE_LONG_DOUBLE(*(_QWORD *)&v7),
      v6,
      prop_name,
      value);
  }
  return v6;
}

// File Line: 6169
// RVA: 0x7EE5E0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetPropertyUnsafe(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  long double v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+38h] [rbp-38h]

  v5 = vm;
  v6 = result;
  if ( (_this->Flags & 0x1F) - 12 > 3 || (v7 = _this->value.VNumber, v7 == 0.0) )
  {
    resulta.pSI = 0i64;
    resulta.SlotIndex = 0i64;
    resulta.This.Flags = 0;
    resulta.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&resulta, vm, _this, prop_name, 0);
    if ( resulta.This.Flags & 0x1F
      && (!((_QWORD)resulta.pSI & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
      && (!((LOBYTE(resulta.pSI) >> 1) & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
    {
      Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, v6, v5, value, 0);
    }
    else
    {
      v6->Result = 0;
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags >> 9) & 1 )
      {
        v8 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v8 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.This.Bonus.pWeakProxy = 0i64;
        resulta.This.value = 0ui64;
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
  }
  else
  {
    (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v7 + 32i64))(
      COERCE_LONG_DOUBLE(*(_QWORD *)&v7),
      v6,
      prop_name,
      value);
  }
  return v6;
}

// File Line: 6196
// RVA: 0x81AE10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::SetProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  Scaleform::GFx::AS3::Multiname *v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::Object *v7; // rdi
  Scaleform::GFx::AS3::VM *v8; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::Value scope; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+40h] [rbp+Fh]

  v4 = value;
  v5 = prop_name;
  v6 = result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  resulta.pSI = 0i64;
  resulta.SlotIndex = 0i64;
  resulta.This.Flags = 0;
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&scope.value.VNumber = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, this->pTraits.pObject->pVM, &scope, prop_name, FindSet);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  if ( resulta.This.Flags & 0x1F
    && (!((_QWORD)resulta.pSI & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(resulta.pSI) >> 1) & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    Scaleform::GFx::AS3::PropRef::SetSlotValue(&resulta, v6, v8, v4);
  }
  else if ( (LOBYTE(v7->pTraits.pObject->Flags) >> 1) & 1
         && Scaleform::GFx::AS3::Multiname::ContainsNamespace(v5, v8->PublicNamespace.pObject) )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, _QWORD))v7->vfptr[4].Finalize_GC)(
      v7,
      &v5->Name,
      v4,
      0i64,
      *(_QWORD *)&scope.Flags);
    v6->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&scope, eWriteSealedError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v9, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v10 = (Scaleform::GFx::ASStringNode *)scope.Bonus.pWeakProxy;
    v11 = LODWORD(scope.Bonus.pWeakProxy[1].pObject) == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v6->Result = 0;
  }
  if ( (resulta.This.Flags & 0x1F) > 9 )
  {
    if ( (resulta.This.Flags >> 9) & 1 )
    {
      v11 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      resulta.This.Bonus.pWeakProxy = 0i64;
      resulta.This.value = 0ui64;
      resulta.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
    }
  }
  return v6;
}

// File Line: 6232
// RVA: 0x7EDC60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rsi
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Value::Extra v8; // rax
  Scaleform::GFx::AS3::Value::VU v9; // kr00_16
  bool v10; // zf
  Scaleform::GFx::AS3::Value scope; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::AS3::CheckResult v14; // [rsp+98h] [rbp+67h]

  v4 = value;
  v5 = result;
  v6 = this->pTraits.pObject->pVM;
  resulta.pSI = 0i64;
  resulta.SlotIndex = 0i64;
  resulta.This.Flags = 0;
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&scope.value.VNumber = this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, v6, &scope, prop_name, 0);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
  if ( !(resulta.This.Flags & 0x1F)
    || (_QWORD)resulta.pSI & 1 && !((_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
    || (LOBYTE(resulta.pSI) >> 1) & 1 && !((_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
LABEL_20:
    v5->Result = 0;
    goto LABEL_21;
  }
  scope.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, &v14, v6, &scope, 0)->Result )
  {
    if ( (scope.Flags & 0x1F) > 9 )
    {
      if ( (scope.Flags >> 9) & 1 )
      {
        v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        scope.Bonus.pWeakProxy = 0i64;
        scope.value = 0ui64;
        scope.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
      }
    }
    goto LABEL_20;
  }
  v7 = scope.Flags;
  v8.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)scope.Bonus;
  v9 = scope.value;
  scope.Flags = v4->Flags;
  scope.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  scope.value = v4->value;
  v4->Flags = v7;
  v4->Bonus = v8;
  v4->value = v9;
  v5->Result = 1;
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags >> 9) & 1 )
    {
      v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      scope.Bonus.pWeakProxy = 0i64;
      scope.value = 0ui64;
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
    if ( (resulta.This.Flags >> 9) & 1 )
    {
      v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      resulta.This.Bonus.pWeakProxy = 0i64;
      resulta.This.value = 0ui64;
      resulta.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
    }
  }
  return v5;
}

// File Line: 6255
// RVA: 0x7E9370
void __fastcall Scaleform::GFx::AS3::Object::GetDynamicProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v3; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v6; // rcx
  unsigned __int64 v7; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  v3 = &this->DynAttrs;
  v4 = 0i64;
  v5 = value;
  v6 = this->DynAttrs.mHash.pTable;
  if ( v6 )
  {
    v7 = v6->SizeMask;
    v8 = v6 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 4;
    }
    while ( (unsigned __int64)v4 <= v7 );
    v4 = v3;
  }
  Scaleform::GFx::AS3::Value::Assign(
    v5,
    (Scaleform::GFx::AS3::Value *)&v4->mHash.pTable[4 * (unsigned __int64)LODWORD(ind.Index) + 3]);
}

// File Line: 6263
// RVA: 0x7C0E20
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::DeleteProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rax

  v3 = result;
  if ( (LOBYTE(this->pTraits.pObject->Flags) >> 1) & 1 )
  {
    Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(this, result, prop_name);
    v4 = v3;
  }
  else
  {
    result->Result = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 6326
// RVA: 0x7B6BA0
void __fastcall Scaleform::GFx::AS3::Impl::CoerceInternal(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::TypeInfo *ti, Scaleform::GFx::AS3::Value *to, Scaleform::GFx::AS3::Value *from)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rax

  v4 = from;
  v5 = to;
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, ti);
  if ( !v6
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v6->vfptr[3].Finalize_GC)(
          v6,
          v4,
          v5) )
  {
    Scaleform::GFx::AS3::Value::Assign(v5, v4);
  }
}

