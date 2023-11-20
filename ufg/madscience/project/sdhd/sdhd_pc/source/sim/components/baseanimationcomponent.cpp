// File Line: 53
// RVA: 0x154D9C0
__int64 dynamic_initializer_for__UFG::BaseAnimationComponent::s_BaseAnimationComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BaseAnimationComponent::s_BaseAnimationComponentList__);
}

// File Line: 54
// RVA: 0x5825C0
UFG::ComponentIDDesc *__fastcall UFG::BaseAnimationComponent::GetDesc(UFG::BaseAnimationComponent *this)
{
  return &UFG::BaseAnimationComponent::_TypeIDesc;
}

// File Line: 67
// RVA: 0x57C5B0
void __fastcall UFG::BaseAnimationComponent::BaseAnimationComponent(UFG::BaseAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj, component_BaseAnimation *dataPtr)
{
  component_BaseAnimation *v3; // r14
  UFG::SceneObjectProperties *v4; // rbp
  UFG::BaseAnimationComponent *v5; // rsi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v6; // rdi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v7; // rax
  AnimationGroupHandleContainer *v8; // [rsp+68h] [rbp+10h]

  v3 = dataPtr;
  v4 = pSceneObj;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v6 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v5->mRigHandle.mPrev);
  v5->mRigHandle.mLoadFunction = 0i64;
  v5->mRigHandle.mUnloadFunction = 0i64;
  v5->mRigHandle.mUserData = 0i64;
  v5->mRigHandle.mUFGSkeleton = 0i64;
  v5->mRigInstance = 0i64;
  v5->mCreature = 0i64;
  *(_WORD *)&v5->mUpdatedWithResources = 0;
  v5->mTransformsUpdated = 0;
  v8 = &v5->mRequiredAnimationBanks;
  v8->m_AnimationGroupHandleList.mNode.mPrev = &v8->m_AnimationGroupHandleList.mNode;
  v8->m_AnimationGroupHandleList.mNode.mNext = &v8->m_AnimationGroupHandleList.mNode;
  v5->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  *(_WORD *)&v5->mDestroyAttachedCharacters = 1;
  v5->mCurrentRigUID = -1;
  v7 = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v5->mPrev;
  v6->mPrev = v7;
  v5->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID,
    "BaseAnimationComponent");
  if ( v4 )
  {
    UFG::BaseAnimationComponent::bindRequiredAnimBanks(v5, v4, v3);
    v5->mDestroyAttachedCharacters = v3->DestroyAttachedCharacters;
  }
}

// File Line: 89
// RVA: 0x57C480
void __fastcall UFG::BaseAnimationComponent::BaseAnimationComponent(UFG::BaseAnimationComponent *this, UFG::RigResource *rig)
{
  UFG::RigResource *v2; // r14
  UFG::BaseAnimationComponent *v3; // rsi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v4; // rdi
  Creature *v5; // rbp
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v6; // rax
  UFG::allocator::free_link *v7; // rax
  Creature *v8; // rax
  AnimationGroupHandleContainer *v9; // [rsp+68h] [rbp+10h]

  v2 = rig;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v4 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable';
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRigHandle.mPrev);
  v5 = 0i64;
  v3->mRigHandle.mLoadFunction = 0i64;
  v3->mRigHandle.mUnloadFunction = 0i64;
  v3->mRigHandle.mUserData = 0i64;
  v3->mRigHandle.mUFGSkeleton = 0i64;
  v3->mRigInstance = 0i64;
  v3->mCreature = 0i64;
  *(_WORD *)&v3->mUpdatedWithResources = 0;
  v3->mTransformsUpdated = 0;
  v9 = &v3->mRequiredAnimationBanks;
  v9->m_AnimationGroupHandleList.mNode.mPrev = &v9->m_AnimationGroupHandleList.mNode;
  v9->m_AnimationGroupHandleList.mNode.mNext = &v9->m_AnimationGroupHandleList.mNode;
  v3->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  *(_WORD *)&v3->mDestroyAttachedCharacters = 1;
  v3->mCurrentRigUID = -1;
  v6 = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v3->mPrev;
  v4->mPrev = v6;
  v3->mNext = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList;
  UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mPrev = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::BaseAnimationComponent::_BaseAnimationComponentTypeUID,
    "BaseAnimationComponent");
  if ( v2 )
  {
    v7 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
    if ( v7 )
    {
      Creature::Creature((Creature *)v7, v2);
      v5 = v8;
    }
    v3->mCreature = v5;
    v3->mCurrentRigUID = v2->mNode.mUID;
  }
}

