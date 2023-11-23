// File Line: 117
// RVA: 0x7AE460
void __fastcall Scaleform::GFx::AS3::Value::AddRefInternal(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rdx

  if ( (this->Flags & 0x1F) == 10 )
  {
    ++this->value.VS._1.VStr->RefCount;
  }
  else
  {
    if ( (this->Flags & 0x1F) <= 0xA )
      return;
    if ( (this->Flags & 0x1F) <= 0xF )
    {
      VObj = this->value.VS._1;
    }
    else
    {
      if ( (this->Flags & 0x1F) > 0x11 )
        return;
      VObj = (Scaleform::GFx::AS3::Value::V1U)this->value.VS._2.VObj;
    }
    if ( VObj.VStr )
      VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
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
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  pWeakProxy = this->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Flags &= 0xFFFFFDE0;
  this->Bonus.pWeakProxy = 0i64;
  this->value.VS._1.VStr = 0i64;
  this->value.VS._2.VObj = 0i64;
}

// File Line: 175
// RVA: 0x810F60
void __fastcall Scaleform::GFx::AS3::Value::ReleaseInternal(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rdx
  unsigned int Size; // eax

  switch ( this->Flags & 0x1F )
  {
    case 0xAu:
      VStr = this->value.VS._1.VStr;
      if ( VStr->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      break;
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      VObj = this->value.VS._1;
      if ( !VObj.VBool )
        goto LABEL_8;
      this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)VObj.VStr - 1);
      break;
    case 0x10u:
    case 0x11u:
      VObj = (Scaleform::GFx::AS3::Value::V1U)this->value.VS._2.VObj;
      if ( VObj.VBool )
      {
        this->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&VObj.VStr[-1].Size + 7);
      }
      else
      {
LABEL_8:
        if ( VObj.VStr )
        {
          Size = VObj.VStr->Size;
          if ( (Size & 0x3FFFFF) != 0 )
          {
            VObj.VStr->Size = Size - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj.VObj);
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
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringManager *sm,
        Scaleform::GFx::AS3::Value *a4,
        Scaleform::GFx::AS3::Value::Hint hint)
{
  unsigned int v7; // edx
  Scaleform::GFx::AS3::Object *VObj; // rcx
  Scaleform::GFx::AS3::CheckResult *v9; // rax
  Scaleform::GFx::ASStringNode *ConstStringNode; // rax
  Scaleform::GFx::AS3::Value::V2U v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF

  v7 = this->Flags & 0x1F;
  if ( v7 <= 4 || v7 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(a4, this);
  }
  else
  {
    if ( ((v7 - 5) & 0xFFFFFFFD) == 0 )
      goto LABEL_15;
    if ( v7 == 11 )
    {
      Scaleform::GFx::AS3::Value::Assign(a4, (Scaleform::GFx::ASString *)&this->value.VS._1.VStr[1].16);
      result->Result = 1;
      return result;
    }
    if ( v7 - 16 <= 1 )
    {
LABEL_15:
      Scaleform::GFx::AS3::Value::SetNumber(a4, 0.0);
      result->Result = 1;
      return result;
    }
    VObj = this->value.VS._1.VObj;
    if ( VObj )
    {
      if ( !Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(VObj, &resulta, a4, hint)->Result )
      {
        result->Result = 0;
        return result;
      }
    }
    else if ( hint >= hintNone )
    {
      if ( hint <= hintNumber )
      {
        a4->Flags &= 0xFFFFFFE4;
        a4->Flags |= 4u;
        result->Result = 1;
        v9 = result;
        a4->value.VS._1.VStr = 0i64;
        a4->value.VS._2 = v11;
        return v9;
      }
      if ( hint == hintString )
      {
        ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(sm, "null", 4ui64, 0);
        Scaleform::GFx::AS3::Value::AssignUnsafe(a4, ConstStringNode);
        result->Result = 1;
        return result;
      }
    }
  }
  result->Result = 1;
  return result;
}

// File Line: 323
// RVA: 0x7BA270
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *a3)
{
  unsigned int v4; // edx
  Scaleform::GFx::AS3::Object *VObj; // rcx
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF

  v4 = this->Flags & 0x1F;
  if ( v4 <= 4 || v4 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(a3, this);
  }
  else
  {
    if ( ((v4 - 5) & 0xFFFFFFFD) == 0 )
      goto LABEL_11;
    if ( v4 == 11 )
    {
      Scaleform::GFx::AS3::Value::Assign(a3, (Scaleform::GFx::ASString *)&this->value.VS._1.VStr[1].16);
      result->Result = 1;
      return result;
    }
    if ( v4 - 16 <= 1 )
    {
LABEL_11:
      Scaleform::GFx::AS3::Value::SetNumber(a3, 0.0);
      result->Result = 1;
      return result;
    }
    VObj = this->value.VS._1.VObj;
    if ( !VObj )
    {
      a3->Flags &= 0xFFFFFFE4;
      a3->Flags |= 4u;
      result->Result = 1;
      v6 = result;
      a3->value.VS._1.VStr = 0i64;
      a3->value.VS._2 = v7;
      return v6;
    }
    if ( !Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(VObj, &resulta, a3, hintNumber)->Result )
    {
      result->Result = 0;
      return result;
    }
  }
  result->Result = 1;
  return result;
}

// File Line: 371
// RVA: 0x7BF930
Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> *__fastcall Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(
        Scaleform::GFx::AS3::GASRefCountBase *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> *result)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *v4; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v6; // rbx
  __int64 v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // r8
  __int64 v12; // rdx
  __int64 v13; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v14; // rax
  Scaleform::GFx::AS3::WeakProxy *SizeMask; // rax
  Scaleform::GFx::AS3::WeakProxy *v16; // rax
  unsigned __int64 v17; // rax
  Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeRef key; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::GASRefCountBase *v20; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::GASRefCountBase *v21; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::AS3::WeakProxy *v22; // [rsp+88h] [rbp+20h] BYREF

  v20 = this;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)(this->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64);
  v22 = 0i64;
  v21 = this;
  pTable = v4[17].pTable;
  v6 = 5381i64;
  v7 = 8i64;
  if ( pTable )
  {
    v8 = 5381i64;
    v9 = 8i64;
    do
    {
      --v9;
      v10 = 65599 * v8 + *((unsigned __int8 *)&v21 + v9);
      v8 = v10;
    }
    while ( v9 );
    v11 = v10 & pTable->SizeMask;
    v12 = v11;
    v13 = (__int64)&pTable[2 * v11 + 1];
    if ( *(_QWORD *)v13 != -2i64 && *(_QWORD *)(v13 + 8) == v11 )
    {
      while ( *(_QWORD *)(v13 + 8) != v11 || *(Scaleform::GFx::AS3::GASRefCountBase **)(v13 + 16) != this )
      {
        v12 = *(_QWORD *)v13;
        if ( *(_QWORD *)v13 == -1i64 )
          goto LABEL_13;
        v13 = (__int64)&pTable[2 * v12 + 1];
      }
      if ( v12 >= 0 )
      {
        v14 = &pTable[2 * v12 + 2];
        if ( v14 )
        {
          SizeMask = (Scaleform::GFx::AS3::WeakProxy *)v14->SizeMask;
          v22 = SizeMask;
LABEL_20:
          ++SizeMask->RefCount;
          result->pV = v22;
          return result;
        }
      }
    }
  }
LABEL_13:
  LODWORD(v21) = 328;
  v16 = (Scaleform::GFx::AS3::WeakProxy *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::GASRefCountBase *, __int64, Scaleform::GFx::AS3::GASRefCountBase **, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            16i64,
                                            &v21,
                                            -2i64);
  key.pFirst = (Scaleform::GFx::AS3::GASRefCountBase *const *)v16;
  if ( v16 )
  {
    v16->RefCount = 1;
    v16->pObject = this;
  }
  v22 = v16;
  if ( v16 )
  {
    this->RefCount |= 0x4000000u;
    v20 = this;
    key.pFirst = &v20;
    key.pSecond = &v22;
    do
    {
      --v7;
      v17 = 65599 * v6 + *((unsigned __int8 *)&v20 + v7);
      v6 = v17;
    }
    while ( v7 );
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeRef>(
      v4 + 17,
      &v4[17],
      &key,
      v17);
    SizeMask = v22;
    goto LABEL_20;
  }
  result->pV = 0i64;
  return result;
}key,
      v17);
    SizeMask = v22;
    goto LABEL_20;
  }
  r

// File Line: 395
// RVA: 0x7D5FC0
void __fastcall Scaleform::GFx::AS3::NamespaceSet::ForEachChild_GC(
        Scaleform::GFx::AS3::NamespaceSet *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 Size; // rdi
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v8; // rdx

  Size = this->Namespaces.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v8 = &this->Namespaces.Data.Data[i];
    if ( v8->pObject )
      op(prcc, &v8->pObject);
  }
}

// File Line: 416
// RVA: 0x780020
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  this->Kind = MN_QName;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v4 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
         vm->StringManagerRef,
         &result);
  Scaleform::GFx::AS3::Value::Assign(&this->Name, v4);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->PublicNamespace.pObject);
}

// File Line: 428
// RVA: 0x7800C0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v5; // edx
  Scaleform::GFx::AS3::Value::V1U v6; // rbp
  const char *pData; // rax
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::VM::Error v16; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v18; // [rsp+88h] [rbp+20h] BYREF

  this->Kind = MN_QName;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v5 = v->Flags & 0x1F;
  if ( v5 - 2 <= 2 || v5 == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v);
    if ( (this->Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&this->Name, &result);
      pNode = result.pNode;
      if ( result.pNode->Size )
      {
        if ( *result.pNode->pData == 64 )
        {
          this->Kind |= 8u;
          v13 = Scaleform::GFx::ASString::Substring(&result, &v18, 1, pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&this->Name, v13);
          v14 = v18.pNode;
          v10 = v18.pNode->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        }
      }
      v15 = result.pNode;
      v10 = result.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
  }
  else
  {
    if ( v5 - 12 <= 3 )
    {
      v6 = v->value.VS._1;
      if ( v6.VStr )
      {
        pData = v6.VStr[1].pData;
        if ( *((_DWORD *)pData + 30) == 17 && (pData[112] & 0x20) == 0 )
        {
          Scaleform::GFx::AS3::Value::Assign(&this->Name, (Scaleform::GFx::ASString *)&v6.VStr[1].16);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
            *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v6.VStr[1].RefCount);
          this->Kind &= 0xFFFFFFF9;
          return;
        }
      }
    }
    if ( v5 - 12 > 3 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, 1508, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
LABEL_11:
      v9 = v16.Message.pNode;
      v10 = v16.Message.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      return;
    }
    if ( !v->value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v16, 1001, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      goto LABEL_11;
    }
    Scaleform::GFx::AS3::Value::Assign(&this->Name, v);
    if ( !Scaleform::GFx::AS3::Value::ToStringValue(
            &this->Name,
            (Scaleform::GFx::AS3::CheckResult *)&result,
            vm->StringManagerRef)->Result )
      return;
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->DefXMLNamespace.pObject);
  if ( !this->Obj.pObject )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->PublicNamespace.pObject);
}

// File Line: 474
// RVA: 0x77FFD0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        Scaleform::GFx::AS3::Value *name)
{
  this->Kind = MN_QName;
  this->Obj.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(this, name);
}

// File Line: 491
// RVA: 0x7802E0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::ASString *InternedString; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int32 v9; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *InternedNamespaceSet; // rax
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  this->Kind = mn->Kind;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  if ( *(_QWORD *)&mn->NameIndex || mn->Ind )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(file, &result, mn->NameIndex);
    Scaleform::GFx::AS3::Value::Assign(&this->Name, InternedString);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  }
  v9 = mn->Kind & 3;
  if ( v9 )
  {
    if ( v9 != 2 )
      return;
    InternedNamespaceSet = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VMFile::GetInternedNamespaceSet(
                                                                            file,
                                                                            mn->Ind);
  }
  else
  {
    if ( !mn->Ind )
      return;
    InternedNamespaceSet = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                                                                            file,
                                                                            mn->Ind);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
    InternedNamespaceSet);
}

// File Line: 514
// RVA: 0x780690
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::StringDataPtr *qname)
{
  char v6; // r15
  signed __int64 LastChar; // r9
  unsigned __int64 v8; // rax
  unsigned __int64 Size; // r12
  const char *v10; // r13
  unsigned __int64 v11; // r12
  Scaleform::GFx::ASString *v12; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v25; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h] BYREF

  this->Kind = MN_QName;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  v6 = 1;
  LastChar = Scaleform::StringDataPtr::FindLastChar(qname, 58, 0xFFFFFFFFFFFFFFFFui64);
  if ( LastChar < 0 )
  {
    v6 = 0;
    LastChar = Scaleform::StringDataPtr::FindLastChar(qname, 46, 0xFFFFFFFFFFFFFFFFui64);
  }
  v8 = LastChar + 1;
  Size = qname->Size;
  if ( Size < LastChar + 1 )
    v8 = qname->Size;
  v10 = &qname->pStr[v8];
  v11 = Size - v8;
  if ( LastChar <= 0 )
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)vm->PublicNamespace.pObject);
  }
  else
  {
    if ( v6 )
    {
      if ( --LastChar < 0 )
        LastChar = 0i64;
    }
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            vm->StringManagerRef,
            &result,
            qname->pStr,
            LastChar);
    if ( v12->pNode->Size )
    {
      pObject = vm->TraitsNamespace.pObject->ITraits.pObject;
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
        *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&pObject[1].RefCount,
        &v25,
        NS_Public,
        v12,
        &v);
      pV = v25.pV;
    }
    else
    {
      pV = vm->PublicNamespace.pObject;
      if ( pV )
        pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    }
    v15 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->Obj.pObject;
    if ( pV != v15 )
    {
      if ( v15 )
      {
        if ( ((unsigned __int8)v15 & 1) != 0 )
        {
          this->Obj.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v15 - 1);
        }
        else
        {
          RefCount = v15->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v15->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
          }
        }
      }
      this->Obj.pObject = pV;
    }
    pNode = result.pNode;
    v18 = result.pNode->RefCount-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
             vm->StringManagerRef,
             (Scaleform::GFx::ASString *)&v25,
             v10,
             v11);
  Scaleform::GFx::AS3::Value::Assign(&this->Name, String);
  v20 = (Scaleform::GFx::ASStringNode *)v25.pV;
  v18 = LODWORD(v25.pV->pPrev)-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( (this->Name.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&this->Name, (Scaleform::GFx::ASString *)&v25);
    v21 = v25.pV;
    if ( v25.pV->RefCount )
    {
      if ( LOBYTE(v25.pV->vfptr->ForEachChild_GC) == 64 )
      {
        this->Kind |= 8u;
        v22 = Scaleform::GFx::ASString::Substring((Scaleform::GFx::ASString *)&v25, &result, 1, v21->RefCount);
        Scaleform::GFx::AS3::Value::Assign(&this->Name, v22);
        v23 = result.pNode;
        v18 = result.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      }
    }
    v24 = (Scaleform::GFx::ASStringNode *)v25.pV;
    v18 = LODWORD(v25.pV->pPrev)-- == 1;
    if ( v18 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  }
}

