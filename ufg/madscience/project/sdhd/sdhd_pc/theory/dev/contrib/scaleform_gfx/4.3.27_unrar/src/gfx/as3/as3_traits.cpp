// File Line: 59
// RVA: 0x7D7200
void __fastcall Scaleform::GFx::AS3::Slots::ForEachSlot(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::Slots::SlotFunct *f)
{
  unsigned __int64 v2; // r9
  Scaleform::GFx::AS3::AbsoluteIndex v3; // rbx
  Scaleform::GFx::AS3::Slots::SlotFunct *v4; // rsi
  Scaleform::GFx::AS3::Slots *v5; // rdi
  Scaleform::GFx::AS3::SlotInfo *v6; // rax

  v2 = this->FirstOwnSlotNum;
  v3.Index = 0i64;
  v4 = f;
  v5 = this;
  if ( this->FirstOwnSlotNum + this->VArray.Data.Size )
  {
    do
    {
      if ( v3.Index < 0 || v3.Index < v2 )
        v6 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v5->Parent, v3);
      else
        v6 = &v5->VArray.Data.Data[LODWORD(v3.Index) - v2].Value;
      v4->vfptr->operator()(v4, v6);
      if ( v3.Index < 0 || v3.Index < v5->FirstOwnSlotNum + v5->VArray.Data.Size )
        ++v3.Index;
      v2 = v5->FirstOwnSlotNum;
    }
    while ( LODWORD(v3.Index) < v5->FirstOwnSlotNum + v5->VArray.Data.Size );
  }
}

