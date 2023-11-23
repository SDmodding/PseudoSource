// File Line: 37
// RVA: 0x1470090
__int64 dynamic_initializer_for__UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList__);
}

// File Line: 38
// RVA: 0x232690
UFG::ComponentIDDesc *__fastcall UFG::DynamicSceneryInstance::GetDesc(UFG::DynamicSceneryInstance *this)
{
  return &UFG::DynamicSceneryInstance::_TypeIDesc;
}

// File Line: 42
// RVA: 0x22F3D0
void __fastcall UFG::DynamicSceneryInstance::DynamicSceneryInstance(
        UFG::DynamicSceneryInstance *this,
        unsigned int instance_name_uid,
        unsigned int model_name_uid,
        unsigned int tag_uid)
{
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *mPrev; // rax
  signed int mFrameCount; // ecx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qVector4 v12; // xmm3
  CullManager *v13; // rax
  CullInfo *mCullInfo; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  CullInfo *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  UFG::SimComponent::SimComponent(&this->UFG::SimComponent, instance_name_uid);
  this->mPrev = &this->UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance>;
  this->mNext = &this->UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance>;
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::DynamicSceneryInstance::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicSceneryInstance::`vftable{for `UFG::SimComponent};
  UFG::qResourceHandle::qResourceHandle(&this->mModelHandle);
  mPrev = UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev;
  UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList;
  UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mPrev = &this->UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance>;
  UFG::SimComponent::AddType(
    &this->UFG::SimComponent,
    UFG::DynamicSceneryInstance::_DynamicSceneryInstanceTypeUID,
    "DynamicSceneryInstance");
  this->mNameUID = instance_name_uid;
  this->mTagUID = tag_uid;
  this->mHidden = 0;
  this->mSelfIlluminationOverride = 1.0;
  this->mForceTransparencyState = -1;
  mFrameCount = Illusion::gEngine.mFrameCount;
  if ( Render::TransparencySystem::msEnabled )
    this->mTransparencyState[0] = 0;
  else
    this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = mFrameCount + mFrameCount / 255;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mModelHandle, 0xA2ADCD77, model_name_uid, Inventory);
  v12 = 0i64;
  v12.x = (float)1;
  this->mLocalWorld.v0 = v12;
  this->mLocalWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 81);
  this->mLocalWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 69);
  this->mLocalWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 21);
  v13 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v13, &this->mCullResults, &this->mCullInfo, 0i64, 0i64, 0i64);
  this->mCullInfo->mpLocalWorld = &this->mLocalWorld.v0.x;
  mCullInfo = this->mCullInfo;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  mCullInfo->mAABBMin[0] = UFG::qVector3::msZero.x;
  mCullInfo->mAABBMin[1] = y;
  mCullInfo->mAABBMin[2] = z;
  v17 = this->mCullInfo;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  v17->mAABBMax[0] = UFG::qVector3::msZero.x;
  v17->mAABBMax[1] = v18;
  v17->mAABBMax[2] = v19;
}

// File Line: 71
// RVA: 0x22FA80
void __fastcall UFG::DynamicSceneryInstance::~DynamicSceneryInstance(UFG::DynamicSceneryInstance *this)
{
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v2; // rdi
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *mPrev; // rcx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *mNext; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  CullManager *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v10; // rdx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *v11; // rax

  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::DynamicSceneryInstance::`vftable{for `Render::IDecalScenery};
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DynamicSceneryInstance::`vftable{for `UFG::SimComponent};
  if ( this == UFG::DynamicSceneryInstance::s_DynamicSceneryInstancepCurrentIterator )
    UFG::DynamicSceneryInstance::s_DynamicSceneryInstancepCurrentIterator = (UFG::DynamicSceneryInstance *)&this->mPrev[-6].mNext;
  v2 = &this->UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mModelHandle, Inventory);
  Render::IDecalScenery::RemoveAttachedDecals(this, 0xFFFFFFFF);
  v7 = CullManager::Instance();
  CullManager::FreePersistentCullInfo(v7, this->mCullResults, this->mCullInfo);
  v8 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(&this->mModelHandle, v8);
  UFG::qResourceHandle::~qResourceHandle(&this->mModelHandle);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(&this->UFG::SimComponent);
  Render::IDecalScenery::~IDecalScenery(this);
}

// File Line: 101
// RVA: 0x2318F0
void __fastcall UFG::DynamicSceneryInstance::ForceFadeOut(UFG::DynamicSceneryInstance *this)
{
  this->mForceTransparencyState = 0;
}

