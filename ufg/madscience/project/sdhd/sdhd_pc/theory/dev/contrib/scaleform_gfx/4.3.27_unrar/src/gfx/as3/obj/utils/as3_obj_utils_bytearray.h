// File Line: 117
// RVA: 0x8B01B0
void __fastcall Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::ASString>::Add(
        Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::ASString> *this,
        Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  __int64 v6; // rcx
  unsigned __int64 v7; // r9
  Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >::NodeRef key; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int64 v9; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v10; // [rsp+58h] [rbp+10h]

  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ArrayM.Data,
    &this->ArrayM,
    this->ArrayM.Data.Size + 1);
  v4 = &this->ArrayM.Data.Data[this->ArrayM.Data.Size - 1];
  v9 = (unsigned __int64)v4;
  v10 = v4;
  if ( v4 )
  {
    pNode = v->pNode;
    v4->pNode = v->pNode;
    ++pNode->RefCount;
  }
  v9 = this->ArrayM.Data.Size - 1;
  key.pFirst = v;
  key.pSecond = &v9;
  v6 = 8i64;
  v7 = 5381i64;
  do
    v7 = *((unsigned __int8 *)&v->pNode + --v6) + 65599 * v7;
  while ( v6 );
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeRef>(
    &this->HashM.mHash,
    this,
    &key,
    v7);
}

// File Line: 136
// RVA: 0x8CDA20
void __fastcall Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>>::ForEachChild_GC(
        Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  unsigned __int64 Size; // rbp
  unsigned __int64 v4; // rbx
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v13; // rax
  unsigned __int64 v14; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v15; // rax
  Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > *v16; // [rsp+20h] [rbp-28h]

  Size = this->ArrayM.Data.Size;
  v4 = 0i64;
  for ( i = 0i64; i < Size; ++i )
  {
    v9 = &this->ArrayM.Data.Data[i];
    if ( v9->pObject )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *))op)(
        prcc,
        v9);
  }
  pTable = this->HashM.mHash.pTable;
  if ( this->HashM.mHash.pTable )
  {
    SizeMask = pTable->SizeMask;
    v12 = pTable + 1;
    do
    {
      if ( v12->EntryCount != -2i64 )
        break;
      ++v4;
      v12 += 2;
    }
    while ( v4 <= SizeMask );
    v16 = this;
  }
  else
  {
    v16 = 0i64;
  }
  while ( v16 )
  {
    v13 = v16->HashM.mHash.pTable;
    if ( !v16->HashM.mHash.pTable || (signed __int64)v4 > (signed __int64)v13->SizeMask )
      break;
    if ( v13[2 * v4 + 2].EntryCount )
      op(prcc);
    v14 = v16->HashM.mHash.pTable->SizeMask;
    if ( (__int64)v4 <= (__int64)v14 && ++v4 <= v14 )
    {
      v15 = &v16->HashM.mHash.pTable[2 * v4 + 1];
      do
      {
        if ( v15->EntryCount != -2i64 )
          break;
        ++v4;
        v15 += 2;
      }
      while ( v4 <= v14 );
    }
  }
}

// File Line: 255
// RVA: 0x8B9730
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::CanRead(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int num)
{
  result->Result = num + this->Position <= this->Data.Data.Size;
  return result;
}

// File Line: 336
// RVA: 0x8B3220
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::AddToObjTable(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> va; // [rsp+40h] [rbp+8h] BYREF

  va.pObject = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>>::Add(&this->ObjectTable, &va);
  pObject = va.pObject;
  if ( va.pObject )
  {
    if ( ((__int64)va.pObject & 1) != 0 )
    {
      --va.pObject;
    }
    else
    {
      RefCount = va.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        va.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 340
// RVA: 0x8EBFE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ObjectListAdd(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2,Scaleform::ArrayDefaultPolicy> *p_ObjectList; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v4; // rdx
  unsigned int RefCount; // eax

  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  p_ObjectList = &this->ObjectList;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ObjectList,
    &this->ObjectList,
    this->ObjectList.Data.Size + 1);
  v4 = &p_ObjectList->Data.Data[p_ObjectList->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v;
    if ( v )
      v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v && ((unsigned __int8)v & 1) == 0 )
  {
    RefCount = v->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      v->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v);
    }
  }
}

