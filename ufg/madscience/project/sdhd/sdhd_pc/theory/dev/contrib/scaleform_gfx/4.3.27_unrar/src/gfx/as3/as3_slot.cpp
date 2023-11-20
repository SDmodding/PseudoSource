// File Line: 120
// RVA: 0x781EF0
void __fastcall Scaleform::GFx::AS3::SlotInfo::SlotInfo(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::SlotInfo *other)
{
  Scaleform::GFx::AS3::SlotInfo *v2; // r9
  int v3; // er8
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits *v9; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rax

  v2 = this;
  *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 3;
  v3 = *(_DWORD *)this ^ (*(_DWORD *)other ^ *(_DWORD *)this) & 0xC;
  *(_DWORD *)this = v3;
  v4 = v3 ^ (*(_DWORD *)other ^ v3) & 0x30;
  *(_DWORD *)this = v4;
  v5 = v4 ^ (*(_DWORD *)other ^ v4) & 0xC0;
  *(_DWORD *)v2 = v5;
  v6 = v5 ^ (*(_DWORD *)other ^ v5) & 0x300;
  *(_DWORD *)v2 = v6;
  v7 = v6 ^ (*(_DWORD *)other ^ v6) & 0x7C00;
  *(_DWORD *)v2 = v7;
  *(_DWORD *)v2 = *(_DWORD *)other ^ (*(_DWORD *)other ^ v7) & 0x7FFF;
  v2->Padding01 = 0;
  v8 = other->pNs.pObject;
  v2->pNs.pObject = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v9 = other->CTraits.pObject;
  v2->CTraits.pObject = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v10 = other->File.pObject;
  v2->File.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  v2->TI = other->TI;
  v11 = other->Name.pObject;
  if ( v11 )
    ++v11->RefCount;
  v2->Name.pObject = other->Name.pObject;
}

// File Line: 124
// RVA: 0x78DEC0
void __fastcall Scaleform::GFx::AS3::SlotInfo::~SlotInfo(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::SlotInfo *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::AS3::VMAbcFile *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rcx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rcx
  unsigned int v9; // eax

  v1 = this;
  v2 = this->Name.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  }
  v4 = v1->File.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)((char *)v4 - 1);
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
  v6 = v1->CTraits.pObject;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v1->CTraits.pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)((char *)v6 - 1);
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
  v8 = v1->pNs.pObject;
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      v1->pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
}

// File Line: 137
// RVA: 0x7909C0
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::SlotInfo::operator=(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::SlotInfo *other)
{
  Scaleform::GFx::AS3::SlotInfo *v2; // rdi
  Scaleform::GFx::AS3::SlotInfo *v3; // rbx
  int v4; // er8
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf

  v2 = other;
  v3 = this;
  if ( this != other )
  {
    *(_DWORD *)this ^= (*(_DWORD *)this ^ *(_DWORD *)other) & 3;
    v4 = *(_DWORD *)this ^ (*(_DWORD *)this ^ *(_DWORD *)other) & 0xC;
    *(_DWORD *)this = v4;
    v5 = v4 ^ (*(_DWORD *)other ^ v4) & 0x30;
    *(_DWORD *)this = v5;
    v6 = v5 ^ (*(_DWORD *)other ^ v5) & 0xC0;
    *(_DWORD *)v3 = v6;
    v7 = v6 ^ (*(_DWORD *)other ^ v6) & 0x300;
    *(_DWORD *)v3 = v7;
    *(_DWORD *)v3 = v7 ^ (*(_DWORD *)v2 ^ v7) & 0x7C00;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->pNs,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v2->pNs);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->CTraits,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v2->CTraits);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->File,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v2->File);
    v3->TI = v2->TI;
    *(_DWORD *)v3 = *(_DWORD *)v2 ^ (*(_DWORD *)v3 ^ *(_DWORD *)v2) & 0x7FFF;
    v8 = v2->Name.pObject;
    if ( v8 )
      ++v8->RefCount;
    v9 = v3->Name.pObject;
    if ( v9 )
    {
      v10 = v9->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    v3->Name.pObject = v2->Name.pObject;
  }
  return v3;
}

// File Line: 160
// RVA: 0x7F8550
bool __fastcall Scaleform::GFx::AS3::SlotInfo::IsConst(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *v1; // rax
  bool result; // al

  result = 1;
  if ( !(*(_BYTE *)this & 3) )
  {
    v1 = this->TI;
    if ( !v1 || (v1->kind & 0xF) != 6 )
      result = 0;
  }
  return result;
}

// File Line: 167
// RVA: 0x7F83F0
bool __fastcall Scaleform::GFx::AS3::SlotInfo::IsClass(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::Abc::TraitInfo *v1; // rax
  bool result; // al

  result = 1;
  if ( (*(_DWORD *)this & 0x7C00) != 1024 )
  {
    v1 = this->TI;
    if ( !v1 || (v1->kind & 0xF) != 4 )
      result = 0;
  }
  return result;
}

