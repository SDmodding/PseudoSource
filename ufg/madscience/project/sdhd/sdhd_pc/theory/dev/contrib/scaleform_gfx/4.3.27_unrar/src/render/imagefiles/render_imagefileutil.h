// File Line: 42
// RVA: 0x8DE210
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::FileImageSource::GetSize(Scaleform::Render::FileImageSource *this, Scaleform::Render::Size<unsigned long> *result)
{
  result->Width = this->Size.Width;
  result->Height = this->Size.Height;
  return result;
}

