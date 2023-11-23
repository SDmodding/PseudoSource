// File Line: 129
// RVA: 0x7FC3D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_gfx::IMECandidateListStyle *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instance *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle::`vftable;
    v5[1].vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)-1i64;
    v5[1].pRCCRaw = -1i64;
    v5[1].pNext = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)-1i64;
    v5[1].pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)-1i64;
    *(_QWORD *)&v5[1].RefCount = -1i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_gfx::IMECandidateListStyle *)v5;
  return result;
}

