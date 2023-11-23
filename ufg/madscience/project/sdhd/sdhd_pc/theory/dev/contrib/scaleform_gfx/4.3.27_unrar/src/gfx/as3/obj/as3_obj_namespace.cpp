// File Line: 40
// RVA: 0x7B18C0
void __fastcall Scaleform::GFx::AS3::Value::Assign(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
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
  this->Flags &= 0xFFFFFFEB;
  this->Flags |= 0xBu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 50
// RVA: 0x7B1BA0
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEB;
  this->Flags |= 0xBu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 59
// RVA: 0x8071F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *v)
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
  this->Flags &= 0xFFFFFFEB;
  this->Flags |= 0xBu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
}

// File Line: 117
// RVA: 0x7FEE90
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
        Scaleform::GFx::AS3::NamespaceInstanceFactory *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *pTable; // rbx
  signed __int64 v11; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *SizeMask; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::NamespaceKey v16; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+80h] [rbp+8h] BYREF

  v16.Kind = kind;
  v16.URI = (Scaleform::GFx::ASString)uri->pNode;
  pNode = v16.URI.pNode;
  ++v16.URI.pNode->RefCount;
  pTable = this->NamespaceSet.pTable;
  if ( pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                &this->NamespaceSet,
                &v16,
                pTable->SizeMask & ((unsigned int)kind ^ (unsigned __int64)(4 * (pNode->HashFlags & 0xFFFFFF)))),
        v11 >= 0) )
  {
    SizeMask = (Scaleform::GFx::AS3::Instances::fl::Namespace *)pTable[v11 + 1].SizeMask;
    result->pV = SizeMask;
    if ( SizeMask )
      SizeMask->RefCount = (SizeMask->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
      this->pNamespaceInstanceTraits,
      &resulta,
      kind,
      uri,
      prefix);
    pV = resulta.pV;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      &this->NamespaceSet,
      &this->NamespaceSet,
      &resulta.pV,
      (4 * (resulta.pV->Uri.pNode->HashFlags & 0xFFFFFF)) ^ (unsigned __int64)(unsigned int)((int)(*((_DWORD *)resulta.pV + 10) << 28) >> 28));
    result->pV = pV;
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 197
// RVA: 0x780A00
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const char *uri)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax

  GC = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  *((_QWORD *)this + 5) = *((_QWORD *)this + 5) & 0xFFFFFFFFFFFFFFE0ui64 | kind & 0xF;
  this->VMRef = vm;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    vm->StringManagerRef,
    &this->Uri,
    uri);
  this->pFactory.pObject = 0i64;
  this->Prefix.Flags = 0;
  this->Prefix.Bonus.pWeakProxy = 0i64;
}