// File Line: 77
// RVA: 0x819CB0
void __fastcall Scaleform::GFx::AS3::Slots::SetKey(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::ASString *k)
{
  Scaleform::GFx::AS3::Slots *v3; // r14
  unsigned __int64 v4; // r12
  Scaleform::GFx::ASStringNode *v5; // rbx
  unsigned __int64 v6; // rbp
  Scaleform::GFx::AS3::Slots::Pair *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v10; // r8
  unsigned __int64 v11; // r10
  __int64 v12; // r9
  signed __int64 v13; // rdi
  unsigned __int64 *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *v16; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v20; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v21; // [rsp+80h] [rbp+18h]

  v3 = this;
  v4 = LODWORD(ind.Index) - this->FirstOwnSlotNum;
  v5 = k->pNode;
  v6 = v4 << 6;
  v7 = this->VArray.Data.Data;
  if ( v7[v4].Key.pObject != k->pNode )
  {
    if ( v5 )
      ++v5->RefCount;
    v8 = *(Scaleform::GFx::ASStringNode **)((char *)&v7->Key.pObject + v6);
    if ( v8 )
    {
      v9 = v8->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    }
    *(Scaleform::GFx::ASStringNode **)((char *)&v7->Key.pObject + v6) = v5;
    if ( v5 )
      ++v5->RefCount;
    v20 = v5;
    v10 = v3->Set.mHash.pTable;
    if ( !v10 )
      goto LABEL_18;
    v11 = v10->SizeMask;
    v12 = (unsigned int)v11 & v5->HashFlags;
    v13 = v12;
    v14 = &v10->EntryCount + v12 + 2 * (v12 + 1);
    if ( *v14 == -2i64 || ((unsigned int)v11 & *(_DWORD *)(v14[1] + 28)) != v12 )
      goto LABEL_18;
    while ( 1 )
    {
      v15 = (Scaleform::GFx::ASStringNode *)v14[1];
      if ( ((unsigned int)v11 & v15->HashFlags) == v12 && v15 == v5 )
        break;
      v13 = *v14;
      if ( *v14 == -1i64 )
        goto LABEL_18;
      v14 = &v10->EntryCount + v13 + 2 * (v13 + 1);
    }
    if ( v13 >= 0 )
    {
      v16 = &v3->Set;
    }
    else
    {
LABEL_18:
      v16 = 0i64;
      v13 = 0i64;
    }
    if ( v5 )
    {
      v9 = v5->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    }
    if ( v16 && (v17 = v16->mHash.pTable) != 0i64 && v13 <= (signed __int64)v17->SizeMask )
    {
      *(__int64 *)((char *)&v3->VArray.Data.Data->Prev + v6) = *((unsigned int *)&v17[2].EntryCount + 6 * v13);
      *((_DWORD *)&v16->mHash.pTable[2].EntryCount + 6 * v13) = v4 + LODWORD(v3->FirstOwnSlotNum);
    }
    else
    {
      LODWORD(v20) = v4 + LODWORD(v3->FirstOwnSlotNum);
      if ( v5 )
        ++v5->RefCount;
      v21 = v5;
      key.pFirst = (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&v21;
      key.pSecond = (const unsigned int *)&v20;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&v3->Set.mHash.pTable,
        &v3->Set,
        &key,
        v5->HashFlags);
      v18 = v21;
      if ( v21 )
      {
        v9 = v21->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      *(__int64 *)((char *)&v3->VArray.Data.Data->Prev + v6) = -1i64;
    }
  }
}

// File Line: 107
// RVA: 0x7AAF40
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Slots::Add(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::AbsoluteIndex *result, Scaleform::GFx::ASString *k, Scaleform::GFx::AS3::SlotInfo *v)
{
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::AS3::AbsoluteIndex *v5; // r12
  Scaleform::GFx::AS3::Slots *v6; // r14
  unsigned __int64 v7; // r15
  Scaleform::GFx::ASStringNode *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v12; // r8
  unsigned __int64 v13; // r10
  __int64 v14; // r9
  signed __int64 v15; // rdi
  unsigned __int64 *v16; // rdx
  Scaleform::GFx::ASStringNode *v17; // rcx
  signed __int64 v18; // rsi
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [rsp+28h] [rbp-90h]
  Scaleform::GFx::AS3::Slots::Pair val; // [rsp+38h] [rbp-80h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+C0h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v24; // [rsp+C8h] [rbp+10h]

  v4 = k;
  v5 = result;
  v6 = this;
  v7 = this->VArray.Data.Size;
  v8 = k->pNode;
  if ( k->pNode )
    ++v8->RefCount;
  v23 = v8;
  if ( v8 )
    ++v8->RefCount;
  val.Key.pObject = v8;
  val.Prev = -1i64;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(&val.Value, v);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &v6->VArray.Data,
    &val);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&val.Value);
  v9 = val.Key.pObject;
  if ( val.Key.pObject )
  {
    v10 = val.Key.pObject->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  if ( v8 )
  {
    v10 = v8->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v11 = v4->pNode;
  if ( v4->pNode )
    ++v11->RefCount;
  v23 = v11;
  v12 = v6->Set.mHash.pTable;
  if ( !v12 )
    goto LABEL_22;
  v13 = v12->SizeMask;
  v14 = (unsigned int)v13 & v11->HashFlags;
  v15 = v14;
  v16 = &v12->EntryCount + v14 + 2 * (v14 + 1);
  if ( *v16 == -2i64 || ((unsigned int)v13 & *(_DWORD *)(v16[1] + 28)) != v14 )
    goto LABEL_22;
  while ( 1 )
  {
    v17 = (Scaleform::GFx::ASStringNode *)v16[1];
    if ( ((unsigned int)v13 & v17->HashFlags) == v14 && v17 == v11 )
      break;
    v15 = *v16;
    if ( *v16 == -1i64 )
      goto LABEL_22;
    v16 = &v12->EntryCount + v15 + 2 * (v15 + 1);
  }
  if ( v15 >= 0 )
  {
    v18 = (signed __int64)&v6->Set;
  }
  else
  {
LABEL_22:
    v18 = 0i64;
    v15 = 0i64;
  }
  if ( v11 )
  {
    v10 = v11->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( v18 && *(_QWORD *)v18 && v15 <= *(_QWORD *)(*(_QWORD *)v18 + 8i64) )
  {
    v6->VArray.Data.Data[v7].Prev = *(unsigned int *)(24 * v15 + *(_QWORD *)v18 + 32);
    *(_DWORD *)(24 * v15 + *(_QWORD *)v18 + 32) = v7 + LODWORD(v6->FirstOwnSlotNum);
  }
  else
  {
    LODWORD(v23) = v7 + LODWORD(v6->FirstOwnSlotNum);
    if ( v11 )
      ++v11->RefCount;
    v24 = v11;
    key.pFirst = (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&v24;
    key.pSecond = (const unsigned int *)&v23;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&v6->Set.mHash.pTable,
      &v6->Set,
      &key,
      v11->HashFlags);
    v19 = v24;
    if ( v24 )
    {
      v10 = v24->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    }
    v6->VArray.Data.Data[v7].Prev = -1i64;
  }
  v5->Index = v7 + v6->FirstOwnSlotNum;
  return v5;
}

// File Line: 133
// RVA: 0x7D4060
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::AbsoluteIndex *result, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::AbsoluteIndex *v4; // r14
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rbp
  Scaleform::GFx::AS3::Slots *v6; // rdi
  const unsigned int *v7; // rax
  unsigned __int64 v8; // rbx
  __int64 v9; // rsi
  Scaleform::GFx::AS3::SlotInfo *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rdx
  bool v12; // zf

  v4 = result;
  v5 = ns;
  v6 = this;
  v7 = Scaleform::GFx::AS3::Slots::FindSlotValues(this, name);
  if ( v7 )
  {
    v8 = *v7;
    v9 = *((_QWORD *)v5 + 5) << 60 >> 60;
    while ( 1 )
    {
      v10 = v8 < v6->FirstOwnSlotNum ? Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                         v6->Parent,
                                         (Scaleform::GFx::AS3::AbsoluteIndex)v8) : &v6->VArray.Data.Data[(unsigned int)v8 - v6->FirstOwnSlotNum].Value;
      v11 = v10->pNs.pObject;
      if ( (unsigned int)(*((_QWORD *)v11 + 5) << 60 >> 60) == (_DWORD)v9 )
      {
        if ( (_DWORD)v9 == 1 )
          break;
        v12 = (_DWORD)v9 == 3 ? v5 == v11 : v11->Uri.pNode == v5->Uri.pNode;
        if ( v12 )
          break;
      }
      if ( v8 >= v6->FirstOwnSlotNum )
        v8 = v6->VArray.Data.Data[v8 - v6->FirstOwnSlotNum].Prev;
      else
        v8 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v6->Parent, v8);
      if ( (v8 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_16;
    }
    v4->Index = v8;
  }
  else
  {
LABEL_16:
    v4->Index = -1i64;
  }
  return v4;
}

// File Line: 189
// RVA: 0x783480
void __fastcall Scaleform::GFx::AS3::Traits::Traits(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::VM *_vm, Scaleform::GFx::AS3::Traits *pt, bool isDynamic, bool isFinal)
{
  Scaleform::GFx::AS3::Traits *v5; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v6; // rax
  Scaleform::GFx::AS3::Slots *v7; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Slots::Pair,332,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::GFx::AS3::BuiltinTraitsType v9; // eax
  Scaleform::MemoryHeap *v10; // rcx
  unsigned __int8 v11; // al
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *v12; // rax
  signed __int64 v13; // [rsp+48h] [rbp+10h]

  v5 = this;
  v6 = _vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v6;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable';
  v7 = (Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum;
  v7->FirstOwnSlotNum = 0i64;
  v7->Parent = 0i64;
  v8 = &this->VArray;
  v8->Data.Data = 0i64;
  v8->Data.Size = 0i64;
  v8->Data.Policy.Capacity = 0i64;
  this->Set.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  this->FirstOwnSlotInd.Index = 0i64;
  this->FixedValueSlotNumber = 0i64;
  this->MemSize = 0;
  this->Flags = 0i64;
  if ( pt )
    v9 = pt->TraitsType;
  else
    v9 = 0;
  this->TraitsType = v9;
  this->pVM = _vm;
  this->pConstructor.pObject = 0i64;
  this->pParent.pObject = pt;
  if ( pt )
    pt->RefCount = (pt->RefCount + 1) & 0x8FBFFFFF;
  this->pVTable.pObject = 0i64;
  this->pVTable.Owner = 1;
  v10 = _vm->MHeap;
  v13 = (signed __int64)&v5->InitScope;
  *(_OWORD *)v13 = 0ui64;
  *(_QWORD *)(v13 + 16) = 0i64;
  v5->InitScope.Data.pHeap = v10;
  if ( pt )
    v11 = pt->Flags & 1;
  else
    v11 = 0;
  v5->Flags &= 0xFFFFFFFFFFFFFFBCui64;
  v5->Flags |= (isDynamic ? 2 : 0) | (isFinal ? 0x40 : 0) | (unsigned __int64)(-v11 & 1);
  v5->RefCount |= 0x8000000u;
  v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)v5->pParent.pObject;
  if ( v12 )
  {
    v5->Parent = (Scaleform::GFx::AS3::Slots *)&v12[5];
    v7->FirstOwnSlotNum = (unsigned __int64)v12[5].pTable + (unsigned __int64)v12[8].pTable;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Assign(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&v5->Set.mHash.pTable,
      &v5->Set,
      v12 + 10);
    v5->FirstOwnSlotInd.Index = v5->VArray.Data.Size + v5->FirstOwnSlotNum;
    v5->FixedValueSlotNumber = v5->pParent.pObject->FixedValueSlotNumber;
  }
}

// File Line: 225
// RVA: 0x783390
void __fastcall Scaleform::GFx::AS3::Traits::Traits(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::VM *_vm)
{
  Scaleform::GFx::AS3::Traits *v2; // r8
  Scaleform::GFx::AS3::ASRefCountCollector *v3; // rax
  Scaleform::GFx::AS3::Slots *v4; // rcx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Slots::Pair,332,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::MemoryHeap *v6; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v7; // rax

  v2 = this;
  v3 = _vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable';
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v3;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable';
  v4 = (Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum;
  v4->FirstOwnSlotNum = 0i64;
  v4->Parent = 0i64;
  v5 = &v2->VArray;
  v5->Data.Data = 0i64;
  v5->Data.Size = 0i64;
  v5->Data.Policy.Capacity = 0i64;
  v2->Set.mHash.pTable = 0i64;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  v2->FirstOwnSlotInd.Index = 0i64;
  v2->FixedValueSlotNumber = 0i64;
  v2->MemSize = 0;
  v2->Flags = 0i64;
  v2->TraitsType = 0;
  v2->pVM = _vm;
  v2->pConstructor.pObject = 0i64;
  v2->pParent.pObject = 0i64;
  v2->pVTable.pObject = 0i64;
  v2->pVTable.Owner = 1;
  v6 = _vm->MHeap;
  v7 = &v2->InitScope;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  v2->InitScope.Data.pHeap = v6;
  v2->RefCount |= 0x8000000u;
}

// File Line: 239
// RVA: 0x78E900
void __fastcall Scaleform::GFx::AS3::Traits::~Traits(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::Traits *v1; // rdi
  void **v2; // rbx
  Scaleform::GFx::AS3::VTable *v3; // rcx
  Scaleform::GFx::AS3::Traits *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::Class *v6; // rcx
  unsigned int v7; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  v2 = (void **)&this->InitScope.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->InitScope.Data.Data,
    this->InitScope.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v2);
  v3 = v1->pVTable.pObject;
  if ( v3 )
  {
    if ( v1->pVTable.Owner )
    {
      v1->pVTable.Owner = 0;
      Scaleform::GFx::AS3::VTable::`scalar deleting destructor'(v3, 1u);
    }
    v1->pVTable.pObject = 0i64;
  }
  v1->pVTable.Owner = 0;
  v4 = v1->pParent.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->pParent.pObject = (Scaleform::GFx::AS3::Traits *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
  v6 = v1->pConstructor.pObject;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v1->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( v7 & 0x3FFFFF )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> > *)&v1->Set.mHash.pTable);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy> *)&v1->VArray.Data.Data);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 258
// RVA: 0x7B0410
__int64 __fastcall Scaleform::GFx::AS3::Traits::Alloc(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::VM *v1; // rax
  unsigned __int64 v2; // rdx
  int v4; // [rsp+30h] [rbp+8h]

  v1 = this->pVM;
  v2 = this->MemSize;
  v4 = 337;
  return v1->MHeap->vfptr->Alloc(v1->MHeap, v2, (Scaleform::AllocInfo *)&v4);
}

// File Line: 288
// RVA: 0x820E80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::SetupSlotValues(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::HasTraits *t)
{
  Scaleform::GFx::AS3::Abc::HasTraits *v4; // r13
  Scaleform::GFx::AS3::VMAbcFile *v5; // rsi
  Scaleform::GFx::AS3::CheckResult *v6; // r12
  Scaleform::GFx::AS3::Traits *v7; // r9
  Scaleform::GFx::AS3::VM *v8; // r15
  __int64 v9; // rbx
  __int64 v10; // rcx
  Scaleform::GFx::AS3::Abc::File *v11; // rdx
  Scaleform::GFx::AS3::Abc::ValueDetail *v12; // rdi
  signed __int64 v13; // rcx
  Scaleform::GFx::AS3::SlotInfo *v14; // r14
  Scaleform::GFx::AS3::Value *v15; // rax
  bool v16; // di
  bool v17; // zf
  Scaleform::GFx::AS3::Value *v18; // rcx
  Scaleform::GFx::AS3::Abc::File *v19; // rdx
  __int64 v20; // rax
  signed __int64 v21; // rax
  Scaleform::GFx::AS3::Value *v22; // rax
  Scaleform::GFx::AS3::CheckResult v24; // [rsp+30h] [rbp-61h]
  Scaleform::GFx::AS3::Abc::Multiname mn; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::AS3::Abc::Multiname v26; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS3::Value v27; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+78h] [rbp-19h]
  Scaleform::GFx::AS3::VM *v29; // [rsp+98h] [rbp+7h]
  __int64 v30; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Traits *v31; // [rsp+F0h] [rbp+5Fh]
  Scaleform::GFx::AS3::CheckResult v32; // [rsp+108h] [rbp+77h]

  v31 = this;
  v30 = -2i64;
  v4 = t;
  v5 = file;
  v6 = result;
  v7 = this;
  v8 = this->pVM;
  v29 = v8;
  ++v8->InInitializer;
  v9 = 0i64;
  if ( !v4->obj_traits.Data.Size )
  {
LABEL_29:
    v6->Result = 1;
    goto LABEL_30;
  }
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v5->File.pObject;
    v12 = (Scaleform::GFx::AS3::Abc::ValueDetail *)v11->Traits.TraitInfos.Data.Data[v4->obj_traits.Data.Data[v10]];
    if ( v12->Kind & 0xF && (v12->Kind & 0xF) != 6 )
      goto LABEL_26;
    v13 = (signed __int64)&v11->Const_Pool.const_multiname.Data.Data[v12->ValueIndex];
    mn.Ind = *(_DWORD *)v13;
    mn.NextIndex = *(_DWORD *)(v13 + 4);
    mn.NameIndex = *(_DWORD *)(v13 + 8);
    mn.Kind = *(_DWORD *)(v13 + 12);
    v14 = Scaleform::GFx::AS3::Traits::FindSlotInfo(v7, v5, &mn);
    if ( v14 )
      break;
LABEL_25:
    v7 = v31;
LABEL_26:
    v10 = (unsigned int)++v9;
    if ( (unsigned int)v9 >= v4->obj_traits.Data.Size )
      goto LABEL_29;
  }
  if ( v12[2].ValueIndex > 0 )
  {
    v15 = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(v5, &resulta, v12 + 2);
    v16 = Scaleform::GFx::AS3::SlotInfo::SetSlotValue(v14, &v32, v31->pVM, v15)->Result == 0;
    if ( (resulta.Flags & 0x1F) <= 9 )
      goto LABEL_24;
    if ( (resulta.Flags >> 9) & 1 )
    {
      v17 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value = 0ui64;
      resulta.Flags &= 0xFFFFFDE0;
      goto LABEL_24;
    }
    v18 = &resulta;
LABEL_23:
    Scaleform::GFx::AS3::Value::ReleaseInternal(v18);
    goto LABEL_24;
  }
  v19 = v5->File.pObject;
  if ( v12->Kind & 0xF && (v12->Kind & 0xF) != 6 )
    v20 = v19->AS3_Classes.Info.Data.Data[v12[1].ValueIndex]->inst_info.name_ind;
  else
    v20 = v12[1].ValueIndex;
  v21 = (signed __int64)&v19->Const_Pool.const_multiname.Data.Data[v20];
  v26.Ind = *(_DWORD *)v21;
  v26.NextIndex = *(_DWORD *)(v21 + 4);
  v26.NameIndex = *(_DWORD *)(v21 + 8);
  v26.Kind = *(_DWORD *)(v21 + 12);
  v22 = Scaleform::GFx::AS3::VM::GetDefaultValue(v31->pVM, &v27, v5, &v26);
  v16 = Scaleform::GFx::AS3::SlotInfo::SetSlotValue(v14, &v24, v31->pVM, v22)->Result == 0;
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( !((v27.Flags >> 9) & 1) )
    {
      v18 = &v27;
      goto LABEL_23;
    }
    v17 = v27.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v17 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v27.Bonus.pWeakProxy = 0i64;
    v27.value = 0ui64;
    v27.Flags &= 0xFFFFFDE0;
  }
LABEL_24:
  if ( !v16 )
    goto LABEL_25;
  v6->Result = 0;
LABEL_30:
  --v8->InInitializer;
  return v6;
}

// File Line: 368
// RVA: 0x7D6670
void __fastcall Scaleform::GFx::AS3::Traits::ForEachChild_GC(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Traits *v3; // rsi
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // rdi
  Scaleform::GFx::AS3::VTable *v6; // rcx

  v3 = this;
  v4 = op;
  v5 = prcc;
  Scaleform::GFx::AS3::Slots::ForEachChild_GC((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, prcc, op);
  if ( v3->pConstructor.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v4)(v5);
  if ( v3->pParent.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v4)(v5);
  v6 = v3->pVTable.pObject;
  if ( v6 )
    Scaleform::GFx::AS3::VTable::ForEachChild_GC(v6, v5, v4);
  Scaleform::GFx::AS3::ForEachChild_GC(v5, &v3->InitScope, v4);
}

// File Line: 388
// RVA: 0x7E6140
signed __int64 __fastcall Scaleform::GFx::AS3::Traits::GetBindingType(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rax
  signed __int64 result; // rax

  v3 = this->pVM;
  if ( !*(_QWORD *)&mn->NameIndex && !mn->Ind )
    return 2i64;
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this->pVM, (Scaleform::GFx::AS3::VMFile *)&file->vfptr, mn);
  if ( !v4 )
    return 2i64;
  switch ( v4->TraitsType )
  {
    case 1:
      result = 5i64;
      break;
    case 2:
      result = 6i64;
      break;
    case 3:
      result = 7i64;
      break;
    case 4:
      result = 8i64;
      break;
    case 5:
      result = 9i64;
      break;
    case 0xA:
      return 2i64;
    default:
      result = (unsigned int)(v4 != (Scaleform::GFx::AS3::ClassTraits::Traits *)v3->TraitsObject.pObject) + 2;
      break;
  }
  return result;
}

// File Line: 442
// RVA: 0x7AEEE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlotsWithID(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Abc::HasTraits *traits, Scaleform::GFx::AS3::VMAbcFile *file)
{
  Scaleform::GFx::AS3::VMAbcFile *v4; // r13
  Scaleform::GFx::AS3::Abc::HasTraits *v5; // r12
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::Traits *v7; // r11
  __int64 v8; // rdi
  __int64 v9; // r10
  Scaleform::GFx::AS3::Abc::File *v10; // r9
  Scaleform::GFx::AS3::Abc::TraitInfo *ti; // r14
  int v12; // edx
  Scaleform::GFx::AS3::Abc::Multiname *v13; // rbp
  int v14; // ebx
  char v15; // si
  bool _const; // r15
  __int64 v17; // r8
  unsigned int v18; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // rax
  Scaleform::GFx::AS3::SlotInfo *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+48h] [rbp-60h]
  Scaleform::GFx::AS3::Traits *v27; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::AS3::CheckResult *v28; // [rsp+B8h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+C0h] [rbp+18h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+C8h] [rbp+20h]

  v28 = result;
  v27 = this;
  v4 = file;
  v5 = traits;
  v6 = result;
  v7 = this;
  vm = file->VMRef;
  v8 = 0i64;
  if ( !traits->obj_traits.Data.Size )
  {
LABEL_31:
    v6->Result = 1;
    return v6;
  }
  v9 = 0i64;
  while ( 1 )
  {
    v10 = v4->File.pObject;
    ti = v10->Traits.TraitInfos.Data.Data[v5->obj_traits.Data.Data[v9]];
    v12 = ti->kind & 0xF;
    if ( ti->kind & 0xF && (unsigned int)(v12 - 4) > 2 )
      goto LABEL_23;
    v13 = &v10->Const_Pool.const_multiname.Data.Data[ti->name_ind];
    v14 = ti->SlotId;
    if ( !v14 )
      goto LABEL_23;
    v15 = 1;
    _const = 0;
    if ( !(ti->kind & 0xF) )
      goto LABEL_15;
    switch ( v12 )
    {
      case 4:
        goto LABEL_34;
      case 5:
        v15 = 2;
        break;
      case 6:
LABEL_34:
        _const = 1;
        if ( ti->kind & 0xF && v12 != 6 )
          v17 = v10->AS3_Classes.Info.Data.Data[ti->Ind]->inst_info.name_ind;
        else
LABEL_15:
          v17 = ti->Ind;
        v15 = Scaleform::GFx::AS3::Traits::GetBindingType(v7, v4, &v10->Const_Pool.const_multiname.Data.Data[v17]);
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString((Scaleform::GFx::AS3::VMFile *)&v4->vfptr, &resulta, v13->NameIndex);
    v18 = v14 - 1;
    v19 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&v4->vfptr, v13);
    if ( v19 )
      v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
    v20 = Scaleform::GFx::AS3::Traits::AddSetSlot(
            v27,
            (Scaleform::GFx::AS3::RelativeIndex)v18,
            &resulta,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)v19,
            v4,
            ti,
            _const);
    if ( *(_DWORD *)v20 & 0x7C00 )
      break;
    *(_DWORD *)v20 = *(_DWORD *)v20 & 0x3FF | ((*(_DWORD *)&v15 | 0xFFFFFFE0) << 10);
    v21 = resulta.pNode;
    v22 = resulta.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v7 = v27;
LABEL_23:
    v9 = (unsigned int)++v8;
    if ( (unsigned int)v8 >= v5->obj_traits.Data.Size )
    {
      v6 = v28;
      goto LABEL_31;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v26, eIllegalOverrideError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v23, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v24 = v26.Message.pNode;
  v22 = v26.Message.pNode->RefCount == 1;
  --v24->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  v28->Result = 0;
  v25 = resulta.pNode;
  v22 = resulta.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  return v28;
}e->RefCount == 1;
  --v25->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStr

// File Line: 548
// RVA: 0x7AF100
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Abc::HasTraits *traits, Scaleform::GFx::AS3::VMAbcFile *file, bool members)
{
  Scaleform::GFx::AS3::VMAbcFile *v5; // r13
  Scaleform::GFx::AS3::Abc::HasTraits *v6; // r14
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  Scaleform::GFx::AS3::Traits *v8; // r10
  _BOOL8 v9; // r12
  __int64 v10; // rbx
  __int64 v11; // r9
  bool v12; // r8
  Scaleform::GFx::AS3::Abc::File *v13; // rdx
  Scaleform::GFx::AS3::Abc::TraitInfo *v14; // r14
  int v15; // ecx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // er15
  Scaleform::GFx::AS3::Abc::Multiname *v17; // rsi
  unsigned __int64 v18; // rdi
  int v19; // edx
  Scaleform::GFx::AS3::Abc::File *v20; // r9
  __int64 v21; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v22; // rax
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // edi
  bool v26; // zf
  Scaleform::GFx::AS3::Slots::Pair *v27; // rdx
  int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::AS3::CheckResult v33; // [rsp+30h] [rbp-81h]
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-79h]
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+40h] [rbp-71h]
  Scaleform::GFx::AS3::Value v; // [rsp+70h] [rbp-41h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+90h] [rbp-21h]
  Scaleform::GFx::AS3::AbsoluteIndex v38; // [rsp+98h] [rbp-19h]
  Scaleform::GFx::ASStringNode *v39; // [rsp+A0h] [rbp-11h]
  __int64 v40; // [rsp+A8h] [rbp-9h]
  __int64 v41; // [rsp+B0h] [rbp-1h]
  Scaleform::GFx::AS3::Traits *v42; // [rsp+110h] [rbp+5Fh]
  Scaleform::GFx::AS3::CheckResult *v43; // [rsp+118h] [rbp+67h]
  Scaleform::GFx::AS3::Abc::HasTraits *v44; // [rsp+120h] [rbp+6Fh]
  char v45; // [rsp+128h] [rbp+77h]

  v44 = traits;
  v43 = result;
  v42 = this;
  v40 = -2i64;
  v5 = file;
  v6 = traits;
  v7 = result;
  v8 = this;
  LOBYTE(v9) = 1;
  vm = file->VMRef;
  v10 = 0i64;
  if ( !traits->obj_traits.Data.Size )
    goto LABEL_46;
  v11 = 0i64;
  v12 = members;
  while ( 1 )
  {
    v13 = v5->File.pObject;
    v14 = v13->Traits.TraitInfos.Data.Data[v6->obj_traits.Data.Data[v11]];
    v15 = v14->kind & 0xF;
    if ( v14->kind & 0xF && (unsigned int)(v15 - 4) > 2 )
    {
      if ( v12 )
        goto LABEL_38;
    }
    else if ( !v12 || v14->SlotId )
    {
      goto LABEL_38;
    }
    bt = 1;
    v17 = &v13->Const_Pool.const_multiname.Data.Data[v14->name_ind];
    if ( (unsigned int)(v15 - 1) > 2 )
    {
      v18 = v8->FixedValueSlotNumber;
      v8->FixedValueSlotNumber = v18 + 1;
    }
    else
    {
      LODWORD(v18) = -1;
    }
    v45 = 0;
    v19 = v14->kind & 0xF;
    switch ( v19 )
    {
      case 0:
        goto $LN11_62;
      case 1:
        bt = 11;
        break;
      case 2:
        bt = 12;
        break;
      case 3:
        bt = 13;
        break;
      case 4:
      case 6:
        v45 = 1;
$LN11_62:
        v20 = v5->File.pObject;
        if ( v14->kind & 0xF && v19 != 6 )
          v21 = v20->AS3_Classes.Info.Data.Data[v14->Ind]->inst_info.name_ind;
        else
          v21 = v14->Ind;
        bt = Scaleform::GFx::AS3::Traits::GetBindingType(v8, v5, &v20->Const_Pool.const_multiname.Data.Data[v21]);
        break;
      case 5:
        bt = 2;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString((Scaleform::GFx::AS3::VMFile *)&v5->vfptr, &resulta, v17->NameIndex);
    v22 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace((Scaleform::GFx::AS3::VMFile *)&v5->vfptr, v17);
    v41 = 0i64;
    if ( v22 )
      v22->RefCount = (v22->RefCount + 1) & 0x8FBFFFFF;
    v23 = (v45 != 0) + 2;
    nsi = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&nsi & 0x8000 | 0xFFFF8000);
    nsi.Padding01 = 0;
    nsi.pNs.pObject = v22;
    nsi.CTraits.pObject = 0i64;
    nsi.File.pObject = v5;
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
    nsi.TI = v14;
    nsi.Name.pObject = 0i64;
    nsi = (Scaleform::GFx::AS3::SlotInfo)(((((*(_DWORD *)&nsi & 0xFFFFFFFC | v23 & 1) & 0xFFFFFFF3 | 4 * ((v23 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v23 >> 2) & 1)) & 0xFFFFFF3F | (((v23 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v23 >> 4) & 1) << 8));
    if ( (v14->kind & 0xFu) - 1 <= 2 )
    {
      v24 = v14->Ind;
      v.Flags = 2;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VInt = v24;
      v9 = Scaleform::GFx::AS3::Traits::RegisterWithVT(v42, &v33, &resulta, &nsi, &v, bt)->Result;
      v25 = v.Flags;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          v26 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v26 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v.Bonus.pWeakProxy = 0i64;
          v.value = 0ui64;
          v.Flags = v25 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
      }
      goto LABEL_34;
    }
    v27 = &v42->VArray.Data.Data[LODWORD(Scaleform::GFx::AS3::Slots::Add(
                                           (Scaleform::GFx::AS3::Slots *)&v42->FirstOwnSlotNum,
                                           &v38,
                                           &resulta,
                                           &nsi)->Index)
                               - v42->FirstOwnSlotNum];
    v28 = (int)v27->Value;
    if ( v28 & 0x7C00 )
      break;
    v27->Value = (Scaleform::GFx::AS3::SlotInfo)(*(_DWORD *)&v27->Value & 0x3FF | ((bt & 0x1F | 32 * (signed int)v18) << 10));
LABEL_34:
    if ( !(_BYTE)v9 )
      goto LABEL_41;
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
    v29 = resulta.pNode;
    v26 = resulta.pNode->RefCount == 1;
    --v29->RefCount;
    if ( v26 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    v12 = members;
    v8 = v42;
LABEL_38:
    v11 = (unsigned int)++v10;
    v6 = v44;
    if ( (unsigned int)v10 >= v44->obj_traits.Data.Size )
      goto LABEL_45;
  }
  LOBYTE(v9) = 0;
LABEL_41:
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v38, eIllegalOverrideError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v30, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v31 = v39;
  v26 = v39->RefCount == 1;
  --v31->RefCount;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  v32 = resulta.pNode;
  v26 = resulta.pNode->RefCount == 1;
  --v32->RefCount;
  if ( v26 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
LABEL_45:
  v7 = v43;
LABEL_46:
  v7->Result = v9;
  return v7;
}

// File Line: 673
// RVA: 0x7AEE00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlots(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Abc::HasTraits *traits, Scaleform::GFx::AS3::VMAbcFile *file, unsigned int parent_size)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rsi
  signed int v6; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v7; // rdi
  Scaleform::GFx::AS3::Abc::HasTraits *v8; // r14
  Scaleform::GFx::AS3::Traits *v9; // rbp
  bool v10; // di
  Scaleform::GFx::AS3::CheckResult *v11; // rax
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+31h] [rbp-27h]
  unsigned int v14; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+68h] [rbp+10h]

  v5 = result;
  v6 = 1;
  v7 = file;
  v8 = traits;
  v9 = this;
  v14 = 1;
  v10 = 0;
  if ( Scaleform::GFx::AS3::Traits::AddSlotsWithID(this, &resulta, traits, file)->Result )
  {
    v6 = 3;
    v14 = 3;
    if ( Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(v9, &v12, v8, v7, 1)->Result )
    {
      v6 = 7;
      v14 = 7;
      if ( Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(v9, &v13, v8, v7, 0)->Result )
        v10 = 1;
    }
  }
  if ( v6 & 4 )
  {
    v6 &= 0xFFFFFFFB;
    v14 = v6;
  }
  if ( v6 & 2 )
  {
    v6 &= 0xFFFFFFFD;
    v14 = v6;
  }
  if ( v6 & 1 )
    v14 = v6 & 0xFFFFFFFE;
  if ( v10 )
    Scaleform::GFx::AS3::Traits::CalculateMemSize(v9, parent_size);
  v11 = v5;
  v5->Result = v10;
  return v11;
}

// File Line: 698
// RVA: 0x7AA410
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::SlotInfo *si, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::SlotInfo::BindingType v4; // esi
  Scaleform::GFx::AS3::Value *v5; // rbp
  Scaleform::GFx::AS3::SlotInfo *v6; // r14
  Scaleform::GFx::AS3::VTable *v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rbx
  int v10; // edi
  Scaleform::GFx::AS3::AbsoluteIndex v11; // rbx
  signed int v12; // edi
  signed int v13; // eax
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+48h] [rbp+10h]

  v4 = new_bt;
  v5 = v;
  v6 = si;
  v7 = Scaleform::GFx::AS3::Traits::GetVT(this);
  v8 = *(_DWORD *)v6;
  v9 = v8;
  v10 = v8 & 0xFFFFFDFF | 0x100;
  v11.Index = v9 >> 15;
  *(_DWORD *)v6 = v10;
  if ( v11.Index < 0 )
  {
    *(_DWORD *)v6 = *(_DWORD *)v6 & 0x3FF | ((v4 & 0x1F | 32
                                                        * (unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                          v7,
                                                                          &result,
                                                                          v5,
                                                                          v4)->Index) << 10);
    return;
  }
  v12 = v10 << 17 >> 27;
  if ( v12 != 11 || v4 == 11 )
  {
    Scaleform::GFx::AS3::VTable::SetMethod(v7, v11, v5, v4);
    v13 = v12;
    if ( v12 == 12 )
    {
      if ( v4 != 13 )
      {
LABEL_10:
        if ( v13 != v12 )
        {
          *(_DWORD *)v6 &= 0x3FFu;
          *(_DWORD *)v6 |= (v13 & 0x1F | 32 * LODWORD(v11.Index)) << 10;
        }
        return;
      }
    }
    else
    {
      if ( v12 != 13 )
        return;
      if ( v4 != 12 )
        goto LABEL_10;
    }
    v13 = 14;
    goto LABEL_10;
  }
}

// File Line: 749
// RVA: 0x8295A0
void __fastcall Scaleform::GFx::AS3::Traits::UpdateVT(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::SlotInfo *si, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::SlotInfo::BindingType v4; // edi
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::SlotInfo *v6; // rbx
  Scaleform::GFx::AS3::VTable *v7; // rax

  v4 = new_bt;
  v5 = v;
  v6 = si;
  v7 = Scaleform::GFx::AS3::Traits::GetVT(this);
  if ( *(_DWORD *)v6 << 17 >> 27 != 11 || v4 == 11 )
    Scaleform::GFx::AS3::VTable::SetMethod(
      v7,
      (Scaleform::GFx::AS3::AbsoluteIndex)((signed __int64)*(_DWORD *)v6 >> 15),
      v5,
      v4);
}

// File Line: 790
// RVA: 0x7B2420
void __fastcall Scaleform::GFx::AS3::Traits::CalculateMemSize(Scaleform::GFx::AS3::Traits *this, unsigned int parent_size)
{
  Scaleform::GFx::AS3::Traits *v2; // rdi
  Scaleform::MemoryHeap *v3; // r8
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // r12
  int v6; // er13
  int v7; // er15
  int v8; // ebp
  int v9; // esi
  unsigned __int64 v10; // rcx
  Scaleform::GFx::AS3::AbsoluteIndex v11; // rbx
  Scaleform::GFx::AS3::SlotInfo *v12; // rax
  int v13; // eax
  unsigned int v14; // er11
  unsigned int v15; // er9
  unsigned int v16; // er10
  unsigned __int64 v17; // rdx
  unsigned int v18; // er14
  unsigned int v19; // er10
  unsigned int v20; // er9
  unsigned int v21; // er11
  Scaleform::GFx::AS3::Slots::Pair *v22; // rbx
  int v23; // er8
  int v24; // eax
  void *v25; // [rsp+28h] [rbp-60h]
  __int64 v26; // [rsp+30h] [rbp-58h]
  __int64 v27; // [rsp+38h] [rbp-50h]
  Scaleform::MemoryHeap *v28; // [rsp+40h] [rbp-48h]
  unsigned int v29; // [rsp+98h] [rbp+10h]

  v29 = parent_size;
  v2 = this;
  this->MemSize = parent_size;
  v3 = this->pVM->MHeap;
  v25 = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v28 = v3;
  v4 = this->FirstOwnSlotNum;
  v5 = v4 + this->VArray.Data.Size;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = LODWORD(this->FirstOwnSlotInd.Index);
  v11.Index = (unsigned int)v10;
  if ( v10 < v5 )
  {
    do
    {
      if ( v11.Index < 0 || v11.Index < v4 )
        v12 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v2->Parent, v11);
      else
        v12 = &v2->VArray.Data.Data[LODWORD(v11.Index) - v4].Value;
      v13 = *(_DWORD *)v12;
      if ( !(v13 & 0x300) )
      {
        switch ( v13 << 17 >> 27 )
        {
          case 2:
            ++v9;
            break;
          case 3:
          case 8:
          case 9:
            ++v8;
            break;
          case 5:
            ++v6;
            break;
          case 6:
          case 7:
            ++v7;
            break;
          default:
            break;
        }
      }
      ++v11.Index;
    }
    while ( v11.Index < v5 );
    LODWORD(v10) = v2->FirstOwnSlotInd.Index;
  }
  if ( v9 + v8 + v7 + v6 )
  {
    v14 = v29 + v6;
    if ( v7 )
      v14 = (v14 + 3) & 0xFFFFFFFC;
    v15 = v14 + 4 * v7;
    if ( v8 )
      v15 = (v15 + 7) & 0xFFFFFFF8;
    v16 = v15 + 8 * v8;
    if ( v9 )
      v16 = (v16 + 31) & 0xFFFFFFE0;
    v2->MemSize = v16 + 32 * v9;
    v17 = (unsigned int)v10;
    if ( (unsigned int)v10 < v5 )
    {
      v18 = v29 << 15;
      v19 = v16 << 15;
      v20 = v15 << 15;
      v21 = v14 << 15;
      do
      {
        v22 = &v2->VArray.Data.Data[(unsigned int)v17 - v2->FirstOwnSlotNum];
        v23 = (int)v22->Value;
        if ( !(v23 & 0x300) )
        {
          switch ( *(_DWORD *)&v22->Value << 17 >> 27 )
          {
            case 2:
              v24 = v19 ^ ((unsigned __int16)v23 ^ (unsigned __int16)v19) & 0x7FFF;
              v19 += 0x100000;
              goto LABEL_29;
            case 3:
            case 8:
            case 9:
              v24 = v20 ^ ((unsigned __int16)v23 ^ (unsigned __int16)v20) & 0x7FFF;
              v20 += 0x40000;
              goto LABEL_29;
            case 5:
              v24 = v18 ^ ((unsigned __int16)v23 ^ (unsigned __int16)v18) & 0x7FFF;
              v18 += 0x8000;
              goto LABEL_29;
            case 6:
            case 7:
              v24 = v21 ^ ((unsigned __int16)v23 ^ (unsigned __int16)v21) & 0x7FFF;
              v21 += 0x20000;
LABEL_29:
              v22->Value = (Scaleform::GFx::AS3::SlotInfo)v24;
              break;
            default:
              break;
          }
        }
        ++v17;
      }
      while ( v17 < v5 );
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v25);
}

// File Line: 936
// RVA: 0x7EA2E0
__int64 __fastcall Scaleform::GFx::AS3::IntervalTimer::GetId(Scaleform::GFx::AS2::IntervalTimer *this)
{
  return (unsigned int)this->Id;
}

// File Line: 946
// RVA: 0x8164D0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::VMAppDomain *v3; // rbp
  Scaleform::GFx::AS3::ClassInfo *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::TypeInfo *v6; // r9
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rbx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned int v13; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // [rsp+68h] [rbp+20h]

  v3 = appDomain;
  v4 = ci;
  v5 = vm;
  v6 = ci->Type->Parent;
  if ( !v6 )
    return 0i64;
  v15 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(vm, &result, 0, v6->PkgName)->pV;
  v7 = v15;
  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
         (Scaleform::GFx::ASString *)&result,
         v4->Type->Parent->Name);
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v5, v8, v7, v3);
  v10 = (Scaleform::GFx::ASStringNode *)result.pV;
  v11 = LODWORD(result.pV->pPrev) == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( !v7 )
    return v9;
  if ( (unsigned __int8)v7 & 1 )
  {
    v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v7 - 1);
    return v9;
  }
  v13 = v7->RefCount;
  if ( !(v13 & 0x3FFFFF) )
    return v9;
  v7->RefCount = v13 - 1;
  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
  return v9;
}

// File Line: 970
// RVA: 0x822580
void __fastcall Scaleform::GFx::AS3::Traits::StoreScopeStack(Scaleform::GFx::AS3::Traits *this, const unsigned __int64 baseSSInd, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // r14
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // r8
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v7; // rdi
  signed __int64 v8; // rsi
  unsigned __int64 v9; // rbp
  Scaleform::GFx::AS3::Value *v10; // rbx
  signed __int64 v11; // rdx
  int v12; // eax
  long double v13; // rcx

  v3 = ss;
  v4 = baseSSInd;
  v5 = ss->Data.Size;
  v6 = v5 + this->InitScope.Data.Size;
  v7 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->InitScope.Data.Data;
  if ( v6 > this->InitScope.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->InitScope.Data.Data,
      this->InitScope.Data.pHeap,
      v6);
  if ( v4 < v5 )
  {
    v8 = v4;
    v9 = v5 - v4;
    do
    {
      v10 = v3->Data.Data;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v7,
        v7[1].Data,
        v7->Size + 1);
      v11 = (signed __int64)&v7->Data[v7->Size - 1];
      if ( !v11 )
        goto LABEL_18;
      *(_DWORD *)v11 = v10[v8].Flags;
      *(_QWORD *)(v11 + 8) = v10[v8].Bonus.pWeakProxy;
      *(long double *)(v11 + 16) = v10[v8].value.VNumber;
      *(_QWORD *)(v11 + 24) = v10[v8].value.VS._2.VObj;
      v12 = v10[v8].Flags & 0x1F;
      if ( v12 <= 9 )
        goto LABEL_18;
      if ( (v10[v8].Flags >> 9) & 1 )
      {
        ++v10[v8].Bonus.pWeakProxy->RefCount;
      }
      else if ( v12 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v10[v8].value.VNumber + 24i64);
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          v13 = v10[v8].value.VNumber;
LABEL_15:
          if ( v13 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
          goto LABEL_18;
        }
        if ( v12 <= 17 )
        {
          v13 = *(double *)&v10[v8].value.VS._2.VObj;
          goto LABEL_15;
        }
      }
LABEL_18:
      ++v8;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 981
// RVA: 0x7AE520
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Traits::AddSetSlot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::RelativeIndex ind, Scaleform::GFx::ASString *name, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::TraitInfo *ti, bool _const)
{
  Scaleform::GFx::ASString *v7; // r15
  Scaleform::GFx::AS3::Traits *v8; // r14
  __int64 v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v14; // rcx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS3::AbsoluteIndex v21; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > nsa; // [rsp+C8h] [rbp+48h]

  nsa.pV = ns.pV;
  v7 = name;
  v8 = this;
  v9 = LODWORD(this->FirstOwnSlotInd.Index) + (unsigned __int64)LODWORD(ind.Index);
  if ( (unsigned int)v9 > this->FirstOwnSlotNum + this->VArray.Data.Size )
  {
    do
    {
      v = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&v & 0x8000 | 0xFFFF8000);
      v.Padding01 = 0;
      v.pNs.pObject = 0i64;
      v.CTraits.pObject = 0i64;
      v.File.pObject = 0i64;
      v.TI = 0i64;
      v.Name.pObject = 0i64;
      v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->pVM->StringManagerRef->Builtins,
              &result);
      Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)&v8->FirstOwnSlotNum, &v21, v10, &v);
      v11 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v13 = v.Name.pObject;
      if ( v.Name.pObject )
      {
        v12 = v.Name.pObject->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      }
      v14 = v.File.pObject;
      if ( v.File.pObject )
      {
        if ( (_QWORD)v.File.pObject & 1 )
        {
          --v.File.pObject;
        }
        else
        {
          v15 = v.File.pObject->RefCount;
          if ( v15 & 0x3FFFFF )
          {
            v.File.pObject->RefCount = v15 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->vfptr);
          }
        }
      }
      v16 = v.CTraits.pObject;
      if ( v.CTraits.pObject )
      {
        if ( (_QWORD)v.CTraits.pObject & 1 )
        {
          --v.CTraits.pObject;
        }
        else
        {
          v17 = v.CTraits.pObject->RefCount;
          if ( v17 & 0x3FFFFF )
          {
            v.CTraits.pObject->RefCount = v17 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
          }
        }
      }
      v18 = v.pNs.pObject;
      if ( v.pNs.pObject )
      {
        if ( (_QWORD)v.pNs.pObject & 1 )
        {
          --v.pNs.pObject;
        }
        else
        {
          v19 = v.pNs.pObject->RefCount;
          if ( v19 & 0x3FFFFF )
          {
            v.pNs.pObject->RefCount = v19 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v18->vfptr);
          }
        }
      }
    }
    while ( (unsigned int)v9 > v8->VArray.Data.Size + v8->FirstOwnSlotNum );
    ns.pV = nsa.pV;
  }
  if ( (unsigned int)v9 == v8->VArray.Data.Size + v8->FirstOwnSlotNum )
    v9 = Scaleform::GFx::AS3::Traits::AddSlot(
           v8,
           (Scaleform::GFx::AS3::AbsoluteIndex *)&result,
           v7,
           ns,
           file,
           ti,
           _const)->Index;
  else
    Scaleform::GFx::AS3::Traits::SetSlot(v8, (Scaleform::GFx::AS3::AbsoluteIndex)v9, v7, ns, file, ti, _const);
  return &v8->VArray.Data.Data[(unsigned int)v9 - v8->FirstOwnSlotNum].Value;
}

// File Line: 1019
// RVA: 0x7AE890
void __fastcall Scaleform::GFx::AS3::Traits::AddSlot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::ASString *name, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, Scaleform::GFx::AS3::SlotInfo::BindingType dt, Scaleform::GFx::AS3::AbsoluteIndex offset, bool const_)
{
  char v6; // di
  Scaleform::GFx::AS3::Traits *v7; // rsi
  unsigned int v8; // er8
  Scaleform::GFx::ASStringNode *v9; // rbx
  bool v10; // zf
  Scaleform::GFx::AS3::Slots::Pair *v11; // rdx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+80h] [rbp+20h]
  Scaleform::GFx::ASStringNode *v14; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // [rsp+90h] [rbp+30h]

  v15 = ns.pV;
  v6 = dt;
  v7 = this;
  v8 = (const_ != 0) + 2;
  v9 = name->pNode;
  if ( name->pNode )
    ++v9->RefCount;
  v14 = v9;
  v = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&v & 0x8000 | 0xFFFF8000);
  v.Padding01 = 0;
  v.pNs.pObject = v15;
  v.CTraits.pObject = 0i64;
  v.File.pObject = 0i64;
  v.TI = 0i64;
  if ( v9 )
    ++v9->RefCount;
  v.Name.pObject = v9;
  v = (Scaleform::GFx::AS3::SlotInfo)(((((v8 & 1 | *(_DWORD *)&v & 0xFFFFFFFC) & 0xFFFFFFF3 | 4 * ((v8 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v8 >> 2) & 1)) & 0xFFFFFF3F | (((v8 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8));
  Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, &result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( v9 )
  {
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  v11 = &v7->VArray.Data.Data[LODWORD(result.Index) - v7->FirstOwnSlotNum];
  *(_DWORD *)&v11->Value &= 0xFFFF83FF;
  *(_DWORD *)&v11->Value |= (v6 & 0x1F) << 10;
  v11->Value = (Scaleform::GFx::AS3::SlotInfo)((LODWORD(offset.Index) << 15) | *(_DWORD *)&v11->Value & 0x7FFF);
}

// File Line: 1037
// RVA: 0x7AE720
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Traits::AddSlot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::AbsoluteIndex *result, Scaleform::GFx::ASString *name, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::TraitInfo *ti, bool const_)
{
  Scaleform::GFx::AS3::AbsoluteIndex *v7; // rdi
  unsigned int v8; // er9
  Scaleform::GFx::ASStringNode *v9; // rbx
  bool v10; // zf
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h]

  v7 = result;
  v9 = name->pNode;
  if ( name->pNode )
    ++v9->RefCount;
  v = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&v & 0x8000 | 0xFFFF8000);
  v.Padding01 = 0;
  v.pNs.pObject = ns.pV;
  v.CTraits.pObject = 0i64;
  v.File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  v.TI = ti;
  if ( v9 )
    ++v9->RefCount;
  v.Name.pObject = v9;
  v8 = (const_ != 0) + 2;
  v = (Scaleform::GFx::AS3::SlotInfo)(((((v8 & 1 | *(_DWORD *)&v & 0xFFFFFFFC) & 0xFFFFFFF3 | 4 * ((v8 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v8 >> 2) & 1)) & 0xFFFFFF3F | (((v8 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8));
  Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( v9 )
  {
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  return v7;
}

// File Line: 1053
// RVA: 0x7AEC80
void __fastcall Scaleform::GFx::AS3::Traits::AddSlotCPP(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::ASString *name, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, Scaleform::GFx::AS3::ClassTraits::Traits *tr, Scaleform::GFx::AS3::SlotInfo::BindingType dt, Scaleform::GFx::AS3::AbsoluteIndex offset, bool const_)
{
  Scaleform::GFx::AS3::Traits *v7; // rdi
  unsigned int v8; // er8
  Scaleform::GFx::ASStringNode *v9; // rbx
  bool v10; // zf
  Scaleform::GFx::AS3::Slots::Pair *v11; // rdx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+80h] [rbp+20h]
  Scaleform::GFx::ASStringNode *v14; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // [rsp+90h] [rbp+30h]

  v15 = ns.pV;
  v7 = this;
  v8 = ((const_ != 0) + 2) | 0x10;
  v9 = name->pNode;
  if ( name->pNode )
    ++v9->RefCount;
  v14 = v9;
  v = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&v & 0x8000 | 0xFFFF8000);
  v.Padding01 = 0;
  v.pNs.pObject = v15;
  v.CTraits.pObject = tr;
  if ( tr )
    tr->RefCount = (tr->RefCount + 1) & 0x8FBFFFFF;
  v.File.pObject = 0i64;
  v.TI = 0i64;
  if ( v9 )
    ++v9->RefCount;
  v.Name.pObject = v9;
  v = (Scaleform::GFx::AS3::SlotInfo)(((((v8 & 1 | *(_DWORD *)&v & 0xFFFFFFFC) & 0xFFFFFFF3 | 4 * ((v8 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v8 >> 2) & 1)) & 0xFFFFFF3F | (((v8 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8));
  Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, &result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( v9 )
  {
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
  v11 = &v7->VArray.Data.Data[LODWORD(result.Index) - v7->FirstOwnSlotNum];
  *(_DWORD *)&v11->Value &= 0xFFFF83FF;
  *(_DWORD *)&v11->Value |= (dt & 0x1F) << 10;
  v11->Value = (Scaleform::GFx::AS3::SlotInfo)((LODWORD(offset.Index) << 15) | *(_DWORD *)&v11->Value & 0x7FFF);
}

// File Line: 1072
// RVA: 0x7AEA10
void __fastcall Scaleform::GFx::AS3::Traits::AddSlot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::MemberInfo *mi)
{
  Scaleform::GFx::AS3::MemberInfo *v2; // r14
  Scaleform::GFx::AS3::Traits *v3; // r15
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v5; // rdi
  int v6; // er8
  unsigned int v7; // esi
  const char *v8; // r9
  const char *v9; // rax
  int v10; // edx
  int v11; // er10
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rdi
  Scaleform::GFx::AS3::Slots::Pair *v17; // rdx
  int v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::ASString k; // [rsp+90h] [rbp+30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+98h] [rbp+38h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v23; // [rsp+A0h] [rbp+40h]

  v2 = mi;
  v3 = this;
  v4 = this->pVM;
  v5 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins;
  v6 = *((_DWORD *)mi + 4);
  v7 = (*((_DWORD *)mi + 4) & 0x2000000 | 0x24000000u) >> 25;
  v8 = mi->NamespaceName;
  if ( v8 && *v8 )
  {
    if ( v8 != Scaleform::GFx::AS3::NS_AS3 )
    {
      v9 = mi->NamespaceName;
      do
      {
        v10 = (unsigned __int8)v9[Scaleform::GFx::AS3::NS_AS3 - v8];
        v11 = *(unsigned __int8 *)v9 - v10;
        if ( *(unsigned __int8 *)v9 != v10 )
          break;
        ++v9;
      }
      while ( v10 );
      if ( v11 )
      {
        v12 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                this->pVM,
                &result,
                (Scaleform::GFx::AS3::Abc::NamespaceKind)(v6 << 12 >> 28),
                v8)->pV;
        goto LABEL_16;
      }
    }
    v12 = v4->AS3Namespace.pObject;
    goto LABEL_12;
  }
  if ( !(v6 & 0xF0000) )
  {
    v12 = v4->PublicNamespace.pObject;
LABEL_12:
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
    goto LABEL_16;
  }
  v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          v5,
          (Scaleform::GFx::ASString *)&result);
  v12 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
          v4,
          &v23,
          (Scaleform::GFx::AS3::Abc::NamespaceKind)(*((_DWORD *)v2 + 4) << 12 >> 28),
          v13)->pV;
  v14 = (Scaleform::GFx::ASStringNode *)result.pV;
  v15 = LODWORD(result.pV->pPrev) == 1;
  --v14->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_16:
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    v5,
    &k,
    v2->Name);
  v16 = k.pNode;
  if ( k.pNode )
    ++k.pNode->RefCount;
  v23.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v16;
  v = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&v & 0x8000 | 0xFFFF8000);
  v.Padding01 = 0;
  v.pNs.pObject = v12;
  v.CTraits.pObject = 0i64;
  v.File.pObject = 0i64;
  v.TI = 0i64;
  if ( v16 )
    ++v16->RefCount;
  v.Name.pObject = v16;
  v = (Scaleform::GFx::AS3::SlotInfo)(((((v7 & 1 | *(_DWORD *)&v & 0xFFFFFFFC) & 0xFFFFFFF3 | 4 * ((v7 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v7 >> 2) & 1)) & 0xFFFFFF3F | (((v7 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v7 >> 4) & 1) << 8));
  Scaleform::GFx::AS3::Slots::Add(
    (Scaleform::GFx::AS3::Slots *)&v3->FirstOwnSlotNum,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&result,
    &k,
    &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( v16 )
  {
    v15 = v16->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  v17 = &v3->VArray.Data.Data[LODWORD(result.pV) - v3->FirstOwnSlotNum];
  v18 = *((_DWORD *)v2 + 4);
  *(_DWORD *)&v17->Value &= 0x3FFu;
  *(_DWORD *)&v17->Value |= ((v18 << 7 >> 27) & 0x1F | 32 * (unsigned __int16)v18) << 10;
  v19 = k.pNode;
  v15 = k.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 1114
// RVA: 0x7AA580
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::ClassInfo *ci, Scaleform::GFx::AS3::ThunkInfo *func)
{
  Scaleform::GFx::AS3::ThunkInfo *v3; // rsi
  Scaleform::GFx::AS3::ClassInfo *v4; // rbx
  Scaleform::GFx::AS3::Traits *v5; // r14
  Scaleform::GFx::AS3::VM *v6; // rdi
  const char *v7; // r9
  const char *v8; // rax
  int v9; // ecx
  int v10; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rax
  const char *v12; // rax
  bool v13; // cl
  const char *v14; // r9
  bool v15; // al
  Scaleform::GFx::ASStringNode *v16; // rbx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // edx
  bool v18; // si
  bool v19; // zf
  unsigned int v20; // ebx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-21h]
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+58h] [rbp-1h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v26; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+77h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+D8h] [rbp+7Fh]

  v3 = func;
  v4 = ci;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pVM->StringManagerRef->Builtins,
    &result,
    func->Name);
  v6 = v5->pVM;
  v7 = v3->NamespaceName;
  if ( v7 && *v7 )
  {
    if ( v7 != Scaleform::GFx::AS3::NS_AS3 )
    {
      v8 = v3->NamespaceName;
      do
      {
        v9 = (unsigned __int8)v8[Scaleform::GFx::AS3::NS_AS3 - v7];
        v10 = *(unsigned __int8 *)v8 - v9;
        if ( *(unsigned __int8 *)v8 != v9 )
          break;
        ++v8;
      }
      while ( v9 );
      if ( v10 )
      {
        v11 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                v5->pVM,
                &v26,
                (Scaleform::GFx::AS3::Abc::NamespaceKind)(*((_DWORD *)v3 + 8) & 0xF),
                v7)->pV;
        goto LABEL_24;
      }
    }
    v11 = v6->AS3Namespace.pObject;
  }
  else
  {
    v12 = v4->Type->Name;
    v13 = !v12 || !*v12;
    v14 = v4->Type->PkgName;
    v15 = !v14 || !*v14;
    if ( v13 && !v15 )
    {
      v11 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
              v5->pVM,
              &v26,
              (Scaleform::GFx::AS3::Abc::NamespaceKind)(*((_DWORD *)v3 + 8) & 0xF),
              v14)->pV;
      goto LABEL_24;
    }
    v11 = v6->PublicNamespace.pObject;
  }
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
LABEL_24:
  v.Flags = 5;
  v.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v.value.VNumber = v3;
  v16 = result.pNode;
  if ( result.pNode )
    ++result.pNode->RefCount;
  v28 = v16;
  nsi = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&nsi & 0x8000 | 0xFFFF8000);
  nsi.Padding01 = 0;
  nsi.pNs.pObject = v11;
  nsi.CTraits.pObject = 0i64;
  nsi.File.pObject = 0i64;
  nsi.TI = 0i64;
  if ( v16 )
    ++v16->RefCount;
  nsi.Name.pObject = v16;
  nsi = (Scaleform::GFx::AS3::SlotInfo)((*(_DWORD *)&nsi & 0xFFFFFFF4 | 4) & 0xFFFFFC0F);
  bt = 11;
  if ( (*((_DWORD *)v3 + 8) >> 4) & 3 )
  {
    if ( ((*((_DWORD *)v3 + 8) >> 4) & 3) == 1 )
    {
      bt = 12;
    }
    else if ( ((*((_DWORD *)v3 + 8) >> 4) & 3) == 2 )
    {
      bt = 13;
    }
  }
  v18 = Scaleform::GFx::AS3::Traits::RegisterWithVT(v5, (Scaleform::GFx::AS3::CheckResult *)&v26, &result, &nsi, &v, bt)->Result == 0;
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  if ( v16 )
  {
    v19 = v16->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  v20 = v.Flags;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v.Bonus.pWeakProxy = 0i64;
      v.value = 0ui64;
      v.Flags = v20 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( v18 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v, eIllegalOverrideError, v6);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v21, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v22 = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
    v19 = LODWORD(v.Bonus.pWeakProxy[1].pObject) == 1;
    --v22->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  v23 = result.pNode;
  v19 = result.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}

// File Line: 1161
// RVA: 0x829490
void __fastcall Scaleform::GFx::AS3::Traits::UpdateVT4IM(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::ASString *mn_name, Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Value *v5; // r14
  Scaleform::GFx::AS3::Traits *v6; // rbp
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rdx
  Scaleform::GFx::AS3::SlotInfo *v9; // rsi
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS3::VTable *v11; // rax

  v5 = v;
  v6 = this;
  if ( mn_ns == this->pVM->PublicNamespace.pObject )
  {
    v7 = *Scaleform::GFx::AS3::Slots::FindSlotValues((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, mn_name);
    while ( 1 )
    {
      v8 = v6->FirstOwnSlotNum;
      v9 = v7 < v8 ? Scaleform::GFx::AS3::Slots::GetSlotInfo(v6->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v7) : &v6->VArray.Data.Data[(unsigned int)v7 - v8].Value;
      if ( (*((_BYTE *)v9->pNs.pObject + 40) >> 4) & 1 )
        break;
      v10 = v6->FirstOwnSlotNum;
      if ( v7 >= v10 )
        v7 = v6->VArray.Data.Data[v7 - v10].Prev;
      else
        v7 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v6->Parent, v7);
      if ( (v7 & 0x8000000000000000ui64) != 0i64 )
        return;
    }
    v11 = Scaleform::GFx::AS3::Traits::GetVT(v6);
    if ( *(_DWORD *)v9 << 17 >> 27 != 11 || bt == 11 )
      Scaleform::GFx::AS3::VTable::SetMethod(
        v11,
        (Scaleform::GFx::AS3::AbsoluteIndex)((signed __int64)*(_DWORD *)v9 >> 15),
        v5,
        bt);
  }
}

// File Line: 1187
// RVA: 0x7AA4F0
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::ASString *mn_name, Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns, Scaleform::GFx::AS3::SlotInfo *nsi, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // rbp
  Scaleform::GFx::ASString *v7; // r14
  Scaleform::GFx::AS3::Traits *v8; // r15
  Scaleform::GFx::AS3::SlotInfo::BindingType v9; // edi
  Scaleform::GFx::AS3::Slots::Pair *v10; // rsi
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+50h] [rbp+8h]

  v6 = mn_ns;
  v7 = mn_name;
  v8 = this;
  Scaleform::GFx::AS3::Slots::Add((Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum, &result, mn_name, nsi);
  v9 = bt;
  v10 = &v8->VArray.Data.Data[LODWORD(result.Index) - v8->FirstOwnSlotNum];
  Scaleform::GFx::AS3::Traits::UpdateVT4IM(v8, v7, v6, v, bt);
  Scaleform::GFx::AS3::Traits::Add2VT(v8, &v10->Value, v, v9);
}

// File Line: 1199
// RVA: 0x810BF0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::RegisterWithVT(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASString *mn_name, Scaleform::GFx::AS3::SlotInfo *nsi, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // r12
  Scaleform::GFx::AS3::CheckResult *v7; // rdi
  Scaleform::GFx::AS3::SlotInfo *v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rbp
  Scaleform::GFx::ASString *v10; // r15
  unsigned __int64 v11; // r8
  Scaleform::GFx::AS3::SlotInfo *v12; // r14
  signed int v13; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v15; // esi
  Scaleform::GFx::AS3::AbsoluteIndex resulta; // [rsp+60h] [rbp+8h]

  v6 = nsi->pNs.pObject;
  v7 = result;
  v8 = nsi;
  v9 = this;
  v10 = mn_name;
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
    (Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum,
    &resulta,
    mn_name,
    nsi->pNs.pObject);
  if ( resulta.Index < 0 )
  {
    Scaleform::GFx::AS3::Traits::Add2VT(v9, v10, v6, v8, v, bt);
    v7->Result = 1;
    return v7;
  }
  v11 = v9->FirstOwnSlotNum;
  if ( resulta.Index >= v11 )
    v12 = &v9->VArray.Data.Data[LODWORD(resulta.Index) - v11].Value;
  else
    v12 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v9->Parent, resulta);
  v13 = *(_DWORD *)v12 << 17 >> 27;
  if ( v13 && v13 < 11 )
  {
    v7->Result = 0;
    return v7;
  }
  v15 = bt;
  if ( v13 == 12 )
  {
    if ( bt != 13 )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( v13 == 13 && bt == 12 )
LABEL_14:
    v13 = 14;
LABEL_15:
  if ( v13 == bt )
  {
    Scaleform::GFx::AS3::Traits::UpdateVT4IM(v9, v10, v6, v, bt);
    Scaleform::GFx::AS3::Traits::UpdateVT(v9, v12, v, v15);
  }
  else
  {
    Scaleform::GFx::AS3::Traits::Add2VT(v9, v10, v6, v12, v, bt);
  }
  v7->Result = 1;
  return v7;
}

// File Line: 1246
// RVA: 0x7E5E10
Scaleform::GFx::AS3::VMAppDomain *__fastcall Scaleform::GFx::AS3::Traits::GetAppDomain(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::Traits *v1; // rbx
  __int64 v2; // rax
  Scaleform::GFx::AS3::VMAppDomain *result; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[2].~RefCountBaseGC<328>)();
  if ( v2 )
    result = *(Scaleform::GFx::AS3::VMAppDomain **)(v2 + 48);
  else
    result = v1->pVM->SystemDomain.pObject;
  return result;
}

// File Line: 1294
// RVA: 0x7C4640
void __fastcall Scaleform::GFx::AS3::Traits::DestructTail(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rbp
  Scaleform::GFx::AS3::Traits *v3; // rsi
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // rdx
  Scaleform::GFx::AS3::SlotInfo *v6; // rax
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  int v11; // eax
  Scaleform::GFx::AS3::WeakProxy *v12; // rdx

  v2 = obj;
  v3 = this;
  v4 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  while ( v4 )
  {
    if ( (--v4 & 0x8000000000000000ui64) != 0i64 || (v5 = v3->FirstOwnSlotNum, v4 < v5) )
      v6 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v3->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v4);
    else
      v6 = &v3->VArray.Data.Data[(unsigned int)v4 - v5].Value;
    if ( !(*(_DWORD *)v6 & 0x300) )
    {
      v7 = (Scaleform::GFx::AS3::Value *)((char *)v2 + ((signed __int64)*(_DWORD *)v6 >> 15));
      switch ( *(_DWORD *)v6 << 17 >> 27 )
      {
        case 2:
          if ( (v7->Flags & 0x1F) > 9 )
          {
            if ( (v7->Flags >> 9) & 1 )
            {
              v12 = v7->Bonus.pWeakProxy;
              v9 = v12->RefCount-- == 1;
              if ( v9 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v7->Flags &= 0xFFFFFDE0;
              v7->Bonus.pWeakProxy = 0i64;
              v7->value.VNumber = 0.0;
              v7->value.VS._2.VObj = 0i64;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
            }
          }
          break;
        case 3:
          if ( *(_QWORD *)&v7->Flags )
          {
            v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(*(_QWORD *)&v7->Flags & 0xFFFFFFFFFFFFFFF9ui64);
            if ( v7->Flags & 1 )
            {
              *(_QWORD *)&v7->Flags = (char *)v10 + (v7->Flags & 6) - 1;
            }
            else
            {
              v11 = *(_DWORD *)((*(_QWORD *)&v7->Flags & 0xFFFFFFFFFFFFFFF9ui64) + 0x20);
              if ( v11 & 0x3FFFFF )
              {
                *(_DWORD *)((*(_QWORD *)&v7->Flags & 0xFFFFFFFFFFFFFFF9ui64) + 0x20) = v11 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
              }
            }
          }
          break;
        case 9:
          v8 = *(Scaleform::GFx::ASStringNode **)&v7->Flags;
          if ( *(_QWORD *)&v7->Flags )
          {
            v9 = v8->RefCount-- == 1;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v8);
          }
          break;
      }
    }
  }
}

// File Line: 1309
// RVA: 0x7B9890
void __fastcall Scaleform::GFx::AS3::Traits::ConstructTail(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rbp
  Scaleform::GFx::AS3::Traits *v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::AbsoluteIndex v5; // rbx
  unsigned __int64 v6; // rdx
  Scaleform::GFx::AS3::SlotInfo *v7; // rax
  __int64 v8; // rax
  _QWORD *v9; // rdx
  int v10; // eax
  int v11; // eax

  v2 = obj;
  v3 = this;
  v4 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  v5.Index = 0i64;
  if ( v4 )
  {
    do
    {
      if ( v5.Index < 0 || (v6 = v3->FirstOwnSlotNum, v5.Index < v6) )
        v7 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v3->Parent, v5);
      else
        v7 = &v3->VArray.Data.Data[LODWORD(v5.Index) - v3->FirstOwnSlotNum].Value;
      v8 = *(_DWORD *)v7;
      if ( !(v8 & 0x300) )
      {
        v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)((char *)&v2->vfptr + (v8 >> 15));
        v10 = ((_DWORD)v8 << 17 >> 27) - 2;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 == 6 )
              *v9 = 0i64;
          }
          else if ( v9 )
          {
            *v9 = 0i64;
          }
        }
        else if ( v9 )
        {
          *(_DWORD *)v9 = 0;
          v9[1] = 0i64;
        }
      }
      ++v5.Index;
    }
    while ( v5.Index < v4 );
  }
}

// File Line: 1322
// RVA: 0x7D70F0
void __fastcall Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::Object *obj, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::GFx::AS3::Object *v5; // r14
  Scaleform::GFx::AS3::RefCountCollector<328> *v6; // r15
  Scaleform::GFx::AS3::Traits *v7; // rdi
  Scaleform::GFx::AS3::AbsoluteIndex v8; // rbx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rdx
  Scaleform::GFx::AS3::SlotInfo *v11; // rax

  v4 = op;
  v5 = obj;
  v6 = prcc;
  v7 = this;
  v8.Index = 0i64;
  v9 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  if ( v9 )
  {
    do
    {
      if ( v8.Index < 0 || (v10 = v7->FirstOwnSlotNum, v8.Index < v10) )
        v11 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, v8);
      else
        v11 = &v7->VArray.Data.Data[LODWORD(v8.Index) - v10].Value;
      Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(v11, v6, v5, v4);
      ++v8.Index;
    }
    while ( v8.Index < v9 );
  }
}

// File Line: 1354
// RVA: 0x7F0D10
Scaleform::GFx::AS3::VTable *__fastcall Scaleform::GFx::AS3::Traits::GetVT(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::Traits *v1; // rbx
  bool v2; // zf
  Scaleform::MemoryHeap *v3; // rcx
  Scaleform::MemoryHeapVtbl *v4; // rax
  __int64 v5; // rsi
  Scaleform::GFx::AS3::VTable *v6; // rax
  Scaleform::GFx::AS3::VTable *v7; // rcx
  Scaleform::GFx::AS3::Traits **v9; // rax
  signed __int64 v10; // [rsp+60h] [rbp+18h]

  v1 = this;
  if ( this->pVTable.pObject )
    return this->pVTable.pObject;
  v2 = this->pParent.pObject == 0i64;
  v3 = this->pVM->MHeap;
  v4 = v3->vfptr;
  if ( v2 )
  {
    v9 = (Scaleform::GFx::AS3::Traits **)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->Alloc)(
                                           v3,
                                           32i64);
    v5 = (__int64)v9;
    if ( v9 )
    {
      *v9 = v1;
      v10 = (signed __int64)(v9 + 1);
      *(_OWORD *)v10 = 0ui64;
      *(_QWORD *)(v10 + 16) = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->Alloc)(v3, 32i64);
    if ( v5 )
    {
      v6 = Scaleform::GFx::AS3::Traits::GetVT(v1->pParent.pObject);
      *(_QWORD *)v5 = v1;
      Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>(
        (Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> *)(v5 + 8),
        &v6->VTMethods.Data);
    }
    else
    {
      v5 = 0i64;
    }
  }
  v7 = v1->pVTable.pObject;
  if ( v7 != (Scaleform::GFx::AS3::VTable *)v5 )
  {
    if ( v7 )
    {
      if ( v1->pVTable.Owner )
      {
        v1->pVTable.Owner = 0;
        Scaleform::GFx::AS3::VTable::`scalar deleting destructor'(v7, 1);
      }
    }
    v1->pVTable.pObject = (Scaleform::GFx::AS3::VTable *)v5;
  }
  v1->pVTable.Owner = v5 != 0;
  return v1->pVTable.pObject;
}

