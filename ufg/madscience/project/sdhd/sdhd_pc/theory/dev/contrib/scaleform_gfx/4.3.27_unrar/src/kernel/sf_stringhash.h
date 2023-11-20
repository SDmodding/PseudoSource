// File Line: 192
// RVA: 0x8A2510
void __fastcall Scaleform::StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(Scaleform::StringHashLH<Scaleform::GFx::FontMap::MapEntry,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this)
{
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontMap::MapEntry,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::FontMap::MapEntry,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&this->mHash.pTable);
}

// File Line: 306
// RVA: 0x8D5AB0
char __fastcall Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetCaseInsensitive(Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this, Scaleform::String *key, unsigned int *pvalue)
{
  bool v3; // zf
  unsigned int *v4; // rdi
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v5; // rbx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  Scaleform::String::NoCaseKey keya; // [rsp+30h] [rbp+8h]

  v3 = this->mHash.pTable == 0i64;
  v4 = pvalue;
  v5 = this;
  keya.pStr = key;
  if ( v3 )
    return 0;
  v6 = Scaleform::String::BernsteinHashFunctionCIS(
         (const void *)((key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
         0x1505ui64);
  v7 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
         (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v5->mHash.pTable,
         &keya,
         v6 & v5->mHash.pTable->SizeMask);
  if ( v7 < 0 )
    return 0;
  v8 = (signed __int64)&v5->mHash.pTable[2 * (v7 + 1)];
  if ( !v8 )
    return 0;
  if ( v4 )
    *v4 = *(_DWORD *)(v8 + 8);
  return 1;
}

// File Line: 334
// RVA: 0x906960
void __fastcall Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::SetCaseInsensitive(Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *this, Scaleform::String *key, const unsigned int *value)
{
  bool v3; // zf
  const unsigned int *v4; // rsi
  Scaleform::String *v5; // rdi
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v6; // rbx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > v9; // rdx
  Scaleform::String v10; // rcx
  unsigned __int64 v11; // rax
  Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef v12; // [rsp+20h] [rbp-18h]
  Scaleform::String::NoCaseKey keya; // [rsp+40h] [rbp+8h]

  v3 = this->mHash.pTable == 0i64;
  v4 = value;
  v5 = key;
  v6 = this;
  keya.pStr = key;
  if ( v3
    || (v7 = Scaleform::String::BernsteinHashFunctionCIS(
               (const void *)((key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
               *(_QWORD *)(key->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
               0x1505ui64),
        v8 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::String::NoCaseKey>(
               (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v6->mHash.pTable,
               &keya,
               v7 & v6->mHash.pTable->SizeMask),
        v8 < 0)
    || (v9.pTable = v6->mHash.pTable) == 0i64
    || v8 > (signed __int64)v9.pTable->SizeMask )
  {
    v10.pData = (Scaleform::String::DataDesc *)v5->HeapTypeBits;
    v12.pFirst = v5;
    v12.pSecond = v4;
    v11 = Scaleform::String::BernsteinHashFunctionCIS(
            (const void *)((v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            *(_QWORD *)(v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
            0x1505ui64);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v6->mHash.pTable,
      v6,
      &v12,
      v11);
  }
  else
  {
    LODWORD(v9.pTable[2 * v8 + 2].SizeMask) = *v4;
  }
}

