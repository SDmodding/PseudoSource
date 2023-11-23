// File Line: 34
// RVA: 0x997C40
bool __fastcall Scaleform::Render::FenceImpl::IsPending(Scaleform::Render::FenceImpl *this, __int64 waitType)
{
  if ( this->Parent )
    return ((__int64 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))this->RSContext->vfptr[4].__vecDelDtor)(
             this->RSContext,
             waitType,
             this->APIHandle);
  else
    return 0;
}

// File Line: 42
// RVA: 0x9C26E0
void __fastcall Scaleform::Render::FenceImpl::WaitFence(Scaleform::Render::FenceImpl *this, __int64 waitType)
{
  if ( this->Parent )
    ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))this->RSContext->vfptr[5].__vecDelDtor)(
      this->RSContext,
      waitType,
      this->APIHandle);
}

// File Line: 62
// RVA: 0x9A7860
void __fastcall Scaleform::Render::Fence::Release(Scaleform::Render::Fence *this)
{
  bool v2; // zf
  Scaleform::Render::FenceImpl *Data; // rcx
  Scaleform::Render::RenderSync *RSContext; // rbx
  Scaleform::Render::FenceImpl *v5; // rcx

  v2 = this->RefCount-- == 1;
  if ( v2 )
  {
    v2 = this->HasData == 0;
    Data = this->Data;
    if ( v2 )
    {
      this->Data = (Scaleform::Render::FenceImpl *)Data[4].Parent;
      Data[4].Parent = (Scaleform::Render::FenceFrame *)this;
    }
    else
    {
      RSContext = Data->RSContext;
      ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))Data->RSContext->FenceFrameAlloc.pHeapOrPtr)(
        Data,
        Data->APIHandle);
      v5 = this->Data;
      v5->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
      RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v5;
      this->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
      RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)this;
    }
  }
}

// File Line: 84
// RVA: 0x94A010
void __fastcall Scaleform::Render::FenceFrame::~FenceFrame(Scaleform::Render::FenceFrame *this)
{
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::Render::Fence>,2,Scaleform::ArrayConstPolicy<128,64,1> > *p_Fences; // rdi
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::Render::Fence>,2,Scaleform::ArrayConstPolicy<128,64,1> > *v3; // rsi
  signed __int64 v4; // rbx
  Scaleform::Render::Fence *pObject; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *Data; // rdx
  Scaleform::Render::RenderSync *RSContext; // rcx
  Scaleform::Render::Fence *v8; // rsi
  bool v9; // zf
  Scaleform::Render::FenceImpl *v10; // rcx
  Scaleform::Render::RenderSync *v11; // rbx
  Scaleform::Render::FenceImpl *v12; // rcx
  Scaleform::Render::Fence *v13; // rsi
  Scaleform::Render::FenceImpl *v14; // rcx
  Scaleform::Render::RenderSync *v15; // rbx
  Scaleform::Render::FenceImpl *v16; // rcx

  p_Fences = &this->Fences;
  v3 = &this->Fences;
  v4 = 0i64;
  while ( v3 != p_Fences || v4 != p_Fences->Data.Size )
  {
    pObject = v3->Data.Data[v4].pObject;
    if ( pObject->HasData )
    {
      pObject->HasData = 0;
      this->RSContext->vfptr[8].__vecDelDtor(this->RSContext, v3->Data.Data[v4].pObject->Data->APIHandle);
      Data = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v3->Data.Data[v4].pObject->Data;
      RSContext = this->RSContext;
      Data->pNext = RSContext->FenceImplAlloc.FirstEmptySlot;
      RSContext->FenceImplAlloc.FirstEmptySlot = Data;
      v3->Data.Data[v4].pObject->Data = (Scaleform::Render::FenceImpl *)this->RSContext;
    }
    if ( v4 < (signed __int64)v3->Data.Size )
      ++v4;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::ResizeNoConstruct(
    &p_Fences->Data,
    p_Fences,
    0i64);
  v8 = this->FrameEndFence.pObject;
  if ( v8 )
  {
    v9 = v8->RefCount-- == 1;
    if ( v9 )
    {
      v10 = v8->Data;
      if ( v8->HasData )
      {
        v11 = v10->RSContext;
        ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v10->RSContext->FenceFrameAlloc.pHeapOrPtr)(
          v10,
          v10->APIHandle);
        v12 = v8->Data;
        v12->RSContext = (Scaleform::Render::RenderSync *)v11->FenceImplAlloc.FirstEmptySlot;
        v11->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v12;
        v8->Data = (Scaleform::Render::FenceImpl *)v11->FenceAlloc.FirstEmptySlot;
        v11->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v8;
      }
      else
      {
        v8->Data = (Scaleform::Render::FenceImpl *)v10[4].Parent;
        v10[4].Parent = (Scaleform::Render::FenceFrame *)v8;
      }
    }
  }
  this->FrameEndFence.pObject = 0i64;
  v13 = this->FrameEndFence.pObject;
  if ( v13 )
  {
    v9 = v13->RefCount-- == 1;
    if ( v9 )
    {
      v14 = v13->Data;
      if ( v13->HasData )
      {
        v15 = v14->RSContext;
        ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v14->RSContext->FenceFrameAlloc.pHeapOrPtr)(
          v14,
          v14->APIHandle);
        v16 = v13->Data;
        v16->RSContext = (Scaleform::Render::RenderSync *)v15->FenceImplAlloc.FirstEmptySlot;
        v15->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v16;
        v13->Data = (Scaleform::Render::FenceImpl *)v15->FenceAlloc.FirstEmptySlot;
        v15->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v13;
      }
      else
      {
        v13->Data = (Scaleform::Render::FenceImpl *)v14[4].Parent;
        v14[4].Parent = (Scaleform::Render::FenceFrame *)v13;
      }
    }
  }
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(
    p_Fences->Data.Data,
    p_Fences->Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_Fences->Data.Data);
}

