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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,2,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, long double *))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalGet;
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
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,3,Scaleform::GFx::AS3::Value const,double>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, Scaleform::GFx::AS3::Value *, long double))Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalSet;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::OutputProgressEvent(
        Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this,
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
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::`vftable;
  this->BytesPending = 0i64;
  this->BytesTotal = 0i64;
}

// File Line: 72
// RVA: 0x82E5E0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalGet(
        Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this,
        long double *result)
{
  signed __int64 BytesTotal; // rax
  double v3; // xmm0_8

  BytesTotal = this->BytesTotal;
  v3 = (double)(int)BytesTotal;
  if ( BytesTotal < 0 )
    v3 = v3 + 1.844674407370955e19;
  *result = v3;
}

// File Line: 78
// RVA: 0x82E630
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::bytesTotalSet(
        Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this,
        Scaleform::GFx::AS3::Value *result,
        long double value)
{
  unsigned __int64 v3; // rdx

  v3 = 0i64;
  if ( value >= 9.223372036854776e18 )
  {
    value = value - 9.223372036854776e18;
    if ( value < 9.223372036854776e18 )
      v3 = 0x8000000000000000ui64;
  }
  this->BytesTotal = v3 + (unsigned int)(int)value;
}

// File Line: 91
// RVA: 0x865E10
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdx
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
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rdx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rdx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int Flags; // ebx
  __int128 v28; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value v29; // [rsp+30h] [rbp-B8h] BYREF
  int argv; // [rsp+50h] [rbp-98h] BYREF
  __int64 argv_8; // [rsp+58h] [rbp-90h]
  _BYTE argv_16[24]; // [rsp+60h] [rbp-88h]
  __int64 v33; // [rsp+78h] [rbp-70h]
  __int64 v34; // [rsp+80h] [rbp-68h]
  __int128 v35; // [rsp+88h] [rbp-60h]
  int v36; // [rsp+98h] [rbp-50h]
  __int64 v37; // [rsp+A0h] [rbp-48h]
  __int128 v38; // [rsp+A8h] [rbp-40h]
  int v39; // [rsp+B8h] [rbp-30h]
  __int64 v40; // [rsp+C0h] [rbp-28h]
  __int128 v41; // [rsp+C8h] [rbp-20h]
  int v42; // [rsp+D8h] [rbp-10h]
  __int64 v43; // [rsp+E0h] [rbp-8h]
  __int128 v44; // [rsp+E8h] [rbp+0h]
  int v45; // [rsp+F8h] [rbp+10h]
  __int64 v46; // [rsp+100h] [rbp+18h]
  __int128 v47; // [rsp+108h] [rbp+20h]
  __int64 v48; // [rsp+118h] [rbp+30h]
  Scaleform::GFx::ASString resulta; // [rsp+148h] [rbp+60h] BYREF

  v48 = -2i64;
  v29.Flags = 0;
  v29.Bonus.pWeakProxy = 0i64;
  pVM = this->pTraits.pObject->pVM;
  v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         pVM->StringManagerRef,
         &resulta,
         "OutputProgressEvent");
  argv = 10;
  argv_8 = 0i64;
  pNode = v5->pNode;
  *(Scaleform::GFx::ASString *)argv_16 = (Scaleform::GFx::ASString)v5->pNode;
  if ( v5->pNode == &v5->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    *(_OWORD *)argv_16 = v28;
    argv = 12;
  }
  else
  {
    ++pNode->RefCount;
  }
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         pVM->StringManagerRef,
         &resulta,
         "type");
  *(_DWORD *)&argv_16[16] = 10;
  v33 = 0i64;
  v10 = v9->pNode;
  *(Scaleform::GFx::ASString *)&argv_16[8] = (Scaleform::GFx::ASString)v9->pNode;
  if ( v9->pNode == &v9->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    *(_OWORD *)&argv_16[8] = v28;
    *(_DWORD *)&argv_16[16] = 12;
  }
  else
  {
    ++v10->RefCount;
  }
  v11 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &resulta,
          "bubbles");
  LODWORD(v33) = 10;
  v34 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v35 = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    v35 = v28;
    LODWORD(v33) = 12;
  }
  else
  {
    ++v13->RefCount;
  }
  v14 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &resulta,
          "cancelable");
  v36 = 10;
  v37 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v38 = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    v38 = v28;
    v36 = 12;
  }
  else
  {
    ++v16->RefCount;
  }
  v17 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &resulta,
          "eventPhase");
  v39 = 10;
  v40 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v41 = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    v41 = v28;
    v39 = 12;
  }
  else
  {
    ++v19->RefCount;
  }
  v20 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &resulta,
          "bytesLoaded");
  v42 = 10;
  v43 = 0i64;
  v22 = v21->pNode;
  *(Scaleform::GFx::ASString *)&v44 = (Scaleform::GFx::ASString)v21->pNode;
  if ( v21->pNode == &v21->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    v44 = v28;
    v42 = 12;
  }
  else
  {
    ++v22->RefCount;
  }
  v23 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  v24 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          pVM->StringManagerRef,
          &resulta,
          "bytesTotal");
  v45 = 10;
  v46 = 0i64;
  v25 = v24->pNode;
  *(Scaleform::GFx::ASString *)&v47 = (Scaleform::GFx::ASString)v24->pNode;
  if ( v24->pNode == &v24->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v28 = 0i64;
    v47 = v28;
    v45 = 12;
  }
  else
  {
    ++v25->RefCount;
  }
  v26 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    this,
    &v29,
    7u,
    (Scaleform::GFx::AS3::Value *const)&argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v29, (Scaleform::GFx::AS3::CheckResult *)&resulta, result);
  `eh vector destructor iterator(&argv, 0x20ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  Flags = v29.Flags;
  if ( (v29.Flags & 0x1F) > 9 )
  {
    if ( (v29.Flags & 0x200) != 0 )
    {
      v8 = v29.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v29.Bonus, 0, 24);
      v29.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
    }
  }
}

// File Line: 127
// RVA: 0x7B62A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // r8

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pObject[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)this->BytesLoaded;
  pObject[1].pRCCRaw = this->BytesTotal;
  return result;
}

// File Line: 169
// RVA: 0x7FFD90
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::OutputProgressEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 209
// RVA: 0x7516A0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::OutputProgressEvent::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::OutputProgressEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::OutputProgressEvent::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_events::OutputProgressEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::OutputProgressEvent::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::OutputProgressEvent::`vftable;
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"outputProgress";
  }
  return result;
}

