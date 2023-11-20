// File Line: 52
// RVA: 0x9927F0
void __fastcall Scaleform::HeapPT::SysAllocGranulator::Init(Scaleform::HeapPT::SysAllocGranulator *this, Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::SysAllocGranulator *v2; // rbx
  Scaleform::HeapPT::Granulator *v3; // rcx
  Scaleform::HeapPT::Granulator *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rcx
  __int128 v7; // [rsp+38h] [rbp-40h]
  __int64 v8; // [rsp+48h] [rbp-30h]
  __int128 v9; // [rsp+50h] [rbp-28h]
  __int64 v10; // [rsp+60h] [rbp-18h]

  v2 = this;
  v3 = (Scaleform::HeapPT::Granulator *)this->PrivateData;
  if ( v3 )
    Scaleform::HeapPT::Granulator::Granulator(v3, sysAlloc, 0x1000ui64, 0x1000ui64, 0x2000ui64);
  else
    v4 = 0i64;
  v2->pGranulator = v4;
  v7 = 0ui64;
  v8 = 0i64;
  v9 = 0ui64;
  v10 = 0i64;
  v4->pSysAlloc->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)&v4->pSysAlloc->vfptr, (unsigned int)&v7);
  *(_OWORD *)&v2->SysDirectThreshold = v9;
  v5 = v7;
  v2->MinAlign = v7;
  v6 = *((_QWORD *)&v7 + 1);
  v2->MaxAlign = *((_QWORD *)&v7 + 1);
  if ( !v5 )
    v2->MinAlign = 1i64;
  if ( !v6 )
    v2->MaxAlign = 0x8000000000000000i64;
}

// File Line: 77
// RVA: 0x987530
void __fastcall Scaleform::HeapPT::SysAllocGranulator::GetInfo(Scaleform::HeapPT::SysAllocGranulator *this, Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 v2; // rax

  i->MinAlign = 0i64;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->SysDirectThreshold = this->SysDirectThreshold;
  v2 = this->MaxHeapGranularity;
  i->HasRealloc = 1;
  i->MaxHeapGranularity = v2;
}

// File Line: 89
// RVA: 0x956D40
Scaleform::HeapPT::DualTNode *__fastcall Scaleform::HeapPT::SysAllocGranulator::Alloc(Scaleform::HeapPT::SysAllocGranulator *this, unsigned __int64 size, unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::Alloc(this->pGranulator, size, alignment);
}

// File Line: 104
// RVA: 0x9A7080
bool __fastcall Scaleform::HeapPT::SysAllocGranulator::ReallocInPlace(Scaleform::HeapPT::SysAllocGranulator *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::ReallocInPlace(this->pGranulator, oldPtr, oldSize, newSize, alignment);
}

// File Line: 111
// RVA: 0x97DFE0
bool __fastcall Scaleform::HeapPT::SysAllocGranulator::Free(Scaleform::HeapPT::SysAllocGranulator *this, void *ptr, unsigned __int64 size, unsigned __int64 alignment)
{
  return Scaleform::HeapPT::Granulator::Free(this->pGranulator, ptr, size, alignment);
}

// File Line: 127
// RVA: 0x957F70
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::AllocSysDirect(Scaleform::HeapPT::SysAllocGranulator *this, unsigned __int64 size, unsigned __int64 alignment, unsigned __int64 *actualSize, unsigned __int64 *actualAlign)
{
  unsigned __int64 v5; // r10
  Scaleform::HeapPT::Granulator *v6; // rax

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
  v6 = this->pGranulator;
  this->SysDirectFootprint += size;
  return ((__int64 (*)(void))v6->pSysAlloc->vfptr[1].initHeapEngine)();
}

// File Line: 150
// RVA: 0x97E630
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::FreeSysDirect(Scaleform::HeapPT::SysAllocGranulator *this, void *ptr, unsigned __int64 size, unsigned __int64 alignment)
{
  Scaleform::HeapPT::Granulator *v4; // rax

  v4 = this->pGranulator;
  this->SysDirectFootprint -= size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64))v4->pSysAlloc->vfptr[1].shutdownHeapEngine)(
           v4->pSysAlloc,
           ptr,
           size,
           alignment);
}

