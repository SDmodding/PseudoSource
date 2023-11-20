// File Line: 34
// RVA: 0x1598410
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_text::StaticText_0_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F9A8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_text::StaticText,0,Scaleform::GFx::ASString>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl_text::StaticText *, Scaleform::GFx::ASString *))_;
  return result;
}

// File Line: 88
// RVA: 0x8EAFA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StaticText> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 110
// RVA: 0x87A990
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_text::StaticText::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject::DisplayObject(
      v5,
      v2,
      &Scaleform::GFx::AS3::fl_text::StaticTextCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_text::StaticText::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::DisplayObject(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_text::StaticTextCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_text::StaticText::`vftable';
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

