// File Line: 53
// RVA: 0x4CB520
void __fastcall UFG::InteriorTriggerProperties::InteriorTriggerProperties(UFG::InteriorTriggerProperties *this)
{
  *(_QWORD *)&this->mTriggerName.mUID = -1i64;
  this->mEnvironment.mUID = -1;
  this->mEnterEnvironment.mUID = -1;
  this->mExitEnvironment.mUID = -1;
  this->mPhysicsActiveRegionMode.mUID = -1;
  UFG::qString::qString(&this->mCameraContextOverrideTow);
  UFG::qString::qString(&this->mCameraContextLocalOverrideTow);
}

// File Line: 54
// RVA: 0x4CBD30
void __fastcall UFG::InteriorTriggerProperties::~InteriorTriggerProperties(UFG::InteriorTriggerProperties *this)
{
  UFG::qString::~qString(&this->mCameraContextLocalOverrideTow);
  UFG::qString::~qString(&this->mCameraContextOverrideTow);
}