// File Line: 158
// RVA: 0x9C1DA0
void __fastcall Scaleform::HeapPT::SysAllocGranulator::VisitMem(Scaleform::HeapPT::SysAllocGranulator *this, Scaleform::Heap::MemVisitor *visitor)
{
  Scaleform::Heap::MemVisitor *v2; // r9
  Scaleform::HeapPT::AllocLite *v3; // rcx
  Scaleform::HeapPT::DualTNode *v4; // rdx
  __int64 v5; // [rsp+30h] [rbp-48h]
  __int64 v6; // [rsp+40h] [rbp-38h]
  __int64 v7; // [rsp+48h] [rbp-30h]
  __int64 v8; // [rsp+50h] [rbp-28h]
  __int64 v9; // [rsp+58h] [rbp-20h]
  __int64 v10; // [rsp+60h] [rbp-18h]
  __int64 v11; // [rsp+68h] [rbp-10h]

  v2 = visitor;
  v3 = &this->pGranulator->Allocator;
  v7 = 16i64;
  v4 = v3->SizeTree.Tree.Root;
  v6 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  v11 = 0i64;
  Scaleform::HeapPT::AllocLite::visitTree(v3, v4, (Scaleform::Heap::HeapSegment *)&v5, v2, Cat_SysAllocFree);
}

// File Line: 166
// RVA: 0x9C2030
void __fastcall Scaleform::HeapPT::SysAllocGranulator::VisitSegments(Scaleform::HeapPT::SysAllocGranulator *this, Scaleform::Heap::SegVisitor *visitor, unsigned __int64 catSeg, unsigned __int64 catUnused)
{
  Scaleform::HeapPT::Granulator *v4; // rbx
  unsigned int v5; // esi
  Scaleform::Heap::SegVisitor *v6; // rdi

  v4 = this->pGranulator;
  v5 = catUnused;
  v6 = visitor;
  Scaleform::HeapPT::Granulator::visitSegments(this->pGranulator, v4->UsedSeg.Root, visitor, catSeg);
  Scaleform::HeapPT::AllocLite::visitUnusedInTree(&v4->Allocator, v4->Allocator.SizeTree.Tree.Root, v6, v5);
}

// File Line: 171
// RVA: 0x984970
unsigned __int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetFootprint(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint + this->pGranulator->Footprint;
}

// File Line: 172
// RVA: 0x98EA80
unsigned __int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetUsedSpace(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return this->SysDirectFootprint
       + this->pGranulator->Footprint
       - (this->pGranulator->Allocator.FreeBlocks << this->pGranulator->Allocator.MinShift);
}

// File Line: 175
// RVA: 0x9800A0
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetBase(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return ((__int64 (*)(void))this->pGranulator->pSysAlloc->vfptr[3].__vecDelDtor)();
}

// File Line: 176
// RVA: 0x98B730
__int64 __fastcall Scaleform::HeapPT::SysAllocGranulator::GetSize(Scaleform::HeapPT::SysAllocGranulator *this)
{
  return ((__int64 (*)(void))this->pGranulator->pSysAlloc->vfptr[3].initHeapEngine)();
}

// File Line: 188
// RVA: 0x945770
void __fastcall Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(Scaleform::HeapPT::SysAllocWrapper *this, Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::SysAllocPaged *v2; // rsi
  Scaleform::HeapPT::SysAllocWrapper *v3; // rbx
  Scaleform::HeapPT::SysAllocGranulator *v4; // rdi
  unsigned __int64 v5; // [rsp+28h] [rbp-40h]
  __int64 v6; // [rsp+30h] [rbp-38h]
  __int128 v7; // [rsp+38h] [rbp-30h]
  __int64 v8; // [rsp+48h] [rbp-20h]
  __int64 v9; // [rsp+50h] [rbp-18h]

  v2 = sysAlloc;
  v3 = this;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::HeapPT::SysAllocWrapper::`vftable;
  v4 = &this->Allocator;
  this->Allocator.vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  v4->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  v4->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::HeapPT::SysAllocGranulator::`vftable;
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
  v5 = 0i64;
  v6 = 0i64;
  v7 = 0ui64;
  v8 = 0i64;
  v9 = 0i64;
  v2->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)&v2->vfptr, (unsigned int)&v5);
  if ( (_QWORD)v7 )
  {
    Scaleform::HeapPT::SysAllocGranulator::Init(&v3->Allocator, v2);
    v3->pSysAlloc = (Scaleform::SysAllocPaged *)&v4->vfptr;
    v3->SysGranularity = v7;
  }
  if ( v3->MinAlign < v5 )
    v3->MinAlign = v5;
}

