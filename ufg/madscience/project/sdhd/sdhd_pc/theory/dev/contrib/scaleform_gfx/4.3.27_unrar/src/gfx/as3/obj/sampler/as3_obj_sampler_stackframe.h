// File Line: 117
// RVA: 0x8EA2B0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_sampler::StackFrame::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame> *result, Scaleform::GFx::AS3::InstanceTraits::fl_sampler::StackFrame *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_sampler::StackFrame *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_sampler::StackFrame::`vftable;
    v5->file = 0i64;
    v5->line = 0;
    v5->name = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

