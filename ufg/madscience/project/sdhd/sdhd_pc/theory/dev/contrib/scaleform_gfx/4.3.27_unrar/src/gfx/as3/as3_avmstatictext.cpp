// File Line: 24
// RVA: 0x77B220
void __fastcall Scaleform::GFx::AS3::AvmStaticText::AvmStaticText(Scaleform::GFx::AS3::AvmStaticText *this, Scaleform::GFx::StaticTextCharacter *pch)
{
  Scaleform::GFx::AS3::AvmStaticText *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr,
    (Scaleform::GFx::DisplayObject *)&pch->vfptr);
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmStaticText::`vftable;
}

