// File Line: 36
// RVA: 0x7FBA90
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeInstance(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *result, Scaleform::GFx::AS3::VMAbcFile *file, const unsigned int method_ind, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss, Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Function> *v6; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::Function *v8; // rdi
  Scaleform::GFx::AS3::Instances::Function *v9; // rax
  int v11; // [rsp+58h] [rbp+10h]

  v6 = result;
  v7 = Scaleform::GFx::AS3::VMAbcFile::GetFunctionInstanceTraits(file, gos, method_ind);
  v8 = (Scaleform::GFx::AS3::InstanceTraits::Function *)v7;
  v11 = 337;
  v9 = (Scaleform::GFx::AS3::Instances::Function *)(*(__int64 (__fastcall **)(_QWORD, _QWORD, int *))(**(_QWORD **)(v7[3].pRCCRaw + 48) + 80i64))(
                                                     *(_QWORD *)(v7[3].pRCCRaw + 48),
                                                     LODWORD(v7[2].pPrev),
                                                     &v11);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::Function::Function(v9, v8, ss);
  v6->pV = v9;
  return v6;
}

// File Line: 52
// RVA: 0x8007A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeThunkFunction(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *result, Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::ThunkFunction> *v4; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rsi
  Scaleform::GFx::AS3::Instances::FunctionBase *v6; // rax
  Scaleform::GFx::AS3::Instances::ThunkFunction *v7; // rbx
  int v9; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::FunctionBase *v10; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::FunctionBase *v11; // [rsp+68h] [rbp+20h]

  v3 = thunk;
  v4 = result;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].pNext;
  v9 = 337;
  v6 = (Scaleform::GFx::AS3::Instances::FunctionBase *)v5->pVM->MHeap->vfptr->Alloc(
                                                         v5->pVM->MHeap,
                                                         v5->MemSize,
                                                         (Scaleform::AllocInfo *)&v9);
  v7 = (Scaleform::GFx::AS3::Instances::ThunkFunction *)v6;
  v10 = v6;
  v11 = v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v6, v5);
    v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable';
    v7->Thunk = v3;
  }
  else
  {
    v7 = 0i64;
  }
  v4->pV = v7;
  return v4;
}

// File Line: 63
// RVA: 0x7FA530
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *result, Scaleform::GFx::AS3::Class *data_type, Scaleform::GFx::AS3::ThunkInfo *thunk)
{
  Scaleform::GFx::AS3::ThunkInfo *v4; // rsi
  Scaleform::GFx::AS3::Class *v5; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> *v6; // rdi
  Scaleform::GFx::AS3::Traits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // r14
  Scaleform::GFx::AS3::Instances::FunctionBase *v9; // rax
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v10; // rbx

  v4 = thunk;
  v5 = data_type;
  v6 = result;
  v7 = this->pTraits.pObject;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v7[1].pNext;
  v9 = (Scaleform::GFx::AS3::Instances::FunctionBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const , signed __int64))v7->pVM->MHeap->vfptr->Alloc)(
                                                         v7->pVM->MHeap,
                                                         80i64);
  v10 = (Scaleform::GFx::AS3::Instances::CheckTypeTF *)v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(v9, v8);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::ThunkFunction::`vftable';
    v10->Thunk = v4;
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::CheckTypeTF::`vftable';
    v10->DataTypeClass = v5;
  }
  else
  {
    v10 = 0i64;
  }
  v6->pV = v10;
  return v6;
}

// File Line: 79
// RVA: 0x800690
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::Function::MakePrototype(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v2; // rbx
  Scaleform::GFx::AS3::Instances::FunctionBase *v3; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = Scaleform::GFx::AS3::InstanceTraits::Function::MakeInstance(
         (Scaleform::GFx::AS3::InstanceTraits::Function *)this->pTraits.pObject[1].vfptr,
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = v2;
  v2->pV = (Scaleform::GFx::AS3::Object *)&v3->vfptr;
  return v4;
}

// File Line: 85
// RVA: 0x7F4340
void __fastcall Scaleform::GFx::AS3::Classes::Function::InitPrototype(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::GFx::AS3::Object *obj)
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
  v5 = Scaleform::GFx::AS3::Classes::Function::f;
  v6 = 4i64;
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

// File Line: 104
// RVA: 0x7B8920
void __fastcall Scaleform::GFx::AS3::Classes::Function::Construct(Scaleform::GFx::AS3::Classes::Function *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool extCall)
{
  Scaleform::GFx::AS3::Classes::Function *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+38h] [rbp-20h]

  v5 = this;
  if ( argc )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eFunctionConstructorError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::EvalErrorTI);
    v7 = v9.Message.pNode;
    v8 = v9.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct((Scaleform::GFx::AS3::Class *)&this->vfptr, _this, 0, argv, extCall);
  }
}

// File Line: 132
// RVA: 0x77D840
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(Scaleform::GFx::AS3::Instances::FunctionBase *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rbx
  unsigned int v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  v2->Prototype.pObject = 0i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v2->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  v3 = (Scaleform::GFx::AS3::Instances::fl::Object *)v2->Prototype.pObject;
  v4 = result.pV;
  if ( result.pV != v3 )
  {
    if ( v3 )
    {
      if ( (unsigned __int8)v3 & 1 )
      {
        v2->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)&v3[-1].DynAttrs.mHash.pTable + 7);
      }
      else
      {
        v5 = v3->RefCount;
        if ( v5 & 0x3FFFFF )
        {
          v3->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
        }
      }
    }
    v2->Prototype.pObject = (Scaleform::GFx::AS3::Object *)&v4->vfptr;
  }
}

// File Line: 137
// RVA: 0x78ACF0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::~FunctionBase(Scaleform::GFx::AS3::Instances::FunctionBase *this)
{
  Scaleform::GFx::AS3::Instances::FunctionBase *v1; // rbx
  Scaleform::GFx::AS3::Object *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  v2 = this->Prototype.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instance::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)v1->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&v1->vfptr);
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 141
// RVA: 0x75A560
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // rbx
  unsigned int v6; // eax
  Scaleform::GFx::ASString *v7; // rax
  unsigned __int64 v8; // r8
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::LongFormatter v13; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::ASString resulta; // [rsp+B0h] [rbp+18h]

  v4 = result;
  v5 = vm;
  v6 = _this->Flags & 0x1F;
  if ( v6 == 14 )
  {
    v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
           &resulta,
           "function Function() {}");
    Scaleform::GFx::AS3::Value::Assign(v4, v7);
    goto LABEL_10;
  }
  if ( v6 != 5 )
  {
    v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
            &resulta,
            "function Function() {}");
    Scaleform::GFx::AS3::Value::Assign(v4, v11);
LABEL_10:
    v12 = resulta.pNode;
    v10 = resulta.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    return;
  }
  Scaleform::LongFormatter::LongFormatter(&v13, _this->value.VS._1.VUInt);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
    &resulta,
    "[object Function-");
  *((_DWORD *)&v13 + 12) = *((_DWORD *)&v13 + 12) & 0xFFFFFFF0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v13.vfptr[1].Reflect)(&v13);
  v8 = -1i64;
  do
    ++v8;
  while ( v13.ValueStr[v8] );
  Scaleform::GFx::ASString::Append(&resulta, v13.ValueStr, v8);
  Scaleform::GFx::ASString::Append(&resulta, "]", 1ui64);
  Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
  v9 = resulta.pNode;
  v10 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v13.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v13.vfptr);
}