// File Line: 1373
// RVA: 0x1588330
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Class_1369_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A510 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1369,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Class::prototypeGet;
  return result;
}

// File Line: 1374
// RVA: 0x1588360
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Class_1370_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A520 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1370,long>::Method = Scaleform::GFx::AS3::Class::lengthGet;
  return result;
}

// File Line: 1375
// RVA: 0x1588390
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Class_1371_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A530 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Class,1371,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Class::toString;
  return result;
}

// File Line: 1390
// RVA: 0x1597520
__int64 Scaleform::GFx::AS3::ClassTraits::_dynamic_initializer_for__ti__()
{
  __int64 result; // rax

  *((_QWORD *)&ti[1] + 4) = 576i64;
  ti[0].DefArgValue = 0i64;
  ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  ti[1].Method = Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty;
  ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  ti[1].ArgType = &tit[2];
  ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  ti[1].Name = "hasOwnProperty";
  result = 0i64;
  ti[1].DefArgValue = 0i64;
  *((_QWORD *)&ti[2] + 4) = 576i64;
  ti[2].Method = Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable;
  ti[2].DefArgValue = 0i64;
  ti[2].ArgType = &tit[4];
  ti[2].Name = "propertyIsEnumerable";
  return result;
}

// File Line: 1410
// RVA: 0x783620
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassInfo *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v6; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList **v8; // rdi
  unsigned __int16 v9; // bp
  unsigned __int8 i; // di
  unsigned __int16 v11; // bp
  unsigned __int8 j; // di

  v3 = ci;
  v4 = vm;
  v5 = this;
  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v6 = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(LODWORD(vm->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v6 = vm->CurrentDomain.pObject;
  v7 = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, v3, v6);
  Scaleform::GFx::AS3::Traits::Traits(
    (Scaleform::GFx::AS3::Traits *)&v5->vfptr,
    v4,
    (Scaleform::GFx::AS3::Traits *)&v7->vfptr,
    1,
    0);
  v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable';
  v5->ITraits.pObject = 0i64;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)v4->TraitsClassClass.pObject->ITraits.pObject;
  if ( !v8[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*v8)->List.Data.Data)(v8);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v5->pConstructor,
    v8[17]);
  v5->Flags |= 0x20ui64;
  if ( !v5->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(v5);
  v9 = v3->Type->ClassMemberNum;
  for ( i = 0;
        i < v9;
        Scaleform::GFx::AS3::Traits::AddSlot((Scaleform::GFx::AS3::Traits *)&v5->vfptr, &v3->ClassMember[i++]) )
  {
    ;
  }
  v11 = v3->Type->ClassMethodNum;
  for ( j = 0;
        j < v11;
        Scaleform::GFx::AS3::Traits::Add2VT((Scaleform::GFx::AS3::Traits *)&v5->vfptr, v3, &v3->ClassMethod[j++]) )
  {
    ;
  }
}

