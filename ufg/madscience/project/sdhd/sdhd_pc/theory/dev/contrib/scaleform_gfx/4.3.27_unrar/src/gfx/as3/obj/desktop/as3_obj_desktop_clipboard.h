// File Line: 171
// RVA: 0x7FB1E0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_desktop::Clipboard> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_desktop::Clipboard::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_desktop::Clipboard> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_desktop::Clipboard *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_desktop::Clipboard *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl_desktop::Clipboard *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_desktop::Clipboard::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