// File Line: 543
// RVA: 0x780490
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::TypeInfo *ti)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  Scaleform::GFx::ASString *v7; // r14
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *ConstString; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v20; // [rsp+88h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+18h] BYREF

  this->Kind = MN_QName;
  this->Obj.pObject = 0i64;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0i64;
  StringManagerRef = vm->StringManagerRef;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         StringManagerRef,
         &result,
         ti->PkgName);
  if ( v7->pNode->Size )
  {
    pObject = vm->TraitsNamespace.pObject->ITraits.pObject;
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::GFx::AS3::NamespaceInstanceFactory::MakeNamespace(
      *(Scaleform::GFx::AS3::NamespaceInstanceFactory **)&pObject[1].RefCount,
      &v20,
      NS_Public,
      v7,
      &v);
    pV = v20.pV;
  }
  else
  {
    pV = vm->PublicNamespace.pObject;
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
  }
  v10 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->Obj.pObject;
  if ( pV != v10 )
  {
    if ( v10 )
    {
      if ( ((unsigned __int8)v10 & 1) != 0 )
      {
        this->Obj.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v10 - 1);
      }
      else
      {
        RefCount = v10->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v10->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
        }
      }
    }
    this->Obj.pObject = pV;
  }
  pNode = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  ConstString = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                  StringManagerRef,
                  (Scaleform::GFx::ASString *)&v20,
                  ti->Name);
  Scaleform::GFx::AS3::Value::Assign(&this->Name, ConstString);
  v15 = (Scaleform::GFx::ASStringNode *)v20.pV;
  v13 = LODWORD(v20.pV->pPrev)-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( (this->Name.Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&this->Name, (Scaleform::GFx::ASString *)&v20);
    v16 = v20.pV;
    if ( v20.pV->RefCount )
    {
      if ( LOBYTE(v20.pV->vfptr->ForEachChild_GC) == 64 )
      {
        this->Kind |= 8u;
        v17 = Scaleform::GFx::ASString::Substring((Scaleform::GFx::ASString *)&v20, &result, 1, v16->RefCount);
        Scaleform::GFx::AS3::Value::Assign(&this->Name, v17);
        v18 = result.pNode;
        v13 = result.pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      }
    }
    v19 = (Scaleform::GFx::ASStringNode *)v20.pV;
    v13 = LODWORD(v20.pV->pPrev)-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  }
}

// File Line: 559
// RVA: 0x7803C0
void __fastcall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Multiname *other)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // r8
  unsigned int Flags; // r8d
  Scaleform::GFx::AS3::Value::V2U v4; // r8
  Scaleform::GFx::AS3::Value::V1U v5; // r8

  this->Kind = other->Kind;
  pObject = other->Obj.pObject;
  this->Obj.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = other->Name.Flags;
  this->Name.Bonus.pWeakProxy = other->Name.Bonus.pWeakProxy;
  this->Name.value = other->Name.value;
  Flags = other->Name.Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++other->Name.Bonus.pWeakProxy->RefCount;
    }
    else if ( (other->Name.Flags & 0x1F) == 10 )
    {
      ++other->Name.value.VS._1.VStr->RefCount;
    }
    else if ( (other->Name.Flags & 0x1F) > 0xA )
    {
      if ( (other->Name.Flags & 0x1F) <= 0xF )
      {
        v5 = other->Name.value.VS._1;
        if ( v5.VStr )
          v5.VStr->Size = (v5.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (other->Name.Flags & 0x1F) <= 0x11 )
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
  Scaleform::GFx::AS3::Value *p_Name; // rcx
  int v2; // edx
  bool v3; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  p_Name = &this->Name;
  v2 = p_Name->Flags & 0x1F;
  if ( !v2 )
    return 1;
  if ( (unsigned int)(v2 - 12) > 3 && v2 != 10 )
    return 0;
  if ( !p_Name->value.VS._1.VStr )
    return 1;
  if ( v2 != 10 )
    return 0;
  Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(p_Name, &result);
  v3 = !result.pNode->Size || *result.pNode->pData == pattern[0] && !*((_BYTE *)result.pNode->pData + 1);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return v3;
}

// File Line: 579
// RVA: 0x7B9980
bool __fastcall Scaleform::GFx::AS3::Multiname::ContainsNamespace(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rdx
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // r9
  __int64 v6; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *i; // rdx

  pObject = this->Obj.pObject;
  if ( (this->Kind & 3) != 2 )
    return pObject[1].pNext == (Scaleform::GFx::AS3::RefCountBaseGC<328> *)ns->Uri.pNode
        && ((*((_BYTE *)ns + 40) ^ LOBYTE(pObject[1].vfptr)) & 0xF) == 0;
  pRCC = pObject[1]._pRCC;
  v6 = 0i64;
  if ( pRCC )
  {
    for ( i = pObject[1].vfptr;
          (Scaleform::GFx::ASStringNode *)*((_QWORD *)i->ForEachChild_GC + 7) != ns->Uri.pNode
       || ((*((_BYTE *)ns + 40) ^ *((_BYTE *)i->ForEachChild_GC + 40)) & 0xF) != 0;
          i = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)((char *)i + 8) )
    {
      if ( ++v6 >= (unsigned __int64)pRCC )
        return 0;
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 594
// RVA: 0x807370
void __fastcall Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VSBase *vs)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  Scaleform::GFx::AS3::Value::V1U v5; // rax
  const char *pData; // rcx
  Scaleform::GFx::AS3::Value::V1U v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  pCurrent = vs->pCurrent;
  if ( (pCurrent->Flags & 0x1F) - 12 > 3
    || (v5 = pCurrent->value.VS._1, !v5.VStr)
    || (pData = v5.VStr[1].pData, *((_DWORD *)pData + 30) != 17)
    || (pData[112] & 0x20) != 0 )
  {
    this->Name.Flags = pCurrent->Flags;
    this->Name.Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
    this->Name.value.VS._1.VStr = pCurrent->value.VS._1.VStr;
    this->Name.value.VS._2.VObj = pCurrent->value.VS._2.VObj;
    --vs->pCurrent;
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
    return;
  }
  v7 = pCurrent->value.VS._1;
  Scaleform::GFx::AS3::Value::Assign(&this->Name, (Scaleform::GFx::ASString *)&v7.VStr[1].16);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
    *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v7.VStr[1].RefCount);
  this->Kind &= 0xFFFFFFF9;
  v8 = vs->pCurrent;
  if ( (vs->pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_11:
    --vs->pCurrent;
    return;
  }
  if ( (vs->pCurrent->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(vs->pCurrent);
    goto LABEL_11;
  }
  pWeakProxy = v8->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v8->Flags &= 0xFFFFFDE0;
  v8->Bonus.pWeakProxy = 0i64;
  v8->value.VS._1.VStr = 0i64;
  v8->value.VS._2.VObj = 0i64;
  --vs->pCurrent;
}

// File Line: 636
// RVA: 0x81D3A0
void __fastcall Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Value *nameVal)
{
  Scaleform::GFx::AS3::Value::V1U v3; // rbx
  const char *pData; // rax

  if ( (nameVal->Flags & 0x1F) - 12 <= 3
    && (v3 = nameVal->value.VS._1, v3.VStr)
    && (pData = v3.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&this->Name, (Scaleform::GFx::ASString *)&v3.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v3.VStr[1].RefCount);
    this->Kind &= 0xFFFFFFF9;
  }
  else
  {
    Scaleform::GFx::AS3::Value::AssignUnsafe(&this->Name, nameVal);
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
  }
}

// File Line: 654
// RVA: 0x807CF0
void __fastcall Scaleform::GFx::AS3::Multiname::PostProcessName(
        Scaleform::GFx::AS3::Multiname *this,
        const bool fromQName)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v9; // [rsp+50h] [rbp+18h] BYREF

  if ( (this->Name.Flags & 0x1F) == 10 && !fromQName )
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&this->Name, &result);
    pNode = result.pNode;
    if ( result.pNode->Size )
    {
      if ( *result.pNode->pData == 64 )
      {
        this->Kind |= 8u;
        v4 = Scaleform::GFx::ASString::Substring(&result, &v9, 1, pNode->Size);
        Scaleform::GFx::AS3::Value::Assign(&this->Name, v4);
        v5 = v9.pNode;
        v6 = v9.pNode->RefCount-- == 1;
        if ( v6 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      }
    }
    v7 = result.pNode;
    v6 = result.pNode->RefCount-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 683
// RVA: 0x7D3EB0
void __fastcall Scaleform::GFx::AS3::FindScopeProperty(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        unsigned __int64 baseSSInd,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *scope_stack,
        Scaleform::GFx::AS3::Multiname *mn)
{
  unsigned __int64 Size; // rbx
  unsigned __int64 v10; // rdi

  Size = scope_stack->Data.Size;
  if ( Size > baseSSInd )
  {
    v10 = Size;
    do
    {
      Scaleform::GFx::AS3::FindPropertyWith(result, vm, &scope_stack->Data.Data[v10 - 1], mn);
      if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
        break;
      --Size;
      --v10;
    }
    while ( Size > baseSSInd );
  }
}

// File Line: 715
// RVA: 0x7D27E0
void __fastcall Scaleform::GFx::AS3::FindGOProperty(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl::GlobalObject *,2,Scaleform::ArrayDefaultPolicy> *go,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::ClassTraits::Traits *ctr)
{
  __int64 v8; // r12
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rdi
  Scaleform::GFx::AS3::Value::V1U v11; // rbx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Value scope; // [rsp+38h] [rbp-50h] BYREF

  v8 = 0i64;
  if ( ctr )
    v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))ctr->vfptr[2].~RefCountBaseGC<328>)(ctr);
  Size = go->Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v11 = (Scaleform::GFx::AS3::Value::V1U)go->Data.Data[i];
    if ( !ctr
      || v8 == (*(__int64 (__fastcall **)(const char *))(*(_QWORD *)v11.VStr[1].pData + 56i64))(v11.VStr[1].pData) )
    {
      scope.Flags = 12;
      scope.Bonus.pWeakProxy = 0i64;
      scope.value.VS._1 = v11;
      if ( v11.VStr )
        v11.VStr->Size = (v11.VStr->Size + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::FindPropertyWith(result, vm, &scope, mn, FindGet);
      if ( v11.VBool )
      {
        scope.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)v11.VStr - 1);
      }
      else if ( v11.VStr )
      {
        v12 = v11.VStr->Size;
        if ( (v12 & 0x3FFFFF) != 0 )
        {
          v11.VStr->Size = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11.VObj);
        }
      }
      if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
        break;
    }
  }
}

// File Line: 763
// RVA: 0x7D2250
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::FindFixedSlot(
        Scaleform::GFx::AS3::Traits *t,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        unsigned __int64 *index,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Slots *v5; // rsi
  Scaleform::GFx::AS3::SlotInfo *v9; // r14
  const unsigned int *SlotValues; // rax
  __int64 Prev; // rbx
  unsigned __int64 FirstOwnSlotNum; // rdi
  Scaleform::GFx::AS3::SlotInfo *v13; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx

  v5 = &t->Scaleform::GFx::AS3::Slots;
  v9 = 0i64;
  SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(&t->Scaleform::GFx::AS3::Slots, name);
  if ( SlotValues )
  {
    Prev = *SlotValues;
    while ( 1 )
    {
      *index = Prev;
      FirstOwnSlotNum = v5->FirstOwnSlotNum;
      v13 = Prev >= v5->FirstOwnSlotNum
          ? &v5->VArray.Data.Data[(unsigned int)Prev - FirstOwnSlotNum].Value
          : Scaleform::GFx::AS3::Slots::GetSlotInfo(v5->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
      pObject = v13->pNs.pObject;
      if ( (int)(*((_DWORD *)pObject + 10) << 28) >> 28 == (int)(*((_DWORD *)ns + 10) << 28) >> 28 )
      {
        if ( (int)(*((_DWORD *)ns + 10) << 28) >> 28 == 1 )
          break;
        if ( (int)(*((_DWORD *)ns + 10) << 28) >> 28 == 3 ? ns == pObject : pObject->Uri.pNode == ns->Uri.pNode )
          break;
      }
      if ( Prev >= FirstOwnSlotNum )
        Prev = v5->VArray.Data.Data[Prev - FirstOwnSlotNum].Prev;
      else
        Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v5->Parent, Prev);
      if ( Prev < 0 )
        goto LABEL_18;
    }
    v9 = v13;
  }
LABEL_18:
  if ( obj )
    return (Scaleform::GFx::AS3::SlotInfo *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, Scaleform::GFx::AS3::SlotInfo *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::Namespace *, unsigned __int64 *))obj->vfptr[6].~RefCountBaseGC<328>)(
                                              obj,
                                              v9,
                                              name,
                                              ns,
                                              index);
  else
    return v9;
}

