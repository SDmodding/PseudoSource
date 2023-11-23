// File Line: 77
// RVA: 0x969340
Scaleform::MemoryHeap *__fastcall Scaleform::MemoryHeap::CreateRootHeapMH(Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  Scaleform::MemoryHeap::HeapDesc desca; // [rsp+30h] [rbp-48h] BYREF

  if ( !Scaleform::HeapMH::GlobalRootMH )
    return 0i64;
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    return 0i64;
  }
  *(_OWORD *)&desca.Flags = *(_OWORD *)&desc->Flags;
  *(_OWORD *)&desca.Granularity = *(_OWORD *)&desc->Granularity;
  *(_OWORD *)&desca.Threshold = *(_OWORD *)&desc->Threshold;
  desca.Arena = desc->Arena;
  desca.HeapId = 1i64;
  Scaleform::Memory::pGlobalHeap = Scaleform::HeapMH::RootMH::CreateHeap(
                                     Scaleform::HeapMH::GlobalRootMH,
                                     "Global",
                                     0i64,
                                     &desca);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return Scaleform::Memory::pGlobalHeap;
}

// File Line: 114
// RVA: 0x9A82B0
char __fastcall Scaleform::MemoryHeap::ReleaseRootHeapMH()
{
  Scaleform::LockSafe *p_RootLock; // rbx
  bool v2; // di

  if ( !Scaleform::HeapMH::GlobalRootMH )
    return 1;
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  if ( Scaleform::Memory::pGlobalHeap )
  {
    v2 = !Scaleform::Memory::pGlobalHeap->vfptr->dumpMemoryLeaks(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap->vfptr->destroyItself(Scaleform::Memory::pGlobalHeap);
    Scaleform::Memory::pGlobalHeap = 0i64;
  }
  else
  {
    v2 = 1;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v2;
}

// File Line: 155
// RVA: 0x997B90
char __fastcall Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
        hkGeometryUtils::IVertices *this,
        int vertexA,
        int vertexB)
{
  return 1;
}

// File Line: 163
// RVA: 0x967410
Scaleform::MemoryHeapMH *__fastcall Scaleform::MemoryHeapMH::CreateHeap(
        Scaleform::MemoryHeapMH *this,
        const char *name,
        Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // rbp
  Scaleform::MemoryHeapMH *Heap; // rdi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  Heap = Scaleform::HeapMH::RootMH::CreateHeap(Scaleform::HeapMH::GlobalRootMH, name, this, desc);
  if ( Heap )
    ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  if ( Heap )
  {
    EnterCriticalSection(&this->HeapLock.cs);
    Heap->pPrev = this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev;
    Heap->pNext = (Scaleform::MemoryHeap *)&this->Info.pName;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev->Scaleform::MemoryHeap::pNext = Heap;
    this->ChildHeaps.Root.Scaleform::MemoryHeap::pPrev = Heap;
    LeaveCriticalSection(&this->HeapLock.cs);
  }
  return Heap;
}

// File Line: 184
// RVA: 0x9848B0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetFootprint(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 Footprint; // rdi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = this->pEngine->Footprint;
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}

// File Line: 191
// RVA: 0x98DCC0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetTotalFootprint(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 Footprint; // rbp
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v6; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = 0i64;
  if ( (this->Info.Desc.Flags & 0x1000) == 0 )
    Footprint = this->pEngine->Footprint;
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    Footprint += pNext->vfptr->GetTotalFootprint(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return Footprint;
}

// File Line: 209
// RVA: 0x98E9B0
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetUsedSpace(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 UsedSpace; // rdi

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  UsedSpace = this->pEngine->UsedSpace;
  LeaveCriticalSection(&p_HeapLock->cs);
  return UsedSpace;
}