// File Line: 100
// RVA: 0x57D5F0
void __fastcall UFG::BaseAnimationComponent::~BaseAnimationComponent(UFG::BaseAnimationComponent *this)
{
  UFG::BaseAnimationComponent *v1; // rdi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v2; // rsi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v3; // rcx
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v4; // rax
  Creature *v5; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v10; // rcx
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BaseAnimationComponent::`vftable';
  if ( this == UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator )
    UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mCreature;
  if ( v5 )
    Creature::Destroy(v5);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  v6 = v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev;
  v7 = v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mPrev = &v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext = &v1->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode;
  v8 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mRigHandle.mPrev, v8);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mRigHandle.mPrev);
  v10 = v2->mPrev;
  v11 = v2->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 109
// RVA: 0x5860F0
void __fastcall UFG::BaseAnimationComponent::OnAttach(UFG::BaseAnimationComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rsi
  UFG::BaseAnimationComponent *v3; // rbx
  UFG::SceneObjectProperties *v4; // rdi
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  component_BaseAnimation *v7; // rax
  UFG::SimObject *v8; // rdi
  UFG::TransformNodeComponent *v9; // rdi
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rdi
  UFG::SimComponent *v13; // rax
  UFG::qResourceInventory *v14; // rax
  unsigned int v15; // esi
  UFG::qResourceWarehouse *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  Render::FXSimComponent *v19; // rax
  UFG::SceneObjectProperties *v20; // rdi
  UFG::qPropertySet *v21; // rcx
  UFG::qPropertySet *v22; // rax
  UFG::RigResource *v23; // r8

  v2 = object;
  v3 = this;
  if ( this->mCreature )
  {
    v4 = object->m_pSceneObj;
    if ( v4 )
    {
      v5 = v4->mpWritableProperties;
      if ( !v5 )
        v5 = v4->mpConstProperties;
      v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             v5,
             (UFG::qSymbol *)&component_BaseAnimation::sPropertyName.mUID,
             DEPTH_RECURSE);
      if ( v6 )
      {
        v7 = (component_BaseAnimation *)UFG::qPropertySet::GetMemImagePtr(v6);
        if ( v7 )
          UFG::BaseAnimationComponent::bindRequiredAnimBanks(v3, v4, v7);
      }
    }
    v8 = v3->m_pSimObject;
    if ( v8 )
    {
      v9 = v8->m_pTransformNodeComponent;
      if ( v9 )
      {
        Creature::SetTransformNodeComponentRoot(v3->mCreature, v9);
        UFG::TransformNodeComponent::UpdateWorldTransform(v9);
        Creature::SetTransform(v3->mCreature, &v9->mWorldTransform);
      }
    }
    v10 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v10 )
    {
      v11 = v10->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = v10->m_Components.p[14].m_pComponent;
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = v10->m_Components.p[9].m_pComponent;
        }
        else
        {
          v13 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v10,
                                    UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v10->vfptr,
                                                                                   UFG::CompositeDrawableComponent::_TypeUID);
          v12 = v13;
        }
      }
      else
      {
        v12 = v10->m_Components.p[14].m_pComponent;
      }
      if ( v12 )
      {
        v12[21].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v3->mCreature->mPose;
        v14 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
        v15 = v3->mCurrentRigUID;
        if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
        {
          v16 = UFG::qResourceWarehouse::Instance();
          v14 = UFG::qResourceWarehouse::GetInventory(v16, 0x39BC0A7Eu);
          `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v14;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v12[21].m_SafePointerList, 0x39BC0A7Eu, v15, v14);
      }
    }
    v17 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v17 )
    {
      v18 = v17->m_Flags;
      if ( (v18 >> 14) & 1 )
      {
        v19 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, Render::FXSimComponent::_TypeUID);
      }
      else if ( (v18 & 0x8000u) == 0 )
      {
        if ( (v18 >> 13) & 1 )
        {
          v19 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v17,
                                            Render::FXSimComponent::_TypeUID);
        }
        else if ( (v18 >> 12) & 1 )
        {
          v19 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v17,
                                            Render::FXSimComponent::_TypeUID);
        }
        else
        {
          v19 = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v17->vfptr,
                                            Render::FXSimComponent::_TypeUID);
        }
      }
      else
      {
        v19 = (Render::FXSimComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, Render::FXSimComponent::_TypeUID);
      }
      if ( v19 )
        v19->mPose = &v3->mCreature->mPose;
    }
  }
  else
  {
    this->mCurrentRigUID = -1;
    v20 = object->m_pSceneObj;
    if ( v20 )
    {
      v21 = v20->mpWritableProperties;
      if ( v21 || (v21 = v20->mpConstProperties) != 0i64 )
      {
        v22 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v21,
                (UFG::qSymbol *)&component_BaseAnimation::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v22 )
          v22 = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(v22);
        UFG::BaseAnimationComponent::InitPropertySetInfo(v3, v20, (component_BaseAnimation *)v22);
      }
    }
    v23 = (UFG::RigResource *)v3->mRigHandle.mData;
    if ( v23 )
      UFG::PhysicsSystem::AddPhysicsComponents((UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance, v2, v23);
    v3->mUpdatedFromNIS = 0;
  }
}

