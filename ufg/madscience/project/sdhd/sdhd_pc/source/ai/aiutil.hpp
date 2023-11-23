// File Line: 162
// RVA: 0x516EB0
void __fastcall UFG::EvtEntityDied::EvtEntityDied(UFG::EvtEntityDied *this, const char *name, UFG::SimObject *pObject)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax

  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  this->vfptr = (UFG::EventVtbl *)&UFG::EvtEntityDied::`vftable;
  p_pSimObject = &this->pSimObject;
  this->pSimObject.mPrev = &this->pSimObject;
  this->pSimObject.mNext = &this->pSimObject;
  this->pSimObject.m_pPointer = pObject;
  if ( pObject )
  {
    mPrev = pObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    mPrev->mNext = p_pSimObject;
    p_pSimObject->mPrev = mPrev;
    this->pSimObject.mNext = &pObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pSimObject;
  }
}

