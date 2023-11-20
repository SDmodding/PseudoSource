// File Line: 38
// RVA: 0x158C080
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_0_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B650 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,0,double>::Method = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedGet;
  return result;
}

// File Line: 39
// RVA: 0x1592290
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_1_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B660 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,1,Scaleform::GFx::AS3::Value const,double>::Method = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedSet;
  return result;
}

// File Line: 40
// RVA: 0x158BFF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_2_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B670 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,2,double>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, long double *))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalGet;
  return result;
}

// File Line: 41
// RVA: 0x15922C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_3_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B680 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,3,Scaleform::GFx::AS3::Value const,double>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalSet;
  return result;
}

// File Line: 42
// RVA: 0x158C020
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B690 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 43
// RVA: 0x158C050
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent_5_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B6A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,5,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::toString;
  return result;
}

// File Line: 53
// RVA: 0x780F60
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::OutputProgressEvent(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *v2; // rbx

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
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::`vftable';
  v2->BytesPending = 0i64;
  v2->BytesTotal = 0i64;
}

// File Line: 72
// RVA: 0x82E5E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalGet(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, long double *result)
{
  signed __int64 v2; // rax
  double v3; // xmm0_8

  v2 = this->BytesTotal;
  v3 = (double)(signed int)v2;
  if ( v2 < 0 )
    v3 = v3 + 1.844674407370955e19;
  *result = v3;
}

// File Line: 78
// RVA: 0x82E630
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalSet(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, Scaleform::GFx::AS3::Value *result, long double value)
{
  signed __int64 v3; // rdx

  v3 = 0i64;
  if ( value >= 9.223372036854776e18 )
  {
    value = value - 9.223372036854776e18;
    if ( value < 9.223372036854776e18 )
      v3 = 0x8000000000000000i64;
  }
  this->BytesTotal = v3 + (unsigned int)(signed int)value;
}

// File Line: 91
// RVA: 0x865E10
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *v3; // rdi
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
                        "OutputProgressEvent");
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
          "bytesLoaded");
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
          "bytesTotal");
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

// File Line: 127
// RVA: 0x7B62A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::Clone(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // r8

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  v4[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v3->BytesLoaded;
  v4[1].pRCCRaw = v3->BytesTotal;
  return v2;
}

// File Line: 169
// RVA: 0x7FFD90
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 209
// RVA: 0x7516A0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::OutputProgressEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::OutputProgressEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::OutputProgressEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_events::OutputProgressEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::OutputProgressEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"outputProgress";
  }
  return v3;
}

