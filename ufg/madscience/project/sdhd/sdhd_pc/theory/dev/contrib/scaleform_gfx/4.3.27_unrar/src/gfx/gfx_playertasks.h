// File Line: 95
// RVA: 0x6C9ED0
void __fastcall Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(Scaleform::GFx::LoadQueueEntry *this, Scaleform::String *url, Scaleform::GFx::LoadQueueEntry::LoadMethod method, bool loadingVars, bool quietOpen)
{
  bool v5; // bl
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // er14
  Scaleform::String *v7; // rsi
  Scaleform::GFx::LoadQueueEntry *v8; // rdi
  signed int v9; // ecx

  v5 = loadingVars;
  v6 = method;
  v7 = url;
  v8 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&this->URL);
  if ( v5 )
    v9 = 4;
  else
    v9 = (v7->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  v8->Type = v9;
  v8->Method = v6;
  v8->pNext = 0i64;
  Scaleform::String::operator=(&v8->URL, v7);
  v8->EntryTime = -1;
  *(_WORD *)&v8->QuietOpen = quietOpen;
}

// File Line: 109
// RVA: 0x6D1DB0
void __fastcall Scaleform::GFx::LoadQueueEntry::~LoadQueueEntry(Scaleform::GFx::LoadQueueEntry *this)
{
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

