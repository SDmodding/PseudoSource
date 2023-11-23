// File Line: 42
// RVA: 0x48E10
void __fastcall Scaleform::System::System(Scaleform::System *this, Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::MemoryHeap::HeapDesc v2; // [rsp+20h] [rbp-48h] BYREF

  v2.Flags = 0;
  v2.MinAlign = 16i64;
  v2.Granularity = 0x4000i64;
  v2.Reserve = 0x4000i64;
  v2.Threshold = 0x40000i64;
  v2.Limit = 0i64;
  v2.HeapId = 1i64;
  v2.Arena = 0i64;
  Scaleform::System::Init(&v2, psysAlloc);
}

// File Line: 46
// RVA: 0x48DF0
void __fastcall Scaleform::System::System(
        Scaleform::System *this,
        Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}

// File Line: 53
// RVA: 0x49220
// attributes: thunk
void __fastcall Scaleform::System::~System(Scaleform::System *this)
{
  Scaleform::System::Destroy();
}

// File Line: 65
// RVA: 0x50B00
void __fastcall Scaleform::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::MemoryHeap::HeapDesc v1; // [rsp+20h] [rbp-48h] BYREF

  v1.Flags = 0;
  v1.MinAlign = 16i64;
  v1.Granularity = 0x4000i64;
  v1.Reserve = 0x4000i64;
  v1.Threshold = 0x40000i64;
  v1.Limit = 0i64;
  v1.HeapId = 1i64;
  v1.Arena = 0i64;
  Scaleform::System::Init(&v1, psysAlloc);
}

