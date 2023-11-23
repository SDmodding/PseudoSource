// File Line: 36
// RVA: 0x158D9D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,0,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::afterOrientationGet;
  return result;
}

// File Line: 37
// RVA: 0x158D940
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_1_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,1,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::beforeOrientationGet;
  return result;
}

// File Line: 38
// RVA: 0x158D970
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 39
// RVA: 0x158D9A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::toString;
  return result;
}

// File Line: 47
// RVA: 0x7822F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::StageOrientationEvent(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
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
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::`vftable;
  this->BeforeOrientation.Flags = 0;
  this->BeforeOrientation.Bonus.pWeakProxy = 0i64;
  this->AfterOrientation.Flags = 0;
  this->AfterOrientation.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Value::SetNull(&this->BeforeOrientation);
  Scaleform::GFx::AS3::Value::SetNull(&this->AfterOrientation);
}

// File Line: 55
// RVA: 0x82BBB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::afterOrientationGet(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int v3; // edx
  Scaleform::GFx::ASStringNode *VStr; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  v3 = this->AfterOrientation.Flags & 0x1F;
  if ( v3 - 12 > 3 && v3 != 10 || this->AfterOrientation.value.VS._1.VStr )
    VStr = this->AfterOrientation.value.VS._1.VStr;
  else
    VStr = &result->pNode->pManager->NullStringNode;
  ++VStr->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = VStr;
}

// File Line: 62
// RVA: 0x82D950
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::beforeOrientationGet(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::ASString *result)
{
  unsigned int v3; // edx
  Scaleform::GFx::ASStringNode *VStr; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  v3 = this->BeforeOrientation.Flags & 0x1F;
  if ( v3 - 12 > 3 && v3 != 10 || this->BeforeOrientation.value.VS._1.VStr )
    VStr = this->BeforeOrientation.value.VS._1.VStr;
  else
    VStr = &result->pNode->pManager->NullStringNode;
  ++VStr->RefCount;
  pNode = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = VStr;
}

// File Line: 76
// RVA: 0x8674B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
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
  unsigned int Flags; // ebx
  __int128 v25; // [rsp+20h] [rbp-C8h]
  Scaleform::GFx::AS3::Value v26; // [rsp+30h] [rbp-B8h] BYREF
  int argv; // [rsp+50h] [rbp-98h] BYREF
  __int64 argv_8; // [rsp+58h] [rbp-90h]
  _BYTE argv_16[24]; // [rsp+60h] [rbp-88h]
  __int64 v30; // [rsp+78h] [rbp-70h]
  __int64 v31; // [rsp+80h] [rbp-68h]
  __int128 v32; // [rsp+88h] [rbp-60h]
  int v33; // [rsp+98h] [rbp-50h]
  __int64 v34; // [rsp+A0h] [rbp-48h]
  __int128 v35; // [rsp+A8h] [rbp-40h]
  int v36; // [rsp+B8h] [rbp-30h]
  __int64 v37; // [rsp+C0h] [rbp-28h]
  __int128 v38; // [rsp+C8h] [rbp-20h]
  int v39; // [rsp+D8h] [rbp-10h]
  __int64 v40; // [rsp+E0h] [rbp-8h]
  __int128 v41; // [rsp+E8h] [rbp+0h]
  __int64 v42; // [rsp+F8h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+128h] [rbp+40h] BYREF

  v42 = -2i64;
  v26.Flags = 0;
  v26.Bonus.pWeakProxy = 0i64;
  pVM = this->pTraits.pObject->pVM;
  v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         pVM->StringManagerRef,
         &resulta,
         "StageOrientationEvent");
  argv = 10;
  argv_8 = 0i64;
  pNode = v5->pNode;
  *(Scaleform::GFx::ASString *)argv_16 = (Scaleform::GFx::ASString)v5->pNode;
  if ( v5->pNode == &v5->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    *(_OWORD *)argv_16 = v25;
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
  v30 = 0i64;
  v10 = v9->pNode;
  *(Scaleform::GFx::ASString *)&argv_16[8] = (Scaleform::GFx::ASString)v9->pNode;
  if ( v9->pNode == &v9->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    *(_OWORD *)&argv_16[8] = v25;
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
  LODWORD(v30) = 10;
  v31 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v32 = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    v32 = v25;
    LODWORD(v30) = 12;
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
  v33 = 10;
  v34 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v35 = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    v35 = v25;
    v33 = 12;
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
          "beforeOrientation");
  v36 = 10;
  v37 = 0i64;
  v19 = v18->pNode;
  *(Scaleform::GFx::ASString *)&v38 = (Scaleform::GFx::ASString)v18->pNode;
  if ( v18->pNode == &v18->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    v38 = v25;
    v36 = 12;
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
          "afterOrientation");
  v39 = 10;
  v40 = 0i64;
  v22 = v21->pNode;
  *(Scaleform::GFx::ASString *)&v41 = (Scaleform::GFx::ASString)v21->pNode;
  if ( v21->pNode == &v21->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v25 = 0i64;
    v41 = v25;
    v39 = 12;
  }
  else
  {
    ++v22->RefCount;
  }
  v23 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
    this,
    &v26,
    6u,
    (Scaleform::GFx::AS3::Value *const)&argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v26, (Scaleform::GFx::AS3::CheckResult *)&resulta, result);
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

// File Line: 103
// RVA: 0x7D6570
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_value; // rdx
  unsigned int v8; // ecx

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->CurrentTarget.pObject )
    op(prcc, &this->CurrentTarget.pObject);
  if ( this->Target.pObject )
    op(prcc, &this->Target.pObject);
  Flags = this->BeforeOrientation.Flags;
  if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 && (this->BeforeOrientation.Flags & 0x1F) >= 0xB )
  {
    if ( (this->BeforeOrientation.Flags & 0x1F) <= 0xF )
    {
      if ( this->BeforeOrientation.value.VS._1.VStr )
      {
        p_value = 0i64;
        if ( (this->BeforeOrientation.Flags & 0x1F) - 11 <= 4 )
          p_value = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->BeforeOrientation.value;
        goto LABEL_15;
      }
    }
    else if ( (this->BeforeOrientation.Flags & 0x1F) <= 0x11 )
    {
      p_value = &this->BeforeOrientation.value.VS._2.VObj;
      if ( this->BeforeOrientation.value.VS._2.VObj )
LABEL_15:
        op(prcc, p_value);
    }
  }
  v8 = this->AfterOrientation.Flags;
  if ( (v8 & 0x1F) > 0xA && (v8 & 0x200) == 0 && (this->AfterOrientation.Flags & 0x1F) >= 0xB )
  {
    if ( (this->AfterOrientation.Flags & 0x1F) <= 0xF )
    {
      if ( !this->AfterOrientation.value.VS._1.VStr )
        return;
      goto LABEL_24;
    }
    if ( (this->AfterOrientation.Flags & 0x1F) <= 0x11 && this->AfterOrientation.value.VS._2.VObj )
LABEL_24:
      ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *))op)(prcc);
  }
}

// File Line: 111
// RVA: 0x7994A0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // r14
  unsigned int v7; // edx
  unsigned int v8; // edx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  pVM = this->pTraits.pObject->pVM;
  if ( argc >= 4 )
  {
    if ( (Scaleform::GFx::AS3::Value::Assign(&this->BeforeOrientation, argv + 3), v7 = argv[3].Flags & 0x1F, v7 - 12 > 3)
      && v7 != 10
      || argv[3].value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::ToStringValue(&this->BeforeOrientation, &result, pVM->StringManagerRef);
    }
  }
  if ( argc >= 5 )
  {
    if ( (Scaleform::GFx::AS3::Value::Assign(&this->AfterOrientation, argv + 4), v8 = argv[3].Flags & 0x1F, v8 - 12 > 3)
      && v8 != 10
      || argv[3].value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::ToStringValue(&this->AfterOrientation, &result, pVM->StringManagerRef);
    }
  }
}

// File Line: 132
// RVA: 0x7E9620
Scaleform::GFx::AS3::Object *__fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this)
{
  return (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.Size;
}

// File Line: 137
// RVA: 0x7B63A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rbx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  Scaleform::GFx::AS3::Value::Assign(
    (Scaleform::GFx::AS3::Value *)&result->pObject[1].RefCount,
    &this->BeforeOrientation);
  Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&pObject[1].RefCount, &this->AfterOrientation);
  return result;
}

// File Line: 175
// RVA: 0x800150
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::StageOrientationEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::StageOrientationEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::StageOrientationEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::StageOrientationEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::StageOrientationEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 217
// RVA: 0x739990
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::StageOrientationEvent::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::StageOrientationEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::StageOrientationEvent::`vftable;
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
      &Scaleform::GFx::AS3::fl_events::StageOrientationEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::StageOrientationEvent::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::StageOrientationEvent::`vftable;
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"orientationChange";
    v10[1].pRCCRaw = (unsigned __int64)"orientationChanging";
  }
  return result;
}

