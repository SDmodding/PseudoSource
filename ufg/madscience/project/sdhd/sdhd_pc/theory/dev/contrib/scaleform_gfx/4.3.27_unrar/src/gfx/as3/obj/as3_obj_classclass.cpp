// File Line: 36
// RVA: 0x820330
void __fastcall Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(Scaleform::GFx::AS3::Classes::ClassClass *this)
{
  Scaleform::GFx::AS3::Classes::ClassClass *v1; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v2; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *v3; // rbx
  unsigned int v4; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v5; // rbx
  Scaleform::GFx::AS3::Object *v6; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+30h] [rbp+8h]

  v1 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  v2 = (Scaleform::GFx::AS3::Instances::fl::Object *)v1->pPrototype.pObject;
  v3 = result.pV;
  if ( result.pV != v2 )
  {
    if ( v2 )
    {
      if ( (unsigned __int8)v2 & 1 )
      {
        v1->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)&v2[-1].DynAttrs.mHash.pTable + 7);
      }
      else
      {
        v4 = v2->RefCount;
        if ( v4 & 0x3FFFFF )
        {
          v2->RefCount = v4 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
        }
      }
    }
    v1->pPrototype.pObject = (Scaleform::GFx::AS3::Object *)&v3->vfptr;
  }
  v5 = v1->vfptr;
  v6 = Scaleform::GFx::AS3::Class::GetPrototype((Scaleform::GFx::AS3::Class *)&v1->vfptr);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::ClassClass *, Scaleform::GFx::AS3::Object *))v5[7].Finalize_GC)(
    v1,
    v6);
}

// File Line: 46
// RVA: 0x77BFE0
void __fastcall Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(Scaleform::GFx::AS3::ClassTraits::ClassClass *this, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v6; // rbx
  Scaleform::GFx::AS3::Class *v7; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rbx

  v2 = vm;
  v3 = this;
  Scaleform::GFx::AS3::Traits::Traits((Scaleform::GFx::AS3::Traits *)&this->vfptr, vm);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable;
  v3->ITraits.pObject = 0i64;
  v3->Flags |= 0x20ui64;
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::ClassClass::`vftable;
  v4 = v2->MHeap;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v2->MHeap, 240ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v5, v2, &Scaleform::GFx::AS3::fl::ClassCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::ClassClass::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    (Scaleform::GFx::AS3::ClassTraits::Traits *)&v3->vfptr,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v6);
  v7 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, (Scaleform::GFx::AS3::ClassTraits::Traits *)&v3->vfptr);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::ClassClass::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->pConstructor,
    v8);
}

// File Line: 62
// RVA: 0x7B68B0
char __fastcall Scaleform::GFx::AS3::ClassTraits::ClassClass::Coerce(Scaleform::GFx::AS3::ClassTraits::ClassClass *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::Assign(result, value);
  return 1;
}

