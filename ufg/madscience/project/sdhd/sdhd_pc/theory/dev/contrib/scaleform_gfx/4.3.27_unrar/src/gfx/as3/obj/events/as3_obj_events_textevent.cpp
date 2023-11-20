// File Line: 36
// RVA: 0x158DBE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TextEvent_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D160 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,0,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_events::TextEvent::textGet;
  return result;
}

// File Line: 37
// RVA: 0x15934C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::TextEvent_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D170 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_events::TextEvent::textSet;
  return result;
}

// File Line: 38
// RVA: 0x158DB80
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TextEvent_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D180 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 39
// RVA: 0x158DBB0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TextEvent_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D190 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::TextEvent::toString;
  return result;
}

// File Line: 48
// RVA: 0x782650
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v2; // rbx

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
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::TextEvent::`vftable';
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &v2->Text);
}

// File Line: 75
// RVA: 0x867B90
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v3; // rdi
  Scaleform::GFx::AS3::VM *v4; // rbx
  long double *v5; // rax
  long double v6; // rdx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::Value::V2U *v9; // rax
  Scaleform::GFx::AS3::Value::V2U v10; // rdx
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
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rdx
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int v24; // ebx
  Scaleform::GFx::AS3::Value::VU v25; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value v26; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS3::Value argv; // [rsp+50h] [rbp-98h]
  int v28; // [rsp+70h] [rbp-78h]
  __int64 v29; // [rsp+78h] [rbp-70h]
  __int64 v30; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::Value::VU v31; // [rsp+88h] [rbp-60h]
  int v32; // [rsp+98h] [rbp-50h]
  __int64 v33; // [rsp+A0h] [rbp-48h]
  Scaleform::GFx::AS3::Value::VU v34; // [rsp+A8h] [rbp-40h]
  int v35; // [rsp+B8h] [rbp-30h]
  __int64 v36; // [rsp+C0h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v37; // [rsp+C8h] [rbp-20h]
  int v38; // [rsp+D8h] [rbp-10h]
  __int64 v39; // [rsp+E0h] [rbp-8h]
  Scaleform::GFx::AS3::Value::VU v40; // [rsp+E8h] [rbp+0h]
  __int64 v41; // [rsp+F8h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+128h] [rbp+40h]

  v41 = -2i64;
  v2 = result;
  v3 = this;
  v26.Flags = 0;
  v26.Bonus.pWeakProxy = 0i64;
  v4 = this->pTraits.pObject->pVM;
  v5 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                        &resulta,
                        "TextEvent");
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v6 = *v5;
  argv.value.VNumber = *v5;
  if ( *(_QWORD *)v5 == *(_QWORD *)(*(_QWORD *)v5 + 8i64) + 104i64 )
  {
    v25.VNumber = 0.0;
    argv.value = v25;
    argv.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
  }
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = (Scaleform::GFx::AS3::Value::V2U *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                                            &resulta,
                                            "type");
  v28 = 10;
  v29 = 0i64;
  v10.VObj = v9->VObj;
  argv.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)v9->VObj;
  if ( v9->VObj == (Scaleform::GFx::AS3::Object *)(v9->VObj->pRCCRaw + 104) )
  {
    v25.VNumber = 0.0;
    *(Scaleform::GFx::AS3::Value::VU *)((char *)&argv.value + 8) = v25;
    v28 = 12;
  }
  else
  {
    ++LODWORD(v10.VObj->pPrev);
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
  LODWORD(v29) = 10;
  v30 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v31.VNumber = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    v25.VNumber = 0.0;
    v31 = v25;
    LODWORD(v29) = 12;
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
  v32 = 10;
  v33 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v34.VNumber = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    v25.VNumber = 0.0;
    v34 = v25;
    v32 = 12;
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
          "eventPhase");
  v35 = 10;
  v36 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v37.VNumber = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    v25.VNumber = 0.0;
    v37 = v25;
    v35 = 12;
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
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &resulta,
          "text");
  v38 = 10;
  v39 = 0i64;
  v22 = v21->pNode;
  *(Scaleform::GFx::ASString *)&v40.VNumber = (Scaleform::GFx::ASString)v21->pNode;
  if ( v21->pNode == &v21->pNode->pManager->NullStringNode )
  {
    v25.VNumber = 0.0;
    v40 = v25;
    v38 = 12;
  }
  else
  {
    ++v22->RefCount;
  }
  v23 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v3->vfptr,
    &v26,
    6u,
    &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v26, (Scaleform::GFx::AS3::CheckResult *)&resulta, v2);
  `eh vector destructor iterator'(&argv, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  v24 = v26.Flags;
  if ( (v26.Flags & 0x1F) > 9 )
  {
    if ( (v26.Flags >> 9) & 1 )
    {
      v8 = v26.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v26.Bonus.pWeakProxy = 0i64;
      v26.value = 0ui64;
      v26.Flags = v24 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    }
  }
}

// File Line: 106
// RVA: 0x7B64A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::Clone(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  v5 = v3->Text.pNode;
  ++v5->RefCount;
  v6 = (Scaleform::GFx::ASStringNode *)v4[1].vfptr;
  v7 = v6->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v4[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v5;
  return v2;
}

// File Line: 117
// RVA: 0x81ECD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this, const wchar_t *pwstr)
{
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
         &result,
         pwstr,
         -1i64)->pNode;
  ++v3->RefCount;
  v4 = v2->Text.pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v2->Text.pNode = v3;
  v6 = result.pNode;
  v5 = result.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 151
// RVA: 0x8001B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 193
// RVA: 0x757820
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::TextEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::TextEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::TextEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"link";
    v10[1].pRCCRaw = (unsigned __int64)"textInput";
  }
  return v3;
}

