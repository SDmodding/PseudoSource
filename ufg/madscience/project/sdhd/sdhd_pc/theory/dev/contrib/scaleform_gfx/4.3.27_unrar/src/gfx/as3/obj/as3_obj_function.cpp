// File Line: 36
// RVA: 0x7FBA90
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeInstance(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        unsigned int method_ind,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos)
{
  Scaleform::GFx::AS3::InstanceTraits::Function *FunctionInstanceTraits; // rdi
  Scaleform::GFx::AS3::Instances::Function *v8; // rax
  int v10; // [rsp+58h] [rbp+10h] BYREF

  FunctionInstanceTraits = Scaleform::GFx::AS3::VMAbcFile::GetFunctionInstanceTraits(file, gos, method_ind);
  v10 = 337;
  v8 = (Scaleform::GFx::AS3::Instances::Function *)FunctionInstanceTraits->pVM->MHeap->vfptr->Alloc(
                                                     FunctionInstanceTraits->pVM->MHeap,
                                                     FunctionInstanceTraits->MemSize,
                                                     (Scaleform::AllocInfo *)&v10);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::Function::Function(v8, FunctionInstanceTraits, ss);
  result->pV = v8;
  return result;
}

// File Line: 52
// RVA: 0x8007A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *result,
        Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // rsi
  Scaleform::GFx::AS3::Instances::FunctionBase *v6; // rax
  Scaleform::GFx::AS3::Instances::ThunkFunction *v7; // rbx
  int v9; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::FunctionBase *v10; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::FunctionBase *v11; // [rsp+68h] [rbp+20h]

  pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].pNext;
  v9 = 337;
  v6 = (Scaleform::GFx::AS3::Instances::FunctionBase *)pNext->pVM->MHeap->vfptr->Alloc(
                                                         pNext->pVM->MHeap,
                                                         pNext->MemSize,
                                                         (Scaleform::AllocInfo *)&v9);
  v7 = (Scaleform::GFx::AS3::Instances::ThunkFunction *)v6;
  v10 = v6;
  v11 = v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v6, pNext);
    v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable;
    v7->Thunk = thunk;
  }
  else
  {
    v7 = 0i64;
  }
  result->pV = v7;
  return result;
}