// File Line: 214
// RVA: 0x780A90
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::Resource *factory,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rdx

  GC = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  *((_QWORD *)this + 5) = *((_QWORD *)this + 5) & 0xFFFFFFFFFFFFFFE0ui64 | kind & 0xF;
  this->VMRef = vm;
  pNode = uri->pNode;
  this->Uri = (Scaleform::GFx::ASString)uri->pNode;
  ++pNode->RefCount;
  if ( factory )
    Scaleform::Render::RenderBuffer::AddRef(factory);
  this->pFactory.pObject = (Scaleform::GFx::AS3::NamespaceInstanceFactory *)factory;
  this->Prefix.Flags = prefix->Flags;
  this->Prefix.Bonus.pWeakProxy = prefix->Bonus.pWeakProxy;
  this->Prefix.value = prefix->value;
  if ( (prefix->Flags & 0x1F) > 9 )
  {
    if ( (prefix->Flags & 0x200) != 0 )
    {
      ++prefix->Bonus.pWeakProxy->RefCount;
      return;
    }
    if ( (prefix->Flags & 0x1F) == 10 )
    {
      ++prefix->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (prefix->Flags & 0x1F) <= 0xA )
        return;
      if ( (prefix->Flags & 0x1F) <= 0xF )
      {
        VObj = prefix->value.VS._1;
      }
      else
      {
        if ( (prefix->Flags & 0x1F) > 0x11 )
          return;
        VObj = (Scaleform::GFx::AS3::Value::V1U)prefix->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
}

// File Line: 218
// RVA: 0x78CE60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::~Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory *pObject; // rcx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v4; // zf
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *key; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  pObject = this->pFactory.pObject;
  if ( pObject )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::RemoveAlt<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      &pObject->NamespaceSet,
      &key);
  }
  if ( (this->Prefix.Flags & 0x1F) > 9 )
  {
    if ( (this->Prefix.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Prefix.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Prefix.Bonus.pWeakProxy = 0i64;
      this->Prefix.value.VS._1.VStr = 0i64;
      this->Prefix.value.VS._2.VObj = 0i64;
      this->Prefix.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->Prefix);
    }
  }
  v5 = (Scaleform::Render::RenderBuffer *)this->pFactory.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  pNode = this->Uri.pNode;
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 225
// RVA: 0x81EF50
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *VMRef; // rsi
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  VMRef = this->VMRef;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, value);
  if ( ValueTraits->TraitsType != Traits_QName || (ValueTraits->Flags & 0x20) != 0 )
  {
    Scaleform::GFx::AS3::Value::Convert2String(value, (Scaleform::GFx::AS3::CheckResult *)&result, &this->Uri);
  }
  else
  {
    v6 = value->value.VS._1;
    if ( v6.VStr )
    {
      v7 = *(_QWORD *)&v6.VStr[1].RefCount;
      if ( v7 )
      {
        v13 = *(Scaleform::GFx::ASStringNode **)(v7 + 56);
        ++v13->RefCount;
        pNode = this->Uri.pNode;
        v11 = pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        this->Uri.pNode = v13;
      }
      else
      {
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               VMRef->StringManagerRef,
               &result,
               pattern);
        v9 = v8->pNode;
        ++v8->pNode->RefCount;
        v10 = this->Uri.pNode;
        v11 = v10->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        this->Uri.pNode = v9;
        v12 = result.pNode;
        v11 = result.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      }
    }
  }
}

// File Line: 253
// RVA: 0x798810
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char v5; // bl
  Scaleform::GFx::AS3::VM *VMRef; // r14
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value::V1U v14; // rcx
  const char *pData; // rax
  Scaleform::GFx::ASString *v16; // rdx
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // r14
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value::V1U *v21; // rax
  Scaleform::GFx::AS3::Value::V1U v22; // rcx
  unsigned int Flags; // edi
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v27; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v28; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+68h] [rbp-18h] BYREF
  __int64 v30; // [rsp+78h] [rbp-8h]
  Scaleform::GFx::AS3::CheckResult v31; // [rsp+B0h] [rbp+30h] BYREF
  Scaleform::GFx::AS3::CheckResult v32; // [rsp+B8h] [rbp+38h] BYREF
  Scaleform::GFx::ASString v33; // [rsp+C8h] [rbp+48h] BYREF

  v30 = -2i64;
  v5 = 0;
  VMRef = this->VMRef;
  if ( !argc )
  {
    v21 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                                               VMRef->StringManagerRef,
                                               &v27);
    other.Flags = 10;
    other.Bonus.pWeakProxy = 0i64;
    v22 = *v21;
    other.value.VS._1 = v22;
    if ( v22.VStr == &v22.VStr->pManager->NullStringNode )
    {
      other.value.VS._1.VStr = 0i64;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v29.Message.pNode;
      other.Flags = 12;
    }
    else
    {
      ++v22.VStr->RefCount;
    }
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, &other);
    Flags = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    pNode = v27.pNode;
    goto LABEL_42;
  }
  if ( argc != 1 )
  {
    StringManagerRef = VMRef->StringManagerRef;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &result);
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v33);
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v32, &result)->Result
      && Scaleform::GFx::AS3::Value::Convert2String(argv + 1, &v31, &v33)->Result )
    {
      if ( !result.pNode->Size || v33.pNode->Size )
      {
        Scaleform::GFx::AS3::Value::Assign(&this->Prefix, argv);
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, argv + 1);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v29, 1098, VMRef);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v9 = v29.Message.pNode;
        v10 = v29.Message.pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
    }
    v11 = v33.pNode;
    v10 = v33.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    pNode = result.pNode;
