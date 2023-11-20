// File Line: 117
// RVA: 0x7AE460
void __fastcall Scaleform::GFx::AS3::Value::AddRefInternal(Scaleform::GFx::AS3::Value *this)
{
  signed int v1; // eax
  long double v2; // rdx

  v1 = this->Flags & 0x1F;
  if ( v1 == 10 )
  {
    ++*(_DWORD *)(*(_QWORD *)&this->value.VNumber + 24i64);
  }
  else
  {
    if ( v1 <= 10 )
      return;
    if ( v1 <= 15 )
    {
      v2 = this->value.VNumber;
    }
    else
    {
      if ( v1 > 17 )
        return;
      v2 = *(double *)&this->value.VS._2.VObj;
    }
    if ( v2 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v2 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v2 + 32i64) + 1) & 0x8FBFFFFF;
  }
}

// File Line: 155
// RVA: 0x7AE4A0
void __fastcall Scaleform::GFx::AS3::Value::AddRefWeakRef(Scaleform::GFx::AS3::Value *this)
{
  ++this->Bonus.pWeakProxy->RefCount;
}

// File Line: 161
// RVA: 0x811210
void __fastcall Scaleform::GFx::AS3::Value::ReleaseWeakRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::WeakProxy *v1; // rdx
  Scaleform::GFx::AS3::Value *v2; // rbx
  bool v3; // zf

  v1 = this->Bonus.pWeakProxy;
  v2 = this;
  v3 = v1->RefCount-- == 1;
  if ( v3 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v2->Flags &= 0xFFFFFDE0;
  v2->Bonus.pWeakProxy = 0i64;
  v2->value.VNumber = 0.0;
  v2->value.VS._2.VObj = 0i64;
}

// File Line: 175
// RVA: 0x810F60
void __fastcall Scaleform::GFx::AS3::Value::ReleaseInternal(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::ASStringNode *v1; // rcx
  bool v2; // zf
  long double v3; // rdx
  int v4; // eax

  switch ( this->Flags & 0x1F )
  {
    case 0xAu:
      v1 = this->value.VS._1.VStr;
      v2 = v1->RefCount-- == 1;
      if ( v2 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v1);
      break;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      v3 = this->value.VNumber;
      if ( !(LOBYTE(v3) & 1) )
        goto LABEL_8;
      *(_QWORD *)&this->value.VNumber = *(_QWORD *)&v3 - 1i64;
      break;
    case 0x10u:
    case 0x11u:
      v3 = *(double *)&this->value.VS._2.VObj;
      if ( LOBYTE(v3) & 1 )
      {
        this->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(*(_QWORD *)&v3 - 1i64);
      }
      else
      {
LABEL_8:
        if ( v3 != 0.0 )
        {
          v4 = *(_DWORD *)(*(_QWORD *)&v3 + 32i64);
          if ( v4 & 0x3FFFFF )
          {
            *(_DWORD *)(*(_QWORD *)&v3 + 32i64) = v4 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3);
          }
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 242
// RVA: 0x7BA110
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASStringManager *sm, Scaleform::GFx::AS3::Value *a4, Scaleform::GFx::AS3::Value::Hint hint)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  Scaleform::GFx::AS3::Value *v6; // rbx
  signed int v7; // edx
  long double v8; // rcx
  Scaleform::GFx::AS3::CheckResult *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::AS3::Value::V2U v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]

  v5 = result;
  v6 = a4;
  v7 = this->Flags & 0x1F;
  if ( v7 <= 4 || v7 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(a4, this);
  }
  else
  {
    if ( !((v7 - 5) & 0xFFFFFFFD) )
      goto LABEL_20;
    if ( v7 == 11 )
    {
      Scaleform::GFx::AS3::Value::Assign(a4, (Scaleform::GFx::ASString *)(*(_QWORD *)&this->value.VNumber + 56i64));
      v5->Result = 1;
      return v5;
    }
    if ( (unsigned int)(v7 - 16) <= 1 )
    {
LABEL_20:
      Scaleform::GFx::AS3::Value::SetNumber(a4, 0.0);
      v5->Result = 1;
      return v5;
    }
    v8 = this->value.VNumber;
    if ( v8 == 0.0 )
    {
      if ( (signed int)hint >= 0 )
      {
        if ( (signed int)hint <= 1 )
        {
          a4->Flags &= 0xFFFFFFE4;
          a4->Flags |= 4u;
          v5->Result = 1;
          v9 = v5;
          a4->value.VNumber = 0.0;
          a4->value.VS._2 = v11;
          return v9;
        }
        if ( hint == 2 )
        {
          v10 = Scaleform::GFx::ASStringManager::CreateConstStringNode(sm, "null", 4ui64, 0);
          Scaleform::GFx::AS3::Value::AssignUnsafe(v6, v10);
          v5->Result = 1;
          return v5;
        }
      }
    }
    else if ( !Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(
                 *(Scaleform::GFx::AS3::Object **)&v8,
                 &resulta,
                 a4,
                 hint)->Result )
    {
      v5->Result = 0;
      return v5;
    }
  }
  v5->Result = 1;
  return v5;
}

// File Line: 323
// RVA: 0x7BA270
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *a3)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  signed int v4; // edx
  long double v5; // rcx
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = this->Flags & 0x1F;
  if ( v4 <= 4 || v4 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(a3, this);
  }
  else
  {
    if ( !((v4 - 5) & 0xFFFFFFFD) )
      goto LABEL_16;
    if ( v4 == 11 )
    {
      Scaleform::GFx::AS3::Value::Assign(a3, (Scaleform::GFx::ASString *)(*(_QWORD *)&this->value.VNumber + 56i64));
      v3->Result = 1;
      return v3;
    }
    if ( (unsigned int)(v4 - 16) <= 1 )
    {
LABEL_16:
      Scaleform::GFx::AS3::Value::SetNumber(a3, 0.0);
      v3->Result = 1;
      return v3;
    }
    v5 = this->value.VNumber;
    if ( v5 == 0.0 )
    {
      a3->Flags &= 0xFFFFFFE4;
      a3->Flags |= 4u;
      v3->Result = 1;
      v6 = v3;
      a3->value.VNumber = 0.0;
      a3->value.VS._2 = v7;
      return v6;
    }
    if ( !Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(
            *(Scaleform::GFx::AS3::Object **)&v5,
            &resulta,
            a3,
            hintNumber)->Result )
    {
      v3->Result = 0;
      return v3;
    }
  }
  v3->Result = 1;
  return v3;
}

// File Line: 371
// RVA: 0x7BF930
Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> *__fastcall Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(Scaleform::GFx::AS3::GASRefCountBase *this, Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> *v2; // r14
  Scaleform::GFx::AS3::GASRefCountBase *v3; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *v4; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v5; // r9
  signed __int64 v6; // rbx
  signed __int64 v7; // rdi
  signed __int64 v8; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // rax
  signed __int64 v11; // r8
  signed __int64 v12; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v13; // rcx
  signed __int64 v14; // rax
  Scaleform::GFx::AS3::WeakProxy *v15; // rax
  __int64 v16; // rax
  unsigned __int64 v17; // rax
  Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeRef key; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::GASRefCountBase *v20; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::GASRefCountBase *v21; // [rsp+80h] [rbp+18h]
  Scaleform::GFx::AS3::WeakProxy *v22; // [rsp+88h] [rbp+20h]

  v20 = this;
  v2 = result;
  v3 = this;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)(this->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64);
  v22 = 0i64;
  v21 = this;
  v5 = v4[17].pTable;
  v6 = 5381i64;
  v7 = 8i64;
  if ( v5 )
  {
    v8 = 5381i64;
    v9 = 8i64;
    do
    {
      v10 = 65599 * v8 + *((unsigned __int8 *)&v21 + --v9);
      v8 = 65599 * v8 + *((unsigned __int8 *)&v21 + v9);
    }
    while ( v9 );
    v11 = v10 & v5->SizeMask;
    v12 = v10 & v5->SizeMask;
    v13 = &v5[2 * (v10 & v5->SizeMask) + 1];
    if ( v13->EntryCount != -2i64 && v13->SizeMask == v11 )
    {
      while ( v13->SizeMask != v11 || (Scaleform::GFx::AS3::GASRefCountBase *)v13[1].EntryCount != v3 )
      {
        v12 = v13->EntryCount;
        if ( v13->EntryCount == -1i64 )
          goto LABEL_13;
        v13 = &v5[2 * v12 + 1];
      }
      if ( v12 >= 0 )
      {
        v14 = (signed __int64)&v5[2 * (v12 + 1)];
        if ( v14 )
        {
          v15 = *(Scaleform::GFx::AS3::WeakProxy **)(v14 + 8);
          v22 = v15;
LABEL_20:
          ++v15->RefCount;
          v2->pV = v22;
          return v2;
        }
      }
    }
  }
LABEL_13:
  LODWORD(v21) = 328;
  v16 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::GASRefCountBase *, signed __int64, Scaleform::GFx::AS3::GASRefCountBase **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
          Scaleform::Memory::pGlobalHeap,
          v3,
          16i64,
          &v21,
          -2i64);
  key.pFirst = (Scaleform::GFx::AS3::GASRefCountBase *const *)v16;
  if ( v16 )
  {
    *(_DWORD *)v16 = 1;
    *(_QWORD *)(v16 + 8) = v3;
  }
  v22 = (Scaleform::GFx::AS3::WeakProxy *)v16;
  if ( v16 )
  {
    v3->RefCount |= 0x4000000u;
    v20 = v3;
    key.pFirst = &v20;
    key.pSecond = &v22;
    do
    {
      v17 = 65599 * v6 + *((unsigned __int8 *)&v20 + --v7);
      v6 = 65599 * v6 + *((unsigned __int8 *)&v20 + v7);
    }
    while ( v7 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeRef>(
      v4 + 17,
      &v4[17],
      &key,
      v17);
    v15 = v22;
    goto LABEL_20;
  }
  v2->pV = 0i64;
  return v2;
}17],
      &key,
      v17);
    v15 = v22;
    goto LABEL_20;
  }

// File Line: 395
// RVA: 0x7D5FC0
void __fastcall Scaleform::GFx::AS3::NamespaceSet::ForEachChild_GC(Scaleform::GFx::AS3::NamespaceSet *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbx
  void (__fastcall *v5)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::GFx::AS3::RefCountCollector<328> *v6; // r14
  Scaleform::GFx::AS3::NamespaceSet *v7; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v8; // rdx

  v3 = this->Namespaces.Data.Size;
  v4 = 0i64;
  v5 = op;
  v6 = prcc;
  v7 = this;
  if ( v3 )
  {
    do
    {
      v8 = &v7->Namespaces.Data.Data[v4];
      if ( v8->pObject )
        v5(v6, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v8);
      ++v4;
    }
    while ( v4 < v3 );
  }
}

// File Line: 416
// RVA: 0x780020
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::GFx::AS3::Multiname *v3; // rsi
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v2 = vm;
  v3 = this;
  this->Kind = 0;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v4 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
         &result);
  Scaleform::GFx::AS3::Value::Assign(&v3->Name, v4);
  v5 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->Obj,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v2->DefXMLNamespace.pObject);
  if ( !v3->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v2->PublicNamespace.pObject);
}

// File Line: 428
// RVA: 0x7800C0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VM *v3; // rsi
  Scaleform::GFx::AS3::Multiname *v4; // rdi
  unsigned int v5; // edx
  long double v6; // rbp
  __int64 v7; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  __int64 v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+80h] [rbp+18h]
  Scaleform::GFx::ASString v18; // [rsp+88h] [rbp+20h]

  v3 = vm;
  v4 = this;
  this->Kind = 0;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v5 = v->Flags & 0x1F;
  if ( v5 - 2 <= 2 || v5 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v);
    if ( (v4->Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v4->Name, (Scaleform::GFx::ASString *)&result);
      v12 = *(_QWORD *)&result.Result;
      if ( *(_DWORD *)(*(_QWORD *)&result.Result + 32i64) )
      {
        if ( ***(_BYTE ***)&result.Result == 64 )
        {
          v4->Kind |= 8u;
          v13 = Scaleform::GFx::ASString::Substring((Scaleform::GFx::ASString *)&result, &v18, 1, *(_DWORD *)(v12 + 32));
          Scaleform::GFx::AS3::Value::Assign(&v4->Name, v13);
          v14 = v18.pNode;
          v10 = v18.pNode->RefCount == 1;
          --v14->RefCount;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        }
      }
      v15 = *(Scaleform::GFx::ASStringNode **)&result.Result;
      v10 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
      --v15->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
  }
  else
  {
    if ( v5 - 12 <= 3 )
    {
      v6 = v->value.VNumber;
      if ( v6 != 0.0 )
      {
        v7 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64);
        if ( *(_DWORD *)(v7 + 120) == 17 )
        {
          if ( ~(*(_BYTE *)(v7 + 112) >> 5) & 1 )
          {
            Scaleform::GFx::AS3::Value::Assign(&this->Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v6 + 56i64));
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Obj,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v6 + 64i64));
            v4->Kind &= 0xFFFFFFF9;
            return;
          }
        }
      }
    }
    if ( v5 - 12 > 3 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eInvalidArgumentError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_11:
      v9 = v16.Message.pNode;
      v10 = v16.Message.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      return;
    }
    if ( !*(_QWORD *)&v->value.VNumber )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, eNotImplementedError, v3);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      goto LABEL_11;
    }
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v);
    if ( !Scaleform::GFx::AS3::Value::ToStringValue(&v4->Name, &result, v3->StringManagerRef)->Result )
      return;
    Scaleform::GFx::AS3::Multiname::PostProcessName(v4, 0);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Obj,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->DefXMLNamespace.pObject);
  if ( !v4->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->PublicNamespace.pObject);
}

// File Line: 474
// RVA: 0x77FFD0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, Scaleform::GFx::AS3::Value *name)
{
  this->Kind = 0;
  this->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&ns->vfptr;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(this, name);
}

// File Line: 491
// RVA: 0x7802E0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VMFile *file, Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Abc::Multiname *v3; // rdi
  Scaleform::GFx::AS3::VMFile *v4; // rbp
  Scaleform::GFx::AS3::Multiname *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // rax
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v3 = mn;
  v4 = file;
  v5 = this;
  this->Kind = mn->Kind;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  if ( *(_QWORD *)&mn->NameIndex || mn->Ind )
  {
    v6 = Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, mn->NameIndex);
    Scaleform::GFx::AS3::Value::Assign(&v5->Name, v6);
    v7 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    Scaleform::GFx::AS3::Multiname::PostProcessName(v5, 0);
  }
  v9 = v3->Kind & 3;
  if ( v9 > 1 || v9 == 1 )
  {
    if ( v9 != 2 )
      return;
    v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                           v4,
                                                           v3->Ind);
  }
  else
  {
    if ( !v3->Ind )
      return;
    v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v4, v3->Ind);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v5->Obj,
    v10);
}

