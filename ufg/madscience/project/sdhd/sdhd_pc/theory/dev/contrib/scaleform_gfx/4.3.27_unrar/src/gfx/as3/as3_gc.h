// File Line: 185
// RVA: 0x810E00
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rax

  v2 = *pchild;
  if ( (--v2->RefCount & 0x3FFFFF) != 0 )
  {
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*pchild);
  }
  else
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(prcc, *pchild);
    (*pchild)->RefCount |= 0x800000u;
    Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
  }
}

// File Line: 203
// RVA: 0x800C40
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  --(*pchild)->RefCount;
  Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
}

// File Line: 211
// RVA: 0x817420
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  __int64 v2; // rdx

  if ( (++(*pchild)->RefCount & 0x70000000) != 0 )
  {
    (*pchild)->RefCount &= 0x8FFFFFFF;
    v2 = (__int64)*pchild;
    if ( (*(_BYTE *)(v2 + 35) & 1) != 0 )
    {
      *(_QWORD *)(*(_QWORD *)(v2 + 24) + 16i64) = *(_QWORD *)(v2 + 16);
      *(_QWORD *)(*(_QWORD *)(v2 + 16) + 24i64) = *(_QWORD *)(v2 + 24);
      *(_QWORD *)(v2 + 24) = prcc->pLastPtr->pNext->pPrev;
      *(_QWORD *)(v2 + 16) = prcc->pLastPtr->pNext;
      prcc->pLastPtr->pNext->pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v2;
      prcc->pLastPtr->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v2;
    }
  }
}

// File Line: 223
// RVA: 0x8174A0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rax
  unsigned int v3; // r8d

  ++(*pchild)->RefCount;
  v2 = *pchild;
  v3 = ((*pchild)->RefCount >> 28) & 7;
  if ( v3 != 5 )
  {
    if ( v3 )
    {
      v2->RefCount &= ~0x20000000u;
      v2->RefCount |= 0x50000000u;
      Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(prcc, *pchild);
    }
  }
}

// File Line: 235
// RVA: 0x7C49B0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall(
        Scaleform::GFx::AS3::RefCountCollector<328> *__formal,
        Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  *pchild = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)*pchild + 1);
}

// File Line: 371
// RVA: 0x787BA0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::~RefCountBaseGC<328>(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
}

// File Line: 512
// RVA: 0x7741A0
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>(
        Scaleform::GFx::AS3::RefCountCollector<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *p_ListRoot; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,328>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS3::RefCountCollector<328>,328>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::`vftable;
  p_ListRoot = &this->ListRoot;
  p_ListRoot->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  p_ListRoot->RefCount = 1;
  p_ListRoot->pRCCRaw = 0i64;
  p_ListRoot->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode::`vftable;
  this->WProxyHash.mHash.pTable = 0i64;
  this->Flags = 0;
  this->HeadDelayedPtrRelease.pObject = 0i64;
  this->pExcludedRoots = 0i64;
  this->CurrentMaxGen = 2;
  this->pLastPtr = p_ListRoot;
  this->Roots[0].pRootHead = 0i64;
  *(_QWORD *)&this->Roots[0].nRoots = 0i64;
  this->Roots[1].pRootHead = 0i64;
  *(_QWORD *)&this->Roots[1].nRoots = 0i64;
  this->Roots[2].pRootHead = 0i64;
  *(_QWORD *)&this->Roots[2].nRoots = 0i64;
  this->FinalizeRoots.pRootHead = 0i64;
  *(_QWORD *)&this->FinalizeRoots.nRoots = 0i64;
}