// File Line: 204
// RVA: 0x9875E0
void __fastcall Scaleform::HeapPT::SysAllocWrapper::GetInfo(Scaleform::HeapPT::SysAllocWrapper *this, Scaleform::SysAllocPaged::Info *i)
{
  i->MinAlign = 0i64;
  i->MaxAlign = 0i64;
  i->Granularity = 0i64;
  i->SysDirectThreshold = 0i64;
  i->MaxHeapGranularity = 0i64;
  *(_QWORD *)&i->HasRealloc = 0i64;
  ((void (*)(void))this->pSysAlloc->vfptr[1].__vecDelDtor)();
}

// File Line: 210
// RVA: 0x956E30
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::Alloc(Scaleform::HeapPT::SysAllocWrapper *this, unsigned __int64 size, unsigned __int64 align)
{
  this->UsedSpace += size;
  return ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))this->pSysAlloc->vfptr[1].initHeapEngine)(
           this->pSysAlloc,
           size,
           align);
}

// File Line: 216
// RVA: 0x97E1F0
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::Free(Scaleform::HeapPT::SysAllocWrapper *this, void *ptr, unsigned __int64 size, unsigned __int64 align)
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
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::ReallocInPlace(Scaleform::HeapPT::SysAllocWrapper *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 align)
{
  this->UsedSpace += newSize - oldSize;
  return this->pSysAlloc->vfptr[2].__vecDelDtor((Scaleform::SysAllocBase *)this->pSysAlloc, (unsigned int)oldPtr);
}

// File Line: 229
// RVA: 0x957FC0
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::AllocSysDirect(Scaleform::HeapPT::SysAllocWrapper *this, unsigned __int64 size, unsigned __int64 alignment, unsigned __int64 *actualSize, unsigned __int64 *actualAlign)
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
__int64 __fastcall Scaleform::HeapPT::SysAllocWrapper::FreeSysDirect(Scaleform::HeapPT::SysAllocWrapper *this, void *ptr, unsigned __int64 size, unsigned __int64 alignment)
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
void __fastcall Scaleform::HeapPT::SysAllocWrapper::VisitMem(Scaleform::HeapPT::SysAllocWrapper *this, Scaleform::Heap::MemVisitor *visitor)
{
  this->pSysAlloc->vfptr[4].initHeapEngine((Scaleform::SysAllocBase *)this->pSysAlloc, visitor);
}

// File Line: 247
// RVA: 0x9C2090
void __fastcall Scaleform::HeapPT::SysAllocWrapper::VisitSegments(Scaleform::HeapPT::SysAllocWrapper *this, Scaleform::Heap::SegVisitor *visitor, unsigned __int64 catSeg, unsigned __int64 catUnused)
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
  return ((__int64 (*)(void))this->pSysAlloc->vfptr[3].shutdownHeapEngine)();
}

// File Line: 291
// RVA: 0x93DE20
void __fastcall Scaleform::HeapPT::HeapRoot::HeapRoot(Scaleform::HeapPT::HeapRoot *this, Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::HeapPT::HeapRoot *v2; // rdi

  v2 = this;
  Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(&this->AllocWrapper, sysAlloc);
  Scaleform::HeapPT::Granulator::Granulator(
    &v2->AllocStarter.Allocator,
    (Scaleform::SysAllocPaged *)&v2->AllocWrapper.vfptr,
    0x100ui64,
    0x8000ui64,
    0x2000ui64);
  Scaleform::HeapPT::Bookkeeper::Bookkeeper(
    &v2->AllocBookkeeper,
    (Scaleform::SysAllocPaged *)&v2->AllocWrapper.vfptr,
    0x8000ui64);
  Scaleform::Lock::Lock(&v2->RootLock.mLock, 0);
  v2->pArenas = 0i64;
  v2->NumArenas = 0i64;
  Scaleform::HeapPT::GlobalPageTable->pStarter = &v2->AllocStarter;
  Scaleform::HeapPT::GlobalRoot = v2;
}

