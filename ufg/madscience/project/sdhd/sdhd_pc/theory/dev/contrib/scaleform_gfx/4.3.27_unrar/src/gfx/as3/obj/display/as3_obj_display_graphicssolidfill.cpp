// File Line: 47
// RVA: 0x797DB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  long double *v4; // rsi
  unsigned int v5; // edi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]

  v3 = argv;
  v4 = &this->alpha;
  v5 = argc;
  this->color = 0;
  this->alpha = 1.0;
  if ( argc >= 1 )
    Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &result, &this->color);
  if ( v5 >= 2 )
    Scaleform::GFx::AS3::Value::Convert2Number(v3 + 1, &result, v4);
}

// File Line: 89
// RVA: 0x7FF880
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 111
// RVA: 0x72C960
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsSolidFill::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::GraphicsSolidFillCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::GraphicsSolidFill::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::GraphicsSolidFillCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::`vftable';
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