// File Line: 216
// RVA: 0x98DE20
unsigned __int64 __fastcall Scaleform::MemoryHeapMH::GetTotalUsedSpace(Scaleform::MemoryHeapMH *this)
{
  Scaleform::Lock *p_HeapLock; // rbx
  unsigned __int64 UsedSpace; // rbp
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v6; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  UsedSpace = 0i64;
  if ( (this->Info.Desc.Flags & 0x1000) == 0 )
    UsedSpace = this->pEngine->UsedSpace;
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    UsedSpace += pNext->vfptr->GetTotalUsedSpace(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return UsedSpace;
}

// File Line: 234
// RVA: 0x9B15C0
void __fastcall Scaleform::MemoryHeapMH::SetLimitHandler(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::LimitHandler *handler)
{
  Scaleform::Lock *p_HeapLock; // rbx

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  this->pEngine->pLimHandler = handler;
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 241
// RVA: 0x9B14A0
void __fastcall Scaleform::MemoryHeapMH::SetLimit(Scaleform::MemoryHeapMH *this, unsigned __int64 newLimit)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::HeapMH::AllocEngineMH *pEngine; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( newLimit < this->Info.Desc.Limit )
  {
    pEngine = this->pEngine;
    if ( newLimit < pEngine->Footprint )
      newLimit = pEngine->Footprint;
  }
  this->pEngine->Limit = newLimit;
  this->Info.Desc.Limit = newLimit;
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 253
// RVA: 0x9548D0
void __fastcall Scaleform::MemoryHeapMH::AddRef(Scaleform::MemoryHeapMH *this)
{
  Scaleform::LockSafe *p_RootLock; // rbx

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  ++this->RefCount;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 262
// RVA: 0x9A7A10
void __fastcall Scaleform::MemoryHeapMH::Release(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeap *pParent; // r14
  Scaleform::LockSafe *p_RootLock; // rbp
  Scaleform::HeapMH::RootMH *v5; // rbx
  unsigned __int64 SelfSize; // rdi
  Scaleform::LockSafe *v7; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+68h] [rbp+10h]

  pParent = this->Info.pParent;
  if ( pParent )
  {
    lpCriticalSection = &pParent->HeapLock.cs;
    EnterCriticalSection(&pParent->HeapLock.cs);
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    if ( this->RefCount-- == 1 )
    {
      this->vfptr->dumpMemoryLeaks(this);
      this->pPrev->Scaleform::MemoryHeap::pNext = this->pNext;
      this->pNext->Scaleform::MemoryHeap::pPrev = this->pPrev;
      v5 = Scaleform::HeapMH::GlobalRootMH;
      SelfSize = this->SelfSize;
      this->vfptr->__vecDelDtor(this, 0i64);
      ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::MemoryHeapMH *, unsigned __int64, __int64, __int64))v5->pSysAlloc->vfptr[1].initHeapEngine)(
        v5->pSysAlloc,
        this,
        SelfSize,
        8i64,
        -2i64);
    }
    else
    {
      pParent = 0i64;
    }
    LeaveCriticalSection(&p_RootLock->mLock.cs);
    LeaveCriticalSection(lpCriticalSection);
    if ( pParent )
      pParent->vfptr->Release(pParent);
  }
  else
  {
    v7 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    --this->RefCount;
    LeaveCriticalSection(&v7->mLock.cs);
  }
}

// File Line: 332
// RVA: 0x9DFA50
void __fastcall Scaleform::MemoryHeapMH::destroyItself(Scaleform::MemoryHeapMH *this)
{
  Scaleform::MemoryHeap *i; // rcx
  char **v3; // rax
  Scaleform::MemoryHeap *pNext; // rbx
  Scaleform::HeapMH::RootMH *v5; // rbx
  unsigned __int64 SelfSize; // rdi

  for ( i = this->ChildHeaps.Root.pNext; ; i = pNext )
  {
    v3 = this == (Scaleform::MemoryHeapMH *)-136i64 ? 0i64 : &this->Info.pName;
    if ( i == (Scaleform::MemoryHeap *)v3 )
      break;
    pNext = i->pNext;
    i->vfptr->destroyItself(i);
  }
  v5 = Scaleform::HeapMH::GlobalRootMH;
  SelfSize = this->SelfSize;
  this->vfptr->__vecDelDtor(this, 0i64);
  ((void (__fastcall *)(Scaleform::SysAlloc *, Scaleform::MemoryHeapMH *, unsigned __int64, __int64))v5->pSysAlloc->vfptr[1].initHeapEngine)(
    v5->pSysAlloc,
    this,
    SelfSize,
    8i64);
}