// File Line: 825
// RVA: 0x7D1890
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::FindClassTraits(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // r13
  Scaleform::GFx::AS3::RefCountCollector<328> *pRCC; // r12
  unsigned __int64 v8; // rbp
  Scaleform::GFx::AS3::Value *p_Name; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rax
  __int64 v11; // rbx
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // rsi
  signed __int64 v16; // rax
  __int64 v17; // rsi
  int v18; // eax
  bool v19; // zf
  Scaleform::GFx::AS3::ClassTraits::Traits *v20; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::VMAppDomain *v22; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS3::Value *v27; // [rsp+20h] [rbp-78h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v31; // [rsp+50h] [rbp-48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::ClassTraits::Traits *v33; // [rsp+B8h] [rbp+20h] BYREF

  if ( (mn->Kind & 3u) <= 1 )
    return Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vm, mn, appDomain);
  pObject = mn->Obj.pObject;
  pRCC = pObject[1]._pRCC;
  v8 = 0i64;
  if ( !pRCC )
    return 0i64;
  p_Name = &mn->Name;
  v27 = &mn->Name;
  do
  {
    Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(p_Name, &result);
    vfptr = pObject[1].vfptr;
    v11 = *((_QWORD *)&vfptr->ForEachChild_GC + v8);
    ParentDomain = appDomain->ParentDomain;
    if ( !ParentDomain
      || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(
                         ParentDomain,
                         &result,
                         *((Scaleform::GFx::AS3::Instances::fl::Namespace **)&vfptr->ForEachChild_GC + v8))) == 0i64 )
    {
      pNode = result.pNode;
      key.Name = result;
      ++result.pNode->RefCount;
      key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v11;
      if ( v11 )
        *(_DWORD *)(v11 + 32) = (*(_DWORD *)(v11 + 32) + 1) & 0x8FBFFFFF;
      pTable = appDomain->ClassTraitsSet.Entries.mHash.pTable;
      if ( pTable
        && (v16 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)&appDomain->ClassTraitsSet,
                    &key,
                    pTable->SizeMask & (pNode->HashFlags & 0xFFFFFF ^ (4
                                                                     * (*(_DWORD *)(*(_QWORD *)(v11 + 56) + 28i64) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(*(_DWORD *)(v11 + 40) << 28) >> 28))),
            v16 >= 0)
        && (v17 = (__int64)&pTable[2] + 40 * v16) != 0 )
      {
        ClassTrait = (Scaleform::GFx::AS3::ClassTraits::Traits **)(v17 + 16);
      }
      else
      {
        ClassTrait = 0i64;
      }
      if ( v11 )
      {
        if ( (v11 & 1) != 0 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(v11 - 1);
        }
        else
        {
          v18 = *(_DWORD *)(v11 + 32);
          if ( (v18 & 0x3FFFFF) != 0 )
          {
            *(_DWORD *)(v11 + 32) = v18 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11);
          }
        }
      }
      v19 = pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !ClassTrait )
        goto LABEL_23;
    }
    v20 = *ClassTrait;
    if ( !*ClassTrait )
    {
LABEL_23:
      ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                      vm->GlobalObject.pObject,
                      &result,
                      (Scaleform::GFx::AS3::Instances::fl::Namespace *)v11);
      v20 = ClassTraits;
      if ( ClassTraits )
      {
        v22 = vm->SystemDomain.pObject;
        v33 = ClassTraits;
        v28 = result.pNode;
        ++result.pNode->RefCount;
        v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v11;
        if ( v11 )
          *(_DWORD *)(v11 + 32) = (*(_DWORD *)(v11 + 32) + 1) & 0x8FBFFFFF;
        v31.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v28;
        v31.pSecond = &v33;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
          &v22->ClassTraitsSet.Entries.mHash,
          v22->ClassTraitsSet.Entries.mHash.pHeap,
          &v31,
          v28->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v29[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v29[1].vfptr) << 28) >> 28));
        v23 = v29;
        if ( v29 )
        {
          if ( ((unsigned __int8)v29 & 1) != 0 )
          {
            v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v29 - 1);
          }
          else
          {
            RefCount = v29->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v29->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
            }
          }
        }
        v25 = v28;
        v19 = v28->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
    }
    v26 = result.pNode;
    v19 = result.pNode->RefCount-- == 1;
    if ( v19 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    if ( v20 )
      break;
    ++v8;
    p_Name = v27;
  }
  while ( v8 < (unsigned __int64)pRCC );
  return v20;
}

// File Line: 915
// RVA: 0x7D2040
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::FindFixedSlot(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Traits *t,
        Scaleform::GFx::AS3::Multiname *mn,
        unsigned __int64 *index,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // r14
  __int64 v9; // r12
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rdi
  const unsigned int *SlotValues; // rax
  unsigned __int64 pRCCRaw; // rbx
  unsigned __int64 i; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // rbp
  __int64 Prev; // rbx
  unsigned __int64 FirstOwnSlotNum; // rdi
  Scaleform::GFx::AS3::SlotInfo *v17; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // rdx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v22; // [rsp+30h] [rbp-58h]
  const unsigned int *v23; // [rsp+38h] [rbp-50h]
  unsigned __int64 v24; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::ASString name; // [rsp+A0h] [rbp+18h] BYREF

  name.pNode = vm->StringManagerRef->Builtins[0].pNode;
  ++name.pNode->RefCount;
  FixedSlot = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&v24, &name)->Result )
  {
    v9 = 0i64;
    if ( (mn->Kind & 3u) > 1 )
    {
      pObject = mn->Obj.pObject;
      v22 = pObject;
      SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(&t->Scaleform::GFx::AS3::Slots, &name);
      v23 = SlotValues;
      pRCCRaw = pObject[1].pRCCRaw;
      v24 = pRCCRaw;
      for ( i = 0i64; i < pRCCRaw; SlotValues = v23 )
      {
        v14 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_QWORD *)&pObject[1].vfptr->ForEachChild_GC + i);
        if ( SlotValues )
        {
          Prev = *SlotValues;
          while ( 1 )
          {
            *index = Prev;
            FirstOwnSlotNum = t->FirstOwnSlotNum;
            v17 = Prev >= FirstOwnSlotNum
                ? &t->VArray.Data.Data[(unsigned int)Prev - FirstOwnSlotNum].Value
                : Scaleform::GFx::AS3::Slots::GetSlotInfo(t->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
            v18 = v17->pNs.pObject;
            if ( (int)(*((_DWORD *)v18 + 10) << 28) >> 28 == (int)(*((_DWORD *)v14 + 10) << 28) >> 28 )
            {
              if ( (int)(*((_DWORD *)v14 + 10) << 28) >> 28 == 1 )
                break;
              v19 = (int)(*((_DWORD *)v14 + 10) << 28) >> 28 == 3 ? v14 == v18 : v18->Uri.pNode == v14->Uri.pNode;
              if ( v19 )
                break;
            }
            if ( Prev >= FirstOwnSlotNum )
              Prev = t->VArray.Data.Data[Prev - FirstOwnSlotNum].Prev;
            else
              Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(t->Parent, Prev);
            if ( Prev < 0 )
              goto LABEL_22;
          }
          v9 = (__int64)v17;
LABEL_22:
          pObject = v22;
          pRCCRaw = v24;
        }
        if ( obj )
          v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Instances::fl::Namespace *, unsigned __int64 *))obj->vfptr[6].~RefCountBaseGC<328>)(
                 obj,
                 v9,
                 &name,
                 v14,
                 index);
        if ( v9 )
          break;
        ++i;
      }
      FixedSlot = (Scaleform::GFx::AS3::SlotInfo *)v9;
    }
    else
    {
      FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(
                    t,
                    &name,
                    (Scaleform::GFx::AS3::Instances::fl::Namespace *)mn->Obj.pObject,
                    index,
                    obj);
    }
  }
  pNode = name.pNode;
  v19 = name.pNode->RefCount-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return FixedSlot;
}

// File Line: 1002
// RVA: 0x7D23A0
Scaleform::GFx::AS3::ClassTraits::Traits *__fastcall Scaleform::GFx::AS3::FindFixedTraits(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Traits *t,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // r12
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v8; // r14
  const unsigned int *v9; // rax
  __int64 PrevSlotIndex; // rbx
  unsigned __int64 v11; // rsi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v13; // rdx
  bool v14; // zf
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rdi
  Scaleform::GFx::AS3::Slots *v16; // r14
  const unsigned int *SlotValues; // rax
  unsigned __int64 v18; // r13
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // rdi
  __int64 Prev; // rbx
  __int64 v21; // r15
  unsigned __int64 FirstOwnSlotNum; // rsi
  Scaleform::GFx::AS3::SlotInfo *v23; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // rdx
  Scaleform::GFx::AS3::VM *v26; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *v27; // rdx
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor> *v31; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *v34; // r11
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v35; // rcx
  unsigned int v36; // eax
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-60h] BYREF
  unsigned __int64 pRCCRaw; // [rsp+28h] [rbp-58h]
  const unsigned int *v42; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::AS3::GASRefCountBase *v43; // [rsp+38h] [rbp-48h]
  __int64 v44; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v45; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::MultinameHash<bool,2>::Key key; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef v48; // [rsp+68h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::ClassTraits::Traits *v50; // [rsp+D0h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::VMAppDomain *v51; // [rsp+D8h] [rbp+58h]

  v51 = appDomain;
  v44 = -2i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &result);
  v6 = 0i64;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, (Scaleform::GFx::AS3::CheckResult *)&v50, &result)->Result )
    goto LABEL_69;
  DataType = 0i64;
  if ( (mn->Kind & 3u) > 1 )
  {
    pObject = mn->Obj.pObject;
    v43 = pObject;
    v16 = &t->Scaleform::GFx::AS3::Slots;
    SlotValues = Scaleform::GFx::AS3::Slots::FindSlotValues(&t->Scaleform::GFx::AS3::Slots, &result);
    v42 = SlotValues;
    pRCCRaw = pObject[1].pRCCRaw;
    v18 = 0i64;
    if ( !pRCCRaw )
    {
LABEL_68:
      v6 = DataType;
      goto LABEL_69;
    }
    while ( 1 )
    {
      v19 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_QWORD *)&pObject[1].vfptr->ForEachChild_GC + v18);
      if ( SlotValues )
      {
        Prev = *SlotValues;
        v21 = (__int64)(*((_QWORD *)v19 + 5) << 60) >> 60;
        while ( 1 )
        {
          FirstOwnSlotNum = v16->FirstOwnSlotNum;
          v23 = Prev >= v16->FirstOwnSlotNum
              ? &v16->VArray.Data.Data[(unsigned int)Prev - FirstOwnSlotNum].Value
              : Scaleform::GFx::AS3::Slots::GetSlotInfo(v16->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)Prev);
          v24 = v23->pNs.pObject;
          if ( (int)(*((_DWORD *)v24 + 10) << 28) >> 28 == (_DWORD)v21 )
          {
            if ( (_DWORD)v21 == 1 )
              break;
            if ( (_DWORD)v21 == 3 ? v19 == v24 : v24->Uri.pNode == v19->Uri.pNode )
              break;
          }
          if ( Prev >= FirstOwnSlotNum )
            Prev = v16->VArray.Data.Data[Prev - FirstOwnSlotNum].Prev;
          else
            Prev = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(v16->Parent, Prev);
          if ( Prev < 0 )
            goto LABEL_39;
        }
        v26 = vm;
        DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(v23, vm);
        if ( DataType )
          goto LABEL_68;
      }
      else
      {
LABEL_39:
        v26 = vm;
      }
      v27 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)v51;
      ParentDomain = v51->ParentDomain;
      if ( ParentDomain )
      {
        ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &result, v19);
        if ( ClassTrait )
          goto LABEL_55;
        v27 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> > *)v51;
      }
      pNode = result.pNode;
      key.Name = result;
      ++result.pNode->RefCount;
      key.pNs.pObject = v19;
      if ( v19 )
        v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
      v31 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::GetAlt<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
              v27 + 6,
              &key);
      ClassTrait = (Scaleform::GFx::AS3::ClassTraits::Traits **)&v31->Second;
      if ( !v31 )
        ClassTrait = 0i64;
      if ( v19 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          key.pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v19 - 1);
        }
        else
        {
          RefCount = v19->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v19->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
          }
        }
      }
      v14 = pNode->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( ClassTrait )
      {
LABEL_55:
        DataType = *ClassTrait;
        if ( *ClassTrait )
          goto LABEL_68;
      }
      ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                      v26->GlobalObject.pObject,
                      &result,
                      v19);
      DataType = ClassTraits;
      if ( ClassTraits )
      {
        v34 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF> > *)v26->SystemDomain.pObject;
        v50 = ClassTraits;
        v45 = result.pNode;
        ++result.pNode->RefCount;
        v46 = v19;
        if ( v19 )
          v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
        v48.pFirst = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key *)&v45;
        v48.pSecond = &v50;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,329>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key,Scaleform::GFx::AS3::ClassTraits::Traits *,Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Key::HashFunctor>::NodeRef>(
          v34 + 6,
          v34[7].pTable,
          &v48,
          v45->HashFlags & 0xFFFFFF ^ (4 * (HIDWORD(v46[1].pNext->pPrevRoot) & 0xFFFFFFu)) ^ (unsigned __int64)(unsigned int)((int)(LODWORD(v46[1].vfptr) << 28) >> 28));
        v35 = v46;
        if ( v46 )
        {
          if ( ((unsigned __int8)v46 & 1) != 0 )
          {
            v46 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v46 - 1);
          }
          else
          {
            v36 = v46->RefCount;
            if ( (v36 & 0x3FFFFF) != 0 )
            {
              v46->RefCount = v36 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
            }
          }
        }
        v37 = v45;
        v14 = v45->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      }
      if ( !DataType )
      {
        ++v18;
        SlotValues = v42;
        pObject = v43;
        if ( v18 < pRCCRaw )
          continue;
      }
      goto LABEL_68;
    }
  }
  v8 = mn->Obj.pObject;
  v9 = Scaleform::GFx::AS3::Slots::FindSlotValues(&t->Scaleform::GFx::AS3::Slots, &result);
  if ( v9 )
  {
    PrevSlotIndex = *v9;
    while ( PrevSlotIndex >= 0 )
    {
      v11 = t->FirstOwnSlotNum;
      if ( PrevSlotIndex >= v11 )
        p_Value = &t->VArray.Data.Data[(unsigned int)PrevSlotIndex - v11].Value;
      else
        p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(t->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)PrevSlotIndex);
      v13 = p_Value->pNs.pObject;
      if ( (int)(*((_DWORD *)v13 + 10) << 28) >> 28 == (int)(LODWORD(v8[1].vfptr) << 28) >> 28 )
      {
        if ( (int)(LODWORD(v8[1].vfptr) << 28) >> 28 == 1
          || ((int)(LODWORD(v8[1].vfptr) << 28) >> 28 == 3
            ? (v14 = v8 == v13)
            : (v14 = v13->Uri.pNode == (Scaleform::GFx::ASStringNode *)v8[1].pNext),
              v14) )
        {
          if ( p_Value )
            v6 = Scaleform::GFx::AS3::SlotInfo::GetDataType(p_Value, t->pVM);
          break;
        }
      }
      if ( PrevSlotIndex >= v11 )
        PrevSlotIndex = t->VArray.Data.Data[PrevSlotIndex - v11].Prev;
      else
        PrevSlotIndex = Scaleform::GFx::AS3::Slots::GetPrevSlotIndex(t->Parent, PrevSlotIndex);
    }
  }
