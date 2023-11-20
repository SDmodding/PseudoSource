// File Line: 54
// RVA: 0x1452540
__int64 dynamic_initializer_for__gDebugMultiMorphName__()
{
  UFG::qString::qString(&gDebugMultiMorphName);
  return atexit(dynamic_atexit_destructor_for__gDebugMultiMorphName__);
}

// File Line: 69
// RVA: 0x4190
void UFG::CompositeDrawableComponent::SystemInit(void)
{
  UFG::CompositeDrawableComponent::msDebugRender.mSkeletonRenderSkin = 1;
  UFG::CompositeDrawableComponent::msDebugRender.mSkeletonDebugFinalPose = 1;
  UFG::CompositeDrawableComponent::msDebugRender.mFinalTransformDrawScale = FLOAT_0_5;
  UFG::CompositeDrawableComponent::msDebugRender.mDebugMotion = 0;
}

// File Line: 102
// RVA: 0x14524E0
__int64 dynamic_initializer_for__UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList__);
}

// File Line: 103
// RVA: 0x3BE0
signed __int64 __fastcall UFG::CompositeDrawableComponent::GetTypeSize(UFG::CompositeDrawableComponent *this)
{
  return 1504i64;
}

// File Line: 117
// RVA: 0x2270
void __fastcall UFG::CompositeDrawableComponent::CompositeDrawableComponent(UFG::CompositeDrawableComponent *this)
{
  UFG::CompositeDrawableComponent *v1; // rsi
  Render::IDecalScenery *v2; // rdx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v3; // rdi
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v4; // rax
  UFG::qList<Render::Decal,Render::Decal,0,0> *v5; // [rsp+60h] [rbp+18h]

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v2 = (Render::IDecalScenery *)&v1->vfptr;
  v2->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable';
  v5 = &v1->mAttachedDecals;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v3 = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  v1->mCompositeLook = 0i64;
  Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(&v1->mMaterialModifier);
  v1->mIsHidden = 0;
  v1->mCullLayer = 0i64;
  v1->mCullResults = 0i64;
  v1->mCullInfo = 0i64;
  v1->mPose = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mRigHandle.mPrev);
  v1->mRigHandle.mLoadFunction = 0i64;
  v1->mRigHandle.mUnloadFunction = 0i64;
  v1->mRigHandle.mUserData = 0i64;
  v1->mRigHandle.mUFGSkeleton = 0i64;
  v1->mLODBiasMult = 1.0;
  v1->mDrawScale = 1.0;
  v1->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&v1->mActiveMultiMorphTargets.size = 0i64;
  v4 = UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v1->mPrev;
  v3->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v1->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID,
    "CompositeDrawableComponent");
  UFG::CompositeDrawableComponent::Reset(v1);
  UFG::qMemSet(v1->mModelType, 0, 0x28u);
  if ( UFG::CompositeDrawableComponent::mDefaultCullLayer )
    UFG::CompositeDrawableComponent::SetLayer(v1, UFG::CompositeDrawableComponent::mDefaultCullLayer);
}

