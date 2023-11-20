// File Line: 158
// RVA: 0x59CD00
UFG::qSharedString *__fastcall UFG::GameSlice::GetAudioName(UFG::GameSlice *this, UFG::qSharedString *result)
{
  UFG::qSharedString *v2; // rsi
  UFG::GameSlice *v3; // rbp
  UFG::qSharedString *v4; // rdi
  UFG::qSharedStringData *v5; // rbx

  v2 = result;
  v3 = this;
  v4 = &this->mAudioOverride;
  v5 = (UFG::qSharedStringData *)(this->mAudioOverride.mText - 48);
  if ( v5 == UFG::qSharedStringData::GetEmptyString() )
    v4 = &v3->mName;
  UFG::qSharedString::qSharedString(v2, v4);
  return v2;
}

// File Line: 314
// RVA: 0x4ABF00
_BOOL8 __fastcall UFG::GameSlice::IsDeferredRestartIfInsideRegion(UFG::GameSlice *this)
{
  _BOOL8 result; // rax

  if ( this->mpParent )
    result = UFG::GameSlice::IsDeferredRestartIfInsideRegion(this->mpParent);
  else
    result = this->mDeferRestartIfInsideRegion != 0;
  return result;
}

// File Line: 341
// RVA: 0x4BD0A0
void __fastcall UFG::GameSlice::SetRestoreVehicle(UFG::GameSlice *this, UFG::SimObject *vehicle)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpRestoredVehicle.mPrev;
  if ( this->mpRestoredVehicle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)vehicle;
  if ( vehicle )
  {
    v5 = vehicle->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &vehicle->m_SafePointerList.mNode;
    vehicle->m_SafePointerList.mNode.mPrev = v2;
  }
}

