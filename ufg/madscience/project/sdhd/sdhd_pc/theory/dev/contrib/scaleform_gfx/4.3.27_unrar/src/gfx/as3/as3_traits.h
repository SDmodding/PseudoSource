// File Line: 137
// RVA: 0x8A79F0
void __fastcall Scaleform::GFx::AS3::Slots::SlotFunct::~SlotFunct(Scaleform::GFx::AS3::Slots::SlotFunct *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Slots::SlotFunctVtbl *)&Scaleform::GFx::AS3::Slots::SlotFunct::`vftable';
}

// File Line: 160
// RVA: 0x7EF330
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Slots::GetSlotInfo(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::SlotInfo *result; // rax

  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    result = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    result = &this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Value;
  return result;
}

// File Line: 172
// RVA: 0x7EF3E0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::AS3::Slots::GetSlotNameNode(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::ASStringNode *result; // rax

  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    result = Scaleform::GFx::AS3::Slots::GetSlotNameNode(this->Parent, ind);
  else
    result = this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Key.pObject;
  return result;
}

// File Line: 184
// RVA: 0x7EF370
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Slots::GetSlotName(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v3 = result;
  if ( ind.Index < 0 || ind.Index < this->FirstOwnSlotNum )
    v4 = Scaleform::GFx::AS3::Slots::GetSlotNameNode(this->Parent, ind);
  else
    v4 = this->VArray.Data.Data[LODWORD(ind.Index) - this->FirstOwnSlotNum].Key.pObject;
  v3->pNode = v4;
  ++v4->RefCount;
  return v3;
}

// File Line: 203
// RVA: 0x7D4170
const unsigned int *__fastcall Scaleform::GFx::AS3::Slots::FindSlotValues(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *v2; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v3; // r10
  unsigned __int64 v4; // rbx
  signed __int64 v5; // r11
  signed __int64 v6; // rdx
  unsigned __int64 *v7; // r9
  Scaleform::GFx::ASStringNode *v8; // rcx
  signed __int64 v9; // rbx
  signed __int64 v10; // rbx
  bool v11; // zf

  v2 = name->pNode;
  if ( name->pNode )
    ++v2->RefCount;
  v3 = this->Set.mHash.pTable;
  if ( !v3 )
    goto LABEL_13;
  v4 = v3->SizeMask;
  v5 = (unsigned int)v4 & v2->HashFlags;
  v6 = v5;
  v7 = &v3->EntryCount + v5 + 2 * (v5 + 1);
  if ( *v7 == -2i64 || ((unsigned int)v4 & *(_DWORD *)(v7[1] + 28)) != v5 )
    goto LABEL_13;
  while ( 1 )
  {
    v8 = (Scaleform::GFx::ASStringNode *)v7[1];
    if ( ((unsigned int)v4 & v8->HashFlags) == v5 && v8 == v2 )
      break;
    v6 = *v7;
    if ( *v7 == -1i64 )
      goto LABEL_13;
    v7 = &v3->EntryCount + v6 + 2 * (v6 + 1);
  }
  if ( v6 >= 0 && (v9 = (signed __int64)v3 + 24 * (v6 + 1)) != 0 )
    v10 = v9 + 8;
  else
LABEL_13:
    v10 = 0i64;
  if ( v2 )
  {
    v11 = v2->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  }
  return (const unsigned int *)v10;
}

// File Line: 208
// RVA: 0x7EDBC0
__int64 __fastcall Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(Scaleform::GFx::AS3::Slots *this, __int64 ind)
{
  for ( ; ind < this->FirstOwnSlotNum; this = this->Parent )
    ;
  return this->VArray.Data.Data[ind - this->FirstOwnSlotNum].Prev;
}

// File Line: 223
// RVA: 0x7D6390
void __fastcall Scaleform::GFx::AS3::Slots::ForEachChild_GC(Scaleform::GFx::AS3::Slots *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rsi
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // r14
  Scaleform::GFx::AS3::Slots *v6; // r15
  __int64 v7; // rdi
  Scaleform::GFx::AS3::Slots::Pair *v8; // rbx

  v3 = this->VArray.Data.Size;
  v4 = op;
  v5 = prcc;
  v6 = this;
  if ( v3 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->VArray.Data.Data;
      if ( v8[v7].Value.File.pObject )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v4)(v5);
      if ( v8[v7].Value.pNs.pObject )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v4)(v5);
      if ( v8[v7].Value.CTraits.pObject )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v4)(v5);
      ++v7;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 396
// RVA: 0x7E7360
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::Traits::GetConstructor(Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::Traits *v1; // rbx

  v1 = this;
  if ( this->pConstructor.pObject )
    return this->pConstructor.pObject;
  ((void (*)(void))this->vfptr[3].~RefCountBaseGC<328>)();
  return v1->pConstructor.pObject;
}

// File Line: 481
// RVA: 0x7EFE30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Object *const obj)
{
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  unsigned __int64 v7; // r11
  Scaleform::GFx::AS3::SlotInfo *v8; // rax

  v5 = value;
  v6 = result;
  if ( ind.Index < 0 || (v7 = this->FirstOwnSlotNum, ind.Index < v7) )
    v8 = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    v8 = &this->VArray.Data.Data[LODWORD(ind.Index) - v7].Value;
  Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(v8, v6, v5, obj);
  return v6;
}

// File Line: 495
// RVA: 0x81E590
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Traits::SetSlotValue(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  unsigned __int64 v7; // r11
  Scaleform::GFx::AS3::SlotInfo *v8; // rax

  v4 = this->pVM;
  v5 = v;
  v6 = result;
  if ( ind.Index < 0 || (v7 = this->FirstOwnSlotNum, ind.Index < v7) )
    v8 = Scaleform::GFx::AS3::Slots::GetSlotInfo(this->Parent, ind);
  else
    v8 = &this->VArray.Data.Data[LODWORD(ind.Index) - v7].Value;
  Scaleform::GFx::AS3::SlotInfo::SetSlotValue(v8, v6, v4, v5);
  return v6;
}

// File Line: 524
// RVA: 0x81D5A0
void __fastcall Scaleform::GFx::AS3::Traits::SetSlot(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::AbsoluteIndex index, Scaleform::GFx::ASString *name, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::Abc::TraitInfo *ti, bool _const)
{
  Scaleform::GFx::ASString *v7; // r14
  Scaleform::GFx::AS3::Traits *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rsi
  unsigned int v10; // edx
  bool v11; // zf
  Scaleform::GFx::AS3::SlotInfo other; // [rsp+28h] [rbp-38h]
  __int64 ind; // [rsp+98h] [rbp+38h]

  ind = index.Index;
  v7 = name;
  v8 = this;
  v9 = name->pNode;
  if ( name->pNode )
    ++v9->RefCount;
  other = (Scaleform::GFx::AS3::SlotInfo)(*(_WORD *)&other & 0x8000 | 0xFFFF8000);
  other.Padding01 = 0;
  other.pNs.pObject = ns.pV;
  other.CTraits.pObject = 0i64;
  other.File.pObject = file;
  if ( file )
    file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  other.TI = ti;
  if ( v9 )
    ++v9->RefCount;
  other.Name.pObject = v9;
  v10 = (_const != 0) + 2;
  other = (Scaleform::GFx::AS3::SlotInfo)(((((*(_DWORD *)&other & 0xFFFFFFFC | v10 & 1) & 0xFFFFFFF3 | 4 * ((v10 >> 1) & 1)) & 0xFFFFFFCF | 16 * ((v10 >> 2) & 1)) & 0xFFFFFF3F | (((v10 >> 3) & 1) << 6)) & 0xFFFFFCFF | (((v10 >> 4) & 1) << 8));
  Scaleform::GFx::AS3::SlotInfo::operator=(
    &this->VArray.Data.Data[(unsigned int)ind - this->FirstOwnSlotNum].Value,
    &other);
  Scaleform::GFx::AS3::Slots::SetKey(
    (Scaleform::GFx::AS3::Slots *)&v8->FirstOwnSlotNum,
    (Scaleform::GFx::AS3::AbsoluteIndex)ind,
    v7);
  Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&other);
  if ( v9 )
  {
    v11 = v9->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  }
}

// File Line: 829
// RVA: 0x7F8AD0
char __fastcall Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(Scaleform::GFx::AS3::ClassTraits::Traits *this, Scaleform::GFx::AS3::ClassTraits::Traits *other)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // rbx

  v2 = other;
  v3 = this;
  if ( other == this )
    return 1;
  if ( this )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v3->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v3->ITraits.pObject,
               v2->ITraits.pObject) )
    {
      v3 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v3->pParent.pObject;
      if ( v3 == v2 )
        break;
      if ( !v3 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 948
// RVA: 0x7EC6B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Object::GetName(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx

  v2 = result;
  ((void (__cdecl *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *))this->pTraits.pObject->vfptr[1].~RefCountBaseGC<328>)(
    this->pTraits.pObject,
    result);
  return v2;
}

// File Line: 954
// RVA: 0x7EF420
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::SlotIndex ind, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rdi

  v4 = result;
  Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
    this->pTraits.pObject,
    result,
    value,
    (Scaleform::GFx::AS3::AbsoluteIndex)(LODWORD(this->pTraits.pObject->FirstOwnSlotInd.Index) + ind.Index - 1i64),
    this);
  return v4;
}

