// File Line: 64
// RVA: 0x87ECC0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_security::RevocationCheckSettings::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rax
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(
      v5,
      vm,
      &Scaleform::GFx::AS3::fl_security::RevocationCheckSettingsCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_security::RevocationCheckSettings::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v7 )
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_security::RevocationCheckSettingsCI);
  else
    v8.pV = 0i64;
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)MHeap->vfptr->Alloc(MHeap, 200ui64, 0i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_security::RevocationCheckSettings::`vftable;
    LODWORD(v10[1].vfptr) = 0;
    v10[1].pRCCRaw = 0i64;
    v10[1].RefCount = 0;
    v10[1].pTraits.pObject = 0i64;
    LODWORD(v10[1].pPrototype.pObject) = 0;
    v10[2].vfptr = 0i64;
    LODWORD(v10[2].pPrev) = 0;
    *(_QWORD *)&v10[2].RefCount = 0i64;
  }
  return result;
}