// File Line: 504
// RVA: 0x9569B0
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::Alloc(
        Scaleform::MemoryHeapMH *this,
        unsigned __int64 size,
        Scaleform::AllocInfo *info)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::HeapMH::AllocEngineMH *pEngine; // rsi
  unsigned __int64 MinAlignSize; // r8
  Scaleform::HeapMH::BinNodeMH *v8; // rdi
  unsigned __int64 v9; // r14
  Scaleform::LockSafe *p_RootLock; // r15
  _RTL_CRITICAL_SECTION *p_cs; // rcx
  Scaleform::HeapMH::AllocEngineMH *v12; // rbx
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // r14
  Scaleform::LockSafe *v15; // rsi
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+40h] [rbp-19h] BYREF
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+58h] [rbp-1h] BYREF
  bool limHandlerOK; // [rsp+C0h] [rbp+67h] BYREF
  Scaleform::LockSafe *v20; // [rsp+D8h] [rbp+7Fh]

  if ( this->UseLocks )
  {
    p_HeapLock = &this->HeapLock;
    v20 = (Scaleform::LockSafe *)&this->HeapLock;
    EnterCriticalSection(&this->HeapLock.cs);
    pEngine = this->pEngine;
    MinAlignSize = pEngine->MinAlignSize;
    if ( MinAlignSize <= 0x10 )
    {
      if ( size > 0x200 )
      {
        p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        limHandlerOK = 0;
        do
          v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                 pEngine,
                                                 size,
                                                 pEngine->MinAlignSize,
                                                 &limHandlerOK,
                                                 &infoa);
        while ( !v8 && limHandlerOK );
        LeaveCriticalSection(&p_RootLock->mLock.cs);
      }
      else
      {
        v9 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        limHandlerOK = 0;
        while ( 1 )
        {
          v8 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&pEngine->Allocator, v9, &headers);
          if ( v8 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(pEngine, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_18;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++pEngine->UseCount;
        pEngine->UsedSpace += v9;
      }
    }
    else
    {
      v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(
                                             pEngine,
                                             size,
                                             MinAlignSize,
                                             &infoa,
                                             0);
    }
LABEL_18:
    p_cs = &p_HeapLock->cs;
LABEL_36:
    LeaveCriticalSection(p_cs);
    return v8;
  }
  v12 = this->pEngine;
  v13 = v12->MinAlignSize;
  if ( v13 > 0x10 )
    return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v12, size, v13, &infoa, 0);
  if ( size > 0x200 )
  {
    v15 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    v20 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    limHandlerOK = 0;
    while ( 1 )
    {
      v8 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                             v12,
                                             size,
                                             v12->MinAlignSize,
                                             &limHandlerOK,
                                             &infoa);
      if ( v8 )
        break;
      if ( !limHandlerOK )
      {
        LeaveCriticalSection(&v15->mLock.cs);
        return v8;
      }
    }
    p_cs = &v15->mLock.cs;
    goto LABEL_36;
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
void *__fastcall Scaleform::MemoryHeapMH::Alloc(
        Scaleform::MemoryHeapMH *this,
        unsigned __int64 size,
        unsigned __int64 align,
        Scaleform::AllocInfo *info)
{
  Scaleform::Lock *p_HeapLock; // rbx
  void *v8; // rdi
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+38h] [rbp-20h] BYREF

  if ( !this->UseLocks )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this->pEngine, size, align, &infoa, 0);
  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  v8 = Scaleform::HeapMH::AllocEngineMH::Alloc(this->pEngine, size, align, &infoa, 0);
  LeaveCriticalSection(&p_HeapLock->cs);
  return v8;
}

// File Line: 530
// RVA: 0x957180
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::AllocAutoHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned __int64 thisPtr,
        unsigned __int64 size,
        Scaleform::AllocInfo *info)
{
  Scaleform::HeapMH::RootMH *v6; // r14
  Scaleform::HeapMH::PageMH *v7; // rax
  Scaleform::MemoryHeapMH *pHeap; // rdi
  _RTL_CRITICAL_SECTION *v9; // rbx
  Scaleform::HeapMH::AllocEngineMH *pEngine; // r14
  unsigned __int64 v11; // r8
  Scaleform::HeapMH::BinNodeMH *v12; // rdi
  unsigned __int64 v13; // rsi
  Scaleform::LockSafe *v14; // r15
  _RTL_CRITICAL_SECTION *p_cs; // rcx
  Scaleform::HeapMH::AllocEngineMH *v16; // rbx
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rsi
  _RTL_CRITICAL_SECTION *v19; // r14
  unsigned __int64 v20; // rdi
  _RTL_CRITICAL_SECTION *v21; // rbx
  Scaleform::LockSafe *p_RootLock; // r13
  Scaleform::HeapMH::AllocEngineMH *v23; // r14
  unsigned __int64 MinAlignSize; // r15
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // rsi
  Scaleform::LockSafe *v27; // r12
  Scaleform::HeapMH::AllocEngineMH *v28; // rbx
  unsigned __int64 v29; // r14
  unsigned __int64 v30; // rsi
  unsigned __int64 v31; // rsi
  bool limHandlerOK; // [rsp+8h] [rbp-39h] BYREF
  Scaleform::HeapMH::PageInfoMH infoa; // [rsp+18h] [rbp-29h] BYREF
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+30h] [rbp-11h] BYREF
  Scaleform::LockSafe *p_HeapLock; // [rsp+68h] [rbp+27h]
  __int64 v37; // [rsp+70h] [rbp+2Fh]

  v37 = -2i64;
  v6 = Scaleform::HeapMH::GlobalRootMH;
  v7 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( !v7 )
  {
    EnterCriticalSection(&v6->RootLock.mLock.cs);
    v20 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            thisPtr)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(&v6->RootLock.mLock.cs);
    if ( *(_BYTE *)(v20 + 192) )
    {
      v21 = (_RTL_CRITICAL_SECTION *)(v20 + 152);
      EnterCriticalSection((LPCRITICAL_SECTION)(v20 + 152));
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      p_HeapLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v23 = *(Scaleform::HeapMH::AllocEngineMH **)(v20 + 200);
      MinAlignSize = v23->MinAlignSize;
      limHandlerOK = 0;
      if ( MinAlignSize <= 0x10 )
      {
        if ( size > 0x200 )
        {
          while ( 1 )
          {
            v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                    v23,
                                                    size,
                                                    v23->MinAlignSize,
                                                    &limHandlerOK,
                                                    &infoa);
            if ( v12 )
              goto LABEL_63;
            if ( !limHandlerOK )
            {
LABEL_62:
              v12 = 0i64;
              goto LABEL_63;
            }
          }
        }
        v25 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v23->Allocator, v25, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v23, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_62;
        }
      }
      else
      {
        if ( size > 0x200 )
        {
          if ( size < MinAlignSize )
            size = MinAlignSize;
          v26 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
          while ( 1 )
          {
            v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                    v23,
                                                    v26,
                                                    MinAlignSize,
                                                    &limHandlerOK,
                                                    &infoa);
            if ( v12 )
              goto LABEL_63;
            if ( !limHandlerOK )
              goto LABEL_62;
          }
        }
        v25 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v23->Allocator, v25, MinAlignSize, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v23, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_62;
        }
      }
      if ( headers.Header1 )
        ++headers.Header1->UseCount;
      if ( headers.Header2 )
        ++headers.Header2->UseCount;
      ++v23->UseCount;
      v23->UsedSpace += v25;