// File Line: 63
// RVA: 0x7FA530
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *result,
        Scaleform::GFx::AS3::Class *data_type,
        Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pNext; // r14
  Scaleform::GFx::AS3::Instances::FunctionBase *v9; // rax
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v10; // rbx

  pObject = this->pTraits.pObject;
  pNext = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject[1].pNext;
  v9 = (Scaleform::GFx::AS3::Instances::FunctionBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))pObject->pVM->MHeap->vfptr->Alloc)(
                                                         pObject->pVM->MHeap,
                                                         80i64);
  v10 = (Scaleform::GFx::AS3::Instances::CheckTypeTF *)v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v9, pNext);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable;
    v10->Thunk = thunk;
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::CheckTypeTF::`vftable;
    v10->DataTypeClass = data_type;
  }
  else
  {
    v10 = 0i64;
  }
  result->pV = v10;
  return result;
}

// File Line: 79
// RVA: 0x800690
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakePrototype(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> resulta; // [rsp+30h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::Function::MakeInstance(
         (Scaleform::GFx::AS3::InstanceTraits::Function *)this->pTraits.pObject[1].vfptr,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = result;
  result->pV = pV;
  return v4;
}

// File Line: 85
// RVA: 0x7F4340
void __fastcall Scaleform::GFx::AS3::Classes::Function::InitPrototype(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::GFx::AS3::Object *obj)
{
  __int64 v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // r14
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v9; // rbx
  __int64 v10; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int Size; // eax
  int v18; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v21; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v22; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+58h] [rbp-18h]
  __int64 v24; // [rsp+60h] [rbp-10h]
  _QWORD vars0[3]; // [rsp+70h] [rbp+0h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h] BYREF
  __int64 v27; // [rsp+98h] [rbp+28h]
  __int64 v28; // [rsp+A0h] [rbp+30h]

  vars0[2] = vars0;
  vars0[1] = v3;
  vars0[0] = v5;
  v27 = v2;
  v28 = v4;
  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v9 = Scaleform::GFx::AS3::Classes::Function::f;
  v10 = 4i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v9++);
    --v10;
  }
  while ( v10 );
  v21 = 13;
  v22 = 0i64;
  v23 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          this->pTraits.pObject->pVM->StringManagerRef,
          &result,
          "constructor");
  v18 = 1;
  pNode = v11->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v18;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v21;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v12 = pNode;
  v13 = pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v14 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (v21 & 0x1Fu) > 9 )
  {
    if ( (v21 & 0x200) != 0 )
    {
      v13 = (*v22)-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v22 = 0i64;
      v23 = 0i64;
      v24 = 0i64;
      v21 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v21 & 0x1F )
      {
        case 0xA:
          v15 = v23;
          v13 = v23->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
          break;
        case 0xB:
        case 0xC:
          v16 = v23;
          if ( ((unsigned __int8)v23 & 1) != 0 )
          {
            v23 = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
          }
          else if ( v23 )
          {
            Size = v23->Size;
            if ( (Size & 0x3FFFFF) != 0 )
            {
              v23->Size = Size - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v16);
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 104
// RVA: 0x7B8920
void __fastcall Scaleform::GFx::AS3::Classes::Function::Construct(
        Scaleform::GFx::AS3::Classes::Function *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+38h] [rbp-20h] BYREF

  if ( argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1066, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::EvalErrorTI);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct(this, _this, 0, argv, extCall);
  }
}

// File Line: 132
// RVA: 0x77D840
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable;
  this->Prototype.pObject = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)this->Prototype.pObject;
  pV = result.pV;
  if ( result.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->Prototype.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->Prototype.pObject = pV;
  }
}

// File Line: 137
// RVA: 0x78ACF0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::~FunctionBase(
        Scaleform::GFx::AS3::Instances::FunctionBase *this)
{
  Scaleform::GFx::AS3::Object *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable;
  pObject = this->Prototype.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 141
// RVA: 0x75A560
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned __int64 v6; // r8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::LongFormatter v11; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+B0h] [rbp+18h] BYREF

  if ( (_this->Flags & 0x1F) == 5 )
  {
    Scaleform::LongFormatter::LongFormatter(&v11, _this->value.VS._1.VUInt);
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
      vm->StringManagerRef,
      &resulta,
      "[object Function-");
    *((_DWORD *)&v11 + 12) = *((_DWORD *)&v11 + 12) & 0xFFFFFFE0 | 0x10;
    ((void (__fastcall *)(Scaleform::LongFormatter *))v11.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v11);
    v6 = -1i64;
    do
      ++v6;
    while ( v11.ValueStr[v6] );
    Scaleform::GFx::ASString::Append(&resulta, v11.ValueStr, v6);
    Scaleform::GFx::ASString::Append(&resulta, "]", 1ui64);
    Scaleform::GFx::AS3::Value::Assign(result, &resulta);
    pNode = resulta.pNode;
    v8 = resulta.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v11.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v11);
  }
  else
  {
    v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           vm->StringManagerRef,
           &resulta,
           "function Function() {}");
    Scaleform::GFx::AS3::Value::Assign(result, v9);
    v10 = resulta.pNode;
    v8 = resulta.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 194
// RVA: 0x7B29E0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::Call(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  Scaleform::GFx::AS3::Value::V2U v10; // r8
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::Value::Extra v12; // rax
  Scaleform::GFx::AS3::Value::V1U v13; // rdx
  Scaleform::GFx::AS3::Value::V2U v14; // r8
  Scaleform::GFx::AS3::Value v16; // [rsp+38h] [rbp-28h] BYREF

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v16.Flags = v.Flags;
  v16.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v10.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v9 = v.value.VS._1;
  v16.value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( (v.Flags & 0x1F) == 10 )
    {
      ++v.value.VS._1.VStr->RefCount;
    }
    else if ( (v.Flags & 0x1F) > 0xA )
    {
      if ( (v.Flags & 0x1F) <= 0xF )
      {
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v9.VStr->Size &= 0x8FBFFFFF;
        }
      }
      else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v10.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::FunctionBase *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const))this->vfptr[6].Finalize_GC)(
    this,
    _this,
    &v16,
    argc,
    argv);
  Flags = result->Flags;
  v12.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)result->Bonus;
  v13 = result->value.VS._1;
  v14.VObj = (Scaleform::GFx::AS3::Object *)result->value.VS._2;
  result->Flags = v16.Flags;
  result->Bonus.pWeakProxy = v16.Bonus.pWeakProxy;
  result->value = v16.value;
  v16.Flags = Flags;
  v16.Bonus = v12;
  v16.value.VS._1 = v13;
  v16.value.VS._2 = v14;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      if ( v16.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v16.Bonus, 0, 24);
      v16.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
    }
  }
}

// File Line: 201
// RVA: 0x75D170
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::apply(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::Value::V1U v8; // rdx
  Scaleform::GFx::AS3::Value::V2U v9; // r9
  unsigned int pData; // edi
  Scaleform::GFx::AS3::Value *Data; // rbx
  int v12; // edx
  Scaleform::GFx::AS3::Impl::SparseArray *v13; // r14
  Scaleform::MemoryHeap *MHeap; // rax
  __int64 v15; // rsi
  Scaleform::GFx::AS3::Value *v16; // rax
  bool v17; // zf
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value *v20; // r8
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::Extra v22; // rax
  Scaleform::GFx::AS3::Value::VU value; // kr10_16
  Scaleform::GFx::AS3::Value resulta; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value v25; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> v26; // [rsp+58h] [rbp-19h] BYREF
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v27; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v28; // [rsp+80h] [rbp+Fh] BYREF
  __int64 v29; // [rsp+90h] [rbp+1Fh]
  Scaleform::GFx::AS3::Value *vars0; // [rsp+E0h] [rbp+6Fh]
  void *retaddr; // [rsp+E8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *_thisa; // [rsp+F0h] [rbp+7Fh]

  v29 = -2i64;
  v7 = _S11_12;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    v7 = _S11_12;
  }
  resulta.Flags = v.Flags;
  resulta.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v9.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v8 = v.value.VS._1;
  resulta.value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( (v.Flags & 0x1F) == 10 )
    {
      ++v.value.VS._1.VStr->RefCount;
    }
    else if ( (v.Flags & 0x1F) > 0xA )
    {
      if ( (v.Flags & 0x1F) <= 0xF )
      {
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v8.VStr->Size &= 0x8FBFFFFF;
        }
      }
      else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v9.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  if ( !(_DWORD)retaddr )
  {
    if ( (v7 & 1) == 0 )
    {
      _S11_12 = v7 | 1;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    LOBYTE(resulta.value.VS._2.VObj) = 0;
    resulta.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)_thisa;
    v20 = &v;
    goto LABEL_46;
  }
  if ( (_DWORD)retaddr == 1 )
  {
    LOBYTE(resulta.value.VS._2.VObj) = 0;
    resulta.value.VS._1.VStr = 0i64;
    v20 = _thisa;
LABEL_46:
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      vm,
      _this,
      v20,
      &resulta,
      0,
      (Scaleform::GFx::AS3::Value *)resulta.value.VS._1.VStr,
      (bool)resulta.value.VS._2.VObj);
LABEL_47:
    Flags = resulta.Flags;
    v22.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)resulta.Bonus;
    value = resulta.value;
    resulta.Flags = result->Flags;
    resulta.Bonus.pWeakProxy = result->Bonus.pWeakProxy;
    resulta.value = result->value;
    result->Flags = Flags;
    result->Bonus = v22;
    result->value = value;
    goto LABEL_48;
  }
  v25.Flags = 0;
  v25.Bonus.pWeakProxy = 0i64;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::fl::Array *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))vm->TraitsArray.pObject->vfptr[3].Finalize_GC)(
         vm->TraitsArray.pObject,
         &_thisa[1],
         &v25) )
  {
    pData = 0;
    Data = 0i64;
    v12 = v25.Flags & 0x1F;
    if ( (unsigned int)(v12 - 12) > 3 && v12 != 10 || v25.value.VS._1.VStr )
    {
      v13 = (Scaleform::GFx::AS3::Impl::SparseArray *)&v25.value.VS._1.VStr[1].16;
      if ( v25.value.VS._1.VStr[1].pLower <= (Scaleform::GFx::ASStringNode *)v25.value.VS._1.VStr[3].pData )
      {
        pData = (unsigned int)v25.value.VS._1.VStr[3].pData;
        Data = *(Scaleform::GFx::AS3::Value **)&v25.value.VS._1.VStr[2].Size;
      }
      else
      {
        MHeap = vm->MHeap;
        v27 = &v26;
        memset(&v26, 0, 24);
        v26.pHeap = MHeap;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &v26,
          v13->Length);
        pData = v26.Size;
        if ( v26.Size )
        {
          v15 = 0i64;
          do
          {
            v16 = Scaleform::GFx::AS3::Impl::SparseArray::At(v13, (unsigned __int64)Data);
            Scaleform::GFx::AS3::Value::Assign(&v26.Data[v15], v16);
            Data = (Scaleform::GFx::AS3::Value *)((char *)Data + 1);
            ++v15;
            pData = v26.Size;
          }
          while ( (unsigned __int64)Data < v26.Size );
          result = vars0;
        }
        Data = v26.Data;
        v27 = &v26;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v26.Data, v26.Size);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v26.Data);
      }
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, _thisa, &resulta, pData, Data, 0);
    if ( (v25.Flags & 0x1F) > 9 )
    {
      if ( (v25.Flags & 0x200) != 0 )
      {
        v17 = v25.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v25.Bonus, 0, 24);
        v25.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
      }
    }
    goto LABEL_47;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v28, eApplyError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v28.Message.pNode;
  v17 = v28.Message.pNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (v25.Flags & 0x1F) > 9 )
  {
    if ( (v25.Flags & 0x200) != 0 )
    {
      v17 = v25.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v25.Bonus, 0, 24);
      v25.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
    }
  }
LABEL_48:
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags & 0x200) != 0 )
    {
      v17 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      resulta.Flags &= 0xFFFFFDE0;
      memset(&resulta.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
}

// File Line: 277
// RVA: 0x7B89A0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::Construct(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool __formal)
{
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Value::Pick(result, resulta.pV);
  vfptr = this->vfptr;
  __formal = 1;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::FunctionBase *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))vfptr[7].ForEachChild_GC)(
    this,
    result,
    argc,
    argv);
}

// File Line: 292
// RVA: 0x851630
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::lengthGet(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        unsigned int *result)
{
  *result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::FunctionBase *))this->vfptr[7].~RefCountBaseGC<328>)(this);
}

// File Line: 297
// RVA: 0x75C830
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::call(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::V1U v7; // rcx
  Scaleform::GFx::AS3::Value::V2U v8; // r8
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // rcx
  unsigned int Flags; // edx
  int v13; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r8
  Scaleform::GFx::AS3::Value::V2U v15; // rax
  Scaleform::GFx::AS3::Value::V1U v16; // rcx
  Scaleform::GFx::AS3::Value *p_thisa; // r8
  char v18; // bl
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // rax
  unsigned int v20; // edx
  Scaleform::GFx::AS3::Value::Extra v21; // rax
  Scaleform::GFx::AS3::Value::VU value; // kr10_16
  Scaleform::GFx::AS3::Value resulta; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value v25; // [rsp+68h] [rbp+7h] BYREF
  void *retaddr; // [rsp+D8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v27; // [rsp+E0h] [rbp+7Fh]

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  resulta.Flags = v.Flags;
  resulta.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v8.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v7 = v.value.VS._1;
  resulta.value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( (v.Flags & 0x1F) == 10 )
    {
      ++v.value.VS._1.VStr->RefCount;
    }
    else if ( (v.Flags & 0x1F) > 0xA )
    {
      if ( (v.Flags & 0x1F) <= 0xF )
      {
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v7.VStr->Size &= 0x8FBFFFFF;
        }
      }
      else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v8.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  if ( (_DWORD)retaddr )
  {
    Flags = v27->Flags;
    v13 = v27->Flags & 0x1F;
    if ( v13 && ((unsigned int)(v13 - 12) > 3 && v13 != 10 || v27->value.VS._1.VStr) )
    {
      _thisa.Flags = v27->Flags;
      pWeakProxy = v27->Bonus.pWeakProxy;
      _thisa.Bonus.pWeakProxy = pWeakProxy;
      _thisa.value.VS._1.VStr = v27->value.VS._1.VStr;
      v15.VObj = (Scaleform::GFx::AS3::Object *)v27->value.VS._2;
      _thisa.value.VS._2 = v15;
      if ( v13 > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          ++pWeakProxy->RefCount;
        }
        else if ( v13 == 10 )
        {
          ++v27->value.VS._1.VStr->RefCount;
        }
        else if ( v13 <= 15 )
        {
          v16 = v27->value.VS._1;
          if ( v16.VStr )
            v16.VStr->Size = (v16.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v13 <= 17 && v15.VObj )
        {
          v15.VObj->RefCount = (v15.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
      p_thisa = &_thisa;
      v18 = 2;
    }
    else
    {
      GlobalObject = Scaleform::GFx::AS3::VM::GetGlobalObject(vm);
      v25.Flags = 12;
      v25.Bonus.pWeakProxy = 0i64;
      v25.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)GlobalObject;
      if ( GlobalObject )
        GlobalObject->RefCount = (GlobalObject->RefCount + 1) & 0x8FBFFFFF;
      p_thisa = &v25;
      v18 = 1;
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, p_thisa, &resulta, (_DWORD)retaddr - 1, v27 + 1, 0);
    if ( (v18 & 2) != 0 )
    {
      v18 &= ~2u;
      if ( (_thisa.Flags & 0x1F) > 9 )
      {
        if ( (_thisa.Flags & 0x200) != 0 )
        {
          v10 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&_thisa.Bonus, 0, 24);
          _thisa.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_thisa);
        }
      }
    }
    if ( (v18 & 1) != 0 && (v25.Flags & 0x1F) > 9 )
    {
      if ( (v25.Flags & 0x200) == 0 )
      {
        v11 = &v25;
        goto LABEL_57;
      }
      v10 = v25.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v25.Bonus, 0, 24);
      v25.Flags &= 0xFFFFFDE0;
    }
  }
  else
  {
    v9 = Scaleform::GFx::AS3::VM::GetGlobalObject(vm);
    _thisa.Flags = 12;
    _thisa.Bonus.pWeakProxy = 0i64;
    _thisa.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, _this, &_thisa, &resulta, (unsigned int)retaddr, v27, 0);
    if ( (_thisa.Flags & 0x1F) > 9 )
    {
      if ( (_thisa.Flags & 0x200) != 0 )
      {
        v10 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&_thisa.Bonus, 0, 24);
        _thisa.Flags &= 0xFFFFFDE0;
        goto LABEL_58;
      }
      v11 = &_thisa;
LABEL_57:
      Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
    }
  }
LABEL_58:
  v20 = resulta.Flags;
  v21.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)resulta.Bonus;
  value = resulta.value;
  resulta.Flags = result->Flags;
  resulta.Bonus.pWeakProxy = result->Bonus.pWeakProxy;
  resulta.value = result->value;
  result->Flags = v20;
  result->Bonus = v21;
  result->value = value;
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
}

// File Line: 326
// RVA: 0x8165A0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(
        Scaleform::GFx::AS3::Instances::FunctionBase *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value *pCurrent; // rcx

  pVM = this->pTraits.pObject->pVM;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
    {
      pWeakProxy = result->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result->Flags &= 0xFFFFFDE0;
      result->Bonus.pWeakProxy = 0i64;
      result->value.VS._1.VStr = 0i64;
      result->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
  }
  pCurrent = pVM->OpStack.pCurrent;
  result->Flags = pCurrent->Flags;
  result->Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
  result->value.VS._1.VStr = pCurrent->value.VS._1.VStr;
  result->value.VS._2.VObj = pCurrent->value.VS._2.VObj;
  --pVM->OpStack.pCurrent;
}

// File Line: 372
// RVA: 0x77D6C0
void __fastcall Scaleform::GFx::AS3::Instances::Function::Function(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::InstanceTraits::Function *tr,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::GFx::AS3::VM *pVM; // rbp
  unsigned __int64 Size; // rsi
  unsigned __int64 ScopeStackBaseInd; // rax
  __int64 v8; // rdi
  unsigned __int64 i; // rsi
  Scaleform::GFx::AS3::Value *v10; // rbx
  Scaleform::GFx::AS3::Value *v11; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(this, tr);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::Function::`vftable;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
    &this->StoredScopeStack.Data,
    &ss->Data);
  pVM = this->pTraits.pObject->pVM;
  Size = pVM->ScopeStack.Data.Size;
  if ( pVM->CallStack.Size )
    ScopeStackBaseInd = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0i64;
  if ( ScopeStackBaseInd < Size )
  {
    v8 = ScopeStackBaseInd;
    for ( i = Size - ScopeStackBaseInd; i; --i )
    {
      v10 = &pVM->ScopeStack.Data.Data[v8];
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->StoredScopeStack.Data,
        this->StoredScopeStack.Data.pHeap,
        this->StoredScopeStack.Data.Size + 1);
      v11 = &this->StoredScopeStack.Data.Data[this->StoredScopeStack.Data.Size - 1];
      if ( !v11 )
        goto LABEL_19;
      v11->Flags = v10->Flags;
      v11->Bonus.pWeakProxy = v10->Bonus.pWeakProxy;
      v11->value.VS._1.VStr = v10->value.VS._1.VStr;
      v11->value.VS._2.VObj = v10->value.VS._2.VObj;
      if ( (v10->Flags & 0x1F) <= 9 )
        goto LABEL_19;
      if ( (v10->Flags & 0x200) != 0 )
      {
        ++v10->Bonus.pWeakProxy->RefCount;
      }
      else if ( (v10->Flags & 0x1F) == 10 )
      {
        ++v10->value.VS._1.VStr->RefCount;
      }
      else if ( (v10->Flags & 0x1F) > 0xA )
      {
        if ( (v10->Flags & 0x1F) <= 0xF )
        {
          VObj = v10->value.VS._1;
LABEL_16:
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
          goto LABEL_19;
        }
        if ( (v10->Flags & 0x1F) <= 0x11 )
        {
          VObj = (Scaleform::GFx::AS3::Value::V1U)v10->value.VS._2.VObj;
          goto LABEL_16;
        }
      }
LABEL_19:
      ++v8;
    }
  }
}