// File Line: 519
// RVA: 0x787BB0
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::~RefCountCollector<328>(
        Scaleform::GFx::AS3::RefCountCollector<328> *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::`vftable;
  this->Flags |= 0x20u;
  Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, 2u, 0, 0i64);
  pObject = (Scaleform::Render::RenderBuffer *)this->HeadDelayedPtrRelease.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>((Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF> > *)&this->WProxyHash);
  this->ListRoot.vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 531
// RVA: 0x7EF0C0
unsigned __int64 __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        unsigned int uptoGen)
{
  __int64 v2; // r9
  __int64 v3; // r11
  __int64 nRoots; // rbx
  __int64 v5; // rdi
  unsigned int *p_nRoots; // r8
  unsigned __int64 v7; // r10
  unsigned int v8; // esi
  __int64 v9; // rax

  v2 = 0i64;
  v3 = 0i64;
  nRoots = 0i64;
  v5 = 0i64;
  if ( (int)(uptoGen + 1) < 2 )
    goto LABEL_5;
  p_nRoots = &this->Roots[1].nRoots;
  v7 = (unsigned __int64)(uptoGen + 1) >> 1;
  v8 = 2 * v7;
  v5 = 2 * v7;
  do
  {
    v9 = *(p_nRoots - 4);
    p_nRoots += 8;
    v2 += v9;
    v3 += *(p_nRoots - 8);
    --v7;
  }
  while ( v7 );
  if ( v8 <= uptoGen )
LABEL_5:
    nRoots = this->Roots[v5].nRoots;
  return nRoots + v3 + v2;
}

// File Line: 591
// RVA: 0x7D77E0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc)
{
  signed int RefCount; // ecx

  this->RefCount &= 0x8FFFFFFF;
  RefCount = this->RefCount;
  if ( (RefCount & 0x1000000) != 0 )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->RefCount &= ~0x1000000u;
  }
  else if ( RefCount < 0 )
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(
      (Scaleform::GFx::AS3::RefCountCollector<328> *)(this->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64),
      this);
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, __int64))this->vfptr->~RefCountBaseGC<328>)(
    this,
    1i64);
}

// File Line: 626
// RVA: 0x810E60
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // rdi
  signed int RefCount; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pRootHead; // rax

  pRCC = this->_pRCC;
  RefCount = this->RefCount;
  v4 = (Scaleform::GFx::AS3::RefCountCollector<328> *)((unsigned __int64)pRCC & 0xFFFFFFFFFFFFFFFCui64);
  if ( (RefCount & 0x3FFFFF) != 0 )
  {
    if ( (RefCount & 0x70000000) != 805306368 )
    {
      if ( (RefCount & 0x1000000) != 0 || RefCount < 0 )
      {
        this->RefCount = RefCount & 0x8FFFFFFF | 0x30000000;
      }
      else if ( (v4->Flags & 8) == 0 )
      {
        v5 = &v4->Roots[(__int64)this->_pRCC & 3];
        pRootHead = v5->pRootHead;
        this->pPrev = 0i64;
        this->pNext = pRootHead;
        if ( v5->pRootHead )
          v5->pRootHead->pPrev = this;
        ++v5->nRoots;
        v5->pRootHead = this;
        this->RefCount = this->RefCount & 0xFFFFFFF | 0xB0000000;
      }
    }
  }
  else
  {
    if ( (RefCount & 0x2000000) != 0 )
      this->vfptr->Finalize_GC(this);
    if ( (this->RefCount & 0x1000000) != 0 )
      this->RefCount |= 0x800000u;
    else
      Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(this, v4);
  }
}

// File Line: 757
// RVA: 0x810D40
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *pchild)
{
  if ( (pchild->RefCount & 0x1000000) != 0 )
  {
    pchild->pPrev->pNext = pchild->pNext;
    pchild->pNext->pPrev = pchild->pPrev;
    pchild->pPrev = this->pLastPtr->pNext->pPrev;
    pchild->pNext = this->pLastPtr->pNext;
    this->pLastPtr->pNext->pPrev = pchild;
    this->pLastPtr->pNext = pchild;
  }
}

// File Line: 775
// RVA: 0x7AFA60
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *pchild)
{
  signed int RefCount; // r8d
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // rax
  __int64 v6; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // r8

  RefCount = pchild->RefCount;
  if ( RefCount < 0 && (RefCount & 0x1000000) == 0 )
  {
    pPrev = pchild->pPrev;
    pNext = pchild->pNext;
    v6 = 2 * (((__int64)pchild->_pRCC & 3) + 1i64);
    if ( pPrev )
      pPrev->pNext = pNext;
    else
      this->Roots[(__int64)pchild->_pRCC & 3].pRootHead = pNext;
    v7 = pchild->pNext;
    if ( v7 )
      v7->pPrev = pchild->pPrev;
    pchild->RefCount &= ~0x80000000;
    pchild->pNext = 0i64;
    pchild->pPrev = 0i64;
    --*((_DWORD *)&this->RefCount + 2 * v6);
  }
  if ( (pchild->RefCount & 0x1000000) == 0 )
  {
    pchild->pPrev = this->pLastPtr->pNext->pPrev;
    pchild->pNext = this->pLastPtr->pNext;
    this->pLastPtr->pNext->pPrev = pchild;
    this->pLastPtr->pNext = pchild;
    this->pLastPtr = pchild;
    pchild->RefCount |= 0x1000000u;
  }
}

// File Line: 793
// RVA: 0x7ABA50
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::AddDelayedReleaseProxy(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::Resource *preleaseProxy)
{
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx

  if ( preleaseProxy )
  {
    pObject = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
    if ( pObject )
    {
      Scaleform::Render::RenderBuffer::AddRef(pObject);
      v7 = *(Scaleform::Render::RenderBuffer **)&preleaseProxy[1].RefCount.Value;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      *(_QWORD *)&preleaseProxy[1].RefCount.Value = this->HeadDelayedPtrRelease.pObject;
      Scaleform::Render::RenderBuffer::AddRef(preleaseProxy);
      v8 = (Scaleform::Render::RenderBuffer *)this->HeadDelayedPtrRelease.pObject;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      this->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)preleaseProxy;
    }
    else
    {
      Scaleform::Render::RenderBuffer::AddRef(preleaseProxy);
      v5 = (Scaleform::Render::RenderBuffer *)this->HeadDelayedPtrRelease.pObject;
      if ( v5 )
        Scaleform::RefCountImpl::Release(v5);
      this->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)preleaseProxy;
      v6 = *(Scaleform::Render::RenderBuffer **)&preleaseProxy[1].RefCount.Value;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      *(_QWORD *)&preleaseProxy[1].RefCount.Value = 0i64;
    }
  }
}

// File Line: 813
// RVA: 0x7B3C10
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::AmpStats *ampStats)
{
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v4; // rbx
  Scaleform::GFx::Resource *pRenderTargetData; // rcx
  Scaleform::Render::RenderBuffer *v6; // rdi

  pObject = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef(pObject);
  v4 = (Scaleform::Render::RenderBuffer *)this->HeadDelayedPtrRelease.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->HeadDelayedPtrRelease.pObject = 0i64;
  if ( v4 )
  {
    this->Flags |= 0x10u;
    while ( 1 )
    {
      pRenderTargetData = (Scaleform::GFx::Resource *)v4->pRenderTargetData;
      if ( pRenderTargetData )
        Scaleform::Render::RenderBuffer::AddRef(pRenderTargetData);
      v6 = (Scaleform::Render::RenderBuffer *)v4->pRenderTargetData;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      v4->pRenderTargetData = 0i64;
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
      if ( v4 )
        Scaleform::RefCountImpl::Release(v4);
      v4 = v6;
      if ( !v6 )
        break;
      Scaleform::RefCountImpl::Release(v6);
    }
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
}

// File Line: 872
// RVA: 0x811A70
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *root)
{
  signed int RefCount; // r8d
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // rax
  __int64 v6; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // r8

  RefCount = root->RefCount;
  if ( RefCount < 0 && (RefCount & 0x1000000) == 0 )
  {
    pPrev = root->pPrev;
    pNext = root->pNext;
    v6 = 2 * (((__int64)root->_pRCC & 3) + 1i64);
    if ( pPrev )
      pPrev->pNext = pNext;
    else
      this->Roots[(__int64)root->_pRCC & 3].pRootHead = pNext;
    v7 = root->pNext;
    if ( v7 )
      v7->pPrev = root->pPrev;
    root->RefCount &= ~0x80000000;
    root->pNext = 0i64;
    root->pPrev = 0i64;
    --*((_DWORD *)&this->RefCount + 2 * v6);
  }
}

// File Line: 897
// RVA: 0x7B6DE0
char __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::Collect(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        unsigned int uptoGeneration,
        bool upgradeGen,
        Scaleform::GFx::AS3::RefCountCollector<328>::Stats *pstat)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats *v4; // r13
  Scaleform::Render::RenderBuffer *v7; // rcx
  char Flags; // al
  char v9; // si
  Scaleform::Render::RenderBuffer *pObject; // rbx
  unsigned int v11; // eax
  __int64 v12; // rcx
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *p_ListRoot; // r14
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *Roots; // rax
  int v15; // ebp
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v16; // rsi
  __int64 v17; // r15
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *i; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // rax
  int pRCC; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *v21; // rdx
  int RefCount; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v23; // rcx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v24; // rcx
  unsigned int v25; // r15d
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rbx
  char v27; // bp
  unsigned int v28; // r13d
  unsigned int v29; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rbx
  unsigned int v31; // ecx
  int v32; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v33; // rbx
  unsigned int v34; // r13d
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *v35; // rsi
  unsigned int v36; // eax
  int v37; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pRootHead; // rax
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v39; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v40; // rsi
  unsigned int v41; // r13d
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *v42; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *j; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v44; // rax
  int v45; // ecx
  __int64 v46; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v48; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v49; // rdx
  Scaleform::GFx::AS3::RefCountCollector<328>::RootDesc *v50; // rcx
  unsigned int v51; // eax
  unsigned int v53; // [rsp+20h] [rbp-68h]
  unsigned int v54; // [rsp+28h] [rbp-60h]
  unsigned int v55; // [rsp+2Ch] [rbp-5Ch]
  __int64 v56; // [rsp+30h] [rbp-58h]
  Scaleform::AmpStats *ampStats; // [rsp+38h] [rbp-50h]
  Scaleform::AmpStats *v58; // [rsp+90h] [rbp+8h]
  unsigned int v59; // [rsp+90h] [rbp+8h]

  v4 = pstat;
  v7 = 0i64;
  this->Flags &= ~0x10u;
  Flags = this->Flags;
  if ( (Flags & 4) == 0 && (Flags & 2) == 0 )
  {
    v9 = 1;
    if ( pstat )
    {
      if ( pstat->AdvanceStats.pObject )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pstat->AdvanceStats.pObject);
      pObject = (Scaleform::Render::RenderBuffer *)v4->AdvanceStats.pObject;
      v58 = v4->AdvanceStats.pObject;
      v7 = (Scaleform::Render::RenderBuffer *)v4->AdvanceStats.pObject;
    }
    else
    {
      v58 = 0i64;
      v9 = 2;
      pObject = 0i64;
    }
    ampStats = v58;
    if ( (v9 & 2) != 0 )
    {
      v9 &= ~2u;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
    }
    if ( (v9 & 1) != 0 && pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->Flags |= 4u;
    v59 = 0;
    v53 = 0;
    v54 = 0;
    if ( (this->Flags & 0x20) != 0 )
    {
      upgradeGen = 0;
      v11 = 2;
      uptoGeneration = 2;
    }
    else
    {
      v11 = uptoGeneration;
    }
    this->CurrentMaxGen = v11;
    v12 = v11 + 1;
    v55 = v11 + 1;
    p_ListRoot = &this->ListRoot;
    Roots = this->Roots;
    v56 = v12;
    while ( 1 )
    {
      do
      {
        this->Flags |= 1u;
        this->pLastPtr = p_ListRoot;
        this->ListRoot.pPrev = p_ListRoot;
        this->ListRoot.pNext = p_ListRoot;
        this->ListRoot.RefCount |= 0x1000000u;
        v15 = 0;
        this->Flags |= 8u;
        v16 = Roots;
        v17 = v12;
        do
        {
          for ( i = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)v16->pRootHead; v16->pRootHead; ++v15 )
          {
            pNext = i->pNext;
            v16->pRootHead = pNext;
            if ( pNext )
              pNext->pPrev = 0i64;
            i->RefCount &= ~0x80000000;
            --v16->nRoots;
            if ( (i->RefCount & 0x70000000) == 805306368 )
            {
              pRCC = (int)i->_pRCC;
              if ( (pRCC & 3u) > this->CurrentMaxGen )
              {
                i->RefCount &= 0x8FFFFFFF;
                v24 = &this->Roots[pRCC & 3];
                i->pNext = v24->pRootHead;
                i->pPrev = 0i64;
                if ( v24->pRootHead )
                  v24->pRootHead->pPrev = i;
                v24->pRootHead = i;
                ++v24->nRoots;
                i->RefCount = i->RefCount & 0xFFFFFFF | 0xB0000000;
              }
              else
              {
                Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(this, i);
                if ( i != p_ListRoot )
                {
                  do
                  {
                    if ( (unsigned __int64)((__int64)i->_pRCC & 3) > this->CurrentMaxGen )
                    {
                      v21 = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)i->pNext;
                      if ( (i->RefCount & 0x1000000) != 0 )
                      {
                        if ( this->pLastPtr == i )
                          this->pLastPtr = i->pPrev;
                        i->pPrev->pNext = i->pNext;
                        i->pNext->pPrev = i->pPrev;
                        i->RefCount &= ~0x1000000u;
                      }
                      RefCount = i->RefCount;
                      if ( RefCount < 0 )
                      {
                        i->RefCount = RefCount & 0x8FFFFFFF | 0x30000000;
                      }
                      else
                      {
                        i->RefCount = RefCount & 0x8FFFFFFF;
                        v23 = &this->Roots[(__int64)i->_pRCC & 3];
                        i->pNext = v23->pRootHead;
                        i->pPrev = 0i64;
                        if ( v23->pRootHead )
                          v23->pRootHead->pPrev = i;
                        v23->pRootHead = i;
                        ++v23->nRoots;
                        i->RefCount = i->RefCount & 0xFFFFFFF | 0xB0000000;
                      }
                    }
                    else
                    {
                      if ( (i->RefCount & 0x70000000) != 0x10000000 )
                      {
                        i->RefCount = i->RefCount & 0x8FFFFFFF | 0x10000000;
                        i->vfptr->ForEachChild_GC(i, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall);
                      }
                      v21 = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)i->pNext;
                    }
                    i = v21;
                  }
                  while ( v21 != p_ListRoot );
                }
              }
            }
            i = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)v16->pRootHead;
          }
          ++v16;
          --v17;
        }
        while ( v17 );
        this->Flags &= ~8u;
        v25 = v59;
        if ( !v15 )
        {
LABEL_112:
          if ( v4 )
          {
            v4->RootsNumber = v25;
            v51 = v53;
            if ( v25 < v53 )
              v51 = v25;
            v4->RootsFreedTotal = v51;
            v4->ObjectsIteratedNumber = v54;
            v4->ObjectsFreedTotal = v53;
            v4->GensNumber = v55;
            if ( ampStats )
            {
              ampStats->vfptr[3].__vecDelDtor(ampStats, v25);
              ampStats->vfptr[4].__vecDelDtor(ampStats, v4->RootsFreedTotal);
            }
          }
          this->Flags &= 0xDBu;
          Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(this, ampStats);
          return 1;
        }
        v25 = v15 + v59;
        v59 += v15;
        v26 = this->ListRoot.pNext;
        v27 = 0;
        if ( v26 != p_ListRoot )
        {
          v28 = v54;
          do
          {
            ++v28;
            v29 = v26->RefCount;
            if ( (v29 & 0x3FFFFF) != 0 )
            {
              v26->RefCount = v29 & 0x8FFFFFFF;
              this->pLastPtr = v26;
              v26->vfptr->ForEachChild_GC(v26, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall);
            }
            else
            {
              if ( (v29 & 0x2000000) != 0 )
                v27 = 1;
              v26->RefCount = v29 & 0x8FFFFFFF | 0x20000000;
            }
            v26 = v26->pNext;
          }
          while ( v26 != p_ListRoot );
          v54 = v28;
          v4 = pstat;
          if ( v27 )
          {
            v30 = this->ListRoot.pNext;
            for ( this->pLastPtr = p_ListRoot; v30 != p_ListRoot; v30 = v30->pNext )
            {
              v31 = v30->RefCount;
              v32 = (v31 >> 28) & 7;
              if ( v32 == 2 )
              {
                if ( (v31 & 0x2000000) != 0 )
                {
                  v30->RefCount = v31 & 0x8FFFFFFF;
                  this->pLastPtr = v30;
                  v30->vfptr->ForEachChild_GC(v30, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
                  v30->RefCount |= 0x400000u;
                }
              }
              else if ( v32 == 5 )
              {
                v30->RefCount = v31 & 0x8FFFFFFF;
                this->pLastPtr = v30;
                v30->vfptr->ForEachChild_GC(v30, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
              }
            }
          }
        }
        v33 = this->ListRoot.pNext;
        this->pLastPtr = p_ListRoot;
        if ( v33 != p_ListRoot )
        {
          v34 = v53;
          do
          {
            v35 = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)v33->pNext;
            if ( (v33->RefCount & 0x70000000) == 0x20000000 )
            {
              if ( (v33->RefCount & 0x8000000) == 0 )
              {
                v33->pPrev->pNext = v35;
                v33->pNext->pPrev = v33->pPrev;
                v33->RefCount &= ~0x1000000u;
                Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(this, v33);
                v33->vfptr->ForEachChild_GC(v33, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
                ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, __int64))v33->vfptr->~RefCountBaseGC<328>)(
                  v33,
                  1i64);
                ++v34;
              }
            }
            else
            {
              if ( upgradeGen )
              {
                v36 = (__int64)v33->_pRCC & 3;
                if ( v36 < 2 )
                {
                  v33->pRCCRaw &= 0xFFFFFFFFFFFFFFFCui64;
                  v33->pRCCRaw |= ((_BYTE)v36 + 1) & 3;
                }
              }
              v33->pPrev->pNext = v35;
              v33->pNext->pPrev = v33->pPrev;
              v33->RefCount &= ~0x1000000u;
              v37 = v33->RefCount;
              if ( (v37 & 0x800000) != 0 )
              {
                v33->RefCount = v37 & 0xFF7FFFFF;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v33);
              }
              else if ( (v37 & 0x400000) != 0 )
              {
                v33->pNext = this->FinalizeRoots.pRootHead;
                v33->pPrev = 0i64;
                pRootHead = this->FinalizeRoots.pRootHead;
                if ( pRootHead )
                  pRootHead->pPrev = v33;
                this->FinalizeRoots.pRootHead = v33;
                ++this->FinalizeRoots.nRoots;
                v33->RefCount |= 0x80000000;
              }
              else if ( (v37 & 0x70000000) == 805306368 && v37 >= 0 )
              {
                v33->RefCount = v37 & 0x8FFFFFFF;
                if ( (this->Flags & 8) == 0 )
                {
                  v39 = &this->Roots[(__int64)v33->_pRCC & 3];
                  v33->pNext = v39->pRootHead;
                  v33->pPrev = 0i64;
                  if ( v39->pRootHead )
                    v39->pRootHead->pPrev = v33;
                  v39->pRootHead = v33;
                  ++v39->nRoots;
                  v33->RefCount = v33->RefCount & 0xFFFFFFF | 0xB0000000;
                }
              }
            }
            v33 = v35;
          }
          while ( v35 != p_ListRoot );
          v53 = v34;
          v4 = pstat;
          v25 = v59;
        }
        v40 = this->ListRoot.pNext;
        if ( v40 != p_ListRoot )
        {
          v41 = v53;
          do
          {
            v42 = (Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *)v40->pNext;
            Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(this, v40);
            v40->vfptr->ForEachChild_GC(v40, this, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
            ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, __int64))v40->vfptr->~RefCountBaseGC<328>)(
              v40,
              1i64);
            ++v41;
            v40 = v42;
          }
          while ( v42 != p_ListRoot );
          v53 = v41;
          v4 = pstat;
          v25 = v59;
        }
        this->pLastPtr = p_ListRoot;
        this->ListRoot.RefCount &= ~0x1000000u;
        this->Flags &= ~1u;
        if ( v27 )
        {
          for ( j = this->FinalizeRoots.pRootHead; j; j = this->FinalizeRoots.pRootHead )
          {
            v44 = j->pNext;
            this->FinalizeRoots.pRootHead = v44;
            if ( v44 )
              v44->pPrev = 0i64;
            j->RefCount &= ~0x80000000;
            if ( (j->RefCount & 0x400000) != 0 )
            {
              j->RefCount = (j->RefCount & 0xFDBFFFFF) + 1;
              j->vfptr->Finalize_GC(j);
              v45 = --j->RefCount;
              if ( v45 < 0 && (v45 & 0x1000000) == 0 )
              {
                v46 = 2 * (((__int64)j->_pRCC & 3) + 1i64);
                pPrev = j->pPrev;
                v48 = j->pNext;
                if ( pPrev )
                  pPrev->pNext = v48;
                else
                  this->Roots[(__int64)j->_pRCC & 3].pRootHead = v48;
                v49 = j->pNext;
                if ( v49 )
                  v49->pPrev = j->pPrev;
                j->pNext = 0i64;
                j->pPrev = 0i64;
                j->RefCount &= ~0x80000000;
                --*((_DWORD *)&this->RefCount + 2 * v46);
              }
              j->RefCount &= 0x8FFFFFFF;
              j->pRCCRaw &= 0xFFFFFFFFFFFFFFFCui64;
              if ( (this->Flags & 8) == 0 )
              {
                v50 = &this->Roots[(__int64)j->_pRCC & 3];
                j->pNext = v50->pRootHead;
                j->pPrev = 0i64;
                if ( v50->pRootHead )
                  v50->pRootHead->pPrev = j;
                v50->pRootHead = j;
                ++v50->nRoots;
                j->RefCount = j->RefCount & 0xFFFFFFF | 0xB0000000;
              }
            }
          }
        }
        upgradeGen = 0;
        Roots = this->Roots;
        v12 = v56;
      }
      while ( this->Roots[0].pRootHead );
      if ( uptoGeneration != 2 )
        break;
      Roots = this->Roots;
      if ( !this->Roots[2].pRootHead )
      {
LABEL_111:
        Roots = this->Roots;
        v12 = v56;
        if ( !this->Roots[1].pRootHead )
          goto LABEL_112;
      }
    }
    if ( !uptoGeneration )
      goto LABEL_112;
    goto LABEL_111;
  }
  if ( pstat )
  {
    *(_QWORD *)&pstat->ObjectsFreedTotal = 0i64;
    *(_QWORD *)&pstat->RootsFreedTotal = 0i64;
    pstat->RootsNumber = 0;
  }
  return 0;
}ts = this->Roots;
      if ( !this->Roots[2].pRootHead )
      {
LABEL_111:
        Roots = this->Roots;
        v12 = v56;
        if ( !this->Roots[1].pRootHead )
          goto LABEL_112;
      }
    }
    if ( !uptoGeneration )
      goto LABEL_112;
    goto LABEL_111;
  }
  if ( pstat )
  {
    *(_QWORD *)&pstat->ObjectsFreedTotal = 0i64;
    *(_QWORD *)&pstat->RootsFreedTotal = 0i6

// File Line: 1415
// RVA: 0x7F1EA0
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(
        Scaleform::GFx::AS3::RefCountCollector<328> *this,
        Scaleform::GFx::AS3::GASRefCountBase *pcur)
{
  unsigned int RefCount; // edx
  Scaleform::Hash<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > > *p_WProxyHash; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v6; // rcx
  __int64 v7; // rdx
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v13; // rdx
  unsigned __int64 SizeMask; // rdx
  __int64 v16; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::GASRefCountBase *key; // [rsp+38h] [rbp+10h] BYREF

  RefCount = pcur->RefCount;
  if ( (RefCount & 0x4000000) != 0 )
  {
    p_WProxyHash = &this->WProxyHash;
    pcur->RefCount = RefCount & 0xFBFFFFFF;
    pTable = this->WProxyHash.mHash.pTable;
    key = pcur;
    if ( pTable )
    {
      v6 = 5381i64;
      v7 = 8i64;
      do
      {
        v8 = *((unsigned __int8 *)&v16 + v7-- + 7);
        v9 = 65599 * v6 + v8;
        v6 = v9;
      }
      while ( v7 );
      v10 = v9 & pTable->SizeMask;
      v11 = v10;
      v12 = (__int64)&pTable[2 * v10 + 1];
      if ( *(_QWORD *)v12 != -2i64 && *(_QWORD *)(v12 + 8) == v10 )
      {
        while ( *(_QWORD *)(v12 + 8) != v10 || *(Scaleform::GFx::AS3::GASRefCountBase **)(v12 + 16) != pcur )
        {
          v11 = *(_QWORD *)v12;
          if ( *(_QWORD *)v12 == -1i64 )
            return;
          v12 = (__int64)&pTable[2 * v11 + 1];
        }
        if ( v11 >= 0 )
        {
          v13 = &pTable[2 * v11 + 2];
          if ( v13 )
          {
            SizeMask = v13->SizeMask;
            if ( SizeMask )
            {
              *(_QWORD *)(SizeMask + 8) = 0i64;
              if ( (*(_DWORD *)SizeMask)-- == 1 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              key = pcur;
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                &p_WProxyHash->mHash,
                &key);
            }
          }
        }
      }
    }
  }
}

// File Line: 1456
// RVA: 0x7D5280
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::Value *v,
        void (*op)(void))
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Value::VU *p_value; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rdx

  v4 = v->Flags & 0x1F;
  if ( v4 > 0xA && (v->Flags & 0x200) == 0 && (v->Flags & 0x1F) >= 0xB )
  {
    if ( (v->Flags & 0x1F) <= 0xF )
    {
      p_value = &v->value;
      if ( v->value.VS._1.VStr )
      {
        v6 = 0i64;
        if ( v4 - 11 <= 4 )
          v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_value;
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op)(
          prcc,
          v6);
      }
    }
    else if ( (v->Flags & 0x1F) <= 0x11 )
    {
      if ( v->value.VS._2.VObj )
        op();
    }
  }
}