// File Line: 514
// RVA: 0x780690
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VM *vm, Scaleform::StringDataPtr *qname)
{
  Scaleform::StringDataPtr *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rbp
  Scaleform::GFx::AS3::Multiname *v5; // rdi
  char v6; // r15
  signed __int64 v7; // r9
  signed __int64 v8; // rax
  unsigned __int64 v9; // r12
  const char *v10; // r13
  unsigned __int64 v11; // r12
  Scaleform::GFx::ASString *v12; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v14; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v25; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h]

  v3 = qname;
  v4 = vm;
  v5 = this;
  this->Kind = 0;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v6 = 1;
  v7 = Scaleform::StringDataPtr::FindLastChar(qname, 58, 0xFFFFFFFFFFFFFFFFui64);
  if ( v7 < 0 )
  {
    v6 = 0;
    v7 = Scaleform::StringDataPtr::FindLastChar(v3, 46, 0xFFFFFFFFFFFFFFFFui64);
  }
  v8 = v7 + 1;
  v9 = v3->Size;
  if ( v9 < v7 + 1 )
    v8 = v3->Size;
  v10 = &v3->pStr[v8];
  v11 = v9 - v8;
  if ( v7 <= 0 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v5->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v4->PublicNamespace.pObject);
  }
  else
  {
    if ( v6 )
    {
      if ( --v7 < 0 )
        v7 = 0i64;
    }
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
            &result,
            v3->pStr,
            v7);
    if ( v12->pNode->Size )
    {
      v14 = v4->TraitsNamespace.pObject->ITraits.pObject;
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
        *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v14[1].RefCount,
        &v25,
        0,
        v12,
        &v);
      v13 = v25.pV;
    }
    else
    {
      v13 = v4->PublicNamespace.pObject;
      if ( v13 )
        v13->RefCount = (v13->RefCount + 1) & 0x8FBFFFFF;
    }
    v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v5->Obj.pObject;
    if ( v13 != v15 )
    {
      if ( v15 )
      {
        if ( (unsigned __int8)v15 & 1 )
        {
          v5->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)&v15[-1].Prefix.value.VS._2.pTraits + 7);
        }
        else
        {
          v16 = v15->RefCount;
          if ( v16 & 0x3FFFFF )
          {
            v15->RefCount = v16 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15->vfptr);
          }
        }
      }
      v5->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v13->vfptr;
    }
    v17 = result.pNode;
    v18 = result.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  }
  v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          (Scaleform::GFx::ASString *)&v25,
          v10,
          v11);
  Scaleform::GFx::AS3::Value::Assign(&v5->Name, v19);
  v20 = (Scaleform::GFx::ASStringNode *)v25.pV;
  v18 = LODWORD(v25.pV->pPrev) == 1;
  --v20->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( (v5->Name.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v5->Name, (Scaleform::GFx::ASString *)&v25);
    v21 = v25.pV;
    if ( v25.pV->RefCount )
    {
      if ( LOBYTE(v25.pV->vfptr->ForEachChild_GC) == 64 )
      {
        v5->Kind |= 8u;
        v22 = Scaleform::GFx::ASString::Substring((Scaleform::GFx::ASString *)&v25, &result, 1, v21->RefCount);
        Scaleform::GFx::AS3::Value::Assign(&v5->Name, v22);
        v23 = result.pNode;
        v18 = result.pNode->RefCount == 1;
        --v23->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      }
    }
    v24 = (Scaleform::GFx::ASStringNode *)v25.pV;
    v18 = LODWORD(v25.pV->pPrev) == 1;
    --v24->RefCount;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  }
}

// File Line: 543
// RVA: 0x780490
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::AS3::TypeInfo *v3; // rbp
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::Multiname *v5; // rdi
  Scaleform::GFx::AS3::StringManager *v6; // r15
  Scaleform::GFx::ASString *v7; // r14
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v20; // [rsp+88h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h]

  v3 = ti;
  v4 = vm;
  v5 = this;
  this->Kind = 0;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v6 = vm->StringManagerRef;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
         &result,
         ti->PkgName);
  if ( v7->pNode->Size )
  {
    v9 = v4->TraitsNamespace.pObject->ITraits.pObject;
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&v9[1].RefCount,
      &v20,
      0,
      v7,
      &v);
    v8 = v20.pV;
  }
  else
  {
    v8 = v4->PublicNamespace.pObject;
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
  }
  v10 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v5->Obj.pObject;
  if ( v8 != v10 )
  {
    if ( v10 )
    {
      if ( (unsigned __int8)v10 & 1 )
      {
        v5->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)&v10[-1].Prefix.value.VS._2.pTraits + 7);
      }
      else
      {
        v11 = v10->RefCount;
        if ( v11 & 0x3FFFFF )
        {
          v10->RefCount = v11 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
        }
      }
    }
    v5->Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)&v8->vfptr;
  }
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
          (Scaleform::GFx::ASString *)&v20,
          v3->Name);
  Scaleform::GFx::AS3::Value::Assign(&v5->Name, v14);
  v15 = (Scaleform::GFx::ASStringNode *)v20.pV;
  v13 = LODWORD(v20.pV->pPrev) == 1;
  --v15->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( (v5->Name.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v5->Name, (Scaleform::GFx::ASString *)&v20);
    v16 = v20.pV;
    if ( v20.pV->RefCount )
    {
      if ( LOBYTE(v20.pV->vfptr->ForEachChild_GC) == 64 )
      {
        v5->Kind |= 8u;
        v17 = Scaleform::GFx::ASString::Substring((Scaleform::GFx::ASString *)&v20, &result, 1, v16->RefCount);
        Scaleform::GFx::AS3::Value::Assign(&v5->Name, v17);
        v18 = result.pNode;
        v13 = result.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
    }
    v19 = (Scaleform::GFx::ASStringNode *)v20.pV;
    v13 = LODWORD(v20.pV->pPrev) == 1;
    --v19->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
}

// File Line: 559
// RVA: 0x7803C0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::Multiname *other)
{
  Scaleform::GFx::AS3::GASRefCountBase *v2; // r8
  signed int v3; // eax
  Scaleform::GFx::AS3::Value::V2U v4; // r8
  long double v5; // r8

  this->Kind = other->Kind;
  v2 = other->Obj.pObject;
  this->Obj.pObject = v2;
  if ( v2 )
    v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = other->Name.Flags;
  this->Name.Bonus.pWeakProxy = other->Name.Bonus.pWeakProxy;
  this->Name.value = other->Name.value;
  v3 = other->Name.Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (other->Name.Flags >> 9) & 1 )
    {
      ++other->Name.Bonus.pWeakProxy->RefCount;
    }
    else if ( v3 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&other->Name.value.VNumber + 24i64);
    }
    else if ( v3 > 10 )
    {
      if ( v3 <= 15 )
      {
        v5 = other->Name.value.VNumber;
        if ( v5 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v5 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v5 + 32i64) + 1) & 0x8FBFFFFF;
      }
      else if ( v3 <= 17 )
      {
        v4.VObj = (Scaleform::GFx::AS3::Object *)other->Name.value.VS._2;
        if ( v4.VObj )
          v4.VObj->RefCount = (v4.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 563
// RVA: 0x7F8090
char __fastcall Scaleform::GFx::AS3::Multiname::IsAnyType(Scaleform::GFx::AS3::Multiname *this)
{
  Scaleform::GFx::AS3::Value *v1; // rcx
  int v2; // edx
  bool v3; // bl
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = &this->Name;
  v2 = v1->Flags & 0x1F;
  if ( !v2 )
    return 1;
  if ( (unsigned int)(v2 - 12) > 3 && v2 != 10 )
    return 0;
  if ( !*(_QWORD *)&v1->value.VNumber )
    return 1;
  if ( v2 != 10 )
    return 0;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v1, &result);
  v3 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
  v4 = result.pNode;
  v5 = result.pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  return v3;
}

// File Line: 579
// RVA: 0x7B9980
bool __fastcall Scaleform::GFx::AS3::Multiname::ContainsNamespace(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // r8
  Scaleform::GFx::AS3::GASRefCountBase *v3; // rdx
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // r9
  unsigned __int64 v6; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v7; // rdx

  v2 = ns;
  v3 = this->Obj.pObject;
  if ( (this->Kind & 3) != 2 )
    return v3[1].pNext == (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v2->Uri.pNode
        && !((*((_BYTE *)v2 + 40) ^ LOBYTE(v3[1].vfptr)) & 0xF);
  v5 = v3[1]._pRCC;
  v6 = 0i64;
  if ( !v5 )
    return 0;
  v7 = v3[1].vfptr;
  while ( (Scaleform::GFx::ASStringNode *)*((_QWORD *)v7->ForEachChild_GC + 7) != v2->Uri.pNode
       || (*((_BYTE *)v2 + 40) ^ *((_BYTE *)v7->ForEachChild_GC + 40)) & 0xF )
  {
    ++v6;
    v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)v7 + 8);
    if ( v6 >= (unsigned __int64)v5 )
      return 0;
  }
  return 1;
}

// File Line: 594
// RVA: 0x807370
void __fastcall Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::VSBase *vs)
{
  Scaleform::GFx::AS3::VSBase *v2; // rdi
  Scaleform::GFx::AS3::Value *v3; // rdx
  Scaleform::GFx::AS3::Multiname *v4; // rsi
  long double v5; // rax
  __int64 v6; // rcx
  long double v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rbx
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  bool v10; // zf

  v2 = vs;
  v3 = vs->pCurrent;
  v4 = this;
  if ( (v3->Flags & 0x1F) - 12 > 3
    || (v5 = v3->value.VNumber, v5 == 0.0)
    || (v6 = *(_QWORD *)(*(_QWORD *)&v5 + 40i64), *(_DWORD *)(v6 + 120) != 17)
    || !(~(*(_BYTE *)(v6 + 112) >> 5) & 1) )
  {
    v4->Name.Flags = v3->Flags;
    v4->Name.Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    v4->Name.value.VNumber = v3->value.VNumber;
    v4->Name.value.VS._2.VObj = v3->value.VS._2.VObj;
    --v2->pCurrent;
    Scaleform::GFx::AS3::Multiname::PostProcessName(v4, 0);
    return;
  }
  v7 = v3->value.VNumber;
  Scaleform::GFx::AS3::Value::Assign(&v4->Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v7 + 56i64));
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v4->Obj,
    *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v7 + 64i64));
  v4->Kind &= 0xFFFFFFF9;
  v8 = v2->pCurrent;
  if ( (v2->pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_11:
    --v2->pCurrent;
    return;
  }
  if ( !((v2->pCurrent->Flags >> 9) & 1) )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(v2->pCurrent);
    goto LABEL_11;
  }
  v9 = v8->Bonus.pWeakProxy;
  v10 = v9->RefCount-- == 1;
  if ( v10 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v8->Flags &= 0xFFFFFDE0;
  v8->Bonus.pWeakProxy = 0i64;
  v8->value.VNumber = 0.0;
  v8->value.VS._2.VObj = 0i64;
  --v2->pCurrent;
}

// File Line: 636
// RVA: 0x81D3A0
void __fastcall Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(Scaleform::GFx::AS3::Multiname *this, Scaleform::GFx::AS3::Value *nameVal)
{
  Scaleform::GFx::AS3::Multiname *v2; // rdi
  long double v3; // rbx
  __int64 v4; // rax

  v2 = this;
  if ( (nameVal->Flags & 0x1F) - 12 <= 3
    && (v3 = nameVal->value.VNumber, v3 != 0.0)
    && (v4 = *(_QWORD *)(*(_QWORD *)&v3 + 40i64), *(_DWORD *)(v4 + 120) == 17)
    && ~(*(_BYTE *)(v4 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v3 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v2->Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v3 + 64i64));
    v2->Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&this->Name, nameVal);
    Scaleform::GFx::AS3::Multiname::PostProcessName(v2, 0);
  }
}

// File Line: 654
// RVA: 0x807CF0
void __fastcall Scaleform::GFx::AS3::Multiname::PostProcessName(Scaleform::GFx::AS3::Multiname *this, const bool fromQName)
{
  Scaleform::GFx::AS3::Multiname *v2; // rdi
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString v9; // [rsp+50h] [rbp+18h]

  v2 = this;
  if ( (this->Name.Flags & 0x1F) == 10 && !fromQName )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&this->Name, &result);
    v3 = result.pNode;
    if ( result.pNode->Size )
    {
      if ( *result.pNode->pData == 64 )
      {
        v2->Kind |= 8u;
        v4 = Scaleform::GFx::ASString::Substring(&result, &v9, 1, v3->Size);
        Scaleform::GFx::AS3::Value::Assign(&v2->Name, v4);
        v5 = v9.pNode;
        v6 = v9.pNode->RefCount == 1;
        --v5->RefCount;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      }
    }
    v7 = result.pNode;
    v6 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 683
// RVA: 0x7D3EB0
void __fastcall Scaleform::GFx::AS3::FindScopeProperty(Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::VM *vm, const unsigned __int64 baseSSInd, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *scope_stack, Scaleform::GFx::AS3::Multiname *mn)
{
  unsigned __int64 v5; // rbx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v6; // r14
  unsigned __int64 v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // r12
  Scaleform::GFx::AS3::PropRef *v9; // rbp
  signed __int64 v10; // rdi

  v5 = scope_stack->Data.Size;
  v6 = scope_stack;
  v7 = baseSSInd;
  v8 = vm;
  v9 = result;
  if ( v5 > baseSSInd )
  {
    v10 = v5;
    do
    {
      Scaleform::GFx::AS3::FindPropertyWith(v9, v8, &v6->Data.Data[v10 - 1], mn);
      if ( Scaleform::GFx::AS3::PropRef::operator bool(v9) )
        break;
      --v5;
      --v10;
    }
    while ( v5 > v7 );
  }
}

// File Line: 715
// RVA: 0x7D27E0
void __fastcall Scaleform::GFx::AS3::FindGOProperty(Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::VM *vm, Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl::GlobalObject *,2,Scaleform::ArrayDefaultPolicy> *go, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::ClassTraits::Traits *ctr)
{
  Scaleform::GFx::AS3::Multiname *v5; // r13
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl::GlobalObject *,2,Scaleform::ArrayDefaultPolicy> *v6; // r15
  Scaleform::GFx::AS3::PropRef *v7; // r14
  __int64 v8; // r12
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rdi
  long double v11; // rbx
  int v12; // eax
  Scaleform::GFx::AS3::Value scope; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS3::VM *vma; // [rsp+98h] [rbp+10h]

  vma = vm;
  v5 = mn;
  v6 = go;
  v7 = result;
  v8 = 0i64;
  if ( ctr )
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))ctr->vfptr[2].~RefCountBaseGC<328>)(ctr);
  v9 = v6->Data.Size;
  v10 = 0i64;
  if ( v9 )
  {
    do
    {
      v11 = *(double *)&v6->Data.Data[v10];
      if ( !ctr || v8 == (*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)&v11 + 40i64) + 56i64))() )
      {
        scope.Flags = 12;
        scope.Bonus.pWeakProxy = 0i64;
        scope.value.VNumber = v11;
        if ( v11 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::FindPropertyWith(v7, vma, &scope, v5, 0);
        if ( LOBYTE(v11) & 1 )
        {
          *(_QWORD *)&scope.value.VNumber = *(_QWORD *)&v11 - 1i64;
        }
        else if ( v11 != 0.0 )
        {
          v12 = *(_DWORD *)(*(_QWORD *)&v11 + 32i64);
          if ( v12 & 0x3FFFFF )
          {
            *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v11);
          }
        }
        if ( Scaleform::GFx::AS3::PropRef::operator bool(v7) )
          break;
      }
      ++v10;
    }
    while ( v10 < v9 );
  }
}

