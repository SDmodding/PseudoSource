// File Line: 137
// RVA: 0x8A79F0
void __fastcall Scaleform::GFx::AS3::Slots::SlotFunct::~SlotFunct(Scaleform::GFx::AS3::Slots::SlotFunct *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Slots::SlotFunctVtbl *)&Scaleform::GFx::AS3::Slots::SlotFunct::`vftable;
}

// File Line: 160
// RVA: 0x7EF330
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Slots::GetSlotInfo(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    return Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    return &this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Value;
}

// File Line: 172
// RVA: 0x7EF3E0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::AS3::Slots::GetSlotNameNode(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    return Scaleform::GFx::AS3::Slots::GetSlotNameNode(this->Parent, ind);
  else
    return this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Key.pObject;
}

// File Line: 184
// RVA: 0x7EF370
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Slots::GetSlotName(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::ASStringNode *SlotNameNode; // rax

  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(this->Parent, ind);
  else
    SlotNameNode = this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Key.pObject;
  result->pNode = SlotNameNode;
  ++SlotNameNode->RefCount;
  return result;
}

// File Line: 203
// RVA: 0x7D4170
char *__fastcall Scaleform::GFx::AS3::Slots::FindSlotValues(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *pNode; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // rbx
  __int64 v5; // r11
  __int64 v6; // rdx
  unsigned __int64 *v7; // r9
  Scaleform::GFx::ASStringNode *v8; // rcx
  unsigned __int64 *v9; // rbx
  char *v10; // rbx

  pNode = name->pNode;
  if ( name->pNode )
    ++pNode->RefCount;
  pTable = this->Set.mHash.pTable;
  if ( !pTable )
    goto LABEL_13;
  SizeMask = pTable->SizeMask;
  v5 = (unsigned int)SizeMask & pNode->HashFlags;
  v6 = v5;
  v7 = &pTable[v5 + 1].EntryCount + v5;
  if ( *v7 == -2i64 || ((unsigned int)SizeMask & *(_DWORD *)(v7[1] + 28)) != v5 )
    goto LABEL_13;
  while ( 1 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)v7[1];
    if ( ((unsigned int)SizeMask & v8->HashFlags) == v5 && v8 == pNode )
      break;
    v6 = *v7;
    if ( *v7 == -1i64 )
      goto LABEL_13;
    v7 = &pTable[v6 + 1].EntryCount + v6;
  }
  if ( v6 >= 0 && (v9 = &pTable[1].SizeMask + 3 * v6) != 0i64 )
    v10 = (char *)(v9 + 1);
  else
LABEL_13:
    v10 = 0i64;
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return v10;
}

// File Line: 208
// RVA: 0x7EDBC0
__int64 __fastcall Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(Scaleform::GFx::AS3::Slots *this, unsigned __int64 ind)
{
  for ( ; ind < this->FirstOwnSlotNum; this = this->Parent )
    ;
  return this->VArray.Data.Data[ind - this->FirstOwnSlotNum].Prev;
}

// File Line: 223
// RVA: 0x7D6390
void __fastcall Scaleform::GFx::AS3::Slots::ForEachChild_GC(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  unsigned __int64 Size; // rsi
  __int64 v7; // rdi
  Scaleform::GFx::AS3::Slots::Pair *Data; // rbx

  Size = this->VArray.Data.Size;
  if ( Size )
  {
    v7 = 0i64;
    do
    {
      Data = this->VArray.Data.Data;
      if ( Data[v7].Value.File.pObject )
        op(prcc);
      if ( Data[v7].Value.pNs.pObject )
        op(prcc);
      if ( Data[v7].Value.CTraits.pObject )
        op(prcc);
      ++v7;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 396
// RVA: 0x7E7360
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::Traits::GetConstructor(Scaleform::GFx::AS3::Traits *this)
{
  if ( this->pConstructor.pObject )
    return this->pConstructor.pObject;
  this->vfptr[3].~RefCountBaseGC<328>(this);
  return this->pConstructor.pObject;
}

// File Line: 481
// RVA: 0x7EFE30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Object *const obj)
{
  unsigned __int64 FirstOwnSlotNum; // r11
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax

  if ( ind.Index < 0 || (FirstOwnSlotNum = this->FirstOwnSlotNum, ind.Index < FirstOwnSlotNum) )
    SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    SlotInfo = &this->VArray.Data.Data[LODWORD(ind.Index) - FirstOwnSlotNum].Value;
  Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(SlotInfo, result, value, obj);
  return result;
}

// File Line: 495
// RVA: 0x81E590
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::SetSlotValue(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned __int64 FirstOwnSlotNum; // r11
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax

  pVM = this->pVM;
  if ( ind.Index < 0 || (FirstOwnSlotNum = this->FirstOwnSlotNum, ind.Index < FirstOwnSlotNum) )
    SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    SlotInfo = &this->VArray.Data.Data[LODWORD(ind.Index) - FirstOwnSlotNum].Value;
  Scaleform::GFx::AS3::SlotInfo::SetSlotValue(SlotInfo, result, pVM, v);
  return result;
}

// File Line: 524
// RVA: 0x81D5A0
void __fastcall Scaleform::GFx::AS3::Traits::SetSlot(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        Scaleform::GFx::ASString *name,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::TraitInfo *ti,
        bool _const)
{
  Scaleform::GFx::ASStringNode *pNode; // rsi
  unsigned int v10; // edx
  Scaleform::GFx::AS3::SlotInfo other; // [rsp+28h] [rbp-38h] BYREF

  pNode = name->pNode;
  if ( name->pNode )
    ++pNode->RefCount;
  *(_DWORD *)&other = *(_WORD *)&other & 0x8000 | 0xFFFF8000;
  other.Padding01 = 0;
  other.pNs.pObject = ns.pV;
  other.CTraits.pObject = 0i64;
  other.File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  other.TI = ti;
  if ( pNode )
    ++pNode->RefCount;
  other.Name.pObject = pNode;
  v10 = _const + 2;
  *(_DWORD *)&other = *(_DWORD *)&other & 0xFFFFFC00 | v10 & 1 | (4 * ((v10 >> 1) & 1)) & 0xFFFFFC0F | (16 * ((v10 >> 2) & 1)) & 0xFFFFFC3F | (((v10 >> 3) & 1) << 6) & 0xFFFFFCFF | (((v10 >> 4) & 1) << 8);
  Scaleform::GFx::AS3::SlotInfo::operator=(
    &this->VArray.Data.Data[LODWORD(index.Index) - this->FirstOwnSlotNum].Value,
    &other);
  Scaleform::GFx::AS3::Slots::SetKey(&this->Scaleform::GFx::AS3::Slots, index, name);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&other);
  if ( pNode )
  {
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 829
// RVA: 0x7F8AD0
char __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
        Scaleform::GFx::AS3::ClassTraits::Traits *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *other)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // rbx

  pObject = this;
  if ( other == this )
    return 1;
  if ( this )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))pObject->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               pObject->ITraits.pObject,
               other->ITraits.pObject) )
    {
      pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == other )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 948
// RVA: 0x7EC6B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Object::GetName(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::ASString *result)
{
  this->pTraits.pObject->vfptr[1].~RefCountBaseGC<328>(this->pTraits.pObject);
  return result;
}

// File Line: 954
// RVA: 0x7EF420
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SlotIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
    this->pTraits.pObject,
    result,
    value,
    (Scaleform::GFx::AS3::AbsoluteIndex)(LODWORD(this->pTraits.pObject->FirstOwnSlotInd.Index) + ind.Index - 1i64),
    this);
  return result;
}