// File Line: 194
// RVA: 0x7B29E0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::Call(Scaleform::GFx::AS3::Instances::FunctionBase *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // r14
  Scaleform::GFx::AS3::Instances::FunctionBase *v8; // rdi
  __int64 v9; // rcx
  __int64 v10; // r8
  Scaleform::GFx::AS3::Value::VU v11; // kr00_16
  int v12; // edx
  unsigned int v13; // er9
  Scaleform::GFx::AS3::Value::Extra v14; // rax
  long double v15; // rdx
  Scaleform::GFx::AS3::Value::V2U v16; // r8
  bool v17; // zf
  Scaleform::GFx::AS3::Value v18; // [rsp+38h] [rbp-28h]

  v5 = argc;
  v6 = result;
  v7 = _this;
  v8 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v18.Flags = v.Flags;
  v18.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v11 = v.value;
  v10 = *(_OWORD *)&v11 >> 64;
  v9 = (unsigned __int128)v11;
  v18.value = v.value;
  v12 = v.Flags & 0x1F;
  if ( v12 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v12 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v12 > 10 )
    {
      if ( v12 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(v9 + 32) &= 0x8FBFFFFF;
        }
      }
      else if ( v12 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        *(_DWORD *)(v10 + 32) &= 0x8FBFFFFF;
      }
    }
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::FunctionBase *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const ))v8->vfptr[6].Finalize_GC)(
    v8,
    v7,
    &v18,
    v5,
    argv);
  v13 = v6->Flags;
  v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v6->Bonus;
  v15 = v6->value.VNumber;
  v16.VObj = (Scaleform::GFx::AS3::Object *)v6->value.VS._2;
  v6->Flags = v18.Flags;
  v6->Bonus.pWeakProxy = v18.Bonus.pWeakProxy;
  v6->value = v18.value;
  v18.Flags = v13;
  v18.Bonus = v14;
  v18.value.VNumber = v15;
  v18.value.VS._2 = v16;
  if ( (char)(v13 & 0x1F) > 9 )
  {
    if ( (v13 >> 9) & 1 )
    {
      v17 = v18.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v18.Bonus.pWeakProxy = 0i64;
      v18.value = 0ui64;
      v18.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
    }
  }
}

// File Line: 201
// RVA: 0x75D170
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::apply(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // r12
  Scaleform::GFx::AS3::VM *v6; // r15
  unsigned int v7; // ecx
  __int64 v8; // rdx
  __int64 v9; // r9
  Scaleform::GFx::AS3::Value::VU v10; // kr00_16
  int v11; // er8
  unsigned int v12; // edi
  Scaleform::GFx::AS3::Value *v13; // rbx
  int v14; // edx
  Scaleform::GFx::AS3::Impl::SparseArray *v15; // r14
  Scaleform::MemoryHeap *v16; // rax
  __int64 v17; // rsi
  Scaleform::GFx::AS3::Value *v18; // rax
  bool v19; // zf
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::Value *v22; // r8
  unsigned int v23; // edx
  Scaleform::GFx::AS3::Value::Extra v24; // rax
  Scaleform::GFx::AS3::Value::VU v25; // kr10_16
  Scaleform::GFx::AS3::Value resulta; // [rsp+18h] [rbp-59h]
  Scaleform::GFx::AS3::Value v27; // [rsp+38h] [rbp-39h]
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> v28; // [rsp+58h] [rbp-19h]
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v29; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v30; // [rsp+80h] [rbp+Fh]
  __int64 v31; // [rsp+90h] [rbp+1Fh]
  Scaleform::GFx::AS3::Value *vars0; // [rsp+E0h] [rbp+6Fh]
  void *retaddr; // [rsp+E8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *_thisa; // [rsp+F0h] [rbp+7Fh]

  v31 = -2i64;
  v4 = result;
  v5 = _this;
  v6 = vm;
  v7 = _S11_12;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    v7 = _S11_12;
  }
  resulta.Flags = v.Flags;
  resulta.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v10 = v.value;
  v9 = *(_OWORD *)&v10 >> 64;
  v8 = (unsigned __int128)v10;
  resulta.value = v.value;
  v11 = v.Flags & 0x1F;
  if ( v11 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v11 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v11 > 10 )
    {
      if ( v11 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(v8 + 32) &= 0x8FBFFFFF;
        }
      }
      else if ( v11 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        *(_DWORD *)(v9 + 32) &= 0x8FBFFFFF;
      }
    }
  }
  if ( !(_DWORD)retaddr )
  {
    if ( !(v7 & 1) )
    {
      _S11_12 = v7 | 1;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    LOBYTE(resulta.value.VS._2.VObj) = 0;
    *(_QWORD *)&resulta.value.VNumber = _thisa;
    v22 = &v;
    goto LABEL_46;
  }
  if ( (_DWORD)retaddr == 1 )
  {
    LOBYTE(resulta.value.VS._2.VObj) = 0;
    resulta.value.VNumber = 0.0;
    v22 = _thisa;
LABEL_46:
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      v6,
      v5,
      v22,
      &resulta,
      0,
      (Scaleform::GFx::AS3::Value *)resulta.value.VS._1.VStr,
      (bool)resulta.value.VS._2.VObj);
LABEL_47:
    v23 = resulta.Flags;
    v24.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)resulta.Bonus;
    v25 = resulta.value;
    resulta.Flags = v4->Flags;
    resulta.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    resulta.value = v4->value;
    v4->Flags = v23;
    v4->Bonus = v24;
    v4->value = v25;
    goto LABEL_48;
  }
  v27.Flags = 0;
  v27.Bonus.pWeakProxy = 0i64;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::fl::Array *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))v6->TraitsArray.pObject->vfptr[3].Finalize_GC)(
         v6->TraitsArray.pObject,
         &_thisa[1],
         &v27) )
  {
    v12 = 0;
    v13 = 0i64;
    v14 = v27.Flags & 0x1F;
    if ( (unsigned int)(v14 - 12) > 3 && v14 != 10 || *(_QWORD *)&v27.value.VNumber )
    {
      v15 = (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v27.value.VNumber + 56i64);
      if ( *(_QWORD *)(*(_QWORD *)&v27.value.VNumber + 56i64) <= *(_QWORD *)(*(_QWORD *)&v27.value.VNumber + 120i64) )
      {
        v12 = *(_DWORD *)(*(_QWORD *)&v27.value.VNumber + 120i64);
        v13 = *(Scaleform::GFx::AS3::Value **)(*(_QWORD *)&v27.value.VNumber + 112i64);
      }
      else
      {
        v16 = v6->MHeap;
        v29 = &v28;
        v28.Data = 0i64;
        *(_OWORD *)&v28.Size = 0ui64;
        v28.pHeap = v16;
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &v28,
          v15->Length);
        v12 = v28.Size;
        if ( v28.Size )
        {
          v17 = 0i64;
          do
          {
            v18 = Scaleform::GFx::AS3::Impl::SparseArray::At(v15, (unsigned __int64)v13);
            Scaleform::GFx::AS3::Value::Assign(&v28.Data[v17], v18);
            v13 = (Scaleform::GFx::AS3::Value *)((char *)v13 + 1);
            ++v17;
            v12 = v28.Size;
          }
          while ( (unsigned __int64)v13 < v28.Size );
          v4 = vars0;
        }
        v13 = v28.Data;
        v29 = &v28;
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v28.Data, v28.Size);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v28.Data);
      }
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, v5, _thisa, &resulta, v12, v13, 0);
    if ( (v27.Flags & 0x1F) > 9 )
    {
      if ( (v27.Flags >> 9) & 1 )
      {
        v19 = v27.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v27.Bonus.pWeakProxy = 0i64;
        v27.value = 0ui64;
        v27.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
      }
    }
    goto LABEL_47;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v30, eApplyError, v6);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v20, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v21 = v30.Message.pNode;
  v19 = v30.Message.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags >> 9) & 1 )
    {
      v19 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v27.Bonus.pWeakProxy = 0i64;
      v27.value = 0ui64;
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
LABEL_48:
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags >> 9) & 1 )
    {
      v19 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      resulta.Flags &= 0xFFFFFDE0;
      resulta.value = 0ui64;
      resulta.Bonus.pWeakProxy = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
}

