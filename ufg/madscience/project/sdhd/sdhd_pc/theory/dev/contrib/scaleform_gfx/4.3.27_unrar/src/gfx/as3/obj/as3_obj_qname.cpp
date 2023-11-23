// File Line: 35
// RVA: 0x158C470
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::QName_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B360 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,0,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::QName,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::QName *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::QName> *))Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::QName(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &this->LocalName);
  pObject = t->pVM->PublicNamespace.pObject;
  this->Ns.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 68
// RVA: 0x86B920
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::uriGet(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx

  pObject = this->Ns.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Value::Assign(result, &pObject->Uri);
  else
    Scaleform::GFx::AS3::Value::SetNull(result);
}

// File Line: 81
// RVA: 0x7A9260
void __fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3valueOf(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(result, this);
}

// File Line: 87
// RVA: 0x7A81A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdi
  Scaleform::StringDH *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::String resulta; // [rsp+40h] [rbp+8h] BYREF

  pObject = this->Ns.pObject;
  if ( pObject )
  {
    pNode = pObject->Uri.pNode;
    if ( pNode->Size )
    {
      ++pNode->RefCount;
      v10 = result->pNode;
      v9 = result->pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      result->pNode = pNode;
      Scaleform::GFx::ASString::Append(result, "::", 2ui64);
      Scaleform::GFx::ASString::Append(result, &this->LocalName);
    }
    else
    {
      v7 = this->LocalName.pNode;
      ++v7->RefCount;
      v8 = result->pNode;
      v9 = result->pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      result->pNode = v7;
    }
  }
  else
  {
    v5 = (Scaleform::StringDH *)Scaleform::operator+(&resulta, "*::", &this->LocalName);
    Scaleform::GFx::ASString::operator=<Scaleform::String>(result, v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 115
// RVA: 0x747820
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Instances::fl::QName *VStr; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_6;
  VObj = _this->value.VS._1.VObj;
  pObject = vm->TraitsQName.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else
  {
LABEL_6:
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
    if ( ValueTraits->TraitsType != Traits_QName || (ValueTraits->Flags & 0x20) != 0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v14, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v14.Message.pNode;
    }
    else
    {
      VStr = (Scaleform::GFx::AS3::Instances::fl::QName *)_this->value.VS._1.VStr;
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        vm->StringManagerRef,
        &resulta);
      Scaleform::GFx::AS3::Instances::fl::QName::AS3toString(VStr, &resulta);
      Scaleform::GFx::AS3::Value::Assign(result, &resulta);
      pNode = resulta.pNode;
    }
    if ( pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 154
// RVA: 0x781780
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::QName(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::ASString *n,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::QName::`vftable;
  pNode = n->pNode;
  this->LocalName = (Scaleform::GFx::ASString)n->pNode;
  ++pNode->RefCount;
  this->Ns.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 163
// RVA: 0x7D6D70
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->Parent.pObject )
    op(prcc, &this->Parent.pObject);
}

// File Line: 177
// RVA: 0x798E70
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // r9
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rbp
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  const char *pData; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // rcx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v17; // rbx
  Scaleform::GFx::AS3::Value *prefix; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned int v20; // ebx
  Scaleform::GFx::AS3::Value *p_Size; // rcx
  Scaleform::GFx::ASStringNode *pLower; // rbx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::CheckResult v27; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v28; // [rsp+88h] [rbp+20h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  if ( !argc )
  {
    v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
           pVM->StringManagerRef,
           &result);
    pNode = v7->pNode;
    ++v7->pNode->RefCount;
    v9 = this->LocalName.pNode;
    v10 = v9->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    this->LocalName.pNode = pNode;
    goto LABEL_41;
  }
  if ( argc == 1 )
  {
    if ( (argv->Flags & 0x1F) == 0 || Scaleform::GFx::AS3::Value::Convert2String(argv, &v27, &this->LocalName)->Result )
    {
      pData = this->LocalName.pNode->pData;
      if ( *pData == pattern[0] && !pData[1] )
      {
        pObject = this->Ns.pObject;
        if ( pObject )
        {
          if ( ((unsigned __int8)pObject & 1) != 0 )
          {
            this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
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
          this->Ns.pObject = 0i64;
        }
      }
    }
    return;
  }
  v14 = this->Ns.pObject;
  if ( v14 )
  {
    if ( ((unsigned __int8)v14 & 1) != 0 )
    {
      this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v14 - 1);
    }
    else
    {
      v15 = v14->RefCount;
      if ( (v15 & 0x3FFFFF) != 0 )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
    this->Ns.pObject = 0i64;
  }
  v16 = argv->Flags & 0x1F;
  if ( v16 - 12 > 3 && v16 != 10 || argv->value.VS._1.VStr )
  {
    if ( v16 == 11 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)argv->value.VS._1.VStr);
    }
    else if ( Scaleform::GFx::AS3::IsQNameObject(argv) )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->Ns,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&argv->value.VS._1.VStr[1].RefCount);
    }
    else
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        StringManagerRef,
        &result);
      if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v27, &result)->Result )
      {
        v17 = this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject;
        prefix = Scaleform::GFx::AS3::Value::GetUndefined();
        Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
          *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v17[1].RefCount,
          &v28,
          NS_Public,
          &result,
          prefix);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v28.pV);
      }
      v19 = result.pNode;
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    }
  }
  v20 = argv[1].Flags & 0x1F;
  if ( v20 == 11 )
  {
    p_Size = (Scaleform::GFx::AS3::Value *)&argv->value.VS._1.VStr[1].Size;
    goto LABEL_44;
  }
  if ( !Scaleform::GFx::AS3::IsQNameObject(argv + 1) )
  {
    if ( !v20 )
    {
      v24 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
              StringManagerRef,
              &result);
      Scaleform::GFx::ASString::operator=(&this->LocalName, v24);
LABEL_41:
      v25 = result.pNode;
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      return;
    }
    p_Size = argv + 1;
LABEL_44:
    Scaleform::GFx::AS3::Value::Convert2String(p_Size, &v27, &this->LocalName);
    return;
  }
  pLower = argv[1].value.VS._1.VStr[1].pLower;
  ++pLower->RefCount;
  v23 = this->LocalName.pNode;
  v10 = v23->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  this->LocalName.pNode = pLower;
}

// File Line: 284
// RVA: 0x7ECED0
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rcx
  unsigned int v5; // r8d
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v11; // [rsp+58h] [rbp+20h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = ind.Index - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return;
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           StringManagerRef,
           &result,
           "localName");
    Scaleform::GFx::AS3::Value::Assign(name, v6);
    pNode = result.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           StringManagerRef,
           &v11,
           "uri");
    Scaleform::GFx::AS3::Value::Assign(name, v8);
    pNode = v11.pNode;
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 302
// RVA: 0x7ECCB0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::QName::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int v4; // r8d
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx

  v4 = ind.Index - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
      Scaleform::GFx::AS3::Value::Assign(value, &this->LocalName);
  }
  else
  {
    pObject = this->Ns.pObject;
    if ( pObject )
      Scaleform::GFx::AS3::Value::Assign(value, &pObject->Uri);
    else
      Scaleform::GFx::AS3::Value::SetNull(value);
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::QName *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::QName *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 397
// RVA: 0x7F4AC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::QName::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::QName *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // rcx
  unsigned int RefCount; // eax
  int v12; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v15; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v16; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+10h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, Scaleform::GFx::AS3::Classes::fl::QName::ti);
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
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v17;
          if ( ((unsigned __int8)v17 & 1) == 0 )
            goto LABEL_19;
          v17 = (Scaleform::GFx::ASStringNode *)((char *)v17 - 1);
          break;
        case 0x10:
        case 0x11:
          v10 = v18;
          if ( ((unsigned __int8)v18 & 1) != 0 )
          {
            v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v18 - 1);
          }
          else
          {
LABEL_19:
            if ( v10 )
            {
              RefCount = v10->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v10->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
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
void __fastcall Scaleform::GFx::AS3::Classes::fl::QName::Construct(
        Scaleform::GFx::AS3::Classes::fl::QName *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax

  if ( argc == 1
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv),
        ValueTraits->TraitsType == Traits_QName)
    && (ValueTraits->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(_this, argv);
  }
  else
  {
    Scaleform::GFx::AS3::Class::Construct(this, _this, argc, argv, extCall);
  }
}

// File Line: 447
// RVA: 0x7541E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::QName::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::QNameCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::QName::`vftable;
    v6->TraitsType = Traits_QName;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::QNameCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::QName::`vftable;
    v8.pV->TraitsType = Traits_QName;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::QName::`vftable;
  }
  return result;
}

