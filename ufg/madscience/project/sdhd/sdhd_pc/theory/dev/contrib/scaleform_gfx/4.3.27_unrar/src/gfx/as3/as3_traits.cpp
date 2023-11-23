// File Line: 59
// RVA: 0x7D7200
void __fastcall Scaleform::GFx::AS3::Slots::ForEachSlot(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::Slots::SlotFunct *f)
{
  unsigned __int64 FirstOwnSlotNum; // r9
  signed __int64 i; // rbx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax

  FirstOwnSlotNum = this->FirstOwnSlotNum;
  for ( i = 0i64; (unsigned int)i < this->FirstOwnSlotNum + this->VArray.Data.Size; FirstOwnSlotNum = this->FirstOwnSlotNum )
  {
    if ( i < 0 || i < FirstOwnSlotNum )
      SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)i);
    else
      SlotInfo = &this->VArray.Data.Data[(unsigned int)i - FirstOwnSlotNum].Value;
    f->vfptr->operator()(f, SlotInfo);
    if ( i < 0 || i < this->FirstOwnSlotNum + this->VArray.Data.Size )
      ++i;
  }
}

// File Line: 77
// RVA: 0x819CB0
void __fastcall Scaleform::GFx::AS3::Slots::SetKey(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::ASString *k)
{
  unsigned __int64 v4; // r12
  Scaleform::GFx::ASStringNode *pNode; // rbx
  unsigned __int64 v6; // rbp
  Scaleform::GFx::AS3::Slots::Pair *Data; // rdi
  Scaleform::GFx::ASStringNode *pObject; // rcx
  bool v9; // zf
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // r8
  unsigned __int64 SizeMask; // r10
  __int64 v12; // r9
  __int64 v13; // rdi
  unsigned __int64 *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v21; // [rsp+80h] [rbp+18h] BYREF

  v4 = LODWORD(ind.Index) - this->FirstOwnSlotNum;
  pNode = k->pNode;
  v6 = v4 << 6;
  Data = this->VArray.Data.Data;
  if ( Data[v4].Key.pObject != k->pNode )
  {
    if ( pNode )
      ++pNode->RefCount;
    pObject = Data[v4].Key.pObject;
    if ( pObject )
    {
      v9 = pObject->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    }
    Data[v4].Key.pObject = pNode;
    if ( pNode )
      ++pNode->RefCount;
    v20 = pNode;
    pTable = this->Set.mHash.pTable;
    if ( !pTable )
      goto LABEL_18;
    SizeMask = pTable->SizeMask;
    v12 = (unsigned int)SizeMask & pNode->HashFlags;
    v13 = v12;
    v14 = &pTable[v12 + 1].EntryCount + v12;
    if ( *v14 == -2i64 || ((unsigned int)SizeMask & *(_DWORD *)(v14[1] + 28)) != v12 )
      goto LABEL_18;
    while ( 1 )
    {
      v15 = (Scaleform::GFx::ASStringNode *)v14[1];
      if ( ((unsigned int)SizeMask & v15->HashFlags) == v12 && v15 == pNode )
        break;
      v13 = *v14;
      if ( *v14 == -1i64 )
        goto LABEL_18;
      v14 = &pTable[v13 + 1].EntryCount + v13;
    }
    if ( v13 >= 0 )
    {
      p_Set = &this->Set;
    }
    else
    {
LABEL_18:
      p_Set = 0i64;
      v13 = 0i64;
    }
    if ( pNode )
    {
      v9 = pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( p_Set && (v17 = p_Set->mHash.pTable) != 0i64 && v13 <= (signed __int64)v17->SizeMask )
    {
      *(__int64 *)((char *)&this->VArray.Data.Data->Prev + v6) = *((unsigned int *)&v17[2].EntryCount + 6 * v13);
      *((_DWORD *)&p_Set->mHash.pTable[2].EntryCount + 6 * v13) = v4 + LODWORD(this->FirstOwnSlotNum);
    }
    else
    {
      LODWORD(v20) = v4 + LODWORD(this->FirstOwnSlotNum);
      if ( pNode )
        ++pNode->RefCount;
      v21 = pNode;
      key.pFirst = (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&v21;
      key.pSecond = (const unsigned int *)&v20;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
        &this->Set.mHash,
        &this->Set,
        &key,
        pNode->HashFlags);
      v18 = v21;
      if ( v21 )
      {
        v9 = v21->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
      *(__int64 *)((char *)&this->VArray.Data.Data->Prev + v6) = -1i64;
    }
  }
}

// File Line: 107
// RVA: 0x7AAF40
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Slots::Add(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *k,
        Scaleform::GFx::AS3::SlotInfo *v)
{
  unsigned __int64 Size; // r15
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *pObject; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // r8
  unsigned __int64 SizeMask; // r10
  __int64 v14; // r9
  __int64 v15; // rdi
  unsigned __int64 *v16; // rdx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::HashUncachedLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,333> *p_Set; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef key; // [rsp+28h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::Slots::Pair val; // [rsp+38h] [rbp-80h] BYREF
  Scaleform::GFx::ASStringNode *v24; // [rsp+C0h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v25; // [rsp+C8h] [rbp+10h] BYREF

  Size = this->VArray.Data.Size;
  pNode = k->pNode;
  if ( k->pNode )
    ++pNode->RefCount;
  v24 = pNode;
  if ( pNode )
    ++pNode->RefCount;
  val.Key.pObject = pNode;
  val.Prev = -1i64;
  Scaleform::GFx::AS3::SlotInfo::SlotInfo(&val.Value, v);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->VArray.Data,
    &val);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&val.Value);
  pObject = val.Key.pObject;
  if ( val.Key.pObject )
  {
    v10 = val.Key.pObject->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  }
  if ( pNode )
  {
    v10 = pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v11 = k->pNode;
  if ( k->pNode )
    ++v11->RefCount;
  v24 = v11;
  pTable = this->Set.mHash.pTable;
  if ( !pTable )
    goto LABEL_22;
  SizeMask = pTable->SizeMask;
  v14 = (unsigned int)SizeMask & v11->HashFlags;
  v15 = v14;
  v16 = &pTable[v14 + 1].EntryCount + v14;
  if ( *v16 == -2i64 || ((unsigned int)SizeMask & *(_DWORD *)(v16[1] + 28)) != v14 )
    goto LABEL_22;
  while ( 1 )
  {
    v17 = (Scaleform::GFx::ASStringNode *)v16[1];
    if ( ((unsigned int)SizeMask & v17->HashFlags) == v14 && v17 == v11 )
      break;
    v15 = *v16;
    if ( *v16 == -1i64 )
      goto LABEL_22;
    v16 = &pTable[v15 + 1].EntryCount + v15;
  }
  if ( v15 >= 0 )
  {
    p_Set = &this->Set;
  }
  else
  {
LABEL_22:
    p_Set = 0i64;
    v15 = 0i64;
  }
  if ( v11 )
  {
    v10 = v11->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( p_Set && (v19 = p_Set->mHash.pTable) != 0i64 && v15 <= (signed __int64)v19->SizeMask )
  {
    this->VArray.Data.Data[Size].Prev = *((unsigned int *)&v19[2].EntryCount + 6 * v15);
    *((_DWORD *)&p_Set->mHash.pTable[2].EntryCount + 6 * v15) = Size + LODWORD(this->FirstOwnSlotNum);
  }
  else
  {
    LODWORD(v24) = Size + LODWORD(this->FirstOwnSlotNum);
    if ( v11 )
      ++v11->RefCount;
    v25 = v11;
    key.pFirst = (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)&v25;
    key.pSecond = (const unsigned int *)&v24;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeRef>(
      &this->Set.mHash,
      &this->Set,
      &key,
      v11->HashFlags);
    v20 = v25;
    if ( v25 )
    {
      v10 = v25->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
    this->VArray.Data.Data[Size].Prev = -1i64;
  }
  result->Index = Size + this->FirstOwnSlotNum;
  return result;
}

// File Line: 133
// RVA: 0x7D4060
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  const unsigned int *SlotValues; // rax
  unsigned __int64 Prev; // rbx
  __int64 v9; // rsi
  Scaleform::GFx::AS3::SlotInfo *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx

  SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(this, name);
  if ( SlotValues )
  {
    Prev = *SlotValues;
    v9 = (__int64)(*((_QWORD *)ns + 5) << 60) >> 60;
    while ( 1 )
    {
      v10 = Prev < this->FirstOwnSlotNum
          ? Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev)
          : &this->VArray.Data.Data[(unsigned int)Prev - this->FirstOwnSlotNum].Value;
      pObject = v10->pNs.pObject;
      if ( (int)(*((_DWORD *)pObject + 10) << 28) >> 28 == (_DWORD)v9 )
      {
        if ( (_DWORD)v9 == 1 )
          break;
        if ( (_DWORD)v9 == 3 ? ns == pObject : pObject->Uri.pNode == ns->Uri.pNode )
          break;
      }
      if ( Prev >= this->FirstOwnSlotNum )
        Prev = this->VArray.Data.Data[Prev - this->FirstOwnSlotNum].Prev;
      else
        Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(this->Parent, Prev);
      if ( (Prev & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_16;
    }
    result->Index = Prev;
  }
  else
  {
LABEL_16:
    result->Index = -1i64;
  }
  return result;
}

// File Line: 189
// RVA: 0x783480
void __fastcall Scaleform::GFx::AS3::Traits::Traits(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VM *_vm,
        Scaleform::GFx::AS3::Traits *pt,
        bool isDynamic,
        bool isFinal)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::GFx::AS3::Slots *v7; // rdi
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // eax
  Scaleform::MemoryHeap *MHeap; // rcx
  unsigned __int8 v10; // al
  Scaleform::GFx::AS3::Traits *pObject; // rax

  GC = _vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  v7 = &this->Scaleform::GFx::AS3::Slots;
  this->FirstOwnSlotNum = 0i64;
  this->Parent = 0i64;
  this->VArray.Data.Data = 0i64;
  this->VArray.Data.Size = 0i64;
  this->VArray.Data.Policy.Capacity = 0i64;
  this->Set.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable;
  this->FirstOwnSlotInd.Index = 0i64;
  this->FixedValueSlotNumber = 0i64;
  this->MemSize = 0;
  this->Flags = 0i64;
  if ( pt )
    TraitsType = pt->TraitsType;
  else
    TraitsType = Traits_Unknown;
  this->TraitsType = TraitsType;
  this->pVM = _vm;
  this->pConstructor.pObject = 0i64;
  this->pParent.pObject = pt;
  if ( pt )
    pt->RefCount = (pt->RefCount + 1) & 0x8FBFFFFF;
  this->pVTable.pObject = 0i64;
  this->pVTable.Owner = 1;
  MHeap = _vm->MHeap;
  this->InitScope.Data.Data = 0i64;
  this->InitScope.Data.Size = 0i64;
  this->InitScope.Data.Policy.Capacity = 0i64;
  this->InitScope.Data.pHeap = MHeap;
  if ( pt )
    v10 = pt->Flags & 1;
  else
    v10 = 0;
  this->Flags &= 0xFFFFFFFFFFFFFFBCui64;
  this->Flags |= (isDynamic ? 2 : 0) | (isFinal ? 0x40 : 0) | (unsigned __int64)(-v10 & 1);
  this->RefCount |= 0x8000000u;
  pObject = this->pParent.pObject;
  if ( pObject )
  {
    this->Parent = &pObject->Scaleform::GFx::AS3::Slots;
    v7->FirstOwnSlotNum = pObject->FirstOwnSlotNum + pObject->VArray.Data.Size;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Assign(
      &this->Set.mHash,
      &this->Set,
      &pObject->Set.mHash);
    this->FirstOwnSlotInd.Index = this->VArray.Data.Size + this->FirstOwnSlotNum;
    this->FixedValueSlotNumber = this->pParent.pObject->FixedValueSlotNumber;
  }
}

// File Line: 225
// RVA: 0x783390
void __fastcall Scaleform::GFx::AS3::Traits::Traits(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::VM *_vm)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::MemoryHeap *MHeap; // rcx

  GC = _vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->FirstOwnSlotNum = 0i64;
  this->Parent = 0i64;
  this->VArray.Data.Data = 0i64;
  this->VArray.Data.Size = 0i64;
  this->VArray.Data.Policy.Capacity = 0i64;
  this->Set.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable;
  this->FirstOwnSlotInd.Index = 0i64;
  this->FixedValueSlotNumber = 0i64;
  this->MemSize = 0;
  this->Flags = 0i64;
  this->TraitsType = Traits_Unknown;
  this->pVM = _vm;
  this->pConstructor.pObject = 0i64;
  this->pParent.pObject = 0i64;
  this->pVTable.pObject = 0i64;
  this->pVTable.Owner = 1;
  MHeap = _vm->MHeap;
  this->InitScope.Data.Data = 0i64;
  this->InitScope.Data.Size = 0i64;
  this->InitScope.Data.Policy.Capacity = 0i64;
  this->InitScope.Data.pHeap = MHeap;
  this->RefCount |= 0x8000000u;
}

// File Line: 239
// RVA: 0x78E900
void __fastcall Scaleform::GFx::AS3::Traits::~Traits(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_InitScope; // rbx
  Scaleform::GFx::AS3::VTable *pObject; // rcx
  Scaleform::GFx::AS3::Traits *v4; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v6; // rcx
  unsigned int v7; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Traits::`vftable;
  p_InitScope = &this->InitScope;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->InitScope.Data.Data,
    this->InitScope.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_InitScope->Data.Data);
  pObject = this->pVTable.pObject;
  if ( pObject )
  {
    if ( this->pVTable.Owner )
    {
      this->pVTable.Owner = 0;
      Scaleform::GFx::AS3::VTable::`scalar deleting destructor(pObject, 1u);
    }
    this->pVTable.pObject = 0i64;
  }
  this->pVTable.Owner = 0;
  v4 = this->pParent.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->pParent.pObject = (Scaleform::GFx::AS3::Traits *)((char *)v4 - 1);
    }
    else
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  v6 = this->pConstructor.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v6 - 1);
    }
    else
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Clear(&this->Set.mHash);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>(&this->VArray.Data);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 258
// RVA: 0x7B0410
__int64 __fastcall Scaleform::GFx::AS3::Traits::Alloc(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::VM *pVM; // rax
  unsigned __int64 MemSize; // rdx
  int v4; // [rsp+30h] [rbp+8h] BYREF

  pVM = this->pVM;
  MemSize = this->MemSize;
  v4 = 337;
  return (__int64)pVM->MHeap->vfptr->Alloc(pVM->MHeap, MemSize, (Scaleform::AllocInfo *)&v4);
}

