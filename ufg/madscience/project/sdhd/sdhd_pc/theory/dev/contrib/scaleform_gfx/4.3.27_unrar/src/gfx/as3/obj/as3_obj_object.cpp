// File Line: 34
// RVA: 0x77EFE0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::Interface(Scaleform::GFx::AS3::InstanceTraits::Interface *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::Interface *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    ci);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Interface::`vftable';
  v3->MemSize = 56;
  v3->Flags |= 4ui64;
}

// File Line: 40
// RVA: 0x7FC690
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::MakeInstance(Scaleform::GFx::AS3::InstanceTraits::Interface *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *v4; // rdi
  Scaleform::GFx::AS3::Instance *v5; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rbx
  int v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::AS3::Instance *v10; // [rsp+68h] [rbp+20h]

  v3 = t;
  v4 = result;
  v8 = 337;
  v5 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v8);
  v6 = (Scaleform::GFx::AS3::Instances::fl::Object *)v5;
  v9 = v5;
  v10 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, v3);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v4->pV = v6;
  return v4;
}

// File Line: 45
// RVA: 0x7FFA60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::MakeObject(Scaleform::GFx::AS3::InstanceTraits::Interface *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::Interface::MakeInstance(this, &resulta, t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 58
// RVA: 0x780F30
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::Object(Scaleform::GFx::AS3::Instances::fl::Object *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
}

// File Line: 64
// RVA: 0x7444C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3isPrototypeOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::VM *v7; // rbx
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  unsigned int v10; // ecx
  long double v11; // rdi
  Scaleform::GFx::AS3::Traits *v12; // rbx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-20h]

  v6 = result;
  v7 = vm;
  v8 = _this->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&_this->value.VNumber )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_21:
    v14 = v16.Message.pNode;
    v15 = v16.Message.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    return;
  }
  if ( argc < 1 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_21;
  }
  v10 = argv->Flags & 0x1F;
  if ( v10 && (v10 - 12 > 3 && v10 != 10 || *(_QWORD *)&argv->value.VNumber) )
  {
    v11 = _this->value.VNumber;
    v12 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, argv);
    if ( v12 )
    {
      while ( 1 )
      {
        if ( !v12->pConstructor.pObject )
          v12->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
        if ( Scaleform::GFx::AS3::Class::GetPrototype(v12->pConstructor.pObject) == *(Scaleform::GFx::AS3::Object **)&v11 )
          break;
        v12 = v12->pParent.pObject;
        if ( !v12 )
          goto LABEL_18;
      }
      Scaleform::GFx::AS3::Value::SetBool(v6, 1);
    }
    else
    {
LABEL_18:
      Scaleform::GFx::AS3::Value::SetBool(v6, 0);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetBool(result, 0);
  }
}

// File Line: 105
// RVA: 0x79F010
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rbx
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rcx
  long double v12; // rbx
  __int64 v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  char v18; // al
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Traits *v20; // rax
  Scaleform::GFx::AS3::SlotInfo *v21; // rax
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASString name; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::AS3::VM::Error v24; // [rsp+38h] [rbp-48h]
  __int64 v25; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname v26; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+B0h] [rbp+30h]

  v25 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = _this->Flags & 0x1F;
  if ( !v9 || (v9 - 12 <= 3 || v9 == 10) && !*(_QWORD *)&_this->value.VNumber )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v22, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    goto LABEL_27;
  }
  if ( argc < 1 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_27:
    v19 = v24.Message.pNode;
LABEL_28:
    v16 = v19->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    return;
  }
  if ( v9 - 12 > 3 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
      &name);
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&resulta, &name)->Result )
    {
      *(_QWORD *)&v24.ID = 0i64;
      v20 = Scaleform::GFx::AS3::VM::GetValueTraits(v8, v7);
      v21 = Scaleform::GFx::AS3::FindFixedSlot(v20, &name, v8->PublicNamespace.pObject, (unsigned __int64 *)&v24, 0i64);
      Scaleform::GFx::AS3::Value::SetBool(v6, v21 != 0i64);
    }
    v19 = name.pNode;
    goto LABEL_28;
  }
  v11 = vm->PublicNamespace.pObject;
  v26.Kind = 0;
  v26.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v11->vfptr;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v26.Name.Flags = 0;
  v26.Name.Bonus.pWeakProxy = 0i64;
  if ( (argv->Flags & 0x1F) - 12 <= 3
    && (v12 = argv->value.VNumber, v12 != 0.0)
    && (v13 = *(_QWORD *)(*(_QWORD *)&v12 + 40i64), *(_DWORD *)(v13 + 120) == 17)
    && ~(*(_BYTE *)(v13 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v26.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v12 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v26.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v12 + 64i64));
    v26.Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v26.Name, argv);
    if ( (v26.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v26.Name, &resulta);
      if ( resulta.pNode->Size )
      {
        if ( *resulta.pNode->pData == 64 )
        {
          v26.Kind |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&resulta, &name, 1, resulta.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v26.Name, v14);
          v15 = name.pNode;
          v16 = name.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = resulta.pNode;
      v16 = resulta.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  v18 = (*((__int64 (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Multiname *, _QWORD))v7->value.VS._1.VStr->pData + 6))(
          *(_QWORD *)&v7->value.VNumber,
          &v26,
          0i64);
  Scaleform::GFx::AS3::Value::SetBool(v6, v18);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v26);
}

