// File Line: 278
// RVA: 0x7FBDD0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_filters::GradientBevelFilter::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_filters::GradientBevelFilter *t)
{
  Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter *)t->pVM->MHeap->vfptr->Alloc(
                                                                            t->pVM->MHeap,
                                                                            t->MemSize,
                                                                            &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_filters::GradientBevelFilter::GradientBevelFilter(v4, t);
  result->pV = v4;
  return result;
}

