// File Line: 36
// RVA: 0x820330
void __fastcall Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(
        Scaleform::GFx::AS3::Classes::ClassClass *this)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *vfptr; // rbx
  Scaleform::GFx::AS3::Object *Prototype; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Object::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)this->pTraits.pObject->pVM->TraitsObject.pObject->ITraits.pObject);
  pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)this->pPrototype.pObject;
  pV = result.pV;
  if ( result.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pPrototype.pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->pPrototype.pObject = pV;
  }
  vfptr = this->vfptr;
  Prototype = Scaleform::GFx::AS3::Class::GetPrototype(this);
  ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::ClassClass *, Scaleform::GFx::AS3::Object *))vfptr[7].Finalize_GC)(
    this,
    Prototype);
}

// File Line: 46
// RVA: 0x77BFE0
void __fastcall Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(
        Scaleform::GFx::AS3::ClassTraits::ClassClass *this,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v5; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v6; // rbx
  Scaleform::GFx::AS3::Class *v7; // rax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // rbx

  Scaleform::GFx::AS3::Traits::Traits(this, vm);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::Traits::`vftable;
  this->ITraits.pObject = 0i64;
  this->Flags |= 0x20ui64;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::ClassClass::`vftable;
  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v5, vm, &Scaleform::GFx::AS3::fl::ClassCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::ClassClass::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    this,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v6);
  v7 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::Class::Class(v7, this);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::ClassClass::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pConstructor,
    v8);
}

// File Line: 62
// RVA: 0x7B68B0
char __fastcall Scaleform::GFx::AS3::ClassTraits::ClassClass::Coerce(
        Scaleform::GFx::AS3::ClassTraits::ClassClass *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value::Assign(result, value);
  return 1;
}