// File Line: 389
// RVA: 0x7CA110
void __fastcall Scaleform::GFx::AS3::Instances::Function::Execute(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  Scaleform::GFx::AS3::Traits *pObject; // rdx
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned int v11; // ecx
  __int64 v12; // rbx
  Scaleform::GFx::AS3::Traits *v13; // r8
  Scaleform::GFx::AS3::VMAbcFile *Parent; // r15
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v17; // zf
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::ValueStack *p_OpStack; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **p_DefXMLNamespace; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v24; // rdi
  Scaleform::GFx::AS3::CallFrame **Pages; // rax
  __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-B1h] BYREF
  Scaleform::GFx::AS3::Value v29; // [rsp+C0h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::VM::Error v30; // [rsp+E0h] [rbp-1h] BYREF
  __int64 v31; // [rsp+F0h] [rbp+Fh]
  Scaleform::GFx::AS3::CallFrame *v32; // [rsp+140h] [rbp+5Fh] BYREF
  Scaleform::GFx::AS3::CallFrame *v33; // [rsp+148h] [rbp+67h]

  v31 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  v11 = _this->Flags & 0x1F;
  if ( (!v11 || (v11 - 12 <= 3 || v11 == 10) && !_this->value.VS._1.VStr) && pObject->InitScope.Data.Size )
    _this = pObject->InitScope.Data.Data;
  v12 = *(int *)(*(_QWORD *)(pObject[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                           + 8i64 * SLODWORD(pObject[1].FirstOwnSlotNum))
               + 8i64);
  v13 = (Scaleform::GFx::AS3::Traits *)pObject[1].VArray.Data.Data->Value.File.pObject;
  v29.Flags = 14;
  v29.Bonus.pWeakProxy = 0i64;
  v29.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  Parent = (Scaleform::GFx::AS3::VMAbcFile *)pObject[1].Parent;
  if ( pVM->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v30, 1023, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v15, &Scaleform::GFx::AS3::fl::ErrorTI);
    pNode = v30.Message.pNode;
    v17 = v30.Message.pNode->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    other.DiscardResult = discard_result;
    other.ACopy = 0;
    VMRef = Parent->VMRef;
    other.ScopeStackBaseInd = VMRef->ScopeStack.Data.Size;
    other.CP = 0i64;
    other.pRegisterFile = &VMRef->RegisterFile;
    other.pHeap = VMRef->MHeap;
    other.pFile = Parent;
    other.MBIIndex.Ind = v12;
    other.pSavedScope = &this->StoredScopeStack;
    other.OriginationTraits = v13;
    other.pScopeStack = &VMRef->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = 14;
    other.Invoker.Bonus.pWeakProxy = 0i64;
    other.Invoker.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
    other.Invoker.value.VS._2.VObj = v29.value.VS._2.VObj;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    p_OpStack = &Parent->VMRef->OpStack;
    other.PrevInitialStackPos = p_OpStack->pCurrent;
    other.PrevFirstStackPos = p_OpStack->pStack;
    v20 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(p_OpStack, v20->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v20->local_reg_count);
    p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *p_DefXMLNamespace )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *p_DefXMLNamespace);
      v32 = 0i64;
      if ( &v32 != (Scaleform::GFx::AS3::CallFrame **)p_DefXMLNamespace )
      {
        v22 = *p_DefXMLNamespace;
        if ( *p_DefXMLNamespace )
        {
          if ( ((unsigned __int8)v22 & 1) != 0 )
          {
            *p_DefXMLNamespace = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v22 - 1);
          }
          else
          {
            RefCount = v22->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v22->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
            }
          }
        }
        *p_DefXMLNamespace = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      Parent->File.pObject->Methods.Info.Data.Data[Parent->File.pObject->MethodBodies.Info.Data.Data[v12]->method_info_ind],
      _this,
      argc,
      argv);
    if ( pVM->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v24 = pVM->CallStack.Size >> 6;
      if ( v24 >= pVM->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          &pVM->CallStack,
          pVM->CallStack.Size >> 6);
      Pages = pVM->CallStack.Pages;
      v26 = pVM->CallStack.Size & 0x3F;
      v17 = &Pages[v24][v26] == 0i64;
      v27 = &Pages[v24][v26];
      v32 = v27;
      v33 = v27;
      if ( !v17 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
      ++pVM->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
}

// File Line: 415
// RVA: 0x7D0D70
void __fastcall Scaleform::GFx::AS3::Instances::Function::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int RefCount; // eax
  char v8; // [rsp+20h] [rbp-28h]

  v8 = 0;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::Function *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, char))this->vfptr[7].ForEachChild_GC)(
    this,
    _this,
    argc,
    argv,
    v8);
  if ( !this->pTraits.pObject->pVM->HandleException )
  {
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteCode(this->pTraits.pObject->pVM, 1u);
    if ( !this->pTraits.pObject->pVM->HandleException )
      Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(this, result);
    if ( ((unsigned __int8)this & 1) == 0 )
    {
      RefCount = this->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        this->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(this);
      }
    }
  }
}

