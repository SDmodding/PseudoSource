// File Line: 77
// RVA: 0x969340
Scaleform::MemoryHeap *__fastcall Scaleform::MemoryHeap::CreateRootHeapMH(Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::MemoryHeap::HeapDesc desca; // [rsp+30h] [rbp-48h]

  v1 = desc;
  if ( !Scaleform::HeapMH::GlobalRootMH )
    return 0i64;
  v2 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    LeaveCriticalSection(v2);
    return 0i64;
  }
  *(_OWORD *)&desca.Flags = *(_OWORD *)&v1->Flags;
  *(_OWORD *)&desca.Granularity = *(_OWORD *)&v1->Granularity;
  *(_OWORD *)&desca.Threshold = *(_OWORD *)&v1->Threshold;
  *(_OWORD *)&desca.HeapId = *(_OWORD *)&v1->HeapId;
  desca.HeapId = 1i64;
  Scaleform::Memory::pGlobalHeap = (Scaleform::MemoryHeap *)Scaleform::HeapMH::RootMH::CreateHeap(
                                                              Scaleform::HeapMH::GlobalRootMH,
                                                              "Global",
                                                              0i64,
                                                              &desca);
  LeaveCriticalSection(v2);
  return Scaleform::Memory::pGlobalHeap;
}

// File Line: 114
// RVA: 0x9A82B0
char __fastcall Scaleform::MemoryHeap::ReleaseRootHeapMH()
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  bool v2; // di

  if ( !Scaleform::HeapMH::GlobalRootMH )
    return 1;
  v1 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    v2 = ((unsigned __int8 (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->dumpMemoryLeaks)(Scaleform::Memory::pGlobalHeap) == 0;
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->destroyItself)(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap = 0i64;
  }
  else
  {
    v2 = 1;
  }
  LeaveCriticalSection(v1);
  return v2;
}

// File Line: 155
// RVA: 0x997B90
char __fastcall Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(hkGeometryUtils::IVertices *this, int vertexA, int vertexB)
{
  return 1;
}

// File Line: 163
// RVA: 0x967410
Scaleform::MemoryHeapMH *__fastcall Scaleform::MemoryHeapMH::CreateHeap(Scaleform::MemoryHeapMH *this, const char *name, Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v3; // rbx
  const char *v4; // rdi
  Scaleform::MemoryHeapMH *v5; // rsi
  _RTL_CRITICAL_SECTION *v6; // rbp
  Scaleform::MemoryHeapMH *v7; // rdi

  v3 = desc;
  v4 = name;
  v5 = this;
  v6 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v7 = Scaleform::HeapMH::RootMH::CreateHeap(Scaleform::HeapMH::GlobalRootMH, v4, v5, v3);
  if ( v7 )
    ++v5->RefCount;
  LeaveCriticalSection(v6);
  if ( v7 )
  {
    EnterCriticalSection(&v5->HeapLock.cs);
    v7->pPrev = v5->ChildHeaps.Root.pPrev;
    v7->pNext = (Scaleform::MemoryHeap *)&v5->Info.pName;
    v5->ChildHeaps.Root.pPrev->pNext = (Scaleform::MemoryHeap *)&v7->vfptr;
    v5->ChildHeaps.Root.pPrev = (Scaleform::MemoryHeap *)&v7->vfptr;
    LeaveCriticalSection(&v5->HeapLock.cs);
  }
  return v7;
}

// File Line: 184
// RVA: 0x9848B0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetFootprint(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = v1->pEngine->Footprint;
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 191
// RVA: 0x98DCC0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetTotalFootprint(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rbp
  Scaleform::MemoryHeap *v4; // rdi
  signed __int64 v5; // rsi
  signed __int64 v6; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = 0i64;
  if ( !(v1->Info.Desc.Flags & 0x1000) )
    v3 = v1->pEngine->Footprint;
  v4 = v1->ChildHeaps.Root.pNext;
  v5 = (signed __int64)&v1->ChildHeaps;
  while ( 1 )
  {
    v6 = v5 ? v5 - 8 : 0i64;
    if ( v4 == (Scaleform::MemoryHeap *)v6 )
      break;
    v3 += v4->vfptr->GetTotalFootprint(v4);
    v4 = v4->pNext;
  }
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 209
// RVA: 0x98E9B0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetUsedSpace(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rdi

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = v1->pEngine->UsedSpace;
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 216
// RVA: 0x98DE20
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetTotalUsedSpace(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 v3; // rbp
  Scaleform::MemoryHeap *v4; // rdi
  signed __int64 v5; // rsi
  signed __int64 v6; // rax

  v1 = this;
  v2 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = 0i64;
  if ( !(v1->Info.Desc.Flags & 0x1000) )
    v3 = v1->pEngine->UsedSpace;
  v4 = v1->ChildHeaps.Root.pNext;
  v5 = (signed __int64)&v1->ChildHeaps;
  while ( 1 )
  {
    v6 = v5 ? v5 - 8 : 0i64;
    if ( v4 == (Scaleform::MemoryHeap *)v6 )
      break;
    v3 += v4->vfptr->GetTotalUsedSpace(v4);
    v4 = v4->pNext;
  }
  LeaveCriticalSection(v2);
  return v3;
}

