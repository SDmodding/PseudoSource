// File Line: 120
// RVA: 0x7FC210
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsStroke *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke *)t->pVM->MHeap->vfptr->Alloc(
                                                                       t->pVM->MHeap,
                                                                       t->MemSize,
                                                                       &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_display::GraphicsStroke::GraphicsStroke(v4, t);
  result->pV = v4;
  return result;
}