// File Line: 191
// RVA: 0x7EF530
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // r14
  Scaleform::GFx::AS3::CheckResult *v6; // rsi
  signed __int64 v7; // rbx
  Scaleform::GFx::AS3::Class **v8; // rdx
  Scaleform::GFx::AS3::Class *v9; // rdx
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // rax
  long double v12; // xmm0_8
  Scaleform::GFx::ASStringNode *v13; // rdx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  bool v17; // r12
  Scaleform::GFx::AS3::VTable *v18; // rcx
  Scaleform::GFx::AS3::Traits *v19; // rax
  Scaleform::GFx::AS3::Value *v20; // rax
  Scaleform::GFx::AS3::Value *v21; // rcx
  Scaleform::GFx::AS3::VTable *v22; // rax
  Scaleform::GFx::AS3::Traits *v23; // rax
  int v24; // eax
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::VM::Error *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  bool super[8]; // [rsp+20h] [rbp-49h]
  Scaleform::GFx::ASStringNode *v31; // [rsp+28h] [rbp-41h]
  bool result_on_stack; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ASStringNode *v33; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::AS3::Value func; // [rsp+40h] [rbp-29h]
  Scaleform::GFx::AS3::Value v35; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp+4Fh]
  void *retaddr; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::AS3::VTable *v38; // [rsp+E0h] [rbp+77h]
  int v39; // [rsp+E8h] [rbp+7Fh]

  v4 = value;
  v5 = vm;
  v6 = result;
  v7 = (signed __int64)*(_DWORD *)this >> 15;
  switch ( *(_DWORD *)this << 17 >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)(*(_QWORD *)(*((_QWORD *)retaddr + 2) + 168i64) + 32i64 * (unsigned int)v7));
      goto LABEL_52;
    case 2:
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)(*((_QWORD *)retaddr + 2) + (unsigned int)v7));
      goto LABEL_52;
    case 3:
      Scaleform::GFx::AS3::STPtr::GetValueUnsafe(
        (Scaleform::GFx::AS3::STPtr *)(*((_QWORD *)retaddr + 2) + (unsigned int)v7),
        value);
      goto LABEL_52;
    case 4:
      v8 = (Scaleform::GFx::AS3::Class **)(*((_QWORD *)retaddr + 2) + (unsigned int)v7);
      if ( v8 )
      {
        v9 = *v8;
        if ( v9 && (LOBYTE(v9->pTraits.pObject->Flags) >> 5) & 1 )
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
        else
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, (Scaleform::GFx::AS3::Object *)&v9->vfptr);
      }
      goto LABEL_52;
    case 5:
      v10 = value->Flags & 0xFFFFFFE1 | 1;
      super[0] = *(_BYTE *)((unsigned int)v7 + *((_QWORD *)retaddr + 2));
      goto LABEL_11;
    case 6:
      v10 = value->Flags & 0xFFFFFFE2 | 2;
      *(_DWORD *)super = *(_DWORD *)((unsigned int)v7 + *((_QWORD *)retaddr + 2));
      goto LABEL_11;
    case 7:
      v10 = value->Flags & 0xFFFFFFE3 | 3;
      *(_DWORD *)super = *(_DWORD *)((unsigned int)v7 + *((_QWORD *)retaddr + 2));
LABEL_11:
      value->Flags = v10;
      value->value.VNumber = *(long double *)super;
      v11 = v31;
      goto LABEL_12;
    case 8:
      v12 = *(double *)((unsigned int)v7 + *((_QWORD *)retaddr + 2));
      value->Flags = value->Flags & 0xFFFFFFE4 | 4;
      value->value.VNumber = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v33;
      goto LABEL_52;
    case 9:
      v13 = *(Scaleform::GFx::ASStringNode **)((unsigned int)v7 + *((_QWORD *)retaddr + 2));
      if ( v13 )
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(value, v13);
      }
      else
      {
        value->Flags &= 0xFFFFFFEC;
        value->Flags |= 0xCu;
        value->value.VNumber = 0.0;
        v11 = v33;
LABEL_12:
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11;
      }
      goto LABEL_52;
    case 0xA:
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
              &resulta,
              *(const char **)(*((_QWORD *)retaddr + 2) + (unsigned int)v7));
      Scaleform::GFx::AS3::Value::AssignUnsafe(v4, v14);
      v15 = resulta.pNode;
      v16 = resulta.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_52;
    case 0xB:
      v17 = 0;
      v18 = v38;
      if ( v38 )
      {
        v17 = 1;
      }
      else
      {
        v19 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, (Scaleform::GFx::AS3::Value *)retaddr);
        v18 = Scaleform::GFx::AS3::Traits::GetVT(v19);
      }
      if ( (*(_DWORD *)retaddr & 0x1Fu) - 12 <= 3 && !v39 )
      {
        Scaleform::GFx::AS3::VTable::GetMethod(
          v18,
          v4,
          (Scaleform::GFx::AS3::AbsoluteIndex)v7,
          *((Scaleform::GFx::AS3::Object **)retaddr + 2),
          v17);
        goto LABEL_52;
      }
      v20 = Scaleform::GFx::AS3::VTable::GetValue(v18, &v35, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      Scaleform::GFx::AS3::Value::AssignUnsafe(v4, v20);
      if ( (v35.Flags & 0x1F) <= 9 )
        goto LABEL_52;
      if ( !((v35.Flags >> 9) & 1) )
      {
        v21 = &v35;
        goto LABEL_51;
      }
      v16 = v35.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35.Bonus.pWeakProxy = 0i64;
      v35.value = 0ui64;
      v35.Flags &= 0xFFFFFDE0;
      goto LABEL_52;
    case 0xC:
    case 0xE:
      v22 = v38;
      if ( !v38 )
      {
        v23 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, (Scaleform::GFx::AS3::Value *)retaddr);
        v22 = Scaleform::GFx::AS3::Traits::GetVT(v23);
      }
      Scaleform::GFx::AS3::VTable::GetValue(v22, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      v24 = func.Flags & 0x1F;
      if ( v24 >= 12 || (unsigned int)(v24 - 5) <= 2 )
      {
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, &func, (Scaleform::GFx::AS3::Value *)retaddr, v4, 0, 0i64, 0);
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags >> 9) & 1 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            func.Bonus.pWeakProxy = 0i64;
            func.value = 0ui64;
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            v21 = &func;
LABEL_51:
            Scaleform::GFx::AS3::Value::ReleaseInternal(v21);
          }
        }