// File Line: 234
// RVA: 0x9B15C0
void __fastcall Scaleform::MemoryHeapMH::SetLimitHandler(Scaleform::MemoryHeapMH *this, Scaleform::MemoryHeap::LimitHandler *handler)
{
  Scaleform::MemoryHeap::LimitHandler *v2; // rsi
  Scaleform::MemoryHeapMH *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = handler;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3->pEngine->pLimHandler = v2;
  LeaveCriticalSection(v4);
}

// File Line: 241
// RVA: 0x9B14A0
void __fastcall Scaleform::MemoryHeapMH::SetLimit(Scaleform::MemoryHeapMH *this, unsigned __int64 newLimit)
{
  unsigned __int64 v2; // rdi
  Scaleform::MemoryHeapMH *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::HeapMH::AllocEngineMH *v5; // rax

  v2 = newLimit;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( v2 < v3->Info.Desc.Limit )
  {
    v5 = v3->pEngine;
    if ( v2 < v5->Footprint )
      v2 = v5->Footprint;
  }
  v3->pEngine->Limit = v2;
  v3->Info.Desc.Limit = v2;
  LeaveCriticalSection(v4);
}

// File Line: 253
// RVA: 0x9548D0
void __fastcall Scaleform::MemoryHeapMH::AddRef(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx

  v1 = this;
  v2 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  ++v1->RefCount;
  LeaveCriticalSection(v2);
}

// File Line: 262
// RVA: 0x9A7A10
void __fastcall Scaleform::MemoryHeapMH::Release(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rsi
  Scaleform::MemoryHeap *v2; // r14
  _RTL_CRITICAL_SECTION *v3; // rbp
  bool v4; // zf
  __int64 v5; // rax
  Scaleform::HeapMH::RootMH *v6; // rbx
  unsigned __int64 v7; // rdi
  _RTL_CRITICAL_SECTION *v8; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = this->Info.pParent;
  if ( v2 )
  {
    lpCriticalSection = &v2->HeapLock.cs;
    EnterCriticalSection(&v2->HeapLock.cs);
    v3 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v4 = v1->RefCount-- == 1;
    v5 = v1->RefCount;
    if ( v4 )
    {
      v1->vfptr->dumpMemoryLeaks((Scaleform::MemoryHeap *)&v1->vfptr);
      v1->pPrev->pNext = v1->pNext;
      v1->pNext->pPrev = v1->pPrev;
      v6 = Scaleform::HeapMH::GlobalRootMH;
      v7 = v1->SelfSize;
      v1->vfptr->__vecDelDtor((Scaleform::MemoryHeap *)&v1->vfptr, 0);
      ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::MemoryHeapMH *, unsigned __int64, signed __int64, signed __int64))v6->pSysAlloc->vfptr[1].initHeapEngine)(
        v6->pSysAlloc,
        v1,
        v7,
        8i64,
        -2i64);
    }
    else
    {
      v2 = 0i64;
    }
    LeaveCriticalSection(v3);
    LeaveCriticalSection(lpCriticalSection);
    if ( v2 )
      v2->vfptr->Release(v2);
  }
  else
  {
    v8 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    --v1->RefCount;
    LeaveCriticalSection(v8);
  }
}

// File Line: 332
// RVA: 0x9DFA50
void __fastcall Scaleform::MemoryHeapMH::destroyItself(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeapMH *v1; // rsi
  Scaleform::MemoryHeap *i; // rcx
  signed __int64 v3; // rax
  Scaleform::MemoryHeap *v4; // rbx
  Scaleform::HeapMH::RootMH *v5; // rbx
  unsigned __int64 v6; // rdi

  v1 = this;
  for ( i = this->ChildHeaps.Root.pNext; ; i = v4 )
  {
    v3 = (signed __int64)(v1 == (Scaleform::MemoryHeapMH *)-136i64 ? 0i64 : &v1->Info.pName);
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    v4 = i->pNext;
    ((void (*)(void))i->vfptr->destroyItself)();
  }
  v5 = Scaleform::HeapMH::GlobalRootMH;
  v6 = v1->SelfSize;
  v1->vfptr->__vecDelDtor((Scaleform::MemoryHeap *)&v1->vfptr, 0);
  ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::MemoryHeapMH *, unsigned __int64, signed __int64))v5->pSysAlloc->vfptr[1].initHeapEngine)(
    v5->pSysAlloc,
    v1,
    v6,
    8i64);
}

