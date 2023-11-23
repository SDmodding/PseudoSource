// File Line: 47
// RVA: 0x797DB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  long double *p_alpha; // rsi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF

  p_alpha = &this->alpha;
  this->color = 0;
  this->alpha = 1.0;
  if ( argc )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &result, &this->color);
  if ( argc >= 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(argv + 1, &result, p_alpha);
}

// File Line: 89
// RVA: 0x7FF880
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 111
// RVA: 0x72C960
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsSolidFill::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::GraphicsSolidFillCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsSolidFill::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::GraphicsSolidFillCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::`vftable;
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

