// File Line: 53
// RVA: 0x154D9C0
__int64 dynamic_initializer_for__UFG::BaseAnimationComponent::s_BaseAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BaseAnimationComponent::s_BaseAnimationComponentList__);
}

// File Line: 54
// RVA: 0x5825C0
UFG::ComponentIDDesc *__fastcall UFG::BaseAnimationComponent::GetDesc(UFG::BaseAnimationComponent *this)
{
  return &UFG::BaseAnimationComponent::_TypeIDesc;
}

// File Line: 67
// RVA: 0x57C5B0
void __fastcall UFG::BaseAnimationComponent::BaseAnimationComponent(
        UFG::BaseAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_BaseAnimation *dataPtr)
{
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->mNext = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  this->mRigHandle.mUFGSkeleton = 0i64;
  this->mRigInstance = 0i64;
  this->mCreature = 0i64;
  *(_WORD *)&this->mUpdatedWithResources = 0;
  this->mTransformsUpdated = 0;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  this->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  *(_WORD *)&this->mDestroyAttachedCharacters = 1;
  this->mCurrentRigUID = -1;
  mPrev = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID,
    "BaseAnimationComponent");
  if ( pSceneObj )
  {
    UFG::BaseAnimationComponent::bindRequiredAnimBanks(this, pSceneObj, dataPtr);
    this->mDestroyAttachedCharacters = dataPtr->DestroyAttachedCharacters;
  }
}

// File Line: 89
// RVA: 0x57C480
void __fastcall UFG::BaseAnimationComponent::BaseAnimationComponent(
        UFG::BaseAnimationComponent *this,
        UFG::RigResource *rig)
{
  Creature *v4; // rbp
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *mPrev; // rax
  UFG::allocator::free_link *v6; // rax
  Creature *v7; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->mNext = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mRigHandle);
  v4 = 0i64;
  this->mRigHandle.mLoadFunction = 0i64;
  this->mRigHandle.mUnloadFunction = 0i64;
  this->mRigHandle.mUserData = 0i64;
  this->mRigHandle.mUFGSkeleton = 0i64;
  this->mRigInstance = 0i64;
  this->mCreature = 0i64;
  *(_WORD *)&this->mUpdatedWithResources = 0;
  this->mTransformsUpdated = 0;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  this->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  *(_WORD *)&this->mDestroyAttachedCharacters = 1;
  this->mCurrentRigUID = -1;
  mPrev = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID,
    "BaseAnimationComponent");
  if ( rig )
  {
    v6 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
    if ( v6 )
    {
      Creature::Creature((Creature *)v6, rig);
      v4 = v7;
    }
    this->mCreature = v4;
    this->mCurrentRigUID = rig->mNode.mUID;
  }
}

// File Line: 100
// RVA: 0x57D5F0
void __fastcall UFG::BaseAnimationComponent::~BaseAnimationComponent(UFG::BaseAnimationComponent *this)
{
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v2; // rsi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *mPrev; // rcx
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *mNext; // rax
  Creature *mCreature; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v10; // rcx
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable;
  if ( this == UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator )
    UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mCreature = this->mCreature;
  if ( mCreature )
    Creature::Destroy(mCreature);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  v6 = this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev;
  v7 = this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext = &this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mRigHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mRigHandle);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 109