// File Line: 504
// RVA: 0x9569B0
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::Alloc(Scaleform::MemoryHeapMH *this, unsigned __int64 size, Scaleform::AllocInfo *info)
{
  unsigned __int64 v3; // r14
  Scaleform::MemoryHeapMH *v4; // rdi
  Scaleform::Lock *v5; // rbx
  Scaleform::HeapMH::AllocEngineMH *v6; // rsi
  unsigned __int64 v7; // r8
  Scaleform::HeapMH::BinNodeMH *v8; // rdi
  unsigned __int64 v9; // r14
  _RTL_CRITICAL_SECTION *v10; // r15
  _RTL_CRITICAL_SECTION *v11; // rcx
  Scaleform::HeapMH::AllocEngineMH *v12; // rbx
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // r14
  _RTL_CRITICAL_SECTION *v15; // rsi
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+40h] [rbp-19h]
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+58h] [rbp-1h]
  bool limHandlerOK; // [rsp+C0h] [rbp+67h]
  Scaleform::LockSafe *v20; // [rsp+D8h] [rbp+7Fh]

  v3 = size;
  v4 = this;
  if ( this->UseLocks )
  {
    v5 = &this->HeapLock;
    v20 = (Scaleform::LockSafe *)&this->HeapLock;
    EnterCriticalSection(&this->HeapLock.cs);
    v6 = v4->pEngine;
    v7 = v6->MinAlignSize;
    if ( v7 <= 0x10 )
    {
      if ( v3 > 0x200 )
      {
        v10 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        limHandlerOK = 0;
        while ( 1 )
        {
          v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                 v6,
                                                 v3,
                                                 v6->MinAlignSize,
                                                 &limHandlerOK,
                                                 &infoa);
          if ( v8 )
            break;
          if ( !limHandlerOK )
          {
            LeaveCriticalSection(v10);
            goto LABEL_19;
          }
        }
        LeaveCriticalSection(v10);
      }
      else
      {
        v9 = (v3 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        limHandlerOK = 0;
        while ( 1 )
        {
          v8 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v6->Allocator, v9, &headers);
          if ( v8 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v6, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_19;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++v6->UseCount;
        v6->UsedSpace += v9;
      }
    }
    else
    {
      v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v6, v3, v7, &infoa, 0);
    }
LABEL_19:
    v11 = &v5->cs;
LABEL_37:
    LeaveCriticalSection(v11);
    return v8;
  }
  v12 = this->pEngine;
  v13 = v12->MinAlignSize;
  if ( v13 > 0x10 )
    return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v12, size, v13, &infoa, 0);
  if ( size > 0x200 )
  {
    v15 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
    v20 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    limHandlerOK = 0;
    while ( 1 )
    {
      v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                             v12,
                                             v3,
                                             v12->MinAlignSize,
                                             &limHandlerOK,
                                             &infoa);
      if ( v8 )
        break;
      if ( !limHandlerOK )
      {
        LeaveCriticalSection(v15);
        return v8;
      }
    }
    v11 = v15;
    goto LABEL_37;
  }
  v14 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  limHandlerOK = 0;
  while ( 1 )
  {
    v8 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v12->Allocator, v14, &headers);
    if ( v8 )
      break;
    Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v12, &limHandlerOK);
    if ( !limHandlerOK )
      return v8;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  ++v12->UseCount;
  v12->UsedSpace += v14;
  return v8;
}

// File Line: 516
// RVA: 0x956910
void *__fastcall Scaleform::MemoryHeapMH::Alloc(Scaleform::MemoryHeapMH *this, unsigned __int64 size, unsigned __int64 align, Scaleform::AllocInfo *info)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::MemoryHeapMH *v6; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  void *v8; // rdi
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+38h] [rbp-20h]

  v4 = align;
  v5 = size;
  v6 = this;
  if ( !this->UseLocks )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this->pEngine, size, align, &infoa, 0);
  v7 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v8 = Scaleform::HeapMH::AllocEngineMH::Alloc(v6->pEngine, v5, v4, &infoa, 0);
  LeaveCriticalSection(v7);
  return v8;
}

// File Line: 530
// RVA: 0x957180
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::AllocAutoHeap(Scaleform::MemoryHeapMH *this, const void *thisPtr, unsigned __int64 size, Scaleform::AllocInfo *info)
{
  unsigned __int64 v4; // rsi
  const void *v5; // rdi
  Scaleform::HeapMH::RootMH *v6; // r14
  Scaleform::HeapMH::PageMH *v7; // rax
  Scaleform::MemoryHeapMH *v8; // rdi
  signed __int64 v9; // rbx
  Scaleform::HeapMH::AllocEngineMH *v10; // r14
  unsigned __int64 v11; // r8
  Scaleform::HeapMH::BinNodeMH *v12; // rdi
  unsigned __int64 v13; // rsi
  _RTL_CRITICAL_SECTION *v14; // r15
  _RTL_CRITICAL_SECTION *v15; // rcx
  Scaleform::HeapMH::AllocEngineMH *v16; // rbx
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rsi
  _RTL_CRITICAL_SECTION *v19; // r14
  unsigned __int64 v20; // rdi
  signed __int64 v21; // rbx
  _RTL_CRITICAL_SECTION *v22; // r13
  Scaleform::HeapMH::AllocEngineMH *v23; // r14
  unsigned __int64 v24; // r15
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // rsi
  Scaleform::LockSafe *v27; // r12
  Scaleform::HeapMH::AllocEngineMH *v28; // rbx
  unsigned __int64 v29; // r14
  unsigned __int64 v30; // rsi
  unsigned __int64 v31; // rsi
  bool limHandlerOK; // [rsp+8h] [rbp-39h]
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+18h] [rbp-29h]
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+30h] [rbp-11h]
  Scaleform::LockSafe *v36; // [rsp+68h] [rbp+27h]
  __int64 v37; // [rsp+70h] [rbp+2Fh]

  v37 = -2i64;
  v4 = size;
  v5 = thisPtr;
  v6 = Scaleform::HeapMH::GlobalRootMH;
  v7 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)thisPtr);
  if ( !v7 )
  {
    EnterCriticalSection(&v6->RootLock.mLock.cs);
    v20 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            (unsigned __int64)v5)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(&v6->RootLock.mLock.cs);
    if ( *(_BYTE *)(v20 + 192) )
    {
      v21 = v20 + 152;
      EnterCriticalSection((LPCRITICAL_SECTION)(v20 + 152));
      v22 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      v36 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v23 = *(Scaleform::HeapMH::AllocEngineMH **)(v20 + 200);
      v24 = v23->MinAlignSize;
      limHandlerOK = 0;
      if ( v24 <= 0x10 )
      {
        if ( v4 > 0x200 )
        {
          while ( 1 )
          {
            infoa.Node = (Scaleform::HeapMH::NodeMH *)&infoa;
            v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                    v23,
                                                    v4,
                                                    v23->MinAlignSize,
                                                    &limHandlerOK,
                                                    &infoa);
            if ( v12 )
              goto LABEL_68;
            if ( !limHandlerOK )
            {
LABEL_67:
              v12 = 0i64;
              goto LABEL_68;
            }
          }
        }
        v25 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v23->Allocator, v25, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v23, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_67;
        }
      }
      else
      {
        if ( v4 > 0x200 )
        {
          if ( v24 < 8 )
            v24 = 8i64;
          if ( v4 < v24 )
            v4 = v24;
          v26 = (v4 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
          while ( 1 )
          {
            v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                    v23,
                                                    v26,
                                                    v24,
                                                    &limHandlerOK,
                                                    &infoa);
            if ( v12 )
              goto LABEL_68;
            if ( !limHandlerOK )
              goto LABEL_67;
          }
        }
        if ( v24 < 0x10 )
          v24 = 16i64;
        v25 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v23->Allocator, v25, v24, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v23, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_67;
        }
      }
      if ( headers.Header1 )
        ++headers.Header1->UseCount;
      if ( headers.Header2 )
        ++headers.Header2->UseCount;
      ++v23->UseCount;
      v23->UsedSpace += v25;
