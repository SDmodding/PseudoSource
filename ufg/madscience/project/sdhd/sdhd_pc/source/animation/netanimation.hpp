// File Line: 32
// RVA: 0x3B5490
void __fastcall ConstructNetSequence::Visit(ConstructNetSequence *this, PoseNodeParent *node)
{
  int *p_mNetPoseSequence; // rsi
  int *i; // rbx

  ++this->mNetPoseSequence;
  p_mNetPoseSequence = &node->mNetPoseSequence;
  node->mNetPoseSequence = LOWORD(this->mNetPoseSequence);
  if ( this->mRecurse )
  {
    for ( i = (int *)&node->mChildren.mNode.mNext[-3].mNext;
          i != p_mNetPoseSequence;
          i = (int *)(*((_QWORD *)i + 6) - 40i64) )
    {
      (*(void (__fastcall **)(int *, ConstructNetSequence *))(*(_QWORD *)i + 80i64))(i, this);
    }
  }
}

// File Line: 45
// RVA: 0x3B5480
void __fastcall ConstructNetSequence::Visit(ConstructNetSequence *this, AnimationNode *node)
{
  ++this->mNetPoseSequence;
  node->mNetPoseSequence = LOWORD(this->mNetPoseSequence);
}