// File Line: 288
// RVA: 0x820E80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::SetupSlotValues(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::HasTraits *t)
{
  Scaleform::GFx::AS3::Traits *v7; // r9
  Scaleform::GFx::AS3::VM *pVM; // r15
  __int64 v9; // rbx
  __int64 v10; // rcx
  Scaleform::GFx::AS3::Abc::File *pObject; // rdx
  Scaleform::GFx::AS3::Abc::ValueDetail *v12; // rdi
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // r14
  Scaleform::GFx::AS3::Value *DetailValue; // rax
  bool v15; // di
  bool v16; // zf
  Scaleform::GFx::AS3::Value *p_resulta; // rcx
  Scaleform::GFx::AS3::Abc::File *v18; // rdx
  __int64 ValueIndex; // rax
  Scaleform::GFx::AS3::Value *DefaultValue; // rax
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+30h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Abc::Multiname mn; // [rsp+38h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Abc::Multiname v24; // [rsp+48h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value v25; // [rsp+58h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [rsp+78h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::VM *v27; // [rsp+98h] [rbp+7h]
  __int64 v28; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::CheckResult v30; // [rsp+108h] [rbp+77h] BYREF

  v28 = -2i64;
  v7 = this;
  pVM = this->pVM;
  v27 = pVM;
  ++pVM->InInitializer;
  v9 = 0i64;
  if ( !t->obj_traits.Data.Size )
  {
LABEL_29:
    result->Result = 1;
    goto LABEL_30;
  }
  v10 = 0i64;
  while ( 1 )
  {
    pObject = file->File.pObject;
    v12 = (Scaleform::GFx::AS3::Abc::ValueDetail *)pObject->Traits.TraitInfos.Data.Data[t->obj_traits.Data.Data[v10]];
    if ( (v12->Kind & 0xF) != 0 && (v12->Kind & 0xF) != 6 )
      goto LABEL_26;
    mn = pObject->Const_Pool.const_multiname.Data.Data[v12->ValueIndex];
    SlotInfo = Scaleform::GFx::AS3::Traits::FindSlotInfo(v7, file, &mn);
    if ( SlotInfo )
      break;
LABEL_25:
    v7 = this;
LABEL_26:
    v10 = (unsigned int)++v9;
    if ( (unsigned int)v9 >= t->obj_traits.Data.Size )
      goto LABEL_29;
  }
  if ( v12[2].ValueIndex > 0 )
  {
    DetailValue = Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(file, &resulta, v12 + 2);
    v15 = !Scaleform::GFx::AS3::SlotInfo::SetSlotValue(SlotInfo, &v30, this->pVM, DetailValue)->Result;
    if ( (resulta.Flags & 0x1F) <= 9 )
      goto LABEL_24;
    if ( (resulta.Flags & 0x200) != 0 )
    {
      v16 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&resulta.Bonus, 0, 24);
      resulta.Flags &= 0xFFFFFDE0;
      goto LABEL_24;
    }
    p_resulta = &resulta;
LABEL_23:
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_resulta);
    goto LABEL_24;
  }
  v18 = file->File.pObject;
  if ( (v12->Kind & 0xF) == 0 || (v12->Kind & 0xF) == 6 )
    ValueIndex = v12[1].ValueIndex;
  else
    ValueIndex = v18->AS3_Classes.Info.Data.Data[v12[1].ValueIndex]->inst_info.name_ind;
  v24 = v18->Const_Pool.const_multiname.Data.Data[ValueIndex];
  DefaultValue = Scaleform::GFx::AS3::VM::GetDefaultValue(this->pVM, &v25, file, &v24);
  v15 = !Scaleform::GFx::AS3::SlotInfo::SetSlotValue(SlotInfo, &v22, this->pVM, DefaultValue)->Result;
  if ( (v25.Flags & 0x1F) > 9 )
  {
    if ( (v25.Flags & 0x200) == 0 )
    {
      p_resulta = &v25;
      goto LABEL_23;
    }
    v16 = v25.Bonus.pWeakProxy->RefCount-- == 1;
    if ( v16 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    memset(&v25.Bonus, 0, 24);
    v25.Flags &= 0xFFFFFDE0;
  }
LABEL_24:
  if ( !v15 )
    goto LABEL_25;
  result->Result = 0;
LABEL_30:
  --pVM->InInitializer;
  return result;
}