// File Line: 174
// RVA: 0x586A30
void __fastcall UFG::BaseAnimationComponent::OnDetach(UFG::BaseAnimationComponent *this)
{
  UFG::BaseAnimationComponent *v1; // rbx
  Creature *v2; // rcx

  v1 = this;
  UFG::PhysicsSystem::RemovePhysicsComponents(
    (UFG::PhysicsSystem *)UFG::BasePhysicsSystem::mInstance,
    this->m_pSimObject);
  v2 = v1->mCreature;
  if ( v2 )
  {
    Creature::DestroyAllAttachments(v2, v1->m_pSimObject, v1->mDestroyAttachedCharacters == 0);
    Creature::KillBlendTree(v1->mCreature);
  }
  UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(v1);
}

// File Line: 192
// RVA: 0x58C8F0
void __fastcall UFG::BaseAnimationComponent::Suspend(UFG::BaseAnimationComponent *this)
{
  unsigned __int16 v1; // dx

  v1 = this->m_Flags;
  if ( !(((unsigned __int8)v1 >> 1) & 1) )
    this->m_Flags = v1 | 2;
}

// File Line: 201
// RVA: 0x58B4F0
void __fastcall UFG::BaseAnimationComponent::Restore(UFG::BaseAnimationComponent *this)
{
  unsigned __int16 v1; // dx

  v1 = this->m_Flags;
  if ( ((unsigned __int8)v1 >> 1) & 1 )
    this->m_Flags = v1 & 0xFFFD;
}

// File Line: 210
// RVA: 0x5918D0
void __fastcall UFG::BaseAnimationComponent::UpdateTransforms(UFG::BaseAnimationComponent *this)
{
  UFG::BaseAnimationComponent *v1; // rbx

  v1 = this;
  if ( (this->m_Flags & 3) == 1 && !this->mTransformsUpdated )
  {
    Creature::UpdateTransforms(this->mCreature);
    v1->mTransformsUpdated = 1;
  }
}

// File Line: 233
// RVA: 0x588630
AnimationNode *__fastcall UFG::BaseAnimationComponent::PlayAnimation(UFG::BaseAnimationComponent *this, UFG::qSymbolUC *animName, float startTime)
{
  Creature *v3; // rcx
  AnimationNode *result; // rax
  int returnCode; // [rsp+50h] [rbp+8h]

  v3 = this->mCreature;
  returnCode = 0;
  if ( v3 )
    result = (AnimationNode *)Creature::PlayAnimation(v3, animName, APM_CYCLIC, startTime, -1.0, 0.0, 0, &returnCode);
  else
    result = 0i64;
  return result;
}

