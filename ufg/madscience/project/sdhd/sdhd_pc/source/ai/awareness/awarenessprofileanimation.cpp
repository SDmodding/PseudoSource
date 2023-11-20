// File Line: 21
// RVA: 0x39A840
void __fastcall UFG::AIAwareness::SubProfileAnimation::Clear(UFG::AIAwareness::SubProfileAnimation *this)
{
  *(_WORD *)&this->mEnableHeadTrack = 0;
  this->mEnableSpineTrack = 0;
}