// File Line: 304
// RVA: 0x965F90
void __fastcall Scaleform::HeapPT::HeapRoot::CreateArena(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena, Scaleform::SysAllocPaged *sysAlloc)
{
  Scaleform::SysAllocPaged *v3; // r12
  unsigned __int64 v4; // rbp
  Scaleform::HeapPT::HeapRoot *v5; // rsi
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int64 v7; // r14
  char *v8; // r15
  Scaleform::SysAllocPaged **v9; // rdx
  Scaleform::HeapPT::SysAllocWrapper *v10; // rcx
  Scaleform::HeapPT::SysAllocWrapper *v11; // rax

  v3 = sysAlloc;
  v4 = arena;
  v5 = this;
  v6 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( v5->NumArenas < v4 )
  {
    v7 = (v4 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
    v8 = Scaleform::HeapPT::Bookkeeper::Alloc(&v5->AllocBookkeeper, 8 * v7);
    memset(v8, 0, 8 * v7);
    v9 = v5->pArenas;
    if ( v9 )
    {
      memmove(v8, v9, 8 * v5->NumArenas);
      Scaleform::HeapPT::Bookkeeper::Free(&v5->AllocBookkeeper, v5->pArenas, 8 * v5->NumArenas);
    }
    v5->pArenas = (Scaleform::SysAllocPaged **)v8;
    v5->NumArenas = v7;
  }
  v5->pArenas[v4 - 1] = (Scaleform::SysAllocPaged *)Scaleform::HeapPT::Bookkeeper::Alloc(
                                                      &v5->AllocBookkeeper,
                                                      0x168ui64);
  v10 = (Scaleform::HeapPT::SysAllocWrapper *)v5->pArenas[v4 - 1];
  if ( v10 )
  {
    Scaleform::HeapPT::SysAllocWrapper::SysAllocWrapper(v10, v3);
    v10 = v11;
  }
  v5->pArenas[v4 - 1] = (Scaleform::SysAllocPaged *)&v10->vfptr;
  LeaveCriticalSection(v6);
}

// File Line: 330
// RVA: 0x96D830
__int64 __fastcall Scaleform::HeapPT::HeapRoot::DestroyArena(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena)
{
  unsigned __int64 v2; // rsi
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::SysAllocPaged *v5; // rcx
  Scaleform::SysAllocPaged **v6; // rax
  unsigned int v7; // edi

  v2 = arena;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( (unsigned __int8)Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(v3, v2) )
  {
    v5 = v3->pArenas[v2 - 1];
    v5->vfptr->__vecDelDtor((Scaleform::SysAllocBase *)v5, 0);
    Scaleform::HeapPT::Bookkeeper::Free(&v3->AllocBookkeeper, v3->pArenas[v2 - 1], 0x168ui64);
    v6 = v3->pArenas;
    v7 = 0;
    v6[v2 - 1] = 0i64;
  }
  else
  {
    v7 = MEMORY[0];
  }
  LeaveCriticalSection(v4);
  return v7;
}

// File Line: 356
// RVA: 0x96D480
void __fastcall Scaleform::HeapPT::HeapRoot::DestroyAllArenas(Scaleform::HeapPT::HeapRoot *this)
{
  Scaleform::HeapPT::HeapRoot *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  unsigned __int64 i; // rdi

  v1 = this;
  v2 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( v1->pArenas )
  {
    for ( i = v1->NumArenas; i; --i )
    {
      if ( v1->pArenas[i - 1] )
        Scaleform::HeapPT::HeapRoot::DestroyArena(v1, i);
    }
    Scaleform::HeapPT::Bookkeeper::Free(&v1->AllocBookkeeper, v1->pArenas, 8 * v1->NumArenas);
    v1->pArenas = 0i64;
    v1->NumArenas = 0i64;
  }
  LeaveCriticalSection(v2);
}

// File Line: 373
// RVA: 0x95A0B0
_BOOL8 __fastcall Scaleform::HeapPT::HeapRoot::ArenaIsEmpty(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena)
{
  unsigned __int64 v2; // rsi
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  bool v5; // di

  v2 = arena;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  EnterCriticalSection(v4);
  if ( v2 )
    v3 = (Scaleform::HeapPT::HeapRoot *)v3->pArenas[v2 - 1];
  LeaveCriticalSection(v4);
  v5 = ((__int64 (__fastcall *)(Scaleform::HeapPT::HeapRoot *))v3->AllocWrapper.vfptr[4].__vecDelDtor)(v3) == 0;
  LeaveCriticalSection(v4);
  return v5;
}

// File Line: 380
// RVA: 0x98C5C0
Scaleform::HeapPT::HeapRoot *__fastcall Scaleform::HeapPT::HeapRoot::GetSysAlloc(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 arena)
{
  unsigned __int64 v2; // rsi
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = arena;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  if ( v2 )
    v3 = (Scaleform::HeapPT::HeapRoot *)v3->pArenas[v2 - 1];
  LeaveCriticalSection(v4);
  return v3;
}

// File Line: 396
// RVA: 0x9671F0
Scaleform::MemoryHeapPT *__fastcall Scaleform::HeapPT::HeapRoot::CreateHeap(Scaleform::HeapPT::HeapRoot *this, const char *name, Scaleform::MemoryHeapPT *parent, Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::MemoryHeap::HeapDesc *v4; // r15
  const char *v5; // rbp
  Scaleform::HeapPT::HeapRoot *v6; // rsi
  _RTL_CRITICAL_SECTION *v7; // rbx
  signed __int64 v8; // rdi
  signed __int64 v9; // rbx
  unsigned __int64 v10; // rbx
  Scaleform::HeapPT::Bookkeeper *v11; // r13
  char *v12; // rsi
  unsigned int v13; // er14
  Scaleform::SysAllocPaged *v14; // rax
  __int64 v15; // rax
  __int64 v16; // rcx
  Scaleform::HeapPT::HeapRoot *v18; // [rsp+B0h] [rbp+8h]
  Scaleform::MemoryHeapPT *v19; // [rsp+C0h] [rbp+18h]

  v19 = parent;
  v18 = this;
  v4 = desc;
  v5 = name;
  v6 = this;
  v7 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  LeaveCriticalSection(v7);
  v8 = -1i64;
  v9 = -1i64;
  do
    ++v9;
  while ( v5[v9] );
  v10 = (v9 + 2120) & 0xFFFFFFFFFFFFFFE0ui64;
  v11 = &v6->AllocBookkeeper;
  v12 = Scaleform::HeapPT::Bookkeeper::Alloc(&v6->AllocBookkeeper, v10);
  if ( !v12 )
    return 0i64;
  v13 = 0;
  if ( v4->Flags & 2 )
    v13 = 16;
  if ( !(v4->Flags & 4) )
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
    v14 = Scaleform::HeapPT::HeapRoot::GetSysAlloc(v18, v4->Arena);
    Scaleform::HeapPT::AllocEngine::AllocEngine(
      (Scaleform::HeapPT::AllocEngine *)(v12 + 216),
      v14,
      (Scaleform::MemoryHeapPT *)v12,
      v13,
      v4->MinAlign,
      v4->Granularity,
      v4->Reserve,
      v4->Threshold,
      v4->Limit);
    v16 = v15;
  }
  if ( !*(_BYTE *)(v16 + 1770) )
  {
    Scaleform::HeapPT::Bookkeeper::Free(v11, v12, v10);
    return 0i64;
  }
  *((_QWORD *)v12 + 3) = v10;
  *((_DWORD *)v12 + 8) = 1;
  *((_QWORD *)v12 + 6) = 0i64;
  *((_QWORD *)v12 + 7) = *(_QWORD *)&v4->Flags;
  *((_QWORD *)v12 + 8) = v4->MinAlign;
  *((_QWORD *)v12 + 9) = v4->Granularity;
  *((_QWORD *)v12 + 10) = v4->Reserve;
  *((_QWORD *)v12 + 11) = v4->Threshold;
  *((_QWORD *)v12 + 12) = v4->Limit;
  *((_QWORD *)v12 + 13) = v4->HeapId;
  *((_QWORD *)v12 + 14) = v4->Arena;
  *((_QWORD *)v12 + 15) = v19;
  *((_QWORD *)v12 + 16) = v12 + 2088;
  v12[192] = ~LOBYTE(v4->Flags) & 1;
  v12[193] = ~(unsigned __int8)(v4->Flags >> 4) & 1;
  *((_QWORD *)v12 + 25) = v16;
  do
    ++v8;
  while ( v5[v8] );
  memmove(v12 + 2088, v5, v8 + 1);
  return (Scaleform::MemoryHeapPT *)v12;
}

