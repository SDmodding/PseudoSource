// File Line: 16
// RVA: 0x2DD940
void __fastcall UFG::AnimatedEvent::AnimatedEvent(UFG::AnimatedEvent *this, const char *name, UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *object)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rbx
  UFG::AnimatedEvent *v4; // rdi
  UFG::qNode<UFG::Event,UFG::Event> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::SimObject *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v3 = object;
  v4 = this;
  v5 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  v4->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable';
  v6 = &v4->pSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v7 = v3->m_pPointer;
  v4->pSimObject.m_pPointer = v7;
  if ( v7 )
  {
    v8 = &v7->m_SafePointerList.mNode;
    v9 = v8->mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v4->pSimObject.mNext = v8;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

