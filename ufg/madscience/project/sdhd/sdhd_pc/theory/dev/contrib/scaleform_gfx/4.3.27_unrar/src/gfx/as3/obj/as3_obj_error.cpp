// File Line: 34
// RVA: 0x1589890
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Error_0_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A5E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,0,long>::Method = Scaleform::GFx::AS3::Instances::fl::Error::errorIDGet;
  return result;
}

// File Line: 35
// RVA: 0x1589830
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Error_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A5F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,1,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Error *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace;
  return result;
}

// File Line: 39
// RVA: 0x1589860
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Error_2_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A600 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,2,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::Error::toStringProto;
  return result;
}

// File Line: 53
// RVA: 0x77CA70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::Error(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  __int64 v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Error::`vftable;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->message,
    this->pTraits.pObject->pVM->StringManagerRef);
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->name,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->ID = 0;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **))t->vfptr[1].~RefCountBaseGC<328>)(
         t,
         &v9);
  v5 = *(Scaleform::GFx::ASStringNode **)v4;
  ++*(_DWORD *)(*(_QWORD *)v4 + 24i64);
  pNode = this->name.pNode;
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->name.pNode = v5;
  v8 = v9;
  v7 = v9->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 66
// RVA: 0x838880
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::errorIDGet(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        int *result)
{
  *result = this->ID;
}

// File Line: 72
// RVA: 0x84CE40
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[2].pNode;
  ++pNode->RefCount;
  v4 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    result->pNode = pNode;
  }
  else
  {
    result->pNode = pNode;
  }
}

// File Line: 83
// RVA: 0x869670
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::toStringProto(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  const char *v9; // rdx
  unsigned __int64 v10; // r8
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::String v12; // [rsp+48h] [rbp+10h] BYREF

  Name = Scaleform::GFx::AS3::Object::GetName(this, &resulta);
  pNode = Name->pNode;
  ++Name->pNode->RefCount;
  v6 = result->pNode;
  v7 = result->pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  result->pNode = pNode;
  v8 = resulta.pNode;
  v7 = resulta.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( this->message.pNode->Size )
  {
    v9 = (const char *)((Scaleform::operator+(&v12, ": ", &this->message)->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v10 = -1i64;
    do
      ++v10;
    while ( v9[v10] );
    Scaleform::GFx::ASString::Append(result, v9, v10);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 116
// RVA: 0x796730
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Error *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v6; // r9d
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *p_NullStringNode; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h] BYREF
  int v12; // [rsp+58h] [rbp+20h] BYREF

  if ( argc )
  {
    v6 = argv->Flags & 0x1F;
    if ( v6 - 12 > 3 && v6 != 10 || argv->value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, &result, &this->message);
    }
    else
    {
      pNode = this->message.pNode;
      p_NullStringNode = &pNode->pManager->NullStringNode;
      ++pNode->pManager->NullStringNode.RefCount;
      v9 = this->message.pNode;
      if ( v9->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      this->message.pNode = p_NullStringNode;
    }
  }
  if ( argc > 1 && Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &result, &v12)->Result )
    this->ID = v12;
}

// File Line: 155
// RVA: 0x7FF490
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Error *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Error *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 198
// RVA: 0x7F4180
void __fastcall Scaleform::GFx::AS3::Classes::fl::Error::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Error *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx
  unsigned int Size; // eax
  int v12; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v15; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v16; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+58h] [rbp-18h]
  __int64 v18; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+10h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, Scaleform::GFx::AS3::Classes::fl::Error::ti);
  v15 = 13;
  v16 = 0i64;
  v17 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         "constructor");
  v12 = 1;
  pNode = v5->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v12;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v15;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v6 = pNode;
  v7 = pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v8 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( (v15 & 0x1Fu) > 9 )
  {
    if ( (v15 & 0x200) != 0 )
    {
      v7 = (*v16)-- == 1;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v16 = 0i64;
      v17 = 0i64;
      v18 = 0i64;
      v15 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v15 & 0x1F )
      {
        case 0xA:
          v9 = v17;
          v7 = v17->RefCount-- == 1;
          if ( v7 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v9);
          break;
        case 0xB:
          v10 = v17;
          if ( ((unsigned __int8)v17 & 1) != 0 )
          {
            v17 = (Scaleform::GFx::ASStringNode *)((char *)v17 - 1);
          }
          else if ( v17 )
          {
            Size = v17->Size;
            if ( (Size & 0x3FFFFF) != 0 )
            {
              v17->Size = Size - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10);
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 214
// RVA: 0x800660
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl::Error::MakePrototype(
        Scaleform::GFx::AS3::Classes::fl::Error *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Error *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> resulta; // [rsp+30h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl::Error *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = result;
  result->pV = pV;
  return v4;
}

// File Line: 225
// RVA: 0x15905B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl::Error_0_Scaleform::GFx::ASString_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A610 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet;
  return result;
}

// File Line: 226
// RVA: 0x1594EA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::Error_1_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A620 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Error,1,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet;
  return result;
}

// File Line: 251
// RVA: 0x73E810
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Error::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::ErrorCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Error::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::ErrorCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Error::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Error::`vftable;
  }
  return result;
}