LABEL_42:
    v10 = pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  v13 = argv->Flags & 0x1F;
  if ( v13 == 11 )
  {
    Scaleform::GFx::AS3::Instances::fl::Namespace::operator=(this, argv->value.VS._1.VNs);
    return;
  }
  if ( v13 - 12 <= 3 )
  {
    v14 = argv->value.VS._1;
    if ( v14.VStr )
    {
      pData = v14.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 17 && (pData[112] & 0x20) == 0 )
      {
        v16 = *(Scaleform::GFx::ASString **)&v14.VStr[1].RefCount;
        if ( v16 )
        {
          Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v16 + 7);
          return;
        }
        v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                VMRef->StringManagerRef,
                &v28,
                pattern);
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, v17);
        pNode = v28.pNode;
        goto LABEL_42;
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(this, argv);
  v18 = 0;
  if ( (argv->Flags & 0x1F) == 10 )
  {
    v5 = 1;
    if ( !Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(argv, &v26)->pNode->Size )
      v18 = 1;
  }
  if ( (v5 & 1) != 0 )
  {
    v19 = v26.pNode;
    v10 = v26.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( v18 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, argv);
  }
  else
  {
    Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, Undefined);
  }
}

// File Line: 326
// RVA: 0x7908A0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::operator=(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *other)
{
  Scaleform::GFx::ASStringNode *pNode; // rsi
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx

  if ( this != other )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, &other->Prefix);
    pNode = other->Uri.pNode;
    ++pNode->RefCount;
    v5 = this->Uri.pNode;
    if ( v5->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    this->Uri.pNode = pNode;
    *((_QWORD *)this + 5) ^= (*((_DWORD *)this + 10) ^ *((_DWORD *)other + 10)) & 0xF;
    pObject = (Scaleform::GFx::Resource *)other->pFactory.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef(pObject);
    v8 = (Scaleform::Render::RenderBuffer *)this->pFactory.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    this->pFactory.pObject = other->pFactory.pObject;
  }
  return this;
}

// File Line: 339
// RVA: 0x7F9590
bool __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::IsVMPublic(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this)
{
  return this == this->VMRef->PublicNamespace.pObject;
}

// File Line: 344
// RVA: 0x7D5F60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::Value::V2U *v5; // rdx
  Scaleform::GFx::AS3::Value::VU *p_value; // rcx

  Flags = this->Prefix.Flags;
  if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 && (this->Prefix.Flags & 0x1F) >= 0xB )
  {
    if ( (this->Prefix.Flags & 0x1F) <= 0xF )
    {
      p_value = &this->Prefix.value;
      if ( !p_value->VS._1.VStr )
        return;
      v5 = 0i64;
      if ( (Flags & 0x1F) - 11 <= 4 )
        v5 = (Scaleform::GFx::AS3::Value::V2U *)p_value;
      goto LABEL_11;
    }
    if ( (this->Prefix.Flags & 0x1F) <= 0x11 )
    {
      v5 = &this->Prefix.value.VS._2;
      if ( this->Prefix.value.VS._2.VObj )
LABEL_11:
        op(prcc, &v5->VObj);
    }
  }
}

// File Line: 352
// RVA: 0x7ECDF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  unsigned int v5; // r8d
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString *v8; // rax
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v11; // [rsp+58h] [rbp+20h] BYREF

  VMRef = this->VMRef;
  v5 = ind.Index - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return;
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           VMRef->StringManagerRef,
           &result,
           "prefix");
    Scaleform::GFx::AS3::Value::Assign(name, v6);
    pNode = result.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           VMRef->StringManagerRef,
           &v11,
           "uri");
    Scaleform::GFx::AS3::Value::Assign(name, v8);
    pNode = v11.pNode;
  }
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 412
// RVA: 0x1597100
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 418
// RVA: 0x780910
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassInfo *ci)
{
  __int64 v5; // rcx
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v6; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::`vftable;
  this->pNamespaceFactory.pObject = 0i64;
  this->TraitsType = Traits_Namespace;
  v6 = (Scaleform::GFx::AS3::NamespaceInstanceFactory *)((__int64 (__fastcall *)(__int64, __int64))vm->MHeap->vfptr->Alloc)(
                                                          v5,
                                                          32i64);
  if ( v6 )
  {
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v6->RefCount = 1;
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,336>::`vftable;
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS3::NamespaceInstanceFactory,336>::`vftable;
    v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::NamespaceInstanceFactory::`vftable;
    v6->NamespaceSet.pTable = 0i64;
    v6->pNamespaceInstanceTraits = this;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pNamespaceFactory.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pNamespaceFactory.pObject = v6;
}