// File Line: 137
// RVA: 0x7A17A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rbp
  __int64 v9; // rdi
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  unsigned int v13; // ecx
  Scaleform::GFx::AS3::Traits *v14; // rax
  Scaleform::GFx::AS3::Value *v15; // r14
  unsigned int v16; // ecx
  bool v17; // al
  bool v18; // dl
  Scaleform::GFx::AS3::SlotInfo *v19; // rax
  bool v20; // dl
  __int64 *v21; // rsi
  Scaleform::GFx::ASStringNode *v22; // rdx
  __int64 v23; // r9
  __int64 v24; // r8
  __int64 v25; // rbx
  __int64 *v26; // rcx
  __int64 v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rbx
  Scaleform::GFx::ASStringNode *v31; // rcx
  const char *v32; // rdx
  __int64 v33; // rcx
  char v34; // al
  char v35; // al
  unsigned int ind; // [rsp+34h] [rbp-54h]
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-50h]
  unsigned __int64 index; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v39; // [rsp+48h] [rbp-40h]
  __int64 v40; // [rsp+50h] [rbp-38h]
  int v41; // [rsp+58h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v42; // [rsp+60h] [rbp-28h]

  v40 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = 0i64;
  if ( argc < 1 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&index, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v11 = v39;
    v12 = v39->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    return;
  }
  v13 = _this->Flags & 0x1F;
  if ( v13 - 12 > 3 || (v13 - 12 <= 3 || v13 == 10) && !*(_QWORD *)&_this->value.VNumber )
  {
    if ( v13 == 11 && (argv->Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, &resulta);
      v30 = resulta.pNode;
      index = (unsigned __int64)resulta.pNode;
      ++*(_DWORD *)(index + 24);
      v31 = resulta.pNode;
      v12 = resulta.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      v32 = v30->pData;
      v33 = 0i64;
      while ( 1 )
      {
        v34 = v32[v33++];
        if ( v34 != aPrefix[v33 - 1] )
          break;
        if ( v33 == 7 )
        {
LABEL_51:
          Scaleform::GFx::AS3::Value::SetBool(v6, 1);
          v12 = v30->RefCount-- == 1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
          return;
        }
      }
      while ( 1 )
      {
        v35 = v32[v9++];
        if ( v35 != aUri[v9 - 1] )
          break;
        if ( v9 == 4 )
          goto LABEL_51;
      }
      v12 = v30->RefCount-- == 1;
      if ( v12 )
      {
        v28 = v30;
        goto LABEL_55;
      }
    }
    goto LABEL_56;
  }
  v14 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  v15 = argv;
  v17 = 0;
  if ( v14->TraitsType == 7 )
  {
    if ( ~(LOBYTE(v14->Flags) >> 5) & 1 )
    {
      v16 = argv->Flags & 0x1F;
      if ( v16 - 2 <= 2
        || v16 == 10
        && Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&argc, argv->value.VS._1.VStr, &ind)->Result )
      {
        v17 = 1;
      }
    }
  }
  if ( v17 )
  {
    v18 = 1;
LABEL_57:
    Scaleform::GFx::AS3::Value::SetBool(v6, v18);
    return;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v15, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    index = 0i64;
    v19 = Scaleform::GFx::AS3::FindFixedSlot(
            *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v7->value.VNumber + 40i64),
            &resulta,
            v8->PublicNamespace.pObject,
            &index,
            v7->value.VS._1.VObj);
    if ( v19 )
    {
      v20 = (*(_BYTE *)v19 & 0xC) == 0;
LABEL_38:
      Scaleform::GFx::AS3::Value::SetBool(v6, v20);
      goto LABEL_39;
    }
    v21 = (__int64 *)(*(_QWORD *)&v7->value.VNumber + 48i64);
    if ( v21 )
    {
      v41 = 0;
      v22 = resulta.pNode;
      v42 = resulta.pNode;
      ++v42->RefCount;
      v23 = *v21;
      if ( !*v21 )
        goto LABEL_29;
      v24 = v22->HashFlags & *(_DWORD *)(v23 + 8) & 0xFFFFFF;
      v25 = (unsigned int)v24;
      v26 = (__int64 *)((v24 << 6) + v23 + 16);
      if ( *v26 == -2 || v26[1] != v24 )
        goto LABEL_29;
      while ( v26[1] != v24 || (Scaleform::GFx::ASStringNode *)v26[3] != v22 )
      {
        v25 = *v26;
        if ( *v26 == -1 )
          goto LABEL_29;
        v26 = (__int64 *)((v25 << 6) + v23 + 16);
      }
      if ( v25 < 0 )
      {
LABEL_29:
        v21 = 0i64;
        v25 = 0i64;
      }
      v12 = v22->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      if ( v21 )
      {
        v27 = *v21;
        if ( *v21 )
        {
          if ( v25 <= *(_QWORD *)(v27 + 8) )
          {
            v20 = ~*(_BYTE *)((v25 << 6) + v27 + 32) & 1;
            goto LABEL_38;
          }
        }
      }
    }
    v28 = resulta.pNode;
    v12 = resulta.pNode->RefCount == 1;
    --v28->RefCount;
    if ( v12 )