// File Line: 344
// RVA: 0x8CC030
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::FindInObjTable(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::Object *k)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF> >::TableType *pTable; // r10
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 v6; // rax
  __int64 v7; // r9
  __int64 v8; // rdx
  __int64 v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF> >::TableType *v10; // rbx
  unsigned __int64 SizeMask; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Object *v14; // [rsp+40h] [rbp+8h]

  v14 = k;
  if ( k )
    k->RefCount = (k->RefCount + 1) & 0x8FBFFFFF;
  pTable = this->ObjectTable.HashM.mHash.pTable;
  if ( !pTable )
    goto LABEL_15;
  v4 = 8i64;
  v5 = 5381i64;
  do
  {
    --v4;
    v6 = 65599 * v5 + *((unsigned __int8 *)&v14 + v4);
    v5 = v6;
  }
  while ( v4 );
  v7 = v6 & pTable->SizeMask;
  v8 = v7;
  v9 = (__int64)&pTable[2 * v7 + 1];
  if ( *(_QWORD *)v9 == -2i64 || *(_QWORD *)(v9 + 8) != v7 )
    goto LABEL_15;
  while ( *(_QWORD *)(v9 + 8) != v7 || *(Scaleform::GFx::AS3::Object **)(v9 + 16) != k )
  {
    v8 = *(_QWORD *)v9;
    if ( *(_QWORD *)v9 == -1i64 )
      goto LABEL_15;
    v9 = (__int64)&pTable[2 * v8 + 1];
  }
  if ( v8 >= 0 && (v10 = &pTable[2 * v8 + 2]) != 0i64 )
    SizeMask = v10->SizeMask;
  else
LABEL_15:
    LODWORD(SizeMask) = -1;
  if ( k )
  {
    if ( ((unsigned __int8)k & 1) != 0 )
    {
      v14 = (Scaleform::GFx::AS3::Object *)((char *)k - 1);
    }
    else
    {
      RefCount = k->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        k->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(k);
      }
    }
  }
  return (unsigned int)SizeMask;
}

// File Line: 345
// RVA: 0x8CC140
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::FindInTraitsTable(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *k)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *pTable; // r10
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 v6; // rax
  __int64 v7; // r9
  __int64 v8; // rdx
  __int64 v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v10; // rbx
  unsigned __int64 SizeMask; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v14; // [rsp+40h] [rbp+8h]

  v14 = k;
  if ( k )
    k->RefCount = (k->RefCount + 1) & 0x8FBFFFFF;
  pTable = this->TraitsTable.HashM.mHash.pTable;
  if ( !pTable )
    goto LABEL_15;
  v4 = 8i64;
  v5 = 5381i64;
  do
  {
    --v4;
    v6 = 65599 * v5 + *((unsigned __int8 *)&v14 + v4);
    v5 = v6;
  }
  while ( v4 );
  v7 = v6 & pTable->SizeMask;
  v8 = v7;
  v9 = (__int64)&pTable[2 * v7 + 1];
  if ( *(_QWORD *)v9 == -2i64 || *(_QWORD *)(v9 + 8) != v7 )
    goto LABEL_15;
  while ( *(_QWORD *)(v9 + 8) != v7 || *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v9 + 16) != k )
  {
    v8 = *(_QWORD *)v9;
    if ( *(_QWORD *)v9 == -1i64 )
      goto LABEL_15;
    v9 = (__int64)&pTable[2 * v8 + 1];
  }
  if ( v8 >= 0 && (v10 = &pTable[2 * v8 + 2]) != 0i64 )
    SizeMask = v10->SizeMask;
  else
LABEL_15:
    LODWORD(SizeMask) = -1;
  if ( k )
  {
    if ( ((unsigned __int8)k & 1) != 0 )
    {
      v14 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)k - 1);
    }
    else
    {
      RefCount = k->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        k->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(k);
      }
    }
  }
  return (unsigned int)SizeMask;
}

// File Line: 485
// RVA: 0x851820
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this,
        unsigned int value)
{
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(this, &v, value);
}

// File Line: 698
// RVA: 0x7FB080
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *t)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)t->pVM->MHeap->vfptr->Alloc(
                                                                t->pVM->MHeap,
                                                                t->MemSize,
                                                                &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ByteArray(v4, t);
  result->pV = v4;
  return result;
}

