// File Line: 158
// RVA: 0x8E9BF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcher(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

