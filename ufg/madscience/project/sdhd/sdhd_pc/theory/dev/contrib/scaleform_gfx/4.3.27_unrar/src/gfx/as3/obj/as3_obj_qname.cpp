// File Line: 35
// RVA: 0x158C470
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::QName_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B360 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,0,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet;
  return result;
}

// File Line: 36
// RVA: 0x158C3E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::QName_1_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B370 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,1,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl::QName::uriGet;
  return result;
}

// File Line: 37
// RVA: 0x158C410
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::QName_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::QName___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B380 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *))Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf;
  return result;
}

// File Line: 38
// RVA: 0x158C440
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::QName_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B390 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl::QName::AS3toString;
  return result;
}

// File Line: 53
// RVA: 0x7816F0
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::QName(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::QName *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rcx

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v3->LocalName);
  v4 = v2->pVM->PublicNamespace.pObject;
  v3->Ns.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 68
// RVA: 0x86B920
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::uriGet(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rdx

  v2 = result;
  v3 = this->Ns.pObject;
  if ( v3 )
    Scaleform::GFx::AS3::Value::Assign(v2, &v3->Uri);
  else
    Scaleform::GFx::AS3::Value::SetNull(v2);
}

// File Line: 81
// RVA: 0x7A9260
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf(Scaleform::GFx::AS3::Instances::fl::XMLList *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, this);
}

// File Line: 87
// RVA: 0x7A81A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::QName *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rdi
  Scaleform::StringDH *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::String resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = this->Ns.pObject;
  if ( v4 )
  {
    v6 = v4->Uri.pNode;
    if ( v6->Size )
    {
      ++v6->RefCount;
      v10 = result->pNode;
      v9 = result->pNode->RefCount == 1;
      --v10->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      v2->pNode = v6;
      Scaleform::GFx::ASString::Append(v2, "::", 2ui64);
      Scaleform::GFx::ASString::Append(v2, &v3->LocalName);
    }
    else
    {
      v7 = this->LocalName.pNode;
      ++v7->RefCount;
      v8 = result->pNode;
      v9 = result->pNode->RefCount == 1;
      --v8->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      v2->pNode = v7;
    }
  }
  else
  {
    v5 = (Scaleform::StringDH *)Scaleform::operator+(&resulta, "*::", &this->LocalName);
    Scaleform::GFx::ASString::operator=<Scaleform::String>(v2, v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 115
// RVA: 0x747820
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::VM *v6; // rdi
  long double v7; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rbx
  Scaleform::GFx::AS3::Traits *v9; // rax
  Scaleform::GFx::AS3::Instances::fl::QName *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  bool v13; // zf
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v4 = result;
  v5 = _this;
  v6 = vm;
  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_14;
  v7 = _this->value.VNumber;
  v8 = vm->TraitsQName.pObject->ITraits.pObject;
  if ( !v8->pConstructor.pObject )
    v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
  if ( *(Scaleform::GFx::AS3::Object **)&v7 != Scaleform::GFx::AS3::Class::GetPrototype(v8->pConstructor.pObject) )
  {
LABEL_14:
    v9 = Scaleform::GFx::AS3::VM::GetValueTraits(v6, v5);
    if ( v9->TraitsType != 17 || (LOBYTE(v9->Flags) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v14, eInvokeOnIncompatibleObjectError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v11 = v14.Message.pNode;
    }
    else
    {
      v10 = (Scaleform::GFx::AS3::Instances::fl::QName *)v5->value.VS._1.VStr;
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
        &resulta);
      Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(v10, &resulta);
      Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
      v11 = resulta.pNode;
    }
    v13 = v11->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::ASString *)v6->StringManagerRef);
  }
}

// File Line: 154
// RVA: 0x781780
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::QName(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rsi
  Scaleform::GFx::ASString *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::QName *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rax

  v4 = ns;
  v5 = n;
  v6 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable;
  v7 = v5->pNode;
  v6->LocalName = (Scaleform::GFx::ASString)v5->pNode;
  ++v7->RefCount;
  v6->Ns.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 163
// RVA: 0x7D6D70
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->Parent.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->Parent);
}

