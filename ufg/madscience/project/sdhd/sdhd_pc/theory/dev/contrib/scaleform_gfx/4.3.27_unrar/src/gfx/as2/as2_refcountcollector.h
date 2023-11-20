// File Line: 292
// RVA: 0x7100C0
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  unsigned int v1; // eax

  this->pPrev->pRCC = this->pRCC;
  *(_QWORD *)this->pRCC->Roots.gap0 = this->pPrev;
  this->RefCount &= 0x77FFFFFFu;
  v1 = this->RefCount >> 27;
  this->pRCC = 0i64;
  if ( !(v1 & 1) )
    this->RootIndex = -1;
}

// File Line: 316
// RVA: 0x6D0920
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::~RefCountBaseGC<323>(Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
}

// File Line: 397
// RVA: 0x6C6A90
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::RefCountCollector<323>(Scaleform::GFx::AS2::RefCountCollector<323> *this)
{
  Scaleform::ArrayPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,2> *v1; // [rsp+28h] [rbp+10h]
  Scaleform::GFx::AS2::RefCountCollector<323>::Root *v2; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS2::RefCountCollector<323>,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable';
  v1 = &this->Roots;
  v1->Size = 0i64;
  v1->NumPages = 0i64;
  v1->MaxPages = 0i64;
  v1->Pages = 0i64;
  this->FirstFreeRootIndex = -1i64;
  v2 = &this->ListRoot;
  *(_OWORD *)&v2->vfptr = (unsigned __int64)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
  v2->RefCount = 1;
  v2->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::Root::`vftable';
  this->Flags = 0;
  this->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&this->ListRoot.vfptr;
}

// File Line: 398
// RVA: 0x6D0970
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::~RefCountCollector<323>(Scaleform::GFx::AS2::RefCountCollector<323> *this)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::RefCountCollector<323>::`vftable';
  Scaleform::GFx::AS2::RefCountCollector<323>::Collect(this, 0i64);
  v1->ListRoot.vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)v1->Roots.gap0);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 434
// RVA: 0x70FCE0
void __fastcall Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Scaleform::GFx::AS2::RefCountBaseGC<323> *this)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v1; // rbx
  unsigned int v2; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rdx
  Scaleform::GFx::AS2::RefCountCollector<323> *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // r8
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // ecx

  v1 = this;
  v2 = this->RefCount;
  if ( !(v2 & 0x3FFFFFF) )
  {
    if ( (v2 >> 27) & 1 )
    {
      v1->RefCount = v2 | 0x4000000;
      return;
    }
    v3 = v1->pRCC;
    if ( (v3->ListRoot.RefCount >> 27) & 1 )
    {
      v1->vfptr->ExecuteForEachChild_GC(v1, v3, 0i64);
    }
    else
    {
      v3->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->ListRoot.vfptr;
      v4 = v1->pRCC;
      v4->ListRoot.pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->ListRoot.vfptr;
      v1->pRCC->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)((char *)v4 + 64);
      v1->pRCC->ListRoot.RefCount |= 0x8000000u;
      v1->vfptr->ExecuteForEachChild_GC(v1, v1->pRCC, 0i64);
      while ( v1->pRCC->ListRoot.pRCC != (Scaleform::GFx::AS2::RefCountCollector<323> *)((char *)v1->pRCC + 64) )
      {
        v5 = v1->pRCC->ListRoot.pNext;
        v5->pPrev->pRCC = v5->pRCC;
        *(_QWORD *)v5->pRCC->Roots.gap0 = v5->pPrev;
        v5->RefCount &= 0x77FFFFFFu;
        v6 = v5->RefCount;
        v7 = v5->RefCount;
        v5->pRCC = 0i64;
        if ( !((v7 >> 27) & 1) )
          v5->RootIndex = -1;
        v8 = v6 & 0x77FFFFFF;
        v5->pRCC = v1->pRCC;
        v5->RefCount = v8;
        if ( !((v8 >> 27) & 1) )
          v5->RootIndex = -1;
        v5->RefCount = v8 & 0xFBFFFFFF;
        v1->pRCC->pLastPtr = v1->pRCC->ListRoot.pPrev;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
      v9 = v1->pRCC;
      v9->ListRoot.RefCount &= 0x77FFFFFFu;
      v10 = v9->ListRoot.RefCount;
      v9->ListRoot.pRCC = 0i64;
      if ( !((v10 >> 27) & 1) )
        v9->ListRoot.RootIndex = -1;
    }
    v1->RefCount &= 0x8FFFFFFF;
    v11 = v1->RefCount;
    v12 = v11 >> 27;
    if ( (v11 & 0x80000000) != 0 )
    {
      if ( !(v12 & 1) )
      {
        Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(v1->pRCC, v1);
        goto LABEL_17;
      }
    }
    else if ( !(v12 & 1) )
    {
LABEL_17:
      v1->vfptr->Finalize_GC(v1);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
      return;
    }
    Scaleform::GFx::AS2::RefCountBaseGC<323>::RemoveFromList(v1);
    goto LABEL_17;
  }
  if ( (v2 & 0x70000000) != 805306368 )
  {
    v13 = v2 & 0xBFFFFFFF | 0x30000000;
    v1->RefCount = v13;
    if ( !((v13 >> 27) & 1) && (v13 & 0x80000000) == 0 )
      Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(v1->pRCC, v1);
  }
}

