// File Line: 54
// RVA: 0x1452540
__int64 dynamic_initializer_for__gDebugMultiMorphName__()
{
  UFG::qString::qString(&gDebugMultiMorphName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDebugMultiMorphName__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList__);
}

// File Line: 103
// RVA: 0x3BE0
__int64 __fastcall UFG::CompositeDrawableComponent::GetTypeSize(UFG::CompositeDrawableComponent *this)
{
  return 1504i64;
}

// File Line: 117
// RVA: 0x2270
void __fastcall UFG::CompositeDrawableComponent::CompositeDrawableComponent(UFG::CompositeDrawableComponent *this)
{
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  this->mPrev = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->mNext = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable{for `UFG::SimComponent};
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable{for `Render::IDecalScenery};
  this->mCompositeLook = 0i64;
  Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(&this->mMaterialModifier);
  this->mIsHidden = 0;
  this->mCullLayer = 0i64;
  this->mCullResults = 0i64;
  this->mCullInfo = 0i64;
  this->mPose = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  this->mRigHandle.mUFGSkeleton = 0i64;
  this->mLODBiasMult = 1.0;
  this->mDrawScale = 1.0;
  this->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&this->mActiveMultiMorphTargets.size = 0i64;
  mPrev = UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID,
    "CompositeDrawableComponent");
  UFG::CompositeDrawableComponent::Reset(this);
  UFG::qMemSet(this->mModelType, 0, 0x28u);
  if ( UFG::CompositeDrawableComponent::mDefaultCullLayer )
    UFG::CompositeDrawableComponent::SetLayer(this, UFG::CompositeDrawableComponent::mDefaultCullLayer);
}

