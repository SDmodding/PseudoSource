// File Line: 48
// RVA: 0x7E9660
Scaleform::GFx::AS3::ValueRegisterFile::Page *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx::GetEventClass(Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx *this)
{
  return this->pTraits.pObject->pVM[1].RegisterFile.pCurrentPage;
}

// File Line: 53
// RVA: 0x7B6510
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx::Clone(Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rbp
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v2 = result;
  v3 = this;
  Scaleform::GFx::AS3::Instances::fl_events::Event::Clone(
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&this->vfptr,
    result);
  v4 = v2->pObject;
  v5 = v3->Text.pNode;
  ++v5->RefCount;
  v6 = (Scaleform::GFx::ASStringNode *)v4[1].vfptr;
  v7 = v6->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  v4[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)v5;
  LODWORD(v4[1]._pRCC) = v3->controllerIdx;
  HIDWORD(v4[1].pRCCRaw) = v3->buttonIdx;
  return v2;
}

// File Line: 82
// RVA: 0x8001E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::TextEventEx::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_gfx::TextEventEx *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::TextEventEx> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_gfx::TextEventEx::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_gfx::TextEventEx *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 124
// RVA: 0x7674A0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_gfx::TextEventEx::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_gfx::TextEventExCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::Event::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::TextEvent::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_gfx::TextEventEx::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_gfx::TextEventExCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_gfx::TextEventEx::`vftable';
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
                                       88i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_gfx::TextEventEx::`vftable';
    v10[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"linkMouseOver";
    v10[1].pRCCRaw = (unsigned __int64)"linkMouseOut";
  }
  return v3;
}

