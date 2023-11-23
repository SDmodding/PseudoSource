// File Line: 52
// RVA: 0x9927F0
void __fastcall Scaleform::HeapPT::SysAllocGranulator::Init(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  unsigned __int64 *PrivateData; // rcx
  Scaleform::HeapPT::Granulator *v4; // rax
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // [rsp+38h] [rbp-40h] BYREF
  unsigned __int64 v8; // [rsp+40h] [rbp-38h]
  __int64 v9; // [rsp+48h] [rbp-30h]
  unsigned __int64 v10; // [rsp+50h] [rbp-28h]
  unsigned __int64 v11; // [rsp+58h] [rbp-20h]
  __int64 v12; // [rsp+60h] [rbp-18h]

  PrivateData = this->PrivateData;
  if ( PrivateData )
    Scaleform::HeapPT::Granulator::Granulator(
      (Scaleform::HeapPT::Granulator *)PrivateData,
      sysAlloc,
      0x1000ui64,
      0x1000ui64,
      0x2000ui64);
  else
    v4 = 0i64;
  this->pGranulator = v4;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  v12 = 0i64;
  v4->pSysAlloc->vfptr[1].__vecDelDtor(v4->pSysAlloc, (unsigned int)&v7);
  this->SysDirectThreshold = v10;
  this->MaxHeapGranularity = v11;
  v5 = v7;
  this->MinAlign = v7;
  v6 = v8;
  this->MaxAlign = v8;
  if ( !v5 )
    this->MinAlign = 1i64;
  if ( !v6 )
    this->MaxAlign = 0x8000000000000000ui64;
}

// File Line: 77
// RVA: 0x987530
void __fastcall Scaleform::HeapPT::SysAllocGranulator::GetInfo(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 MaxHeapGranularity; // rax

  i->MinAlign = 0i64;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->SysDirectThreshold = this->SysDirectThreshold;
  MaxHeapGranularity = this->MaxHeapGranularity;
  i->HasRealloc = 1;
  i->MaxHeapGranularity = MaxHeapGranularity;
}

// File Line: 89
// RVA: 0x956D40
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::SysAllocGranulator::Alloc(
        Scaleform::HeapPT::SysAllocGranulator *this,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::Alloc(this->pGranulator, size, alignment);
}

// File Line: 104
// RVA: 0x9A7080
bool __fastcall Scaleform::HeapPT::SysAllocGranulator::ReallocInPlace(
        Scaleform::HeapPT::SysAllocGranulator *this,
        char *oldPtr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::ReallocInPlace(this->pGranulator, oldPtr, oldSize, newSize, alignment);
}

// File Line: 111
// RVA: 0x97DFE0
bool __fastcall Scaleform::HeapPT::SysAllocGranulator::Free(
        Scaleform::HeapPT::SysAllocGranulator *this,
        char *ptr,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::Free(this->pGranulator, ptr, size, alignment);
}

// File Line: 127
// RVA: 0x957F70
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::AllocSysDirect(
        Scaleform::HeapPT::SysAllocGranulator *this,
        unsigned __int64 size,
        unsigned __int64 alignment,
        unsigned __int64 *actualSize,
        unsigned __int64 *actualAlign)
{
  unsigned __int64 v5; // r10
  Scaleform::HeapPT::Granulator *pGranulator; // rax

  v5 = alignment;
  if ( alignment < 0x1000 )
    v5 = 4096i64;
  if ( alignment < this->MinAlign )
    alignment = this->MinAlign;
  if ( alignment > this->MaxAlign )
    alignment = this->MaxAlign;
  if ( alignment < v5 )
    size += v5;
  *actualSize = size;
  *actualAlign = alignment;
  pGranulator = this->pGranulator;
  this->SysDirectFootprint += size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *))pGranulator->pSysAlloc->vfptr[1].initHeapEngine)(pGranulator->pSysAlloc);
}

