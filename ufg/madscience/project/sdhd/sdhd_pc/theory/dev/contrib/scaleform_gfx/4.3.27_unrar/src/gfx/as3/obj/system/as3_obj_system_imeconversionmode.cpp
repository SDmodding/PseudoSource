// File Line: 43
// RVA: 0x8972C0
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::IMEConversionMode(Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::`vftable';
  v2->ALPHANUMERIC_FULL = "ALPHANUMERIC_FULL";
  v2->ALPHANUMERIC_HALF = "ALPHANUMERIC_HALF";
  v2->CHINESE = "CHINESE";
  v2->JAPANESE_HIRAGANA = "JAPANESE_HIRAGANA";
  v2->JAPANESE_KATAKANA_FULL = "JAPANESE_KATAKANA_FULL";
  v2->JAPANESE_KATAKANA_HALF = "JAPANESE_KATAKANA_HALF";
  v2->KOREAN = "KOREAN";
  v2->UNKNOWN = "UNKNOWN";
}

// File Line: 76
// RVA: 0x8760D0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::IMEConversionMode::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *v10; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_system::IMEConversionModeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::IMEConversionMode::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v8,
      v2,
      &Scaleform::GFx::AS3::fl_system::IMEConversionModeCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode *)v4->vfptr->Alloc(v4, 136ui64, 0i64);
  if ( v10 )
    Scaleform::GFx::AS3::Classes::fl_system::IMEConversionMode::IMEConversionMode(v10, v3->pV);
  return v3;
}

