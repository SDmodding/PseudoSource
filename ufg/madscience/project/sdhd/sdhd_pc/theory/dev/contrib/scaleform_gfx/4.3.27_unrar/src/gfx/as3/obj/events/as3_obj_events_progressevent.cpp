// File Line: 38
// RVA: 0x158C3B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_0_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,0,double>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, long double *))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedGet;
  return result;
}

// File Line: 39
// RVA: 0x15924A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_1_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,1,Scaleform::GFx::AS3::Value const,double>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedSet;
  return result;
}

// File Line: 40
// RVA: 0x158C320
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_2_double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,2,double>::Method = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalGet;
  return result;
}

// File Line: 41
// RVA: 0x15924D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_3_Scaleform::GFx::AS3::Value_const__double_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,3,Scaleform::GFx::AS3::Value const,double>::Method = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalSet;
  return result;
}

// File Line: 42
// RVA: 0x158C350
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 43
// RVA: 0x158C380
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent_5_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D0F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent,5,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::toString;
  return result;
}

// File Line: 51
// RVA: 0x7815D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::ProgressEvent(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v2; // rbx

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
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::`vftable';
  v2->BytesTotal = 0i64;
  v2->BytesLoaded = 0i64;
}

// File Line: 58
// RVA: 0x82E4F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedGet(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this, long double *result)
{
  signed __int64 v2; // rax
  double v3; // xmm0_8

  v2 = this->BytesPending;
  v3 = (double)(signed int)v2;
  if ( v2 < 0 )
    v3 = v3 + 1.844674407370955e19;
  *result = v3;
}

// File Line: 65
// RVA: 0x82E540
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesLoadedSet(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this, Scaleform::GFx::AS3::Value *result, long double value)
{
  signed __int64 v3; // rdx

  v3 = 0i64;
  if ( value >= 9.223372036854776e18 )
  {
    value = value - 9.223372036854776e18;
    if ( value < 9.223372036854776e18 )
      v3 = 0x8000000000000000i64;
  }
  this->BytesPending = v3 + (unsigned int)(signed int)value;
}

// File Line: 93
// RVA: 0x866B60
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::toString(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v3; // rdi
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
                        "ProgressEvent");
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

// File Line: 120
// RVA: 0x7E9600
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::GetEventClass(Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this)
{
  return this->pTraits.pObject->pVM[1].ScopeStack.Data.Data;
}

// File Line: 167
// RVA: 0x7FFE50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::ProgressEvent::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_events::ProgressEvent *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_events::ProgressEvent::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_events::ProgressEvent *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 209
// RVA: 0x73B380
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::ProgressEvent::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_events::ProgressEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::ProgressEvent::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_events::ProgressEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::ProgressEvent::`vftable';
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::ProgressEvent::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"progress";
    v10[1].pRCCRaw = (unsigned __int64)"socketData";
  }
  return v3;
}