// File Line: 106
// RVA: 0x2330C0
_BOOL8 __fastcall UFG::DynamicSceneryInstance::HasFadedOut(UFG::DynamicSceneryInstance *this)
{
  return this->mTransparencyState[0] == 0;
}

// File Line: 111
// RVA: 0x231900
void __fastcall UFG::DynamicSceneryInstance::ForceVisible(UFG::DynamicSceneryInstance *this)
{
  signed int mFrameCount; // r8d

  mFrameCount = Illusion::gEngine.mFrameCount;
  this->mTransparencyState[0] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[1] = Render::TransparencySystem::msOpaqueIndex;
  this->mTransparencyState[2] = mFrameCount + mFrameCount / 255;
  this->mForceTransparencyState = Render::TransparencySystem::msOpaqueIndex;
}

// File Line: 117
// RVA: 0x230FE0
void __fastcall UFG::DynamicSceneryInstance::Draw(UFG::DynamicSceneryInstance *this, Render::View *view)
{
  CullResults *mCullResults; // rdx
  __int64 mCullIndex; // rcx
  unsigned __int64 v6; // r8
  BOOL v7; // ebp
  BOOL v8; // eax
  int *v9; // rcx
  CullResults *v10; // rax
  bool v11; // cf
  int v12; // r11d
  __int16 mForceTransparencyState; // ax
  int v14; // r10d
  int v15; // r9d
  int v16; // ebx
  int v17; // eax
  Render::ViewSettings *mSettings; // rdx
  float v19; // xmm0_4
  float v20; // xmm0_4
  Illusion::SubmitContext *mSubmitContext; // rax
  AMD_HD3D *v22; // rax
  void *v23; // rax
  void *v24; // rbx
  Illusion::StateValues *StateValues; // rax
  float distance_from_near_plane; // [rsp+90h] [rbp+18h] BYREF
  float v27; // [rsp+98h] [rbp+20h] BYREF
  float v28; // [rsp+9Ch] [rbp+24h]

  if ( !gDrawScenery || this->mHidden || !this->mModelHandle.mData )
    return;
  mCullResults = this->mCullResults;
  if ( !mCullResults || (mCullIndex = view->mSettings->mCullIndex, (_DWORD)mCullIndex == -1) )
  {
    v8 = Render::View::IsInView(view, &this->mModelHandle, &this->mLocalWorld, &distance_from_near_plane);
    v6 = 0i64;
    v7 = !v8;
  }
  else
  {
    v6 = 0i64;
    v7 = 0;
    if ( (int)mCullIndex >= 0 )
      LOBYTE(v7) = mCullResults->mViewResult[mCullIndex] > 1u;
  }
  v9 = 0i64;
  if ( view->mSettings->mCullIndex )
    goto LABEL_35;
  v10 = this->mCullResults;
  if ( v10 )
  {
    v11 = (float)(view->mSettings->mCullPixelDensityThreshold * 1.0700001) < v10->mPixelCoverage[0];
    v12 = Render::TransparencySystem::msOpaqueIndex;
    mForceTransparencyState = this->mForceTransparencyState;
    v14 = Render::TransparencySystem::msOpaqueIndex;
    if ( !v11 )
      v14 = 0;
    if ( mForceTransparencyState != -1 )
      v14 = mForceTransparencyState;
    v15 = (unsigned __int8)this->mTransparencyState[0];
    v16 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    v17 = (int)Render::TransparencySystem::msTransparencyFrameCounter % 255
        - ((unsigned __int8)this->mTransparencyState[2] + 1) % 255;
    if ( v17 < 0 )
      v17 = ((unsigned __int8)this->mTransparencyState[2] + 1) % 255
          - (int)Render::TransparencySystem::msTransparencyFrameCounter % 255;
    if ( v17 <= 0 )
    {
      if ( v15 >= v14 )
      {
        if ( v15 > v14 )
          --v15;
      }
      else
      {
        ++v15;
      }
    }
    else
    {
      v15 = v14;
    }
    this->mTransparencyState[1] = v14;
    this->mTransparencyState[2] = v16;
    if ( v15 > 0 )
      LODWORD(v6) = v15;
    if ( (int)v6 < v12 )
      LOBYTE(v12) = v6;
    this->mTransparencyState[0] = v12;
    if ( (_BYTE)v12 )
    {
      mSettings = view->mSettings;
      v6 = *(_QWORD *)this->mTransparencyState;
      if ( view->mSettings->mCullIndex >= 6 )
        v19 = 0.0;
      else
        v19 = this->mCullResults->mDistance[view->mSettings->mCullIndex];
      v27 = v19;
      if ( mSettings->mCullIndex >= 6 )
        v20 = *(float *)&FLOAT_1_0;
      else
        v20 = this->mCullResults->mPixelCoverage[mSettings->mCullIndex];
      v28 = v20;
      v9 = (int *)&v27;
LABEL_35:
      mSubmitContext = view->mSubmitContext;
      mSubmitContext[1].vfptr = (Illusion::SubmitContextVtbl *)v9;
      mSubmitContext[1].mStateValues.mSetValueMask.mFlags[0] = v6;
      if ( gDrawDynamicCullResults && !view->mSettings->mCullIndex )
      {
        v22 = (AMD_HD3D *)CullManager::Instance();
        _(v22);
      }
      if ( !v7 )
      {
        if ( !view->mSettings->mCullIndex )
        {
          v23 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
          *(UFG::qColour *)v23 = UFG::qColour::White;
          v24 = v23;
          *((UFG::qColour *)v23 + 1) = UFG::qColour::White;
          *((_DWORD *)v23 + 7) = LODWORD(this->mSelfIlluminationOverride);
          StateValues = Render::View::GetStateValues(view);
          StateValues->mSetValueMask.mFlags[0] |= 0x400000000ui64;
          StateValues->mParamValues[34] = v24;
        }
        SubmitRenderModel(view, (Illusion::Model *)this->mModelHandle.mData, &this->mLocalWorld);
      }
    }
  }
}

