// File Line: 114
// RVA: 0x7FC180
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsSolidFill *t)
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
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill::`vftable;
    v5[1].vfptr = 0i64;
    LODWORD(v5[1]._pRCC) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_display::GraphicsSolidFill *)v5;
  return result;
}

