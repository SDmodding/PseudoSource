// File Line: 36
// RVA: 0x48D810
void __fastcall UFG::ScoreAffector::ScoreAffector(UFG::ScoreAffector *this)
{
  this->mPoints = 0.0;
  *(_QWORD *)&this->mCurrentMultiplier = 1065353216i64;
  *(_QWORD *)&this->mMultiplierReduction = 0i64;
  this->mTimestamp = 0i64;
  this->mIsActive = 0;
  UFG::qString::qString(&this->mCaption);
}

// File Line: 38
// RVA: 0x491480
void __fastcall UFG::ScoreAffector::~ScoreAffector(UFG::ScoreAffector *this)
{
  UFG::qString::~qString(&this->mCaption);
}

// File Line: 79
// RVA: 0x51EED0
UFG::ComponentIDDesc *__fastcall UFG::FaceMeterComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::FaceMeterComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::FaceMeterComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::FaceMeterComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::FaceMeterComponent::_DescInit = 1;
    UFG::FaceMeterComponent::_TypeUID = UFG::FaceMeterComponent::_TypeIDesc.mChildBitMask | (UFG::FaceMeterComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::FaceMeterComponent::_FaceMeterComponentTypeUID = UFG::FaceMeterComponent::_TypeIDesc.mChildBitMask | (UFG::FaceMeterComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::FaceMeterComponent::_TypeIDesc;
}