// RVA: 0x5860F0
void __fastcall UFG::BaseAnimationComponent::OnAttach(UFG::BaseAnimationComponent *this, UFG::SimObjectGame *object)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v6; // rax
  component_BaseAnimation *MemImagePtr; // rax
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObjectGame *v10; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v13; // rax
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mCurrentRigUID; // esi
  UFG::qResourceWarehouse *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  __int16 v18; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SceneObjectProperties *v20; // rdi
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v22; // rax
  UFG::RigResource *mData; // r8

  if ( this->mCreature )
  {
    m_pSceneObj = object->m_pSceneObj;
    if ( m_pSceneObj )
    {
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
      v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&component_BaseAnimation::sPropertyName,
             DEPTH_RECURSE);
      if ( v6 )
      {
        MemImagePtr = (component_BaseAnimation *)UFG::qPropertySet::GetMemImagePtr(v6);
        if ( MemImagePtr )
          UFG::BaseAnimationComponent::bindRequiredAnimBanks(this, m_pSceneObj, MemImagePtr);
      }
    }
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        Creature::SetTransformNodeComponentRoot(this->mCreature, m_pTransformNodeComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        Creature::SetTransform(this->mCreature, &m_pTransformNodeComponent->mWorldTransform);
      }
    }
    v10 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v10 )
    {
      m_Flags = v10->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v10->m_Components.p[14].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = v10->m_Components.p[9].m_pComponent;
        }
        else
        {
          v13 = (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::CompositeDrawableComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v10, UFG::CompositeDrawableComponent::_TypeUID);
          m_pComponent = v13;
        }
      }
      else
      {
        m_pComponent = v10->m_Components.p[14].m_pComponent;
      }
      if ( m_pComponent )
      {
        m_pComponent[21].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&this->mCreature->mPose;
        Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
        mCurrentRigUID = this->mCurrentRigUID;
        if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
        {
          v16 = UFG::qResourceWarehouse::Instance();
          Inventory = UFG::qResourceWarehouse::GetInventory(v16, 0x39BC0A7Eu);
          `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
        }
        UFG::qResourceHandle::Init(
          (UFG::qResourceHandle *)&m_pComponent[21].m_SafePointerList,
          0x39BC0A7Eu,
          mCurrentRigUID,
          Inventory);
      }
    }
    v17 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v17 )
    {
      v18 = v17->m_Flags;
      if ( (v18 & 0x4000) != 0 || v18 < 0 || (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v17, Render::FXSimComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v17, Render::FXSimComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        *(_QWORD *)&ComponentOfTypeHK[1].m_Flags = &this->mCreature->mPose;
    }
  }
  else
  {
    this->mCurrentRigUID = -1;
    v20 = object->m_pSceneObj;
    if ( v20 )
    {
      mpConstProperties = v20->mpWritableProperties;
      if ( mpConstProperties || (mpConstProperties = v20->mpConstProperties) != 0i64 )
      {
        v22 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                mpConstProperties,
                (UFG::qArray<unsigned long,0> *)&component_BaseAnimation::sPropertyName,
                DEPTH_RECURSE);
        if ( v22 )
          v22 = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(v22);
        UFG::BaseAnimationComponent::InitPropertySetInfo(this, v20, (component_BaseAnimation *)v22);
      }
    }
    mData = (UFG::RigResource *)this->mRigHandle.mData;
    if ( mData )
      UFG::PhysicsSystem::AddPhysicsComponents((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, object, mData);
    this->mUpdatedFromNIS = 0;
  }
}

// File Line: 174
// RVA: 0x586A30
void __fastcall UFG::BaseAnimationComponent::OnDetach(UFG::BaseAnimationComponent *this)
{
  Creature *mCreature; // rcx

  UFG::PhysicsSystem::RemovePhysicsComponents(
    (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
    this->m_pSimObject);
  mCreature = this->mCreature;
  if ( mCreature )
  {
    Creature::DestroyAllAttachments(mCreature, this->m_pSimObject, !this->mDestroyAttachedCharacters);
    Creature::KillBlendTree(this->mCreature);
  }
  UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(this);
}

// File Line: 192
// RVA: 0x58C8F0
void __fastcall UFG::BaseAnimationComponent::Suspend(UFG::BaseAnimationComponent *this)
{
  unsigned __int16 m_Flags; // dx

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) == 0 )
    this->m_Flags = m_Flags | 2;
}

// File Line: 201
// RVA: 0x58B4F0
void __fastcall UFG::BaseAnimationComponent::Restore(UFG::BaseAnimationComponent *this)
{
  unsigned __int16 m_Flags; // dx

  m_Flags = this->m_Flags;
  if ( (m_Flags & 2) != 0 )
    this->m_Flags = m_Flags & 0xFFFD;
}

// File Line: 210
// RVA: 0x5918D0
void __fastcall UFG::BaseAnimationComponent::UpdateTransforms(UFG::BaseAnimationComponent *this)
{
  if ( (this->m_Flags & 3) == 1 && !this->mTransformsUpdated )
  {
    Creature::UpdateTransforms(this->mCreature);
    this->mTransformsUpdated = 1;
  }
}

// File Line: 233
// RVA: 0x588630
AnimationNode *__fastcall UFG::BaseAnimationComponent::PlayAnimation(
        UFG::BaseAnimationComponent *this,
        UFG::qSymbolUC *animName,
        float startTime)
{
  Creature *mCreature; // rcx
  int returnCode; // [rsp+50h] [rbp+8h] BYREF

  mCreature = this->mCreature;
  returnCode = 0;
  if ( mCreature )
    return (AnimationNode *)Creature::PlayAnimation(
                              mCreature,
                              animName,
                              APM_CYCLIC,
                              startTime,
                              -1.0,
                              0.0,
                              0,
                              &returnCode);
  else
    return 0i64;
}

// File Line: 261
// RVA: 0x58D4F0
void __fastcall UFG::BaseAnimationComponent::Update(UFG::BaseAnimationComponent *this, float delta_sec)
{
  __int64 v3; // r8
  Creature *mCreature; // rcx

  UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
  if ( !this->mUpdatedFromNIS )
  {
    if ( !this->mUpdatedWithResources )
    {
      if ( !UFG::BaseAnimationComponent::AreResourcesAvailable(this) )
        return;
      this->mUpdatedWithResources = 1;
    }
    mCreature = this->mCreature;
    if ( mCreature )
    {
      Creature::Update(mCreature, delta_sec, v3);
      Creature::SubmitPoseTask(this->mCreature);
    }
    this->mTransformsUpdated = 0;
  }
}

// File Line: 293
// RVA: 0x58DA30
void __fastcall UFG::BaseAnimationComponent::UpdateAll(float delta_sec)
{
  unsigned __int64 Ticks; // rdi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  Ticks = UFG::qGetTicks();
  v2 = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext - 4;
  for ( UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)(&UFG::BaseAnimationComponent::s_BaseAnimationComponentList
                                                                                    - 4);
        UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)v2 )
  {
    if ( ((__int64)v2[2].mPrev & 3) == 1 )
    {
      ((void (__fastcall *)(UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *))v2->mPrev[7].mNext)(v2);
      v2 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(Ticks, v3);
}

// File Line: 341
// RVA: 0x58BA50
void __fastcall UFG::BaseAnimationComponent::SetUpdateFromNIS(UFG::BaseAnimationComponent *this, bool nisControl)
{
  this->mUpdatedFromNIS = nisControl;
}

// File Line: 346
// RVA: 0x5909E0
void __fastcall UFG::BaseAnimationComponent::UpdateNIS(UFG::BaseAnimationComponent *this, float delta_sec, __int64 a3)
{
  Creature *mCreature; // rcx

  mCreature = this->mCreature;
  if ( mCreature )
  {
    Creature::Update(mCreature, delta_sec, a3);
    Creature::SubmitPoseTask(this->mCreature);
  }
  this->mTransformsUpdated = 0;
}

// File Line: 373
// RVA: 0x58B220
void __fastcall UFG::BaseAnimationComponent::Reset(UFG::BaseAnimationComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *v3; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v6; // rax
  component_BaseAnimation *MemImagePtr; // rsi
  UFG::SimObject *v8; // rax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::SimObject *v10; // rax

  Creature::KillBlendTree(this->mCreature);
  Creature::Destroy(this->mCreature);
  m_pSimObject = this->m_pSimObject;
  v3 = 0i64;
  this->mCreature = 0i64;
  *(_WORD *)&this->mUpdatedWithResources = 0;
  this->mTransformsUpdated = 0;
  this->mTemporaryRig = 0;
  this->mCurrentRigUID = -1;
  if ( !m_pSimObject || (m_pSceneObj = m_pSimObject->m_pSceneObj) == 0i64 )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      goto LABEL_16;
    goto LABEL_7;
  }
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_BaseAnimation::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
    MemImagePtr = (component_BaseAnimation *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  v8 = this->m_pSimObject;
  if ( v8 )
    v9 = v8->m_pSceneObj;
  else
    v9 = 0i64;
  UFG::BaseAnimationComponent::bindRequiredAnimBanks(this, v9, MemImagePtr);
  v10 = this->m_pSimObject;
  if ( v10 )
    v3 = v10->m_pSceneObj;
  UFG::BaseAnimationComponent::InitPropertySetInfo(this, v3, MemImagePtr);
LABEL_16:
  this->m_Flags &= 0xFFFDu;
}

// File Line: 401
// RVA: 0x58AF10
void __fastcall UFG::BaseAnimationComponent::RebindRequiredAnimationBanks(UFG::BaseAnimationComponent *this)
{
  Creature **p_mCreature; // rdi
  AnimationGroupHandle *v2; // rbx

  p_mCreature = &this->mCreature;
  v2 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v2 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( !v2->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v2);
      v2 = (AnimationGroupHandle *)&v2->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v2 != (AnimationGroupHandle *)p_mCreature );
  }
}

// File Line: 406
// RVA: 0x58D300
void __fastcall UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(UFG::BaseAnimationComponent *this)
{
  Creature **p_mCreature; // rsi
  AnimationGroupHandle *v2; // rbx

  this->mUpdatedWithResources = 1;
  p_mCreature = &this->mCreature;
  v2 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v2 == (AnimationGroupHandle *)&this->mCreature )
  {
    this->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  }
  else
  {
    do
    {
      AnimationGroupHandle::Unbind(v2);
      v2 = (AnimationGroupHandle *)&v2->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v2 != (AnimationGroupHandle *)p_mCreature );
    this->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  }
}

// File Line: 421
// RVA: 0x58AF60
void __fastcall UFG::BaseAnimationComponent::RebindResources(UFG::BaseAnimationComponent *this)
{
  Creature **p_mCreature; // rdi
  AnimationGroupHandle *v3; // rbx

  p_mCreature = &this->mCreature;
  v3 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v3 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( !v3->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v3);
      v3 = (AnimationGroupHandle *)&v3->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)p_mCreature );
  }
  Creature::RebindResources(this->mCreature);
}

// File Line: 427
// RVA: 0x57F310
char __fastcall UFG::BaseAnimationComponent::AreResourcesAvailable(UFG::BaseAnimationComponent *this)
{
  Creature **p_mCreature; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rbx
  AnimationGroup *mNext; // rcx

  p_mCreature = &this->mCreature;
  v2 = this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext - 1;
  if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mCreature )
    return 1;
  while ( 1 )
  {
    if ( LOWORD(v2[4].mPrev) > 2u )
    {
      mNext = (AnimationGroup *)v2[3].mNext;
      if ( !mNext || !AnimationGroup::IsStreamedIn(mNext) )
        break;
    }
    v2 = v2[1].mNext - 1;
    if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)p_mCreature )
      return 1;
  }
  return 0;
}

// File Line: 433
// RVA: 0x58B790
void __fastcall UFG::BaseAnimationComponent::SetAnimationBankPriority(
        UFG::BaseAnimationComponent *this,
        UFG::qSymbolUC *theAnimationGroupSymbol,
        UFG::eAnimationPriorityEnum eAnimationPriority)
{
  Creature **p_mCreature; // rdi
  AnimationGroupHandle *v5; // rbx

  p_mCreature = &this->mCreature;
  v5 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v5 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( v5->m_AnimationGroupSymbol.mUID == theAnimationGroupSymbol->mUID )
        AnimationGroupHandle::SetAnimationPriority(v5, eAnimationPriority, 0);
      v5 = (AnimationGroupHandle *)&v5->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
    }
    while ( v5 != (AnimationGroupHandle *)p_mCreature );
  }
}

// File Line: 442
// RVA: 0x583870
void __fastcall UFG::BaseAnimationComponent::InitPropertySetInfo(
        UFG::BaseAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_BaseAnimation *dataPtr)
{
  __int64 mOffset; // rax
  Creature *v7; // r14
  const char *v8; // rdi
  __int64 v9; // rax
  const char *v10; // rbp
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int64 v14; // rax
  const char *v15; // rax
  __int64 v16; // rcx
  UFG::qSymbolUC *ArchetypePropertiesName; // rax
  char *v18; // rax
  unsigned int v19; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::RigResource *mData; // rdi
  UFG::SimObjectGame *v23; // rcx
  __int16 v24; // dx
  UFG::SimComponent *v25; // rax
  UFG::allocator::free_link *v26; // rax
  Creature *v27; // rax
  UFG::SimObject *v28; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObjectGame *v30; // rcx
  __int16 v31; // dx
  UFG::CompositeDrawableComponent *v32; // rcx
  UFG::SimComponent *v33; // rax
  UFG::SimObjectGame *v34; // rcx
  __int16 v35; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSymbolUC poseDriverSet; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v38; // [rsp+70h] [rbp+18h]

  mOffset = dataPtr->RigName.mOffset;
  v7 = 0i64;
  if ( mOffset )
    v8 = (char *)&dataPtr->RigName + mOffset;
  else
    v8 = 0i64;
  v9 = dataPtr->WeightSetFileName.mOffset;
  if ( v9 )
    v10 = (char *)&dataPtr->WeightSetFileName + v9;
  else
    v10 = 0i64;
  poseDriverSet.mUID = dataPtr->PoseDriverSet.mUID;
  if ( pSceneObj )
  {
    m_pSimObject = (UFG::SimObjectGame *)pSceneObj->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
        else
          m_pComponent = (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                           m_pSimObject,
                           UFG::StreamedResourceComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pSimObject->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent && LOBYTE(m_pComponent[1].m_TypeUID) )
      {
        v14 = dataPtr->RigNameHD.mOffset;
        if ( v14 && (v15 = (char *)&dataPtr->RigNameHD + v14) != 0i64 && *v15 )
        {
          v16 = dataPtr->WeightSetFileNameHD.mOffset;
          if ( v16 )
            v10 = (char *)&dataPtr->WeightSetFileNameHD + v16;
          else
            v10 = 0i64;
          v8 = v15;
        }
        else
        {
          ArchetypePropertiesName = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(pSceneObj);
          v18 = UFG::qSymbol::as_cstr_dbg(ArchetypePropertiesName);
          UFG::qPrintf(
            "BaseAnimationComponent::InitPropertySetInfo(): Requesting an HD character, but there is no RigNameHD propert"
            "y set in PropertySet %s\n",
            v18);
        }
      }
    }
  }
  if ( v8 && *v8 )
  {
    v19 = UFG::qStringHashUpper32(v8, -1);
    this->mCurrentRigUID = v19;
    Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
    {
      v21 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0x39BC0A7Eu);
      `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mRigHandle, 0x39BC0A7Eu, v19, Inventory);
    mData = (UFG::RigResource *)this->mRigHandle.mData;
    this->mTemporaryRig = 0;
    if ( !mData )
    {
      v23 = (UFG::SimObjectGame *)pSceneObj->m_pSimObject;
      if ( v23 )
      {
        v24 = v23->m_Flags;
        if ( (v24 & 0x4000) != 0 )
        {
          v25 = v23->m_Components.p[3].m_pComponent;
        }
        else if ( v24 >= 0 )
        {
          if ( (v24 & 0x2000) != 0 )
            v25 = v23->m_Components.p[4].m_pComponent;
          else
            v25 = (v24 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::SimObjectPropertiesComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v23, UFG::SimObjectPropertiesComponent::_TypeUID);
        }
        else
        {
          v25 = v23->m_Components.p[3].m_pComponent;
        }
        if ( v25 && LODWORD(v25[1].m_SafePointerList.mNode.mNext) == 4 )
        {
          this->mCurrentRigUID = qSymbolX_defaultVehicleRig.mUID;
          UFG::qTypedResourceHandle<968624766,UFG::RigResource>::Init(
            &this->mRigHandle,
            qSymbolX_defaultVehicleRig.mUID);
          mData = (UFG::RigResource *)this->mRigHandle.mData;
          this->mTemporaryRig = 1;
        }
      }
    }
    UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
    if ( mData )
    {
      v26 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
      v38 = v26;
      if ( v26 )
      {
        Creature::Creature((Creature *)v26, mData);
        v7 = v27;
      }
      this->mCreature = v7;
      if ( v10 && *v10 )
        Creature::InitWeightSet(v7, v10);
      Creature::BuildPoseDriver(this->mCreature, &poseDriverSet);
      v28 = this->m_pSimObject;
      if ( v28 )
      {
        m_pTransformNodeComponent = v28->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          Creature::SetTransformNodeComponentRoot(this->mCreature, m_pTransformNodeComponent);
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          Creature::SetTransform(this->mCreature, &m_pTransformNodeComponent->mWorldTransform);
        }
      }
      v30 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v30 )
      {
        v31 = v30->m_Flags;
        if ( (v31 & 0x4000) != 0 )
        {
          v32 = (UFG::CompositeDrawableComponent *)v30->m_Components.p[14].m_pComponent;
        }
        else if ( v31 >= 0 )
        {
          if ( (v31 & 0x2000) != 0 )
          {
            v32 = (UFG::CompositeDrawableComponent *)v30->m_Components.p[9].m_pComponent;
          }
          else
          {
            v33 = (v31 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v30, UFG::CompositeDrawableComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v30, UFG::CompositeDrawableComponent::_TypeUID);
            v32 = (UFG::CompositeDrawableComponent *)v33;
          }
        }
        else
        {
          v32 = (UFG::CompositeDrawableComponent *)v30->m_Components.p[14].m_pComponent;
        }
        if ( v32 )
        {
          v32->mPose = &this->mCreature->mPose;
          UFG::CompositeDrawableComponent::SetRig(v32, this->mCurrentRigUID);
        }
      }
      v34 = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( v34 )
      {
        v35 = v34->m_Flags;
        if ( (v35 & 0x4000) != 0 || v35 < 0 || (v35 & 0x2000) != 0 || (v35 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v34, Render::FXSimComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v34, Render::FXSimComponent::_TypeUID);
        if ( ComponentOfTypeHK )
          *(_QWORD *)&ComponentOfTypeHK[1].m_Flags = &this->mCreature->mPose;
      }
    }
    UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
  }
}
    UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
  }
}

