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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Error,1,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Error *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::Error(Scaleform::GFx::AS3::Instances::fl::Error *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::Error *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // [rsp+48h] [rbp+10h]

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Error::`vftable';
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v3->message,
    v3->pTraits.pObject->pVM->StringManagerRef);
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v3->name,
    v3->pTraits.pObject->pVM->StringManagerRef);
  v3->ID = 0;
  v4 = *(Scaleform::GFx::ASStringNode **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASStringNode **))v2->vfptr[1].~RefCountBaseGC<328>)(
                                           v2,
                                           &v8);
  ++v4->RefCount;
  v5 = v3->name.pNode;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v3->name.pNode = v4;
  v7 = v8;
  v6 = v8->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 66
// RVA: 0x838880
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::errorIDGet(Scaleform::GFx::AS3::Instances::fl::Error *this, int *result)
{
  *result = this->ID;
}

// File Line: 72
// RVA: 0x84CE40
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::getStackTrace(Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v2 = result;
  v3 = this->pTraits.pObject->pVM->StringManagerRef->Builtins[2].pNode;
  ++v3->RefCount;
  v4 = result->pNode;
  v5 = result->pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    v2->pNode = v3;
  }
  else
  {
    result->pNode = v3;
  }
}

// File Line: 83
// RVA: 0x869670
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::toStringProto(Scaleform::GFx::AS3::Instances::fl::Error *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::Error *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  const char *v8; // rdx
  unsigned __int64 v9; // r8
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::String v11; // [rsp+48h] [rbp+10h]

  v2 = result;
  v3 = this;
  v4 = Scaleform::GFx::AS3::Object::GetName((Scaleform::GFx::AS3::Object *)&this->vfptr, &resulta)->pNode;
  ++v4->RefCount;
  v5 = v2->pNode;
  v6 = v2->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v2->pNode = v4;
  v7 = resulta.pNode;
  v6 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v3->message.pNode->Size )
  {
    v8 = (const char *)((Scaleform::operator+(&v11, ": ", &v3->message)->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v9 = -1i64;
    do
      ++v9;
    while ( v8[v9] );
    Scaleform::GFx::ASString::Append(v2, v8, v9);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 116
// RVA: 0x796730
void __fastcall Scaleform::GFx::AS3::Instances::fl::Error::AS3Constructor(Scaleform::GFx::AS3::Instances::fl::Error *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Error *v4; // r14
  unsigned int v5; // ebp
  unsigned int v6; // er9
  Scaleform::GFx::ASStringNode *v7; // rax
  signed __int64 v8; // rsi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h]
  int v12; // [rsp+58h] [rbp+20h]

  v3 = argv;
  v4 = this;
  v5 = argc;
  if ( argc )
  {
    v6 = argv->Flags & 0x1F;
    if ( v6 - 12 > 3 && v6 != 10 || *(_QWORD *)&argv->value.VNumber )
    {
      Scaleform::GFx::AS3::Value::Convert2String(argv, &result, &this->message);
    }
    else
    {
      v7 = this->message.pNode;
      v8 = (signed __int64)&v7->pManager->NullStringNode;
      ++v7->pManager->NullStringNode.RefCount;
      v9 = this->message.pNode;
      v10 = v9->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v4->message.pNode = (Scaleform::GFx::ASStringNode *)v8;
    }
  }
  if ( v5 > 1 )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2Int32(v3 + 1, &result, &v12)->Result )
      v4->ID = v12;
  }
}

// File Line: 155
// RVA: 0x7FF490
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::Error *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::Error *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 198
// RVA: 0x7F4180
void __fastcall Scaleform::GFx::AS3::Classes::fl::Error::InitPrototype(Scaleform::GFx::AS3::Classes::fl::Error *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rbx
  Scaleform::GFx::AS3::Class *v4; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  int v9; // eax
  _DWORD *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int v13; // eax
  int v14; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v15; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  unsigned int v17; // [rsp+48h] [rbp-28h]
  _DWORD *v18; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+10h]

  v2 = obj;
  v3 = (Scaleform::GFx::ASStringNode *)this;
  v4 = this->ParentClass.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::GFx::AS3::Class *))v4->vfptr[7].Finalize_GC)(v4);
  Scaleform::GFx::AS3::Object::AddDynamicFunc(v2, Scaleform::GFx::AS3::Classes::fl::Error::ti);
  v17 = 13;
  v18 = 0i64;
  v19 = v3;
  v3->Size = (v3->Size + 1) & 0x8FBFFFFF;
  v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(*((_QWORD *)v3[1].pData
                                                                                                 + 16)
                                                                                               + 16i64),
         &result,
         "constructor");
  v14 = 1;
  v15 = v5->pNode;
  ++v15->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v14;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v17;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v2->DynAttrs.mHash.pTable,
    &v2->DynAttrs,
    &key);
  v6 = v15;
  v7 = v15->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v8 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = v17 & 0x1F;
  if ( v9 > 9 )
  {
    if ( (v17 >> 9) & 1 )
    {
      v10 = v18;
      v7 = *v18 == 1;
      --*v10;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v10);
      v18 = 0i64;
      v19 = 0i64;
      v20 = 0i64;
      v17 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v9 )
      {
        case 10:
          v11 = v19;
          v7 = v19->RefCount == 1;
          --v11->RefCount;
          if ( v7 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v19;
          if ( !((unsigned __int8)v19 & 1) )
            goto LABEL_19;
          v19 = (Scaleform::GFx::ASStringNode *)((char *)v19 - 1);
          break;
        case 16:
        case 17:
          v12 = v20;
          if ( (unsigned __int8)v20 & 1 )
          {
            v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
          }
          else
          {
LABEL_19:
            if ( v12 )
            {
              v13 = v12->RefCount;
              if ( v13 & 0x3FFFFF )
              {
                v12->RefCount = v13 - 1;
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

// File Line: 214
// RVA: 0x800660
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl::Error::MakePrototype(Scaleform::GFx::AS3::Classes::fl::Error *this, Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::Error *v3; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl::Error *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = v2;
  v2->pV = (Scaleform::GFx::AS3::Object *)&v3->vfptr;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl::Error,0,Scaleform::GFx::ASString,long>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::ASString *, int))Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::Error,1,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl::Error *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet;
  return result;
}

// File Line: 251
// RVA: 0x73E810
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Error::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::ErrorCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Error::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::ErrorCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Error::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Error::`vftable';
  }
  return v3;
}