LABEL_69:
  v38 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  return v6;
}

// File Line: 1090
// RVA: 0x7D2F20
void __fastcall Scaleform::GFx::AS3::FindObjProperty(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *scope,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::FindPropAttr attr)
{
  bool v9; // r15
  Scaleform::GFx::AS3::Traits *ValueTraits; // rbx
  Scaleform::GFx::AS3::Object *obj; // rax
  Scaleform::GFx::AS3::VM *FixedSlot; // rax
  unsigned __int64 v13; // r10
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r8
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned int v17; // ebx
  Scaleform::GFx::AS3::FindPropAttr v19; // ebp
  Scaleform::GFx::AS3::PropRef *v20; // rax
  Scaleform::GFx::AS3::Object *Prototype; // rax
  Scaleform::GFx::AS3::ReadValue v22; // [rsp+38h] [rbp-60h] BYREF
  unsigned __int64 index; // [rsp+B0h] [rbp+18h] BYREF

  v9 = (scope->Flags & 0x1F) - 12 <= 2;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  index = 0i64;
  if ( v9 )
    obj = scope->value.VS._1.VObj;
  else
    obj = 0i64;
  FixedSlot = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::AS3::FindFixedSlot(vm, ValueTraits, mn, &index, obj);
  if ( FixedSlot )
  {
    v22.VMRef = FixedSlot;
    v13 = index;
    v22.OpStack = (Scaleform::GFx::AS3::ValueStack *)index;
    Flags = scope->Flags;
    v22.ArgValue.Flags = Flags;
    pWeakProxy = scope->Bonus.pWeakProxy;
    v22.ArgValue.Bonus.pWeakProxy = pWeakProxy;
    VObj = scope->value.VS._1;
    v22.ArgValue.value = scope->value;
    if ( (Flags & 0x1F) <= 9 )
      goto LABEL_16;
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_16;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++VObj.VStr->RefCount;
    }
    else if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
        goto LABEL_13;
      if ( (Flags & 0x1F) <= 0x11 )
      {
        VObj = (Scaleform::GFx::AS3::Value::V1U)scope->value.VS._2.VObj;
LABEL_13:
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_16:
    result->pSI = (Scaleform::GFx::AS3::SlotInfo *)FixedSlot;
    result->SlotIndex = v13;
    Scaleform::GFx::AS3::Value::Assign(&result->This, &v22.ArgValue);
    v17 = v22.ArgValue.Flags;
    if ( (v22.ArgValue.Flags & 0x1F) > 9 )
    {
      if ( (v22.ArgValue.Flags & 0x200) != 0 )
      {
        if ( v22.ArgValue.Bonus.pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v22.ArgValue.Bonus, 0, 24);
        v22.ArgValue.Flags = v17 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v22.ArgValue);
      }
    }
    return;
  }
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(mn, vm->PublicNamespace.pObject) )
  {
    v19 = attr;
    if ( v9 && (ValueTraits->Flags & 2) != 0 && (attr != FindCall || !Scaleform::GFx::AS3::IsXMLObject(scope)) )
    {
      v20 = (Scaleform::GFx::AS3::PropRef *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::ReadValue *, Scaleform::GFx::AS3::Multiname *))scope->value.VS._1.VStr->pData
                                             + 18))(
                                              scope->value.VS._1,
                                              &v22,
                                              mn);
      Scaleform::GFx::AS3::PropRef::operator=(result, v20);
      Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>(&v22);
    }
    if ( ((result->This.Flags & 0x1F) == 0
       || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
       || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0)
      && v19 != FindSet )
    {
      for ( ; ValueTraits; ValueTraits = ValueTraits->pParent.pObject )
      {
        if ( !ValueTraits->pConstructor.pObject )
          ValueTraits->vfptr[3].~RefCountBaseGC<328>(ValueTraits);
        Prototype = Scaleform::GFx::AS3::Class::GetPrototype(ValueTraits->pConstructor.pObject);
        Scaleform::GFx::AS3::Object::FindProperty(Prototype, result, mn, v19);
        if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
          break;
      }
      if ( !Scaleform::GFx::AS3::PropRef::operator bool(result) && (scope->Flags & 0x1F) == 14 )
        Scaleform::GFx::AS3::FindScopeProperty(
          result,
          vm,
          0i64,
          (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&scope->value.VS._1.VStr[1].RefCount,
          mn);
    }
  }
}

// File Line: 1187
// RVA: 0x7D3AA0
void __fastcall Scaleform::GFx::AS3::FindPropertyWith(
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *scope,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rbx
  Scaleform::GFx::AS3::Object *obj; // rax
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  unsigned __int64 v9; // r10
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r8
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned int v13; // ebx
  bool v14; // zf
  Scaleform::GFx::AS3::FindPropAttr v15; // edx
  Scaleform::GFx::AS3::PropRef *v16; // rax
  Scaleform::GFx::AS3::Object *Prototype; // rax
  Scaleform::GFx::AS3::PropRef *v18; // rax
  unsigned int *p_RefCount; // rax
  __int64 v20; // rbx
  __int64 v21; // rdi
  unsigned __int64 index[2]; // [rsp+18h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+28h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::PropRef v24; // [rsp+58h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::VM *vma; // [rsp+B0h] [rbp+67h]
  unsigned int *retaddr; // [rsp+B8h] [rbp+6Fh]
  Scaleform::GFx::AS3::Multiname *mna; // [rsp+C0h] [rbp+77h]
  Scaleform::GFx::AS3::FindPropAttr v28; // [rsp+C8h] [rbp+7Fh]

  v28 = (int)vm;
  index[1] = -2i64;
  LODWORD(retaddr) = (scope->Flags & 0x1F) - 12 <= 2;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, scope);
  index[0] = 0i64;
  if ( (_BYTE)retaddr )
    obj = scope->value.VS._1.VObj;
  else
    obj = 0i64;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(vma, ValueTraits, mna, index, obj);
  if ( FixedSlot )
  {
    resulta.pSI = FixedSlot;
    v9 = index[0];
    resulta.SlotIndex = index[0];
    Flags = scope->Flags;
    resulta.This.Flags = Flags;
    pWeakProxy = scope->Bonus.pWeakProxy;
    resulta.This.Bonus.pWeakProxy = pWeakProxy;
    VObj = scope->value.VS._1;
    resulta.This.value = scope->value;
    if ( (Flags & 0x1F) <= 9 )
      goto LABEL_16;
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_16;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++VObj.VStr->RefCount;
    }
    else if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
        goto LABEL_13;
      if ( (Flags & 0x1F) <= 0x11 )
      {
        VObj = (Scaleform::GFx::AS3::Value::V1U)scope->value.VS._2.VObj;
LABEL_13:
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_16:
    result->pSI = FixedSlot;
    result->SlotIndex = v9;
    Scaleform::GFx::AS3::Value::Assign(&result->This, &resulta.This);
    v13 = resulta.This.Flags;
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags & 0x200) != 0 )
      {
        v14 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&resulta.This.Bonus, 0, 24);
        resulta.This.Flags = v13 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    return;
  }
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->vfptr[1].ForEachChild_GC)(ValueTraits)
    && (scope->Flags & 0x100) == 0 )
  {
    return;
  }
  v15 = v28;
  if ( (_BYTE)retaddr && (ValueTraits->Flags & 2) != 0 )
  {
    if ( v28 != FindCall || !Scaleform::GFx::AS3::IsXMLObject(scope) )
    {
      v16 = (Scaleform::GFx::AS3::PropRef *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::PropRef *, Scaleform::GFx::AS3::Multiname *))scope->value.VS._1.VStr->pData
                                             + 18))(
                                              scope->value.VS._1,
                                              &resulta,
                                              mna);
      Scaleform::GFx::AS3::PropRef::operator=(result, v16);
      if ( (resulta.This.Flags & 0x1F) > 9 )
      {
        if ( (resulta.This.Flags & 0x200) != 0 )
        {
          v14 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&resulta.This.Bonus, 0, 24);
          resulta.This.Flags &= 0xFFFFFDE0;
          v15 = v28;
          goto LABEL_35;
        }
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    v15 = v28;
  }
LABEL_35:
  if ( ((result->This.Flags & 0x1F) == 0
     || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
     || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0)
    && v15 != FindSet )
  {
    memset(&resulta, 0, 20);
    resulta.This.Bonus.pWeakProxy = 0i64;
    while ( 1 )
    {
      if ( !ValueTraits->pConstructor.pObject )
        ValueTraits->vfptr[3].~RefCountBaseGC<328>(ValueTraits);
      Prototype = Scaleform::GFx::AS3::Class::GetPrototype(ValueTraits->pConstructor.pObject);
      Scaleform::GFx::AS3::Object::FindProperty(Prototype, &resulta, mna, v28);
      if ( (resulta.This.Flags & 0x1F) != 0
        && (((__int64)resulta.pSI & 1) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
        && (((__int64)resulta.pSI & 2) == 0 || ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
      {
        break;
      }
      ValueTraits = ValueTraits->pParent.pObject;
      if ( !ValueTraits )
        goto LABEL_52;
    }
    Scaleform::GFx::AS3::PropRef::PropRef(&v24, scope, 0i64, 0i64);
    Scaleform::GFx::AS3::PropRef::operator=(result, v18);
    Scaleform::GFx::AS3::DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>::~DefArgs3<Scaleform::GFx::AS3::Instances::fl_geom::Point *,unsigned long,Scaleform::GFx::AS3::Value const &>((Scaleform::GFx::AS3::ReadValue *)&v24);
LABEL_52:
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags & 0x200) != 0 )
      {
        v14 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&resulta.This.Bonus, 0, 24);
        resulta.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      }
    }
    if ( ((result->This.Flags & 0x1F) == 0
       || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
       || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0)
      && (scope->Flags & 0x1F) == 14 )
    {
      p_RefCount = &scope->value.VS._1.VStr[1].RefCount;
      retaddr = p_RefCount;
      v20 = *(_QWORD *)&scope->value.VS._1.VStr[1].Size;
      if ( v20 )
      {
        v21 = 32 * v20;
        do
        {
          Scaleform::GFx::AS3::FindPropertyWith(
            result,
            vma,
            (Scaleform::GFx::AS3::Value *)(v21 + *(_QWORD *)p_RefCount - 32i64),
            mna,
            FindGet);
          if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
            break;
          v21 -= 32i64;
          --v20;
          p_RefCount = retaddr;
        }
        while ( v20 );
      }
    }
  }
}

