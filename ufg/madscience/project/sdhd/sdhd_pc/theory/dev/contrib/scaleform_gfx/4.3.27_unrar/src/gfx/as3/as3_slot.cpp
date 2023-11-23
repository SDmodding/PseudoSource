// File Line: 120
// RVA: 0x781EF0
void __fastcall Scaleform::GFx::AS3::SlotInfo::SlotInfo(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::SlotInfo *other)
{
  int v3; // r8d
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rax

  *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 3;
  v3 = *(_DWORD *)this ^ (*(_DWORD *)other ^ *(_DWORD *)this) & 0xC;
  *(_DWORD *)this = v3;
  v4 = v3 ^ (*(_DWORD *)other ^ v3) & 0x30;
  *(_DWORD *)this = v4;
  v5 = v4 ^ (*(_DWORD *)other ^ v4) & 0xC0;
  *(_DWORD *)this = v5;
  v6 = v5 ^ (*(_DWORD *)other ^ v5) & 0x300;
  *(_DWORD *)this = v6;
  v7 = v6 ^ (*(_DWORD *)other ^ v6) & 0x7C00;
  *(_DWORD *)this = v7;
  *(_DWORD *)this = *(_DWORD *)other ^ (*(_DWORD *)other ^ v7) & 0x7FFF;
  this->Padding01 = 0;
  pObject = other->pNs.pObject;
  this->pNs.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v9 = other->CTraits.pObject;
  this->CTraits.pObject = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v10 = other->File.pObject;
  this->File.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  this->TI = other->TI;
  v11 = other->Name.pObject;
  if ( v11 )
    ++v11->RefCount;
  this->Name.pObject = other->Name.pObject;
}

// File Line: 124
// RVA: 0x78DEC0
void __fastcall Scaleform::GFx::AS3::SlotInfo::~SlotInfo(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::ASStringNode *pObject; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v4; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rcx
  unsigned int v9; // eax

  pObject = this->Name.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  }
  v4 = this->File.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v4 - 1);
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
  v6 = this->CTraits.pObject;
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      this->CTraits.pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)v6 - 1);
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
  v8 = this->pNs.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
}

// File Line: 137
// RVA: 0x7909C0
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::SlotInfo::operator=(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::SlotInfo *other)
{
  int v4; // r8d
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  Scaleform::GFx::ASStringNode *pObject; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx

  if ( this != other )
  {
    *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 3;
    v4 = *(_DWORD *)this ^ (*(_DWORD *)this ^ *(_DWORD *)other) & 0xC;
    *(_DWORD *)this = v4;
    v5 = v4 ^ (*(_DWORD *)other ^ v4) & 0x30;
    *(_DWORD *)this = v5;
    v6 = v5 ^ (*(_DWORD *)other ^ v5) & 0xC0;
    *(_DWORD *)this = v6;
    v7 = v6 ^ (*(_DWORD *)other ^ v6) & 0x300;
    *(_DWORD *)this = v7;
    *(_DWORD *)this = v7 ^ (*(_DWORD *)other ^ v7) & 0x7C00;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->pNs,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&other->pNs);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->CTraits,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&other->CTraits);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->File,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&other->File);
    this->TI = other->TI;
    *(_DWORD *)this = *(_DWORD *)other ^ (*(_DWORD *)this ^ *(_DWORD *)other) & 0x7FFF;
    pObject = other->Name.pObject;
    if ( pObject )
      ++pObject->RefCount;
    v9 = this->Name.pObject;
    if ( v9 )
    {
      if ( v9->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    this->Name.pObject = other->Name.pObject;
  }
  return this;
}

// File Line: 160
// RVA: 0x7F8550
bool __fastcall Scaleform::GFx::AS3::SlotInfo::IsConst(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  bool result; // al

  result = 1;
  if ( (*(_BYTE *)this & 3) == 0 )
  {
    TI = this->TI;
    if ( !TI || (TI->kind & 0xF) != 6 )
      return 0;
  }
  return result;
}

// File Line: 167
// RVA: 0x7F83F0
bool __fastcall Scaleform::GFx::AS3::SlotInfo::IsClass(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  bool result; // al

  result = 1;
  if ( (*(_DWORD *)this & 0x7C00) != 1024 )
  {
    TI = this->TI;
    if ( !TI || (TI->kind & 0xF) != 4 )
      return 0;
  }
  return result;
}

