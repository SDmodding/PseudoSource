// File Line: 127
// RVA: 0xBE530
float __fastcall UFG::UIMapBlipGraphic::AltitudeIconRange(UFG::UIMapBlipGraphic *this)
{
  return FLOAT_200_0;
}

// File Line: 162
// RVA: 0xBBA00
void __fastcall UFG::UIMapBlipGraphicCop::UIMapBlipGraphicCop(UFG::UIMapBlipGraphicCop *this)
{
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  this->mIconPoly.Size = 10.0;
  this->mIconPoly.Matrix = 0i64;
  this->mIconPoly.Scale = 1.0;
  this->mIconPoly.Visible = 0;
  this->mPolys[0] = &this->mIconPoly;
  this->mPolys[1] = 0i64;
  this->mPolys[2] = 0i64;
  this->mPolys[3] = 0i64;
  this->mPolys[4] = 0i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphicCop::`vftable;
  *(_QWORD *)&this->mFrameCount = 0i64;
  this->mColor = UFG::qColour::DogerBlue;
}

// File Line: 182
// RVA: 0xBE540
float __fastcall UFG::UIMapBlipGraphicEventObjective::AltitudeIconRange(UFG::UIMapBlipGraphicMissionObjective *this)
{
  return FLOAT_100_0;
}

// File Line: 214
// RVA: 0xBBDC0
void __fastcall UFG::UIMapBlipGraphicWitness::UIMapBlipGraphicWitness(UFG::UIMapBlipGraphicWitness *this)
{
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphic::`vftable;
  this->mAnimateBlink = 0;
  *(_QWORD *)&this->mBlinkScale = 1065353216i64;
  this->mBlinkTimesMax = 5;
  this->mIconPoly.Size = 10.0;
  this->mIconPoly.Matrix = 0i64;
  this->mIconPoly.Scale = 1.0;
  this->mIconPoly.Visible = 0;
  this->mPolys[0] = &this->mIconPoly;
  this->mPolys[1] = 0i64;
  this->mPolys[2] = 0i64;
  this->mPolys[3] = 0i64;
  this->mPolys[4] = 0i64;
  this->vfptr = (UFG::UIMapBlipGraphicVtbl *)&UFG::UIMapBlipGraphicWitness::`vftable;
  this->mAlpha = 1.0;
  this->mPulse = 0;
}

// File Line: 218
// RVA: 0xCB410
void __fastcall UFG::UIMapBlipGraphicWitness::SetPulse(UFG::UIMapBlipGraphicWitness *this)
{
  this->mPulse = 1;
}