// File Line: 1287
// RVA: 0x7D0550
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ExecutePropertyUnsafe(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::Value::V1U v7; // rcx
  int v8; // ecx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::VM::Error result_on_stack; // [rsp+30h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::PropRef v18; // [rsp+60h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::CheckResult v19; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::Value *v20; // [rsp+D8h] [rbp+6Fh]
  unsigned int v21; // [rsp+E0h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v22; // [rsp+E8h] [rbp+7Fh]

  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    v7 = _this->value.VS._1;
    if ( v7.VStr )
    {
      (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v7.VStr->pData
       + 10))(
        v7,
        result,
        prop_name,
        v20,
        v21,
        v22);
      return result;
    }
  }
  memset(&v18, 0, 20);
  v18.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::FindObjProperty(&v18, vm, _this, prop_name, FindCall);
  if ( (v18.This.Flags & 0x1F) != 0
    && (((__int64)v18.pSI & 1) == 0 || ((unsigned __int64)v18.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)v18.pSI & 2) == 0 || ((unsigned __int64)v18.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&v18, &v19, vm, &value, valExecute)->Result )
    {
      result->Result = 0;
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v11 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      goto LABEL_38;
    }
    v8 = value.Flags & 0x1F;
    if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v8 - 12) > 3 && v8 != 10 || value.value.VS._1.VStr) )
    {
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, &value, _this, v20, v21, v22, 0);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&result_on_stack, 1006, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = result_on_stack.Message.pNode;
      v11 = result_on_stack.Message.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v11 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
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
    if ( (Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this)->Flags & 2) != 0
      || (_this->Flags & 0x1F) <= 4
      || (_this->Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&result_on_stack, 1006, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v13, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&result_on_stack, 1069, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v12, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
    v14 = result_on_stack.Message.pNode;
    v11 = result_on_stack.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  result->Result = !vm->HandleException;
LABEL_38:
  if ( (v18.This.Flags & 0x1F) > 9 )
  {
    if ( (v18.This.Flags & 0x200) != 0 )
    {
      v11 = v18.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v18.This.Bonus, 0, 24);
      v18.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v18.This);
    }
  }
  return result;
}

// File Line: 1365
// RVA: 0x78D020
void __fastcall Scaleform::GFx::AS3::Object::~Object(Scaleform::GFx::AS3::Object *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>(&this->DynAttrs.mHash);
  pObject = this->pTraits.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pTraits.pObject = (Scaleform::GFx::AS3::Traits *)((char *)pObject - 1);
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
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
}

// File Line: 1377
// RVA: 0x7D6030
void __fastcall Scaleform::GFx::AS3::Object::ForEachChild_GC(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // rcx
  signed __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rdx
  int v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v16; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v17; // rcx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  __int128 v21; // [rsp+20h] [rbp-18h]

  p_DynAttrs = &this->DynAttrs;
  pTable = this->DynAttrs.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = 0i64;
    v10 = pTable + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 += 4;
    }
    while ( v9 <= SizeMask );
    *(_QWORD *)&v21 = p_DynAttrs;
    *((_QWORD *)&v21 + 1) = v9;
  }
  else
  {
    v21 = 0ui64;
  }
  v11 = *((_QWORD *)&v21 + 1);
  while ( (_QWORD)v21 )
  {
    v12 = *(_QWORD *)v21;
    if ( !*(_QWORD *)v21 || v11 > *(_QWORD *)(v12 + 8) )
      break;
    v13 = v12 + (v11 << 6);
    v14 = *(_DWORD *)(v13 + 48);
    v15 = v14 & 0x1F;
    if ( v15 <= 0xA || (v14 & 0x200) != 0 || (*(_DWORD *)(v13 + 48) & 0x1Fu) < 0xB )
      goto LABEL_22;
    if ( (*(_DWORD *)(v13 + 48) & 0x1Fu) <= 0xF )
    {
      v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v13 + 64);
      if ( !*(_QWORD *)(v13 + 64) )
        goto LABEL_22;
      v16 = 0i64;
      if ( v15 - 11 <= 4 )
        v16 = v17;
    }
    else
    {
      if ( (*(_DWORD *)(v13 + 48) & 0x1Fu) > 0x11 )
        goto LABEL_22;
      v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v13 + 72);
      if ( !*v16 )
        goto LABEL_22;
    }
    op(prcc, v16);
LABEL_22:
    v18 = *(_QWORD *)(*(_QWORD *)v21 + 8i64);
    if ( v11 <= (__int64)v18 && ++v11 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)v21 + (v11 << 6) + 16);
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
  pObject = this->pTraits.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::Traits::ForEachChild_GC_Slot(pObject, prcc, this, op);
  if ( this->pTraits.pObject )
    op(prcc, &this->pTraits.pObject);
}

// File Line: 1403
// RVA: 0x81D710
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::SetSlotValue(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::SlotIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits::SetSlotValue(
    this->pTraits.pObject,
    result,
    (Scaleform::GFx::AS3::AbsoluteIndex)(LODWORD(this->pTraits.pObject->FirstOwnSlotInd.Index) + ind.Index - 1i64),
    value,
    this);
  return result;
}

// File Line: 1408
// RVA: 0x7F28E0
_BOOL8 __fastcall Scaleform::GFx::AS3::Object::HasProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        bool check_prototype)
{
  bool v3; // bl
  Scaleform::GFx::AS3::PropRef v6; // [rsp+28h] [rbp-40h] BYREF

  memset(&v6, 0, 20);
  v6.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(this, &v6, prop_name, (Scaleform::GFx::AS3::FindPropAttr)!check_prototype);
  v3 = (v6.This.Flags & 0x1F) != 0
    && (((__int64)v6.pSI & 1) == 0 || ((unsigned __int64)v6.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)v6.pSI & 2) == 0 || ((unsigned __int64)v6.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0);
  if ( (v6.This.Flags & 0x1F) > 9 )
  {
    if ( (v6.This.Flags & 0x200) != 0 )
    {
      if ( v6.This.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v6.This.Bonus, 0, 24);
      v6.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6.This);
    }
  }
  return v3;
}

// File Line: 1419
// RVA: 0x7E7A90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::GetDefaultValueUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *a3,
        int hint)
{
  Scaleform::GFx::AS3::Traits *pObject; // r10
  Scaleform::GFx::AS3::VM *pVM; // rax
  __int64 StringManagerRef; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v9; // r15
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // edx
  char v11; // di
  char v12; // si
  Scaleform::GFx::AS3::Value::V1U v13; // rbx
  Scaleform::GFx::AS3::Value::Extra v14; // rcx
  int v15; // r13d
  const char *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // bl
  unsigned int v22; // r9d
  Scaleform::GFx::AS3::Value::Extra v23; // rax
  Scaleform::GFx::AS3::Value::VU v24; // kr00_16
  int v25; // r9d
  Scaleform::GFx::AS3::Value::V1U v26; // rbx
  Scaleform::GFx::AS3::Value::Extra v27; // rcx
  int v28; // esi
  const char *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASStringNode *v32; // rcx
  bool v33; // bl
  unsigned int v34; // edx
  Scaleform::GFx::AS3::Value::Extra v35; // rax
  Scaleform::GFx::AS3::Value::VU v36; // kr10_16
  Scaleform::GFx::AS3::Value::V1U v37; // rbx
  Scaleform::GFx::AS3::Value::Extra v38; // rcx
  int v39; // r13d
  const char *pData; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v43; // rcx
  bool v44; // bl
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::Value::Extra v46; // rax
  Scaleform::GFx::AS3::Value::VU value; // kr20_16
  int v48; // r9d
  Scaleform::GFx::AS3::Value::V1U v49; // rbx
  const char *v50; // rax
  bool v51; // bl
  unsigned int Kind; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v53; // rax
  Scaleform::GFx::AS3::Value::V1U v54; // r8
  Scaleform::GFx::AS3::Value::Extra v55; // r9
  Scaleform::GFx::AS3::Value p; // [rsp+30h] [rbp-A9h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+50h] [rbp-89h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Multiname v60; // [rsp+78h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Multiname v61; // [rsp+A8h] [rbp-31h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+D8h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Value::Extra v63; // [rsp+E0h] [rbp+7h]
  Scaleform::GFx::AS3::Value::V1U *v64; // [rsp+E8h] [rbp+Fh]
  __int64 v65; // [rsp+F0h] [rbp+17h]
  char v67; // [rsp+158h] [rbp+7Fh] BYREF

  v65 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  StringManagerRef = (__int64)pVM->StringManagerRef;
  v64 = (Scaleform::GFx::AS3::Value::V1U *)StringManagerRef;
  v9 = pVM->PublicNamespace.pObject;
  TraitsType = pObject->TraitsType;
  if ( (unsigned int)(TraitsType - 18) > 1 )
  {
    if ( !hint )
      hint = (TraitsType == Traits_Date) + 1;
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
    v60.Kind = MN_MultinameA;
    v60.Obj.pObject = 0i64;
    v37 = *(Scaleform::GFx::AS3::Value::V1U *)(StringManagerRef + 200);
    *(Scaleform::GFx::AS3::Value::V1U *)&v60.Name.Flags = v37;
    if ( v37.VStr == &v37.VStr->pManager->NullStringNode )
    {
      v37.VStr = 0i64;
      *(_QWORD *)&v60.Name.Flags = 0i64;
      v38.pWeakProxy = v63.pWeakProxy;
      v60.Name.Bonus = v63;
      v12 = 12;
      v60.Kind = 12;
    }
    else
    {
      ++v37.VStr->RefCount;
      v38.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v60.Name.Bonus;
    }
    v61.Kind = MN_QName;
    v61.Obj.pObject = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v61.Name.Flags = 0;
    v61.Name.Bonus.pWeakProxy = 0i64;
    v39 = v12 & 0x1F;
    if ( (unsigned int)(v39 - 12) <= 3
      && v37.VStr
      && (pData = v37.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v61.Name, (Scaleform::GFx::ASString *)&v37.VStr[1].16);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v61.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v37.VStr[1].RefCount);
      v61.Kind &= 0xFFFFFFF9;
    }
    else
    {
      _mm_prefetch((const char *)&v60, 2);
      *(_QWORD *)&v61.Name.Flags = *(_QWORD *)&v60.Kind;
      v61.Name.Bonus.pWeakProxy = 0i64;
      v61.Name.value.VS._1 = v37;
      v61.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v38.pWeakProxy;
      if ( (v12 & 0x1Fu) > 9 )
      {
        if ( v39 == 10 )
        {
          ++v37.VStr->RefCount;
        }
        else if ( (v12 & 0x1Fu) <= 0xF )
        {
          if ( v37.VStr )
            v37.VStr->Size = (v37.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (v12 & 0x1Fu) <= 0x11 && v38.pWeakProxy )
        {
          v38.pWeakProxy[2].RefCount = (v38.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
        }
      }
      if ( (v61.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v61.Name, &resulta);
        if ( resulta.pNode->Size )
        {
          if ( *resulta.pNode->pData == 64 )
          {
            v61.Kind |= 8u;
            v41 = Scaleform::GFx::ASString::Substring(&resulta, &v62, 1, resulta.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v61.Name, v41);
            pNode = v62.pNode;
            v19 = v62.pNode->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
        }
        v43 = resulta.pNode;
        v19 = resulta.pNode->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      }
    }
    v44 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, _DWORD, _QWORD))this->vfptr[3].~RefCountBaseGC<328>)(
                      this,
                      &v67,
                      &v61,
                      &p,
                      0,
                      0i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v61);
    if ( (v12 & 0x1Fu) > 9 )
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v60);
    if ( v44 )
      goto LABEL_35;
    Flags = p.Flags;
    v46.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p.Bonus;
    value = p.value;
    p.Flags = a3->Flags;
    p.Bonus.pWeakProxy = a3->Bonus.pWeakProxy;
    p.value = a3->value;
    a3->Flags = Flags;
    a3->Bonus = v46;
    a3->value = value;
    v48 = Flags & 0x1F;
    if ( v48 > 4 && v48 != 10 )
    {
      v60.Kind = MN_QName;
      v60.Obj.pObject = 0i64;
      other.Flags = 10;
      other.Bonus.pWeakProxy = 0i64;
      v49 = v64[24];
      other.value.VS._1 = v49;
      if ( v49.VStr == &v49.VStr->pManager->NullStringNode )
      {
        v49.VStr = 0i64;
        other.value.VS._1.VStr = 0i64;
        other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v63.pWeakProxy;
        v11 = 12;
        other.Flags = 12;
      }
      else
      {
        ++v49.VStr->RefCount;
      }
      v61.Kind = MN_QName;
      v61.Obj.pObject = v9;
      if ( v9 )
        v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
      v61.Name.Flags = 0;
      v61.Name.Bonus.pWeakProxy = 0i64;
      if ( (v11 & 0x1Fu) - 12 <= 3
        && v49.VStr
        && (v50 = v49.VStr[1].pData, *((_DWORD *)v50 + 30) == 17)
        && (v50[112] & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v61.Name, (Scaleform::GFx::ASString *)&v49.VStr[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v61.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v49.VStr[1].RefCount);
        v61.Kind &= 0xFFFFFFF9;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v61.Name, &other);
        Scaleform::GFx::AS3::Multiname::PostProcessName(&v61, 0);
      }
      v51 = *(_BYTE *)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))this->vfptr[3].~RefCountBaseGC<328>)(
                        this,
                        &v67,
                        &v61,
                        &v60,
                        0,
                        0i64,
                        p.Flags,
                        (Scaleform::GFx::AS3::Value::Extra)p.Bonus.pWeakProxy,
                        (Scaleform::GFx::AS3::Value::V1U)p.value.VS._1.VStr,
                        (Scaleform::GFx::AS3::Value::V2U)p.value.VS._2.VObj,
                        other.Flags,
                        (Scaleform::GFx::AS3::Value::Extra)other.Bonus.pWeakProxy,
                        (Scaleform::GFx::AS3::Value::V1U)other.value.VS._1.VStr,
                        (Scaleform::GFx::AS3::Value::V2U)other.value.VS._2.VObj) == 0;
      Scaleform::GFx::AS3::Multiname::~Multiname(&v61);
      Scaleform::GFx::AS3::Value::~Value(&other);
      if ( v51 )
      {
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&v60);
LABEL_132:
        Scaleform::GFx::AS3::Value::~Value(&p);
        return result;
      }
      Kind = v60.Kind;
      v53 = v60.Obj.pObject;
      v54 = *(Scaleform::GFx::AS3::Value::V1U *)&v60.Name.Flags;
      v55.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v60.Name.Bonus;
      v60.Kind = a3->Flags;
      v60.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)a3->Bonus.pWeakProxy;
      *(_QWORD *)&v60.Name.Flags = a3->value.VS._1.VStr;
      v60.Name.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)a3->value.VS._2.VObj;
      a3->Flags = Kind;
      a3->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v53;
      a3->value.VS._1 = v54;
      a3->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v55.pWeakProxy;
      Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&v60);
    }