// File Line: 141
// RVA: 0x2080
void __fastcall UFG::CompositeDrawableComponent::CompositeDrawableComponent(
        UFG::CompositeDrawableComponent *this,
        UFG::RigResource *rig)
{
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *mPrev; // rax
  ModelType *ModelType; // rax
  unsigned int mUID; // edi
  UFG::qResourceInventory *inventory; // rax
  UFG::qResourceWarehouse *v8; // rax
  ModelType *v9; // rcx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rax
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // rcx

  UFG::SimComponent::SimComponent(this, 0);
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&Render::IDecalScenery::`vftable;
  this->mAttachedDecals.mNode.Render::IDecalScenery::mPrev = &this->mAttachedDecals.mNode;
  this->mAttachedDecals.mNode.mNext = &this->mAttachedDecals.mNode;
  this->mPrev = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->mNext = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable{for `UFG::SimComponent};
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable{for `Render::IDecalScenery};
  this->mCompositeLook = 0i64;
  Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(&this->mMaterialModifier);
  this->mIsHidden = 0;
  this->mCullLayer = 0i64;
  this->mCullResults = 0i64;
  this->mCullInfo = 0i64;
  this->mPose = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  this->mRigHandle.mUFGSkeleton = 0i64;
  this->mLODBiasMult = 1.0;
  this->mDrawScale = 1.0;
  this->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&this->mActiveMultiMorphTargets.size = 0i64;
  mPrev = UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList;
  UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CompositeDrawableComponent::_CompositeDrawableComponentTypeUID,
    "CompositeDrawableComponent");
  UFG::CompositeDrawableComponent::Reset(this);
  UFG::qMemSet(this->mModelType, 0, 0x28u);
  ModelType = UFG::CompositeDrawableComponent::CreateModelType(this, 1);
  this->mModelType[0] = ModelType;
  this->mNumModelTypeLODs = ModelType != 0i64;
  mUID = rig->mNode.mUID;
  inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    inventory = UFG::qResourceWarehouse::GetInventory(v8, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = inventory;
  }
  UFG::qResourceHandle::Init(&this->mRigHandle, 0x39BC0A7Eu, mUID, rig, inventory);
  if ( UFG::CompositeDrawableComponent::mDefaultCullLayer )
    UFG::CompositeDrawableComponent::SetLayer(this, UFG::CompositeDrawableComponent::mDefaultCullLayer);
  this->mHasSoftBody = 0;
  v9 = this->mModelType[0];
  if ( v9 )
  {
    mNext = v9->mModelBindingSkinTable.mNode.mNext;
    p_mModelBindingSkinTable = &v9->mModelBindingSkinTable;
    if ( mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
    {
      while ( !mNext[6].mPrev )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
          return;
      }
      this->mHasSoftBody = 1;
    }
  }
}

// File Line: 160
// RVA: 0x25D0
void __fastcall UFG::CompositeDrawableComponent::~CompositeDrawableComponent(UFG::CompositeDrawableComponent *this)
{
  Render::IDecalScenery *v2; // r15
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v3; // r14
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *mPrev; // rcx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *mNext; // rax
  __int64 i; // rdi
  ModelType *v7; // rsi
  ActiveMultiMorphTarget *p; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v10; // rax
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v11; // rcx
  UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> *v12; // rax
  UFG::qList<Render::Decal,Render::Decal,0,0> *p_mAttachedDecals; // r8
  UFG::qList<Render::Decal,Render::Decal,0,0> *v14; // rax
  UFG::qNode<Render::Decal,Render::Decal> *v15; // rdx
  UFG::qNode<Render::Decal,Render::Decal> *v16; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v17; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v18; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CompositeDrawableComponent::`vftable{for `UFG::SimComponent};
  v2 = &this->Render::IDecalScenery;
  this->Render::IDecalScenery::vfptr = (Render::IDecalSceneryVtbl *)&UFG::CompositeDrawableComponent::`vftable{for `Render::IDecalScenery};
  if ( this == UFG::CompositeDrawableComponent::s_CompositeDrawableComponentpCurrentIterator )
    UFG::CompositeDrawableComponent::s_CompositeDrawableComponentpCurrentIterator = (UFG::CompositeDrawableComponent *)&this->mPrev[-6].mNext;
  v3 = &this->UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent>;
  mPrev = this->mPrev;
  mNext = v3->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  Render::IDecalScenery::RemoveAttachedDecals(v2, 0xFFFFFFFF);
  for ( i = 0i64; (unsigned int)i < this->mNumModelTypeLODs; i = (unsigned int)(i + 1) )
  {
    v7 = this->mModelType[i];
    if ( v7 )
    {
      ModelType::~ModelType(this->mModelType[i]);
      operator delete[](v7);
    }
  }
  p = this->mActiveMultiMorphTargets.p;
  if ( p )
    operator delete[](p);
  this->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&this->mActiveMultiMorphTargets.size = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v10 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v10, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mRigHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mRigHandle);
  `eh vector destructor iterator(
    this->mMaterialModifier.mOverrides,
    0x68ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ParamOverride::~ParamOverride);
  v11 = v3->mPrev;
  v12 = v3->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v3->mPrev = v3;
  v3->mNext = v3;
  p_mAttachedDecals = &v2->mAttachedDecals;
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
    while ( v14 != p_mAttachedDecals );
  }
  v17 = p_mAttachedDecals->mNode.mPrev;
  v18 = v2->mAttachedDecals.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mAttachedDecals->mNode.mPrev = &p_mAttachedDecals->mNode;
  v2->mAttachedDecals.mNode.mNext = &v2->mAttachedDecals.mNode;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 172
// RVA: 0x4000
void __fastcall UFG::CompositeDrawableComponent::SetIsHidden(UFG::CompositeDrawableComponent *this, bool bIsHidden)
{
  UFG::ICompositeLook *mCompositeLook; // r9

  mCompositeLook = this->mCompositeLook;
  this->mIsHidden = bIsHidden;
  if ( mCompositeLook )
    mCompositeLook->vfptr->OnSetHidden(mCompositeLook, this, bIsHidden);
}

// File Line: 181
// RVA: 0x2C40
void __fastcall UFG::CompositeDrawableComponent::ClearLODs(UFG::CompositeDrawableComponent *this)
{
  unsigned int v1; // ebx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v3; // r14
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v4; // rsi

  v1 = 1;
  if ( this->mNumModelTypeLODs <= 1 )
  {
    this->mNumModelTypeLODs = 1;
  }
  else
  {
    do
    {
      v3 = &(&this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr)[v1];
      v4 = v3[178];
      if ( v4 )
      {
        ModelType::~ModelType((ModelType *)v3[178]);
        operator delete[](v4);
      }
      ++v1;
      v3[178] = 0i64;
    }
    while ( v1 < this->mNumModelTypeLODs );
    this->mNumModelTypeLODs = 1;
  }
}

// File Line: 191
// RVA: 0x3DC0
void __fastcall UFG::CompositeDrawableComponent::Reset(UFG::CompositeDrawableComponent *this)
{
  ActiveMultiMorphTarget *p; // rcx
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  UFG::ICompositeLook *mCompositeLook; // rcx

  this->mIsHidden = 0;
  p = this->mActiveMultiMorphTargets.p;
  if ( p )
    operator delete[](p);
  this->mActiveMultiMorphTargets.p = 0i64;
  *(_QWORD *)&this->mActiveMultiMorphTargets.size = 0i64;
  this->mDrawScale = 1.0;
  z = UFG::qVector4::msOne.z;
  w = UFG::qVector4::msOne.w;
  x = UFG::qVector4::msOne.x;
  this->mSceneryInstance.SIColourTint[1] = UFG::qVector4::msOne.y;
  this->mSceneryInstance.SIColourTint[2] = z;
  this->mSceneryInstance.SIColourTint[0] = x;
  this->mSceneryInstance.SIColourTint[3] = w;
  y = UFG::qVector4::msOne.y;
  v7 = UFG::qVector4::msOne.z;
  v8 = UFG::qVector4::msOne.w;
  this->mSceneryInstance.Value0[0] = UFG::qVector4::msOne.x;
  this->mSceneryInstance.Value0[1] = y;
  this->mSceneryInstance.Value0[2] = v7;
  this->mSceneryInstance.Value0[3] = v8;
  v9 = UFG::qVector4::msOne.z;
  v10 = UFG::qVector4::msOne.w;
  v11 = UFG::qVector4::msOne.x;
  this->mSceneryInstance.ColourTint[1] = UFG::qVector4::msOne.y;
  this->mSceneryInstance.ColourTint[0] = v11;
  this->mSceneryInstance.ColourTint[2] = v9;
  this->mSceneryInstance.ColourTint[3] = v10;
  v12 = UFG::qVector4::msOne.z;
  v13 = UFG::qVector4::msOne.w;
  v14 = UFG::qVector4::msOne.x;
  this->mSceneryInstance.Mask[1] = UFG::qVector4::msOne.y;
  this->mSceneryInstance.Mask[2] = v12;
  this->mSceneryInstance.Mask[0] = v14;
  this->mSceneryInstance.Mask[3] = v13;
  Render::IDecalScenery::RemoveAttachedDecals(&this->Render::IDecalScenery, 0xFFFFFFFF);
  mCompositeLook = this->mCompositeLook;
  if ( mCompositeLook )
    mCompositeLook->vfptr->OnReset(mCompositeLook, this);
}

// File Line: 235
// RVA: 0x3F30
void __fastcall UFG::CompositeDrawableComponent::ResetModelType(UFG::CompositeDrawableComponent *this)
{
  ModelType *ModelType; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rcx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // rax

  UFG::CompositeDrawableComponent::ClearLODs(this);
  ModelType = UFG::CompositeDrawableComponent::CreateModelType(this, 1);
  this->mHasSoftBody = 0;
  this->mModelType[0] = ModelType;
  if ( ModelType )
  {
    mNext = ModelType->mModelBindingSkinTable.mNode.mNext;
    p_mModelBindingSkinTable = &ModelType->mModelBindingSkinTable;
    if ( mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
    {
      while ( !mNext[6].mPrev )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
          return;
      }
      this->mHasSoftBody = 1;
    }
  }
}

// File Line: 245
// RVA: 0x3CE0
void __fastcall UFG::CompositeDrawableComponent::OnAttach(
        UFG::CompositeDrawableComponent *this,
        UFG::SimObject *object)
{
  ModelType *v3; // rdx
  ModelType *mNext; // rax

  if ( !this->mModelType[0] )
    this->mModelType[0] = UFG::CompositeDrawableComponent::CreateModelType(this, 1);
  v3 = this->mModelType[0];
  this->mHasSoftBody = 0;
  if ( v3 )
  {
    mNext = (ModelType *)v3->mModelBindingSkinTable.mNode.mNext;
    if ( mNext != (ModelType *)&v3->mModelBindingSkinTable )
    {
      while ( !mNext->mModelBindingRigidTable.mNode.mPrev )
      {
        mNext = (ModelType *)mNext->mNext;
        if ( mNext == (ModelType *)&v3->mModelBindingSkinTable )
          goto LABEL_9;
      }
      this->mHasSoftBody = 1;
    }
  }
LABEL_9:
  this->mNumModelTypeLODs = v3 != 0i64;
}

// File Line: 253
// RVA: 0x3D60
void __fastcall UFG::CompositeDrawableComponent::OnDetach(UFG::CompositeDrawableComponent *this)
{
  CullResults *mCullResults; // rdi
  CullManager *v3; // rax

  mCullResults = this->mCullResults;
  this->mPose = 0i64;
  if ( mCullResults )
  {
    v3 = CullManager::Instance();
    CullManager::FreePersistentCullInfo(v3, mCullResults, this->mCullInfo);
    this->mCullInfo = 0i64;
    this->mCullResults = 0i64;
  }
}

// File Line: 259
// RVA: 0x4830
void __fastcall UFG::CompositeDrawableComponent::UpdateHasSoftBody(UFG::CompositeDrawableComponent *this)
{
  ModelType *v1; // rdx
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rax
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // rdx

  this->mHasSoftBody = 0;
  v1 = this->mModelType[0];
  if ( v1 )
  {
    mNext = v1->mModelBindingSkinTable.mNode.mNext;
    p_mModelBindingSkinTable = &v1->mModelBindingSkinTable;
    if ( mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
    {
      while ( !mNext[6].mPrev )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)p_mModelBindingSkinTable )
          return;
      }
      this->mHasSoftBody = 1;
    }
  }
}