// File Line: 261
// RVA: 0x58D4F0
void __fastcall UFG::BaseAnimationComponent::Update(UFG::BaseAnimationComponent *this, float delta_sec)
{
  UFG::BaseAnimationComponent *v2; // rbx
  __int64 v3; // rdx
  __int64 v4; // r8
  Creature *v5; // rcx

  v2 = this;
  UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(this);
  if ( !v2->mUpdatedFromNIS )
  {
    if ( !v2->mUpdatedWithResources )
    {
      if ( !UFG::BaseAnimationComponent::AreResourcesAvailable(v2) )
        return;
      v2->mUpdatedWithResources = 1;
    }
    v5 = v2->mCreature;
    if ( v5 )
    {
      Creature::Update(v5, delta_sec, v3, v4);
      Creature::SubmitPoseTask(v2->mCreature);
    }
    v2->mTransformsUpdated = 0;
  }
}

// File Line: 293
// RVA: 0x58DA30
void __fastcall UFG::BaseAnimationComponent::UpdateAll(float delta_sec)
{
  unsigned __int64 v1; // rdi
  UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *v2; // rcx
  unsigned __int64 v3; // rax

  v1 = UFG::qGetTicks();
  v2 = UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext - 4;
  for ( UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)&UFG::BaseAnimationComponent::s_BaseAnimationComponentList.mNode.mNext[-4];
        v2 != (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)(&UFG::BaseAnimationComponent::s_BaseAnimationComponentList
                                                                                    - 4);
        UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = (UFG::BaseAnimationComponent *)v2 )
  {
    if ( ((_QWORD)v2[2].mPrev & 3) == 1 )
    {
      ((void (*)(void))v2->mPrev[7].mNext)();
      v2 = (UFG::qNode<UFG::BaseAnimationComponent,UFG::BaseAnimationComponent> *)UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator;
    }
    v2 = v2[4].mNext - 4;
  }
  UFG::BaseAnimationComponent::s_BaseAnimationComponentpCurrentIterator = 0i64;
  v3 = UFG::qGetTicks();
  UFG::gGameSimMetrics.mUpdateComponentsTiming = UFG::gGameSimMetrics.mUpdateComponentsTiming
                                               + UFG::qGetTickTime(v1, v3);
}

// File Line: 341
// RVA: 0x58BA50
void __fastcall UFG::BaseAnimationComponent::SetUpdateFromNIS(UFG::BaseAnimationComponent *this, bool nisControl)
{
  this->mUpdatedFromNIS = nisControl;
}

// File Line: 346
// RVA: 0x5909E0
void __usercall UFG::BaseAnimationComponent::UpdateNIS(UFG::BaseAnimationComponent *this@<rcx>, float delta_sec@<xmm1>, __int64 a3@<rdx>, __int64 a4@<r8>)
{
  UFG::BaseAnimationComponent *v4; // rbx
  Creature *v5; // rcx

  v4 = this;
  v5 = this->mCreature;
  if ( v5 )
  {
    Creature::Update(v5, delta_sec, a3, a4);
    Creature::SubmitPoseTask(v4->mCreature);
  }
  v4->mTransformsUpdated = 0;
}

