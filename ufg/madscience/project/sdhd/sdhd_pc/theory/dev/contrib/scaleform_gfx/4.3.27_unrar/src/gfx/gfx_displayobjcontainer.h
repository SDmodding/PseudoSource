// File Line: 58
// RVA: 0x7E66C0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayObjContainer::GetBounds(Scaleform::GFx::DisplayObjContainer *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  Scaleform::GFx::DisplayList::GetBounds(&this->mDisplayList, result, t);
  return v3;
}

