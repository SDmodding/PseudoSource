// File Line: 162
// RVA: 0x516EB0
void __fastcall UFG::EvtEntityDied::EvtEntityDied(UFG::EvtEntityDied *this, const char *name, UFG::SimObject *pObject)
{
  UFG::SimObject *v3; // rdi
  UFG::EvtEntityDied *v4; // rbx
  UFG::qNode<UFG::Event,UFG::Event> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  v3 = pObject;
  v4 = this;
  v5 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
  v4->vfptr = (UFG::EventVtbl *)&UFG::EvtEntityDied::`vftable';
  v6 = &v4->pSimObject;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->pSimObject.m_pPointer = v3;
  if ( v3 )
  {
    v7 = v3->m_SafePointerList.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v7;
    v4->pSimObject.mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

