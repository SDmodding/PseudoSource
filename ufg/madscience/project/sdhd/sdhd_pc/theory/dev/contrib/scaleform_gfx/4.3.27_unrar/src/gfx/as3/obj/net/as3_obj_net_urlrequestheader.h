// File Line: 110
// RVA: 0x7FDEC0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequestHeader::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader> *result, Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequestHeader *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequestHeader *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader *)t->pVM->MHeap->vfptr->Alloc(
                                                                     t->pVM->MHeap,
                                                                     t->MemSize,
                                                                     (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_net::URLRequestHeader::URLRequestHeader(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