// File Line: 432
// RVA: 0x75E250
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::prefixGet(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::AS3::Value *)&_this->value.VS._1.VStr[1].Size);
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

// File Line: 468
// RVA: 0x7A7F30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::AS3valueOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)&_this->value.VS._1.VStr[1].16);
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

// File Line: 480
// RVA: 0x760AA0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::valueOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::toStringProto(ti, vm, _this, result, argc, argv);
}

// File Line: 486
// RVA: 0x7614A0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v6; // ecx
  Scaleform::GFx::AS3::Object *VObj; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  v6 = _this->Flags & 0x1F;
  if ( v6 - 12 <= 3 && (VObj = _this->value.VS._1.VObj) != 0i64 )
  {
    pObject = vm->TraitsNamespace.pObject->ITraits.pObject;
    if ( !pObject->pConstructor.pObject )
      pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
    if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
    {
      Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)vm->StringManagerRef);
      return;
    }
  }
  else if ( v6 == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)&_this->value.VS._1.VStr[1].16);
    return;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v12, eUndefinedVarError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v12.Message.pNode;
  if ( v12.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 555
// RVA: 0x7F4520
void __fastcall Scaleform::GFx::AS3::Classes::fl::Namespace::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Namespace *this,
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
  v9 = Scaleform::GFx::AS3::Classes::fl::Namespace::ti;
  v10 = 2i64;
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

// File Line: 571
// RVA: 0x7B8B50
void __fastcall Scaleform::GFx::AS3::Classes::fl::Namespace::Construct(
        Scaleform::GFx::AS3::Classes::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::VM *pVM; // rbp
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *vfptr; // r15
  Scaleform::GFx::ASString *v11; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v15; // [rsp+30h] [rbp-28h] BYREF
  __int64 v16; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h] BYREF

  v16 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( argc == 1
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pObject->pVM, argv),
        ValueTraits->TraitsType == Traits_Namespace)
    && ((unsigned __int8)~(LOBYTE(ValueTraits->Flags) >> 5) & (unsigned __int8)argc) != 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, argv);
  }
  else
  {
    vfptr = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)pObject[1].vfptr;
    v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            pVM->StringManagerRef,
            &resulta);
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(vfptr, &v15, NS_Public, v11, &v);
    pNode = resulta.pNode;
    if ( resulta.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pV = v15.pV;
    Scaleform::GFx::AS3::Value::Pick(result, v15.pV);
    pV->vfptr[1].ForEachChild_GC(
      pV,
      (Scaleform::GFx::AS3::RefCountCollector<328> *)argc,
      (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))argv);
    if ( !pVM->HandleException )
    {
      resulta.pNode = (Scaleform::GFx::ASStringNode *)pV;
      Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
        &vfptr->pNamespaceFactory.pObject->NamespaceSet,
        &vfptr->pNamespaceFactory.pObject->NamespaceSet,
        (Scaleform::GFx::AS3::Instances::fl::Namespace **)&resulta,
        (4 * (pV->Uri.pNode->HashFlags & 0xFFFFFF)) ^ (unsigned __int64)(unsigned int)((int)(*((_DWORD *)pV + 10) << 28) >> 28));
    }
  }
}

// File Line: 622
// RVA: 0x766D90
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Namespace::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::NamespaceCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Namespace::`vftable;
    v6->TraitsType = Traits_Namespace;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)MHeap->vfptr->Alloc(MHeap, 248ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::Namespace(v8, vm, &Scaleform::GFx::AS3::fl::NamespaceCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Namespace::`vftable;
  }
  return result;
}

// File Line: 636
// RVA: 0x7B6940
_BOOL8 __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Namespace::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::Namespace *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  char v8; // [rsp+20h] [rbp-18h]

  pObject = this->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(this->ITraits.pObject);
  v8 = 0;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, __int64, Scaleform::GFx::AS3::Value *, char))pObject->pConstructor.pObject->Scaleform::GFx::AS3::Traits::vfptr[4].ForEachChild_GC)(
    pObject->pConstructor.pObject,
    result,
    1i64,
    value,
    v8);
  return !this->pVM->HandleException;
}