// File Line: 277
// RVA: 0x7B89A0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::Construct(Scaleform::GFx::AS3::Instances::FunctionBase *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool __formal)
{
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::Instances::FunctionBase *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rbx
  unsigned int v8; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v9; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+40h] [rbp+8h]

  v5 = result;
  v6 = this;
  v7 = argv;
  v8 = argc;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  Scaleform::GFx::AS3::Value::Pick(v5, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  v9 = v6->vfptr;
  __formal = 1;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::FunctionBase *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))v9[7].ForEachChild_GC)(
    v6,
    v5,
    v8,
    v7);
}

// File Line: 292
// RVA: 0x851630
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::lengthGet(Scaleform::GFx::AS3::Instances::FunctionBase *this, unsigned int *result)
{
  *result = ((__int64 (*)(void))this->vfptr[7].~RefCountBaseGC<328>)();
}

// File Line: 297
// RVA: 0x75C830
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::call(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Value *v5; // r15
  Scaleform::GFx::AS3::VM *v6; // r14
  __int64 v7; // rcx
  __int64 v8; // r8
  Scaleform::GFx::AS3::Value::VU v9; // kr00_16
  int v10; // edx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v11; // rax
  bool v12; // zf
  Scaleform::GFx::AS3::Value *v13; // rcx
  unsigned int v14; // edx
  int v15; // ecx
  Scaleform::GFx::AS3::WeakProxy *v16; // r8
  Scaleform::GFx::AS3::Value::V2U v17; // rax
  long double v18; // rcx
  Scaleform::GFx::AS3::Value *v19; // r8
  char v20; // bl
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v21; // rax
  unsigned int v22; // edx
  Scaleform::GFx::AS3::Value::Extra v23; // rax
  Scaleform::GFx::AS3::Value::VU v24; // kr10_16
  Scaleform::GFx::AS3::Value resulta; // [rsp+28h] [rbp-39h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-19h]
  Scaleform::GFx::AS3::Value v27; // [rsp+68h] [rbp+7h]
  void *retaddr; // [rsp+D8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v29; // [rsp+E0h] [rbp+7Fh]

  v4 = result;
  v5 = _this;
  v6 = vm;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  resulta.Flags = v.Flags;
  resulta.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v9 = v.value;
  v8 = *(_OWORD *)&v9 >> 64;
  v7 = (unsigned __int128)v9;
  resulta.value = v.value;
  v10 = v.Flags & 0x1F;
  if ( v10 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v10 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v10 > 10 )
    {
      if ( v10 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(v7 + 32) &= 0x8FBFFFFF;
        }
      }
      else if ( v10 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        *(_DWORD *)(v8 + 32) &= 0x8FBFFFFF;
      }
    }
  }
  if ( (unsigned int)retaddr >= 1 )
  {
    v14 = v29->Flags;
    v15 = v29->Flags & 0x1F;
    if ( v15 && ((unsigned int)(v15 - 12) > 3 && v15 != 10 || *(_QWORD *)&v29->value.VNumber) )
    {
      _thisa.Flags = v29->Flags;
      v16 = v29->Bonus.pWeakProxy;
      _thisa.Bonus.pWeakProxy = v29->Bonus.pWeakProxy;
      _thisa.value.VNumber = v29->value.VNumber;
      v17.VObj = (Scaleform::GFx::AS3::Object *)v29->value.VS._2;
      _thisa.value.VS._2.VObj = v29->value.VS._2.VObj;
      if ( v15 > 9 )
      {
        if ( (v14 >> 9) & 1 )
        {
          ++v16->RefCount;
        }
        else if ( v15 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v29->value.VNumber + 24i64);
        }
        else if ( v15 > 10 )
        {
          if ( v15 <= 15 )
          {
            v18 = v29->value.VNumber;
            if ( v18 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v18 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v18 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v15 <= 17 && v17.VObj )
          {
            v17.VObj->RefCount = (v17.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
      v19 = &_thisa;
      v20 = 2;
    }
    else
    {
      v21 = Scaleform::GFx::AS3::VM::GetGlobalObject(v6);
      v27.Flags = 12;
      v27.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v27.value.VNumber = v21;
      if ( v21 )
        v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
      v19 = &v27;
      v20 = 1;
    }
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, v5, v19, &resulta, (_DWORD)retaddr - 1, v29 + 1, 0);
    if ( v20 & 2 )
    {
      v20 &= 0xFDu;
      if ( (_thisa.Flags & 0x1F) > 9 )
      {
        if ( (_thisa.Flags >> 9) & 1 )
        {
          v12 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          _thisa.Bonus.pWeakProxy = 0i64;
          _thisa.value = 0ui64;
          _thisa.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_thisa);
        }
      }
    }
    if ( v20 & 1 && (v27.Flags & 0x1F) > 9 )
    {
      if ( !((v27.Flags >> 9) & 1) )
      {
        v13 = &v27;
        goto LABEL_58;
      }
      v12 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v27.Bonus.pWeakProxy = 0i64;
      v27.value = 0ui64;
      v27.Flags &= 0xFFFFFDE0;
    }
  }
  else
  {
    v11 = Scaleform::GFx::AS3::VM::GetGlobalObject(v6);
    _thisa.Flags = 12;
    _thisa.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&_thisa.value.VNumber = v11;
    if ( v11 )
      v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, v5, &_thisa, &resulta, (unsigned int)retaddr, v29, 0);
    if ( (_thisa.Flags & 0x1F) > 9 )
    {
      if ( (_thisa.Flags >> 9) & 1 )
      {
        v12 = _thisa.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _thisa.Bonus.pWeakProxy = 0i64;
        _thisa.value = 0ui64;
        _thisa.Flags &= 0xFFFFFDE0;
        goto LABEL_59;
      }
      v13 = &_thisa;
LABEL_58:
      Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
      goto LABEL_59;
    }
  }
LABEL_59:
  v22 = resulta.Flags;
  v23.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)resulta.Bonus;
  v24 = resulta.value;
  resulta.Flags = v4->Flags;
  resulta.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  resulta.value = v4->value;
  v4->Flags = v22;
  v4->Bonus = v23;
  v4->value = v24;
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags >> 9) & 1 )
    {
      v12 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
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
}

// File Line: 326
// RVA: 0x8165A0
void __fastcall Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(Scaleform::GFx::AS3::Instances::FunctionBase *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::VM *v3; // rdi
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf
  Scaleform::GFx::AS3::Value *v6; // rcx

  v2 = result;
  v3 = this->pTraits.pObject->pVM;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags >> 9) & 1 )
    {
      v4 = result->Bonus.pWeakProxy;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
  }
  v6 = v3->OpStack.pCurrent;
  v2->Flags = v6->Flags;
  v2->Bonus.pWeakProxy = v6->Bonus.pWeakProxy;
  v2->value.VNumber = v6->value.VNumber;
  v2->value.VS._2.VObj = v6->value.VS._2.VObj;
  --v3->OpStack.pCurrent;
}

