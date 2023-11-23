// File Line: 166
// RVA: 0x7FB540
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Domain *t)
{
  Scaleform::GFx::AS3::Instances::fl::Domain *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Domain *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::Domain *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Domain *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl::Domain::Domain(v4, t);
  result->pV = v4;
  return result;
}

