// File Line: 49
// RVA: 0x8AE9C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v4; // r9d
  unsigned int v5; // ecx
  Scaleform::GFx::AS3::Value::V1U v6; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *InstanceS; // rax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> result; // [rsp+58h] [rbp+20h] BYREF

  if ( argc )
  {
    v4 = argv->Flags & 0x1F;
    if ( v4 )
    {
      if ( v4 - 12 > 3 && v4 != 10 || argv->value.VS._1.VStr )
        this->checkPolicyFile = argv->value.VS._1.VBool;
    }
  }
  if ( argc > 1 )
  {
    v5 = argv[1].Flags & 0x1F;
    if ( v5 )
    {
      if ( v5 - 12 > 3 && v5 != 10 || argv[1].value.VS._1.VStr )
      {
        v6 = argv[1].value.VS._1;
        InstanceS = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstanceS(
                                                                                            (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)v6.VStr[1].pData,
                                                                                            &result,
                                                                                            (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)v6.VStr[1].pData);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->applicationDomain,
          InstanceS);
        pObject = result.pObject;
        if ( result.pObject )
        {
          if ( ((__int64)result.pObject & 1) != 0 )
          {
            --result.pObject;
          }
          else
          {
            RefCount = result.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              result.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
          }
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->applicationDomain.pObject->VMDomain,
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)v6.VStr[1].pLower);
      }
    }
  }
}

// File Line: 85
// RVA: 0x8EAE50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::LoaderContext> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::LoaderContext> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 107
// RVA: 0x87EAC0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::LoaderContext::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_system::LoaderContextCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::LoaderContext::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_system::LoaderContextCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

