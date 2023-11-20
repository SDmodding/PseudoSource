// File Line: 116
// RVA: 0x7FCB80
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> *result, Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_gfx::MouseEventEx *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)t->pVM->MHeap->vfptr->Alloc(
                                                                  t->pVM->MHeap,
                                                                  t->MemSize,
                                                                  (Scaleform::AllocInfo *)&v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_events::MouseEvent::MouseEvent(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx::`vftable';
    v5[1].vfptr = 0i64;
    LODWORD(v5[1]._pRCC) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_gfx::MouseEventEx *)v5;
  return v3;
}