// File Line: 276
// RVA: 0x41C0
void __fastcall UFG::CompositeDrawableComponent::TeleportEventHandler(
        UFG::CompositeDrawableComponent *this,
        UFG::Event *event)
{
  ModelType *v2; // rdi
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *i; // rdi
  Render::Softbody *mPrev; // rcx

  if ( this->mHasSoftBody )
  {
    v2 = this->mModelType[0];
    if ( v2 )
    {
      mNext = v2->mModelBindingSkinTable.mNode.mNext;
      for ( i = &v2->mModelBindingSkinTable;
            mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)i;
            mNext = mNext->mNext )
      {
        mPrev = (Render::Softbody *)mNext[6].mPrev;
        if ( mPrev )
          Render::Softbody::ForceReset(mPrev);
      }
    }
  }
}

// File Line: 313
// RVA: 0x4870
void UFG::CompositeDrawableComponent::UpdateTransformsAll(void)
{
  UFG::CompositeDrawableComponent *p_mNext; // rbx
  UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *v1; // rsi
  ModelType *v2; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mNext; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *i; // rdi
  Render::Softbody *mPrev; // rcx

  p_mNext = (UFG::CompositeDrawableComponent *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
  {
    do
    {
      v1 = (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)&p_mNext->mNext[-6].mNext;
      if ( (p_mNext->m_Flags & 3) == 1 )
      {
        UFG::CompositeDrawableComponent::UpdateCullInfo(p_mNext);
        if ( p_mNext->mHasSoftBody )
        {
          v2 = p_mNext->mModelType[0];
          mNext = v2->mModelBindingSkinTable.mNode.mNext;
          for ( i = &v2->mModelBindingSkinTable;
                mNext != (UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *)i;
                mNext = mNext->mNext )
          {
            mPrev = (Render::Softbody *)mNext[6].mPrev;
            if ( mPrev )
              Render::Softbody::UpdateTransform(mPrev);
          }
        }
      }
      p_mNext = (UFG::CompositeDrawableComponent *)v1;
    }
    while ( v1 != (UFG::qList<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent,1,0> *)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) );
  }
}

// File Line: 324
// RVA: 0x4030
void __fastcall UFG::CompositeDrawableComponent::SetLayer(UFG::CompositeDrawableComponent *this, CullLayer *cull_layer)
{
  CullInfo *mCullInfo; // rbx
  CullResults *mCullResults; // rbp
  CullManager *v6; // rax
  CullManager *v7; // rax
  UFG::qVector4 v8; // xmm2

  mCullInfo = this->mCullInfo;
  if ( mCullInfo )
  {
    if ( mCullInfo->mCullLayer == cull_layer )
      return;
    mCullResults = this->mCullResults;
    if ( mCullResults )
    {
      v6 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v6, mCullResults, mCullInfo);
      this->mCullInfo = 0i64;
      this->mCullResults = 0i64;
    }
  }
  this->mCullLayer = cull_layer;
  v7 = CullManager::Instance();
  CullManager::AllocPersistentCullInfo(v7, &this->mCullResults, &this->mCullInfo, cull_layer, this, this);
  v8 = 0i64;
  v8.x = (float)1;
  this->mPoseRootMatrix.v0 = v8;
  this->mPoseRootMatrix.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 81);
  this->mPoseRootMatrix.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 69);
  this->mPoseRootMatrix.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v8, (__m128)v8, 21);
  this->mCullInfo->mpLocalWorld = &this->mPoseRootMatrix.v0.x;
}

