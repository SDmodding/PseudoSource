// File Line: 65
// RVA: 0x1A82C0
void __fastcall DNA::IQueryNode::~IQueryNode(DNA::IQueryNode *this)
{
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v1; // rdx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v2; // rcx
  UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *v3; // rax

  this->vfptr = (DNA::IQueryNodeVtbl *)&DNA::IQueryNode::`vftable;
  v1 = (UFG::qNode<DNA::IQueryNode,DNA::IQueryNode> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

