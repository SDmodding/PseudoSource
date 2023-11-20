// File Line: 117
// RVA: 0x8B01B0
void __fastcall Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::ASString>::Add(Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::ASString> *this, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::ASString> *v3; // rsi
  Scaleform::GFx::ASString *v4; // rcx
  Scaleform::GFx::ASString v5; // rax
  signed __int64 v6; // rcx
  unsigned __int64 v7; // r9
  Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >::NodeRef key; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::ASString *v9; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString *v10; // [rsp+58h] [rbp+10h]

  v2 = v;
  v3 = this;
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::ArrayDefaultPolicy> *)&this->ArrayM.Data.Data,
    &this->ArrayM,
    this->ArrayM.Data.Size + 1);
  v4 = &v3->ArrayM.Data.Data[v3->ArrayM.Data.Size - 1];
  v9 = v4;
  v10 = v4;
  if ( v4 )
  {
    v5.pNode = v2->pNode;
    v4->pNode = v2->pNode;
    ++v5.pNode->RefCount;
  }
  v9 = (Scaleform::GFx::ASString *)(v3->ArrayM.Data.Size - 1);
  key.pFirst = v2;
  key.pSecond = (const unsigned __int64 *)&v9;
  v6 = 8i64;
  v7 = 5381i64;
  do
    v7 = *((unsigned __int8 *)&v2->pNode + --v6) + 65599 * v7;
  while ( v6 );
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >,Scaleform::HashNode<Scaleform::GFx::ASString,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> >::NodeHashF> > *)&v3->HashM.mHash.pTable,
    v3,
    &key,
    v7);
}

// File Line: 136
// RVA: 0x8CDA20
void __fastcall Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>>::ForEachChild_GC(Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rbx
  void (__fastcall *v5)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // r14
  Scaleform::GFx::AS3::RefCountCollector<328> *v6; // r15
  Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > *v7; // rsi
  unsigned __int64 v8; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> *v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v10; // rax
  unsigned __int64 v11; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v12; // rax
  __int64 v13; // rbx
  __int64 v14; // rdi
  __int64 v15; // rax
  unsigned __int64 v16; // rcx
  _QWORD *v17; // rax
  __m128i v18; // [rsp+20h] [rbp-28h]

  v3 = this->ArrayM.Data.Size;
  v4 = 0i64;
  v5 = op;
  v6 = prcc;
  v7 = this;
  v8 = 0i64;
  if ( v3 )
  {
    do
    {
      v9 = &v7->ArrayM.Data.Data[v8];
      if ( v9->pObject )
        v5(v6, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v9);
      ++v8;
    }
    while ( v8 < v3 );
  }
  v10 = v7->HashM.mHash.pTable;
  if ( v7->HashM.mHash.pTable )
  {
    v11 = v10->SizeMask;
    v12 = v10 + 1;
    do
    {
      if ( v12->EntryCount != -2i64 )
        break;
      ++v4;
      v12 += 2;
    }
    while ( v4 <= v11 );
    v18.m128i_i64[0] = (__int64)v7;
  }
  else
  {
    v18.m128i_i64[0] = 0i64;
  }
  v18.m128i_i64[1] = v4;
  _mm_store_si128(&v18, v18);
  v13 = v18.m128i_i64[1];
  v14 = v18.m128i_i64[0];
  while ( v14 )
  {
    v15 = *(_QWORD *)v14;
    if ( !*(_QWORD *)v14 || v13 > *(_QWORD *)(v15 + 8) )
      break;
    if ( *(_QWORD *)(v15 + 32 * (v13 + 1)) )
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v5)(v6);
    v16 = *(_QWORD *)(*(_QWORD *)v14 + 8i64);
    if ( v13 <= (signed __int64)v16 && ++v13 <= v16 )
    {
      v17 = (_QWORD *)(*(_QWORD *)v14 + 32 * v13 + 16);
      do
      {
        if ( *v17 != -2i64 )
          break;
        ++v13;
        v17 += 4;
      }
      while ( v13 <= v16 );
    }
  }
}

// File Line: 255
// RVA: 0x8B9730
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::CanRead(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int num)
{
  result->Result = num + this->Position <= this->Data.Data.Size;
  return result;
}

