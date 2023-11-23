// File Line: 158
// RVA: 0x59CD00
UFG::qSharedString *__fastcall UFG::GameSlice::GetAudioName(UFG::GameSlice *this, UFG::qSharedString *result)
{
  UFG::qSharedString *p_mAudioOverride; // rdi
  UFG::qSharedStringData *v5; // rbx

  p_mAudioOverride = &this->mAudioOverride;
  v5 = (UFG::qSharedStringData *)(this->mAudioOverride.mText - 48);
  if ( v5 == UFG::qSharedStringData::GetEmptyString() )
    p_mAudioOverride = &this->mName;
  UFG::qSharedString::qSharedString(result, p_mAudioOverride);
  return result;
}

// File Line: 314
// RVA: 0x4ABF00
_BOOL8 __fastcall UFG::GameSlice::IsDeferredRestartIfInsideRegion(UFG::GameSlice *this)
{
  if ( this->mpParent )
    return UFG::GameSlice::IsDeferredRestartIfInsideRegion(this->mpParent);
  else
    return this->mDeferRestartIfInsideRegion != 0;
}

// File Line: 341
// RVA: 0x4BD0A0
void __fastcall UFG::GameSlice::SetRestoreVehicle(UFG::GameSlice *this, UFG::SimObject *vehicle)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpRestoredVehicle; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mpRestoredVehicle = &this->mpRestoredVehicle;
  if ( this->mpRestoredVehicle.m_pPointer )
  {
    mPrev = p_mpRestoredVehicle->mPrev;
    mNext = p_mpRestoredVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpRestoredVehicle->mPrev = p_mpRestoredVehicle;
    p_mpRestoredVehicle->mNext = p_mpRestoredVehicle;
  }
  p_mpRestoredVehicle->m_pPointer = vehicle;
  if ( vehicle )
  {
    v5 = vehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v5->mNext = p_mpRestoredVehicle;
    p_mpRestoredVehicle->mPrev = v5;
    p_mpRestoredVehicle->mNext = &vehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    vehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpRestoredVehicle;
  }
}

