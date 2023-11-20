// File Line: 44
// RVA: 0x4C9EF0
void __fastcall UFG::SectionChooser::Lookahead::Lookahead(UFG::SectionChooser::Lookahead *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  this->mEnabled = 1;
  this->vfptr = (UFG::SectionChooser::LookaheadVtbl *)&UFG::SectionChooser::Lookahead::`vftable;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->mViewerPosition.x = UFG::qVector3::msZero.x;
  this->mViewerPosition.y = v1;
  this->mViewerPosition.z = v2;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mViewerDirection.x = UFG::qVector3::msZero.x;
  this->mViewerDirection.y = v3;
  this->mViewerDirection.z = v4;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->mViewerVelocity.x = UFG::qVector3::msZero.x;
  this->mViewerVelocity.y = v5;
  this->mViewerVelocity.z = v6;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->mCurrentLookaheadPos.x = UFG::qVector3::msZero.x;
  this->mCurrentLookaheadPos.y = v7;
  this->mCurrentLookaheadPos.z = v8;
  this->mCurrentLookaheadDistance = 0.0;
}

