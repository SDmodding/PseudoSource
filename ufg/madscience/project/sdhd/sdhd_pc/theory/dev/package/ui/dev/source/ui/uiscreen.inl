// File Line: 112
// RVA: 0x5C3980
bool __fastcall UFG::UIScreen::isDimmed(UFG::UIScreen *this)
{
  return this->mDimType && this->mCurDimDirection == 0.0;
}

// File Line: 122
// RVA: 0x5C39A0
bool __fastcall UFG::UIScreen::isDimming(UFG::UIScreen *this)
{
  return this->mCurDimDirection < 0.0;
}

// File Line: 132
// RVA: 0x5C39B0
bool __fastcall UFG::UIScreen::isUnDimming(UFG::UIScreen *this)
{
  return this->mCurDimDirection > 0.0;
}

