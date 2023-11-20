// File Line: 270
// RVA: 0x77C4B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *this, Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *o)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v2; // r8
  signed int v3; // eax
  long double v4; // rcx

  v2 = this;
  this->Method.Flags = o->Method.Flags;
  this->Method.Bonus.pWeakProxy = o->Method.Bonus.pWeakProxy;
  this->Method.value = o->Method.value;
  v3 = o->Method.Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (o->Method.Flags >> 9) & 1 )
    {
      ++o->Method.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v3 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&o->Method.value.VNumber + 24i64);
        goto LABEL_13;
      }
      if ( v3 > 10 )
      {
        if ( v3 <= 15 )
        {
          v4 = o->Method.value.VNumber;
        }
        else
        {
          if ( v3 > 17 )
            goto LABEL_13;
          v4 = *(double *)&o->Method.value.VS._2.VObj;
        }
        if ( v4 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v4 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v4 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
LABEL_13:
  v2->Frame = o->Frame;
}

// File Line: 322
// RVA: 0x7FCC10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *result, Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      (Scaleform::AllocInfo *)&v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::`vftable;
    v5[1].vfptr = 0i64;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Sprite::`vftable;
    v5[1].pRCCRaw = 0i64;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::MovieClip::`vftable;
    v5[1].pNext = 0i64;
    LODWORD(v5[1].pPrev) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)v5;
  return v3;
}