// File Line: 439
// RVA: 0x7EBCA0
__int64 __fastcall Scaleform::GFx::AS3::Instances::Function::GetMaxParamNum(
        Scaleform::GFx::AS3::Instances::Function *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // r8

  pObject = this->pTraits.pObject;
  return *(unsigned int *)(*(_QWORD *)(pObject[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                                     + 8i64
                                     * *(int *)(*(&pObject[1].Parent[3].Parent[7].Parent->FirstOwnSlotNum
                                                + *(int *)(*(_QWORD *)(pObject[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                                                                     + 8i64 * SLODWORD(pObject[1].FirstOwnSlotNum))
                                                         + 8i64))
                                              + 24))
                         + 24i64);
}

// File Line: 447
// RVA: 0x7D59B0
void __fastcall Scaleform::GFx::AS3::Instances::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->StoredScopeStack, op);
}

// File Line: 464
// RVA: 0x7D0E30
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkInfo *Thunk; // rax
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value v8; // [rsp+48h] [rbp-30h] BYREF

  Thunk = this->Thunk;
  v8.Flags = 5;
  v8.Bonus.pWeakProxy = 0i64;
  v8.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)Thunk;
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, &v8, _this, result, argc, argv, 0);
  Flags = v8.Flags;
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags & 0x200) != 0 )
    {
      if ( v8.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v8.Bonus, 0, 24);
      v8.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
    }
  }
}