LABEL_52:
        v6->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)super, eCallOfNonFunctionError, v5);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v25, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v26 = v31;
        v16 = v31->RefCount == 1;
        --v26->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        v6->Result = 0;
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags >> 9) & 1 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            func.Bonus.pWeakProxy = 0i64;
            func.value = 0ui64;
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
      }
      return v6;
    case 0xD:
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result_on_stack, eWriteOnlyError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v27, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v28 = v33;
      v16 = v33->RefCount == 1;
      --v28->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      goto LABEL_55;
    default:
LABEL_55:
      v6->Result = 0;
      return v6;
  }
}

// File Line: 312
// RVA: 0x7EF9F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // r14
  signed __int64 v7; // rbx
  Scaleform::GFx::AS3::Class **v8; // rdx
  Scaleform::GFx::AS3::Class *v9; // rdx
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // rax
  long double v12; // xmm0_8
  Scaleform::GFx::ASStringNode *v13; // rdx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::AS3::VTable *v17; // rax
  Scaleform::GFx::AS3::VTable *v18; // rax
  Scaleform::GFx::AS3::VM *v19; // r15
  int v20; // eax
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::VM *v23; // rbx
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::VM::Error v27; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS3::Value func; // [rsp+50h] [rbp-1h]
  Scaleform::GFx::AS3::Value _this; // [rsp+70h] [rbp+1Fh]
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp+67h]

  v4 = obj;
  v5 = value;
  v6 = result;
  v7 = (signed __int64)*(_DWORD *)this >> 15;
  switch ( *(_DWORD *)this << 17 >> 27 )
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
        if ( v9 && (LOBYTE(v9->pTraits.pObject->Flags) >> 5) & 1 )
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, v9);
        else
          Scaleform::GFx::AS3::Value::AssignUnsafe(value, (Scaleform::GFx::AS3::Object *)&v9->vfptr);
      }
      goto LABEL_44;
    case 5:
      v10 = value->Flags & 0xFFFFFFE1 | 1;
      LOBYTE(v27.ID) = *((_BYTE *)&obj->vfptr + (unsigned int)v7);
      goto LABEL_11;
    case 6:
      v10 = value->Flags & 0xFFFFFFE2 | 2;
      v27.ID = *(_DWORD *)((char *)&obj->vfptr + (unsigned int)v7);
      goto LABEL_11;
    case 7:
      v10 = value->Flags & 0xFFFFFFE3 | 3;
      v27.ID = *(_DWORD *)((char *)&obj->vfptr + (unsigned int)v7);
LABEL_11:
      value->Flags = v10;
      value->value.VNumber = *(long double *)&v27.ID;
      v11 = v27.Message.pNode;
      goto LABEL_12;
    case 8:
      v12 = *(double *)((char *)&obj->vfptr + (unsigned int)v7);
      value->Flags = value->Flags & 0xFFFFFFE4 | 4;
      value->value.VNumber = v12;
      value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v28.Message.pNode;
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
        value->value.VNumber = 0.0;
        v11 = v28.Message.pNode;
