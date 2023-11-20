// File Line: 172
// RVA: 0x9FB760
void __fastcall Scaleform::Render::RenderSync::RenderSync(Scaleform::Render::RenderSync *this)
{
  Scaleform::List<Scaleform::Render::FenceFrame,Scaleform::Render::FenceFrame> *v1; // rax
  Scaleform::ListAllocLH<Scaleform::Render::FenceFrame,127,2> *v2; // [rsp+28h] [rbp+10h]
  Scaleform::ListAllocLH_POD<Scaleform::Render::FenceImpl,127,2> *v3; // [rsp+28h] [rbp+10h]
  Scaleform::ListAllocLH<Scaleform::Render::Fence,127,2> *v4; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::RenderSync,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderSync::`vftable';
  v1 = &this->FenceFrames;
  v1->Root.pPrev = (Scaleform::Render::FenceFrame *)v1;
  v1->Root.pNext = (Scaleform::Render::FenceFrame *)v1;
  v2 = &this->FenceFrameAlloc;
  *(_OWORD *)&v2->FirstPage = 0ui64;
  v2->NumElementsInPage = 127;
  v2->FirstEmptySlot = 0i64;
  v2->pHeapOrPtr = v2;
  v3 = &this->FenceImplAlloc;
  *(_OWORD *)&v3->FirstPage = 0ui64;
  v3->NumElementsInPage = 127;
  v3->FirstEmptySlot = 0i64;
  v3->pHeapOrPtr = v3;
  v4 = &this->FenceAlloc;
  *(_OWORD *)&v4->FirstPage = 0ui64;
  v4->NumElementsInPage = 127;
  v4->FirstEmptySlot = 0i64;
  v4->pHeapOrPtr = v4;
  this->NextFenceID = 0i64;
  this->OutstandingFrames = 0;
  this->WithinFrame = 0;
}

// File Line: 226
// RVA: 0x9FBC00
void __fastcall Scaleform::Render::FenceWrapperList::~FenceWrapperList(Scaleform::Render::FenceWrapperList *this)
{
  this->vfptr = (Scaleform::Render::FenceWrapperListVtbl *)&Scaleform::Render::FenceWrapperList::`vftable';
}

// File Line: 230
// RVA: 0x9FF410
void __fastcall Scaleform::Render::FenceWrapperList::Initialize(Scaleform::Render::FenceWrapperList *this)
{
  unsigned int v1; // edi
  Scaleform::Render::FenceWrapperList *v2; // rbx
  unsigned int *v3; // rsi
  __int64 v4; // rax

  v1 = 0;
  v2 = this;
  if ( this->ReservePoolSize )
  {
    v3 = &this[-1].ReservePoolSize;
    do
    {
      v4 = (__int64)v2->vfptr->allocateWrapper(v2);
      ++v1;
      *(_QWORD *)(v4 + 16) = v2->WrapperList.Root.pPrev;
      *(_QWORD *)(v4 + 24) = v3;
      v2->WrapperList.Root.pPrev->pNext = (Scaleform::Render::FenceWrapper *)v4;
      v2->WrapperList.Root.pPrev = (Scaleform::Render::FenceWrapper *)v4;
    }
    while ( v1 < v2->ReservePoolSize );
  }
}

// File Line: 240
// RVA: 0xA02E80
void __fastcall Scaleform::Render::FenceWrapperList::Shutdown(Scaleform::Render::FenceWrapperList *this)
{
  Scaleform::Render::FenceWrapperList *v1; // rdi
  Scaleform::List<Scaleform::Render::FenceWrapper,Scaleform::Render::FenceWrapper> *v2; // rbx
  signed __int64 v3; // rax
  Scaleform::Render::FenceWrapper *v4; // rcx

  v1 = this;
  v2 = &this->WrapperList;
  while ( 1 )
  {
    v3 = (signed __int64)(v2 ? &v2[-1] : 0i64);
    if ( v2->Root.pNext == (Scaleform::Render::FenceWrapper *)v3 )
      break;
    v4 = v1->WrapperList.Root.pNext;
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->pPrev = v4->pPrev;
    v4->pPrev = (Scaleform::Render::FenceWrapper *)-1i64;
    v4->pNext = (Scaleform::Render::FenceWrapper *)-1i64;
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
  }
}

// File Line: 251
// RVA: 0x9FCBE0
Scaleform::GFx::Resource *__fastcall Scaleform::Render::FenceWrapperList::Alloc(Scaleform::Render::FenceWrapperList *this)
{
  Scaleform::Render::FenceWrapper *v1; // rdx
  Scaleform::GFx::Resource *v2; // rbx

  if ( this == (Scaleform::Render::FenceWrapperList *)-8i64 )
    v1 = 0i64;
  else
    v1 = (Scaleform::Render::FenceWrapper *)&this[-1].ReservePoolSize;
  if ( this->WrapperList.Root.pNext == v1 )
  {
    v2 = (Scaleform::GFx::Resource *)((__int64 (*)(void))this->vfptr->allocateWrapper)();
  }
  else
  {
    v2 = (Scaleform::GFx::Resource *)this->WrapperList.Root.pNext;
    *(_QWORD *)&v2->pLib[1].RefCount = v2[1].vfptr;
    v2[1].vfptr->GetResourceTypeCode = (unsigned int (__fastcall *)(Scaleform::GFx::Resource *))v2->pLib;
    v2->pLib = (Scaleform::GFx::ResourceLibBase *)-1i64;
    v2[1].vfptr = (Scaleform::GFx::ResourceVtbl *)-1i64;
  }
  Scaleform::Render::RenderBuffer::AddRef(v2);
  return v2;
}

