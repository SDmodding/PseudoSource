// File Line: 75
// RVA: 0x2AB20
void __fastcall UFG::SpotShadowRenderQueueTaskResults::SpotShadowRenderQueueTaskResults(UFG::SpotShadowRenderQueueTaskResults *this)
{
  UFG::SpotShadowRenderQueueTaskResults *v1; // rbx
  UFG::qTaskGroup **v2; // rcx
  $841545914FC682C9D9C2D70337586AAF *v3; // rax
  signed __int64 v4; // rdx

  v1 = this;
  `eh vector constructor iterator(
    this,
    0x20ui64,
    32,
    (void (__fastcall *)(void *))ShadowRenderQueueResults::ShadowRenderQueueResults);
  v1->mNumActiveSpotShadows = 0;
  v2 = v1->mSpotShadowTaskGroups;
  v3 = v1->mShadowsBucketIndices;
  v4 = 8i64;
  do
  {
    v3->bucket_index = 0;
    *v2 = 0i64;
    ++v3;
    ++v2;
    --v4;
  }
  while ( v4 );
}

// File Line: 92
// RVA: 0x2AAA0
void __fastcall UFG::SpotShadowRenderQueueSimResults::SpotShadowRenderQueueSimResults(UFG::SpotShadowRenderQueueSimResults *this)
{
  UFG::SpotShadowRenderQueueSimResults *v1; // rbx

  v1 = this;
  `eh vector constructor iterator(
    this->mCompositeDrawableSpotShadows,
    0x10ui64,
    8,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  v1->mDynamicInstances[0] = 0i64;
  v1->mDynamicInstances[1] = 0i64;
  v1->mDynamicInstances[2] = 0i64;
  v1->mDynamicInstances[3] = 0i64;
  v1->mDynamicInstances[4] = 0i64;
  v1->mDynamicInstances[5] = 0i64;
  v1->mDynamicInstances[6] = 0i64;
  v1->mDynamicInstances[7] = 0i64;
}