// File Line: 349
// RVA: 0x45A0
void __fastcall UFG::CompositeDrawableComponent::UpdateCullInfo(UFG::CompositeDrawableComponent *this)
{
  SkeletalPose *v2; // rax
  ModelType *v3; // rbx
  float x; // eax
  CullInfo *mCullInfo; // rdi
  float z; // xmm1_4
  float y; // xmm0_4
  float v8; // xmm1_4
  SkeletalPose *mPose; // rdx
  hkaPose *mHavokPose; // rcx
  hkQsTransformf *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  CullResults *mCullResults; // rbx
  CullManager *v26; // rax

  if ( (this->m_Flags & 3) == 1 && !this->mIsHidden && (v2 = this->mPose) != 0i64 && v2->mRigHandle.mData )
  {
    if ( !this->mCullInfo )
      UFG::CompositeDrawableComponent::SetLayer(this, this->mCullLayer);
    v3 = this->mModelType[0];
    this->mCullInfo->mViewsCulled = 0;
    ModelType::UpdateAABB(v3, this->mPose);
    this->mCullInfo->mPixelScaleBias = CullManager::Instance()->mPixelDensityDynamicBias;
    x = v3->mAABBMin.x;
    mCullInfo = this->mCullInfo;
    z = v3->mAABBMin.z;
    mCullInfo->mAABBMin[1] = v3->mAABBMin.y;
    mCullInfo->mAABBMin[2] = z;
    mCullInfo->mAABBMin[0] = x;
    y = v3->mAABBMax.y;
    v8 = v3->mAABBMax.z;
    mCullInfo->mAABBMax[0] = v3->mAABBMax.x;
    mCullInfo->mAABBMax[1] = y;
    mCullInfo->mAABBMax[2] = v8;
    SkeletalPose::GetRootMatrix(this->mPose, &this->mPoseRootMatrix);
    mPose = this->mPose;
    if ( mPose->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size > 1 )
    {
      mHavokPose = mPose->mHavokPose;
      if ( (mHavokPose->m_boneFlags.m_data[1] & 2) != 0 )
        v11 = hkaPose::calculateBoneModelSpace(mHavokPose, 1);
      else
        v11 = mHavokPose->m_modelPose.m_data + 1;
      v12 = mCullInfo->mAABBMin[0];
      if ( mCullInfo->mAABBMin[0] >= v11->m_translation.m_quad.m128_f32[0] )
        v12 = v11->m_translation.m_quad.m128_f32[0];
      mCullInfo->mAABBMin[0] = v12;
      v13 = mCullInfo->mAABBMin[1];
      if ( v13 >= v11->m_translation.m_quad.m128_f32[1] )
        v13 = v11->m_translation.m_quad.m128_f32[1];
      mCullInfo->mAABBMin[1] = v13;
      v14 = mCullInfo->mAABBMin[2];
      if ( v14 >= v11->m_translation.m_quad.m128_f32[2] )
        v14 = v11->m_translation.m_quad.m128_f32[2];
      mCullInfo->mAABBMin[2] = v14;
      v15 = mCullInfo->mAABBMax[0];
      if ( v15 <= v11->m_translation.m_quad.m128_f32[0] )
        v15 = v11->m_translation.m_quad.m128_f32[0];
      mCullInfo->mAABBMax[0] = v15;
      v16 = mCullInfo->mAABBMax[1];
      if ( v16 <= v11->m_translation.m_quad.m128_f32[1] )
        v16 = v11->m_translation.m_quad.m128_f32[1];
      mCullInfo->mAABBMax[1] = v16;
      v17 = mCullInfo->mAABBMax[2];
      if ( v17 <= v11->m_translation.m_quad.m128_f32[2] )
        v17 = v11->m_translation.m_quad.m128_f32[2];
      mCullInfo->mAABBMax[2] = v17;
    }
    v18 = this->mPose->mRigHandle.mUFGSkeleton->mBoneScale * this->mDrawScale;
    v19 = v18 * mCullInfo->mAABBMin[2];
    v20 = v18 * mCullInfo->mAABBMin[0];
    v21 = v18 * mCullInfo->mAABBMin[1];
    mCullInfo->mAABBMin[2] = v19;
    mCullInfo->mAABBMin[0] = v20;
    mCullInfo->mAABBMin[1] = v21;
    v22 = this->mPose->mRigHandle.mUFGSkeleton->mBoneScale * this->mDrawScale;
    v23 = v22 * mCullInfo->mAABBMax[0];
    v24 = v22 * mCullInfo->mAABBMax[1];
    mCullInfo->mAABBMax[2] = v22 * mCullInfo->mAABBMax[2];
    mCullInfo->mAABBMax[0] = v23;
    mCullInfo->mAABBMax[1] = v24;
  }
  else
  {
    mCullResults = this->mCullResults;
    if ( mCullResults )
    {
      v26 = CullManager::Instance();
      CullManager::FreePersistentCullInfo(v26, mCullResults, this->mCullInfo);
      this->mCullInfo = 0i64;
      this->mCullResults = 0i64;
    }
  }
}

