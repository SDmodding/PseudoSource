// File Line: 42
// RVA: 0x1596FB0
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 61
// RVA: 0x731290
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::AS3toString(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(
      result,
      (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[5i64 - _this->value.VS._1.VBool]);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 73
// RVA: 0x7A9170
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::AS3valueOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1004, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 85
// RVA: 0x732320
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Object *VObj; // r14

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_6;
  pObject = vm->TraitsBoolean.pObject->ITraits.pObject;
  VObj = _this->value.VS._1.VObj;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[5]);
  else
LABEL_6:
    Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::AS3toString(ti, vm, _this, result);
}

// File Line: 95
// RVA: 0x732900
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::valueOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_6;
  VObj = _this->value.VS._1.VObj;
  pObject = vm->TraitsBoolean.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
  {
    Scaleform::GFx::AS3::Value::SetBool(result, 0);
  }
  else
  {
LABEL_6:
    if ( (_this->Flags & 0x1F) == 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(result, _this);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v12.Message.pNode;
      if ( v12.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 131
// RVA: 0x7F3F30
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl::Boolean::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Boolean *this,
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
  int v12; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v15; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v16; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+58h] [rbp-18h]
  __int64 v18; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v5 = Scaleform::GFx::AS3::Classes::fl::Boolean::ti;
  v6 = 2i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v5++);
    --v6;
  }
  while ( v6 );
  v15 = 13;
  v16 = 0i64;
  v17 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         "constructor");
  v12 = 1;
  pNode = v7->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v12;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v15;
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
  if ( (v15 & 0x1Fu) > 9 )
  {
    if ( (v15 & 0x200) != 0 )
    {
      v9 = (*v16)-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v16 = 0i64;
      v17 = 0i64;
      v18 = 0i64;
      v15 &= 0xFFFFFDE0;
    }
    else if ( (v15 & 0x1F) == 10 )
    {
      v11 = v17;
      v9 = v17->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
  }
}

// File Line: 147
// RVA: 0x7B87F0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Boolean::Construct(
        Scaleform::GFx::AS3::Classes::fl::Boolean *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  bool v5; // al

  if ( argc )
  {
    v5 = Scaleform::GFx::AS3::Value::Convert2Boolean(argv);
    Scaleform::GFx::AS3::Value::SetBool(result, v5);
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetBool(result, 0);
  }
}

// File Line: 171
// RVA: 0x734030
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Boolean::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::BooleanCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Boolean::`vftable;
    v6->TraitsType = Traits_Boolean;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::BooleanCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Boolean::`vftable;
    v8.pV->TraitsType = Traits_Boolean;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Boolean::`vftable;
  }
  return result;
}

// File Line: 185
// RVA: 0x7B6880
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Boolean::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::Boolean *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  bool v4; // al

  v4 = Scaleform::GFx::AS3::Value::Convert2Boolean(value);
  Scaleform::GFx::AS3::Value::SetBool(result, v4);
  return 1;
}