// File Line: 763
// RVA: 0x7D2250
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::FindFixedSlot(Scaleform::GFx::AS3::Traits *t, Scaleform::GFx::ASString *name, Scaleform::GFx::AS3::Instances::fl::Namespace *ns, unsigned __int64 *index, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Slots *v5; // rsi
  unsigned __int64 *v6; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // rbp
  Scaleform::GFx::ASString *v8; // r12
  Scaleform::GFx::AS3::SlotInfo *v9; // r14
  const unsigned int *v10; // rax
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rdi
  signed __int64 v13; // r8
  __int64 v14; // rdx
  __int64 v15; // rcx
  int v16; // ecx
  bool v17; // zf
  Scaleform::GFx::AS3::SlotInfo *result; // rax

  v5 = (Scaleform::GFx::AS3::Slots *)&t->FirstOwnSlotNum;
  v6 = index;
  v7 = ns;
  v8 = name;
  v9 = 0i64;
  v10 = Scaleform::GFx::AS3::Slots::FindSlotValues((Scaleform::GFx::AS3::Slots *)&t->FirstOwnSlotNum, name);
  if ( v10 )
  {
    v11 = *v10;
    while ( 1 )
    {
      *v6 = v11;
      v12 = v5->FirstOwnSlotNum;
      v13 = (signed __int64)(v11 >= v5->FirstOwnSlotNum ? &v5->VArray.Data.Data[(unsigned int)v11 - v12].Value : Scaleform::GFx::AS3::Slots::GetSlotInfo(v5->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v11));
      v14 = *(_QWORD *)(v13 + 8);
      v15 = *((_QWORD *)v7 + 5) << 60 >> 60;
      if ( (unsigned int)(*(_QWORD *)(v14 + 40) << 60 >> 60) == (_DWORD)v15 )
      {
        v16 = v15 - 1;
        if ( !v16 )
          break;
        v17 = v16 == 2 ? v7 == (Scaleform::GFx::AS3::Instances::fl::Namespace *)v14 : *(Scaleform::GFx::ASStringNode **)(v14 + 56) == v7->Uri.pNode;
        if ( v17 )
          break;
      }
      if ( v11 >= v12 )
        v11 = v5->VArray.Data.Data[v11 - v12].Prev;
      else
        v11 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v5->Parent, v11);
      if ( (v11 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_18;
    }
    v9 = (Scaleform::GFx::AS3::SlotInfo *)v13;
  }
LABEL_18:
  if ( obj )
    result = (Scaleform::GFx::AS3::SlotInfo *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::SlotInfo *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::Namespace *, unsigned __int64 *))obj->vfptr[6].~RefCountBaseGC<328>)(
                                                obj,
                                                v9,
                                                v8,
                                                v7,
                                                v6);
  else
    result = v9;
  return result;
}

// File Line: 825
// RVA: 0x7D1890
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::FindClassTraits(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *v3; // r14
  Scaleform::GFx::AS3::VM *v4; // r15
  Scaleform::GFx::AS3::GASRefCountBase *v6; // r13
  Scaleform::GFx::AS3::RefCountCollector<328> *v7; // r12
  unsigned __int64 v8; // rbp
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v10; // rax
  __int64 v11; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v13; // rsi
  Scaleform::GFx::ASStringNode *v14; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *v15; // rsi
  signed __int64 v16; // rax
  signed __int64 v17; // rsi
  int v18; // eax
  bool v19; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v20; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v21; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v22; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Value *v27; // [rsp+20h] [rbp-78h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+30h] [rbp-68h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+40h] [rbp-58h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v31; // [rsp+50h] [rbp-48h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS3::ClassTraits::Traits *v33; // [rsp+B8h] [rbp+20h]

  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)appDomain;
  v4 = vm;
  if ( (mn->Kind & 3u) <= 1 )
    return Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, mn, appDomain);
  v6 = mn->Obj.pObject;
  v7 = v6[1]._pRCC;
  v8 = 0i64;
  if ( !v7 )
    return 0i64;
  v9 = &mn->Name;
  v27 = &mn->Name;
  do
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v9, &result);
    v10 = v6[1].vfptr;
    v11 = *((_QWORD *)&v10->ForEachChild_GC + v8);
    v12 = (Scaleform::GFx::AS3::VMAppDomain *)v3[5].pTable;
    if ( !v12
      || (v13 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
                  v12,
                  &result,
                  *((Scaleform::GFx::AS3::Instances::fl::Namespace **)&v10->ForEachChild_GC + v8))) == 0i64 )
    {
      v14 = result.pNode;
      key.Name = result;
      ++key.Name.pNode->RefCount;
      key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v11;
      if ( v11 )
        *(_DWORD *)(v11 + 32) = (*(_DWORD *)(v11 + 32) + 1) & 0x8FBFFFFF;
      v15 = v3[6].pTable;
      if ( v15
        && (v16 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                    v3 + 6,
                    &key,
                    v15->SizeMask & (v14->HashFlags & 0xFFFFFF ^ 4
                                                               * (*(_DWORD *)(*(_QWORD *)(v11 + 56) + 28i64) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)(*(_QWORD *)(v11 + 40) << 60 >> 60))),
            v16 >= 0)
        && (v17 = (signed __int64)&v15[2] + 40 * v16) != 0 )
      {
        v13 = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v17 + 16);
      }
      else
      {
        v13 = 0i64;
      }
      if ( v11 )
      {
        if ( v11 & 1 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(v11 - 1);
        }
        else
        {
          v18 = *(_DWORD *)(v11 + 32);
          if ( v18 & 0x3FFFFF )
          {
            *(_DWORD *)(v11 + 32) = v18 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11);
          }
        }
      }
      v19 = v14->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( !v13 )
        goto LABEL_41;
    }
    v20 = *v13;
    if ( !*v13 )
    {
LABEL_41:
      v21 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
              v4->GlobalObject.pObject,
              &result,
              (Scaleform::GFx::AS3::Instances::fl::Namespace *)v11);
      v20 = v21;
      if ( v21 )
      {
        v22 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v4->SystemDomain.pObject;
        v33 = v21;
        v28 = result.pNode;
        ++v28->RefCount;
        v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11;
        if ( v11 )
          *(_DWORD *)(v11 + 32) = (*(_DWORD *)(v11 + 32) + 1) & 0x8FBFFFFF;
        v31.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v28;
        v31.pSecond = &v33;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
          v22 + 6,
          v22[7].pTable,
          &v31,
          v28->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v29[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v29[1].vfptr << 60 >> 60));
        v23 = v29;
        if ( v29 )
        {
          if ( (unsigned __int8)v29 & 1 )
          {
            v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v29 - 1);
          }
          else
          {
            v24 = v29->RefCount;
            if ( v24 & 0x3FFFFF )
            {
              v29->RefCount = v24 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
            }
          }
        }
        v25 = v28;
        v19 = v28->RefCount == 1;
        --v25->RefCount;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
    v26 = result.pNode;
    v19 = result.pNode->RefCount == 1;
    --v26->RefCount;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    if ( v20 )
      break;
    ++v8;
    v9 = v27;
  }
  while ( v8 < (unsigned __int64)v7 );
  return v20;
}

// File Line: 915
// RVA: 0x7D2040
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::FindFixedSlot(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Traits *t, Scaleform::GFx::AS3::Multiname *mn, unsigned __int64 *index, Scaleform::GFx::AS3::Object *obj)
{
  unsigned __int64 *v5; // r13
  Scaleform::GFx::AS3::Multiname *v6; // rbx
  Scaleform::GFx::AS3::Traits *v7; // rsi
  Scaleform::GFx::AS3::SlotInfo *v8; // r14
  __int64 v9; // r12
  Scaleform::GFx::AS3::GASRefCountBase *v10; // rdi
  const unsigned int *v11; // rax
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r15
  __int64 v14; // rbp
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // rdi
  signed __int64 v17; // r8
  __int64 v18; // rdx
  __int64 v19; // rcx
  int v20; // ecx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v24; // [rsp+30h] [rbp-58h]
  const unsigned int *v25; // [rsp+38h] [rbp-50h]
  unsigned __int64 v26; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::ASString name; // [rsp+A0h] [rbp+18h]

  v5 = index;
  v6 = mn;
  v7 = t;
  name.pNode = vm->StringManagerRef->Builtins[0].pNode;
  ++name.pNode->RefCount;
  v8 = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&v26, &name)->Result )
  {
    v9 = 0i64;
    if ( (v6->Kind & 3u) > 1 )
    {
      v10 = v6->Obj.pObject;
      v24 = v6->Obj.pObject;
      v11 = Scaleform::GFx::AS3::Slots::FindSlotValues((Scaleform::GFx::AS3::Slots *)&v7->FirstOwnSlotNum, &name);
      v25 = v11;
      v12 = v10[1].pRCCRaw;
      v26 = v12;
      v13 = 0i64;
      if ( v12 )
      {
        do
        {
          v14 = *((_QWORD *)&v10[1].vfptr->ForEachChild_GC + v13);
          if ( v11 )
          {
            v15 = *v11;
            while ( 1 )
            {
              *v5 = v15;
              v16 = v7->FirstOwnSlotNum;
              v17 = (signed __int64)(v15 >= v16 ? &v7->VArray.Data.Data[(unsigned int)v15 - v16].Value : Scaleform::GFx::AS3::Slots::GetSlotInfo(v7->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v15));
              v18 = *(_QWORD *)(v17 + 8);
              v19 = *(_QWORD *)(v14 + 40) << 60 >> 60;
              if ( (unsigned int)(*(_QWORD *)(v18 + 40) << 60 >> 60) == (_DWORD)v19 )
              {
                v20 = v19 - 1;
                if ( !v20 )
                  break;
                v21 = v20 == 2 ? v14 == v18 : *(_QWORD *)(v18 + 56) == *(_QWORD *)(v14 + 56);
                if ( v21 )
                  break;
              }
              if ( v15 >= v16 )
                v15 = v7->VArray.Data.Data[v15 - v16].Prev;
              else
                v15 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v7->Parent, v15);
              if ( (v15 & 0x8000000000000000ui64) != 0i64 )
                goto LABEL_22;
            }
            v9 = v17;
LABEL_22:
            v10 = v24;
            v12 = v26;
          }
          if ( obj )
            v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, __int64, Scaleform::GFx::ASString *, __int64, unsigned __int64 *))obj->vfptr[6].~RefCountBaseGC<328>)(
                   obj,
                   v9,
                   &name,
                   v14,
                   v5);
          if ( v9 )
            break;
          ++v13;
          v11 = v25;
        }
        while ( v13 < v12 );
      }
      v8 = (Scaleform::GFx::AS3::SlotInfo *)v9;
    }
    else
    {
      v8 = Scaleform::GFx::AS3::FindFixedSlot(
             v7,
             &name,
             (Scaleform::GFx::AS3::Instances::fl::Namespace *)v6->Obj.pObject,
             v5,
             obj);
    }
  }
  v22 = name.pNode;
  v21 = name.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  return v8;
}

// File Line: 1002
// RVA: 0x7D23A0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::FindFixedTraits(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Traits *t, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::Multiname *v4; // rdi
  Scaleform::GFx::AS3::Traits *v5; // r15
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // r12
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v8; // r14
  const unsigned int *v9; // rax
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  Scaleform::GFx::AS3::SlotInfo *v12; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rdx
  __int64 v14; // rcx
  int v15; // ecx
  bool v16; // zf
  __int64 v17; // rdi
  signed __int64 v18; // r14
  const unsigned int *v19; // rax
  unsigned __int64 v20; // r13
  __int64 v21; // rdi
  unsigned __int64 v22; // rbx
  __int64 v23; // r15
  unsigned __int64 v24; // rsi
  Scaleform::GFx::AS3::SlotInfo *v25; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // rdx
  bool v27; // zf
  Scaleform::GFx::AS3::VM *v28; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *v29; // rdx
  Scaleform::GFx::AS3::VMAppDomain *v30; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v31; // rsi
  Scaleform::GFx::ASStringNode *v32; // rbx
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *v33; // rax
  int v34; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *v35; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v36; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v37; // rcx
  unsigned int v38; // eax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-60h]
  unsigned __int64 v43; // [rsp+28h] [rbp-58h]
  const unsigned int *v44; // [rsp+30h] [rbp-50h]
  __int64 v45; // [rsp+38h] [rbp-48h]
  __int64 v46; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v47; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v48; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+58h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v50; // [rsp+68h] [rbp-18h]
  Scaleform::GFx::AS3::VM *vma; // [rsp+C0h] [rbp+40h]
  Scaleform::GFx::AS3::CheckResult v52; // [rsp+D0h] [rbp+50h]
  Scaleform::GFx::AS3::VMAppDomain *v53; // [rsp+D8h] [rbp+58h]

  v53 = appDomain;
  vma = vm;
  v46 = -2i64;
  v4 = mn;
  v5 = t;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &result);
  v6 = 0i64;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(&v4->Name, &v52, &result)->Result )
    goto LABEL_69;
  v7 = 0i64;
  if ( (v4->Kind & 3u) > 1 )
  {
    v17 = (__int64)v4->Obj.pObject;
    v45 = v17;
    v18 = (signed __int64)&v5->FirstOwnSlotNum;
    v19 = Scaleform::GFx::AS3::Slots::FindSlotValues((Scaleform::GFx::AS3::Slots *)&v5->FirstOwnSlotNum, &result);
    v44 = v19;
    v43 = *(_QWORD *)(v17 + 48);
    v20 = 0i64;
    if ( !v43 )
    {
LABEL_68:
      v6 = v7;
      goto LABEL_69;
    }
    while ( 1 )
    {
      v21 = *(_QWORD *)(*(_QWORD *)(v17 + 40) + 8 * v20);
      if ( v19 )
      {
        v22 = *v19;
        v23 = *(_QWORD *)(v21 + 40) << 60 >> 60;
        while ( 1 )
        {
          v24 = *(_QWORD *)v18;
          v25 = (Scaleform::GFx::AS3::SlotInfo *)(v22 >= *(_QWORD *)v18 ? (((unsigned int)v22 - v24) << 6)
                                                                        + *(_QWORD *)(v18 + 16)
                                                                        + 16i64 : Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                                                    *(Scaleform::GFx::AS3::Slots **)(v18 + 8),
                                                                                    (Scaleform::GFx::AS3::AbsoluteIndex)v22));
          v26 = v25->pNs.pObject;
          if ( (unsigned int)(*((_QWORD *)v26 + 5) << 60 >> 60) == (_DWORD)v23 )
          {
            if ( (_DWORD)v23 == 1 )
              break;
            v27 = (_DWORD)v23 == 3 ? v21 == (_QWORD)v26 : v26->Uri.pNode == *(Scaleform::GFx::ASStringNode **)(v21 + 56);
            if ( v27 )
              break;
          }
          if ( v22 >= v24 )
            v22 = *(_QWORD *)(((v22 - v24) << 6) + *(_QWORD *)(v18 + 16) + 8);
          else
            v22 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(*(Scaleform::GFx::AS3::Slots **)(v18 + 8), v22);
          if ( (v22 & 0x8000000000000000ui64) != 0i64 )
            goto LABEL_39;
        }
        v28 = vma;
        v7 = Scaleform::GFx::AS3::SlotInfo::GetDataType(v25, vma);
        if ( v7 )
          goto LABEL_68;
      }
      else
      {
LABEL_39:
        v28 = vma;
      }
      v29 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)v53;
      v30 = v53->ParentDomain;
      if ( v30 )
      {
        v31 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
                v30,
                &result,
                (Scaleform::GFx::AS3::Instances::fl::Namespace *)v21);
        if ( v31 )
          goto LABEL_55;
        v29 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)v53;
      }
      v32 = result.pNode;
      key.Name = result;
      ++key.Name.pNode->RefCount;
      key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v21;
      if ( v21 )
        *(_DWORD *)(v21 + 32) = (*(_DWORD *)(v21 + 32) + 1) & 0x8FBFFFFF;
      v33 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
              v29 + 6,
              &key);
      v31 = (Scaleform::GFx::AS3::ClassTraits::Traits **)&v33->Second;
      if ( !v33 )
        v31 = 0i64;
      if ( v21 )
      {
        if ( v21 & 1 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(v21 - 1);
        }
        else
        {
          v34 = *(_DWORD *)(v21 + 32);
          if ( v34 & 0x3FFFFF )
          {
            *(_DWORD *)(v21 + 32) = v34 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v21);
          }
        }
      }
      v16 = v32->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      if ( v31 )
      {
LABEL_55:
        v7 = *v31;
        if ( *v31 )
          goto LABEL_68;
      }
      v35 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
              v28->GlobalObject.pObject,
              &result,
              (Scaleform::GFx::AS3::Instances::fl::Namespace *)v21);
      v7 = v35;
      if ( v35 )
      {
        v36 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scale)v28->SystemDomain.pObject;
        *(_QWORD *)&v52.Result = v35;
        v47 = result.pNode;
        ++v47->RefCount;
        v48 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v21;
        if ( v21 )
          *(_DWORD *)(v21 + 32) = (*(_DWORD *)(v21 + 32) + 1) & 0x8FBFFFFF;
        v50.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v47;
        v50.pSecond = (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&v52;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
          v36 + 6,
          v36[7].pTable,
          &v50,
          v47->HashFlags & 0xFFFFFF ^ 4 * (HIDWORD(v48[1].pNext->pPrevRoot) & 0xFFFFFFu) ^ (unsigned __int64)(unsigned int)((_QWORD)v48[1].vfptr << 60 >> 60));
        v37 = v48;
        if ( v48 )
        {
          if ( (unsigned __int8)v48 & 1 )
          {
            v48 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v48 - 1);
          }
          else
          {
            v38 = v48->RefCount;
            if ( v38 & 0x3FFFFF )
            {
              v48->RefCount = v38 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v37);
            }
          }
        }
        v39 = v47;
        v16 = v47->RefCount == 1;
        --v39->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v39);
      }
      if ( !v7 )
      {
        ++v20;
        v19 = v44;
        v17 = v45;
        if ( v20 < v43 )
          continue;
      }
      goto LABEL_68;
    }
  }
  v8 = v4->Obj.pObject;
  v9 = Scaleform::GFx::AS3::Slots::FindSlotValues((Scaleform::GFx::AS3::Slots *)&v5->FirstOwnSlotNum, &result);
  if ( v9 )
  {
    v10 = *v9;
    while ( (v10 & 0x8000000000000000ui64) == 0i64 )
    {
      v11 = v5->FirstOwnSlotNum;
      if ( v10 >= v11 )
        v12 = &v5->VArray.Data.Data[(unsigned int)v10 - v11].Value;
      else
        v12 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v5->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v10);
      v13 = v12->pNs.pObject;
      v14 = (_QWORD)v8[1].vfptr << 60 >> 60;
      if ( (unsigned int)(*((_QWORD *)v13 + 5) << 60 >> 60) == (_DWORD)v14 )
      {
        v15 = v14 - 1;
        if ( !v15
          || (v15 == 2 ? (v16 = v8 == (Scaleform::GFx::AS3::GASRefCountBase *)v13) : (v16 = v13->Uri.pNode == (Scaleform::GFx::ASStringNode *)v8[1].pNext),
              v16) )
        {
          if ( v12 )
            v6 = Scaleform::GFx::AS3::SlotInfo::GetDataType(v12, v5->pVM);
          break;
        }
      }
      if ( v10 >= v11 )
        v10 = v5->VArray.Data.Data[v10 - v11].Prev;
      else
        v10 = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v5->Parent, v10);
    }
  }
