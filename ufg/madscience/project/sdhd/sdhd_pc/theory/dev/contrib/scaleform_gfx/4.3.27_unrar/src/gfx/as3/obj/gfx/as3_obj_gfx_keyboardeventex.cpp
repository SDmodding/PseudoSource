// File Line: 47
// RVA: 0x7E9560
Scaleform::GFx::AS3::ValueStack::Page *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx::GetEventClass(Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx *this)
{
  return this->pTraits.pObject->pVM[1].OpStack.pReserved;
}

// File Line: 52
// RVA: 0x7B6040
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx::Clone(Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // r8

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  LODWORD(v4[1].vfptr) = v3->EvtId.Id;
  HIDWORD(v4[1].vfptr) = v3->EvtId.WcharCode;
  LODWORD(v4[1]._pRCC) = v3->EvtId.KeyCode;
  BYTE4(v4[1].pRCCRaw) = v3->EvtId.AsciiCode;
  LOBYTE(v4[1].pNext) = v3->EvtId.RollOverCnt;
  BYTE1(v4[1].pNext) = v3->EvtId.ControllerIndex;
  BYTE2(v4[1].pNextRoot) = v3->EvtId.KeysState.States;
  BYTE3(v4[1].pNextRoot) = v3->EvtId.MouseWheelDelta;
  HIDWORD(v4[1].pNextRoot) = v3->KeyLocation;
  LODWORD(v4[1].pPrev) = v3->controllerIdx;
  return v2;
}

// File Line: 80
// RVA: 0x7FFAC0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::KeyboardEventEx> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 102
// RVA: 0x728550
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::KeyboardEventEx::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::KeyboardEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::KeyboardEvent::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::KeyboardEventEx::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::KeyboardEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::KeyboardEvent::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::KeyboardEventEx::`vftable';
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
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