// File Line: 150
// RVA: 0x97E630
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::FreeSysDirect(
        Scaleform::HeapPT::SysAllocGranulator *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  Scaleform::HeapPT::Granulator *pGranulator; // rax

  pGranulator = this->pGranulator;
  this->SysDirectFootprint -= size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64))pGranulator->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           pGranulator->pSysAlloc,
           ptr,
           size,
           alignment);
}

// File Line: 158
// RVA: 0x9C1DA0
void __fastcall Scaleform::HeapPT::SysAllocGranulator::VisitMem(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::HeapPT::AllocLite *p_Allocator; // rcx
  Scaleform::HeapPT::DualTNode *Root; // rdx
  Scaleform::Heap::HeapSegment v5; // [rsp+30h] [rbp-48h] BYREF

  p_Allocator = &this->pGranulator->Allocator;
  *(_QWORD *)&v5.SegType = 16i64;
  Root = p_Allocator->SizeTree.Tree.Root;
  v5.SelfSize = 0i64;
  memset(&v5.UseCount, 0, 32);
  Scaleform::HeapPT::AllocLite::visitTree(p_Allocator, Root, &v5, visitor, Cat_SysAllocFree);
}

// File Line: 166
// RVA: 0x9C2030
void __fastcall Scaleform::HeapPT::SysAllocGranulator::VisitSegments(
        Scaleform::HeapPT::SysAllocGranulator *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned __int64 catSeg,
        unsigned __int64 catUnused)
{
  Scaleform::HeapPT::Granulator *pGranulator; // rbx
  unsigned int v5; // esi

  pGranulator = this->pGranulator;
  v5 = catUnused;
  Scaleform::HeapPT::Granulator::visitSegments(pGranulator, pGranulator->UsedSeg.Root, visitor, catSeg);
  Scaleform::HeapPT::AllocLite::visitUnusedInTree(
    &pGranulator->Allocator,
    pGranulator->Allocator.SizeTree.Tree.Root,
    visitor,
    v5);
}

// File Line: 171
// RVA: 0x984970
unsigned __int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetFootprint(
        Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint + this->pGranulator->Footprint;
}

// File Line: 172
// RVA: 0x98EA80
unsigned __int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetUsedSpace(
        Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint
       + this->pGranulator->Footprint
       - (this->pGranulator->Allocator.FreeBlocks << this->pGranulator->Allocator.MinShift);
}

// File Line: 175
// RVA: 0x9800A0
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetBase(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *))this->pGranulator->pSysAlloc->vfptr[3].__vecDelDtor)(this->pGranulator->pSysAlloc);
}

// File Line: 176
// RVA: 0x98B730
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetSize(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *))this->pGranulator->pSysAlloc->vfptr[3].initHeapEngine)(this->pGranulator->pSysAlloc);
}

// File Line: 188
// RVA: 0x945770
void __fastcall Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocGranulator *p_Allocator; // rdi
  __int64 v5[2]; // [rsp+28h] [rbp-40h] BYREF
  unsigned __int64 v6; // [rsp+38h] [rbp-30h]
  __int64 v7; // [rsp+40h] [rbp-28h]
  __int64 v8; // [rsp+48h] [rbp-20h]
  __int64 v9; // [rsp+50h] [rbp-18h]

  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::HeapPT::SysAllocWrapper::`vftable;
  p_Allocator = &this->Allocator;
  this->Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::HeapPT::SysAllocGranulator::`vftable;
  this->Allocator.pGranulator = 0i64;
  this->Allocator.SysDirectThreshold = 0i64;
  this->Allocator.MinAlign = 0i64;
  this->Allocator.MaxAlign = 0i64;
  this->Allocator.SysDirectFootprint = 0i64;
  this->pSrcAlloc = sysAlloc;
  this->pSysAlloc = sysAlloc;
  this->SysGranularity = 4096i64;
  this->MinAlign = 1i64;
  this->UsedSpace = 0i64;
  v5[0] = 0i64;
  v5[1] = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  sysAlloc->vfptr[1].__vecDelDtor(sysAlloc, (unsigned int)v5);
  if ( v6 )
  {
    Scaleform::HeapPT::SysAllocGranulator::Init(&this->Allocator, sysAlloc);
    this->pSysAlloc = p_Allocator;
    this->SysGranularity = v6;
  }
  if ( this->MinAlign < v5[0] )
    this->MinAlign = v5[0];
}

