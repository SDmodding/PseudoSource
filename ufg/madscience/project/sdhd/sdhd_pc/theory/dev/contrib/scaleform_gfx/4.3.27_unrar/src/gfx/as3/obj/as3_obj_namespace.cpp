// File Line: 40
// RVA: 0x7B18C0
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rdi
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
  v2->Flags &= 0xFFFFFFEB;
  v2->Flags |= 0xBu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 50
// RVA: 0x7B1BA0
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEB;
  this->Flags |= 0xBu;
  *(_QWORD *)&this->value.VNumber = v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 59
// RVA: 0x8071F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Instances::fl::Namespace *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rdi
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
  v2->Flags &= 0xFFFFFFEB;
  v2->Flags |= 0xBu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
}

// File Line: 117
// RVA: 0x7FEE90
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(Scaleform::GFx::AS3::NamespaceInstanceFactory *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::GFx::ASString *uri, Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::ASString *v5; // r15
  Scaleform::GFx::AS3::Abc::NamespaceKind v6; // ebp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // rsi
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v8; // r13
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> >::TableType *v10; // rbx
  signed __int64 v11; // rax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v12; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rbx
  bool v14; // zf
  Scaleform::GFx::AS3::Abc::NamespaceKind v16; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+40h] [rbp-38h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> resulta; // [rsp+80h] [rbp+8h]

  v5 = uri;
  v6 = kind;
  v7 = result;
  v8 = this;
  v16 = kind;
  v17 = uri->pNode;
  v9 = v17;
  ++v9->RefCount;
  v10 = this->NamespaceSet.pTable;
  if ( v10
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::findIndexCore<Scaleform::GFx::AS3::NamespaceKey>(
                (Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&this->NamespaceSet.pTable,
                (Scaleform::GFx::AS3::NamespaceKey *)&v16,
                v10->SizeMask & ((unsigned int)kind ^ (unsigned __int64)(4 * (v9->HashFlags & 0xFFFFFF)))),
        v11 >= 0) )
  {
    v12 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v10[v11 + 1].SizeMask;
    v7->pV = v12;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
      v8->pNamespaceInstanceTraits,
      &resulta,
      v6,
      v5,
      prefix);
    v13 = resulta.pV;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      (Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&v8->NamespaceSet.pTable,
      &v8->NamespaceSet,
      &resulta.pV,
      4 * (resulta.pV->Uri.pNode->HashFlags & 0xFFFFFF) ^ (unsigned __int64)(unsigned int)(*((_QWORD *)resulta.pV + 5) << 60 >> 60));
    v7->pV = v13;
  }
  v14 = v9->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v7;
}

// File Line: 197
// RVA: 0x780A00
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Abc::NamespaceKind kind, const char *uri)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v5; // rax

  v4 = this;
  v5 = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v5;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  *((_QWORD *)v4 + 5) = *((_QWORD *)v4 + 5) & 0xFFFFFFFFFFFFFFE0ui64 | kind & 0xF;
  this->VMRef = vm;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &this->Uri,
    uri);
  v4->pFactory.pObject = 0i64;
  v4->Prefix.Flags = 0;
  v4->Prefix.Bonus.pWeakProxy = 0i64;
}