// File Line: 192
// RVA: 0x2313B0
void __fastcall UFG::DynamicSceneryInstance::DrawAll(Render::View *view)
{
  UFG::DynamicSceneryInstance *p_mNext; // rcx
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v3; // rbx

  p_mNext = (UFG::DynamicSceneryInstance *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
  {
    do
    {
      v3 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&p_mNext->mNext[-6].mNext;
      UFG::DynamicSceneryInstance::Draw(p_mNext, view);
      p_mNext = (UFG::DynamicSceneryInstance *)v3;
    }
    while ( v3 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                            - 88) );
  }
}

// File Line: 398
// RVA: 0x2357E0
void __fastcall UFG::DynamicSceneryInstance::UpdateCullInfo(UFG::DynamicSceneryInstance *this)
{
  UFG::qResourceData *mData; // r8
  CullInfo *mCullInfo; // rdx
  float v4; // xmm0_4
  float v5; // xmm1_4
  CullInfo *v6; // rcx
  float v7; // xmm0_4
  unsigned int mUID; // xmm1_4

  mData = this->mModelHandle.mData;
  if ( mData )
  {
    if ( !this->mHidden )
    {
      mCullInfo = this->mCullInfo;
      v4 = *((float *)&mData[1].mNode.mParent + 1);
      v5 = *(float *)mData[1].mNode.mChild;
      mCullInfo->mAABBMin[0] = *(float *)&mData[1].mNode.mParent;
      mCullInfo->mAABBMin[1] = v4;
      mCullInfo->mAABBMin[2] = v5;
      v6 = this->mCullInfo;
      v7 = *((float *)&mData[1].mNode.mChild[1] + 1);
      mUID = mData[1].mNode.mUID;
      v6->mAABBMax[0] = *(float *)&mData[1].mNode.mChild[1];
      v6->mAABBMax[1] = v7;
      LODWORD(v6->mAABBMax[2]) = mUID;
      this->mCullInfo->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
    }
  }
}

// File Line: 416
// RVA: 0x232DA0
char __fastcall UFG::DynamicSceneryInstance::GetTransform(
        UFG::DynamicSceneryInstance *this,
        Render::Decal *decal,
        UFG::qMatrix44 *mat)
{
  char result; // al
  CullResults *mCullResults; // rax
  UFG::qVector4 v5; // xmm3
  UFG::qVector4 v6; // xmm2
  UFG::qVector4 v7; // xmm1

  if ( this->mHidden )
    return 0;
  mCullResults = this->mCullResults;
  if ( mCullResults )
  {
    if ( mCullResults->mViewResult[0] > 1u )
      return 0;
  }
  v5 = this->mLocalWorld.v1;
  v6 = this->mLocalWorld.v2;
  result = 1;
  v7 = this->mLocalWorld.v3;
  mat->v0 = this->mLocalWorld.v0;
  mat->v1 = v5;
  mat->v2 = v6;
  mat->v3 = v7;
  return result;
}