LABEL_69:
  v40 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v40->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  return v6;
}

// File Line: 1090
// RVA: 0x7D2F20
void __fastcall Scaleform::GFx::AS3::FindObjProperty(Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *scope, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::FindPropAttr attr)
{
  Scaleform::GFx::AS3::Multiname *v5; // r14
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::VM *v7; // r13
  Scaleform::GFx::AS3::PropRef *v8; // rdi
  char v9; // r15
  Scaleform::GFx::AS3::Traits *v10; // rbx
  Scaleform::GFx::AS3::Object *obj; // rax
  Scaleform::GFx::AS3::VM *v12; // rax
  Scaleform::GFx::AS3::VM *v13; // r9
  unsigned __int64 v14; // r10
  unsigned int v15; // edx
  Scaleform::GFx::AS3::WeakProxy *v16; // r8
  long double v17; // rcx
  int v18; // eax
  unsigned int v19; // ebx
  bool v20; // zf
  Scaleform::GFx::AS3::FindPropAttr v21; // ebp
  Scaleform::GFx::AS3::PropRef *v22; // rax
  Scaleform::GFx::AS3::Object *v23; // rax
  Scaleform::GFx::AS3::ReadValue v24; // [rsp+38h] [rbp-60h]
  unsigned __int64 index; // [rsp+B0h] [rbp+18h]

  v5 = mn;
  v6 = scope;
  v7 = vm;
  v8 = result;
  v9 = 0;
  if ( (scope->Flags & 0x1F) - 12 <= 2 )
    v9 = 1;
  v10 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  index = 0i64;
  if ( v9 )
    obj = v6->value.VS._1.VObj;
  else
    obj = 0i64;
  v12 = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::FindFixedSlot(v7, v10, v5, &index, obj);
  v13 = v12;
  if ( v12 )
  {
    v24.VMRef = v12;
    v14 = index;
    v24.OpStack = (Scaleform::GFx::AS3::ValueStack *)index;
    v15 = v6->Flags;
    v24.ArgValue.Flags = v15;
    v16 = v6->Bonus.pWeakProxy;
    v24.ArgValue.Bonus.pWeakProxy = v6->Bonus.pWeakProxy;
    v17 = v6->value.VNumber;
    v24.ArgValue.value = v6->value;
    v18 = v15 & 0x1F;
    if ( v18 <= 9 )
      goto LABEL_18;
    if ( (v15 >> 9) & 1 )
    {
      ++v16->RefCount;
      goto LABEL_18;
    }
    if ( v18 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v17 + 24i64);
    }
    else if ( v18 > 10 )
    {
      if ( v18 <= 15 )
        goto LABEL_15;
      if ( v18 <= 17 )
      {
        v17 = *(double *)&v6->value.VS._2.VObj;
LABEL_15:
        if ( v17 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v17 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v17 + 32i64) + 1) & 0x8FBFFFFF;
        goto LABEL_18;
      }
    }
LABEL_18:
    v8->pSI = (Scaleform::GFx::AS3::SlotInfo *)v13;
    v8->SlotIndex = v14;
    Scaleform::GFx::AS3::Value::Assign(&v8->This, &v24.ArgValue);
    v19 = v24.ArgValue.Flags;
    if ( (v24.ArgValue.Flags & 0x1F) > 9 )
    {
      if ( (v24.ArgValue.Flags >> 9) & 1 )
      {
        v20 = v24.ArgValue.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v24.ArgValue.Bonus.pWeakProxy = 0i64;
        v24.ArgValue.value = 0ui64;
        v24.ArgValue.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v24.ArgValue);
      }
    }
    return;
  }
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(v5, v7->PublicNamespace.pObject) )
  {
    v21 = attr;
    if ( v9 && (LOBYTE(v10->Flags) >> 1) & 1 && (attr != 2 || !Scaleform::GFx::AS3::IsXMLObject(v6)) )
    {
      v22 = (Scaleform::GFx::AS3::PropRef *)(*((__int64 (__fastcall **)(_QWORD, Scaleform::GFx::AS3::ReadValue *, Scaleform::GFx::AS3::Multiname *))v6->value.VS._1.VStr->pData
                                             + 18))(
                                              *(_QWORD *)&v6->value.VNumber,
                                              &v24,
                                              v5);
      Scaleform::GFx::AS3::PropRef::operator=(v8, v22);
      Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>(&v24);
    }
    if ( (!(v8->This.Flags & 0x1F)
       || (_QWORD)v8->pSI & 1 && !((_QWORD)v8->pSI & 0xFFFFFFFFFFFFFFFEui64)
       || ((unsigned __int8)v8->pSI >> 1) & 1 && !((_QWORD)v8->pSI & 0xFFFFFFFFFFFFFFFDui64))
      && v21 != 1 )
    {
      for ( ; v10; v10 = v10->pParent.pObject )
      {
        if ( !v10->pConstructor.pObject )
          v10->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
        v23 = Scaleform::GFx::AS3::Class::GetPrototype(v10->pConstructor.pObject);
        Scaleform::GFx::AS3::Object::FindProperty(v23, v8, v5, v21);
        if ( Scaleform::GFx::AS3::PropRef::operator bool(v8) )
          break;
      }
      if ( !Scaleform::GFx::AS3::PropRef::operator bool(v8) && (v6->Flags & 0x1F) == 14 )
        Scaleform::GFx::AS3::FindScopeProperty(
          v8,
          v7,
          0i64,
          (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)(*(_QWORD *)&v6->value.VNumber
                                                                                           + 64i64),
          v5);
    }
  }
}

// File Line: 1187
// RVA: 0x7D3AA0
void __fastcall Scaleform::GFx::AS3::FindPropertyWith(Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *scope, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::PropRef *v5; // rsi
  signed int v6; // ecx
  Scaleform::GFx::AS3::Traits *v7; // rbx
  Scaleform::GFx::AS3::Object *v8; // rax
  Scaleform::GFx::AS3::SlotInfo *v9; // rax
  __int64 v10; // rdx
  __int64 v11; // r8
  Scaleform::GFx::AS3::SlotInfo *v12; // r9
  unsigned __int64 v13; // r10
  unsigned int v14; // edx
  Scaleform::GFx::AS3::WeakProxy *v15; // r8
  long double v16; // rcx
  int v17; // eax
  unsigned int v18; // ebx
  bool v19; // zf
  int v20; // edx
  Scaleform::GFx::AS3::PropRef *v21; // rax
  Scaleform::GFx::AS3::Object *v22; // rax
  Scaleform::GFx::AS3::PropRef *v23; // rax
  _QWORD *v24; // rax
  __int64 v25; // rbx
  signed __int64 v26; // rdi
  unsigned __int64 index; // [rsp+18h] [rbp-31h]
  Scaleform::GFx::AS3::Object *obj; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+28h] [rbp-21h]
  Scaleform::GFx::AS3::PropRef v30; // [rsp+58h] [rbp+Fh]
  Scaleform::GFx::AS3::VM *vma; // [rsp+B0h] [rbp+67h]
  signed __int64 retaddr; // [rsp+B8h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *mna; // [rsp+C0h] [rbp+77h]
  Scaleform::GFx::AS3::VM *v34; // [rsp+C8h] [rbp+7Fh]

  v34 = vm;
  obj = (Scaleform::GFx::AS3::Object *)-2i64;
  v4 = scope;
  v5 = result;
  v6 = 0;
  if ( (scope->Flags & 0x1F) - 12 <= 2 )
    v6 = 1;
  LODWORD(retaddr) = v6;
  v7 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  index = 0i64;
  if ( (_BYTE)retaddr )
    v8 = v4->value.VS._1.VObj;
  else
    v8 = 0i64;
  v9 = Scaleform::GFx::AS3::FindFixedSlot(vma, v7, mna, &index, v8);
  v12 = v9;
  if ( v9 )
  {
    resulta.pSI = v9;
    v13 = index;
    resulta.SlotIndex = index;
    v14 = v4->Flags;
    resulta.This.Flags = v14;
    v15 = v4->Bonus.pWeakProxy;
    resulta.This.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    v16 = v4->value.VNumber;
    resulta.This.value = v4->value;
    v17 = v14 & 0x1F;
    if ( v17 <= 9 )
      goto LABEL_18;
    if ( (v14 >> 9) & 1 )
    {
      ++v15->RefCount;
      goto LABEL_18;
    }
    if ( v17 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v16 + 24i64);
    }
    else if ( v17 > 10 )
    {
      if ( v17 <= 15 )
        goto LABEL_15;
      if ( v17 <= 17 )
      {
        v16 = *(double *)&v4->value.VS._2.VObj;
LABEL_15:
        if ( v16 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v16 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v16 + 32i64) + 1) & 0x8FBFFFFF;
        goto LABEL_18;
      }
    }
LABEL_18:
    v5->pSI = v12;
    v5->SlotIndex = v13;
    Scaleform::GFx::AS3::Value::Assign(&v5->This, &resulta.This);
    v18 = resulta.This.Flags;
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags >> 9) & 1 )
      {
        v19 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.This.Bonus.pWeakProxy = 0i64;
        resulta.This.value = 0ui64;
        resulta.This.Flags = v18 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    return;
  }
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *, __int64, __int64, _QWORD))v7->vfptr[1].ForEachChild_GC)(
          v7,
          v10,
          v11,
          0i64)
    && !((LOWORD(v4->Flags) >> 8) & 1) )
  {
    return;
  }
  v20 = (signed int)v34;
  if ( (_BYTE)retaddr && (LOBYTE(v7->Flags) >> 1) & 1 )
  {
    if ( (_DWORD)v34 != 2 || !Scaleform::GFx::AS3::IsXMLObject(v4) )
    {
      v21 = (Scaleform::GFx::AS3::PropRef *)(*((__int64 (__fastcall **)(_QWORD, Scaleform::GFx::AS3::PropRef *, Scaleform::GFx::AS3::Multiname *))v4->value.VS._1.VStr->pData
                                             + 18))(
                                              *(_QWORD *)&v4->value.VNumber,
                                              &resulta,
                                              mna);
      Scaleform::GFx::AS3::PropRef::operator=(v5, v21);
      if ( (resulta.This.Flags & 0x1F) > 9 )
      {
        if ( (resulta.This.Flags >> 9) & 1 )
        {
          v19 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          resulta.This.Bonus.pWeakProxy = 0i64;
          resulta.This.value = 0ui64;
          resulta.This.Flags &= 0xFFFFFDE0;
          v20 = (signed int)v34;
          goto LABEL_37;
        }
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    v20 = (signed int)v34;
  }
LABEL_37:
  if ( (!(v5->This.Flags & 0x1F)
     || (_QWORD)v5->pSI & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFEui64)
     || ((unsigned __int8)v5->pSI >> 1) & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFDui64))
    && v20 != 1 )
  {
    resulta.pSI = 0i64;
    resulta.SlotIndex = 0i64;
    resulta.This.Flags = 0;
    resulta.This.Bonus.pWeakProxy = 0i64;
    while ( 1 )
    {
      if ( !v7->pConstructor.pObject )
        v7->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v7->vfptr);
      v22 = Scaleform::GFx::AS3::Class::GetPrototype(v7->pConstructor.pObject);
      Scaleform::GFx::AS3::Object::FindProperty(v22, &resulta, mna, (Scaleform::GFx::AS3::FindPropAttr)v34);
      if ( resulta.This.Flags & 0x1F )
      {
        if ( (!((_QWORD)resulta.pSI & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
          && (!((LOBYTE(resulta.pSI) >> 1) & 1) || (_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
        {
          break;
        }
      }
      v7 = v7->pParent.pObject;
      if ( !v7 )
        goto LABEL_54;
    }
    Scaleform::GFx::AS3::PropRef::PropRef(&v30, v4, 0i64, 0i64);
    Scaleform::GFx::AS3::PropRef::operator=(v5, v23);
    Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&v30);
LABEL_54:
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags >> 9) & 1 )
      {
        v19 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.This.Bonus.pWeakProxy = 0i64;
        resulta.This.value = 0ui64;
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    if ( (!(v5->This.Flags & 0x1F)
       || (_QWORD)v5->pSI & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFEui64)
       || ((unsigned __int8)v5->pSI >> 1) & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFDui64))
      && (v4->Flags & 0x1F) == 14 )
    {
      v24 = (_QWORD *)(*(_QWORD *)&v4->value.VNumber + 64i64);
      retaddr = *(_QWORD *)&v4->value.VNumber + 64i64;
      v25 = *(_QWORD *)(*(_QWORD *)&v4->value.VNumber + 72i64);
      if ( v25 )
      {
        v26 = 32 * v25;
        do
        {
          Scaleform::GFx::AS3::FindPropertyWith(v5, vma, (Scaleform::GFx::AS3::Value *)(v26 + *v24 - 32i64), mna, 0);
          if ( Scaleform::GFx::AS3::PropRef::operator bool(v5) )
            break;
          v26 -= 32i64;
          --v25;
          v24 = (_QWORD *)retaddr;
        }
        while ( v25 );
      }
    }
  }
}