// File Line: 368
// RVA: 0x7D6670
void __fastcall Scaleform::GFx::AS3::Traits::ForEachChild_GC(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  Scaleform::GFx::AS3::VTable *pObject; // rcx

  Scaleform::GFx::AS3::Slots::ForEachChild_GC(&this->Scaleform::GFx::AS3::Slots, prcc, op);
  if ( this->pConstructor.pObject )
    op(prcc);
  if ( this->pParent.pObject )
    op(prcc);
  pObject = this->pVTable.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::VTable::ForEachChild_GC(
      pObject,
      prcc,
      (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op);
  Scaleform::GFx::AS3::ForEachChild_GC(
    prcc,
    &this->InitScope,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op);
}

// File Line: 388
// RVA: 0x7E6140
__int64 __fastcall Scaleform::GFx::AS3::Traits::GetBindingType(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rax
  __int64 result; // rax

  pVM = this->pVM;
  if ( !*(_QWORD *)&mn->NameIndex && !mn->Ind )
    return 2i64;
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(this->pVM, file, mn);
  if ( !v4 )
    return 2i64;
  switch ( v4->TraitsType )
  {
    case Traits_Boolean:
      result = 5i64;
      break;
    case Traits_SInt:
      result = 6i64;
      break;
    case Traits_UInt:
      result = 7i64;
      break;
    case Traits_Number:
      result = 8i64;
      break;
    case Traits_String:
      result = 9i64;
      break;
    case Traits_Function:
      return 2i64;
    default:
      result = (unsigned int)(v4 != pVM->TraitsObject.pObject) + 2;
      break;
  }
  return result;
}

// File Line: 442
// RVA: 0x7AEEE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlotsWithID(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file)
{
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::Traits *v7; // r11
  __int64 v8; // rdi
  __int64 v9; // r10
  Scaleform::GFx::AS3::Abc::File *pObject; // r9
  Scaleform::GFx::AS3::Abc::TraitInfo *ti; // r14
  int v12; // edx
  Scaleform::GFx::AS3::Abc::Multiname *v13; // rbp
  int SlotId; // ebx
  char BindingType; // si
  bool _const; // r15
  __int64 Ind; // r8
  unsigned int v18; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::SlotInfo *v20; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v22; // zf
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+C0h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+C8h] [rbp+20h]

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
    pObject = file->File.pObject;
    ti = pObject->Traits.TraitInfos.Data.Data[traits->obj_traits.Data.Data[v9]];
    v12 = ti->kind & 0xF;
    if ( (ti->kind & 0xF) != 0 && (unsigned int)(v12 - 4) > 2 )
      goto LABEL_23;
    v13 = &pObject->Const_Pool.const_multiname.Data.Data[ti->name_ind];
    SlotId = ti->SlotId;
    if ( !SlotId )
      goto LABEL_23;
    BindingType = 1;
    _const = 0;
    if ( (ti->kind & 0xF) == 0 )
      goto LABEL_15;
    switch ( v12 )
    {
      case 4:
        goto LABEL_12;
      case 5:
        BindingType = 2;
        break;
      case 6:
LABEL_12:
        _const = 1;
        if ( v12 == 6 )
LABEL_15:
          Ind = ti->Ind;
        else
          Ind = pObject->AS3_Classes.Info.Data.Data[ti->Ind]->inst_info.name_ind;
        BindingType = Scaleform::GFx::AS3::Traits::GetBindingType(
                        v7,
                        file,
                        &pObject->Const_Pool.const_multiname.Data.Data[Ind]);
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(file, &resulta, v13->NameIndex);
    v18 = SlotId - 1;
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v13);
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    v20 = Scaleform::GFx::AS3::Traits::AddSetSlot(
            this,
            (Scaleform::GFx::AS3::RelativeIndex)v18,
            &resulta,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)InternedNamespace,
            file,
            ti,
            _const);
    if ( (*(_DWORD *)v20 & 0x7C00) != 0 )
      break;
    *(_DWORD *)v20 = *(_DWORD *)v20 & 0x3FF | ((*(_DWORD *)&BindingType | 0xFFFFFFE0) << 10);
    pNode = resulta.pNode;
    v22 = resulta.pNode->RefCount-- == 1;
    if ( v22 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v7 = this;
LABEL_23:
    v9 = (unsigned int)++v8;
    if ( (unsigned int)v8 >= traits->obj_traits.Data.Size )
    {
      v6 = result;
      goto LABEL_31;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v26, 1053, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v23, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v24 = v26.Message.pNode;
  v22 = v26.Message.pNode->RefCount-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  result->Result = 0;
  v25 = resulta.pNode;
  v22 = resulta.pNode->RefCount-- == 1;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  return result;
}

// File Line: 548
// RVA: 0x7AF100
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file,
        bool members)
{
  Scaleform::GFx::AS3::Abc::HasTraits *v6; // r14
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  Scaleform::GFx::AS3::Traits *v8; // r10
  bool v9; // r12
  __int64 v10; // rbx
  __int64 v11; // r9
  bool v12; // r8
  Scaleform::GFx::AS3::Abc::File *pObject; // rdx
  Scaleform::GFx::AS3::Abc::TraitInfo *v14; // r14
  int v15; // ecx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // r15d
  Scaleform::GFx::AS3::Abc::Multiname *v17; // rsi
  unsigned __int64 FixedValueSlotNumber; // rdi
  Scaleform::GFx::AS3::Abc::File *v19; // r9
  __int64 Ind; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  unsigned int v22; // edx
  int v23; // eax
  unsigned int Flags; // edi
  bool v25; // zf
  Scaleform::GFx::AS3::Slots::Pair *v26; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::AS3::CheckResult v31; // [rsp+30h] [rbp-81h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+40h] [rbp-71h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+70h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+90h] [rbp-21h]
  Scaleform::GFx::AS3::VM::Error v36; // [rsp+98h] [rbp-19h] BYREF
  __int64 v37; // [rsp+A8h] [rbp-9h]
  __int64 v38; // [rsp+B0h] [rbp-1h]
  char v42; // [rsp+128h] [rbp+77h]

  v37 = -2i64;
  v6 = traits;
  v7 = result;
  v8 = this;
  v9 = 1;
  vm = file->VMRef;
  v10 = 0i64;
  if ( !traits->obj_traits.Data.Size )
    goto LABEL_46;
  v11 = 0i64;
  v12 = members;
  while ( 1 )
  {
    pObject = file->File.pObject;
    v14 = pObject->Traits.TraitInfos.Data.Data[v6->obj_traits.Data.Data[v11]];
    v15 = v14->kind & 0xF;
    if ( (v14->kind & 0xF) != 0 && (unsigned int)(v15 - 4) > 2 )
    {
      if ( v12 )
        goto LABEL_38;
    }
    else if ( !v12 || v14->SlotId )
    {
      goto LABEL_38;
    }
    bt = BT_ValueArray;
    v17 = &pObject->Const_Pool.const_multiname.Data.Data[v14->name_ind];
    if ( (unsigned int)(v15 - 1) > 2 )
    {
      FixedValueSlotNumber = v8->FixedValueSlotNumber;
      v8->FixedValueSlotNumber = FixedValueSlotNumber + 1;
    }
    else
    {
      LODWORD(FixedValueSlotNumber) = -1;
    }
    v42 = 0;
    switch ( v14->kind & 0xF )
    {
      case 0:
        goto $LN11_62;
      case 1:
        bt = BT_Code;
        break;
      case 2:
        bt = BT_Get;
        break;
      case 3:
        bt = BT_Set;
        break;
      case 4:
      case 6:
        v42 = 1;
$LN11_62:
        v19 = file->File.pObject;
        if ( (v14->kind & 0xF) == 0 || (v14->kind & 0xF) == 6 )
          Ind = v14->Ind;
        else
          Ind = v19->AS3_Classes.Info.Data.Data[v14->Ind]->inst_info.name_ind;
        bt = Scaleform::GFx::AS3::Traits::GetBindingType(v8, file, &v19->Const_Pool.const_multiname.Data.Data[Ind]);
        break;
      case 5:
        bt = BT_Value;
        break;
      default:
        break;
    }
    Scaleform::GFx::AS3::VMFile::GetInternedString(file, &resulta, v17->NameIndex);
    InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v17);
    v38 = 0i64;
    if ( InternedNamespace )
      InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
    v22 = (v42 != 0) + 2;
    *(_DWORD *)&nsi = *(_WORD *)&nsi & 0x8000 | 0xFFFF8000;
    nsi.Padding01 = 0;
    nsi.pNs.pObject = InternedNamespace;
    nsi.CTraits.pObject = 0i64;
    nsi.File.pObject = file;
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
    nsi.TI = v14;
    nsi.Name.pObject = 0i64;
    *(_DWORD *)&nsi = *(_DWORD *)&nsi & 0xFFFFFC00 | v22 & 1 | (4 * ((v22 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v22 >> 2) & 1)) & 0xFFFFFC3F | (((v22 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v22 >> 4) & 1) << 8);
    if ( (v14->kind & 0xFu) - 1 <= 2 )
    {
      v23 = v14->Ind;
      v.Flags = 2;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VInt = v23;
      v9 = Scaleform::GFx::AS3::Traits::RegisterWithVT(this, &v31, &resulta, &nsi, &v, bt)->Result;
      Flags = v.Flags;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          v25 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v25 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v.Bonus, 0, 24);
          v.Flags = Flags & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
      }
      goto LABEL_34;
    }
    v26 = &this->VArray.Data.Data[LODWORD(Scaleform::GFx::AS3::Slots::Add(
                                            &this->Scaleform::GFx::AS3::Slots,
                                            (Scaleform::GFx::AS3::AbsoluteIndex *)&v36,
                                            &resulta,
                                            &nsi)->Index)
                                - this->FirstOwnSlotNum];
    if ( (*(_DWORD *)&v26->Value & 0x7C00) != 0 )
      break;
    *(_DWORD *)&v26->Value = *(_DWORD *)&v26->Value & 0x3FF | ((bt & 0x1F | (32 * (_DWORD)FixedValueSlotNumber)) << 10);
LABEL_34:
    if ( !v9 )
      goto LABEL_41;
    Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
    pNode = resulta.pNode;
    v25 = resulta.pNode->RefCount-- == 1;
    if ( v25 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = members;
    v8 = this;
LABEL_38:
    v11 = (unsigned int)++v10;
    v6 = traits;
    if ( (unsigned int)v10 >= traits->obj_traits.Data.Size )
      goto LABEL_45;
  }
  v9 = 0;