LABEL_55:
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
LABEL_56:
    v18 = 0;
    goto LABEL_57;
  }
LABEL_39:
  v29 = resulta.pNode;
  v12 = resulta.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
}

// File Line: 189
// RVA: 0x7464A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::hasOwnPropertyProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
}

// File Line: 196
// RVA: 0x746DB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::propertyIsEnumerableProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);
}

// File Line: 203
// RVA: 0x747940
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::setPropertyIsEnumerableProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rbp
  unsigned int v8; // edi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned int v11; // ecx
  bool v12; // r14
  Scaleform::GFx::AS3::Value *v13; // rsi
  __int64 *v14; // rsi
  int v15; // edi
  Scaleform::GFx::ASStringNode *v16; // rdx
  __int64 v17; // r9
  __int64 v18; // r8
  __int64 v19; // rbx
  __int64 *v20; // rcx
  bool v21; // zf
  __int64 v22; // rax
  __int64 v23; // rbx
  Scaleform::GFx::AS3::VM::Error *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::VM::Error *v26; // rax
  Scaleform::GFx::AS3::VM::Error v27; // [rsp+20h] [rbp-38h]
  __int64 v28; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+38h] [rbp-20h]

  v28 = -2i64;
  v6 = _this;
  v7 = vm;
  v8 = argc;
  if ( argc < 1 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v27, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    v10 = v27.Message.pNode;
    goto LABEL_30;
  }
  v11 = _this->Flags & 0x1F;
  if ( v11 - 12 <= 3 && (v11 - 12 > 3 && v11 != 10 || *(_QWORD *)&_this->value.VNumber) )
  {
    v12 = 1;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
      (Scaleform::GFx::ASString *)&v27);
    v13 = argv;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&argc,
            (Scaleform::GFx::ASString *)&v27)->Result )
      goto LABEL_8;
    if ( v8 > 1 )
      v12 = Scaleform::GFx::AS3::Value::Convert2Boolean(v13 + 1);
    v14 = (__int64 *)(*(_QWORD *)&v6->value.VNumber + 48i64);
    if ( *(_QWORD *)&v6->value.VNumber == -48i64 )
      goto LABEL_8;
    v15 = 0;
    v29.ID = 0;
    v16 = *(Scaleform::GFx::ASStringNode **)&v27.ID;
    v29.Message.pNode = *(Scaleform::GFx::ASStringNode **)&v27.ID;
    ++v29.Message.pNode->RefCount;
    v17 = *v14;
    if ( !*v14 )
      goto LABEL_20;
    v18 = v16->HashFlags & *(_DWORD *)(v17 + 8) & 0xFFFFFF;
    v19 = (unsigned int)v18;
    v20 = (__int64 *)((v18 << 6) + v17 + 16);
    if ( *v20 == -2 || v20[1] != v18 )
      goto LABEL_20;
    while ( v20[1] != v18 || (Scaleform::GFx::ASStringNode *)v20[3] != v16 )
    {
      v19 = *v20;
      if ( *v20 == -1 )
        goto LABEL_20;
      v20 = (__int64 *)((v19 << 6) + v17 + 16);
    }
    if ( v19 < 0 )
    {
LABEL_20:
      v14 = 0i64;
      v19 = 0i64;
    }
    v21 = v16->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( v14 )
    {
      v22 = *v14;
      if ( *v14 )
      {
        if ( v19 <= *(_QWORD *)(v22 + 8) )
        {
          v23 = v19 << 6;
          *(_DWORD *)(v23 + v22 + 32) &= 0xFFFFFFFE;
          LOBYTE(v15) = v12 == 0;
          *(_DWORD *)(v23 + v22 + 32) |= -v15 & 1;
LABEL_8:
          v10 = *(Scaleform::GFx::ASStringNode **)&v27.ID;
          goto LABEL_30;
        }
      }
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v29, eWriteSealedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v24, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v25 = v29.Message.pNode;
    v21 = v29.Message.pNode->RefCount == 1;
    --v25->RefCount;
    if ( !v21 )
      goto LABEL_8;
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    v10 = *(Scaleform::GFx::ASStringNode **)&v27.ID;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v29, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v26, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v29.Message.pNode;
  }