// File Line: 214
// RVA: 0x780A90
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::NamespaceInstanceFactory *factory, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::GFx::ASString *uri, Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  signed int v10; // eax
  long double v11; // rdx

  v6 = factory;
  v7 = this;
  v8 = vm->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v8;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  *((_QWORD *)v7 + 5) = *((_QWORD *)v7 + 5) & 0xFFFFFFFFFFFFFFE0ui64 | kind & 0xF;
  this->VMRef = vm;
  v9 = uri->pNode;
  v7->Uri = (Scaleform::GFx::ASString)uri->pNode;
  ++v9->RefCount;
  if ( factory )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)factory);
  v7->pFactory.pObject = v6;
  v7->Prefix.Flags = prefix->Flags;
  v7->Prefix.Bonus.pWeakProxy = prefix->Bonus.pWeakProxy;
  v7->Prefix.value = prefix->value;
  v10 = prefix->Flags & 0x1F;
  if ( v10 > 9 )
  {
    if ( (prefix->Flags >> 9) & 1 )
    {
      ++prefix->Bonus.pWeakProxy->RefCount;
      return;
    }
    if ( v10 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&prefix->value.VNumber + 24i64);
    }
    else
    {
      if ( v10 <= 10 )
        return;
      if ( v10 <= 15 )
      {
        v11 = prefix->value.VNumber;
      }
      else
      {
        if ( v10 > 17 )
          return;
        v11 = *(double *)&prefix->value.VS._2.VObj;
      }
      if ( v11 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
}

// File Line: 218
// RVA: 0x78CE60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::~Namespace(Scaleform::GFx::AS3::Instances::fl::Namespace *this)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v1; // rdi
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v2; // rcx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *key; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable;
  v2 = this->pFactory.pObject;
  if ( v2 )
  {
    key = v1;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::RemoveAlt<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
      (Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&v2->NamespaceSet.pTable,
      &key);
  }
  if ( (v1->Prefix.Flags & 0x1F) > 9 )
  {
    if ( (v1->Prefix.Flags >> 9) & 1 )
    {
      v3 = v1->Prefix.Bonus.pWeakProxy;
      v4 = v3->RefCount-- == 1;
      if ( v4 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v1->Prefix.Bonus.pWeakProxy = 0i64;
      v1->Prefix.value.VNumber = 0.0;
      v1->Prefix.value.VS._2.VObj = 0i64;
      v1->Prefix.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->Prefix);
    }
  }
  v5 = (Scaleform::Render::RenderBuffer *)v1->pFactory.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = v1->Uri.pNode;
  v4 = v6->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 225
// RVA: 0x81EF50
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::Traits *v5; // rax
  long double v6; // rax
  __int64 v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = value;
  v3 = this;
  v4 = this->VMRef;
  v5 = Scaleform::GFx::AS3::VM::GetValueTraits(this->VMRef, value);
  if ( v5->TraitsType == 17 && ~(LOBYTE(v5->Flags) >> 5) & 1 )
  {
    v6 = v2->value.VNumber;
    if ( v6 != 0.0 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)&v6 + 64i64);
      if ( v7 )
      {
        v12 = *(Scaleform::GFx::ASStringNode **)(v7 + 56);
        ++v12->RefCount;
        v13 = v3->Uri.pNode;
        v10 = v13->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        v3->Uri.pNode = v12;
      }
      else
      {
        v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
               &result,
               pattern)->pNode;
        ++v8->RefCount;
        v9 = v3->Uri.pNode;
        v10 = v9->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        v3->Uri.pNode = v8;
        v11 = result.pNode;
        v10 = result.pNode->RefCount == 1;
        --v11->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Convert2String(v2, (Scaleform::GFx::AS3::CheckResult *)&result, &v3->Uri);
  }
}

