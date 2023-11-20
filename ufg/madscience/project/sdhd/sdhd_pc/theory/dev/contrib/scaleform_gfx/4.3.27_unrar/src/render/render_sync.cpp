// File Line: 34
// RVA: 0x997C40
bool __fastcall Scaleform::Render::FenceImpl::IsPending(Scaleform::Render::FenceImpl *this, __int64 waitType)
{
  bool result; // al

  if ( this->Parent )
    result = ((__int64 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))this->RSContext->vfptr[4].__vecDelDtor)(
               this->RSContext,
               waitType,
               this->APIHandle);
  else
    result = 0;
  return result;
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
  Scaleform::Render::Fence *v1; // rdi
  bool v2; // zf
  Scaleform::Render::FenceImpl *v3; // rcx
  Scaleform::Render::RenderSync *v4; // rbx
  Scaleform::Render::FenceImpl *v5; // rcx

  v1 = this;
  v2 = this->RefCount-- == 1;
  if ( v2 )
  {
    v2 = this->HasData == 0;
    v3 = this->Data;
    if ( v2 )
    {
      v1->Data = (Scaleform::Render::FenceImpl *)v3[4].Parent;
      v3[4].Parent = (Scaleform::Render::FenceFrame *)v1;
    }
    else
    {
      v4 = v3->RSContext;
      ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v3->RSContext->FenceFrameAlloc.pHeapOrPtr)(
        v3,
        v3->APIHandle);
      v5 = v1->Data;
      v5->RSContext = (Scaleform::Render::RenderSync *)v4->FenceImplAlloc.FirstEmptySlot;
      v4->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v5;
      v1->Data = (Scaleform::Render::FenceImpl *)v4->FenceAlloc.FirstEmptySlot;
      v4->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v1;
    }
  }
}

// File Line: 84
// RVA: 0x94A010
void __fastcall Scaleform::Render::FenceFrame::~FenceFrame(Scaleform::Render::FenceFrame *this)
{
  Scaleform::Render::FenceFrame *v1; // rbp
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *v2; // rdi
  __int64 v3; // rbx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *v4; // rsi
  Scaleform::Render::Fence *v5; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *v6; // rdx
  Scaleform::Render::RenderSync *v7; // rcx
  Scaleform::Render::Fence *v8; // rsi
  bool v9; // zf
  Scaleform::Render::FenceImpl *v10; // rcx
  Scaleform::Render::RenderSync *v11; // rbx
  Scaleform::Render::FenceImpl *v12; // rcx
  Scaleform::Render::Fence *v13; // rsi
  Scaleform::Render::FenceImpl *v14; // rcx
  Scaleform::Render::RenderSync *v15; // rbx
  Scaleform::Render::FenceImpl *v16; // rcx
  __m128i v17; // [rsp+30h] [rbp-28h]

  v1 = this;
  v2 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *)&this->Fences.Data.Data;
  v17 = (__m128i)(unsigned __int64)&this->Fences;
  _mm_store_si128(&v17, v17);
  v3 = v17.m128i_i64[1];
  v4 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *)v17.m128i_i64[0];
  while ( v4 != v2 || v3 != v2->Size )
  {
    v5 = v4->Data[v3].pObject;
    if ( v5->HasData )
    {
      v5->HasData = 0;
      v1->RSContext->vfptr[8].__vecDelDtor(
        (Scaleform::RefCountImplCore *)v1->RSContext,
        v4->Data[v3].pObject->Data->APIHandle);
      v6 = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v4->Data[v3].pObject->Data;
      v7 = v1->RSContext;
      v6->pNext = v7->FenceImplAlloc.FirstEmptySlot;
      v7->FenceImplAlloc.FirstEmptySlot = v6;
      v4->Data[v3].pObject->Data = (Scaleform::Render::FenceImpl *)v1->RSContext;
    }
    if ( v3 < (signed __int64)v4->Size )
      ++v3;
  }
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::ResizeNoConstruct(
    v2,
    v2,
    0i64);
  v8 = v1->FrameEndFence.pObject;
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
  v1->FrameEndFence.pObject = 0i64;
  v13 = v1->FrameEndFence.pObject;
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
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::Render::Fence>>::DestructArray(v2->Data, v2->Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2->Data);
}