// File Line: 1287
// RVA: 0x7D0550
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ExecutePropertyUnsafe(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::VM *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rsi
  long double v7; // rcx
  unsigned int attr; // ST20_4
  int v9; // ecx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  int v13; // eax
  Scaleform::GFx::AS3::VM::Error *v14; // rax
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool result_on_stack; // [rsp+30h] [rbp-39h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-29h]
  Scaleform::GFx::AS3::PropRef v21; // [rsp+60h] [rbp-9h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::AS3::Value *v23; // [rsp+D8h] [rbp+6Fh]
  unsigned int v24; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v25; // [rsp+E8h] [rbp+7Fh]

  v4 = _this;
  v5 = vm;
  v6 = result;
  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    v7 = _this->value.VNumber;
    if ( v7 != 0.0 )
    {
      attr = v24;
      (*(void (__fastcall **)(long double, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v7 + 80i64))(
        COERCE_LONG_DOUBLE(*(_QWORD *)&v7),
        v6,
        prop_name,
        v23,
        attr,
        v25);
      return v6;
    }
  }
  v21.pSI = 0i64;
  v21.SlotIndex = 0i64;
  v21.This.Flags = 0;
  v21.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&v21, vm, _this, prop_name, FindCall);
  if ( v21.This.Flags & 0x1F
    && (!((_QWORD)v21.pSI & 1) || (_QWORD)v21.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(v21.pSI) >> 1) & 1) || (_QWORD)v21.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&v21, &v22, v5, &value, valExecute)->Result )
    {
      v6->Result = 0;
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags >> 9) & 1 )
        {
          v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          value.Bonus.pWeakProxy = 0i64;
          value.value = 0ui64;
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      goto LABEL_38;
    }
    v9 = value.Flags & 0x1F;
    if ( value.Flags & 0x1F && ((unsigned int)(v9 - 12) > 3 && v9 != 10 || *(_QWORD *)&value.value.VNumber) )
    {
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5, &value, v4, v23, v24, v25, 0);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result_on_stack,
        eCallOfNonFunctionError,
        v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v11 = v19;
      v12 = v19->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v12 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v12 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
  }
  else
  {
    if ( (LOBYTE(Scaleform::GFx::AS3::VM::GetValueTraits(v5, v4)->Flags) >> 1) & 1
      || (v13 = v4->Flags & 0x1F, v13 <= 4)
      || v13 == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&result_on_stack,
        eCallOfNonFunctionError,
        v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v15, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&result_on_stack, eReadSealedError, v5);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5, v14, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
    v16 = v19;
    v12 = v19->RefCount == 1;
    --v16->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  v6->Result = v5->HandleException == 0;
LABEL_38:
  if ( (v21.This.Flags & 0x1F) > 9 )
  {
    if ( (v21.This.Flags >> 9) & 1 )
    {
      v12 = v21.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v21.This.Bonus.pWeakProxy = 0i64;
      v21.This.value = 0ui64;
      v21.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v21.This);
    }
  }
  return v6;
}

// File Line: 1365
// RVA: 0x78D020
void __fastcall Scaleform::GFx::AS3::Object::~Object(Scaleform::GFx::AS3::Object *this)
{
  Scaleform::GFx::AS3::Object *v1; // rbx
  Scaleform::GFx::AS3::Traits *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&this->DynAttrs.mHash.pTable);
  v2 = v1->pTraits.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pTraits.pObject = (Scaleform::GFx::AS3::Traits *)((char *)v2 - 1);
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
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase((Scaleform::GFx::AS3::GASRefCountBase *)&v1->vfptr);
}

// File Line: 1377
// RVA: 0x7D6030
void __fastcall Scaleform::GFx::AS3::Object::ForEachChild_GC(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v3; // r9
  Scaleform::GFx::AS3::Object *v4; // r14
  void (__fastcall *v5)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v6; // rcx
  Scaleform::GFx::AS3::RefCountCollector<328> *v7; // rbp
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // rcx
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rcx
  __int64 v14; // rdx
  int v15; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v16; // rdx
  signed __int64 v17; // rcx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  Scaleform::GFx::AS3::Traits *v20; // rcx
  __m128i v21; // [rsp+20h] [rbp-18h]

  v3 = &this->DynAttrs;
  v4 = this;
  v5 = op;
  v6 = this->DynAttrs.mHash.pTable;
  v7 = prcc;
  if ( v6 )
  {
    v8 = v6->SizeMask;
    v9 = 0i64;
    v10 = v6 + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 += 4;
    }
    while ( v9 <= v8 );
    v21.m128i_i64[0] = (__int64)v3;
    v21.m128i_i64[1] = v9;
  }
  else
  {
    v21 = 0ui64;
  }
  _mm_store_si128(&v21, v21);
  v11 = v21.m128i_i64[1];
  v12 = v21.m128i_i64[0];
  while ( v12 )
  {
    v13 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 || v11 > *(_QWORD *)(v13 + 8) )
      break;
    v14 = v13 + (v11 << 6);
    v15 = *(_DWORD *)(v14 + 48) & 0x1F;
    if ( v15 <= 10 || (*(_DWORD *)(v14 + 48) >> 9) & 1 || v15 < 11 )
      goto LABEL_22;
    if ( v15 <= 15 )
    {
      v17 = v14 + 64;
      if ( !*(_QWORD *)(v14 + 64) )
        goto LABEL_22;
      v16 = 0i64;
      if ( (unsigned int)(v15 - 11) <= 4 )
        v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v17;
    }
    else
    {
      if ( v15 > 17 )
        goto LABEL_22;
      v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v14 + 72);
      if ( !*v16 )
        goto LABEL_22;
    }
    v5(v7, v16);
LABEL_22:
    v18 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
    if ( v11 <= (signed __int64)v18 && ++v11 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)v12 + (v11 << 6) + 16);
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v11;
        v19 += 8;
      }
      while ( v11 <= v18 );
    }
  }
  v20 = v4->pTraits.pObject;
  if ( v20 )
    Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(v20, v7, v4, v5);
  if ( v4->pTraits.pObject )
    v5(v7, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v4->pTraits);
}

// File Line: 1403
// RVA: 0x81D710
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::SetSlotValue(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::SlotIndex ind, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rbx

  v4 = result;
  Scaleform::GFx::AS3::Traits::SetSlotValue(
    this->pTraits.pObject,
    result,
    (Scaleform::GFx::AS3::AbsoluteIndex)(LODWORD(this->pTraits.pObject->FirstOwnSlotInd.Index) + ind.Index - 1i64),
    value,
    this);
  return v4;
}

// File Line: 1408
// RVA: 0x7F28E0
_BOOL8 __fastcall Scaleform::GFx::AS3::Object::HasProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::Multiname *prop_name, bool check_prototype)
{
  bool v3; // bl
  bool v4; // zf
  __int64 v6; // [rsp+28h] [rbp-40h]
  __int64 v7; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::AS3::Value v8; // [rsp+38h] [rbp-30h]

  v6 = 0i64;
  v7 = 0i64;
  v8.Flags = 0;
  v8.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(
    this,
    (Scaleform::GFx::AS3::PropRef *)&v6,
    prop_name,
    (Scaleform::GFx::AS3::FindPropAttr)(check_prototype == 0));
  v3 = v8.Flags & 0x1F
    && (!(v6 & 1) || v6 & 0xFFFFFFFFFFFFFFFEui64)
    && (!(((unsigned __int8)v6 >> 1) & 1) || v6 & 0xFFFFFFFFFFFFFFFDui64);
  if ( (v8.Flags & 0x1F) > 9 )
  {
    if ( (v8.Flags >> 9) & 1 )
    {
      v4 = v8.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v8.Bonus.pWeakProxy = 0i64;
      v8.value = 0ui64;
      v8.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
    }
  }
  return v3;
}

// File Line: 1419
// RVA: 0x7E7A90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *a3, Scaleform::GFx::AS3::Value::Hint hint)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::CheckResult *v5; // r14
  Scaleform::GFx::AS3::Traits *v6; // r10
  Scaleform::GFx::AS3::VM *v7; // rax
  Scaleform::GFx::AS3::StringManager *v8; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v9; // r15
  Scaleform::GFx::AS3::BuiltinTraitsType v10; // edx
  unsigned int v11; // edi
  unsigned int v12; // esi
  long double v13; // rbx
  Scaleform::GFx::AS3::Value::Extra v14; // rcx
  int v15; // er13
  __int64 v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // bl
  unsigned int v22; // er9
  Scaleform::GFx::AS3::Value::Extra v23; // rax
  Scaleform::GFx::AS3::Value::VU v24; // kr00_16
  int v25; // er9
  long double v26; // rbx
  Scaleform::GFx::AS3::Value::Extra v27; // rcx
  int v28; // esi
  __int64 v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASStringNode *v32; // rcx
  bool v33; // bl
  unsigned int v34; // edx
  Scaleform::GFx::AS3::Value::Extra v35; // rax
  Scaleform::GFx::AS3::Value::VU v36; // kr10_16
  long double v37; // rbx
  Scaleform::GFx::AS3::Value::Extra v38; // rcx
  int v39; // er13
  __int64 v40; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASStringNode *v43; // rcx
  bool v44; // bl
  unsigned int v45; // er9
  Scaleform::GFx::AS3::Value::Extra v46; // rax
  Scaleform::GFx::AS3::Value::VU v47; // kr20_16
  int v48; // er9
  long double v49; // rbx
  __int64 v50; // rax
  bool v51; // bl
  Scaleform::GFx::AS3::Abc::MultinameKind v52; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v53; // rax
  long double v54; // r8
  Scaleform::GFx::AS3::Value::Extra v55; // r9
  __int64 v57; // [rsp+20h] [rbp-B9h]
  __int64 v58; // [rsp+20h] [rbp-B9h]
  Scaleform::GFx::AS3::Value p; // [rsp+30h] [rbp-A9h]
  Scaleform::GFx::AS3::Value other; // [rsp+50h] [rbp-89h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp-69h]
  Scaleform::GFx::AS3::Multiname v62; // [rsp+78h] [rbp-61h]
  Scaleform::GFx::AS3::Multiname v63; // [rsp+A8h] [rbp-31h]
  Scaleform::GFx::ASString v64; // [rsp+D8h] [rbp-1h]
  Scaleform::GFx::AS3::Value::Extra v65; // [rsp+E0h] [rbp+7h]
  Scaleform::GFx::AS3::StringManager *v66; // [rsp+E8h] [rbp+Fh]
  __int64 v67; // [rsp+F0h] [rbp+17h]
  Scaleform::GFx::AS3::Object *v68; // [rsp+140h] [rbp+67h]
  char v69; // [rsp+158h] [rbp+7Fh]

  v68 = this;
  v67 = -2i64;
  v4 = a3;
  v5 = result;
  v6 = this->pTraits.pObject;
  v7 = v6->pVM;
  v8 = v7->StringManagerRef;
  v66 = v7->StringManagerRef;
  v9 = (Scaleform::GFx::AS3::GASRefCountBase *)&v7->PublicNamespace.pObject->vfptr;
  v10 = v6->TraitsType;
  if ( (unsigned int)(v10 - 18) > 1 )
  {
    if ( hint == hintNone )
      hint = (v10 == 9) + 1;
  }
  else
  {
    hint = 2;
  }
  p.Flags = 0;
  p.Bonus.pWeakProxy = 0i64;
  v11 = 10;
  v12 = 10;
  if ( hint != 2 )
  {
    v62.Kind = 10;
    v62.Obj.pObject = 0i64;
    v37 = *(double *)&v8->Builtins[25].pNode;
    *(long double *)&v62.Name.Flags = v37;
    if ( *(_QWORD *)&v37 == *(_QWORD *)(*(_QWORD *)&v37 + 8i64) + 104i64 )
    {
      v37 = 0.0;
      *(_QWORD *)&v62.Name.Flags = 0i64;
      v38.pWeakProxy = v65.pWeakProxy;
      v62.Name.Bonus = v65;
      v12 = 12;
      v62.Kind = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v37 + 24i64);
      v38.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v62.Name.Bonus;
    }
    v63.Kind = 0;
    v63.Obj.pObject = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v63.Name.Flags = 0;
    v63.Name.Bonus.pWeakProxy = 0i64;
    v39 = v12 & 0x1F;
    if ( (unsigned int)(v39 - 12) <= 3
      && v37 != 0.0
      && (v40 = *(_QWORD *)(*(_QWORD *)&v37 + 40i64), *(_DWORD *)(v40 + 120) == 17)
      && ~(*(_BYTE *)(v40 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v63.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v37 + 56i64));
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v63.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v37 + 64i64));
      v63.Kind &= 0xFFFFFFF9;
    }
    else
    {
      __asm { prefetcht1 byte ptr [rbp+57h+var_B8.Kind]; Prefetch to all cache levels }
      *(_QWORD *)&v63.Name.Flags = *(_QWORD *)&v62.Kind;
      v63.Name.Bonus.pWeakProxy = 0i64;
      v63.Name.value.VNumber = v37;
      v63.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.pWeakProxy;
      if ( v39 > 9 )
      {
        if ( (v12 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] + 1;
        }
        else if ( v39 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v37 + 24i64);
        }
        else if ( v39 > 10 )
        {
          if ( v39 <= 15 )
          {
            if ( v37 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v37 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v37 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v39 <= 17 && v38.pWeakProxy )
          {
            v38.pWeakProxy[2].RefCount = (v38.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
      if ( (v63.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v63.Name, &resulta);
        if ( resulta.pNode->Size )
        {
          if ( *resulta.pNode->pData == 64 )
          {
            v63.Kind |= 8u;
            v41 = Scaleform::GFx::ASString::Substring(&resulta, &v64, 1, resulta.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v63.Name, v41);
            v42 = v64.pNode;
            v19 = v64.pNode->RefCount == 1;
            --v42->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v42);
          }
        }
        v43 = resulta.pNode;
        v19 = resulta.pNode->RefCount == 1;
        --v43->RefCount;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      }
    }
    v44 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, _DWORD, _QWORD))v68->vfptr[3].~RefCountBaseGC<328>)(
                      v68,
                      &v69,
                      &v63,
                      &p,
                      0,
                      0i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v63);
    if ( v39 > 9 )
    {
      if ( (v12 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        v62.Obj.pObject = 0i64;
        *(_QWORD *)&v62.Name.Flags = 0i64;
        v62.Name.Bonus.pWeakProxy = 0i64;
        v62.Kind = v12 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v62);
      }
    }
    if ( v44 )
      goto LABEL_42;
    v45 = p.Flags;
    v46.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p.Bonus;
    v47 = p.value;
    p.Flags = v4->Flags;
    p.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    p.value = v4->value;
    v4->Flags = v45;
    v4->Bonus = v46;
    v4->value = v47;
    v48 = v45 & 0x1F;
    if ( v48 > 4 && v48 != 10 )
    {
      v62.Kind = 0;
      v62.Obj.pObject = 0i64;
      other.Flags = 10;
      other.Bonus.pWeakProxy = 0i64;
      v49 = *(double *)&v66->Builtins[24].pNode;
      other.value.VNumber = v49;
      if ( *(_QWORD *)&v49 == *(_QWORD *)(*(_QWORD *)&v49 + 8i64) + 104i64 )
      {
        v49 = 0.0;
        other.value.VNumber = 0.0;
        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v65.pWeakProxy;
        LOBYTE(v11) = 12;
        other.Flags = 12;
      }
      else
      {
        ++*(_DWORD *)(*(_QWORD *)&v49 + 24i64);
      }
      v63.Kind = 0;
      v63.Obj.pObject = v9;
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
      v63.Name.Flags = 0;
      v63.Name.Bonus.pWeakProxy = 0i64;
      if ( (v11 & 0x1F) - 12 <= 3
        && v49 != 0.0
        && (v50 = *(_QWORD *)(*(_QWORD *)&v49 + 40i64), *(_DWORD *)(v50 + 120) == 17)
        && ~(*(_BYTE *)(v50 + 112) >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v63.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v49 + 56i64));
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v63.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v49 + 64i64));
        v63.Kind &= 0xFFFFFFF9;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v63.Name, &other);
        Scaleform::GFx::AS3::Multiname::PostProcessName(&v63, 0);
      }
      LODWORD(v58) = 0;
      v51 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Multiname *, __int64, _QWORD, _QWORD, Scaleform::GFx::AS3::Value::Extra, _QWORD, Scaleform::GFx::AS3::Value::V2U, _QWORD, Scaleform::GFx::AS3::Value::Extra, _QWORD, Scaleform::GFx::AS3::Value::V2U))v68->vfptr[3].~RefCountBaseGC<328>)(
                        v68,
                        &v69,
                        &v63,
                        &v62,
                        v58,
                        0i64,
                        *(_QWORD *)&p.Flags,
                        p.Bonus,
                        *(_QWORD *)&p.value.VNumber,
                        p.value.VS._2,
                        *(_QWORD *)&other.Flags,
                        other.Bonus,
                        *(_QWORD *)&other.value.VNumber,
                        other.value.VS._2) == 0;
      Scaleform::GFx::AS3::Multiname::~Multiname(&v63);
      Scaleform::GFx::AS3::Value::~Value(&other);
      if ( v51 )
      {
        v5->Result = 0;
        Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&v62);