LABEL_41:
  Scaleform::GFx::AS3::VM::Error::Error(&v36, 1053, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v28, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v29 = v36.Message.pNode;
  v25 = v36.Message.pNode->RefCount-- == 1;
  if ( v25 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  v30 = resulta.pNode;
  v25 = resulta.pNode->RefCount-- == 1;
  if ( v25 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
LABEL_45:
  v7 = result;
LABEL_46:
  v7->Result = v9;
  return v7;
}

// File Line: 673
// RVA: 0x7AEE00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::AddSlots(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Abc::HasTraits *traits,
        Scaleform::GFx::AS3::VMAbcFile *file,
        unsigned int parent_size)
{
  unsigned int v6; // ebx
  bool v10; // di
  Scaleform::GFx::AS3::CheckResult *v11; // rax
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+31h] [rbp-27h] BYREF
  unsigned int v14; // [rsp+34h] [rbp-24h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+68h] [rbp+10h] BYREF

  v6 = 1;
  v14 = 1;
  v10 = 0;
  if ( Scaleform::GFx::AS3::Traits::AddSlotsWithID(this, &resulta, traits, file)->Result )
  {
    v6 = 3;
    v14 = 3;
    if ( Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(this, &v12, traits, file, 1)->Result )
    {
      v6 = 7;
      v14 = 7;
      if ( Scaleform::GFx::AS3::Traits::AddSlotsWithoutID(this, &v13, traits, file, 0)->Result )
        v10 = 1;
    }
  }
  if ( (v6 & 4) != 0 )
  {
    v6 &= ~4u;
    v14 = v6;
  }
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v14 = v6;
  }
  if ( (v6 & 1) != 0 )
    v14 = v6 & 0xFFFFFFFE;
  if ( v10 )
    Scaleform::GFx::AS3::Traits::CalculateMemSize(this, parent_size);
  v11 = result;
  result->Result = v10;
  return v11;
}

// File Line: 698
// RVA: 0x7AA410
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::SlotInfo *si,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // rax
  __int64 v8; // rbx
  int v9; // edi
  __int64 v10; // rbx
  int v11; // edi
  int v12; // eax
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+48h] [rbp+10h] BYREF

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v8 = *(_DWORD *)si;
  v9 = v8 & 0xFFFFFCFF | 0x100;
  v10 = v8 >> 15;
  *(_DWORD *)si = v9;
  if ( v10 < 0 )
  {
    *(_DWORD *)si = *(_DWORD *)si & 0x3FF | ((new_bt & 0x1F | (32
                                                             * (unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                               VT,
                                                                               &result,
                                                                               v,
                                                                               new_bt)->Index)) << 10);
    return;
  }
  v11 = v9 << 17 >> 27;
  if ( v11 != 11 || new_bt == BT_Code )
  {
    Scaleform::GFx::AS3::VTable::SetMethod(VT, (Scaleform::GFx::AS3::AbsoluteIndex)v10, v, new_bt);
    v12 = v11;
    if ( v11 == 12 )
    {
      if ( new_bt != BT_Set )
      {
LABEL_10:
        if ( v12 != v11 )
        {
          *(_DWORD *)si &= 0x3FFu;
          *(_DWORD *)si |= (v12 & 0x1F | (32 * (_DWORD)v10)) << 10;
        }
        return;
      }
    }
    else
    {
      if ( v11 != 13 )
        return;
      if ( new_bt != BT_Get )
        goto LABEL_10;
    }
    v12 = 14;
    goto LABEL_10;
  }
}

// File Line: 749
// RVA: 0x8295A0
void __fastcall Scaleform::GFx::AS3::Traits::UpdateVT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::SlotInfo *si,
        Scaleform::GFx::AS3::Value *v,
        int new_bt)
{
  Scaleform::GFx::AS3::VTable *VT; // rax
  __int64 v8; // rdx
  int v9; // ecx
  __int64 v10; // rdx

  VT = Scaleform::GFx::AS3::Traits::GetVT(this);
  v8 = *(_DWORD *)si;
  v9 = (int)((_DWORD)v8 << 17) >> 27;
  v10 = v8 >> 15;
  if ( v9 != 11 || new_bt == 11 )
    Scaleform::GFx::AS3::VTable::SetMethod(VT, (Scaleform::GFx::AS3::AbsoluteIndex)v10, v, new_bt);
}

// File Line: 790
// RVA: 0x7B2420
void __fastcall Scaleform::GFx::AS3::Traits::CalculateMemSize(
        Scaleform::GFx::AS3::Traits *this,
        unsigned int parent_size)
{
  unsigned __int64 FirstOwnSlotNum; // r14
  unsigned __int64 v4; // r12
  int v5; // r13d
  int v6; // r15d
  int v7; // ebp
  int v8; // esi
  unsigned __int64 Index_low; // rcx
  __int64 v10; // rbx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax
  int v12; // eax
  unsigned int v13; // r11d
  unsigned int v14; // r9d
  unsigned int v15; // r10d
  unsigned __int64 v16; // rdx
  unsigned int v17; // r14d
  unsigned int v18; // r10d
  unsigned int v19; // r9d
  unsigned int v20; // r11d
  Scaleform::GFx::AS3::Slots::Pair *v21; // rbx
  int Value; // r8d
  int v23; // eax

  this->MemSize = parent_size;
  FirstOwnSlotNum = this->FirstOwnSlotNum;
  v4 = FirstOwnSlotNum + this->VArray.Data.Size;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  Index_low = LODWORD(this->FirstOwnSlotInd.Index);
  v10 = (unsigned int)Index_low;
  if ( Index_low < v4 )
  {
    do
    {
      if ( v10 < 0 || v10 < FirstOwnSlotNum )
        SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v10);
      else
        SlotInfo = &this->VArray.Data.Data[(unsigned int)v10 - FirstOwnSlotNum].Value;
      v12 = *(_DWORD *)SlotInfo;
      if ( (v12 & 0x300) == 0 )
      {
        switch ( v12 << 17 >> 27 )
        {
          case 2:
            ++v8;
            break;
          case 3:
          case 8:
          case 9:
            ++v7;
            break;
          case 5:
            ++v5;
            break;
          case 6:
          case 7:
            ++v6;
            break;
          default:
            break;
        }
      }
      ++v10;
    }
    while ( v10 < v4 );
    LODWORD(Index_low) = this->FirstOwnSlotInd.Index;
  }
  if ( v8 + v7 + v6 + v5 )
  {
    v13 = parent_size + v5;
    if ( v6 )
      v13 = (v13 + 3) & 0xFFFFFFFC;
    v14 = v13 + 4 * v6;
    if ( v7 )
      v14 = (v14 + 7) & 0xFFFFFFF8;
    v15 = v14 + 8 * v7;
    if ( v8 )
      v15 = (v15 + 31) & 0xFFFFFFE0;
    this->MemSize = v15 + 32 * v8;
    v16 = (unsigned int)Index_low;
    if ( (unsigned int)Index_low < v4 )
    {
      v17 = parent_size << 15;
      v18 = v15 << 15;
      v19 = v14 << 15;
      v20 = v13 << 15;
      do
      {
        v21 = &this->VArray.Data.Data[(unsigned int)v16 - this->FirstOwnSlotNum];
        Value = (int)v21->Value;
        if ( (Value & 0x300) == 0 )
        {
          switch ( Value << 17 >> 27 )
          {
            case 2:
              v23 = v18 ^ ((unsigned __int16)Value ^ (unsigned __int16)v18) & 0x7FFF;
              v18 += 0x100000;
              goto LABEL_29;
            case 3:
            case 8:
            case 9:
              v23 = v19 ^ ((unsigned __int16)Value ^ (unsigned __int16)v19) & 0x7FFF;
              v19 += 0x40000;
              goto LABEL_29;
            case 5:
              v23 = v17 ^ ((unsigned __int16)Value ^ (unsigned __int16)v17) & 0x7FFF;
              v17 += 0x8000;
              goto LABEL_29;
            case 6:
            case 7:
              v23 = v20 ^ ((unsigned __int16)Value ^ (unsigned __int16)v20) & 0x7FFF;
              v20 += 0x20000;
LABEL_29:
              *(_DWORD *)&v21->Value = v23;
              break;
            default:
              break;
          }
        }
        ++v16;
      }
      while ( v16 < v4 );
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
}

// File Line: 936
// RVA: 0x7EA2E0
__int64 __fastcall Scaleform::GFx::AS3::IntervalTimer::GetId(Scaleform::GFx::AS2::IntervalTimer *this)
{
  return (unsigned int)this->Id;
}

// File Line: 946
// RVA: 0x8164D0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::TypeInfo *Parent; // r9
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // [rsp+68h] [rbp+20h]

  Parent = ci->Type->Parent;
  if ( !Parent )
    return 0i64;
  pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(vm, &result, NS_Public, Parent->PkgName)->pV;
  v15 = pV;
  ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  vm->StringManagerRef,
                  (Scaleform::GFx::ASString *)&result,
                  ci->Type->Parent->Name);
  v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, ConstString, pV, appDomain);
  v10 = (Scaleform::GFx::ASStringNode *)result.pV;
  if ( LODWORD(result.pV->pPrev)-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( !pV )
    return v9;
  if ( ((unsigned __int8)pV & 1) != 0 )
  {
    v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV - 1);
    return v9;
  }
  RefCount = pV->RefCount;
  if ( (RefCount & 0x3FFFFF) == 0 )
    return v9;
  pV->RefCount = RefCount - 1;
  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
  return v9;
}

