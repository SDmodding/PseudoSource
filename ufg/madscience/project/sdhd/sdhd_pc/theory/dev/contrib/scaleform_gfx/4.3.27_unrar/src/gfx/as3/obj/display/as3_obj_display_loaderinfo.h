// File Line: 142
// RVA: 0x7E73A0
Scaleform::RefCountNTSImpl *__fastcall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v1; // rbx
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::RefCountNTSImpl *v4; // rbx
  char v5; // di
  Scaleform::RefCountNTSImpl *v7; // [rsp+40h] [rbp+8h]

  v1 = this->Content.pObject;
  v2 = 0i64;
  if ( v1 )
  {
    v3 = v1->pDispObj.pObject;
    if ( v3 )
      ++v3->RefCount;
    v4 = (Scaleform::RefCountNTSImpl *)&v1->pDispObj.pObject->vfptr;
    v7 = v4;
    v5 = 1;
    v2 = v4;
  }
  else
  {
    v7 = 0i64;
    v5 = 2;
    v4 = 0i64;
  }
  if ( v5 & 2 )
  {
    v5 &= 0xFDu;
    if ( v2 )
      Scaleform::RefCountNTSImpl::Release(v2);
  }
  if ( v5 & 1 && v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  return v7;
}

// File Line: 336
// RVA: 0x7FC8A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *result, Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)t->pVM->MHeap->vfptr->Alloc(
                                                                   t->pVM->MHeap,
                                                                   t->MemSize,
                                                                   (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::LoaderInfo(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

