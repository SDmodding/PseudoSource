// File Line: 103
// RVA: 0x34F400
void __fastcall UFG::SidewalkWanderData::ClearDestination(UFG::SidewalkWanderData *this)
{
  UFG::SidewalkWanderData *v1; // rdi
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4

  v1 = this;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mGoals[0].mpDestinationNode);
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mGoals[0].mPosition.x = UFG::qVector3::msZero.x;
  v1->mGoals[0].mPosition.y = v2;
  v1->mGoals[0].mPosition.z = v3;
  v1->mGoals[0].mGoalId = -1;
  v1->mGoals[0].mIsValid = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v1->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mGoals[1].mpDestinationNode);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  v1->mGoals[1].mPosition.y = v4;
  v1->mGoals[1].mPosition.z = v5;
  v1->mGoals[1].mGoalId = -1;
  v1->mGoals[1].mIsValid = 0;
  v1->mPreviousDesiredDirectionValid = 0;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v1->mPreviousDesiredDirection.x = UFG::qVector3::msZero.x;
  v1->mPreviousDesiredDirection.y = v6;
  v1->mPreviousDesiredDirection.z = v7;
}

// File Line: 108
// RVA: 0x34F650
void __fastcall UFG::SidewalkWanderData::ClearLookAheadDestination(UFG::SidewalkWanderData *this)
{
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1];
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v1 + 1);
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  *(float *)&v1[2].mPrev = UFG::qVector3::msZero.x;
  *((float *)&v1[2].mPrev + 1) = v2;
  *(float *)&v1[2].mNext = v3;
  HIDWORD(v1[2].mNext) = -1;
  LOBYTE(v1[2].mData) = 0;
}