// File Line: 427
// RVA: 0x2351A0
void __fastcall UFG::TestDynamicSceneryForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *p_mNext; // rbx
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *mNext; // r14
  UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *v6; // rsi
  UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *mPrev; // rax
  UFG::qMatrix44 *v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qMatrix44 *v13; // rax
  UFG::qVector4 v14; // xmm2
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm0
  UFG::qResourceInventory *Inventory; // rax
  unsigned int v18; // r12d
  UFG::qResourceWarehouse *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qVector3 min; // [rsp+20h] [rbp-88h] BYREF
  UFG::qVector3 max; // [rsp+30h] [rbp-78h] BYREF
  UFG::qMatrix44 m; // [rsp+40h] [rbp-68h] BYREF

  p_mNext = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext;
  if ( &UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> **)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList - 88) )
  {
    do
    {
      mNext = p_mNext[9].mNode.mNext;
      v6 = (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)&p_mNext[6].mNode.mPrev[-6].mNext;
      if ( mNext && !LOWORD(p_mNext[6].mNode.mNext) )
      {
        mPrev = p_mNext[7].mNode.mPrev;
        v8 = &UFG::qMatrix44::msIdentity;
        v9 = *((float *)&mPrev->mPrev + 1);
        v10 = *(float *)&mPrev->mNext;
        min.x = *(float *)&mPrev->mPrev;
        min.y = v9;
        min.z = v10;
        v11 = *((float *)&mPrev[1].mPrev + 1);
        v12 = *(float *)&mPrev[1].mNext;
        max.x = *(float *)&mPrev[1].mPrev;
        max.y = v11;
        max.z = v12;
        v13 = (UFG::qMatrix44 *)mPrev[3].mNext;
        if ( v13 )
          v8 = v13;
        v14 = v8->v2;
        v15 = v8->v3;
        v16 = v8->v0;
        m.v1 = v8->v1;
        m.v2 = v14;
        m.v0 = v16;
        m.v3 = v15;
        TransformAABB(&m, &min, &max);
        if ( min.x <= projBox->mMax.x
          && max.x >= projBox->mMin.x
          && min.y <= projBox->mMax.y
          && max.y >= projBox->mMin.y
          && min.z <= projBox->mMax.z
          && max.z >= projBox->mMin.z )
        {
          Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          v18 = (unsigned int)mNext[1].mNext;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v19 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v19, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
          }
          UFG::qResourceHandle::Init(&request->mModelProxy.mModelHandle, 0xA2ADCD77, v18, Inventory);
          request->mModelProxy.mRModel = 0i64;
          p_mComponentPtr = &request->mComponentPtr;
          request->mLocalToWorld.v0 = (UFG::qVector4)p_mNext[11];
          request->mLocalToWorld.v1 = (UFG::qVector4)p_mNext[12];
          request->mLocalToWorld.v2 = (UFG::qVector4)p_mNext[13];
          request->mLocalToWorld.v3 = (UFG::qVector4)p_mNext[14];
          if ( request->mComponentPtr.m_pPointer )
          {
            v21 = p_mComponentPtr->mPrev;
            v22 = request->mComponentPtr.mNext;
            v21->mNext = v22;
            v22->mPrev = v21;
            p_mComponentPtr->mPrev = p_mComponentPtr;
            request->mComponentPtr.mNext = &request->mComponentPtr;
          }
          request->mComponentPtr.m_pPointer = (UFG::SimComponent *)&p_mNext[1].mNode.mNext;
          if ( p_mNext != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)-24i64 )
          {
            v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)p_mNext[2].mNode.mPrev;
            v23->mNext = p_mComponentPtr;
            p_mComponentPtr->mPrev = v23;
            request->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&p_mNext[2];
            p_mNext[2].mNode.mPrev = (UFG::qNode<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance> *)p_mComponentPtr;
          }
          request->mScenery = (Render::IDecalScenery *)p_mNext;
          Render::DecalManager::AddClipQueue(&Render::gDecalManager, request);
        }
      }
      p_mNext = v6;
    }
    while ( v6 != (UFG::qList<UFG::DynamicSceneryInstance,UFG::DynamicSceneryInstance,1,0> *)((char *)&UFG::DynamicSceneryInstance::s_DynamicSceneryInstanceList
                                                                                            - 88) );
  }
}