// File Line: 406
// RVA: 0x3A50
__int64 __fastcall UFG::CompositeDrawableComponent::GetLOD(UFG::CompositeDrawableComponent *this, float pixel_coverage)
{
  __int64 v2; // rdx
  ModelType **v3; // rax

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
    v3 = &this->mModelType[(unsigned int)v2];
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
CullResults *__fastcall UFG::CompositeDrawableComponent::GetMainViewLOD(UFG::CompositeDrawableComponent *this)
{
  CullResults *result; // rax

  result = this->mCullResults;
  if ( result )
    return (CullResults *)UFG::CompositeDrawableComponent::GetLOD(this, result->mPixelCoverage[0]);
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
void __fastcall UFG::CompositeDrawableComponent::DrawSkin(
        UFG::CompositeDrawableComponent *this,
        Render::View *view,
        ModelType::ModelBindingSkin *model_binding,
        UFG::qMatrix44 *local_matrix,
        SkeletalPose *pose,
        unsigned int pose_crc)
{
  Illusion::ModelProxy *p_mModelProxy; // rsi
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax
  float v12; // xmm6_4
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v13; // r8
  Skeleton *mUFGSkeleton; // rax
  unsigned int v15; // ecx
  ModelType::SimpleMorphTargets *mMorphTargets; // rdx
  UFG::qMatrix44 *mInverseModelSpace; // rcx
  char *mSkeletonToModelBoneMap; // rax
  Illusion::Model *mData; // rsi
  unsigned int mNumModelBindings; // r8d
  unsigned int v21; // eax
  float *mMorphWeights; // rcx
  Illusion::Model **p_mData; // rdx
  UFG::qResourceData *v24; // rax
  __int64 v25; // rcx
  unsigned int v26; // edx
  float *morph_weights_array; // rax
  int v28; // ebx
  __int64 v29; // rcx
  unsigned int size; // r10d
  ActiveMultiMorphTarget *p; // rdx
  __int64 *v32; // r9
  __int64 v33; // r8
  char *v34; // rax
  ModelType::SkinnedDecalLayer *mDecalLayer; // rcx
  Render::SkinClipInfo *mClipQuery; // rcx
  Render::SkinClipInfo *v37; // rcx
  UFG::qVector4 v38; // xmm3
  UFG::qVector4 v39; // xmm2
  UFG::qVector4 v40; // xmm1
  ModelType::SkinnedDecalLayer *v41; // rcx
  Render::Softbody *mSoftbody; // rcx
  UFG::ICompositeLook *mCompositeLook; // rcx
  char *v44; // rbx
  Illusion::StateValues *StateValues; // rax
  Render::SkinningParams skinning_params; // [rsp+30h] [rbp-99h] BYREF

  p_mModelProxy = &model_binding->mModelProxy;
  if ( (model_binding->mModelProxy.mModelHandle.mData || model_binding->mModelProxy.mRModel)
    && model_binding->mSkeletonToModelBoneMap )
  {
    SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(pose->mHavokPose);
    skinning_params.view = view;
    v12 = 0.0;
    *(_OWORD *)&skinning_params.bone_inverse_array = 0i64;
    *(_OWORD *)&skinning_params.user_data_0 = 0i64;
    *(_OWORD *)&skinning_params.mDecalMaterial = 0i64;
    v13 = SyncedPoseModelSpace;
    mUFGSkeleton = pose->mRigHandle.mUFGSkeleton;
    skinning_params.skin_model_proxy = p_mModelProxy;
    skinning_params.local_transform = local_matrix;
    v15 = (unsigned int)this;
    if ( pose_crc != -1 )
      v15 = pose_crc;
    mMorphTargets = model_binding->mMorphTargets;
    memset(&skinning_params.bone_matrix_count, 0, 20);
    skinning_params.mUsePersistentCache = pose_crc != -1;
    skinning_params.transform_array = 0i64;
    skinning_params.instance_uid = v15;
    skinning_params.morph_weights_array = 0i64;
    skinning_params.morph_weights_count = 0;
    skinning_params.no_override = 0;
    skinning_params.clip_info = 0i64;
    memset(&skinning_params.mDecalVertNum, 0, 17);
    mInverseModelSpace = mUFGSkeleton->mInverseModelSpace;
    mSkeletonToModelBoneMap = model_binding->mSkeletonToModelBoneMap;
    skinning_params.bone_inverse_array = mInverseModelSpace;
    skinning_params.bone_remap_array = mSkeletonToModelBoneMap;
    skinning_params.transform_array = v13->m_data;
    skinning_params.bone_matrix_count = model_binding->mNumMappedBones;
    skinning_params.transform_count = v13->m_size;
    if ( mMorphTargets )
      mData = (Illusion::Model *)mMorphTargets->mModelHandles[0].mData;
    else
      mData = 0i64;
    if ( mMorphTargets )
      mNumModelBindings = mMorphTargets->mNumModelBindings;
    else
      mNumModelBindings = 0;
    v21 = 0;
    if ( mNumModelBindings )
    {
      mMorphWeights = mMorphTargets->mMorphWeights;
      p_mData = (Illusion::Model **)&mMorphTargets->mModelHandles[0].mData;
      while ( *mMorphWeights <= 0.0 )
      {
        ++v21;
        ++mMorphWeights;
        p_mData += 4;
        if ( v21 >= mNumModelBindings )
          goto LABEL_18;
      }
      mData = *p_mData;
      v12 = *mMorphWeights;
    }
LABEL_18:
    v24 = model_binding->mModelProxy.mModelHandle.mData;
    if ( v24
      && (v25 = *(_QWORD *)&v24[2].mDebugName[20]) != 0
      && (v26 = *(_DWORD *)(v25 + 120), (skinning_params.morph_weights_count = v26) != 0)
      && (morph_weights_array = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * v26, 4u),
          v28 = 0,
          skinning_params.morph_weights_array = morph_weights_array,
          skinning_params.morph_weights_count) )
    {
      while ( 1 )
      {
        v29 = 0i64;
        morph_weights_array[v28] = 0.0;
        size = this->mActiveMultiMorphTargets.size;
        if ( size )
          break;
LABEL_28:
        if ( ++v28 >= skinning_params.morph_weights_count )
          goto LABEL_31;
        morph_weights_array = skinning_params.morph_weights_array;
      }
      p = this->mActiveMultiMorphTargets.p;
      v32 = (__int64 *)(*(_QWORD *)&model_binding->mModelProxy.mModelHandle.mData[2].mDebugName[20] + 128i64);
      v33 = *v32;
      while ( 1 )
      {
        v34 = (char *)v32 + v33;
        if ( !v33 )
          v34 = 0i64;
        if ( p->mMorphUID == *(_DWORD *)&v34[4 * v28] )
          break;
        v29 = (unsigned int)(v29 + 1);
        ++p;
        if ( (unsigned int)v29 >= size )
          goto LABEL_28;
      }
      skinning_params.morph_weights_array[v28] = this->mActiveMultiMorphTargets.p[v29].mMorphWeight;
    }
    else
    {
LABEL_31:
      if ( view->mSubmitContext->mRenderPass == Solid )
      {
        mDecalLayer = model_binding->mDecalLayer;
        if ( mDecalLayer )
        {
          if ( mDecalLayer->mClipQuery )
          {
            ModelType::SkinnedDecalLayer::UpdateDecalMesh(mDecalLayer);
            mClipQuery = model_binding->mDecalLayer->mClipQuery;
            if ( mClipQuery->mQueryReady && !mClipQuery->mQueryInProcess )
            {
              mClipQuery->mQueryInProcess = 1;
              v37 = model_binding->mDecalLayer->mClipQuery;
              v38 = local_matrix->v1;
              v39 = local_matrix->v2;
              v40 = local_matrix->v3;
              v37->mModelLocalWorld.v0 = local_matrix->v0;
              v37->mModelLocalWorld.v1 = v38;
              v37->mModelLocalWorld.v2 = v39;
              v37->mModelLocalWorld.v3 = v40;
              v41 = model_binding->mDecalLayer;
              skinning_params.clip_info = v41->mClipQuery;
              skinning_params.mDecalTaskUID = v41->mDecalTaskUID;
            }
          }
        }
      }
      skinning_params.simple_morph_weight = v12;
      skinning_params.simple_morph_target = mData;
      skinning_params.mHasSoftbody = gEnableSoftbodySkinning && model_binding->mSoftbody != 0i64;
      mSoftbody = model_binding->mSoftbody;
      skinning_params.user_data_0 = 0i64;
      skinning_params.no_override = 1;
      if ( mSoftbody )
        skinning_params.user_data_1 = Render::Softbody::CreateTaskParameters(
                                        mSoftbody,
                                        (Illusion::Model *)model_binding->mModelProxy.mModelHandle.mData,
                                        skinning_params.local_transform);
      else
        skinning_params.user_data_1 = 0i64;
      mCompositeLook = this->mCompositeLook;
      if ( mCompositeLook )
        mCompositeLook->vfptr->OnDrawSkin(mCompositeLook, this, view, model_binding, &skinning_params);
      v44 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x40u);
      UFG::qMemCopy(v44, &this->mSceneryInstance, 0x40u);
      StateValues = Render::View::GetStateValues(view);
      StateValues->mSetValueMask.mFlags[0] |= 0x400000000ui64;
      StateValues->mParamValues[34] = v44;
      Render::View::AddMetric_NumSkinnedModelsRendered(view, 1);
      Render::Skinning::DrawSkinnedModel(&Render::Skinning::gSkinning, &skinning_params);
    }
  }
}

