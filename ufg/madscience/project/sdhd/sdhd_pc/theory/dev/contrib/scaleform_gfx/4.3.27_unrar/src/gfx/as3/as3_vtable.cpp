// File Line: 73
// RVA: 0x7EC260
void __fastcall Scaleform::GFx::AS3::VTable::GetMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Object *_this,
        bool super)
{
  Scaleform::GFx::AS3::Value *v6; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // rax
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-28h] BYREF

  v6 = &this->VTMethods.Data.Data[LODWORD(ind.Index)];
  if ( (v6->Flags & 0x1F) == 5 )
  {
    v7 = v6->value.VS._1;
    other.Flags = 16;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = _this;
    other.value.VS._1 = v7;
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::Assign(value, &other);
  }
  else
  {
    if ( (v6->Flags & 0x1F) != 6 )
    {
      Scaleform::GFx::AS3::Value::Assign(value, v6);
      return;
    }
    other.Flags = 17;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = _this;
    other.value.VS._1.VInt = ind.Index;
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    other.Flags = (super ? 0x800 : 0) | 0x11;
    Scaleform::GFx::AS3::Value::Assign(value, &other);
  }
  Flags = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Flags = Flags & 0xFFFFFDE0;
      memset(&other.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 94
// RVA: 0x7F0E20
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VTable::GetValue(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // r9
  Scaleform::GFx::AS3::Traits *pTraits; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  v3 = &this->VTMethods.Data.Data[LODWORD(ind.Index)];
  if ( (v3->Flags & 0x1F) == 6 )
  {
    pTraits = this->pTraits;
    result->Flags = 7;
    result->Bonus.pWeakProxy = 0i64;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pTraits;
    result->value.VS._1.VInt = ind.Index;
  }
  else
  {
    result->Flags = v3->Flags;
    result->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    result->value = v3->value;
    if ( (v3->Flags & 0x1F) > 9 )
    {
      if ( (v3->Flags & 0x200) != 0 )
      {
        ++v3->Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (v3->Flags & 0x1F) == 10 )
        {
          ++v3->value.VS._1.VStr->RefCount;
          return result;
        }
        if ( (v3->Flags & 0x1F) > 0xA )
        {
          if ( (v3->Flags & 0x1F) <= 0xF )
          {
            VObj = v3->value.VS._1;
          }
          else
          {
            if ( (v3->Flags & 0x1F) > 0x11 )
              return result;
            VObj = (Scaleform::GFx::AS3::Value::V1U)v3->value.VS._2.VObj;
          }
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
}

// File Line: 133
// RVA: 0x81A630
void __fastcall Scaleform::GFx::AS3::VTable::SetMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *m,
        int dt)
{
  Scaleform::GFx::AS3::Value *v5; // rcx
  __int64 Index_low; // rcx
  Scaleform::GFx::AS3::Traits *pTraits; // rax
  int VInt; // edx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF

  v5 = 0i64;
  if ( dt >= 11 )
  {
    if ( dt <= 12 )
    {
      Index_low = LODWORD(ind.Index);
    }
    else
    {
      if ( dt != 13 )
        goto LABEL_7;
      Index_low = (unsigned int)(LODWORD(ind.Index) + 1);
    }
    v5 = &this->VTMethods.Data.Data[Index_low];
  }
LABEL_7:
  if ( (m->Flags & 0x1F) == 2 )
  {
    pTraits = this->pTraits;
    VInt = m->value.VS._1.VInt;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pTraits;
    other.value.VS._1.VInt = VInt;
    Scaleform::GFx::AS3::Value::Assign(v5, &other);
    Flags = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(v5, m);
  }
}

// File Line: 162
// RVA: 0x7ADEF0
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::VTable::AddMethod(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::AS3::Value *m,
        Scaleform::GFx::AS3::SlotInfo::BindingType dt)
{
  __int64 v8; // rdi
  unsigned __int64 Size; // rsi
  Scaleform::GFx::AS3::Traits *pTraits; // rax
  int VInt; // edx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-40h] BYREF

  v8 = 0i64;
  if ( dt == BT_Code )
  {
LABEL_7:
    Size = this->VTMethods.Data.Size;
    goto LABEL_8;
  }
  if ( dt != BT_Get )
  {
    if ( dt != BT_Set )
    {
      Size = 0i64;
      goto LABEL_9;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault(&this->VTMethods);
    goto LABEL_7;
  }
  Size = this->VTMethods.Data.Size;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault(&this->VTMethods);
LABEL_8:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault(&this->VTMethods);
LABEL_9:
  if ( (m->Flags & 0x1F) == 2 )
  {
    pTraits = this->pTraits;
    VInt = m->value.VS._1.VInt;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pTraits;
    other.value.VS._1.VInt = VInt;
    Scaleform::GFx::AS3::Value::Assign(&this->VTMethods.Data.Data[Size], &other);
    Flags = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&this->VTMethods.Data.Data[Size], m);
  }
  LOBYTE(v8) = dt != BT_Code;
  result->Index = this->VTMethods.Data.Size - (v8 + 1);
  return result;
}

// File Line: 203
// RVA: 0x7D6CC0
void __fastcall Scaleform::GFx::AS3::VTable::ForEachChild_GC(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 Size; // rdi
  __int64 i; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_VObj; // rdx
  Scaleform::GFx::AS3::Value::VU *p_value; // rcx

  Size = this->VTMethods.Data.Size;
  if ( Size )
  {
    for ( i = 0i64; ; ++i )
    {
      v8 = &this->VTMethods.Data.Data[i];
      v9 = v8->Flags & 0x1F;
      if ( v9 <= 0xA || (v8->Flags & 0x200) != 0 || (v8->Flags & 0x1F) < 0xB )
        goto LABEL_14;
      if ( (v8->Flags & 0x1F) > 0xF )
        break;
      p_value = &v8->value;
      if ( v8->value.VS._1.VStr )
      {
        p_VObj = 0i64;
        if ( v9 - 11 <= 4 )
          p_VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_value;
LABEL_13:
        op(prcc, p_VObj);
      }
LABEL_14:
      if ( !--Size )
        return;
    }
    if ( (v8->Flags & 0x1F) > 0x11 )
      goto LABEL_14;
    p_VObj = &v8->value.VS._2.VObj;
    if ( !*p_VObj )
      goto LABEL_14;
    goto LABEL_13;
  }
}

// File Line: 213
// RVA: 0x7AD4C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(
        Scaleform::GFx::AS3::InstanceTraits::Traits *this,
        Scaleform::GFx::AS3::VMAbcFile *file_ptr,
        Scaleform::GFx::AS3::InstanceTraits::Traits *itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // r15
  signed __int64 v5; // rdi
  unsigned __int64 FirstOwnSlotNum; // r9
  Scaleform::GFx::AS3::Slots *v7; // rsi
  Scaleform::GFx::ASStringNode *SlotNameNode; // r12
  unsigned __int64 v9; // rdx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // r11
  __int64 v14; // r9
  __int64 v15; // rdx
  __int64 *v16; // r8
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned __int64 *v18; // rbx
  unsigned int *v19; // rbx
  unsigned __int64 Prev; // rbx
  __int64 v21; // rbp
  Scaleform::GFx::AS3::SlotInfo *v22; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // rdx
  bool v24; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // r14
  const unsigned int *SlotValues; // rax
  unsigned __int64 PrevSlotIndex; // rbx
  __int64 v29; // rbp
  Scaleform::GFx::AS3::SlotInfo *v30; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v31; // rdx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v34; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v35; // rcx
  unsigned int RefCount; // eax
  int v37; // r15d
  Scaleform::GFx::AS3::SlotInfo *v38; // r14
  Scaleform::GFx::AS3::Instances::fl::Namespace *v39; // r14
  const unsigned int *v40; // rax
  __int64 Index; // rbx
  __int64 v42; // rbp
  Scaleform::GFx::AS3::SlotInfo *v43; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v44; // rdx
  Scaleform::GFx::AS3::SlotInfo *v46; // rbp
  Scaleform::GFx::AS3::Slots::Pair *v47; // r14
  __int64 v48; // rbx
  Scaleform::GFx::AS3::Value *v49; // rbx
  Scaleform::GFx::AS3::VTable *v50; // rax
  __int64 v51; // rbx
  Scaleform::GFx::AS3::Value *v52; // rbx
  Scaleform::GFx::AS3::VTable *v53; // rax
  Scaleform::GFx::AS3::AbsoluteIndex *v54; // rdx
  __int64 v55; // rbx
  __int64 v56; // rbx
  Scaleform::GFx::AS3::Value *v57; // rbx
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::VM::Error *v59; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Traits *i; // rbx
  Scaleform::GFx::AS3::VM *pVM; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::VM::Error v63; // [rsp+28h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+38h] [rbp-B0h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v65; // [rsp+68h] [rbp-80h] BYREF
  char v66; // [rsp+70h] [rbp-78h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v67; // [rsp+78h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::AbsoluteIndex v68; // [rsp+80h] [rbp-68h] BYREF
  Scaleform::GFx::ASStringNode *v69; // [rsp+88h] [rbp-60h]
  __int64 v70; // [rsp+90h] [rbp-58h]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+98h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v73; // [rsp+F8h] [rbp+10h]
  Scaleform::GFx::ASString name; // [rsp+100h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::SlotInfo *v75; // [rsp+108h] [rbp+20h]

  v73 = file_ptr;
  v70 = -2i64;
  v4 = this;
  pVM = this->pVM;
  v5 = 0i64;
  FirstOwnSlotNum = itr->FirstOwnSlotNum;
  if ( !(FirstOwnSlotNum + itr->VArray.Data.Size) )
  {
LABEL_114:
    for ( i = itr->pParent.pObject; i; file_ptr = v73 )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::VMAbcFile *, Scaleform::GFx::AS3::InstanceTraits::Traits *))i->vfptr[4].Finalize_GC)(
        i,
        file_ptr,
        v4);
      i = i->pParent.pObject;
    }
    return;
  }
  v7 = &this->Scaleform::GFx::AS3::Slots;
  while ( 1 )
  {
    if ( v5 < 0 || v5 < FirstOwnSlotNum )
      SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(itr->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v5);
    else
      SlotNameNode = itr->VArray.Data.Data[(unsigned int)v5 - FirstOwnSlotNum].Key.pObject;
    name.pNode = SlotNameNode;
    ++SlotNameNode->RefCount;
    if ( v5 < 0 || (v9 = itr->FirstOwnSlotNum, v5 < v9) )
      SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(itr->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v5);
    else
      SlotInfo = &itr->VArray.Data.Data[(unsigned int)v5 - v9].Value;
    v75 = SlotInfo;
    pObject = SlotInfo->pNs.pObject;
    ++SlotNameNode->RefCount;
    v69 = SlotNameNode;
    pTable = v7->Set.mHash.pTable;
    if ( !pTable )
      goto LABEL_21;
    SizeMask = pTable->SizeMask;
    v14 = (unsigned int)SizeMask & SlotNameNode->HashFlags;
    v15 = v14;
    v16 = (__int64 *)(&pTable[v14 + 1].EntryCount + v14);
    if ( *v16 == -2 || ((unsigned int)SizeMask & *(_DWORD *)(v16[1] + 28)) != v14 )
      goto LABEL_21;
    while ( 1 )
    {
      v17 = (Scaleform::GFx::ASStringNode *)v16[1];
      if ( ((unsigned int)SizeMask & v17->HashFlags) == v14 && v17 == SlotNameNode )
        break;
      v15 = *v16;
      if ( *v16 == -1 )
        goto LABEL_21;
      v16 = (__int64 *)(&pTable[v15 + 1].EntryCount + v15);
    }
    if ( v15 >= 0 && (v18 = &pTable[1].SizeMask + 3 * v15) != 0i64 )
      v19 = (unsigned int *)(v18 + 1);
    else
LABEL_21:
      v19 = 0i64;
    v24 = SlotNameNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
    if ( v19 )
    {
      Prev = *v19;
      v21 = (__int64)(*((_QWORD *)pObject + 5) << 60) >> 60;
      while ( 1 )
      {
        v22 = Prev < v7->FirstOwnSlotNum
            ? Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev)
            : &v7->VArray.Data.Data[(unsigned int)Prev - v7->FirstOwnSlotNum].Value;
        v23 = v22->pNs.pObject;
        if ( (int)(*((_DWORD *)v23 + 10) << 28) >> 28 == (_DWORD)v21 )
        {
          if ( (_DWORD)v21 == 1 )
            break;
          v24 = (_DWORD)v21 == 3 ? pObject == v23 : v23->Uri.pNode == pObject->Uri.pNode;
          if ( v24 )
            break;
        }
        if ( Prev >= v7->FirstOwnSlotNum )
          Prev = v7->VArray.Data.Data[Prev - v7->FirstOwnSlotNum].Prev;
        else
          Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, Prev);
        if ( (Prev & 0x8000000000000000ui64) != 0i64 )
          goto LABEL_44;
      }
      if ( Prev >= v7->FirstOwnSlotNum
         ? &v7->VArray.Data.Data[(unsigned int)Prev - v7->FirstOwnSlotNum].Value
         : Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev) )
      {
        goto LABEL_102;
      }
    }