// File Line: 970
// RVA: 0x822580
void __fastcall Scaleform::GFx::AS3::Traits::StoreScopeStack(
        Scaleform::GFx::AS3::Traits *this,
        unsigned __int64 baseSSInd,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 v6; // r8
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_InitScope; // rdi
  unsigned __int64 v8; // rsi
  unsigned __int64 i; // rbp
  Scaleform::GFx::AS3::Value *Data; // rbx
  __int64 v11; // rdx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  Size = ss->Data.Size;
  v6 = Size + this->InitScope.Data.Size;
  p_InitScope = &this->InitScope;
  if ( v6 > this->InitScope.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->InitScope.Data,
      (__int64 *)this->InitScope.Data.pHeap,
      v6);
  if ( baseSSInd < Size )
  {
    v8 = baseSSInd;
    for ( i = Size - baseSSInd; i; --i )
    {
      Data = ss->Data.Data;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &p_InitScope->Data,
        (__int64 *)p_InitScope->Data.pHeap,
        p_InitScope->Data.Size + 1);
      v11 = (__int64)&p_InitScope->Data.Data[p_InitScope->Data.Size - 1];
      if ( !v11 )
        goto LABEL_18;
      *(_DWORD *)v11 = Data[v8].Flags;
      *(_QWORD *)(v11 + 8) = Data[v8].Bonus.pWeakProxy;
      *(_QWORD *)(v11 + 16) = Data[v8].value.VS._1.VStr;
      *(_QWORD *)(v11 + 24) = Data[v8].value.VS._2.VObj;
      Flags = Data[v8].Flags;
      if ( (Flags & 0x1F) <= 9 )
        goto LABEL_18;
      if ( (Flags & 0x200) != 0 )
      {
        ++Data[v8].Bonus.pWeakProxy->RefCount;
      }
      else if ( (Data[v8].Flags & 0x1F) == 10 )
      {
        ++Data[v8].value.VS._1.VStr->RefCount;
      }
      else if ( (Data[v8].Flags & 0x1F) > 0xA )
      {
        if ( (Data[v8].Flags & 0x1F) <= 0xF )
        {
          VObj = Data[v8].value.VS._1;
LABEL_15:
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
          goto LABEL_18;
        }
        if ( (Data[v8].Flags & 0x1F) <= 0x11 )
        {
          VObj = (Scaleform::GFx::AS3::Value::V1U)Data[v8].value.VS._2.VObj;
          goto LABEL_15;
        }
      }
LABEL_18:
      ++v8;
    }
  }
}

// File Line: 981
// RVA: 0x7AE520
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Traits::AddSetSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::RelativeIndex ind,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::TraitInfo *ti,
        bool _const)
{
  __int64 Index; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *pObject; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v14; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // rcx
  unsigned int v19; // eax
  Scaleform::GFx::AS3::AbsoluteIndex v21; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > nsa; // [rsp+C8h] [rbp+48h]

  nsa.pV = ns.pV;
  Index = LODWORD(this->FirstOwnSlotInd.Index) + (unsigned __int64)LODWORD(ind.Index);
  if ( (unsigned int)Index > this->FirstOwnSlotNum + this->VArray.Data.Size )
  {
    do
    {
      *(_DWORD *)&v = *(_WORD *)&v & 0x8000 | 0xFFFF8000;
      memset(&v.Padding01, 0, 44);
      v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
              this->pVM->StringManagerRef,
              &result);
      Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &v21, v10, &v);
      pNode = result.pNode;
      v12 = result.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      pObject = v.Name.pObject;
      if ( v.Name.pObject )
      {
        v12 = v.Name.pObject->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
      }
      v14 = v.File.pObject;
      if ( v.File.pObject )
      {
        if ( ((__int64)v.File.pObject & 1) != 0 )
        {
          --v.File.pObject;
        }
        else
        {
          RefCount = v.File.pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v.File.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
          }
        }
      }
      v16 = v.CTraits.pObject;
      if ( v.CTraits.pObject )
      {
        if ( ((__int64)v.CTraits.pObject & 1) != 0 )
        {
          --v.CTraits.pObject;
        }
        else
        {
          v17 = v.CTraits.pObject->RefCount;
          if ( (v17 & 0x3FFFFF) != 0 )
          {
            v.CTraits.pObject->RefCount = v17 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
          }
        }
      }
      v18 = v.pNs.pObject;
      if ( v.pNs.pObject )
      {
        if ( ((__int64)v.pNs.pObject & 1) != 0 )
        {
          --v.pNs.pObject;
        }
        else
        {
          v19 = v.pNs.pObject->RefCount;
          if ( (v19 & 0x3FFFFF) != 0 )
          {
            v.pNs.pObject->RefCount = v19 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
          }
        }
      }
    }
    while ( (unsigned int)Index > this->VArray.Data.Size + this->FirstOwnSlotNum );
    ns.pV = nsa.pV;
  }
  if ( (unsigned int)Index == this->VArray.Data.Size + this->FirstOwnSlotNum )
    Index = Scaleform::GFx::AS3::Traits::AddSlot(
              this,
              (Scaleform::GFx::AS3::AbsoluteIndex *)&result,
              name,
              ns,
              file,
              ti,
              _const)->Index;
  else
    Scaleform::GFx::AS3::Traits::SetSlot(this, (Scaleform::GFx::AS3::AbsoluteIndex)Index, name, ns, file, ti, _const);
  return &this->VArray.Data.Data[(unsigned int)Index - this->FirstOwnSlotNum].Value;
}me, ns, file, ti, _const);
  return &this->VArray.Data.Data[(unsigned 

// File Line: 1019
// RVA: 0x7AE890
void __fastcall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        Scaleform::GFx::AS3::AbsoluteIndex offset,
        bool const_)
{
  char v6; // di
  unsigned int v8; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Slots::Pair *v11; // rdx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+80h] [rbp+20h] BYREF
  Scaleform::GFx::ASStringNode *v14; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // [rsp+90h] [rbp+30h]

  pV = ns.pV;
  v6 = dt;
  v8 = const_ + 2;
  pNode = name->pNode;
  if ( name->pNode )
    ++pNode->RefCount;
  v14 = pNode;
  *(_DWORD *)&v = *(_WORD *)&v & 0x8000 | 0xFFFF8000;
  v.Padding01 = 0;
  v.pNs.pObject = pV;
  memset(&v.CTraits, 0, 24);
  if ( pNode )
    ++pNode->RefCount;
  v.Name.pObject = pNode;
  *(_DWORD *)&v = v8 & 1 | *(_DWORD *)&v & 0xFFFFFC00 | (4 * ((v8 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v8 >> 2) & 1)) & 0xFFFFFC3F | (((v8 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8);
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v11 = &this->VArray.Data.Data[LODWORD(result.Index) - this->FirstOwnSlotNum];
  *(_DWORD *)&v11->Value &= 0xFFFF83FF;
  *(_DWORD *)&v11->Value |= (v6 & 0x1F) << 10;
  *(_DWORD *)&v11->Value = (LODWORD(offset.Index) << 15) | *(_DWORD *)&v11->Value & 0x7FFF;
}

// File Line: 1037
// RVA: 0x7AE720
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::TraitInfo *ti,
        bool const_)
{
  unsigned int v8; // r9d
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h] BYREF

  pNode = name->pNode;
  if ( name->pNode )
    ++pNode->RefCount;
  *(_DWORD *)&v = *(_WORD *)&v & 0x8000 | 0xFFFF8000;
  v.Padding01 = 0;
  v.pNs.pObject = ns.pV;
  v.CTraits.pObject = 0i64;
  v.File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  v.TI = ti;
  if ( pNode )
    ++pNode->RefCount;
  v.Name.pObject = pNode;
  v8 = const_ + 2;
  *(_DWORD *)&v = v8 & 1 | *(_DWORD *)&v & 0xFFFFFC00 | (4 * ((v8 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v8 >> 2) & 1)) & 0xFFFFFC3F | (((v8 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8);
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return result;
}

// File Line: 1053
// RVA: 0x7AEC80
void __fastcall Scaleform::GFx::AS3::Traits::AddSlotCPP(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt,
        Scaleform::GFx::AS3::AbsoluteIndex offset,
        bool const_)
{
  unsigned int v8; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Slots::Pair *v11; // rdx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+80h] [rbp+20h] BYREF
  Scaleform::GFx::ASStringNode *v14; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // [rsp+90h] [rbp+30h]

  pV = ns.pV;
  v8 = (const_ + 2) | 0x10;
  pNode = name->pNode;
  if ( name->pNode )
    ++pNode->RefCount;
  v14 = pNode;
  *(_DWORD *)&v = *(_WORD *)&v & 0x8000 | 0xFFFF8000;
  v.Padding01 = 0;
  v.pNs.pObject = pV;
  v.CTraits.pObject = tr;
  if ( tr )
    tr->RefCount = (tr->RefCount + 1) & 0x8FBFFFFF;
  v.File.pObject = 0i64;
  v.TI = 0i64;
  if ( pNode )
    ++pNode->RefCount;
  v.Name.pObject = pNode;
  *(_DWORD *)&v = v8 & 1 | *(_DWORD *)&v & 0xFFFFFC00 | (4 * ((v8 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v8 >> 2) & 1)) & 0xFFFFFC3F | (((v8 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v8 >> 4) & 1) << 8);
  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &result, name, &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v11 = &this->VArray.Data.Data[LODWORD(result.Index) - this->FirstOwnSlotNum];
  *(_DWORD *)&v11->Value &= 0xFFFF83FF;
  *(_DWORD *)&v11->Value |= (dt & 0x1F) << 10;
  *(_DWORD *)&v11->Value = (LODWORD(offset.Index) << 15) | *(_DWORD *)&v11->Value & 0x7FFF;
}

// File Line: 1072
// RVA: 0x7AEA10
void __fastcall Scaleform::GFx::AS3::Traits::AddSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::MemberInfo *mi)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rdi
  int v6; // r8d
  unsigned int v7; // esi
  const char *NamespaceName; // r9
  const char *v9; // rax
  int v10; // edx
  int v11; // r10d
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::ASString *EmptyString; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::AS3::Slots::Pair *v17; // rdx
  int v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::ASString k; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [rsp+98h] [rbp+38h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v23; // [rsp+A0h] [rbp+40h] BYREF

  pVM = this->pVM;
  StringManagerRef = pVM->StringManagerRef;
  v6 = *((_DWORD *)mi + 4);
  v7 = (v6 & 0x2000000 | 0x24000000u) >> 25;
  NamespaceName = mi->NamespaceName;
  if ( NamespaceName && *NamespaceName )
  {
    if ( NamespaceName != Scaleform::GFx::AS3::NS_AS3 )
    {
      v9 = mi->NamespaceName;
      do
      {
        v10 = (unsigned __int8)v9[Scaleform::GFx::AS3::NS_AS3 - NamespaceName];
        v11 = *(unsigned __int8 *)v9 - v10;
        if ( v11 )
          break;
        ++v9;
      }
      while ( v10 );
      if ( v11 )
      {
        pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
               this->pVM,
               &result,
               (Scaleform::GFx::AS3::Abc::NamespaceKind)(v6 << 12 >> 28),
               NamespaceName)->pV;
        goto LABEL_16;
      }
    }
    pV = pVM->AS3Namespace.pObject;
    goto LABEL_12;
  }
  if ( (v6 & 0xF0000) == 0 )
  {
    pV = pVM->PublicNamespace.pObject;
LABEL_12:
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    goto LABEL_16;
  }
  EmptyString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                  StringManagerRef,
                  (Scaleform::GFx::ASString *)&result);
  pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
         pVM,
         &v23,
         (Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(*((_DWORD *)mi + 4) << 12) >> 28),
         EmptyString)->pV;
  v14 = (Scaleform::GFx::ASStringNode *)result.pV;
  v15 = LODWORD(result.pV->pPrev)-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_16:
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    StringManagerRef,
    &k,
    mi->Name);
  pNode = k.pNode;
  if ( k.pNode )
    ++k.pNode->RefCount;
  v23.pV = (Scaleform::GFx::AS3::Instances::fl::Namespace *)pNode;
  *(_DWORD *)&v = *(_WORD *)&v & 0x8000 | 0xFFFF8000;
  v.Padding01 = 0;
  v.pNs.pObject = pV;
  memset(&v.CTraits, 0, 24);
  if ( pNode )
    ++pNode->RefCount;
  v.Name.pObject = pNode;
  *(_DWORD *)&v = v7 & 1 | *(_DWORD *)&v & 0xFFFFFC00 | (4 * ((v7 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v7 >> 2) & 1)) & 0xFFFFFC3F | (((v7 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v7 >> 4) & 1) << 8);
  Scaleform::GFx::AS3::Slots::Add(
    &this->Scaleform::GFx::AS3::Slots,
    (Scaleform::GFx::AS3::AbsoluteIndex *)&result,
    &k,
    &v);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
  if ( pNode )
  {
    v15 = pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v17 = &this->VArray.Data.Data[LODWORD(result.pV) - this->FirstOwnSlotNum];
  v18 = *((_DWORD *)mi + 4);
  *(_DWORD *)&v17->Value &= 0x3FFu;
  *(_DWORD *)&v17->Value |= ((v18 << 7 >> 27) & 0x1F | (32 * (unsigned __int16)v18)) << 10;
  v19 = k.pNode;
  v15 = k.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
} k.pNode;
  v15 = k.pNode->RefCount-- == 1;
  if (

// File Line: 1114
// RVA: 0x7AA580
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::ClassInfo *ci,
        Scaleform::GFx::AS3::ThunkInfo *func)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  const char *NamespaceName; // r9
  const char *v8; // rax
  int v9; // ecx
  int v10; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rax
  const char *Name; // rax
  bool v13; // cl
  bool v14; // al
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // edx
  bool v17; // si
  bool v18; // zf
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+58h] [rbp-1h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v25; // [rsp+C0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D0h] [rbp+77h] BYREF
  Scaleform::GFx::ASStringNode *v27; // [rsp+D8h] [rbp+7Fh]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->pVM->StringManagerRef,
    &result,
    func->Name);
  pVM = this->pVM;
  NamespaceName = func->NamespaceName;
  if ( NamespaceName && *NamespaceName )
  {
    if ( NamespaceName != Scaleform::GFx::AS3::NS_AS3 )
    {
      v8 = func->NamespaceName;
      do
      {
        v9 = (unsigned __int8)v8[Scaleform::GFx::AS3::NS_AS3 - NamespaceName];
        v10 = *(unsigned __int8 *)v8 - v9;
        if ( v10 )
          break;
        ++v8;
      }
      while ( v9 );
      if ( v10 )
      {
LABEL_8:
        pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
               this->pVM,
               &v25,
               (Scaleform::GFx::AS3::Abc::NamespaceKind)(*((_DWORD *)func + 8) & 0xF),
               NamespaceName)->pV;
        goto LABEL_23;
      }
    }
    pV = pVM->AS3Namespace.pObject;
  }
  else
  {
    Name = ci->Type->Name;
    v13 = !Name || !*Name;
    NamespaceName = ci->Type->PkgName;
    v14 = !NamespaceName || !*NamespaceName;
    if ( v13 && !v14 )
      goto LABEL_8;
    pV = pVM->PublicNamespace.pObject;
  }
  if ( pV )
    pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