// File Line: 204
// RVA: 0x9875E0
void __fastcall Scaleform::HeapPT::SysAllocWrapper::GetInfo(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = 0i64;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->SysDirectThreshold = 0i64;
  i->MaxHeapGranularity = 0i64;
  *(_QWORD *)&i->HasRealloc = 0i64;
  ((void (__fastcall *)(Scaleform::SysAllocPaged *))this->pSysAlloc->vfptr[1].__vecDelDtor)(this->pSysAlloc);
}

// File Line: 210
// RVA: 0x956E30
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::Alloc(
        Scaleform::HeapPT::SysAllocWrapper *this,
        unsigned __int64 size,
        unsigned __int64 align)
{
  this->UsedSpace += size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
           this->pSysAlloc,
           size,
           align);
}

// File Line: 216
// RVA: 0x97E1F0
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::Free(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 align)
{
  this->UsedSpace -= size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           this->pSysAlloc,
           ptr,
           size,
           align);
}

// File Line: 222
// RVA: 0x9A7380
void *__fastcall Scaleform::HeapPT::SysAllocWrapper::ReallocInPlace(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *oldPtr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 align)
{
  this->UsedSpace += newSize - oldSize;
  return this->pSysAlloc->vfptr[2].__vecDelDtor(this->pSysAlloc, oldPtr);
}

// File Line: 229
// RVA: 0x957FC0
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::AllocSysDirect(
        Scaleform::HeapPT::SysAllocWrapper *this,
        unsigned __int64 size,
        unsigned __int64 alignment,
        unsigned __int64 *actualSize,
        unsigned __int64 *actualAlign)
{
  this->UsedSpace += size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64, unsigned __int64 *))this->pSysAlloc->vfptr[2].initHeapEngine)(
           this->pSysAlloc,
           size,
           alignment,
           actualSize);
}

// File Line: 235
// RVA: 0x97E650
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::FreeSysDirect(
        Scaleform::HeapPT::SysAllocWrapper *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  this->UsedSpace -= size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[2].shutdownHeapEngine)(
           this->pSysAlloc,
           ptr,
           size,
           alignment);
}

// File Line: 241
// RVA: 0x9C1E40
void __fastcall Scaleform::HeapPT::SysAllocWrapper::VisitMem(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::Heap::MemVisitor *visitor)
{
  this->pSysAlloc->vfptr[4].initHeapEngine(this->pSysAlloc, visitor);
}

// File Line: 247
// RVA: 0x9C2090
void __fastcall Scaleform::HeapPT::SysAllocWrapper::VisitSegments(
        Scaleform::HeapPT::SysAllocWrapper *this,
        Scaleform::Heap::SegVisitor *visitor,
        unsigned __int64 catSeg,
        unsigned __int64 catUnused)
{
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, Scaleform::Heap::SegVisitor *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[4].shutdownHeapEngine)(
    this->pSysAlloc,
    visitor,
    catSeg,
    catUnused);
}

// File Line: 268
// RVA: 0x984980
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::GetFootprint(Scaleform::HeapPT::SysAllocWrapper *this)
{
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *))this->pSysAlloc->vfptr[3].shutdownHeapEngine)(this->pSysAlloc);
}

// File Line: 291
// RVA: 0x93DE20
void __fastcall Scaleform::HeapPT::HeapRoot::HeapRoot(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(&this->AllocWrapper, sysAlloc);
  Scaleform::HeapPT::Granulator::Granulator(
    &this->AllocStarter.Allocator,
    &this->AllocWrapper,
    0x100ui64,
    0x8000ui64,
    0x2000ui64);
  Scaleform::HeapPT::Bookkeeper::Bookkeeper(&this->AllocBookkeeper, &this->AllocWrapper, 0x8000ui64);
  Scaleform::Lock::Lock(&this->RootLock.mLock, 0);
  this->pArenas = 0i64;
  this->NumArenas = 0i64;
  Scaleform::HeapPT::GlobalPageTable->pStarter = &this->AllocStarter;
  Scaleform::HeapPT::GlobalRoot = this;
}