LABEL_153:
        Scaleform::GFx::AS3::Value::~Value(&p);
        return v5;
      }
      v52 = v62.Kind;
      v53 = v62.Obj.pObject;
      v54 = *(double *)&v62.Name.Flags;
      v55.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v62.Name.Bonus;
      v62.Kind = v4->Flags;
      v62.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)v4->Bonus.pWeakProxy;
      *(long double *)&v62.Name.Flags = v4->value.VNumber;
      v62.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v4->value.VS._2.VObj;
      v4->Flags = v52;
      v4->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v53;
      v4->value.VNumber = v54;
      v4->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v55.pWeakProxy;
      Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&v62);
    }
LABEL_152:
    v5->Result = 1;
    goto LABEL_153;
  }
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  v13 = *(double *)&v8->Builtins[24].pNode;
  other.value.VNumber = v13;
  if ( *(_QWORD *)&v13 == *(_QWORD *)(*(_QWORD *)&v13 + 8i64) + 104i64 )
  {
    v13 = 0.0;
    other.value.VNumber = 0.0;
    v14.pWeakProxy = v65.pWeakProxy;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v65.pWeakProxy;
    v12 = 12;
    other.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v13 + 24i64);
    v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.value.VS._2.VObj;
  }
  v62.Kind = 0;
  v62.Obj.pObject = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v62.Name.Flags = 0;
  v62.Name.Bonus.pWeakProxy = 0i64;
  v15 = v12 & 0x1F;
  if ( (unsigned int)(v15 - 12) <= 3
    && v13 != 0.0
    && (v16 = *(_QWORD *)(*(_QWORD *)&v13 + 40i64), *(_DWORD *)(v16 + 120) == 17)
    && ~(*(_BYTE *)(v16 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v62.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v13 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v62.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v13 + 64i64));
    v62.Kind &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+130h+other.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v62.Name.Flags = *(_QWORD *)&other.Flags;
    v62.Name.Bonus.pWeakProxy = 0i64;
    v62.Name.value.VNumber = v13;
    v62.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    if ( v15 > 9 )
    {
      if ( (v12 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v15 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v13 + 24i64);
      }
      else if ( v15 > 10 )
      {
        if ( v15 <= 15 )
        {
          if ( v13 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v15 <= 17 && v14.pWeakProxy )
        {
          v14.pWeakProxy[2].RefCount = (v14.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
    if ( (v62.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v62.Name, &resulta);
      if ( resulta.pNode->Size )
      {
        if ( *resulta.pNode->pData == 64 )
        {
          v62.Kind |= 8u;
          v17 = Scaleform::GFx::ASString::Substring(&resulta, &v64, 1, resulta.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v62.Name, v17);
          v18 = v64.pNode;
          v19 = v64.pNode->RefCount == 1;
          --v18->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        }
      }
      v20 = resulta.pNode;
      v19 = resulta.pNode->RefCount == 1;
      --v20->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
  }
  v21 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, _DWORD, _QWORD))v68->vfptr[3].~RefCountBaseGC<328>)(
                    v68,
                    &v69,
                    &v62,
                    &p,
                    0,
                    0i64) == 0;
  Scaleform::GFx::AS3::Multiname::~Multiname(&v62);
  if ( v15 > 9 )
  {
    if ( (v12 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v12 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( v21 )
  {
LABEL_42:
    v5->Result = 0;
    goto LABEL_43;
  }
  v22 = p.Flags;
  v23.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p.Bonus;
  v24 = p.value;
  p.Flags = v4->Flags;
  p.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  p.value = v4->value;
  v4->Flags = v22;
  v4->Bonus = v23;
  v4->value = v24;
  v25 = v22 & 0x1F;
  if ( v25 > 4 && v25 != 10 )
  {
    other.Flags = 0;
    other.Bonus.pWeakProxy = 0i64;
    v62.Kind = 10;
    v62.Obj.pObject = 0i64;
    v26 = *(double *)&v66->Builtins[25].pNode;
    *(long double *)&v62.Name.Flags = v26;
    if ( *(_QWORD *)&v26 == *(_QWORD *)(*(_QWORD *)&v26 + 8i64) + 104i64 )
    {
      v26 = 0.0;
      *(_QWORD *)&v62.Name.Flags = 0i64;
      v27.pWeakProxy = v65.pWeakProxy;
      v62.Name.Bonus = v65;
      v11 = 12;
      v62.Kind = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v26 + 24i64);
      v27.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v62.Name.Bonus;
    }
    v63.Kind = 0;
    v63.Obj.pObject = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v63.Name.Flags = 0;
    v63.Name.Bonus.pWeakProxy = 0i64;
    v28 = v11 & 0x1F;
    if ( (unsigned int)(v28 - 12) <= 3
      && v26 != 0.0
      && (v29 = *(_QWORD *)(*(_QWORD *)&v26 + 40i64), *(_DWORD *)(v29 + 120) == 17)
      && ~(*(_BYTE *)(v29 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v63.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v26 + 56i64));
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v63.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v26 + 64i64));
      v63.Kind &= 0xFFFFFFF9;
    }
    else
    {
      __asm { prefetcht1 byte ptr [rbp+57h+var_B8.Kind]; Prefetch to all cache levels }
      *(_QWORD *)&v63.Name.Flags = *(_QWORD *)&v62.Kind;
      v63.Name.Bonus.pWeakProxy = 0i64;
      v63.Name.value.VNumber = v26;
      v63.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v27.pWeakProxy;
      if ( v28 > 9 )
      {
        if ( (v11 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] + 1;
        }
        else if ( v28 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v26 + 24i64);
        }
        else if ( v28 > 10 )
        {
          if ( v28 <= 15 )
          {
            if ( v26 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v26 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v26 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v28 <= 17 && v27.pWeakProxy )
          {
            v27.pWeakProxy[2].RefCount = (v27.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
      if ( (v63.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v63.Name, &resulta);
        if ( resulta.pNode->Size )
        {
          if ( *resulta.pNode->pData == 64 )
          {
            v63.Kind |= 8u;
            v30 = Scaleform::GFx::ASString::Substring(&resulta, &v64, 1, resulta.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v63.Name, v30);
            v31 = v64.pNode;
            v19 = v64.pNode->RefCount == 1;
            --v31->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
          }
        }
        v32 = resulta.pNode;
        v19 = resulta.pNode->RefCount == 1;
        --v32->RefCount;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      }
    }
    LODWORD(v57) = 0;
    v33 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, __int64, _QWORD))v68->vfptr[3].~RefCountBaseGC<328>)(
                      v68,
                      &v69,
                      &v63,
                      &other,
                      v57,
                      0i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v63);
    if ( v28 > 9 )
    {
      if ( (v11 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        v62.Obj.pObject = 0i64;
        *(_QWORD *)&v62.Name.Flags = 0i64;
        v62.Name.Bonus.pWeakProxy = 0i64;
        v62.Kind = v11 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v62);
      }
    }
    if ( v33 )
    {
      v5->Result = 0;
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v19 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      goto LABEL_43;
    }
    v34 = other.Flags;
    v35.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.Bonus;
    v36 = other.value;
    other.Flags = v4->Flags;
    other.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    other.value = v4->value;
    v4->Flags = v34;
    v4->Bonus = v35;
    v4->value = v36;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v19 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    goto LABEL_152;
  }
  v5->Result = 1;
LABEL_43:
  if ( (p.Flags & 0x1F) > 9 )
  {
    if ( (p.Flags >> 9) & 1 )
    {
      v19 = p.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      p.Bonus.pWeakProxy = 0i64;
      p.value = 0ui64;
      p.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
    }
  }
  return v5;
}

// File Line: 1506
// RVA: 0x7D3730
void __fastcall Scaleform::GFx::AS3::Object::FindProperty(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::FindPropAttr attr)
{
  Scaleform::GFx::AS3::FindPropAttr v4; // ebx
  Scaleform::GFx::AS3::PropRef *v5; // rdi
  Scaleform::GFx::AS3::Object *v6; // rsi
  Scaleform::GFx::AS3::SlotInfo *v7; // rax
  unsigned __int64 v8; // rdx
  unsigned int v9; // ebx
  bool v10; // zf
  Scaleform::GFx::AS3::Traits *v11; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS3::Traits *i; // rbx
  Scaleform::GFx::AS3::Object *v14; // rax
  Scaleform::GFx::AS3::SlotInfo *v15; // [rsp+38h] [rbp-38h]
  unsigned __int64 v16; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-28h]
  unsigned __int64 index; // [rsp+90h] [rbp+20h]
  Scaleform::GFx::AS3::Multiname *mna; // [rsp+A0h] [rbp+30h]
  Scaleform::GFx::AS3::FindPropAttr attra; // [rsp+A8h] [rbp+38h]

  attra = attr;
  mna = mn;
  v4 = attr;
  v5 = result;
  v6 = this;
  index = 0i64;
  v7 = Scaleform::GFx::AS3::FindFixedSlot(this->pTraits.pObject->pVM, this->pTraits.pObject, mn, &index, this);
  if ( v7 )
  {
    v15 = v7;
    v8 = index;
    v16 = index;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&other.value.VNumber = v6;
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
    v5->pSI = v7;
    v5->SlotIndex = v8;
    Scaleform::GFx::AS3::Value::Assign(&v5->This, &other);
    v9 = other.Flags;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags >> 9) & 1 )
      {
        v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        other.Bonus.pWeakProxy = 0i64;
        other.value = 0ui64;
        other.Flags = v9 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  else
  {
    v11 = v6->pTraits.pObject;
    if ( (LOBYTE(v11->Flags) >> 1) & 1 && (v4 != 2 || v11->TraitsType != 18 || !(~(LOBYTE(v11->Flags) >> 5) & 1)) )
    {
      v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::SlotInfo **, Scaleform::GFx::AS3::Multiname *))v6->vfptr[6].ForEachChild_GC)(
              v6,
              &v15,
              mna);
      v5->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      v5->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      v5->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      v5->SlotIndex = *(_QWORD *)(v12 + 8);
      Scaleform::GFx::AS3::Value::Assign(&v5->This, (Scaleform::GFx::AS3::Value *)(v12 + 16));
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags >> 9) & 1 )
        {
          v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          other.Bonus.pWeakProxy = 0i64;
          other.value = 0ui64;
          other.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
    }
    if ( (!(v5->This.Flags & 0x1F)
       || (_QWORD)v5->pSI & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFEui64)
       || ((unsigned __int8)v5->pSI >> 1) & 1 && !((_QWORD)v5->pSI & 0xFFFFFFFFFFFFFFFDui64))
      && v4 != 1 )
    {
      for ( i = v6->pTraits.pObject; i; i = i->pParent.pObject )
      {
        if ( !i->pConstructor.pObject )
          i->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&i->vfptr);
        v14 = Scaleform::GFx::AS3::Class::GetPrototype(i->pConstructor.pObject);
        if ( v14 == v6 )
          break;
        Scaleform::GFx::AS3::Object::FindProperty(v14, v5, mna, attra);
        if ( Scaleform::GFx::AS3::PropRef::operator bool(v5) )
          break;
      }
    }
  }
}

// File Line: 1552
// RVA: 0x7D0870
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::ExecutePropertyUnsafe(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *a4)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbx
  int v7; // ecx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  int v11; // eax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value scope; // [rsp+28h] [rbp-59h]
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp-39h]
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+68h] [rbp-19h]
  Scaleform::GFx::AS3::VM::Error v19; // [rsp+98h] [rbp+17h]
  __int64 v20; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+D8h] [rbp+57h]
  unsigned int v22; // [rsp+F8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v23; // [rsp+100h] [rbp+7Fh]

  v20 = -2i64;
  v4 = a4;
  v5 = result;
  resulta.pSI = 0i64;
  resulta.SlotIndex = 0i64;
  resulta.This.Flags = 0;
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&scope.value.VNumber = this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v6 = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, this->pTraits.pObject->pVM, &scope, prop_name, FindCall);
  if ( !(resulta.This.Flags & 0x1F)
    || (_QWORD)resulta.pSI & 1 && !((_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64)
    || (LOBYTE(resulta.pSI) >> 1) & 1 && !((_QWORD)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    if ( (LOBYTE(Scaleform::GFx::AS3::VM::GetValueTraits(v6, &scope)->Flags) >> 1) & 1
      || (v11 = scope.Flags & 0x1F, v11 <= 4)
      || v11 == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eCallOfNonFunctionError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eReadSealedError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
    v14 = v19.Message.pNode;
    v10 = v19.Message.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_45:
    v5->Result = v6->HandleException == 0;
    if ( (scope.Flags & 0x1F) > 9 )
    {
      if ( (scope.Flags >> 9) & 1 )
      {
        v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        scope.Bonus.pWeakProxy = 0i64;
        scope.value = 0ui64;
        scope.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
      }
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags >> 9) & 1 )
      {
        v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        goto LABEL_55;
      }
LABEL_56:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      return v5;
    }
    return v5;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, &v21, v6, &value, valExecute)->Result )
  {
    v7 = value.Flags & 0x1F;
    if ( value.Flags & 0x1F && ((unsigned int)(v7 - 12) > 3 && v7 != 10 || *(_QWORD *)&value.value.VNumber) )
    {
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, &value, &scope, v4, v22, v23, 0);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v19, eCallOfNonFunctionError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v9 = v19.Message.pNode;
      v10 = v19.Message.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    goto LABEL_45;
  }
  v5->Result = 0;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags >> 9) & 1 )
    {
      v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      scope.Bonus.pWeakProxy = 0i64;
      scope.value = 0ui64;
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  if ( (resulta.This.Flags & 0x1F) > 9 )
  {
    if ( !((resulta.This.Flags >> 9) & 1) )
      goto LABEL_56;
    v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
    if ( !v10 )
    {
LABEL_55:
      resulta.This.Bonus.pWeakProxy = 0i64;
      resulta.This.value = 0ui64;
      resulta.This.Flags &= 0xFFFFFDE0;
      return v5;
    }
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    resulta.This.Bonus.pWeakProxy = 0i64;
    resulta.This.value = 0ui64;
    resulta.This.Flags &= 0xFFFFFDE0;
  }
  return v5;
}

// File Line: 1596
// RVA: 0x7AC8A0
void __fastcall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::ASString *prop_name, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  BOOL v6; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASStringNode *v7; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h]

  v6 = a == 2;
  v7 = prop_name->pNode;
  ++v7->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v6;
  key.pSecond = v;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&this->DynAttrs.mHash.pTable,
    &this->DynAttrs,
    &key);
  v4 = v7;
  v5 = v7->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}