// File Line: 575
// RVA: 0x6D94F0
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(Scaleform::GFx::AS2::RefCountCollector<323> *this, Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rdi
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rbx
  unsigned int v4; // eax
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v6; // rdx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rbp
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v10; // rdx
  bool v11; // al
  unsigned int v12; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *val; // [rsp+48h] [rbp+10h]

  val = root;
  v2 = root;
  v3 = this;
  if ( this->FirstFreeRootIndex == -1i64 )
  {
    v8 = this->Roots.Size;
    root->RefCount |= 0x80000000;
    root->RootIndex = v8;
    this->Flags |= 1u;
    v9 = this->Roots.Size >> 10;
    if ( (v9 < this->Roots.NumPages
       || Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
            (Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)this->Roots.gap0,
            this->Roots.Size >> 10))
      && (v10 = &v3->Roots.Pages[v9][v3->Roots.Size & 0x3FF]) != 0i64 )
    {
      *v10 = v2;
      ++v3->Roots.Size;
    }
    else
    {
      v3->Flags &= 0xFEu;
      v11 = Scaleform::GFx::AS2::RefCountCollector<323>::Collect(v3, 0i64);
      v3->Flags |= 1u;
      if ( !v11
        || !Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(
              (Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)v3->Roots.gap0,
              &val) )
      {
        v2->RefCount &= 0x7FFFFFFFu;
        v12 = v2->RefCount;
        if ( !((v2->RefCount >> 27) & 1) )
          v2->RootIndex = -1;
        v2->RefCount = v12 & 0x8FFFFFFF;
      }
    }
    v3->Flags &= 0xFEu;
  }
  else
  {
    v4 = this->FirstFreeRootIndex;
    root->RefCount |= 0x80000000;
    root->RootIndex = v4;
    v5 = this->FirstFreeRootIndex;
    v6 = this->Roots.Pages;
    v7 = (signed __int64)v6[v5 >> 10][this->FirstFreeRootIndex & 0x3FF] >> 1;
    v6[this->FirstFreeRootIndex >> 10][v5 & 0x3FF] = v2;
    this->FirstFreeRootIndex = v7;
  }
}

// File Line: 628
// RVA: 0x710100
void __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::RemoveFromRoots(Scaleform::GFx::AS2::RefCountCollector<323> *this, Scaleform::GFx::AS2::RefCountBaseGC<323> *root)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v2; // rbx
  unsigned int v3; // edx
  unsigned __int64 v4; // rdx

  v2 = root;
  v3 = root->RefCount;
  if ( (v3 & 0x80000000) != 0 && !((v3 >> 27) & 1) )
  {
    v4 = v2->RootIndex;
    if ( (_DWORD)v4 + 1 == this->Roots.Size )
    {
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        (Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)this->Roots.gap0,
        v4);
    }
    else
    {
      this->Roots.Pages[(unsigned __int64)(unsigned int)v4 >> 10][v4 & 0x3FF] = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(2 * this->FirstFreeRootIndex | 1);
      this->FirstFreeRootIndex = v2->RootIndex;
    }
    v2->RefCount &= 0x7FFFFFFFu;
    if ( !((v2->RefCount >> 27) & 1) )
      v2->RootIndex = -1;
  }
}