// File Line: 141
// RVA: 0x2080
void __fastcall UFG::CompositeDrawableComponent::CompositeDrawableComponent(UFG::CompositeDrawableComponent *this, UFG::RigResource *rig)
{
  UFG::RigResource *v2; // r14
  UFG::CompositeDrawableComponent *v3; // rsi
  Render::IDecalScenery *v4; // r8
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v5; // rbx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v6; // rax
  ModelType *v7; // rax
  unsigned int v8; // edi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  ModelType *v11; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v12; // rax
  signed __int64 v13; // rcx
  UFG::qList<Render::Decal,Render::Decal,0,0> *v14; // [rsp+80h] [rbp+18h]

  v2 = rig;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v4 = (Render::IDecalScenery *)&v3->vfptr;
  v4->vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable';
  v14 = &v3->mAttachedDecals;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v5 = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v3->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `UFG::SimComponent'};
  v4->vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  v3->mCompositeLook = 0i64;
  Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(&v3->mMaterialModifier);
  v3->mIsHidden = 0;
  v3->mCullLayer = 0i64;
  v3->mCullResults = 0i64;
  v3->mCullInfo = 0i64;
  v3->mPose = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRigHandle.mPrev);
  v3->mRigHandle.mLoadFunction = 0i64;
  v3->mRigHandle.mUnloadFunction = 0i64;
  v3->mRigHandle.mUserData = 0i64;
  v3->mRigHandle.mUFGSkeleton = 0i64;
  v3->mLODBiasMult = 1.0;
  v3->mDrawScale = 1.0;
  v3->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&v3->mActiveMultiMorphTargets.size = 0i64;
  v6 = UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v3->mPrev;
  v5->mPrev = v6;
  v3->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID,
    "CompositeDrawableComponent");
  UFG::CompositeDrawableComponent::Reset(v3);
  UFG::qMemSet(v3->mModelType, 0, 0x28u);
  v7 = UFG::CompositeDrawableComponent::CreateModelType(v3, 1);
  v3->mModelType[0] = v7;
  v3->mNumModelTypeLODs = v7 != 0i64;
  v8 = v2->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = inventory;
  }
  UFG::qResourceHandle::Init(
    (UFG::qResourceHandle *)&v3->mRigHandle.mPrev,
    0x39BC0A7Eu,
    v8,
    (UFG::qResourceData *)&v2->mNode,
    inventory);
  if ( UFG::CompositeDrawableComponent::mDefaultCullLayer )
    UFG::CompositeDrawableComponent::SetLayer(v3, UFG::CompositeDrawableComponent::mDefaultCullLayer);
  v3->mHasSoftBody = 0;
  v11 = v3->mModelType[0];
  if ( v11 )
  {
    v12 = v11->mModelBindingSkinTable.mNode.mNext;
    v13 = (signed __int64)&v11->mModelBindingSkinTable;
    if ( v12 != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v13 )
    {
      while ( !v12[6].mPrev )
      {
        v12 = v12->mNext;
        if ( v12 == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v13 )
          return;
      }
      v3->mHasSoftBody = 1;
    }
  }
}

// File Line: 160
// RVA: 0x25D0
void __fastcall UFG::CompositeDrawableComponent::~CompositeDrawableComponent(UFG::CompositeDrawableComponent *this)
{
  UFG::CompositeDrawableComponent *v1; // rbx
  Render::IDecalScenery *v2; // r15
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v3; // r14
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v4; // rcx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v5; // rax
  __int64 v6; // rdi
  ModelType *v7; // rsi
  ActiveMultiMorphTarget *v8; // rcx
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v11; // rcx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v12; // rax
  UFG::qList<Render::Decal,Render::Decal,0,0> *v13; // r8
  UFG::qList<Render::Decal,Render::Decal,0,0> *v14; // rax
  UFG::qNode<Render::Decal,Render::Decal> *v15; // rdx
  UFG::qNode<Render::Decal,Render::Decal> *v16; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v17; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `UFG::SimComponent'};
  v2 = (Render::IDecalScenery *)&this->vfptr;
  this->vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable'{for `Render::IDecalScenery'};
  if ( this == UFG::CompositeDrawableComponent::s_CompositeDrawableComponentpCurrentIterator )
    UFG::CompositeDrawableComponent::s_CompositeDrawableComponentpCurrentIterator = (UFG::CompositeDrawableComponent *)&this->mPrev[-6].mNext;
  v3 = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&this->mPrev;
  v4 = this->mPrev;
  v5 = v3->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  Render::IDecalScenery::RemoveAttachedDecals(v2, 0xFFFFFFFF);
  v6 = 0i64;
  if ( v1->mNumModelTypeLODs )
  {
    do
    {
      v7 = v1->mModelType[v6];
      if ( v7 )
      {
        ModelType::~ModelType(v1->mModelType[v6]);
        operator delete[](v7);
      }
      v6 = (unsigned int)(v6 + 1);
    }
    while ( (unsigned int)v6 < v1->mNumModelTypeLODs );
  }
  v8 = v1->mActiveMultiMorphTargets.p;
  if ( v8 )
    operator delete[](v8);
  v1->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&v1->mActiveMultiMorphTargets.size = 0i64;
  v9 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v9;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mRigHandle.mPrev, v9);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mRigHandle.mPrev);
  `eh vector destructor iterator'(
    v1->mMaterialModifier.mOverrides,
    0x68ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ParamOverride::~ParamOverride);
  v11 = v3->mPrev;
  v12 = v3->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v3->mPrev = v3;
  v3->mNext = v3;
  v13 = &v2->mAttachedDecals;
  v14 = (UFG::qList<Render::Decal,Render::Decal,0,0> *)v2->mAttachedDecals.mNode.mNext;
  if ( v14 != &v2->mAttachedDecals )
  {
    do
    {
      v15 = v14->mNode.mPrev;
      v16 = v14->mNode.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mNode.mPrev = &v14->mNode;
      v14->mNode.mNext = &v14->mNode;
      v14 = (UFG::qList<Render::Decal,Render::Decal,0,0> *)v2->mAttachedDecals.mNode.mNext;
    }
    while ( v14 != v13 );
  }
  v17 = v13->mNode.mPrev;
  v18 = v2->mAttachedDecals.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mNode.mPrev = &v13->mNode;
  v2->mAttachedDecals.mNode.mNext = &v2->mAttachedDecals.mNode;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 172
// RVA: 0x4000
void __fastcall UFG::CompositeDrawableComponent::SetIsHidden(UFG::CompositeDrawableComponent *this, const bool bIsHidden)
{
  UFG::ICompositeLook *v2; // r9

  v2 = this->mCompositeLook;
  this->mIsHidden = bIsHidden;
  if ( v2 )
    v2->vfptr->OnSetHidden(v2, this, bIsHidden);
}

// File Line: 181
// RVA: 0x2C40
void __fastcall UFG::CompositeDrawableComponent::ClearLODs(UFG::CompositeDrawableComponent *this)
{
  unsigned int v1; // ebx
  UFG::CompositeDrawableComponent *v2; // rdi
  signed __int64 v3; // r14
  void *v4; // rsi

  v1 = 1;
  v2 = this;
  if ( this->mNumModelTypeLODs <= 1 )
  {
    this->mNumModelTypeLODs = 1;
  }
  else
  {
    do
    {
      v3 = (signed __int64)v2 + 8 * v1;
      v4 = *(void **)(v3 + 1424);
      if ( v4 )
      {
        ModelType::~ModelType(*(ModelType **)(v3 + 1424));
        operator delete[](v4);
      }
      ++v1;
      *(_QWORD *)(v3 + 1424) = 0i64;
    }
    while ( v1 < v2->mNumModelTypeLODs );
    v2->mNumModelTypeLODs = 1;
  }
}

// File Line: 191
// RVA: 0x3DC0
void __fastcall UFG::CompositeDrawableComponent::Reset(UFG::CompositeDrawableComponent *this)
{
  UFG::CompositeDrawableComponent *v1; // rbx
  ActiveMultiMorphTarget *v2; // rcx
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  UFG::ICompositeLook *v15; // rcx

  v1 = this;
  this->mIsHidden = 0;
  v2 = this->mActiveMultiMorphTargets.p;
  if ( v2 )
    operator delete[](v2);
  v1->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&v1->mActiveMultiMorphTargets.size = 0i64;
  v1->mDrawScale = 1.0;
  v3 = UFG::qVector4::msOne.z;
  v4 = UFG::qVector4::msOne.w;
  v5 = UFG::qVector4::msOne.x;
  v1->mSceneryInstance.SIColourTint[1] = UFG::qVector4::msOne.y;
  v1->mSceneryInstance.SIColourTint[2] = v3;
  v1->mSceneryInstance.SIColourTint[0] = v5;
  v1->mSceneryInstance.SIColourTint[3] = v4;
  v6 = UFG::qVector4::msOne.y;
  v7 = UFG::qVector4::msOne.z;
  v8 = UFG::qVector4::msOne.w;
  v1->mSceneryInstance.Value0[0] = UFG::qVector4::msOne.x;
  v1->mSceneryInstance.Value0[1] = v6;
  v1->mSceneryInstance.Value0[2] = v7;
  v1->mSceneryInstance.Value0[3] = v8;
  v9 = UFG::qVector4::msOne.z;
  v10 = UFG::qVector4::msOne.w;
  v11 = UFG::qVector4::msOne.x;
  v1->mSceneryInstance.ColourTint[1] = UFG::qVector4::msOne.y;
  v1->mSceneryInstance.ColourTint[0] = v11;
  v1->mSceneryInstance.ColourTint[2] = v9;
  v1->mSceneryInstance.ColourTint[3] = v10;
  v12 = UFG::qVector4::msOne.z;
  v13 = UFG::qVector4::msOne.w;
  v14 = UFG::qVector4::msOne.x;
  v1->mSceneryInstance.Mask[1] = UFG::qVector4::msOne.y;
  v1->mSceneryInstance.Mask[2] = v12;
  v1->mSceneryInstance.Mask[0] = v14;
  v1->mSceneryInstance.Mask[3] = v13;
  Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v1->vfptr, 0xFFFFFFFF);
  v15 = v1->mCompositeLook;
  if ( v15 )
    v15->vfptr->OnReset(v15, v1);
}

// File Line: 235
// RVA: 0x3F30
void __fastcall UFG::CompositeDrawableComponent::ResetModelType(UFG::CompositeDrawableComponent *this)
{
  UFG::CompositeDrawableComponent *v1; // rbx
  ModelType *v2; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v3; // rcx
  signed __int64 v4; // rax

  v1 = this;
  UFG::CompositeDrawableComponent::ClearLODs(this);
  v2 = UFG::CompositeDrawableComponent::CreateModelType(v1, 1);
  v1->mHasSoftBody = 0;
  v1->mModelType[0] = v2;
  if ( v2 )
  {
    v3 = v2->mModelBindingSkinTable.mNode.mNext;
    v4 = (signed __int64)&v2->mModelBindingSkinTable;
    if ( v3 != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v4 )
    {
      while ( !v3[6].mPrev )
      {
        v3 = v3->mNext;
        if ( v3 == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v4 )
          return;
      }
      v1->mHasSoftBody = 1;
    }
  }
}

// File Line: 245
// RVA: 0x3CE0
void __fastcall UFG::CompositeDrawableComponent::OnAttach(UFG::CompositeDrawableComponent *this, UFG::SimObject *object)
{
  UFG::CompositeDrawableComponent *v2; // rbx
  ModelType *v3; // rdx
  ModelType *v4; // rax

  v2 = this;
  if ( !this->mModelType[0] )
    this->mModelType[0] = UFG::CompositeDrawableComponent::CreateModelType(this, 1);
  v3 = v2->mModelType[0];
  v2->mHasSoftBody = 0;
  if ( v3 )
  {
    v4 = (ModelType *)v3->mModelBindingSkinTable.mNode.mNext;
    if ( v4 != (ModelType *)&v3->mModelBindingSkinTable )
    {
      while ( !v4->mModelBindingRigidTable.mNode.mPrev )
      {
        v4 = (ModelType *)v4->mNext;
        if ( v4 == (ModelType *)&v3->mModelBindingSkinTable )
          goto LABEL_9;
      }
      v2->mHasSoftBody = 1;
    }
  }
LABEL_9:
  v2->mNumModelTypeLODs = v3 != 0i64;
}

// File Line: 253
// RVA: 0x3D60
void __fastcall UFG::CompositeDrawableComponent::OnDetach(UFG::CompositeDrawableComponent *this)
{
  CullResults *v1; // rdi
  UFG::CompositeDrawableComponent *v2; // rbx
  CullManager *v3; // rax

  v1 = this->mCullResults;
  v2 = this;
  this->mPose = 0i64;
  if ( v1 )
  {
    v3 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v3, v1, v2->mCullInfo);
    v2->mCullInfo = 0i64;
    v2->mCullResults = 0i64;
  }
}

// File Line: 259
// RVA: 0x4830
void __fastcall UFG::CompositeDrawableComponent::UpdateHasSoftBody(UFG::CompositeDrawableComponent *this)
{
  ModelType *v1; // rdx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v2; // rax
  signed __int64 v3; // rdx

  this->mHasSoftBody = 0;
  v1 = this->mModelType[0];
  if ( v1 )
  {
    v2 = v1->mModelBindingSkinTable.mNode.mNext;
    v3 = (signed __int64)&v1->mModelBindingSkinTable;
    if ( v2 != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v3 )
    {
      while ( !v2[6].mPrev )
      {
        v2 = v2->mNext;
        if ( v2 == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)v3 )
          return;
      }
      this->mHasSoftBody = 1;
    }
  }
}

// File Line: 276
// RVA: 0x41C0
void __fastcall UFG::CompositeDrawableComponent::TeleportEventHandler(UFG::CompositeDrawableComponent *this, UFG::Event *event)
{
  ModelType *v2; // rdi
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v3; // rbx
  signed __int64 i; // rdi
  Render::Softbody *v5; // rcx

  if ( this->mHasSoftBody )
  {
    v2 = this->mModelType[0];
    if ( v2 )
    {
      v3 = v2->mModelBindingSkinTable.mNode.mNext;
      for ( i = (signed __int64)&v2->mModelBindingSkinTable;
            v3 != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)i;
            v3 = v3->mNext )
      {
        v5 = (Render::Softbody *)v3[6].mPrev;
        if ( v5 )
          Render::Softbody::ForceReset(v5);
      }
    }
  }
}

// File Line: 313
// RVA: 0x4870
void UFG::CompositeDrawableComponent::UpdateTransformsAll(void)
{
  UFG::CompositeDrawableComponent *v0; // rbx
  UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *v1; // rsi
  ModelType *v2; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v3; // rbx
  signed __int64 i; // rdi
  Render::Softbody *v5; // rcx

  v0 = (UFG::CompositeDrawableComponent *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
  {
    do
    {
      v1 = (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)&v0->mNext[-6].mNext;
      if ( (v0->m_Flags & 3) == 1 )
      {
        UFG::CompositeDrawableComponent::UpdateCullInfo(v0);
        if ( v0->mHasSoftBody )
        {
          v2 = v0->mModelType[0];
          v3 = v2->mModelBindingSkinTable.mNode.mNext;
          for ( i = (signed __int64)&v2->mModelBindingSkinTable;
                v3 != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)i;
                v3 = v3->mNext )
          {
            v5 = (Render::Softbody *)v3[6].mPrev;
            if ( v5 )
              Render::Softbody::UpdateTransform(v5);
          }
        }
      }
      v0 = (UFG::CompositeDrawableComponent *)v1;
    }
    while ( v1 != (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) );
  }
}

// File Line: 324
// RVA: 0x4030
void __fastcall UFG::CompositeDrawableComponent::SetLayer(UFG::CompositeDrawableComponent *this, CullLayer *cull_layer)
{
  CullInfo *v2; // rbx
  CullLayer *v3; // r14
  UFG::CompositeDrawableComponent *cull_info_param0; // rdi
  CullResults *v5; // rbp
  CullManager *v6; // rax
  CullManager *v7; // rax
  __m128 v8; // xmm2
  signed __int64 v9; // rcx

  v2 = this->mCullInfo;
  v3 = cull_layer;
  cull_info_param0 = this;
  if ( v2 )
  {
    if ( v2->mCullLayer == cull_layer )
      return;
    v5 = this->mCullResults;
    if ( v5 )
    {
      v6 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v6, v5, v2);
      cull_info_param0->mCullInfo = 0i64;
      cull_info_param0->mCullResults = 0i64;
    }
  }
  cull_info_param0->mCullLayer = v3;
  v7 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(
    v7,
    &cull_info_param0->mCullResults,
    &cull_info_param0->mCullInfo,
    v3,
    cull_info_param0,
    cull_info_param0);
  v8 = 0i64;
  v9 = (signed __int64)&cull_info_param0->mPoseRootMatrix;
  v8.m128_f32[0] = (float)1;
  *(__m128 *)v9 = v8;
  *(__m128 *)(v9 + 16) = _mm_shuffle_ps(v8, v8, 81);
  *(__m128 *)(v9 + 32) = _mm_shuffle_ps(v8, v8, 69);
  *(__m128 *)(v9 + 48) = _mm_shuffle_ps(v8, v8, 21);
  cull_info_param0->mCullInfo->mpLocalWorld = &cull_info_param0->mPoseRootMatrix.v0.x;
}

// File Line: 349
// RVA: 0x45A0
void __fastcall UFG::CompositeDrawableComponent::UpdateCullInfo(UFG::CompositeDrawableComponent *this)
{
  UFG::CompositeDrawableComponent *v1; // rsi
  SkeletalPose *v2; // rax
  ModelType *v3; // rbx
  float v4; // eax
  float *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  SkeletalPose *v9; // rdx
  hkaPose *v10; // rcx
  hkQsTransformf *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  CullResults *v23; // rbx
  CullManager *v24; // rax

  v1 = this;
  if ( (this->m_Flags & 3) == 1 && !this->mIsHidden && (v2 = this->mPose) != 0i64 && v2->mRigHandle.mData )
  {
    if ( !this->mCullInfo )
      UFG::CompositeDrawableComponent::SetLayer(this, this->mCullLayer);
    v3 = v1->mModelType[0];
    v1->mCullInfo->mViewsCulled = 0;
    ModelType::UpdateAABB(v3, v1->mPose);
    v1->mCullInfo->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
    v4 = v3->mAABBMin.x;
    v5 = v1->mCullInfo->mAABBMin;
    v6 = v3->mAABBMin.z;
    v5[1] = v3->mAABBMin.y;
    v5[2] = v6;
    *v5 = v4;
    v7 = v3->mAABBMax.y;
    v8 = v3->mAABBMax.z;
    v5[4] = v3->mAABBMax.x;
    v5[5] = v7;
    v5[6] = v8;
    SkeletalPose::GetRootMatrix(v1->mPose, &v1->mPoseRootMatrix);
    v9 = v1->mPose;
    if ( v9->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size > 1 )
    {
      v10 = v9->mHavokPose;
      if ( v10->m_boneFlags.m_data[1] & 2 )
        v11 = hkaPose::calculateBoneModelSpace(v10, 1);
      else
        v11 = v10->m_modelPose.m_data + 1;
      v12 = *v5;
      if ( *v5 >= v11->m_translation.m_quad.m128_f32[0] )
        v12 = v11->m_translation.m_quad.m128_f32[0];
      *v5 = v12;
      v13 = v5[1];
      if ( v13 >= v11->m_translation.m_quad.m128_f32[1] )
        v13 = v11->m_translation.m_quad.m128_f32[1];
      v5[1] = v13;
      v14 = v5[2];
      if ( v14 >= v11->m_translation.m_quad.m128_f32[2] )
        v14 = v11->m_translation.m_quad.m128_f32[2];
      v5[2] = v14;
      v15 = v5[4];
      if ( v15 <= v11->m_translation.m_quad.m128_f32[0] )
        v15 = v11->m_translation.m_quad.m128_f32[0];
      v5[4] = v15;
      v16 = v5[5];
      if ( v16 <= v11->m_translation.m_quad.m128_f32[1] )
        v16 = v11->m_translation.m_quad.m128_f32[1];
      v5[5] = v16;
      v17 = v5[6];
      if ( v17 <= v11->m_translation.m_quad.m128_f32[2] )
        v17 = v11->m_translation.m_quad.m128_f32[2];
      v5[6] = v17;
    }
    v18 = (float)(v1->mPose->mRigHandle.mUFGSkeleton->mBoneScale * v1->mDrawScale) * *v5;
    v19 = (float)(v1->mPose->mRigHandle.mUFGSkeleton->mBoneScale * v1->mDrawScale) * v5[1];
    v5[2] = (float)(v1->mPose->mRigHandle.mUFGSkeleton->mBoneScale * v1->mDrawScale) * v5[2];
    *v5 = v18;
    v5[1] = v19;
    v20 = v1->mPose->mRigHandle.mUFGSkeleton->mBoneScale * v1->mDrawScale;
    v21 = v20 * v5[4];
    v22 = v20 * v5[5];
    v5[6] = v20 * v5[6];
    v5[4] = v21;
    v5[5] = v22;
  }
  else
  {
    v23 = this->mCullResults;
    if ( v23 )
    {
      v24 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v24, v23, v1->mCullInfo);
      v1->mCullInfo = 0i64;
      v1->mCullResults = 0i64;
    }
  }
}

// File Line: 406
// RVA: 0x3A50
__int64 __fastcall UFG::CompositeDrawableComponent::GetLOD(UFG::CompositeDrawableComponent *this, float pixel_coverage)
{
  __int64 v2; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v3; // rax

  LODWORD(v2) = 0;
  if ( pixel_coverage < (float)(this->mLODBiasMult * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[0]) )
  {
    do
    {
      if ( (unsigned int)v2 >= 5 )
        break;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( pixel_coverage < (float)(this->mLODBiasMult * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[v2]) );
  }
  if ( (unsigned int)v2 >= this->mNumModelTypeLODs - 1 )
    LODWORD(v2) = this->mNumModelTypeLODs - 1;
  if ( (_DWORD)v2 )
  {
    v3 = &(&this->vfptr)[(unsigned int)v2 + 178i64];
    do
    {
      if ( *v3 )
        break;
      --v3;
      LODWORD(v2) = v2 - 1;
    }
    while ( (_DWORD)v2 );
  }
  return (unsigned int)v2;
}

// File Line: 427
// RVA: 0x3AC0
__int64 __fastcall UFG::CompositeDrawableComponent::GetMainViewLOD(UFG::CompositeDrawableComponent *this)
{
  __int64 result; // rax

  result = (__int64)this->mCullResults->mViewResult;
  if ( result )
    result = UFG::CompositeDrawableComponent::GetLOD(this, *(float *)(result + 40));
  return result;
}

// File Line: 443
// RVA: 0x3F90
void __fastcall UFG::CompositeDrawableComponent::ScalePixelCoverageToLOD(float scale)
{
  UFG::CompositeDrawableComponent::msPixelCoverageToLOD[0] = UFG::CompositeDrawableComponent::msDefaultPixelCoverageToLOD[0]
                                                           * scale;
  *(float *)&dword_14202132C = *(float *)&dword_142021314 * scale;
  *(float *)&dword_142021330 = *(float *)&dword_142021318 * scale;
  *(float *)&dword_142021338 = *(float *)&dword_142021320 * scale;
  *(float *)&dword_142021334 = *(float *)&dword_14202131C * scale;
}

// File Line: 517
// RVA: 0x3680
void __fastcall UFG::CompositeDrawableComponent::DrawSkin(UFG::CompositeDrawableComponent *this, Render::View *view, ModelType::ModelBindingSkin *model_binding, UFG::qMatrix44 *local_matrix, SkeletalPose *pose, unsigned int pose_crc)
{
  Illusion::ModelProxy *v6; // rsi
  UFG::qMatrix44 *v7; // r12
  ModelType::ModelBindingSkin *v8; // rdi
  Render::View *v9; // r15
  UFG::CompositeDrawableComponent *v10; // r14
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v11; // rax
  float v12; // xmm6_4
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v13; // r8
  Skeleton *v14; // rax
  unsigned int v15; // ecx
  ModelType::SimpleMorphTargets *v16; // rdx
  UFG::qMatrix44 *v17; // rcx
  char *v18; // rax
  Illusion::Model *v19; // rsi
  unsigned int v20; // er8
  unsigned int v21; // eax
  float *v22; // rcx
  Illusion::Model **v23; // rdx
  UFG::qResourceData *v24; // rax
  __int64 v25; // rcx
  unsigned int v26; // edx
  float *v27; // rax
  int v28; // ebx
  __int64 v29; // rcx
  unsigned int v30; // er10
  ActiveMultiMorphTarget *v31; // rdx
  __int64 *v32; // r9
  __int64 v33; // r8
  char *v34; // rax
  ModelType::SkinnedDecalLayer *v35; // rcx
  Render::SkinClipInfo *v36; // rcx
  Render::SkinClipInfo *v37; // rcx
  UFG::qVector4 v38; // xmm3
  UFG::qVector4 v39; // xmm2
  UFG::qVector4 v40; // xmm1
  ModelType::SkinnedDecalLayer *v41; // rcx
  Render::Softbody *v42; // rcx
  UFG::ICompositeLook *v43; // rcx
  char *v44; // rbx
  Illusion::StateValues *v45; // rax
  Render::SkinningParams skinning_params; // [rsp+30h] [rbp-99h]

  v6 = &model_binding->mModelProxy;
  v7 = local_matrix;
  v8 = model_binding;
  v9 = view;
  v10 = this;
  if ( (model_binding->mModelProxy.mModelHandle.mData || model_binding->mModelProxy.mRModel)
    && model_binding->mSkeletonToModelBoneMap )
  {
    v11 = hkaPose::getSyncedPoseModelSpace(pose->mHavokPose);
    skinning_params.view = v9;
    v12 = 0.0;
    _mm_store_si128((__m128i *)&skinning_params.bone_inverse_array, (__m128i)0i64);
    _mm_store_si128((__m128i *)&skinning_params.user_data_0, (__m128i)0i64);
    _mm_store_si128((__m128i *)&skinning_params.mDecalMaterial, (__m128i)0i64);
    v13 = v11;
    v14 = pose->mRigHandle.mUFGSkeleton;
    skinning_params.skin_model_proxy = v6;
    skinning_params.local_transform = v7;
    v15 = (unsigned int)v10;
    if ( pose_crc != -1 )
      v15 = pose_crc;
    v16 = v8->mMorphTargets;
    *(_QWORD *)&skinning_params.bone_matrix_count = 0i64;
    skinning_params.mUsePersistentCache = pose_crc != -1;
    skinning_params.transform_array = 0i64;
    skinning_params.instance_uid = v15;
    skinning_params.simple_morph_target = 0i64;
    skinning_params.simple_morph_weight = 0.0;
    skinning_params.morph_weights_array = 0i64;
    skinning_params.morph_weights_count = 0;
    skinning_params.no_override = 0;
    skinning_params.clip_info = 0i64;
    *(_QWORD *)&skinning_params.mDecalVertNum = 0i64;
    skinning_params.mRigidTransform = 0i64;
    skinning_params.mHasSoftbody = 0;
    v17 = v14->mInverseModelSpace;
    v18 = v8->mSkeletonToModelBoneMap;
    skinning_params.bone_inverse_array = v17;
    skinning_params.bone_remap_array = v18;
    skinning_params.transform_array = v13->m_data;
    *(_QWORD *)&skinning_params.bone_matrix_count = v8->mNumMappedBones;
    skinning_params.transform_count = v13->m_size;
    if ( v16 )
      v19 = (Illusion::Model *)v16->mModelHandles[0].mData;
    else
      v19 = 0i64;
    if ( v16 )
      v20 = v16->mNumModelBindings;
    else
      v20 = 0;
    v21 = 0;
    if ( v20 )
    {
      v22 = v16->mMorphWeights;
      v23 = (Illusion::Model **)&v16->mModelHandles[0].mData;
      while ( *v22 <= 0.0 )
      {
        ++v21;
        ++v22;
        v23 += 4;
        if ( v21 >= v20 )
          goto LABEL_18;
      }
      v19 = *v23;
      v12 = *v22;
    }
LABEL_18:
    v24 = v8->mModelProxy.mModelHandle.mData;
    if ( v24
      && (v25 = *(_QWORD *)&v24[2].mDebugName[20]) != 0
      && (v26 = *(_DWORD *)(v25 + 120), (skinning_params.morph_weights_count = v26) != 0)
      && (v27 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * v26, 4u),
          v28 = 0,
          skinning_params.morph_weights_array = v27,
          skinning_params.morph_weights_count > 0) )
    {
      while ( 1 )
      {
        v29 = 0i64;
        v27[v28] = 0.0;
        v30 = v10->mActiveMultiMorphTargets.size;
        if ( v30 )
          break;
LABEL_28:
        if ( ++v28 >= skinning_params.morph_weights_count )
          goto LABEL_31;
        v27 = skinning_params.morph_weights_array;
      }
      v31 = v10->mActiveMultiMorphTargets.p;
      v32 = (__int64 *)(*(_QWORD *)&v8->mModelProxy.mModelHandle.mData[2].mDebugName[20] + 128i64);
      v33 = *v32;
      while ( 1 )
      {
        v34 = (char *)v32 + v33;
        if ( !v33 )
          v34 = 0i64;
        if ( v31->mMorphUID == *(_DWORD *)&v34[4 * v28] )
          break;
        v29 = (unsigned int)(v29 + 1);
        ++v31;
        if ( (unsigned int)v29 >= v30 )
          goto LABEL_28;
      }
      skinning_params.morph_weights_array[v28] = v10->mActiveMultiMorphTargets.p[v29].mMorphWeight;
    }
    else
    {
LABEL_31:
      if ( v9->mSubmitContext->mRenderPass == Solid )
      {
        v35 = v8->mDecalLayer;
        if ( v35 )
        {
          if ( v35->mClipQuery )
          {
            ModelType::SkinnedDecalLayer::UpdateDecalMesh(v35);
            v36 = v8->mDecalLayer->mClipQuery;
            if ( v36->mQueryReady )
            {
              if ( !v36->mQueryInProcess )
              {
                v36->mQueryInProcess = 1;
                v37 = v8->mDecalLayer->mClipQuery;
                v38 = v7->v1;
                v39 = v7->v2;
                v40 = v7->v3;
                v37->mModelLocalWorld.v0 = v7->v0;
                v37->mModelLocalWorld.v1 = v38;
                v37->mModelLocalWorld.v2 = v39;
                v37->mModelLocalWorld.v3 = v40;
                v41 = v8->mDecalLayer;
                skinning_params.clip_info = v41->mClipQuery;
                skinning_params.mDecalTaskUID = v41->mDecalTaskUID;
              }
            }
          }
        }
      }
      skinning_params.simple_morph_weight = v12;
      skinning_params.simple_morph_target = v19;
      if ( gEnableSoftbodySkinning )
        skinning_params.mHasSoftbody = v8->mSoftbody != 0i64;
      else
        skinning_params.mHasSoftbody = 0;
      v42 = v8->mSoftbody;
      skinning_params.user_data_0 = 0i64;
      skinning_params.no_override = 1;
      if ( v42 )
        skinning_params.user_data_1 = Render::Softbody::CreateTaskParameters(
                                        v42,
                                        (Illusion::Model *)v8->mModelProxy.mModelHandle.mData,
                                        skinning_params.local_transform);
      else
        skinning_params.user_data_1 = 0i64;
      v43 = v10->mCompositeLook;
      if ( v43 )
        v43->vfptr->OnDrawSkin(v43, v10, v9, v8, &skinning_params);
      v44 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x40u);
      UFG::qMemCopy(v44, &v10->mSceneryInstance, 0x40u);
      v45 = Render::View::GetStateValues(v9);
      v45->mSetValueMask.mFlags[0] |= 0x400000000ui64;
      v45->mParamValues[34] = v44;
      Render::View::AddMetric_NumSkinnedModelsRendered(v9, 1);
      Render::Skinning::DrawSkinnedModel(&Render::Skinning::gSkinning, &skinning_params);
    }
  }
}

// File Line: 613
// RVA: 0x34D0
void __fastcall UFG::CompositeDrawableComponent::DrawRigid(UFG::CompositeDrawableComponent *this, Render::View *view, ModelType::ModelBindingRigid *model_binding, UFG::qMatrix44 *local_matrix, SkeletalPose *pose)
{
  UFG::qMatrix44 *v5; // rbx
  ModelType::ModelBindingRigid *v6; // rdi
  Render::View *v7; // rsi
  UFG::CompositeDrawableComponent *v8; // rbp
  __int64 v9; // rdx
  hkaPose *v10; // r8
  hkQsTransformf *v11; // rax
  Render::DebugDrawContext *v12; // rax
  UFG::ICompositeLook *v13; // rcx
  char *v14; // rbx
  Illusion::StateValues *v15; // rax
  Illusion::Model *v16; // rdx
  Illusion::rModel *v17; // rdx
  hkQsTransformf v18; // [rsp+30h] [rbp-B8h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h]
  UFG::qMatrix44 d; // [rsp+A0h] [rbp-48h]

  v5 = local_matrix;
  v6 = model_binding;
  v7 = view;
  v8 = this;
  if ( (model_binding->mModelProxy.mModelHandle.mData || model_binding->mModelProxy.mRModel) && model_binding->mVisible )
  {
    v9 = model_binding->mBoneID;
    v10 = pose->mHavokPose;
    if ( v10->m_boneFlags.m_data[v9] & 2 )
      v11 = hkaPose::calculateBoneModelSpace(pose->mHavokPose, v9);
    else
      v11 = &v10->m_modelPose.m_data[v9];
    v18.m_translation = v11->m_translation;
    v18.m_rotation = v11->m_rotation;
    v18.m_scale = v11->m_scale;
    hkQsTransformf::get4x4ColumnMajor(&v18, &d.v0.x);
    UFG::qMatrix44::operator*(&d, &result, v5);
    if ( gSkeletonDebug )
    {
      v12 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v12, &result, 0.15000001, 0i64);
    }
    v13 = v8->mCompositeLook;
    if ( v13 )
      v13->vfptr->OnDrawRigid(v13, v8, v7, v6);
    v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x40u);
    UFG::qMemCopy(v14, &v8->mSceneryInstance, 0x40u);
    v15 = Render::View::GetStateValues(v7);
    v15->mSetValueMask.mFlags[0] |= 0x400000000ui64;
    v15->mParamValues[34] = v14;
    Render::View::AddMetric_NumRigidModelsRendered(v7, 1);
    v16 = (Illusion::Model *)v6->mModelProxy.mModelHandle.mData;
    if ( v16 )
    {
      SubmitRenderModel(v7, v16, &result);
    }
    else
    {
      v17 = v6->mModelProxy.mRModel;
      if ( v17 )
        Render::View::Draw(v7, v17, &result, 0);
    }
  }
}

// File Line: 651
// RVA: 0x3140
void __fastcall UFG::CompositeDrawableComponent::Draw(UFG::CompositeDrawableComponent *this, Render::View *view, int curr_lod)
{
  __int64 v3; // rbx
  Render::View *v4; // rsi
  UFG::CompositeDrawableComponent *v5; // rdi
  unsigned __int64 v6; // rax
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  ModelType *v10; // r14
  unsigned __int64 v11; // r15
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  bool v24; // al
  SkeletalPose *v25; // rdx
  float v26; // xmm7_4
  __m128 v27; // xmm1
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v28; // r8
  __int64 v29; // rdx
  __int64 v30; // rcx
  __m128 v31; // xmm1
  ModelType::ModelBindingSkin *v32; // r8
  ModelType::ModelBindingSkin *v33; // rbx
  ModelType::ModelBindingRigid *v34; // r8
  ModelType::ModelBindingRigid *v35; // rbx
  UFG::ICompositeLook *v36; // rcx
  unsigned __int64 v37; // rax
  float v38; // xmm0_4
  UFG::qMatrix44 local_matrix; // [rsp+30h] [rbp-D8h]

  v3 = (unsigned int)curr_lod;
  v4 = view;
  v5 = this;
  if ( this->mPose )
  {
    v6 = UFG::qGetTicks();
    v7 = v5->mPoseRootMatrix.v1.z;
    v8 = v5->mPoseRootMatrix.v1.w;
    v9 = v5->mPoseRootMatrix.v2.x;
    v10 = v5->mModelType[v3];
    v11 = v6;
    v12 = v5->mPoseRootMatrix.v2.y;
    v13 = v5->mPoseRootMatrix.v2.z;
    v14 = v5->mPoseRootMatrix.v2.w;
    v15 = v5->mPoseRootMatrix.v3.y;
    v16 = v5->mPoseRootMatrix.v0.x;
    v17 = v5->mPoseRootMatrix.v0.y;
    v18 = v5->mPoseRootMatrix.v0.z;
    v19 = v5->mPoseRootMatrix.v0.w;
    v20 = v5->mPoseRootMatrix.v1.x;
    v21 = v5->mPoseRootMatrix.v1.y;
    local_matrix.v3.x = v5->mPoseRootMatrix.v3.x;
    local_matrix.v3.z = v5->mPoseRootMatrix.v3.z;
    v22 = v5->mDrawScale;
    local_matrix.v3.y = v15;
    v23 = v5->mPoseRootMatrix.v3.w;
    local_matrix.v1.z = v7 * v22;
    local_matrix.v1.w = v8 * v22;
    local_matrix.v2.x = v9 * v22;
    local_matrix.v3.w = v23;
    local_matrix.v2.y = v12 * v22;
    local_matrix.v2.z = v13 * v22;
    local_matrix.v2.w = v14 * v22;
    local_matrix.v0.x = v16 * v22;
    local_matrix.v0.y = v17 * v22;
    local_matrix.v0.z = v18 * v22;
    local_matrix.v0.w = v19 * v22;
    local_matrix.v1.x = v20 * v22;
    local_matrix.v1.y = v21 * v22;
    if ( UFG::CompositeDrawableComponent::msDebugRender.mSkeletonRenderSkin )
    {
      v24 = SkeletalPose::HasPoseChanged(v5->mPose);
      v25 = v5->mPose;
      v26 = v25->mRigHandle.mUFGSkeleton->mBoneScale;
      v27 = (__m128)LODWORD(v26);
      v27.m128_f32[0] = v26 - 1.0;
      if ( (float)(v26 - 1.0) < 0.0 )
        v27 = _mm_xor_ps(v27, *(__m128 *)_xmm);
      if ( v27.m128_f32[0] >= 0.001 && v24 )
      {
        v28 = hkaPose::accessSyncedPoseLocalSpace(v25->mHavokPose);
        v29 = v5->mPose->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
        if ( v29 > 0 )
        {
          v30 = 0i64;
          v27.m128_f32[0] = 1.0 / v26;
          v31 = _mm_shuffle_ps(v27, v27, 0);
          do
          {
            ++v30;
            v28->m_data[v30 - 1].m_translation.m_quad = _mm_mul_ps(v28->m_data[v30 - 1].m_translation.m_quad, v31);
            --v29;
          }
          while ( v29 );
        }
      }
      if ( v5->mMaterialModifier.mNumOverrides )
        v4->mSubmitContext->mMaterialModifier = (Illusion::MaterialModifierData *)&v5->mMaterialModifier.mOverridesPtr;
      v32 = (ModelType::ModelBindingSkin *)v10->mModelBindingSkinTable.mNode.mNext;
      if ( v32 != (ModelType::ModelBindingSkin *)&v10->mModelBindingSkinTable )
      {
        do
        {
          v33 = (ModelType::ModelBindingSkin *)v32->mNext;
          UFG::CompositeDrawableComponent::DrawSkin(v5, v4, v32, &local_matrix, v5->mPose, 0xFFFFFFFF);
          v32 = v33;
        }
        while ( v33 != (ModelType::ModelBindingSkin *)&v10->mModelBindingSkinTable );
      }
      v34 = (ModelType::ModelBindingRigid *)v10->mModelBindingRigidTable.mNode.mNext;
      if ( v34 != (ModelType::ModelBindingRigid *)&v10->mModelBindingRigidTable )
      {
        do
        {
          v35 = (ModelType::ModelBindingRigid *)v34->mNext;
          UFG::CompositeDrawableComponent::DrawRigid(v5, v4, v34, &local_matrix, v5->mPose);
          v34 = v35;
        }
        while ( v35 != (ModelType::ModelBindingRigid *)&v10->mModelBindingRigidTable );
      }
      if ( v5->mMaterialModifier.mNumOverrides )
        v4->mSubmitContext->mMaterialModifier = 0i64;
    }
    v36 = v5->mCompositeLook;
    if ( v36 )
      v36->vfptr->OnDraw(v36, v5, v4, &local_matrix);
    v37 = UFG::qGetTicks();
    v38 = UFG::qGetTickTime(v11, v37);
    Render::View::AddMetric_DrawComposite(v4, v38);
  }
}

// File Line: 734
// RVA: 0x3040
void __fastcall UFG::CompositeDrawableComponent::Draw(UFG::CompositeDrawableComponent *this, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::CompositeDrawableComponent *v3; // rbx
  CullResults *v4; // rdx
  UFG::ICompositeLook *v5; // rcx
  __int64 v6; // rcx
  float v7; // xmm1_4
  int v8; // eax

  v2 = view;
  v3 = this;
  if ( gEnableCompositeDrawable && (UFG::Editor::GetDrawMode() || UFG::Editor::GetDrawFlags() & 4) )
  {
    Render::View::AddMetric_NumCompositeProcessed(v2, 1);
    if ( (v3->m_Flags & 3) == 1 && !v3->mIsHidden )
    {
      if ( v3->mPose->mRigHandle.mData )
      {
        v4 = v3->mCullResults;
        if ( v4 )
        {
          if ( v2->mSettings->mCullIndex < 0 || v4->mViewResult[v2->mSettings->mCullIndex] <= 1u )
          {
            v5 = v3->mCompositeLook;
            if ( !v5 || !v5->vfptr->OnIsCulled(v5, v3, v2) )
            {
              v6 = v2->mSettings->mCullIndex;
              if ( (signed int)v6 >= 6 )
                v7 = *(float *)&FLOAT_1_0;
              else
                v7 = v3->mCullResults->mPixelCoverage[v6];
              v8 = UFG::CompositeDrawableComponent::GetLOD(v3, v7);
              UFG::CompositeDrawableComponent::Draw(v3, v2, v8);
            }
          }
        }
      }
    }
  }
}

// File Line: 775
// RVA: 0x2CE0
ModelType *__fastcall UFG::CompositeDrawableComponent::CreateModelType(UFG::CompositeDrawableComponent *this, bool create_rig_bindings)
{
  bool v2; // bl
  UFG::RigResource *v3; // rdi
  char *v5; // rax
  ModelType *v6; // rax
  ModelType *v7; // r13
  unsigned int i; // ebx
  unsigned int v9; // esi
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  signed __int64 v14; // rsi
  unsigned int v15; // er13
  signed int v16; // ecx
  __int64 j; // rbx
  char *v18; // rax
  __int64 v19; // rax
  __int64 v20; // rcx
  unsigned int v21; // er12
  __int64 v22; // r15
  UFG::qResourceHandle *v23; // r14
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  unsigned int v26; // ebx
  unsigned int v27; // er14
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  UFG::qResourceHandle v32; // [rsp+38h] [rbp-28h]
  __int64 v33; // [rsp+58h] [rbp-8h]
  ModelType *v34; // [rsp+B0h] [rbp+50h]

  v2 = create_rig_bindings;
  v3 = (UFG::RigResource *)this->mRigHandle.mData;
  if ( !v3 )
    return 0i64;
  v5 = UFG::qMalloc(0xA0ui64, "ModelDataBase::ModelType", 0x800ui64);
  if ( v5 )
  {
    ModelType::ModelType((ModelType *)v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v34 = v7;
  ModelType::SetRigHandle(v7, v3->mNode.mUID, v3);
  if ( v2 )
  {
    for ( i = 0; i < v3->mNumSkins; ++i )
    {
      v9 = v3->mSkinGuids[i];
      UFG::qResourceHandle::qResourceHandle(&v32);
      v10 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
      {
        v11 = UFG::qResourceWarehouse::Instance();
        v10 = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v10;
      }
      UFG::qResourceHandle::Init(&v32, 0xA2ADCD77, v9, v10);
      v33 = 0i64;
      ModelType::AddSkinModelBinding(v7, (Illusion::ModelProxy *)&v32, &UFG::qMatrix44::msIdentity, 0, 0);
      v12 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
      {
        v13 = UFG::qResourceWarehouse::Instance();
        v12 = UFG::qResourceWarehouse::GetInventory(v13, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v12;
      }
      UFG::qResourceHandle::Close(&v32, v12);
      UFG::qResourceHandle::~qResourceHandle(&v32);
    }
    if ( v3->mNumSkinMorphs )
    {
      v14 = (signed __int64)&v7->mModelBindingSkinTable;
      v15 = 0;
      do
      {
        v16 = v3->mSkinMorphBaseSkinID[v15];
        for ( j = *(_QWORD *)(v14 + 8); v16 > 0; j = *(_QWORD *)(j + 8) )
        {
          if ( j == v14 )
            break;
          --v16;
        }
        if ( !*(_QWORD *)(j + 80) )
        {
          v18 = UFG::qMalloc(0x50ui64, "ModelDataBase::ModelType::MorphTargets", 0i64);
          if ( v18 )
            ModelType::SimpleMorphTargets::SimpleMorphTargets((ModelType::SimpleMorphTargets *)v18);
          else
            v19 = 0i64;
          *(_QWORD *)(j + 80) = v19;
        }
        v20 = *(_QWORD *)(j + 80);
        v21 = v3->mSkinMorphGuids[v15];
        v22 = *(unsigned int *)(v20 + 72);
        v23 = (UFG::qResourceHandle *)(v20 + 32 * v22);
        v24 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
        {
          v25 = UFG::qResourceWarehouse::Instance();
          v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v24;
        }
        UFG::qResourceHandle::Init(v23, 0xA2ADCD77, v21, v24);
        *(_DWORD *)(*(_QWORD *)(j + 80) + 4 * v22 + 64) = 0;
        ++*(_DWORD *)(*(_QWORD *)(j + 80) + 72i64);
        ++v15;
      }
      while ( v15 < v3->mNumSkinMorphs );
      v7 = v34;
    }
    v26 = 0;
    if ( v3->mNumModelMap )
    {
      do
      {
        v27 = v3->mModelMap[v26].modelGuid;
        UFG::qResourceHandle::qResourceHandle(&v32);
        v28 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
        {
          v29 = UFG::qResourceWarehouse::Instance();
          v28 = UFG::qResourceWarehouse::GetInventory(v29, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v28;
        }
        UFG::qResourceHandle::Init(&v32, 0xA2ADCD77, v27, v28);
        v33 = 0i64;
        ModelType::AddRigidModelBinding(
          v7,
          (Illusion::ModelProxy *)&v32,
          v3->mModelMap[v26].boneIndex,
          &UFG::qMatrix44::msIdentity,
          0);
        v30 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
        {
          v31 = UFG::qResourceWarehouse::Instance();
          v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v30;
        }
        UFG::qResourceHandle::Close(&v32, v30);
        UFG::qResourceHandle::~qResourceHandle(&v32);
        ++v26;
      }
      while ( v26 < v3->mNumModelMap );
    }
  }
  return v7;
}

// File Line: 851
// RVA: 0x3B10
char __fastcall UFG::CompositeDrawableComponent::GetTransform(UFG::CompositeDrawableComponent *this, Render::Decal *decal, UFG::qMatrix44 *mat)
{
  __int64 v3; // r9
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v4; // rax
  _BYTE *v5; // rax
  SkeletalPose *v6; // rcx

  LODWORD(v3) = 0;
  if ( (float)(*(float *)&this->mRigHandle.mUserData * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[0]) > 0.0 )
  {
    do
    {
      if ( (unsigned int)v3 >= 5 )
        break;
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (float)(*(float *)&this->mRigHandle.mUserData * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[v3]) > 0.0 );
  }
  if ( (unsigned int)v3 >= LODWORD(this->mRigHandle.mPrev) - 1 )
    LODWORD(v3) = LODWORD(this->mRigHandle.mPrev) - 1;
  if ( (_DWORD)v3 )
  {
    v4 = &(&this->vfptr)[(unsigned int)v3 + 170i64];
    do
    {
      if ( *v4 )
        break;
      --v4;
      LODWORD(v3) = v3 - 1;
    }
    while ( (_DWORD)v3 );
    if ( (_DWORD)v3 )
      return 0;
  }
  if ( LOBYTE(this->mSceneryInstance.ColourTint[0]) )
    return 0;
  v5 = *(_BYTE **)this->mSceneryInstance.SIColourTint;
  if ( v5 )
  {
    if ( *v5 > 1u )
      return 0;
  }
  v6 = *(SkeletalPose **)&this->mPoseRootMatrix.v0.x;
  if ( !v6->mHavokPose )
    return 0;
  SkeletalPose::GetPositionWS(v6, decal->mBindIndex, mat);
  return 1;
}

// File Line: 864
// RVA: 0x4220
void __fastcall UFG::TestCompositeDrawableForDecals(Render::DecalClipRequest *request, UFG::qBox *projBox)
{
  UFG::qBox *v2; // r13
  char *v3; // rbx
  char *v4; // rbp
  Render::DecalClipRequest *v5; // rsi
  __int64 v6; // rax
  signed __int64 v7; // r14
  float v8; // xmm1_4
  __int64 v9; // rcx
  unsigned int v10; // eax
  char *v11; // rax
  __int64 v12; // r15
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  __int64 v18; // rdi
  __int64 v19; // r14
  int v20; // ebx
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  Illusion::ModelProxy *v23; // rax
  Illusion::ModelProxy *v24; // rbx
  ModelType::SkinnedDecalLayer *v25; // rcx
  UFG::qVector3 min; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 max; // [rsp+40h] [rbp-98h]
  UFG::qMatrix44 matrixWS; // [rsp+50h] [rbp-88h]
  signed __int64 v29; // [rsp+F8h] [rbp+20h]

  v2 = projBox;
  v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
  v4 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
  v5 = request;
  if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
  {
    do
    {
      v6 = *((_QWORD *)v4 + 157);
      v7 = *((_QWORD *)v4 + 12) - 88i64;
      v29 = *((_QWORD *)v4 + 12) - 88i64;
      if ( v6 )
      {
        v8 = *(float *)(v6 + 40);
        v9 = 0i64;
        if ( v8 < (float)(*((float *)v4 + 366) * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[0]) )
        {
          do
          {
            if ( (unsigned int)v9 >= 5 )
              break;
            v9 = (unsigned int)(v9 + 1);
          }
          while ( v8 < (float)(*((float *)v4 + 366) * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[v9]) );
        }
        v10 = *((_DWORD *)v4 + 354) - 1;
        if ( (unsigned int)v9 >= v10 )
          v9 = v10;
        if ( (_DWORD)v9 )
        {
          v11 = &v4[8 * v9 + 1424];
          do
          {
            if ( *(_QWORD *)v11 )
              break;
            v11 -= 8;
            LODWORD(v9) = v9 - 1;
          }
          while ( (_DWORD)v9 );
        }
        if ( (v4[32] & 3) == 1 && !(_DWORD)v9 && !v4[1240] )
        {
          if ( *(_QWORD *)(*((_QWORD *)v4 + 168) + 200i64) )
          {
            v12 = *((_QWORD *)v4 + 178);
            if ( v12 )
            {
              v13 = *(float *)(v12 + 132);
              min.x = *(float *)(v12 + 128);
              v14 = *(float *)(v12 + 136);
              min.y = v13;
              v15 = *(float *)(v12 + 140);
              min.z = v14;
              v16 = *(float *)(v12 + 144);
              max.x = v15;
              v17 = *(float *)(v12 + 148);
              max.y = v16;
              max.z = v17;
              TransformAABB((UFG::qMatrix44 *)v4 + 20, &min, &max);
              if ( min.x <= v2->mMax.x
                && max.x >= v2->mMin.x
                && min.y <= v2->mMax.y
                && max.y >= v2->mMin.y
                && min.z <= v2->mMax.z
                && max.z >= v2->mMin.z )
              {
                v18 = *(_QWORD *)(v12 + 104);
                if ( v18 != v12 + 96 )
                {
                  do
                  {
                    v19 = *(_QWORD *)(v18 + 8);
                    if ( *(_WORD *)(v18 + 114) )
                    {
                      v20 = *(unsigned __int16 *)(v18 + 112);
                      SkeletalPose::GetPositionWS(*((SkeletalPose **)v4 + 168), v20, &matrixWS);
                      Illusion::ModelProxy::operator=(&v5->mModelProxy, (Illusion::ModelProxy *)(v18 + 24));
                      v21 = matrixWS.v2;
                      v5->mLocalToWorld.v0 = matrixWS.v0;
                      v5->mLocalToWorld.v1 = matrixWS.v1;
                      v22 = matrixWS.v3;
                      v5->mLocalToWorld.v2 = v21;
                      v5->mLocalToWorld.v3 = v22;
                      UFG::qSafePointer<Creature,Creature>::operator=(&v5->mComponentPtr, (UFG::SimComponent *)v4);
                      v5->mScenery = (Render::IDecalScenery *)(v4 + 64);
                      v5->mBindIndex = v20;
                      Render::DecalManager::AddClipQueue(&Render::gDecalManager, v5);
                    }
                    v18 = v19;
                  }
                  while ( v19 != v12 + 96 );
                  v7 = v29;
                  v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
                }
                if ( v5->mRadius <= 0.039999999 )
                {
                  SkeletalPose::GetPositionWS(*((SkeletalPose **)v4 + 168), 0, &matrixWS);
                  v23 = *(Illusion::ModelProxy **)(v12 + 88);
                  if ( v23 != (Illusion::ModelProxy *)(v12 + 80) )
                  {
                    do
                    {
                      v24 = (Illusion::ModelProxy *)v23->mModelHandle.mNext;
                      if ( v23[1].mModelHandle.mData || v23[1].mRModel )
                      {
                        v25 = (ModelType::SkinnedDecalLayer *)v23[2].mModelHandle.mNext;
                        if ( v25 )
                          ModelType::SkinnedDecalLayer::CreateDecal(
                            v25,
                            &v5->mMatrix,
                            &matrixWS,
                            v5->mRadius,
                            (Render::DecalSettings *)v5->mSettingsHandle.mData,
                            v23 + 1);
                      }
                      v23 = v24;
                    }
                    while ( v24 != (Illusion::ModelProxy *)(v12 + 80) );
                    v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
                  }
                }
              }
            }
          }
        }
      }
      v4 = (char *)v7;
    }
    while ( (char *)v7 != v3 );
  }
}

