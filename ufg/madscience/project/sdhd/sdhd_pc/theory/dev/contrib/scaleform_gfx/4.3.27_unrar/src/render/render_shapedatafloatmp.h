// File Line: 70
// RVA: 0x9A73A0
void __fastcall Scaleform::Render::ShapeDataFloatMP::RectanglePath(
        Scaleform::Render::ShapeDataFloatMP *this,
        float x1,
        float y1,
        float x2,
        float y2)
{
  Scaleform::Render::ShapeDataFloat *pObject; // rcx
  float StartX; // xmm1_4

  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
    this->pData.pObject,
    x1,
    y1);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    this->pData.pObject,
    x2,
    y1);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    this->pData.pObject,
    x2,
    y2);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    this->pData.pObject,
    x1,
    y2);
  pObject = this->pData.pObject;
  StartX = pObject->StartX;
  if ( StartX != pObject->LastX || pObject->StartY != pObject->LastY )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      pObject,
      StartX,
      pObject->StartY);
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this->pData.pObject);
}