// File Line: 105
// RVA: 0x94C4A0
void __fastcall Scaleform::Render::RenderSync::~RenderSync(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::RenderSync *v1; // rdi
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v2; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::PageType *v3; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v4; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v5; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v6; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v7; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderSync::`vftable;
  Scaleform::Render::RenderSync::ReleaseOutstandingFrames(this);
  v2 = v1->FenceAlloc.FirstPage;
  if ( v2 )
  {
    do
    {
      v3 = v2->pNext;
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v2 = v3;
    }
    while ( v3 );
  }
  v4 = v1->FenceImplAlloc.FirstPage;
  if ( v4 )
  {
    do
    {
      v5 = v4->pNext;
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v4 = v5;
    }
    while ( v5 );
  }
  v6 = v1->FenceFrameAlloc.FirstPage;
  if ( v6 )
  {
    do
    {
      v7 = v6->pNext;
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v6 = v7;
    }
    while ( v7 );
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 110
// RVA: 0x95A6C0
void __fastcall Scaleform::Render::RenderSync::BeginFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::RenderSync *v1; // rbx
  Scaleform::Render::FenceFrame *v2; // rax
  signed __int64 v3; // [rsp+50h] [rbp+18h]

  v1 = this;
  this->WithinFrame = 1;
  v2 = Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *)&this->FenceFrameAlloc.FirstPage);
  if ( v2 )
  {
    v2->pPrev = 0i64;
    v2->pNext = 0i64;
    v2->RSContext = 0i64;
    v2->WrappedAround = 0;
    v3 = (signed __int64)&v2->Fences;
    *(_OWORD *)v3 = 0ui64;
    *(_QWORD *)(v3 + 16) = 0i64;
    v2->FrameEndFence.pObject = 0i64;
  }
  v2->RSContext = v1;
  v2->pPrev = v1->FenceFrames.Root.pPrev;
  v2->pNext = (Scaleform::Render::FenceFrame *)&v1->FenceFrames;
  v1->FenceFrames.Root.pPrev->pNext = v2;
  v1->FenceFrames.Root.pPrev = v2;
  ++v1->OutstandingFrames;
  if ( !warned_1 )
    warned_1 = v1->OutstandingFrames >= 0x64;
}

// File Line: 125
// RVA: 0x970880
char __fastcall Scaleform::Render::RenderSync::EndFrame(Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *v1; // rsi
  Scaleform::Render::RenderSync *v2; // r14
  Scaleform::Render::FenceFrame *v4; // rdi
  Scaleform::Render::Fence *v5; // rax
  Scaleform::Render::Fence *v6; // rbx
  Scaleform::Render::Fence *v7; // rcx
  Scaleform::Render::Fence *v8; // rcx
  Scaleform::Render::FenceImpl *v9; // rdx
  char v10; // al
  Scaleform::Render::FenceFrame *v11; // rdi
  char v12; // bp
  Scaleform::Render::Fence *v13; // rcx
  Scaleform::Render::FenceImpl *v14; // r8
  Scaleform::Render::FenceFrame *v15; // rbx
  Scaleform::Render::FenceFrame *i; // rax

  v1 = &this->FenceFrames;
  v2 = this;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0;
  v4 = v1->Root.pPrev;
  v5 = Scaleform::Render::RenderSync::InsertFence(this);
  v6 = v5;
  if ( v5 )
    ++v5->RefCount;
  v7 = v4->FrameEndFence.pObject;
  if ( v7 )
    Scaleform::Render::Fence::Release(v7);
  v4->FrameEndFence.pObject = v6;
  v8 = v1->Root.pPrev->FrameEndFence.pObject;
  if ( v8->HasData )
    v9 = v8->Data;
  else
    v9 = 0i64;
  v10 = (__int64)v2->vfptr[7].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, v9->APIHandle);
  v11 = v2->FenceFrames.Root.pNext;
  v12 = v10;
  if ( v11 != v1->Root.pPrev )
  {
    do
    {
      v13 = v11->FrameEndFence.pObject;
      if ( !v13 )
        break;
      if ( v13->HasData )
      {
        v14 = v13->Data;
        if ( v13->Data )
        {
          if ( v14->Parent
            && ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v14->RSContext->vfptr[4].__vecDelDtor)(
                 v14->RSContext,
                 1i64,
                 v14->APIHandle) )
          {
            break;
          }
        }
      }
      v15 = v11->pNext;
      v11->pPrev->pNext = v15;
      v11->pNext->pPrev = v11->pPrev;
      v11->pPrev = (Scaleform::Render::FenceFrame *)-1i64;
      v11->pNext = (Scaleform::Render::FenceFrame *)-1i64;
      Scaleform::Render::FenceFrame::~FenceFrame(v11);
      v11->pPrev = (Scaleform::Render::FenceFrame *)v2->FenceFrameAlloc.FirstEmptySlot;
      v2->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)v11;
      --v2->OutstandingFrames;
      v11 = v15;
    }
    while ( v15 != v1->Root.pPrev );
  }
  if ( v12 )
  {
    for ( i = v2->FenceFrames.Root.pNext; i != (Scaleform::Render::FenceFrame *)v1; i = i->pNext )
      i->WrappedAround = 1;
  }
  v2->WithinFrame = 0;
  return 1;
}

// File Line: 164
// RVA: 0x995430
Scaleform::Render::Fence *__fastcall Scaleform::Render::RenderSync::InsertFence(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::RenderSync *v1; // rbx
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *v2; // r14
  __int64 v4; // rdi
  Scaleform::Render::FenceImpl *v5; // rax
  Scaleform::Render::FenceImpl *v6; // rsi
  signed __int64 v7; // rdx
  Scaleform::Render::FenceFrame *v8; // rcx
  Scaleform::Render::Fence *v9; // rax
  Scaleform::Render::Fence *v10; // rdi
  Scaleform::Render::FenceFrame *v11; // rbx
  Scaleform::Render::Fence **v12; // rdx

  v1 = this;
  v2 = &this->FenceFrames;
  if ( (Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *)this->FenceFrames.Root.pNext == &this->FenceFrames )
    return 0i64;
  v4 = ((__int64 (__cdecl *)(Scaleform::Render::RenderSync *))this->vfptr[6].__vecDelDtor)(this);
  v5 = Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> > *)&v1->FenceImplAlloc.FirstPage);
  v6 = v5;
  if ( v5 )
  {
    v7 = v1->NextFenceID + 1;
    v1->NextFenceID = v7;
    v8 = v2->Root.pPrev;
    v5->RSContext = v1;
    v5->Parent = v8;
    v5->APIHandle = v4;
    v5->FenceID = v7;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> > *)&v1->FenceAlloc.FirstPage);
  v10 = v9;
  if ( v9 )
  {
    v9->Data = 0i64;
    v9->RefCount = 1;
    v9->HasData = 0;
  }
  v9->HasData = 1;
  v9->Data = v6;
  v11 = v2->Root.pPrev;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1>>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Fence>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Fence>,2>,Scaleform::ArrayConstPolicy<128,64,1> > *)&v2->Root.pPrev->Fences.Data.Data,
    &v2->Root.pPrev->Fences,
    v2->Root.pPrev->Fences.Data.Size + 1);
  v12 = &v11->Fences.Data.Data[v11->Fences.Data.Size - 1].pObject;
  if ( v12 )
  {
    ++v10->RefCount;
    *v12 = v10;
  }
  Scaleform::Render::Fence::Release(v10);
  return v10;
}

// File Line: 178
// RVA: 0x9A80D0
void __fastcall Scaleform::Render::RenderSync::ReleaseOutstandingFrames(Scaleform::Render::RenderSync *this)
{
  Scaleform::Render::FenceFrame *v1; // rbx
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *v2; // rbp
  Scaleform::Render::RenderSync *v3; // rsi
  Scaleform::Render::FenceFrame *v4; // rdi

  v1 = this->FenceFrames.Root.pNext;
  v2 = &this->FenceFrames;
  v3 = this;
  if ( v1 != (Scaleform::Render::FenceFrame *)&this->FenceFrames )
  {
    do
    {
      v4 = v1->pNext;
      v1->pPrev->pNext = v4;
      v1->pNext->pPrev = v1->pPrev;
      v1->pPrev = (Scaleform::Render::FenceFrame *)-1i64;
      v1->pNext = (Scaleform::Render::FenceFrame *)-1i64;
      Scaleform::Render::FenceFrame::~FenceFrame(v1);
      v1->pPrev = (Scaleform::Render::FenceFrame *)v3->FenceFrameAlloc.FirstEmptySlot;
      v3->FenceFrameAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)v1;
      --v3->OutstandingFrames;
      v1 = v4;
    }
    while ( v4 != (Scaleform::Render::FenceFrame *)v2 );
  }
}

