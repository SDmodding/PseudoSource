// File Line: 40
// RVA: 0x89A820
void __fastcall Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor::MouseCursor(Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor::`vftable;
  v2->ARROW = "arrow";
  v2->AUTO = "auto";
  v2->BUTTON = "button";
  v2->HAND = "hand";
  v2->IBEAM = "ibeam";
}

// File Line: 70
// RVA: 0x87A490
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::MouseCursor::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor *v10; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_ui::MouseCursorCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::MouseCursor::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, v2, &Scaleform::GFx::AS3::fl_ui::MouseCursorCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                                              v4,
                                                              112i64);
  if ( v10 )
    Scaleform::GFx::AS3::Classes::fl_ui::MouseCursor::MouseCursor(v10, v3->pV);
  return v3;
}

