// File Line: 73
// RVA: 0x7EC260
void __fastcall Scaleform::GFx::AS3::VTable::GetMethod(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Object *_this, bool super)
{
  Scaleform::GFx::AS3::Value *v5; // r10
  Scaleform::GFx::AS3::Value *v6; // rdx
  long double v7; // rax
  unsigned int v8; // edi
  bool v9; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-28h]

  v5 = value;
  v6 = &this->VTMethods.Data.Data[LODWORD(ind.Index)];
  if ( (v6->Flags & 0x1F) == 5 )
  {
    v7 = v6->value.VNumber;
    other.Flags = 16;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = _this;
    other.value.VNumber = v7;
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::Value::Assign(v5, &other);
  }
  else
  {
    if ( (v6->Flags & 0x1F) != 6 )
    {
      Scaleform::GFx::AS3::Value::Assign(v5, v6);
      return;
    }
    other.Flags = 17;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2.VObj = _this;
    other.value.VS._1.VInt = ind.Index;
    if ( _this )
      _this->RefCount = (_this->RefCount + 1) & 0x8FBFFFFF;
    other.Flags = (super ? 0x800 : 0) | 0x11;
    Scaleform::GFx::AS3::Value::Assign(v5, &other);
  }
  v8 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v9 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Flags = v8 & 0xFFFFFDE0;
      other.value = 0ui64;
      other.Bonus.pWeakProxy = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 94
// RVA: 0x7F0E20
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VTable::GetValue(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // r9
  Scaleform::GFx::AS3::Traits *v4; // rax
  int v5; // eax
  long double v6; // rcx

  v3 = &this->VTMethods.Data.Data[LODWORD(ind.Index)];
  if ( (v3->Flags & 0x1F) == 6 )
  {
    v4 = this->pTraits;
    result->Flags = 7;
    result->Bonus.pWeakProxy = 0i64;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v4;
    result->value.VS._1.VInt = ind.Index;
  }
  else
  {
    result->Flags = v3->Flags;
    result->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    result->value = v3->value;
    v5 = v3->Flags & 0x1F;
    if ( v5 > 9 )
    {
      if ( (v3->Flags >> 9) & 1 )
      {
        ++v3->Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( v5 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v3->value.VNumber + 24i64);
          return result;
        }
        if ( v5 > 10 )
        {
          if ( v5 <= 15 )
          {
            v6 = v3->value.VNumber;
          }
          else
          {
            if ( v5 > 17 )
              return result;
            v6 = *(double *)&v3->value.VS._2.VObj;
          }
          if ( v6 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v6 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v6 + 32i64) + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
}

// File Line: 133
// RVA: 0x81A630
void __fastcall Scaleform::GFx::AS3::VTable::SetMethod(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *m, Scaleform::GFx::AS3::SlotInfo::BindingType dt)
{
  Scaleform::GFx::AS3::Value::V2U *v4; // r10
  Scaleform::GFx::AS3::Value *v5; // rcx
  __int64 v6; // rcx
  Scaleform::GFx::AS3::Value::V2U v7; // rax
  int v8; // edx
  unsigned int v9; // ebx
  bool v10; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v4 = (Scaleform::GFx::AS3::Value::V2U *)this;
  v5 = 0i64;
  if ( (signed int)dt >= 11 )
  {
    if ( (signed int)dt <= 12 )
    {
      v6 = LODWORD(ind.Index);
    }
    else
    {
      if ( dt != 13 )
        goto LABEL_7;
      v6 = (unsigned int)(LODWORD(ind.Index) + 1);
    }
    v5 = (Scaleform::GFx::AS3::Value *)((char *)v4[1].VObj + 32 * v6);
  }
LABEL_7:
  if ( (m->Flags & 0x1F) == 2 )
  {
    v7.VObj = v4->VObj;
    v8 = m->value.VS._1.VInt;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2 = v7;
    other.value.VS._1.VInt = v8;
    Scaleform::GFx::AS3::Value::Assign(v5, &other);
    v9 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v9 & 0xFFFFFDE0;
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
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::VTable::AddMethod(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::AbsoluteIndex *result, Scaleform::GFx::AS3::Value *m, Scaleform::GFx::AS3::SlotInfo::BindingType dt)
{
  Scaleform::GFx::AS3::SlotInfo::BindingType v4; // ebp
  Scaleform::GFx::AS3::Value *v5; // r15
  Scaleform::GFx::AS3::AbsoluteIndex *v6; // r12
  Scaleform::GFx::AS3::VTable *v7; // r14
  __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  Scaleform::GFx::AS3::Value::V2U v10; // rax
  int v11; // edx
  unsigned int v12; // ebx
  bool v13; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-40h]

  v4 = dt;
  v5 = m;
  v6 = result;
  v7 = this;
  v8 = 0i64;
  if ( dt == 11 )
  {
LABEL_7:
    v9 = v7->VTMethods.Data.Size;
    goto LABEL_8;
  }
  if ( dt != 12 )
  {
    if ( dt != 13 )
    {
      v9 = 0i64;
      goto LABEL_9;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> > *)&this->VTMethods.Data);
    goto LABEL_7;
  }
  v9 = this->VTMethods.Data.Size;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> > *)&this->VTMethods.Data);
LABEL_8:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>>::PushDefault((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy> > *)&v7->VTMethods.Data);
LABEL_9:
  if ( (v5->Flags & 0x1F) == 2 )
  {
    v10.VObj = (Scaleform::GFx::AS3::Object *)v7->pTraits;
    v11 = v5->value.VS._1.VInt;
    other.Flags = 6;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._2 = v10;
    other.value.VS._1.VInt = v11;
    Scaleform::GFx::AS3::Value::Assign(&v7->VTMethods.Data.Data[v9], &other);
    v12 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v13 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v12 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&v7->VTMethods.Data.Data[v9], v5);
  }
  LOBYTE(v8) = v4 != 11;
  v6->Index = v7->VTMethods.Data.Size - (v8 + 1);
  return v6;
}