LABEL_63:
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      p_cs = v21;
LABEL_90:
      LeaveCriticalSection(p_cs);
      return v12;
    }
    v27 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    v28 = *(Scaleform::HeapMH::AllocEngineMH **)(v20 + 200);
    v29 = v28->MinAlignSize;
    limHandlerOK = 0;
    if ( v29 <= 0x10 )
    {
      if ( size > 0x200 )
      {
        while ( 1 )
        {
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v28,
                                                  size,
                                                  v28->MinAlignSize,
                                                  &limHandlerOK,
                                                  &infoa);
          if ( v12 )
            goto LABEL_89;
          if ( !limHandlerOK )
          {
LABEL_88:
            v12 = 0i64;
            goto LABEL_89;
          }
        }
      }
      v30 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
      while ( 1 )
      {
        v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v28->Allocator, v30, &headers);
        if ( v12 )
          break;
        Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v28, &limHandlerOK);
        if ( !limHandlerOK )
          goto LABEL_88;
      }
    }
    else
    {
      if ( size > 0x200 )
      {
        if ( size < v29 )
          size = v29;
        v31 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v28,
                                                  v31,
                                                  v29,
                                                  &limHandlerOK,
                                                  &infoa);
          if ( v12 )
            goto LABEL_89;
          if ( !limHandlerOK )
            goto LABEL_88;
        }
      }
      v30 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
      while ( 1 )
      {
        v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v28->Allocator, v30, v29, &headers);
        if ( v12 )
          break;
        Scaleform::HeapMH::AllocEngineMH::allocPageLocked(v28, &limHandlerOK);
        if ( !limHandlerOK )
          goto LABEL_88;
      }
    }
    if ( headers.Header1 )
      ++headers.Header1->UseCount;
    if ( headers.Header2 )
      ++headers.Header2->UseCount;
    ++v28->UseCount;
    v28->UsedSpace += v30;
LABEL_89:
    p_cs = &v27->mLock.cs;
    goto LABEL_90;
  }
  pHeap = v7->pHeap;
  if ( pHeap->UseLocks )
  {
    v9 = &pHeap->HeapLock.cs;
    p_HeapLock = (Scaleform::LockSafe *)&pHeap->HeapLock;
    EnterCriticalSection(&pHeap->HeapLock.cs);
    pEngine = pHeap->pEngine;
    v11 = pEngine->MinAlignSize;
    if ( v11 <= 0x10 )
    {
      if ( size > 0x200 )
      {
        v14 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        limHandlerOK = 0;
        do
          v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  pEngine,
                                                  size,
                                                  pEngine->MinAlignSize,
                                                  &limHandlerOK,
                                                  &infoa);
        while ( !v12 && limHandlerOK );
        LeaveCriticalSection(&v14->mLock.cs);
      }
      else
      {
        v13 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        limHandlerOK = 0;
        while ( 1 )
        {
          v12 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&pEngine->Allocator, v13, &headers);
          if ( v12 )
            break;
          Scaleform::HeapMH::AllocEngineMH::allocPageUnlocked(pEngine, &limHandlerOK);
          if ( !limHandlerOK )
            goto LABEL_19;
        }
        if ( headers.Header1 )
          ++headers.Header1->UseCount;
        if ( headers.Header2 )
          ++headers.Header2->UseCount;
        ++pEngine->UseCount;
        pEngine->UsedSpace += v13;
      }
    }
    else
    {
      v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(pEngine, size, v11, &infoa, 0);
    }
