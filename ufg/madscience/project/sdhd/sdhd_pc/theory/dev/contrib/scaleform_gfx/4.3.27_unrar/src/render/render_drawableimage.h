// File Line: 296
// RVA: 0x98B6D0
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::DrawableImage::GetSize(Scaleform::Render::DrawableImage *this, Scaleform::Render::Size<unsigned long> *result)
{
  result->Width = this->ISize.Width;
  result->Height = this->ISize.Height;
  return result;
}

// File Line: 371
// RVA: 0x78A1C0
void __fastcall Scaleform::Render::DIPixelProvider::~DIPixelProvider(Scaleform::Render::DIPixelProvider *this)
{
  this->vfptr = (Scaleform::Render::DIPixelProviderVtbl *)&Scaleform::Render::DIPixelProvider::`vftable;
}