// File Line: 1603
// RVA: 0x7AC900
void __fastcall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::Value *prop_name, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::AS3::SlotInfo::Attribute v4; // esi
  Scaleform::GFx::AS3::Value *v5; // rbp
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::Object *v7; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h]
  __int64 v12; // [rsp+28h] [rbp-30h]
  BOOL v13; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASStringNode *v14; // [rsp+38h] [rbp-20h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+60h] [rbp+8h]

  v12 = -2i64;
  v4 = a;
  v5 = v;
  v6 = prop_name;
  v7 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v6, &v16, &result)->Result )
  {
    v13 = v4 == 2;
    v14 = result.pNode;
    ++v14->RefCount;
    key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v13;
    key.pSecond = v5;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v7->DynAttrs.mHash.pTable,
      &v7->DynAttrs,
      &key);
    v8 = v14;
    v9 = v14->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 1616
// RVA: 0x7C0940
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Multiname *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::Object *v5; // rsi
  char v6; // bp
  Scaleform::GFx::ASStringNode *v7; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // r10
  __int64 v9; // r9
  signed __int64 v10; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v11; // rcx
  signed __int64 v12; // rbx
  signed __int64 v13; // rbx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::Object::DynAttrsKey key; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v19; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v3 = mn;
  v4 = result;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(&v3->Name, &v19, &resulta)->Result )
  {
    v6 = 1;
    key.Flags = 0;
    v7 = resulta.pNode;
    key.Name = resulta;
    ++key.Name.pNode->RefCount;
    v8 = v5->DynAttrs.mHash.pTable;
    if ( !v8 )
      goto LABEL_13;
    v9 = v7->HashFlags & v8->SizeMask & 0xFFFFFF;
    v10 = (unsigned int)v9;
    v11 = &v8[4 * v9 + 1];
    if ( v11->EntryCount == -2i64 || v11->SizeMask != v9 )
      goto LABEL_13;
    while ( v11->SizeMask != v9 || (Scaleform::GFx::ASStringNode *)v11[1].SizeMask != v7 )
    {
      v10 = v11->EntryCount;
      if ( v11->EntryCount == -1i64 )
        goto LABEL_13;
      v11 = &v8[4 * v10 + 1];
    }
    if ( v10 >= 0 && (v12 = (signed __int64)&v8[4 * v10 + 2]) != 0 )
      v13 = v12 + 16;
    else
LABEL_13:
      v13 = 0i64;
    v14 = v7->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( v13 )
    {
      key.Flags = 0;
      v15 = resulta.pNode;
      key.Name = resulta;
      ++key.Name.pNode->RefCount;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Object::DynAttrsKey>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v5->DynAttrs.mHash.pTable,
        &key);
      v14 = v15->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      v6 = 0;
    }
    v4->Result = v6;
  }
  else
  {
    v4->Result = 0;
  }
  v16 = resulta.pNode;
  v14 = resulta.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return v4;
}

// File Line: 1656
// RVA: 0x7ECBD0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Object::GetNextDynPropIndex(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v3; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // r9
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // r11
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rax
  signed __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // r10
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rax
  bool v13; // zf
  bool v14; // sf
  unsigned __int8 v15; // of
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v16; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v17; // rdx
  unsigned int v18; // ecx
  Scaleform::GFx::AS3::GlobalSlotIndex *v19; // rax

  v3 = this->DynAttrs.mHash.pTable;
  v4 = &this->DynAttrs;
  v5 = result;
  if ( v3 )
  {
    v6 = v3->SizeMask;
    v7 = 0i64;
    v8 = v3 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v7;
      v8 += 4;
    }
    while ( v7 <= v6 );
  }
  else
  {
    v4 = 0i64;
  }
  if ( ind.Index )
    v9 = ind.Index - 1;
  else
    v9 = -1i64;
  if ( !v4 )
    goto LABEL_29;
  v10 = v4->mHash.pTable;
  if ( !v4->mHash.pTable )
    goto LABEL_29;
  v11 = v10->SizeMask;
  if ( v9 > (signed __int64)v11 )
    goto LABEL_29;
  v12 = v9 + 1;
  v15 = __OFSUB__(v12, v11);
  v13 = v12 == v11;
  v14 = (signed __int64)(v12 - v11) < 0;
  if ( v12 <= v11 )
  {
    v16 = &v10[4 * v12 + 1];
    do
    {
      if ( v16->EntryCount != -2i64 )
        break;
      ++v12;
      v16 += 4;
    }
    while ( v12 <= v11 );
    goto LABEL_16;
  }
LABEL_17:
  while ( (unsigned __int8)(v14 ^ v15) | v13 && v10[4 * v12 + 2].EntryCount & 1 )
  {
    v15 = __OFSUB__(++v12, v11);
    v13 = v12 == v11;
    v14 = (signed __int64)(v12 - v11) < 0;
    if ( v12 <= v11 )
    {
      v17 = &v10[4 * v12 + 1];
      do
      {
        if ( v17->EntryCount != -2i64 )
          break;
        ++v12;
        v17 += 4;
      }
      while ( v12 <= v11 );
LABEL_16:
      v15 = __OFSUB__(v12, v11);
      v13 = v12 == v11;
      v14 = (signed __int64)(v12 - v11) < 0;
      goto LABEL_17;
    }
  }
  if ( (signed __int64)v12 <= (signed __int64)v11 )
  {
    v18 = v12 + 1;
    v19 = v5;
    v5->Index = v18;
  }
  else
  {
LABEL_29:
    v5->Index = 0;
    v19 = v5;
  }
  return v19;
}

// File Line: 1675
// RVA: 0x7ECE70
void __fastcall Scaleform::GFx::AS3::Object::GetNextPropertyName(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v3; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v6; // rcx
  unsigned __int64 v7; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  v3 = &this->DynAttrs;
  v4 = 0i64;
  v5 = name;
  v6 = this->DynAttrs.mHash.pTable;
  if ( v6 )
  {
    v7 = v6->SizeMask;
    v8 = v6 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 4;
    }
    while ( (unsigned __int64)v4 <= v7 );
    v4 = v3;
  }
  Scaleform::GFx::AS3::Value::Assign(
    v5,
    (Scaleform::GFx::ASString *)&v4->mHash.pTable[4 * (unsigned __int64)(ind.Index - 1) + 2].SizeMask);
}

// File Line: 1685
// RVA: 0x7ED110
void __fastcall Scaleform::GFx::AS3::Object::GetNextPropertyValue(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, signed __int64, Scaleform::GFx::AS3::Value *))this->vfptr[1].Finalize_GC)(
      this,
      ind.Index - 1i64,
      value);
}

// File Line: 1702
// RVA: 0x7D1B50
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Object::FindDynamicSlot(Scaleform::GFx::AS3::Object *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::PropRef *v3; // rdi
  Scaleform::GFx::AS3::Object *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v7; // r10
  __int64 v8; // r9
  signed __int64 v9; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // rcx
  signed __int64 v11; // rax
  signed __int64 v12; // rax
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::PropRef *v17; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h]

  v17 = result;
  v3 = result;
  v4 = this;
  v5 = &mn->Name;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v5, &v16, &resulta)->Result )
  {
    v6 = resulta.pNode;
    ++resulta.pNode->RefCount;
    v7 = v4->DynAttrs.mHash.pTable;
    if ( !v7 )
      goto LABEL_13;
    v8 = v6->HashFlags & v7->SizeMask & 0xFFFFFF;
    v9 = (unsigned int)v8;
    v10 = &v7[4 * v8 + 1];
    if ( v10->EntryCount == -2i64 || v10->SizeMask != v8 )
      goto LABEL_13;
    while ( v10->SizeMask != v8 || (Scaleform::GFx::ASStringNode *)v10[1].SizeMask != v6 )
    {
      v9 = v10->EntryCount;
      if ( v10->EntryCount == -1i64 )
        goto LABEL_13;
      v10 = &v7[4 * v9 + 1];
    }
    if ( v9 >= 0 && (v11 = (signed __int64)&v7[4 * v9 + 2]) != 0 )
      v12 = v11 + 16;
    else
LABEL_13:
      v12 = 0i64;
    v3->pSI = (Scaleform::GFx::AS3::SlotInfo *)(v12 | 1);
    v3->This.Flags = 12;
    v3->This.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v3->This.value.VNumber = v4;
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
    v13 = v6->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  else
  {
    v3->pSI = 0i64;
    v3->SlotIndex = 0i64;
    v3->This.Flags = 0;
    v3->This.Bonus.pWeakProxy = 0i64;
  }
  v14 = resulta.pNode;
  v13 = resulta.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  return v3;
}

// File Line: 1776
// RVA: 0x7F0070
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetSuperProperty(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Value *a4, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Traits *v7; // rax
  Scaleform::GFx::AS3::VM *v8; // rsi
  Scaleform::GFx::AS3::CheckResult *v9; // rbx
  Scaleform::GFx::AS3::Traits *v10; // rdi
  Scaleform::GFx::AS3::SlotInfo *v11; // r12
  __int64 v12; // r8
  unsigned int v13; // edx
  Scaleform::GFx::AS3::Value::Extra v14; // rax
  Scaleform::GFx::AS3::Value::VU v15; // kr00_16
  Scaleform::GFx::AS3::WeakProxy *v16; // rdx
  bool v17; // zf
  Scaleform::GFx::AS3::WeakProxy *v18; // rdx
  unsigned __int64 index; // [rsp+40h] [rbp-30h]
  __int64 v21; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Value value; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+40h]

  v21 = -2i64;
  v6 = a4;
  v7 = ot;
  v8 = vm;
  v9 = result;
  if ( !ot )
    v7 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  v10 = v7->pParent.pObject;
  if ( !v10 )
    goto LABEL_18;
  index = 0i64;
  v11 = Scaleform::GFx::AS3::FindFixedSlot(v8, v10, mn, &index, 0i64);
  if ( !v11 )
    goto LABEL_18;
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Traits::GetVT(v10);
  if ( !Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(v11, &resulta, v8, &value)->Result )
  {
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v18 = value.Bonus.pWeakProxy;
        v17 = value.Bonus.pWeakProxy->RefCount == 1;
        --v18->RefCount;
        if ( v17 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v18,
            v12);
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
LABEL_18:
    v9->Result = 0;
    return v9;
  }
  v13 = value.Flags;
  v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)value.Bonus;
  v15 = value.value;
  value.Flags = v6->Flags;
  value.Bonus.pWeakProxy = v6->Bonus.pWeakProxy;
  value.value = v6->value;
  v6->Flags = v13;
  v6->Bonus = v14;
  v6->value = v15;
  v9->Result = 1;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v16 = value.Bonus.pWeakProxy;
      v17 = value.Bonus.pWeakProxy->RefCount == 1;
      --v16->RefCount;
      if ( v17 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v16,
          *(_QWORD *)&v15.VNumber);
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return v9;
}

// File Line: 1831
// RVA: 0x81E950
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SetSuperProperty(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Traits *ot, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits *v6; // rax
  Scaleform::GFx::AS3::VM *v7; // rbp
  Scaleform::GFx::AS3::CheckResult *v8; // rdi
  Scaleform::GFx::AS3::Traits *v9; // rsi
  Scaleform::GFx::AS3::Traits *v10; // rdx
  Scaleform::GFx::AS3::SlotInfo *v11; // r15
  bool v12; // al
  unsigned __int64 index; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h]

  v6 = ot;
  v7 = vm;
  v8 = result;
  if ( !ot )
    v6 = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  v9 = v6->pParent.pObject;
  if ( v9 )
  {
    v10 = v6->pParent.pObject;
    index = 0i64;
    v11 = Scaleform::GFx::AS3::FindFixedSlot(v7, v10, mn, &index, 0i64);
    v12 = 0;
    if ( v11 )
    {
      Scaleform::GFx::AS3::Traits::GetVT(v9);
      if ( Scaleform::GFx::AS3::SlotInfo::SetSlotValue(v11, &resulta, v7, value)->Result )
        v12 = 1;
    }
    v8->Result = v12;
  }
  else
  {
    v8->Result = 0;
  }
  return v8;
}

// File Line: 1879
// RVA: 0x7EF460
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(Scaleform::GFx::AS3::PropRef *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::SlotInfo::ValTarget vtt)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::PropRef *v6; // rdx
  Scaleform::GFx::AS3::SlotInfo *v7; // rcx
  bool v8; // di
  unsigned __int64 v9; // rcx
  int v10; // eax
  Scaleform::GFx::AS3::Value::V2U v12; // [rsp+48h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+8h]

  v5 = result;
  v6 = this;
  v7 = this->pSI;
  v8 = 1;
  if ( (unsigned __int8)v7 & 3 )
  {
    if ( ((unsigned __int8)v7 & 3) == 1i64 )
    {
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)((unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFEui64));
      v5->Result = 1;
      return v5;
    }
    if ( ((unsigned __int8)v7 & 3) == 2i64 )
    {
      value->Flags &= 0xFFFFFFEC;
      value->Flags |= 0xCu;
      v9 = (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFDui64;
      *(_QWORD *)&value->value.VNumber = v9;
      value->value.VS._2 = v12;
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 32);
        v5->Result = 1;
        *(_DWORD *)(v9 + 32) = (v10 + 1) & 0x8FBFFFFF;
        return v5;
      }
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(v7, &resulta, vm, value, &v6->This, 0i64, vtt)->Result;
  }
  v5->Result = v8;
  return v5;
}

// File Line: 1925
// RVA: 0x81D740
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::PropRef::SetSlotValue(Scaleform::GFx::AS3::PropRef *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  Scaleform::GFx::AS3::PropRef *v5; // rdx
  Scaleform::GFx::AS3::SlotInfo *v6; // rcx
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  bool v8; // cl
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]

  v4 = result;
  v5 = this;
  v6 = this->pSI;
  if ( (unsigned __int8)v6 & 3 )
  {
    if ( ((unsigned __int8)v6 & 3) == 1i64 )
    {
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)((unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFEui64),
        value);
      v4->Result = 1;
      v7 = v4;
    }
    else
    {
      v7 = v4;
      v4->Result = ((unsigned __int8)v6 & 3) != 2i64;
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS3::SlotInfo::SetSlotValue(v6, &resulta, vm, value, &v5->This, 0i64)->Result;
    v7 = v4;
    v4->Result = v8;
  }
  return v7;
}

// File Line: 1952
// RVA: 0x77BEC0
void __fastcall Scaleform::GFx::AS3::Class::Class(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // rsi
  Scaleform::GFx::AS3::Class *v3; // rbx
  Scaleform::GFx::AS3::ASRefCountCollector *v4; // r8
  Scaleform::GFx::AS3::Traits *v5; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v6; // rdi
  Scaleform::GFx::AS3::Class *v7; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rcx
  unsigned int v10; // eax

  v2 = t;
  v3 = this;
  v4 = t->pVM->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)v4;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable;
  this->pTraits.pObject = (Scaleform::GFx::AS3::Traits *)&t->vfptr;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Class::`vftable;
  v5 = t->pParent.pObject;
  if ( v5 )
  {
    v6 = v5[1].vfptr;
    if ( !v6[5].Finalize_GC )
      (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v6->ForEachChild_GC + 10))(v6);
    v7 = (Scaleform::GFx::AS3::Class *)v6[5].Finalize_GC;
  }
  else
  {
    v7 = 0i64;
  }
  v3->ParentClass.pObject = v7;
  if ( v7 )
    v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  v3->pPrototype.pObject = 0i64;
  v8 = v2->ITraits.pObject;
  v9 = v8->pConstructor.pObject;
  if ( v3 != v9 )
  {
    if ( v9 )
    {
      if ( (unsigned __int8)v9 & 1 )
      {
        v8->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v9 - 1);
      }
      else
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
        }
      }
    }
    v8->pConstructor.pObject = v3;
  }
}

// File Line: 1959
// RVA: 0x789F20
void __fastcall Scaleform::GFx::AS3::Class::~Class(Scaleform::GFx::AS3::Class *this)
{
  Scaleform::GFx::AS3::Class *v1; // rbx
  Scaleform::GFx::AS3::Object *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::Class *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Class::`vftable;
  v2 = this->pPrototype.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)v2 - 1);
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
  v4 = v1->ParentClass.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v1->ParentClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Object::~Object((Scaleform::GFx::AS3::Object *)&v1->vfptr);
}