LABEL_30:
  v21 = v10->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 253
// RVA: 0x7481B0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::isPrototypeOfProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3isPrototypeOf(ti, vm, _this, result, argc, argv);
}

// File Line: 260
// RVA: 0x748770
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rdi
  Scaleform::GFx::AS3::Traits *v7; // r11
  Scaleform::GFx::AS3::ClassTraits::Function *v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h]
  __int64 v17; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString v; // [rsp+48h] [rbp+10h]

  v17 = -2i64;
  v4 = result;
  v5 = _this;
  v6 = vm;
  v7 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  v8 = v6->TraitsFunction.pObject;
  v.pNode = v6->StringManagerRef->Builtins[19].pNode;
  ++v.pNode->RefCount;
  if ( v7->TraitsType == 10 && ~(LOBYTE(v7->Flags) >> 5) & 1 )
  {
    if ( v7 == (Scaleform::GFx::AS3::Traits *)v8->ThunkTraits.pObject )
    {
      v9 = Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
             (Scaleform::GFx::AS3::InstanceTraits::Thunk *)v7,
             &resulta,
             v5);
      Scaleform::GFx::ASString::Append(&v, v9);
    }
    else if ( v7 == (Scaleform::GFx::AS3::Traits *)v8->ThunkFunctionTraits.pObject )
    {
      v10 = Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::GetThunkName(
              (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)v7,
              &resulta,
              v5);
      Scaleform::GFx::ASString::Append(&v, v10);
    }
    else
    {
      if ( v7 == (Scaleform::GFx::AS3::Traits *)v8->MethodIndTraits.pObject )
        v11 = Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
                (Scaleform::GFx::AS3::InstanceTraits::Thunk *)v7,
                &resulta,
                v5);
      else
        v11 = Scaleform::GFx::AS3::InstanceTraits::Function::GetFunctionName(
                (Scaleform::GFx::AS3::InstanceTraits::Function *)v7,
                &resulta,
                v5);
      Scaleform::GFx::ASString::Append(&v, v11);
    }
  }
  else
  {
    v12 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *))v7->vfptr[1].~RefCountBaseGC<328>)(
                                        v7,
                                        &resulta);
    Scaleform::GFx::ASString::Append(&v, v12);
  }
  v13 = resulta.pNode;
  v14 = resulta.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  Scaleform::GFx::ASString::Append(&v, (Scaleform::GFx::ASString *)&v6->StringManagerRef->Builtins[20]);
  Scaleform::GFx::AS3::Value::Assign(v4, &v);
  v15 = v.pNode;
  v14 = v.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 338
// RVA: 0x749900
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::toLocaleStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object::toStringProto(ti, vm, _this, result);
}

// File Line: 345
// RVA: 0x749D20
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::valueOfProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::Assign(result, _this);
}

