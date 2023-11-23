// File Line: 103
// RVA: 0x34F400
void __fastcall UFG::SidewalkWanderData::ClearDestination(UFG::SidewalkWanderData *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4

  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&this->mGoals[0].mpDestinationNode);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mGoals[0].mPosition.x = UFG::qVector3::msZero.x;
  this->mGoals[0].mPosition.y = y;
  this->mGoals[0].mPosition.z = z;
  this->mGoals[0].mGoalId = -1;
  this->mGoals[0].mIsValid = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&this->mGoals[1].mpDestinationNode);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  this->mGoals[1].mPosition.y = v4;
  this->mGoals[1].mPosition.z = v5;
  this->mGoals[1].mGoalId = -1;
  this->mGoals[1].mIsValid = 0;
  this->mPreviousDesiredDirectionValid = 0;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->mPreviousDesiredDirection.x = UFG::qVector3::msZero.x;
  this->mPreviousDesiredDirection.y = v6;
  this->mPreviousDesiredDirection.z = v7;
}

// File Line: 108
// RVA: 0x34F650
void __fastcall UFG::SidewalkWanderData::ClearLookAheadDestination(UFG::SidewalkWanderData *this)
{
  UFG::SidewalkWanderData::GoalInfo *v1; // rbx
  float y; // xmm1_4
  float z; // xmm2_4

  v1 = &this->mGoals[1];
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mpDestinationNode);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v1->mPosition.x = UFG::qVector3::msZero.x;
  v1->mPosition.y = y;
  v1->mPosition.z = z;
  v1->mGoalId = -1;
  v1->mIsValid = 0;
}