// File Line: 191
// RVA: 0x7EF530
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *value)
{
  __int64 v7; // rbx
  Scaleform::GFx::AS3::Class **v8; // rdx
  Scaleform::GFx::AS3::Class *v9; // rdx
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::Value::V1U v12; // xmm0_8
  Scaleform::GFx::ASStringNode *v13; // rdx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  bool v17; // r12
  Scaleform::GFx::AS3::VTable *v18; // rcx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Value *v20; // rax
  Scaleform::GFx::AS3::Value *p_func; // rcx
  Scaleform::GFx::AS3::VTable *v22; // rax
  Scaleform::GFx::AS3::Traits *v23; // rax
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::VM::Error *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::VM::Error super; // [rsp+20h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::VM::Error result_on_stack; // [rsp+30h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::Value v32; // [rsp+60h] [rbp-9h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp+4Fh] BYREF
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::AS3::VTable *v35; // [rsp+E0h] [rbp+77h]
  int v36; // [rsp+E8h] [rbp+7Fh]

  v7 = (__int64)*(_DWORD *)this >> 15;
  switch ( (int)(*(_DWORD *)this << 17) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)retaddr->value.VS._1.VStr[4].pManager + (unsigned int)v7);
      goto LABEL_52;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)((char *)retaddr->value.VS._1.VStr + (unsigned int)v7));
      goto LABEL_52;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe(
        (Scaleform::GFx::AS3::STPtr *)((char *)retaddr->value.VS._1.VStr + (unsigned int)v7),
        value);
      goto LABEL_52;
    case 4:
      v8 = (Scaleform::GFx::AS3::Class **)((char *)retaddr->value.VS._1.VStr + (unsigned int)v7);
      if ( v8 )
      {
        v9 = *v8;
        if ( v9 && (v9->pTraits.pObject->Flags & 0x20) != 0 )
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
        else
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
      }
      goto LABEL_52;
    case 5:
      v10 = value->Flags & 0xFFFFFFE0 | 1;
      LOBYTE(super.ID) = *((_BYTE *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7);
      goto LABEL_11;
    case 6:
      v10 = value->Flags & 0xFFFFFFE0 | 2;
      super.ID = *(_DWORD *)((char *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7);
      goto LABEL_11;
    case 7:
      v10 = value->Flags & 0xFFFFFFE0 | 3;
      super.ID = *(_DWORD *)((char *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7);
LABEL_11:
      value->Flags = v10;
      value->value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)&super.ID;
      pNode = super.Message.pNode;
      goto LABEL_12;
    case 8:
      v12 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7);
      value->Flags = value->Flags & 0xFFFFFFE0 | 4;
      value->value.VS._1 = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result_on_stack.Message.pNode;
      goto LABEL_52;
    case 9:
      v13 = *(Scaleform::GFx::ASStringNode **)((char *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7);
      if ( v13 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v13);
      }
      else
      {
        value->Flags &= 0xFFFFFFEC;
        value->Flags |= 0xCu;
        value->value.VS._1.VStr = 0i64;
        pNode = result_on_stack.Message.pNode;
LABEL_12:
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      }
      goto LABEL_52;
    case 10:
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              vm->StringManagerRef,
              &resulta,
              *(const char **)((char *)&retaddr->value.VS._1.VStr->pData + (unsigned int)v7));
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, v14);
      v15 = resulta.pNode;
      v16 = resulta.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_52;
    case 11:
      v17 = 0;
      v18 = v35;
      if ( v35 )
      {
        v17 = 1;
      }
      else
      {
        ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, retaddr);
        v18 = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
      }
      if ( (retaddr->Flags & 0x1F) - 12 <= 3 && !v36 )
      {
        Scaleform::GFx::AS3::VTable::GetMethod(
          v18,
          value,
          (Scaleform::GFx::AS3::AbsoluteIndex)v7,
          retaddr->value.VS._1.VObj,
          v17);
        goto LABEL_52;
      }
      v20 = Scaleform::GFx::AS3::VTable::GetValue(v18, &v32, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, v20);
      if ( (v32.Flags & 0x1F) <= 9 )
        goto LABEL_52;
      if ( (v32.Flags & 0x200) == 0 )
      {
        p_func = &v32;
        goto LABEL_51;
      }
      v16 = v32.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v32.Bonus, 0, 24);
      v32.Flags &= 0xFFFFFDE0;
      goto LABEL_52;
    case 12:
    case 14:
      v22 = v35;
      if ( !v35 )
      {
        v23 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, retaddr);
        v22 = Scaleform::GFx::AS3::Traits::GetVT(v23);
      }
      Scaleform::GFx::AS3::VTable::GetValue(v22, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      if ( (func.Flags & 0x1F) >= 0xC || (func.Flags & 0x1F) - 5 <= 2 )
      {
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &func, retaddr, value, 0, 0i64, 0);
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags & 0x200) != 0 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&func.Bonus, 0, 24);
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            p_func = &func;
LABEL_51:
            Scaleform::GFx::AS3::Value::ReleaseInternal(p_func);
          }
        }
LABEL_52:
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&super, 1006, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v24, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v25 = super.Message.pNode;
        v16 = super.Message.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        result->Result = 0;
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags & 0x200) != 0 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&func.Bonus, 0, 24);
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
      }
      return result;
    case 13:
      Scaleform::GFx::AS3::VM::Error::Error(&result_on_stack, 1077, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v26, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v27 = result_on_stack.Message.pNode;
      v16 = result_on_stack.Message.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      goto LABEL_55;
    default:
LABEL_55:
      result->Result = 0;
      return result;
  }
}

