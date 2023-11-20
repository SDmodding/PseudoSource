// File Line: 68
// RVA: 0x93F7B0
void __fastcall Scaleform::MemoryHeap::MemoryHeap(Scaleform::MemoryHeap *this)
{
  Scaleform::MemoryHeap *v1; // rbx
  signed __int64 v2; // rax
  _QWORD *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::MemoryHeap::`vftable;
  v2 = 0i64;
  this->SelfSize = 0i64;
  this->RefCount = 1;
  this->OwnerThreadId = 0i64;
  this->pAutoRelease = 0i64;
  this->Info.Desc.Flags = 0;
  this->Info.Desc.MinAlign = 16i64;
  this->Info.Desc.Granularity = 0x2000i64;
  this->Info.Desc.Reserve = 0x2000i64;
  this->Info.Desc.Threshold = -1i64;
  this->Info.Desc.Limit = 0i64;
  this->Info.Desc.HeapId = 0i64;
  this->Info.Desc.Arena = 0i64;
  v3 = &this->ChildHeaps.Root.pPrev;
  if ( v3 )
    v2 = (signed __int64)(v3 - 1);
  *v3 = v2;
  v3[1] = v2;
  Scaleform::Lock::Lock(&v1->HeapLock, 0);
  *(_WORD *)&v1->UseLocks = 257;
  memset(&v1->Info, 0, 0x50ui64);
}

// File Line: 86
// RVA: 0x95A330
void __fastcall Scaleform::MemoryHeap::AssignToCurrentThread(Scaleform::MemoryHeap *this)
{
  this->OwnerThreadId = GetCurrentThreadId();
}

