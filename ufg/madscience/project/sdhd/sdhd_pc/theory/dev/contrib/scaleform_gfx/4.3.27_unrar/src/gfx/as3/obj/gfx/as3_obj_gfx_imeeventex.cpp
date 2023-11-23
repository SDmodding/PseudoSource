// File Line: 38
// RVA: 0x77ECA0
void __fastcall Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx::IMEEventEx(
        Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx *this,
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
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx::`vftable;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->message,
    this->pTraits.pObject->pVM->StringManagerRef);
}

// File Line: 65
// RVA: 0x7FF9D0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMEEventEx> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 86
// RVA: 0x77EC10
void __fastcall Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx::IMEEventEx(
        Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx::`vftable;
  this->SET_CURRENT_INPUT_LANGUAGE = "SetCurrentInputLanguage";
  this->SET_SUPPORTED_LANGUAGES = "SetSupportedLanguages";
  this->SET_SUPPORTED_IMENAMES = "SetSupportedIMENames";
  this->SET_IMENAME = "SetIMEName";
  this->SET_CURRENT_LANGUAGE = "SetCurrentLanguage";
  this->REMOVE_STATUS_WINDOW = "RemoveStatusWindow";
  this->DISPLAY_STATUS_WINDOW = "DisplayStatusWindow";
  this->SET_CONVERSION_STATUS = "SetConversionStatus";
}

// File Line: 119
// RVA: 0x73F300
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_gfx::IMEEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::IMEEventEx::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_gfx::IMEEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMEEventEx::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx *)MHeap->vfptr->Alloc(MHeap, 136ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_gfx::IMEEventEx::IMEEventEx(v9, result->pV);
  return result;
}