LABEL_12:
        value->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11;
      }
      goto LABEL_44;
    case 0xA:
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)obj->pTraits.pObject->pVM->StringManagerRef->Builtins,
              &resulta,
              *(const char **)((char *)&obj->vfptr + (unsigned int)(*(_DWORD *)this >> 15)));
      Scaleform::GFx::AS3::Value::AssignUnsafe(v5, v14);
      v15 = resulta.pNode;
      v16 = resulta.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_44;
    case 0xB:
      v17 = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetMethod(v17, v5, (Scaleform::GFx::AS3::AbsoluteIndex)v7, v4, 0);
      goto LABEL_44;
    case 0xC:
    case 0xE:
      v18 = Scaleform::GFx::AS3::Traits::GetVT(obj->pTraits.pObject);
      Scaleform::GFx::AS3::VTable::GetValue(v18, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      v19 = v4->pTraits.pObject->pVM;
      v20 = func.Flags & 0x1F;
      if ( v20 >= 12 || (unsigned int)(v20 - 5) <= 2 )
      {
        _this.Flags = 12;
        _this.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&_this.value.VNumber = v4;
        v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v19, &func, &_this, v5, 0, 0i64, 0);
        if ( (_this.Flags & 0x1F) > 9 )
        {
          if ( (_this.Flags >> 9) & 1 )
          {
            v16 = _this.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            _this.Bonus.pWeakProxy = 0i64;
            _this.value = 0ui64;
            _this.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
          }
        }
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags >> 9) & 1 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            func.Bonus.pWeakProxy = 0i64;
            func.value = 0ui64;
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
LABEL_44:
        v6->Result = 1;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v27, eCallOfNonFunctionError, v4->pTraits.pObject->pVM);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v19, v21, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v22 = v27.Message.pNode;
        v16 = v27.Message.pNode->RefCount == 1;
        --v22->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        v6->Result = 0;
        if ( (func.Flags & 0x1F) > 9 )
        {
          if ( (func.Flags >> 9) & 1 )
          {
            v16 = func.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            func.Bonus.pWeakProxy = 0i64;
            func.value = 0ui64;
            func.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
          }
        }
      }
      return v6;
    case 0xD:
      v23 = obj->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eWriteOnlyError, v23);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v23, v24, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v25 = v28.Message.pNode;
      v16 = v28.Message.pNode->RefCount == 1;
      --v25->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      break;
    default:
      break;
  }
  v6->Result = 0;
  return v6;
}

// File Line: 423
// RVA: 0x81D7C0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::SlotInfo *v7; // rdi
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  __int64 v15; // r8
  __int64 v16; // rdi
  long double v17; // rsi
  __int64 v18; // r14
  __int64 v19; // rdi
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  signed int v24; // eax
  __int64 v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rcx
  unsigned int v27; // eax
  long double v28; // rsi
  Scaleform::GFx::ASStringNode **v29; // rdi
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::AS3::VM::Error *v31; // rax
  Scaleform::GFx::AS3::VTable *v32; // rax
  Scaleform::GFx::AS3::Traits *v33; // rax
  int v34; // eax
  Scaleform::GFx::AS3::VM::Error *v35; // rax
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::Value *v37; // rax
  int v38; // ecx
  long double v39; // rcx
  int v40; // ecx
  Scaleform::GFx::AS3::VM::Error *v41; // rax
  Scaleform::GFx::AS3::VM::Error *v42; // rax
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-79h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+48h] [rbp-59h]
  Scaleform::GFx::AS3::Value v46; // [rsp+68h] [rbp-39h]
  Scaleform::GFx::AS3::VM::Error v47; // [rsp+88h] [rbp-19h]
  Scaleform::GFx::AS3::VM::Error v48; // [rsp+98h] [rbp-9h]
  __int64 v49; // [rsp+A8h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v50; // [rsp+B0h] [rbp+Fh]
  Scaleform::GFx::AS3::VM::Error v51; // [rsp+C0h] [rbp+1Fh]
  Scaleform::GFx::AS3::Value *va; // [rsp+118h] [rbp+77h]
  Scaleform::GFx::AS3::VTable *v53; // [rsp+120h] [rbp+7Fh]

  v49 = -2i64;
  v4 = v;
  v5 = vm;
  v6 = result;
  v7 = this;
  if ( *(_BYTE *)this & 3 && vm->InInitializer <= 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v47, eConstWriteError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v9 = v47.Message.pNode;
    v10 = v47.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v6->Result = 0;
    return v6;
  }
  other.Flags = 0;
  other.Bonus.pWeakProxy = 0i64;
  if ( (v->Flags & 0x1F) == 13 || (signed int)((*(_DWORD *)this & 0xFFFFFC00) << 17) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&other, v);
  }
  else
  {
    v11 = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
    if ( !v11 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eClassNotFoundError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v12, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
LABEL_10:
      v13 = v47.Message.pNode;
LABEL_11:
      v10 = v13->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_13:
      v6->Result = 0;
      goto LABEL_14;
    }
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v11->vfptr[3].Finalize_GC)(
            v11,
            v4,
            &other) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eCheckTypeFailedError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      goto LABEL_10;
    }
  }
  v15 = *(_DWORD *)v7;
  v16 = (unsigned int)(*(_DWORD *)v7 >> 15);
  switch ( (_DWORD)v15 << 17 >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)(*(_QWORD *)(*(_QWORD *)&va->value.VNumber + 168i64)
                                     + 32i64 * (unsigned int)(v15 >> 15)),
        &other);
      goto LABEL_100;
    case 2:
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)((unsigned int)v16 + *(_QWORD *)&va->value.VNumber),
        &other);
      goto LABEL_100;
    case 3:
      v17 = va->value.VNumber;
      v18 = (unsigned int)v16;
      v19 = 0i64;
      v20 = other.Flags & 0x1F;
      if ( ((unsigned int)(v20 - 12) <= 3 || v20 == 11) && *(_QWORD *)&other.value.VNumber )
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
        v19 = *(_QWORD *)&other.value.VNumber | v24;
      }
      v25 = *(_QWORD *)(v18 + *(_QWORD *)&v17);
      if ( v19 != v25 )
      {
        if ( v25 )
        {
          v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v25 & 0xFFFFFFFFFFFFFFF9ui64);
          if ( (unsigned __int8)v26 & 1 )
          {
            *(_QWORD *)(v18 + *(_QWORD *)&v17) = (char *)v26 + (*(_DWORD *)(v18 + *(_QWORD *)&v17) & 6) - 1;
          }
          else
          {
            v27 = v26->RefCount;
            if ( v27 & 0x3FFFFF )
            {
              v26->RefCount = v27 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
            }
          }
        }
        *(_QWORD *)(v18 + *(_QWORD *)&v17) = v19;
        if ( v19 )
          *(_DWORD *)((v19 & 0xFFFFFFFFFFFFFFF8ui64) + 32) = (*(_DWORD *)((v19 & 0xFFFFFFFFFFFFFFF8ui64) + 32) + 1) & 0x8FBFFFFF;
      }
      goto LABEL_100;
    case 4:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(_QWORD *)&va->value.VNumber
                                                                                 + (unsigned int)v16),
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)other.value.VS._1.VStr);
      goto LABEL_100;
    case 5:
      *(_BYTE *)(v16 + *(_QWORD *)&va->value.VNumber) = other.value.VS._1.VBool;
      goto LABEL_100;
    case 6:
    case 7:
      *(_DWORD *)(v16 + *(_QWORD *)&va->value.VNumber) = other.value.VS._1.VInt;
      goto LABEL_100;
    case 8:
      *(long double *)(v16 + *(_QWORD *)&va->value.VNumber) = other.value.VNumber;
      goto LABEL_100;
    case 9:
      v28 = other.value.VNumber;
      v29 = (Scaleform::GFx::ASStringNode **)(*(_QWORD *)&va->value.VNumber + v16);
      v30 = *v29;
      if ( *v29 )
      {
        v10 = v30->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
      }
      *(long double *)v29 = v28;
      if ( v28 != 0.0 )
        ++*(_DWORD *)(*(_QWORD *)&v28 + 24i64);
      goto LABEL_100;
    case 0xA:
    case 0xC:
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eConstWriteError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v31, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      goto LABEL_10;
    case 0xB:
      v40 = va->Flags & 0x1F;
      if ( v40 <= 4 || v40 == 10 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v51, eWriteSealedError, v5);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v42, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v13 = v51.Message.pNode;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v48, eCannotAssignToMethodError, v5);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v41, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
        v13 = v48.Message.pNode;
      }
      goto LABEL_11;
    case 0xD:
    case 0xE:
      v32 = v53;
      if ( !v53 )
      {
        v33 = Scaleform::GFx::AS3::VM::GetValueTraits(v5, va);
        v32 = Scaleform::GFx::AS3::Traits::GetVT(v33);
      }
      Scaleform::GFx::AS3::VTable::GetValue(v32, &resulta, (Scaleform::GFx::AS3::AbsoluteIndex)(unsigned int)(v16 + 1));
      v34 = resulta.Flags & 0x1F;
      if ( v34 < 12 && (unsigned int)(v34 - 5) > 2 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v50, eCallOfNonFunctionError, v5);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v35, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v36 = v50.Message.pNode;
        v10 = v50.Message.pNode->RefCount == 1;
        --v36->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        v6->Result = 0;
