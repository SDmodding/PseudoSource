// File Line: 16
// RVA: 0x2DD940
void __fastcall UFG::AnimatedEvent::AnimatedEvent(
        UFG::AnimatedEvent *this,
        const char *name,
        UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *object)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pSimObject; // rdx
  UFG::SimObject *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax

  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  this->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable;
  p_pSimObject = &this->pSimObject;
  this->pSimObject.mPrev = &this->pSimObject;
  this->pSimObject.mNext = &this->pSimObject;
  m_pPointer = object->m_pPointer;
  this->pSimObject.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    p_mNode = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    mPrev = p_mNode->mPrev;
    mPrev->mNext = p_pSimObject;
    p_pSimObject->mPrev = mPrev;
    this->pSimObject.mNext = p_mNode;
    p_mNode->mPrev = p_pSimObject;
  }
}

