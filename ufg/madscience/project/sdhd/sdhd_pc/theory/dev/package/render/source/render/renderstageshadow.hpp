// File Line: 81
// RVA: 0x376E0
void __fastcall UFG::ShadowRenderQueueTaskResults::ShadowRenderQueueTaskResults(UFG::ShadowRenderQueueTaskResults *this)
{
  UFG::ShadowRenderQueueTaskResults *v1; // rbx
  UFG::qTaskGroup **v2; // rdx
  $841545914FC682C9D9C2D70337586AAF *v3; // rax
  signed __int64 v4; // rcx

  v1 = this;
  `eh vector constructor iterator'(
    this,
    0x20ui64,
    16,
    (void (__fastcall *)(void *))ShadowRenderQueueResults::ShadowRenderQueueResults);
  v1->mNumCascades = 0;
  v2 = v1->mCascadeTaskGroups;
  v3 = v1->mShadowsBucketIndices;
  v4 = 4i64;
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

// File Line: 104
// RVA: 0x375F0
void __fastcall UFG::ShadowRenderQueueSimResults::ShadowRenderQueueSimResults(UFG::ShadowRenderQueueSimResults *this)
{
  UFG::ShadowRenderQueueSimResults *v1; // rbx
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v2; // [rsp+58h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v3; // [rsp+58h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v4; // [rsp+58h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v5; // [rsp+58h] [rbp+10h]
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v6; // [rsp+58h] [rbp+10h]

  v1 = this;
  `eh vector constructor iterator'(
    this->mCompositeDrawableCascades,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  v2 = &v1->mDownsampleShadows;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  `eh vector constructor iterator'(
    v1->mCollector,
    0x10ui64,
    4,
    (void (__fastcall *)(void *))UFG::TargetSphere::TargetSphere);
  v3 = &v1->mCharacterShadows;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v1->mCloudShadows;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &v1->mPreShadowPass;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v6 = &v1->mPostShadowPass;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v1->mDynamicInstances[0] = 0i64;
  v1->mDynamicInstances[1] = 0i64;
  v1->mDynamicInstances[2] = 0i64;
  v1->mDynamicInstances[3] = 0i64;
}

