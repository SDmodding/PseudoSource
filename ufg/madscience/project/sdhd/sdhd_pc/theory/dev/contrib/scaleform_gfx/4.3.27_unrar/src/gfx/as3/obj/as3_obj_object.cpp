// File Line: 34
// RVA: 0x77EFE0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::Interface(
        Scaleform::GFx::AS3::InstanceTraits::Interface *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Interface::`vftable;
  this->MemSize = 56;
  this->Flags |= 4ui64;
}

// File Line: 40
// RVA: 0x7FC690
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::Interface *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance *v5; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rbx
  int v8; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::AS3::Instance *v10; // [rsp+68h] [rbp+20h]

  v8 = 337;
  v5 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v8);
  v6 = (Scaleform::GFx::AS3::Instances::fl::Object *)v5;
  v9 = v5;
  v10 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, t);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  return result;
}

// File Line: 45
// RVA: 0x7FFA60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Interface::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::Interface *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::Interface::MakeInstance(this, &resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 58
// RVA: 0x780F30
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::Object(
        Scaleform::GFx::AS3::Instances::fl::Object *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
}

// File Line: 64
// RVA: 0x7444C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3isPrototypeOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::Object *VObj; // rdi
  Scaleform::GFx::AS3::Traits *ValueTraits; // rbx
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-20h] BYREF

  v8 = _this->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !_this->value.VS._1.VStr )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_21:
    pNode = v16.Message.pNode;
    if ( v16.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( !argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    goto LABEL_21;
  }
  v10 = argv->Flags & 0x1F;
  if ( v10 && (v10 - 12 > 3 && v10 != 10 || argv->value.VS._1.VStr) )
  {
    VObj = _this->value.VS._1.VObj;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, argv);
    if ( ValueTraits )
    {
      while ( 1 )
      {
        if ( !ValueTraits->pConstructor.pObject )
          ValueTraits->vfptr[3].~RefCountBaseGC<328>(ValueTraits);
        if ( Scaleform::GFx::AS3::Class::GetPrototype(ValueTraits->pConstructor.pObject) == VObj )
          break;
        ValueTraits = ValueTraits->pParent.pObject;
        if ( !ValueTraits )
          goto LABEL_18;
      }
      Scaleform::GFx::AS3::Value::SetBool(result, 1);
    }
    else
    {
LABEL_18:
      Scaleform::GFx::AS3::Value::SetBool(result, 0);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetBool(result, 0);
  }
}

// File Line: 105
// RVA: 0x79F010
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::AS3::Value::V1U v12; // rbx
  const char *pData; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  char v18; // al
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASString name; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v24; // [rsp+38h] [rbp-48h] BYREF
  __int64 v25; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname v26; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+B0h] [rbp+30h] BYREF

  v25 = -2i64;
  v9 = _this->Flags & 0x1F;
  if ( !v9 || (v9 - 12 <= 3 || v9 == 10) && !_this->value.VS._1.VStr )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, 1009, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v22, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    goto LABEL_27;
  }
  if ( !argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v24, 1063, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
LABEL_27:
    pNode = v24.Message.pNode;
LABEL_28:
    v16 = pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( v9 - 12 > 3 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      vm->StringManagerRef,
      &name);
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&resulta, &name)->Result )
    {
      *(_QWORD *)&v24.ID = 0i64;
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
      FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                    ValueTraits,
                    &name,
                    vm->PublicNamespace.pObject,
                    (unsigned __int64 *)&v24,
                    0i64);
      Scaleform::GFx::AS3::Value::SetBool(result, FixedSlot != 0i64);
    }
    pNode = name.pNode;
    goto LABEL_28;
  }
  pObject = vm->PublicNamespace.pObject;
  v26.Kind = MN_QName;
  v26.Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v26.Name.Flags = 0;
  v26.Name.Bonus.pWeakProxy = 0i64;
  if ( (argv->Flags & 0x1F) - 12 <= 3
    && (v12 = argv->value.VS._1, v12.VStr)
    && (pData = v12.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v26.Name, (Scaleform::GFx::ASString *)&v12.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v26.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v12.VStr[1].RefCount);
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
          v16 = name.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = resulta.pNode;
      v16 = resulta.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  v18 = (*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Multiname *, _QWORD))_this->value.VS._1.VStr->pData
         + 6))(
          _this->value.VS._1,
          &v26,
          0i64);
  Scaleform::GFx::AS3::Value::SetBool(result, v18);
  Scaleform::GFx::AS3::Multiname::~Multiname(&v26);
}

// File Line: 137
// RVA: 0x7A17A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  __int64 v9; // rdi
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  unsigned int v13; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Value *v15; // r14
  unsigned int v16; // ecx
  bool v18; // dl
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  bool v20; // dl
  Scaleform::GFx::ASStringManager **p_pManager; // rsi
  Scaleform::GFx::ASStringNode *v22; // rdx
  Scaleform::GFx::ASStringManager *v23; // r9
  __int64 v24; // r8
  __int64 v25; // rbx
  __int64 *v26; // rcx
  Scaleform::GFx::ASStringManager *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASStringNode *v30; // rbx
  Scaleform::GFx::ASStringNode *v31; // rcx
  const char *pData; // rdx
  __int64 v33; // rcx
  char v34; // al
  char v35; // al
  unsigned int ind; // [rsp+34h] [rbp-54h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error index; // [rsp+40h] [rbp-48h] BYREF
  __int64 v39; // [rsp+50h] [rbp-38h]
  int v40; // [rsp+58h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v41; // [rsp+60h] [rbp-28h]

  v39 = -2i64;
  v9 = 0i64;
  if ( !argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&index, 1063, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = index.Message.pNode;
    v12 = index.Message.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  v13 = _this->Flags & 0x1F;
  if ( v13 - 12 > 3 || !_this->value.VS._1.VStr )
  {
    if ( v13 == 11 && (argv->Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, &resulta);
      v30 = resulta.pNode;
      *(Scaleform::GFx::ASString *)&index.ID = resulta;
      ++resulta.pNode->RefCount;
      v31 = resulta.pNode;
      v12 = resulta.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      pData = v30->pData;
      v33 = 0i64;
      while ( 1 )
      {
        v34 = pData[v33++];
        if ( v34 != aPrefix[v33 - 1] )
          break;
        if ( v33 == 7 )
        {
LABEL_49:
          Scaleform::GFx::AS3::Value::SetBool(result, 1);
          v12 = v30->RefCount-- == 1;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
          return;
        }
      }
      while ( 1 )
      {
        v35 = pData[v9++];
        if ( v35 != aUri[v9 - 1] )
          break;
        if ( v9 == 4 )
          goto LABEL_49;
      }
      v12 = v30->RefCount-- == 1;
      if ( v12 )
      {
        v28 = v30;
        goto LABEL_53;
      }
    }
    goto LABEL_54;
  }
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  v15 = argv;
  if ( ValueTraits->TraitsType == Traits_Array && (ValueTraits->Flags & 0x20) == 0 )
  {
    v16 = argv->Flags & 0x1F;
    if ( v16 - 2 <= 2
      || v16 == 10
      && Scaleform::GFx::AS3::GetArrayInd((Scaleform::GFx::AS3::CheckResult *)&argc, argv->value.VS._1.VStr, &ind)->Result )
    {
      v18 = 1;
LABEL_55:
      Scaleform::GFx::AS3::Value::SetBool(result, v18);
      return;
    }
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v15, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    *(_QWORD *)&index.ID = 0i64;
    FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                  (Scaleform::GFx::AS3::Traits *)_this->value.VS._1.VStr[1].pData,
                  &resulta,
                  vm->PublicNamespace.pObject,
                  (unsigned __int64 *)&index,
                  _this->value.VS._1.VObj);
    if ( FixedSlot )
    {
      v20 = (*(_BYTE *)FixedSlot & 0xC) == 0;
LABEL_36:
      Scaleform::GFx::AS3::Value::SetBool(result, v20);
      goto LABEL_37;
    }
    p_pManager = &_this->value.VS._1.VStr[1].pManager;
    if ( p_pManager )
    {
      v40 = 0;
      v22 = resulta.pNode;
      v41 = resulta.pNode;
      ++resulta.pNode->RefCount;
      v23 = *p_pManager;
      if ( !*p_pManager )
        goto LABEL_27;
      v24 = v22->HashFlags & v23->RefCount & 0xFFFFFF;
      v25 = (unsigned int)v24;
      v26 = (__int64 *)(&v23->StringSet + 8 * v24);
      if ( *v26 == -2 || v26[1] != v24 )
        goto LABEL_27;
      while ( v26[1] != v24 || (Scaleform::GFx::ASStringNode *)v26[3] != v22 )
      {
        v25 = *v26;
        if ( *v26 == -1 )
          goto LABEL_27;
        v26 = (__int64 *)(&v23->StringSet + 8 * v25);
      }
      if ( v25 < 0 )
      {
LABEL_27:
        p_pManager = 0i64;
        v25 = 0i64;
      }
      v12 = v22->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      if ( p_pManager )
      {
        v27 = *p_pManager;
        if ( *p_pManager )
        {
          if ( v25 <= *(_QWORD *)&v27->RefCount )
          {
            v20 = (*(_BYTE *)(&v27->pFreeStringNodes + 8 * v25) & 1) == 0;
            goto LABEL_36;
          }
        }
      }
    }
    v28 = resulta.pNode;
    v12 = resulta.pNode->RefCount-- == 1;
    if ( v12 )
LABEL_53:
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
LABEL_54:
    v18 = 0;
    goto LABEL_55;
  }
LABEL_37:
  v29 = resulta.pNode;
  v12 = resulta.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
}

// File Line: 189
// RVA: 0x7464A0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::hasOwnPropertyProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3hasOwnProperty(ti, vm, _this, result, argc, argv);
}

// File Line: 196
// RVA: 0x746DB0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::propertyIsEnumerableProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3propertyIsEnumerable(ti, vm, _this, result, argc, argv);
}

// File Line: 203
// RVA: 0x747940
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::setPropertyIsEnumerableProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v8; // edi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // r14
  Scaleform::GFx::AS3::Value *v12; // rsi
  Scaleform::GFx::ASStringManager **p_pManager; // rsi
  int v14; // edi
  Scaleform::GFx::ASStringNode *v15; // rdx
  Scaleform::GFx::ASStringManager *v16; // r9
  __int64 v17; // r8
  __int64 v18; // rbx
  __int64 *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringManager *v21; // rax
  __int64 v22; // rbx
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::VM::Error *v25; // rax
  Scaleform::GFx::AS3::VM::Error v26; // [rsp+20h] [rbp-38h] BYREF
  __int64 v27; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+38h] [rbp-20h] BYREF

  v27 = -2i64;
  v8 = argc;
  if ( !argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v26, eWrongArgumentCountError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
    pNode = v26.Message.pNode;
    goto LABEL_28;
  }
  if ( (_this->Flags & 0x1F) - 12 <= 3 && _this->value.VS._1.VStr )
  {
    v11 = 1;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      vm->StringManagerRef,
      (Scaleform::GFx::ASString *)&v26);
    v12 = argv;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(
            argv,
            (Scaleform::GFx::AS3::CheckResult *)&argc,
            (Scaleform::GFx::ASString *)&v26)->Result )
      goto LABEL_6;
    if ( v8 > 1 )
      v11 = Scaleform::GFx::AS3::Value::Convert2Boolean(v12 + 1);
    p_pManager = &_this->value.VS._1.VStr[1].pManager;
    if ( _this->value.VS._1.VStr == (Scaleform::GFx::ASStringNode *)-48i64 )
      goto LABEL_6;
    v14 = 0;
    v28.ID = 0;
    v15 = *(Scaleform::GFx::ASStringNode **)&v26.ID;
    v28.Message.pNode = *(Scaleform::GFx::ASStringNode **)&v26.ID;
    ++*(_DWORD *)(*(_QWORD *)&v26.ID + 24i64);
    v16 = *p_pManager;
    if ( !*p_pManager )
      goto LABEL_18;
    v17 = v15->HashFlags & v16->RefCount & 0xFFFFFF;
    v18 = (unsigned int)v17;
    v19 = (__int64 *)(&v16->StringSet + 8 * v17);
    if ( *v19 == -2 || v19[1] != v17 )
      goto LABEL_18;
    while ( v19[1] != v17 || (Scaleform::GFx::ASStringNode *)v19[3] != v15 )
    {
      v18 = *v19;
      if ( *v19 == -1 )
        goto LABEL_18;
      v19 = (__int64 *)(&v16->StringSet + 8 * v18);
    }
    if ( v18 < 0 )
    {
LABEL_18:
      p_pManager = 0i64;
      v18 = 0i64;
    }
    v20 = v15->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    if ( p_pManager )
    {
      v21 = *p_pManager;
      if ( *p_pManager )
      {
        if ( v18 <= *(_QWORD *)&v21->RefCount )
        {
          v22 = v18 << 6;
          *(_DWORD *)((char *)&v21->pFreeStringNodes + v22) &= ~1u;
          LOBYTE(v14) = !v11;
          *(_DWORD *)((char *)&v21->pFreeStringNodes + v22) |= -v14 & 1;
LABEL_6:
          pNode = *(Scaleform::GFx::ASStringNode **)&v26.ID;
          goto LABEL_28;
        }
      }
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v28, eWriteSealedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v23, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v24 = v28.Message.pNode;
    v20 = v28.Message.pNode->RefCount-- == 1;
    if ( !v20 )
      goto LABEL_6;
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    pNode = *(Scaleform::GFx::ASStringNode **)&v26.ID;
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v28, eConvertNullToObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v25, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v28.Message.pNode;
  }
LABEL_28:
  v20 = pNode->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 253
// RVA: 0x7481B0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::isPrototypeOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Object::AS3isPrototypeOf(ti, vm, _this, result, argc, argv);
}

// File Line: 260
// RVA: 0x748770
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // r11
  Scaleform::GFx::AS3::ClassTraits::Function *pObject; // rax
  Scaleform::GFx::ASString *MethodIndName; // rax
  Scaleform::GFx::ASString *ThunkName; // rax
  Scaleform::GFx::ASString *FunctionName; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h] BYREF
  __int64 v17; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString v; // [rsp+48h] [rbp+10h] BYREF

  v17 = -2i64;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  pObject = vm->TraitsFunction.pObject;
  v.pNode = vm->StringManagerRef->Builtins[19].pNode;
  ++v.pNode->RefCount;
  if ( ValueTraits->TraitsType != Traits_Function || (ValueTraits->Flags & 0x20) != 0 )
  {
    v12 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *))ValueTraits->vfptr[1].~RefCountBaseGC<328>)(
                                        ValueTraits,
                                        &resulta);
    Scaleform::GFx::ASString::Append(&v, v12);
  }
  else if ( ValueTraits == pObject->ThunkTraits.pObject )
  {
    MethodIndName = Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
                      (Scaleform::GFx::AS3::InstanceTraits::Thunk *)ValueTraits,
                      &resulta,
                      _this);
    Scaleform::GFx::ASString::Append(&v, MethodIndName);
  }
  else if ( ValueTraits == pObject->ThunkFunctionTraits.pObject )
  {
    ThunkName = Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::GetThunkName(
                  (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)ValueTraits,
                  &resulta,
                  _this);
    Scaleform::GFx::ASString::Append(&v, ThunkName);
  }
  else
  {
    if ( ValueTraits == pObject->MethodIndTraits.pObject )
      FunctionName = Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
                       (Scaleform::GFx::AS3::InstanceTraits::Thunk *)ValueTraits,
                       &resulta,
                       _this);
    else
      FunctionName = Scaleform::GFx::AS3::InstanceTraits::Function::GetFunctionName(
                       (Scaleform::GFx::AS3::InstanceTraits::Function *)ValueTraits,
                       &resulta,
                       _this);
    Scaleform::GFx::ASString::Append(&v, FunctionName);
  }
  pNode = resulta.pNode;
  v14 = resulta.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::ASString::Append(&v, (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[20]);
  Scaleform::GFx::AS3::Value::Assign(result, &v);
  v15 = v.pNode;
  v14 = v.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
}

// File Line: 338
// RVA: 0x749900
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::toLocaleStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object::toStringProto(ti, vm, _this, result);
}

// File Line: 345
// RVA: 0x749D20
void __fastcall Scaleform::GFx::AS3::Instances::fl::Object::valueOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
        Scaleform::GFx::AS3::InstanceTraits::fl::Object *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
}

// File Line: 386
// RVA: 0x7FFD60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Object *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Object *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 430
// RVA: 0x7F48E0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Object::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Object *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  int v14; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v17; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v18; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v5 = Scaleform::GFx::AS3::Classes::fl::Object::ti;
  v6 = 7i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v5++);
    --v6;
  }
  while ( v6 );
  v17 = 13;
  v18 = 0i64;
  v19 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         "constructor");
  v14 = 1;
  pNode = v7->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v14;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v17;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v8 = pNode;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( (v17 & 0x1Fu) > 9 )
  {
    if ( (v17 & 0x200) != 0 )
    {
      v9 = (*v18)-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v18 = 0i64;
      v19 = 0i64;
      v20 = 0i64;
      v17 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v17 & 0x1F )
      {
        case 0xA:
          v11 = v19;
          v9 = v19->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v19;
          if ( ((unsigned __int8)v19 & 1) == 0 )
            goto LABEL_21;
          v19 = (Scaleform::GFx::ASStringNode *)((char *)v19 - 1);
          break;
        case 0x10:
        case 0x11:
          v12 = v20;
          if ( ((unsigned __int8)v20 & 1) != 0 )
          {
            v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
          }
          else
          {
LABEL_21:
            if ( v12 )
            {
              RefCount = v12->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v12->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
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
void __fastcall Scaleform::GFx::AS3::Classes::fl::Object::Construct(
        Scaleform::GFx::AS3::Classes::fl::Object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::ClassTraits::Function *v7; // rcx
  Scaleform::GFx::AS3::ThunkInfo *VThunk; // rsi
  Scaleform::GFx::AS3::Classes::Function **v9; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *ThunkFunction; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> resulta; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject;
  if ( !argc )
  {
LABEL_11:
    (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *))pObject[1].vfptr->ForEachChild_GC
     + 11))(
      pObject[1].vfptr,
      result,
      pObject[1].vfptr,
      argv);
    return;
  }
  v6 = argv->Flags & 0x1F;
  if ( v6 != 5 )
  {
    if ( v6 && (v6 - 12 > 3 && v6 != 10 || argv->value.VS._1.VStr) )
    {
      Scaleform::GFx::AS3::Value::Assign(result, argv);
      return;
    }
    goto LABEL_11;
  }
  v7 = pObject->pVM->TraitsFunction.pObject;
  VThunk = argv->value.VS._1.VThunk;
  v9 = (Scaleform::GFx::AS3::Classes::Function **)v7->ITraits.pObject;
  if ( !v9[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v9)[1]._pRCC)(v7->ITraits.pObject);
  ThunkFunction = Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(v9[17], &resulta, VThunk);
  Scaleform::GFx::AS3::Value::Pick(result, ThunkFunction->pV);
}

// File Line: 494
// RVA: 0x780ED0
void __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(
        Scaleform::GFx::AS3::ClassTraits::fl::Object *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
}

// File Line: 501
// RVA: 0x753520
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Object::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::ObjectCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::ObjectCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Object::`vftable;
  }
  return result;
}

