// File Line: 65
// RVA: 0x1A82C0
void __fastcall DNA::IQueryNode::~IQueryNode(DNA::IQueryNode *this)
{
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v1; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mPrev; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *mNext; // rax

  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  v1 = &this->UFG::qNode<DNA::IQueryNode,DNA::IQueryNode>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

