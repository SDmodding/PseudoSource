// File Line: 90
// RVA: 0x81ECA0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this, Scaleform::GFx::ASString *t)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v2 = t->pNode;
  v3 = this;
  ++v2->RefCount;
  v4 = this->Text.pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v3->Text.pNode = v2;
}

// File Line: 150
// RVA: 0x7FDB10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