// File Line: 105
// RVA: 0x94C4A0
void __fastcall Scaleform::Render::RenderSync::~RenderSync(Scaleform::Render::RenderSync *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *FirstPage; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *pNext; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v4; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v5; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v6; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v7; // rbx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderSync::`vftable;
  Scaleform::Render::RenderSync::ReleaseOutstandingFrames(this);
  FirstPage = this->FenceAlloc.FirstPage;
  if ( FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      FirstPage = pNext;
    }
    while ( pNext );
  }
  v4 = this->FenceImplAlloc.FirstPage;
  if ( v4 )
  {
    do
    {
      v5 = v4->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v4 = v5;
    }
    while ( v5 );
  }
  v6 = this->FenceFrameAlloc.FirstPage;
  if ( v6 )
  {
    do
    {
      v7 = v6->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v6 = v7;
    }
    while ( v7 );
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 110
// RVA: 0x95A6C0
void __fastcall Scaleform::Render::RenderSync::BeginFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::FenceFrame *v2; // rax

  this->WithinFrame = 1;
  v2 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate(&this->FenceFrameAlloc);
  if ( v2 )
  {
    v2->pPrev = 0i64;
    v2->pNext = 0i64;
    v2->RSContext = 0i64;
    v2->WrappedAround = 0;
    v2->Fences.Data.Data = 0i64;
    v2->Fences.Data.Size = 0i64;
    v2->Fences.Data.Policy.Capacity = 0i64;
    v2->FrameEndFence.pObject = 0i64;
  }
  v2->RSContext = this;
  v2->pPrev = this->FenceFrames.Root.pPrev;
  v2->pNext = (Scaleform::Render::FenceFrame *)&this->FenceFrames;
  this->FenceFrames.Root.pPrev->pNext = v2;
  this->FenceFrames.Root.pPrev = v2;
  ++this->OutstandingFrames;
  if ( !warned_1 )
    warned_1 = this->OutstandingFrames >= 0x64;
}

// File Line: 125
// RVA: 0x970880
char __fastcall Scaleform::Render::RenderSync::EndFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // rsi
  Scaleform::Render::FenceFrame *pPrev; // rdi
  Scaleform::Render::Fence *inserted; // rax
  Scaleform::Render::Fence *v6; // rbx
  Scaleform::Render::Fence *pObject; // rcx
  Scaleform::Render::Fence *v8; // rcx
  Scaleform::Render::FenceImpl *Data; // rdx
  char v10; // al
  Scaleform::Render::FenceFrame *pNext; // rdi
  char v12; // bp
  Scaleform::Render::Fence *v13; // rcx
  Scaleform::Render::FenceImpl *v14; // r8
  Scaleform::Render::FenceFrame *v15; // rbx
  Scaleform::Render::FenceFrame *i; // rax

  p_FenceFrames = &this->FenceFrames;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0;
  pPrev = p_FenceFrames->Root.pPrev;
  inserted = Scaleform::Render::RenderSync::InsertFence(this);
  v6 = inserted;
  if ( inserted )
    ++inserted->RefCount;
  pObject = pPrev->FrameEndFence.pObject;
  if ( pObject )
    Scaleform::Render::Fence::Release(pObject);
  pPrev->FrameEndFence.pObject = v6;
  v8 = p_FenceFrames->Root.pPrev->FrameEndFence.pObject;
  if ( v8->HasData )
    Data = v8->Data;
  else
    Data = 0i64;
  v10 = (char)this->vfptr[7].__vecDelDtor(this, Data->APIHandle);
  pNext = this->FenceFrames.Root.pNext;
  v12 = v10;
  if ( pNext != p_FenceFrames->Root.pPrev )
  {
    do
    {
      v13 = pNext->FrameEndFence.pObject;
      if ( !v13 )
        break;
      if ( v13->HasData )
      {
        v14 = v13->Data;
        if ( v13->Data )
        {
          if ( v14->Parent
            && ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))v14->RSContext->vfptr[4].__vecDelDtor)(
                 v14->RSContext,
                 1i64,
                 v14->APIHandle) )
          {
            break;
          }
        }
      }
      v15 = pNext->pNext;
      pNext->pPrev->pNext = v15;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::FenceFrame>::$5032416B5D868C6211F0AE4746352ADE::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::FenceFrame *)-1i64;
      pNext->pNext = (Scaleform::Render::FenceFrame *)-1i64;
      Scaleform::Render::FenceFrame::~FenceFrame(pNext);
      pNext->pPrev = (Scaleform::Render::FenceFrame *)this->FenceFrameAlloc.FirstEmptySlot;
      this->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)pNext;
      --this->OutstandingFrames;
      pNext = v15;
    }
    while ( v15 != p_FenceFrames->Root.pPrev );
  }
  if ( v12 )
  {
    for ( i = this->FenceFrames.Root.pNext; i != (Scaleform::Render::FenceFrame *)p_FenceFrames; i = i->pNext )
      i->WrappedAround = 1;
  }
  this->WithinFrame = 0;
  return 1;
}

