// File Line: 70
// RVA: 0x1CA5A0
UFG::allocator::free_link *__fastcall Render::FXOverride::CreateOverride(const char *allocationName, UFG::qMemoryPool *memoryPool)
{
  UFG::qMemoryPool *v2; // rbx
  UFG::allocator::free_link *result; // rax

  v2 = memoryPool;
  if ( Render::FXOverride::sNumInstancesInService >= 650 )
    return 0i64;
  result = UFG::qMalloc(0x70ui64, allocationName, 0x1000ui64);
  if ( !result )
    return 0i64;
  LODWORD(result->mNext) = 0;
  LODWORD(result[6].mNext) = -1;
  HIDWORD(result[9].mNext) = 1065353216;
  LODWORD(result[10].mNext) = 1065353216;
  HIDWORD(result[10].mNext) = 1065353216;
  result[11].mNext = (UFG::allocator::free_link *)v2;
  result[12].mNext = 0i64;
  result[13].mNext = 0i64;
  LODWORD(result[2].mNext) = 1065353216;
  HIDWORD(result[2].mNext) = 1065353216;
  LODWORD(result[3].mNext) = 1065353216;
  HIDWORD(result[3].mNext) = 1065353216;
  LODWORD(result[4].mNext) = -1082130432;
  *(UFG::allocator::free_link **)((char *)&result[8].mNext + 4) = 0i64;
  *(UFG::allocator::free_link **)((char *)&result[7].mNext + 4) = 0i64;
  *(UFG::allocator::free_link **)((char *)&result[6].mNext + 4) = 0i64;
  ++Render::FXOverride::sNumInstancesInService;
  return result;
}

// File Line: 98
// RVA: 0x1C3A50
void __fastcall Render::FXOverride::~FXOverride(Render::FXOverride *this)
{
  Render::FXOverride::PrecalculatedTriangle *v1; // rdx

  v1 = this->mTriangleInfo;
  if ( v1 )
    UFG::qMemoryPool::Free(this->mMemoryPool, v1);
  --Render::FXOverride::sNumInstancesInService;
}

// File Line: 141
// RVA: 0x146AFC0
__int64 dynamic_initializer_for__Render::FXInstance::smOcclusionList__()
{
  return atexit(dynamic_atexit_destructor_for__Render::FXInstance::smOcclusionList__);
}

// File Line: 150
// RVA: 0x1C1220
void __fastcall Render::FXInstance::FXInstance(Render::FXInstance *this, UFG::qMatrix44 *basis, UFG::TransformNodeComponent *parent, Render::FXOverride *overrideObject, char useRelativeBasis)
{
  Render::FXOverride *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  UFG::qMatrix44 *v7; // rbp
  Render::FXInstance *v8; // rsi
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v9; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float *v25; // r14
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  UFG::qMatrix44 *v38; // rax
  UFG::qVector4 v39; // xmm2
  UFG::qVector4 v40; // xmm1
  UFG::qVector4 v41; // xmm0
  CullManager *v42; // rax
  signed __int64 v43; // rcx
  __m128 v44; // xmm3
  UFG::qMatrix44 result; // [rsp+38h] [rbp-70h]
  UFG::qList<Render::FXComponentInstance,Render::FXComponentInstance,1,0> *v46; // [rsp+B8h] [rbp+10h]

  v5 = overrideObject;
  v6 = parent;
  v7 = basis;
  v8 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  v9 = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  v10 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&this->mPrev;
  v10->mPrev = v10;
  v10->mNext = v10;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettings.mPrev);
  v46 = &v8->mComponents;
  v46->mNode.mPrev = &v46->mNode;
  v46->mNode.mNext = &v46->mNode;
  v8->mBasisRelativeToParent = useRelativeBasis;
  v8->mOcclusionQuery = 0i64;
  v11 = &v8->mParentNode;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v8->mParentNode.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v11->mPrev = v12;
    v8->mParentNode.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  }
  v13 = v7->v0.y;
  v14 = v7->v0.z;
  v15 = v7->v0.w;
  v8->mBasis.v0.x = v7->v0.x;
  v8->mBasis.v0.y = v13;
  v8->mBasis.v0.z = v14;
  v8->mBasis.v0.w = v15;
  v16 = v7->v1.y;
  v17 = v7->v1.z;
  v18 = v7->v1.w;
  v8->mBasis.v1.x = v7->v1.x;
  v8->mBasis.v1.y = v16;
  v8->mBasis.v1.z = v17;
  v8->mBasis.v1.w = v18;
  v19 = v7->v2.y;
  v20 = v7->v2.z;
  v21 = v7->v2.w;
  v8->mBasis.v2.x = v7->v2.x;
  v8->mBasis.v2.y = v19;
  v8->mBasis.v2.z = v20;
  v8->mBasis.v2.w = v21;
  v22 = v7->v3.y;
  v23 = v7->v3.z;
  v24 = v7->v3.w;
  v8->mBasis.v3.x = v7->v3.x;
  v8->mBasis.v3.y = v22;
  v8->mBasis.v3.z = v23;
  v8->mBasis.v3.w = v24;
  v25 = &v8->mRelativeBasis.v0.x;
  v26 = v7->v0.y;
  v27 = v7->v0.z;
  v28 = v7->v0.w;
  *v25 = v7->v0.x;
  v25[1] = v26;
  v25[2] = v27;
  v25[3] = v28;
  v29 = v7->v1.y;
  v30 = v7->v1.z;
  v31 = v7->v1.w;
  v25[4] = v7->v1.x;
  v25[5] = v29;
  v25[6] = v30;
  v25[7] = v31;
  v32 = v7->v2.y;
  v33 = v7->v2.z;
  v34 = v7->v2.w;
  v25[8] = v7->v2.x;
  v25[9] = v32;
  v25[10] = v33;
  v25[11] = v34;
  v35 = v7->v3.y;
  v36 = v7->v3.z;
  v37 = v7->v3.w;
  v25[12] = v7->v3.x;
  v25[13] = v35;
  v25[14] = v36;
  v25[15] = v37;
  if ( v5 )
    ++v5->mReferenceCount;
  v8->mStateBlockOverride.m_pPointer = v5;
  if ( v8->mBasisRelativeToParent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    v38 = UFG::qMatrix44::operator*(&v8->mRelativeBasis, &result, &v6->mWorldTransform);
    v39 = v38->v1;
    v40 = v38->v2;
    v41 = v38->v3;
    v8->mBasis.v0 = v38->v0;
    v8->mBasis.v1 = v39;
    v8->mBasis.v2 = v40;
    v8->mBasis.v3 = v41;
  }
  v42 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v42, &v8->mCullResults, &v8->mCullInfo, 0i64, 0i64, 0i64);
  v43 = (signed __int64)&v8->mCullMatrix;
  v44 = 0i64;
  v44.m128_f32[0] = (float)1;
  *(__m128 *)v43 = v44;
  *(__m128 *)(v43 + 16) = _mm_shuffle_ps(v44, v44, 81);
  *(__m128 *)(v43 + 32) = _mm_shuffle_ps(v44, v44, 69);
  *(__m128 *)(v43 + 48) = _mm_shuffle_ps(v44, v44, 21);
  v8->mCullInfo->mpLocalWorld = &v8->mCullMatrix.v0.x;
}

