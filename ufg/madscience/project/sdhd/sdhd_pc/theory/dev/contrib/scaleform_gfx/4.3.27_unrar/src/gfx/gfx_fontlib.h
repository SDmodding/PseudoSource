// File Line: 112
// RVA: 0x6EFA80
Scaleform::Ptr<Scaleform::GFx::FontLib> *__fastcall Scaleform::GFx::StateBag::GetFontLib(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::FontLib> *result)
{
  result->pObject = (Scaleform::GFx::FontLib *)this->vfptr->GetStateAddRef(this, 20i64);
  return result;
}

