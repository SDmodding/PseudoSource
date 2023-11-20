// File Line: 32
// RVA: 0x3B5490
void __fastcall ConstructNetSequence::Visit(ConstructNetSequence *this, PoseNodeParent *node)
{
  int *v2; // rsi
  ConstructNetSequence *v3; // rdi
  UFG::qNode<PoseNode,PoseNode> **i; // rbx

  ++this->mNetPoseSequence;
  v2 = &node->mNetPoseSequence;
  node->mNetPoseSequence = LOWORD(this->mNetPoseSequence);
  v3 = this;
  if ( this->mRecurse )
  {
    for ( i = &node->mChildren.mNode.mNext[-3].mNext; i != (UFG::qNode<PoseNode,PoseNode> **)v2; i = &i[6][-3].mNext )
      ((void (__fastcall *)(UFG::qNode<PoseNode,PoseNode> **, ConstructNetSequence *))(*i)[5].mPrev)(i, v3);
  }
}

// File Line: 45
// RVA: 0x3B5480
void __fastcall ConstructNetSequence::Visit(ConstructNetSequence *this, AnimationNode *node)
{
  ++this->mNetPoseSequence;
  node->mNetPoseSequence = LOWORD(this->mNetPoseSequence);
}