// File Line: 372
// RVA: 0x77D6C0
void __fastcall Scaleform::GFx::AS3::Instances::Function::Function(Scaleform::GFx::AS3::Instances::Function *this, Scaleform::GFx::AS3::InstanceTraits::Function *tr, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::Instances::Function *v4; // r15
  Scaleform::GFx::AS3::VM *v5; // rbp
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rax
  signed __int64 v8; // rdi
  unsigned __int64 v9; // rsi
  signed __int64 v10; // rbx
  signed __int64 v11; // rdx
  int v12; // eax
  __int64 v13; // rcx

  v3 = ss;
  v4 = this;
  Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
    (Scaleform::GFx::AS3::Instances::FunctionBase *)&this->vfptr,
    (Scaleform::GFx::AS3::InstanceTraits::Traits *)&tr->vfptr);
  v4->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::Function::`vftable';
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>(
    &v4->StoredScopeStack.Data,
    &v3->Data);
  v5 = v4->pTraits.pObject->pVM;
  v6 = v5->ScopeStack.Data.Size;
  if ( v5->CallStack.Size )
    v7 = v5->CallStack.Pages[(v5->CallStack.Size - 1) >> 6][(LODWORD(v5->CallStack.Size) - 1) & 0x3F].ScopeStackBaseInd;
  else
    v7 = 0i64;
  if ( v7 < v6 )
  {
    v8 = v7;
    v9 = v6 - v7;
    do
    {
      v10 = (signed __int64)&v5->ScopeStack.Data.Data[v8];
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v4->StoredScopeStack.Data.Data,
        v4->StoredScopeStack.Data.pHeap,
        v4->StoredScopeStack.Data.Size + 1);
      v11 = (signed __int64)&v4->StoredScopeStack.Data.Data[v4->StoredScopeStack.Data.Size - 1];
      if ( !v11 )
        goto LABEL_19;
      *(_DWORD *)v11 = *(_DWORD *)v10;
      *(_QWORD *)(v11 + 8) = *(_QWORD *)(v10 + 8);
      *(_QWORD *)(v11 + 16) = *(_QWORD *)(v10 + 16);
      *(_QWORD *)(v11 + 24) = *(_QWORD *)(v10 + 24);
      v12 = *(_DWORD *)v10 & 0x1F;
      if ( v12 <= 9 )
        goto LABEL_19;
      if ( (*(_DWORD *)v10 >> 9) & 1 )
      {
        ++**(_DWORD **)(v10 + 8);
      }
      else if ( v12 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v10 + 16) + 24i64);
      }
      else if ( v12 > 10 )
      {
        if ( v12 <= 15 )
        {
          v13 = *(_QWORD *)(v10 + 16);
LABEL_16:
          if ( v13 )
            *(_DWORD *)(v13 + 32) = (*(_DWORD *)(v13 + 32) + 1) & 0x8FBFFFFF;
          goto LABEL_19;
        }
        if ( v12 <= 17 )
        {
          v13 = *(_QWORD *)(v10 + 24);
          goto LABEL_16;
        }
      }
LABEL_19:
      ++v8;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 389
// RVA: 0x7CA110
void __fastcall Scaleform::GFx::AS3::Instances::Function::Execute(Scaleform::GFx::AS3::Instances::Function *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool discard_result)
{
  Scaleform::GFx::AS3::Value *v5; // r12
  unsigned int v6; // er13
  Scaleform::GFx::AS3::Value *v7; // r14
  Scaleform::GFx::AS3::Instances::Function *v8; // r10
  Scaleform::GFx::AS3::Traits *v9; // rdx
  Scaleform::GFx::AS3::VM *v10; // rsi
  int v11; // ecx
  __int64 v12; // rbx
  Scaleform::GFx::AS3::Traits *v13; // r8
  Scaleform::GFx::AS3::VMAbcFile *v14; // r15
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS3::VM *v18; // rcx
  Scaleform::GFx::AS3::ValueStack *v19; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList **v21; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v22; // rcx
  unsigned int v23; // eax
  unsigned __int64 v24; // rdi
  Scaleform::GFx::AS3::CallFrame **v25; // rax
  signed __int64 v26; // rcx
  Scaleform::GFx::AS3::CallFrame *v27; // rcx
  Scaleform::GFx::AS3::CallFrame other; // [rsp+30h] [rbp-B1h]
  Scaleform::GFx::AS3::Value v29; // [rsp+C0h] [rbp-21h]
  Scaleform::GFx::AS3::VM::Error v30; // [rsp+E0h] [rbp-1h]
  __int64 v31; // [rsp+F0h] [rbp+Fh]
  Scaleform::GFx::AS3::CallFrame *v32; // [rsp+140h] [rbp+5Fh]
  Scaleform::GFx::AS3::CallFrame *v33; // [rsp+148h] [rbp+67h]

  v31 = -2i64;
  v5 = argv;
  v6 = argc;
  v7 = _this;
  v8 = this;
  v9 = this->pTraits.pObject;
  v10 = v9->pVM;
  v11 = v7->Flags & 0x1F;
  if ( (!v11 || ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !*(_QWORD *)&v7->value.VNumber)
    && v9->InitScope.Data.Size )
  {
    v7 = v9->InitScope.Data.Data;
  }
  v12 = *(signed int *)(*(_QWORD *)(v9[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                                  + 8i64 * SLODWORD(v9[1].FirstOwnSlotNum))
                      + 8i64);
  v13 = (Scaleform::GFx::AS3::Traits *)v9[1].VArray.Data.Data->Value.File.pObject;
  v29.Flags = 14;
  v29.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v29.value.VNumber = v8;
  v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  v14 = (Scaleform::GFx::AS3::VMAbcFile *)v9[1].Parent;
  if ( v10->CallStack.Size == 128 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v30, eStackOverflowError, v10);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v15, &Scaleform::GFx::AS3::fl::ErrorTI);
    v16 = v30.Message.pNode;
    v17 = v30.Message.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  else
  {
    other.DiscardResult = discard_result;
    other.ACopy = 0;
    v18 = v14->VMRef;
    *(_OWORD *)&other.ScopeStackBaseInd = v18->ScopeStack.Data.Size;
    other.pRegisterFile = &v18->RegisterFile;
    other.pHeap = v18->MHeap;
    other.pFile = v14;
    other.MBIIndex.Ind = v12;
    other.pSavedScope = &v8->StoredScopeStack;
    other.OriginationTraits = v13;
    other.pScopeStack = &v18->ScopeStack;
    other.DefXMLNamespace.pObject = 0i64;
    other.Invoker.Flags = 14;
    other.Invoker.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&other.Invoker.value.VNumber = v8;
    other.Invoker.value.VS._2.VObj = v29.value.VS._2.VObj;
    v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
    v19 = &v14->VMRef->OpStack;
    other.PrevInitialStackPos = v19->pCurrent;
    other.PrevFirstStackPos = v19->pStack;
    v20 = other.pFile->File.pObject->MethodBodies.Info.Data.Data[other.MBIIndex.Ind];
    Scaleform::GFx::AS3::ValueStack::Reserve(v19, v20->max_stack + 1);
    Scaleform::GFx::AS3::ValueRegisterFile::Reserve(other.pRegisterFile, v20->local_reg_count);
    v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)&other.pFile->VMRef->DefXMLNamespace;
    if ( *v21 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&other.DefXMLNamespace,
        *v21);
      v32 = 0i64;
      if ( &v32 != (Scaleform::GFx::AS3::CallFrame **)v21 )
      {
        v22 = *v21;
        if ( *v21 )
        {
          if ( (unsigned __int8)v22 & 1 )
          {
            *v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v22 - 1);
          }
          else
          {
            v23 = v22->RefCount;
            if ( v23 & 0x3FFFFF )
            {
              v22->RefCount = v23 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
            }
          }
        }
        *v21 = 0i64;
      }
    }
    Scaleform::GFx::AS3::CallFrame::SetupRegisters(
      &other,
      v14->File.pObject->Methods.Info.Data.Data[v14->File.pObject->MethodBodies.Info.Data.Data[v12]->method_info_ind],
      v7,
      v6,
      v5);
    if ( v10->HandleException )
    {
      other.ACopy = 1;
    }
    else
    {
      v24 = v10->CallStack.Size >> 6;
      if ( v24 >= v10->CallStack.NumPages )
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
          (Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *)v10->CallStack.gap0,
          v10->CallStack.Size >> 6);
      v25 = v10->CallStack.Pages;
      v26 = v10->CallStack.Size & 0x3F;
      v17 = &v25[v24][v26] == 0i64;
      v27 = &v25[v24][v26];
      v32 = v27;
      v33 = v27;
      if ( !v17 )
        Scaleform::GFx::AS3::CallFrame::CallFrame(v27, &other);
      ++v10->CallStack.Size;
    }
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
}

// File Line: 415
// RVA: 0x7D0D70
void __fastcall Scaleform::GFx::AS3::Instances::Function::ExecuteUnsafe(Scaleform::GFx::AS3::Instances::Function *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::Instances::Function *v6; // rbx
  char v7; // ST20_1
  unsigned int v8; // eax

  v5 = result;
  v6 = this;
  v7 = 0;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::Function *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *, char))this->vfptr[7].ForEachChild_GC)(
    this,
    _this,
    argc,
    argv,
    v7);
  if ( !v6->pTraits.pObject->pVM->HandleException )
  {
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteCode(v6->pTraits.pObject->pVM, 1u);
    if ( !v6->pTraits.pObject->pVM->HandleException )
      Scaleform::GFx::AS3::Instances::FunctionBase::RetrieveResult(
        (Scaleform::GFx::AS3::Instances::FunctionBase *)&v6->vfptr,
        v5);
    if ( !((unsigned __int8)v6 & 1) )
    {
      v8 = v6->RefCount;
      if ( v8 & 0x3FFFFF )
      {
        v6->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
  }
}

// File Line: 439
// RVA: 0x7EBCA0
__int64 __fastcall Scaleform::GFx::AS3::Instances::Function::GetMaxParamNum(Scaleform::GFx::AS3::Instances::Function *this)
{
  Scaleform::GFx::AS3::Traits *v1; // r8

  v1 = this->pTraits.pObject;
  return *(unsigned int *)(*(_QWORD *)(v1[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                                     + 8i64
                                     * *(signed int *)(*(&v1[1].Parent[3].Parent[7].Parent->FirstOwnSlotNum
                                                       + *(signed int *)(*(_QWORD *)(v1[1].Parent[3].Parent[4].VArray.Data.Policy.Capacity
                                                                                   + 8i64
                                                                                   * SLODWORD(v1[1].FirstOwnSlotNum))
                                                                       + 8i64))
                                                     + 24))
                         + 24i64);
}

// File Line: 447
// RVA: 0x7D59B0
void __fastcall Scaleform::GFx::AS3::Instances::Function::ForEachChild_GC(Scaleform::GFx::AS3::Instances::Function *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::Function *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(v4, &v5->StoredScopeStack, v3);
}

// File Line: 464
// RVA: 0x7D0E30
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(Scaleform::GFx::AS3::Instances::ThunkFunction *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkInfo *v5; // rax
  unsigned int v6; // ebx
  bool v7; // zf
  Scaleform::GFx::AS3::Value v8; // [rsp+48h] [rbp-30h]

  v5 = this->Thunk;
  v8.Flags = 5;
  v8.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v8.value.VNumber = v5;
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, &v8, _this, result, argc, argv, 0);
  v6 = v8.Flags;
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags >> 9) & 1 )
    {
      v7 = v8.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v8.Bonus.pWeakProxy = 0i64;
      v8.value = 0ui64;
      v8.Flags = v6 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
    }
  }
}

// File Line: 470
// RVA: 0x7CA740
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(Scaleform::GFx::AS3::Instances::ThunkFunction *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v7; // rax
  Scaleform::GFx::AS3::VM *v8; // r14
  __int64 v9; // rcx
  __int64 v10; // r8
  Scaleform::GFx::AS3::Value::VU v11; // kr00_16
  int v12; // edx
  bool v13; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+30h] [rbp-9h]
  Scaleform::GFx::AS3::Value func; // [rsp+50h] [rbp+17h]
  char v16; // [rsp+B8h] [rbp+7Fh]

  v4 = argv;
  v5 = argc;
  v6 = _this;
  v7 = this->Thunk;
  func.Flags = 5;
  func.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&func.value.VNumber = v7;
  v8 = this->pTraits.pObject->pVM;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  result.Flags = v.Flags;
  result.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v11 = v.value;
  v10 = *(_OWORD *)&v11 >> 64;
  v9 = (unsigned __int128)v11;
  result.value = v.value;
  v12 = v.Flags & 0x1F;
  if ( v12 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v12 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v12 > 10 )
    {
      if ( v12 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(v9 + 32) &= 0x8FBFFFFF;
        }
      }
      else if ( v12 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        *(_DWORD *)(v10 + 32) &= 0x8FBFFFFF;
      }
    }
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, &func, v6, &result, v5, v4, v16 == 0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v13 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags >> 9) & 1 )
    {
      v13 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v13 )
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

// File Line: 476
// RVA: 0x8515B0
void __fastcall Scaleform::GFx::AS3::Instances::ThunkFunction::length(Scaleform::GFx::AS3::Instances::ThunkFunction *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::ThunkInfo *v4; // rax
  unsigned __int64 v5; // rcx
  signed __int64 v6; // rax

  v4 = this->Thunk;
  v5 = *((_QWORD *)v4 + 4);
  v6 = (*((_QWORD *)v4 + 4) >> 9) & 0xFFFi64;
  if ( (_DWORD)v6 == 4095 )
    LODWORD(v6) = (v5 >> 6) & 7;
  Scaleform::GFx::AS3::Value::SetUInt32(result, v6);
}

// File Line: 491
// RVA: 0x7D0C70
void __fastcall Scaleform::GFx::AS3::Instances::CheckTypeTF::ExecuteUnsafe(Scaleform::GFx::AS3::Instances::CheckTypeTF *this, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v5; // er14
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // rbp
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+38h] [rbp-30h]

  v5 = argc;
  v6 = result;
  v7 = _this;
  v8 = this;
  v9 = this->DataTypeClass->pTraits.pObject;
  v10 = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  v11 = v10;
  if ( v9 == (Scaleform::GFx::AS3::Traits *)v10 )
  {
LABEL_8:
    Scaleform::GFx::AS3::Instances::ThunkFunction::ExecuteUnsafe(
      (Scaleform::GFx::AS3::Instances::ThunkFunction *)&v8->vfptr,
      v7,
      v6,
      v5,
      argv);
    return;
  }
  if ( v10 )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v11->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v11->ITraits.pObject,
               v9[1].vfptr) )
    {
      v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject;
      if ( v11 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v9 )
        break;
      if ( !v11 )
        goto LABEL_6;
    }
    goto LABEL_8;
  }
LABEL_6:
  Scaleform::GFx::AS3::VM::Error::Error(&v15, eCheckTypeFailedError, v8->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8->pTraits.pObject->pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v13 = v15.Message.pNode;
  v14 = v15.Message.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}

// File Line: 511
// RVA: 0x7CA010
void __fastcall Scaleform::GFx::AS3::Instances::CheckTypeTF::Execute(Scaleform::GFx::AS3::Instances::CheckTypeTF *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool discard_result)
{
  Scaleform::GFx::AS3::Value *v5; // r14
  unsigned int v6; // er15
  Scaleform::GFx::AS3::Value *v7; // rbp
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+38h] [rbp-30h]

  v5 = argv;
  v6 = argc;
  v7 = _this;
  v8 = this;
  v9 = this->DataTypeClass->pTraits.pObject;
  v10 = Scaleform::GFx::AS3::VM::GetClassTraits(this->pTraits.pObject->pVM, _this);
  v11 = v10;
  if ( v9 == (Scaleform::GFx::AS3::Traits *)v10 )
  {
LABEL_8:
    Scaleform::GFx::AS3::Instances::ThunkFunction::Execute(
      (Scaleform::GFx::AS3::Instances::ThunkFunction *)&v8->vfptr,
      v7,
      v6,
      v5,
      discard_result);
    return;
  }
  if ( v10 )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v11->ITraits.pObject->vfptr[4].~RefCountBaseGC<328>)(
               v11->ITraits.pObject,
               v9[1].vfptr) )
    {
      v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v11->pParent.pObject;
      if ( v11 == (Scaleform::GFx::AS3::ClassTraits::Traits *)v9 )
        break;
      if ( !v11 )
        goto LABEL_6;
    }
    goto LABEL_8;
  }
LABEL_6:
  Scaleform::GFx::AS3::VM::Error::Error(&v15, eCheckTypeFailedError, v8->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8->pTraits.pObject->pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v13 = v15.Message.pNode;
  v14 = v15.Message.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(Scaleform::GFx::AS3::InstanceTraits::Thunk *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v2; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  signed __int64 v4; // rdi

  v2 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::fl::FunctionCICpp);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Thunk::`vftable';
  v2->TraitsType = 10;
  v3 = Scaleform::GFx::AS3::InstanceTraits::Thunk::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v2->vfptr,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      v3);
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 566
// RVA: 0x851720
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Thunk::lengthGet(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  signed __int64 v4; // rax

  v4 = (*(_QWORD *)(*(_QWORD *)&_this->value.VNumber + 32i64) >> 9) & 0xFFFi64;
  if ( (_DWORD)v4 == 4095 )
    v4 = (*(_QWORD *)(*(_QWORD *)&_this->value.VNumber + 32i64) >> 6) & 7i64;
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::MethodInd(Scaleform::GFx::AS3::InstanceTraits::MethodInd *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::InstanceTraits::MethodInd *v2; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  signed __int64 v4; // rdi

  v2 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::fl::FunctionCICpp);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::MethodInd::`vftable';
  v2->TraitsType = 10;
  v3 = Scaleform::GFx::AS3::InstanceTraits::MethodInd::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v2->vfptr,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      v3);
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 607
// RVA: 0x7EC390
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::GetMethodIndName(Scaleform::GFx::AS3::InstanceTraits::Thunk *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v4; // rbx
  unsigned __int64 v5; // r8
  Scaleform::Formatter v7; // [rsp+30h] [rbp-68h]
  void **v8; // [rsp+48h] [rbp-50h]
  char *str; // [rsp+58h] [rbp-40h]
  unsigned int v10; // [rsp+60h] [rbp-38h]

  v3 = result;
  v4 = this;
  Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)&v7, _this->value.VS._1.VUInt);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->pVM->StringManagerRef->Builtins,
    v3,
    "Function-");
  v10 = v10 & 0xFFFFFFF0 | 0x10;
  ((void (__fastcall *)(Scaleform::Formatter *))v7.vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( str[v5] );
  Scaleform::GFx::ASString::Append(v3, str, v5);
  v8 = &Scaleform::String::InitStruct::`vftable';
  Scaleform::Formatter::~Formatter(&v7);
  return v3;
}

