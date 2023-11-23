// File Line: 117
// RVA: 0x6F88A0
Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *__fastcall Scaleform::GFx::StateBag::GetXMLSupport(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *result)
{
  result->pObject = (Scaleform::GFx::XML::SupportBase *)this->vfptr->GetStateAddRef(this, 28i64);
  return result;
}

