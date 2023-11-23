// File Line: 68
// RVA: 0x93F7B0
void __fastcall Scaleform::MemoryHeap::MemoryHeap(Scaleform::MemoryHeap *this)
{
  Scaleform::MemoryHeap *v2; // rax
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // rcx

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
  p_ChildHeaps = &this->ChildHeaps;
  if ( p_ChildHeaps )
    v2 = (Scaleform::MemoryHeap *)&p_ChildHeaps[-1].Root.8;
  p_ChildHeaps->Root.pPrev = v2;
  p_ChildHeaps->Root.pNext = v2;
  Scaleform::Lock::Lock(&this->HeapLock, 0);
  *(_WORD *)&this->UseLocks = 257;
  memset(&this->Info, 0, sizeof(this->Info));
}

// File Line: 86
// RVA: 0x95A330
void __fastcall Scaleform::MemoryHeap::AssignToCurrentThread(Scaleform::MemoryHeap *this)
{
  this->OwnerThreadId = GetCurrentThreadId();
}