// File Line: 1432
// RVA: 0x7837B0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassTraits::Traits *pt)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v5; // rbx

  v3 = vm;
  v4 = this;
  Scaleform::GFx::AS3::Traits::Traits(
    (Scaleform::GFx::AS3::Traits *)&this->vfptr,
    vm,
    (Scaleform::GFx::AS3::Traits *)&pt->vfptr,
    1,
    0);
  v4->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable';
  v4->ITraits.pObject = 0i64;
  v5 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)v3->TraitsClassClass.pObject->ITraits.pObject;
  if ( !v5[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*v5)->List.Data.Data)(v5);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->pConstructor,
    v5[17]);
  v4->Flags |= 0x20ui64;
  if ( !v4->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(v4);
}

// File Line: 1448
// RVA: 0x819B10
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> itr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // rcx
  unsigned int v5; // eax

  v2 = this;
  v3 = itr.pV;
  this->Flags ^= (LODWORD(this->Flags) ^ -((LODWORD(itr.pV->Flags) >> 2) & 1)) & 4;
  v4 = this->ITraits.pObject;
  if ( itr.pV != v4 )
  {
    if ( v4 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v2->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v4 - 1);
        v2->ITraits.pObject = itr.pV;
        return;
      }
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v2->ITraits.pObject = v3;
  }
}