LABEL_63:
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags >> 9) & 1 )
          {
            v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            resulta.Bonus.pWeakProxy = 0i64;
            resulta.value = 0ui64;
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
        goto LABEL_14;
      }
      v37 = Scaleform::GFx::AS3::Value::GetUndefined();
      v46.Flags = v37->Flags;
      v46.Bonus.pWeakProxy = v37->Bonus.pWeakProxy;
      v46.value = v37->value;
      v38 = v37->Flags & 0x1F;
      if ( v38 <= 9 )
        goto LABEL_81;
      if ( (v37->Flags >> 9) & 1 )
      {
        ++v37->Bonus.pWeakProxy->RefCount;
        goto LABEL_81;
      }
      if ( v38 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v37->value.VNumber + 24i64);
      }
      else
      {
        if ( v38 <= 10 )
          goto LABEL_81;
        if ( v38 <= 15 )
        {
          v39 = v37->value.VNumber;
        }
        else
        {
          if ( v38 > 17 )
            goto LABEL_81;
          v39 = *(double *)&v37->value.VS._2.VObj;
        }
        if ( v39 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v39 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v39 + 32i64) + 1) & 0x8FBFFFFF;
      }
LABEL_81:
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, &resulta, va, &v46, 1u, &other, 0);
      if ( v5->HandleException )
      {
        v6->Result = 0;
        if ( (v46.Flags & 0x1F) > 9 )
        {
          if ( (v46.Flags >> 9) & 1 )
          {
            v10 = v46.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v46.Bonus.pWeakProxy = 0i64;
            v46.value = 0ui64;
            v46.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
          }
        }
        goto LABEL_63;
      }
      if ( (v46.Flags & 0x1F) > 9 )
      {
        if ( (v46.Flags >> 9) & 1 )
        {
          v10 = v46.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v46.Bonus.pWeakProxy = 0i64;
          v46.value = 0ui64;
          v46.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
        }
      }
      if ( (resulta.Flags & 0x1F) > 9 )
      {
        if ( (resulta.Flags >> 9) & 1 )
        {
          v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          resulta.Bonus.pWeakProxy = 0i64;
          resulta.value = 0ui64;
          resulta.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
        }
      }