// File Line: 304
// RVA: 0x965F90
void __fastcall Scaleform::HeapPT::HeapRoot::CreateArena(
        Scaleform::HeapPT::HeapRoot *this,
        unsigned __int64 arena,
        Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  unsigned __int64 v7; // r14
  char *v8; // r15
  Scaleform::SysAllocPaged **pArenas; // rdx
  Scaleform::HeapPT::SysAllocWrapper *v10; // rcx
  Scaleform::HeapPT::SysAllocWrapper *v11; // rax

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( this->NumArenas < arena )
  {
    v7 = (arena + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v8 = Scaleform::HeapPT::Bookkeeper::Alloc(&this->AllocBookkeeper, 8 * v7);
    memset(v8, 0, 8 * v7);
    pArenas = this->pArenas;
    if ( pArenas )
    {
      memmove(v8, pArenas, 8 * this->NumArenas);
      Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, this->pArenas, 8 * this->NumArenas);
    }
    this->pArenas = (Scaleform::SysAllocPaged **)v8;
    this->NumArenas = v7;
  }
  this->pArenas[arena - 1] = (Scaleform::SysAllocPaged *)Scaleform::HeapPT::Bookkeeper::Alloc(
                                                           &this->AllocBookkeeper,
                                                           0x168ui64);
  v10 = (Scaleform::HeapPT::SysAllocWrapper *)this->pArenas[arena - 1];
  if ( v10 )
  {
    Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(v10, sysAlloc);
    v10 = v11;
  }
  this->pArenas[arena - 1] = v10;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 330
// RVA: 0x96D830
__int64 __fastcall Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  Scaleform::SysAllocPaged *v5; // rcx
  Scaleform::SysAllocPaged **pArenas; // rax
  unsigned int v7; // edi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(this, arena) )
  {
    v5 = this->pArenas[arena - 1];
    v5->vfptr->__vecDelDtor(v5, 0);
    Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, this->pArenas[arena - 1], 0x168ui64);
    pArenas = this->pArenas;
    v7 = 0;
    pArenas[arena - 1] = 0i64;
  }
  else
  {
    v7 = MEMORY[0];
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v7;
}

// File Line: 356
// RVA: 0x96D480
void __fastcall Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::HeapRoot *this)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  unsigned __int64 i; // rdi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( this->pArenas )
  {
    for ( i = this->NumArenas; i; --i )
    {
      if ( this->pArenas[i - 1] )
        Scaleform::HeapPT::HeapRoot::DestroyArena(this, i);
    }
    Scaleform::HeapPT::Bookkeeper::Free(&this->AllocBookkeeper, this->pArenas, 8 * this->NumArenas);
    this->pArenas = 0i64;
    this->NumArenas = 0i64;
  }
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 373
// RVA: 0x95A0B0
_BOOL8 __fastcall Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena)
{
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  Scaleform::LockSafe *p_RootLock; // rbx
  bool v5; // di

  v3 = this;
  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  EnterCriticalSection(&p_RootLock->mLock.cs);
  if ( arena )
    v3 = (Scaleform::HeapPT::HeapRoot *)v3->pArenas[arena - 1];
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  v5 = ((__int64 (__fastcall *)(Scaleform::HeapPT::HeapRoot *))v3->AllocWrapper.vfptr[4].__vecDelDtor)(v3) == 0;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v5;
}

