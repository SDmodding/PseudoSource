// File Line: 35
// RVA: 0x1587D00
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Object___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D670 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>>::Method = Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::statusGet;
  return result;
}

// File Line: 36
// RVA: 0x1587CA0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent_1_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D680 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 37
// RVA: 0x1587CD0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent_2_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D690 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent,2,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::toString;
  return result;
}

// File Line: 45
// RVA: 0x77AB20
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AppLifecycleEvent(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v2; // rbx
  signed __int64 v3; // rcx

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
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::`vftable';
  v3 = (signed __int64)&v2->Status;
  *(_DWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0i64;
  Scaleform::GFx::AS3::Value::SetNull(&v2->Status);
}

// File Line: 52
// RVA: 0x860070
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::statusGet(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result)
{
  if ( (this->Status.Flags & 0x1F) - 12 <= 3 )
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->Status.value.VS._1.VStr);
}

// File Line: 59
// RVA: 0x830B60
void __fastcall Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList **v3; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v4; // rcx
  unsigned int v5; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = (Scaleform::GFx::AS3::Instances::fl::XMLList **)((__int64 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_events::TransformGestureEvent *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))this->vfptr[7].~RefCountBaseGC<328>)(
                                                         this,
                                                         &v6);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v2,
    *v3);
  v4 = v6;
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v6 - 1);
    }
    else
    {
      v5 = v6->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v6->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
      }
    }
  }
}

// File Line: 66
// RVA: 0x861750
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::Value::V2U *v5; // rax
  Scaleform::GFx::AS3::Value::V2U v6; // rdx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rdx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rdx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rdx
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int v21; // ebx
  __int128 v22; // [rsp+20h] [rbp-81h]
  Scaleform::GFx::AS3::Value argv; // [rsp+30h] [rbp-71h]
  int v24; // [rsp+58h] [rbp-49h]
  __int64 v25; // [rsp+60h] [rbp-41h]
  __int128 v26; // [rsp+68h] [rbp-39h]
  int v27; // [rsp+78h] [rbp-29h]
  __int64 v28; // [rsp+80h] [rbp-21h]
  __int128 v29; // [rsp+88h] [rbp-19h]
  int v30; // [rsp+98h] [rbp-9h]
  __int64 v31; // [rsp+A0h] [rbp-1h]
  __int128 v32; // [rsp+A8h] [rbp+7h]
  int v33; // [rsp+B8h] [rbp+17h]
  __int64 v34; // [rsp+C0h] [rbp+1Fh]
  __int128 v35; // [rsp+C8h] [rbp+27h]
  __int64 v36; // [rsp+D8h] [rbp+37h]
  Scaleform::GFx::ASString resulta; // [rsp+108h] [rbp+67h]

  v36 = -2i64;
  v2 = result;
  v3 = this;
  argv.Flags = 0;
  argv.Bonus.pWeakProxy = 0i64;
  v4 = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::AS3::Value::V2U *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                                            &resulta,
                                            "AppLifecycleEvent");
  LODWORD(argv.Bonus.pWeakProxy) = 10;
  argv.value.VNumber = 0.0;
  v6.VObj = v5->VObj;
  argv.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)v5->VObj;
  if ( v5->VObj == (Scaleform::GFx::AS3::Object *)(v5->VObj->pRCCRaw + 104) )
  {
    *(_QWORD *)&v22 = 0i64;
    *(_OWORD *)&argv.value.VS._2.VObj = v22;
    LODWORD(argv.Bonus.pWeakProxy) = 12;
  }
  else
  {
    ++LODWORD(v6.VObj->pPrev);
  }
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
         &resulta,
         "type");
  v24 = 10;
  v25 = 0i64;
  v10 = v9->pNode;
  *(Scaleform::GFx::ASString *)&v26 = (Scaleform::GFx::ASString)v9->pNode;
  if ( v9->pNode == &v9->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v22 = 0i64;
    v26 = v22;
    v24 = 12;
  }
  else
  {
    ++v10->RefCount;
  }
  v11 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &resulta,
          "bubbles");
  v27 = 10;
  v28 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v29 = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v22 = 0i64;
    v29 = v22;
    v27 = 12;
  }
  else
  {
    ++v13->RefCount;
  }
  v14 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &resulta,
          "cancelable");
  v30 = 10;
  v31 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v32 = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v22 = 0i64;
    v32 = v22;
    v30 = 12;
  }
  else
  {
    ++v16->RefCount;
  }
  v17 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &resulta,
          "status");
  v33 = 10;
  v34 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v35 = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v22 = 0i64;
    v35 = v22;
    v33 = 12;
  }
  else
  {
    ++v19->RefCount;
  }
  v20 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v3->vfptr,
    &argv,
    5u,
    (Scaleform::GFx::AS3::Value *)((char *)&argv + 8));
  Scaleform::GFx::AS3::Value::Convert2String(&argv, (Scaleform::GFx::AS3::CheckResult *)&resulta, v2);
  `eh vector destructor iterator'(
    &argv.Bonus,
    0x20ui64,
    5,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  v21 = argv.Flags;
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v8 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      argv.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&argv.Flags = v21 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
}

// File Line: 92
// RVA: 0x7D52E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v5; // rbx
  int v6; // eax
  signed __int64 v7; // rdx
  _QWORD *v8; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->CurrentTarget.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->CurrentTarget);
  if ( v5->Target.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->Target);
  v6 = v5->Status.Flags & 0x1F;
  if ( v6 > 10 && !((v5->Status.Flags >> 9) & 1) && v6 >= 11 )
  {
    if ( v6 <= 15 )
    {
      v8 = (_QWORD *)&v5->Status.value.VNumber;
      if ( !*v8 )
        return;
      v7 = 0i64;
      if ( (unsigned int)(v6 - 11) <= 4 )
        v7 = (signed __int64)v8;
      goto LABEL_15;
    }
    if ( v6 <= 17 )
    {
      v7 = (signed __int64)&v5->Status.value.VS._2.VObj;
      if ( v5->Status.value.VS._2.VObj )
      {
LABEL_15:
        v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v7);
        return;
      }
    }
  }
}

// File Line: 99
// RVA: 0x794C10
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v5; // rdi
  Scaleform::GFx::AS3::VM *v6; // rbp
  int v7; // edx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]

  v3 = argv;
  v4 = argc;
  v5 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    argc,
    argv);
  v6 = v5->pTraits.pObject->pVM;
  if ( v4 >= 4 )
  {
    if ( (Scaleform::GFx::AS3::Value::Assign(&v5->Status, v3 + 3), v7 = v3[3].Flags & 0x1F, (unsigned int)(v7 - 12) > 3)
      && v7 != 10
      || *(_QWORD *)&v3[3].value.VNumber )
    {
      Scaleform::GFx::AS3::Value::ToStringValue(&v5->Status, &result, v6->StringManagerRef);
    }
  }
}

// File Line: 112
// RVA: 0x7E9480
Scaleform::GFx::AS3::Object *__fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::GetEventClass(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this)
{
  return (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.Policy.Capacity;
}

// File Line: 117
// RVA: 0x7B4CF0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent::Clone(Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent *v3; // rbx

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&v2->pObject[1], &v3->Status);
  return v2;
}

// File Line: 152
// RVA: 0x7FF130
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::AppLifecycleEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 194
// RVA: 0x75F7B0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::AppLifecycleEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::AppLifecycleEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::AppLifecycleEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::AppLifecycleEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::AppLifecycleEvent::`vftable';
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
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::AppLifecycleEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"onPause";
    v10[1].pRCCRaw = (unsigned __int64)"onResume";
  }
  return v3;
}