// File Line: 670
// RVA: 0x6DDEA0
char __fastcall Scaleform::GFx::AS2::RefCountCollector<323>::Collect(Scaleform::GFx::AS2::RefCountCollector<323> *this, Scaleform::GFx::AS2::RefCountCollector<323>::Stats *pstat)
{
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats *v2; // r12
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rsi
  Scaleform::Render::RenderBuffer *v4; // rbx
  char v5; // di
  Scaleform::Render::RenderBuffer *v6; // rcx
  unsigned __int64 v7; // r13
  unsigned __int64 v8; // r15
  signed __int64 v9; // rbp
  unsigned __int64 v10; // r14
  unsigned __int64 v11; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rbx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *i; // rbx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rdi
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  char result; // al
  Scaleform::AmpStats *v23; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS2::RefCountCollector<323>::Stats *v24; // [rsp+78h] [rbp+10h]

  v24 = pstat;
  v2 = pstat;
  v3 = this;
  if ( this->Flags & 1 || !this->Roots.Size )
  {
    if ( pstat )
    {
      pstat->AdvanceStats.pObject = 0i64;
      *(_QWORD *)&pstat->RootsNumber = 0i64;
    }
    result = 0;
  }
  else
  {
    if ( pstat )
    {
      if ( pstat->AdvanceStats.pObject )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pstat->AdvanceStats.pObject);
      v4 = (Scaleform::Render::RenderBuffer *)v2->AdvanceStats.pObject;
      v23 = v2->AdvanceStats.pObject;
      v5 = 1;
      v6 = (Scaleform::Render::RenderBuffer *)v2->AdvanceStats.pObject;
    }
    else
    {
      v6 = 0i64;
      v23 = 0i64;
      v5 = 2;
      v4 = 0i64;
    }
    if ( v5 & 2 )
    {
      v5 &= 0xFDu;
      if ( v6 )
        Scaleform::RefCountImpl::Release(v6);
    }
    if ( v5 & 1 && v4 )
      Scaleform::RefCountImpl::Release(v4);
    v7 = 0i64;
    v8 = 0i64;
    v9 = (signed __int64)&v3->ListRoot;
    do
    {
      v10 = v3->Roots.Size;
      v7 += (unsigned int)v3->Roots.Size;
      v3->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
      v3->ListRoot.pPrev = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
      v3->ListRoot.pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v9;
      v3->ListRoot.RefCount |= 0x8000000u;
      v11 = 0i64;
      if ( v10 )
      {
        do
        {
          v12 = v3->Roots.Pages[v11 >> 10][v11 & 0x3FF];
          if ( !((unsigned __int8)v12 & 1) )
          {
            v13 = v12->RefCount;
            if ( (v12->RefCount & 0x70000000) == 805306368 )
            {
              if ( !((v13 >> 27) & 1) )
              {
                v12->pPrev = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)v3->pLastPtr->pRCC->Roots.gap0;
                v12->pRCC = v3->pLastPtr->pRCC;
                *(_QWORD *)v3->pLastPtr->pRCC->Roots.gap0 = v12;
                v3->pLastPtr->pRCC = (Scaleform::GFx::AS2::RefCountCollector<323> *)v12;
                v3->pLastPtr = v12;
                v12->RefCount |= 0x8000000u;
              }
              for ( ; v12 != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9; v12 = v12->pNext )
              {
                if ( (v12->RefCount & 0x70000000) != 0x10000000 )
                {
                  v12->RefCount = v12->RefCount & 0x9FFFFFFF | 0x10000000;
                  v12->vfptr->ExecuteForEachChild_GC(v12, v3, Operation_MarkInCycle);
                }
              }
            }
            else
            {
              v14 = v13 & 0x7FFFFFFF;
              v12->RefCount = v14;
              if ( !((v14 >> 27) & 1) )
                v12->RootIndex = -1;
            }
          }
          ++v11;
        }
        while ( v11 < v10 );
      }
      v3->FirstFreeRootIndex = -1i64;
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        (Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)v3->Roots.gap0,
        0i64);
      for ( i = v3->ListRoot.pNext; i != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9; i = i->pNext )
      {
        v16 = i->RefCount;
        if ( v16 & 0x3FFFFFF )
        {
          i->RefCount = v16 & 0x8FFFFFFF;
          v3->pLastPtr = i;
          i->vfptr->ExecuteForEachChild_GC(i, v3, Operation_ScanInUse);
        }
        else
        {
          i->RefCount = v16 & 0xAFFFFFFF | 0x20000000;
        }
      }
      v17 = v3->ListRoot.pNext;
      if ( v17 != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9 )
      {
        do
        {
          v18 = v17->pNext;
          v19 = v17->RefCount;
          if ( (v17->RefCount & 0x70000000) == 0x20000000 )
          {
            v17->vfptr->Finalize_GC(v17);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17);
            ++v8;
          }
          else
          {
            v17->pRCC = v3;
            v20 = v19 & 0x77FFFFFF;
            v17->RefCount = v20;
            if ( !((v20 >> 27) & 1) )
              v17->RootIndex = -1;
            if ( (v20 >> 26) & 1 )
            {
              v17->RefCount = v20 & 0xFBFFFFFF;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
            }
            else if ( (v20 & 0x70000000) == 805306368 )
            {
              Scaleform::GFx::AS2::RefCountCollector<323>::AddRoot(v3, v17);
            }
            else
            {
              v21 = v20 & 0x7FFFFFFF;
              v17->RefCount = v21;
              if ( !((v21 >> 27) & 1) )
                v17->RootIndex = -1;
            }
          }
          v17 = v18;
        }
        while ( v18 != (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9 );
      }
      v3->pLastPtr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
      v3->ListRoot.pRCC = 0i64;
      v3->ListRoot.RefCount &= 0x77FFFFFFu;
      if ( !((v3->ListRoot.RefCount >> 27) & 1) )
        v3->ListRoot.RootIndex = -1;
      v3->FirstFreeRootIndex = -1i64;
    }
    while ( v3->Roots.Size );
    if ( v24 )
    {
      v24->RootsNumber = v7;
      if ( v7 < v8 )
        LODWORD(v8) = v7;
      v24->RootsFreedTotal = v8;
      if ( v23 )
      {
        v23->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, v7);
        v23->vfptr[4].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, v24->RootsFreedTotal);
      }
    }
    result = 1;
  }
  return result;
}