// File Line: 312
// RVA: 0x7EF9F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Object *obj)
{
  __int64 v7; // rbx
  Scaleform::GFx::AS3::Class **v8; // rdx
  Scaleform::GFx::AS3::Class *v9; // rdx
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::AS3::Value::V1U v12; // xmm0_8
  Scaleform::GFx::ASStringNode *v13; // rdx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::VTable *v18; // rax
  Scaleform::GFx::AS3::VM *pVM; // r15
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::VM *v22; // rbx
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+30h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::VM::Error v27; // [rsp+40h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+50h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+70h] [rbp+1Fh] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp+67h] BYREF

  v7 = (__int64)*(_DWORD *)this >> 15;
  switch ( (int)(*(_DWORD *)this << 17) >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (Scaleform::GFx::AS3::Value *)obj[3].vfptr + (unsigned int)v7);
      goto LABEL_44;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, (Scaleform::GFx::AS3::Value *)((char *)obj + (unsigned int)v7));
      goto LABEL_44;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe((Scaleform::GFx::AS3::STPtr *)((char *)obj + (unsigned int)v7), value);
      goto LABEL_44;
    case 4:
      v8 = (Scaleform::GFx::AS3::Class **)((char *)obj + (unsigned int)v7);
      if ( v8 )
      {
        v9 = *v8;
        if ( v9 && (v9->pTraits.pObject->Flags & 0x20) != 0 )
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
        else
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
      }
      goto LABEL_44;
    case 5:
      v10 = value->Flags & 0xFFFFFFE0 | 1;
      LOBYTE(v26.ID) = *((_BYTE *)&obj->vfptr + (unsigned int)v7);
      goto LABEL_11;
    case 6:
      v10 = value->Flags & 0xFFFFFFE0 | 2;
      v26.ID = *(_DWORD *)((char *)&obj->vfptr + (unsigned int)v7);
      goto LABEL_11;
    case 7:
      v10 = value->Flags & 0xFFFFFFE0 | 3;
      v26.ID = *(_DWORD *)((char *)&obj->vfptr + (unsigned int)v7);
LABEL_11:
      value->Flags = v10;
      value->value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)&v26.ID;
      pNode = v26.Message.pNode;
      goto LABEL_12;
    case 8:
      v12 = *(Scaleform::GFx::AS3::Value::V1U *)((char *)&obj->vfptr + (unsigned int)v7);
      value->Flags = value->Flags & 0xFFFFFFE0 | 4;
      value->value.VS._1 = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v27.Message.pNode;
      goto LABEL_44;
    case 9:
      v13 = *(Scaleform::GFx::ASStringNode **)((char *)&obj->vfptr + (unsigned int)v7);
      if ( v13 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v13);
      }
      else
      {
        value->Flags &= 0xFFFFFFEC;
        value->Flags |= 0xCu;
        value->value.VS._1.VStr = 0i64;
        pNode = v27.Message.pNode;
LABEL_12:
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
      }
      goto LABEL_44;
    case 10:
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              obj->pTraits.pObject->pVM->StringManagerRef,
              &resulta,
              *(const char **)((char *)&obj->vfptr + (unsigned int)(*(_DWORD *)this >> 15)));
      Scaleform::GFx::AS3::Value::AssignUnsafe(value, v14);
      v15 = resulta.pNode;
      v16 = resulta.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_44;
    case 11:
      VT = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetMethod(VT, value, (Scaleform::GFx::AS3::AbsoluteIndex)v7, obj, 0);
      goto LABEL_44;
    case 12:
    case 14:
      v18 = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetValue(v18, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      pVM = obj->pTraits.pObject->pVM;
      if ( (func.Flags & 0x1F) >= 0xC || (func.Flags & 0x1F) - 5 <= 2 )
      {
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0i64;
        _this.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)obj;
        obj->RefCount = (obj->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pVM, &func, &_this, value, 0, 0i64, 0);
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            v16 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&_this.Bonus, 0, 24);
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags & 0x200) != 0 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&func.Bonus, 0, 24);
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
LABEL_44:
        result->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v26, 1006, obj->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v21 = v26.Message.pNode;
        v16 = v26.Message.pNode->RefCount-- == 1;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        result->Result = 0;
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags & 0x200) != 0 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&func.Bonus, 0, 24);
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
      }
      return result;
    case 13:
      v22 = obj->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v27, 1077, v22);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v22, v23, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v24 = v27.Message.pNode;
      v16 = v27.Message.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      goto LABEL_47;
    default:
LABEL_47:
      result->Result = 0;
      return result;
  }
}

