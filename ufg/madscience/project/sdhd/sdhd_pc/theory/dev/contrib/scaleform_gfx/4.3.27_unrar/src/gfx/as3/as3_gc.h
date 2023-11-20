// File Line: 185
// RVA: 0x810E00
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseCall(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v3; // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi

  v2 = *pchild;
  v3 = pchild;
  v4 = prcc;
  if ( --v2->RefCount & 0x3FFFFF )
  {
    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*pchild);
  }
  else
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(prcc, *pchild);
    (*v3)->RefCount |= 0x800000u;
    Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(v4, *v3);
  }
}

// File Line: 203
// RVA: 0x800C40
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  --(*pchild)->RefCount;
  Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(prcc, *pchild);
}

// File Line: 211
// RVA: 0x817420
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rdx

  if ( ++(*pchild)->RefCount & 0x70000000 )
  {
    (*pchild)->RefCount &= 0x8FFFFFFF;
    v2 = *pchild;
    if ( v2->RefCount & 0x1000000 )
    {
      v2->pPrev->pNext = v2->pNext;
      v2->pNext->pPrev = v2->pPrev;
      v2->pPrev = prcc->pLastPtr->pNext->pPrev;
      v2->pNext = prcc->pLastPtr->pNext;
      prcc->pLastPtr->pNext->pPrev = v2;
      prcc->pLastPtr->pNext = v2;
    }
  }
}

// File Line: 223
// RVA: 0x8174A0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rax
  unsigned int v3; // er8

  ++(*pchild)->RefCount;
  v2 = *pchild;
  v3 = ((*pchild)->RefCount >> 28) & 7;
  if ( v3 != 5 )
  {
    if ( v3 )
    {
      v2->RefCount &= 0xDFFFFFFF;
      v2->RefCount |= 0x50000000u;
      Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(prcc, *pchild);
    }
  }
}

// File Line: 235
// RVA: 0x7C49B0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall(Scaleform::GFx::AS3::RefCountCollector<328> *__formal, Scaleform::GFx::AS3::RefCountBaseGC<328> **pchild)
{
  *pchild = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)*pchild + 1);
}

// File Line: 371
// RVA: 0x787BA0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::~RefCountBaseGC<328>(Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
}

