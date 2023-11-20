// File Line: 35
// RVA: 0x1589920
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent_0_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CA20 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,0,long>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *, int *))Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::errorIDGet;
  return result;
}

// File Line: 36
// RVA: 0x15898C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent_1_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CA30 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 37
// RVA: 0x15898F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent_2_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CA40 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent,2,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::toString;
  return result;
}

// File Line: 51
// RVA: 0x838890
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::errorIDGet(Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent *this, unsigned int *result)
{
  *result = this->EvtId.KeyCode;
}

// File Line: 63
// RVA: 0x862730
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *v3; // rdi
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
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rdx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // ebx
  Scaleform::GFx::AS3::Value::VU v28; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value v29; // [rsp+30h] [rbp-B8h]
  Scaleform::GFx::AS3::Value argv; // [rsp+50h] [rbp-98h]
  int v31; // [rsp+70h] [rbp-78h]
  __int64 v32; // [rsp+78h] [rbp-70h]
  __int64 v33; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS3::Value::VU v34; // [rsp+88h] [rbp-60h]
  int v35; // [rsp+98h] [rbp-50h]
  __int64 v36; // [rsp+A0h] [rbp-48h]
  Scaleform::GFx::AS3::Value::VU v37; // [rsp+A8h] [rbp-40h]
  int v38; // [rsp+B8h] [rbp-30h]
  __int64 v39; // [rsp+C0h] [rbp-28h]
  Scaleform::GFx::AS3::Value::VU v40; // [rsp+C8h] [rbp-20h]
  int v41; // [rsp+D8h] [rbp-10h]
  __int64 v42; // [rsp+E0h] [rbp-8h]
  Scaleform::GFx::AS3::Value::VU v43; // [rsp+E8h] [rbp+0h]
  int v44; // [rsp+F8h] [rbp+10h]
  __int64 v45; // [rsp+100h] [rbp+18h]
  Scaleform::GFx::AS3::Value::VU v46; // [rsp+108h] [rbp+20h]
  __int64 v47; // [rsp+118h] [rbp+30h]
  Scaleform::GFx::ASString resulta; // [rsp+148h] [rbp+60h]

  v47 = -2i64;
  v2 = result;
  v3 = this;
  v29.Flags = 0;
  v29.Bonus.pWeakProxy = 0i64;
  v4 = this->pTraits.pObject->pVM;
  v5 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
                        &resulta,
                        "ErrorEvent");
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v6 = *v5;
  argv.value.VNumber = *v5;
  if ( *(_QWORD *)v5 == *(_QWORD *)(*(_QWORD *)v5 + 8i64) + 104i64 )
  {
    v28.VNumber = 0.0;
    argv.value = v28;
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
  v31 = 10;
  v32 = 0i64;
  v10.VObj = v9->VObj;
  argv.value.VS._2 = (Scaleform::GFx::AS3::Value::V2U)v9->VObj;
  if ( v9->VObj == (Scaleform::GFx::AS3::Object *)(v9->VObj->pRCCRaw + 104) )
  {
    v28.VNumber = 0.0;
    *(Scaleform::GFx::AS3::Value::VU *)((char *)&argv.value + 8) = v28;
    v31 = 12;
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
  LODWORD(v32) = 10;
  v33 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v34.VNumber = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    v28.VNumber = 0.0;
    v34 = v28;
    LODWORD(v32) = 12;
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
  v35 = 10;
  v36 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v37.VNumber = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    v28.VNumber = 0.0;
    v37 = v28;
    v35 = 12;
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
  v38 = 10;
  v39 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v40.VNumber = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    v28.VNumber = 0.0;
    v40 = v28;
    v38 = 12;
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
  v41 = 10;
  v42 = 0i64;
  v22 = v21->pNode;
  *(Scaleform::GFx::ASString *)&v43.VNumber = (Scaleform::GFx::ASString)v21->pNode;
  if ( v21->pNode == &v21->pNode->pManager->NullStringNode )
  {
    v28.VNumber = 0.0;
    v43 = v28;
    v41 = 12;
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
  v24 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v4->StringManagerRef->Builtins,
          &resulta,
          "errorID");
  v44 = 10;
  v45 = 0i64;
  v25 = v24->pNode;
  *(Scaleform::GFx::ASString *)&v46.VNumber = (Scaleform::GFx::ASString)v24->pNode;
  if ( v24->pNode == &v24->pNode->pManager->NullStringNode )
  {
    v28.VNumber = 0.0;
    v46 = v28;
    v44 = 12;
  }
  else
  {
    ++v25->RefCount;
  }
  v26 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v26->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v3->vfptr,
    &v29,
    7u,
    &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v29, (Scaleform::GFx::AS3::CheckResult *)&resulta, v2);
  `eh vector destructor iterator'(&argv, 0x20ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  v27 = v29.Flags;
  if ( (v29.Flags & 0x1F) > 9 )
  {
    if ( (v29.Flags >> 9) & 1 )
    {
      v8 = v29.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v29.Bonus.pWeakProxy = 0i64;
      v29.value = 0ui64;
      v29.Flags = v27 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
    }
  }
}

// File Line: 89
// RVA: 0x7967E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *v5; // rsi
  int v6; // edx

  v3 = argv;
  v4 = argc;
  v5 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    argc,
    argv);
  if ( v4 >= 4 )
  {
    if ( (v6 = v3[3].Flags & 0x1F, (unsigned int)(v6 - 12) > 3) && v6 != 10 || *(_QWORD *)&v3[3].value.VNumber )
    {
      if ( (unsigned int)(v6 - 2) <= 1 )
        v5->errorID = v3[3].value.VS._1.VInt;
    }
  }
}

// File Line: 101
// RVA: 0x7B4D50
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::Clone(Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent *v3; // rbx

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)&this->vfptr,
    result);
  LODWORD(v2->pObject[1]._pRCC) = v3->errorID;
  return v2;
}

// File Line: 136
// RVA: 0x7FF4C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 176
// RVA: 0x744710
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::ErrorEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::ErrorEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::ErrorEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::ErrorEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::ErrorEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"error";
  }
  return v3;
}