// File Line: 423
// RVA: 0x81D7C0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  __int64 v15; // r8
  __int64 v16; // rdi
  Scaleform::GFx::AS3::Value::V1U v17; // rsi
  __int64 v18; // r14
  __int64 v19; // rdi
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // eax
  __int64 v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value::V1U v28; // rsi
  Scaleform::GFx::ASStringNode **v29; // rdi
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::AS3::VM::Error *v31; // rax
  Scaleform::GFx::AS3::VTable *v32; // rax
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::VM::Error *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::VM::Error *v38; // rax
  Scaleform::GFx::AS3::VM::Error *v39; // rax
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [rsp+48h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value v43; // [rsp+68h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::VM::Error v44; // [rsp+88h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::VM::Error v45; // [rsp+98h] [rbp-9h] BYREF
  __int64 v46; // [rsp+A8h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v47; // [rsp+B0h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::VM::Error v48; // [rsp+C0h] [rbp+1Fh] BYREF
  Scaleform::GFx::AS3::Value *va; // [rsp+118h] [rbp+77h]
  Scaleform::GFx::AS3::VTable *v50; // [rsp+120h] [rbp+7Fh]

  v46 = -2i64;
  if ( (*(_BYTE *)this & 3) != 0 && vm->InInitializer <= 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v44, 1074, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v44.Message.pNode;
    v10 = v44.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
    return result;
  }
  other.Flags = 0;
  other.Bonus.pWeakProxy = 0i64;
  if ( (v->Flags & 0x1F) == 13 || (int)((*(_DWORD *)this & 0xFFFFFC00) << 17) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&other, v);
LABEL_22:
    v15 = *(_DWORD *)this;
    v16 = (unsigned int)(*(_DWORD *)this >> 15);
    switch ( (int)((_DWORD)v15 << 17) >> 27 )
    {
      case 1:
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)va->value.VS._1.VStr[4].pManager + (unsigned int)(v15 >> 15),
          &other);
        goto LABEL_100;
      case 2:
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)((char *)va->value.VS._1.VStr + (unsigned int)v16),
          &other);
        goto LABEL_100;
      case 3:
        v17 = va->value.VS._1;
        v18 = (unsigned int)v16;
        v19 = 0i64;
        v20 = other.Flags & 0x1F;
        if ( ((unsigned int)(v20 - 12) <= 3 || v20 == 11) && other.value.VS._1.VStr )
        {
          v21 = v20 - 11;
          if ( v21 )
          {
            v22 = v21 - 1;
            if ( v22 )
            {
              v23 = v22 - 1;
              if ( v23 )
              {
                if ( v23 == 1 )
                  v24 = 4;
                else
                  v24 = -1;
              }
              else
              {
                v24 = 2;
              }
            }
            else
            {
              v24 = 0;
            }
          }
          else
          {
            v24 = 6;
          }
          v19 = (__int64)other.value.VS._1.VStr | v24;
        }
        v25 = *(__int64 *)((char *)&v17.VStr->pData + v18);
        if ( v19 != v25 )
        {
          if ( v25 )
          {
            v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v25 & 0xFFFFFFFFFFFFFFF9ui64);
            if ( ((unsigned __int8)v26 & 1) != 0 )
            {
              *(const char **)((char *)&v17.VStr->pData + v18) = (char *)&v26[-1].RefCount
                                                               + (*(_DWORD *)((_BYTE *)&v17.VStr->pData + v18) & 6)
                                                               + 7;
            }
            else
            {
              RefCount = v26->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v26->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
              }
            }
          }
          *(const char **)((char *)&v17.VStr->pData + v18) = (const char *)v19;
          if ( v19 )
            *(_DWORD *)((v19 & 0xFFFFFFFFFFFFFFF8ui64) + 32) = (*(_DWORD *)((v19 & 0xFFFFFFFFFFFFFFF8ui64) + 32) + 1) & 0x8FBFFFFF;
        }
        goto LABEL_100;
      case 4:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)va->value.VS._1.VStr
                                                                                   + (unsigned int)v16),
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)other.value.VS._1.VStr);
        goto LABEL_100;
      case 5:
        *((_BYTE *)&va->value.VS._1.VStr->pData + v16) = other.value.VS._1.VBool;
        goto LABEL_100;
      case 6:
      case 7:
        *(_DWORD *)((char *)&va->value.VS._1.VStr->pData + v16) = other.value.VS._1.VInt;
        goto LABEL_100;
      case 8:
        *(const char **)((char *)&va->value.VS._1.VStr->pData + v16) = (const char *)other.value.VS._1.VStr;
        goto LABEL_100;
      case 9:
        v28 = other.value.VS._1;
        v29 = (Scaleform::GFx::ASStringNode **)((char *)va->value.VS._1.VStr + v16);
        v30 = *v29;
        if ( *v29 )
        {
          v10 = v30->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        }
        *v29 = v28.VStr;
        if ( v28.VStr )
          ++v28.VStr->RefCount;
        goto LABEL_100;
      case 10:
      case 12:
        Scaleform::GFx::AS3::VM::Error::Error(&v44, 1074, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v31, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        goto LABEL_10;
      case 11:
        if ( (va->Flags & 0x1F) <= 4 || (va->Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v48, 1056, vm);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v39, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
          v13 = v48.Message.pNode;
        }
        else
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v45, 1037, vm);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v38, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
          v13 = v45.Message.pNode;
        }
        goto LABEL_11;
      case 13:
      case 14:
        v32 = v50;
        if ( !v50 )
        {
          ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, va);
          v32 = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
        }
        Scaleform::GFx::AS3::VTable::GetValue(
          v32,
          &resulta,
          (Scaleform::GFx::AS3::AbsoluteIndex)(unsigned int)(v16 + 1));
        if ( (resulta.Flags & 0x1F) < 0xC && (resulta.Flags & 0x1F) - 5 > 2 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v47, 1006, vm);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v34, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          v35 = v47.Message.pNode;
          v10 = v47.Message.pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v35);
          result->Result = 0;
          goto LABEL_63;
        }
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        v43.Flags = Undefined->Flags;
        v43.Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
        v43.value = Undefined->value;
        if ( (Undefined->Flags & 0x1F) <= 9 )
          goto LABEL_81;
        if ( (Undefined->Flags & 0x200) != 0 )
        {
          ++Undefined->Bonus.pWeakProxy->RefCount;
        }
        else
        {
          if ( (Undefined->Flags & 0x1F) == 10 )
          {
            ++Undefined->value.VS._1.VStr->RefCount;
            goto LABEL_81;
          }
          if ( (Undefined->Flags & 0x1F) > 0xA )
          {
            if ( (Undefined->Flags & 0x1F) <= 0xF )
            {
              VObj = Undefined->value.VS._1;
            }
            else
            {
              if ( (Undefined->Flags & 0x1F) > 0x11 )
                goto LABEL_81;
              VObj = (Scaleform::GFx::AS3::Value::V1U)Undefined->value.VS._2.VObj;
            }
            if ( VObj.VStr )
              VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
          }
        }
