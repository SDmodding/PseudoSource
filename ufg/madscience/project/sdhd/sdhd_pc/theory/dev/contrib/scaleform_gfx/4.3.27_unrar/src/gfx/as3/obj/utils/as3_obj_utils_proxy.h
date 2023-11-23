// File Line: 218
// RVA: 0x8EA120
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Proxy> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Proxy::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Proxy> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Proxy *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Proxy::`vftable;
    v5[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)-1i64;
    v5[1].pRCCRaw = -1i64;
    v5[1].pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)-1i64;
    v5[1].pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)-1i64;
    *(_QWORD *)&v5[1].RefCount = -1i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_utils::Proxy *)v5;
  return result;
}

