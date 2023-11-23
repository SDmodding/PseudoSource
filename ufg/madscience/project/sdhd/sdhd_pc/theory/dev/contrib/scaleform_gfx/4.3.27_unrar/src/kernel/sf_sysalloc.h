// File Line: 37
// RVA: 0x49210
void __fastcall Scaleform::SysAllocBase::~SysAllocBase(Scaleform::SysAllocBase *this)
{
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
}

// File Line: 74
// RVA: 0x491E0
void __fastcall Scaleform::SysAlloc::~SysAlloc(Scaleform::SysAlloc *this)
{
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAlloc::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
}

// File Line: 195
// RVA: 0x94CF90
void __fastcall Scaleform::SysAllocPaged::~SysAllocPaged(Scaleform::SysAllocPaged *this)
{
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
}

// File Line: 278
// RVA: 0x51910
Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::SysAllocContainer *__fastcall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton()
{
  if ( (`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::`local static guard & 1) == 0 )
  {
    `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::`local static guard |= 1u;
    `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container.Initialized = 0;
  }
  `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container.Data[0] = (unsigned __int64)&Scaleform::SysAllocMalloc::`vftable;
  `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container.Data[1] = (unsigned __int64)&`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container;
  `Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container.Initialized = 1;
  return &`Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::InitSystemSingleton::`2::Container;
}

// File Line: 298
// RVA: 0x9F2420
__int64 __fastcall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::shutdownHeapEngine(
        Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged> *this)
{
  unsigned __int8 v2; // di
  Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::SysAllocContainer *pContainer; // rax

  v2 = Scaleform::MemoryHeap::ReleaseRootHeapPT();
  Scaleform::MemoryHeap::CleanUpPT();
  pContainer = this->pContainer;
  if ( pContainer )
  {
    pContainer->Initialized = 0;
    this->vfptr->__vecDelDtor(this, 0i64);
    this->pContainer = 0i64;
  }
  return v2;
}

// File Line: 341
// RVA: 0xA10640
void __fastcall Scaleform::SysMemMapper::~SysMemMapper(Scaleform::SysMemMapper *this)
{
  this->vfptr = (Scaleform::SysMemMapperVtbl *)&Scaleform::SysMemMapper::`vftable;
}