LABEL_81:
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &resulta, va, &v43, 1u, &other, 0);
        if ( !vm->HandleException )
        {
          if ( (v43.Flags & 0x1F) > 9 )
          {
            if ( (v43.Flags & 0x200) != 0 )
            {
              v10 = v43.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v10 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v43.Bonus, 0, 24);
              v43.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v43);
            }
          }
          if ( (resulta.Flags & 0x1F) > 9 )
          {
            if ( (resulta.Flags & 0x200) != 0 )
            {
              v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v10 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&resulta.Bonus, 0, 24);
              resulta.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
            }
          }
LABEL_100:
          result->Result = 1;
          goto LABEL_14;
        }
        result->Result = 0;
        if ( (v43.Flags & 0x1F) > 9 )
        {
          if ( (v43.Flags & 0x200) != 0 )
          {
            v10 = v43.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v43.Bonus, 0, 24);
            v43.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v43);
          }
        }
LABEL_63:
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags & 0x200) != 0 )
          {
            v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&resulta.Bonus, 0, 24);
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
        goto LABEL_14;
      default:
        goto LABEL_13;
    }
  }
  DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
  if ( !DataType )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v44, 1014, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v12, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    goto LABEL_10;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))DataType->vfptr[3].Finalize_GC)(
         DataType,
         v,
         &other) )
  {
    goto LABEL_22;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v44, 1034, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_10:
  v13 = v44.Message.pNode;
LABEL_11:
  v10 = v13->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_13:
  result->Result = 0;
LABEL_14:
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  return result;
}

// File Line: 568
// RVA: 0x81DEA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rsi
  unsigned __int64 v17; // rbx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // eax
  __int64 v23; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // rcx
  unsigned int RefCount; // eax
  __int64 v26; // rsi
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  unsigned int v30; // ebx
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::VM::Error *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::VM::Error *v36; // rax
  _DWORD *result_on_stack; // [rsp+30h] [rbp-79h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *p; // [rsp+38h] [rbp-71h]
  Scaleform::GFx::AS3::Value other; // [rsp+40h] [rbp-69h] BYREF
  __int64 v41; // [rsp+60h] [rbp-49h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+68h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::VM::Error v43; // [rsp+88h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+98h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM::Error v45; // [rsp+B8h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::VM::Error v46; // [rsp+C8h] [rbp+1Fh] BYREF
  __int64 v47; // [rsp+D8h] [rbp+2Fh]
  Scaleform::GFx::AS3::Value::V1U v48; // [rsp+128h] [rbp+7Fh]

  v47 = -2i64;
  if ( (*(_BYTE *)this & 3) != 0 && vm->InInitializer <= 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v43, 1074, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v43.Message.pNode;
    v10 = v43.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
    return result;
  }
  other.Flags = 0;
  result_on_stack = 0i64;
  if ( (v->Flags & 0x1F) == 13 || (int)((*(_DWORD *)this & 0xFFFFFC00) << 17) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&other, v);