// File Line: 541
// RVA: 0x591CA0
void __fastcall UFG::BaseAnimationComponent::bindRequiredAnimBanks(
        UFG::BaseAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        component_BaseAnimation *dataPtr)
{
  AnimationGroupHandleContainer *p_mRequiredAnimationBanks; // rbp
  __int64 mOffset; // rax
  UFG::qPropertyList *v6; // rsi
  unsigned int mNumElements; // edi
  unsigned int i; // ebx
  UFG::qSymbolUC *v9; // rax
  AnimationGroupHandle *v10; // rbx
  bool v11; // di
  char v12; // al

  p_mRequiredAnimationBanks = &this->mRequiredAnimationBanks;
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  if ( dataPtr )
  {
    mOffset = dataPtr->RequiredAnimBanks.mOffset;
    if ( mOffset )
    {
      v6 = (UFG::qPropertyList *)((char *)&dataPtr->RequiredAnimBanks + mOffset);
      if ( v6 )
      {
        mNumElements = v6->mNumElements;
        for ( i = 0; i < mNumElements; ++i )
        {
          v9 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v6, i);
          if ( v9 )
            AnimationGroupHandleContainer::Add(p_mRequiredAnimationBanks, v9, eANIM_PRIORITY_REQUIRED);
        }
      }
    }
    v10 = (AnimationGroupHandle *)&p_mRequiredAnimationBanks->m_AnimationGroupHandleList.mNode.mNext[-1];
    if ( v10 != (AnimationGroupHandle *)&p_mRequiredAnimationBanks[-1].m_AnimationGroupHandleList.mNode.mNext )
    {
      v11 = 1;
      do
      {
        v12 = AnimationGroupHandle::Bind(v10);
        v11 = v11 && v12;
        v10 = (AnimationGroupHandle *)&v10->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext[-1];
      }
      while ( v10 != (AnimationGroupHandle *)&p_mRequiredAnimationBanks[-1].m_AnimationGroupHandleList.mNode.mNext );
      p_mRequiredAnimationBanks->m_bHasBeenBound = 1;
    }
  }
}

