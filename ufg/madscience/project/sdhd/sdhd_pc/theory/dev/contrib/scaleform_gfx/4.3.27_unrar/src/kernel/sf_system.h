// File Line: 42
// RVA: 0x48E10
void __fastcall Scaleform::System::System(Scaleform::System *this, Scaleform::SysAllocBase *psysAlloc)
{
  int v2; // [rsp+20h] [rbp-48h]
  __int64 v3; // [rsp+28h] [rbp-40h]
  __int64 v4; // [rsp+30h] [rbp-38h]
  __int64 v5; // [rsp+38h] [rbp-30h]
  __int64 v6; // [rsp+40h] [rbp-28h]
  __int64 v7; // [rsp+48h] [rbp-20h]
  __int64 v8; // [rsp+50h] [rbp-18h]
  __int64 v9; // [rsp+58h] [rbp-10h]

  v2 = 0;
  v3 = 16i64;
  v4 = 0x4000i64;
  v5 = 0x4000i64;
  v6 = 0x40000i64;
  v7 = 0i64;
  v8 = 1i64;
  v9 = 0i64;
  Scaleform::System::Init((Scaleform::MemoryHeap::HeapDesc *)&v2, psysAlloc);
}

// File Line: 46
// RVA: 0x48DF0
void __fastcall Scaleform::System::System(Scaleform::System *this, Scaleform::MemoryHeap::HeapDesc *rootHeapDesc, Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}

// File Line: 53
// RVA: 0x49220
void __fastcall Scaleform::System::~System(Scaleform::System *this)
{
  Scaleform::System::Destroy();
}

// File Line: 65
// RVA: 0x50B00
void __fastcall Scaleform::System::Init(Scaleform::SysAllocBase *psysAlloc)
{
  int v1; // [rsp+20h] [rbp-48h]
  __int64 v2; // [rsp+28h] [rbp-40h]
  __int64 v3; // [rsp+30h] [rbp-38h]
  __int64 v4; // [rsp+38h] [rbp-30h]
  __int64 v5; // [rsp+40h] [rbp-28h]
  __int64 v6; // [rsp+48h] [rbp-20h]
  __int64 v7; // [rsp+50h] [rbp-18h]
  __int64 v8; // [rsp+58h] [rbp-10h]

  v1 = 0;
  v2 = 16i64;
  v3 = 0x4000i64;
  v4 = 0x4000i64;
  v5 = 0x40000i64;
  v6 = 0i64;
  v7 = 1i64;
  v8 = 0i64;
  Scaleform::System::Init((Scaleform::MemoryHeap::HeapDesc *)&v1, psysAlloc);
}

