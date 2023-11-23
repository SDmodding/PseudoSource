// File Line: 188
// RVA: 0x8D5570
Scaleform::Render::Rect<unsigned long> *__fastcall Scaleform::GFx::ConstShapeWithStyles::GetBoundsLocal(
        Scaleform::Render::SubImage *this,
        Scaleform::Render::Rect<unsigned long> *result)
{
  *result = this->SubRect;
  return result;
}

// File Line: 189
// RVA: 0x906800
void __fastcall Scaleform::GFx::ConstShapeWithStyles::SetBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::Render::Rect<float> *r)
{
  float x1; // eax
  float y2; // xmm2_4
  float y1; // xmm0_4

  x1 = r->x1;
  y2 = r->y2;
  y1 = r->y1;
  this->Bound.x2 = r->x2;
  this->Bound.y2 = y2;
  this->Bound.x1 = x1;
  this->Bound.y1 = y1;
}

// File Line: 191
// RVA: 0x8DD520
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::ConstShapeWithStyles::GetRectBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::Render::Rect<float> *result)
{
  *result = this->RectBound;
  return result;
}

// File Line: 192
// RVA: 0x90AD70
void __fastcall Scaleform::GFx::ConstShapeWithStyles::SetRectBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::Render::Rect<float> *r)
{
  float x1; // eax
  float y2; // xmm2_4
  float y1; // xmm0_4

  x1 = r->x1;
  y2 = r->y2;
  y1 = r->y1;
  this->RectBound.x2 = r->x2;
  this->RectBound.y2 = y2;
  this->RectBound.x1 = x1;
  this->RectBound.y1 = y1;
}

// File Line: 195
// RVA: 0x8DE780
__int64 __fastcall Scaleform::Render::RawImage::GetUse(Scaleform::GFx::ConstShapeWithStyles *this)
{
  return this->StrokeStylesNum;
}

// File Line: 237
// RVA: 0x8C5060
__int64 __fastcall Scaleform::GFx::SwfShapeCharacterDef::DefPointTestLocal(
        Scaleform::GFx::SwfShapeCharacterDef *this,
        Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  return Scaleform::GFx::ShapeDataBase::DefPointTestLocal(
           this->pShape.pObject,
           this->pShapeMeshProvider.pObject,
           pt,
           testShape,
           pinst);
}

// File Line: 247
// RVA: 0x8EBD70
__int64 __fastcall Scaleform::GFx::SwfShapeCharacterDef::NeedsResolving(Scaleform::GFx::SwfShapeCharacterDef *this)
{
  return ((unsigned __int8)this->pShape.pObject->Flags >> 2) & 1;
}

// File Line: 266
// RVA: 0x8DD540
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::ImageShapeCharacterDef::GetRectBoundsLocal(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  this->vfptr[1].GetResourceReport(this);
  return result;
}

