// File Line: 35
// RVA: 0x158BFC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D060 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoGet;
  return result;
}

// File Line: 36
// RVA: 0x1592260
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D070 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoSet;
  return result;
}

// File Line: 37
// RVA: 0x158BF60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D080 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 38
// RVA: 0x158BF90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D090 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::toString;
  return result;
}

// File Line: 48
// RVA: 0x780D30
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::NetStatusEvent(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &this->Type);
  this->CurrentTarget.pObject = 0i64;
  this->Target.pObject = 0i64;
  this->Phase = 2;
  *((_BYTE *)&this->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) &= 0xC0u;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::`vftable;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &this->Code);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &this->Level);
}

// File Line: 54
// RVA: 0x84F8F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoGet(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // rbx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned int v16; // eax
  int v17; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v20; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Object *v21; // [rsp+A0h] [rbp+30h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+A8h] [rbp+38h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  pV = resulta.pV;
  v21 = resulta.pV;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v20.Flags = 10;
  v20.Bonus.pWeakProxy = 0i64;
  pNode = this->Code.pNode;
  v20.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    v20.value.VS._1.VStr = 0i64;
    v20.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
    v20.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  v17 = 0;
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          StringManagerRef,
          (Scaleform::GFx::ASString *)&resulta,
          "code")->pNode;
  ++v18->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v17;
  key.pSecond = &v20;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &pV->DynAttrs.mHash,
    &pV->DynAttrs,
    &key);
  v7 = v18;
  v8 = v18->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v8 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( (v20.Flags & 0x1F) > 9 )
  {
    if ( (v20.Flags & 0x200) != 0 )
    {
      v8 = v20.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v20.Bonus, 0, 24);
      v20.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
    }
  }
  v20.Flags = 10;
  v20.Bonus.pWeakProxy = 0i64;
  v10 = this->Level.pNode;
  v20.value.VS._1.VStr = v10;
  if ( v10 == &v10->pManager->NullStringNode )
  {
    v20.value.VS._1.VStr = 0i64;
    v20.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
    v20.Flags = 12;
  }
  else
  {
    ++v10->RefCount;
  }
  String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
             StringManagerRef,
             (Scaleform::GFx::ASString *)&resulta,
             "level");
  v17 = 0;
  v18 = String->pNode;
  ++v18->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v17;
  key.pSecond = &v20;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &pV->DynAttrs.mHash,
    &pV->DynAttrs,
    &key);
  v12 = v18;
  v8 = v18->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v8 = LODWORD(resulta.pV->pPrev)-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( (v20.Flags & 0x1F) > 9 )
  {
    if ( (v20.Flags & 0x200) != 0 )
    {
      v8 = v20.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v20.Bonus, 0, 24);
      v20.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
    }
  }
  if ( &v21 != (Scaleform::GFx::AS3::Instances::fl::Object **)result )
  {
    if ( pV )
      pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
    pObject = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v21 = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pV - 1);
    }
    else
    {
      v16 = pV->RefCount;
      if ( (v16 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
}

// File Line: 64
// RVA: 0x84FBC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoSet(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v4; // r13
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r12
  char v6; // si
  char v7; // di
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Value::V2U v9; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // r8
  int v11; // r14d
  const char *pData; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::Value::V1U *v18; // rax
  Scaleform::GFx::AS3::Value::V1U v19; // rbx
  Scaleform::GFx::AS3::Value::V2U v20; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // r8
  int v22; // edi
  const char *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Value v32; // [rsp+20h] [rbp-89h] BYREF
  int v33; // [rsp+40h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v34; // [rsp+48h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value v35; // [rsp+50h] [rbp-59h] BYREF
  int v36; // [rsp+70h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v37; // [rsp+78h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value v38; // [rsp+80h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::Value v39; // [rsp+A0h] [rbp-9h] BYREF
  __int64 v40; // [rsp+C0h] [rbp+17h]
  Scaleform::GFx::ASString v41; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v42; // [rsp+120h] [rbp+77h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+128h] [rbp+7Fh] BYREF

  v40 = -2i64;
  v4 = value->value.VS._1;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v6 = 10;
  v7 = 10;
  v32.Flags = 10;
  v32.Bonus.pWeakProxy = 0i64;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            StringManagerRef,
            &resulta,
            "code")->pNode;
  v32.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    v32.value.VS._1.VStr = 0i64;
    v9.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v32.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v7 = 12;
    v32.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    v9.VObj = (Scaleform::GFx::AS3::Object *)v32.value.VS._2;
  }
  pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->PublicNamespace.pObject;
  v33 = 0;
  v34.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  v35.Flags = 0;
  v35.Bonus.pWeakProxy = 0i64;
  v11 = v7 & 0x1F;
  if ( (unsigned int)(v11 - 12) <= 3
    && pNode
    && (pData = pNode[1].pData, *((_DWORD *)pData + 30) == 17)
    && (pData[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v35, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v34,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    v33 &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v32, 2);
    *(_QWORD *)&v35.Flags = *(_QWORD *)&v32.Flags;
    v35.Bonus.pWeakProxy = 0i64;
    v35.value.VS._1.VStr = pNode;
    v35.value.VS._2 = v9;
    if ( (v7 & 0x1Fu) > 9 )
    {
      if ( v11 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v7 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v7 & 0x1Fu) <= 0x11 && v9.VObj )
      {
        v9.VObj->RefCount = (v9.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v35.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v35, &v41);
      if ( v41.pNode->Size )
      {
        if ( *v41.pNode->pData == 64 )
        {
          v33 |= 8u;
          v13 = Scaleform::GFx::ASString::Substring(&v41, &v42, 1, v41.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v35, v13);
          v14 = v42.pNode;
          v15 = v42.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        }
      }
      v16 = v41.pNode;
      v15 = v41.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
  }
  if ( (v7 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
  v17 = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                             StringManagerRef,
                                             &resulta,
                                             "level");
  v32.Flags = 10;
  v32.Bonus.pWeakProxy = 0i64;
  v19 = *v18;
  v32.value.VS._1 = v19;
  if ( v19.VStr == &v19.VStr->pManager->NullStringNode )
  {
    v19.VStr = 0i64;
    v32.value.VS._1.VStr = 0i64;
    v20.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v32.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v6 = 12;
    v32.Flags = 12;
  }
  else
  {
    ++v19.VStr->RefCount;
    v20.VObj = (Scaleform::GFx::AS3::Object *)v32.value.VS._2;
  }
  v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->PublicNamespace.pObject;
  v36 = 0;
  v37.pObject = v21;
  if ( v21 )
    v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
  v38.Flags = 0;
  v38.Bonus.pWeakProxy = 0i64;
  v22 = v6 & 0x1F;
  if ( (unsigned int)(v22 - 12) <= 3
    && v19.VStr
    && (v23 = v19.VStr[1].pData, *((_DWORD *)v23 + 30) == 17)
    && (v23[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v38, (Scaleform::GFx::ASString *)&v19.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v37,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v19.VStr[1].RefCount);
    v36 &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v32, 2);
    *(_QWORD *)&v38.Flags = *(_QWORD *)&v32.Flags;
    v38.Bonus.pWeakProxy = 0i64;
    v38.value.VS._1 = v19;
    v38.value.VS._2 = v20;
    if ( (v6 & 0x1Fu) > 9 )
    {
      if ( v22 == 10 )
      {
        ++v19.VStr->RefCount;
      }
      else if ( (v6 & 0x1Fu) <= 0xF )
      {
        if ( v19.VStr )
          v19.VStr->Size = (v19.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v6 & 0x1Fu) <= 0x11 && v20.VObj )
      {
        v20.VObj->RefCount = (v20.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v38.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v38, &v41);
      if ( v41.pNode->Size )
      {
        if ( *v41.pNode->pData == 64 )
        {
          v36 |= 8u;
          v24 = Scaleform::GFx::ASString::Substring(&v41, &v42, 1, v41.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v38, v24);
          v25 = v42.pNode;
          v15 = v42.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        }
      }
      v26 = v41.pNode;
      v15 = v41.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    }
  }
  if ( (v6 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
  v27 = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  v39.Flags = 0;
  v39.Bonus.pWeakProxy = 0i64;
  if ( *(_BYTE *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))v4.VStr->pData
                  + 4))(
                   v4,
                   &v41,
                   &v33,
                   &v39) )
    Scaleform::GFx::AS3::Value::Convert2String(&v39, (Scaleform::GFx::AS3::CheckResult *)&v41, &this->Code);
  if ( *(_BYTE *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))v4.VStr->pData
                  + 4))(
                   v4,
                   &v41,
                   &v36,
                   &v39) )
    Scaleform::GFx::AS3::Value::Convert2String(&v39, (Scaleform::GFx::AS3::CheckResult *)&v41, &this->Level);
  if ( (v39.Flags & 0x1F) > 9 )
  {
    if ( (v39.Flags & 0x200) != 0 )
    {
      v15 = v39.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v39.Bonus, 0, 24);
      v39.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v39);
    }
  }
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags & 0x200) != 0 )
    {
      v15 = v38.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v38.Bonus, 0, 24);
      v38.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
    }
  }
  v28 = v37.pObject;
  if ( v37.pObject )
  {
    if ( ((__int64)v37.pObject & 1) != 0 )
    {
      --v37.pObject;
    }
    else
    {
      RefCount = v37.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v37.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
      }
    }
  }
  if ( (v35.Flags & 0x1F) > 9 )
  {
    if ( (v35.Flags & 0x200) != 0 )
    {
      v15 = v35.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v35.Bonus, 0, 24);
      v35.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
    }
  }
  v30 = v34.pObject;
  if ( v34.pObject )
  {
    if ( ((__int64)v34.pObject & 1) != 0 )
    {
      --v34.pObject;
    }
    else
    {
      v31 = v34.pObject->RefCount;
      if ( (v31 & 0x3FFFFF) != 0 )
      {
        v34.pObject->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
}

// File Line: 87
// RVA: 0x865AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rbx
  const char *v5; // rax
  Scaleform::GFx::AS3::Value::V1U *v6; // rax
  Scaleform::GFx::AS3::Value::V1U v7; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rdx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rdx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rdx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rdx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rdx
  Scaleform::GFx::ASStringNode *v24; // rcx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value v26; // [rsp+20h] [rbp-C8h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-A8h] BYREF
  int v28; // [rsp+60h] [rbp-88h]
  __int64 v29; // [rsp+68h] [rbp-80h]
  char v30[24]; // [rsp+70h] [rbp-78h]
  int v31; // [rsp+88h] [rbp-60h]
  __int64 v32; // [rsp+90h] [rbp-58h]
  __int128 v33; // [rsp+98h] [rbp-50h]
  int v34; // [rsp+A8h] [rbp-40h]
  __int64 v35; // [rsp+B0h] [rbp-38h]
  __int128 v36; // [rsp+B8h] [rbp-30h]
  int v37; // [rsp+C8h] [rbp-20h]
  __int64 v38; // [rsp+D0h] [rbp-18h]
  __int128 v39; // [rsp+D8h] [rbp-10h]
  __int64 v40; // [rsp+E8h] [rbp+0h]
  Scaleform::GFx::ASString resulta; // [rsp+118h] [rbp+30h] BYREF

  v40 = -2i64;
  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *))this->vfptr[6].Finalize_GC)(this);
  v6 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            StringManagerRef,
                                            &resulta,
                                            v5);
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v7 = *v6;
  argv.value.VS._1 = *v6;
  if ( v6->VStr == &v6->VStr->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)&v26.Flags;
    argv.Flags = 12;
  }
  else
  {
    ++v7.VStr->RefCount;
  }
  pNode = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          &resulta,
          "type");
  v28 = 10;
  v29 = 0i64;
  v11 = v10->pNode;
  *(Scaleform::GFx::ASString *)v30 = (Scaleform::GFx::ASString)v10->pNode;
  if ( v10->pNode == &v10->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    *(_OWORD *)v30 = *(_OWORD *)&v26.Flags;
    v28 = 12;
  }
  else
  {
    ++v11->RefCount;
  }
  v12 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          &resulta,
          "bubbles");
  LODWORD(v29) = 10;
  *(_QWORD *)v30 = 0i64;
  v14 = v13->pNode;
  *(Scaleform::GFx::ASString *)&v30[8] = (Scaleform::GFx::ASString)v13->pNode;
  if ( v13->pNode == &v13->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    *(_OWORD *)&v30[8] = *(_OWORD *)&v26.Flags;
    LODWORD(v29) = 12;
  }
  else
  {
    ++v14->RefCount;
  }
  v15 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          &resulta,
          "cancelable");
  v31 = 10;
  v32 = 0i64;
  v17 = v16->pNode;
  *(Scaleform::GFx::ASString *)&v33 = (Scaleform::GFx::ASString)v16->pNode;
  if ( v16->pNode == &v16->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    v33 = *(_OWORD *)&v26.Flags;
    v31 = 12;
  }
  else
  {
    ++v17->RefCount;
  }
  v18 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          &resulta,
          "info");
  v34 = 10;
  v35 = 0i64;
  v20 = v19->pNode;
  *(Scaleform::GFx::ASString *)&v36 = (Scaleform::GFx::ASString)v19->pNode;
  if ( v19->pNode == &v19->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    v36 = *(_OWORD *)&v26.Flags;
    v34 = 12;
  }
  else
  {
    ++v20->RefCount;
  }
  v21 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  v22 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          StringManagerRef,
          &resulta,
          "target");
  v37 = 10;
  v38 = 0i64;
  v23 = v22->pNode;
  *(Scaleform::GFx::ASString *)&v39 = (Scaleform::GFx::ASString)v22->pNode;
  if ( v22->pNode == &v22->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    v39 = *(_OWORD *)&v26.Flags;
    v37 = 12;
  }
  else
  {
    ++v23->RefCount;
  }
  v24 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  v26.Flags = 0;
  v26.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &v26, 6u, &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v26, (Scaleform::GFx::AS3::CheckResult *)&resulta, result);
  Flags = v26.Flags;
  if ( (v26.Flags & 0x1F) > 9 )
  {
    if ( (v26.Flags & 0x200) != 0 )
    {
      v9 = v26.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v26.Bonus, 0, 24);
      v26.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    }
  }
  `eh vector destructor iterator(&argv, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 112
// RVA: 0x798AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
    Scaleform::GFx::AS3::Value::Convert2String(argv + 3, &result, &this->Code);
  if ( argc >= 5 )
    Scaleform::GFx::AS3::Value::Convert2String(argv + 4, &result, &this->Level);
}