// File Line: 470
// RVA: 0x7CA740
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkInfo *Thunk; // rax
  Scaleform::GFx::AS3::VM *pVM; // r14
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  Scaleform::GFx::AS3::Value::V2U v10; // r8
  bool v11; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+30h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+50h] [rbp+17h] BYREF
  char v14; // [rsp+B8h] [rbp+7Fh]

  Thunk = this->Thunk;
  func.Flags = 5;
  func.Bonus.pWeakProxy = 0i64;
  func.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)Thunk;
  pVM = this->pTraits.pObject->pVM;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  result.Flags = v.Flags;
  result.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v10.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v9 = v.value.VS._1;
  result.value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( (v.Flags & 0x1F) == 10 )
    {
      ++v.value.VS._1.VStr->RefCount;
    }
    else if ( (v.Flags & 0x1F) > 0xA )
    {
      if ( (v.Flags & 0x1F) <= 0xF )
      {
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v9.VStr->Size &= 0x8FBFFFFF;
        }
      }
      else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v10.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pVM, &func, _this, &result, argc, argv, v14 == 0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v11 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
    {
      v11 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
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

// File Line: 476
// RVA: 0x8515B0
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::length(
        Scaleform::GFx::AS3::Instances::ThunkFunction *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned __int64 v4; // rcx
  __int64 v5; // rax

  v4 = *((_QWORD *)this->Thunk + 4);
  v5 = (v4 >> 9) & 0xFFF;
  if ( (_DWORD)v5 == 4095 )
    LODWORD(v5) = (v4 >> 6) & 7;
  Scaleform::GFx::AS3::Value::SetUInt32(result, v5);
}

// File Line: 491
// RVA: 0x7D0C70
void __fastcall Scaleform::GFx::AS3::Instances::CheckTypeTF::ExecuteUnsafe(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+38h] [rbp-30h] BYREF

  pObject = this->DataTypeClass->pTraits.pObject;
  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  v11 = ClassTraits;
  if ( pObject == ClassTraits )
  {
LABEL_8:
    Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(this, _this, result, argc, argv);
    return;
  }
  if ( ClassTraits )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v11->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v11->ITraits.pObject,
               pObject[1].vfptr) )
    {
      v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject;
      if ( v11 == pObject )
        break;
      if ( !v11 )
        goto LABEL_6;
    }
    goto LABEL_8;
  }
LABEL_6:
  Scaleform::GFx::AS3::VM::Error::Error(&v15, 1034, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v15.Message.pNode;
  if ( v15.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 511
// RVA: 0x7CA010
void __fastcall Scaleform::GFx::AS3::Instances::CheckTypeTF::Execute(
        Scaleform::GFx::AS3::Instances::CheckTypeTF *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  Scaleform::GFx::AS3::Traits *pObject; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+38h] [rbp-30h] BYREF

  pObject = this->DataTypeClass->pTraits.pObject;
  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  v11 = ClassTraits;
  if ( pObject == ClassTraits )
  {
LABEL_8:
    Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(this, _this, argc, argv, discard_result);
    return;
  }
  if ( ClassTraits )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v11->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v11->ITraits.pObject,
               pObject[1].vfptr) )
    {
      v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject;
      if ( v11 == pObject )
        break;
      if ( !v11 )
        goto LABEL_6;
    }
    goto LABEL_8;
  }
LABEL_6:
  Scaleform::GFx::AS3::VM::Error::Error(&v15, 1034, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v15.Message.pNode;
  if ( v15.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 537
// RVA: 0x1595E60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::ThunkFunction_534_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B5B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::ThunkFunction,534,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = Scaleform::GFx::AS3::Instances::ThunkFunction::length;
  return result;
}

// File Line: 538
// RVA: 0x1589F80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::FunctionBase_535_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B5C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::FunctionBase,535,unsigned long>::Method = Scaleform::GFx::AS3::Instances::FunctionBase::lengthGet;
  return result;
}