// File Line: 613
// RVA: 0x34D0
void __fastcall UFG::CompositeDrawableComponent::DrawRigid(
        UFG::CompositeDrawableComponent *this,
        Render::View *view,
        ModelType::ModelBindingRigid *model_binding,
        UFG::qMatrix44 *local_matrix,
        SkeletalPose *pose)
{
  __int64 mBoneID; // rdx
  hkaPose *mHavokPose; // r8
  hkQsTransformf *v11; // rax
  Render::DebugDrawContext *Context; // rax
  UFG::ICompositeLook *mCompositeLook; // rcx
  char *v14; // rbx
  Illusion::StateValues *StateValues; // rax
  Illusion::Model *mData; // rdx
  Illusion::rModel *mRModel; // rdx
  hkQsTransformf v18; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h] BYREF
  UFG::qMatrix44 d; // [rsp+A0h] [rbp-48h] BYREF

  if ( (model_binding->mModelProxy.mModelHandle.mData || model_binding->mModelProxy.mRModel) && model_binding->mVisible )
  {
    mBoneID = model_binding->mBoneID;
    mHavokPose = pose->mHavokPose;
    if ( (mHavokPose->m_boneFlags.m_data[mBoneID] & 2) != 0 )
      v11 = hkaPose::calculateBoneModelSpace(pose->mHavokPose, mBoneID);
    else
      v11 = &mHavokPose->m_modelPose.m_data[mBoneID];
    v18 = *v11;
    hkQsTransformf::get4x4ColumnMajor(&v18, &d.v0.x);
    UFG::qMatrix44::operator*(&d, &result, local_matrix);
    if ( gSkeletonDebug )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawCoord(Context, &result, 0.15000001, 0i64);
    }
    mCompositeLook = this->mCompositeLook;
    if ( mCompositeLook )
      mCompositeLook->vfptr->OnDrawRigid(mCompositeLook, this, view, model_binding);
    v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x40u);
    UFG::qMemCopy(v14, &this->mSceneryInstance, 0x40u);
    StateValues = Render::View::GetStateValues(view);
    StateValues->mSetValueMask.mFlags[0] |= 0x400000000ui64;
    StateValues->mParamValues[34] = v14;
    Render::View::AddMetric_NumRigidModelsRendered(view, 1);
    mData = (Illusion::Model *)model_binding->mModelProxy.mModelHandle.mData;
    if ( mData )
    {
      SubmitRenderModel(view, mData, &result);
    }
    else
    {
      mRModel = model_binding->mModelProxy.mRModel;
      if ( mRModel )
        Render::View::Draw(view, mRModel, &result, 0);
    }
  }
}

// File Line: 651
// RVA: 0x3140
void __fastcall UFG::CompositeDrawableComponent::Draw(
        UFG::CompositeDrawableComponent *this,
        Render::View *view,
        unsigned int curr_lod)
{
  __int64 v3; // rbx
  unsigned __int64 Ticks; // rax
  float z; // xmm8_4
  float w; // xmm9_4
  float x; // xmm10_4
  ModelType *v10; // r14
  unsigned __int64 v11; // r15
  float y; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm13_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float mDrawScale; // xmm0_4
  float v23; // xmm1_4
  bool HasPoseChanged; // al
  SkeletalPose *mPose; // rdx
  float mBoneScale; // xmm7_4
  __m128 v27; // xmm1
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v28; // r8
  __int64 m_size; // rdx
  __int64 v30; // rcx
  __m128 v31; // xmm1
  ModelType::ModelBindingSkin *mNext; // r8
  ModelType::ModelBindingSkin *v33; // rbx
  ModelType::ModelBindingRigid *v34; // r8
  ModelType::ModelBindingRigid *v35; // rbx
  UFG::ICompositeLook *mCompositeLook; // rcx
  unsigned __int64 v37; // rax
  float TickTime; // xmm0_4
  UFG::qMatrix44 local_matrix; // [rsp+30h] [rbp-D8h] BYREF

  v3 = curr_lod;
  if ( this->mPose )
  {
    Ticks = UFG::qGetTicks();
    z = this->mPoseRootMatrix.v1.z;
    w = this->mPoseRootMatrix.v1.w;
    x = this->mPoseRootMatrix.v2.x;
    v10 = this->mModelType[v3];
    v11 = Ticks;
    y = this->mPoseRootMatrix.v2.y;
    v13 = this->mPoseRootMatrix.v2.z;
    v14 = this->mPoseRootMatrix.v2.w;
    v15 = this->mPoseRootMatrix.v3.y;
    v16 = this->mPoseRootMatrix.v0.x;
    v17 = this->mPoseRootMatrix.v0.y;
    v18 = this->mPoseRootMatrix.v0.z;
    v19 = this->mPoseRootMatrix.v0.w;
    v20 = this->mPoseRootMatrix.v1.x;
    v21 = this->mPoseRootMatrix.v1.y;
    local_matrix.v3.x = this->mPoseRootMatrix.v3.x;
    local_matrix.v3.z = this->mPoseRootMatrix.v3.z;
    mDrawScale = this->mDrawScale;
    local_matrix.v3.y = v15;
    v23 = this->mPoseRootMatrix.v3.w;
    local_matrix.v1.z = z * mDrawScale;
    local_matrix.v1.w = w * mDrawScale;
    local_matrix.v2.x = x * mDrawScale;
    local_matrix.v3.w = v23;
    local_matrix.v2.y = y * mDrawScale;
    local_matrix.v2.z = v13 * mDrawScale;
    local_matrix.v2.w = v14 * mDrawScale;
    local_matrix.v0.x = v16 * mDrawScale;
    local_matrix.v0.y = v17 * mDrawScale;
    local_matrix.v0.z = v18 * mDrawScale;
    local_matrix.v0.w = v19 * mDrawScale;
    local_matrix.v1.x = v20 * mDrawScale;
    local_matrix.v1.y = v21 * mDrawScale;
    if ( UFG::CompositeDrawableComponent::msDebugRender.mSkeletonRenderSkin )
    {
      HasPoseChanged = SkeletalPose::HasPoseChanged(this->mPose);
      mPose = this->mPose;
      mBoneScale = mPose->mRigHandle.mUFGSkeleton->mBoneScale;
      v27 = (__m128)LODWORD(mBoneScale);
      v27.m128_f32[0] = mBoneScale - 1.0;
      if ( (float)(mBoneScale - 1.0) < 0.0 )
        v27 = _mm_xor_ps(v27, *(__m128 *)_xmm);
      if ( v27.m128_f32[0] >= 0.001 && HasPoseChanged )
      {
        v28 = hkaPose::accessSyncedPoseLocalSpace(mPose->mHavokPose);
        m_size = this->mPose->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
        if ( m_size > 0 )
        {
          v30 = 0i64;
          v27.m128_f32[0] = 1.0 / mBoneScale;
          v31 = _mm_shuffle_ps(v27, v27, 0);
          do
          {
            ++v30;
            v28->m_data[v30 - 1].m_translation.m_quad = _mm_mul_ps(v28->m_data[v30 - 1].m_translation.m_quad, v31);
            --m_size;
          }
          while ( m_size );
        }
      }
      if ( this->mMaterialModifier.mNumOverrides )
        view->mSubmitContext->mMaterialModifier = &this->mMaterialModifier;
      mNext = (ModelType::ModelBindingSkin *)v10->mModelBindingSkinTable.mNode.mNext;
      if ( mNext != (ModelType::ModelBindingSkin *)&v10->mModelBindingSkinTable )
      {
        do
        {
          v33 = (ModelType::ModelBindingSkin *)mNext->mNext;
          UFG::CompositeDrawableComponent::DrawSkin(this, view, mNext, &local_matrix, this->mPose, 0xFFFFFFFF);
          mNext = v33;
        }
        while ( v33 != (ModelType::ModelBindingSkin *)&v10->mModelBindingSkinTable );
      }
      v34 = (ModelType::ModelBindingRigid *)v10->mModelBindingRigidTable.mNode.mNext;
      if ( v34 != (ModelType::ModelBindingRigid *)&v10->mModelBindingRigidTable )
      {
        do
        {
          v35 = (ModelType::ModelBindingRigid *)v34->mNext;
          UFG::CompositeDrawableComponent::DrawRigid(this, view, v34, &local_matrix, this->mPose);
          v34 = v35;
        }
        while ( v35 != (ModelType::ModelBindingRigid *)&v10->mModelBindingRigidTable );
      }
      if ( this->mMaterialModifier.mNumOverrides )
        view->mSubmitContext->mMaterialModifier = 0i64;
    }
    mCompositeLook = this->mCompositeLook;
    if ( mCompositeLook )
      mCompositeLook->vfptr->OnDraw(mCompositeLook, this, view, &local_matrix);
    v37 = UFG::qGetTicks();
    TickTime = UFG::qGetTickTime(v11, v37);
    Render::View::AddMetric_DrawComposite(view, TickTime);
  }
}

