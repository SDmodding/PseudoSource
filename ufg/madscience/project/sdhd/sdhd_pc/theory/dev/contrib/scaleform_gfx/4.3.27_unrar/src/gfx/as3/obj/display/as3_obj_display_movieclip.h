// File Line: 270
// RVA: 0x77C4B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr::Descr(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *this,
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *o)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  this->Method.Flags = o->Method.Flags;
  this->Method.Bonus.pWeakProxy = o->Method.Bonus.pWeakProxy;
  this->Method.value = o->Method.value;
  if ( (o->Method.Flags & 0x1F) > 9 )
  {
    if ( (o->Method.Flags & 0x200) != 0 )
    {
      ++o->Method.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (o->Method.Flags & 0x1F) == 10 )
      {
        ++o->Method.value.VS._1.VStr->RefCount;
        goto LABEL_13;
      }
      if ( (o->Method.Flags & 0x1F) > 0xA )
      {
        if ( (o->Method.Flags & 0x1F) <= 0xF )
        {
          VObj = o->Method.value.VS._1;
        }
        else
        {
          if ( (o->Method.Flags & 0x1F) > 0x11 )
            goto LABEL_13;
          VObj = (Scaleform::GFx::AS3::Value::V1U)o->Method.value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
LABEL_13:
  this->Frame = o->Frame;
}

// File Line: 322
// RVA: 0x7FCC10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::MovieClip> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::MovieClip *t)
{
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)t->pVM->MHeap->vfptr->Alloc(
                                                                      t->pVM->MHeap,
                                                                      t->MemSize,
                                                                      &v7);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::DisplayObject(v4, t);
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
  result->pV = (Scaleform::GFx::AS3::Instances::fl_display::MovieClip *)v5;
  return result;
}

