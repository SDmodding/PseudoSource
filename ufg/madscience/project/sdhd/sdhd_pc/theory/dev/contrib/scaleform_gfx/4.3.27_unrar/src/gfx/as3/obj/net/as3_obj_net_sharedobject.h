// File Line: 249
// RVA: 0x7FD590
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *result, Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_net::SharedObject *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::SharedObject> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_net::SharedObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                 t->pVM->MHeap,
                                                                 t->MemSize,
                                                                 (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_net::SharedObject::SharedObject(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

