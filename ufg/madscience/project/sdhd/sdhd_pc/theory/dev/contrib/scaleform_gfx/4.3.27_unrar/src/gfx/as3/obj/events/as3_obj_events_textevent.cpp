// File Line: 36
// RVA: 0x158DBE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::TextEvent_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D160 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,0,Scaleform::GFx::ASString>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::ASString *))Scaleform::GFx::AS3::Instances::fl_events::TextEvent::textGet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::TextEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
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
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::TextEvent::`vftable;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &this->Text);
}

// File Line: 75
// RVA: 0x867B90
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::Value::V1U *v5; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
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
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rdx
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value::VU v25; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::Value v26; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+50h] [rbp-B0h] BYREF
  int v28; // [rsp+70h] [rbp-90h]
  __int64 v29; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::AS3::Value::VU v30; // [rsp+80h] [rbp-80h]
  int v31; // [rsp+90h] [rbp-70h]
  __int64 v32; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::AS3::Value::VU v33; // [rsp+A0h] [rbp-60h]
  int v34; // [rsp+B0h] [rbp-50h]
  __int64 v35; // [rsp+B8h] [rbp-48h]
  Scaleform::GFx::AS3::Value::VU v36; // [rsp+C0h] [rbp-40h]
  int v37; // [rsp+D0h] [rbp-30h]
  __int64 v38; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v39; // [rsp+E0h] [rbp-20h]
  int v40; // [rsp+F0h] [rbp-10h]
  __int64 v41; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::AS3::Value::VU v42; // [rsp+100h] [rbp+0h]
  __int64 v43; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::ASString v44; // [rsp+140h] [rbp+40h] BYREF

  v43 = -2i64;
  v26.Flags = 0;
  v26.Bonus.pWeakProxy = 0i64;
  pVM = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            pVM->StringManagerRef,
                                            &v44,
                                            "TextEvent");
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v6 = *v5;
  argv.value.VS._1 = *v5;
  if ( v5->VStr == &v5->VStr->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    argv.value = v25;
    argv.Flags = 12;
  }
  else
  {
    ++v6.VStr->RefCount;
  }
  pNode = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         pVM->StringManagerRef,
         &v44,
         "type");
  v28 = 10;
  v29 = 0i64;
  v10 = v9->pNode;
  *(Scaleform::GFx::ASString *)&v30.VNumber = (Scaleform::GFx::ASString)v9->pNode;
  if ( v9->pNode == &v9->pNode->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    v30 = v25;
    v28 = 12;
  }
  else
  {
    ++v10->RefCount;
  }
  v11 = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &v44,
          "bubbles");
  v31 = 10;
  v32 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v33.VNumber = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    v33 = v25;
    v31 = 12;
  }
  else
  {
    ++v13->RefCount;
  }
  v14 = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &v44,
          "cancelable");
  v34 = 10;
  v35 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v36.VNumber = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    v36 = v25;
    v34 = 12;
  }
  else
  {
    ++v16->RefCount;
  }
  v17 = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &v44,
          "eventPhase");
  v37 = 10;
  v38 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v39.VNumber = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    v39 = v25;
    v37 = 12;
  }
  else
  {
    ++v19->RefCount;
  }
  v20 = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &v44,
          "text");
  v40 = 10;
  v41 = 0i64;
  v22 = v21->pNode;
  *(Scaleform::GFx::ASString *)&v42.VNumber = (Scaleform::GFx::ASString)v21->pNode;
  if ( v21->pNode == &v21->pNode->pManager->NullStringNode )
  {
    v25.VS._1.VStr = 0i64;
    v42 = v25;
    v40 = 12;
  }
  else
  {
    ++v22->RefCount;
  }
  v23 = v44.pNode;
  v8 = v44.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &v26, 6u, &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v26, (Scaleform::GFx::AS3::CheckResult *)&v44, result);
  `eh vector destructor iterator(&argv, 0x20ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  Flags = v26.Flags;
  if ( (v26.Flags & 0x1F) > 9 )
  {
    if ( (v26.Flags & 0x200) != 0 )
    {
      v8 = v26.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v26.Bonus, 0, 24);
      v26.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    }
  }
}

// File Line: 106
// RVA: 0x7B64A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *vfptr; // rcx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Text.pNode;
  ++pNode->RefCount;
  vfptr = (Scaleform::GFx::ASStringNode *)pObject[1].vfptr;
  if ( vfptr->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(vfptr);
  pObject[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)pNode;
  return result;
}

// File Line: 117
// RVA: 0x81ECD0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        const wchar_t *pwstr)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *v7; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         pwstr,
         -1i64);
  pNode = v3->pNode;
  ++v3->pNode->RefCount;
  v5 = this->Text.pNode;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  this->Text.pNode = pNode;
  v7 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 151
// RVA: 0x8001B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 193
// RVA: 0x757820
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::TextEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_events::TextEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::`vftable;
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
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::TextEvent::`vftable;
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"link";
    v10[1].pRCCRaw = (unsigned __int64)"textInput";
  }
  return result;
}