LABEL_68:
      LeaveCriticalSection(v22);
      v15 = (_RTL_CRITICAL_SECTION *)v21;
LABEL_99:
      LeaveCriticalSection(v15);
      return v12;
    }
    v27 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v28 = *(Scaleform::HeapMH::AllocEngineMH **)(v20 + 200);
    v29 = v28->MinAlignSize;
    limHandlerOK = 0;
    if ( v29 <= 0x10 )
    {
      if ( v4 > 0x200 )
      {
        while ( 1 )
        {
          infoa.Node = (Scaleform::HeapMH::NodeMH *)&infoa;
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v28,
                                                  v4,
                                                  v28->MinAlignSize,
                                                  &limHandlerOK,
                                                  &infoa);
          if ( v12 )
            goto LABEL_98;
          if ( !limHandlerOK )
          {
LABEL_97:
            v12 = 0i64;
            goto LABEL_98;
          }
        }
      }
      v30 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
      while ( 1 )
      {
        v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v28->Allocator, v30, &headers);
        if ( v12 )
          break;
        Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v28, &limHandlerOK);
        if ( !limHandlerOK )
          goto LABEL_97;
      }
    }
    else
    {
      if ( v4 > 0x200 )
      {
        if ( v29 < 8 )
          v29 = 8i64;
        if ( v4 < v29 )
          v4 = v29;
        v31 = (v4 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v28,
                                                  v31,
                                                  v29,
                                                  &limHandlerOK,
                                                  &infoa);
          if ( v12 )
            goto LABEL_98;
          if ( !limHandlerOK )
            goto LABEL_97;
        }
      }
      if ( v29 < 0x10 )
        v29 = 16i64;
      v30 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
      while ( 1 )
      {
        v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v28->Allocator, v30, v29, &headers);
        if ( v12 )
          break;
        Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v28, &limHandlerOK);
        if ( !limHandlerOK )
          goto LABEL_97;
      }
    }
    if ( headers.Header1 )
      ++headers.Header1->UseCount;
    if ( headers.Header2 )
      ++headers.Header2->UseCount;
    ++v28->UseCount;
    v28->UsedSpace += v30;
LABEL_98:
    v15 = &v27->mLock.cs;
    goto LABEL_99;
  }
  v8 = v7->pHeap;
  if ( v8->UseLocks )
  {
    v9 = (signed __int64)&v8->HeapLock;
    v36 = (Scaleform::LockSafe *)&v8->HeapLock;
    EnterCriticalSection(&v8->HeapLock.cs);
    v10 = v8->pEngine;
    v11 = v10->MinAlignSize;
    if ( v11 <= 0x10 )
    {
      if ( v4 > 0x200 )
      {
        v14 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        limHandlerOK = 0;
        while ( 1 )
        {
          infoa.Node = (Scaleform::HeapMH::NodeMH *)&infoa;
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v10,
                                                  v4,
                                                  v10->MinAlignSize,
                                                  &limHandlerOK,
                                                  &infoa);
          if ( v12 )
            break;
          if ( !limHandlerOK )
          {
            LeaveCriticalSection(v14);
            goto LABEL_20;
          }
        }
        LeaveCriticalSection(v14);
      }
      else
      {
        v13 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        limHandlerOK = 0;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v10->Allocator, v13, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v10, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_20;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++v10->UseCount;
        v10->UsedSpace += v13;
      }
    }
    else
    {
      v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v10, v4, v11, &infoa, 0);
    }