// File Line: 373
// RVA: 0x58B220
void __fastcall UFG::BaseAnimationComponent::Reset(UFG::BaseAnimationComponent *this)
{
  UFG::BaseAnimationComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  UFG::SceneObjectProperties *v3; // rdi
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax
  component_BaseAnimation *v7; // rsi
  UFG::SimObject *v8; // rax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::SimObject *v10; // rax

  v1 = this;
  Creature::KillBlendTree(this->mCreature);
  Creature::Destroy(v1->mCreature);
  v2 = v1->m_pSimObject;
  v3 = 0i64;
  v1->mCreature = 0i64;
  *(_WORD *)&v1->mUpdatedWithResources = 0;
  v1->mTransformsUpdated = 0;
  v1->mTemporaryRig = 0;
  v1->mCurrentRigUID = -1;
  if ( !v2 || (v4 = v2->m_pSceneObj) == 0i64 )
  {
    v5 = 0i64;
LABEL_6:
    if ( !v5 )
      goto LABEL_16;
    goto LABEL_7;
  }
  v5 = v4->mpWritableProperties;
  if ( !v5 )
  {
    v5 = v4->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_BaseAnimation::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v7 = (component_BaseAnimation *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  v8 = v1->m_pSimObject;
  if ( v8 )
    v9 = v8->m_pSceneObj;
  else
    v9 = 0i64;
  UFG::BaseAnimationComponent::bindRequiredAnimBanks(v1, v9, v7);
  v10 = v1->m_pSimObject;
  if ( v10 )
    v3 = v10->m_pSceneObj;
  UFG::BaseAnimationComponent::InitPropertySetInfo(v1, v3, v7);
LABEL_16:
  v1->m_Flags &= 0xFFFDu;
}

// File Line: 401
// RVA: 0x58AF10
void __fastcall UFG::BaseAnimationComponent::RebindRequiredAnimationBanks(UFG::BaseAnimationComponent *this)
{
  Creature **v1; // rdi
  AnimationGroupHandle *v2; // rbx

  v1 = &this->mCreature;
  v2 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v2 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( !v2->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v2);
      v2 = (AnimationGroupHandle *)&v2->mNext[-1];
    }
    while ( v2 != (AnimationGroupHandle *)v1 );
  }
}

// File Line: 406
// RVA: 0x58D300
void __fastcall UFG::BaseAnimationComponent::UnbindRequiredAnimationBanks(UFG::BaseAnimationComponent *this)
{
  Creature **v1; // rsi
  AnimationGroupHandle *v2; // rbx
  UFG::BaseAnimationComponent *v3; // rdi

  this->mUpdatedWithResources = 1;
  v1 = &this->mCreature;
  v2 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  v3 = this;
  if ( v2 == (AnimationGroupHandle *)&this->mCreature )
  {
    this->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  }
  else
  {
    do
    {
      AnimationGroupHandle::Unbind(v2);
      v2 = (AnimationGroupHandle *)&v2->mNext[-1];
    }
    while ( v2 != (AnimationGroupHandle *)v1 );
    v3->mRequiredAnimationBanks.m_bHasBeenBound = 0;
  }
}

// File Line: 421
// RVA: 0x58AF60
void __fastcall UFG::BaseAnimationComponent::RebindResources(UFG::BaseAnimationComponent *this)
{
  Creature **v1; // rdi
  UFG::BaseAnimationComponent *v2; // rsi
  AnimationGroupHandle *v3; // rbx

  v1 = &this->mCreature;
  v2 = this;
  v3 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( v3 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( !v3->m_AnimationGroup.m_pPointer )
        AnimationGroupHandle::Bind(v3);
      v3 = (AnimationGroupHandle *)&v3->mNext[-1];
    }
    while ( v3 != (AnimationGroupHandle *)v1 );
  }
  Creature::RebindResources(v2->mCreature);
}

// File Line: 427
// RVA: 0x57F310
char __fastcall UFG::BaseAnimationComponent::AreResourcesAvailable(UFG::BaseAnimationComponent *this)
{
  Creature **v1; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v2; // rbx
  AnimationGroup *v3; // rcx

  v1 = &this->mCreature;
  v2 = this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext - 1;
  if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&this->mCreature )
    return 1;
  while ( 1 )
  {
    if ( LOWORD(v2[4].mPrev) > 2u )
    {
      v3 = (AnimationGroup *)v2[3].mNext;
      if ( !v3 || !AnimationGroup::IsStreamedIn(v3) )
        break;
    }
    v2 = v2[1].mNext - 1;
    if ( v2 == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v1 )
      return 1;
  }
  return 0;
}

// File Line: 433
// RVA: 0x58B790
void __fastcall UFG::BaseAnimationComponent::SetAnimationBankPriority(UFG::BaseAnimationComponent *this, UFG::qSymbolUC *theAnimationGroupSymbol, UFG::eAnimationPriorityEnum eAnimationPriority)
{
  Creature **v3; // rdi
  UFG::eAnimationPriorityEnum v4; // ebp
  AnimationGroupHandle *v5; // rbx
  UFG::qSymbolUC *v6; // rsi

  v3 = &this->mCreature;
  v4 = eAnimationPriority;
  v5 = (AnimationGroupHandle *)&this->mRequiredAnimationBanks.m_AnimationGroupHandleList.mNode.mNext[-1];
  v6 = theAnimationGroupSymbol;
  if ( v5 != (AnimationGroupHandle *)&this->mCreature )
  {
    do
    {
      if ( v5->m_AnimationGroupSymbol.mUID == v6->mUID )
        AnimationGroupHandle::SetAnimationPriority(v5, v4, 0);
      v5 = (AnimationGroupHandle *)&v5->mNext[-1];
    }
    while ( v5 != (AnimationGroupHandle *)v3 );
  }
}