// File Line: 203
// RVA: 0x7D6CC0
void __fastcall Scaleform::GFx::AS3::VTable::ForEachChild_GC(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rdi
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rsi
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // rbp
  Scaleform::GFx::AS3::VTable *v6; // r14
  __int64 v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdx
  int v9; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rdx
  signed __int64 v11; // rcx

  v3 = this->VTMethods.Data.Size;
  v4 = op;
  v5 = prcc;
  v6 = this;
  if ( v3 )
  {
    v7 = 0i64;
    while ( 1 )
    {
      v8 = &v6->VTMethods.Data.Data[v7];
      v9 = v8->Flags & 0x1F;
      if ( v9 <= 10 || (v8->Flags >> 9) & 1 || v9 < 11 )
        goto LABEL_14;
      if ( v9 > 15 )
        break;
      v11 = (signed __int64)&v8->value;
      if ( *(_QWORD *)&v8->value.VNumber )
      {
        v10 = 0i64;
        if ( (unsigned int)(v9 - 11) <= 4 )
          v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v11;
LABEL_13:
        v4(v5, v10);
      }
LABEL_14:
      ++v7;
      if ( !--v3 )
        return;
    }
    if ( v9 > 17 )
      goto LABEL_14;
    v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v8->value.VS._2.VObj;
    if ( !*v10 )
      goto LABEL_14;
    goto LABEL_13;
  }
}