LABEL_19:
    p_cs = v9;
    goto LABEL_90;
  }
  v16 = pHeap->pEngine;
  v17 = v16->MinAlignSize;
  if ( v17 > 0x10 )
    return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(v16, size, v17, &infoa, 0);
  if ( size > 0x200 )
  {
    v19 = &v6->RootLock.mLock.cs;
    EnterCriticalSection(v19);
    limHandlerOK = 0;
    while ( 1 )
    {
      v12 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                              v16,
                                              size,
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
    p_cs = v19;
    goto LABEL_90;
  }
  v18 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
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
Scaleform::HeapMH::BinNodeMH *__fastcall Scaleform::MemoryHeapMH::AllocAutoHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned __int64 thisPtr,
        unsigned __int64 size,
        unsigned __int64 align)
{
  Scaleform::HeapMH::RootMH *v7; // rbx
  Scaleform::HeapMH::PageMH *v8; // rax
  Scaleform::MemoryHeapMH *pHeap; // r14
  Scaleform::HeapMH::BinNodeMH *v10; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rcx
  _RTL_CRITICAL_SECTION *v13; // rbx
  unsigned __int64 v14; // r14
  _RTL_CRITICAL_SECTION *v15; // rbx
  Scaleform::LockSafe *p_RootLock; // r13
  Scaleform::HeapMH::AllocEngineMH *v17; // r14
  unsigned __int64 v18; // r15
  unsigned __int64 v19; // r15
  Scaleform::LockSafe *v20; // r12
  Scaleform::HeapMH::AllocEngineMH *v21; // rbx
  unsigned __int64 v22; // r14
  unsigned __int64 v23; // r14
  bool limHandlerOK; // [rsp+8h] [rbp-41h] BYREF
  Scaleform::HeapMH::PageInfoMH v25; // [rsp+20h] [rbp-29h] BYREF
  __int64 v26; // [rsp+38h] [rbp-11h]
  Scaleform::HeapMH::MagicHeadersInfo headers; // [rsp+40h] [rbp-9h] BYREF

  v26 = -2i64;
  v7 = Scaleform::HeapMH::GlobalRootMH;
  v8 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( v8 )
  {
    pHeap = v8->pHeap;
    if ( !pHeap->UseLocks )
      return (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(
                                               pHeap->pEngine,
                                               size,
                                               align,
                                               &v25,
                                               0);
    EnterCriticalSection(&pHeap->HeapLock.cs);
    v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::Alloc(pHeap->pEngine, size, align, &v25, 0);
    p_cs = &pHeap->HeapLock.cs;
  }
  else
  {
    v13 = &v7->RootLock.mLock.cs;
    EnterCriticalSection(v13);
    v14 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
            &Scaleform::HeapMH::GlobalRootMH->HeapTree,
            thisPtr)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(v13);
    if ( *(_BYTE *)(v14 + 192) )
    {
      v15 = (_RTL_CRITICAL_SECTION *)(v14 + 152);
      EnterCriticalSection((LPCRITICAL_SECTION)(v14 + 152));
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v17 = *(Scaleform::HeapMH::AllocEngineMH **)(v14 + 200);
      limHandlerOK = 0;
      if ( size > 0x200 )
      {
        if ( align < 8 )
          align = 8i64;
        if ( size < align )
          size = align;
        v19 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v17,
                                                  v19,
                                                  align,
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
        if ( align < 0x10 )
          align = 16i64;
        v18 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v17->Allocator, v18, align, &headers);
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
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      p_cs = v15;
    }
    else
    {
      v20 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v21 = *(Scaleform::HeapMH::AllocEngineMH **)(v14 + 200);
      limHandlerOK = 0;
      if ( size > 0x200 )
      {
        if ( align < 8 )
          align = 8i64;
        if ( size < align )
          size = align;
        v23 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
        while ( 1 )
        {
          v10 = (Scaleform::HeapMH::BinNodeMH *)Scaleform::HeapMH::AllocEngineMH::allocDirect(
                                                  v21,
                                                  v23,
                                                  align,
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
        if ( align < 0x10 )
          align = 16i64;
        v22 = (size + 15) & 0xFFFFFFFFFFFFFFF0ui64;
        while ( 1 )
        {
          v10 = Scaleform::HeapMH::AllocBitSet2MH::Alloc(&v21->Allocator, v22, align, &headers);
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
      p_cs = &v20->mLock.cs;
    }
  }
  LeaveCriticalSection(p_cs);
  return v10;
}

// File Line: 701
// RVA: 0x97DD40
void __fastcall Scaleform::MemoryHeapMH::Free(Scaleform::MemoryHeapMH *this, void *ptr)
{
  Scaleform::HeapMH::RootMH *v3; // rbx
  Scaleform::HeapMH::PageMH *v4; // rax
  Scaleform::HeapMH::PageMH *v5; // rdi
  unsigned __int64 pHeap; // rsi
  Scaleform::LockSafe *v7; // rbx
  Scaleform::HeapPT::TreeSeg *GrEq; // r14
  Scaleform::LockSafe *p_RootLock; // rdi

  if ( ptr )
  {
    v3 = Scaleform::HeapMH::GlobalRootMH;
    v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)ptr);
    v5 = v4;
    if ( v4 )
    {
      pHeap = (unsigned __int64)v4->pHeap;
      if ( !*(_BYTE *)(pHeap + 192) )
      {
        Scaleform::HeapMH::AllocEngineMH::Free(
          *(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 200),
          v4,
          (unsigned __int64)ptr,
          0);
        goto LABEL_10;
      }
      v7 = (Scaleform::LockSafe *)(pHeap + 152);
      EnterCriticalSection((LPCRITICAL_SECTION)(pHeap + 152));
      Scaleform::HeapMH::AllocEngineMH::Free(
        *(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 200),
        v5,
        (unsigned __int64)ptr,
        0);
    }
    else
    {
      EnterCriticalSection(&v3->RootLock.mLock.cs);
      GrEq = (Scaleform::HeapPT::TreeSeg *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                                             &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                                             (unsigned __int64)ptr);
      pHeap = (unsigned __int64)GrEq->Headers & 0xFFFFFFFFFFFFFFFCui64;
      LeaveCriticalSection(&v3->RootLock.mLock.cs);
      if ( *(_BYTE *)(pHeap + 192) )
      {
        v7 = (Scaleform::LockSafe *)(pHeap + 152);
        EnterCriticalSection((LPCRITICAL_SECTION)(pHeap + 152));
        p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 200), GrEq, ptr, 1);
        LeaveCriticalSection(&p_RootLock->mLock.cs);
      }
      else
      {
        v7 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
        EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
        Scaleform::HeapMH::AllocEngineMH::Free(*(Scaleform::HeapMH::AllocEngineMH **)(pHeap + 200), GrEq, ptr, 1);
      }
    }
    LeaveCriticalSection(&v7->mLock.cs);
LABEL_10:
    if ( ptr == *(void **)(pHeap + 48) )
      (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)pHeap + 64i64))(pHeap);
  }
}

