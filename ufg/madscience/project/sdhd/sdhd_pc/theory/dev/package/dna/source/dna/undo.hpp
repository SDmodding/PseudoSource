// File Line: 54
// RVA: 0x1A4260
void __fastcall DNA::IAction::~IAction(DNA::IAction *this)
{
  UFG::qNode<DNA::IAction,DNA::IAction> *v1; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *v2; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v3; // rax

  this->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  v1 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 80
// RVA: 0x1AAC00
void __fastcall DNA::Transaction::~Transaction(DNA::Transaction *this)
{
  DNA::Transaction *v1; // rdi
  UFG::qList<DNA::IAction,DNA::IAction,1,0> *v2; // rbx
  UFG::qNode<DNA::IAction,DNA::IAction> *v3; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v4; // rax
  UFG::qNode<DNA::IAction,DNA::IAction> *v5; // rdx
  UFG::qNode<DNA::IAction,DNA::IAction> *v6; // rcx
  UFG::qNode<DNA::IAction,DNA::IAction> *v7; // rax

  v1 = this;
  this->vfptr = (DNA::IActionVtbl *)&DNA::Transaction::`vftable;
  v2 = &this->mActions;
  UFG::qList<DNA::IAction,DNA::IAction,1,0>::DeleteNodes(&this->mActions);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->vfptr = (DNA::IActionVtbl *)&DNA::IAction::`vftable;
  v5 = (UFG::qNode<DNA::IAction,DNA::IAction> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

