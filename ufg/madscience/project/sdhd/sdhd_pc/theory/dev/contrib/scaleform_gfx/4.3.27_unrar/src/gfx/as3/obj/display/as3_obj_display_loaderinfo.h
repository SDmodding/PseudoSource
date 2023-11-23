// File Line: 142
// RVA: 0x7E73A0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::GetContentDispObj(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pObject; // rbx
  Scaleform::RefCountNTSImpl *v2; // rcx
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::RefCountNTSImpl *v4; // rbx
  char v5; // di
  Scaleform::RefCountNTSImpl *v7; // [rsp+40h] [rbp+8h]

  pObject = this->Content.pObject;
  v2 = 0i64;
  if ( pObject )
  {
    v3 = pObject->pDispObj.pObject;
    if ( v3 )
      ++v3->RefCount;
    v4 = pObject->pDispObj.pObject;
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
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v2 )
      Scaleform::RefCountNTSImpl::Release(v2);
  }
  if ( (v5 & 1) != 0 && v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  return (Scaleform::GFx::DisplayObject *)v7;
}

// File Line: 336
// RVA: 0x7FC8A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::LoaderInfo *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)t->pVM->MHeap->vfptr->Alloc(
                                                                   t->pVM->MHeap,
                                                                   t->MemSize,
                                                                   &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::LoaderInfo(v4, t);
  result->pV = v4;
  return result;
}

