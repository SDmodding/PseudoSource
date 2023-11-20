// File Line: 201
// RVA: 0x303690
void __fastcall UFG::ProgressionTracker::SetLastUsedVehicle(UFG::ProgressionTracker *this, UFG::SimObjectVehicle *vehicle)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mLastUsedVehicle.mPrev;
  if ( this->mLastUsedVehicle.m_pPointer )
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