LABEL_44:
    v26 = pVM->PublicNamespace.pObject;
    SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(v7, &name);
    if ( SlotValues )
    {
      PrevSlotIndex = *SlotValues;
      v29 = (__int64)(*((_QWORD *)v26 + 5) << 60) >> 60;
      while ( 1 )
      {
        v30 = PrevSlotIndex < v7->FirstOwnSlotNum
            ? Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)PrevSlotIndex)
            : &v7->VArray.Data.Data[(unsigned int)PrevSlotIndex - v7->FirstOwnSlotNum].Value;
        v31 = v30->pNs.pObject;
        if ( (int)(*((_DWORD *)v31 + 10) << 28) >> 28 == (_DWORD)v29 )
        {
          if ( (_DWORD)v29 == 1 )
            break;
          if ( (_DWORD)v29 == 3 ? v26 == v31 : v31->Uri.pNode == v26->Uri.pNode )
            break;
        }
        if ( PrevSlotIndex >= v7->FirstOwnSlotNum )
          PrevSlotIndex = v7->VArray.Data.Data[PrevSlotIndex - v7->FirstOwnSlotNum].Prev;
        else
          PrevSlotIndex = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, PrevSlotIndex);
        if ( (PrevSlotIndex & 0x8000000000000000ui64) != 0i64 )
          goto LABEL_63;
      }
      if ( PrevSlotIndex >= v7->FirstOwnSlotNum )
        p_Value = &v7->VArray.Data.Data[(unsigned int)PrevSlotIndex - v7->FirstOwnSlotNum].Value;
      else
        p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)PrevSlotIndex);
    }
    else
    {
LABEL_63:
      p_Value = 0i64;
    }
    if ( p_Value )
    {
      Scaleform::GFx::AS3::SlotInfo::SlotInfo(&v, p_Value);
      v34 = SlotInfo->pNs.pObject;
      v35 = v.pNs.pObject;
      if ( v34 != v.pNs.pObject )
      {
        if ( v34 )
        {
          v34->RefCount = (v34->RefCount + 1) & 0x8FBFFFFF;
          v35 = v.pNs.pObject;
        }
        if ( v35 )
        {
          if ( ((unsigned __int8)v35 & 1) != 0 )
          {
            v.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v35 - 1);
          }
          else
          {
            RefCount = v35->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v35->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
            }
          }
        }
        v.pNs.pObject = v34;
      }
      Scaleform::GFx::AS3::Slots::Add(v7, &result, &name, &v);
      Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
      goto LABEL_102;
    }
    if ( (itr->Flags & 4) == 0 )
      break;
    v37 = (int)(*(_DWORD *)SlotInfo << 17) >> 27;
    v38 = v75;
    *((_QWORD *)v75->pNs.pObject + 5) |= 0x10ui64;
    v39 = v38->pNs.pObject;
    v40 = Scaleform::GFx::AS3::Slots::FindSlotValues(v7, &name);
    if ( v40 )
    {
      Index = *v40;
      v42 = (__int64)(*((_QWORD *)v39 + 5) << 60) >> 60;
      while ( 1 )
      {
        v43 = Index < v7->FirstOwnSlotNum
            ? Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Index)
            : &v7->VArray.Data.Data[(unsigned int)Index - v7->FirstOwnSlotNum].Value;
        v44 = v43->pNs.pObject;
        if ( (int)(*((_DWORD *)v44 + 10) << 28) >> 28 == (_DWORD)v42 )
        {
          if ( (_DWORD)v42 == 1 )
            break;
          if ( (_DWORD)v42 == 3 ? v39 == v44 : v44->Uri.pNode == v39->Uri.pNode )
            break;
        }
        if ( Index >= v7->FirstOwnSlotNum )
          Index = v7->VArray.Data.Data[Index - v7->FirstOwnSlotNum].Prev;
        else
          Index = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, Index);
        if ( Index < 0 )
          goto LABEL_91;
      }
    }
    else
    {
LABEL_91:
      Index = -1i64;
    }
    v46 = v75;
    if ( Index < 0 )
      Index = Scaleform::GFx::AS3::Slots::Add(v7, &v65, &name, v75)->Index;
    v47 = &v7->VArray.Data.Data[(unsigned int)Index - v7->FirstOwnSlotNum];
    if ( v37 < 11 )
      goto LABEL_102;
    if ( v37 <= 12 )
    {
      v56 = (__int64)*(_DWORD *)v46 >> 15;
      v57 = &Scaleform::GFx::AS3::Traits::GetVT(itr)->VTMethods.Data.Data[(unsigned int)v56];
      VT = Scaleform::GFx::AS3::Traits::GetVT(this);
      *(_DWORD *)&v47->Value = *(_DWORD *)&v47->Value & 0x3FF | ((v37 & 0x1F | (32
                                                                              * (unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                                                VT,
                                                                                                (Scaleform::GFx::AS3::AbsoluteIndex *)&v63,
                                                                                                v57,
                                                                                                (Scaleform::GFx::AS3::SlotInfo::BindingType)v37)->Index)) << 10);
LABEL_102:
      v4 = this;
      goto LABEL_103;
    }
    if ( v37 == 13 )
    {
      v55 = ((__int64)*(_DWORD *)v46 >> 15) + 1;
      v52 = &Scaleform::GFx::AS3::Traits::GetVT(itr)->VTMethods.Data.Data[(unsigned int)v55];
      v4 = this;
      v53 = Scaleform::GFx::AS3::Traits::GetVT(this);
      v54 = &v67;
    }
    else
    {
      if ( v37 != 14 )
        goto LABEL_102;
      v48 = (__int64)*(_DWORD *)v46 >> 15;
      v49 = &Scaleform::GFx::AS3::Traits::GetVT(itr)->VTMethods.Data.Data[(unsigned int)v48];
      v4 = this;
      v50 = Scaleform::GFx::AS3::Traits::GetVT(this);
      *(_DWORD *)&v47->Value = *(_DWORD *)&v47->Value & 0x3FF | ((unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                                 v50,
                                                                                 &v68,
                                                                                 v49,
                                                                                 BT_Get)->Index << 15) | 0x3000;
      v51 = ((__int64)*(_DWORD *)v46 >> 15) + 1;
      v52 = &Scaleform::GFx::AS3::Traits::GetVT(itr)->VTMethods.Data.Data[(unsigned int)v51];
      v53 = Scaleform::GFx::AS3::Traits::GetVT(this);
      v54 = (Scaleform::GFx::AS3::AbsoluteIndex *)&v66;
    }
    *(_DWORD *)&v47->Value = *(_DWORD *)&v47->Value & 0x3FF | ((unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                               v53,
                                                                               v54,
                                                                               v52,
                                                                               BT_Set)->Index << 15) | 0x3400;
LABEL_103:
    v24 = SlotNameNode->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
    if ( v5 < 0 || v5 < itr->FirstOwnSlotNum + itr->VArray.Data.Size )
      ++v5;
    FirstOwnSlotNum = itr->FirstOwnSlotNum;
    if ( (unsigned int)v5 >= FirstOwnSlotNum + itr->VArray.Data.Size )
    {
      file_ptr = v73;
      goto LABEL_114;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v63, 1122, this->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pVM, v59, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v63.Message.pNode;
  v24 = v63.Message.pNode->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v24 = SlotNameNode->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
}