// File Line: 177
// RVA: 0x798E70
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::AS3Constructor(Scaleform::GFx::AS3::Instances::fl::QName *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::QName *v4; // rdi
  Scaleform::GFx::AS3::VM *v5; // r9
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v6; // rbp
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  const char *v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rcx
  unsigned int v14; // eax
  int v15; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v16; // rbx
  Scaleform::GFx::AS3::Value *prefix; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  int v19; // ebx
  Scaleform::GFx::AS3::Value *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rbx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::CheckResult v26; // [rsp+78h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v27; // [rsp+88h] [rbp+20h]

  v3 = argv;
  v4 = this;
  v5 = this->pTraits.pObject->pVM;
  v6 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins;
  if ( !argc )
  {
    v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->StringManagerRef->Builtins,
           &result)->pNode;
    ++v7->RefCount;
    v8 = v4->LocalName.pNode;
    v9 = v8->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v4->LocalName.pNode = v7;
    goto LABEL_41;
  }
  if ( argc == 1 )
  {
    if ( !(argv->Flags & 0x1F) || Scaleform::GFx::AS3::Value::Convert2String(argv, &v26, &this->LocalName)->Result )
    {
      v10 = v4->LocalName.pNode->pData;
      if ( *v10 == pattern[0] && !v10[1] )
      {
        v11 = v4->Ns.pObject;
        if ( v11 )
        {
          if ( (unsigned __int8)v11 & 1 )
          {
            v4->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( v12 & 0x3FFFFF )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
            }
          }
          v4->Ns.pObject = 0i64;
        }
      }
    }
    return;
  }
  v13 = this->Ns.pObject;
  if ( v13 )
  {
    if ( (unsigned __int8)v13 & 1 )
    {
      v4->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v13 - 1);
    }
    else
    {
      v14 = v13->RefCount;
      if ( v14 & 0x3FFFFF )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
      }
    }
    v4->Ns.pObject = 0i64;
  }
  v15 = v3->Flags & 0x1F;
  if ( (unsigned int)(v15 - 12) > 3 && v15 != 10 || *(_QWORD *)&v3->value.VNumber )
  {
    if ( v15 == 11 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Ns,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->value.VS._1.VStr);
    }
    else if ( Scaleform::GFx::AS3::IsQNameObject(v3) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v4->Ns,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)(*(_QWORD *)&v3->value.VNumber + 64i64));
    }
    else
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v6, &result);
      if ( Scaleform::GFx::AS3::Value::Convert2String(v3, &v26, &result)->Result )
      {
        v16 = v4->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject;
        prefix = Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
          *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v16[1].RefCount,
          &v27,
          0,
          &result,
          prefix);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Ns,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v27.pV);
      }
      v18 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  v19 = v3[1].Flags & 0x1F;
  if ( v19 == 11 )
  {
    v20 = (Scaleform::GFx::AS3::Value *)(*(_QWORD *)&v3->value.VNumber + 72i64);
    goto LABEL_44;
  }
  if ( !Scaleform::GFx::AS3::IsQNameObject(v3 + 1) )
  {
    if ( !v19 )
    {
      v23 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
              v6,
              &result);
      Scaleform::GFx::ASString::operator=(&v4->LocalName, v23);
LABEL_41:
      v24 = result.pNode;
      v9 = result.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      return;
    }
    v20 = v3 + 1;
LABEL_44:
    Scaleform::GFx::AS3::Value::Convert2String(v20, &v26, &v4->LocalName);
    return;
  }
  v21 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)&v3[1].value.VNumber + 56i64);
  ++v21->RefCount;
  v22 = v4->LocalName.pNode;
  v9 = v22->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v4->LocalName.pNode = v21;
}

// File Line: 284
// RVA: 0x7ECED0
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::StringManager *v4; // rcx
  unsigned int v5; // er8
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString *v8; // rax
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString v11; // [rsp+58h] [rbp+20h]

  v3 = name;
  v4 = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = ind.Index - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return;
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
           &result,
           "localName");
    Scaleform::GFx::AS3::Value::Assign(v3, v6);
    v7 = result.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
           &v11,
           "uri");
    Scaleform::GFx::AS3::Value::Assign(v3, v8);
    v7 = v11.pNode;
  }
  v9 = v7->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 302
// RVA: 0x7ECCB0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextDynPropIndex(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v3; // rax

  v3 = result;
  if ( ind.Index > 1 )
    result->Index = 0;
  else
    result->Index = ind.Index + 1;
  return v3;
}

// File Line: 316
// RVA: 0x7ED130
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextPropertyValue(Scaleform::GFx::AS3::Instances::fl::QName *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // rax
  unsigned int v4; // er8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v5; // rdx

  v3 = value;
  v4 = ind.Index - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
      Scaleform::GFx::AS3::Value::Assign(value, &this->LocalName);
  }
  else
  {
    v5 = this->Ns.pObject;
    if ( v5 )
      Scaleform::GFx::AS3::Value::Assign(v3, &v5->Uri);
    else
      Scaleform::GFx::AS3::Value::SetNull(v3);
  }
}

// File Line: 354
// RVA: 0x1597180
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::QName::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::QName::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::QName::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 368
// RVA: 0x7FFE80
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::QName *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::QName *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 397
// RVA: 0x7F4AC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::QName::InitPrototype(Scaleform::GFx::AS3::Classes::fl::QName *this, Scaleform::GFx::AS3::Object *obj)
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
  Scaleform::GFx::AS3::Object::AddDynamicFunc(v2, Scaleform::GFx::AS3::Classes::fl::QName::ti);
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

// File Line: 407
// RVA: 0x7B8E40
void __fastcall Scaleform::GFx::AS3::Classes::fl::QName::Construct(Scaleform::GFx::AS3::Classes::fl::QName *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool extCall)
{
  Scaleform::GFx::AS3::Value *v5; // rbx
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::Classes::fl::QName *v8; // rsi
  Scaleform::GFx::AS3::Traits *v9; // rax

  v5 = argv;
  v6 = argc;
  v7 = _this;
  v8 = this;
  if ( argc == 1
    && (v9 = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv), v9->TraitsType == 17)
    && (unsigned __int8)~(LOBYTE(v9->Flags) >> 5) & (unsigned __int8)v6 )
  {
    Scaleform::GFx::AS3::Value::Assign(v7, v5);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct((Scaleform::GFx::AS3::Class *)&v8->vfptr, v7, v6, v5, extCall);
  }
}

// File Line: 447
// RVA: 0x7541E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::QName::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::QNameCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::QName::`vftable;
    v6->TraitsType = 17;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::QNameCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::QName::`vftable;
    v8.pV->TraitsType = 17;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::QName::`vftable;
  }
  return v3;
}

