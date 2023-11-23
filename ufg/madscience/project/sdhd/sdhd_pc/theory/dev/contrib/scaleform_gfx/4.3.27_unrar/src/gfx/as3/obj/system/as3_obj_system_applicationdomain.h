// File Line: 156
// RVA: 0x7FAC70
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *t)
{
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)t->pVM->MHeap->vfptr->Alloc(
                                                                         t->pVM->MHeap,
                                                                         t->MemSize,
                                                                         &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::ApplicationDomain(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 160
// RVA: 0x8EAAF0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstanceS(
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+58h] [rbp+20h] BYREF

  result->pObject = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(&resulta, t)->pV;
  return result;
}

