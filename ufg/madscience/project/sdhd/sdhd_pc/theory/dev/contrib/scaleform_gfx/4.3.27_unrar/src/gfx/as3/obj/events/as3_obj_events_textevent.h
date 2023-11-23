// File Line: 90
// RVA: 0x81ECA0
void __fastcall Scaleform::GFx::AS3::Instances::fl_events::TextEvent::SetText(
        Scaleform::GFx::AS3::Instances::fl_events::TextEvent *this,
        Scaleform::GFx::ASString *t)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = t->pNode;
  ++t->pNode->RefCount;
  v4 = this->Text.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Text.pNode = pNode;
}

// File Line: 150
// RVA: 0x7FDB10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::TextEvent> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_events::TextEvent *t)
{
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::TextEvent *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::TextEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::TextEvent::TextEvent(v4, t);
  result->pV = v4;
  return result;
}

