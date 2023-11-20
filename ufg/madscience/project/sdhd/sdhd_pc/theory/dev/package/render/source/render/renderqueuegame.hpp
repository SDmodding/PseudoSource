// File Line: 24
// RVA: 0x612D0
void __fastcall RenderQueueTreeNode::RenderQueueTreeNode(RenderQueueTreeNode *this, unsigned int uid)
{
  Illusion::RenderQueue *v2; // [rsp+60h] [rbp+18h]
  UFG::qList<Illusion::QueueCommandBucket,Illusion::QueueCommandBucket,1,0> *v3; // [rsp+68h] [rbp+20h]

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  v2 = &this->mRenderQueue;
  v2->mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&v2->mPrev;
  v3 = &this->mRenderQueue.mBuckets;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  UFG::qMemSet(this->mRenderQueue.mStateValues.mParamValues, 0, 0x400u);
  v2->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  v2->mStateValues.mSetValueMask.mFlags[0] = 0i64;
  v2->mState = 0;
  v2->mFreeBucket = 0i64;
  v2->mPlatData0 = 0i64;
  v2->mPlatData1 = 0i64;
  v2->mUserData = 0i64;
  *(_QWORD *)&v2->mCommandCount = 0i64;
}

