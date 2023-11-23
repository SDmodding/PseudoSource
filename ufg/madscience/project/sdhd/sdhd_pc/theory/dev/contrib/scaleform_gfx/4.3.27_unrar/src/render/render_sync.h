// File Line: 172
// RVA: 0x9FB760
void __fastcall Scaleform::Render::RenderSync::RenderSync(Scaleform::Render::RenderSync *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::RenderSync,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderSync::`vftable;
  this->FenceFrames.Root.pPrev = (Scaleform::Render::FenceFrame *)&this->FenceFrames;
  this->FenceFrames.Root.pNext = (Scaleform::Render::FenceFrame *)&this->FenceFrames;
  this->FenceFrameAlloc.FirstPage = 0i64;
  this->FenceFrameAlloc.LastPage = 0i64;
  this->FenceFrameAlloc.NumElementsInPage = 127;
  this->FenceFrameAlloc.FirstEmptySlot = 0i64;
  this->FenceFrameAlloc.pHeapOrPtr = &this->FenceFrameAlloc;
  this->FenceImplAlloc.FirstPage = 0i64;
  this->FenceImplAlloc.LastPage = 0i64;
  this->FenceImplAlloc.NumElementsInPage = 127;
  this->FenceImplAlloc.FirstEmptySlot = 0i64;
  this->FenceImplAlloc.pHeapOrPtr = &this->FenceImplAlloc;
  this->FenceAlloc.FirstPage = 0i64;
  this->FenceAlloc.LastPage = 0i64;
  this->FenceAlloc.NumElementsInPage = 127;
  this->FenceAlloc.FirstEmptySlot = 0i64;
  this->FenceAlloc.pHeapOrPtr = &this->FenceAlloc;
  this->NextFenceID = 0i64;
  this->OutstandingFrames = 0;
  this->WithinFrame = 0;
}

// File Line: 226
// RVA: 0x9FBC00
void __fastcall Scaleform::Render::FenceWrapperList::~FenceWrapperList(Scaleform::Render::FenceWrapperList *this)
{
  this->vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::FenceWrapperList::`vftable;
}

// File Line: 230
// RVA: 0x9FF410
void __fastcall Scaleform::Render::FenceWrapperList::Initialize(Scaleform::Render::FenceWrapperList *this)
{
  unsigned int v1; // edi
  unsigned int *p_ReservePoolSize; // rsi
  Scaleform::Render::FenceWrapper *v4; // rax

  v1 = 0;
  if ( this->ReservePoolSize )
  {
    p_ReservePoolSize = &this[-1].ReservePoolSize;
    do
    {
      v4 = this->vfptr->allocateWrapper(this);
      ++v1;
      v4->pPrev = this->WrapperList.Root.pPrev;
      v4->pNext = (Scaleform::Render::FenceWrapper *)p_ReservePoolSize;
      this->WrapperList.Root.pPrev->pNext = v4;
      this->WrapperList.Root.pPrev = v4;
    }
    while ( v1 < this->ReservePoolSize );
  }
}

// File Line: 240
// RVA: 0xA02E80
void __fastcall Scaleform::Render::FenceWrapperList::Shutdown(Scaleform::Render::FenceWrapperList *this)
{
  Scaleform::List<Scaleform::Render::FenceWrapper,Scaleform::Render::FenceWrapper> *p_WrapperList; // rbx
  __int64 v3; // rax
  Scaleform::Render::FenceWrapper *pNext; // rcx

  p_WrapperList = &this->WrapperList;
  while ( 1 )
  {
    v3 = p_WrapperList ? (__int64)&p_WrapperList[-1] : 0i64;
    if ( p_WrapperList->Root.pNext == (Scaleform::Render::FenceWrapper *)v3 )
      break;
    pNext = this->WrapperList.Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::FenceWrapper *)-1i64;
    pNext->pNext = (Scaleform::Render::FenceWrapper *)-1i64;
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pNext);
  }
}

// File Line: 251
// RVA: 0x9FCBE0
Scaleform::GFx::Resource *__fastcall Scaleform::Render::FenceWrapperList::Alloc(
        Scaleform::Render::FenceWrapperList *this)
{
  Scaleform::Render::FenceWrapper *p_ReservePoolSize; // rdx
  Scaleform::GFx::Resource *pNext; // rbx

  if ( this == (Scaleform::Render::FenceWrapperList *)-8i64 )
    p_ReservePoolSize = 0i64;
  else
    p_ReservePoolSize = (Scaleform::Render::FenceWrapper *)&this[-1].ReservePoolSize;
  if ( this->WrapperList.Root.pNext == p_ReservePoolSize )
  {
    pNext = (Scaleform::GFx::Resource *)this->vfptr->allocateWrapper(this);
  }
  else
  {
    pNext = (Scaleform::GFx::Resource *)this->WrapperList.Root.pNext;
    *(_QWORD *)&pNext->pLib[1].RefCount = pNext[1].vfptr;
    pNext[1].vfptr->GetResourceTypeCode = (unsigned int (__fastcall *)(Scaleform::GFx::Resource *))pNext->pLib;
    pNext->pLib = (Scaleform::GFx::ResourceLibBase *)-1i64;
    pNext[1].vfptr = (Scaleform::GFx::ResourceVtbl *)-1i64;
  }
  Scaleform::Render::RenderBuffer::AddRef(pNext);
  return pNext;
}

