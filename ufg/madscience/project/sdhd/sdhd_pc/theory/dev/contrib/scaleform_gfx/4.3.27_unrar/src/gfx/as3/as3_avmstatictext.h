// File Line: 36
// RVA: 0x7E77F0
const char *__fastcall Scaleform::GFx::AS3::AvmStaticText::GetDefaultASClassName(Scaleform::GFx::AS3::AvmStaticText *this)
{
  return "flash.text.StaticText";
}

// File Line: 38
// RVA: 0x7E49F0
Scaleform::String *__fastcall Scaleform::GFx::AS3::AvmStaticText::GetASClassName(Scaleform::GFx::AS3::AvmStaticText *this, Scaleform::String *className)
{
  Scaleform::String *v2; // rbx

  v2 = className;
  Scaleform::String::operator=(className, "flash.text.StaticText");
  return v2;
}

