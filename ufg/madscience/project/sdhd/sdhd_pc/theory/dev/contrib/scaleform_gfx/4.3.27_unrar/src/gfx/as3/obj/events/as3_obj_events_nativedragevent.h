// File Line: 127
// RVA: 0x7FCD60
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent::`vftable;
    v5->allowedActions.pObject = 0i64;
    v5->clipboard.pObject = 0i64;
    Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
      &v5->dropAction,
      v5->pTraits.pObject->pVM->StringManagerRef);
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