// File Line: 442
// RVA: 0x583870
void __fastcall UFG::BaseAnimationComponent::InitPropertySetInfo(UFG::BaseAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj, component_BaseAnimation *dataPtr)
{
  component_BaseAnimation *v3; // rsi
  UFG::SceneObjectProperties *v4; // r15
  UFG::BaseAnimationComponent *v5; // rbx
  __int64 v6; // rax
  Creature *v7; // r14
  const char *v8; // rdi
  __int64 v9; // rax
  const char *v10; // rbp
  UFG::SimObjectGame *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  __int64 v14; // rax
  const char *v15; // rax
  __int64 v16; // rcx
  UFG::qSymbolUC *v17; // rax
  char *v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // edi
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::RigResource *v23; // rdi
  UFG::SimObjectGame *v24; // rcx
  unsigned __int16 v25; // dx
  UFG::SimComponent *v26; // rax
  UFG::allocator::free_link *v27; // rax
  Creature *v28; // rax
  UFG::SimObject *v29; // rdi
  UFG::TransformNodeComponent *v30; // rdi
  UFG::SimObjectGame *v31; // rcx
  unsigned __int16 v32; // dx
  UFG::CompositeDrawableComponent *v33; // rcx
  UFG::SimComponent *v34; // rax
  UFG::SimObjectGame *v35; // rcx
  unsigned __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  UFG::qSymbolUC poseDriverSet; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v39; // [rsp+70h] [rbp+18h]

  v3 = dataPtr;
  v4 = pSceneObj;
  v5 = this;
  v6 = dataPtr->RigName.mOffset;
  v7 = 0i64;
  if ( v6 )
    v8 = (char *)&dataPtr->RigName + v6;
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
    v11 = (UFG::SimObjectGame *)pSceneObj->m_pSimObject;
    if ( v11 )
    {
      v12 = v11->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = v11->m_Components.p[10].m_pComponent;
      }
      else if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
          v13 = v11->m_Components.p[7].m_pComponent;
        else
          v13 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v11,
                                    UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v11->vfptr,
                                                                                  UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v13 = v11->m_Components.p[10].m_pComponent;
      }
      if ( v13 && LOBYTE(v13[1].m_TypeUID) )
      {
        v14 = v3->RigNameHD.mOffset;
        if ( v14 && (v15 = (char *)&v3->RigNameHD + v14) != 0i64 && *v15 )
        {
          v16 = v3->WeightSetFileNameHD.mOffset;
          if ( v16 )
            v10 = (char *)&v3->WeightSetFileNameHD + v16;
          else
            v10 = 0i64;
          v8 = v15;
        }
        else
        {
          v17 = (UFG::qSymbolUC *)UFG::SceneObjectProperties::GetArchetypePropertiesName(v4);
          v18 = UFG::qSymbol::as_cstr_dbg(v17);
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
    v19 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
    v20 = v19;
    v5->mCurrentRigUID = v19;
    v21 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
    {
      v22 = UFG::qResourceWarehouse::Instance();
      v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x39BC0A7Eu);
      `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v21;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mRigHandle.mPrev, 0x39BC0A7Eu, v20, v21);
    v23 = (UFG::RigResource *)v5->mRigHandle.mData;
    v5->mTemporaryRig = 0;
    if ( !v23 )
    {
      v24 = (UFG::SimObjectGame *)v4->m_pSimObject;
      if ( v24 )
      {
        v25 = v24->m_Flags;
        if ( (v25 >> 14) & 1 )
        {
          v26 = v24->m_Components.p[3].m_pComponent;
        }
        else if ( (v25 & 0x8000u) == 0 )
        {
          if ( (v25 >> 13) & 1 )
            v26 = v24->m_Components.p[4].m_pComponent;
          else
            v26 = (v25 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v24,
                                      UFG::SimObjectPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v24->vfptr,
                                                                                       UFG::SimObjectPropertiesComponent::_TypeUID);
        }
        else
        {
          v26 = v24->m_Components.p[3].m_pComponent;
        }
        if ( v26 && LODWORD(v26[1].m_SafePointerList.mNode.mNext) == 4 )
        {
          v5->mCurrentRigUID = qSymbolX_defaultVehicleRig.mUID;
          UFG::qTypedResourceHandle<968624766,UFG::RigResource>::Init(
            (UFG::qTypedResourceHandle<968624766,UFG::RigResource> *)&v5->mRigHandle.mPrev,
            qSymbolX_defaultVehicleRig.mUID);
          v23 = (UFG::RigResource *)v5->mRigHandle.mData;
          v5->mTemporaryRig = 1;
        }
      }
    }
    UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(v5);
    if ( v23 )
    {
      v27 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
      v39 = v27;
      if ( v27 )
      {
        Creature::Creature((Creature *)v27, v23);
        v7 = v28;
      }
      v5->mCreature = v7;
      if ( v10 && *v10 )
        Creature::InitWeightSet(v7, v10);
      Creature::BuildPoseDriver(v5->mCreature, &poseDriverSet);
      v29 = v5->m_pSimObject;
      if ( v29 )
      {
        v30 = v29->m_pTransformNodeComponent;
        if ( v30 )
        {
          Creature::SetTransformNodeComponentRoot(v5->mCreature, v30);
          UFG::TransformNodeComponent::UpdateWorldTransform(v30);
          Creature::SetTransform(v5->mCreature, &v30->mWorldTransform);
        }
      }
      v31 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( v31 )
      {
        v32 = v31->m_Flags;
        if ( (v32 >> 14) & 1 )
        {
          v33 = (UFG::CompositeDrawableComponent *)v31->m_Components.p[14].m_pComponent;
        }
        else if ( (v32 & 0x8000u) == 0 )
        {
          if ( (v32 >> 13) & 1 )
          {
            v33 = (UFG::CompositeDrawableComponent *)v31->m_Components.p[9].m_pComponent;
          }
          else
          {
            v34 = (v32 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v31,
                                      UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v31->vfptr,
                                                                                     UFG::CompositeDrawableComponent::_TypeUID);
            v33 = (UFG::CompositeDrawableComponent *)v34;
          }
        }
        else
        {
          v33 = (UFG::CompositeDrawableComponent *)v31->m_Components.p[14].m_pComponent;
        }
        if ( v33 )
        {
          v33->mPose = &v5->mCreature->mPose;
          UFG::CompositeDrawableComponent::SetRig(v33, v5->mCurrentRigUID);
        }
      }
      v35 = (UFG::SimObjectGame *)v5->m_pSimObject;
      if ( v35 )
      {
        v36 = v35->m_Flags;
        if ( (v36 >> 14) & 1 )
        {
          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, Render::FXSimComponent::_TypeUID);
        }
        else if ( (v36 & 0x8000u) == 0 )
        {
          if ( (v36 >> 13) & 1 )
          {
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, Render::FXSimComponent::_TypeUID);
          }
          else if ( (v36 >> 12) & 1 )
          {
            v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, Render::FXSimComponent::_TypeUID);
          }
          else
          {
            v37 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v35->vfptr, Render::FXSimComponent::_TypeUID);
          }
        }
        else
        {
          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, Render::FXSimComponent::_TypeUID);
        }
        if ( v37 )
          *(_QWORD *)&v37[1].m_Flags = (char *)v5->mCreature + 240;
      }
    }
    UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(v5);
  }
}

// File Line: 541
// RVA: 0x591CA0
void __fastcall UFG::BaseAnimationComponent::bindRequiredAnimBanks(UFG::BaseAnimationComponent *this, UFG::SceneObjectProperties *pSceneObj, component_BaseAnimation *dataPtr)
{
  AnimationGroupHandleContainer *v3; // rbp
  component_BaseAnimation *v4; // rbx
  __int64 v5; // rax
  UFG::qPropertyList *v6; // rsi
  unsigned int v7; // edi
  unsigned int v8; // ebx
  UFG::qSymbolUC *v9; // rax
  AnimationGroupHandle *v10; // rbx
  bool v11; // di
  char v12; // al

  v3 = &this->mRequiredAnimationBanks;
  v4 = dataPtr;
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mRequiredAnimationBanks.m_AnimationGroupHandleList);
  if ( v4 )
  {
    v5 = v4->RequiredAnimBanks.mOffset;
    if ( v5 )
    {
      v6 = (UFG::qPropertyList *)((char *)&v4->RequiredAnimBanks + v5);
      if ( v6 )
      {
        v7 = v6->mNumElements;
        v8 = 0;
        if ( v7 )
        {
          do
          {
            v9 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v6, v8);
            if ( v9 )
              AnimationGroupHandleContainer::Add(v3, v9, eANIM_PRIORITY_REQUIRED);
            ++v8;
          }
          while ( v8 < v7 );
        }
      }
    }
    v10 = (AnimationGroupHandle *)&v3->m_AnimationGroupHandleList.mNode.mNext[-1];
    if ( v10 != (AnimationGroupHandle *)&v3[-1].m_AnimationGroupHandleList.mNode.mNext )
    {
      v11 = 1;
      do
      {
        v12 = AnimationGroupHandle::Bind(v10);
        v11 = v11 && v12;
        v10 = (AnimationGroupHandle *)&v10->mNext[-1];
      }
      while ( v10 != (AnimationGroupHandle *)&v3[-1].m_AnimationGroupHandleList.mNode.mNext );
      v3->m_bHasBeenBound = 1;
    }
  }
}

// File Line: 576
// RVA: 0x591D70
void __fastcall UFG::BaseAnimationComponent::checkSuspendActionTreeIfUsingTempRigOrWaitingForCreature(UFG::BaseAnimationComponent *this)
{
  UFG::SimObjectGame *v1; // rdi
  UFG::BaseAnimationComponent *v2; // rsi
  unsigned __int16 v3; // dx
  UFG::ActionTreeComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  bool v6; // cl
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::ActionTreeComponent *)v1->m_Components.p[7].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::ActionTreeComponent *)v1->m_Components.p[6].m_pComponent;
      }
      else
      {
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v4 = (UFG::ActionTreeComponent *)v5;
      }
    }
    else
    {
      v4 = (UFG::ActionTreeComponent *)v1->m_Components.p[7].m_pComponent;
    }
    if ( v4 )
    {
      v6 = v2->mTemporaryRig;
      if ( v6 != 1 && v2->mCreature || (LOBYTE(v4->m_Flags) >> 1) & 1 )
      {
        if ( !v6 && v2->mCreature && (LOBYTE(v4->m_Flags) >> 1) & 1 )
        {
          v7 = v1->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PowerManagementComponent::_TypeUID);
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PowerManagementComponent::_TypeUID);
            }
            else if ( (v7 >> 12) & 1 )
            {
              v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PowerManagementComponent::_TypeUID);
            }
            else
            {
              v8 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v1->vfptr,
                     UFG::PowerManagementComponent::_TypeUID);
            }
          }
          else
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PowerManagementComponent::_TypeUID);
          }
          if ( !v8 || !LODWORD(v8[1].m_pSimObject) )
            ((void (__fastcall *)(UFG::ActionTreeComponent *))v4->vfptr[9].__vecDelDtor)(v4);
        }
      }
      else
      {
        UFG::ActionTreeComponent::Reset(v4);
        ((void (__fastcall *)(UFG::ActionTreeComponent *))v4->vfptr[8].__vecDelDtor)(v4);
      }
    }
  }
}

// File Line: 631
// RVA: 0x585F60
void __fastcall UFG::BaseAnimationComponent::NotifyProxyModeChanged(UFG::BaseAnimationComponent *this, UFG::SimObject::eProxyMode proxyMode)
{
  Creature *v2; // r8

  v2 = this->mCreature;
  if ( v2 )
    v2->mNetworkLock = proxyMode == 2;
}