LABEL_100:
      v6->Result = 1;
LABEL_14:
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      return v6;
    default:
      goto LABEL_13;
  }
}

// File Line: 568
// RVA: 0x81DEA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SlotInfo::SetSlotValue(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::CheckResult *v6; // rdi
  Scaleform::GFx::AS3::SlotInfo *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rax
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
  signed int v22; // eax
  __int64 v23; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // rcx
  unsigned int v25; // eax
  __int64 v26; // rsi
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  unsigned int v30; // ebx
  Scaleform::GFx::AS3::VTable *v31; // rax
  int v32; // eax
  Scaleform::GFx::AS3::VM::Error *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::AS3::Value *v35; // rax
  int v36; // ecx
  long double v37; // rcx
  Scaleform::GFx::AS3::VM::Error *v38; // rax
  _DWORD *result_on_stack; // [rsp+30h] [rbp-79h]
  Scaleform::GFx::AS3::Instances::fl::XMLList *p; // [rsp+38h] [rbp-71h]
  Scaleform::GFx::AS3::Value other; // [rsp+40h] [rbp-69h]
  __int64 v43; // [rsp+60h] [rbp-49h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+68h] [rbp-41h]
  Scaleform::GFx::AS3::VM::Error v45; // [rsp+88h] [rbp-21h]
  Scaleform::GFx::AS3::Value _this; // [rsp+98h] [rbp-11h]
  Scaleform::GFx::AS3::VM::Error v47; // [rsp+B8h] [rbp+Fh]
  Scaleform::GFx::AS3::VM::Error v48; // [rsp+C8h] [rbp+1Fh]
  __int64 v49; // [rsp+D8h] [rbp+2Fh]
  long double v50; // [rsp+128h] [rbp+7Fh]

  v49 = -2i64;
  v4 = v;
  v5 = vm;
  v6 = result;
  v7 = this;
  if ( *(_BYTE *)this & 3 && vm->InInitializer <= 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v45, eConstWriteError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v8, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v9 = v45.Message.pNode;
    v10 = v45.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v6->Result = 0;
    return v6;
  }
  other.Flags = 0;
  result_on_stack = 0i64;
  if ( (v->Flags & 0x1F) == 13 || (signed int)((*(_DWORD *)this & 0xFFFFFC00) << 17) > 1342177280 )
  {
    Scaleform::GFx::AS3::Value::Assign(&other, v);
  }
  else
  {
    v11 = Scaleform::GFx::AS3::SlotInfo::GetDataType(this, vm);
    if ( !v11 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v45, eClassNotFoundError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v12, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
LABEL_10:
      v13 = v45.Message.pNode;
LABEL_11:
      v10 = v13->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
LABEL_13:
      v6->Result = 0;
      goto LABEL_14;
    }
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v11->vfptr[3].Finalize_GC)(
            v11,
            v4,
            &other) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v45, eCheckTypeFailedError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v14, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      goto LABEL_10;
    }
  }
  v15 = (unsigned int)(*(_DWORD *)v7 >> 15);
  switch ( *(_DWORD *)v7 << 17 >> 27 )
  {
    case 1:
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)(*(_QWORD *)(*(_QWORD *)&v50 + 168i64)
                                     + 32i64 * (unsigned int)(*(_DWORD *)v7 >> 15)),
        &other);
      goto LABEL_105;
    case 2:
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)(*(_QWORD *)&v50 + (unsigned int)v15), &other);
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
      v23 = *(_QWORD *)((unsigned int)v15 + *(_QWORD *)&v50);
      if ( v17 != v23 )
      {
        if ( v23 )
        {
          v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v23 & 0xFFFFFFFFFFFFFFF9ui64);
          if ( (unsigned __int8)v24 & 1 )
          {
            *(_QWORD *)((unsigned int)v15 + *(_QWORD *)&v50) = (char *)v24
                                                             + (*(_DWORD *)((unsigned int)v15 + *(_QWORD *)&v50) & 6)
                                                             - 1;
          }
          else
          {
            v25 = v24->RefCount;
            if ( v25 & 0x3FFFFF )
            {
              v24->RefCount = v25 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
            }
          }
        }
        *(_QWORD *)(v16 + *(_QWORD *)&v50) = v17;
        if ( v17 )
          *(_DWORD *)((v17 & 0xFFFFFFFFFFFFFFF8ui64) + 32) = (*(_DWORD *)((v17 & 0xFFFFFFFFFFFFFFF8ui64) + 32) + 1) & 0x8FBFFFFF;
      }
      goto LABEL_105;
    case 4:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(_QWORD *)&v50 + (unsigned int)v15),
        p);
      goto LABEL_105;
    case 5:
      *(_BYTE *)(v15 + *(_QWORD *)&v50) = (_BYTE)p;
      goto LABEL_105;
    case 6:
    case 7:
      *(_DWORD *)(v15 + *(_QWORD *)&v50) = (_DWORD)p;
      goto LABEL_105;
    case 8:
      *(_QWORD *)(v15 + *(_QWORD *)&v50) = p;
      goto LABEL_105;
    case 9:
      v26 = (unsigned int)v15;
      v27 = *(Scaleform::GFx::ASStringNode **)(v15 + *(_QWORD *)&v50);
      if ( v27 )
      {
        v10 = v27->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      }
      *(_QWORD *)(v26 + *(_QWORD *)&v50) = p;
      if ( p )
        ++LODWORD(p->pPrev);
      goto LABEL_105;
    case 0xA:
    case 0xC:
      Scaleform::GFx::AS3::VM::Error::Error(&v45, eConstWriteError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v28, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v29 = v45.Message.pNode;
      v10 = v45.Message.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      goto LABEL_105;
    case 0xB:
      Scaleform::GFx::AS3::VM::Error::Error(&v47, eCannotAssignToMethodError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v38, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v13 = v47.Message.pNode;
      goto LABEL_11;
    case 0xD:
    case 0xE:
      v30 = v15 + 1;
      v31 = Scaleform::GFx::AS3::Traits::GetVT(*(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v50 + 40i64));
      Scaleform::GFx::AS3::VTable::GetValue(
        v31,
        (Scaleform::GFx::AS3::Value *)((char *)&other + 8),
        (Scaleform::GFx::AS3::AbsoluteIndex)v30);
      v32 = (_QWORD)other.Bonus.pWeakProxy & 0x1F;
      if ( v32 < 12 && (unsigned int)(v32 - 5) > 2 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v48, eCallOfNonFunctionError, v5);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v33, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v34 = v48.Message.pNode;
        v10 = v48.Message.pNode->RefCount == 1;
        --v34->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
        v6->Result = 0;
LABEL_62:
        if ( ((_QWORD)other.Bonus.pWeakProxy & 0x1F) > 9 )
        {
          if ( (LODWORD(other.Bonus.pWeakProxy) >> 9) & 1 )
          {
            v10 = other.value.VS._1.VStr->pData-- == (const char *)1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            other.value = 0ui64;
            v43 = 0i64;
            LODWORD(other.Bonus.pWeakProxy) &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&other + 8));
          }
        }
        goto LABEL_14;
      }
      v35 = Scaleform::GFx::AS3::Value::GetUndefined();
      resulta.Flags = v35->Flags;
      resulta.Bonus.pWeakProxy = v35->Bonus.pWeakProxy;
      resulta.value = v35->value;
      v36 = v35->Flags & 0x1F;
      if ( v36 <= 9 )
        goto LABEL_80;
      if ( (v35->Flags >> 9) & 1 )
      {
        ++v35->Bonus.pWeakProxy->RefCount;
        goto LABEL_80;
      }
      if ( v36 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v35->value.VNumber + 24i64);
      }
      else
      {
        if ( v36 <= 10 )
          goto LABEL_80;
        if ( v36 <= 15 )
        {
          v37 = v35->value.VNumber;
        }
        else
        {
          if ( v36 > 17 )
            goto LABEL_80;
          v37 = *(double *)&v35->value.VS._2.VObj;
        }
        if ( v37 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v37 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v37 + 32i64) + 1) & 0x8FBFFFFF;
      }