// File Line: 1458
// RVA: 0x7F3C10
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::InitOnDemand(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v1; // rcx

  v1 = this->ITraits.pObject;
  if ( !v1->pConstructor.pObject )
    ((void (*)(void))v1->vfptr[3].~RefCountBaseGC<328>)();
}

// File Line: 1467
// RVA: 0x7D66F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::ForEachChild_GC(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
}

// File Line: 1474
// RVA: 0x80FFC0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v1; // r15
  const char **v2; // rsi
  signed __int64 v3; // r13
  Scaleform::GFx::AS3::VM *v4; // r14
  const char *v5; // r9
  const char *v6; // rax
  int v7; // ecx
  int v8; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rax
  const char *v10; // rax
  bool v11; // dl
  const char *v12; // r9
  bool v13; // al
  Scaleform::GFx::ASStringNode *v14; // rbx
  unsigned int v15; // ecx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // edx
  bool v17; // di
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::AS3::VMAbcFile *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // rcx
  unsigned int v25; // eax
  unsigned int v26; // ebx
  int v27; // ecx
  Scaleform::GFx::ASStringNode *v28; // rcx
  long double v29; // rcx
  int v30; // eax
  Scaleform::GFx::AS3::VM::Error *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v34; // rbx
  __int64 v35; // r12
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+30h] [rbp-99h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-69h]
  __int64 v38; // [rsp+80h] [rbp-49h]
  int v39; // [rsp+88h] [rbp-41h]
  __int16 v40; // [rsp+8Ch] [rbp-3Dh]
  char *v41; // [rsp+90h] [rbp-39h]
  char *v42; // [rsp+98h] [rbp-31h]
  __int64 v43; // [rsp+A0h] [rbp-29h]
  __int64 v44; // [rsp+A8h] [rbp-21h]
  Scaleform::GFx::AS3::VM::Error v45; // [rsp+B0h] [rbp-19h]
  Scaleform::GFx::ASStringNode *v46; // [rsp+C0h] [rbp-9h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v47; // [rsp+C8h] [rbp-1h]
  __int64 v48; // [rsp+D0h] [rbp+7h]
  Scaleform::GFx::AS3::CheckResult v49; // [rsp+130h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh]
  __int64 v51; // [rsp+140h] [rbp+77h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v52; // [rsp+148h] [rbp+7Fh]

  v48 = -2i64;
  v1 = this;
  v2 = &ti[0].NamespaceName;
  v51 = 3i64;
  v3 = 3i64;
  do
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v1->pVM->StringManagerRef->Builtins,
      &result,
      *(v2 - 1));
    v4 = v1->pVM;
    v5 = *v2;
    if ( *v2 && *v5 )
    {
      if ( v5 != Scaleform::GFx::AS3::NS_AS3 )
      {
        v6 = *v2;
        do
        {
          v7 = (unsigned __int8)v6[Scaleform::GFx::AS3::NS_AS3 - v5];
          v8 = *(unsigned __int8 *)v6 - v7;
          if ( *(unsigned __int8 *)v6 != v7 )
            break;
          ++v6;
        }
        while ( v7 );
        if ( v8 )
        {
          v9 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                 v1->pVM,
                 &v52,
                 (Scaleform::GFx::AS3::Abc::NamespaceKind)((_DWORD)v2[1] & 0xF),
                 v5)->pV;
          goto LABEL_25;
        }
      }
      v9 = v4->AS3Namespace.pObject;
    }
    else
    {
      v10 = Scaleform::GFx::AS3::fl::ObjectCI.Type->Name;
      v11 = !v10 || !*v10;
      v12 = Scaleform::GFx::AS3::fl::ObjectCI.Type->PkgName;
      v13 = !v12 || !*v12;
      if ( v11 && !v13 )
      {
        v9 = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
               v1->pVM,
               &v47,
               (Scaleform::GFx::AS3::Abc::NamespaceKind)((_DWORD)v2[1] & 0xF),
               v12)->pV;
        goto LABEL_25;
      }
      v9 = v4->PublicNamespace.pObject;
    }
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
LABEL_25:
    v.Flags = 5;
    v.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v.value.VNumber = v2 - 3;
    v14 = result.pNode;
    if ( result.pNode )
      ++result.pNode->RefCount;
    v46 = v14;
    v15 = *(_WORD *)&nsi & 0x8000 | 0xFFFF8000;
    nsi = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&nsi & 0x8000 | 0xFFFF8000);
    nsi.Padding01 = 0;
    nsi.pNs.pObject = v9;
    nsi.CTraits.pObject = 0i64;
    nsi.File.pObject = 0i64;
    nsi.TI = 0i64;
    if ( v14 )
      ++v14->RefCount;
    nsi.Name.pObject = v14;
    nsi = (Scaleform::GFx::AS3::SlotInfo)((v15 & 0xFFFFFFF4 | 4) & 0xFFFFFC0F);
    bt = 11;
    if ( (*((_DWORD *)v2 + 2) >> 4) & 3 )
    {
      if ( ((*((_DWORD *)v2 + 2) >> 4) & 3) == 1 )
      {
        bt = 12;
      }
      else if ( ((*((_DWORD *)v2 + 2) >> 4) & 3) == 2 )
      {
        bt = 13;
      }
    }
    v17 = Scaleform::GFx::AS3::Traits::RegisterWithVT(
            (Scaleform::GFx::AS3::Traits *)&v1->vfptr,
            &v49,
            &result,
            &nsi,
            &v,
            bt)->Result == 0;
    v18 = nsi.Name.pObject;
    if ( nsi.Name.pObject )
    {
      v19 = nsi.Name.pObject->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    v20 = nsi.File.pObject;
    if ( nsi.File.pObject )
    {
      if ( (_QWORD)nsi.File.pObject & 1 )
      {
        --nsi.File.pObject;
      }
      else
      {
        v21 = nsi.File.pObject->RefCount;
        if ( v21 & 0x3FFFFF )
        {
          nsi.File.pObject->RefCount = v21 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v20->vfptr);
        }
      }
    }
    v22 = nsi.CTraits.pObject;
    if ( nsi.CTraits.pObject )
    {
      if ( (_QWORD)nsi.CTraits.pObject & 1 )
      {
        --nsi.CTraits.pObject;
      }
      else
      {
        v23 = nsi.CTraits.pObject->RefCount;
        if ( v23 & 0x3FFFFF )
        {
          nsi.CTraits.pObject->RefCount = v23 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
        }
      }
    }
    v24 = nsi.pNs.pObject;
    if ( nsi.pNs.pObject )
    {
      if ( (_QWORD)nsi.pNs.pObject & 1 )
      {
        --nsi.pNs.pObject;
      }
      else
      {
        v25 = nsi.pNs.pObject->RefCount;
        if ( v25 & 0x3FFFFF )
        {
          nsi.pNs.pObject->RefCount = v25 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v24->vfptr);
        }
      }
    }
    if ( v14 )
    {
      v19 = v14->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    }
    v26 = v.Flags;
    v27 = v.Flags & 0x1F;
    if ( v27 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v.Flags = v26 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v27 )
        {
          case 10:
            v28 = v.value.VS._1.VStr;
            v19 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
            --v28->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v28);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            if ( !v.value.VS._1.VBool )
            {
              v29 = v.value.VNumber;
              goto LABEL_69;
            }
            --*(_QWORD *)&v.value.VNumber;
            break;
          case 16:
          case 17:
            if ( (_QWORD)v.value.VS._2.VObj & 1 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
              v29 = *(double *)&v.value.VS._2.VObj;
LABEL_69:
              if ( v29 != 0.0 )
              {
                v30 = *(_DWORD *)(*(_QWORD *)&v29 + 32i64);
                if ( v30 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = v30 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v29);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    if ( v17 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v45, eIllegalOverrideError, v4);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v31, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v32 = v45.Message.pNode;
      v19 = v45.Message.pNode->RefCount == 1;
      --v32->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
    }
    v33 = result.pNode;
    v19 = result.pNode->RefCount == 1;
    --v33->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    v2 += 6;
    --v3;
  }
  while ( v3 );
  v38 = 0i64;
  v39 = 0;
  v40 = 0;
  v41 = &customWorldMapCaption;
  v42 = &customWorldMapCaption;
  v43 = 0i64;
  v44 = 0i64;
  nsi = (Scaleform::GFx::AS3::SlotInfo)&v38;
  nsi.pNs.pObject = 0i64;
  nsi.CTraits.pObject = 0i64;
  nsi.File.pObject = 0i64;
  nsi.TI = 0i64;
  nsi.Name.pObject = 0i64;
  v34 = f;
  v35 = v51;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v1->vfptr,
      (Scaleform::GFx::AS3::ClassInfo *)&nsi,
      v34);
    ++v34;
    --v35;
  }
  while ( v35 );
  v1->FirstOwnSlotInd.Index += 6i64;
}

