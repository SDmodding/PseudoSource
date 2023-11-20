// File Line: 147
// RVA: 0x7FC570
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::IOErrorEvent *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *v5; // rbx
  Scaleform::GFx::AS3::StringManager *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  int v9; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v10; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v11; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v9 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 (Scaleform::AllocInfo *)&v9);
  v5 = (Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *)v4;
  v10 = v4;
  v11 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::ErrorEvent::`vftable';
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent::`vftable';
    v6 = v5->pTraits.pObject->pVM->StringManagerRef;
    v7 = v6->Builtins[0].pNode;
    v5->Text.pNode = v6->Builtins[0].pNode;
    ++v7->RefCount;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