// File Line: 752
// RVA: 0x9EEFD0
char *__fastcall Scaleform::MemoryHeapMH::reallocMem(
        Scaleform::MemoryHeapMH *this,
        Scaleform::HeapMH::PageMH *page,
        char *oldPtr,
        unsigned __int64 newSize,
        bool globalLocked)
{
  Scaleform::HeapMH::AllocEngineMH *pEngine; // rdi
  char *v10; // r10
  unsigned __int64 v11; // rbx
  Scaleform::LockSafe *p_RootLock; // rdi
  void *v14; // rbx
  Scaleform::HeapMH::PageInfoMH newInfo; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::HeapMH::MagicHeadersInfo v16; // [rsp+50h] [rbp-58h] BYREF
  Scaleform::LockSafe *oldSize; // [rsp+B0h] [rbp+8h] BYREF

  pEngine = this->pEngine;
  v10 = 0i64;
  if ( newSize < 0x800 )
  {
    v11 = (newSize + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v10 = Scaleform::HeapMH::AllocBitSet2MH::ReallocInPlace(
            &pEngine->Allocator,
            page,
            oldPtr,
            v11,
            (unsigned __int64 *)&oldSize,
            &v16);
    if ( v10 )
    {
      newInfo.UsableSize = v11;
      newInfo.Page = v16.Page;
      newInfo.Node = 0i64;
      pEngine->UsedSpace += v11 - (_QWORD)oldSize;
    }
  }
  if ( v10 )
    return v10;
  if ( globalLocked )
    return (char *)Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(this->pEngine, page, oldPtr, newSize, &newInfo, 1);
  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  oldSize = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v14 = Scaleform::HeapMH::AllocEngineMH::ReallocGeneral(this->pEngine, page, oldPtr, newSize, &newInfo, 1);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return (char *)v14;
}

// File Line: 861
// RVA: 0x9A6350
void *__fastcall Scaleform::MemoryHeapMH::Realloc(
        Scaleform::MemoryHeapMH *this,
        void *oldPtr,
        unsigned __int64 newSize)
{
  Scaleform::HeapMH::RootMH *v5; // rbx
  Scaleform::HeapMH::PageMH *v6; // rax
  Scaleform::HeapMH::PageMH *v7; // rsi
  Scaleform::MemoryHeapMH *pHeap; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  void *v10; // rdi
  Scaleform::HeapMH::NodeMH *GrEq; // r13
  unsigned __int64 v13; // r14
  Scaleform::LockSafe *p_RootLock; // rsi
  void *v15; // rdi
  Scaleform::LockSafe *v16; // rdi
  void *v17; // rbx
  Scaleform::HeapMH::PageInfoMH newInfo; // [rsp+40h] [rbp-48h] BYREF

  v5 = Scaleform::HeapMH::GlobalRootMH;
  v6 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)oldPtr);
  v7 = v6;
  if ( v6 )
  {
    pHeap = v6->pHeap;
    if ( pHeap->UseLocks )
    {
      p_cs = &pHeap->HeapLock.cs;
      EnterCriticalSection(&pHeap->HeapLock.cs);
      v10 = Scaleform::MemoryHeapMH::reallocMem(pHeap, v7, oldPtr, newSize, 0);
      LeaveCriticalSection(p_cs);
      return v10;
    }
    else
    {
      return Scaleform::MemoryHeapMH::reallocMem(pHeap, v6, oldPtr, newSize, 0);
    }
  }
  else
  {
    EnterCriticalSection(&v5->RootLock.mLock.cs);
    GrEq = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
             &Scaleform::HeapMH::GlobalRootMH->HeapTree,
             (unsigned __int64)oldPtr);
    v13 = GrEq->pHeap & 0xFFFFFFFFFFFFFFFCui64;
    LeaveCriticalSection(&v5->RootLock.mLock.cs);
    if ( *(_BYTE *)(v13 + 192) )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)(v13 + 152));
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v15 = Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
              *(Scaleform::HeapMH::AllocEngineMH **)(v13 + 200),
              GrEq,
              oldPtr,
              (newSize + 7) & 0xFFFFFFFFFFFFFFF8ui64,
              &newInfo);
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      LeaveCriticalSection((LPCRITICAL_SECTION)(v13 + 152));
      return v15;
    }
    else
    {
      v16 = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      v17 = Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
              *(Scaleform::HeapMH::AllocEngineMH **)(v13 + 200),
              GrEq,
              oldPtr,
              (newSize + 7) & 0xFFFFFFFFFFFFFFF8ui64,
              &newInfo);
      LeaveCriticalSection(&v16->mLock.cs);
      return v17;
    }
  }
}