// File Line: 253
// RVA: 0x798810
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::AS3Constructor(Scaleform::GFx::AS3::Instances::fl::Namespace *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rsi
  char v5; // bl
  Scaleform::GFx::AS3::VM *v6; // r14
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  unsigned int v13; // eax
  long double v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::ASString *v16; // rdx
  Scaleform::GFx::ASString *v17; // rax
  bool v18; // r14
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value *v20; // rax
  long double *v21; // rax
  long double v22; // rcx
  unsigned int v23; // edi
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::ASString v26; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::ASString v27; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::ASString v28; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+68h] [rbp-18h]
  __int64 v30; // [rsp+78h] [rbp-8h]
  Scaleform::GFx::AS3::CheckResult v31; // [rsp+B0h] [rbp+30h]
  Scaleform::GFx::AS3::CheckResult v32; // [rsp+B8h] [rbp+38h]
  Scaleform::GFx::ASString v33; // [rsp+C8h] [rbp+48h]

  v30 = -2i64;
  v3 = argv;
  v4 = this;
  v5 = 0;
  v6 = this->VMRef;
  if ( !argc )
  {
    v21 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
                           &v27);
    other.Flags = 10;
    other.Bonus.pWeakProxy = 0i64;
    v22 = *v21;
    other.value.VNumber = v22;
    if ( *(_QWORD *)&v22 == *(_QWORD *)(*(_QWORD *)&v22 + 8i64) + 104i64 )
    {
      other.value.VNumber = 0.0;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v29.Message.pNode;
      other.Flags = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v22 + 24i64);
    }
    Scaleform::GFx::AS3::Value::Assign(&v4->Prefix, &other);
    v23 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v23 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    v12 = v27.pNode;
    goto LABEL_42;
  }
  if ( argc != 1 )
  {
    v7 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
      &result);
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v7, &v33);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v3, &v32, &result)->Result
      && Scaleform::GFx::AS3::Value::Convert2String(v3 + 1, &v31, &v33)->Result )
    {
      if ( !result.pNode->Size || v33.pNode->Size )
      {
        Scaleform::GFx::AS3::Value::Assign(&v4->Prefix, v3);
        Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(v4, v3 + 1);
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v29, eXMLNamespaceWithPrefixAndNoURI, v6);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
        v9 = v29.Message.pNode;
        v10 = v29.Message.pNode->RefCount == 1;
        --v9->RefCount;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      }
    }
    v11 = v33.pNode;
    v10 = v33.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v12 = result.pNode;
LABEL_42:
    v10 = v12->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
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
    v14 = argv->value.VNumber;
    if ( v14 != 0.0 )
    {
      v15 = *(_QWORD *)(*(_QWORD *)&v14 + 40i64);
      if ( *(_DWORD *)(v15 + 120) == 17 )
      {
        if ( ~(*(_BYTE *)(v15 + 112) >> 5) & 1 )
        {
          v16 = *(Scaleform::GFx::ASString **)(*(_QWORD *)&v14 + 64i64);
          if ( v16 )
          {
            Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(v4, v16 + 7);
            return;
          }
          v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->StringManagerRef->Builtins,
                  &v28,
                  pattern);
          Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(v4, v17);
          v12 = v28.pNode;
          goto LABEL_42;
        }
      }
    }
  }
  Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(v4, argv);
  v18 = 0;
  if ( (v3->Flags & 0x1F) == 10 )
  {
    v5 = 1;
    if ( !Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v3, &v26)->pNode->Size )
      v18 = 1;
  }
  if ( v5 & 1 )
  {
    v19 = v26.pNode;
    v10 = v26.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
  if ( v18 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v4->Prefix, v3);
  }
  else
  {
    v20 = Scaleform::GFx::AS3::Value::GetUndefined();
    Scaleform::GFx::AS3::Value::Assign(&v4->Prefix, v20);
  }
}

// File Line: 326
// RVA: 0x7908A0
Scaleform::GFx::AS3::Instances::fl::Namespace *__fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::operator=(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::Instances::fl::Namespace *other)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::Resource *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx

  v2 = other;
  v3 = this;
  if ( this != other )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Prefix, &other->Prefix);
    v4 = v2->Uri.pNode;
    ++v4->RefCount;
    v5 = v3->Uri.pNode;
    v6 = v5->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v3->Uri.pNode = v4;
    *((_QWORD *)v3 + 5) ^= (*((_DWORD *)v3 + 10) ^ *((_DWORD *)v2 + 10)) & 0xF;
    v7 = (Scaleform::GFx::Resource *)v2->pFactory.pObject;
    if ( v7 )
      Scaleform::Render::RenderBuffer::AddRef(v7);
    v8 = (Scaleform::Render::RenderBuffer *)v3->pFactory.pObject;
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    v3->pFactory.pObject = v2->pFactory.pObject;
  }
  return v3;
}