// File Line: 545
// RVA: 0x782780
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(
        Scaleform::GFx::AS3::InstanceTraits::Thunk *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  __int64 v4; // rdi

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Thunk::`vftable;
  this->TraitsType = Traits_Function;
  v3 = Scaleform::GFx::AS3::InstanceTraits::Thunk::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v3++);
    --v4;
  }
  while ( v4 );
}

// File Line: 566
// RVA: 0x851720
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Thunk::lengthGet(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  __int64 v4; // rax

  v4 = (*(_QWORD *)&_this->value.VS._1.VStr->Size >> 9) & 0xFFFi64;
  if ( (_DWORD)v4 == 4095 )
    v4 = (*(_QWORD *)&_this->value.VS._1.VStr->Size >> 6) & 7i64;
  Scaleform::GFx::AS3::Value::SetUInt32(result, v4);
}

// File Line: 589
// RVA: 0x1596DC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::Thunk::f__()
{
  __int64 result; // rax

  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1] + 4) = 4193792i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[0].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::InstanceTraits::Thunk::lengthGet;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::FunctionBase::call;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2].ArgType = &Scaleform::GFx::AS3::InstanceTraits::Thunk::tit[4];
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1].ArgType = &Scaleform::GFx::AS3::InstanceTraits::Thunk::tit[3];
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2].Name = "length";
  result = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2].NamespaceName = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[1].Name = "call";
  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2] + 4) = 16i64;
  Scaleform::GFx::AS3::InstanceTraits::Thunk::f[2].DefArgValue = 0i64;
  return result;
}

// File Line: 597
// RVA: 0x77FA20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::MethodInd(
        Scaleform::GFx::AS3::InstanceTraits::MethodInd *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  __int64 v4; // rdi

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::MethodInd::`vftable;
  this->TraitsType = Traits_Function;
  v3 = Scaleform::GFx::AS3::InstanceTraits::MethodInd::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v3++);
    --v4;
  }
  while ( v4 );
}

// File Line: 607
// RVA: 0x7EC390
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(
        Scaleform::GFx::AS3::InstanceTraits::Thunk *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *_this)
{
  unsigned __int64 v5; // r8
  Scaleform::LongFormatter v7; // [rsp+30h] [rbp-68h] BYREF

  Scaleform::LongFormatter::LongFormatter(&v7, _this->value.VS._1.VUInt);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->pVM->StringManagerRef,
    result,
    "Function-");
  *((_DWORD *)&v7 + 12) = *((_DWORD *)&v7 + 12) & 0xFFFFFFE0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v7.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( v7.ValueStr[v5] );
  Scaleform::GFx::ASString::Append(result, v7.ValueStr, v5);
  v7.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  Scaleform::Formatter::~Formatter(&v7);
  return result;
}

// File Line: 618
// RVA: 0x851650
void __fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::lengthGet(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  __int64 VInt; // rbx
  Scaleform::GFx::AS3::Traits *pTraits; // rdi
  __int64 v7; // rax

  VInt = _this->value.VS._1.VInt;
  if ( (_this->Flags & 0x1F) == 6 )
    pTraits = _this->value.VS._2.pTraits;
  else
    pTraits = _this->value.VS._2.VObj->pTraits.pObject;
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::VM *))pTraits->vfptr[2].~RefCountBaseGC<328>)(
         pTraits,
         vm) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pTraits->vfptr[2].~RefCountBaseGC<328>)(pTraits);
    Scaleform::GFx::AS3::Value::SetUInt32(
      result,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 152) + 224i64) + 8 * VInt) + 24i64));
  }
}

// File Line: 646
// RVA: 0x1596D10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::MethodInd::f__()
{
  __int64 result; // rax

  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1] + 4) = 4193792i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[0].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::InstanceTraits::MethodInd::lengthGet;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::FunctionBase::call;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2].ArgType = &Scaleform::GFx::AS3::InstanceTraits::MethodInd::tit[4];
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1].ArgType = &Scaleform::GFx::AS3::InstanceTraits::MethodInd::tit[3];
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2].Name = "length";
  result = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2].NamespaceName = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[1].Name = "call";
  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2] + 4) = 16i64;
  Scaleform::GFx::AS3::InstanceTraits::MethodInd::f[2].DefArgValue = 0i64;
  return result;
}