// File Line: 213
// RVA: 0x7AD4C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Traits::AddInterfaceSlots(Scaleform::GFx::AS3::InstanceTraits::Traits *this, Scaleform::GFx::AS3::VMAbcFile *file_ptr, Scaleform::GFx::AS3::InstanceTraits::Traits *itr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // r13
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // r15
  Scaleform::GFx::AS3::AbsoluteIndex v5; // rdi
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS3::Slots *v7; // rsi
  Scaleform::GFx::ASStringNode *v8; // r12
  unsigned __int64 v9; // rdx
  Scaleform::GFx::AS3::SlotInfo *v10; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::TableType *v12; // r10
  unsigned __int64 v13; // r11
  __int64 v14; // r9
  signed __int64 v15; // rdx
  unsigned __int64 *v16; // r8
  Scaleform::GFx::ASStringNode *v17; // rcx
  signed __int64 v18; // rbx
  unsigned int *v19; // rbx
  __int64 v20; // rbx
  __int64 v21; // rbp
  Scaleform::GFx::AS3::SlotInfo *v22; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // rdx
  bool v24; // zf
  signed __int64 v25; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // r14
  const unsigned int *v27; // rax
  __int64 v28; // rbx
  __int64 v29; // rbp
  Scaleform::GFx::AS3::SlotInfo *v30; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v31; // rdx
  bool v32; // zf
  Scaleform::GFx::AS3::SlotInfo *v33; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v34; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v35; // rcx
  unsigned int v36; // eax
  Scaleform::GFx::AS3::SlotInfo::BindingType v37; // er15
  Scaleform::GFx::AS3::SlotInfo *v38; // r14
  Scaleform::GFx::AS3::Instances::fl::Namespace *v39; // r14
  const unsigned int *v40; // rax
  Scaleform::GFx::AS3::AbsoluteIndex v41; // rbx
  __int64 v42; // rbp
  Scaleform::GFx::AS3::SlotInfo *v43; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v44; // rdx
  bool v45; // zf
  Scaleform::GFx::AS3::SlotInfo *v46; // rbp
  Scaleform::GFx::AS3::Slots::Pair *v47; // r14
  signed __int64 v48; // rbx
  Scaleform::GFx::AS3::Value *v49; // rbx
  Scaleform::GFx::AS3::VTable *v50; // rax
  signed __int64 v51; // rbx
  Scaleform::GFx::AS3::Value *v52; // rbx
  Scaleform::GFx::AS3::VTable *v53; // rax
  Scaleform::GFx::AS3::AbsoluteIndex *v54; // rdx
  signed __int64 v55; // rbx
  signed __int64 v56; // rbx
  Scaleform::GFx::AS3::Value *v57; // rbx
  Scaleform::GFx::AS3::VTable *v58; // rax
  Scaleform::GFx::AS3::VM::Error *v59; // rax
  Scaleform::GFx::ASStringNode *v60; // rcx
  Scaleform::GFx::AS3::Traits *i; // rbx
  Scaleform::GFx::AS3::VM *v62; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::AbsoluteIndex v63; // [rsp+28h] [rbp-C0h]
  Scaleform::GFx::ASStringNode *v64; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS3::SlotInfo v; // [rsp+38h] [rbp-B0h]
  Scaleform::GFx::AS3::AbsoluteIndex v66; // [rsp+68h] [rbp-80h]
  char v67; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::AS3::AbsoluteIndex v68; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::AS3::AbsoluteIndex v69; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::ASStringNode *v70; // [rsp+88h] [rbp-60h]
  __int64 v71; // [rsp+90h] [rbp-58h]
  Scaleform::GFx::AS3::AbsoluteIndex result; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::AS3::InstanceTraits::Traits *v73; // [rsp+F0h] [rbp+8h]
  Scaleform::GFx::AS3::VMAbcFile *v74; // [rsp+F8h] [rbp+10h]
  Scaleform::GFx::ASString name; // [rsp+100h] [rbp+18h]
  Scaleform::GFx::AS3::SlotInfo *v76; // [rsp+108h] [rbp+20h]

  v74 = file_ptr;
  v73 = this;
  v71 = -2i64;
  v3 = itr;
  v4 = this;
  v62 = this->pVM;
  v5.Index = 0i64;
  v6 = itr->FirstOwnSlotNum;
  if ( !(v6 + itr->VArray.Data.Size) )
  {
LABEL_119:
    for ( i = v3->pParent.pObject; i; file_ptr = v74 )
    {
      ((void (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::VMAbcFile *, Scaleform::GFx::AS3::InstanceTraits::Traits *))i->vfptr[4].Finalize_GC)(
        i,
        file_ptr,
        v4);
      i = i->pParent.pObject;
    }
    return;
  }
  v7 = (Scaleform::GFx::AS3::Slots *)&this->FirstOwnSlotNum;
  while ( 1 )
  {
    if ( v5.Index < 0 || v5.Index < v6 )
      v8 = Scaleform::GFx::AS3::Slots::GetSlotNameNode(v3->Parent, v5);
    else
      v8 = v3->VArray.Data.Data[LODWORD(v5.Index) - v6].Key.pObject;
    name.pNode = v8;
    ++v8->RefCount;
    if ( v5.Index < 0 || (v9 = v3->FirstOwnSlotNum, v5.Index < v9) )
      v10 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v3->Parent, v5);
    else
      v10 = &v3->VArray.Data.Data[LODWORD(v5.Index) - v3->FirstOwnSlotNum].Value;
    v76 = v10;
    v11 = v10->pNs.pObject;
    ++v8->RefCount;
    v70 = v8;
    v12 = v7->Set.mHash.pTable;
    if ( !v12 )
      goto LABEL_21;
    v13 = v12->SizeMask;
    v14 = (unsigned int)v13 & v8->HashFlags;
    v15 = v14;
    v16 = &v12->EntryCount + v14 + 2 * (v14 + 1);
    if ( *v16 == -2i64 || ((unsigned int)v13 & *(_DWORD *)(v16[1] + 28)) != v14 )
      goto LABEL_21;
    while ( 1 )
    {
      v17 = (Scaleform::GFx::ASStringNode *)v16[1];
      if ( ((unsigned int)v13 & v17->HashFlags) == v14 && v17 == v8 )
        break;
      v15 = *v16;
      if ( *v16 == -1i64 )
        goto LABEL_21;
      v16 = &v12->EntryCount + v15 + 2 * (v15 + 1);
    }
    if ( v15 >= 0 && (v18 = (signed __int64)v12 + 24 * (v15 + 1)) != 0 )
      v19 = (unsigned int *)(v18 + 8);
    else