LABEL_23:
  v.Flags = 5;
  v.Bonus.pWeakProxy = 0i64;
  v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)func;
  pNode = result.pNode;
  if ( result.pNode )
    ++result.pNode->RefCount;
  v27 = pNode;
  *(_DWORD *)&nsi = *(_WORD *)&nsi & 0x8000 | 0xFFFF8000;
  nsi.Padding01 = 0;
  nsi.pNs.pObject = pV;
  memset(&nsi.CTraits, 0, 24);
  if ( pNode )
    ++pNode->RefCount;
  nsi.Name.pObject = pNode;
  *(_DWORD *)&nsi = *(_DWORD *)&nsi & 0xFFFFFC00 | 4;
  bt = BT_Code;
  if ( ((*((_DWORD *)func + 8) >> 4) & 3) != 0 )
  {
    if ( ((*((_DWORD *)func + 8) >> 4) & 3) == 1 )
    {
      bt = BT_Get;
    }
    else if ( ((*((_DWORD *)func + 8) >> 4) & 3) == 2 )
    {
      bt = BT_Set;
    }
  }
  v17 = !Scaleform::GFx::AS3::Traits::RegisterWithVT(
           this,
           (Scaleform::GFx::AS3::CheckResult *)&v25,
           &result,
           &nsi,
           &v,
           bt)->Result;
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&nsi);
  if ( pNode )
  {
    v18 = pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Flags = v.Flags;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      v18 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
  if ( v17 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v, 1053, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v20, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v.Bonus.pWeakProxy;
    v18 = LODWORD(v.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  v22 = result.pNode;
  v18 = result.pNode->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 1161
// RVA: 0x829490
void __fastcall Scaleform::GFx::AS3::Traits::UpdateVT4IM(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *mn_name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns,
        Scaleform::GFx::AS3::Value *v,
        int bt)
{
  __int64 Prev; // rbx
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::AS3::SlotInfo *v9; // rsi
  unsigned __int64 v10; // rax
  Scaleform::GFx::AS3::VTable *VT; // rax
  __int64 v12; // rdx
  int v13; // ecx
  __int64 v14; // rdx

  if ( mn_ns == this->pVM->PublicNamespace.pObject )
  {
    Prev = *(unsigned int *)Scaleform::GFx::AS3::Slots::FindSlotValues(&this->Scaleform::GFx::AS3::Slots, mn_name);
    while ( 1 )
    {
      FirstOwnSlotNum = this->FirstOwnSlotNum;
      v9 = Prev < FirstOwnSlotNum
         ? Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev)
         : &this->VArray.Data.Data[(unsigned int)Prev - FirstOwnSlotNum].Value;
      if ( (*((_BYTE *)v9->pNs.pObject + 40) & 0x10) != 0 )
        break;
      v10 = this->FirstOwnSlotNum;
      if ( Prev >= v10 )
        Prev = this->VArray.Data.Data[Prev - v10].Prev;
      else
        Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(this->Parent, Prev);
      if ( Prev < 0 )
        return;
    }
    VT = Scaleform::GFx::AS3::Traits::GetVT(this);
    v12 = *(_DWORD *)v9;
    v13 = (int)((_DWORD)v12 << 17) >> 27;
    v14 = v12 >> 15;
    if ( v13 != 11 || bt == 11 )
      Scaleform::GFx::AS3::VTable::SetMethod(VT, (Scaleform::GFx::AS3::AbsoluteIndex)v14, v, bt);
  }
}

// File Line: 1187
// RVA: 0x7AA4F0
void __fastcall Scaleform::GFx::AS3::Traits::Add2VT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::ASString *mn_name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *mn_ns,
        Scaleform::GFx::AS3::SlotInfo *nsi,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::SlotInfo::BindingType v9; // edi
  Scaleform::GFx::AS3::Slots::Pair *v10; // rsi
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+50h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Slots::Add(&this->Scaleform::GFx::AS3::Slots, &result, mn_name, nsi);
  v9 = bt;
  v10 = &this->VArray.Data.Data[LODWORD(result.Index) - this->FirstOwnSlotNum];
  Scaleform::GFx::AS3::Traits::UpdateVT4IM(this, mn_name, mn_ns, v, bt);
  Scaleform::GFx::AS3::Traits::Add2VT(this, &v10->Value, v, v9);
}

// File Line: 1199
// RVA: 0x810BF0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::RegisterWithVT(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *mn_name,
        Scaleform::GFx::AS3::SlotInfo *nsi,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::BindingType bt)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r12
  unsigned __int64 FirstOwnSlotNum; // r8
  Scaleform::GFx::AS3::SlotInfo *p_Value; // r14
  int v13; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v15; // esi
  Scaleform::GFx::AS3::AbsoluteIndex resulta; // [rsp+60h] [rbp+8h] BYREF

  pObject = nsi->pNs.pObject;
  Scaleform::GFx::AS3::Slots::FindSlotInfoIndex(&this->Scaleform::GFx::AS3::Slots, &resulta, mn_name, pObject);
  if ( resulta.Index < 0 )
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, mn_name, pObject, nsi, v, bt);
    result->Result = 1;
    return result;
  }
  FirstOwnSlotNum = this->FirstOwnSlotNum;
  if ( resulta.Index >= FirstOwnSlotNum )
    p_Value = &this->VArray.Data.Data[LODWORD(resulta.Index) - FirstOwnSlotNum].Value;
  else
    p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, resulta);
  v13 = (int)(*(_DWORD *)p_Value << 17) >> 27;
  if ( v13 && v13 < 11 )
  {
    result->Result = 0;
    return result;
  }
  v15 = bt;
  if ( v13 == 12 )
  {
    if ( bt != BT_Set )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( v13 == 13 && bt == BT_Get )
LABEL_14:
    v13 = 14;
LABEL_15:
  if ( v13 == bt )
  {
    Scaleform::GFx::AS3::Traits::UpdateVT4IM(this, mn_name, pObject, v, bt);
    Scaleform::GFx::AS3::Traits::UpdateVT(this, p_Value, v, v15);
  }
  else
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, mn_name, pObject, p_Value, v, bt);
  }
  result->Result = 1;
  return result;
}

