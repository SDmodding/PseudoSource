// File Line: 184
// RVA: 0x6EFBC0
Scaleform::Ptr<Scaleform::GFx::ImageCreator> *__fastcall Scaleform::GFx::StateBag::GetImageCreator(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ImageCreator> *result)
{
  result->pObject = (Scaleform::GFx::ImageCreator *)this->vfptr->GetStateAddRef(this, 14i64);
  return result;
}

// File Line: 193
// RVA: 0x8D9C60
Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *__fastcall Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *result)
{
  result->pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)this->vfptr->GetStateAddRef(this, 15i64);
  return result;
}

