// File Line: 81
// RVA: 0x376E0
void __fastcall UFG::ShadowRenderQueueTaskResults::ShadowRenderQueueTaskResults(
        UFG::ShadowRenderQueueTaskResults *this)
{
  UFG::qTaskGroup **mCascadeTaskGroups; // rdx
  $841545914FC682C9D9C2D70337586AAF *mShadowsBucketIndices; // rax
  __int64 v4; // rcx

  `eh vector constructor iterator(
    this,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))ShadowRenderQueueResults::ShadowRenderQueueResults);
  this->mNumCascades = 0;
  mCascadeTaskGroups = this->mCascadeTaskGroups;
  mShadowsBucketIndices = this->mShadowsBucketIndices;
  v4 = 4i64;
  do
  {
    mShadowsBucketIndices->bucket_index = 0;
    *mCascadeTaskGroups = 0i64;
    ++mShadowsBucketIndices;
    ++mCascadeTaskGroups;
    --v4;
  }
  while ( v4 );
}

// File Line: 104
// RVA: 0x375F0
void __fastcall UFG::ShadowRenderQueueSimResults::ShadowRenderQueueSimResults(UFG::ShadowRenderQueueSimResults *this)
{
  `eh vector constructor iterator(
    this->mCompositeDrawableCascades,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  this->mDownsampleShadows.mNode.mPrev = &this->mDownsampleShadows.mNode;
  this->mDownsampleShadows.mNode.mNext = &this->mDownsampleShadows.mNode;
  `eh vector constructor iterator(
    this->mCollector,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  this->mCharacterShadows.mNode.mPrev = &this->mCharacterShadows.mNode;
  this->mCharacterShadows.mNode.mNext = &this->mCharacterShadows.mNode;
  this->mCloudShadows.mNode.mPrev = &this->mCloudShadows.mNode;
  this->mCloudShadows.mNode.mNext = &this->mCloudShadows.mNode;
  this->mPreShadowPass.mNode.mPrev = &this->mPreShadowPass.mNode;
  this->mPreShadowPass.mNode.mNext = &this->mPreShadowPass.mNode;
  this->mPostShadowPass.mNode.mPrev = &this->mPostShadowPass.mNode;
  this->mPostShadowPass.mNode.mNext = &this->mPostShadowPass.mNode;
  this->mDynamicInstances[0] = 0i64;
  this->mDynamicInstances[1] = 0i64;
  this->mDynamicInstances[2] = 0i64;
  this->mDynamicInstances[3] = 0i64;
}

