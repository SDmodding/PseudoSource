// File Line: 195
// RVA: 0x7FD300
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *result, Scaleform::GFx::AS3::InstanceTraits::fl::QName *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::QName *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::QName *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl::QName *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::QName *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl::QName *)t->pVM->MHeap->vfptr->Alloc(
                                                      t->pVM->MHeap,
                                                      t->MemSize,
                                                      (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl::QName::QName(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

// File Line: 212
// RVA: 0x7FD280
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::QName::MakeInstance(Scaleform::GFx::AS3::InstanceTraits::fl::QName *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t, Scaleform::GFx::ASString *n, Scaleform::GFx::AS3::Instances::fl::Namespace *ns)
{
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::QName> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::QName *v8; // rax
  int v10; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl::QName *v11; // [rsp+50h] [rbp+18h]

  v5 = n;
  v6 = t;
  v7 = result;
  v10 = 337;
  v8 = (Scaleform::GFx::AS3::Instances::fl::QName *)t->pVM->MHeap->vfptr->Alloc(
                                                      t->pVM->MHeap,
                                                      t->MemSize,
                                                      (Scaleform::AllocInfo *)&v10);
  v11 = v8;
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl::QName::QName(v8, v6, v5, ns);
  v7->pV = v8;
  return v7;
}

