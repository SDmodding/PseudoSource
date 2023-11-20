// File Line: 784
// RVA: 0x7FB340
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Date> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Date::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Date> *result, Scaleform::GFx::AS3::InstanceTraits::fl::Date *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Date *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Date> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instance *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Date::`vftable';
    LODWORD(v5[1].vfptr) = 0;
    BYTE4(v5[1].vfptr) = 0;
    v5[1].pRCCRaw = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::Date *)v5;
  return v3;
}