LABEL_20:
    v15 = (_RTL_CRITICAL_SECTION *)v9;
    goto LABEL_99;
  }
  v16 = v8->pEngine;
  v17 = v16->MinAlignSize;
  if ( v17 > 0x10 )
    return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v16, v4, v17, &infoa, 0);
  if ( v4 > 0x200 )
  {
    v19 = &v6->RootLock.mLock.cs;
    EnterCriticalSection(v19);
    limHandlerOK = 0;
    while ( 1 )
    {
      infoa.Node = (Scaleform::HeapMH::NodeMH *)&infoa;
      v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                              v16,
                                              v4,
                                              v16->MinAlignSize,
                                              &limHandlerOK,
                                              &infoa);
      if ( v12 )
        break;
      if ( !limHandlerOK )
      {
        LeaveCriticalSection(v19);
        return v12;
      }
    }
    v15 = v19;
    goto LABEL_99;
  }
  v18 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  limHandlerOK = 0;
  while ( 1 )
  {
    v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v16->Allocator, v18, &headers);
    if ( v12 )
      break;
    Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(v16, &limHandlerOK);
    if ( !limHandlerOK )
      return v12;
  }
  if ( headers.Header1 )
    ++headers.Header1->UseCount;
  if ( headers.Header2 )
    ++headers.Header2->UseCount;
  ++v16->UseCount;
  v16->UsedSpace += v18;
  return v12;
}

// File Line: 598
// RVA: 0x956E50
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::AllocAutoHeap(Scaleform::MemoryHeapMH *this, const void *thisPtr, unsigned __int64 size, unsigned __int64 align)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rdi
  const void *v6; // r14
  Scaleform::HeapMH::RootMH *v7; // rbx
  Scaleform::HeapMH::PageMH *v8; // rax
  Scaleform::MemoryHeapMH *v9; // r14
  Scaleform::HeapMH::BinNodeMH *v10; // rdi
  _RTL_CRITICAL_SECTION *v11; // rcx
  _RTL_CRITICAL_SECTION *v13; // rbx
  unsigned __int64 v14; // r14
  signed __int64 v15; // rbx
  _RTL_CRITICAL_SECTION *v16; // r13
  Scaleform::HeapMH::AllocEngineMH *v17; // r14
  unsigned __int64 v18; // r15
  unsigned __int64 v19; // r15
  Scaleform::LockSafe *v20; // r12
  Scaleform::HeapMH::AllocEngineMH *v21; // rbx
  unsigned __int64 v22; // r14
  unsigned __int64 v23; // r14
  bool limHandlerOK; // [rsp+8h] [rbp-41h]
  Scaleform::HeapMH::PageInfoMH v25; // [rsp+20h] [rbp-29h]
  __int64 v26; // [rsp+38h] [rbp-11h]
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+40h] [rbp-9h]

  v26 = -2i64;
  v4 = align;
  v5 = size;
  v6 = thisPtr;
  v7 = Scaleform::HeapMH::GlobalRootMH;
  v8 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)thisPtr);
  if ( v8 )
  {
    v9 = v8->pHeap;
    if ( !v9->UseLocks )
    {
      LOBYTE(v25.Page) = 0;
      return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v9->pEngine, v5, v4, &v25, 0);
    }
    EnterCriticalSection(&v9->HeapLock.cs);
    LOBYTE(v25.Page) = 0;
    v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v9->pEngine, v5, v4, &v25, 0);
    v11 = &v9->HeapLock.cs;
  }
  else
  {
    v13 = &v7->RootLock.mLock.cs;
    EnterCriticalSection(v13);
    v14 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            (unsigned __int64)v6)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(v13);
    if ( *(_BYTE *)(v14 + 192) )
    {
      v15 = v14 + 152;
      EnterCriticalSection((LPCRITICAL_SECTION)(v14 + 152));
      v16 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v17 = *(Scaleform::HeapMH::AllocEngineMH **)(v14 + 200);
      limHandlerOK = 0;
      if ( v5 > 0x200 )
      {
        if ( v4 < 8 )
          v4 = 8i64;
        if ( v5 < v4 )
          v5 = v4;
        v19 = (v5 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v17,
                                                  v19,
                                                  v4,
                                                  &limHandlerOK,
                                                  &v25);
          if ( v10 )
            break;
          if ( !limHandlerOK )
          {
LABEL_25:
            v10 = 0i64;
            break;
          }
        }
      }
      else
      {
        if ( v4 < 0x10 )
          v4 = 16i64;
        v18 = (v5 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v17->Allocator, v18, v4, &headers);
          if ( v10 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v17, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_25;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++v17->UseCount;
        v17->UsedSpace += v18;
      }
      LeaveCriticalSection(v16);
      v11 = (_RTL_CRITICAL_SECTION *)v15;
    }
    else
    {
      v20 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v21 = *(Scaleform::HeapMH::AllocEngineMH **)(v14 + 200);
      limHandlerOK = 0;
      if ( v5 > 0x200 )
      {
        if ( v4 < 8 )
          v4 = 8i64;
        if ( v5 < v4 )
          v5 = v4;
        v23 = (v5 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v21,
                                                  v23,
                                                  v4,
                                                  &limHandlerOK,
                                                  &v25);
          if ( v10 )
            break;
          if ( !limHandlerOK )
          {
LABEL_46:
            v10 = 0i64;
            break;
          }
        }
      }
      else
      {
        if ( v4 < 0x10 )
          v4 = 16i64;
        v22 = (v5 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v21->Allocator, v22, v4, &headers);
          if ( v10 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v21, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_46;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++v21->UseCount;
        v21->UsedSpace += v22;
      }
      v11 = &v20->mLock.cs;
    }
  }
  LeaveCriticalSection(v11);
  return v10;
}