// File Line: 618
// RVA: 0x851650
void __fastcall Scaleform::GFx::AS3::InstanceTraits::MethodInd::lengthGet(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  __int64 v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::Value::V2U v6; // rdi
  __int64 v7; // rax

  v4 = _this->value.VS._1.VInt;
  v5 = result;
  if ( (_this->Flags & 0x1F) == 6 )
    v6.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2;
  else
    v6.VObj = (Scaleform::GFx::AS3::Object *)_this->value.VS._2.VObj->pTraits.pObject;
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Value::V2U, Scaleform::GFx::AS3::VM *))v6.VObj->vfptr[2].~RefCountBaseGC<328>)(
         v6,
         vm) )
  {
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Value::V2U))v6.VObj->vfptr[2].~RefCountBaseGC<328>)(v6);
    Scaleform::GFx::AS3::Value::SetUInt32(
      v5,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 152) + 224i64) + 8 * v4) + 24i64));
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::VTableInd::VTableInd(Scaleform::GFx::AS3::InstanceTraits::VTableInd *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v2; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v3; // rbx
  signed __int64 v4; // rdi

  v2 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    &Scaleform::GFx::AS3::fl::FunctionCICpp);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::VTableInd::`vftable';
  v2->TraitsType = 10;
  v3 = Scaleform::GFx::AS3::InstanceTraits::VTableInd::f;
  v4 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v2->vfptr,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      v3);
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 662
// RVA: 0x851750
void __fastcall Scaleform::GFx::AS3::InstanceTraits::VTableInd::lengthGet(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  __int64 v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::Traits *v6; // rdi
  __int64 v7; // rbx
  __int64 v8; // rax

  v5 = result;
  if ( (_this->Flags & 0x1F) == 7 )
    v6 = _this->value.VS._2.pTraits;
  else
    v6 = _this->value.VS._2.VObj->pTraits.pObject;
  v4 = _this->value.VS._1.VUInt;
  v7 = Scaleform::GFx::AS3::Traits::GetVT(v6)->VTMethods.Data.Data[v4].value.VS._1.VInt;
  if ( ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v6->vfptr[2].~RefCountBaseGC<328>)(v6) )
  {
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v6->vfptr[2].~RefCountBaseGC<328>)(v6);
    Scaleform::GFx::AS3::Value::SetUInt32(
      v5,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 152) + 224i64) + 8 * v7) + 24i64));
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
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::GetThunkName(Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *v4; // rbx
  unsigned __int64 v5; // r8
  Scaleform::LongFormatter v7; // [rsp+30h] [rbp-68h]

  v3 = result;
  v4 = this;
  Scaleform::LongFormatter::LongFormatter(&v7, *(_DWORD *)(*(_QWORD *)&_this->value.VNumber + 64i64));
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->pVM->StringManagerRef->Builtins,
    v3,
    "Function-");
  *((_DWORD *)&v7 + 12) = *((_DWORD *)&v7 + 12) & 0xFFFFFFF0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v7.vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( v7.ValueStr[v5] );
  Scaleform::GFx::ASString::Append(v3, v7.ValueStr, v5);
  v7.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v7.vfptr);
  return v3;
}

// File Line: 747
// RVA: 0x77D5F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::Function(Scaleform::GFx::AS3::InstanceTraits::Function *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::ClassInfo *ci, const unsigned int mi, Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *gos)
{
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v6; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Function *v7; // rdi
  Scaleform::GFx::AS3::ClassTraits::Function *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList **v9; // rbx

  v5 = mi;
  v6 = file;
  v7 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    file->VMRef,
    ci);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable';
  v7->MethodInfoInd.Ind = v5;
  v7->File.pObject = v6;
  v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
  v7->GOS.pObject = gos;
  if ( gos )
    gos->RefCount = (gos->RefCount + 1) & 0x8FBFFFFF;
  v8 = v6->VMRef->TraitsFunction.pObject;
  v9 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)v8->ITraits.pObject;
  if ( !v9[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v9)->List.Data.Data)(v8->ITraits.pObject);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v7->pConstructor,
    v9[17]);
  v7->TraitsType = 10;
  Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(v7);
}

// File Line: 779
// RVA: 0x7D5940
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::ForEachChild_GC(Scaleform::GFx::AS3::InstanceTraits::Function *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Function *v5; // rsi

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->Ns.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->File.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->GOS.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
}

// File Line: 787
// RVA: 0x80FEF0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots(Scaleform::GFx::AS3::InstanceTraits::Function *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Function *v1; // rsi
  Scaleform::GFx::ASString *v2; // rax
  Scaleform::GFx::AS3::VM *v3; // r8
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // r9
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v5; // r8
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::ThunkInfo *v8; // rbx
  signed __int64 v9; // rdi
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pVM->StringManagerRef->Builtins,
         &result,
         "prototype");
  v3 = v1->pVM;
  v4 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v3->TraitsObject.pObject->vfptr;
  v5.pV = v3->PublicNamespace.pObject;
  if ( v5.pV )
    v5.pV->RefCount = (v5.pV->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::AddSlotCPP(
    (Scaleform::GFx::AS3::Traits *)&v1->vfptr,
    v2,
    v5,
    v4,
    BT_ObjectCpp,
    (Scaleform::GFx::AS3::AbsoluteIndex)56i64,
    0);
  v6 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v8 = Scaleform::GFx::AS3::InstanceTraits::Function::f;
  v9 = 3i64;
  do
  {
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v1->vfptr,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      v8);
    ++v8;
    --v9;
  }
  while ( v9 );
}

// File Line: 803
// RVA: 0x7E9FA0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::Function::GetFunctionName(Scaleform::GFx::AS3::InstanceTraits::Function *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Function *v4; // rbx
  unsigned __int64 v5; // r8
  Scaleform::LongFormatter v7; // [rsp+30h] [rbp-68h]

  v3 = result;
  v4 = this;
  Scaleform::LongFormatter::LongFormatter(
    &v7,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)&_this->value.VNumber + 40i64) + 240i64));
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->pVM->StringManagerRef->Builtins,
    v3,
    "Function-");
  *((_DWORD *)&v7 + 12) = *((_DWORD *)&v7 + 12) & 0xFFFFFFF0 | 0x10;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v7.vfptr[1].Reflect)(&v7);
  v5 = -1i64;
  do
    ++v5;
  while ( v7.ValueStr[v5] );
  Scaleform::GFx::ASString::Append(v3, v7.ValueStr, v5);
  v7.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
  Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v7.vfptr);
  return v3;
}

// File Line: 816
// RVA: 0x7FF640
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Function::MakeObject(Scaleform::GFx::AS3::InstanceTraits::Function *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = Scaleform::GFx::AS3::InstanceTraits::Function::MakeInstance(this, &resulta, t);
  Scaleform::GFx::AS3::Value::Pick(v3, v4->pV);
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
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::Function *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Instances::Function *v4; // rdi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Flags;
  v4 = v;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  v2->Flags &= 0xFFFFFFEE;
  v2->Flags |= 0xEu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 927
// RVA: 0x807170
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::FunctionBase *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Instances::FunctionBase *v4; // rdi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Flags;
  v4 = v;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  v2->Flags &= 0xFFFFFFEE;
  v2->Flags |= 0xEu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
}

// File Line: 951
// RVA: 0x8072F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::ThunkFunction *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Instances::ThunkFunction *v4; // rdi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Flags;
  v4 = v;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  v2->Flags &= 0xFFFFFFEF;
  v2->Flags |= 0xFu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
}

// File Line: 972
// RVA: 0x77D180
void __fastcall Scaleform::GFx::AS3::ClassTraits::Function::Function(Scaleform::GFx::AS3::ClassTraits::Function *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::ClassInfo *v3; // r15
  Scaleform::GFx::AS3::VM *v4; // r14
  Scaleform::GFx::AS3::ClassTraits::Function *v5; // rdi
  Scaleform::GFx::AS3::InstanceTraits::VTableInd *v6; // rbp
  Scaleform::MemoryHeap *v7; // rsi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v9; // rbx
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::MemoryHeap *v11; // rcx
  Scaleform::GFx::AS3::Class *v12; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v13; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v14; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v15; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v16; // rcx
  unsigned int v17; // eax
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

  v3 = ci;
  v4 = vm;
  v5 = this;
  Scaleform::GFx::AS3::ClassTraits::Traits::Traits((Scaleform::GFx::AS3::ClassTraits::Traits *)&this->vfptr, vm, ci);
  v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Function::`vftable';
  v6 = 0i64;
  v5->ThunkTraits.pObject = 0i64;
  v5->ThunkFunctionTraits.pObject = 0i64;
  v5->MethodIndTraits.pObject = 0i64;
  v5->VTableTraits.pObject = 0i64;
  v5->TraitsType = 10;
  v7 = v4->MHeap;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v7->vfptr->Alloc(v4->MHeap, 264ui64, 0i64);
  v9.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v8->vfptr;
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v8, v4, v3);
    v9.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Function::`vftable';
    v9.pV[1].RefCount = 0;
    v9.pV[1].FirstOwnSlotNum = 0i64;
    v9.pV[1].Parent = 0i64;
    v9.pV->TraitsType = 10;
    Scaleform::GFx::AS3::InstanceTraits::Function::RegisterSlots((Scaleform::GFx::AS3::InstanceTraits::Function *)v9.pV);
  }
  else
  {
    v9.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->vfptr,
    v9);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v7->vfptr->Alloc)(
                                        v7,
                                        72i64);
  v12 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, (Scaleform::GFx::AS3::ClassTraits::Traits *)&v5->vfptr);
    v12->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::Function::`vftable';
  }
  else
  {
    v12 = 0i64;
  }
  v13 = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)v4->MHeap->vfptr->Alloc(v11, 240ui64, 0i64);
  if ( v13 )
  {
    Scaleform::GFx::AS3::InstanceTraits::Thunk::Thunk(v13, v4);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = v5->ThunkTraits.pObject;
  if ( v15 != v16 )
  {
    if ( v16 )
    {
      if ( (unsigned __int8)v16 & 1 )
      {
        v5->ThunkTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Thunk *)((char *)v16 - 1);
      }
      else
      {
        v17 = v16->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v16->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
        }
      }
    }
    v5->ThunkTraits.pObject = v15;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v18 = v5->ThunkTraits.pObject;
  v19 = v18->pConstructor.pObject;
  if ( v12 != v19 )
  {
    if ( v19 )
    {
      if ( (unsigned __int8)v19 & 1 )
      {
        v18->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v19 - 1);
      }
      else
      {
        v20 = v19->RefCount;
        if ( v20 & 0x3FFFFF )
        {
          v19->RefCount = v20 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
        }
      }
    }
    v18->pConstructor.pObject = v12;
  }
  v21 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->MHeap->vfptr->Alloc(
                                                          (Scaleform::MemoryHeap *)v19,
                                                          240ui64,
                                                          0i64);
  v22 = v21;
  if ( v21 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v21, v4, &Scaleform::GFx::AS3::fl::FunctionCIThunk);
    v22->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::`vftable';
    v22->TraitsType = 10;
    Scaleform::GFx::AS3::Traits::Add2VT(
      (Scaleform::GFx::AS3::Traits *)&v22->vfptr,
      &Scaleform::GFx::AS3::fl::FunctionCI,
      Scaleform::GFx::AS3::InstanceTraits::ThunkFunction::f);
  }
  else
  {
    v22 = 0i64;
  }
  v23 = v5->ThunkFunctionTraits.pObject;
  if ( v22 != (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v23 )
  {
    if ( v23 )
    {
      if ( (unsigned __int8)v23 & 1 )
      {
        v5->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)((char *)v23 - 1);
      }
      else
      {
        v24 = v23->RefCount;
        if ( v24 & 0x3FFFFF )
        {
          v23->RefCount = v24 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v23->vfptr);
        }
      }
    }
    v5->ThunkFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::ThunkFunction *)v22;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v25 = v5->ThunkFunctionTraits.pObject;
  v26 = v25->pConstructor.pObject;
  if ( v12 != v26 )
  {
    if ( v26 )
    {
      if ( (unsigned __int8)v26 & 1 )
      {
        v25->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v26 - 1);
      }
      else
      {
        v27 = v26->RefCount;
        if ( v27 & 0x3FFFFF )
        {
          v26->RefCount = v27 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26->vfptr);
        }
      }
    }
    v25->pConstructor.pObject = v12;
  }
  v28 = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)v4->MHeap->vfptr->Alloc(
                                                            (Scaleform::MemoryHeap *)v26,
                                                            240ui64,
                                                            0i64);
  if ( v28 )
  {
    Scaleform::GFx::AS3::InstanceTraits::MethodInd::MethodInd(v28, v4);
    v30 = v29;
  }
  else
  {
    v30 = 0i64;
  }
  v31 = v5->MethodIndTraits.pObject;
  if ( v30 != v31 )
  {
    if ( v31 )
    {
      if ( (unsigned __int8)v31 & 1 )
      {
        v5->MethodIndTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::MethodInd *)((char *)v31 - 1);
      }
      else
      {
        v32 = v31->RefCount;
        if ( v32 & 0x3FFFFF )
        {
          v31->RefCount = v32 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v31->vfptr);
        }
      }
    }
    v5->MethodIndTraits.pObject = v30;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v33 = v5->MethodIndTraits.pObject;
  v34 = v33->pConstructor.pObject;
  if ( v12 != v34 )
  {
    if ( v34 )
    {
      if ( (unsigned __int8)v34 & 1 )
      {
        v33->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v34 - 1);
      }
      else
      {
        v35 = v34->RefCount;
        if ( v35 & 0x3FFFFF )
        {
          v34->RefCount = v35 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v34->vfptr);
        }
      }
    }
    v33->pConstructor.pObject = v12;
  }
  v36 = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)v4->MHeap->vfptr->Alloc(
                                                            (Scaleform::MemoryHeap *)v34,
                                                            240ui64,
                                                            0i64);
  if ( v36 )
  {
    Scaleform::GFx::AS3::InstanceTraits::VTableInd::VTableInd(v36, v4);
    v6 = v37;
  }
  v38 = v5->VTableTraits.pObject;
  if ( v6 != v38 )
  {
    if ( v38 )
    {
      if ( (unsigned __int8)v38 & 1 )
      {
        v5->VTableTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::VTableInd *)((char *)v38 - 1);
      }
      else
      {
        v39 = v38->RefCount;
        if ( v39 & 0x3FFFFF )
        {
          v38->RefCount = v39 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v38->vfptr);
        }
      }
    }
    v5->VTableTraits.pObject = v6;
  }
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  v40 = v5->VTableTraits.pObject;
  v41 = v40->pConstructor.pObject;
  if ( v12 != v41 )
  {
    if ( v41 )
    {
      if ( (unsigned __int8)v41 & 1 )
      {
        v40->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v41 - 1);
      }
      else
      {
        v42 = v41->RefCount;
        if ( v42 & 0x3FFFFF )
        {
          v41->RefCount = v42 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v41->vfptr);
        }
      }
    }
    v40->pConstructor.pObject = v12;
  }
}

// File Line: 1001
// RVA: 0x7FA720
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::Function::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::GFx::AS3::ClassTraits::Function *v4; // rax

  v2 = vm;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::ClassTraits::Function *)vm->MHeap->vfptr->Alloc(
                                                       (Scaleform::MemoryHeap *)result,
                                                       240ui64,
                                                       0i64);
  if ( v4 )
    Scaleform::GFx::AS3::ClassTraits::Function::Function(v4, v2, &Scaleform::GFx::AS3::fl::FunctionCI);
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->vfptr;
  return v3;
}

// File Line: 1008
// RVA: 0x7D58B0
void __fastcall Scaleform::GFx::AS3::ClassTraits::Function::ForEachChild_GC(Scaleform::GFx::AS3::ClassTraits::Function *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Function *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Traits::ForEachChild_GC((Scaleform::GFx::AS3::Traits *)&this->vfptr, prcc, op);
  if ( v5->ITraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->ThunkTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->ThunkFunctionTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->MethodIndTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
  if ( v5->VTableTraits.pObject )
    ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))v3)(v4);
}

// File Line: 1018
// RVA: 0x7B68D0
bool __fastcall Scaleform::GFx::AS3::ClassTraits::Function::Coerce(Scaleform::GFx::AS3::ClassTraits::Function *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::ClassTraits::Function *v3; // r10
  unsigned int v4; // er9
  long double v6; // rax
  __int64 v7; // rcx

  v3 = this;
  v4 = value->Flags & 0x1F;
  if ( !((v4 - 5) & 0xFFFFFFFD) )
    goto LABEL_4;
  if ( v4 == 12 )
  {
    v6 = value->value.VNumber;
    if ( v6 != 0.0 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64);
      if ( *(_DWORD *)(v7 + 120) == 10 )
      {
        if ( ~(*(_BYTE *)(v7 + 112) >> 5) & 1 )
          goto LABEL_4;
      }
    }
  }
  else if ( v4 - 14 <= 3 )
  {
LABEL_4:
    Scaleform::GFx::AS3::Value::Assign(result, value);
    return 1;
  }
  return Scaleform::GFx::AS3::ClassTraits::Traits::CoerceValue(
           (Scaleform::GFx::AS3::ClassTraits::Traits *)&v3->vfptr,
           value,
           result);
}

