// File Line: 75
// RVA: 0x2AB20
void __fastcall UFG::SpotShadowRenderQueueTaskResults::SpotShadowRenderQueueTaskResults(
        UFG::SpotShadowRenderQueueTaskResults *this)
{
  UFG::qTaskGroup **mSpotShadowTaskGroups; // rcx
  $841545914FC682C9D9C2D70337586AAF *mShadowsBucketIndices; // rax
  __int64 v4; // rdx

  `eh vector constructor iterator(
    this,
    0x20ui64,
    32,
    (void (__fastcall *)(void *))ShadowRenderQueueResults::ShadowRenderQueueResults);
  this->mNumActiveSpotShadows = 0;
  mSpotShadowTaskGroups = this->mSpotShadowTaskGroups;
  mShadowsBucketIndices = this->mShadowsBucketIndices;
  v4 = 8i64;
  do
  {
    mShadowsBucketIndices->bucket_index = 0;
    *mSpotShadowTaskGroups = 0i64;
    ++mShadowsBucketIndices;
    ++mSpotShadowTaskGroups;
    --v4;
  }
  while ( v4 );
}

// File Line: 92
// RVA: 0x2AAA0
void __fastcall UFG::SpotShadowRenderQueueSimResults::SpotShadowRenderQueueSimResults(
        UFG::SpotShadowRenderQueueSimResults *this)
{
  `eh vector constructor iterator(
    this->mCompositeDrawableSpotShadows,
    0x10ui64,
    8,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  this->mDynamicInstances[0] = 0i64;
  this->mDynamicInstances[1] = 0i64;
  this->mDynamicInstances[2] = 0i64;
  this->mDynamicInstances[3] = 0i64;
  this->mDynamicInstances[4] = 0i64;
  this->mDynamicInstances[5] = 0i64;
  this->mDynamicInstances[6] = 0i64;
  this->mDynamicInstances[7] = 0i64;
}