// File Line: 701
// RVA: 0x97DD40
void __fastcall Scaleform::MemoryHeapMH::Free(Scaleform::MemoryHeapMH *this, void *ptr)
{
  void *v2; // rbp
  Scaleform::HeapMH::RootMH *v3; // rbx
  Scaleform::HeapMH::PageMH *v4; // rax
  Scaleform::HeapMH::PageMH *v5; // rdi
  unsigned __int64 v6; // rsi
  _RTL_CRITICAL_SECTION *v7; // rbx
  Scaleform::HeapMH::NodeMH *v8; // r14
  _RTL_CRITICAL_SECTION *v9; // rdi

  if ( ptr )
  {
    v2 = ptr;
    v3 = Scaleform::HeapMH::GlobalRootMH;
    v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)ptr);
    v5 = v4;
    if ( v4 )
    {
      v6 = (unsigned __int64)v4->pHeap;
      if ( !*(_BYTE *)(v6 + 192) )
      {
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(v6 + 200), v4, v2, 0);
        goto LABEL_10;
      }
      v7 = (_RTL_CRITICAL_SECTION *)(v6 + 152);
      EnterCriticalSection((LPCRITICAL_SECTION)(v6 + 152));
      Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(v6 + 200), v5, v2, 0);
    }
    else
    {
      EnterCriticalSection(&v3->RootLock.mLock.cs);
      v8 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
             &Scaleform::HeapMH::GlobalRootMH->HeapTree,
             (unsigned __int64)v2);
      v6 = v8->pHeap & 0xFFFFFFFFFFFFFFFCui64;
      LeaveCriticalSection(&v3->RootLock.mLock.cs);
      if ( *(_BYTE *)(v6 + 192) )
      {
        v7 = (_RTL_CRITICAL_SECTION *)(v6 + 152);
        EnterCriticalSection((LPCRITICAL_SECTION)(v6 + 152));
        v9 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(v6 + 200), v8, v2, 1);
        LeaveCriticalSection(v9);
      }
      else
      {
        v7 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(v6 + 200), v8, v2, 1);
      }
    }
    LeaveCriticalSection(v7);
LABEL_10:
    if ( v2 == *(void **)(v6 + 48) )
      (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v6 + 64i64))(v6);
  }
}

// File Line: 752
// RVA: 0x9EEFD0
char *__fastcall Scaleform::MemoryHeapMH::reallocMem(Scaleform::MemoryHeapMH *this, Scaleform::HeapMH::PageMH *page, void *oldPtr, unsigned __int64 newSize, bool globalLocked)
{
  unsigned __int64 v5; // rsi
  void *v6; // r14
  Scaleform::HeapMH::PageMH *v7; // r15
  Scaleform::MemoryHeapMH *v8; // rbp
  Scaleform::HeapMH::AllocEngineMH *v9; // rdi
  char *v10; // r10
  unsigned __int64 v11; // rbx
  _RTL_CRITICAL_SECTION *v13; // rdi
  void *v14; // rbx
  Scaleform::HeapMH::PageInfoMH newInfo; // [rsp+38h] [rbp-70h]
  __int64 v16; // [rsp+50h] [rbp-58h]
  Scaleform::HeapMH::PageMH *v17; // [rsp+80h] [rbp-28h]
  Scaleform::LockSafe *oldSize; // [rsp+B0h] [rbp+8h]

  v5 = newSize;
  v6 = oldPtr;
  v7 = page;
  v8 = this;
  v9 = this->pEngine;
  v10 = 0i64;
  if ( newSize < 0x800 )
  {
    v11 = (newSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v10 = Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(
            &v9->Allocator,
            page,
            oldPtr,
            v11,
            (unsigned __int64 *)&oldSize,
            (Scaleform::HeapMH::MagicHeadersInfo *)&v16);
    if ( v10 )
    {
      newInfo.UsableSize = v11;
      newInfo.Page = v17;
      newInfo.Node = 0i64;
      v9->UsedSpace += v11 - (_QWORD)oldSize;
    }
  }
  if ( v10 )
    return v10;
  if ( globalLocked )
    return (char *)Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(v8->pEngine, v7, v6, v5, &newInfo, 1);
  v13 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  oldSize = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v14 = Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(v8->pEngine, v7, v6, v5, &newInfo, 1);
  LeaveCriticalSection(v13);
  return (char *)v14;
}

// File Line: 861
// RVA: 0x9A6350
void *__fastcall Scaleform::MemoryHeapMH::Realloc(Scaleform::MemoryHeapMH *this, void *oldPtr, unsigned __int64 newSize)
{
  unsigned __int64 v3; // r15
  void *v4; // rbp
  Scaleform::HeapMH::RootMH *v5; // rbx
  Scaleform::HeapMH::PageMH *v6; // rax
  Scaleform::HeapMH::PageMH *v7; // rsi
  Scaleform::MemoryHeapMH *v8; // rdi
  _RTL_CRITICAL_SECTION *v9; // rbx
  void *v10; // rdi
  void *result; // rax
  Scaleform::HeapMH::NodeMH *v12; // r13
  unsigned __int64 v13; // r14
  _RTL_CRITICAL_SECTION *v14; // rsi
  void *v15; // rdi
  _RTL_CRITICAL_SECTION *v16; // rdi
  void *v17; // rbx
  Scaleform::HeapMH::PageInfoMH newInfo; // [rsp+40h] [rbp-48h]

  v3 = newSize;
  v4 = oldPtr;
  v5 = Scaleform::HeapMH::GlobalRootMH;
  v6 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)oldPtr);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6->pHeap;
    if ( v8->UseLocks )
    {
      v9 = &v8->HeapLock.cs;
      EnterCriticalSection(&v8->HeapLock.cs);
      v10 = Scaleform::MemoryHeapMH::reallocMem(v8, v7, v4, v3, 0);
      LeaveCriticalSection(v9);
      result = v10;
    }
    else
    {
      result = Scaleform::MemoryHeapMH::reallocMem(v8, v6, v4, v3, 0);
    }
  }
  else
  {
    EnterCriticalSection(&v5->RootLock.mLock.cs);
    v12 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            (unsigned __int64)v4);
    v13 = v12->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(&v5->RootLock.mLock.cs);
    if ( *(_BYTE *)(v13 + 192) )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)(v13 + 152));
      v14 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v15 = Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
              *(Scaleform::HeapMH::AllocEngineMH **)(v13 + 200),
              v12,
              v4,
              (v3 + 7) & 0xFFFFFFFFFFFFFFF8ui64,
              &newInfo);
      LeaveCriticalSection(v14);
      LeaveCriticalSection((LPCRITICAL_SECTION)(v13 + 152));
      result = v15;
    }
    else
    {
      v16 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v17 = Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
              *(Scaleform::HeapMH::AllocEngineMH **)(v13 + 200),
              v12,
              v4,
              (v3 + 7) & 0xFFFFFFFFFFFFFFF8ui64,
              &newInfo);
      LeaveCriticalSection(v16);
      result = v17;
    }
  }
  return result;
}

