// File Line: 253
// RVA: 0x8A50B0
void __fastcall Scaleform::MemoryHeap::LimitHandler::~LimitHandler(Scaleform::MemoryHeap::LimitHandler *this)
{
  this->vfptr = (Scaleform::MemoryHeap::LimitHandlerVtbl *)&Scaleform::MemoryHeap::LimitHandler::`vftable';
}

// File Line: 301
// RVA: 0x94B4C0
void __fastcall Scaleform::MemoryHeap::~MemoryHeap(Scaleform::MemoryHeap *this)
{
  this->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::MemoryHeap::`vftable';
  DeleteCriticalSection(&this->HeapLock.cs);
}

