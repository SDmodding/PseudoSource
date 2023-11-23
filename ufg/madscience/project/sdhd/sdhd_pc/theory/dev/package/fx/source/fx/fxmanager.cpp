// File Line: 70
// RVA: 0x1CA5A0
UFG::allocator::free_link *__fastcall Render::FXOverride::CreateOverride(
        const char *allocationName,
        UFG::allocator::free_link *memoryPool)
{
  UFG::allocator::free_link *result; // rax

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
  result[11].mNext = memoryPool;
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
  char *mTriangleInfo; // rdx

  mTriangleInfo = (char *)this->mTriangleInfo;
  if ( mTriangleInfo )
    UFG::qMemoryPool::Free(this->mMemoryPool, mTriangleInfo);
  --Render::FXOverride::sNumInstancesInService;
}

// File Line: 141
// RVA: 0x146AFC0
__int64 dynamic_initializer_for__Render::FXInstance::smOcclusionList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::FXInstance::smOcclusionList__);
}

// File Line: 150
// RVA: 0x1C1220
void __fastcall Render::FXInstance::FXInstance(
        Render::FXInstance *this,
        UFG::qMatrix44 *basis,
        UFG::TransformNodeComponent *parent,
        Render::FXOverride *overrideObject,
        char useRelativeBasis)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mParentNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  float y; // xmm2_4
  float z; // xmm1_4
  float w; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  UFG::qMatrix44 *v35; // rax
  UFG::qVector4 v36; // xmm2
  UFG::qVector4 v37; // xmm1
  UFG::qVector4 v38; // xmm0
  CullManager *v39; // rax
  UFG::qVector4 v40; // xmm3
  UFG::qMatrix44 result; // [rsp+38h] [rbp-70h] BYREF

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mPrev = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
  UFG::qResourceHandle::qResourceHandle(&this->mSettings);
  this->mComponents.mNode.mPrev = &this->mComponents.mNode;
  this->mComponents.mNode.mNext = &this->mComponents.mNode;
  this->mBasisRelativeToParent = useRelativeBasis;
  this->mOcclusionQuery = 0i64;
  p_mParentNode = &this->mParentNode;
  this->mParentNode.mPrev = &this->mParentNode;
  this->mParentNode.mNext = &this->mParentNode;
  this->mParentNode.m_pPointer = parent;
  if ( parent )
  {
    mPrev = parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    mPrev->mNext = p_mParentNode;
    p_mParentNode->mPrev = mPrev;
    this->mParentNode.mNext = &parent->m_SafePointerList.mNode;
    parent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mParentNode;
  }
  y = basis->v0.y;
  z = basis->v0.z;
  w = basis->v0.w;
  this->mBasis.v0.x = basis->v0.x;
  this->mBasis.v0.y = y;
  this->mBasis.v0.z = z;
  this->mBasis.v0.w = w;
  v14 = basis->v1.y;
  v15 = basis->v1.z;
  v16 = basis->v1.w;
  this->mBasis.v1.x = basis->v1.x;
  this->mBasis.v1.y = v14;
  this->mBasis.v1.z = v15;
  this->mBasis.v1.w = v16;
  v17 = basis->v2.y;
  v18 = basis->v2.z;
  v19 = basis->v2.w;
  this->mBasis.v2.x = basis->v2.x;
  this->mBasis.v2.y = v17;
  this->mBasis.v2.z = v18;
  this->mBasis.v2.w = v19;
  v20 = basis->v3.y;
  v21 = basis->v3.z;
  v22 = basis->v3.w;
  this->mBasis.v3.x = basis->v3.x;
  this->mBasis.v3.y = v20;
  this->mBasis.v3.z = v21;
  this->mBasis.v3.w = v22;
  v23 = basis->v0.y;
  v24 = basis->v0.z;
  v25 = basis->v0.w;
  this->mRelativeBasis.v0.x = basis->v0.x;
  this->mRelativeBasis.v0.y = v23;
  this->mRelativeBasis.v0.z = v24;
  this->mRelativeBasis.v0.w = v25;
  v26 = basis->v1.y;
  v27 = basis->v1.z;
  v28 = basis->v1.w;
  this->mRelativeBasis.v1.x = basis->v1.x;
  this->mRelativeBasis.v1.y = v26;
  this->mRelativeBasis.v1.z = v27;
  this->mRelativeBasis.v1.w = v28;
  v29 = basis->v2.y;
  v30 = basis->v2.z;
  v31 = basis->v2.w;
  this->mRelativeBasis.v2.x = basis->v2.x;
  this->mRelativeBasis.v2.y = v29;
  this->mRelativeBasis.v2.z = v30;
  this->mRelativeBasis.v2.w = v31;
  v32 = basis->v3.y;
  v33 = basis->v3.z;
  v34 = basis->v3.w;
  this->mRelativeBasis.v3.x = basis->v3.x;
  this->mRelativeBasis.v3.y = v32;
  this->mRelativeBasis.v3.z = v33;
  this->mRelativeBasis.v3.w = v34;
  if ( overrideObject )
    ++overrideObject->mReferenceCount;
  this->mStateBlockOverride.m_pPointer = overrideObject;
  if ( this->mBasisRelativeToParent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(parent);
    v35 = UFG::qMatrix44::operator*(&this->mRelativeBasis, &result, &parent->mWorldTransform);
    v36 = v35->v1;
    v37 = v35->v2;
    v38 = v35->v3;
    this->mBasis.v0 = v35->v0;
    this->mBasis.v1 = v36;
    this->mBasis.v2 = v37;
    this->mBasis.v3 = v38;
  }
  v39 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v39, &this->mCullResults, &this->mCullInfo, 0i64, 0i64, 0i64);
  v40 = 0i64;
  v40.x = (float)1;
  this->mCullMatrix.v0 = v40;
  this->mCullMatrix.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v40, (__m128)v40, 81);
  this->mCullMatrix.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v40, (__m128)v40, 69);
  this->mCullMatrix.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v40, (__m128)v40, 21);
  this->mCullInfo->mpLocalWorld = &this->mCullMatrix.v0.x;
}

