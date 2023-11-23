// File Line: 43
// RVA: 0x8972C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::IMEConversionMode(
        Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::`vftable;
  this->ALPHANUMERIC_FULL = "ALPHANUMERIC_FULL";
  this->ALPHANUMERIC_HALF = "ALPHANUMERIC_HALF";
  this->CHINESE = "CHINESE";
  this->JAPANESE_HIRAGANA = "JAPANESE_HIRAGANA";
  this->JAPANESE_KATAKANA_FULL = "JAPANESE_KATAKANA_FULL";
  this->JAPANESE_KATAKANA_HALF = "JAPANESE_KATAKANA_HALF";
  this->KOREAN = "KOREAN";
  this->UNKNOWN = "UNKNOWN";
}

// File Line: 76
// RVA: 0x8760D0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::IMEConversionMode::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *v10; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_system::IMEConversionModeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::IMEConversionMode::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v8,
      vm,
      &Scaleform::GFx::AS3::fl_system::IMEConversionModeCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *)MHeap->vfptr->Alloc(MHeap, 136ui64, 0i64);
  if ( v10 )
    Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::IMEConversionMode(v10, result->pV);
  return result;
}

