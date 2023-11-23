// File Line: 36
// RVA: 0x896BD0
void __fastcall Scaleform::GFx::FontMap::FontMap(Scaleform::GFx::FontMap *this)
{
  Scaleform::GFx::FontMapImpl *v2; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_UserData|0x10;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontMap::`vftable;
  v2 = (Scaleform::GFx::FontMapImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        8i64);
  if ( v2 )
    v2->FontMapValue.mHash.pTable = 0i64;
  this->pImpl = v2;
}

// File Line: 40
// RVA: 0x8A4AD0
void __fastcall Scaleform::GFx::FontMap::~FontMap(Scaleform::GFx::FontMap *this)
{
  Scaleform::GFx::FontMapImpl *pImpl; // rdi

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontMap::`vftable;
  pImpl = this->pImpl;
  if ( pImpl )
  {
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&pImpl->FontMapValue.mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 45
// RVA: 0x8EB5E0
char __fastcall Scaleform::GFx::FontMap::MapFont(
        Scaleform::GFx::FontMap *this,
        const char *pfontName,
        const char *pnewFontName,
        Scaleform::GFx::FontMap::MapFontFlags mff,
        float scaleFactor)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImpl; // rdi
  unsigned __int64 v9; // rax
  signed __int64 v10; // rax
  __int64 v11; // rax
  char v12; // di
  Scaleform::GFx::FontMapImpl *v13; // rcx
  Scaleform::String src; // [rsp+20h] [rbp-58h] BYREF
  Scaleform::String::NoCaseKey key; // [rsp+28h] [rbp-50h] BYREF
  __int64 v17; // [rsp+30h] [rbp-48h]
  Scaleform::String v18; // [rsp+38h] [rbp-40h] BYREF
  float v19; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::FontMap::MapFontFlags v20; // [rsp+44h] [rbp-34h]
  Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeRef v21; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::String v22; // [rsp+80h] [rbp+8h] BYREF

  v17 = -2i64;
  if ( !this->pImpl || !pfontName )
    return 0;
  Scaleform::String::String(&v22, pfontName);
  pImpl = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)this->pImpl;
  key.pStr = &v22;
  if ( pImpl->pTable
    && (v9 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
                pImpl,
                &key,
                v9 & pImpl->pTable->SizeMask),
        v10 >= 0)
    && (v11 = (__int64)&pImpl->pTable[2] + 40 * v10) != 0
    && v11 != -8 )
  {
    v12 = 0;
  }
  else
  {
    Scaleform::String::String(&src, pnewFontName);
    Scaleform::String::String(&v18, &src);
    v19 = scaleFactor;
    v20 = mff;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v13 = this->pImpl;
    v21.pFirst = &v22;
    v21.pSecond = (Scaleform::GFx::FontMap::MapEntry *)&v18;
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &v13->FontMapValue.mHash,
      v13,
      &v21);
    v12 = 1;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v18.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v12;
}

// File Line: 82
// RVA: 0x8D84E0
char __fastcall Scaleform::GFx::FontMap::GetFontMapping(
        Scaleform::GFx::FontMap *this,
        Scaleform::GFx::FontMap::MapEntry *pentry,
        const char *pfontName)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImpl; // rbx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rbx
  __int64 v9; // rbx
  Scaleform::String v11; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::String::NoCaseKey key; // [rsp+58h] [rbp+20h] BYREF

  if ( !this->pImpl )
    return 0;
  Scaleform::String::String(&v11, pfontName);
  pImpl = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceHandle,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::ResourceHandle,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)this->pImpl;
  key.pStr = &v11;
  if ( pImpl->pTable
    && (v6 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v7 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
               pImpl,
               &key,
               v6 & pImpl->pTable->SizeMask),
        v7 >= 0)
    && (v8 = (__int64)&pImpl->pTable[2] + 40 * v7) != 0 )
  {
    v9 = v8 + 8;
  }
  else
  {
    v9 = 0i64;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !v9 )
    return 0;
  Scaleform::String::operator=(&pentry->Name, (Scaleform::String *)v9);
  pentry->ScaleFactor = *(float *)(v9 + 8);
  pentry->Flags = *(_DWORD *)(v9 + 12);
  return 1;
}