LABEL_22:
    v15 = (unsigned int)(*(_DWORD *)this >> 15);
    switch ( (int)(*(_DWORD *)this << 17) >> 27 )
    {
      case 1:
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)v48.VStr[4].pManager + (unsigned int)(*(_DWORD *)this >> 15),
          &other);
        goto LABEL_105;
      case 2:
        Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((char *)v48.VStr + (unsigned int)v15), &other);
        goto LABEL_105;
      case 3:
        v16 = (unsigned int)v15;
        v17 = 0i64;
        v18 = other.Flags & 0x1F;
        if ( ((unsigned int)(v18 - 12) <= 3 || v18 == 11) && p )
        {
          v19 = v18 - 11;
          if ( v19 )
          {
            v20 = v19 - 1;
            if ( v20 )
            {
              v21 = v20 - 1;
              if ( v21 )
              {
                if ( v21 == 1 )
                  v22 = 4;
                else
                  v22 = -1;
              }
              else
              {
                v22 = 2;
              }
            }
            else
            {
              v22 = 0;
            }
          }
          else
          {
            v22 = 6;
          }
          v17 = (unsigned __int64)p | v22;
        }
        v23 = *(__int64 *)((char *)&v48.VStr->pData + (unsigned int)v15);
        if ( v17 != v23 )
        {
          if ( v23 )
          {
            v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v23 & 0xFFFFFFFFFFFFFFF9ui64);
            if ( ((unsigned __int8)v24 & 1) != 0 )
            {
              *(const char **)((char *)&v48.VStr->pData + (unsigned int)v15) = (char *)&v24[-1].RefCount
                                                                             + (*(_DWORD *)((_BYTE *)&v48.VStr->pData
                                                                                          + (unsigned int)v15) & 6)
                                                                             + 7;
            }
            else
            {
              RefCount = v24->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v24->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
              }
            }
          }
          *(const char **)((char *)&v48.VStr->pData + v16) = (const char *)v17;
          if ( v17 )
            *(_DWORD *)((v17 & 0xFFFFFFFFFFFFFFF8ui64) + 32) = (*(_DWORD *)((v17 & 0xFFFFFFFFFFFFFFF8ui64) + 32) + 1) & 0x8FBFFFFF;
        }
        goto LABEL_105;
      case 4:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)v48.VStr + (unsigned int)v15),
          p);
        goto LABEL_105;
      case 5:
        *((_BYTE *)&v48.VStr->pData + v15) = (_BYTE)p;
        goto LABEL_105;
      case 6:
      case 7:
        *(_DWORD *)((char *)&v48.VStr->pData + v15) = (_DWORD)p;
        goto LABEL_105;
      case 8:
        *(const char **)((char *)&v48.VStr->pData + v15) = (const char *)p;
        goto LABEL_105;
      case 9:
        v26 = (unsigned int)v15;
        v27 = *(Scaleform::GFx::ASStringNode **)((char *)&v48.VStr->pData + v15);
        if ( v27 )
        {
          v10 = v27->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        }
        *(const char **)((char *)&v48.VStr->pData + v26) = (const char *)p;
        if ( p )
          ++LODWORD(p->pPrev);
        goto LABEL_105;
      case 10:
      case 12:
        Scaleform::GFx::AS3::VM::Error::Error(&v43, 1074, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v28, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v29 = v43.Message.pNode;
        v10 = v43.Message.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v29);
        goto LABEL_105;
      case 11:
        Scaleform::GFx::AS3::VM::Error::Error(&v45, 1037, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v36, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v13 = v45.Message.pNode;
        goto LABEL_11;
      case 13:
      case 14:
        v30 = v15 + 1;
        VT = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)v48.VStr[1].pData);
        Scaleform::GFx::AS3::VTable::GetValue(
          VT,
          (Scaleform::GFx::AS3::Value *)&other.Bonus,
          (Scaleform::GFx::AS3::AbsoluteIndex)v30);
        if ( (unsigned __int64)((__int64)other.Bonus.pWeakProxy & 0x1F) < 0xC
          && (unsigned __int64)(((__int64)other.Bonus.pWeakProxy & 0x1F) - 5) > 2 )
        {
          Scaleform::GFx::AS3::VM::Error::Error(&v46, 1006, vm);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v32, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          v33 = v46.Message.pNode;
          v10 = v46.Message.pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          result->Result = 0;
          goto LABEL_62;
        }
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        resulta.Flags = Undefined->Flags;
        resulta.Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
        resulta.value = Undefined->value;
        if ( (Undefined->Flags & 0x1F) <= 9 )
          goto LABEL_80;
        if ( (Undefined->Flags & 0x200) != 0 )
        {
          ++Undefined->Bonus.pWeakProxy->RefCount;
        }
        else
        {
          if ( (Undefined->Flags & 0x1F) == 10 )
          {
            ++Undefined->value.VS._1.VStr->RefCount;
            goto LABEL_80;
          }
          if ( (Undefined->Flags & 0x1F) > 0xA )
          {
            if ( (Undefined->Flags & 0x1F) <= 0xF )
            {
              VObj = Undefined->value.VS._1;
            }
            else
            {
              if ( (Undefined->Flags & 0x1F) > 0x11 )
                goto LABEL_80;
              VObj = (Scaleform::GFx::AS3::Value::V1U)Undefined->value.VS._2.VObj;
            }
            if ( VObj.VStr )
              VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
          }
        }