// File Line: 162
// RVA: 0x1C36F0
void __fastcall Render::FXInstance::~FXInstance(Render::FXInstance *this, int a2, int a3)
{
  Render::FXInstance *p_mNext; // rcx
  Render::FXInstance *p_mUID; // rbx
  FX::HardwareOcclusionQuery *mOcclusionQuery; // rbx
  Illusion::IOcclusion *OcclusionSystem; // rax
  Illusion::IOcclusion *v8; // rsi
  __int64 mQueryID; // rdx
  __int64 mUnculledQueryID; // rdx
  CullManager *v11; // rax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v13; // rbx
  char *mTriangleInfo; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mParentNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qList<Render::FXComponentInstance,Render::FXComponentInstance,1,0> *p_mComponents; // rbx
  Render::FXInstance *i; // rax
  UFG::qBaseNodeRB **mChild; // rdx
  UFG::qBaseNodeRB *v23; // rcx
  UFG::qBaseNodeRB *v24; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v25; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v26; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v28; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v29; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v30; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v31; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v32; // rax

  if ( this->mAudioId
    && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
  {
    UFG::AudioVFXManager::Remove((UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)this);
  }
  p_mNext = (Render::FXInstance *)&this->mComponents.mNode.mNext[-1].mNext;
  if ( p_mNext != (Render::FXInstance *)&this->mSettings.mNameUID )
  {
    do
    {
      p_mUID = (Render::FXInstance *)&p_mNext->mNode.mChild[1][-1].mUID;
      (*(void (__fastcall **)(Render::FXInstance *, _QWORD))&p_mNext->mNode.mParent->mUID)(p_mNext, 0i64);
      p_mNext = p_mUID;
    }
    while ( p_mUID != (Render::FXInstance *)&this->mSettings.mNameUID );
  }
  mOcclusionQuery = this->mOcclusionQuery;
  if ( mOcclusionQuery )
  {
    OcclusionSystem = Render::GetOcclusionSystem();
    v8 = OcclusionSystem;
    mQueryID = mOcclusionQuery->mQueryID;
    if ( (_DWORD)mQueryID != -1 )
    {
      OcclusionSystem->vfptr->ReleaseQueryHandle(OcclusionSystem, mQueryID, mOcclusionQuery->mTarget);
      mOcclusionQuery->mQueryID = -1;
    }
    mUnculledQueryID = mOcclusionQuery->mUnculledQueryID;
    if ( (_DWORD)mUnculledQueryID != -1 )
    {
      v8->vfptr->ReleaseQueryHandle(v8, mUnculledQueryID, mOcclusionQuery->mTarget);
      mOcclusionQuery->mUnculledQueryID = -1;
    }
    operator delete[](mOcclusionQuery);
  }
  v11 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v11, this->mCullResults, this->mCullInfo);
  m_pPointer = this->mStateBlockOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v13 = this->mStateBlockOverride.m_pPointer;
    if ( v13->mReferenceCount <= 0 )
    {
      if ( v13 )
      {
        mTriangleInfo = (char *)v13->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v13->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v13);
      }
      this->mStateBlockOverride.m_pPointer = 0i64;
    }
  }
  p_mParentNode = &this->mParentNode;
  if ( this->mParentNode.m_pPointer )
  {
    mPrev = p_mParentNode->mPrev;
    mNext = this->mParentNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mParentNode->mPrev = p_mParentNode;
    this->mParentNode.mNext = &this->mParentNode;
  }
  this->mParentNode.m_pPointer = 0i64;
  v18 = p_mParentNode->mPrev;
  v19 = this->mParentNode.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mParentNode->mPrev = p_mParentNode;
  this->mParentNode.mNext = &this->mParentNode;
  p_mComponents = &this->mComponents;
  for ( i = (Render::FXInstance *)&this->mComponents.mNode.mNext[-1].mNext;
        i != (Render::FXInstance *)&this->mSettings.mNameUID;
        i = (Render::FXInstance *)&this->mComponents.mNode.mNext[-1].mNext )
  {
    mChild = i->mNode.mChild;
    v23 = i->mNode.mChild[0];
    v24 = i->mNode.mChild[1];
    v23->mChild[0] = v24;
    v24->mParent = v23;
    *mChild = (UFG::qBaseNodeRB *)mChild;
    mChild[1] = (UFG::qBaseNodeRB *)mChild;
    if ( mChild != (UFG::qBaseNodeRB **)8 )
      ((void (__fastcall *)(UFG::qBaseNodeRB **, __int64))(*(mChild - 1))->mParent)(mChild - 1, 1i64);
  }
  v25 = p_mComponents->mNode.mPrev;
  v26 = this->mComponents.mNode.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_mComponents->mNode.mPrev = &p_mComponents->mNode;
  this->mComponents.mNode.mNext = &this->mComponents.mNode;
  Inventory = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v28, 0xED341A8D);
    `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettings, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSettings);
  v29 = this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev;
  v30 = this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
  v31 = this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mPrev;
  v32 = this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext;
  v31->mNext = v32;
  v32->mPrev = v31;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mPrev = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
  this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
}

// File Line: 176
// RVA: 0x1CC300
UFG::qMatrix44 *__fastcall Render::FXInstance::GetBasis(Render::FXInstance *this)
{
  UFG::SimComponent *m_pPointer; // rbx

  m_pPointer = this->mParentNode.m_pPointer;
  if ( !m_pPointer || this->mBasisRelativeToParent )
    return &this->mBasis;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mParentNode.m_pPointer);
  return (UFG::qMatrix44 *)&m_pPointer[2];
}

// File Line: 181
// RVA: 0x1C7DD0
void __fastcall Render::FXInstance::CalcBasisHelper(
        UFG::qMatrix44 *dst,
        UFG::qMatrix44 *init,
        UFG::qResourceHandle *fxHandle,
        unsigned int componentIndex,
        float startTime)
{
  UFG::qResourceData *mData; // rcx
  __int64 v8; // rdi
  int v9; // ecx
  float mSimTimeMSec_low; // xmm9_4
  float v11; // xmm10_4
  float v12; // xmm9_4
  float v13; // xmm2_4
  float v14; // xmm10_4
  int v15; // ecx
  UFG::qMatrix44 *v16; // rax
  UFG::qMatrix44 *v17; // rax
  UFG::qVector4 v18; // xmm1
  UFG::qVector4 v19; // xmm2
  UFG::qVector4 v20; // xmm3
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm1_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float v43; // xmm0_4
  UFG::qVector3 radians; // [rsp+20h] [rbp-108h] BYREF
  UFG::qMatrix44 rot; // [rsp+30h] [rbp-F8h] BYREF
  UFG::qMatrix44 v46; // [rsp+70h] [rbp-B8h] BYREF
  UFG::qMatrix44 result; // [rsp+B0h] [rbp-78h] BYREF

  mData = fxHandle->mData;
  if ( componentIndex < BYTE1(mData[1].mTypeUID) && (v8 = (__int64)&mData[1].mDebugName[148 * componentIndex + 12]) != 0 )
  {
    v9 = *(_DWORD *)(v8 + 36);
    if ( v9 )
    {
      mSimTimeMSec_low = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
      if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
        mSimTimeMSec_low = mSimTimeMSec_low + 1.8446744e19;
      v11 = (float)(mSimTimeMSec_low * 0.001) - startTime;
      v12 = (float)((float)(v11 * *(float *)(v8 + 72)) * 2.0) * 3.1415927;
      v13 = (float)((float)(v11 * *(float *)(v8 + 64)) * 2.0) * 3.1415927;
      v14 = (float)((float)(v11 * *(float *)(v8 + 68)) * 2.0) * 3.1415927;
      v15 = v9 - 1;
      if ( v15 )
      {
        if ( v15 == 1 )
        {
          radians.x = (float)((float)((float)(sinf(v13) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 52) - *(float *)(v8 + 40)))
                    + *(float *)(v8 + 40);
          radians.y = (float)((float)((float)(sinf(v14) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 56) - *(float *)(v8 + 44)))
                    + *(float *)(v8 + 44);
          radians.z = (float)((float)((float)(sinf(v12) + 1.0) * 0.5)
                            * (float)(*(float *)(v8 + 60) - *(float *)(v8 + 48)))
                    + *(float *)(v8 + 48);
        }
      }
      else
      {
        radians.x = v13;
        radians.y = v14;
        radians.z = v12;
      }
      UFG::qRotationMatrixXYZDepreciated(&rot, &radians);
      rot.v3 = (UFG::qVector4)_xmm;
      v16 = UFG::qMatrix44::operator*(&rot, &result, (UFG::qMatrix44 *)(v8 + 76));
      v17 = UFG::qMatrix44::operator*(v16, &v46, init);
    }
    else
    {
      v17 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v8 + 76), &v46, init);
    }
    v18 = v17->v1;
    v19 = v17->v2;
    v20 = v17->v3;
    dst->v0 = v17->v0;
    dst->v1 = v18;
    dst->v2 = v19;
    dst->v3 = v20;
    if ( *(_BYTE *)(v8 + 24) )
    {
      v21 = *(float *)(v8 + 12);
      v22 = *(float *)(v8 + 16);
      v23 = *(float *)(v8 + 20);
    }
    else
    {
      v24 = *(float *)(v8 + 12);
      v25 = *(float *)(v8 + 16);
      v26 = (float)(v25 * dst->v1.z) + (float)(v24 * dst->v0.z);
      v27 = (float)(v25 * dst->v1.x) + (float)(v24 * dst->v0.x);
      v28 = (float)(*(float *)(v8 + 16) * dst->v1.y) + (float)(v24 * dst->v0.y);
      v29 = *(float *)(v8 + 20);
      v21 = v27 + (float)(v29 * dst->v2.x);
      v22 = v28 + (float)(v29 * dst->v2.y);
      v23 = v26 + (float)(v29 * dst->v2.z);
    }
    v30 = v22 + dst->v3.y;
    v31 = v23 + dst->v3.z;
    dst->v3.x = v21 + dst->v3.x;
    dst->v3.y = v30;
    dst->v3.z = v31;
    dst->v3.w = 1.0;
  }
  else
  {
    z = UFG::qVector4::msZero.z;
    w = UFG::qVector4::msZero.w;
    x = UFG::qVector4::msZero.x;
    dst->v0.y = UFG::qVector4::msZero.y;
    dst->v0.z = z;
    dst->v0.x = x;
    dst->v0.w = w;
    y = UFG::qVector4::msZero.y;
    v36 = UFG::qVector4::msZero.z;
    v37 = UFG::qVector4::msZero.w;
    dst->v1.x = UFG::qVector4::msZero.x;
    dst->v1.y = y;
    dst->v1.z = v36;
    dst->v1.w = v37;
    v38 = UFG::qVector4::msZero.z;
    v39 = UFG::qVector4::msZero.w;
    v40 = UFG::qVector4::msZero.x;
    dst->v2.y = UFG::qVector4::msZero.y;
    dst->v2.x = v40;
    dst->v2.z = v38;
    dst->v2.w = v39;
    v41 = UFG::qVector4::msZero.z;
    v42 = UFG::qVector4::msZero.w;
    v43 = UFG::qVector4::msZero.x;
    dst->v3.y = UFG::qVector4::msZero.y;
    dst->v3.z = v41;
    dst->v3.x = v43;
    dst->v3.w = v42;
  }
}

// File Line: 273
// RVA: 0x1CB710
void __fastcall Render::FXInstance::DrawOcclusionObject(Render::FXInstance *this, Render::View *view)
{
  UFG::TransformNodeComponent *m_pPointer; // rdi
  UFG::qVector4 v3; // xmm2
  UFG::qMatrix44 *p_mBasis; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  FX::HardwareOcclusionQuery *mOcclusionQuery; // rcx
  UFG::qMatrix44 probeTransform; // [rsp+20h] [rbp-48h] BYREF

  m_pPointer = (UFG::TransformNodeComponent *)this->mParentNode.m_pPointer;
  v3 = 0i64;
  v3.x = (float)1;
  probeTransform.v0 = v3;
  probeTransform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 21);
  probeTransform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 81);
  probeTransform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 69);
  if ( !m_pPointer || this->mBasisRelativeToParent )
  {
    p_mBasis = &this->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
    p_mBasis = &m_pPointer->mWorldTransform;
  }
  y = p_mBasis->v3.y;
  z = p_mBasis->v3.z;
  mOcclusionQuery = this->mOcclusionQuery;
  probeTransform.v3.x = p_mBasis->v3.x;
  probeTransform.v3.y = y;
  LODWORD(probeTransform.v3.w) = (_DWORD)FLOAT_1_0;
  probeTransform.v3.z = z;
  FX::HardwareOcclusionQuery::DrawSphere(mOcclusionQuery, view, &probeTransform);
}

// File Line: 284
// RVA: 0x1CB6B0
void __fastcall Render::FXManager::DrawCullingAABBs(Render::FXManager *this, Render::View *view)
{
  Render::FXInstance *v3; // rcx
  UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *v4; // rbx

  v3 = (Render::FXInstance *)&Render::FXInstance::smOcclusionList.mNode.mNext[-2];
  if ( (UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *)&Render::FXInstance::smOcclusionList.mNode.mNext[-2] != &Render::FXInstance::smOcclusionList - 2 )
  {
    do
    {
      v4 = (UFG::qList<Render::FXInstance,Render::FXInstance_OcclusionList,1,0> *)&v3->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext[-2];
      Render::FXInstance::DrawOcclusionObject(v3, view);
      v3 = (Render::FXInstance *)v4;
    }
    while ( v4 != &Render::FXInstance::smOcclusionList - 2 );
  }
}

// File Line: 350
// RVA: 0x1D8FA0
void __fastcall Render::FXInstance::Update(
        Render::FXInstance *this,
        UFG::qVector3 *cam_pos,
        char main_view_cull_index,
        float simTime)
{
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *v9; // rax
  UFG::qVector4 v10; // xmm2
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::SimComponent *v13; // rbx
  UFG::qMatrix44 *p_mBasis; // r8
  float v15; // xmm2_4
  char v16; // r14
  UFG::qResourceData *mData; // rcx
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
  bool v28; // r12
  unsigned int *p_mNameUID; // r15
  unsigned int mNameUID; // eax
  float v31; // xmm9_4
  float x; // xmm11_4
  float v33; // xmm8_4
  float y; // xmm10_4
  float v35; // xmm5_4
  float z; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm7_4
  float v40; // xmm10_4
  Render::FXComponentInstance *p_mNext; // rbx
  Render::FXComponentInstance *v42; // rsi
  Render::FXComponentInstance::eForceSuspendedState mForceSuspendState; // eax
  UFG::qResourceData *v44; // rcx
  unsigned int mComponentIndex; // edx
  __int64 v46; // rdx
  unsigned __int8 v47; // al
  UFG::qVector3 end; // [rsp+38h] [rbp-100h] BYREF
  UFG::qVector3 start; // [rsp+48h] [rbp-F0h] BYREF
  UFG::qMatrix44 result; // [rsp+58h] [rbp-E0h] BYREF

  if ( this->mBasisRelativeToParent )
  {
    m_pPointer = this->mParentNode.m_pPointer;
    if ( m_pPointer )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mParentNode.m_pPointer);
      v9 = UFG::qMatrix44::operator*(&this->mRelativeBasis, &result, (UFG::qMatrix44 *)&m_pPointer[2]);
      v10 = v9->v1;
      v11 = v9->v2;
      v12 = v9->v3;
      this->mBasis.v0 = v9->v0;
      this->mBasis.v1 = v10;
      this->mBasis.v2 = v11;
      this->mBasis.v3 = v12;
    }
  }
  v13 = this->mParentNode.m_pPointer;
  if ( !v13 || this->mBasisRelativeToParent )
  {
    p_mBasis = &this->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mParentNode.m_pPointer);
    p_mBasis = (UFG::qMatrix44 *)&v13[2];
  }
  v15 = (float)((float)((float)(cam_pos->y - p_mBasis->v3.y) * (float)(cam_pos->y - p_mBasis->v3.y))
              + (float)((float)(cam_pos->x - p_mBasis->v3.x) * (float)(cam_pos->x - p_mBasis->v3.x)))
      + (float)((float)(cam_pos->z - p_mBasis->v3.z) * (float)(cam_pos->z - p_mBasis->v3.z));
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
  mData = this->mSettings.mData;
  if ( mData )
  {
    v18 = this->mStateBlockOverride.m_pPointer;
    if ( !v18 || v18->modelToEmitFromUID == -1 )
    {
      v19 = *(float *)&mData[1].mNode.mParent;
      v20 = *((float *)&mData[1].mNode.mParent + 1);
      v21 = *(float *)mData[1].mNode.mChild;
      v22 = *((float *)mData[1].mNode.mChild + 1);
      v23 = *(float *)&mData[1].mNode.mChild[1];
      v24 = *((float *)&mData[1].mNode.mChild[1] + 1);
    }
    else
    {
      v19 = v18->mAABBMin[0];
      v20 = v18->mAABBMin[1];
      v21 = v18->mAABBMin[2];
      v22 = v18->mAABBMax[0];
      v23 = v18->mAABBMax[1];
      v24 = v18->mAABBMax[2];
    }
    this->mCullInfo->mAABBMin[0] = v19;
    this->mCullInfo->mAABBMin[1] = v20;
    this->mCullInfo->mAABBMin[2] = v21;
    this->mCullInfo->mAABBMax[0] = v22;
    this->mCullInfo->mAABBMax[1] = v23;
    this->mCullInfo->mAABBMax[2] = v24;
    v25 = p_mBasis->v1;
    v26 = p_mBasis->v2;
    v27 = p_mBasis->v3;
    this->mCullMatrix.v0 = p_mBasis->v0;
    this->mCullMatrix.v1 = v25;
    this->mCullMatrix.v2 = v26;
    this->mCullMatrix.v3 = v27;
    this->mCullInfo->mPixelScaleBias = 0;
    this->mCullInfo->mViewsCulled = ~(1 << main_view_cull_index);
  }
  v28 = 0;
  p_mNameUID = &this->mSettings.mNameUID;
  mNameUID = this->mSettings.mNameUID;
  if ( mNameUID == 0x6A0A159B || mNameUID == 0xD2E000A1 || mNameUID == 0x8F9B2D6D )
  {
    v31 = (float)(p_mBasis->v1.x + p_mBasis->v0.x) * 0.0;
    x = p_mBasis->v2.x;
    v33 = (float)(p_mBasis->v1.y + p_mBasis->v0.y) * 0.0;
    y = p_mBasis->v2.y;
    v35 = (float)(p_mBasis->v1.z + p_mBasis->v0.z) * 0.0;
    z = p_mBasis->v2.z;
    v37 = (float)((float)(z * 0.5) + v35) + p_mBasis->v3.z;
    v38 = (float)((float)(y * 0.5) + v33) + p_mBasis->v3.y;
    start.x = (float)((float)(x * 0.5) + v31) + p_mBasis->v3.x;
    start.y = v38;
    start.z = v37;
    v39 = (float)((float)(z * 3.0) + v35) + p_mBasis->v3.z;
    v40 = (float)((float)(y * 3.0) + v33) + p_mBasis->v3.y;
    end.x = (float)((float)(x * 3.0) + v31) + p_mBasis->v3.x;
    end.y = v40;
    end.z = v39;
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)&result,
      0.050000001,
      0x18u,
      PhantomBehaviour_Simple);
    v28 = UFG::BasePhysicsSystem::CastShape(
            UFG::BasePhysicsSystem::mInstance,
            (UFG::ShapeCasterCollector *)&result,
            &start,
            &end);
    UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&result);
  }
  p_mNext = (Render::FXComponentInstance *)&this->mComponents.mNode.mNext[-1].mNext;
  if ( p_mNext != (Render::FXComponentInstance *)p_mNameUID )
  {
    while ( 1 )
    {
      v42 = (Render::FXComponentInstance *)&p_mNext->mNext[-1].mNext;
      if ( v28 )
        goto LABEL_26;
      mForceSuspendState = p_mNext->mForceSuspendState;
      if ( mForceSuspendState == eSuspending )
      {
        ((void (__fastcall *)(Render::FXComponentInstance *))p_mNext->vfptr->Suspend)(p_mNext);
        p_mNext->mForceSuspendState = eSuspended;
      }
      else if ( mForceSuspendState == eUnsuspending && p_mNext->mIsActive )
      {
        ((void (__fastcall *)(Render::FXComponentInstance *))p_mNext->vfptr->Resume)(p_mNext);
        p_mNext->mForceSuspendState = eUnsuspended;
      }
      if ( simTime > p_mNext->mEndTime )
      {
        if ( p_mNext->mIsActive )
        {
          if ( !p_mNext->mIsSuspended )
            ((void (__fastcall *)(Render::FXComponentInstance *, UFG::qVector3 *))p_mNext->vfptr->Update)(
              p_mNext,
              cam_pos);
          p_mNext->vfptr->Deactivate(p_mNext, 0);
        }
        goto LABEL_47;
      }
      if ( simTime >= p_mNext->mStartTime )
      {
        if ( !p_mNext->mIsActive )
          p_mNext->vfptr->Activate(p_mNext);
        v44 = this->mSettings.mData;
        if ( !v44 )
        {
LABEL_45:
          if ( !p_mNext->mIsSuspended )
            ((void (__fastcall *)(Render::FXComponentInstance *, UFG::qVector3 *))p_mNext->vfptr->Update)(
              p_mNext,
              cam_pos);
          goto LABEL_47;
        }
        mComponentIndex = p_mNext->mComponentIndex;
        if ( mComponentIndex < BYTE1(v44[1].mTypeUID) )
        {
          v46 = (__int64)&v44[1].mDebugName[148 * mComponentIndex + 12];
          if ( v46 )
            break;
        }
      }
LABEL_47:
      p_mNext = v42;
      if ( v42 == (Render::FXComponentInstance *)p_mNameUID )
        return;
    }
    v47 = *(_BYTE *)(v46 + 25);
    if ( (v47 & 8) != 0 || (v47 & (unsigned __int8)v16) != 0 )
      goto LABEL_45;
LABEL_26:
    ((void (__fastcall *)(Render::FXComponentInstance *))p_mNext->vfptr->Suspend)(p_mNext);
    goto LABEL_47;
  }
}

// File Line: 478
// RVA: 0x1CBC00
void __fastcall Render::FXInstance::EnableOcclusionCulling(Render::FXInstance *this)
{
  FX::HardwareOcclusionQuery *v2; // rax
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *v3; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *mPrev; // rax

  if ( !this->mOcclusionQuery )
  {
    v2 = (FX::HardwareOcclusionQuery *)UFG::qMalloc(0x18ui64, "FXInstance::mOcclusionQuery", 0i64);
    if ( v2 )
    {
      *(_QWORD *)&v2->mQueryID = -1i64;
      v2->mTarget = 0i64;
    }
    this->mOcclusionQuery = v2;
    v3 = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
    if ( v3->mPrev == v3
      && this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext == &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> )
    {
      mPrev = Render::FXInstance::smOcclusionList.mNode.mPrev;
      Render::FXInstance::smOcclusionList.mNode.mPrev->mNext = v3;
      v3->mPrev = mPrev;
      this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext = (UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList> *)&Render::FXInstance::smOcclusionList;
      Render::FXInstance::smOcclusionList.mNode.mPrev = &this->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>;
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
  Render::gFXManager.mCamTransformNode.mPrev = &Render::gFXManager.mCamTransformNode;
  Render::gFXManager.mCamTransformNode.mNext = &Render::gFXManager.mCamTransformNode;
  Render::gFXManager.mCamTransformNode.m_pPointer = 0i64;
  Render::gFXManager.mEffectId = 0;
  Render::gFXManager.mLastUpdateTime = 0.0;
  Render::gFXManager.mFXOverrideStateParamIndex = -1;
  Render::gFXManager.mDisplayFXInfo = 0;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gFXManager__);
}

// File Line: 526
// RVA: 0x1C3950
void __fastcall Render::FXManager::~FXManager(Render::FXManager *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mCamTransformNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v8; // rbx
  char *mTriangleInfo; // rdx
  unsigned int *p; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v11; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v12; // rax

  p_mCamTransformNode = &this->mCamTransformNode;
  if ( this->mCamTransformNode.m_pPointer )
  {
    mPrev = p_mCamTransformNode->mPrev;
    mNext = p_mCamTransformNode->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCamTransformNode->mPrev = p_mCamTransformNode;
    p_mCamTransformNode->mNext = p_mCamTransformNode;
  }
  p_mCamTransformNode->m_pPointer = 0i64;
  v5 = p_mCamTransformNode->mPrev;
  v6 = p_mCamTransformNode->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mCamTransformNode->mPrev = p_mCamTransformNode;
  p_mCamTransformNode->mNext = p_mCamTransformNode;
  m_pPointer = this->mStateBlockDefaultOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v8 = this->mStateBlockDefaultOverride.m_pPointer;
    if ( v8->mReferenceCount <= 0 )
    {
      if ( v8 )
      {
        mTriangleInfo = (char *)v8->mTriangleInfo;
        if ( mTriangleInfo )
          UFG::qMemoryPool::Free(v8->mMemoryPool, mTriangleInfo);
        --Render::FXOverride::sNumInstancesInService;
        operator delete[](v8);
      }
      this->mStateBlockDefaultOverride.m_pPointer = 0i64;
    }
  }
  p = this->mFilteredEffects.p;
  if ( p )
    operator delete[](p);
  this->mFilteredEffects.p = 0i64;
  *(_QWORD *)&this->mFilteredEffects.size = 0i64;
  UFG::qList<Render::FXInstance,Render::FXInstance_UpdateList,1,0>::DeleteNodes(&this->mEffectsList);
  v11 = this->mEffectsList.mNode.mPrev;
  v12 = this->mEffectsList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->mEffectsList.mNode.mPrev = &this->mEffectsList.mNode;
  this->mEffectsList.mNode.mNext = &this->mEffectsList.mNode;
  UFG::qTreeRB<Render::FXInstance,Render::FXInstance,1>::~qTreeRB<Render::FXInstance,Render::FXInstance,1>(&this->mEffectsTree);
}

// File Line: 532
// RVA: 0x1CE540
void __fastcall Render::FXManager::Init(Render::FXManager *this, unsigned int max_particle_buffers_HACK)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rdi
  unsigned int v5; // eax
  UFG::SimComponent *v6; // rax
  UFG::SimComponent *v7; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mCamTransformNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  hkResourceHandle *v12; // rax
  unsigned int v13; // eax
  UFG::allocator::free_link *Override; // rax
  UFG::qString v15; // [rsp+58h] [rbp-30h] BYREF

  if ( !this->mCamTransformNode.m_pPointer )
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "mCamTransformNode", 0i64, 1u);
    if ( v4 )
    {
      v5 = UFG::qStringHashUpper32("mCamTransformNode", -1);
      UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v4, v5, 0i64, 0);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    p_mCamTransformNode = &this->mCamTransformNode;
    if ( this->mCamTransformNode.m_pPointer )
    {
      mPrev = p_mCamTransformNode->mPrev;
      mNext = this->mCamTransformNode.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mCamTransformNode->mPrev = p_mCamTransformNode;
      this->mCamTransformNode.mNext = &this->mCamTransformNode;
    }
    this->mCamTransformNode.m_pPointer = v7;
    if ( v7 )
    {
      v11 = v7->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_mCamTransformNode;
      p_mCamTransformNode->mPrev = v11;
      this->mCamTransformNode.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = p_mCamTransformNode;
    }
  }
  UFG::TransformNodeComponent::SetWorldTransform(
    (UFG::TransformNodeComponent *)this->mCamTransformNode.m_pPointer,
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
  this->mRenderRainWhileInside = 0;
  UFG::qString::qString(&v15, "Data\\Global\\Effects.bin");
  v12 = (hkResourceHandle *)UFG::HotSwapFileManager::Get();
  TargetVisibleInAIDataCondition::CreateClone(v12);
  v13 = UFG::qStringHash32("cbFXOverrideSettings", 0xFFFFFFFF);
  this->mFXOverrideStateParamIndex = Illusion::StateSystem::AddParam(
                                       &Illusion::gStateSystem,
                                       v13,
                                       "cbFXOverrideSettings",
                                       0);
  Override = Render::FXOverride::CreateOverride("FXOverride Default", 0i64);
  FX::SharedPointer<Render::FXOverride>::Set(&this->mStateBlockDefaultOverride, (Render::FXOverride *)Override);
  UFG::qString::~qString(&v15);
}

// File Line: 648
// RVA: 0x1CBDE0
UFG::qBaseTreeRB *__fastcall Render::FXManager::FindEffect(Render::FXManager *this, unsigned int fxId)
{
  if ( fxId != -1 && fxId )
    return UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
  else
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
          return 1;
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
void __fastcall Render::FXManager::KillEffect(
        Render::FXManager *this,
        unsigned int fxId,
        Render::eFXKillOption killOption)
{
  UFG::qBaseTreeRB *v6; // rax
  int v7; // edx
  hkGeometryUtils::IVertices *v8; // rcx
  int v9; // r8d
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *v10; // rbx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mPrev; // rcx
  UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *mNext; // rax
  int v13; // r8d

  if ( fxId != -1 )
  {
    if ( fxId )
    {
      v6 = UFG::qBaseTreeRB::Get(&this->mEffectsTree.mTree, fxId);
      v10 = (UFG::qNode<UFG::AudioVFXNode,UFG::AudioVFXNode> *)v6;
      if ( v6 )
      {
        if ( *(_QWORD *)&v6[1].mNULL.mUID
          && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v8, v7, v9) )
        {
          UFG::AudioVFXManager::Remove(v10);
        }
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v10);
        mPrev = v10[3].mPrev;
        mNext = v10[3].mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v10[3].mPrev = v10 + 3;
        v10[3].mNext = v10 + 3;
        Render::FXInstance::~FXInstance((Render::FXInstance *)v10, (_DWORD)v10 + 48, v13);
        operator delete[](v10);
      }
    }
  }
  if ( killOption == FXKILLOPTION_ERASE_EMITTED_OBJECTS )
    Render::ParticleEmitterManager::KillBuffersWithParent(&Render::gParticleEmitterManager, fxId);
}

// File Line: 771
// RVA: 0x1D12F0
void __fastcall Render::FXManager::KillAllEffects(Render::FXManager *this)
{
  unsigned int *p_mUID; // rsi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mNext; // rdx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mPrev; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v5; // rax
  Render::FXInstance *v6; // rbx
  int v7; // edx
  int v8; // r8d
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *p_mNode; // r8
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v10; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v13; // rax
  unsigned int v14; // edi
  UFG::qArray<Render::ParticleEmitterBuffer *,0> *activeBuffers; // rbx

  p_mUID = &this->mEffectsTree.mTree.mRoot.mUID;
  while ( (unsigned int *)&this->mEffectsList.mNode.mNext[-3] != p_mUID )
  {
    mNext = this->mEffectsList.mNode.mNext;
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v6 = (Render::FXInstance *)&mNext[-3];
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&mNext[-3]);
    if ( v6 )
    {
      Render::FXInstance::~FXInstance(v6, v7, v8);
      operator delete[](v6);
    }
  }
  p_mNode = stru_142366970.mNode.mNext;
  if ( (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)stru_142366970.mNode.mNext != &stru_142366970 )
  {
    do
    {
      v10 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)p_mNode->mNext;
      v11 = p_mNode->mPrev;
      v11->mNext = &v10->mNode;
      v10->mNode.mPrev = v11;
      p_mNode->mPrev = p_mNode;
      p_mNode->mNext = p_mNode;
      v12 = p_mNode->mPrev;
      v13 = p_mNode->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      p_mNode->mPrev = p_mNode;
      p_mNode->mNext = p_mNode;
      p_mNode->mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)unk_142366958;
      unk_142366958 = p_mNode;
      --unk_142366964;
      p_mNode = &v10->mNode;
    }
    while ( v10 != &stru_142366970 );
  }
  v14 = 0;
  activeBuffers = Render::gParticleEmitterManager.activeBuffers;
  do
  {
    while ( activeBuffers->size )
      Render::ParticleEmitterManager::AddToFreeBufferList(&Render::gParticleEmitterManager, v14, 0);
    ++v14;
    ++activeBuffers;
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
  unsigned int v6; // r8d
  __int64 p_mUID; // rcx
  _DWORD *v8; // rax
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
        p_mUID = (__int64)&v3[1].mNULL.mParent[-1].mUID;
        if ( BYTE1(v5[4].mChild[0]) )
        {
          do
          {
            if ( v6 < BYTE1(v5[4].mChild[0]) )
              v8 = (_DWORD *)&v5[4].mChild[2] + 37 * v6;
            else
              v8 = 0i64;
            if ( *v8 == 1775129656 )
            {
              if ( (v9 = strength, strength <= 0.02) && *(float *)(p_mUID + 88) > 0.0
                || COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)(p_mUID + 88) - strength) & _xmm) > 0.02 )
              {
                if ( strength <= 0.02 )
                  v9 = 0.0;
                *(float *)(p_mUID + 88) = v9;
                *(_DWORD *)(p_mUID + 92) = UFG::Metrics::msFrameCount;
              }
            }
            v5 = v4[1].mRoot.mChild[0];
            ++v6;
            p_mUID = *(_QWORD *)(p_mUID + 16) - 8i64;
          }
          while ( (int)v6 < BYTE1(v5[4].mChild[0]) );
        }
      }
    }
  }
}

// File Line: 838
// RVA: 0x1D1850
void __fastcall Render::LoopEffect(Render::FXInstance *curFX, float simTime)
{
  __int64 v2; // rdx
  UFG::qResourceData *mData; // rbp
  unsigned int *p_mNameUID; // r14
  Render::FXInstance *p_mNext; // rbx
  __int64 mNext_low; // rcx
  __int64 p_mUID; // rsi
  __int64 v9; // rdi
  float v10; // xmm1_4

  mData = curFX->mSettings.mData;
  p_mNameUID = &curFX->mSettings.mNameUID;
  p_mNext = (Render::FXInstance *)&curFX->mComponents.mNode.mNext[-1].mNext;
  curFX->mStartTime = simTime;
  curFX->mEndTime = simTime + *(float *)&mData[1].mNode.mUID;
  if ( p_mNext != (Render::FXInstance *)&curFX->mSettings.mNameUID )
  {
    do
    {
      mNext_low = LODWORD(p_mNext->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext);
      p_mUID = (__int64)&p_mNext->mNode.mChild[1][-1].mUID;
      if ( (unsigned int)mNext_low < BYTE1(mData[1].mTypeUID) )
        v9 = (__int64)&mData[1].mDebugName[148 * mNext_low + 12];
      else
        v9 = 0i64;
      if ( BYTE4(p_mNext->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mNext) )
      {
        LOBYTE(v2) = (float)(*(float *)(v9 + 32) - *(float *)(v9 + 28)) == *(float *)&mData[1].mNode.mUID;
        (*(void (__fastcall **)(Render::FXInstance *, __int64))&p_mNext->mNode.mParent->mUID)(p_mNext, v2);
      }
      v10 = simTime + *(float *)(v9 + 32);
      *(float *)&p_mNext->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mPrev = simTime
                                                                                                 + *(float *)(v9 + 28);
      *((float *)&p_mNext->UFG::qNode<Render::FXInstance,Render::FXInstance_OcclusionList>::mPrev + 1) = v10;
      p_mNext = (Render::FXInstance *)p_mUID;
    }
    while ( (unsigned int *)p_mUID != p_mNameUID );
  }
}

// File Line: 871
// RVA: 0x1D94B0
void __fastcall Render::FXManager::Update(
        Render::FXManager *this,
        UFG::qMatrix44 *view_world,
        char main_view_cull_index,
        float simTime)
{
  UFG::TransformNodeComponent *m_pPointer; // rcx
  Render::FXInstance *v9; // rbx
  float mEndTime; // xmm3_4
  Render::FXManager *v11; // rdi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mPrev; // rcx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mNext; // rax
  int v14; // r8d

  Render::gFXForceManager.mNumForces = 0;
  Render::gGeoManager.mGeos.size = 0;
  m_pPointer = (UFG::TransformNodeComponent *)this->mCamTransformNode.m_pPointer;
  if ( m_pPointer )
    UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, view_world);
  Render::ScreenParticleEmitterManager::Update(&Render::gScreenParticleEmitterManager, simTime);
  v9 = (Render::FXInstance *)&this->mEffectsList.mNode.mNext[-3];
  if ( v9 != (Render::FXInstance *)&this->mEffectsTree.mTree.mRoot.mUID )
  {
    do
    {
      mEndTime = v9->mEndTime;
      v11 = (Render::FXManager *)&v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext[-3];
      if ( simTime < mEndTime )
      {
        if ( simTime >= v9->mStartTime )
          goto LABEL_9;
      }
      else
      {
        if ( v9->mLoop )
        {
          Render::LoopEffect(v9, simTime);
LABEL_9:
          Render::FXInstance::Update(v9, (UFG::qVector3 *)&view_world->v3, main_view_cull_index, simTime);
          goto LABEL_10;
        }
        Render::FXInstance::Update(v9, (UFG::qVector3 *)&view_world->v3, main_view_cull_index, mEndTime);
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)this,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)v9);
        mPrev = v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev;
        mNext = v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev = &v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
        v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext = &v9->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
        Render::FXInstance::~FXInstance(v9, (_DWORD)v9 + 48, v14);
        operator delete[](v9);
      }
LABEL_10:
      v9 = (Render::FXInstance *)v11;
    }
    while ( v11 != (Render::FXManager *)&this->mEffectsTree.mTree.mRoot.mUID );
  }
  this->mLastUpdateTime = simTime;
}

// File Line: 931
// RVA: 0x1D6010
void __fastcall Render::FXManager::ResumeAndSuspendBasedOnCullResults(
        Render::FXManager *this,
        UFG::qVector3 *cam_pos,
        float simTime)
{
  unsigned int *p_mUID; // r12
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v4; // rbx
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mPrev; // rbp
  __int64 v7; // r15
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *mNext; // rdi
  float *v9; // rdi
  float v10; // xmm2_4
  char v11; // si
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> **p_mNext; // r14
  bool v13; // di
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rbx
  char *v17; // rax
  unsigned __int8 v18; // dl

  p_mUID = &this->mEffectsTree.mTree.mRoot.mUID;
  v4 = this->mEffectsList.mNode.mNext - 3;
  if ( v4 != (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&this->mEffectsTree.mTree.mRoot.mUID )
  {
    do
    {
      mPrev = v4[5].mPrev;
      v7 = (__int64)&v4[3].mNext[-3];
      if ( mPrev )
      {
        mNext = v4[15].mNext;
        if ( !mNext || BYTE5(v4[8].mNext) )
        {
          v9 = (float *)&v4[16];
        }
        else
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4[15].mNext);
          v9 = (float *)&mNext[8];
        }
        v10 = (float)((float)((float)(cam_pos->x - v9[12]) * (float)(cam_pos->x - v9[12]))
                    + (float)((float)(cam_pos->y - v9[13]) * (float)(cam_pos->y - v9[13])))
            + (float)((float)(cam_pos->z - v9[14]) * (float)(cam_pos->z - v9[14]));
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
        p_mNext = &v4[5].mNext;
        v13 = v4[13].mNext->mPrev <= (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)1;
        v14 = (__int64)&v4[6].mNext[-1].mNext;
        if ( (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> **)v14 != &v4[5].mNext )
        {
          do
          {
            v15 = *(unsigned int *)(v14 + 40);
            v16 = *(_QWORD *)(v14 + 16) - 8i64;
            if ( (unsigned int)v15 < BYTE1(mPrev[8].mNext) )
              v17 = (char *)&mPrev[9].mNext + 148 * v15;
            else
              v17 = 0i64;
            v18 = v17[25];
            if ( ((v18 & 8) != 0 || (v18 & (unsigned __int8)v11) != 0) && *(_BYTE *)(v14 + 44) && !*(_DWORD *)(v14 + 48) )
            {
              if ( *(_BYTE *)(v14 + 45) )
              {
                if ( v13 || (v18 & 8) != 0 )
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 56i64))(v14);
              }
              else if ( !v13 && (v18 & 8) == 0 )
              {
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 48i64))(v14);
              }
            }
            v14 = v16;
          }
          while ( (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> **)v16 != p_mNext );
        }
      }
      v4 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)v7;
    }
    while ( (unsigned int *)v7 != p_mUID );
  }
}

// File Line: 989
// RVA: 0x1D3BF0
void __fastcall Render::FXManager::Render(
        Render::FXManager *this,
        Render::View *view,
        float simTime,
        Render::eFXDrawPass drawPass,
        Render::FXManagerAuxBuffers *auxBuffers)
{
  int v6; // r9d

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
          view,
          simTime,
          PARTICLEQUEUE_FORWARD_HIGH_QUALITY,
          auxBuffers);
        Render::FlareManager::Render(&Render::gFlareManager, view, simTime, FLAREQUEUE_FORWARD_HIGH_QUALITY, 0);
        Render::CoronaFlareManager::Render(&Render::gCoronaFlareManager, view, simTime);
        Render::BeamManager::Render(&Render::gBeamManager, view, simTime);
        Render::LightningManager::Render(&Render::gLightningManager, view, 0i64, 0x69DAE2D1u);
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
      Render::FlareManager::Render(&Render::gFlareManager, view, simTime, FLAREQUEUE_FORWARD_LOW_QUALITY, 0);
    }
  }
  else
  {
    Render::PolyStripManager::Render(&Render::gPolyStripManager, view, simTime);
    Render::GeoManager::Render(&Render::gGeoManager, view, FXDRAWPASS_DEFERRED, simTime);
    Render::ParticleEmitterManager::Render(
      &Render::gParticleEmitterManager,
      view,
      simTime,
      PARTICLEQUEUE_DEFERRED,
      auxBuffers);
  }
}

// File Line: 1056
// RVA: 0x1CA250
signed __int64 __fastcall Render::FXManager::CreateEffect(
        Render::FXManager *this,
        unsigned int fx_id,
        UFG::qVector3 *vPos,
        UFG::qVector3 *vDir)
{
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  __int128 v7; // xmm9
  __m128 v8; // xmm4
  __m128 y_low; // xmm5
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
  float v21; // xmm5_4
  __m128 v22; // xmm9
  float v23; // xmm4_4
  __m128 v24; // xmm6
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm5_4
  float v28; // xmm9_4
  float v29; // xmm4_4
  float v30; // xmm2_4
  UFG::qMatrix44 basis; // [rsp+40h] [rbp-A8h] BYREF

  x = vDir->x;
  y = vDir->y;
  z = vDir->z;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(y * 0.0) + (float)(vDir->x * 0.0)) + z) & _xmm) <= 0.99 )
  {
    v7 = 0i64;
    v8 = (__m128)(unsigned int)FLOAT_1_0;
  }
  else
  {
    v7 = (unsigned int)FLOAT_1_0;
    v8 = 0i64;
  }
  y_low = (__m128)LODWORD(vDir->y);
  y_low.m128_f32[0] = (float)((float)(y * y) + (float)(x * x)) + (float)(z * z);
  if ( y_low.m128_f32[0] == 0.0 )
    v10 = 0.0;
  else
    v10 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  v11 = x * v10;
  v12 = y * v10;
  v13 = z * v10;
  v14 = v8;
  basis.v2.x = v11;
  basis.v2.y = v12;
  basis.v2.z = v13;
  v14.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(*(float *)&v7 * *(float *)&v7);
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
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
    v20 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
  *(float *)&v16 = *(float *)&v16 * v20;
  v22 = (__m128)v16;
  basis.v0.y = v8.m128_f32[0] * v20;
  basis.v0.z = v18 * v20;
  LODWORD(basis.v0.x) = v16;
  v21 = (float)((float)(v18 * v20) * v12) - (float)((float)(v8.m128_f32[0] * v20) * v13);
  v22.m128_f32[0] = (float)(*(float *)&v16 * v13) - (float)((float)(v18 * v20) * v11);
  v23 = (float)((float)(v8.m128_f32[0] * v20) * v11) - (float)(*(float *)&v16 * v12);
  v24 = v22;
  v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  v26 = vPos->y;
  v27 = v21 * v25;
  v28 = v22.m128_f32[0] * v25;
  v29 = v23 * v25;
  v30 = vPos->z;
  basis.v3.x = vPos->x;
  basis.v1.x = v27;
  basis.v1.y = v28;
  basis.v0.w = 0.0;
  basis.v1.w = 0.0;
  basis.v2.w = 0.0;
  basis.v1.z = v29;
  basis.v3.y = v26;
  basis.v3.z = v30;
  basis.v3.w = 1.0;
  return Render::FXManager::CreateEffect(this, fx_id, &basis, 0i64);
}

// File Line: 1079
// RVA: 0x1CA220
signed __int64 __fastcall Render::FXManager::CreateEffect(
        Render::FXManager *this,
        unsigned int fx_id,
        UFG::qMatrix44 *basis,
        unsigned int splitScreenViewMask)
{
  return Render::FXManager::CreateEffect(this, fx_id, basis, 0i64);
}

// File Line: 1086
// RVA: 0x1CA510
signed __int64 __fastcall Render::FXManager::CreateEffect(
        Render::FXManager *this,
        unsigned int fx_id,
        UFG::TransformNodeComponent *parent,
        unsigned int splitScreenViewMask,
        Render::FXOverride *overrideObject)
{
  UFG::qMatrix44 *p_mWorldTransform; // r8

  if ( parent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(parent);
    p_mWorldTransform = &parent->mWorldTransform;
  }
  else
  {
    p_mWorldTransform = &UFG::qMatrix44::msIdentity;
  }
  return Render::FXManager::CreateEffect(this, fx_id, p_mWorldTransform, (Render::FXOverride *)parent);
}

// File Line: 1125
// RVA: 0x1C9D30
signed __int64 __fastcall Render::FXManager::CreateEffect(
        Render::FXManager *this,
        unsigned int fx_id,
        UFG::qMatrix44 *basis,
        Render::FXOverride *parent)
{
  UFG::TransformNodeComponent *m_pPointer; // rbx
  unsigned int size; // ecx
  unsigned int v8; // r10d
  unsigned int *p; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  Render::FXSettings *mData; // rdi
  unsigned int Effect; // ebx
  char v15; // cl
  unsigned int mNext; // edx
  float v17; // xmm5_4
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
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
  char *v38; // rdi
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  Render::FXComponentInstance *ComponentFromID; // rax
  float v43; // xmm1_4
  float v44; // xmm1_4
  float mEndTime; // xmm0_4
  float mStartTime; // xmm0_4
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v47; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rax
  UFG::qBaseTreeRB *v49; // rdi
  UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *v50; // rax
  UFG::qResourceInventory *v51; // rax
  UFG::qResourceWarehouse *v52; // rax
  int v53; // edx
  hkGeometryUtils::IVertices *v54; // rcx
  int v55; // r8d
  UFG::qResourceInventory *v56; // rax
  UFG::qResourceWarehouse *v57; // rax
  unsigned int mNameUID; // [rsp+28h] [rbp-61h]
  UFG::qMatrix44 basisa; // [rsp+38h] [rbp-51h] BYREF
  Render::FXSettings *v60; // [rsp+78h] [rbp-11h]
  UFG::qResourceHandle v61; // [rsp+80h] [rbp-9h] BYREF
  __int64 v62; // [rsp+A0h] [rbp+17h]
  UFG::qBaseTreeRB *v63; // [rsp+D8h] [rbp+4Fh]
  UFG::qMatrix44 *retaddr; // [rsp+E8h] [rbp+5Fh]
  UFG::TransformNodeComponent *parenta; // [rsp+F0h] [rbp+67h]
  float v66; // [rsp+F8h] [rbp+6Fh]
  unsigned int v67; // [rsp+100h] [rbp+77h]

  v67 = (unsigned int)basis;
  parenta = (UFG::TransformNodeComponent *)this;
  v62 = -2i64;
  m_pPointer = (UFG::TransformNodeComponent *)parent;
  size = this->mFilteredEffects.size;
  v8 = 0;
  if ( !size )
  {
LABEL_7:
    UFG::qResourceHandle::qResourceHandle(&v61);
    Inventory = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v61, 0xED341A8D, fx_id, Inventory);
    mData = (Render::FXSettings *)v61.mData;
    v60 = (Render::FXSettings *)v61.mData;
    if ( !v61.mData )
    {
      Effect = -1;
LABEL_50:
      v56 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v57 = UFG::qResourceWarehouse::Instance();
        v56 = UFG::qResourceWarehouse::GetInventory(v57, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v56;
      }
      UFG::qResourceHandle::Close(&v61, v56);
      UFG::qResourceHandle::~qResourceHandle(&v61);
      return Effect;
    }
    v15 = BYTE2(v61.mData[1].mTypeUID);
    if ( v15 )
    {
      if ( this->mCamTransformNode.m_pPointer )
        m_pPointer = (UFG::TransformNodeComponent *)this->mCamTransformNode.m_pPointer;
      parenta = m_pPointer;
    }
    if ( UFG::Metrics::msInstance.mSimTimeScaleInGame < 1.0 )
    {
      mNext = (unsigned int)v61.mData[1].mResourceHandles.mNode.mNext;
      if ( mNext != -1 )
      {
        Effect = Render::FXManager::CreateEffect(this, mNext, retaddr, parenta);
        goto LABEL_50;
      }
      m_pPointer = parenta;
    }
    if ( v15
      && this->mCamTransformNode.m_pPointer
      && (v17 = *((float *)&v61.mData[1].mResourceHandles.mNode.mNext + 1), v17 > 0.0000099999997) )
    {
      y = retaddr->v0.y;
      z = retaddr->v0.z;
      w = retaddr->v0.w;
      basisa.v0.x = retaddr->v0.x;
      basisa.v0.y = y;
      basisa.v0.z = z;
      basisa.v0.w = w;
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
        Render::FXInstance::FXInstance((Render::FXInstance *)v29, &basisa, m_pPointer, parent, 1);
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
        Render::FXInstance::FXInstance((Render::FXInstance *)v32, retaddr, m_pPointer, parent, 0);
        v31 = v33;
      }
      else
      {
        v31 = 0i64;
      }
    }
    mNameUID = v61.mNameUID;
    v34 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v35 = UFG::qResourceWarehouse::Instance();
      v34 = UFG::qResourceWarehouse::GetInventory(v35, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v34;
    }
    UFG::qResourceHandle::Init(&v31->mSettings, 0xED341A8D, mNameUID, v34);
    v31->mStartTime = 3.4028235e38;
    v31->mEndTime = -3.4028235e38;
    v31->mLoop = mData->mLoop;
    v31->mAudioId = mData->mAudioId;
    v31->mTransformNodeExtraTime = mData->mTransformNodeExtraTime;
    v31->mSplitScreenViewMask = v67;
    v36 = UFG::qRandom(0x7FFFFFFFu, (unsigned int *)&UFG::qDefaultSeed);
    this->mEffectId = v36;
    v31->mId = v36;
    v31->mNode.mUID = v36;
    v37 = 0;
    if ( !mData->mComponentCount )
    {
LABEL_44:
      v49 = v63;
      UFG::qBaseTreeRB::Add(v63, &v31->mNode);
      v50 = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)v49[1].mRoot.mChild[0];
      v49[1].mRoot.mChild[0] = (UFG::qBaseNodeRB *)&v31->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
      v31->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mPrev = (UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList> *)&v49[1];
      v31->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>::mNext = v50;
      v50->mPrev = &v31->UFG::qNode<Render::FXInstance,Render::FXInstance_UpdateList>;
      v51 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v52 = UFG::qResourceWarehouse::Instance();
        v51 = UFG::qResourceWarehouse::GetInventory(v52, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v51;
      }
      UFG::qResourceHandle::Close(&v61, v51);
      if ( v31->mAudioId && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v54, v53, v55) )
        UFG::AudioVFXManager::Add(v31, v31->mAudioId);
      Effect = v31->mId;
      goto LABEL_50;
    }
    while ( 1 )
    {
      v38 = (char *)&mData[1] + 0x94 * v37;
      v39 = *((float *)v38 + 0x24);
      v40 = *((float *)v38 + 0x23);
      v41 = *((float *)&v63[1].mNULL.mParent + 1);
      if ( v39 < v40 )
      {
        if ( v41 >= v40 || v41 <= v39 )
        {
LABEL_37:
          ComponentFromID = Render::FXManager::CreateComponentFromID(*(_DWORD *)v38, *((_DWORD *)v38 + 1));
          if ( ComponentFromID )
          {
            ComponentFromID->mContainer = v31;
            ComponentFromID->mComponentIndex = v37;
            v43 = *((float *)v38 + 8);
            ComponentFromID->mStartTime = *((float *)v38 + 7) + v66;
            v44 = v43 + v66;
            ComponentFromID->mEndTime = v44;
            mEndTime = v31->mEndTime;
            if ( mEndTime <= v44 )
              mEndTime = v44;
            v31->mEndTime = mEndTime;
            mStartTime = v31->mStartTime;
            if ( mStartTime >= ComponentFromID->mStartTime )
              mStartTime = ComponentFromID->mStartTime;
            v31->mStartTime = mStartTime;
            v47 = &ComponentFromID->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
            mPrev = v31->mComponents.mNode.mPrev;
            mPrev->mNext = v47;
            v47->mPrev = mPrev;
            v47->mNext = &v31->mComponents.mNode;
            v31->mComponents.mNode.mPrev = v47;
          }
        }
      }
      else if ( v40 <= v41 && v39 >= v41 )
      {
        goto LABEL_37;
      }
      ++v37;
      mData = v60;
      if ( v37 >= (unsigned __int8)v60->mComponentCount )
        goto LABEL_44;
    }
  }
  p = this->mFilteredEffects.p;
  while ( fx_id != *p )
  {
    ++v8;
    ++p;
    if ( v8 >= size )
      goto LABEL_7;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1233
// RVA: 0x1D0F70
signed __int64 __fastcall Render::FXManager::IsInBetweenTime(
        Render::FXManager *this,
        float time,
        float startTime,
        float endTime)
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
Render::FXComponentInstance *__fastcall Render::FXManager::CreateComponentFromID(
        unsigned int typeId,
        unsigned int nameId)
{
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
          goto LABEL_60;
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
      goto LABEL_60;
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
      goto LABEL_60;
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
      goto LABEL_60;
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
LABEL_60:
  (*((void (__fastcall **)(Render::FXComponentInstance *, _QWORD))&v5->vfptr->__vecDelDtor + 1))(v5, nameId);
  return v5;
}

// File Line: 1349
// RVA: 0x1CC280
void __fastcall Render::FXComponentInstance::GetBasis(Render::FXComponentInstance *this, UFG::qMatrix44 *dst)
{
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *p_mBasis; // rdx

  mContainer = this->mContainer;
  m_pPointer = mContainer->mParentNode.m_pPointer;
  if ( !m_pPointer || mContainer->mBasisRelativeToParent )
  {
    p_mBasis = &mContainer->mBasis;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
    p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
  }
  Render::FXInstance::CalcBasisHelper(
    dst,
    p_mBasis,
    &this->mContainer->mSettings,
    this->mComponentIndex,
    this->mStartTime);
}

// File Line: 1362
// RVA: 0x1C3580
void __fastcall Render::FXComponentInstance::~FXComponentInstance(Render::FXComponentInstance *this)
{
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v1; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v1 = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

