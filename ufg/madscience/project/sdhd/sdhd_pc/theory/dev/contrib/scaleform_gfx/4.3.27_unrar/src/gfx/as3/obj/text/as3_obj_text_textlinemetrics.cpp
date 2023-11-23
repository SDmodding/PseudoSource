// File Line: 51
// RVA: 0x8AEBF0
void __fastcall Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF

  if ( argc )
  {
    Scaleform::GFx::AS3::Value::Convert2Number(argv, &result, &this->ascent);
    if ( argc >= 2 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &result, &this->descent);
    if ( argc >= 3 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 2, &result, &this->height);
    if ( argc >= 4 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 3, &result, &this->leading);
    if ( argc >= 5 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 4, &result, &this->width);
    if ( argc >= 6 )
      Scaleform::GFx::AS3::Value::Convert2Number(argv + 5, &result, &this->x);
  }
}

// File Line: 87
// RVA: 0x8EB060
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::TextLineMetrics> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 109
// RVA: 0x873830
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_text::TextLineMetrics::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_text::TextLineMetricsCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_text::TextLineMetrics::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_text::TextLineMetricsCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_text::TextLineMetrics::`vftable;
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
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