LABEL_80:
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0i64;
        _this.value.VS._1 = v48;
        v48.VStr->Size = (v48.VStr->Size + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          vm,
          (Scaleform::GFx::AS3::Value *)&other.Bonus,
          &_this,
          &resulta,
          1u,
          &other,
          0);
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags & 0x200) != 0 )
          {
            v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&_this.Bonus, 0, 24);
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
        if ( !vm->HandleException )
        {
          if ( (resulta.Flags & 0x1F) > 9 )
          {
            if ( (resulta.Flags & 0x200) != 0 )
            {
              v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v10 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&resulta.Bonus, 0, 24);
              resulta.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
            }
          }
          if ( (unsigned __int64)((__int64)other.Bonus.pWeakProxy & 0x1F) > 9 )
          {
            if ( ((__int64)other.Bonus.pWeakProxy & 0x200) != 0 )
            {
              v10 = LODWORD(other.value.VS._1.VStr->pData)-- == 1;
              if ( v10 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              other.value = 0ui64;
              v41 = 0i64;
              LODWORD(other.Bonus.pWeakProxy) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other.Bonus);
            }
          }
LABEL_105:
          result->Result = 1;
          goto LABEL_14;
        }
        result->Result = 0;
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags & 0x200) != 0 )
          {
            v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&resulta.Bonus, 0, 24);
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
LABEL_62:
        if ( (unsigned __int64)((__int64)other.Bonus.pWeakProxy & 0x1F) > 9 )
        {
          if ( ((__int64)other.Bonus.pWeakProxy & 0x200) != 0 )
          {
            v10 = LODWORD(other.value.VS._1.VStr->pData)-- == 1;
            if ( v10 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            other.value = 0ui64;
            v41 = 0i64;
            LODWORD(other.Bonus.pWeakProxy) &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&other.Bonus);
          }
        }
        goto LABEL_14;
      default:
        goto LABEL_13;
    }
  }
  DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
  if ( !DataType )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v43, 1014, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v12, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    goto LABEL_10;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))DataType->vfptr[3].Finalize_GC)(
         DataType,
         v,
         &other) )
  {
    goto LABEL_22;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v43, 1034, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_10:
  v13 = v43.Message.pNode;
LABEL_11:
  v10 = v13->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_13:
  result->Result = 0;
LABEL_14:
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v10 = (*result_on_stack)-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      *(&other.Flags + 1) = 0;
      other.Flags = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  return result;
}

// File Line: 760
// RVA: 0x7D62C0
void __fastcall Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::Object *obj,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  __int64 v4; // r10
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  unsigned __int64 *v8; // rdi
  unsigned __int64 v9; // rax
  int v10; // ebx
  unsigned __int64 v11; // [rsp+30h] [rbp+8h] BYREF

  v4 = *(_DWORD *)this;
  v5 = ((int)(*(_DWORD *)this << 17) >> 27) - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          if ( *(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl **)((char *)&obj->vfptr + (v4 >> 15)) )
            op(prcc);
        }
      }
      else
      {
        v8 = (unsigned __int64 *)((char *)obj + (v4 >> 15));
        v9 = *v8;
        if ( *v8 )
        {
          v11 = v9 & 0xFFFFFFFFFFFFFFF9ui64;
          v10 = v9 & 6;
          ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, unsigned __int64 *))op)(prcc, &v11);
          *v8 = v11 | v10;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::ForEachChild_GC(
        prcc,
        (Scaleform::GFx::AS3::Value *)((char *)obj + (v4 >> 15)),
        (void (*)(void))op);
    }
  }
  else
  {
    Scaleform::GFx::AS3::ForEachChild_GC(
      prcc,
      (Scaleform::GFx::AS3::Value *)obj[3].vfptr + (unsigned int)((int)v4 >> 15),
      (void (*)(void))op);
  }
}

