// File Line: 92
// RVA: 0x7E96A0
const char *__fastcall Scaleform::GFx::AS3::Instances::fl_events::Event::GetEventName(Scaleform::GFx::AS3::Instances::fl_events::Event *this)
{
  return "Event";
}

// File Line: 96
// RVA: 0x7F9040
bool __fastcall Scaleform::GFx::AS3::Instances::fl_events::Event::IsPropagationStopped(Scaleform::GFx::AS3::Instances::fl_events::Event *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 84);
  return v1 & 8 || v1 & 0x10;
}

// File Line: 245
// RVA: 0x7FB710
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_events::Event::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *result, Scaleform::GFx::AS3::InstanceTraits::fl_events::Event *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_events::Event *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_events::Event> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::Event *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::Event *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)t->pVM->MHeap->vfptr->Alloc(
                                                             t->pVM->MHeap,
                                                             t->MemSize,
                                                             (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_events::Event::Event(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