// File Line: 654
// RVA: 0x784D40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::VTableInd::VTableInd(
        Scaleform::GFx::AS3::InstanceTraits::VTableInd *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  __int64 v4; // rdi

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::VTableInd::`vftable;
  this->TraitsType = Traits_Function;
  v3 = Scaleform::GFx::AS3::InstanceTraits::VTableInd::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v3++);
    --v4;
  }
  while ( v4 );
}

// File Line: 662
// RVA: 0x851750
void __fastcall Scaleform::GFx::AS3::InstanceTraits::VTableInd::lengthGet(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  __int64 VUInt; // rbx
  Scaleform::GFx::AS3::Traits *pTraits; // rdi
  __int64 VInt; // rbx
  __int64 v8; // rax

  if ( (_this->Flags & 0x1F) == 7 )
    pTraits = _this->value.VS._2.pTraits;
  else
    pTraits = _this->value.VS._2.VObj->pTraits.pObject;
  VUInt = _this->value.VS._1.VUInt;
  VInt = Scaleform::GFx::AS3::Traits::GetVT(pTraits)->VTMethods.Data.Data[VUInt].value.VS._1.VInt;
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pTraits->vfptr[2].~RefCountBaseGC<328>)(pTraits) )
  {
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))pTraits->vfptr[2].~RefCountBaseGC<328>)(pTraits);
    Scaleform::GFx::AS3::Value::SetUInt32(
      result,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 152) + 224i64) + 8 * VInt) + 24i64));
  }
}

// File Line: 693
// RVA: 0x1596E70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::VTableInd::f__()
{
  __int64 result; // rax

  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1] + 4) = 4193792i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[0].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::InstanceTraits::VTableInd::lengthGet;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::FunctionBase::call;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2].ArgType = &Scaleform::GFx::AS3::InstanceTraits::VTableInd::tit[4];
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1].ArgType = &Scaleform::GFx::AS3::InstanceTraits::VTableInd::tit[3];
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2].Name = "length";
  result = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2].NamespaceName = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[1].Name = "call";
  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2] + 4) = 16i64;
  Scaleform::GFx::AS3::InstanceTraits::VTableInd::f[2].DefArgValue = 0i64;
  return result;
}

// File Line: 712
// RVA: 0x7F04C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::GetThunkName(
        Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *_this)
{
  unsigned __int64 v5; // r8
  Scaleform::LongFormatter v7; // [rsp+30h] [rbp-68h] BYREF

  Scaleform::LongFormatter::LongFormatter(&v7, _this->value.VS._1.VStr[1].RefCount);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->pVM->StringManagerRef,
    result,
    "Function-");
  *((_DWORD *)&v7 + 12) = *((_DWORD *)&v7 + 12) & 0xFFFFFFE0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v7.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( v7.ValueStr[v5] );
  Scaleform::GFx::ASString::Append(result, v7.ValueStr, v5);
  v7.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  Scaleform::Formatter::~Formatter(&v7);
  return result;
}

// File Line: 747
// RVA: 0x77D5F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::Function(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::ClassInfo *ci,
        int mi,
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos)
{
  Scaleform::GFx::AS3::ClassTraits::Function *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList **v9; // rbx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, file->VMRef, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable;
  this->MethodInfoInd.Ind = mi;
  this->File.pObject = file;
  file->RefCount = (file->RefCount + 1) & 0x8FBFFFFF;
  this->GOS.pObject = gos;
  if ( gos )
    gos->RefCount = (gos->RefCount + 1) & 0x8FBFFFFF;
  pObject = file->VMRef->TraitsFunction.pObject;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)pObject->ITraits.pObject;
  if ( !v9[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v9)->List.Data.Data)(pObject->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    v9[17]);
  this->TraitsType = Traits_Function;
  Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(this);
}

// File Line: 779
// RVA: 0x7D5940
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->File.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->GOS.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
}

// File Line: 787
// RVA: 0x80FEF0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(
        Scaleform::GFx::AS3::InstanceTraits::Function *this)
{
  Scaleform::GFx::ASString *v2; // rax
  Scaleform::GFx::AS3::VM *pVM; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // r9
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v5; // r8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rbx
  __int64 v9; // rdi
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  v2 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pVM->StringManagerRef,
         &result,
         "prototype");
  pVM = this->pVM;
  pObject = pVM->TraitsObject.pObject;
  v5.pV = pVM->PublicNamespace.pObject;
  if ( v5.pV )
    v5.pV->RefCount = (v5.pV->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::AddSlotCPP(
    this,
    v2,
    v5,
    pObject,
    BT_ObjectCpp,
    (Scaleform::GFx::AS3::AbsoluteIndex)56i64,
    0);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = Scaleform::GFx::AS3::InstanceTraits::Function::f;
  v9 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(this, &Scaleform::GFx::AS3::fl::FunctionCI, v8++);
    --v9;
  }
  while ( v9 );
}

// File Line: 803
// RVA: 0x7E9FA0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::Function::GetFunctionName(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *_this)
{
  unsigned __int64 v5; // r8
  Scaleform::LongFormatter v7; // [rsp+30h] [rbp-68h] BYREF

  Scaleform::LongFormatter::LongFormatter(&v7, *((_DWORD *)_this->value.VS._1.VStr[1].pData + 60));
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    this->pVM->StringManagerRef,
    result,
    "Function-");
  *((_DWORD *)&v7 + 12) = *((_DWORD *)&v7 + 12) & 0xFFFFFFE0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v7.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( v7.ValueStr[v5] );
  Scaleform::GFx::ASString::Append(result, v7.ValueStr, v5);
  v7.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  Scaleform::Formatter::~Formatter(&v7);
  return result;
}

// File Line: 816
// RVA: 0x7FF640
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::Function *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::Function::MakeInstance(this, &resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 828
// RVA: 0x1596C60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::Function::f__()
{
  __int64 result; // rax

  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::Function::f[1] + 4) = 4193792i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[1].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[0].DefArgValue = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[2].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::FunctionBase,535,unsigned long>::Func;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[1].Method = (void (__fastcall *)(Scaleform::GFx::AS3::ThunkInfo *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::FunctionBase::call;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[2].ArgType = &Scaleform::GFx::AS3::InstanceTraits::Function::tit[4];
  Scaleform::GFx::AS3::InstanceTraits::Function::f[1].ArgType = &Scaleform::GFx::AS3::InstanceTraits::Function::tit[3];
  Scaleform::GFx::AS3::InstanceTraits::Function::f[2].Name = "length";
  result = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[2].NamespaceName = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[1].Name = "call";
  *((_QWORD *)&Scaleform::GFx::AS3::InstanceTraits::Function::f[2] + 4) = 16i64;
  Scaleform::GFx::AS3::InstanceTraits::Function::f[2].DefArgValue = 0i64;
  return result;
}

// File Line: 883
// RVA: 0x7B1830
void __fastcall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::Function *v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags &= 0xFFFFFFEE;
  this->Flags |= 0xEu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 927
// RVA: 0x807170
void __fastcall Scaleform::GFx::AS3::Value::Pick(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::FunctionBase *v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags &= 0xFFFFFFEE;
  this->Flags |= 0xEu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
}

// File Line: 951
// RVA: 0x8072F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::ThunkFunction *v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->Flags &= ~0x10u;
  this->Flags |= 0xFu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
}

// File Line: 972
// RVA: 0x77D180
void __fastcall Scaleform::GFx::AS3::ClassTraits::Function::Function(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v6; // rbp
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v9; // rbx
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::GFx::AS3::Class *v12; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v13; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v14; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v15; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Thunk *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v18; // rsi
  Scaleform::GFx::AS3::Class *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v21; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v22; // rsi
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v25; // rsi
  Scaleform::GFx::AS3::Class *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v28; // rax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v29; // rax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v30; // rsi
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v31; // rcx
  unsigned int v32; // eax
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v33; // rsi
  Scaleform::GFx::AS3::Class *v34; // rcx
  unsigned int v35; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v36; // rax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v37; // rax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v40; // rsi
  Scaleform::GFx::AS3::Class *v41; // rcx
  unsigned int v42; // eax

  Scaleform::GFx::AS3::ClassTraits::Traits::Traits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Function::`vftable;
  v6 = 0i64;
  this->ThunkTraits.pObject = 0i64;
  this->ThunkFunctionTraits.pObject = 0i64;
  this->MethodIndTraits.pObject = 0i64;
  this->VTableTraits.pObject = 0i64;
  this->TraitsType = Traits_Function;
  MHeap = vm->MHeap;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 264ui64, 0i64);
  v9.pV = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v8, vm, ci);
    v9.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable;
    v9.pV[1].RefCount = 0;
    v9.pV[1].FirstOwnSlotNum = 0i64;
    v9.pV[1].Parent = 0i64;
    v9.pV->TraitsType = Traits_Function;
    Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots((Scaleform::GFx::AS3::InstanceTraits::Function *)v9.pV);
  }
  else
  {
    v9.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(this, v9);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        72i64);
  v12 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, this);
    v12->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::Function::`vftable;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)vm->MHeap->vfptr->Alloc(v11, 240i64, 0i64);
  if ( v13 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(v13, vm);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  pObject = this->ThunkTraits.pObject;
  if ( v15 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->ThunkTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->ThunkTraits.pObject = v15;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v18 = this->ThunkTraits.pObject;
  v19 = v18->pConstructor.pObject;
  if ( v12 != v19 )
  {
    if ( v19 )
    {
      if ( ((unsigned __int8)v19 & 1) != 0 )
      {
        v18->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v19 - 1);
      }
      else
      {
        v20 = v19->RefCount;
        if ( (v20 & 0x3FFFFF) != 0 )
        {
          v19->RefCount = v20 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
        }
      }
    }
    v18->pConstructor.pObject = v12;
  }
  v21 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)vm->MHeap->vfptr->Alloc(v19, 240i64, 0i64);
  v22 = v21;
  if ( v21 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v21, vm, &Scaleform::GFx::AS3::fl::FunctionCIThunk);
    v22->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::`vftable;
    v22->TraitsType = Traits_Function;
    Scaleform::GFx::AS3::Traits::Add2VT(
      v22,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::f);
  }
  else
  {
    v22 = 0i64;
  }
  v23 = this->ThunkFunctionTraits.pObject;
  if ( v22 != v23 )
  {
    if ( v23 )
    {
      if ( ((unsigned __int8)v23 & 1) != 0 )
      {
        this->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)((char *)v23 - 1);
      }
      else
      {
        v24 = v23->RefCount;
        if ( (v24 & 0x3FFFFF) != 0 )
        {
          v23->RefCount = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
        }
      }
    }
    this->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)v22;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v25 = this->ThunkFunctionTraits.pObject;
  v26 = v25->pConstructor.pObject;
  if ( v12 != v26 )
  {
    if ( v26 )
    {
      if ( ((unsigned __int8)v26 & 1) != 0 )
      {
        v25->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v26 - 1);
      }
      else
      {
        v27 = v26->RefCount;
        if ( (v27 & 0x3FFFFF) != 0 )
        {
          v26->RefCount = v27 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
        }
      }
    }
    v25->pConstructor.pObject = v12;
  }
  v28 = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)vm->MHeap->vfptr->Alloc(v26, 240i64, 0i64);
  if ( v28 )
  {
    Scaleform::GFx::AS3::InstanceTraits::MethodInd::MethodInd(v28, vm);
    v30 = v29;
  }
  else
  {
    v30 = 0i64;
  }
  v31 = this->MethodIndTraits.pObject;
  if ( v30 != v31 )
  {
    if ( v31 )
    {
      if ( ((unsigned __int8)v31 & 1) != 0 )
      {
        this->MethodIndTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)((char *)v31 - 1);
      }
      else
      {
        v32 = v31->RefCount;
        if ( (v32 & 0x3FFFFF) != 0 )
        {
          v31->RefCount = v32 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
        }
      }
    }
    this->MethodIndTraits.pObject = v30;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v33 = this->MethodIndTraits.pObject;
  v34 = v33->pConstructor.pObject;
  if ( v12 != v34 )
  {
    if ( v34 )
    {
      if ( ((unsigned __int8)v34 & 1) != 0 )
      {
        v33->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v34 - 1);
      }
      else
      {
        v35 = v34->RefCount;
        if ( (v35 & 0x3FFFFF) != 0 )
        {
          v34->RefCount = v35 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
        }
      }
    }
    v33->pConstructor.pObject = v12;
  }
  v36 = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)vm->MHeap->vfptr->Alloc(v34, 240i64, 0i64);
  if ( v36 )
  {
    Scaleform::GFx::AS3::InstanceTraits::VTableInd::VTableInd(v36, vm);
    v6 = v37;
  }
  v38 = this->VTableTraits.pObject;
  if ( v6 != v38 )
  {
    if ( v38 )
    {
      if ( ((unsigned __int8)v38 & 1) != 0 )
      {
        this->VTableTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)((char *)v38 - 1);
      }
      else
      {
        v39 = v38->RefCount;
        if ( (v39 & 0x3FFFFF) != 0 )
        {
          v38->RefCount = v39 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
        }
      }
    }
    this->VTableTraits.pObject = v6;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v40 = this->VTableTraits.pObject;
  v41 = v40->pConstructor.pObject;
  if ( v12 != v41 )
  {
    if ( v41 )
    {
      if ( ((unsigned __int8)v41 & 1) != 0 )
      {
        v40->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v41 - 1);
      }
      else
      {
        v42 = v41->RefCount;
        if ( (v42 & 0x3FFFFF) != 0 )
        {
          v41->RefCount = v42 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
        }
      }
    }
    v40->pConstructor.pObject = v12;
  }
}

