// File Line: 164
// RVA: 0x6D1B20
void __fastcall Scaleform::String::InitStruct::~InitStruct(Scaleform::String::InitStruct *this)
{
  this->vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
}

// File Line: 182
// RVA: 0x6D25E0
void __fastcall Scaleform::String::~String(Scaleform::String *this)
{
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

