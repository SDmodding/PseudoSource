// File Line: 201
// RVA: 0x303690
void __fastcall UFG::ProgressionTracker::SetLastUsedVehicle(
        UFG::ProgressionTracker *this,
        UFG::SimObjectVehicle *vehicle)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mLastUsedVehicle; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mLastUsedVehicle = &this->mLastUsedVehicle;
  if ( this->mLastUsedVehicle.m_pPointer )
  {
    mPrev = p_mLastUsedVehicle->mPrev;
    mNext = p_mLastUsedVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastUsedVehicle->mPrev = p_mLastUsedVehicle;
    p_mLastUsedVehicle->mNext = p_mLastUsedVehicle;
  }
  p_mLastUsedVehicle->m_pPointer = vehicle;
  if ( vehicle )
  {
    v5 = vehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mLastUsedVehicle;
    p_mLastUsedVehicle->mPrev = v5;
    p_mLastUsedVehicle->mNext = &vehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    vehicle->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLastUsedVehicle;
  }
}

