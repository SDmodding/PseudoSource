// File Line: 54
// RVA: 0x1A4260
void __fastcall DNA::IAction::~IAction(DNA::IAction *this)
{
  UFG::qNode<DNA::IAction,DNA::IAction> *v1; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *mPrev; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *mNext; // rax

  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  v1 = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 80
// RVA: 0x1AAC00
void __fastcall DNA::Transaction::~Transaction(DNA::Transaction *this)
{
  UFG::qList<DNA::IAction,DNA::IAction,1,0> *p_mActions; // rbx
  UFG::qNode<DNA::IAction,DNA::IAction> *mPrev; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *mNext; // rax
  UFG::qNode<DNA::IAction,DNA::IAction> *v5; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v6; // rax

  this->vfptr = (DNA::IActionVtbl *)&DNA::Transaction::`vftable;
  p_mActions = &this->mActions;
  UFG::qList<DNA::IAction,DNA::IAction,1,0>::DeleteNodes(&this->mActions);
  mPrev = p_mActions->mNode.mPrev;
  mNext = p_mActions->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mActions->mNode.mPrev = &p_mActions->mNode;
  p_mActions->mNode.mNext = &p_mActions->mNode;
  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  v5 = this->mPrev;
  v6 = this->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPrev = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
  this->mNext = &this->UFG::qNode<DNA::IAction,DNA::IAction>;
}