// File Line: 734
// RVA: 0x3040
void __fastcall UFG::CompositeDrawableComponent::Draw(UFG::CompositeDrawableComponent *this, Render::View *view)
{
  CullResults *mCullResults; // rdx
  UFG::ICompositeLook *mCompositeLook; // rcx
  __int64 mCullIndex; // rcx
  float v7; // xmm1_4
  int LOD; // eax

  if ( gEnableCompositeDrawable && (UFG::Editor::GetDrawMode() || (UFG::Editor::GetDrawFlags() & 4) != 0) )
  {
    Render::View::AddMetric_NumCompositeProcessed(view, 1);
    if ( (this->m_Flags & 3) == 1 && !this->mIsHidden )
    {
      if ( this->mPose->mRigHandle.mData )
      {
        mCullResults = this->mCullResults;
        if ( mCullResults )
        {
          if ( view->mSettings->mCullIndex < 0 || mCullResults->mViewResult[view->mSettings->mCullIndex] <= 1u )
          {
            mCompositeLook = this->mCompositeLook;
            if ( !mCompositeLook || !mCompositeLook->vfptr->OnIsCulled(mCompositeLook, this, view) )
            {
              mCullIndex = view->mSettings->mCullIndex;
              if ( (int)mCullIndex >= 6 )
                v7 = *(float *)&FLOAT_1_0;
              else
                v7 = this->mCullResults->mPixelCoverage[mCullIndex];
              LOD = UFG::CompositeDrawableComponent::GetLOD(this, v7);
              UFG::CompositeDrawableComponent::Draw(this, view, LOD);
            }
          }
        }
      }
    }
  }
}