// File Line: 162
// RVA: 0x1C36F0
void __fastcall Render::FXInstance::~FXInstance(Render::FXInstance *this, int a2, __int64 a3)
{
  Render::FXInstance *v3; // rdi
  unsigned int *v4; // rcx
  signed __int64 v5; // rbx
  FX::HardwareOcclusionQuery *v6; // rbx
  Illusion::IOcclusion *v7; // rax
  Illusion::IOcclusion *v8; // rsi
  __int64 v9; // rdx
  __int64 v10; // rdx
  CullManager *v11; // rax
  Render::FXOverride *v12; // rax
  Render::FXOverride *v13; // rbx
  Render::FXOverride::PrecalculatedTriangle *v14; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qList<Render::FXComponentInstance,Render::FXComponentInstance,1,0> *v20; // rbx
  signed __int64 i; // rax
  _QWORD *v22; // rdx
  __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v25; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v26; // rax
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v29; // rdx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v30; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v31; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v32; // rdx
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v33; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v34; // rax

  v3 = this;
  if ( this->mAudioId
    && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
  {
    UFG::AudioVFXManager::Remove(v3);
  }
  v4 = (unsigned int *)&v3->mComponents.mNode.mNext[-1].mNext;
  if ( v4 != &v3->mSettings.mNameUID )
  {
    do
    {
      v5 = *((_QWORD *)v4 + 2) - 8i64;
      (*(void (__fastcall **)(unsigned int *, _QWORD, __int64))(*(_QWORD *)v4 + 24i64))(v4, 0i64, a3);
      v4 = (unsigned int *)v5;
    }
    while ( (unsigned int *)v5 != &v3->mSettings.mNameUID );
  }
  v6 = v3->mOcclusionQuery;
  if ( v6 )
  {
    v7 = Render::GetOcclusionSystem();
    v8 = v7;
    v9 = v6->mQueryID;
    if ( (_DWORD)v9 != -1 )
    {
      v7->vfptr->ReleaseQueryHandle(v7, v9, v6->mTarget);
      v6->mQueryID = -1;
    }
    v10 = v6->mUnculledQueryID;
    if ( (_DWORD)v10 != -1 )
    {
      v8->vfptr->ReleaseQueryHandle(v8, v10, v6->mTarget);
      v6->mUnculledQueryID = -1;
    }
    operator delete[](v6);
  }
  v11 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v11, v3->mCullResults, v3->mCullInfo);
  v12 = v3->mStateBlockOverride.m_pPointer;
  if ( v12 )
  {
    --v12->mReferenceCount;
    v13 = v3->mStateBlockOverride.m_pPointer;
    if ( v13->mReferenceCount <= 0 )
    {
      if ( v13 )
      {
        v14 = v13->mTriangleInfo;
        if ( v14 )
          UFG::qMemoryPool::Free(v13->mMemoryPool, v14);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v13);
      }
      v3->mStateBlockOverride.m_pPointer = 0i64;
    }
  }
  v15 = &v3->mParentNode;
  if ( v3->mParentNode.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v3->mParentNode.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v3->mParentNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mParentNode.mPrev;
  }
  v3->mParentNode.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v3->mParentNode.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v3->mParentNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mParentNode.mPrev;
  v20 = &v3->mComponents;
  for ( i = (signed __int64)&v3->mComponents.mNode.mNext[-1].mNext;
        (unsigned int *)i != &v3->mSettings.mNameUID;
        i = (signed __int64)&v3->mComponents.mNode.mNext[-1].mNext )
  {
    v22 = (_QWORD *)(i + 8);
    v23 = *(_QWORD *)(i + 8);
    v24 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v23 + 8) = v24;
    *v24 = v23;
    *v22 = v22;
    v22[1] = v22;
    if ( v22 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v22 - 1))(v22 - 1, 1i64);
  }
  v25 = v20->mNode.mPrev;
  v26 = v3->mComponents.mNode.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v20->mNode.mPrev = &v20->mNode;
  v3->mComponents.mNode.mNext = &v3->mComponents.mNode;
  v27 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    v27 = UFG::qResourceWarehouse::GetInventory(v28, 0xED341A8D);
    `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v27;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mSettings.mPrev, v27);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v3->mSettings.mPrev);
  v29 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v3->mPrev;
  v30 = v3->mPrev;
  v31 = v3->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  v32 = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&v3->mPrev;
  v33 = v3->mPrev;
  v34 = v3->mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v32->mPrev = v32;
  v32->mNext = v32;
}

// File Line: 176
// RVA: 0x1CC300
UFG::qMatrix44 *__fastcall Render::FXInstance::GetBasis(Render::FXInstance *this)
{
  UFG::SimComponent *v1; // rbx

  v1 = this->mParentNode.m_pPointer;
  if ( !v1 || this->mBasisRelativeToParent )
    return &this->mBasis;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mParentNode.m_pPointer);
  return (UFG::qMatrix44 *)&v1[2];
}

// File Line: 181
// RVA: 0x1C7DD0
void __fastcall Render::FXInstance::CalcBasisHelper(UFG::qMatrix44 *dst, UFG::qMatrix44 *init, UFG::qResourceHandle *fxHandle, unsigned int componentIndex, float startTime)
{
  UFG::qMatrix44 *v5; // rbx
  UFG::qResourceData *v6; // rcx
  UFG::qMatrix44 *v7; // rsi
  signed __int64 v8; // rdi
  int v9; // ecx
  float v10; // xmm9_4
  float v11; // xmm9_4
  float v12; // xmm2_4
  float v13; // xmm10_4
  float v14; // xmm9_4
  float v15; // xmm2_4
  float v16; // xmm10_4
  int v17; // ecx
  UFG::qMatrix44 *v18; // rax
  UFG::qMatrix44 *v19; // rax
  UFG::qVector4 v20; // xmm1
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm3
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  UFG::qVector3 radians; // [rsp+20h] [rbp-108h]
  UFG::qMatrix44 rot; // [rsp+30h] [rbp-F8h]
  UFG::qMatrix44 v44; // [rsp+70h] [rbp-B8h]
  UFG::qMatrix44 result; // [rsp+B0h] [rbp-78h]

  v5 = dst;
  v6 = fxHandle->mData;
  v7 = init;
  if ( componentIndex < BYTE1(v6[1].mTypeUID)
    && (v8 = (signed __int64)&v6[1].mDebugName[148 * componentIndex + 12]) != 0 )
  {
    v9 = *(_DWORD *)(v8 + 36);
    if ( v9 )
    {
      v10 = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
      if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
        v10 = v10 + 1.8446744e19;
      v11 = (float)(v10 * 0.001) - startTime;
      v12 = v11;
      v13 = v11;
      v14 = (float)((float)(v11 * *(float *)(v8 + 72)) * 2.0) * 3.1415927;
      v15 = (float)((float)(v12 * *(float *)(v8 + 64)) * 2.0) * 3.1415927;
      v16 = (float)((float)(v13 * *(float *)(v8 + 68)) * 2.0) * 3.1415927;
      v17 = v9 - 1;
      if ( v17 )
      {
        if ( v17 == 1 )
        {
          radians.x = (float)((float)((float)(sinf(v15) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 52) - *(float *)(v8 + 40)))
                    + *(float *)(v8 + 40);
          radians.y = (float)((float)((float)(sinf(v16) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 56) - *(float *)(v8 + 44)))
                    + *(float *)(v8 + 44);
          radians.z = (float)((float)((float)(sinf(v14) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 60) - *(float *)(v8 + 48)))
                    + *(float *)(v8 + 48);
        }
      }
      else
      {
        radians.x = v15;
        radians.y = v16;
        radians.z = v14;
      }
      UFG::qRotationMatrixXYZDepreciated(&rot, &radians);
      rot.v3 = (UFG::qVector4)_xmm;
      v18 = UFG::qMatrix44::operator*(&rot, &result, (UFG::qMatrix44 *)(v8 + 76));
      v19 = UFG::qMatrix44::operator*(v18, &v44, v7);
    }
    else
    {
      v19 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v8 + 76), &v44, init);
    }
    v20 = v19->v1;
    v21 = v19->v2;
    v22 = v19->v3;
    v5->v0 = v19->v0;
    v5->v1 = v20;
    v5->v2 = v21;
    v5->v3 = v22;
    if ( *(_BYTE *)(v8 + 24) )
    {
      v23 = *(float *)(v8 + 12);
      v24 = *(float *)(v8 + 16);
      v25 = *(float *)(v8 + 20);
    }
    else
    {
      v26 = *(float *)(v8 + 12);
      v27 = *(float *)(v8 + 20);
      v23 = (float)((float)(*(float *)(v8 + 16) * v5->v1.x) + (float)(v26 * v5->v0.x)) + (float)(v27 * v5->v2.x);
      v24 = (float)((float)(*(float *)(v8 + 16) * v5->v1.y) + (float)(*(float *)(v8 + 12) * v5->v0.y))
          + (float)(*(float *)(v8 + 20) * v5->v2.y);
      v25 = (float)((float)(*(float *)(v8 + 16) * v5->v1.z) + (float)(v26 * v5->v0.z)) + (float)(v27 * v5->v2.z);
    }
    v28 = v24 + v5->v3.y;
    v29 = v25 + v5->v3.z;
    v5->v3.x = v23 + v5->v3.x;
    v5->v3.y = v28;
    v5->v3.z = v29;
    v5->v3.w = 1.0;
  }
  else
  {
    v30 = UFG::qVector4::msZero.z;
    v31 = UFG::qVector4::msZero.w;
    v32 = UFG::qVector4::msZero.x;
    v5->v0.y = UFG::qVector4::msZero.y;
    v5->v0.z = v30;
    v5->v0.x = v32;
    v5->v0.w = v31;
    v33 = UFG::qVector4::msZero.y;
    v34 = UFG::qVector4::msZero.z;
    v35 = UFG::qVector4::msZero.w;
    v5->v1.x = UFG::qVector4::msZero.x;
    v5->v1.y = v33;
    v5->v1.z = v34;
    v5->v1.w = v35;
    v36 = UFG::qVector4::msZero.z;
    v37 = UFG::qVector4::msZero.w;
    v38 = UFG::qVector4::msZero.x;
    v5->v2.y = UFG::qVector4::msZero.y;
    v5->v2.x = v38;
    v5->v2.z = v36;
    v5->v2.w = v37;
    v39 = UFG::qVector4::msZero.z;
    v40 = UFG::qVector4::msZero.w;
    v41 = UFG::qVector4::msZero.x;
    v5->v3.y = UFG::qVector4::msZero.y;
    v5->v3.z = v39;
    v5->v3.x = v41;
    v5->v3.w = v40;
  }
}

// File Line: 273
// RVA: 0x1CB710
void __fastcall Render::FXInstance::DrawOcclusionObject(Render::FXInstance *this, Render::View *view)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qVector4 v3; // xmm2
  Render::View *v4; // rsi
  Render::FXInstance *v5; // rbx
  UFG::qMatrix44 *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  FX::HardwareOcclusionQuery *v9; // rcx
  UFG::qMatrix44 probeTransform; // [rsp+20h] [rbp-48h]

  v2 = (UFG::TransformNodeComponent *)this->mParentNode.m_pPointer;
  v3 = 0i64;
  v4 = view;
  v5 = this;
  v3.x = (float)1;
  probeTransform.v0 = v3;
  probeTransform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 21);
  probeTransform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 81);
  probeTransform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 69);
  if ( !v2 || this->mBasisRelativeToParent )
  {
    v6 = &this->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v6 = &v2->mWorldTransform;
  }
  v7 = v6->v3.y;
  v8 = v6->v3.z;
  v9 = v5->mOcclusionQuery;
  probeTransform.v3.x = v6->v3.x;
  probeTransform.v3.y = v7;
  LODWORD(probeTransform.v3.w) = (_DWORD)FLOAT_1_0;
  probeTransform.v3.z = v8;
  FX::HardwareOcclusionQuery::DrawSphere(v9, v4, &probeTransform);
}

// File Line: 284
// RVA: 0x1CB6B0
void __fastcall Render::FXManager::DrawCullingAABBs(Render::FXManager *this, Render::View *view)
{
  Render::View *v2; // rsi
  Render::FXInstance *v3; // rcx
  UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *v4; // rbx

  v2 = view;
  v3 = (Render::FXInstance *)&Render::FXInstance::smOcclusionList.mNode.mNext[-2];
  if ( (UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *)&Render::FXInstance::smOcclusionList.mNode.mNext[-2] != &Render::FXInstance::smOcclusionList - 2 )
  {
    do
    {
      v4 = (UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *)&v3->mNext[-2];
      Render::FXInstance::DrawOcclusionObject(v3, v2);
      v3 = (Render::FXInstance *)v4;
    }
    while ( v4 != &Render::FXInstance::smOcclusionList - 2 );
  }
}

// File Line: 350
// RVA: 0x1D8FA0
void __fastcall Render::FXInstance::Update(Render::FXInstance *this, UFG::qVector3 *cam_pos, int main_view_cull_index, float simTime)
{
  float v4; // xmm12_4
  char v5; // si
  UFG::qVector3 *v6; // rbp
  Render::FXInstance *v7; // rdi
  UFG::SimComponent *v8; // rbx
  UFG::qMatrix44 *v9; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::SimComponent *v13; // rbx
  signed __int64 v14; // r8
  float v15; // xmm2_4
  char v16; // r14
  UFG::qResourceData *v17; // rcx
  Render::FXOverride *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm0
  char v28; // r12
  Render::FXComponentInstance *v29; // r15
  unsigned int v30; // eax
  float v31; // xmm9_4
  float v32; // xmm11_4
  float v33; // xmm8_4
  float v34; // xmm10_4
  float v35; // xmm5_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm7_4
  float v40; // xmm10_4
  Render::FXComponentInstance *v41; // rbx
  Render::FXComponentInstance *v42; // rsi
  Render::FXComponentInstance::eForceSuspendedState v43; // eax
  UFG::qResourceData *v44; // rcx
  unsigned int v45; // edx
  signed __int64 v46; // rdx
  unsigned __int8 v47; // al
  UFG::qVector3 end; // [rsp+38h] [rbp-100h]
  UFG::qVector3 start; // [rsp+48h] [rbp-F0h]
  UFG::qMatrix44 result; // [rsp+58h] [rbp-E0h]

  v4 = simTime;
  v5 = main_view_cull_index;
  v6 = cam_pos;
  v7 = this;
  if ( this->mBasisRelativeToParent )
  {
    v8 = this->mParentNode.m_pPointer;
    if ( v8 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mParentNode.m_pPointer);
      v9 = UFG::qMatrix44::operator*(&v7->mRelativeBasis, &result, (UFG::qMatrix44 *)&v8[2]);
      v10 = v9->v1;
      v11 = v9->v2;
      v12 = v9->v3;
      v7->mBasis.v0 = v9->v0;
      v7->mBasis.v1 = v10;
      v7->mBasis.v2 = v11;
      v7->mBasis.v3 = v12;
    }
  }
  v13 = v7->mParentNode.m_pPointer;
  if ( !v13 || v7->mBasisRelativeToParent )
  {
    v14 = (signed __int64)&v7->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7->mParentNode.m_pPointer);
    v14 = (signed __int64)&v13[2];
  }
  v15 = (float)((float)((float)(v6->y - *(float *)(v14 + 52)) * (float)(v6->y - *(float *)(v14 + 52)))
              + (float)((float)(v6->x - *(float *)(v14 + 48)) * (float)(v6->x - *(float *)(v14 + 48))))
      + (float)((float)(v6->z - *(float *)(v14 + 56)) * (float)(v6->z - *(float *)(v14 + 56)));
  if ( v15 >= 529.0 )
  {
    if ( v15 >= 1521.0 )
    {
      v16 = 0;
      if ( v15 < 250000.0 )
        v16 = 4;
    }
    else
    {
      v16 = 2;
    }
  }
  else
  {
    v16 = 1;
  }
  v17 = v7->mSettings.mData;
  if ( v17 )
  {
    v18 = v7->mStateBlockOverride.m_pPointer;
    if ( v18 && v18->modelToEmitFromUID != -1 )
    {
      v19 = v18->mAABBMin[0];
      v20 = v18->mAABBMin[1];
      v21 = v18->mAABBMin[2];
      v22 = v18->mAABBMax[0];
      v23 = v18->mAABBMax[1];
      v24 = v18->mAABBMax[2];
    }
    else
    {
      v19 = *(float *)&v17[1].mNode.mParent;
      v20 = *((float *)&v17[1].mNode.mParent + 1);
      v21 = *(float *)v17[1].mNode.mChild;
      v22 = *((float *)v17[1].mNode.mChild + 1);
      v23 = *(float *)&v17[1].mNode.mChild[1];
      v24 = *((float *)&v17[1].mNode.mChild[1] + 1);
    }
    v7->mCullInfo->mAABBMin[0] = v19;
    v7->mCullInfo->mAABBMin[1] = v20;
    v7->mCullInfo->mAABBMin[2] = v21;
    v7->mCullInfo->mAABBMax[0] = v22;
    v7->mCullInfo->mAABBMax[1] = v23;
    v7->mCullInfo->mAABBMax[2] = v24;
    v25 = *(UFG::qVector4 *)(v14 + 16);
    v26 = *(UFG::qVector4 *)(v14 + 32);
    v27 = *(UFG::qVector4 *)(v14 + 48);
    v7->mCullMatrix.v0 = *(UFG::qVector4 *)v14;
    v7->mCullMatrix.v1 = v25;
    v7->mCullMatrix.v2 = v26;
    v7->mCullMatrix.v3 = v27;
    v7->mCullInfo->mPixelScaleBias = 0;
    v7->mCullInfo->mViewsCulled = ~(1 << v5);
  }
  v28 = 0;
  v29 = (Render::FXComponentInstance *)&v7->mSettings.mNameUID;
  v30 = v7->mSettings.mNameUID;
  if ( v30 == 0x6A0A159B || v30 == 0xD2E000A1 || v30 == 0x8F9B2D6D )
  {
    v31 = (float)(*(float *)(v14 + 16) + *(float *)v14) * 0.0;
    v32 = *(float *)(v14 + 32);
    v33 = (float)(*(float *)(v14 + 20) + *(float *)(v14 + 4)) * 0.0;
    v34 = *(float *)(v14 + 36);
    v35 = (float)(*(float *)(v14 + 24) + *(float *)(v14 + 8)) * 0.0;
    v36 = *(float *)(v14 + 40);
    v37 = (float)((float)(*(float *)(v14 + 40) * 0.5) + v35) + *(float *)(v14 + 56);
    v38 = (float)((float)(*(float *)(v14 + 36) * 0.5) + v33) + *(float *)(v14 + 52);
    start.x = (float)((float)(*(float *)(v14 + 32) * 0.5) + v31) + *(float *)(v14 + 48);
    start.y = v38;
    start.z = v37;
    v39 = (float)((float)(v36 * 3.0) + v35) + *(float *)(v14 + 56);
    v40 = (float)((float)(v34 * 3.0) + v33) + *(float *)(v14 + 52);
    end.x = (float)((float)(v32 * 3.0) + v31) + *(float *)(v14 + 48);
    end.y = v40;
    end.z = v39;
    UFG::ShapeCasterCollector::ShapeCasterCollector((UFG::ShapeCasterCollector *)&result, 0.050000001, 0x18u, 0);
    v28 = 0;
    if ( UFG::BasePhysicsSystem::CastShape(
           UFG::BasePhysicsSystem::mInstance,
           (UFG::ShapeCasterCollector *)&result,
           &start,
           &end) )
    {
      v28 = 1;
    }
    UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&result);
  }
  v41 = (Render::FXComponentInstance *)&v7->mComponents.mNode.mNext[-1].mNext;
  if ( v41 != v29 )
  {
    do
    {
      v42 = (Render::FXComponentInstance *)&v41->mNext[-1].mNext;
      if ( v28 == 1 )
      {
        ((void (__fastcall *)(Render::FXComponentInstance *))v41->vfptr->Suspend)(v41);
      }
      else
      {
        v43 = v41->mForceSuspendState;
        if ( v43 == 2 )
        {
          ((void (__fastcall *)(Render::FXComponentInstance *))v41->vfptr->Suspend)(v41);
          v41->mForceSuspendState = 1;
        }
        else if ( v43 == 3 && v41->mIsActive )
        {
          ((void (__fastcall *)(Render::FXComponentInstance *))v41->vfptr->Resume)(v41);
          v41->mForceSuspendState = 0;
        }
        if ( v4 <= v41->mEndTime )
        {
          if ( v4 >= v41->mStartTime )
          {
            if ( !v41->mIsActive )
              v41->vfptr->Activate(v41);
            v44 = v7->mSettings.mData;
            if ( !v44 )
            {
LABEL_48:
              if ( !v41->mIsSuspended )
                ((void (__fastcall *)(Render::FXComponentInstance *, UFG::qVector3 *))v41->vfptr->Update)(v41, v6);
              goto LABEL_50;
            }
            v45 = v41->mComponentIndex;
            if ( v45 < BYTE1(v44[1].mTypeUID) )
            {
              v46 = (signed __int64)&v44[1].mDebugName[148 * v45 + 12];
              if ( v46 )
              {
                v47 = *(_BYTE *)(v46 + 25);
                if ( v47 & 8 || v47 & (unsigned __int8)v16 )
                  goto LABEL_48;
                ((void (__fastcall *)(Render::FXComponentInstance *))v41->vfptr->Suspend)(v41);
              }
            }
          }
        }
        else if ( v41->mIsActive )
        {
          if ( !v41->mIsSuspended )
            ((void (__fastcall *)(Render::FXComponentInstance *, UFG::qVector3 *))v41->vfptr->Update)(v41, v6);
          v41->vfptr->Deactivate(v41, 0);
        }
      }
LABEL_50:
      v41 = v42;
    }
    while ( v42 != v29 );
  }
}

// File Line: 478
// RVA: 0x1CBC00
void __fastcall Render::FXInstance::EnableOcclusionCulling(Render::FXInstance *this)
{
  Render::FXInstance *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v3; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v4; // rax

  v1 = this;
  if ( !this->mOcclusionQuery )
  {
    v2 = UFG::qMalloc(0x18ui64, "FXInstance::mOcclusionQuery", 0i64);
    if ( v2 )
    {
      v2->mNext = (UFG::allocator::free_link *)-1i64;
      v2[1].mNext = 0i64;
    }
    v1->mOcclusionQuery = (FX::HardwareOcclusionQuery *)v2;
    v3 = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&v1->mPrev;
    if ( v3->mPrev == v3 && (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> **)v1->mNext == &v1->mPrev )
    {
      v4 = Render::FXInstance::smOcclusionList.mNode.mPrev;
      Render::FXInstance::smOcclusionList.mNode.mPrev->mNext = v3;
      v3->mPrev = v4;
      v1->mNext = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&Render::FXInstance::smOcclusionList;
      Render::FXInstance::smOcclusionList.mNode.mPrev = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&v1->mPrev;
    }
  }
}

// File Line: 511
// RVA: 0x146B480
__int64 Render::_dynamic_initializer_for__gFXManager__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&Render::gFXManager.mEffectsTree.mTree);
  Render::gFXManager.mEffectsList.mNode.mPrev = &Render::gFXManager.mEffectsList.mNode;
  Render::gFXManager.mEffectsList.mNode.mNext = &Render::gFXManager.mEffectsList.mNode;
  Render::gFXManager.mFilteredEffects.p = 0i64;
  *(_QWORD *)&Render::gFXManager.mFilteredEffects.size = 0i64;
  Render::gFXManager.mStateBlockDefaultOverride.m_pPointer = 0i64;
  Render::gFXManager.mCamTransformNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&Render::gFXManager.mCamTransformNode.mPrev;
  Render::gFXManager.mCamTransformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&Render::gFXManager.mCamTransformNode.mPrev;
  Render::gFXManager.mCamTransformNode.m_pPointer = 0i64;
  Render::gFXManager.mEffectId = 0;
  Render::gFXManager.mLastUpdateTime = 0.0;
  Render::gFXManager.mFXOverrideStateParamIndex = -1;
  Render::gFXManager.mDisplayFXInfo = 0;
  return atexit(Render::_dynamic_atexit_destructor_for__gFXManager__);
}

// File Line: 526
// RVA: 0x1C3950
void __fastcall Render::FXManager::~FXManager(Render::FXManager *this)
{
  Render::FXManager *v1; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  Render::FXOverride *v7; // rax
  Render::FXOverride *v8; // rbx
  Render::FXOverride::PrecalculatedTriangle *v9; // rdx
  unsigned int *v10; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v11; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v12; // rax

  v1 = this;
  v2 = &this->mCamTransformNode;
  if ( this->mCamTransformNode.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = v1->mStateBlockDefaultOverride.m_pPointer;
  if ( v7 )
  {
    --v7->mReferenceCount;
    v8 = v1->mStateBlockDefaultOverride.m_pPointer;
    if ( v8->mReferenceCount <= 0 )
    {
      if ( v8 )
      {
        v9 = v8->mTriangleInfo;
        if ( v9 )
          UFG::qMemoryPool::Free(v8->mMemoryPool, v9);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v8);
      }
      v1->mStateBlockDefaultOverride.m_pPointer = 0i64;
    }
  }
  v10 = v1->mFilteredEffects.p;
  if ( v10 )
    operator delete[](v10);
  v1->mFilteredEffects.p = 0i64;
  *(_QWORD *)&v1->mFilteredEffects.size = 0i64;
  UFG::qList<Render::FXInstance,Render::FXInstance_UpdateList,1,0>::DeleteNodes(&v1->mEffectsList);
  v11 = v1->mEffectsList.mNode.mPrev;
  v12 = v1->mEffectsList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->mEffectsList.mNode.mPrev = &v1->mEffectsList.mNode;
  v1->mEffectsList.mNode.mNext = &v1->mEffectsList.mNode;
  UFG::qTreeRB<Render::FXInstance,Render::FXInstance,1>::~qTreeRB<Render::FXInstance,Render::FXInstance,1>(&v1->mEffectsTree);
}

// File Line: 532
// RVA: 0x1CE540
void __fastcall Render::FXManager::Init(Render::FXManager *this, unsigned int max_particle_buffers_HACK)
{
  Render::FXManager *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rdi
  unsigned int v5; // eax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  void (__fastcall *v12)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  hkResourceHandle *v13; // rax
  unsigned int v14; // eax
  UFG::allocator::free_link *v15; // rax
  fastdelegate::FastDelegate1<char const *,void> v16; // [rsp+38h] [rbp-50h]
  void (__fastcall *v17)(AMD_HD3D *); // [rsp+48h] [rbp-40h]
  void (__fastcall *v18)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-38h]
  UFG::qString v19; // [rsp+58h] [rbp-30h]

  v2 = this;
  if ( !this->mCamTransformNode.m_pPointer )
  {
    v3 = UFG::GetSimulationMemoryPool();
    v4 = UFG::qMemoryPool::Allocate(v3, 0x110ui64, "mCamTransformNode", 0i64, 1u);
    if ( v4 )
    {
      v5 = UFG::qStringHashUpper32("mCamTransformNode", 0xFFFFFFFF);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v4, v5, 0i64, 0);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = &v2->mCamTransformNode;
    if ( v2->mCamTransformNode.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->mCamTransformNode.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->mCamTransformNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mCamTransformNode.mPrev;
    }
    v2->mCamTransformNode.m_pPointer = v7;
    if ( v7 )
    {
      v11 = v7->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->mCamTransformNode.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
  }
  UFG::TransformNodeComponent::SetWorldTransform(
    (UFG::TransformNodeComponent *)v2->mCamTransformNode.m_pPointer,
    &UFG::qMatrix44::msIdentity);
  Render::ParticleEmitterManager::Init(&Render::gParticleEmitterManager);
  Render::DecalManager::Init(&Render::gDecalManager);
  Render::FlareManager::Init(&Render::gFlareManager);
  Render::CoronaFlareManager::Init(&Render::gCoronaFlareManager);
  Render::BeamManager::Init(&Render::gBeamManager);
  if ( Render::gGeoManager.mGeos.capacity < 0x32 )
    UFG::qArray<Render::GeoManager::GeoEntry,0>::Reallocate(
      &Render::gGeoManager.mGeos,
      0x32u,
      "qArray.Reserve.GeoManagerGeos");
  Render::gGeoManager.mSceneryInstanceStateParamIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                                                            &Illusion::gStateSystem,
                                                                            "cbSceneryInstance",
                                                                            0);
  Render::gFXForceManager.mForceList = (Render::FXForce *)UFG::qMalloc(
                                                            0x5A0ui64,
                                                            "FXForceManager::mForceList",
                                                            0x1000ui64);
  Render::PolyStripManager::Init(&Render::gPolyStripManager, 256);
  Render::ScreenParticleEmitterManager::Init(&Render::gScreenParticleEmitterManager);
  Render::LightningManager::Init(&Render::gLightningManager, UFG::gMainMemoryPool);
  FX::HardwareOcclusionQuery::InitSystem();
  v2->mRenderRainWhileInside = 0;
  UFG::qString::qString(&v19, "Data\\Global\\Effects.bin");
  v16 = UFG::DefaultHotSwapCallBack;
  v12 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
  if ( !_ )
    v12 = 0i64;
  v18 = v12;
  v17 = _;
  v13 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v13);
  v14 = UFG::qStringHash32("cbFXOverrideSettings", 0xFFFFFFFF);
  v2->mFXOverrideStateParamIndex = Illusion::StateSystem::AddParam(
                                     &Illusion::gStateSystem,
                                     v14,
                                     "cbFXOverrideSettings",
                                     0);
  v15 = Render::FXOverride::CreateOverride("FXOverride Default", 0i64);
  FX::SharedPointer<Render::FXOverride>::Set(&v2->mStateBlockDefaultOverride, (Render::FXOverride *)v15);
  UFG::qString::~qString(&v19);
}

// File Line: 648
// RVA: 0x1CBDE0
Render::FXInstance *__fastcall Render::FXManager::FindEffect(Render::FXManager *this, unsigned int fxId)
{
  if ( fxId != -1 )
    JUMPOUT(fxId, 0, UFG::qBaseTreeRB::Get);
  return 0i64;
}

// File Line: 685
// RVA: 0x1D0F40
bool __fastcall Render::FXManager::IsEffectLooping(Render::FXManager *this, unsigned int fxId)
{
  UFG::qBaseTreeRB *v2; // rax
  bool result; // al

  result = 0;
  if ( fxId != -1 )
  {
    if ( fxId )
    {
      v2 = UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
      if ( v2 )
      {
        if ( *((_BYTE *)&v2[1].mCount + 4) )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 692
// RVA: 0x1CBC90
void __fastcall Render::FXManager::EnableOcclusionCulling(Render::FXManager *this, unsigned int fxId)
{
  UFG::qBaseTreeRB *v2; // rax

  if ( fxId != -1 && fxId )
  {
    v2 = UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
    if ( v2 )
      Render::FXInstance::EnableOcclusionCulling((Render::FXInstance *)v2);
  }
}

// File Line: 751
// RVA: 0x1D1520
void __fastcall Render::FXManager::KillEffect(Render::FXManager *this, unsigned int fxId, Render::eFXKillOption killOption)
{
  unsigned int v3; // edi
  UFG::qBaseTreeVariableRB<unsigned __int64> *v4; // rsi
  Render::eFXKillOption v5; // ebp
  UFG::qBaseTreeRB *v6; // rax
  int v7; // edx
  hkGeometryUtils::IVertices *v8; // rcx
  int v9; // er8
  Render::FXInstance *v10; // rbx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v11; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v12; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v13; // rdx
  __int64 v14; // r8

  v3 = fxId;
  v4 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)this;
  v5 = killOption;
  if ( fxId != -1 )
  {
    if ( fxId )
    {
      v6 = UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
      v10 = (Render::FXInstance *)v6;
      if ( v6 )
      {
        if ( *(_QWORD *)&v6[1].mNULL.mUID
          && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v8, v7, v9) )
        {
          UFG::AudioVFXManager::Remove(v10);
        }
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(v4, (UFG::qBaseNodeVariableRB<unsigned __int64> *)v10);
        v11 = v10->mPrev;
        v12 = v10->mNext;
        v13 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v10->mPrev;
        v11->mNext = v12;
        v12->mPrev = v11;
        v13->mPrev = v13;
        v13->mNext = v13;
        Render::FXInstance::~FXInstance(v10, (_DWORD)v10 + 48, v14);
        operator delete[](v10);
      }
    }
  }
  if ( v5 == 1 )
    Render::ParticleEmitterManager::KillBuffersWithParent(&Render::gParticleEmitterManager, v3);
}

// File Line: 771
// RVA: 0x1D12F0
void __fastcall Render::FXManager::KillAllEffects(Render::FXManager *this)
{
  UFG::qBaseTreeVariableRB<unsigned __int64> *v1; // rdi
  unsigned int *v2; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *v3; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rax
  Render::FXInstance *v6; // rbx
  int v7; // edx
  __int64 v8; // r8
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v9; // r8
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v10; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v13; // rax
  unsigned int v14; // edi
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *v15; // rbx

  v1 = (UFG::qBaseTreeVariableRB<unsigned __int64> *)this;
  v2 = &this->mEffectsTree.mTree.mRoot.mUID;
  if ( (unsigned int *)&this->mEffectsList.mNode.mNext[-3] != &this->mEffectsTree.mTree.mRoot.mUID )
  {
    do
    {
      v3 = v1[1].mRoot.mChild[0];
      v4 = v3->mParent;
      v5 = v3->mChild[0];
      v4->mChild[0] = v5;
      v5->mParent = v4;
      v3->mParent = v3;
      v3->mChild[0] = v3;
      v6 = (Render::FXInstance *)&v3[-2].mChild1;
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        v1,
        (UFG::qBaseNodeVariableRB<unsigned __int64> *)((char *)v3 - 48));
      if ( v6 )
      {
        Render::FXInstance::~FXInstance(v6, v7, v8);
        operator delete[](v6);
      }
    }
    while ( (unsigned int *)&v1[1].mRoot.mChild[0][-2].mChild1 != v2 );
  }
  v9 = stru_142366970.mNode.mNext;
  if ( (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)stru_142366970.mNode.mNext != &stru_142366970 )
  {
    do
    {
      v10 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)v9->mNext;
      v11 = v9->mPrev;
      v11->mNext = &v10->mNode;
      v10->mNode.mPrev = v11;
      v9->mPrev = v9;
      v9->mNext = v9;
      v12 = v9->mPrev;
      v13 = v9->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v9->mPrev = v9;
      v9->mNext = v9;
      v9->mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)unk_142366958;
      unk_142366958 = v9;
      --unk_142366964;
      v9 = &v10->mNode;
    }
    while ( v10 != &stru_142366970 );
  }
  v14 = 0;
  v15 = Render::gParticleEmitterManager.activeBuffers;
  do
  {
    while ( v15->size )
      Render::ParticleEmitterManager::AddToFreeBufferList(&Render::gParticleEmitterManager, v14, 0);
    ++v14;
    ++v15;
  }
  while ( v14 < 3 );
}

// File Line: 803
// RVA: 0x1D6B10
void __fastcall Render::FXManager::SetTrackStrength(Render::FXManager *this, unsigned int fxId, float strength)
{
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *v4; // r9
  UFG::qBaseNodeRB *v5; // rdx
  unsigned int v6; // er8
  signed __int64 v7; // rcx
  unsigned int *v8; // rax
  float v9; // xmm1_4

  if ( fxId != -1 )
  {
    if ( fxId )
    {
      v3 = UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
      v4 = v3;
      if ( v3 )
      {
        v5 = v3[1].mRoot.mChild[0];
        v6 = 0;
        v7 = (signed __int64)&v3[1].mNULL.mParent[-1].mUID;
        if ( BYTE1(v5[4].mChild[0]) )
        {
          do
          {
            if ( v6 < BYTE1(v5[4].mChild[0]) )
              v8 = &v5[4].mUID + 37 * v6;
            else
              v8 = 0i64;
            if ( *v8 == 1775129656 )
            {
              if ( (v9 = strength, strength <= 0.02) && *(float *)(v7 + 88) > 0.0
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(v7 + 88) - strength) & _xmm) > 0.02 )
              {
                if ( strength <= 0.02 )
                  v9 = 0.0;
                *(float *)(v7 + 88) = v9;
                *(_DWORD *)(v7 + 92) = UFG::Metrics::msFrameCount;
              }
            }
            v5 = v4[1].mRoot.mChild[0];
            ++v6;
            v7 = *(_QWORD *)(v7 + 16) - 8i64;
          }
          while ( (signed int)v6 < BYTE1(v5[4].mChild[0]) );
        }
      }
    }
  }
}

// File Line: 838
// RVA: 0x1D1850
void __usercall Render::LoopEffect(Render::FXInstance *curFX@<rcx>, float simTime@<xmm1>, __int64 a3@<rdx>)
{
  UFG::qResourceData *v3; // rbp
  float v4; // xmm6_4
  unsigned int *v5; // r14
  Render::FXInstance *v6; // rbx
  __int64 v7; // rcx
  signed __int64 v8; // rsi
  signed __int64 v9; // rdi
  float v10; // xmm1_4

  v3 = curFX->mSettings.mData;
  v4 = simTime;
  v5 = &curFX->mSettings.mNameUID;
  v6 = (Render::FXInstance *)&curFX->mComponents.mNode.mNext[-1].mNext;
  curFX->mStartTime = simTime;
  curFX->mEndTime = simTime + *(float *)&v3[1].mNode.mUID;
  if ( v6 != (Render::FXInstance *)&curFX->mSettings.mNameUID )
  {
    do
    {
      v7 = LODWORD(v6->mNext);
      v8 = (signed __int64)&v6->mNode.mChild[1][-1].mUID;
      if ( (unsigned int)v7 < BYTE1(v3[1].mTypeUID) )
        v9 = (signed __int64)&v3[1].mDebugName[148 * v7 + 12];
      else
        v9 = 0i64;
      if ( BYTE4(v6->mNext) )
      {
        LOBYTE(a3) = (float)(*(float *)(v9 + 32) - *(float *)(v9 + 28)) == *(float *)&v3[1].mNode.mUID;
        (*(void (__fastcall **)(Render::FXInstance *, __int64))&v6->mNode.mParent->mUID)(v6, a3);
      }
      v10 = v4 + *(float *)(v9 + 32);
      *(float *)&v6->mPrev = v4 + *(float *)(v9 + 28);
      *((float *)&v6->mPrev + 1) = v10;
      v6 = (Render::FXInstance *)v8;
    }
    while ( (unsigned int *)v8 != v5 );
  }
}

// File Line: 871
// RVA: 0x1D94B0
void __fastcall Render::FXManager::Update(Render::FXManager *this, UFG::qMatrix44 *view_world, int main_view_cull_index, float simTime)
{
  Render::FXManager *v4; // r14
  UFG::TransformNodeComponent *v5; // rcx
  float v6; // xmm6_4
  int v7; // ebp
  UFG::qMatrix44 *v8; // rsi
  __int64 v9; // rdx
  Render::FXInstance *v10; // rbx
  float v11; // xmm3_4
  signed __int64 v12; // rdi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v13; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v14; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v15; // rdx
  __int64 v16; // r8

  v4 = this;
  Render::gFXForceManager.mNumForces = 0;
  Render::gGeoManager.mGeos.size = 0;
  v5 = (UFG::TransformNodeComponent *)this->mCamTransformNode.m_pPointer;
  v6 = simTime;
  v7 = main_view_cull_index;
  v8 = view_world;
  if ( v5 )
    UFG::TransformNodeComponent::SetWorldTransform(v5, view_world);
  Render::ScreenParticleEmitterManager::Update(&Render::gScreenParticleEmitterManager, simTime);
  v10 = (Render::FXInstance *)&v4->mEffectsList.mNode.mNext[-3];
  if ( v10 != (Render::FXInstance *)&v4->mEffectsTree.mTree.mRoot.mUID )
  {
    do
    {
      v11 = v10->mEndTime;
      v12 = (signed __int64)&v10->mNext[-3];
      if ( v6 < v11 )
      {
        if ( v6 >= v10->mStartTime )
          goto LABEL_9;
      }
      else
      {
        if ( v10->mLoop )
        {
          Render::LoopEffect(v10, v6, v9);
LABEL_9:
          Render::FXInstance::Update(v10, (UFG::qVector3 *)&v8->v3, v7, v6);
          goto LABEL_10;
        }
        Render::FXInstance::Update(v10, (UFG::qVector3 *)&v8->v3, v7, v11);
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)v4,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v10);
        v13 = v10->mPrev;
        v14 = v10->mNext;
        v15 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v10->mPrev;
        v13->mNext = v14;
        v14->mPrev = v13;
        v15->mPrev = v15;
        v15->mNext = v15;
        Render::FXInstance::~FXInstance(v10, (_DWORD)v10 + 48, v16);
        operator delete[](v10);
      }
LABEL_10:
      v10 = (Render::FXInstance *)v12;
    }
    while ( (unsigned int *)v12 != &v4->mEffectsTree.mTree.mRoot.mUID );
  }
  v4->mLastUpdateTime = v6;
}

// File Line: 931
// RVA: 0x1D6010
void __fastcall Render::FXManager::ResumeAndSuspendBasedOnCullResults(Render::FXManager *this, UFG::qVector3 *cam_pos, float simTime)
{
  unsigned int *v3; // r12
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v4; // rbx
  UFG::qVector3 *v5; // r13
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v6; // rbp
  signed __int64 v7; // r15
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v8; // rdi
  float *v9; // rdi
  float v10; // xmm2_4
  char v11; // si
  signed __int64 v12; // r14
  bool v13; // di
  signed __int64 v14; // rcx
  __int64 v15; // rdx
  signed __int64 v16; // rbx
  signed __int64 v17; // rax
  unsigned __int8 v18; // dl
  char v19; // al

  v3 = &this->mEffectsTree.mTree.mRoot.mUID;
  v4 = this->mEffectsList.mNode.mNext - 3;
  v5 = cam_pos;
  if ( v4 != (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&this->mEffectsTree.mTree.mRoot.mUID )
  {
    do
    {
      v6 = v4[5].mPrev;
      v7 = (signed __int64)&v4[3].mNext[-3];
      if ( v6 )
      {
        v8 = v4[15].mNext;
        if ( !v8 || BYTE5(v4[8].mNext) )
        {
          v9 = (float *)&v4[16];
        }
        else
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4[15].mNext);
          v9 = (float *)&v8[8];
        }
        v10 = (float)((float)((float)(v5->x - v9[12]) * (float)(v5->x - v9[12]))
                    + (float)((float)(v5->y - v9[13]) * (float)(v5->y - v9[13])))
            + (float)((float)(v5->z - v9[14]) * (float)(v5->z - v9[14]));
        if ( v10 >= 529.0 )
        {
          if ( v10 >= 1521.0 )
          {
            v11 = 0;
            if ( v10 < 250000.0 )
              v11 = 4;
          }
          else
          {
            v11 = 2;
          }
        }
        else
        {
          v11 = 1;
        }
        v12 = (signed __int64)&v4[5].mNext;
        v13 = v4[13].mNext->mPrev <= (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)1;
        v14 = (signed __int64)&v4[6].mNext[-1].mNext;
        if ( (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> **)v14 != &v4[5].mNext )
        {
          do
          {
            v15 = *(unsigned int *)(v14 + 40);
            v16 = *(_QWORD *)(v14 + 16) - 8i64;
            if ( (unsigned int)v15 < BYTE1(v6[8].mNext) )
              v17 = (signed __int64)&v6[9].mNext + 148 * v15;
            else
              v17 = 0i64;
            v18 = *(_BYTE *)(v17 + 25);
            v19 = (v18 >> 3) & 1;
            if ( (v19 || v18 & (unsigned __int8)v11) && *(_BYTE *)(v14 + 44) && !*(_DWORD *)(v14 + 48) )
            {
              if ( *(_BYTE *)(v14 + 45) )
              {
                if ( v13 || v19 )
                  (*(void (**)(void))(*(_QWORD *)v14 + 56i64))();
              }
              else if ( !v13 && !v19 )
              {
                (*(void (**)(void))(*(_QWORD *)v14 + 48i64))();
              }
            }
            v14 = v16;
          }
          while ( v16 != v12 );
        }
      }
      v4 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)v7;
    }
    while ( (unsigned int *)v7 != v3 );
  }
}

// File Line: 989
// RVA: 0x1D3BF0
void __fastcall Render::FXManager::Render(Render::FXManager *this, Render::View *view, float simTime, Render::eFXDrawPass drawPass, Render::FXManagerAuxBuffers *auxBuffers)
{
  Render::View *v5; // rbx
  __int32 v6; // er9

  v5 = view;
  if ( drawPass )
  {
    v6 = drawPass - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        Render::FXManager::DrawCullingAABBs(this, view);
        Render::ParticleEmitterManager::Render(
          &Render::gParticleEmitterManager,
          v5,
          simTime,
          PARTICLEQUEUE_FORWARD_HIGH_QUALITY,
          auxBuffers);
        Render::FlareManager::Render(&Render::gFlareManager, v5, simTime, FLAREQUEUE_FORWARD_HIGH_QUALITY, 0);
        Render::CoronaFlareManager::Render(&Render::gCoronaFlareManager, v5, simTime);
        Render::BeamManager::Render(&Render::gBeamManager, v5, simTime);
        Render::LightningManager::Render(&Render::gLightningManager, v5, 0i64, 0x69DAE2D1u);
      }
    }
    else
    {
      Render::ParticleEmitterManager::Render(
        &Render::gParticleEmitterManager,
        view,
        simTime,
        PARTICLEQUEUE_FORWARD_LOW_QUALITY,
        auxBuffers);
      Render::FlareManager::Render(&Render::gFlareManager, v5, simTime, 0, 0);
    }
  }
  else
  {
    Render::PolyStripManager::Render(&Render::gPolyStripManager, view, simTime);
    Render::GeoManager::Render(&Render::gGeoManager, v5, 0, simTime);
    Render::ParticleEmitterManager::Render(&Render::gParticleEmitterManager, v5, simTime, 0, auxBuffers);
  }
}

// File Line: 1056
// RVA: 0x1CA250
signed __int64 __fastcall Render::FXManager::CreateEffect(Render::FXManager *this, unsigned int fx_id, UFG::qVector3 *vPos, UFG::qVector3 *vDir)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  float v6; // xmm8_4
  __int128 v7; // xmm9
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  float v10; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  __m128 v14; // xmm1
  float v15; // xmm5_4
  __int128 v16; // xmm11
  float v17; // xmm10_4
  float v18; // xmm10_4
  __m128 v19; // xmm5
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  __m128 v23; // xmm9
  float v24; // xmm4_4
  __m128 v25; // xmm6
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm9_4
  float v30; // xmm4_4
  float v31; // xmm2_4
  UFG::qMatrix44 basis; // [rsp+40h] [rbp-A8h]

  v4 = vDir->x;
  v5 = vDir->y;
  v6 = vDir->z;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(vDir->y * 0.0) + (float)(vDir->x * 0.0)) + v6) & _xmm) <= 0.99 )
  {
    v7 = 0i64;
    v8 = (__m128)(unsigned int)FLOAT_1_0;
  }
  else
  {
    v7 = (unsigned int)FLOAT_1_0;
    v8 = 0i64;
  }
  v9 = (__m128)LODWORD(vDir->y);
  v9.m128_f32[0] = (float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6);
  if ( v9.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v11 = v4 * v10;
  v12 = v5 * v10;
  v13 = v6 * v10;
  v14 = v8;
  basis.v2.x = v11;
  basis.v2.y = v12;
  basis.v2.z = v13;
  v14.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(*(float *)&v7 * *(float *)&v7);
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
  v8.m128_f32[0] = v8.m128_f32[0] * v15;
  *(float *)&v7 = *(float *)&v7 * v15;
  v16 = v7;
  *(float *)&v16 = (float)(*(float *)&v7 * v13) - (float)(v8.m128_f32[0] * v12);
  v17 = (float)(v15 * 0.0) * v12;
  v8.m128_f32[0] = (float)(v8.m128_f32[0] * v11) - (float)((float)(v15 * 0.0) * v13);
  v19 = v8;
  v18 = v17 - (float)(*(float *)&v7 * v11);
  v19.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(*(float *)&v16 * *(float *)&v16))
                  + (float)(v18 * v18);
  if ( v19.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
  v21 = v8.m128_f32[0] * v20;
  *(float *)&v16 = *(float *)&v16 * v20;
  v23 = (__m128)v16;
  basis.v0.y = v21;
  basis.v0.z = v18 * v20;
  LODWORD(basis.v0.x) = v16;
  v22 = (float)((float)(v18 * v20) * v12) - (float)(v21 * v13);
  v23.m128_f32[0] = (float)(*(float *)&v16 * v13) - (float)((float)(v18 * v20) * v11);
  v24 = (float)(v21 * v11) - (float)(*(float *)&v16 * v12);
  v25 = v23;
  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25));
  v27 = vPos->y;
  v28 = v22 * v26;
  v29 = v23.m128_f32[0] * v26;
  v30 = v24 * v26;
  v31 = vPos->z;
  basis.v3.x = vPos->x;
  basis.v1.x = v28;
  basis.v1.y = v29;
  basis.v0.w = 0.0;
  basis.v1.w = 0.0;
  basis.v2.w = 0.0;
  basis.v1.z = v30;
  basis.v3.y = v27;
  basis.v3.z = v31;
  basis.v3.w = 1.0;
  return Render::FXManager::CreateEffect(this, fx_id, &basis, 0i64);
}

// File Line: 1079
// RVA: 0x1CA220
signed __int64 __fastcall Render::FXManager::CreateEffect(Render::FXManager *this, unsigned int fx_id, UFG::qMatrix44 *basis, unsigned int splitScreenViewMask)
{
  return Render::FXManager::CreateEffect(this, fx_id, basis, 0i64);
}

// File Line: 1086
// RVA: 0x1CA510
signed __int64 __fastcall Render::FXManager::CreateEffect(Render::FXManager *this, unsigned int fx_id, UFG::TransformNodeComponent *parent, unsigned int splitScreenViewMask, Render::FXOverride *overrideObject)
{
  UFG::TransformNodeComponent *v5; // rbx
  unsigned int v6; // esi
  Render::FXManager *v7; // rbp
  UFG::qMatrix44 *v8; // r8

  v5 = parent;
  v6 = fx_id;
  v7 = this;
  if ( parent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(parent);
    v8 = &v5->mWorldTransform;
  }
  else
  {
    v8 = &UFG::qMatrix44::msIdentity;
  }
  return Render::FXManager::CreateEffect(v7, v6, v8, v5);
}

// File Line: 1125
// RVA: 0x1C9D30
signed __int64 __fastcall Render::FXManager::CreateEffect(Render::FXManager *this, unsigned int fx_id, UFG::qMatrix44 *basis, UFG::TransformNodeComponent *parent)
{
  UFG::TransformNodeComponent *v4; // rbx
  unsigned int v5; // edi
  Render::FXManager *v6; // rsi
  unsigned int v7; // ecx
  unsigned int v8; // er10
  unsigned int *v9; // rax
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Render::FXSettings *v13; // rdi
  unsigned int v14; // ebx
  char v15; // cl
  unsigned int v16; // edx
  float v17; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  UFG::allocator::free_link *v29; // rax
  Render::FXInstance *v30; // rax
  Render::FXInstance *v31; // rbx
  UFG::allocator::free_link *v32; // rax
  Render::FXInstance *v33; // rax
  UFG::qResourceInventory *v34; // rax
  UFG::qResourceWarehouse *v35; // rax
  unsigned int v36; // eax
  unsigned int v37; // esi
  Render::FXSettingsMember *i; // rdi
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  Render::FXComponentInstance *v42; // rax
  float v43; // xmm1_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm0_4
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v47; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v48; // rax
  UFG::qBaseTreeRB *v49; // rdi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v50; // rdx
  UFG::qBaseNodeRB *v51; // rax
  UFG::qResourceInventory *v52; // rax
  UFG::qResourceWarehouse *v53; // rax
  int v54; // edx
  hkGeometryUtils::IVertices *v55; // rcx
  int v56; // er8
  UFG::qResourceInventory *v57; // rax
  UFG::qResourceWarehouse *v58; // rax
  unsigned int v59; // [rsp+28h] [rbp-61h]
  UFG::qMatrix44 basisa; // [rsp+38h] [rbp-51h]
  Render::FXSettings *v61; // [rsp+78h] [rbp-11h]
  UFG::qResourceHandle v62; // [rsp+80h] [rbp-9h]
  __int64 v63; // [rsp+A0h] [rbp+17h]
  UFG::qBaseTreeRB *v64; // [rsp+D8h] [rbp+4Fh]
  UFG::qMatrix44 *retaddr; // [rsp+E8h] [rbp+5Fh]
  UFG::TransformNodeComponent *parenta; // [rsp+F0h] [rbp+67h]
  float v67; // [rsp+F8h] [rbp+6Fh]
  UFG::qMatrix44 *v68; // [rsp+100h] [rbp+77h]
  Render::FXOverride *v69; // [rsp+108h] [rbp+7Fh]

  v69 = (Render::FXOverride *)parent;
  v68 = basis;
  parenta = (UFG::TransformNodeComponent *)this;
  v63 = -2i64;
  v4 = parent;
  v5 = fx_id;
  v6 = this;
  v7 = this->mFilteredEffects.size;
  v8 = 0;
  if ( !v7 )
  {
LABEL_7:
    UFG::qResourceHandle::qResourceHandle(&v62);
    v11 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v11;
    }
    UFG::qResourceHandle::Init(&v62, 0xED341A8D, v5, v11);
    v13 = (Render::FXSettings *)v62.mData;
    v61 = (Render::FXSettings *)v62.mData;
    if ( !v62.mData )
    {
      v14 = -1;
LABEL_54:
      v57 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v58 = UFG::qResourceWarehouse::Instance();
        v57 = UFG::qResourceWarehouse::GetInventory(v58, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v57;
      }
      UFG::qResourceHandle::Close(&v62, v57);
      UFG::qResourceHandle::~qResourceHandle(&v62);
      return v14;
    }
    v15 = BYTE2(v62.mData[1].mTypeUID);
    if ( v15 )
    {
      if ( v6->mCamTransformNode.m_pPointer )
        v4 = (UFG::TransformNodeComponent *)v6->mCamTransformNode.m_pPointer;
      parenta = v4;
    }
    if ( UFG::Metrics::msInstance.mSimTimeScaleInGame < 1.0 )
    {
      v16 = (unsigned int)v62.mData[1].mResourceHandles.mNode.mNext;
      if ( v16 != -1 )
      {
        v14 = Render::FXManager::CreateEffect(v6, v16, retaddr, parenta);
        goto LABEL_54;
      }
      v4 = parenta;
    }
    if ( v15
      && v6->mCamTransformNode.m_pPointer
      && (v17 = *((float *)&v62.mData[1].mResourceHandles.mNode.mNext + 1), v17 > 0.0000099999997) )
    {
      v18 = retaddr->v0.y;
      v19 = retaddr->v0.z;
      v20 = retaddr->v0.w;
      basisa.v0.x = retaddr->v0.x;
      basisa.v0.y = v18;
      basisa.v0.z = v19;
      basisa.v0.w = v20;
      v21 = retaddr->v1.y;
      v22 = retaddr->v1.z;
      v23 = retaddr->v1.w;
      basisa.v1.x = retaddr->v1.x;
      basisa.v1.y = v21;
      basisa.v1.z = v22;
      basisa.v1.w = v23;
      v24 = retaddr->v2.y;
      v25 = retaddr->v2.z;
      v26 = retaddr->v2.w;
      basisa.v2.x = retaddr->v2.x;
      basisa.v2.y = v24;
      basisa.v2.z = v25;
      basisa.v2.w = v26;
      v27 = retaddr->v3.z - (float)(v25 * v17);
      v28 = retaddr->v3.y - (float)(v24 * v17);
      basisa.v3.x = retaddr->v3.x - (float)(basisa.v2.x * v17);
      basisa.v3.y = v28;
      basisa.v3.z = v27;
      basisa.v3.w = 1.0;
      v29 = UFG::qMalloc(0x190ui64, "FXInstance", 0x1000ui64);
      if ( v29 )
      {
        Render::FXInstance::FXInstance((Render::FXInstance *)v29, &basisa, v4, v69, 1);
        v31 = v30;
      }
      else
      {
        v31 = 0i64;
      }
    }
    else
    {
      v32 = UFG::qMalloc(0x190ui64, "FXInstance", 0x1000ui64);
      if ( v32 )
      {
        Render::FXInstance::FXInstance((Render::FXInstance *)v32, retaddr, v4, v69, 0);
        v31 = v33;
      }
      else
      {
        v31 = 0i64;
      }
    }
    v59 = v62.mNameUID;
    v34 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v35 = UFG::qResourceWarehouse::Instance();
      v34 = UFG::qResourceWarehouse::GetInventory(v35, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v34;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v31->mSettings.mPrev, 0xED341A8D, v59, v34);
    v31->mStartTime = 3.4028235e38;
    v31->mEndTime = -3.4028235e38;
    v31->mLoop = v13->mLoop;
    v31->mAudioId = v13->mAudioId;
    v31->mTransformNodeExtraTime = v13->mTransformNodeExtraTime;
    v31->mSplitScreenViewMask = (unsigned int)v68;
    v36 = UFG::qRandom(0x7FFFFFFF, &UFG::qDefaultSeed);
    v6->mEffectId = v36;
    v31->mId = v36;
    v31->mNode.mUID = v36;
    v37 = 0;
    if ( !v13->mComponentCount )
    {
LABEL_48:
      v49 = v64;
      UFG::qBaseTreeRB::Add(v64, &v31->mNode);
      v50 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v31->mPrev;
      v51 = v49[1].mRoot.mChild[0];
      v49[1].mRoot.mChild[0] = (UFG::qBaseNodeRB *)&v31->mPrev;
      v50->mPrev = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v49[1];
      v50->mNext = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)v51;
      v51->mParent = (UFG::qBaseNodeRB *)&v31->mPrev;
      v52 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v53 = UFG::qResourceWarehouse::Instance();
        v52 = UFG::qResourceWarehouse::GetInventory(v53, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v52;
      }
      UFG::qResourceHandle::Close(&v62, v52);
      if ( v31->mAudioId && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v55, v54, v56) )
        UFG::AudioVFXManager::Add(v31, v31->mAudioId);
      v14 = v31->mId;
      goto LABEL_54;
    }
    if ( (unsigned __int8)v13->mComponentCount > 0u )
      goto LABEL_34;
    for ( i = 0i64; ; i = (Render::FXSettingsMember *)((char *)&v13[1] + 0x94 * v37) )
    {
      v39 = i->endTime;
      v40 = i->startTime;
      v41 = *((float *)&v64[1].mNULL.mParent + 1);
      if ( v39 < v40 )
      {
        if ( v41 < v40 && v41 > v39 )
          goto LABEL_47;
      }
      else if ( v40 > v41 || v39 < v41 )
      {
        goto LABEL_47;
      }
      v42 = Render::FXManager::CreateComponentFromID(i->typeId, i->nameId);
      if ( v42 )
      {
        v42->mContainer = v31;
        v42->mComponentIndex = v37;
        v43 = i->end;
        v42->mStartTime = i->start + v67;
        v44 = v43 + v67;
        v42->mEndTime = v44;
        v45 = v31->mEndTime;
        if ( v45 <= v44 )
          v45 = v44;
        v31->mEndTime = v45;
        v46 = v31->mStartTime;
        if ( v46 >= v42->mStartTime )
          v46 = v42->mStartTime;
        v31->mStartTime = v46;
        v47 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v42->mPrev;
        v48 = v31->mComponents.mNode.mPrev;
        v48->mNext = v47;
        v47->mPrev = v48;
        v47->mNext = &v31->mComponents.mNode;
        v31->mComponents.mNode.mPrev = v47;
      }
LABEL_47:
      ++v37;
      v13 = v61;
      if ( v37 >= (unsigned __int8)v61->mComponentCount )
        goto LABEL_48;
LABEL_34:
      ;
    }
  }
  v9 = v6->mFilteredEffects.p;
  while ( fx_id != *v9 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_7;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1233
// RVA: 0x1D0F70
signed __int64 __fastcall Render::FXManager::IsInBetweenTime(Render::FXManager *this, float time, float startTime, float endTime)
{
  if ( endTime < startTime )
  {
    if ( time >= startTime || time <= endTime )
      return 1i64;
  }
  else if ( startTime <= time && endTime >= time )
  {
    return 1i64;
  }
  return 0i64;
}

// File Line: 1246
// RVA: 0x1C9170
Render::FXComponentInstance *__fastcall Render::FXManager::CreateComponentFromID(unsigned int typeId, unsigned int nameId)
{
  unsigned int v2; // edi
  UFG::allocator::free_link *v3; // rax
  Render::FXComponentInstance *v4; // rax
  Render::FXComponentInstance *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  Render::FXComponentInstance *v7; // rax
  UFG::allocator::free_link *v8; // rax
  Render::FXComponentInstance *v9; // rax
  UFG::allocator::free_link *v10; // rax
  Render::FXComponentInstance *v11; // rax
  UFG::allocator::free_link *v12; // rax
  Render::FXComponentInstance *v13; // rax
  UFG::allocator::free_link *v14; // rax
  Render::FXComponentInstance *v15; // rax
  UFG::allocator::free_link *v16; // rax
  Render::FXComponentInstance *v17; // rax
  UFG::allocator::free_link *v18; // rax
  Render::FXComponentInstance *v19; // rax
  UFG::allocator::free_link *v20; // rax
  Render::FXComponentInstance *v21; // rax
  UFG::allocator::free_link *v22; // rax
  Render::FXComponentInstance *v23; // rax
  UFG::allocator::free_link *v25; // rax
  Render::FXComponentInstance *v26; // rax
  UFG::allocator::free_link *v27; // rax
  Render::FXComponentInstance *v28; // rax
  UFG::allocator::free_link *v29; // rax
  Render::FXComponentInstance *v30; // rax
  UFG::allocator::free_link *v31; // rax
  Render::FXComponentInstance *v32; // rax

  v2 = nameId;
  if ( typeId > 0x433ED8DF )
  {
    if ( typeId > 0xD6CD7114 )
    {
      switch ( typeId )
      {
        case 0xD77CCEB2:
          v31 = UFG::qMalloc(0x68ui64, "FXInstance", 0x800ui64);
          if ( v31 )
          {
            Render::AudioFXInstance::AudioFXInstance((Render::AudioFXInstance *)v31);
            v5 = v32;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xE4B8F46A:
          v29 = UFG::qMalloc(0x78ui64, "FXInstance", 0x800ui64);
          if ( v29 )
          {
            Render::VolumetricEffectInstance::VolumetricEffectInstance((Render::VolumetricEffectInstance *)v29);
            v5 = v30;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xF1734D8E:
          v27 = UFG::qMalloc(0x78ui64, "FXInstance", 0x800ui64);
          if ( v27 )
          {
            Render::GeoInstance::GeoInstance((Render::GeoInstance *)v27);
            v5 = v28;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xFF1F2832:
          v25 = UFG::qMalloc(0x1A8ui64, "FXInstance", 0x800ui64);
          if ( v25 )
          {
            Render::EffectEmitterInstance::EffectEmitterInstance((Render::EffectEmitterInstance *)v25);
            v5 = v26;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
      }
    }
    else
    {
      switch ( typeId )
      {
        case 0xD6CD7114:
          v22 = UFG::qMalloc(0x150ui64, "FXInstance", 0x1000ui64);
          if ( v22 )
          {
            Render::DynamicLightInstance::DynamicLightInstance((Render::DynamicLightInstance *)v22);
            v5 = v23;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0x69CE5438u:
          v20 = UFG::qMalloc(0x68ui64, "FXInstance", 0i64);
          if ( v20 )
          {
            Render::TrackStripInstance::TrackStripInstance((Render::TrackStripInstance *)v20);
            v5 = v21;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xA0AAE10F:
          v18 = UFG::qMalloc(0x70ui64, "FXInstance", 0x800ui64);
          if ( v18 )
          {
            Render::BeamInstance::BeamInstance((Render::BeamInstance *)v18);
            v5 = v19;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xA6535FBB:
          v16 = UFG::qMalloc(0xD0ui64, "FXInstance", 0x800ui64);
          if ( v16 )
          {
            Render::FlareInstance::FlareInstance((Render::FlareInstance *)v16);
            v5 = v17;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xAE323146:
          v14 = UFG::qMalloc(0x68ui64, "FXInstance", 0x800ui64);
          if ( v14 )
          {
            Render::DecalInstance::DecalInstance((Render::DecalInstance *)v14);
            v5 = v15;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
        case 0xB76CCFB8:
          v12 = UFG::qMalloc(0x98ui64, "FXInstance", 0x800ui64);
          if ( v12 )
          {
            Render::CoronaFlareInstance::CoronaFlareInstance((Render::CoronaFlareInstance *)v12);
            v5 = v13;
          }
          else
          {
            v5 = 0i64;
          }
          goto LABEL_73;
      }
    }
    return 0i64;
  }
  switch ( typeId )
  {
    case 0x433ED8DFu:
      v10 = UFG::qMalloc(0x98ui64, "FXInstance", 0x800ui64);
      if ( v10 )
      {
        Render::FXForceComponent::FXForceComponent((Render::FXForceComponent *)v10);
        v5 = v11;
      }
      else
      {
        v5 = 0i64;
      }
      goto LABEL_73;
    case 0x21AE1C64u:
      v8 = UFG::qMalloc(0xF8ui64, "LightningInstance", 0i64);
      if ( v8 )
      {
        Render::LightningInstance::LightningInstance((Render::LightningInstance *)v8);
        v5 = v9;
      }
      else
      {
        v5 = 0i64;
      }
      goto LABEL_73;
    case 0x354C3CDCu:
      v6 = UFG::qMalloc(0x68ui64, "ScreenParticleEmitterSettings", 0x800ui64);
      if ( v6 )
      {
        Render::ScreenParticleEmitterInstance::ScreenParticleEmitterInstance((Render::ScreenParticleEmitterInstance *)v6);
        v5 = v7;
      }
      else
      {
        v5 = 0i64;
      }
      goto LABEL_73;
  }
  if ( typeId != 0x3BEE21DC )
    return 0i64;
  v3 = UFG::qMalloc(0x108ui64, "FXInstance", 0x800ui64);
  if ( v3 )
  {
    Render::ParticleEmitterInstance::ParticleEmitterInstance((Render::ParticleEmitterInstance *)v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
LABEL_73:
  (*((void (__fastcall **)(Render::FXComponentInstance *, _QWORD))&v5->vfptr->__vecDelDtor + 1))(v5, v2);
  return v5;
}

// File Line: 1349
// RVA: 0x1CC280
void __fastcall Render::FXComponentInstance::GetBasis(Render::FXComponentInstance *this, UFG::qMatrix44 *dst)
{
  Render::FXInstance *v2; // rax
  UFG::qMatrix44 *v3; // rsi
  Render::FXComponentInstance *v4; // rdi
  UFG::SimComponent *v5; // rbx
  UFG::qMatrix44 *v6; // rdx

  v2 = this->mContainer;
  v3 = dst;
  v4 = this;
  v5 = v2->mParentNode.m_pPointer;
  if ( !v5 || v2->mBasisRelativeToParent )
  {
    v6 = &v2->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mParentNode.m_pPointer);
    v6 = (UFG::qMatrix44 *)&v5[2];
  }
  Render::FXInstance::CalcBasisHelper(
    v3,
    v6,
    (UFG::qResourceHandle *)&v4->mContainer->mSettings.mPrev,
    v4->mComponentIndex,
    v4->mStartTime);
}

// File Line: 1362
// RVA: 0x1C3580
void __fastcall Render::FXComponentInstance::~FXComponentInstance(Render::FXComponentInstance *this)
{
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v1; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v3; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v1 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