// File Line: 380
// RVA: 0x98C5C0
Scaleform::HeapPT::HeapRoot *__fastcall Scaleform::HeapPT::HeapRoot::GetSysAlloc(
        Scaleform::HeapPT::HeapRoot *this,
        unsigned __int64 arena)
{
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  Scaleform::LockSafe *p_RootLock; // rbx

  v3 = this;
  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( arena )
    v3 = (Scaleform::HeapPT::HeapRoot *)v3->pArenas[arena - 1];
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v3;
}

// File Line: 396
// RVA: 0x9671F0
Scaleform::MemoryHeapPT *__fastcall Scaleform::HeapPT::HeapRoot::CreateHeap(
        Scaleform::HeapPT::HeapRoot *this,
        const char *name,
        Scaleform::MemoryHeapPT *parent,
        Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  __int64 v8; // rdi
  __int64 v9; // rbx
  unsigned __int64 v10; // rbx
  Scaleform::HeapPT::Bookkeeper *p_AllocBookkeeper; // r13
  char *v12; // rsi
  char v13; // r14
  Scaleform::SysAllocPaged *SysAlloc; // rax
  __int64 v15; // rax
  __int64 v16; // rcx

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  v8 = -1i64;
  v9 = -1i64;
  do
    ++v9;
  while ( name[v9] );
  v10 = (v9 + 2120) & 0xFFFFFFFFFFFFFFE0ui64;
  p_AllocBookkeeper = &this->AllocBookkeeper;
  v12 = Scaleform::HeapPT::Bookkeeper::Alloc(&this->AllocBookkeeper, v10);
  if ( !v12 )
    return 0i64;
  v13 = 0;
  if ( (desc->Flags & 2) != 0 )
    v13 = 16;
  if ( (desc->Flags & 4) == 0 )
    v13 |= 0x20u;
  Scaleform::MemoryHeap::MemoryHeap((Scaleform::MemoryHeap *)v12);
  *(_QWORD *)v12 = &Scaleform::MemoryHeapPT::`vftable;
  *((_QWORD *)v12 + 25) = 0i64;
  *((_QWORD *)v12 + 26) = 0i64;
  if ( v12 == (char *)-216i64 )
  {
    v16 = 0i64;
  }
  else
  {
    SysAlloc = Scaleform::HeapPT::HeapRoot::GetSysAlloc(this, desc->Arena);
    Scaleform::HeapPT::AllocEngine::AllocEngine(
      (Scaleform::HeapPT::AllocEngine *)(v12 + 216),
      SysAlloc,
      (Scaleform::MemoryHeapPT *)v12,
      v13,
      desc->MinAlign,
      desc->Granularity,
      desc->Reserve,
      desc->Threshold,
      desc->Limit);
    v16 = v15;
  }
  if ( !*(_BYTE *)(v16 + 1770) )
  {
    Scaleform::HeapPT::Bookkeeper::Free(p_AllocBookkeeper, v12, v10);
    return 0i64;
  }
  *((_QWORD *)v12 + 3) = v10;
  *((_DWORD *)v12 + 8) = 1;
  *((_QWORD *)v12 + 6) = 0i64;
  *((_QWORD *)v12 + 7) = *(_QWORD *)&desc->Flags;
  *((_QWORD *)v12 + 8) = desc->MinAlign;
  *((_QWORD *)v12 + 9) = desc->Granularity;
  *((_QWORD *)v12 + 10) = desc->Reserve;
  *((_QWORD *)v12 + 11) = desc->Threshold;
  *((_QWORD *)v12 + 12) = desc->Limit;
  *((_QWORD *)v12 + 13) = desc->HeapId;
  *((_QWORD *)v12 + 14) = desc->Arena;
  *((_QWORD *)v12 + 15) = parent;
  *((_QWORD *)v12 + 16) = v12 + 2088;
  v12[192] = (desc->Flags & 1) == 0;
  v12[193] = (desc->Flags & 0x10) == 0;
  *((_QWORD *)v12 + 25) = v16;
  do
    ++v8;
  while ( name[v8] );
  memmove(v12 + 2088, name, v8 + 1);
  return (Scaleform::MemoryHeapPT *)v12;
}

// File Line: 532
// RVA: 0x9C1F70
void __fastcall Scaleform::HeapPT::HeapRoot::VisitSegments(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::LockSafe *p_RootLock; // rbx

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  ((void (__fastcall *)(Scaleform::HeapPT::HeapRoot *, Scaleform::Heap::SegVisitor *, __int64))this->AllocWrapper.vfptr[4].shutdownHeapEngine)(
    this,
    visitor,
    1i64);
  Scaleform::HeapPT::Granulator::visitSegments(
    &this->AllocStarter.Allocator,
    this->AllocStarter.Allocator.UsedSeg.Root,
    visitor,
    2u);
  Scaleform::HeapPT::AllocLite::visitUnusedInTree(
    &this->AllocStarter.Allocator.Allocator,
    this->AllocStarter.Allocator.Allocator.SizeTree.Tree.Root,
    visitor,
    0x82u);
  Scaleform::HeapPT::Bookkeeper::VisitSegments(&this->AllocBookkeeper, visitor);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 549
// RVA: 0x98BA10
void __fastcall Scaleform::HeapPT::HeapRoot::GetStats(
        Scaleform::HeapPT::HeapRoot *this,
        Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::LockSafe *p_RootLock; // rbx

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  stats->SysMemFootprint = ((__int64 (__fastcall *)(Scaleform::HeapPT::HeapRoot *))this->AllocWrapper.vfptr[3].shutdownHeapEngine)(this);
  stats->SysMemUsedSpace = ((__int64 (__fastcall *)(Scaleform::HeapPT::HeapRoot *))this->AllocWrapper.vfptr[4].__vecDelDtor)(this);
  stats->PageMapFootprint = this->AllocStarter.Allocator.Footprint;
  stats->PageMapUsedSpace = this->AllocStarter.Allocator.Footprint
                          - (this->AllocStarter.Allocator.Allocator.FreeBlocks << this->AllocStarter.Allocator.Allocator.MinShift);
  stats->BookkeepingFootprint = this->AllocBookkeeper.Footprint;
  stats->BookkeepingUsedSpace = this->AllocBookkeeper.Footprint
                              - (this->AllocBookkeeper.Allocator.Bin.FreeBlocks << this->AllocBookkeeper.Allocator.MinAlignShift);
  stats->DebugInfoFootprint = 0i64;
  stats->DebugInfoUsedSpace = 0i64;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

// File Line: 569
// RVA: 0x957E60
__int64 __fastcall Scaleform::HeapPT::HeapRoot::AllocSysDirect(
        Scaleform::HeapPT::HeapRoot *this,
        unsigned __int64 size)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  unsigned __int64 v5; // rdx
  __int64 v6; // rdi

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v5 = this->AllocWrapper.SysGranularity
     * ((this->AllocWrapper.SysGranularity + size - 1)
      / this->AllocWrapper.SysGranularity);
  this->AllocWrapper.UsedSpace += v5;
  v6 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))this->AllocWrapper.pSrcAlloc->vfptr[1].initHeapEngine)(
         this->AllocWrapper.pSrcAlloc,
         v5,
         this->AllocWrapper.MinAlign);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v6;
}

// File Line: 574
// RVA: 0x97E510
void __fastcall Scaleform::HeapPT::HeapRoot::FreeSysDirect(
        Scaleform::HeapPT::HeapRoot *this,
        void *ptr,
        unsigned __int64 size)
{
  Scaleform::LockSafe *p_RootLock; // rbx
  unsigned __int64 v7; // r8

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v7 = this->AllocWrapper.SysGranularity
     * ((this->AllocWrapper.SysGranularity + size - 1)
      / this->AllocWrapper.SysGranularity);
  this->AllocWrapper.UsedSpace -= v7;
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64, __int64))this->AllocWrapper.pSrcAlloc->vfptr[1].shutdownHeapEngine)(
    this->AllocWrapper.pSrcAlloc,
    ptr,
    v7,
    this->AllocWrapper.MinAlign,
    -2i64);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
}