// File Line: 911
// RVA: 0x97FE80
Scaleform::MemoryHeapMH *__fastcall Scaleform::MemoryHeapMH::GetAllocHeap(Scaleform::MemoryHeapMH *this, const void *thisPtr)
{
  const void *v2; // rbx
  Scaleform::HeapMH::RootMH *v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rax
  unsigned __int64 v6; // rbx

  v2 = thisPtr;
  v3 = Scaleform::HeapMH::GlobalRootMH;
  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)thisPtr);
  if ( v4 )
    return v4->pHeap;
  EnterCriticalSection(&v3->RootLock.mLock.cs);
  v6 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
         &Scaleform::HeapMH::GlobalRootMH->HeapTree,
         (unsigned __int64)v2)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
  LeaveCriticalSection(&v3->RootLock.mLock.cs);
  return (Scaleform::MemoryHeapMH *)v6;
}

// File Line: 922
// RVA: 0x98E700
char *__fastcall Scaleform::MemoryHeapMH::GetUsableSize(Scaleform::MemoryHeapMH *this, const void *ptr)
{
  _BYTE *v2; // rsi
  Scaleform::HeapMH::RootMH *v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rax
  char *v5; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rcx
  bool v9; // cf
  bool v10; // zf
  const unsigned int *v11; // rcx
  char *result; // rax
  char *v13; // rbx

  v2 = ptr;
  v3 = Scaleform::HeapMH::GlobalRootMH;
  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)ptr);
  if ( v4 )
  {
    v5 = v4->Start;
    v6 = (unsigned __int64)(v5 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v7 = (unsigned __int64)(v5 + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v8 = ((unsigned __int64)(v5 + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v7;
    v9 = v7 - v6 < v8;
    v10 = v7 - v6 == v8;
    v11 = (const unsigned int *)(v7 - 80);
    if ( v9 || v10 )
      v11 = (const unsigned int *)(v7 + 16);
    result = (char *)(16 * Scaleform::Heap::BitSet2::GetBlockSize(v11, (signed __int64)&v2[-v6] >> 4));
  }
  else
  {
    EnterCriticalSection(&v3->RootLock.mLock.cs);
    v13 = (char *)((char *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                             &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                             (unsigned __int64)v2)
                 - v2);
    LeaveCriticalSection(&v3->RootLock.mLock.cs);
    result = v13;
  }
  return result;
}

// File Line: 939
// RVA: 0x957EF0
__int64 __fastcall Scaleform::MemoryHeapMH::AllocSysDirect(Scaleform::MemoryHeapMH *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rbx
  _RTL_CRITICAL_SECTION *v3; // rdi
  __int64 v4; // rbx

  v2 = size;
  v3 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v4 = ((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, signed __int64))Scaleform::HeapMH::GlobalRootMH->pSysAlloc->vfptr[1].__vecDelDtor)(
         Scaleform::HeapMH::GlobalRootMH->pSysAlloc,
         v2,
         8i64);
  LeaveCriticalSection(v3);
  return v4;
}

// File Line: 945
// RVA: 0x97E5B0
void __fastcall Scaleform::MemoryHeapMH::FreeSysDirect(Scaleform::MemoryHeapMH *this, void *ptr, unsigned __int64 size)
{
  unsigned __int64 v3; // rbx
  void *v4; // rdi
  _RTL_CRITICAL_SECTION *v5; // rsi

  v3 = size;
  v4 = ptr;
  v5 = &Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  ((void (__fastcall *)(Scaleform::SysAlloc *, void *, unsigned __int64, signed __int64, signed __int64))Scaleform::HeapMH::GlobalRootMH->pSysAlloc->vfptr[1].initHeapEngine)(
    Scaleform::HeapMH::GlobalRootMH->pSysAlloc,
    v4,
    v3,
    8i64,
    -2i64);
  LeaveCriticalSection(v5);
}

// File Line: 952
// RVA: 0x98BAE0
char __fastcall Scaleform::MemoryHeapMH::GetStats(Scaleform::MemoryHeapMH *this, Scaleform::StatBag *bag)
{
  Scaleform::MemoryHeapMH *v2; // rsi
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::MemoryHeap *v4; // rdi
  signed __int64 v5; // rsi
  signed __int64 v6; // rax

  v2 = this;
  v3 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v4 = v2->ChildHeaps.Root.pNext;
  v5 = (signed __int64)&v2->ChildHeaps;
  while ( 1 )
  {
    v6 = v5 ? v5 - 8 : 0i64;
    if ( v4 == (Scaleform::MemoryHeap *)v6 )
      break;
    if ( !(v4->Info.Desc.Flags & 0x1000) )
      v4->vfptr->GetTotalFootprint(v4);
    v4 = v4->pNext;
  }
  LeaveCriticalSection(v3);
  return 1;
}

// File Line: 1019
// RVA: 0x9E7920
void __fastcall Scaleform::MemoryHeapMH::getUserDebugStats(Scaleform::MemoryHeapMH *this, Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::MemoryHeap::RootStats *v2; // rbp
  Scaleform::MemoryHeapMH *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::MemoryHeap *v5; // rdi
  signed __int64 v6; // rsi
  signed __int64 v7; // rax

  v2 = stats;
  v3 = this;
  v4 = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( v3->Info.Desc.Flags & 0x1000 )
  {
    v2->UserDebugFootprint += v3->pEngine->Footprint;
    v2->UserDebugUsedSpace += v3->pEngine->UsedSpace;
  }
  v5 = v3->ChildHeaps.Root.pNext;
  v6 = (signed __int64)&v3->ChildHeaps;
  while ( 1 )
  {
    v7 = v6 ? v6 - 8 : 0i64;
    if ( v5 == (Scaleform::MemoryHeap *)v7 )
      break;
    v5->vfptr->getUserDebugStats(v5, v2);
    v5 = v5->pNext;
  }
  LeaveCriticalSection(v4);
}

// File Line: 1036
// RVA: 0x98B190
void __fastcall Scaleform::MemoryHeapMH::GetRootStats(Scaleform::MemoryHeapMH *this, Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::MemoryHeap::RootStats *v2; // rdi
  Scaleform::MemoryHeapMH *v3; // rbx
  __int64 v4; // rax
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rax

  v2 = stats;
  v3 = this;
  stats->UserDebugFootprint = 0i64;
  stats->UserDebugUsedSpace = 0i64;
  ((void (*)(void))this->vfptr->getUserDebugStats)();
  v2->DebugInfoFootprint = 0i64;
  v2->DebugInfoUsedSpace = 0i64;
  v2->SysMemFootprint = v2->UserDebugFootprint
                      + v2->DebugInfoFootprint
                      + v3->vfptr->GetTotalFootprint((Scaleform::MemoryHeap *)&v3->vfptr);
  v4 = v3->vfptr->GetTotalUsedSpace((Scaleform::MemoryHeap *)&v3->vfptr);
  v2->PageMapFootprint = 0i64;
  v5 = v2->DebugInfoFootprint + v4;
  v2->PageMapUsedSpace = 0i64;
  v2->BookkeepingFootprint = 0i64;
  v6 = v2->UserDebugFootprint + v5;
  v2->BookkeepingUsedSpace = 0i64;
  v2->SysMemUsedSpace = v6;
}

// File Line: 1086
// RVA: 0x9E8410
bool __fastcall Scaleform::SysAlloc::initHeapEngine(Scaleform::SysAlloc *this, const void *heapDesc)
{
  Scaleform::MemoryHeap::HeapDesc *v2; // rbx

  v2 = (Scaleform::MemoryHeap::HeapDesc *)heapDesc;
  if ( !Scaleform::HeapMH::GlobalRootMH )
    Scaleform::HeapMH::RootMH::RootMH(&HeapRootMemMH, this);
  return Scaleform::MemoryHeap::CreateRootHeapMH(v2) != 0i64;
}

// File Line: 1094
// RVA: 0x9F2470
__int64 __fastcall Scaleform::SysAlloc::shutdownHeapEngine(Scaleform::SysAlloc *this)
{
  unsigned __int8 v1; // di
  Scaleform::HeapMH::RootMH *v2; // rbx

  v1 = Scaleform::MemoryHeap::ReleaseRootHeapMH();
  v2 = Scaleform::HeapMH::GlobalRootMH;
  if ( Scaleform::HeapMH::GlobalRootMH )
  {
    Scaleform::HeapMH::RootMH::FreeTables(Scaleform::HeapMH::GlobalRootMH);
    Scaleform::HeapMH::GlobalRootMH = 0i64;
    DeleteCriticalSection(&v2->RootLock.mLock.cs);
    Scaleform::HeapMH::GlobalRootMH = 0i64;
  }
  return v1;
}

