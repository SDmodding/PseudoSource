// File Line: 54
// RVA: 0x7E7760
const char *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetDefaultASClassName(Scaleform::GFx::AS3::AvmBitmap *this)
{
  return "flash.display.Bitmap";
}

// File Line: 56
// RVA: 0x7E4910
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmBitmap::GetASClassName(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::String *className)
{
  Scaleform::String *v2; // rbx

  v2 = className;
  Scaleform::String::operator=(className, "flash.display.Bitmap");
  return v2;
}

// File Line: 94
// RVA: 0x819A70
void __fastcall Scaleform::GFx::AS3::AvmBitmap::SetImage(Scaleform::GFx::AS3::AvmBitmap *this, Scaleform::GFx::ImageResource *img)
{
  Scaleform::GFx::ImageResource *v2; // rbx
  Scaleform::GFx::AS3::AvmBitmap *v3; // rdi
  Scaleform::GFx::Resource *v4; // rcx

  v2 = img;
  v3 = this;
  if ( img )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&img->vfptr);
  v4 = (Scaleform::GFx::Resource *)&v3->pImage.pObject->vfptr;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v3->pImage.pObject = v2;
}

