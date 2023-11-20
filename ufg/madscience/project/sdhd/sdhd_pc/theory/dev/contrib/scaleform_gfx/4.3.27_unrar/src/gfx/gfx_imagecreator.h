// File Line: 184
// RVA: 0x6EFBC0
Scaleform::Ptr<Scaleform::GFx::ImageCreator> *__fastcall Scaleform::GFx::StateBag::GetImageCreator(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ImageCreator> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ImageCreator *)this->vfptr->GetStateAddRef(
                                                      this,
                                                      State_OrigNodeBounds|State_MaskNode);
  return v2;
}

// File Line: 193
// RVA: 0x8D9C60
Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *__fastcall Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)this->vfptr->GetStateAddRef(
                                                                  this,
                                                                  State_Type_Count|State_MaskNode);
  return v2;
}

