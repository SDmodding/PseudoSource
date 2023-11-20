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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::NetStatusEvent(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::Event::`vftable';
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v2->Type);
  v2->CurrentTarget.pObject = 0i64;
  v2->Target.pObject = 0i64;
  v2->Phase = 2;
  *((_BYTE *)&v2->0 + 84) &= 0xC0u;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::`vftable';
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v2->Code);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v2->Level);
}

// File Line: 54
// RVA: 0x84F8F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoGet(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  __int64 *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v5; // r15
  long double v6; // rcx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  long double v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  __int64 v16; // rcx
  int v17; // eax
  unsigned int v18; // eax
  int v19; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v20; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value v22; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Instances::fl::Object *v23; // [rsp+A0h] [rbp+30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> resulta; // [rsp+A8h] [rbp+38h]

  v2 = (__int64 *)result;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  v4 = resulta.pV;
  v23 = resulta.pV;
  v5 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins;
  v22.Flags = 10;
  v22.Bonus.pWeakProxy = 0i64;
  v6 = *(double *)&v3->Code.pNode;
  v22.value.VNumber = v6;
  if ( *(_QWORD *)&v6 == *(_QWORD *)(*(_QWORD *)&v6 + 8i64) + 104i64 )
  {
    v22.value.VNumber = 0.0;
    v22.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
    v22.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
  }
  v19 = 0;
  v20 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "code")->pNode;
  ++v20->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v19;
  key.pSecond = &v22;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v4->DynAttrs.mHash.pTable,
    &v4->DynAttrs,
    &key);
  v7 = v20;
  v8 = v20->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v8 = LODWORD(resulta.pV->pPrev) == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( (v22.Flags & 0x1F) > 9 )
  {
    if ( (v22.Flags >> 9) & 1 )
    {
      v10 = v22.Bonus.pWeakProxy;
      v8 = v22.Bonus.pWeakProxy->RefCount == 1;
      --v10->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v10);
      v22.Bonus.pWeakProxy = 0i64;
      v22.value = 0ui64;
      v22.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
    }
  }
  v22.Flags = 10;
  v22.Bonus.pWeakProxy = 0i64;
  v11 = *(double *)&v3->Level.pNode;
  v22.value.VNumber = v11;
  if ( *(_QWORD *)&v11 == *(_QWORD *)(*(_QWORD *)&v11 + 8i64) + 104i64 )
  {
    v22.value.VNumber = 0.0;
    v22.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)key.pSecond;
    v22.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v11 + 24i64);
  }
  v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          v5,
          (Scaleform::GFx::ASString *)&resulta,
          "level");
  v19 = 0;
  v20 = v12->pNode;
  ++v20->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v19;
  key.pSecond = &v22;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v4->DynAttrs.mHash.pTable,
    &v4->DynAttrs,
    &key);
  v13 = v20;
  v8 = v20->RefCount == 1;
  --v13->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = (Scaleform::GFx::ASStringNode *)resulta.pV;
  v8 = LODWORD(resulta.pV->pPrev) == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (v22.Flags & 0x1F) > 9 )
  {
    if ( (v22.Flags >> 9) & 1 )
    {
      v15 = v22.Bonus.pWeakProxy;
      v8 = v22.Bonus.pWeakProxy->RefCount == 1;
      --v15->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v15);
      v22.Bonus.pWeakProxy = 0i64;
      v22.value = 0ui64;
      v22.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
    }
  }
  if ( &v23 != (Scaleform::GFx::AS3::Instances::fl::Object **)v2 )
  {
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
    v16 = *v2;
    if ( *v2 )
    {
      if ( v16 & 1 )
      {
        *v2 = v16 - 1;
      }
      else
      {
        v17 = *(_DWORD *)(v16 + 32);
        if ( v17 & 0x3FFFFF )
        {
          *(_DWORD *)(v16 + 32) = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v16);
        }
      }
    }
    *v2 = (__int64)v4;
  }
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v23 = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
    }
    else
    {
      v18 = v4->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v4->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 64
// RVA: 0x84FBC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::infoSet(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *v3; // r15
  long double v4; // r13
  Scaleform::GFx::AS3::StringManager *v5; // r12
  unsigned int v6; // esi
  unsigned int v7; // edi
  Scaleform::GFx::ASStringNode *v8; // rbx
  Scaleform::GFx::AS3::Value::V2U v9; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v10; // r8
  int v11; // er14
  const char *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  long double *v18; // rax
  long double v19; // rbx
  Scaleform::GFx::AS3::Value::V2U v20; // rdx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v21; // r8
  int v22; // edi
  __int64 v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v28; // rcx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Value v32; // [rsp+20h] [rbp-89h]
  int v33; // [rsp+40h] [rbp-69h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v34; // [rsp+48h] [rbp-61h]
  Scaleform::GFx::AS3::Value v35; // [rsp+50h] [rbp-59h]
  int v36; // [rsp+70h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v37; // [rsp+78h] [rbp-31h]
  Scaleform::GFx::AS3::Value v38; // [rsp+80h] [rbp-29h]
  Scaleform::GFx::AS3::Value v39; // [rsp+A0h] [rbp-9h]
  __int64 v40; // [rsp+C0h] [rbp+17h]
  Scaleform::GFx::ASString v41; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::ASString v42; // [rsp+120h] [rbp+77h]
  Scaleform::GFx::ASString resulta; // [rsp+128h] [rbp+7Fh]

  v40 = -2i64;
  v3 = this;
  v4 = value->value.VNumber;
  v5 = this->pTraits.pObject->pVM->StringManagerRef;
  v6 = 10;
  v7 = 10;
  v32.Flags = 10;
  v32.Bonus.pWeakProxy = 0i64;
  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
         &resulta,
         "code")->pNode;
  *(_QWORD *)&v32.value.VNumber = v8;
  if ( v8 == &v8->pManager->NullStringNode )
  {
    v8 = 0i64;
    v32.value.VNumber = 0.0;
    v9.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v32.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v7 = 12;
    v32.Flags = 12;
  }
  else
  {
    ++v8->RefCount;
    v9.VObj = (Scaleform::GFx::AS3::Object *)v32.value.VS._2;
  }
  v10 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pTraits.pObject->pVM->PublicNamespace.pObject;
  v33 = 0;
  v34.pObject = v10;
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
  v35.Flags = 0;
  v35.Bonus.pWeakProxy = 0i64;
  v11 = v7 & 0x1F;
  if ( (unsigned int)(v11 - 12) <= 3
    && v8
    && (v12 = v8[1].pData, *((_DWORD *)v12 + 30) == 17)
    && ~((const unsigned __int8)v12[112] >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v35, (Scaleform::GFx::ASString *)&v8[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v34,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v8[1].RefCount);
    v33 &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+100h+var_E0.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v35.Flags = *(_QWORD *)&v32.Flags;
    v35.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v35.value.VNumber = v8;
    v35.value.VS._2 = v9;
    if ( v11 > 9 )
    {
      if ( (v7 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v11 == 10 )
      {
        ++v8->RefCount;
      }
      else if ( v11 > 10 )
      {
        if ( v11 <= 15 )
        {
          if ( v8 )
            v8->Size = (v8->Size + 1) & 0x8FBFFFFF;
        }
        else if ( v11 <= 17 && v9.VObj )
        {
          v9.VObj->RefCount = (v9.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
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
          v15 = v42.pNode->RefCount == 1;
          --v14->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        }
      }
      v16 = v41.pNode;
      v15 = v41.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
  }
  if ( v11 > 9 )
  {
    if ( (v7 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags = v7 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v17 = resulta.pNode;
  v15 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Builtins,
                         &resulta,
                         "level");
  v32.Flags = 10;
  v32.Bonus.pWeakProxy = 0i64;
  v19 = *v18;
  v32.value.VNumber = v19;
  if ( *(_QWORD *)&v19 == *(_QWORD *)(*(_QWORD *)&v19 + 8i64) + 104i64 )
  {
    v19 = 0.0;
    v32.value.VNumber = 0.0;
    v20.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v32.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v32.Bonus.pWeakProxy;
    v6 = 12;
    v32.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v19 + 24i64);
    v20.VObj = (Scaleform::GFx::AS3::Object *)v32.value.VS._2;
  }
  v21 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pTraits.pObject->pVM->PublicNamespace.pObject;
  v36 = 0;
  v37.pObject = v21;
  if ( v21 )
    v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
  v38.Flags = 0;
  v38.Bonus.pWeakProxy = 0i64;
  v22 = v6 & 0x1F;
  if ( (unsigned int)(v22 - 12) <= 3
    && v19 != 0.0
    && (v23 = *(_QWORD *)(*(_QWORD *)&v19 + 40i64), *(_DWORD *)(v23 + 120) == 17)
    && ~(*(_BYTE *)(v23 + 112) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v38, (Scaleform::GFx::ASString *)(*(_QWORD *)&v19 + 56i64));
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v37,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v19 + 64i64));
    v36 &= 0xFFFFFFF9;
  }
  else
  {
    __asm { prefetcht1 byte ptr [rsp+100h+var_E0.Flags]; Prefetch to all cache levels }
    *(_QWORD *)&v38.Flags = *(_QWORD *)&v32.Flags;
    v38.Bonus.pWeakProxy = 0i64;
    v38.value.VNumber = v19;
    v38.value.VS._2 = v20;
    if ( v22 > 9 )
    {
      if ( (v6 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] + 1;
      }
      else if ( v22 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v19 + 24i64);
      }
      else if ( v22 > 10 )
      {
        if ( v22 <= 15 )
        {
          if ( v19 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v19 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v19 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v22 <= 17 && v20.VObj )
        {
          v20.VObj->RefCount = (v20.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
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
          v15 = v42.pNode->RefCount == 1;
          --v25->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        }
      }
      v26 = v41.pNode;
      v15 = v41.pNode->RefCount == 1;
      --v26->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    }
  }
  if ( v22 > 9 )
  {
    if ( (v6 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v32.Bonus.pWeakProxy = 0i64;
      v32.value = 0ui64;
      v32.Flags = v6 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
  v27 = resulta.pNode;
  v15 = resulta.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  v39.Flags = 0;
  v39.Bonus.pWeakProxy = 0i64;
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v4 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v4),
                   &v41,
                   &v33,
                   &v39) )
    Scaleform::GFx::AS3::Value::Convert2String(&v39, (Scaleform::GFx::AS3::CheckResult *)&v41, &v3->Code);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(long double, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))(**(_QWORD **)&v4 + 32i64))(
                   COERCE_LONG_DOUBLE(*(_QWORD *)&v4),
                   &v41,
                   &v36,
                   &v39) )
    Scaleform::GFx::AS3::Value::Convert2String(&v39, (Scaleform::GFx::AS3::CheckResult *)&v41, &v3->Level);
  if ( (v39.Flags & 0x1F) > 9 )
  {
    if ( (v39.Flags >> 9) & 1 )
    {
      v15 = v39.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v39.Bonus.pWeakProxy = 0i64;
      v39.value = 0ui64;
      v39.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v39);
    }
  }
  if ( (v38.Flags & 0x1F) > 9 )
  {
    if ( (v38.Flags >> 9) & 1 )
    {
      v15 = v38.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v38.Bonus.pWeakProxy = 0i64;
      v38.value = 0ui64;
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
    if ( (_QWORD)v37.pObject & 1 )
    {
      --v37.pObject;
    }
    else
    {
      v29 = v37.pObject->RefCount;
      if ( v29 & 0x3FFFFF )
      {
        v37.pObject->RefCount = v29 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v28->vfptr);
      }
    }
  }
  if ( (v35.Flags & 0x1F) > 9 )
  {
    if ( (v35.Flags >> 9) & 1 )
    {
      v15 = v35.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v35.Bonus.pWeakProxy = 0i64;
      v35.value = 0ui64;
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
    if ( (_QWORD)v34.pObject & 1 )
    {
      --v34.pObject;
    }
    else
    {
      v31 = v34.pObject->RefCount;
      if ( v31 & 0x3FFFFF )
      {
        v34.pObject->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v30->vfptr);
      }
    }
  }
}if ( v34.pObject )
  {
    if ( (_QWORD)v34.pObject & 1 )
    {
      --v34.pObject;
    }
    else
    {
      v31 = v34.pObject->RefCount;
      if ( v31 & 0x3FFFFF )
      {
        v34.pOb

// File Line: 87
// RVA: 0x865AD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *v3; // rdi
  Scaleform::GFx::AS3::StringManager *v4; // rbx
  const char *v5; // rax
  long double *v6; // rax
  long double v7; // rdx
  Scaleform::GFx::ASStringNode *v8; // rcx
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
  unsigned int v25; // ebx
  Scaleform::GFx::AS3::Value v26; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value argv; // [rsp+40h] [rbp-A8h]
  int v28; // [rsp+60h] [rbp-88h]
  __int64 v29; // [rsp+68h] [rbp-80h]
  __int128 v30; // [rsp+70h] [rbp-78h]
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
  Scaleform::GFx::ASString resulta; // [rsp+118h] [rbp+30h]

  v40 = -2i64;
  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM->StringManagerRef;
  v5 = (const char *)((__int64 (*)(void))this->vfptr[6].Finalize_GC)();
  v6 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
                        &resulta,
                        v5);
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v7 = *v6;
  argv.value.VNumber = *v6;
  if ( *(_QWORD *)v6 == *(_QWORD *)(*(_QWORD *)v6 + 8i64) + 104i64 )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)&v26.Flags;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v7 + 24i64);
  }
  v8 = resulta.pNode;
  v9 = resulta.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
          &resulta,
          "type");
  v28 = 10;
  v29 = 0i64;
  v11 = v10->pNode;
  *(Scaleform::GFx::ASString *)&v30 = (Scaleform::GFx::ASString)v10->pNode;
  if ( v10->pNode == &v10->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    v30 = *(_OWORD *)&v26.Flags;
    v28 = 12;
  }
  else
  {
    ++v11->RefCount;
  }
  v12 = resulta.pNode;
  v9 = resulta.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
          &resulta,
          "bubbles");
  LODWORD(v29) = 10;
  *(_QWORD *)&v30 = 0i64;
  v14 = v13->pNode;
  *((Scaleform::GFx::ASString *)&v30 + 1) = (Scaleform::GFx::ASString)v13->pNode;
  if ( v13->pNode == &v13->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v26.Flags = 0i64;
    *(__int128 *)((char *)&v30 + 8) = *(_OWORD *)&v26.Flags;
    LODWORD(v29) = 12;
  }
  else
  {
    ++v14->RefCount;
  }
  v15 = resulta.pNode;
  v9 = resulta.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
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
  v9 = resulta.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
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
  v9 = resulta.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  v22 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->Builtins,
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
  v9 = resulta.pNode->RefCount == 1;
  --v24->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  v26.Flags = 0;
  v26.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v3->vfptr,
    &v26,
    6u,
    &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v26, (Scaleform::GFx::AS3::CheckResult *)&resulta, v2);
  v25 = v26.Flags;
  if ( (v26.Flags & 0x1F) > 9 )
  {
    if ( (v26.Flags >> 9) & 1 )
    {
      v9 = v26.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v26.Bonus.pWeakProxy = 0i64;
      v26.value = 0ui64;
      v26.Flags = v25 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    }
  }
  `eh vector destructor iterator'(&argv, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
}

// File Line: 112
// RVA: 0x798AF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *v5; // rdi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]

  v3 = argv;
  v4 = argc;
  v5 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    argc,
    argv);
  if ( v4 >= 4 )
    Scaleform::GFx::AS3::Value::Convert2String(v3 + 3, &result, &v5->Code);
  if ( v4 >= 5 )
    Scaleform::GFx::AS3::Value::Convert2String(v3 + 4, &result, &v5->Level);
}

// File Line: 121
// RVA: 0x7B6410
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::Clone(Scaleform::GFx::AS3::Instances::fl_events::StatusEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::StatusEvent *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rbp
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  v5 = v3->Code.pNode;
  ++v5->RefCount;
  v6 = (Scaleform::GFx::ASStringNode *)v4[1].vfptr;
  v7 = v6->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v4[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v5;
  v8 = v3->Level.pNode;
  ++v8->RefCount;
  v9 = (Scaleform::GFx::ASStringNode *)v4[1]._pRCC;
  v7 = v9->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v4[1].pRCCRaw = (unsigned __int64)v8;
  return v2;
}

// File Line: 129
// RVA: 0x7E96B0
const char *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::GetEventName(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this)
{
  return "NetStatusEvent";
}

// File Line: 133
// RVA: 0x7E95C0
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent::GetEventClass(Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent *this)
{
  Scaleform::StringDataPtr gname; // [rsp+20h] [rbp-18h]

  gname.Size = 27i64;
  gname.pStr = "flash.events.NetStatusEvent";
  return Scaleform::GFx::AS3::VM::GetClass(
           this->pTraits.pObject->pVM,
           &gname,
           this->pTraits.pObject->pVM->CurrentDomain.pObject);
}

// File Line: 169
// RVA: 0x7FFD30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NetStatusEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 209
// RVA: 0x74F610
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::NetStatusEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::NetStatusEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::NetStatusEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::NetStatusEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::NetStatusEvent::`vftable';
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
                                       80i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::NetStatusEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"netStatus";
  }
  return v3;
}