// File Line: 121
// RVA: 0x7B6410
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::StatusEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rbp
  Scaleform::GFx::ASStringNode *vfptr; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode *pRCC; // rcx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Code.pNode;
  ++pNode->RefCount;
  vfptr = (Scaleform::GFx::ASStringNode *)pObject[1].vfptr;
  v7 = vfptr->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(vfptr);
  pObject[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)pNode;
  v8 = this->Level.pNode;
  ++v8->RefCount;
  pRCC = (Scaleform::GFx::ASStringNode *)pObject[1]._pRCC;
  v7 = pRCC->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pRCC);
  pObject[1].pRCCRaw = (unsigned __int64)v8;
  return result;
}

// File Line: 129
// RVA: 0x7E96B0
const char *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::GetEventName(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this)
{
  return "NetStatusEvent";
}

// File Line: 133
// RVA: 0x7E95C0
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this)
{
  Scaleform::StringDataPtr gname; // [rsp+20h] [rbp-18h] BYREF

  gname.Size = 27i64;
  gname.pStr = "flash.events.NetStatusEvent";
  return Scaleform::GFx::AS3::VM::GetClass(
           this->pTraits.pObject->pVM,
           &gname,
           this->pTraits.pObject->pVM->CurrentDomain.pObject);
}

// File Line: 169
// RVA: 0x7FFD30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 209
// RVA: 0x74F610
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::NetStatusEvent::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::NetStatusEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::NetStatusEvent::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_events::NetStatusEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::`vftable;
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
                                       80i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::NetStatusEvent::`vftable;
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"netStatus";
  }
  return result;
}