LABEL_131:
    result->Result = 1;
    goto LABEL_132;
  }
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  v13 = *(Scaleform::GFx::AS3::Value::V1U *)(StringManagerRef + 192);
  other.value.VS._1 = v13;
  if ( v13.VStr == &v13.VStr->pManager->NullStringNode )
  {
    v13.VStr = 0i64;
    other.value.VS._1.VStr = 0i64;
    v14.pWeakProxy = v63.pWeakProxy;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v63.pWeakProxy;
    v12 = 12;
    other.Flags = 12;
  }
  else
  {
    ++v13.VStr->RefCount;
    v14.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.value.VS._2.VObj;
  }
  v60.Kind = MN_QName;
  v60.Obj.pObject = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  v60.Name.Flags = 0;
  v60.Name.Bonus.pWeakProxy = 0i64;
  v15 = v12 & 0x1F;
  if ( (unsigned int)(v15 - 12) <= 3
    && v13.VStr
    && (v16 = v13.VStr[1].pData, *((_DWORD *)v16 + 30) == 17)
    && (v16[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v60.Name, (Scaleform::GFx::ASString *)&v13.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v60.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v13.VStr[1].RefCount);
    v60.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&other, 2);
    *(_QWORD *)&v60.Name.Flags = *(_QWORD *)&other.Flags;
    v60.Name.Bonus.pWeakProxy = 0i64;
    v60.Name.value.VS._1 = v13;
    v60.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14.pWeakProxy;
    if ( (v12 & 0x1Fu) > 9 )
    {
      if ( v15 == 10 )
      {
        ++v13.VStr->RefCount;
      }
      else if ( (v12 & 0x1Fu) <= 0xF )
      {
        if ( v13.VStr )
          v13.VStr->Size = (v13.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v12 & 0x1Fu) <= 0x11 && v14.pWeakProxy )
      {
        v14.pWeakProxy[2].RefCount = (v14.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v60.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v60.Name, &resulta);
      if ( resulta.pNode->Size )
      {
        if ( *resulta.pNode->pData == 64 )
        {
          v60.Kind |= 8u;
          v17 = Scaleform::GFx::ASString::Substring(&resulta, &v62, 1, resulta.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v60.Name, v17);
          v18 = v62.pNode;
          v19 = v62.pNode->RefCount-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        }
      }
      v20 = resulta.pNode;
      v19 = resulta.pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
  }
  v21 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, _DWORD, _QWORD))this->vfptr[3].~RefCountBaseGC<328>)(
                    this,
                    &v67,
                    &v60,
                    &p,
                    0,
                    0i64) == 0;
  Scaleform::GFx::AS3::Multiname::~Multiname(&v60);
  if ( (v12 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  if ( v21 )
  {
LABEL_35:
    result->Result = 0;
    goto LABEL_36;
  }
  v22 = p.Flags;
  v23.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p.Bonus;
  v24 = p.value;
  p.Flags = a3->Flags;
  p.Bonus.pWeakProxy = a3->Bonus.pWeakProxy;
  p.value = a3->value;
  a3->Flags = v22;
  a3->Bonus = v23;
  a3->value = v24;
  v25 = v22 & 0x1F;
  if ( v25 > 4 && v25 != 10 )
  {
    other.Flags = 0;
    other.Bonus.pWeakProxy = 0i64;
    v60.Kind = MN_MultinameA;
    v60.Obj.pObject = 0i64;
    v26 = v64[25];
    *(Scaleform::GFx::AS3::Value::V1U *)&v60.Name.Flags = v26;
    if ( v26.VStr == &v26.VStr->pManager->NullStringNode )
    {
      v26.VStr = 0i64;
      *(_QWORD *)&v60.Name.Flags = 0i64;
      v27.pWeakProxy = v63.pWeakProxy;
      v60.Name.Bonus = v63;
      v11 = 12;
      v60.Kind = 12;
    }
    else
    {
      ++v26.VStr->RefCount;
      v27.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v60.Name.Bonus;
    }
    v61.Kind = MN_QName;
    v61.Obj.pObject = v9;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
    v61.Name.Flags = 0;
    v61.Name.Bonus.pWeakProxy = 0i64;
    v28 = v11 & 0x1F;
    if ( (unsigned int)(v28 - 12) <= 3
      && v26.VStr
      && (v29 = v26.VStr[1].pData, *((_DWORD *)v29 + 30) == 17)
      && (v29[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v61.Name, (Scaleform::GFx::ASString *)&v26.VStr[1].16);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v61.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v26.VStr[1].RefCount);
      v61.Kind &= 0xFFFFFFF9;
    }
    else
    {
      _mm_prefetch((const char *)&v60, 2);
      *(_QWORD *)&v61.Name.Flags = *(_QWORD *)&v60.Kind;
      v61.Name.Bonus.pWeakProxy = 0i64;
      v61.Name.value.VS._1 = v26;
      v61.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v27.pWeakProxy;
      if ( (v11 & 0x1Fu) > 9 )
      {
        if ( v28 == 10 )
        {
          ++v26.VStr->RefCount;
        }
        else if ( (v11 & 0x1Fu) <= 0xF )
        {
          if ( v26.VStr )
            v26.VStr->Size = (v26.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (v11 & 0x1Fu) <= 0x11 && v27.pWeakProxy )
        {
          v27.pWeakProxy[2].RefCount = (v27.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
        }
      }
      if ( (v61.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v61.Name, &resulta);
        if ( resulta.pNode->Size )
        {
          if ( *resulta.pNode->pData == 64 )
          {
            v61.Kind |= 8u;
            v30 = Scaleform::GFx::ASString::Substring(&resulta, &v62, 1, resulta.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&v61.Name, v30);
            v31 = v62.pNode;
            v19 = v62.pNode->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
          }
        }
        v32 = resulta.pNode;
        v19 = resulta.pNode->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      }
    }
    v33 = *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, _DWORD, _QWORD))this->vfptr[3].~RefCountBaseGC<328>)(
                      this,
                      &v67,
                      &v61,
                      &other,
                      0,
                      0i64) == 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&v61);
    if ( (v11 & 0x1Fu) > 9 )
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v60);
    if ( v33 )
    {
      result->Result = 0;
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
        {
          v19 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&other.Bonus, 0, 24);
          other.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      goto LABEL_36;
    }
    v34 = other.Flags;
    v35.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other.Bonus;
    v36 = other.value;
    other.Flags = a3->Flags;
    other.Bonus.pWeakProxy = a3->Bonus.pWeakProxy;
    other.value = a3->value;
    a3->Flags = v34;
    a3->Bonus = v35;
    a3->value = v36;
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v19 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
    goto LABEL_131;
  }
  result->Result = 1;
LABEL_36:
  if ( (p.Flags & 0x1F) > 9 )
  {
    if ( (p.Flags & 0x200) != 0 )
    {
      v19 = p.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&p.Bonus, 0, 24);
      p.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&p);
    }
  }
  return result;
}

// File Line: 1506
// RVA: 0x7D3730
void __fastcall Scaleform::GFx::AS3::Object::FindProperty(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::FindPropAttr attr)
{
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  unsigned __int64 v8; // rdx
  unsigned int Flags; // ebx
  bool v10; // zf
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  __int64 v12; // rax
  Scaleform::GFx::AS3::Traits *i; // rbx
  Scaleform::GFx::AS3::Object *Prototype; // rax
  __int64 v15[2]; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value other; // [rsp+48h] [rbp-28h] BYREF
  unsigned __int64 index; // [rsp+90h] [rbp+20h] BYREF
  Scaleform::GFx::AS3::Multiname *mna; // [rsp+A0h] [rbp+30h]
  Scaleform::GFx::AS3::FindPropAttr attra; // [rsp+A8h] [rbp+38h]

  attra = attr;
  mna = mn;
  index = 0i64;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(this->pTraits.pObject->pVM, this->pTraits.pObject, mn, &index, this);
  if ( FixedSlot )
  {
    v15[0] = (__int64)FixedSlot;
    v8 = index;
    v15[1] = index;
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    result->pSI = FixedSlot;
    result->SlotIndex = v8;
    Scaleform::GFx::AS3::Value::Assign(&result->This, &other);
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
  }
  else
  {
    pObject = this->pTraits.pObject;
    if ( (pObject->Flags & 2) != 0
      && (attr != FindCall || pObject->TraitsType != Traits_XML || (pObject->Flags & 0x20) != 0) )
    {
      v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Object *, __int64 *, Scaleform::GFx::AS3::Multiname *))this->vfptr[6].ForEachChild_GC)(
              this,
              v15,
              mna);
      result->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      result->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      result->pSI = *(Scaleform::GFx::AS3::SlotInfo **)v12;
      result->SlotIndex = *(_QWORD *)(v12 + 8);
      Scaleform::GFx::AS3::Value::Assign(&result->This, (Scaleform::GFx::AS3::Value *)(v12 + 16));
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
        {
          v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&other.Bonus, 0, 24);
          other.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
    }
    if ( ((result->This.Flags & 0x1F) == 0
       || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
       || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0)
      && attr != FindSet )
    {
      for ( i = this->pTraits.pObject; i; i = i->pParent.pObject )
      {
        if ( !i->pConstructor.pObject )
          i->vfptr[3].~RefCountBaseGC<328>(i);
        Prototype = Scaleform::GFx::AS3::Class::GetPrototype(i->pConstructor.pObject);
        if ( Prototype == this )
          break;
        Scaleform::GFx::AS3::Object::FindProperty(Prototype, result, mna, attra);
        if ( Scaleform::GFx::AS3::PropRef::operator bool(result) )
          break;
      }
    }
  }
}

// File Line: 1552
// RVA: 0x7D0870
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::ExecutePropertyUnsafe(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *a4)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  int v7; // ecx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value scope; // [rsp+28h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::PropRef resulta; // [rsp+68h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+98h] [rbp+17h] BYREF
  __int64 v19; // [rsp+A8h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult v20; // [rsp+D8h] [rbp+57h] BYREF
  unsigned int v21; // [rsp+F8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v22; // [rsp+100h] [rbp+7Fh]

  v19 = -2i64;
  memset(&resulta, 0, 20);
  resulta.This.Bonus.pWeakProxy = 0i64;
  scope.Flags = 12;
  scope.Bonus.pWeakProxy = 0i64;
  scope.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::FindObjProperty(&resulta, pVM, &scope, prop_name, FindCall);
  if ( (resulta.This.Flags & 0x1F) == 0
    || ((__int64)resulta.pSI & 1) != 0 && ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)resulta.pSI & 2) != 0 && ((unsigned __int64)resulta.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    if ( (Scaleform::GFx::AS3::VM::GetValueTraits(pVM, &scope)->Flags & 2) != 0
      || (scope.Flags & 0x1F) <= 4
      || (scope.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, 1006, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, 1069, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v11, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    }
    pNode = v18.Message.pNode;
    v10 = v18.Message.pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_45:
    result->Result = !pVM->HandleException;
    if ( (scope.Flags & 0x1F) > 9 )
    {
      if ( (scope.Flags & 0x200) != 0 )
      {
        v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&scope.Bonus, 0, 24);
        scope.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
      }
    }
    if ( (resulta.This.Flags & 0x1F) > 9 )
    {
      if ( (resulta.This.Flags & 0x200) != 0 )
      {
        v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_55;
      }
LABEL_56:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta.This);
      return result;
    }
    return result;
  }
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&resulta, &v20, pVM, &value, valExecute)->Result )
  {
    v7 = value.Flags & 0x1F;
    if ( (value.Flags & 0x1F) != 0 && ((unsigned int)(v7 - 12) > 3 && v7 != 10 || value.value.VS._1.VStr) )
    {
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(pVM, &value, &scope, a4, v21, v22, 0);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v18, 1006, pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v9 = v18.Message.pNode;
      v10 = v18.Message.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v10 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    goto LABEL_45;
  }
  result->Result = 0;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v10 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (scope.Flags & 0x1F) > 9 )
  {
    if ( (scope.Flags & 0x200) != 0 )
    {
      v10 = scope.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&scope.Bonus, 0, 24);
      scope.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  if ( (resulta.This.Flags & 0x1F) > 9 )
  {
    if ( (resulta.This.Flags & 0x200) == 0 )
      goto LABEL_56;
    v10 = resulta.This.Bonus.pWeakProxy->RefCount-- == 1;
    if ( !v10 )
    {
LABEL_55:
      memset(&resulta.This.Bonus, 0, 24);
      resulta.This.Flags &= 0xFFFFFDE0;
      return result;
    }
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    memset(&resulta.This.Bonus, 0, 24);
    resulta.This.Flags &= 0xFFFFFDE0;
  }
  return result;
}

// File Line: 1596
// RVA: 0x7AC8A0
void __fastcall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::ASString *prop_name,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::ASStringNode *v4; // rcx
  BOOL v6; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-28h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h] BYREF

  v6 = a == aDontEnum;
  pNode = prop_name->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v6;
  key.pSecond = v;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &this->DynAttrs.mHash,
    &this->DynAttrs,
    &key);
  v4 = pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}

