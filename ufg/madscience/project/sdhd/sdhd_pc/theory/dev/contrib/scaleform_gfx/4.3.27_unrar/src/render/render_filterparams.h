// File Line: 90
// RVA: 0x77B800
void __fastcall Scaleform::Render::BlurFilterParams::BlurFilterParams(Scaleform::Render::BlurFilterParams *this)
{
  this->Mode = 0;
  this->Passes = 1;
  this->BlurX = 100.0;
  *(_QWORD *)&this->BlurY = 1120403456i64;
  this->Offset.y = 0.0;
  this->Strength = 1.0;
  this->Gradient.pObject = 0i64;
  *(_DWORD *)&this->Colors[0].Channels.Green = 16711680;
  this->Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Colors[1].Channels.Green = 0;
  this->Colors[1].Channels.Alpha = 0;
}

// File Line: 119
// RVA: 0x8C8AE0
bool __fastcall Scaleform::Render::BlurFilterParams::EqualsAll(
        Scaleform::Render::BlurFilterParams *this,
        Scaleform::Render::BlurFilterParams *b)
{
  return this->Mode == b->Mode
      && b->BlurX == this->BlurX
      && b->BlurY == this->BlurY
      && this->Passes == b->Passes
      && b->Offset.x == this->Offset.x
      && b->Offset.y == this->Offset.y
      && b->Strength == this->Strength
      && this->Colors[0].Raw == b->Colors[0].Raw
      && this->Colors[1].Raw == b->Colors[1].Raw;
}

