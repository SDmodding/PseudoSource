// File Line: 64
// RVA: 0x87A2C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_printing::PrintJobOrientation::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(
      v5,
      vm,
      &Scaleform::GFx::AS3::fl_printing::PrintJobOrientationCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_printing::PrintJobOrientation::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v8,
      vm,
      &Scaleform::GFx::AS3::fl_printing::PrintJobOrientationCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        88i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_printing::PrintJobOrientation::`vftable;
    v11[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)"landscape";
    v11[1].pRCCRaw = (unsigned __int64)"portrait";
  }
  return result;
}

