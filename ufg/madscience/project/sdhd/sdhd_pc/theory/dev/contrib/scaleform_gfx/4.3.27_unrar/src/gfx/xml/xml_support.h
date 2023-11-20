// File Line: 117
// RVA: 0x6F88A0
Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *__fastcall Scaleform::GFx::StateBag::GetXMLSupport(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *result)
{
  Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::XML::SupportBase *)this->vfptr->GetStateAddRef(
                                                          this,
                                                          State_OrigScale9Parent|State_MaskNode|0x10);
  return v2;
}

