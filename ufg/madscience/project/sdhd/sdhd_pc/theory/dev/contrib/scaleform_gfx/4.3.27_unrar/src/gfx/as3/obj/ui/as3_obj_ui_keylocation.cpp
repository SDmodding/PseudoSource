// File Line: 68
// RVA: 0x8741E0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::KeyLocation::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::Class *v8; // rax
  Scaleform::GFx::AS3::Class *v9; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_ui::KeyLocationCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::KeyLocation::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v7 )
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_ui::KeyLocationCI);
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v7);
  v8 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       88i64);
  v9 = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Class::Class(v8, v3->pV);
    v9->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_ui::KeyLocation::`vftable';
    LODWORD(v9[1].vfptr) = 1;
    HIDWORD(v9[1].vfptr) = 3;
    v9[1].pRCCRaw = 2i64;
  }
  return v3;
}