// File Line: 810
// RVA: 0x7E75E0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::SlotInfo::GetDataType(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rbp
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *TypeName; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rax
  Scaleform::GFx::AS3::Multiname v10; // [rsp+28h] [rbp-40h] BYREF

  if ( !this->CTraits.pObject )
  {
    pObject = this->File.pObject;
    if ( pObject && (TI = this->TI) != 0i64 )
    {
      if ( (TI->kind & 0xF) != 0 && (TI->kind & 0xFu) - 4 > 2 )
      {
        v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsFunction.pObject;
LABEL_17:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->CTraits,
          v6);
      }
      else
      {
        TypeName = Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(TI, pObject->File.pObject);
        Scaleform::GFx::AS3::Multiname::Multiname(&v10, pObject, TypeName);
        v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                              vm,
                                                              this->File.pObject,
                                                              TypeName);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->CTraits,
          v8);
        Scaleform::GFx::AS3::Multiname::~Multiname(&v10);
      }
    }
    else
    {
      switch ( (int)(*(_DWORD *)this << 17) >> 27 )
      {
        case 0:
        case 1:
        case 2:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsClassClass.pObject;
          goto LABEL_17;
        case 3:
        case 4:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsObject.pObject;
          goto LABEL_17;
        case 5:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsBoolean.pObject;
          goto LABEL_17;
        case 6:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsInt.pObject;
          goto LABEL_17;
        case 7:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsUint.pObject;
          goto LABEL_17;
        case 8:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsNumber.pObject;
          goto LABEL_17;
        case 9:
        case 10:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsString.pObject;
          goto LABEL_17;
        case 11:
        case 12:
        case 13:
        case 14:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsFunction.pObject;
          goto LABEL_17;
        default:
          return this->CTraits.pObject;
      }
    }
  }
  return this->CTraits.pObject;
}

// File Line: 889
// RVA: 0x7F8420
_BOOL8 __fastcall Scaleform::GFx::AS3::SlotInfo::IsClassType(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::VMAbcFile *pObject; // r8
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  Scaleform::GFx::AS3::Abc::File *v3; // r8
  __int64 Ind; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rdx
  __int64 p_any_namespace; // rbx
  char *Data; // r9
  char v8; // al
  char *v9; // r9
  unsigned int v10; // ecx
  int v11; // r8d
  char v12; // dl
  int v13; // eax

  pObject = this->File.pObject;
  if ( !pObject )
    return 0i64;
  TI = this->TI;
  if ( !TI )
    return 0i64;
  v3 = pObject->File.pObject;
  if ( (TI->kind & 0xF) == 0 || (TI->kind & 0xF) == 6 )
    Ind = TI->Ind;
  else
    Ind = v3->AS3_Classes.Info.Data.Data[TI->Ind]->inst_info.name_ind;
  v5 = &v3->Const_Pool.const_multiname.Data.Data[Ind];
  if ( v5->Ind )
    p_any_namespace = (__int64)&v3->Const_Pool.ConstNamespace.Data.Data[v5->Ind];
  else
    p_any_namespace = (__int64)&v3->Const_Pool.any_namespace;
  Data = (char *)v3->Const_Pool.ConstStr.Data.Data[v5->NameIndex].Data;
  if ( !Data )
    return 0i64;
  v8 = *Data;
  v9 = Data + 1;
  v10 = 7;
  v11 = v8 & 0x7F;
  if ( v8 < 0 )
  {
    do
    {
      if ( v10 >= 0x20 )
        break;
      v12 = *v9++;
      v13 = (v12 & 0x7F) << v10;
      v10 += 7;
      v11 |= v13;
    }
    while ( v12 < 0 );
  }
  return v11 == 5i64
      && ("Class" == v9 || v9 && !strncmp(v9, "Class", v11))
      && (*(_DWORD *)p_any_namespace & 0xFFFFFFFB) == 0
      && *(_QWORD *)(p_any_namespace + 16) == 0i64;
}

// File Line: 987
// RVA: 0x7EC730
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::SlotInfo::GetName(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pObject; // rbx
  unsigned __int64 Size; // rcx
  __int64 LastChar; // rax
  unsigned __int64 v6; // rcx
  Scaleform::StringDataPtr v8; // [rsp+30h] [rbp-18h] BYREF

  pObject = this->Name.pObject;
  Size = pObject->Size;
  v8.pStr = pObject->pData;
  v8.Size = Size;
  LastChar = Scaleform::StringDataPtr::FindLastChar(&v8, 47, 0xFFFFFFFFFFFFFFFFui64);
  if ( LastChar < 0 )
    LastChar = Scaleform::StringDataPtr::FindLastChar(&v8, 46, 0xFFFFFFFFFFFFFFFFui64);
  v6 = LastChar + 1;
  if ( v8.Size < LastChar + 1 )
    v6 = v8.Size;
  Scaleform::GFx::ASStringManager::CreateString(pObject->pManager, result, &v8.pStr[v6], v8.Size - v6);
  return result;
}

