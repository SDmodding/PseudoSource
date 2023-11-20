// File Line: 192
// RVA: 0x8EA5D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Timer> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Timer::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Timer> *result, Scaleform::GFx::AS3::InstanceTraits::fl_utils::Timer *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::Timer *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Timer> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Timer *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Timer::`vftable';
    *(_QWORD *)&v5->RepeatCount = 0i64;
    v5->Delay = 0.0;
    v5->pCoreTimer.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

