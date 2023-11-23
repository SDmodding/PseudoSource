// File Line: 32
// RVA: 0x945520
void __fastcall Scaleform::SysAllocPagedMalloc::SysAllocPagedMalloc(
        Scaleform::SysAllocPagedMalloc *this,
        unsigned __int64 granularity)
{
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::`vftable;
  this->pContainer = 0i64;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPagedMalloc::`vftable;
  this->Granularity = (granularity + 0xFFFF) & 0xFFFFFFFFFFFF0000ui64;
  this->Footprint = 0i64;
  this->Base = -1i64;
}

// File Line: 38
// RVA: 0x987590
void __fastcall Scaleform::SysAllocPagedMalloc::GetInfo(
        Scaleform::SysAllocPagedMalloc *this,
        Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 Granularity; // rax

  i->MinAlign = 1i64;
  i->MaxAlign = 1i64;
  Granularity = this->Granularity;
  i->SysDirectThreshold = 0x8000i64;
  i->MaxHeapGranularity = 0x2000i64;
  i->HasRealloc = 0;
  i->Granularity = Granularity;
}

// File Line: 49
// RVA: 0x956DD0
void *__fastcall Scaleform::SysAllocPagedMalloc::Alloc(
        Scaleform::SysAllocPagedMalloc *this,
        unsigned __int64 size,
        unsigned __int64 __formal)
{
  void *result; // rax

  result = malloc(size);
  if ( result )
  {
    this->Footprint += size;
    if ( (unsigned __int64)result < this->Base )
      this->Base = (unsigned __int64)result;
  }
  return result;
}

// File Line: 71
// RVA: 0x97E040
char __fastcall Scaleform::SysAllocPagedMalloc::Free(
        Scaleform::SysAllocPagedMalloc *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 __formal)
{
  free(ptr);
  this->Footprint -= size;
  return 1;
}

