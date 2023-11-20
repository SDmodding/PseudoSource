// File Line: 49
// RVA: 0x8AE9C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::LoaderContext::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_system::LoaderContext *v3; // rbx
  unsigned int v4; // er9
  unsigned int v5; // ecx
  long double v6; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // rax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> result; // [rsp+58h] [rbp+20h]

  v3 = this;
  if ( argc )
  {
    v4 = argv->Flags & 0x1F;
    if ( v4 )
    {
      if ( v4 - 12 > 3 && v4 != 10 || *(_QWORD *)&argv->value.VNumber )
        this->checkPolicyFile = argv->value.VS._1.VBool;
    }
  }
  if ( argc > 1 )
  {
    v5 = argv[1].Flags & 0x1F;
    if ( v5 )
    {
      if ( v5 - 12 > 3 && v5 != 10 || *(_QWORD *)&argv[1].value.VNumber )
      {
        v6 = argv[1].value.VNumber;
        v7 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstanceS(
                                                                                     *(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain **)(*(_QWORD *)&v6 + 40i64),
                                                                                     &result,
                                                                                     *(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain **)(*(_QWORD *)&v6 + 40i64));
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->applicationDomain,
          v7);
        v8 = result.pObject;
        if ( result.pObject )
        {
          if ( (_QWORD)result.pObject & 1 )
          {
            --result.pObject;
          }
          else
          {
            v9 = result.pObject->RefCount;
            if ( v9 & 0x3FFFFF )
            {
              result.pObject->RefCount = v9 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
            }
          }
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v3->applicationDomain.pObject->VMDomain,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v6 + 56i64));
      }
    }
  }
}

// File Line: 85
// RVA: 0x8EAE50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::LoaderContext> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 107
// RVA: 0x87EAC0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::LoaderContext::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_system::LoaderContextCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::LoaderContext::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_system::LoaderContextCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_system::LoaderContext::`vftable;
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