// File Line: 1603
// RVA: 0x7AC900
void __fastcall Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *prop_name,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-38h] BYREF
  __int64 v12; // [rsp+28h] [rbp-30h]
  BOOL v13; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+38h] [rbp-20h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+60h] [rbp+8h] BYREF

  v12 = -2i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(prop_name, &v16, &result)->Result )
  {
    v13 = a == aDontEnum;
    pNode = result.pNode;
    ++result.pNode->RefCount;
    key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v13;
    key.pSecond = v;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      &this->DynAttrs.mHash,
      &this->DynAttrs,
      &key);
    v8 = pNode;
    v9 = pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
}

// File Line: 1616
// RVA: 0x7C0940
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Object::DeleteDynamicSlotValuePair(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *mn)
{
  bool v6; // bp
  Scaleform::GFx::ASStringNode *pNode; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // r10
  __int64 v9; // r9
  __int64 EntryCount; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v11; // rcx
  __int64 v12; // rbx
  __int64 v13; // rbx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::Object::DynAttrsKey key; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v19; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(&mn->Name, &v19, &resulta)->Result )
  {
    v6 = 1;
    key.Flags = 0;
    pNode = resulta.pNode;
    key.Name = resulta;
    ++resulta.pNode->RefCount;
    pTable = this->DynAttrs.mHash.pTable;
    if ( !pTable )
      goto LABEL_13;
    v9 = pNode->HashFlags & pTable->SizeMask & 0xFFFFFF;
    EntryCount = (unsigned int)v9;
    v11 = &pTable[4 * v9 + 1];
    if ( v11->EntryCount == -2i64 || v11->SizeMask != v9 )
      goto LABEL_13;
    while ( v11->SizeMask != v9 || (Scaleform::GFx::ASStringNode *)v11[1].SizeMask != pNode )
    {
      EntryCount = v11->EntryCount;
      if ( v11->EntryCount == -1i64 )
        goto LABEL_13;
      v11 = &pTable[4 * EntryCount + 1];
    }
    if ( EntryCount >= 0 && (v12 = (__int64)&pTable[4 * EntryCount + 2]) != 0 )
      v13 = v12 + 16;
    else
LABEL_13:
      v13 = 0i64;
    v14 = pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v13 )
    {
      key.Flags = 0;
      v15 = resulta.pNode;
      key.Name = resulta;
      ++resulta.pNode->RefCount;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::Object::DynAttrsKey>(
        &this->DynAttrs.mHash,
        &key);
      v14 = v15->RefCount-- == 1;
      if ( v14 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      v6 = 0;
    }
    result->Result = v6;
  }
  else
  {
    result->Result = 0;
  }
  v16 = resulta.pNode;
  v14 = resulta.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  return result;
}

// File Line: 1656
// RVA: 0x7ECBD0
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Object::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r9
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 v7; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rax
  __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // r10
  __int64 v11; // r8
  unsigned __int64 v12; // rax
  bool v13; // cc
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v14; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v15; // rdx
  unsigned int v16; // ecx
  Scaleform::GFx::AS3::GlobalSlotIndex *v17; // rax

  pTable = this->DynAttrs.mHash.pTable;
  p_DynAttrs = &this->DynAttrs;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = 0i64;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v7;
      v8 += 4;
    }
    while ( v7 <= SizeMask );
  }
  else
  {
    p_DynAttrs = 0i64;
  }
  if ( ind.Index )
    v9 = ind.Index - 1;
  else
    v9 = -1i64;
  if ( !p_DynAttrs )
    goto LABEL_26;
  v10 = p_DynAttrs->mHash.pTable;
  if ( !p_DynAttrs->mHash.pTable )
    goto LABEL_26;
  v11 = v10->SizeMask;
  if ( v9 > v11 )
    goto LABEL_26;
  v12 = v9 + 1;
  v13 = (__int64)v12 <= v11;
  if ( v12 <= v11 )
  {
    v14 = &v10[4 * v12 + 1];
    do
    {
      if ( v14->EntryCount != -2i64 )
        break;
      ++v12;
      v14 += 4;
    }
    while ( v12 <= v11 );
    goto LABEL_16;
  }
LABEL_17:
  while ( v13 && (v10[4 * v12 + 2].EntryCount & 1) != 0 )
  {
    v13 = (__int64)++v12 <= v11;
    if ( v12 <= v11 )
    {
      v15 = &v10[4 * v12 + 1];
      do
      {
        if ( v15->EntryCount != -2i64 )
          break;
        ++v12;
        v15 += 4;
      }
      while ( v12 <= v11 );
LABEL_16:
      v13 = (__int64)v12 <= v11;
      goto LABEL_17;
    }
  }
  if ( (__int64)v12 <= v11 )
  {
    v16 = v12 + 1;
    v17 = result;
    result->Index = v16;
  }
  else
  {
LABEL_26:
    result->Index = 0;
    return result;
  }
  return v17;
}

// File Line: 1675
// RVA: 0x7ECE70
void __fastcall Scaleform::GFx::AS3::Object::GetNextPropertyName(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  p_DynAttrs = &this->DynAttrs;
  v4 = 0i64;
  pTable = this->DynAttrs.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 4;
    }
    while ( (unsigned __int64)v4 <= SizeMask );
    v4 = p_DynAttrs;
  }
  Scaleform::GFx::AS3::Value::Assign(
    name,
    (Scaleform::GFx::ASString *)&v4->mHash.pTable[4 * (unsigned __int64)(ind.Index - 1) + 2].SizeMask);
}

// File Line: 1685
// RVA: 0x7ED110
void __fastcall Scaleform::GFx::AS3::Object::GetNextPropertyValue(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  if ( ind.Index )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Object *, __int64, Scaleform::GFx::AS3::Value *))this->vfptr[1].Finalize_GC)(
      this,
      ind.Index - 1i64,
      value);
}

// File Line: 1702
// RVA: 0x7D1B50
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Object::FindDynamicSlot(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *p_Name; // rbx
  Scaleform::GFx::ASStringNode *pNode; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // r10
  __int64 v8; // r9
  __int64 EntryCount; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rax
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::PropRef *v17; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+70h] [rbp+18h] BYREF

  v17 = result;
  p_Name = &mn->Name;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(p_Name, &v16, &resulta)->Result )
  {
    pNode = resulta.pNode;
    ++resulta.pNode->RefCount;
    pTable = this->DynAttrs.mHash.pTable;
    if ( !pTable )
      goto LABEL_13;
    v8 = pNode->HashFlags & pTable->SizeMask & 0xFFFFFF;
    EntryCount = (unsigned int)v8;
    v10 = &pTable[4 * v8 + 1];
    if ( v10->EntryCount == -2i64 || v10->SizeMask != v8 )
      goto LABEL_13;
    while ( v10->SizeMask != v8 || (Scaleform::GFx::ASStringNode *)v10[1].SizeMask != pNode )
    {
      EntryCount = v10->EntryCount;
      if ( v10->EntryCount == -1i64 )
        goto LABEL_13;
      v10 = &pTable[4 * EntryCount + 1];
    }
    if ( EntryCount >= 0 && (v11 = (__int64)&pTable[4 * EntryCount + 2]) != 0 )
      v12 = v11 + 16;
    else
LABEL_13:
      v12 = 0i64;
    result->pSI = (Scaleform::GFx::AS3::SlotInfo *)(v12 | 1);
    result->This.Flags = 12;
    result->This.Bonus.pWeakProxy = 0i64;
    result->This.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    v13 = pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    result->pSI = 0i64;
    result->SlotIndex = 0i64;
    result->This.Flags = 0;
    result->This.Bonus.pWeakProxy = 0i64;
  }
  v14 = resulta.pNode;
  v13 = resulta.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  return result;
}

// File Line: 1776
// RVA: 0x7F0070
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GetSuperProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Value *a4,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Multiname *mn)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rdi
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // r12
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::Extra v13; // rax
  Scaleform::GFx::AS3::Value::VU v14; // kr00_16
  bool v15; // zf
  unsigned __int64 index[2]; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+40h] BYREF

  index[1] = -2i64;
  ValueTraits = ot;
  if ( !ot )
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  pObject = ValueTraits->pParent.pObject;
  if ( !pObject )
    goto LABEL_18;
  index[0] = 0i64;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(vm, pObject, mn, index, 0i64);
  if ( !FixedSlot )
    goto LABEL_18;
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Traits::GetVT(pObject);
  if ( !Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(FixedSlot, &resulta, vm, &value)->Result )
  {
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v15 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v15 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
LABEL_18:
    result->Result = 0;
    return result;
  }
  Flags = value.Flags;
  v13.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)value.Bonus;
  v14 = value.value;
  value.Flags = a4->Flags;
  value.Bonus.pWeakProxy = a4->Bonus.pWeakProxy;
  value.value = a4->value;
  a4->Flags = Flags;
  a4->Bonus = v13;
  a4->value = v14;
  result->Result = 1;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v15 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return result;
}

// File Line: 1831
// RVA: 0x81E950
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::SetSuperProperty(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Traits *ot,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Traits *pObject; // rsi
  Scaleform::GFx::AS3::Traits *v10; // rdx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // r15
  bool v12; // al
  unsigned __int64 index[4]; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h] BYREF

  ValueTraits = ot;
  if ( !ot )
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(vm, _this);
  pObject = ValueTraits->pParent.pObject;
  if ( pObject )
  {
    v10 = ValueTraits->pParent.pObject;
    index[0] = 0i64;
    FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(vm, v10, mn, index, 0i64);
    v12 = 0;
    if ( FixedSlot )
    {
      Scaleform::GFx::AS3::Traits::GetVT(pObject);
      if ( Scaleform::GFx::AS3::SlotInfo::SetSlotValue(FixedSlot, &resulta, vm, value)->Result )
        v12 = 1;
    }
    result->Result = v12;
  }
  else
  {
    result->Result = 0;
  }
  return result;
}

// File Line: 1879
// RVA: 0x7EF460
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::SlotInfo::ValTarget vtt)
{
  Scaleform::GFx::AS3::SlotInfo *pSI; // rcx
  bool v8; // di
  unsigned __int64 v9; // rcx
  int v10; // eax
  Scaleform::GFx::AS3::Value::V2U v12; // [rsp+48h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+8h] BYREF

  pSI = this->pSI;
  v8 = 1;
  if ( ((unsigned __int8)pSI & 3) != 0 )
  {
    if ( ((unsigned __int8)pSI & 3) == 1i64 )
    {
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (Scaleform::GFx::AS3::Value *)((unsigned __int64)pSI & 0xFFFFFFFFFFFFFFFEui64));
      result->Result = 1;
      return result;
    }
    if ( ((unsigned __int8)pSI & 3) == 2i64 )
    {
      value->Flags &= 0xFFFFFFEC;
      value->Flags |= 0xCu;
      v9 = (unsigned __int64)pSI & 0xFFFFFFFFFFFFFFFDui64;
      value->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v9;
      value->value.VS._2 = v12;
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 32);
        result->Result = 1;
        *(_DWORD *)(v9 + 32) = (v10 + 1) & 0x8FBFFFFF;
        return result;
      }
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(pSI, &resulta, vm, value, &this->This, 0i64, vtt)->Result;
  }
  result->Result = v8;
  return result;
}

// File Line: 1925
// RVA: 0x81D740
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::PropRef::SetSlotValue(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::SlotInfo *pSI; // rcx
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  bool v8; // cl
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF

  pSI = this->pSI;
  if ( ((unsigned __int8)pSI & 3) != 0 )
  {
    if ( ((unsigned __int8)pSI & 3) == 1i64 )
    {
      Scaleform::GFx::AS3::Value::Assign(
        (Scaleform::GFx::AS3::Value *)((unsigned __int64)pSI & 0xFFFFFFFFFFFFFFFEui64),
        value);
      result->Result = 1;
      return result;
    }
    else
    {
      v7 = result;
      result->Result = ((unsigned __int8)pSI & 3) != 2i64;
    }
  }
  else
  {
    v8 = Scaleform::GFx::AS3::SlotInfo::SetSlotValue(pSI, &resulta, vm, value, &this->This, 0i64)->Result;
    v7 = result;
    result->Result = v8;
  }
  return v7;
}

// File Line: 1952
// RVA: 0x77BEC0
void __fastcall Scaleform::GFx::AS3::Class::Class(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // r8
  Scaleform::GFx::AS3::Traits *pObject; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rdi
  Scaleform::GFx::AS3::Class *Finalize_GC; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rcx
  unsigned int RefCount; // eax

  GC = t->pVM->GC.GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned __int64)GC;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Object::`vftable;
  this->pTraits.pObject = t;
  t->RefCount = (t->RefCount + 1) & 0x8FBFFFFF;
  this->DynAttrs.mHash.pTable = 0i64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Class::`vftable;
  pObject = t->pParent.pObject;
  if ( pObject )
  {
    vfptr = pObject[1].vfptr;
    if ( !vfptr[5].Finalize_GC )
      (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))vfptr->ForEachChild_GC + 10))(vfptr);
    Finalize_GC = (Scaleform::GFx::AS3::Class *)vfptr[5].Finalize_GC;
  }
  else
  {
    Finalize_GC = 0i64;
  }
  this->ParentClass.pObject = Finalize_GC;
  if ( Finalize_GC )
    Finalize_GC->RefCount = (Finalize_GC->RefCount + 1) & 0x8FBFFFFF;
  this->pPrototype.pObject = 0i64;
  v8 = t->ITraits.pObject;
  v9 = v8->pConstructor.pObject;
  if ( this != v9 )
  {
    if ( v9 )
    {
      if ( ((unsigned __int8)v9 & 1) != 0 )
      {
        v8->pConstructor.pObject = (Scaleform::GFx::AS3::Class *)((char *)v9 - 1);
      }
      else
      {
        RefCount = v9->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
        }
      }
    }
    v8->pConstructor.pObject = this;
  }
}