// File Line: 532
// RVA: 0x9C1F70
void __fastcall Scaleform::HeapPT::HeapRoot::VisitSegments(Scaleform::HeapPT::HeapRoot *this, Scaleform::Heap::SegVisitor *visitor)
{
  Scaleform::Heap::SegVisitor *v2; // rbp
  Scaleform::HeapPT::HeapRoot *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = visitor;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  ((void (__fastcall *)(Scaleform::HeapPT::HeapRoot *, Scaleform::Heap::SegVisitor *, signed __int64))v3->AllocWrapper.vfptr[4].shutdownHeapEngine)(
    v3,
    v2,
    1i64);
  Scaleform::HeapPT::Granulator::visitSegments(
    &v3->AllocStarter.Allocator,
    v3->AllocStarter.Allocator.UsedSeg.Root,
    v2,
    2u);
  Scaleform::HeapPT::AllocLite::visitUnusedInTree(
    &v3->AllocStarter.Allocator.Allocator,
    v3->AllocStarter.Allocator.Allocator.SizeTree.Tree.Root,
    v2,
    0x82u);
  Scaleform::HeapPT::Bookkeeper::VisitSegments(&v3->AllocBookkeeper, v2);
  LeaveCriticalSection(v4);
}

// File Line: 549
// RVA: 0x98BA10
void __fastcall Scaleform::HeapPT::HeapRoot::GetStats(Scaleform::HeapPT::HeapRoot *this, Scaleform::MemoryHeap::RootStats *stats)
{
  Scaleform::MemoryHeap::RootStats *v2; // rsi
  Scaleform::HeapPT::HeapRoot *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = stats;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v2->SysMemFootprint = v3->AllocWrapper.vfptr[3].shutdownHeapEngine((Scaleform::SysAllocBase *)&v3->AllocWrapper.vfptr);
  v2->SysMemUsedSpace = ((__int64 (__fastcall *)(Scaleform::HeapPT::HeapRoot *))v3->AllocWrapper.vfptr[4].__vecDelDtor)(v3);
  v2->PageMapFootprint = v3->AllocStarter.Allocator.Footprint;
  v2->PageMapUsedSpace = v3->AllocStarter.Allocator.Footprint
                       - (v3->AllocStarter.Allocator.Allocator.FreeBlocks << v3->AllocStarter.Allocator.Allocator.MinShift);
  v2->BookkeepingFootprint = v3->AllocBookkeeper.Footprint;
  v2->BookkeepingUsedSpace = v3->AllocBookkeeper.Footprint
                           - (v3->AllocBookkeeper.Allocator.Bin.FreeBlocks << v3->AllocBookkeeper.Allocator.MinAlignShift);
  v2->DebugInfoFootprint = 0i64;
  v2->DebugInfoUsedSpace = 0i64;
  LeaveCriticalSection(v4);
}

