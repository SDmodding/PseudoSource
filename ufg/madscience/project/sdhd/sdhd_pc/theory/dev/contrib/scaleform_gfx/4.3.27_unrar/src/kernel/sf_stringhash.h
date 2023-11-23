// File Line: 192
// RVA: 0x8A2510
void __fastcall Scaleform::StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(
        Scaleform::StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&this->mHash);
}

// File Line: 306
// RVA: 0x8D5AB0
char __fastcall Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetCaseInsensitive(
        Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this,
        Scaleform::String *key,
        unsigned int *pvalue)
{
  bool v3; // zf
  unsigned __int64 v6; // rax
  signed __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v8; // rax
  Scaleform::String::NoCaseKey keya; // [rsp+30h] [rbp+8h] BYREF

  v3 = this->mHash.pTable == 0i64;
  keya.pStr = key;
  if ( v3 )
    return 0;
  v6 = Scaleform::String::BernsteinHashFunctionCIS(
         (const void *)((key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
         0x1505ui64);
  v7 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
         &this->mHash,
         &keya,
         v6 & this->mHash.pTable->SizeMask);
  if ( v7 < 0 )
    return 0;
  v8 = &this->mHash.pTable[2 * v7 + 2];
  if ( !v8 )
    return 0;
  if ( pvalue )
    *pvalue = v8->SizeMask;
  return 1;
}

// File Line: 334
// RVA: 0x906960
void __fastcall Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(
        Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this,
        Scaleform::String *key,
        const unsigned int *value)
{
  bool v3; // zf
  unsigned __int64 v7; // rax
  signed __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rdx
  unsigned __int64 HeapTypeBits; // rcx
  unsigned __int64 v11; // rax
  Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef v12; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::String::NoCaseKey keya; // [rsp+40h] [rbp+8h] BYREF

  v3 = this->mHash.pTable == 0i64;
  keya.pStr = key;
  if ( v3
    || (v7 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v8 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
               &this->mHash,
               &keya,
               v7 & this->mHash.pTable->SizeMask),
        v8 < 0)
    || (pTable = this->mHash.pTable) == 0i64
    || v8 > (signed __int64)pTable->SizeMask )
  {
    HeapTypeBits = key->HeapTypeBits;
    v12.pFirst = key;
    v12.pSecond = value;
    v11 = Scaleform::String::BernsteinHashFunctionCIS(
            (const void *)((HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            *(_QWORD *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
            0x1505ui64);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      &this->mHash,
      this,
      &v12,
      v11);
  }
  else
  {
    LODWORD(pTable[2 * v8 + 2].SizeMask) = *value;
  }
}

