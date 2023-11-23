// File Line: 25
// RVA: 0x429170
void __fastcall UFG::OSuiteMessage::~OSuiteMessage(UFG::OSuiteMessage *this)
{
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *v1; // rdx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage> *mNext; // rax

  this->vfptr = (UFG::OSuiteMessageVtbl *)&UFG::OSuiteMessage::`vftable;
  v1 = &this->UFG::qNode<UFG::OSuiteMessage,UFG::OSuiteMessage>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

