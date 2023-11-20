// File Line: 25
// RVA: 0x429170
void __fastcall UFG::OSuiteMessage::~OSuiteMessage(UFG::OSuiteMessage *this)
{
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v1; // rdx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v2; // rcx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v3; // rax

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable;
  v1 = (UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

