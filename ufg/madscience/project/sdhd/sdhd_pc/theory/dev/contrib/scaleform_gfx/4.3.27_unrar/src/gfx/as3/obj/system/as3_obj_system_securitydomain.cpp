// File Line: 60
// RVA: 0x8EAF40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 78
// RVA: 0x91E610
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain::currentDomainGet(Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain> *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method class_::SecurityDomain::currentDomainGet() is not implemented\n");
}

// File Line: 91
// RVA: 0x15983E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F8C8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::SecurityDomain>>::Method = Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain::currentDomainGet;
  return result;
}

// File Line: 114
// RVA: 0x87AB40
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_system::SecurityDomainCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::SecurityDomain::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_system::SecurityDomainCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_system::SecurityDomain::`vftable';
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
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::SecurityDomain::`vftable';
  }
  return v3;
}