LABEL_21:
      v19 = 0i64;
    v24 = v8->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v19 )
    {
      v20 = *v19;
      if ( v20 >= 0 )
      {
        v21 = *((_QWORD *)v11 + 5) << 60 >> 60;
        while ( 1 )
        {
          v22 = v20 < 0 || v20 < v7->FirstOwnSlotNum ? Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                         v7->Parent,
                                                         (Scaleform::GFx::AS3::AbsoluteIndex)v20) : &v7->VArray.Data.Data[(unsigned int)v20 - v7->FirstOwnSlotNum].Value;
          v23 = v22->pNs.pObject;
          if ( (unsigned int)(*((_QWORD *)v23 + 5) << 60 >> 60) == (_DWORD)v21 )
          {
            if ( (_DWORD)v21 == 1 )
              break;
            v24 = (_DWORD)v21 == 3 ? v11 == v23 : v23->Uri.pNode == v11->Uri.pNode;
            if ( v24 )
              break;
          }
          if ( v20 >= v7->FirstOwnSlotNum )
            v20 = v7->VArray.Data.Data[v20 - v7->FirstOwnSlotNum].Prev;
          else
            v20 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, v20);
          if ( v20 < 0 )
            goto LABEL_47;
        }
        if ( v20 >= 0 )
        {
          v25 = (signed __int64)(v20 >= v7->FirstOwnSlotNum ? &v7->VArray.Data.Data[(unsigned int)v20
                                                                                  - v7->FirstOwnSlotNum].Value : Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v20));
          if ( v25 )
            goto LABEL_107;
        }
      }
    }