// File Line: 576
// RVA: 0x591D70
void __fastcall UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(
        UFG::BaseAnimationComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rdi
  __int16 m_Flags; // dx
  UFG::ActionTreeComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // rax
  bool mTemporaryRig; // cl
  __int16 v7; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::ActionTreeComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::ActionTreeComponent *)m_pSimObject->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = (UFG::ActionTreeComponent *)v5;
      }
    }
    else
    {
      m_pComponent = (UFG::ActionTreeComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      mTemporaryRig = this->mTemporaryRig;
      if ( !mTemporaryRig && this->mCreature || (m_pComponent->m_Flags & 2) != 0 )
      {
        if ( !mTemporaryRig && this->mCreature && (m_pComponent->m_Flags & 2) != 0 )
        {
          v7 = m_pSimObject->m_Flags;
          if ( (v7 & 0x4000) != 0 || v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::PowerManagementComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::PowerManagementComponent::_TypeUID);
          if ( !ComponentOfTypeHK || !LODWORD(ComponentOfTypeHK[1].m_pSimObject) )
            ((void (__fastcall *)(UFG::ActionTreeComponent *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[9].__vecDelDtor)(m_pComponent);
        }
      }
      else
      {
        UFG::ActionTreeComponent::Reset(m_pComponent);
        ((void (__fastcall *)(UFG::ActionTreeComponent *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[8].__vecDelDtor)(m_pComponent);
      }
    }
  }
}

// File Line: 631
// RVA: 0x585F60
void __fastcall UFG::BaseAnimationComponent::NotifyProxyModeChanged(
        UFG::BaseAnimationComponent *this,
        UFG::SimObject::eProxyMode proxyMode)
{
  Creature *mCreature; // r8

  mCreature = this->mCreature;
  if ( mCreature )
    mCreature->mNetworkLock = proxyMode == ePM_PROXY_REMOTE_PHYSICS;
}