// File Line: 911
// RVA: 0x97FE80
Scaleform::MemoryHeapMH *__fastcall Scaleform::MemoryHeapMH::GetAllocHeap(
        Scaleform::MemoryHeapMH *this,
        unsigned __int64 thisPtr)
{
  Scaleform::HeapMH::RootMH *v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rax
  unsigned __int64 v6; // rbx

  v3 = Scaleform::HeapMH::GlobalRootMH;
  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, thisPtr);
  if ( v4 )
    return v4->pHeap;
  EnterCriticalSection(&v3->RootLock.mLock.cs);
  v6 = Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
         &Scaleform::HeapMH::GlobalRootMH->HeapTree,
         thisPtr)->pHeap & 0xFFFFFFFFFFFFFFFCui64;
  LeaveCriticalSection(&v3->RootLock.mLock.cs);
  return (Scaleform::MemoryHeapMH *)v6;
}

// File Line: 922
// RVA: 0x98E700
signed __int64 __fastcall Scaleform::MemoryHeapMH::GetUsableSize(Scaleform::MemoryHeapMH *this, _BYTE *ptr)
{
  Scaleform::HeapMH::RootMH *v3; // rdi
  Scaleform::HeapMH::PageMH *v4; // rax
  char *Start; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rdx
  bool v8; // cc
  const unsigned int *v9; // rcx
  signed __int64 v11; // rbx

  v3 = Scaleform::HeapMH::GlobalRootMH;
  v4 = Scaleform::HeapMH::RootMH::ResolveAddress(Scaleform::HeapMH::GlobalRootMH, (unsigned __int64)ptr);
  if ( v4 )
  {
    Start = v4->Start;
    v6 = (unsigned __int64)(Start + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v7 = (unsigned __int64)(Start + 4095) & 0xFFFFFFFFFFFFF000ui64;
    v8 = v7 - v6 <= ((unsigned __int64)(Start + 4096) & 0xFFFFFFFFFFFFFFF0ui64) - v7;
    v9 = (const unsigned int *)(v7 - 80);
    if ( v8 )
      v9 = (const unsigned int *)(v7 + 16);
    return 16 * Scaleform::Heap::BitSet2::GetBlockSize(v9, (__int64)&ptr[-v6] >> 4);
  }
  else
  {
    EnterCriticalSection(&v3->RootLock.mLock.cs);
    v11 = (char *)Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::FindGrEq(
                    &Scaleform::HeapMH::GlobalRootMH->HeapTree,
                    (unsigned __int64)ptr)
        - ptr;
    LeaveCriticalSection(&v3->RootLock.mLock.cs);
    return v11;
  }
}

// File Line: 939
// RVA: 0x957EF0
__int64 __fastcall Scaleform::MemoryHeapMH::AllocSysDirect(Scaleform::MemoryHeapMH *this, unsigned __int64 size)
{
  Scaleform::LockSafe *p_RootLock; // rdi
  __int64 v4; // rbx

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  v4 = ((__int64 (__fastcall *)(Scaleform::SysAlloc *, unsigned __int64, __int64))Scaleform::HeapMH::GlobalRootMH->pSysAlloc->vfptr[1].__vecDelDtor)(
         Scaleform::HeapMH::GlobalRootMH->pSysAlloc,
         size,
         8i64);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v4;
}

// File Line: 945
// RVA: 0x97E5B0
void __fastcall Scaleform::MemoryHeapMH::FreeSysDirect(Scaleform::MemoryHeapMH *this, void *ptr, unsigned __int64 size)
{
  Scaleform::LockSafe *p_RootLock; // rsi

  p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
  EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
  ((void (__fastcall *)(Scaleform::SysAlloc *, void *, unsigned __int64, __int64, __int64))Scaleform::HeapMH::GlobalRootMH->pSysAlloc->vfptr[1].initHeapEngine)(
    Scaleform::HeapMH::GlobalRootMH->pSysAlloc,
    ptr,
    size,
    8i64,
    -2i64);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 952
// RVA: 0x98BAE0
char __fastcall Scaleform::MemoryHeapMH::GetStats(Scaleform::MemoryHeapMH *this, Scaleform::StatBag *bag)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v6; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v6 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v6 )
      break;
    if ( (pNext->Info.Desc.Flags & 0x1000) == 0 )
      pNext->vfptr->GetTotalFootprint(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
  return 1;
}

// File Line: 1019
// RVA: 0x9E7920
void __fastcall Scaleform::MemoryHeapMH::getUserDebugStats(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::Lock *p_HeapLock; // rbx
  Scaleform::MemoryHeap *pNext; // rdi
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rsi
  __int64 v7; // rax

  p_HeapLock = &this->HeapLock;
  EnterCriticalSection(&this->HeapLock.cs);
  if ( (this->Info.Desc.Flags & 0x1000) != 0 )
  {
    stats->UserDebugFootprint += this->pEngine->Footprint;
    stats->UserDebugUsedSpace += this->pEngine->UsedSpace;
  }
  pNext = this->ChildHeaps.Root.pNext;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v7 = p_ChildHeaps ? (__int64)&p_ChildHeaps[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::MemoryHeap *)v7 )
      break;
    pNext->vfptr->getUserDebugStats(pNext, stats);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_HeapLock->cs);
}

