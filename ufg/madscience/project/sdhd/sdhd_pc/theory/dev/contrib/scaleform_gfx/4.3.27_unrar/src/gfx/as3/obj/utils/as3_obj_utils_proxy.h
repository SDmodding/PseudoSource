// File Line: 218
// RVA: 0x8EA120
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Proxy> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Proxy::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Proxy> *result, Scaleform::GFx::AS3::InstanceTraits::fl_utils::Proxy *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::Proxy *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Proxy> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Proxy *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_utils::Proxy *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Proxy::`vftable';
    *(_QWORD *)&v5->callPropertyInd = -1i64;
    *(_QWORD *)&v5->getDescendantsInd = -1i64;
    *(_QWORD *)&v5->hasPropertyInd = -1i64;
    *(_QWORD *)&v5->nextNameInd = -1i64;
    *(_QWORD *)&v5->nextValueInd = -1i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

