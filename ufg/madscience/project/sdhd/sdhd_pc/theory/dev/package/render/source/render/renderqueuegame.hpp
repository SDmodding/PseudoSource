// File Line: 24
// RVA: 0x612D0
void __fastcall RenderQueueTreeNode::RenderQueueTreeNode(RenderQueueTreeNode *this, unsigned int uid)
{
  Illusion::RenderQueue *p_mRenderQueue; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  p_mRenderQueue = &this->mRenderQueue;
  this->mRenderQueue.mPrev = &this->mRenderQueue;
  this->mRenderQueue.mNext = &this->mRenderQueue;
  this->mRenderQueue.mBuckets.mNode.mPrev = &this->mRenderQueue.mBuckets.mNode;
  this->mRenderQueue.mBuckets.mNode.mNext = &this->mRenderQueue.mBuckets.mNode;
  UFG::qMemSet(this->mRenderQueue.mStateValues.mParamValues, 0, 0x400u);
  p_mRenderQueue->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  p_mRenderQueue->mStateValues.mSetValueMask.mFlags[0] = 0i64;
  p_mRenderQueue->mState = 0;
  p_mRenderQueue->mFreeBucket = 0i64;
  p_mRenderQueue->mPlatData0 = 0i64;
  p_mRenderQueue->mPlatData1 = 0i64;
  p_mRenderQueue->mUserData = 0i64;
  *(_QWORD *)&p_mRenderQueue->mCommandCount = 0i64;
}

