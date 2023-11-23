// File Line: 192
// RVA: 0x8EA5D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Timer> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Timer::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Timer> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Timer *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Timer::`vftable;
    v5[1].vfptr = 0i64;
    v5[1].pRCCRaw = 0i64;
    v5[1].pNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_utils::Timer *)v5;
  return result;
}

