// File Line: 296
// RVA: 0x7FC910
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_geom::Matrix3D *t)
{
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_geom::Matrix3D::Matrix3D(v4, t);
  result->pV = v4;
  return result;
}

