// File Line: 112
// RVA: 0x6EFA80
Scaleform::Ptr<Scaleform::GFx::FontLib> *__fastcall Scaleform::GFx::StateBag::GetFontLib(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::FontLib> *result)
{
  Scaleform::Ptr<Scaleform::GFx::FontLib> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::FontLib *)this->vfptr->GetStateAddRef(
                                                 this,
                                                 (Scaleform::GFx::State::StateType)20i64);
  return v2;
}

