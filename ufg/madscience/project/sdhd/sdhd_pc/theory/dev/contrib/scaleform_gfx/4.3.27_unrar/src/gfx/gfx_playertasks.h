// File Line: 95
// RVA: 0x6C9ED0
void __fastcall Scaleform::GFx::LoadQueueEntry::LoadQueueEntry(
        Scaleform::GFx::LoadQueueEntry *this,
        Scaleform::String *url,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method,
        bool loadingVars,
        bool quietOpen)
{
  Scaleform::GFx::LoadQueueEntry::LoadType v9; // ecx

  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  Scaleform::String::String(&this->URL);
  if ( loadingVars )
    v9 = LT_LoadText;
  else
    v9 = (url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) == -12i64;
  this->Type = v9;
  this->Method = method;
  this->pNext = 0i64;
  Scaleform::String::operator=(&this->URL, url);
  this->EntryTime = -1;
  *(_WORD *)&this->QuietOpen = quietOpen;
}

// File Line: 109
// RVA: 0x6D1DB0
void __fastcall Scaleform::GFx::LoadQueueEntry::~LoadQueueEntry(Scaleform::GFx::LoadQueueEntry *this)
{
  this->vfptr = (Scaleform::GFx::LoadQueueEntryVtbl *)&Scaleform::GFx::LoadQueueEntry::`vftable;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->URL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

