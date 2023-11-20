// File Line: 70
// RVA: 0x9A73A0
void __fastcall Scaleform::Render::ShapeDataFloatMP::RectanglePath(Scaleform::Render::ShapeDataFloatMP *this, float x1, float y1, float x2, float y2)
{
  Scaleform::Render::ShapeDataFloatMP *v5; // rbx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v6; // rcx
  float v7; // xmm1_4

  v5 = this;
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
    (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&this->pData.pObject->vfptr,
    x1,
    y1);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->pData.pObject->vfptr,
    x2,
    y1);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->pData.pObject->vfptr,
    x2,
    y2);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->pData.pObject->vfptr,
    x1,
    y2);
  v6 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->pData.pObject->vfptr;
  v7 = v6->StartX;
  if ( v7 != v6->LastX || v6->StartY != v6->LastY )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      v6,
      v7,
      v6->StartY);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->pData.pObject->vfptr);
}

