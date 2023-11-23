// File Line: 36
// RVA: 0x158AD90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CD50 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,0,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::textGet;
  return result;
}

// File Line: 37
// RVA: 0x15916F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CD60 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLRequest::contentTypeSet;
  return result;
}

// File Line: 38
// RVA: 0x158AD30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_events::Event___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CD70 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *))Scaleform::GFx::AS3::Instances::fl_gfx::GamePadAnalogEvent::clone;
  return result;
}

// File Line: 39
// RVA: 0x158AD60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243CD80 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::toString;
  return result;
}

// File Line: 75
// RVA: 0x864330
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::toString(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
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
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value::VU v19; // [rsp+8h] [rbp-79h]
  __int128 v20; // [rsp+8h] [rbp-79h]
  __int128 v21; // [rsp+8h] [rbp-79h]
  __int128 v22; // [rsp+8h] [rbp-79h]
  Scaleform::GFx::AS3::Value v23; // [rsp+18h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+38h] [rbp-49h] BYREF
  int v25; // [rsp+58h] [rbp-29h]
  __int64 v26; // [rsp+60h] [rbp-21h]
  __int128 v27; // [rsp+68h] [rbp-19h]
  int v28; // [rsp+78h] [rbp-9h]
  __int64 v29; // [rsp+80h] [rbp-1h]
  __int128 v30; // [rsp+88h] [rbp+7h]
  int v31; // [rsp+98h] [rbp+17h]
  __int64 v32; // [rsp+A0h] [rbp+1Fh]
  __int128 v33; // [rsp+A8h] [rbp+27h]
  __int64 v34; // [rsp+B8h] [rbp+37h]
  Scaleform::GFx::ASString resulta; // [rsp+E8h] [rbp+67h] BYREF

  v34 = -2i64;
  v23.Flags = 0;
  v23.Bonus.pWeakProxy = 0i64;
  pVM = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                            pVM->StringManagerRef,
                                            &resulta,
                                            "IOErrorEvent");
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  v6 = *v5;
  argv.value.VS._1 = *v5;
  if ( v5->VStr == &v5->VStr->pManager->NullStringNode )
  {
    v19.VS._1.VStr = 0i64;
    argv.value = v19;
    argv.Flags = 12;
  }
  else
  {
    ++v6.VStr->RefCount;
  }
  pNode = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         pVM->StringManagerRef,
         &resulta,
         "type");
  v25 = 10;
  v26 = 0i64;
  v10 = v9->pNode;
  *(Scaleform::GFx::ASString *)&v27 = (Scaleform::GFx::ASString)v9->pNode;
  if ( v9->pNode == &v9->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v20 = 0i64;
    v27 = v20;
    v25 = 12;
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
  v28 = 10;
  v29 = 0i64;
  v13 = v12->pNode;
  *(Scaleform::GFx::ASString *)&v30 = (Scaleform::GFx::ASString)v12->pNode;
  if ( v12->pNode == &v12->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v21 = 0i64;
    v30 = v21;
    v28 = 12;
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
          "text");
  v31 = 10;
  v32 = 0i64;
  v16 = v15->pNode;
  *(Scaleform::GFx::ASString *)&v33 = (Scaleform::GFx::ASString)v15->pNode;
  if ( v15->pNode == &v15->pNode->pManager->NullStringNode )
  {
    *(_QWORD *)&v22 = 0i64;
    v33 = v22;
    v31 = 12;
  }
  else
  {
    ++v16->RefCount;
  }
  v17 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(this, &v23, 4u, &argv);
  Scaleform::GFx::AS3::Value::Convert2String(&v23, (Scaleform::GFx::AS3::CheckResult *)&resulta, result);
  `eh vector destructor iterator(&argv, 0x20ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  Flags = v23.Flags;
  if ( (v23.Flags & 0x1F) > 9 )
  {
    if ( (v23.Flags & 0x200) != 0 )
    {
      v8 = v23.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v23.Bonus, 0, 24);
      v23.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v23);
    }
  }
}

// File Line: 99
// RVA: 0x7E9500
Scaleform::GFx::AS3::Class *__fastcall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::GetEventClass(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this)
{
  Scaleform::StringDataPtr gname; // [rsp+20h] [rbp-18h] BYREF

  gname.Size = 25i64;
  gname.pStr = "flash.events.IOErrorEvent";
  return Scaleform::GFx::AS3::VM::GetClass(
           this->pTraits.pObject->pVM,
           &gname,
           this->pTraits.pObject->pVM->CurrentDomain.pObject);
}

// File Line: 107
// RVA: 0x7B5F40
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::Clone(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl_events::Event *pObject; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *pNext; // rcx

  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(this, result);
  pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)result->pObject;
  pNode = this->Text.pNode;
  ++pNode->RefCount;
  pNext = (Scaleform::GFx::ASStringNode *)pObject[1].pNext;
  if ( pNext->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNext);
  pObject[1].pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pNode;
  return result;
}

// File Line: 114
// RVA: 0x7981F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::Event::AS3Constructor(this, argc, argv);
  if ( argc >= 4 )
    Scaleform::GFx::AS3::Value::Convert2String(argv + 3, &result, &this->Text);
}

// File Line: 152
// RVA: 0x7FFA00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 192
// RVA: 0x74B850
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::IOErrorEvent::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::IOErrorEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::ErrorEvent::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::IOErrorEvent::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_events::IOErrorEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::ErrorEvent::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::IOErrorEvent::`vftable;
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"ioError";
  }
  return result;
}