// File Line: 775
// RVA: 0x2CE0
ModelType *__fastcall UFG::CompositeDrawableComponent::CreateModelType(
        UFG::CompositeDrawableComponent *this,
        bool create_rig_bindings)
{
  UFG::RigResource *mData; // rdi
  char *v5; // rax
  ModelType *v6; // rax
  ModelType *v7; // r13
  unsigned int i; // ebx
  unsigned int v9; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *p_mModelBindingSkinTable; // rsi
  unsigned int v15; // r13d
  int v16; // ecx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *j; // rbx
  char *v18; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *v19; // rax
  UFG::qNode<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin> *mPrev; // rcx
  unsigned int v21; // r12d
  __int64 mNext_low; // r15
  UFG::qResourceHandle *v23; // r14
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  unsigned int k; // ebx
  unsigned int modelGuid; // r14d
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  UFG::qResourceInventory *v30; // rax
  UFG::qResourceWarehouse *v31; // rax
  Illusion::ModelProxy v32; // [rsp+38h] [rbp-28h] BYREF
  ModelType *v33; // [rsp+B0h] [rbp+50h]

  mData = (UFG::RigResource *)this->mRigHandle.mData;
  if ( !mData )
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
  v33 = v7;
  ModelType::SetRigHandle(v7, mData->mNode.mUID, mData);
  if ( create_rig_bindings )
  {
    for ( i = 0; i < mData->mNumSkins; ++i )
    {
      v9 = mData->mSkinGuids[i];
      UFG::qResourceHandle::qResourceHandle(&v32.mModelHandle);
      Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v11 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&v32.mModelHandle, 0xA2ADCD77, v9, Inventory);
      v32.mRModel = 0i64;
      ModelType::AddSkinModelBinding(v7, &v32, &UFG::qMatrix44::msIdentity, 0, 0);
      v12 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v13 = UFG::qResourceWarehouse::Instance();
        v12 = UFG::qResourceWarehouse::GetInventory(v13, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v12;
      }
      UFG::qResourceHandle::Close(&v32.mModelHandle, v12);
      UFG::qResourceHandle::~qResourceHandle(&v32.mModelHandle);
    }
    if ( mData->mNumSkinMorphs )
    {
      p_mModelBindingSkinTable = &v7->mModelBindingSkinTable;
      v15 = 0;
      do
      {
        v16 = mData->mSkinMorphBaseSkinID[v15];
        for ( j = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)p_mModelBindingSkinTable->mNode.mNext;
              v16 > 0;
              j = (UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *)j->mNode.mNext )
        {
          if ( j == p_mModelBindingSkinTable )
            break;
          --v16;
        }
        if ( !j[5].mNode.mPrev )
        {
          v18 = UFG::qMalloc(0x50ui64, "ModelDataBase::ModelType::MorphTargets", 0i64);
          if ( v18 )
            ModelType::SimpleMorphTargets::SimpleMorphTargets((ModelType::SimpleMorphTargets *)v18);
          else
            v19 = 0i64;
          j[5].mNode.mPrev = v19;
        }
        mPrev = j[5].mNode.mPrev;
        v21 = mData->mSkinMorphGuids[v15];
        mNext_low = LODWORD(mPrev[4].mNext);
        v23 = (UFG::qResourceHandle *)&mPrev[2 * mNext_low];
        v24 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
        if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
        {
          v25 = UFG::qResourceWarehouse::Instance();
          v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xA2ADCD77);
          `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v24;
        }
        UFG::qResourceHandle::Init(v23, 0xA2ADCD77, v21, v24);
        *((_DWORD *)&j[5].mNode.mPrev[4].mPrev + mNext_low) = 0;
        ++LODWORD(j[5].mNode.mPrev[4].mNext);
        ++v15;
      }
      while ( v15 < mData->mNumSkinMorphs );
      v7 = v33;
    }
    for ( k = 0; k < mData->mNumModelMap; ++k )
    {
      modelGuid = mData->mModelMap[k].modelGuid;
      UFG::qResourceHandle::qResourceHandle(&v32.mModelHandle);
      v28 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v29 = UFG::qResourceWarehouse::Instance();
        v28 = UFG::qResourceWarehouse::GetInventory(v29, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v28;
      }
      UFG::qResourceHandle::Init(&v32.mModelHandle, 0xA2ADCD77, modelGuid, v28);
      v32.mRModel = 0i64;
      ModelType::AddRigidModelBinding(v7, &v32, mData->mModelMap[k].boneIndex, &UFG::qMatrix44::msIdentity, 0);
      v30 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v31 = UFG::qResourceWarehouse::Instance();
        v30 = UFG::qResourceWarehouse::GetInventory(v31, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v30;
      }
      UFG::qResourceHandle::Close(&v32.mModelHandle, v30);
      UFG::qResourceHandle::~qResourceHandle(&v32.mModelHandle);
    }
  }
  return v7;
}

// File Line: 851
// RVA: 0x3B10
char __fastcall UFG::CompositeDrawableComponent::GetTransform(
        UFG::CompositeDrawableComponent *this,
        Render::Decal *decal,
        UFG::qMatrix44 *mat)
{
  __int64 v3; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **v4; // rax
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
    v4 = &this->mRigHandle.mNext + (unsigned int)v3;
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
  char *v3; // rbx
  char *p_mNext; // rbp
  __int64 v6; // rax
  __int64 v7; // r14
  float v8; // xmm1_4
  __int64 i; // rcx
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
  unsigned int v20; // ebx
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  Illusion::ModelProxy *v23; // rax
  Illusion::ModelProxy *mNext; // rbx
  ModelType::SkinnedDecalLayer *v25; // rcx
  UFG::qVector3 min; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 max; // [rsp+40h] [rbp-98h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+50h] [rbp-88h] BYREF
  __int64 v29; // [rsp+F8h] [rbp+20h]

  v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
  p_mNext = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext;
  if ( &UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList.mNode.mNext[-6].mNext != (UFG::qNode<UFG::CompositeDrawableComponent,UFG::CompositeDrawableComponent> **)((char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88) )
  {
    do
    {
      v6 = *((_QWORD *)p_mNext + 157);
      v7 = *((_QWORD *)p_mNext + 12) - 88i64;
      v29 = v7;
      if ( v6 )
      {
        v8 = *(float *)(v6 + 40);
        for ( i = 0i64;
              v8 < (float)(*((float *)p_mNext + 366) * UFG::CompositeDrawableComponent::msPixelCoverageToLOD[i]);
              i = (unsigned int)(i + 1) )
        {
          if ( (unsigned int)i >= 5 )
            break;
        }
        v10 = *((_DWORD *)p_mNext + 354) - 1;
        if ( (unsigned int)i >= v10 )
          i = v10;
        if ( (_DWORD)i )
        {
          v11 = &p_mNext[8 * i + 1424];
          do
          {
            if ( *(_QWORD *)v11 )
              break;
            v11 -= 8;
            LODWORD(i) = i - 1;
          }
          while ( (_DWORD)i );
        }
        if ( (p_mNext[32] & 3) == 1 && !(_DWORD)i && !p_mNext[1240] )
        {
          if ( *(_QWORD *)(*((_QWORD *)p_mNext + 168) + 200i64) )
          {
            v12 = *((_QWORD *)p_mNext + 178);
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
              TransformAABB((UFG::qMatrix44 *)p_mNext + 20, &min, &max);
              if ( min.x <= projBox->mMax.x
                && max.x >= projBox->mMin.x
                && min.y <= projBox->mMax.y
                && max.y >= projBox->mMin.y
                && min.z <= projBox->mMax.z
                && max.z >= projBox->mMin.z )
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
                      SkeletalPose::GetPositionWS(*((SkeletalPose **)p_mNext + 168), v20, &matrixWS);
                      Illusion::ModelProxy::operator=(&request->mModelProxy, (Illusion::ModelProxy *)(v18 + 24));
                      v21 = matrixWS.v2;
                      request->mLocalToWorld.v0 = matrixWS.v0;
                      request->mLocalToWorld.v1 = matrixWS.v1;
                      v22 = matrixWS.v3;
                      request->mLocalToWorld.v2 = v21;
                      request->mLocalToWorld.v3 = v22;
                      UFG::qSafePointer<Creature,Creature>::operator=(
                        &request->mComponentPtr,
                        (UFG::SimComponent *)p_mNext);
                      request->mScenery = (Render::IDecalScenery *)(p_mNext + 64);
                      request->mBindIndex = v20;
                      Render::DecalManager::AddClipQueue(&Render::gDecalManager, request);
                    }
                    v18 = v19;
                  }
                  while ( v19 != v12 + 96 );
                  v7 = v29;
                  v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
                }
                if ( request->mRadius <= 0.039999999 )
                {
                  SkeletalPose::GetPositionWS(*((SkeletalPose **)p_mNext + 168), 0, &matrixWS);
                  v23 = *(Illusion::ModelProxy **)(v12 + 88);
                  if ( v23 != (Illusion::ModelProxy *)(v12 + 80) )
                  {
                    do
                    {
                      mNext = (Illusion::ModelProxy *)v23->mModelHandle.mNext;
                      if ( v23[1].mModelHandle.mData || v23[1].mRModel )
                      {
                        v25 = (ModelType::SkinnedDecalLayer *)v23[2].mModelHandle.mNext;
                        if ( v25 )
                          ModelType::SkinnedDecalLayer::CreateDecal(
                            v25,
                            &request->mMatrix,
                            &matrixWS,
                            request->mRadius,
                            (Render::DecalSettings *)request->mSettingsHandle.mData,
                            v23 + 1);
                      }
                      v23 = mNext;
                    }
                    while ( mNext != (Illusion::ModelProxy *)(v12 + 80) );
                    v3 = (char *)&UFG::CompositeDrawableComponent::s_CompositeDrawableComponentList - 88;
                  }
                }
              }
            }
          }
        }
      }
      p_mNext = (char *)v7;
    }
    while ( (char *)v7 != v3 );
  }
}

