// File Line: 127
// RVA: 0x7FCD60
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::NativeDragEvent *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // rax
  Scaleform::GFx::ASString *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::ASString *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent::`vftable';
    v5[16].pNode = 0i64;
    v5[17].pNode = 0i64;
    Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
      v5 + 18,
      (Scaleform::GFx::AS3::StringManager *)v5[5].pNode[3].pManager->StringSet.pTable);
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_events::NativeDragEvent *)v5;
  return v3;
}