// File Line: 569
// RVA: 0x957E60
__int64 __fastcall Scaleform::HeapPT::HeapRoot::AllocSysDirect(Scaleform::HeapPT::HeapRoot *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  Scaleform::HeapPT::HeapRoot *v3; // rsi
  _RTL_CRITICAL_SECTION *v4; // rbx
  unsigned __int64 v5; // rdx
  __int64 v6; // rdi

  v2 = size;
  v3 = this;
  v4 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v5 = v3->AllocWrapper.SysGranularity * ((v3->AllocWrapper.SysGranularity + v2 - 1) / v3->AllocWrapper.SysGranularity);
  v3->AllocWrapper.UsedSpace += v5;
  v6 = ((__int64 (__fastcall *)(Scaleform::SysAllocPaged *, unsigned __int64, unsigned __int64))v3->AllocWrapper.pSrcAlloc->vfptr[1].initHeapEngine)(
         v3->AllocWrapper.pSrcAlloc,
         v5,
         v3->AllocWrapper.MinAlign);
  LeaveCriticalSection(v4);
  return v6;
}

// File Line: 574
// RVA: 0x97E510
void __fastcall Scaleform::HeapPT::HeapRoot::FreeSysDirect(Scaleform::HeapPT::HeapRoot *this, void *ptr, unsigned __int64 size)
{
  unsigned __int64 v3; // rdi
  void *v4; // rbp
  Scaleform::HeapPT::HeapRoot *v5; // rsi
  _RTL_CRITICAL_SECTION *v6; // rbx
  unsigned __int64 v7; // r8

  v3 = size;
  v4 = ptr;
  v5 = this;
  v6 = &this->RootLock.mLock.cs;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  v7 = v5->AllocWrapper.SysGranularity * ((v5->AllocWrapper.SysGranularity + v3 - 1) / v5->AllocWrapper.SysGranularity);
  v5->AllocWrapper.UsedSpace -= v7;
  ((void (__fastcall *)(Scaleform::SysAllocPaged *, void *, unsigned __int64, unsigned __int64, signed __int64))v5->AllocWrapper.pSrcAlloc->vfptr[1].shutdownHeapEngine)(
    v5->AllocWrapper.pSrcAlloc,
    v4,
    v7,
    v5->AllocWrapper.MinAlign,
    -2i64);
  LeaveCriticalSection(v6);
}