// File Line: 372
// RVA: 0x1597160
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::Object::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 379
// RVA: 0x780F00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(Scaleform::GFx::AS3::InstanceTraits::fl::Object *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    ci);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
}

// File Line: 386
// RVA: 0x7FFD60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::Object *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 430
// RVA: 0x7F48E0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Object::InitPrototype(Scaleform::GFx::AS3::Classes::fl::Object *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rsi
  Scaleform::GFx::ASStringNode *v3; // r14
  Scaleform::GFx::AS3::Class *v4; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  signed __int64 v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  int v11; // eax
  _DWORD *v12; // rdx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rcx
  unsigned int v15; // eax
  int v16; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  unsigned int v19; // [rsp+48h] [rbp-28h]
  _DWORD *v20; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v21; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h]

  v2 = obj;
  v3 = (Scaleform::GFx::ASStringNode *)this;
  v4 = this->ParentClass.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::GFx::AS3::Class *))v4->vfptr[7].Finalize_GC)(v4);
  v5 = Scaleform::GFx::AS3::Classes::fl::Object::ti;
  v6 = 7i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(v2, v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  v19 = 13;
  v20 = 0i64;
  v21 = v3;
  v3->Size = (v3->Size + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(*((_QWORD *)v3[1].pData
                                                                                                 + 16)
                                                                                               + 16i64),
         &result,
         "constructor");
  v16 = 1;
  v17 = v7->pNode;
  ++v17->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v16;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v19;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v2->DynAttrs.mHash.pTable,
    &v2->DynAttrs,
    &key);
  v8 = v17;
  v9 = v17->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = v19 & 0x1F;
  if ( v11 > 9 )
  {
    if ( (v19 >> 9) & 1 )
    {
      v12 = v20;
      v9 = *v20 == 1;
      --*v12;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v12);
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0i64;
      v19 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v11 )
      {
        case 10:
          v13 = v21;
          v9 = v21->RefCount == 1;
          --v13->RefCount;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v14 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v21;
          if ( !((unsigned __int8)v21 & 1) )
            goto LABEL_21;
          v21 = (Scaleform::GFx::ASStringNode *)((char *)v21 - 1);
          break;
        case 16:
        case 17:
          v14 = v22;
          if ( (unsigned __int8)v22 & 1 )
          {
            v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
          }
          else
          {
LABEL_21:
            if ( v14 )
            {
              v15 = v14->RefCount;
              if ( v15 & 0x3FFFFF )
              {
                v14->RefCount = v15 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 446
// RVA: 0x7B8D70
void __fastcall Scaleform::GFx::AS3::Classes::fl::Object::Construct(Scaleform::GFx::AS3::Classes::fl::Object *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // rdi
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::ClassTraits::Function *v7; // rcx
  long double v8; // rsi
  Scaleform::GFx::AS3::Classes::Function **v9; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *v10; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> resulta; // [rsp+30h] [rbp+8h]

  v4 = this->pTraits.pObject;
  v5 = result;
  if ( !argc )
  {
LABEL_11:
    (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *))v4[1].vfptr->ForEachChild_GC
     + 11))(
      v4[1].vfptr,
      result,
      v4[1].vfptr,
      argv);
    return;
  }
  v6 = argv->Flags & 0x1F;
  if ( v6 != 5 )
  {
    if ( v6 && (v6 - 12 > 3 && v6 != 10 || *(_QWORD *)&argv->value.VNumber) )
    {
      Scaleform::GFx::AS3::Value::Assign(result, argv);
      return;
    }
    goto LABEL_11;
  }
  v7 = v4->pVM->TraitsFunction.pObject;
  v8 = argv->value.VNumber;
  v9 = (Scaleform::GFx::AS3::Classes::Function **)v7->ITraits.pObject;
  if ( !v9[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v9)[1]._pRCC)(v7->ITraits.pObject);
  v10 = Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
          v9[17],
          &resulta,
          *(Scaleform::GFx::AS3::ThunkInfo **)&v8);
  Scaleform::GFx::AS3::Value::Pick(v5, v10->pV);
}

// File Line: 494
// RVA: 0x780ED0
void __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(Scaleform::GFx::AS3::ClassTraits::fl::Object *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v3; // rbx

  v3 = this;
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits((Scaleform::GFx::AS3::ClassTraits::Traits *)&this->vfptr, vm, ci);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
}

// File Line: 501
// RVA: 0x753520
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Object::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::ObjectCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::ObjectCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Object::`vftable';
  }
  return v3;
}

