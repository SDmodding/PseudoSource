// File Line: 188
// RVA: 0x7FB620
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Error::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Error> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Error *t)
{
  Scaleform::GFx::AS3::Instances::fl::Error *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Error *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::Error *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Error *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl::Error::Error(v4, t);
  result->pV = v4;
  return result;
}