// File Line: 1036
// RVA: 0x98B190
void __fastcall Scaleform::MemoryHeapMH::GetRootStats(
        Scaleform::MemoryHeapMH *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rax

  stats->UserDebugFootprint = 0i64;
  stats->UserDebugUsedSpace = 0i64;
  ((void (__fastcall *)(Scaleform::MemoryHeapMH *))this->vfptr->getUserDebugStats)(this);
  stats->DebugInfoFootprint = 0i64;
  stats->DebugInfoUsedSpace = 0i64;
  stats->SysMemFootprint = stats->UserDebugFootprint + stats->DebugInfoFootprint + this->vfptr->GetTotalFootprint(this);
  v4 = this->vfptr->GetTotalUsedSpace(this);
  stats->PageMapFootprint = 0i64;
  v5 = stats->DebugInfoFootprint + v4;
  stats->PageMapUsedSpace = 0i64;
  stats->BookkeepingFootprint = 0i64;
  v6 = stats->UserDebugFootprint + v5;
  stats->BookkeepingUsedSpace = 0i64;
  stats->SysMemUsedSpace = v6;
}

// File Line: 1086
// RVA: 0x9E8410
bool __fastcall Scaleform::SysAlloc::initHeapEngine(
        Scaleform::SysAlloc *this,
        Scaleform::MemoryHeap::HeapDesc *heapDesc)
{
  if ( !Scaleform::HeapMH::GlobalRootMH )
    Scaleform::HeapMH::RootMH::RootMH(&HeapRootMemMH, this);
  return Scaleform::MemoryHeap::CreateRootHeapMH(heapDesc) != 0i64;
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

