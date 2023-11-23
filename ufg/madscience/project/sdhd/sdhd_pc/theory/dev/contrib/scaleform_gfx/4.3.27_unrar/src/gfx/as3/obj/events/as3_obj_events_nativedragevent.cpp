// File Line: 82
// RVA: 0x7FFCA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 102
// RVA: 0x780BA0
void __fastcall Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent::NativeDragEvent(
        Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent::`vftable;
  this->NATIVE_DRAG_COMPLETE = "nativeDragComplete";
  this->NATIVE_DRAG_DROP = "nativeDragDrop";
  this->NATIVE_DRAG_ENTER = "nativeDragEnter";
  this->NATIVE_DRAG_EXIT = "nativeDragExit";
  this->NATIVE_DRAG_OVER = "nativeDragOver";
  this->NATIVE_DRAG_START = "nativeDragStart";
  this->NATIVE_DRAG_UPDATE = "nativeDragUpdate";
}

// File Line: 134
// RVA: 0x727810
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_events::NativeDragEvent::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_events::NativeDragEventCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::MouseEvent::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::NativeDragEvent::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_events::NativeDragEventCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::MouseEvent::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent *)MHeap->vfptr->Alloc(MHeap, 128ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_events::NativeDragEvent::NativeDragEvent(v9, result->pV);
  return result;
}

