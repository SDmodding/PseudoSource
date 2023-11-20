// File Line: 170
// RVA: 0x8EA3A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *result, Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_text::StyleSheet *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_text::StyleSheet> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_text::StyleSheet::`vftable';
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

