// File Line: 292
// RVA: 0x7100C0
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int v1; // eax

  this->pPrev->pRCC = this->pRCC;
  *(_QWORD *)this->pRCC->Roots.gap0 = this->pPrev;
  this->RefCount &= 0x77FFFFFFu;
  v1 = this->RefCount >> 27;
  this->pRCC = 0i64;
  if ( (v1 & 1) == 0 )
    this->RootIndex = -1;
}

// File Line: 316
// RVA: 0x6D0920
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::~RefCountBaseGC<323>(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
}

// File Line: 397
// RVA: 0x6C6A90
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::RefCountCollector<323>(
        Scaleform::GFx::AS2::RefCountCollector<323> *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::RefCountCollector<323>,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable;
  this->Roots.Size = 0i64;
  this->Roots.NumPages = 0i64;
  this->Roots.MaxPages = 0i64;
  this->Roots.Pages = 0i64;
  this->FirstFreeRootIndex = -1i64;
  this->ListRoot.vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  this->ListRoot.pRCC = 0i64;
  this->ListRoot.RefCount = 1;
  this->ListRoot.vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::Root::`vftable;
  this->Flags = 0;
  this->pLastPtr = &this->ListRoot;
}

// File Line: 398
// RVA: 0x6D0970
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::~RefCountCollector<323>(
        Scaleform::GFx::AS2::RefCountCollector<323> *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable;
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, 0i64);
  this->ListRoot.vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable;
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease(&this->Roots);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 434
// RVA: 0x70FCE0
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(
        Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int RefCount; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // rdx
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNext; // r8
  unsigned int v6; // ecx
  int v7; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *v8; // rcx
  unsigned int v9; // eax
  signed int v10; // eax
  int v11; // ecx

  RefCount = this->RefCount;
  if ( (RefCount & 0x3FFFFFF) == 0 )
  {
    if ( (RefCount & 0x8000000) != 0 )
    {
      this->RefCount = RefCount | 0x4000000;
      return;
    }
    pRCC = this->pRCC;
    if ( (pRCC->ListRoot.RefCount & 0x8000000) != 0 )
    {
      this->vfptr->ExecuteForEachChild_GC(this, pRCC, Operation_Release);
    }
    else
    {
      pRCC->pLastPtr = &pRCC->ListRoot;
      v4 = this->pRCC;
      v4->ListRoot.pPrev = &v4->ListRoot;
      this->pRCC->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)&v4->ListRoot;
      this->pRCC->ListRoot.RefCount |= 0x8000000u;
      this->vfptr->ExecuteForEachChild_GC(this, this->pRCC, Operation_Release);
      while ( this->pRCC->ListRoot.pRCC != (Scaleform::GFx::AS2::RefCountCollector<323> *)&this->pRCC->ListRoot )
      {
        pNext = this->pRCC->ListRoot.pNext;
        pNext->pPrev->pRCC = pNext->pRCC;
        *(_QWORD *)pNext->pRCC->Roots.gap0 = pNext->pPrev;
        pNext->RefCount &= 0x77FFFFFFu;
        v6 = pNext->RefCount;
        pNext->pRCC = 0i64;
        if ( (v6 & 0x8000000) == 0 )
          pNext->RootIndex = -1;
        v7 = v6 & 0x77FFFFFF;
        pNext->pRCC = this->pRCC;
        pNext->RefCount = v7;
        if ( (v7 & 0x8000000) == 0 )
          pNext->RootIndex = -1;
        pNext->RefCount = v7 & 0xFBFFFFFF;
        this->pRCC->pLastPtr = this->pRCC->ListRoot.pPrev;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pNext);
      }
      v8 = this->pRCC;
      v8->ListRoot.RefCount &= 0x77FFFFFFu;
      v9 = v8->ListRoot.RefCount;
      v8->ListRoot.pRCC = 0i64;
      if ( (v9 & 0x8000000) == 0 )
        v8->ListRoot.RootIndex = -1;
    }
    this->RefCount &= 0x8FFFFFFF;
    v10 = this->RefCount;
    if ( v10 < 0 )
    {
      if ( (v10 & 0x8000000) == 0 )
      {
        Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(this->pRCC, this);
        goto LABEL_17;
      }
    }
    else if ( (v10 & 0x8000000) == 0 )
    {
LABEL_17:
      this->vfptr->Finalize_GC(this);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
      return;
    }
    Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(this);
    goto LABEL_17;
  }
  if ( (RefCount & 0x70000000) != 805306368 )
  {
    v11 = RefCount & 0x8FFFFFFF | 0x30000000;
    this->RefCount = v11;
    if ( (v11 & 0x8000000) == 0 && v11 >= 0 )
      Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(this->pRCC, this);
  }
}

// File Line: 575
// RVA: 0x6D94F0
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  unsigned int FirstFreeRootIndex; // eax
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // rdx
  __int64 v7; // rax
  unsigned __int64 Size; // rax
  unsigned __int64 v9; // rbp
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v10; // rdx
  bool v11; // al
  unsigned int RefCount; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *val; // [rsp+48h] [rbp+10h] BYREF

  val = root;
  if ( this->FirstFreeRootIndex == -1i64 )
  {
    Size = this->Roots.Size;
    root->RefCount |= 0x80000000;
    root->RootIndex = Size;
    this->Flags |= 1u;
    v9 = this->Roots.Size >> 10;
    if ( (v9 < this->Roots.NumPages
       || Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
            &this->Roots,
            this->Roots.Size >> 10))
      && (v10 = &this->Roots.Pages[v9][this->Roots.Size & 0x3FF]) != 0i64 )
    {
      *v10 = root;
      ++this->Roots.Size;
    }
    else
    {
      this->Flags &= ~1u;
      v11 = Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, 0i64);
      this->Flags |= 1u;
      if ( !v11
        || !Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(
              &this->Roots,
              &val) )
      {
        root->RefCount &= ~0x80000000;
        RefCount = root->RefCount;
        if ( (RefCount & 0x8000000) == 0 )
          root->RootIndex = -1;
        root->RefCount = RefCount & 0x8FFFFFFF;
      }
    }
    this->Flags &= ~1u;
  }
  else
  {
    FirstFreeRootIndex = this->FirstFreeRootIndex;
    root->RefCount |= 0x80000000;
    root->RootIndex = FirstFreeRootIndex;
    v5 = this->FirstFreeRootIndex;
    Pages = this->Roots.Pages;
    v7 = (__int64)Pages[v5 >> 10][v5 & 0x3FF] >> 1;
    Pages[v5 >> 10][v5 & 0x3FF] = root;
    this->FirstFreeRootIndex = v7;
  }
}

// File Line: 628
// RVA: 0x710100
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  signed int RefCount; // edx
  unsigned __int64 RootIndex; // rdx

  RefCount = root->RefCount;
  if ( RefCount < 0 && (RefCount & 0x8000000) == 0 )
  {
    RootIndex = root->RootIndex;
    if ( (_DWORD)RootIndex + 1 == this->Roots.Size )
    {
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        &this->Roots,
        RootIndex);
    }
    else
    {
      this->Roots.Pages[(unsigned __int64)(unsigned int)RootIndex >> 10][RootIndex & 0x3FF] = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((2 * this->FirstFreeRootIndex) | 1);
      this->FirstFreeRootIndex = root->RootIndex;
    }
    root->RefCount &= ~0x80000000;
    if ( (root->RefCount & 0x8000000) == 0 )
      root->RootIndex = -1;
  }
}

// File Line: 670
// RVA: 0x6DDEA0
char __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::Collect(
        Scaleform::GFx::AS2::RefCountCollector<323> *this,
        Scaleform::GFx::AS2::RefCountCollector<323>::Stats *pstat)
{
  Scaleform::Render::RenderBuffer *pObject; // rbx
  char v5; // di
  Scaleform::Render::RenderBuffer *v6; // rcx
  unsigned __int64 v7; // r13
  unsigned __int64 v8; // r15
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *p_ListRoot; // rbp
  unsigned __int64 Size; // r14
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *pRCC; // rbx
  unsigned int RefCount; // ecx
  int v14; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *j; // rbx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pNext; // rbx
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *v18; // rdi
  unsigned int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  Scaleform::AmpStats *v23; // [rsp+70h] [rbp+8h]

  if ( (this->Flags & 1) != 0 || !this->Roots.Size )
  {
    if ( pstat )
    {
      pstat->AdvanceStats.pObject = 0i64;
      *(_QWORD *)&pstat->RootsNumber = 0i64;
    }
    return 0;
  }
  else
  {
    if ( pstat )
    {
      if ( pstat->AdvanceStats.pObject )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pstat->AdvanceStats.pObject);
      pObject = (Scaleform::Render::RenderBuffer *)pstat->AdvanceStats.pObject;
      v23 = pstat->AdvanceStats.pObject;
      v5 = 1;
      v6 = (Scaleform::Render::RenderBuffer *)pstat->AdvanceStats.pObject;
    }
    else
    {
      v6 = 0i64;
      v23 = 0i64;
      v5 = 2;
      pObject = 0i64;
    }
    if ( (v5 & 2) != 0 )
    {
      v5 &= ~2u;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
    }
    if ( (v5 & 1) != 0 && pObject )
      Scaleform::RefCountImpl::Release(pObject);
    v7 = 0i64;
    v8 = 0i64;
    p_ListRoot = &this->ListRoot;
    do
    {
      Size = this->Roots.Size;
      v7 += (unsigned int)Size;
      this->pLastPtr = p_ListRoot;
      this->ListRoot.pPrev = p_ListRoot;
      this->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)p_ListRoot;
      this->ListRoot.RefCount |= 0x8000000u;
      for ( i = 0i64; i < Size; ++i )
      {
        pRCC = (Scaleform::GFx::AS2::RefCountCollector<323>::Root *)this->Roots.Pages[i >> 10][i & 0x3FF];
        if ( ((unsigned __int8)pRCC & 1) == 0 )
        {
          RefCount = pRCC->RefCount;
          if ( (RefCount & 0x70000000) == 805306368 )
          {
            if ( (RefCount & 0x8000000) == 0 )
            {
              pRCC->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)this->pLastPtr->pRCC->Roots.gap0;
              pRCC->pRCC = this->pLastPtr->pRCC;
              *(_QWORD *)this->pLastPtr->pRCC->Roots.gap0 = pRCC;
              this->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)pRCC;
              this->pLastPtr = pRCC;
              pRCC->RefCount |= 0x8000000u;
            }
            for ( ; pRCC != p_ListRoot; pRCC = (Scaleform::GFx::AS2::RefCountCollector<323>::Root *)pRCC->pRCC )
            {
              if ( (pRCC->RefCount & 0x70000000) != 0x10000000 )
              {
                pRCC->RefCount = pRCC->RefCount & 0x8FFFFFFF | 0x10000000;
                pRCC->vfptr->ExecuteForEachChild_GC(pRCC, this, Operation_MarkInCycle);
              }
            }
          }
          else
          {
            v14 = RefCount & 0x7FFFFFFF;
            pRCC->RefCount = v14;
            if ( (v14 & 0x8000000) == 0 )
              pRCC->RootIndex = -1;
          }
        }
      }
      this->FirstFreeRootIndex = -1i64;
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        &this->Roots,
        0i64);
      for ( j = this->ListRoot.pNext; j != p_ListRoot; j = j->pNext )
      {
        v16 = j->RefCount;
        if ( (v16 & 0x3FFFFFF) != 0 )
        {
          j->RefCount = v16 & 0x8FFFFFFF;
          this->pLastPtr = j;
          j->vfptr->ExecuteForEachChild_GC(j, this, Operation_ScanInUse);
        }
        else
        {
          j->RefCount = v16 & 0x8FFFFFFF | 0x20000000;
        }
      }
      pNext = this->ListRoot.pNext;
      if ( pNext != p_ListRoot )
      {
        do
        {
          v18 = (Scaleform::GFx::AS2::RefCountCollector<323>::Root *)pNext->pRCC;
          v19 = pNext->RefCount;
          if ( (v19 & 0x70000000) == 0x20000000 )
          {
            pNext->vfptr->Finalize_GC(pNext);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pNext);
            ++v8;
          }
          else
          {
            pNext->pRCC = this;
            v20 = v19 & 0x77FFFFFF;
            pNext->RefCount = v20;
            if ( (v20 & 0x8000000) == 0 )
              pNext->RootIndex = -1;
            if ( (v20 & 0x4000000) != 0 )
            {
              pNext->RefCount = v20 & 0xFBFFFFFF;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pNext);
            }
            else if ( (v20 & 0x70000000) == 805306368 )
            {
              Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(this, pNext);
            }
            else
            {
              v21 = v20 & 0x7FFFFFFF;
              pNext->RefCount = v21;
              if ( (v21 & 0x8000000) == 0 )
                pNext->RootIndex = -1;
            }
          }
          pNext = v18;
        }
        while ( v18 != p_ListRoot );
      }
      this->pLastPtr = p_ListRoot;
      this->ListRoot.pRCC = 0i64;
      this->ListRoot.RefCount &= 0x77FFFFFFu;
      if ( (this->ListRoot.RefCount & 0x8000000) == 0 )
        this->ListRoot.RootIndex = -1;
      this->FirstFreeRootIndex = -1i64;
    }
    while ( this->Roots.Size );
    if ( pstat )
    {
      pstat->RootsNumber = v7;
      if ( v7 < v8 )
        LODWORD(v8) = v7;
      pstat->RootsFreedTotal = v8;
      if ( v23 )
      {
        v23->vfptr[3].__vecDelDtor(v23, v7);
        v23->vfptr[4].__vecDelDtor(v23, pstat->RootsFreedTotal);
      }
    }
    return 1;
  }
}

