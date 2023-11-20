// File Line: 50
// RVA: 0x7E77B0
const char *__fastcall Scaleform::GFx::AS3::AvmLoader::GetDefaultASClassName(Scaleform::GFx::AS3::AvmLoader *this)
{
  return "flash.display.Loader";
}

// File Line: 52
// RVA: 0x7E49C0
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmLoader::GetASClassName(Scaleform::GFx::AS3::AvmLoader *this, Scaleform::String *className)
{
  Scaleform::String *v2; // rbx

  v2 = className;
  Scaleform::String::operator=(className, "flash.display.Loader");
  return v2;
}