// File Line: 1966
// RVA: 0x7B8830
void __fastcall Scaleform::GFx::AS3::Class::Construct(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv, bool extCall)
{
  Scaleform::GFx::AS3::Value *v5; // rbp
  unsigned int v6; // er14
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::Class *v8; // rdi
  Scaleform::GFx::AS3::Traits *v9; // rax
  Scaleform::GFx::AS3::VM *v10; // rsi
  int v11; // ecx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+28h] [rbp-30h]
  char v16; // [rsp+60h] [rbp+8h]

  v5 = argv;
  v6 = argc;
  v7 = _this;
  v8 = this;
  v9 = this->pTraits.pObject;
  v10 = v9->pVM;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))v9[1].vfptr->ForEachChild_GC
   + 11))(
    v9[1].vfptr,
    _this,
    v9[1].vfptr);
  v11 = v7->Flags & 0x1F;
  if ( ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !*(_QWORD *)&v7->value.VNumber )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eOutOfMemoryError, v10);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v10, v12, &Scaleform::GFx::AS3::fl_errors::MemoryErrorTI);
    v13 = v15.Message.pNode;
    v14 = v15.Message.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *, Scaleform::GFx::AS3::Value *))v8->vfptr[6].Finalize_GC)(
                   v8,
                   &v16,
                   v7) )
  {
    (*((void (__fastcall **)(_QWORD, bool))v7->value.VS._1.VStr->pData + 13))(*(_QWORD *)&v7->value.VNumber, extCall);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))v8->vfptr[7].ForEachChild_GC)(
      v8,
      v7,
      v6,
      v5);
  }
}

// File Line: 1995
// RVA: 0x8079F0
void __fastcall Scaleform::GFx::AS3::Class::PostInit(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *_this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  (*((void (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::AS3::Value *))_this->value.VS._1.VStr->pData + 11))(
    *(_QWORD *)&_this->value.VNumber,
    argc,
    argv);
}

// File Line: 2002
// RVA: 0x7D54F0
void __fastcall Scaleform::GFx::AS3::Class::ForEachChild_GC(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbx
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rdi
  Scaleform::GFx::AS3::Class *v5; // rsi

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->ParentClass.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->ParentClass);
  if ( v5->pPrototype.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->pPrototype);
}

// File Line: 2012
// RVA: 0x7F52D0
void __fastcall Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Object *obj, Scaleform::GFx::AS3::Value *(__fastcall *f)(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *))
{
  Scaleform::GFx::AS3::Value *(__fastcall *v3)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *); // r12
  Scaleform::GFx::AS3::Object *v4; // r13
  Scaleform::GFx::AS3::Class *v5; // r15
  Scaleform::GFx::AS3::Traits *v6; // rdi
  Scaleform::GFx::AS3::AbsoluteIndex v7; // rbx
  unsigned __int64 v8; // rsi
  Scaleform::GFx::AS3::SlotInfo *v9; // rax
  __int64 v10; // r14
  Scaleform::GFx::ASStringNode *v11; // rsi
  Scaleform::GFx::AS3::Value *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  int v15; // eax
  _DWORD *v16; // rdx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rcx
  unsigned int v19; // eax
  int v20; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v21; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  unsigned int v23; // [rsp+48h] [rbp-28h]
  _DWORD *v24; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v25; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::AS3::VTable *v27; // [rsp+B0h] [rbp+40h]

  v3 = f;
  v4 = obj;
  v5 = this;
  v6 = (Scaleform::GFx::AS3::Traits *)this->pTraits.pObject[1].vfptr;
  v27 = Scaleform::GFx::AS3::Traits::GetVT(v6);
  v7.Index = 0i64;
  v8 = v6->FirstOwnSlotNum;
  if ( v8 + v6->VArray.Data.Size )
  {
    do
    {
      if ( v7.Index < 0 || v7.Index < v8 )
        v9 = Scaleform::GFx::AS3::Slots::GetSlotInfo(v6->Parent, v7);
      else
        v9 = &v6->VArray.Data.Data[LODWORD(v7.Index) - v8].Value;
      v10 = *(_DWORD *)v9;
      if ( (*(_DWORD *)v9 & 0x7C00) == 11264 )
      {
        if ( v7.Index < 0 || v7.Index < v8 )
          v11 = Scaleform::GFx::AS3::Slots::GetSlotNameNode(v6->Parent, v7);
        else
          v11 = v6->VArray.Data.Data[LODWORD(v7.Index) - v8].Key.pObject;
        v12 = (Scaleform::GFx::AS3::Value *)(*(__int64 (__fastcall **)(char *, unsigned int *, Scaleform::GFx::AS3::Value *))v3)(
                                              (char *)v5 + *((signed int *)v3 + 2),
                                              &v23,
                                              &v27->VTMethods.Data.Data[(unsigned int)(v10 >> 15)]);
        ++v11->RefCount;
        v20 = 1;
        v21 = v11;
        ++v11->RefCount;
        key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v20;
        key.pSecond = v12;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v4->DynAttrs.mHash.pTable,
          &v4->DynAttrs,
          &key);
        v13 = v21;
        v14 = v21->RefCount == 1;
        --v13->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        v14 = v11->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v15 = v23 & 0x1F;
        if ( v15 > 9 )
        {
          if ( (v23 >> 9) & 1 )
          {
            v16 = v24;
            v14 = *v24 == 1;
            --*v16;
            if ( v14 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
                Scaleform::Memory::pGlobalHeap,
                v16);
            v24 = 0i64;
            v25 = 0i64;
            v26 = 0i64;
            v23 &= 0xFFFFFDE0;
          }
          else
          {
            switch ( v15 )
            {
              case 10:
                v17 = v25;
                v14 = v25->RefCount == 1;
                --v17->RefCount;
                if ( v14 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v17);
                break;
              case 11:
              case 12:
              case 13:
              case 14:
              case 15:
                v18 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v25;
                if ( !((unsigned __int8)v25 & 1) )
                  goto LABEL_27;
                v25 = (Scaleform::GFx::ASStringNode *)((char *)v25 - 1);
                break;
              case 16:
              case 17:
                v18 = v26;
                if ( (unsigned __int8)v26 & 1 )
                {
                  v26 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v26 - 1);
                }
                else
                {
LABEL_27:
                  if ( v18 )
                  {
                    v19 = v18->RefCount;
                    if ( v19 & 0x3FFFFF )
                    {
                      v18->RefCount = v19 - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
                    }
                  }
                }
                break;
              default:
                break;
            }
          }
        }
      }
      if ( v7.Index < 0 || v7.Index < v6->FirstOwnSlotNum + v6->VArray.Data.Size )
        ++v7.Index;
      v8 = v6->FirstOwnSlotNum;
    }
    while ( LODWORD(v7.Index) < v8 + v6->VArray.Data.Size );
  }
}

// File Line: 2043
// RVA: 0x7F4110
void __fastcall Scaleform::GFx::AS3::Class::InitPrototype(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *v2; // rbx
  Scaleform::GFx::AS3::Class *v3; // rcx
  Scaleform::GFx::AS3::Object *v4; // rdi
  __m128i v5; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = this->ParentClass.pObject;
  v4 = obj;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].Finalize_GC)();
  v5.m128i_i32[2] = 0;
  v5.m128i_i64[0] = (__int64)Scaleform::GFx::AS3::Class::ConvertCheckType;
  _mm_store_si128(&v5, v5);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    v2,
    v4,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v5);
  Scaleform::GFx::AS3::Class::AddConstructor(v2, v4);
}

// File Line: 2052
// RVA: 0x7AB920
void __fastcall Scaleform::GFx::AS3::Class::AddConstructor(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  int v8; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::ASStringNode *v9; // [rsp+30h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::Value v11; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v2 = obj;
  v11.Flags = 13;
  v11.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v11.value.VNumber = this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
         &result,
         "constructor");
  v8 = 1;
  v9 = v3->pNode;
  ++v9->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v8;
  key.pSecond = &v11;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v2->DynAttrs.mHash.pTable,
    &v2->DynAttrs,
    &key);
  v4 = v9;
  v5 = v9->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v6 = result.pNode;
  v5 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags >> 9) & 1 )
    {
      v7 = v11.Bonus.pWeakProxy;
      v5 = v11.Bonus.pWeakProxy->RefCount == 1;
      --v7->RefCount;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v7);
      v11.Bonus.pWeakProxy = 0i64;
      v11.value = 0ui64;
      v11.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
    }
  }
}

// File Line: 2062
// RVA: 0x8004E0
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Class::MakePrototype(Scaleform::GFx::AS3::Class *this, Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v2; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  v2->pV = (Scaleform::GFx::AS3::Object *)resulta.pV;
  return v2;
}

// File Line: 2067
// RVA: 0x7BACC0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Class::ConvertCopy(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *v)
{
  signed int v3; // eax
  long double v4; // rcx

  result->Flags = v->Flags;
  result->Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  result->value = v->value;
  v3 = v->Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (v->Flags >> 9) & 1 )
    {
      ++v->Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v3 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v->value.VNumber + 24i64);
        return result;
      }
      if ( v3 > 10 )
      {
        if ( v3 <= 15 )
        {
          v4 = v->value.VNumber;
        }
        else
        {
          if ( v3 > 17 )
            return result;
          v4 = *(double *)&v->value.VS._2.VObj;
        }
        if ( v4 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v4 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v4 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
  return result;
}

// File Line: 2073
// RVA: 0x7BAC10
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Class::ConvertCheckType(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Class *v4; // rsi
  long double v5; // rbp
  Scaleform::GFx::AS3::Classes::Function **v6; // rdi
  Scaleform::GFx::AS3::Instances::CheckTypeTF *v7; // rcx
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+38h] [rbp-20h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> resulta; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::Value *v11; // [rsp+68h] [rbp+10h]

  v11 = result;
  v3 = result;
  v4 = this;
  v5 = v->value.VNumber;
  v6 = (Scaleform::GFx::AS3::Classes::Function **)this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject;
  if ( !v6[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::Function **))(*v6)[1]._pRCC)(v6);
  v7 = Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
         v6[17],
         &resulta,
         v4,
         *(Scaleform::GFx::AS3::ThunkInfo **)&v5)->pV;
  v3->Flags = 0;
  v3->Bonus.pWeakProxy = 0i64;
  v3->Flags &= 0xFFFFFFEF;
  v3->Flags |= 0xFu;
  *(_QWORD *)&v3->value.VNumber = v7;
  v3->value.VS._2 = v9;
  return v3;
}

// File Line: 2078
// RVA: 0x7EE710
Scaleform::GFx::AS3::Object *__fastcall Scaleform::GFx::AS3::Class::GetPrototype(Scaleform::GFx::AS3::Class *this)
{
  Scaleform::GFx::AS3::Class *v1; // rdi
  Scaleform::GFx::AS3::Object **v2; // rax
  Scaleform::GFx::AS3::Object *v3; // rcx
  Scaleform::GFx::AS3::Object *v4; // rbx
  unsigned int v5; // eax
  char v7; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->pPrototype.pObject )
    return this->pPrototype.pObject;
  v2 = (Scaleform::GFx::AS3::Object **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *))this->vfptr[8].ForEachChild_GC)(
                                         this,
                                         &v7);
  v3 = v1->pPrototype.pObject;
  v4 = *v2;
  if ( *v2 != v3 )
  {
    if ( v3 )
    {
      if ( (unsigned __int8)v3 & 1 )
      {
        v1->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)v3 - 1);
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
    v1->pPrototype.pObject = v4;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Object *))v1->vfptr[7].Finalize_GC)(
    v1,
    v1->pPrototype.pObject);
  return v1->pPrototype.pObject;
}

// File Line: 2094
// RVA: 0x858980
void __fastcall Scaleform::GFx::AS3::Class::prototypeGet(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::Object *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::AS3::Class::GetPrototype(this);
  Scaleform::GFx::AS3::Value::Assign(v2, v3);
}

// File Line: 2099
// RVA: 0x861A20
void __fastcall Scaleform::GFx::AS3::Class::toString(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Class *v3; // rbx
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::String *v5; // rax
  Scaleform::String *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString v12; // [rsp+50h] [rbp+8h]
  Scaleform::String v13; // [rsp+58h] [rbp+10h]
  Scaleform::String resulta; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::ASStringNode *v15; // [rsp+68h] [rbp+20h]

  v2 = result;
  v3 = this;
  v4 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **))this->pTraits.pObject->vfptr[1].~RefCountBaseGC<328>)(
                                     this->pTraits.pObject,
                                     &v15);
  v5 = Scaleform::operator+(&resulta, "[class ", v4);
  v6 = Scaleform::String::operator+(v5, &v13, "]");
  v7 = Scaleform::GFx::AS3::Object::GetASString((Scaleform::GFx::AS3::Object *)&v3->vfptr, &v12, v6)->pNode;
  ++v7->RefCount;
  v8 = v2->pNode;
  v9 = v2->pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v2->pNode = v7;
  v10 = v12.pNode;
  v9 = v12.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v13.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v11 = v15;
  v9 = v15->RefCount == 1;
  --v11->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}

// File Line: 2110
// RVA: 0x7B2850
void __fastcall Scaleform::GFx::AS3::Class::Call(Scaleform::GFx::AS3::Class *this, Scaleform::GFx::AS3::Value *__formal, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Class *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h]

  v5 = this;
  if ( argc == 1 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *const , Scaleform::GFx::AS3::Value *))this->pTraits.pObject->vfptr[3].Finalize_GC)(
           this->pTraits.pObject,
           argv,
           result) )
    {
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eCheckTypeFailedError, v5->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eCoerceArgumentCountError, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::RangeErrorTI);
  }
  v8 = v10.Message.pNode;
  v9 = v10.Message.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 2141
// RVA: 0x7AAE90
void __fastcall Scaleform::GFx::AS3::NamespaceSet::Add(Scaleform::GFx::AS3::NamespaceSet *this, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v2; // rdi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rdx
  unsigned int v5; // eax

  v2 = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  v3 = &this->Namespaces;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Namespaces,
    &this->Namespaces,
    this->Namespaces.Data.Size + 1);
  v4 = &v3->Data.Data[v3->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = v2;
    if ( v2 )
      v2->RefCount = (v2->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( v2 && !((unsigned __int8)v2 & 1) )
  {
    v5 = v2->RefCount;
    if ( v5 & 0x3FFFFF )
    {
      v2->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
    }
  }
}

// File Line: 2149
// RVA: 0x784E70
void __fastcall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  this->Flags = 12;
  this->Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&this->value.VNumber = v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2163
// RVA: 0x7B1950
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Object *v4; // rdi
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
  v2->Flags &= 0xFFFFFFEC;
  v2->Flags |= 0xCu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2172
// RVA: 0x7B1BD0
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  *(_QWORD *)&this->value.VNumber = v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2181
// RVA: 0x7B17A0
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Class *v4; // rdi
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
  v2->Flags &= 0xFFFFFFED;
  v2->Flags |= 0xDu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2190
// RVA: 0x7B1B70
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFED;
  this->Flags |= 0xDu;
  *(_QWORD *)&this->value.VNumber = v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2199
// RVA: 0x807270
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Object *v4; // rdi
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
  v2->Flags &= 0xFFFFFFEC;
  v2->Flags |= 0xCu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
}

// File Line: 2207
// RVA: 0x807490
void __fastcall Scaleform::GFx::AS3::Value::PickUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  *(_QWORD *)&this->value.VNumber = v;
  this->value.VS._2 = v2;
}

// File Line: 2215
// RVA: 0x8070F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Class *v4; // rdi
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
  v2->Flags &= 0xFFFFFFED;
  v2->Flags |= 0xDu;
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
}