// File Line: 1246
// RVA: 0x7E5E10
Scaleform::GFx::AS3::VMAppDomain *__fastcall Scaleform::GFx::AS3::Traits::GetAppDomain(
        Scaleform::GFx::AS3::Traits *this)
{
  __int64 v2; // rax

  v2 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))this->vfptr[2].~RefCountBaseGC<328>)(this);
  if ( v2 )
    return *(Scaleform::GFx::AS3::VMAppDomain **)(v2 + 48);
  else
    return this->pVM->SystemDomain.pObject;
}

// File Line: 1294
// RVA: 0x7C4640
void __fastcall Scaleform::GFx::AS3::Traits::DestructTail(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::Object *obj)
{
  unsigned __int64 v4; // rdi
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  int v11; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  v4 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  while ( v4 )
  {
    if ( (--v4 & 0x8000000000000000ui64) != 0i64 || (FirstOwnSlotNum = this->FirstOwnSlotNum, v4 < FirstOwnSlotNum) )
      SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v4);
    else
      SlotInfo = &this->VArray.Data.Data[(unsigned int)v4 - FirstOwnSlotNum].Value;
    if ( (*(_DWORD *)SlotInfo & 0x300) == 0 )
    {
      v7 = (Scaleform::GFx::AS3::Value *)((char *)obj + ((__int64)*(_DWORD *)SlotInfo >> 15));
      switch ( (int)(*(_DWORD *)SlotInfo << 17) >> 27 )
      {
        case 2:
          if ( (v7->Flags & 0x1F) > 9 )
          {
            if ( (v7->Flags & 0x200) != 0 )
            {
              pWeakProxy = v7->Bonus.pWeakProxy;
              v9 = pWeakProxy->RefCount-- == 1;
              if ( v9 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              v7->Flags &= 0xFFFFFDE0;
              v7->Bonus.pWeakProxy = 0i64;
              v7->value.VS._1.VStr = 0i64;
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
            if ( (v7->Flags & 1) != 0 )
            {
              *(_QWORD *)&v7->Flags = (char *)v10 + (v7->Flags & 6) - 1;
            }
            else
            {
              v11 = *(_DWORD *)((*(_QWORD *)&v7->Flags & 0xFFFFFFFFFFFFFFF9ui64) + 0x20);
              if ( (v11 & 0x3FFFFF) != 0 )
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
void __fastcall Scaleform::GFx::AS3::Traits::ConstructTail(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::Object *obj)
{
  unsigned __int64 v4; // rsi
  __int64 i; // rbx
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax
  __int64 v8; // rax
  _QWORD *v9; // rdx
  int v10; // eax
  int v11; // eax

  v4 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  for ( i = 0i64; i < v4; ++i )
  {
    if ( i < 0 || (FirstOwnSlotNum = this->FirstOwnSlotNum, i < FirstOwnSlotNum) )
      SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)i);
    else
      SlotInfo = &this->VArray.Data.Data[(unsigned int)i - FirstOwnSlotNum].Value;
    v8 = *(_DWORD *)SlotInfo;
    if ( (v8 & 0x300) == 0 )
    {
      v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)((char *)&obj->vfptr + (v8 >> 15));
      v10 = ((int)((_DWORD)v8 << 17) >> 27) - 2;
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
  }
}

// File Line: 1322
// RVA: 0x7D70F0
void __fastcall Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::Object *obj,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  __int64 v8; // rbx
  unsigned __int64 v9; // rsi
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax

  v8 = 0i64;
  v9 = this->FirstOwnSlotNum + this->VArray.Data.Size;
  if ( v9 )
  {
    do
    {
      if ( v8 < 0 || (FirstOwnSlotNum = this->FirstOwnSlotNum, v8 < FirstOwnSlotNum) )
        SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v8);
      else
        SlotInfo = &this->VArray.Data.Data[(unsigned int)v8 - FirstOwnSlotNum].Value;
      Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(SlotInfo, prcc, obj, op);
      ++v8;
    }
    while ( v8 < v9 );
  }
}

// File Line: 1354
// RVA: 0x7F0D10
Scaleform::GFx::AS3::VTable *__fastcall Scaleform::GFx::AS3::Traits::GetVT(Scaleform::GFx::AS3::Traits *this)
{
  bool v2; // zf
  Scaleform::MemoryHeap *MHeap; // rcx
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  Scaleform::GFx::AS3::VTable *v5; // rsi
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::VTable *pObject; // rcx
  Scaleform::GFx::AS3::VTable *v9; // rax

  if ( this->pVTable.pObject )
    return this->pVTable.pObject;
  v2 = this->pParent.pObject == 0i64;
  MHeap = this->pVM->MHeap;
  vfptr = MHeap->vfptr;
  if ( v2 )
  {
    v9 = (Scaleform::GFx::AS3::VTable *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))vfptr->Alloc)(
                                          MHeap,
                                          32i64);
    v5 = v9;
    if ( v9 )
    {
      v9->pTraits = this;
      v9->VTMethods.Data.Data = 0i64;
      v9->VTMethods.Data.Size = 0i64;
      v9->VTMethods.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v5 = (Scaleform::GFx::AS3::VTable *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))vfptr->Alloc)(
                                          MHeap,
                                          32i64);
    if ( v5 )
    {
      VT = Scaleform::GFx::AS3::Traits::GetVT(this->pParent.pObject);
      v5->pTraits = this;
      Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>(
        &v5->VTMethods.Data,
        &VT->VTMethods.Data);
    }
    else
    {
      v5 = 0i64;
    }
  }
  pObject = this->pVTable.pObject;
  if ( pObject != v5 )
  {
    if ( pObject )
    {
      if ( this->pVTable.Owner )
      {
        this->pVTable.Owner = 0;
        Scaleform::GFx::AS3::VTable::`scalar deleting destructor(pObject, 1);
      }
    }
    this->pVTable.pObject = v5;
  }
  this->pVTable.Owner = v5 != 0i64;
  return this->pVTable.pObject;
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
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::VMAppDomain *pObject; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *ParentClassTraits; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList **v8; // rdi
  unsigned __int16 ClassMemberNum; // bp
  unsigned __int8 i; // di
  unsigned __int16 ClassMethodNum; // bp
  unsigned __int8 j; // di

  if ( vm->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    pObject = vm->CallStack.Pages[(vm->CallStack.Size - 1) >> 6][(LODWORD(vm->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    pObject = vm->CurrentDomain.pObject;
  ParentClassTraits = Scaleform::GFx::AS3::Traits::RetrieveParentClassTraits(vm, ci, pObject);
  Scaleform::GFx::AS3::Traits::Traits(this, vm, ParentClassTraits, 1, 0);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable;
  this->ITraits.pObject = 0i64;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)vm->TraitsClassClass.pObject->ITraits.pObject;
  if ( !v8[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*v8)->List.Data.Data)(v8);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    v8[17]);
  this->Flags |= 0x20ui64;
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this);
  ClassMemberNum = ci->Type->ClassMemberNum;
  for ( i = 0; i < ClassMemberNum; ++i )
    Scaleform::GFx::AS3::Traits::AddSlot(this, &ci->ClassMember[i]);
  ClassMethodNum = ci->Type->ClassMethodNum;
  for ( j = 0; j < ClassMethodNum; ++j )
    Scaleform::GFx::AS3::Traits::Add2VT(this, ci, &ci->ClassMethod[j]);
}

// File Line: 1432
// RVA: 0x7837B0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Traits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassTraits::Traits *pt)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList **pObject; // rbx

  Scaleform::GFx::AS3::Traits::Traits(this, vm, pt, 1, 0);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable;
  this->ITraits.pObject = 0i64;
  pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList **)vm->TraitsClassClass.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::XMLList **))(*pObject)->List.Data.Data)(pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    pObject[17]);
  this->Flags |= 0x20ui64;
  if ( !this->pParent.pObject )
    Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this);
}

// File Line: 1448
// RVA: 0x819B10
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  unsigned int RefCount; // eax

  this->Flags ^= (LODWORD(this->Flags) ^ -((LODWORD(itr.pV->Flags) >> 2) & 1)) & 4;
  pObject = this->ITraits.pObject;
  if ( itr.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->ITraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)pObject - 1);
        this->ITraits.pObject = itr.pV;
        return;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->ITraits.pObject = itr.pV;
  }
}

// File Line: 1458
// RVA: 0x7F3C10
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::InitOnDemand(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx

  pObject = this->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
}

// File Line: 1467
// RVA: 0x7D66F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    op(prcc);
}

// File Line: 1474
// RVA: 0x80FFC0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(Scaleform::GFx::AS3::ClassTraits::Traits *this)
{
  const char **p_NamespaceName; // rsi
  __int64 v3; // r13
  Scaleform::GFx::AS3::VM *pVM; // r14
  const char *v5; // r9
  const char *v6; // rax
  int v7; // ecx
  int v8; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rax
  const char *Name; // rax
  bool v11; // dl
  const char *PkgName; // r9
  bool v13; // al
  Scaleform::GFx::ASStringNode *pNode; // rbx
  unsigned int v15; // ecx
  Scaleform::GFx::AS3::SlotInfo::BindingType bt; // edx
  bool v17; // di
  Scaleform::GFx::ASStringNode *pObject; // rcx
  bool v19; // zf
  Scaleform::GFx::AS3::VMAbcFile *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // rcx
  unsigned int v25; // eax
  unsigned int Flags; // ebx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::VM::Error *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v33; // rbx
  __int64 v34; // r12
  Scaleform::GFx::AS3::SlotInfo nsi; // [rsp+30h] [rbp-99h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-69h] BYREF
  __int64 v37; // [rsp+80h] [rbp-49h] BYREF
  int v38; // [rsp+88h] [rbp-41h]
  __int16 v39; // [rsp+8Ch] [rbp-3Dh]
  char *v40; // [rsp+90h] [rbp-39h]
  char *v41; // [rsp+98h] [rbp-31h]
  __int64 v42; // [rsp+A0h] [rbp-29h]
  __int64 v43; // [rsp+A8h] [rbp-21h]
  Scaleform::GFx::AS3::VM::Error v44; // [rsp+B0h] [rbp-19h] BYREF
  Scaleform::GFx::ASStringNode *v45; // [rsp+C0h] [rbp-9h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v46; // [rsp+C8h] [rbp-1h] BYREF
  __int64 v47; // [rsp+D0h] [rbp+7h]
  Scaleform::GFx::AS3::CheckResult v48; // [rsp+130h] [rbp+67h] BYREF
  Scaleform::GFx::ASString result; // [rsp+138h] [rbp+6Fh] BYREF
  __int64 v50; // [rsp+140h] [rbp+77h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v51; // [rsp+148h] [rbp+7Fh] BYREF

  v47 = -2i64;
  p_NamespaceName = &ti[0].NamespaceName;
  v50 = 3i64;
  v3 = 3i64;
  do
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      this->pVM->StringManagerRef,
      &result,
      *(p_NamespaceName - 1));
    pVM = this->pVM;
    v5 = *p_NamespaceName;
    if ( *p_NamespaceName && *v5 )
    {
      if ( v5 != Scaleform::GFx::AS3::NS_AS3 )
      {
        v6 = *p_NamespaceName;
        do
        {
          v7 = (unsigned __int8)v6[Scaleform::GFx::AS3::NS_AS3 - v5];
          v8 = *(unsigned __int8 *)v6 - v7;
          if ( v8 )
            break;
          ++v6;
        }
        while ( v7 );
        if ( v8 )
        {
          pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
                 this->pVM,
                 &v51,
                 (Scaleform::GFx::AS3::Abc::NamespaceKind)((_DWORD)p_NamespaceName[1] & 0xF),
                 v5)->pV;
          goto LABEL_25;
        }
      }
      pV = pVM->AS3Namespace.pObject;
    }
    else
    {
      Name = Scaleform::GFx::AS3::fl::ObjectCI.Type->Name;
      v11 = !Name || !*Name;
      PkgName = Scaleform::GFx::AS3::fl::ObjectCI.Type->PkgName;
      v13 = !PkgName || !*PkgName;
      if ( v11 && !v13 )
      {
        pV = Scaleform::GFx::AS3::VM::MakeInternedNamespace(
               this->pVM,
               &v46,
               (Scaleform::GFx::AS3::Abc::NamespaceKind)((_DWORD)p_NamespaceName[1] & 0xF),
               PkgName)->pV;
        goto LABEL_25;
      }
      pV = pVM->PublicNamespace.pObject;
    }
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
LABEL_25:
    v.Flags = 5;
    v.Bonus.pWeakProxy = 0i64;
    v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)(p_NamespaceName - 3);
    pNode = result.pNode;
    if ( result.pNode )
      ++result.pNode->RefCount;
    v45 = pNode;
    v15 = *(_WORD *)&nsi & 0x8000 | 0xFFFF8000;
    *(_DWORD *)&nsi = v15;
    nsi.Padding01 = 0;
    nsi.pNs.pObject = pV;
    memset(&nsi.CTraits, 0, 24);
    if ( pNode )
      ++pNode->RefCount;
    nsi.Name.pObject = pNode;
    *(_DWORD *)&nsi = v15 & 0xFFFFFC00 | 4;
    bt = BT_Code;
    if ( ((*((_DWORD *)p_NamespaceName + 2) >> 4) & 3) != 0 )
    {
      if ( ((*((_DWORD *)p_NamespaceName + 2) >> 4) & 3) == 1 )
      {
        bt = BT_Get;
      }
      else if ( ((*((_DWORD *)p_NamespaceName + 2) >> 4) & 3) == 2 )
      {
        bt = BT_Set;
      }
    }
    v17 = !Scaleform::GFx::AS3::Traits::RegisterWithVT(this, &v48, &result, &nsi, &v, bt)->Result;
    pObject = nsi.Name.pObject;
    if ( nsi.Name.pObject )
    {
      v19 = nsi.Name.pObject->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    }
    v20 = nsi.File.pObject;
    if ( nsi.File.pObject )
    {
      if ( ((__int64)nsi.File.pObject & 1) != 0 )
      {
        --nsi.File.pObject;
      }
      else
      {
        RefCount = nsi.File.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          nsi.File.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
        }
      }
    }
    v22 = nsi.CTraits.pObject;
    if ( nsi.CTraits.pObject )
    {
      if ( ((__int64)nsi.CTraits.pObject & 1) != 0 )
      {
        --nsi.CTraits.pObject;
      }
      else
      {
        v23 = nsi.CTraits.pObject->RefCount;
        if ( (v23 & 0x3FFFFF) != 0 )
        {
          nsi.CTraits.pObject->RefCount = v23 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
        }
      }
    }
    v24 = nsi.pNs.pObject;
    if ( nsi.pNs.pObject )
    {
      if ( ((__int64)nsi.pNs.pObject & 1) != 0 )
      {
        --nsi.pNs.pObject;
      }
      else
      {
        v25 = nsi.pNs.pObject->RefCount;
        if ( (v25 & 0x3FFFFF) != 0 )
        {
          nsi.pNs.pObject->RefCount = v25 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
        }
      }
    }
    if ( pNode )
    {
      v19 = pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Flags = v.Flags;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v19 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v.Bonus, 0, 24);
        v.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        switch ( v.Flags & 0x1F )
        {
          case 0xA:
            VStr = v.value.VS._1.VStr;
            v19 = v.value.VS._1.VStr->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( !v.value.VS._1.VBool )
            {
              VObj = v.value.VS._1.VObj;
              goto LABEL_69;
            }
            --v.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
            {
              --v.value.VS._2.VObj;
            }
            else
            {
              VObj = v.value.VS._2.VObj;
LABEL_69:
              if ( VObj )
              {
                v29 = VObj->RefCount;
                if ( (v29 & 0x3FFFFF) != 0 )
                {
                  VObj->RefCount = v29 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
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
      Scaleform::GFx::AS3::VM::Error::Error(&v44, 1053, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v30, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v31 = v44.Message.pNode;
      v19 = v44.Message.pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    }
    v32 = result.pNode;
    v19 = result.pNode->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v32);
    p_NamespaceName += 6;
    --v3;
  }
  while ( v3 );
  v37 = 0i64;
  v38 = 0;
  v39 = 0;
  v40 = &customCaption;
  v41 = &customCaption;
  v42 = 0i64;
  v43 = 0i64;
  *(_QWORD *)&nsi = &v37;
  memset(&nsi.pNs, 0, 40);
  v33 = f;
  v34 = v50;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, (Scaleform::GFx::AS3::ClassInfo *)&nsi, v33++);
    --v34;
  }
  while ( v34 );
  this->FirstOwnSlotInd.Index += 6i64;
}

// File Line: 1489
// RVA: 0x7F8EF0
char __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *other)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // rbx

  pObject = other;
  if ( this == other )
    return 1;
  if ( other )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))pObject->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               pObject->ITraits.pObject,
               this->ITraits.pObject) )
    {
      pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == this )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 1515
// RVA: 0x7B6B10
// attributes: thunk
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::Coerce(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  return Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(this, value, result);
}

// File Line: 1520
// RVA: 0x7B6BF0
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *pVM; // r8
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // ecx
  Scaleform::GFx::AS3::Value *v7; // rbx
  bool v8; // al
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rdx

  pVM = this->pVM;
  TraitsType = this->TraitsType;
  v7 = value;
  switch ( value->Flags & 0x1F )
  {
    case 0u:
      Scaleform::GFx::AS3::Value::SetNull(result);
      return 1;
    case 1u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_Boolean )
        goto LABEL_16;
      goto $LN19_39;
    case 2u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_SInt )
        goto LABEL_16;
      Scaleform::GFx::AS3::Value::SetSInt32(result, value->value.VS._1.VInt);
      v8 = 1;
      break;
    case 3u:
      if ( this != pVM->TraitsObject.pObject && TraitsType != Traits_UInt )
        goto LABEL_16;
      Scaleform::GFx::AS3::Value::SetUInt32(result, value->value.VS._1.VUInt);
      v8 = 1;
      break;
    case 4u:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_Number )
        goto $LN19_39;
      v8 = 0;
      break;
    case 5u:
    case 7u:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_Function )
        goto $LN19_39;
      goto LABEL_16;
    case 0xAu:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_String )
        goto $LN19_39;
      v8 = 0;
      break;
    case 0xBu:
      if ( this == pVM->TraitsObject.pObject || TraitsType == Traits_Namespace )
        goto $LN19_39;
      v8 = 0;
      break;
    case 0xCu:
    case 0xEu:
    case 0xFu:
      if ( !value->value.VS._1.VStr )
        goto LABEL_13;
      ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(pVM, value);
LABEL_29:
      if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(this, ClassTraits) )
      {
$LN19_39:
        value = v7;
LABEL_13:
        Scaleform::GFx::AS3::Value::Assign(result, value);
        v8 = 1;
      }
      else
      {
LABEL_16:
        v8 = 0;
      }
      break;
    case 0xDu:
      ClassTraits = (Scaleform::GFx::AS3::ClassTraits::Traits *)value->value.VS._1.VStr[1].pData;
      goto LABEL_29;
    case 0x10u:
    case 0x11u:
      goto $LN19_39;
    default:
      return 1;
  }
  return v8;
}

// File Line: 1624
// RVA: 0x7EC7D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ClassTraits::Traits::GetName(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::ASString *result)
{
  this->ITraits.pObject->vfptr[1].~RefCountBaseGC<328>(this->ITraits.pObject);
  return result;
}

// File Line: 1629
// RVA: 0x7EE8B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ClassTraits::Traits::GetQualifiedName(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::ASString *result,
        __int64 f)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *, __int64))this->ITraits.pObject->vfptr[1].Finalize_GC)(
    this->ITraits.pObject,
    result,
    f);
  return result;
}

