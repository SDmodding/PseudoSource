// File Line: 54
// RVA: 0x7E7760
const char *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetDefaultASClassName(Scaleform::GFx::AS3::AvmBitmap *this)
{
  return "flash.display.Bitmap";
}

// File Line: 56
// RVA: 0x7E4910
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetASClassName(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::String *className)
{
  Scaleform::String::operator=(className, "flash.display.Bitmap");
  return className;
}

// File Line: 94
// RVA: 0x819A70
void __fastcall Scaleform::GFx::AS3::AvmBitmap::SetImage(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::ImageResource *img)
{
  Scaleform::GFx::ImageResource *pObject; // rcx

  if ( img )
    Scaleform::Render::RenderBuffer::AddRef(img);
  pObject = this->pImage.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pImage.pObject = img;
}

