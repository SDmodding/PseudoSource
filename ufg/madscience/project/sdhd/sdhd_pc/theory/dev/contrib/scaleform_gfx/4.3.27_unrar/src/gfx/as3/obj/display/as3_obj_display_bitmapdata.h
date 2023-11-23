// File Line: 267
// RVA: 0x82F2A0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *__fastcall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result)
{
  result->pObject = 0i64;
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData::clone(this, result);
  return result;
}

// File Line: 404
// RVA: 0x7FAEE0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::BitmapData> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::BitmapData *t)
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
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::BitmapData::`vftable;
    v5[1].vfptr = 0i64;
    v5[1].pRCCRaw = 0i64;
    v5[1].pNext = 0i64;
    v5[1].pPrev = 0i64;
    LOBYTE(v5[1].RefCount) = 1;
    *(&v5[1].RefCount + 1) = 0;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v5;
  return result;
}