// File Line: 336
// RVA: 0x8B3220
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::AddToObjTable(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Object *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> va; // [rsp+40h] [rbp+8h]

  va.pObject = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::ArrayHashLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>>::Add(&this->ObjectTable, &va);
  v2 = va.pObject;
  if ( va.pObject )
  {
    if ( (_QWORD)va.pObject & 1 )
    {
      --va.pObject;
    }
    else
    {
      v3 = va.pObject->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        va.pObject->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
}

// File Line: 340
// RVA: 0x8EBFE0
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ObjectListAdd(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Object *v2; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *v4; // rdx
  unsigned int v5; // eax

  v2 = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
  v3 = &this->ObjectList;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ObjectList,
    &this->ObjectList,
    this->ObjectList.Data.Size + 1);
  v4 = &v3->Data.Data[v3->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v2 && !((unsigned __int8)v2 & 1) )
  {
    v5 = v2->RefCount;
    if ( v5 & 0x3FFFFF )
    {
      v2->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
    }
  }
}

// File Line: 344
// RVA: 0x8CC030
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::FindInObjTable(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, Scaleform::GFx::AS3::Object *k)
{
  Scaleform::GFx::AS3::Object *v2; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF> >::TableType *v3; // r10
  signed __int64 v4; // rdx
  signed __int64 v5; // rcx
  signed __int64 v6; // rax
  unsigned __int64 v7; // r9
  signed __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> > >::NodeHashF> >::TableType *v9; // rcx
  signed __int64 v10; // rbx
  __int64 v11; // rbx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Object *v14; // [rsp+40h] [rbp+8h]

  v2 = k;
  v14 = k;
  if ( k )
    k->RefCount = (k->RefCount + 1) & 0x8FBFFFFF;
  v3 = this->ObjectTable.HashM.mHash.pTable;
  if ( !v3 )
    goto LABEL_15;
  v4 = 8i64;
  v5 = 5381i64;
  do
  {
    v6 = 65599 * v5 + *((unsigned __int8 *)&v14 + --v4);
    v5 = 65599 * v5 + *((unsigned __int8 *)&v14 + v4);
  }
  while ( v4 );
  v7 = v6 & v3->SizeMask;
  v8 = v6 & v3->SizeMask;
  v9 = &v3[2 * (v6 & v3->SizeMask) + 1];
  if ( v9->EntryCount == -2i64 || v9->SizeMask != v7 )
    goto LABEL_15;
  while ( v9->SizeMask != v7 || (Scaleform::GFx::AS3::Object *)v9[1].EntryCount != v2 )
  {
    v8 = v9->EntryCount;
    if ( v9->EntryCount == -1i64 )
      goto LABEL_15;
    v9 = &v3[2 * v8 + 1];
  }
  if ( v8 >= 0 && (v10 = (signed __int64)&v3[2 * (v8 + 1)]) != 0 )
    v11 = *(_QWORD *)(v10 + 8);
  else
LABEL_15:
    LODWORD(v11) = -1;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v14 = (Scaleform::GFx::AS3::Object *)((char *)v2 - 1);
    }
    else
    {
      v12 = v2->RefCount;
      if ( v12 & 0x3FFFFF )
      {
        v2->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  return (unsigned int)v11;
}

// File Line: 345
// RVA: 0x8CC140
__int64 __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::FindInTraitsTable(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, Scaleform::GFx::AS3::InstanceTraits::Traits *k)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v3; // r10
  signed __int64 v4; // rdx
  signed __int64 v5; // rcx
  signed __int64 v6; // rax
  unsigned __int64 v7; // r9
  signed __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >,Scaleform::HashNode<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits>,unsigned __int64,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Traits> > >::NodeHashF> >::TableType *v9; // rcx
  signed __int64 v10; // rbx
  __int64 v11; // rbx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v14; // [rsp+40h] [rbp+8h]

  v2 = k;
  v14 = k;
  if ( k )
    k->RefCount = (k->RefCount + 1) & 0x8FBFFFFF;
  v3 = this->TraitsTable.HashM.mHash.pTable;
  if ( !v3 )
    goto LABEL_15;
  v4 = 8i64;
  v5 = 5381i64;
  do
  {
    v6 = 65599 * v5 + *((unsigned __int8 *)&v14 + --v4);
    v5 = 65599 * v5 + *((unsigned __int8 *)&v14 + v4);
  }
  while ( v4 );
  v7 = v6 & v3->SizeMask;
  v8 = v6 & v3->SizeMask;
  v9 = &v3[2 * (v6 & v3->SizeMask) + 1];
  if ( v9->EntryCount == -2i64 || v9->SizeMask != v7 )
    goto LABEL_15;
  while ( v9->SizeMask != v7 || (Scaleform::GFx::AS3::InstanceTraits::Traits *)v9[1].EntryCount != v2 )
  {
    v8 = v9->EntryCount;
    if ( v9->EntryCount == -1i64 )
      goto LABEL_15;
    v9 = &v3[2 * v8 + 1];
  }
  if ( v8 >= 0 && (v10 = (signed __int64)&v3[2 * (v8 + 1)]) != 0 )
    v11 = *(_QWORD *)(v10 + 8);
  else
LABEL_15:
    LODWORD(v11) = -1;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v14 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v2 - 1);
    }
    else
    {
      v12 = v2->RefCount;
      if ( v12 & 0x3FFFFF )
      {
        v2->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  return (unsigned int)v11;
}

// File Line: 485
// RVA: 0x851820
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *this, unsigned int value)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v3; // rdi

  v2 = value;
  v3 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(v3, &v, v2);
}

// File Line: 698
// RVA: 0x7FB080
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *result, Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)t->pVM->MHeap->vfptr->Alloc(
                                                                t->pVM->MHeap,
                                                                t->MemSize,
                                                                (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::ByteArray(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