// File Line: 339
// RVA: 0x7F9590
bool __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::IsVMPublic(Scaleform::GFx::AS3::Instances::fl::Namespace *this)
{
  return this == this->VMRef->PublicNamespace.pObject;
}

// File Line: 344
// RVA: 0x7D5F60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v3; // r10
  signed int v4; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v5; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rdx

  v3 = prcc;
  v4 = this->Prefix.Flags & 0x1F;
  if ( v4 > 10 && !((this->Prefix.Flags >> 9) & 1) && v4 >= 11 )
  {
    if ( v4 <= 15 )
    {
      v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Prefix.value;
      if ( *v5 )
      {
        v6 = 0i64;
        if ( (unsigned int)(v4 - 11) <= 4 )
          v6 = v5;
        op(v3, v6);
      }
    }
    else if ( v4 <= 17 )
    {
      if ( this->Prefix.value.VS._2.VObj )
        op(prcc, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Prefix.value.VS._2.VObj);
    }
  }
}

// File Line: 352
// RVA: 0x7ECDF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rcx
  unsigned int v5; // er8
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString *v8; // rax
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString v11; // [rsp+58h] [rbp+20h]

  v3 = name;
  v4 = this->VMRef;
  v5 = ind.Index - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return;
    v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
           &result,
           "prefix");
    Scaleform::GFx::AS3::Value::Assign(v3, v6);
    v7 = result.pNode;
  }
  else
  {
    v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
           &v11,
           "uri");
    Scaleform::GFx::AS3::Value::Assign(v3, v8);
    v7 = v11.pNode;
  }
  v9 = v7->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::Namespace(Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rbx
  Scaleform::Render::RenderBuffer *v7; // rcx

  v3 = vm;
  v4 = this;
  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
    (Scaleform::GFx::AS3::InstanceTraits::CTraits *)&this->vfptr,
    vm,
    ci);
  v4->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  v4->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::`vftable;
  v4->pNamespaceFactory.pObject = 0i64;
  v4->TraitsType = 6;
  v6 = ((__int64 (__fastcall *)(__int64, signed __int64))v3->MHeap->vfptr->Alloc)(v5, 32i64);
  if ( v6 )
  {
    *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v6 + 8) = 1;
    *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,336>::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::GFx::AS3::NamespaceInstanceFactory,336>::`vftable;
    *(_QWORD *)v6 = &Scaleform::GFx::AS3::NamespaceInstanceFactory::`vftable;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 24) = v4;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::Render::RenderBuffer *)v4->pNamespaceFactory.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v4->pNamespaceFactory.pObject = (Scaleform::GFx::AS3::NamespaceInstanceFactory *)v6;
}

// File Line: 432
// RVA: 0x75E250
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::prefixGet(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v4 = vm;
  if ( (_this->Flags & 0x1F) == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::AS3::Value *)(*(_QWORD *)&_this->value.VNumber + 72i64));
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 468
// RVA: 0x7A7F30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::AS3valueOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v4 = vm;
  if ( (_this->Flags & 0x1F) == 11 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)(*(_QWORD *)&_this->value.VNumber + 56i64));
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 480
// RVA: 0x760AA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::valueOfProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::toStringProto(ti, vm, _this, result, argc, argv);
}

// File Line: 486
// RVA: 0x7614A0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // rdi
  unsigned int v6; // ecx
  long double v7; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rbx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h]

  v4 = result;
  v5 = vm;
  v6 = _this->Flags & 0x1F;
  if ( v6 - 12 > 3 || (v7 = _this->value.VNumber, v7 == 0.0) )
  {
    if ( v6 == 11 )
    {
      Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)(*(_QWORD *)&_this->value.VNumber + 56i64));
      return;
    }
  }
  else
  {
    v8 = vm->TraitsNamespace.pObject->ITraits.pObject;
    if ( !v8->pConstructor.pObject )
      v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
    if ( *(Scaleform::GFx::AS3::Object **)&v7 == Scaleform::GFx::AS3::Class::GetPrototype(v8->pConstructor.pObject) )
    {
      Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::ASString *)v5->StringManagerRef);
      return;
    }
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v12, eUndefinedVarError, v5);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v10 = v12.Message.pNode;
  v11 = v12.Message.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 555
// RVA: 0x7F4520
void __fastcall Scaleform::GFx::AS3::Classes::fl::Namespace::InitPrototype(Scaleform::GFx::AS3::Classes::fl::Namespace *this, Scaleform::GFx::AS3::Object *obj)
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
  v5 = Scaleform::GFx::AS3::Classes::fl::Namespace::ti;
  v6 = 2i64;
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

// File Line: 571
// RVA: 0x7B8B50
void __fastcall Scaleform::GFx::AS3::Classes::fl::Namespace::Construct(Scaleform::GFx::AS3::Classes::fl::Namespace *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  unsigned int v5; // er14
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Traits *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rbp
  Scaleform::GFx::AS3::Traits *v9; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v10; // r15
  Scaleform::GFx::ASString *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v15; // [rsp+30h] [rbp-28h]
  __int64 v16; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+8h]

  v16 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this->pTraits.pObject;
  v8 = v7->pVM;
  if ( argc == 1
    && (v9 = Scaleform::GFx::AS3::VM::GetValueTraits(v7->pVM, argv), v9->TraitsType == 6)
    && (unsigned __int8)~(LOBYTE(v9->Flags) >> 5) & (unsigned __int8)v5 )
  {
    Scaleform::GFx::AS3::Value::Assign(v6, v4);
  }
  else
  {
    v10 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v7[1].vfptr;
    v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins,
            &resulta);
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(v10, &v15, 0, v11, &v);
    v12 = resulta.pNode;
    v13 = resulta.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v14 = (Scaleform::GFx::ASStringNode *)v15.pV;
    Scaleform::GFx::AS3::Value::Pick(v6, v15.pV);
    (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, _QWORD, Scaleform::GFx::AS3::Value *))v14->pData + 3))(
      v14,
      v5,
      v4);
    if ( !v8->HandleException )
    {
      resulta.pNode = v14;
      Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc>>::add<Scaleform::GFx::AS3::Instances::fl::Namespace *>(
        (Scaleform::HashSetBase<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl::Namespace *,2>,Scaleform::HashsetEntry<Scaleform::GFx::AS3::Instances::fl::Namespace *,Scaleform::GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc> > *)&v10->pNamespaceFactory.pObject->NamespaceSet.pTable,
        &v10->pNamespaceFactory.pObject->NamespaceSet,
        (Scaleform::GFx::AS3::Instances::fl::Namespace *const *)&resulta,
        4 * (v14[1].pLower->HashFlags & 0xFFFFFF) ^ (unsigned __int64)(unsigned int)((_QWORD)v14[1].pData << 60 >> 60));
    }
  }
}

// File Line: 622
// RVA: 0x766D90
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Namespace::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::NamespaceCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Namespace::`vftable;
    v6->TraitsType = 6;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v4->vfptr->Alloc(v4, 248ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::Namespace(v8, v2, &Scaleform::GFx::AS3::fl::NamespaceCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                        v4,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, v3->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Namespace::`vftable;
  }
  return v3;
}

// File Line: 636
// RVA: 0x7B6940
_BOOL8 __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Namespace::Coerce(Scaleform::GFx::AS3::ClassTraits::fl::Namespace *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rbp
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v6; // rdi
  char v7; // ST20_1

  v3 = this->ITraits.pObject;
  v4 = result;
  v5 = value;
  v6 = this;
  if ( !v3->pConstructor.pObject )
    v3->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&this->ITraits.pObject->vfptr);
  v7 = 0;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, signed __int64, Scaleform::GFx::AS3::Value *, char))v3->pConstructor.pObject->vfptr[4].ForEachChild_GC)(
    v3->pConstructor.pObject,
    v4,
    1i64,
    v5,
    v7);
  return v6->pVM->HandleException == 0;
}

