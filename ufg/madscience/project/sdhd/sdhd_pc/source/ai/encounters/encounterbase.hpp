// File Line: 68
// RVA: 0x3EF500
_BOOL8 __fastcall UFG::EncounterBase::IsFocusTargetOnMeshHeuristic(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mIsOnMeshHeuristic;
}

// File Line: 69
// RVA: 0x3EF4F0
_BOOL8 __fastcall UFG::EncounterBase::IsFocusTargetInsideInterior(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mIsInsideInterior;
}

// File Line: 70
// RVA: 0x3EF4E0
_BOOL8 __fastcall UFG::EncounterBase::IsFocusTargetInWater(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mIsInWater;
}

// File Line: 71
// RVA: 0x3EF0B0
_BOOL8 __fastcall UFG::EncounterBase::HasFocusTargetOpenedFired(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mOpenFired;
}

// File Line: 72
// RVA: 0x3EF0C0
_BOOL8 __fastcall UFG::EncounterBase::HasFocusTargetOpenedFiredWithHostage(UFG::EncounterBase *this)
{
  return this->mFocusTargetContext.mOpenFiredWithHostage;
}

// File Line: 73
// RVA: 0x3EF4D0
bool __fastcall UFG::EncounterBase::IsExecutingReducedRadiusMode(UFG::EncounterBase *this)
{
  return this->mReducedRadiusTimer > 0.0;
}

// File Line: 77
// RVA: 0x3ED7C0
UFG::SimObject *__fastcall UFG::EncounterBase::GetFocusTarget(UFG::EncounterBase *this)
{
  return this->mpFocusTarget.m_pPointer;
}

// File Line: 78
// RVA: 0x3F0500
void __fastcall UFG::EncounterBase::SetFocusTarget(UFG::EncounterBase *this, UFG::SimObject *pTarget)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpFocusTarget; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mpFocusTarget = &this->mpFocusTarget;
  if ( this->mpFocusTarget.m_pPointer )
  {
    mPrev = p_mpFocusTarget->mPrev;
    mNext = p_mpFocusTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpFocusTarget->mPrev = p_mpFocusTarget;
    p_mpFocusTarget->mNext = p_mpFocusTarget;
  }
  p_mpFocusTarget->m_pPointer = pTarget;
  if ( pTarget )
  {
    v5 = pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mpFocusTarget;
    p_mpFocusTarget->mPrev = v5;
    p_mpFocusTarget->mNext = &pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpFocusTarget;
  }
}

// File Line: 79
// RVA: 0x3ED7D0
UFG::qVector3 *__fastcall UFG::EncounterBase::GetFocusTargetPosition(UFG::EncounterBase *this)
{
  return &this->mFocusTargetPosition;
}

// File Line: 81
// RVA: 0x3EDBC0
UFG::SimObject *__fastcall UFG::EncounterBase::GetSecondaryTarget(UFG::EncounterBase *this)
{
  return this->mpSecondaryTarget.m_pPointer;
}

// File Line: 89
// RVA: 0x3ED6C0
ANamed *__fastcall ActionNodeImplementation::GetChildList(SSActor *this)
{
  return &this->ANamed;
}

// File Line: 96
// RVA: 0x3EDBD0
__int64 __fastcall UFG::EncounterBase::GetSpawnCount(UFG::EncounterBase *this)
{
  return (unsigned int)(this->mVehicleSpawnCount + this->mCharacterSpawnCount);
}

// File Line: 97
// RVA: 0x3EDB90
__int64 __fastcall UFG::EncounterBase::GetKillCount(UFG::EncounterBase *this)
{
  return (unsigned int)(this->mVehicleKillCount + this->mCharacterKillCount);
}

// File Line: 122
// RVA: 0x3ED900
UFG::qPropertySet *__fastcall UFG::EncounterBase::GetHeatLevelProperties(UFG::EncounterBase *this)
{
  __int64 mHeatLevel; // rax

  mHeatLevel = this->mHeatLevel;
  if ( this->mFocusTargetContext.mIsInWater )
    return this->mWaterHeatLevelProperties[mHeatLevel];
  else
    return this->mHeatLevelProperties[mHeatLevel];
}

