// File Line: 104
// RVA: 0x7FB160
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Catch *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Catch *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl::Catch *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Catch::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

// File Line: 175
// RVA: 0x7FB0F0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *__fastcall Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstance(
        Scaleform::GFx::AS3::Classes::fl::Catch *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> *result,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *e)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch> v8; // [rsp+28h] [rbp-10h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> resulta; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::GFx::AS3::Classes::fl::Catch::MakeInstanceTraits(this, &resulta, file, e);
  result->pV = Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(&v8, resulta.pObject)->pV;
  pObject = resulta.pObject;
  if ( resulta.pObject )
  {
    if ( ((__int64)resulta.pObject & 1) != 0 )
    {
      --resulta.pObject;
    }
    else
    {
      RefCount = resulta.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        resulta.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return result;
}

