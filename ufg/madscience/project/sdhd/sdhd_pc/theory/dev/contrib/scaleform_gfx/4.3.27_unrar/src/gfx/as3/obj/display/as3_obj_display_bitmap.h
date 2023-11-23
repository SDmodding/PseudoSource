// File Line: 111
// RVA: 0x818430
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Bitmap::SetBitmapData(
        Scaleform::GFx::AS3::Instances::fl_display::Bitmap *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *b)
{
  Scaleform::GFx::DisplayObject *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *v4; // rdi
  Scaleform::GFx::Resource *v5; // rdi
  Scaleform::GFx::Resource *pParent; // rcx
  Scaleform::GFx::Resource *v7; // rcx
  Scaleform::GFx::AS3::AvmBitmap *v8; // rcx

  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pBitmapData,
    b);
  pObject = this->pDispObj.pObject;
  if ( pObject )
  {
    v4 = this->pBitmapData.pObject;
    if ( v4 )
    {
      v5 = v4->pDefImpl.pObject;
      if ( v5 )
        Scaleform::Render::RenderBuffer::AddRef(v5);
      pParent = (Scaleform::GFx::Resource *)pObject[1].pParent;
      if ( pParent )
        Scaleform::GFx::Resource::Release(pParent);
      pObject[1].pParent = (Scaleform::GFx::InteractiveObject *)v5;
    }
    else
    {
      v7 = (Scaleform::GFx::Resource *)pObject[1].pParent;
      if ( v7 )
        Scaleform::GFx::Resource::Release(v7);
      pObject[1].pParent = 0i64;
    }
  }
  v8 = (Scaleform::GFx::AS3::AvmBitmap *)this->pDispObj.pObject;
  if ( v8 )
    Scaleform::GFx::AS3::AvmBitmap::RecreateRenderNode(v8);
}

// File Line: 190
// RVA: 0x7FAE50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Bitmap> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Bitmap> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Bitmap *t)
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
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_display::Bitmap::`vftable;
    v5[1].vfptr = 0i64;
    LODWORD(v5[1]._pRCC) = 0;
    BYTE4(v5[1].pRCCRaw) = 1;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = (Scaleform::GFx::AS3::Instances::fl_display::Bitmap *)v5;
  return result;
}