// File Line: 512
// RVA: 0x7741A0
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>(Scaleform::GFx::AS3::RefCountCollector<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode *v1; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,328>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS3::RefCountCollector<328>,328>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::`vftable';
  v1 = &this->ListRoot;
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  v1->RefCount = 1;
  v1->pRCCRaw = 0i64;
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::ListRootNode::`vftable';
  this->WProxyHash.mHash.pTable = 0i64;
  this->Flags = 0;
  this->HeadDelayedPtrRelease.pObject = 0i64;
  this->pExcludedRoots = 0i64;
  this->CurrentMaxGen = 2;
  this->pLastPtr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->ListRoot.vfptr;
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
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::~RefCountCollector<328>(Scaleform::GFx::AS3::RefCountCollector<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::RefCountCollector<328>::`vftable';
  this->Flags |= 0x20u;
  Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, 2u, 0, 0i64);
  v2 = (Scaleform::Render::RenderBuffer *)v1->HeadDelayedPtrRelease.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>((Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,328>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>,Scaleform::HashNode<Scaleform::GFx::AS3::Instances::fl::ConstStringKey,Scaleform::GFx::AS3::ClassInfo const *,Scaleform::GFx::AS3::Instances::fl::ConstStringHashFn>::NodeHashF> > *)&v1->WProxyHash);
  v1->ListRoot.vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 531
// RVA: 0x7EF0C0
__int64 __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(Scaleform::GFx::AS3::RefCountCollector<328> *this, unsigned int uptoGen)
{
  __int64 v2; // r9
  __int64 v3; // r11
  __int64 v4; // rbx
  signed __int64 v5; // rdi
  char *v6; // r8
  unsigned __int64 v7; // r10
  unsigned int v8; // esi
  __int64 v9; // rax

  v2 = 0i64;
  v3 = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  if ( (signed int)(uptoGen + 1) < 2 )
    goto LABEL_9;
  v6 = (char *)&this->Roots[1].nRoots;
  v7 = (unsigned __int64)(uptoGen + 1) >> 1;
  v8 = 2 * v7;
  v5 = 2 * v7;
  do
  {
    v9 = *((unsigned int *)v6 - 4);
    v6 += 32;
    v2 += v9;
    v3 += *((unsigned int *)v6 - 8);
    --v7;
  }
  while ( v7 );
  if ( v8 <= uptoGen )
LABEL_9:
    v4 = this->Roots[v5].nRoots;
  return v4 + v3 + v2;
}

// File Line: 591
// RVA: 0x7D77E0
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(Scaleform::GFx::AS3::RefCountBaseGC<328> *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rbx
  signed int v3; // ecx

  this->RefCount &= 0x8FFFFFFF;
  v2 = this;
  v3 = this->RefCount;
  if ( v3 & 0x1000000 )
  {
    v2->pPrev->pNext = v2->pNext;
    v2->pNext->pPrev = v2->pPrev;
    v2->RefCount &= 0xFEFFFFFF;
  }
  else if ( v3 < 0 )
  {
    Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(
      (Scaleform::GFx::AS3::RefCountCollector<328> *)(v2->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64),
      v2);
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, signed __int64))v2->vfptr->~RefCountBaseGC<328>)(
    v2,
    1i64);
}

// File Line: 626
// RVA: 0x810E60
void __fastcall Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(Scaleform::GFx::AS3::RefCountBaseGC<328> *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v1; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::RefCountImplCoreVtbl **v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // rax

  v1 = this->_pRCC;
  v2 = this;
  v3 = this->RefCount;
  v4 = (Scaleform::GFx::AS3::RefCountCollector<328> *)((unsigned __int64)v1 & 0xFFFFFFFFFFFFFFFCui64);
  if ( v3 & 0x3FFFFF )
  {
    if ( (v3 & 0x70000000) != 805306368 )
    {
      if ( v3 & 0x1000000 || (v3 & 0x80000000) != 0 )
      {
        v2->RefCount = v3 & 0xBFFFFFFF | 0x30000000;
      }
      else if ( !(v4->Flags & 8) )
      {
        v5 = &(&v4->vfptr)[2 * (((_QWORD)v2->_pRCC & 3) + 1i64)];
        v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v5;
        v2->pPrev = 0i64;
        v2->pNext = v6;
        if ( *v5 )
          (*v5)[3].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v2;
        ++*((_DWORD *)v5 + 2);
        *v5 = (Scaleform::RefCountImplCoreVtbl *)v2;
        v2->RefCount = v2->RefCount & 0xFFFFFFF | 0xB0000000;
      }
    }
  }
  else
  {
    if ( (v3 >> 25) & 1 )
      v2->vfptr->Finalize_GC(v2);
    if ( (v2->RefCount >> 24) & 1 )
      v2->RefCount |= 0x800000u;
    else
      Scaleform::GFx::AS3::RefCountBaseGC<328>::FreeThis(v2, v4);
  }
}

// File Line: 757
// RVA: 0x810D40
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::ReinsertToList(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::GFx::AS3::RefCountBaseGC<328> *pchild)
{
  if ( pchild->RefCount & 0x1000000 )
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
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::GFx::AS3::RefCountBaseGC<328> *pchild)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v2; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // rax
  signed __int64 v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // r8

  v2 = this;
  if ( (pchild->RefCount & 0x80000000) != 0 && !((pchild->RefCount >> 24) & 1) )
  {
    v3 = pchild->pPrev;
    v4 = pchild->pNext;
    v5 = 2 * (((_QWORD)pchild->_pRCC & 3) + 1i64);
    if ( v3 )
      v3->pNext = v4;
    else
      (&v2->vfptr)[2 * (((_QWORD)pchild->_pRCC & 3) + 1i64)] = (Scaleform::RefCountImplCoreVtbl *)v4;
    v6 = pchild->pNext;
    if ( v6 )
      v6->pPrev = pchild->pPrev;
    pchild->RefCount &= 0x7FFFFFFFu;
    pchild->pNext = 0i64;
    pchild->pPrev = 0i64;
    --*((_DWORD *)&v2->RefCount + 2 * v5);
  }
  if ( !(pchild->RefCount & 0x1000000) )
  {
    pchild->pPrev = v2->pLastPtr->pNext->pPrev;
    pchild->pNext = v2->pLastPtr->pNext;
    v2->pLastPtr->pNext->pPrev = pchild;
    v2->pLastPtr->pNext = pchild;
    v2->pLastPtr = pchild;
    pchild->RefCount |= 0x1000000u;
  }
}

// File Line: 793
// RVA: 0x7ABA50
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::AddDelayedReleaseProxy(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::GFx::AS3::PtrReleaseProxy<328> *preleaseProxy)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v2; // rdi
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::GFx::AS3::PtrReleaseProxy<328> *v4; // rbx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx

  if ( preleaseProxy )
  {
    v2 = this;
    v3 = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
    v4 = preleaseProxy;
    if ( v3 )
    {
      Scaleform::Render::RenderBuffer::AddRef(v3);
      v7 = (Scaleform::Render::RenderBuffer *)v4->pNext.pObject;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      v4->pNext.pObject = v2->HeadDelayedPtrRelease.pObject;
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4);
      v8 = (Scaleform::Render::RenderBuffer *)v2->HeadDelayedPtrRelease.pObject;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      v2->HeadDelayedPtrRelease.pObject = v4;
    }
    else
    {
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)preleaseProxy);
      v5 = (Scaleform::Render::RenderBuffer *)v2->HeadDelayedPtrRelease.pObject;
      if ( v5 )
        Scaleform::RefCountImpl::Release(v5);
      v2->HeadDelayedPtrRelease.pObject = v4;
      v6 = (Scaleform::Render::RenderBuffer *)v4->pNext.pObject;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
      v4->pNext.pObject = 0i64;
    }
  }
}

// File Line: 813
// RVA: 0x7B3C10
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::AmpStats *ampStats)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v2; // rdi
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rbx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::Resource *v6; // rcx
  Scaleform::GFx::Resource *v7; // rdi
  Scaleform::Render::RenderBuffer *v8; // rcx

  v2 = this;
  v3 = (Scaleform::GFx::Resource *)this->HeadDelayedPtrRelease.pObject;
  if ( v3 )
    Scaleform::Render::RenderBuffer::AddRef(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v2->HeadDelayedPtrRelease.pObject;
  v5 = (Scaleform::Render::RenderBuffer *)v2->HeadDelayedPtrRelease.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v2->HeadDelayedPtrRelease.pObject = 0i64;
  if ( v4 )
  {
    v2->Flags |= 0x10u;
    while ( 1 )
    {
      v6 = (Scaleform::GFx::Resource *)v4->pRenderTargetData;
      if ( v6 )
        Scaleform::Render::RenderBuffer::AddRef(v6);
      v7 = (Scaleform::GFx::Resource *)v4->pRenderTargetData;
      v8 = (Scaleform::Render::RenderBuffer *)v4->pRenderTargetData;
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      v4->pRenderTargetData = 0i64;
      if ( v7 )
        Scaleform::Render::RenderBuffer::AddRef(v7);
      if ( v4 )
        Scaleform::RefCountImpl::Release(v4);
      v4 = (Scaleform::Render::RenderBuffer *)v7;
      if ( !v7 )
        break;
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
    }
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
}

// File Line: 872
// RVA: 0x811A70
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::RemoveFromRoots(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::GFx::AS3::RefCountBaseGC<328> *root)
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v2; // r9
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // r8
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // rax
  signed __int64 v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // r8

  v2 = this;
  if ( (root->RefCount & 0x80000000) != 0 && !((root->RefCount >> 24) & 1) )
  {
    v3 = root->pPrev;
    v4 = root->pNext;
    v5 = 2 * (((_QWORD)root->_pRCC & 3) + 1i64);
    if ( v3 )
      v3->pNext = v4;
    else
      (&v2->vfptr)[2 * (((_QWORD)root->_pRCC & 3) + 1i64)] = (Scaleform::RefCountImplCoreVtbl *)v4;
    v6 = root->pNext;
    if ( v6 )
      v6->pPrev = root->pPrev;
    root->RefCount &= 0x7FFFFFFFu;
    root->pNext = 0i64;
    root->pPrev = 0i64;
    --*((_DWORD *)&v2->RefCount + 2 * v5);
  }
}

// File Line: 897
// RVA: 0x7B6DE0
char __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::Collect(Scaleform::GFx::AS3::RefCountCollector<328> *this, unsigned int uptoGeneration, bool upgradeGen, Scaleform::GFx::AS3::RefCountCollector<328>::Stats *pstat)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats *v4; // r13
  bool v5; // r12
  Scaleform::GFx::AS3::RefCountCollector<328> *v6; // rdi
  Scaleform::Render::RenderBuffer *v7; // rcx
  char v8; // al
  char v9; // si
  Scaleform::Render::RenderBuffer *v10; // rbx
  signed int v11; // eax
  __int64 v12; // rcx
  signed __int64 v13; // r14
  signed __int64 v14; // rax
  int v15; // ebp
  signed __int64 v16; // rsi
  __int64 v17; // r15
  __int64 i; // rbx
  __int64 v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  int v22; // ecx
  Scaleform::RefCountImplCoreVtbl **v23; // rcx
  Scaleform::RefCountImplCoreVtbl **v24; // rcx
  unsigned int v25; // er15
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rbx
  char v27; // bp
  unsigned int v28; // er13
  unsigned int v29; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rbx
  unsigned int v31; // ecx
  int v32; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v33; // rbx
  unsigned int v34; // er13
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v35; // rsi
  int v36; // eax
  unsigned int v37; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v38; // rax
  Scaleform::RefCountImplCoreVtbl **v39; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v40; // rsi
  unsigned int v41; // er13
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v42; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *j; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v44; // rax
  signed __int64 v45; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // rdx
  Scaleform::RefCountImplCoreVtbl *v47; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v48; // rdx
  Scaleform::RefCountImplCoreVtbl **v49; // rcx
  unsigned int v50; // eax
  unsigned int v52; // [rsp+20h] [rbp-68h]
  unsigned int v53; // [rsp+28h] [rbp-60h]
  int v54; // [rsp+2Ch] [rbp-5Ch]
  __int64 v55; // [rsp+30h] [rbp-58h]
  Scaleform::AmpStats *ampStats; // [rsp+38h] [rbp-50h]
  Scaleform::AmpStats *v57; // [rsp+90h] [rbp+8h]
  unsigned int v58; // [rsp+90h] [rbp+8h]
  unsigned int v59; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats *v60; // [rsp+A8h] [rbp+20h]

  v60 = pstat;
  v59 = uptoGeneration;
  v4 = pstat;
  v5 = upgradeGen;
  v6 = this;
  v7 = 0i64;
  v6->Flags &= 0xEFu;
  v8 = v6->Flags;
  if ( !(v8 & 4) && !(v8 & 2) )
  {
    v9 = 1;
    if ( pstat )
    {
      if ( pstat->AdvanceStats.pObject )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pstat->AdvanceStats.pObject);
      v10 = (Scaleform::Render::RenderBuffer *)v4->AdvanceStats.pObject;
      v57 = v4->AdvanceStats.pObject;
      v7 = (Scaleform::Render::RenderBuffer *)v4->AdvanceStats.pObject;
    }
    else
    {
      v57 = 0i64;
      v9 = 2;
      v10 = 0i64;
    }
    ampStats = v57;
    if ( v9 & 2 )
    {
      v9 &= 0xFDu;
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
    }
    if ( v9 & 1 && v10 )
      Scaleform::RefCountImpl::Release(v10);
    v6->Flags |= 4u;
    v58 = 0;
    v52 = 0;
    v53 = 0;
    if ( v6->Flags & 0x20 )
    {
      v5 = 0;
      v11 = 2;
      v59 = 2;
    }
    else
    {
      v11 = v59;
    }
    v6->CurrentMaxGen = v11;
    v12 = (unsigned int)(v11 + 1);
    v54 = v11 + 1;
    v13 = (signed __int64)&v6->ListRoot;
    v14 = (signed __int64)v6->Roots;
    v55 = v12;
    while ( 1 )
    {
      do
      {
        v6->Flags |= 1u;
        v6->pLastPtr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
        v6->ListRoot.pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
        v6->ListRoot.pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
        v6->ListRoot.RefCount |= 0x1000000u;
        v15 = 0;
        v6->Flags |= 8u;
        v16 = v14;
        v17 = v12;
        do
        {
          for ( i = *(_QWORD *)v16; *(_QWORD *)v16; ++v15 )
          {
            v19 = *(_QWORD *)(i + 16);
            *(_QWORD *)v16 = v19;
            if ( v19 )
              *(_QWORD *)(v19 + 24) = 0i64;
            *(_DWORD *)(i + 32) &= 0x7FFFFFFFu;
            --*(_DWORD *)(v16 + 8);
            if ( (*(_DWORD *)(i + 32) & 0x70000000) == 805306368 )
            {
              v20 = *(_DWORD *)(i + 8);
              if ( (*(_DWORD *)(i + 8) & 3u) > v6->CurrentMaxGen )
              {
                *(_DWORD *)(i + 32) &= 0x8FFFFFFF;
                v24 = &(&v6->vfptr)[2 * ((v20 & 3) + 1i64)];
                *(_QWORD *)(i + 16) = *v24;
                *(_QWORD *)(i + 24) = 0i64;
                if ( *v24 )
                  (*v24)[3].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))i;
                *v24 = (Scaleform::RefCountImplCoreVtbl *)i;
                ++*((_DWORD *)v24 + 2);
                *(_DWORD *)(i + 32) = *(_DWORD *)(i + 32) & 0xFFFFFFF | 0xB0000000;
              }
              else
              {
                Scaleform::GFx::AS3::RefCountCollector<328>::AddToList(
                  v6,
                  (Scaleform::GFx::AS3::RefCountBaseGC<328> *)i);
                if ( i != v13 )
                {
                  do
                  {
                    if ( (*(_DWORD *)(i + 8) & 3u) > v6->CurrentMaxGen )
                    {
                      v21 = *(_QWORD *)(i + 16);
                      if ( *(_BYTE *)(i + 35) & 1 )
                      {
                        if ( v6->pLastPtr == (Scaleform::GFx::AS3::RefCountBaseGC<328> *)i )
                          v6->pLastPtr = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(i + 24);
                        *(_QWORD *)(*(_QWORD *)(i + 24) + 16i64) = *(_QWORD *)(i + 16);
                        *(_QWORD *)(*(_QWORD *)(i + 16) + 24i64) = *(_QWORD *)(i + 24);
                        *(_DWORD *)(i + 32) &= 0xFEFFFFFF;
                      }
                      v22 = *(_DWORD *)(i + 32);
                      if ( *(_DWORD *)(i + 32) < 0 )
                      {
                        *(_DWORD *)(i + 32) = v22 & 0xBFFFFFFF | 0x30000000;
                      }
                      else
                      {
                        *(_DWORD *)(i + 32) = v22 & 0x8FFFFFFF;
                        v23 = &(&v6->vfptr)[2 * ((*(_DWORD *)(i + 8) & 3) + 1i64)];
                        *(_QWORD *)(i + 16) = *v23;
                        *(_QWORD *)(i + 24) = 0i64;
                        if ( *v23 )
                          (*v23)[3].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))i;
                        *v23 = (Scaleform::RefCountImplCoreVtbl *)i;
                        ++*((_DWORD *)v23 + 2);
                        *(_DWORD *)(i + 32) = *(_DWORD *)(i + 32) & 0xFFFFFFF | 0xB0000000;
                      }
                    }
                    else
                    {
                      if ( (*(_DWORD *)(i + 32) & 0x70000000) != 0x10000000 )
                      {
                        *(_DWORD *)(i + 32) = *(_DWORD *)(i + 32) & 0x9FFFFFFF | 0x10000000;
                        (**(void (__fastcall ***)(__int64, Scaleform::GFx::AS3::RefCountCollector<328> *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **)))i)(
                          i,
                          v6,
                          Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall);
                      }
                      v21 = *(_QWORD *)(i + 16);
                    }
                    i = v21;
                  }
                  while ( v21 != v13 );
                }
              }
            }
            i = *(_QWORD *)v16;
          }
          v16 += 16i64;
          --v17;
        }
        while ( v17 );
        v6->Flags &= 0xF7u;
        v25 = v58;
        if ( !v15 )
        {
LABEL_112:
          if ( v4 )
          {
            v4->RootsNumber = v25;
            v50 = v52;
            if ( v25 < v52 )
              v50 = v25;
            v4->RootsFreedTotal = v50;
            v4->ObjectsIteratedNumber = v53;
            v4->ObjectsFreedTotal = v52;
            v4->GensNumber = v54;
            if ( ampStats )
            {
              ampStats->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)&ampStats->vfptr, v25);
              ampStats->vfptr[4].__vecDelDtor((Scaleform::RefCountImplCore *)&ampStats->vfptr, v4->RootsFreedTotal);
            }
          }
          v6->Flags &= 0xDBu;
          Scaleform::GFx::AS3::RefCountCollector<328>::CleanDelayedReleaseProxies(v6, ampStats);
          return 1;
        }
        v25 = v15 + v58;
        v58 += v15;
        v26 = v6->ListRoot.pNext;
        v27 = 0;
        if ( v26 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 )
        {
          v28 = v53;
          do
          {
            ++v28;
            v29 = v26->RefCount;
            if ( v29 & 0x3FFFFF )
            {
              v26->RefCount = v29 & 0x8FFFFFFF;
              v6->pLastPtr = v26;
              v26->vfptr->ForEachChild_GC(v26, v6, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanInUseCall);
            }
            else
            {
              if ( (v29 >> 25) & 1 )
                v27 = 1;
              v26->RefCount = v29 & 0xAFFFFFFF | 0x20000000;
            }
            v26 = v26->pNext;
          }
          while ( v26 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 );
          v53 = v28;
          v4 = v60;
          if ( v27 )
          {
            v30 = v6->ListRoot.pNext;
            for ( v6->pLastPtr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
                  v30 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
                  v30 = v30->pNext )
            {
              v31 = v30->RefCount;
              v32 = (v30->RefCount >> 28) & 7;
              if ( v32 == 2 )
              {
                if ( (v31 >> 25) & 1 )
                {
                  v30->RefCount = v31 & 0x8FFFFFFF;
                  v6->pLastPtr = v30;
                  v30->vfptr->ForEachChild_GC(v30, v6, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
                  v30->RefCount |= 0x400000u;
                }
              }
              else if ( v32 == 5 )
              {
                v30->RefCount = v31 & 0x8FFFFFFF;
                v6->pLastPtr = v30;
                v30->vfptr->ForEachChild_GC(v30, v6, Scaleform::GFx::AS3::RefCountBaseGC<328>::ScanTempInUseCall);
              }
            }
          }
        }
        v33 = v6->ListRoot.pNext;
        v6->pLastPtr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
        if ( v33 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 )
        {
          v34 = v52;
          do
          {
            v35 = v33->pNext;
            if ( (v33->RefCount & 0x70000000) == 0x20000000 )
            {
              if ( !((v33->RefCount >> 27) & 1) )
              {
                v33->pPrev->pNext = v35;
                v33->pNext->pPrev = v33->pPrev;
                v33->RefCount &= 0xFEFFFFFF;
                Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(v6, v33);
                v33->vfptr->ForEachChild_GC(v33, v6, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
                ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, signed __int64))v33->vfptr->~RefCountBaseGC<328>)(
                  v33,
                  1i64);
                ++v34;
              }
            }
            else
            {
              if ( v5 )
              {
                v36 = (_QWORD)v33->_pRCC & 3;
                if ( v36 < 2 )
                {
                  v33->pRCCRaw &= 0xFFFFFFFFFFFFFFFCui64;
                  v33->pRCCRaw |= ((_BYTE)v36 + 1) & 3;
                }
              }
              v33->pPrev->pNext = v35;
              v33->pNext->pPrev = v33->pPrev;
              v33->RefCount &= 0xFEFFFFFF;
              v37 = v33->RefCount;
              if ( (v33->RefCount >> 23) & 1 )
              {
                v33->RefCount = v37 & 0xFF7FFFFF;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v33);
              }
              else if ( (v37 >> 22) & 1 )
              {
                v33->pNext = v6->FinalizeRoots.pRootHead;
                v33->pPrev = 0i64;
                v38 = v6->FinalizeRoots.pRootHead;
                if ( v38 )
                  v38->pPrev = v33;
                v6->FinalizeRoots.pRootHead = v33;
                ++v6->FinalizeRoots.nRoots;
                v33->RefCount |= 0x80000000;
              }
              else if ( (v37 & 0x70000000) == 805306368 && (v37 & 0x80000000) == 0 )
              {
                v33->RefCount = v37 & 0x8FFFFFFF;
                if ( !(v6->Flags & 8) )
                {
                  v39 = &(&v6->vfptr)[2 * (((_QWORD)v33->_pRCC & 3) + 1i64)];
                  v33->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v39;
                  v33->pPrev = 0i64;
                  if ( *v39 )
                    (*v39)[3].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))v33;
                  *v39 = (Scaleform::RefCountImplCoreVtbl *)v33;
                  ++*((_DWORD *)v39 + 2);
                  v33->RefCount = v33->RefCount & 0xFFFFFFF | 0xB0000000;
                }
              }
            }
            v33 = v35;
          }
          while ( v35 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 );
          v52 = v34;
          v4 = v60;
          v25 = v58;
        }
        v40 = v6->ListRoot.pNext;
        if ( v40 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 )
        {
          v41 = v52;
          do
          {
            v42 = v40->pNext;
            Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(v6, v40);
            v40->vfptr->ForEachChild_GC(v40, v6, Scaleform::GFx::AS3::RefCountBaseGC<328>::DisableCall);
            ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountBaseGC<328> *, signed __int64))v40->vfptr->~RefCountBaseGC<328>)(
              v40,
              1i64);
            ++v41;
            v40 = v42;
          }
          while ( v42 != (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13 );
          v52 = v41;
          v4 = v60;
          v25 = v58;
        }
        v6->pLastPtr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13;
        v6->ListRoot.RefCount &= 0xFEFFFFFF;
        v6->Flags &= 0xFEu;
        if ( v27 )
        {
          for ( j = v6->FinalizeRoots.pRootHead; j; j = v6->FinalizeRoots.pRootHead )
          {
            v44 = j->pNext;
            v6->FinalizeRoots.pRootHead = v44;
            if ( v44 )
              v44->pPrev = 0i64;
            j->RefCount &= 0x7FFFFFFFu;
            if ( (j->RefCount >> 22) & 1 )
            {
              j->RefCount = (j->RefCount & 0xFDBFFFFF) + 1;
              j->vfptr->Finalize_GC(j);
              if ( (--j->RefCount & 0x80000000) != 0 && !((j->RefCount >> 24) & 1) )
              {
                v45 = 2 * (((_QWORD)j->_pRCC & 3) + 1i64);
                v46 = j->pPrev;
                v47 = (Scaleform::RefCountImplCoreVtbl *)j->pNext;
                if ( v46 )
                  v46->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v47;
                else
                  (&v6->vfptr)[2 * (((_QWORD)j->_pRCC & 3) + 1i64)] = v47;
                v48 = j->pNext;
                if ( v48 )
                  v48->pPrev = j->pPrev;
                j->pNext = 0i64;
                j->pPrev = 0i64;
                j->RefCount &= 0x7FFFFFFFu;
                --*((_DWORD *)&v6->RefCount + 2 * v45);
              }
              j->RefCount &= 0x8FFFFFFF;
              j->pRCCRaw &= 0xFFFFFFFFFFFFFFFCui64;
              if ( !(v6->Flags & 8) )
              {
                v49 = &(&v6->vfptr)[2 * (((_QWORD)j->_pRCC & 3) + 1i64)];
                j->pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v49;
                j->pPrev = 0i64;
                if ( *v49 )
                  (*v49)[3].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountImplCore *, unsigned int))j;
                *v49 = (Scaleform::RefCountImplCoreVtbl *)j;
                ++*((_DWORD *)v49 + 2);
                j->RefCount = j->RefCount & 0xFFFFFFF | 0xB0000000;
              }
            }
          }
        }
        v5 = 0;
        v14 = (signed __int64)v6->Roots;
        v12 = v55;
      }
      while ( v6->Roots[0].pRootHead );
      if ( v59 != 2 )
        break;
      v14 = (signed __int64)v6->Roots;
      if ( !v6->Roots[2].pRootHead )
      {
LABEL_111:
        v14 = (signed __int64)v6->Roots;
        v12 = v55;
        if ( !v6->Roots[1].pRootHead )
          goto LABEL_112;
      }
    }
    if ( v59 < 1 )
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
}

// File Line: 1415
// RVA: 0x7F1EA0
void __fastcall Scaleform::GFx::AS3::RefCountCollector<328>::HandleWeakRef(Scaleform::GFx::AS3::RefCountCollector<328> *this, Scaleform::GFx::AS3::RefCountBaseGC<328> *pcur)
{
  Scaleform::GFx::AS3::GASRefCountBase *v2; // rbx
  unsigned int v3; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *v4; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v5; // r9
  signed __int64 v6; // rcx
  signed __int64 v7; // rdx
  __int64 v8; // rax
  signed __int64 v9; // rax
  unsigned __int64 v10; // r8
  signed __int64 v11; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v12; // rcx
  signed __int64 v13; // rdx
  __int64 v14; // rdx
  bool v15; // zf
  __int64 v16; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::GASRefCountBase *key; // [rsp+38h] [rbp+10h]

  v2 = (Scaleform::GFx::AS3::GASRefCountBase *)pcur;
  v3 = pcur->RefCount;
  if ( (v3 >> 26) & 1 )
  {
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)&this->WProxyHash.mHash.pTable;
    v2->RefCount = v3 & 0xFBFFFFFF;
    v5 = this->WProxyHash.mHash.pTable;
    key = v2;
    if ( v5 )
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
      v10 = v9 & v5->SizeMask;
      v11 = v10;
      v12 = &v5[2 * v10 + 1];
      if ( v12->EntryCount != -2i64 && v12->SizeMask == v10 )
      {
        while ( v12->SizeMask != v10 || (Scaleform::GFx::AS3::GASRefCountBase *)v12[1].EntryCount != v2 )
        {
          v11 = v12->EntryCount;
          if ( v12->EntryCount == -1i64 )
            return;
          v12 = &v5[2 * v11 + 1];
        }
        if ( v11 >= 0 )
        {
          v13 = (signed __int64)&v5[2 * (v11 + 1)];
          if ( v13 )
          {
            v14 = *(_QWORD *)(v13 + 8);
            if ( v14 )
            {
              *(_QWORD *)(v14 + 8) = 0i64;
              v15 = (*(_DWORD *)v14)-- == 1;
              if ( v15 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              key = v2;
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                v4,
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
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::Value *v, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v3; // r10
  signed int v4; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rdx

  v3 = prcc;
  v4 = v->Flags & 0x1F;
  if ( v4 > 10 && !((v->Flags >> 9) & 1) && v4 >= 11 )
  {
    if ( v4 <= 15 )
    {
      v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v->value;
      if ( *(_QWORD *)&v->value.VNumber )
      {
        v6 = 0i64;
        if ( (unsigned int)(v4 - 11) <= 4 )
          v6 = v5;
        op(v3, v6);
      }
    }
    else if ( v4 <= 17 )
    {
      if ( v->value.VS._2.VObj )
        ((void (*)(void))op)();
    }
  }
}