LABEL_80:
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0i64;
      _this.value.VNumber = v50;
      *(_DWORD *)(*(_QWORD *)&v50 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v50 + 32i64) + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        v5,
        (Scaleform::GFx::AS3::Value *)((char *)&other + 8),
        &_this,
        &resulta,
        1u,
        &other,
        0);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags >> 9) & 1 )
        {
          v10 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _this.Bonus.pWeakProxy = 0i64;
          _this.value = 0ui64;
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      if ( v5->HandleException )
      {
        v6->Result = 0;
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags >> 9) & 1 )
          {
            v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v10 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            resulta.Bonus.pWeakProxy = 0i64;
            resulta.value = 0ui64;
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
        goto LABEL_62;
      }
      if ( (resulta.Flags & 0x1F) > 9 )
      {
        if ( (resulta.Flags >> 9) & 1 )
        {
          v10 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          resulta.Bonus.pWeakProxy = 0i64;
          resulta.value = 0ui64;
          resulta.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
        }
      }
      if ( ((_QWORD)other.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( (LODWORD(other.Bonus.pWeakProxy) >> 9) & 1 )
        {
          v10 = other.value.VS._1.VStr->pData-- == (const char *)1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.value = 0ui64;
          v43 = 0i64;
          LODWORD(other.Bonus.pWeakProxy) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&other + 8));
        }
      }
LABEL_105:
      v6->Result = 1;
LABEL_14:
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v10 = (*result_on_stack)-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          *(_QWORD *)&other.Flags = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      return v6;
    default:
      goto LABEL_13;
  }
}