// File Line: 164
// RVA: 0x995430
Scaleform::Render::Fence *__fastcall Scaleform::Render::RenderSync::InsertFence(Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // r14
  __int64 v4; // rdi
  Scaleform::Render::FenceImpl *v5; // rax
  Scaleform::Render::FenceImpl *v6; // rsi
  unsigned __int64 v7; // rdx
  Scaleform::Render::FenceFrame *pPrev; // rcx
  Scaleform::Render::Fence *v9; // rax
  Scaleform::Render::Fence *v10; // rdi
  Scaleform::Render::FenceFrame *v11; // rbx
  Scaleform::Render::Fence **p_pObject; // rdx

  p_FenceFrames = &this->FenceFrames;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0i64;
  v4 = ((__int64 (__fastcall *)(Scaleform::Render::RenderSync *))this->vfptr[6].__vecDelDtor)(this);
  v5 = Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2>>::allocate(&this->FenceImplAlloc);
  v6 = v5;
  if ( v5 )
  {
    v7 = this->NextFenceID + 1;
    this->NextFenceID = v7;
    pPrev = p_FenceFrames->Root.pPrev;
    v5->RSContext = this;
    v5->Parent = pPrev;
    v5->APIHandle = v4;
    v5->FenceID = v7;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2>>::allocate(&this->FenceAlloc);
  v10 = v9;
  if ( v9 )
  {
    v9->Data = 0i64;
    v9->RefCount = 1;
    v9->HasData = 0;
  }
  v9->HasData = 1;
  v9->Data = v6;
  v11 = p_FenceFrames->Root.pPrev;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::ResizeNoConstruct(
    &p_FenceFrames->Root.pPrev->Fences.Data,
    &p_FenceFrames->Root.pPrev->Fences,
    p_FenceFrames->Root.pPrev->Fences.Data.Size + 1);
  p_pObject = &v11->Fences.Data.Data[v11->Fences.Data.Size - 1].pObject;
  if ( p_pObject )
  {
    ++v10->RefCount;
    *p_pObject = v10;
  }
  Scaleform::Render::Fence::Release(v10);
  return v10;
}

// File Line: 178
// RVA: 0x9A80D0
void __fastcall Scaleform::Render::RenderSync::ReleaseOutstandingFrames(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::FenceFrame *pNext; // rbx
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *p_FenceFrames; // rbp
  Scaleform::Render::FenceFrame *v4; // rdi

  pNext = this->FenceFrames.Root.pNext;
  p_FenceFrames = &this->FenceFrames;
  if ( pNext != (Scaleform::Render::FenceFrame *)&this->FenceFrames )
  {
    do
    {
      v4 = pNext->pNext;
      pNext->pPrev->pNext = v4;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::FenceFrame>::$5032416B5D868C6211F0AE4746352ADE::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::FenceFrame *)-1i64;
      pNext->pNext = (Scaleform::Render::FenceFrame *)-1i64;
      Scaleform::Render::FenceFrame::~FenceFrame(pNext);
      pNext->pPrev = (Scaleform::Render::FenceFrame *)this->FenceFrameAlloc.FirstEmptySlot;
      this->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)pNext;
      --this->OutstandingFrames;
      pNext = v4;
    }
    while ( v4 != (Scaleform::Render::FenceFrame *)p_FenceFrames );
  }
}