// File Line: 1001
// RVA: 0x7FA720
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS3::ClassTraits::Function::MakeClassTraits(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::ClassTraits::Function *v4; // rax

  v4 = (Scaleform::GFx::AS3::ClassTraits::Function *)vm->MHeap->vfptr->Alloc(result, 240i64, 0i64);
  if ( v4 )
    Scaleform::GFx::AS3::ClassTraits::Function::Function(v4, vm, &Scaleform::GFx::AS3::fl::FunctionCI);
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v4;
  return result;
}

// File Line: 1008
// RVA: 0x7D58B0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->ITraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->ThunkTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->ThunkFunctionTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->MethodIndTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  if ( this->VTableTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
}

// File Line: 1018
// RVA: 0x7B68D0
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Function::Coerce(
        Scaleform::GFx::AS3::ClassTraits::Function *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v4; // r9d
  Scaleform::GFx::AS3::Value::V1U v6; // rax
  const char *pData; // rcx

  v4 = value->Flags & 0x1F;
  if ( ((v4 - 5) & 0xFFFFFFFD) == 0 )
    goto LABEL_4;
  if ( v4 == 12 )
  {
    v6 = value->value.VS._1;
    if ( v6.VStr )
    {
      pData = v6.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 10 && (pData[112] & 0x20) == 0 )
        goto LABEL_4;
    }
  }
  else if ( v4 - 14 <= 3 )
  {
LABEL_4:
    Scaleform::GFx::AS3::Value::Assign(result, value);
    return 1;
  }
  return Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(this, value, result);
}