// File Line: 760
// RVA: 0x7D62C0
void __fastcall Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::Object *obj, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  __int64 v4; // r10
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  unsigned __int64 *v8; // rdi
  unsigned __int64 v9; // rax
  int v10; // ebx
  unsigned __int64 v11; // [rsp+30h] [rbp+8h]

  v4 = *(_DWORD *)this;
  v5 = (*(_DWORD *)this << 17 >> 27) - 1;
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
            ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
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
          op(prcc, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v11);
          *v8 = v11 | v10;
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::ForEachChild_GC(prcc, (Scaleform::GFx::AS3::Value *)((char *)obj + (v4 >> 15)), op);
    }
  }
  else
  {
    Scaleform::GFx::AS3::ForEachChild_GC(
      prcc,
      (Scaleform::GFx::AS3::Value *)obj[3].vfptr + (unsigned int)((signed int)v4 >> 15),
      op);
  }
}

// File Line: 810
// RVA: 0x7E75E0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::SlotInfo::GetDataType(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rsi
  Scaleform::GFx::AS3::SlotInfo *v3; // r14
  Scaleform::GFx::AS3::VMAbcFile *v4; // rbp
  Scaleform::GFx::AS3::Abc::TraitInfo *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v6; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rax
  Scaleform::GFx::AS3::Multiname v10; // [rsp+28h] [rbp-40h]

  v2 = vm;
  v3 = this;
  if ( !this->CTraits.pObject )
  {
    v4 = this->File.pObject;
    if ( v4 && (v5 = this->TI) != 0i64 )
    {
      if ( v5->kind & 0xF && (v5->kind & 0xFu) - 4 > 2 )
      {
        v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsFunction.pObject;
LABEL_17:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->CTraits,
          v6);
      }
      else
      {
        v7 = Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(v5, v4->File.pObject);
        Scaleform::GFx::AS3::Multiname::Multiname(&v10, (Scaleform::GFx::AS3::VMFile *)&v4->vfptr, v7);
        v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
                                                              v2,
                                                              (Scaleform::GFx::AS3::VMFile *)&v3->File.pObject->vfptr,
                                                              v7);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->CTraits,
          v8);
        Scaleform::GFx::AS3::Multiname::~Multiname(&v10);
      }
    }
    else
    {
      switch ( *(_DWORD *)v3 << 17 >> 27 )
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
        case 0xA:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsString.pObject;
          goto LABEL_17;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
          v6 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->TraitsFunction.pObject;
          goto LABEL_17;
        default:
          return v3->CTraits.pObject;
      }
    }
  }
  return v3->CTraits.pObject;
}

// File Line: 889
// RVA: 0x7F8420
signed __int64 __fastcall Scaleform::GFx::AS3::SlotInfo::IsClassType(Scaleform::GFx::AS3::SlotInfo *this)
{
  Scaleform::GFx::AS3::VMAbcFile *v1; // r8
  Scaleform::GFx::AS3::Abc::TraitInfo *v2; // rax
  Scaleform::GFx::AS3::Abc::File *v3; // r8
  __int64 v4; // rdx
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rdx
  signed __int64 v6; // rbx
  const char *v7; // r9
  char v8; // al
  char *v9; // r9
  unsigned int v10; // ecx
  int v11; // er8
  char v12; // dl
  int v13; // eax
  signed __int64 result; // rax

  v1 = this->File.pObject;
  if ( !v1 )
    return 0i64;
  v2 = this->TI;
  if ( !v2 )
    return 0i64;
  v3 = v1->File.pObject;
  if ( v2->kind & 0xF && (v2->kind & 0xF) != 6 )
    v4 = v3->AS3_Classes.Info.Data.Data[v2->Ind]->inst_info.name_ind;
  else
    v4 = v2->Ind;
  v5 = &v3->Const_Pool.const_multiname.Data.Data[v4];
  if ( v5->Ind )
    v6 = (signed __int64)&v3->Const_Pool.ConstNamespace.Data.Data[v5->Ind];
  else
    v6 = (signed __int64)&v3->Const_Pool.any_namespace;
  v7 = v3->Const_Pool.ConstStr.Data.Data[v5->NameIndex].Data;
  if ( !v7 )
    return 0i64;
  v8 = *v7;
  v9 = (char *)(v7 + 1);
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
  if ( v11 != 5i64 || "Class" != v9 && (!v9 || strncmp(v9, "Class", v11)) || *(_DWORD *)v6 & 0xFFFFFFFB )
    return 0i64;
  result = 0i64;
  if ( !*(_QWORD *)(v6 + 16) )
    result = 1i64;
  return result;
}

// File Line: 987
// RVA: 0x7EC730
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::SlotInfo::GetName(Scaleform::GFx::AS3::SlotInfo *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rbx
  unsigned __int64 v4; // rcx
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  Scaleform::StringDataPtr v8; // [rsp+30h] [rbp-18h]

  v2 = result;
  v3 = this->Name.pObject;
  v4 = v3->Size;
  v8.pStr = v3->pData;
  v8.Size = v4;
  v5 = Scaleform::StringDataPtr::FindLastChar(&v8, 47, 0xFFFFFFFFFFFFFFFFui64);
  if ( v5 < 0 )
    v5 = Scaleform::StringDataPtr::FindLastChar(&v8, 46, 0xFFFFFFFFFFFFFFFFui64);
  v6 = v5 + 1;
  if ( v8.Size < v5 + 1 )
    v6 = v8.Size;
  Scaleform::GFx::ASStringManager::CreateString(v3->pManager, v2, &v8.pStr[v6], v8.Size - v6);
  return v2;
}

