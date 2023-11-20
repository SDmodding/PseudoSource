// File Line: 89
// RVA: 0xA107F0
unsigned __int64 __fastcall Scaleform::SysMemMapperWinAPI::GetPageSize(Scaleform::SysMemMapperWinAPI *this)
{
  _SYSTEM_INFO SystemInfo; // [rsp+20h] [rbp-38h]

  GetSystemInfo(&SystemInfo);
  return SystemInfo.dwPageSize;
}

// File Line: 101
// RVA: 0xA10870
LPVOID __fastcall Scaleform::SysMemMapperWinAPI::ReserveAddrSpace(Scaleform::SysMemMapperWinAPI *this, unsigned __int64 size)
{
  return VirtualAlloc(0i64, size, 0x2000u, 4u);
}

// File Line: 107
// RVA: 0xA10850
bool __fastcall Scaleform::SysMemMapperWinAPI::ReleaseAddrSpace(Scaleform::SysMemMapperWinAPI *this, void *ptr, unsigned __int64 __formal)
{
  return VirtualFree(ptr, 0i64, 0x8000u) != 0;
}

// File Line: 113
// RVA: 0xA10820
LPVOID __fastcall Scaleform::SysMemMapperWinAPI::MapPages(Scaleform::SysMemMapperWinAPI *this, void *ptr, unsigned __int64 size)
{
  return VirtualAlloc(ptr, size, 0x1000u, 4u);
}

// File Line: 119
// RVA: 0xA10890
bool __fastcall Scaleform::SysMemMapperWinAPI::UnmapPages(Scaleform::SysMemMapperWinAPI *this, void *ptr, unsigned __int64 size)
{
  return VirtualFree(ptr, size, 0x4000u) != 0;
}

// File Line: 127
// RVA: 0xA10580
void __fastcall Scaleform::SysAllocWinAPI::SysAllocWinAPI(Scaleform::SysAllocWinAPI *this, unsigned __int64 granularity, unsigned __int64 segSize)
{
  unsigned __int64 v3; // r9
  Scaleform::SysAllocWinAPI *v4; // rbx
  Scaleform::SysAllocMapper *v5; // rax
  Scaleform::SysMemMapper *v6; // rdx
  Scaleform::SysAllocMapper *v7; // rcx

  v3 = granularity;
  v4 = this;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable';
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged>::`vftable';
  v5 = 0i64;
  this->pContainer = 0i64;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocWinAPI::`vftable';
  v6 = (Scaleform::SysMemMapper *)&this->Mapper.vfptr;
  v6->vfptr = (Scaleform::SysMemMapperVtbl *)&Scaleform::SysMemMapper::`vftable';
  v6->vfptr = (Scaleform::SysMemMapperVtbl *)&Scaleform::SysMemMapperWinAPI::`vftable';
  v7 = (Scaleform::SysAllocMapper *)this->PrivateData;
  if ( v4 != (Scaleform::SysAllocWinAPI *)-32i64 )
    Scaleform::SysAllocMapper::SysAllocMapper(v7, v6, segSize, v3, 1);
  v4->pAllocator = v5;
}

// File Line: 148
// RVA: 0xA107E0
void __fastcall Scaleform::SysAllocWinAPI::GetInfo(Scaleform::SysAllocWinAPI *this, Scaleform::SysAllocPaged::Info *i)
{
  this->pAllocator->vfptr[1].__vecDelDtor((Scaleform::SysAllocBase *)this->pAllocator, (unsigned int)i);
}

// File Line: 154
// RVA: 0xA10780
__int64 __fastcall Scaleform::SysAllocWinAPI::Alloc(Scaleform::SysAllocWinAPI *this, unsigned __int64 size, unsigned __int64 align)
{
  return ((__int64 (__fastcall *)(Scaleform::SysAllocMapper *, unsigned __int64, unsigned __int64))this->pAllocator->vfptr[1].initHeapEngine)(
           this->pAllocator,
           size,
           align);
}

// File Line: 166
// RVA: 0xA10840
void __fastcall hkpMapPointsToSubShapeContactMgr::processContactImpl(hkpMapPointsToSubShapeContactMgr *this, hkpCollidable *a, hkpCollidable *b, hkpProcessCollisionInput *input, hkpProcessCollisionData *collisionData)
{
  ((void (__fastcall *)(hkpContactMgr *, hkpCollidable *, hkpCollidable *, hkpProcessCollisionInput *))this->m_contactMgr->vfptr[3].__vecDelDtor)(
    this->m_contactMgr,
    a,
    b,
    input);
}

// File Line: 193
// RVA: 0xA107D0
void __fastcall Scaleform::SysAllocWinAPI::GetFootprint(Scaleform::GFx::MovieImpl *this, __int64 suspend)
{
  this->pASMovieRoot.pObject->vfptr[11].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, suspend);
}

// File Line: 199
// RVA: 0xA10810
void __fastcall Scaleform::GFx::MovieImpl::ScheduleGC(Scaleform::GFx::MovieImpl *this, __int64 gcFlags)
{
  this->pASMovieRoot.pObject->vfptr[12].__vecDelDtor((Scaleform::RefCountImplCore *)this->pASMovieRoot.pObject, gcFlags);
}

// File Line: 205
// RVA: 0xA107A0
char *__fastcall Scaleform::SysAllocWinAPI::GetBitSet(Scaleform::SysAllocWinAPI *this, unsigned __int64 seg)
{
  Scaleform::SysAllocMapper *v2; // r8
  char *result; // rax

  v2 = this->pAllocator;
  if ( seg < v2->NumSegments )
    result = &v2->Segments[seg].Memory[v2->SegmSize - v2->PageSize];
  else
    result = 0i64;
  return result;
}

// File Line: 210
// RVA: 0xA10790
void __fastcall hkpMapPointsToSubShapeContactMgr::cleanup(hkpMapPointsToSubShapeContactMgr *this)
{
  ((void (*)(void))this->m_contactMgr->vfptr[4].__first_virtual_table_function__)();
}