// File Line: 1959
// RVA: 0x789F20
void __fastcall Scaleform::GFx::AS3::Class::~Class(Scaleform::GFx::AS3::Class *this)
{
  Scaleform::GFx::AS3::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v4; // rcx
  unsigned int v5; // eax

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Class::`vftable;
  pObject = this->pPrototype.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
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
  v4 = this->ParentClass.pObject;
  if ( v4 )
  {
    if ( ((unsigned __int8)v4 & 1) != 0 )
    {
      this->ParentClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( (v5 & 0x3FFFFF) != 0 )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
  Scaleform::GFx::AS3::Object::~Object(this);
}

// File Line: 1966
// RVA: 0x7B8830
void __fastcall Scaleform::GFx::AS3::Class::Construct(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM *pVM; // rsi
  unsigned int v11; // ecx
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+28h] [rbp-30h] BYREF
  char v16; // [rsp+60h] [rbp+8h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *))pObject[1].vfptr->ForEachChild_GC
   + 11))(
    pObject[1].vfptr,
    _this,
    pObject[1].vfptr);
  v11 = _this->Flags & 0x1F;
  if ( (v11 - 12 <= 3 || v11 == 10) && !_this->value.VS._1.VStr )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1000, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v12, &Scaleform::GFx::AS3::fl_errors::MemoryErrorTI);
    pNode = v15.Message.pNode;
    if ( v15.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( *(_BYTE *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *, Scaleform::GFx::AS3::Value *))this->vfptr[6].Finalize_GC)(
                   this,
                   &v16,
                   _this) )
  {
    (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, bool))_this->value.VS._1.VStr->pData + 13))(
      _this->value.VS._1,
      extCall);
    ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *))this->vfptr[7].ForEachChild_GC)(
      this,
      _this,
      argc,
      argv);
  }
}

// File Line: 1995
// RVA: 0x8079F0
void __fastcall Scaleform::GFx::AS3::Class::PostInit(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, _QWORD, Scaleform::GFx::AS3::Value *))_this->value.VS._1.VStr->pData
   + 11))(
    _this->value.VS._1,
    argc,
    argv);
}

// File Line: 2002
// RVA: 0x7D54F0
void __fastcall Scaleform::GFx::AS3::Class::ForEachChild_GC(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->ParentClass.pObject )
    op(prcc, &this->ParentClass.pObject);
  if ( this->pPrototype.pObject )
    op(prcc, &this->pPrototype.pObject);
}

// File Line: 2012
// RVA: 0x7F52D0
void __fastcall Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj,
        __int64 (__fastcall **f)(char *, int *, __int64))
{
  Scaleform::GFx::AS3::Traits *vfptr; // rdi
  __int64 v7; // rbx
  unsigned __int64 FirstOwnSlotNum; // rsi
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // rax
  __int64 v10; // r14
  Scaleform::GFx::ASStringNode *SlotNameNode; // rsi
  Scaleform::GFx::AS3::Value *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int RefCount; // eax
  int v18; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *v19; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v21; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v22; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::AS3::VTable *VT; // [rsp+B0h] [rbp+40h]

  vfptr = (Scaleform::GFx::AS3::Traits *)this->pTraits.pObject[1].vfptr;
  VT = Scaleform::GFx::AS3::Traits::GetVT(vfptr);
  v7 = 0i64;
  FirstOwnSlotNum = vfptr->FirstOwnSlotNum;
  if ( FirstOwnSlotNum + vfptr->VArray.Data.Size )
  {
    do
    {
      if ( v7 < 0 || v7 < FirstOwnSlotNum )
        SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(vfptr->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v7);
      else
        SlotInfo = &vfptr->VArray.Data.Data[(unsigned int)v7 - FirstOwnSlotNum].Value;
      v10 = *(_DWORD *)SlotInfo;
      if ( (*(_DWORD *)SlotInfo & 0x7C00) == 11264 )
      {
        if ( v7 < 0 || v7 < FirstOwnSlotNum )
          SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                           vfptr->Parent,
                           (Scaleform::GFx::AS3::AbsoluteIndex)v7);
        else
          SlotNameNode = vfptr->VArray.Data.Data[(unsigned int)v7 - FirstOwnSlotNum].Key.pObject;
        v12 = (Scaleform::GFx::AS3::Value *)(*f)(
                                              (char *)this + *((int *)f + 2),
                                              &v21,
                                              (__int64)&VT->VTMethods.Data.Data[(unsigned int)(v10 >> 15)]);
        ++SlotNameNode->RefCount;
        v18 = 1;
        v19 = SlotNameNode;
        ++SlotNameNode->RefCount;
        key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v18;
        key.pSecond = v12;
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
          &obj->DynAttrs.mHash,
          &obj->DynAttrs,
          &key);
        v13 = v19;
        v14 = v19->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        v14 = SlotNameNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
        if ( (v21 & 0x1Fu) > 9 )
        {
          if ( (v21 & 0x200) != 0 )
          {
            v14 = (*v22)-- == 1;
            if ( v14 )
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
                v14 = v23->RefCount-- == 1;
                if ( v14 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v15);
                break;
              case 0xB:
              case 0xC:
              case 0xD:
              case 0xE:
              case 0xF:
                v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23;
                if ( ((unsigned __int8)v23 & 1) == 0 )
                  goto LABEL_27;
                v23 = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
                break;
              case 0x10:
              case 0x11:
                v16 = v24;
                if ( ((unsigned __int8)v24 & 1) != 0 )
                {
                  v24 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v24 - 1);
                }
                else
                {
LABEL_27:
                  if ( v16 )
                  {
                    RefCount = v16->RefCount;
                    if ( (RefCount & 0x3FFFFF) != 0 )
                    {
                      v16->RefCount = RefCount - 1;
                      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
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
      if ( v7 < 0 || v7 < vfptr->FirstOwnSlotNum + vfptr->VArray.Data.Size )
        ++v7;
      FirstOwnSlotNum = vfptr->FirstOwnSlotNum;
    }
    while ( (unsigned int)v7 < FirstOwnSlotNum + vfptr->VArray.Data.Size );
  }
}

// File Line: 2043
// RVA: 0x7F4110
void __fastcall Scaleform::GFx::AS3::Class::InitPrototype(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::Value *(__fastcall *v5)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *); // [rsp+20h] [rbp-18h] BYREF
  int v6; // [rsp+28h] [rbp-10h]

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v6 = 0;
  v5 = Scaleform::GFx::AS3::Class::ConvertCheckType;
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v5);
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}

// File Line: 2052
// RVA: 0x7AB920
void __fastcall Scaleform::GFx::AS3::Class::AddConstructor(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASStringNode *v6; // rcx
  int v7; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value v10; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  v10.Flags = 13;
  v10.Bonus.pWeakProxy = 0i64;
  v10.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)this;
  if ( this )
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         "constructor");
  v7 = 1;
  pNode = v3->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v7;
  key.pSecond = &v10;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v4 = pNode;
  v5 = pNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v6 = result.pNode;
  v5 = result.pNode->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
    {
      v5 = v10.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v10.Bonus, 0, 24);
      v10.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
}

// File Line: 2062
// RVA: 0x8004E0
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Class::MakePrototype(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  result->pV = resulta.pV;
  return result;
}

// File Line: 2067
// RVA: 0x7BACC0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Class::ConvertCopy(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  result->Flags = v->Flags;
  result->Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  result->value = v->value;
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags & 0x200) != 0 )
    {
      ++v->Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (v->Flags & 0x1F) == 10 )
      {
        ++v->value.VS._1.VStr->RefCount;
        return result;
      }
      if ( (v->Flags & 0x1F) > 0xA )
      {
        if ( (v->Flags & 0x1F) <= 0xF )
        {
          VObj = v->value.VS._1;
        }
        else
        {
          if ( (v->Flags & 0x1F) > 0x11 )
            return result;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v->value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
  return result;
}

// File Line: 2073
// RVA: 0x7BAC10
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Class::ConvertCheckType(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::ThunkInfo *VThunk; // rbp
  Scaleform::GFx::AS3::Classes::Function **pObject; // rdi
  Scaleform::GFx::AS3::Instances::CheckTypeTF *pV; // rcx
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+38h] [rbp-20h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Value *v11; // [rsp+68h] [rbp+10h]

  v11 = result;
  VThunk = v->value.VS._1.VThunk;
  pObject = (Scaleform::GFx::AS3::Classes::Function **)this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject;
  if ( !pObject[17] )
    ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::Function **))(*pObject)[1]._pRCC)(pObject);
  pV = Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(pObject[17], &resulta, this, VThunk)->pV;
  result->Flags = 0;
  result->Bonus.pWeakProxy = 0i64;
  result->Flags &= ~0x10u;
  result->Flags |= 0xFu;
  result->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pV;
  result->value.VS._2 = v9;
  return result;
}

// File Line: 2078
// RVA: 0x7EE710
Scaleform::GFx::AS3::Object *__fastcall Scaleform::GFx::AS3::Class::GetPrototype(Scaleform::GFx::AS3::Class *this)
{
  Scaleform::GFx::AS3::Object **v2; // rax
  Scaleform::GFx::AS3::Object *pObject; // rcx
  Scaleform::GFx::AS3::Object *v4; // rbx
  unsigned int RefCount; // eax
  char v7; // [rsp+30h] [rbp+8h] BYREF

  if ( this->pPrototype.pObject )
    return this->pPrototype.pObject;
  v2 = (Scaleform::GFx::AS3::Object **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Class *, char *))this->vfptr[8].ForEachChild_GC)(
                                         this,
                                         &v7);
  pObject = this->pPrototype.pObject;
  v4 = *v2;
  if ( *v2 != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
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
    this->pPrototype.pObject = v4;
  }
  ((void (__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Object *))this->vfptr[7].Finalize_GC)(
    this,
    this->pPrototype.pObject);
  return this->pPrototype.pObject;
}

// File Line: 2094
// RVA: 0x858980
void __fastcall Scaleform::GFx::AS3::Class::prototypeGet(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *Prototype; // rax

  Prototype = Scaleform::GFx::AS3::Class::GetPrototype(this);
  Scaleform::GFx::AS3::Value::Assign(result, Prototype);
}

// File Line: 2099
// RVA: 0x861A20
void __fastcall Scaleform::GFx::AS3::Class::toString(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::String *v5; // rax
  Scaleform::String *v6; // rax
  Scaleform::GFx::ASString *ASString; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString v13; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::String v14; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::String resulta; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::GFx::ASStringNode *v16; // [rsp+68h] [rbp+20h] BYREF

  v4 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASStringNode **))this->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[1].~RefCountBaseGC<328>)(
                                     this->pTraits.pObject,
                                     &v16);
  v5 = Scaleform::operator+(&resulta, "[class ", v4);
  v6 = Scaleform::String::operator+(v5, &v14, "]");
  ASString = Scaleform::GFx::AS3::Object::GetASString(this, &v13, v6);
  pNode = ASString->pNode;
  ++ASString->pNode->RefCount;
  v9 = result->pNode;
  v10 = result->pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  result->pNode = pNode;
  v11 = v13.pNode;
  v10 = v13.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v14.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v12 = v16;
  v10 = v16->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 2110
// RVA: 0x7B2850
void __fastcall Scaleform::GFx::AS3::Class::Call(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h] BYREF

  if ( argc == 1 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::AS3::Value *const, Scaleform::GFx::AS3::Value *))this->pTraits.pObject->Scaleform::GFx::AS3::Object::vfptr[3].Finalize_GC)(
           this->pTraits.pObject,
           argv,
           result) )
    {
      return;
    }
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1034, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v10, 1112, this->pTraits.pObject->pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::RangeErrorTI);
  }
  pNode = v10.Message.pNode;
  if ( v10.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 2141
// RVA: 0x7AAE90
void __fastcall Scaleform::GFx::AS3::NamespaceSet::Add(
        Scaleform::GFx::AS3::NamespaceSet *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *p_Namespaces; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v4; // rdx
  unsigned int RefCount; // eax

  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  p_Namespaces = &this->Namespaces;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Namespaces,
    &this->Namespaces,
    this->Namespaces.Data.Size + 1);
  v4 = &p_Namespaces->Data.Data[p_Namespaces->Data.Size - 1];
  if ( v4 )
  {
    v4->pObject = ns;
    if ( ns )
      ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  }
  if ( ns && ((unsigned __int8)ns & 1) == 0 )
  {
    RefCount = ns->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      ns->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(ns);
    }
  }
}

// File Line: 2149
// RVA: 0x784E70
void __fastcall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
{
  this->Flags = 12;
  this->Bonus.pWeakProxy = 0i64;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2163
// RVA: 0x7B1950
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
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
  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2172
// RVA: 0x7B1BD0
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2181
// RVA: 0x7B17A0
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
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
  this->Flags &= 0xFFFFFFED;
  this->Flags |= 0xDu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2190
// RVA: 0x7B1B70
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Class *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFED;
  this->Flags |= 0xDu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v2;
  if ( v )
    v->RefCount = (v->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 2199
// RVA: 0x807270
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Object *v)
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
  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
}

// File Line: 2207
// RVA: 0x807490
void __fastcall Scaleform::GFx::AS3::Value::PickUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Object *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v2;
}

// File Line: 2215
// RVA: 0x8070F0
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Class *v)
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
  this->Flags &= 0xFFFFFFED;
  this->Flags |= 0xDu;
  this->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v;
  this->value.VS._2 = v7;
}