// File Line: 1489
// RVA: 0x7F8EF0
char __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::ClassTraits::Traits *other)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // rdi

  v2 = other;
  v3 = this;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v2->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v2->ITraits.pObject,
               v3->ITraits.pObject) )
    {
      v2 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v2->pParent.pObject;
      if ( v2 == v3 )
        break;
      if ( !v2 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 1515
// RVA: 0x7B6B10
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Coerce(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  return Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(this, value, result);
}

// File Line: 1520
// RVA: 0x7B6BF0
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rsi
  Scaleform::GFx::AS3::BuiltinTraitsType v6; // ecx
  Scaleform::GFx::AS3::Value *v7; // rbx
  bool v8; // al
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rdx

  v3 = result;
  v4 = this->pVM;
  v5 = this;
  v6 = this->TraitsType;
  v7 = value;
  switch ( value->Flags & 0x1F )
  {
    case 0u:
      Scaleform::GFx::AS3::Value::SetNull(v3);
      goto LABEL_3;
    case 1u:
      if ( v5 != (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject && v6 != 1 )
        goto LABEL_16;
      goto $LN19_39;
    case 2u:
      if ( v5 != (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject && v6 != 2 )
        goto LABEL_16;
      Scaleform::GFx::AS3::Value::SetSInt32(v3, value->value.VS._1.VInt);
      return 1;
    case 3u:
      if ( v5 != (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject && v6 != 3 )
        goto LABEL_16;
      Scaleform::GFx::AS3::Value::SetUInt32(v3, value->value.VS._1.VUInt);
      return 1;
    case 4u:
      if ( v5 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject || v6 == 4 )
        goto $LN19_39;
      return 0;
    case 5u:
    case 7u:
      if ( v5 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject || v6 == 10 )
        goto $LN19_39;
      goto LABEL_16;
    case 0xAu:
      if ( v5 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject || v6 == 5 )
        goto $LN19_39;
      return 0;
    case 0xBu:
      if ( v5 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->TraitsObject.pObject || v6 == 6 )
        goto $LN19_39;
      return 0;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      if ( !*(_QWORD *)&value->value.VNumber )
        goto LABEL_13;
      v9 = Scaleform::GFx::AS3::VM::GetClassTraits(v4, value);
      goto LABEL_29;
    case 0xDu:
      v9 = *(Scaleform::GFx::AS3::ClassTraits::Traits **)(*(_QWORD *)&value->value.VNumber + 40i64);
LABEL_29:
      if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(v5, v9) )
        goto $LN19_39;
LABEL_16:
      v8 = 0;
      break;
    case 0x10u:
    case 0x11u:
$LN19_39:
      value = v7;
LABEL_13:
      Scaleform::GFx::AS3::Value::Assign(v3, value);
      v8 = 1;
      break;
    default:
LABEL_3:
      v8 = 1;
      break;
  }
  return v8;
}

// File Line: 1624
// RVA: 0x7EC7D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ClassTraits::Traits::GetName(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  ((void (__cdecl *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *))this->ITraits.pObject->vfptr[1].~RefCountBaseGC<328>)(
    this->ITraits.pObject,
    result);
  return v2;
}

// File Line: 1629
// RVA: 0x7EE8B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ClassTraits::Traits::GetQualifiedName(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::ASString *result, __int64 f)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *, __int64))this->ITraits.pObject->vfptr[1].Finalize_GC)(
    this->ITraits.pObject,
    result,
    f);
  return v3;
}