LABEL_47:
    v26 = v62->PublicNamespace.pObject;
    v27 = Scaleform::GFx::AS3::Slots::FindSlotValues(v7, &name);
    if ( !v27 )
      goto LABEL_68;
    v28 = *v27;
    v29 = *((_QWORD *)v26 + 5) << 60 >> 60;
    while ( 1 )
    {
      v30 = v28 < 0 || v28 < v7->FirstOwnSlotNum ? Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                     v7->Parent,
                                                     (Scaleform::GFx::AS3::AbsoluteIndex)v28) : &v7->VArray.Data.Data[(unsigned int)v28 - v7->FirstOwnSlotNum].Value;
      v31 = v30->pNs.pObject;
      if ( (unsigned int)(*((_QWORD *)v31 + 5) << 60 >> 60) == (_DWORD)v29 )
      {
        if ( (_DWORD)v29 == 1 )
          break;
        v32 = (_DWORD)v29 == 3 ? v26 == v31 : v31->Uri.pNode == v26->Uri.pNode;
        if ( v32 )
          break;
      }
      if ( v28 >= v7->FirstOwnSlotNum )
        v28 = v7->VArray.Data.Data[v28 - v7->FirstOwnSlotNum].Prev;
      else
        v28 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, v28);
      if ( v28 < 0 )
        goto LABEL_68;
    }
    if ( v28 >= 0 )
    {
      if ( v28 >= v7->FirstOwnSlotNum )
        v33 = &v7->VArray.Data.Data[(unsigned int)v28 - v7->FirstOwnSlotNum].Value;
      else
        v33 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v28);
    }
    else
    {
LABEL_68:
      v33 = 0i64;
    }
    if ( v33 )
    {
      Scaleform::GFx::AS3::SlotInfo::SlotInfo(&v, v33);
      v34 = v10->pNs.pObject;
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
          if ( (unsigned __int8)v35 & 1 )
          {
            v.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v35 - 1);
          }
          else
          {
            v36 = v35->RefCount;
            if ( v36 & 0x3FFFFF )
            {
              v35->RefCount = v36 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v35->vfptr);
            }
          }
        }
        v.pNs.pObject = v34;
      }
      Scaleform::GFx::AS3::Slots::Add(v7, &result, &name, &v);
      Scaleform::GFx::AS3::SlotInfo::~SlotInfo(&v);
      goto LABEL_107;
    }
    if ( !((LOBYTE(v3->Flags) >> 2) & 1) )
      break;
    v37 = *(_DWORD *)v10 << 17 >> 27;
    v38 = v76;
    *((_QWORD *)v76->pNs.pObject + 5) |= 0x10ui64;
    v39 = v38->pNs.pObject;
    v40 = Scaleform::GFx::AS3::Slots::FindSlotValues(v7, &name);
    if ( v40 )
    {
      v41.Index = *v40;
      v42 = *((_QWORD *)v39 + 5) << 60 >> 60;
      while ( 1 )
      {
        v43 = v41.Index < v7->FirstOwnSlotNum ? Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, v41) : &v7->VArray.Data.Data[LODWORD(v41.Index) - v7->FirstOwnSlotNum].Value;
        v44 = v43->pNs.pObject;
        if ( (unsigned int)(*((_QWORD *)v44 + 5) << 60 >> 60) == (_DWORD)v42 )
        {
          if ( (_DWORD)v42 == 1 )
            break;
          v45 = (_DWORD)v42 == 3 ? v39 == v44 : v44->Uri.pNode == v39->Uri.pNode;
          if ( v45 )
            break;
        }
        if ( v41.Index >= v7->FirstOwnSlotNum )
          v41.Index = v7->VArray.Data.Data[v41.Index - v7->FirstOwnSlotNum].Prev;
        else
          v41.Index = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, v41.Index);
        if ( v41.Index < 0 )
          goto LABEL_96;
      }
    }
    else
    {
LABEL_96:
      v41.Index = -1i64;
    }
    v46 = v76;
    if ( v41.Index < 0 )
      v41.Index = Scaleform::GFx::AS3::Slots::Add(v7, &v66, &name, v76)->Index;
    v47 = &v7->VArray.Data.Data[LODWORD(v41.Index) - v7->FirstOwnSlotNum];
    if ( (signed int)v37 < 11 )
      goto LABEL_107;
    if ( (signed int)v37 <= 12 )
    {
      v56 = (signed __int64)*(_DWORD *)v46 >> 15;
      v57 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v3->vfptr)->VTMethods.Data.Data[(unsigned int)v56];
      v58 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v73->vfptr);
      v47->Value = (Scaleform::GFx::AS3::SlotInfo)(*(_DWORD *)&v47->Value & 0x3FF | ((v37 & 0x1F | 32
                                                                                                 * (unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(v58, &v63, v57, v37)->Index) << 10));
LABEL_107:
      v4 = v73;
      goto LABEL_108;
    }
    if ( v37 == 13 )
    {
      v55 = ((signed __int64)*(_DWORD *)v46 >> 15) + 1;
      v52 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v3->vfptr)->VTMethods.Data.Data[(unsigned int)v55];
      v4 = v73;
      v53 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v73->vfptr);
      v54 = &v68;
    }
    else
    {
      if ( v37 != 14 )
        goto LABEL_107;
      v48 = (signed __int64)*(_DWORD *)v46 >> 15;
      v49 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v3->vfptr)->VTMethods.Data.Data[(unsigned int)v48];
      v4 = v73;
      v50 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v73->vfptr);
      v47->Value = (Scaleform::GFx::AS3::SlotInfo)(*(_DWORD *)&v47->Value & 0x3FF | ((unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                                                     v50,
                                                                                                     &v69,
                                                                                                     v49,
                                                                                                     BT_Get)->Index << 15) | 0x3000);
      v51 = ((signed __int64)*(_DWORD *)v46 >> 15) + 1;
      v52 = &Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v3->vfptr)->VTMethods.Data.Data[(unsigned int)v51];
      v53 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)&v73->vfptr);
      v54 = (Scaleform::GFx::AS3::AbsoluteIndex *)&v67;
    }
    v47->Value = (Scaleform::GFx::AS3::SlotInfo)(*(_DWORD *)&v47->Value & 0x3FF | ((unsigned int)Scaleform::GFx::AS3::VTable::AddMethod(
                                                                                                   v53,
                                                                                                   v54,
                                                                                                   v52,
                                                                                                   BT_Set)->Index << 15) | 0x3400);
LABEL_108:
    v24 = v8->RefCount-- == 1;
    if ( v24 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v5.Index < 0 || v5.Index < v3->FirstOwnSlotNum + v3->VArray.Data.Size )
      ++v5.Index;
    v6 = v3->FirstOwnSlotNum;
    if ( LODWORD(v5.Index) >= v6 + v3->VArray.Data.Size )
    {
      file_ptr = v74;
      goto LABEL_119;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&v63,
    eIllegalInterfaceMethodBodyError,
    v73->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v73->pVM, v59, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v60 = v64;
  v24 = v64->RefCount == 1;
  --v60->RefCount;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v24 = v8->RefCount-- == 1;
  if ( v24 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

